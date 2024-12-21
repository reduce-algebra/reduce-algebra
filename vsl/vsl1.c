// Visible Lisp                                A C Norman, August 2012
//
// This is a small Lisp system. It is especially
// intended for use of the Raspberry Pi board, but should build
// on almost any computer with a modern C compiler.

// This code may be used subject to the BSD licence included in the file
// "bsd.txt" that should accompany it.

#ifdef __GNUC__
#define INLINE inline
#define USE_INLINE
#else // __GNUC__
#define INLINE
#endif // __GNUC__

//#ifndef DEBUG
//#define NDEBUG 1
//#endif // DEBUG

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdarg.h>
#include <assert.h>

#ifndef NO_ZLIB
#include <zlib.h>
#else

typedef FILE *gzFile;

static gzFile gzopen(const char *name, const char *mode)
{   return fopen(name, mode);
}

static gzclose(gzFile f)
{   fclose(f);
}

static size_t gzread(gzFile f, void *b, size_t n)
{   return fread(b, 1, n, f);
}

static void gzwrite(gzFile f, void *b, size_t n)
{   fwrite(b, 1, n, f);
}
#endif

char promptstring[1000] = "> ";

#ifndef NOLIBEDIT
#include <histedit.h>

static EditLine *elx_e;
static History *elx_h;
static HistEvent elx_v;

const char *prompt(EditLine *e)
{   return promptstring;
}

const char *elx_line = NULL;
int elx_count = 0;
#endif // NOLIBEDIT

#ifdef WIN32
#define popen _popen
#endif

// A Lisp item is represented as an integer and the low 3 bits
// contain tag information that specify how the rest will be used.

typedef intptr_t LispObject;
typedef uintptr_t ULispObject;

#define TAGBITS    0x7

#define tagCONS    0     // Traditional Lisp "cons" item.
#define tagSYMBOL  1     // a symbol.
#define tagFIXNUM  2     // An immediate integer value (29 or 61 bits).
#define tagFLOAT   3     // A double-precision number.
#define tagATOM    4     // Something else that will have a header word.
#define tagFORWARD 5     // Used during garbage collection.
#define tagHDR     6     // the header word at the start of an atom .
#define tagSPARE   7     // not used!

// Note that in the above I could have used tagATOM to include the case
// of symbols (aka identifiers) but as an optimisation I choose to make that
// a special case. I still have one spare code (tagSPARE) that could be
// used to extend the system.

// Now I provide macros that test the tag bits. These are all rather obvious!

#define isCONS(x)    (((x) & TAGBITS) == tagCONS)
#define isSYMBOL(x)  (((x) & TAGBITS) == tagSYMBOL)
#define isFIXNUM(x)  (((x) & TAGBITS) == tagFIXNUM)
#define isFLOAT(x)   (((x) & TAGBITS) == tagFLOAT)
#define isATOM(x)    (((x) & TAGBITS) == tagATOM)
#define isFORWARD(x) (((x) & TAGBITS) == tagFORWARD)
#define isHDR(x)     (((x) & TAGBITS) == tagHDR)

// In memory CONS cells and FLOATS exist as just 2-word items with
// all their bits in use. All other sorts of data have a header word
// at their start.
// This contains extra information about the exact form of data present.

#define TYPEBITS       0x78

#define typeSYM        0x00
#define typeGENSYM     0x08
#define typeSTRING     0x10
#define typeVEC        0x18
#define typeBIGNUM     0x20
//                     0x28
#define typeEQHASH     0x30
#define typeEQHASHX    0x38
#define typeEQUALHASH  0x40
#define typeEQUALHASHX 0x48
// Codes 0x28,    0x50, 0x58, 0x60, 0x68, 0x70 and 0x78 spare!

#define veclength(h)  (((uintptr_t)(h)) >> 7)
#define packlength(n) (((LispObject)(n)) << 7)

#ifdef USE_INLINE
static INLINE LispObject *heapaddr(LispObject x)
{
    return (LispObject *)x;
}

#else // USE_INLINE
#define heapaddr(x) ((LispObject *)(x))

#endif // USE_INLINE
// General indirection

#define qind(x)     (*((LispObject *)(x)))

// Accessor macros the extract fields from LispObjects ...

#define qcar(x) ((heapaddr(x))[0])
#define qcdr(x) ((heapaddr(x))[1])

// For all other types I must remove the tagging information before I
// can use the item as a pointer.

// An especially important case is that of Symbols. These are the fields that
// they provide.

typedef LispObject SpecialForm(LispObject lits, LispObject a1);
typedef LispObject LispFn(LispObject lits, int nargs, ...);

#define qflags(x) ((heapaddr((x)-tagSYMBOL))[0])
#define qvalue(x) ((heapaddr((x)-tagSYMBOL))[1])
#define qplist(x) ((heapaddr((x)-tagSYMBOL))[2])
#define qpname(x) ((heapaddr((x)-tagSYMBOL))[3])
#define qlits(x)  ((heapaddr((x)-tagSYMBOL))[4])
#define qdefn(x)  (((void **)       (heapaddr((x)-tagSYMBOL)))[5])
#define SYMSIZE 6

// Bits within the flags field of a symbol. Uses explained later on.

#define flagTRACED    0x080
#define flagSPECFORM  0x100
#define flagMACRO     0x200
#define flagGLOBAL    0x400
#define flagFLUID     0x800
// There are LOTS more bits available for flags etc here if needbe!

// Other atoms have a header that gives info about them. Well as a special
// case I will allow that something tagged with tagATOM but with zero as
// its address is a special marker value...

#define NULLATOM   (tagATOM + 0)
#define qheader(x) ((heapaddr((x)-tagATOM))[0])

// Fixnums and Floating point numbers are rather easy!

#define qfixnum(x)     ((x) >> 3)
#define packfixnum(n)  ((LispObject)((((ULispObject)(n)) << 3) + tagFIXNUM))

#define MIN_FIXNUM     qfixnum(INTPTR_MIN)
#define MAX_FIXNUM     qfixnum(INTPTR_MAX)

#define qfloat(x)      (((double *)((x)-tagFLOAT))[0])

#define isBIGNUM(x) (isATOM(x) && ((qheader(x) & TYPEBITS) == typeBIGNUM))
#define qint64(x) (*(int64_t *)((x) - tagATOM + 8))

#define isSTRING(x) (isATOM(x) && ((qheader(x) & TYPEBITS) == typeSTRING))
#define qstring(x) ((char *)((x) - tagATOM + sizeof(LispObject)))

#define isVEC(x) (isATOM(x) && ((qheader(x) & TYPEBITS) == typeVEC))
#define isEQHASH(x) (isATOM(x) && ((qheader(x) & TYPEBITS) == typeEQHASH))
#define isEQHASHX(x) (isATOM(x) && ((qheader(x) & TYPEBITS) == typeEQHASHX))
#define isEQUALHASH(x) (isATOM(x) && ((qheader(x) & TYPEBITS) == typeEQUALHASH))
#define isEQUALHASHX(x) (isATOM(x) && ((qheader(x) & TYPEBITS) == typeEQUALHASHX))

// The Lisp heap will have fixed size. Here I make it 256 Mbytes on a
// 32-bit machine and 612M on a 64-bit one.

#ifndef MEM
#define MEM (256*(sizeof(void *)/4))
#endif // MEM

#define BITMAPSIZE ((uintptr_t)MEM*1024*(1024/128))
#define HEAPSIZE   (BITMAPSIZE*128)
#define STACKSIZE  (128*1024*sizeof(LispObject))

LispObject stackbase, *sp, stacktop;
// I should probably arrange to check for stack overflow here.
#define push(x)        { *sp++ = (x); }
#define TOS            (sp[-1])
#define pop(x)         { (x) = *--sp; }
#define push2(x, y)    { push(x); push(y); }
#define pop2(y, x)     { pop(y); pop(x); }
#define push3(x, y, z) { push(x); push(y); push(z); }
#define pop3(z, y, x)  { pop(z); pop(y); pop(x); }

// This sets the size of the hash table used to store all the symbols
// that Lisp knows about. I note that if I built a serious application
// such as the Reduce algebra system (reduce-algebra.sourceforge.net) I would
// end up with around 7000 symbols in a basic installation! So the size
// table I use here intended to give decent performance out to that scale.
// This is (of course) utterly over the top for the purpose of toy and
// demonstration applications! I make the table size a prime in the hope that
// that will help keep hashed distribution even across it.

#define OBHASH_SIZE 1009

// Some Lisp values that I will use frequently...

#define nil        bases[0]
#define undefined  bases[1]
#define lisptrue   bases[2]
#define lispsystem bases[3]
#define echo       bases[4]
#define lambda     bases[5]
#define function   bases[6]
#define quote      bases[7]
#define backquote  bases[8]
#define comma      bases[9]
#define comma_at   bases[10]
#define comma_dot  bases[11]
#define eofsym     bases[12]
#define cursym     bases[13]
#define work1      bases[14]
#define work2      bases[15]
#define restartfn  bases[16]
#define expr       bases[17]
#define subr       bases[18]
#define fexpr      bases[19]
#define fsubr      bases[20]
#define macro      bases[21]
#define input      bases[22]
#define output     bases[23]
#define pipe       bases[24]
#define eq         bases[25]
#define equal      bases[26]
#define raise      bases[27]
#define lower      bases[28]
#define dfprint    bases[29]
#define bignum     bases[30]
#define charvalue    bases[31]
#define toploopeval  bases[32]
#define loseflag     bases[33]
#define condsymbol   bases[34]
#define prognsymbol  bases[35]
#define gosymbol     bases[36]
#define returnsymbol bases[37]
#ifdef PSL
#define dummyvar     bases[38]
#endif
#define BASES_SIZE       39

LispObject bases[BASES_SIZE];
LispObject obhash[OBHASH_SIZE];

// ... and non-LispObject values that need to be saved as part of a
// heap image.

#define headerword     nonbases[0]
#define heap1base      nonbases[1]
#define heap1top       nonbases[2]
#define fringe1        nonbases[3]
#define saveinterp     nonbases[4]
#define saveinterpspec nonbases[5]
#define fpfringe1      nonbases[6]
#define NONBASES_SIZE           7

LispObject nonbases[NONBASES_SIZE];

void my_exit(int n)
{
    printf("\n+++++ Exit called %d\n", n);
    fflush(stdout);
    fflush(stderr);
    abort();
}

LispObject heap2base, heap2top, fringe2, fpfringe2, bitmap;

// Here there are some memory blocks allocated, each with their
// halfbitmapsize field filled in. Fill in the rest of the entries
// in them. 

#define ALIGN8(a) (((a) + 7) & ~(LispObject)7)

void allocateheap(void *pool)
{
    heap1base = (LispObject)pool;
    heap1base = ALIGN8(heap1base); // ensure alignment
    heap1top = heap2base = heap1base + (HEAPSIZE/2);
    heap2top = heap2base + (HEAPSIZE/2);
    stackbase = heap2top;
    stacktop = stackbase + STACKSIZE;
    bitmap = stacktop;
    sp = (LispObject *)stackbase;
    fringe1 = heap1base;
    fringe2 = heap2base;
    fpfringe1 = heap1top;
    fpfringe2 = heap2top;
}

// Now I have enough to let me define various allocation functions.

extern void reclaim();
extern LispObject error1(const char *s, LispObject a);
extern LispObject error2(const char *s, LispObject a, LispObject b);

static INLINE LispObject cons(LispObject a, LispObject b)
{
    if (fringe1 + 2*sizeof(LispObject) >= fpfringe1)
    {   push2(a, b);
        reclaim();
        pop2(b, a);
    }
    qcar(fringe1) = a;
    qcdr(fringe1) = b;
    a = fringe1;
    fringe1 += 2*sizeof(LispObject);
    return a;
}

static INLINE LispObject list2star(LispObject a, LispObject b, LispObject c)
{   // (cons a (cons b c))
    if (fringe1 + 4*sizeof(LispObject) >= fpfringe1)
    {   push3(a, b, c);
        reclaim();
        pop3(c, b, a);
    }
    qcar(fringe1) = a;
    qcdr(fringe1) = fringe1 + 2*sizeof(LispObject);
    a = fringe1;
    fringe1 += 2*sizeof(LispObject);
    qcar(fringe1) = b;
    qcdr(fringe1) = c;
    fringe1 += 2*sizeof(LispObject);
    return a;
}

static INLINE LispObject acons(LispObject a, LispObject b, LispObject c)
{   // (cons (cons a b) c)
    if (fringe1 + 4*sizeof(LispObject) >= fpfringe1)
    {   push3(a, b, c);
        reclaim();
        pop3(c, b, a);
    }
    qcar(fringe1) = fringe1 + 2*sizeof(LispObject);
    qcdr(fringe1) = c;
    c = fringe1;
    fringe1 += 2*sizeof(LispObject);
    qcar(fringe1) = a;
    qcdr(fringe1) = b;
    fringe1 += 2*sizeof(LispObject);
    return c;
}

static INLINE LispObject boxfloat(double a)
{   LispObject r;
    if (fringe1 +sizeof(double) >= fpfringe1) reclaim();
    fpfringe1 -= sizeof(double);
    r = fpfringe1 + tagFLOAT;
    qfloat(r) = a;
    return r;
}

// The code here does not fill in ANY of the fields within the symbol. That
// needs to be done promptly.

LispObject allocatesymbol()
{   LispObject r;
    if (fringe1 + 4*sizeof(LispObject) >= fpfringe1) reclaim();
    r = fringe1 + tagSYMBOL;
    qflags(r) = tagHDR + typeSYM;
    fringe1 += 6*sizeof(LispObject);
    return r;
}

// This one allocates an atom that is n bytes long (plus its header
// word) and again does not fill in ANY of the fields.

static INLINE LispObject allocateatom(int n)
{   LispObject r;
// The actual amount of space allocated must include a word for the
// header and must then be rounded up to be a multiple of 8.
    int nn = ALIGN8(sizeof(LispObject) + n);
    if (fringe1 + nn >= fpfringe1) reclaim();
    r = fringe1 + tagATOM;
// I mark the new vector as being a string so that it is GC safe
    qheader(r) = tagHDR + typeSTRING + packlength(n);
    fringe1 += nn;
    return r;
}

static INLINE LispObject makestring(const char *s, int len)
{
    LispObject r = allocateatom(len);
//  qheader(r) = tagHDR + typeSTRING + packlength(len); // already done!
    memcpy(qstring(r), s, len);
    return r;
}

#define elt(v, n) \
    (((LispObject *)((v)-tagATOM+sizeof(LispObject)))[n])

static INLINE LispObject makevector(int maxindex)
{   int i, len = (maxindex+1)*sizeof(LispObject);
    LispObject r = allocateatom(len);
    qheader(r) = tagHDR + typeVEC + packlength(len);
    for (i=0; i<=maxindex; i++) elt(r, i) = nil;
    return r;
}

static INLINE LispObject boxint64(int64_t a)
{
    LispObject r = allocateatom(8);
    qheader(r) = tagHDR + typeBIGNUM + packlength(8);
    qint64(r) = a;
    return r;
}

// I will try to have a general macro that will help me with bringing
// everything to consistent numeric types - ie I can start off with a
// mix of fixnums, bignums and floats. The strategy here is that if either
// args is a float then the other is forced to that, and then for all sorts
// of pure integer work everything will be done as int64_t

#define NUMOP(name, a, b)                                                \
    if (isFLOAT(a))                                                      \
    {   if (isFLOAT(b)) return FF(qfloat(a), qfloat(b));                 \
        else if (isFIXNUM(b)) return FF(qfloat(a), (double)qfixnum(b));  \
        else if (isBIGNUM(b)) return FF(qfloat(a), (double)qint64(b));   \
        else return error1("Bad argument for " name, b);                 \
    }                                                                    \
    else if (isBIGNUM(a))                                                \
    {   if (isFLOAT(b)) return FF((double)qint64(a), qfloat(b));         \
        else if (isFIXNUM(b)) return BB(qint64(a), (int64_t)qfixnum(b)); \
        else if (isBIGNUM(b)) return BB(qint64(a), qint64(b));           \
        else return error1("Bad argument for " name, b);                 \
    }                                                                    \
    else if (isFIXNUM(a))                                                \
    {   if (isFLOAT(b)) return FF((double)qfixnum(a), qfloat(b));        \
        else if (isFIXNUM(b)) return BB((int64_t)qfixnum(a),             \
                                        (int64_t)qfixnum(b));            \
        else if (isBIGNUM(b)) return BB((int64_t)qfixnum(a), qint64(b)); \
        else return error1("Bad argument for " name, b);                 \
    }                                                                    \
    else return error1("Bad argument for " name, a)

#define UNARYOP(name, a)                                                 \
    if (isFIXNUM(a)) return BB((int64_t)qfixnum(a));                     \
    else if (isFLOAT(a)) return FF(qfloat(a));                           \
    else if (isBIGNUM(a)) return BB(qint64(a));                          \
    else return error1("Bad argument for " name, a)

// Similar, but only supporting integer (not floating point) values

#define INTOP(name, a, b)                                                \
    if (isBIGNUM(a))                                                     \
    {   if (isFIXNUM(b)) return BB(qint64(a), (int64_t)qfixnum(b));      \
        else if (isBIGNUM(b)) return BB(qint64(a), qint64(b));           \
        else return error1("Bad argument for " name, b);                 \
    }                                                                    \
    else if (isFIXNUM(a))                                                \
    {   if (isFIXNUM(b)) return BB((int64_t)qfixnum(a),                  \
                                   (int64_t)qfixnum(b));                 \
        else if (isBIGNUM(b)) return BB((int64_t)qfixnum(a), qint64(b)); \
        else return error1("Bad argument for " name, b);                 \
    }                                                                    \
    else return error1("Bad argument for " name, a)

