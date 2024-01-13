
Cr = 1
Cf = 1
m = 200
Izz = 100
lf = 0.7650
lr = 0.7650
v_x=10

A = [-(Cr + Cf)/(m), (-v_x^2*m-Cf*lf + Cr*lr)/(m),Cf/m; (lr*Cr-lf*Cf)/(Izz), (lf^2*Cf-lr^2*Cr)/(Izz),lf*Cf/Izz;0,0,0]
B = [0; 1/Izz;0]
C = eye(3)
D = zeros([3,1])

sys1 = ss(A,B,C,D,0.001)