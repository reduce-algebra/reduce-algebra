<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>Obtaining REDUCE from SourceForge</title>
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
</head>
<body>
	<div id="content">
		<h1>Obtaining REDUCE from SourceForge</h1>
		<div id="middle">
			<nav>
				<script language="php">
						include 'navigation.inc';
				</script>
			</nav>
			<div id="main">
				<p>The SourceForge repository contains several versions of REDUCE, including the complete sources for both REDUCE and the underlying CSL Lisp system. The best place to start downloading is the REDUCE <a href="http://www.sourceforge.net/projects/reduce-algebra/">project page</a> at SourceForge.</p>
				<h2>Compiled Versions</h2>
				<p>There are several compiled versions available for download. To obtain one of these, click on the white Download link at the right of the page near the top, and then click on reduce-algebra under &quot;Package.&quot; You will then see several instances of the available binaries. Please use the latest version if that meets your needs. Otherwise, click on the other links, and a variety of versions will be displayed. Hopefully one of these will meet your needs. The relevant files are there in zip format. To use them, create a directory where you wish to store them (e.g., &quot;reduce&quot;), connect to this directory, and then unzip the contents of the downloaded file. Among the files produced should be a REDUCE executable.</p>
				<h2>Complete Sources and Supporting Files</h2>
				<p>If none of the above versions meets your needs, you will need to download the complete sources. For this you need the &quot;subversion&quot; program svn. If you don't have this, you will need to obtain it from somewhere. Once that is available, you can say</p>
				<p><code>svn co https://svn.code.sf.net/p/reduce-algebra/code/trunk/</code></p>
				<p>This will download all relevant files to a sub-directory &quot;reduce-algebra.&quot;</p>
				<p>To create the necessary executables, cd to the reduce-algebra/trunk directory, and then type:</p>
				<p><code>./configure --with-csl</code> or <code>./configure --with-psl</code></p>
				<p>depending upon which underlying Lisp you prefer to use.</p>
				<p>Now type</p>
				<p><code>make</code></p>
				<p>and be prepared to wait a long time for the compilation to complete. After this is done, a suitable executable (redcsl or redpsl, with a &quot;bat&quot; extension for Windows) will be found in the &quot;bin&quot; subdirectory.</p>
				<p>You can review the files in the subversion archive by going to &quot;Public&quot; from the REDUCE project page, then &quot;Browse SVN.&quot; Further details about SVN at Sourceforge may be found under &quot;SVN repository.&quot; One thing to bear in mind is that once you have downloaded the file set, the command</p>
				<p><code>svn update</code></p>
				<p>will download only those files that have been changed since your last call to that command.</p>
				<h2>Known Problems</h2>
				<p>With the CSL version, there are some glitches with the mathematical prettyprinting of expressions. To turn this feature off, say</p>
				<p><code>off fancy;</code></p>
				<p>in REDUCE. In addition, if you are having problems with the window-based version, or prefer a command-line version, you can use the program in command-line mode by typing</p>
				<p><code>reduce -w</code></p>
				<p>to load the program.</p>
				<h2>Further Developments</h2>
				<p>Once you have installed the program, please review from time to time the reduce-algebra-developers mailing list under Public/Mailing Lists at SourceForge. That way, you can learn of further developments as they occur.</p>
			</div>
			<!--/#main-->
		</div>
		<!--/#middle-->
	</div>
	<!--/#content-->
</body>
</html>
