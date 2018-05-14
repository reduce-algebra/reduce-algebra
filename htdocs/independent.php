<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'Independent Distributions of REDUCE');

$smarty->assign('header_title', 'Independent Distributions');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>
	We encourage independent distributions of REDUCE for platforms that the main developers do not provide. This page lists those that we know about. Please let us know about updates to this list by email to the <a href="https://sourceforge.net/users/fjwright/">webmaster</a>.
</p>
<h2>Arch Linux (via AUR):</h2>
<ul>
	<li>
		<a href="https://aur.archlinux.org/packages/reduce-common-svn/">https://aur.archlinux.org/packages/reduce-common-svn/</a>
	</li>
	<li>
		<a href="https://aur.archlinux.org/packages/reduce-csl-svn/">https://aur.archlinux.org/packages/reduce-csl-svn/</a>
	</li>
	<li>
		<a href="https://aur.archlinux.org/packages/reduce-psl-svn/">https://aur.archlinux.org/packages/reduce-psl-svn/</a>
	</li>
</ul>
<h2>Slackware (via Slackbuilds):</h2>
<ul>
	<li>
		<a href="https://slackbuilds.org/result/?search=reduce-algebra">https://slackbuilds.org/result/?search=reduce-algebra</a>
	</li>
</ul>
END_OF_MAIN_CONTENT
);

$smarty->display('secondary.tpl');

?>
