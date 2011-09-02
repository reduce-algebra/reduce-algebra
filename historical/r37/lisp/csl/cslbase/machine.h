/* machine.h                  Copyright (C) 1990-2002 Codemist Ltd */

/*
 * Set characteristics of machine given type.  This ought to be the only
 * file that inspects macros predefined by your compiler, and on the basis
 * of those it sets a further set of macros that identify features
 * that characterise your computer.  If you move CSL to a new computer
 * you should expect to have to add a few lines to this file.
 * Ideally all macros used with #ifdef should be mentioned in this file,
 * as documentation about what is available.  At any one time that will
 * not be so as (for instance) short-term debugging control things will
 * come and go...
 * I will try to put comments about each symbol the first time it is
 * mentioned here.
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */

/* Signature: 1ccdfd3d 28-Feb-2003 */


#ifndef header_machine_h
#define header_machine_h 1

#include <stdio.h>      /* almost everybody needs this               */
#include <stdlib.h>
#include <signal.h>     /* needed for errorset & floating exceptions */

/*
 * The macro COMMON decides if the code is being built to implement
 * a Common Lisp or a Standard Lisp.  If you want to build a Common
 * Lisp you should arrange that your makefiles establish -DCOMMON=1 as
 * a command-line option for the C compiler.  NB with the COMMON option
 * you need a set of Lisp sources to build lots of higher level Common
 * Lisp functions, and these are not provided when CSL is shipped for
 * use with Reduce.
 */

/*
 * I want COMMON Lisp mode systems to use 18-page bits even on small
 * machines, so that image files can port between those and big systems.
 * As of April 1995 I will do the same for Standard Lisp, so that image
 * files are always cross-portable. If this puts too heavy a load on memory
 * on the remaining systems that do not support virtual memory then I could
 * go back down to using 16-bits, but that also limits the size of the largest
 * supported vector, biggest bignum etc.
 * In April 2002 I change this to 22, giving 4 Mbyte pages. Because of the
 * way that vector-headers are packed that is a limit on the size of objects
 * anyway sountil I do more radical re-work (inclusing perhaps a universal
 * move to 64-bit items) this as as far as it can go.
 */
#define SMALL_PAGE_BITS 22

/*
 * It is assumed that all addresses are 32-bits long (i.e. sizeof(void *)==4),
 * and that the sign of (long int)malloc(...) is always the same.  For
 * some segmented machines, and possibly the transputer, malloc'd addresses
 * may look negative and I am supposed to be able to cope with this.
 * Also ANSI do not specify what happens when you go
 *   int p = ((int)q) >> n;
 * with respect to sign-bit propagation.  On many (most?) machines shifts
 * on signed values will be arithmetic (i.e. propagate the sign bit)
 * but I have tried to identify places where I rely on this and provide
 * alternative code for use when signed shifts are logical.
 *
 * The case of 64-bit addresses is under investigation for the DEC Alpha;
 * that case works provided all CSL memory can be put at addresses lower
 * than 0x7fffffff. The DEC/OSF "-taso" linker option supports that.
 * An extended and more genuine version for 64-bit arithmetic and addresses
 * is also part of an experiment, but that will not be complete for
 * some while [Sept 1997].
 * Well, in fact I now seem to be able to run on genuine 64-bit architectures
 * (testing on NetBSD on a DEC Alpha)... [2001]
 */

#undef  SIGNED_SHIFTS_ARE_LOGICAL   /* I hope I never have to activate this */

#define MEGABYTE                ((unsigned32)0x100000U)

/*
 * I will define SOCKETS if a BSD-like socket library is available. Since
 * this is so on most important targets I will make it the default and
 * I will put an "#undef SOCKETS" where needbe, or go "-DNO_SOCKETS" when
 * I compile.
 */
#ifndef NO_SOCKETS
#define SOCKETS                  1
#endif

/*
 * When WXWIN is defined I should be building using the wxWindows cross-
 * platform toolkit. In this case I will define CWIN too since the way I
 * interface to wxWindows is in many respects similar to that which I
 * originally used with my own CWIN windows code (which is built on the
 * MFC libraries). If I use either of those I will specify "WINDOW_SYSTEM"
 * too.
 */

#ifdef WXWIN
#  ifndef CWIN
#     define CWIN 1
#  endif
#endif


/*
 * __WATCOMC__ is defined by Watcom C compilers. Note that some time in
 * 2002 the Watcom compilers turned open-source. I expect this compiler to
 * be associated with DOS/Windows and so if a version of Watcom for
 * some non x86 architecture or for a non-Microsoft operating system is
 * released some further adjustment will be needed here. Also note that for
 * the Windows build I need to link in the Microsoft Foundation Classes (MFC)
 * and those may not be available with OpenWatcom. So if I am using
 * OpenWatcom I will need to build either a command-line version or
 * the wxWindows variant.
 */
 
#ifdef __WATCOMC__

#ifndef __SW_3R
/*
 * I really want this to have /3r or /5r calling conventions so that native
 * code and imulwat.asm can interface properly.
 */
#error Watcom C to be used with register (default) calling conventions, /5r
#endif

#ifndef WINDOWS_NT
/*
 * IMPNAME names the version of CSL that I am compiling.  It is made
 * available as a string as the initial value of a variable IMPNAME. Note
 * that undue reliance upon this can make Lisp checkpoint images non-portable.
 */
#  define IMPNAME               "DOS-386"
/*
 * NATIVE_CODE_TAG is used as an identification number that indicates
 * what hard machine code conventions (this must include register conventions
 * as well as base machine architecture) apply in this version. When
 * any Lisp is compiled into real machine code the stored version of same
 * is marked with the value of NATIVE_CODE_TAG. If the image file that
 * results is loaded into a copy of CSL that uses the same tag then the
 * compiled code will be used. Otherwise it must not be. The objective here
 * is that a single image file *might* contain real machine code for
 * several architectures and I need to avoid mixups. Note that one
 * processor (eg Intel) may have different calling conventions (say
 * DOS/386, Windows and Linux) and one operating system and compiler may exist
 * on several different CPU architectures (eg Linux or generic UNix).
 * If I do not set a specific value of NATIVE_CODE_TAG it will default
 * to the value 0, which will be taken to mean "not available on this
 * version", which is at least a fairly safe situation.
 * I will also provide for a run-time computed extension to this tag
 * so that I can cope with machines that are very similar indeed but where
 * different optimisations are appropriate.
 */
