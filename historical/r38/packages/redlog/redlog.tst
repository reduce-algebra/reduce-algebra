% ----------------------------------------------------------------------
% $Id: redlog.tst,v 1.7 2002/08/20 14:44:50 seidl Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1997
% Andreas Dolzmann and Thomas Sturm, Universitaet Passau
% ----------------------------------------------------------------------
% $Log: redlog.tst,v $
% Revision 1.7  2002/08/20 14:44:50  seidl
% Moved CAD example to a better place.
%
% Revision 1.6  2002/08/20 14:32:36  seidl
% rlcad cox6 added.
%
% Revision 1.5  1999/04/13 21:53:26  sturm
% Removed "on echo".
%
% Revision 1.4  1999/04/05 12:25:29  dolzmann
% Fixed a bug.
%
% Revision 1.3  1999/04/05 12:15:43  dolzmann
% Added code for testing the contexts acfsf and dvfsf.
%
% Revision 1.2  1997/08/20 16:22:07  sturm
% Do not use "on time".
%
% Revision 1.1  1997/08/18 15:59:01  sturm
% Renamed "rl.red" to "redlog.red", and thus "rl.tst" to this file
% "redlog.tst."
%
% ----------------------------------------------------------------------
% Revision 1.3  1996/10/14 16:18:39  sturm
% Added sc50b for testing the optimizer.
%
% Revision 1.2  1996/10/03 16:09:39  sturm
% Added new QE example for testing rlatl, ..., rlifacml, rlstruct,
% rlifstruct.
%
% Revision 1.1  1996/09/30 17:07:52  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------
on rlverbose;

% Ordered fields standard form:
rlset ofsf;
rlset();

% Chains
-3/5<x>y>z<=a<>b>c<5/3;

% For loop actions.
g := for i:=1:6 mkor
   for j := 1:6 mkand
      mkid(a,i) <= mkid(a,j);

% Quantifier elimination and variants
h := rlsimpl rlall g;
rlmatrix h;
on rlrealtime;
rlqe h;
off rlrealtime;

h := rlsimpl rlall(g,{a2});
rlqe h;

off rlqeheu,rlqedfs;
rlqe ex(x,a*x**2+b*x+c>0);
on rlqedfs;
rlqe ex(x,a*x**2+b*x+c>0);
on rlqeheu;

rlqe(ex(x,a*x**2+b*x+c>0),{a<0});

rlgqe ex(x,a*x**2+b*x+c>0);
rlthsimpl ({a*b*c=0,b<>0});


rlqe ex({x,y},(for i:=1:5 product mkid(a,i)*x**10-mkid(b,i)*y**2)<=0);

sol := rlqe ex(x,a*x**2+b*x+c>0);
rlatnum sol;

rlatl sol;
rlatml sol;
rlterml sol;
rltermml sol;
rlifacl sol;
rlifacml sol;

rlstruct(sol,v);
rlifstruct(sol,v);

rlitab sol;
rlatnum ws;
rlgsn sol;
rlatnum ws;

off rlverbose;

rlqea ex(x,m*x+b=0);

% from Marc van Dongen. Finding the first feasible solution for the 
% solution of systems of linear diophantine inequalities.
dong := {
  3*X259+4*X261+3*X262+2*X263+X269+2*X270+3*X271+4*X272+5*X273+X229=2,
  7*X259+11*X261+8*X262+5*X263+3*X269+6*X270+9*X271+12*X272+15*X273+X229=4,
  2*X259+5*X261+4*X262+3*X263+3*X268+4*X269+5*X270+6*X271+7*X272+8*X273=1,
  X262+2*X263+5*X268+4*X269+3*X270+2*X271+X272+2*X229=1,
  X259+X262+2*X263+4*X268+3*X269+2*X270+X271-X273+3*X229=2,
  X259+2*X261+2*X262+2*X263+3*X268+3*X269+3*X270+3*X271+3*X272+3*X273+X229=1,
     X259+X261+X262+X263+X268+X269+X270+X271+X272+X273+X229=1};
sol := rlopt(dong,0);

% Substitution
sub(first second sol,for each atf in dong mkand atf);
rlsimpl ws;
sub(x=a,x=0 and a=0 and ex(x,x=y) and ex(a,x>a));

