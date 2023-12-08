function transform = forwardKinematics(theta)
    theta1 = theta(1);
    theta2 = theta(2);
    theta3 = theta(3);
    theta4 = theta(4);
    l1 = 0.14;
    l2 = 0.35;
    l3 = 0.05;
    l4 = 0.25;
    l5 = 0.15;
    l_23 = sqrt(l2 * l2 + l3 * l3);
    beta = atan2(l3, l2);

    % theta, alpha, a, d
    dh = [theta1, 0, 0, l1;
          theta2 - pi/2 + beta , -pi/2, 0, 0;
          theta3 - beta, 0, l_23, 0;
          theta4, -pi/2, 0, l4;
               0, 0, 0, l5];
    % Create identity matrix of 4x4
    transform = eye(4);
    for i = 1:size(dh,1)
        % append("T_", char(i-1 + '0'), "_", char(i+'0'))
        t = homoTransMatrix(dh(i,1), dh(i,2), dh(i,3), dh(i,4));
        transform = transform * t;
    end
    rot = transform(1:3, 1:3);
    trans = transform(1:3, 4);