#  define NATIVE_CODE_TAG       1    /* DOS, Watcom, DOS4GW */
/*
 * Identify operating system being used
 */
#  define MS_DOS                1
#  undef SOCKETS
/*
 * Identify the C compiler that I will use
 */
#  define WATCOM                1
#  define IMULTIPLY             1
#  define IDIVIDE               1
/*
 * PAGE_BITS controls the size of page that CSL allocates memory in. For
 * 16-bit DOS this MUST be at most 16.  Making it smaller would limit the
 * largest size of vectors and bignums in a bad way.  For other systems it
 * can be (modestly) increased.  If not set in this file a sensible default
 * applies.  Keeping PAGE_BITS reasonably small makes some sense on machines
 * that do not have virtual memory, in that it reduces wastage due to
 * page granularity.
 */
#  define PAGE_BITS             SMALL_PAGE_BITS
/*
 * On computers with lots of registers I choose to keep many important
 * variables where they can be addressed relative to one pointer, nil.
 * On register-poor machines this is silly, and I use regular external
 * variables instead.  NILSEG_EXTERNS selects this option. The incantation
 * -DNILSEG_REGISTER=1 when compiling can override this...
 */
#ifndef NILSEG_REGISTER
#  define NILSEG_EXTERNS        1   /* externs.h */
#endif
/*
 * See "tags.h" - these symbols control the size of memory that can
 * be accomodated, and under MSDOS there is a limit at 16 Mbytes anyway,
 * so allocating tables that could map more would be silly.
 * It is valid to set MAX_HEAPSIZE up to 2048*MEGABYTE (probably!),
 * but bit-packing for code-pointers (for bytecoded functions) means that
 * MAX_BPSSIZE MUST be no larger than (64*MEGABYTE).  Keeping these
 * values realistically small will save (a modest amount of) space for
 * tables of pages.  If you do not set values in this header file some
 * sensible default values will apply, so values are only set here for
 * "small" machines where saving a few kilobytes may matter.
 * The default values will be 1Gbyte of heap plus 64 Mbytes of compiled
 * bytecode (and another 64 Mbytes of hard code, in any case where that
 * option is supported).
 */
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
/*
 * On this (and some other machines) a steady stream of clock
 * ticks is available - I make these soft-interrupt CSL on a regular basis
 * and can then poll a window manager, refresh the screen, check for ^C
 * interrupts or whatever else needs doing.
 * The details will tend to be rather system specific.
 */
#  define TICK_STREAM           1
/*
 * On some systems I will improve real speed or at the least arrange that
 * the times I record are not polluted by slow physical IO by buffering
 * screen updates.  BUFFERED_STDOUT enables this.  NEEDS_CARRIAGE_RETURN
 * must be set if buffers written by fwrite() need to have '\r' as well as
 * '\n' characters in them to mark line ends.
 */
#  define BUFFERED_STDOUT       1
#  define NEEDS_CARRIAGE_RETURN 1
/*
 * If POLL_FOR_ATTN is defined than a function poll_for_attn will
 * be called early in the handling of a clock tick, and the call
 * can set interrupt_pending is a ^C (or similar event) has been
 * requested by the user but not yet processed.  This is done when
 * detection of such events involves active interaction with the
 * operating system.  E.g. under MSDOS the ^C interrupt is not taken
 * until a system call is made, so poll_for_attn() just does an otherwise
 * fairly cheap and harmless system call.
 */
#  define POLL_FOR_ATTN         1
/*
 * HELP_SYSTEM is defined if (inside the Lisp) I allow for keeping a database
 * of messages that get scanned by a function called "help". Actually these
 * days the default is to include help support and NO_HELP_SYSTEM must be
 * defined to disable it.
 */
#  define HELP_SYSTEM           1
#endif /* end of DOS variant of Watcom */
#endif /* __WATCOMC__ */

/*
 * The section here supports LCC as a (free) C compiler in a DOS-box.
 * LCC is very portable but MAYBE a DOS-like system is a good enough
 * starting place for anybody who wants to try it out.
 */

#ifdef __LCC__
#  define IMPNAME               "LCC"
#  define NATIVE_CODE_TAG       10    /* LCC (not really thought through!) */
/*
 * Identify operating system being used and pretend to be DOS! Ie command
 * line interface only.
 */
#  define MS_DOS                1
#  undef SOCKETS
/*
 * Identify the C compiler that I will use
 */
#  define LCC_C                 1
/* #  define IMULTIPLY             1 */
/* #  define IDIVIDE               1 */
#  define PAGE_BITS             SMALL_PAGE_BITS
#ifndef NILSEG_REGISTER
#  define NILSEG_EXTERNS        1   /* externs.h */
#endif
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define TICK_STREAM           1
#ifndef SOFTWARE_TICKS
#  define SOFTWARE_TICKS        software_ticks
#endif
#  define INITIAL_SOFTWARE_TICKS  3000
#  define SOFTWARE_TICKS_PER_SECOND 40
#  define BUFFERED_STDOUT       1
#  define NEEDS_CARRIAGE_RETURN 1
#  define POLL_FOR_ATTN         1
/* #  define HELP_SYSTEM           1 */
#endif /* end of LCC */

#ifdef MS_DOS
/*
 * OPSYS is used to set the operating system identification put in
 * the "lispsystem*" variable
 */
#  ifndef OPSYS
#  define OPSYS                 "msdos"
#  endif
#endif

/*
 * The WINDOWS NT version is intended for all 32-bit windows worlds,
 * that is Windows NT, Windows 95 and (as a temporary expedient) Win32s
 * running on top of Windows 3.x.  Eventually the support for win32s will
 * be abandoned.
 */
#ifdef WINDOWS_NT

/*
 * For very many purposes I will build  a Windows NT version of this code
 * using a (slightly separate) window management packaged called CWIN.
 * But to provide flexibility for people who do not want to use this (for
 * instance if they wish to build the code for embedded use and not give
 * it any direct access to the user) I will not force this option here, but
 * will require that in suitable cases the C compiler is invoked with the
 * symbol CWIN predefined. This can make sense since the build sequences
 * in such cases will need to compile and link in parts of the CWIN
 * package too.
 */

