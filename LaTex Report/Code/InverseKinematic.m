function sol1 = InverseKinematic(position)
%INVERSEKINEMATIC2 Summary of this function goes here
%   Detailed explanation goes here
    px = position(1);
    py = position(2);
    pz = position(3);
    
    % Arm Dimensions
    l1 = 0.14;
    l2 = 0.35;
    l3 = 0.05;
    l23 = sqrt(l2^2 + l3^2);
    beta_arm = atan2(l3, l2);
    l4 = 0.25;
    l5 = 0.15;
    % Set final position equal to tip of end effector
    l4 = l4 + l5;

    % Theta1 Solutions
    theta1_1 = atan2(py, px);
    theta1_2 = atan2(-py, -px);

    % Theta4 Solution
    theta4 = 0;

    dist_between_T1_T5 = sqrt(px^2 + py^2 + (pz - l1)^2); 
    % transform end effector position for the T01 so everthing is planar on
    % the XZ-plane then use law of cosines to find angles for triangle of
    % arm sections and distance between Base and end effector.

    T1Px_1 = InverseHomogeneousMatrix(homoTransform(0,      0,      l1, theta1_1)) * transpose([px py pz 1]);
    angle_1 = atan2(T1Px_1(1), T1Px_1(3));
    T1Px_2 = InverseHomogeneousMatrix(homoTransform(0,      0,      l1, theta1_2)) * transpose([px py pz 1]);
    angle_2 = atan2(T1Px_2(1), T1Px_2(3));
    % 3side Triangle solution law of cosines
    a = l23;
    b = l4;
   

    if T1Px_1(1) > T1Px_2(1)
        c = sqrt(T1Px_1(1)*T1Px_1(1) + T1Px_1(3)*T1Px_1(3));
        beta = acos((a^2 + c^2 - b^2)/(2*a*c));
        gamma = acos((a^2 +b^2 - c^2)/(2*a*b));
        
        theta2_1 = angle_1 - beta - beta_arm;
        theta3_1 = pi/2 - gamma + beta_arm;
        sol1 = [theta1_1, theta2_1, theta3_1, 0]';
        return
    else
        c = sqrt(T1Px_2(1)*T1Px_2(1) + T1Px_2(3)*T1Px_2(3));
        beta = acos((a^2 + c^2 - b^2)/(2*a*c));
        gamma = acos((a^2 +b^2 - c^2)/(2*a*b));
        theta2_1 = angle_2 - beta - beta_arm;
        theta3_1 = pi/2 - gamma + beta_arm;
        sol1 = [theta1_2, theta2_1, theta3_1, 0]';
        return
    end
end

