
// $destdir/u20.c        Machine generated C code

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



// Code for indexvarordp

static LispObject CC_indexvarordp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0024, v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indexvarordp");
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
    v0024 = stack[-1];
    v0025 = qcar(v0024);
    v0024 = stack[0];
    v0024 = qcar(v0024);
    if (v0025 == v0024) goto v0026;
    v0024 = qvalue(elt(env, 1)); // t
    goto v0027;

v0027:
    if (v0024 == nil) goto v0028;
    v0025 = stack[-1];
    v0024 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // ordop
        return (*qfn2(fn))(qenv(fn), v0025, v0024);
    }

v0028:
    v0024 = stack[-1];
    v0024 = qcdr(v0024);
    fn = elt(env, 6); // flatindxl
    stack[-2] = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0024 = stack[0];
    v0024 = qcdr(v0024);
    fn = elt(env, 6); // flatindxl
    v0025 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0024 = stack[-2];
    stack[-2] = v0025;
    v0025 = v0024;
    v0024 = qvalue(elt(env, 3)); // indxl!*
    fn = elt(env, 7); // boundindp
    v0024 = (*qfn2(fn))(qenv(fn), v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    if (v0024 == nil) goto v0030;
    v0025 = stack[-2];
    v0024 = qvalue(elt(env, 3)); // indxl!*
    fn = elt(env, 7); // boundindp
    v0024 = (*qfn2(fn))(qenv(fn), v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    if (v0024 == nil) goto v0031;
    v0024 = stack[-1];
    v0025 = qcdr(v0024);
    v0024 = stack[0];
    v0024 = qcdr(v0024);
    {
        popv(4);
        fn = elt(env, 8); // indordlp
        return (*qfn2(fn))(qenv(fn), v0025, v0024);
    }

v0031:
    v0024 = qvalue(elt(env, 1)); // t
    { popv(4); return onevalue(v0024); }

v0030:
    v0025 = stack[-2];
    v0024 = qvalue(elt(env, 3)); // indxl!*
    fn = elt(env, 7); // boundindp
    v0024 = (*qfn2(fn))(qenv(fn), v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    if (v0024 == nil) goto v0032;
    v0024 = qvalue(elt(env, 4)); // nil
    { popv(4); return onevalue(v0024); }

v0032:
    v0025 = stack[-1];
    v0024 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // ordop
        return (*qfn2(fn))(qenv(fn), v0025, v0024);
    }

v0026:
    v0025 = stack[-1];
    v0024 = qvalue(elt(env, 2)); // kord!*
    v0024 = Lmemq(nil, v0025, v0024);
    if (!(v0024 == nil)) goto v0027;
    v0025 = stack[0];
    v0024 = qvalue(elt(env, 2)); // kord!*
    v0024 = Lmemq(nil, v0025, v0024);
    goto v0027;
// error exit handlers
v0029:
    popv(4);
    return nil;
}



// Code for inttovec!-solve

static LispObject CC_inttovecKsolve(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0044, v0045;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inttovec-solve");
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
    v0045 = stack[-2];
    v0044 = (LispObject)1; // 0
    if (v0045 == v0044) goto v0046;
    v0045 = stack[-3];
    v0044 = (LispObject)17; // 1
    v0044 = (v0045 == v0044 ? lisp_true : nil);
    goto v0027;

v0027:
    if (v0044 == nil) goto v0047;
    v0045 = stack[-2];
    v0044 = (LispObject)1; // 0
    popv(6);
    return cons(v0045, v0044);

v0047:
    v0044 = (LispObject)1; // 0
    stack[-4] = v0044;
    v0044 = (LispObject)17; // 1
    stack[0] = v0044;
    goto v0014;

v0014:
    v0044 = stack[0];
    stack[-1] = v0044;
    v0044 = stack[-4];
    v0044 = add1(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    stack[-4] = v0044;
    v0045 = stack[-3];
    v0044 = stack[-4];
    v0045 = plus2(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0044 = stack[-1];
    v0045 = times2(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0044 = stack[-4];
    v0044 = quot2(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    stack[0] = v0044;
    v0045 = stack[0];
    v0044 = stack[-2];
    v0044 = (LispObject)greaterp2(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    v0044 = v0044 ? lisp_true : nil;
    env = stack[-5];
    if (v0044 == nil) goto v0014;
    stack[0] = stack[-4];
    v0045 = stack[-2];
    v0044 = stack[-1];
    v0044 = difference2(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    {
        LispObject v0049 = stack[0];
        popv(6);
        return cons(v0049, v0044);
    }

v0046:
    v0044 = qvalue(elt(env, 1)); // t
    goto v0027;
// error exit handlers
v0048:
    popv(6);
    return nil;
}



// Code for begin1a

static LispObject CC_begin1a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086, v0087, v0088;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for begin1a");
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
    v0086 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0086; // otime!*
    v0086 = elt(env, 2); // gctime
    fn = elt(env, 55); // getd
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0086 == nil) goto v0090;
    v0086 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0086; // ogctime!*
    goto v0091;

v0091:
    v0086 = qvalue(elt(env, 1)); // otime!*
    qvalue(elt(env, 4)) = v0086; // otime3!*
    qvalue(elt(env, 5)) = v0086; // otime2!*
    qvalue(elt(env, 6)) = v0086; // otime1!*
    v0086 = qvalue(elt(env, 3)); // ogctime!*
    qvalue(elt(env, 7)) = v0086; // ogctime3!*
    qvalue(elt(env, 8)) = v0086; // ogctime2!*
    qvalue(elt(env, 9)) = v0086; // ogctime1!*
    v0086 = stack[0];
    qvalue(elt(env, 10)) = v0086; // peekchar!*
    v0086 = elt(env, 11); // !*semicol!*
    qvalue(elt(env, 12)) = v0086; // cursym!*
    v0086 = qvalue(elt(env, 13)); // nil
    qvalue(elt(env, 14)) = v0086; // curescaped!*
    goto v0016;

v0016:
    fn = elt(env, 56); // terminalp
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0086 == nil) goto v0092;
    v0086 = qvalue(elt(env, 15)); // !*nosave!*
    if (!(v0086 == nil)) goto v0041;
    v0087 = qvalue(elt(env, 16)); // statcounter
    v0086 = (LispObject)1; // 0
    if (v0087 == v0086) goto v0041;
    fn = elt(env, 57); // add2buflis
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0041;

v0041:
    fn = elt(env, 58); // update_prompt
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0092;

v0092:
    v0086 = qvalue(elt(env, 13)); // nil
    qvalue(elt(env, 15)) = v0086; // !*nosave!*
    v0086 = (LispObject)1; // 0
    qvalue(elt(env, 17)) = v0086; // !*strind
    v0086 = qvalue(elt(env, 13)); // nil
    stack[-1] = v0086;
    v0086 = qvalue(elt(env, 18)); // !*time
    if (v0086 == nil) goto v0093;
    v0086 = elt(env, 19); // (showtime)
    fn = elt(env, 59); // lispeval
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0093;

v0093:
    v0086 = qvalue(elt(env, 20)); // !*output
    if (v0086 == nil) goto v0038;
    v0086 = qvalue(elt(env, 21)); // ofl!*
    if (v0086 == nil) goto v0039;
    v0086 = qvalue(elt(env, 13)); // nil
    goto v0012;

v0012:
    if (v0086 == nil) goto v0038;
    v0086 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0038;

v0038:
    v0086 = qvalue(elt(env, 24)); // tslin!*
    if (v0086 == nil) goto v0094;
    v0086 = qvalue(elt(env, 24)); // tslin!*
    v0086 = qcar(v0086);
    qvalue(elt(env, 25)) = v0086; // !*slin
    v0086 = qvalue(elt(env, 24)); // tslin!*
    v0086 = qcdr(v0086);
    qvalue(elt(env, 26)) = v0086; // lreadfn!*
    v0086 = qvalue(elt(env, 13)); // nil
    qvalue(elt(env, 24)) = v0086; // tslin!*
    goto v0094;

v0094:
    v0086 = qvalue(elt(env, 27)); // initl!*
    stack[0] = v0086;
    goto v0027;

v0027:
    v0086 = stack[0];
    if (v0086 == nil) goto v0025;
    v0086 = stack[0];
    v0086 = qcar(v0086);
    fn = elt(env, 60); // sinitl
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    stack[0] = v0086;
    goto v0027;

v0025:
    v0087 = qvalue(elt(env, 28)); // forkeywords!*
    v0086 = elt(env, 29); // delim
    v0086 = Lremflag(nil, v0087, v0086);
    env = stack[-2];
    v0087 = qvalue(elt(env, 30)); // repeatkeywords!*
    v0086 = elt(env, 29); // delim
    v0086 = Lremflag(nil, v0087, v0086);
    env = stack[-2];
    v0087 = qvalue(elt(env, 31)); // whilekeywords!*
    v0086 = elt(env, 29); // delim
    v0086 = Lremflag(nil, v0087, v0086);
    env = stack[-2];
    v0086 = qvalue(elt(env, 32)); // !*int
    if (v0086 == nil) goto v0095;
    v0086 = qvalue(elt(env, 13)); // nil
    qvalue(elt(env, 33)) = v0086; // erfg!*
    goto v0095;

v0095:
    v0087 = qvalue(elt(env, 12)); // cursym!*
    v0086 = elt(env, 34); // end
    if (v0087 == v0086) goto v0096;
    fn = elt(env, 56); // terminalp
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0086 == nil) goto v0097;
    v0087 = qvalue(elt(env, 35)); // key!*
    v0086 = elt(env, 36); // ed
    if (v0087 == v0086) goto v0097;
    v0086 = qvalue(elt(env, 37)); // promptexp!*
    fn = elt(env, 61); // printprompt
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0097;

v0097:
    v0087 = elt(env, 38); // (command)
    v0086 = qvalue(elt(env, 39)); // t
    fn = elt(env, 62); // errorset!*
    v0086 = (*qfn2(fn))(qenv(fn), v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    stack[0] = v0086;
    fn = elt(env, 63); // condterpri
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0086 = stack[0];
    fn = elt(env, 64); // errorp
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0086 == nil) goto v0098;
    fn = elt(env, 65); // eofcheck
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (!(v0086 == nil)) goto v0046;
    v0087 = qvalue(elt(env, 46)); // eof!*
    v0086 = (LispObject)1; // 0
    v0086 = (LispObject)greaterp2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0086 = v0086 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0086 == nil)) goto v0046;
    v0087 = stack[0];
    v0086 = elt(env, 50); // "BEGIN invalid"
    if (equal(v0087, v0086)) goto v0016;
    v0086 = qvalue(elt(env, 39)); // t
    stack[-1] = v0086;
    goto v0099;

v0099:
    fn = elt(env, 66); // resetparser
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0100;

v0100:
    v0086 = qvalue(elt(env, 39)); // t
    qvalue(elt(env, 33)) = v0086; // erfg!*
    v0086 = qvalue(elt(env, 32)); // !*int
    if (v0086 == nil) goto v0101;
    v0086 = qvalue(elt(env, 13)); // nil
    goto v0102;

v0102:
    if (v0086 == nil) goto v0103;
    v0086 = qvalue(elt(env, 39)); // t
    qvalue(elt(env, 22)) = v0086; // !*defn
    v0086 = qvalue(elt(env, 39)); // t
    qvalue(elt(env, 52)) = v0086; // !*echo
    v0086 = qvalue(elt(env, 53)); // cmsg!*
    if (!(v0086 == nil)) goto v0104;
    v0086 = elt(env, 54); // "Continuing with parsing only ..."
    fn = elt(env, 67); // lprie
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0104;

v0104:
    v0086 = qvalue(elt(env, 39)); // t
    qvalue(elt(env, 53)) = v0086; // cmsg!*
    goto v0016;

v0103:
    v0086 = qvalue(elt(env, 51)); // !*errcont
    if (v0086 == nil) goto v0105;
    v0086 = qvalue(elt(env, 13)); // nil
    qvalue(elt(env, 33)) = v0086; // erfg!*
    goto v0016;

v0105:
    v0086 = stack[-1];
    fn = elt(env, 68); // pause1
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0088 = v0086;
    v0086 = v0088;
    if (v0086 == nil) goto v0106;
    v0086 = v0088;
    fn = elt(env, 59); // lispeval
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0086 = (v0086 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0086); }

v0106:
    v0086 = qvalue(elt(env, 13)); // nil
    qvalue(elt(env, 33)) = v0086; // erfg!*
    goto v0016;

v0101:
    v0086 = qvalue(elt(env, 51)); // !*errcont
    v0086 = (v0086 == nil ? lisp_true : nil);
    goto v0102;

v0046:
    v0086 = qvalue(elt(env, 44)); // crbuf1!*
    if (v0086 == nil) goto v0107;
    v0086 = elt(env, 45); // "Closing object improperly removed. Redo edit."
    fn = elt(env, 69); // lprim
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0086 = qvalue(elt(env, 13)); // nil
    qvalue(elt(env, 44)) = v0086; // crbuf1!*
    v0086 = qvalue(elt(env, 13)); // nil
    { popv(3); return onevalue(v0086); }

v0107:
    v0087 = qvalue(elt(env, 46)); // eof!*
    v0086 = (LispObject)65; // 4
    v0086 = (LispObject)greaterp2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0086 = v0086 ? lisp_true : nil;
    env = stack[-2];
    if (v0086 == nil) goto v0108;
    v0086 = elt(env, 47); // "End-of-file read"
    fn = elt(env, 69); // lprim
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0086 = elt(env, 48); // (bye)
    {
        popv(3);
        fn = elt(env, 59); // lispeval
        return (*qfn1(fn))(qenv(fn), v0086);
    }

v0108:
    fn = elt(env, 56); // terminalp
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0086 == nil) goto v0109;
    v0086 = qvalue(elt(env, 13)); // nil
    qvalue(elt(env, 49)) = v0086; // crbuf!*
    v0086 = qvalue(elt(env, 39)); // t
    qvalue(elt(env, 15)) = v0086; // !*nosave!*
    goto v0016;

