<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Support');

$smarty->assign('Q_A', array(
	array(
		'Q' => 'What is REDUCE?',
		'A' => 'REDUCE is a Computer Algebra System. Think of it as a very advanced programmable scientific calculator intended for solving algebraic or symbolic problems. But it will also solve purely numerical problems and plot graphs.'),
	array(
		'Q' => 'What users is REDUCE intended for?',
		'A' => 'REDUCE can be used to solve problems in mathematics, science and engineering at pre-university level and above, although it was originally developed for research in high energy (elementary particle) physics. But, as when using any kind of calculator or computer software, you may need to do quite a lot of work to get your problem into a form that REDUCE can solve. REDUCE (like most Computer Algebra Systems) is good at solving concrete problems (such as problems involving matrices with specified elements) and not so good as solving abstract problems (such as problems involving vector spaces of arbitrary dimension).'),
	array(
		'Q' => 'How can I obtain REDUCE?',
		'A' => 'Go to the SourceForge <a href="https://sourceforge.net/projects/reduce-algebra/">REDUCE project page</a>, click on the green Download button and install the file that is downloaded. For more options (previous versions, other platforms, etc.) click on the <a href="https://sourceforge.net/projects/reduce-algebra/files/">Files</a> tab. For full and historical REDUCE-related source code (for REDUCE itself, Lisp systems, user interfaces, documentation, etc.) click on the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">Code</a> tab to access the Subversion repository. See <a href="obtaining.php">Obtaining REDUCE</a> for further details.'),
	array(
		'Q' => 'How do I run REDUCE?',
		'A' => 'Once you have installed REDUCE, you should see applications named something like CSL REDUCE and/or PSL REDUCE in your application menu; click on one of them. CSL REDUCE provides a graphical user interface (by default) and PSL REDUCE provides a command-line interface. But unless you are already familiar with REDUCE you should probably first browse the REDUCE User&#39;s Manual, either as <a href="../manual/manual.html">HTML</a> or <a href="../manual/manual.pdf">PDF</a>. A number of commercially published <a href="books.php">books about REDUCE and related topics</a> are also available.'),
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
		'Q' => 'Why are there multiple REDUCE web sites?',
		'A' => 'REDUCE is hosted on SourceForge, which provides a project site and a project web site for each project; see the SourceForge <a href="https://p.sf.net/sourceforge/docs">Site Documentation</a> for details. The project site (<a href="https://sourceforge.net/p/reduce-algebra/">https://sourceforge.net/p/reduce-algebra</a> for REDUCE) hosts the software itself and its format is completely controlled by SourceForge. The project web site (<a href="http://reduce-algebra.sourceforge.net">reduce-algebra.sourceforge.net</a> for REDUCE) hosts any other information (such as this page) that the project team wants to provide and its format is controlled by them. The REDUCE project web site can also be accessed as <a href="http://reduce-algebra.com/">reduce-algebra.com</a>. This was originally the REDUCE web site created by Tony Hearn when REDUCE was a commercial product, but since 2017 it has been an alias for <a href="http://reduce-algebra.sourceforge.net/">reduce-algebra.sourceforge.net</a>. (The URLs beginning with www, namely <a href="http://www.reduce-algebra.sourceforge.net/">www.reduce-algebra.sourceforge.net</a> and <a href="http://www.reduce-algebra.com/">www.reduce-algebra.com</a>, are also aliases for <a href="http://reduce-algebra.sourceforge.net/">reduce-algebra.sourceforge.net</a>.) Redlog, which is the REDUCE package for computing with logic and is included in the standard distribution, has its own <a href="http://www.redlog.eu/">independent web site</a>, which includes an independent <a href="http://redlog.eu/reduce-wiki">Reduce Wiki</a> that provides some general information about REDUCE.'),
	array(
		'Q' => 'How do I find out more about SourceForge in general?',
		'A' => 'There is a link to the SourceForge <a href="https://p.sf.net/sourceforge/docs">Site Documentation</a> at the bottom of every SourceForge page, but this is aimed more at developers than users and is not specific to REDUCE. The most useful general user documentation is probably the <a href="https://sourceforge.net/p/forge/documentation/User%20Accounts/">User Account Information</a>.'),
	array(
		'Q' => 'Why should I register with SourceForge and log in?',
		'A' => 'According to the SourceForge documentation on <a href="https://sourceforge.net/p/forge/documentation/User%20Accounts/">User Account Information</a>: Software can be downloaded from SourceForge.net without registering an account. An account is needed in order to participate in discussion forums, submit bug reports, and join a project [as an administrator or developer]. <a href="https://sourceforge.net/account/registration/">Register a user account</a>.'),
	array(
		'Q' => 'How should I report a REDUCE bug?',
		'A' => 'If you think you have found an error or omission in REDUCE, or in any of its support systems or documentation, then please report it using the bug tracker accessible via the <a href="https://sourceforge.net/p/reduce-algebra/bugs/">Bugs</a> tab on the REDUCE project page. You need to be logged in to SourceForge to do this. Or, if you prefer, you can use the <a href="mailto:reduce-algebra-developers@lists.sourceforge.net">reduce-algebra-developers mailing list</a>, but you need to be registered with SourceForge to do this.'),
	array(
		'Q' => 'What REDUCE online discussion fora are there?',
		'A' => 'There are currently three REDUCE discussion fora &ndash; Open Discussion, Help, and Developers &ndash; accessible via the <a href="https://sourceforge.net/p/reduce-algebra/discussion/">Discussion</a> tab on the REDUCE project page. If you are not sure which is most appropriate, you can take a look at past discussions on that forum. You need to be logged in to SourceForge to post comments. Note that SourceForge uses markdown syntax for input such as forum posts, which can have unexpected consequences if you think you are writing plain text! Please read the <a href="https://sourceforge.net/p/reduce-algebra/discussion/markdown_syntax">Formatting Help</a> if you are not familiar with markdown. In particular, markdown hijacks several mathematical operators for other purposes and, for example, if you want to use * to indicate multiplication then you either need to escape it as \* or use the HTML entity code &amp;ast;.'),
	array(
		'Q' => 'What REDUCE mailing lists are available?',
		'A' => 'We currently run only one mailing list, details of which are accessible via the <a href="https://sourceforge.net/p/reduce-algebra/mailman/">Mailing Lists</a> tab on the REDUCE project page. Here you can access past discussions and subscribe to the list. Although the list is called &quot;reduce-algebra-developers&quot;, it is used for general &quot;discussion of development, administration and support for Reduce&quot;. In practice, it is probably used most by users asking questions that developers try to answer. It is currently the main source of support for REDUCE and can be used to report bugs, request features, and discuss anything related to REDUCE. Developers also occasionally use it for announcements. The list is low volume!'),
	array(
		'Q' => 'How do I receive updates on REDUCE by email?',
		'A' => 'Log in to SourceForge and then click on the blue Get Updates button beside the green Download button on the <a href="https://sourceforge.net/projects/reduce-algebra/">REDUCE project page</a>. To control all your email subscriptions, log in to SourceForge and then look at the Me link towards the top right-hand corner of most SourceForge pages. Hover over this, click on Account Settings in the drop-down menu and then select the Subscriptions tab.'),
	array(
		'Q' => 'What is in the REDUCE code repository?',
		'A' => 'You can browse the REDUCE source code repository most easily by clicking on the <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">Code</a> tab on the REDUCE project page. You are most likely to be interested in the code in the directory called trunk, so click on <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk">trunk</a> in the File column. Most directories contain a README file that is displayed at the bottom of the directory listing and gives some information about the purpose of the directory and/or how to use its contents. Most of the code relates to REDUCE itself or the Lisp systems used to implement it. The <code>packages</code> directory contains most of the main code for REDUCE itself that is written in RLISP and is (essentially) independent of the underlying Lisp system. The <code>csl</code> and <code>psl</code> directories contain the main code for the two Lisp systems that support the distributed versions of REDUCE. The <code>jlisp</code>, <code>jslisp</code> and <code>vsl</code> directories contain experimental Lisp systems. The <code>doc</code> directory contains the main documentation for REDUCE. The <code>contrib</code> and <code>generic</code> directories contain contributed code that is not (yet) incorporated into the REDUCE distributions. The <code>web</code> directory contains the code used to run the REDUCE web site (such as this page).')
));

$smarty->display('support.tpl');

?>
