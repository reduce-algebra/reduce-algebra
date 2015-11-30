

		  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		  %   Twisting type N solutions of GR   %
		  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% The problem is to analyse an ansatz for a particular type of vacuum
% solution to Einstein's equations for general relativity. The analysis was
% described by Finley and Price (Proc Aspects of GR and Math Phys
% (Plebanski Festschrift), Mexico City June 1993). The equations resulting
% from the ansatz are:

% F    - F*gamma = 0
%  3 3
%
% F   *x  + 2*F *x    + x     *F - x *Delta*F = 0
%  2 2  1      2  1 2    1 2 2      1
%
% 2*F   *x    + 2*F *x      + 2*F   *x    + 2*F *x      + x       *F = 0
%    2 3  2 3      2  2 3 3      3 2  2 3      3  2 2 3    2 2 3 3
%
% Delta =0       Delta  neq 0
%      3	           1      
%
% gamma =0       gamma  neq 0
%      2	           1      

% where the unknowns are {F,x,gamma,Delta} and the indices refer to
% derivatives with respect to an anholonomic basis. The highest order is 4,
% but the 4th order jet bundle is too large for practical computation, so
% it is necessary to construct partial prolongations. There is a single
% known solution, due to Hauser, which is verified at the end.

on evallhseqp,edssloppy,edsverbose;
off arbvars,edsdebug;

pform {f,x,delta,gamma,v,y,u}=0;
pform v(i)=0,omega(i)=1;
indexrange {i,j,k,l}={1,2,3};

% Construct J1({v,y,u},{x}) and transform coordinates. Use ordering
% statement to get v eliminated in favour of x where possible.
% NB Coordinate change cc1 is invertible only when x(-1) neq 0.

j1 := contact(1,{v,y,u},{x});
korder x(-1),x(-2),v(-3);
cc1 :=	{x(-v) = x(-1),
	 x(-y) = x(-2),
	 x(-u) = -x(-1)*v(-3)};
j1 := restrict(pullback(j1,cc1),{x(-1) neq 0});

% Set up anholonomic cobasis

bc1 :=	{omega(1) = d v - v(-3)*d u,
	 omega(2) = d y,
	 omega(3) = d u};
j1 := transform(j1,bc1);

% Prolong to J421: 4th order in x, 2nd in F and 1st in rest

j2 := prolong j1$
j20 := j2 cross {f}$
j31 := prolong j20$
j310 := j31 cross {delta,gamma}$
j421 := prolong j310$
cc4 := first pullback_maps;

% Apply first order de and restrictions

de1 :=	{delta(-3) = 0,
	 gamma(-2) = 0,
	 delta(-1) neq 0,
	 gamma(-1) neq 0};

j421 := pullback(j421,de1)$

% Main de in original coordinates 

de2 :=	{f(-3,-3) - gamma*f,
	 x(-1)*f(-2,-2) + 2*x(-1,-2)*f(-2)
		 + (x(-1,-2,-2) - x(-1)*delta)*f,
	 x(-2,-3)*(f(-2,-3)+f(-3,-2)) + x(-2,-2,-3)*f(-3)
		 + x(-2,-3,-3)*f(-2) + (1/2)*x(-2,-2,-3,-3)*f};

% This is not expressed in terms of current coordinates.
% Missing coordinates are seen from 1-form variables in following

d de2 xmod cobasis j421;

% The necessary equation is contained in the last prolongation

pullback(d de2,cc4) xmod cobasis j421;

% Apply main de

pb1 := first solve(pullback(de2,cc4),{f(-3,-3),f(-2,-2),f(-2,-3)});
y421 := pullback(j421,pb1)$

% Check involution

on ranpos;
characters y421;
dim_grassmann_variety y421;

% 15+2*7 = 29 > 28: Y421 not involutive, so prolong

y532 := prolong y421$

characters y532;
dim_grassmann_variety y532;

% 22+2*6 = 34: just need to check for integrability conditions

torsion y532;

% Y532 involutive. Dimensions?

dim y532;
length one_forms y532;

% The following puts in part of Hauser's solution and ends up with an ODE
% system (all characters 0), so no more solutions, as described by Finley
% at MG6.

hauser := {x=-v+(1/2)*(y+u)**2,delta=3/(8x),gamma=3/(8v)};
h532 := pullback(y532,hauser)$
lift ws;
characters ws;

