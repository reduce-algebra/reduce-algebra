// "vsl.c"                                A C Norman, January 2012
//
// This is a small Lisp system. It is especially
// intended for use of the Raspberry Pi board, but should build
// on almost any computer with a modern C compiler.

// This code may be used subject to the BSD licence included in the file
// "bsd.txt" that should accompany it.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdarg.h>

// A Lisp item is represented as an integer and the low 3 bits
// contain tag information that specify how the rest will be used.

typedef intptr_t LispObject;

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

// In memory CONS cells and FLOATS exist as just 2-word items with all their
// bits in use. All other sorts of data have a header word at their start. This
// contains extra information about the exact form of data present

#define TYPEBITS    0x78

#define typeSYM     0x00
#define typeSTRING  0x08
#define typeVEC     0x10
#define typeBIGNUM  0x18
#define typeEQHASH  0x20
#define typeEQHASHX 0x28
// Codes 0x30, 0x38, 0x40, 0x48, 0x50, 0x58, 0x60, 0x68,
// 0x70 and 0x78 spare!

#define veclength(h)  (((uintptr_t)(h)) >> 7)
#define packlength(n) (((LispObject)(n)) << 7)

// Accessor macros the extract fields from LispObjects ...

#define qcar(x) (((LispObject *)(x))[0])
#define qcdr(x) (((LispObject *)(x))[1])

// For all other types I must remove the tagging information before I
// can use the item as a pointer.

// An especially important case is that of Symbols. These are the fields that
// they provide.

#define qflags(x) (((LispObject *)((x)-tagSYMBOL))[0])
#define qvalue(x) (((LispObject *)((x)-tagSYMBOL))[1])
#define qplist(x) (((LispObject *)((x)-tagSYMBOL))[2])
#define qpname(x) (((LispObject *)((x)-tagSYMBOL))[3])
#define qdefn(x)  (((void **)     ((x)-tagSYMBOL))[4])
#define qlits(x)  (((LispObject *)((x)-tagSYMBOL))[5])

// Bits within the flags field of a symbol. Uses explained later on.

#define flagTRACED    0x080
#define flagSPECFORM  0x100
#define flagMACRO     0x200
// There are LOTS more bits available for flags etc here if needbe!

// Other atoms have a header that gives info about them. Well as a special
// case I will allow that something tagged with tagATOM but with zero as
// its address is a special marker value...

#define NULLATOM   (tagATOM + 0)
#define qheader(x) (((LispObject *)((x)-tagATOM))[0])

// Fixnums and Floating point numbers are rather easy!

#define qfixnum(x)     ((x) >> 3)
#define packfixnum(n)  ((((LispObject)(n)) << 3) + tagFIXNUM)

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

// The Lisp heap will have fixed size. Here I make it 32 Mbytes which should
// fit comfortable on a Raspberry Pi but will also be ample for many serious
// applications. On a 64-bit machine twice as much memory will be used.

#define HEAPSIZE (8*1024*1024*sizeof(LispObject))
#define STACKSIZE (128*1024*sizeof(LispObject))

// I force sizes to be multiples of some power of 2 mostly because I view
// it as tidy, but in part to guarantee alignment of addresses.

#define ROUNDED_HEAPSIZE ((HEAPSIZE+0xfff) & ~0xfff)
#define ROUNDED_STACKSIZE ((STACKSIZE+0xfff) & ~0xfff)
#define BITMAPSIZE (ROUNDED_HEAPSIZE/128)

LispObject stackbase, *sp, stacktop;

// I should probably arrange to check for stack overflow here.

#define push(x)        { *sp++ = (x); }
#define TOS            (sp[-1])
#define pop(x)         { (x) = *--sp; }
#define push2(x, y)    { push(x); push(y); }
#define pop2(y, x)     { pop(y); pop(x); }
#define push3(x, y, z) { push(x); push(y); push(z); }
#define pop3(z, y, x)  { pop(z); pop(y); pop(x); }
#define discard(n)     { sp -= (n); }

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
#define quote      bases[6]
#define backquote  bases[7]
#define comma      bases[8]
#define comma_at   bases[9]
#define eofsym     bases[10]
#define cursym     bases[11]
#define work1      bases[12]
#define work2      bases[13]
#define restartfn  bases[14]
#define expr       bases[15]
#define subr       bases[16]
#define fexpr      bases[17]
#define fsubr      bases[18]
#define macro      bases[19]
#define input      bases[20]
#define output     bases[21]
#define pipe       bases[22]
#define raise      bases[23]
#define lower      bases[24]
#define BASES_SIZE       25

LispObject bases[BASES_SIZE];
LispObject obhash[OBHASH_SIZE];

// ... and non-LispObject values that need to be saved as part of a
// heap image.

#define headerword     nonbases[0]
#define heap1base      nonbases[1]
#define heap1top       nonbases[2]
#define fringe1        nonbases[3]
#define fpfringe1      nonbases[4]
#define saveinterp     nonbases[5]
#define saveinterpspec nonbases[6]
#define NONBASES_SIZE       7

LispObject nonbases[NONBASES_SIZE];
LispObject heap2base, heap2top, fringe2, fpfringe2, bitmap;

// allocate memory for the heap... to be done once at the start of a run.

void allocateheap()
{   void *pool = (void *)
        malloc(ROUNDED_HEAPSIZE+BITMAPSIZE+ROUNDED_STACKSIZE+16);
    if (pool == NULL)
    {   fprintf(stderr, "Not enough memory available: Unable to proceed\n");
        exit(1);
    }
    heap1base = (LispObject)pool;
    heap1base = (heap1base + 7) & ~7; // ensure alignment
    heap1top = heap2base = heap1base + (ROUNDED_HEAPSIZE/2);
    heap2top = heap2base + (ROUNDED_HEAPSIZE/2);
    fringe1 = heap1base;
    fpfringe1 = heap1top;
    fringe2 = heap2base;
    fpfringe2 = heap2top;
    stackbase = heap2top;
    stacktop = stackbase + ROUNDED_STACKSIZE;
    bitmap = stacktop;
    sp = (LispObject *)stackbase;
}

