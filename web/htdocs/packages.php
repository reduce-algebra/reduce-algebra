<?php  // -*-mhtml-*-

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
<p>
  REDUCE distributions include a wide variety
  of <a href="documentation.php#contributed">specialized
  packages</a>. The external packages listed below use REDUCE but are
  not included in the REDUCE repository or in REDUCE distributions.
</p>
<h2>Packages available separately for download</h2>
<dl>
  <dt>
    <a href="https://www.latrobe.edu.au/mathematics-and-statistics/research/geometric-and-algebraic-techniques-for-differential-equations/dimsym">Dimsym</a>
    &ndash; symmetry determination and linear differential equation
    package
  </dt>
  <dd>
    Authors: James Sherring, Geoff Prince and Michael Jerie
  </dd>
  <dt>
    <a href="grg32/grg32.php">GRG 3.2</a> &ndash; differential
    geometry, gravitation and field theory
  </dt>
  <dd>
    Author: Vadim V. Zhytnikov
  </dd>
  <dt>
    <a href="https://www.utsc.utoronto.ca/~harper/redten.html">REDTEN</a>
    &ndash; tensor and tensor-like objects and manipulation functions
    for work in general relativity
  </dt>
  <dd>
    Authors: <a href="mailto:harper@utsc.utoronto.ca">John Harper</a>
    and <a href="mailto:dyer@utsc.utoronto.ca">Charles Dyer</a>
  </dd>
</dl>
<h2>Dynamical Systems Packages</h2>
<dl>
  <!-- <dt><a href="http://www.maths.adelaide.edu.au/anthony.roberts/holistic1.php">Holistic discretisation of a dynamical Partial Differential Equation</a><br /> -->
  <!--   <a href="http://www.maths.adelaide.edu.au/anthony.roberts/holistic3.php">Holistic discretisation of three coupled dynamical Partial Differential Equations</a><br /> -->
  <!--   <a href="http://www.maths.adelaide.edu.au/anthony.roberts/sdenf.php">Normal form of stochastic or deterministic multiscale differential equations</a><br /> -->
  <!--   <a href="http://www.maths.adelaide.edu.au/anthony.roberts/sdesm.php">Slow manifold of stochastic or deterministic multiscale differential equations</a><br /> -->
  <!--   <a href="http://www.maths.adelaide.edu.au/anthony.roberts/gencm.php">Construct centre manifolds of ordinary or delay differential equations (autonomous)</a></dt> -->

  <!-- The links above seem to be broken and the links below don't
  seem to run the demos, although they provide links to some
  downloadable software! -->

  <dt>
    <a href="https://profajroberts.github.io/holistic1.html">Holistic
    discretisation of a dynamical Partial Differential
    Equation</a><br />
    <a href="https://profajroberts.github.io/holistic3.html">Holistic
    discretisation of three coupled dynamical Partial Differential
    Equations</a><br />
    <a href="https://profajroberts.github.io/sdenf.html">Normal form
    of stochastic or deterministic multiscale differential
    equations</a><br />
    <a href="https://profajroberts.github.io/sdesm.html">Slow manifold
    of stochastic or deterministic multiscale differential
    equations</a><br />
    <a href="https://profajroberts.github.io/gencm.html">Construct
    invariant manifolds of ordinary or delay differential equations
    (autonomous)</a>
  </dt>
  <dd>
    Author: <a href="https://profajroberts.github.io/">A.&nbsp;J. Roberts</a>
  </dd>
</dl>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
