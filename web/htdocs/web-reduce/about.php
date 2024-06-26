<?php
$page_title = 'About Web REDUCE';
$header_title = 'About Web REDUCE';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>

<h2 class="text-center"><strong>This facility is experimental!</strong></h2>

<h2>Purpose</h2>

<p>
    Web REDUCE runs as an app in your web browser and does not need
    any installation. It is intended primarily as a demonstration of
    REDUCE appropriate for simple interactive experimentation. It is
    not intended for heavy-duty problem solving (although you can use
    it however you want).
</p>

<?php
/* ?start used in page linked from main navigation */
if ($_SERVER['QUERY_STRING']) : ?>
    <h2>Running Web REDUCE</h2>
    <p>
        Click a button below to open the Web REDUCE main page
        and run the appropriate version of Web REDUCE, which
        will start loading immediately and start running as
        soon as it has loaded. <strong>Beware that, the first time
            you run it (or after an update to the Web REDUCE engine),
            there will be a noticeable pause while the Web REDUCE engine
            downloads.</strong> But normally it should load and run
        almost instantaneously.
    </p>
    <p>
        There are two main versions of Web REDUCE &ndash; desktop and mobile &ndash;
        and the button(s) below should start the right version.
        The mobile version uses less memory than the desktop version
        and omits some of the more specialised packages,
        which is currently necessary because of problems with
        memory management in mobile web browsers and not primarily
        because mobile devices lack physical memory. The mobile version
        runs on desktop computers, but probably not vice versa!
    </p>
    <p>
        <strong>
            Beware that the mobile version defaults to full window mode, which
            hides the main navigation panel/widget. Full window mode can be
            controlled using the View menu.
        </strong>
    </p>
    <p class="text-center">
        <span id="desktop">
            <a class="btn btn-primary btn-lg mb-2" href="/web-reduce">Start desktop Web REDUCE</a>
            &emsp;
            <a class="btn btn-primary btn-lg mb-2" href="/web-reduce/?gnuplot">Start desktop Web REDUCE<br />with plotting</a>
        </span>
        <a id="mobile" class="btn btn-primary btn-lg mb-2" href="/web-reduce/?mobile">Start mobile Web REDUCE</a>
    </p>
    <p>
        Alternatively, you can click on one of the following links to
        start a specific version of Web REDUCE:
        <a href="/web-reduce">desktop</a>,
        <a href="/web-reduce/?gnuplot">desktop with plotting</a>,
        <a href="/web-reduce/?mobile">mobile</a>.
    </p>
<?php endif; ?>

<h2>Limitations</h2>

