% Author H.-G. Graebe | Univ. Leipzig | Version 6.9.1998
% graebe@informatik.uni-leipzig.de

COMMENT 

Test suite for the package GEOMETRY 1.1

end comment;

algebraic;
load cali,geometry;
off nat;
on echo;
showtime;


% #####################
% Some one line proofs
% #####################

% A generic triangle ABC

a:=point(a1,a2); b:=point(b1,b2); c:=point(c1,c2);

% Its midpoint perpendiculars have a point in common:

	concurrent(mp(a,b),mp(b,c),mp(c,a));
 
% This point

	m:=intersection_point(mp(a,b),mp(b,c));

% is the center of the circumscribed circle

	sqrdist(m,a) - sqrdist(m,b);	

% The altitutes intersection theorem

	concurrent(altitude(a,b,c),altitude(b,c,a),altitude(c,a,b));

% The median intersection theorem

	concurrent(median(a,b,c),median(b,c,a),median(c,a,b));

% Euler's line

        m:=intersection_point(mp(a,b),mp(b,c));
        h:=intersection_point(altitude(a,b,c),altitude(b,c,a));
        s:=intersection_point(median(a,b,c),median(b,c,a));

                collinear(m,h,s);
                sqrdist(s,varpoint(m,h,2/3));

% Feuerbach's circle

	% Choose a special coordinate system
	a:=point(0,0); b:=point(u1,0); c:=point(u2,u3);

        m:=intersection_point(mp(a,b),mp(b,c));
        h:=intersection_point(altitude(a,b,c),altitude(b,c,a));
        n:=midpoint(m,h);

                sqrdist(n,midpoint(a,b))-sqrdist(n,midpoint(b,c));
                sqrdist(n,midpoint(a,b))-sqrdist(n,midpoint(h,c));

        d:=intersection_point(pp_line(a,b),pp_line(h,c));

                sqrdist(n,midpoint(a,b))-sqrdist(n,d);

clear_ndg(); clear(a,b,c,d,m,h,s,n);

% ############################# 
% Non-linear Geometric Objects
% #############################

% Bisector intersection theorem
 
a:=point(0,0); b:=point(1,0); c:=point(u1,u2);
p:=point(x1,x2);
 
polys:={
        point_on_bisector(p,a,b,c),
        point_on_bisector(p,b,c,a),
        point_on_bisector(p,c,a,b)};

con1:=num(sqrdist(p,pedalpoint(p,pp_line(a,c)))-x2^2);
con2:=num(sqrdist(p,pedalpoint(p,pp_line(b,c)))-x2^2);

setring({x1,x2},{},lex);
setideal(polys,polys);
gbasis polys;
{con1,con2} mod gbasis polys;

% Bisector intersection theorem. A constructive proof.
 
a:=point(0,0); b:=point(1,0); p:=point(u1,u2);
l1:=pp_line(a,b);
l2:=symline(l1,pp_line(a,p));
l3:=symline(l1,pp_line(b,p));

point_on_bisector(p,a,b,intersection_point(l2,l3));

clear_ndg(); clear(a,b,c,p,l1,l2,l3);

% Miquel's theorem

on gcd;
a:=point(0,0); b:=point(1,0); c:=point(c1,c2);
p:=choose_pl(pp_line(a,b),u1);
q:=choose_pl(pp_line(b,c),u2);
r:=choose_pl(pp_line(a,c),u3);

x:=other_cc_point(p,p3_circle(a,p,r),p3_circle(b,p,q))$

point_on_circle(x,p3_circle(c,q,r));

off gcd;
clear_ndg(); clear(a,b,c,p,q,r,x);

% ########################
% Theorems of linear type
% ########################

% Pappus' theorem

a:=point(u1,u2); b:=point(u3,u4); c:=point(x1,u5); 
p:=point(u6,u7); q:=point(u8,u9); r:=point(u0,x2);

polys:={collinear(a,b,c), collinear(p,q,r)};

con:=collinear(
	intersection_point(pp_line(a,q),pp_line(p,b)),
	intersection_point(pp_line(a,r),pp_line(p,c)),
	intersection_point(pp_line(b,r),pp_line(q,c)))$

vars:={x1,x2};
sol:=solve(polys,vars);

sub(sol,con);

% Pappus' theorem. A constructive approach

