<?php
$page_title = 'Building REDUCE';
$header_title = 'Building REDUCE';
include './include/begin-head.php';
include './include/begin-body.php';
?>

<p>
    These instructions outline how to build REDUCE from the source
    code.  The process is very similar on all platforms, but it is
    fairly time-consuming and not easy for the uninitiated.  You can
    download the complete source code, including both the PSL and CSL
    Lisp systems and full documentation, from the REDUCE project page
    as either:
</p>
<ul>
    <li>a pre-packaged distribution via the
        <a href="https://sourceforge.net/projects/reduce-algebra/files/">Files</a>
        tab, which is easiest and should give you a tested
        &quot;snapshot&quot;;</li>
    <li>files from the Subversion repository via the
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/">Code</a>
        tab, which will give you the latest bug fixes and updates but
        may not be fully tested and so may not be completely stable.</li>
</ul>
<p>
    For the latest definitive guidance, please see the file
    <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/README.BUILDING">README.BUILDING</a>
    in the trunk of the Subversion repository.  Below is a brief
    outline of the build process.
</p>
<p>
    If you prefer to use a version control system other than
    Subversion, the REDUCE repository is mirrored at
    <a href="https://github.com/reduce-algebra/reduce-algebra">GitHub</a>,
    where the
    <a href="https://github.com/reduce-algebra/reduce-algebra/blob/master/README.md">README</a>
    lists several other mirrors, and the
    <a href="https://github.com/reduce-algebra">GitHub REDUCE
    organization</a> page provides alternative access to a number of
    closely <a href="projects.php">related projects</a>.
</p>

<h2>Microsoft Windows</h2>
<p>
    On Microsoft Windows, we currently only explicitly support
    building using <a href="https://cygwin.com">Cygwin</a>, although
    the resulting compiled version of REDUCE will be a native Windows
    application that does not require Cygwin to run.  Cygwin provides
    a very similar environment to GNU/Linux, which consists of GNU
    software running on a Linux kernel, whereas Cygwin consists of GNU
    software running on a Windows kernel via a Unix-like emulation
    layer provided by the Cygwin dll.
</p>
<h2>Outline of the General Build Process</h2>
<p>
    You need to have a sufficiently complete software installation,
    including the tools required to obtain the source code files and
    the tools required to build programs.  This involves using the
    appropriate package manager for your platform to download and
    install the packages required.  If the build process fails in any
    non-obvious way then it probably means that you are missing some
    necessary build tool.
</p>
<p>
    If you have downloaded a pre-packaged source code archive file
    <code>Reduce-svn<em>nnnn</em>-src.tar.gz</code>
    (where <code><em>nnnn</em></code> is the revision number), move it
    to an appropriate directory and unpack it, which you can do using
    the command
</p>
<pre><code>tar axf Reduce-svn<em>nnnn</em>-src.tar.gz</code></pre>
<p>
    This will generate a sub-directory
    <code>Reduce-svn<em>nnnn</em>-src</code> containing the REDUCE
    repository snapshot, which is equivalent to the directory referred
    to below as <code>reduce-algebra</code>.
</p>
<p>
    If you prefer to download directly from the live Subversion
    repository you need the &quot;subversion&quot; program <em>svn</em>,
    which you may have to install explicitly.  Once that is available,
    you can run the command
</p>
<pre><code>svn co https://svn.code.sf.net/p/reduce-algebra/code/trunk/</code></pre>
<p>
    This will download a copy of all the latest files to the
    sub-directory <code>reduce-algebra</code>.
</p>
<p>
    To create the necessary executables, <kbd>cd</kbd> to the
    <code>reduce-algebra/trunk</code> directory, and then execute the
    command
</p>
<p>
    <code>./configure --with-csl</code> or <code>./configure
    --with-psl</code> (or both)
</p>
<p>
    depending upon which underlying Lisp(s) you prefer to use.  Now
    execute the command
</p>
<pre><code>make</code></pre>
<p>
    and be prepared to wait a long time for the compilation to
    complete.  After this is done, the script file(s)
    <code>redcsl</code> and/or <code>redpsl</code>, with a
    <code>.bat</code> extension for Windows, to run REDUCE will be
    found in the <code>bin</code> subdirectory.
</p>
<p>
    Once you have downloaded the file set using <em>svn</em>, running
    the command
</p>
<pre><code>svn update</code></pre>
<p>
    in the root of your local copy of the repository will download
    only those files that have changed since you last updated the
    repository.
</p>

</div><!-- opened in begin-body.php -->

<?php
include './include/footer.php';
?>

</body>
</html>