#define UNARYINTOP(name, a)                                              \
    if (isFIXNUM(a)) return BB((int64_t)qfixnum(a));                     \
    else if (isBIGNUM(a)) return BB(qint64(a));                          \
    else return error1("Bad argument for " name, a)

// This takes an arbitrary 64-bit integer and returns either a fixnum
// or a bignum as necessary.

LispObject makeinteger(int64_t a)
{   if (a >= MIN_FIXNUM && a <= MAX_FIXNUM) return packfixnum(a);
    else return boxint64(a);
}

#undef FF
#undef BB
#define FF(a) boxfloat(-(a))
#define BB(a) makeinteger(-(a))

LispObject Nminus(LispObject a)
{   UNARYOP("minus", a);
}

#undef FF
#undef BB
#define FF(a, b) boxfloat((a) + (b))
#define BB(a, b) makeinteger((a) + (b))

LispObject Nplus2(LispObject a, LispObject b)
{   NUMOP("plus", a, b);
}

#undef FF
#undef BB
#define FF(a, b) boxfloat((a) * (b))
#define BB(a, b) makeinteger((a) * (b))

LispObject Ntimes2(LispObject a, LispObject b)
{   NUMOP("times", a, b);
}

#undef BB
#define BB(a, b) makeinteger((a) & (b))

LispObject Nlogand2(LispObject a, LispObject b)
{   INTOP("logand", a, b);
}

#undef BB
#define BB(a, b) makeinteger((a) | (b))

LispObject Nlogor2(LispObject a, LispObject b)
{   INTOP("logor", a, b);
}

#undef BB
#define BB(a, b) makeinteger((a) ^ (b))

LispObject Nlogxor2(LispObject a, LispObject b)
{   INTOP("logxor", a, b);
}

#undef FF
#undef BB

#define BOFFO_SIZE 4096
char boffo[BOFFO_SIZE+4];
int boffop;

#define swap(a,b) w = (a); (a) = (b); (b) = w;

static INLINE LispObject copy(LispObject x);

int gccount = 1;

#define allocate_memory(n) malloc(n)

void disaster(int line)
{   printf("\nInternal inconsistency detected on line %d\n", line);
    printf("Unable to continue. Apologies.\n");
    abort();
}

void reclaim()
{
// The strategy here is due to C J Cheyney ("A Nonrecursive List Compacting
// Algorithm". Communications of the ACM 13 (11): 677-678, 1970).
    LispObject *s, w;
    printf("+++ GC number %d", gccount++);
// I need to clear the part of the bitmap that could be relevant for floating
// point values.
    int o = (fpfringe1 - heap1base)/(8*8);
    while (o < BITMAPSIZE) ((unsigned char *)bitmap)[o++] = 0;
// Process everything that is on the stack.
    for (s=(LispObject *)stackbase; s<sp; s++) *s = copy(*s);
// I should also copy any other list base values here.
    for (o=0; o<BASES_SIZE; o++) bases[o] = copy(bases[o]);
    for (o=0; o<OBHASH_SIZE; o++)
        obhash[o] = copy(obhash[o]);
// Now perform the second part of Cheyney's algorithm, scanning the
// data that has been put in the new heap.
    s = (LispObject *)heap2base;
    while ((LispObject)s != fringe2)
    {   LispObject h = *s;
        if (!isHDR(h)) // The item to be processed is a simple cons cell
        {   *s++ = copy(h);
            *s = copy(*s);
            s++;
        }
        else              // The item is one that uses a header
            switch (h & TYPEBITS)
            {   case typeSYM:
                case typeGENSYM:
                    w = ((LispObject)s) + tagSYMBOL;
                    // qflags(w) does not need adjusting
                    qvalue(w) = copy(qvalue(w));
                    qplist(w) = copy(qplist(w));
                    qpname(w) = copy(qpname(w));
                    // qdefn(w) does not need adjusting
                    qlits(w)  = copy(qlits(w));
                    s += 6;
                    continue;
                case typeSTRING:
                case typeBIGNUM:
// These only contain binary information, so none of their content needs
// any more processing.
                    w = (sizeof(LispObject) + veclength(h) + 7) & ~7;
                    s += w/sizeof(LispObject);
                    continue;
                case typeVEC:
                case typeEQHASH:
                case typeEQHASHX:
                case typeEQUALHASH:
                case typeEQUALHASHX:
// These are to be processed the same way. They contain a bunch of
// reference items.
                    s++; // Past the header
                    w = veclength(h);
                    while (w > 0)
                    {   *s = copy(*s);
                        s++;
                        w -= sizeof(LispObject);
                    }
                    w = (LispObject)s;
                    w = (w + 7) & ~7;
                    s = (LispObject *)w;
                    continue;
                default:
                    // all the "spare" codes!
                    disaster(__LINE__);
            }
    }
// Finally flip the two heaps ready for next time.
    swap(heap1base, heap2base);
    swap(heap1top, heap2top);
    fringe1 = fringe2;
    fpfringe1 = fpfringe2;
    fringe2 = heap2base;
    fpfringe2 = heap2top;
    printf(" - collection complete (%" PRIu64 " Kbytes free)\n",
        ((uint64_t)(fpfringe1-fringe1))/1024);
    if (fpfringe1 - fringe1 < 1000*sizeof(LispObject))
    {   printf("\nRun out of memory.\n");
        exit(1);
    }
    fflush(stdout);
}

LispObject copy(LispObject x)
{   LispObject h;
    int o, b;
    switch (x & TAGBITS)
    {   case tagCONS:
            if (x == 0) disaster(__LINE__);
            h = *((LispObject *)x);
            if (isFORWARD(h)) return (h - tagFORWARD);
            qcar(fringe2) = h;
            qcdr(fringe2) = qcdr(x);
            h = fringe2;
            qcar(x) = tagFORWARD + h;
            fringe2 += 2*sizeof(LispObject);
            return h;
        case tagSYMBOL:
            h = *((LispObject *)(x - tagSYMBOL));
            if (isFORWARD(h)) return (h - tagFORWARD + tagSYMBOL);
            if (!isHDR(h)) disaster(__LINE__);
            h = fringe2 + tagSYMBOL;
            qflags(h) = qflags(x);
            qvalue(h) = qvalue(x);
            qplist(h) = qplist(x);
            qpname(h) = qpname(x);
            qdefn(h)  = qdefn(x);
            qlits(h)  = qlits(x);
            fringe2 += 6*sizeof(LispObject);
            qflags(x) = h - tagSYMBOL + tagFORWARD;
            return h;
        case tagATOM:
            if (x == NULLATOM) return x; // special case!
            h = qheader(x);
            if (isFORWARD(h)) return (h - tagFORWARD + tagATOM);
            if (!isHDR(h)) disaster(__LINE__);
            switch (h & TYPEBITS)
            {   case typeEQHASH:
                case typeEQUALHASH:
// When a hash table is copied its header is changes to EQHASHX, which
// indicates that it will need rehashing before further use.
                    qheader(x) ^= (typeEQHASH ^ typeEQHASHX);
                case typeEQHASHX:
                case typeEQUALHASHX:
                case typeSTRING:
                case typeVEC:
                case typeBIGNUM:
                    o = (int)veclength(h);  // number of bytes excluding the header
                    *((LispObject *)fringe2) = h; // copy header word across
                    h = fringe2 + tagATOM;
                    *((LispObject *)(x - tagATOM)) = fringe2 + tagFORWARD;
                    fringe2 += sizeof(LispObject);
                    x = x - tagATOM + sizeof(LispObject);
                    while (o > 0)
                    {   *((LispObject *)fringe2) = *((LispObject *)x);
                        fringe2 += sizeof(LispObject);
                        x += sizeof(LispObject);
                        o -= sizeof(LispObject);
                    }
                    fringe2 = (fringe2 + 7) & ~7;
                    return h;
                default:
                    //case typeSYM: case typeGENSYM:
                    // also the spare codes!
                    disaster(__LINE__);
            }
        case tagFLOAT:
// every float is 8 bytes wide, regardless of what sort of machine I am on.
            h = (x - tagFLOAT - heap1base)/8;
            o = h/8;
            b = 1 << (h%8);
// now o is an offset and b a bit in the bitmap.
            if ((((unsigned char *)bitmap)[o] & b) != 0) // marked already.
                return *((LispObject *)(x-tagFLOAT));
            else
            {   ((unsigned char *)bitmap)[o] |= b; // mark it now.
                fpfringe2 -= sizeof(double);
                h = fpfringe2 + tagFLOAT;
                qfloat(h) = qfloat(x);             // copy the float.
                *((LispObject *)(x-tagFLOAT)) = h; // write in forwarding address.
                return h;
            }
        case tagFIXNUM:
            return x;
        default:
//case tagFORWARD:
//case tagHDR:
            disaster(__LINE__);
            return 0;  // avoid GCC moans.
    }
}

#define printPLAIN   1
#define printESCAPES 2
#define printHEX     4

// I suspect that linelength and linepos need to be maintained
// independently for each output stream. At present that is not
// done.
int linelength = 80, linepos = 0, printflags = printESCAPES;

#define MAX_LISPFILES 30
#ifdef DEBUG
FILE *lispfiles[MAX_LISPFILES], *logfile = NULL;
#else // DEBUG
FILE *lispfiles[MAX_LISPFILES];
#endif // DEBUG
int curchars[MAX_LISPFILES+1];
int symtypes[MAX_LISPFILES+1];
#define curchar curchars[lispin+1]
#define symtype symtypes[lispin+1]
int32_t file_direction = 0, interactive = 0;
int lispin = 0, lispout = 1;

extern LispObject lookup(const char *s, int n, int flags);

void wrch(int c)
{
    if (lispout == -1)
    {   char w[4];
// This bit is for the benefit of explode and explodec.
        LispObject r;
        w[0] = c; w[1] = 0;
        r = lookup(w, 1, 1);
        work1 = cons(r, work1);
    }
    else if (lispout == -2) boffo[boffop++] = c;
    else
    {   putc(c, lispfiles[lispout]);
#ifdef DEBUG
        if (logfile != NULL)
        {   putc(c, logfile);
            if (c == '\n')
            {   fprintf(logfile, "%d]", lispout);
            }
        }
#endif // DEBUG
        if (c == '\n')
        {   linepos = 0;
            fflush(lispfiles[lispout]);
        }
        else linepos++;
    }
}

int my_getc(FILE *f)
{
#ifdef NOLIBEDIT
// This can help while running under a debugger!
    return getc(f);
#else
    if (f != stdin) return getc(f);
    if (elx_count == 0)
    {   elx_line = el_gets(elx_e, &elx_count);
        if (elx_count <= 0) return EOF;
        if (elx_count > 1 || (elx_line[0] != '\n' && elx_line[0] != '\r'))
            history(elx_h, &elx_v, H_ENTER, elx_line);
    }
    elx_count--;
    return *elx_line++;
#endif
}

int rdch()
{   LispObject w;
    if (lispin == -1)
    {   if (!isCONS(work1)) return EOF;
        w = qcar(work1);
        work1 = qcdr(work1);
        if (isSYMBOL(w)) w = qpname(w);
        if (!isSTRING(w)) return EOF;
        return *qstring(w);
    }
    else
    {   int c = my_getc(lispfiles[lispin]);
#ifdef DEBUG
        if (c != EOF /*&& qvalue(echo) != nil*/) wrch(c);
#else // DEBUG
        if (c != EOF && qvalue(echo) != nil) wrch(c);
#endif // DEBUG
        return c;
    }
}

int gensymcounter = 1;

void checkspace(int n)
{   if (linepos + n >= linelength && lispout != -1) wrch('\n');
}

char printbuffer[32];

extern LispObject call1(const char *name, LispObject a1);
extern LispObject call2(const char *name, LispObject a1, LispObject a2);

void internalprint(LispObject x)
{   int sep = '(', i, esc, len;
    char *s;
    LispObject pn;
    i = 0;
    int some = 0;
    switch (x & TAGBITS)
    {   case tagCONS:
            if (x == 0)    // can only occur in case of bugs here.
            {   wrch('#');
                return;
            }
            while (isCONS(x))
            {   i = printflags;
                if (qcar(x) == bignum &&
                    (pn = call1("~big2str", qcdr(x))) != NULLATOM &&
                    pn != nil)
                {   printflags = printPLAIN;
                    internalprint(pn);
                    printflags = i;
                    if (some == 0) return;
                    else break;
                }
                printflags = i;
                checkspace(1);
                if (linepos != 0 || sep != ' ' || lispout < 0) wrch(sep);
                sep = ' ';
                push(x);
                internalprint(qcar(x));
                pop(x);
                some = 1;
                x = qcdr(x);
            }
            if (x != nil)
            {   checkspace(3);
                wrch(' '); wrch('.'); wrch(' ');
                internalprint(x);
            }
            checkspace(1);
            wrch(')');
            return;
        case tagSYMBOL:
            pn = qpname(x);
            if (pn == nil)
            {   int len = sprintf(printbuffer, "g%.3d", gensymcounter++);
                push(x);
                pn = makestring(printbuffer, len);
                pop(x);
                qpname(x) = pn;
            }
            len = veclength(qheader(pn));
            s = qstring(pn);
            if ((printflags & printESCAPES) == 0)
            {   int i;
                checkspace(len);
                for (i=0; i<len; i++) wrch(s[i]);
            }
            else if (len != 0)
            {   esc = 0;
                if (!islower((int)s[0])) esc++;
                for (i=1; i<len; i++)
                {   if (!islower((int)s[i]) &&
                        !isdigit((int)s[i]) &&
                        s[i]!='_') esc++;
                }
                checkspace(len + esc);
                if (!islower((int)s[0])) wrch('!');
                wrch(s[0]);
                for (i=1; i<len; i++)
                {   if (!islower((int)s[i]) &&
                        !isdigit((int)s[i]) &&
                        s[i]!='_')
                        wrch('!');
                    wrch(s[i]);
                }
            }
            return;
        case tagATOM:
            if (x == NULLATOM)
            {   checkspace(5);
                wrch('#'); wrch('n'); wrch('u'); wrch('l'); wrch('l');
                return;
            }
            else switch (qheader(x) & TYPEBITS)
                {   case typeSTRING:
                        len = veclength(qheader(x));
                        push(x);
#define RAWSTRING       qstring(TOS)
                        if ((printflags & printESCAPES) == 0)
                        {   int i;
                            checkspace(len);
                            for (i=0; i<len; i++) wrch(RAWSTRING[i]);
                        }
                        else
                        {   esc = 2;
                            for (i=0; i<len; i++)
                                if (RAWSTRING[i] == '"') esc++;
                            checkspace(len+esc);
                            wrch('"');
                            for (i=0; i<len; i++)
                            {   if (RAWSTRING[i] == '"') wrch('"');
                                wrch(RAWSTRING[i]);
                            }
                            wrch('"');
                        }
                        pop(x);
#undef RAWSTRING
                        return;
                    case typeBIGNUM:
                        sprintf(printbuffer, "%" PRId64, qint64(x));
                        checkspace(len = strlen(printbuffer));
                        for (i=0; i<len; i++) wrch(printbuffer[i]);
                        return;
                    case typeVEC:
                        i++;
                    case typeEQUALHASH:
                        i++;
                    case typeEQUALHASHX:
                        i++;
                    case typeEQHASH:
                        i++;
                    case typeEQHASHX:
                        switch (i)
                        {
// EQ hash table                     #h
// EQUALhash table                   #H
// ditto but in need of rehashing    #g or 'G
                        case 0:
                            wrch('#'); wrch('g');
                            break;
                        case 1:
                            wrch('#'); wrch('h');
                            break;
                        case 2:
                            wrch('#'); wrch('G');
                            break;
                        case 3:
                            wrch('#'); wrch('H');
                            break;
                        case 4:
                            break;
                        }
                        sep = '[';
                        push(x);
                        for (i=0; i<veclength(qheader(TOS))/sizeof(LispObject); i++)
                        {   checkspace(1);
                            wrch(sep);
                            sep = ' ';
                            internalprint(elt(TOS, i));
                        }
                        pop(x);
                        checkspace(1);
                        wrch(']');
                        return;
                    default:
                        //case typeSYM:
                        // also the spare codes!
                        assert(0);
                }
        case tagFLOAT:
            {   double d =  *((double *)(x - tagFLOAT));
                if (isnan(d)) strcpy(printbuffer, "NaN");
                else if (isfinite(d)) sprintf(printbuffer, "%.14g", d);
                else strcpy(printbuffer, "inf");
            }
            s = printbuffer;
// The C printing of floating point values is not to my taste, so I (slightly)
// asjust the output here...
            if (*s == '+' || *s == '-') s++;
            while (isdigit((int)*s)) s++;
            if (*s == 0 || *s == 'e')  // No decimal point present!
            {   len = strlen(s);
                while (len >= 0)       // Move existing text up 2 places
                {   s[len+2] = s[len];
                    len--;
                }
                s[0] = '.'; s[1] = '0'; // insert ".0"
            }
            checkspace(len = strlen(printbuffer));
            for (i=0; i<len; i++) wrch(printbuffer[i]);
            return;
        case tagFIXNUM:
            sprintf(printbuffer, "%" PRId64, (int64_t)qfixnum(x));
            checkspace(len = strlen(printbuffer));
            for (i=0; i<len; i++) wrch(printbuffer[i]);
            return;
        default:
//case tagFORWARD:
//case tagHDR:
//          sprintf(printbuffer, "??%#" PRIxPTR "??\n", x);
//          checkspace(len = strlen(printbuffer));
//          for (i=0; i<len; i++) wrch(printbuffer[i]);
            assert(0);
    }
}

