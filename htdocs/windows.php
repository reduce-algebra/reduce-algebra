<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'Installing REDUCE on Microsoft Windows');

$smarty->assign('header_title', 'Instructions for installing REDUCE on Microsoft Windows');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>These instructions apply primarily to Windows XP and Vista. Similar procedures will probably work for other recent versions of Windows. There are two main ways to install REDUCE on Microsoft Windows:</p>
<ul>
	<li><strong><a href="#binary">Use a pre-compiled binary distribution.</a></strong><br />
		This has the advantage that it is very quick and easy, but the disadvantage that you will probably not get the most recent updates.</li>
	<li><strong><a href="#source">Compile from the source code.</a></strong><br />
		This has the disadvantages that it is fairly time-consuming, not easy for the uninitiated, and we currently explicitly support building only using <a href="http://cygwin.com">Cygwin</a>, although the resulting compiled version of REDUCE will be a native Windows application that does not require Cygwin to run. You can download either:
		<ul>
			<li>a pre-packaged distribution, which is easiest and should give you a tested &quot;snapshot&quot;;</li>
			<li>files from the subversion repository, which will give you the latest bug fixes and updates but may not be fully tested and so may not be completely stable.</li>
		</ul>
	</li>
</ul>
<h2 id="binary">Installing a pre-compiled binary version</h2>
<p>Choose an installation folder. This can be almost anywhere, such as C:\, C:\REDUCE\ or D:\. Installing in &quot;C:\Program Files\&quot;  is probably <strong>not</strong> a good idea on Vista or later versions of Windows.</p>
<p>Go to the SourceForge download area and select the <strong>Package</strong> <a href="https://sourceforge.net/project/showfiles.php?group_id=248416&amp;package_id=303329">reduce-algebra</a>. Look for the latest <strong>Release</strong> that includes a <strong>Filename</strong> that contains &quot;windows&quot; and has extension &quot;.zip&quot;. Note that clicking on a Package link or a Release link expands or collapses its contents. Let's assume that the filename is &quot;reduce-windows-20090106.zip&quot; (in the release &quot;CSL-80020106-Windows&quot;, because at the time of writing this is the latest Windows binary distribution).</p>
<p>Click on the Filename link (e.g. &quot;reduce-windows-20090106.zip&quot;) to download the file. Save it to your chosen installation folder, then open it and select &quot;Extract all files&quot; from &quot;Folder Tasks&quot; in the task bar or &quot;Extract All...&quot; from the File menu. This will extract the contents of the ZIP archive into a folder with the same name as the file, which you can change if you want but let's assume it is called &quot;reduce-windows-20090106&quot;. (If you are running a version of Windows older than XP you will need to use a separate application to unpack the ZIP archive, such as <a href="https://sourceforge.net/projects/sevenzip/">7-Zip</a>, <a href="https://sourceforge.net/projects/peazip/">PeaZip</a>, or <a href="https://sourceforge.net/projects/infozip/">Info-ZIP</a>.) You can now delete the ZIP archive if you want.</p>
<p>The new folder (&quot;reduce-windows-20090106&quot;) should contain two folders called reduce.doc and reduce.fonts, and three files called reduce.com, reduce.exe and reduce.img. There are two ways to run REDUCE:</p>
<ul>
	<li>Opening reduce.exe, e.g. by double-clicking on it, should start REDUCE as a normal windowed application, which is what most users will want. It supports typeset-style two-dimensional mathematical display of REDUCE output. (You can turn this off if necessary by executing the REDUCE command &quot;off fancy;&quot;.)</li>
	<li>Alternatively, from a command prompt, executing the command &quot;reduce -w&quot;  will start reduce.com and the &quot;-w&quot; flag instructs it to act as a console application. It supports only an ASCII character-based simulation of conventional two-dimensional mathematical display. This is also the way to run REDUCE from within another application, such as Emacs. However, by default this will only work if the folder containing reduce.com is the current directory; <a href="#prompt">see below</a> for further details.</li>
