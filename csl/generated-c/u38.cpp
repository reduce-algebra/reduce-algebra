
// $destdir/u38.c        Machine generated C code

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS 1
#endif
#endif
#ifdef WIN32
# if defined WIN64 || defined __WIN64__
# define OPSYS "win64"
# define IMPNAME "win64"
# else
# define OPSYS "win32"
# define IMPNAME "win32"
# endif
#else
# ifdef HOST_OS
# define OPSYS HOST_OS
# ifdef HOST_CPU
# define IMPNAME HOST_OS ":" HOST_CPU
# else
# define IMPNAME HOST_OS
# endif
# else
# define OPSYS "Unknown"
# define IMPNAME "Generic"
# endif
#endif
#ifdef HAVE_STDINT_H
#if defined __cplusplus && !defined __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
typedef int CSLbool;
#define YES 1
#define NO 0
#define CSL_IGNORE(x) ((void)(x))
#ifndef PAGE_BITS
# define PAGE_BITS 22
#endif 
#define PAGE_POWER_OF_TWO (((intptr_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO - 256)
#ifndef MAX_HEAPSIZE
# define MAX_HEAPSIZE (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
# define MAX_BPSSIZE 64
#endif 
#define MEGABYTE ((intptr_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES MAX_BPS_PAGES
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK 0xff
typedef intptr_t LispObject;
#define CELL ((intptr_t)sizeof(LispObject))
#define TAG_BITS 7
#define TAG_CONS 0 
#define TAG_FIXNUM 1 
#define TAG_ODDS 2 
#define TAG_SFLOAT 3 
#define TAG_SYMBOL 4 
#define TAG_NUMBERS 5 
#define TAG_VECTOR 6 
#define TAG_BOXFLOAT 7 
#define fixnum_of_int(x) ((LispObject)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x) ((int32_t)(((int32_t)(x)) < 0 ? \
 (((int32_t)(x))>>4) | (-0x10000000) : \
 (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x) ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I 8 
#define GC_BIT_H 8 
#define GC_BIT_P ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w) (((int)(w) & GC_BIT_I) != 0)
extern LispObject address_sign; 
#define is_marked_p(w) (((LispObject)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((LispObject)(w) & ~GC_BIT_P) + \
 address_sign)
#define flip_mark_bit_i(w) ((LispObject)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w) ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w) ((LispObject)(w) ^ GC_BIT_P)
#define is_marked_h(w) (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception() (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
 do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h) ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h) ((LispObject)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((LispObject)(h) & ~GC_BIT_I)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p) (is_cons(p) && (p) != nil)
#define symbolp(p) (is_symbol(p) || (p) == nil)
#else 
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p) ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef uintptr_t Header;
#define header_mask 0x3f0
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL 0x00000010
#define SYM_SPECIAL_VAR 0x00000040 
#define SYM_GLOBAL_VAR 0x00000080 
#define SYM_SPECIAL_FORM 0x00000100 
#define SYM_MACRO 0x00000200 
#define SYM_C_DEF 0x00000400 
#define SYM_CODEPTR 0x00000800 
#define SYM_ANY_GENSYM 0x00001000 
#define SYM_TRACED 0x00002000
#define SYM_FASTGET_MASK 0x000fc000 
#define SYM_FASTGET_SHIFT 14
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00100000 
#define SYM_IN_PACKAGE 0xffe00000 
#define SYM_IN_PKG_SHIFT 23
#define SYM_IN_PKG_COUNT 11
#else 
#define SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM 0x020 
#define TYPE_RATNUM 0x060
#define TYPE_COMPLEX_NUM 0x0a0
#define TYPE_SINGLE_FLOAT 0x120
#define TYPE_DOUBLE_FLOAT 0x160
#define TYPE_LONG_FLOAT 0x1a0
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_VECTOR)))
#define elt(v, n) (*(LispObject *)memory_reference((intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
 (intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
 (intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
 ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
 (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
 do { \
 *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
 *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
 } while (0)
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#define TYPE_BITVEC1 0x030 
#define TYPE_BITVEC2 0x0b0 
#define TYPE_BITVEC3 0x130
#define TYPE_BITVEC4 0x1b0 
#define TYPE_BITVEC5 0x230 
#define TYPE_BITVEC6 0x2b0 
#define TYPE_BITVEC7 0x330 
#define TYPE_BITVEC8 0x3b0 
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#define TYPE_STRING 0x070 
#define TYPE_BPS 0x170 
#define TYPE_SPARE 0x270 
#define TYPE_MAPLEREF TYPE_SPARE 
#define TYPE_FOREIGN TYPE_SPARE 
#define TYPE_SP 0x370 
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#define TYPE_SIMPLE_VEC 0x0f0 
#define TYPE_HASH 0x1f0 
#define TYPE_ARRAY 0x2f0 
#define TYPE_STRUCTURE 0x3f0 
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8 TYPE_BPS
#define TYPE_VEC16 0x220 
#define TYPE_VEC32 0x260 
#define TYPE_MIXED1 0x2a0 
#define TYPE_MIXED2 0x2e0 
#define TYPE_FLOAT32 0x320 
#define TYPE_FLOAT64 0x360 
#define TYPE_MIXED3 0x3a0 
#define TYPE_STREAM 0x3e0 
#define ODDS_MASK 0xff
#define TAG_CHAR 0x02 
#define TAG_BPS 0x42
#define TAG_SPID 0xc2 
#define SPID_NIL (TAG_SPID+0x0000) 
#define SPID_FBIND (TAG_SPID+0x0100) 
#define SPID_CATCH (TAG_SPID+0x0200) 
#define SPID_PROTECT (TAG_SPID+0x0300) 
#define SPID_HASH0 (TAG_SPID+0x0400) 
#define SPID_HASH1 (TAG_SPID+0x0500) 
#define SPID_GCMARK (TAG_SPID+0x0600) 
#define SPID_NOINPUT (TAG_SPID+0x0700) 
#define SPID_ERROR (TAG_SPID+0x0800) 
#define SPID_PVBIND (TAG_SPID+0x0900) 
#define SPID_NOARG (TAG_SPID+0x0a00) 
#define SPID_NOPROP (TAG_SPID+0x0b00) 
#define SPID_LIBRARY (TAG_SPID+0x0c00) 
#define is_header(x) (((int)(x) & 0x30) != 0) 
#define is_char(x) (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x) (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x) (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> 8) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << 29) | \
 (((uint32_t)(code)) << 8) | TAG_CHAR))
#define CHAR_EOF pack_char(0, 0x0010ffff)
#define data_of_bps(v) \
 ((char *)(doubleword_align_up((intptr_t) \
 bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) + \
 (SIXTY_FOUR_BIT ? \
 (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
 PAGE_POWER_OF_TWO) : \
 0) + \
 (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head
{
 Header header; 
 LispObject value; 
 LispObject env; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t functionn; 
 LispObject pname; 
 LispObject plist; 
 LispObject fastgets;
 uintptr_t count; 
#ifdef COMMON
 LispObject package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE 63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
 ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
 (n))
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p) (*(Header *) symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p) (*(LispObject *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p) ((one_args *) *((intptr_t *)symalign((char *)(p) + \
 (3*CELL - TAG_SYMBOL))))
#define qfn2(p) ((two_args *) *((intptr_t *)symalign((char *)(p) + \
 (4*CELL - TAG_SYMBOL))))
#define qfnn(p) ((n_args *) *((intptr_t *)symalign((char *)(p) + \
 (5*CELL - TAG_SYMBOL))))
