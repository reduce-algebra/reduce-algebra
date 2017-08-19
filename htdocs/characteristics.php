<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>REDUCE Characteristics</title>
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
</head>
<body>
	<header>
		Characteristics
	</header>
	<table class="layout">
		<tbody>
			<tr>
				<td>
					<nav>
						<script language="php">
						include 'navigation.inc';
						</script>
					</nav>
				</td>
				<td>
					<p>REDUCE is an interactive system for general algebraic computations of interest to mathematicians, scientists and engineers. It has been produced by a collaborative effort involving many <a href="about.php#contributors">contributors</a>. Its capabilities include:</p>
					<ul>
						<li>expansion and ordering of polynomials and rational functions;</li>
						<li>substitutions and pattern matching in a wide variety of forms;</li>
						<li>automatic and user controlled simplification of expressions;</li>
						<li>calculations with symbolic matrices;</li>
						<li>arbitrary precision integer and real arithmetic;</li>
						<li>facilities for defining new functions and extending program syntax;</li>
						<li>analytic differentiation and integration;</li>
						<li>factorization of polynomials;</li>
						<li>facilities for the solution of a variety of algebraic equations;</li>
						<li>facilities for the output of expressions in a variety of formats;</li>
						<li>facilities for generating optimized numerical programs from symbolic input;</li>
						<li>calculations with a wide variety of special functions;</li>
						<li>Dirac matrix calculations of interest to high energy physicists.</li>
					</ul>
					<p>It is often used as an algebraic calculator for problems that are possible to do by hand. However, REDUCE is <a>designed</a> to support calculations that are not feasible by hand. Many such calculations take a significant time to set up and can run for minutes, hours or even days on the most powerful computers.</p>
					<p>The REDUCE computer algebra system has been designed with the following characteristics in mind:</p>
					<ul>
						<li>Code stability. Various versions of REDUCE have been in use for over forty years. There has been a steady stream of improvements and refinements since then, with the source being subject to wide review by the user community. REDUCE has thus evolved into a powerful system whose critical components are highly reliable, stable and efficient.</li>
						<li>Wide user base. A particular algebra system is often chosen for a given calculation because of its widespread use in a particular application area, with existing packages and templates being used to speed up problem solving. As evidenced by approximately 1000 reports listed in the current <a href="bibliography.php">bibliography</a>, REDUCE has a large and dedicated user community working in just about every branch of computational science and engineering. A large number of special purpose packages are available in support of this, with many contributed by users.</li>
						<li>Full source code availability. From the beginning, it has been possible to obtain the complete REDUCE source code, including the &quot;kernel.&quot; Consequently, REDUCE is a valuable educational resource and a good foundation for experiments in the discipline of computer algebra. Many users do in fact effectively modify the source code for their own purposes.</li>
						<li>Flexible updating. One advantage of making all code accessible to the user is that it is relatively easy to incorporate patches to correct small problems or extend the applicability of existing code to new problem areas. World Wide Web servers allow users to get such updates and complete new packages as they become available, without having to wait for a formal system release.</li>
						<li>State-of-the-art algorithms. Another advantage of an &quot;open&quot; system is that there is a shared development effort involving both distributors and users. As a result, it is easier to keep the code up-to-date, with the best current algorithms being used soon after their development. At the present time, we believe REDUCE has superior code for solving nonlinear polynomial equations using <a href="manual/contributed/groebner.pdf">Groebner bases</a>, real and complex <a href="manual/contributed/roots.pdf">root finding</a> to any precision, <a href="manual/contributed/excalc.pdf">exterior calculus</a> calculations and <a href="manual/contributed/scope.pdf">optimized numerical code generation</a> among others. Its simplification strategy, using a combination of efficient polynomial manipulation and flexible pattern matching is focused on giving users as natural a result as possible without excessive programming.</li>
						<li>Algebraic focus. REDUCE aims at being part of a complete scientific environment rather than being the complete environment itself. As a result, users can take advantage of other state-of-the-art systems specializing in numerical and graphical calculations, rather than depend on just one system to provide everything. To this end, REDUCE provides facilities for writing results in a form compatible <a href="manual/contributed/gentran.pdf">with common numerical programming languages</a> (such as C or Fortran) or <a href="manual/contributed/rlfi.pdf">document processors</a> such as TeX.</li>
						<li>Portability. Careful design for portability means REDUCE is often available on new or uncommon machines soon after their release. This has led to significant user communities throughout the world. At the present time, REDUCE is readily available on essentially all computers.</li>
						<li>Uniformity. Even though REDUCE is supported with different Lisps on many different platforms, much attention has been paid to making all versions perform in the same manner regardless of implementation. As a result, users can have confidence that their calculations will not behave differently if they move them to a different machine.</li>
					</ul>
				</td>
			</tr>
		</tbody>
	</table>
</body>
</html>
