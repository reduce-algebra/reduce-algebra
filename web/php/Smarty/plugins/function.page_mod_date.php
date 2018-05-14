<?php
/*
 * Smarty plugin
 * -------------------------------------------------------------
 * Author:   Francis Wright
 * File:     function.page_mod_date.php
 * Type:     function
 * Name:     page_mod_date
 * Purpose:  returns the last modified date of the current page
 * -------------------------------------------------------------
 */
function smarty_function_page_mod_date($params, $smarty)
{
	return date('l jS F Y', filemtime($_SERVER['SCRIPT_FILENAME']));
}
?>
