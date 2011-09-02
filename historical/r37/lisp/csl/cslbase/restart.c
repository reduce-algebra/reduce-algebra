/*  restart.c                       Copyright (C) 1989-2002 Codemist Ltd */

/*
 * Code needed to start off Lisp when no initial heap image is available,
 * or to re-instate links between heap and C-coded core if there IS a
 * heap loaded.  This code is run in a state that is in effect (in-package
 * "lisp").
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


/* Signature: 3c2eae4c 16-Feb-2003 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <float.h>

#include "machine.h"
#include "version.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "read.h"
#include "stream.h"
#include "arith.h"
#include "entries.h"
#ifdef TIMEOUT
#include "timeout.h"
#endif

#ifdef ADDRESS_SIGN_UNKNOWN
int32 address_sign;
#endif

Lisp_Object C_nil;
Lisp_Object *stackbase;

Lisp_Object *nilsegment;
Lisp_Object *stacksegment;
int32 stack_segsize = 1;

char *exit_charvec = NULL;

#ifdef NILSEG_EXTERNS

unsigned32 byteflip;
Lisp_Object codefringe;
Lisp_Object volatile codelimit;
Lisp_Object * volatile stacklimit;
Lisp_Object fringe;
Lisp_Object volatile heaplimit;
Lisp_Object volatile vheaplimit;
Lisp_Object vfringe;
int32 nwork;
int32 exit_reason;
int32 exit_count;
unsigned32 gensym_ser, print_precision, miscflags;
int32 current_modulus, fastget_size, package_bits;
Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
Lisp_Object quote_symbol, function_symbol, comma_symbol, comma_at_symbol;
Lisp_Object cons_symbol, eval_symbol, work_symbol, evalhook, applyhook;
Lisp_Object macroexpand_hook, append_symbol, exit_tag;
Lisp_Object exit_value, catch_tags;
#ifdef COMMON
Lisp_Object keyword_package;
#endif
Lisp_Object current_package;
Lisp_Object startfn;
#ifdef COMMON
Lisp_Object all_packages, package_symbol, internal_symbol;
Lisp_Object external_symbol, inherited_symbol;
#endif
Lisp_Object gensym_base, string_char_sym, boffo;
#ifdef COMMON
Lisp_Object key_key, allow_other_keys, aux_key;
#endif
Lisp_Object err_table;
#ifdef COMMON
Lisp_Object format_symbol;
#endif
Lisp_Object progn_symbol;
#ifdef COMMON
Lisp_Object expand_def_symbol, allow_key_key, declare_symbol, special_symbol;
#endif
Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol, echo_symbol;
Lisp_Object codevec, litvec, supervisor, B_reg, savedef, comp_symbol;
Lisp_Object compiler_symbol, faslvec, tracedfn, lisp_terminal_io;
Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
Lisp_Object prompt_thing, faslgensyms, prinl_symbol, emsg_star, redef_msg;
Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
Lisp_Object cl_symbols, active_stream, current_module;
Lisp_Object features_symbol, lisp_package, sys_hash_table;
Lisp_Object help_index, cfunarg, lex_words, get_counts, fastget_names;
Lisp_Object input_libraries, output_library, current_file, break_function;
Lisp_Object standard_output, standard_input, debug_io;
Lisp_Object error_output, query_io, terminal_io, trace_output, fasl_stream;
Lisp_Object native_code, native_symbol, traceprint_symbol, loadsource_symbol;
Lisp_Object hankaku_symbol;
Lisp_Object workbase[51];

#endif

Lisp_Object user_base_0, user_base_1, user_base_2, user_base_3, user_base_4;
Lisp_Object user_base_5, user_base_6, user_base_7, user_base_8, user_base_9;

Lisp_Object eq_hash_tables, equal_hash_tables;

/*
 * On an Intel 80x86 (because I am almost forced to) and on other machines
 * (much more cheerfully, and for choice!) I will arrange my memory as
 * a number of pages.  A general pool of these pages gets used
 * to satisfy requests for heap, vector heap and BPS space.  Running
 * under the Phar Lap 286 DOS extender in protected mode it seemed that
 * all segments returned by malloc() will have their top bit (when punned
 * as a long int) zero.  Thus even on an 80x86 I could make progress..
 * Ditto under the Zortech (Rational Systems) 80286 extender.  Win32
 * (Windows NT) seems OK too, but Win32s has given me pointers with
 * their top bit set... Ugh!  For the 80286 and small machines the pages
 * will be just 64 Kbytes - for larger machines I will make them a bit
 * bigger (typically 256 Kbytes).  See PAGE_BITS in machine.h.
 *
 * Since this code was first written it has become silly to even consider
 * computers with 16-bit segmented addressing! It is still convenient to
 * allocate memory in chunks, although that does set an upper limit to the
 * size of any individual object: this may hurt if a user wants a big vector
 * and it does constrain the range of big-numbers supported by the
 * artithmetic.
 */

void **pages,
     **heap_pages,
     **vheap_pages,
     **bps_pages,
     **native_pages;
#ifndef NO_COPYING_GC
void **new_heap_pages,
     **new_vheap_pages,
     **new_bps_pages,
     **new_native_pages;
#endif
int32 pages_count,
      heap_pages_count,
      vheap_pages_count,
      bps_pages_count,
      native_pages_count;
#ifndef NO_COPYING_GC
int32 new_heap_pages_count,
      new_vheap_pages_count,
      new_bps_pages_count,
      new_native_pages_count;
#endif

char program_name[64] = {0};

#ifndef COMMON
#ifdef CWIN
/*
 * Could be useful for other windowed systems.
 */
char **loadable_packages, **switches;
#endif
#endif

int native_code_tag;
int native_pages_changed;
int32 native_fringe;
int current_fp_rep;
static int old_fp_rep;
#ifndef ADDRESS_64
static CSLbool flip_needed;
#endif
static int old_page_bits;

/*
 * The next function is handed a page
 * of hard code that has just been loaded into memory and it must scan it
 * performing all relevant relocation. fringe give the offset within the
 * page that is the first byte not in use. The first 4 bytes of the page
 * are reserved for storing fringe from one run to the next. The exact
 * format of the rest must be sufficient to allow this code to scan
 * and correct the code, but thus far I have not defined it, and it will
 * anyway tend to need extension each time a new target architecture is
 * incorporated (to support the new and curious relocation modes tha the
 * new machine requires).
 */

static void relocate_native_code(unsigned char *p, int32 n)
{
/*
 * One helpful observation here. In pretty well all other parts of CSL
 * there is a possibility that an image file created on one computer will
 * be reloaded on another and so all the code is ultra-careful to avoid
 * sensitivity to byte order etc etc issues. But here the native code that
 * is being loaded MUST have been created using the conventions of the
 * current computer (otherwise I should not be loading it and I will be
 * in huge trouble when I try to execute code from it). So direct and
 * simple access to data is legitimate.
 */
    int32 k = 8;
    term_printf("Native code page type %d size %d to be relocated\n",
        native_code_tag, n);
    while (k <= n)
    {   unsigned char *block = p + k;
        int32 len = car32(block);
        term_printf("Block of %d bytes found\n", len);
        if (len == 0)
        {   term_printf("End of native page reached\n");
            break;
        }
        relocate_native_function(block);
        k += len;
    }
}

void relocate_native_function(unsigned char *bps)
{
/*
 * Just for now I will not support native code on 64-bit machines.
 * This is just to save me some hassle re-working this relocation mess!
 */
#ifndef ADDRESS_64 /* No native code for 64-bit architectures yet */
/*
 * Each chunk of memory allocated by make-native will have its length (in
 * bytes) in its first 32-bit word. Next comes the offset of the
 * start of real code in the block. Just after that there will be a
 * hunk of relocation information. The code proper must not start until
 * after the relocation records. Relocation information is stored in the
 * following format as a sequence of bytes:
 *         0                 end of relocation information.
 *         1 to 170/xx       encode a value 0 to 169
 *         171 to 255/xx/yy  extra byte yy extends following offset xx, and
 *                           its top bit is used to extend opcode to range
 *                           0 to 169.
 * The opcode now in the range 0 to 169 is interpreted as
 *         169            no operation
 *         otherwise (0-12)*(0-12) as target*mode
 */
   unsigned char *r = bps + 4;
   unsigned char *next;
   int32 n;
   int code;
   n = *r++;          /* code start offset in LSB format */
   n |= (*r++) << 8;
   n |= (*r++) << 16;
   n |= (*r++) << 24;
   next = bps + n;
#define RELOC_END           0
    while ((code = *r++) != RELOC_END)
    {   int32 off = *r++;
        unsigned char *target;
/*
 * A native compiler will have to generate a sequence of bytes that adhere to
 * the contorted format used here.
 */
        if (code <= 170) code--;
        else
        {   int off1 = *r++;
            code = 2*(code-171) + (off1 >> 7);
            off = off | ((off1 & 0x7f) << 8);
        }
        next += off;   /* address where next relocation is to be applied */
#define RELOC_NOP           169
/*
 * One might like to note that with a long offset the NOP opcode turns into
 * an opcode byte 0xff. And if it then has the longest possible offset one]
 * gets the 3-byte sequence 0xff/0xff/0xff.
 */
        if (code == RELOC_NOP) continue;

#define RELOC_0_ARGS        0
#define RELOC_1_ARGS        1
#define RELOC_2_ARGS        2
#define RELOC_3_ARGS        3
#define RELOC_DIRECT_ENTRY  4
#define RELOC_VAR           5
#define RELOC_SELF_1        6
#define RELOC_SELF_2        7
        switch (code % 13)
        {
    default:
            term_printf("Illegal relocation byte %.2x\n", code);
            my_exit(EXIT_FAILURE);
    case RELOC_SELF_1:
/*
 * base of current native code block with an 8-bit offset.
 */
            target = bps + *r++;
            break;
    case RELOC_SELF_2:
/*
 * base of current native code block with 15 or 23-bit offset. The first byte
 * is the low 8-bits of the offset. The next is the next 7 bits, with its
 * 0x80 bit selecting whether a third byte is needed (which it will hardly
 * ever be).
 */
            off = *r++;
            off = off + (*r++ << 8);
            if (off & 0x8000) off = (off & 0x7fff) + (*r++ << 15);
            target = bps + off;
            break;
    case RELOC_0_ARGS:
/*
 * The next few relocation modes provide access to the C entrypoints
 * associated with a medium number of Lisp functions. The tables and
 * offsets used are documented in file "eval4.c" and are as used with the
 * byte-code compiler.
 */
            target = (unsigned char *)zero_arg_functions[*r++];
            break;
    case RELOC_1_ARGS:
            target = (unsigned char *)one_arg_functions[*r++];
            break;
    case RELOC_2_ARGS:
            target = (unsigned char *)two_arg_functions[*r++];
            break;
    case RELOC_3_ARGS:
            target = (unsigned char *)three_arg_functions[*r++];
            break;
    case RELOC_DIRECT_ENTRY:
/*
 * There are some entrypoints into the CSL kernel that are not
 * called using the usual Lisp conventions but are at a lower-level.
 * A selection of these are visible via the table "useful_functions"
 * in file fns3.c. This table can be extended if a native-mode compiler
 * needs access to any other speciality.
 */
            target = (unsigned char *)useful_functions[*r++];
            break;
    case RELOC_VAR:
/*
 * The function address_f_var (in fns3.c) returns the address of a Lisp
 * internal variable. See there for the numeric encoding used and what can
 * be accessed.
 */
            target = (unsigned char *)address_of_var(*r++);
            break;
        }

#define RELMODE_ABSOLUTE     0
#define RELMODE_RELATIVE     1
#define RELMODE_REL_PLUS_4   2
#define RELMODE_REL_MINUS_2  3
#define RELMODE_REL_MINUS_4  4
#define RELMODE_REL_OFFSET   5
#define RELMODE_SPARE1       6
#define RELMODE_SPARE2       7

        switch (code/13)
        {
    default:
            term_printf("Illegal relocation byte %.2x\n", code);
            my_exit(EXIT_FAILURE);
    case RELMODE_ABSOLUTE:
/*
 * relocate by pointing a 32-bit value directly at the absolute address
 * of the target.
 */
            *(int32 *)next = (int32)target;
            break;
    case RELMODE_RELATIVE:
/*
 * relocate by setting a 32-bit value of the offset from its own first
 * byte to the target.
 */
            *(int32 *)next = (int32)target - (int32)next;
            break;
    case RELMODE_REL_PLUS_4:
/*
 * relocate by setting a 32-bit value of the offset from the start of the
 * word after it.
 */
            *(int32 *)next = (int32)target - ((int32)next + 4);
            break;
    case RELMODE_REL_MINUS_2:
/*
 * relocate by setting a 32-bit value of the offset from the address 2 bytes
 * before its start. This may be used on machines where the relative address
 * is computed based on the start of the instruction rather than the start of
 * the field within the instruction that contains the offset.
 */
            *(int32 *)next = (int32)target - ((int32)next - 2);
            break;
    case RELMODE_REL_MINUS_4:
/*
 * relocate by setting a 32-bit value of the offset from the address 4 bytes
 * before its start. This may be used on machines where the relative address
 * is computed based on the start of the instruction rather than the start of
 * the field within the instruction that contains the offset.
 */
            *(int32 *)next = (int32)target - ((int32)next - 4);
            break;
    case RELMODE_REL_OFFSET:
/*
 * relocate by setting a 32-bit value of the offset from some place
 * offset using an 8-bit signed value from the start of the address. The
 * offset represents the number of bytes after the start of the address
 * that is to be used in the calculation. Note that the special values
 * -4, -2, 0 and 4 need never be used here because there are special
 * relocation modes for those common cases.
 */
            code = *r++;
            if (code & 0x80) code |= ~0xff; /* Sign extend */
            *(int32 *)next = (int32)target - ((int32)next + code);
            break;
        }
    } 
#endif
}

static int32 fread_count;
static unsigned char *fread_ptr;

#ifdef SIXTEEN_BIT
#define FREAD_BUFFER_SIZE 0x4000    /* 16 Kbytes of buffer */
#else
#define FREAD_BUFFER_SIZE 0xc000    /* 48 Kbytes of buffer */
#endif

static unsigned char *pair_c, *char_stack;
static unsigned short int *pair_prev;

static void Cfread(char *p, int32 n)
{
/*
 * The decompression process does not need hashed access to see if
 * character-pairs have been seen before, but it can need a stack to
 * unwind codes that have very lengthy expansions.
 */
    int c1, k;
    unsigned int prev, c, next_code;
    int32 count = fread_count;
    unsigned char *ptr = fread_ptr;
    if (n < compression_worth_while)
    {
#ifdef MAYBE_AVOID_A_DATA_COPY_OPERATION
        if (n > count)
        {   memcpy(p, ptr, (size_t)count);
            p += count;
            n -= count;
        }
        while (n >= FREAD_BUFFER_SIZE)
        {   count = Iread((unsigned char *)p, FREAD_BUFFER_SIZE);
            p += count;
            n -= count;
        }
/*
 * Here I believe that I am in the clear using the (Lisp) stack as
 * a buffer area. This is because Cfread is only used to read heap images,
 * and when such an image is being loaded the contents of the old one
 * (including the stack) are not too relevant.
 */
        ptr = (unsigned char *)stack;
        count = Iread(ptr, FREAD_BUFFER_SIZE);
#endif
        while (n > count)
        {   memcpy(p, ptr, (size_t)count);
            p += count;
            n -= count;
            ptr = (unsigned char *)stack;
            count = Iread(ptr, FREAD_BUFFER_SIZE);
        }
        if (n != 0)
        {   memcpy(p, ptr, (size_t)n);
            ptr += n;
            count -= n;
        }
        fread_count = count;
        fread_ptr = ptr;
        return;
    }

    next_code = 256;

    if (count == 0)
    {   ptr = (unsigned char *)stack;
        count = Iread(ptr, FREAD_BUFFER_SIZE);
    }
    c = *ptr++;
    count--;

    if (count == 0)
    {   ptr = (unsigned char *)stack;
        count = Iread(ptr, FREAD_BUFFER_SIZE);
    }
    c = (c << 8) | *ptr++;
    count--;

    prev = c >> 4;
    *p++ = (char)prev;    /* The first character is not compressed */
    n--;

    while (n > 0)
    {   if (count == 0)
        {   ptr = (unsigned char *)stack;
            count = Iread(ptr, FREAD_BUFFER_SIZE);
        }
        c = ((c & 0xf) << 8) | *ptr++;
        count--;
/*
 * Decode the next 12 bit character
 */
        c1 = c;
        k = 1;
        while (c1 >= 256)
        {   char_stack[k++] = pair_c[c1];
            if (pair_prev[c1] > CODESIZE || k >= CODESIZE)
            {   term_printf("Bad decoded char %x -> %x, k=%d\n", c1, pair_prev[c1], k);
                my_exit(EXIT_FAILURE);
            }
            c1 = pair_prev[c1];
        }
/*
 * Write the decoded stuff into the output array.
 */
        n -= k;
        *p++ = (char)c1;
        while (k != 1)
        {   *p++ = char_stack[--k];
        }
/*
 * ... then build up the decoding tables ready for next time.  Of course
 * the table building in this decoder MUST exactly match the behaviour of
 * the compression code above.
 */
        if (next_code >= CODESIZE) next_code = 256;
        else
        {   pair_prev[next_code] = (unsigned short int)prev;
            pair_c[next_code] = (unsigned char)c1;
            next_code++;
        }
        prev = c;

        if (n <= 0) break;

/*
 * read the next 12 bit character.
 */
        if (count == 0)
        {   ptr = (unsigned char *)stack;
            count = Iread(ptr, FREAD_BUFFER_SIZE);
        }
        c = *ptr++;
        count--;
        if (count == 0)
        {   ptr = (unsigned char *)stack;
            count = Iread(ptr, FREAD_BUFFER_SIZE);
        }
        c = (c << 8) | *ptr++;
        count--;
/*
 * Decode it...
 */
        c1 = c >> 4;
        k = 1;
        while (c1 >= 256)
        {   char_stack[k++] = pair_c[c1];
            if (pair_prev[c1] > CODESIZE || k >= CODESIZE)
            {   term_printf("Bad decoded char %x -> %x, k=%d\n", c1, pair_prev[c1], k);
                my_exit(EXIT_FAILURE);
            }
            c1 = pair_prev[c1];
        }
/*
 * Write the decoded stuff into the output array.
 */
        n -= k;
        *p++ = (char)c1;
        while (k != 1)
        {   *p++ = char_stack[--k];
        }
/*
 * ... then build up the decoding tables ready for next time.  Of course
 * the table building in this decoder MUST exactly match the behaviour of
 * the compression code above.
 */
        if (next_code >= CODESIZE) next_code = 256;
        else
        {   pair_prev[next_code] = (unsigned short int)prev;
            pair_c[next_code] = (unsigned char)c1;
            next_code++;
        }
        prev = c >> 4;
    }
    fread_count = count;
    fread_ptr = ptr;
}

#ifdef ADDRESS_64
#define flip_bytes(a) (a)
#else
#define flip_bytes(a) (flip_needed ? flip_bytes_fn(a) : (a))
#endif

static unsigned32 flip_bytes_fn(unsigned32 x)
{
    unsigned32 b0, b1, b2, b3;
    b0 = (x >> 24) & 0xffU;
    b1 = (x >> 8) & 0xff00U;
    b2 = (x << 8) & 0xff0000U;
    b3 = (x << 24) & 0xff000000U;
    return b0 | b1 | b2 | b3;
}

#ifdef ADDRESS_64
#define flip_halfwords(a) (a)
#else
#define flip_halfwords(a) (flip_needed ? flip_halfwords_fn(a) : (a))

static unsigned32 flip_halfwords_fn(unsigned32 x)
{
    unsigned32 b0, b1, b2, b3;
    b0 = (x >> 8) & 0xffU;
    b1 = (x << 8) & 0xff00U;
    b2 = (x >> 8) & 0xff0000U;
    b3 = (x << 8) & 0xff000000U;
    return b0 | b1 | b2 | b3;
}
#endif


void convert_fp_rep(void *p, int old_rep, int new_rep, int type)
{
#ifndef ADDRESS_64
    unsigned32 *f = (unsigned32 *)p;
    if (old_rep == new_rep) return;
/*
 * type == 0 for sfloat, 1 for single float, 2 for double and 3 for extended.
 * in CSL mode only case 2 can arise.
 */
/*
 * At present conversions involving IBM370 or VAX representations are not
 * supported, i.e. only IEEE floating point units are allowed for.
 * Extended mode is not implemented yet... i.e. I only really expect
 * to be using (64-bit) double precision floating point values.
 */
    if (type >= 2 && ((old_rep ^ new_rep) & FP_WORD_ORDER))
    {   unsigned32 w = f[0];
        f[0] = f[1];
        f[1] = w;
    }
    if ((old_rep ^ new_rep) & FP_BYTE_ORDER)
    {   f[0] = flip_bytes_fn(f[0]);
        if (type >= 2) f[1] = flip_bytes_fn(f[1]);
    }
    if ((old_rep|new_rep) & (FP_VAXREP|FP_IBMREP))
    {   term_printf(
        "\n+++ This cross-floating representation conversion not supported\n");
/*
 * I have not implemented conversions that involve VAX or s/370 representations
 */
        my_exit(EXIT_FAILURE);
    }
#endif
    return;
}