#ifdef CWIN
/*
 * SIMULATED_PIPES directs pipe access through code I write for myself.
 */
#  define SIMULATED_PIPES       1
#endif

#  define MS_DOS                1
#  ifdef __WATCOMC__
#  define NATIVE_CODE_TAG       2    /* Watcom, 32-bit Windows, register calling */
#  else
/*
 * MS_C is set if we are using Microsoft C, or some other C compiler that
 * like __cdecl qualifiers in a load of places.
 */
#  define MS_C                  1
#  define NATIVE_CODE_TAG       3    /* MS VC++ 5.0, Windows 95 & NT */
#  endif
/*
 * The next just provides more info about the target operating system
 */
#  define USES_WIN32            1
#ifndef NILSEG_REGISTER
#  define NILSEG_EXTERNS        1     /* externs.h */
#endif
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
/*
 * IMULTIPLY and IDIVIDE get defined if you have assembly code versions
 * of the primitive arithmetic routines that need 64-bit intermediate
 * working.
 */
#  define IMULTIPLY             1
#  define IDIVIDE               1
#  define TICK_STREAM           1
/*
 * I guard SOFTWARE_TICKS this way so that the user can force its value
 * with -DSOFTWARE_TICKS=nnnn in CFLAGS, either to change the frequency of
 * polling or to force software ticks on a version of the system that
 * usually uses operating-system provided ones. The value 3000 chosen here
 * as a default seems to lead to a tolerable frequency of polling on
 * reasonably fast machines. Slow systems might like a smaller value to
 * keep them more responsive to the user?
 */
#ifndef SOFTWARE_TICKS
#  define SOFTWARE_TICKS        software_ticks
#endif
/*
 * If I define SOFTWARE_TICKS to be software_ticks and then ALSO
 * define INITIAL_SOFTWARE_TICKS I will use a dynamic scheme that
 * tries to adjust things to have about SOFTWARE_TICKS_PER_SECOND
 * ticks per second.
 */
#  define INITIAL_SOFTWARE_TICKS  3000
#  define SOFTWARE_TICKS_PER_SECOND 40
/*
 * COMMAND_LINE_VERSION builds an NT variant that does not use the Window
 * susbsystem. It will be use a simple command-line interface.
 */
#ifdef COMMAND_LINE_VERSION
#  define IMPNAME               "DOS"
#  define OPSYS                 "dos"
#  define NO_HELP_SYSTEM        1
#else
#  define IMPNAME               "Windows"
#  define OPSYS                 "win32"
/*
 * The next flag indicate that a system can provide a windowed
 * environment with support for graphics output.  This arranges that
 * calls that print to stdout are handled specially
 */
#  define WINDOW_SYSTEM         1
/*
 * Note that for Windows I will use the Microsoft HELP mechanism rather
 * than anything built inside the Lisp.  However I build in the Help system
 * here in order to make debugging same easier.
 */
#  define HELP_SYSTEM           1
#endif /* COMMAND_LINE_VERSION */
/*
 * PIPES is set if the functions my_popen(command, dirn) and my_pclose() are
 * available.  I do not make this synomymous with UNIX since a strict ANSI
 * C library will not provide these functions.  Also I make the entries used
 * go via a system-specific hook since not all operating systems have calls
 * that are exactly like the Unix popen and pclose.
 */
#  define PIPES                 1
/*
 * In the case of Win32 I will have pipes if I am under Win32, bit
 * not Win32S - so I will have to have a run-time test to see if pipes are
 * really available.   Oh misery!
 */
#  define PIPES_SOMETIMES       1

#ifndef __WATCOMC__
/*
 * BUILDING_DLL puts a __decltype(dllexport) qualifier in a load of
 * extern declarations. This may be useful if I want CSL/CCL to be a DLL
 * for some reason. But I have not checked this with Watcom C, only
 * with Microsoft, hence I do not enable it too generally.
 */
/* #  define BUILDING_DLL          1 */
#endif


#endif

/*
 * I do not want to use Think C other than on a Mac. And in fact it is a very
 * long time since I build this version so it may well be broken by now.
 */

#ifdef THINK_C     /* Development on a Mac with System 7 and Think C 5.0 */
                   /* Yes this is now old enough it should be pensioned off */
#  define IMPNAME               "Macintosh"
#  define OPSYS                 "finder"
/*
 * Bits of the operating-system interface like to know they are on a Mac.
 */
#  define MACINTOSH             1
/*
 * See comment earlier on about default condition wrt socket support.
 */

/*
 * SIXTEEN_BIT is set if I need to use "long int" to get a 32-bit value.
 * This will hardly ever be true now days! I do not guarantee that it
 * still works! Please avoid if at all possible.
 */
#  define SIXTEEN_BIT           1   /* Check this out - harmless anyway */
#  define PAGE_BITS             SMALL_PAGE_BITS
/*
 * OUT_OF_LINE being defined makes the code SLIGHTLY smaller and SLIGHTLY
 * slower.  It only has an effect on the file "bytes1.c" where you can see
 * what it does.
 */
#  define OUT_OF_LINE           1   /* bytes1.c close to size limit for Mac? */
#  define ADDRESSES_HAVE_TOP_BIT_CLEAR  1
#  define TICK_STREAM           1
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define WINDOW_SYSTEM         1
#  undef SOCKETS
#  define HELP_SYSTEM           1
/*
 * If HOLD_BACK_MEMORY is defined it indicates a number of pages
 * to release to the operating system so that I do not utterly run out ever...
 * Most necessary if low level operating system routines in effect do
 * malloc() in a way I can not control.
 *
 * HOLD_BACK_MEMORY is asserted here and MUST BE for all machines
 * where sizeof(size_t) == 2, since in that case it will not be possible
 * to allocate memory in one big hunk.
 */
#  define HOLD_BACK_MEMORY      6

/*
 * For the Macintosh I will use NewPtr rather than malloc - the main reason
 * I do this is that once malloc has grabbed space (under Think C) free
 * never hands it back to the operating system.
 */
#include <memory.h>