a:=point(u1,u2); b:=point(u3,u4);  
p:=point(u6,u7); q:=point(u8,u9); 

c:=choose_pl(pp_line(a,b),u5);
r:=choose_pl(pp_line(p,q),u0);

con:=collinear(intersection_point(pp_line(a,q),pp_line(p,b)),
	intersection_point(pp_line(a,r),pp_line(p,c)),
	intersection_point(pp_line(b,r),pp_line(q,c)));

clear_ndg(); clear(a,b,c,p,q,r);

% ###########################
% Theorems of non linear type
% ###########################

% Fermat Point

a:=point(0,0); b:=point(0,2); c:=point(u1,u2);
p:=point(x1,x2); q:=point(x3,x4); r:=point(x5,x6);

polys1:={sqrdist(p,b)-sqrdist(b,c), sqrdist(p,c)-sqrdist(b,c), 
	sqrdist(q,a)-sqrdist(a,c), sqrdist(q,c)-sqrdist(a,c), 
	sqrdist(r,b)-sqrdist(a,b), sqrdist(r,a)-sqrdist(a,b)};

con:=concurrent(pp_line(a,p), pp_line(b,q), pp_line(c,r));

vars:={x1,x2,x3,x4,x5,x6};
setring(vars,{},lex);
iso:=isolatedprimes polys1;

for each u in iso collect con mod u;

polys2:={sqrdist(p,b)-sqrdist(p,c), 
	sqrdist(q,a)-sqrdist(q,c),  
	sqrdist(r,a)-sqrdist(r,b), 
	num(p3_angle(r,a,b)-p3_angle(p,b,c)), 
	num(p3_angle(q,c,a)-p3_angle(p,b,c))};

sol:=solve(polys2,{x1,x2,x3,x4,x6});
sub(sol,con);

clear_ndg(); clear(a,b,c,p,q,r);

% ####################
%  Desargue's theorem
% ####################

% A constructive proof.

a:=point(a1,a2); b:=point(b1,b2); 
c:=point(c1,c2); r:=point(d1,d2);

s:=choose_pl(par(r,pp_line(a,b)),u);
t:=intersection_point(par(r,pp_line(a,c)),par(s,pp_line(b,c)));
 
con:=concurrent(pp_line(a,r),pp_line(b,s),pp_line(c,t));

% Desargue's theorem as theorem of linear type.

a:=point(u1,u2); b:=point(u3,u4); c:=point(u5,u6);
r:=point(u7,u8); s:=point(u9,x1); t:=point(x2,x3);

polys:={parallel(pp_line(r,s),pp_line(a,b)),
	parallel(pp_line(s,t),pp_line(b,c)),
	parallel(pp_line(r,t),pp_line(a,c))};

con:=concurrent(pp_line(a,r),pp_line(b,s),pp_line(c,t));

sol:=solve(polys,{x1,x2,x3});
sub(sol,con);

% The general theorem of Desargue.

a:=point(0,0); b:=point(0,1); c:=point(u5,u6);
r:=point(u7,u8); s:=point(u9,u1); t:=point(u2,x1);

con1:=collinear(intersection_point(pp_line(r,s),pp_line(a,b)),
	intersection_point(pp_line(s,t),pp_line(b,c)),
	intersection_point(pp_line(r,t),pp_line(a,c)));

con2:=concurrent(pp_line(a,r),pp_line(b,s),pp_line(c,t));

sol:=solve(con2,x1);
sub(sol,con1);

clear_ndg(); clear(a,b,c,r,s,t);

% #################
%  Brocard points
% #################

a:=point(0,0); b:=point(1,0); c:=point(u1,u2);

c1:=circle(1,x1,x2,x3);
c2:=circle(1,x4,x5,x6);
c3:=circle(1,x7,x8,x9);

polys:={
	cl_tangent(c1,pp_line(a,c)), 
	point_on_circle(a,c1), 
	point_on_circle(b,c1), 
	cl_tangent(c2,pp_line(a,b)), 
	point_on_circle(b,c2), 
	point_on_circle(c,c2), 
	cl_tangent(c3,pp_line(b,c)), 
	point_on_circle(a,c3), 
	point_on_circle(c,c3)};
 
vars:={x1,x2,x3,x4,x5,x6,x7,x8,x9};
sol:=solve(polys,vars);

p:=other_cc_point(b,sub(sol,c1),sub(sol,c2));
con:=point_on_circle(p,sub(sol,c3));

