/*  fasl.c                          Copyright (C) 1990-2008 Codemist Ltd */

/*
 * Binary file support for faster loading of precompiled code etc.
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 58e1f78b 04-Jul-2009 */

#include "headers.h"

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#ifdef SOCKETS
#include "sockhdr.h"
#endif

CSLbool fasl_output_file = NO;  /* An output file is open? */
static int skipping_input = 0, skipping_output = 0;
static int32_t recent_pointer = 0, hits = 0 , misses = 0, fasl_byte_count = 0;
static CSLbool fp_rep_set = NO;

/*
 * FASL files are binary, and are treated as containing sequences of
 * unsigned bytes, where the bytes are names as in the following set
 * of definitions, which MUST be kept in step with the code that
 * creates FASL files.  I expect FASL files to be portable between
 * computers that use the same character set, but names of symbols
 * will get totally scrambled between ASCII and EBCDIC hosts.
 */

#define F_END       0  /* end of FASL file */
#define F_NIL       1  /* the symbol NIL */
#define F_TRU       2  /* the symbol T */
#define F_EXT       3  /* used to get operands > 8 bits into other codes */
#define F_INT       4  /* positive fixnum */
#define F_NEG       5  /* negative fixnum */
#define F_BIG       6  /* bignum */
#define F_RAT       7  /* ratio */
#define F_CPX       8  /* complex number */
#define F_FPS       9  /* short float */
#define F_FPF       10 /* single float */
#define F_FPD       11 /* double float */
#define F_FPL       12 /* long float */
#define F_SYM       13 /* symbol, general length */
#define F_ID1       14 /* symbol with 1-character name */
#define F_ID2       15 /* symbol with 2-character name */
#define F_ID3       16 /* etc */
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
#define F_IDF       28 /* symbol with 15 character name */
#define F_STR       29 /* string */
#define F_BP0       30 /* bytecode string for binary code (0 - 255 bytes) */
#define F_BP1       31 /* 256 - 511 bytes of BPS                          */
#define F_BP2       32 /* 512 - 767 bytes of BPS                          */
#define F_BP3       33 /* 768 - 1023 bytes of BPS                         */
#define F_HASH      34 /* hash table */
#define F_VEC       35 /* simple Lisp vector */
#define F_LST       36 /* list, general length */
#define F_LS1       37 /* list of length 1 */
#define F_LS2       38 /* list of length 2 */
#define F_LS3       39 /* list of length 3 */
#define F_LS4       40 /* list of length 4 */
#define F_DOT       41 /* list ending with dotted item */
#define F_QUT       42 /* (QUOTE xx) */
#define F_DEF0      43 /* function definition, 0 args */
#define F_DEF1      44 /* function definition, 1 arg */
#define F_DEF2      45 /* function definition, 2 args */
#define F_DEF3      46 /* function definition, 3 args */
#define F_DEFN      47 /* function definition, 4 or more args */
#define F_REP       48 /* followed by 2 bytes giving FP rep */
#define F_CHAR      49 /* bits, font, code */
#define F_SDEF      50 /* associated with fn definition - Lisp coded version */
#define F_STRUCT    51 /* Structure or e-vector */
#define F_DEFOPT    52 /* function definition, &optional args */
#define F_DEFHOPT   53 /* function definition, &optional args + initform */
#define F_DEFREST   54 /* function definition, &optional/&rest args */
#define F_DEFHREST  55 /* function definition, &optional/&rest + initform */
#define F_ARRAY     56 /* Common Lisp style general array */
#define F_BITVEC    57 /* Bit-vector */
#ifdef COMMON
#define F_PKGINT    58 /* abc::def (coded as m, n, c1..cm, c1..cn) */
                       /* m=0 can be used for gensyms, as in #:xxx */
#else
#define F_GENSYM    58 /* coded as n, c1..cn. Eg just like PKGINT,0 */
#endif
#define F_PKGEXT    59 /* abc:def (m=0 => keyword) */

#define F_OLD       60 /* all remaining codes denote recently seen symbols */
#define KEEP_RECENT (256 - F_OLD)

#define MAX_OBJECT 256  /* limit on symbol & number length */

#ifdef DEBUG_FASL

static char *fasl_code_names[] =
{
    "END",      "NIL",      "TRU",      "EXT",
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
    "REP",      "CHAR",     "SDEF",     "STRUCT",
    "DEFOPT",   "DEFHOPT",  "DEFREST",  "DEFHREST",
#ifdef COMMON
    "ARRAY",    "BITVEC",   "PKGINT",   "PKGEXT"
#else
    "ARRAY",    "BITVEC",   "GENSYM",   "PKGEXT"
#endif
};

static char old_name[8];

static char *fasl_code(int n)
{
    if (n >= F_OLD)
    {   sprintf(old_name, "OLD%d", n - F_OLD);
        return old_name;
    }
    else return fasl_code_names[n];
}

#endif


#define boffo_char(i) celt(boffo, i)

static int fp_rep = 0; /* representation used when FASL file was written */

static Lisp_Object fastread(void);

#ifdef COMMON
static char package_name[256];
#endif

#ifdef DEBUG_FASL

static int IgetcDebug()
{
    int k = Igetc();
    trace_printf("Igetc = %d/%.2x/%s\n", k, k, fasl_code(k));
    return k;
}

#define Igetc() IgetcDebug()

static int IreadDebug(char *x, int n)
{
    int i;
    int k = Iread(x, n);
    trace_printf("Iread(%d) = %d:", n, k);
    for (i=0; i<k; i++)
    {   trace_printf(" %d/%x", x[i], x[i]);
        if (32 <= x[i] && x[i] < 0x7f) trace_printf("/'%c'", x[i]);
    }
    trace_printf("\n");
    return k;
}

#define Iread(a, n) IreadDebug(a, n)

#endif