static void adjust(Lisp_Object *cp)
/*
 * If p is a pointer to an object that has moved, adjust it.
 */
{
    Lisp_Object nil = C_nil, p = flip_bytes(*cp);
    if  (p == SPID_NIL) *cp = nil;
    else if (is_cons(p))
    {   intxx h = (intxx)heap_pages[(p>>PAGE_BITS) & PAGE_MASK];
        *cp = (Lisp_Object)((char *)quadword_align_up(h) +
                            (p & OFFSET_MASK));
    }
    else if (is_immed_or_cons(p))
    {
#ifdef COMMON
        if (is_sfloat(p))
        {   intxx w = flip_bytes(p);    /* delicate here!! */
            convert_fp_rep((void *)&w, old_fp_rep, current_fp_rep, 0);
            *cp = w;
        }
#endif
        *cp = p;   /* Immediate data here */
    }
    else
    {   intxx h = (intxx)vheap_pages[(p>>PAGE_BITS) & PAGE_MASK];
        *cp = (Lisp_Object)((char *)doubleword_align_up(h) +
                            (p & OFFSET_MASK));
    }
}

static void adjust_consheap(void)
{
    nil_as_base
    int32 page_number;
    for (page_number = 0; page_number < heap_pages_count; page_number++)
    {   void *page = heap_pages[page_number];
        char *low = (char *)quadword_align_up((intxx)page);
        char *start = low + CSL_PAGE_SIZE;
        int32 len = flip_bytes((unsigned32)car32(low));
        char *fr;
        qcar(low) = len;
        fr = low + len;
        fringe = (Lisp_Object)fr;
        heaplimit = (Lisp_Object)(low + SPARE);
        while (fr < start)
        {   adjust((Lisp_Object *)fr);
            fr += sizeof(Lisp_Object);
        }
    }
}

entry_point entries_table[] =
{
/*
 * All values that can go in the function cells of symbols to stand for
 * special interpreter activity are kept here. In most cases where there
 * is an entrypoint there is a corresponding one that behaves just the
 * same except that it has tracing enabled.
 */
    {0,                                          "xillegal"},
    {(void *)undefined1,                         "1undefined1"},
    {(void *)undefined2,                         "2undefined2"},
    {(void *)undefinedn,                         "nundefinedn"},
    {(void *)autoload1,                          "1autoload1"},
    {(void *)autoload2,                          "2autoload2"},
    {(void *)autoloadn,                          "nautoloadn"},
    {(void *)interpreted1,                       "1interpreted1"},
    {(void *)traceinterpreted1,                  "1traceinterpreted1"},
    {(void *)double_interpreted1,                "1double_interpreted1"},
    {(void *)interpreted2,                       "2interpreted2"},
    {(void *)traceinterpreted2,                  "2traceinterpreted2"},
    {(void *)double_interpreted2,                "2double_interpreted2"},
    {(void *)interpretedn,                       "ninterpretedn"},
    {(void *)traceinterpretedn,                  "ntraceinterpretedn"},
    {(void *)double_interpretedn,                "ndouble_interpretedn"},
    {(void *)funarged1,                          "1funarged1"},
    {(void *)tracefunarged1,                     "1tracefunarged1"},
    {(void *)double_funarged1,                   "1double_funarged1"},
    {(void *)funarged2,                          "2funarged2"},
    {(void *)tracefunarged2,                     "2tracefunarged2"},
    {(void *)double_funarged2,                   "2double_funarged2"},
    {(void *)funargedn,                          "nfunargedn"},
    {(void *)tracefunargedn,                     "ntracefunargedn"},
    {(void *)double_funargedn,                   "ndouble_funargedn"},
    {(void *)bytecoded0,                         "nbytecoded0"},
    {(void *)tracebytecoded0,                    "ntracebytecoded0"},
    {(void *)double_bytecoded0,                  "ndouble_bytecoded0"},
    {(void *)bytecoded1,                         "1bytecoded1"},
    {(void *)tracebytecoded1,                    "1tracebytecoded1"},
    {(void *)double_bytecoded1,                  "1double_bytecoded1"},
    {(void *)bytecoded2,                         "2bytecoded2"},
    {(void *)tracebytecoded2,                    "2tracebytecoded2"},
    {(void *)double_bytecoded2,                  "2double_bytecoded2"},
    {(void *)bytecoded3,                         "nbytecoded3"},
    {(void *)tracebytecoded3,                    "ntracebytecoded3"},
    {(void *)double_bytecoded3,                  "ndouble_bytecoded3"},
    {(void *)bytecodedn,                         "nbytecodedn"},
    {(void *)tracebytecodedn,                    "ntracebytecodedn"},
    {(void *)double_bytecodedn,                  "ndouble_bytecodedn"},
    {(void *)byteopt1,                           "1byteopt1"},
    {(void *)tracebyteopt1,                      "1tracebyteopt1"},
    {(void *)double_byteopt1,                    "1double_byteopt1"},
    {(void *)byteopt2,                           "2byteopt2"},
    {(void *)tracebyteopt2,                      "2tracebyteopt2"},
    {(void *)double_byteopt2,                    "2double_byteopt2"},
    {(void *)byteoptn,                           "nbyteoptn"},
    {(void *)tracebyteoptn,                      "ntracebyteoptn"},
    {(void *)double_byteoptn,                    "ndouble_byteoptn"},
    {(void *)hardopt1,                           "1hardopt1"},
    {(void *)tracehardopt1,                      "1tracehardopt1"},
    {(void *)double_hardopt1,                    "1double_hardopt1"},
    {(void *)hardopt2,                           "2hardopt2"},
    {(void *)tracehardopt2,                      "2tracehardopt2"},
    {(void *)double_hardopt2,                    "2double_hardopt2"},
    {(void *)hardoptn,                           "nhardoptn"},
    {(void *)tracehardoptn,                      "ntracehardoptn"},
    {(void *)double_hardoptn,                    "ndouble_hardoptn"},
    {(void *)byteoptrest1,                       "1byteoptrest1"},
    {(void *)tracebyteoptrest1,                  "1tracebyteoptrest1"},
    {(void *)double_byteoptrest1,                "1double_byteoptrest1"},
    {(void *)byteoptrest2,                       "2byteoptrest2"},
    {(void *)tracebyteoptrest2,                  "2tracebyteoptrest2"},
    {(void *)double_byteoptrest2,                "2double_byteoptrest2"},
    {(void *)byteoptrestn,                       "nbyteoptrestn"},
    {(void *)tracebyteoptrestn,                  "ntracebyteoptrestn"},
    {(void *)double_byteoptrestn,                "ndouble_byteoptrestn"},
    {(void *)hardoptrest1,                       "1hardoptrest1"},
    {(void *)tracehardoptrest1,                  "1tracehardoptrest1"},
    {(void *)double_hardoptrest1,                "1double_hardoptrest1"},
    {(void *)hardoptrest2,                       "2hardoptrest2"},
    {(void *)tracehardoptrest2,                  "2tracehardoptrest2"},
    {(void *)double_hardoptrest2,                "2double_hardoptrest2"},
    {(void *)hardoptrestn,                       "nhardoptrestn"},
    {(void *)tracehardoptrestn,                  "ntracehardoptrestn"},
    {(void *)double_hardoptrestn,                "ndouble_hardoptrestn"},
    {(void *)too_many_1,                         "2too_many_1"},
    {(void *)wrong_no_1,                         "nwrong_no_1"},
    {(void *)too_few_2,                          "1too_few_2"},
    {(void *)wrong_no_2,                         "nwrong_no_2"},
    {(void *)wrong_no_0a,                        "1wrong_no_0a"},
    {(void *)wrong_no_0b,                        "2wrong_no_0b"},
    {(void *)wrong_no_3a,                        "1wrong_no_3a"},
    {(void *)wrong_no_3b,                        "2wrong_no_3b"},
    {(void *)wrong_no_na,                        "1wrong_no_na"},
    {(void *)wrong_no_nb,                        "2wrong_no_nb"},
/*
 * As a matter of convenience I will put stream-handling functions here
 * too -- they are not kept in symbol headers but in stream control
 * blocks, but they too need careful treatment across preserve/restart.
 */
    {(void *)char_from_illegal,                  "Xchar_from_illegal"},
    {(void *)char_to_illegal,                    "Xchar_to_illegal"},
    {(void *)read_action_illegal,                "Xread_action_illegal"},
    {(void *)write_action_illegal,               "Xwrite_action_illegal"},
    {(void *)char_from_terminal,                 "Xchar_from_terminal"},
    {(void *)char_to_terminal,                   "Xchar_to_terminal"},
    {(void *)read_action_terminal,               "Xread_action_terminal"},
    {(void *)write_action_terminal,              "Xwrite_action_terminal"},
    {(void *)char_from_file,                     "Xchar_from_file"},
    {(void *)char_to_file,                       "Xchar_to_file"},
    {(void *)read_action_file,                   "Xread_action_file"},
    {(void *)read_action_output_file,            "Xread_action_output_file"},
    {(void *)write_action_file,                  "Xwrite_action_file"},
    {(void *)binary_outchar,                     "Xbinary_outchar"},
    {(void *)char_from_list,                     "Xchar_from_list"},
    {(void *)char_to_list,                       "Xchar_to_list"},
    {(void *)code_to_list,                       "Xcode_to_list"},
    {(void *)read_action_list,                   "Xread_action_list"},
    {(void *)write_action_list,                  "Xwrite_action_list"},
    {(void *)count_character,                    "Xcount_character"},
    {(void *)char_to_pipeout,                    "Xchar_to_pipeout"},
    {(void *)write_action_pipe,                  "Xwrite_action_pipe"},
    {(void *)char_from_synonym,                  "Xchar_from_synonym"},
    {(void *)char_to_synonym,                    "Xchar_to_synonym"},
    {(void *)read_action_synonym,                "Xread_action_synonym"},
    {(void *)write_action_synonym,               "Xwrite_action_synonym"},
    {(void *)char_from_concatenated,             "Xchar_from_concatenated"},
    {(void *)char_to_broadcast,                  "Xchar_to_broadcast"},
    {(void *)read_action_concatenated,           "Xread_action_concatenated"},
    {(void *)write_action_broadcast,             "Xwrite_action_broadcast"},
    {(void *)char_from_echo,                     "Xchar_from_echo"},
/*
 * The batch here relate to function re-work that discards unwanted
 * extra arguments.
 */
    {(void *)f0_as_0,                            "n0->0"},
    {(void *)f1_as_0,                            "11->0"},
    {(void *)f2_as_0,                            "22->0"},
    {(void *)f3_as_0,                            "n3->0"},
    {(void *)f1_as_1,                            "11->1"},
    {(void *)f2_as_1,                            "22->1"},
    {(void *)f3_as_1,                            "n3->1"},
    {(void *)f2_as_2,                            "22->2"},
    {(void *)f3_as_2,                            "n3->2"},
    {(void *)f3_as_3,                            "n3->3"},
#ifdef CJAVA
    {(void *)java0,                              "njava0"},
    {(void *)java1,                              "1java1"},
    {(void *)java2,                              "2java2"},
    {(void *)java3,                              "njava3"},
    {(void *)javan,                              "njavan"},
#endif
    {NULL,                                       "Xdummy"}
};

static void adjust_vecheap(void)
{
    nil_as_base
    int32 page_number, i;
    intxx iw;
    for (page_number = 0; page_number < vheap_pages_count; page_number++)
    {   void *page = vheap_pages[page_number];
        char *low = (char *)doubleword_align_up((intxx)page);
        int32 len = flip_bytes((unsigned32)car32(low));
        char *fr;
        qcar(low) = len;
        fr = low + len;
        vfringe = (Lisp_Object)fr;
        vheaplimit = (Lisp_Object)(low + (CSL_PAGE_SIZE - 8));
        low += 8;
        while (low < fr)
        {   Header h = flip_bytes(*(Header *)low);
            *(Header *)low = h;
            if (is_symbol_header(h))
            {   Lisp_Object ss = (Lisp_Object)(low + TAG_SYMBOL);
                adjust(&qvalue(ss));
                adjust(&qenv(ss));
                adjust(&qpname(ss));
                adjust(&qplist(ss));
                adjust(&qfastgets(ss));
#ifdef COMMON
                adjust(&qpackage(ss));
#endif
/*
 * The mess here is because when CSL is re-loaded the position of all
 * C-coded entrypoints will very probably have changed since the
 * previous run - the set of entrypoints tested for here has to be
 * a complete list, except for ones established via "restart.c".  Note
 * that setup establishes entrypoints later on, so I can afford to leave
 * junk in the function cells of things that will be initialised then.
 * Thus if a "real" function pointer left over from last time happens
 * to look like one of the small integers used here to stand for special
 * built-in cases the false-hit I get here is not important.
 */
                iw = flip_bytes(ifn1(ss));
/*
 * Another delicacy - somebody intent on cleaning up this code may spot the
 * cast from a function pointer to an integer here, and decide it would be
 * neater to make entries_table[] contain a union type that could hide the
 * conversion. But that MIGHT not be good enough if sizeof(void *)==8 and
 * sizeof(int32)==4, but it has been arranged that all pointers used have
 * their 32 most significant bits all zero..... And this odd case can be
 * persuaded to apply on a DEC Alpha!  The cast as written here really does
 * change data representation, but with luck does not lose any vital
 * information. Well that is in the "taso" case, but in other 64-bit cases
 * it is yet different. Ugh.
 */
                if (0 < iw && iw < entry_table_size)
                {   if (*entries_table[iw].s != '1')
                    {   term_printf("?fn1 cell %d %s\n", iw,
                                    entries_table[iw].s);
                    }
                    ifn1(ss) = (intxx)entries_table[iw].p;
                }
                else ifn1(ss) = (intxx)undefined1;
                iw = flip_bytes(ifn2(ss));
                if (0 < iw && iw < entry_table_size)
                {   if (*entries_table[iw].s != '2')
                    {   term_printf("?fn2 cell %d %s\n", iw,
                                    entries_table[iw].s);
                    }
                    ifn2(ss) = (intxx)entries_table[iw].p;
                }
                else ifn2(ss) = (intxx)undefined2;
                iw = flip_bytes(ifnn(ss));
                if (0 < iw && iw < entry_table_size)
                {   if (*entries_table[iw].s != 'n')
                    {   term_printf("?fnn cell %d %s\n", iw,
                                    entries_table[iw].s);
                    }
                    ifnn(ss) = (intxx)entries_table[iw].p;
                }
                else ifnn(ss) = (intxx)undefinedn;
                qcount(ss) = flip_bytes(qcount(ss));
                low += symhdr_length;
                continue;
            }
            else switch (type_of_header(h))
            {
#ifdef COMMON
        case TYPE_RATNUM:
        case TYPE_COMPLEX_NUM:
                adjust((Lisp_Object *)(low+CELL));
                adjust((Lisp_Object *)(low+2*CELL));
                break;
#endif
        case TYPE_HASH:
        case TYPE_SIMPLE_VEC:
        case TYPE_ARRAY:
        case TYPE_STRUCTURE:
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=CELL)
                    adjust((Lisp_Object *)(low+i));
                break;
        case TYPE_MIXED1:
        case TYPE_MIXED2:
        case TYPE_MIXED3:
        case TYPE_STREAM:
                for (i=CELL; i<4*CELL; i+=CELL) adjust((Lisp_Object *)(low+i));
#ifndef ADDRESS_64
                for (; i<doubleword_align_up(length_of_header(h)); i+=4)
                    *(unsigned32 *)(low+i) =
                        flip_bytes(*(unsigned32 *)(low+i));
#endif
                if (type_of_header(h) == TYPE_STREAM)
                {   Lisp_Object ss = (Lisp_Object)(low + TAG_VECTOR);
                    iw = elt(ss, 4);
                    if (0 < iw && iw < entry_table_size)
                    {   if (*entries_table[iw].s != 'X')
                            term_printf("Stream fn %d %s\n", iw, entries_table[iw].s);
                        elt(ss, 4) = (intxx)entries_table[iw].p;
                    }
                    else elt(ss, 4) = (intxx)char_to_illegal;
                    iw = elt(ss, 5);
                    if (0 < iw && iw < entry_table_size)
                    {   if (*entries_table[iw].s != 'X')
                            term_printf("Stream fn %d %s\n", iw, entries_table[iw].s);
                        elt(ss, 5) = (intxx)entries_table[iw].p;
                    }
                    else elt(ss, 5) = (intxx)write_action_illegal;
                    iw = elt(ss, 8);
                    if (0 < iw && iw < entry_table_size)
                    {   if (*entries_table[iw].s != 'X')
                            term_printf("Stream fn %d %s\n", iw, entries_table[iw].s);
                        elt(ss, 8) = (intxx)entries_table[iw].p;
                    }
                    else elt(ss, 8) = (intxx)char_from_illegal;
                    iw = elt(ss, 9);
                    if (0 < iw && iw < entry_table_size)
                    {   if (*entries_table[iw].s != 'X')
                            term_printf("Stream fn %d %s\n", iw, entries_table[iw].s);
                        elt(ss, 9) = (intxx)entries_table[iw].p;
                    }
                    else elt(ss, 9) = (intxx)read_action_illegal;
                }
                break;
        case TYPE_BIGNUM:
        case TYPE_VEC32:
#ifndef ADDRESS_64
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=4)
                    *(unsigned32 *)(low+i) =
                        flip_bytes(*(unsigned32 *)(low+i));
#endif
                break;
        case TYPE_VEC16:
#ifndef ADDRESS_64
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=4)
                    *(unsigned32 *)(low+i) =
                        flip_halfwords(*(unsigned32 *)(low+i));
#endif
                break;
        case TYPE_DOUBLE_FLOAT:
/*
 * note that this conversion is triggered by the vector header, not by
 * the pointer to the object, so punning associated with the pnames of
 * un-printed gensyms will not cause any confusion.
 */
                convert_fp_rep((void *)(low + 8),
                               old_fp_rep, current_fp_rep, 2);
                break;
#ifdef COMMON
        case TYPE_SINGLE_FLOAT:
                convert_fp_rep((void *)(low + CELL),
                               old_fp_rep, current_fp_rep, 1);
                break;
        case TYPE_LONG_FLOAT:
/* Beware - if long floats move up to 3-word values the +8 here will change */
                convert_fp_rep((void *)(low + 8),
                               old_fp_rep, current_fp_rep, 3);
                break;
#endif
        case TYPE_FLOAT32:
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=4)
                    convert_fp_rep((void *)(low+i),
                                   old_fp_rep, current_fp_rep, 1);
                break;
        case TYPE_FLOAT64:
                for (i=8; i<doubleword_align_up(length_of_header(h)); i+=8)
                    convert_fp_rep((void *)(low+i),
                                   old_fp_rep, current_fp_rep, 2);
                break;
        default:
                break;
            }
            low += doubleword_align_up(length_of_header(h));
        }
    }
}

static void adjust_bpsheap(void)
/*
 * This is needed so that (e.g.) headers in the code here get byte-flipped
 * if necessary.  Also to set codefringe.
 */
{
    nil_as_base
    int32 page_number;
#ifdef ENVIRONMENT_VECTORS_IN_BPS_HEAP
    int32 i;
#endif
    codelimit = codefringe = 0;
    for (page_number = 0; page_number < bps_pages_count; page_number++)
    {   void *page = bps_pages[page_number];
        char *low = (char *)doubleword_align_up((intxx)page);
        int32 len = flip_bytes((unsigned32)car32(low));
        char *fr;
        qcar(low) = len;
        fr = low + len;
        codefringe = (Lisp_Object)fr;
        codelimit = (Lisp_Object)(low + 8);
        while (fr < low + CSL_PAGE_SIZE)
        {   Header h = flip_bytes(*(Header *)fr);
            *(Header *)fr = h;
#ifdef ENVIRONMENT_VECTORS_IN_BPS_HEAP
            switch (type_of_header(h))
            {
        case TYPE_SIMPLE_VEC:   /* This option not used at present */
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=CELL)
                    adjust((Lisp_Object *)(fr+i));
                break;
        default:
                break;
            }
#endif
            fr += doubleword_align_up(length_of_header(h));
        }
    }
}

void adjust_all(void)
{
    int32 i;
    Lisp_Object nil = C_nil;
    qheader(nil)  = TAG_ODDS+TYPE_SYMBOL+SYM_SPECIAL_VAR;
#ifdef COMMON
    qheader(nil) |= SYM_EXTERN_IN_HOME;
#endif
    qvalue(nil)   = nil;
    qenv(nil)     = nil;
    ifn1(nil)     = (intxx)undefined1;
    ifn2(nil)     = (intxx)undefined2;
    ifnn(nil)     = (intxx)undefinedn;
    adjust(&(qpname(nil)));     /* not a gensym */
    adjust(&(qplist(nil)));
    adjust(&(qfastgets(nil)));
#ifdef COMMON
    adjust(&(qpackage(nil)));
#endif

    copy_into_nilseg(NO);
    for (i = first_nil_offset; i<last_nil_offset; i++)
        adjust(&BASE[i]);
    copy_out_of_nilseg(NO);

    adjust_consheap();
    adjust_vecheap();
    adjust_bpsheap();
}

static void *allocate_page(void)
{
    if (pages_count == 0) fatal_error(err_no_store);
    return pages[--pages_count];
}

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
intxx memory_base, memory_size, memory_count, memory_records = 0;
unsigned char *memory_map = NULL;
static intxx memory_lowest = 0x7fffffff, memory_highest = -1;
FILE *memory_file = NULL;