v0109:
    v0086 = qvalue(elt(env, 13)); // nil
    { popv(3); return onevalue(v0086); }

v0098:
    v0086 = stack[0];
    v0086 = qcar(v0086);
    stack[0] = v0086;
    v0086 = stack[0];
    v0087 = qcar(v0086);
    v0086 = elt(env, 40); // symbolic
    if (v0087 == v0086) goto v0110;
    v0086 = qvalue(elt(env, 13)); // nil
    goto v0111;

v0111:
    if (v0086 == nil) goto v0112;
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    v0086 = qcar(v0086);
    fn = elt(env, 70); // eval
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    fn = elt(env, 71); // xmodloop
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0088 = v0086;
    goto v0113;

v0113:
    v0086 = v0088;
    if (v0086 == nil) goto v0016;
    v0087 = v0088;
    v0086 = elt(env, 34); // end
    if (v0087 == v0086) goto v0114;
    v0087 = v0088;
    v0086 = elt(env, 42); // err2
    if (v0087 == v0086) goto v0099;
    v0087 = v0088;
    v0086 = elt(env, 43); // err3
    if (v0087 == v0086) goto v0100;
    else goto v0046;

v0114:
    v0086 = qvalue(elt(env, 13)); // nil
    { popv(3); return onevalue(v0086); }

v0112:
    v0086 = stack[0];
    fn = elt(env, 72); // begin11
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0088 = v0086;
    goto v0113;

v0110:
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    v0087 = qcar(v0086);
    v0086 = elt(env, 41); // xmodule
    v0086 = Leqcar(nil, v0087, v0086);
    env = stack[-2];
    goto v0111;

v0096:
    v0086 = elt(env, 34); // end
    fn = elt(env, 73); // comm1
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0086 = qvalue(elt(env, 13)); // nil
    { popv(3); return onevalue(v0086); }

v0039:
    fn = elt(env, 56); // terminalp
    v0086 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0086 == nil) goto v0115;
    v0086 = qvalue(elt(env, 22)); // !*defn
    if (v0086 == nil) goto v0034;
    v0086 = qvalue(elt(env, 13)); // nil
    goto v0012;

v0034:
    v0086 = qvalue(elt(env, 23)); // !*lessspace
    v0086 = (v0086 == nil ? lisp_true : nil);
    goto v0012;

v0115:
    v0086 = qvalue(elt(env, 13)); // nil
    goto v0012;

v0090:
    v0086 = (LispObject)1; // 0
    qvalue(elt(env, 3)) = v0086; // ogctime!*
    goto v0091;
// error exit handlers
v0089:
    popv(3);
    return nil;
}



// Code for bas_newnumber

static LispObject CC_bas_newnumber(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0100, v0116;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bas_newnumber");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0100 = v0001;
    v0116 = v0000;
// end of prologue
    v0100 = qcdr(v0100);
    return cons(v0116, v0100);
}



// Code for xremainder!-mod!-p

static LispObject CC_xremainderKmodKp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0132, v0133, v0134;
    LispObject fn;
    LispObject v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xremainder-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xremainder-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0051;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0135:
    v0132 = stack[-2];
    if (!consp(v0132)) goto v0136;
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = (consp(v0132) ? nil : lisp_true);
    goto v0116;

v0116:
    if (v0132 == nil) goto v0092;
    v0132 = qvalue(elt(env, 1)); // t
    goto v0046;

