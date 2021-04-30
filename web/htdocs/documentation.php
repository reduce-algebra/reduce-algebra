<?php  // -*-mhtml-*-

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

// *** Beware that relative URLs on this page are relative to "/manual/". ***

$smarty->assign('header_title', 'Documentation');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>
  REDUCE includes considerable documentation, not only for the core
  system, but also for the many application packages included in the
  release. (The <a href="/documentation38.php">documentation for
  REDUCE 3.8</a>, the last commercial version of REDUCE released in
  2004, is also still available.)
</p>
<p>For all users:</p>
<ul>
  <li>
    the <strong>REDUCE User&apos;s Manual</strong>
    <small>[ <a href="manual.html"
                title="a multi-page HTML document">HTML</a> |
      <a href="manual.pdf">PDF</a> ]</small> provides a comprehensive
    guide to the REDUCE language and the supported packages
    <small> [<a href="/manual-lookup.php">note on external
        linking</a>]</small>;
  </li>
  <li>
    the <a href="/switches.php">switch summary</a> provides an
    overview of the switches that control REDUCE.
  </li>
</ul>
<p>For advanced users:</p>
<ul>
  <li>
    <a href="/lisp-docs/insidereduce.pdf"><strong>Inside
        Reduce</strong></a> describes how to build REDUCE, the
        structure of the REDUCE source code, and some low-level
        programming features;
  </li>
  <li>
    the <strong>Symbolic Mode
      Primer</strong> <small>[ <a href="/lisp-docs/primer.html">HTML</a>
      | <a href="/lisp-docs/primer.pdf">PDF</a> ]</small> provides an
      introduction to programming in the REDUCE implementation
      language, RLISP, which is Standard Lisp with REDUCE (essentially
      ALGOL 60) syntax;
  </li>
  <li>
    the <strong>Standard Lisp
      Report</strong> <small>[ <a href="/lisp-docs/sl.html">HTML</a>
      | <a href="/lisp-docs/sl.pdf">PDF</a> ]</small> defines Standard
      Lisp, the dialect of Lisp assumed by REDUCE;
  </li>
  <li>
    the <strong>PSL Users Manual</strong>
    <small>[ <a href="/lisp-docs/allman1.html">HTML</a> |
      <a href="/lisp-docs/allman1.pdf">PDF</a> ]</small> documents
    Portable Standard Lisp, the original implementation of Standard
    Lisp;
  </li>
  <li>
    the <a href="/lisp-docs/csl.html"><strong>CSL
        Reference</strong></a> documents Codemist Standard Lisp, a
        later implementation of Standard Lisp.
  </li>
</ul>
<p id="contributed">
  The following documents for the user-contributed packages are
  dynamically generated links into the HTML version of the REDUCE
  User&apos;s Manual.
</p>
END_OF_MAIN_CONTENT
);

$smarty->display('documentation.tpl');

?>