clear_ndg(); clear a,b,c,c1,c2,c3;	

% ##################
%  Simson's theorem
% ##################

% A constructive proof

        m:=point(0,0);
        a:=choose_pc(m,r,u1);
        b:=choose_pc(m,r,u2);
        c:=choose_pc(m,r,u3);
        p:=choose_pc(m,r,u4);
        x:=pedalpoint(p,pp_line(a,b))$
        y:=pedalpoint(p,pp_line(b,c))$
        z:=pedalpoint(p,pp_line(a,c))$
 
        collinear(x,y,z);

clear_ndg(); clear(m,a,b,c,p,x,y,z);

% Simson's theorem almost constructive

clear_ndg();

	a:=point(0,0); b:=point(u1,u2); 
	c:=point(u3,u4); p:=point(u5,x1);
        x:=pedalpoint(p,pp_line(a,b));
        y:=pedalpoint(p,pp_line(b,c));
        z:=pedalpoint(p,pp_line(a,c));

	poly:=p4_circle(a,b,c,p); 

        con:=collinear(x,y,z);

	remainder(num con,poly);

print_ndg();

% Equational proof, first version:

m:=point(0,0); a:=point(0,1); 
b:=point(u1,x1); c:=point(u2,x2); p:=point(u3,x3);

x:=varpoint(a,b,x4); y:=varpoint(b,c,x5); z:=varpoint(a,c,x6);

polys:={sqrdist(m,b)-1, sqrdist(m,c)-1, sqrdist(m,p)-1,
	orthogonal(pp_line(a,b),pp_line(p,x)),
	orthogonal(pp_line(a,c),pp_line(p,z)),
	orthogonal(pp_line(b,c),pp_line(p,y))};

con:=collinear(x,y,z);

vars:={x4,x5,x6,x1,x2,x3};
setring(vars,{},lex);
setideal(polys,polys);
con mod gbasis polys;

% Second version:

a:=point(0,0);
b:=point(1,0);
c:=point(u1,u2);
p:=point(u3,x1);
x:=point(x2,0);		% => on the line AB 
y:=varpoint(b,c,x3);
z:=varpoint(a,c,x4);

polys:={orthogonal(pp_line(a,c),pp_line(p,z)),
	orthogonal(pp_line(b,c),pp_line(p,y)),
	orthogonal(pp_line(a,b),pp_line(p,x)),
       	p4_circle(a,b,c,p)};

con:=collinear(x,y,z);

vars:={x2,x3,x4,x1};
setring(vars,{},lex);
con mod interreduce polys;

% The inverse theorem

polys:={orthogonal(pp_line(a,c),pp_line(p,z)),
	orthogonal(pp_line(b,c),pp_line(p,y)),
	orthogonal(pp_line(a,b),pp_line(p,x)),
       	collinear(x,y,z)};

con:=p4_circle(a,b,c,p);

con mod interreduce polys;

clear_ndg(); clear(m,a,b,c,p,y,z);

% ########################
%  The butterfly theorem
% ########################
 
% An equational proof with groebner factorizer and constraints. 

p:=point(0,0);
o:=point(u1,0);
a:=point(u2,u3);	
b:=point(u4,x1);
c:=point(x2,x3); 
d:=point(x4,x5); 
f:=point(0,x6);
g:=point(0,x7);

polys:={sqrdist(o,b)-sqrdist(o,a), 
	sqrdist(o,c)-sqrdist(o,a), 
	sqrdist(o,d)-sqrdist(o,a),
	point_on_line(p,pp_line(a,c)),
	point_on_line(p,pp_line(b,d)),
	point_on_line(f,pp_line(a,d)),
	point_on_line(g,pp_line(b,c))
};

con:=num sqrdist(p,midpoint(f,g));

vars:={x6,x7,x3,x5,x1,x2,x4};
setring(vars,{},lex);

sol:=groebfactor(polys,{sqrdist(a,c),sqrdist(b,d)});

for each u in sol collect con mod u;

% A constructive proof

on gcd;

o:=point(0,0);
a:=point(1,0);	
b:=choose_pc(o,1,u1);
c:=choose_pc(o,1,u2);
d:=choose_pc(o,1,u3);
p:=intersection_point(pp_line(a,c),pp_line(b,d));

