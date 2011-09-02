% test of DUMMY package version 1.0 running in REDUCE 3.5
% DATE: 15 February 1994
% Authors: A. Dresse <adresse@ulb.ac.be>
%          H. Caprasse <caprasse@vm1.ulg.ac.be>
%
% Case of commuting operator:
%
operator co1,co2;

% declare dummy indices

% first syntax : base <name>
%
dummy_base dv;

% dummy indices are dv1, dv2, dv3, ...

exp := co2(dv2)*co2(dv2)$
c_exp := canonical(exp);

exp := dv2*co2(dv2)*co2(dv2)$
c_exp := canonical(exp);

exp := c_exp * co1(dv3);
c_exp := canonical(exp);

% aliases for dummy indices
%
dummy_names i,j,k;
canonical(c_exp);

% remove dummy_names
clear_dummy_names;

% Case of anticommuting operators
%
operator ao1, ao2;
anticom ao1, ao2;
% product of anticommuting operators with FREE indices
a_exp := ao1(s1)*ao1(s2) - ao1(s2)*ao1(s1);
a_exp := canonical(a_exp);

% the indices are summed upon, i.e. are DUMMY indices
a_exp := ao1(dv1)*ao1(dv2)$
canonical(a_exp);

a_exp := ao1(dv1)*ao1(dv2) - ao1(dv2)*ao1(dv1);
a_exp := canonical(a_exp);

a_exp := ao1(dv2,dv3)*ao2(dv1,dv2)$
a_exp := canonical(a_exp);

a_exp := ao1(dv1)*ao1(dv3)*ao2(dv3)*ao2(dv1)$
a_exp := canonical(a_exp);

% Case of non commuting operators
%
operator no1, no2, no3;
noncom no1, no2, no3;

n_exp := no3(dv2)*no2(dv3)*no1(dv1) + no3(dv3)*no2(dv1)*no1(dv2)
         + no3(dv1)*no2(dv2)*no1(dv3);

n_exp:=canonical n_exp;

% Case of mixed commutation properties
% ***
% The example below displays a restriction of the package i.e
% The non commuting operators are ASSUMED to COMMUTE with the
% anticommuting operators.
% ***
exp := co1(dv1)*ao1(dv2,dv1,dv4)*no1(dv1,dv5)*co2(dv3)*ao1(dv1,dv3);
canonical(exp);

exp := c_exp * a_exp * no3(dv2)*no2(dv3)*no1(dv1);
can_exp := canonical(exp);

% Case of internal symmetries of operators
%
operator as1, as2;
antisymmetric as1, as2;
clear_dummy_base ;
dummy_base s;
% First a non trivial expression:

asc_exp:=as1(s1,s2)*as1(s1,s3)*as1(s3,s4)*co1(s3)*co1(s4)+
        2*as1(s1,s2)*as1(s1,s3)*as1(s3,s4)*co1(s2)*co1(s4)$

canonical asc_exp;
% Second simple illustrative examples:

clear_dummy_base;
dummy_base dv;

exp1 := ao1(dv1)*ao1(dv2)$
canonical(exp1);

exp2 := as1(dv1,dv2)$
canonical(exp2);

canonical(exp1*exp2);

canonical(as1(dv1,dv2)*as2(dv2,dv1));

operator ss1, ss2;
symmetric ss1, ss2;

exp := ss1(dv1,dv2)*ss2(dv1,dv2) - ss1(dv2,dv3)*ss2(dv2,dv3);
canonical(exp);

exp := as1(dv1,dv2)*as1(dv3,dv4)*as1(dv1,dv4);
canonical(exp);
% Indeed the result is equal to half the sum given below:
%
exp + sub(dv2 = dv3, dv3 = dv2, dv1 = dv4, dv4 = dv1, exp);

exp1 := as2(dv3,dv2)*as1(dv3,dv4)*as1(dv1,dv2)*as1(dv1,dv4);
canonical(exp1);

exp2 := as2(dv1,dv4)*as1(dv1,dv3)*as1(dv2,dv4)*as1(dv2,dv3);
canonical(exp2);

canonical(exp1-exp2);

% Indeed:
%
exp2 - sub(dv1 = dv3, dv2 = dv1, dv3 = dv4, dv4 = dv2, exp1);

% Declare the internal symmetry properties of the Riemann tensor
%
operator r;
symtree (r, {!+, {!-, 1, 2}, {!-, 3, 4}});

canonical( r(x,y,z,t) );
canonical( r(x,y,t,z) );
canonical( r(t,z,y,x) );

exp := r(dv1, dv2, dv3, dv4) * r(dv2, dv1, dv4, dv3)$
canonical(exp);

exp := r(dv1, dv2, dv3, dv4) * r(dv1, dv3, dv2, dv4)$
canonical(exp);

dummy_names i,j,k,l;
canonical(exp);

exp := r(i,j,k,l)*ao1(i,j)*ao1(k,l);
canonical(exp);

exp := r(k,i,l,j)*as1(k,i)*as1(k,j);
canonical(exp);

clear_dummy_names; clear_dummy_base;

exp := co1(dv3)$
c_exp := canonical(exp);

end;