LispObject prin(LispObject a)
{   printflags = printESCAPES;
    push(a);
    internalprint(a);
    pop(a);
    return a;
}

LispObject princ(LispObject a)
{   printflags = printPLAIN;
    push(a);
    internalprint(a);
    pop(a);
    return a;
}

LispObject prinhex(LispObject a)
{   printflags = printESCAPES | printHEX;
    push(a);
    internalprint(a);
    pop(a);
    return a;
}

LispObject print(LispObject a)
{   printflags = printESCAPES;
    push(a);
    internalprint(a);
    pop(a);
    wrch('\n');
    return a;
}

void errprint(LispObject a)
{   int saveout = lispout, saveflags = printflags;
    lispout = 1; printflags = printESCAPES;
    push(a);
    internalprint(a);
    pop(a);
    wrch('\n');
    lispout = saveout; printflags = saveflags;
}

void errprin(LispObject a)
{   int saveout = lispout, saveflags = printflags;
    lispout = 1; printflags = printESCAPES;
    push(a);
    internalprint(a);
    pop(a);
    lispout = saveout; printflags = saveflags;
}

LispObject printc(LispObject a)
{   printflags = printPLAIN;
    push(a);
    internalprint(a);
    pop(a);
    wrch('\n');
    return a;
}


int hexval(int n)
{   if (isdigit(n)) return n - '0';
    else if ('a' <= n && n <= 'f') return n - 'a' + 10;
    else if ('A' <= n && n <= 'F') return n - 'A' + 10;
    else return 0;
}

LispObject token()
{   symtype = 'a';           // Default result is an atom.
    while (1)
    {   while (curchar == ' ' ||
               curchar == '\t' ||
               curchar == '\n') curchar = rdch(); // Skip whitespace
// Discard comments from "%" to end of line.
        if (curchar == '%')
        {   while (curchar != '\n' &&
                   curchar != EOF) curchar = rdch();
            continue;
        }
        break;
    }
    if (curchar == EOF)
    {   symtype = curchar;
        return NULLATOM;     // End of file marker.
    }
    if (curchar == '(' || curchar == '.' ||
        curchar == ')' || curchar == '\'' ||
        curchar == '`' || curchar == ',')
    {   symtype = curchar;   // Lisp special characters.
        curchar = rdch();
        if (symtype == ',' && curchar == '@')
        {   symtype = '@';
            curchar = rdch();
        }
        return NULLATOM;
    }
    boffop = 0;
    if (isalpha(curchar) || curchar == '!') // Start a symbol.
    {   while (isalpha(curchar) ||
               isdigit(curchar) ||
               curchar == '_' ||
               curchar == '!')
        {   if (curchar == '!') curchar = rdch();
            else if (curchar != EOF && qvalue(lower) != nil) curchar = tolower(curchar);
            else if (curchar != EOF && qvalue(raise) != nil) curchar = toupper(curchar);
            if (curchar != EOF)
            {   if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
                curchar = rdch();
            }
        }
        boffo[boffop] = 0;
        return lookup(boffo, boffop, 1);
    }
    if (curchar == '"')                     // Start a string
    {   curchar = rdch();
        while (1)
        {   while (curchar != '"' && curchar != EOF)
            {   if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
                curchar = rdch();
            }
// Note that a double-quote can be repeated within a string to denote
// a string with that character within it. As in
//   "abc""def"   is a string with contents   abc"def.
            if (curchar != EOF) curchar = rdch();
            if (curchar != '"') break;
            if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
            curchar = rdch();
        }
        return makestring(boffo, boffop);
    }
    if (curchar == '+' || curchar == '-')
    {   boffo[boffop++] = curchar;
        curchar = rdch();
// + and - are treated specially, since if followed by a digit they
// introduce a (signed) number, but otherwise they are treated as punctuation.
        if (!isdigit(curchar))
        {   boffo[boffop] = 0;
            return lookup(boffo, boffop, 1);
        }
    }
// Note that in some cases after a + or - I drop through to here.
    if (curchar == '0' && boffop == 0)  // "0" without a sign in front
    {   boffo[boffop++] = curchar;
        curchar = rdch();
        if (curchar == 'x' || curchar == 'X') // Ahah - hexadecimal input
        {   LispObject r;
            boffop = 0;
            curchar = rdch();
            while (isxdigit(curchar))
            {   if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
                curchar = rdch();
            }
            r = packfixnum(0);
            boffop = 0;
            while (boffo[boffop] != 0)
            {   r = call2("plus2", call2("times2", packfixnum(16), r),
                           packfixnum(hexval(boffo[boffop++])));
            }
            return r;
        }
    }
    if (isdigit(curchar) || (boffop == 1 && boffo[0] == '0'))
    {   while (isdigit(curchar))
        {   if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
            curchar = rdch();
        }
// At this point I have a (possibly signed) integer. If it is immediately
// followed by a "." then a floating point value is indicated.
        if (curchar == '.')
        {   symtype = 'f';
            if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
            curchar = rdch();
            while (isdigit(curchar))
            {   if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
                curchar = rdch();
            }
// To make things tidy If I have a "." not followed by any digits I will
// insert a "0".
            if (!isdigit((int)boffo[boffop-1])) boffo[boffop++] = '0';
        }
// Whether or not there was a ".", an "e" or "E" introduces an exponent and
// hence indicates a floating point value.
        if (curchar == 'e' || curchar == 'E')
        {   symtype = 'f';
            if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
            curchar = rdch();
            if (curchar == '+' || curchar == '-')
            {   if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
                curchar = rdch();
            }
            while (isdigit(curchar))
            {   if (boffop < BOFFO_SIZE) boffo[boffop++] = curchar;
                curchar = rdch();
            }
// If there had been an "e" I force at least one digit in following it.
            if (!isdigit((int)boffo[boffop-1])) boffo[boffop++] = '0';
        }
        boffo[boffop] = 0;
        if (symtype == 'a')
        {   int neg = 0;
            LispObject r = packfixnum(0);
            boffop = 0;
            if (boffo[boffop] == '+') boffop++;
            else if (boffo[boffop] == '-') neg=1, boffop++;
            while (boffo[boffop] != 0)
            {   r = call2("plus2", call2("times2", packfixnum(10), r),
                           packfixnum(boffo[boffop++] - '0'));
            }
            if (neg) r = call1("minus", r);
            return r;
        }
        else
        {   double d;
            sscanf(boffo, "%lg", &d);
            return boxfloat(d);
        }
    }
    boffo[boffop++] = curchar;
    curchar = rdch();
    boffo[boffop] = 0;
    symtype = 'a';
    return lookup(boffo, boffop, 1);
}

extern LispObject Lget(LispObject lits, int nargs, ...);

LispObject char_function(LispObject a)
{   if (!isSYMBOL(a)) return nil;
    LispObject pn = qpname(a);
    char *s = qstring(pn);
    if (strlen(s) == 1) return packfixnum(s[0]);
    return Lget(nil, 2, a, charvalue);
}

//   S ::= name
//     |   integer
//     |   radix#based-integer
//     |   float
//     |   string
//     |   ' S   | ` S  | , S  | ,@ S | ,. S
//     |   #/ char      integer code for char
//     |   #\ char      integer code is char is single character,
//                      otherwise NULL, BELL, BACKSPACE, TAB, LF, EOL,
//                      FF, CR, EOF, ESC, ESCAPE, SPACE, RUBOUT, RUB,
//                      DELETE, DEL, (lower x), (control x), (ctrl x),
//                      (meta x). *raise can case-fold x unless ! is used.
//     |   #' S
//     |   #. S
//     |   #+ S S
//     |   #- S S
//     |   ( T
//     |   [ V
//     ;
//
//   T ::= )
//     |   . S )
//     |   S T
//     ;
//
//   V ::= ]
//     |   S V
//     ;

extern LispObject readS();
extern LispObject readT();
extern LispObject readV();
extern LispObject eval(LispObject x);

LispObject read_hash_macro()
{   LispObject w;
    int c = curchar;
    curchar = rdch();
    switch (c)
    {   case '\'':         // #'X  => (function X)
            cursym = token();
            w = readS();
            return list2star(function, w, nil);
        case '.':
            cursym = token();
            w = readS();
            return eval(w);
        case '+':
            cursym = token();
            w = readS();
// For now I will suppose that the machine in use is NEVER one of the
// ones tested fpr. The consequence is that "#+ machine S" always gets
// ignored.
            (void)readS();
            return readS();
        case '-':
            cursym = token();
            w = readS();
// To match the behaviour of #+ I just make "#- machine" get ignored so that
// the S-expression beyond that is the one that is read.
            return readS();
        case '/':
            c = curchar;
            curchar = rdch();
            cursym = token();
            return packfixnum(c & 0xff);
        case '\\':
            cursym = token();
            w = readS();
            return char_function(w);
        default:
            return nil;
    }
}

LispObject list_to_vector(LispObject a)
{   int n = 0;
    for (LispObject p=a; p!=nil; p=qcdr(p)) n++;
    LispObject r = makevector(n-1);
    n = 0;
    for (LispObject p=a; p!=nil; p=qcdr(p)) elt(r, n++) = qcar(p);
    return r;
}

LispObject readS()
{   LispObject q, w;
    while (1)
    {   switch (symtype)
        {   case '?':
                cursym = token();
                continue;
            case '(':
                cursym = token();
                return readT();
            case '[':
                cursym = token();
                return list_to_vector(readV());
            case '#':
                return read_hash_macro();
            case '.':
            case ')':     // Ignore spurious ")" input
                cursym = token();
                continue;
            case '\'':
                w = quote;
                break;
            case '`':
                w = backquote;
                break;
            case ',':
                w = comma;
                break;
            case '@':
                w = comma_at;
                break;
            case '.'+0x100:
                w = comma_dot;
                break;
            case EOF:
                return eofsym;
            default:
                symtype = '?';
                return cursym;
        }
        push(w);
        cursym = token();
        q = readS();
        pop(w);
        return list2star(w, q, nil);
    }
}

LispObject readT()
{   LispObject q, r;
    if (symtype == '?') cursym = token();
    switch (symtype)
    {   case EOF:
            return eofsym;
        case '.':
            cursym = token();
            q = readS();
            if (symtype == '?') cursym = token();
            if (symtype == ')') symtype = '?'; // Ignore if not ")".
            return q;
        case ')':
            symtype = '?';
            return nil;
        // case '(':  case '\'':
        // case '`':  case ',':
        // case '@':
        default:
            q = readS();
            push(q);
            r = readT();
            pop(q);
            return cons(q, r);
    }
}

LispObject readV()
{   LispObject q, r;
    if (symtype == '?') cursym = token();
    switch (symtype)
    {   case EOF:
            return eofsym;
        case ']':
            symtype = '?';
            return nil;
        default:
            q = readS();
            push(q);
            r = readV();
            pop(q);
            return cons(q, r);
    }
}

// createp = -1 for remob
//         = 0 for lookup if exists, but do not create
//         = 1 for create symbol if necessary.

LispObject lookup(const char *s, int len, int createp)
{   LispObject w, pn;
    int i, hash = 1;
    for (i=0; i<len; i++) hash = 13*hash + s[i];
    hash = (hash & 0x7fffffff) % OBHASH_SIZE;
    LispObject *prev = &obhash[hash];
    w = *prev;
    while (w != tagFIXNUM)
    {   LispObject a = qcar(w);        // Will be a symbol.
        LispObject n = qpname(a);      // Will be a string.
        int l = veclength(qheader(n)); // Length of the name.
        if (l == len &&
            strncmp(s, qstring(n), len) == 0)
        {   if (createp == -1) *prev = qcdr(w);
            return a;                  // Existing symbol found.
        }
        prev = &qcdr(w);
        w = *prev;
    }
// here the symbol as required was not already present.
    if (createp <= 0) return undefined;
    pn = makestring(s, len);
    push(pn);
    w = allocatesymbol();
    pop(pn);
    qflags(w) = tagHDR + typeSYM;
    qvalue(w) = undefined;
    qplist(w) = nil;
    qpname(w) = pn;
    qdefn(w)  = NULL;
    qlits(w)  = nil;
    push(w);
    obhash[hash] = cons(w, obhash[hash]);
    pop(w);
    return w;
}

#define unwindNONE      0
#define unwindERROR     1
#define unwindBACKTRACE 2
#define unwindGO        4
#define unwindRETURN    8
#define unwindPRESERVE  16
#define unwindRESTART   32

int unwindflag = unwindNONE;

int backtraceflag = -1;
#define backtraceHEADER 1
#define backtraceTRACE  2
int forcedMIN=0, forcedMAX=3;

LispObject error1(const char *msg, LispObject data)
{   if ((backtraceflag & backtraceHEADER) != 0 || forcedMIN > 0)
    {   linepos = printf("\n+++ Error: %s: ", msg);
#ifdef DEBUG
        if (logfile != NULL) fprintf(logfile, "\n+++ Error: %s: ", msg);
#endif // DEBUG
        errprint(data);
    }
    unwindflag = (backtraceflag & backtraceTRACE) != 0 ||
                  forcedMIN > 1 ? unwindBACKTRACE :
                 unwindERROR;
    return nil;
}

LispObject error2(const char *msg, LispObject data1, LispObject data2)
{   if ((backtraceflag & backtraceHEADER) != 0 || forcedMIN > 0)
    {   linepos = printf("\n+++ Error: %s: ", msg);
#ifdef DEBUG
        if (logfile != NULL) fprintf(logfile, "\n+++ Error: %s: ", msg);
#endif // DEBUG
        errprint(data1);
        linepos += printf("  ");
        errprint(data2);
    }
    unwindflag = (backtraceflag & backtraceTRACE) != 0 ||
                 forcedMIN > 1 ? unwindBACKTRACE : unwindERROR;
    return nil;
}

LispObject error1s(const char *msg, const char *data)
{   if ((backtraceflag & backtraceHEADER) != 0 || forcedMIN > 0)
#ifdef DEBUG
    {   printf("\n+++ Error: %s %s\n", msg, data);
        if (logfile != NULL) fprintf(logfile, "\n+++ Error: %s %s\n", msg, data);
    }
#else // DEBUG
        printf("\n+++ Error: %s %s\n", msg, data);
#endif // DEBUG
    unwindflag = (backtraceflag & backtraceTRACE) != 0 ||
                  forcedMIN > 1 ? unwindBACKTRACE : unwindERROR;
    return nil;
}

LispObject applytostack(int n)
{
// Apply a function to n arguments.
// Here the stack has first the function, and then n arguments. The code is
// grim and basically repetitive, and to avoid it being even worse I will
// expect that almost all Lisp functions have at most 4 arguments, so
// if there are more than that I will pass the fifth and beyond all in a list.
    LispObject f, w;
    int traced = (qflags(sp[-n-1]) & flagTRACED) != 0;
    if (traced)
    {   int i;
        linepos = printf("Calling: ");
#ifdef DEBUG
        if (logfile != NULL) fprintf(logfile, "Calling: ");
#endif // DEBUG
        errprint(sp[-n-1]);
        for (i=1; i<=n; i++)
        {   linepos = printf("Arg%d: ", i);
#ifdef DEBUG
            if (logfile != NULL) fprintf(logfile, "Arg%d: ", i);
#endif // DEBUG
            errprint(sp[i-n-1]);
        }
    }
    if (n >= 5)
    {   push(nil);
        n++;
        while (n > 5)
        {   pop(w);
            TOS = cons(TOS, w);
            n--;
        }
    }
    switch (n)
    {   case 0:
            f = TOS;
            w = (*(LispFn *)qdefn(f))(qlits(f), 0);
            break;
        case 1:
        {   LispObject a1;
            pop(a1);
            f = TOS;
            w = (*(LispFn *)qdefn(f))(qlits(f), 1, a1);
            break;
        }
        case 2:
        {   LispObject a1, a2;
            pop(a2)
            pop(a1);
            f = TOS;
            w = (*(LispFn *)qdefn(f))(qlits(f), 2, a1, a2);
            break;
        }
        case 3:
        {   LispObject a1, a2, a3;
            pop(a3);
            pop(a2)
            pop(a1);
            f = TOS;
            w = (*(LispFn *)qdefn(f))(qlits(f), 3, a1, a2, a3);
            break;
        }
        case 4:
        {   LispObject a1, a2, a3, a4;
            pop(a4);
            pop(a3);
            pop(a2)
            pop(a1);
            f = TOS;
            w = (*(LispFn *)qdefn(f))(qlits(f), 4,
                                      a1, a2, a3, a4);
            break;
        }
        case 5:
        {   LispObject a1, a2, a3, a4, a5andup;
            pop(a5andup);
            pop(a4);
            pop(a3);
            pop(a2)
            pop(a1);
            f = TOS;
            w = (*(LispFn *)qdefn(f))(qlits(f), 5,
                                      a1, a2, a3, a4, a5andup);
            break;
        }
        default:
            assert(0);
            return nil;
    }
    pop(f);
    if (unwindflag == unwindBACKTRACE)
    {   linepos = printf("Calling: ");
#ifdef DEBUG
        if (logfile != NULL) fprintf(logfile, "Calling: ");
#endif // DEBUG
        errprint(f);
    }
    else if (traced)
    {   push(w);
        prin(f);
        linepos += printf(" = ");
#ifdef DEBUG
        if (logfile != NULL) fprintf(logfile, " = ");
#endif // DEBUG
        errprint(w);
        pop(w);
    }
    return w;
}

