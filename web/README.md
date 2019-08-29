Files for the REDUCE web site
=============================

Francis Wright, August 2019

The REDUCE web site can be accessed using the URLs
[https://reduce-algebra.sourceforge.io/](https://reduce-algebra.sourceforge.io/),
[http://reduce-algebra.com](http://reduce-algebra.com), etc.

This directory, namely `trunk/web`, in the Subversion repository
corresponds to the directory `/home/project-web/reduce-algebra/` on
the SourceForge web server and is the parent of the web server
document root directory, `htdocs`.  The main directory structure on
the web server is as shown below but not all files and directories are
checked into the repository.  Files that are missing from the
repository can be obtained elsewhere or generated from files available
elsewhere in the repository.  In particular, the main REDUCE-related
documentation files can be generated from source files in the
repository at `trunk/doc`.

The primary technology used to support this web site is the
[Bootstrap](https://getbootstrap.com/) CSS framework and I use the
Smarty template engine to facilitate consistent use of Bootstrap.  The
general setup is described in more detail below.

Web server directory structure
------------------------------

	+---htdocs
	|       Data files for the web pages
	|               
	+---php
	|   +---SimplePie
	|   |       PHP source code, all available from elsewhere
	|   \---Smarty
	|           PHP source code, mostly available from elsewhere
	|               
	+---simplepie
	|   \---cache
	|           Files written by the web server
	|           
	\---smarty
	    +---templates
	    |       Template files for the web pages
	    \---templates_c
	            Files written by the web server

PHP libraries
-------------

I use the [SimplePie](http://simplepie.org/) PHP library to display
RSS feeds.  It is installed in the `php` directory (see above) on the
REDUCE web site and is currently at version 1.5 (released on 17 April
2017).

I use the [Smarty](https://www.smarty.net/) PHP template engine to
manage the main structure of the web site.  It is installed in the
`php` directory (see above) on the REDUCE web site and is currently at
version 3.1.33 (released on 17 September 2018).  To update Smarty,
copy everything except the file `SmartyBC.class.php` in the `libs`
folder in the distributed archive to the web server directory
`php/Smarty`.  Beware that I have added the file `setup.php`, which is
required to configure Smarty, and a few files in the `plugins`
directory.  Don't delete these files or simply replace the whole
Smarty directory!  The main structural page markup is stored in Smarty
template files, into which the data in the web pages in `htdocs` is
inserted by Smarty.

The directory `simplepie` contains the SimplePie cache directory and
the directory `smarty` contains the Smarty templates and cached
templates.  The source for the templates is in the `smarty/templates`
directory, although the web server uses the cached versions in the
`smarty/templates_c` directory.  It seems that directories that need
to be writable by the web server, such as these cache directories,
must be outside the `htdocs` directory.

Style and JavaScript files
--------------------------

The web site uses two style files, which are loaded in the head
section of the file `smarty/templates/main.tpl`.  These are the
Bootstrap style file, which is loaded from a remote server, and the
local style file `htdocs/StyleSheet.css`.

The web site uses several JavaScript libraries, which are loaded from
remote servers at the bottom of the template files (in
`smarty/templates`) for pages that need them, followed sometimes by a
very small amount of local code.  The Bibliography, Support and
Tutorial pages use the jQuery, Popper and Bootstrap JavaScript
libraries (see
[https://getbootstrap.com/](https://getbootstrap.com/)), which are
included from the file `bootstrap-js.tpl` in the JavaScript section at
the bottom of the appropriate template files.  The Bootstrap CSS and
JS files are at version 4.3.1 and the jQuery and Popper libraries are
at the versions recommended for use with this version of Bootstrap.
The Tutorial page also uses the [MathJax](https://www.mathjax.org/)
JavaScript library and it uses the latest version automatically.

Local development and testing
-----------------------------

I develop and test updates to the REDUCE web site on a local server
that matches the configuration of the SourceForge server as closely as
possible.  For this I currently use
[XAMPP](https://www.apachefriends.org/index.html) for Windows 7.1.31
(with only Apache and PHP installed).  I normally update the REDUCE
web site using `rsync`, taking care not to overwrite any files updated
by other developers, such as those in the `htdocs/manual` directory!
I sometimes also do a little interactive maintenance, such as deleting
obsolete files, using SFTP, for which I use the
[FileZilla](https://filezilla-project.org/) Client for Windows.  The
protocols available for maintaining a SourceForge web site are
described in the SourceForge [Site
Documentation](https://sourceforge.net/p/forge/documentation/Project%20Web%20Services/).