#undef  nil             /* Think C headers go "#define nil 0" which hurts me */
#define malloc(n) NewPtr(n)
#define free(p)   DisposPtr((Ptr)(p))

#endif

/*
 * powerpc is another synonym for "Macintosh" in this context, and expects
 * you to be using the Symantecs C compiler.
 */

#ifdef powerc     /* Development on a  PowerPC with System 7 and Symantecs */
#  define IMPNAME               "PowerPC"
#  define OPSYS                 "finder"
/*
 * Bits of the operating-system interface like to know they are on a Mac.
 */
#  define MACINTOSH             1
/*
 * OUT_OF_LINE being defined makes the code SLIGHTLY smaller and SLIGHTLY
 * slower.  It only has an effect on the file "bytes1.c" where you can see
 * what it does.
 */
#  define OUT_OF_LINE           1   /* bytes1.c close to size limit for Mac? */
#  define ADDRESSES_HAVE_TOP_BIT_CLEAR  1
#  define TICK_STREAM           1
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define WINDOW_SYSTEM         1
#  define TICK_STREAM           1
#  define SOFTWARE_TICKS        software_ticks
#  define INITIAL_SOFTWARE_TICKS  3000
#  define SOFTWARE_TICKS_PER_SECOND 40
#  define POLL_FOR_ATTN         1
#  define NO_HELP_SYSTEM        1
#  undef SOCKETS
#  define HELP_SYSTEM           1
/*
 * If HOLD_BACK_MEMORY is defined it indicates a number of pages
 * to release to the operating system so that I do not utterly run out ever...
 * Most necessary if low level operating system routines in effect do
 * malloc() in a way I can not control.
 *
 * HOLD_BACK_MEMORY is asserted here and MUST BE for all machines
 * where sizeof(size_t) == 2, since in that case it will not be possible
 * to allocate memory in one big hunk.
 */
#  define HOLD_BACK_MEMORY      6

#undef  nil             /* Think C headers go "#define nil 0" which hurts me */

#endif

#ifdef arm                          /* Old RISCIX compiler... */
#  define __arm                 1
#endif

#ifdef __arm

#  define IMPNAME               "Archimedes"

#  undef SOCKETS

#ifdef __riscos
/* Note NOT automatically defined by release compiler: Use -D__riscos please */

/*
 * A profile option is available to help record low-level execution
 * profiles of CSL's performance.  Intended for use by those involved in
 * fine-tuning system performance.
 */
#  define SHOW_COUNTS_AVAILABLE 1   /* gc1.c */
/*
 * RISCOS is the operating system on an Acorn Archimedes
 */
#  define RISCOS                1
#  define OPSYS                 "riscos"
#  define HOLD_BACK_MEMORY      1
#  define PAGE_BITS             SMALL_PAGE_BITS
#  define OUT_OF_LINE           1      /* memory generally tight? */
#  define ADDRESSES_HAVE_TOP_BIT_CLEAR  1
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define TICK_STREAM           1
/*
 * USE_AUTOINDEX causes the code that pushes multiple values onto
 * the Lisp stack to use the addressing idiom (*++sp) and *(sp--)
 * repeatedly. Otherwise the data movement and stack adjustment are
 * written out as separate steps so that all adjustment is done in
 * a single operation. With sufficiently clever compilers this ought not
 * to matter, but at present there are plenty of compilers around that
 * are not that smart!
 */
#  define USE_AUTOINDEX         1
#ifndef SOFTWARE_TICKS
#  define SOFTWARE_TICKS        3000   /* Maybe this is more robust?? */
#endif
#  define WINDOW_SYSTEM         1
#  define HELP_SYSTEM           1
/*
 * In the case of RiscOS I will support pipes ONLY to the extent that
 * the gnuplot interface requires them.  Indeed the apparently generic
 * (popen ...) function will send messages via the window manager with
 * destination gnuplot (tested with gnuplot 3.4) only.  Beware!
 */
#  define SIMULATED_PIPES       1
#  define PIPES                 1

#else   /* __riscos : the converse is taken to be RISCIX (Unix) */

/*
 * Where Unix is available I use times() to read the clock, and report
 * user CPU time.  The value given to UNIX_TIMES indicates the clock
 * tick resolution used.  If this is not set I use clock() instead, which
 * tends to count system time as well as user time and hence make the
 * reports suggest lower performance... Do you call this cheating?
 */
#  define UNIX_TIMES            100
#  define UNIX                  1
#  define PIPES                 1

#endif  /* __riscos */
#endif  /* __arm */

/*
 * For the Alpha I have tried builds in DECs OSF/1 (where the code works
 * OK using the "-taso" linker option) and under NetBSD in true 64-bit
 * mode. This setup would not work for Windows NT (now defunct for alphas?),
 * and might not behave well for Linux-alpha. Indeed the Alpha and in general
 * 64-bit support is still in the process of stabilising!
 */

#ifdef __alpha
#  define IMPNAME               "DEC Alpha"
#  define UNIX                  1
#  define BSD_LIB               1
#  define PIPES                 1
#ifdef __NetBSD__
#  define UNIX_TIMES            100
#else
#  define UNIX_TIMES            60
#endif
/*
 * SIXTY_FOUR_BIT can be set if I have a representation of 64-bit
 * integers (efficiently) available.  This gets mapped onto the
 * typedef names int64 and unsigned64, and may be used to speed up
 * bignum arithmetic. SIXTY_FOUR_BIT defined directly indicates that
 * the data type "long int" is a 64 bit one. If "LONG_LONG_64" is set
 * (instead) then the long integer type is taken to be "long long int",
 * an option relevant for (eg) super-sparc. The flag SIXTY_FOUR_BIT on its
 * own does not change the representation of data at all: it just changes
 * the way in which bignumber code is implemented in rather minor ways.
 * However it is needed if the next option (ADDRESS_64) is to be used.
 */
#  define SIXTY_FOUR_BIT        1
/*
 * ADDRESS_64 is set to activate the mode where all items in Lisp
 * are stored as 64 rather than just 32 bits. Doing so doubles the
 * size of data structures but allows the use of truly huge amounts of
 * memory. If may be NEEDED for some future computer architectures as
 * backwards-compatibility modes whereby 64-bit machines can simulate
 * 32 bit ones are gradually withdrawn. At present the computer that
 * I am working on this using runs NetBSD hence the #ifdef. Note that
 * heap images from ADDRESS_64 systems are not compatible with ones from
 * the 32-bit universe.
 */
