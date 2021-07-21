<?php
$header_title = 'Tutorials';
include './include/begin-head.php';
?>

<style type="text/css">
 pre {
     margin: 0
 }
</style>

<?php
include './include/begin-body.php';
?>

<h2 id="lessons">The REDUCE interactive lessons</h2>
<p>
    To run the lessons, you first need to download them, which you can
    do in any of the following ways:
</p>
<ul>
    <li>Select a directory on your computer to contain the
        <code>lessons</code> directory then download
        <a href="tutorials/lessons.zip">lessons.zip</a>
        to this directory and unzip it.</li>
    <li>If you have the
        <a href="https://en.wikipedia.org/wiki/Apache_Subversion">subversion</a>
        program installed then select a directory on your computer to
        contain the
        <code>lessons</code> directory, open a command prompt window
        in that directory (if necessary) and execute the shell command
        <pre>svn checkout svn://svn.code.sf.net/p/reduce-algebra/code/trunk/packages/lessons</pre>
        You can also download individual lesson files this way.
    </li>
    <li id="read-lesson">To download or read just one of the lessons, go to the
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/packages/lessons/">lessons
            directory in the SourceForge code repository</a> and click on the lesson file (e.g.
        <code>less1.red</code>). To download it, click on the link
        labelled &quot;Download this file&quot; that appears above the
        file listing, download the file to your computer, optionally
        create a directory on your computer called <code>lessons</code>
        (although you can call it whatever you want) and save the file
        there.</li>
</ul>
<p>
    The lesson files are intended to be perused in REDUCE (although
    they are plain text files). They consist of long comments
    interspersed with REDUCE input that is intended to be executed,
    and they automatically pause every so often so that you can read
    the next section. But you may need to scroll back to the beginning
    of the file or to the last pause to see the beginning of the
    current section. If you want to read a lesson outside of REDUCE
    then it is easy to do so in your web browser, as described in the
    <a href="#read-lesson">last bullet point above</a>.
</p>
<ul>
    <li>One way to run the lessons in CSL REDUCE is to start it
        normally, click on the
        <code>File / Read...</code> menu item, find your
        <code>lessons</code> directory in the file selector and then select a lesson file, such as
        <code>less1.red</code>.</li>
    <li>One way to run the lessons in PSL REDUCE is to start it
    normally and then execute a command of the following form
    (customized as appropriate for your computer):
        <pre>in &quot;path/to/lessons/less1.red&quot;;</pre></li>
</ul>
<p>
    It is advisable to run each lesson in a new REDUCE session,
    otherwise the lessons may interfere with each other.
</p>

<h2>Elementary mathematics tutorials</h2>
<p>
    The following tutorials cover the application of REDUCE to a range
    of elementary mathematics problems at pre-university and
    first/second-year undergraduate level.  If you spot any errors or
    have better solutions then please
    <a href="https://sourceforge.net/users/fjwright/">let us know</a>.
    Other tutorials may follow as they are developed.
</p>
<p>
    It is assumed that the reader is familiar with the mathematics,
    which is not explained here.  Please refer to the
    <strong>REDUCE User&apos;s Manual</strong> <small>[
        <a href="manual/manual.html">HTML</a> |
        <a href="manual/manual.pdf">PDF</a> ]</small> for details of
    the REDUCE facilities used, which are also not explained here.
    You should be able to copy and paste the REDUCE solutions into
    REDUCE, but you are recommended to try your own solutions first.
</p>
<p>
    <a href="tutorials/em-tutorial.php">Pre-university algebra tutorial</a>
</p>
<p>
    Undergraduate mathematics tutorials on &hellip;
</p>
<ul>
    <li><a href="tutorials/calculus-tutorial.php">calculus</a></li>
    <li><a href="tutorials/veclinalg-tutorial.php">vectors and linear algebra</a></li>
    <li><a href="tutorials/pure-tutorial.php">pure mathematics</a></li>
    <li><a href="tutorials/complex-tutorial.php">complex variables</a></li>
    <li><a href="tutorials/ode-tutorial.php">ordinary differential equations</a></li>
</ul>

<h2 id="egger">Example scripts by Dieter (Olli) Egger</h2>
<p>
    Dieter Egger is the author of
    <a href="https://play.google.com/store/apps/details?id=de.dieteregger.symbolic">Symbolic</a>,
    a REDUCE app for Android available from Google Play, and some of
    the scripts available here are those used as demonstrations for
    Symbolic as shown in the screenshots on Google Play.  Other
    scripts relate to Dieter&apos;s research in curved space-time.  A
    brief description of all his scripts, with links to them, is
    available in either <a href="tutorials/EggerScripts.php">German</a>
    (his original version) or <a href="tutorials/EggerScripts.en.php">English</a>,
    although the scripts themselves are all in English.  The whole
    collection of scripts is also available as a
    <a href="tutorials/EggerReduceScripts.zip">zip archive</a>.
</p>
<p>
    The following papers describe the scientific background to some of
    the scripts:
</p>
<ul>
    <li><a href="tutorials/Metrik.pdf">&Uuml;ber eine spezielle Metrik
        &ndash; Alternative Kosmologie</a>.  This paper (in German)
        ends with several REDUCE scripts.</li>
    <li><a href="tutorials/MetricUniverse.pdf">About a Special Metric
        &ndash; Dark Matter and Dark Energy transmogrified</a>.  This
        paper (in English) is a longer version of the above paper that
        references some of the scripts available via the links above.
        (The link given at the end of the paper no longer works.)</li>
</ul>

</div><!-- opened in begin-body.php -->

<?php
include './include/footer.php';
?>

</body>
</html>
