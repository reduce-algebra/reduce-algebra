Files for the REDUCE web site
=============================

Francis Wright, May 2021

The REDUCE web site can be accessed using the URLs [https://reduce-algebra.sourceforge.io/](https://reduce-algebra.sourceforge.io/), [http://reduce-algebra.com](http://reduce-algebra.com), [http://www.reduce-algebra.com](http://www.reduce-algebra.com), etc. (where the latter are DNS aliases and the reduce-algebra.com domain is paid for by Tony Hearn).

This directory, namely `trunk/web`, in the Subversion repository corresponds to the directory `/home/project-web/reduce-algebra/` on the SourceForge web server and is the parent of the web server document root directory, `htdocs`.  The main directory structure on the web server is as shown below but not all files and directories are checked into the repository.  Files that are missing from the repository can be obtained elsewhere or generated from files available elsewhere in the repository.  In particular, the main REDUCE-related documentation files can be generated from source files in the repository at `trunk/doc`.

The primary technology used to support this web site is PHP, jQuery and the Bootstrap front-end toolkit.  The general setup is described in more detail below.

Web server directory structure
------------------------------

	+---htdocs
	|   |   PHP code and data files for the web pages
    |   \---include
    |           Incomplete PHP code files included in other files
	|
	+---php
	|   \---SimplePie
	|           PHP source code, all available from elsewhere
	|
	\---simplepie
	    \---cache
	            Files written by the web server (PHP)

PHP libraries
-------------

I use the [SimplePie](http://simplepie.org/) PHP library to display RSS feeds.  It is installed in the `php` directory (see above) on the REDUCE web server and is currently at version 1.5 (released on 17 April 2017).

The directory `simplepie` contains the SimplePie cache directory.  It seems that directories that need to be writable by the web server, such as this cache directory, must be outside the `htdocs` directory.

Style and JavaScript files
--------------------------

These are loaded in include files.  The web site uses two style files, which are loaded in the head element in `htdocs/include/begin-head.php`.  These are the Bootstrap style file, which is loaded dynamically from `cdn.jsdelivr.net`, and the local style file `htdocs/StyleSheet.css`.

The [jQuery](https://jquery.com/) and [Bootstrap](https://getbootstrap.com/) JavaScript libraries are loaded at the bottom of `htdocs/include/footer.php`.  jQuery is at version 3.6.0 and Bootstrap is at version 4.6.0.  The tutorial pages also use the latest version (automatically) of the [MathJax](https://www.mathjax.org/) JavaScript library and several pages use a few lines of local JavaScript (mainly jQuery) in a script element below where `htdocs/include/footer.php` is included.  (The HTML REDUCE manual pages also use MathJax, but these are independent HTML pages outside the main PHP framework; see below.)

Search
------

The search facility uses a [Google Custom Search Engine](https://cse.google.com/cse/) (CSE) based in my private Google account.  The directory `trunk/web/search` in the Subversion repository contains two files, `annotations.xml` and `cse.xml` that specify respectively what Goolge calls the CSE annotations and the CSE context.  (They are **not** required on the web server.)  These two files show how the custom search is configured: the annotations are a list of included and excluded web sites; the context is the look and feel (i.e. layout and styling).  This information may be useful if the search facility needs to be moved to a new Google account, and it should be possible to upload the two files to configure a new custom search, although they might need some editing first.

Local development and testing
-----------------------------

I develop and test updates to the REDUCE web site on a local server that matches the configuration of the SourceForge server as closely as possible.  For this I currently use [XAMPP](https://www.apachefriends.org/index.html) for Windows 7.1.31 (with only Apache and PHP installed).  I normally update the REDUCE web site using `rsync`, taking care not to overwrite any files updated by other developers, such as those in the `htdocs/manual` directory!  I sometimes also do a little interactive maintenance, such as deleting obsolete files, using SFTP, for which I use the [FileZilla](https://filezilla-project.org/) Client for Windows.  The protocols available for maintaining a SourceForge web site are described in the SourceForge [Site Documentation](https://sourceforge.net/p/forge/documentation/Project%20Web%20Services/).

REDUCE manual
-------------

The PDF and HTML versions of the REDUCE manual are built separately and normally uploaded directly to the web server.  I currently zip the manual directory (containing only the files required on the server), upload the zip archive to SourceForge using SFTP, log in to SourceForge, unzip the archive to the directory `manual.new`, move `manual` to `manual.old`, move `manual.new` to `manual`, and then check the web site using a web browser.
