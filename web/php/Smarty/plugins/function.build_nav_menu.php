<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * Author:   Francis Wright
 * File:     function.build_nav_menu.php
 * Type:     function
 * Name:     build_nav_menu
 * Purpose:  returns the navigation menu as <ul> content
 * -------------------------------------------------------------
 */
function smarty_function_build_nav_menu($params, $smarty)
{
	global $filename;
	$filename = $_SERVER['PHP_SELF'];
    if (!$filename) $filename = '/index.php';
    # echo "**Filename: $filename**<br />";
    # echo "**Scriptname: " . __FILE__ . "**<br />";

    function menuItem($href, $label, $title = NULL) {
        global $filename;
        if ($href === $filename)
            echo "<li title=\"$title\" class=\"selected\">$label</li>\n";
        else {
            echo "<li title=\"$title\"><a href=\"$href\">$label</a></li>\n";
		}
    }

    menuItem('/index.php', 'Home', 'The REDUCE Computer Algebra System');
    menuItem('/features.php', 'Features', 'REDUCE features and design characteristics');
    menuItem('/obtaining.php', 'Obtaining REDUCE', 'Guidance on downloading REDUCE from SourceForge');
    menuItem('/documentation.php', 'Documentation', 'User guides for REDUCE, its packages and Lisp systems');
    menuItem('/books.php', 'Books', 'Books about REDUCE');
    menuItem('/support.php', 'Support', 'Answers to questions about using REDUCE');
    menuItem('/tutorials.php', 'Tutorials', 'Simple examples of using REDUCE');
    menuItem('/packages.php', 'External Packages', 'External packages that use REDUCE');
    menuItem('/helpwanted.php', 'Help Wanted!', 'Join the REDUCE developer community!');
    menuItem('/bibliography.php', 'Bibliography', 'Publications that reference REDUCE');
    menuItem('/about.php', 'About REDUCE', 'History and contributors');
    menuItem('/projects.php', 'Related Projects', 'Projects related to REDUCE');
}
?>
