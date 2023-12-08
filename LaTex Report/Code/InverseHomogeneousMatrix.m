function T_inv = InverseHomogeneousMatrix(T)
    % Check if the input matrix is a 4x4 matrix
    if size(T) ~= [4, 4]
        error('Input matrix must be a 4x4 homogeneous transformation matrix.');
    end
    
    % Extract the rotation matrix and translation vector from the input matrix
    R = T(1:3, 1:3);
    p = T(1:3, 4);
    
    % Calculate the inverse of the rotation matrix
    R_inv = transpose(R);
    
    % Calculate the translation vector of the inverse
    p_inv = -R_inv * p;
    
    % Construct the inverse homogeneous transformation matrix
    T_inv = [R_inv, p_inv; 0, 0, 0, 1];
end