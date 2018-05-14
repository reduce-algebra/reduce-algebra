<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'Obtaining REDUCE');

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
<style type="text/css">
 #main img.sflogo {
	 float: none;
	 margin: auto;
 }
</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'Obtaining REDUCE');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>
	The REDUCE computer algebra system is released free-of-charge under a modified BSD <a href="license.php">license</a> and can be obtained in <a href="versions.php">two main versions</a> from <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
	<img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>.
	There are also <a href="independent.php">independent distributions</a> available for some platforms not explicitly supported by the REDUCE developers.
	This page explains how to download, install and run REDUCE on the most widely-used platforms.
	
</p>
<h2>The easy way to obtain REDUCE</h2>
<p>
	This is to download and install a pre-packaged REDUCE distribution that contains all the necessary binary files as well as documentation (and the main REDUCE source code). We currently distribute REDUCE in this way primarily for Microsoft Windows, Apple MacOS and some versions of GNU/Linux. This approach should work well if you use a supported platform and don't need the very latest updates. Simply click on the <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
	<img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a> logo to visit the project page and then, towards the top of the page, you should see a large green button containing the word Download with a filename below it. SourceForge uses heuristics to pick a recent distribution file with an appropriate extension for your platform automatically (although it might get it wrong, especially for GNU/Linux).
</p>
<p>
	Note that we do not provide any automatic update facility; to update REDUCE just install it again. This is probably a good idea every year or so, or if you have encountered errors (and especially if you believe they have been fixed).
	
</p>
<h3>Using Microsoft Windows and Apple MacOS</h3>
<p>
	The <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
	<img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a> Download button should include a filename of the form:
	
</p>
<ul>
	<li><code>Reduce-Setup_<em>yyyy-mm-dd</em>.exe</code> on Microsoft Windows</li>
	<li><code>Reduce-snapshot_<em>yyyy-mm-dd</em>.dmg</code> on Apple MacOS</li>
</ul>
<p>
	where <em>yyyy-mm-dd</em> represents the release date in numerical format.
</p>
<p>
	Download the recommended file to your computer and install REDUCE in the normal way: on Windows, double-click on the installer file to execute it; on MacOS, double-click on the installer file to open it and then drag the REDUCE icon to your Applications folder. This process will install the CSL and/or PSL versions of REDUCE, which you can then run like any other application; for example, on Windows the Start menu will contain a folder called Reduce that contains applications called CSL Reduce and/or PSL Reduce, which you can run by clicking on them &ndash; <a href="#windetails">more detail is available below</a>.
</p>
<h3>Using GNU/Linux</h3>
<p>
	The <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
	<img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a> Download button should include a filename of the form:
</p>
<ul>
	<li><code>reduce-complete_<em>yyyy-mm-dd_arch</em>.deb</code> on Debian-based Linux (e.g. Ubuntu)</li>
	<li><code>reduce-complete_<em>yyyy-mm-dd.arch</em>.rpm</code> on Red Hat-based Linux (e.g. Fedora and openSUSE)</li>
</ul>
<p>
	where <em>yyyy-mm-dd</em> represents the release date in numerical format and <em>arch</em> represents the architecture, e.g. amd64 or x86_64 for 64-bit processors.
</p>
<p>
	Download the recommended file to your computer, open the Downloads folder and install REDUCE in the normal way, e.g. on Ubuntu, double-click on the installer file and then click on the Install button. This process will install both the CSL and PSL versions of REDUCE, which you can then run like any other application.
</p>
<p>
	If the above instructions do not work or you do not want to install both the CSL and PSL versions of REDUCE then you should ignore the default download file and proceed as follows. Below the green Download button is a link labelled Browse All Files and clicking on that link or the Files link on the toolbar takes you to a page offering recent REDUCE distributions for all supported platforms. Each distribution is a directory, which normally contains the Windows and MacOS distribution files as described above plus a generic source code bundle in the form of a <a href="https://en.wikipedia.org/wiki/Tar_(computing)">compressed tar file</a> and sets of distribution files for GNU/Linux in the form of <a>compressed tar files</a>, <a href="https://en.wikipedia.org/wiki/Rpm_(software)">.rpm files</a> and <a href="https://en.wikipedia.org/wiki/Deb_(file_format)">.deb files</a>.
	These sets of files include separate distributions for CSL and PSL, for Intel and AMD processors and for 32- and 64-bit architectures. You need to choose and install the right files for your computer, which will include a file with a name of the form <code>reduce-common&hellip;</code> plus the appropriate CSL and/or PSL distribution files for your architecture. (We also provide distributions that combine the common, CSL and PSL components into a single distribution file for each architecture that we support, as described above.)