v0046:
    if (!(v0132 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = qcdr(v0132);
    fn = elt(env, 2); // minus!-mod!-p
    v0133 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    v0132 = stack[-1];
    v0132 = qcar(v0132);
    v0132 = qcdr(v0132);
    fn = elt(env, 3); // quotient!-mod!-p
    v0132 = (*qfn2(fn))(qenv(fn), v0133, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-3] = v0132;
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0133 = qcdr(v0132);
    v0132 = stack[-1];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0132 = qcdr(v0132);
    v0132 = (LispObject)(int32_t)((int32_t)v0133 - (int32_t)v0132 + TAG_FIXNUM);
    v0134 = v0132;
    v0133 = v0134;
    v0132 = (LispObject)1; // 0
    if (v0133 == v0132) goto v0045;
    v0132 = stack[-2];
    stack[-2] = qcdr(v0132);
    v0132 = stack[-1];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0133 = v0134;
    fn = elt(env, 4); // mksp
    v0133 = (*qfn2(fn))(qenv(fn), v0132, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    v0132 = stack[-3];
    v0133 = cons(v0133, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    v0132 = stack[-1];
    v0132 = qcdr(v0132);
    fn = elt(env, 5); // times!-term!-mod!-p
    v0132 = (*qfn2(fn))(qenv(fn), v0133, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    fn = elt(env, 6); // plus!-mod!-p
    v0132 = (*qfn2(fn))(qenv(fn), stack[-2], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-2] = v0132;
    goto v0137;

v0137:
    v0134 = stack[-2];
    v0133 = stack[-1];
    v0132 = stack[0];
    stack[-2] = v0134;
    stack[-1] = v0133;
    stack[0] = v0132;
    goto v0135;

v0045:
    v0132 = stack[-2];
    stack[-2] = qcdr(v0132);
    v0132 = stack[-1];
    v0133 = qcdr(v0132);
    v0132 = stack[-3];
    fn = elt(env, 7); // multiply!-by!-constant!-mod!-p
    v0132 = (*qfn2(fn))(qenv(fn), v0133, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    fn = elt(env, 6); // plus!-mod!-p
    v0132 = (*qfn2(fn))(qenv(fn), stack[-2], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-2] = v0132;
    goto v0137;

v0092:
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0133 = qcar(v0132);
    v0132 = stack[0];
    if (equal(v0133, v0132)) goto v0138;
    v0132 = qvalue(elt(env, 1)); // t
    goto v0046;

v0138:
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0133 = qcdr(v0132);
    v0132 = stack[-1];
    v0132 = qcar(v0132);
    v0132 = qcar(v0132);
    v0132 = qcdr(v0132);
    v0132 = ((intptr_t)v0133 < (intptr_t)v0132) ? lisp_true : nil;
    goto v0046;

v0136:
    v0132 = qvalue(elt(env, 1)); // t
    goto v0116;
// error exit handlers
v0073:
    popv(5);
    return nil;
}



// Code for setk0

static LispObject CC_setk0(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0131, v0132, v0133, v0134;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setk0");
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
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // frasc!*
    qvalue(elt(env, 1)) = nil; // frasc!*
    v0131 = stack[-1];
    fn = elt(env, 8); // getrtype
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-3] = v0131;
    if (v0131 == nil) goto v0155;
    v0132 = stack[-3];
    v0131 = elt(env, 2); // setelemfn
    v0131 = get(v0132, v0131);
    env = stack[-4];
    if (v0131 == nil) goto v0155;
    v0131 = qvalue(elt(env, 3)); // nil
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    qvalue(elt(env, 4)) = v0131; // alglist!*
    v0134 = stack[-2];
    v0133 = stack[-1];
    v0132 = qvalue(elt(env, 3)); // nil
    v0131 = qvalue(elt(env, 5)); // t
    fn = elt(env, 9); // let2
    v0131 = (*qfnn(fn))(qenv(fn), 4, v0134, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    goto v0027;

v0027:
    v0131 = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // frasc!*
    { popv(5); return onevalue(v0131); }

v0155:
    v0131 = stack[-2];
    if (!consp(v0131)) goto v0156;
    v0131 = stack[-2];
    v0131 = qcar(v0131);
    if (symbolp(v0131)) goto v0157;
    v0131 = qvalue(elt(env, 3)); // nil
    goto v0158;

v0158:
    if (v0131 == nil) goto v0019;
    v0131 = qvalue(elt(env, 3)); // nil
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    qvalue(elt(env, 4)) = v0131; // alglist!*
    v0133 = stack[-3];
    v0132 = stack[-2];
    v0131 = stack[-1];
    v0131 = Lapply2(nil, 3, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    goto v0027;

v0019:
    v0131 = stack[-2];
    if (!consp(v0131)) goto v0079;
    v0131 = stack[-2];
    v0131 = qcar(v0131);
    if (!consp(v0131)) goto v0118;
    v0131 = stack[-2];
    v0131 = qcar(v0131);
    v0132 = qcar(v0131);
    v0131 = elt(env, 7); // setstructfn
    v0131 = get(v0132, v0131);
    env = stack[-4];
    stack[-3] = v0131;
    goto v0048;

v0048:
    if (v0131 == nil) goto v0122;
    v0131 = qvalue(elt(env, 3)); // nil
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    qvalue(elt(env, 4)) = v0131; // alglist!*
    v0133 = stack[-3];
    v0132 = stack[-2];
    v0131 = stack[-1];
    v0131 = Lapply2(nil, 3, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    goto v0027;

v0122:
    v0134 = stack[-2];
    v0133 = stack[-1];
    v0132 = qvalue(elt(env, 3)); // nil
    v0131 = qvalue(elt(env, 5)); // t
    fn = elt(env, 9); // let2
    v0131 = (*qfnn(fn))(qenv(fn), 4, v0134, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    goto v0027;

v0118:
    v0131 = qvalue(elt(env, 3)); // nil
    goto v0048;

v0079:
    v0131 = qvalue(elt(env, 3)); // nil
    goto v0048;

v0157:
    v0131 = stack[-2];
    fn = elt(env, 8); // getrtype
    v0131 = (*qfn1(fn))(qenv(fn), v0131);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    if (!(v0131 == nil)) goto v0159;
    v0131 = stack[-2];
    v0131 = qcar(v0131);
    if (!symbolp(v0131)) v0131 = nil;
    else { v0131 = qfastgets(v0131);
           if (v0131 != nil) { v0131 = elt(v0131, 2); // rtype
#ifdef RECORD_GET
             if (v0131 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0131 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0131 == SPID_NOPROP) v0131 = nil; }}
#endif
    goto v0159;

v0159:
    stack[-3] = v0131;
    if (v0131 == nil) goto v0121;
    v0132 = stack[-3];
    v0131 = elt(env, 2); // setelemfn
    v0131 = get(v0132, v0131);
    env = stack[-4];
    stack[-3] = v0131;
    goto v0006;

v0006:
    if (!(v0131 == nil)) goto v0158;
    v0131 = stack[-2];
    v0132 = qcar(v0131);
    v0131 = elt(env, 6); // setkfn
    v0131 = get(v0132, v0131);
    env = stack[-4];
    stack[-3] = v0131;
    goto v0158;

v0121:
    v0131 = qvalue(elt(env, 3)); // nil
    goto v0006;

v0156:
    v0131 = qvalue(elt(env, 3)); // nil
    goto v0158;
// error exit handlers
v0073:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; // frasc!*
    popv(5);
    return nil;
}



// Code for lalr_print_shortnum_vector

static LispObject CC_lalr_print_shortnum_vector(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0162, v0163;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_print_shortnum_vector");
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
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    v0162 = elt(env, 1); // !#!V16![
    stack[-2] = v0162;
    v0162 = (LispObject)1; // 0
    stack[0] = v0162;
    goto v0022;

v0022:
    v0162 = stack[-1];
    v0163 = Lupbv(nil, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0162 = stack[0];
    v0162 = difference2(v0163, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0162 = Lminusp(nil, v0162);
    env = stack[-3];
    if (v0162 == nil) goto v0100;
    v0162 = elt(env, 4); // !]
    v0162 = Lprinc(nil, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0162 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0100:
    v0162 = stack[-2];
    v0162 = Lprinc(nil, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0162 = elt(env, 3); // ! 
    stack[-2] = v0162;
    v0163 = stack[-1];
    v0162 = stack[0];
    fn = elt(env, 5); // getv16
    v0162 = (*qfn2(fn))(qenv(fn), v0163, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0162 = Lprin(nil, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0162 = stack[0];
    v0162 = add1(v0162);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[0] = v0162;
    goto v0022;
// error exit handlers
v0015:
    popv(4);
    return nil;
}



// Code for ofsf_varlat

static LispObject CC_ofsf_varlat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0165, v0166;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_varlat");
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
    v0165 = v0000;
// end of prologue
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    fn = elt(env, 3); // kernels
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-4];
    v0166 = v0165;
    v0165 = qvalue(elt(env, 1)); // !*rlbrkcxk
    if (v0165 == nil) { popv(5); return onevalue(v0166); }
    v0165 = v0166;
    stack[-3] = v0165;
    goto v0023;

v0023:
    v0165 = stack[-3];
    if (v0165 == nil) goto v0161;
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 4); // rltools_lpvarl
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-4];
    stack[-2] = v0165;
    v0165 = stack[-2];
    fn = elt(env, 5); // lastpair
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-4];
    stack[-1] = v0165;
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    v0165 = stack[-1];
    if (!consp(v0165)) goto v0023;
    else goto v0167;

v0167:
    v0165 = stack[-3];
    if (v0165 == nil) goto v0162;
    stack[0] = stack[-1];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 4); // rltools_lpvarl
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-4];
    v0165 = Lrplacd(nil, stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-4];
    v0165 = stack[-1];
    fn = elt(env, 5); // lastpair
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-4];
    stack[-1] = v0165;
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    goto v0167;

v0162:
    v0165 = stack[-2];
    goto v0168;

v0168:
    v0166 = v0165;
    { popv(5); return onevalue(v0166); }

v0161:
    v0165 = qvalue(elt(env, 2)); // nil
    goto v0168;
// error exit handlers
v0012:
    popv(5);
    return nil;
}



// Code for simpqg

static LispObject CC_simpqg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0155, v0099;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpqg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0155 = v0000;
// end of prologue
    v0099 = v0155;
    v0155 = elt(env, 1); // qg
    {
        fn = elt(env, 2); // simpcv
        return (*qfn2(fn))(qenv(fn), v0099, v0155);
    }
}



// Code for mkprod

static LispObject CC_mkprod(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0191, v0192;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkprod");
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
    stack[-4] = v0000;
// end of prologue
    stack[-2] = qvalue(elt(env, 1)); // !*exp
    qvalue(elt(env, 1)) = nil; // !*exp
    stack[-1] = qvalue(elt(env, 2)); // !*sub2
    qvalue(elt(env, 2)) = nil; // !*sub2
    v0191 = stack[-4];
    if (v0191 == nil) goto v0043;
    v0191 = stack[-4];
    fn = elt(env, 10); // kernlp
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    goto v0091;

v0091:
    if (v0191 == nil) goto v0099;
    v0191 = stack[-4];
    goto v0046;

v0046:
    qvalue(elt(env, 2)) = stack[-1]; // !*sub2
    qvalue(elt(env, 1)) = stack[-2]; // !*exp
    { popv(7); return onevalue(v0191); }

v0099:
    v0191 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 2)) = v0191; // !*sub2
    v0192 = stack[-4];
    v0191 = (LispObject)17; // 1
    v0191 = cons(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    fn = elt(env, 11); // subs2
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[0] = v0191;
    v0191 = stack[0];
    v0192 = qcdr(v0191);
    v0191 = (LispObject)17; // 1
    if (v0192 == v0191) goto v0028;
    v0191 = stack[-4];
    goto v0046;

v0028:
    v0191 = stack[0];
    v0192 = qcar(v0191);
    v0191 = stack[-4];
    if (equal(v0192, v0191)) goto v0040;
    v0191 = stack[0];
    v0191 = qcar(v0191);
    stack[-4] = v0191;
    v0191 = stack[-4];
    if (v0191 == nil) goto v0166;
    v0191 = stack[-4];
    fn = elt(env, 10); // kernlp
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    goto v0165;

v0165:
    if (v0191 == nil) goto v0040;
    v0191 = stack[-4];
    goto v0046;

v0040:
    v0191 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 1)) = v0191; // !*exp
    v0191 = stack[-4];
    fn = elt(env, 12); // ckrn
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[-5] = v0191;
    v0192 = stack[-4];
    v0191 = stack[-5];
    fn = elt(env, 13); // quotf
    v0191 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[-4] = v0191;
    v0191 = stack[-4];
    fn = elt(env, 14); // expnd
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[0] = v0191;
    v0191 = stack[0];
    if (v0191 == nil) goto v0031;
    v0191 = stack[0];
    fn = elt(env, 10); // kernlp
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    goto v0008;

v0008:
    if (v0191 == nil) goto v0124;
    v0192 = stack[-5];
    v0191 = stack[0];
    fn = elt(env, 15); // multf
    v0191 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    goto v0046;

v0124:
    v0191 = qvalue(elt(env, 4)); // !*mcd
    if (v0191 == nil) goto v0194;
    v0191 = qvalue(elt(env, 5)); // !*sqfree
    if (!(v0191 == nil)) goto v0195;
    v0191 = qvalue(elt(env, 6)); // !*factor
    if (!(v0191 == nil)) goto v0195;
    v0191 = qvalue(elt(env, 7)); // !*gcd
    if (!(v0191 == nil)) goto v0195;

v0194:
    v0191 = stack[0];
    fn = elt(env, 12); // ckrn
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[-3] = v0191;
    v0192 = stack[0];
    v0191 = stack[-3];
    fn = elt(env, 13); // quotf
    v0191 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[0] = v0191;
    v0192 = stack[0];
    v0191 = (LispObject)17; // 1
    v0191 = cons(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0191 = list2(stack[-3], v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[-3] = v0191;
    goto v0196;

v0196:
    v0191 = stack[-3];
    v0191 = qcdr(v0191);
    v0191 = qcar(v0191);
    v0192 = qcdr(v0191);
    v0191 = (LispObject)17; // 1
    v0191 = (LispObject)greaterp2(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0191 = v0191 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0191 == nil)) goto v0197;
    v0191 = stack[-3];
    v0191 = qcdr(v0191);
    v0191 = qcdr(v0191);
    if (!(v0191 == nil)) goto v0197;
    v0191 = qvalue(elt(env, 9)); // !*group
    if (v0191 == nil) goto v0067;
    v0191 = qvalue(elt(env, 8)); // nil
    goto v0198;

v0198:
    if (v0191 == nil) goto v0199;
    v0191 = stack[-3];
    v0191 = qcdr(v0191);
    v0191 = qcar(v0191);
    v0192 = qcar(v0191);
    v0191 = stack[-3];
    v0191 = qcdr(v0191);
    v0191 = qcar(v0191);
    v0191 = qcdr(v0191);
    fn = elt(env, 16); // mksp!*
    v0192 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0191 = stack[-3];
    v0191 = qcar(v0191);
    fn = elt(env, 15); // multf
    v0191 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[0] = v0191;
    goto v0200;

v0200:
    v0192 = stack[-5];
    v0191 = stack[0];
    fn = elt(env, 15); // multf
    v0191 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    goto v0046;

v0199:
    v0192 = stack[-4];
    v0191 = (LispObject)17; // 1
    fn = elt(env, 16); // mksp!*
    v0191 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[0] = v0191;
    goto v0200;

v0067:
    v0191 = stack[-4];
    fn = elt(env, 17); // tmsf
    stack[0] = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0191 = stack[-3];
    v0191 = qcdr(v0191);
    v0191 = qcar(v0191);
    v0191 = qcar(v0191);
    fn = elt(env, 17); // tmsf
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0191 = (LispObject)greaterp2(stack[0], v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0191 = v0191 ? lisp_true : nil;
    env = stack[-6];
    goto v0198;

v0197:
    v0191 = stack[-3];
    v0191 = qcar(v0191);
    stack[0] = v0191;
    v0191 = stack[-3];
    v0191 = qcdr(v0191);
    stack[-3] = v0191;
    goto v0201;

v0201:
    v0191 = stack[-3];
    if (v0191 == nil) goto v0200;
    v0191 = stack[-3];
    v0191 = qcar(v0191);
    v0192 = v0191;
    v0192 = qcar(v0192);
    v0191 = qcdr(v0191);
    fn = elt(env, 16); // mksp!*
    v0192 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    v0191 = stack[0];
    fn = elt(env, 15); // multf
    v0191 = (*qfn2(fn))(qenv(fn), v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[0] = v0191;
    v0191 = stack[-3];
    v0191 = qcdr(v0191);
    stack[-3] = v0191;
    goto v0201;

v0195:
    v0191 = stack[0];
    fn = elt(env, 18); // fctrf
    v0191 = (*qfn1(fn))(qenv(fn), v0191);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-6];
    stack[-3] = v0191;
    goto v0196;

v0031:
    v0191 = qvalue(elt(env, 3)); // t
    goto v0008;

v0166:
    v0191 = qvalue(elt(env, 3)); // t
    goto v0165;

v0043:
    v0191 = qvalue(elt(env, 3)); // t
    goto v0091;
// error exit handlers
v0193:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-1]; // !*sub2
    qvalue(elt(env, 1)) = stack[-2]; // !*exp
    popv(7);
    return nil;
}



// Code for ibalp_tvb

static LispObject CC_ibalp_tvb(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0126, v0202;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_tvb");
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
    stack[-1] = v0001;
    v0126 = v0000;
// end of prologue
    stack[-2] = v0126;
    goto v0160;

v0160:
    v0126 = stack[-2];
    if (v0126 == nil) goto v0155;
    v0126 = stack[-2];
    v0126 = qcar(v0126);
    stack[0] = v0126;
    v0126 = stack[0];
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0202 = qcar(v0126);
    v0126 = stack[-1];
    v0126 = (LispObject)geq2(v0202, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    v0126 = v0126 ? lisp_true : nil;
    env = stack[-3];
    if (v0126 == nil) goto v0168;
    v0126 = stack[0];
    v0202 = qcdr(v0126);
    v0126 = stack[0];
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0126 = qcar(v0126);
    fn = elt(env, 2); // ibalp_var!-unset
    v0126 = (*qfn2(fn))(qenv(fn), v0202, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    goto v0168;

v0168:
    v0126 = stack[-2];
    v0126 = qcdr(v0126);
    stack[-2] = v0126;
    goto v0160;

v0155:
    v0126 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0126); }
// error exit handlers
v0188:
    popv(4);
    return nil;
}



// Code for gb_buch!-ev_divides!?

static LispObject CC_gb_buchKev_dividesW(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0099, v0100;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gb_buch-ev_divides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0100 = v0001;
    v0099 = v0000;
// end of prologue
    {
        fn = elt(env, 1); // ev_mtest!?
        return (*qfn2(fn))(qenv(fn), v0100, v0099);
    }
}



// Code for diff!-over!-k!-mod!-p

static LispObject CC_diffKoverKkKmodKp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0182, v0210, v0097;
    LispObject fn;
    LispObject v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "diff-over-k-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diff-over-k-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0051;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0182 = stack[-2];
    if (!consp(v0182)) goto v0155;
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    v0182 = (consp(v0182) ? nil : lisp_true);
    goto v0046;

v0046:
    if (v0182 == nil) goto v0154;
    v0182 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0182); }

v0154:
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    v0210 = qcar(v0182);
    v0182 = stack[0];
    if (equal(v0210, v0182)) goto v0040;
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    v0097 = qcdr(v0182);
    v0210 = stack[-1];
    v0182 = stack[0];
    stack[-3] = CC_diffKoverKkKmodKp(env, 3, v0097, v0210, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    v0182 = stack[-2];
    v0097 = qcdr(v0182);
    v0210 = stack[-1];
    v0182 = stack[0];
    v0182 = CC_diffKoverKkKmodKp(env, 3, v0097, v0210, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    v0210 = stack[-3];
    v0097 = v0210;
    if (v0097 == nil) { popv(5); return onevalue(v0182); }
    v0097 = stack[-2];
    v0097 = qcar(v0097);
    v0097 = qcar(v0097);
    popv(5);
    return acons(v0097, v0210, v0182);

v0040:
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    v0210 = qcdr(v0182);
    v0182 = (LispObject)17; // 1
    if (v0210 == v0182) goto v0085;
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    v0182 = qcdr(v0182);
    v0210 = Lmodular_number(nil, v0182);
    env = stack[-4];
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    v0182 = qcdr(v0182);
    fn = elt(env, 3); // times!-mod!-p
    v0210 = (*qfn2(fn))(qenv(fn), v0210, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    v0182 = stack[-1];
    v0182 = Lmodular_number(nil, v0182);
    env = stack[-4];
    fn = elt(env, 4); // quotient!-mod!-p
    stack[-3] = (*qfn2(fn))(qenv(fn), v0210, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    v0182 = stack[-2];
    v0097 = qcdr(v0182);
    v0210 = stack[-1];
    v0182 = stack[0];
    v0182 = CC_diffKoverKkKmodKp(env, 3, v0097, v0210, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    stack[-1] = v0182;
    v0182 = stack[-3];
    if (v0182 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0210 = stack[0];
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    v0182 = qcdr(v0182);
    v0182 = (LispObject)((int32_t)(v0182) - 0x10);
    fn = elt(env, 5); // mksp
    v0097 = (*qfn2(fn))(qenv(fn), v0210, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    v0210 = stack[-3];
    v0182 = stack[-1];
    popv(5);
    return acons(v0097, v0210, v0182);

v0085:
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    v0210 = qcdr(v0182);
    v0182 = stack[-1];
    v0182 = Lmodular_number(nil, v0182);
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); // quotient!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0210, v0182);
    }

v0155:
    v0182 = qvalue(elt(env, 1)); // t
    goto v0046;
// error exit handlers
v0071:
    popv(5);
    return nil;
}



// Code for ir2mml

static LispObject CC_ir2mml(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0168;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ir2mml");
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
    v0168 = elt(env, 1); // (indent)
    fn = elt(env, 8); // fluid
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    v0168 = (LispObject)49; // 3
    qvalue(elt(env, 2)) = v0168; // ind
    v0168 = (LispObject)1; // 0
    qvalue(elt(env, 3)) = v0168; // indent
    v0168 = elt(env, 4); // "<math>"
    fn = elt(env, 9); // printout
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    v0168 = qvalue(elt(env, 5)); // t
    fn = elt(env, 10); // indent!*
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    v0168 = stack[0];
    fn = elt(env, 11); // expression
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    v0168 = qvalue(elt(env, 6)); // nil
    fn = elt(env, 10); // indent!*
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    v0168 = elt(env, 7); // "</math>"
    fn = elt(env, 9); // printout
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    v0168 = nil;
    { popv(2); return onevalue(v0168); }
// error exit handlers
v0167:
    popv(2);
    return nil;
}



// Code for rd!:prep

static LispObject CC_rdTprep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0161;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:prep");
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
    v0161 = qvalue(elt(env, 1)); // !*noconvert
    if (v0161 == nil) goto v0139;
    v0161 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // rdprep1
        return (*qfn1(fn))(qenv(fn), v0161);
    }

v0139:
    v0161 = stack[0];
    fn = elt(env, 3); // rd!:onep
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    if (v0161 == nil) goto v0155;
    v0161 = (LispObject)17; // 1
    { popv(2); return onevalue(v0161); }

v0155:
    v0161 = stack[0];
    fn = elt(env, 4); // rd!:minus
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    fn = elt(env, 3); // rd!:onep
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    if (v0161 == nil) goto v0167;
    v0161 = (LispObject)-15; // -1
    { popv(2); return onevalue(v0161); }

v0167:
    v0161 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // rdprep1
        return (*qfn1(fn))(qenv(fn), v0161);
    }
// error exit handlers
v0026:
    popv(2);
    return nil;
}



// Code for chk

static LispObject CC_chk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0212, v0009, v0010;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chk");
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

v0135:
    v0212 = stack[0];
    if (v0212 == nil) goto v0055;
    v0009 = stack[0];
    v0212 = qvalue(elt(env, 1)); // t
    if (v0009 == v0212) goto v0100;
    v0212 = stack[0];
    v0212 = qcar(v0212);
    fn = elt(env, 3); // bsubs
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    stack[-1] = v0212;
    v0212 = stack[-1];
    fn = elt(env, 4); // freexp
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    if (v0212 == nil) goto v0213;
    v0212 = stack[0];
    v0212 = qcdr(v0212);
    v0212 = CC_chk(env, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    v0009 = v0212;
    v0212 = v0009;
    if (v0212 == nil) goto v0019;
    v0212 = v0009;
    v0010 = qvalue(elt(env, 1)); // t
    if (v0212 == v0010) goto v0162;
    v0212 = stack[-1];
    popv(3);
    return cons(v0212, v0009);

v0162:
    v0212 = stack[-1];
    popv(3);
    return ncons(v0212);

v0019:
    v0212 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0212); }

v0213:
    v0212 = stack[-1];
    fn = elt(env, 5); // reval
    v0009 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    v0212 = qvalue(elt(env, 1)); // t
    if (v0009 == v0212) goto v0165;
    v0212 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0212); }

