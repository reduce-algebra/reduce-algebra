<!-- Index page for https://reduce-algebra.sourceforge.io, http://reduce-algebra.com, etc. -->

<?php
$page_title = 'REDUCE Computer Algebra System';
$header_title = 'What is REDUCE?';
include 'include/begin-head.php';
?>
<meta name="google-site-verification" content="pKr8xVCb35NVMHejjhvma4js1wsSweNQ_8vTVJqWFeA" />

<style type="text/css">
 #main img {
     float: none;
     margin: 0;
     width: 100%;
     border: thin solid;
 }

 #main img.sflogo {
     margin: auto;
     width: auto;
     border: none;
 }

 aside iframe {
     border: 0;
     padding: 0;
     width: 100%;
     height: 500px;
     border: 1px solid #333333;
     background-color: #f8f8ff;
 }
</style>

<?php
$main_class = 'col-md-6 col-xl-6';
include 'include/begin-body.php';
?>

<p>
    See also the <a href="https://sourceforge.net/p/reduce-algebra/"
                    rel="nofollow">REDUCE project page at
    <img class="sflogo" alt="SourceForge"
         src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>.
</p>
<p>
    REDUCE is a <strong>portable general-purpose computer algebra
    system</strong>. It is a system for doing scalar, vector and
    matrix algebra by computer, which also supports arbitrary
    precision numerical approximation and interfaces
    to <a href="http://www.gnuplot.info/">gnuplot</a> to provide
    graphics. It can be used interactively for simple calculations (as
    illustrated in the screenshot below) but also provides a full
    programming language, with a syntax similar to other modern
    programming languages. REDUCE supports alternative
    <a href="support.php#interfaces">user interfaces</a> including
    <a href="https://fjwright.github.io/Run-REDUCE/">Run-REDUCE</a>,
    <a href="https://www.texmacs.org/">TeXmacs</a> and
    <a href="reduce-ide/">GNU Emacs</a>.
</p>
<p>
    REDUCE (and its complete source code) is
    <a href="obtaining.php">available free of charge</a> for most
    common computing systems, in some cases in <a href="versions.php">more
        than one version</a> for the same machine.  The
    <a href="documentation.php">manual and other support documents</a> and
    <a href="tutorials.php">tutorials</a> are also included in the
    distributions.
</p>
<a href="images/reduce_screenshot_1.png">
    <img src="images/reduce_screenshot_1.png" alt="CSL REDUCE on Microsoft Windows"
         title="CSL REDUCE on Microsoft Windows &ndash; click to see the full size image" />
</a>
<p>
    REDUCE has a long and distinguished place in the history of
    computer algebra systems (see the
    <a href="bibliography.php">bibliography</a>). Other systems that
    address some of the same issues but sometimes with rather
    different emphasis are
    <a href="http://www.axiom-developer.org/">Axiom</a>,
    Macsyma (<a href="https://maxima.sourceforge.io/">Maxima</a>),
    <a href="https://www.maplesoft.com/products/Maple/">Maple</a>
    and <a href="https://www.wolfram.com/mathematica/">Mathematica</a>.
</p>
<p id="versions">
    REDUCE is implemented in Lisp (as are Axiom and Macsyma), but this
    is completely hidden from the casual user. REDUCE primarily runs
    on either <a href="versions.php">Portable Standard Lisp (PSL) or
    Codemist Standard Lisp (CSL)</a>, both of which are available in
    the distributions. PSL is long-established and compiles to machine
    code, whereas CSL is newer and compiles to byte code. Hence, PSL
    may be faster but CSL may be available on a wider range of
    platforms. CSL provides a graphical user interface (as illustrated
    in the screenshot above), but PSL provides only a command-line
    interface.
</p>

</div><!-- opened in begin-body.php -->

<aside class="col-md-3 col-xl-2">
    <h2 style="text-align:center; font-size:medium;">SourceForge RSS feeds</h2>
    <div class="row">
        <div class="col-sm col-md-12">
            <iframe src="include/displayRSSfeed.php?https://sourceforge.net/p/reduce-algebra/activity/feed?source=project_activity"></iframe>
        </div>
        <div class="col-sm col-md-12">
            <iframe src="include/displayRSSfeed.php?https://sourceforge.net/p/reduce-algebra/news/feed.rss"></iframe>
        </div>
    </div>
    <p style="text-align:center; font-size:small;">RSS feed display courtesy of <a href="http://simplepie.org/">SimplePie</a></p>
</aside>

<?php
$footer_class='col-xl-2';
include 'include/footer.php';
?>

</body>
</html>