void memory_comment(int n)
{
    if (memory_map != NULL)
    {   putc(0xc0 + (n & 0x3f), memory_file);
        putc(0, memory_file);
        putc(0, memory_file);
    }
}

int kk = 0;

static void identify_one(void *p, intxx size, int type)
{
    int32 i, j;
    intxx base = (intxx)p;
    int32 a = 0, b = 0;
    intxx da = 1, db = 1;
    intxx click = size/0x400;
    switch (type)
    {
case 0:  b = click; break;
case 1:  db = -1;   break;
case 2:  b = click; da = db = 2; break;
case 3:  da = 2; db = -2; break;
case 4:  db = 0; break;
case 5:  da = -1; db = 0; break;
default: b = click; da = db = 0; break;
    }
    if (size > 256)
    {   da *= (size/256);
        db *= (size/256);
    }
    memory_count |= 0x3ff;
    cmemory_reference(base);
    memory_comment(kk ? 3 : 5);
    kk = !kk;
    for (i=0; i<32; i++)
    {   int x;
        memory_count |= 0x3ff;
        cmemory_reference(base);
        for (j=0; j<0x400; j++)
        {   x = a + j*(size/8);
            while (x > size) x -= size;
            while (x < 0) x += size;
            cmemory_reference(base+x);
            x = b + j*(size/8);
            while (x > size) x -= size;
            while (x < 0) x += size;
            cmemory_reference(base+x);
        }
        a += da;
        b += db;
    }
}

static void identify_page(void *p[], int32 n, int type)
{
    while (n != 0)
    {   void *w = p[--n];
        if (w != NULL) identify_one(w, CSL_PAGE_SIZE, type);
    }
}

void identify_page_types()
{
    identify_page(pages,               pages_count,            0);
    identify_page(heap_pages,          heap_pages_count,       1);
    identify_page(vheap_pages,         vheap_pages_count,      2);
    identify_page(bps_pages,           bps_pages_count,        3);
    identify_page(native_pages,        native_pages_count,     4);
    identify_one((void *)stacksegment, CSL_PAGE_SIZE,          5);
    identify_one((void *)nilsegment,   NIL_SEGMENT_SIZE,       6);
}

#endif /* CHECK_ONLY */

long int car_counter;
unsigned long int car_low, car_high;

Cons_Cell *memory_reference(intxx p)
{
    if (p & 0x7)
    {   term_printf("Access to mis-aligned address %.8x\n", (int)p);
        ensure_screen();
        abort();
    }
    return (Cons_Cell *)cmemory_reference(p);
}

char *cmemory_reference(intxx p)
{
#ifdef CHECK_ONLY
    return (char *)p;
#else
    intxx a = p - memory_base;
    if (memory_map != NULL && a >= 0 && a < memory_size)
    {   int bit;
        a = a >> 2;                          /* Get a word address */
        a = a >> 2;                          /* reduce to 4-word resolution */
        if (memory_count >= car_counter &&
            (unsigned long int)a >= car_low &&
            (unsigned long int)a <= car_high)
        {   Lisp_Object nil = C_nil;
            if (exception_pending()) nil = (Lisp_Object)((intxx)nil ^ 1);
            interrupt_pending = 1;
#ifdef SOFTWARE_TICKS
            countdown = 0;
#else
#ifdef TICK_STREAM
            deal_with_tick();  /* pretend tick arrived here and now */
#endif
#endif
            miscflags |= HEADLINE_FLAG | MESSAGES_FLAG;
            car_counter = 0x7fffffff; /* Do not interrupt again */
        }
        bit = 1 << (a & 7);
        a = a >> 3;
        if (a < memory_lowest) memory_lowest = a;
        if (a > memory_highest) memory_highest = a;
        memory_map[a] |= bit;
        if ((++memory_count & 0x3ff) == 0)   /* Every 1024 references... */
        {   unsigned char *pp;
            int c;
            int32 run = 0, i;
/*
 * I use a run-length encoded representation for the file that I write out.
 * Each scan-line is stored as a collection of bytes each of which indicates
 * the number of '0' items before the next '1' in the bit-vector. The encoding
 * of individual lengths is as follows:
 *     0 - 127          1 byte
 *     128 - 16K        First byte has 0x80 plus 6 bits of data (+ 1 more)
 *     16K - 4M         First byte has 0xc0 plus 6 bits of data (+ 2 more)
 *     The byte pair (0x8n, 0x00) stands for n times 4M as a a prefix to
 *     one of the above. This gives up to 2^28 as the max span.
 *     The byte pair (0x80, 0x00) can be used to terminate a line.
 *     Codes (0xcn, 0x00, 0x00) give 64 special codes that can be used
 *     to interveave comments and annotations within the stream.
 */
            pp = memory_map + memory_lowest;
            run = 8*memory_lowest;
            for (i=memory_lowest; i<=memory_highest; i++)
            {   c = *pp++;
                if (c != 0)
                {   bit = 1;
                    while ((c & bit) == 0) run++, bit = bit << 1;
                    if (run >= 0x400000)
                    {   putc(0x80 + ((run >> 22) & 0x3f), memory_file);
                        putc(0x00, memory_file);
                        run &= 0x3fffff;
                    }
                    if (run < 0x80) putc(run, memory_file);
                    else if (run < 0x4000)
                    {   putc(0x80 + (run & 0x3f), memory_file);
                        putc((run >> 6) & 0xff, memory_file);
                    }
                    else
                    {   putc(0xc0 + (run & 0x3f), memory_file);
                        putc((run >> 6) & 0xff, memory_file);
                        putc((run >> 14) & 0xff, memory_file);
                    }
                    c &= ~bit;
                    run = 0;
                    bit = bit << 1;
                    while (c != 0)
                    {   while ((c & bit) == 0) run++, bit = bit << 1;
                        putc(run, memory_file);
                        c &= ~bit;
                        run = 0;
                        bit = bit << 1;
                    }
                    while (bit != 0x100) run++, bit = bit << 1;
                }
                else run += 8;
            }
            putc(0x80, memory_file);
            putc(0x00, memory_file);
            memory_lowest = 0x7fffffff;
            memory_highest = -1;
            memset(memory_map, 0, memory_size/32+8);
            memory_records++;
        }
    }
    return (char *)p;
#endif /* CHECK_ONLY */
}

#endif

static char *global_handle;

void *my_malloc(size_t n)
{
#ifdef NO_WORRY_ABOUT_MEMORY_PROBLEMS
    return (*malloc_hook)(n);
#else
#define EXPLICIT_FREE_AT_END_OF_RUN  1
    char *r = (char *)(*malloc_hook)(n+64);
    int32 *p = (int32 *)quadword_align_up(r);
    if (r == NULL) return NULL;
    n = quadword_align_up(n);
    inject_randomness((int)(intxx)r);
    p[1] = 0;
    ((void **)p)[0] = r;          /* base address for free() */
    p[2] = n;                     /* only permit 32-bit size */
    p[3] = 0x5555aaaa;
    p[4] = 0x12345678;            /* Marker words for security */
    p[5] = 0x3456789a;
    p[6] = 0x12345678;
    p[7] = 0x3456789a;
    r = (char *)&p[8];
    car32(r+n)   = 0x87654321;
    car32(r+n+4) = 0xcba98765;
    return (void *)r;
#endif
}

#ifndef HOLD_BACK_MEMORY
static char *big_chunk_start, *big_chunk_end;
#endif

#ifdef EXPLICIT_FREE_AT_END_OF_RUN

static void my_free(void *r)
{
#ifdef NO_WORRY_ABOUT_MEMORY_PROBLEMS
#ifndef HOLD_BACK_MEMORY
    char *rr = (char *)r;
/*
 * I will not free it if the pointer is strictly inside the single big
 * chunk that I grabbed at the start of the run.
 */
    if (rr > big_chunk_start && rr <= big_chunk_end) return;
#endif
    int *p, *q, n;
    *(free_hook)(r);
#else /* NO_WORRY... */
    int32 *p, *q, n;
#ifndef HOLD_BACK_MEMORY
    char *rr = (char *)r;
/*
 * I will not free it if the pointer is strictly inside the single big
 * chunk that I grabbed at the start of the run.
 */
    if (rr > big_chunk_start && rr <= big_chunk_end) return;
#endif
    p = (int32 *)r - 8;
    n = p[2];
    if (p[4] != 0x12345678 ||
        p[5] != 0x3456789a)
    {   term_printf("Corruption at start of memory block %p: %.8x %.8x\n",
            r, p[4], p[5]);
        ensure_screen();
        my_exit(0);
    }
    q = (int32 *)((char *)r + n);
    if (q[0] != 0x87654321 ||
        q[1] != 0xcba98765)
    {   term_printf("Corruption at end of memory block %p: %.8x %.8x\n",
            r, q[0], q[1]);
        ensure_screen();
        my_exit(0);
    }
    (*free_hook)((void *)((void **)p)[0]);
#endif
}

#endif

static void *my_malloc_1(size_t n)
/*
 * This is a pretty silly function - it gobbles up 24Kbytes of
 * stack and then just calls malloc - it stuffs a pointer to the
 * stack-chunk into a static variable so that compilers can not
 * detect (I hope!) that the array remains unused.  The purpose of this
 * is to make malloc fail if it is about to encroach on space that
 * should be used for stack.  This is relevant on small systems where
 * stack and heap grow towards one another and where one space has been
 * grabbed by malloc it is unavailable for stack (even if it is FREEd).
 * The number 24000 is pretty arbitrary - but if I have 24K bytes of stack
 * I will be able to do at least something.
 * Also this code verifies that the memory addresses returned have the
 * correct most significant bit. I allocate just a bit more memory than
 * is really needed to leave a one-word (or so) guard-band between
 * allocated blocks. This is necessary on some releases of an SGI C
 * compiler (library) where blocks of memory that are word but not
 * doubleword aligned can be returned.
 */
{
    char gobble_stack[24000];
    char *r;
    intxx pun, pun1;
    global_handle = gobble_stack;
    r = (char *)my_malloc(n+16);
    pun = (intxx)r;
    pun1 = (intxx)(r + n);
/*
 * I will moan if the block of memory allocated spans zero.
 * Note that if this does happen then something very funny is happening
 * about 0 cast to a pointer (i.e. a NULL pointer) since NULL is supposed
 * not to be valid as an address (?) but appears to be within the address
 * range of the block of store just allocated.
 */
    if ((pun ^ pun1) < 0) fatal_error(err_mem_spans_zero);
/*
 * Now if I get a block with the "wrong" top bit I will just return NULL
 * to suggest that no more memory was available - CSL can then proceed
 * or fail as it sees fit.
 */
#ifdef ADDRESS_SIGN_UNKNOWN
/*
 * For dynamic address sign I should not test the address sign on the
 * first call - instead I just remember what it was.  On subsequent calls
 * I will check it.
  */
    if (nilsegment != NULL)
    {   if ((pun + address_sign) < 0) return NULL;
                                      /* fatal_error(err_top_bit); */
    }
    else address_sign = pun & 0x80000000;
#else
#ifdef ADDRESSES_HAVE_TOP_BIT_SET
    if (pun > 0) return NULL; /* fatal_error(err_top_bit); */
#else
    if (pun < 0) return NULL; /* fatal_error(err_top_bit); */
#endif
#endif
    return (void *)r;
}

static void *my_malloc_2(size_t n)
/*
 * Rather like my_malloc_1(), but does NOT check the sign bit of the
 * returned pointer. Provided as a place to put hooks to check memory
 * allocation problems.
 */
{
    char gobble_stack[24000];
    char *r;
    global_handle = gobble_stack;
    r = (char *)my_malloc(n+16);
    return (void *)r;
}

static void init_heap_segments(double store_size)
/*
 * This function just makes nil and the pool of page-frames available
 */
{
    char *memfile = "memory.use"; /* For memory statistics etc */
    pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    heap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    vheap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    bps_pages = (void **)my_malloc_2(MAX_BPS_PAGES*sizeof(void *));
    native_pages = (void **)my_malloc_2(MAX_NATIVE_PAGES*sizeof(void *));
#ifndef NO_COPYING_GC
    new_heap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    new_vheap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    new_bps_pages = (void **)my_malloc_2(MAX_BPS_PAGES*sizeof(void *));
    new_native_pages = (void **)my_malloc_2(MAX_NATIVE_PAGES*sizeof(void *));
#endif
    pair_c = (unsigned char *)my_malloc_2(CODESIZE);
/*
 * The next line is utterly unsatisfactory at present
 */
    char_stack = (unsigned char *)my_malloc_2(CSL_PAGE_SIZE+16 /*CODESIZE*/);
    pair_prev = (unsigned short int *)
                    my_malloc_2(CODESIZE*sizeof(unsigned short int));
    if (pages == NULL ||
#ifndef NO_COPYING_GC
        new_heap_pages == NULL ||
        new_vheap_pages == NULL ||
        new_bps_pages == NULL ||
        new_native_pages == NULL ||
#endif
        heap_pages == NULL ||
        vheap_pages == NULL ||
        bps_pages == NULL ||
        native_pages == NULL ||
        pair_c == NULL ||
        char_stack == NULL ||
        pair_prev == NULL) fatal_error(err_no_store);

    {
#ifdef COMMON
        int32 free_space = 32000000; /* Try 32 Mbyte as a default heap size */
#else
        int32 free_space = 32000000; /* Try 32 Mbyte as a default heap size */
#endif
        int32 request = (int32)store_size;
        if (request != 0) free_space = 1024*request;
        free_space = free_space/(CSL_PAGE_SIZE+4);
        if (free_space > MAX_PAGES) free_space = MAX_PAGES;
        pages_count = heap_pages_count = vheap_pages_count =
                      bps_pages_count = native_pages_count = 0;
        native_fringe = 0;
/*
 * I grab memory using a function called my_malloc_1(), which verifies that
 * all addresses used in the heap have the same top bit.  The very first time
 * it is called nilsegment will be NULL - that time it does less checking.
 */
        nilsegment = NULL;

#ifdef HOLD_BACK_MEMORY
/*
 * Try to grab a bit extra since I will then hand it back.  This version
 * of the code MUST be used on machines where size_t (the argument to
 * malloc) denotes a 16-bit value.
 */
        free_space += HOLD_BACK_MEMORY;
/*
 * I should wait until later to grab space, I suspect...  I.e. not pre-allocate
 * pages for the heap now at the start of the run but wait until the garbage
 * collector tells me that enlarging the CSL heap would be a good idea.
 * What I do at present is to allocate a reasonable amount of memory here,
 * and on small machines I will leave it at that.  On large machines
 * I will allocate more space (maybe) during garbage collection.  I use
 * the HOLD_BACK_MEMORY and (init_flags & INIT_EXPANDABLE) to control things
 * in a finer way.
 */
        nilsegment = (Lisp_Object *)my_malloc_1(NIL_SEGMENT_SIZE);
#ifdef COMMON
/*
 * NB here that NIL is tagged as a CONS not as a symbol. That means that
 * qheader(nil) is BEFORE the place that might normally have been the start
 * of the segment, so I add 8 to preserve alignment but to leave room for
 * the header. I have made NIL_SEGMENT_SIZE large enough by a useful margin
 * (in externs.h) so I should not run off th eend of it.
 */
        C_nil = doubleword_align_up(nilsegment) + TAG_CONS + 8;
#else
        C_nil = doubleword_align_up(nilsegment) + TAG_SYMBOL;
#endif
        while (pages_count < free_space)
        {
/*
 * I get a few bytes more than seems necessary because I will need to
 * align my page frames up to a quadword boundary, and that can
 * potentially waste some bytes. Actually my_malloc_1 has already
 * ensured that it hands back a quadword-aligned value so maybe I do not
 * need to worry here any more. However a waste of 16 bytes per page is not
 * really a big issue so I will leave this.
 */
            void *page = (void *)my_malloc_1((size_t)(CSL_PAGE_SIZE+16));
            if (page == NULL) break;
            pages[pages_count++] = page;
        }
/*
 * Now release some memory for the operating system to play with.  This
 * is a bit crude, in that it can "waste" precious space on small
 * machines, but on at least the Acorn Archimedes (RISCOS) and the
 * Macintosh (system 7) it appears to be VITAL. I think that with memory now
 * getting cheap and hardly any machines (that I want to support) not having
 * virtual memory this may no longer be a big issue.
 */
        {   int32 i;
            for (i=0; i<HOLD_BACK_MEMORY; i++)
                if (pages_count != 0) my_free(pages[--pages_count]);
        }
#else /* HOLD_BACK_MEMORY */
#ifdef DEBUG
        if (sizeof(size_t) < 4 && PAGE_BITS > 16)
        {   fprintf(stderr,
                   "This machine needs configuration with HOLD_BACK_MEMORY\n");
            fprintf(stderr,
                   "and PAGE_BITS <= 16.  Change machine.h and recompile\n");
            my_exit(1);
        }
#endif
        {   size_t n = (size_t)(NIL_SEGMENT_SIZE+free_space*(CSL_PAGE_SIZE+16));
/*
 * I try to get the whole of the initial hunk of memory that I need in
 * one gulp since that (maybe) gives me the best chance to obtain all
 * the memory in just one half of my address space.
 */
            char *pool = (char *)my_malloc_1(n);
/*
 * I get 8 bytes more than seems necessary because I will need to
 * align my page frames up to a doubleword boundary, and that can
 * potentially waste 7 bytes.
 */
            if (pool != NULL)
            {   big_chunk_start = (char *)pool;
                big_chunk_end = big_chunk_start + (n-1);
#ifdef __mips__
/*
 * Some versions of the C compiler on 64-bit SGI machines leave
 * big_chunk_start and _end both zero despite the above. The effect is
 * unimportant until the end of a run of CSL, when the test at the start
 * of my_free misbehaves and a report is generated about memory "corruption".
 * With LUCK the extra reference to the variables via the call to the
 * dummy function will cause the compiler to behave in a more conservative
 * manner and get things correct. The problem has not been seen on
 * 32-bit SGI systems, but the extra dummy function call is not very
 * expensive so can be tolerated in such cases.
 *                                                          ACN: August 1996
 */
                dummy_function_call("64-bit SGI machines",
                                    big_chunk_start, big_chunk_end);
#endif
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
                memory_base = (intxx)pool;
                memory_size = n;
                memory_count = 0;
                memory_map = (unsigned char *)(*malloc_hook)(n/32 + 16);
                if (memory_map != 0)
                {   memset(memory_map, 0, n/32+8);
                    memory_file = fopen(memfile, "wb");
                    if (memory_file == NULL)
                    {   (*free_hook)(memory_map);
                        memory_map = 0;
                    }
                    else
                    {   n = n/32 + 8;
                        putc(0, memory_file);
                        putc(0, memory_file);
                        putc(0, memory_file); /* 3 bytes to overwrite later on */
                        putc(n, memory_file);
                        putc(n>>8, memory_file);
                        putc(n>>16, memory_file);
                        memory_comment(2);  /* startup code */
                        init_flags &= ~INIT_EXPANDABLE;
                    }
                }
#endif
#endif
                nilsegment = (Lisp_Object *)pool;
                pool = pool + NIL_SEGMENT_SIZE;
#ifdef COMMON
/* NB here that NIL is tagged as a CONS not as a symbol */
                C_nil = doubleword_align_up(nilsegment) + TAG_CONS + 8;
#else
                C_nil = doubleword_align_up(nilsegment) + TAG_SYMBOL;
#endif
/*
 * If at the end of the run I am going to free some space I had better not
 * free these pages. When I free the nilsegment they all get discarded at
 * once.
 */
                while (pages_count < free_space)
                {   void *page = (void *)&pool[pages_count*(CSL_PAGE_SIZE+16)];
                    pages[pages_count++] = page;
                }
            }
        }
#endif
    }

    if (nilsegment != NULL && pages_count > 0)
    {   if (stack_segsize != 1)
        {   stacksegment =
                (Lisp_Object *)my_malloc(stack_segsize*CSL_PAGE_SIZE + 16);
            if (stacksegment == NULL) fatal_error(err_no_store);
        }
        stacksegment = (Lisp_Object *)pages[--pages_count];
    }
    else fatal_error(err_no_store);
    MD5_Update((unsigned char *)memfile, 8);
/*
 * The stack does not need to be doubleword aligned, but it does need
 * to be word aligned (otherwise certain back-pointers in the garbage
 * collector give trouble), so I fix it up here.  Note that stacksegment
 * remains pointing at the original base so that I can free() it later.
 */
    stackbase = (Lisp_Object *)doubleword_align_up((intxx)stacksegment);
}

#ifdef EXPLICIT_FREE_AT_END_OF_RUN
/*
 * In general I will let CSL exit without bothering to free up all the
 * memory that it allocated - that job can be left (to the extent that
 * it is needed at all) to the run-time system.  But if for some reason
 * you really mind about such things here is some code to do it for you...
 */

static void abandon(void *p[], int32 n)
{
    while (n != 0)
    {   void *w = p[--n];
/*
 * The test here that avoids calling free on a NULL pointer is
 * certainly not needed with an ANSI compliant library - but
 * rumour has it that many Unix libraries are unkind in this
 * respect, and the test is pretty cheap...
 */
        if (w != NULL) my_free(w);
    }
}

#endif

