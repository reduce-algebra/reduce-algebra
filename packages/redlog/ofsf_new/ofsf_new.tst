off rlabout;
rlset ofsf;
off rlverbose;

% all the qe and variants
phi := ex(x,a*x^2+b*x+c=0)$

rlqe phi;
rlgqe phi;
rlqea phi;
rlgqea phi;
rllqe(phi,{},{b=1});
rlposqe phi;
rlposqea phi;
rlcad phi;
rlgcad phi;
rlhqe phi;
rlghqe phi;

% Local QE Examples from https://doi.org/10.1145/345542.345589
generic_quadratic_equation := ex(x, v2*x^2 + v1*x + v0 = 0)$
rllqe(generic_quadratic_equation, {}, {v2=1, v1=1, v0=1});

generic_polygon3 := ex({x, y},
   for i:=1:3 mkand mkid(a, i)*x + mkid(b, i)*y <= mkid(c, i))$
rllqe(generic_polygon3, {}, {a1=1, a2=-3, a3=5, b1=-7, b2=11, b3=-13});

generic_polygon10 := ex({x, y},
   for i:=1:10 mkand mkid(a, i)*x + mkid(b, i)*y <= mkid(c, i))$
generic_polygon10_p := {
   a1=2,a2=-3,a3=5,a4=-7,a5=11,a6=-13,a7=17,a8=-19,a9=23,a10=-29,
   b1=31,b2=-37,b3=41,b4=-43,b5=47,b6=-53,b7=59,b8=-61,b9=67,b10=-71}$
generic_polygon10_sol := rllqe(generic_polygon10, {}, generic_polygon10_p)$
length first generic_polygon10_sol;
rlatnum second generic_polygon10_sol;

kahans_problem := all({x,y},
   b**2*(x-c)**2+a**2*(y-d)**2-a**2*b**2=0 impl x**2+y**2-1 <=0)$
rllqe(sub(d=0, kahans_problem), {}, {a=1/2, b=1/2, c=1/2});

% Examples from a talk on Isabel by T. Nipkow
wnip := rlall(a>=3/4 and a^2<=b*(c+1) and b<=4c impl (a-1)^2<b*c)$
rlqe wnip;
rlqea wnip;
snip := rlall(a>3/4 and a^2<=b*(c+1) and b<=4c impl (a-1)^2<b*c)$
rlqe snip;
rlqea snip;

%%% Test rlqe (xopt-qe)
mtp2 := ex(x11,ex(x12,ex(x13,ex(x21,ex(x22,ex(x23,ex(x31,ex(x32,ex(x33,
x11+x12+x13=a1 and x21+x22+x23=a2 and x31+x32+x33=a3 and
x11+x21+x31=b1 and x12+x22+x32=b2 and x13+x23+x33=b3 and
0 leq x11 and 0 leq x12 and 0 leq x13 and
0 leq x21 and 0 leq x22 and 0 leq x23 and
0 leq x31 and 0 leq x32 and 0 leq x33
)))))))))$
rlqe mtp2$
rlatnum ws;

%%% Test rlqe (linear)
rp2 := ex(x1,ex(x2,ex(y1,ex(y2,ex(d2,all(u,all(v,((a > 0 and b > 0 and
d1 > 0 and (true and - d1 + d2 > 0)) and (true and x1 >= 0 and - a + d1
+ x1 <= 0 and y1 >= 0 and - b + d1 + y1 <= 0 and x2 >= 0 and - a + d2 +
x2 <= 0 and y2 >= 0 and - b + d2 + y2 <= 0) and not(false or false or
false or ( - x1 + x2 <= 0 and - d2 + x1 - x2 < 0) and ( - y1 + y2 <= 0
and - d2 + y1 - y2 < 0) or ( - d1 - x1 + x2 <= 0 and d1 - d2 + x1 - x2 <
0) and ( - y1 + y2 <= 0 and - d2 + y1 - y2 < 0) or ( - x1 + x2 <= 0 and
- d2 + x1 - x2 < 0) and ( - d1 - y1 + y2 <= 0 and d1 - d2 + y1 - y2 < 0)
or ( - d1 - x1 + x2 <= 0 and d1 - d2 + x1 - x2 < 0) and ( - d1 - y1 + y2
<= 0 and d1 - d2 + y1 - y2 < 0) or false or (x1 - x2 <= 0 and - d1 - x1
+ x2 < 0) and (y1 - y2 <= 0 and - d1 - y1 + y2 < 0) or ( - d2 + x1 - x2
<= 0 and - d1 + d2 - x1 + x2 < 0) and (y1 - y2 <= 0 and - d1 - y1 + y2 <
0) or (x1 - x2 <= 0 and - d1 - x1 + x2 < 0) and ( - d2 + y1 - y2 <= 0
and - d1 + d2 - y1 + y2 < 0) or ( - d2 + x1 - x2 <= 0 and - d1 + d2 - x1
+ x2 < 0) and ( - d2 + y1 - y2 <= 0 and - d1 + d2 - y1 + y2 < 0) or
false)) and (( - u <= 0 and - a + u < 0) and ( - v <= 0 and - b + v < 0)
impl false or ( - u + x1 <= 0 and - d1 + u - x1 < 0) and ( - v + y1 <= 0
and - d1 + v - y1 < 0) or ( - u + x2 <= 0 and - d2 + u - x2 < 0) and ( -
v + y2 <= 0 and - d2 + v - y2 < 0)))))))))$
rp2sol := rlqe rp2;

%%% Test rlqe (DFS)

% Prolog III. Communications of the ACM. 33(7), 70-90, July 1990
% Description of the problem on p.79: Consider the infinite sequence
% of real numbers defined by x_{i+2}:=|x_{i+1}|-x_i where $x_1$ and
% $x_2$ are arbitrary numbers. Our aim is to show that this sequence
% is always periodic and that the period is 9, in other words that the
% sequences $x_1, x_2, \dots$ and $x_{1+9}, x_{2+9}, \dots$ are always
% identical.
p9 := rlall((for i:=1:9 mkand
   mkid(x,i+1)>=0 and mkid(x,i+2)=mkid(x,i+1)-mkid(x,i) or
   mkid(x,i+1)<0 and mkid(x,i+2)=-mkid(x,i+1)-mkid(x,i))
      impl x1=x10 and x2=x11)$
rlqe p9;

%%% Test rlqe nonlinear and fallback

% Hoon Hong, talk at the University of Passau, 20 Dec 2005.
hong := all(x,ex(y,x**2+x*y+b>0 and x+a*y**2+b<=0))$
rlqe hong;

