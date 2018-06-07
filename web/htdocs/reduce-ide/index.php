<?php

require_once('../../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'REDUCE IDE');

$smarty->assign('header_title', 'REDUCE IDE');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
	<p>REDUCE IDE is a package that provides an <u>I</u>ntegrated <u>D</u>evelopment <u>E</u>nvironment for the <a>REDUCE</a> computer algebra system within the <a href="http://www.gnu.org/">GNU</a> <a href="http://www.gnu.org/software/emacs/emacs.html">Emacs</a> editor. Its two major components are Emacs Lisp libraries that provide major modes for respectively editing REDUCE source code and running a <strong>command-line version</strong> of REDUCE in an Emacs window. Many of the facilities require that Emacs is running under a GUI such as <a href="http://windows.microsoft.com/">Microsoft Windows</a>, or the <a href="http://www.x.org/">X Window System</a> under some flavour of <a href="http://en.wikipedia.org/wiki/Unix">UNIX</a> or <a href="http://en.wikipedia.org/wiki/Linux">Linux</a>.</p>
	<p>A user guide is available online in <a href="reduce-ide.pdf">PDF</a> and <a href="reduce-ide/index.html">HTML</a>, and various other formats can be generated from the GNU texinfo source file. Full source code is available from the <code>/trunk/generic/emacs</code> directory in the REDUCE subversion repository via a subversion client or <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/">directly using a web browser</a>. A README file provides further technical details.</p>
	<p>REDUCE IDE requires GNU Emacs 23 or later, although I recommend version 25 or later. There is currently no explicit support for <a href="http://www.xemacs.org/">XEmacs</a>.</p>
	<h2>Major update history</h2>
	<p>REDUCE IDE version 1.5 (Nov 2017) should work with the latest versions of both REDUCE and GNU Emacs. It also provides full support for the GNU Emacs package manager (see below), explicit support for running both CSL and PSL REDUCE, and explicit support for running multiple REDUCE processes simultaneously.</p>
	<h2>Installation</h2>
	<p>Provided you are using GNU Emacs 24 or later, I recommend that you install the latest complete REDUCE IDE package, which includes documentation in info format, as follows. Customize the Emacs user option &#39;package-archives&#39; to add a new archive with the URL &quot;<a href="http://reduce-algebra.sourceforge.net/reduce-ide/packages/">http://reduce-algebra.sourceforge.net/reduce-ide/packages/</a>&quot;. You can give this archive any name you like, such as &quot;reduce-ide&quot;. Then run the Emacs package manager, which is available as an item towards the bottom of the Options menu. (Or you can run the command &#39;M-x list-packages&#39;.) This should show the latest available version of the package reduce-ide, which you can install by clicking on it and then clicking the Install button. Whenever you run the Emacs package manager in future it will show if there is a new version of REDUCE IDE available, and allow you to install it.</p>
																																			   <p>Installing the full package will automatically perform all necessary configuration and make REDUCE IDE ready to use. It should also install the documentation, so that if you start the info browser, REDUCE IDE should appear at the top of the Emacs topics (probably immediately before Emacs itself). You can browse info documentation in Emacs via the menu item <em>Help / More Manuals / All Other Manuals (Info)</em> or via the key sequence <em>C-h i</em>.</p>
	<p>An alternative way to install the latest complete REDUCE IDE package is to open the <a href="http://reduce-algebra.sourceforge.net/reduce-ide/packages/">REDUCE IDE packages directory</a> in a web browser, download the latest reduce-ide package, then run the Emacs command &#39;package-install-file&#39; and give it the full pathname of the reduce-ide package file you just downloaded. This will have exactly the same effect as using the Emacs package manager.</p>
																								   <p>Feedback is welcome.</p>
	<address><a href="https://sourceforge.net/u/fjwright">Francis Wright</a></address>
END_OF_MAIN_CONTENT
);

$smarty->display('secondary.tpl');

?>
