function p = joint2Target(P_ct,jointAngles)
% This takes in the joint angles of the robot and position of the target
% with respect to the camera. The output is the transformation matrix of
% the target with respect to the base. ie where we want the end-effector to
% go.

% Define individual angles
t1 = jointAngles(1);
t2 = jointAngles(2);
t3 = jointAngles(3);
t4 = jointAngles(4);

T_0w = FwdKinQARM_wrist(t1,t2,t3,t4); % base to wrist
T_wc = [0, 1, 0, .05;
       -1, 0, 0, -0.05;
        0, 0, 1, -0.03;
        0, 0, 0, 1]; % wrist to camera

T_ct = [1,0,0,P_ct(1);
        0,1,0,P_ct(2);
        0,0,1,P_ct(3);
            0,0,0,1]; % camera to target
T_0t = T_0w*T_wc*T_ct;
p = T_0t(1:3,4)';
end




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function T0_w = FwdKinQARM_wrist(t1,t2,t3,t4)
%FwdKinQARM creates the transformation matrix for the base to the tool frame
% Inputs angles in radians of each joint

% QARM lengths specified in the Lab 6 coordinate system
L1 = 0.14; %m
L2 = 0.35; %m
L3 = 0.05; %m
L4 = 0.25; %m
L5 = 0.15; %m

% Angle between vertical and common perpendicular of joint 2&3
beta = atan2(L3,L2);

% DH Table of QARM
DH = [0,0,L1,t1;
    -pi/2,0,0,t2-pi/2+beta;
    0,sqrt(L2^2+L3^2),0,t3-beta;
    -pi/2,0,L4,t4;
    0,0,L5,0];

% Calculates Transformation matrix base to wrist frame.
T0_w = eye(4);
for i= 1:4;
    T0_w = T0_w*HTM(DH(i,1),DH(i,2),DH(i,3),DH(i,4));
end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function homoTransferMatrix = HTM(alphai_1,ai_1,di,thetai)
%homoTransform This function creates the Homogeneous Transformation Matrix
%   The angles are in radians. Use deg2rad for conversion.
homoTransferMatrix = [cos(thetai),-sin(thetai), 0,ai_1;
    sin(thetai)*cos(alphai_1), cos(thetai)*cos(alphai_1),-sin(alphai_1),-sin(alphai_1)*di;
    sin(thetai)*sin(alphai_1),cos(thetai)*sin(alphai_1),cos(alphai_1),cos(alphai_1)*di;
    0,0,0,1];
end