v0165:
    v0212 = stack[0];
    v0212 = qcdr(v0212);
    stack[0] = v0212;
    goto v0135;

v0100:
    v0212 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0212); }

v0055:
    v0212 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0212); }
// error exit handlers
v0035:
    popv(3);
    return nil;
}



// Code for expvec2a

static LispObject CC_expvec2a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0155, v0099;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expvec2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0155 = v0000;
// end of prologue
    v0099 = v0155;
    v0155 = qvalue(elt(env, 1)); // dipvars!*
    {
        fn = elt(env, 2); // expvec2a1
        return (*qfn2(fn))(qenv(fn), v0099, v0155);
    }
}



// Code for treesizep

static LispObject CC_treesizep(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0168, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for treesizep");
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
    v0168 = v0001;
    v0023 = v0000;
// end of prologue
    fn = elt(env, 1); // treesizep1
    v0023 = (*qfn2(fn))(qenv(fn), v0023, v0168);
    errexit();
    v0168 = (LispObject)1; // 0
    v0168 = (v0023 == v0168 ? lisp_true : nil);
    return onevalue(v0168);
}



// Code for ncoeffs

static LispObject CC_ncoeffs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0012, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ncoeffs");
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
// copy arguments values to proper place
    v0039 = v0000;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    v0012 = (LispObject)1; // 0
    stack[-2] = v0012;
    v0012 = v0039;
    stack[-1] = v0012;
    goto v0099;

v0099:
    v0012 = stack[-1];
    if (v0012 == nil) goto v0038;
    v0012 = stack[-1];
    v0012 = qcar(v0012);
    stack[0] = v0012;
    v0012 = stack[0];
    v0012 = qcar(v0012);
    stack[-4] = v0012;
    goto v0021;

v0021:
    v0039 = stack[-2];
    v0012 = stack[-4];
    v0012 = (LispObject)lessp2(v0039, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    v0012 = v0012 ? lisp_true : nil;
    env = stack[-5];
    if (v0012 == nil) goto v0215;
    v0039 = qvalue(elt(env, 1)); // nil
    v0012 = stack[-3];
    v0012 = cons(v0039, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    stack[-3] = v0012;
    v0012 = stack[-2];
    v0012 = add1(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    stack[-2] = v0012;
    goto v0021;

v0215:
    v0012 = stack[-2];
    v0012 = add1(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    stack[-2] = v0012;
    v0012 = stack[0];
    v0039 = qcdr(v0012);
    v0012 = stack[-3];
    v0012 = cons(v0039, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    stack[-3] = v0012;
    v0012 = stack[-1];
    v0012 = qcdr(v0012);
    stack[-1] = v0012;
    goto v0099;

v0038:
    v0039 = stack[-4];
    v0012 = stack[-3];
    popv(6);
    return cons(v0039, v0012);
// error exit handlers
v0209:
    popv(6);
    return nil;
}



// Code for next!-random!-number

static LispObject CC_nextKrandomKnumber(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0010, v0187, v0034, v0035;
    argcheck(nargs, 0, "next-random-number");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for next-random-number");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0187 = qvalue(elt(env, 1)); // unidev_next!*
    v0010 = (LispObject)865; // 54
    if (v0187 == v0010) goto v0160;
    v0010 = qvalue(elt(env, 1)); // unidev_next!*
    v0010 = (LispObject)((int32_t)(v0010) + 0x10);
    qvalue(elt(env, 1)) = v0010; // unidev_next!*
    goto v0161;

v0161:
    v0187 = qvalue(elt(env, 2)); // unidev_nextp!*
    v0010 = (LispObject)865; // 54
    if (v0187 == v0010) goto v0154;
    v0010 = qvalue(elt(env, 2)); // unidev_nextp!*
    v0010 = (LispObject)((int32_t)(v0010) + 0x10);
    qvalue(elt(env, 2)) = v0010; // unidev_nextp!*
    goto v0036;

v0036:
    v0187 = qvalue(elt(env, 3)); // unidev_vec!*
    v0010 = qvalue(elt(env, 1)); // unidev_next!*
    v0034 = *(LispObject *)((char *)v0187 + (CELL-TAG_VECTOR) + ((int32_t)v0010/(16/CELL)));
    v0187 = qvalue(elt(env, 3)); // unidev_vec!*
    v0010 = qvalue(elt(env, 2)); // unidev_nextp!*
    v0010 = *(LispObject *)((char *)v0187 + (CELL-TAG_VECTOR) + ((int32_t)v0010/(16/CELL)));
    v0010 = (LispObject)(int32_t)((int32_t)v0034 - (int32_t)v0010 + TAG_FIXNUM);
    v0034 = v0010;
    v0010 = v0034;
    v0010 = ((intptr_t)(v0010) < 0 ? lisp_true : nil);
    if (v0010 == nil) goto v0039;
    v0187 = v0034;
    v0010 = qvalue(elt(env, 4)); // randommodulus!*
    v0010 = (LispObject)(int32_t)((int32_t)v0187 + (int32_t)v0010 - TAG_FIXNUM);
    v0034 = v0010;
    goto v0039;

v0039:
    v0187 = qvalue(elt(env, 3)); // unidev_vec!*
    v0035 = qvalue(elt(env, 1)); // unidev_next!*
    v0010 = v0034;
    *(LispObject *)((char *)v0187 + (CELL-TAG_VECTOR) + ((int32_t)v0035/(16/CELL))) = v0010;
    return onevalue(v0034);

v0154:
    v0010 = (LispObject)1; // 0
    qvalue(elt(env, 2)) = v0010; // unidev_nextp!*
    goto v0036;

v0160:
    v0010 = (LispObject)1; // 0
    qvalue(elt(env, 1)) = v0010; // unidev_next!*
    goto v0161;
}



// Code for mk!-strand!-vertex2

static LispObject CC_mkKstrandKvertex2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0091, v0043, v0022;
    LispObject v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mk-strand-vertex2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk-strand-vertex2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0091 = v0051;
    v0043 = v0001;
    v0022 = v0000;
// end of prologue
    return list3(v0022, v0043, v0091);
}



// Code for expand!-imrepart

static LispObject CC_expandKimrepart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0037;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expand-imrepart");
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
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0160;

v0160:
    v0039 = stack[-1];
    if (!consp(v0039)) goto v0091;
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = (consp(v0039) ? nil : lisp_true);
    goto v0136;

v0136:
    if (v0039 == nil) goto v0020;
    v0037 = stack[-1];
    v0039 = (LispObject)17; // 1
    v0039 = cons(v0037, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    v0037 = v0039;
    goto v0027;

v0027:
    v0039 = stack[-2];
    if (v0039 == nil) { popv(4); return onevalue(v0037); }
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    fn = elt(env, 2); // addsq
    v0039 = (*qfn2(fn))(qenv(fn), v0039, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    v0037 = v0039;
    v0039 = stack[-2];
    v0039 = qcdr(v0039);
    stack[-2] = v0039;
    goto v0027;

v0020:
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    fn = elt(env, 3); // expand!-imrepartpow
    stack[0] = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = qcdr(v0039);
    v0039 = CC_expandKimrepart(env, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    fn = elt(env, 4); // multsq
    v0037 = (*qfn2(fn))(qenv(fn), stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    v0039 = stack[-2];
    v0039 = cons(v0037, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    stack[-2] = v0039;
    v0039 = stack[-1];
    v0039 = qcdr(v0039);
    stack[-1] = v0039;
    goto v0160;

v0091:
    v0039 = qvalue(elt(env, 1)); // t
    goto v0136;
// error exit handlers
v0115:
    popv(4);
    return nil;
}



// Code for rootrnd

static LispObject CC_rootrnd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0155, v0099;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rootrnd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0155 = v0000;
// end of prologue
    v0099 = v0155;
    v0155 = qvalue(elt(env, 1)); // acc!#
    {
        fn = elt(env, 2); // rtrnda
        return (*qfn2(fn))(qenv(fn), v0099, v0155);
    }
}



// Code for quotient!-mod!-p

static LispObject CC_quotientKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0095, v0204, v0120;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotient-mod-p");
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
    v0095 = stack[0];
    if (v0095 == nil) goto v0139;
    v0095 = stack[0];
    if (!consp(v0095)) goto v0136;
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = (consp(v0095) ? nil : lisp_true);
    goto v0116;

v0116:
    if (v0095 == nil) goto v0099;
    v0095 = stack[0];
    fn = elt(env, 5); // safe!-modular!-reciprocal
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-3];
    v0204 = stack[0];
    if (v0204 == nil) goto v0092;
    v0204 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0204, v0095);
    }

v0092:
    v0095 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0095; // exact!-quotient!-flag
    { popv(4); return onevalue(v0095); }

v0099:
    v0095 = stack[-1];
    if (v0095 == nil) goto v0162;
    v0095 = stack[-1];
    if (!consp(v0095)) goto v0202;
    v0095 = stack[-1];
    v0095 = qcar(v0095);
    v0095 = (consp(v0095) ? nil : lisp_true);
    goto v0126;

v0126:
    if (v0095 == nil) goto v0038;
    v0095 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0095; // exact!-quotient!-flag
    { popv(4); return onevalue(v0095); }

v0038:
    v0095 = stack[-1];
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    v0204 = qcar(v0095);
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    if (equal(v0204, v0095)) goto v0209;
    v0095 = stack[-1];
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    v0204 = qcar(v0095);
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    fn = elt(env, 7); // ordop
    v0095 = (*qfn2(fn))(qenv(fn), v0204, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-3];
    if (v0095 == nil) goto v0205;
    v0095 = stack[-1];
    v0095 = qcar(v0095);
    v0204 = qcdr(v0095);
    v0095 = stack[0];
    stack[-2] = CC_quotientKmodKp(env, v0204, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-3];
    v0095 = stack[-1];
    v0204 = qcdr(v0095);
    v0095 = stack[0];
    v0095 = CC_quotientKmodKp(env, v0204, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    v0204 = stack[-2];
    v0120 = v0204;
    if (v0120 == nil) { popv(4); return onevalue(v0095); }
    v0120 = stack[-1];
    v0120 = qcar(v0120);
    v0120 = qcar(v0120);
    popv(4);
    return acons(v0120, v0204, v0095);

v0205:
    v0095 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0095; // exact!-quotient!-flag
    { popv(4); return onevalue(v0095); }

v0209:
    v0120 = stack[-1];
    v0204 = stack[0];
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    v0095 = qcar(v0095);
    {
        popv(4);
        fn = elt(env, 8); // xquotient!-mod!-p
        return (*qfnn(fn))(qenv(fn), 3, v0120, v0204, v0095);
    }

v0202:
    v0095 = qvalue(elt(env, 2)); // t
    goto v0126;

v0162:
    v0095 = qvalue(elt(env, 3)); // nil
    { popv(4); return onevalue(v0095); }

v0136:
    v0095 = qvalue(elt(env, 2)); // t
    goto v0116;

v0139:
    v0095 = elt(env, 1); // "B=0 IN QUOTIENT-MOD-P"
    {
        popv(4);
        fn = elt(env, 9); // errorf
        return (*qfn1(fn))(qenv(fn), v0095);
    }
// error exit handlers
v0075:
    popv(4);
    return nil;
}



// Code for cde_delete

static LispObject CC_cde_delete(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0138, v0162, v0163, v0084;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cde_delete");
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
    v0138 = v0001;
    stack[0] = v0000;
// end of prologue
    v0084 = nil;
    stack[-1] = v0138;
    goto v0046;

v0046:
    v0138 = stack[-1];
    if (v0138 == nil) goto v0027;
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    v0163 = v0138;
    v0162 = v0163;
    v0138 = stack[0];
    if (equal(v0162, v0138)) goto v0090;
    v0138 = v0163;
    v0162 = v0084;
    v0138 = cons(v0138, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0084 = v0138;
    goto v0090;

v0090:
    v0138 = stack[-1];
    v0138 = qcdr(v0138);
    stack[-1] = v0138;
    goto v0046;

v0027:
    v0138 = v0084;
        popv(3);
        return Lnreverse(nil, v0138);
// error exit handlers
v0015:
    popv(3);
    return nil;
}



// Code for sfto_sqfpartf

static LispObject CC_sfto_sqfpartf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0165, v0166;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_sqfpartf");
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
// copy arguments values to proper place
    stack[-3] = v0000;
// end of prologue
    v0165 = stack[-3];
    if (!consp(v0165)) goto v0100;
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    v0165 = (consp(v0165) ? nil : lisp_true);
    goto v0099;

v0099:
    if (v0165 == nil) goto v0016;
    v0165 = (LispObject)17; // 1
    { popv(6); return onevalue(v0165); }

v0016:
    v0165 = stack[-3];
    fn = elt(env, 2); // sfto_ucontentf
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-5];
    stack[0] = v0165;
    v0166 = stack[-3];
    v0165 = stack[0];
    fn = elt(env, 3); // quotf
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-5];
    stack[-4] = v0165;
    v0165 = stack[0];
    stack[-2] = CC_sfto_sqfpartf(env, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-4];
    v0166 = stack[-4];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    v0165 = qcar(v0165);
    v0165 = qcar(v0165);
    fn = elt(env, 4); // diff
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-5];
    fn = elt(env, 5); // sfto_gcdf!*
    v0165 = (*qfn2(fn))(qenv(fn), stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-5];
    fn = elt(env, 3); // quotf
    v0165 = (*qfn2(fn))(qenv(fn), stack[-1], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-5];
    {
        LispObject v0037 = stack[-2];
        popv(6);
        fn = elt(env, 6); // multf
        return (*qfn2(fn))(qenv(fn), v0037, v0165);
    }

v0100:
    v0165 = qvalue(elt(env, 1)); // t
    goto v0099;
// error exit handlers
v0039:
    popv(6);
    return nil;
}



