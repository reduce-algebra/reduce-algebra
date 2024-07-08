<?php
$header_title = 'Related Projects';
include './include/begin-head.php';
?>

<style type="text/css">
    #main li {
        margin-bottom: 1em
    }
</style>

<?php
include './include/begin-body.php';
?>

<h2>REDUCE user interfaces</h2>
<ul>
    <li>
        <a href="https://fjwright.github.io/Run-REDUCE/">Run-REDUCE</a> is
        an open-source graphical user interface for running any
        command-line version of REDUCE. Installers are available for
        Microsoft Windows and Gnu/Linux distributions based on Debian
        (e.g. Ubuntu) or Red Hat (e.g. Fedora). A Java JAR file is also
        available that should run on any platform that supports JavaFX.
    </li>
    <li>
        <a href="reduce-ide/">REDUCE IDE</a> is an open-source
        <u>I</u>ntegrated <u>D</u>evelopment <u>E</u>nvironment for the
        <a href="http://www.gnu.org/software/emacs/emacs.html">GNU Emacs</a> editor,
        which supports editing REDUCE source code and running any command-line version of REDUCE.
    </li>
</ul>
<h2>REDUCE for mobile devices</h2>
<p>
    <a href="/web-reduce/about.php?start">Web REDUCE</a> should work on most mobile devices.
</p>
<p>
    As of July 2024 there appear to be no REDUCE mobile apps available
    from the Google or Apple app stores, but there are other options.
    Please note that the apps listed below are <strong>not supported</strong> at all.
    The links below are provided purely for information
    and their presence here does not constitute any recommendation.
    These apps are all fairly old and you use them entirely at you own risk!
</p>
<ul>
    <!-- <li>
        <a href="https://apps.apple.com/us/app/icas/id394637176">iCAS</a>
        is a commercial version of REDUCE packaged for the Apple
        iPhone and iPad.
    </li> -->
    <li>
        Symbolic is a CLI version of REDUCE packaged for Android.
        It was developed from
        Android REDUCE (see below) and was last updated in 2013.
        Beware that users have reported that this app can be a little
        fragile and that the <code>read</code> and <code>save</code>
        facilities do not work, in which case a work-around is to copy
        and paste from a separate file editor.
        Symbolic is available only from
        <a href="https://dl2mie.darc.de/papers/ReduceScripts/index.html">the author's web site</a>
        as both a pre-build package and as source code.
        However, it may not install on recent versions of Android.
        Users have reported that, with a little effort, it can be persuaded to
        install on Android 12 but that it will not install on Android 13.
    </li>
</ul>
<p>
    The following Android apps are available only as source code, not
    as installable apps.
</p>
<ul>
    <li>
        <a href="https://github.com/n0n3m4/ReduceNative">ReduceNative</a>
        is code that provides a GUI written in Kotlin for running
        REDUCE on Android that was kindly released by the authors on
        25 November 2019. It includes a prebuilt binary version of
        REDUCE itself but not the code to build REDUCE for Android.
    </li>
    <li>
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/jlisp/android">Android REDUCE</a>
        is a GUI version of REDUCE packaged for Android that provides
        only non-programmable calculator-style input with limited
        functionality developed in 2011&ndash;12. It was the first
        Android version of REDUCE.
    </li>
</ul>

<h2>External projects using REDUCE</h2>
<p>
    There are a number of independent projects that use REDUCE in
    various ways. These include:
</p>
<ul>
    <li>
        the <a href="http://www.alltypes.de/">ALLTYPES</a> algebraic
        language and type system;
    </li>
    <li>
        <a href="http://mtt.sourceforge.net/">MTT</a>, a set of tools
        for modeling dynamic physical systems using the bond-graph
        methodology;
    </li>
    <li>
        <a href="https://github.com/chakravala/Reduce.jl">Reduce.jl</a>,
        an interface for calling REDUCE from the Julia language for
        symbolic manipulation;
    </li>
    <li>
        the <a href="https://github.com/agraef/pure-lang/wiki/ScientificComputing">Pure</a>
        programming language, which has bindings for REDUCE, providing
        a very interesting environment for doing computer-powered
        science.
    </li>
</ul>

<h2>Internal projects using REDUCE</h2>
<p>
    The following projects were distributed independently but are now
    available from the REDUCE SourceForge project:
</p>
<ul>
    <li>
        <a href="http://www.redlog.eu/">Redlog</a> &ndash; Computing
        with Logic &ndash; is now an integral part of REDUCE;
    </li>
    <li>
        <a href="http://cds.cern.ch/record/438562/files/0005081.pdf">Ortocartan</a>
        is a
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/contrib/ortocartan/">set
            of programs</a> for algebraic calculations in relativity,
        implemented in the Lisp underlying REDUCE;
    </li>
</ul>

<h2>Alternative Access to REDUCE Resources</h2>
<p>
    If you prefer to use a version control system other than
    Subversion, the REDUCE repository is mirrored at
    <a href="https://github.com/reduce-algebra/reduce-algebra">GitHub</a>,
    where the
    <a href="https://github.com/reduce-algebra/reduce-algebra/blob/master/README.md">README</a>
    lists several other mirrors, and the
    <a href="https://github.com/reduce-algebra">GitHub REDUCE
        organization</a> page provides alternative access to a number of
    closely related projects, including several of those listed above.
</p>

<h2>Other computer algebra systems</h2>
<p>
    Wikipedia provides a fairly comprehensive
    <a href="https://en.wikipedia.org/wiki/List_of_computer_algebra_systems">list
        of computer algebra systems</a>, but it does not include the
    following:
</p>
<ul>
    <li>
        <a href="https://www.mathpiper.org/">MathPiper</a>
    </li>
    <li>
        <a href="http://polybori.sourceforge.net/">PolyBoRi</a> &ndash;
        Polynomials over Boolean Rings
    </li>
    <li>
        <a href="https://download.cnet.com/SymbMath/3000-2053_4-10002619.html">SymbMath</a>,
        which has evolved into the
        <a href="http://math.drhuang.com/science/mathematics/software/">Math
            Handbook Calculator</a>
    </li>
</ul>

</div><!-- opened in begin-body.php -->

<?php
include './include/footer.php';
?>

</body>

</html>