LispObject call1(const char *name, LispObject a1)
{
    LispObject fn = lookup(name, strlen(name), 0);
    if (fn == undefined || qdefn(fn) == NULL) return NULLATOM;
    push2(fn, a1);
    return applytostack(1);
}

LispObject call2(const char *name, LispObject a1, LispObject a2)
{
    LispObject fn = lookup(name, strlen(name), 0);
    if (fn == undefined || qdefn(fn) == NULL) return NULLATOM;
    push3(fn, a1, a2);
    return applytostack(2);
}

LispObject interpret(LispObject def, int nargs, ...);
LispObject Lgensym(LispObject lits, int nargs, ...);

LispObject eval(LispObject x)
{   while (isCONS(x) && isSYMBOL(qcar(x)) && (qflags(qcar(x)) & flagMACRO))
    {   push2(qcar(x), x);
        x = applytostack(1);  // Macroexpand before anything else.
        if (unwindflag != unwindNONE) return nil;
    }
    if (isSYMBOL(x))
    {   LispObject v = qvalue(x);
        if (v == undefined) return error1("undefined variable", x);
        else return v;
    }
    else if (!isCONS(x)) return x;
// Now I have something of the form
//     (f arg1 ... argn)
// to process.
    {   LispObject f = qcar(x);
        if (isSYMBOL(f))
        {   LispObject flags = qflags(f), aa, av;
            int i, n = 0;
            if (flags & flagSPECFORM)
            {   SpecialForm *fn = (SpecialForm *)qdefn(f);
                return (*fn)(qlits(f), qcdr(x));
            }
// ... else not a special form...
            if (qdefn(f) == NULL) return error1("undefined function", f);
            aa = qcdr(x);
            while (isCONS(aa))
            {   n++;             // Count number of args supplied.
                aa = qcdr(aa);
            }
            aa = qcdr(x);
            push(f);
// Here I will evaluate all the arguments for the function, leaving the
// evaluated results on the stack.
            for (i=0; i<n; i++)
            {   push(aa);
                av = eval(qcar(aa));
                if (unwindflag != unwindNONE)
                {   while (i != 0)  // Restore the stack if unwinding.
                    {   pop(aa);
                        i--;
                    }
                    pop2(aa, aa);
                    return nil;
                }
                aa = qcdr(TOS);
                TOS = av;
            }
            return applytostack(n);
        }
        else if (isCONS(f) && qcar(f) == lambda)
        {   LispObject w;
            push(x);
            w = Lgensym(nil, 0);
            pop(x);
            qdefn(w) = (void *)interpret;
            qlits(w) = qcdr(qcar(x));
            return eval(cons(w, qcdr(x)));
        }
        else return error1("invalid function", f);
    }
}

LispObject Lprogn(LispObject lits, LispObject x);

// The next array is used to help with error recovery, and it does
// not need to be protected by the garbage collector.
#define MAX_ARGS 50
LispObject pushedvars[MAX_ARGS];

LispObject nreverse(LispObject a)
{   LispObject b = nil, w;
    while (isCONS(a))
    {   w = qcdr(a);
        qcdr(a) = b;
        b = a;
        a = w;
    }
    return b;
}

LispObject interpret(LispObject def, int nargs, ...)
{
// def should be ((a1 a2 ...) e1 e2 ...)
// where the number of args a1 ... should the same as nargs. Use
// "shallow binding" to cope with the need for a1 ... to have some
// sort of local scope.
    va_list aa;
    int i, npushed;
    LispObject arglist, body, w, r = nil;
    if (!isCONS(def)) return error1("bad definition", def);
    va_start(aa, nargs);
    w = arglist = qcar(def);
    body = qcdr(def);
    npushed = 0;
    for (i=0; i<nargs && i<4; i++)
    {   LispObject var;
        if (!isCONS(w) || !isSYMBOL(var = qcar(w)))
        {   while (npushed != 0) pop(qvalue(pushedvars[--npushed]));
            va_end(aa);
            return error1("excess arguments or invalid variable-name", w);
        }
        push(qvalue(var));
        pushedvars[npushed++] = var;
        qvalue(var) = va_arg(aa, LispObject);
        w = qcdr(w);
    }
// To make life easier in "eval" where I call functions I will pass up to
// 4 arguments "naturally", but any beyond that will all be collected as
// a list. So if nargs==5 then arg5 actually represents a list of the form
// (arg5 arg6 ...).
    if (nargs == 5)
    {   r = va_arg(aa, LispObject);
        while (isCONS(w) && isCONS(r))
        {   LispObject var = qcar(w);
            if (!isSYMBOL(var))
            {   while (npushed != 0) pop(qvalue(pushedvars[--npushed]));
                va_end(aa);
                return error1("invalid variable-name", var);
            }
            push(qvalue(var));
            pushedvars[npushed++] = var;
            qvalue(var) = qcar(r);
            w = qcdr(w);
            r = qcdr(r);
        }
    }
    va_end(aa);
    if (isCONS(w) || isCONS(r))
    {   while (npushed != 0) pop(qvalue(pushedvars[--npushed]));
        return error2("wrong number of args", r, w);
    }
    push(arglist);
    r = Lprogn(nil, body);
    pop(arglist);
// Now I must restore the bound variables (regardless of whether there
// has been an error).
    w = nreverse(arglist);
    arglist = nil;
    while (isCONS(w))
    {   LispObject x = w;
        w = qcdr(w);
        qcdr(x) = arglist;
        arglist = x;
        pop(qvalue(qcar(arglist)));
    }
    return r;
}

LispObject interpretspecform(LispObject lits, LispObject x)
{   // lits should be ((var) body...)
    LispObject v, v_value;
    if (!isCONS(lits)) return nil;
    v = qcar(lits);
    lits = qcdr(lits);
    if (!isCONS(v) || !isSYMBOL(v = qcar(v))) return nil;
    v_value = qvalue(v);
    qvalue(v) = x;
    push2(v, v_value);
    lits = Lprogn(nil, lits);
    pop2(v_value, v);
    qvalue(v) = v_value;
    return lits;
}

// Special forms are things that do not have their arguments pre-evaluated.

LispObject Lquote(LispObject lits, LispObject x)
{   if (isCONS(x)) return qcar(x);
    else return nil;
}

LispObject Lcond(LispObject lits, LispObject x)
{
//   Arg is in form
//      ((predicate1 val1a val1b ...)
//       (predicate2 val2a val2b ...)
//       ...)
    while (isCONS(x))
    {   push(x);
        x = qcar(x);
        if (isCONS(x))
        {   LispObject p = eval(qcar(x));
            if (unwindflag != unwindNONE)
            {   pop(x);
                return nil;
            }
            else if (p != nil)
            {   pop(x);
                return Lprogn(nil, qcdr(qcar(x)));
            }
        }
        pop(x);
        x = qcdr(x);
    }
    return nil;
}

LispObject Land(LispObject lits, LispObject x)
{   LispObject r = lisptrue;
    while (isCONS(x))
    {   push(x);
        r = eval(qcar(x));
        pop(x);
        if (r == nil || unwindflag != unwindNONE) return nil;
        x = qcdr(x);
    }
    return r;
}

LispObject Lor(LispObject lits, LispObject x)
{   while (isCONS(x))
    {   LispObject r;
        push(x);
        r = eval(qcar(x));
        pop(x);
        if (r != nil || unwindflag != unwindNONE) return r;
        x = qcdr(x);
    }
    return nil;
}

// A list of lambda-variables should be a properly nil-terminated list
// of symbols, not including keywords or anyting declared global.

int allsymbols(LispObject bvl)
{
    while (isCONS(bvl))
    {   if (!isSYMBOL(qcar(bvl)) ||
            (qflags(qcar(bvl)) & flagGLOBAL) != 0) return 0;
        bvl = qcdr(bvl);
    }
    return (bvl == nil);
}

LispObject definer(LispObject x, int flags, void *fn)
{
// x should be of the form
//     (name (arg list ...) body)
//
// I check for a LOSE flag to give me a way of
// ignoring definitions that I do not like.
    LispObject name, def;
    if (!isCONS(x) ||
        !isSYMBOL(name = qcar(x)) ||
        !isCONS(def = qcdr(x)))
        return error1("malformed use of de, df or dm", x);
// For the moment I prohibit redefinition of special forms...
    if ((qflags(name) & flagSPECFORM) != 0)
        return error1("attempt to redefine special form", name);
    if (Lget(nil, 2, name, loseflag) != nil)
    {   printf("\n+++ LOSE flag on function, so definition ignored: ");
        errprint(name);
        return name;
    }
// Now I will <1>try to call macroexpand_list to expand all macros.
    x = lookup("macroexpand_list", 16, 0);
    if (x != undefined && qdefn(x) != NULL)
    {   push2(name, def);
        push2(x, qcdr(def));
        x = applytostack(1);
        pop2(def, name);
        if (unwindflag != unwindNONE) return name;
        qlits(name) = cons(qcar(def), x);
    }
    else qlits(name) = def;
    qflags(name) = (qflags(name) & ~(flagSPECFORM|flagMACRO)) | flags;
    qdefn(name) = fn;
    return name;
}

LispObject Lde(LispObject lits, LispObject x)
{   return definer(x, 0, (void *)interpret);
}

LispObject Ldf(LispObject lits, LispObject x)
{   return definer(x, flagSPECFORM, (void *)interpretspecform);
}

LispObject Ldm(LispObject lits, LispObject x)
{   return definer(x, flagMACRO, (void *)interpret);
}

LispObject Lsetq(LispObject lits, LispObject x)
{ // (setq var1 val1 var2 val2 ...)
    LispObject w = nil;
    while (isCONS(x) && isCONS(qcdr(x)))
    {   if (!isSYMBOL(w=qcar(x)) ||
            w == nil || w == lisptrue)
            return error1("bad variable in setq", x);
        push(x);
        w = eval(qcar(qcdr(x)));
        pop(x);
        if (unwindflag != unwindNONE) return nil;
        qvalue(qcar(x)) = w;
        x = qcdr(qcdr(x));
    }
    return w;
}

LispObject Lprogn(LispObject lits, LispObject x)
{   LispObject r = nil;
    while (isCONS(x))
    {   push(x);
        r = eval(qcar(x));
        pop(x);
        x = qcdr(x);
        if (unwindflag != unwindNONE) return nil;
    }
    return r;
}

// I want to police a constraint that GO and RETURN are only used in
// "prog context". The following limited number of forms are relevant to
// this:
//    COND
//    PROGN
//    GO
//    RETURN
// and (at least for now) I am not going to allow other conditionals, macros
// or anything else to be transparent to it.

static LispObject eval_prog_context(LispObject x);

LispObject progprogn(LispObject x)
{   LispObject r = nil;
    while (isCONS(x))
    {   push(x);
        r = eval_prog_context(qcar(x));
        pop(x);
        x = qcdr(x);
        if (unwindflag != unwindNONE) return nil;
    }
    return r;
}

LispObject progcond(LispObject x)
{
    while (isCONS(x))
    {   push(x);
        x = qcar(x);
        if (isCONS(x))
        {   LispObject p = eval(qcar(x));
            if (unwindflag != unwindNONE)
            {   pop(x);
                return nil;
            }
            else if (p != nil)
            {   pop(x);
                return progprogn(qcdr(qcar(x)));
            }
        }
        pop(x);
        x = qcdr(x);
    }
    return nil;
}

LispObject proggo(LispObject x)
{   if (!isCONS(x) || !isSYMBOL(work1 = qcar(x)))
        return error1("bad go", x);
    work1 = qcar(x);
    unwindflag = unwindGO;
    return nil;
}

LispObject progreturn(LispObject args)
{   if (!isCONS(args) || isCONS(qcdr(args)))
        return error1("RETURN need just 1 argument", args);
    args = eval(qcar(args));
    if (unwindflag != unwindNONE) return nil;
    work1 = args;
    unwindflag = unwindRETURN;
    return nil;
}

static LispObject eval_prog_context(LispObject x)
{   if (!isCONS(x)) return eval(x);
    else if (qcar(x) == condsymbol) return progcond(qcdr(x));
    else if (qcar(x) == prognsymbol) return progprogn(qcdr(x));
    else if (qcar(x) == gosymbol) return proggo(qcdr(x));
    else if (qcar(x) == returnsymbol) return progreturn(qcdr(x));
    else return eval(x);
}

LispObject Lprog(LispObject lits, LispObject x)
{
    LispObject w, vars;
    if (!isCONS(x)) return nil;
    vars = qcar(x);
    x = qcdr(x);
    w = vars;
// Now bind all the local variables, giving them the value nil.
    while (isCONS(w))
    {   LispObject v = qcar(w);
        w = qcdr(w);
        if (isSYMBOL(v))
        {   push(qvalue(v));
            qvalue(v) = nil;
        }
    }
    push(vars);  // So that I know what to unbind at the end.
    push(x);     // So that "go" can scan the whole block to find a label.
    work1 = nil;
    while (isCONS(x))
    {   push(x);
        if (isCONS(qcar(x))) eval_prog_context(qcar(x));
        pop(x);
        x = qcdr(x);
        if (unwindflag == unwindRETURN)
        {   unwindflag = unwindNONE;
            break;
        }
        else if (unwindflag == unwindGO)
        {   unwindflag = unwindNONE;
            x = TOS;
            while (isCONS(x) && qcar(x) != work1) x = qcdr(x);
            continue;
        }
        if (unwindflag != unwindNONE) break;
        work1 = nil;
    }
// Now I must unbind all the variables.
    pop(x);
    pop(vars);
    w = nreverse(vars);
    vars = nil;
    while (isCONS(w))
    {   LispObject x = w;
        w = qcdr(w);
        qcdr(x) = vars;
        vars = x;
        x = qcar(vars);
        if (isSYMBOL(x)) pop(qvalue(x));
    }
    return work1;
}

LispObject Lgo(LispObject lits, LispObject x)
{   return error1("GO not in PROG context", x);
//  if (!isCONS(x) || !isSYMBOL(work1 = qcar(x)))
//      return error1("bad go", x);
//  work1 = qcar(x);
//  unwindflag = unwindGO;
//  return nil;
}

#define NARY(x, base, combinefn)      \
    LispObject r;                     \
    if (!isCONS(x)) return base;      \
    push(x);                          \
    r = eval(qcar(x));                \
    pop(x);                           \
    if (unwindflag != unwindNONE)     \
        return nil;                   \
    x = qcdr(x);                      \
    while (isCONS(x))                 \
    {   LispObject a;                 \
        push2(x, r);                  \
        a = eval(qcar(x));            \
        pop(r);                       \
        if (unwindflag != unwindNONE) \
        {   pop(x);                   \
            return nil;               \
        }                             \
        r = combinefn(r, a);          \
        pop(x);                       \
        x = qcdr(x);                  \
    }                                 \
    return r

LispObject Lplus(LispObject lits, LispObject x)
{   NARY(x, packfixnum(0), Nplus2);
}

LispObject Ltimes(LispObject lits, LispObject x)
{   NARY(x, packfixnum(1), Ntimes2);
}

LispObject Llogand(LispObject lits, LispObject x)
{   NARY(x, packfixnum(-1), Nlogand2);
}

LispObject Llogor(LispObject lits, LispObject x)
{   NARY(x, packfixnum(0), Nlogor2);
}

LispObject Llogxor(LispObject lits, LispObject x)
{   NARY(x, packfixnum(0), Nlogxor2);
}

LispObject Llist(LispObject lits, LispObject x)
{   int n = 0;
    LispObject r;
    while (isCONS(x))
    {   push(x);
        r = eval(qcar(x));
        if (unwindflag != unwindNONE)
        {   while (n != 0)
            {   pop(x);
                n--;
            }
            pop(x);
            return nil;
        }
        x = qcdr(TOS);
        TOS = r;
        n++;
    }
    r = nil;
    while (n > 0)
    {   pop(x);
        r = cons(x, r);
        n--;
    }
    return r;
}

LispObject Lliststar(LispObject lits, LispObject x)
{   int n = 0;
    LispObject r;
    while (isCONS(x))
    {   push(x);
        r = eval(qcar(x));
        if (unwindflag != unwindNONE)
        {   while (n != 0)
            {   pop(x);
                n--;
            }
            pop(x);
            return nil;
        }
        x = qcdr(TOS);
        TOS = r;
        n++;
    }
    if (n == 0) return nil;
    pop(r);
    n--;
    while (n > 0)
    {   pop(x);
        r = cons(x, r);
        n--;
    }
    return r;
}

// The way that arguments are passed to functions is a little
// ugly, and uses the C facility for calling functions with variable
// numbers of arguments. To shorten the code I put much of the mess into
// macros

#define ARG0(name)              \
    if (nargs != 0) return error1s("wrong number of arguments for", name)

#define ARG1(name, x)           \
    va_list a;                  \
    LispObject x;               \
    if (nargs != 1) return error1s("wrong number of arguments for", name); \
    va_start(a, nargs);         \
    x = va_arg(a, LispObject);  \
    va_end(a)