// Code for sq2sstm

static LispObject CC_sq2sstm(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0048, v0049, v0032;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sq2sstm");
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
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0001;
    v0032 = v0000;
// end of prologue
    v0048 = v0032;
    v0048 = qcar(v0048);
    v0049 = qcar(v0048);
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    v0048 = qcar(v0048);
    if (equal(v0049, v0048)) goto v0155;
    v0048 = v0032;
    stack[-1] = ncons(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    stack[0] = qcdr(v0048);
    v0048 = stack[-2];
    v0048 = qcdr(v0048);
    v0048 = sub1(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    v0048 = cons(stack[0], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    fn = elt(env, 2); // sq2sscfpl
    v0048 = (*qfn2(fn))(qenv(fn), stack[-1], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    v0049 = (LispObject)1; // 0
    stack[-3] = v0049;
    goto v0044;

v0044:
    v0049 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // mapins
        return (*qfn2(fn))(qenv(fn), v0049, v0048);
    }

v0155:
    v0048 = v0032;
    v0048 = qcdr(v0048);
    stack[0] = v0048;
    v0048 = v0032;
    v0048 = qcar(v0048);
    v0048 = qcdr(v0048);
    stack[-3] = v0048;
    v0048 = stack[0];
    if (!consp(v0048)) goto v0190;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0048 = (consp(v0048) ? nil : lisp_true);
    goto v0189;

v0189:
    if (v0048 == nil) goto v0121;
    stack[-1] = stack[-3];
    v0048 = stack[-2];
    v0048 = qcdr(v0048);
    fn = elt(env, 4); // mkzl
    v0049 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    v0048 = stack[0];
    v0048 = acons(stack[-1], v0049, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    popv(5);
    return ncons(v0048);

v0121:
    stack[-1] = stack[0];
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    stack[0] = qcdr(v0048);
    v0048 = stack[-2];
    v0048 = qcdr(v0048);
    v0048 = sub1(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    v0048 = cons(stack[0], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    fn = elt(env, 2); // sq2sscfpl
    v0048 = (*qfn2(fn))(qenv(fn), stack[-1], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    goto v0044;

v0190:
    v0048 = qvalue(elt(env, 1)); // t
    goto v0189;
// error exit handlers
v0002:
    popv(5);
    return nil;
}



// Code for ev_invlexcomp

static LispObject CC_ev_invlexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0124, v0156;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_invlexcomp");
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

v0135:
    v0124 = stack[-1];
    if (v0124 == nil) goto v0027;
    v0124 = stack[-1];
    v0156 = qcar(v0124);
    v0124 = stack[0];
    v0124 = qcar(v0124);
    fn = elt(env, 1); // iequal
    v0124 = (*qfn2(fn))(qenv(fn), v0156, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    if (v0124 == nil) goto v0047;
    v0124 = stack[-1];
    v0156 = qcdr(v0124);
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    stack[-1] = v0156;
    stack[0] = v0124;
    goto v0135;

v0047:
    v0124 = stack[-1];
    v0156 = qcdr(v0124);
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    v0124 = CC_ev_invlexcomp(env, v0156, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    stack[-2] = v0124;
    v0156 = stack[-2];
    v0124 = (LispObject)1; // 0
    fn = elt(env, 1); // iequal
    v0124 = (*qfn2(fn))(qenv(fn), v0156, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    if (v0124 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0124 = stack[0];
    v0156 = qcar(v0124);
    v0124 = stack[-1];
    v0124 = qcar(v0124);
    fn = elt(env, 1); // iequal
    v0124 = (*qfn2(fn))(qenv(fn), v0156, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    if (v0124 == nil) goto v0209;
    v0124 = (LispObject)1; // 0
    { popv(4); return onevalue(v0124); }

v0209:
    v0124 = stack[0];
    v0156 = qcar(v0124);
    v0124 = stack[-1];
    v0124 = qcar(v0124);
    if (((int32_t)(v0156)) > ((int32_t)(v0124))) goto v0125;
    v0124 = (LispObject)-15; // -1
    { popv(4); return onevalue(v0124); }

v0125:
    v0124 = (LispObject)17; // 1
    { popv(4); return onevalue(v0124); }

v0027:
    v0124 = (LispObject)1; // 0
    { popv(4); return onevalue(v0124); }
// error exit handlers
v0031:
    popv(4);
    return nil;
}



// Code for quotofd

static LispObject CC_quotofd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0217, v0214;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotofd");
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
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0160;

v0160:
    v0217 = stack[-2];
    if (v0217 == nil) goto v0046;
    v0217 = stack[-2];
    if (!consp(v0217)) goto v0168;
    v0217 = stack[-2];
    v0217 = qcar(v0217);
    v0217 = (consp(v0217) ? nil : lisp_true);
    goto v0022;

v0022:
    if (v0217 == nil) goto v0163;
    stack[0] = stack[-3];
    v0214 = stack[-2];
    v0217 = stack[-1];
    fn = elt(env, 2); // quotodd
    v0217 = (*qfn2(fn))(qenv(fn), v0214, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-4];
    {
        LispObject v0083 = stack[0];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0083, v0217);
    }

v0163:
    v0217 = stack[-2];
    v0217 = qcar(v0217);
    stack[0] = qcar(v0217);
    v0217 = stack[-2];
    v0217 = qcar(v0217);
    v0214 = qcdr(v0217);
    v0217 = stack[-1];
    v0214 = CC_quotofd(env, v0214, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-4];
    v0217 = stack[-3];
    v0217 = acons(stack[0], v0214, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-4];
    stack[-3] = v0217;
    v0217 = stack[-2];
    v0217 = qcdr(v0217);
    stack[-2] = v0217;
    goto v0160;

v0168:
    v0217 = qvalue(elt(env, 1)); // t
    goto v0022;

v0046:
    v0217 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0217);
    }
// error exit handlers
v0211:
    popv(5);
    return nil;
}



// Code for dipcondense

static LispObject CC_dipcondense(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007, v0186;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipcondense");
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
    v0007 = qvalue(elt(env, 1)); // dipevlist!*
    stack[-3] = v0007;
    goto v0046;

v0046:
    v0007 = stack[-2];
    if (v0007 == nil) goto v0027;
    v0007 = stack[-2];
    v0007 = qcar(v0007);
    stack[-1] = v0007;
    goto v0167;

v0167:
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    if (v0007 == nil) goto v0023;
    v0007 = stack[-2];
    v0186 = qcar(v0007);
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    fn = elt(env, 3); // evcompless!?
    v0007 = (*qfn2(fn))(qenv(fn), v0186, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-4];
    if (v0007 == nil) goto v0023;
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    stack[-3] = v0007;
    goto v0167;

v0023:
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    if (v0007 == nil) goto v0037;
    v0186 = stack[-1];
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    if (!(equal(v0186, v0007))) goto v0037;
    v0186 = stack[-2];
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    fn = elt(env, 4); // setcar
    v0007 = (*qfn2(fn))(qenv(fn), v0186, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-4];
    goto v0162;

v0162:
    v0007 = stack[-2];
    v0007 = qcdr(v0007);
    v0007 = qcdr(v0007);
    stack[-2] = v0007;
    goto v0046;

v0037:
    stack[0] = stack[-3];
    v0186 = stack[-1];
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    v0007 = cons(v0186, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-4];
    fn = elt(env, 5); // setcdr
    v0007 = (*qfn2(fn))(qenv(fn), stack[0], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-4];
    goto v0162;

v0027:
    v0007 = nil;
    { popv(5); return onevalue(v0007); }
// error exit handlers
v0222:
    popv(5);
    return nil;
}



// Code for dipevlcomp

static LispObject CC_dipevlcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0136, v0091;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipevlcomp");
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
    v0136 = v0001;
    v0091 = v0000;
// end of prologue
    v0091 = qcar(v0091);
    v0136 = qcar(v0136);
    fn = elt(env, 1); // evcompless!?
    v0136 = (*qfn2(fn))(qenv(fn), v0091, v0136);
    errexit();
    v0136 = (v0136 == nil ? lisp_true : nil);
    return onevalue(v0136);
}



// Code for coposp

static LispObject CC_coposp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0215, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0026 = v0000;
// end of prologue
    v0215 = v0026;
    v0215 = qcdr(v0215);
    if (v0215 == nil) goto v0055;
    v0215 = v0026;
    v0215 = qcar(v0215);
    if (!consp(v0215)) goto v0116;
    v0215 = v0026;
    v0215 = qcdr(v0215);
    {
        fn = elt(env, 2); // covposp
        return (*qfn1(fn))(qenv(fn), v0215);
    }

v0116:
    v0215 = v0026;
    v0215 = qcdr(v0215);
    {
        fn = elt(env, 3); // contposp
        return (*qfn1(fn))(qenv(fn), v0215);
    }

v0055:
    v0215 = qvalue(elt(env, 1)); // t
    return onevalue(v0215);
}



// Code for nfactorial

static LispObject CC_nfactorial(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0013, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nfactorial");
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
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    v0006 = stack[-1];
    v0013 = (LispObject)321; // 20
    v0013 = (LispObject)greaterp2(v0006, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    v0013 = v0013 ? lisp_true : nil;
    env = stack[-3];
    if (v0013 == nil) goto v0154;
    v0006 = (LispObject)17; // 1
    v0013 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); // fac!-part
        return (*qfn2(fn))(qenv(fn), v0006, v0013);
    }

v0154:
    v0013 = (LispObject)17; // 1
    stack[-2] = v0013;
    v0013 = (LispObject)17; // 1
    stack[0] = v0013;
    goto v0018;

v0018:
    v0006 = stack[-1];
    v0013 = stack[0];
    v0013 = difference2(v0006, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    v0013 = Lminusp(nil, v0013);
    env = stack[-3];
    if (!(v0013 == nil)) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0006 = stack[-2];
    v0013 = stack[0];
    v0013 = times2(v0006, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    stack[-2] = v0013;
    v0013 = stack[0];
    v0013 = add1(v0013);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-3];
    stack[0] = v0013;
    goto v0018;
// error exit handlers
v0159:
    popv(4);
    return nil;
}



// Code for lpriw

static LispObject CC_lpriw(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0011, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lpriw");
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
    v0012 = v0001;
    stack[0] = v0000;
// end of prologue
    stack[-1] = nil;
    v0011 = v0012;
    if (v0011 == nil) goto v0026;
    v0011 = v0012;
    if (!(!consp(v0011))) goto v0026;
    v0011 = v0012;
    v0011 = ncons(v0011);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    goto v0116;

v0116:
    v0011 = cons(stack[0], v0011);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    stack[0] = v0011;
    v0011 = qvalue(elt(env, 1)); // ofl!*
    if (v0011 == nil) goto v0092;
    v0011 = qvalue(elt(env, 2)); // !*fort
    if (!(v0011 == nil)) goto v0027;
    v0011 = qvalue(elt(env, 3)); // !*nat
    if (v0011 == nil) goto v0036;
    v0011 = qvalue(elt(env, 5)); // !*defn
    goto v0019;

v0019:
    if (!(v0011 == nil)) goto v0027;

v0092:
    v0011 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    goto v0160;

v0160:
    v0011 = stack[0];
    fn = elt(env, 7); // lpri
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    v0011 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    v0011 = stack[-1];
    if (v0011 == nil) goto v0016;
    v0011 = stack[-1];
    v0011 = qcdr(v0011);
    v0011 = Lwrs(nil, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    v0011 = qvalue(elt(env, 6)); // nil
    { popv(3); return onevalue(v0011); }

v0016:
    v0011 = qvalue(elt(env, 1)); // ofl!*
    if (!(v0011 == nil)) goto v0027;
    v0011 = qvalue(elt(env, 6)); // nil
    { popv(3); return onevalue(v0011); }

v0027:
    v0011 = qvalue(elt(env, 1)); // ofl!*
    stack[-1] = v0011;
    v0011 = qvalue(elt(env, 6)); // nil
    v0011 = Lwrs(nil, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    goto v0160;

v0036:
    v0011 = qvalue(elt(env, 4)); // t
    goto v0019;

v0026:
    v0011 = v0012;
    goto v0116;
// error exit handlers
v0211:
    popv(3);
    return nil;
}



// Code for mv!-domainlist

static LispObject CC_mvKdomainlist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0224;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-domainlist");
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
    v0224 = nil;
    goto v0139;

v0139:
    v0042 = stack[0];
    if (v0042 == nil) goto v0027;
    v0042 = stack[0];
    v0042 = qcar(v0042);
    v0042 = qcdr(v0042);
    v0042 = cons(v0042, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0224 = v0042;
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0139;

v0027:
    v0042 = v0224;
    {
        popv(2);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0042);
    }
// error exit handlers
v0092:
    popv(2);
    return nil;
}



// Code for rnprep!:

static LispObject CC_rnprepT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0047, v0128, v0018;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnprep:");
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
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    v0047 = qcar(v0047);
    fn = elt(env, 2); // prepf
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0018 = v0047;
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    v0128 = qcdr(v0047);
    v0047 = (LispObject)17; // 1
    if (v0128 == v0047) { popv(4); return onevalue(v0018); }
    stack[-2] = elt(env, 1); // quotient
    stack[0] = v0018;
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    v0047 = qcdr(v0047);
    fn = elt(env, 2); // prepf
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    {
        LispObject v0162 = stack[-2];
        LispObject v0163 = stack[0];
        popv(4);
        return list3(v0162, v0163, v0047);
    }
// error exit handlers
v0138:
    popv(4);
    return nil;
}



// Code for gfk

static LispObject CC_gfk(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0209, v0151, v0152, v0212, v0009, v0010;
    LispObject v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gfk");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0212 = v0051;
    v0009 = v0001;
    v0209 = v0000;
// end of prologue

v0135:
    v0151 = v0212;
    if (!(v0151 == nil)) { popv(3); return onevalue(v0212); }
    v0151 = v0209;
    if (!consp(v0151)) goto v0116;
    v0151 = v0209;
    v0151 = qcar(v0151);
    v0151 = (consp(v0151) ? nil : lisp_true);
    goto v0100;

v0100:
    if (!(v0151 == nil)) { popv(3); return onevalue(v0212); }
    v0151 = v0209;
    v0151 = qcar(v0151);
    v0151 = qcar(v0151);
    v0151 = qcar(v0151);
    v0010 = v0151;
    v0151 = v0209;
    stack[-1] = qcdr(v0151);
    stack[0] = v0009;
    v0209 = qcar(v0209);
    v0152 = qcdr(v0209);
    v0151 = v0009;
    v0209 = v0010;
    if (!consp(v0209)) goto v0012;
    v0209 = v0010;
    v0209 = qcar(v0209);
    v0209 = Lmember(nil, v0209, v0009);
    goto v0013;

v0013:
    if (v0209 == nil) goto v0083;
    v0209 = v0010;
    goto v0085;

v0085:
    v0151 = CC_gfk(env, 3, v0152, v0151, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    v0209 = stack[-1];
    v0009 = stack[0];
    v0212 = v0151;
    goto v0135;

v0083:
    v0209 = v0212;
    goto v0085;

v0012:
    v0209 = qvalue(elt(env, 2)); // nil
    goto v0013;

v0116:
    v0151 = qvalue(elt(env, 1)); // t
    goto v0100;
// error exit handlers
v0035:
    popv(3);
    return nil;
}



// Code for ordered!-gcd!-mod!-p

static LispObject CC_orderedKgcdKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0152, v0212;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordered-gcd-mod-p");
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
    v0152 = (LispObject)1; // 0
    stack[-2] = v0152;
    goto v0046;

v0046:
    v0212 = stack[-1];
    v0152 = stack[0];
    fn = elt(env, 3); // reduce!-degree!-mod!-p
    v0152 = (*qfn2(fn))(qenv(fn), v0212, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-3];
    stack[-1] = v0152;
    v0152 = stack[-1];
    if (v0152 == nil) goto v0168;
    v0152 = stack[-2];
    v0152 = add1(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-3];
    stack[-2] = v0152;
    v0152 = stack[-1];
    if (!consp(v0152)) goto v0020;
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = (consp(v0152) ? nil : lisp_true);
    goto v0092;

v0092:
    if (v0152 == nil) goto v0202;
    v0212 = qvalue(elt(env, 2)); // reduction!-count
    v0152 = stack[-2];
    v0152 = plus2(v0212, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0152; // reduction!-count
    v0152 = (LispObject)17; // 1
    { popv(4); return onevalue(v0152); }

v0202:
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = qcar(v0152);
    v0212 = qcdr(v0152);
    v0152 = stack[0];
    v0152 = qcar(v0152);
    v0152 = qcar(v0152);
    v0152 = qcdr(v0152);
    v0152 = (LispObject)lessp2(v0212, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    v0152 = v0152 ? lisp_true : nil;
    env = stack[-3];
    if (v0152 == nil) goto v0046;
    v0212 = qvalue(elt(env, 2)); // reduction!-count
    v0152 = stack[-2];
    v0152 = plus2(v0212, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0152; // reduction!-count
    v0152 = (LispObject)1; // 0
    stack[-2] = v0152;
    v0152 = stack[-1];
    v0212 = v0152;
    v0152 = stack[0];
    stack[-1] = v0152;
    v0152 = v0212;
    stack[0] = v0152;
    goto v0046;

v0020:
    v0152 = qvalue(elt(env, 1)); // t
    goto v0092;

v0168:
    v0152 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); // monic!-mod!-p
        return (*qfn1(fn))(qenv(fn), v0152);
    }
// error exit handlers
v0034:
    popv(4);
    return nil;
}



// Code for dfprint

static LispObject CC_dfprint(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfprint");
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
    v0014 = qvalue(elt(env, 1)); // dfprint!*
    if (v0014 == nil) goto v0139;
    stack[-1] = qvalue(elt(env, 1)); // dfprint!*
    v0014 = stack[0];
    v0014 = ncons(v0014);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    {
        LispObject v0157 = stack[-1];
        popv(3);
        fn = elt(env, 5); // lispapply
        return (*qfn2(fn))(qenv(fn), v0157, v0014);
    }

v0139:
    v0014 = qvalue(elt(env, 2)); // cmsg!*
    if (v0014 == nil) goto v0017;
    v0014 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0014); }

v0017:
    v0015 = stack[0];
    v0014 = elt(env, 4); // progn
    if (!consp(v0015)) goto v0167;
    v0015 = qcar(v0015);
    if (!(v0015 == v0014)) goto v0167;

v0040:
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    v0014 = stack[0];
    if (v0014 == nil) goto v0036;
    v0014 = stack[0];
    v0014 = qcar(v0014);
    v0014 = CC_dfprint(env, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    goto v0040;

v0036:
    v0014 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0014); }

v0167:
    v0014 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); // prettyprint
        return (*qfn1(fn))(qenv(fn), v0014);
    }
// error exit handlers
v0202:
    popv(3);
    return nil;
}



// Code for ofsf_smwmkatl

static LispObject CC_ofsf_smwmkatl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0019, v0036, v0158, v0138, v0162;
    LispObject fn;
    LispObject v0050, v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smwmkatl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    v0050 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smwmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0036 = v0050;
    v0158 = v0051;
    v0138 = v0001;
    v0162 = v0000;
// end of prologue
    v0019 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0019 == nil) goto v0042;
    v0019 = v0162;
    {
        fn = elt(env, 2); // cl_susimkatl
        return (*qfnn(fn))(qenv(fn), 4, v0019, v0138, v0158, v0036);
    }

