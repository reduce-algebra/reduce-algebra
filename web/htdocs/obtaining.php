<?php
$page_title = 'Obtain and Run REDUCE';
$header_title = 'How to Obtain and Run REDUCE';
include 'include/begin-head.php';
?>

<style type="text/css">
 #main img.sflogo {
     float: none;
     margin: auto;
 }
</style>

<?php
include 'include/begin-body.php';
?>

<p>
    The REDUCE computer algebra system is released free-of-charge
    under a modified BSD <a href="license.php">license</a> and can be
    obtained in <a href="versions.php">two main versions</a> from
    <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
        <img class="sflogo" alt="SourceForge"
             src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>.
        There are also
    <a href="independent.php">independent distributions</a>
    available for some platforms not explicitly supported by the
    REDUCE developers.  This page explains how to download, install
    and run REDUCE on the most widely-used platforms.  (Alternative
    user interfaces such as
    <a href="https://fjwright.github.io/Run-REDUCE/">Run-REDUCE</a>
    or
    <a href="https://www.texmacs.org/">TeXmacs</a> must be installed
    separately; see their own documentation.)
</p>

<h2>The easy way to obtain REDUCE</h2>
<p>
    Download and install a pre-packaged REDUCE distribution that
    contains all the necessary binary files as well as documentation
    (and the main REDUCE source code).  We currently distribute REDUCE
    in this way primarily for Microsoft Windows, Apple MacOS and
    versions of GNU/Linux based on Debian and Red Hat.  This approach
    should work well if you use a supported platform and don&apos;t
    need the very latest updates.  Simply click on
    the <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
    <img class="sflogo" alt="SourceForge"
         src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>
    logo to visit the project page and then, towards the top of the
    page, you should see a large green button containing the word
    Download.  SourceForge uses heuristics to pick the most
    appropriate distribution file for your platform automatically
    (although it might get it wrong, especially for GNU/Linux).  If
    you hover over the Download button then a title should pop up that
    includes the filename explained below.
</p>
<p>
    Note that we do not provide any automatic update facility; to
    update REDUCE just install it again.  This is probably a good idea
    every year or so, or if you have encountered errors (especially
    ones we claim to have fixed).
</p>

<h3>Using Microsoft Windows and Apple MacOS</h3>
<p>
    Hovering over the <a href="https://sourceforge.net/p/reduce-algebra/"
                         rel="nofollow">
    <img class="sflogo" alt="SourceForge"
         src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>
    Download button should pop up a title including a filename of the form
</p>
<ul>
    <li><code>Reduce-Setup_<em>nnnn</em>.exe</code> on Microsoft Windows</li>
    <li><code>Reduce-snapshot_<em>nnnn</em>.dmg</code> on Apple MacOS</li>
</ul>
<p>
    where <em>nnnn</em> represents the revision number.
</p>
<p>
    Download the recommended file to your computer and install REDUCE
    in the normal way: on Windows, double-click on the installer file
    to execute it; on MacOS, double-click on the installer file to
    open it and then drag the REDUCE icon to your Applications folder.
    This process will install the CSL and/or PSL versions of REDUCE,
    which you can then run like any other application; for example, on
    Windows the Start menu will contain a folder called Reduce that
    contains applications called CSL Reduce and/or PSL Reduce, which
    you can run by clicking on them &ndash; <a href="#windetails">more
    details of installing and running REDUCE on Windows are available
    below</a>.
</p>

<h3>Using GNU/Linux</h3>
<p>
    Hovering over the <a href="https://sourceforge.net/p/reduce-algebra/"
                         rel="nofollow">
    <img class="sflogo" alt="SourceForge"
         src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>
    Download button should pop up a title including a filename of the form
</p>
<ul>
    <li><code>reduce-complete_<em>nnnn</em>_amd64.deb</code> on
        Debian-based Linux (e.g. Ubuntu)</li>
    <li><code>reduce-complete-<em>nnnn</em>-1.x86_64.rpm</code> on
        Red Hat-based Linux (e.g. Fedora and openSUSE)</li>
