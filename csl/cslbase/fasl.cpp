//#define DEBUG_FASL 1
//  fasl.cpp                               Copyright (C) 1990-2016 Codemist

//
// Binary file support for faster loading of precompiled code etc.
//

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$


#include "headers.h"

#ifdef WIN32
#include <windows.h>
#else
#ifndef EMBEDDED
#include <dlfcn.h>
#endif
#endif

#ifdef SOCKETS
#include "sockhdr.h"
#endif

// I need to explain the operations that happen on FASL files as regards
// preservation of source code. I am taking the 2016 re-work of code to
// try to rationalise and simplify behaviour.
//
// The starting point for the complication is that the compiler
// arranges that if the variable !*savedef is set when it compiles
// something then the original source is saved under a '!*savedef
// tag on the property list of the name of the function concerned. For
// simple in-store compilation this happens immediately. For compilation
// into a FASL file the definition is written into the file, but whether
// it is instated onto the property list depends on the circumstances
// associated with loading the module.
//
// The when load!-module is used to load the code this extra information
// is ignored.
//
// There is however a scheme that can load !*savedef properties without
// processing and of the other parts of the FASL file. This is the function
// load!-source.
// Neither random executable things nor compiled code get loaded by this. A
// particular thing to note is that if the compiled module was such that
// normal loading of it with load!-module led to subsidiary modules being
// loaded then this will not happen with load!-source. Thus to load all
// the modules making up a package involves finding out some other way what
// they are. I am expecting it will be rather more common to want to load
// all the source for everything that is available, and that can be
// achieved using
//   for each lib in input!-libraries do
//      for each mod in library!-members lib do load!-source mod;
// (or just use library!-members() without an argument to scan the first or
// only available library). But using load!-source without an argument
// achieves essentially just this. Well actually there are extra complications
// which mean that MOST people should use load!-source withgout an argument!
// In general it will be possible to have a number of read-only image files
// present together with at most one read-write one. The (Lisp) variable
// input!-libraries contains a list of rather abstract objects giving
// each library in the order that they will be searched when looking for
// a module to load. The variable output!-library is either nil (if no
// writable library is present) or is one of the libraries in the
// input!-libraries list. When load!-module (or load!-source or of course
// load!-selected!-source) loads a module it always does so from the first
// library that contains a module with the given name. Thus an image file
// that is earlier in the search order can make one that comes later. There
// is (at present????) no provision for loading modules from later in the
// search order.
// library!-members lists the modules present in a specified library. So
// if this is done for several libraries some module names may end up listed
// several times, but every time the module name is used only the first
// instance of that module will be accessed. For load!-source it will not
// matter if a module is scanned several times since the same !*savedef
// information will be instated and because I can be careful and only add
// mention of any given module once to the source record.
//
// The simple case "load!-source mod" loads all !*savedef information in the
// given module. Clearly if it is called repeatedly and several modules are
// scanned the !*savedef information present at the end will be the last
// version loaded. In addition to setting up !*savedef properties the
// load!-source function also records, for each function, which module
// it was found in. This ends up as as load!-source property for the name
// of the function, and will be a list of the names of modules in which
// a definition was found. This scheme is intended to be useful for cross-
// referencing style code that tracks down where in the source some function
// is defined. It is also there so that it is possible to identify cases
// where the same name is used for functions present in several modules. This
// shows up when (at the end of a sequence of uses of load!-source) some names
// have load!-source properties with multiple entries.
// The return value of load!-source is a list of the functions whose source
// has just been loaded.
//
// A second function "load!-selected!-source mod" is available for selective
// loading of !*savedef information.
// In this case !*savedef information is read from the module, but only
// saved for the user if a checksum computed on it matches an integer value
// present as a load!-selected!-source property of its name of if the
// load!-selected!-source property is something else non-nil (typically t).
// The checksum is calculated using md5 but then truncated to 60 bits so
// there is some (small) possibility of an unwanted definition ending up
// loaded. The load!-source propery-list entry will be set up for all
// functions, not just for the ones where checksums match and so not only
// can this be used to detect any cases of hash collisions, but it provides
// a way to collect just this source module information.
//
// load!-source and load!-selected!-source scan all available modules if
// they are called without an argument, and this will often be the most
// convenient way to use them.
//
// Note that the above is a change from previous behaviour which inspected
// variables !*savedef and load!-source at load-time to decide what to do.
// I hope it is cleaner and simpler, and by virtue of this block of comments
// it is certainly better documented!
//
// Uses with the build of Reduce:
//   The bootstrap build of Reduce has !*savedef set while it compiles the
//   code. This puts saved definitions in the FASL files and they will be
//   present at build time, but they do not get loaded by load!_module.
//
//   The "make profile" option in the Makefile measures which functions are
//   most heavily used. The measurements it records include an ordered
//   list of functions and then a checksum of the associated !*savedef
//   information using the same scheme that load!-selected will. This is
//   done so that if two modules each define a function called (say) foo
//   and profile information about each of these gets generated it will be
//   possible to distinguish between them.
//
//   The procedure that compiled from Reduce (ie Lisp) into C++ picks up
//   checksum information from the profile records and uses
//   load!-selected!-source to recover just the matching Lisp source.
//   It converts that into C++ and inserts the checksum into tables as part
//   of that C++ code. When the (final) version of Reduce is compiling
//   itself and it finds a defininition of some function (again suppose
//   it is called foo), it checks if it has a compiled-in C++ function
//   with the same name and the same checksum, and if so it ignores the
//   new definition. This leaves the C++ version to be used. If a newer
//   version of the Reduce sources provide an updated or changed definition
//   then with very high probability the new checksum will not match the
//   one associated with the C++ code, and this will lead to the newer
//   definition being compiled into bytecodes for use. So source changes
//   in Reduce may over time degrade the number of functions where faster
//   C++ versions of functions are used.
//
//   Code used via scripts/clash.sh uses load!-selected!-source
//   with no checksum on property lists. This just loads the information
//   about which modules functions are defined in. It is then possible
//   to identify and report cases where there are multiple versions of
//   functions with the same name present somewher in Reduce.
//   Given that Reduce can not check for this at build time an analysis
//   tool like this can help detect potential problem clashes or opportunities
//   to bring functions to a common place where they are available to all
//   packages that might benefit from them.
//
//   Planned future code for global type-checking of Reduce will use
//   load!-source to gain access to all the source code in a spirit of
//   what other programming systems call "reflection" but that Lisp has
//   pretty much been able to take for granted since the 1960s. In a similar
//   style future cross-referencing code might plausibly work based on
//   !*savedef information rather than by scanning source files. In general
//   tools for code analysis and improvement may find use for all of this. 
//
//   If a debugging tool wanted to recover the source version of just a single
//   function it could set the load!-selected!-source property of the function
//   name to T and call load!-selected!-source - thus recovering the !*savedef
//   information for just that name without needing a checksum in advance.
//
// So here is a go at a summary:
//   load!-module     Loads code and loads any savedef entries present.
//   load!-source     Loads all savedefs and sets function location info.
//   load!-selected!-source
//                    As load!-source but ONLY loads the savedef of a
//                    function if the load!-selected!-source property of
//                    the name of the function is either true or it
//                    is an integer matching a checksum of the saved
//                    definition. Even this load!-selected!-source only
//                    recovers selected !*savedef information it loads
//                    function location information for everything.



bool fasl_output_file = false;  // An output file is open?
static int32_t recent_pointer = 0, hits = 0 , misses = 0, fasl_byte_count = 0;

//
// FASL files are binary, and are treated as containing sequences of
// unsigned bytes, where the bytes are names as in the following set
// of definitions, which MUST be kept in step with the code that
// creates FASL files.  I expect FASL files to be portable between
// computers that use the same character set, but names of symbols
// will get totally scrambled between ASCII and EBCDIC hosts.
//

#define F_END       0  // end of FASL file
#define F_NIL       1  // the symbol NIL
#define F_TRU       2  // the symbol T
#define F_EXT       3  // used to get operands > 8 bits into other codes
#define F_INT       4  // positive fixnum
#define F_NEG       5  // negative fixnum
#define F_BIG       6  // bignum
#define F_RAT       7  // ratio
#define F_CPX       8  // complex number
#define F_FPS       9  // short float
#define F_FPF       10 // single float
#define F_FPD       11 // double float
#define F_FPL       12 // long float
#define F_SYM       13 // symbol, general length
#define F_ID1       14 // symbol with 1-character name
#define F_ID2       15 // symbol with 2-character name
#define F_ID3       16 // etc
#define F_ID4       17
#define F_ID5       18
#define F_ID6       19
#define F_ID7       20
#define F_ID8       21
#define F_ID9       22
#define F_IDA       23
#define F_IDB       24
#define F_IDC       25
#define F_IDD       26
#define F_IDE       27
#define F_IDF       28 // symbol with 15 character name
#define F_STR       29 // string
#define F_BP0       30 // bytecode string for binary code (0 - 255 bytes)
#define F_BP1       31 // 256 - 511 bytes of BPS
#define F_BP2       32 // 512 - 767 bytes of BPS
#define F_BP3       33 // 768 - 1023 bytes of BPS
// Having a single function lead to over 1023 bytes of bytecode seems
// horrible at present.
#define F_HASH      34 // hash table
#define F_VEC       35 // simple Lisp vector
#define F_LST       36 // list, general length
#define F_LS1       37 // list of length 1
#define F_LS2       38 // list of length 2
#define F_LS3       39 // list of length 3
#define F_LS4       40 // list of length 4
#define F_DOT       41 // list ending with dotted item
#define F_QUT       42 // (QUOTE xx)
#define F_DEF0      43 // function definition, 0 args
#define F_DEF1      44 // function definition, 1 arg
#define F_DEF2      45 // function definition, 2 args
#define F_DEF3      46 // function definition, 3 args
#define F_DEFN      47 // function definition, 4 or more args
//
// F_REP is now retired, but I will leave it present (albeit acting as a
// no-op) for a transitional period.
//
#define F_REP       48 // Used to be followed by 2 bytes giving FP rep
#define F_CHAR      49 // bits, font, code
//#define F_SDEF    50 // associated with fn definition - Lisp coded version
#define F_STRUCT    51 // Structure or e-vector
#define F_DEFOPT    52 // function definition, &optional args
#define F_DEFHOPT   53 // function definition, &optional args + initform
#define F_DEFREST   54 // function definition, &optional/&rest args
#define F_DEFHREST  55 // function definition, &optional/&rest + initform
#define F_ARRAY     56 // Common Lisp style general array
#define F_BITVEC    57 // Bit-vector
#ifdef COMMON
#define F_PKGINT    58 // abc::def (coded as m, n, c1..cm, c1..cn)
// m=0 can be used for gensyms, as in #:xxx
#else
#define F_GENSYM    58 // coded as n, c1..cn. Eg just like PKGINT,0
#endif
#define F_PKGEXT    59 // abc:def (m=0 => keyword)

