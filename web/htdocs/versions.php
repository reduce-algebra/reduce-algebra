<?php
$header_title = 'Versions';
include './include/begin-head.php';
include './include/begin-body.php';
?>

<p>
    REDUCE is based on a dialect of Lisp called
    <i><a href="lisp-docs/sl.pdf">Standard Lisp</a></i>, and the main
    differences between versions of REDUCE are the result of different
    implementations of Standard Lisp; in each case the source code for
    REDUCE itself remains essentially the same.  The binary
    distributions of REDUCE available from SourceForge are based on
    two different implementations of Standard Lisp, namely PSL and
    CSL:
</p>
<dl>
    <dt>
        Portable Standard Lisp (PSL)
    </dt>
    <dd>
        PSL was the original implementation of Standard Lisp, but now
        contains many more facilities. It is quite efficient in its
        use of both space and time, and has been optimized for
        algebraic computation. All PSL versions of REDUCE are
        distributed with sufficient PSL support to run on the given
        computing system. PSL is supported on many architectures and
        is an ideal system for those wanting to run REDUCE as a
        stand-alone system. The principal developer of PSL before it
        became Open Source was the Konrad Zuse Center, Berlin
        (<a href="http://www.zib.de/">ZIB</a>).
    </dd>
    <dt>
        Codemist Standard Lisp (CSL)
    </dt>
    <dd>
        CSL is a newer Lisp system that continues to evolve and is now
        written completely in C++, which makes it very easy to port to
        a new machine. Like PSL, it is a faithful implementation of
        Standard Lisp and has been optimized for running REDUCE. It
        requires a very small memory partition for its Lisp
        support. Furthermore, most of the REDUCE facilities are
        supported as machine independent pseudocode, which is quite
        compact. In the worst case, the performance of this system is
        about a factor of two slower than PSL, though in many cases it
        matches PSL performance. However, the memory use is
        smaller. All CSL versions are distributed with sufficient CSL
        support to run on the given computing system. This is also an
        ideal system for those wishing to embed algebraic calculations
        in a C or C++ programming environment. The developer of CSL
        before it became Open Source was
        <a href="http://www.codemist.co.uk/">Codemist Ltd</a>.
    </dd>
    <dt>
        Other Lisps
    </dt>
    <dd>
        There is also experimental code in the SourceForge Subversion
        repository to build REDUCE on
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/REDUCE/">GNU
            Emacs Lisp</a>, three versions of
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/common-lisp/">Common
            Lisp</a> (SBCL, CLISP and ABCL), and a
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/new-embedded/for-emscripten/">version
        of CSL compiled to Javascript and webassemply</a> (to run
        using Node.js or in a web browser).
    </dd>
</dl>
<h2>REDUCE version numbers and releases</h2>
<p>
    The commercial releases of REDUCE had version numbers, the last of
    which was version 3.8 released in 2004.  The Open Source releases
    of REDUCE available since 2008 do not have version numbers, but
    are now identified by revision numbers.  A REDUCE release includes
    all necessary binary files for a specific platform and releases
    are currently provided irregularly every few months for Microsoft
    Windows, Apple MacOS and GNU/Linux (all at the same time).  Every
    so often there may also be a release for a more esoteric platform,
    such as the Raspberry Pi!
</p>
<p>
    A release is essentially a set of files built from a snapshot of
    the source code, which evolves on a daily (if not hourly) basis as
    the developers commit updates.  The source code is managed using
    Subversion, which increments the revision number (of the whole
    code base) with each commit, and this now serves as a version
    number.  Since the whole code base is now publicly available,
    formal releases are no longer very significant.
</p>

</div><!-- opened in begin-body.php -->

<?php
include './include/footer.php';
?>

</body>
</html>