#define ARG2(name, x, y)        \
    va_list a;                  \
    LispObject x, y;            \
    if (nargs != 2) return error1s("wrong number of arguments for", name); \
    va_start(a, nargs);         \
    x = va_arg(a, LispObject);  \
    y = va_arg(a, LispObject);  \
    va_end(a)

#define ARG3(name, x, y, z)     \
    va_list a;                  \
    LispObject x, y, z;         \
    if (nargs != 3) return error1s("wrong number of arguments for", name); \
    va_start(a, nargs);         \
    x = va_arg(a, LispObject);  \
    y = va_arg(a, LispObject);  \
    z = va_arg(a, LispObject);  \
    va_end(a)

#define ARG0123(name, x, y, z)                        \
    va_list a;                                        \
    LispObject x=NULLATOM, y=NULLATOM, z=NULLATOM;    \
    if (nargs > 3) return error1s("wrong number of arguments for", name); \
    va_start(a, nargs);                               \
    if (nargs > 0) x = va_arg(a, LispObject);         \
    if (nargs > 1) y = va_arg(a, LispObject);         \
    if (nargs > 2) z = va_arg(a, LispObject);         \
    va_end(a)

LispObject Lcar(LispObject lits, int nargs, ...)
{   ARG1("car", x);  // Note that this WILL take car of a bignum!
    if (isCONS(x)) return qcar(x);
    else return error1("car of an atom", x);
}

LispObject Lcdr(LispObject lits, int nargs, ...)
{   ARG1("cdr", x);
    if (isCONS(x)) return qcdr(x);
    else return error1("cdr of an atom", x);
}

LispObject Lnth(LispObject lits, int nargs, ...)
{   ARG2("nth", x, n);
    if (!isFIXNUM(n)) return error1("not number in nth", n);
    int i = qfixnum(n);
    while (i > 1)
    {   if (!isCONS(x)) return error1("list too short in nth", n);
        x = qcdr(x);
        i--;
    }
    if (!isCONS(x)) return error1("list too short in nth", n);
    else return qcar(x);
}

LispObject Lpnth(LispObject lits, int nargs, ...)
{   ARG2("pnth", x, n);
    if (!isFIXNUM(n)) return error1("not number in pnth", n);
    int i = qfixnum(n);
    while (i > 1)
    {   if (!isCONS(x)) return error1("list too short in pnth", n);
        x = qcdr(x);
        i--;
    }
    return x;
}

LispObject Lrplaca(LispObject lits, int nargs, ...)
{   ARG2("rplaca", x, y);
    if (isCONS(x))
    {   qcar(x) = y;
        return x;
    }
    else return error1("rplaca on an atom", x);
}

LispObject Lrplacd(LispObject lits, int nargs, ...)
{   ARG2("rplacd", x, y);
    if (isCONS(x))
    {   qcdr(x) = y;
        return x;
    }
    else return error1("rplaca on an atom", x);
}

LispObject Lreclaim(LispObject lits, int nargs, ...)
{   ARG0("reclaim");
    reclaim();
    return nil;
}

LispObject Lcons(LispObject lits, int nargs, ...)
{   ARG2("cons", x, y);
    return cons(x, y);
}

LispObject Latom(LispObject lits, int nargs, ...)
{   ARG1("atom", x); // Observe treatment of bignums!
    return (isCONS(x) && qcar(x) != bignum ? nil : lisptrue);
}

LispObject Lbignump(LispObject lits, int nargs, ...)
{   ARG1("bignump", x);
    return (isCONS(x) && qcar(x) == bignum ? lisptrue : nil);
}

LispObject Lsymbolp(LispObject lits, int nargs, ...)
{   ARG1("symbolp", x);
    return (isSYMBOL(x) ? lisptrue : nil);
}

LispObject Lstringp(LispObject lits, int nargs, ...)
{   ARG1("stringp", x);
    return (isSTRING(x) ? lisptrue : nil);
}

LispObject Lvectorp(LispObject lits, int nargs, ...)
{   ARG1("vectorp", x);
    return (isVEC(x) ? lisptrue : nil);
}

LispObject Lprog1(LispObject lits, int nargs, ...)
{   ARG2("prog1", x, y);
    return x;
}

LispObject Lprog2(LispObject lits, int nargs, ...)
{   ARG2("prog2", x, y);
    return y;
}

LispObject Lnumberp(LispObject lits, int nargs, ...)
{   ARG1("numberp", x);
    return (isFIXNUM(x) || isBIGNUM(x) || isFLOAT(x) ? lisptrue : nil);
}

LispObject Lfixp(LispObject lits, int nargs, ...)
{   ARG1("fixp", x);
    return (isFIXNUM(x) || isBIGNUM(x) ? lisptrue : nil);
}

LispObject Lfloatp(LispObject lits, int nargs, ...)
{   ARG1("floatp", x);
    return (isFLOAT(x) ? lisptrue : nil);
}

LispObject Lfix(LispObject lits, int nargs, ...)
{   ARG1("fix", x);
    return (isFIXNUM(x) || isBIGNUM(x) ? x :
            isFLOAT(x) ? boxint64((int64_t)qfloat(x)) :
            error1("arg for fix", x));
}

LispObject Lfloor(LispObject lits, int nargs, ...)
{   ARG1("floor", x);
    return (isFIXNUM(x) || isBIGNUM(x) ? x :
            isFLOAT(x) ? boxint64((int64_t)floor(qfloat(x))) :
            error1("arg for floor", x));
}

LispObject Lceiling(LispObject lits, int nargs, ...)
{   ARG1("ceiling", x);
    return (isFIXNUM(x) || isBIGNUM(x) ? x :
            isFLOAT(x) ? boxint64((int64_t)ceil(qfloat(x))) :
            error1("arg for ceiling", x));
}

LispObject Lfloat(LispObject lits, int nargs, ...)
{   ARG1("float", x);
    return (isFLOAT(x) ? x :
            isFIXNUM(x) ? boxfloat((double)qfixnum(x)) :
            isBIGNUM(x) ? boxfloat((double)qint64(x)) :
            error1("arg for float", x));
}

#define floatval(x)                   \
   isFLOAT(x) ? qfloat(x) :           \
   isFIXNUM(x) ? (double)qfixnum(x) : \
   isBIGNUM(x) ? (double)qint64(x) :  \
   0.0

LispObject Lcos(LispObject lits, int nargs, ...)
{   ARG1("cos", x);
    return boxfloat(cos(floatval(x)));
}

LispObject Lsin(LispObject lits, int nargs, ...)
{   ARG1("sin", x);
    return boxfloat(sin(floatval(x)));
}

LispObject Lsqrt(LispObject lits, int nargs, ...)
{   ARG1("sqrt", x);
    return boxfloat(sqrt(floatval(x)));
}

LispObject Llog(LispObject lits, int nargs, ...)
{   ARG1("log", x);
    return boxfloat(log(floatval(x)));
}

LispObject Lexp(LispObject lits, int nargs, ...)
{   ARG1("exp", x);
    return boxfloat(exp(floatval(x)));
}

LispObject Latan(LispObject lits, int nargs, ...)
{   ARG1("atan", x);
    return boxfloat(atan(floatval(x)));
}

LispObject Lnull(LispObject lits, int nargs, ...)
{   ARG1("null", x);
    return (x == nil ? lisptrue : nil);
}

LispObject Leq(LispObject lits, int nargs, ...)
{   ARG2("eq", x, y);
    return (x == y ? lisptrue : nil);
}

LispObject Lequal(LispObject lits, int nargs, ...)
{   ARG2("equal", x, y);
    while (x != y && isCONS(x) && isCONS(y))
    {   if (Lequal(lits, 2, qcar(x), qcar(y)) == nil) return nil;
        x = qcdr(x); y = qcdr(y);
    }
    if (x == y) return lisptrue;
    if ((x & TAGBITS) != (y & TAGBITS)) return nil;
    if (isSYMBOL(x) || isFIXNUM(x)) return nil;
    if (isFLOAT(x)) return (qfloat(x) == qfloat(y) ? lisptrue : nil);
    if (qheader(x) != qheader(y)) return nil;
    switch (qheader(x) & TYPEBITS)
    {   case typeVEC: case typeEQHASH: case typeEQHASHX:
        case typeEQUALHASH: case typeEQUALHASHX:
        {   int i;
            for (i=0; i<veclength(qheader(x))/sizeof(LispObject); i++)
                if (Lequal(lits, 2, elt(x, i), elt(y, i)) == nil) return nil;
            return lisptrue;
        }
        default: // Treat all other cases as containing binary information.
        {   int i;
            const char *xx = qstring(x), *yy = qstring(y);
            for (i=0; i<veclength(qheader(x)); i++)
                if (xx[i] != yy[i]) return nil;
            return lisptrue;
        }
    }
}

LispObject Lset(LispObject lits, int nargs, ...)
{   ARG2("set", x, y);
    if (!isSYMBOL(x)) return error1("bad arg for set", x);
    return (qvalue(x) = y);
}

LispObject Lboundp(LispObject lits, int nargs, ...)
{   ARG1("boundp", x);
    return (isSYMBOL(x) && qvalue(x)!=undefined) ? lisptrue : nil;
}

LispObject Lmakeunbound(LispObject lits, int nargs, ...)
{   ARG1("makeunbound", x);
    if (isSYMBOL(x)) qvalue(x) = undefined;
    return nil;
}

LispObject Lgensym(LispObject lits, int nargs, ...)
{   LispObject r;
    ARG0("gensym");
    r = allocatesymbol();
    qflags(r) = tagHDR + typeGENSYM;
    qvalue(r) = undefined;
    qplist(r) = nil;
    qpname(r) = nil;   // A nil pname marks this as a not-yet-printed gensym.
    qdefn(r)  = NULL;
    qlits(r)  = nil;
    return r;
}

LispObject Lgensymp(LispObject lits, int nargs, ...)
{   ARG1("gensymp", x);
    if (!isSYMBOL(x)) return nil;
    return (qflags(x) & TYPEBITS) == typeGENSYM ? lisptrue : nil;
}

LispObject Lchar(LispObject lits, int nargs, ...)
{   ARG1("char", x);
    return char_function(x);
}



LispObject Lcharcode(LispObject lits, int nargs, ...)
{   ARG1("char-code", x);
    if (isFIXNUM(x)) return x;
    if (isSYMBOL(x)) x = qpname(x);
    if (!isSTRING(x)) return error1("bad arg for char-code", x);
    return packfixnum(*qstring(x));
}

LispObject Lcodechar(LispObject lits, int nargs, ...)
{   char ch[4];
    ARG1("code-char", x);
    if (!isFIXNUM(x)) return error1("bad arg for code-char", x);
    ch[0] = (char)qfixnum(x); ch[1] = 0;
    return lookup(ch, 1, 1);
}

LispObject Ltime(LispObject lits, int nargs, ...)
{   clock_t c = clock();
    ARG0("time");   // I will convert the time to be in milliseconds
    return packfixnum((intptr_t)((1000*(int64_t )c)/CLOCKS_PER_SEC));
}

// (date)             "14-May-2013"
// (date!-and!-time)  "Tue May 14 09:52:45 2013"
//

LispObject Ldate(LispObject lits, int nargs, ...)
{   time_t t = time(NULL);
    char today[32];
    char today1[32];
    strcpy(today, ctime(&t));
// e.g. "Sun Sep 16 01:03:52 1973\n"
//       012345678901234567890123
    today[24] = 0;             // loses final '\n'
    today1[0] = today[8]==' ' ? '0' : today[8];
    today1[1] = today[9];
    today1[2] = '-';
    today1[3] = today[4];
    today1[4] = today[5];
    today1[5] = today[6];
    today1[6] = '-';
    today1[7] = today[20];
    today1[8] = today[21];
    today1[9] = today[22];
    today1[10] = today[23];
    today1[11] = 0;             // Now as in 03-Apr-2009
    return makestring(today1, 11);
}

LispObject Ldate_and_time(LispObject lits, int nargs, ...)
{   time_t t = time(NULL);
    char today[32];
    strcpy(today, ctime(&t));
// e.g. "Sun Sep 16 01:03:52 1973\n"
    today[24] = 0;             // loses final '\n'
    return makestring(today, 24);
}

LispObject Loblist(LispObject lits, int nargs, ...)
{
    int i;
    ARG0("oblist");
    work1 = nil;
    for (i=0; i<OBHASH_SIZE; i++)
        for (work2=obhash[i]; isCONS(work2); work2 = qcdr(work2))
        {   if (qcar(work2) != undefined)
                work1 = cons(qcar(work2), work1);
        }
    return work1;
}

LispObject Leval(LispObject lits, int nargs, ...)
{   ARG1("eval", x);
    return eval(x);
}

LispObject Lapply(LispObject lits, int nargs, ...)
{   int n = 0;
    ARG2("apply", x, y);
    if (isCONS(x) && qcar(x) == lambda)
    {   LispObject g;
        push2(x, y);
        g = Lgensym(nil, 0);
        pop2(y, x);
        if (unwindflag != unwindNONE) return nil;
        qdefn(g) = (void *)interpret;
        qlits(g) = qcdr(x);
        x = g;
    }
    else if (!isSYMBOL(x)) return error1("bad arg to apply", x);
    push(x);
    while (isCONS(y))
    {   push(qcar(y));
        y = qcdr(y);
        n++;
    }
    return applytostack(n);
}

LispObject Lplist(LispObject lits, int nargs, ...)
{   ARG1("plist", x);
    if (!isSYMBOL(x)) return nil;
    else return qplist(x);
}

LispObject Lpname(LispObject lits, int nargs, ...)
{   ARG1("pname", x);
    if (!isSYMBOL(x)) return nil;
    else return qpname(x);
}

LispObject Lput(LispObject lits, int nargs, ...)
{   LispObject w;
    ARG3("put", x, y, z);
    if (!isSYMBOL(x)) return error1("bad arg put", x);
    w = qplist(x);
    while (isCONS(w))
    {   LispObject a = qcar(w);
        w = qcdr(w);
        if (isCONS(a) && qcar(a) == y)
        {   qcdr(a) = z;
            return z;
        }
    }
    push2(x, z);
    w = acons(y, z, qplist(x));
    pop2(z, x);
    qplist(x) = w;
    return z;
}

LispObject Lget(LispObject lits, int nargs, ...)
{   ARG2("get", x, y);
    if (!isSYMBOL(x)) return nil;
    x = qplist(x);
    while (isCONS(x))
    {   LispObject a = qcar(x);
        x = qcdr(x);
        if (isCONS(a) && qcar(a) == y) return qcdr(a);
    }
    return nil;
}

LispObject Lremprop(LispObject lits, int nargs, ...)
{   LispObject p, r, *prev;
    ARG2("remprop", x, y);
    if (!isSYMBOL(x)) return nil;
    p = *(prev = &qplist(x));
    while (p != nil)
    {   if (isCONS(r = qcar(p)) && qcar(qcar(p)) == y)
        {   *prev = qcdr(p);
            return r;
        }
        p = *(prev = &qcdr(p));
    }
    return nil;
}

LispObject Lmkvect(LispObject lits, int nargs, ...)
{   int n;
    ARG1("mkvect", x);
    if (!isFIXNUM(x)) return error1("bad size in mkvect", x);
    n = (int)qfixnum(x);
// I put an (arbitrary) limit on the size of the largest vector.
    if (n < -1 || n > 100000) return error1("bad size in mkvect", x);
    return makevector(n);
}

LispObject Lupbv(LispObject lits, int nargs, ...)
{   ARG1("upbv", x);
    if (!isVEC(x)) return error1("bad arg to upbv", x);
    return makeinteger(veclength(qheader(x))/sizeof(LispObject)-1);
}

LispObject Lputv(LispObject lits, int nargs, ...)
{   int n;
    ARG3("putv", x, y, z);
    if (!isVEC(x) || !isFIXNUM(y))
        return error2("bad arg to putv", x, y);
    n = (int)qfixnum(y);
    if (n < 0 || n >= veclength(qheader(x))/sizeof(LispObject))
        return error1("subscript out of range in putv", y);
    elt(x, n) = z;
    return z;
}

LispObject Lgetv(LispObject lits, int nargs, ...)
{   int n;
    ARG2("getv", x, y);
// As a matter of convenience and generosity I will allow "getv" to
// access items from hash tables as well as ordinary vectors.
    if ((!isVEC(x) && !isEQHASH(x) && !isEQHASHX(x) &&
         !isEQUALHASH(x) && !isEQUALHASHX(x)) || !isFIXNUM(y))
        return error2("bad arg to getv", x, y);
    n = (int)qfixnum(y);
    if (n < 0 || n >= veclength(qheader(x))/sizeof(LispObject))
        return error1("subscript out of range in getv", y);
    return elt(x, n);
}

LispObject Lmkhash(LispObject lits, int nargs, ...)
{   LispObject size = packfixnum(10), r, flavour = packfixnum(0);
    va_list a;          // I am going to permit mkhash to have extra arguments.
    va_start(a, nargs); // This is for easier compatibility with Reduce.
    if (nargs >= 1) size = va_arg(a, LispObject);
    if (nargs >= 2) flavour = va_arg(a, LispObject);
    va_end(a);
    if (flavour == eq) flavour = packfixnum(0);
    else if (flavour == equal) flavour = packfixnum(1);
    if (!isFIXNUM(size)) return error1("bad size in mkhash", size);
    if (!isFIXNUM(flavour)) return error1("bad flavour in mkhash", flavour);
    int n = (int)qfixnum(size);
    int f = (int)qfixnum(flavour);
// I force hash tables to be of limited size.
    if (n <= 10) n = 11;
    else if (n > 1000) n = 997;
    n |= 1;  // Force table-size to be an odd number
    r = makevector(n-1);
    f = (f == 0 ? typeEQHASH : typeEQUALHASH);
    qheader(r) ^= (typeVEC ^ f);
    return r;
}

