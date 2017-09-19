<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>REDUCE IDE</title>
	<link rel="icon" type="image/png" href="../images/icon.png" />
	<link rel="stylesheet" href="../StyleSheet.css" />
</head>
<body>
	<div id="content">
		<h1>REDUCE IDE</h1>
		<div id="middle">
			<nav>
				<script language="php">
					$root = '../'; include '../navigation.inc';
				</script>
			</nav>
			<div id="main">
				<p>REDUCE IDE is a package that provides an <u>I</u>ntegrated <u>D</u>evelopment <u>E</u>nvironment for the <a>REDUCE</a> computer algebra system within the <a href="http://www.gnu.org/">GNU</a> <a href="http://www.gnu.org/software/emacs/emacs.html">Emacs</a> editor. Its two major components are Emacs Lisp libraries that provide major modes for respectively editing REDUCE source code and running a <strong>command-line version</strong> of REDUCE in an Emacs window. Many of the facilities require that Emacs is running under a GUI such as <a href="http://windows.microsoft.com/">Microsoft Windows</a>, or the <a href="http://www.x.org/">X Window System</a> under some flavour of <a href="http://en.wikipedia.org/wiki/Unix">UNIX</a> or <a href="http://en.wikipedia.org/wiki/Linux">Linux</a>.</p>
				<p>A 30-page user's guide is available in <a href="reduce-ide.pdf">PDF</a> or <a href="reduce-ide/index.html">HTML</a>, and various other formats can be generated from the GNU texinfo source file. Full source code is available from the <code>/trunk/generic/emacs</code> directory in the REDUCE subversion repository via a <a>subversion client</a> or <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/">directly using a web browser</a>. A README file provides further technical details.</p>
				<p>REDUCE IDE requires a recent version of GNU Emacs. There is currently no explicit support for <a href="http://www.xemacs.org/">XEmacs</a>.</p>
				<p>This package is still under (sporadic) development, and feedback is welcome.</p>
				<p>The current version, 1.21, supports the GNU Emacs 24 package installer, which is the easiest way to install it. I have tested it with a GNU Emacs 24 pretest release and the latest pre-compiled release of REDUCE for 64-bit Windows, reduce-windows64-20110414, on Windows 7.</p>
				<address><a href="http://sourceforge.net/users/fjwright">Francis Wright</a>, February 2012</address>
			</div>
			<!--/#main-->
		</div>
		<!--/#middle-->
	</div>
	<!--/#content-->
</body>
</html>