#define F_OLD       60 // all remaining codes denote recently seen symbols
#define KEEP_RECENT (256 - F_OLD)

#define MAX_OBJECT 256  // limit on symbol & number length

#ifdef DEBUG_FASL

static const char *fasl_code_names[] =
{   "END",      "NIL",      "TRU",      "EXT",
    "INT",      "NEG",      "BIG",      "RAT",
    "CPX",      "FPS",      "FPF",      "FPD",
    "FPL",      "SYM",      "ID1",      "ID2",
    "ID3",      "ID4",      "ID5",      "ID6",
    "ID7",      "ID8",      "ID9",      "IDA",
    "IDB",      "IDC",      "IDD",      "IDE",
    "IDF",      "STR",      "BP0",      "BP1",
    "BP2",      "BP3",      "HASH",     "VEC",
    "LST",      "LS1",      "LS2",      "LS3",
    "LS4",      "DOT",      "QUT",      "DEF0",
    "DEF1",     "DEF2",     "DEF3",     "DEFN",
    "oldREP",   "CHAR",     "SDEF",     "STRUCT",
    "DEFOPT",   "DEFHOPT",  "DEFREST",  "DEFHREST",
#ifdef COMMON
    "ARRAY",    "BITVEC",   "PKGINT",   "PKGEXT"
#else
    "ARRAY",    "BITVEC",   "GENSYM",   "PKGEXT"
#endif
};

static char old_name[8];

static const char *fasl_code(int n)
{   if (n >= F_OLD)
    {   sprintf(old_name, "OLD%d", n - F_OLD);
        return old_name;
    }
    else return fasl_code_names[n];
}

#endif


#define boffo_char(i) celt(boffo, i)

static LispObject fastread(void);

#ifdef COMMON
static char package_name[256];
#endif

#ifdef DEBUG_FASL

static int IgetcDebug()
{   int k = Igetc();
    trace_printf("Igetc = %d/%.2x/%s\n", k, k, fasl_code(k));
    return k;
}

#define Igetc() IgetcDebug()

static int IreadDebug(void *x, int n)
{   int i;
    int k = Iread(x, n);
    trace_printf("Iread(%d) = %d:", n, k);
    for (i=0; i<k; i++)
    {   const unsigned char *xc = (const unsigned char *)x;
        trace_printf(" %d/%x", xc[i], xc[i]);
        if (32 <= xc[i] && xc[i] < 0x7f) trace_printf("/'%c'", xc[i]);
    }
    trace_printf("\n");
    return k;
}

#define Iread(a, n) IreadDebug(a, n)

#endif

static LispObject fastread1(int32_t ch, int32_t operand)
{   LispObject nil = C_nil;
    LispObject r = nil, w;
#ifdef COMMON
    int operand0;
#endif
    int32_t p;
    switch (ch)
{       default:                        // a recently-mentioned item
            if (ch < F_OLD)
            {   err_printf("\nError at byte %ld : %#.2x/%d\n",
                           (long)fasl_byte_count, ch & 0xff, ch & 0xff);
                return aerror("bad byte in FASL file");
            }
            if (operand != 0)
            {   operand = ((operand-1) << 7) + (ch - F_OLD);
                r = faslgensyms;
                while (operand != 0)
                {   r = qcdr(r);
                    operand--;
                }
                return qcar(r);
            }
            operand = recent_pointer - (ch - F_OLD);
            if (operand < 0) operand += KEEP_RECENT;
            r = elt(faslvec, operand);
            return r;

#ifdef COMMON
        case F_PKGINT:
        case F_PKGEXT:
        {   int ch1 = Igetc();
            fasl_byte_count++;
            if (ch1 == EOF) return aerror("premature EOF in FASL file");
            operand0 = ch1 & 0xff;
            ch1 = Igetc();
            if (ch1 == EOF) return aerror("premature EOF in FASL file");
            operand = (operand << 8) + ((int32_t)ch1 & 0xff);
            if (operand0 != 0)
            {   if (Iread(package_name, operand0) != operand0)
                    return aerror("FASL file corrupted");
                fasl_byte_count += operand0;
                r = find_package(package_name, operand0);
                if (r == nil)
                {   err_printf(
                        "+++ Package %s not found, using current package\n",
                        package_name);
                    r = CP;
                }
            }
            else r = qvalue(keyword_package);
            if (Iread(&boffo_char(0), operand) != operand)
                return aerror("FASL file corrupted");
            fasl_byte_count += operand;
            if (ch == F_PKGINT)
            {   if (operand0 == 0)
                {   r = iintern(boffo, (int32_t)operand, CP, 0);
                    errexit();
                    r = Lgensym2(nil, r);
                }
                else r = iintern(boffo, (int32_t)operand, r, 0);
            }
            else if (r == qvalue(keyword_package))
                r = iintern(boffo, (int32_t)operand, r, 0);
            else
            {   push(r);
                w = iintern(boffo, (int32_t)operand, r, 4);
                pop(r);
                errexit();
                if (mv_2 == nil)
                {   err_printf("+++ Symbol %.*s not external in %s\n",
                               (int)operand, &celt(boffo, 0), package_name);
                    err_printf("+++ Treating as an internal symbol...\n");
                    w = iintern(boffo, (int32_t)operand, r, 0);
                }
                r = w;
            }
            errexit();
//
// The KEEP_RECENT most recently used symbols are stored in a cyclic buffer
// so that if re-used they will be rapidly available. See comment under
// F_GENSYM for a delicacy here.
//
            {   recent_pointer++;
                if (recent_pointer == KEEP_RECENT) recent_pointer = 0;
                w = elt(faslvec, recent_pointer);
                if (qpackage(w) == nil) // eg a gensym
                {   push(r);
#ifdef DEBUG_FASL
                    trace_printf("recording gensym ");
                    prin_to_trace(w);
                    trace_printf("\n");
#endif
                    w = cons(w, faslgensyms);
                    pop(r);
                    errexit();
                    faslgensyms = w;
                }
                elt(faslvec, recent_pointer) = r;
#ifdef DEBUG_FASL
                trace_printf("recording ");
                prin_to_trace(r);
                trace_printf("\n");
#endif
            }
            return r;
        }
#else // COMMON
        case F_GENSYM:
        {   int ch1 = Igetc();
            if (ch1 == EOF) return aerror("premature EOF in FASL file");
            operand = (operand << 8) + ((int32_t)ch1 & 0xff);
            if (Iread(&boffo_char(0), operand) != operand)
                return aerror("FASL file corrupted");
            fasl_byte_count += operand;
            r = iintern(boffo, (int32_t)operand, CP, 0);
            errexit();
            r = Lgensym2(nil, r);
            errexit();
//
// The KEEP_RECENT most recently used symbols are stored in a cyclic buffer
// so that if re-used they will be rapidly available.
//
            recent_pointer++;
            if (recent_pointer == KEEP_RECENT) recent_pointer = 0;
            w = elt(faslvec, recent_pointer);
            if (qheader(w) & SYM_ANY_GENSYM)
            {   push(r);
#ifdef DEBUG_FASL
                trace_printf("recording gensym ");
                prin_to_trace(w);
                trace_printf("\n");
#endif
                w = cons(w, faslgensyms);
                pop(r);
                errexit();
                faslgensyms = w;
            }
            elt(faslvec, recent_pointer) = r;
#ifdef DEBUG_FASL
            trace_printf("recording ");
            prin_to_trace(r);
            trace_printf("\n");
#endif
            return r;
        }
#endif // COMMON
        // these all have a 1-byte arg to follow
        case F_INT:
        case F_NEG:
        case F_BIG:
        case F_SYM:
        case F_STR:
        case F_BP0:
        case F_BP1:
        case F_BP2:
        case F_BP3:
        case F_HASH:
        case F_VEC:
        case F_STRUCT:
        case F_LST:
        case F_DOT:
        {   int ch1 = Igetc();
            fasl_byte_count++;
            if (ch1 == EOF) return aerror("premature EOF in FASL file");
            operand = (operand << 8) + ((int32_t)ch1 & 0xff);
        }
        switch (ch)
    {       default:                    // can never occur

            case F_INT:                 // positive fixnum
                return fixnum_of_int(operand);

            case F_NEG:                 // negative fixnum
                return fixnum_of_int(-operand);

            case F_BIG:
                r = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+operand);
                // I tidy up the padding word if needbe
                if ((((operand & 4) != 0) && SIXTY_FOUR_BIT) ||
                    (((operand & 4) == 0) && !SIXTY_FOUR_BIT))
                    *(int32_t *)((char *)r + CELL + 4 - TAG_NUMBERS + operand) = 0;
//
// I accumulate the numeric components of the bignum here by steam - one
// byte at a time - so that fasl files made on a machine with one byte-order
// can be used on machines with the other.  I do not expect that there
// will be many bignums in fasl files, and thus this is not a performance
// critical area.
//
                {   int32_t i;
                    for (i = 0; i<operand; i+=4)
                    {   uint32_t v = (int32_t)Igetc() & 0xff;
                        v = (v << 8) | ((int32_t)Igetc() & 0xff);
                        v = (v << 8) | ((int32_t)Igetc() & 0xff);
                        v = (v << 8) | ((int32_t)Igetc() & 0xff);
                        *(uint32_t *)((char *)r + CELL - TAG_NUMBERS + i) = v;
                        fasl_byte_count += 4;
                    }
                }
                return r;

            case F_SYM:                 // n characters making a symbol
// Is there a risk of buffer overflow here...???
                if (Iread(&boffo_char(0), operand) != operand)
                    return aerror("FASL file corrupted");
                fasl_byte_count += operand;
                r = iintern(boffo, operand, CP, 0);
                errexit();
//
// The KEEP_RECENT most recently used symbols are stored in a cyclic buffer
// so that if re-used they will be rapidly available.
//
                {   recent_pointer++;
                    if (recent_pointer == KEEP_RECENT) recent_pointer = 0;
                    w = elt(faslvec, recent_pointer);
#ifdef COMMON
                    if (qpackage(w) == nil)
#else
                    if (qheader(w) & SYM_ANY_GENSYM)
#endif
                    {   push(r);
#ifdef DEBUG_FASL
                        trace_printf("recording gensym ");
                        prin_to_trace(w);
                        trace_printf("\n");
#endif
                        w = cons(w, faslgensyms);
                        pop(r);
                        errexit();
                        faslgensyms = w;
                    }
                    elt(faslvec, recent_pointer) = r;
#ifdef DEBUG_FASL
                    trace_printf("recording ");
                    prin_to_trace(r);
                    trace_printf("\n");
#endif
                }
                return r;

            case F_STR:                 // n characters making a string
// Here I pass the natural length of the string a the final argument to
// getvector, and the packing between length and type code happens once
// within getvector.
                r = getvector(TAG_VECTOR, TYPE_STRING_4, CELL+operand);
                errexit();
                {   char *s = (char *)r - TAG_VECTOR + CELL;
                    int l = doubleword_align_up(operand+CELL);
                    if (l >= 16) *(int32_t *)(s - CELL + l - 8) = 0;
                    if (!SIXTY_FOUR_BIT || l >= 16)
                        *(int32_t *)(s - CELL + l - 4) = 0;
                    if (Iread(s, operand) != operand)
                        return aerror("FASL file corrupted");
                    fasl_byte_count += operand;
                }
                validate_string(r);
                return r;

            case F_BP3:                 // n + 768 bytes of BPS
                operand += 256;
            // drop through
            case F_BP2:                 // n + 512 bytes of BPS
                operand += 256;
            // drop through
            case F_BP1:                 // n + 256 bytes of BPS
                operand += 256;
            // drop through
            case F_BP0:                 // n bytes making BPS
                {   r = getvector(TAG_VECTOR, TYPE_BPS_4, operand+CELL);
                    errexit();
                    if (Iread(data_of_bps(r), operand) != operand)
                        return aerror("FASL file corrupted");
                    fasl_byte_count += operand;
                    return r;
                }
            case F_HASH:
            case F_STRUCT:
            case F_VEC:                 // normal vector with n entries
                r = getvector_init(CELL*(operand+1), nil);
                errexit();
                if (ch == F_STRUCT)
                    vechdr(r) ^= (TYPE_STRUCTURE ^ TYPE_SIMPLE_VEC);
                else if (ch == F_HASH)
                    vechdr(r) ^= (TYPE_HASH ^ TYPE_SIMPLE_VEC);
                for (p=0; p<operand; p++)
                {   push(r);
                    w = fastread();
                    pop(r);
                    errexit();
                    elt(r, p) = w;
                }
                if (ch == F_HASH)
                {
//
// If I have just read in a hash table that was built on EQ or EQL I will
// need to rehash it now.
//
                    if (elt(r, 0) == fixnum_of_int(0) ||
                        elt(r, 0) == fixnum_of_int(1) ||
                        !is_fixnum(elt(r, 0)))
                    {   LispObject v;
                        rehash_this_table(v = elt(r, 4));
                        push(r);
                        v = ncons(v);
                        pop(r);
                        errexit();
                        qcdr(v) = eq_hash_tables;
                        eq_hash_tables = v;
                    }
                }
                return r;

            case F_LST:                 // build list of length n
            case F_DOT:                 // dotted list with n values
                if (ch == F_LST) r = nil;
                else
                {   r = fastread();
                    errexit();
                }
                for (p = 0; p<operand; p++)
                {   push(r);
                    w = fastread();
                    pop(r);
                    errexit();
                    r = cons(w, r);
                    errexit();
                }
                return r;
        }
    }
}

