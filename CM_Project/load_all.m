% LOAD path of current files, parameters, and CM environment

%LOAD PATH 
mydir = pwd;
idcs = strfind(mydir,'\');
current_dir = append(mydir(1:idcs(end)-1), '\Current');
addpath(current_dir);
addpath(append(mydir, '\src_cm4sl'));

%AND PARAMETERS
Controllerparameters;
mpc_StateSpace_together;

load("params.mat")
load("mpcss.mat")
load("FSE_motor_parameters1.txt")

%CARMAKER ENVIRONMENT
cmenv

% OPEN SIMULINK MODEL WITH CONTROL SYSTEMS
open_system("HPF023ControlSystems")