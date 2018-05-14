<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Help Wanted!');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>Contributors to the REDUCE project are warmly welcome! This page is meant to attract the attention of volunteers on several issues that have arisen in the REDUCE developers' community. Interested people should subscribe to the developers' mailing list and post an item indicating where they would like to help.</p>
<dl>
	<dt>State of REDUCE algorithms</dt>
	<dd>It is necessary to check REDUCE against its main competitors, like Mathematica and Maple. This means checking if the main algorithms in REDUCE are still effective in comparison with those of other Computer Algebra Systems. Examples: REDUCE performs very well in simplifying rational expressions to the canonical form. However, REDUCE seems to perform badly in some packages which might be outdated, for example computing the Jordan canonical form of symbolic matrices (package linalg).</dd>

	<dt>Bringing REDUCE to mobile devices</dt>
	<dd>There is some code that is aimed at a Lisp interpreter in Java. The code proved to be partly working in an Android environment. This should be completed to a fully functional Android REDUCE.</dd>

	<dt>Parallelizing REDUCE</dt>
	<dd>As nearly all devices have multiple cores, it is desirable to use them in REDUCE. For this one needs a Lisp interpreter that is able to run parallel tasks on the various cores. At the moment there is not even an idea about the model for such an interpreter.</dd>

	<dt>REDUCE packages in Linux distributions</dt>
	<dd>REDUCE is not packaged in the main Linux distributions, i.e., Debian-based and Red Hat-based distributions. The source code already contains scripts to generate deb packages that should work on every Debian-based system; the packages have been converted into rpm by the tool alien, and they have been successfully tested in some Red Hat-based distributions. We are looking for Debian/Red Hat maintainers who might wish to include and maintain a REDUCE package for those Linux distributions.</dd>

	<dt>CSL documentation</dt>
	<dd>At the moment, the CSL interpreter of the Lisp dialect in which most of REDUCE is written is almost undocumented. Volunteers should work through the CSL sources listing every defined symbol and writing a paragraph to explain it. In the source code there is a start at putting embedded annotations to be extracted into a TeX document, but continuing that to completion has never been done.</dd>

	<dt>Graphical User Interface in CSL</dt>
	<dd>At present the CSL version uses the FOX GUI toolkit to support its windowed interface. This supports Unix and Windows well, but only runs on a Macintosh via the X11 server, and Macintosh people may view that as almost useless for them. An experimental GUI using the wxWidgets graphical libraries is already in the REDUCE source code. Volunteers are needed to complete this task.</dd>

	<dt>Type-checking in REDUCE</dt>
	<dd>Type mismatch is one of the most frequent errors that symbolic mode programmers make, and at present there are no diagnostics that clearly flag that sort of mistake. There have been attempts to introduce type checking in REDUCE: the package assert and the package reduce4. Starting from revision 4133 of March 2017 type information can be inserted in the arguments of procedures and the declaration of variables. This is a start at a complete type checking system; however much has to be done.</dd>

	<dt>Improve the "ed" command</dt>
	<dd>Review this REDUCE command and make it useful in a modern computing environment, such as by making it invoke the user's choice of editor. This is probably not that huge a task and could provide a gentle induction into the developer community.</dd>

	<dt>LALR parser as a new REDUCE package</dt>
	<dd></dd>

	<dt>Garbage Collection</dt>
	<dd></dd>
</dl>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
