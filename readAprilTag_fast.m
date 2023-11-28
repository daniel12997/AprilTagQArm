function varargout = readAprilTag(I, varargin)
%

%   Copyright 2020-2022 The MathWorks, Inc.

%#codegen


narginchk(1,4);
[tagFamily, estimatePose, intrinsics, tagSize] = parseInputs(I, varargin{:});

% Convert to grayscale
if ~ismatrix(I)
    imgGray = rgb2gray(I);
else
    imgGray = I;
end


% Ensure image data is uint8
if ~isa(imgGray, 'uint8')
    imgUint8 = im2uint8(imgGray);
else
    imgUint8 = imgGray;
end

% Increasing this parameter will increase the speed of the detector at the
% cost of the detection distance.

quadDecimate = 5;
quadDecimate = checkQuadDecimate(quadDecimate);

if ~estimatePose
    nargoutchk(0,3);
    [varargout{1:nargout}] = readAprilTagID(imgUint8, tagFamily, quadDecimate);
else
    nargoutchk(0,4);
    [varargout{1:nargout}] = readAprilTagIDPose(imgUint8, tagFamily, intrinsics, tagSize, quadDecimate);
end

end

%--------------------------------------------------------------------------
% isSimMode - check if simulation mode or codegen mode
%--------------------------------------------------------------------------
function out = isSimMode()
    out = isempty(coder.target);
end

%--------------------------------------------------------------------------
% parseInputs - Parse the input arguments
%--------------------------------------------------------------------------
function [tagFamily, estimatePose, intrinsics, tagSize] = parseInputs(I, varargin)


vision.internal.inputValidation.validateImage(I);

if nargin == 1
    tagFamily = 'all';
    tagSize = 0;    
    
    % allocate memory for intrinsicsObj by assigning default values for camera
    % parameters
    intrinsics = cameraIntrinsics(ones(1,2),ones(1,2),ones(1,2));
end

estimatePose = nargin > 2;

if nargin == 2 % readAprilTag(I, tagFamily)
    
    tagFamily = varargin{1};
    tagSize = 0;
    % allocate memory for intrinsicsObj by assigning default values for camera
    % parameters
    intrinsics = cameraIntrinsics(ones(1,2),ones(1,2),ones(1,2));
    
elseif nargin == 3 % readAprilTag(I, intrinsics, tagSize)
    
    tagFamily = 'all';
    intrinsics = varargin{1};
    tagSize = varargin{2};
    
elseif nargin > 3 % readAprilTag(I, tagFamily, intrinsics, tagSize)
    
    tagFamily  = varargin{1};
    intrinsics = varargin{2};
    tagSize = varargin{3};
end

% validate tag Family
tagFamily = checkTagFamily(tagFamily);

if estimatePose
    vision.internal.inputValidation.checkIntrinsicsAndParameters( ...
    intrinsics, true, mfilename, 'intrinsics'); 
    % validate tag Size
    tagSize = checkTagSize(tagSize);
end
end

%--------------------------------------------------------------------------
% readAprilTagID - Call AprilTag tag ID decoding
%--------------------------------------------------------------------------
function [id, loc, detectedFamily] = readAprilTagID(Img, tagFamily, quadDecimate)