</ul>
<p>(The executables reduce.exe and reduce.com are identical except that the first is linked as a &quot;windows&quot; application and the second as a &quot;console&quot;application. Running the command-line version as &quot;reduce -l logfile.log&quot; arranges to keep a transcript of your session in the given log file.)</p>
<h3>Adding REDUCE to the Windows Start menu</h3>
<p>Installation of Windows applications normally includes adding items (shortcuts) to the Windows Start menu, which you can easily do by hand as follows. Right-click on the Windows Start button. If you want to create Start menu items only for yourself select Open or Explore from the top of the menu; if you want to create Start menu items  for all users select Open All Users or Explore All Users from the bottom of the menu. If you want the REDUCE menu items to appear in the main part of the All Programs menu, open the folder called Programs; if you create them in the root of the Start menu folder they will appear at the top of the All Programs menu. (You can move menu items around after you have created them, just like any other files and folders.)</p>
<p>
	Optionally, select File / New / Folder and type a name for a sub-menu, such as REDUCE, then open the new sub-menu folder. Right-click-and-drag the file reduce.exe to the appropriate Start menu folder and select the option Create Shortcuts Here from the resulting pop-up menu. Change the name of the shortcut to something sensible like REDUCE. Do the same for reduce.com and rename the  shortcut to something like &quot;Command-line REDUCE&quot;. Notice that Windows detects automatically that this is a different kind of shortcut. Right-click it, select Properties and then the Program tab. Add &quot;-w&quot; (without the quotes) to the end of the command line (Cmd line:). You can also change other properties, such as the working directory (Working:), if you want.
</p>
<p>The windowed version of REDUCE has a Help menu (at the right-hand side of the menu bar), which displays HTML documents in your default web browser. You can also provide access to the same help from the Start menu by creating a shortcut to the file index.html in the reduce.doc folder, as described above for the program files, and renaming it to something helpful like Help.</p>
<h3>Testing your REDUCE installation</h3>
<p>For a very quick test that REDUCE is working, you might try typing the following lines of input to successive REDUCE input prompts in either the windowed or the command-line version:</p>
<pre>x^x;
df(ws,x);
int(ws,x);</pre>
<p>Finally, the command</p>
<pre>bye;</pre>
<p>should terminate any version of REDUCE.</p>
<h3 id="prompt">Running REDUCE from a Command Prompt</h3>
<p>To run REDUCE from a command shell (such as the default Windows command shell cmd.exe) it is best to add the directory containing reduce.com to your execution path. One way to do this is to right-click on My Computer, select Properties from the bottom of the pop-up menu, click on the Advanced tab and then click on the Environment Variables button at the bottom of the dialogue box. You will see two sets of variables: user variables for you alone and system variables for everyone. Both sets should contain a variable called PATH. Choose one of these PATH variables, double-click it, and edit the path of the REDUCE executable folder into the value, following the style of the other path elements. (Note that path elements in Windows are separated by semi-colons.)</p>
<h2 id="source">Compiling from the source code</h2>
<p>The build environment on Windows is currently assumed to be <a href="http://cygwin.com/">Cygwin</a>, which  provides a very similar environment to Linux: Linux consists of GNU software running on a Linux kernel, whereas Cygwin consists of GNU software running on a Windows kernel via a Unix emulation layer provided by the Cygwin dll. <a href="http://www.redhat.com/">Red Hat, Inc.</a> supports both Cygwin and its own distribution of Linux.</p>
<p>You need to have a sufficiently complete <a href="http://cygwin.com/">Cygwin</a> installation, including the tools required to obtain and unpack the source code files and the tools required to build using the <a href="http://mingw.sourceforge.net/">MinGW (Minimalist GNU for Windows)</a>  environment. If the build process fails in any non-obvious way then it probably means that you are missing some necessary build tool. Once you have a suitable Cygwin installation, building REDUCE is very similar to the procedure on other platforms. For the time being, please see the general guidance on <a href="downloading.php">Downloading REDUCE from SourceForge</a>.</p>
<p>Here is a tentative list of the Cygwin package you need to build REDUCE, but please note that we don't guarantee  this list to be either sufficient or necessary!</p>
<table border="1" cellpadding="2">
	<caption>
		Required Cygwin packages
	</caption>
	<tr>
		<th scope="col">Package</th>
		<th scope="col">Comment</th>
	</tr>
	<tr>
		<td>autoconf</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>automake</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>(bash)</td>
		<td>installed anyway</td>
	</tr>
	<tr>
		<td>bintools</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>bison</td>
		<td>not used via regular makescripts</td>
	</tr>
	<tr>
		<td>bzip2</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>diffutils</td>
		<td>?needed?</td>
	</tr>
	<tr>
		<td>flex</td>
		<td>not used via regular makescripts</td>
	</tr>
	<tr>
		<td>gcc-g++</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>gcc-mingw-g++</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>gzip</td>
		<td>probably!</td>
	</tr>
	<tr>
		<td>libncurses-devel</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>libtool</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>make</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>patch</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>patchutils</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>sed</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>subversion</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>tar</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>tetex</td>
		<td>to process the documentation</td>
	</tr>
	<tr>
		<td>unzip</td>
		<td>&nbsp;</td>
	</tr>
</table>
END_OF_MAIN_CONTENT
);

$smarty->display('secondary.tpl');

?>
