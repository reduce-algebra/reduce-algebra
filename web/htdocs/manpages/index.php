<?php
$header_title = 'Unix-style Man Pages';
include '../include/begin-head.php';
?>

<style>
    table {
        /* width: 100%; */
        border-collapse: collapse;
        margin-bottom: 1ex;
    }

    th,
    td {
        border: black solid thin;
        padding: 5px;
    }
</style>

<?php
include '../include/begin-body.php';
?>

<p>
    When REDUCE is installed on a Unix-like platform (including <a href="https://www.cygwin.com/">Cygwin</a>), the following <code>man</code> pages are available. They are also available here via the links below as HTML pages that approximate <code>man</code> page formatting.
</p>

<table>
    <tr>
        <th>Command</th>
        <th>Description</th>
    </tr>
    <tr>
        <td><a href="redcsl.html"><code>redcsl</code></a></td>
        <td>Run REDUCE under CSL</td>
    </tr>
    <tr>
        <td><a href="redpsl.html"><code>redpsl</code></a></td>
        <td>Run REDUCE under PSL</td>
    </tr>
    <tr>
        <td><a href="breduce.html"><code>breduce</code></a></td>
        <td>A batch processing facility for REDUCE</td>
    </tr>
    <tr>
        <td><a href="redfront.html"><code>redfront</code></a></td>
        <td rowspan="3">REDUCE frontend</td>
    </tr>
    <tr>
        <td><a href="redfront.html"><code>rfcsl</code></a></td>
    </tr>
    <tr>
        <td><a href="redfront.html"><code>rfpsl</code></a></td>
    </tr>
</table>

<p>
    The commands <code>redfront</code>, <code>rfcsl</code> and <code>rfpsl</code> all have the same <code>man</code> page, which on Cygwin is only available using the name <code>redfront</code>.
    The <code>man</code> page for <code>breduce</code> refers to documentation also available here as <a href="breduce.pdf">breduce.pdf</a>.
</p>

<h2>Microsoft Windows</h2>

<p>
    The commands <code>redcsl</code>, <code>redpsl</code>, <code>rfcsl</code> and <code>rfpsl</code> are available on Microsoft Windows and the Unix-style <code>man</code> pages mostly apply. However, note that the REDUCE <code>bin</code> folder is not automatically added to the execution path, so by default these commands are only available via their full pathnames (e.g. <code>"C:\Program Files\Reduce\bin\redcsl"</code>), and the command <code>redcsl</code> accepts an optional first argument <code>-nocd</code> that causes it to preserve the working directory instead of setting it to the user's <em>Documents</em> folder; see <a href="/directories.php">Working Directories</a>.
</p>

</div><!-- opened in begin-body.php -->

<?php
include '../include/footer.php';
?>

</body>

</html>