</ul>
<p>
    where <em>nnnn</em> represents the revision number (and amd64 or
    x86_64 represents the architecture &ndash; we only support 64-bit
    processors).
</p>
<p>
    Download the recommended file to your computer, open the Downloads
    folder and install REDUCE in the normal way, e.g. double-click on
    the installer file and then click on the Install button.  This
    process will install both the CSL and PSL versions of REDUCE,
    which you can then run like any other application.
</p>
<p>
    To run REDUCE on GNU/Linux, first open a Terminal window.  Then
    executing <code>redpsl</code> will start PSL REDUCE with a command
    line interface (CLI), whereas executing <code>redcsl</code> will
    start REDUCE with a graphical user interface (GUI), although
    executing <code>redcsl --nogui</code> will start CSL REDUCE with a
    CLI.  (The commands <code>redpsl</code> and <code>redcsl</code>
    are shell scripts installed in <code>/usr/bin</code>, which run
    binary files installed in <code>/usr/lib/reduce</code>.)  The CLI
    version of CSL REDUCE provides input history, blue prompts and red
    input.
</p>
<p>
    The commands <code>rfpsl</code> and <code>rfcsl</code> run the
    Redfront versions of, respectively, PSL and CSL REDUCE, which both
    provide the same consistent CLI with input history, red prompts
    and input, and blue algebraic-mode output.
</p>

<h3>Using the Files tab</h3>
<p>
    If the above guidance does not work or does not meet your
    requirements then ignore the default download file and proceed as
    follows.  Below the green Download button is a tab labelled Files
    and clicking on it takes you to a page offering REDUCE snapshots
    listed by date over several years.  Recent snapshots normally
    contain folders labelled <strong>windows</strong>,
    <strong>macintosh</strong> and <strong>linux64</strong>, which
    contain respectively the Microsoft Windows, Apple MacOS and
    GNU/Linux distribution files as described above, plus a generic
    source code bundle in the form of a
    <a href="https://en.wikipedia.org/wiki/Tar_(computing)">compressed
        tar file</a>.
</p>
<p>
    The distribution for GNU/Linux includes <a>compressed tar files</a>
    as well as
    <a href="https://en.wikipedia.org/wiki/Deb_(file_format)">.deb</a>
    and <a href="https://en.wikipedia.org/wiki/Rpm_(software)">.rpm</a>
    files.  If you don&apos;t find a GNU/Linux distribution here that
    you can use then please check the
    <a href="independent.php">independent distributions</a>.  But
    beware that some of these distributions may be quite old.
</p>

<h3>Using other platforms</h3>
<p>
    On a platform for which we do not currently provide REDUCE
    distributions, such as Android, the green box will instead be blue
    and labelled Browse Code. Clicking on it takes you to the
    Subversion code repository, where you might find source code for a
    particular platform.
</p>

<h2>Testing your REDUCE installation</h2>
<p>
    For a very quick test that REDUCE is working, you might try typing
    the following lines of input to successive REDUCE input prompts in
    either the windowed or the command-line version:
</p>
<pre><code>x^x;
df(ws,x);
int(ws,x);</code></pre>
<p>Finally, the command</p>
<pre><code>bye;</code></pre>
<p>
    should terminate any version of REDUCE.
</p>

<h2>The hard way to obtain REDUCE</h2>
<p>
    If the easy way doesn&apos;t work then you have the option of
    <a href="/building.php">building REDUCE from the source code</a>.
    For additional guidance on doing this, please see Chapter 2
    of <a href="/lisp-docs/insidereduce.pdf">Inside Reduce</a>.  See
    also <a href="http://redlog.eu/reduce-wiki/index.php/Installation"
            title="Installation">Installation</a> on the REDUCE Wiki.
