<?php

require_once('../../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Tutorial: Pure Mathematics');

$smarty->assign('preamble',  <<< END_OF_PREAMBLE
    <p><a href="https://sourceforge.net/users/fjwright/">Francis Wright</a>, June 2018</p>
END_OF_PREAMBLE
);

$smarty->assign('P_S', array(

    // MTH4104 Introduction to Algebra Exam 2014 Q2
    array(
        'P' => '<ol style="list-style: lower-alpha">
  <li>Use the Euclidean algorithm to compute \(\gcd(426,330)\).</li>
  <li>Find a solution to the equation
    \[ 426k + 330\ell = \gcd(426,330) \]
    where \(k\) and \(\ell\) are integers.</li>
</ol>',
        'S' => '% This problem is not algebraic and we need integer Euclidean division, so...
symbolic$

gcd(426, 330);

% This implementation of the extended Euclidean algorithm
% is based on <a href="/books.php#Davenport-Siret-Tournier">Davenport, Siret &amp; Tournier</a>, page 214.
q := 426;  r := 330;
qq := {1,0};  rr := {0,1};
while r neq 0 do <<
   tmp := quotient(q,r);
   tt := {first qq - tmp*first rr, second qq - tmp*second rr};
   tmp := remainder(q,r);
   q := r;  r := tmp;
   qq := rr;  rr := tt >>$

write "GCD = ", q$
write "{k,l} = ", qq$

% Check:
426*first qq + 330*second qq;

algebraic$'),

    // Q3
    array(
        'P' => 'Solve the following system of equations over \(\mathbb{Z}_{11}\) for \(x\) and \(y\).
  \[
  \begin{eqnarray*}
  [4]_{11} x + [7]_{11} y &=& [4]_{11} \\\\
  [2]_{11} x + [6]_{11} y &=& [1]_{11}.
  \end{eqnarray*}
  \]
Check your answer.',
        'S' => 'setmod 11; on modular;
eqns := {4x + 7y = 4, 2x + 6y = 1};
solve eqns;
% Check:
sub(ws, eqns);
off modular;'),

    // Q5
    array(
        'P' => 'Prove, using mathematical induction, that
\[ 12 \mid (7^n -3^{n+1} +2) \]
for all natural numbers \(n \ge 0\).',
        'S' => '% First, explore the problem:
operator d; let d(~n) => 7^n-3^(n+1)+2;
for n := 0:5 collect d(n);
for n := 0:5 collect remainder(d(n), 12);
d(n+1) - d(n);
% This is divisible by 12, because 7^n and 3^n must both be odd, so (7^n - 3^n) must be even.
% Base case: d(0) = 0 is divisible by 12.
% Induction step: Suppose 12|d(n).
% Then 12|d(n+1) because d(n+1) = d(n) + 6(7^n - 3^n) and both summands are divisible by 12.'),

    // Q8
    array(
        'P' => 'Let the operations of addition and multiplication on the set
  \[ K = \{at+bu : a,b\in\mathbb{R}\}, \]
  where \(t\) and \(u\) are formal symbols, be defined as follows:
  \[
  \begin{eqnarray*}
  (at+bu)+(ct+du) &=& (a+c)t+(b+d)u, \\\\
  (at+bu) \cdot (ct+du) &=& (ac+ad+bc-bd)t+(-ac+ad+bc+bd)u.
  \end{eqnarray*}
  \]
<ol style="list-style: lower-alpha">
  <li>Compute \((\frac12 t - \frac12 u)^2\) and express the result in the form \(at+bu\).</li>
  <li>Find a multiplicative identity in \(K\), and prove that the multiplication
    in \(K\) satisfies the identity law.</li>
  <li>Specify a bijection \(f : \mathbb{C}\to K\) such that
    \(f(\alpha+\beta) = f(\alpha)+ f(\beta)\) and \(f(\alpha\beta) =
    f(\alpha) f(\beta)\) for all complex numbers \(\alpha\) and
    \(\beta\).<br />
    [Such a bijection is called an <em>isomorphism</em> of rings.]</li>
</ol>',
        'S' => '% Two general elements of K are
k1 := a*t+b*u$  k2 := c*t+d*u$
operator kplus, ktimes;
let kplus(~k1,~k2) =>
   (coeffn(k1,t,1)+coeffn(k2,t,1))*t + (coeffn(k1,u,1)+coeffn(k2,u,1))*u,
   ktimes(~k1,~k2) =>
   begin scalar a,b,c,d;
      a := coeffn(k1,t,1);  b := coeffn(k1,u,1);
      c := coeffn(k2,t,1);  d := coeffn(k2,u,1);
      return (a*c+a*d+b*c-b*d)*t + (-a*c+a*d+b*c+b*d)*u
   end;
% Check the above definitions:
factor t, u;  on div;
kplus(k1,k2);  ktimes(k1,k2);
% (a)
k3 := 1/2*t-1/2*u;  ktimes(k3,k3);
% (b) If k2 is a multiplicative identity for k1 then
ktimes(k1,k2) = k1;
lhs ws - rhs ws$
solve({coeffn(ws,t,1),coeffn(ws,u,1)}, {c,d});
% Hence the multiplicative identity in K is
kid := sub(ws, k2);
% (c) The obvious bijection would be that
% (a + i*b) in C is equivalent to (a*t + b*u) in K:
operator f;  let f(~k) => coeffn(k,t,1) + coeffn(k,u,1)*i;
% However...
f(kplus(k1,k2)) = f(k1) + f(k2);  % works
f(ktimes(k1,k2)) = f(k1) * f(k2);  % fails!

% The bijection must be linear but more symmetric, so try
let f(~k) => (coefn(k,t,1) + coefn(k,u,1)) +
   (coefn(k,t,1) - coefn(k,u,1))*i;

f(kplus(k1,k2)) = f(k1) + f(k2);
if f(kplus(k1,k2)) = f(k1) + f(k2) then true else false;

f(ktimes(k1,k2)) = f(k1) * f(k2);
if f(ktimes(k1,k2)) = f(k1) * f(k2) then true else false;

% Check that f really is a bijection:
f(k1) = c + i*d;
lhs ws - rhs ws$
{coefn(ws,i,0), coefn(ws,i,1)}$  % i.e real and imaginary parts
solve(ws, {a,b});
% which specifies k1 uniquely for any complex number (c + i*d).
off div;')

));

$smarty->display('tutorial.tpl');

?>
