# Files for the REDUCE web site #

**Francis Wright, January 2025**

The REDUCE web site is hosted at the URL [https://reduce-algebra.sourceforge.io](https://reduce-algebra.sourceforge.io) and can also be accessed using the URLs [http://reduce-algebra.sourceforge.net](http://reduce-algebra.sourceforge.net), [http://www.reduce-algebra.com](http://www.reduce-algebra.com) and [http://reduce-algebra.com](http://reduce-algebra.com), which are DNS aliases. The `reduce-algebra.com` domain is paid for by Tony Hearn.

This directory, namely `trunk/web`, in the Subversion repository corresponds to the directory `/home/project-web/reduce-algebra` on the SourceForge web server and is the parent of the web server document root directory, `htdocs`.  The main directory structure on the web server is as shown below but not all files and directories are checked into the repository.  Files that are missing from the repository can be obtained elsewhere or generated from files available elsewhere in the repository.  In particular, the main REDUCE-related documentation files can be generated from source files in the repository at `trunk/doc`.

The primary technology used to support this web site is [PHP](https://www.php.net), the [Bootstrap](https://getbootstrap.com/) front-end toolkit and the [jQuery](https://jquery.com/) library. PHP is provided by SourceForge, and Bootstrap and jQuery are loaded dynamically from CDNs. The general setup is described in more detail below.

## Web server directory structure ##

~~~
    +---htdocs
    |   |   PHP code and data files for the web pages
    |   \---include
    |           Incomplete PHP code files included in other files
    \---sitemap
            Cache file written by the web server (PHP)
~~~

It seems that directories that need to be writable by the web server, namely the sitemap cache directory, must be outside the `htdocs` directory and have the correct permissions explicitly set; see [Project Web Filesystem Permissions](https://sourceforge.net/p/forge/documentation/Project%20Web%20Filesystem%20Permissions/).

## Style and JavaScript files ##

The web site uses the Bootstrap style file and a local style file `htdocs/StyleSheet.css`, which are loaded in the head element in `htdocs/include/begin-head.php`.

The Bootstrap JavaScript library is loaded at the bottom of `htdocs/include/footer.php`.  Several pages use a few lines of JavaScript (mainly using the jQuery library, which they load) in a script element below where `htdocs/include/footer.php` is included. The tutorial and Web REDUCE pages use the [MathJax](https://www.mathjax.org/) JavaScript library. (The HTML REDUCE manual pages also use MathJax, but these are independent HTML pages outside the main PHP framework; see below.)

## Search ##

The search facility uses a [Google Custom Search Engine](https://cse.google.com/cse/) (CSE) based in my private Google account.  (Beware that this is now called Programmable Search!)  The directory `trunk/web/search` in the Subversion repository contains two files, `annotations.xml` and `cse.xml`, which specify respectively what Google calls the CSE annotations and the CSE context.  (They are **not** required on the web server.)  These two files show how the custom search is configured: the annotations are a list of included and excluded web sites; the context is the look and feel (i.e. layout and styling).  This information may be useful if the search facility needs to be moved to a new Google account, and it should be possible to upload the two files to configure a new custom search, although they might need some editing first.

## Local development and testing ##

I develop and test updates to the REDUCE web site on a local server that matches the configuration of the SourceForge server as closely as possible.  For this I currently use [XAMPP](https://www.apachefriends.org/index.html) for Windows 7.1.31 (with only Apache and PHP installed).  I normally update the REDUCE web site using `rsync`.  I sometimes also do a little interactive maintenance, such as deleting obsolete files, using `SFTP`, for which I use the [FileZilla](https://filezilla-project.org/) Client for Windows.  The protocols available for maintaining a SourceForge web site are described in the SourceForge [Site Documentation](https://sourceforge.net/p/forge/documentation/Project%20Web%20Services/).

## REDUCE manual ##

The `PDF` and `HTML` versions of the REDUCE manual are built separately and normally uploaded directly to the web server (not using `rsync`).  I currently copy the required manual `HTML` and `PDF` files from the documentation directory (`doc/manual`) to the web directory (`web/htdocs/manual`) and check them using a local web server.  I then zip the manual directory, upload the zip archive to SourceForge using `SFTP` or `scp`, log in to SourceForge using `ssh`, unzip the archive to the directory `manual.new`, move `manual` to `manual.old`, move `manual.new` to `manual`, and then check the web site using a web browser.

This process can be automated by running the following `bash` commands in this directory (actually, the first three locally and the last at SourceForge):

``` bash
./copy-manual.sh
./upload-manual.sh
ssh -t fjwright@shell.sourceforge.net create
/home/project-web/reduce-algebra/unzip-manual.sh
```

Replace `fjwright` by your Sourceforge username.  The bash script `copy-manual.sh` copies the required manual `HTML` and `PDF` files from `doc/manual` to `htdocs/manual`.  The bash script `upload-manual.sh` zips and uploads `htdocs/manual` and then displays the instruction to run the last two commands.  This process assumes that your SSH key is posted to SourceForge so that no explicit authentication is required; see <https://sourceforge.net/p/forge/documentation/SSH%20Keys/>.  The final manual step is necessary because it seems that operations at SourceForge can only be done interactively.  Note that the file `unzip-manual.sh` in this directory needs to be (and has been) uploaded to Sourceforge.

<!-- Local Variables: -->
<!-- fill-column: 1000 -->
<!-- eval: (auto-fill-mode -1) -->
<!-- eval: (visual-line-mode 1) -->
<!-- eval: (visual-wrap-prefix-mode 1) -->
<!-- End: -->