void drop_heap_segments(void)
{
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    identify_page_types();
#endif
#endif
#ifdef EXPLICIT_FREE_AT_END_OF_RUN
    abandon(pages,           pages_count);
    abandon(heap_pages,      heap_pages_count);
    abandon(vheap_pages,     vheap_pages_count);
    abandon(bps_pages,       bps_pages_count);
    abandon(native_pages,    native_pages_count);
    my_free(stacksegment);
    my_free(nilsegment);
#endif
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    fseek(memory_file, 0L, SEEK_SET);
    putc(memory_records & 0xff, memory_file);
    putc((memory_records>>8) & 0xff, memory_file);
    putc((memory_records>>16) & 0xff, memory_file);
    fclose(memory_file);
    memory_file = NULL;
    memory_map = NULL;
#endif
#endif
}

static char *find_checksum(char *name, int32 len, const setup_type *p)
{
    char *n;
    while (p->name != NULL) p++;
    n = (char *)p->one;
    if (strlen(n) == (size_t)len && memcmp(name, n, len) == 0)
        return (char *)p->two;
    else return NULL;
}

static Lisp_Object MS_CDECL Lcheck_c_code(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object name, lc1, lc2, lc3;
    int32 c1=-1, c2=-1, c3=-1;
    long int x1=-2, x2=-2, x3=-2;
    int32 len;
    va_list a;
    char *p;
    char *sname;
    argcheck(nargs, 4, "check-c-code");
    va_start(a, nargs);
    name = va_arg(a, Lisp_Object);
    lc1 = va_arg(a, Lisp_Object);
    lc2 = va_arg(a, Lisp_Object);
    lc3 = va_arg(a, Lisp_Object);
    va_end(a);
    if (!is_vector(name) ||
        type_of_header(vechdr(name)) != TYPE_STRING ||
        !is_fixnum(lc1) ||
        !is_fixnum(lc2) ||
        !is_fixnum(lc3)) return aerror1("check-c-code", name);
    c1 = int_of_fixnum(lc1);
    c2 = int_of_fixnum(lc2);
    c3 = int_of_fixnum(lc3);
    sname = &celt(name, 0);
    len = length_of_header(vechdr(name)) - CELL;
/*
 *  trace_printf("+++ Checking %.*s  %d %d %d\n",
 *               (int)len, sname, c1, c2, c3); 
 */
                   p = find_checksum(sname, len, u01_setup);
    if (p == NULL) p = find_checksum(sname, len, u02_setup);
    if (p == NULL) p = find_checksum(sname, len, u03_setup);
    if (p == NULL) p = find_checksum(sname, len, u04_setup);
    if (p == NULL) p = find_checksum(sname, len, u05_setup);
    if (p == NULL) p = find_checksum(sname, len, u06_setup);
    if (p == NULL) p = find_checksum(sname, len, u07_setup);
    if (p == NULL) p = find_checksum(sname, len, u08_setup);
    if (p == NULL) p = find_checksum(sname, len, u09_setup);
    if (p == NULL) p = find_checksum(sname, len, u10_setup);
    if (p == NULL) p = find_checksum(sname, len, u11_setup);
    if (p == NULL) p = find_checksum(sname, len, u12_setup);
    if (p == NULL) return aerror1("check-c-code", name);
    if (sscanf(p, "%ld %ld %ld", &x1, &x2, &x3) != 3)
        return aerror("check-c-code");
    if (c1 == x1 && c2 == x2 && c3 == x3) return onevalue(nil);
    err_printf("\n+++++ C code and environment files not compatible\n");
    err_printf("please check, re-compile and try again\n");
    return aerror("check-c-code");
}

static setup_type const restart_setup[] =
/*
 * things that are in modules that do not define enough Lisp entrypoints
 * to be worth giving separate entry-tables.
 */
{
    {"check-c-code",            wrong_no_na, wrong_no_nb, Lcheck_c_code},
    {"define-in-module",        Ldefine_in_module, too_many_1, wrong_no_1},
    {"modulep",                 Lmodule_exists, too_many_1, wrong_no_1},
    {"start-module",            Lstart_module, too_many_1, wrong_no_1},
    {"write-module",            Lwrite_module, too_many_1, wrong_no_1},
    {"copy-module",             Lcopy_module, too_many_1, wrong_no_1},
    {"delete-module",           Ldelete_module, too_many_1, wrong_no_1},
    {"load-module",             Lload_module, too_many_1, wrong_no_1},
    {"list-modules",            wrong_no_na, wrong_no_nb, Llist_modules},
    {"writable-libraryp",       Lwritable_libraryp, too_many_1, wrong_no_1},
    {"library-members",         Llibrary_members, too_many_1, Llibrary_members0},
    {"startup-banner",          Lbanner, too_many_1, wrong_no_1},
#ifdef HELP_SYSTEM
    {"write-help-module",       too_few_2, Lwrite_help_module, wrong_no_2},
    {"help",                    Lhelp, Lhelp_2, Lhelp_n},
    {"?",                       Lhelp, too_many_1, wrong_no_1},
#endif
    {"set-help-file",           too_few_2, Lset_help_file, wrong_no_2},
    {"mapstore",                Lmapstore, too_many_1, Lmapstore0},
    {"verbos",                  Lverbos, too_many_1, wrong_no_1},
#ifdef COMMON
    {"errorset",                Lerrorset1, Lerrorset2, Lerrorsetn},
    {"gc",                      Lgc, too_many_1, Lgc0},
#else
    {"errorset",                Lerrorset1, Lerrorset2, Lerrorsetn},
    {"reclaim",                 Lgc, too_many_1, Lgc0},
#endif
    {NULL,                          0, 0, 0}
};


static void create_symbols(setup_type const s[], CSLbool restartp)
{
    int i;
    for (i=0; s[i].name != NULL; i++)
        make_symbol(s[i].name, restartp, s[i].one, s[i].two, s[i].n);
}

static int32 defined_symbols;

static void count_symbols(setup_type const s[])
{
    int i;
    for (i=0; s[i].name != NULL; i++) defined_symbols++;
}

static void set_up_variables(CSLbool restartp);