LispObject Lclrhash(LispObject lits, int nargs, ...)
{   ARG1("clrhash", x);
    if (isEQHASHX(x)) qheader(x) ^= (typeEQHASH ^ typeEQHASHX);
    if (isEQUALHASHX(x)) qheader(x) ^= (typeEQUALHASH ^ typeEQUALHASHX);
    if (!isEQHASH(x) && !isEQUALHASH(x))
        return error1("not a hash table in clrhash", x);
    size_t n = veclength(qheader(x))/sizeof(LispObject);
    for (size_t i=0; i<n; i++) elt(x, i) = nil;
    return x;
}

uintptr_t hashup(LispObject a, int isEQUAL)
{  if (!isEQUAL) return (uintptr_t)a;
   switch (a & TAGBITS)
   {   case tagCONS:         // Traditional Lisp "cons" item.
           return 19937*hashup(qcar(a), 1) + hashup(qcdr(a), 1);
       case tagFLOAT:        // A double-precision number.
           {   union { double d; uintptr_t i;} dd;
               dd.d = qfloat(a);
               return dd.i;
           }
       case tagATOM:         // Something else that will have a header word.
           if (isSTRING(a))
           {   int len = veclength(qheader(a));
               char *s = qstring(a);
               uintptr_t h = 0;
               for (int i=0; i<len; i++) h = 11213*h + s[i];
               return h;
           }
           return 1;         // give up for other atoms!
       default:
       case tagSYMBOL:       // a symbol.
       case tagFIXNUM:       // An immediate integer value (29 or 61 bits).
           return (uintptr_t)a;
    }
}

void rehash(LispObject x)
{   int isEQUAL = isEQUALHASHX(x);
    int n = veclength(qheader(x));
    int i;
// At the moment that this is invoked it is at least certain that
// garbage collection is not in progress. Hence the second half-space
// is all memory available for use! So on a temporary basis I will put
// a copy of the hash table there.
    LispObject x1 = heap2base + tagATOM;
    memcpy((void *)(x1 - tagATOM), (void *)(x - tagATOM),
            n + sizeof(LispObject));
    n = n/sizeof(LispObject); // Now a count of slots in the table.
// I will now re-hash from the copy that I made back into the hash table, but
// now using the new hash values that reflect and changes that have
// arisen.
    for (i=0; i<n; i++) elt(x, i) = nil;
    for (i=0; i<n; i++)
    {   LispObject b = elt(x1, i);
        while (b != nil)
        {   LispObject ca = qcar(b), cd = qcdr(b);
            int h = (int)(hashup(qcar(ca), isEQUAL)%((uintptr_t)n)); // New bucket.
            qcdr(b) = elt(x, h);
            elt(x, h) = b;    // Re-inserted in table.
            b = cd;
        }
    }
    qheader(x) ^= (typeEQHASH ^ typeEQHASHX);
}

int hashsame(LispObject x, LispObject y, int isEQUAL)
{
    if (isEQUAL) return Lequal(nil, 2, x, y) != nil;
    else return x == y;
}

LispObject Lputhash(LispObject lits, int nargs, ...)
{   int n, h;
    LispObject c;
    ARG3("puthash", x, y, z);
    if (isEQHASHX(y) || isEQUALHASHX(y)) rehash(y);
    if (!isEQHASH(y) && !isEQUALHASH(y))
        return error2("not a hash table in puthash", x, y);
    n = veclength(qheader(y))/sizeof(LispObject);
// I use unsigned types so I get a positive remainder.
    h = (int)(hashup(x, isEQUALHASH(y)) % ((uintptr_t)n));
    c = elt(y, h);
    while (isCONS(c))
    {   if (hashsame(qcar(qcar(c)), x, isEQUALHASH(y)))
        {   qcdr(qcar(c)) = z;
            return z;
        }
        c = qcdr(c);
    }
    push2(y, z);
    c = acons(x, z, elt(y, h));
    pop2(z, y);
    elt(y, h) = c;
    return z;
}

LispObject Lremhash(LispObject lits, int nargs, ...)
{   int n, h;
    LispObject c, *cp;
    ARG2("remhash", x, y);
    if (isEQHASHX(y) || isEQUALHASHX(y)) rehash(y);
    if (!isEQHASH(y) && !isEQUALHASH(y))
        return error2("not a hash table in remhash", x, y);
    n = veclength(qheader(y))/sizeof(LispObject);
    h = (int)(hashup(x, isEQUALHASH(y)) % ((uintptr_t)n));
    c = *(cp = &elt(y, h));
    while (isCONS(c))
    {   if (hashsame(qcar(qcar(c)), x, isEQUALHASH(y)))
        {   *cp = qcdr(c);
            return qcdr(qcar(c));
        }
        c = *(cp = &qcdr(c));
    }
    return nil;
}

LispObject Lgethash(LispObject lits, int nargs, ...)
{   int n, h;
    LispObject c;
    ARG2("gethash", x, y);
    if (isEQHASHX(y) || isEQUALHASHX(y)) rehash(y);
    if (!isEQHASH(y) && !isEQUALHASH(y))
        return error2("not a hash table in gethash", x, y);
    n = veclength(qheader(y))/sizeof(LispObject);
    h = (int)(hashup(x, isEQUALHASH(y)) % ((uintptr_t)n));
    c = elt(y, h);
    while (isCONS(c))
    {   if (hashsame(qcar(qcar(c)), x, isEQUALHASH(y))) return qcdr(qcar(c));
        c = qcdr(c);
    }
    return nil;
}

LispObject Lgetd(LispObject lits, int nargs, ...)
{   ARG1("getd", x);
    if (!isSYMBOL(x)) return nil;
    if ((qflags(x) & flagSPECFORM) != 0)
    {   if (qdefn(x) == (void *)interpretspecform)
            return list2star(fexpr, lambda, qlits(x));
        else return cons(fsubr, x);
    }
    else if (qdefn(x) == NULL) return nil;
    else if (qdefn(x) == (void *)interpret)
        return list2star((qflags(x) & flagMACRO) ? macro : expr,
                         lambda, qlits(x));
    else return cons(subr, x);
}

LispObject Lcopyd(LispObject lits, int nargs, ...)
{   ARG2("copyd", x, y);
    if (!isSYMBOL(x)) return error1("bad arg to copyd", x);
    if (!isSYMBOL(y)) return error1("bad arg to copyd", y);
    qdefn(x) = qdefn(y);
    qlits(x) = qlits(y);
    qflags(x) = qflags(x);
    return y;
}

LispObject Lreturn(LispObject lits, int nargs, ...)
{   ARG1("return", x);
    return error1("RETURN not in PROG context", x);
}

// Now some numeric functions

#undef FF
#undef BB
#define FF(a, b) ((a) > (b) ? lisptrue : nil)
#define BB(a, b) ((a) > (b) ? lisptrue : nil)

LispObject Lgreaterp(LispObject lits, int nargs, ...)
{   ARG2("greaterp", x, y);
    NUMOP("greaterp", x, y);
}

#undef FF
#undef BB
#define FF(a, b) ((a) >= (b) ? lisptrue : nil)
#define BB(a, b) ((a) >= (b) ? lisptrue : nil)

LispObject Lgeq(LispObject lits, int nargs, ...)
{   ARG2("geq", x, y);
    NUMOP("geq", x, y);
}

#undef FF
#undef BB
#define FF(a, b) ((a) < (b) ? lisptrue : nil)
#define BB(a, b) ((a) < (b) ? lisptrue : nil)

LispObject Llessp(LispObject lits, int nargs, ...)
{   ARG2("lessp", x, y);
    NUMOP("lessp", x, y);
}

#undef FF
#undef BB
#define FF(a, b) ((a) <= (b) ? lisptrue : nil)
#define BB(a, b) ((a) <= (b) ? lisptrue : nil)

LispObject Lleq(LispObject lits, int nargs, ...)
{   ARG2("leq", x, y);
    NUMOP("leq", x, y);
}

LispObject Lminus(LispObject lits, int nargs, ...)
{   ARG1("minus", x);
    return Nminus(x);
}

LispObject Lminusp(LispObject lits, int nargs, ...)
{   ARG1("minusp", x);
// Anything non-numeric will not be negative!
    if ((isFIXNUM(x) && x < 0) ||
        (isFLOAT(x) && qfloat(x) < 0.0) ||
        (isATOM(x) &&
         (qheader(x) & TYPEBITS) == typeBIGNUM &&
         qint64(x) < 0)) return lisptrue;
    else return nil;
}

#undef BB
#define BB(a) makeinteger(~(a))

LispObject Llognot(LispObject lits, int nargs, ...)
{   ARG1("lognot", x);
    UNARYINTOP("lognot", x);
}

LispObject Lzerop(LispObject lits, int nargs, ...)
{   ARG1("zerop", x);
// Note that a bignum can never be zero! Because that is not "big".
// This code is generous and anything non-numeric is not zero.
    if (x == packfixnum(0) ||
        (isFLOAT(x) && qfloat(x) == 0.0)) return lisptrue;
    else return nil;
}

LispObject Lonep(LispObject lits, int nargs, ...)
{   ARG1("onep", x);
    if (x == packfixnum(1) ||
        (isFLOAT(x) && qfloat(x) == 1.0)) return lisptrue;
    else return nil;
}

#undef FF
#undef BB
#define FF(a) boxfloat((a) + 1.0)
#define BB(a) makeinteger((a) + 1)

LispObject Ladd1(LispObject lits, int nargs, ...)
{   ARG1("add1", x);
    UNARYOP("add1", x);
}

#undef FF
#undef BB
#define FF(a) boxfloat((a) - 1.0)
#define BB(a) makeinteger((a) - 1)

LispObject Lsub1(LispObject lits, int nargs, ...)
{   ARG1("sub1", x);
    UNARYOP("sub1", x);
}

#undef FF
#undef BB
#define FF(a, b) boxfloat((a) - (b))
#define BB(a, b) makeinteger((a) - (b))

LispObject Ldifference(LispObject lits, int nargs, ...)
{   ARG2("difference", x, y);
    NUMOP("difference", x, y);
}

#undef FF
#undef BB
#define FF(a, b) ((b) == 0.0 ? error1("division by 0.0", nil) : \
                  boxfloat((a) / (b)))
#define BB(a, b) ((b) == 0 ? error1("division by 0", nil) : \
                  makeinteger((a) / (b)))

LispObject Lquotient(LispObject lits, int nargs, ...)
{   ARG2("quotient", x, y);
    NUMOP("quotient", x, y);
}

#undef BB
#define BB(a, b) ((b) == 0 ? error1("remainder by 0", nil) : \
                  makeinteger((a) % (b)))

LispObject Lremainder(LispObject lits, int nargs, ...)
{   ARG2("remainder", x, y);
    INTOP("remainder", x, y);
}

#undef BB
#define BB(a, b) ((b) == 0 ? error1("division by 0", nil) : \
                  cons(makeinteger((a) / (b)), makeinteger((a) % (b))))

LispObject Ldivide(LispObject lits, int nargs, ...)
{   ARG2("divide", x, y);
    INTOP("divide", x, y);
}

#undef BB
#define BB(a) makeinteger((a) << sh)

LispObject Lleftshift(LispObject lits, int nargs, ...)
{   int sh;
    ARG2("leftshift", x, y);
    if (!isFIXNUM(y)) return error1("Bad argument for leftshift", y);
    sh = (int)qfixnum(y);
    UNARYINTOP("leftshift", x);
}

#undef BB
#define BB(a) makeinteger((a) >> sh)

LispObject Lrightshift(LispObject lits, int nargs, ...)
{   int sh;
    ARG2("rightshift", x, y);
    if (!isFIXNUM(y)) return error1("Bad argument for rightshift", y);
    sh = (int)qfixnum(y);
    UNARYINTOP("rightshift", x);
}

LispObject Lstop(LispObject lits, int nargs, ...)
{   LispObject x = packfixnum(0);
    if (nargs != 0)
    {   ARG1("stop", x1);
        x = x1;
    }
    exit(isFIXNUM(x) ? (int)qfixnum(x) : EXIT_SUCCESS);
    return nil;
}

LispObject Lposn(LispObject lits, int nargs, ...)
{   ARG0("posn");
    return packfixnum(linepos);
}

LispObject Llinelength(LispObject lits, int nargs, ...)
{   ARG1("linelength", n);
    LispObject prev = packfixnum(linelength);
    if (isFIXNUM(n)) linelength = qfixnum(n);
    return prev;
}

LispObject Lprinbyte(LispObject lits, int nargs, ...)
{   ARG1("prinbyte", x);  // Arg is an integer, send it to output
                          // with no messing around.
    putc(qfixnum(x), lispfiles[lispout]);
    return x;
}

int coldstart = 0;

LispObject Lrestart_csl(LispObject lits, int nargs, ...)
// (restart!-lisp)       Cold restart (as for command-line "-z" option)...
// OR (restart!-lisp nil)Runs standard Read-Eval-Print loop.
// (restart!-lisp t)     Reload current heap image then uses its restart fn.
// (restart!-lisp f)     Reload heap image then invoke (f). (f!=nil, f!=t)
// (restart!-lisp (m f)) Reload heap, load module m, then call f.
// (restart!-lisp f a)   Reload heap, call (f a). a=nil is NOT special, so
//                       this case depends on the number of args passed rather
//                       than just using default values.
// (restart!-list (m f) a) Reload heap, load module m, call (f a).
{   ARG0123("restart-csl", x, y, z);
    if (z != NULLATOM)
        return error1s("wrong number of arguments for", "restart-lisp");
    if (x == NULLATOM) x = nil;
    if (y == NULLATOM) work1 = cons(x, nil);
    else work1 = list2star(x, y, nil);
    if (unwindflag == unwindNONE) unwindflag = unwindRESTART;
    return nil;
}

LispObject Lpreserve(LispObject lits, int nargs, ...)
// (preserve)           Dump image, leave restart fn unchanged, exit.
// (preserve f)         Dump image with new restart fn if f!=nil, exit.
// (preserve f b)       As above, but also change banner to b if b!=nil.
// (preserve f b nil)   As above.
// (preserve f b t)     Dump image as before, then do restart that loads
//                      the newly created image and uses its restart fn.
// (preserve f b g)     Dump image, readload it but override restart fn
//                      to be g just this time.
// (preserve f b (m g)) Dump image, reload, load-module m, call function g.
// (preserve f b g a)   Reserved to pass a as argument to the restart function.
//                      not implemeted yet.
{   ARG0123("preserve", x,y,z);
    if (x == NULLATOM) x = nil;
    if (y == NULLATOM) y = nil; // Ignored for now!
    if (z == NULLATOM) z = nil;
    restartfn = x;
    work1 = cons(z, nil);
    if (unwindflag == unwindNONE)
    {   unwindflag = unwindPRESERVE;
        if (z != nil) unwindflag |= unwindRESTART;
    }
    return nil;
}

LispObject Lprin(LispObject lits, int nargs, ...)
{   ARG1("prin", x);
    return prin(x);
}

LispObject Lprint(LispObject lits, int nargs, ...)
{   ARG1("print", x);
    return print(x);
}

LispObject Lprinc(LispObject lits, int nargs, ...)
{   ARG1("princ", x);
    return princ(x);
}

LispObject Lprinhex(LispObject lits, int nargs, ...)
{   ARG1("princ", x);
    return prinhex(x);
}

LispObject Lprintc(LispObject lits, int nargs, ...)
{   ARG1("printc", x);
    return printc(x);
}

LispObject Lterpri(LispObject lits, int nargs, ...)
{   ARG0("terpri");
    wrch('\n');
    return nil;
}

LispObject Lnreverse(LispObject lits, int nargs, ...)
{   ARG1("nreverse", x);
    return nreverse(x);
}

LispObject Lexplode(LispObject lits, int nargs, ...)
{   int f = lispout;
    ARG1("explode", x);
    lispout = -1;
    work1 = nil;
    prin(x);
    lispout = f;
    return nreverse(work1);
}

LispObject Lexplodec(LispObject lits, int nargs, ...)
{   int f = lispout;
    ARG1("explodec", x);
    lispout = -1;
    work1 = nil;
    princ(x);
    lispout = f;
    return nreverse(work1);
}

LispObject Lreadbyte(LispObject lits, int nargs, ...)
{   int ch;
    ARG0("readbyte");  // Read byte and return integer.
    ch = curchar;
    curchar = rdch();
    return packfixnum(ch & 0xff);
}

LispObject Lreadch(LispObject lits, int nargs, ...)
{   char ch[4];
    ARG0("readch");
    if (curchar == EOF) return eofsym;
    ch[0] = qvalue(lower) != nil ? tolower(curchar) :
            qvalue(raise) != nil ? toupper(curchar) : curchar;
    ch[1] = 0;
    curchar = rdch();
    return lookup(ch, 1, 1);
}

LispObject Lreadline(LispObject lits, int nargs, ...)
{   char ch[200];
    int n = 0;
    ARG0("readline");
    if (curchar == '\n') curchar = rdch();
    while (curchar != '\n' && curchar != EOF)
    {   if (n < sizeof(ch)-1) ch[n++] = curchar;
        curchar = rdch();
    }
    if (n == 0 && curchar == EOF) return eofsym;
    ch[n] = 0;
    return lookup(ch, n, 1);
}

LispObject Lremob(LispObject lits, int nargs, ...)
{   ARG1("remob", x);
    if (!isSYMBOL(x)) return x;
    LispObject pn = qpname(x);
    int len = veclength(qheader(pn));
    const char *s = qstring(pn);
    return lookup(s, len, -1);
}

LispObject Lread(LispObject lits, int nargs, ...)
{   ARG0("read");
    return readS();
}

LispObject Lcompress(LispObject lits, int nargs, ...)
{   int f = lispin;
    LispObject r;
    ARG1("compress", x);
    lispin = -1;
    symtype = '?';
    curchar = '\n';
    push(cursym);
    work1 = x;
    r = readS();
    lispin = f;
    pop(cursym);
    return r;
}

LispObject Lrds(LispObject lits, int nargs, ...)
{   int old = lispin;
    ARG1("rds", x);
    if (x == nil) x = packfixnum(3);
    if (isFIXNUM(x))
    {   int n = (int)qfixnum(x);
        if (0 <= n && n < MAX_LISPFILES && lispfiles[n] != NULL &&
            (file_direction & (1<<n)) == 0)
        {   lispin = n;
            symtype = '?';
// If you RDS between two files then curchar (for each) must not be
// disturbed, but this hack makes EOF get re-checked for...
            if (curchar == EOF) curchar = '\n';
            return packfixnum(old);
        }
    }
    return error1("rds failed", x);
}

LispObject Lwrs(LispObject lits, int nargs, ...)
{   int old = lispout;
    ARG1("wrs", x);
    if (x == nil) x = packfixnum(1);
    if (isFIXNUM(x))
    {   int n = (int)qfixnum(x);
        if (0 <= n && n < MAX_LISPFILES && lispfiles[n] != NULL &&
            (file_direction & (1<<n)) != 0)
        {   lispout = n;
            return packfixnum(old);
        }
    }
    return error1("wrs failed", x);
}

#define LONGEST_FILENAME 1000
char filename[2*LONGEST_FILENAME+50];
static char imagename[LONGEST_FILENAME];
static char lispdirectory[LONGEST_FILENAME];

LispObject Lget_lisp_directory(LispObject lits, int nargs, ...)
{
    return makestring(lispdirectory, strlen(lispdirectory));
}

LispObject Lsystem(LispObject lits, int nargs, ...)
{   ARG1("system", x);
    if (isSYMBOL(x)) x = qpname(x);
    if (!isSTRING(x))
        return error1("bad arg for system", x);
    sprintf(filename, "%.*s", (int)veclength(qheader(x)), qstring(x));
    system(filename);
    return nil;
}

LispObject Lsetpchar(LispObject lits, int nargs, ...)
{   ARG1("setpchar", x);
    if (isSYMBOL(x)) x = qpname(x);
    if (!isSTRING(x))
        return error1("bad arg for setpchar", x);
    LispObject r = makestring(promptstring, strlen(promptstring));
    sprintf(promptstring, "%.*s", (int)veclength(qheader(x)), qstring(x));
    return r;
}

LispObject Lopen(LispObject lits, int nargs, ...)
{   FILE *f;
    int n, how = 0;
    char *p;
    ARG2("open", x, y);
    if (isSYMBOL(x)) x = qpname(x);
    if (!isSTRING(x) ||
        !((y == input && (how=1)!=0) ||
          (y == output && (how=2)!=0) ||
          (y == pipe && (how=3)!=0)))
        return error2("bad arg for open", x, y);
    if (*qstring(x)=='$' && (p=strchr(qstring(x), '/'))!=NULL)
    {   sprintf(filename, "@%.*s", (int)(p-qstring(x))-1, 1+qstring(x));
        lits = qvalue(lookup(filename, strlen(filename), 0));
        if (isSTRING(lits)) sprintf(filename, "%.*s%.*s",
           (int)veclength(qheader(lits)), qstring(lits),
           (int)(veclength(qheader(x)) - (p-qstring(x))), p);
        else sprintf(filename, "%.*s", (int)veclength(qheader(x)), qstring(x));
    }
    else sprintf(filename, "%.*s", (int)veclength(qheader(x)), qstring(x));
#ifdef __WIN32__
//  while (strchr(filename, '/') != NULL) *strchr(filename, '/') = '\\';
#endif // __WIN32__
    if (how == 3) f = popen(filename, "w");
    else f = fopen(filename, (how == 1 ? "r" : "w"));
    if (f == NULL) return error1("[open] file could not be opened", x);
    for (n=4; n<MAX_LISPFILES && lispfiles[n]!=NULL; n++);
    if (n<MAX_LISPFILES)
    {   lispfiles[n] = f;
        if (y != input) file_direction |= (1 << n);
        return packfixnum(n);
    }
    return error1("too many open files", x);
}

LispObject Lopen_module(LispObject lits, int nargs, ...)
{   FILE *f;
    int n, how = 0;
    ARG2("open-module", x, y);
    if (isSYMBOL(x)) x = qpname(x);
    if (!isSTRING(x) ||
        !((y == input && (how=1)!=0) ||
          (y == output && (how=2)!=0)))
        return error2("bad arg for open-module", x, y);
    sprintf(filename, "%s.modules/%.*s.fasl", imagename,
                      (int)veclength(qheader(x)), qstring(x));
    f = fopen(filename, (how == 1 ? "r" : "w"));
    if (f == NULL)
    {   if (how == 2)
        {
// The function mkdir() is declared in sys/stat.h and may not be
// available on all platforms? If I fail to open xxx.img.modules/yyy.fasl
// I will try makeing certain that the directory exists...
            sprintf(filename, "mkdir %s.modules", imagename);
            system(filename);
            sprintf(filename, "%s.modules/%.*s.fasl", imagename,
                              (int)veclength(qheader(x)), qstring(x));
            f = fopen(filename, "w");
            if (f == NULL)
            {   printf("+++ module file-name: %s  mode=%d\n", filename, how);
                return error1("module could not be opened", x);
            }
        }
        else
        {   printf("+++ module file-name: %s  mode=%d\n", filename, how);
            return error1("module could not be opened", x);
        }
    }
    for (n=4; n<MAX_LISPFILES && lispfiles[n]!=NULL; n++);
    if (n<MAX_LISPFILES)
    {   lispfiles[n] = f;
        if (y != input) file_direction |= (1 << n);
        return packfixnum(n);
    }
    return error1("too many open files", x);
}

LispObject Lmodulep(LispObject lits, int nargs, ...)
{   FILE *f;
    ARG1("modulep", x);
    if (isSYMBOL(x)) x = qpname(x);
    if (!isSTRING(x))
        return error1("bad arg for modulep", x);
    sprintf(filename, "%s.modules/%.*s.fasl", imagename,
                      (int)veclength(qheader(x)), qstring(x));
    f = fopen(filename, "r");
    if (f == NULL) return nil;
    fclose(f);
    return lisptrue;
}

LispObject Lclose(LispObject lits, int nargs, ...)
{   ARG1("close", x);
    if (isFIXNUM(x))
    {   int n = (int)qfixnum(x);
        if (n > 3 && n < MAX_LISPFILES)
        {   if (lispin == n) lispin = 3;
            if (lispout == n) lispout = 1;
            if (lispfiles[n] != NULL) fclose(lispfiles[n]);
            lispfiles[n] = NULL;
            file_direction &= ~(1<<n);
        }
    }
    return nil;
}

void readevalprint(int loadp)
{   while (symtype != EOF)
    {   LispObject r;
        push(qvalue(echo));
        unwindflag = unwindNONE;
        if (loadp) qvalue(echo) = nil;
        backtraceflag = backtraceHEADER | backtraceTRACE;
        r = readS();
        pop(qvalue(echo));
        fflush(stdout);
        if (unwindflag != unwindNONE) /* Do nothing */ ;
        else if (loadp || qvalue(dfprint) == nil ||
            (isCONS(r) && (qcar(r) == lookup("rdf", 3, 0) ||
                           qcar(r) == lookup("faslend", 7, 0))))
        {   r = eval(r);
            if (unwindflag == unwindNONE && !loadp)
            {   linepos += printf("Value: ");
#ifdef DEBUG
                if (logfile != NULL) fprintf(logfile, "Value: ");
#endif // DEBUG
                print(r);
                fflush(stdout);
            }
        }
        else
        {   r = cons(r, nil);
            if (unwindflag == unwindNONE) Lapply(nil, 2, qvalue(dfprint), r);
        }
        if ((unwindflag & (unwindPRESERVE | unwindRESTART)) != 0) return;
    }
}

LispObject Lrdf(LispObject lits, int nargs, ...)
{   int f, f1;
    ARG1("rdf", x);
    f1 = Lopen(nil, 2, x, input);
    if (unwindflag != unwindNONE) return nil;
    f = Lrds(nil, 1, f1);
    readevalprint(0);
    Lrds(nil, 1, f);
    Lclose(nil, 1, f1);
    printf("+++ End of rdf\n");
    return nil;
}

LispObject Lload_module(LispObject lits, int nargs, ...)
{   int f, f1;
    ARG1("load-module", x);
    f1 = Lopen_module(nil, 2, x, input);
    if (unwindflag != unwindNONE) return nil;
// I want to save the current input status
    f = Lrds(nil, 1, f1);
    readevalprint(1);
    Lrds(nil, 1, f);
    Lclose(nil, 1, f1);
    return nil;
}

LispObject Ltrace(LispObject lits, int nargs, ...)
{   ARG1("trace", x);
    while (isCONS(x))
    {   if (isSYMBOL(qcar(x))) qflags(qcar(x)) |= flagTRACED;
        x = qcdr(x);
    }
    return nil;
}

LispObject Luntrace(LispObject lits, int nargs, ...)
{   ARG1("untrace", x);
    while (isCONS(x))
    {   if (isSYMBOL(qcar(x))) qflags(qcar(x)) &= ~flagTRACED;
        x = qcdr(x);
    }
    return nil;
}

LispObject Lerror(LispObject lits, int nargs, ...)
{   ARG2("error", x, y);
    return error2("error function called", x, y);
}

LispObject Lenable_errorset(LispObject lits, int nargs, ...)
{   int r1 = forcedMIN, r2 = forcedMAX;
    ARG2("enable-errorset", x, y);
    if (isFIXNUM(x))
    {   forcedMIN = qfixnum(x);
        if (forcedMIN < 0) forcedMIN = 0;
        else if (forcedMIN > 3) forcedMIN = 3;
    }
    else if (x == nil) forcedMIN = 0;
    else forcedMIN = 3;
    if (isFIXNUM(y))
    {   forcedMAX = qfixnum(y);
        if (forcedMAX < 0) forcedMAX = 0;
        else if (forcedMAX > 3) forcedMAX = 3;
    }
    else if (y == nil) forcedMAX = 0;
    else forcedMAX = 3;
    if (forcedMIN > forcedMAX) forcedMAX = forcedMIN;
    if (forcedMIN > 0) backtraceflag |= backtraceHEADER;
    if (forcedMIN > 1) backtraceflag |= backtraceHEADER;
    if (forcedMAX < 1) backtraceflag &= ~backtraceHEADER;
    if (forcedMAX < 2) backtraceflag &= ~backtraceHEADER;
    return cons(packfixnum(r1), packfixnum(r2));
}

LispObject Lerrorset(LispObject lits, int nargs, ...)
{   int save = backtraceflag;
    ARG3("errorset", x, y, z);
    backtraceflag = 0;
    if (y != nil) backtraceflag |= backtraceHEADER;
    if (z != nil) backtraceflag |= backtraceTRACE;
    if (forcedMAX < 1) backtraceflag &= ~backtraceHEADER;
    if (forcedMAX < 2) backtraceflag &= ~backtraceHEADER;
    if (forcedMIN > 0) backtraceflag |= backtraceHEADER;
    if (forcedMIN > 1) backtraceflag |= backtraceHEADER;
    x = eval(x);
    if (unwindflag == unwindERROR ||
        unwindflag == unwindBACKTRACE)
    {   unwindflag = unwindNONE;
        x = nil;
    }
    else x = cons(x, nil);
    backtraceflag = save;
    return x;
}

struct defined_functions
{   const char *name;
    int flags;
    void *entrypoint;
};

struct defined_functions fnsetup[] =
{
// First the special forms
    {"quote",      flagSPECFORM, (void *)Lquote},   
    {"cond",       flagSPECFORM, (void *)Lcond},   
    {"and",        flagSPECFORM, (void *)Land},   
    {"or",         flagSPECFORM, (void *)Lor},   
    {"de",         flagSPECFORM, (void *)Lde},   
    {"df",         flagSPECFORM, (void *)Ldf},   
    {"dm",         flagSPECFORM, (void *)Ldm},   
    {"setq",       flagSPECFORM, (void *)Lsetq},   
    {"progn",      flagSPECFORM, (void *)Lprogn},   
    {"prog",       flagSPECFORM, (void *)Lprog},   
    {"go",         flagSPECFORM, (void *)Lgo},   
// The following are implemented as special forms here because they
// take variable or arbitrary numbers of arguments - however they all
// evaluate all their arguments in a rather simple way, so they
// could be treated a sorts of "ordinary" function.
    {"list",       flagSPECFORM, (void *)Llist},
    {"list*",      flagSPECFORM, (void *)Lliststar},
    {"iplus",      flagSPECFORM, (void *)Lplus},
    {"itimes",     flagSPECFORM, (void *)Ltimes},
    {"ilogand",    flagSPECFORM, (void *)Llogand},
    {"ilogor",     flagSPECFORM, (void *)Llogor},
    {"ilogxor",    flagSPECFORM, (void *)Llogxor},
// Now ordinary functions.
    {"apply",      0,            (void *)Lapply},
    {"atan",       0,            (void *)Latan},
    {"atom",       0,            (void *)Latom},
    {"bignump",    0,            (void *)Lbignump},
    {"boundp",     0,            (void *)Lboundp},
    {"car",        0,            (void *)Lcar},
    {"cdr",        0,            (void *)Lcdr},
    {"nth",        0,            (void *)Lnth},
    {"pnth",       0,            (void *)Lpnth},
    {"char",       0,            (void *)Lchar},
    {"char-code",  0,            (void *)Lcharcode},
    {"checkpoint", 0,            (void *)Lpreserve},
    {"close",      0,            (void *)Lclose},
    {"clrhash",    0,            (void *)Lclrhash},
    {"code-char",  0,            (void *)Lcodechar},
    {"compress",   0,            (void *)Lcompress},
    {"cons",       0,            (void *)Lcons},
    {"cos",        0,            (void *)Lcos},
    {"date",       0,            (void *)Ldate},
    {"date-and-time",0,          (void *)Ldate_and_time},
    {"eq",         0,            (void *)Leq},
    {"equal",      0,            (void *)Lequal},
    {"error",      0,            (void *)Lerror},
    {"errorset",   0,            (void *)Lerrorset},
    {"enable-errorset", 0,       (void *)Lenable_errorset},
    {"eval",       0,            (void *)Leval},
    {"exp",        0,            (void *)Lexp},
    {"explode",    0,            (void *)Lexplode},
    {"explodec",   0,            (void *)Lexplodec},
    {"floatp",     0,            (void *)Lfloatp},
    {"gensym",     0,            (void *)Lgensym},
    {"gensymp",    0,            (void *)Lgensymp},
    {"get",        0,            (void *)Lget},
    {"get-lisp-directory",0,     (void *)Lget_lisp_directory},
    {"getd",       0,            (void *)Lgetd},
    {"copyd",      0,            (void *)Lcopyd},
    {"gethash",    0,            (void *)Lgethash},
    {"getv",       0,            (void *)Lgetv},
    {"iadd1",      0,            (void *)Ladd1},
    {"iceiling",   0,            (void *)Lceiling},
    {"idifference",0,            (void *)Ldifference},
    {"idivide",    0,            (void *)Ldivide},
    {"iequal",     0,            (void *)Lequal},
    {"ifix",       0,            (void *)Lfix},
    {"ifixp",      0,            (void *)Lfixp},
    {"ifloat",     0,            (void *)Lfloat},
    {"ifloor",     0,            (void *)Lfloor},
    {"igeq",       0,            (void *)Lgeq},
    {"igreaterp",  0,            (void *)Lgreaterp},
    {"ileftshift", 0,            (void *)Lleftshift},
    {"ileq",       0,            (void *)Lleq},
    {"ilessp",     0,            (void *)Llessp},
    {"ilognot",    0,            (void *)Llognot},
    {"iminus",     0,            (void *)Lminus},
    {"iminusp",    0,            (void *)Lminusp},
    {"inumberp",   0,            (void *)Lnumberp},
    {"iquotient",  0,            (void *)Lquotient},
    {"iremainder", 0,            (void *)Lremainder},
    {"irightshift",0,            (void *)Lrightshift},
    {"isub1",      0,            (void *)Lsub1},
    {"linelength*",0,            (void *)Llinelength},
    {"load-module",0,            (void *)Lload_module},
    {"log",        0,            (void *)Llog},
    {"lposn",      0,            (void *)Lposn},
    {"makeunbound",0,            (void *)Lmakeunbound},
    {"mkhash",     0,            (void *)Lmkhash},
    {"mkvect",     0,            (void *)Lmkvect},
    {"modulep",    0,            (void *)Lmodulep},
    {"null",       0,            (void *)Lnull},
    {"oblist",     0,            (void *)Loblist},
    {"onep",       0,            (void *)Lonep},
    {"open",       0,            (void *)Lopen},
    {"open-module",0,            (void *)Lopen_module},
    {"plist",      0,            (void *)Lplist},
    {"pname",      0,            (void *)Lpname},
    {"posn",       0,            (void *)Lposn},
    {"preserve",   0,            (void *)Lpreserve},
    {"prin",       0,            (void *)Lprin},
    {"prin1",      0,            (void *)Lprin},
    {"prin2",      0,            (void *)Lprinc},
    {"prinbyte",   0,            (void *)Lprinbyte},
    {"princ",      0,            (void *)Lprinc},
    {"prinhex",    0,            (void *)Lprinhex},
    {"print",      0,            (void *)Lprint},
    {"printc",     0,            (void *)Lprintc},
    {"prog1",      0,            (void *)Lprog1},
    {"prog2",      0,            (void *)Lprog2},
    {"put",        0,            (void *)Lput},
    {"puthash",    0,            (void *)Lputhash},
    {"putv",       0,            (void *)Lputv},
    {"rdf",        0,            (void *)Lrdf},
    {"rds",        0,            (void *)Lrds},
    {"read",       0,            (void *)Lread},
    {"readbyte",   0,            (void *)Lreadbyte},
    {"readch",     0,            (void *)Lreadch},
    {"readline",   0,            (void *)Lreadline},
    {"reclaim",    0,            (void *)Lreclaim},
    {"remhash",    0,            (void *)Lremhash},
    {"remob",      0,            (void *)Lremob},
    {"remprop",    0,            (void *)Lremprop},
    {"restart-lisp",0,           (void *)Lrestart_csl},
    {"restart-csl",0,            (void *)Lrestart_csl},
    {"return",     0,            (void *)Lreturn},
    {"rplaca",     0,            (void *)Lrplaca},
    {"rplacd",     0,            (void *)Lrplacd},
    {"set",        0,            (void *)Lset},
    {"setpchar*",  0,            (void *)Lsetpchar},
    {"sin",        0,            (void *)Lsin},
    {"sqrt",       0,            (void *)Lsqrt},
    {"stop",       0,            (void *)Lstop},
    {"stringp",    0,            (void *)Lstringp},
    {"symbol-name",0,            (void *)Lpname},
    {"symbolp",    0,            (void *)Lsymbolp},
    {"system",     0,            (void *)Lsystem},
    {"terpri",     0,            (void *)Lterpri},
    {"time",       0,            (void *)Ltime},
    {"trace",      0,            (void *)Ltrace},
    {"untrace",    0,            (void *)Luntrace},
    {"upbv",       0,            (void *)Lupbv},
    {"vectorp",    0,            (void *)Lvectorp},
    {"wrs",        0,            (void *)Lwrs},
    {"zerop",      0,            (void *)Lzerop},
    {NULL,         0,            NULL}   
};

