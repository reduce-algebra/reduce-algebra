<?php
$header_title = 'Related Projects';
include 'include/begin-head.php';
?>

<style type="text/css">
 #main li {
     margin-bottom: 1em
 }
</style>

<?php
include 'include/begin-body.php';
?>

<h2>REDUCE user interfaces</h2>
<p>
    <a href="https://fjwright.github.io/Run-REDUCE/">Run-REDUCE</a> is
    an open-source graphical user interface for running any
    command-line version of REDUCE.  Installers are available for
    Microsoft Windows 10 and Gnu/Linux distributions based on Debian
    (e.g. Ubuntu) or Red Hat (e.g. Fedora).  A Java JAR file is also
    available that should run on any platform that supports JavaFX.
</p>
<h2>REDUCE for mobile devices</h2>
<p>
    Please note that the apps listed below are <strong>not supported</strong> by
    the <a href="https://sourceforge.net/p/reduce-algebra/_members/">REDUCE
    developers</a>, so any queries should be directed to the app
    developers.  The links below are provided purely for information
    and their presence here does not constitute any recommendation by
    the REDUCE developers.  These apps may not use the latest version
    of REDUCE and you use them entirely at you own risk!
</p>
<ul>
    <li>
        <a href="https://apps.apple.com/us/app/icas/id394637176">iCAS</a>
        is a commercial version of REDUCE packaged for the Apple
        iPhone and iPad.
    </li>
    <li>
        <a href="https://play.google.com/store/apps/details?id=de.dieteregger.symbolic">Symbolic</a>
        is a CLI version of REDUCE packaged for Android, which is
        available for free from Google Play.  It was developed from
        Android REDUCE (see below) and was last updated in 2013.
    </li>
    <li>
        <a href="https://www.torrapk.com/en/apps/24-office-and-productivity/2791-Android-REDUCE">Android
            REDUCE</a> is a GUI version of REDUCE packaged for Android
        that provides only non-programmable calculator-style input
        with limited functionality, which is available for free (but
        <strong>not</strong> from Google Play).  It is essentially the
        original Android version of REDUCE.
    </li>
</ul>
<p>
    Beware that users have reported that the above Android apps can be
    a little fragile and that the <code>read</code>
    and <code>save</code> facilities in Symbolic do not work, in which
    case a work-around is to copy and paste from a separate file
    editor.
</p>
<p>
    <a href="https://github.com/n0n3m4/ReduceNative">ReduceNative</a>
    is code that provides a GUI written in Kotlin for running REDUCE
    on Android that was kindly released by the authors on 25 November
    2019.  It includes a prebuilt binary version of REDUCE itself but
    not the code to build REDUCE for Android.  This project needs some
    further development and does not include a prebuild app.
</p>
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
    <li>
        <a href="reduce-ide/">REDUCE IDE</a> is
        an <u>I</u>ntegrated <u>D</u>evelopment <u>E</u>nvironment for
        the <a href="http://www.gnu.org/software/emacs/emacs.html">GNU
            Emacs</a> editor.
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
include 'include/footer.php';
?>

</body>
</html>
