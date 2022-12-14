<?php
$page_title = 'REDUCE IDE';
$header_title = 'REDUCE IDE';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>

<p>
    REDUCE IDE is a <a href="https://www.gnu.org">GNU</a>
    <a href="https://www.gnu.org/software/emacs/emacs.html">Emacs</a>
    package that provides an <b>I</b>ntegrated <b>D</b>evelopment <b>E</b>nvironment
    for REDUCE consisting of major modes for editing REDUCE source
    code and running a <strong>command-line version</strong> of REDUCE
    in an Emacs window. Many of the facilities require that Emacs is
    running under a GUI such as
    <a href="https://www.microsoft.com/en-gb/windows">Microsoft Windows</a>, or
    the <a href="https://www.x.org/wiki/">X Window System</a> under some flavour of
    <a href="https://en.wikipedia.org/wiki/Unix">UNIX</a> or
    <a href="https://en.wikipedia.org/wiki/Linux">Linux</a>.
</p>
<p>
    A user guide is available online in
    <a href="reduce-ide.pdf">PDF</a> and
    <a href="reduce-ide/index.html">HTML</a>, and various other
    formats can be generated from the GNU texinfo source file. Full
    source code is available from the
    <code>/trunk/generic/emacs</code>
    directory in the REDUCE subversion repository via a subversion
    client or
    <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/">directly
        using a web browser</a>. A README file provides further
    technical details.
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
        <code>reduce-ide</code>. If the option <code>package-archives</code>
        is not immediately available then you can access it via the
        customization group <code>package</code>.
    </li>
    <li>
        Run the Emacs package manager, which is available as an item
        towards the bottom of the <em>Options</em> menu. (Or you can
        run the command <code>list-packages</code>.) This should show
        the latest available version of the package <code>reduce-ide</code>,
        which you can install by clicking on it and then clicking the
        <em>Install</em> button. Whenever you run the Emacs package
        manager in future it should show if there is a new version of
        <code>reduce-ide</code> available, and allow you to install
        it.
    </li>
</ol>
<p>
    Installing the full package will automatically perform all
    necessary configuration and make REDUCE IDE ready to use (although
    you can customize REDUCE IDE if you wish). It should also install
    the documentation, so that if you start the Emacs info browser,
    REDUCE IDE should appear at the top of the Emacs topics (probably
    immediately above Emacs itself). You can browse info
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

