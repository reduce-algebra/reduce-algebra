% Dispersionless Boussinesq equation: conservation laws
% 2015-11-09
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={x,t}$
dep_var:={u,v,w}$
odd_var:={p,q,r}$
total_order:=8$
% names for output of the state of cde and results of computations
statename:="bou_lcl1_state.red"$
resname:="bou_lcl1_res.red"$

% The function that defines the Boussinesq equation
principal_der:={u_t,v_t,w_t}$
de:={w*w_x + v_x, - u*w_x - 3*w*u_x,u_x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{principal_der,de,{},{}})$
% Saving cde state in a file
save_cde_state(statename)$

% we assume a conservation law of the form omega = fx dx+ ft dt
% with fx and ft polynomial of second degree in the dependent variables.

ansatz:=1 . mkallmon(2,dep_var)$

ctel:=0$
operator c,equ$
fx:=for each el in ansatz sum c(ctel:=ctel+1)*el$
ft:=for each el in ansatz sum c(ctel:=ctel+1)*el$

equ 1:=td(fx,t) - td(ft,x)$
unk:={fx,ft}$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=1;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedure splitvars in order to obtain equations on coefficiens
% of each monomial.

tel:=splitvars_opequ(equ,1,1,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=2:tel do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write fx:=fx;
write ft:=ft;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;

Local Variables:
mode:reduce
End: