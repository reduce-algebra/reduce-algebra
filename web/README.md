# Files for the REDUCE web site #

**Francis Wright, October 2026**

The REDUCE web site is hosted by SourceForge at the URL <https://reduce-algebra.sourceforge.io> and can also be accessed using the URLs <http://reduce-algebra.sourceforge.net>, <http://www.reduce-algebra.com> and <http://reduce-algebra.com>, which are DNS aliases.  The `reduce-algebra.com` domain is paid for by Tony Hearn.

This directory, namely `trunk/web`, in the Subversion repository corresponds to the directory `/home/project-web/reduce-algebra` on the SourceForge web server and is the parent of the web server document root directory, `htdocs`.  Note that only the sub-directory `htdocs` can be accessed.  Not all files and directories on the web server are committed to the repository.  Files that are missing can be obtained, or generated from files available, elsewhere in the repository.  In particular, the main REDUCE-related documentation files can be generated from source files in the repository at `trunk/doc`.

The primary technologies used to support this web site are [PHP](https://www.php.net), the [Bootstrap](https://getbootstrap.com/) front-end toolkit and the [jQuery](https://jquery.com/) library.  Bootstrap and jQuery are loaded dynamically from CDNs.  The main HTML files are generated from PHP source files by running the Bash script `./build.sh` in this directory.  This requires the CLI version of PHP (see <https://www.php.net/manual/en/features.commandline.php>) to be installed locally and the command `php` to be on your PATH.  The PHP files (and hence the directory `htdocs/include`) are *not* uploaded to the server.  All other files and directories, including all the generated HTML files, are uploaded by running the Bash script `./rsync-web.sh` in this directory.  It is advisable to run this script first with the argument `-n`, which does a "dry run", to check what will actually be uploaded.

The Bash script `./copy-manual.sh` copies the PDF, HTML and image files required for the REDUCE manual from `../doc/manual` to `htdocs/manual`, from where they can be uploaded to the server by running the Bash script `./rsync-web.sh`.

## Style and JavaScript files ##

The web site uses the Bootstrap style file and a local style file `htdocs/StyleSheet.css`, which are loaded in the head element defined in `htdocs/include/begin-head.php`.

The Bootstrap JavaScript library is loaded at the bottom of the general page footer defined in `htdocs/include/footer.php`.  Several pages use a few lines of JavaScript (mainly using the jQuery library, which they load) in a script element below where `htdocs/include/footer.php` is included.  The tutorial and Web REDUCE pages use the [MathJax](https://www.mathjax.org/) JavaScript library. (The HTML REDUCE manual pages also use MathJax, but these are generated independently of the main web pages.)

## Search ##

The search facility uses a [Google Custom Search Engine](https://cse.google.com/cse/) (CSE) based in my private Google account.  (Beware that this is now called Programmable Search!)  The directory `trunk/web/search` in the Subversion repository contains two files, `annotations.xml` and `cse.xml`, which specify respectively what Google calls the CSE annotations and the CSE context.  (They are **not** required on the web server.)  These two files show how the custom search is configured: the annotations are a list of included and excluded web sites; the context is the look and feel (i.e. layout and styling).  This information may be useful if the search facility needs to be moved to a new Google account, and it should be possible to upload the two files to configure a new custom search, although they might need some editing first.

## Local development and testing ##

I develop and test updates to the REDUCE web site using a local server, such as that provided by running `python -m http.server` in the `htdocs` directory.  I normally update the REDUCE web site using `rsync` (see above).  I sometimes also do a little interactive maintenance, such as deleting obsolete files, using `SFTP`, for which I use the [FileZilla](https://filezilla-project.org/) Client for Windows.  The protocols available for maintaining a SourceForge web site are described in the SourceForge [Site Documentation](https://sourceforge.net/p/forge/documentation/Project%20Web%20Services/).

<!-- Local Variables: -->
<!-- fill-column: 1000 -->
<!-- eval: (auto-fill-mode -1) -->
<!-- eval: (visual-line-mode 1) -->
<!-- eval: (visual-wrap-prefix-mode 1) -->
<!-- End: -->
