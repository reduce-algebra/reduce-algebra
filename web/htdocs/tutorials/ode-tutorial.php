<?php
$header_title = 'Tutorial: Ordinary Differential Equations';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>

<p><a href="https://sourceforge.net/users/fjwright/">Francis Wright</a>, June 2018, December 2019</p>
<p>
    Click on a problem header to show/hide my REDUCE solution.
</p>

<div class="accordion" id="P_S_accordion">

    <div>
        <!-- Problem MTH5123 Differential Equations Exam 2014 Q1 -->
        <ol style="list-style: lower-alpha">
            <li>Find a function \(f(u)\) such that the
                differential equation
	        \[ f(x + y) + \ln x + \left(e^{x+y} + y^2\right)
	        \frac{dy}{dx} = 0 \] is exact.</li>
            <li>For the chosen \(f(u)\) find the corresponding
                solution in implicit form.</li>
        </ol>
        <!-- Solution -->
        <pre>% (a)
% The ODE P(x,y) + Q(x,y)df(y,x) = 0 is exact if df(P(x,y),y) = df(Q(x,y),x).
operator f;  let ln ~x => log x;
P := f(x+y) + ln x;  Q := exp(x+y) + y^2;
df(P,y) = df(Q,x);
% Obviously, f(u) = exp(u) + constant. Check:
ws where f ~u => exp u + constant;
% (b)
% The simplest solution has constant = 0, so
let f ~u => exp u;
% p = df(u,x), where u = u(x,y), so
u := int(p,x) + uy;  depend uy, y;
q = df(u,y);
solve(ws, df(uy,y));
int(lhs eqn,y) = int(rhs eqn,y) where eqn => first ws;
% Hence, the solution of the original ODE is
on div;  sub(ws,u) = constant;
off div;  clear P, Q;</pre>
    </div>

    <div>
        <!-- Problem Q1(c) -->
        Solve the initial value problem
        \[ \frac{dy}{dx} = \sqrt{y^2 + 9}, \quad y(1) = 0. \]
        <!-- Solution -->
        <pre>depend y, x;
df(y,x) = sqrt(y^2+9);
soln := odesolve(ws, {x=1, y=0});</pre>
    </div>

    <div>
        <!-- Problem Q2 -->
        <ol style="list-style: lower-alpha">
            <li>Find the general solution of the homogeneous ODE
	        \[ y'' + 9y = 0. \]</li>
            <li>Find the general solution of the non-homogeneous
	        ODE
                \[ y'' + 9y = \sin(2x). \]</li>
            <li>Find the general solution to the first-order
	        homogeneous linear ODE
                \[ y' = \tan(x)\,y. \]</li>
            <li>Solve the initial-value problem for the
	        first-order linear non-homogeneous ODE
                \[ y' = \tan(x)\,y + 1, \quad y(0) = 2. \]</li>
        </ol>
        <!-- Solution -->
        <pre>depend y, x;
% (a)
df(y,x,2) + 9y = 0;  odesolve ws;
% (b)
df(y,x,2) + 9y = sin(2x);  odesolve ws;
% (c)
df(y,x) = tan(x)*y;  odesolve ws;
% (d)
df(y,x) = tan(x)*y + 1;  odesolve(ws, {x=0, y=2});
nodepend y, x;</pre>
    </div>

    <div>
        <!-- Problem Q3 -->
        Solve the following boundary value problem for the
        second-order non-homogeneous differential equation
        \[ \frac{d^2y}{dx^2} = x^2, \quad y(0) = 0, \quad y'(1) = 0. \]
        <!-- Solution -->
        <pre>depend y, x;
df(y,x,2) = x^2;  odesolve(ws, {{x = 0, y = 0}, {x = 1, df(y,x) = 0}});</pre>
    </div>

    <div>
        <!-- Problem Q4 -->
        Consider a system of two nonlinear first-order ODEs:
        \[ \dot{x} = -x - 3y - 3x^3, \quad \dot{y} = \frac43x - y - \frac13 x^3. \]
        <ol style="list-style: lower-alpha">
            <li>Write down in the matrix form the system obtained
	        by linearization of the above equations around the
	        point \(x = y = 0\) and find the corresponding
	        eigenvalues and eigenvectors.</li>
            <li>Find the solution of the linear system
	        corresponding to the initial conditions \(x(0) =
	        2, y(0) = 0\). Determine the type of equilibrium
	        for the system and describe in words the shape of
	        trajectory in the phase plane corresponding to the
	        specified initial conditions. Determine the
	        tangent vector to the trajectory at \(t = 0\).</li>
        </ol>
        <!-- Solution -->
        <pre>% (a)
% xdot = -x - 3y; ydot = 4/3x - y
depend {x, y}, t;
dxy := mat((df(x,t)),(df(y,t)));
coef := mat((-1,-3),(4/3,-1));
xy := mat((x),(y));
% Check:
dxy = coef*xy;

ev := mateigen(coef, lam);
evals := solve first first ev;
evecs := (third first ev where arbcomplex ~j => 1);
evecs := for each eval in evals collect sub(eval,evecs);

% (b)
matrix D(2,2);  for i := 1:2 do D(i,i) := exp(rhs part(evals,i)*t);  D;
matrix P(2,2);  for i := 1:2 do for j := 1:2 do
   P(i,j) :=  &lt;&lt;v := part(evecs,j); P(i,j) := v(i,1)>>;  P;
on div, complex;
soln := P*D*P^(-1);
soln := soln*mat((x0),(y0));  % where x(0) = x0, y(0) = y0.
%Check:
ode := dxy - coef*xy;  % = 0 ?
sub(x=soln(1,1), y=soln(2,1), ode);

x0 := 2$  y0 := 0$  soln;
% The zero solution is a stable equilibrium and nearby solutions
% spiral in towards zero.
sub(t=0, sub(x=soln(1,1), y=soln(2,1), dxy));</pre>
    </div>

    <div>
        <!-- Problem -->
        (Suggested by Tony Roberts from <a href="/books.php#roberts">his book</a>.)<br />
        Find the power series solution \(y(x)\) up to degree
        \(x^7\) to the differential equation
        \[ y''+(1+x)y'-6y^2=0 \] such that
        \[ y(0)=1 \mbox{ and } y'(0)=-1. \]
        <!-- Solution -->
        <pre>% The following switch settings display the solution as usual for a
% power series:
on div; off allfac; on revpri;
y := 1 - x;  % using the initial conditions
let x^8 => 0;  % truncate at degree 7
% This loop shows successive terms converging:
for iter := 1:99 do <<  % loop at most 99 times
   res := df(y,x,2) + (1+x)*df(y,x) - 6y^2;
   write y := y + (dy := -int(int(res,x),x));
   if dy = 0 then iter := 1000;  % terminate the loop
>>;

% You can also find power series for solutions of a wide range of
% related ODEs simply by changing the lines "res := ..." and applying
% the initial conditions by changing the initial assignment "y := ...".</pre>
    </div>

</div>

<?php
include '../include/end-tutorial.php';
?>