% Positive qe:
% Examples from
% Boulier et al. 2007
% http://dx.doi.org/10.1007/978-3-540-73433-8_6
% for n=9 they prove that a Hopf bifurcation exists
ab2007_hopf_n_9 := ex(vv2,ex(vv1,ex(vv3,(( - vv1 < 0 and - vv3 < 0) and
- vv2 < 0) and (((((( gamma0*theta - theta*vv1*vv3**9 - theta*vv1 = 0
and gamma0*mu + lambda1*vv1 - vv2 = 0) and 9*alpha*gamma0 -
9*alpha*vv1*vv3**9 - 9*alpha*vv1 + delta*vv2 - delta*vv3 = 0) and -
9*delta*lambda1*theta*vv1*vv3**8 - delta*theta*vv3**9 - delta*theta < 0
and 6561*alpha**2*vv1**2*vv3**16 + 81*alpha*delta*theta*vv1*vv3 **17 +
81*alpha*delta*theta*vv1*vv3**8 + 162*alpha*delta*vv1*vv3**8 +
162*alpha* theta*vv1*vv3**17 + 162*alpha*theta*vv1*vv3**8 +
81*alpha*vv1*vv3**8 + delta**2* theta*vv3**9 + delta**2*theta + delta**2
- 9*delta*lambda1*theta*vv1*vv3**8 + delta*theta**2*vv3**18 +
2*delta*theta**2*vv3**9 + delta*theta**2 + 2*delta* theta*vv3**9 +
2*delta*theta + delta + theta**2*vv3**18 + 2*theta**2*vv3**9 + theta**2
+ theta*vv3**9 + theta = 0) and - theta < 0) and - gamma0 < 0) and - mu
< 0) and - delta < 0 and - alpha < 0)))$

rlposqe rlex ab2007_hopf_n_9;

%%% Test rlcad

% Wilkinson's polynomial. Tests how fast root isolation is.
wilk := ex(x,8388608*x**20 + 1761607681*x**19 + 172931153920*x**18 +
10543221964800*x**17 + 447347234439168*x**16 +
14028108264898560*x**15 + 336985244869591040*x**14 +
6342720331186176000*x**13 + 94877480085669019648*x**12 +
1137370949952460554240 *x**11 + 10968398649699241820160*x**10 +
85079777790228273561600*x**9 + 528740774622641958944768 *x**8 +
2611655889692786813829120*x**7 + 10122095419974470210682880*x**6 +
30198816984091441338777600 *x**5 + 67426052557934862488567808*x**4 +
107969196810523545855590400*x**3 + 115794329499468438700032000 *x**2 +
73425049924762651852800000*x + 20408661249006627717120000 = 0
and -20<=x<=-10)$
rlcad wilk;

% Convexity of unit square
as5v := all({x1,y1,x2,y2},(0<x1<1 and 0<y1<1 and 0<x2<1 and 0<y2<1) impl
all(l, (0<l and l<1) impl (0<x1+l*(-x1+x2)<1 and 0<y1+l*(-y1+y2)<1)))$
rlcad as5v;

% Consistency
con := ex({z,x,y},x**2+y**2+z**2<1 and x**2+(y+z-2)**2<1)$
rlcad con;

% Condition on quartic polynomial being positive semidefinite.
quartic := all(x,x**4+p*x**2+q*x+r>=0)$
quarticneg := not quartic$
on rlcadfulldimonly;
rlcad quarticneg;
off rlcadfulldimonly;

% Solotareff's problem (cubic) [Ho92] (in [CJ98], p. 211)
solo2 := ex({x,y},1<=4*a<=7 and -3<=4*b<=3 and -1<=x<=0 and 0<=y<=1 and
   3*x**2-2*x-a=0 and x**3-x**2-a*x=2*b-a+2 and 3*y**2-2*y-a=0 and
      y**3-y**2-a*y=a-2)$
rlcad solo2;

%%% Test rlgcad

% x-axis ellipse problem
ell := all({x,y},b**2*(x-c)**2+a**2*y**2-a**2*b**2=0 impl x**2+y**2-1 <=0);
ellgqf := rlgcad ell;

% x-axis ellipse problem variant (refined formula) [Ho92]
cc := x**2+y**2-1$
ee := b**2*(x-c)**2+a**2*y**2-a**2*b**2$
ellv := all({x,y},0<a<=1 and 0<b<=1 and 0<=c<=1-a and
   ((c-a<x<c+a and ee=0) impl cc <= 0))$
ellvgqf := rlgcad ellv;

% Steiner--Lehmus Theorem
h1 := u2>=0 and x1>=0$
h2 := r^2=1+x1^2=u1^2+(u2-x1)^2$
h3 := x2<=0 and r^2=(x2-x1)^2$
h4 := u1*x2+u2*x3-x2*x3=0$
h5 := x4<=1 and (x4-1)^2=(u1-1)^2+u2^2$
h6 := (x4-x5)^2+x6^2=(u1-x5)^2+(u2-x6)^2 and u1*x6-u2*x5-u2+x6=0$
h7 := (-1-u1)^2+u2^2<2^2$
h := h1 and h2 and h3 and h4 and h5 and h6 and h7$
g := (u1-x3)^2+u2^2<(x5-1)^2+x6^2$
sl9 := all({x6,x5,x4,x3,x2,x1,r},h impl g)$
sol := rlgqe sl9$

%%% Test rlgsn

% Result of the rectangle problem from testing rlqe above.
rlgsn rp2sol;

% There is a list of formulas containing 125 lines starting here.
% Forward-search for $ to get to the end of this list.
testseries := {q >= 0 and q - 40 <= 0 and n >= 0 and n - td = 0 and i2 =
 0 and (400*q + 9*td - 20050 <= 0 and q = 0 or 400*q + 9*td - 20050 > 0
and 9*td - 20050 = 0) and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 =
 0 or 2*p1 - 7 >= 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*
z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 =
 0 or td = 0 and z = 0) and (80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 +
 250*p1 + 2*q - 1377 <= 0 and 1480*i2 - 50*n + 4625*p1 + 37*q + 5*td +
750*z - 4647 = 0 or 80*i2 + 250*p1 + 2*q - 1377 > 0 and 80*i2 + 250*p1 +
 2*q - 1457 <= 0 and 76880*i2 - 2000*n + 240250*p1 + 1922*q + 200*td +
50000*z - 669797 = 0 or 80*i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*
p1 + 2*q - 1697 < 0 and 10750000*i2 + 500000*n + 33593750*p1 + 268750*q
- 50000*td - 10000000*z - 402109359 = 0) or q >= 0 and q - 40 <= 0 and n
 >= 0 and n - td = 0 and i2 = 0 and 2*p1 - 7 >= 0 and 80*i2 + 250*p1 + 2
*q - 1377 = 0 and 20*n - 2*td - 300*z - 8331 = 0 and (400*q + 9*td -
20050 <= 0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0)
and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td -
700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z =
0) or q >= 0 and q - 40 <= 0 and n >= 0 and n - td = 0 and i2 = 0 and 2*
p1 - 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1457 = 0 and 100*n - 10*td - 2500
*z - 36519 = 0 and (400*q + 9*td - 20050 <= 0 and q = 0 or 400*q + 9*td
- 20050 > 0 and 9*td - 20050 = 0) and (td - 400 >= 0 and td - 700 < 0
and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td -
 300*z + 1015 = 0 or td = 0 and z = 0) or q >= 0 and q - 40 <= 0 and 9*n
 - 380*q >= 0 and n - td = 0 and i2 = 0 and 400*q + 9*td - 20050 <= 0