h:=lot(p,pp_line(o,p));

f:=intersection_point(h,pp_line(a,d)); 
g:=intersection_point(h,pp_line(b,c));

con:=sqrdist(p,midpoint(f,g));

off gcd;
clear_ndg(); clear(o,a,b,c,d,p,h,f,g);

% ################################
% Tangency of Feuerbach's circle
% ################################
 
a:=point(0,0); b:=point(2,0); c:=point(u1,u2);
m:=intersection_point(mp(a,b),mp(b,c));
h:=intersection_point(altitude(a,b,c),altitude(b,c,a));
n:=midpoint(m,h);	
c1:=c1_circle(n,sqrdist(n,midpoint(a,b)));
			% Feuerbach's circle

p:=point(x1,x2);	% => x2 is the radius of the inscribed circle. 

polys:={point_on_bisector(p,a,b,c), point_on_bisector(p,b,c,a)};

con:=cc_tangent(c1_circle(p,x2^2),c1); 

vars:={x1,x2};
setring(vars,{},lex);
setideal(polys,polys);
num con mod gbasis polys;

% Now let P be the incenter of the triangle ABH

polys1:={point_on_bisector(p,a,b,h), point_on_bisector(p,b,h,a)};

con1:=cc_tangent(c1_circle(p,x2^2),c1); 
setideal(polys1,polys1);
num con1 mod gbasis polys1;

clear_ndg(); clear a,b,c,p,m,n,h,c1;

% #############################
% Solutions to the exercises
% #############################

% 1)

a:=point(0,0); b:=point(1,0); c:=point(1,1); d:=point(0,1);
p:=point(x1,x2); q:=point(x3,1);

polys:={point_on_line(p,par(c,pp_line(b,d))),
	sqrdist(b,d)-sqrdist(b,p),
	point_on_line(q,pp_line(b,p))};

con:=sqrdist(d,p)-sqrdist(d,q);

setring({x1,x2,x3},{},lex);
setideal(polys,polys);
con mod gbasis polys;

clear_ndg(); clear(a,b,c,d,p,q);

% 2)

a:=point(u1,0); b:=point(u2,0); c:=point(0,u3); 
q:=point(0,0);		% the pedal point on AB
r:=pedalpoint(b,pp_line(a,c)); 
p:=pedalpoint(a,pp_line(b,c)); 

con1:=point_on_bisector(c,p,q,r);
con2:=angle_sum(p3_angle(p,q,c),p3_angle(r,q,c));

clear_ndg(); clear(a,b,c,p,q,r);

% 3)

a:=point(u1,0); b:=point(u2,0); c:=point(0,u3); 
p:=pedalpoint(a,pp_line(b,c)); 
q:=pedalpoint(b,pp_line(a,c)); 
r:=pedalpoint(c,pp_line(a,b));

p1:=pedalpoint(p,pp_line(a,b));
p2:=pedalpoint(p,pp_line(a,c));
q1:=pedalpoint(q,pp_line(a,b));
q2:=pedalpoint(q,pp_line(b,c));
r1:=pedalpoint(r,pp_line(a,c));
r2:=pedalpoint(r,pp_line(b,c));

con:=for each x in {q2,r1,r2} collect p4_circle(p1,p2,q1,x);

clear_ndg(); clear(o,a,b,c,p,q,r,p1,p2,q1,q2,r1,r2);

% 4) 

a:=point(u1,0); b:=point(u2,0); c:=point(0,u3); 
		% => Pedalpoint from C is (0,0)
m:=intersection_point(mp(a,b),mp(b,c));

% Prove (2*h_c*R = a*b)^2

con:=4*u3^2*sqrdist(m,a)-sqrdist(c,b)*sqrdist(a,c);

clear_ndg(); clear(a,b,c,m);

% 5. A solution of constructive type.

on gcd;
o:=point(0,u1); a:=point(0,0);	% hence k has radius u1.
b:=point(u2,0);
m:=midpoint(a,b);
d:=choose_pc(o,u1,u3); 
k:=c1_circle(o,u1^2);
c:=other_cl_point(d,k,pp_line(m,d));
eh:=other_cl_point(d,k,pp_line(b,d));
f:=other_cl_point(c,k,pp_line(b,c));

con:=parallel(pp_line(a,b),pp_line(eh,f));

off gcd;
clear_ndg(); clear(o,a,b,c,d,eh,f,m,k);

