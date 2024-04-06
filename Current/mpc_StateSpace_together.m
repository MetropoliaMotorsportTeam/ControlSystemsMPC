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

%% create MPC controller object with sample time
mpc1 = mpc(sys1, 0.001);
%% specify prediction horizon
mpc1.PredictionHorizon = 10;
%% specify control horizon
mpc1.ControlHorizon = 2;
%% specify nominal values for inputs and outputs
mpc1.Model.Nominal.U = 0;
mpc1.Model.Nominal.Y = [0;0;0];
%% specify weights
mpc1.Weights.MV = 0;
mpc1.Weights.MVRate = 0.1;
mpc1.Weights.OV = [1 0 0];
mpc1.Weights.ECR = 100000;


% SAVE ALL VARIABLES TO MPCSS.MAT
save("mpcss.mat")