and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0)
and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td -
700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z =
0) and (80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 + 250*p1 + 2*q - 1377
<= 0 and 1480*i2 - 50*n + 4625*p1 + 162*q + 5*td + 750*z - 4647 = 0 or
80*i2 + 250*p1 + 2*q - 1377 > 0 and 80*i2 + 250*p1 + 2*q - 1457 <= 0 and
 76880*i2 - 2000*n + 240250*p1 + 6922*q + 200*td + 50000*z - 669797 = 0
or 80*i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*q - 1697 < 0
and 10750000*i2 + 500000*n + 33593750*p1 - 981250*q - 50000*td -
10000000*z - 402109359 = 0) or q >= 0 and q - 40 <= 0 and 9*n - 380*q >=
 0 and n - td = 0 and i2 = 0 and 400*q + 9*td - 20050 <= 0 and 2*p1 - 7
>= 0 and 80*i2 + 250*p1 + 2*q - 1377 = 0 and 20*n - 50*q - 2*td - 300*z
- 8331 = 0 and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 =
 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td =
 0 and z = 0) or q >= 0 and q - 40 <= 0 and 9*n - 380*q >= 0 and n - td
= 0 and i2 = 0 and 400*q + 9*td - 20050 <= 0 and 2*p1 - 7 >= 0 and 80*i2
 + 250*p1 + 2*q - 1457 = 0 and 100*n - 250*q - 10*td - 2500*z - 36519 =
0 and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td
- 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z
= 0) or q >= 0 and q - 40 <= 0 and 9*td - 20050 <= 0 and td - 450 >= 0
and 180*n + 171*td - 380950 >= 0 and n - td = 0 and i2 = 0 and 400*q + 9
*td - 20050 >= 0 and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or
 2*p1 - 7 >= 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z -
5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0
or td = 0 and z = 0) and (80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 +
250*p1 + 2*q - 1377 <= 0 and 23680*i2 - 800*n + 74000*p1 + 592*q + 35*td
 + 12000*z + 25898 = 0 or 80*i2 + 250*p1 + 2*q - 1377 > 0 and 80*i2 +
250*p1 + 2*q - 1457 <= 0 and 153760*i2 - 4000*n + 480500*p1 + 3844*q +
175*td + 100000*z - 838344 = 0 or 80*i2 + 250*p1 + 2*q - 1457 > 0 and 80
*i2 + 250*p1 + 2*q - 1697 < 0 and 10750000*i2 + 500000*n + 33593750*p1 +
 268750*q - 21875*td - 10000000*z - 464765609 = 0) or q >= 0 and q - 40
<= 0 and 9*td - 20050 <= 0 and td - 450 >= 0 and 180*n + 171*td - 380950
 >= 0 and n - td = 0 and i2 = 0 and 400*q + 9*td - 20050 >= 0 and 2*p1 -
 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1377 = 0 and 160*n - 7*td - 2400*z -
86698 = 0 and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 =
0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td =
0 and z = 0) or q >= 0 and q - 40 <= 0 and 9*td - 20050 <= 0 and td -
450 >= 0 and 180*n + 171*td - 380950 >= 0 and n - td = 0 and i2 = 0 and
400*q + 9*td - 20050 >= 0 and 2*p1 - 7 >= 0 and 80*i2 + 250*p1 + 2*q -
1457 = 0 and 800*n - 35*td - 20000*z - 392402 = 0 and (td - 400 >= 0 and
 td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990
< 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) or q >= 0 and q -
40 <= 0 and n >= 0 and n - td = 0 and i2 = 0 and (400*q + 9*td - 20050
<= 0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0) and (2*
p1 - 7 < 0 and 20*n - 2*td - 300*z - 2411 = 0 or 2*p1 - 7 >= 0 and 1480*
i2 - 50*n + 4625*p1 + 37*q + 5*td + 750*z - 4647 = 0) and (td - 400 >= 0
 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td -
990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (20*n - 2*
td - 300*z - 5963 > 0 and 20*n - 2*td - 300*z - 8331 <= 0 or 20*n - 2*td
 - 300*z - 8331 > 0 and 20*n - 2*td - 300*z - 8923 <= 0 and 4420*n - 442
*td + 81700*z - 3170191 = 0 or 20*n - 2*td - 300*z - 8923 > 0 and 20*n -
 2*td - 300*z - 10699 < 0 and 31937500*n - 3193750*td - 571562500*z - 13629165033
 = 0) or q >= 0 and q - 40 <= 0 and 9*n - 380*q >= 0 and n - td = 0 and
i2 = 0 and 400*q + 9*td - 20050 <= 0 and (2*p1 - 7 < 0 and 20*n - 50*q -
 2*td - 300*z - 2411 = 0 or 2*p1 - 7 >= 0 and 1480*i2 - 50*n + 4625*p1 +
 162*q + 5*td + 750*z - 4647 = 0) and (td - 400 >= 0 and td - 700 < 0
and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td -
 300*z + 1015 = 0 or td = 0 and z = 0) and (20*n - 50*q - 2*td - 300*z -
 5963 > 0 and 20*n - 50*q - 2*td - 300*z - 8331 <= 0 or 20*n - 50*q - 2*
td - 300*z - 8331 > 0 and 20*n - 50*q - 2*td - 300*z - 8923 <= 0 and
4420*n - 11050*q - 442*td + 81700*z - 3170191 = 0 or 20*n - 50*q - 2*td
- 300*z - 8923 > 0 and 20*n - 50*q - 2*td - 300*z - 10699 < 0 and
31937500*n - 79843750*q - 3193750*td - 571562500*z - 13629165033 = 0) or
 q >= 0 and q - 40 <= 0 and 9*td - 20050 <= 0 and td - 450 >= 0 and 180*
n + 171*td - 380950 >= 0 and n - td = 0 and i2 = 0 and 400*q + 9*td -
20050 >= 0 and (2*p1 - 7 < 0 and 160*n - 7*td - 2400*z - 39338 = 0 or 2*
p1 - 7 >= 0 and 23680*i2 - 800*n + 74000*p1 + 592*q + 35*td + 12000*z +
25898 = 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 =
 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td =
 0 and z = 0) and (160*n - 7*td - 2400*z - 67754 > 0 and 160*n - 7*td -
2400*z - 86698 <= 0 or 160*n - 7*td - 2400*z - 86698 > 0 and 160*n - 7*
td - 2400*z - 91434 <= 0 and 35360*n - 1547*td + 653600*z - 29792578 = 0
 or 160*n - 7*td - 2400*z - 91434 > 0 and 160*n - 7*td - 2400*z - 105642
 < 0 and 255500000*n - 11178125*td - 4572500000*z - 141050664014 = 0) or
 q >= 0 and q - 40 <= 0 and 1480*i2 - 50*n + 4625*p1 + 37*q + 5*td + 750
*z - 4647 <= 0 and 1480*i2 - 50*n + 4625*p1 + 37*q + 5*td + 750*z + 353
>= 0 and 112480*i2 - 3575*n + 351500*p1 + 2812*q + 380*td + 57000*z -
353172 >= 0 and n - td = 0 and i2 = 0 and (400*q + 9*td - 20050 <= 0 and
 1480*i2 - 50*n + 4625*p1 + 162*q + 5*td + 750*z - 4647 = 0 or 400*q + 9
*td - 20050 > 0 and 23680*i2 - 800*n + 74000*p1 + 592*q + 35*td + 12000*
z + 25898 = 0) and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2
*p1 - 7 >= 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z -
5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0
or td = 0 and z = 0) and (80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 +
250*p1 + 2*q - 1377 <= 0 or 80*i2 + 250*p1 + 2*q - 1377 > 0 and 80*i2 +
250*p1 + 2*q - 1457 <= 0 and 17680*i2 + 55250*p1 + 442*q + 20000*z -
483917 = 0 or 80*i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*q -
 1697 < 0 and 25550000*i2 + 79843750*p1 + 638750*q - 2500000*z -
448579359 = 0) or q >= 0 and q - 40 <= 0 and 20*n - 2*td - 300*z - 8331
>= 0 and 20*n - 2*td - 300*z - 10331 <= 0 and 715*n - 76*td - 11400*z -
316578 <= 0 and n - td = 0 and i2 = 0 and 2*p1 - 7 >= 0 and 80*i2 + 250*
p1 + 2*q - 1377 = 0 and (400*q + 9*td - 20050 <= 0 and 20*n - 50*q - 2*
td - 300*z - 8331 = 0 or 400*q + 9*td - 20050 > 0 and 160*n - 7*td -
2400*z - 86698 = 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z
 - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 =
0 or td = 0 and z = 0) or q >= 0 and q - 40 <= 0 and 20*n - 2*td - 300*z
 - 8923 >= 0 and 20*n - 2*td - 300*z - 10923 <= 0 and 715*n - 76*td -
11400*z - 339074 <= 0 and n - td = 0 and i2 = 0 and 2*p1 - 7 >= 0 and 80
*i2 + 250*p1 + 2*q - 1457 = 0 and 125*z - 1012 = 0 and (400*q + 9*td -
20050 <= 0 and 20*n - 50*q - 2*td - 300*z - 8923 = 0 or 400*q + 9*td -
20050 > 0 and 160*n - 7*td - 2400*z - 91434 = 0) and (td - 400 >= 0 and
td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 <
 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) or q >= 0 and q - 40
 <= 0 and n >= 0 and n - td = 0 and i2 = 0 and (400*q + 9*td - 20050 <=
0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0) and (2*p1
- 7 < 0 and 20*n - 2*td - 500*z + 1153 = 0 or 2*p1 - 7 >= 0 and 76880*i2
 - 2000*n + 240250*p1 + 1922*q + 200*td + 50000*z - 669797 = 0) and (td
- 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0
 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (
100*n - 10*td - 2500*z - 17299 > 0 and 20*n - 2*td - 500*z - 6535 <= 0
and 4420*n - 442*td + 81700*z - 3170191 = 0 or 20*n - 2*td - 500*z -
6535 > 0 and 100*n - 10*td - 2500*z - 36519 <= 0 or 100*n - 10*td - 2500
*z - 36519 > 0 and 100*n - 10*td - 2500*z - 48051 < 0 and 187312500*n -
18731250*td - 4082187500*z - 74105780531 = 0) or q >= 0 and q - 40 <= 0
and 9*n - 380*q >= 0 and n - td = 0 and i2 = 0 and 400*q + 9*td - 20050
<= 0 and (2*p1 - 7 < 0 and 20*n - 50*q - 2*td - 500*z + 1153 = 0 or 2*p1
 - 7 >= 0 and 76880*i2 - 2000*n + 240250*p1 + 6922*q + 200*td + 50000*z
- 669797 = 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z -
5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0
or td = 0 and z = 0) and (100*n - 250*q - 10*td - 2500*z - 17299 > 0 and
 20*n - 50*q - 2*td - 500*z - 6535 <= 0 and 4420*n - 11050*q - 442*td +
81700*z - 3170191 = 0 or 20*n - 50*q - 2*td - 500*z - 6535 > 0 and 100*n
 - 250*q - 10*td - 2500*z - 36519 <= 0 or 100*n - 250*q - 10*td - 2500*z
 - 36519 > 0 and 100*n - 250*q - 10*td - 2500*z - 48051 < 0 and
187312500*n - 468281250*q - 18731250*td - 4082187500*z - 74105780531 = 0
) or q >= 0 and q - 40 <= 0 and 9*td - 20050 <= 0 and td - 450 >= 0 and
180*n + 171*td - 380950 >= 0 and n - td = 0 and i2 = 0 and 400*q + 9*td
- 20050 >= 0 and (2*p1 - 7 < 0 and 160*n - 7*td - 4000*z - 10826 = 0 or
2*p1 - 7 >= 0 and 153760*i2 - 4000*n + 480500*p1 + 3844*q + 175*td +
100000*z - 838344 = 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td +
400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z +
1015 = 0 or td = 0 and z = 0) and (800*n - 35*td - 20000*z - 238642 > 0
and 160*n - 7*td - 4000*z - 72330 <= 0 and 35360*n - 1547*td + 653600*z
- 29792578 = 0 or 160*n - 7*td - 4000*z - 72330 > 0 and 800*n - 35*td -
20000*z - 392402 <= 0 or 800*n - 35*td - 20000*z - 392402 > 0 and 800*n
- 35*td - 20000*z - 484658 < 0 and 1498500000*n - 65559375*td - 32657500000
*z - 780627025498 = 0) or q >= 0 and q - 40 <= 0 and 76880*i2 - 2000*n +
 240250*p1 + 1922*q + 200*td + 50000*z - 669797 <= 0 and 76880*i2 - 2000
*n + 240250*p1 + 1922*q + 200*td + 50000*z - 469797 >= 0 and 1460720*i2
- 35750*n + 4564750*p1 + 36518*q + 3800*td + 950000*z - 12726143 >= 0
and n - td = 0 and i2 = 0 and (400*q + 9*td - 20050 <= 0 and 76880*i2 -
2000*n + 240250*p1 + 6922*q + 200*td + 50000*z - 669797 = 0 or 400*q + 9
*td - 20050 > 0 and 153760*i2 - 4000*n + 480500*p1 + 3844*q + 175*td +
100000*z - 838344 = 0) and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577
= 0 or 2*p1 - 7 >= 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400
*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015
= 0 or td = 0 and z = 0) and (80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2
+ 250*p1 + 2*q - 1377 <= 0 and 17680*i2 + 55250*p1 + 442*q + 20000*z -
483917 = 0 or 80*i2 + 250*p1 + 2*q - 1377 > 0 and 80*i2 + 250*p1 + 2*q -
 1457 <= 0 or 80*i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*q -
 1697 < 0 and 29970000*i2 + 93656250*p1 + 749250*q + 2500000*z -
569558609 = 0) or q >= 0 and q - 40 <= 0 and 20*n - 2*td - 500*z - 6535
>= 0 and 20*n - 2*td - 500*z - 8535 <= 0 and 715*n - 76*td - 19000*z -
248330 <= 0 and n - td = 0 and i2 = 0 and 2*p1 - 7 >= 0 and 80*i2 + 250*
p1 + 2*q - 1377 = 0 and 50*z - 449 = 0 and (400*q + 9*td - 20050 <= 0
and 20*n - 50*q - 2*td - 500*z - 6535 = 0 or 400*q + 9*td - 20050 > 0
and 160*n - 7*td - 4000*z - 72330 = 0) and (td - 400 >= 0 and td - 700 <
 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*
td - 300*z + 1015 = 0 or td = 0 and z = 0) or q >= 0 and q - 40 <= 0 and
 4420*n - 442*td + 81700*z - 3170191 >= 0 and 4420*n - 442*td + 81700*z
- 3612191 <= 0 and 158015*n - 16796*td + 3104600*z - 120467258 <= 0 and
n - td = 0 and i2 = 0 and (400*q + 9*td - 20050 <= 0 and 4420*n - 11050*
q - 442*td + 81700*z - 3170191 = 0 or 400*q + 9*td - 20050 > 0 and 35360
*n - 1547*td + 653600*z - 29792578 = 0) and (2*p1 - 7 < 0 and 50*z - 891
 = 0 or 2*p1 - 7 >= 0 and 17680*i2 + 55250*p1 + 442*q + 20000*z - 483917
 = 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or
 td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0
and z = 0) and (250*z - 3129 < 0 and 50*z - 449 >= 0 or 50*z - 449 < 0
and 125*z - 1012 >= 0 or 125*z - 1012 < 0 and 250*z - 1361 > 0 and
108437500*z - 865858649 = 0) or q >= 0 and q - 40 <= 0 and 100*n - 10*td
 - 2500*z - 36519 >= 0 and 100*n - 10*td - 2500*z - 46519 <= 0 and 3575*
n - 380*td - 95000*z - 1387722 <= 0 and n - td = 0 and i2 = 0 and 2*p1 -
 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1457 = 0 and (400*q + 9*td - 20050 <=
 0 and 100*n - 250*q - 10*td - 2500*z - 36519 = 0 or 400*q + 9*td -
20050 > 0 and 800*n - 35*td - 20000*z - 392402 = 0) and (td - 400 >= 0
and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td -
990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) or q >= 0 and q
 - 40 <= 0 and n >= 0 and n - td = 0 and i2 = 0 and (400*q + 9*td -
20050 <= 0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0)
and (2*p1 - 7 < 0 and 62500*n - 6250*td - 1250000*z - 40571873 = 0 or 2*
p1 - 7 >= 0 and 10750000*i2 + 500000*n + 33593750*p1 + 268750*q - 50000*
td - 10000000*z - 402109359 = 0) and (td - 400 >= 0 and td - 700 < 0 and
 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td -
300*z + 1015 = 0 or td = 0 and z = 0) and (62500*n - 6250*td - 1250000*z
 - 32509373 < 0 and 62500*n - 6250*td - 1250000*z - 27134373 >= 0 and
31937500*n - 3193750*td - 571562500*z - 13629165033 = 0 or 62500*n -
6250*td - 1250000*z - 27134373 < 0 and 62500*n - 6250*td - 1250000*z -
25790623 >= 0 and 187312500*n - 18731250*td - 4082187500*z - 74105780531
 = 0 or 62500*n - 6250*td - 1250000*z - 25790623 < 0 and 62500*n - 6250*
td - 1250000*z - 21759373 > 0) or q >= 0 and q - 40 <= 0 and 9*n - 380*q
 >= 0 and n - td = 0 and i2 = 0 and 400*q + 9*td - 20050 <= 0 and (2*p1
- 7 < 0 and 62500*n - 156250*q - 6250*td - 1250000*z - 40571873 = 0 or 2
*p1 - 7 >= 0 and 10750000*i2 + 500000*n + 33593750*p1 - 981250*q - 50000
*td - 10000000*z - 402109359 = 0) and (td - 400 >= 0 and td - 700 < 0
and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td -
 300*z + 1015 = 0 or td = 0 and z = 0) and (62500*n - 156250*q - 6250*td
 - 1250000*z - 32509373 < 0 and 62500*n - 156250*q - 6250*td - 1250000*z
 - 27134373 >= 0 and 31937500*n - 79843750*q - 3193750*td - 571562500*z
- 13629165033 = 0 or 62500*n - 156250*q - 6250*td - 1250000*z - 27134373
 < 0 and 62500*n - 156250*q - 6250*td - 1250000*z - 25790623 >= 0 and
187312500*n - 468281250*q - 18731250*td - 4082187500*z - 74105780531 = 0
 or 62500*n - 156250*q - 6250*td - 1250000*z - 25790623 < 0 and 62500*n
- 156250*q - 6250*td - 1250000*z - 21759373 > 0) or q >= 0 and q - 40 <=
 0 and 9*td - 20050 <= 0 and td - 450 >= 0 and 180*n + 171*td - 380950
>= 0 and n - td = 0 and i2 = 0 and 400*q + 9*td - 20050 >= 0 and (2*p1 -
 7 < 0 and 500000*n - 21875*td - 10000000*z - 387231234 = 0 or 2*p1 - 7
>= 0 and 10750000*i2 + 500000*n + 33593750*p1 + 268750*q - 21875*td -
10000000*z - 464765609 = 0) and (td - 400 >= 0 and td - 700 < 0 and 3*td
 + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z +
 1015 = 0 or td = 0 and z = 0) and (500000*n - 21875*td - 10000000*z -
322731234 < 0 and 500000*n - 21875*td - 10000000*z - 279731234 >= 0 and
255500000*n - 11178125*td - 4572500000*z - 141050664014 = 0 or 500000*n
- 21875*td - 10000000*z - 279731234 < 0 and 500000*n - 21875*td -
10000000*z - 268981234 >= 0 and 1498500000*n - 65559375*td - 32657500000
*z - 780627025498 = 0 or 500000*n - 21875*td - 10000000*z - 268981234 <
0 and 500000*n - 21875*td - 10000000*z - 236731234 > 0) or q >= 0 and q
- 40 <= 0 and 10750000*i2 + 500000*n + 33593750*p1 + 268750*q - 50000*td
 - 10000000*z - 402109359 >= 0 and 10750000*i2 + 500000*n + 33593750*p1
+ 268750*q - 50000*td - 10000000*z - 452109359 <= 0 and 204250000*i2 +
8937500*n + 638281250*p1 + 5106250*q - 950000*td - 190000000*z - 7640077821
 <= 0 and n - td = 0 and i2 = 0 and (400*q + 9*td - 20050 <= 0 and
10750000*i2 + 500000*n + 33593750*p1 - 981250*q - 50000*td - 10000000*z
- 402109359 = 0 or 400*q + 9*td - 20050 > 0 and 10750000*i2 + 500000*n +
 33593750*p1 + 268750*q - 21875*td - 10000000*z - 464765609 = 0) and (2*
p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) and (td
- 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0
 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (
80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 + 250*p1 + 2*q - 1377 <= 0 and
 25550000*i2 + 79843750*p1 + 638750*q - 2500000*z - 448579359 = 0 or 80*
i2 + 250*p1 + 2*q - 1377 > 0 and 80*i2 + 250*p1 + 2*q - 1457 <= 0 and
29970000*i2 + 93656250*p1 + 749250*q + 2500000*z - 569558609 = 0 or 80*
i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*q - 1697 < 0) or q
>= 0 and q - 40 <= 0 and 31937500*n - 3193750*td - 571562500*z - 13629165033
 >= 0 and 31937500*n - 3193750*td - 571562500*z - 16822915033 <= 0 and 1141765625
*n - 121362500*td - 21719375000*z - 517908271254 <= 0 and n - td = 0 and
 i2 = 0 and (400*q + 9*td - 20050 <= 0 and 31937500*n - 79843750*q -
3193750*td - 571562500*z - 13629165033 = 0 or 400*q + 9*td - 20050 > 0
and 255500000*n - 11178125*td - 4572500000*z - 141050664014 = 0) and (2*
p1 - 7 < 0 and 156250*z + 16518749 = 0 or 2*p1 - 7 >= 0 and 25550000*i2
+ 79843750*p1 + 638750*q - 2500000*z - 448579359 = 0) and (td - 400 >= 0
 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td -
990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (156250*z +
 6937499 > 0 and 156250*z + 549999 <= 0 or 156250*z + 549999 > 0 and
78125*z - 523438 <= 0 and 108437500*z - 865858649 = 0 or 78125*z -
523438 > 0 and 156250*z - 5837501 < 0) or q >= 0 and q - 40 <= 0 and
187312500*n - 18731250*td - 4082187500*z - 74105780531 >= 0 and
187312500*n - 18731250*td - 4082187500*z - 92837030531 <= 0 and 6696421875
*n - 711787500*td - 155123125000*z - 2816019660178 <= 0 and n - td = 0
and i2 = 0 and (400*q + 9*td - 20050 <= 0 and 187312500*n - 468281250*q
- 18731250*td - 4082187500*z - 74105780531 = 0 or 400*q + 9*td - 20050 >
 0 and 1498500000*n - 65559375*td - 32657500000*z - 780627025498 = 0)
and (2*p1 - 7 < 0 and 156250*z - 22087499 = 0 or 2*p1 - 7 >= 0 and
29970000*i2 + 93656250*p1 + 749250*q + 2500000*z - 569558609 = 0) and (
td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700
>= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0)
and (156250*z - 10848749 < 0 and 156250*z - 3356249 >= 0 and 108437500*z
 - 865858649 = 0 or 156250*z - 3356249 < 0 and 78125*z - 741562 >= 0 or
78125*z - 741562 < 0 and 156250*z + 4136251 > 0),
2*p1 - 7 >= 0 and 400*q + 9*td - 20050 <= 0 and i2 = 0 and n - td = 0
and q >= 0 and q - 40 <= 0 and (td - 400 >= 0 and td - 700 < 0 and 3*td
+ 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z +
1015 = 0 or td = 0 and z = 0) or 2*p1 - 7 >= 0 and 400*q + 9*td - 20050
>= 0 and i2 = 0 and n - td = 0 and td - 450 >= 0 and 9*td - 20050 <= 0
and q - 40 <= 0 and q >= 0 and (td - 400 >= 0 and td - 700 < 0 and 3*td
+ 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z +
1015 = 0 or td = 0 and z = 0) or 2*p1 - 7 >= 0 and i2 = 0 and n - td = 0
 and q - 40 <= 0 and q >= 0 and (td - 400 >= 0 and td - 700 < 0 and 3*td
 + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z +
 1015 = 0 or td = 0 and z = 0) and (400*q + 9*td - 20050 <= 0 and q - 40
 = 0 or 400*q + 9*td - 20050 > 0 and td - 450 = 0) or 2*p1 - 7 < 0 and
400*q + 9*td - 20050 <= 0 and i2 = 0 and n - td = 0 and q >= 0 and q -
40 <= 0 and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0
or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0
and z = 0) or 2*p1 - 7 < 0 and 400*q + 9*td - 20050 >= 0 and i2 = 0 and
n - td = 0 and td - 450 >= 0 and 9*td - 20050 <= 0 and q - 40 <= 0 and q
 >= 0 and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or
 td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0
and z = 0) or 2*p1 - 7 < 0 and i2 = 0 and n - td = 0 and q - 40 <= 0 and
 q >= 0 and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0
or td - 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0
and z = 0) and (400*q + 9*td - 20050 <= 0 and q - 40 = 0 or 400*q + 9*td
 - 20050 > 0 and td - 450 = 0),