static void warm_setup(void)
{
/*
 * Here I need to read in the bulk of the checkpoint file.
 */
    Lisp_Object nil = C_nil;
    int32 i;
    Cfread((char *)&heap_pages_count, sizeof(heap_pages_count));
    Cfread((char *)&vheap_pages_count, sizeof(vheap_pages_count));
    Cfread((char *)&bps_pages_count, sizeof(bps_pages_count));

    heap_pages_count = flip_bytes(heap_pages_count);
    vheap_pages_count = flip_bytes(vheap_pages_count);
    bps_pages_count = flip_bytes(bps_pages_count);

/*
 * Here I want to arrange to have at least one free page after re-loading
 * an image.  If malloc can give me enough I grab it here. Note that I do
 * not yet know how many pages will be needed for hard code, which is a
 * bit of a nuisance!
 */
    i = heap_pages_count+vheap_pages_count+
        bps_pages_count+1 - pages_count;
#ifdef MEMORY_TRACE
    if (i > 0) fatal_error(err_no_store);
#else
    while (i-- > 0)
    {   void *page = my_malloc_1((size_t)(CSL_PAGE_SIZE + 16));
        if (page == NULL) fatal_error(err_no_store);
        else pages[pages_count++] = page;
    }
#endif
    {   char dummy[16];
        Cfread(dummy, 8);
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(6);  /* vector heap */
#endif
#endif
    for (i=0; i<vheap_pages_count; i++)
    {   intxx p;
        vheap_pages[i] = allocate_page();
        p = doubleword_align_up((intxx)vheap_pages[i]);
        Cfread((char *)p, CSL_PAGE_SIZE);
    }

    {   char dummy[16];
        Cfread(dummy, 8);
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(5);  /* cons heap */
#endif
#endif
    for (i=0; i<heap_pages_count; i++)
    {   intxx p;
        heap_pages[i] = allocate_page();
        p = quadword_align_up((intxx)heap_pages[i]);
        Cfread((char *)p, CSL_PAGE_SIZE);
    }

    {   char dummy[16];
        Cfread(dummy, 8);
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(14);  /* BPS heap */
#endif
#endif
    for (i=0; i<bps_pages_count; i++)
    {   intxx p;
        bps_pages[i] = allocate_page();
        p = doubleword_align_up((intxx)bps_pages[i]);
        Cfread((char *)p, CSL_PAGE_SIZE);
    }

    {   char endmsg[32];
        Cfread(endmsg, 24);  /* the termination record */
/*
 * Although I check here I will not make the system crash if I see an
 * error - at least until I have tested things and found this test
 * properly reliable.
 */
#ifdef COMMON
        if (strncmp(endmsg, "\n\nEnd of CCL dump file\n\n", 24) != 0)
#else
        if (strncmp(endmsg, "\n\nEnd of CSL dump file\n\n", 24) != 0)
#endif
        {   term_printf("\n+++ Bad end record |%s|\n", endmsg);
        }
    }
/*
 * There is a delicacy here - Cfread uses Iread to read chunks of
 * data from the real input file, but it never goes beyond the recorded
 * end of file mark.  This buffering ensures that at this stage any
 * pending part-word of data will have been read - this because the
 * read buffer used is a multiple of 4 bytes long.  This point matters
 * with regard to checksum validation on these files.
 */
    crypt_active = -1;  /* Have read all of the initial image file */
    IcloseInput(YES);

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(9);  /* adjusting */
#endif
#endif
    inject_randomness((int)clock());
    adjust_all();

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(12);  /* remainder of setup */
#endif
#endif
    eq_hash_tables = eq_hash_table_list;
    equal_hash_tables = equal_hash_table_list;
    eq_hash_table_list = equal_hash_table_list = nil;
    {   Lisp_Object qq;
        for (qq = eq_hash_tables; qq!=nil; qq=qcdr(qq))
            rehash_this_table(qcar(qq));
        for (qq = equal_hash_tables; qq!=nil; qq=qcdr(qq))
            rehash_this_table(qcar(qq));
    }

    gensym_ser = flip_bytes(gensym_ser);
    print_precision = flip_bytes(print_precision);
    miscflags = flip_bytes(miscflags);
    current_modulus = flip_bytes(current_modulus);
    fastget_size = flip_bytes(fastget_size);
    package_bits = flip_bytes(package_bits);
    set_up_functions(1);
    set_up_variables(1);
/*
 * Now I have closed the main heap image, but if there is any hard machine
 * code available for this architecture I should load it. When I do this
 * the main heap has been loaded and relocated and all the entrypoints
 * in it that relate to kernel code have been inserted.
 */
    if (native_code_tag != 0) /* Not worth trying if none available */
    {   if (!IopenRoot(NULL, -native_code_tag))
        {   int32 nn = Igetc() & 0xff;
            nn = nn + ((Igetc() & 0xff) << 8);
            native_pages_count = nn;
            for (i=0; i<native_pages_count; i++)
            {   intxx p;
/*
 * Because I did not know earlier how many pages would be needed here I
 * may not have overall enough. So I expand my heap (if possible)
 * when things start to look tight here.
 */
                if (pages_count <= 1)
                {   void *page = my_malloc_1((size_t)(CSL_PAGE_SIZE + 16));
                    if (page == NULL) fatal_error(err_no_store);
                    else pages[pages_count++] = page;
                }
                native_pages[i] = allocate_page();
                p = (intxx)native_pages[i];
                p = doubleword_align_up(p);
                fread_count = 0;
                Cfread((char *)p, CSL_PAGE_SIZE);
                native_fringe = car32(p);
                relocate_native_code((unsigned char *)p, native_fringe);
            }
            IcloseInput(YES);
        }
    }
/*
 * Finally with a warm start I must instate the definitions of all functions
 * that may have been compiled into hard code on this platform. Functions that
 * may be hard-coded on SOME platform may also be in a mess and will have
 * a byte-coded definition put back in place at this point. Observe that this
 * happens AFTER the system has otherwise been loaded and relocated.
 */
    {   Lisp_Object f_list = native_code, byte_code_def;
        do_not_kill_native_code = 1;
        while (f_list != nil)
        {   Lisp_Object w, fn, defs;
            int32 nargs;
            int instated_something = 0;
            byte_code_def = nil;
            w = qcar(f_list);
            f_list = qcdr(f_list);
            fn = qcar(w); w = qcdr(w);
            nargs = int_of_fixnum(qcar(w));
            defs = qcdr(w);
            while (defs != nil)
            {   int32 n, tag, type, off;
                intxx page;
                void *e;
                w = qcar(defs);
                defs = qcdr(defs);
                n = int_of_fixnum(qcar(w));
                w = qcdr(w);
                tag = (n >> 20) & 0xff;
                type = (n >> 18) & 0x3;
                page = n & 0x3ffff;
                if (tag == 0)
                {   byte_code_def = qcdr(w);
                    continue;
                }
                if (tag != native_code_tag) continue; /* Not for me today */
                instated_something = 1;
                off = int_of_fixnum(qcar(w));
                w = qcdr(w);
/*
 * Now fn should be a symbol, the function to be defined. w is the thing to go
 * into its environment cell. page and off define a location in the hard
 * code space and type tells me which of the 3 function cells to put that in.
 *
 * I will not (yet) mess around with the removal of C definition
 * flags and all the other delicacies. Note that this means attempts to
 * redefine built-in functions with user-provided native code varients
 * may cause all sorts of muddle! Please do not try it, but when you
 * do (!) tell me and I will attempt to work out what ought to happen.
 * Maybe it will all be OK provided that a consistent byte-code definition
 * is in place before any native code gets generated.
 */
                page = (intxx)native_pages[page];
                page = doubleword_align_up(page);
                e = (void *)((char *)page + off);
                switch (type)
                {
/*
 * Warning - I just support nargs being a simple integer here, with no
 * fancy encoding for variable numbers of args or &rest args etc. I think
 * that for native code all such cases need to be dealt with via non-zero
 * type code so that the 3 individual function cells get filled in one
 * by 1.
 */
            case 0: switch (nargs)
                    {
                case 0: set_fns(fn, wrong_no_0a, wrong_no_0b, (n_args *)e);
                        break;
                case 1: set_fns(fn, (one_args *)e, too_many_1, wrong_no_1);
                        break;
                case 2: set_fns(fn, too_few_2, (two_args *)e, wrong_no_2);
                        break;
                case 3: set_fns(fn, wrong_no_3a, wrong_no_3b, (n_args *)e);
                        break;
                default:set_fns(fn, wrong_no_na, wrong_no_nb, (n_args *)e);
                        break;
                    }
                    break;
/*
 * A non-zero type field allows me to fill in just one of the function cells.
 * Note that I ought to arrange to get ALL of them filled in somehow, either
 * by using type=0 or by using all three of type = 1,2,3.
 */
            case 1: ifn1(fn) = (intxx)e;
                    break;
            case 2: ifn2(fn) = (intxx)e;
                    break;
            case 3: ifnn(fn) = (intxx)e;
                    break;
                }
                qenv(fn) = w;
            }
            if (!instated_something && byte_code_def != nil)
            {   w = cons(fixnum_of_int(nargs), byte_code_def);
/*
 * You can look at this bit of code and moan, saying "What happens if
 * the call to CONS causes a garbage collection?". Well I have this policy
 * that garbage collection attempts during startup should be thought of
 * as fatal, and that the user should give enough memory to make it possible
 * to get at least started. I hope that I do not generate much litter here
 * and in other places within the startup code. Not thinking about GC
 * safety leaves the code neater and easier to work with.
 */
                Lsymbol_set_definition(nil, fn, w);
            }
        }
        do_not_kill_native_code = 0;
    }
    inject_randomness((int)clock());
}

static void cold_setup(void)
{
    Lisp_Object nil = C_nil;
    void *p;
    p = vheap_pages[vheap_pages_count++] = allocate_page();
    vfringe = (Lisp_Object)(8 + (char *)doubleword_align_up((intxx)p));
    vheaplimit = (Lisp_Object)((char *)vfringe + (CSL_PAGE_SIZE - 16));

    p = heap_pages[heap_pages_count++] = allocate_page();
    heaplimit = quadword_align_up((intxx)p);
    fringe = (Lisp_Object)((char *)heaplimit + CSL_PAGE_SIZE);
    heaplimit = (Lisp_Object)((char *)heaplimit + SPARE);

    codelimit = codefringe = 0; /* no BPS to start with */

    miscflags = 3;
    qplist(nil) = nil;
    qfastgets(nil) = nil;
    qenv(nil) = nil;        /* points to self in undefined case */
    ifn1(nil) = (intxx)undefined1;
    ifn2(nil) = (intxx)undefined2;
    ifnn(nil) = (intxx)undefinedn;
    qheader(nil) = TAG_ODDS+TYPE_SYMBOL+SYM_SPECIAL_VAR;
    qvalue(nil) = nil;
#ifdef COMMON
    qpname(nil) = make_string("NIL");
#else
    qpname(nil) = make_string("nil");
#endif
    qcount(nil) = 0;
    exit_tag = exit_value = nil;
    exit_reason = UNWIND_NULL;
    eq_hash_tables = equal_hash_tables = nil;

    current_package = nil;
    qvalue(nil) = getvector_init(sizeof(Package), nil);
#ifdef COMMON
    qpackage(nil) = qvalue(nil);    /* For sake of restart code */
    all_packages = ncons(qvalue(nil));
#endif

    packhdr_(CP) = TYPE_STRUCTURE + (packhdr_(CP) & ~header_mask);
#ifdef COMMON
    packname_(CP) = make_string("LISP");
#endif
/*
 * The size chosen here is only an initial size - the hash table in a package
 * can grow later on if needbe - but I ought to ensure that the initial
 * size is big enough for the built-in symbols that Lisp creates in
 * this restart code.  The size must be a power of 2.
 */
    packint_(CP) = getvector_init(CELL+INIT_OBVECI_SIZE, fixnum_of_int(0));
    packvint_(CP) = fixnum_of_int(1);
    packflags_(CP) = fixnum_of_int(++package_bits);
#ifdef COMMON
/*
 * Common Lisp also has "external" symbols to allow for...
 */
    packnint_(CP) = fixnum_of_int(0);
    packext_(CP) = getvector_init(CELL+INIT_OBVECX_SIZE, fixnum_of_int(0));
    packvext_(CP) = fixnum_of_int(1);
    packnext_(CP) = fixnum_of_int(1); /* Allow for nil */
    {   int i = (int)(hash_lisp_string(qpname(nil)) &
                      (INIT_OBVECX_SIZE/CELL - 1));
        elt(packext_(CP), i) = nil;
    }
#else
    packnint_(CP) = fixnum_of_int(1); /* Allow for nil */
    {   int i = (int)(hash_lisp_string(qpname(nil)) &
                      (INIT_OBVECI_SIZE/CELL - 1));
        elt(packint_(CP), i) = nil;
    }
#endif
    gensym_ser = 0;
    print_precision = 15;
    current_modulus = 1;
    fastget_size = 32;
    package_bits = 0;
    unset_var = nil;
/*
 * there had better not be a need for garbage collection here...
 * ... or elsewhere in setup, since the world is not yet put together.
 * Ditto interrupts.
 */
#define boffo_size 256
    boffo = getvector(TAG_VECTOR, TYPE_STRING, CELL+boffo_size);
    memset((void *)((char *)boffo + (CELL - TAG_VECTOR)), '@', boffo_size);
#ifndef COMMON
    if (current_package == nil)
    {   current_package      = make_undefined_symbol("*package*");
        qheader(current_package) |= SYM_SPECIAL_VAR;
        lisp_package = qvalue(current_package) = qvalue(nil);
        qvalue(nil) = nil;
    }
#else
/*
 * The next line has hidden depths.  When it is obeyed during cold start
 * the C variable current_package has the value nil, hence make_symbol
 * looks in the value cell of nil to find the package to intern wrt. Once
 * this has been done I can put nil back how it ought to have been!
 */
    current_package          = make_undefined_symbol("*package*");
    qheader(current_package)|= SYM_SPECIAL_VAR;
    lisp_package = qvalue(current_package)  = qpackage(nil);
    qvalue(nil)              = nil;          /* Whew! */
#endif

    B_reg = nil;                             /* safe for GC */
    unset_var                = make_undefined_symbol("~indefinite-value~");
    qheader(unset_var)      |= SYM_SPECIAL_VAR;
    qvalue(unset_var)        = unset_var;
    Lunintern(nil, unset_var);
/*
 * Now in some minor sense the world is in a self-consistent state
 */
    lisp_true           = make_undefined_symbol("t");
    qheader(lisp_true) |= SYM_SPECIAL_VAR;
    qvalue(lisp_true)   = lisp_true;
    savedef             = make_undefined_symbol("*savedef");
    comma_symbol        = make_undefined_symbol("~comma");
    comma_at_symbol     = make_undefined_symbol("~comma-at");
    lambda              = make_undefined_symbol("lambda");
    funarg              = make_undefined_symbol("funarg");
    cfunarg             = make_undefined_symbol("cfunarg");
    opt_key             = make_undefined_symbol("&optional");
    rest_key            = make_undefined_symbol("&rest");
#ifdef COMMON
    key_key             = make_undefined_symbol("&key");
    allow_other_keys    = make_undefined_symbol("&allow-other-keys");
    aux_key             = make_undefined_symbol("&aux");
#endif
    work_symbol         = make_undefined_symbol("~magic-internal-symbol~");
    Lunintern(nil, work_symbol);
#ifndef COMMON
    packid_(CP)         = make_undefined_symbol("package");
#else
    package_symbol      = make_undefined_symbol("package");
    packid_(CP)         = package_symbol;
#endif

    macroexpand_hook    = make_undefined_symbol("*macroexpand-hook*");
    qheader(macroexpand_hook) |= SYM_SPECIAL_VAR;
    evalhook            = make_undefined_symbol("*evalhook*");
    qheader(evalhook)  |= SYM_SPECIAL_VAR;
    qvalue(evalhook)    = nil;
    applyhook           = make_undefined_symbol("*applyhook*");
    qheader(applyhook) |= SYM_SPECIAL_VAR;
    qvalue(applyhook)   = nil;
#ifdef COMMON
    keyword_package     = make_undefined_symbol("*keyword-package*");
    qheader(keyword_package) |= SYM_SPECIAL_VAR;
    qvalue(keyword_package) = make_package(make_string("KEYWORD"));
    err_table           = make_undefined_symbol("*ERROR-MESSAGE*");
#else
    err_table           = make_undefined_symbol("*error-messages*");
#endif
    qheader(err_table) |= SYM_SPECIAL_VAR;
    qvalue(err_table)   = nil;
#ifdef COMMON
#define make_keyword(name) \
        Lintern_2(nil, make_string(name), qvalue(keyword_package))
    internal_symbol     = make_keyword("INTERNAL");
    external_symbol     = make_keyword("EXTERNAL");
    inherited_symbol    = make_keyword("INHERITED");
    allow_key_key       = make_keyword("ALLOW-OTHER-KEYS");
#else
#define make_keyword(name) make_undefined_symbol(name)
#endif
    gensym_base         = make_string("G");
#ifdef COMMON
    special_symbol      = make_undefined_symbol("special");
    expand_def_symbol   = make_undefined_symbol("expand-definer");
    format_symbol       = make_undefined_symbol("format");
    string_char_sym     = make_undefined_symbol("string-char");
    cl_symbols          = make_undefined_symbol("*cl-symbols*");
/*
 * cl_symbols has to be at least a vector or else I can not
 * read in the Lisp file that sets its proper value...
 */
    qvalue(cl_symbols)  = getvector_init(8*CELL, nil);
    features_symbol     = make_undefined_symbol("*features*");
    qheader(cl_symbols)      |= SYM_SPECIAL_VAR;
    qheader(features_symbol) |= SYM_SPECIAL_VAR;
    {   Lisp_Object w;
#define make_constant(name, value)       \
        w = make_undefined_symbol(name); \
        qheader(w) |= SYM_SPECIAL_VAR;   \
        qvalue(w) = value;
        make_constant("most-positive-fixnum", fixnum_of_int(0x07ffffff));
        make_constant("most-negative-fixnum", fixnum_of_int(0xf8000000));
/* #undef  TYPE_LONG_FLOAT                   */
/* #define TYPE_LONG_FLOAT TYPE_DOUBLE_FLOAT */
        make_constant("pi",
            make_boxfloat(3.141592653589793238, TYPE_LONG_FLOAT));
    }
#endif
    append_symbol       = make_undefined_symbol("append");
    raise_symbol        = make_undefined_symbol("*raise");
    lower_symbol        = make_undefined_symbol("*lower");
    echo_symbol         = make_undefined_symbol("*echo");
/*
 * I think that having a built-in symbol called *hankaku even if Kanji support
 * is not otherwise present is not too severe a problem, and making the
 * symbol present always will help keep image files re-usable from one
 * version of CSL to another.
 */
    hankaku_symbol      = make_undefined_symbol("*hankaku");
    comp_symbol         = make_undefined_symbol("*comp");
    compiler_symbol     = make_undefined_symbol("compile");
    native_symbol       = make_undefined_symbol("native-compile");
    traceprint_symbol   = make_undefined_symbol("trace-print");
    loadsource_symbol   = make_symbol("load-source", 0, Lload_source, too_many_1, wrong_no_1);
    prinl_symbol        = make_symbol("prinl", 0, Lprin, too_many_1, wrong_no_1);
    emsg_star           = make_undefined_symbol("emsg*");
    redef_msg           = make_undefined_symbol("*redefmsg");
    expr_symbol         = make_undefined_symbol("expr");
    fexpr_symbol        = make_undefined_symbol("fexpr");
    macro_symbol        = make_undefined_symbol("macro");
    break_function      = make_undefined_symbol("*break-loop*");
    qheader(raise_symbol) |= SYM_SPECIAL_VAR;
    qheader(lower_symbol) |= SYM_SPECIAL_VAR;
    qheader(echo_symbol)  |= SYM_SPECIAL_VAR;
    qheader(hankaku_symbol) |= SYM_SPECIAL_VAR;
    qheader(comp_symbol)  |= SYM_SPECIAL_VAR;
    qheader(emsg_star)    |= SYM_SPECIAL_VAR;
    qheader(redef_msg)    |= SYM_SPECIAL_VAR;
    qheader(break_function)    |= SYM_SPECIAL_VAR;
    qvalue(break_function)      = nil;
    qheader(loadsource_symbol) |= SYM_SPECIAL_VAR;
    qvalue(loadsource_symbol)   = nil;
    {   Lisp_Object common = make_undefined_symbol("common-lisp-mode");
        qheader(common)   |= SYM_SPECIAL_VAR;
#ifdef COMMON
        qvalue(common)        = lisp_true;
        qvalue(raise_symbol)  = lisp_true;
        qvalue(lower_symbol)  = nil;
#else
        qvalue(common)        = nil;
        qvalue(raise_symbol)  = nil;
        qvalue(lower_symbol)  = lisp_true;
#endif
    }
    qvalue(echo_symbol)    = nil;
    qvalue(hankaku_symbol) = nil;
    qvalue(comp_symbol)    = nil;
    qvalue(emsg_star)      = nil;
    qvalue(redef_msg)      = lisp_true;

    sys_hash_table = Lmkhash(nil, 3, fixnum_of_int(5), fixnum_of_int(2), nil);
    get_counts = Lmkhash(nil, 3, fixnum_of_int(5), fixnum_of_int(0), nil);
/*
 * I make the vector that can hold the names used for "fast" get tags big
 * enough for the largest possible number.
 */
    fastget_names = getvector_init((MAX_FASTGET_SIZE+2)*CELL, SPID_NOPROP);
/*
 * The next bit is a horrid fudge, used in read.c (function orderp) to
 * support REDUCE. It ensures that the flag 'noncom is subject to an
 * optimisation for flag/flagp that allows it to be tested for using a
 * simple bit-test.  This MUST use entry zero (coded as 1 here!).
 * Also I insist that 'lose be the second fastget thing!
 */
    {   Lisp_Object nc = make_undefined_symbol("noncom");
        qheader(nc) |= (1L << SYM_FASTGET_SHIFT);
        elt(fastget_names, 0) = nc;
        nc = make_undefined_symbol("lose");
        qheader(nc) |= (2L << SYM_FASTGET_SHIFT);
        elt(fastget_names, 1) = nc;
    }
/*
 * I create the stream objects just once at cold-start time, but every time I
 * restart I will fill in their components in the standard way again.
 */
    lisp_work_stream = make_stream_handle();
    lisp_terminal_io = make_stream_handle();
    lisp_standard_output = make_stream_handle();
    lisp_standard_input = make_stream_handle();
    lisp_error_output = make_stream_handle();
    lisp_trace_output = make_stream_handle();
    lisp_debug_io = make_stream_handle();
    lisp_query_io = make_stream_handle();
    inject_randomness((int)clock());
    set_up_functions(0);
    set_up_variables(0);
}

void set_up_functions(CSLbool restartp)
{
/*
 * All symbols that have a pointer to C code in their function cell must
 * be set up whether we are in a warm OR a cold start state, because the
 * actual addresses associated with C entrypoints will vary from version
 * to version of the binary of the system.
 */
    int i;
    nil_as_base
#ifdef COMMON
/*
 * In Common Lisp mode it could be that the user had something other than the
 * LISP package active when the image was saved. But I want all the symbols
 * that I create or restore here to be in the LISP (or sometimes keyword)
 * package. So I temporarily reset the package here...
 */
    Lisp_Object saved_package = CP;
    CP = find_package("LISP", 4);
#endif
    function_symbol          = make_symbol("function", restartp, function_fn, bad_special2, bad_specialn);
    qheader(function_symbol)|= SYM_SPECIAL_FORM;
    quote_symbol             = make_symbol("quote", restartp, quote_fn, bad_special2, bad_specialn);
    qheader(quote_symbol)   |= SYM_SPECIAL_FORM;
    progn_symbol             = make_symbol("progn", restartp, progn_fn, bad_special2, bad_specialn);
    qheader(progn_symbol)   |= SYM_SPECIAL_FORM;
#ifdef COMMON
    declare_symbol           = make_symbol("declare", restartp, declare_fn, bad_special2, bad_specialn);
    qheader(declare_symbol) |= SYM_SPECIAL_FORM;
#endif
    cons_symbol              = make_symbol("cons", restartp, too_few_2, Lcons, wrong_no_2);
    eval_symbol              = make_symbol("eval", restartp, Leval, too_many_1, wrong_no_1);
    loadsource_symbol        = make_symbol("load-source", restartp, Lload_source, too_many_1, wrong_no_1);
/*
 * The main bunch of symbols can be handed using a table that
 * gives names and values.
 */
    for (i=0; eval2_setup[i].name != NULL; i++)
        qheader(make_symbol(eval2_setup[i].name,
                            restartp,
                            eval2_setup[i].one,
                            eval2_setup[i].two,
                            eval2_setup[i].n)) |= SYM_SPECIAL_FORM;
    for (i=0; eval3_setup[i].name != NULL; i++)
        qheader(make_symbol(eval3_setup[i].name,
                            restartp,
                            eval3_setup[i].one,
                            eval3_setup[i].two,
                            eval3_setup[i].n)) |= SYM_SPECIAL_FORM;

    create_symbols(arith06_setup, restartp);
    create_symbols(arith08_setup, restartp);
    create_symbols(arith10_setup, restartp);
    create_symbols(arith12_setup, restartp);
    create_symbols(char_setup, restartp);
    create_symbols(eval1_setup, restartp);
    create_symbols(funcs1_setup, restartp);
    create_symbols(funcs2_setup, restartp);
    create_symbols(funcs3_setup, restartp);
    create_symbols(print_setup, restartp);
    create_symbols(read_setup, restartp);
    create_symbols(restart_setup, restartp);
    create_symbols(mpi_setup, restartp);
/*
 * Although almost everything is mappeed into upper case in a Common Lisp
 * world I will preserve the case of symbols defined un u01 to u12.
 */
    create_symbols(u01_setup, restartp | 2);
    create_symbols(u02_setup, restartp | 2);
    create_symbols(u03_setup, restartp | 2);
    create_symbols(u04_setup, restartp | 2);
    create_symbols(u05_setup, restartp | 2);
    create_symbols(u06_setup, restartp | 2);
    create_symbols(u07_setup, restartp | 2);
    create_symbols(u08_setup, restartp | 2);
    create_symbols(u09_setup, restartp | 2);
    create_symbols(u10_setup, restartp | 2);
    create_symbols(u11_setup, restartp | 2);
    create_symbols(u12_setup, restartp | 2);

#ifdef NAG
    create_symbols(asp_setup, restartp);
    create_symbols(nag_setup, restartp);
    create_symbols(socket_setup, restartp);
    create_symbols(xdr_setup, restartp);
    create_symbols(grep_setup, restartp);
    create_symbols(axfns_setup, restartp);
    create_symbols(gr_setup, restartp);
#endif

#ifdef OPENMATH
    create_symbols(om_setup, restartp);
    create_symbols(om_parse_setup, restartp);
#endif

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(13);  /* tail end of setup */
#endif
#endif

#ifdef COMMON
    CP = saved_package;
#endif
}

#ifndef COMMON
#ifdef CWIN

static int MS_CDECL alpha0(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

static int MS_CDECL alpha1(const void *a, const void *b)
{
    return strcmp(1+*(const char **)a, 1+*(const char **)b);
}

#endif
#endif

static void set_up_variables(CSLbool restartp)
{
    Lisp_Object nil = C_nil;
    int i;
#ifdef COMMON
    Lisp_Object saved_package = CP;
    CP = find_package("LISP", 4);
#endif
    qvalue(macroexpand_hook) = make_symbol("funcall", restartp, Lfuncall1, Lfuncall2, Lfuncalln);
    input_libraries = make_undefined_symbol("input-libraries");
    qheader(input_libraries)  |= SYM_SPECIAL_FORM;
    qvalue(input_libraries) = nil;
    for (i=number_of_fasl_paths-1; i>=0; i--)
        qvalue(input_libraries) = cons(SPID_LIBRARY + (((int32)i)<<20),
                                       qvalue(input_libraries));
    output_library = make_undefined_symbol("output-library");
    qheader(output_library)   |= SYM_SPECIAL_FORM;
    qvalue(output_library)  = output_directory < 0 ? nil :
                              SPID_LIBRARY + (((int32)output_directory)<<20);
/*
 * The Lisp variable lispsystem* gets set here. (in COMMON mode it is
 * the variable *features*)
 * Its value is a list.
 *       csl                      says I am a CSL Lisp
 *       (executable . "string")  name of current executable (if available)
 *       pipes                    do I support open-pipe?
 *       (version . "string")     eg "2.11"
 *       (name . "string")        eg "MSDOS/386"
 *       (opsys . id)             unix/msdos/riscos/win32/finder/riscos/...
 *       id                       unix/msdos etc again...
 *       win32s                   qualifier when (opsys . win32) is set
 *       win95                    ditto
 *       help                     help mechanism provided within Lisp
 *       debug                    Lisp built with debug options
 *       (native . number)        native code tag
 *       (c-code . number)        u01.c through u12.c define n functions
 *
 * In COMMON mode the tags on the *features* list are generally in the
 * keyword package. Otherwise they are just regular symbols. This makes it
 * slightly hard to use code that tests this list in a generic environment!
 */
    {
#ifdef COMMON
        Lisp_Object n = features_symbol;
        Lisp_Object w;
        char opsys[32];
        char *p1 = opsys, *p2 = OPSYS;
        while ((*p1++ = toupper(*p2++)) != 0);
        *p1 = 0;
        w = cons(make_keyword(opsys), nil);
#else
        Lisp_Object n = make_undefined_symbol("lispsystem*");
        Lisp_Object w = cons(make_keyword(OPSYS), nil), w1;
        qheader(n) |= SYM_SPECIAL_VAR;
#endif
        defined_symbols = 0;
        count_symbols(u01_setup); count_symbols(u02_setup);
        count_symbols(u03_setup); count_symbols(u04_setup);
        count_symbols(u05_setup); count_symbols(u06_setup);
        count_symbols(u07_setup); count_symbols(u08_setup);
        count_symbols(u09_setup); count_symbols(u10_setup);
        count_symbols(u11_setup); count_symbols(u12_setup);
#ifdef COMMON
/*
 * A gratuitous misery here is the need to make COMMON words
 * upper case.
 */
        w = acons(make_keyword("OPSYS"),
                  make_undefined_symbol(OPSYS), w);
        w = acons(make_keyword("NATIVE"),
                  fixnum_of_int(native_code_tag), w);
        w = acons(make_keyword("C-CODE"),
                  fixnum_of_int(defined_symbols), w);
#ifdef WINDOWS_NT
        if (win32s==1) w = cons(make_keyword("WIN32S"), w);
        else if (win32s==2) w = cons(make_keyword("WIN95"), w);
#endif
#ifdef PIPES
#ifdef PIPES_SOMETIMES
        if (pipes_today)
#endif
            w = cons(make_keyword("PIPES"), w);
#endif
#ifdef HELP_SYSTEM
        w = cons(make_keyword("HELP"), w);
#endif
#ifdef DEBUG
        w = cons(make_keyword("DEBUG"), w);
#endif
        w = cons(make_keyword("RECORD_GET"), w);
        if (program_name[0] != 0)
            w = acons(make_keyword("EXECUTABLE"),
                      make_string(program_name), w);
        w = acons(make_keyword("NAME"), make_string(IMPNAME), w);
        w = acons(make_keyword("VERSION"), make_string(VERSION), w);
        w = cons(make_keyword("CCL"), w);
        w = cons(make_keyword("COMMON-LISP"), w);
#else   /* !COMMON */
        w = acons(make_keyword("opsys"),
                  make_undefined_symbol(OPSYS), w);
        w = acons(make_keyword("native"),
                  fixnum_of_int(native_code_tag), w);
        w = acons(make_keyword("c-code"),
                  fixnum_of_int(defined_symbols), w);
#ifdef WINDOWS_NT
        if (win32s==1) w = cons(make_keyword("win32s"), w);
        else if (win32s==2) w = cons(make_keyword("win95"), w);
#endif
#ifdef PIPES
#ifdef PIPES_SOMETIMES
        if (pipes_today)
#endif
            w = cons(make_keyword("pipes"), w);
#endif
#ifdef HELP_SYSTEM
        w = cons(make_keyword("help"), w);
#endif
#ifdef DEBUG
        w = cons(make_keyword("debug"), w);
#endif
#ifdef RECORD_GET
        w = cons(make_keyword("record_get"), w);
#endif
        if (program_name[0] != 0)
            w = acons(make_keyword("executable"),
                      make_string(program_name), w);
        w = acons(make_keyword("name"), make_string(IMPNAME), w);
        w = acons(make_keyword("version"), make_string(VERSION), w);
        w = cons(make_keyword("csl"), w);
/*
 * Ha Ha a trick here - if a symbol ADDSQ is defined I view this image
 * as being one for REDUCE and push that information onto lispsystem*,
 * and I also reset the "about box" information (if using cwin).
 */
        w1 = make_undefined_symbol("addsq");
        if (qfn1(w1) != undefined1)
        {   w = cons(make_keyword("reduce"), w);
/*
 * I then inspect VERSION!* to try to see whether I have 3.6 or 3.7
 */
            w1 = qvalue(make_undefined_symbol("version*"));
            if (is_vector(w1) && 
                type_of_header(vechdr(w1)) == TYPE_STRING)
            {
#ifdef CWIN
                int n = length_of_header(vechdr(w1))-4;
                sprintf(about_box_title, "About %.*s",
                   (n > 31-(int)strlen("About ") ?
                        31-(int)strlen("About ") : n),
                   &celt(w1, 0));
                sprintf(about_box_description, "%.*s",
                   (n > 31 ? 31 : n),
                   &celt(w1, 0));
/*
 * 3.6 did not have copyright1!* etc info, so take it specially here.
 */
                if (memcmp(&celt(w1, 0), "REDUCE 3.6", 10) == 0)
                {   strcpy(about_box_rights_1, "Copyright RAND 1995");
                    strcpy(about_box_rights_2, "Copyright Codemist 1996");
                }
                else
                {   w1 = qvalue(make_undefined_symbol("copyright1*"));
                    if (is_vector(w1) && 
                        type_of_header(vechdr(w1)) == TYPE_STRING)
                    {   n = length_of_header(vechdr(w1))-4;
                        sprintf(about_box_rights_1, "%.*s",
                            n > 31 ? 31 : n, &celt(w1, 0));
                    }
                    else strcpy(about_box_rights_1, "Copyright A C Hearn/RAND");
                    w1 = qvalue(make_undefined_symbol("copyright2*"));
                    if (is_vector(w1) && 
                        type_of_header(vechdr(w1)) == TYPE_STRING)
                    {   n = length_of_header(vechdr(w1))-4;
                        sprintf(about_box_rights_2, "%.*s",
                            n > 31 ? 31 : n, &celt(w1, 0));
                    }
                    else strcpy(about_box_rights_2, "Copyright Codemist Ltd");
                }
#endif
            }
            else
            {
#ifdef CWIN
                strcpy(about_box_title, "About REDUCE");
                strcpy(about_box_description, "REDUCE");
                strcpy(about_box_rights_1, "Copyright A C Hearn/RAND");
                strcpy(about_box_rights_2, "Copyright Codemist Ltd");
#endif
            }
        }
#endif
        qheader(n) |= SYM_SPECIAL_VAR;
        qvalue(n) = w;
    }
#ifdef COMMON
/*
 * Floating point characteristics are taken from <float.h> where it is
 * supposed that the C compiler involved has got the values correct.
 * I do this every time the system is loaded rather than just when an
 * image is cold-created. This is because an image file may have been created
 * on a system differing from the one on which it is used. Mayve in fact
 * IEEE arithmetic is ALMOST universal and I am being too cautious here?
 */
    {   Lisp_Object w;
        make_constant("short-float-epsilon",
                      make_sfloat(16.0*FLT_EPSILON));
        make_constant("single-float-epsilon",
                      make_boxfloat(FLT_EPSILON, TYPE_SINGLE_FLOAT));
        make_constant("double-float-epsilon",
                      make_boxfloat(DBL_EPSILON, TYPE_DOUBLE_FLOAT));
/* For now "long" = "double" */
        make_constant("long-float-epsilon",
                      make_boxfloat(DBL_EPSILON, TYPE_LONG_FLOAT));
/*
 * I assume that I have a radix 2 representation, and float-negative-epsilon
 * is just half float-epsilon. Correct me if I am wrong...
 */
        make_constant("short-float-negative-epsilon",
                      make_sfloat(16.0*FLT_EPSILON/2.0));
        make_constant("single-float-negative-epsilon",
                      make_boxfloat(FLT_EPSILON/2.0, TYPE_SINGLE_FLOAT));
        make_constant("double-float-negative-epsilon",
                      make_boxfloat(DBL_EPSILON/2.0, TYPE_DOUBLE_FLOAT));
/* For now "long" = "double" */
        make_constant("long-float-negative-epsilon",
                      make_boxfloat(DBL_EPSILON/2.0, TYPE_LONG_FLOAT));
/*
 * I hope that the C header file gets extremal values correct. Note that
 * because make_sfloat() truncates (rather than rounding) it should give
 * correct values for most-positive-short-float etc
 */
        make_constant("most-positive-short-float",
                      make_sfloat(FLT_MAX));
        make_constant("most-positive-single-float",
                      make_boxfloat(FLT_MAX, TYPE_SINGLE_FLOAT));
        make_constant("most-positive-double-float",
                      make_boxfloat(DBL_MAX, TYPE_DOUBLE_FLOAT));
        make_constant("most-positive-long-float",
                      make_boxfloat(DBL_MAX, TYPE_LONG_FLOAT));
/*
 * Here I assume that the floating point representation is sign-and-magnitude
 * and hence symmetric about zero.
 */
        make_constant("most-negative-short-float",
                      make_sfloat(-FLT_MAX));
        make_constant("most-negative-single-float",
                      make_boxfloat(-FLT_MAX, TYPE_SINGLE_FLOAT));
        make_constant("most-negative-double-float",
                      make_boxfloat(-DBL_MAX, TYPE_DOUBLE_FLOAT));
        make_constant("most-negative-long-float",
                      make_boxfloat(-DBL_MAX, TYPE_LONG_FLOAT));
/*
 * The "least-xxx" set of values did not consider the case of denormalised
 * numbers too carefully in ClTl-1, so in ClTl-2 there are elaborations. I
 * believe that a proper C header file <float.h> will make the macros that
 * I use here refer to NORMALISED values, so the numeric results I use
 * here will not be quite proper (ie there are smaller floats that are
 * un-normalised). But I will ignore that worry just for now.
 */
        make_constant("least-positive-short-float",
                      make_sfloat(FLT_MIN));
        make_constant("least-positive-single-float",
                      make_boxfloat(FLT_MIN, TYPE_SINGLE_FLOAT));
        make_constant("least-positive-double-float",
                      make_boxfloat(DBL_MIN, TYPE_DOUBLE_FLOAT));
        make_constant("least-positive-long-float",
                      make_boxfloat(DBL_MIN, TYPE_LONG_FLOAT));
        make_constant("least-negative-short-float",
                      make_sfloat(-FLT_MIN));
        make_constant("least-negative-single-float",
                      make_boxfloat(-FLT_MIN, TYPE_SINGLE_FLOAT));
        make_constant("least-negative-double-float",
                      make_boxfloat(-DBL_MIN, TYPE_DOUBLE_FLOAT));
        make_constant("least-negative-long-float",
                      make_boxfloat(-DBL_MIN, TYPE_LONG_FLOAT));
/*
 * The bunch here are intended to be NORMALISED numbers, while the unqualified
 * ones above may not be.
 */
        make_constant("least-positive-normalized-short-float",
                      make_sfloat(FLT_MIN));
        make_constant("least-positive-normalized-single-float",
                      make_boxfloat(FLT_MIN, TYPE_SINGLE_FLOAT));
        make_constant("least-positive-normalized-double-float",
                      make_boxfloat(DBL_MIN, TYPE_DOUBLE_FLOAT));
        make_constant("least-positive-normalized-long-float",
                      make_boxfloat(DBL_MIN, TYPE_LONG_FLOAT));
        make_constant("least-negative-normalized-short-float",
                      make_sfloat(-FLT_MIN));
        make_constant("least-negative-normalized-single-float",
                      make_boxfloat(-FLT_MIN, TYPE_SINGLE_FLOAT));
        make_constant("least-negative-normalized-double-float",
                      make_boxfloat(-DBL_MIN, TYPE_DOUBLE_FLOAT));
        make_constant("least-negative-normalized-long-float",
                      make_boxfloat(-DBL_MIN, TYPE_LONG_FLOAT));
#ifdef UNIX_TIMES
/* /*
 * ACN believes that the following is misguided, since the time-reading
 * function (defined in fns1.c) that CCL provides always returns its answer
 * in milliseconds. This the 1000 below is NOT as arbitrary as all that, it
 * represents the unit that CCL (across all platforms) returns time
 * measurements in. The UNIX_TIMES macro is set on Unix systems to
 * influence whether the times() function or clock() is used to read
 * time, where in the former case Unix makes it possible to separate
 * user and system time.
 */
        /* UNIX_TIMES is set in machine.h and will usually be HZ. */
        make_constant("internal-time-units-per-second",
            fixnum_of_int(UNIX_TIMES));
#else
        make_constant("internal-time-units-per-second",
            fixnum_of_int(1000)); /* Arbitrary figure */
#endif
    }
#endif
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(3);  /* creating symbols */
#endif
#endif
    charvec = getvector_init(257*CELL, nil);
    faslvec = nil;
    faslgensyms = nil;

    qheader(terminal_io = make_undefined_symbol("*terminal-io*"))
        |= SYM_SPECIAL_VAR;
    qheader(standard_input = make_undefined_symbol("*standard-input*"))
        |= SYM_SPECIAL_VAR;
    qheader(standard_output = make_undefined_symbol("*standard-output*"))
        |= SYM_SPECIAL_VAR;
    qheader(error_output = make_undefined_symbol("*error-output*"))
        |= SYM_SPECIAL_VAR;
    qheader(trace_output = make_undefined_symbol("*trace-output*"))
        |= SYM_SPECIAL_VAR;
    qheader(debug_io = make_undefined_symbol("*debug-io*"))
        |= SYM_SPECIAL_VAR;
    qheader(query_io = make_undefined_symbol("*query-io*"))
        |= SYM_SPECIAL_VAR;

    stream_type(lisp_work_stream) = make_undefined_symbol("work-stream");

    {   Lisp_Object f = lisp_terminal_io;
        stream_type(f) = make_undefined_symbol("terminal-stream");
        set_stream_read_fn(f, char_from_terminal);
        set_stream_read_other(f, read_action_terminal);
        set_stream_write_fn(f, char_to_terminal);
        set_stream_write_other(f, write_action_terminal);
        qvalue(terminal_io) = f;

        f = lisp_standard_input;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
/*
 * If I do not have COMMON defined I will take a slight short cut here and
 * make reading from *standard-input* read directly from the terminal. For
 * full Common Lisp compatibility I think *standard-input* is required to
 * be a synonym stream that will dynamically look at the value of the variable
 * *terminal-io* every time it does anything. Ugh, since people who assign to
 * or re-bind *terminal-io* seem to me to be asking for terrible trouble!
 */
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
        qvalue(standard_input) = f;

        f = lisp_standard_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(standard_output) = f;

        f = lisp_error_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(error_output) = f;

        f = lisp_trace_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(trace_output) = f;

        f = lisp_debug_io;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(debug_io) = f;

        f = lisp_query_io;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(query_io) = f;
    }

/*
 * I can not handle boffo overflow very well here, but I do really hope that
 * symbols spelt out on the command line will always be fairly short.
 */
    for (i=0; i<number_of_symbols_to_define; i++)
    {   CSLbool undef = undefine_this_one[i];
        char *s = symbols_to_define[i];
        if (undef)
        {   Lisp_Object n = make_undefined_symbol(s);
            qvalue(n) = unset_var;
        }
        else
        {   char buffer[256];
            char *p = buffer;
            int c;
            Lisp_Object n, v;
            while ((c = *s++) != 0 && c != '=') *p++ = (char)c;
            *p = 0;
            n = make_undefined_symbol(buffer);
            push(n);
            if (c == 0) v = lisp_true;
            else
            {
/*
 * I have been having a big difficulty here, caused by the inconsistent and
 * awkward behaviours of various shells and "make" utilities. In a tidy
 * and simple world I might like a command-line option -Dxx=yyy to allow
 * arbitrary text for yyy terminating it at the next whitespace. Then yyy
 * could be processed by the Lisp reader so that numbers, symbols, strings
 * etc could be specified. However I find that things I often want to
 * use involve characters such as "\" and ":" (as components of file-names
 * on some machines), and sometimes "make" treats these as terminators, or
 * wants to do something magic with "\".  If I put things within quote marks
 * then sometimes the quotes get passed through to Lisp and sometimes not.
 * This is all a BIG misery in a multi-platform situation!  As a fresh
 * attempt to inject sanity I will always convert yyy to a Lisp string. If
 * it is specified with leading and trailing '"' marks I will strip them. Thus
 * both -Dxxx=yyy and -Dxxx="yyy" will leave the variable xxx set to the
 * string "yyy". Then as a Lisp user I can parse the string if I need to
 * interpret it as something else.
 */
#ifndef PASS_PREDEFINES_THROUGH_READER
                if (*s == '"')   /* Convert "yyy" to just yyy */
                {   p = ++s;
                    while (*p != 0) p++;
                    if (*--p == '"') *p = 0;
                }
#endif
                v = make_string(s);
#ifdef PASS_PREDEFINES_THROUGH_READER
                v = Lexplodec(nil, v);
                v = Lcompress(nil, v);
/*
 * The above will first make the value in -Dname=value into a string,
 * then explode it into a list, and compress back - the effect is as if the
 * original value had been passed through the regular Lisp READ function,
 * so symbols, numbers and even s-expressions can be parsed.  If the
 * parsing fails I (silently) treat the value as just NIL.
 */
#endif
                nil = C_nil;
                if (exception_pending()) v = flip_exception();
            }
            pop(n);
            qheader(n) |= SYM_SPECIAL_VAR;
            qvalue(n) = v;
        }
    }
#ifndef COMMON
#ifdef CWIN
/*
 * Now if I have the CWIN windowed system (I might want this info elsewhere
 * too if another windowed implementation of CSL can use it) I look in the
 * Lisp variables
 *    loadable-packages!*
 *    switches!*
 * (both expected to be lists of symbols) and copy info into a couple of
 * C vectors, whence it can go to the window manager and be used to create
 * suitable menus.
 */
    {   Lisp_Object w1 = qvalue(make_undefined_symbol("loadable-packages*"));
        Lisp_Object w2;
        int n;
        char *v;
        n = 0;
        for (w2=w1; consp(w2); w2=qcdr(w2)) n++; /* How many? */
        loadable_packages = (char **)(*malloc_hook)((n+1)*sizeof(char *));
        if (loadable_packages != NULL)
        {   n = 0;
            for (w2=w1; consp(w2); w2=qcdr(w2))
            {   Lisp_Object w3 = qcar(w2);
                int n1;
                if (is_symbol(w3)) w3 = qpname(w3);
                if (!is_vector(w3) ||
                    type_of_header(vechdr(w3)) != TYPE_STRING) break;
                n1 = length_of_header(vechdr(w3))-4;
                v = (char *)(*malloc_hook)(n1+1);
                if (v == NULL) break;
                memcpy(v, &celt(w3, 0), n1);
                v[n1] = 0;
                loadable_packages[n++] = v;
            }
            qsort(loadable_packages, n, sizeof(char *), alpha0);
            loadable_packages[n] = NULL;
        }
        w1 = qvalue(make_undefined_symbol("switches*"));
        n = 0;
        for (w2=w1; consp(w2); w2=qcdr(w2)) n++; /* How many? */
        switches = (char **)(*malloc_hook)((n+1)*sizeof(char *));
        if (switches != NULL)
        {   n = 0;
            for (w2=w1; consp(w2); w2=qcdr(w2))
            {   Lisp_Object w3 = qcar(w2), w4;
                char sname[64];
                int n1;
                if (is_symbol(w3)) w3 = qpname(w3);
                if (!is_vector(w3) ||
                    type_of_header(vechdr(w3)) != TYPE_STRING) break;
                n1 = length_of_header(vechdr(w3))-4;
                if (n1 > 60) break;
                sprintf(sname, "*%.*s", n1, &celt(w3, 0));
                w4 = make_undefined_symbol(sname);
                v = (char *)(*malloc_hook)(n1+2);
                if (v == NULL) break;
/*
 * The first character records the current state of the switch.
 */
                if (qvalue(w4) == nil) v[0] = 'n';
                else v[0] = 'y';
                memcpy(v+1, &celt(w3, 0), n1);
                v[n1+1] = 0;
                switches[n++] = v;
            }
            qsort(switches, n, sizeof(char *), alpha1);
            switches[n] = NULL;
        }
    }

#endif /* CWIN */
#endif /* COMMON */
#ifdef COMMON
    CP = saved_package;
#endif
}

unsigned char registration_data[REGISTRATION_SIZE];
CSLbool MD5_busy;
unsigned char unpredictable[256];
static int n_unpredictable = 0;
static CSLbool unpredictable_pending = 0;

void inject_randomness(int n)
{
    unpredictable[n_unpredictable++] ^= (n % 255);
    if (n_unpredictable >= 256)
    {   n_unpredictable = 0;
        unpredictable_pending = YES;
    }
    if (unpredictable_pending & !MD5_busy)
    {   MD5_Init();
        MD5_Update(unpredictable, sizeof(unpredictable));
        MD5_Final(unpredictable);
        unpredictable_pending = NO;
    }
}

/*
 * For some of what follows I think I need to show that I have considered
 * the issue of export regulations.
 *
 * What I have here is MD5 (and when and if I feel keen SHA-1). I observe
 * that MD5, SHA-1 and DSA are made available as part of Sun's Java
 * Development Kit in the version that can be downloade freely from their
 * servers. They have a separate Java Cryptography Extension within which
 * they keep things that are subject to USA export regulations. I take this
 * as encouragement to believe that these three algorithms are not subject
 * to USA export limits. I believe such limits to be supersets (ie more
 * restrictive) than ones that apply in the UK and so feel happy about
 * including the implementations that I do here. Specifically, although I
 * have extracts from the SSL code which as a whole might give trouble if
 * importen to the USA and the re-exported I only have the message digest
 * bits that should not be so encumbered. I am aware that MD5 is now
 * considered weakish with SHA-1 the improved replacement, but will take the
 * view that I was not aiming for real security on anything anyway!
 */

/*
 *  MD5 message digest code, adapted from Eric Young's version,
 *  for which the copyright and disclaimer notices follow. Observe that
 *  this code can be adapted and re-used subject to these terms being
 *  retained.
 */


/* crypto/md/md5.c and support files */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */

/*
 * End of Eric Young's copyright and disclaimer notice.
 *
 * The changes made by A C Norman remove some optimisation to leave shorter
 * code (I will not be using this in speed-critical applications) and
 * adjusting the style and layout to agree with other Codemist utilities.
 */

#define MD5_CBLOCK         64
#define MD5_LBLOCK         16

static unsigned32 MD5_A, MD5_B, MD5_C, MD5_D;
static unsigned32 MD5_Nl;
static int MD5_num;
static unsigned32 MD5_data[MD5_CBLOCK];

#define F(x,y,z)        ((((y) ^ (z)) & (x)) ^ (z))
#define G(x,y,z)        ((((x) ^ (y)) & (z)) ^ (y))
#define H(x,y,z)        ((x) ^ (y) ^ (z))
#define I(x,y,z)        (((x) | (~(z))) ^ (y))

#define ROTATE(a,n)     (((a)<<(n))|((a)>>(32-(n))))


#define R0(a,b,c,d,k,s,t) {          \
        a+=((k)+(t)+F((b),(c),(d))); \
        a=ROTATE(a,s);               \
        a+=b; }

#define R1(a,b,c,d,k,s,t) {          \
        a+=((k)+(t)+G((b),(c),(d))); \
        a=ROTATE(a,s);               \
        a+=b; }

#define R2(a,b,c,d,k,s,t) {          \
        a+=((k)+(t)+H((b),(c),(d))); \
        a=ROTATE(a,s);               \
        a+=b; }

#define R3(a,b,c,d,k,s,t) {          \
        a+=((k)+(t)+I((b),(c),(d))); \
        a=ROTATE(a,s);               \
        a+=b; }


