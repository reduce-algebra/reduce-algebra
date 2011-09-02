This document explains how to build or rebuild REDUCE 3.7
using the CSL Lisp system.  A number of different possibilities
arise depending on whether you have a C compiler available (and
in some cases which one!) and how comprehensive a re-build is
wanted.  I will start with the simplest case.

(0) Before you begin.
If you are running on some version of Unix it may be that file-permissions
were not set up when the REDUCE files moved to your machine. Select the
"lisp/csl/util" dircetory as current and run the script "setexec"
         source setexec
to correct this.



(1) Recompilation of all of REDUCE after some source files have
    changed.

Make the directory containing the REDUCE executable (r37.exe or r37)
your current directory. This directory will have a path-name that
ends up ".../lisp/csl/<machine>" where the final component refers
to the type of computer you are using. Examples are "win32" or "linux".
In all the file-names that I quote here I will use "/" as the directory
separator, however on Windows systems you will need to use "\" instead.

Optionally make a copy of the existing r37.img and then delete the
existing file of that name. The merits of making a backup copy of the
image file should be obvious. Deleting r37.img before running the
build job will reduce your peak demands on disc space. Run the script:
           ../util/full37
Note that on a 400 MHz Pentium II system this runs for around 3 minutes.
All future timings I quote will be in terms of this reference configuration.
On slower or faster machines it will take different amounts of time of
course.  A log of what has happened will be placed in log/full37.log. The
most you are really likely to want to do with this is to scan it to verify
that it ends up saying something like

    +++ untrrl compiled, 56 + 36 bytes
    +++ untrrlid compiled, 44 + 28 bytes
    +++ FASLEND: hits = 372, misses = 144
    Fast-loading "E:\r37\lisp\csl\win32\R37.IMG(rtrace)"
    
    The system is about to do a restart...
    Dump file created: Sat Jan 23 16:31:35 1999
    REDUCE 3.7, 15-Jan-99 ...
    Memory allocation: 10213632 bytes
    Fast-loading "E:\r37\lisp\csl\win32\R37.IMG(user)"
    
    End of Lisp run after 142.15+10.14 seconds

and that it does not contain the string "Error".

You should now check the resulting system, either by trying your own
code on it, or by running and then checking all the standard test cases.
To run a full set of tests just run
           ../util/testall
but be aware that this runs for around half an hour. This is because REDUCE
has a substantial number of test files that check and illustrate all of its
capabilities.  Running "testall" leaves a set of new log files close to the
top-level in the REDUCE tree. From where your current directory they are in
"../../../log/*.rlg". If especially interested in just a few of them you
can check them by hand, but a further script
           ../util/checkall                  [not yet provided]
compares all these logs against a reference set and produces summary
information in "log/checkall.log". This file is intended to be short enough
to be worth reading.  Note that a major reason for rebuilding REDUCE will
be to incorporate some corrections or enhancements and it is very probable
that these will cause some logs to change from the original reference set.
Thus discrepancies reported in log/checkall.log do not necessarily indicate
problems!

If you go
          ../util/testall XXX
where XXX is the name of a REDUCE package (eg "alg") then this will run
the test script for (just) that module.

(2) Rebuild everything from source.
At the other extreme you may wish to re-create everything from source,
including re-building the underlying Lisp system.  The steps are as follows.

(2.a) Create an empty directory ".../lisp/csl/<machine>" named suitably
for your environment. Select it as your current directory.

(2.b) If there is a suitable Makefile in ../util then copy it or link it
into the current directory: eg
        copy ..\util\Makefile.w32 Makefile     [Windows, Watcom C]
or      ln -s ../util/Makefile.linux Makefile  [Linux]
If no pre-build Makefile is available then you may be able to create
one using the "makemake" program in the util directory: read the comments
and explanation in it and the "makebase" file, but it will probably
be easiest for you to copy a generic Unix Makefile and edit it by hand to suit
your needs.  The Makefile is intended to be conservative and does little more
than explain which C files to compile and link.  If you have a C compiler
but it does not use textual Makefiles then inspect the link steps
in the provided ones to see which source files need to be compiled.

Note that the directory may contain a "Makefile.cyg" for use with the Cygnus
compilers for Windows.  Observe from the Cygnus FAQ
   In particular, if you intend to port a commercial (non-GPL'd)
   application using Cygwin, you will need the commercial license to Cygwin
   that comes with the supported native Win32 GNUPro product.  The price
   for five users is $7495, which includes the GNUPro Toolkit, Mission
   Critical Support for one year, and a commercially licensed version of
   the Cygwin library.  For more information about the commercial-use
   license, please contact info@cygnus.com.  All other questions should be
   sent to the project mailing list gnu-win32@cygnus.com.
and Codemist will neither distribute binaries compiled using this
system nor provide guaranteed support for those who decide that re-compiling
REDUCE using this compiler is a good idea.



(2.c) Build slowr37 (slowr37.exe on Windows)
         make slowr37           [Unix]
         make slowr37.exe       [Windows]
This is a basic version of the CSL Lisp system and at this stage is only
useful for building the bootstrap version of REDUCE.

(2.d) Create a bootstrap version of REDUCE. The image file for this will
be around 8 Mbytes large, and the system will run much more slowly than the
final and proper version of REDUCE. However it should be able to run all
REDUCE tests properly.
         ../util/boot37
where a log is left on log/boot37.log. This step takes around 3 minutes.

(2.e) Optionally run ../util/testslow, expecting it to run for around
an hour. Logs are left where test logs for the final system will be, so
../util/checkall can be used to verify that all is under control, although
most of the time you will not want to spend time of this verification step.

(2.f) If you are starting completely from scratch it is necessary to
collect profile information which is used to determine which parts of
REDUCE should be most carefully optimised. If you already have a file
"../csl-c/profile.dat" you may omit this step, but after significant changes
or as a demonstration of a complete fresh start it may be useful. Run
         ../util/profile
and wait around an hour for it to create a file "profile.dat" in the current
directory. This file lists the modules tested and for each gives an
ordered list of functions, each accompanied by a long string of digits that
are a digital signature for the version of the function that was involved.
Copy profile.dat as ../csl-c/profile.dat (optionally backing up your
original copy) and delete it from the current directory.

(2.g) Run the script
         ../util/c-code37
which uses ../csl-c/profile.dat and the bootstrap image to create twelve
files of C code (../csl-c/u01.c to ../csl-c/u12.c) and twelve corresponding
Lisp files (same file-names but with ".lsp" as their suffix). These files
represent optimised versions of the most important parts of REDUCE.

(2.h) Create the main REDUCE executable (r37 or r37.exe)
         make r37               [Unix]
         make r37.exe           [Windows]
and just to be safe please delete r37.img, since the image file depends on
the set of things created in step (2.g) above and so is probably now
out of date.  WARNING: running a reduce executable with an image file
that it does not correspond to can lead to unpredictable failure, so although
image files are portable from one machine architecture to another they
must be used with a REDUCE executable that was built with the same set of
file u01.c through u12.c.
[Can I generate a scheme that will allow me to soften this warning, or will
at least check for compatibility when the system is loaded?]

(2.i) Make the final image file. This is exactly the step described as
the simple case:
         ../util/full37

(2.j) Test the new system as documented towards the top of this document.

