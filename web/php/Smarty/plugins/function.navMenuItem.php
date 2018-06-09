<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * Author:   Francis Wright
 * File:     function.navMenuItem.php
 * Type:     function
 * Name:     navMenuItem
 * Purpose:  return one navigation menu list item
 * -------------------------------------------------------------
 */
function smarty_function_navMenuItem($params, $smarty)
{
	global $filename;
	# Constant for all menu items on the same page, so only set once.
	if (!$filename) {
		$filename = $_SERVER['PHP_SELF'];
		# echo "**Filename: $filename**<br />";
	}
	$href = $params['href'];
	$label = $params['label'];
	$title = $params['title'];
    if ($href === $filename)
        echo "<li title=\"$title\" class=\"selected\">$label</li>\n";
    else {
        echo "<li title=\"$title\"><a href=\"$href\">$label</a></li>\n";
	}
}
?>