#ifdef __NetBSD__
#  define ADDRESS_64            1
#endif
#  ifndef _CC_NORCROFT
/*
 * MULDIV64 is set if "long" is a 64-bit type to be used in Imultiply etc
 * here (temporarily) I only use it if I am using the DEC C compiler.
 */
#     define MULDIV64           1
#  endif
#endif

/*
 * Something of a place-holder for the Intel 64-bit chip. Here I expect
 * it to be run on some form of Unix as a true 64-bit system.
 */

#ifdef __ia64
#  define IMPNAME               "ia64"
#  define UNIX                  1
#  define BSD_LIB               1
#  define PIPES                 1
#  define UNIX_TIMES            60
#  define SIXTY_FOUR_BIT        1
#  define ADDRESS_64            1
#  define MULDIV64              1
#endif

#ifndef __sgi

#ifdef __mips
#  ifndef __mips__
#     define __mips__
#  endif
#endif

#ifdef __mips__
#  define IMPNAME               "MIPS"
/*
 * To my amazement on most machines an integer GCD function based on
 * subtraction and shifting outperformed one based on division.  Where
 * really fast hardware division is available define this symbol to
 * use the more obvious code.
 */
#  define FAST_DIVISION         1   /* arith09.c (gcd) */
#  define UNIX                  1
#  define PIPES                 1
/*
 * Ultrix seems to object to fopen(xx, "rb"), and demand fopen(xx, "r")
 * This is harmless of all UNIX systems, as all I/O is binary in Unix, but
 * most other versions will at least accept "rb" and "wb", and if the C
 * library is ANSI compatible they MUST do so.
 */
#  define NO_BINARY_FOPEN       1
/* At present I can deal with two UNIX library types; BSD and NCC
 * With BSD_LIB set then use will be made of isatty(2) and some other
 * functions.  With NCC_LIB (which is rather strict) private knowledge of the
 * systems is used.  But since NCC is the Codemist C compiler and library
 * maybe we (Codemist) are entitled to exploit a bit of inside information
 * from time to time?
 */

#ifdef SGICC
#  undef __sgi
#endif

# ifdef __titan
#  define NCC_LIB               1
# else
#  ifdef __sgi
#    define NCC_LIB             1
#  else
#    define BSD_LIB             1
#    define WANT_POSIX          1
#    define UNIX_TIMES          CLK_TCK
#  endif
# endif
#endif

#endif

#ifdef __sgi
# if __mips == 3
#  define IMPNAME              "SGI MIPS III"
# elif __mips == 1
#  define IMPNAME              "SGI MIPS I"
# else
#  define IMPNAME              "SGI"
# endif
#  define WANT_POSIX           1
#  define PIPES                1
#  define UNIX_TIMES           CLK_TCK
#  define UNIX                 1
#  define BSD_LIB              1
#endif

#ifdef vax
#  ifdef vms
      /* this allows me to compile under VAX/VMS directly */
#     define __vmsvax__
#  endif
#endif

#ifdef __vax__
#  define IMPNAME               "VAX"
#  define NO_BINARY_FOPEN       1
#  define UNIX_TIMES            60
#  define UNIX                  1
#  define BSD_LIB               1
#  define PIPES                 1
#  define USE_AUTOINDEX         1
#endif

#ifdef __vmsvax__
#  define IMPNAME               "VAX/VMS"
#  define OPSYS                 "vms"
#  define VAXFLOAT              1
#  define UNIX_TIMES            60    /* OK under VMS? */
#  define HELP_SYSTEM           1
#  define USE_AUTOINDEX         1
#  undef SOCKETS
#endif

#ifdef NeXT
/*
 * This was once tested on a Pentium Pro running NeXT, and may deserve
 * adjustment for other variant targets.
 */
#  define IMPNAME               "NeXT"
#  define UNIX                  1       /* almost! */
#  define OPSYS                 "unix"  /* close enough! */
#  define UNIX_TIMES            60
#  define BSD_LIB               1
#  define USE_DIRECT_H          1       /* use <direct.h> not <dirent.h> */
#  define UTIME_TIME_T          1       /* Arg type for utime() function */
#  define NO_GETCWD             1       /* Functionality unavailable? */
#endif

#ifdef _rs6000
#  define IMPNAME               "rs/6000"
#  define UNIX                  1
/*
 * Magic to do with the need for symbols predefined before <stdio.h> etc
 * get scanned on this machine.
 */
#  define WANT_POSIX            1
#  define PIPES                 1
#  define UNIX_TIMES            100
#  define BSD_LIB               1
#endif

#ifdef SR2201
/*
 * Experimental use of the Hitachi mpp based on HP-precision derived CPUs.
 * No longer under serious consideration.
 */
#  define IMPNAME               "SR2201"
#  define UNIX                  1
#  define PIPES                 1
#  define UNIX_TIMES            100
#  define BSD_LIB               1
/*
 * USE_PVM guards extra capability for the Lisp so that it can use PVM
 * to provide a parallel Lisp environment, at least in a crude way. Well
 * these days I think that MPI is a better bet anyway, so that is another
 * respect in which this code is a historical relic!
 */
#  define USE_PVM               1
#endif

#ifdef __clipper
#  define IMPNAME               "Clipper"
#  define UNIX                  1
#  define NCC_LIB               1
#endif

#ifdef __bsdos__
#  define IMPNAME               "BSD/OS 2.1"
#  define UNIX                  1
#  define UNIX_TIMES            60
#  define PIPES                 1
#  define BSD_LIB               1
#  define IMULTIPLY             1
#  define IDIVIDE               1
#endif

#ifdef __CYGWIN32__
#  define IMPNAME               "CygWin32"
#  define OPSYS                 "cygwin32"
#  define NATIVE_CODE_TAG       9
#  define UNIX                  1   /* Well not really, but close enough! */
#  define PIPES                 1
#  define BSD_LIB               1
#endif