</p>
<p>
	If you don't find a distribution here that you can use then please check the <a href="independent.php">independent distributions</a>.
</p>
<p>
	To run REDUCE on Linux, first open a Terminal window. Then executing <code>redpsl</code> will start PSL REDUCE with a CLI, whereas executing <code>redcsl</code> will start REDUCE with a GUI (and executing <code>redcsl --nogui</code> will start CSL REDUCE with a CLI). (The commands <code>redpsl</code> and <code>redcsl</code> are shell scripts installed in <code>/usr/bin</code>, which run binary files installed in <code>/usr/lib/reduce</code>.)
</p>
<h3>Using other platforms</h3>
<p>
	On a platform for which we do not currently provide REDUCE distributions, such as Android, the green box will instead be blue and labelled Browse Code. Clicking on it takes you to the Subversion code repository, where you may find source code for a particular platform.
</p>
<h2>The hard way to obtain REDUCE</h2>
<p>If the easy way doesn't work then you have the option of building REDUCE from the source code. For guidance on doing this, please see Chapter 2 of <a href="lisp-docs/insidereduce.pdf">Inside Reduce</a>. There are also <a href="downloading.php">brief general installation instructions</a> for all platforms and <a href="windows.php">installation instructions for Microsoft Windows users</a>, but these documents are now somewhat out of date. See also <a href="http://redlog.eu/reduce-wiki/index.php/Installation" title="Installation">Installation</a> on the REDUCE Wiki.</p>
<h2 id="windetails">More details of installing and running REDUCE on Windows</h2>
<p>The Windows installer gives you the option to install the REDUCE source code, files for CSL and files for PSL. The source code is entirely optional and only relevant if you want to understand how REDUCE works and/or modify it. You need to install files for CSL and/or files for PSL: CSL will give you a graphical user interface (GUI) by default like that shown in the <a href="images/reduce_screenshot_1.PNG">main image on the home page</a>, but can also be run with a command-line interface (CLI); PSL will give you a CLI running in a standard Windows Command Prompt window. Beware that the REDUCE installation process will overwrite any previous installation without warning (which is probably what you want).</p>
<p>Once you have installed REDUCE, you will see a folder called &quot;Reduce&quot; in your Start menu, which contains &quot;CSL Reduce&quot; and/or &quot;PSL Reduce&quot;. (You may also see other items such as &quot;CSL Bootstrap Reduce&quot; and &quot;CSL Lisp system&quot;, which are probably only of interest to developers. You can safely ignore or remove them. If you can&#39;t unpin them from the list of applications, you can remove the underlying shortcuts by right-clicking on the menu item, selecting &quot;More &gt; Open file location&quot; and then deleting the shortcuts.)</p>
<p>
	If you want to run REDUCE in an existing Command Prompt window (rather than have REDUCE open its own window), note that the PSL Reduce Start menu item runs the command &quot;<code>C:\Program Files\Reduce\bin\redpsl.bat</code>&quot;. You can either enter this long command name after a command prompt (including the quotes), or you can add &quot;<code>C:\Program Files\Reduce\bin\</code>&quot; to your command search path. The REDUCE installer does not do this for you. You can change your command search path permanently via the Advanced tab of the System Properties dialogue, which you can find in Control Panel or by searching. In Windows 10, typing Adv into Cortana seems to suffice! Click on the &quot;Environment Variables&hellip;&quot; button at the bottom of the Advanced tab, then edit the Path variable to include &quot;<code>C:\Program Files\Reduce\bin\</code>&quot;. Editing the user variable is slightly safer than editing the system variable and will suffice unless you want the change to apply to all users. Then opening a Command Prompt window and executing <code>redpsl</code> will start PSL REDUCE (with a CLI), whereas executing <code>redcsl</code> will start REDUCE with a GUI (and executing <code>redcsl --nogui</code> will start CSL REDUCE with a CLI).
</p>
<p>If you have <a href="http://www.cygwin.com/">Cygwin</a> installed then the REDUCE installer automatically adds a number of commands to the Cygwin <code>/usr/local/bin/</code> directory, in particular <code>redcsl</code> and <code>redpsl</code>. These commands are automatically accessible from a Cygwin shell and run respectively the GUI and command-line versions of REDUCE as described above.</p>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
