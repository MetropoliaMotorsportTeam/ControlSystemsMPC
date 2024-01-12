Ts=0.001;
%% create MPC controller object with sample time
sys_dis = c2d(sys:C,Ts);
mpc1_C = mpc(sys_dis, 1);
%% specify prediction horizon
mpc1_C.PredictionHorizon = 10;
%% specify control horizon
mpc1_C.ControlHorizon = 2;
%% specify nominal values for inputs and outputs
mpc1_C.Model.Nominal.U = 0;
mpc1_C.Model.Nominal.Y = [0;0;0];
%% specify weights
mpc1_C.Weights.MV = 0;
mpc1_C.Weights.MVRate = 0.1;
mpc1_C.Weights.OV = [1 0 0];
mpc1_C.Weights.ECR = 100000;

save('MPC01.mat','mpc1_C')