% 6)

z:=point(0,0); x:=point(0,1); y:=point(0,-1); 
b:=point(u1,0); c:=point(u2,0); p:=point(0,u3);
m:=point(x1,x2); n:=point(x3,x4); 
a:=point(x5,0); d:=point(x6,0);

polys:={p4_circle(x,y,b,n), p4_circle(x,y,c,m),
	p4_circle(x,y,b,d), p4_circle(x,y,c,a),
	collinear(b,p,n), collinear(c,p,m)};

con:=concurrent(pp_line(a,m),pp_line(d,n),pp_line(x,y));

vars:={x1,x2,x3,x4,x5,x6};
setring(vars,{},lex);
res:=groebfactor(polys,{x5-u2,x1-u2,x6-u1,x3-u1});
	% constraints A\neq C, M\neq C, D\neq B, N\neq B
for each u in res collect con mod u;

clear_ndg(); clear(z,x,y,b,c,p,m,n,a,d);

% 7)

m:=point(0,0);
a:=point(0,u1); b:=point(-1,0); c:=point(1,0); 
eh:=varpoint(a,b,x1); f:=varpoint(a,c,x2);
o:=intersection_point(pp_line(a,m),lot(b,pp_line(a,b))); 
q:=intersection_point(pp_line(eh,f),pp_line(b,c));

con1:=num orthogonal(pp_line(o,q),pp_line(eh,q));
con2:=num sqrdist(q,midpoint(eh,f));

vars:={x1,x2};
setring(vars,{},lex);
p1:=groebfactor({con1},{x1-1,x2-1,x1,x2});
p2:=groebfactor({con2},{x1-1,x2-1,x1,x2});
	% constraint A,C\neq Eh, B,C\neq F

for each u in p1 collect con2 mod u;
for each u in p2 collect con1 mod u;

% Note that the second component of p2 has no relevant *real* roots,
% since it factors as u1^2 * (x1 - x2)^2 + (x1 + x2 -2)^2 :

u1^2 * (x1 - x2)^2 + (x1 + x2 -2)^2 mod second p2;

clear_ndg(); clear(m,a,b,c,o,eh,f,q);

% 8)

on gcd; 

a:=point(u1,0); b:=point(u2,0); l1:=pp_line(a,b);
m:=point(0,u3);		% the incenter, hence u3 = incircle radius 

c:=intersection_point(symline(l1,pp_line(a,m)),
		symline(l1,pp_line(b,m)));  

n:=intersection_point(mp(a,b),mp(b,c)); % the outcenter

sqr_rad:=sqrdist(a,n);	% the outcircle sqradius.

(sqr_rad-sqrdist(m,n))^2-4*u3^2*sqr_rad;

off gcd;
clear_ndg(); clear a,b,c,m,n,l1,sqr_rad;

% 9)

on gcd;

a:=point(0,0); b:=point(1,0); m:=point(u1,0);
c:=point(u1,u1); f:=point(u1,1-u1);

c1:=red_hom_coords p3_circle(a,m,c); 
c2:=red_hom_coords p3_circle(b,m,f);
n:=other_cc_point(m,c1,c2);

point_on_line(n,pp_line(a,f));
point_on_line(n,pp_line(b,c));

l1:=red_hom_coords pp_line(m,n);
l2:=sub(u1=u2,l1);

intersection_point(l1,l2); % = (1/2,-1/2)

off gcd;
clear_ndg(); clear a,b,c,f,m,n,c1,c2,l1,l2;

% ####################
% Some more examples
% ####################

% Origin: D. Wang at
%	http://cosmos.imag.fr/ATINF/Dongming.Wang/geother.html
% --------------------------
% Given triangle ABC, H orthocenter, O circumcenter, A1 circumcenter
% of BHC, B1 circumcenter of AHC.
%
% Claim: OH, AA1, BB1 are concurrent.
% --------------------------

a:=point(u1,0); b:=point(u2,0); c:=point(0,u3); 
h:=intersection_point(altitude(c,a,b),altitude(a,b,c));
o:=circle_center(p3_circle(a,b,c)); 
a1:=circle_center(p3_circle(h,b,c)); 
b1:=circle_center(p3_circle(h,a,c)); 

con:=concurrent(pp_line(o,h),pp_line(a,a1),pp_line(b,b1));

end;

