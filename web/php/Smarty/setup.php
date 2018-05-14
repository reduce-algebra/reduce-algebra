<?php

// load Smarty library
require_once('Smarty.class.php');

// The setup.php file is a good place to load
// required application library files, and you
// can do that right here. An example:
// require('guestbook/guestbook.lib.php');

class Smarty_REDUCE extends Smarty {

	function __construct()
	{

        // Class Constructor.
        // These automatically get set with each new instance.

        parent::__construct();

        $this->setTemplateDir(SMARTY_DIR . '../../smarty/templates/');
        $this->setCompileDir(SMARTY_DIR . '../../smarty/templates_c/');
        $this->setConfigDir(SMARTY_DIR . '../../smarty/configs/');
        $this->setCacheDir(SMARTY_DIR . '../../smarty/cache/');

        // $this->caching = Smarty::CACHING_LIFETIME_CURRENT;
        // $this->assign('app_name', 'Guest Book');
	}

}
?>