<ul>
    <li>
        Web REDUCE will be a little slower than conventional REDUCE
        and there may occasionally be a noticeable pause while the
        REDUCE engine downloads.
    </li>
    <li>
        Web REDUCE does not support the standard REDUCE file access
        commands
        <code><a href="/manual-lookup.php?File%20Handling%20Commands">IN</a></code>,
        <code><a href="/manual-lookup.php?File%20Handling%20Commands">OUT</a></code>
        and <code><a href="/manual-lookup.php?File%20Handling%20Commands">SHUT</a></code>,
        but the <a href="UserGuide.php#FileMenu">File Menu</a> provides
        emulations of these commands. (Currently these emulations work well on Chromium-based desktop
        browsers but much less well on other browsers.)
    </li>
    <li>
        Web REDUCE does not support compiling or loading user modules
        or packages, although it does support compiling procedures using <code>on comp</code>.
        It does, however, provide all (or many of) the standard
        REDUCE packages, which as usual either autoload or can be
        loaded explicitly with the
        <a href="/manual-lookup.php?User%20Contributed%20Packages"><code>load_package</code></a>
        command. <strong>But note that, because of the asynchronous
            nature of JavaScript, a <code>load_package</code>
            statement must always be alone in its own input</strong> and
        autoload may not always work correctly. This applies in
        particular if an autoloaded package defines new input syntax.
        Therefore, before using the <code>mat</code> matrix input
        operator, you need to execute <code>load_package matrix;</code>
        otherwise you may get an <code>end-of-file</code> error (see below).
        Note that the <em>Matrix&hellip;</em> item in the <a href="#TemplatesMenu">Templates Menu</a> automatically
        loads the matrix package the first time it is used.
    </li>
    <li>
        User queries do not work, so Web REDUCE sets
        <a href="/manual-lookup.php?Commands%20for%20Interactive%20Use"><code>off int; on errcont;</code></a>
        by default, which provides a reasonable user experience.
        However, it means that the standard REDUCE operators
        <a href="/manual-lookup.php?Referencing%20Previous%20Results"><code>ws</code>,
            <code>input</code> and <code>display</code></a> are not available,
        although <code>ws</code> used as a variable works as usual.
    </li>
    <li>
        Web REDUCE does not provide any input prompts, unlike conventional REDUCE.
        <!-- This limits the usefulness of the standard REDUCE operators
        <a href="/manual-lookup.php?Referencing%20Previous%20Results"><code>ws</code>
            and <code>input</code></a>, which work but you have to count
        inputs yourself! (In principle, the standard REDUCE command
        <a href="/manual-lookup.php?Referencing%20Previous%20Results"><code>display</code></a>
        should help, but it doesn't work with <code>off int</code>.)
        However, <code>ws</code> used as a variable works as usual. -->
    </li>
    <li>
        Any kind of comment at the end of input causes an
        <code>end-of-file</code> warning. Similarly, the first time the
        <code>mat</code> operator is used (without first loading the
        <code>matrix</code> package) may cause an
        <code>end-of-file</code> warning. In both cases REDUCE
        recovers, and re-inputting <code>mat</code> seems to work.
    </li>
    <!-- <li>
        Web REDUCE cannot run any external programs, so facilities
        that rely on this, such as plotting, do not work.
    </li> -->
    <li>
        You need a recent web browser, preferably the latest version,
        to run Web REDUCE.
    </li>
    <li>
        <strong>Plotting:</strong>
        <ul>
            <li>only the last plot is visible since each plot overwrites any previous plot;</li>
            <li>plotting can cause spurious <code>end-of-file</code> warnings and fatal <code>end-of-file</code> errors;</li>
            <li>mobile Web REDUCE does not support plotting.</li>
        </ul>
    </li>
</ul>
<p>
    It may be possible to remove some of these limitations in future.
</p>

<h2>What is it?</h2>

<p>
    Web REDUCE consists of a graphical user interface (GUI)
    implemented using HTML, CSS and JavaScript that runs a Wasm (<a href="https://webassembly.org/">WebAssembly</a>)
    version of the REDUCE engine developed by Arthur Norman and Avery
    Laird, which is CSL REDUCE compiled to WebAssembly using
    <a href="https://emscripten.org/">Emscripten</a>. See
    <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/new-embedded/for-emscripten/">SourceForge</a>
    for details of how to build this version of REDUCE, which consists
    of two files, <code>reduce.web.js</code> and <code>reduce.web.wasm</code>.
    The web worker interface to the Wasm REDUCE engine uses code
    developed by Arthur Norman and Avery Laird. The Web REDUCE GUI is
    modelled on the <a href="https://fjwright.github.io/Run-REDUCE/">Run-REDUCE</a>
    GUI for conventional REDUCE, which itself is loosely based on the
    CSL REDUCE GUI by Arthur Norman.
</p>
<p>
    Typeset mathematics is output using <span class="latex">L<sup>a</sup>T<sub>e</sub>X</span> code generated by the
    REDUCE <code>tmprint</code> package and rendered by
    the <a href="https://www.mathjax.org/">MathJax</a> JavaScript
    library, which is also used elsewhere on the REDUCE web site.
</p>
<p>
    Plotting is provided by <a href="http://www.gnuplot.info/">Gnuplot</a>
    compiled to <a href="https://webassembly.org/">WebAssembly</a>
    using <a href="https://emscripten.org/">Emscripten</a>, based on
    <a href="https://github.com/CD3/gnuplot-in-the-browser">work by CD Clark III</a>.
    The code to call Web Gnuplot from Web REDUCE is based on
    <a href="https://github.com/kungfooman/WebREDUCE/">work by Hermann Rolfes</a>.
</p>

<address><a href="https://sites.google.com/site/fjwcentaur/feedback">Francis Wright</a>, April 2024</address>

</div><!-- opened in begin-body.php -->

<?php include '../include/footer.php'; ?>

<script type="module">
    let mobile;
    // Only defined in secure contexts (HTTPS) in Chromium-based browsers:
    if (navigator.userAgentData) mobile = navigator.userAgentData.mobile;
    // Only defined in mobile browsers, although deprecated, and may be 0 (degrees):
    else mobile = (typeof window.orientation !== "undefined");
    document.getElementById(mobile ? "desktop" : "mobile").hidden = true;
</script>

</body>

</html>