#ifdef __linux__
/*
 * Linux can be run on many sorts of host hardware. The entry here is for
 * Linux on x86 systems. Other cases (Alpha, Sparc etc?) could be detected
 * earlier in this file and if they define IMPNAME this set of defaults
 * will not get activated.  I think this all shows that there is a problem
 * around here. The C compiler used provides (default) predefined symbols,
 * and my configuration may need to depend in part on hardware architecture,
 * operating system AND the specific C compiler. But in some cases there are
 * strong associations between combinations of these.
 */

#ifndef IMPNAME                      /* more specific variants can go first */
#  define IMPNAME               "Linux"
/*
 * WARNING - I ought to filter the next line on Intel archirecture,
 * since otherwise it will cause trouble on other variants on Linux!
 */
#  define NATIVE_CODE_TAG       4    /* Linux, Intel, Pentium conventions */
#  define UNIX                  1
#  define PIPES                 1
#  define BSD_LIB               1
#endif
#endif

#ifdef __hp9000s300
#  define IMPNAME               "HP/9000.300"
#  define WANT_POSIX            1
/*
 * HP Unix has a few features that I need to support specially in sysunix.c
 */
#  define HP_UNIX               1
/*
 * More (HP-specific) magic that arranges that the standard headers
 * provide XOPEN support.
 */
# ifndef _INCLUDE_XOPEN_SOURCE
#  define _INCLUDE_XOPEN_SOURCE 1
# endif
#  define PIPES                 1
#  define UNIX_TIMES            CLK_TCK
#  define UNIX                  1
#  define BSD_LIB               1
#endif

#ifdef __hp9000s800
#  define IMPNAME               "HP/9000.800"
#  define WANT_POSIX            1
#  define HP_UNIX               1
#  define _INCLUDE_XOPEN_SOURCE 1
#  define PIPES                 1
#  define UNIX_TIMES            CLK_TCK
#  define UNIX                  1
#  define BSD_LIB               1
#endif

#ifdef __APOLLO__
#  define IMPNAME               "Apollo"
#  define UNIX_TIMES            60
#  define UNIX                  1
#  define BSD_LIB               1
#  define PIPES                 1
/*
 * I define OUT_OF_LINE here to reduce stress on a C compiler that has in the
 * past given some trouble.
 */
#  define OUT_OF_LINE           1
#endif

#ifdef __ibm370
/*
 * Note that I have not tested CSL on this target yet... and image files etc
 * will not be compatible from ASCII to EBCDIC machines. Furthermore you
 * may have trouble finding an instance of the IBM mainframe architecture now!
 */
#  define IMPNAME               "S/370"
#  define OPSYS                 "mvs"
#  define HELP_SYSTEM           1
#  undef SOCKETS
#endif

#ifdef __m88k__
/*
 * I had one of these (a Data General Aviion) once...
 */
#  define IMPNAME               "mc88000"
#  define UNIX_TIMES            60
#  define UNIX                  1
#  define BSD_LIB               1
#  define PIPES                 1
#endif

/* GNU C defines __GNUC__ */
/* SPARCCompiler defines __SUNPRO_C */

#if defined(__sparc) || defined(__sparc__)
#   if defined(__SUNPRO_C)
#      define IMPNAME               "SPARC-SUNPRO"
#      define NATIVE_CODE_TAG       5
#   elif defined(__GNUC__)
#      define IMPNAME               "SPARC-GCC"
/*
 * It may be that SPARC and the 2 C compilers mentioned here both use
 * identical code, so I could give them the same tag. But equally I might
 * need to refine things to cope with the difference between the baseline
 * sparc architecture and the ultra-sparc (etc) variants.
 */
#      define NATIVE_CODE_TAG       6
#   else
#      define IMPNAME               "SPARC"
#   endif
#   define UNIX                  1
#   define UNIX_TIMES            CLK_TCK
#   define BSD_LIB               1
#   define PIPES                 1

#else

/*
 * This is the older version of SPARC options.
 */


#if defined __sparc__
#  define IMPNAME               "SPARC"
#  ifdef sun              /* For Sparcstation with sub-standard C library */
                          /* You may need to adjust this for your sun     */
typedef char *VoidStar;
#endif
#  include <sys/param.h>
#  define UNIX_TIMES            HZ
#  define UNIX                  1
#  define BSD_LIB               1
#  define PIPES                 1
#endif

#ifdef __sparc
#  define IMPNAME               "SPARC"
#  define UNIX                  1
#  define NO_BINARY_FOPEN       1   /* probably not needed */
#  ifndef BSD_LIB
#     define NCC_LIB            1
#  endif
#  define PIPES                 1
#endif

#endif

#ifdef __kcm                    /* The ICL "Knowledge Crunching Machine */
#  define IMPNAME               "KCM"
#  define OPSYS                 "kcm"
#  define HELP_SYSTEM           1
#  undef SOCKETS
#endif

#ifdef __BORLANDC__
/*
 * An experimental build for 32-bit console mode using Borland C 4.0. Not
 * really needed any more but kept here as a historical relic.
 */
#  define IMPNAME               "Borland 4.0"
#  define NATIVE_CODE_TAG       7
#  define MS_DOS                1
#  define OPSYS                 "msdos"
#  define PAGE_BITS             SMALL_PAGE_BITS
#ifndef NILSEG_REGISTER
#  define NILSEG_EXTERNS        1   /* externs.h */
#endif
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define TICK_STREAM           1
#  define SOFTWARE_TICKS        software_ticks
#  define INITIAL_SOFTWARE_TICKS  3000
#  define SOFTWARE_TICKS_PER_SECOND 40
#  define POLL_FOR_ATTN         1
#  define NO_HELP_SYSTEM        1
#  undef SOCKETS                    /* It may be that Borland have these */
#endif


#ifdef OLD_OPTIONS_NO_LONGER_SUPPORTED

#  undef SOCKETS

/*
 * I once supported MSDOS using Zortech C release 3.0
 * This could be used in two modes - one for 80286 systems, and one for
 * 386 and 486.  When using this option ensure that you have collected
 * all available patches and updates from Zortech...  DOS16RM is set by
 * Zortech C when in 16-bit extended mode.
 * Note that the compiler referred to here as "Zortech" is now shipped
 * by Symantec, and their current offering is not the one I use when
 * building and testing my code. I have no reason to suppose that the
 * Symantec C will give problems here, but it is very probable that some
 * small changes to the makefile and code will be called for if you use it.
 */

