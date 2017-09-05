<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>REDUCE Features</title>
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
</head>
<body>
	<div id="content">
		<header>Features</header>
		<div id="middle">
			<nav>
				<script language="php">
					include 'navigation.inc';
				</script>
			</nav>
			<div id="main">
				<p>
					REDUCE is a system for general algebraic computations of interest to mathematicians, scientists and engineers, which is normally used interactively. It has been produced by a collaborative effort involving many <a href="about.php#contributors">contributors</a>.
				</p>
				<h2>Basic features</h2>
				<p>
					The basic features of REDUCE, which might be useful to students and teachers from high school / secondary school up to university level, include:
				</p>
				<ul>
					<li>exact arithmetic using integers and fractions;</li>
					<li>arbitrary precision numerical approximation;</li>
					<li>polynomial and rational function algebra;</li>
					<li>exponential, logarithmic, trigonometric and hyperbolic functions;</li>
					<li>differentiation and	integration of functions of one	or more variables;</li>
					<li>factorization and expansion of polynomials and rational functions;</li>
					<li>solution of single and simultaneous equations;</li>
					<li>automatic and user controlled simplification of expressions;</li>
					<li>plotting graphs of functions in 2 and 3 dimensions;</li>
					<li>output of results in a variety of formats.</li>
				</ul>
				<h2>Advanced features</h2>
				<p>
					More advanced features, which allow calculations at university level and beyond, include:
				</p>
				<ul>
					<li>substitutions and pattern matching in a wide variety of expressions;</li>
					<li>calculations involving matrices with numerical and symbolic elements;</li>
					<li>general matrix and non-commutative algebra;</li>
					<li>solution of ordinary differential equations;</li>
					<li>powerful intuitive user-level programming language;</li>
					<li>facilities for generating optimized numerical programs from symbolic input;</li>
					<li>calculations with a wide variety of special (higher transcendental) functions;</li>
					<li>quantifier elimination and decision for interpreted first-order logic;</li>
					<li>Dirac matrix calculations of interest to high energy physicists.</li>
				</ul>
				<h2>Interactive and batch-mode use</h2>
				<p>
					REDUCE is often used as an interactive algebraic calculator for problems that are possible to do by hand. However, it is <a>designed</a> to support calculations that are not feasible by hand. Many such calculations take a significant time to set up and can run for minutes, hours or even days on the most powerful computers. REDUCE supports non-interactive batch-mode use for large computations.
				</p>
				<h2>General design characteristics</h2>
				<p>
					The REDUCE computer algebra system has been designed with the following general characteristics in mind:
				</p>
				<dl>
					<dt>Code stability</dt>
					<dd>Various versions of REDUCE have been in use since the late 1960s. There has been a steady stream of improvements and refinements since then, with the source being subject to wide review by the user community. REDUCE has thus evolved into a powerful system whose critical components are highly reliable, stable and efficient.</dd>
					<dt>Full source code availability</dt>
					<dd>From the beginning, it has been possible to obtain the complete REDUCE source code, including the &quot;kernel.&quot; Consequently, REDUCE is a valuable educational resource and a good foundation for experiments in the discipline of computer algebra. Many users do in fact effectively modify the source code for their own purposes.</dd>
					<dt>Flexible updating</dt>
					<dd>One advantage of making all code accessible to the user is that it is relatively easy to incorporate patches to correct small problems or extend the applicability of existing code to new problem areas. World Wide Web servers (currently SourceForge and its mirror sites) allow users to get such updates and completely new packages as they become available, without having to wait for a formal system release.</dd>
					<dt>Portability</dt>
					<dd>Careful design for portability means REDUCE is often available on new or uncommon machines soon after their release. This has led to significant user communities throughout the world. At the present time, REDUCE is readily available on essentially all computers.</dd>
					<dt>Uniformity</dt>
					<dd>Even though REDUCE is supported with different Lisps on many different platforms, much attention has been paid to making all versions perform in the same manner regardless of implementation. As a result, users can have confidence that their calculations will not behave differently if they move them to a different machine.</dd>
					<dt>Algebraic focus</dt>
					<dd>REDUCE aims at being part of a complete scientific environment rather than being the complete environment itself. As a result, users can take advantage of other state-of-the-art systems specializing in numerical and graphical calculations, rather than depend on just one system to provide everything. To this end, REDUCE provides facilities for writing results in a form compatible <a href="manual/contributed/gentran.pdf">with common numerical programming languages</a> (such as C or Fortran) or <a href="manual/contributed/rlfi.pdf">document processors</a> such as <span class="latex">L<sup>a</sup>T<sub>e</sub>X</span>.</dd>
					<dt>State-of-the-art algorithms</dt>
					<dd>Another advantage of an &quot;open&quot; system is that there is a shared development effort involving both distributors and users. As a result, it is easier to keep the code up-to-date, with the best current algorithms being used soon after their development. At the present time, we believe REDUCE has superior code for solving non-linear polynomial equations using <a href="manual/contributed/groebner.pdf">Gr&ouml;bner bases</a>, real and complex <a href="manual/contributed/roots.pdf">root finding</a> to any precision, <a href="manual/contributed/excalc.pdf">exterior calculus</a> calculations and <a href="manual/contributed/scope.pdf">optimized numerical code generation</a> among others. Its simplification strategy, using a combination of efficient polynomial manipulation and flexible pattern matching is focused on giving users as natural a result as possible without excessive programming.</dd>
				</dl>
				<h2>Specialist packages</h2>
				<p>
					REDUCE has a wide user base, which has led to a wide range of packages for specific purposes. A particular algebra system is often chosen for a given calculation because of its widespread use in a particular application area, with existing packages and templates being used to speed up problem solving. As evidenced by approximately 1000 reports listed in the current <a href="bibliography.php">bibliography</a>, REDUCE has a large and dedicated user community working in just about every branch of computational science and engineering. A large number of special purpose packages are available in support of this, with many contributed by users.
				</p>
			</div>
			<!--/#main-->
		</div>
		<!--/#middle-->
	</div>
	<!--/#content-->
</body>
</html>
