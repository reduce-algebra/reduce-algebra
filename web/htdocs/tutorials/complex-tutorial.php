<?php
$header_title = 'Tutorial: Complex Variables';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>

<p><a href="https://sourceforge.net/users/fjwright/">Francis Wright</a>, June 2018</p>

<div class="accordion" id="P_S_accordion">

    <div>
        <!-- Problem MTH5103 Exam 2014 Q1 -->
	<div>
            <ol style="list-style: lower-alpha">
                <li>Find all solutions \(z \in \mathbb{C}\) of the equation \(z^3 = 8\).</li>
                <li>Find all solutions \(z \in \mathbb{C}\) of the equation \(e^{3z} = 1\).</li>
                <li>Suppose \(w = f(z) = \frac{z-1}{z-3}\).  Show that the image under
                    \(f\) of the line \(Re(z) = 2\) is the unit circle
                    \(\{w \in \mathbb{C} : |w| = 1\}\).</li>
            </ol>
	</div>
        <!-- Solution -->
        <pre>% (a)
solve(z^3=8);
% (b)
solve(exp(3z)=1);
% (c)
w := (z-1)/(z-3)$
z := 2 + i*y$  w;
(w * conj w) where impart y => 0, repart y => y;  % since y is real</pre>
    </div>

    <div>
        <!-- Problem MTH5103 Exam 2014 Q2(b) -->
	<div>
	    Find the Taylor series expansion \(\sum_{n=0}^\infty
            a_n(z-3)^n\) of \(f(z) = 1/(1+4z)\) about the point \(z_0
            = 3\).
        </div>
        <!-- Solution -->
        <pre>clear z;  f := 1/(1+4z);
% Deduce that the nth derivative is (-4)^n*n!/(1+4z)^(n+1).  Hence
operator a;  let a(~n) => (-4)^n/13^(n+1);
on div, revpri;  for n := 0:6 sum a(n)*!(z!-3!)^n;
% where I have used !(z!-3!) instead of (z-3) to stop the powers being expanded.
% Check:
load_package "taylor";
taylorprintterms := all$
taylor(f,z,3,6);</pre>
    </div>

    <div>
        <!-- Problem MTH5103 Exam 2014 Q2(d) -->
	<div>
            If \(g(z) = \frac{1}{(z-1)(3-z)}\), find the Laurent
            series \(\sum_{n=0}^\infty a_n(z-1)^n + \sum_{n=1}^\infty
            b_n(z-1)^{-n}\) for \(g\) about the point \(z = 1\).
        </div>
        <!-- Solution -->
        <pre>on factor;
g := 1/((z-1)*(3-z));
gpf := pf(g,z);
load_package "taylor";
taylorprintterms := all$
write "Increasing sum is ", taylor(second gpf, z, 1, 6);
write "Decreasing sum is ", first gpf;
off factor;</pre>
    </div>

    <div>
        <!-- Problem MTH5103 Exam 2014 Q3(c) -->
	<div>
            Let \(f(z) = y(3x^2 - y^2) + ix(x^2 - 3y^2)\).  Show that
            \(f\) is complex differentiable at just one point, and
            compute its derivative at this point.
        </div>
        <!-- Solution -->
        <pre>% f(z) = y*(3x^2-y^2) + i*x*(x^2-3y^2) = u(x,y) + i*v(x,y) where z = x * i*y.
% Hence
u := y*(3x^2-y^2);  v := x*(x^2-3y^2);
% The Cauchy-Riemann equations are
{df(u,x) = df(v,y), df(u,y) = -df(v,x)};
solve ws;
sub(ws, df(u + i*v,x));</pre>
    </div>

    <div>
        <!-- Problem MTH5103 Exam 2014 Q4(b) -->
	<div>
            Locate the poles of the function
            \[ f(z) = \frac{z}{(z^2 + 9)^2}. \]
            Determine the order of each pole, and its residue.
        </div>
        <!-- Solution -->
        <pre>f := z/(z^2+9)^2;
poles := solve(den f);  orders := root_multiplicities;
z0 := rhs first poles$  ord := first orders$
limit(f*(z-z0)^ord, z, z0);
z0 := rhs second poles$  ord := second orders$
limit(f*(z-z0)^ord, z, z0);</pre>
    </div>

    <div>
        <!-- Problem MTH5103 Exam 2014 Q5(b) -->
	<div>
            Evaluate the integral \(\int_C f(z)\,dz\) when \(f(z) =
            \bar{z}\) (the complex conjugate of \(z\)) and
            <ol style="list-style: lower-alpha">
                <li>\(C\) is the straight line segment from \(+2\) to \(-2\).</li>
                <li>\(C\) is the curve from \(+2\) to \(-2\) along the upper half of
                    the radius-\(2\) circle centred at \(0\).</li>
            </ol>
	</div>
        <!-- Solution -->
        <pre>f := conj z$
% (a)
let repart x => x, impart x => 0;  % since x is real
z := x;  % x = +2 to x = -2
f;  int(f, x, +2, -2);
% (b)
let repart theta => theta, impart theta => 0;  % since theta is real
z := 2 exp(i*theta);  % theta from 0 to pi
f;  int(f, theta, 0, pi);</pre>
    </div>

    <div>
        <!-- Problem MTH5103 Exam 2014 Q6(a) -->
	<div>
            Use Cauchy's Theorem to calculate
            \[ \int_C \frac{\sin(z)}{z^2 + 2z + 2} \, dz \]
            where \(C\) is the positively oriented circle centred at the origin
            with radius \(1\), being careful to justify your answer.
	</div>
        <!-- Solution -->
        <pre>clear z;  on complex;
operator f;  let f(~z) => sin(z)/(z^2+2z+2);
poles := solve(den f(z));  orders := root_multiplicities;
z0 := rhs first poles;  abs z0;  % > 1 so outside C
z0 := rhs second poles;  abs z0;  % > 1 so outside C
% No poles inside (or on) C, so integral = 0.</pre>
    </div>

</div>

<?php
include '../include/end-tutorial.php';
?>
