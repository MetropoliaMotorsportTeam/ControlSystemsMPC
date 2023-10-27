A = [-(Cr + Cf)/(m), (-v_x^2*m-Cf*lf + Cr*lr)/(m),Cf/m; (lr*Cr-lf*Cf)/(Izz), (lf^2*Cf-lr^2*Cr)/(Izz),lf*Cf/Izz;0,0,0]
B = [0; 1/Izz;0]
C = eye(3)
D = zeros([3,1])

sys = ss(A,B,C,D)