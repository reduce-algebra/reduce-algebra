<?php  // -*-mhtml-*-

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'Search the REDUCE Web Site');

$smarty->assign('header_title', 'Search the REDUCE Web Site');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<script async src="https://cse.google.com/cse.js?cx=016704250287712503695:oxb7ffjizr2"></script>
<div class="gcse-search"></div>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
