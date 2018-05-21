<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'REDUCE Documentation');

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
<style type="text/css">
 #contributed + ul > li > a {
	 font-weight: bold
 }
</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'Documentation');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>REDUCE includes considerable documentation, not only for the core system, but also for the many application packages included in the release. (The documentation for <a href="documentation38.php">REDUCE 3.8</a>, the last commercial version of REDUCE released in 2004, is also still available.)</p>
<p>For all users:</p>
<ul>
	<li>the <strong>REDUCE User's Manual</strong> <small>[ <a href="manual/manual.html">HTML</a> | <a href="manual/manual.pdf">PDF</a> ]</small> provides a comprehensive guide to the REDUCE language and the supported packages.</li>
</ul>
<p>For advanced users:</p>
<ul>
	<li><a href="lisp-docs/insidereduce.pdf"><strong>Inside Reduce</strong></a> describes how to build REDUCE, the structure of the REDUCE source code, and some low-level programming features;</li>
	<li>the <strong>Symbolic Mode Primer</strong> <small>[ <a href="lisp-docs/primer.html">HTML</a> | <a href="lisp-docs/primer.pdf">PDF</a> ]</small> provides an introduction to programming in the REDUCE implementation language, RLISP, which is Standard Lisp with REDUCE (essentially ALGOL 60) syntax;</li>
	<li>the <strong>Standard Lisp Report</strong> <small>[ <a href="lisp-docs/sl.html">HTML</a> | <a href="lisp-docs/sl.pdf">PDF</a> ]</small> defines Standard Lisp, the dialect of Lisp assumed by REDUCE;</li>
	<li>the <strong>PSL Users Manual</strong> <small>[ <a href="lisp-docs/allman1.html">HTML</a> | <a href="lisp-docs/allman1.pdf">PDF</a> ]</small> documents Portable Standard Lisp, the original implementation of Standard Lisp, and the <a href="lisp-docs/csl.html"><strong>CSL Reference</strong></a> documents Codemist Standard Lisp, a later implementation of Standard Lisp.</li>
