% Checking Schouten bracket of three first-order operators
% of Dubrovin-Novikov type (homogeneous) in two independent variables
% 2015.10.10 R. Vitolo

load_package cde;

% Initialization
indep_var:={x,y}$
dep_var:={p1,p2}$
odd_var:={q1,q2}$
total_order:=8$

resfile:="dn2d_sb1_res.red"$
statename:="dn2d_sb1_state.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},{})$

% Saving cde state in a file
save_cde_state(statename)$


% Number of components of the operators
ncomp:=length(dep_var)$

cu1:=mat((1,0),(0,0))$
cu2:=mat((0,0),(0,1))$

% First Ist order operator
mk_cdiffop(aa1,1,{2},2)$
for all i,j,psi let aa1(i,j,psi)=
cu1(i,j)*td(psi,x)+cu2(i,j)*td(psi,y)$

% The operator aa2 is the third order homogeneous
% (not necessarily Hamiltonian) skew-adjoint operator
for each el in {f,g} do
  for each ell in dep_var do depend el,ell$

mk_cdiffop(aa2,1,{2},2)$
for all psi let aa2(1,1,psi) = 2*df(g,p1)*p2_y*td(psi,x) +
  df(g,p1)*p2_xy*psi + df(g,p1,p2)*p2_x*p2_y*psi + df(g,p1,2)*p1_x*p2_y*psi;

for all psi let aa2(1,2,psi) = f*td(psi,x,2) - g*td(psi,y,2)
  + df(f,p1)*p1_x*td(psi,x) -
  (df(g,p2)*p2_y + 2*df(g,p1)*p1_y)*td(psi,y) -
  df(g,p1,2)*p1_y*p1_y*psi - df(g,p1,p2)*p1_y*p2_y*psi - df(g,p1)*p1_2y*psi;

for all psi let aa2(2,1,psi) = -f*td(psi,x,2)
  + g*td(psi,y,2) +
  df(g,p2)*p2_y*td(psi,y) -
  (df(f,p1)*p1_x+2*df(f,p2)*p2_x)*td(psi,x)
    - df(f,p2,2)*p2_x*p2_x*psi - df(f,p1,p2)*p1_x*p2_x*psi
      - df(f,p2)*p2_2x*psi;

for all psi let aa2(2,2,psi) = 2*df(f,p2)*p1_x*td(psi,y)
  + df(f,p2)*p1_xy*psi + df(f,p1,p2)*p1_x*p1_y*psi
    + df(f,p2,2)*p1_x*p2_y*psi;

mk_cdiffop(aa3,1,{2},2)$
for all psi let aa3(1,1,psi) = aa2(1,1,psi);
for all psi let aa3(1,2,psi) = aa2(2,1,psi);
for all psi let aa3(2,1,psi) = aa2(1,2,psi);
for all psi let aa3(2,2,psi) = aa2(2,2,psi);

conv_cdiff2superfun(aa1,sym1)$
conv_cdiff2superfun(aa2,sym2)$
conv_cdiff2superfun(aa3,sym3)$

adjoint_cdiffop(aa1,aa1_star);
adjoint_cdiffop(aa2,aa2_star);
adjoint_cdiffop(aa3,aa3_star);

for i:=1:2 do write sym1(i) + aa1_star_sf(i);
for i:=1:2 do write sym2(i) + aa2_star_sf(i);
for i:=1:2 do write sym3(i) + aa3_star_sf(i);

% Now I compute Schouten brackets

biv1:=conv_genfun2biv(sym1)$
biv2:=conv_genfun2biv(sym2)$
biv3:=conv_genfun2biv(sym3)$

sb11:=schouten_bracket(biv1,biv1);

sb12:=schouten_bracket(biv1,biv2);

sb13:=schouten_bracket(biv1,biv3);

% It should be sb11 and sb13 zero, sb12 nonzero.

off nat; off echo;
out <<resfile>>;

write "sb12:=",sb12;

write "sb13:=",sb13;

write ";end;";

shut <<resfile>>;

;end;

Local Variables:
mode:reduce
End:
