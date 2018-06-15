<?php

require_once('../../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Tutorial: Calculus');

$smarty->assign('preamble',  <<< END_OF_PREAMBLE
	<p>Francis Wright, June 2018</p>
	<p>The problems on this page are typical undergraduate calculus problems.</p>
END_OF_PREAMBLE
);

$smarty->assign('P_S', array(

	// MTH4100 2014 Q1(a)
	array(
	'P' => 'Find the set of all \(x \in \mathbb{R}\) which satisfy the inequality
	\[ |x - 1| \le x^2 - 1. \]',
	'S' => 'plot({abs(x-1), x^2-1}, x=(-3 .. 3));
% Clearly, the problem is equivalent to -(x-1) <= x^2-1.
solve(-(x-1)=x^2-1);
% Hence the solution is x <= -2 or x >= 1.'),

	// (b)
	array(
	'P' => 'Let \[ f(x) = \frac{x^2 - 4x + 4}{x^2 - x - 2} \]
	for all \(x \in \mathbb{R} \setminus \{-1, 2\}\).
	Determine whether each of the following limits exist,
	giving the value if it exists:
	\[ \lim_{x \to -1} f(x); \quad \lim_{x \to 2} f(x); \quad \lim_{x \to \infty} f(x). \]
	Determine whether \(f\) has a continuous extension at \(x = -1\) or \(x = 2\),
	defining the extension if it exists.',
		'S' => 'f := (x^2-4x+4)/(x^2-x-2);
limit(f, x, -1);  % i.e. no finite limit
limit(f, x, 2);
limit(f, x, infinity);
% Note that
on gcd;  f;  off gcd;
% Hence no continuous extension at x = -1 but a continuous extension as above at x = 2.'),

	// (c)
	array(
	'P' => 'Determine the derivative of the function arctan.',
	'S' => 'df(atan x, x);'),

	// (d)
	array(
	'P' => 'Find the equation of the tangent to the curve
	\(y^3 + x^2y - 3x + 1 = 0\) at the point \((1, 1)\).',
	'S' => <<< END_OF_SOLN
depend y, x;  curve := y^3 + x^2*y - 3x + 1; % = 0
df(curve, x);
solve(ws, df(y,x));
m := sub(x=1, y=1, rhs first ws);
tangent := (y-1) - m*(x-1); % = 0
% The following trick plots the implicitly-defined curve and tangent line
% together, but unfortunately with a gap and with the x-axis vertical:
plot(curve*tangent=0, x=(0 .. 2), y=(0 .. 2), points=100);
nodepend y, x;
END_OF_SOLN
),

	// (e)
	array(
	'P' => 'Find the area of the region bounded above by the curve
	\(x^2 + y^2 = 2\) and below by the curve \(y = x^2\).',
	'S' => 'solve(x^2 + y^2 = 2, y);
above := rhs first ws;
below := x^2;
solve(above = below);
int(above - below, x, -1, 1);'),

	// (f)
	array(
	'P' => 'Evaluate \[ \int (x + 2) \ln(x - 3) \, dx . \]',
	'S' => 'define ln = log;  % or just use log instead of ln
int((x+2)*ln(x-3), x);
% This form is slightly tidier:
factor log;  ws;'),


	// Q2
	array(
	'P' => 'Consider the curve \(y = f(x)\) for the function \(f(x) = 3x^\frac23(5 - x)\).
	<ol>
		<li>Identify the domain of \(f\) and determine whether or not \(f\) is an even function or an odd function.</li>
		<li>Find \(f\'(x)\) and \(f\'\'(x)\).</li>
		<li>Find the critical points of \(f\), determine where \(f\) is increasing or decreasing, and determine the behavior of \(f\) at each of its critical points.</li>
		<li>Find the inflexion points for \(f\), if any occur, and determine the concavity of the curve.</li>
		<li>Determine the behavior of \(f(x)\) as \(x \to \pm\infty\) and identify any asymptotes.</li>
		<li>Plot key points, such as intercepts, critical points, and points of inflexion, and sketch the curve.</li>
	</ol>',
	'S' => <<< END_OF_SOLN
operator f;  let f(~x) => 3x^(2/3)*(5-x);
% Domain is x >= 0 since x^(2/3) is undefined for x < 0.
% Hence f(x) is neither even nor odd.  Also, formally:
if f(x) = f(-x) then even else if f(x) = -f(-x) then odd else neither;
df(f(x), x);  operator fp;  for all x saveas fp(x);
df(f(x), x, 2);  operator fpp;  for all x saveas fpp(x);
solve fp(x);
% One critical point at x = 2.
fpp(rhs first ws);
% This critical point is a maximum. Hence f is increasing for x < 2 and decreasing for x > 2.
solve fpp(x);
% No inflexion points (within the domain of f).
% Hence (since f'' < 0) f is (strictly) concave (downwards).
limit(f(x), x, infinity);
plot(f(x), x=(0 .. 6));
END_OF_SOLN
),


	// MTH4101 2014 Q1(a)
	array(
	'P' => 'Consider the function \[ f(x, y) = \frac{2x - xy - 3y + 6}{y - 2}, y \not= 2. \]
	Find the limit of \(f\) as \((x, y) \to (1, 2)\).',
	'S' => 'f := (2x - x*y -3y + 6)/(y - 2);  sub(x=1, y=2, f);'),

	// (b)
	array(
	'P' => 'Find the directional derivative of the function
	\[f(x, y, z) = xy + xz + yz\]
	at the point \((-1, 1, -2)\) in the direction of the vector
	\(\mathbf{A} = \mathbf{i} - 2\mathbf{j} + 2\mathbf{k}\).',
	'S' => 'f := x*y + x*z + y*z;
load_package avector;
g := grad f;
x := -1$ y := 1$ z := -2$ g := avec(g(0),g(1),g(2)); clear x,y,z;
A := avec(1, -2, 2);  % i - 2j + 2k
g dot (A/vmod A);'),

	// (c)
	array(
	'P' => 'Find the linearisation of \[f(x, y) = 7x + 3y - 11\]
	at the point \((2, 3)\).',
	'S' => 'f := 7x + 3y - 11;
{df(f,x), df(f,y), f};
sub(x=2, y=3, ws);
x*first ws + y*second ws + third ws;'),

	// (d)
	array(
	'P' => 'Obtain the limit as \(n \to \infty\) for the sequence
	\[ a_n = \left(1 + \frac5n\right)^n. \]',
	'S' => 'an := (1 + 5/n)^n;
limit(an, n, infinity);'),

	// (e)
	array(
	'P' => 'Find the sum of the series \[ \sum_{k=0}^\infty (-2)^k \frac3{4^k}. \]',
	'S' => '% Must do some of the work by hand for this example!
% s := (-2)^k*3/4^k;  % doesn\'t simplify (even with on combineexpt), so
s := (-2/4)^k*3;
sum(s, k, 0, infinity);  % obviously should evaluate to 2.
% sum(s, k, 0, n);  limit(ws, n, infinity);  % doesn\'t simplify'),

	// (f)
	array(
	'P' => 'Sketch the region of integration and evaluate the integral
	\[ \int_0^1 \int_y^\sqrt y (3x - 1) \, dx \, dy. \]
	Then reverse the order of integration and re-evaluate the integral.',
	'S' => 'plot({x,x^2}, x=(0 .. 1));
% As in the question:
int( int(3x-1, x, y, sqrt y), y, 0, 1);
% With the order of integration reversed:
int( int(3x-1, y, x^2, x), x, 0, 1);'),

	// (g)
	array(
	'P' => 'Find the Jacobian \(\partial(x,y,z)/\partial(u,v,w)\) for the
	transformation \(x = v + 2w, y = u + vw, z = uv^2.\)',
	'S' => 'load_package linalg;
mat_jacobian({v+2w, u+v*w, u*v^2}, {u, v, w});'),

	// (h)
	array(
	'P' => 'Solve the differential equation \[ \frac{dy}{dx} = e^{y-x} \]
	and confirm the solution.',
	'S' => 'depend y, x;  df(y,x) = exp(y-x);
saveas ode;
odesolve ode;
solve(ws, y);
sub(ws, ode);
% This equation is clearly true, even if REDUCE
% doesn\'t seem to know that exp(2 arbint i pi) = 1.
nodepend y, x;'),


	// Q2(c)
	array(
	'P' => 'Let \[ f(x,y) = \frac{x^2}4 + y^2. \]
	Sketch the level curve \(f = 2\).
	Calculate the gradient vector \(\nabla f\) at the point
	\((2, -1)\) and sketch it. Then calculate the equation for the
	tangent line to the level curve at the same point and sketch it.',
	'S' => 'f := x^2/4 + y^2;
plot(f - 2 = 0, x = (-3 .. 3), y = (-2 .. 2));
load_package avector;
g := grad f;
x := 2$ y := -1$ p := avec(x,y,0); g := avec(g(0), g(1), 0); clear x, y;
% There is currently no way to plot this vector together with the curve.
tangent := avec(-g(1), g(0), 0);
% A general point on the tangent line is given for any real alpha by
line := p + alpha*tangent;
eqn := avec(x,y,0) - line;
solve(eqn(0), alpha);
sub(ws, eqn(1));
% The Cartesian equation of the line is
first solve(ws, y);
y_tangent := rhs ws$

% Until plot handles mixed data better...
eps := 1e-6$
solve(f = 2, y)$
plot({rhs first ws, rhs second ws, y_tangent},
   x = (-2 sqrt 2+eps .. 2 sqrt 2-eps), y = (-sqrt 2+eps .. sqrt 2-eps));'),


	// Q3
	array(
	'P' => 'Use the method of Lagrange multipliers to find the extreme points of
	the function \[ f(x,y) = xy \]
	subject to the condition \[ x^2 + y^2 = 9. \]
	Determine the value of the function \(f\) at each of the extreme points.',
	'S' => 'f := x*y;
g := x^2 + y^2 - 9;  % = 0
% Define a Lagrangian function L with Lagrange multiplier lam and find its critical points:
L := f - lam*g;
{df(L,x), df(L,y), g};
solns := solve ws;
for each soln in solns do write append(rest soln, sub(soln, {f, g}));
% Hence x = y = +/- 3/sqrt 2 are maxima with f = 9/2 and x = -y = +/- 3/sqrt 2 are minima with f = -9/2.'),


	// Q5(b)
	array(
	'P' => 'Find the Taylor series generated by \(f(x) = e^{2x}\) at \(x = 0\).',
	'S' => 'f := exp(2x);
df(f,x,1);  df(f,x,2);  df(f,x,3);
% Conclude that df(f,x,n) evaluated at x = 0 is
sub(x=0, 2^n*exp(2x));
% Hence the nth term is
operator term;  let term ~n => 2^n*x^n/factorial n;
% The Taylor series is the sum of this general term for n from 0 to infinity.
% The Taylor polynomial to degree 6 is
for n := 0:6 sum term n;
% This looks better like this:
on div;  ws;  off div;
% Apart from term order, this is the same as
taylorprintterms := all$
taylor(f, x, 0, 6);'),

));

$smarty->display('tutorial.tpl');

?>
