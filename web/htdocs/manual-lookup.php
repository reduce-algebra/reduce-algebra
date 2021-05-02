<?php  // -*-mhtml-*-

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
<style type="text/css">
  body {
      display: none;
  }
  #form {
      text-align: center;
  }
  #Text1 {
      width: 250px;
  }
</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'Manual Page Look-Up');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>
  Internal links within the HTML version of the REDUCE manual should
  not be used externally because they may change when the manual is
  rebuilt from source, which typically happens a few times a year.
  Instead, use a URL of the form
  <a href="#"><span class="href"></span>?<em>query string</em></a>,
  where <em>query string</em> is any (case-sensitive) string of
  characters that appears uniquely in the title of an entry in
  the <a href="/manual/manual.html">REDUCE manual table of
  contents</a>.  (Don&apos;t use section numbers, which may change.)
  For example, these links should reliably access appropriate sections
  of the manual describing <strong>User Contributed Packages</strong>:
</p>
<ul>
  <li><a href="?EXCALC"><span class="href"></span>?EXCALC</a></li>
  <li><a href="?GROEBNER"><span class="href"></span>?GROEBNER</a></li>
  <li><a href="?LINALG"><span class="href"></span>?LINALG</a></li>
  <li><a href="?ODESOLVE"><span class="href"></span>?ODESOLVE</a></li>
  <li><a href="?REDLOG"><span class="href"></span>?REDLOG</a></li>
  <li><a href="?ROOTS"><span class="href"></span>?ROOTS</a></li>
</ul>
<p>
  Alternatively, for interactive experimentation, enter a <em>query
    string</em> in the field below and hit <em>Enter</em> or click on
    the <em>Go</em> button.
</p>
<p id="form">
  <input id="Text1" type="text" placeholder="query string" />
  <input id="Button1" type="button" value="Go" />
</p>
<p>
  If a query string is not found then the
  <a href="/manual/manual.html">REDUCE manual table of
  contents</a> is displayed.
</p>
END_OF_MAIN_CONTENT
);

$smarty->display('manual-lookup.tpl');

?>