f1 := x=0 and b>=0;
f2 := a=0;
f := f1 or f2;

% Boolean normal forms.
rlcnf f;

rldnf ws;

rlcnf f;

% Negation normal form and prenex normal form
hugo := a=0 and b=0 and y<0 equiv ex(y,y>=a) or a>0;
rlnnf hugo;
rlpnf hugo;

% Length and Part
part(hugo,0);
part(hugo,2,1,2);
length ws;
length hugo;
length part(hugo,1);

% Tableau
mats := all(t,ex({l,u},(
(t>=0 and t<=1) impl
(l>0 and u<=1 and
  -t*x1+t*x2+2*t*x1*u+u=l*x1 and
  -2*t*x2+t*x2*u=l*x2))));
sol := rlgsn rlqe mats;
rltab(sol,{x1>0,x1<0,x1=0});

% Part on psopfn / cleanupfn
part(rlqe ex(x,m*x+b=0),1);
walter := (x>0 and y>0);
rlsimpl(true,rlatl walter);
part(rlatl walter,1,1);

% Optimizer
sc50b!-t := -1*vCOL00004$

sc50b!-c := {
vCOL00001 >= 0,vCOL00002 >= 0,vCOL00003 >= 0,vCOL00004 >= 0,vCOL00005 >= 0,
vCOL00006 >= 0,vCOL00007 >= 0,vCOL00008 >= 0,vCOL00009 >= 0,vCOL00010 >= 0,
vCOL00011 >= 0,vCOL00012 >= 0,vCOL00013 >= 0,vCOL00014 >= 0,vCOL00015 >= 0,
vCOL00016 >= 0,vCOL00017 >= 0,vCOL00018 >= 0,vCOL00019 >= 0,vCOL00020 >= 0,
vCOL00021 >= 0,vCOL00022 >= 0,vCOL00023 >= 0,vCOL00024 >= 0,vCOL00025 >= 0,
vCOL00026 >= 0,vCOL00027 >= 0,vCOL00028 >= 0,vCOL00029 >= 0,vCOL00030 >= 0,
vCOL00031 >= 0,vCOL00032 >= 0,vCOL00033 >= 0,vCOL00034 >= 0,vCOL00035 >= 0,
vCOL00036 >= 0,vCOL00037 >= 0,vCOL00038 >= 0,vCOL00039 >= 0,vCOL00040 >= 0,
vCOL00041 >= 0,vCOL00042 >= 0,vCOL00043 >= 0,vCOL00044 >= 0,vCOL00045 >= 0,
vCOL00046 >= 0,vCOL00047 >= 0,vCOL00048 >= 0,
3*vCOL00001+(3*vCOL00002)+(3*vCOL00003) <= 300,
1*vCOL00004+(-1*vCOL00005) = 0,
-1*vCOL00001+(1*vCOL00006) = 0,
-1*vCOL00002+(1*vCOL00007) = 0,
-1*vCOL00003+(1*vCOL00008) = 0,
-1*vCOL00006+(1*vCOL00009) <= 0,
-1*vCOL00007+(1*vCOL00010) <= 0,
-1*vCOL00008+(1*vCOL00011) <= 0,
-1*vCOL00009+(3*vCOL00012)+(3*vCOL00013)+(3*vCOL00014) <= 300,
0.400000*vCOL00005+(-1*vCOL00010) <= 0,
0.600000*vCOL00005+(-1*vCOL00011) <= 0,
1.100000*vCOL00004+(-1*vCOL00015) = 0,
1*vCOL00005+(1*vCOL00015)+(-1*vCOL00016) = 0,
-1*vCOL00006+(-1*vCOL00012)+(1*vCOL00017) = 0,
-1*vCOL00007+(-1*vCOL00013)+(1*vCOL00018) = 0,
-1*vCOL00008+(-1*vCOL00014)+(1*vCOL00019) = 0,
-1*vCOL00017+(1*vCOL00020) <= 0,
-1*vCOL00018+(1*vCOL00021) <= 0,
-1*vCOL00019+(1*vCOL00022) <= 0,
-1*vCOL00020+(3*vCOL00023)+(3*vCOL00024)+(3*vCOL00025) <= 300,
0.400000*vCOL00016+(-1*vCOL00021) <= 0,
0.600000*vCOL00016+(-1*vCOL00022) <= 0,
1.100000*vCOL00015+(-1*vCOL00026) = 0,
1*vCOL00016+(1*vCOL00026)+(-1*vCOL00027) = 0,
-1*vCOL00017+(-1*vCOL00023)+(1*vCOL00028) = 0,
-1*vCOL00018+(-1*vCOL00024)+(1*vCOL00029) = 0,
-1*vCOL00019+(-1*vCOL00025)+(1*vCOL00030) = 0,
-1*vCOL00028+(1*vCOL00031) <= 0,
-1*vCOL00029+(1*vCOL00032) <= 0,
-1*vCOL00030+(1*vCOL00033) <= 0,
-1*vCOL00031+(3*vCOL00034)+(3*vCOL00035)+(3*vCOL00036) <= 300,
0.400000*vCOL00027+(-1*vCOL00032) <= 0,
0.600000*vCOL00027+(-1*vCOL00033) <= 0,
1.100000*vCOL00026+(-1*vCOL00037) = 0,
1*vCOL00027+(1*vCOL00037)+(-1*vCOL00038) = 0,
-1*vCOL00028+(-1*vCOL00034)+(1*vCOL00039) = 0,
-1*vCOL00029+(-1*vCOL00035)+(1*vCOL00040) = 0,
-1*vCOL00030+(-1*vCOL00036)+(1*vCOL00041) = 0,
-1*vCOL00039+(1*vCOL00042) <= 0,
-1*vCOL00040+(1*vCOL00043) <= 0,
-1*vCOL00041+(1*vCOL00044) <= 0,
-1*vCOL00042+(3*vCOL00045)+(3*vCOL00046)+(3*vCOL00047) <= 300,
0.400000*vCOL00038+(-1*vCOL00043) <= 0,
0.600000*vCOL00038+(-1*vCOL00044) <= 0,
1.100000*vCOL00037+(-1*vCOL00048) = 0,
-0.700000*vCOL00045+(0.300000*vCOL00046)+(0.300000*vCOL00047) <= 0,
-1*vCOL00046+(0.400000*vCOL00048) <= 0,
-1*vCOL00047+(0.600000*vCOL00048) <= 0}$