/*
 * Implemented from RFC1321 The MD5 Message-Digest Algorithm
 */

void MD5_Init(void)
{
    MD5_busy = YES;
    MD5_A = 0x67452301;
    MD5_B = 0xefcdab89;
    MD5_C = 0x98badcfe;
    MD5_D = 0x10325476;
    MD5_Nl = 0;
    MD5_num = 0;
}

static unsigned char byte_order_test[4] = {1, 0, 0, 0};

static void md5_block(void)
{
    unsigned32 A=MD5_A, B=MD5_B, C=MD5_C, D=MD5_D;
    int i;
/*
 * Here I re-write the buffer so that it now behaves as if it is
 * an array of 32-bit words in native computer representation. On
 * many machines the code here will have no effect at all apart from
 * consuming a little time. I do a little test first to see if
 * it is really needed.
 */
    unsigned32 *p = MD5_data;
    unsigned char *q = (unsigned char *)p;
    if (((unsigned32 *)byte_order_test)[0] != 1)
    {   for (i=0; i<MD5_LBLOCK; i++)
        {   unsigned32 w = *q++;
            w |= *q++ << 8;
            w |= *q++ << 16;
            w |= *q++ << 24;
            *p++ = w;
        }
    }
    p = MD5_data;
    /* Round 0 */
    R0(A,B,C,D,p[ 0], 7,0xd76aa478); R0(D,A,B,C,p[ 1],12,0xe8c7b756);
    R0(C,D,A,B,p[ 2],17,0x242070db); R0(B,C,D,A,p[ 3],22,0xc1bdceee);
    R0(A,B,C,D,p[ 4], 7,0xf57c0faf); R0(D,A,B,C,p[ 5],12,0x4787c62a);
    R0(C,D,A,B,p[ 6],17,0xa8304613); R0(B,C,D,A,p[ 7],22,0xfd469501);
    R0(A,B,C,D,p[ 8], 7,0x698098d8); R0(D,A,B,C,p[ 9],12,0x8b44f7af);
    R0(C,D,A,B,p[10],17,0xffff5bb1); R0(B,C,D,A,p[11],22,0x895cd7be);
    R0(A,B,C,D,p[12], 7,0x6b901122); R0(D,A,B,C,p[13],12,0xfd987193);
    R0(C,D,A,B,p[14],17,0xa679438e); R0(B,C,D,A,p[15],22,0x49b40821);
    /* Round 1 */
    R1(A,B,C,D,p[ 1], 5,0xf61e2562); R1(D,A,B,C,p[ 6], 9,0xc040b340);
    R1(C,D,A,B,p[11],14,0x265e5a51); R1(B,C,D,A,p[ 0],20,0xe9b6c7aa);
    R1(A,B,C,D,p[ 5], 5,0xd62f105d); R1(D,A,B,C,p[10], 9,0x02441453);
    R1(C,D,A,B,p[15],14,0xd8a1e681); R1(B,C,D,A,p[ 4],20,0xe7d3fbc8);
    R1(A,B,C,D,p[ 9], 5,0x21e1cde6); R1(D,A,B,C,p[14], 9,0xc33707d6);
    R1(C,D,A,B,p[ 3],14,0xf4d50d87); R1(B,C,D,A,p[ 8],20,0x455a14ed);
    R1(A,B,C,D,p[13], 5,0xa9e3e905); R1(D,A,B,C,p[ 2], 9,0xfcefa3f8);
    R1(C,D,A,B,p[ 7],14,0x676f02d9); R1(B,C,D,A,p[12],20,0x8d2a4c8a);
    /* Round 2 */
    R2(A,B,C,D,p[ 5], 4,0xfffa3942); R2(D,A,B,C,p[ 8],11,0x8771f681);
    R2(C,D,A,B,p[11],16,0x6d9d6122); R2(B,C,D,A,p[14],23,0xfde5380c);
    R2(A,B,C,D,p[ 1], 4,0xa4beea44); R2(D,A,B,C,p[ 4],11,0x4bdecfa9);
    R2(C,D,A,B,p[ 7],16,0xf6bb4b60); R2(B,C,D,A,p[10],23,0xbebfbc70);
    R2(A,B,C,D,p[13], 4,0x289b7ec6); R2(D,A,B,C,p[ 0],11,0xeaa127fa);
    R2(C,D,A,B,p[ 3],16,0xd4ef3085); R2(B,C,D,A,p[ 6],23,0x04881d05);
    R2(A,B,C,D,p[ 9], 4,0xd9d4d039); R2(D,A,B,C,p[12],11,0xe6db99e5);
    R2(C,D,A,B,p[15],16,0x1fa27cf8); R2(B,C,D,A,p[ 2],23,0xc4ac5665);
    /* Round 3 */
    R3(A,B,C,D,p[ 0], 6,0xf4292244); R3(D,A,B,C,p[ 7],10,0x432aff97);
    R3(C,D,A,B,p[14],15,0xab9423a7); R3(B,C,D,A,p[ 5],21,0xfc93a039);
    R3(A,B,C,D,p[12], 6,0x655b59c3); R3(D,A,B,C,p[ 3],10,0x8f0ccc92);
    R3(C,D,A,B,p[10],15,0xffeff47d); R3(B,C,D,A,p[ 1],21,0x85845dd1);
    R3(A,B,C,D,p[ 8], 6,0x6fa87e4f); R3(D,A,B,C,p[15],10,0xfe2ce6e0);
    R3(C,D,A,B,p[ 6],15,0xa3014314); R3(B,C,D,A,p[13],21,0x4e0811a1);
    R3(A,B,C,D,p[ 4], 6,0xf7537e82); R3(D,A,B,C,p[11],10,0xbd3af235);
    R3(C,D,A,B,p[ 2],15,0x2ad7d2bb); R3(B,C,D,A,p[ 9],21,0xeb86d391);

    MD5_A += A;
    MD5_B += B;
    MD5_C += C;
    MD5_D += D;
}