#define ifn1(p) (*(intptr_t *)symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p) (*(LispObject *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p) (*(Header *) memory_reference((intptr_t) \
 symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p) ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p) ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p) ((n_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p) (*(uintptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
typedef union Float_union
{ float f;
 int32_t i;
} Float_union;
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b) ((uint32_t *)memory_reference((intptr_t)((char *)b + \
 (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b) ((uint32_t *)((char *)b + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n) (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
#define numerator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
#define real_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 16
#define long_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((LispObject)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((LispObject)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((LispObject)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((LispObject)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((LispObject)((intptr_t)(n) & (-16)))
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#if 0 && defined DEBUG
#define SHOW_FNAME (exit_reason == UNWIND_THROW || \
 (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS (exit_reason == UNWIND_THROW || \
 (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#endif
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern "C" LispObject interrupted(LispObject p);
extern "C" LispObject error(int nargs, int code, ...);
extern "C" LispObject cerror(int nargs, int code1, int code2, ...);
extern "C" LispObject too_few_2(LispObject env, LispObject a1);
extern "C" LispObject too_many_1(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_0a(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_0b(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_3a(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_3b(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_na(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_nb(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_1(LispObject env, int nargs, ...);
extern "C" LispObject wrong_no_2(LispObject env, int nargs, ...);
extern "C" LispObject bad_specialn(LispObject env, int nargs, ...);
extern "C" LispObject aerror(const char *s); 
extern "C" LispObject aerror0(const char *s);
extern "C" LispObject aerror1(const char *s, LispObject a);
extern "C" LispObject aerror2(const char *s, LispObject a, LispObject b);
extern "C" void fatal_error(int code, ...);
#define GC_MESSAGES 0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS 0x04
#define GC_MSG_BITS 0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG 0x10
#define ARGS_FLAG 0x20
#define BACKTRACE_MSG_BITS 0x38
#define err_bad_car 0 
#define err_bad_cdr 1 
#define err_no_store 2 
#define err_undefined_function_1 3 
#define err_undefined_function_2 4 
#define err_undefined_function_n 5 
#define err_wrong_no_args 6 
#define err_unbound_lexical 7 
#define err_bad_rplac 8 
#define err_bad_arith 9 
#define err_redef_special 10 
#define err_bad_arg 11 
#define err_bad_declare 12 
#define err_bad_fn 13 
#define err_unset_var 14 
#define err_too_many_args1 15 
#define err_too_many_args2 16 
#define err_bad_apply 17 
#define err_macroex_hook 18 
#define err_block_tag 19 
#define err_go_tag 20 
#define err_excess_args 21
#define err_insufficient_args 22
#define err_bad_bvl 23 
#define err_bad_keyargs 24
#define err_write_err 25
#define err_bad_endp 26 
#define err_no_fasldir 27
#define err_no_fasl 28 
#define err_open_failed 29 
#define err_pipe_failed 30 
#define err_stack_overflow 31
#define err_top_bit 32
#define err_mem_spans_zero 33
#define err_no_longer_used 34 
#define err_no_tempdir 35
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
 "attempt to take cdr of an atom",
 "insufficient freestore to run this package",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function",
 "wrong number of arguments",
 "unbound lexical variable",
 "bad rplaca/rplacd",
 "bad argument for an arithmetic function",
 "attempt to redefine a special form",
 "not a variable",
 "bad use of declare",
 "attempt to apply non-function",
 "unset variable",
 "too many arguments",
 "too many arguments",
 "object not valid as a function (apply,",
 "macroexpand-hook failure",
 "block tag not found",
 "go tag not found",
 "too many arguments provided",
 "not enough arguments provided",
 "bad item in bound variable list",
 "bad keyword arguments",
 "write-error on file",
 "endp used on badly terminated list",
 "environment parameter 'fasldir' not set",
 "loadable module not found for loading",
 "file could not be opened",
 "unable to establish pipe",
 "stack overflow",
 "top bit of address has unexpected value",
 "memory block spans the zero address",
 "this error code available for re-use",
 "unable to find a directory for temporary files",
 "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
 fflush(stderr); \
 } while (0)
#define DS(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
 fflush(stderr); \
 } while (0)
#define DX(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
 (long long unsigned)(s)); \
 fflush(stderr); \
 } while (0)
extern void **pages,
 **heap_pages, **vheap_pages,
 **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
 **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS 0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS 2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{ void *start;
 void *end;
 int type;
} page_map_t;
#endif
extern int32_t pages_count,
 heap_pages_count, vheap_pages_count,
 bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
 new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern LispObject *C_stack;
#define stack C_stack
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif
extern LispObject multiplication_buffer;
#ifdef MEMORY_TRACE
#define push(a) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); } while (0)
#define push2(a,b) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); \
 *++stack = (d); \
 memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); \
 *++stack = (d); \
 memory_reference((intptr_t)stack); \
 *++stack = (e); \
 memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop() (memory_reference((int32_t)stack), (*stack--))
#define pop(a) { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
 memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
 memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n) stack -= (n)
#else 
#define push(a) { *++stack = (a); }
#define push2(a,b) { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack += 3; }
#define push4(a,b,c,d) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) { \
 stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack[6] = (f); \
 stack += 6; }
#define pop(a) { (a) = *stack--; }
#define pop2(a,b) { stack -= 2; (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c) { stack -= 3; (a) = stack[3]; (b) = stack[2]; \
 (c) = stack[1]; }
#define pop4(a,b,c,d) { stack -= 4; (a) = stack[4]; (b) = stack[3]; \
 (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5; (a) = stack[5]; (b) = stack[4]; \
 (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6; \
 (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
 (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n) stack -= (n)
#endif 
#define errexit() { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n) { nil = C_nil; \
 if (exception_pending()) { popv(n); return nil; } }
#define errexitv() { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil; \
 if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
#define GC_PRESERVE 6
#define GC_NATIVE 7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
 if (check_stack("@" __FILE__,__LINE__)) \
 { show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
 { const char *p = (char *)&p; \
 if (p < C_stack_limit) return aerror("stack overflow"); \
 }
#endif
extern int32_t software_ticks, countdown;
#ifdef DEBUG
extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);
#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
 if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
extern volatile int blipflag;
extern int64_t blipcount, startblip;
#if defined __linux__ && defined DEBUG
#define HANDLE_BLIP \
 if (blipflag) \
 { blipflag = 0; \
 if (startblip >= 0 && ++blipcount > startblip) \
 { fprintf(stderr, "Line %d of file %s\n", __LINE__, __FILE__); \
 fflush(stderr); \
 } \
 }
#else
#define HANDLE_BLIP
#endif
#define stackcheck0(k) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { reclaim(nil, "stack", GC_STACK, 0); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck1(k, a1) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { a1 = reclaim(a1, "stack", GC_STACK, 0); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck2(k, a1, a2) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push(a2); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck3(k, a1, a2, a3) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push2(a2, a3); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop2(a3, a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck4(k, a1, a2, a3, a4) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push3(a2, a3, a4); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop3(a4, a3, a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
extern LispObject C_nil;
#define first_nil_offset 50 
#define work_0_offset 200
#define last_nil_offset 251
#define NIL_SEGMENT_SIZE (last_nil_offset*sizeof(LispObject) + 32)
#define SPARE 512
#ifdef COMMON
#define BASE ((LispObject *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((LispObject *)(nil+4)): ((LispObject *)nil))
#endif
extern intptr_t byteflip;
extern LispObject codefringe;
extern LispObject volatile codelimit;
extern LispObject * volatile stacklimit;
extern LispObject fringe;
extern LispObject volatile heaplimit;
extern LispObject volatile vheaplimit;
extern LispObject vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table;
extern LispObject progn_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject cl_symbols, active_stream, current_module;
extern LispObject native_defs, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject native_code, native_symbol, traceprint_symbol;
extern LispObject loadsource_symbol;
extern LispObject hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, count_high;
#ifdef COMMON
extern LispObject keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol;
extern LispObject expand_def_symbol, allow_key_key;
#endif
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern LispObject om_closeConn(LispObject nil, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject nil, LispObject ldev);
extern LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern LispObject om_putAtp(LispObject nil, LispObject ldev);
extern LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_putAttr(LispObject nil, LispObject ldev);
extern LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_putBind(LispObject nil, LispObject ldev);
extern LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern LispObject om_putBVar(LispObject nil, LispObject ldev);
extern LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_putError(LispObject nil, LispObject ldev);
extern LispObject om_putEndError(LispObject nil, LispObject ldev);
extern LispObject om_putObject(LispObject nil, LispObject ldev);
extern LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern LispObject om_getApp(LispObject nil, LispObject ldev);
extern LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern LispObject om_getAtp(LispObject nil, LispObject ldev);
extern LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_getAttr(LispObject nil, LispObject ldev);
extern LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_getBind(LispObject nil, LispObject ldev);
extern LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern LispObject om_getBVar(LispObject nil, LispObject ldev);
extern LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_getError(LispObject nil, LispObject ldev);
extern LispObject om_getEndError(LispObject nil, LispObject ldev);
extern LispObject om_getObject(LispObject nil, LispObject ldev);
extern LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern LispObject om_getInt(LispObject nil, LispObject ldev);
extern LispObject om_getFloat(LispObject nil, LispObject ldev);
extern LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern LispObject om_getVar(LispObject nil, LispObject ldev);
extern LispObject om_getString(LispObject nil, LispObject ldev);
extern LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern LispObject om_getType(LispObject nil, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);
extern LispObject om_read(LispObject nil, LispObject dev);
extern LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject nil, int nargs, ...);
extern LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern LispObject om_whichCDs(LispObject nil, LispObject lsym);
#endif
extern LispObject workbase[51];
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 workbase[0]
#define work_1 workbase[1]
#define mv_1 workbase[1]
#define mv_2 workbase[2]
#define mv_3 workbase[3]
#define work_50 workbase[50]
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list BASE[50] 
#define equal_hash_table_list BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(LispObject v);
extern LispObject eq_hash_tables, equal_hash_tables;
extern LispObject volatile savecodelimit;
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
#ifndef NO_BYTECOUNT
extern const char *name_of_caller;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES 40 
#define MAX_SYMBOLS_TO_DEFINE 40
#define MAX_FASL_PATHS 20
extern const char *files_to_read[MAX_INPUT_FILES],
 *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
 *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern int boffop;
extern void packbyte(int c);
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern int number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths,
 init_flags;
extern int native_code_tag;
extern const char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{ FILE *f; 
 long int o; 
 long int n; 
 uint32_t chk; 
 int status; 
 int nativedir; 
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE 0x1000
typedef struct entry_point1
{ one_args *p;
 const char *s;
} entry_point1;
typedef struct entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct entry_pointn
{ n_args *p;
 const char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject nil, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern int load_dynamic(const char *objname, const char *modname,
 LispObject name, LispObject fns);
extern "C" LispObject Linstate_c_code(LispObject nil,
 LispObject name, LispObject fns);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(const char *s, int len);
#define IOPEN_OUT 0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED 2
extern CSLbool Iopen(const char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(const char *name, int len, char *datestamp, int32_t *size,
 char *expanded_name);
extern CSLbool Icopy(const char *name, int len);
extern CSLbool Idelete(const char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(const void *buff, int32_t size);
extern long int Ioutsize(void);
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(const unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
extern const char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern "C" void sigint_handler(int code);
extern "C" void record_get(LispObject tag, CSLbool found);
extern int primep(int32_t);
extern void adjust_all(void);
extern void set_up_functions(CSLbool restartp);
extern void get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(LispObject code, LispObject lit,
 LispObject *entry_stack);
extern CSLbool complex_stringp(LispObject a);
extern void freshline_trace(void);
extern void freshline_debug(void);
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject Ceval(LispObject u, LispObject env);
extern LispObject noisy_Ceval(LispObject u, LispObject env);
extern uint32_t Crand(void);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern "C" CSLbool eql_fn(LispObject a, LispObject b);
extern "C" CSLbool cl_equal_fn(LispObject a, LispObject b);
extern "C" CSLbool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" CSLbool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs,
 LispObject env, LispObject fname, int noisy);
extern LispObject apply_lambda(LispObject def, int nargs,
 LispObject env, LispObject name, int noisy);
extern void deallocate_pages(void);
extern void drop_heap_segments(void);
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
#ifdef COMMON
extern "C" LispObject get(LispObject a, LispObject b, LispObject c);
#else
extern "C" LispObject get(LispObject a, LispObject b);
#endif
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern LispObject getcodevector(int type, size_t size);
extern uint32_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" CSLbool geq2(LispObject a, LispObject b);
extern "C" CSLbool greaterp2(LispObject a, LispObject b);
extern "C" CSLbool lesseq2(LispObject a, LispObject b);
extern "C" CSLbool lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, int32_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 one_args *f1, two_args *f2, n_args *fn);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern "C" LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern "C" LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern FILE *open_file(char *filename, const char *original_name,
 size_t n, const char *dirn, FILE *old_file);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, int len);
extern void preserve_native_code(void);
extern void relocate_native_function(unsigned char *bps);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t *len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prin_to_error(LispObject u);
extern void loop_print_stdout(LispObject o);
extern void loop_print_terminal(LispObject o);
extern void loop_print_debug(LispObject o);
extern void loop_print_query(LispObject o);
extern void loop_print_trace(LispObject o);
extern void loop_print_error(LispObject o);
extern void internal_prin(LispObject u, int prefix);
extern LispObject princ(LispObject u);
extern LispObject print(LispObject u);
extern LispObject printc(LispObject u);
extern void print_bignum(LispObject u, CSLbool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, CSLbool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(const char *why, int line, const char *file);
extern int check_env(LispObject env);
#endif
extern CSLbool do_not_kill_native_code;
extern void set_fns(LispObject sym, one_args *f1,
 two_args *f2, n_args *fn);
extern void setup(int restartp, double storesize);
extern LispObject simplify_string(LispObject s);
extern CSLbool stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
#ifdef HAVE_INT64_T
extern int64_t sixty_four_bits(LispObject a);
#endif
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r) (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r) (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#define noisy_eval(a, b) noisy_Ceval(a, b)
#define noisy_voideval(a, b) noisy_Ceval(a, b)
#else
#define eval(a, b) \
 (is_cons(a) ? Ceval(a, b) : \
 is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
 onevalue(qvalue(a))) : \
 onevalue(a))
#define voideval(a, b) \
 if (is_cons(a)) Ceval(a, b) 
#define noisy_eval(a, b) \
 (is_cons(a) ? noisy_Ceval(a, b) : \
 is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
 onevalue(qvalue(a))) : \
 onevalue(a))
#define noisy_voideval(a, b) \
 if (is_cons(a)) noisy_Ceval(a, b) 
#endif
#define equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 equal_fn(a, b)))
#define cl_equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 cl_equal_fn(a, b)))
#define eql(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
 uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args *three_arg_functions[];
extern void *useful_functions[];
extern char *address_of_var(int n);
typedef struct setup_type
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
 uint32_t c1;
 uint32_t c2;
} setup_type_1;
extern setup_type const
arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
 arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
 eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
 print_setup[], read_setup[], mpi_setup[];
extern setup_type const
u01_setup[], u02_setup[], u03_setup[], u04_setup[],
 u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
 u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
 u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
 u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
 u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
 u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
 u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
 u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
 u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
 u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
 u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
 u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern const char *find_image_directory(int argc, const char *argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
 LispObject env, int compilerp, int noisy);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject noisy_mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject noisy_progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
extern LispObject noisy_tagbody_fn(LispObject args, LispObject env);
extern LispObject resource_exceeded();
extern int64_t time_base, space_base, io_base, errors_base;
extern int64_t time_now, space_now, io_now, errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(LispObject def, LispObject env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
#define M2_31_1 -2147483649.0 
#define _pi ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr 0
#define boole_and 1
#define boole_andc2 2
#define boole_1 3
#define boole_andc1 4
#define boole_2 5
#define boole_xor 6
#define boole_ior 7
#define boole_nor 8
#define boole_eqv 9
#define boole_c2 10
#define boole_orc2 11
#define boole_c1 12
#define boole_orc1 13
#define boole_nand 14
#define boole_set 15
#define top_bit_set(n) (((int32_t)(n)) < 0)
#define top_bit(n) (((uint32_t)(n)) >> 31)
#define set_top_bit(n) ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n) ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1 
#define Dmultiply(hi, lo, a, b, c) \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) + \
 (uint32_t)(c); \
 (lo) = 0x7fffffffu & (uint32_t)r64; \
 (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE 1
#define Ddivide(r, q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#define Ddivideq(q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); } while (0)
#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)
#define Ddivider(r, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b) ((r) = Idiv10_9(&(q), (a), (b)))
#define Ddivideq(q, a, b, c) (Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9q(q, a, b) (Idiv10_9(&(q), (a), (b)))
#define Ddivider(r, a, b, c) ((r) = Idivide(NULL, (a), (b), (c)))
#define Ddiv10_9r(r, a, b) ((r) = Idiv10_9(NULL, (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, int32_t n);
extern LispObject quotbn1(LispObject a, int32_t n);
extern LispObject quotbb(LispObject a, LispObject b);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, int32_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern CSLbool numeq2(LispObject a, LispObject b);
extern "C" CSLbool zerop(LispObject a);
extern CSLbool onep(LispObject a);
extern CSLbool minusp(LispObject a);
extern CSLbool plusp(LispObject a);
extern CSLbool lesspbd(LispObject a, double b);
extern CSLbool lessprd(LispObject a, double b);
extern CSLbool lesspdb(double a, LispObject b);
extern CSLbool lesspdr(double a, LispObject b);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
 uint32_t a3, int32_t n);
extern LispObject make_lisp_integer32(int32_t n);
extern LispObject make_lisp_integer64(int64_t n);
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(LispObject a, LispObject b);
extern CSLbool lesspib(LispObject a, LispObject b);
typedef struct Complex
{ double real;
 double imag;
} Complex;
extern Complex Cln(Complex a);
extern Complex Ccos(Complex a);
extern Complex Cexp(Complex a);
extern Complex Cpow(Complex a, Complex b);
extern double Cabs(Complex a);
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
#ifdef MACINTOSH
extern sem_t *kara_sem1a, *kara_sem1b, *kara_sem1c,
 *kara_sem2a, *kara_sem2b, *kara_sem2c;
#else
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
 kara_sem2a, kara_sem2b, kara_sem2c;
#endif
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern "C" LispObject Lbatchp(LispObject env, int nargs, ...);
extern "C" LispObject bytecounts(LispObject nil, int nargs, ...);
extern "C" LispObject Ldate(LispObject env, int nargs, ...);
extern "C" LispObject Ldatestamp(LispObject nil, int nargs, ...);
extern "C" LispObject Leject(LispObject env, int nargs, ...);
extern "C" LispObject Lerror(LispObject env, int nargs, ...);
extern "C" LispObject Lerror0(LispObject env, int nargs, ...);
extern "C" LispObject Lflush(LispObject nil, int nargs, ...);
extern "C" LispObject Lgc0(LispObject nil, int nargs, ...);
extern "C" LispObject Lgctime(LispObject env, int nargs, ...);
extern "C" LispObject Lgensym(LispObject env, int nargs, ...);
extern "C" LispObject Llist_modules(LispObject env, int nargs, ...);
extern "C" LispObject Llibrary_members0(LispObject env, int nargs, ...);
extern "C" LispObject Llposn(LispObject env, int nargs, ...);
extern "C" LispObject Lmapstore0(LispObject env, int nargs, ...);
extern "C" LispObject Lnext_random(LispObject env, int nargs, ...);
extern "C" LispObject Lposn(LispObject env, int nargs, ...);
extern "C" LispObject Lread(LispObject env, int nargs, ...);
extern "C" LispObject Lreadch(LispObject env, int nargs, ...);
extern "C" LispObject Lrtell(LispObject nil, int nargs, ...);
extern "C" LispObject Lterpri(LispObject env, int nargs, ...);
extern "C" LispObject Ltime(LispObject env, int nargs, ...);
extern "C" LispObject Ltmpnam(LispObject nil, int nargs, ...);
extern "C" LispObject Ltyi(LispObject env, int nargs, ...);
extern "C" LispObject autoload1(LispObject env, LispObject a1);
extern "C" LispObject bytecoded1(LispObject env, LispObject a);
extern "C" LispObject bytecounts1(LispObject env, LispObject a);
extern "C" LispObject byteopt1(LispObject def, LispObject a);
extern "C" LispObject byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_bytecoded1(LispObject env, LispObject a);
extern "C" LispObject double_byteopt1(LispObject def, LispObject a);
extern "C" LispObject double_byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_funarged1(LispObject env, LispObject a1);
extern "C" LispObject double_hardopt1(LispObject def, LispObject a);
extern "C" LispObject double_hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_interpreted1(LispObject env, LispObject a1);
extern "C" LispObject funarged1(LispObject env, LispObject a1);
extern "C" LispObject tracefunarged1(LispObject env, LispObject a1);
extern "C" LispObject tracesetfunarged1(LispObject env, LispObject a1);
extern "C" LispObject hardopt1(LispObject def, LispObject a);
extern "C" LispObject hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject interpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracesetbytecoded1(LispObject env, LispObject a);
extern "C" LispObject jitcompileme1(LispObject env, LispObject a);
extern "C" LispObject tracebyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracesetbyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracebyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracesetbyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracesetbytecoded1(LispObject env, LispObject a);
extern "C" LispObject traceinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracesetinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracehardopt1(LispObject def, LispObject a);
extern "C" LispObject tracesethardopt1(LispObject def, LispObject a);
extern "C" LispObject tracehardoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracesethardoptrest1(LispObject def, LispObject a);
extern "C" LispObject undefined1(LispObject env, LispObject a1);
extern "C" LispObject f1_as_0(LispObject env, LispObject a);
extern "C" LispObject f1_as_1(LispObject env, LispObject a);
#ifdef CJAVA
extern "C" LispObject java1(LispObject env, LispObject a);
#endif
extern "C" LispObject Labsval(LispObject env, LispObject a);
extern "C" LispObject Ladd1(LispObject env, LispObject a);
extern "C" LispObject Lalpha_char_p(LispObject env, LispObject a);
extern "C" LispObject Lapply0(LispObject env, LispObject a);
extern "C" LispObject Lapply_1(LispObject env, LispObject fn);
extern "C" LispObject Latan(LispObject env, LispObject a);
extern "C" LispObject Latom(LispObject env, LispObject a);
extern "C" LispObject Lbanner(LispObject env, LispObject a);
extern "C" LispObject Lboundp(LispObject env, LispObject a);
extern "C" LispObject Lbpsp(LispObject nil, LispObject a);
extern "C" LispObject Lbpsupbv(LispObject nil, LispObject v);
extern "C" LispObject Lcaaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaadar(LispObject env, LispObject a);
extern "C" LispObject Lcaaddr(LispObject env, LispObject a);
extern "C" LispObject Lcaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcadaar(LispObject env, LispObject a);
extern "C" LispObject Lcadadr(LispObject env, LispObject a);
extern "C" LispObject Lcadar(LispObject env, LispObject a);
extern "C" LispObject Lcaddar(LispObject env, LispObject a);
extern "C" LispObject Lcadddr(LispObject env, LispObject a);
extern "C" LispObject Lcaddr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcdaaar(LispObject env, LispObject a);
extern "C" LispObject Lcdaadr(LispObject env, LispObject a);
extern "C" LispObject Lcdaar(LispObject env, LispObject a);
extern "C" LispObject Lcdadar(LispObject env, LispObject a);
extern "C" LispObject Lcdaddr(LispObject env, LispObject a);
extern "C" LispObject Lcdadr(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcddaar(LispObject env, LispObject a);
extern "C" LispObject Lcddadr(LispObject env, LispObject a);
extern "C" LispObject Lcddar(LispObject env, LispObject a);
extern "C" LispObject Lcdddar(LispObject env, LispObject a);
extern "C" LispObject Lcddddr(LispObject env, LispObject a);
extern "C" LispObject Lcdddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lchar_code(LispObject env, LispObject a);
extern "C" LispObject Lclose(LispObject env, LispObject a);
extern "C" LispObject Lcodep(LispObject env, LispObject a);
extern "C" LispObject Lcompress(LispObject env, LispObject a);
extern "C" LispObject Lconsp(LispObject env, LispObject a);
extern "C" LispObject Lconstantp(LispObject env, LispObject a);
extern "C" LispObject Lcopy_module(LispObject env, LispObject a);
extern "C" LispObject Ldefine_in_module(LispObject env, LispObject a);
extern "C" LispObject Ldelete_module(LispObject env, LispObject a);
extern "C" LispObject Ldigitp(LispObject env, LispObject a);
extern "C" LispObject Lendp(LispObject env, LispObject a);
extern "C" LispObject Lerror1(LispObject nil, LispObject a1);
extern "C" LispObject Lerrorset1(LispObject nil, LispObject form);
extern "C" LispObject Leval(LispObject env, LispObject a);
extern "C" LispObject Levenp(LispObject env, LispObject a);
extern "C" LispObject Levlis(LispObject env, LispObject a);
extern "C" LispObject Lexplode(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lc(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lcn(LispObject nil, LispObject a);
extern "C" LispObject Lexplode2n(LispObject env, LispObject a);
extern "C" LispObject Lexplodec(LispObject env, LispObject a);
extern "C" LispObject Lexplodecn(LispObject env, LispObject a);
extern "C" LispObject Lexplodehex(LispObject nil, LispObject a);
extern "C" LispObject Lexploden(LispObject env, LispObject a);
extern "C" LispObject Lexplodeoctal(LispObject nil, LispObject a);
extern "C" LispObject Lfixp(LispObject env, LispObject a);
extern "C" LispObject Lfloat(LispObject env, LispObject a);
extern "C" LispObject Lfloatp(LispObject env, LispObject a);
extern "C" LispObject Lfrexp(LispObject nil, LispObject a);
extern "C" LispObject Lfuncall1(LispObject env, LispObject fn);
extern "C" LispObject Lgc(LispObject nil, LispObject a);
extern "C" LispObject Lgensym1(LispObject env, LispObject a);
extern "C" LispObject Lgensym2(LispObject env, LispObject a);
extern "C" LispObject Lgetd(LispObject env, LispObject a);
extern "C" LispObject Lgetenv(LispObject env, LispObject a);
extern "C" LispObject Lget_bps(LispObject env, LispObject a);
extern "C" LispObject Lhelp(LispObject nil, LispObject a);
extern "C" LispObject Liadd1(LispObject env, LispObject a);
extern "C" LispObject Lidentity(LispObject env, LispObject a);
extern "C" LispObject Liminus(LispObject env, LispObject a);
extern "C" LispObject Liminusp(LispObject env, LispObject a);
extern "C" LispObject Lindirect(LispObject env, LispObject a);
extern "C" LispObject Lintegerp(LispObject env, LispObject a);
extern "C" LispObject Lintern(LispObject env, LispObject a);
extern "C" LispObject Lionep(LispObject nil, LispObject a);
extern "C" LispObject Lisub1(LispObject env, LispObject a);
extern "C" LispObject Lizerop(LispObject nil, LispObject a);
extern "C" LispObject Llength(LispObject env, LispObject a);
extern "C" LispObject Llengthc(LispObject env, LispObject a);
extern "C" LispObject Llibrary_members(LispObject nil, LispObject a);
extern "C" LispObject Llinelength(LispObject env, LispObject a);
extern "C" LispObject Llist_to_string(LispObject env, LispObject a);
extern "C" LispObject Llist_to_vector(LispObject env, LispObject a);
extern "C" LispObject Lload_module(LispObject env, LispObject a);
extern "C" LispObject Lload_source(LispObject env, LispObject a);
extern "C" LispObject Llognot(LispObject env, LispObject a);
extern "C" LispObject Llog_1(LispObject nil, LispObject a);
extern "C" LispObject Llsd(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern "C" LispObject Lmacro_function(LispObject env, LispObject a);
extern "C" LispObject Lmake_global(LispObject env, LispObject a);
extern "C" LispObject Lmake_special(LispObject env, LispObject a);
extern "C" LispObject Lmapstore(LispObject env, LispObject a);
extern "C" LispObject Lmd5(LispObject env, LispObject a1);
extern "C" LispObject Lmd60(LispObject env, LispObject a1);
extern "C" LispObject Lminus(LispObject env, LispObject a);
extern "C" LispObject Lminusp(LispObject env, LispObject a);
extern "C" LispObject Lmkevect(LispObject nil, LispObject n);
extern "C" LispObject Lmkquote(LispObject env, LispObject a);
extern "C" LispObject Lmkvect(LispObject env, LispObject a);
extern "C" LispObject Lmodular_minus(LispObject env, LispObject a);
extern "C" LispObject Lmodular_number(LispObject env, LispObject a);
extern "C" LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern "C" LispObject Lmodule_exists(LispObject env, LispObject a);
extern "C" LispObject Lmsd(LispObject env, LispObject a);
extern "C" LispObject Lmv_list(LispObject nil, LispObject a);
extern "C" LispObject Lncons(LispObject env, LispObject a);
extern "C" LispObject Lnreverse(LispObject env, LispObject a);
extern "C" LispObject Lnull(LispObject env, LispObject a);
extern "C" LispObject Lnumberp(LispObject env, LispObject a);
extern "C" LispObject Loddp(LispObject env, LispObject a);
extern "C" LispObject Lonep(LispObject env, LispObject a);
extern "C" LispObject Lpagelength(LispObject env, LispObject a);
extern "C" LispObject Lplist(LispObject env, LispObject a);
extern "C" LispObject Lplusp(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin2a(LispObject nil, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprint(LispObject env, LispObject a);
extern "C" LispObject Lprintc(LispObject env, LispObject a);
extern "C" LispObject Lrandom(LispObject env, LispObject a);
extern "C" LispObject Lrational(LispObject env, LispObject a);
extern "C" LispObject Lrdf1(LispObject env, LispObject a);
extern "C" LispObject Lrds(LispObject env, LispObject a);
extern "C" LispObject Lremd(LispObject env, LispObject a);
extern "C" LispObject Lreverse(LispObject env, LispObject a);
extern "C" LispObject Lsetpchar(LispObject env, LispObject a);
extern "C" LispObject Lset_small_modulus(LispObject env, LispObject a);
extern "C" LispObject Lsmkvect(LispObject env, LispObject a);
extern "C" LispObject Lspecial_char(LispObject env, LispObject a);
extern "C" LispObject Lspecial_form_p(LispObject env, LispObject a);
extern "C" LispObject Lspool(LispObject env, LispObject a);
extern "C" LispObject Lstart_module(LispObject env, LispObject a);
extern "C" LispObject Lstop(LispObject env, LispObject a);
extern "C" LispObject Lstringp(LispObject env, LispObject a);
extern "C" LispObject Lsub1(LispObject env, LispObject a);
extern "C" LispObject Lsymbolp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_env(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_function(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_name(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_value(LispObject env, LispObject a);
extern "C" LispObject Lsystem(LispObject env, LispObject a);
extern "C" LispObject Lthreevectorp(LispObject env, LispObject a);
extern "C" LispObject Lthrow_nil(LispObject env, LispObject a);
extern "C" LispObject Ltrace(LispObject env, LispObject a);
extern "C" LispObject Ltraceset(LispObject env, LispObject a);
extern "C" LispObject Ltruncate(LispObject env, LispObject a);
extern "C" LispObject Lttab(LispObject env, LispObject a);
extern "C" LispObject Ltyo(LispObject env, LispObject a);
extern "C" LispObject Lunintern(LispObject env, LispObject a);
extern "C" LispObject Lunmake_global(LispObject env, LispObject a);
extern "C" LispObject Lunmake_special(LispObject env, LispObject a);
extern "C" LispObject Luntrace(LispObject env, LispObject a);
extern "C" LispObject Lupbv(LispObject env, LispObject a);
extern "C" LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern "C" LispObject Lvectorp(LispObject env, LispObject a);
extern "C" LispObject Lverbos(LispObject env, LispObject a);
extern "C" LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern "C" LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern "C" LispObject Lwrite_module(LispObject env, LispObject a);
extern "C" LispObject Lwrs(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lzerop(LispObject env, LispObject a);
#ifdef COMMON
extern "C" LispObject Lfind_symbol_1(LispObject nil, LispObject str);
extern "C" LispObject Llistp(LispObject env, LispObject a);
#endif
extern "C" LispObject autoload2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject double_byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject double_hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracefunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracesetfunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesetbyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesetbyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject tracesetbytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject jitcompileme2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject traceinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracesetinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracehardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesethardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesethardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject undefined2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
#ifdef CJAVA
extern "C" LispObject java2(LispObject env, LispObject a, LispObject b);
#endif
extern "C" LispObject Lappend(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lbpsgetv(LispObject nil, LispObject v, LispObject n);
extern "C" LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcopy_native(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldifference2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldivide(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leql(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqn(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lerror2(LispObject nil, LispObject a1, LispObject a2);
extern "C" LispObject Lerrorset2(LispObject nil, LispObject form, LispObject ffg1);
extern "C" LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfuncall2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lgcd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lhelp_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lidifference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligeq(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Ligreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lileq(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lilessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limax(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limin(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Linorm(LispObject nil, LispObject a, LispObject k);
extern "C" LispObject Linstate_c_code(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lintersect(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Liplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liremainder(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Litimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llcm(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llist2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lmax2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmin2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmod(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lneq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lpair(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrem(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lresource_limit2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrseek(LispObject nil, LispObject a);
extern "C" LispObject Lset(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lset_help_file(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lwrite_help_module(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lxcons(LispObject env, LispObject a, LispObject b);
#ifdef COMMON
extern "C" LispObject Laref2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfloat_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrandom_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
#endif
extern "C" LispObject autoloadn(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject double_bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject double_bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject double_byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject double_byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_funargedn(LispObject env, int nargs, ...);
extern "C" LispObject double_hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject double_hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject funargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracefunargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetfunargedn(LispObject env, int nargs, ...);
extern "C" LispObject hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracebyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracesetbyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracebyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracesetbyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracebytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject jitcompileme0(LispObject env, int nargs, ...);
extern "C" LispObject jitcompileme3(LispObject env, int nargs, ...);
extern "C" LispObject jitcompilemen(LispObject env, int nargs, ...);
extern "C" LispObject traceinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracehardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracesethardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracehardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracesethardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject undefinedn(LispObject env, int nargs, ...);
extern "C" LispObject f0_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_1(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_2(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_3(LispObject env, int nargs, ...);
#ifdef CJAVA
extern "C" LispObject java0(LispObject env, int nargs, ...);
extern "C" LispObject java3(LispObject env, int nargs, ...);
extern "C" LispObject javan(LispObject env, int nargs, ...);
#endif
extern "C" LispObject Lacons(LispObject env, int nargs, ...);
extern "C" LispObject Lapply_n(LispObject env, int nargs, ...);
extern "C" LispObject Lapply2(LispObject env, int nargs, ...);
extern "C" LispObject Lapply3(LispObject env, int nargs, ...);
extern "C" LispObject Lbpsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorset3(LispObject nil, int nargs, ...);
extern "C" LispObject Lerrorsetn(LispObject env, int nargs, ...);
extern "C" LispObject Lfuncalln(LispObject env, int nargs, ...);
extern "C" LispObject Lhelp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llist(LispObject env, int nargs, ...);
extern "C" LispObject Llist2star(LispObject env, int nargs, ...);
extern "C" LispObject Llist3(LispObject env, int nargs, ...);
extern "C" LispObject Llogand(LispObject env, int nargs, ...);
extern "C" LispObject Llogeqv(LispObject env, int nargs, ...);
extern "C" LispObject Llogor(LispObject env, int nargs, ...);
extern "C" LispObject Llogxor(LispObject env, int nargs, ...);
extern "C" LispObject Lmax(LispObject env, int nargs, ...);
extern "C" LispObject Lmin(LispObject env, int nargs, ...);
extern "C" LispObject Lmkhash(LispObject nil, int nargs, ...);
extern "C" LispObject Lput_hash(LispObject env, int nargs, ...);
extern "C" LispObject Lputprop(LispObject env, int nargs, ...);
extern "C" LispObject Lputv(LispObject env, int nargs, ...);
extern "C" LispObject Lresource_limitn(LispObject env, int nargs, ...);
extern "C" LispObject Lsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lsubst(LispObject env, int nargs, ...);
extern "C" LispObject Lvalues(LispObject env, int nargs, ...);
#ifdef COMMON
extern "C" LispObject Lappend_n(LispObject nil, int nargs, ...);
extern "C" LispObject Laref(LispObject env, int nargs, ...);
extern "C" LispObject Laset(LispObject env, int nargs, ...);
extern "C" LispObject Leqn_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lgcd_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgeq_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lget_3(LispObject env, int nargs, ...);
extern "C" LispObject Lgreaterp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llcm_n(LispObject env, int nargs, ...);
extern "C" LispObject Lleq_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llessp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lquotient_n(LispObject nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern "C" LispObject om_openFileDev(LispObject env, int nargs, ...);
extern "C" LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern "C" LispObject om_closeDev(LispObject env, LispObject dev);
extern "C" LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern "C" LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern "C" LispObject om_closeConn(LispObject nil, LispObject lconn);
extern "C" LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern "C" LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern "C" LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern "C" LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern "C" LispObject om_putApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_putBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_putBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_putError(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndError(LispObject nil, LispObject ldev);
extern "C" LispObject om_putObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern "C" LispObject om_getApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_getBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_getBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getError(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndError(LispObject nil, LispObject ldev);
extern "C" LispObject om_getObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_getInt(LispObject nil, LispObject ldev);
extern "C" LispObject om_getFloat(LispObject nil, LispObject ldev);
extern "C" LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern "C" LispObject om_getVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getString(LispObject nil, LispObject ldev);
extern "C" LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern "C" LispObject om_getType(LispObject nil, LispObject ldev);
extern "C" LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern "C" LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);
extern "C" LispObject om_read(LispObject nil, LispObject dev);
extern "C" LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern "C" LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern "C" LispObject om_listCDs(LispObject nil, int nargs, ...);
extern "C" LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern "C" LispObject om_whichCDs(LispObject nil, LispObject lsym);
#endif
#endif 



// Code for !*multf

static LispObject CC_Hmultf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0105, v0106, v0107;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *multf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0105 = stack[-3];
    if (v0105 == nil) goto v0108;
    v0105 = stack[-2];
    v0105 = (v0105 == nil ? lisp_true : nil);
    goto v0109;

v0109:
    if (v0105 == nil) goto v0110;
    v0105 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0105); }

v0110:
    v0106 = stack[-3];
    v0105 = (LispObject)17; // 1
    if (v0106 == v0105) goto v0111;
    v0106 = stack[-2];
    v0105 = (LispObject)17; // 1
    if (v0106 == v0105) goto v0112;
    v0105 = stack[-3];
    if (!consp(v0105)) goto v0113;
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0114;

v0114:
    if (v0105 == nil) goto v0115;
    stack[0] = stack[-3];
    v0105 = stack[-2];
    fn = elt(env, 7); // squashsqrt
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    {
        LispObject v0117 = stack[0];
        popv(6);
        fn = elt(env, 8); // multd
        return (*qfn2(fn))(qenv(fn), v0117, v0105);
    }

v0115:
    v0105 = stack[-2];
    if (!consp(v0105)) goto v0118;
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0119;

v0119:
    if (v0105 == nil) goto v0120;
    stack[0] = stack[-2];
    v0105 = stack[-3];
    fn = elt(env, 7); // squashsqrt
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    {
        LispObject v0121 = stack[0];
        popv(6);
        fn = elt(env, 8); // multd
        return (*qfn2(fn))(qenv(fn), v0121, v0105);
    }

v0120:
    v0105 = qvalue(elt(env, 3)); // !*noncomp
    if (v0105 == nil) goto v0122;
    v0106 = stack[-3];
    v0105 = stack[-2];
    {
        popv(6);
        fn = elt(env, 9); // multf
        return (*qfn2(fn))(qenv(fn), v0106, v0105);
    }

v0122:
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    stack[0] = v0105;
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    stack[-1] = v0105;
    v0106 = stack[0];
    v0105 = stack[-1];
    if (v0106 == v0105) goto v0123;
    v0106 = stack[0];
    v0105 = stack[-1];
    fn = elt(env, 10); // ordop
    v0105 = (*qfn2(fn))(qenv(fn), v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    if (v0105 == nil) goto v0124;
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[0] = v0105;
    v0105 = stack[-3];
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = v0105;
    v0105 = stack[0];
    if (v0105 == nil) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    if (!consp(v0105)) goto v0125;
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0126;

v0126:
    if (v0105 == nil) goto v0127;
    v0105 = qvalue(elt(env, 2)); // nil
    goto v0128;

v0128:
    if (v0105 == nil) goto v0129;
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0106 = qcar(v0105);
    v0105 = (LispObject)17; // 1
    v0105 = cons(v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0106 = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[0];
    v0106 = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0106, v0105);
    }

v0129:
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0107 = qcar(v0105);
    v0106 = stack[0];
    v0105 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); // makeupsf
        return (*qfnn(fn))(qenv(fn), 3, v0107, v0106, v0105);
    }

v0127:
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0106 = qcar(v0105);
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    if (v0106 == v0105) goto v0130;
    v0105 = qvalue(elt(env, 2)); // nil
    goto v0128;

v0130:
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    if (!consp(v0105)) goto v0131;
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0106 = qcar(v0105);
    v0105 = elt(env, 4); // (expt sqrt)
    v0105 = Lmemq(nil, v0106, v0105);
    goto v0128;

v0131:
    v0105 = qvalue(elt(env, 2)); // nil
    goto v0128;

v0125:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0126;

v0124:
    v0106 = stack[-3];
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[0] = v0105;
    v0106 = stack[-3];
    v0105 = stack[-2];
    v0105 = qcdr(v0105);
    v0105 = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = v0105;
    v0105 = stack[0];
    if (v0105 == nil) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    if (!consp(v0105)) goto v0132;
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0133;

v0133:
    if (v0105 == nil) goto v0134;
    v0105 = qvalue(elt(env, 2)); // nil
    goto v0135;

v0135:
    if (v0105 == nil) goto v0136;
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0106 = qcar(v0105);
    v0105 = (LispObject)17; // 1
    v0105 = cons(v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0106 = CC_Hmultf(env, stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0106, v0105);
    }

v0136:
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0107 = qcar(v0105);
    v0106 = stack[0];
    v0105 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); // makeupsf
        return (*qfnn(fn))(qenv(fn), 3, v0107, v0106, v0105);
    }

v0134:
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0106 = qcar(v0105);
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    if (v0106 == v0105) goto v0137;
    v0105 = qvalue(elt(env, 2)); // nil
    goto v0135;

v0137:
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    if (!consp(v0105)) goto v0138;
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0106 = qcar(v0105);
    v0105 = elt(env, 4); // (expt sqrt)
    v0105 = Lmemq(nil, v0106, v0105);
    goto v0135;

v0138:
    v0105 = qvalue(elt(env, 2)); // nil
    goto v0135;

v0132:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0133;

v0123:
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0106 = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[-2];
    v0105 = qcdr(v0105);
    stack[-1] = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[-3];
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    fn = elt(env, 11); // addf
    v0105 = (*qfn2(fn))(qenv(fn), stack[-1], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = v0105;
    v0106 = stack[0];
    v0105 = elt(env, 5); // sqrt
    if (!consp(v0106)) goto v0139;
    v0106 = qcar(v0106);
    if (!(v0106 == v0105)) goto v0139;
    v0105 = stack[-1];
    fn = elt(env, 7); // squashsqrt
    stack[-4] = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = stack[0];
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    stack[0] = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = plus2(v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    fn = elt(env, 13); // !*multfsqrt
    v0105 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    {
        LispObject v0140 = stack[-4];
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0140, v0105);
    }

v0139:
    v0106 = stack[0];
    v0105 = elt(env, 6); // expt
    if (!consp(v0106)) goto v0141;
    v0106 = qcar(v0106);
    if (!(v0106 == v0105)) goto v0141;
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    fn = elt(env, 14); // prefix!-rational!-numberp
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    goto v0142;

v0142:
    if (v0105 == nil) goto v0143;
    v0105 = stack[-1];
    fn = elt(env, 7); // squashsqrt
    stack[-4] = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = stack[0];
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    stack[0] = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = plus2(v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    fn = elt(env, 15); // !*multfexpt
    v0105 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    {
        LispObject v0144 = stack[-4];
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0144, v0105);
    }

v0143:
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = plus2(v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    fn = elt(env, 16); // mkspm
    v0105 = (*qfn2(fn))(qenv(fn), stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[0] = v0105;
    v0105 = stack[0];
    if (v0105 == nil) goto v0145;
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    v0106 = qcdr(v0105);
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = CC_Hmultf(env, v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-3] = v0105;
    v0105 = (v0105 == nil ? lisp_true : nil);
    goto v0146;

v0146:
    if (!(v0105 == nil)) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0106 = stack[0];
    v0105 = (LispObject)17; // 1
    v0105 = cons(v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0106 = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[-3];
    fn = elt(env, 9); // multf
    v0106 = (*qfn2(fn))(qenv(fn), v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0105 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0106, v0105);
    }

v0145:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0146;

v0141:
    v0105 = qvalue(elt(env, 2)); // nil
    goto v0142;

v0118:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0119;

v0113:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0114;

v0112:
    v0105 = stack[-3];
    {
        popv(6);
        fn = elt(env, 7); // squashsqrt
        return (*qfn1(fn))(qenv(fn), v0105);
    }

v0111:
    v0105 = stack[-2];
    {
        popv(6);
        fn = elt(env, 7); // squashsqrt
        return (*qfn1(fn))(qenv(fn), v0105);
    }

v0108:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0109;
// error exit handlers
v0116:
    popv(6);
    return nil;
}



// Code for createsinglevariablemonom

static LispObject CC_createsinglevariablemonom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0152, v0153, v0154;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for createsinglevariablemonom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0000;
// end of prologue
    v0152 = (LispObject)17; // 1
    v0152 = Lmkvect(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-4];
    stack[-3] = v0152;
    v0154 = stack[-3];
    v0153 = (LispObject)1; // 0
    v0152 = (LispObject)17; // 1
    *(LispObject *)((char *)v0154 + (CELL-TAG_VECTOR) + ((int32_t)v0153/(16/CELL))) = v0152;
    stack[-1] = stack[-3];
    stack[0] = (LispObject)17; // 1
    v0154 = stack[-2];
    v0153 = qvalue(elt(env, 1)); // nil
    v0152 = qvalue(elt(env, 1)); // nil
    v0152 = list2star(v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0152;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }
// error exit handlers
v0155:
    popv(5);
    return nil;
}



// Code for fctlength

static LispObject CC_fctlength(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0156;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fctlength");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0156 = v0000;
// end of prologue
    fn = elt(env, 1); // fctargs
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    errexit();
        return Llength(nil, v0156);
}



// Code for pasf_smordtable

static LispObject CC_pasf_smordtable(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0099, v0114;
    LispObject fn;
    LispObject v0009, v0147, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pasf_smordtable");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smordtable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0147,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0147,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0009;
    stack[-1] = v0147;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0114 = stack[-1];
    v0099 = stack[0];
    v0099 = (LispObject)lessp2(v0114, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    v0099 = v0099 ? lisp_true : nil;
    env = stack[-4];
    if (v0099 == nil) goto v0161;
    v0114 = stack[-3];
    v0099 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); // pasf_smordtable2
        return (*qfn2(fn))(qenv(fn), v0114, v0099);
    }

v0161:
    v0114 = stack[-1];
    v0099 = stack[0];
    v0099 = (LispObject)greaterp2(v0114, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    v0099 = v0099 ? lisp_true : nil;
    env = stack[-4];
    if (v0099 == nil) goto v0101;
    v0114 = stack[-3];
    v0099 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // pasf_smordtable1
        return (*qfn2(fn))(qenv(fn), v0114, v0099);
    }

v0101:
    v0099 = elt(env, 1); // "abused smordtable"
    v0099 = ncons(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(qenv(fn), v0099);
    }
// error exit handlers
v0160:
    popv(5);
    return nil;
}



// Code for lowupperlimitrd

static LispObject CC_lowupperlimitrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0157, v0100;
    LispObject fn;
    argcheck(nargs, 0, "lowupperlimitrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lowupperlimitrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// end of prologue
    stack[-2] = nil;
    fn = elt(env, 5); // mathml
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    stack[0] = v0157;
    fn = elt(env, 6); // lex
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    v0100 = qvalue(elt(env, 1)); // char
    v0157 = elt(env, 2); // (!/ l o w l i m i t)
    if (equal(v0100, v0157)) goto v0166;
    v0100 = elt(env, 3); // "</lowlimit>"
    v0157 = (LispObject)33; // 2
    fn = elt(env, 7); // errorml
    v0157 = (*qfn2(fn))(qenv(fn), v0100, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    goto v0167;

v0167:
    stack[-1] = elt(env, 4); // lowupperlimit
    v0157 = stack[-2];
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    {
        LispObject v0115 = stack[-1];
        LispObject v0099 = stack[0];
        popv(4);
        return list2star(v0115, v0099, v0157);
    }

v0166:
    fn = elt(env, 8); // upperlimitrd
    v0157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    stack[-2] = v0157;
    goto v0167;
// error exit handlers
v0165:
    popv(4);
    return nil;
}



// Code for ldf!-simp

static LispObject CC_ldfKsimp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0096, v0119;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldf-simp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0119 = v0000;
// end of prologue
    v0096 = v0119;
    if (v0096 == nil) goto v0004;
    v0096 = v0119;
    v0096 = qcdr(v0096);
    if (v0096 == nil) goto v0171;
    v0096 = v0119;
    fn = elt(env, 3); // prepf
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    fn = elt(env, 4); // simp
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0096 = qcar(v0096);
    v0119 = v0096;
    v0096 = v0119;
    if (!consp(v0096)) goto v0114;
    v0096 = v0119;
    v0096 = qcar(v0096);
    v0096 = (consp(v0096) ? nil : lisp_true);
    goto v0099;

v0099:
    if (!(v0096 == nil)) goto v0173;
    stack[0] = v0119;
    v0096 = v0119;
    fn = elt(env, 5); // comfac
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0096 = qcdr(v0096);
    fn = elt(env, 6); // quotf
    v0096 = (*qfn2(fn))(qenv(fn), stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0119 = v0096;
    goto v0173;

v0173:
    v0096 = v0119;
    {
        popv(2);
        fn = elt(env, 7); // absf
        return (*qfn1(fn))(qenv(fn), v0096);
    }

v0114:
    v0096 = qvalue(elt(env, 2)); // t
    goto v0099;

v0171:
    v0096 = v0119;
    v0096 = qcar(v0096);
    v0096 = qcar(v0096);
    v0119 = qcar(v0096);
    v0096 = (LispObject)17; // 1
    fn = elt(env, 8); // to
    v0119 = (*qfn2(fn))(qenv(fn), v0119, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0096 = (LispObject)17; // 1
    v0096 = cons(v0119, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    fn = elt(env, 3); // prepf
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    fn = elt(env, 4); // simp
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    v0096 = qcar(v0096);
    { popv(2); return onevalue(v0096); }

v0004:
    v0096 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0096); }
// error exit handlers
v0172:
    popv(2);
    return nil;
}



// Code for simpimpart

static LispObject CC_simpimpart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0174, v0166;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpimpart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0166 = v0000;
// end of prologue
    v0174 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 2)); // !*factor
    qvalue(elt(env, 2)) = v0174; // !*factor
    v0174 = v0166;
    v0174 = qcar(v0174);
    fn = elt(env, 3); // simp!*
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-1];
    fn = elt(env, 4); // impartsq
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*factor
    { popv(2); return onevalue(v0174); }
// error exit handlers
v0175:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*factor
    popv(2);
    return nil;
}



// Code for suspend

static LispObject CC_suspend(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0182, v0183, v0184, v0185;
    LispObject fn;
    LispObject v0178, v0181, v0156, v0004, v0009;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "suspend");
    va_start(aa, nargs);
    v0009 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0156 = va_arg(aa, LispObject);
    v0181 = va_arg(aa, LispObject);
    v0178 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for suspend");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0178,v0181,v0156,v0004,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0009,v0004,v0156,v0181,v0178);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0178;
    v0183 = v0181;
    v0184 = v0156;
    v0185 = v0004;
    v0182 = v0009;
// end of prologue
    stack[-8] = qvalue(elt(env, 1)); // op
    qvalue(elt(env, 1)) = nil; // op
    stack[-6] = qvalue(elt(env, 2)); // r
    qvalue(elt(env, 2)) = nil; // r
    stack[-5] = qvalue(elt(env, 3)); // p
    qvalue(elt(env, 3)) = nil; // p
    qvalue(elt(env, 1)) = v0182; // op
    v0182 = v0185;
    qvalue(elt(env, 2)) = v0182; // r
    v0182 = v0184;
    qvalue(elt(env, 3)) = v0182; // p
    v0182 = qvalue(elt(env, 2)); // r
    stack[-4] = qcar(v0182);
    v0182 = qvalue(elt(env, 3)); // p
    stack[-3] = qcar(v0182);
    stack[-2] = v0183;
    stack[-1] = qvalue(elt(env, 1)); // op
    v0182 = qvalue(elt(env, 2)); // r
    stack[0] = qcdr(v0182);
    v0183 = qvalue(elt(env, 1)); // op
    v0182 = qvalue(elt(env, 3)); // p
    v0182 = qcdr(v0182);
    v0182 = cons(v0183, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-9];
    v0182 = ncons(v0182);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-9];
    v0183 = acons(stack[-1], stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-9];
    v0182 = stack[-7];
    v0182 = cons(v0183, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-9];
    fn = elt(env, 4); // amatch
    v0182 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-3], stack[-2], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; // p
    qvalue(elt(env, 2)) = stack[-6]; // r
    qvalue(elt(env, 1)) = stack[-8]; // op
    { popv(10); return onevalue(v0182); }
// error exit handlers
v0172:
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; // p
    qvalue(elt(env, 2)) = stack[-6]; // r
    qvalue(elt(env, 1)) = stack[-8]; // op
    popv(10);
    return nil;
}



// Code for vdpmember

static LispObject CC_vdpmember(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0161, v0187;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpmember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue

v0156:
    v0161 = stack[0];
    if (v0161 == nil) goto v0174;
    v0187 = stack[-1];
    v0161 = stack[0];
    v0161 = qcar(v0161);
    fn = elt(env, 2); // vdpequal
    v0161 = (*qfn2(fn))(qenv(fn), v0187, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    if (!(v0161 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    stack[0] = v0161;
    goto v0156;

v0174:
    v0161 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0161); }
// error exit handlers
v0103:
    popv(3);
    return nil;
}



// Code for evinsert

static LispObject CC_evinsert(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0098, v0169, v0188;
    LispObject fn;
    LispObject v0009, v0147, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "evinsert");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evinsert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0147,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0147,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0009;
    stack[-1] = v0147;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0188 = nil;
    goto v0174;

v0174:
    v0098 = stack[-3];
    if (v0098 == nil) goto v0108;
    v0098 = stack[0];
    v0098 = (v0098 == nil ? lisp_true : nil);
    goto v0109;

v0109:
    if (v0098 == nil) goto v0163;
    v0098 = v0188;
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0098);
    }

v0163:
    v0098 = stack[0];
    v0169 = qcar(v0098);
    v0098 = stack[-2];
    if (equal(v0169, v0098)) goto v0149;
    v0098 = stack[-3];
    v0098 = qcar(v0098);
    v0169 = v0188;
    v0098 = cons(v0098, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    v0188 = v0098;
    v0098 = stack[-3];
    v0098 = qcdr(v0098);
    stack[-3] = v0098;
    v0098 = stack[0];
    v0098 = qcdr(v0098);
    stack[0] = v0098;
    goto v0174;

v0149:
    stack[0] = v0188;
    v0169 = stack[-1];
    v0098 = stack[-3];
    v0098 = qcdr(v0098);
    v0098 = cons(v0169, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    {
        LispObject v0189 = stack[0];
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0189, v0098);
    }

v0108:
    v0098 = qvalue(elt(env, 1)); // t
    goto v0109;
// error exit handlers
v0172:
    popv(5);
    return nil;
}



// Code for simpwedge

static LispObject CC_simpwedge(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0156;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpwedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0156 = v0000;
// end of prologue
    fn = elt(env, 1); // partitwedge
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(qenv(fn), v0156);
    }
// error exit handlers
v0181:
    popv(1);
    return nil;
}



// Code for s_noparents

static LispObject CC_s_noparents(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0158, v0150;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s_noparents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    stack[-1] = nil;
    goto v0156;

v0156:
    v0158 = stack[0];
    if (v0158 == nil) goto v0174;
    v0158 = stack[0];
    v0158 = qcar(v0158);
    fn = elt(env, 1); // has_parents
    v0158 = (*qfn1(fn))(qenv(fn), v0158);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    if (v0158 == nil) goto v0159;
    v0158 = stack[0];
    v0158 = qcdr(v0158);
    stack[0] = v0158;
    goto v0156;

v0159:
    v0158 = stack[0];
    v0150 = qcar(v0158);
    v0158 = stack[-1];
    v0158 = cons(v0150, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    stack[-1] = v0158;
    v0158 = stack[0];
    v0158 = qcdr(v0158);
    stack[0] = v0158;
    goto v0156;

v0174:
    v0158 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0158);
    }
// error exit handlers
v0162:
    popv(3);
    return nil;
}



// Code for pst_subpst

static LispObject CC_pst_subpst(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0104, v0109;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_subpst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0109 = v0001;
    v0104 = v0000;
// end of prologue
    stack[0] = qcdr(v0104);
    v0104 = v0109;
    v0104 = sub1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    v0104 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0104/(16/CELL)));
    { popv(1); return onevalue(v0104); }
// error exit handlers
v0151:
    popv(1);
    return nil;
}



// Code for lpos

static LispObject CC_lpos(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0161, v0187, v0167, v0102;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lpos");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0167 = v0001;
    v0102 = v0000;
// end of prologue
    v0187 = v0102;
    v0161 = v0167;
    v0161 = qcar(v0161);
    if (v0187 == v0161) goto v0156;
    v0161 = v0102;
    v0187 = v0167;
    v0187 = qcdr(v0187);
    v0161 = CC_lpos(env, v0161, v0187);
    errexit();
    return add1(v0161);

v0156:
    v0161 = (LispObject)17; // 1
    return onevalue(v0161);
}



// Code for get!-current!-representation

static LispObject CC_getKcurrentKrepresentation(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0122, v0175;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-current-representation");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0122 = v0000;
// end of prologue
    v0175 = elt(env, 1); // currep
    return get(v0122, v0175);
}



// Code for read!-comment1

static LispObject CC_readKcomment1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0190, v0191;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for read-comment1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0190 = v0000;
// end of prologue
    stack[-1] = qvalue(elt(env, 1)); // !*lower
    qvalue(elt(env, 1)) = nil; // !*lower
    stack[0] = qvalue(elt(env, 2)); // !*raise
    qvalue(elt(env, 2)) = nil; // !*raise
    v0190 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0190; // named!-character!*
    goto v0181;

v0181:
    v0190 = qvalue(elt(env, 4)); // named!-character!*
    if (!(v0190 == nil)) goto v0122;
    v0190 = qvalue(elt(env, 5)); // crchar!*
    fn = elt(env, 9); // id2string
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    fn = elt(env, 10); // string!-length
    v0191 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    v0190 = (LispObject)17; // 1
    if (v0191 == v0190) goto v0187;
    v0190 = qvalue(elt(env, 6)); // t
    goto v0151;

v0151:
    if (!(v0190 == nil)) goto v0122;
    v0190 = elt(env, 8); // ! 
    qvalue(elt(env, 5)) = v0190; // crchar!*
    fn = elt(env, 11); // condterpri
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    v0190 = nil;
    qvalue(elt(env, 2)) = stack[0]; // !*raise
    qvalue(elt(env, 1)) = stack[-1]; // !*lower
    { popv(3); return onevalue(v0190); }

v0122:
    v0190 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0190; // named!-character!*
    fn = elt(env, 12); // readch1
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0190; // crchar!*
    goto v0181;

v0187:
    v0190 = qvalue(elt(env, 5)); // crchar!*
    fn = elt(env, 13); // delcp
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    if (v0190 == nil) goto v0158;
    v0191 = qvalue(elt(env, 5)); // crchar!*
    v0190 = qvalue(elt(env, 7)); // !$eol!$
    v0190 = (v0191 == v0190 ? lisp_true : nil);
    goto v0151;

v0158:
    v0190 = qvalue(elt(env, 6)); // t
    goto v0151;
// error exit handlers
v0179:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[0]; // !*raise
    qvalue(elt(env, 1)) = stack[-1]; // !*lower
    popv(3);
    return nil;
}



// Code for component_action

static LispObject CC_component_action(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0189, v0193, v0194;
    LispObject fn;
    LispObject v0147, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "component_action");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for component_action");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0147,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0147;
    stack[-3] = v0001;
    stack[0] = v0000;
// end of prologue
    v0193 = qvalue(elt(env, 1)); // nil
    v0189 = (LispObject)17; // 1
    v0189 = cons(v0193, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    stack[-4] = v0189;
    v0189 = stack[0];
    v0189 = qcdr(v0189);
    stack[-1] = v0189;
    goto v0196;

v0196:
    v0189 = stack[-1];
    if (v0189 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    stack[0] = v0189;
    v0189 = stack[0];
    v0193 = qcar(v0189);
    v0189 = stack[-3];
    fn = elt(env, 2); // ext_mult
    v0193 = (*qfn2(fn))(qenv(fn), v0193, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0189 = stack[0];
    v0189 = qcdr(v0189);
    v0194 = v0193;
    v0193 = v0189;
    v0189 = v0194;
    v0189 = qcar(v0189);
    if (v0189 == nil) goto v0173;
    stack[0] = stack[-4];
    v0189 = v0194;
    fn = elt(env, 3); // multsq
    v0193 = (*qfn2(fn))(qenv(fn), v0189, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0189 = stack[-2];
    fn = elt(env, 3); // multsq
    v0189 = (*qfn2(fn))(qenv(fn), v0193, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    fn = elt(env, 4); // addsq
    v0189 = (*qfn2(fn))(qenv(fn), stack[0], v0189);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    stack[-4] = v0189;
    goto v0173;

v0173:
    v0189 = stack[-1];
    v0189 = qcdr(v0189);
    stack[-1] = v0189;
    goto v0196;
// error exit handlers
v0195:
    popv(6);
    return nil;
}



// Code for drop_rl_with

static LispObject CC_drop_rl_with(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0161, v0187, v0167;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for drop_rl_with");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0161 = v0001;
    v0187 = v0000;
// end of prologue
    stack[-1] = v0161;
    stack[0] = elt(env, 1); // rl_with
    v0167 = v0187;
    v0187 = v0161;
    v0161 = elt(env, 1); // rl_with
    v0161 = get(v0187, v0161);
    env = stack[-2];
    v0161 = Ldelete(nil, v0167, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    {
        LispObject v0150 = stack[-1];
        LispObject v0112 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v0150, v0112, v0161);
    }
// error exit handlers
v0158:
    popv(3);
    return nil;
}



// Code for giintgcd

static LispObject CC_giintgcd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0198, v0199, v0200, v0201;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for giintgcd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0199 = v0001;
    v0200 = v0000;
// end of prologue

v0175:
    v0201 = v0199;
    v0198 = (LispObject)17; // 1
    if (v0201 == v0198) goto v0166;
    v0198 = v0200;
    if (v0198 == nil) { popv(2); return onevalue(v0199); }
    v0198 = v0200;
    if (!consp(v0198)) goto v0163;
    v0201 = v0200;
    v0198 = elt(env, 1); // !:gi!:
    if (!consp(v0201)) goto v0185;
    v0201 = qcar(v0201);
    if (!(v0201 == v0198)) goto v0185;
    v0198 = v0200;
    v0198 = qcdr(v0198);
    stack[0] = qcar(v0198);
    v0198 = v0200;
    v0198 = qcdr(v0198);
    v0198 = qcdr(v0198);
    v0198 = Lgcd(nil, v0198, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    {
        LispObject v0203 = stack[0];
        popv(2);
        return Lgcd(nil, v0203, v0198);
    }

v0185:
    v0198 = v0200;
    v0198 = qcar(v0198);
    v0198 = qcdr(v0198);
    stack[0] = v0198;
    v0198 = v0200;
    v0198 = qcdr(v0198);
    v0198 = CC_giintgcd(env, v0198, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-1];
    v0199 = v0198;
    v0198 = stack[0];
    v0200 = v0198;
    goto v0175;

v0163:
    v0198 = v0200;
        popv(2);
        return Lgcd(nil, v0198, v0199);

v0166:
    v0198 = (LispObject)17; // 1
    { popv(2); return onevalue(v0198); }
// error exit handlers
v0202:
    popv(2);
    return nil;
}



// Code for orddf

static LispObject CC_orddf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0177, v0182;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for orddf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue

v0156:
    v0177 = stack[-1];
    if (v0177 == nil) goto v0174;
    v0177 = stack[0];
    if (v0177 == nil) goto v0171;
    v0177 = stack[-1];
    v0182 = qcar(v0177);
    v0177 = stack[0];
    v0177 = qcar(v0177);
    fn = elt(env, 6); // exptcompare
    v0177 = (*qfn2(fn))(qenv(fn), v0182, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    if (v0177 == nil) goto v0101;
    v0177 = qvalue(elt(env, 4)); // t
    { popv(3); return onevalue(v0177); }

v0101:
    v0177 = stack[0];
    v0182 = qcar(v0177);
    v0177 = stack[-1];
    v0177 = qcar(v0177);
    fn = elt(env, 6); // exptcompare
    v0177 = (*qfn2(fn))(qenv(fn), v0182, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    if (v0177 == nil) goto v0191;
    v0177 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0177); }

v0191:
    v0177 = stack[-1];
    v0177 = qcdr(v0177);
    stack[-1] = v0177;
    v0177 = stack[0];
    v0177 = qcdr(v0177);
    stack[0] = v0177;
    goto v0156;

v0171:
    v0177 = elt(env, 3); // "Orddf u longer than v"
    {
        popv(3);
        fn = elt(env, 7); // interr
        return (*qfn1(fn))(qenv(fn), v0177);
    }

v0174:
    v0177 = stack[0];
    if (v0177 == nil) goto v0104;
    v0177 = elt(env, 2); // "Orddf v longer than u"
    {
        popv(3);
        fn = elt(env, 7); // interr
        return (*qfn1(fn))(qenv(fn), v0177);
    }

v0104:
    v0177 = elt(env, 1); // "Orddf = case"
    {
        popv(3);
        fn = elt(env, 7); // interr
        return (*qfn1(fn))(qenv(fn), v0177);
    }
// error exit handlers
v0185:
    popv(3);
    return nil;
}



// Code for mri_2ofsfat

static LispObject CC_mri_2ofsfat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0151;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_2ofsfat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0108 = stack[0];
    fn = elt(env, 2); // mri_op
    stack[-1] = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0108 = stack[0];
    fn = elt(env, 3); // mri_arg2l
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0151 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0186 = stack[-1];
        popv(3);
        return list3(v0186, v0108, v0151);
    }
// error exit handlers
v0197:
    popv(3);
    return nil;
}



// Code for sfto_qsubhor1

static LispObject CC_sfto_qsubhor1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0092, v0093;
    LispObject fn;
    LispObject v0147, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sfto_qsubhor1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_qsubhor1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0147,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0147;
    v0092 = v0001;
    stack[0] = v0000;
// end of prologue
    v0093 = stack[0];
    fn = elt(env, 2); // sfto_mvartest
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-6];
    if (v0092 == nil) goto v0163;
    v0092 = stack[-1];
    v0092 = qcar(v0092);
    stack[-4] = v0092;
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    stack[-3] = v0092;
    v0092 = (LispObject)17; // 1
    stack[-2] = v0092;
    v0092 = stack[0];
    fn = elt(env, 3); // coeffs
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-6];
    v0093 = v0092;
    v0092 = v0093;
    v0092 = qcar(v0092);
    stack[-5] = v0092;
    v0092 = v0093;
    v0092 = qcdr(v0092);
    stack[-1] = v0092;
    goto v0165;

v0165:
    v0092 = stack[-1];
    if (v0092 == nil) goto v0210;
    v0092 = stack[-1];
    v0092 = qcar(v0092);
    stack[0] = v0092;
    v0093 = stack[-2];
    v0092 = stack[-3];
    v0092 = times2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-6];
    stack[-2] = v0092;
    v0093 = stack[0];
    v0092 = stack[-2];
    fn = elt(env, 4); // multf
    stack[0] = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-6];
    v0093 = stack[-5];
    v0092 = stack[-4];
    fn = elt(env, 4); // multf
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-6];
    fn = elt(env, 5); // addf
    v0092 = (*qfn2(fn))(qenv(fn), stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-6];
    stack[-5] = v0092;
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    stack[-1] = v0092;
    goto v0165;

v0210:
    v0092 = stack[-5];
    fn = elt(env, 6); // sfto_dprpartksf
    v0093 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    v0092 = (LispObject)17; // 1
    popv(7);
    return cons(v0093, v0092);

v0163:
    v0093 = stack[0];
    v0092 = (LispObject)17; // 1
    popv(7);
    return cons(v0093, v0092);
// error exit handlers
v0209:
    popv(7);
    return nil;
}



// Code for rl_multsurep

static LispObject CC_rl_multsurep(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0196, v0197;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_multsurep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0196 = v0001;
    v0197 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_multsurep!*
    v0196 = list2(v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-1];
    {
        LispObject v0171 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0171, v0196);
    }
// error exit handlers
v0170:
    popv(2);
    return nil;
}



// Code for matrixrd

static LispObject CC_matrixrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0207, v0094;
    LispObject fn;
    argcheck(nargs, 0, "matrixrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// end of prologue
    v0207 = (LispObject)1; // 0
    stack[-1] = v0207;
    v0207 = nil;
    stack[0] = v0207;
    goto v0151;

v0151:
    v0094 = stack[-1];
    v0207 = (LispObject)1; // 0
    if (v0094 == v0207) goto v0104;
    v0094 = elt(env, 6); // mat
    v0207 = stack[0];
    v0207 = cons(v0094, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); // aeval
        return (*qfn1(fn))(qenv(fn), v0207);
    }

v0104:
    fn = elt(env, 8); // lex
    v0207 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0094 = qvalue(elt(env, 2)); // char
    v0207 = elt(env, 3); // (m a t r i x r o w)
    if (equal(v0094, v0207)) goto v0163;
    v0207 = (LispObject)17; // 1
    stack[-1] = v0207;
    goto v0151;

v0163:
    fn = elt(env, 9); // matrixrowrd
    v0207 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0094 = v0207;
    v0207 = stack[0];
    if (v0207 == nil) goto v0204;
    v0207 = v0094;
    v0207 = ncons(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0207 = Lappend(nil, stack[0], v0207);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    stack[0] = v0207;
    goto v0177;

v0177:
    v0094 = qvalue(elt(env, 2)); // char
    v0207 = elt(env, 4); // (!/ m a t r i x r o w)
    if (equal(v0094, v0207)) goto v0151;
    v0094 = elt(env, 5); // "</matrixrow>"
    v0207 = (LispObject)33; // 2
    fn = elt(env, 10); // errorml
    v0207 = (*qfn2(fn))(qenv(fn), v0094, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    goto v0151;

v0204:
    v0207 = v0094;
    v0207 = ncons(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    stack[0] = v0207;
    goto v0177;
// error exit handlers
v0212:
    popv(3);
    return nil;
}



// Code for compl

static LispObject CC_compl(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0154, v0157, v0100;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0100 = nil;
    goto v0181;

v0181:
    v0154 = stack[-1];
    if (v0154 == nil) goto v0166;
    v0154 = stack[-1];
    v0157 = qcar(v0154);
    v0154 = stack[0];
    v0154 = Lmember(nil, v0157, v0154);
    if (v0154 == nil) goto v0167;
    v0154 = stack[-1];
    v0154 = qcdr(v0154);
    stack[-1] = v0154;
    goto v0181;

v0167:
    v0154 = stack[-1];
    v0154 = qcar(v0154);
    v0157 = v0100;
    v0154 = cons(v0154, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-2];
    v0100 = v0154;
    v0154 = stack[-1];
    v0154 = qcdr(v0154);
    stack[-1] = v0154;
    goto v0181;

v0166:
    v0154 = v0100;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0154);
    }
// error exit handlers
v0155:
    popv(3);
    return nil;
}



// Code for assgnpri

static LispObject CC_assgnpri(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0229, v0230, v0231;
    LispObject fn;
    LispObject v0147, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assgnpri");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assgnpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0147,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0147;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0229 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 2)) = v0229; // overflowed!*
    qvalue(elt(env, 3)) = v0229; // testing!-width!*
    v0229 = stack[-3];
    if (!(v0229 == nil)) goto v0122;
    v0229 = (LispObject)1; // 0
    stack[-3] = v0229;
    goto v0122;

v0122:
    v0229 = qvalue(elt(env, 4)); // !*nero
    if (v0229 == nil) goto v0151;
    v0230 = stack[-3];
    v0229 = (LispObject)1; // 0
    if (!(v0230 == v0229)) goto v0151;
    v0229 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0229); }

v0151:
    v0229 = qvalue(elt(env, 5)); // !*tex
    if (v0229 == nil) goto v0158;
    v0231 = stack[-3];
    v0230 = stack[-2];
    v0229 = stack[-1];
    {
        popv(6);
        fn = elt(env, 22); // texpri
        return (*qfnn(fn))(qenv(fn), 3, v0231, v0230, v0229);
    }

v0158:
    v0229 = elt(env, 6); // vecp
    fn = elt(env, 23); // getd
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    if (v0229 == nil) goto v0169;
    v0229 = stack[-3];
    fn = elt(env, 6); // vecp
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    if (v0229 == nil) goto v0169;
    v0230 = stack[-3];
    v0229 = elt(env, 7); // mat
    {
        popv(6);
        fn = elt(env, 24); // vecpri
        return (*qfn2(fn))(qenv(fn), v0230, v0229);
    }

v0169:
    v0230 = elt(env, 8); // csl
    v0229 = qvalue(elt(env, 9)); // lispsystem!*
    v0229 = Lmemq(nil, v0230, v0229);
    if (v0229 == nil) goto v0185;
    v0229 = elt(env, 10); // math!-display
    fn = elt(env, 23); // getd
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    if (v0229 == nil) goto v0185;
    v0229 = (LispObject)1; // 0
    fn = elt(env, 10); // math!-display
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    if (v0229 == nil) goto v0185;
    v0230 = qvalue(elt(env, 11)); // outputhandler!*
    v0229 = elt(env, 12); // fancy!-output
    if (v0230 == v0229) goto v0207;
    v0229 = qvalue(elt(env, 1)); // nil
    goto v0211;

v0211:
    if (v0229 == nil) goto v0185;
    v0229 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 25); // fmp!-switch
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0229 = qvalue(elt(env, 13)); // t
    stack[-4] = v0229;
    goto v0185;

v0185:
    v0229 = stack[-3];
    fn = elt(env, 26); // getrtype
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0231 = v0229;
    if (v0229 == nil) goto v0232;
    v0230 = v0231;
    v0229 = elt(env, 14); // sprifn
    v0229 = Lflagp(nil, v0230, v0229);
    env = stack[-5];
    if (v0229 == nil) goto v0233;
    v0229 = qvalue(elt(env, 11)); // outputhandler!*
    v0229 = (v0229 == nil ? lisp_true : nil);
    goto v0234;

v0234:
    if (v0229 == nil) goto v0232;
    v0229 = stack[-2];
    if (v0229 == nil) goto v0235;
    v0231 = elt(env, 16); // setq
    v0229 = stack[-2];
    v0230 = qcar(v0229);
    v0229 = stack[-3];
    v0229 = list3(v0231, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    fn = elt(env, 27); // maprin
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0236;

v0236:
    v0229 = stack[-4];
    if (v0229 == nil) goto v0237;
    v0229 = qvalue(elt(env, 13)); // t
    fn = elt(env, 25); // fmp!-switch
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0237;

v0237:
    v0229 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0229); }

v0235:
    v0230 = v0231;
    v0229 = elt(env, 15); // tag
    v0229 = get(v0230, v0229);
    env = stack[-5];
    if (!symbolp(v0229)) v0230 = nil;
    else { v0230 = qfastgets(v0229);
           if (v0230 != nil) { v0230 = elt(v0230, 57); // prifn
#ifdef RECORD_GET
             if (v0230 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0230 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0230 == SPID_NOPROP) v0230 = nil; }}
#endif
    v0229 = stack[-3];
    v0229 = Lapply1(nil, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0236;

v0232:
    v0230 = stack[-1];
    v0229 = elt(env, 17); // (first only)
    v0229 = Lmemq(nil, v0230, v0229);
    if (v0229 == nil) goto v0238;
    v0229 = qvalue(elt(env, 13)); // t
    fn = elt(env, 28); // terpri!*
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0238;

v0238:
    v0229 = stack[-2];
    fn = elt(env, 29); // evalvars
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    stack[-2] = v0229;
    v0229 = qvalue(elt(env, 18)); // !*fort
    if (v0229 == nil) goto v0239;
    v0231 = stack[-3];
    v0230 = stack[-2];
    v0229 = stack[-1];
    fn = elt(env, 30); // fvarpri
    v0229 = (*qfnn(fn))(qenv(fn), 3, v0231, v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0229 = stack[-4];
    if (v0229 == nil) goto v0240;
    v0229 = qvalue(elt(env, 13)); // t
    fn = elt(env, 25); // fmp!-switch
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0240;

v0240:
    v0229 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0229); }

v0239:
    v0229 = stack[-2];
    if (v0229 == nil) goto v0241;
    stack[0] = elt(env, 16); // setq
    v0230 = stack[-2];
    v0229 = stack[-3];
    fn = elt(env, 31); // aconc
    v0229 = (*qfn2(fn))(qenv(fn), v0230, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0229 = cons(stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0242;

v0242:
    fn = elt(env, 27); // maprin
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    v0229 = stack[-1];
    if (v0229 == nil) goto v0072;
    v0230 = stack[-1];
    v0229 = elt(env, 19); // first
    v0229 = (v0230 == v0229 ? lisp_true : nil);
    goto v0243;

v0243:
    if (v0229 == nil) goto v0244;
    v0229 = stack[-4];
    if (v0229 == nil) goto v0245;
    v0229 = qvalue(elt(env, 13)); // t
    fn = elt(env, 25); // fmp!-switch
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0245;

v0245:
    v0229 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0229); }

v0244:
    v0229 = qvalue(elt(env, 20)); // !*nat
    if (!(v0229 == nil)) goto v0246;
    v0229 = elt(env, 21); // "$"
    fn = elt(env, 32); // prin2!*
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0246;

v0246:
    v0229 = qvalue(elt(env, 20)); // !*nat
    v0229 = (v0229 == nil ? lisp_true : nil);
    fn = elt(env, 28); // terpri!*
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0236;

v0072:
    v0229 = qvalue(elt(env, 13)); // t
    goto v0243;

v0241:
    v0229 = stack[-3];
    goto v0242;

v0233:
    v0229 = qvalue(elt(env, 1)); // nil
    goto v0234;

v0207:
    v0229 = stack[-3];
    fn = elt(env, 33); // would!-be!-huge
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-5];
    goto v0211;
// error exit handlers
v0064:
    popv(6);
    return nil;
}



// Code for extbrsea

static LispObject CC_extbrsea(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0125, v0280, v0281;
    LispObject fn;
    argcheck(nargs, 0, "extbrsea");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extbrsea");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// end of prologue
    v0125 = qvalue(elt(env, 1)); // rowmin
    stack[-1] = v0125;
    goto v0108;

v0108:
    v0280 = qvalue(elt(env, 2)); // rowmax
    v0125 = stack[-1];
    v0125 = difference2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0125 = Lminusp(nil, v0125);
    env = stack[-2];
    if (v0125 == nil) goto v0157;
    fn = elt(env, 8); // initbrsea
    v0125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    fn = elt(env, 9); // extbrsea1
    v0125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    goto v0223;

v0223:
    fn = elt(env, 10); // expandprod
    v0125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0125 = qvalue(elt(env, 1)); // rowmin
    stack[-1] = v0125;
    goto v0222;

v0222:
    v0280 = qvalue(elt(env, 2)); // rowmax
    v0125 = stack[-1];
    v0125 = difference2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0125 = Lminusp(nil, v0125);
    env = stack[-2];
    if (v0125 == nil) goto v0283;
    fn = elt(env, 8); // initbrsea
    v0125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    fn = elt(env, 9); // extbrsea1
    v0125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    fn = elt(env, 11); // shrinkprod
    v0125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    if (!(v0125 == nil)) goto v0223;
    v0125 = nil;
    { popv(3); return onevalue(v0125); }

v0283:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0280 = qvalue(elt(env, 5)); // maxvar
    v0125 = stack[-1];
    v0125 = plus2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0280 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0125 = (LispObject)49; // 3
    v0280 = *(LispObject *)((char *)v0280 + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0125 = (LispObject)-15; // -1
    if (v0280 == v0125) goto v0244;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0280 = qvalue(elt(env, 5)); // maxvar
    v0125 = stack[-1];
    v0125 = plus2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0280 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0125 = (LispObject)33; // 2
    v0280 = *(LispObject *)((char *)v0280 + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0125 = elt(env, 7); // times
    v0125 = (v0280 == v0125 ? lisp_true : nil);
    goto v0284;

v0284:
    if (v0125 == nil) goto v0285;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0280 = qvalue(elt(env, 5)); // maxvar
    v0125 = stack[-1];
    v0125 = plus2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0281 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0280 = (LispObject)1; // 0
    v0125 = qvalue(elt(env, 6)); // t
    *(LispObject *)((char *)v0281 + (CELL-TAG_VECTOR) + ((int32_t)v0280/(16/CELL))) = v0125;
    goto v0286;

v0286:
    v0125 = stack[-1];
    v0125 = add1(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    stack[-1] = v0125;
    goto v0222;

v0285:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0280 = qvalue(elt(env, 5)); // maxvar
    v0125 = stack[-1];
    v0125 = plus2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0281 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0280 = (LispObject)1; // 0
    v0125 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0281 + (CELL-TAG_VECTOR) + ((int32_t)v0280/(16/CELL))) = v0125;
    goto v0286;

v0244:
    v0125 = qvalue(elt(env, 3)); // nil
    goto v0284;

v0157:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0280 = qvalue(elt(env, 5)); // maxvar
    v0125 = stack[-1];
    v0125 = plus2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0280 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0125 = (LispObject)49; // 3
    v0280 = *(LispObject *)((char *)v0280 + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0125 = (LispObject)-15; // -1
    if (v0280 == v0125) goto v0187;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0280 = qvalue(elt(env, 5)); // maxvar
    v0125 = stack[-1];
    v0125 = plus2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0280 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0125 = (LispObject)49; // 3
    v0280 = *(LispObject *)((char *)v0280 + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0125 = (LispObject)-31; // -2
    v0125 = (v0280 == v0125 ? lisp_true : nil);
    goto v0161;

v0161:
    if (v0125 == nil) goto v0287;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0280 = qvalue(elt(env, 5)); // maxvar
    v0125 = stack[-1];
    v0125 = plus2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0281 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0280 = (LispObject)1; // 0
    v0125 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0281 + (CELL-TAG_VECTOR) + ((int32_t)v0280/(16/CELL))) = v0125;
    goto v0111;

v0111:
    v0125 = stack[-1];
    v0125 = add1(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    stack[-1] = v0125;
    goto v0108;

v0287:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0280 = qvalue(elt(env, 5)); // maxvar
    v0125 = stack[-1];
    v0125 = plus2(v0280, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0281 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0125/(16/CELL)));
    v0280 = (LispObject)1; // 0
    v0125 = qvalue(elt(env, 6)); // t
    *(LispObject *)((char *)v0281 + (CELL-TAG_VECTOR) + ((int32_t)v0280/(16/CELL))) = v0125;
    goto v0111;

v0187:
    v0125 = qvalue(elt(env, 6)); // t
    goto v0161;
// error exit handlers
v0282:
    popv(3);
    return nil;
}



// Code for a2bc

static LispObject CC_a2bc(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0153, v0154;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for a2bc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0153 = v0000;
// end of prologue
    v0154 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0154 == nil) goto v0112;
    v0154 = v0153;
    if (!consp(v0154)) goto v0104;
    v0154 = v0153;
    v0154 = qcar(v0154);
    v0154 = (consp(v0154) ? nil : lisp_true);
    goto v0176;

v0176:
    if (v0154 == nil) goto v0111;
    {
        popv(1);
        fn = elt(env, 4); // bcfd
        return (*qfn1(fn))(qenv(fn), v0153);
    }

v0111:
    v0154 = elt(env, 3); // " Invalid coefficient "
    v0153 = list2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); // rederr
        return (*qfn1(fn))(qenv(fn), v0153);
    }

v0104:
    v0154 = qvalue(elt(env, 2)); // t
    goto v0176;

v0112:
    {
        popv(1);
        fn = elt(env, 6); // simp!*
        return (*qfn1(fn))(qenv(fn), v0153);
    }
// error exit handlers
v0157:
    popv(1);
    return nil;
}



// Code for applysetop

static LispObject CC_applysetop(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0063, v0064, v0248;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for applysetop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0064 = v0001;
    stack[-6] = v0000;
// end of prologue
    stack[-5] = nil;
    v0063 = (LispObject)1; // 0
    stack[-7] = v0063;
    v0063 = v0064;
    stack[-4] = v0063;
    v0063 = stack[-4];
    if (v0063 == nil) goto v0196;
    v0063 = stack[-4];
    v0063 = qcar(v0063);
    stack[0] = v0063;
    v0063 = stack[0];
    fn = elt(env, 6); // reval
    v0064 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[0] = v0064;
    v0063 = elt(env, 2); // list
    if (!consp(v0064)) goto v0187;
    v0064 = qcar(v0064);
    if (!(v0064 == v0063)) goto v0187;
    v0063 = stack[0];
    v0063 = qcdr(v0063);
    fn = elt(env, 7); // delete!-dups
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[0] = v0063;
    v0064 = stack[-7];
    v0063 = (LispObject)1; // 0
    if (v0064 == v0063) goto v0173;
    v0248 = stack[-6];
    v0064 = stack[-7];
    v0063 = stack[0];
    v0063 = Lapply2(nil, 3, v0248, v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    goto v0101;

v0101:
    stack[-7] = v0063;
    v0063 = stack[0];
    fn = elt(env, 8); // make!-set
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    goto v0163;

v0163:
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[-2] = v0063;
    stack[-3] = v0063;
    goto v0109;

v0109:
    v0063 = stack[-4];
    v0063 = qcdr(v0063);
    stack[-4] = v0063;
    v0063 = stack[-4];
    if (v0063 == nil) goto v0226;
    stack[-1] = stack[-2];
    v0063 = stack[-4];
    v0063 = qcar(v0063);
    stack[0] = v0063;
    v0063 = stack[0];
    fn = elt(env, 6); // reval
    v0064 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[0] = v0064;
    v0063 = elt(env, 2); // list
    if (!consp(v0064)) goto v0271;
    v0064 = qcar(v0064);
    if (!(v0064 == v0063)) goto v0271;
    v0063 = stack[0];
    v0063 = qcdr(v0063);
    fn = elt(env, 7); // delete!-dups
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[0] = v0063;
    v0064 = stack[-7];
    v0063 = (LispObject)1; // 0
    if (v0064 == v0063) goto v0302;
    v0248 = stack[-6];
    v0064 = stack[-7];
    v0063 = stack[0];
    v0063 = Lapply2(nil, 3, v0248, v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    goto v0303;

v0303:
    stack[-7] = v0063;
    v0063 = stack[0];
    fn = elt(env, 8); // make!-set
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    goto v0270;

v0270:
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0063 = Lrplacd(nil, stack[-1], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0063 = stack[-2];
    v0063 = qcdr(v0063);
    stack[-2] = v0063;
    goto v0109;

v0302:
    v0063 = stack[0];
    goto v0303;

v0271:
    v0063 = stack[0];
    if (symbolp(v0063)) goto v0262;
    v0063 = stack[0];
    v0063 = Lconsp(nil, v0063);
    env = stack[-8];
    if (v0063 == nil) goto v0304;
    v0063 = stack[0];
    v0064 = qcar(v0063);
    v0063 = elt(env, 3); // setvalued
    v0063 = Lflagp(nil, v0064, v0063);
    env = stack[-8];
    if (!(v0063 == nil)) goto v0262;

v0304:
    v0064 = stack[0];
    v0063 = elt(env, 4); // "set"
    fn = elt(env, 9); // typerr
    v0063 = (*qfn2(fn))(qenv(fn), v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    goto v0270;

v0262:
    v0064 = stack[0];
    v0063 = stack[-5];
    v0063 = Lmember(nil, v0064, v0063);
    if (!(v0063 == nil)) goto v0240;
    v0064 = stack[0];
    v0063 = stack[-5];
    v0063 = cons(v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[-5] = v0063;
    goto v0240;

v0240:
    v0063 = stack[0];
    goto v0270;

v0226:
    v0063 = stack[-3];
    goto v0104;

v0104:
    v0248 = v0063;
    v0063 = stack[-5];
    if (v0063 == nil) goto v0231;
    stack[0] = stack[-6];
    v0064 = stack[-6];
    v0063 = elt(env, 5); // setdiff
    if (v0064 == v0063) goto v0305;
    v0064 = stack[-7];
    v0063 = (LispObject)1; // 0
    if (v0064 == v0063) goto v0255;
    v0063 = stack[-7];
    fn = elt(env, 8); // make!-set
    v0064 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0063 = stack[-5];
    v0063 = cons(v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    goto v0306;

v0306:
    {
        LispObject v0307 = stack[0];
        popv(9);
        return cons(v0307, v0063);
    }

v0255:
    v0063 = stack[-5];
    goto v0306;

v0305:
    v0063 = v0248;
    goto v0306;

v0231:
    v0063 = stack[-7];
    fn = elt(env, 8); // make!-set
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 10); // aeval
        return (*qfn1(fn))(qenv(fn), v0063);
    }

v0173:
    v0063 = stack[0];
    goto v0101;

v0187:
    v0063 = stack[0];
    if (symbolp(v0063)) goto v0210;
    v0063 = stack[0];
    v0063 = Lconsp(nil, v0063);
    env = stack[-8];
    if (v0063 == nil) goto v0224;
    v0063 = stack[0];
    v0064 = qcar(v0063);
    v0063 = elt(env, 3); // setvalued
    v0063 = Lflagp(nil, v0064, v0063);
    env = stack[-8];
    if (!(v0063 == nil)) goto v0210;

v0224:
    v0064 = stack[0];
    v0063 = elt(env, 4); // "set"
    fn = elt(env, 9); // typerr
    v0063 = (*qfn2(fn))(qenv(fn), v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    goto v0163;

v0210:
    v0064 = stack[0];
    v0063 = stack[-5];
    v0063 = Lmember(nil, v0064, v0063);
    if (!(v0063 == nil)) goto v0095;
    v0064 = stack[0];
    v0063 = stack[-5];
    v0063 = cons(v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[-5] = v0063;
    goto v0095;

v0095:
    v0063 = stack[0];
    goto v0163;

v0196:
    v0063 = qvalue(elt(env, 1)); // nil
    goto v0104;
// error exit handlers
v0128:
    popv(9);
    return nil;
}



// Code for calc_atlas

static LispObject CC_calc_atlas(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0159, v0111, v0148, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_atlas");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0159 = v0001;
    v0111 = v0000;
// end of prologue
    v0148 = v0111;
    v0110 = qcar(v0148);
    v0148 = v0111;
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0111 = qcdr(v0111);
    v0111 = qcar(v0111);
    {
        fn = elt(env, 1); // calc_map_2d
        return (*qfnn(fn))(qenv(fn), 4, v0110, v0148, v0111, v0159);
    }
}



// Code for !*n2a

static LispObject CC_Hn2a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0104, v0109;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *n2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0109 = v0000;
// end of prologue
    v0104 = v0109;
    v0104 = integerp(v0104);
    if (!(v0104 == nil)) return onevalue(v0109);
    v0104 = v0109;
    {
        fn = elt(env, 1); // !*q2a
        return (*qfn1(fn))(qenv(fn), v0104);
    }
}



// Code for appn

static LispObject CC_appn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0114, v0113;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for appn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0109;

v0109:
    v0113 = stack[0];
    v0114 = (LispObject)17; // 1
    if (v0113 == v0114) goto v0174;
    v0113 = stack[-1];
    v0114 = stack[-2];
    v0114 = cons(v0113, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    stack[-2] = v0114;
    v0114 = stack[0];
    v0114 = sub1(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    stack[0] = v0114;
    goto v0109;

v0174:
    v0114 = stack[-1];
    v0113 = v0114;
    goto v0166;

v0166:
    v0114 = stack[-2];
    if (v0114 == nil) { popv(4); return onevalue(v0113); }
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = Lappend(nil, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    v0113 = v0114;
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    stack[-2] = v0114;
    goto v0166;
// error exit handlers
v0160:
    popv(4);
    return nil;
}



// Code for maxfrom

static LispObject CC_maxfrom(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0108, v0151;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxfrom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0108 = v0001;
    v0151 = v0000;
// end of prologue
    stack[0] = v0151;
    v0151 = add1(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-1];
    v0108 = (LispObject)1; // 0
    {
        LispObject v0197 = stack[0];
        popv(2);
        fn = elt(env, 1); // maxfrom1
        return (*qfnn(fn))(qenv(fn), 3, v0197, v0151, v0108);
    }
// error exit handlers
v0196:
    popv(2);
    return nil;
}



// Code for pasf_fact

static LispObject CC_pasf_fact(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0239, v0312, v0313;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_fact");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    v0312 = stack[-1];
    v0239 = elt(env, 1); // true
    if (v0312 == v0239) goto v0104;
    v0312 = stack[-1];
    v0239 = elt(env, 3); // false
    v0239 = (v0312 == v0239 ? lisp_true : nil);
    goto v0176;

v0176:
    if (!(v0239 == nil)) { LispObject res = stack[-1]; popv(7); return onevalue(res); }
    v0239 = stack[-1];
    v0239 = qcar(v0239);
    stack[-5] = v0239;
    v0239 = stack[-1];
    v0239 = qcdr(v0239);
    v0239 = qcar(v0239);
    fn = elt(env, 10); // fctrf
    v0239 = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    stack[0] = v0239;
    v0239 = stack[0];
    v0312 = Llength(nil, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    v0239 = (LispObject)49; // 3
    v0239 = (LispObject)lessp2(v0312, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    v0239 = v0239 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0239 == nil)) { LispObject res = stack[-1]; popv(7); return onevalue(res); }
    v0312 = stack[-5];
    v0239 = elt(env, 4); // (equal neq)
    v0239 = Lmemq(nil, v0312, v0239);
    if (v0239 == nil) goto v0303;
    v0312 = stack[-5];
    v0239 = elt(env, 5); // equal
    if (v0312 == v0239) goto v0189;
    v0239 = elt(env, 7); // and
    stack[-4] = v0239;
    goto v0120;

v0120:
    v0239 = stack[0];
    v0239 = qcdr(v0239);
    stack[-3] = v0239;
    v0239 = stack[-3];
    if (v0239 == nil) goto v0300;
    v0239 = stack[-3];
    v0239 = qcar(v0239);
    v0313 = stack[-5];
    v0312 = qcar(v0239);
    v0239 = qvalue(elt(env, 8)); // nil
    v0239 = list3(v0313, v0312, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    v0239 = ncons(v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    stack[-1] = v0239;
    stack[-2] = v0239;
    goto v0314;

v0314:
    v0239 = stack[-3];
    v0239 = qcdr(v0239);
    stack[-3] = v0239;
    v0239 = stack[-3];
    if (v0239 == nil) goto v0225;
    stack[0] = stack[-1];
    v0239 = stack[-3];
    v0239 = qcar(v0239);
    v0313 = stack[-5];
    v0312 = qcar(v0239);
    v0239 = qvalue(elt(env, 8)); // nil
    v0239 = list3(v0313, v0312, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    v0239 = ncons(v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    v0239 = Lrplacd(nil, stack[0], v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    v0239 = stack[-1];
    v0239 = qcdr(v0239);
    stack[-1] = v0239;
    goto v0314;

v0225:
    v0239 = stack[-2];
    goto v0096;

v0096:
    {
        LispObject v0315 = stack[-4];
        popv(7);
        return cons(v0315, v0239);
    }

v0300:
    v0239 = qvalue(elt(env, 8)); // nil
    goto v0096;

v0189:
    v0239 = elt(env, 6); // or
    stack[-4] = v0239;
    goto v0120;

v0303:
    v0312 = stack[-5];
    v0239 = elt(env, 9); // (leq lessp geq greaterp)
    v0239 = Lmemq(nil, v0312, v0239);
    if (v0239 == nil) { LispObject res = stack[-1]; popv(7); return onevalue(res); }
    v0239 = stack[0];
    stack[-1] = qcdr(v0239);
    v0239 = stack[0];
    v0239 = qcar(v0239);
    fn = elt(env, 11); // minusf
    v0239 = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    if (v0239 == nil) goto v0316;
    v0239 = stack[-5];
    fn = elt(env, 12); // pasf_anegrel
    v0239 = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-6];
    goto v0269;

v0269:
    {
        LispObject v0082 = stack[-1];
        popv(7);
        fn = elt(env, 13); // pasf_fact1
        return (*qfn2(fn))(qenv(fn), v0082, v0239);
    }

v0316:
    v0239 = stack[-5];
    goto v0269;

v0104:
    v0239 = qvalue(elt(env, 2)); // t
    goto v0176;
// error exit handlers
v0266:
    popv(7);
    return nil;
}



// Code for upperlimitrd

static LispObject CC_upperlimitrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0161, v0187;
    LispObject fn;
    argcheck(nargs, 0, "upperlimitrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for upperlimitrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// end of prologue
    fn = elt(env, 4); // mathml
    v0161 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    stack[0] = v0161;
    fn = elt(env, 5); // lex
    v0161 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    v0187 = qvalue(elt(env, 1)); // char
    v0161 = elt(env, 2); // (!/ u p l i m i t)
    if (equal(v0187, v0161)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0187 = elt(env, 3); // "</uplimit>"
    v0161 = (LispObject)33; // 2
    fn = elt(env, 6); // errorml
    v0161 = (*qfn2(fn))(qenv(fn), v0187, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    v0161 = nil;
    { popv(2); return onevalue(v0161); }
// error exit handlers
v0102:
    popv(2);
    return nil;
}



// Code for prlist

static LispObject CC_prlist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0158, v0150;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0150 = nil;
    goto v0156;

v0156:
    v0158 = stack[0];
    if (v0158 == nil) goto v0174;
    v0158 = stack[0];
    v0158 = qcar(v0158);
    v0158 = Lconsp(nil, v0158);
    env = stack[-1];
    if (v0158 == nil) goto v0187;
    v0158 = stack[0];
    v0158 = qcar(v0158);
    v0158 = cons(v0158, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-1];
    v0150 = v0158;
    v0158 = stack[0];
    v0158 = qcdr(v0158);
    stack[0] = v0158;
    goto v0156;

v0187:
    v0158 = stack[0];
    v0158 = qcdr(v0158);
    stack[0] = v0158;
    goto v0156;

v0174:
    v0158 = v0150;
    {
        popv(2);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0158);
    }
// error exit handlers
v0149:
    popv(2);
    return nil;
}



// Code for copy_mat

static LispObject CC_copy_mat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0150, v0112;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for copy_mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    stack[-1] = nil;
    goto v0156;

v0156:
    v0150 = stack[0];
    v0150 = Lconsp(nil, v0150);
    env = stack[-2];
    if (v0150 == nil) goto v0163;
    v0150 = stack[0];
    v0150 = qcar(v0150);
    v0112 = CC_copy_mat(env, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-2];
    v0150 = stack[-1];
    v0150 = cons(v0112, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-2];
    stack[-1] = v0150;
    v0150 = stack[0];
    v0150 = qcdr(v0150);
    stack[0] = v0150;
    goto v0156;

v0163:
    v0112 = stack[-1];
    v0150 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0112, v0150);
    }
// error exit handlers
v0152:
    popv(3);
    return nil;
}



// Code for mkbc

static LispObject CC_mkbc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0209, v0317;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkbc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue

v0156:
    v0209 = stack[-1];
    v0209 = (is_number(v0209) ? lisp_true : nil);
    if (!(v0209 == nil)) goto v0178;
    v0209 = stack[-1];
    fn = elt(env, 3); // f2dip11
    v0209 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    goto v0178;

v0178:
    v0209 = stack[0];
    v0209 = (is_number(v0209) ? lisp_true : nil);
    if (!(v0209 == nil)) goto v0109;
    v0209 = stack[0];
    fn = elt(env, 3); // f2dip11
    v0209 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    goto v0109;

v0109:
    v0209 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0209 == nil) goto v0162;
    v0209 = stack[0];
    v0209 = Lmodular_reciprocal(nil, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0209 = times2(stack[-1], v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(qenv(fn), v0209);
    }

v0162:
    v0317 = stack[0];
    v0209 = (LispObject)17; // 1
    if (v0317 == v0209) goto v0099;
    v0209 = stack[0];
    fn = elt(env, 5); // minusf
    v0209 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    if (v0209 == nil) goto v0279;
    v0209 = stack[-1];
    fn = elt(env, 6); // negf
    v0209 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    stack[-1] = v0209;
    v0209 = stack[0];
    fn = elt(env, 6); // negf
    v0209 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    stack[0] = v0209;
    goto v0156;

v0279:
    v0317 = stack[-1];
    v0209 = stack[0];
    fn = elt(env, 7); // gcdf
    v0209 = (*qfn2(fn))(qenv(fn), v0317, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    stack[-2] = v0209;
    v0317 = stack[-1];
    v0209 = stack[-2];
    fn = elt(env, 8); // quotfx
    stack[-1] = (*qfn2(fn))(qenv(fn), v0317, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0317 = stack[0];
    v0209 = stack[-2];
    fn = elt(env, 8); // quotfx
    v0209 = (*qfn2(fn))(qenv(fn), v0317, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    {
        LispObject v0275 = stack[-1];
        popv(4);
        return cons(v0275, v0209);
    }

v0099:
    v0317 = stack[-1];
    v0209 = (LispObject)17; // 1
    if (v0317 == v0209) goto v0165;
    v0317 = stack[-1];
    v0209 = stack[0];
    popv(4);
    return cons(v0317, v0209);

v0165:
    v0209 = elt(env, 2); // (1 . 1)
    { popv(4); return onevalue(v0209); }
// error exit handlers
v0234:
    popv(4);
    return nil;
}



// Code for mkupf

static LispObject CC_mkupf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0311, v0296, v0297;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkupf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0311 = v0000;
// end of prologue
    v0296 = v0311;
    v0311 = (LispObject)17; // 1
    fn = elt(env, 3); // mksq
    v0311 = (*qfn2(fn))(qenv(fn), v0296, v0311);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    stack[0] = v0311;
    v0311 = stack[0];
    v0311 = qcar(v0311);
    if (v0311 == nil) goto v0108;
    v0311 = stack[0];
    v0311 = qcar(v0311);
    if (!consp(v0311)) goto v0111;
    v0311 = stack[0];
    v0311 = qcar(v0311);
    v0311 = qcar(v0311);
    v0311 = (consp(v0311) ? nil : lisp_true);
    goto v0159;

v0159:
    if (v0311 == nil) goto v0113;
    v0296 = (LispObject)17; // 1
    v0311 = stack[0];
    v0311 = cons(v0296, v0311);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    popv(2);
    return ncons(v0311);

v0113:
    v0311 = stack[0];
    v0296 = qcdr(v0311);
    v0311 = (LispObject)17; // 1
    if (v0296 == v0311) goto v0184;
    v0311 = qvalue(elt(env, 1)); // nil
    goto v0115;

v0115:
    if (v0311 == nil) goto v0224;
    v0311 = stack[0];
    v0311 = qcar(v0311);
    v0311 = qcar(v0311);
    v0311 = qcar(v0311);
    v0297 = qcar(v0311);
    v0296 = (LispObject)17; // 1
    v0311 = (LispObject)17; // 1
    v0311 = list2star(v0297, v0296, v0311);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    popv(2);
    return ncons(v0311);

v0224:
    v0311 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // partitsq!*
        return (*qfn1(fn))(qenv(fn), v0311);
    }

v0184:
    v0311 = stack[0];
    v0311 = qcar(v0311);
    v0311 = qcar(v0311);
    v0296 = qcdr(v0311);
    v0311 = (LispObject)17; // 1
    if (v0296 == v0311) goto v0182;
    v0311 = qvalue(elt(env, 1)); // nil
    goto v0115;

v0182:
    v0311 = stack[0];
    v0311 = qcar(v0311);
    v0311 = qcdr(v0311);
    if (v0311 == nil) goto v0189;
    v0311 = qvalue(elt(env, 1)); // nil
    goto v0115;

v0189:
    v0311 = stack[0];
    v0311 = qcar(v0311);
    v0311 = qcar(v0311);
    v0311 = qcar(v0311);
    v0311 = qcar(v0311);
    fn = elt(env, 5); // sfp
    v0311 = (*qfn1(fn))(qenv(fn), v0311);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    v0311 = (v0311 == nil ? lisp_true : nil);
    goto v0115;

v0111:
    v0311 = qvalue(elt(env, 2)); // t
    goto v0159;

v0108:
    v0311 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0311); }
// error exit handlers
v0090:
    popv(2);
    return nil;
}



// Code for replace2_parents

static LispObject CC_replace2_parents(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0173, v0155;
    LispObject v0147, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "replace2_parents");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replace2_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0147,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0147;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0155 = stack[-2];
    v0173 = stack[0];
    v0173 = qcar(v0173);
    if (!(equal(v0155, v0173))) goto v0161;
    v0155 = stack[0];
    v0173 = stack[-1];
    v0173 = Lrplaca(nil, v0155, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    goto v0161;

v0161:
    v0155 = stack[-2];
    v0173 = stack[0];
    v0173 = qcdr(v0173);
    if (equal(v0155, v0173)) goto v0162;
    v0173 = nil;
    { popv(3); return onevalue(v0173); }

v0162:
    v0155 = stack[0];
    v0173 = stack[-1];
        popv(3);
        return Lrplacd(nil, v0155, v0173);
// error exit handlers
v0114:
    popv(3);
    return nil;
}



// Code for formsetq0

static LispObject CC_formsetq0(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0370, v0371, v0372, v0373;
    LispObject fn;
    LispObject v0147, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formsetq0");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formsetq0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0147,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0147;
    stack[-4] = v0001;
    stack[0] = v0000;
// end of prologue
    stack[-1] = nil;
    v0370 = stack[0];
    v0370 = qcdr(v0370);
    stack[0] = v0370;
    v0370 = qcar(v0370);
    stack[-2] = v0370;
    if (!(symbolp(v0370))) goto v0187;
    v0371 = stack[-2];
    v0370 = stack[-4];
    v0370 = Latsoc(nil, v0371, v0370);
    stack[-1] = v0370;
    goto v0187;

v0187:
    v0370 = stack[0];
    v0370 = qcdr(v0370);
    v0371 = qcar(v0370);
    v0370 = elt(env, 1); // quote
    if (!consp(v0371)) goto v0154;
    v0371 = qcar(v0371);
    if (!(v0371 == v0370)) goto v0154;
    v0370 = elt(env, 2); // symbolic
    stack[-3] = v0370;
    goto v0154;

v0154:
    v0370 = stack[0];
    v0370 = qcdr(v0370);
    v0373 = qcar(v0370);
    v0372 = stack[-4];
    v0371 = elt(env, 2); // symbolic
    v0370 = stack[-3];
    fn = elt(env, 24); // convertmode
    v0370 = (*qfnn(fn))(qenv(fn), 4, v0373, v0372, v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    stack[-5] = v0370;
    v0370 = stack[-2];
    if (!consp(v0370)) goto v0276;
    v0370 = qvalue(elt(env, 3)); // !*savedef
    if (v0370 == nil) goto v0097;
    v0370 = stack[-2];
    v0371 = qcar(v0370);
    v0370 = elt(env, 4); // inline
    v0370 = get(v0371, v0370);
    env = stack[-6];
    if (!(v0370 == nil)) goto v0098;
    v0370 = stack[-2];
    v0371 = qcar(v0370);
    v0370 = elt(env, 5); // smacro
    v0370 = get(v0371, v0370);
    env = stack[-6];
    if (!(v0370 == nil)) goto v0098;

v0097:
    v0370 = qvalue(elt(env, 7)); // t
    goto v0182;

v0182:
    if (v0370 == nil) goto v0180;
    v0370 = stack[-2];
    v0370 = qcar(v0370);
    if (symbolp(v0370)) goto v0375;
    v0371 = stack[-2];
    v0370 = elt(env, 9); // "assignment"
    {
        popv(7);
        fn = elt(env, 25); // typerr
        return (*qfn2(fn))(qenv(fn), v0371, v0370);
    }

v0375:
    v0371 = stack[-2];
    v0370 = stack[-3];
    fn = elt(env, 26); // macrochk
    v0370 = (*qfn2(fn))(qenv(fn), v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    stack[-2] = v0370;
    if (!consp(v0370)) goto v0273;
    v0370 = stack[-2];
    v0370 = qcar(v0370);
    fn = elt(env, 27); // arrayp
    v0370 = (*qfn1(fn))(qenv(fn), v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    goto v0376;

v0376:
    if (v0370 == nil) goto v0225;
    stack[0] = elt(env, 10); // setel
    v0372 = stack[-2];
    v0371 = stack[-4];
    v0370 = stack[-3];
    fn = elt(env, 28); // intargfn
    v0371 = (*qfnn(fn))(qenv(fn), 3, v0372, v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    v0370 = stack[-5];
    {
        LispObject v0023 = stack[0];
        popv(7);
        return list3(v0023, v0371, v0370);
    }

v0225:
    v0370 = stack[-2];
    if (!consp(v0370)) goto v0377;
    v0370 = stack[-2];
    v0370 = qcdr(v0370);
    if (v0370 == nil) goto v0232;
    v0370 = stack[-2];
    v0370 = qcar(v0370);
    if (!symbolp(v0370)) v0371 = nil;
    else { v0371 = qfastgets(v0370);
           if (v0371 != nil) { v0371 = elt(v0371, 2); // rtype
#ifdef RECORD_GET
             if (v0371 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0371 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0371 == SPID_NOPROP) v0371 = nil; }}
#endif
    v0370 = elt(env, 11); // vector
    if (v0371 == v0370) goto v0316;
    v0370 = stack[-2];
    v0370 = qcdr(v0370);
    v0370 = qcar(v0370);
    v0370 = Lsimple_vectorp(nil, v0370);
    env = stack[-6];
    if (!(v0370 == nil)) goto v0378;
    v0370 = stack[-2];
    v0370 = qcdr(v0370);
    v0371 = qcar(v0370);
    v0370 = elt(env, 12); // vecfn
    v0370 = Lflagpcar(nil, v0371, v0370);
    env = stack[-6];
    goto v0378;

v0378:
    if (v0370 == nil) goto v0241;
    v0372 = stack[0];
    v0371 = stack[-4];
    v0370 = stack[-3];
    {
        popv(7);
        fn = elt(env, 29); // putvect
        return (*qfnn(fn))(qenv(fn), 3, v0372, v0371, v0370);
    }

v0241:
    v0371 = stack[-2];
    v0370 = elt(env, 13); // part
    if (!consp(v0371)) goto v0217;
    v0371 = qcar(v0371);
    if (!(v0371 == v0370)) goto v0217;
    stack[-1] = elt(env, 14); // list
    v0370 = elt(env, 15); // setpart!*
    stack[0] = Lmkquote(nil, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0370 = stack[-2];
    v0372 = qcdr(v0370);
    v0371 = stack[-4];
    v0370 = stack[-3];
    fn = elt(env, 30); // formlis
    v0370 = (*qfnn(fn))(qenv(fn), 3, v0372, v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0371 = list2star(stack[-1], stack[0], v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0370 = stack[-5];
    {
        popv(7);
        fn = elt(env, 31); // aconc
        return (*qfn2(fn))(qenv(fn), v0371, v0370);
    }

v0217:
    v0370 = stack[-2];
    if (!consp(v0370)) goto v0379;
    v0370 = stack[-2];
    v0371 = qcar(v0370);
    v0370 = elt(env, 16); // setqfn
    v0370 = get(v0371, v0370);
    env = stack[-6];
    stack[-1] = v0370;
    goto v0237;

v0237:
    if (v0370 == nil) goto v0380;
    v0370 = stack[-2];
    v0371 = qcdr(v0370);
    v0370 = stack[0];
    v0370 = qcdr(v0370);
    v0371 = Lappend(nil, v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0370 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 32); // applsmacro
    v0372 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0371 = stack[-4];
    v0370 = stack[-3];
    {
        popv(7);
        fn = elt(env, 33); // form1
        return (*qfnn(fn))(qenv(fn), 3, v0372, v0371, v0370);
    }

v0380:
    v0371 = stack[-3];
    v0370 = elt(env, 2); // symbolic
    if (v0371 == v0370) goto v0381;
    v0370 = qvalue(elt(env, 8)); // nil
    goto v0382;

v0382:
    if (v0370 == nil) goto v0383;
    stack[0] = elt(env, 19); // rsetf
    v0372 = stack[-2];
    v0371 = stack[-4];
    v0370 = stack[-3];
    fn = elt(env, 33); // form1
    v0371 = (*qfnn(fn))(qenv(fn), 3, v0372, v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    v0370 = stack[-5];
    {
        LispObject v0384 = stack[0];
        popv(7);
        return list3(v0384, v0371, v0370);
    }

v0383:
    stack[0] = elt(env, 20); // setk
    v0372 = stack[-2];
    v0371 = stack[-4];
    v0370 = elt(env, 21); // algebraic
    fn = elt(env, 33); // form1
    v0371 = (*qfnn(fn))(qenv(fn), 3, v0372, v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    v0370 = stack[-5];
    {
        LispObject v0385 = stack[0];
        popv(7);
        return list3(v0385, v0371, v0370);
    }

v0381:
    v0370 = qvalue(elt(env, 17)); // !*rlisp88
    if (!(v0370 == nil)) goto v0382;
    v0371 = stack[-2];
    v0370 = elt(env, 18); // structfetch
    v0370 = Leqcar(nil, v0371, v0370);
    env = stack[-6];
    goto v0382;

v0379:
    v0370 = qvalue(elt(env, 8)); // nil
    goto v0237;

v0316:
    v0370 = qvalue(elt(env, 7)); // t
    goto v0378;

v0232:
    v0370 = qvalue(elt(env, 8)); // nil
    goto v0378;

v0377:
    v0370 = qvalue(elt(env, 8)); // nil
    goto v0378;

v0273:
    v0370 = qvalue(elt(env, 8)); // nil
    goto v0376;

v0180:
    v0370 = stack[-2];
    if (symbolp(v0370)) goto v0386;
    v0371 = stack[-2];
    v0370 = elt(env, 9); // "assignment"
    {
        popv(7);
        fn = elt(env, 25); // typerr
        return (*qfn2(fn))(qenv(fn), v0371, v0370);
    }

v0386:
    v0371 = stack[-2];
    v0370 = elt(env, 22); // reserved
    v0370 = Lflagp(nil, v0371, v0370);
    env = stack[-6];
    if (v0370 == nil) goto v0387;
    v0371 = stack[-2];
    v0370 = stack[-4];
    v0370 = Latsoc(nil, v0371, v0370);
    v0370 = (v0370 == nil ? lisp_true : nil);
    goto v0388;

v0388:
    if (v0370 == nil) goto v0048;
    v0370 = stack[-2];
    {
        popv(7);
        fn = elt(env, 34); // rsverr
        return (*qfn1(fn))(qenv(fn), v0370);
    }

v0048:
    v0370 = stack[-2];
    if (!symbolp(v0370)) v0370 = nil;
    else { v0370 = qfastgets(v0370);
           if (v0370 != nil) { v0370 = elt(v0370, 17); // share
#ifdef RECORD_GET
             if (v0370 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0370 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0370 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0370 == SPID_NOPROP) v0370 = nil; else v0370 = lisp_true; }}
#endif
    if (v0370 == nil) goto v0389;
    v0371 = stack[-2];
    v0370 = stack[-4];
    fn = elt(env, 35); // symbid
    v0371 = (*qfn2(fn))(qenv(fn), v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0370 = stack[-5];
    {
        popv(7);
        fn = elt(env, 36); // mksetshare
        return (*qfn2(fn))(qenv(fn), v0371, v0370);
    }

v0389:
    v0371 = stack[-3];
    v0370 = elt(env, 2); // symbolic
    if (v0371 == v0370) goto v0390;
    v0370 = stack[-1];
    if (!(v0370 == nil)) goto v0391;
    v0371 = stack[-5];
    v0370 = elt(env, 1); // quote
    v0370 = Leqcar(nil, v0371, v0370);
    env = stack[-6];
    goto v0391;

v0391:
    if (v0370 == nil) goto v0030;
    v0371 = stack[-2];
    v0370 = stack[-4];
    fn = elt(env, 35); // symbid
    v0371 = (*qfn2(fn))(qenv(fn), v0371, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0370 = stack[-5];
    {
        popv(7);
        fn = elt(env, 37); // mksetq
        return (*qfn2(fn))(qenv(fn), v0371, v0370);
    }

v0030:
    v0370 = stack[0];
    v0370 = qcdr(v0370);
    v0370 = qcar(v0370);
    v0370 = Lsimple_vectorp(nil, v0370);
    env = stack[-6];
    if (!(v0370 == nil)) goto v0392;
    v0370 = stack[0];
    v0370 = qcdr(v0370);
    v0371 = qcar(v0370);
    v0370 = elt(env, 12); // vecfn
    v0370 = Lflagpcar(nil, v0371, v0370);
    env = stack[-6];
    if (!(v0370 == nil)) goto v0392;
    stack[0] = elt(env, 20); // setk
    v0370 = stack[-2];
    v0371 = Lmkquote(nil, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    v0370 = stack[-5];
    {
        LispObject v0393 = stack[0];
        popv(7);
        return list3(v0393, v0371, v0370);
    }

v0392:
    stack[-1] = elt(env, 23); // setv
    v0370 = stack[-2];
    v0371 = Lmkquote(nil, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    v0370 = stack[0];
    v0370 = qcdr(v0370);
    v0370 = qcar(v0370);
    {
        LispObject v0394 = stack[-1];
        popv(7);
        return list3(v0394, v0371, v0370);
    }

v0390:
    v0370 = qvalue(elt(env, 7)); // t
    goto v0391;

v0387:
    v0370 = qvalue(elt(env, 8)); // nil
    goto v0388;

v0098:
    v0370 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0370 = (LispObject)zerop(v0370);
    v0370 = v0370 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0370 == nil)) goto v0314;
    v0370 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    goto v0314;

v0314:
    v0370 = elt(env, 6); // "+++ Assign via inline or smacro: "
    v0370 = Lprinc(nil, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    v0370 = stack[-2];
    v0370 = Lprint(nil, v0370);
    nil = C_nil;
    if (exception_pending()) goto v0374;
    env = stack[-6];
    goto v0097;

v0276:
    v0370 = qvalue(elt(env, 8)); // nil
    goto v0182;
// error exit handlers
v0374:
    popv(7);
    return nil;
}



// Code for redall

static LispObject CC_redall(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0401, v0402, v0360;
    LispObject fn;
    LispObject v0009, v0147, v0001;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "redall");
    va_start(aa, nargs);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for redall");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0009,v0147,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0001,v0147,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0009;
    v0402 = v0147;
    v0401 = v0001;
// end of prologue
    stack[-8] = qvalue(elt(env, 1)); // gg!*
    qvalue(elt(env, 1)) = nil; // gg!*
    qvalue(elt(env, 1)) = v0401; // gg!*
    v0401 = v0402;
    stack[-6] = v0401;
    v0401 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 3)) = v0401; // shortway!*
    qvalue(elt(env, 4)) = v0401; // thirdway!*
    v0401 = qvalue(elt(env, 5)); // t
    stack[-1] = v0401;
    goto v0171;

v0171:
    v0401 = stack[-6];
    if (v0401 == nil) goto v0170;
    v0401 = stack[-6];
    v0401 = Lreverse(nil, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = qcar(v0401);
    stack[-5] = v0401;
    v0402 = stack[-5];
    v0401 = stack[-6];
    v0401 = Ldelete(nil, v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    stack[-6] = v0401;
    v0401 = stack[-5];
    v0401 = qcar(v0401);
    stack[-2] = v0401;
    v0402 = qvalue(elt(env, 6)); // gv!*
    v0401 = stack[-2];
    v0401 = *(LispObject *)((char *)v0402 + (CELL-TAG_VECTOR) + ((int32_t)v0401/(16/CELL)));
    stack[-4] = v0401;
    v0401 = qvalue(elt(env, 7)); // path
    if (v0401 == nil) goto v0193;
    v0401 = stack[-1];
    if (v0401 == nil) goto v0098;
    v0401 = stack[-4];
    fn = elt(env, 12); // ljet
    v0401 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = Lprinc(nil, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = elt(env, 8); // " ==> "
    v0401 = Lprinc(nil, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    goto v0193;

v0193:
    stack[-3] = qvalue(elt(env, 6)); // gv!*
    stack[0] = stack[-2];
    v0360 = stack[-4];
    v0402 = qvalue(elt(env, 1)); // gg!*
    v0401 = stack[-7];
    fn = elt(env, 13); // nf
    v0401 = (*qfnn(fn))(qenv(fn), 3, v0360, v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0401;
    stack[-5] = v0401;
    v0401 = stack[-5];
    if (v0401 == nil) goto v0403;
    v0401 = stack[-5];
    fn = elt(env, 12); // ljet
    v0401 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    goto v0206;

v0206:
    stack[-3] = v0401;
    v0401 = qvalue(elt(env, 7)); // path
    if (v0401 == nil) goto v0299;
    v0401 = stack[-3];
    v0401 = Lprinc(nil, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    goto v0299;

v0299:
    v0401 = stack[-5];
    if (v0401 == nil) goto v0171;
    v0401 = stack[-3];
    fn = elt(env, 14); // ord
    v0402 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = (LispObject)1; // 0
    if (v0402 == v0401) goto v0124;
    v0401 = stack[-5];
    fn = elt(env, 12); // ljet
    stack[0] = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = stack[-4];
    fn = elt(env, 12); // ljet
    v0401 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    if (equal(stack[0], v0401)) goto v0235;
    v0401 = qvalue(elt(env, 5)); // t
    qvalue(elt(env, 3)) = v0401; // shortway!*
    goto v0235;

v0235:
    v0401 = stack[-1];
    if (v0401 == nil) goto v0378;
    v0401 = qvalue(elt(env, 2)); // nil
    goto v0308;

v0308:
    if (v0401 == nil) goto v0302;
    v0401 = qvalue(elt(env, 5)); // t
    qvalue(elt(env, 4)) = v0401; // thirdway!*
    goto v0302;

v0302:
    v0401 = qvalue(elt(env, 1)); // gg!*
    stack[-4] = v0401;
    goto v0137;

v0137:
    v0401 = stack[-4];
    if (v0401 == nil) goto v0290;
    v0401 = stack[-4];
    v0401 = qcar(v0401);
    stack[-1] = v0401;
    v0402 = stack[-3];
    v0401 = stack[-1];
    v0401 = qcdr(v0401);
    fn = elt(env, 15); // dd
    stack[0] = (*qfn2(fn))(qenv(fn), v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0402 = stack[-7];
    v0401 = (LispObject)33; // 2
    v0401 = plus2(v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = (LispObject)geq2(stack[0], v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    v0401 = v0401 ? lisp_true : nil;
    env = stack[-9];
    if (v0401 == nil) goto v0404;
    v0402 = stack[-1];
    v0401 = qvalue(elt(env, 1)); // gg!*
    v0401 = Ldelete(nil, v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0401; // gg!*
    v0402 = stack[-1];
    v0401 = stack[-6];
    fn = elt(env, 16); // insert
    v0401 = (*qfn2(fn))(qenv(fn), v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    stack[-6] = v0401;
    v0360 = qvalue(elt(env, 11)); // bv!*
    v0401 = stack[-1];
    v0402 = qcar(v0401);
    v0401 = qvalue(elt(env, 5)); // t
    *(LispObject *)((char *)v0360 + (CELL-TAG_VECTOR) + ((int32_t)v0402/(16/CELL))) = v0401;
    goto v0404;

v0404:
    v0401 = stack[-4];
    v0401 = qcdr(v0401);
    stack[-4] = v0401;
    goto v0137;

v0290:
    v0402 = stack[-2];
    v0401 = stack[-3];
    v0402 = cons(v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = qvalue(elt(env, 1)); // gg!*
    fn = elt(env, 16); // insert
    v0401 = (*qfn2(fn))(qenv(fn), v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0401; // gg!*
    v0401 = qvalue(elt(env, 2)); // nil
    stack[-1] = v0401;
    goto v0171;

v0378:
    v0402 = stack[-5];
    v0401 = stack[-4];
    v0401 = Lneq(nil, v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    goto v0308;

v0124:
    v0402 = stack[-5];
    v0401 = qvalue(elt(env, 10)); // conds!*
    v0401 = cons(v0402, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    qvalue(elt(env, 10)) = v0401; // conds!*
    goto v0171;

v0403:
    v0401 = (LispObject)1; // 0
    goto v0206;

v0098:
    v0401 = stack[-4];
    fn = elt(env, 12); // ljet
    v0401 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = Lprinc(nil, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    v0401 = elt(env, 9); // " --> "
    v0401 = Lprinc(nil, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-9];
    goto v0193;

v0170:
    v0401 = qvalue(elt(env, 1)); // gg!*
    qvalue(elt(env, 1)) = stack[-8]; // gg!*
    { popv(10); return onevalue(v0401); }
// error exit handlers
v0231:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; // gg!*
    popv(10);
    return nil;
}



// Code for pa_list2vect

static LispObject CC_pa_list2vect(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0223, v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pa_list2vect");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0001;
    stack[0] = v0000;
// end of prologue
    stack[-4] = nil;
    v0223 = (LispObject)1; // 0
    stack[-3] = v0223;
    v0223 = stack[-5];
    v0223 = sub1(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    v0223 = Lmkvect(nil, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    stack[-6] = v0223;
    v0223 = stack[0];
    stack[-2] = v0223;
    goto v0108;

v0108:
    v0223 = stack[-2];
    if (v0223 == nil) goto v0109;
    v0223 = stack[-2];
    v0223 = qcar(v0223);
    stack[0] = v0223;
    v0085 = elt(env, 2); // min
    v0223 = stack[0];
    v0223 = cons(v0085, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    fn = elt(env, 3); // eval
    v0085 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    v0223 = stack[-4];
    v0223 = cons(v0085, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    stack[-4] = v0223;
    v0223 = stack[0];
    stack[-1] = v0223;
    goto v0155;

v0155:
    v0223 = stack[-1];
    if (v0223 == nil) goto v0173;
    v0223 = stack[-1];
    v0223 = qcar(v0223);
    stack[0] = stack[-6];
    v0085 = sub1(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    v0223 = stack[-4];
    v0223 = qcar(v0223);
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0085/(16/CELL))) = v0223;
    v0223 = stack[-1];
    v0223 = qcdr(v0223);
    stack[-1] = v0223;
    goto v0155;

v0173:
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    stack[-2] = v0223;
    goto v0108;

v0109:
    v0223 = (LispObject)17; // 1
    stack[-1] = v0223;
    goto v0203;

v0203:
    v0085 = stack[-5];
    v0223 = stack[-1];
    v0223 = difference2(v0085, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    v0223 = Lminusp(nil, v0223);
    env = stack[-7];
    if (v0223 == nil) goto v0206;
    v0223 = stack[-4];
    v0085 = Lreverse(nil, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    v0223 = stack[-6];
    popv(8);
    return cons(v0085, v0223);

v0206:
    stack[0] = stack[-6];
    v0223 = stack[-1];
    v0223 = sub1(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    v0223 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0223/(16/CELL)));
    if (!(v0223 == nil)) goto v0228;
    v0085 = stack[-3];
    v0223 = (LispObject)1; // 0
    if (!(v0085 == v0223)) goto v0233;
    v0223 = stack[-1];
    stack[-3] = v0223;
    v0085 = stack[-3];
    v0223 = stack[-4];
    v0223 = cons(v0085, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    stack[-4] = v0223;
    goto v0233;

v0233:
    stack[0] = stack[-6];
    v0223 = stack[-1];
    v0085 = sub1(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    v0223 = stack[-3];
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0085/(16/CELL))) = v0223;
    goto v0228;

v0228:
    v0223 = stack[-1];
    v0223 = add1(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-7];
    stack[-1] = v0223;
    goto v0203;
// error exit handlers
v0406:
    popv(8);
    return nil;
}



// Code for basic!-kern

static LispObject CC_basicKkern(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0167, v0102;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for basic-kern");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0102 = v0000;
// end of prologue
    v0167 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0167;
    v0167 = v0102;
    stack[0] = v0167;
    goto v0178;

v0178:
    v0167 = stack[0];
    if (v0167 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0167 = stack[0];
    v0167 = qcar(v0167);
    fn = elt(env, 2); // basic!-kern1
    v0102 = (*qfn1(fn))(qenv(fn), v0167);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-2];
    v0167 = stack[-1];
    fn = elt(env, 3); // union
    v0167 = (*qfn2(fn))(qenv(fn), v0102, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-2];
    stack[-1] = v0167;
    v0167 = stack[0];
    v0167 = qcdr(v0167);
    stack[0] = v0167;
    goto v0178;
// error exit handlers
v0150:
    popv(3);
    return nil;
}



// Code for check_letop

static LispObject CC_check_letop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0151, v0164;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for check_letop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0151 = v0000;
// end of prologue
    v0164 = v0151;
    v0151 = elt(env, 1); // letop
    fn = elt(env, 3); // freeof
    v0151 = (*qfn2(fn))(qenv(fn), v0164, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[0];
    if (v0151 == nil) goto v0004;
    v0151 = nil;
    { popv(1); return onevalue(v0151); }

v0004:
    v0151 = elt(env, 2); // "Presence of letop, jetspace too small!"
    {
        popv(1);
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(qenv(fn), v0151);
    }
// error exit handlers
v0196:
    popv(1);
    return nil;
}



// Code for lto_alunion

static LispObject CC_lto_alunion(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0122, v0175;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_alunion");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0122 = v0000;
// end of prologue
    v0175 = v0122;
    v0122 = elt(env, 1); // union
    {
        fn = elt(env, 2); // lto_almerge
        return (*qfn2(fn))(qenv(fn), v0175, v0122);
    }
}



// Code for fctargs

static LispObject CC_fctargs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0151, v0164;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fctargs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0151 = v0000;
// end of prologue
    v0164 = qvalue(elt(env, 1)); // depl!*
    v0164 = Lassoc(nil, v0151, v0164);
    v0151 = v0164;
    if (v0164 == nil) goto v0156;
    v0151 = qcdr(v0151);
    return onevalue(v0151);

v0156:
    v0151 = nil;
    return onevalue(v0151);
}



// Code for repr_new

static LispObject CC_repr_new(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0152, v0153, v0154, v0157;
    LispObject fn;
    LispObject v0009, v0147, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "repr_new");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0147 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repr_new");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0147,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0147,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0152 = v0009;
    v0153 = v0147;
    v0154 = v0001;
    v0157 = v0000;
// end of prologue
    stack[-3] = v0157;
    stack[-2] = v0154;
    stack[-1] = v0153;
    stack[0] = v0152;
    v0152 = v0153;
    if (v0152 == nil) goto v0163;
    v0152 = v0153;
    v0152 = qcar(v0152);
    v0152 = qcdr(v0152);
    goto v0171;

v0171:
    v0152 = list2(stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    {
        LispObject v0115 = stack[-3];
        LispObject v0099 = stack[-2];
        LispObject v0114 = stack[-1];
        popv(5);
        return list3star(v0115, v0099, v0114, v0152);
    }

v0163:
    v0152 = elt(env, 1); // "repr_new : invalid coefficient list"
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    fn = elt(env, 2); // rederr
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    goto v0171;
// error exit handlers
v0165:
    popv(5);
    return nil;
}



// Code for intervalrd

static LispObject CC_intervalrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0162, v0152;
    LispObject fn;
    argcheck(nargs, 0, "intervalrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intervalrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// end of prologue
    fn = elt(env, 4); // mathml
    v0162 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-2];
    stack[-1] = v0162;
    fn = elt(env, 4); // mathml
    v0162 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-2];
    stack[0] = v0162;
    fn = elt(env, 5); // lex
    v0162 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-2];
    v0152 = qvalue(elt(env, 1)); // char
    v0162 = elt(env, 2); // (!/ i n t e r v a l)
    if (equal(v0152, v0162)) goto v0186;
    v0152 = elt(env, 3); // "</interval>"
    v0162 = (LispObject)33; // 2
    fn = elt(env, 6); // errorml
    v0162 = (*qfn2(fn))(qenv(fn), v0152, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    v0162 = nil;
    { popv(3); return onevalue(v0162); }

v0186:
    v0152 = stack[-1];
    v0162 = stack[0];
    popv(3);
    return list2(v0152, v0162);
// error exit handlers
v0157:
    popv(3);
    return nil;
}



setup_type const u38_setup[] =
{
    {"*multf",                  too_few_2,      CC_Hmultf,     wrong_no_2},
    {"createsinglevariablemonom",CC_createsinglevariablemonom,too_many_1,wrong_no_1},
    {"fctlength",               CC_fctlength,   too_many_1,    wrong_no_1},
    {"pasf_smordtable",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smordtable},
    {"lowupperlimitrd",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowupperlimitrd},
    {"ldf-simp",                CC_ldfKsimp,    too_many_1,    wrong_no_1},
    {"simpimpart",              CC_simpimpart,  too_many_1,    wrong_no_1},
    {"suspend",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_suspend},
    {"vdpmember",               too_few_2,      CC_vdpmember,  wrong_no_2},
    {"evinsert",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evinsert},
    {"simpwedge",               CC_simpwedge,   too_many_1,    wrong_no_1},
    {"s_noparents",             CC_s_noparents, too_many_1,    wrong_no_1},
    {"pst_subpst",              too_few_2,      CC_pst_subpst, wrong_no_2},
    {"lpos",                    too_few_2,      CC_lpos,       wrong_no_2},
    {"get-current-representation",CC_getKcurrentKrepresentation,too_many_1,wrong_no_1},
    {"read-comment1",           CC_readKcomment1,too_many_1,   wrong_no_1},
    {"component_action",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_component_action},
    {"drop_rl_with",            too_few_2,      CC_drop_rl_with,wrong_no_2},
    {"giintgcd",                too_few_2,      CC_giintgcd,   wrong_no_2},
    {"orddf",                   too_few_2,      CC_orddf,      wrong_no_2},
    {"mri_2ofsfat",             CC_mri_2ofsfat, too_many_1,    wrong_no_1},
    {"sfto_qsubhor1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_sfto_qsubhor1},
    {"rl_multsurep",            too_few_2,      CC_rl_multsurep,wrong_no_2},
    {"matrixrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrd},
    {"compl",                   too_few_2,      CC_compl,      wrong_no_2},
    {"assgnpri",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_assgnpri},
    {"extbrsea",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_extbrsea},
    {"a2bc",                    CC_a2bc,        too_many_1,    wrong_no_1},
    {"applysetop",              too_few_2,      CC_applysetop, wrong_no_2},
    {"calc_atlas",              too_few_2,      CC_calc_atlas, wrong_no_2},
    {"*n2a",                    CC_Hn2a,        too_many_1,    wrong_no_1},
    {"appn",                    too_few_2,      CC_appn,       wrong_no_2},
    {"maxfrom",                 too_few_2,      CC_maxfrom,    wrong_no_2},
    {"pasf_fact",               CC_pasf_fact,   too_many_1,    wrong_no_1},
    {"upperlimitrd",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_upperlimitrd},
    {"prlist",                  CC_prlist,      too_many_1,    wrong_no_1},
    {"copy_mat",                CC_copy_mat,    too_many_1,    wrong_no_1},
    {"mkbc",                    too_few_2,      CC_mkbc,       wrong_no_2},
    {"mkupf",                   CC_mkupf,       too_many_1,    wrong_no_1},
    {"replace2_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace2_parents},
    {"formsetq0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq0},
    {"redall",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_redall},
    {"pa_list2vect",            too_few_2,      CC_pa_list2vect,wrong_no_2},
    {"basic-kern",              CC_basicKkern,  too_many_1,    wrong_no_1},
    {"check_letop",             CC_check_letop, too_many_1,    wrong_no_1},
    {"lto_alunion",             CC_lto_alunion, too_many_1,    wrong_no_1},
    {"fctargs",                 CC_fctargs,     too_many_1,    wrong_no_1},
    {"repr_new",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_repr_new},
    {"intervalrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_intervalrd},
    {NULL, (one_args *)"u38", (two_args *)"16361 6883712 2255581", 0}
};

// end of generated code
