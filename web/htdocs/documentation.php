<?php
$header_title = 'Documentation';
include './include/begin-head.php';
?>

<base href="/manual/" />
<!-- *** Beware that relative URLs on this page are relative to "/manual/" for the  User Contributed Packages. *** -->

<?php
include './include/begin-body.php';
?>

<p>
    REDUCE includes considerable documentation, not only for the core system,
    but also for the many application packages included in the release.
    The main documentation is included in a standard REDUCE installation; it
    is available on Microsoft Windows via the <em>Start</em> menu and
    on other platforms in <code>/usr/share/doc/reduce</code>.
    (The <a href="/documentation38.php">documentation for
        REDUCE 3.8</a>, the last commercial version of REDUCE released in
    2004, is also still available for historical interest.)
</p>
<p>For all users:</p>
<ul>
    <li>
        <strong>REDUCE User&apos;s Manual</strong>
        <small>[ <a href="manual.html" title="a multi-page HTML document">HTML</a> |
            <a href="manual.pdf">PDF</a> ]</small> &ndash;
        a comprehensive guide to the REDUCE language and the supported packages.
        It can be accessed via the <em>Help</em> menu in the
        <a href="/versions.php#csl">CSL REDUCE GUI</a>
        (and in <a href="https://fjwright.github.io/Run-REDUCE/">Run-REDUCE</a>)
        <small> [<a href="/manual-lookup.php">note on external linking</a>]</small>;
    </li>
    <li>
        <strong><a href="/switches.php">Switch Summary</a></strong> &ndash;
        an overview of the switches that control REDUCE.
    </li>
</ul>
<p>For advanced users:</p>
<ul>
    <li>
        <a href="/lisp-docs/insidereduce.pdf"><strong>Inside
                Reduce</strong></a> &ndash; how to build REDUCE, the
        structure of the REDUCE source code, and some low-level
        programming features;
    </li>
    <li>
        <strong>Symbolic Mode Primer</strong>
        <small>[ <a href="/lisp-docs/primer.html">HTML</a>
            | <a href="/lisp-docs/primer.pdf">PDF</a> ]</small> &ndash; an
        introduction to programming in the REDUCE implementation
        language, RLISP, which is Standard Lisp with REDUCE (essentially
        ALGOL 60) syntax;
    </li>
    <li>
        <strong>Standard Lisp Report</strong>
        <small>[ <a href="/lisp-docs/sl.html">HTML</a>
            | <a href="/lisp-docs/sl.pdf">PDF</a> ]</small> &ndash; defines Standard
        Lisp, the dialect of Lisp assumed by REDUCE;
    </li>
    <li>
        <strong>PSL Users Manual</strong>
        <small>[ <a href="/lisp-docs/allman1.html">HTML</a> |
            <a href="/lisp-docs/allman1.pdf">PDF</a> ]</small> &ndash; documents
        Portable Standard Lisp, the original implementation of Standard
        Lisp;
    </li>
    <li>
        <a href="/lisp-docs/csl.html"><strong>CSL
                Reference</strong></a> &ndash; documents Codemist Standard Lisp, a
        later implementation of Standard Lisp.
    </li>
</ul>
<p id="contributed">
    The following documents for the user-contributed packages are
    dynamically generated links into the HTML version of the REDUCE
    User&apos;s Manual.
</p>
<div>
    <?php
    $doc = new DOMDocument();
    libxml_use_internal_errors(true);
    if ($doc->loadHTMLFile('manual/manual.html')) {
        // Use XPath to extract the User Contributed Packages links in the Table of Contents:
        $xpath = new DOMXpath($doc);
        $chapterAnchor = $xpath->query(
            "/html/body/div[@class='tableofcontents']/span[@class='chapterToc']/a[.='User Contributed Packages']"
        )->item(0);
        $chapterAnchor->removeAttribute('id');
        echo "<span style='font-size:x-large'>{$doc->saveHTML($chapterAnchor)}</span><br/>\n";
        $sectionSpans = $xpath->query("parent::span/following-sibling::span", $chapterAnchor);
        foreach ($sectionSpans as $sectionSpan) {
            if ($sectionSpan->getAttribute('class') == 'chapterToc') break;
            $sectionAnchor = $sectionSpan->getElementsByTagName('a')->item(0);
            $sectionAnchor->removeAttribute('id');
            // The following works but utf8_decode is deprecated in PHP 8.2.
            // I think 'manual/manual.html' really is encoded as UTF-8,
            // but without utf8_decode the output is mangled!
            $sectionAnchorString = utf8_decode($doc->saveHTML($sectionAnchor));
            // Embolden the package name (before the colon):
            $sectionAnchorString = preg_replace('/>(.*):/', '><b>$1</b>:', $sectionAnchorString);
            echo "&emsp;&emsp;$sectionAnchorString<br/>\n";
        }
    } else { ?>
        <h2>REDUCE Manual Contents Error</h2>
        <p>
            Failed to load the REDUCE manual contents page. Sorry.
            This should not happen!
        </p>
        <p>
            Please email this error message to
            <a href="https://sites.google.com/site/fjwcentaur/feedback">webmaster</a>
            and include the URL of this page.
        </p>
    <?php } ?>
</div>

</div><!-- opened in begin-body.php -->

<?php
include './include/footer.php';
?>

</body>

</html>