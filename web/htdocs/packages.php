<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'External REDUCE Packages');

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
<style type="text/css">
 dd {
	 margin-bottom: 0.5em;
 }
</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'External Packages');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>REDUCE distributions include a wide variety of specialized packages as <a href="documentation.php">described on the documentation page</a>. The external packages listed below use REDUCE but are not included in REDUCE distributions.</p>
<h2>Packages available separately for download</h2>
<dl>
	<dt><a href="http://www.latrobe.edu.au/mathematics-and-statistics/research/geometric-and-algebraic-techniques-for-differential-equations/dimsym">Dimsym</a> &ndash; Symmetry Determination and Linear Differential Equation Package</dt>
	<dd>Authors: James Sherring, Geoff Prince and Michael Jerie</dd>
	<dt><a href="grg32/grg32.php">GRG 3.2</a> &ndash; for making calculation in differential geometry and field theory as simple and natural as possible</dt>
	<dd>Author: Vadim V. Zhytnikov</dd>
	<dt><a href="http://www.utsc.utoronto.ca/~harper/redten.html">REDTEN</a> &ndash; for tensor manipulation</dt>
	<dd>Authors: <a href="mailto:harper@utsc.utoronto.ca">John Harper</a> and <a href="mailto:dyer@utsc.utoronto.ca">Charles Dyer</a></dd>
</dl>
<h2>Packages that can only be used online and/or via email</h2>
<dl>
	<dt><a href="http://convode.physique.fundp.ac.be/convode/Main.py?m=0&amp;r=0&amp;i=0&amp;lg=en">CONVODE</a> &ndash; for solving various systems of differential equations</dt>
	<dd>Author: <a href="mailto:alain.moussiaux@unamur.be">Alain Moussiaux</a></dd>
	<dt><a href="http://www.maths.adelaide.edu.au/anthony.roberts/holistic1.php">Holistic discretisation of a dynamical Partial Differential Equation</a><br />
		<a href="http://www.maths.adelaide.edu.au/anthony.roberts/holistic3.php">Holistic discretisation of three coupled dynamical Partial Differential Equations</a><br />
		<a href="http://www.maths.adelaide.edu.au/anthony.roberts/sdenf.php">Normal form of stochastic or deterministic multiscale differential equations</a><br />
		<a href="http://www.maths.adelaide.edu.au/anthony.roberts/sdesm.php">Slow manifold of stochastic or deterministic multiscale differential equations</a><br />
		<a href="http://www.maths.adelaide.edu.au/anthony.roberts/gencm.php">Construct centre manifolds of ordinary or delay differential equations (autonomous)</a></dt>
	<dd>Author: <a>A.&nbsp;J. Roberts</a></dd>
</dl>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