v0042:
    v0019 = v0162;
    {
        fn = elt(env, 3); // ofsf_smmkatl
        return (*qfnn(fn))(qenv(fn), 4, v0019, v0138, v0158, v0036);
    }
}



// Code for vintersection

static LispObject CC_vintersection(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0081, v0082;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vintersection");
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

v0135:
    v0081 = stack[-1];
    if (v0081 == nil) goto v0027;
    v0081 = stack[-1];
    v0081 = qcar(v0081);
    v0082 = qcar(v0081);
    v0081 = stack[0];
    v0081 = Lassoc(nil, v0082, v0081);
    stack[-2] = v0081;
    if (v0081 == nil) goto v0215;
    v0081 = stack[-1];
    v0081 = qcar(v0081);
    v0082 = qcdr(v0081);
    v0081 = stack[-2];
    v0081 = qcdr(v0081);
    v0081 = (LispObject)greaterp2(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0081 = v0081 ? lisp_true : nil;
    env = stack[-3];
    if (v0081 == nil) goto v0223;
    v0081 = stack[-2];
    v0082 = qcdr(v0081);
    v0081 = (LispObject)1; // 0
    if (v0082 == v0081) goto v0006;
    v0081 = stack[-1];
    v0082 = qcdr(v0081);
    v0081 = stack[0];
    v0081 = CC_vintersection(env, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    {
        LispObject v0227 = stack[-2];
        popv(4);
        return cons(v0227, v0081);
    }

v0006:
    v0081 = stack[-1];
    v0082 = qcdr(v0081);
    v0081 = stack[0];
    stack[-1] = v0082;
    stack[0] = v0081;
    goto v0135;

v0223:
    v0081 = stack[-1];
    v0081 = qcar(v0081);
    v0082 = qcdr(v0081);
    v0081 = (LispObject)1; // 0
    if (v0082 == v0081) goto v0222;
    v0081 = stack[-1];
    stack[-2] = qcar(v0081);
    v0081 = stack[-1];
    v0082 = qcdr(v0081);
    v0081 = stack[0];
    v0081 = CC_vintersection(env, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    {
        LispObject v0228 = stack[-2];
        popv(4);
        return cons(v0228, v0081);
    }

v0222:
    v0081 = stack[-1];
    v0082 = qcdr(v0081);
    v0081 = stack[0];
    stack[-1] = v0082;
    stack[0] = v0081;
    goto v0135;

v0215:
    v0081 = stack[-1];
    v0082 = qcdr(v0081);
    v0081 = stack[0];
    stack[-1] = v0082;
    stack[0] = v0081;
    goto v0135;

v0027:
    v0081 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0081); }
// error exit handlers
v0118:
    popv(4);
    return nil;
}



// Code for dm!-gt

static LispObject CC_dmKgt(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0100, v0116;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-gt");
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
// copy arguments values to proper place
    v0116 = v0001;
    v0100 = v0000;
// end of prologue
    fn = elt(env, 1); // dm!-difference
    v0100 = (*qfn2(fn))(qenv(fn), v0116, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !:minusp
        return (*qfn1(fn))(qenv(fn), v0100);
    }
// error exit handlers
v0136:
    popv(1);
    return nil;
}



// Code for partitexdf

static LispObject CC_partitexdf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0160;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for partitexdf");
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
    v0160 = v0000;
// end of prologue
    v0160 = qcar(v0160);
    fn = elt(env, 1); // partitop
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // exdfpf
        return (*qfn1(fn))(qenv(fn), v0160);
    }
// error exit handlers
v0016:
    popv(1);
    return nil;
}



// Code for indord2

static LispObject CC_indord2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0189, v0190;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indord2");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0190 = stack[-1];
    v0189 = stack[0];
    fn = elt(env, 1); // indordp
    v0189 = (*qfn2(fn))(qenv(fn), v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    if (v0189 == nil) goto v0026;
    v0190 = stack[-1];
    v0189 = stack[0];
    popv(2);
    return list2(v0190, v0189);

v0026:
    v0190 = stack[0];
    v0189 = stack[-1];
    popv(2);
    return list2(v0190, v0189);
// error exit handlers
v0047:
    popv(2);
    return nil;
}



// Code for assert_format

