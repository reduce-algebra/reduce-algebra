<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>Obtaining REDUCE</title>
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
	<style type="text/css">
		#main img.sflogo {
			float: none;
			margin: auto;
		}
	</style>
</head>
<body>
	<div id="content">
		<header>Obtaining REDUCE</header>
		<div id="middle">
			<nav>
				<script language="php">
						include 'navigation.inc';
				</script>
			</nav>
			<div id="main">
				<p>
					The REDUCE computer algebra system is released free-of-charge under a modified BSD <a href="license.php">license</a> and can be obtained in various versions from <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
						<img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>, as explained below.
				</p>
				<p>REDUCE is based on a dialect of Lisp called <i><a href="lisp-docs/sl.pdf">Standard Lisp</a></i>, and the differences between versions are the result of different implementations of this Lisp; in each case the source code for REDUCE itself remains the same. The available versions of REDUCE are based on two different Lisps, namely:</p>
				<dl>
					<dt><strong>Portable Standard Lisp (PSL)</strong></dt>
					<dd>PSL was the original implementation of Standard Lisp, but now contains many more facilities. It is quite efficient in its use of both space and time, and has been optimized for algebraic computation. All PSL versions of REDUCE are distributed with sufficient PSL support to run on the given computing system. PSL is supported on many architectures and is an ideal system for those wanting to run REDUCE as a stand-alone system. The principal developer of PSL before it became Open Source was the Konrad Zuse Center, Berlin (<a href="http://www.zib.de/">ZIB</a>).</dd>
					<dt><strong>Codemist Standard Lisp (CSL)</strong></dt>
					<dd>CSL is a newer Lisp system that continues to evolve and is now written completely in C++, which makes it very easy to port to a new machine. Like PSL, it is a faithful implementation of Standard Lisp and has been optimized for running REDUCE. It requires a very small memory partition for its Lisp support. Furthermore, most of the REDUCE facilities are supported as machine independent pseudocode, which is quite compact. In the worst case, the performance of this system is about a factor of two slower than PSL, though in many cases it matches PSL performance. However, the memory use is smaller. All CSL versions are distributed with sufficient CSL support to run on the given computing system. This is also an ideal system for those wishing to embed algebraic calculations in a C or C++ programming environment. The developer of CSL before it became Open Source was <a href="http://www.codemist.co.uk/">Codemist Ltd</a>.</dd>
				</dl>
				<h2>REDUCE versions and releases</h2>
				<p>The commercial releases of REDUCE had version numbers, the last of which was version 3.8 released in 2004. The Open Source releases of REDUCE available since 2008 do not have version numbers, but are identified by release dates. A REDUCE release includes all necessary binary files for a specific platform. Releases are currently provided irregularly every few months for Microsoft Windows, Apple MacOS and GNU/Linux (all at the same time). Every so often there may also be a release for a more esoteric architecture, such as the Raspberry Pi!</p>
				<p>A release is essentially a set of files built from a snapshot of the source code, which evolves on a daily (if not hourly) basis as the developers commit updates. The source code is managed using Subversion, which increments the revision number (of the whole code base) with each commit, and this now serves as a version number. Since the whole code base is now publicly available, formal releases are no longer very significant.</p>
				<h2>The easy way to obtain REDUCE</h2>
				<p>
					This is to download and install a pre-packaged REDUCE release that contains all necessary binary files as well as documentation (and the main REDUCE source code). We currently release REDUCE in this way primarily for Microsoft Windows, Apple MacOS and GNU/Linux. This approach should work well if you use a supported platform and don't need the very latest version. Simply click on the <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
						<img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a> logo to visit the project page and then, towards the top of the page, you should see a green box containing the word Download with a filename below it. SourceForge uses heuristics to pick automatically a recent distribution file with an appropriate extension for your platform (although it might get it wrong). You should see a filename of the form:
				</p>
				<ul>
					<li>on Microsoft Windows: Reduce-Setup_<em>yyyy-mm-dd</em>.exe</li>
					<li>on Apple MacOS: Reduce-snapshot_<em>yyyy-mm-dd</em>.dmg</li>
				</ul>
				<p>
					where <em>yyyy-mm-dd</em> represents the release date in numerical format.
				</p>
				<p>
					Download the recommended file to your computer and install it in the normal way: on Windows, double-click the installer file to execute it; on MacOS, double-click the installer file to open it and drag the REDUCE icon to your Applications folder. This process will install both the PSL and the CSL versions of REDUCE, which can be run like any other application; for example, on Windows the Start menu will contain a folder called Reduce that contains applications called CSL Reduce and PSL Reduce, which can be run by clicking on them.
				</p>
				<p>
					Below the green box is a link labelled Browse All Files, and clicking on either that link or the Files link on the toolbar takes you to a page offering recent REDUCE releases for all supported platforms. Each release is a directory, which normally contains the Windows and MacOS distribution files as described above plus a generic source code bundle in the form of a <a href="https://en.wikipedia.org/wiki/Tar_(computing)">compressed tar archive</a> and sets of distribution files for GNU/Linux in the form of <a>compressed tar archives</a>, <a href="https://en.wikipedia.org/wiki/Rpm_(software)">.rpm files</a> and <a href="https://en.wikipedia.org/wiki/Deb_(file_format)">.deb files</a>. These sets of files include separate distribution files for CSL and PSL, for Intel and AMD processors and for 32- and 64-bit architectures. You need to choose and install the right files for your computer.
				</p>
				<p>
					On a platform for which we do not currently provide REDUCE releases, such as Android, the green box will instead be blue and labelled Browse Code. Clicking on it takes you to the Subversion code repository (where you may or may not find source code for a particular platform).
				</p>
				<p>
					Note that we do not provide any automatic update facility; to update REDUCE just install it again. This is probably a good idea every year or so, or if you have encountered errors (and especially if you believe they have been fixed).
				</p>
				<h2>The hard way to obtain REDUCE</h2>
				<p>If the easy way doesn't work for you for some reason then you have the option of building REDUCE yourself from the source code. For guidance on doing this, please see Chapter 2 of <a href="lisp-docs/insidereduce.pdf">Inside Reduce</a>.</p>
				<p>There are also <a href="downloading.php">brief general installation instructions</a> for all platforms and <a href="windows.php">installation instructions for Microsoft Windows users</a>, but these documents are older and now somewhat out of date.</p>
			</div>
			<!--/#main-->
		</div>
		<!--/#middle-->
	</div>
	<!--/#content-->
</body>
</html>