clear v(i),omega(i);
clear f,x,delta,gamma,v,y,u,omega;
off ranpos;



	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%   Isometric embeddings of Ricci-flat R(4) in ISO(10)   %
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Determine the Cartan characters of a Ricci-flat embedding of R(4) into
% the orthonormal frame bundle ISO(10) over flat R(6).  Reference:
% Estabrook & Wahlquist, Class Quant Grav 10(1993)1851

% Indices

indexrange {p,q,r,s}={1,2,3,4,5,6,7,8,9,10},
      	   {i,j,k,l}={1,2,3,4},{a,b,c,d}={5,6,7,8,9,10};

% Metric for R10

pform g(p,q)=0;
g(p,q) := 0$ g(-p,-q) := 0$ g(-p,-p) := g(p,p) := 1$

% Hodge map for R4

pform epsilon(i,j,k,l)=0;
index_symmetries epsilon(i,j,k,l):antisymmetric;
epsilon(1,2,3,4) := 1;

% Coframe for ISO(10)
% NB index_symmetries must come after o(p,-q) := ... (EXCALC bug)

pform e(r)=1,o(r,s)=1;
korder index_expand {e(r)};
e(-p) := g(-p,-q)*e(q)$
o(p,-q) := o(p,r)*g(-r,-q)$
index_symmetries o(p,q):antisymmetric;

% Structure equations

flat_no_torsion := {d e(p) => -o(p,-q)^e(q),
      	       	    d o(p,q) => -o(p,-r)^o(r,q)};

% Coframing structure

iso := coframing({e(p),o(p,q)},flat_no_torsion)$
dim iso;

% 4d curvature 2-forms

pform f(i,j)=2;
index_symmetries f(i,j):antisymmetric;
f(-i,-j) := -g(-i,-k)*o(k,-a)^o(a,-j);

% EDS for vacuum GR (Ricci-flat) in 4d

gr0 := eds({e(a),epsilon(i,j,k,l)*f(-j,-k)^e(-l)},
	   {e(i)},
      	   iso)$

% Find an integral element, and linearise

z := integral_element gr0$
grz := linearise(gr0,z)$

% This actually tells us the characters already:
%  {45-39,39-29,29-21,21} = {6,10,8,21}

% Get the characters and dimension at Z

characters grz;
dim_grassmann_variety grz;

% 6+2*10+3*8+4*21 = 134, so involutive

clear e(r),o(r,s),g(p,q),epsilon(i,j,k,l),f(i,j);
clear e,o,g,epsilon,f,z;
indexrange 0;

			%%%%%%%%%%%%%%%%%%%%%%%%%%
			%   Janet's PDE system   %
			%%%%%%%%%%%%%%%%%%%%%%%%%%

% This is something of a standard test problem in analysing integrability
% conditions. Although it looks very innocent, it must be prolonged five
% times from the second jet bundle before reaching involution. The initial 
% equations are just
%
%     u   =w,    u   =u   *y + v
%      y y        z z  x x 

load sets;
off varopt;
pform {x,y,z,u,v,w}=0$

janet := contact(2,{x,y,z},{u,v,w})$
janet := pullback(janet,{u(-y,-y)=w,u(-z,-z)=y*u(-x,-x)+v})$

% Prolong to involution

involutive janet;
involution janet;
involutive ws;

% Solve the homogeneous system, for which the
% involutive prolongation is completely integrable

fdomain u=u(x,y,z),v=v(x,y,z),w=w(x,y,z);

janet := {@(u,y,y)=0,@(u,z,z)=y*@(u,x,x)};
janet := involution pde2eds janet$

% Check if completely integrable
if frobenius janet then write "yes" else write "no";
length one_forms janet;

% So there are 12 constants in the solution: there should be 12 invariants

length(c := invariants janet);
solve(for i:=1:length c collect
         part(c,i) = mkid(k,i),coordinates janet \ {x,y,z})$
s := select(lhs ~q = u,first ws);

% Check solution
mkdepend dependencies;
sub(s,{@(u,y,y),@(u,z,z)-y*@(u,x,x)});

clear u(i,j),v(i,j),w(i,j),u(i),v(i),w(i);
clear x,y,z,u,v,w,c,s;

end;