80*i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*q - 1697 < 0 and
i2 = 0 and n - td = 0 and n >= 0 and q - 40 <= 0 and q >= 0 and (td -
400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0
and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (2
*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) and (
400*q + 9*td - 20050 <= 0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td
 - 20050 = 0) or 80*i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*
q - 1697 < 0 and i2 = 0 and n - td = 0 and 9*n - 380*q >= 0 and q - 40
<= 0 and q >= 0 and 400*q + 9*td - 20050 <= 0 and (td - 400 >= 0 and td
- 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0
and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (2*p1 - 7 < 0 and
80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) or 80*i2 + 250*p1 + 2*q
 - 1457 > 0 and 80*i2 + 250*p1 + 2*q - 1697 < 0 and i2 = 0 and n - td =
0 and 180*n + 171*td - 380950 >= 0 and td - 450 >= 0 and 9*td - 20050 <=
 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 >= 0 and (td -
400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0
and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (2
*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) or 2*p1
 - 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1457 = 0 and i2 = 0 and n - td = 0
and n >= 0 and q - 40 <= 0 and q >= 0 and (td - 400 >= 0 and td - 700 <
0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td
 - 300*z + 1015 = 0 or td = 0 and z = 0) and (400*q + 9*td - 20050 <= 0
and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0) or 2*p1 - 7
>= 0 and 80*i2 + 250*p1 + 2*q - 1457 = 0 and i2 = 0 and n - td = 0 and 9
*n - 380*q >= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 <= 0
 and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td -
 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z =
 0) or 2*p1 - 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1457 = 0 and i2 = 0 and
n - td = 0 and 180*n + 171*td - 380950 >= 0 and td - 450 >= 0 and 9*td -
 20050 <= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 >= 0 and
 (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700
 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0)
or 80*i2 + 250*p1 + 2*q - 1377 > 0 and 80*i2 + 250*p1 + 2*q - 1457 <= 0
and i2 = 0 and n - td = 0 and n >= 0 and q - 40 <= 0 and q >= 0 and (td
- 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0
 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (
2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) and (
400*q + 9*td - 20050 <= 0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td
 - 20050 = 0) or 80*i2 + 250*p1 + 2*q - 1377 > 0 and 80*i2 + 250*p1 + 2*
q - 1457 <= 0 and i2 = 0 and n - td = 0 and 9*n - 380*q >= 0 and q - 40
<= 0 and q >= 0 and 400*q + 9*td - 20050 <= 0 and (td - 400 >= 0 and td
- 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0
and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (2*p1 - 7 < 0 and
80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) or 80*i2 + 250*p1 + 2*q
 - 1377 > 0 and 80*i2 + 250*p1 + 2*q - 1457 <= 0 and i2 = 0 and n - td =
 0 and 180*n + 171*td - 380950 >= 0 and td - 450 >= 0 and 9*td - 20050
<= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 >= 0 and (td -
400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0
and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (2
*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) or 2*p1
 - 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1377 = 0 and i2 = 0 and n - td = 0
and n >= 0 and q - 40 <= 0 and q >= 0 and (td - 400 >= 0 and td - 700 <
0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0 and 2*td
 - 300*z + 1015 = 0 or td = 0 and z = 0) and (400*q + 9*td - 20050 <= 0
and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0) or 2*p1 - 7
>= 0 and 80*i2 + 250*p1 + 2*q - 1377 = 0 and i2 = 0 and n - td = 0 and 9
*n - 380*q >= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 <= 0
 and (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td -
 700 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z =
 0) or 2*p1 - 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1377 = 0 and i2 = 0 and
n - td = 0 and 180*n + 171*td - 380950 >= 0 and td - 450 >= 0 and 9*td -
 20050 <= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 >= 0 and
 (td - 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700
 >= 0 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0)
or 80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 + 250*p1 + 2*q - 1377 <= 0
and i2 = 0 and n - td = 0 and n >= 0 and q - 40 <= 0 and q >= 0 and (td
- 400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0
 and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (
2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) and (
400*q + 9*td - 20050 <= 0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td
 - 20050 = 0) or 80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 + 250*p1 + 2*
q - 1377 <= 0 and i2 = 0 and n - td = 0 and 9*n - 380*q >= 0 and q - 40
<= 0 and q >= 0 and 400*q + 9*td - 20050 <= 0 and (td - 400 >= 0 and td
- 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0 and td - 990 < 0
and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (2*p1 - 7 < 0 and
80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) or 80*i2 + 250*p1 + 2*q
 - 1057 > 0 and 80*i2 + 250*p1 + 2*q - 1377 <= 0 and i2 = 0 and n - td =
 0 and 180*n + 171*td - 380950 >= 0 and td - 450 >= 0 and 9*td - 20050
<= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 >= 0 and (td -
400 >= 0 and td - 700 < 0 and 3*td + 400*z - 5320 = 0 or td - 700 >= 0
and td - 990 < 0 and 2*td - 300*z + 1015 = 0 or td = 0 and z = 0) and (2
*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0),
80*i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*q - 1697 < 0 and
i2 = 0 and n >= 0 and q - 40 <= 0 and q >= 0 and (2*p1 - 7 < 0 and 80*i2
 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) and (400*q + 9*td - 20050 <=
 0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0) or 80*i2
+ 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*q - 1697 < 0 and i2 = 0
 and 9*n - 380*q >= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td -
20050 <= 0 and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1
- 7 >= 0) or 80*i2 + 250*p1 + 2*q - 1457 > 0 and 80*i2 + 250*p1 + 2*q -
1697 < 0 and i2 = 0 and 180*n + 171*td - 380950 >= 0 and td - 450 >= 0
and 9*td - 20050 <= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td -
20050 >= 0 and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1
- 7 >= 0) or 2*p1 - 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1457 = 0 and i2 =
0 and n >= 0 and q - 40 <= 0 and q >= 0 and (400*q + 9*td - 20050 <= 0
and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0) or 2*p1 - 7
>= 0 and 80*i2 + 250*p1 + 2*q - 1457 = 0 and i2 = 0 and 9*n - 380*q >= 0
 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 <= 0 or 2*p1 - 7 >=
 0 and 80*i2 + 250*p1 + 2*q - 1457 = 0 and i2 = 0 and 180*n + 171*td -
380950 >= 0 and td - 450 >= 0 and 9*td - 20050 <= 0 and q - 40 <= 0 and
q >= 0 and 400*q + 9*td - 20050 >= 0 or 80*i2 + 250*p1 + 2*q - 1377 > 0
and 80*i2 + 250*p1 + 2*q - 1457 <= 0 and i2 = 0 and n >= 0 and q - 40 <=
 0 and q >= 0 and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*
p1 - 7 >= 0) and (400*q + 9*td - 20050 <= 0 and q = 0 or 400*q + 9*td -
20050 > 0 and 9*td - 20050 = 0) or 80*i2 + 250*p1 + 2*q - 1377 > 0 and
80*i2 + 250*p1 + 2*q - 1457 <= 0 and i2 = 0 and 9*n - 380*q >= 0 and q -
 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 <= 0 and (2*p1 - 7 < 0 and
80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) or 80*i2 + 250*p1 + 2*q
 - 1377 > 0 and 80*i2 + 250*p1 + 2*q - 1457 <= 0 and i2 = 0 and 180*n +
171*td - 380950 >= 0 and td - 450 >= 0 and 9*td - 20050 <= 0 and q - 40
<= 0 and q >= 0 and 400*q + 9*td - 20050 >= 0 and (2*p1 - 7 < 0 and 80*
i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) or 2*p1 - 7 >= 0 and 80*i2
 + 250*p1 + 2*q - 1377 = 0 and i2 = 0 and n >= 0 and q - 40 <= 0 and q
>= 0 and (400*q + 9*td - 20050 <= 0 and q = 0 or 400*q + 9*td - 20050 >
0 and 9*td - 20050 = 0) or 2*p1 - 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1377
 = 0 and i2 = 0 and 9*n - 380*q >= 0 and q - 40 <= 0 and q >= 0 and 400*
q + 9*td - 20050 <= 0 or 2*p1 - 7 >= 0 and 80*i2 + 250*p1 + 2*q - 1377 =
 0 and i2 = 0 and 180*n + 171*td - 380950 >= 0 and td - 450 >= 0 and 9*
td - 20050 <= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td - 20050 >= 0
 or 80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 + 250*p1 + 2*q - 1377 <= 0
 and i2 = 0 and n >= 0 and q - 40 <= 0 and q >= 0 and (2*p1 - 7 < 0 and
80*i2 + 250*p1 + 2*q - 577 = 0 or 2*p1 - 7 >= 0) and (400*q + 9*td -
20050 <= 0 and q = 0 or 400*q + 9*td - 20050 > 0 and 9*td - 20050 = 0)
or 80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 + 250*p1 + 2*q - 1377 <= 0
and i2 = 0 and 9*n - 380*q >= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9
*td - 20050 <= 0 and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or
 2*p1 - 7 >= 0) or 80*i2 + 250*p1 + 2*q - 1057 > 0 and 80*i2 + 250*p1 +
2*q - 1377 <= 0 and i2 = 0 and 180*n + 171*td - 380950 >= 0 and td - 450
 >= 0 and 9*td - 20050 <= 0 and q - 40 <= 0 and q >= 0 and 400*q + 9*td
- 20050 >= 0 and (2*p1 - 7 < 0 and 80*i2 + 250*p1 + 2*q - 577 = 0 or 2*
p1 - 7 >= 0)}$
for each ex in testseries collect {rlatnum ex,rlatnum rlgsn ex};

%%% Test rltab

% Result of the rectangle problem from testing rlqe above.
rltab rp2sol;

% Polynomial exponential problems

% A.1 Complete Example
a1 := ex({x, y}, e**x-y**2=0 and x-y=0);
rldpep a1;

% A.2 Properties of the Exponential Function
a21 := ex(x, e**x<=0);
rldpep a21;

a22 := all(x, e**x>=1+x);
rldpep a22;

a23 := all(x, (1-x)*e**x<=1 or x>=1);
rldpep a23;

% A.3 Exponential Systems
a32 := ex({x, y, z}, 2x-y+z+e**(2x)=0 and 3y-z=0 and 2x+y+3z+e**x=0);
rldpep a32;

a33 := ex(x, e**(2x)-x*e**x-1=0 and e**(2x)+e**x-2x>0);
rldpep a33;

% A.4 Examples with Hyperbolic Functions
% tanh(x):
a43 := all(x, x>0 impl x*e**(2x)-x>(x-1)*e**(2x)+x-1);
rldpep a43;

% A.5 Examples with the Gauss Curve
a51 := ex({z, x}, 4*x**2*e**z=1+x**2 and z+x**2=0);
rldpep a51;

a52 := ex({z, x}, 10*e**z=-8*x**2+10 and x neq 0 and z+x**2=0);
rldpep a52;

% Additional Examples with the Gauss Curve
add53 := all({z, x}, x**2+z=0 impl e**z>0);
rldpep add53;

% Some simple tropical decision using only Reduce simplex
rlptropsat(x=0 or x+1 = 0);

rltropsat(x=0 or x+1 = 0);

zerop(x**2+x);

pzerop(x**2-2);

w := pzerop(-2x1^6+x1^3*x2-3x1^3+2x1*x2^2);
zeroapprox(-2x1^6+x1^3*x2-3x1^3+2x1*x2^2, w);
zerosolve(-2x1^6+x1^3*x2-3x1^3+2x1*x2^2, w);

% Optimizer and VS with learning

% Test case for an ofsf_xopt bug discovered by Eddy Westbrook.
rlqe ex(y,(y=x or y=-x) and y>=0);

% from Marc van Dongen. Finding the first feasible solution for the
% solution of systems of linear diophantine inequalities.
dong := {
  3*x259+4*x261+3*x262+2*x263+x269+2*x270+3*x271+4*x272+5*x273+x229=2,
  7*x259+11*x261+8*x262+5*x263+3*x269+6*x270+9*x271+12*x272+15*x273+x229=4,
  2*x259+5*x261+4*x262+3*x263+3*x268+4*x269+5*x270+6*x271+7*x272+8*x273=1,
  x262+2*x263+5*x268+4*x269+3*x270+2*x271+x272+2*x229=1,
  x259+x262+2*x263+4*x268+3*x269+2*x270+x271-x273+3*x229=2,
  x259+2*x261+2*x262+2*x263+3*x268+3*x269+3*x270+3*x271+3*x272+3*x273+x229=1,
     x259+x261+x262+x263+x268+x269+x270+x271+x272+x273+x229=1};
sol := rlopt(dong,0);

% Parameter-Free Linear Optimization -
% Examples sc50a and sc50b taken from the ZIB netlib-lp
% ftp://ftp.zib.de/pub/mp-testdata/lp/netlib-lp/

sc50a_c := {
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
2*vCOL00001+(1*vCOL00002)+(1.5*vCOL00003) <= 170,
1*vCOL00001+(2*vCOL00002)+(1.5*vCOL00003) <= 130,
1*vCOL00004+(-1*vCOL00005) = 0,
-1*vCOL00001+(1*vCOL00006) = 0,
-1*vCOL00002+(1*vCOL00007) = 0,
-1*vCOL00003+(1*vCOL00008) = 0,
-1*vCOL00006+(1*vCOL00009) <= 0,
-1*vCOL00007+(1*vCOL00010) <= 0,
-1*vCOL00008+(1*vCOL00011) <= 0,
-1*vCOL00009+(2*vCOL00012)+(1*vCOL00013)+(1.5*vCOL00014) <= 170,
-1*vCOL00010+(1*vCOL00012)+(2*vCOL00013)+(1.5*vCOL00014) <= 130,
1*vCOL00005+(-1*vCOL00011) <= 0,
1.1*vCOL00004+(-1*vCOL00015) = 0,
1*vCOL00005+(1*vCOL00015)+(-1*vCOL00016) = 0,
-1*vCOL00006+(-1*vCOL00012)+(1*vCOL00017) = 0,
-1*vCOL00007+(-1*vCOL00013)+(1*vCOL00018) = 0,
-1*vCOL00008+(-1*vCOL00014)+(1*vCOL00019) = 0,
-1*vCOL00017+(1*vCOL00020) <= 0,
-1*vCOL00018+(1*vCOL00021) <= 0,
-1*vCOL00019+(1*vCOL00022) <= 0,
-1*vCOL00020+(2*vCOL00023)+(1*vCOL00024)+(1.5*vCOL00025) <= 170,
-1*vCOL00021+(1*vCOL00023)+(2*vCOL00024)+(1.5*vCOL00025) <= 130,
1*vCOL00016+(-1*vCOL00022) <= 0,
1.1*vCOL00015+(-1*vCOL00026) = 0,
1*vCOL00016+(1*vCOL00026)+(-1*vCOL00027) = 0,
-1*vCOL00017+(-1*vCOL00023)+(1*vCOL00028) = 0,
-1*vCOL00018+(-1*vCOL00024)+(1*vCOL00029) = 0,
-1*vCOL00019+(-1*vCOL00025)+(1*vCOL00030) = 0,
-1*vCOL00028+(1*vCOL00031) <= 0,
-1*vCOL00029+(1*vCOL00032) <= 0,
-1*vCOL00030+(1*vCOL00033) <= 0,
-1*vCOL00031+(2*vCOL00034)+(1*vCOL00035)+(1.5*vCOL00036) <= 170,
-1*vCOL00032+(1*vCOL00034)+(2*vCOL00035)+(1.5*vCOL00036) <= 130,
1*vCOL00027+(-1*vCOL00033) <= 0,
1.1*vCOL00026+(-1*vCOL00037) = 0,
1*vCOL00027+(1*vCOL00037)+(-1*vCOL00038) = 0,
-1*vCOL00028+(-1*vCOL00034)+(1*vCOL00039) = 0,
-1*vCOL00029+(-1*vCOL00035)+(1*vCOL00040) = 0,
-1*vCOL00030+(-1*vCOL00036)+(1*vCOL00041) = 0,
-1*vCOL00039+(1*vCOL00042) <= 0,
-1*vCOL00040+(1*vCOL00043) <= 0,
-1*vCOL00041+(1*vCOL00044) <= 0,
-1*vCOL00042+(2*vCOL00045)+(1*vCOL00046)+(1.5*vCOL00047) <= 170,
-1*vCOL00043+(1*vCOL00045)+(2*vCOL00046)+(1.5*vCOL00047) <= 130,
1*vCOL00038+(-1*vCOL00044) <= 0,
1.1*vCOL00037+(-1*vCOL00048) = 0,
-0.8*vCOL00045+(0.1*vCOL00046)+(0.15*vCOL00047) <= 0,
0.1*vCOL00045+(-0.8*vCOL00046)+(0.15*vCOL00047) <= 0,
-1*vCOL00047+(1*vCOL00048) <= 0}$

sc50a_t := -1*vCOL00004$

rlopt(sc50a_c,sc50a_t);

sc50b_t := -1*vCOL00004$

sc50b_c := {
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

rlopt(sc50b_c,sc50b_t);

% Adding a constraints choosing the objective function slightly smaller than the
% known minimum, which renders the problem infeasible.

sc50a_infeasible := cons(sc50a_t <= -65, sc50a_c)$

rlvsl sc50a_infeasible;

sc50b_infeasible := cons(sc50b_t <= -71, sc50b_c)$

rlvsl sc50b_infeasible;

% Substitution
sub(first second sol,for each atf in dong mkand atf);
rlsimpl ws;

end;
