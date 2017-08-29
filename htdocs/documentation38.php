<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>REDUCE Documentation</title>
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
	<style type="text/css">
		#main a {
			font-weight: bold
		}
	</style>
</head>
<body>
	<div id="content">
		<h1>REDUCE 3.8 Documentation</h1>
		<div id="middle">
			<nav>
				<script language="php">
						include 'navigation.inc';
				</script>
			</nav>
			<div id="main">
				<p>REDUCE 3.8, released in 2004, was the last commercial release of REDUCE before it became Open Source in 2008. This page provides access to the REDUCE 3.8 documentation, mainly for historical interest.</p>
				<p>One key document is the <a href="reduce38-docs/reduce.pdf">REDUCE User&#39;s Manual</a>, version 3.8. This provides a comprehensive guide to the REDUCE language and the supported packages. A comprehensive html-based <a href="reduce38-docs/help/index.html">help facility</a> indexes essentially all capabilities of the system. A <a href="reduce38-docs/primer.pdf">primer</a> for the symbolic mode of REDUCE and the <a href="reduce38-docs/sl.pdf">Standard Lisp Report</a> are also online.</p>
				<p>The particular packages with their own documentation are as follows:</p>
				<ul>
					<li>
						<a href="reduce38-docs/algint.pdf">algint</a> This 
  package extends the INT operator so it can handle a wider range of expressions 
  involving square roots.
					</li>
					<li>
						<a href="reduce38-docs/applysym.pdf">applysym</a> This package provides 
  three programs APPLYSYM, QUASILINPDE and DETRAFO for computing with 
  infinitesimal symmetries of differential equations. 
					</li>
					<li>
						<a href="reduce38-docs/arnum.pdf">arnum</a> This package provides facilities 
  for handling algebraic numbers as polynomial coefficients in REDUCE 
  calculations. It includes facilities for introducing indeterminates to 
  represent algebraic numbers, for calculating splitting fields, for factoring 
  and for finding greatest common divisors in such domains.
					</li>
					<li>
						<a href="reduce38-docs/assist.pdf">assist</a> ASSIST contains a large number 
  of additional general purpose functions that allow a user to better adapt 
  REDUCE to various calculational strategies and to make the programming task 
  more straightforward and more efficient.
					</li>
					<li>
						<a href="reduce38-docs/atensor.ps">atensor</a> This 
  package supports tensor manipulation.
					</li>
					<li>
						<a href="reduce38-docs/avector.pdf">avector</a> This package performs vector 
  algebra using the same notation as scalar algebra. The basic algebraic 
  operations are supported, as are differentiation and integration of vectors 
  with respect to scalar variables, cross product and dot product, component 
  manipulation and application of scalar functions (e.g. cosine) to a vector to 
  yield a vector result.
					</li>
					<li>
						<a href="reduce38-docs/boolean.pdf">boolean</a> This package supports 
  computation with boolean expressions in the propositional calculus. The data 
  objects are composed from algebraic expressions connected by the infix boolean 
  operators <i>and</i>, <i>or</i>, <i>implies</i>, <i>equiv</i>, and the unary 
  prefix operator <i>not</i>. BOOLEAN allows you to simplify expressions built 
  from these operators, and to test properties like equivalence, subset property 
  etc.
					</li>
					<li>
						<a href="reduce38-docs/cali.pdf">cali</a> CALI contains algorithms for 
  computations in commutative algebra closely related to the Groebner algorithm 
  for ideals and modules. Its heart is a new implementation of the Groebner 
  algorithm that also allows for the computation of syzygies. This 
  implementation is also applicable to submodules of free modules with 
  generators represented as rows of a matrix. 
					</li>
					<li>
						<a href="reduce38-docs/camal.pdf">camal</a> This package implements in 
  REDUCE the Fourier transform procedures of the CAMAL package for celestial 
  mechanics. 
					</li>
					<li>
						<a href="reduce38-docs/cantens.pdf">cantens</a> CANTENS is a package that 
  creates an environment inside REDUCE which allows the user to manipulate and 
  simplify expressions containing various indexed objects such as tensors, 
  spinors, and quantum fields. 
					</li>
					<li>
						<a href="reduce38-docs/cgb.pdf">cgb</a> The CGB package provides functions 
  for computing both Comprehensive Groebner Bases (CGB's) and conventional 
  Groebner systems, and for turning Groebner systems into CGB's. 
					</li>
					<li>
						<a href="reduce38-docs/changevr.pdf">changevr</a> This package provides 
  facilities for changing the independent variables in a differential equation. 
  It is basically the application of the chain rule. 
					</li>
					<li>
						<a href="reduce38-docs/compact.pdf">compact</a> COMPACT is a package of 
  functions for the reduction of a polynomial in the presence of side relations. 
  COMPACT applies the side relations to the polynomial so that an equivalent 
  expression results with as few terms as possible. 
					</li>
					<li>
						<a href="reduce38-docs/conlaw.pdf">conlaw</a> This package presents three 
  different approaches for the determination of conservation laws of 
  differential equations. 
					</li>
					<li>
						<a href="reduce38-docs/crack.pdf">crack</a> CRACK is a package for solving 
  overdetermined systems of partial or ordinary differential equations (PDEs, 
  ODEs). Examples of programs which make use of CRACK for investigating ODEs 
  (finding symmetries, first integrals, an equivalent Lagrangian or a 
  &quot;differential factorization&quot;) are included. 
					</li>
					<li>
						<a href="reduce38-docs/cvit.pdf">cvit</a> This package provides an 
  alternative method for computing traces of Dirac gamma matrices, based on an 
  algorithm by Cvitanovich that treats gamma matrices as 3-j symbols. 
					</li>
					<li>
						<a href="reduce38-docs/defint.pdf">defint</a> DEFINT finds the definite 
  integral of an expression in a stated interval. It uses several techniques, 
  including an innovative approach based on the Meijer G-function, and contour 
  integration. 
					</li>
					<li>
						<a href="reduce38-docs/desir.pdf">desir</a> This package enables the basis 
  of formal solutions to be computed for an ordinary homogeneous differential 
  equation with polynomial coefficients over Q of any order, in the neighborhood 
  of zero (regular or irregular singular point, or ordinary point). 
					</li>
					<li>
						<a href="reduce38-docs/dfpart.pdf">dfpart</a> This package supports 
  computations with total and partial derivatives of formal function objects. 
  Such computations can be useful in the context of differential equations or 
  power series expansions. 
					</li>
					<li>
						<a href="reduce38-docs/dummy.pdf">dummy</a> This package allows a user to 
  find the canonical form of expressions involving dummy variables. In that way, 
  the simplification of polynomial expressions can be fully achieved. The 
  indeterminates are general operator objects endowed with as few properties as 
  possible. 
					</li>
					<li>
						<a href="reduce38-docs/eds.pdf">eds</a> EDS provides a number of tools for 
  setting up and manipulating exterior differential systems and implements many 
  features of the theory. Its main strengths are the ability to use anholonomic 
  or moving frames and the care taken with nonlinear problems. 
					</li>
					<li>
						<a href="reduce38-docs/excalc.pdf">excalc</a> The EXCALC package is designed 
  for easy use by all who are familiar with the calculus of Modern Differential 
  Geometry. The program is currently able to handle scalar-valued exterior 
  forms, vectors and operations between them, as well as non-scalar valued forms 
  (indexed forms). 
					</li>
					<li>
						<a href="reduce38-docs/fide.txt">fide</a> This package uses computer algebra 
  to automate the process of numerically solving systems of partial differential 
  equations (PDES). For PDE solving, the finite difference method is applied. 
  (Note: the documentation for this package is in text format.) 
					</li>
					<li>
						<a href="reduce38-docs/fps.pdf">fps</a> This package can expand a specific 
  class of functions into their corresponding Laurent-Puiseux series. 
					</li>
					<li>
						<a href="reduce38-docs/gentran.pdf">gentran</a> This package is an automatic 
  code GENerator and TRANslator. It constructs complete numerical programs based 
  on sets of algorithmic specifications and symbolic expressions. Formatted 
  FORTRAN, RATFOR or C code can be generated through a series of interactive 
  commands or under the control of a template processing routine. 
					</li>
					<li>
						<a href="reduce38-docs/geoprover.html">geoprover</a> This package provides 
  tools for the formulation and mechanized proofs of geometry statements in the 
  spirit of the &quot;Chinese Prover&quot; of W.-T. Wu and the fundamental book of S.-C. 
  Chou who proved 512 geometry theorems with this mechanized method. 
					</li>
					<li>
						<a href="reduce38-docs/ghyper.pdf">ghyper</a> The GHYPER package simplifies 
  several cases of generalized hypergeometric functions. The simplifications are 
  performed in terms of polynomials, elementary or special functions, or simpler 
  hypergeometric functions. 
					</li>
					<li>
						<a href="reduce38-docs/gnuplot.pdf">gnuplot</a> The GNUPLOT package lets one 
  use the GNUPLOT graphical system directly from inside REDUCE, either for the 
  interactive display of curves/surfaces or for the production of pictures on 
  paper. 
					</li>
					<li>
						<a href="reduce38-docs/groebner.pdf">groebner</a> The GROEBNER package 
  calculates Groebner bases using the Buchberger algorithm and provides related 
  algorithms for arithmetic with ideal bases, such as ideal quotients and 
  Hilbert polynomials. 
					</li>
					<li>
						<a href="reduce38-docs/ideals.pdf">ideals</a> This package implements the 
  basic arithmetic for polynomial ideals by using the REDUCE Groebner bases 
  package. 
					</li>
					<li>
						<a href="reduce38-docs/ineq.pdf">ineq</a> This package supports the <i>ineq_solve</i> operator that attempts to solve single inequalities and sets of 
  coupled inequalities. 
					</li>
					<li>
						<a href="reduce38-docs/invbase.pdf">invbase</a> Involutive bases are a new 
  tool for solving multivariate polynomial problems, such as solving systems of 
  polynomial equations and analyzing polynomial ideals. An involutive basis of a 
  polynomial ideal is nothing more than a special form of a redundant Groebner 
  basis. The construction of involutive bases reduces the problem of solving 
  polynomial systems to simple linear algebra. 
					</li>
					<li>
						<a href="reduce38-docs/laplace.pdf">laplace</a> This package can calculate 
  ordinary and inverse Laplace transforms of expressions. 
					</li>
					<li>
						<a href="reduce38-docs/lie.pdf">lie</a> LIE is a package of functions for 
  the classification of real n-dimensional Lie algebras. 
					</li>
					<li>
						<a href="reduce38-docs/liepde.pdf">liepde</a> LIEPDE computes infinitesimal 
  symmetries for a given single system of differential equation(s) (ODEs or PDEs). 
					</li>
					<li>
						<a href="reduce38-docs/limits.pdf">limits</a> LIMITS is a fast limit package 
  for REDUCE for functions which are continuous except for computable poles and 
  singularities. 
					</li>
					<li>
						<a href="reduce38-docs/linalg.pdf">linalg</a> This package provides a 
  selection of functions that are useful in the world of linear algebra. 
					</li>
					<li>
						<a href="reduce38-docs/mathml.pdf">mathml</a> The MathML interface for 
  REDUCE provides an easy to use series of commands, allowing it to evaluate and 
  output MathML. 
					</li>
					<li>
						<a href="reduce38-docs/meijerg.pdf">meijerg</a> The MEIJERG package 
  simplifies several forms of Meijer's G function. The simplifications are 
  performed in terms of polynomials, elementary or special functions, or 
  (generalized) hypergeometric functions. 
					</li>
					<li>
						<a href="reduce38-docs/modsr.pdf">modsr</a> This extends the SOLVE and ROOT 
  operators to modular polynomials and modular polynomial systems.<br>
					</li>
					<li>
						<a href="reduce38-docs/mrvlimit.pdf">mrvlimit</a> This package extends the 
  range of problems that can be solved by the LIMITS package. 
					</li>
					<li>
						<a href="reduce38-docs/ncpoly.pdf">ncpoly</a> This package allows the user 
  to set up automatically a consistent environment for computing in an algebra 
  where non-commutativity is defined by Lie-bracket commutators. 
					</li>
					<li>
						<a href="reduce38-docs/normform.pdf">normform</a> This package defines an 
  operator <i>smithex</i> that computes the Smith normal form of a matrix. 
					</li>
					<li>
						<a href="reduce38-docs/numeric.pdf">numeric</a> The numeric package supplies 
  procedures based on the approximation techniques of numerical mathematics. The 
  procedures use the rounded mode arithmetic of REDUCE, including the variable 
  precision feature which is exploited in some algorithms in an adaptive manner 
  to reach the desired accuracy. 
					</li>
					<li>
						<a href="reduce38-docs/odesolve.pdf">odesolve</a> The ODESOLVE package is a 
  solver for ordinary differential equations. At the present time it can handle 
  only a single scalar equation presented as an algebraic expression or 
  equation, and it can solve only first-order equations of simple types, linear 
  equations with constant coefficients and Euler equations. 
					</li>
					<li>
						<a href="reduce38-docs/orthovec.pdf">orthovec</a> ORTHOVEC is a collection 
  of REDUCE procedures and operations which provide a simple-to-use environment 
  for the manipulation of scalars and vectors. 
					</li>
					<li>
						<a href="reduce38-docs/physop.pdf">physop</a> This package provides a tool 
  for theoretical physicists wishing to perform calculations in quantum theory 
  with expressions containing operators. These operations consist mainly of the 
  calculation of commutators between operator expressions, and in the evaluation 
  of operator matrix elements in some abstract space. 
					</li>
					<li>
						<a href="reduce38-docs/pm.pdf">pm</a> PM is a general pattern matcher 
  similar in style to those found in systems such as Mathematica. 
					</li>
					<li>
						<a href="reduce38-docs/polydiv.pdf">polydiv</a> This package provides better 
  access to the standard internal polynomial division facilities of REDUCE and 
  implements polynomial pseudo-division. It provides optional local control over 
  the main variable used for division. 
					</li>
					<li>
						<a href="reduce38-docs/qsum.pdf">qsum</a> This package is an implementation 
  of the <i>q</i>-analogues of Gosper's and Zeilberger's algorithm for 
  indefinite and definite summation of <i>q</i>-hypergeometric terms. A
  <a href="reduce38-docs/qsum.ps">Postscript</a> version is also available. 
					</li>
					<li>
						<a href="reduce38-docs/randpoly.pdf">randpoly</a> This package is based on a 
  port of the Maple random polynomial generator together with some support 
  facilities for the generation of random numbers and anonymous procedures. 
					</li>
					<li>
						<a href="reduce38-docs/rataprx.pdf">rataprx</a> This package provides 
  functions to convert rational numbers into their periodic representation and 
  vice versa, to compute continued fractions and to compute the Pad&eacute; 
  approximant of a function. 
					</li>
					<li>
						<a href="reduce38-docs/ratint.pdf">ratint</a> This package implements the 
  Horowitz/Rothstein/Trager algorithms for the integration of rational 
  functions. 
					</li>
					<li>
						<a href="reduce38-docs/reacteqn.pdf">reacteqn</a> This package transforms 
  chemical reaction systems into ordinary differential equation systems 
  corresponding to the laws of pure mass action. 
					</li>
					<li>
						<a href="reduce38-docs/redlog.pdf">redlog</a> REDLOG extends REDUCE to a 
  computer logic system implementing symbolic algorithms on first-order formulas 
  with respect to temporarily fixed first-order languages and theories. 
					</li>
					<li>
						<a href="reduce38-docs/reset.pdf">reset</a> Provides support for resetting 
  REDUCE to its original state.
					</li>
					<li>
						<a href="reduce38-docs/residue.pdf">residue</a> This package supports the 
  calculation of residues. 
					</li>
					<li>
						<a href="reduce38-docs/rlfi.pdf">rlfi</a> The RLFI package provides the 
  printing of REDUCE expressions in LaTeX format, so it can be used directly for 
  document production. 
					</li>
					<li>
						<a href="reduce38-docs/roots.pdf">roots</a> The root finding package finds 
  some or all of the roots of univariate polynomials with real or complex 
  coefficients, to the accuracy specified by the user. 
					</li>
					<li>
						<a href="reduce38-docs/rsolve.pdf">rsolve</a> The <i>r_solve</i> operator 
  computes all exact rational zeros of a single univariate polynomial using fast 
  modular methods. A companion operator <i>i_solve</i> computes only integer 
  zeros by a more efficient method than extracting them from the rational zeros. 
					</li>
					<li>
						<a href="reduce38-docs/rtrace.pdf">rtrace</a> This package provides tracing 
  and debugging facilities for REDUCE programming. It is a portable version of 
  the PSL-based <a href="reduce38-docs/rdebug.pdf">rdebug</a> package. 
					</li>
					<li>
						<a href="reduce38-docs/scope.pdf">scope</a> SCOPE is a package for producing 
  an optimized form for a set of expressions. It applies a heuristic search for 
  common (sub)expressions in a set of REDUCE assignment statements. The output 
  is a sequence of assignment statements. 
					</li>
					<li>
						<a href="reduce38-docs/sets.pdf">sets</a> The SETS package provides 
  algebraic-mode support for set operations on lists regarded as sets (or 
  representing explicit sets) and on implicit sets represented by identifiers. 
					</li>
					<li>
						<a href="reduce38-docs/sparse.pdf">sparse</a> This package extends the 
  available matrix feature to enable calculations with sparse matrices. It also 
  provides a selection of functions that are useful in the world of linear 
  algebra with respect to sparse matrices. 
					</li>
					<li>
						<a href="reduce38-docs/spde.pdf">spde</a> The SPDE package provides 
  functions for determining the symmetry group of Lie- or point-symmetries of a 
  given set of partial differential equations. In many cases the determining 
  system is solved automatically. In other cases the user has to provide 
  additional information for the solution algorithm to succeed. 
					</li>
					<li>
						<a href="reduce38-docs/specfn.pdf">specfn</a> This package supplies extended 
  algebraic and numeric support for a wide class of special functions. 
					</li>
					<li>
						<a href="reduce38-docs/sum.pdf">sum</a> The <i>sum</i> operator returns the 
  indefinite or definite summation of a given expression. 
					</li>
					<li>
						<a href="reduce38-docs/susy2.pdf">susy2</a> This package deals with 
  supersymmetric functions and with the algebra of supersymmetric operators in 
  the extended N=2 as well as in the nonextended N=1 supersymmetry. 
					</li>
					<li>
						<a href="reduce38-docs/symmetry.pdf">symmetry</a> The SYMMETRY package 
  computes symmetry-adapted bases and block diagonal forms of matrices that have 
  the symmetry of a group. The package implements the theory of linear 
  representations for small finite groups such as the dihedral groups. 
					</li>
					<li>
						<a href="reduce38-docs/taylor.pdf">taylor</a> This package defines 
  procedures that compute Taylor expansions in one or more variables and 
  efficient manipulation of the resulting series. 
					</li>
					<li>
						<a href="reduce38-docs/tps.pdf">tps</a> This package implements formal 
  Laurent series expansions in one variable using the domain mechanism of 
  REDUCE, so that power series objects can be added, multiplied, differentiated 
  etc., like other first class objects in the system. 
					</li>
					<li>
						<a href="reduce38-docs/tri.pdf">tri</a> This package provides facilities 
  written in Rlisp for typesetting REDUCE formulas using TEX.
  <a href="reduce38-docs/tritest.tex">Examples</a> of using this program are also 
  available. 
					</li>
					<li>
						<a href="reduce38-docs/trigint.pdf">trigint</a> This package is an 
  implementation of a new algorithm proposed by D.J. Jeffrey and A.D. Rich that 
  removes &quot;spurious&quot; discontinuities from integrals. 
					</li>
					<li>
						<a href="reduce38-docs/trigsimp.pdf">trigsimp</a> TRIGSIMP is a useful tool 
  for all kinds of trigonometric and hyperbolic simplification and 
  factorization.
  <!--
   <li>     <a href="reduce38-docs/turtle.pdf">turtle</a>  A simple implementation
of the "Turtle Graphics" style drawing graphs in REDUCE. The background and
ideas for "Turtle Graphics" are also outlined.</li>
-->
					</li>
					<li>
						<a href="reduce38-docs/wu.pdf">wu</a> This is a simple implementation of the 
  Wu algorithm taken directly from <i>A Zero Structure Theorem for 
  Polynomial-Equations-Solving</i>, Wu Wen-tsun, Institute of Systems Science, 
  Academia Sinica, Beijing. 
					</li>
					<li>
						<a href="reduce38-docs/xcolor.pdf">xcolor</a> This package calculates the 
  color factor in non-abelian gauge field theories using an algorithm due to 
  Cvitanovich. 
					</li>
					<li>
						<a href="reduce38-docs/xideal.pdf">xideal</a> XIDEAL constructs Groebner 
  bases for solving the left ideal membership problem: Groebner left ideal bases 
  or GLIBs. 
					</li>
					<li>
						<a href="reduce38-docs/zeilberg.pdf">zeilberg</a> This package implements 
  the Gosper and Zeilberger algorithms for indefinite and definite summation of 
  hypergeometric terms, respectively. 
					</li>
					<li>
						<a href="reduce38-docs/ztrans.pdf">ztrans</a> This package is an 
  implementation of the Z-transform of a sequence, which is the discrete 
  analogue of the Laplace Transform. 
					</li>
				</ul>
				<!--
<h2> Lisp System-specific Documentation</h2>
   A REDUCE implementation is built at the present time on one of two Lisp 
systems; Codemist Standard Lisp (CSL) or Portable Standard Lisp (PSL). The 
following documents are specific to the PSL version:   
<ul>
	 <li>     <a href="reduce38-docs/pc-install.pdf">pc-install</a>  Installation
 guide for the PC version of PSL REDUCE. A <a href="reduce38-docs/pc-install.ps">Postscript</a>
 version is also available.</li>
	 <li>     <a href="reduce38-docs/pc-oper.pdf">pc-oper</a>  User's guide 
for the PC version of PSL REDUCE. A <a href="reduce38-docs/pc-oper.ps">Postscript</a> 
version is also available.</li>
	 <li>     <a href="reduce38-docs/pslman.pdf">pslman</a>      The PSL Users
 Manual, Version 4.2. A <a href="reduce38-docs/pslman.ps">Postscript</a> version is
 also available.</li>
	 <li>     <a href="reduce38-docs/rdebug.pdf">rdebug</a>  This package supports
 the use of the tracing and debugging facilities of PSL for REDUCE programming.
 A <a href="reduce38-docs/rdebug.pdf">Postscript</a> version is also available.</li>
	 <li>     <a href="reduce38-docs/unix-inst.pdf">unix-inst</a>  Installation
 guide for the Unix version of PSL REDUCE. A <a href="reduce38-docs/unix-inst.ps">Postscript</a>
 version is also available.</li>
	 <li>     <a href="reduce38-docs/unix-oper.pdf">unix-oper</a>  User's guide
 for the Unix version of PSL REDUCE. A <a href="reduce38-docs/unix-oper.ps">Postscript</a>
 version is also available.</li>
	 
</ul>
   <br>
-->
			</div>
			<!--/#main-->
		</div>
		<!--/#middle-->
	</div>
	<!--/#content-->
</body>
</html>
