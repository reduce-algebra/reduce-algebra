<?php
$header_title = 'Documentation';
include 'include/begin-head.php';
?>

<style type="text/css">
 #contrib > span.chapterToc > a {
     font-size: x-large;
 }
</style>

<base href="/manual/" />
<!-- *** Beware that relative URLs on this page are relative to "/manual/". *** -->

<?php
include 'include/begin-body.php';
?>

<p>
    REDUCE includes considerable documentation, not only for the core
    system, but also for the many application packages included in the
    release. (The <a href="/documentation38.php">documentation for
    REDUCE 3.8</a>, the last commercial version of REDUCE released in
    2004, is also still available.)
</p>
<p>For all users:</p>
<ul>
    <li>
        the <strong>REDUCE User&apos;s Manual</strong>
        <small>[ <a href="manual.html"
                    title="a multi-page HTML document">HTML</a> |
            <a href="manual.pdf">PDF</a> ]</small> provides a comprehensive
        guide to the REDUCE language and the supported packages
        <small> [<a href="/manual-lookup.php">note on external
            linking</a>]</small>;
    </li>
    <li>
        the <a href="/switches.php">switch summary</a> provides an
        overview of the switches that control REDUCE.
    </li>
</ul>
<p>For advanced users:</p>
<ul>
    <li>
        <a href="/lisp-docs/insidereduce.pdf"><strong>Inside
            Reduce</strong></a> describes how to build REDUCE, the
        structure of the REDUCE source code, and some low-level
        programming features;
    </li>
    <li>
        the <strong>Symbolic Mode Primer</strong>
        <small>[ <a href="/lisp-docs/primer.html">HTML</a>
            | <a href="/lisp-docs/primer.pdf">PDF</a> ]</small> provides an
        introduction to programming in the REDUCE implementation
        language, RLISP, which is Standard Lisp with REDUCE (essentially
        ALGOL 60) syntax;
    </li>
    <li>
        the <strong>Standard Lisp Report</strong>
        <small>[ <a href="/lisp-docs/sl.html">HTML</a>
            | <a href="/lisp-docs/sl.pdf">PDF</a> ]</small> defines Standard
        Lisp, the dialect of Lisp assumed by REDUCE;
    </li>
    <li>
        the <strong>PSL Users Manual</strong>
        <small>[ <a href="/lisp-docs/allman1.html">HTML</a> |
            <a href="/lisp-docs/allman1.pdf">PDF</a> ]</small> documents
        Portable Standard Lisp, the original implementation of Standard
        Lisp;
    </li>
    <li>
        the <a href="/lisp-docs/csl.html"><strong>CSL
        Reference</strong></a> documents Codemist Standard Lisp, a
        later implementation of Standard Lisp.
    </li>
</ul>
<p id="contributed">
    The following documents for the user-contributed packages are
    dynamically generated links into the HTML version of the REDUCE
    User&apos;s Manual.
</p>
<div id="contrib">
    <p>A list of user-contributed packages is being generated...</p>
</div>

</div><!-- opened in begin-body.php -->

<?php
include 'include/footer.php';
?>

<!-- *** Re-implement this in PHP! *** -->
<script>
 $("#contrib").
          load("/manual/manual.html div.tableofcontents > *",
               function() {  // invoked once as a method of each element of the jQuery object
                   $("#contrib > span.chapterToc:has(a:contains(User Contributed Packages))").prevAll().remove()
                   $("#contrib > span.chapterToc:nth(1)").nextAll().addBack().remove()
                   // Remove numbering from heading:
                   $("#contrib > span.chapterToc").contents().first().remove()
                   $("#contrib > span.sectionToc").each(function() {
                       var $this = $(this)
                       // Replace numbering of package with space:
                       $this.contents().first().replaceWith("&emsp;&emsp;")
                       // Embolden the package name (before colon):
                       $this.find("a").html(function(n, current){
                           var ind = current.search(":");
                           return "<b>" + current.substring(0, ind) + "</b>" + current.substring(ind)
                       })
                   })
          })
</script>

</body>
</html>
