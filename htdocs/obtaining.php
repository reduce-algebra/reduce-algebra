<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>Obtaining REDUCE</title>
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
</head>
<body>
	<header>Obtaining REDUCE</header>
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
					<p>The REDUCE computer algebra system is released free-of-charge under a modified BSD <a href="license.php">license</a>. It can be obtained in various versions from <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow"><img alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>. Please see these <a href="downloading.php">brief general installation instructions</a> and these <a href="windows.php">installation instructions for Microsoft Windows users</a>.</p>
					<p>REDUCE is based on a dialect of Lisp called <i><a href="lisp-docs/sl.pdf">Standard Lisp</a></i>, and the differences between versions are the result of different implementations of this Lisp; in each case the source code for REDUCE itself remains the same. The available versions of REDUCE are based on two different Lisps, namely:</p>
					<dl>
						<dt><strong>Portable Standard Lisp (PSL)</strong></dt>
						<dd>This is currently the Lisp used most widely for running REDUCE. It evolved from the original Standard Lisp definition, but now contains many more facilities. It is quite efficient in its use of both space and time, and has been optimized for algebraic computation. All PSL versions of REDUCE are distributed with sufficient PSL support to run on the given computing system. PSL is supported on many architectures and is an ideal system for those wanting to run REDUCE as a standalone system. The principal developer of PSL before it became Open Source was the Konrad Zuse Center, Berlin (<a href="http://www.zib.de/">ZIB</a>).</dd>
						<dt><strong>Codemist Standard Lisp (CSL)</strong></dt>
						<dd>This is a Lisp system written completely in ANSI C, which makes it very easy to port to a new machine. Like PSL, it is a faithful implementation of Standard Lisp and has been optimized for running REDUCE. It requires a very small memory partition for its Lisp support. Furthermore, most of the REDUCE facilities are supported as machine independent pseudocode, which is quite compact. In the worst case, the performance of this system is about a factor of two slower than PSL, though in many cases it matches PSL performance. However, the memory use is smaller. All CSL versions are distributed with sufficient CSL support to run on the given computing system. This is an ideal system for those wishing to embed algebraic calculations in a C-based programming environment. The developer of CSL before it became Open Source was <a href="http://www.codemist.co.uk/">Codemist Ltd</a>.</dd>
					</dl>
				</td>
			</tr>
		</tbody>
	</table>
</body>
</html>
