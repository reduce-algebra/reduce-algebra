<?php
$page_title = 'REDUCE IDE';
$header_title = 'REDUCE IDE';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>

<p>
    REDUCE IDE is a package that provides an
    <u>I</u>ntegrated <u>D</u>evelopment <u>E</u>nvironment for the
    <a>REDUCE</a> computer algebra system within the
    <a href="http://www.gnu.org/">GNU</a> <a href="http://www.gnu.org/software/emacs/emacs.html">Emacs</a>
    editor.  Its two major components are Emacs Lisp libraries that
    provide major modes for respectively editing REDUCE source code
    and running a <strong>command-line version</strong>
    of REDUCE in an Emacs window.  Many of the facilities require that
    Emacs is running under a GUI such as
    <a href="http://windows.microsoft.com/">Microsoft Windows</a>, or
    the <a href="http://www.x.org/">X Window System</a> under some flavour of
    <a href="http://en.wikipedia.org/wiki/Unix">UNIX</a> or
    <a href="http://en.wikipedia.org/wiki/Linux">Linux</a>.
</p>
<p>
    A user guide is available online in
    <a href="reduce-ide.pdf">PDF</a> and
    <a href="reduce-ide/index.html">HTML</a>, and various other
    formats can be generated from the GNU texinfo source file.  Full
    source code is available from the
    <code>/trunk/generic/emacs</code>
    directory in the REDUCE subversion repository via a subversion
    client or
    <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/">directly
        using a web browser</a>.  A README file provides further
    technical details.
</p>
<p>
    REDUCE IDE requires GNU Emacs 23 or later, although I recommend
    version 25 or later.  There is currently no explicit support for
    <a href="http://www.xemacs.org/">XEmacs</a>.
</p>
<h2>Major update history</h2>
<p>
    REDUCE IDE version 1.5 (Nov 2017) should work with the latest
    versions of both REDUCE and GNU Emacs.  It also provides full
    support for the GNU Emacs package manager (see below), explicit
    support for running both CSL and PSL REDUCE, and explicit support
    for running multiple REDUCE processes simultaneously.
</p>
<h2>Installation</h2>
<p>
    Provided you are using GNU Emacs 24 or later, I recommend that you
    install the latest complete REDUCE IDE package, which includes
    documentation in GNU info format, as follows.
</p>
<ol>
    <li>
        Customize the Emacs user option <code>package-archives</code>
        to add a new archive with the URL
        <code>https://reduce-algebra.sourceforge.io/reduce-ide/packages/</code>.
        You can give this archive any name you like, such as
        <code>reduce-ide</code>.  If the option <code>package-archives</code>
        is not immediately available then you can access it via the
        customization group <code>package</code>.
    </li>
    <li>
        Run the Emacs package manager, which is available as an item
        towards the bottom of the <em>Options</em> menu.  (Or you can
        run the command <code>list-packages</code>.)  This should show
        the latest available version of the package <code>reduce-ide</code>,
        which you can install by clicking on it and then clicking the
        <em>Install</em> button.  Whenever you run the Emacs package
        manager in future it should show if there is a new version of
        <code>reduce-ide</code> available, and allow you to install
        it.
    </li>
</ol>
<p>
    Installing the full package will automatically perform all
    necessary configuration and make REDUCE IDE ready to use (although
    you can customize REDUCE IDE if you wish).  It should also install
    the documentation, so that if you start the Emacs info browser,
    REDUCE IDE should appear at the top of the Emacs topics (probably
    immediately above Emacs itself).  You can browse info
    documentation in Emacs via the menu item
    <em>Help / More Manuals / All Other Manuals (Info)</em>
    or via the key sequence <em>C-h i</em>.
</p>
<p>
    An alternative way to install the latest complete REDUCE IDE
    package is to open the <a href="packages/">REDUCE IDE packages
    directory</a> in a web browser, download the latest
    <code>reduce-ide</code> package file (which will have a name of the form
    <code>reduce-ide-<em>version</em>.tar</code>), then run the Emacs command
    <code>package-install-file</code> and give it the full pathname of the
    <code>reduce-ide</code> package file you just downloaded.
</p>
<p>Feedback is welcome.</p>
<address>
    <a href="https://sites.google.com/site/fjwcentaur/feedback">Francis Wright</a>
</address>

</div><!-- opened in begin-body.php -->

<?php
include '../include/footer.php';
?>

</body>
</html>
