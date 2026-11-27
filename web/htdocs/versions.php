<?php
$header_title = 'Versions';
include '../include/begin-head.php';
include '../include/begin-body.php';
?>

<p>
    REDUCE is based on a dialect of Lisp called
    <i><a href="lisp-docs/sl.pdf">Standard Lisp</a></i>, and the main
    differences between versions of REDUCE are the result of different
    implementations of Standard Lisp; in each case the source code for
    REDUCE itself remains essentially the same. The binary
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
        became Open Source was the Zuse Institute Berlin
        (<a href="https://www.zib.de/">ZIB</a>).
        PSL REDUCE offers only a command-line interface.
    </dd>
    <dt id="csl">
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
        CSL REDUCE offers both a graphical and a command-line interface.
    </dd>
    <dt>
        Common Lisp
    </dt>
    <dd>
        REDUCE can also be
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/common-lisp/README.md">
            built on Common Lisp</a>,
        which is the current standard definition of the Lisp language.
        This works by emulating Standard Lisp in Common Lisp.
        The build details are slightly different for different implementations of Common Lisp.
        Currently,
        <a href="http://www.sbcl.org/">Steel Bank Common Lisp</a> (SBCL),
        <a href="https://clisp.sourceforge.io/">CLISP</a> and
        <a href="https://ccl.clozure.com/">Clozure Common Lisp</a> (CCL) are supported.
        Common Lisp (CL) is not included in the SourceForge REDUCE repository and,
        if not already available, must be installed separately.
        Then building REDUCE on CL is straightforward and very fast.
        However, REDUCE on CL runs slower than on PSL or CSL,
        and a few obscure features may not work correctly on all implementations of CL.
        REDUCE on SBCL is the fastest and most complete version of REDUCE on CL,
        and it is unlikely that a casual user would notice any difference between this and REDUCE on PSL or CSL.
        REDUCE on CL itself provided only a command-line interface, but it runs well in
        <a href="https://fjwright.github.io/Run-REDUCE/">Run-REDUCE</a>
        (which supports typeset mathematical output) and
        <a href="reduce-ide/">REDUCE IDE</a> for the
        <a href="https://www.gnu.org/software/emacs/emacs.html">GNU Emacs</a> editor.
    </dd>
    <dt>
        Other Lisps
    </dt>
    <dd>
        There is also experimental code in the SourceForge Subversion
        repository to build REDUCE on several other Lisps, including
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/REDUCE/">GNU
            Emacs Lisp</a>,
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/jlisp/">Jlisp</a>
        (which is in effect a clone of CSL coded in Java),
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/jslisp/">JSlisp</a>
        (which is an experimental version of Jlisp designed to be compiled into JavaScript),
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/vsl/">the VSL Lisp system</a>
        (the key attribute of which is that it is SMALL), and a
        <a href="https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/new-embedded/for-emscripten/">version
            of CSL compiled to Javascript and WebAssembly</a> (to run
        using Node.js or in a web browser).
    </dd>
</dl>
<h2>REDUCE version numbers and releases</h2>
<p>
    The commercial releases of REDUCE had version numbers, the last of
    which was version 3.8 released in 2004. The Open Source releases
    of REDUCE available since 2008 do not have version numbers, but
    are now identified by their Subversion revision numbers. A REDUCE release includes
    all necessary binary files for a specific platform and releases
    are currently provided irregularly every year or so for Microsoft
    Windows, Apple macOS and GNU/Linux.
    Every so often there may also be a release for a more esoteric
    platform, such as the Raspberry Pi!
</p>
<p>
    A release is essentially a set of files built from a snapshot of
    the source code, which evolves on a daily (if not hourly) basis as
    the developers commit updates. The source code is managed using
    Subversion, which increments the revision number (of the whole
    code base) with each commit, and this now serves as a version
    number. Since the whole code base is now publicly available,
    formal releases are no longer very significant.
</p>

</div><!-- opened in begin-body.php -->

<?php
include '../include/footer.php';
?>

</body>

</html>