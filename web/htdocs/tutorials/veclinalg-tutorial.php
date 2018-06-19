<?php

require_once('../../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Tutorial: Vectors and Linear Algebra');

$smarty->assign('preamble',  <<< END_OF_PREAMBLE
	<p><a href="https://sourceforge.net/users/fjwright/">Francis Wright</a>, June 2018</p>
END_OF_PREAMBLE
);

$smarty->assign('P_S', array(

	// MTH4103 Exam 2014 Q1
	array(
		'P' => 'Let \(A = (1,3,-1)\) and \(B = (4,1,1)\), and let \(\mathbf{a}\) and
\(\mathbf{b}\) be the position vectors of \(A\) and \(B\)
respectively. Determine:
<ol style="list-style: lower-alpha">
  <li>the length of \(\mathbf{a}\);</li>
  <li>the vector having length \(3\) in the same direction as \(\mathbf{a}\);</li>
  <li>the vector represented by \(\overrightarrow{AB}\);</li>
  <li>parametric equations for the line through \(A\) and \(B\);</li>
  <li>the cosine of the angle between \(\mathbf{a}\) and \(\mathbf{b}\);</li>
  <li>the vector product \(\mathbf{a}\times\mathbf{b}\) of \(\mathbf{a}\) and \(\mathbf{b}\).</li>
</ol>',
		'S' => 'load_package avector;
a := avec(1,3,-1);  b := avec(4,1,1);
% (a)
vmod a;
% (b)
3 a/ws;
% (c)
ab := b - a;
% (d)
line := a + alpha*ab;
% Or as scalar equations:
{x = line(0), y = line(1), z = line(2)};
% (e)
(a dot b)/(vmod a * vmod b);
% (f)
a cross b;'),

	// Q2
	array(
		'P' => 'Let \(\mathbf{a} = \left(\begin{array}{c}3\\\\-1\\\\-6\end{array}\right)\),
and let \(\mathbf{b}\) and \(\mathbf{c}\) be position vectors of
points in the \((x,y)\)-plane such that the area of the parallelogram
with sides \(\mathbf{b}\) and \(\mathbf{c}\) is \(7\). Let the
parallelepiped with sides corresponding to \(\mathbf{a}\),
\(\mathbf{b}\) and \(\mathbf{c}\) have volume \(V\).
<ol style="list-style: lower-alpha">
  <li>Is there sufficient information to calculate \(V\)?</li>
  <li>If so, determine \(V\).</li>
</ol>',
		'S' => 'load_package avector;
a := avec(3,-1,-6);
k := avec(0,0,1);
% b cross c = |b cross c| k = 7 k
% V = |a dot (b cross c)| = 7 |a dot k|
% (a) Yes
% (b)
a dot k;  V := 7 abs ws;'),

	// Q3
	array(
		'P' => 'Determine <em>all</em> solutions to the following system of linear
equations in \(x, y, z\) defined over \(\mathbb{R}\):
\[
\left.\begin{eqnarray*}
-x-2y+5z &=& 8 \\\\
3x+2y+ z &=& -4 \\\\
x+ y- z &=& -3
\end{eqnarray*}\right\}.
\]',
		'S' => 'eqns := {-x-2y+5z = 8, 3x+2y+z = -4, x+y-z = -3};
solve ws;  % regarding arbcomplex() as a real parameter'),

	// Q4
	array(
		'P' => 'Calculate the distance between the <strong>parallel</strong> lines with vector equations
\[
r = \left(\begin{array}{c}2\\\\1\\\\2\end{array}\right) + \lambda
\left(\begin{array}{c}1\\\\2\\\\3\end{array}\right)
\quad\mbox{and}\quad
r =\left(\begin{array}{c}2\\\\-1\\\\3\end{array}\right) + \mu
\left(\begin{array}{c}-2\\\\-4\\\\-6\end{array}\right)
\]
respectively. (The parameters \(\lambda\) and \(\mu\) both range over
the whole of  \(\mathbb{R}\).)',
	'S' => 'load_package avector;
% This is a vector from one line to the other:
avec(2,1,2) - avec(2,-1,3);
% and this is the magnitude of its projection perpendicular to the lines:
vmod(ws cross avec(1,2,3));'),

	// Q5
	array(
		'P' => 'Let
\[
A = \left(\begin{array}{rrr}1 & 2 & 0\\\\-1 & 1 & 2\\\\1 & -2 & -1\end{array}\right)
\quad\mbox{and}\quad
B = \left(\begin{array}{rrr}2 & -1 & 0\\\\-1 & 2 & 0\\\\1 & -2 & -3\end{array}\right).
\]
Calculate the following:
<ol style="list-style: lower-alpha">
  <li>\(-2A+B\);</li>
  <li>\(A^2\);</li>
  <li>the characteristic polynomial of \(B\);</li>
  <li>\(\det B\) [Hint: the answer to the previous part should help].</li>
</ol>',
		'S' => 'a := mat((1,2,0),(-1,1,2),(1,-2,-1));
b := mat((2,-1,0),(-1,2,0),(1,-2,-3));
-2a+b;
a^2;
det(lam*mat((1,0,0),(0,1,0),(0,0,1))-b);
-sub(lam=0,ws);  % using the hint, or directly:
det b;'),

	// Q8(c)
	array(
		'P' => 'Let \(S_\theta\) denote the \(2\times2\) matrix representing the
reflexion (in the \((x,y)\)-plane) in the line through the origin at
anticlockwise angle \(\theta/2\) to the \(x\)-axis. Then
\[
S_\theta = \left(\begin{array}{cc}\cos\theta & \sin\theta \\\\ \sin\theta\ & -\cos\theta\end{array}\right).
\]
<ol style="list-style: lower-alpha">
  <li>Determine the eigenvalues of \(S_\theta\).</li>
<li>Now let \(S\) be the matrix of the reflexion in the line \(y =
  x\). Write down \(S\), and write down an eigenvector of \(S\) and
  its corresponding eigenvalue.</li>
</ol>',
		'S' => 'S_theta := mat((cos theta, sin theta),(sin theta, -cos theta));
% (a)
let cos(~th)^2 + sin(~th)^2 => 1;
E_theta := mateigen(S_theta, lam);  % Hence eigenvalues are +/- 1.
% (b)
theta := pi/2;
S := S_theta;
E_theta;
third first ws; % with corresponding eigenvalue 1.'),


	// MTH5112 Exam 2014 Q1
	array(
		'P' => 'Compute the determinant of the matrix
\[ \left(\begin{array}{ccc}
1  & -1 & 1 \\\\
2  & 0  & 1 \\\\
-1 & 2  & -2
\end{array}\right).
\]
Is this matrix invertible? If so, find its inverse.
Hence or otherwise solve the linear system
\[ \begin{eqnarray}
x_1 - x_2 + x_3 &=& 1 \\\\
2x_1 + x_3 &=& 2 \\\\
-x_1 + 2x_2 - 2x_3 &=& -3.
\end{eqnarray}
\]',
		'S' => 'M := mat((1,-1,1),(2,0,1),(-1,2,-2));
det M;
M^-1;
% Hence:
ws * mat((1),(2),(-3));
% or otherwise:
eqns := {x1 - x2 + x3 = 1, 2x1 + x3 = 2, -x1 + 2x2 - 2x3 = -3};
solve ws;'),

	// Q2
	array(
		'P' => 'Let
\[
A = \left(\begin{array}{cc}
0  & 3 \\\\
-1 & 2
\end{array}\right), \quad
B =\left(\begin{array}{cc}
-1 & 2 \\\\
0  & 3 \\\\
1  & -2
\end{array}\right).
\]
For each of the products \(A^2\), \(AB\), \(BA\), \(B^2\), state
whether or not it exists; if it exists then evaluate it.',
		'S' => 'A := mat((0,3),(-1,2));  B := mat((-1,2),(0,3),(1,-2));
A^2;  A*B;  B*A;  B^2;'),

	array(
		'P' => 'Suppose that \(B\) is a square matrix and \(B^2 = O\).  Prove that
\(I+B\) is invertible, and find its inverse.  Illustrate with a
\(2\times2\) example.',
		'S' => '% (I + B)(I - B) = I^2 - B^2 = I, hence (I + B)^-1 = (I - B)
B := mat((0,1),(0,0));  B^2;
Id := mat((1,0),(0,1));  A := Id + B;
A^-1 = Id - B;'),

	// Q3
	array(
		'P' => 'For each of the following statements about \(n\times n\) matrices
\(A\) and \(B\), state whether it is true or false, and illustrate
with general \(2\times2\) matrices.
<ol style="list-style: lower-alpha">
  <li>\(\det(A + B) = \det A + \det B\);</li>
  <li>\(\det(A + B^T) = \det(B + A^T)\);</li>
  <li>\(\det(BA) = \det(AB)\);</li>
  <li>\(\det(\lambda A) = \lambda \det A\), where \(\lambda\in\mathbb{R}\).</li>
</ol>',
		'S' => 'matrix A, B;  operator aa, bb;
for i := 1:2 do for j := 1:2 do &lt;&lt;A(i,j) := aa(i,j); B(i,j) := bb(i,j)>>;
A;  B;
% (a) false
det(A + B) = det A + det B;
if det(A + B) = det A + det B then true else false;
% (b) true
det(A + tp B)= det(tp A + B);
if det(A + tp B)= det(tp A + B) then true else false;
% (c) true
det(B*A) = det(A*B);
if det(B*A) = det(A*B) then true else false;
% (d) false (unless n=1)
det(lam*A) = lam*det(A);
if det(lam*A) = lam*det(A) then true else false;'),

	// Q4(b)
	array(
		'P' => 'Let \(V = \mathbb{R}^4\), and let
\[
S = \{(0,2,1,-3)^T, (1,1,1,2)^T, (3,0,-1,-1)^T, (-1,4,4,2)^T\}.
\]
  <strong>Either</strong> determine whether or not \(S\) is a spanning set for \(V\),
  <strong>or</strong> determine whether or not \(S\) is a linearly dependent set.',
		'S' => '% Using lists to represent vectors:
S := {{0,2,1,-3}, {1,1,1,2}, {3,0,-1,-1}, {-1,4,4,2}};
rank S;
% or equivalently
S := mat((0,2,1,-3), (1,1,1,2), (3,0,-1,-1), (-1,4,4,2));
rank S;
% S is not a spanning set because it contains only 3 linearly independent vectors.'),

	// Q5
	array(
		'P' => 'Let \(P_2\) denote the set of polynomials of degree at most \(2\), that is
\[
  P_2 = \{\mathbf{p} \mid \mathbf{p}(x) = a_2x^2 + a_1x + a_0 \mbox{ for some }
  a_0, a_1, a_2 \in \mathbb{R}\}.
\]
Let \(D : P_2 \to P_2\) be the mapping given by \(D(\mathbf{p}) =
\mathbf{q}\), where \(\mathbf{p}\'\) denotes the derivative of
\(\mathbf{p}\), and
\[
  \mathbf{q}(x) = x^2\mathbf{p}(0) + \mathbf{p}\'(x).
\]
<ol style="list-style: lower-alpha">
  <li>Show that \(D\) is a linear transformation.</li>
  <li>Is \(D\) surjective? Justify your answer.</li>
  <li>Is \(D\) injective? Justify your answer.</li>
</ol>',
		'S' => 'operator D;  let D(~p) => x^2*sub(x=0,p) + df(p,x);
p1 := a2*x^2 + a1*x + a0;  p2 := b2*x^2 + b1*x + b0;
% (a)
D(alpha*p1 + beta*p2) = alpha*D(p1) + beta*D(p2);
if D(alpha*p1 + beta*p2) = alpha*D(p1) + beta*D(p2) then true else false;
% (b) Yes if we can find p1 that maps to an arbitrary p2:
D(p1) = p2;
coeff(lhs ws - rhs ws, x);
solve(ws, {a2,a1,a0});
% (c) Yes, since precisely one p1 maps to each p2.'),

	// Q6(d)
	array(
		'P' => 'Let \(H\) be a subspace of \(\mathbb{R}^n\) and let \(H^\perp\) denote
the <em>orthogonal complement</em> of \(H\).  Suppose \(n = 4\) and
\[
H = \{(x,y,z,t)^T \mid x + 2y - 3z = 0, 3y + 2z - t = 0\}.
\]
Compute \(\dim H\), \(\dim H^\perp\), and a basis for \(H^\perp\).',
		'S' => '% First, ensure that arbitrary constants have the expected indices:
% (See <a href="/books.php#MacCallum-Wright">MacCallum and Wright</a>, footnote 31 on page 35.)
symbolic(!!arbint := 0);
solve({x+2y-3z=0, 3y+2z-t=0}, {x,y,z,t});
h := for each el in first ws collect rhs el;
% 2 parameters, so dim H = 2, with basis vectors
h1 := sub(arbcomplex(1)=1, arbcomplex(2)=0, h);
h2 := sub(arbcomplex(1)=0, arbcomplex(2)=1, h);
% Hence a vector {x,y,z,t} in Hperp must satisfy
solve({-2x+1y+0z+3t=0, 3x+0y+1z+2t=0}, {x,y,z,t});
hp := for each el in first ws collect rhs el;
% 2 parameters, so dim Hperp = 2, with basis vectors
hp1 := sub(arbcomplex(3)=1, arbcomplex(4)=0, hp);
hp2 := sub(arbcomplex(3)=0, arbcomplex(4)=1, hp);'),

	// Q8
	array(
		'P' => 'Let
\[
A = \left(\begin{array}{ccc}
-1 & 0 & 1 \\\\
2  & 3 & 2 \\\\
2  & 4 & 0
\end{array}\right), \quad
\mathbf{v}_1 = \left(\begin{array}{c}
-2 \\\\
1 \\\\
0
\end{array}\right), \quad
\mathbf{v}_2 = \left(\begin{array}{c}
1 \\\\
0 \\\\
-1
\end{array}\right).
\]
<ol style="list-style: lower-alpha">
  <li>Show that \(\mathbf{v}_1\) and \(\mathbf{v}_2\) are eigenvectors of \(A\) and find
  the corresponding eigenvalues.</li>
  <li>Find the characteristic polynomial of \(A\).</li>
  <li>Determine all eigenvalues of \(A\) and find bases for the
  corresponding eigenspaces.</li>
  <li>Find an invertible matrix \(P\) and a diagonal matrix \(D\) such
  that \(P^{-1}AP = D\).</li>
</ol>',
		'S' => 'A := mat((-1,0,1),(2,3,2),(2,4,0));
v1 := mat((-2),(1),(0));
v2 := mat((1),(0),(-1));
% (a)
A*v1;  A*v2;
% Hence the eigenvalues are respectively -1 and -2.
% (b)
det(lam*mat((1,0,0),(0,1,0),(0,0,1))-A);
% (c)
solve ws;  ev := mateigen(A, lam);
for each el in ev collect third el;
let arbcomplex(~j) => 1;  bases := ws; clear arbcomplex(~j);
% (d)
% Construct D from the eigenvalues:
for each el in ev collect rhs first solve first el;
clear D;  matrix D(3,3);
for i := 1:3 do D(i,i) := part(ws, i);  D;
% Construct P from the eigenspace bases:
matrix P(3,3);
for i := 1:3 do for j := 1:3 do P(i,j) := &lt;&lt;v:=part(bases, j); v(i,1)>>;
% Check
P^(-1)*A*P = D;'),

));

$smarty->display('tutorial.tpl');

?>