void setup()
{
// Ensure that initial symbols and functions are in place. Parts of this
// code are rather rambling and repetitive but this is at least a simple
// way to do things. I am going to assume that nothing can fail within this
// setup code, so I can omit all checks for error conditions.
    struct defined_functions *p;
    undefined = lookup("~indefinite-value~", 18, 1);
    qflags(undefined) |= flagGLOBAL;
    qvalue(undefined) = undefined;
    nil = lookup("nil", 3, 1);
    qflags(nil) |= flagGLOBAL;
    qvalue(nil) = nil;
    lisptrue = lookup("t", 1, 1);
    qflags(lisptrue) |= flagGLOBAL;
    qvalue(lisptrue) = lisptrue;
    qvalue(echo = lookup("*echo", 5, 1)) = interactive ? nil : lisptrue;
    qflags(echo) |= flagFLUID;
    qvalue(lispsystem = lookup("lispsystem*", 11, 1)) =
        list2star(lookup("vsl", 3, 1), lookup("csl", 3, 1),
                  list2star(lookup("embedded", 8, 1),
                      cons(lookup("image", 5, 3),
                           makestring(imagename, strlen(imagename))), nil));
    qflags(lispsystem) |= flagGLOBAL;
    quote = lookup("quote", 5, 1);
    function = lookup("function", 8, 1);
    backquote = lookup("`", 1, 1);
    comma = lookup(",", 1, 1);
    comma_at = lookup(",@", 2, 1);
    comma_dot = lookup(",.", 2, 1);
    eofsym = lookup("$eof$", 5, 1);
    qflags(eofsym) |= flagGLOBAL;
    qvalue(eofsym) = eofsym;
    lambda = lookup("lambda", 6, 1);
    expr = lookup("expr", 4, 1);
    subr = lookup("subr", 4, 1);
    fexpr = lookup("fexpr", 5, 1);
    fsubr = lookup("fsubr", 5, 1);
    macro = lookup("macro", 5, 1);
    input = lookup("input", 5, 1);
    output = lookup("output", 6, 1);
    pipe = lookup("pipe", 4, 1);
    eq = lookup("eq", 2, 1);
    equal = lookup("equal", 5, 1);    
    qvalue(dfprint = lookup("dfprint*", 6, 1)) = nil;
    qflags(dfprint) |= flagFLUID;
    qvalue(raise = lookup("*raise", 6, 1)) = nil;
    qvalue(lower = lookup("*lower", 6, 1)) = lisptrue;
    qflags(raise) |= flagFLUID;
    qflags(lower) |= flagFLUID;
    toploopeval = lookup("toploopeval*", 12, 1);
    loseflag = lookup("lose", 4, 1);
    bignum = lookup("~bignum", 7, 1);
    condsymbol = lookup("cond", 4, 1);
    prognsymbol = lookup("progn", 5, 1);
    gosymbol = lookup("go", 2, 1);
    returnsymbol = lookup("return", 6, 1);
#ifdef PSL
    dummyvar = lookup("~dummyvar", 9, 1);
#endif
    cursym = nil;
    work1 = work2 = nil;
    p = fnsetup;
    while (p->name != NULL)
    {   LispObject w = lookup(p->name, strlen(p->name), 1);
        qflags(w) |= p->flags;
        qdefn(w) = p->entrypoint;
        p++;
    }
}

void cold_start()
{
// version of setup to call when there is no initial heap image at all.
    int i;
// I make the object-hash-table lists end in a fixnum rather than nil
// because I want to create the hash table before even the symbol nil
// exists.
    for (i=0; i<OBHASH_SIZE; i++) obhash[i] = tagFIXNUM;
    for (i=0; i<BASES_SIZE; i++) bases[i] = NULLATOM;
    setup();
// The following fields could not be set up quite early enough in the
// cold start case, so I repair them now.
    restartfn = qplist(undefined) = qlits(undefined) =
        qplist(nil) = qlits(nil) = nil;
}

LispObject relocate(LispObject a, LispObject change)
{
// Used to update a LispObject when reloaded from a saved heap image.
    switch (a & TAGBITS)
    {   case tagATOM:
           if (a == NULLATOM) return a;
        case tagCONS:
        case tagSYMBOL:
        case tagFLOAT:
            return a + change;
        default:
//case tagFIXNUM:
//case tagFORWARD:
//case tagHDR:
            return a;
    }
}

// A saved image will start with a word that contains the following 32-bit
// code. This identifies the word-width of the system involved.

#define FILEID (('v' << 0) | ('s' << 8) | ('l' << 16) |   \
                (('0' + sizeof(LispObject)) << 24))

void warm_start()
{
// The idea here is that a file that will already have been
// created by a previous use of Lisp, and it should be re-loaded.
    gzFile f = gzopen(imagename, "rb");
    int i;
    LispObject currentbase = heap1base, change, s;
    if (f == NULL)
    {   printf("Error: unable to open image for reading\n");
        my_exit(EXIT_FAILURE);
    }
    if (gzread(f, nonbases, (unsigned int)sizeof(nonbases)) != sizeof(nonbases) ||
        headerword != FILEID ||
        gzread(f, bases, (unsigned int)sizeof(bases)) != sizeof(bases) ||
        gzread(f, obhash, (unsigned int)sizeof(obhash)) != sizeof(obhash))
    {   printf("Error: Image file corrupted or incompatible\n");
        my_exit(EXIT_FAILURE);
    }
    change = currentbase - heap1base;
// Now I relocate the key addresses to refer to the CURRENT rather than
// the saved address map.
    heap1base  += change;
    heap1top   += change;
    fringe1    += change;
    fpfringe1  += change;
    if (gzread(f, (void *)heap1base, (unsigned int)(fringe1-heap1base)) !=
              (int)(fringe1-heap1base) ||
        gzread(f, (void *)fpfringe1, (unsigned int)(heap1top-fpfringe1)) !=
              (int)(heap1top-fpfringe1))
    {   printf("Error: Unable to read image file\n");
        my_exit(EXIT_FAILURE);
    }
    gzclose(f);
    if (change != 0)
    {   for (i=0; i<BASES_SIZE; i++)
            bases[i] = relocate(bases[i], change);
        for (i=0; i<OBHASH_SIZE; i++)
            obhash[i] = relocate(obhash[i], change);
// The main heap now needs to be scanned and addresses in it corrected.
        s = heap1base;
        while (s != fringe1)
        {   LispObject h, w;
            if (!isHDR(h = qcar(s))) // A simple cons cell
            {   qcar(s) = relocate(h, change);
                qcdr(s) = relocate(qcdr(s), change);
                s += 2*sizeof(LispObject);
            }
            else              // The item is one that uses a header
                switch (h & TYPEBITS)
                {   case typeSYM:
                    case typeGENSYM:
                        w = s + tagSYMBOL;
                        // qflags(w) does not need adjusting
                        qvalue(w) = relocate(qvalue(w), change);
                        qplist(w) = relocate(qplist(w), change);
                        qpname(w) = relocate(qpname(w), change);
                        if (qdefn(w) == (void *)saveinterp)
                            qdefn(w) = (void *)interpret;
                        else if (qdefn(w) == (void *)saveinterpspec)
                            qdefn(w) = (void *)interpretspecform;
                        qlits(w)  = relocate(qlits(w), change);
                        s += SYMSIZE*sizeof(LispObject);
                        continue;
                    case typeSTRING: case typeBIGNUM:
// These sorts of atom just contain binary data so do not need adjusting,
// but I have to allow for the length code being in bytes etc.
                        s += ALIGN8(sizeof(LispObject) + veclength(h));
                        continue;
                    case typeEQHASH: case typeEQUALHASH:
                        qcar(s) ^= (typeEQHASH ^ typeEQHASHX);
                    case typeVEC: case typeEQHASHX: case typeEQUALHASHX:
                        s += sizeof(LispObject);
                        w = veclength(h);
                        while (w > 0)
                        {   qcar(s) = relocate(qcar(s), change);
                            s += sizeof(LispObject);
                            w -= sizeof(LispObject);
                        }
                        s = ALIGN8(s);
                        continue;
                    default:
                        // The spare codes!
                        printf("Failure with h = %x\n", (int)h & TYPEBITS);
                        assert(0);
                }
        }
    }
    setup(); // resets all built-in functions properly.
}

#define VERSION 1002

int main(int argc, char *argv[])
{
    for (int i=0; i<MAX_LISPFILES+1; i++)
    {   curchars[i] = '\n';
        symtypes[i] = 0;
    }
#ifndef NOLIBEDIT
    elx_e = el_init(argv[0], stdin, stdout, stderr);
    el_set(elx_e, EL_PROMPT, prompt);
    el_set(elx_e, EL_EDITOR, "emacs");
    if ((elx_h = history_init()) == 0)
    {   fprintf(stderr, "Unable to initialize history\n");
        exit(1);
    }
    history(elx_h, &elx_v, H_SETSIZE, 400);
    el_set(elx_e, EL_HIST, history, elx_h);
#endif
    int i;
    const char *inputfilename = NULL;
    void *pool;
    pool = (void *)malloc(HEAPSIZE + BITMAPSIZE + STACKSIZE + 16);
    if (pool == NULL)
    {   printf("Not enough memory available: Unable to proceed\n");
        my_exit(EXIT_FAILURE);
    }
    memset(pool, 0, HEAPSIZE + BITMAPSIZE + STACKSIZE + 16);
    coldstart = 0;
    interactive = 1;
#ifdef DEBUG
    logfile = fopen("vsl.log", "w");
#endif // DEBUG
#ifdef __WIN32__
    i = strlen(argv[0]);
    if (strcmp(argv[0]+i-4, ".exe") == 0) i -= 4;
    sprintf(imagename, "%.*s.img", i, argv[0]);
#else // __WIN32__
    sprintf(imagename, "%s.img", argv[0]);
#endif // __WIN32__
    strcpy(lispdirectory, imagename);
    {   char *p = lispdirectory+strlen(lispdirectory)-5;
        while (isalnum((int)*p) && p != &lispdirectory[0]) p--;
        if (*p != '/' && *p != '\\') p++;
        *p = 0;
    }
    for (i=1; i<argc; i++)
    {
// I have some VERY simple command-line options here.
//        -z         do a "cold start".
//        -ifilename use that as image file
//        -i filename    ditto
//        filename   read from that file rather than from the standard input.
//        -g         force all diagnostics
        if (strcmp(argv[i], "-z") == 0) coldstart = 1;
        else if (strcmp(argv[i], "-g") == 0)
            forcedMIN = forcedMAX = 3;
        else if (strcmp(argv[i], "-i") == 0 && i<argc-1)
        {   strcpy(imagename, argv[i+1]);
            i++;
        }
        else if (strncmp(argv[i], "-i", 2) == 0) strcpy(imagename, argv[i]+2);
        else if (argv[i][0] != '-') inputfilename = argv[i], interactive = 0;
    }
    printf("VSL version %d.%.3d\n", VERSION/1000, VERSION%1000); fflush(stdout);
    linepos = 0;
    for (i=0; i<MAX_LISPFILES; i++) lispfiles[i] = 0;
    lispfiles[0] = stdin;   lispfiles[1] = stdout;
    lispfiles[2] = stderr;  lispfiles[3] = stdin;
    file_direction = (1<<1) | (1<<2); // 1 bits for writable files.
    lispin = 3; lispout = 1;
    if (inputfilename != NULL)
    {   FILE *in = fopen(inputfilename, "r");
        if (in == NULL)
            printf("Unable to read from %s, so using standard input\n",
                   inputfilename);
        else lispfiles[3] = in;
    }
    boffop = 0;
    for (;;) // This loop is for restart-lisp and preserve.
    {   allocateheap(pool);
// A warm start will read an image file which it expects to have been
// made by a previous use of vsl.
        if (coldstart) cold_start();
        else warm_start();
// Any predefined specified on the command-line using -Dxx=yy are
// instated or re-instated here so they apply even after restart!-lisp.
        for (i=1; i<argc; i++)
        {   if (argv[i][0] == '-' && argv[i][1] == 'D')
            {   const char *d1 = strchr(argv[i], '=');
                if (d1 == NULL) continue;
// In general through setup (and I count this as still being setup)
// I will code on the basis that there will not be any garbage collection
// so I do not need to think about the effects of data movement during GC.
                qvalue(lookup(argv[i]+2, (d1-argv[i])-2, 1)) =
                    makestring(d1+1, strlen(d1+1));
            }
        }
        fflush(stdout);
        curchar = '\n'; symtype = '?'; cursym = nil;
        if (boffop == 0) // Use standard restart function from image.
        {   if (restartfn == nil) readevalprint(0);
            else Lapply(nil, 2, restartfn, nil);
        }
        else
        {   LispObject x, data = makestring(boffo, boffop);
            data = Lcompress(nil, 1, Lexplodec(nil, 1, data));
            x = qcar(data);   // 'fn or '(module fn)
            if (x != nil)
            {   if (x == lisptrue) x = restartfn;
                else if (isCONS(x) && isCONS(qcdr(x)))
                {   push2(data, qcar(qcdr(x)));
                    Lload_module(nil, 1, qcar(x));
                    pop2(x, data);
                }
                Lapply(nil, 2, x, qcdr(data));
            }
        }
        if ((unwindflag & unwindPRESERVE) != 0)
        {   gzFile f = gzopen(imagename, "wbT");
            if (f == NULL)
                printf("\n+++ Unable to open %s for writing\n", imagename);
            else
            {   reclaim(); // To compact memory.
                headerword = FILEID;
                saveinterp = (LispObject)(void *)interpret;
                saveinterpspec = (LispObject)(void *)interpretspecform;
                gzwrite(f, nonbases, (unsigned int)sizeof(nonbases));
                gzwrite(f, bases, (unsigned int)sizeof(bases));
                gzwrite(f, obhash, (unsigned int)sizeof(obhash));
                gzwrite(f, (void *)heap1base, (unsigned int)(fringe1-heap1base));
                gzwrite(f, (void *)fpfringe1, (unsigned int)(heap1top-fpfringe1));
            }
            gzclose(f);
// A cautious person would have checked for error codes returned by the
// above calls to write and close. I omit that here to be concise.
        }
        if ((unwindflag & unwindRESTART) == 0) break;
        unwindflag = unwindNONE;
        boffop = 0;
        if (qcar(work1) == nil) coldstart = 1;
        else if (qcar(work1) == lisptrue) coldstart = 0;
        else
        {   int save = lispout;
            lispout = -2;
            internalprint(work1);
            wrch(0);
            lispout = save;
            coldstart = 0;
        }
    }
    return 0;
}

// end of main source file.