#ifdef DOS16RM                      /* Intel 80286 family (16 bit mode)     */
                                    /* For use with Zortech Mode Z extender */
#  define IMPNAME               "MSDOS/286"
#  define MS_DOS                1
#  define ZORTECH_C             1
#  define BUFFERED_STDOUT       1
#  define NEEDS_CARRIAGE_RETURN 1
#  define SIXTEEN_BIT           1
#  define PAGE_BITS             16
#ifndef NILSEG_REGISTER
#  define NILSEG_EXTERNS        1   /* externs.h */
#endif
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define OUT_OF_LINE           1
#  define TICK_STREAM           1
#  define POLL_FOR_ATTN         1
#ifndef SOFTWARE_TICKS
#  define SOFTWARE_TICKS        software_ticks
#endif
#  define INITIAL_SOFTWARE_TICKS  3000
#  define SOFTWARE_TICKS_PER_SECOND 40
#  define HOLD_BACK_MEMORY      1
#  define HELP_SYSTEM           1
#endif

/*
 * DOS386 is predefined by Zortech in flat 32-bit mode.  I use the
 * Flashtek X-32VM DOS extender so that virtual memory is available
 * to me, but you could rebuild without that and the code would still
 * work.
 */
#ifdef DOS386                       /* Zortech 32-bit mode 386 */
#  define IMPNAME               "MSDOS/386"
#  define MS_DOS                1
#  define ZORTECH_C             1
#  define IMULTIPLY             1
#  define IDIVIDE               1
#  define PAGE_BITS             SMALL_PAGE_BITS
/*
 * Selecting the NILSEG_EXTERNS option gives a (roughly 4%) speed-up
 * for the 386.  Really it is a toss-up whether to use it or not.
 */
#ifndef NILSEG_REGISTER
#  define NILSEG_EXTERNS        1   /* externs.h */
#endif
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define TICK_STREAM           1
#  define BUFFERED_STDOUT       1
#  define NEEDS_CARRIAGE_RETURN 1
/*
 * define OLD_ZORTECH_DOS_EXTENDER if you need to use software ticks.
 */
#ifdef OLD_ZORTECH_DOS_EXTENDER
/*
 * If fully asynchronous clock interrupts are too hard or too dangerous
 * (and in Zortech 'X' mode they are in January 1992 - pending a bug-fix
 * release of the DOS extender) I can provide second best with sem-
 * regular polling done totally from within the CSL software.  There will
 * be both performance loss and a loss of responsiveness - the value that
 * the macro SOFTWARE_TICKS is given will allow some control over
 * this trade-off, with small values giving better response but lower
 * overall speed.  The latest Zortech extender I have tried is 3.0r4, which
 * needs SOFTWARE_TICKS, but if I use the Flashtek extender I seem to be
 * OK. See comments above whereby in recent versions of CSL I can make
 * the count here dynamic to tune the rate of clicks a to deliver a
 * measure of the number of ticks per second rather than the ration of
 * elemental operatiomns within CSL to these clicks.
 */
#ifndef SOFTWARE_TICKS
#  define SOFTWARE_TICKS        3000
#endif
#endif
#  define POLL_FOR_ATTN         1
#  define HELP_SYSTEM           1
#endif

#ifdef GCC386                       /* GNU C for DOS */
#  define IMPNAME               "GCC/386"
#  define NATIVE_CODE_TAG       8
#  define MS_DOS                1
#  define PAGE_BITS             SMALL_PAGE_BITS
/*
 * Selecting the NILSEG_EXTERNS option gives a (roughly 4%) speed-up
 * for the 386.  Really it is a toss-up whether to use it or not.
 */
#ifndef NILSEG_REGISTER
#  define NILSEG_EXTERNS        1   /* externs.h */
#endif
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define TICK_STREAM           1
#  define BUFFERED_STDOUT       1
#  define NEEDS_CARRIAGE_RETURN 1
#ifndef SOFTWARE_TICKS
#  define SOFTWARE_TICKS        software_ticks
#endif
#  define INITIAL_SOFTWARE_TICKS  3000
#  define SOFTWARE_TICKS_PER_SECOND 40
#  define POLL_FOR_ATTN         1
#  define HELP_SYSTEM           1
#  define IMULTIPLY             1
#  define IDIVIDE               1
#  define HUGE_VAL              1.7976931348623167e+308 /* deficient headers */
#endif

#ifdef ATARI                       /* Lattice C for all STs */
#  define IMPNAME               "ATARI"
#  define OPSYS                 "atari"
/*
 * Identify the C compiler I will use; well I actually use Lattice and Norcroft
 */
#  define LATTICE_C             1
#  define SIXTEEN_BIT           1   /* Certainly not needed with NCC. Lattice? */
#  define HOLD_BACK_MEMORY      1
#  define PAGE_BITS             SMALL_PAGE_BITS
#ifndef NILSEG_REGISTER
#  define NILSEG_EXTERNS        1   /* externs.h */
#endif
#  define MAX_HEAPSIZE          (2048*MEGABYTE)
#  define MAX_BPSSIZE           (64*MEGABYTE)
#  define TICK_STREAM           1
#  define NO_COPYING_GC         1
#  define POLL_FOR_ATTN         1
#  define HELP_SYSTEM           1
/*
 * If I know that addresses returned by malloc() will always have their top
 * bit either set or clear I assert ADDRESSES_HAVE_TOP_BIT_SET or _CLEAR.
 * Otherwise CSL will discover for itself at run time.  I can set _UNKNOWN
 * to stress that dynamic discovery is needed.
 */