static LispObject fastread(void)
{   int32_t operand = 0, ch = Igetc();
    LispObject nil = C_nil;
    LispObject r = nil, w;
    fasl_byte_count++;
    if (ch == EOF) return aerror("premature EOF in FASL file");
    ch &= 0xff;
    for (;;)
    {   switch (ch)
        {   case F_END:                     // marks end of file
                return eof_symbol;      // CHAR_EOF;

            case F_NIL:                     // represents the value NIL
                return nil;

            case F_TRU:                     // represents the value T
                return lisp_true;

            case F_QUT:                     // (QUOTE <next thing>)
                r = fastread();
                errexit();
                return list2(quote_symbol, r);

            case F_DEF0:                    // introduces defn of compiled code
            case F_DEF1:
            case F_DEF2:
            case F_DEF3:
            case F_DEFN:
            case F_DEFOPT:
            case F_DEFHOPT:
            case F_DEFREST:
            case F_DEFHREST:
            {   LispObject name, bps, env;
                push(r);
                name = fastread();
                pop(r);
                errexit();
                push(name);
                bps = fastread();
                errexitn(1);
                push(bps);
                env = fastread();
                errexitn(2);
                pop(bps);
                if (is_fixnum(bps))
                {   int nn = int_of_fixnum(bps);
                    pop(name);
                    if (qvalue(savedef) != savedef)
                    {   switch (ch)
                        {   case F_DEF0: switch (nn)
                                {   case 0: set_fns(name, wrong_no_na, wrong_no_nb, f0_as_0);
                                        break;
                                    default:goto bad_tail;
                                }
                                break;
                            case F_DEF1: switch (nn)
                                {   case 0: set_fns(name, f1_as_0, too_many_1, wrong_no_1);
                                        break;
                                    case 1: set_fns(name, f1_as_1, too_many_1, wrong_no_1);
                                        break;
                                    default:goto bad_tail;
                                }
                                break;
                            case F_DEF2: switch (nn)
                                {   case 0: set_fns(name, too_few_2, f2_as_0, wrong_no_2);
                                        break;
                                    case 1: set_fns(name, too_few_2, f2_as_1, wrong_no_2);
                                        break;
                                    case 2: set_fns(name, too_few_2, f2_as_2, wrong_no_2);
                                        break;
                                    default:goto bad_tail;
                                }
                                break;
                            case F_DEF3: switch (nn)
                                {   case 0: set_fns(name, wrong_no_na, wrong_no_nb, f3_as_0);
                                        break;
                                    case 1: set_fns(name, wrong_no_na, wrong_no_nb, f3_as_1);
                                        break;
                                    case 2: set_fns(name, wrong_no_na, wrong_no_nb, f3_as_2);
                                        break;
                                    case 3: set_fns(name, wrong_no_na, wrong_no_nb, f3_as_3);
                                        break;
                                    default:goto bad_tail;
                                }
                                break;
                            case F_DEFN: switch (nn)
                            {       default:goto bad_tail;
                                }
                                break;
                            case F_DEFOPT:
                                switch (nn)
                            {       default:goto bad_tail;
                                }
                                break;
                            case F_DEFHOPT:
                                switch (nn)
                            {       default:goto bad_tail;
                                }
                                break;
                            case F_DEFREST:
                                switch (nn)
                            {       default:goto bad_tail;
                                }
                                break;
                            case F_DEFHREST:
                                switch (nn)
                            {       default:goto bad_tail;
                                }
                                break;
                        }
                        if ((qheader(name) & (SYM_C_DEF | SYM_CODEPTR)) ==
                            (SYM_C_DEF | SYM_CODEPTR))
                        {
#ifdef NOISY_RE_PROTECTED_FNS
                            if (verbos_flag & 2)
                            {   freshline_trace();
                                trace_printf("+++ Protected function ");
                                prin_to_trace(name);
                                trace_printf("\n");
                            }
#endif
                        }
                        else
                        {   qenv(name) = env;
                            if ((qheader(name) & SYM_C_DEF) != 0)
                                lose_C_def(name);
                        }
                    }
                    return nil;
                bad_tail:
                    err_printf("+++++ Bad tailcall combination %d %d\n",
                               ch, nn);
                    return nil;
                }
                env = cons(bps, env);
                pop(name);
                errexit();
//
// If the variable !*savedef has !*savedef as its value I will not instate
// function definitions here at all.  This is a very odd thing to do, but
// turns out to help me save memory when I want to load FASL files in order
// to retrieve the Lisp form of definitions but I do not really want the
// code present instated.
//
                if (qvalue(savedef) != savedef)
                {   switch (ch)
                    {   case F_DEF0: set_fns(name, wrong_no_0a, wrong_no_0b,
                                                 bytecoded0);
                            break;
                        case F_DEF1: set_fns(name, bytecoded1,  too_many_1, wrong_no_1);
                            break;
                        case F_DEF2: set_fns(name, too_few_2,   bytecoded2, wrong_no_2);
                            break;
                        case F_DEF3: set_fns(name, wrong_no_3a, wrong_no_3b,
                                                 bytecoded3);
                            break;
                        case F_DEFN: set_fns(name, wrong_no_na, wrong_no_nb, bytecodedn);
                            break;
                        case F_DEFOPT:
                            set_fns(name, byteopt1,  byteopt2, byteoptn);
                            break;
                        case F_DEFHOPT:
                            set_fns(name, hardopt1,  hardopt2, hardoptn);
                            break;
                        case F_DEFREST:
                            set_fns(name, byteoptrest1,  byteoptrest2, byteoptrestn);
                            break;
                        case F_DEFHREST:
                            set_fns(name, hardoptrest1,  hardoptrest2, hardoptrestn);
                            break;
                    }
                    if ((qheader(name) & (SYM_C_DEF | SYM_CODEPTR)) ==
                        (SYM_C_DEF | SYM_CODEPTR))
                    {
#ifdef NOISY_RE_PROTECTED_FNS
                        if (verbos_flag & 2)
                        {   freshline_trace();
                            trace_printf("+++ Protected function ");
                            prin_to_trace(name);
                            trace_printf("\n");
                        }
#endif
                    }
                    else
                    {   qenv(name) = env;
                        if ((qheader(name) & SYM_C_DEF) != 0) lose_C_def(name);
                    }
                    if (qvalue(comp_symbol) != nil &&
                        qfn1(native_symbol) != undefined1)
                    {   name = ncons(name);
                        nil = C_nil;
                        if (!exception_pending())
                            (qfn1(native_symbol))(qenv(native_symbol), name);
                    }
                }
                return nil;
            }

            case F_LS4:
                push(r);
                w = fastread();
                pop(r);
                errexit();
                r = cons(w, r);
                errexit();
            // DROP THROUGH
            case F_LS3:
                push(r);
                w = fastread();
                pop(r);
                errexit();
                r = cons(w, r);
                errexit();
            // DROP THROUGH
            case F_LS2:
                push(r);
                w = fastread();
                pop(r);
                errexit();
                r = cons(w, r);
                errexit();
            // DROP THROUGH
            case F_LS1:
                push(r);
                w = fastread();
                pop(r);
                errexit();
                r = cons(w, r);
                errexit();
                return r;

            case F_CHAR:
//
// I dump characters as 24 bits of data.
//
            {   int32_t b1, b2, b3;
                b1 = Igetc();
                fasl_byte_count++;
                if (b1 == EOF) return aerror("premature EOF in FASL file");
                b2 = Igetc();
                fasl_byte_count++;
                if (b2 == EOF) return aerror("premature EOF in FASL file");
                b3 = Igetc();
                fasl_byte_count++;
                if (b3 == EOF) return aerror("premature EOF in FASL file");
                return ((b1 & 0xff)<<24) |
                       ((b2 & 0xff)<<16) |
                       ((b3 & 0xff)<<8) | TAG_CHAR;
            }

            case F_REP:  // Now no longer useful!
            {   int c1, c2;
                c1 = Igetc();
                fasl_byte_count++;
                if (c1 == EOF) return aerror("premature EOF in FASL file");
                c2 = Igetc();
                fasl_byte_count++;
                if (c2 == EOF) return aerror("premature EOF in FASL file");
                ch = Igetc();
                fasl_byte_count++;
                if (ch == EOF) return aerror("premature EOF in FASL file");
                ch &= 0xff;
                continue;
            }

            case F_RAT:
                w = fastread();
                errexit();
                push(w);
                r = fastread();
                pop(w);
                errexit();
                return make_ratio(w, r);

            case F_CPX:
                w = fastread();
                errexit();
                push(w);
                r = fastread();
                pop(w);
                errexit();
                return make_complex(w, r);

            case F_FPS:
            {   LispObject w1;
                if (Iread((char *)&w1, 4) != 4)
                    return aerror("FASL file corrupted");
                fasl_byte_count += 4;
// For a while I will not allow floating point values to be created
// with one byte-order in FASL files and loaded with the other. The nearest to
// an extent architecture I know of where this will impact me is SPARC, and
// that is not very widely used these days - and SOONISH I will re-work the
// whole FASL scheme in a way that will fix this issue in what I hope will
// be a better way.
//@@            convert_fp_rep(&w1, 0, current_fp_rep, 0);
                return w1;
            }

            case F_FPF:
//
// Floating point values go into FASL files with bytes swapped around
// (if necessary) so that they are in little endian form arranged as
// things are on the Intel architecture. They are converted to that
// layout when written to the fasl file and converted back to native
// layout when read back in. This should mean that fasl files created on
// any one sort of computer will be interpreted correctly by any other
// sort. Well that is subject to use of IEEE formats. Anybody using the
// old-style IBM radix-16 scheme or one of the interesting VAX layouts
// will end up unlucky.
//
                r = getvector(TAG_BOXFLOAT, TYPE_SINGLE_FLOAT,
                              sizeof(Single_Float));
                errexit();
                if (Iread((char *)r + CELL - TAG_BOXFLOAT, 4) != 4)
                    return aerror("FASL file corrupted");
                fasl_byte_count += 4;
//@@            convert_fp_rep((char *)r + CELL - TAG_BOXFLOAT,
//@@                           0, current_fp_rep, 1);
                return r;

            case F_FPD:
                r = getvector(TAG_BOXFLOAT, TYPE_DOUBLE_FLOAT,
                              SIZEOF_DOUBLE_FLOAT);
                errexit();
// zero out the padding word if there is one!
                *(int32_t *)((char *)r + CELL - TAG_BOXFLOAT) = 0;
                if (Iread((char *)r + 8 - TAG_BOXFLOAT, 8) != 8)
                    return aerror("FASL file corrupted");
                fasl_byte_count += 8;
//@@            convert_fp_rep((char *)r + 8 - TAG_BOXFLOAT,
//@@                           0, current_fp_rep, 2);
                return r;

            case F_FPL:
                r = getvector(TAG_BOXFLOAT, TYPE_LONG_FLOAT, SIZEOF_LONG_FLOAT);
                errexit();
// zero out the padding word if there is one!
                *(int32_t *)((char *)r + CELL - TAG_BOXFLOAT) = 0;
                if (Iread((char *)r + 8 - TAG_BOXFLOAT, 8) != 8)
                    return aerror("FASL file corrupted");
                fasl_byte_count += 8;
// Beware offset of 8 here if long floats -> 3 words
//@@            convert_fp_rep((char *)r + 8 - TAG_BOXFLOAT,
//@@                           0, current_fp_rep, 3);
                return r;

            case F_ID1:
            case F_ID2:
            case F_ID3:
            case F_ID4:
            case F_ID5:
            case F_ID6:
            case F_ID7:
            case F_ID8:
            case F_ID9:
            case F_IDA:
            case F_IDB:
            case F_IDC:
            case F_IDD:
            case F_IDE:
            case F_IDF:
                operand = ch - F_ID1 + 1;
                if (Iread(&boffo_char(0), operand) != operand)
                    return aerror("FASL file corrupted");
                fasl_byte_count += operand;
                r = iintern(boffo, operand, CP, 0);
                errexit();
//
// The KEEP_RECENT most recently used symbols are stored in a cyclic buffer
// so that if re-used they will be rapidly available.
//
                {   recent_pointer++;
                    if (recent_pointer == KEEP_RECENT) recent_pointer = 0;
                    w = elt(faslvec, recent_pointer);
#ifdef COMMON
                    if (qpackage(w) == nil)
#else
                    if (qheader(w) & SYM_ANY_GENSYM)
#endif
                    {   push(r);
#ifdef DEBUG_FASL
                        trace_printf("recording gensym ");
                        prin_to_trace(w);
                        trace_printf("\n");
#endif
                        w = cons(w, faslgensyms);
                        pop(r);
                        errexit();
                        faslgensyms = w;
                    }
                    elt(faslvec, recent_pointer) = r;
#ifdef DEBUG_FASL
                    trace_printf("recording ");
                    prin_to_trace(r);
                    trace_printf("\n");
#endif
                }
                return r;

            case F_EXT:                 // extend effective range of operand
            {   int ch1 = Igetc();
                fasl_byte_count++;
                if (ch1 == EOF) return aerror("premature EOF in FASL file");
                operand = (operand << 8) + ((int32_t)ch1 & 0xff);
            }
            ch = (int32_t)Igetc();
            fasl_byte_count++;
            if (ch == EOF) return aerror("premature EOF in FASL file");
            ch &= 0xff;
            continue;           // dispatch again on next byte

            default:
                return fastread1(ch, operand);
        }
    }
}

static char *trim_module_name(char *name, int32_t *lenp)
{   int len = *lenp, len1;
    len1 = len - 1;
//
// Firstly I will decrease the length of the string if there is a "."
// towards the end.
//
    while (len1 > 0 && name[len1] != '.')
    {   if (name[len1] == '/' || name[len1] == '\\')
        {   len1 = len;
            break;
        }
        len1--;
    }
    if (len1 > 0) len = len1;
//
// Now I will try to remove any prefix that ends in "/" or "\".
// Through all this I will attempt to leave SOMETHING over from "silly"
// inputs such as ".....", but exactly what happens in such cases does not
// bother me much!
//
    len1 = len - 1;
    while (len1 > 0 && name[len1] != '/' &&
           name[len1] != '\\' && name[len1] != '.') len1--;
    if (len1 > 0 && len1 < len-2)
    {   len1++;
        name += len1;
        len -= len1;
    }
    *lenp = len;
    return name;
}

LispObject Lcopy_module(LispObject nil, LispObject file)
//
// copy-module will ensure that the output PDS contains a copy of
// the module that is named. There is no provision for copying
// startup banner data - that must be set up by hand.
//
{   Header h;
    int32_t len;
    char *modname;
#if 0
#ifdef SOCKETS
//
// Security measure - remote client can not do "copy-module"
//
    if (socket_server != 0) return onevalue(nil);
#endif
#endif
    if (file == nil) Icopy(NULL, 0);
    else
    {   if (symbolp(file))
        {   file = get_pname(file);
            errexit();
            h = vechdr(file);
        }
        else if (!is_vector(file) || !is_string_header(h = vechdr(file)))
            return aerror("copy-module");
        len = length_of_byteheader(h) - CELL;
        modname = (char *)file + CELL - TAG_VECTOR;
#ifdef TRIM_MODULE_NAMES
        modname = trim_module_name(modname, &len);
#endif
        Icopy(modname, (int)len);
    }
    return onevalue(nil);
}

LispObject Lcopy_native(LispObject nil, LispObject src, LispObject dest)
//
// (copy-native external-file internal-name)
// copies (binary) data from the named external file to a module with
// the specified name. This will mostly be used for native code and is
// not really expected to make sense to normal end-users.
//
{   Header h;
    size_t len;
    const char *modname, *w;
    char filename[LONGEST_LEGAL_FILENAME];
    FILE *srcfile;
    int c;
    memset(filename, 0, sizeof(filename));
#if 0
#ifdef SOCKETS
//
// Security measure - remote client can not do "copy-native"
//
    if (socket_server != 0) return onevalue(nil);
#endif
#endif
    w = get_string_data(src, "copy-native", &len);
    nil = C_nil;
    if (exception_pending()) return nil;
    if (len >= sizeof(filename)) len = sizeof(filename);
    srcfile = open_file(filename, w, len, "rb", NULL);
    if (srcfile == NULL)
    {   error(1, err_open_failed, src);
        return onevalue(nil);
    }
    if (symbolp(dest))
    {   dest = get_pname(dest);
        errexit();
        h = vechdr(dest);
    }
    else if (!is_vector(dest) || !is_string_header(h = vechdr(dest)))
        return aerror("copy-module");
    len = length_of_byteheader(h) - CELL;
    modname = (char *)dest + CELL - TAG_VECTOR;
//
// Unlike the case of copy_module I will demand that the module name
// here be handed down in exactly the form required...
//
    if (open_output(modname, len)) return onevalue(nil);
//
// OK, now the output module is open for writing... now Iputc(int) can
// plant bytes, returning true if trouble, or Iwrite(char *, int) can write
// a block of bytes.
//
    while ((c = getc(srcfile)) != -1) Iputc(c);
    fclose(srcfile);
    if (IcloseOutput()) return onevalue(nil);
// return T on success
    return onevalue(lisp_true);
}

LispObject Ldelete_module(LispObject nil, LispObject file)
//
// delete-module deletes the named module from the output PDS, supposing it
// was there to begin with.  (delete-module nil) deletes any help data.
//
{   Header h;
    int32_t len;
    char *modname;
#if 0
#ifdef SOCKETS
//
// Security measure - remote client can not do "delete-module"
//
    if (socket_server != 0) return onevalue(nil);
#endif
#endif
    if (file == nil) Idelete(NULL, 0);
    else
    {   if (symbolp(file))
        {   file = get_pname(file);
            errexit();
            h = vechdr(file);
        }
        else if (!is_vector(file) || !is_string_header(h = vechdr(file)))
            return aerror("delete-module");
        len = length_of_byteheader(h) - CELL;
        modname = (char *)file + CELL - TAG_VECTOR;
#ifdef TRIM_MODULE_NAMES
        modname = trim_module_name(modname, &len);
#endif
        Idelete(modname, (int)len);
    }
    return onevalue(nil);
}

LispObject Lbanner(LispObject nil, LispObject info)
//
// (startup!-banner nil)      returns the current banner info (nil if none)
// (startup!-banner "string") sets new info
// (startup!-banner "")       deletes any that there is.
//
{   Header h;
    int i;
    int32_t len;
    char *name;
    if (info == nil)
    {   char b[64];
        if (Iopen_banner(0)) return onevalue(nil);
        for (i=0; i<64; i++)
            b[i] = (char)Igetc();
        IcloseInput();
        info = make_string(b);
        validate_string(info);
        errexit();
        return onevalue(info);
    }
#if 0
#ifdef SOCKETS
//
// Security measure - remote client can not change banner info
//
    if (socket_server != 0) return onevalue(nil);
#endif
#endif
    if (symbolp(info))
    {   info = get_pname(info);
        errexit();
        h = vechdr(info);
    }
    else if (!is_vector(info) || !is_string_header(h = vechdr(info)))
        return aerror("banner");
    len = length_of_byteheader(h) - CELL;
    name = (char *)info + CELL - TAG_VECTOR;
    if (len == 0) Iopen_banner(-2); // delete banner info
    else
    {
//
// The following writes to the current output image. Well that is not
// always nice, and in particular I do not want "just" updating the banner
// to create an image file that had otherwise been in "pending" state. So
// the implementation of Iopen_banner(-1) will report failure in that
// case rather than creating a fresh image file.
//
        if (Iopen_banner(-1)) return onevalue(nil);
        if (len > 63) len = 63;
        for (i=0; i<64; i++) Iputc(i >= len ? 0 : name[i]);
        IcloseOutput();
    }
    return onevalue(lisp_true);
}

LispObject Llist_modules(LispObject nil, int nargs, ...)
//
// display information about available modules
//
{   argcheck(nargs, 0, "list-modules");
    Ilist();
    return onevalue(nil);
}

LispObject Lwritable_libraryp(LispObject nil, LispObject file)
//
// This tests if a library handle refers to a writable file.
//
{   int i;
    directory *d;
    if ((file & 0xffff) != SPID_LIBRARY) return onevalue(nil);
    i = (file >> 20) & 0xfff;
    d = fasl_files[i];
    i = d->h.updated;
    return onevalue(Lispify_predicate(i & D_WRITE_OK));
}

#define F_LOAD_MODULE     0
#define F_LOAD_SOURCE     1
#define F_SELECTED_SOURCE 2

// This is a single function that will implement load-module,
// load-source and select-source.

static LispObject load_module(LispObject nil, LispObject file,
                              int option)
//
// load_module() rebinds *package* in COMMON mode, but also note that
// it also rebinds *echo to nil in case we are reading from a stream.
//
{   char filename[LONGEST_LEGAL_FILENAME];
    Header h;
    int32_t len;
    LispObject v;
    bool from_stream = false;
    bool close_mode;
    char *modname;
    memset(filename, 0, sizeof(filename));
    if (is_stream(file)) h=0, from_stream = true;
    else if (symbolp(file))
    {   file = get_pname(file);
        errexit();
        h = vechdr(file);
    }
    else if (!is_vector(file) || !is_string_header(h = vechdr(file)))
    {   switch (option)
        {
        default:
            return aerror("load-module");
        case F_LOAD_SOURCE:
            return aerror("load-source");
        case F_SELECTED_SOURCE:
            return aerror("load-selected-source");
        }
    }
    current_module = file;
    if (from_stream)
    {   if (Iopen_from_stdin())
        {   err_printf("Failed to load module from stream\n");
            return error(1, err_no_fasl, file);
        }
        push(qvalue(standard_input));
        qvalue(standard_input) = file;
        push(qvalue(echo_symbol));
        qvalue(echo_symbol) = nil;
    }
    else
    {   len = length_of_byteheader(h) - CELL;
        modname = (char *)file + CELL - TAG_VECTOR;
        modname = trim_module_name(modname, &len);
        if (Iopen(modname, (int)len, IOPEN_CHECKED, filename))
        {   err_printf("Failed to find \"%s\"\n", filename);
            return error(1, err_no_fasl, file);
        }
    }
    v = getvector_init(CELL*(KEEP_RECENT+1), nil); //@@@ will soon not be needed
    nil = C_nil;
    if (exception_pending())
    {   IcloseInput();
        if (from_stream)
        {   flip_exception();
            pop(qvalue(echo_symbol));
            pop(qvalue(standard_input));
            flip_exception();
        }
        return nil;
    }
//
// I will account time spent fast-loading things as "storage management"
// overhead to be counted as "garbage collector time" rather than
// regular "cpu time"
//
    push_clock();
    if (verbos_flag & 2)
    {   freshline_trace();
        if (option != F_LOAD_MODULE)
        {   if (from_stream) trace_printf("Loading source from a stream\n");
            else trace_printf("Loading source for \"%s\"\n", filename);
        }
        else
        {   if (from_stream) trace_printf("Fast-loading from a stream\n");
            else trace_printf("Fast-loading \"%s\"\n", filename);
        }
    }
    push3(CP, faslvec, faslgensyms);
    faslvec = v;
    faslgensyms = nil;
    recent_pointer = 0;
    fasl_byte_count = 0;
    LispObject r = fastread();
    nil = C_nil;
    if (!exception_pending() && r != eof_symbol &&
        option != F_LOAD_MODULE) r = fastread();
    close_mode = true;
    if (exception_pending()) flip_exception(), close_mode = false;
    pop3(faslgensyms, faslvec, CP);
    IcloseInput();
    if (from_stream)
    {   pop(qvalue(echo_symbol));
        pop(qvalue(standard_input));
    }
    gc_time += pop_clock();
    if (!close_mode)
    {   flip_exception();
        return nil;
    }
// I will process the stuff I just read AFTER I have closed the stream
// etc. That will mean I never try using nested reading of fasl streams.
    if (option == F_LOAD_MODULE)
    {   voideval(r, nil); // voideval is a macro and NEEDS the {} shown here!
    }
    else
    {
// Now r should be a list of the form ( (name def) (name def) )
#ifdef DEBUG_FASL
        trace_printf("SAVEDEF info: ");
        loop_print_trace(r);
        trace_printf("\n");
#endif
        file = nil;
        while (is_cons(r))
        {   LispObject p = qcar(r);
            r = qcdr(r);
            LispObject name, def;
            if (is_cons(p) && is_cons(qcdr(p)))
            {   name = qcar(p);
                def = qcar(qcdr(p));
            }
            else continue;
// if I am in load_selected_source mode I need to check before I set up
// !*savedef information.
            bool getsavedef = true;
            if (option == F_SELECTED_SOURCE)
            {   LispObject w;
#ifdef COMMON
                w = get(name, load_selected_source_symbol, nil);
#else
                w = get(name, load_selected_source_symbol);
#endif
                if (w == nil) getsavedef = false;
                else if (integerp(w) != nil && consp(def))
                {   push4(name, file, r, def);
// The md60 function is called on something like (fname (args...) body...)
                    def = cons(name, qcdr(def));
                    errexitn(4);
                    LispObject w1 = Lmd60(nil, def);
                    if (!numeq2(w, w1)) getsavedef = false;
                    pop4(def, r, file, name);
                }
            }
            if (getsavedef)
            {   push3(name, file, r)
                putprop(name, savedef, def);
                pop3(r, file, name);
                nil = C_nil;
                if (exception_pending()) break;
// Build up a list of the names of all functions whose !*savedef information
// has been established.
                push2(r, name);
                file = cons(name, file);
                pop2(name, r);
                nil = C_nil;
                if (exception_pending()) break;
            }
// Now set up the load_source property on the function name to indicate the
// module it was found in.
            LispObject w;
#ifdef COMMON
            w = get(name, load_source_symbol, nil);
#else
            w = get(name, load_source_symbol);
#endif
            push3(name, file, r)
            w = cons(current_module, w);
            pop3(r, file, name);
            nil = C_nil;
            if (exception_pending()) break;
            push3(name, file, r)
            putprop(name, load_source_symbol, w);
            pop3(r, file, name);
            nil = C_nil;
            if (exception_pending()) break;
        }
    }
    errexit();
#ifdef DEBUG_VALIDATE
    copy_into_nilseg(false);
    validate_all("end of fast-load", __LINE__, __FILE__);
#endif
    if (option == F_LOAD_MODULE) return onevalue(nil);
    else return onevalue(file);
}

LispObject Lload_module(LispObject nil, LispObject file)
{   return load_module(nil, file, F_LOAD_MODULE);
}

LispObject Lload_source(LispObject nil, LispObject file)
{   return load_module(nil, file, F_LOAD_SOURCE);
}

LispObject load_source0(int option)
{
// First I will scan all the input libraries collectin a list of the
// names of modules present in them. I will discard any duplicates
// names.
    LispObject nil = C_nil;
    LispObject mods = nil;
    for (LispObject l = qvalue(input_libraries); is_cons(l); l = qcdr(l))
    {   push2(mods, l);
        LispObject m = Llibrary_members(nil, qcar(l));
        pop2(l, mods);
        errexit();
        while (is_cons(m))
        {   LispObject m1 = qcar(m);
            m = qcdr(m);
            if (Lmemq(nil, m1, mods) != nil) continue;
            push2(l, m);
            mods = cons(m1, mods);
            pop2(m, l);
            errexit();
        }
    }
//@ printf("list of modules = "); simple_print(mods); printf("\n");
// Now I will do load-source or load-selected-source on each module, and
// form the union of the results, which should give me a consolidated
// list of the names of functions seen.
    LispObject r = nil;
    while (is_cons(mods))
    {   LispObject m = qcar(mods);
        mods = qcdr(mods);
        push2(r, mods);
//@ printf("Call load_module on "); simple_print(m); printf("\n");
//@ printf("1 r = "); simple_print(r); printf("\n");
        LispObject w = load_module(nil, m, option);
        pop2(mods, r);
//@ printf("2 r = "); simple_print(r); printf("\n");
//@ printf("2 w = "); simple_print(w); printf("\n");
        errexit();
        push(mods);
        r = Lunion(nil, r, w);
        pop(mods);
//@ printf("3 r = "); simple_print(r); printf("\n");
        errexit();
//@ printf("result from union = "); simple_print(r); printf("\n");
    }
    return onevalue(r); 
}

LispObject Lload_selected_source(LispObject nil, LispObject file)
{   return load_module(nil, file, F_SELECTED_SOURCE);
}

LispObject Lload_source0(LispObject nil, int nargs, ...)
{   argcheck(nargs, 0, "load-source");
    return load_source0(F_LOAD_SOURCE);   
}

LispObject Lload_selected_source0(LispObject nil, int nargs, ...)
{   argcheck(nargs, 0, "load-selected-source");
    return load_source0(F_SELECTED_SOURCE);
}

#ifdef DEBUG_FASL

static void IputcDebug(int c, int line)
{   Iputc(c);
    trace_printf("Iputc(%d/%x/%s: %d %.8x %.8x)\n", c, c, fasl_code(c),
                 line, C_stack, C_nil);
}

#define Iputc(c) IputcDebug(c, __LINE__)

#endif


static void out_fasl_prefix(int32_t n)
//
// Used to generate any prefixes to cope with large operands in
// FASL streams
//
{   if (n != 0)
    {   out_fasl_prefix(n >> 8);
        Iputc(F_EXT);
        Iputc((int)(n & 0xff));
    }
}

LispObject Lmodule_exists(LispObject nil, LispObject file)
{   char filename[LONGEST_LEGAL_FILENAME], tt[32];
    Header h;
    int32_t len;
    int32_t size;
    char *modname;
    memset(filename, 0, sizeof(filename));
    if (symbolp(file))
    {   file = get_pname(file);
        errexit();
        h = vechdr(file);
    }
    else if (!is_vector(file) ||!is_string_header(h = vechdr(file)))
        return aerror("modulep");
    len = length_of_byteheader(h) - CELL;
    modname = (char *)file + CELL - TAG_VECTOR;
#ifdef TRIM_MODULE_NAMES
    modname = trim_module_name(modname, &len);
#endif
    if (Imodulep(modname, (int)len, tt, &size, filename))
        return onevalue(nil);
    tt[24] = 0;
    file = make_string(tt);
    errexit();
    return onevalue(file);
}

LispObject Lstart_module(LispObject nil, LispObject name)
//
// This must be called before write-module - it resets the table of recently-
// mentioned identifiers to be empty.  Calling with a nil argument
// closes the current fasl file, otherwise the arg is the name of
// a file to open.  It is not intended that ordinary programmers call
// this function - it is for use from within the compiler.
// As a special bit of magic the name passed can be a Lisp stream, in
// which case the module data will be written to it.
//
{   LispObject w;
#if 0
#ifdef SOCKETS
//
// Security measure - remote client can not do "FASLOUT" & start-module
//
    if (socket_server != 0) return onevalue(nil);
#endif
#endif
    recent_pointer = 0;
    if (name == nil)
    {   if (fasl_output_file)
        {   int k = (int)Ioutsize() & 0x3;
//
// Here I arrange that all FASL modules will end up being a multiple of
// 4 bytes long.  "WHY?"  Well I once suffered from a machine that was not
// very good at supporting odd-length data transfers (the suggestion I
// collected is that it MAY be because I had an early version of an 80386 CPU
// chip installed). The padding up here is not very painful and may avoid
// some painful trouble on my machine (and hence maybe on some other ones).
// The machine concerned is a PC and the chip and 80386, just in case you
// wondered.  Zortech technical support were very helpful trying to
// track down the crashes I was having - even had they provided a software
// work-around in their code at some time I should leave this code and comment
// in CSL.
// Note (June 1992) I now have a computer with a newer CPU chip in it and
// the problem mentioned above does not arise - but it still seems reasonable
// to keep modules a multiple of 4 bytes long.
// Note (October 1995) Well, now I have a Pentium rather than a 386, and
// my previous 80486 system has gone down the feeding chain to replace the
// old and dodgy 80386. So sometime within the next year or so I will
// remove this comment, but still leave modules padded to multiples of
// 4 bytes since maybe I would introduce more bugs removing that than I would
// save.
// (January 1999) This little essay continues to entertain me. The 386 system
// happens to be around Cambridge again as a "relic" having been discarded as
// too old-fashioned and slow by pretty well everybody! Gosh how machines
// change during the life-time of a piece of software!
// (March 2001) "early 386" bug hah. Gosh that was slow by today's standards.
// (May 2010) !!!!!!!
//
            while (k != 3) k++, Iputc(F_NIL);
            Iputc(F_END);
            IcloseOutput();
            faslvec = nil;
            faslgensyms = nil;
            fasl_output_file = false;
            fasl_stream = nil;
            if (verbos_flag & 2)
            {   freshline_trace();
#ifdef COMMON
                trace_printf(";; FASLEND: hits = %ld, misses = %ld\n",
                             (long)hits, (long)misses);
#else
                trace_printf("+++ FASLEND: hits = %ld, misses = %ld\n",
                             (long)hits, (long)misses);
#endif
            }
            return onevalue(lisp_true);
        }
        else return onevalue(nil);
    }
    else if (is_stream(name))
    {   push(name);
        w = getvector_init(CELL*(KEEP_RECENT+1), nil);
        pop(name);
        errexit();
        faslvec = w;
        hits = misses = 0;
        faslgensyms = nil;
        fasl_stream = name;
        fasl_output_file = true;
        Iopen_to_stdout();
        return onevalue(lisp_true);
    }
    else
    {   char filename[LONGEST_LEGAL_FILENAME];
        char *modname;
        int32_t len;
        Header h;
        memset(filename, 0, sizeof(filename));
        push(name);
        w = getvector_init(CELL*(KEEP_RECENT+1), nil);
        pop(name);
        errexit();
        faslvec = w;
        hits = misses = 0;
        faslgensyms = nil;
#ifdef COMMON
        if (complex_stringp(name))
        {   name = simplify_string(name);
            errexit();
            h = vechdr(name);
        }
        else
#endif
            if (symbolp(name))
            {   name = get_pname(name);
                errexit();
                h = vechdr(name);
            }
            else if (!(is_vector(name))) return aerror("start-module");
            else if (!is_string_header(h = vechdr(name)))
                return aerror("start-module");
        len = length_of_byteheader(h) - CELL;
        modname = (char *)name + CELL - TAG_VECTOR;
//
// Here I will play jolly games! The name as passed in to start-module will
// be allowed to be a fairly general file-name. If there is a suffix of the
// form ".xxx" on the end I will strip that off. If there is a directory-
// style component before that (as signalled by having a "/" or a "\" or
// another "." within the name) I will trim that off too. So the input
// string "/home/xxx/something.fsl" (say) would be treated exactly as if
// it had been just "something".
//
        modname = trim_module_name(modname, &len);
        if ((size_t)len >= sizeof(filename)) len = sizeof(filename);
        if (Iopen(modname, (int)len, IOPEN_OUT, filename))
        {   err_printf("Failed to open \"%s\"\n", filename);
            return onevalue(nil);
        }
        fasl_output_file = true;
        return onevalue(lisp_true);
    }
}

LispObject Ldefine_in_module(LispObject nil, LispObject a)
{   int32_t args, opts, ntail;
#if 0
#ifdef SOCKETS
//
// Security measure - remote client can not do "define-in-module"
//
    if (socket_server != 0) return onevalue(nil);
#endif
#endif
    if (!is_fixnum(a)) return aerror("define-in-module");
    args = int_of_fixnum(a);
    opts = args >> 8;
    ntail = opts >> 10;
    if (ntail != 0)
        return aerror("tailcall magic not supported in FASL files yet");
    opts &= 0x3ff;
    if (opts == 0) switch (args & 0xff)
        {   case 0: Iputc(F_DEF0);
                break;
            case 1: Iputc(F_DEF1);
                break;
            case 2: Iputc(F_DEF2);
                break;
            case 3: Iputc(F_DEF3);
                break;
            default:Iputc(F_DEFN);
                break;
        }
    else switch (opts >> 8)
    {       default:
            case 0: Iputc(F_DEFOPT);
                break;
            case 1: Iputc(F_DEFHOPT);
                break;
            case 2: Iputc(F_DEFREST);
                break;
            case 3: Iputc(F_DEFHREST);
                break;
        }
    return onevalue(nil);
}

#ifdef DEBUG_FASL

static void IwriteDebug(void *x, int n, int line)
{   int i;
    Iwrite(x, n);
    trace_printf("Iwrite %d %.8x %.8x", line, C_nil, C_stack);
    for (i=0; i<n ; i++)
    {   const unsigned char *xc = (const unsigned char *)x;
        trace_printf(" %d/%x", xc[i], xc[i]);
        if (32 <= xc[i] && xc[i] < 0x7f) trace_printf("/'%c'", xc[i]);
    }
    trace_printf("\n");
}

#define Iwrite(x, n) IwriteDebug(x, n, __LINE__)

#endif

static LispObject write_module0(LispObject nil, LispObject a);

static LispObject write_module1(LispObject a)
{   LispObject nil = C_nil;
    if (is_bfloat(a))
    {   Header h = flthdr(a);
        uint32_t bits[2];
        switch (type_of_header(h))
    {       default:
                return aerror("unrecognized FP number type");
            case TYPE_SINGLE_FLOAT:
                Iputc(F_FPF);
                bits[0] = ((uint32_t *)((char *)a + CELL - TAG_BOXFLOAT))[0];
                Iwrite(bits, 4);
                break;
            case TYPE_DOUBLE_FLOAT:
                Iputc(F_FPD);
                // nb offset here is 8 in both 32 and 64 bit modes
                bits[0] = ((uint32_t *)((char *)a + 8 - TAG_BOXFLOAT))[0];
                bits[1] = ((uint32_t *)((char *)a + 8 - TAG_BOXFLOAT))[1];
                Iwrite(bits, 8);
                break;
            case TYPE_LONG_FLOAT:
                Iputc(F_FPL);
                bits[0] = ((uint32_t *)((char *)a + 8 - TAG_BOXFLOAT))[0];
                bits[1] = ((uint32_t *)((char *)a + 8 - TAG_BOXFLOAT))[1];
                Iwrite(bits, 8);
                break;
        }
    }
    else if (is_char(a))
    {   Iputc(F_CHAR);
//
// Note that for somewhat dubious reasons I have separated out the
// end of file character earlier on and treated it oddly.
//
        Iputc((int)(a >> 24) & 0xff);
        Iputc((int)(a >> 16) & 0xff);
        Iputc((int)(a >> 8) & 0xff);
    }
    else if (is_bps(a))
    {   unsigned char *d = data_of_bps(a);
        int32_t len = length_of_byteheader(vechdr(a)) - CELL;
        switch (len >> 8)
        {   case 3: Iputc(F_BP3);
                break;
            case 2: Iputc(F_BP2);
                break;
            case 1: Iputc(F_BP1);
                break;
            default:
                out_fasl_prefix(len >> 8);
                Iputc(F_BP0);
                break;
        }
        Iputc((int)(len & 0xff));
        Iwrite(d, len);
    }
    else if (is_vector(a))
    {   Header h = vechdr(a);
        int32_t len = length_of_header(h) - CELL, i;
        switch (type_of_header(h))
        {
            case TYPE_STRING_1:
            case TYPE_STRING_2:
            case TYPE_STRING_3:
            case TYPE_STRING_4:
                len = length_of_byteheader(h) - CELL;
                out_fasl_prefix(len >> 8);
                Iputc(F_STR);
                Iputc((int)(len & 0xff));
                Iwrite((char *)a + CELL - TAG_VECTOR, len);
                break;

            case TYPE_HASH:      // Writing these may be easy...
            case TYPE_SIMPLE_VEC:
            case TYPE_STRUCTURE:
                len /= CELL;
                out_fasl_prefix(len >> 8);
                Iputc(type_of_header(h) == TYPE_HASH ? F_HASH :
                      type_of_header(h) == TYPE_STRUCTURE ? F_STRUCT : F_VEC);
                Iputc((int)(len & 0xff));
                for (i=0; i<len; i++)
                {   push(a);
                    write_module0(nil, elt(a, i));
                    pop(a);
                    errexit();
                }
                break;

            default:
//
// The explicit enumeration of left-over cases is here ready for when
// (or if!) I ever decide to extend the FASL format to support these
// extra types.  Until I do please note that Common Lisp arrays and
// bit-vectors can not be coped with here.
//
            case TYPE_ARRAY:
            case TYPE_BITVEC_1:
            case TYPE_BITVEC_2:
            case TYPE_BITVEC_3:
            case TYPE_BITVEC_4:
            case TYPE_BITVEC_5:
            case TYPE_BITVEC_6:
            case TYPE_BITVEC_7:
            case TYPE_BITVEC_8:
            case TYPE_BITVEC_9:
            case TYPE_BITVEC_10:
            case TYPE_BITVEC_11:
            case TYPE_BITVEC_12:
            case TYPE_BITVEC_13:
            case TYPE_BITVEC_14:
            case TYPE_BITVEC_15:
            case TYPE_BITVEC_16:
            case TYPE_BITVEC_17:
            case TYPE_BITVEC_18:
            case TYPE_BITVEC_19:
            case TYPE_BITVEC_20:
            case TYPE_BITVEC_21:
            case TYPE_BITVEC_22:
            case TYPE_BITVEC_23:
            case TYPE_BITVEC_24:
            case TYPE_BITVEC_25:
            case TYPE_BITVEC_26:
            case TYPE_BITVEC_27:
            case TYPE_BITVEC_28:
            case TYPE_BITVEC_29:
            case TYPE_BITVEC_30:
            case TYPE_BITVEC_31:
            case TYPE_BITVEC_32:
            case TYPE_MIXED1:
            case TYPE_MIXED2:
                return aerror("vector type unsupported by write-module");
        }
    }
    else return aerror("write-module");
    return nil;
}

LispObject Lwrite_module(LispObject nil, LispObject a, LispObject b)
{
#ifdef DEBUG_FASL
    push2(a, b);
    trace_printf("FASLOUT: ");
    loop_print_trace(a);
    errexit();
    trace_printf("\n");
    loop_print_trace(b);
    errexit();
    trace_printf("\n");
    pop2(b, a);
#endif
    push(b);
    write_module0(nil, a);
    errexit();
    pop(b);
    write_module0(nil, b);
    errexit();
    return onevalue(nil);
}