if isSimMode()
    [id, loc, detectedFamily] = vision.internal.aprilTagReader(Img.', tagFamily, false, quadDecimate);
else
    [id, loc, detectedFamily] = vision.internal.buildable.readAprilTagBuildable.readAprilTagID(Img.', ...
        tagFamily, false, quadDecimate);
end

loc = loc + 1; % AprilTag uses zero-indexing for images

if isSimMode()
    %output string array for detected families
    detectedFamily = string(detectedFamily);
end

end

%--------------------------------------------------------------------------
% readAprilTagIDPose - Call AprilTag tag ID decoding and pose estimation
%--------------------------------------------------------------------------
function [id, loc, pose, detectedFamily] = readAprilTagIDPose(I, tagFamily, intrinsics, tagSize, quadDecimate)

focalLength = intrinsics.FocalLength;
principalPoint = intrinsics.PrincipalPoint;

if isSimMode()
    [id, loc, detectedFamily, rotMatrices, transVectors] = vision.internal.aprilTagReader(I.', tagFamily, ...
        true, quadDecimate, focalLength, principalPoint, tagSize);
else
    [id, loc, detectedFamily, rotMatrices, transVectors] = vision.internal.buildable.readAprilTagBuildable.readAprilTagID(I.', tagFamily, ...
        true, quadDecimate, focalLength, principalPoint, tagSize);
end

count = 1;
invalidIdx = [];

if isSimMode()
    pose = rigidtform3d.empty;
    for idx = 1:size(rotMatrices, 3)

        % Only accept tags with valid poses. An invalid rotation matrix points
        % to an incorrect detection. This is more prominent in the smaller tag
        % families like tag16h5 and tag25h9.
        try
            vision.internal.inputValidation.validateRotationMatrix(...
                rotMatrices(:,:,idx), 'readAprilTag', 'rotationMatrix');
            pose(count) = rigidtform3d(rotMatrices(:,:,idx)', transVectors(:,:,idx)');
            count = count + 1;
        catch
            invalidIdx = [invalidIdx idx]; %#ok<AGROW>
        end
    end
    
else
    
    % allocating memory for rigidtform3d object array
    dataType = 'double';
    T = eye(4, 4, dataType);
    
    % Create a dummy object
    pose = rigidtform3d(T);
    
    countValid = 1;
    for idx = 1:size(rotMatrices, 3)
        if checkRotationMatrix(rotMatrices(:,:,idx))
            
            %creating rigidtform3d object array
            pose(countValid) = rigidtform3d(rotMatrices(:,:,idx)',transVectors(:,:,idx)');
            countValid = countValid+1;
        else
            invalidIdx = [invalidIdx idx];
        end
    end
    
end
id(invalidIdx) = [];
loc(:,:,invalidIdx) = [];
detectedFamily(invalidIdx) = [];

loc = loc + 1; % AprilTag uses zero-indexing for images

if isSimMode()
    detectedFamily = string(detectedFamily);
end

end

%--------------------------------------------------------------------------
% checkTagFamily - Validate AprilTag families
%--------------------------------------------------------------------------
function tagFamily = checkTagFamily(tagFamily)
validateattributes(tagFamily, {'char', 'string', 'cell'}, {'nonempty', 'vector'}, 'readAprilTag', 'tagFamily');

supportedFamilies = vision.internal.supportedAprilTagFamilies();

if ischar(tagFamily) || isStringScalar(tagFamily)
    
    if ~isSimMode()
        n = size(supportedFamilies,2);
        validFamiliesChar = cell(1,n+1);
        validFamiliesChar{1} = 'all';
        for i = 1:n
            validFamiliesChar{i+1} = supportedFamilies{i};
        end
        
        % a tag family is valid if it matches with families present in
        % validFamilies
        isValidFamily = any(strcmp(validFamiliesChar,tagFamily));
        
        formatMsg = strjoin(supportedFamilies, ', ');
        coder.internal.errorIf(~isValidFamily,'vision:apriltag:unrecognizedStringChoice', formatMsg);
        
    else 
        validFamiliesChar = [{'all'}, supportedFamilies(:)'];
        tagFamily = validatestring(tagFamily, validFamiliesChar, 'readAprilTag', 'tagFamily');
    end
else
        
    coder.internal.errorIf(~iscellstr(tagFamily) && ...
    ~isstring(tagFamily),'vision:apriltag:invalidStringList');
    
    if isSimMode()
        isValidFamily = all(ismember(tagFamily, supportedFamilies));
    else
        count = 0;
        if iscellstr(tagFamily)         
            for i = 1:size(tagFamily,2)
                count = count+any(strcmp(supportedFamilies,tagFamily{i}));
            end
            isValidFamily = (count == size(tagFamily,2));
        else
            isValidFamily = any(strcmp(supportedFamilies, tagFamily));
        end
    end
    
    formatMsg = strjoin(supportedFamilies, ', ');
    coder.internal.errorIf(~isValidFamily,'vision:apriltag:unrecognizedStringChoice', formatMsg);

    if isSimMode()
        tagFamily = cellstr(tagFamily);
    end
end

end

%--------------------------------------------------------------------------
% checkTagSize - Validate tag size
%--------------------------------------------------------------------------
function tagSize = checkTagSize(tagSize)
validateattributes(tagSize, {'numeric'}, {'finite', 'real', 'nonsparse', ...
    'scalar', 'positive'}, 'readAprilTag');
end

%--------------------------------------------------------------------------
% checkQuadDecimate - Validate quadDecimate parameter
%--------------------------------------------------------------------------
function quadDecimate = checkQuadDecimate(quadDecimate)
validateattributes(quadDecimate, {'numeric'}, {'finite', 'real', 'nonsparse', ...
    'scalar', 'positive', '>=', 1}, 'readAprilTag');
end

%--------------------------------------------------------------------------
% checkRotationMatrix - Validate rotation matrix
%--------------------------------------------------------------------------
function validFlag = checkRotationMatrix(M)

validateattributes(M, {'numeric'}, ...
    {'finite', '2d', 'real', 'nonsparse', 'size', [3,3]});

if abs(det(double(M))-1) > 1e-3
    validFlag = false;
else
    M = double(M);
    MM = M*M';
    I = eye(3);
    if max(abs(MM(:)-I(:))) > 1e-3
        validFlag = false;
    end
    validFlag = true;
end
end
