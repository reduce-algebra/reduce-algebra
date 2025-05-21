<?php
$page_title = 'Additional Documentation for REDUCE Packages';
$header_title = 'Additional Documentation';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>

<p>
   For various reasons, not all REDUCE packages are fully documented in the
   main REDUCE manual &ndash; usually because the documentation is not available,
   not available in a convenient source format, or too big.
   Documentation is available here as PDF files for the following packages:
</p>
<ul>
   <li><a href="atensor.pdf">ATENSOR: A REDUCE Program for Tensor Simplification</a></li>
   <!-- <li><a href="crack.pdf">CRACK: Solving Overdetermined Systems of PDEs or ODEs</a>
      <ul>
         <li><a href="conlaw.pdf">CONLAW: Find Conservation Laws for Differential Equations</a></li>
         <li><a href="v3tools.pdf">V3TOOLS: Computations with Polynomials of Products of 3-Vectors</a></li>
      </ul>
   </li> -->
   <li><a href="gentran.pdf">GENTRAN: A Code Generation Package</a></li>
   <!-- <li><a href="mathml.pdf">MATHML: REDUCE-MathML Interface</a></li>
   <li><a href="mathmlom_user.pdf">MATHMLOM: REDUCE OpenMath/MathML Interface</a></li> -->
   <li><a href="scope.pdf">SCOPE: REDUCE Source Code Optimization Package</a></li>
   <!-- <li><a href="susy2.pdf">SUSY2: Supersymmetric Functions and Algebra of Supersymmetric Operators</a></li> -->
   <li><a href="tri.pdf">TRI: TeX REDUCE Interface</a></li>
</ul>
<p>
   These documents are mostly quite old and have not all been fully updated for the current version of REDUCE.
   Any recent date appearing in them is probably the date when the documentation was formatted,
   not the date when it was written or fully updated.
   Despite what these documents may imply, the packages should all be pre-compiled
   and only need loading in currently distributed versions of REDUCE.
   Any references to the REDUCE commands <code>load</code> or <code>load!-package</code>
   should probably be interpreted as <code>load_package</code>.
</p>

</div><!-- opened in begin-body.php -->

<?php
include '../include/footer.php';
?>

</body>

</html>