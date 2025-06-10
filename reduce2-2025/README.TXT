The files here mostly derive from a version of the REDUCE source from
1973 as recovered from some archive files.

The comments here are by ACN reporting on the experience of getting the code
to run.

The version I started for is the file REDUCE.RED which was for use on
TENEX (is a PDP10)and is dated 25 March 1973. The process of making this
run will have been very similar to the porting process normally needed
for Reduce then when Lisp systems on the various machines it was used on
differed. The start of the file contains a collection of mappings,
definitions and redefinitions that LIsp 1.6 on TENEX did not support
or where it used different names. I have had to replace or override these
with code that has the same intent but to set up compatibility with the
small Lisp system that I am using.

The code show signs of a range of compatibility issues it had encountered.
The ones that seem most notable to me are:

There is also a Reduce source file dated 15 September 1972 that is all
in Lisp. It includes many checks of the form (EQ *MODE (QUOTE SYMBOLIC) and
that amounts to a signature of a system where executable parts of Reduce
would be written in its own language. As in (1) that follows it is clear
that LISP/360 was not offering a string data type. A version of Reduce in its
own language needed a directly Lisp-coded for bootstrapping, so Lisp
versions like this will have persisted for a while even when the main
development had moved on. 

(1) Some Lisp systems supported strings (as in "I am a string") as
    a native data structure while other did not. It looks as if Reduce
    could at one time run using a representation (string ordinarysymbol)
    to represent a string.
(2) There are functions EXPLODE and COMPRESS that map between symbols
    and numbers (and perhaps strings) and lists of characters. The
    behaviour of these on symbols whose names included whitespace or
    punctuation marks was not fully stable. Specifically using COMPRESS
    on a list consiting of (* a b c) might produce a symbol called *abc
    or it might stop at the "*" and need escape characters to support
    unusually spelt characters. And then EXPLODE might or might not
    insert those escape characters.
(3) The Lisp might or might not provide vectors or arrays, and if it did
    the names of the functions involved were not standardized. Reduce
    could potentially exploit a rich Lisp, but otherwise would represent
    a vector as a list. If the underlying Lisp provided a function VECTORP
    that tested for a "real" vector but Reduce was using its emulated ones
    consusion could arise.
(4) If FN is the name of a Lisp variable, should (FN arg) invoke the
    function or would it be necessary to use (apply FN (list arg))? The
    terminology used regarding this was "is it a Lisp-1 or a Lisp-2?".
(5) A whole range of small utility functions might either not be provided
    by the Lisp or might be present but under a different name - or
    with arguments taken in a different order!
(6) Back in the early 1970s taking the stream of input characters and
    turning it into a stream of symbols felp expensive, and any particular
    Lisp might have desirable built-in functions that could really help
    but would not port to other platforms.
(7) Character classification in support of (6) could be untidy. See for
    instance this fragment from REDUCE.RED that identifies letters:
        SYMBOLIC PROCEDURE LITER X;
           NULL NUMBERP X AND
           (X := LSH (MAKNUM(CAAR GET(X,'PNAME),'FIXNUM),-11))>64
            AND 91>X;
    where the MAKNUM and the shift are not very portable and it is clear
    that lower case letters had not been invented.
(8) REDUCE.RED contains a 4-line assembly code function for use for
    ordering variables. That needs adjustment.
(9) Anything that is specific to interavtive vs batch use is of course
    "delicate".

However the PDP10 scheme for covering all the above is just a clearly
separated out 500 line prelude to the main Reduce code.

Once Reduce is built it should be able to parse its own source - but of
course at the start of testing it has not been built! So to bootstrap
it one starts by using an existing running version of Reduce to
parse REDUCE.RED and emit the raw Lisp equivalent. Well of course for
pragmentic reasons some of the machine-sensitive customizations are done
ahead of that conversion. A current (ie 2025) version of Reduce was used
to make a file reduce.lsp. For this conversion a number of behaviours
that the current parser would have exhibited needed to be disabled, either
by removing tags from property lists or by hiding some symbols completely.
The file reduce.red was then hand-edited further to gain the level of
compatibility between 1973 and 2025 standards that was needed.

The resulting reduce.lsp was loaded into a Lisp system known as "vsl".
This is a fairly minimal Lisp that consists of 3500 lines of C code
implementing much of the "Standard Lisp" that later versions of Reduce
settled on. It is complete enough that it can run an up to date version
of Reduce, but is an interpreter-only system and so is not very fast.
The aim was that the C code should be fairly spartan, and so for instance
at that level it supports CAR and CDR. All the combinations such as
CDADR and so on are then defined in Lisp in a file vsl.lsp. That file
also provides the functions to append and reverse and search lists. But the
two big sections of codin in vsl.lsp are the ones that support big integers
and that can prettyprint (ie print with neat indentation) Lisp code.
Well in 1973 many Lisp systems did not support integers with more bits than
would fit in a machine register. vsl.c provides for a represention of
overlarge integers but leaves all arithmetic on them to lisp code in vsl.lsp,
where the numbers are handled as list of digits. Performance took second
place to code simplicity.
I could have modified vsl to support the ancient Reduce more directly,
but instead I modified reduce.lsp to live with it.

The result of all of the above is a workable Reduce (which will without
doubt have residual errors and limitations above and beyond the ones
inherent from its age). The test applied for it is a file that in
a modern copy of Reduce would live as packages/alg/alg.tst and which
was for very many years treated as the definitive demonstration and main
test for Reduce. Tony Hearn collected timings from running it on many
computers (dedicated Lisp machines, departmental servers, mainframes,
supercomputers and various more personal machines) and today it feels
amazing that the really crude implementation reported here is dramatically
faster then a whole range of impressive and expensive hardware from the
past. "REDUCE as a Lisp Benchmark" by Marti and Hearn (ACM SIGSAM Bulletin,
Volume 19, Issue 3 Pages 8 - 16) 1985. As what may be a key illustration of
this test ran for most of a minute on a VAX 11/780 or for 5 or 6 seconds
on the fastest IBM mainframe of the day. The current crudely implemented
interpreter-only Lisp running on a 7 year old (and hence not really
cutting edge) x86_64 pc completes the run in about 0.3 second.

I point that I note is that the underlying representation used for
polynomials and for rational functions has conspicuously not changed
from usage in the early sources. The functions ADDF, ADDSQ and flags such
as !*MCD, along with the general framework for simplifications using a
function SIMP that dispatches based on the identity of the expression it
is handed has the same overall structure even though a range of detailed
changes and upgrades have been applied. The same holds true for much of
code for both parsing and printing: the function names in the old code
will be really familiar to those who work with the current system.


ACN March 2025