</p>

<h2 id="windetails">Details of installing and running REDUCE on Windows</h2>
<p>
    The Windows installer gives you the option to install the REDUCE
    source code, files for CSL and files for PSL.  The source code is
    entirely optional and only relevant if you want to understand how
    REDUCE works and/or modify it.  You need to install files for CSL
    and/or files for PSL: CSL gives you a graphical user interface
    (GUI) by default like that shown in the
    <a href="images/reduce_screenshot_1.PNG">main image on the
        home page</a>, but can also be run with a command-line interface
    (CLI); PSL gives you a CLI running in a standard Windows Command
    Prompt window.  Beware that the REDUCE installation process will
    overwrite any previous installation without warning (which is
    probably what you want).
</p>
<p>
    Once you have installed REDUCE, you will see a folder called
    &quot;Reduce&quot; in your Start menu, which contains &quot;CSL
    Reduce&quot; and/or &quot;PSL Reduce&quot;.  (You may also see
    other items such as &quot;CSL Bootstrap Reduce&quot; and &quot;CSL
    Lisp system&quot;, which are probably only of interest to
    developers.  You can safely ignore them, or you can remove them by
    right-clicking on one of them, selecting &quot;More &gt; Open file
    location&quot; and then deleting the shortcuts.)
</p>
<p>
    If you want to run REDUCE in an existing Command Prompt window
    (rather than have REDUCE open its own window), note that the PSL
    Reduce Start menu item runs the command <code>&quot;C:\Program
    Files\Reduce\bin\redpsl.bat&quot;</code>.  (This assumes the
    default REDUCE installation folder; if you used a different
    location then please modify all file paths in this paragraph
    appropriately.)  You can either enter this long command name
    (including the quotes) after a command prompt, or you can add
    <code>C:\Program Files\Reduce\bin\</code> to your Path
    environment variable.  The REDUCE installer does not do this for
    you.  You can change your <em>Path</em> environment variable
    permanently via the <em>Advanced</em> tab of the
    <em>System Properties</em> dialogue, which you can find in
    <em>Control Panel</em> or by searching.  In Windows 10, typing
    <em>env</em> with the <em>Start</em> menu open should suffice!
    Click on the <em>Environment Variables&hellip;</em>
    button at the bottom of the
    <em>Advanced</em> tab, then edit the Path variable to include
    <code>C:\Program Files\Reduce\bin\</code>.  Editing the user
    variable is slightly safer than editing the system variable and
    will suffice unless you want the change to apply to all users.
</p>
<p>
    Now opening a Command Prompt window and executing <code>redpsl</code>
    will start PSL REDUCE (with a CLI), whereas executing
    <code>redcsl</code> will start REDUCE with a GUI (and executing
    <code>redcsl --nogui</code> will start CSL REDUCE with a CLI).
    Both CLIs provide input history, and the CSL REDUCE CLI provides
    coloured prompts and input.  The commands <code>rfpsl</code> and
    <code>rfcsl</code> run the Redfront versions of, respectively, PSL
    and CSL REDUCE, which both provide the same consistent CLI with
    input history and blue algebraic-mode output.
</p>
<p>
    If you have <a href="https://www.cygwin.com/">Cygwin</a> installed
    then you can use a Cygwin shell and the commands
    <code>redpsl</code>, <code>redcsl</code>, <code>rfpsl</code>
    and <code>rfcsl</code> work much as described above.  But note
    that under Cygwin the CSL REDUCE GUI uses the
    <a href="https://en.wikipedia.org/wiki/X_Window_System">X Window
        System</a>, so you need to have an
    <a href="https://x.cygwin.com/">X Window server</a> running, and
    the commands <code>rfpsl</code> and <code>rfcsl</code> both
    provide red (instead of white) prompts and input.
</p>

</div><!-- opened in begin-body.php -->

<?php
include 'include/footer.php';
?>

</body>
</html>