static LispObject write_module0(LispObject nil, LispObject a)
//
// write one expression to the currently selected output stream.
// That stream ought to have been opened using start-module, and is
// binary (i.e. no record separators or concern about record length
// must intrude).
//
{
#if 0
#ifdef SOCKETS
//
// Security measure - remote client can not do "write-module"
//
    if (socket_server != 0) return onevalue(nil);
#endif
#endif
    if (a == nil) Iputc(F_NIL);
    else if (a == lisp_true) Iputc(F_TRU);
    else if (a == eof_symbol) Iputc(F_END);
//
// In Common Lisp mode there will be a certain amount of horrible fun with
// symbols and the package system.  But a symbol that is EQ to one recently
// processed can be handled that way regardless.
//
    else if (is_symbol(a))
    {   int32_t i, len;
        LispObject w, w1;
        int pkgid = 0;
        int32_t k;
#ifdef COMMON
        int32_t lenp;
#endif
        for (i=0; i<KEEP_RECENT; i++)
        {   int32_t w = recent_pointer - i;
            if (w < 0) w += KEEP_RECENT;
            if (a == elt(faslvec, w))
            {   Iputc((int)(F_OLD+i));
                hits++;
                return onevalue(nil);
            }
        }
        push(a);
        w = get_pname(a);
        pop(a);
        errexit();
//
// The FASL mechanism does not in general preserve EQness. In particular
// cyclic structures will upset it, and multiple references to the same
// string or float (etc) will read back as distinct entities. However
// within one S-expression I will arrange that uninterned symbols are
// handled tolerably cleanly... The first time such a symbol is written
// its name is dumped in the file. When this is read back a new uninterned
// symbol with that name is created.  Usually the next few uses will use
// the "recently referenced symbol" mechanism, and so will refer back to
// this value. For gensyms I extend the usual cyclic buffer that holds the
// recently mentioned symbols with a fall-back list of mentioned gensyms,
// and refer into that using F_EXT followed by a "recent" reference. This
// mechanism gets activated especially if the FASL file contains a
// macro-expanded but not compiled form where the expansion introduces
// gensyms as labels etc.
//

#ifdef COMMON
//
// The code here is expected to match that in print.c. It sets pkgid to
// indicate how the symbol involved needs to be put into the FASL file.
// My byte format there is optimised for the case where no package marker
// is needed. The values of pkgid are:
//  0    no package marker needed
//  1    display as #:xxx      (ie as a gensym)
//  2    display as :xxx       (ie in keyword package)
//  3    display as ppp:xxx    (external in its home package)
//  4    display as ppp::xxx   (internal in its home package)
//
        if (qpackage(a) == nil)
        {   for (w1 = faslgensyms, k=0; w1!=nil; w1=qcdr(w1), k++)
            {   if (qcar(w1) == a)
                {   out_fasl_prefix(1 + (k>>7));
                    Iputc((int)(F_OLD+(k & 0x7f)));
#ifdef DEBUG_FASL
                    trace_printf("++ Ancient FASL gensym ref %d\n", k);
#endif
                    hits++;
                    return onevalue(nil);
                }
            }
            pkgid = 1; // gensym
        }
        else if (qpackage(a) == qvalue(keyword_package)) pkgid = 2;
        else if (qpackage(a) == CP) pkgid = 0; // home is current
        else
        {   pkgid = 3;
            k = packflags_(CP);
            if (k != 0 && k <= 10)
            {   k = ((int32_t)1) << (k+SYM_IN_PKG_SHIFT-1);
                if (k & qheader(a)) pkgid = 0;
            }
            else k = 0;
            if (pkgid != 0)
            {   push2(a, w);
                w1 = Lfind_symbol_1(nil, w);
                pop2(w, a);
                errexit();
                if (mv_2 != nil && w1 == a)
                {   pkgid = 0;
                    qheader(a) |= k;
                }
                else if (qheader(a) & SYM_EXTERN_IN_HOME) pkgid = 3;
                else pkgid = 4;
            }
        }
        misses++;
        {   recent_pointer++;
            if (recent_pointer == KEEP_RECENT) recent_pointer = 0;
            w1 = elt(faslvec, recent_pointer);
            if (qpackage(w1) == nil)
            {   push(a);
#ifdef DEBUG_FASL
                trace_printf("recording gensym ");
                prin_to_trace(w1);
                trace_printf("\n");
#endif
                w1 = cons(w1, faslgensyms);
                pop(a);
                errexit();
                faslgensyms = w1;
            }
            elt(faslvec, recent_pointer) = a;
#ifdef DEBUG_FASL
            trace_printf("recording ");
            prin_to_trace(a);
            trace_printf("\n");
#endif
        }
        len = length_of_byteheader(vechdr(w)) - CELL;
        switch (pkgid)
        {   case 0: if (1 <= len && len <= 15) Iputc(F_ID1 + (int)len - 1);
                else
                {   out_fasl_prefix(len >> 8);
                    Iputc(F_SYM);
                    Iputc((int)(len & 0xff));
                }
                lenp = -1;
                break;
            case 1: out_fasl_prefix(len >> 8);
                Iputc(F_PKGINT);
                Iputc(0);
                lenp = 0;
                break;
            case 2: out_fasl_prefix(len >> 8);
                Iputc(F_PKGEXT);
                Iputc(0);
                lenp = 0;
                break;
            case 3: out_fasl_prefix(len >> 8);
                Iputc(F_PKGEXT);
                lenp = 1;
                break;
            case 4: out_fasl_prefix(len >> 8);
                Iputc(F_PKGINT);
                lenp = 1;
                break;
        }
        if (lenp > 0)
        {   push(w);
            a = packname_(qpackage(a));
            pop(w);
            errexit();
            lenp = length_of_byteheader(vechdr(a)) - CELL;
//
// Another ugliness rears its head here... I allow for symbols that have
// very long names, but I will only support packages where the name of the
// package is less then 256 characters. This is so I can use a one-byte
// counter to indicate its length. If I REALLY have to I can put in
// support for ultra-long names for packages, but the mess involved
// seems offensive at the moment. I truncate any over-long package name
// at 255 here. Silently.
//
            if (lenp > 255) lenp = 255;
            Iputc(lenp);
            Iputc((int)(len & 255));
            Iwrite((char *)a + CELL - TAG_VECTOR, lenp);
        }
        else if (lenp == 0) Iputc((int)(len & 0xff));
        Iwrite((char *)w + CELL - TAG_VECTOR, len);
#else
//
// In Standard Lisp mode things that were gensyms in the original
// will probably get read back in as ordinary symbols. This at least
// ensures that multiple references to the same gensym end up matching, and
// it is less effort than the Common Lisp solution...
// Actually I am now finding this to be UNSATISFACTORY and am going to
// change it to be much more like the behaviour I have in the COMMON case.
//
        if ((qheader(a) & SYM_ANY_GENSYM) != 0)
        {   for (w1 = faslgensyms, k=0; w1!=nil; w1=qcdr(w1), k++)
            {   if (qcar(w1) == a)
                {   out_fasl_prefix(1 + (k>>7));
                    Iputc((int)(F_OLD+(k & 0x7f)));
#ifdef DEBUG_FASL
                    trace_printf("++ Ancient FASL gensym ref %d\n", k);
#endif
                    hits++;
                    return onevalue(nil);
                }
            }
            pkgid = 1; // gensym
        }
        misses++;
//
// See comment where F_GENSYM is read to understand why gensyms must be
// recorded even when skipping...
//
        {   recent_pointer++;
            if (recent_pointer == KEEP_RECENT) recent_pointer = 0;
            w1 = elt(faslvec, recent_pointer);
            if ((qheader(w1) & SYM_ANY_GENSYM) != 0)
            {   push(a);
#ifdef DEBUG_FASL
                trace_printf("recording gensym ");
                prin_to_trace(w1);
                trace_printf("\n");
#endif
                w1 = cons(w1, faslgensyms);
                pop(a);
                errexit();
                faslgensyms = w1;
            }
            elt(faslvec, recent_pointer) = a;
#ifdef DEBUG_FASL
            trace_printf("recording ");
            prin_to_trace(a);
            trace_printf("\n");
#endif
        }
        len = length_of_byteheader(vechdr(w)) - CELL;
        if (pkgid == 0)
        {   if (1 <= len && len <= 15) Iputc(F_ID1 + (int)len - 1);
            else
            {   out_fasl_prefix(len >> 8);
                Iputc(F_SYM);
                Iputc((int)(len & 0xff));
            }
        }
        else
        {   out_fasl_prefix(len >> 8);  // here it is a gensym
            Iputc(F_GENSYM);
            Iputc((int)(len & 0xff));
        }
        Iwrite((char *)w + CELL - TAG_VECTOR, len);
#endif
    }
    else if (is_cons(a))
    {   int32_t len, i;
        LispObject cara = qcar(a), cdra = qcdr(a);
        if (cara == quote_symbol && consp(cdra) && qcdr(cdra) == nil)
        {   Iputc(F_QUT);
            return write_module0(nil, qcar(cdra));
        }
        len = 1;
        while (consp(cdra)) len++, cdra = qcdr(cdra);
        out_fasl_prefix(len >> 8);
        if (cdra == nil)
        {   switch (len)
            {   case 1:
                    Iputc(F_LS1);
                    break;
                case 2:
                    Iputc(F_LS2);
                    break;
                case 3:
                    Iputc(F_LS3);
                    break;
                case 4:
                    Iputc(F_LS4);
                    break;
                default:
                    Iputc(F_LST);
                    Iputc((int)(len & 0xff));
                    break;
            }
        }
        else
        {   Iputc(F_DOT);
            Iputc((int)(len & 0xff));
            push(a);
            stackcheck1(1, cdra);
            write_module0(nil, cdra);
            pop(a);
            errexit();
        }
        cdra = nil;
        for (i=0; i<len; i++)
        {   push(a);
            cdra = cons(qcar(a), cdra);
            pop(a);
            errexit();
            a = qcdr(a);
        }
        for (i=0; i<len; i++)
        {   push(cdra);
            write_module0(nil, qcar(cdra));
            pop(cdra);
            errexit();
            cdra = qcdr(cdra);
        }
    }
    else if (is_fixnum(a))
    {   int32_t n = int_of_fixnum(a);
        bool sign;
//
// The fixnum range is 0xf8000000 to 0x07ffffff
//
        if (n < 0) n = -n, sign = true;
        else sign = false;
        out_fasl_prefix(n >> 8);
        Iputc(sign ? F_NEG : F_INT);
        Iputc((int)(n & 0xff));
    }
    else if (is_numbers(a))
    {   Header h = numhdr(a);
        int32_t len, i;
        switch (type_of_header(h))
    {       default:
                return aerror("unrecognized number type");
            case TYPE_RATNUM:
                Iputc(F_RAT);
                break;
            case TYPE_COMPLEX_NUM:
                Iputc(F_CPX);
                break;
            case TYPE_BIGNUM:
                len = length_of_header(h) - CELL;
                out_fasl_prefix(len >> 8);
                Iputc(F_BIG);
                Iputc((int)(len & 0xff));
//
// I write out the value byte by byte so that the binary in the file
// does not depend on the byte-ordering used by the host computer.
//
                for (i=0; i<len; i+=4) // always in 32-bit units
                {   uint32_t v =
                        *(uint32_t *)((char *)a + CELL - TAG_NUMBERS + i);
                    Iputc((int)(v >> 24) & 0xff);
                    Iputc((int)(v >> 16) & 0xff);
                    Iputc((int)(v >> 8) & 0xff);
                    Iputc((int)v & 0xff);
                }
                return onevalue(nil);
        }
#ifdef COMMON
        write_module0(nil, *(LispObject *)((char *)a + CELL - TAG_NUMBERS));
        errexit();
        return write_module0(nil,
                             *(LispObject *)((char *)a + 2*CELL - TAG_NUMBERS));
#endif
    }
    else if (is_sfloat(a))
    {   uint32_t w = (uint32_t)a;
//@@    convert_fp_rep(&w, current_fp_rep, 0, 0);
        Iputc(F_FPS);
        Iwrite((char *)&w, 4);
    }
    else write_module1(a);
    return onevalue(nil);
}

//
// (set-help-file "key" "path") puts an extra help file on the cwin
// HELP menu. If "path" is NIL then the item specified by "key" is
// removed. If "key" is NIL then all user-inserted items are removed.
//

LispObject Lset_help_file(LispObject nil, LispObject a, LispObject b)
{
#ifdef HAVE_FWIN
    const char *w;
    char *aa, *bb = NULL;
    size_t lena, lenb;
    if (a != nil)
    {   w = get_string_data(a, "set-help-file", &lena);
        errexit();
        aa = (char *)malloc(lena+1);
        if (aa == NULL) return aerror("set-help-file");
        memcpy(aa, w, lena);
        aa[lena] = 0;
    }
    else
    {   aa = NULL;
        b = nil;
    }
    if (b != nil)
    {   w = get_string_data(b, "set-help-file", &lenb);
        errexit();
        bb = (char *)malloc(lenb+1);
        if (bb == NULL) return aerror("set-help-file");
        memcpy(bb, w, lenb);
        bb[lenb] = 0;
    }
    fwin_set_help_file(aa, bb);
#endif
    return onevalue(nil);
}

char prompt_string[MAX_PROMPT_LENGTH];

LispObject Lsetpchar(LispObject nil, LispObject a)
{   LispObject old = prompt_thing;
    prompt_thing = a;
#define escape_nolinebreak 0x80
    escaped_printing = escape_nolinebreak;
    set_stream_write_fn(lisp_work_stream, count_character);
    memory_print_buffer[0] = 0;
    set_stream_write_other(lisp_work_stream, write_action_list);
    stream_byte_pos(lisp_work_stream) = 0;
    stream_char_pos(lisp_work_stream) = 0;
    active_stream = lisp_work_stream;
    push(old);
    internal_prin(a, 0);
    pop(old);
    errexit();
    memcpy(prompt_string, memory_print_buffer, MAX_PROMPT_LENGTH);
    prompt_string[MAX_PROMPT_LENGTH-1] = 0;
#ifdef HAVE_FWIN
    fwin_set_prompt(prompt_string);
#endif
    return onevalue(old);
}

// end of fasl.cpp
