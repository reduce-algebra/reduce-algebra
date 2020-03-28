% Pavlov equation: recursion operator for symmetries
% 2017-10-06
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u}$
odd_var:={q,r}$
total_order:=6;

% The even equation
principal_der:={u_2y}$
de:={u_tx + u_y*u_2x - u_x*u_xy}$

% The odd nonlocal variable
rx:=u_x*q_x + q_y - u_2x*q$
ry:=q_t + u_y*q_x - u_xy*q$

% The odd equation
principal_odd:={q_2y,r_x,r_y}$
de_odd:={q_2x*u_y  + q_tx - q_x*u_xy - q_xy*u_x + q_y*u_2x,rx,ry}$

% names for output of the state of cde and results of computations
statename:="pav_ro1_state.red"$
resname:="pav_ro1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
  {principal_der,de,principal_odd,de_odd})$

mk_superfun(lpav_sf,1,1);
lpav_sf(1):= - q_2x*u_y + q_2y - q_tx + q_x*u_xy + q_xy*u_x - q_y*u_2x$
conv_superfun2cdiff(lpav_sf,lpav);

lpav(1,1,r);

;end;

