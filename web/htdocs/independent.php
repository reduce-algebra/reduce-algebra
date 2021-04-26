<?php  // -*-mhtml-*-

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'Independent Distributions of REDUCE');

$smarty->assign('header_title', 'Independent Distributions');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>
  We encourage independent distributions of REDUCE for platforms that
  the main developers do not provide. This page lists those that we
  know about. Please let us know about updates to this list by email
  to
  the <a href="https://sourceforge.net/users/fjwright/">webmaster</a>.
</p>
<ul>
  <li>
    <a href="https://aur.archlinux.org/pkgbase/reduce-svn/">Arch Linux (via AUR)</a>
  </li>
  <li>
    <a href="https://slackbuilds.org/repository/14.2/academic/reduce-algebra/">Slackware (via Slackbuilds)</a>
  </li>
</ul>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