<h2>Recent update history</h2>
<ul>
    <li>
        <strong>REDUCE IDE version 1.5</strong> (November 2017) should work with the latest
        versions of both REDUCE and GNU Emacs. It also provides full
        support for the GNU Emacs package manager (see above),
        explicit support for running both CSL and PSL REDUCE, and
        explicit support for running multiple REDUCE processes
        simultaneously.
    </li>
    <li>
        <strong>REDUCE IDE version 1.6</strong> (June 2022) provides better syntactic
        highlighting (fontification) and better delimiter matching, which
        are provided by two new files. It also repairs support for
        running PSL REDUCE on Microsoft Windows. I have tested REDUCE
        IDE 1.6 with REDUCE revision 6339 and GNU Emacs 28 on
        Microsoft Windows and Ubuntu.
    </li>
    <li>
        <strong>REDUCE IDE version 1.7</strong> (September 2022):
        <ul>
            <li><strong>INCOMPATIBLE CHANGE:</strong> The command <code>run-reduce</code> is
                now the only way to run REDUCE. It prompts for the REDUCE
                command name to run, defaulting to the last one used.</li>
            <li>The commands <code>run-csl-reduce</code> and <code>run-psl-reduce</code> have
                been removed; use <code>run-reduce</code> and select the
                appropriate command name instead.</li>
            <li>The customizable option <code>reduce-run-commands</code> now
                accepts arbitrary key strings and an arbitrary number of
                REDUCE versions.</li>
            <li>Improved access to the <code>comint</code> customization
                group (since REDUCE Run mode inherits from comint).</li>
            <li><code>&lt;RET&gt;</code> in REDUCE Run mode now adds a <code>;</code> statement
                terminator automatically as appropriate (whereas <code>S-&lt;RET&gt;</code> never
                adds a terminator).</li>
            <li>REDUCE mode now inherits from <code>prog-mode</code>,
                so it runs <code>prog-mode-hook</code> and
                some <code>prog-mode</code> customizations are relevant.</li>
            <li>Initial support for C-style <code>/**/</code> comments:
                they are now highlighted as comments and movement commands
                should skip them.</li>
            <li><strong>INCOMPATIBLE CHANGE:</strong> The command <code>reduce-eval-line</code> is
                now bound to the key sequence <code>C-c C-e</code> instead of <code>C-c C-n</code>,
                which was already bound to <code>reduce-forward-statement</code>.</li>
            <li>Improved code relating to all the commands that move by statements and expressions.</li>
            <li><strong>INCOMPATIBLE CHANGE:</strong> The customizable option <code>reduce-max-up-tries</code> is
                now called <code>reduce-max-escape-tries</code>.</li>
        </ul>
    </li>
    <li>
        <strong>REDUCE IDE version 1.8</strong> (October 2022):
        <ul>
            <li>Use lexical scoping, which might be a little faster.</li>
            <li><strong>INCOMPATIBLE CHANGE:</strong> The commands <code>reduce-forward-sexp</code> and
                <code>reduce-backward-sexp</code> no longer accept an argument and now skip any comments or white space,
                but <strong>not terminators</strong>, between point and the "balanced expression".
            </li>
            <li>Add the command <code>reduce-kill-sexp</code> to kill one "balanced expression" either forwards or, with
                any argument, backwards, bound to <code>C-M-k</code>.</li>
            <li>Reliably disregard ! as an escape character at the end of a string, which would otherwise mask the end
                of the string.</li>
            <li>Treat the escape character (!) as part of a word for motion commands.</li>
            <li>Use Emacs parsing in preference to heuristics to detect whether point is in a string or (% or /**/)
                comment.</li>
            <li>The command <code>reduce-kill-procedure</code> now accepts an argument.</li>
            <li>Operations based on procedures now support <code>matrixproc</code>, <code>listproc</code>, and procedure
                type declarations. They report a user error if they fail.</li>
            <li>Syntax Highlighting:
                <ul>
                    <li>More robust highlighting of comment statements.</li>
                    <li>There are now three strictly inclusive levels: “Symbolic” includes “Algebraic” includes “Basic”.
                    </li>
                    <li>Highlight group delimiters the same as block delimiters.</li>
                    <li>Highlight named constants such as Catalan.</li>
                    <li>Highlight symbolic-mode functions such as get and put as builtin functions.</li>
                    <li>Highlight lambda arguments the same as procedure arguments.</li>
                    <li>Fix some errors. Should be more robust and possibly slightly faster.</li>
                </ul>
            </li>
        </ul>
    </li>
    <li>
        <strong>REDUCE IDE version 1.9</strong> (October 2022):
        <ul>
            <li>Highlight fluid and global forms as variable type declarations rather than as quoted data.</li>
            <li>Some menu improvements.</li>
            <li>Indentation is now more reasonable.</li>
            <li><strong>INCOMPATIBLE CHANGE:</strong> The command <code>reduce-indent-line</code> is now idempotent and
                no longer successively indents. Hence, the option <code>reduce-indent-line-conservative</code> no longer
                exists.</li>
            <li>The command <code>reduce-indent-line</code> is now bound indirectly to <code>TAB</code> but is also
                bound directly to <code>M-i</code>, which allows it to be run with a prefix argument to indent the whole
                of the current statement rigidly.</li>
            <li>The new command <code>reduce-indent-line-always</code> bound to <code>C-TAB</code> indents by one step,
                and replaces the effect of executing <code>reduce-indent-line</code> repeatedly.</li>
            <li>The command <code>reduce-indent-procedure</code> preserves point and no longer leaves the procedure
                selected.</li>
        </ul>
    </li>
    <li>
        <strong>REDUCE IDE version 1.10</strong> (December 2022):
        <ul>
            <li>Fix a trivial compilation error on Linux.</li>
            <li>Parse comment statements robustly starting from the top of the buffer.</li>
            <li>Fontify multi-line <code>/**/</code> comments correctly.</li>
            <li>Support filling of <code>/**/</code> comments.</li>
            <li>Improve indentation.</li>
            <li>Treat REDUCE mode and REDUCE Run mode more as parts of an integrated REDUCE IDE package.
                <ul>
                    <li>Add a new option <code>autoload-reduce-run</code> to control whether, and if so how, to autoload
                        REDUCE Run mode.</li>
                    <li>Remove <code>require-reduce-run</code> as an option on <code>reduce-mode-load-hook</code>.</li>
                    <li><strong>Note that <code>require-reduce-run</code> is now deprecated and will be removed in the
                            next release</strong>; please use <code>autoload-reduce-run</code> instead.</li>
                    <li>Optionally include in REDUCE mode buffers either the full Run REDUCE menu or a Run REDUCE menu
                        stub, which can only run REDUCE or explicitly load REDUCE Run mode. Replace the stub with the
                        full menu when REDUCE Run mode loads.</li>
                </ul>
            </li>
        </ul>

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