void MD5_Update(unsigned char *data, int len)
{
    unsigned char *p = (unsigned char *)MD5_data;
/*
 * The full MD5 procedure allows for encoding strings of up to
 * around 2^64 bits. I will restrict myself to 2^32 so I can just ignore
 * the high word of the bit-count.
 */
    MD5_Nl += len<<3;   /* Counts in BITS not BYTES here */
    while (len != 0)
    {   p[MD5_num++] = *data++;
        len--;
        if (MD5_num == MD5_CBLOCK)
        {   md5_block();
            MD5_num = 0;
        }
    }
}

void MD5_Final(unsigned char *md)
{
    unsigned32 l = MD5_Nl;
    unsigned char *p = (unsigned char *)MD5_data;
    
    p[MD5_num++] = 0x80;
    if (MD5_num >= MD5_CBLOCK-8)
    {   while (MD5_num < MD5_CBLOCK) p[MD5_num++] = 0;
        md5_block();
        MD5_num = 0;
    }
    while (MD5_num < MD5_CBLOCK-8) p[MD5_num++] = 0;
    p[MD5_num++] = (unsigned char)l;
    p[MD5_num++] = (unsigned char)(l>>8);
    p[MD5_num++] = (unsigned char)(l>>16);
    p[MD5_num++] = (unsigned char)(l>>24);
    p[MD5_num++] = 0;
    p[MD5_num++] = 0;
    p[MD5_num++] = 0;
    p[MD5_num++] = 0;
    md5_block();
    p = md;
    l = MD5_A;
    *p++ = (unsigned char)l;
    *p++ = (unsigned char)(l>>8);
    *p++ = (unsigned char)(l>>16);
    *p++ = (unsigned char)(l>>24);
    l = MD5_B;
    *p++ = (unsigned char)l;
    *p++ = (unsigned char)(l>>8);
    *p++ = (unsigned char)(l>>16);
    *p++ = (unsigned char)(l>>24);
    l = MD5_C;
    *p++ = (unsigned char)l;
    *p++ = (unsigned char)(l>>8);
    *p++ = (unsigned char)(l>>16);
    *p++ = (unsigned char)(l>>24);
    l = MD5_D;
    *p++ = (unsigned char)l;
    *p++ = (unsigned char)(l>>8);
    *p++ = (unsigned char)(l>>16);
    *p++ = (unsigned char)(l>>24);
    MD5_busy = NO;
}

unsigned char *MD5(unsigned char *d, int n, unsigned char *md)
{
    if (n < 0) n = strlen((char *)d);
    MD5_Init();
    MD5_Update(d, n);
    MD5_Final(md);
    return md;
}

#ifdef STAND_ALONE_TESTING_OF_MD5_CODE

