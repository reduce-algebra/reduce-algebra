<?php
$header_title = 'Tutorial: Essential Mathematics';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>

<p><a href="https://sourceforge.net/users/fjwright/">Francis Wright</a>, June 2018</p>
<p>
    The problems on this page are taken from
    <a href="http://www.maths.qmul.ac.uk/~fvivaldi/books/em/">essential
        mathematics</a>, a free web-book by franco vivaldi.  I include
    the answers essentially as given in the web-book to show precisely
    what simplification I am aiming at using REDUCE.
</p>
<p>
    Click on a problem header to show/hide my REDUCE solution.
</p>

<div class="accordion" id="P_S_accordion">

    <div>
        <!-- Problem -->
	<p>
            How many of the following integers are prime?
            \[ 19,\quad 29,\quad 39,\quad 49,\quad 59,\quad 69 \]</p>
        <p><strong>Ans:</strong> 3</p>
        <!-- Solution -->
        <pre>for each i in {19, 29, 39, 49, 59, 69} sum if primep i then 1 else 0;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Determine the least common multiple of \(120\) and
            \(54\) in fully factorized form (i.e. as a product of
            positive integer powers of prime numbers).</p>
        <p><strong>Ans:</strong> \(2^3\cdot 3^3\cdot 5\)</p>
        <!-- Solution -->
        <pre>lcm(120, 54);  factorize ws;

COMMENT Displaying this result as an explicit product of powers is an
interesting exercise in REDUCE symbolic-mode programming. Here is one
way to do it:;