static Lisp_Object fastread1(int32_t ch, int32_t operand)
{
    Lisp_Object nil = C_nil;
    Lisp_Object r = nil, w;
#ifdef COMMON
    int operand0;
#endif
    int32_t p;
    switch (ch)
    {
default:                        /* a recently-mentioned item */
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
            if (skipping_input == 2) r = nil;
            else if (ch == F_PKGINT)
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
/*
 * The KEEP_RECENT most recently used symbols are stored in a cyclic buffer
 * so that if re-used they will be rapidly available. See comment under
 * F_GENSYM for a delicacy here.
 */
            if (skipping_input == 0 ||
                (ch == F_PKGINT && operand0 == 0)) /* NB keep gensyms! */
            {   recent_pointer++;
                if (recent_pointer == KEEP_RECENT) recent_pointer = 0;
                w = elt(faslvec, recent_pointer);
                if (qpackage(w) == nil) /* eg a gensym */
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
#else /* COMMON */
case F_GENSYM:
        {   int ch1 = Igetc();
            if (ch1 == EOF) return aerror("premature EOF in FASL file");
            operand = (operand << 8) + ((int32_t)ch1 & 0xff);
            if (Iread(&boffo_char(0), operand) != operand)
                return aerror("FASL file corrupted");
            fasl_byte_count += operand;
            if (skipping_input == 2) r = nil;
            r = iintern(boffo, (int32_t)operand, CP, 0);
            errexit();
            r = Lgensym2(nil, r);
            errexit();
/*
 * The KEEP_RECENT most recently used symbols are stored in a cyclic buffer
 * so that if re-used they will be rapidly available. Note as a real curiosity
 * then gensyms will be stored in this even if skipping_input is non-zero.
 * this is essential so that gensyms within saved-definitions are
 * can get processed properly. Specifically so that repeated use of a gensym
 * within a saved definition leads to two references to the same thing
 * rather than to the creation of two new gensyms.  The same issue should
 * arise for un-interned Common Lisp symbols.
 */
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
#endif /* COMMON */
                                /* these all have a 1-byte arg to follow */
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
        {
    default:                    /* can never occur */

    case F_INT:                 /* positive fixnum */
            return fixnum_of_int(operand);

    case F_NEG:                 /* negative fixnum */
            return fixnum_of_int(-operand);

    case F_BIG:
            r = getvector(TAG_NUMBERS, TYPE_BIGNUM, CELL+operand);
            /* I tidy up the padding word if needbe */
            if ((((operand & 4) != 0) && SIXTY_FOUR_BIT) ||
                (((operand & 4) == 0) && !SIXTY_FOUR_BIT))
                *(int32_t *)((char *)r + CELL + 4 - TAG_NUMBERS + operand) = 0;
/*
 * I accumulate the numeric components of the bignum here by steam - one
 * byte at a time - so that fasl files made on a machine with one byte-order
 * can be used on machines with the other.  I do not expect that there
 * will be many bignums in fasl files, and thus this is not a performance
 * critical area.
 */
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

    case F_SYM:                 /* n characters making a symbol */
            if (Iread(&boffo_char(0), operand) != operand)
                return aerror("FASL file corrupted");
            fasl_byte_count += operand;
/*
 * skipping_input is usually zero.  If it is 1 then I read in expressions
 * as normal save that I do not update the recently-mentioned-symbol cache.
 * skipping_input==2 causes me to parse the input FASL file but not
 * return a useful result.  Well actually everything will be read in
 * as normal save that symbols will all be mapped onto NIL.
 */
            if (skipping_input == 2) r = nil;
            else r = iintern(boffo, operand, CP, 0);
            errexit();
/*
 * The KEEP_RECENT most recently used symbols are stored in a cyclic buffer
 * so that if re-used they will be rapidly available.
 */
            if (skipping_input == 0)
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

    case F_STR:                 /* n characters making a string */
            r = getvector(TAG_VECTOR, TYPE_STRING, CELL+operand);
            errexit();
            {   char *s = (char *)r - TAG_VECTOR + CELL;
                int l = operand & 7;
                if (SIXTY_FOUR_BIT)
                {   switch (l)
                    {
                case 1:
                case 2:
                case 3: *(int32_t *)(s + operand - l) = 0; 
                case 4:
                case 5:
                case 6:
                case 7: *(int32_t *)(s + operand - l + 4) = 0;     
                case 0: break;
                    }
                }
                else
                {   switch (l)
                    {
                case 5:
                case 6:
                case 7: *(int32_t *)(s + operand - l + 8) = 0;
                case 0:
                case 1:
                case 2:
                case 3: *(int32_t *)(s + operand - l + 4) = 0;
                case 4: break;
                    }
                }
                if (Iread(s, operand) != operand)
                    return aerror("FASL file corrupted");
                fasl_byte_count += operand;
            }
            return r;

    case F_BP3:                 /* n + 768 bytes of BPS */
            operand += 256;
            /* drop through */
    case F_BP2:                 /* n + 512 bytes of BPS */
            operand += 256;
            /* drop through */
    case F_BP1:                 /* n + 256 bytes of BPS */
            operand += 256;
            /* drop through */
    case F_BP0:                 /* n bytes making BPS */
/* See the other place where qvalue(savedef) == savedef is tested. */
            if (qvalue(savedef) == savedef)
            {   int32_t i;
                for (i=0; i<operand; i++) Igetc();
                fasl_byte_count += operand;
                return nil;
            }
            else
            {   r = getcodevector(TYPE_BPS, operand+CELL);
                errexit();
                if (Iread(data_of_bps(r), operand) != operand)
                    return aerror("FASL file corrupted");
                fasl_byte_count += operand;
                return r;
            }
    case F_HASH:
    case F_STRUCT:
    case F_VEC:                 /* normal vector with n entries */
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
/*
 * If I have just read in a hash table that was built on EQ or EQL I will
 * need to rehash it now.
 */
                if (elt(r, 0) == fixnum_of_int(0) ||
                    elt(r, 0) == fixnum_of_int(1) ||
                    !is_fixnum(elt(r, 0)))
                {   Lisp_Object v;
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

    case F_LST:                 /* build list of length n */
    case F_DOT:                 /* dotted list with n values */
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

static CSLbool just_reading_source = NO;

static Lisp_Object fastread(void)
{
    int32_t operand = 0, ch = Igetc();
    Lisp_Object nil = C_nil;
    Lisp_Object r = nil, w;
    fasl_byte_count++;
    if (ch == EOF) return aerror("premature EOF in FASL file");
    ch &= 0xff;
    for (;;)
    {
        switch (ch)
        {
    case F_END:                     /* marks end of file */
            return CHAR_EOF;

    case F_NIL:                     /* represents the value NIL */
            return nil;

    case F_TRU:                     /* represents the value T */
            return lisp_true;

    case F_QUT:                     /* (QUOTE <next thing>) */
            r = fastread();
            errexit();
            return list2(quote_symbol, r);

    case F_SDEF:
/*
 * I am THINKING about an option that avoids reading in definitions here
 * when *SAVEDEF is nil, and just skips the bytes in the FASL file.  The
 * problem with doing so is that of the table of recently referred to
 * symbols - which must be kept in step between FASL writing and reading
 * whether or not *SAVEDEF is active.
 */
            if (qvalue(savedef) == nil) skipping_input = 2;
            else skipping_input = 1;
            r = fastread();
            skipping_input = 0;
            errexit();
            ch = Igetc();
            fasl_byte_count++;
            if (ch == EOF) return aerror("premature EOF in FASL file");
            ch &= 0xff;
            /* And drop through */
    case F_DEF0:                    /* introduces defn of compiled code */
    case F_DEF1:
    case F_DEF2:
    case F_DEF3:
    case F_DEFN:
    case F_DEFOPT:
    case F_DEFHOPT:
    case F_DEFREST:
    case F_DEFHREST:
            {   Lisp_Object name, bps, env;
                push(r);
                name = fastread();
                pop(r);
                errexit();
                push(name);
                if (qvalue(savedef) != nil)
                {
                    if (just_reading_source)
                    {   Lisp_Object w;
#ifdef COMMON
                        w = get(name, loadsource_symbol, nil);
#else
                        w = get(name, loadsource_symbol);
#endif
                        if (w == nil &&
                            qvalue(loadsource_symbol) != nil) w = lisp_true;
                        if (w != nil)
                        {   Lisp_Object w1, chk = w;
                            CSLbool include = YES;
                            push3(chk, name, r);
                            if (consp(w))
                            {   if (integerp(qcar(w)))
                                {   chk = qcar(w);
                                    w = list2star(qcar(w),
                                                  current_module, qcdr(w));
                                }
                                else w = cons(current_module, w);
                            }
                            else
                            {   if (integerp(w)) w = list2(w, current_module);
                                else w = ncons(current_module);
                            }
                            pop3(r, name, chk);
                            errexit();
/*
 * If the load-source property is an integer then the source is only
 * loaded if the definition concerned matched that as an MD5 checksum.
 * (well actually I compute MD5 then truncate the digest to 60 bits).
 * (I allow a property (integer ...) too).
 * If load-source started off as just T then the last definition loaded
 * will be the one that survives, but the load-source property will
 * be replaced by a list of the modules that provided definitions (which
 * may or may not be conflicting ones).
 */
                            if (integerp(chk) != nil && consp(r))
                            {   push4(name, r, chk, w);
                                w1 = Lmd60(nil, qcdr(r));
                                pop4(w, chk, r, name);
                                errexit();
                                push4(name, r, chk, w);
                                include = numeq2(w1, chk);
#ifdef DEBUG_FASL
                                prin_to_trace(name); trace_printf("\n");
                                prin_to_trace(r);    trace_printf("\n");
                                prin_to_trace(w1);   trace_printf("\n");
                                prin_to_trace(w);    trace_printf("\n");
                                prin_to_trace(chk);  trace_printf("\n");
                                trace_printf(" MD5 equality = %d\n", include);
#endif
                                pop4(w, chk, r, name);
                                errexit();
                            }
#ifdef DEBUG_FASL
                            else trace_printf("simple case\n");
#endif
                            if (include)
                            {   push2(name, r);
                                putprop(name, loadsource_symbol, w);
#ifdef DEBUG_FASL
                                trace_printf("record sourceloc\n");
#endif
                                pop2(r, name);
                                errexit();
#ifdef DEBUG_FASL
                                trace_printf("record savedef\n");
#endif
                                push2(name, r);
/* here I build up a list of the functions whose definitions were loaded */
                                w1 = cons(name, qvalue(work_symbol));
                                pop2(r, name);
                                errexit();
                                qvalue(work_symbol) = w1;
                                putprop(name, savedef, r);
                            }
                        }
                    }
                    else putprop(name, savedef, r);
                    errexit();
                }
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
                        {
                case F_DEF0: switch (nn)
                             {
                         case 0: set_fns(name, wrong_no_na, wrong_no_nb, f0_as_0);
                                 break;
                         default:goto bad_tail;
                             }
                             break;
                case F_DEF1: switch (nn)
                             {
                         case 0: set_fns(name, f1_as_0, too_many_1, wrong_no_1);
                                 break;
                         case 1: set_fns(name, f1_as_1, too_many_1, wrong_no_1);
                                 break;
                         default:goto bad_tail;
                             }
                             break;
                case F_DEF2: switch (nn)
                             {
                         case 0: set_fns(name, too_few_2, f2_as_0, wrong_no_2);
                                 break;
                         case 1: set_fns(name, too_few_2, f2_as_1, wrong_no_2);
                                 break;
                         case 2: set_fns(name, too_few_2, f2_as_2, wrong_no_2);
                                 break;
                         default:goto bad_tail;
                             }
                             break;
                case F_DEF3: switch (nn)
                             {
                         case 0: set_fns(name, wrong_no_na, wrong_no_nb, f3_as_0);
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
                             {
                         default:goto bad_tail;
                             }
                             break;
                case F_DEFOPT:
                             switch (nn)
                             {
                         default:goto bad_tail;
                             }
                             break;
                case F_DEFHOPT:
                             switch (nn)
                             {
                         default:goto bad_tail;
                             }
                             break;
                case F_DEFREST:
                             switch (nn)
                             {
                         default:goto bad_tail;
                             }
                             break;
                case F_DEFHREST:
                             switch (nn)
                             {
                         default:goto bad_tail;
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
/*
 * If the variable !*savedef has !*savedef as its value I will not instate
 * function definitions here at all.  This is a very odd thing to do, but
 * turns out to help me save memory when I want to load FASL files in order
 * to retrieve the Lisp form of definitions but I do not really want the
 * code present instated.
 */
                if (qvalue(savedef) != savedef)
                {   switch (ch)
                    {
            case F_DEF0: set_fns(name, wrong_no_0a, wrong_no_0b,
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
            /* DROP THROUGH */
    case F_LS3:
            push(r);
            w = fastread();
            pop(r);
            errexit();
            r = cons(w, r);
            errexit();
            /* DROP THROUGH */
    case F_LS2:
            push(r);
            w = fastread();
            pop(r);
            errexit();
            r = cons(w, r);
            errexit();
            /* DROP THROUGH */
    case F_LS1:
            push(r);
            w = fastread();
            pop(r);
            errexit();
            r = cons(w, r);
            errexit();
            return r;

    case F_CHAR:
/*
 * Note that in Kanji mode the interpretation here should be that the 16 bit
 * character code is specified by bits/code. I ensure that when FASL files
 * are written this arrangement holds.
 */
            {   int32_t bits, font, code;
                bits = Igetc();
                fasl_byte_count++;
                if (bits == EOF) return aerror("premature EOF in FASL file");
                font = Igetc();
                fasl_byte_count++;
                if (font == EOF) return aerror("premature EOF in FASL file");
                code = Igetc();
                fasl_byte_count++;
                if (code == EOF) return aerror("premature EOF in FASL file");
                return pack_char(bits, font & 0xff, code & 0xff);
            }

    case F_REP:
            {   int c1, c2;
                c1 = Igetc();
                fasl_byte_count++;
                if (c1 == EOF) return aerror("premature EOF in FASL file");
                c2 = Igetc();
                fasl_byte_count++;
                if (c2 == EOF) return aerror("premature EOF in FASL file");
                fp_rep = (c1 & 0xff) + ((c2 & 0xff) << 8);
                ch = Igetc();
                fasl_byte_count++;
                if (ch == EOF) return aerror("premature EOF in FASL file");
                ch &= 0xff;
                continue;
            }

#ifdef COMMON
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
            {   Lisp_Object w1;
                if (Iread((char *)&w1, 4) != 4)
                    return aerror("FASL file corrupted");
                fasl_byte_count += 4;
                convert_fp_rep(&w1, fp_rep, current_fp_rep, 0);
                return w1;
            }

    case F_FPF:
            r = getvector(TAG_BOXFLOAT, TYPE_SINGLE_FLOAT,
                          sizeof(Single_Float));
            errexit();
            if (Iread((char *)r + CELL - TAG_BOXFLOAT, 4) != 4)
                return aerror("FASL file corrupted");
            fasl_byte_count += 4;
            convert_fp_rep((char *)r + CELL - TAG_BOXFLOAT,
                           fp_rep, current_fp_rep, 1);
            return r;
#endif

    case F_FPD:
            r = getvector(TAG_BOXFLOAT, TYPE_DOUBLE_FLOAT,
                          SIZEOF_DOUBLE_FLOAT);
            errexit();
/* zero out the padding word if there is one! */
            *(int32_t *)((char *)r + CELL - TAG_BOXFLOAT) = 0;
            if (Iread((char *)r + 8 - TAG_BOXFLOAT, 8) != 8)
                return aerror("FASL file corrupted");
            fasl_byte_count += 8;
            convert_fp_rep((char *)r + 8 - TAG_BOXFLOAT,
                           fp_rep, current_fp_rep, 2);
            return r;

#ifdef COMMON
    case F_FPL:
            r = getvector(TAG_BOXFLOAT, TYPE_LONG_FLOAT, SIZEOF_LONG_FLOAT);
            errexit();
/* zero out the padding word if there is one! */
            *(int32_t *)((char *)r + CELL - TAG_BOXFLOAT) = 0;
            if (Iread((char *)r + 8 - TAG_BOXFLOAT, 8) != 8)
                return aerror("FASL file corrupted");
            fasl_byte_count += 8;
/* Beware offset of 8 here if long floats -> 3 words */
            convert_fp_rep((char *)r + 8 - TAG_BOXFLOAT,
                           fp_rep, current_fp_rep, 3);
            return r;
#endif

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
            if (skipping_input == 2) r = nil;
            else r = iintern(boffo, operand, CP, 0);
            errexit();
/*
 * The KEEP_RECENT most recently used symbols are stored in a cyclic buffer
 * so that if re-used they will be rapidly available.
 */
            if (skipping_input == 0)
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

    case F_EXT:                 /* extend effective range of operand */
            {   int ch1 = Igetc();
                fasl_byte_count++;
                if (ch1 == EOF) return aerror("premature EOF in FASL file");
                operand = (operand << 8) + ((int32_t)ch1 & 0xff);
            }
            ch = (int32_t)Igetc();
            fasl_byte_count++;
            if (ch == EOF) return aerror("premature EOF in FASL file");
            ch &= 0xff;
            continue;           /* dispatch again on next byte */

    default:
            return fastread1(ch, operand);
        }
    }
}

static char *trim_module_name(char *name, int32_t *lenp)
{
   int len = *lenp, len1;
   len1 = len - 1;
/*
 * Firstly I will decrease the length of the string if there is a "."
 * towards the end.
 */
   while (len1 > 0 && name[len1] != '.')
   {   if (name[len1] == '/' || name[len1] == '\\')
       {   len1 = len;
           break;
       }
       len1--;
   }
   if (len1 > 0) len = len1;
/*
 * Now I will try to remove any prefix that ends in "/" or "\".
 * Through all this I will attempt to leave SOMETHING over from "silly"
 * inputs such as ".....", but exactly what happens in such cases does not
 * bother me much!
 */
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

Lisp_Object Lcopy_module(Lisp_Object nil, Lisp_Object file)
/*
 * copy-module will ensure that the output PDS contains a copy of
 * the module that is named. As a special case (copy-module nil) will
 * copy the help data "module". There is no provision for copying
 * startup banner data - that must be set up by hand.
 */
{
    Header h;
    int32_t len;
    char *modname;
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "copy-module"
 */
    if (socket_server != 0) return onevalue(nil);
#endif
    if (file == nil) Icopy(NULL, 0);
    else
    {   if (symbolp(file))
        {   file = get_pname(file);
            errexit();
            h = vechdr(file);
        }
        else if (!is_vector(file) ||
             type_of_header(h = vechdr(file)) != TYPE_STRING)
            return aerror("copy-module");
        len = length_of_header(h) - CELL;
        modname = (char *)file + CELL - TAG_VECTOR;
#ifdef TRIM_MODULE_NAMES
        modname = trim_module_name(modname, &len);
#endif
        Icopy(modname, (int)len);
    }
    return onevalue(nil);
}

Lisp_Object Lcopy_native(Lisp_Object nil, Lisp_Object src, Lisp_Object dest)
/*
 * (copy-native external-file internal-name)
 * copies (binary) data from the named external file to a module with
 * the specified name. This will mostly be used for native code and is
 * not really expected to make sense to normal end-users.
 */
{
    Header h;
    int32_t len;
    char *modname, *w;
    char filename[LONGEST_LEGAL_FILENAME];
    FILE *srcfile;
    int c;
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "copy-native"
 */
    if (socket_server != 0) return onevalue(nil);
#endif

    w = get_string_data(src, "copy-native", &len);
    nil = C_nil;
    if (exception_pending()) return nil;
    if (len >= sizeof(filename)) len = sizeof(filename);
    srcfile = open_file(filename, w,
                        (size_t)len, "rb", NULL);
    if (srcfile == NULL)
    {   error(1, err_open_failed, src);
        return onevalue(nil);
    }
    if (symbolp(dest))
    {   dest = get_pname(dest);
        errexit();
        h = vechdr(dest);
    }
    else if (!is_vector(dest) ||
        type_of_header(h = vechdr(dest)) != TYPE_STRING)
        return aerror("copy-module");
    len = length_of_header(h) - CELL;
    modname = (char *)dest + CELL - TAG_VECTOR;
/*
 * Unlike the case of copy_module I will demand that the module name
 * here be handed down in exactly the form required...
 */
    if (open_output(modname, (int)len)) return onevalue(nil);
/*
 * OK, now the output module is open for writing... now Iputc(int) can
 * plant bytes, returning true if trouble, or Iwrite(char *, int) can write
 * a block of bytes.
 */
    while ((c = getc(srcfile)) != -1) Iputc(c);
    fclose(srcfile);
/*
 * After writing the stuff I go IcloseOutput(0) where the arg 0 indicates that
 * I will not want a checksum planted.
 */
    if (IcloseOutput(0)) return onevalue(nil);
/* return T on success */
    return onevalue(lisp_true);
}

Lisp_Object Ldelete_module(Lisp_Object nil, Lisp_Object file)
/*
 * delete-module deletes the named module from the output PDS, supposing it
 * was there to begin with.  (delete-module nil) deletes any help data.
 */
{
    Header h;
    int32_t len;
    char *modname;
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "delete-module"
 */
    if (socket_server != 0) return onevalue(nil);
#endif
    if (file == nil) Idelete(NULL, 0);
    else
    {   if (symbolp(file))
        {   file = get_pname(file);
            errexit();
            h = vechdr(file);
        }
        else if (!is_vector(file) ||
             type_of_header(h = vechdr(file)) != TYPE_STRING)
            return aerror("delete-module");
        len = length_of_header(h) - CELL;
        modname = (char *)file + CELL - TAG_VECTOR;
#ifdef TRIM_MODULE_NAMES
        modname = trim_module_name(modname, &len);
#endif
        Idelete(modname, (int)len);
    }
    return onevalue(nil);
}

Lisp_Object Lbanner(Lisp_Object nil, Lisp_Object info)
/*
 * (startup!-banner nil)      returns the current banner info (nil if none)
 * (startup!-banner "string") sets new info
 * (startup!-banner "")       deletes any that there is.
 */
{
    Header h;
    int i;
    int32_t len;
    char *name;
    Ihandle save;
    if (info == nil)
    {   char b[64];
        Icontext(&save);
        if (Iopen_banner(0))
        {   Irestore_context(save);
            return onevalue(nil);
        }
        for (i=0; i<64; i++)
            b[i] = (char)Igetc();
        IcloseInput(NO);
        Irestore_context(save);
        info = make_string(b);
        errexit();
        return onevalue(info);
    }
#ifdef SOCKETS
/*
 * Security measure - remote client can not change banner info
 */
    if (socket_server != 0) return onevalue(nil);
#endif
    if (symbolp(info))
    {   info = get_pname(info);
        errexit();
        h = vechdr(info);
    }
    else if (!is_vector(info) ||
         type_of_header(h = vechdr(info)) != TYPE_STRING)
        return aerror("banner");
    len = length_of_header(h) - CELL;
    name = (char *)info + CELL - TAG_VECTOR;
    if (len == 0) Iopen_banner(-2); /* delete banner info */
    else
    {
/*
 * The following writes to the current output image. Well that is not
 * always nice, and in particular I do not want "just" updating the banner
 * to create an image file that had otherwise been in "pending" state. So
 * the implementation of Iopen_banner(-1) will report failure in that
 * case rather than creating a fresh image file.
 */
        Icontext(&save);
        if (Iopen_banner(-1))
        {   Irestore_context(save);
            return onevalue(nil);
        }
        if (len > 63) len = 63;
        for (i=0; i<64; i++) Iputc(i >= len ? 0 : name[i]);
        IcloseOutput(1);
        Irestore_context(save);
    }
    return onevalue(lisp_true);
}

Lisp_Object MS_CDECL Llist_modules(Lisp_Object nil, int nargs, ...)
/*
 * display information about available modules
 */
{
    argcheck(nargs, 0, "list-modules");
    Ilist();
    return onevalue(nil);
}

Lisp_Object Lwritable_libraryp(Lisp_Object nil, Lisp_Object file)
/*
 * This tests if a library handle refers to a writable file.
 */
{
    int i;
    directory *d;
    if ((file & 0xffff) != SPID_LIBRARY) return onevalue(nil);
    i = (file >> 20) & 0xfff;
    d = fasl_files[i];
    i = d->h.updated;
    return onevalue(Lispify_predicate(i & D_WRITE_OK));
}

static Lisp_Object load_module(Lisp_Object nil, Lisp_Object file,
                               int sourceonly)
/*
 * load_module() rebinds *package* in COMMON mode, but also note that
 * it DOES rebind a whole load of variables so that loading one module
 * can be done while in the process of loading another.
 * also rebinds *echo to nil in case we are reading from a stream.
 */
{
    char filename[LONGEST_LEGAL_FILENAME];
    Header h;
    int32_t len;
    Ihandle save;
    Lisp_Object v;
    CSLbool from_stream = NO;
    int close_mode;
    char *modname;
    int32_t save_recent = recent_pointer,
          save_byte_count = fasl_byte_count;
#ifdef NAG
    char *ptr;
    int32_t old_symbol_protect_flag;
#endif

    if (is_stream(file)) h=0, from_stream = YES;
    else if (symbolp(file))
    {   file = get_pname(file);
        errexit();
        h = vechdr(file);
    }
    else if (!is_vector(file) ||
         type_of_header(h = vechdr(file)) != TYPE_STRING)
        return aerror("load-module");
    current_module = file;
    if (from_stream)
    {   Icontext(&save);
        if (Iopen_from_stdin())
        {   err_printf("Failed to load module from stream\n");
            Irestore_context(save);
            return error(1, err_no_fasl, file);
        }
        push(qvalue(standard_input));
        qvalue(standard_input) = file;
        push(qvalue(echo_symbol));
        qvalue(echo_symbol) = nil;
    }
    else
    {   len = length_of_header(h) - CELL;
        modname = (char *)file + CELL - TAG_VECTOR;
        modname = trim_module_name(modname, &len);
        Icontext(&save);
        if (Iopen(modname, (int)len, IOPEN_CHECKED, filename))
        {   err_printf("Failed to find \"%s\"\n", filename);
            Irestore_context(save);
            return error(1, err_no_fasl, file);
        }
    }
    v = getvector_init(CELL*(KEEP_RECENT+1), nil);
    nil = C_nil;
    if (exception_pending())
    {   IcloseInput(NO);
        Irestore_context(save);
        if (from_stream)
        {   flip_exception();
            pop(qvalue(echo_symbol));
            pop(qvalue(standard_input));
            flip_exception();
        }
        return nil;
    }
    push(qvalue(work_symbol));
    qvalue(work_symbol) = nil; /* list of functions loaded in source form */
/*
 * I will account time spent fast-loading things as "storage management"
 * overhead to be counted as "garbage collector time" rather than
 * regular "cpu time"
 */
    push_clock();
    if (verbos_flag & 2)
    {   freshline_trace();
        if (sourceonly)
        {   if (from_stream) trace_printf("Loading source from a stream\n");
            else trace_printf("Loading source for \"%s\"\n", filename);
        }
        else
        {   if (from_stream) trace_printf("Fast-loading from a stream\n");
            else trace_printf("Fast-loading \"%s\"\n", filename);
        }
    }

#ifdef NAG
/* 
 * This next bit is designed to ensure that, under the default configuration,
 * the user can overwrite bits of the system that are re-defined in the kernel, 
 * but loading the Lisp versions from a "standard" image file will have no
 * effect.  This is totally AXIOM dependent!
 */
    old_symbol_protect_flag = symbol_protect_flag;
    ptr = strrchr(filename, '/');
/* /* BEWARE for Axiom purposes!!!!!!!! */
    if (ptr && strlen(ptr) > 5 && strncmp(ptr+1,"axiom",5) == 0) 
        symbol_protect_flag = 1;
#endif
    push(CP);
    push(faslvec);
    faslvec = v;
    push(faslgensyms);
    faslgensyms = nil;
    push(qvalue(savedef));
    if (sourceonly) qvalue(savedef) = savedef;
    just_reading_source = sourceonly;
    recent_pointer = 0;
    fasl_byte_count = 0;
    skipping_input = 0;
    for (;;)
    {   Lisp_Object r = fastread();
        nil = C_nil;
        if (exception_pending() || r == CHAR_EOF) break;
#ifdef DEBUG_FASL
        trace_printf("FASL: ");
        loop_print_trace(r);
        trace_printf("\n");
#endif
        if (!sourceonly) voideval(r, nil);
        nil = C_nil;
        if (exception_pending()) break;
    }
    close_mode = YES;
    if (exception_pending()) flip_exception(), close_mode = NO;
    pop(qvalue(savedef));
    pop(faslgensyms);
    pop(faslvec);
    pop(CP);
    if (sourceonly) file = qvalue(work_symbol);
    else file = nil;
    pop(qvalue(work_symbol));
/* If something already smashed there is no joy in checking the checksum */
    push(file);
    IcloseInput(close_mode);
    Irestore_context(save);
#ifdef NAG
    symbol_protect_flag = old_symbol_protect_flag;
#endif
    pop(file);
    if (from_stream)
    {   pop(qvalue(echo_symbol));
        pop(qvalue(standard_input));
    }
    recent_pointer = save_recent;
    fasl_byte_count = save_byte_count;
    gc_time += pop_clock();
    if (!close_mode)
    {   flip_exception();
        return nil;
    }
    return onevalue(file);
}

Lisp_Object Lload_source(Lisp_Object nil, Lisp_Object file)
{
    return load_module(nil, file, 1);
}

Lisp_Object Lload_module(Lisp_Object nil, Lisp_Object file)
{
    return load_module(nil, file, 0);
}

#ifdef DEBUG_FASL

static void IputcDebug(int c, int line)
{
    Iputc(c);
    trace_printf("Iputc(%d/%x/%s: %d %.8x %.8x)\n", c, c, fasl_code(c),
        line, C_stack, C_nil);
}

#define Iputc(c) IputcDebug(c, __LINE__)

#endif


static void out_fasl_prefix(int32_t n)
/*
 * Used to generate any prefixes to cope with large operands in
 * FASL streams
 */
{
    if (n != 0)
    {   out_fasl_prefix(n >> 8);
        Iputc(F_EXT);
        Iputc((int)(n & 0xff));
    }
}

Lisp_Object Lmodule_exists(Lisp_Object nil, Lisp_Object file)
{
    char filename[LONGEST_LEGAL_FILENAME], tt[32];
    Header h;
    int32_t len;
    int32_t size;
    char *modname;
    if (symbolp(file))
    {   file = get_pname(file);
        errexit();
        h = vechdr(file);
    }
    else if (!is_vector(file) ||
         type_of_header(h = vechdr(file)) != TYPE_STRING)
        return aerror("modulep");
    len = length_of_header(h) - CELL;
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

Lisp_Object Lstart_module(Lisp_Object nil, Lisp_Object name)
/*
 * This must be called before write-module - it resets the table of recently-
 * mentioned identifiers to be empty.  Calling with a nil argument
 * closes the current fasl file, otherwise the arg is the name of
 * a file to open.  It is not intended that ordinary programmers call
 * this function - it is for use from within the compiler.
 * As a special bit of magic the name passed can be a Lisp stream, in
 * which case the module data will be written to it.
 */
{
    Lisp_Object w;        
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "FASLOUT" & start-module
 */
    if (socket_server != 0) return onevalue(nil);
#endif

    recent_pointer = 0;
    skipping_output = 0;
    fp_rep_set = NO;
    if (name == nil)
    {   if (fasl_output_file)
        {   int k = (int)Ioutsize() & 0x3;
/*
 * Here I arrange that all FASL modules will end up being a multiple of
 * 4 bytes long.  "WHY?"  Well I once suffered from a machine that was not
 * very good at supporting odd-length data transfers (the suggestion I
 * collected is that it MAY be because I had an early version of an 80386 CPU
 * chip installed). The padding up here is not very painful and may avoid
 * some painful trouble on my machine (and hence maybe on some other ones).
 * The machine concerned is a PC and the chip and 80386, just in case you
 * wondered.  Zortech technical support were very helpful trying to
 * track down the crashes I was having - even had they provided a software
 * work-around in their code at some time I should leave this code and comment
 * in CSL.
 * Note (June 1992) I now have a computer with a newer CPU chip in it and
 * the problem mentioned above does not arise - but it still seems reasonable
 * to keep modules a multiple of 4 bytes long.
 * Note (October 1995) Well, now I have a Pentium rather than a 386, and
 * my previous 80486 system has gone down the feeding chain to replace the
 * old and dodgy 80386. So sometime within the next year or so I will
 * remove this comment, but still leave modules padded to multiples of
 * 4 bytes since maybe I would introduce more bugs removing that than I would
 * save.
 * (January 1999) This little essay continues to entertain me. The 386 system
 * happens to be around Cambridge again as a "relic" having been discarded as
 * too old-fashioned and slow by pretty well everybody! Gosh how machines
 * change during the life-time of a piece of software!
 * (March 2001) "early 386" bug hah. Gosh that was slow by today's standards.
 * (August 2008) !!!!!!!
 */
            while (k != 3) k++, Iputc(F_NIL);
            Iputc(F_END);
            IcloseOutput(1);
            faslvec = nil;
            faslgensyms = nil;
            fasl_output_file = NO;
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
        fasl_output_file = YES;
        Iopen_to_stdout(); /* initialises checksum calculation */
        return onevalue(lisp_true);
    }
    else
    {   char filename[LONGEST_LEGAL_FILENAME];
        char *modname;
        int32_t len;
        Header h;
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
        else if (type_of_header(h = vechdr(name)) != TYPE_STRING)
            return aerror("start-module");
        len = length_of_header(h) - CELL;
        modname = (char *)name + CELL - TAG_VECTOR;
/*
 * Here I will play jolly games! The name as passed in to start-module will
 * be allowed to be a fairly general file-name. If there is a suffix of the
 * form ".xxx" on the end I will strip that off. If there is a directory-
 * style component before that (as signalled by having a "/" or a "\" or
 * another "." within the name) I will trim that off too. So the input
 * string "/home/xxx/something.fsl" (say) would be treated exactly as if
 * it had been just "something".
 */
        modname = trim_module_name(modname, &len);
        if (len >= sizeof(filename)) len = sizeof(filename);
        if (Iopen(modname, (int)len, IOPEN_OUT, filename))
        {   err_printf("Failed to open \"%s\"\n", filename);
            return onevalue(nil);
        }
        fasl_output_file = YES;
        return onevalue(lisp_true);
    }
}

Lisp_Object Ldefine_in_module(Lisp_Object nil, Lisp_Object a)
{
    int32_t args, opts, ntail;
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "define-in-module"
 */
    if (socket_server != 0) return onevalue(nil);
#endif
    if (!is_fixnum(a)) return aerror("define-in-module");
    if (a == fixnum_of_int(-1))
    {   Iputc(F_SDEF);
/*
 * An expression preceeded with F_SDEF will be loaded again only if
 * the variable "*savedef" is true at the time of loading, or if
 * the load-source function is called and the function whose definition
 * is involved has a load-source property.
 */
        skipping_output = 1;
        return onevalue(nil);
    }
    skipping_output = 0;
    args = int_of_fixnum(a);
    opts = args >> 8;
    ntail = opts >> 10;
    if (ntail != 0) 
        return aerror("tailcall magic not supported in FASL files yet");
    opts &= 0x3ff;
    if (opts == 0) switch (args & 0xff)
    {
case 0: Iputc(F_DEF0);
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
    {
default:
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

static void IwriteDebug(char *x, int n, int line)
{
    int i;
    Iwrite(x, n);
    trace_printf("Iwrite %d %.8x %.8x", line, C_nil, C_stack);
    for (i=0; i<n ;i++)
    {   trace_printf(" %d/%x", x[i], x[i]);
        if (32 <= x[i] && x[i] < 0x7f) trace_printf("/'%c'", x[i]);
    }
    trace_printf("\n");
}

#define Iwrite(x, n) IwriteDebug(x, n, __LINE__)

#endif

static Lisp_Object write_module0(Lisp_Object nil, Lisp_Object a);

static Lisp_Object write_module1(Lisp_Object a)
{
    Lisp_Object nil = C_nil;
    if (is_bfloat(a))
    {   Header h = flthdr(a);
        if (!fp_rep_set)
        {   fp_rep_set = YES;
            Iputc(F_REP);
            Iputc(current_fp_rep & 0xff);
            Iputc((current_fp_rep >> 8) & 0xff);
        }
        switch (type_of_header(h))
        {
    default:
            return aerror("unrecognized FP number type");
#ifdef COMMON
    case TYPE_SINGLE_FLOAT:
            Iputc(F_FPF);
            Iwrite((char *)a + CELL - TAG_BOXFLOAT, 4);
            break;
#endif
    case TYPE_DOUBLE_FLOAT:
            Iputc(F_FPD);
            /* nb offset here is 8 in both 32 and 64 bit modes */
            Iwrite((char *)a + 8L - TAG_BOXFLOAT, 8);
            break;
#ifdef COMMON
    case TYPE_LONG_FLOAT:
            Iputc(F_FPL);
            Iwrite((char *)a + 8 - TAG_BOXFLOAT, 8);
            break;
#endif
        }
    }
    else if (is_char(a))
    {   Iputc(F_CHAR);
/*
 * Note that for somewhat dubious reasons I have separated out the
 * end of file character earlier on and treated it oddly.
 */
        Iputc((int)bits_of_char(a));
        Iputc((int)font_of_char(a));
        Iputc((int)code_of_char(a));
    }
    else if (is_bps(a))
    {   char *d = data_of_bps(a);
        int32_t len = length_of_header(*(Header *)(d - CELL)) - CELL;
        switch (len >> 8)
        {
    case 3: Iputc(F_BP3);
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
    case TYPE_STRING:
            out_fasl_prefix(len >> 8);
            Iputc(F_STR);
            Iputc((int)(len & 0xff));
            Iwrite((char *)a + CELL - TAG_VECTOR, len);
            break;

    case TYPE_HASH:      /* Writing these may be easy... */
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
/*
 * The explicit enumeration of left-over cases is here ready for when
 * (or if!) I ever decide to extend the FASL format to support these
 * extra types.  Until I do please note that Common Lisp arrays and
 * bit-vectors can not be coped with here.
 */
#ifdef COMMON
    case TYPE_ARRAY:
    case TYPE_BITVEC1:
    case TYPE_BITVEC2:
    case TYPE_BITVEC3:
    case TYPE_BITVEC4:
    case TYPE_BITVEC5:
    case TYPE_BITVEC6:
    case TYPE_BITVEC7:
    case TYPE_BITVEC8:
#endif
    case TYPE_MIXED1:
    case TYPE_MIXED2:
            return aerror("vector type unsupported by write-module");
        }
    }
    else return aerror("write-module");
    return nil;
}

Lisp_Object Lwrite_module(Lisp_Object nil, Lisp_Object a)
{
#ifdef DEBUG_FASL
    push(a);
    trace_printf("FASLOUT: ");
    loop_print_trace(a);
    errexit();
    trace_printf("\n");
    pop(a);
#endif
    return write_module0(nil, a);
}

static Lisp_Object write_module0(Lisp_Object nil, Lisp_Object a)
/*
 * write one expression to the currently selected output stream.
 * That stream ought to have been opened using start-module, and is
 * binary (i.e. no record separators or concern about record length
 * must intrude).
 */
{
#ifdef SOCKETS
/*
 * Security measure - remote client can not do "write-module"
 */
    if (socket_server != 0) return onevalue(nil);
#endif
    if (a == nil) Iputc(F_NIL);
    else if (a == lisp_true) Iputc(F_TRU);
    else if (a == CHAR_EOF) Iputc(F_END);
/*
 * In Common Lisp mode there will be a certain amount of horrible fun with
 * symbols and the package system.  But a symbol that is EQ to one recently
 * processed can be handled that way regardless.
 */
    else if (is_symbol(a))
    {   int32_t i, len;
        Lisp_Object w, w1;
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
/*
 * The FASL mechanism does not in general preserve EQness. In particular
 * cyclic structures will upset it, and multiple references to the same
 * string or float (etc) will read back as distinct entities. However
 * within one S-expression I will arrange that uninterned symbols are
 * handled tolerably cleanly... The first time such a symbol is written
 * its name is dumped in the file. When this is read back a new uninterned
 * symbol with that name is created.  Usually the next few uses will use
 * the "recently referenced symbol" mechanism, and so will refer back to
 * this value. For gensyms I extend the usual cyclic buffer that holds the
 * recently mentioned symbols with a fall-back list of mentioned gensyms,
 * and refer into that using F_EXT followed by a "recent" reference. This
 * mechanism gets activated especially if the FASL file contains a
 * macro-expanded but not compiled form where the expansion introduces
 * gensyms as labels etc.
 */

#ifdef COMMON
/*
 * The code here is expected to match that in print.c. It sets pkgid to
 * indicate how the symbol involved needs to be put into the FASL file.
 * My byte format there is optimised for the case where no package marker
 * is needed. The values of pkgid are:
 *  0    no package marker needed
 *  1    display as #:xxx      (ie as a gensym)
 *  2    display as :xxx       (ie in keyword package)
 *  3    display as ppp:xxx    (external in its home package)
 *  4    display as ppp::xxx   (internal in its home package)
 */
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
            pkgid = 1; /* gensym */
        }
        else if (qpackage(a) == qvalue(keyword_package)) pkgid = 2;
        else if (qpackage(a) == CP) pkgid = 0; /* home is current */
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
        if (skipping_output == 0 || pkgid == 1)
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
        len = length_of_header(vechdr(w)) - CELL;
        switch (pkgid)
        {
    case 0: if (1 <= len && len <= 15) Iputc(F_ID1 + (int)len - 1);
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
            lenp = length_of_header(vechdr(a)) - CELL;
/*
 * Another ugliness rears its head here... I allow for symbols that have
 * very long names, but I will only support packages where the name of the
 * package is less then 256 characters. This is so I can use a one-byte
 * counter to indicate its length. If I REALLY have to I can put in
 * support for ultra-long names for packages, but the mess involved
 * seems offensive at the moment. I truncate any over-long package name
 * at 255 here. Silently.
 */
            if (lenp > 255) lenp = 255;
            Iputc(lenp);
            Iputc((int)(len & 255));
            Iwrite((char *)a + CELL - TAG_VECTOR, lenp);
        }
        else if (lenp == 0) Iputc((int)(len & 0xff));
        Iwrite((char *)w + CELL - TAG_VECTOR, len);
#else
/*
 * In Standard Lisp mode things that were gensyms in the original
 * will probably get read back in as ordinary symbols. This at least
 * ensures that multiple references to the same gensym end up matching, and
 * it is less effort than the Common Lisp solution...
 * Actually I am now finding this to be UNSATISFACTORY and am going to
 * change it to be much more like the behaviour I have in the COMMON case.
 */
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
            pkgid = 1; /* gensym */
        }
        misses++;
/*
 * See comment where F_GENSYM is read to understand why gensyms must be
 * recorded even when skipping...
 */
        if (skipping_output == 0 || pkgid == 1)
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
        len = length_of_header(vechdr(w)) - CELL;
        if (pkgid == 0)
        {   if (1 <= len && len <= 15) Iputc(F_ID1 + (int)len - 1);
            else
            {   out_fasl_prefix(len >> 8);
                Iputc(F_SYM);
                Iputc((int)(len & 0xff));
            }
        }
        else
        {   out_fasl_prefix(len >> 8);  /* here it is a gensym */
            Iputc(F_GENSYM);
            Iputc((int)(len & 0xff));
        }
        Iwrite((char *)w + CELL - TAG_VECTOR, len);
#endif
    }
    else if (is_cons(a))
    {   int32_t len, i;
        Lisp_Object cara = qcar(a), cdra = qcdr(a);
        if (cara == quote_symbol && consp(cdra) && qcdr(cdra) == nil)
        {   Iputc(F_QUT);
            return write_module0(nil, qcar(cdra));
        }
        len = 1;
        while (consp(cdra)) len++, cdra = qcdr(cdra);
        out_fasl_prefix(len >> 8);
        if (cdra == nil)
        {   switch (len)
            {
        case 1:
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
        CSLbool sign;
/*
 * The fixnum range is 0xf8000000 to 0x07ffffff
 */
        if (n < 0) n = -n, sign = YES;
        else sign = NO;
        out_fasl_prefix(n >> 8);
        Iputc(sign ? F_NEG : F_INT);
        Iputc((int)(n & 0xff));
    }
    else if (is_numbers(a))
    {   Header h = numhdr(a);
        int32_t len, i;
        switch (type_of_header(h))
        {
    default:
            return aerror("unrecognized number type");
#ifdef COMMON
    case TYPE_RATNUM:
            Iputc(F_RAT);
            break;
    case TYPE_COMPLEX_NUM:
            Iputc(F_CPX);
            break;
#endif
    case TYPE_BIGNUM:
            len = length_of_header(h) - CELL;
            out_fasl_prefix(len >> 8);
            Iputc(F_BIG);
            Iputc((int)(len & 0xff));
/*
 * I write out the value byte by byte so that the binary in the file
 * does not depend on the byte-ordering used by the host computer.
 */
            for (i=0; i<len; i+=4) /* always in 32-bit units */
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
        write_module0(nil, *(Lisp_Object *)((char *)a + CELL - TAG_NUMBERS));
        errexit();
        return write_module0(nil,
                           *(Lisp_Object *)((char *)a + 2*CELL - TAG_NUMBERS));
#endif
    }
#ifdef COMMON
    else if (is_sfloat(a))
    {   Lisp_Object w = a;
/*
 * I write out floating point values in whatever the natural host
 * representation is - but prefix the first FP value with a marker that
 * identifies what that representation is so that when the file is re-loaded
 * a conversion can be applied as necessary.
 */
        if (!fp_rep_set)
        {   fp_rep_set = YES;
            Iputc(F_REP);
            Iputc(current_fp_rep & 0xff);
            Iputc((current_fp_rep >> 8) & 0xff);
        }
        Iputc(F_FPS);
        Iwrite((char *)&w, 4);
    }
#endif
    else write_module1(a);
    return onevalue(nil);
}

/*
 * (set-help-file "key" "path") puts an extra help file on the cwin
 * HELP menu. If "path" is NIL then the item specified by "key" is
 * removed. If "key" is NIL then all user-inserted items are removed.
 */

Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
#ifdef HAVE_FWIN
    char *w, *aa, *bb = NULL;
    int32_t lena, lenb;
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

#if 0

/*
 * write-help-module (now) takes as argument a file-name. It expects the
 * file to be in INFO format. It copies the text from the file into
 * a section of the image file and builds an index (which will remain in
 * memory).
 */

/*
 * write-help-module has two arguments here because the previous version did
 * and changing that would cause short-term confusion...
 */

static void merge_sort(char *a, char *b, int left, int right)
{
    int next = left+8, mid, i, j;
    if (left==right) return;    /* Empty vector to sort */
    while (next < right && a[next] != 0) next += 8;
    if (next >= right) return;  /* Only one item there */
    mid = ((left+right)/2) & ~7;
    if (mid <= next) mid = next;
    else while (a[mid] != 0) mid -= 8;
/*
 * Now (left..mid) is non-empty because mid >= next, and (mid..right) is not
 * empty because mid rounded downwards and the vector has at least two
 * items in it.
 */
    merge_sort(a, b, left, mid);
    merge_sort(a, b, mid, right);
    for (i=left; i<=right; i++) b[i] = a[i];
    i = left; j = mid; next = left;
/* Now merge back from b to a */
    while (i < mid && j < right)
    {   int i1 = i+4, j1=j+4, k;
        for (k=0; k<28; k++)
        {   if (b[i1] != b[j1]) break;
            i1++;
            j1++;
        }
        if (b[i1] <= b[j1])
        {   do
            {   *(int32_t *)(&a[next]) = *(int32_t *)(&b[i]);
                *(int32_t *)(&a[next+4]) = *(int32_t *)(&b[i+4]);
                next += 8;
                i += 8;
            } while (b[i] != 0);
        }
        else
        {   do
            {   *(int32_t *)(&a[next]) = *(int32_t *)(&b[j]);
                *(int32_t *)(&a[next+4]) = *(int32_t *)(&b[j+4]);
                next += 8;
                j += 8;
            } while (b[j] != 0);
        }
    }
    while (i < mid) a[next++] = b[i++];
    while (j < right) a[next++] = b[j++];
}

/*
 * To get some sort of compression on the help text I will collect
 * statistics about which pairs of characters occur adjacent to one
 * another. I will first use an array of 256*256 unsigned characters. When
 * a particular pair records 255 in this count field I will enter it in
 * an overflow hash table. The space for each of these tables will be
 * grabbed using malloc(), so if you try to build a help database on
 * a machine where grabbing an extra 100K of memory is awkward then you
 * may be out of luck.
 */

typedef struct char_pair_hash
{
    int32_t count;
    char c1, c2;
} char_pair_hash;

/*
 * I observe (having done the experiment) that the REDUCE help database
 * causes overflow for somewhat under 400 character-pairs. Thus a hash
 * table with room for twice that number should suffice for now. Note that
 * an utterly worst-case file would have to be over 256Kbytes long for
 * more than 1000 character pairs each to occur over 256 times, and all
 * realistic text files will be a very long way from that case. If, by
 * mistake, one fed this code a file that was already compressed it would
 * collapse with an overfull hash table. Tough luck - in such cases I will
* just deliver slightly silly results.
 */

#define OVERFLOW_SIZE 1000

#define PASS_COUNT 12

static int MS_CDECL compare_char_counts(void const *aa, void const *bb)
{
    return ((char_pair_hash *)bb)->count -
           ((char_pair_hash *)aa)->count;
}

#define INFO_CHAR   ('_' & 0x1f)

Lisp_Object Lwrite_help_module(Lisp_Object nil,
                               Lisp_Object name, Lisp_Object ignore)
{
    int i, c1, c2, c3, pass, linep;
    int32_t info_seen;
    unsigned char cx1[256], cx2[256];
    char buff[16], line[256];
/*
 * There can be no more than 256 items put in the coded[] hash table, and
 * in general I expect it to be considerably less than that. So having the
 * table of size 409 (a prime) guarantees it will never get too full so
 * performance ought to be pretty good.
 */
#define CODED_SIZE  409
    char_pair_hash coded[CODED_SIZE];
    int32_t buffp;
    Ihandle save;
    Lisp_Object v = nil, v1;
    int32_t indexlength = -10000, saving;
    int32_t helpsize = 0, len;
    char filename[LONGEST_LEGAL_FILENAME];
    Header h;
    FILE *file;
    unsigned char *frequencies;
    char_pair_hash *overflow;
    CSL_IGNORE(ignore);
#ifdef SOCKETS
/*
 * Security measure - remote client can not do write-help-module"
 */
    if (socket_server != 0) return onevalue(nil);
#endif
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
    else if (!(is_vector(name))) return aerror("write-help-module");
    else if (type_of_header(h = vechdr(name)) != TYPE_STRING)
        return aerror("write-help-module");
    len = length_of_header(h) - CELL;
    if (len > sizeof(filename)) len = sizeof(filename);
    file = open_file(filename, (char *)name + (CELL-TAG_VECTOR),
                     (size_t)len, "r", NULL);
    if (file == NULL) return aerror("write-help-module");
    Icontext(&save);
    if (Iopen_help(-1))        /* Open help sub-file for writing */
    {   Irestore_context(save);
        fclose(file);
        return aerror("Unable to open help file");
    }
    for (i=0; i<CODED_SIZE; i++)
    {   coded[i].c1 = coded[i].c2 = 0;
        coded[i].count = 0;
    } 
    frequencies = (unsigned char *)malloc(0x10000);
    overflow = (char_pair_hash *)malloc(OVERFLOW_SIZE*sizeof(char_pair_hash));
    if (frequencies == NULL || overflow == NULL)
    {   Irestore_context(save);
        fclose(file);
        free((void *)frequencies);
        free((void *)overflow);
        return aerror("Not enough memory to build help database");
    }
    for (i=0; i<256; i++) cx1[i] = cx2[i] = 0;
    for (pass=1; pass<=PASS_COUNT; pass++)
    {   term_printf("Start of pass %d\n", pass);
        if (pass == PASS_COUNT)
        {   v = getvector(TAG_VECTOR, TYPE_STRING, CELL+4+indexlength);
            nil = C_nil;
/*
 * I will get another vectors the same size so that I have plenty of
 * space for a simple-minded implementation of merge-sort.
 */
            if (!exception_pending())
            {   push(v);
                v1 = getvector(TAG_VECTOR, TYPE_STRING, CELL+4+indexlength);
                pop(v);
                nil = C_nil;
            }
            else v1 = nil;
            if (exception_pending())
            {   flip_exception();
                IcloseOutput(1);
                Irestore_context(save);
                fclose(file);
                free((void *)frequencies);
                free((void *)overflow);
                flip_exception();
                return nil;
            }
        }
        indexlength = 512;
        fseek(file, SEEK_SET, 0L);
        for (i=0; i<0x10000; i++) frequencies[i] = 0;
        for (i=0; i<OVERFLOW_SIZE; i++)
        {   overflow[i].c1 = overflow[i].c2 = 0;
            overflow[i].count = 0;
        }
        for (i=0; i<16; i++) buff[i] = 0;
        buffp = 0;
        i = 100;
        saving = 0;
/* An "info" file has a little header at the top - skip that */
        while ((c2 = getc(file)) != EOF &&
               c2 != INFO_CHAR) /* do nothing */;
        c2 = getc(file);        /* newline following the ^_ */
        linep = 0;
        info_seen = 0;
        while ((c2 = getc(file)) != EOF)
        {   uint32_t x;
            int n;
            if (c2 == '\n')
            {   line[linep] = 0;
                if (linep == 1 && line[0] == INFO_CHAR)
                {   int32_t bp = buffp;
/*
 * I flush the compression look-ahead buffer when I find a "^_" record
 * so that the break between help topics is on a real byte boundary and so
 * that I can tell where in the help file this boundary will fall.
 */
                    for (;;)
                    {   bp++;
                        c1 = buff[bp & 15];
                        buff[bp & 15] = 0;
                        if (c1 == 0) break;
                        if (pass == PASS_COUNT)
                        {   if (c1 == INFO_CHAR) Iputc(0);
                            else Iputc(c1);
                            helpsize++;
                        }
                    }
                    info_seen = helpsize;
                    linep = 0;
                    continue;  /* Throws away the '\n' after '^_' */
                }
                else if (info_seen >= 0)
                {   if (strcmp(line, "Tag Table:") == 0) break;
/*
 * Here I must spot "File:" lines and count the size of the node name and/or
 * insert it in the index vector.
 */
                    if (strncmp(line, "File: ", 6) == 0)
                    {   linep = linep-6;
                        while (linep>0 &&
                               strncmp(&line[linep], "Node: ", 6) != 0)
                            linep--;
                        if (linep != 0)
                        {   char *node = &line[linep+6];
                            int nodelen = 0;
/*
 * I will force node labels into upper case here. I use upper rather than
 * lower case mainly because it turns out to make it easier for me to compare
 * the sorted order of my key-table with the order imposed by a (DOS) sort
 * utility I have. In particular it makes the collating order of '_' with
 * letters compatible with the independent external utility.
 */
                            while (node[nodelen] != ',' &&
                                   node[nodelen] != 0)
                            {   node[nodelen] = (char)toupper(node[nodelen]);
                                nodelen++;
                            }
                            if (nodelen > 28) nodelen = 28;
                            if (pass == PASS_COUNT)
                            {   ucelt(v, indexlength++) = 0;
                                ucelt(v, indexlength++) = (unsigned char)(info_seen & 0xff);
                                ucelt(v, indexlength++) = (unsigned char)((info_seen >> 8) & 0xff);
                                ucelt(v, indexlength++) = (unsigned char)((info_seen >> 16) & 0xff);
                                while (nodelen-- != 0)
                                    celt(v, indexlength++) = *node++;
                                while (indexlength & 7)
                                    celt(v, indexlength++) = 0;
                            } 
                            else indexlength = indexlength +
                                ((nodelen + 11) & ~7);
                        }
                    }
                    info_seen = -1;
                }
                else info_seen = -1;
                linep = 0;
            }
            else if (linep < 255) line[linep++] = (char)c2;
/*
 * I truncate lines at 255 characters. This is not so comfortable as all that!
 * The Reduce Help Database ends up with lines of up to 195 characters long,
 * in cases where the names of several adjacent sections are all ridiculously
 * long.
 */
            cx1[c2] = (unsigned char)c2;
            for (;;)
            {   c3 = buff[(buffp-1) & 15];
                if (c3 != 0)
                {   int c4 = 0;
                    int32_t hash = ((((c3 & 0xff)<<8)+
                                  (c2 & 0xff))*32359) % CODED_SIZE;
                    for (;;)
                    {   if (coded[hash].count == 0) break;
                        else if (coded[hash].c1 == c3 &&
                                 coded[hash].c2 == c2)
                        {   c4 = coded[hash].count;
                            buffp--;
                            buff[buffp & 15] = 0;
                            saving++;
                            break;
                        }
                        hash++;
                        if (hash == CODED_SIZE) hash = 0;
                    }
                    if (c4 != 0)
                    {   c2 = c4;
                        continue;
                    }
                }
                break;
            }
            c1 = buff[(buffp+1) & 15];
            c3 = buff[(buffp+2) & 15];
            buff[buffp & 15] = (char)c2;
            buffp++;
            buff[buffp & 15] = 0;
            c2 = c3;
            if (c1 == 0 || c2 == 0 || c1 == INFO_CHAR ||
                c2 == INFO_CHAR) continue;
            if (pass == PASS_COUNT)
            {   if (c1 == INFO_CHAR) Iputc(0);  /* terminate a section */
                else Iputc(c1);
                helpsize++;    
            }
            x = ((c1 & 0xff) << 8) | (c2 & 0xff);
            n = frequencies[x];
            if (--i == 0)
            {   stackcheck0(0);
                i = 100;
            }
            if (n == 255)
            {   x = (x*32359) % OVERFLOW_SIZE;
/*
 * In general I expect inserting character-pairs in this table will only
 * take a few probes. But any scan that takes over 3*OVERFLOW_SIZE/4 is
 * abandoned. The effect is that worst-case behaviour could eventually
 * fill the table up totally, so this long-stop would be the only thing
 * preventing the code from looping for ever. So then it would run around
 * 200 times slower than usual, but it would eventually finish! Such bad cases
 * can not happen with reasonable input data.
 */
                for (n=0;n<(3*OVERFLOW_SIZE)/4;n++)
                {   if (overflow[x].count == 0)
                    {   overflow[x].c1 = (char)c1;
                        overflow[x].c2 = (char)c2;
                        overflow[x].count = 256;
                        break;
                    }
                    else if (c1 == overflow[x].c1 &&
                             c2 == overflow[x].c2)
                    {   overflow[x].count++;
                        break;
                    }
                    x = x + 1;
                    if (x == OVERFLOW_SIZE) x = 0;
                }
            }
            else frequencies[x] = (unsigned char)(n+1);
        }
/*
 * It is possible (probable!) that at the end of processing there are a few
 * characters left buffered up. Flush them out now.
 */
        if (pass == PASS_COUNT)
        {   for (;;)
            {   buffp++;
                c1 = buff[buffp & 15];
                buff[buffp & 15] = 0;
                if (c1 == INFO_CHAR) Iputc(0);
                else Iputc(c1);
                helpsize++;    
                if (c1 == 0) break;  /* NB I write a zero to terminate */
            }
        }
        term_printf("Saving this pass was %d\n", saving);
        qsort(overflow, (size_t)OVERFLOW_SIZE, sizeof(char_pair_hash),
              compare_char_counts);
        if (pass < PASS_COUNT)
        {   for (i=0; i<(pass==PASS_COUNT-1 ? OVERFLOW_SIZE : 10); i++)
            {   int rep;
                int32_t hash;
                if (overflow[i].c1 == 0 || overflow[i].c2 == 0) continue;
                for (rep=1; rep<256; rep++)
                    if (cx1[rep]==0) break;
                if (rep == 256) break;
                c1 = overflow[i].c1;
                c2 = overflow[i].c2;
                cx1[rep] = (unsigned char)c1;
                cx2[rep] = (unsigned char)c2;
                hash = ((((c1 & 0xff)<<8)+(c2 & 0xff))*32359) % CODED_SIZE;
                for (;;)
                {   if (coded[hash].count == 0)
                    {   coded[hash].c1 = (char)c1;
                        coded[hash].c2 = (char)c2;
                        coded[hash].count = rep;
                        break;
                    }
                    else if (coded[hash].c1 == c1 &&
                             coded[hash].c2 == c2) break;
                    hash++;
                    if (hash == CODED_SIZE) hash = 0;
                }
                term_printf("%.2x %.2x => %.2x (%d)\n",
                            c1 & 0xff, c2 & 0xff, rep & 0xff, overflow[i].count);
            }
        }
    }
    celt(v, indexlength) = 0;   /* needed as a terminator */
    for (i=0; i<256; i++)
    {   celt(v, 2*i) = cx1[i];
        celt(v, 2*i+1) = cx2[i];
    }
    i = Ioutsize() & 3;
    while ((i & 3) != 0) Iputc(0), i++;   /* Pad to multiple of 4 bytes */
    IcloseOutput(1);
    fclose(file);
    free((void *)frequencies);
    free((void *)overflow);
    trace_printf("%ld bytes of help data\n", (long)helpsize);
    Irestore_context(save);
/*
 * Now I have made a help module and an associated index vector, however
 * the index information is at present unordered. I want to sort it but
 * the situation is a little curious - the items in the vector are of
 * variable length and so most of the sorting methods I can think of
 * are not easily applied.  I guess that merge-sort is the solution...
 */
    merge_sort(&celt(v, 0), &celt(v1, 0), 512, indexlength);

    help_index = v;   /* Only set up the index vector if all seemed OK */
    return onevalue(nil);
}

/*
 * Here I will have a simulation of some modest part of the "curses"
 * interface that Unix tends to support. I will certainly not support
 * everything - just a minimum that I think I need for my help browser.
 * I support the following environments
 * (a) Watcom C for DOS, using the Watcom graphics library
 * (b) Unix using real "curses", but adding two new functions initkb()
 *     and resetkb() to switch to unbuffered un-echoed input from getch()
 * (c) Watcom C and Windows (win32) using a separate 25 by 80 window
 *     for all the text output here.  This case will be flagged by having
 *     the pre-processor symbol WIN32 defined.
 */

#include <ctype.h>

#ifdef WIN32

/*
 * Under win32 I will have the implementation of all this stuff as
 * part of my window manager code, and hence elsewhere. So I just provide
 * a collection of declarations to show what will be available.
 */

/*
 * For Windows I will only support an 80 by 25 window. I guess it
 * would be easy enough to permit other sizes, except that I do not have
 * an easy answer to what should happen if the user re-sizes the window
 * while other things are going on. Hence my conservative caution - at
 * least for now!
 */
extern int LINES, COLS;

/* initscr() must be called once at the start of a run */
extern void initscr(void);

/*
 * initkb() and resetkb() delimit regions in the code where keyboard
 * input is treated as requests to the curses window but is accepted
 * with no delay and no echo.  Also mouse events can be posted during
 * this time.
 */
extern void initkb(void);
extern void resetkb(void);

extern int mouse_button;  /* set non-zero when user presses a button */
extern int mouse_cx;      /* 0 <= mouse_cx < COLS                    */
extern int mouse_cy;      /* 0 <= mouse_cy < LINES                   */

/* refresh() is called to force the screen to be up to date */
extern void refresh();

/* endwin() hides the curses window, restoring simple text handling */
extern void endwin(void);

/* Move text insertion point. Origin (0,0) is top left of screen */
extern void move(int y, int x);

/* standout() and standend() delimit inverse video (or whatever) text */
extern void standout(void);
extern void standend(void);

/* erase() clears the whole screen */
extern void erase(void);

/*
 * addch() and addstr() add text to the screen, advancing the cursor. I
 * view it as illegal to write beyond either right or bottom margin of the
 * screen.
 */
extern void addch(int ch);
extern void addstr(char *s);

/*
 * getch() reads a character from the keyboard. It does not wait for
 * a newline, and does not echo anything. Because the name getch() may be
 * in use in some C libraries in a way that could conflict I use some
 * re-naming here.  If there has been a mouse-click recently then getch()
 * should return a value (0x100 + bits) where the odd bits may indicate which
 * button was pressed. In that case (mouse_cx,mouse_cy) will be the
 * character-position coordinates at which the hit was taken. Systems
 * that can not support a mouse do not have to worry about this and can always
 * return a value in the range 0..255, or EOF. On some systems getch() will
 * return 0 with no delay if there is no character available (so that
 * the application will busy-wait). On others it is entitled to wait until
 * the user presses a key. But (once again) it should not do line editing or
 * wait for an ENTER.
 */
extern int my_getch(void);
#undef getch
#define getch() my_getch()

#else /* WIN32 */

/*
 * Assume Unix here - or some system providing Unix compatibility.
 * Note that "curses" may not always be installed, but is needed here
 * if the embedded help system is to work.
 */


#include <curses.h>

/*
 * In fact for the curses-Unix style interface I do not support a mouse,
 * but that is no great problem - I just let mouse_button remain zero
 * always.
 */

int mouse_button = 0;  /* set non-zero when user presses a button */
int mouse_cx = 0;      /* 0 <= mouse_cx < COLS                    */
int mouse_cy = 0;      /* 0 <= mouse_cy < LINES                   */


void initkb()
{
    cbreak();
    noecho();
}

void resetkb()
{
    nocbreak();
    echo();
}


#endif /* WIN32 */

/*
 * End of curses compatibility code
 */

char file[256], node[256], next[256], prev[256], up[256];
long int topic_start = 0, topic_header_size = 0;

void find_word(char *buffer, char *tag, char *value)
{
    int len = strlen(tag), ch;
    *value = 0;
    while (*buffer != 0)
    {   if (strncmp(buffer, tag, len) != 0)
        {   buffer++;
            continue;
        }
        buffer += len;
        while ((ch = *buffer) == ' ' && ch != 0) buffer++;
        if (ch == 0) return;
        while ((ch = *buffer++) != ',' && ch != 0) *value++ = (char)ch;
        *value = 0;
        return;
    }
}

static int shown_lines = 0;

static unsigned char cstack[28];
static int cstackp;

/*
 * I have here some fairly simple compression on the help text. Characters
 * can either stand for themselves or for pairs of characters. The table in
 * the first 512 bytes of the index table indicates which. If at location
 * (2*i, 2*i+1) this table contains (p,q) then q=0 means that the character
 * i stands for itself (and p=i). Otherwise i expands to p followed by q where
 * each of these are subject to the same potential expansion. Code 0 is
 * reserved as a section or file terminator.
 */

static int getc_help(void)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v = help_index;
    unsigned char *p;
    int k, c2;
    CSL_IGNORE(nil);
    p = &ucelt(v, 0);
    if (cstackp == 0) k = Igetc();
    else k = cstack[--cstackp];
    for (;;)
    {   if (k == EOF || k == 0) return 0;
        c2 = p[2*k+1];
        if (c2 == 0) return k;
        cstack[cstackp++] = (unsigned char)c2;
        k = p[2*k];
    }
}

#define MAX_MENUS  32

static int at_end_of_topic = 0;
static int menu_line[MAX_MENUS], menu_col[MAX_MENUS], max_menu, active_menu;
static char menu_text[MAX_MENUS][40];

void display_next_page(void)
{
    int ch, line = 0, col, llen = 80, i, j;
    char buffer[256];
    if (COLS < 80) llen = COLS;
    erase();
    at_end_of_topic = 0;
    max_menu = active_menu = -1;
/*
 * There is an "ugly" here. The sprintf that formats the header line
 * does not protect against over-long topic-names that could lead to over-full
 * buffers. I make the buffer 256 characters long and hope! I force a '\0'
 * in at column 80 (or whatever) later on to effect truncation.
 */
    sprintf(buffer, "Node: %s, Next: %s, Prev: %s, Up:%s",
            node, next, prev, up);
    buffer[llen] = 0;
    move(0, 0);
    addstr(buffer);
    while (++line < LINES)
    {   col = 0;
        while ((ch = getc_help()) != '\n')
        {   if (ch == 0 || ch == EOF) 
            {   at_end_of_topic = 1;
                break;
            }
            if (col < llen) buffer[col++] = (char)ch;
        }
        if (at_end_of_topic) break;
        buffer[col] = 0;
        for (i=0; i<col &&
                  !(buffer[i]=='*' &&
                    buffer[i+1]==' '); i++);
        for (j=i+1; j<col && 
                    !(buffer[j]==':' &&
                      buffer[j+1]==':'); j++);
        if (j < col && max_menu < MAX_MENUS-2)
        {   max_menu++;
            menu_line[max_menu] = line;
            menu_col[max_menu] = i + 2;
            memset(menu_text[max_menu], 0, 39);
            strncpy(menu_text[max_menu], &buffer[i+2], j-i-2);
            menu_text[max_menu][39] = 0;
        }
        move(line, 0);
        addstr(buffer);
        shown_lines++;
    }
    refresh();
}

void skip_some_lines(int n)
{
    int ch, line = 0, col;
    char buffer[16];
    at_end_of_topic = 0;
    while (++line <= n)
    {   col = 0;
        while ((ch = getc_help()) != '\n')
        {   if (ch == 0 || ch == EOF)
            {   at_end_of_topic = 1;
                break;
            }
            if (col < 8) buffer[col++] = (char)ch;
        }
        if (at_end_of_topic) break;
        shown_lines++;
    }
}

static int topic_in_index(char *key)
{
    int len = strlen(key);
    Lisp_Object nil = C_nil;
    Lisp_Object v = help_index;
    int32_t size, i, low, high, offset;
    int k, l;
    char *p;
    CSL_IGNORE(nil);
    if (len > 28) len = 28;
    if (!is_vector(v)) return 0;
    size = length_of_header(vechdr(v)) - CELL;
    p = &celt(v, 0);

/*
 * The first 512 bytes of the help index contain data for the decompression
 * process, and so are not used in the following search.
 * I stop at size-4 on the next line because I added an extra 4 bytes
 * of padding on the end of the help index to terminate the last entry.
 */
    low = 512;
    high = size-4;
/*
 * Do a binary search a bit, but when I am down to a fairly narrow
 * range drop down to linear scan.  Note that binary search is somewhat
 * curious given that the items in my index are variable length!
 */
    while (high > low + 64)  /* largest item in table is 28 bytes */
    {   int32_t mid = (high + low)/2;
        mid &= ~7;           /* Align it properly */
/*
 * At this stage mid might point part way through an index entry. Move it
 * up until it points at something that has a zero first byte. Because
 * I started off with low and high well separated this is guaranteed to
 * terminate with mid strictly between low and high.  I slide up rather
 * than down to (slightly) balance the rounding down that happened in
 * the original calculation of the mid-point.
 */
        while (p[mid] != 0) mid += 8;
        for (k=0; k<len && toupper(key[k]) == p[mid+k+4]; k++) {};
        if (k < len)
        {   if (toupper(key[k]) < p[mid+k+4]) high = mid;
            else low = mid;
            continue;
        }
        else if (p[mid+k+4] != 0)
        {   high = mid;
            continue;
        }
        low = high = mid;   /* Found it exactly */
        break;
    }
    l = 0;
    for (i=low; i<high; i=i+l+4)
    {   l = 4;
        while (p[i+l+4] != 0) l += 8;
        if (len > l) continue;
        for (k=0; k<len && toupper(key[k]) == p[i+k+4]; k++) {};
        if (k < len) continue;
        if (p[i+len+4] != 0) continue;
        l = 0;   /* Match found: mark the fact with l=0 */
        break;
    }
    if (l != 0) return 0;  /* Failed to find the key */
    offset = p[i+3] & 0xff;
    offset = (offset << 8) + (p[i+2] & 0xff);
    offset = (offset << 8) + (p[i+1] & 0xff);
    IcloseInput(NO);
    if (Iopen_help(offset)) return 0;
    topic_start = offset;
    cstackp = 0;
    return 1;
}

int find_topic(char *s)
{
    char buffer[256];
    int i, c1;
    if (!topic_in_index(s)) return 0;
    shown_lines = 0;
    cstackp = 0;
    for (i=0, c1=getc_help();c1!='\n';c1=getc_help())
        if (i < 250) buffer[i++] = (char)c1;
    buffer[i] = 0;
    topic_header_size = i;
    find_word(buffer, "Node:", node);
    find_word(buffer, "File:", file);
    find_word(buffer, "Next:", next);
    find_word(buffer, "Prev:", prev);
    find_word(buffer, "Up:",   up);
    display_next_page();
    return 1;
}

void restart_topic(void)
{
    IcloseInput(NO);
    if (!Iopen_help(topic_start))
    {   int i;
        for (i=0; i<topic_header_size; i++) getc_help();
    }
    cstackp = 0;
}

static void help_about_help_browser(void)
{
    int ch;
    erase();
    move( 1, 0); addstr("*** HELP BROWSER COMMANDS ***");
    
    move( 3, 0); addstr("b      go Back to start of topic");
    move( 4, 0); addstr("space  move on one page through topic");
    move( 5, 0); addstr("delete move back one page in topic");
    move( 6, 0); addstr("?, h   display this Help text");
    move( 7, 0); addstr("n      go to Next topic");
    move( 8, 0); addstr("p      go to Previous topic");
    move( 9, 0); addstr("u      go Up a level");
    move(10, 0); addstr("q      Quit");
    move(11, 0); addstr("tab, m Select next Menu item");
    move(12, 0); addstr("ENTER, f  Follow selected menu item");
    move(13, 0); addstr("1-9    First 9 menu items visible");
    
    move(15, 0); addstr("[Type SPACE or ENTER to continue]");
    refresh();
    while ((ch = getch()) != ' ' && ch != '\n' && ch != '\r');
}

static int help_main(char *s)
{
    int i, w;
    initscr();
    initkb();
    if (!find_topic(s)) return 1;
    for (;;)
    {   w = getch();
        switch (tolower(w))
        {
    case 'q': break;
    case 'n': if (next[0] != 0)
              {   if (!find_topic(next)) goto redisplay_current_topic;
              }
              continue;
    case 'p': if (prev[0] != 0)
              {   if (!find_topic(prev)) goto redisplay_current_topic;
              }
              continue;
    case 'u': if (up[0] != 0)
              {   if (!find_topic(up)) goto redisplay_current_topic;
              }
              continue;
    case ' ': if (!at_end_of_topic) display_next_page();
              continue;
    case 0x8:
    case 0x7f:
    case 0xff:
              if (shown_lines <= (LINES-2)) continue;
              i = shown_lines - 2*LINES + 2;
              if (i < 0) i = 0;
              restart_topic();
              shown_lines = 0;
              skip_some_lines(i);
              display_next_page();
              continue;
    case '?':
    case 'h': help_about_help_browser();
              /* Drop through */
    redisplay_current_topic:
    case 'b': restart_topic();
              shown_lines = 0;
              display_next_page();
              continue;
    case '\t':
    case 'm': /* For this version I make "m" skip to the next menu item */
              if (max_menu < 0) continue;
              if (active_menu >= 0)
              {   move(menu_line[active_menu], menu_col[active_menu]);
                  addstr(menu_text[active_menu]);
                  active_menu++;
                  if (active_menu > max_menu) active_menu = 0;
              }
              else active_menu = 0;
              move(menu_line[active_menu], menu_col[active_menu]);
              standout();
              addstr(menu_text[active_menu]);
              standend();
              refresh();
              continue;
    case '\n': /* Follow a menu item, as selected */
    case '\r':
    case 'f': if (max_menu >= 0 && active_menu >= 0)
              {   if (!find_topic(menu_text[active_menu]))
                      goto redisplay_current_topic;
              }
              continue;
    case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9':
              w = w - '1';
              if (w <= max_menu)
              {   if (!find_topic(menu_text[w]))
                      goto redisplay_current_topic;
              }
              continue;
    default:  continue;
        }
        break;
    }
    resetkb();
    endwin();
    return 0;
}

static void help(char *word, int len)
{
    Ihandle save;
    char key[32];
    Icontext(&save);
    if (Iopen_help(0)) debug_printf("\nNo heap available\n");
    else
    {   if (len > 28) len = 28;
        key[len] = 0;
        while (--len >= 0) key[len] = word[len];
/*      memcpy(key, word, len);  <curses.h> on a sparc kills this!! */
/*      key[len] = 0;            by its attempts to mix BSD & sysV. */

        if (help_main(key)) debug_printf("\nNo help available\n");

        IcloseInput(NO);
    }
    Irestore_context(save);
    return;
}

Lisp_Object lisp_help(Lisp_Object nil, Lisp_Object a)
{
   switch ((int)a & TAG_BITS)
   {
case TAG_SYMBOL:
#ifndef COMMON
        if (a == nil)
        {   help("Top", 3);   /* this tag is the default one to give */
            return onevalue(nil);
        }
#endif
        a = get_pname(a);
        errexit();
case TAG_VECTOR:
        if (type_of_header(vechdr(a)) == TYPE_STRING)
        {   Header h = vechdr(a);
            int32_t len = length_of_header(h);  /* counts in bytes */
            len -= CELL;
            help(&celt(a, 0), len);
            return onevalue(nil);
        }

case TAG_CONS:
#ifdef COMMON
        if (a == nil)
        {   help("Top", 3);
            return onevalue(nil);
        }
#endif
        while (consp(a))
        {   push(a);
            lisp_help(nil, qcar(a));
            pop(a);
            errexit();
            a = qcdr(a);
        }
        return onevalue(nil);

case TAG_BOXFLOAT:
default:
        return onevalue(nil);
    }
}

Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a)
{
    return lisp_help(nil, a);
}

Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    push(b);
    lisp_help(nil, a);
    pop(b);
    errexit();
    return lisp_help(nil, b);
}

Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...)
{
    if (nargs == 0) help("Top", 0);
    else
    {   va_list a;
        int i;
        va_start(a, nargs);
        push_args(a, nargs);
        for (i=0; i<nargs; i++)
        {   Lisp_Object c = stack[i-nargs+1];
            lisp_help(nil, c);
            errexitn(nargs);
        }
        popv(nargs);
    }
    return onevalue(nil);
}

#else

Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return onevalue(nil);
}

Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a)
{
    term_printf("HELP not built in to this version of the system\n");
    return onevalue(nil);
}

Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    return Lhelp(nil, a);
}

Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...)
{
    return Lhelp(nil, nil);
}

#endif /* code for (old) embedded help system - now removed */

char prompt_string[MAX_PROMPT_LENGTH];

Lisp_Object Lsetpchar(Lisp_Object nil, Lisp_Object a)
{
    Lisp_Object old = prompt_thing;
    CSL_IGNORE(nil);
    prompt_thing = a;
#define escape_nolinebreak 0x80
    escaped_printing = escape_nolinebreak;
    set_stream_write_fn(lisp_work_stream, count_character);
    memory_print_buffer[0] = 0;
    set_stream_write_other(lisp_work_stream, write_action_list);
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

/* end of fasl.c */