rlopt(sc50b!-c,sc50b!-t);

% QE by partial CAD:
cox6 := ex({u,v},x=u*v and y=u**2 and z=v**2)$
rlcad cox6;

% Algebraically closed fields standard form:
sub(x=a,x=0 and a=0 and ex(x,x=y) and ex(a,x<>a));

rlset acfsf;

rlsimpl(x^2+y^2+1<>0);

rlqe ex(x,x^2=y);

clear f;
h := rlqe ex(x,x^3+a*x^2+b*x+c=0 and x^3+d*x^2+e*x+f=0);
rlstruct h;
rlqe rlall (h equiv resultant(x^3+a*x^2+b*x+c,x^3+d*x^2+e*x+f,x)=0);
clear h;

% Discretely valued fields standard form:
rlset dvfsf;
sub(x=a,x=0 and a=0 and ex(x,x=y) and ex(a,x~a));


% P-adic Balls, taken from Andreas Dolzmann, Thomas Sturm. P-adic
% Constraint Solving, Proceedings of the ISSAC '99.
rlset dvfsf;
rlqe all(r_1,all(r_2,all(a,all(b,
ex(x,r_1||x-a and r_2||x-b and r_1|r_2) impl
all(y,r_2||y-b impl r_1||y-a)))));
rlmkcanonic ws;
rlset(dvfsf,100003);
rlqe all(r_1,all(r_2,all(a,all(b,
ex(x,r_1||x-a and r_2||x-b and r_1|r_2) impl
all(y,r_2||y-b impl r_1||y-a)))));

% Size of the Residue Field, taken from Andreas Dolzmann, Thomas
% Sturm. P-adic Constraint Solving. Proceedings of the ISSAC '99.
rlset(dvfsf);
rlqe ex(x,x~1 and x-1~1 and x-2~1 and x-3~1 and 2~1 and 3~1);
rlexplats ws;
rldnf ws;

% Selecting contexts:

rlset ofsf;
f:= ex(x,m*x+b=0);
rlqe f;
rlset dvfsf;
rlqe f;
rlset acfsf;
rlqe f;

end;  % of file