saveas p;  share p, q;
symbolic;  p;
q := 'list . mapcar(cdr p, function(lambda x; list('list, compress('!! . explode cadr x), caddr x)));
algebraic;  q;
for each l in q product first l ^ second l;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Determine the fractional part of \(\displaystyle\frac{2000}{13}\).</p>
        <p><strong>Ans:</strong> \(\frac{11}{13}\)</p>
        <!-- Solution -->
        <pre>2000/13$  ws - fix ws;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Determine the integer nearest to \(\displaystyle\frac{2225}{7}\).</p>
        <p><strong>Ans:</strong> \(318\)</p>
        <!-- Solution -->
        <pre>round(2225/7);</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Evaluate
            \[
            -\left(-\frac{1}{4}\right)\times\left(-\frac{2}{5}\right)+
            \left[\left(-\frac{5}{2}+\frac{5}{3}\right)^2-1+\frac{3}{12}\right]\div
            \left[-\frac{1}{11}\times\left(-\frac{11}{12}\right)^2+\left(-\frac{3}{4}+\frac{2}{3}\right)^2\right].
            \]</p>
        <p><strong>Ans:</strong> \(\frac{7}{10}\)</p>
        <!-- Solution -->
        <pre>-(-1/4)*(-2/5) + ((-5/2+5/3)^2-1+3/12) / (-1/11*(-11/12)^2+(-3/4+2/3)^2);</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Estimate
            \[ x=\frac{2}{5}\times{25001}\times\frac{60}{5999} \] by
            finding the integer \(n\) such that
            \(10^n&lt;x&lt;10^{n+1}\).</p>
        <p><strong>Ans:</strong> \(n=2, 10^2&lt;x&lt;10^3\)</p>
        <!-- Solution -->
        <pre>x := 2/5 * 25001 * 60/5999;
on rounded;  x;  log10(x);  off rounded;
% Conjecture 10^2 < x < 10^3; now prove it:
if 10^2 < x and x < 10^3 then true else false;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Find the value of the positive integer \(n\) such that the
            greatest common divisor \(x\) of \(72\) and \(30^3\)
            satisfies \(2^n&le;x&lt;2^{n+1}\).</p>
        <p><strong>Ans:</strong> \(n=6, 64&le;x&lt;128\)</p>
        <!-- Solution -->
        <pre>x := gcd(72, 30^3);
on rounded;  logb(x,2);  off rounded;  n := fix ws;
if 2^n <= x and x < 2^(n+1) then true else false;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Simplify
            \[ \left(\frac{x^3}{-z^2}\right)^{2}\,\left(-\frac{z^2}{z\,y^{-3}}\right)^{-3}\,(1/x)^2. \]</p>
        <p><strong>Ans:</strong> \(-\frac{x^4}{z^7y^9}\)</p>
        <!-- Solution -->
        <pre>clear x;
(x^3/(-z^2))^2 * (-z^2/(z*y^-3))^(-3) * (1/x)^2;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Compute the quotient of the following division
            \[ (-y^4-y^3+1)\,\div\,(y+2). \]</p>
        <p><strong>Ans:</strong> \(-y^3+y^2-2y+4\)</p>
        <!-- Solution -->
        <pre>first divide(-y^4 - y^3 + 1, y + 2);</pre>
    </div>

    <div>
        <!-- Problem -->
        When \(15x^2+6x-70x-28\) is factored completely, show that
        one of these factors is \(3x-14\).
        <!-- Solution -->
        <pre>on factor;  15x^2 + 6x - 70x - 28;  off factor;</pre>
    </div>

    <div>
        <!-- Problem -->
        When \(32s^2q+3r^2p-12s^2p-8r^2q\) is factored completely,
        show that one of these factors is \(r+2s\).
        <!-- Solution -->
        <pre>on factor;  32s^2*q + 3r^2*p - 12s^2*p - 8r^2*q;  off factor;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Add and simplify to fully factorized form
            \[ \frac{-z}{z^2-5z}+\frac{2z}{z^2-3z-10}. \]</p>
        <p><strong>Ans:</strong> \(\frac{z-2}{(z+2)(z-5)}\)</p>
        <!-- Solution -->
        <pre>on factor;  -z/(z^2-5z) + 2z/(z^2-3z-10);  off factor;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Simplify
            \[
            \left(\frac{1}{2}x^2-1\right)^2+\left[\left(\frac{x}{2}-\frac{3y}{2}\right)^2+
            y\left(\frac{3}{2}x-\frac{9}{4}y\right)+\frac{3}{2}x^2\right]^2\div\left(-\frac{7}{4}\right).
            \]</p>
        <p><strong>Ans:</strong> \(-\frac{3}{2}x^4-x^2+1\)</p>
        <!-- Solution -->
        <pre>(1/2x^2-1)^2 + ((x/2-3y/2)^2 + y*(3/2x-9/4y) + 3/2x^2)^2 / (-7/4);
on div;  ws;  off div;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Compute \(f(-a^{-1})\), where
            \[ f(y)=\frac{y}{3}-\frac{y^2-y^3}{y}. \]</p>
        <p><strong>Ans:</strong> \(\frac{2a+3}{3a^2}\)</p>
        <!-- Solution -->
        <pre>operator f;  let f(~y) => y/3 - (y^2-y^3)/y;
f(-a^-1);</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Simplify, eliminating radicals at denominator
            \[ \frac{\sqrt{2}\sqrt{6}}{5-\sqrt{3^3}}-\sqrt{\frac{1}{3}}. \]</p>
        <p><strong>Ans:</strong> \(-\frac{27+16\sqrt{3}}{3}\)</p>
        <!-- Solution -->
        <pre>q := sqrt(2)*sqrt(6)/(5-sqrt(3)^3) - sqrt(1/3);
on rationalize;  ws;  off rationalize;</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Simplify, eliminating radicals at denominator
            \[ \frac{2}{\sqrt{5a+1}}\,\sqrt{-a^2+\frac{1}{25}}. \]</p>
        <p><strong>Ans:</strong> \(\frac{2\sqrt{1-5a}}{5}\)</p>
        <!-- Solution -->
        <pre>2/sqrt(5a+1)*sqrt(-a^2+1/25);
sqrt(ws^2);</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Solve
            \[ \frac{z-3}{5}-\frac{2z^2+z}{3z}-1&lt;\frac{4z-1}{15}+2z. \]</p>
        <p><strong>Ans:</strong> \(z>-\frac{28}{41}\)</p>
        <!-- Solution -->
        <pre>let l = (z-3)/5 - (2z^2+z)/(3z) - 1, r = (4z-1)/15 + 2z;
% l < r implies
r - l; % > 0
solve ws;
% So the solution is z > -28/41.</pre>
    </div>

    <div>
        <!-- Problem -->
	<p>
            Find all solutions of
            \[ 2\sqrt{x+1}+x=0. \]</p>
        <p><strong>Ans:</strong> \(2-2\sqrt{2}\)</p>
        <!-- Solution -->
        <pre>solve(2sqrt(x+1)+x = 0);</pre>
    </div>

</div>

<?php
include '../include/end-tutorial.php';
?>
