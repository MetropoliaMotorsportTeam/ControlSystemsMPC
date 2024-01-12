% CONTROLLER PARAMETERS



% Vehicle parameters for controller
Rd = 0.205;
wf = 0.6;
wr = 0.6; 
Gr = 12;
m = 280; 
g = 9.81; 
lf = 0.765; 
lr = 0.765; 
l = 1.53; 
h = 0.3; 
myy = 2; 
Sgr = 5; 

% Tunable controller parameters 

Ku = 0; % Understeer gradient
SteeringDeadzoneLowerlimit = -10;
SteeringDeadzoneUpperlimit = 10; 
UpperYawMoment = 3600 ;
LowerYawMoment = -3600 ; 
Upper_slip_threshold = 0.24 ;
Lower_slip_threshold = 0.20 ;
MaxmotorRPM = 20000;
MinmotorRPM = 0;
SystemVelocityActivation = 2.5 ;
PedalPostionActivation = 0.1 ; 
% Activation options

TuneGains = 1 ; % If controller is too aggresive this value 
% For example if values is increased from 1 to 2 it cuts controller PI
% gains by half 
feedforwardgain = 4 ; % Specify feedforward system gain 


% Sample Time

Ts = 0.01 ; % 100 Hz


TV_feedback_active = 0 ;
TV_feedforward_active = 1 ;
TV_active = 0 ;
TCS_active = 0 ;
VelocityControlActive = 0;
Longitudinal_distribution = 0; 

%%%% DATA INTEGRITY CHECK 
%%%% IF VALUE IS NOT BETWEEN POSSIBLE VALUE VALUES ARE SET TO ZERO 
% Vehicle velocity m/s
% Velocity can between 0 and 40 m/s 
VelocityMax = 40 ;
Velocitymin = 0 ; 
% Front left wheel rotational speed rad/s
% Can be from 0 to 175 rad/s 
wFLmax = 175 ;
wFLmin = 0;
% Front right wheel rotational speed rad/s
% Can be from 0 to 175 rad/s
wFRmax = 175 ;
wFRmin = 0;
% Rear left wheel rotational speed rad/s
% Can be from 0 to 175 rad/s 
wRLmax = 175 ;
wRLmin = 0;
% Rear right wheel rotational speed rad/s
% Can be from 0 to 175 rad/s
wRRmax = 175 ;
wRRmin = 0;
% Vehicle acceleration m/s^2
% Can be from 2.3 G to -2.3G
LongAccMax = 23 ;
LongAccMin = -23 ;
% Vehicle yaw rate rad/s 
% Yaw rate can be between 120 deg/s and -120 deg/s or 2.094 rad/s
Yawratemax = 2.094 ;
Yawratemin = -2.094;
% Vehicle steering wheel angle rad
% Steering wheel angle can be maximum 140 or -140 degrees 
MaxStrAng = 145 ;
MinStrAng = -145 ; 