% WDVV equation in 3 components: local Hamiltonian operators
% See Ferapontov, Galvao, Mokhov, Nutku, Comm. Math. Phys. 
% 2015-10-09

% File biham1: checking that
% 1 - the third-order operator aa2 fulfills [aa2,aa2]=0.
% 2 - the first-order operator aa1 fulfills [aa1,aa1]=0.
% 3 - the two operators are compatible, [aa1,aa2]=0.

% Loading the interface to cdiff packages
in "cde.red"$

algebraic;

load_package assist;

indep_var:={t,x}$
dep_var:={a,b,c}$
odd_var:={p,q,r}$
total_order:=10$
resname:="wdvv_biham1_res.red"$

% left-hand side of the differential equation
principal_der:={a_t,b_t,c_t}$
% right-hand side of the differential equation
de:={b_x,c_x,(2*b*b_x - a*c_x - a_x*c)}$

% same constructions for odd coordinates; here we do not need
% t-derivatives of odd variables
principal_odd:={p_t,q_t,r_t}$
de_odd:={0,0,0}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$
% Saving cde state in a file
% save_cde_state(statename)$

% Number of components of the operators
ncomp:=length(dep_var)$

% Ist order operator
gu1:=mat(
(-(3/2),(1/2)*a,b),
((1/2)*a,b,(3/2)*c),
(b,(3/2)*c,2*(b**2 - a*c))
)$

gl1:=gu1**(-1)$

% Transform metrics into operators
operator glo1,guo1$
for i:=1:ncomp do
 for j:=1:ncomp do
  <<
   glo1(i,j):=gl1(i,j);
   guo1(i,j):=gu1(i,j)
  >>$

% Define and compute Christoffel symbols of first and second type

procedure chr1(gmat,i,j,k,vars)$
% Christoffel symbols of the first kind \Gamma_{ijk}
   (1/2)*(df(gmat(i,j),part(vars,k))+df(gmat(i,k),part(vars,j))
      -df(gmat(j,k),part(vars,i)))$

procedure mk_chr1(gmat,i,j,k,vars)$
% Generate a symbol from the table of all Christoffel symbols
   list_to_ids({chr1_,i,j,k})$

procedure generate_all_chr1(gmat,vars)$
% Generate all Christoffel symbols of type 1
begin scalar n_vars,list_done$
   n_vars:=length(vars)$
   list_done:={}$
   for i:=1:n_vars do
    for j:=1:n_vars do
     for k:=1:n_vars do
      if not ({i,j,k} member list_done) then
      <<
       set(mk_chr1(gmat,i,j,k,vars),chr1(gmat,i,j,k,vars))$
       list_done:={i,j,k} . list_done
      >>$
end$

procedure chr2(gmat,i,j,k,inv_gmat,vars)$
% Christoffel symbols of the second kind of gmat, \Gamma^i_{jk}
% inv_gmat should be an operator containing the inverse of gmat
begin scalar n_gmat$
   n_gmat:=length(vars)$
   return for s:=1:n_gmat sum
    inv_gmat(i,s)*mk_chr1(gmat,s,j,k,vars)
end$

procedure mk_chr2(gmat,i,j,k,vars)$
% Generate a symbol from the table of all Christoffel symbols
   list_to_ids({chr2_,i,j,k})$

procedure generate_all_chr2(gmat,inv_gmat,vars)$
% Generate all Christoffel symbols of type 1
begin scalar n_vars,list_done$
   list_done:={}$
   n_vars:=length(vars)$
   for i:=1:n_vars do
    for j:=1:n_vars do
     for k:=1:n_vars do
      if not ({i,j,k} member list_done) then
      <<
       set(mk_chr2(gmat,i,j,k,vars),chr2(gmat,i,j,k,inv_gmat,vars))$
       list_done:={i,j,k} . list_done
      >>$
end$

generate_all_chr1(glo1,dep_var)$
generate_all_chr2(glo1,guo1,dep_var)$

% Raise another second index of the Christoffel symbols of second type
% gamma^i_jk = chr2(gl1,i,j,k,gu1,dep_var) of gl1
templist:={}$
operator gamma_hi$
for i:=1:ncomp do
 for j:=1:ncomp do
  for k:=1:ncomp do
   gamma_hi(i,j,k):=
    <<
     templist:=
      for s:=1:ncomp collect
        - gu1(i,s)*chr2(glo1,j,s,k,guo1,dep_var)$
     templist:=part(templist,0):=plus
    >>$

% Introduce the contracted operator
operator gamma_hi_con$
for i:=1:ncomp do
 for j:=1:ncomp do
  gamma_hi_con(i,j):=
   <<
    templist:=for k:=1:ncomp collect gamma_hi(i,j,k)*mkid(part(dep_var,k),!_x)$
    templist:=part(templist,0):=plus
   >>$

% The operator aa1 is the ansatz for the first homogeneous Hamiltonian operator
mk_cdiffop(aa1,1,{3},3)$
for all i,j,psi let aa1(i,j,psi)=
 gu1(i,j)*td(psi,x)+gamma_hi_con(i,j)*psi$

% IIIrd order operator

% Must load one metric (as a matrix), then rename it as 'gl3'.
gu3:=mat(
(0,0,1),(0,1, - a),(1, - a,2*b+a**2)
)$

% Reconstruction of the third order operator.
gl3:=gu3**(-1)$

% Define c_ijk = (1/3)*(g_ki,j - g_ji,k)
operator c_lo$
for i:=1:ncomp do
 for j:=1:ncomp do
  for k:=1:ncomp do
  <<
   c_lo(i,j,k):=
    (1/3)*(df(gl3(k,i),part(dep_var,j)) - df(gl3(j,i),part(dep_var,k)))$
  >>$

% Define c^ij_k=c_hi(i,j,k) using the formula
% g^ni*g^mj*c_mnk = c^ij_k
templist:={}$
operator c_hi$
for i:=1:ncomp do
 for j:=1:ncomp do
  for k:=1:ncomp do
   c_hi(i,j,k):=
    <<
     templist:=
      for m:=1:ncomp join
       for n:=1:ncomp collect
        gu3(n,i)*gu3(m,j)*c_lo(m,n,k)$
     templist:=part(templist,0):=plus
    >>$

% Command to check the matrices c^ij_k - Compare with Potemin-Balandin's
% paper - recall that there is a misprint in their expression, when k=2
% the only nonzero term should be 1.
%
% for i:=1:3 do for j:=1:3 do write "c_hi(",i,",",j,",",1,"):=",c_hi(i,j,1);

% Introduce the contracted operator
operator c_hi_con$
for i:=1:ncomp do
 for j:=1:ncomp do
  c_hi_con(i,j):=
   <<
    templist:=for k:=1:ncomp collect c_hi(i,j,k)*mkid(part(dep_var,k),!_x)$
    templist:=part(templist,0):=plus
   >>$

% The operator aa2 is the ansatz for the second hamiltonian operator aa
mk_cdiffop(aa2,1,{3},3)$
for all i,j,psi let aa2(i,j,psi) =
td(
  gu3(i,j)*td(psi,x,2)+c_hi_con(i,j)*td(psi,x)
    ,x
)$

% Now I start to compute Schouten brackets
conv_cdiff2superfun(aa1,sym1)$
conv_cdiff2superfun(aa2,sym2)$

biv1:=conv_genfun2biv(sym1)$
biv2:=conv_genfun2biv(sym2)$

schouten_bracket(biv1,biv1);
schouten_bracket(biv1,biv2);
schouten_bracket(biv2,biv2);

;end;

Local Variables:
mode:reduce
End:
