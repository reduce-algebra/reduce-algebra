<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Support');

$smarty->assign('Q_A', array(

	array(
		'Q' => 'What is REDUCE?',
		'A' => 'REDUCE is a Computer Algebra System. Think of it as a very advanced programmable scientific calculator intended for solving algebraic or symbolic problems. But it will also solve purely numerical problems (exactly or approximately) and plot graphs.'),

	array(
		'Q' => 'Who is REDUCE intended for?',
		'A' => '<p>REDUCE is intended for users who want to solve problems in mathematics, science and engineering at pre-university level and above, although it was originally developed for research in high energy (elementary particle) physics. But, as when using any kind of calculator or computer software, you may need to do quite a lot of work to get your problem into a form that REDUCE can solve. REDUCE (like most Computer Algebra Systems) is good at solving concrete problems (such as problems involving matrices with specified elements) and not so good as solving abstract problems (such as problems involving vector spaces of arbitrary dimension).</p>
<ol>
	<li>Casual users wishing to solve straightforward problems can use REDUCE interactively and may want to use some of the <a href="documentation.php#contributed">contributed REDUCE packages</a> that are not automatically loaded, which extend the domain of applicability of REDUCE beyond that of the core system.</li>
	<li>Users wishing to solve more complicated problems can use the REDUCE algebraic-mode programming language and may want to prepare REDUCE programs in files of source code to be read into REDUCE.</li>
	<li>Advanced users wishing to extend the domain of applicability of REDUCE may want to write programs using the REDUCE symbolic-mode programming language and compile them into new packages.</li>
	<li>Developers wishing to port REDUCE to other platforms or Lisp systems, incorporate REDUCE into other software, or modify REDUCE for their own purposes, and anyone interested in how REDUCE works, can access all the current <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">source code</a> for REDUCE and its support systems.</li>
</ol>'),

	array(
		'Q' => 'How can I obtain REDUCE?',
		'A' => 'Go to the SourceForge <a href="https://sourceforge.net/projects/reduce-algebra/">REDUCE project page</a>, click on the green Download button and install the file that is downloaded. For more options (previous versions, other platforms, etc.) click on the <a href="https://sourceforge.net/projects/reduce-algebra/files/">Files</a> tab. For full and historical REDUCE-related source code (for REDUCE itself, Lisp systems, user interfaces, documentation, etc.) click on the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">Code</a> tab to access the Subversion repository. See <a href="obtaining.php">Obtaining REDUCE</a> for further details.'),

	array(
		'Q' => 'How do I run REDUCE?',
		'A' => 'Once you have installed REDUCE, you should see applications named something like CSL REDUCE and/or PSL REDUCE in your application menu; click on one of them. CSL REDUCE provides a graphical user interface (by default) and PSL REDUCE provides a command-line interface. But unless you are already familiar with REDUCE you should probably first browse the REDUCE User&#39;s Manual, either as <a href="../manual/manual.html">HTML</a> or <a href="../manual/manual.pdf">PDF</a>. A number of <a href="books.php">published books</a> about REDUCE and related topics are also available.'),

	array(
		'Q' => 'Why are there two versions of REDUCE?',
		'A' => 'REDUCE runs on <a href="documentation.php">Standard Lisp</a> and there are two versions of Standard Lisp that were developed primarily to support REDUCE, namely <a href="versions.php">PSL and CSL</a> (in that order chronologically). We only release distributions of REDUCE based on these two Lisps, although REDUCE can be implemented on other versions of Standard Lisp (and there is some experimental code to do this in the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/">repository</a>).'),

	array(
		'Q' => 'What user interfaces does REDUCE provide?',
		'A' => 'PSL REDUCE itself provides only a command-line interface (CLI). CSL REDUCE provides a graphical user interface (GUI) by default, but it provides a command-line interface if started with the <code>--nogui</code> option. <a href="https://www.gnu.org/software/emacs/emacs.html">GNU Emacs</a> provides a GUI for PSL and CSL REDUCE via the <a href="reduce-ide/">REDUCE IDE</a> package and <a href="http://www.texmacs.org/">GNU TeXmacs</a> provides a GUI for PSL and CSL REDUCE via a <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/texmacs/">plugin for running REDUCE</a>. There is code in the repository for two other packages, <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/redfront">redfront</a> and <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/psl/xr/">XR</a>, that provide GUIs for PSL, but neither is currently distributed as a pre-built binary and XR is somewhat out of date.'),

	array(
		'Q' => 'What start-up options does REDUCE provide?',
		'A' => 'For CSL REDUCE, running <code>redcsl --nogui --help</code> at a command prompt (assuming <code>redcsl</code> is on your search path &ndash; see <a href="obtaining.php">Obtaining REDUCE</a>) lists the start-up options.'),

	array(
		'Q' => 'How can I learn how to use REDUCE?',
		'A' => 'The <strong>REDUCE User&#39;s Manual</strong> <small>[ <a href="manual/manual.html">HTML</a> | <a href="manual/manual.pdf">PDF</a> ]</small> is the obvious starting point and there are a number of <a href="books.php">published books</a> covering various aspects of REDUCE. You may like to work through the <a href="javascript:void $(\'#lessons\').parent().parent().collapse(\'show\');">REDUCE interactive lessons</a>. Each of the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/packages/">REDUCE packages</a> has one or more associated test files (with extension &quot;<code>.tst</code>&quot;) and a corresponding log file containing the output from running the test (with extension &quot;<code>.rlg</code>&quot;). These files, particularly the log files, provide instructive examples of how to use REDUCE, although they were not written as instructional material and are somewhat cryptic, assuming the reader is familiar with the problems addressed. The <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/xmpl">xmpl</a> directory provides a convenient collection of test and log files from many of the packages, although they may be out of date.'),

	array(
		'Q' => 'How can I run the REDUCE interactive lessons?',
		'A' => '<p id="lessons">First, you need to download them from SourceForge.</p>
<ul>
	<li>If you have the <a href="https://en.wikipedia.org/wiki/Apache_Subversion">subversion</a> program installed then select a directory on your computer to contain the <code>lessons</code> directory, open a command prompt window in that directory (if necessary) and execute the shell command
		<pre>svn checkout svn://svn.code.sf.net/p/reduce-algebra/code/trunk/packages/lessons</pre>
	</li>
	<li>If you don&#39;t have subversion then create a directory on your computer called<code> lessons</code> (although you can call it whatever you want). Go to the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/packages/lessons/">lessons directory in the SourceForge code repository</a>, click on the first lesson file (called <code>less1.red</code>), click on the link labelled &quot;Download this file&quot; that appears above the file listing, download the file to your computer and save it in your <code>lessons</code> directory. Repeat this process for the remaining lesson files.</li>
</ul>
<p>The lesson files are intended to be perused in REDUCE (although they are plain text files). They consist of long comments interspersed with REDUCE input that is intended to be executed, and they automatically pause every so often so that you can read the next section. But you may need to scroll back to the beginning of the file or to the last pause to see the beginning of the current section. If you want to read a lesson outside of REDUCE then it is easy to do so in your web browser, as described in the second bullet point above.</p>
<ul>
	<li>One way to run the lessons in CSL REDUCE is to start it normally, click on the <code>File / Read...</code> menu item, find your <code>lessons</code> directory in the file selector and then select a lesson file, such as <code>less1.red</code>.</li>
	<li>One way to run the lessons in PSL REDUCE is to start it normally and then execute a command of the following form (customized as appropriate for your computer):
		<pre>in &quot;path/to/lessons/less1.red&quot;;</pre></li>
</ul>
<p>It is advisable to run each lesson in a new REDUCE sessions, otherwise the lessons may interfere with each other.</p>'),

	array(
		'Q' => 'How can I learn how REDUCE works and how to modify or extend it?',
		'A' => '<a href="http://localhost/REDUCE/web/htdocs/lisp-docs/insidereduce.pdf"><strong>Inside Reduce</strong></a>, the <strong>Symbolic Mode Primer</strong> <small>[ <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/primer.html">HTML</a> | <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/primer.pdf">PDF</a> ]</small>, the <strong>Standard Lisp Report</strong> <small>[ <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/sl.html">HTML</a> | <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/sl.pdf">PDF</a> ]</small>, the <strong>PSL Users Manual</strong> <small>[ <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/allman1.html">HTML</a> | <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/allman1.pdf">PDF</a> ]</small> and the <a href="http://localhost/REDUCE/web/htdocs/lisp-docs/csl.html"><strong>CSL Reference</strong></a> all provide useful background. Some of the <a href="books.php">published books</a> on REDUCE discuss algorithms and implementation, and the references in them will take you further.&nbsp; Ultimately, you will have to read the REDUCE <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">source code</a>!'),

	array(
		'Q' => 'Why are there multiple REDUCE web sites?',
		'A' => 'REDUCE is hosted on SourceForge, which provides a project site and a project web site for each project; see the SourceForge <a href="https://p.sf.net/sourceforge/docs">Site Documentation</a> for details. The project site (<a href="https://sourceforge.net/p/reduce-algebra/">https://sourceforge.net/p/reduce-algebra</a> for REDUCE) hosts the software itself and its format is completely controlled by SourceForge. The project web site (<a href="http://reduce-algebra.sourceforge.net">reduce-algebra.sourceforge.net</a> for REDUCE) hosts any other information (such as this page) that the project team wants to provide and its format is controlled by them. The REDUCE web site can also be accessed as <a href="http://reduce-algebra.com/">reduce-algebra.com</a>. This was originally the REDUCE web site created by Tony Hearn when REDUCE was a commercial product, but since 2017 it has been an alias for <a href="http://reduce-algebra.sourceforge.net/">reduce-algebra.sourceforge.net</a>. (The same URLs but beginning with www, namely <a href="http://www.reduce-algebra.sourceforge.net/">www.reduce-algebra.sourceforge.net</a> and <a href="http://www.reduce-algebra.com/">www.reduce-algebra.com</a>, also work.) Redlog, which is the REDUCE package for computing with logic included in the standard distribution, has its own <a href="http://www.redlog.eu/">independent web site</a>, which includes the <a href="http://redlog.eu/reduce-wiki">Reduce Wiki</a> that provides some general information about REDUCE.'),

	array(
		'Q' => 'How do I find out more about SourceForge?',
		'A' => 'There is a link to the SourceForge <a href="https://p.sf.net/sourceforge/docs">Site Documentation</a> at the bottom of every SourceForge page, but this is aimed more at developers than users and is not specific to REDUCE. The most useful general user documentation is probably the <a href="https://sourceforge.net/p/forge/documentation/User%20Accounts/">User Account Information</a>.'),

	array(
		'Q' => 'Why should I register with SourceForge and log in?',
		'A' => 'According to the SourceForge documentation on <a href="https://sourceforge.net/p/forge/documentation/User%20Accounts/">User Account Information</a>: Software can be downloaded from SourceForge.net without registering an account. An account is needed in order to participate in discussion forums, submit bug reports, and join a project [as an administrator or developer]. <a href="https://sourceforge.net/account/registration/">Register a user account</a>.'),

	array(
		'Q' => 'How should I report a REDUCE bug?',
		'A' => 'If you think you have found an error or omission in REDUCE, or in any of its support systems or documentation, then please report it using the bug tracker accessible via the <a href="https://sourceforge.net/p/reduce-algebra/bugs/">Bugs</a> tab on the REDUCE project page. You need to be logged in to SourceForge to do this. Or, if you prefer, you can use the <a href="mailto:reduce-algebra-developers@lists.sourceforge.net">reduce-algebra-developers mailing list</a>, but you need to be registered with SourceForge to do this.'),

	array(
		'Q' => 'What REDUCE online discussion fora are there?',
		'A' => '<p>There are currently three REDUCE discussion fora &ndash; Open Discussion, Help, and Developers &ndash; accessible via the <a href="https://sourceforge.net/p/reduce-algebra/discussion/">Discussion</a> tab on the REDUCE project page. If you are not sure which is most appropriate, you can take a look at past discussions on each forum. You need to be logged in to SourceForge to post comments.</p>
<p>Note that SourceForge uses <a href="https://en.wikipedia.org/wiki/Markdown">markdown</a> syntax for input such as forum posts, which can have unexpected consequences if you think you are writing plain text! Please read the <a href="https://sourceforge.net/p/reduce-algebra/discussion/markdown_syntax">Formatting Help</a> if you are not familiar with markdown. In particular, markdown hijacks several mathematical operators for other purposes and, for example, if you want to use * to indicate multiplication then you either need to escape it as \* or use the HTML entity code &amp;ast;.</p>'),

	array(
		'Q' => 'What REDUCE mailing lists are available?',
		'A' => 'We currently run only one mailing list, details of which are accessible via the <a href="https://sourceforge.net/p/reduce-algebra/mailman/">Mailing Lists</a> tab on the REDUCE project page. Here you can access past discussions and subscribe to the list. Although the list is called &quot;reduce-algebra-developers&quot;, it is used for general &quot;discussion of development, administration and support for Reduce&quot;. In practice, it is probably used most by users asking questions that developers try to answer. It is currently the main support mechanism for REDUCE and can be used to report bugs, request features, and discuss anything related to REDUCE. Developers also occasionally use it for announcements. The list is low volume!'),

	array(
		'Q' => 'How can I receive updates on REDUCE by email?',
		'A' => '<p>Log in to the <a href="https://sourceforge.net/projects/reduce-algebra/">REDUCE project page</a> at SourceForge and then click on the blue Get Updates button (beside the green Download button).</p>
<p>To control all your email subscriptions, log in to SourceForge and then look at the Me link towards the top right-hand corner of most SourceForge pages. Hover over this, click on Account Settings in the drop-down menu and then select the Subscriptions tab.</p>'),

	array(
		'Q' => 'What is in the REDUCE code repository?',
		'A' => '<p>You can browse the REDUCE source code repository most easily by clicking on the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">Code</a> tab on the REDUCE project page. You are most likely to be interested in the code in the directory called trunk, so click on <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk">trunk</a> in the File column. Most directories contain a README file that is displayed at the bottom of the directory listing and gives some information about the purpose of the directory and/or how to use its contents. Most of the code relates to REDUCE itself or the Lisp systems used to implement it.</p>
<p>The <code>packages</code> directory contains most of the main code for REDUCE itself, which is written in RLISP and is (essentially) independent of the underlying Lisp system. The <code>csl</code> and <code>psl</code> directories contain the main code for the two Lisp systems that support the distributed versions of REDUCE. The <code>jlisp</code>, <code>jslisp</code> and <code>vsl</code> directories contain experimental Lisp systems. The <code>doc</code> directory contains the main documentation for REDUCE. The <code>contrib</code> and <code>generic</code> directories contain contributed code that is not (yet) incorporated into the REDUCE distributions. The <code>web</code> directory contains the code used to run the REDUCE web site (such as this page).</p>')

));

$smarty->display('support.tpl');

?>