</ul>
<p id="contributed">The following PDF documents for the user-contributed packages are extracts from the full REDUCE User&#39;s Manual.</p>
<ul>
	<li><a href="manual/contributed/algint.pdf">ALGINT</a>: Integration of square roots</li>
	<li><a href="manual/contributed/applysym.pdf">APPLYSYM</a>: Infinitesimal symmetries of differential equations</li>
	<li><a href="manual/contributed/arnum.pdf">ARNUM</a>: An algebraic number package</li>
	<li><a href="manual/contributed/assert.pdf">ASSERT</a>: Dynamic Verification of Assertions on Function Types</li>
	<li><a href="manual/contributed/assist.pdf">ASSIST</a>: Useful utilities for various applications</li>
	<li><a href="manual/contributed/avector.pdf">AVECTOR</a>: A vector algebra and calculus package</li>
	<li><a href="manual/contributed/bibasis.pdf">BIBASIS</a>: A Package for Calculating Boolean Involutive Bases</li>
	<li><a href="manual/contributed/boolean.pdf">BOOLEAN</a>: A package for boolean algebra</li>
	<li><a href="manual/contributed/cali.pdf">CALI</a>: A package for computational commutative algebra</li>
	<li><a href="manual/contributed/camal.pdf">CAMAL</a>: Calculations in celestial mechanics</li>
	<li><a href="manual/contributed/cantens.pdf">CANTENS</a>: A Package for Manipulations and Simplifications of Indexed Objects</li>
	<li><a href="manual/contributed/cde.pdf">CDE</a>: A package for integrability of PDEs</li>
	<li><a href="manual/contributed/cdiff.pdf">CDIFF</a>: A package for computations in geometry of Differential Equations</li>
	<li><a href="manual/contributed/cgb.pdf">CGB</a>: Computing Comprehensive Gr&ouml;bner Bases</li>
	<li><a href="manual/contributed/compact.pdf">COMPACT</a>: Package for compacting expressions</li>
	<li><a href="manual/contributed/crack.pdf">CRACK</a>: Solving overdetermined systems of PDEs or ODEs</li>
	<li><a href="manual/contributed/cvit.pdf">CVIT</a>: Fast calculation of Dirac gamma matrix traces</li>
	<li><a href="manual/contributed/defint.pdf">DEFINT</a>: A definite integration interface</li>
	<li><a href="manual/contributed/desir.pdf">DESIR</a>: Differential linear homogeneous equation solutions in the neighborhood of irregular and regular singular points</li>
	<li><a href="manual/contributed/dfpart.pdf">DFPART</a>: Derivatives of generic functions</li>
	<li><a href="manual/contributed/dummy.pdf">DUMMY</a>: Canonical form of expressions with dummy variables</li>
	<li><a href="manual/contributed/excalc.pdf">EXCALC</a>: A differential geometry package</li>
	<li><a href="manual/contributed/fide.pdf">FIDE</a>: Finite difference method for partial differential equations</li>
	<li><a href="manual/contributed/fps.pdf">FPS</a>: Automatic calculation of formal power series</li>
	<li><a href="manual/contributed/gcref.pdf">GCREF</a>: A Graph Cross Referencer</li>
	<li><a href="manual/contributed/gentran.pdf">GENTRAN</a>: A code generation package</li>
	<li><a href="manual/contributed/gnuplot.pdf">GNUPLOT</a>: Display of functions and surfaces</li>
	<li><a href="manual/contributed/groebner.pdf">GROEBNER</a>: A Gr&ouml;bner basis package</li>
	<li><a href="manual/contributed/guardian.pdf">GUARDIAN</a>: Guarded Expressions in Practice</li>
	<li><a href="manual/contributed/ideals.pdf">IDEALS</a>: Arithmetic for polynomial ideals</li>
	<li><a href="manual/contributed/ineq.pdf">INEQ</a>: Support for solving inequalities</li>
	<li><a href="manual/contributed/invbase.pdf">INVBASE</a>: A package for computing involutive bases</li>
	<li><a href="manual/contributed/lalr.pdf">LALR</a>: A parser generator</li>
	<li><a href="manual/contributed/laplace.pdf">LAPLACE</a>: Laplace transforms</li>
	<li><a href="manual/contributed/lie.pdf">LIE</a>: Functions for the classification of real <em>n</em>-dimensional Lie algebras</li>
	<li><a href="manual/contributed/limits.pdf">LIMITS</a>: A package for finding limits</li>
	<li><a href="manual/contributed/linalg.pdf">LINALG</a>: Linear algebra package</li>
	<li><a href="manual/contributed/listvecops.pdf">LISTVECOPS</a>: Vector operations on lists</li>
	<li><a href="manual/contributed/lpdo.pdf">LPDO</a>: Linear Partial Differential Operators</li>
	<li><a href="manual/contributed/modsr.pdf">MODSR</a>: Modular solve and roots</li>
	<li><a href="manual/contributed/ncpoly.pdf">NCPOLY</a>: Non-commutative polynomial ideals</li>
	<li><a href="manual/contributed/normform.pdf">NORMFORM</a>: Computation of matrix normal forms</li>
	<li><a href="manual/contributed/numeric.pdf">NUMERIC</a>: Solving numerical problems</li>
	<li><a href="manual/contributed/odesolve.pdf">ODESOLVE</a>: Ordinary differential equations solver</li>
	<li><a href="manual/contributed/orthovec.pdf">ORTHOVEC</a>: Manipulation of scalars and vectors</li>
	<li><a href="manual/contributed/physop.pdf">PHYSOP</a>: Operator calculus in quantum theory</li>
	<li><a href="manual/contributed/pm.pdf">PM</a>: A REDUCE pattern matcher</li>
	<li><a href="manual/contributed/polydiv.pdf">POLYDIV</a>: Enhanced Polynomial Division</li>
	<li><a href="manual/contributed/qsum.pdf">QSUM</a>: Indefinite and Definite Summation of <em>q</em>-hypergeometric Terms</li>
	<li><a href="manual/contributed/randpoly.pdf">RANDPOLY</a>: A random polynomial generator</li>
	<li><a href="manual/contributed/rataprx.pdf">RATAPRX</a>: Rational Approximations Package for REDUCE</li>
	<li><a href="manual/contributed/reacteqn.pdf">REACTEQN</a>: Support for chemical reaction equation systems</li>
	<li><a href="manual/contributed/redlog.pdf">REDLOG</a>: Extend REDUCE to a computer logic system</li>
	<li><a href="manual/contributed/reset.pdf">RESET</a>: Code to reset REDUCE to its initial state</li>
	<li><a href="manual/contributed/residue.pdf">RESIDUE</a>: A residue package</li>
	<li><a href="manual/contributed/rlfi.pdf">RLFI</a>: REDUCE <span class="latex">L<sup>a</sup>T<sub>e</sub>X</span> formula interface</li>
	<li><a href="manual/contributed/roots.pdf">ROOTS</a>: A REDUCE root finding package</li>
	<li><a href="manual/contributed/rsolve.pdf">RSOLVE</a>: Rational/integer polynomial solvers</li>
	<li><a href="manual/contributed/rtrace.pdf">RTRACE</a>: Tracing in REDUCE</li>
	<li><a href="manual/contributed/scope.pdf">SCOPE</a>: REDUCE source code optimization package</li>
	<li><a href="manual/contributed/sets.pdf">SETS</a>: A basic set theory package</li>
	<li><a href="manual/contributed/sparse.pdf">SPARSE</a>: Sparse Matrix Calculations</li>
	<li><a href="manual/contributed/spde.pdf">SPDE</a>: Finding symmetry groups of PDEs</li>
	<li><a href="manual/contributed/specfn.pdf">SPECFN</a>: Package for special functions</li>
	<li><a href="manual/contributed/specfn2.pdf">SPECFN2</a>: Package for special special functions</li>
	<li><a href="manual/contributed/sstools.pdf">SSTOOLS</a>: Computations with supersymmetric algebraic and differential expressions</li>
	<li><a href="manual/contributed/sum.pdf">SUM</a>: A package for series summation</li>
	<li><a href="manual/contributed/symmetry.pdf">SYMMETRY</a>: Operations on symmetric matrices</li>
	<li><a href="manual/contributed/taylor.pdf">TAYLOR</a>: Manipulation of Taylor series</li>
	<li><a href="manual/contributed/tps.pdf">TPS</a>: A truncated power series package</li>
	<li><a href="manual/contributed/tri.pdf">TRI</a>: <span class="tex">T<sub>e</sub>X</span> REDUCE interface</li>
	<li><a href="manual/contributed/trigsimp.pdf">TRIGSIMP</a>: Simplification and factorization of trigonometric and hyperbolic functions</li>
	<li><a href="manual/contributed/turtle.pdf">TURTLE</a>: Turtle Graphics Interface for REDUCE</li>
	<li><a href="manual/contributed/wu.pdf">WU</a>: Wu algorithm for polynomial systems</li>
	<li><a href="manual/contributed/xcolor.pdf">XCOLOR</a>: Color factor in some field theories</li>
	<li><a href="manual/contributed/xideal.pdf">XIDEAL</a>: Gr&ouml;bner Bases for exterior algebra</li>
	<li><a href="manual/contributed/zeilberg.pdf">ZEILBERG</a>: Indefinite and definite summation</li>
	<li><a href="manual/contributed/ztrans.pdf">ZTRANS</a>: <em>Z</em>-transform package</li>
</ul>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