static LispObject CC_assert_format(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0204, v0120, v0197;
    LispObject v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assert_format");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_format");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    v0204 = v0051;
    stack[-8] = v0001;
    stack[-9] = v0000;
// end of prologue
    v0204 = Lexplode(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    stack[-10] = v0204;
    stack[-7] = elt(env, 1); // !!
    stack[-6] = elt(env, 2); // !)
    stack[-5] = elt(env, 1); // !!
    stack[-4] = elt(env, 3); // ! 
    stack[-3] = elt(env, 1); // !!
    stack[-2] = elt(env, 4); // !-
    stack[-1] = elt(env, 1); // !!
    stack[0] = elt(env, 5); // !>
    v0197 = elt(env, 1); // !!
    v0120 = elt(env, 3); // ! 
    v0204 = stack[-10];
    v0204 = list2star(v0197, v0120, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = list2star(stack[-1], stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = list2star(stack[-3], stack[-2], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = list2star(stack[-5], stack[-4], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = list2star(stack[-7], stack[-6], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    stack[-10] = v0204;
    v0204 = stack[-8];
    v0204 = Lreverse(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    stack[-4] = v0204;
    goto v0159;

v0159:
    v0204 = stack[-4];
    if (v0204 == nil) goto v0153;
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    stack[-3] = elt(env, 1); // !!
    stack[-2] = elt(env, 7); // !,
    stack[-1] = elt(env, 1); // !!
    stack[0] = elt(env, 3); // ! 
    v0120 = Lexplode(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = stack[-10];
    v0204 = Lnconc(nil, v0120, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = list2star(stack[-1], stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = list2star(stack[-3], stack[-2], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    stack[-10] = v0204;
    v0204 = stack[-4];
    v0204 = qcdr(v0204);
    stack[-4] = v0204;
    goto v0159;

v0153:
    v0204 = stack[-10];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    stack[-10] = v0204;
    stack[-3] = elt(env, 1); // !!
    stack[-2] = elt(env, 8); // !:
    stack[-1] = elt(env, 1); // !!
    stack[0] = elt(env, 3); // ! 
    v0197 = elt(env, 1); // !!
    v0120 = elt(env, 9); // !(
    v0204 = stack[-10];
    v0204 = list2star(v0197, v0120, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = list2star(stack[-1], stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = list2star(stack[-3], stack[-2], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    stack[-10] = v0204;
    v0204 = stack[-9];
    v0120 = Lexplode(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-11];
    v0204 = stack[-10];
    v0204 = Lnconc(nil, v0120, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    stack[-10] = v0204;
    v0204 = stack[-10];
        popv(12);
        return Lcompress(nil, v0204);
// error exit handlers
v0133:
    popv(12);
    return nil;
}



// Code for sf2mv1

static LispObject CC_sf2mv1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0147, v0225, v0220;
    LispObject fn;
    LispObject v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sf2mv1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf2mv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0051;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue

v0160:
    v0147 = stack[-3];
    if (v0147 == nil) goto v0046;
    v0147 = stack[-3];
    if (!consp(v0147)) goto v0022;
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = (consp(v0147) ? nil : lisp_true);
    goto v0043;

v0043:
    if (v0147 == nil) goto v0084;
    stack[0] = stack[-2];
    v0147 = stack[-1];
    v0147 = Llength(nil, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-5];
    fn = elt(env, 3); // nzeros
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-5];
    v0225 = Lappend(nil, stack[0], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-5];
    v0147 = stack[-3];
    v0147 = cons(v0225, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    popv(6);
    return ncons(v0147);

v0084:
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    v0225 = qcar(v0147);
    v0147 = stack[-1];
    v0147 = qcar(v0147);
    if (equal(v0225, v0147)) goto v0038;
    stack[0] = stack[-2];
    v0147 = (LispObject)1; // 0
    v0147 = ncons(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-5];
    v0147 = Lappend(nil, stack[0], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-5];
    stack[-2] = v0147;
    v0147 = stack[-1];
    v0147 = qcdr(v0147);
    stack[-1] = v0147;
    goto v0160;

v0038:
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    stack[-4] = qcdr(v0147);
    stack[0] = stack[-2];
    v0147 = stack[-3];
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    v0147 = qcdr(v0147);
    v0147 = ncons(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-5];
    v0225 = Lappend(nil, stack[0], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-5];
    v0147 = stack[-1];
    v0147 = qcdr(v0147);
    stack[0] = CC_sf2mv1(env, 3, stack[-4], v0225, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-5];
    v0147 = stack[-3];
    v0220 = qcdr(v0147);
    v0225 = stack[-2];
    v0147 = stack[-1];
    v0147 = CC_sf2mv1(env, 3, v0220, v0225, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    {
        LispObject v0208 = stack[0];
        popv(6);
        return Lappend(nil, v0208, v0147);
    }

v0022:
    v0147 = qvalue(elt(env, 2)); // t
    goto v0043;

v0046:
    v0147 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0147); }
// error exit handlers
v0230:
    popv(6);
    return nil;
}



// Code for !:rn2rd

static LispObject CC_Trn2rd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0091, v0043;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :rn2rd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0043 = v0000;
// end of prologue
    v0091 = qvalue(elt(env, 1)); // !*roundall
    if (v0091 == nil) return onevalue(v0043);
    v0091 = qvalue(elt(env, 2)); // !*rounded
    if (v0091 == nil) return onevalue(v0043);
    v0091 = v0043;
    {
        fn = elt(env, 3); // !*rn2rd
        return (*qfn1(fn))(qenv(fn), v0091);
    }
}



// Code for groeb!=weight

static LispObject CC_groebMweight(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0154;
    LispObject fn;
    LispObject v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groeb=weight");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=weight");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0051;
    stack[-1] = v0001;
    v0154 = v0000;
// end of prologue
    fn = elt(env, 1); // mo_ecart
    stack[-2] = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    v0154 = stack[-1];
    fn = elt(env, 2); // bas_dpecart
    stack[-1] = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    v0154 = stack[0];
    fn = elt(env, 2); // bas_dpecart
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    v0154 = Lmin2(nil, stack[-1], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    {
        LispObject v0042 = stack[-2];
        popv(4);
        return plus2(v0042, v0154);
    }
// error exit handlers
v0026:
    popv(4);
    return nil;
}



// Code for reducepowers

static LispObject CC_reducepowers(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0079, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reducepowers");
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

v0055:
    v0079 = stack[0];
    if (!consp(v0079)) goto v0091;
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0079 = (consp(v0079) ? nil : lisp_true);
    goto v0136;

v0136:
    if (v0079 == nil) goto v0224;
    v0079 = qvalue(elt(env, 1)); // t
    goto v0155;

v0155:
    if (!(v0079 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0080 = qcdr(v0079);
    v0079 = qvalue(elt(env, 2)); // repowl!*
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    if (equal(v0080, v0079)) goto v0153;
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    stack[-1] = qcar(v0079);
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0080 = qcdr(v0079);
    v0079 = qvalue(elt(env, 2)); // repowl!*
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0079 = difference2(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    fn = elt(env, 3); // to
    v0080 = (*qfn2(fn))(qenv(fn), stack[-1], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    v0079 = (LispObject)17; // 1
    v0079 = cons(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    v0080 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    fn = elt(env, 4); // multf
    v0080 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    v0079 = qvalue(elt(env, 2)); // repowl!*
    v0079 = qcdr(v0079);
    fn = elt(env, 4); // multf
    v0080 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    fn = elt(env, 5); // addf
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    stack[0] = v0079;
    goto v0055;

v0153:
    v0079 = qvalue(elt(env, 2)); // repowl!*
    v0080 = qcdr(v0079);
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    fn = elt(env, 4); // multf
    v0080 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    {
        popv(3);
        fn = elt(env, 5); // addf
        return (*qfn2(fn))(qenv(fn), v0080, v0079);
    }

v0224:
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0080 = qcdr(v0079);
    v0079 = qvalue(elt(env, 2)); // repowl!*
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0079 = (LispObject)lessp2(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0079 = v0079 ? lisp_true : nil;
    env = stack[-2];
    goto v0155;

v0091:
    v0079 = qvalue(elt(env, 1)); // t
    goto v0136;
// error exit handlers
v0184:
    popv(3);
    return nil;
}



// Code for general!-reciprocal!-by!-gcd

static LispObject CC_generalKreciprocalKbyKgcd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0005, v0219, v0146;
    LispObject fn;
    LispObject v0050, v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "general-reciprocal-by-gcd");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    v0050 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-reciprocal-by-gcd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0050,v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0051,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0050;
    stack[-2] = v0051;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue

v0136:
    v0219 = stack[-3];
    v0005 = (LispObject)1; // 0
    if (v0219 == v0005) goto v0154;
    v0219 = stack[-3];
    v0005 = (LispObject)17; // 1
    if (v0219 == v0005) goto v0084;
    v0219 = stack[-4];
    v0005 = stack[-3];
    v0005 = quot2(v0219, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-6];
    stack[-5] = v0005;
    v0005 = stack[-4];
    v0219 = v0005;
    v0005 = stack[-3];
    stack[-4] = v0005;
    stack[0] = v0219;
    v0219 = stack[-3];
    v0005 = stack[-5];
    v0005 = times2(v0219, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-6];
    v0005 = difference2(stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-6];
    stack[-3] = v0005;
    v0005 = stack[-2];
    v0219 = v0005;
    v0005 = stack[-1];
    stack[-2] = v0005;
    stack[0] = v0219;
    v0219 = stack[-1];
    v0005 = stack[-5];
    v0005 = times2(v0219, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-6];
    v0005 = difference2(stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-6];
    stack[-1] = v0005;
    goto v0136;

v0084:
    v0219 = stack[-1];
    v0005 = (LispObject)1; // 0
    v0005 = (LispObject)lessp2(v0219, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    v0005 = v0005 ? lisp_true : nil;
    env = stack[-6];
    if (v0005 == nil) { LispObject res = stack[-1]; popv(7); return onevalue(res); }
    v0005 = stack[-1];
    v0219 = qvalue(elt(env, 3)); // current!-modulus
    popv(7);
    return plus2(v0005, v0219);

v0154:
    v0146 = elt(env, 1); // alg
    v0219 = (LispObject)129; // 8
    v0005 = elt(env, 2); // "Invalid modular division"
    {
        popv(7);
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0146, v0219, v0005);
    }
// error exit handlers
v0220:
    popv(7);
    return nil;
}



// Code for exc

static LispObject CC_exc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0136, v0091;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0136 = v0001;
    v0091 = v0000;
// end of prologue
    v0091 = qcdr(v0091);
    if (v0091 == nil) return onevalue(v0136);
    v0136 = (v0136 == nil ? lisp_true : nil);
    return onevalue(v0136);
}



// Code for lex_cleanup

static LispObject CC_lex_cleanup(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0128, v0018, v0019, v0036;
    argcheck(nargs, 0, "lex_cleanup");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lex_cleanup");
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
// end of prologue
    v0128 = qvalue(elt(env, 1)); // lex_keyword_names
    v0036 = v0128;
    goto v0160;

v0160:
    v0128 = v0036;
    if (v0128 == nil) goto v0139;
    v0128 = v0036;
    v0128 = qcar(v0128);
    v0019 = v0128;
    v0018 = v0019;
    v0128 = elt(env, 3); // lex_code
    v0128 = Lremprop(nil, v0018, v0128);
    env = stack[0];
    v0018 = v0019;
    v0128 = elt(env, 4); // lex_dipthong
    v0128 = Lremprop(nil, v0018, v0128);
    env = stack[0];
    v0128 = v0036;
    v0128 = qcdr(v0128);
    v0036 = v0128;
    goto v0160;

v0139:
    v0128 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 1)) = v0128; // lex_keyword_names
    v0128 = qvalue(elt(env, 5)); // lex_initial_next_code
    qvalue(elt(env, 6)) = v0128; // lex_next_code
    v0128 = elt(env, 7); // ((0 . !:eof) (1 . !:symbol) (2 . !:string) (3 . !:number) (4 . !:list))
    qvalue(elt(env, 8)) = v0128; // lex_codename
    v0128 = nil;
    { popv(1); return onevalue(v0128); }
}



// Code for defineargs

static LispObject CC_defineargs(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0217, v0214, v0011, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for defineargs");
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
    v0217 = stack[-1];
    if (!symbolp(v0217)) v0217 = nil;
    else { v0217 = qfastgets(v0217);
           if (v0217 != nil) { v0217 = elt(v0217, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v0217 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v0217 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v0217 == SPID_NOPROP) v0217 = nil; }}
#endif
    v0214 = v0217;
    v0217 = v0214;
    if (v0217 == nil) goto v0091;
    v0011 = stack[0];
    v0217 = v0214;
    if (equal(v0011, v0217)) goto v0161;
    v0011 = stack[-1];
    v0217 = elt(env, 2); // calledby
    v0011 = get(v0011, v0217);
    env = stack[-2];
    v0217 = v0011;
    if (v0011 == nil) goto v0123;
    v0012 = stack[-1];
    v0011 = stack[0];
    fn = elt(env, 3); // instdof
    v0217 = (*qfnn(fn))(qenv(fn), 4, v0012, v0011, v0214, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-2];
    goto v0123;

v0123:
    v0214 = stack[-1];
    v0217 = stack[0];
    fn = elt(env, 4); // hasarg
    v0217 = (*qfn2(fn))(qenv(fn), v0214, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    v0217 = nil;
    { popv(3); return onevalue(v0217); }

v0161:
    v0217 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0217); }

v0091:
    v0214 = stack[-1];
    v0217 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // hasarg
        return (*qfn2(fn))(qenv(fn), v0214, v0217);
    }
// error exit handlers
v0211:
    popv(3);
    return nil;
}



// Code for mk!+unit!+mat

static LispObject CC_mkLunitLmat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0160;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+unit+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0160 = v0000;
// end of prologue
    {
        fn = elt(env, 1); // gen!+can!+bas
        return (*qfn1(fn))(qenv(fn), v0160);
    }
}



// Code for ibalp_var!-wclist

static LispObject CC_ibalp_varKwclist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0181, v0234;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-wclist");
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
    stack[-4] = v0000;
// end of prologue
    stack[-3] = nil;
    v0181 = stack[-4];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    stack[-2] = v0181;
    goto v0046;

v0046:
    v0181 = stack[-2];
    if (v0181 == nil) { LispObject res = stack[-3]; popv(7); return onevalue(res); }
    v0181 = stack[-2];
    v0181 = qcar(v0181);
    stack[-1] = v0181;
    v0181 = stack[-1];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    if (!(v0181 == nil)) goto v0021;
    v0181 = stack[-1];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    stack[0] = qcdr(v0181);
    v0234 = stack[-4];
    v0181 = stack[-1];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    fn = elt(env, 2); // delq
    v0181 = (*qfn2(fn))(qenv(fn), v0234, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0181 = (*qfn2(fn))(qenv(fn), stack[0], v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    v0181 = stack[-4];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    stack[0] = qcdr(v0181);
    v0234 = stack[-1];
    v0181 = stack[-4];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    fn = elt(env, 2); // delq
    v0181 = (*qfn2(fn))(qenv(fn), v0234, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0181 = (*qfn2(fn))(qenv(fn), stack[0], v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    v0181 = stack[-1];
    fn = elt(env, 4); // ibalp_getnewwl
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    stack[-5] = v0181;
    v0181 = stack[-5];
    if (v0181 == nil) goto v0147;
    v0181 = stack[-1];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    stack[0] = qcdr(v0181);
    v0234 = stack[-5];
    v0181 = stack[-1];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    v0181 = cons(v0234, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0181 = (*qfn2(fn))(qenv(fn), stack[0], v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    v0181 = stack[-5];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    stack[0] = qcdr(v0181);
    v0234 = stack[-1];
    v0181 = stack[-5];
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    v0181 = cons(v0234, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0181 = (*qfn2(fn))(qenv(fn), stack[0], v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    goto v0021;

v0021:
    v0181 = stack[-2];
    v0181 = qcdr(v0181);
    stack[-2] = v0181;
    goto v0046;

v0147:
    v0234 = stack[-1];
    v0181 = stack[-3];
    v0181 = cons(v0234, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    stack[-3] = v0181;
    goto v0021;
// error exit handlers
v0066:
    popv(7);
    return nil;
}



// Code for aex_deg

static LispObject CC_aex_deg(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0116, v0136;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_deg");
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
    stack[0] = v0001;
    v0116 = v0000;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-1];
    v0136 = qcar(v0116);
    v0116 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // sfto_vardeg
        return (*qfn2(fn))(qenv(fn), v0136, v0116);
    }
// error exit handlers
v0043:
    popv(2);
    return nil;
}



// Code for horner!-rule!-mod!-p

static LispObject CC_hornerKruleKmodKp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0137, v0076, v0075, v0196, v0142;
    LispObject fn;
    LispObject v0055, v0050, v0051, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "horner-rule-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    v0050 = va_arg(aa, LispObject);
    v0055 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for horner-rule-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0055,v0050,v0051,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0051,v0050,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0055;
    stack[-3] = v0050;
    stack[-4] = v0051;
    v0075 = v0001;
    v0196 = v0000;
// end of prologue

v0135:
    v0137 = stack[-4];
    if (!consp(v0137)) goto v0043;
    v0137 = stack[-4];
    v0137 = qcar(v0137);
    v0137 = (consp(v0137) ? nil : lisp_true);
    goto v0091;

v0091:
    if (v0137 == nil) goto v0224;
    v0137 = qvalue(elt(env, 1)); // t
    goto v0099;

v0099:
    if (v0137 == nil) goto v0152;
    v0137 = stack[-3];
    if (v0137 == nil) goto v0084;
    v0137 = stack[-3];
    v0137 = (LispObject)zerop(v0137);
    v0137 = v0137 ? lisp_true : nil;
    env = stack[-6];
    goto v0163;

v0163:
    if (!(v0137 == nil)) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v0196;
    v0137 = stack[-3];
    v0076 = v0075;
    fn = elt(env, 2); // expt!-mod!-p
    v0137 = (*qfn2(fn))(qenv(fn), v0137, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    fn = elt(env, 3); // times!-mod!-p
    v0137 = (*qfn2(fn))(qenv(fn), stack[0], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    v0196 = v0137;
    v0137 = stack[-4];
    v0076 = v0196;
    {
        popv(7);
        fn = elt(env, 4); // plus!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0137, v0076);
    }

v0084:
    v0137 = qvalue(elt(env, 1)); // t
    goto v0163;

v0152:
    v0137 = stack[-4];
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    stack[-5] = v0137;
    v0137 = stack[-3];
    if (v0137 == nil) goto v0219;
    v0137 = stack[-3];
    v0137 = (LispObject)zerop(v0137);
    v0137 = v0137 ? lisp_true : nil;
    env = stack[-6];
    goto v0005;

v0005:
    if (v0137 == nil) goto v0230;
    v0137 = stack[-4];
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    v0196 = v0137;
    goto v0186;

v0186:
    v0075 = stack[-5];
    v0137 = stack[-4];
    v0142 = qcdr(v0137);
    v0076 = stack[-3];
    v0137 = stack[-2];
    stack[-4] = v0142;
    stack[-3] = v0076;
    stack[-2] = v0137;
    goto v0135;

v0230:
    v0137 = stack[-4];
    v0137 = qcar(v0137);
    stack[-1] = qcdr(v0137);
    stack[0] = v0196;
    v0076 = stack[-3];
    v0137 = stack[-5];
    v0137 = (LispObject)(int32_t)((int32_t)v0075 - (int32_t)v0137 + TAG_FIXNUM);
    fn = elt(env, 2); // expt!-mod!-p
    v0137 = (*qfn2(fn))(qenv(fn), v0076, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    fn = elt(env, 3); // times!-mod!-p
    v0137 = (*qfn2(fn))(qenv(fn), stack[0], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    fn = elt(env, 4); // plus!-mod!-p
    v0137 = (*qfn2(fn))(qenv(fn), stack[-1], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    v0196 = v0137;
    goto v0186;

v0219:
    v0137 = qvalue(elt(env, 1)); // t
    goto v0005;

v0224:
    v0137 = stack[-4];
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0076 = qcar(v0137);
    v0137 = stack[-2];
    v0137 = (equal(v0076, v0137) ? lisp_true : nil);
    v0137 = (v0137 == nil ? lisp_true : nil);
    goto v0099;

v0043:
    v0137 = qvalue(elt(env, 1)); // t
    goto v0091;
// error exit handlers
v0133:
    popv(7);
    return nil;
}



// Code for simprecip

static LispObject CC_simprecip(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041, v0040;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simprecip");
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
    v0040 = v0000;
// end of prologue
    v0041 = qvalue(elt(env, 1)); // !*mcd
    if (v0041 == nil) goto v0022;
    v0041 = elt(env, 2); // recip
    fn = elt(env, 3); // carx
    v0041 = (*qfn2(fn))(qenv(fn), v0040, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[0];
    fn = elt(env, 4); // simp
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); // invsq
        return (*qfn1(fn))(qenv(fn), v0041);
    }

v0022:
    v0041 = elt(env, 2); // recip
    fn = elt(env, 3); // carx
    v0040 = (*qfn2(fn))(qenv(fn), v0040, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[0];
    v0041 = (LispObject)-15; // -1
    v0041 = list2(v0040, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); // simpexpt
        return (*qfn1(fn))(qenv(fn), v0041);
    }
// error exit handlers
v0047:
    popv(1);
    return nil;
}



// Code for coordp

static LispObject CC_coordp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0155, v0099;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0155 = v0000;
// end of prologue
    v0099 = qvalue(elt(env, 1)); // coord!*
    v0155 = Lmemq(nil, v0155, v0099);
    return onevalue(v0155);
}



setup_type const u20_setup[] =
{
    {"indexvarordp",            too_few_2,      CC_indexvarordp,wrong_no_2},
    {"inttovec-solve",          too_few_2,      CC_inttovecKsolve,wrong_no_2},
    {"begin1a",                 CC_begin1a,     too_many_1,    wrong_no_1},
    {"bas_newnumber",           too_few_2,      CC_bas_newnumber,wrong_no_2},
    {"xremainder-mod-p",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremainderKmodKp},
    {"setk0",                   too_few_2,      CC_setk0,      wrong_no_2},
    {"lalr_print_shortnum_vector",CC_lalr_print_shortnum_vector,too_many_1,wrong_no_1},
    {"ofsf_varlat",             CC_ofsf_varlat, too_many_1,    wrong_no_1},
    {"simpqg",                  CC_simpqg,      too_many_1,    wrong_no_1},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"ibalp_tvb",               too_few_2,      CC_ibalp_tvb,  wrong_no_2},
    {"gb_buch-ev_divides?",     too_few_2,      CC_gb_buchKev_dividesW,wrong_no_2},
    {"diff-over-k-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKoverKkKmodKp},
    {"ir2mml",                  CC_ir2mml,      too_many_1,    wrong_no_1},
    {"rd:prep",                 CC_rdTprep,     too_many_1,    wrong_no_1},
    {"chk",                     CC_chk,         too_many_1,    wrong_no_1},
    {"expvec2a",                CC_expvec2a,    too_many_1,    wrong_no_1},
    {"treesizep",               too_few_2,      CC_treesizep,  wrong_no_2},
    {"ncoeffs",                 CC_ncoeffs,     too_many_1,    wrong_no_1},
    {"next-random-number",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nextKrandomKnumber},
    {"mk-strand-vertex2",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKstrandKvertex2},
    {"expand-imrepart",         CC_expandKimrepart,too_many_1, wrong_no_1},
    {"rootrnd",                 CC_rootrnd,     too_many_1,    wrong_no_1},
    {"quotient-mod-p",          too_few_2,      CC_quotientKmodKp,wrong_no_2},
    {"cde_delete",              too_few_2,      CC_cde_delete, wrong_no_2},
    {"sfto_sqfpartf",           CC_sfto_sqfpartf,too_many_1,   wrong_no_1},
    {"sq2sstm",                 too_few_2,      CC_sq2sstm,    wrong_no_2},
    {"ev_invlexcomp",           too_few_2,      CC_ev_invlexcomp,wrong_no_2},
    {"quotofd",                 too_few_2,      CC_quotofd,    wrong_no_2},
    {"dipcondense",             CC_dipcondense, too_many_1,    wrong_no_1},
    {"dipevlcomp",              too_few_2,      CC_dipevlcomp, wrong_no_2},
    {"coposp",                  CC_coposp,      too_many_1,    wrong_no_1},
    {"nfactorial",              CC_nfactorial,  too_many_1,    wrong_no_1},
    {"lpriw",                   too_few_2,      CC_lpriw,      wrong_no_2},
    {"mv-domainlist",           CC_mvKdomainlist,too_many_1,   wrong_no_1},
    {"rnprep:",                 CC_rnprepT,     too_many_1,    wrong_no_1},
    {"gfk",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_gfk},
    {"ordered-gcd-mod-p",       too_few_2,      CC_orderedKgcdKmodKp,wrong_no_2},
    {"dfprint",                 CC_dfprint,     too_many_1,    wrong_no_1},
    {"ofsf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwmkatl},
    {"vintersection",           too_few_2,      CC_vintersection,wrong_no_2},
    {"dm-gt",                   too_few_2,      CC_dmKgt,      wrong_no_2},
    {"partitexdf",              CC_partitexdf,  too_many_1,    wrong_no_1},
    {"indord2",                 too_few_2,      CC_indord2,    wrong_no_2},
    {"assert_format",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_format},
    {"sf2mv1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_sf2mv1},
    {":rn2rd",                  CC_Trn2rd,      too_many_1,    wrong_no_1},
    {"groeb=weight",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMweight},
    {"reducepowers",            CC_reducepowers,too_many_1,    wrong_no_1},
    {"general-reciprocal-by-gcd",wrong_no_na,   wrong_no_nb,   (n_args *)CC_generalKreciprocalKbyKgcd},
    {"exc",                     too_few_2,      CC_exc,        wrong_no_2},
    {"lex_cleanup",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_lex_cleanup},
    {"defineargs",              too_few_2,      CC_defineargs, wrong_no_2},
    {"mk+unit+mat",             CC_mkLunitLmat, too_many_1,    wrong_no_1},
    {"ibalp_var-wclist",        CC_ibalp_varKwclist,too_many_1,wrong_no_1},
    {"aex_deg",                 too_few_2,      CC_aex_deg,    wrong_no_2},
    {"horner-rule-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKmodKp},
    {"simprecip",               CC_simprecip,   too_many_1,    wrong_no_1},
    {"coordp",                  CC_coordp,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u20", (two_args *)"1323 6158113 3073124", 0}
};

// end of generated code
