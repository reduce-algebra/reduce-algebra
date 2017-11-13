<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>REDUCE Support</title>
	<meta name="Description" content="Support available for REDUCE" />
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
	<style type="text/css">
		dt {
			margin-top: 1ex;
			margin-bottom: 0.5ex;
		}
	</style>
</head>
<body>
	<div id="content">
		<header>Support</header>
		<div id="middle">
			<nav>
				<script language="php">
					include 'navigation.inc';
				</script>
			</nav>
			<div id="main">
				<dl>
					<dt>Why are there two versions of REDUCE?</dt>
					<dd>REDUCE runs on <a href="documentation.php">Standard Lisp</a> and there are two versions of Standard Lisp that were developed primarily to support REDUCE, namely <a href="versions.php">PSL and CSL</a> (in that order chronologically). We only release distributions of REDUCE based on these two Lisps, although REDUCE can be implemented on other versions of Standard Lisp (and there is some experimental code to do this in the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/">repository</a>).</dd>
					<dt>What user interfaces does REDUCE provide?</dt>
					<dd>PSL REDUCE itself provides only a command-line interface (CLI). CSL REDUCE provides a graphical user interface (GUI) by default, but it provides a command-line interface if started with the <code>--nogui</code> option. <a href="https://www.gnu.org/software/emacs/emacs.html">GNU Emacs</a> provides a GUI for PSL and CSL REDUCE via the <a href="reduce-ide/">REDUCE IDE</a> package and <a href="http://www.texmacs.org/">GNU TeXmacs</a> provides a GUI for PSL and CSL REDUCE via a <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/texmacs/">plugin for running REDUCE</a>. There is code in the repository for two other packages, <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/redfront">redfront</a> and <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/psl/xr/">XR</a>, that provide GUIs for PSL, but neither is currently distributed as a pre-built binary and XR is somewhat out of date.</dd>
					<dt>What start-up options does REDUCE provide?</dt>
					<dd>For CSL REDUCE, running <code>redcsl --nogui --help</code> at a command prompt (assuming <code>redcsl</code> is on your search path &ndash; see <a href="obtaining.php">Obtaining REDUCE</a>) lists the start-up options.</dd>
				</dl>
				<p>Support for <a href="obtaining.php">obtaining and installing REDUCE</a> and for <a href="documentation.php">running REDUCE</a> is available from this web site. Here are some other useful support links.</p>
				<dl>
					<dt><a href="http://sourceforge.net/projects/reduce-algebra/">Project home page</a></dt>
					<dd>the home page for the REDUCE distributions</dd>
					<dt><a href="http://sourceforge.net/projects/reduce-algebra/files/">Download a pre-packaged distribution</a></dt>
					<dd>There are distributions for different platforms. Click on a release name in the <strong>File/Folder Name</strong> column to display the archive files available. Click on your chosen file to download it.</dd>
					<dt><a href="https://sourceforge.net/p/reduce-algebra/code/">Browse the code repository</a></dt>
					<dd>We use Subversion (SVN). For instructions and other options, go to the <a href="http://sourceforge.net/projects/reduce-algebra/">Project</a> page and click on the <strong>Code</strong> button.</dd>
					<dt><a href="https://lists.sourceforge.net/lists/listinfo/reduce-algebra-developers">Join the mailing list</a></dt>
					<dd>currently the main source of support for REDUCE</dd>
					<dt><a href="https://sourceforge.net/p/reduce-algebra/bugs/">Bug tracker</a></dt>
					<dd>If you think you have found a bug in REDUCE or any of its support or related systems then please report it here.</dd>
					<dt><a href="http://sourceforge.net/p/reduce-algebra/discussion/">Discussion fora</a></dt>
					<dd>a list of the current discussion fora</dd>
					<dt><a href="http://www.redlog.eu/">Redlog home page</a></dt>
					<dd>REDLOG provides an extension of REDUCE to a <em>computer logic system</em>. It is included in the SourceForge distribution.</dd>
					<dt><a href="http://redlog.eu/reduce-wiki">REDUCE Wiki</a></dt>
					<dd>REDUCE support hosted on the REDLOG web site</dd>
				</dl>
			</div>
			<!--/#main-->
		</div>
		<!--/#middle-->
		<script language="php">
			include 'footer.inc';
		</script>
	</div>
	<!--/#content-->
</body>
</html>
