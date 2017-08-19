<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<!-- Index page for http://reduce-algebra.sourceforge.net/, http://reduce-algebra.com, etc. -->
<head>
	<meta charset="utf-8" />
	<title>REDUCE Computer Algebra System</title>
	<meta name="Description" content="The REDUCE Computer Algebra System" />
	<meta name="Keywords" content="Open Source, Software, Development, Developers, Projects, Downloads, SF.net, SourceForge, BSD License, Science/Research, OS Portable (Source code to work with many OS platforms), Mathematics, Lisp, REDUCE, reduce-algebra, computer algebra system, CAS" />
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
	<style type="text/css">
		#main img {
			float: right;
			margin-left: 1em;
			margin-top: 1em;
		}
	</style>
</head>
<body>
	<header>REDUCE</header>
	<p>A portable general-purpose computer algebra system</p>
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
				<td id="main"><a href="images/reduce_screenshot_1.PNG">
					<img src="images/reduce_screenshot_thumbnail_1.PNG" width="266" height="297" alt="CSL REDUCE on Microsoft Windows"
						title="CSL REDUCE on Microsoft Windows - click to see the full size image" /></a>
					<p>REDUCE is a system for doing scalar, vector and matrix algebra by computer, which also supports arbitrary precision numerical approximation and interfaces to <a href="http://www.gnuplot.info/">gnuplot</a> to provide graphics. It can be used interactively for simple calculations (as illustrated in the screenshot) but also provides a full programming language, with a syntax similar to other modern programming languages.</p>
					<p>REDUCE has a long and distinguished place in the history of computer algebra systems (see the <a href="bibliography.php">bibliography</a>). Other systems that address some of the same issues but sometimes with rather different emphasis are <a href="http://www.axiom-developer.org/">Axiom</a>, Macsyma (<a href="http://maxima.sourceforge.net/">Maxima</a>), <a href="http://www.maplesoft.com/products/Maple/">Maple</a> and <a href="http://www.wolfram.com/mathematica/">Mathematica</a>.</p>
					<p>REDUCE (and its complete source code) is <a href="obtaining.php">available free of charge</a> for most common computing systems, in some cases in more than one version for the same machine. On-line versions of the <a href="documentation.php">manual and other support documents</a> and tutorials are also included with the distribution.</p>
					<p>REDUCE is implemented in Lisp (as are Axiom and Macsyma), but this is completely hidden from the casual user. REDUCE primarily runs on either <a href="obtaining.php">Portable Standard Lisp (PSL) or Codemist Standard Lisp (CSL)</a>, both of which are included in the distribution. PSL is long-established and compiles to machine code, whereas CSL is newer and compiles to byte code. Hence, PSL may be faster but CSL may be available on a wider range of platforms.</p>
				</td>
			</tr>
		</tbody>
	</table>
	<footer>
		<p>All information available through this web site is Copyright &copy; Anthony C. Hearn 2009&ndash;2017, all Rights Reserved.</p>
		<p>Please report broken links (both in-coming and out-going), other errors or suggestions for improvement to <a href="https://sourceforge.net/users/fjwright/">webmaster</a>.</p>
		<!--<p>
			<a href="https://sourceforge.net/">Project Web Hosted by
			<img src="http://sflogo.sourceforge.net/sflogo.php?group_id=248416&amp;type=3" alt="SourceForge.net" /></a>
		</p>-->
	</footer>
</body>
</html>