// Now I have enough to let me define various allocation functions.

extern void reclaim();

LispObject cons(LispObject a, LispObject b)
{   if (fringe1 >= fpfringe1)
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

LispObject list2star(LispObject a, LispObject b, LispObject c)
{
// (cons a (cons b c))
    if (fringe1 + 2*sizeof(LispObject) >= fpfringe1)
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

LispObject acons(LispObject a, LispObject b, LispObject c)
{
// (cons (cons a b) c)
    if (fringe1 + 2*sizeof(LispObject) >= fpfringe1)
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

LispObject boxfloat(double a)
{   LispObject r;
    if (fringe1 >= fpfringe1) reclaim();
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
    fringe1 += 6*sizeof(LispObject);
    return r;
}

// This one allocates an atom that is n bytes long (plus its header
// word) and again does not fill in ANY of the fields.

LispObject allocateatom(int n)
{   LispObject r;
    if (fringe1 + n*sizeof(LispObject) >= fpfringe1) reclaim();
    r = fringe1 + tagATOM;
// The actual amount of space allocated must include a word for the
// header and must then be rounded up to be a multiple of 8.
    n = (n + sizeof(LispObject) + 7) & ~7;
    fringe1 += n;
    return r;
}

LispObject makestring(const char *s, int len)
{   LispObject r = allocateatom(len);
    qheader(r) = tagHDR + typeSTRING + packlength(len);
    memcpy(qstring(r), s, len);
    return r;
}

#define elt(v, n) (((LispObject *)((v) - tagATOM + sizeof(LispObject)))[n])

LispObject makevector(int maxindex)
{   int len = (maxindex+1)*sizeof(LispObject);
    LispObject r = allocateatom(len);
    int i;
    qheader(r) = tagHDR + typeVEC + packlength(len);
    for (i=0; i<=maxindex; i++) elt(r, i) = nil;
    return r;
}

LispObject boxint64(int64_t a)
{   LispObject r = allocateatom(16);
    qheader(r) = tagHDR + typeBIGNUM + packlength(16);
    qint64(r) = a;
    return r;
}

void disaster(int line)
{   fprintf(stderr, "\nInternal inconsistency detected on line %d\n", line);
    fprintf(stderr, "Unable to continue. Apologies.\n");
    abort();
}

extern LispObject error1(const char *msg, LispObject data);

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

#define BOFFO_SIZE 256
char boffo[BOFFO_SIZE+4];
int boffop;

#define swap(a,b) w = (a); (a) = (b); (b) = w;

extern LispObject copy(LispObject x);

int gccount = 1;

void reclaim()
{
// The strategy here is due to C J Cheyney ("A Nonrecursive List Compacting
// Algorithm". Communications of the ACM 13 (11): 677-678, 1970).
    LispObject *s, w;
    fprintf(stderr, "+++ GC number %d", gccount++);
    fflush(stderr);
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
// I fill the alternative half-space with junk so that any refereces
// that still point there are liable to lead to prompt crashes.
    memset((void *)heap2base, 0x56, (size_t)(heap2top-heap2base));
    if (fpfringe1 - fringe1 < 1000*sizeof(LispObject))
    {   fprintf(stderr, "\nRun out of memory.\n");
        fprintf(stderr, "Unable to continue. Apologies.\n");
        exit(1);
    }
    fprintf(stderr, " - collection complete\n");
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
// When a hash table is copied its header is changes to EQHASHX, which
// indicates that it will need rehashing before further use.
                    h ^= (typeEQHASH ^ typeEQHASHX);
                case typeEQHASHX:
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
                    //case typeSYM:
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
            return 0;  // gcc does not know that the "disaster" function will
            // never return, so this is to avoid a moan from it.
    }
}

#define printPLAIN   0
#define printESCAPES 1

int linelength = 80, linepos = 0, printflags = printESCAPES;

#define MAX_LISPFILES 10
FILE *lispfiles[MAX_LISPFILES];
int32_t file_direction = 0, interactive = 0;
int lispin, lispout;

extern LispObject lookup(const char *s);

void wrch(int c)
{   if (lispout != -1)
    {   putc(c, lispfiles[lispout]);
        if (c == '\n')
        {   linepos = 0;
            fflush(lispfiles[lispout]);
        }
        else linepos++;
    }
    else
    {   char w[4];
// This bit is for the benefit of explode and explodec
        LispObject r;
        w[0] = c; w[1] = 0;
        r = lookup(w);
        work1 = cons(r, work1);
    }
}

int rdch()
{   LispObject w;
    if (lispin != -1)
    {   int c = getc(lispfiles[lispin]);
        if (c != EOF && qvalue(echo) != nil) wrch(c);
        return c;
    }
    else if (!isCONS(work1)) return EOF;
    w = qcar(work1);
    work1 = qcdr(work1);
    if (isSYMBOL(w)) w = qpname(w);
    if (!isSTRING(w)) return EOF;
    return *qstring(w);
}

int gensymcounter = 1;

void checkspace(int n)
{   if (linepos + n >= linelength && lispout != -1) wrch('\n');
}

char printbuffer[32];

void internalprint(LispObject x)
{   int sep = '(', i, esc, len;
    char *s;
    LispObject pn;
    switch (x & TAGBITS)
    {   case tagCONS:
            if (x == 0)    // can only occus in case of bugs here.
            {   wrch('#');
                return;
            }
            while (isCONS(x))
            {   checkspace(1);
                if (linepos != 0 || sep != ' ') wrch(sep);
                sep = ' ';
                push(x);
                internalprint(qcar(x));
                pop(x);
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
                if (!isalpha((int)s[0])) esc++;
                for (i=1; i<len; i++)
                {   if (!isalpha((int)s[i]) &&
                        !isdigit((int)s[i]) &&
                        s[i]!='_') esc++;
                }
                checkspace(len + esc);
                if (!isalpha((int)s[0])) wrch('!');
                wrch(s[0]);
                for (i=1; i<len; i++)
                {   if (!isalpha((int)s[i]) &&
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
                        s = qstring(x);
                        if ((printflags & printESCAPES) == 0)
                        {   int i;
                            checkspace(len);
                            for (i=0; i<len; i++) wrch(s[i]);
                        }
                        else
                        {   esc = 2;
                            for (i=0; i<len; i++)
                                if (s[i] == '"') esc++;
                            checkspace(len+esc);
                            wrch('"');
                            for (i=0; i<len; i++)
                            {   if (s[i] == '"') wrch('"');
                                wrch(s[i]);
                            }
                            wrch('"');
                        }
                        return;
                    case typeBIGNUM:
                        sprintf(printbuffer, "%" PRId64, qint64(x));
                        checkspace(len = strlen(printbuffer));
                        for (i=0; i<len; i++) wrch(printbuffer[i]);
                        return;
                    case typeVEC:
                    case typeEQHASH:
                    case typeEQHASHX:
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
                        disaster(__LINE__);
                }
        case tagFLOAT:
            {   double d =  *((double *)(x - tagFLOAT));
                if (isnan(d)) strcpy(printbuffer, "NaN");
                else if (finite(d)) sprintf(printbuffer, "%.14g", d);
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
            disaster(__LINE__);
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

LispObject print(LispObject a)
{   printflags = printESCAPES;
    push(a);
    internalprint(a);
    pop(a);
    wrch('\n');
    return a;
}

LispObject printc(LispObject a)
{   printflags = printPLAIN;
    push(a);
    internalprint(a);
    pop(a);
    wrch('\n');
    return a;
}

int curchar = '\n', symtype = 0;

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
        return lookup(boffo);
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
            return lookup(boffo);
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
            {   r = Nplus2(Ntimes2(packfixnum(16), r),
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
            {   r = Nplus2(Ntimes2(packfixnum(10), r),
                           packfixnum(boffo[boffop++] - '0'));
            }
            if (neg) r = Nminus(r);
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
    return lookup(boffo);
}

// Syntax for Lisp input
//
//   S ::= name
//     |   integer
//     |   float
//     |   string
//     |   ' S   | ` S  | , S  | ,@ S
//     |   ( T
//     ;
//
//   T ::= )
//     |   . S )
//     |   S T
//     ;

extern LispObject readT();

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
            case '.':
            case ')':     // Ignore spurious "." and ")" input.
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

LispObject lookup(const char *s)
{   LispObject w, pn;
    int len = strlen(s);
    int i, hash = 1;
    for (i=0; i<len; i++) hash = 13*hash + s[i];
    hash = (hash & 0x7fffffff) % OBHASH_SIZE;
    w = obhash[hash];
    while (w != tagFIXNUM)
    {   LispObject a = qcar(w);        // Will be a symbol.
        LispObject n = qpname(a);      // Will be a string.
        int l = veclength(qheader(n)); // Length of the name.
        if (l == len &&
            strncmp(s, qstring(n), len) == 0)
            return a;                  // Existing symbol found.
        w = qcdr(w);
    }
// here the symbol as required was not already present.
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

int unwindflag = 0;

#define unwindNONE      0
#define unwindERROR     1
#define unwindBACKTRACE 2
#define unwindGO        3
#define unwindRETURN    4

int backtraceflag = -1;
#define backtraceHEADER 1
#define backtraceTRACE  2

LispObject error1(const char *msg, LispObject data)
{   int f = lispout;
    if ((backtraceflag & backtraceHEADER) != 0)
    {   linepos = fprintf(stderr, "\n+++ Error: %s: ", msg);
        lispout = 2;
        print(data);
        lispout = f;
    }
    unwindflag = (backtraceflag & backtraceTRACE) != 0 ? unwindBACKTRACE :
                 unwindERROR;
    return nil;
}

LispObject error1s(const char *msg, const char *data)
{   if ((backtraceflag & backtraceHEADER) != 0)
        fprintf(stderr, "\n+++ Error: %s %s\n", msg, data);
    unwindflag = (backtraceflag & backtraceTRACE) != 0 ? unwindBACKTRACE :
                 unwindERROR;
    return nil;
}

typedef LispObject specialform(LispObject data, LispObject x);
typedef LispObject lispfn(LispObject data, int nargs, ...);

LispObject applytostack(int n)
{
// Apply a function to n arguments.
// Here the stack has first the function, and then n arguments. The code is
// grim and basically repetitive, and to avoid it being even worse I will
// expect that almost all Lisp functions have at most 4 arguments, so
// if there are more than that I will pass the fifth and beyond all in a list.
    LispObject f, w;
    int saveout = lispout,
        traced = (qflags(sp[-n-1]) & flagTRACED) != 0;
    if (traced)
    {   int i;
        fprintf(stderr, "Calling: "); linepos = 9;
        lispout = 2; print(sp[-n-1]);
        for (i=1; i<=n; i++)
        {   linepos = fprintf(stderr, "Arg%d: ", i);
            print(sp[i-n-1]);
        }
        lispout = saveout;
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
    {   case 0: f = TOS;
            w = (*(lispfn *)qdefn(f))(qlits(f), 0);
            break;
        case 1:
        {   LispObject a1;
            pop(a1);
            f = TOS;
            w = (*(lispfn *)qdefn(f))(qlits(f), 1, a1);
            break;
        }
        case 2:
        {   LispObject a1, a2;
            pop(a2)
            pop(a1);
            f = TOS;
            w = (*(lispfn *)qdefn(f))(qlits(f), 2, a1, a2);
            break;
        }
        case 3:
        {   LispObject a1, a2, a3;
            pop(a3);
            pop(a2)
            pop(a1);
            f = TOS;
            w = (*(lispfn *)qdefn(f))(qlits(f), 3, a1, a2, a3);
            break;
        }
        case 4:
        {   LispObject a1, a2, a3, a4;
            pop(a4);
            pop(a3);
            pop(a2)
            pop(a1);
            f = TOS;
            w = (*(lispfn *)qdefn(f))(qlits(f), 4,
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
            w = (*(lispfn *)qdefn(f))(qlits(f), 5,
                                      a1, a2, a3, a4, a5andup);
            break;
        }
        default:disaster(__LINE__);
            return nil;
    }
    pop(f);
    if (unwindflag == unwindBACKTRACE)
    {   saveout = lispout; lispout = 2;
        linepos = fprintf(stderr, "Calling: ");
        print(f); lispout = saveout;
    }
    else if (traced)
    {   push(w); saveout = lispout; lispout = 2;
        prin(f); fprintf(stderr, " = "); linepos += 3;
        print(w); lispout = saveout; pop(w);
    }
    return w;
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
            {   specialform *fn = (specialform *)qdefn(f);
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

LispObject Lprogn(LispObject lits, LispObject x);

// The next array is used to help with error recovery, and it does
// not need to be protected by the garbage collector.
#define MAX_ARGS 50
LispObject pushedvars[MAX_ARGS];

LispObject interpret(LispObject def, int nargs, ...)
{
// def should be ((a1 a2 ...) e1 e2 ...)
// where the number of args a1 ... should the same as nargs. Use
// "shallow binding" to cope with the need for a1 ... to have some
// sort of local scope. Note with mild distress that this implements
// "dynamic" rather than "static" scoping, but old-fashioned Lisp code
// will have coped with that!
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
        return error1("wrong number of args", cons(r, w));
    }
    push(arglist);
    r = Lprogn(nil, body);
// Now I must restore the bound variables (regardless of whether there
// has been an error).
    pop(arglist);
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
    LispObject v;
    if (!isCONS(lits)) return nil;
    v = qcar(lits);
    lits = qcdr(lits);
    if (!isCONS(v) || !isSYMBOL(v = qcar(v))) return nil;
    push2(qvalue(v), v);
    qvalue(v) = x;
    lits = Lprogn(nil, lits);
    pop2(v, qvalue(v));
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

LispObject definer(LispObject x, int flags, void *fn)
{
// x should be of the form
//     (name (arg list ...) body)
    LispObject name, def;
    if (!isCONS(x) ||
        !isSYMBOL(name = qcar(x)) ||
        !isCONS(def = qcdr(x)))
        return error1("malformed use of de, df or dm", x);
    if ((qflags(name) & flagSPECFORM) != 0)
        return error1("attempt to redefine special form", name);
    qflags(name) |= flags;
    qdefn(name) = fn;
    qlits(name) = def;
// Now I will try to call macroexpand_list to expand all macros
    push2(name, def);
    x = lookup("macroexpand_list");
    if (qdefn(x) != NULL)
    {   def = qcdr(TOS);
        push2(x, def);
        x = applytostack(1);
        pop2(def, name);
        if (unwindflag != unwindNONE) return name;
        qlits(name) = cons(qcar(def), x);
    }
    return name;
}

LispObject Lde(LispObject lits, LispObject x)
{   return definer(x, 0, (void*)interpret);
}

LispObject Ldf(LispObject lits, LispObject x)
{   return definer(x, flagSPECFORM, (void*)interpretspecform);
}

LispObject Ldm(LispObject lits, LispObject x)
{   return definer(x, flagMACRO, (void*)interpret);
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

LispObject Lprog(LispObject lits, LispObject x)
{
// Does merely progn just now!!!
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
        if (isCONS(qcar(x))) eval(qcar(x));
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
        work1 = nil;
        if (unwindflag != unwindNONE) break;
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
{   if (!isCONS(x) || !isSYMBOL(work1 = qcar(x)))
        return error1("bad go", x);
    work1 = qcar(x);
    unwindflag = unwindGO;
    return nil;
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
        if (unwindflag != unwindNONE) \
        {   pop2(r, x);               \
            return nil;               \
        }                             \
        pop(r);                       \
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

LispObject Lcar(LispObject lits, int nargs, ...)
{   ARG1("car", x);
    if (isCONS(x)) return qcar(x);
    else return error1("car of an atom", x);
}

LispObject Lcdr(LispObject lits, int nargs, ...)
{   ARG1("cdr", x);
    if (isCONS(x)) return qcdr(x);
    else return error1("cdr of an atom", x);
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

LispObject Lcons(LispObject lits, int nargs, ...)
{   ARG2("cons", x, y);
    return cons(x, y);
}

LispObject Latom(LispObject lits, int nargs, ...)
{   ARG1("atom", x);
    return (isCONS(x) ? nil : lisptrue);
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
            error1("arg for fix", x));
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
        {   int i;
            for (i=0; i<veclength(qheader(x))/sizeof(LispObject); i++)
                if (Lequal(lits, 2, elt(x, i), elt(y, i)) == nil) return nil;
            return lisptrue;
        }
        default: // Treat all other cases as containing binary information.
        {   int i;
            const char *xx = qstring(x), *yy = qstring(y);
            for (i=0; i<veclength(qheader(x)); i++)
                if (xx[1] != yy[1]) return nil;
            return lisptrue;
        }
    }
}

LispObject Lset(LispObject lits, int nargs, ...)
{   ARG2("set", x, y);
    if (!isSYMBOL(x)) return error1("bad arg for set", x);
    return (qvalue(x) = y);
}

LispObject Lgensym(LispObject lits, int nargs, ...)
{   LispObject r;
    ARG0("gensym");
    r = allocatesymbol();
    qflags(r) = tagHDR + typeSYM;
    qvalue(r) = undefined;
    qplist(r) = nil;
    qpname(r) = nil;   // A nil pname marks this as a gensym.
    qdefn(r)  = NULL;
    qlits(r)  = nil;
    return r;
}

LispObject Ltime(LispObject lits, int nargs, ...)
{   clock_t c = clock();
    ARG0("time");   // I will convert the time to be in milliseconds
    return packfixnum((intptr_t)((1000*(int64_t )c)/CLOCKS_PER_SEC));
}

LispObject Loblist(LispObject lits, int nargs, ...)
{   ARG0("oblist");
    int i;
    work1 = nil;
    for (i=0; i<OBHASH_SIZE; i++)
        for (work2=obhash[i]; isCONS(work2); work2 = qcdr(work2))
            if (qcar(work2) != undefined)
                work1 = cons(qcar(work2), work1);
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
    push3(x, y, z);
    w = acons(y, z, qplist(x));
    pop3(z, y, x);
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
    if (n < 0 || n > 100000) return error1("bad size in mkvect", x);
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
        return error1("bad arg to putv", cons(x, y));
    n = (int)qfixnum(y);
    if (n < 0 || n >= veclength(qheader(x))/sizeof(LispObject))
        return error1("subscript out of range in putv", y);
    elt(x, n) = z;
    return z;
}

LispObject Lgetv(LispObject lits, int nargs, ...)
{   int n;
    ARG2("getvec", x, y);
// As a metter of convenience and generosity I will allow "getv" to
// access items from hash tables as well as ordinary vectors.
    if ((!isVEC(x) && !isEQHASH(x) && !isEQHASHX(x)) || !isFIXNUM(y))
        return error1("bad arg to getv", cons(x, y));
    n = (int)qfixnum(y);
    if (n < 0 || n >= veclength(qheader(x))/sizeof(LispObject))
        return error1("subscript out of range in getv", y);
    return elt(x, n);
}

LispObject Lmkhash(LispObject lits, int nargs, ...)
{   int n;
    LispObject x, r;
    va_list a;          // I am going to permit mkhash to have extra arguments.               
    va_start(a, nargs); // This is for easier conmpatibility with Reduce.        
    x = va_arg(a, LispObject);  
    va_end(a);
    if (!isFIXNUM(x)) return error1("bad size in mkhash", x);
    n = (int)qfixnum(x);
// I force hash tables to be of limited size.
    if (n <= 10) n = 11;
    else if (n > 1000) n = 997;
    n |= 1;  // Force table-size to be an odd number
    r = makevector(n-1);
    qheader(r) ^= (typeVEC ^ typeEQHASH);
    return r;
}

void rehash(LispObject x)
{
// At the moment that this is invoked it is at least certain that
// garbage collection is not in progress. Hence the second half-space
// is all memory available for use! So on a temporary basis I will put
// a copy of the hash table there.
    LispObject x1 = heap2base + tagATOM;
    int n = veclength(qheader(x));
    int i;
    memcpy((void *)heap2base, (void *)(x - tagATOM), n + sizeof(LispObject));
    n = n/sizeof(LispObject); // Now a count of slots in the table.
// I will now re-hash from the copy that I made back into the hash table, but
// now using the new hash values that reflect and changes that might have
// arisen.
    for (i=0; i<n; i++) elt(x, i) = nil;
    for (i=0; i<n; i++)
    {   LispObject b = elt(x1, i);
        while (b != nil)
        {   LispObject ca = qcar(b), cd = qcdr(b);
            int h = (int)(((uintptr_t)qcar(ca))/((uintptr_t)n)); // New bucket.
            qcdr(b) = elt(x, h);
            elt(x, h) = b;    // Re-inserted in table.
            b = cd;
        }
    }
}

LispObject Lputhash(LispObject lits, int nargs, ...)
{   int n, h;
    LispObject c;
    ARG3("puthash", x, y, z);
    if (isEQHASHX(y)) rehash(y);
    if (!isEQHASH(y)) return error1("not a hash table in puthash", cons(x, y));
    n = veclength(qheader(y))/sizeof(LispObject);
// I use unsigned types so I get a positive remainder.
    h = (int)(((uintptr_t)y) % ((uintptr_t)n));
    c = elt(y, h);
    while (isCONS(c))
    {   if (qcar(qcar(c)) == x)
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
    if (isEQHASHX(y)) rehash(y);
    if (!isEQHASH(y)) return error1("not a hash table in remhash", cons(x, y));
    n = veclength(qheader(y))/sizeof(LispObject);
    h = (int)(((uintptr_t)y) % ((uintptr_t)n));
    c = *(cp = &elt(y, h));
    while (isCONS(c))
    {   if (qcar(qcar(c)) == x)
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
    if (isEQHASHX(y)) rehash(y);
    if (!isEQHASH(y)) return error1("not a hash table in gethash", cons(x, y));
    n = veclength(qheader(y))/sizeof(LispObject);
    h = (int)(((uintptr_t)y) % ((uintptr_t)n));
    c = elt(y, h);
    while (isCONS(c))
    {   if (qcar(qcar(c)) == x) return qcdr(qcar(c));
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

LispObject Lreturn(LispObject lits, int nargs, ...)
{   ARG1("return", x);
    work1 = x;
    unwindflag = unwindRETURN;
    return nil;
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
#define FF(a, b) boxfloat((a) / (b))
#define BB(a, b) makeinteger((a) / (b))

LispObject Lquotient(LispObject lits, int nargs, ...)
{   ARG2("quotient", x, y);
    NUMOP("quotient", x, y);
}

#undef BB
#define BB(a, b) makeinteger((a) % (b))

LispObject Lremainder(LispObject lits, int nargs, ...)
{   ARG2("remainder", x, y);
    INTOP("remainder", x, y);
}

#undef BB
#define BB(a, b) cons(makeinteger((a) / (b)), makeinteger((a) % (b)))

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

// A saved image will start with a word that contains the following 32-bit
// code. This can identify the byte-ordering and word-width of the system
// involved, so protects against attempts to reload an image on a machine
// other than the one it was build on. If I was being more proper I would
// include a version number as well.

#define FILEID (('v' << 0) | ('s' << 8) | ('l' << 16) |   \
                (('0' + sizeof(LispObject)) << 24))

LispObject Lpreserve(LispObject lits, int nargs, ...)
{
// preserve can take either 0 or 1 args. If it has a (non-nil) arg that will
// be a startup function for the image when restored.
    va_list a;
    LispObject x;
    FILE *f;
    if (nargs == 0) x = nil;
    else
    {   if (nargs != 1)
            return error1s("wrong number of arguments for", "preserve");
        va_start(a, nargs);
        x = va_arg(a, LispObject);
        va_end(a);
    }
    restartfn = x;
    f = fopen("vsl.img", "wb");
    if (f == NULL) return error1("unable to open vsl.img for writing", nil);
    headerword = FILEID;
    reclaim(); // To compact memory.
// I write this stuff out as a bunch of bytes, since I only intend to
// re-read it on exactly the same computer.
    saveinterp = (LispObject)(void *)interpret;
    saveinterpspec = (LispObject)(void *)interpretspecform;
    fwrite(nonbases, 1, sizeof(nonbases), f);
    fwrite(bases, 1, sizeof(bases), f);
    fwrite(obhash, 1, sizeof(obhash), f);
    fwrite((void *)heap1base, 1, (size_t)(fringe1-heap1base), f);
    fwrite((void *)fpfringe1, 1, (size_t)(heap1top-fpfringe1), f);
    fclose(f);
// A cautious person would have checked for error codes returned by the
// above calls to fwrite and close. I omit that here to be concise.
    return nil;
}

LispObject Lstop(LispObject lits, int nargs, ...)
{   ARG1("stop", x);
    exit(isFIXNUM(x) ? (int)qfixnum(x) : 0);
    return nil; // well this will in fact neber be executed!
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

LispObject Lcharcode(LispObject lits, int nargs, ...)
{   ARG1("char-code", x);
    if (isSYMBOL(x)) x = qpname(x);
    if (!isSTRING(x)) return error1("bad arg for char-code", x);
    return packfixnum(*qstring(x));
}

LispObject Lcodechar(LispObject lits, int nargs, ...)
{   char b[4];
    ARG1("code-char", x);
    if (!isFIXNUM(x)) return error1("bad arg for code-char", x);
    b[0] = (char)qfixnum(x); b[1] = 0;
    return lookup(b);
}

LispObject Lreadch(LispObject lits, int nargs, ...)
{   char ch[4];
    ARG0("readch");
    ch[0] = qvalue(lower) != nil ? tolower(curchar) :
            qvalue(raise) != nil ? toupper(curchar) : curchar;
    ch[1] = 0;
    curchar = rdch();
    return lookup(ch);
}

LispObject Lreadline(LispObject lits, int nargs, ...)
{   char ch[100];
    int n = 0;
    ARG0("readline");
    if (curchar == '\n') curchar = rdch();
    while (curchar != '\n' && curchar != EOF)
    {   if (n < sizeof(ch)-1) ch[n++] = curchar;
        curchar = rdch();
    }
    ch[n] = 0;
    return lookup(ch);
}

LispObject Lread(LispObject lits, int nargs, ...)
{   ARG0("read");
    return readS();
}

LispObject Lcompress(LispObject lits, int nargs, ...)
{   int f = lispin;
    LispObject r;
    int savetype = symtype, savech = curchar;
    ARG1("compress", x);
    lispin = -1;
    symtype = '?';
    curchar = '\n';
    push(cursym);
    work1 = x;
    r = readS();
    lispin = f;
    pop(cursym);
    symtype = savetype;
    curchar = savech;
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

#define LONGEST_FILENAME 100
char filename[LONGEST_FILENAME];

LispObject Lopen(LispObject lits, int nargs, ...)
{   FILE *f;
    int n;
    ARG2("open", x, y);
    if (!isSTRING(x) ||
        (y != input && y != output && y != pipe))
        return error1("bad arg for open", cons(x, y));
    memset(filename, 0, LONGEST_FILENAME);
    memcpy(filename, qstring(x), (size_t)veclength(qheader(x)));
#ifdef _WIN32
    while (strchr(filename, '/') != NULL) *strchr(filename, '/') = '\\';
#endif
    if (y == pipe) f = popen(filename, "w");
    else f = fopen(filename, (y == input ? "r" : "w"));
    if (f == NULL) return error1("file could not be opened", x);
    for (n=4; n<MAX_LISPFILES && lispfiles[n]!=NULL; n++);
    if (n<MAX_LISPFILES)
    {   lispfiles[n] = f;
        if (y != input) file_direction |= (1 << n);
        return packfixnum(n);
    }
    return error1("too many open files", x);;
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

LispObject Lrdf(LispObject lits, int nargs, ...)
{   int f, f1;
    ARG1("rdf", x);
    f1 = Lopen(nil, 2, x, input);
    if (unwindflag != unwindNONE) return nil;
    f = Lrds(nil, 1, f1);
    while (symtype != EOF)
    {   LispObject r;
        unwindflag = unwindNONE;
        backtraceflag = backtraceHEADER | backtraceTRACE;
        r = eval(readS());
        if (unwindflag == unwindNONE) print(r);
    }
    curchar = '\n';
    symtype = '?';
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
    return error1("error function called", list2star(x,y,nil));
}

LispObject Lerrorset(LispObject lits, int nargs, ...)
{   int save = backtraceflag;
    ARG3("errorset", x, y, z);
    backtraceflag = 0;
    if (y != nil) backtraceflag |= backtraceHEADER;
    if (z != nil) backtraceflag |= backtraceTRACE;
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
    {"plus",       flagSPECFORM, (void *)Lplus},
    {"times",      flagSPECFORM, (void *)Ltimes},
    {"logand",     flagSPECFORM, (void *)Llogand},
    {"logor",      flagSPECFORM, (void *)Llogor},
    {"logxor",     flagSPECFORM, (void *)Llogxor},
// Now ordinary functions. I have put these in alphabetic order.
    {"add1",       0,            (void *)Ladd1},
    {"apply",      0,            (void *)Lapply},
    {"atan",       0,            (void *)Latan},
    {"atom",       0,            (void *)Latom},
    {"car",        0,            (void *)Lcar},
    {"cdr",        0,            (void *)Lcdr},
    {"char-code",  0,            (void *)Lcharcode},
    {"ceiling",    0,            (void *)Lceiling},
    {"close",      0,            (void *)Lclose},
    {"code-char",  0,            (void *)Lcodechar},
    {"compress",   0,            (void *)Lcompress},
    {"cons",       0,            (void *)Lcons},
    {"cos",        0,            (void *)Lcos},
    {"difference", 0,            (void *)Ldifference},
    {"divide",     0,            (void *)Ldivide},
    {"eq",         0,            (void *)Leq},
    {"equal",      0,            (void *)Lequal},
    {"error",      0,            (void *)Lerror},
    {"errorset",   0,            (void *)Lerrorset},
    {"eval",       0,            (void *)Leval},
    {"exp",        0,            (void *)Lexp},
    {"explode",    0,            (void *)Lexplode},
    {"explodec",   0,            (void *)Lexplodec},
    {"fix",        0,            (void *)Lfix},
    {"fixp",       0,            (void *)Lfixp},
    {"float",      0,            (void *)Lfloat},
    {"floatp",     0,            (void *)Lfloatp},
    {"floor",      0,            (void *)Lfloor},
    {"gensym",     0,            (void *)Lgensym},
    {"geq",        0,            (void *)Lgeq},
    {"get",        0,            (void *)Lget},
    {"getd",       0,            (void *)Lgetd},
    {"gethash",    0,            (void *)Lgethash},
    {"getv",       0,            (void *)Lgetv},
    {"greaterp",   0,            (void *)Lgreaterp},
    {"leftshift",  0,            (void *)Lleftshift},
    {"leq",        0,            (void *)Lleq},
    {"lessp",      0,            (void *)Llessp},
    {"log",        0,            (void *)Llog},
    {"lognot",     0,            (void *)Llognot},
    {"minus",      0,            (void *)Lminus},
    {"minusp",     0,            (void *)Lminusp},
    {"mkhash",     0,            (void *)Lmkhash},
    {"mkvect",     0,            (void *)Lmkvect},
    {"null",       0,            (void *)Lnull},
    {"numberp",    0,            (void *)Lnumberp},
    {"oblist",     0,            (void *)Loblist},
    {"onep",       0,            (void *)Lonep},
    {"open",       0,            (void *)Lopen},
    {"plist",      0,            (void *)Lplist},
    {"preserve",   0,            (void *)Lpreserve},
    {"prin",       0,            (void *)Lprin},
    {"princ",      0,            (void *)Lprinc},
    {"print",      0,            (void *)Lprint},
    {"printc",     0,            (void *)Lprintc},
    {"put",        0,            (void *)Lput},
    {"puthash",    0,            (void *)Lputhash},
    {"putv",       0,            (void *)Lputv},
    {"quotient",   0,            (void *)Lquotient},
    {"rdf",        0,            (void *)Lrdf},
    {"rds",        0,            (void *)Lrds},
    {"read",       0,            (void *)Lread},
    {"readch",     0,            (void *)Lreadch},
    {"readline",   0,            (void *)Lreadline},
    {"remainder",  0,            (void *)Lremainder},
    {"remhash",    0,            (void *)Lremhash},
    {"remprop",    0,            (void *)Lremprop},
    {"return",     0,            (void *)Lreturn},
    {"rightshift", 0,            (void *)Lrightshift},
    {"rplaca",     0,            (void *)Lrplaca},
    {"rplacd",     0,            (void *)Lrplacd},
    {"set",        0,            (void *)Lset},
    {"sin",        0,            (void *)Lsin},
    {"sqrt",       0,            (void *)Lsqrt},
    {"stop",       0,            (void *)Lstop},
    {"stringp",    0,            (void *)Lstringp},
    {"sub1",       0,            (void *)Lsub1},
    {"symbolp",    0,            (void *)Lsymbolp},
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
    undefined = lookup("~indefinite-value~");
    qvalue(undefined) = undefined;
    nil = lookup("nil");
    qvalue(nil) = nil;
    lisptrue = lookup("t");
    qvalue(lisptrue) = lisptrue;
    qvalue(echo = lookup("*echo")) = interactive ? nil : lisptrue;
    qvalue(lispsystem = lookup("lispsystem*")) =
       list2star(lookup("vsl"), lookup("csl"), nil);
    quote = lookup("quote");
    backquote = lookup("`");
    comma = lookup(",");
    comma_at = lookup(",@");
    eofsym = lookup("$eof$");
    qvalue(eofsym) = eofsym;
    lambda = lookup("lambda");
    expr = lookup("expr");
    subr = lookup("subr");
    fexpr = lookup("fexpr");
    fsubr = lookup("fsubr");
    macro = lookup("macro");
    input = lookup("input");
    output = lookup("output");
    pipe = lookup("pipe");
    qvalue(raise = lookup("*raise")) = nil;
    qvalue(lower = lookup("*lower")) = lisptrue;
    cursym = nil;
    work1 = work2 = restartfn = nil;
    p = fnsetup;
    while (p->name != NULL)
    {   LispObject w = lookup(p->name);
        qflags(w) |= p->flags;
        qdefn(w) = p->entrypoint;
        p++;
    }
}

void cold_setup()
{
// version of setup to call when there is no initial heap image at all.
    int i;
// I make the object-hash-table lists end in a fixnum rather than nil
// because I want to create the hash table before even the symbol nil
// exists.
    for (i=0; i<OBHASH_SIZE; i++) obhash[i] = tagFIXNUM;
    setup();
// The following fields could not be set up quite early enough in the
// cold start case, so I repair them now.
    qplist(undefined) = qlits(undefined) = nil;
    qplist(nil) = qlits(nil) = nil;
}

LispObject relocate(LispObject a, LispObject change)
{
// Used to update a LispObject when reloaded from a saved heap image.
    switch (a & TAGBITS)
    {   case tagCONS:
        case tagSYMBOL:
        case tagATOM:
        case tagFLOAT:
            return a + change;
        default:
//case tagFIXNUM:
//case tagFORWARD:
//case tagHDR:
            return a;
    }
}

void warm_setup()
{
// The idea here is that a file called "vsl.img" will already have been
// created by a previous use of vsl, and it should be re-loaded.
    FILE *f = fopen("vsl.img", "rb");
    int i;
    LispObject currentbase = heap1base, change, *s;
    if (f == NULL)
    {   fprintf(stderr, "Error: unable to open vsl.img for reading\n");
        exit(1);
    }
    if (fread(nonbases, 1, sizeof(nonbases), f) != sizeof(nonbases) ||
        headerword != FILEID ||
        fread(bases, 1, sizeof(bases), f) != sizeof(bases) ||
        fread(obhash, 1, sizeof(obhash), f) != sizeof(obhash))
    {   fprintf(stderr, "Error: Image file corrupted or incompatible\n");
        exit(1);
    }
    change = currentbase - heap1base;
// Now I relocate the key addresses to refer to the CURRENT rather than
// the saved address map.
    heap1base  += change;
    heap1top   += change;
    fringe1    += change;
    fpfringe1  += change;
    if (fread((void *)heap1base, 1, (size_t)(fringe1-heap1base), f) !=
              (size_t)(fringe1-heap1base) ||
        fread((void *)fpfringe1, 1, (size_t)(heap1top-fpfringe1), f) !=
              (size_t)(heap1top-fpfringe1))
    {   fprintf(stderr, "Error: Unable to read image file\n");
        exit(1);
    }
    fclose(f);
    for (i=0; i<BASES_SIZE; i++)
        bases[i] = relocate(bases[i], change);
    for (i=0; i<OBHASH_SIZE; i++)
        obhash[i] = relocate(obhash[i], change);
// The main heap now needs to be scanned and addresses in it corrected.
    s = (LispObject *)heap1base;
    while ((LispObject)s != fringe1)
    {   LispObject h = *s, w;
        if (!isHDR(h)) // The item to be processed is a simple cons cell
        {   *s++ = relocate(h, change);
            *s = relocate(*s, change);
            s++;
        }
        else              // The item is one that uses a header
            switch (h & TYPEBITS)
            {   case typeSYM:
                    w = ((LispObject)s) + tagSYMBOL;
                    // qflags(w) does not need adjusting
                    qvalue(w) = relocate(qvalue(w), change);
                    qplist(w) = relocate(qplist(w), change);
                    qpname(w) = relocate(qpname(w), change);
                    if (qdefn(w) == (void *)saveinterp)
                        qdefn(w) = (void *)interpret;
                    else if (qdefn(w) == (void *)saveinterpspec)
                        qdefn(w) = (void *)interpretspecform;
                    qlits(w)  = relocate(qlits(w), change);
                    s += 6;
                    continue;
                case typeSTRING: case typeBIGNUM:
// These sorts of atom just contain binary data so do not need adjusting,
// but I have to allow for the length code being in bytes etc.
                    w = (LispObject)s;
                    w += veclength(h);
                    w = (w + sizeof(LispObject) + 7) & ~7;
                    s = (LispObject *)w;
                    continue;
                case typeVEC: case typeEQHASH: case typeEQHASHX:
                    s++;
                    w = veclength(h);
                    while (w > 0)
                    {   *s = relocate(*s, change);
                        s++;
                        w -= sizeof(LispObject);
                    }
                    s = (LispObject *)(((LispObject)s + 7) & ~7);
                    continue;
                default:
                    // The spare codes!
                    disaster(__LINE__);
            }
    }
    setup(); // resets all built-in functions properly.
}

int main(int argc, char *argv[])
{   int i;
    const char *inputfilename = NULL;
    int coldstart = 0;
    interactive = 1;
    for (i=1; i<argc; i++)
    {
// I have some VERY simple command-line options here.
//        -z        do a "cold start" rather than re-loading an existing
//                  heap image.
//        filename  read from that file rather than from the standard input.
        if (strcmp(argv[i], "-z") == 0) coldstart = 1;
        if (argv[i][0] != '-') inputfilename = argv[i], interactive = 0;
    }
    printf("VSL version 1.00\n");
    linepos = 0;
    for (i=0; i>MAX_LISPFILES; i++) lispfiles[i] = 0;
    lispfiles[0] = stdin;   lispfiles[1] = stdout;
    lispfiles[2] = stderr;  lispfiles[3] = stdin;
    file_direction = (1<<1) | (1<<2); // 1 bits for writable files.
    lispin = 3; lispout = 1;
    if (inputfilename != NULL)
    {   FILE *in = fopen(inputfilename, "r");
        if (in == NULL)
            fprintf(stderr,
                    "Unable to read from %s, so using standard input\n",
                    inputfilename);
        else lispfiles[3] = in;
    }
    allocateheap();
// A warm start will read a file "vsl.img" which it expects to have been
// made by a previous use of vsl.
    if (coldstart) cold_setup();
    else warm_setup();
    curchar = '\n'; symtype = '?'; cursym = nil;
// If a heap image had been built specifying a restart function then
// call that here rather than using the normal read-eval-print loop.
    if (restartfn != nil)
    {   Lapply(nil, 2, restartfn, nil);
    }
    else while (symtype != EOF)
        {   LispObject r;
            unwindflag = unwindNONE;
            backtraceflag = backtraceHEADER | backtraceTRACE;
            r = eval(readS());
            if (unwindflag == unwindNONE)
            {   printf("Value: "); linepos += 7;
                print(r);
            }
        }
    return 0;
}

// end of "vsl.c"
