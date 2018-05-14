<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Versions');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>REDUCE is based on a dialect of Lisp called <i><a href="lisp-docs/sl.pdf">Standard Lisp</a></i>, and the differences between versions are the result of different implementations of this Lisp; in each case the source code for REDUCE itself remains the same. The available versions of REDUCE are based on two different Lisps, namely:</p>
<dl>
	<dt>Portable Standard Lisp (PSL)</dt>
	<dd>PSL was the original implementation of Standard Lisp, but now contains many more facilities. It is quite efficient in its use of both space and time, and has been optimized for algebraic computation. All PSL versions of REDUCE are distributed with sufficient PSL support to run on the given computing system. PSL is supported on many architectures and is an ideal system for those wanting to run REDUCE as a stand-alone system. The principal developer of PSL before it became Open Source was the Konrad Zuse Center, Berlin (<a href="http://www.zib.de/">ZIB</a>).</dd>
	<dt>Codemist Standard Lisp (CSL)</dt>
	<dd>CSL is a newer Lisp system that continues to evolve and is now written completely in C++, which makes it very easy to port to a new machine. Like PSL, it is a faithful implementation of Standard Lisp and has been optimized for running REDUCE. It requires a very small memory partition for its Lisp support. Furthermore, most of the REDUCE facilities are supported as machine independent pseudocode, which is quite compact. In the worst case, the performance of this system is about a factor of two slower than PSL, though in many cases it matches PSL performance. However, the memory use is smaller. All CSL versions are distributed with sufficient CSL support to run on the given computing system. This is also an ideal system for those wishing to embed algebraic calculations in a C or C++ programming environment. The developer of CSL before it became Open Source was <a href="http://www.codemist.co.uk/">Codemist Ltd</a>.</dd>
</dl>
<h2>REDUCE version numbers and releases</h2>
<p>The commercial releases of REDUCE had version numbers, the last of which was version 3.8 released in 2004. The Open Source releases of REDUCE available since 2008 do not have version numbers, but are identified by release dates. A REDUCE release includes all necessary binary files for a specific platform and releases are currently provided irregularly every few months for Microsoft Windows, Apple MacOS and GNU/Linux (all at the same time). Every so often there may also be a release for a more esoteric architecture, such as the Raspberry Pi!</p>
<p>A release is essentially a set of files built from a snapshot of the source code, which evolves on a daily (if not hourly) basis as the developers commit updates. The source code is managed using Subversion, which increments the revision number (of the whole code base) with each commit, and this now serves as a version number. Since the whole code base is now publicly available, formal releases are no longer very significant.</p>
END_OF_MAIN_CONTENT
);

$smarty->display('secondary.tpl');

?>