int main(int argc, char *argv[])
{
    int i;
    unsigned char mm[16];
    MD5("", 0, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    MD5("a", 1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    MD5("abc", 3, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    MD5("message digest", -1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    MD5("abcdefghijklmnopqrstuvwxyz", -1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    MD5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", -1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    MD5("12345678901234567890123456789012345678901234567890123456789012345678901234567890", -1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    return 0;
}

#endif

/*
 * This is the end of the Eric Young code - what follows is Codemist
 * original code again.
 *
 *
 *
 * The next bit is for an experiment in controlling access to image files
 * etc.  It is solely intended for use in implementing this access control
 * and is not made available as something that a CSL/Reduce user can access
 * directly. It favours high speed above other things, and much of its
 * security in use will be based on nobody having a real incentive to
 * poke at it since CSL-based images will not be expected to be of
 * sufficient value to justify the effort.
 */



int crypt_active;
unsigned char *crypt_buffer;
int crypt_count;

/*
 * The following code was generated by running the program "gencry.c",
 * within which you can find the comments that explain what is going on. The
 * macro TIME_TEST could be defined to make this file more of a self-
 * contained test of its performance, but to do that you probably need
 * to look at the raw output from gencry.c.
 *
 * word length = 32
 * shift register length = 65
 * tap at position 18
 * shuffle-buffer size = 4096
 */

#ifdef TIME_TEST

#include <stdio.h>
#include <time.h>

#define N       10000000   /* parameters for time test */
#define NSTARTS 4000
#define NTINY   50000000
#define KEY     "Arthurs's sample key"

typedef unsigned int unsigned32;

#endif /* TIME_TEST */

static unsigned32 lf[65], mix[4096];

#define R(x) ((x) >> 20)
#define S(x) ((x) >> 18)
#define T(x) ((x) << 13)

/*
 * static unsigned char byte_order_test[] =
 * {1, 0, 0, 0, 0, 0, 0, 0};
 */

#define CRYPT_BLOCK_SIZE 128

void crypt_get_block(unsigned char block[CRYPT_BLOCK_SIZE])
{
    unsigned32 *b = (unsigned32 *)block;
    int n;
    lf[0] -= lf[18];     lf[1] ^= lf[19];
    lf[2] -= lf[20];     lf[3] += lf[21];
    lf[4] += lf[22];     lf[5] -= lf[23];
    lf[6] ^= lf[24];     lf[7] -= lf[25];
    lf[8] += lf[26];     lf[9] ^= lf[27];
    lf[10] -= lf[28];    lf[11] -= lf[29];
    lf[12] += lf[30];    lf[13] += lf[31];
    lf[14] -= lf[32];    lf[15] ^= lf[33];
    lf[16] -= lf[34];    lf[17] += lf[35];
    lf[18] += lf[36];    lf[19] += lf[37];
    lf[20] -= lf[38];    lf[21] -= lf[39];
    lf[22] ^= lf[40];    lf[23] += lf[41];
    lf[24] -= lf[42];    lf[25] -= lf[43];
    lf[26] += lf[44];    lf[27] += lf[45];
    lf[28] -= lf[46];    lf[29] ^= lf[47];
    lf[30] -= lf[48];    lf[31] += lf[49];
    lf[32] -= lf[50];    lf[33] ^= lf[51];
    lf[34] -= lf[52];    lf[35] ^= lf[53];
    lf[36] += lf[54];    lf[37] += lf[55];
    lf[38] ^= lf[56];    lf[39] ^= lf[57];
    lf[40] += lf[58];    lf[41] -= lf[59];
    lf[42] ^= lf[60];    lf[43] += lf[61];
    lf[44] += lf[62];    lf[45] ^= lf[63];
    lf[46] ^= lf[64];    lf[47] -= lf[0];
    lf[48] ^= lf[1];     lf[49] ^= lf[2];
    lf[50] ^= lf[3];     lf[51] ^= lf[4];
    lf[52] ^= lf[5];     lf[53] ^= lf[6];
    lf[54] += lf[7];     lf[55] -= lf[8];
    lf[56] -= lf[9];     lf[57] ^= lf[10];
    lf[58] -= lf[11];    lf[59] -= lf[12];
    lf[60] ^= lf[13];    lf[61] += lf[14];
    lf[62] ^= lf[15];    lf[63] -= lf[16];
    lf[64] -= lf[17];
    n = R(lf[0]); b[0] = mix[n]; mix[n] = (lf[54] + S(lf[29])) ^ T(lf[5]);
    n = R(lf[1]); b[1] = mix[n]; mix[n] = ~(lf[39] + S(lf[47])) + T(lf[15]);
    n = R(lf[2]); b[2] = mix[n]; mix[n] = (lf[25] + S(lf[14])) + T(lf[38]);
    n = R(lf[4]); b[3] = mix[n]; mix[n] = ~(lf[48] - S(lf[40])) ^ T(lf[10]);
    n = R(lf[5]); b[4] = mix[n]; mix[n] = (lf[44] - S(lf[55])) - T(lf[49]);
    n = R(lf[6]); b[5] = mix[n]; mix[n] = ~(lf[9] ^ S(lf[37])) + T(lf[50]);
    n = R(lf[8]); b[6] = mix[n]; mix[n] = (lf[64] ^ S(lf[51])) + T(lf[8]);
    n = R(lf[9]); b[7] = mix[n]; mix[n] = ~(lf[11] - S(lf[35])) - T(lf[21]);
    n = R(lf[10]); b[8] = mix[n]; mix[n] = (lf[20] ^ S(lf[21])) ^ T(lf[3]);
    n = R(lf[12]); b[9] = mix[n]; mix[n] = ~(lf[6] ^ S(lf[31])) - T(lf[61]);
    n = R(lf[13]); b[10] = mix[n]; mix[n] = (lf[3] - S(lf[16])) ^ T(lf[16]);
    n = R(lf[14]); b[11] = mix[n]; mix[n] = ~(lf[17] - S(lf[53])) - T(lf[2]);
    n = R(lf[16]); b[12] = mix[n]; mix[n] = (lf[27] + S(lf[42])) - T(lf[33]);
    n = R(lf[17]); b[13] = mix[n]; mix[n] = ~(lf[28] + S(lf[63])) - T(lf[46]);
    n = R(lf[18]); b[14] = mix[n]; mix[n] = (lf[10] - S(lf[46])) + T(lf[35]);
    n = R(lf[20]); b[15] = mix[n]; mix[n] = ~(lf[53] - S(lf[10])) - T(lf[27]);
    n = R(lf[21]); b[16] = mix[n]; mix[n] = (lf[4] + S(lf[18])) - T(lf[7]);
    n = R(lf[22]); b[17] = mix[n]; mix[n] = ~(lf[43] + S(lf[64])) ^ T(lf[45]);
    n = R(lf[24]); b[18] = mix[n]; mix[n] = (lf[14] + S(lf[26])) + T(lf[44]);
    n = R(lf[25]); b[19] = mix[n]; mix[n] = ~(lf[23] ^ S(lf[38])) + T(lf[58]);
    n = R(lf[26]); b[20] = mix[n]; mix[n] = (lf[47] + S(lf[59])) ^ T(lf[47]);
    n = R(lf[28]); b[21] = mix[n]; mix[n] = ~(lf[63] - S(lf[36])) - T(lf[57]);
    n = R(lf[29]); b[22] = mix[n]; mix[n] = (lf[56] + S(lf[4])) + T(lf[19]);
    n = R(lf[30]); b[23] = mix[n]; mix[n] = ~(lf[42] - S(lf[52])) - T(lf[56]);
    n = R(lf[32]); b[24] = mix[n]; mix[n] = (lf[37] + S(lf[3])) - T(lf[63]);
    n = R(lf[33]); b[25] = mix[n]; mix[n] = ~(lf[32] + S(lf[1])) - T(lf[12]);
    n = R(lf[34]); b[26] = mix[n]; mix[n] = (lf[62] - S(lf[39])) - T(lf[31]);
    n = R(lf[36]); b[27] = mix[n]; mix[n] = ~(lf[2] ^ S(lf[44])) ^ T(lf[18]);
    n = R(lf[37]); b[28] = mix[n]; mix[n] = (lf[24] ^ S(lf[50])) ^ T(lf[55]);
    n = R(lf[38]); b[29] = mix[n]; mix[n] = ~(lf[22] + S(lf[27])) - T(lf[32]);
    n = R(lf[40]); b[30] = mix[n]; mix[n] = (lf[51] + S(lf[33])) + T(lf[0]);
    n = R(lf[41]); b[31] = mix[n]; mix[n] = ~(lf[52] ^ S(lf[19])) - T(lf[26]);
    n = R(lf[42]); mix[n] = (lf[5] ^ S(lf[41])) + T(lf[28]);
    n = R(lf[44]); mix[n] = ~(lf[30] ^ S(lf[15])) - T(lf[30]);
    n = R(lf[45]); mix[n] = (lf[45] + S(lf[24])) ^ T(lf[51]);
    n = R(lf[46]); mix[n] = ~(lf[13] + S(lf[49])) - T(lf[11]);
    n = R(lf[48]); mix[n] = (lf[16] + S(lf[11])) - T(lf[39]);
    n = R(lf[49]); mix[n] = ~(lf[57] - S(lf[43])) - T(lf[60]);
    n = R(lf[50]); mix[n] = (lf[49] + S(lf[48])) ^ T(lf[25]);
    n = R(lf[52]); mix[n] = ~(lf[34] - S(lf[22])) ^ T(lf[23]);
    n = R(lf[53]); mix[n] = (lf[18] + S(lf[6])) + T(lf[1]);
    n = R(lf[54]); mix[n] = ~(lf[29] + S(lf[61])) - T(lf[64]);
    n = R(lf[56]); mix[n] = (lf[59] ^ S(lf[45])) - T(lf[41]);
    n = R(lf[57]); mix[n] = ~(lf[36] - S(lf[32])) + T(lf[37]);
    n = R(lf[58]); mix[n] = (lf[40] + S(lf[60])) + T(lf[14]);
    n = R(lf[60]); mix[n] = ~(lf[1] + S(lf[56])) ^ T(lf[36]);
    n = R(lf[61]); mix[n] = (lf[8] ^ S(lf[5])) ^ T(lf[17]);
    n = R(lf[62]); mix[n] = ~(lf[31] ^ S(lf[17])) ^ T(lf[52]);
/* The test this way around favours Intel etc byte order */
    if (((unsigned int *)byte_order_test)[0] != 1)
    {   int i;
        for (i=0; i<32; i++)
        {   unsigned32 w = b[i];
            unsigned32 b0, b1, b2, b3;
            b0 = (w >> 24) & 0xffU;
            b1 = (w >> 8) & 0xff00U;
            b2 = (w << 8) & 0xff0000U;
            b3 = (w << 24) & 0xff000000U;
            b[i] = b0 | b1 | b2 | b3;
        }
    }
    return;
}

void crypt_init(char *key)
{
    char *pk = key;
    unsigned char junk[CRYPT_BLOCK_SIZE];
    int i, j;
    unsigned32 w = 0;
    for (i=0; i<260; i++)
    {   int k = *pk++;
        if (k == 0) pk = key;  /* Cycle key (inc. terminating 0) */
        w = (w << 8) | (k & 0xff);
        if ((i % 4) == 3) lf[i/4] = w;
    }
    for (i=0; i<4096; i++) mix[i] = 0;
    for (i=0; i<8; i++)
    {   for (j=0; j<65; j++)
            lf[j] = (lf[j] << 10) | (lf[j] >> 22);
        lf[0] |= 1;
        for (j=0; j<64; j++)
            crypt_get_block(junk);
    }
    for (i=0; i<4096;)
    {   int j;
        crypt_get_block(junk);
        for (j=0; j<32; j++)
        {   unsigned32 r = junk[4*j];
            r = (r << 8) | junk[4*j+1];
            r = (r << 8) | junk[4*j+2];
            r = (r << 8) | junk[4*j+3];
            if (r == 0) continue;
            mix[i++] ^= junk[j];
            if (i == 4096) break;
        }
    }
    for (i=0; i<192; i++)
        crypt_get_block(junk);
    return;
}

#ifdef TIME_TEST
/*
 * The main program here does not do anything of real interest. It
 * runs both the key-setup and the main loop lots of times and reports
 * how long it all takes.
 *
 * Here is some sample output from a Pentium-II 400Mhz system
 *
 * [02faf080] 7.60 nanoseconds to do tiny loop
 * 1.25 milliseconds to startup
 * rate = 104.86 megabytes per second
 * 79 a7 e1 52 2e 84 09 ce d0 3d 45 b2 52 2d b6 c7
 * 9b ee 57 25 68 58 b7 44 42 51 1c c7 de 69 0f 89
 * 98 6c cd 45 e0 a1 d4 04 a3 be 3d 5f 93 64 c9 d9
 * b9 47 28 59 d0 99 5a 35 56 fd 89 e6 48 4f a4 88
 * 7e dd 31 76 2b 8e 96 fa d0 6f d7 30 9c 3c 01 97
 * 8a 54 93 c0 02 1d 26 df 31 2b 7b 92 56 51 fa 47
 * 92 13 39 47 45 d2 b5 33 2b f6 cc 62 ec 73 00 40
 * 66 ab 37 f5 1d 21 3a a9 b8 da 35 ac 04 f1 3b 53
 *
 */

int main(int argc, char *argv[])
{
    clock_t c0, c1;
    unsigned char r[CRYPT_BLOCK_SIZE];
    int i, j = 0;
    double rate;
    c0 = clock();
    for (i=0; i<(NTINY+1); i++) j ^= i;
    c1 = clock();
    printf("[%.8x] %.2f nanoseconds to do tiny loop\n", j,
       1.0e9*(double)(c1-c0)/((double)CLOCKS_PER_SEC*(double)(NTINY+1)));
    c0 = clock();
    for (i=0; i<NSTARTS; i++) crypt_init(KEY);
    c1 = clock();
    printf("%.2f milliseconds to startup\n",
       1000.0*(double)(c1-c0)/((double)CLOCKS_PER_SEC*(double)NSTARTS));
    c0 = clock();
    for (i=0; i<N; i++) crypt_get_block(r);
    c1 = clock();
    rate = (double)N*(double)CRYPT_BLOCK_SIZE*(double)CLOCKS_PER_SEC/
           ((double)(c1-c0)*1.0e6);
    printf("rate = %.2f megabytes per second\n", rate);
    for (i=0; i<128; i++)
    {   printf("%.2x ", r[i]);
        if ((i % 16) == 15) printf("\n");
    }
    return 0;
}

#endif /* TIME_TEST */

#undef R
#undef S
#undef T

/* End of generated code... */

static void get_checksum(const setup_type *p)
{
    while (p->name!=NULL) p++;
    if (p->one != NULL && p->two != NULL)
    {   unsigned char *w = (unsigned char *)p->two;
        MD5_Update(w, strlen((char *)w));
    }
}

void get_user_files_checksum(unsigned char *b)
{
    MD5_Init();
    get_checksum(u01_setup);
    get_checksum(u02_setup);
    get_checksum(u03_setup);
    get_checksum(u04_setup);
    get_checksum(u05_setup);
    get_checksum(u06_setup);
    get_checksum(u07_setup);
    get_checksum(u08_setup);
    get_checksum(u09_setup);
    get_checksum(u10_setup);
    get_checksum(u11_setup);
    get_checksum(u12_setup);
    MD5_Final(b);
}

char *crypt_keys[CRYPT_KEYS];


void setup(int restartp, double store_size)
{
    int i;
    Lisp_Object nil;
#ifdef TIME_TEST_CRYPTO
/* *********** Now I will time my encryption stuff... ************* */
    clock_t t0 = clock(), t1;
#define TRIALS 2000
    for (i=0; i<TRIALS; i++) crypt_init("Arthur\'s secret key");
    t1 = clock();
    term_printf("Time for crypt_init = %.2g milliseconds\n",
        1.0e3*((double)(t1-t0))/(double)CLOCKS_PER_SEC/(double)TRIALS);
#define TRIALS1 1000000
    {   unsigned char buffer[CRYPT_BLOCK];
        t0 = clock();
        for (i=0; i<TRIALS1; i++) crypt_get_block(buffer);
        t1 = clock();
    }
    {   double Mbytes = (double)TRIALS1*(double)CRYPT_BLOCK/1000000.0;
        double seconds = (double)(t1-t0)/(double)CLOCKS_PER_SEC;
        term_printf("Time to do 1 Mbyte = %.2g seconds\n", seconds/Mbytes);
        term_printf("Ie %.4g Mbytes per sec\n", Mbytes/seconds);
    }
/* **************** end of temp gunk ***************** */
#endif
    crypt_active = -1;

#ifdef DEBUG
/*
 * Just a sanity check so that if I add entries in this table but to
 * not change the recorded size I will be warned.
 */
    if ((entry_table_size+1)*sizeof(entry_point) != sizeof(entries_table))
    {   term_printf("entry_table_size badly set up in externs.h\n");
        my_exit(EXIT_FAILURE);
    }
    if (sizeof(int32) != 4 ||
        sizeof(unsigned32) != 4 ||
#ifdef SIXTY_FOUR_BIT
        sizeof(int64) != 8 ||
        sizeof(unsigned64) != 8 ||
#endif
#ifndef ILP64
        sizeof(int16) != 2 ||
        sizeof(unsigned16) != 2 ||
#endif
        sizeof(int8) != 1 ||
        sizeof(unsigned8) != 1)
    {   term_printf("Some datatype size is wrongly set up in tags.h\n");
        my_exit(EXIT_FAILURE);
    }
#endif

    if (restartp & 2) init_heap_segments(store_size);
    restartp &= 1;
    nil = C_nil;
#ifdef TIDY_UP_MEMORY_AT_START
/*
 * The following should not be needed, feature on big machines could be
 * expensive.  The code is left in case it helps with repeatability in
 * the face of accesses to uninitialised locations (ie BUGS)
 */
    for (i=0; i<pages_count; i++)
        memset(pages[i], 0, (size_t)CSL_PAGE_SIZE+16);
    memset(stacksegment, 0, (size_t)stack_segsize*CSL_PAGE_SIZE+16);
    memset(nilsegment, 0, (size_t)NIL_SEGMENT_SIZE);
#endif
    stack = stackbase;
    exit_tag = exit_value = nil;
    exit_reason = UNWIND_NULL;

    if (restartp & 1)
    {   char junkbuf[120];
        char filename[LONGEST_LEGAL_FILENAME];
        if (IopenRoot(filename, 0))
        {   term_printf("\n+++ Image file \"%s\" can not be read\n",
                    filename);
            my_exit(EXIT_FAILURE);
        }
/*
 * I read input via a buffer of size FREAD_BUFFER_SIZE, which I pre-fill
 * at this stage before I even try to read anything
 */
        fread_ptr = (unsigned char *)stack;
        fread_count = Iread(fread_ptr, FREAD_BUFFER_SIZE);
/*
 * I can adjust here (automatically) for whatever compression threshold
 * had been active when the image file was created.
 */
        compression_worth_while = 128;
        crypt_active = -1;
        Cfread(junkbuf, 112);
        {   int fg = junkbuf[111];
            while (fg != 0) compression_worth_while <<= 1, fg--;
            fg = junkbuf[110];
            while (fg != 0) crypt_active++, fg--;
            if (crypt_active >= 0 &&
                crypt_active < CRYPT_KEYS &&
                crypt_keys[crypt_active] != NULL)
            {   crypt_init(crypt_keys[crypt_active]);
                if ((crypt_buffer = 
                       (unsigned char *)(*malloc_hook)(CRYPT_BLOCK))
                     == NULL) crypt_active = -1; /* And will then fail */
                crypt_count = 0;
            }
        }
        if (init_flags & INIT_VERBOSE)
        {   term_printf("Created: %.25s\n", &junkbuf[64]);
            /* Time dump was taken */
        }
        {   unsigned char chk[16];
            get_user_files_checksum(chk);
            for (i=0; i<16; i++)
            {   if (chk[i] != (junkbuf[90+i] & 0xff))
                {   term_printf(
                        "\n+++ Image file belongs with a different version\n");
                    term_printf(
                        "    of the executable file (incompatible code\n");
                    term_printf(
                        "    has been optimised into C and incorporated)\n");
                    term_printf(
                        "    Unable to use this image file, so stopping\n");
                    my_exit(EXIT_FAILURE);
                }
            }
        }
/*
 * To make things more responsive for the user I will display a
 * banner rather early (before reading the bulk of the image file).
 * The banner that I will display is one provided to be by PRESERVE.
 */
        {   Ihandle save;
            char b[64];
            int i;
            Icontext(&save);
#define BANNER_CODE (-1002)
            if (IopenRoot(filename, BANNER_CODE)) b[0] = 0;
            else
            {   for (i=0; i<64; i++) b[i] = (char)Igetc();
                IcloseInput(NO);
            }
            Irestore_context(save);
/*
 * A banner set via startup-banner takes precedence over one from preserve.
 */
            if (b[0] != 0)
            {   term_printf("%s\n", b);
                ensure_screen();
            }
            else if (junkbuf[0] != 0)
            {   term_printf("%s\n", junkbuf);
                ensure_screen();
            }
        }
#ifdef PREVIOUS_ATTEMPT_AT_AUTHENTICATION
        {   char username[48];
            unsigned char sig[16];
            unsigned32 hash;
            int c1;
            unsigned char *s = &registration_data[4];
            MD5_Update(s, 48);
            MD5_Final(sig);
            if (memcmp(sig, &s[48], 16) != 0)
            {   term_printf("************************************\n");
                term_printf("* Registration data seems corrupt  *\n");
                term_printf("* Please check with your supplier. *\n");
                term_printf("************************************\n");
/*
 * If I were really feeling confident - or possibly mean - I would
 * just exit from the system here declaring that my consistency check
 * had failed and that hence there was a presumption that somebody had
 * tried to patch or otherwise bodge my registration-name code. At least for
 * a few weeks I will not go that far, and I will expect that the annoying
 * message above will do quite enough. The real security that I can enforce
 * is pretty low anyway, and so overall I believe that the policy adopted
 * here is probably adequate.
 */
            }
            else
            {   hash = *s++;
                hash |= *s++<<8;
                hash |= *s++<<16;
                hash |= *s++<<24;
                for (c1=0;c1<44;c1++)
                {   hash = 69069*hash + 314159;
                    username[c1] = *s++ ^ (hash >> 16);
                }
                while (c1 > 0 && username[--c1] == ' ') username[c1] = 0;
                term_printf("Registered to: %s\n", username);
            }
        }
#endif /* AUTHORIZATION */
/*
 * From here on if crypt_active is >= 0 I will be decoding an encrypted
 * image file.
 */
        Cfread(junkbuf, 8);
        Cfread((char *)BASE, sizeof(Lisp_Object)*last_nil_offset);
        copy_out_of_nilseg(YES);
#ifndef COMMON
        qheader(nil) = TAG_ODDS+TYPE_SYMBOL+SYM_SPECIAL_VAR;/* BEFORE nil... */
#endif
        if ((byteflip & 0xffff0000U) == 0x56780000U)
        {
#ifndef ADDRESS_64
            flip_needed = NO;
#endif
            old_fp_rep = (int)(byteflip & FP_MASK);
            old_page_bits = (int)((byteflip >> 8) & 0x1f);
        }
        else if ((byteflip & 0x0000ffffU) == 0x00007856U)
        {
#ifndef ADDRESS_64
            flip_needed = YES;
#endif
            old_fp_rep = (int)(flip_bytes_fn(byteflip) & FP_MASK);
            old_page_bits = (int)((flip_bytes_fn(byteflip) >> 8) & 0x1f);
        }
        else
        {   term_printf("\n+++ The checkpoint file is corrupt\n");
/*
 * Note: I use different numbers to check byte-ordering on segmented feature
 * non-segmented systems, since the heap image formats are not compatible.
 * A result will be that use of the wrong sort of image will lead to a
 * "checkpoint file corrupt" message rather than a more serious shambles.
 */
            my_exit(EXIT_FAILURE);
        }
        if (old_page_bits == 0) old_page_bits = 16; /* Old default value */
/*
 * I could in fact recover in the case that old_page_bits < PAGE_BITS, since
 * I could just map the old small pages into the new big ones with a little
 * padding where needed.  I will not do that JUST yet.  In general it will
 * not be possible to load an image with large pages into a CSL that only
 * has small ones - eg there might be some vector that just would not fit
 * in the small page size.  Even discounting that worry rearranging the
 * heap to allow for the discontinuities at the smaller page granularity would
 * be pretty painful.  Again in the limit something very much akin to the
 * normal garbage collector could probably do it if it ever became really
 * necessary.
 */
        if (old_page_bits != PAGE_BITS)
        {   term_printf("\n+++ The checkpoint file was made on a machine\n");
            term_printf("where CSL had been configured with a different page\n");
            term_printf("size. It is not usable with this version.\n");
            my_exit(EXIT_FAILURE);
        }
        /* The saved value of NIL is not needed in this case */
    }
    else
    {
        for (i=first_nil_offset; i<last_nil_offset; i++)
             BASE[i] = nil;
        copy_out_of_nilseg(NO);
    }

    stacklimit = &stack[stack_segsize*CSL_PAGE_SIZE/4-200]; 
                 /* allow some slop at end */
    byteflip = 0x56780000 |
               ((int32)current_fp_rep & ~FP_WORD_ORDER) |
               (((int32)PAGE_BITS) << 8);
    native_pages_changed = 0;
    if (restartp) warm_setup();
    else cold_setup();

    if (init_flags & INIT_QUIET) Lverbos(nil, fixnum_of_int(1));
    if (init_flags & INIT_VERBOSE) Lverbos(nil, fixnum_of_int(3));
#ifndef HOLD_BACK_MEMORY
/*
 * Here I grab more memory (if I am allowed to) until the proportion of the
 * heap active at the end of garbage collection is less than 1/2.  If the
 * attempt to grab more memory fails I clear the bit in init_flags that
 * allows me to try to expand, so I will not waste time again.  If
 * HOLD_BACK_MEMORY was asserted (for machines where grabbing all seemingly
 * available memory may cause a crash) I do not try this operation.  The
 * aim of keeping the heap less than half full is an heuristic and could be
 * adjusted on the basis of experience with this code.
 */
    if (init_flags & INIT_EXPANDABLE)
    {   int32 more = heap_pages_count + vheap_pages_count +
                     bps_pages_count + native_pages_count;
        more = 3 *more - pages_count;
        while (more-- > 0)
        {   void *page = (void *)my_malloc_1((size_t)(CSL_PAGE_SIZE + 16));
/*
 * CF the code in gc.c -- I can still use my_malloc_1 here, which makes this
 * code just a tiny bit safer.
 */
            intxx pun = (intxx)page;
            intxx pun1 = (intxx)((char *)page + CSL_PAGE_SIZE + 16);
            if ((pun ^ pun1) < 0) page = NULL;
#ifdef ADDRESS_SIGN_UNKNOWN
            if ((pun + address_sign) < 0) page = NULL;
#else
#ifdef ADDRESSES_HAVE_TOP_BIT_SET
            if (pun > 0) page = NULL;
#else
            if (pun < 0) page = NULL;
#endif
#endif
            if (page == NULL)
            {   init_flags &= ~INIT_EXPANDABLE;
                break;
            }
            else pages[pages_count++] = page;
        }
    }
#endif
    {
      int32 w = 0;
#ifndef NO_COPYING_GC
/*
 * I will make the first garbage collection a copying one if the heap is
 * at most 25% full, or a sliding one if it is more full than that.
 */
      w = heap_pages_count + vheap_pages_count +
          bps_pages_count + native_pages_count;
      gc_method_is_copying = (pages_count > 3*w);
#endif
/*
 * The total store allocated is that used plus that free, including the
 * page set aside for the Lisp stack.
 */
        if (init_flags & INIT_VERBOSE)
            term_printf("Memory allocation: %ld bytes\n",
                                         (long)CSL_PAGE_SIZE*(pages_count+w+1));
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(15);
#endif
#endif
    return;
}

void copy_into_nilseg(int fg)
{
    int i;
    Lisp_Object nil = C_nil;

#ifdef NILSEG_EXTERNS
    if (fg)     /* move non list bases too */
    {   *(unsigned32 *)&BASE[12]                 = byteflip;
        BASE[13]                                 = codefringe;
        *(Lisp_Object volatile *)&BASE[14]       = codelimit;
/*
 * The messing around here is to ensure that on 64-bit architectures
 * stacklimit is kept properly aligned.
 */
#ifdef COMMON
        *(Lisp_Object * volatile *)&BASE[16] = stacklimit;
#else
        *(Lisp_Object * volatile *)&BASE[15] = stacklimit;
#endif
        BASE[18]                                 = fringe;
        *(Lisp_Object volatile *)&BASE[19]       = heaplimit;
        *(Lisp_Object volatile *)&BASE[20]       = vheaplimit;
        BASE[21]                                 = vfringe;
        *(unsigned32 *)&BASE[22]                 = miscflags;

        *(int32 *)&BASE[24]                      = nwork;
        *(int32 *)&BASE[25]                      = exit_reason;
        *(int32 *)&BASE[26]                      = exit_count;
        *(unsigned32 *)&BASE[27]                 = gensym_ser;
        *(unsigned32 *)&BASE[28]                 = print_precision;
        *(int32 *)&BASE[29]                      = current_modulus;
        *(int32 *)&BASE[30]                      = fastget_size;
        *(int32 *)&BASE[31]                      = package_bits;
    }
/*
 * Entries 50 and 51 are used for chains of hash tables, and so get
 * very special individual treatment.
 */
    BASE[52]     = current_package;
    BASE[53]     = B_reg;
    BASE[54]     = codevec;
    BASE[55]     = litvec;
    BASE[56]     = exit_tag;
    BASE[57]     = exit_value;
    BASE[58]     = catch_tags;
    BASE[59]     = lisp_package;
    BASE[60]     = boffo;
    BASE[61]     = charvec;
    BASE[62]     = sys_hash_table;
    BASE[63]     = help_index;
    BASE[64]     = gensym_base;
    BASE[65]     = err_table;
    BASE[66]     = supervisor;
    BASE[67]     = startfn;
    BASE[68]     = faslvec;
    BASE[69]     = tracedfn;
    BASE[70]     = prompt_thing;
    BASE[71]     = faslgensyms;
    BASE[72]     = cl_symbols;
    BASE[73]     = active_stream;
    BASE[74]     = current_module;

    BASE[90]     = append_symbol;
    BASE[91]     = applyhook;
    BASE[92]     = cfunarg;
    BASE[93]     = comma_at_symbol;
    BASE[94]     = comma_symbol;
    BASE[95]     = compiler_symbol;
    BASE[96]     = comp_symbol;
    BASE[97]     = cons_symbol;
    BASE[98]     = echo_symbol;
    BASE[99]     = emsg_star;
    BASE[100]    = evalhook;
    BASE[101]    = eval_symbol;
    BASE[102]    = expr_symbol;
    BASE[103]    = features_symbol;
    BASE[104]    = fexpr_symbol;
    BASE[105]    = funarg;
    BASE[106]    = function_symbol;
    BASE[107]    = lambda;
    BASE[108]    = lisp_true;
    BASE[109]    = lower_symbol;
    BASE[110]    = macroexpand_hook;
    BASE[111]    = macro_symbol;
    BASE[112]    = opt_key;
    BASE[113]    = prinl_symbol;
    BASE[114]    = progn_symbol;
    BASE[115]    = quote_symbol;
    BASE[116]    = raise_symbol;
    BASE[117]    = redef_msg;
    BASE[118]    = rest_key;
    BASE[119]    = savedef;
    BASE[120]    = string_char_sym;
    BASE[121]    = unset_var;
    BASE[122]    = work_symbol;
    BASE[123]    = lex_words;
    BASE[124]    = get_counts;
    BASE[125]    = fastget_names;
    BASE[126]    = input_libraries;
    BASE[127]    = output_library;
    BASE[128]    = current_file;
    BASE[129]    = break_function;

    BASE[130]    = lisp_work_stream;
    BASE[131]    = lisp_standard_output;
    BASE[132]    = lisp_standard_input;
    BASE[133]    = lisp_debug_io;
    BASE[134]    = lisp_error_output;
    BASE[135]    = lisp_query_io;
    BASE[136]    = lisp_terminal_io;
    BASE[137]    = lisp_trace_output;
    BASE[138]    = standard_output;
    BASE[139]    = standard_input;
    BASE[140]    = debug_io;
    BASE[141]    = error_output;
    BASE[142]    = query_io;
    BASE[143]    = terminal_io;
    BASE[144]    = trace_output;
    BASE[145]    = fasl_stream;
    BASE[146]    = native_code;
    BASE[147]    = native_symbol;
    BASE[148]    = traceprint_symbol;
    BASE[149]    = loadsource_symbol;
    BASE[150]    = hankaku_symbol;

#ifdef COMMON
    BASE[170]    = keyword_package;
    BASE[171]    = all_packages;
    BASE[172]    = package_symbol;
    BASE[173]    = internal_symbol;
    BASE[174]    = external_symbol;
    BASE[175]    = inherited_symbol;
    BASE[176]    = key_key;
    BASE[177]    = allow_other_keys;
    BASE[178]    = aux_key;
    BASE[179]    = format_symbol;
    BASE[180]    = expand_def_symbol;
    BASE[181]    = allow_key_key;
    BASE[182]    = declare_symbol;
    BASE[183]    = special_symbol;
#endif

    for (i=0; i<=50; i++)
        BASE[work_0_offset+i]   = workbase[i];
#endif /* NILSEG_EXTERNS */
    BASE[190]    = user_base_0;
    BASE[191]    = user_base_1;
    BASE[192]    = user_base_2;
    BASE[193]    = user_base_3;
    BASE[194]    = user_base_4;
    BASE[195]    = user_base_5;
    BASE[196]    = user_base_6;
    BASE[197]    = user_base_7;
    BASE[198]    = user_base_8;
    BASE[199]    = user_base_9;

}

void copy_out_of_nilseg(int fg)
{
    int i;
    Lisp_Object nil = C_nil;

#ifdef NILSEG_EXTERNS
    if (fg)
    {
        byteflip         = *(unsigned32 *)&BASE[12];
        codefringe       = BASE[13];
        codelimit        = *(Lisp_Object volatile *)&BASE[14];
#ifdef COMMON
        stacklimit       = *(Lisp_Object *volatile *)&BASE[16];
#else
        stacklimit       = *(Lisp_Object *volatile *)&BASE[15];
#endif
        fringe           = BASE[18];
        heaplimit        = *(Lisp_Object volatile *)&BASE[19];
        vheaplimit       = *(Lisp_Object volatile *)&BASE[20];
        vfringe          = BASE[21];
        miscflags        = *(unsigned32 *)&BASE[22];

        nwork            = *(int32 *)&BASE[24];
        exit_reason      = *(int32 *)&BASE[25];
        exit_count       = *(int32 *)&BASE[26];
        gensym_ser       = *(unsigned32 *)&BASE[27];
        print_precision  = *(unsigned32 *)&BASE[28];
        current_modulus  = *(int32 *)&BASE[29];
        fastget_size     = *(int32 *)&BASE[30];
        package_bits     = *(int32 *)&BASE[31];
    }

    current_package       = BASE[52];
    B_reg                 = BASE[53];
    codevec               = BASE[54];
    litvec                = BASE[55];
    exit_tag              = BASE[56];
    exit_value            = BASE[57];
    catch_tags            = BASE[58];
    lisp_package          = BASE[59];
    boffo                 = BASE[60];
    charvec               = BASE[61];
    sys_hash_table        = BASE[62];
    help_index            = BASE[63];
    gensym_base           = BASE[64];
    err_table             = BASE[65];
    supervisor            = BASE[66];
    startfn               = BASE[67];
    faslvec               = BASE[68];
    tracedfn              = BASE[69];
    prompt_thing          = BASE[70];
    faslgensyms           = BASE[71];
    cl_symbols            = BASE[72];
    active_stream         = BASE[73];
    current_module        = BASE[74];

    append_symbol         = BASE[90];
    applyhook             = BASE[91];
    cfunarg               = BASE[92];
    comma_at_symbol       = BASE[93];
    comma_symbol          = BASE[94];
    compiler_symbol       = BASE[95];
    comp_symbol           = BASE[96];
    cons_symbol           = BASE[97];
    echo_symbol           = BASE[98];
    emsg_star             = BASE[99];
    evalhook              = BASE[100];
    eval_symbol           = BASE[101];
    expr_symbol           = BASE[102];
    features_symbol       = BASE[103];
    fexpr_symbol          = BASE[104];
    funarg                = BASE[105];
    function_symbol       = BASE[106];
    lambda                = BASE[107];
    lisp_true             = BASE[108];
    lower_symbol          = BASE[109];
    macroexpand_hook      = BASE[110];
    macro_symbol          = BASE[111];
    opt_key               = BASE[112];
    prinl_symbol          = BASE[113];
    progn_symbol          = BASE[114];
    quote_symbol          = BASE[115];
    raise_symbol          = BASE[116];
    redef_msg             = BASE[117];
    rest_key              = BASE[118];
    savedef               = BASE[119];
    string_char_sym       = BASE[120];
    unset_var             = BASE[121];
    work_symbol           = BASE[122];
    lex_words             = BASE[123];
    get_counts            = BASE[124];
    fastget_names         = BASE[125];
    input_libraries       = BASE[126];
    output_library        = BASE[127];
    current_file          = BASE[128];
    break_function        = BASE[129];

    lisp_work_stream      = BASE[130];
    lisp_standard_output  = BASE[131];
    lisp_standard_input   = BASE[132];
    lisp_debug_io         = BASE[133];
    lisp_error_output     = BASE[134];
    lisp_query_io         = BASE[135];
    lisp_terminal_io      = BASE[136];
    lisp_trace_output     = BASE[137];
    standard_output       = BASE[138];
    standard_input        = BASE[139];
    debug_io              = BASE[140];
    error_output          = BASE[141];
    query_io              = BASE[142];
    terminal_io           = BASE[143];
    trace_output          = BASE[144];
    fasl_stream           = BASE[145];
    native_code           = BASE[146];
    native_symbol         = BASE[147];
    traceprint_symbol     = BASE[148];
    loadsource_symbol     = BASE[149];
    hankaku_symbol        = BASE[150];

#ifdef COMMON

    keyword_package       = BASE[170];
    all_packages          = BASE[171];
    package_symbol        = BASE[172];
    internal_symbol       = BASE[173];
    external_symbol       = BASE[174];
    inherited_symbol      = BASE[175];
    key_key               = BASE[176];
    allow_other_keys      = BASE[177];
    aux_key               = BASE[178];
    format_symbol         = BASE[179];
    expand_def_symbol     = BASE[180];
    allow_key_key         = BASE[181];
    declare_symbol        = BASE[182];
    special_symbol        = BASE[183];

#endif

    for (i = 0; i<=50; i++)
        workbase[i]  = BASE[work_0_offset+i];
#endif /* NILSEG_EXTERNS */

    user_base_0           = BASE[190];
    user_base_1           = BASE[191];
    user_base_2           = BASE[192];
    user_base_3           = BASE[193];
    user_base_4           = BASE[194];
    user_base_5           = BASE[195];
    user_base_6           = BASE[196];
    user_base_7           = BASE[197];
    user_base_8           = BASE[198];
    user_base_9           = BASE[199];
}


/* end of restart.c */

