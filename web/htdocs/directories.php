<?php
$header_title = 'Working Directories';
include './include/begin-head.php';
?>

<style>
table {
    width: 100%;
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
include './include/begin-body.php';
?>

<p>
    The portable REDUCE source code does not support the concept of a working directory (nor does Standard Lisp),
    but actual Lisp implementations normally do, albeit in slightly different ways. This document outlines the
    support provided by PSL and CSL from REDUCE algebraic mode. PSL support is described in the PSL Users
    Manual <small>[ <a href="/lisp-docs/allman1.html">HTML</a> | <a href="/lisp-docs/allman1.pdf">PDF</a> ]</small>.
    Other Lisps can be expected to provide broadly similar support. Working directory is abbreviated to WD and the
    WD to be selected is indicated by <em>dir</em> below.
</p>

<h2>Initial WD on Microsoft Windows</h2>

<p>
    When invoked from the Windows <em>Start</em> menu, both PSL and CSL REDUCE have their initial WD set to the user's
    <em>Documents</em> folder. When CSL REDUCE is invoked using the command <code>redcsl</code> the initial WD is also
    set to the user's <em>Documents</em> folder by default, for consistency, but if <code>redcsl</code> is called with
    <em>first</em> argument <code>-nocd</code> then the WD is preserved, i.e. the initial WD for REDUCE is the current
    WD of the shell or other application that invoked it. When PSL REDUCE is invoked using the command
    <code>redpsl</code> the WD is always preserved, i.e. it is the current WD of the shell or other application that
    invoked it.
</p>
<p>
    The behaviour on <a href="https://www.cygwin.com/">Cygwin</a> is the same as on other Unix-like platforms; see
    below.
</p>

<h2>Initial WD on Unix-like Platforms</h2>

<p>
    When invoked from the desktop, both PSL and CSL REDUCE have their initial WD set to the user's home directory,
    i.e. the value of the environment variable <code>HOME</code>. When invoked using the command <code>redpsl</code>
    or <code>redcsl</code> the WD is preserved, i.e. it is the current WD of the shell or other application that
    invoked REDUCE.
</p>

<h2>Discovering and Changing the WD</h2>

<table>
    <thead>
        <tr>
            <th>What</th>
            <th>PSL REDUCE</th>
            <th>CSL REDUCE GUI</th>
            <th>CSL REDUCE CLI</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Get</td>
            <td><code>pwd();</code> returns string</td>
            <td>Click on <em>Read...</em> or <em>Save...</em> in the <em>File</em> menu.</td>
            <td>Windows: <code>system "cd"$</code><br />
                Unix-like: <code>system "pwd"$</code><br />
                outputs to terminal</td>
        </tr>
        <tr>
            <td>Set</td>
            <td><code>cd "<em>dir</em>";</code></td>
            <td>Select using <em>Read...</em> or <em>Save...</em> in the <em>File</em> menu, or<br />
                <code>lisp chdir "<em>dir</em>";</code>
            </td>
            <td><code>lisp chdir "<em>dir</em>";</code></td>
        </tr>
    </tbody>
</table>

</div><!-- opened in begin-body.php -->

<?php
include './include/footer.php';
?>

</body>

</html>