#  define ADDRESSES_HAVE_TOP_BIT_CLEAR  1
#define sqrt(x) atari_sqrt(x)
#define exp(x) atari_exp(x)
#define sin(x) atari_sin(x)
#define cos(x) atari_cos(x)
#define tan(x) atari_tan(x)
#define atan(x) atari_atan(x)
#define asin(x) atari_asin(x)
#define acos(x) atari_acos(x)
#define sinh(x) atari_sinh(x)
#define cosh(x) atari_cosh(x)
#define tanh(x) atari_tanh(x)
#define log(x) atari_log(x)
#define pow(x,y) atari_pow(x,y)
#define frexp(x,y) atari_frexp(x,y)
#define ldexp(x,y) atari_ldexp(x,y)
extern double atari_sqrt(double);
extern double atari_exp(double);
extern double atari_sin(double);
extern double atari_cos(double);
extern double atari_tan(double);
extern double atari_atan(double);
extern double atari_asin(double);
extern double atari_acos(double);
extern double atari_sinh(double);
extern double atari_cosh(double);
extern double atari_tanh(double);
extern double atari_log(double);
extern double atari_pow(double,double);
extern double atari_frexp(double, int*);
extern double atari_ldexp(double,int);
#endif

#else
/*
 * But having withdrawn support I will arrange that if anybody tries to use
 * the old code they get a diagnostic. There remains a reasonable chance that
 * by altering this file and making a modest number of system-specific
 * patches elsewhere (notably in sysxxx.c and its associates) the system
 * could be revived. And if there is substantial demand I may try that
 * myself, provided I can gain access to a suitable computer.
 */
#ifdef DOS16RM                      /* Intel 80286 family (16 bit mode)     */
#error This compiler/computer is not lonnger supported by CSL
#endif
#ifdef DOS386                       /* Zortech 32-bit mode 386 */
#error This compiler/computer is not lonnger supported by CSL
#endif
#ifdef GCC386                       /* GNU C for DOS */
#error This compiler/computer is not lonnger supported by CSL
#endif
#ifdef ATARI                       /* Lattice C for all STs */
#error This compiler/computer is not lonnger supported by CSL
#endif
#endif /* OLD_OPTIONS_NO_LONGER_SUPPORTED */

/*
 * Now to make things easier for experimentation I will set some defaults
 * for the name of the implementation and the style of operating system
 * in use.
 */

#ifndef IMPNAME
#  define IMPNAME               "Generic"
#endif
#ifndef OPSYS
#  define UNIX                  1
#endif

#ifdef UNIX
#  ifndef OPSYS
#     define OPSYS              "unix"
#  endif
#  ifndef HELP_SYSTEM
#     define HELP_SYSTEM        1
#  endif
#  ifndef ADDRESS_SIGN_UNKNOWN
#     ifndef ADDRESSES_HAVE_TOP_BIT_SET
#        define ADDRESSES_HAVE_TOP_BIT_CLEAR  1
#     endif
#  endif
#endif



/*----------------------------------------------------------------------*/

#ifdef WANT_POSIX
#  ifndef _POSIX_SOURCE
#     define _POSIX_SOURCE         1
#     define _INCLUDE_POSIX_SOURCE 1
#  endif
#endif

#ifndef WINDOW_SYSTEM
#ifdef CWIN
#define WINDOW_SYSTEM 1
#endif
#ifdef WXWIN
#define WINDOW_SYSTEM 1
#endif
#endif

#ifdef WINDOW_SYSTEM
#  ifndef BUFFERED_STDOUT
#     define BUFFERED_STDOUT       1
#  endif
#endif

#ifndef NATIVE_CODE_TAG
#  define NATIVE_CODE_TAG          0  /* Native code not available */
#endif

#ifndef _cplusplus
/*
 * If I am compiling with a C++ compiler then setjmp is a BAD thing to
 * use, but there are "better" exception handling facilities. If you are
 * going to link the code here with any C++ class libraries (say that
 * look after graphical user interfaces) it might make sense to compile
 * everything in C++ mode just to be on the safe side. With some C++
 * compilers the conflict between setjmp and try/catch seems to be
 * pretty extreme. In some cases it may even extend to the whole
 * application failing to link.
 */
#include <setjmp.h>
#endif

#include <time.h>       /* so I can declare base_time etc as clock_t */

#ifdef MS_C
/*
 * If I use something other than __cdecl as the default calling convention
 * with Microsoft C I need to stick in a qualifier for some of my functions
 * where the standard calling model is needed.  Eg signal handler fns. For
 * compilers other than the Microsoft one I do not need qualifiers at all.
 */
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif

/*
 * When building for use with Windows (Win32 or Win32s) I will make most
 * entrypoints available if the whole package is linked as a DLL. At least
 * I do that if building with Microsoft C - with Watcom I need to do more
 * work first to understand how to make that option work.
 */

#ifdef BUILDING_DLL
#define DLLexport __declspec(dllexport)
#else
#define DLLexport
#endif

/*
 * Several C compilers that I have come across follow an ANSI draft that
 * called the clock quantum CLK_TCK, while in the final standard it
 * is CLOCKS_PER_SEC.  Attempt to patch things up.  If even CLK_TCK is not
 * defined I would rather you gave me a value using -DCLOCKS_PER_SEC, or
 * maybe in a machine-specific #ifdef... but I still try at least SOMETHING.
 *
 * In similar style, some sets of supposedly standard header files fail to
 * define EXIT_SUCCESS, EXIT_FAILURE or SEEK_SET.  I attempt to patch things
 * up here, but really it would be better to get the host C compiler mended.
 */

#ifndef CLK_TCK
#  define CLK_TCK 60    /* Utterly spurious value - I know no better */
#endif

#ifndef CLOCKS_PER_SEC
#  define CLOCKS_PER_SEC (CLK_TCK)
#endif

#ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS          0
#endif

#ifndef EXIT_FAILURE
#  define EXIT_FAILURE          1
#endif

#  ifndef SEEK_SET
#     define SEEK_SET           0
#  endif

#  ifndef SEEK_END
#     define SEEK_END           2
#  endif

#ifdef NO_HELP_SYSTEM
/* Even if default for this architecture, remove HELP support */
#  undef HELP_SYSTEM
#endif

#ifdef INITIAL_SOFTWARE_TICKS
#  ifndef SOFTWARE_TICKS_PER_SECOND
#    define SOFTWARE_TICKS_PER_SECOND 40
#  endif
#endif

#ifdef SOFTWARE_TICKS_PER_SECOND
#  ifndef INITIAL_SOFTWARE_TICKS
#    define INITIAL_SOFTWARE_TICKS  3000
#  endif
#endif

#ifdef CWIN
#  include "cwin.h"
#endif

#endif /* header_machine_h */

/* end machine.h */

