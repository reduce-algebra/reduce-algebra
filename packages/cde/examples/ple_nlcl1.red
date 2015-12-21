% Plebanski equation: conservation laws on the cotangent covering
%    for non-local variables.
% 2015-10-10
% Raffaele Vitolo

% Loading the interface to cdiff packages; used to generate all
% (even and odd) derivative coordinates,
% (even and odd) principal and parametric derivatives,
% and the restriction of total derivatives to the (even and odd) equation.
% Of course mostly odd part refers to tangent or cotangent covering.
in "cde.red"$

algebraic;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y,z}$
dep_var:={u}$
odd_var:={p}$
deg_indep_var:={-1,-1,-4,-4}$
deg_dep_var:={1}$
deg_odd_var:={4}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="ple_nlcl1_state.red"$
resname:="ple_nlcl1_res.red"$

% Initialization of the differential equation.
% The system must be in passive orthonomic form;
% this means that there will be no nontrivial integrability conditions
% between parametric derivatives.

% left-hand side of the differential equation
principal_der:={u_xz}$
% right-hand side of the differential equation
de:={-u_ty+u_tx**2-u_2t*u_2x}$

% same constructions for odd coordinates
principal_odd:={p_xz}$
de_odd:={-p_ty+2*u_tx*p_tx-u_2x*p_2t-u_2t*p_2x}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
save_cde_state(statename)$

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% we assume that conserved currents have the form
% cl = ct dxdydz + cx dtdydz + cy dtdxdz + cz dtdxdy
% in order to have a homogeneous c.l. w.r.t. grading
% there must hold: [ct]=[cx], [cy]=[cz], [cx]=[cz]+3.
% we will look for two components c.l. with cy=cz=0.

% Select only variables of jetspace order not greater than 4.
v0_4:=for i:=0:4 join selectvars(0,i,dep_var,all_parametric_der)$
vo0_4:=for i:=0:4 join selectvars(1,i,odd_var,all_parametric_odd)$
% List of variables ordered by gradings
graadlijst:=der_deg_ordering(0,v0_4)$
graadlijst_odd:={1} . der_deg_ordering(1,vo0_4)$
% List of graded monomials of scale degree <= 10
graadmon:=for i:=1:13 collect mkvarlist1(i,i)$
graadmon:={1} . graadmon$
% The grading for which the ansatz is being constructed
deg_cx:=8$
deg_ct:=deg_cx$

linoddt:=mkalllinodd(graadmon,graadlijst_odd,deg_ct,deg_ct)$
linoddx:=linoddt$
% Ansatz:
ct:=(for each el in linoddt sum (c(ctel:=ctel+1)*el))$
cx:=(for each el in linoddx sum (c(ctel:=ctel+1)*el))$

ct_t:=td(ct,t)$
cx_x:=td(cx,x)$

equ 1:=ct_t-cx_x$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=1$

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0})$

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.

tel:=splitext_opequ(equ,1,1)$

tel2:=splitvars_opequ(equ,2,tel,vars);

put_equations_used tel2$

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i$

off nat$
off echo$
out <<resname>>$
write "% Conservation laws (including trivial ones)";
write ct:=ct;
write cx:=cx;
out t$
on echo$
on nat$

% Beginning of removal of trivial c.l. from the solution
operator cc$
cctel:=0$

% ansatz for tcl, the grading must be compatible with
% tcl = tctx dtdx + tcty dtdy + tctz dtdz + tcxy dxdy + tcxz dxdz + tcyz dydz
% and dbar(tcl) = (ddze(tcxy)-ddye(tcxz)+ddxe(tcyz))dxdydz +
%                 (ddze(tcty)-ddye(tctz)+ddte(tcyz))dtdydz +
%                 (ddze(tctx)-ddxe(tctz)+ddte(tcxz))dtdxdz +
%                 (ddye(tctx)-ddxe(tcty)+ddte(tcxy))dtdxdy
%               = ct dxdydz + cx dtdydz + cy dtdxdz + cz dtdxdy
%
% We will assume a single potential of the form: tcyz dydz
deg_tcyz:=7$

linodd_tcyz:=mkalllinodd(graadmon,graadlijst_odd,deg_tcyz,deg_tcyz)$
tcyz:=(for each el in linodd_tcyz sum (cc(cctel:=cctel+1)*el))$

% Note: there is no need to check_letop here.

clear equ$
operator equ$

equ 1:=td(tcyz,x) - ct$
equ 2:=td(tcyz,t) - cx$

vars:=append(indep_var,all_parametric_der)$

% This is the number of initial equation(s)

tel:=2$

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{cc,cctel,0},{f,0,0})$

% Run the procedures splitext and splitvars
% in order to obtain equations on coefficiens
% of each monomial.
tel:=splitext_opequ(equ,1,2);

tel2:=splitvars_opequ(equ,3,tel,vars);

put_equations_used tel2$

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i$

off nat$
off echo$
out <<resname>>$
write "% Conservation laws (after removal of trivial ones)";
write ctnontriv:=equ 1$
write cxnontriv:=equ 2$

write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;


Local Variables:
mode:reduce
End:
