/* doc.h                        Copyright (C) 1991-4 Codemist Ltd */

/* Signature: 440bda8c 08-Dec-1995 */

Although this file is stored with suffix ".h" it is not intended to be
compiled. It is just documentation about CSL and its history.

-------------------------------------------------------------------------------

April 95:

Introduce vectors containing binary.
   mkvect8/mkvect16/mkvect32/fmkvect32/fmkvect64
to hold 8, 16 and 32 bit (unboxed) integers and 32/64 bit (unboxed) floats.

Access via putv8/getv8 putv16/getv16 putv32/getv32 fputv32/fgetv32
fputv64/fgetv64.  NOT integrated with other (generic) vectore handling
functions.

double-execute() and undouble-execute() are like trace() and untrace() but
cause the nominated functions to double their costs. Only at first actually
does anything for functions with fixed nuymbers of args.

November 94:

Introduction of "mixed" vectors.

October/November 94:

Adjustment of various source files to support Watcom C 10.0 as well as
Zortech, GCC and Microsoft foir use on 80x86.


May 30 1994:

In COMMON Lisp mode the compiler now supports FLET, LABELS and PROGV.
Interpreted PROGV mended.

May 20 1994:

Bug fixed in preserve.c that meant that on 16 bit machines compressing a heap
image could loop if a suitable segment boundary in the file fell on a
64Kbyte boundary! Some attempt to make bytestream_interpret more compact
by moving some fragments of it out of line.

May 18 1994:

PRESERVE now (really) has optional args.  First specifies a restart function
to be called, the second is a banner to display when the image is reloaded.
Reduce now uses this mechanism to gets its banner displayed.

Lexical closures supported in the bytecode compiler (for variable reference
but not GO or RETURN-FROM) and 3 new opcodes (closure, loadlex, storelex)
introduced in bytes1.c to support same.

May 16 1994:

By default the MSB of pointers is now determined at run time (rather than
being a manifest value compiled into the code).  Exception conditions
changed to set the 1 bit of nil rather than the 0x80000000 bit.  More
macros used to test and set exception conditions.

286 version uses software ticks.  Seems as if real asynchronous ticks
are needed most on just those machines least liable to support them reliably.

Output column control used to be muddled between stdout (eg trace) output
and regfular user printing.  Now improved.

Better build procedures for patches and updated help files for REDUCE, and
initial banner for Reduce displayed earlier.

May 1 1994:

Support for calls to functions with large numbers of arguments is
improved. In particular in Common Lisp mode it is possible to have
more than 50 args.

Line-length overflow checking for printing of big numbers implemented.

binary printing for numbers, and case fold up as well as down, supported.

Demonstration version of Reduce brought back into step with rest of system.

car and filesign utilities scan files in alphabetic order under DOS and NT.

'demo put in lispsytem!* list if help function available.

build files for Reduce include help system and patches, and can build
demonstration system correctly.

-------------------------------------------------------------------------------

DATA REPRESENTATION
===================

All objects in CSL are represented by 32-bit words, and each object in
memory is aligned at an 8-byte boundary.  The bottom 3 bits of a word
aare used as tags, and indicate how the rest of the word should be
interpreted.  In some cases the rest of the word is just direct information
(eg small integers are handled this way) and then the 0x8-bit is used by
the garbage collecter.  In other cases the 32-bit word contains the address
in memory of some object, and in that case its most significant bit is
reserved for use by the garbage collector.  Thus all valid addresses must have
the same sign (but this can be either + or -).  Many objects in memory have
a header word at their start that indicates their length and gives more
details about their type.  The encoding of object lengths means that the
largest possible single object in CSL would be 4 Mbytes long.

The coding in the low bits of a word is as follows:

    x x x | x 0 0 0      cons cell (and NIL in Common Lisp mode)
    x x x | G 0 0 1      28-bit integer (G = garbage collector bit)
    x x x | G 0 1 0      characters, vec-hdrs, other oddities (immediate)
    x x x | G 0 1 1      28-bit short float if Common Lisp mode
    x x x | x 1 0 0      a symbol
    x x x | x 1 0 1      bignum. {rational number, complex number}
    x x x | x 1 1 0      Lisp vector (includes strings etc)
    x x x | x 1 1 1      pointer to boxed floating point number

Pointers reserve the 0x80000000L bit for the garbage collector,
assuming that all addresses are in the same half of the space.  This
of course is a slightly dodgy assumption that may be false on some
computers.



Header words in the vector heap

If the bottom 3 bits of a word are 010 (TAG_ODDS) the word is
treated as immediate data.  In that case the 1000 bit (GC_BIT_I)
is kept free for use as a mark bit.  The next bits up classify the
object:
          | x x 0 0 | * 0 1 0       valid immediate date in heap
                                    but can also be used as vector headers
          | x x 0 1 | * 0 1 0       symbol headers
          | x x 1 0 | * 0 1 0       number headers
          | x x 1 1 | * 0 1 0       vector headers

Data that could be in the heap or on the stack decodes further:

      x x | 0 0 0 0 | * 0 1 0       character
      x x | 0 1 0 0 | * 0 1 0       handle/offset to BPS page
      x x | 1 0 0 0 | * 0 1 0       [handle/offset to literal vector]
      x x | 1 1 0 0 | * 0 1 0       special marker (SPID) left on stack
                                    to help interpreter

The remaining 24 bits of the word are available for data.  The BPS and
literal vector handles in this case are for a segmented memory
implementation, and the 24 bit address has its top 10 bits identifying
a page number, then 14 bits giving a WORD offset into the associated
page, which can thus be up to 64 Kbytes large. Or more depending on
PAGE_BITS.  Literal vectors done this way are not used at present.
For Standard Lisp only 8 bits of character information is needed - the
remaining bits are there to support font etc information in a Common
Lisp world.


  . . . . | g f 0 1 | * 0 1 0       symbol header
        g   global variable
        f   fluid (special) variable
The remaining bits in the word are used as follows
    00000100  symbol names a special form
    00000200  symbol has a definition as a macro
    00000400  an unprinted gensym (so print-name is not complete yet)
    00000800  has a definition in C from the C-coded kernel
    00001000  just carries a code-pointer (codep test)
    00002000  any gensym, printed or not
    000fc000  fastget code in this is used as a p-list indicator
    00100000  traced
    00200000  is external in its home package
    ffc00000  reachability in first ten packages


The remaining header words hold the length (in bytes) of the object
(including the length of the header word) in the upper 22 bits of the
word.  This puts a limit of 4 Mbytes on the largest possible single
object in this Lisp.

      0 0 | 0 0 1 0 | * 0 1 0       bignum header word
      0 0 | 0 1 1 0 | * 0 1 0       ratnum
      0 0 | 1 0 1 0 | * 0 1 0       complex number
      0 0 | 1 1 1 0 | * 0 1 0       NOT USED (non-float number)
      0 1 | 0 0 1 0 | * 0 1 0       single float
      0 1 | 0 1 1 0 | * 0 1 0       double float
      0 1 | 1 0 1 0 | * 0 1 0       long float
      0 1 | 1 1 1 0 | * 0 1 0       NOT USED (floating number)


Note that headers for numbers are 0x|xx10|x010 and the 0x100 bit flags
floating point cases


      n n | n 0 1 1 | * 0 1 0       bitvector with nnn bits in last byte

      0 0 | 0 1 1 1 | * 0 1 0       string
      0 0 | 1 0 1 1 | * 0 1 0       (bitvector)
      0 0 | 1 1 1 1 | * 0 1 0       simple vector
      0 1 | 0 0 1 1 | * 0 1 0       (bitvector)
      0 1 | 0 1 1 1 | * 0 1 0       BPS
      0 1 | 1 0 1 1 | * 0 1 0       (bitvector)
      0 1 | 1 1 1 1 | * 0 1 0       hash table
      1 0 | 0 0 1 1 | * 0 1 0       (bitvector)
      1 0 | 0 1 1 1 | * 0 1 0       SPARE contains binary data
      1 0 | 1 0 1 1 | * 0 1 0       (bitvector)
      1 0 | 1 1 1 1 | * 0 1 0       Common Lisp array (header block)
      1 1 | 0 0 1 1 | * 0 1 0       (bitvector)
      1 1 | 0 1 1 1 | * 0 1 0       encapsulated stack pointer
      1 1 | 1 0 1 1 | * 0 1 0       (bitvector)
      1 1 | 1 1 1 1 | * 0 1 0       Common Lisp structure

                                    (use BPS for vector of 8-bit ints)
      1 0 | 0 0 1 0 | * 0 1 0       vector of 16-bit integers
      1 0 | 0 1 1 0 | * 0 1 0       vector of 32-bit integers
      1 0 | 1 0 1 0 | * 0 1 0       MIXED1 [3 words of pointers, then binary]
      1 0 | 1 1 1 0 | * 0 1 0       MIXED2
      1 1 | 0 0 1 0 | * 0 1 0       vector of single-precision floats
      1 1 | 0 1 1 0 | * 0 1 0       vector of double-precision floats
      1 1 | 1 0 1 0 | * 0 1 0       MIXED3
      1 1 | 1 1 1 0 | * 0 1 0       Stream handle (aka MIXED4)


-------------------------------------------------------------------------------


/* end of doc.h */
