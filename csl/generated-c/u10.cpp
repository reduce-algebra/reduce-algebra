
// $destdir/u10.c        Machine generated C code

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



// Code for ev_tdeg

static LispObject CC_ev_tdeg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0005, v0006;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_tdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0005 = v0000;
// end of prologue
    v0004 = (LispObject)1; // 0
    goto v0007;

v0007:
    v0006 = v0005;
    if (v0006 == nil) return onevalue(v0004);
    v0006 = v0005;
    v0006 = qcar(v0006);
    v0004 = (LispObject)(int32_t)((int32_t)v0006 + (int32_t)v0004 - TAG_FIXNUM);
    v0005 = qcdr(v0005);
    goto v0007;
}



// Code for omiir

static LispObject CC_omiir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0008;
    LispObject fn;
    argcheck(nargs, 0, "omiir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omiir");
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
    fn = elt(env, 2); // lex
    v0008 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-1];
    v0008 = qvalue(elt(env, 1)); // char
    v0008 = Lcompress(nil, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-1];
    stack[0] = v0008;
    fn = elt(env, 2); // lex
    v0008 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0009:
    popv(2);
    return nil;
}



// Code for ps!:evaluate

static LispObject CC_psTevaluate(LispObject env,
                         LispObject v0010, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0020, v0021;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:evaluate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0010,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0001;
    v0020 = v0010;
// end of prologue
    stack[-3] = qvalue(elt(env, 1)); // ps
    qvalue(elt(env, 1)) = nil; // ps
    qvalue(elt(env, 1)) = v0020; // ps
    v0021 = qvalue(elt(env, 1)); // ps
    v0020 = stack[-2];
    fn = elt(env, 3); // ps!:get!-term
    v0020 = (*qfn2(fn))(qenv(fn), v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    stack[-1] = v0020;
    v0020 = stack[-1];
    if (v0020 == nil) goto v0023;
    v0020 = stack[-1];
    goto v0024;

v0024:
    qvalue(elt(env, 1)) = stack[-3]; // ps
    { popv(5); return onevalue(v0020); }

v0023:
    v0020 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 4); // ps!:last!-term
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    v0020 = add1(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    stack[0] = v0020;
    goto v0025;

v0025:
    v0021 = stack[-2];
    v0020 = stack[0];
    v0020 = difference2(v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    v0020 = Lminusp(nil, v0020);
    env = stack[-4];
    if (v0020 == nil) goto v0026;
    v0020 = stack[-1];
    goto v0024;

v0026:
    v0021 = qvalue(elt(env, 1)); // ps
    v0020 = stack[0];
    fn = elt(env, 5); // ps!:evaluate!-next
    v0020 = (*qfn2(fn))(qenv(fn), v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    stack[-1] = v0020;
    v0020 = stack[0];
    v0020 = add1(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    stack[0] = v0020;
    goto v0025;
// error exit handlers
v0022:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; // ps
    popv(5);
    return nil;
}



// Code for vdplength

static LispObject CC_vdplength(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdplength");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0000;
// end of prologue
    v0007 = qcdr(v0007);
    v0007 = qcdr(v0007);
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    {
        fn = elt(env, 1); // diplength
        return (*qfn1(fn))(qenv(fn), v0007);
    }
}



// Code for plus!:

static LispObject CC_plusT(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056, v0057, v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0057 = v0010;
    v0058 = v0000;
// end of prologue
    v0055 = v0058;
    v0055 = qcdr(v0055);
    v0056 = qcar(v0055);
    stack[-1] = v0056;
    v0055 = (LispObject)1; // 0
    if (v0056 == v0055) { popv(6); return onevalue(v0057); }
    v0055 = v0057;
    v0055 = qcdr(v0055);
    v0056 = qcar(v0055);
    stack[0] = v0056;
    v0055 = (LispObject)1; // 0
    if (v0056 == v0055) { popv(6); return onevalue(v0058); }
    v0055 = v0058;
    v0055 = qcdr(v0055);
    v0055 = qcdr(v0055);
    stack[-4] = v0055;
    v0056 = v0057;
    v0056 = qcdr(v0056);
    v0056 = qcdr(v0056);
    stack[-2] = v0056;
    v0056 = difference2(v0055, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    stack[-3] = v0056;
    v0055 = (LispObject)1; // 0
    if (v0056 == v0055) goto v0020;
    v0056 = stack[-3];
    v0055 = (LispObject)1; // 0
    v0055 = (LispObject)greaterp2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-5];
    if (v0055 == nil) goto v0060;
    stack[-4] = elt(env, 1); // !:rd!:
    v0056 = stack[-1];
    v0055 = stack[-3];
    fn = elt(env, 2); // ashift
    v0056 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0055 = stack[0];
    v0056 = plus2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0055 = stack[-2];
    {
        LispObject v0061 = stack[-4];
        popv(6);
        return list2star(v0061, v0056, v0055);
    }

v0060:
    stack[-2] = elt(env, 1); // !:rd!:
    v0055 = stack[-3];
    v0055 = negate(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    fn = elt(env, 2); // ashift
    v0055 = (*qfn2(fn))(qenv(fn), stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0056 = plus2(stack[-1], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0055 = stack[-4];
    {
        LispObject v0062 = stack[-2];
        popv(6);
        return list2star(v0062, v0056, v0055);
    }

v0020:
    stack[-2] = elt(env, 1); // !:rd!:
    v0056 = stack[-1];
    v0055 = stack[0];
    v0056 = plus2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0055 = stack[-4];
    {
        LispObject v0063 = stack[-2];
        popv(6);
        return list2star(v0063, v0056, v0055);
    }
// error exit handlers
v0059:
    popv(6);
    return nil;
}



// Code for formc

static LispObject CC_formc(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0075, v0076, v0077, v0078;
    LispObject fn;
    LispObject v0001, v0010, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0010,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0010;
    stack[-2] = v0000;
// end of prologue
    v0075 = qvalue(elt(env, 1)); // !*rlisp88
    if (v0075 == nil) goto v0016;
    v0076 = stack[-2];
    v0075 = elt(env, 2); // modefn
    v0075 = Lflagpcar(nil, v0076, v0075);
    env = stack[-3];
    if (v0075 == nil) goto v0016;
    v0075 = stack[-2];
    v0076 = qcar(v0075);
    v0075 = elt(env, 3); // symbolic
    if (v0076 == v0075) goto v0016;
    v0076 = elt(env, 4); // "algebraic expression"
    v0075 = elt(env, 5); // "Rlisp88 form"
    {
        popv(4);
        fn = elt(env, 8); // typerr
        return (*qfn2(fn))(qenv(fn), v0076, v0075);
    }

v0016:
    v0076 = stack[0];
    v0075 = elt(env, 6); // algebraic
    if (v0076 == v0075) goto v0051;
    v0075 = qvalue(elt(env, 7)); // nil
    goto v0079;

v0079:
    if (!(v0075 == nil)) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0078 = stack[-2];
    v0077 = stack[-1];
    v0076 = elt(env, 3); // symbolic
    v0075 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); // convertmode
        return (*qfnn(fn))(qenv(fn), 4, v0078, v0077, v0076, v0075);
    }

v0051:
    v0076 = stack[-2];
    v0075 = stack[-1];
    fn = elt(env, 10); // intexprnp
    v0075 = (*qfn2(fn))(qenv(fn), v0076, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    goto v0079;
// error exit handlers
v0080:
    popv(4);
    return nil;
}



// Code for simp

static LispObject CC_simp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0184, v0185, v0186;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0000;
// end of prologue
    v0184 = qvalue(elt(env, 1)); // varstack!*
    stack[-6] = qvalue(elt(env, 1)); // varstack!*
    qvalue(elt(env, 1)) = v0184; // varstack!*
    stack[-1] = nil;
    v0184 = stack[-5];
    v0184 = integerp(v0184);
    if (v0184 == nil) goto v0071;
    v0185 = stack[-5];
    v0184 = (LispObject)1; // 0
    if (v0185 == v0184) goto v0187;
    v0184 = qvalue(elt(env, 3)); // dmode!*
    if (!(v0184 == nil)) goto v0188;
    v0185 = stack[-5];
    v0184 = (LispObject)17; // 1
    v0184 = cons(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0034:
    qvalue(elt(env, 1)) = stack[-6]; // varstack!*
    { popv(8); return onevalue(v0184); }

v0188:
    v0185 = stack[-5];
    v0184 = qvalue(elt(env, 1)); // varstack!*
    v0184 = cons(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    qvalue(elt(env, 1)) = v0184; // varstack!*
    v0185 = qvalue(elt(env, 4)); // simpcount!*
    v0184 = qvalue(elt(env, 5)); // simplimit!*
    v0184 = (LispObject)greaterp2(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    v0184 = v0184 ? lisp_true : nil;
    env = stack[-7];
    if (v0184 == nil) goto v0190;
    v0184 = (LispObject)1; // 0
    qvalue(elt(env, 4)) = v0184; // simpcount!*
    v0186 = elt(env, 6); // alg
    v0185 = (LispObject)193; // 12
    v0184 = elt(env, 7); // "Simplification recursion too deep"
    fn = elt(env, 24); // rerror
    v0184 = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0191;

v0191:
    v0184 = qvalue(elt(env, 4)); // simpcount!*
    v0184 = add1(v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    qvalue(elt(env, 4)) = v0184; // simpcount!*
    v0184 = stack[-5];
    if (!consp(v0184)) goto v0192;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (symbolp(v0184)) goto v0193;
    v0184 = qvalue(elt(env, 12)); // t
    goto v0194;

v0194:
    if (v0184 == nil) goto v0195;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!consp(v0184)) goto v0196;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    v0184 = qcar(v0184);
    if (!(symbolp(v0184))) goto v0197;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    v0185 = qcar(v0184);
    v0184 = elt(env, 15); // name
    v0184 = get(v0185, v0184);
    env = stack[-7];
    stack[-1] = v0184;
    if (v0184 == nil) goto v0197;
    v0185 = stack[-5];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0197:
    v0184 = stack[-5];
    v0185 = qcar(v0184);
    v0184 = elt(env, 16); // mat
    if (!consp(v0185)) goto v0198;
    v0185 = qcar(v0185);
    if (!(v0185 == v0184)) goto v0198;
    v0184 = stack[-5];
    v0184 = qcdr(v0184);
    fn = elt(env, 26); // revlis
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    stack[-1] = v0184;
    fn = elt(env, 27); // numlis
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    if (v0184 == nil) goto v0199;
    v0184 = stack[-1];
    v0185 = Llength(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = (LispObject)33; // 2
    v0184 = (v0185 == v0184 ? lisp_true : nil);
    goto v0200;

v0200:
    if (v0184 == nil) goto v0201;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    v0185 = qcdr(v0184);
    v0184 = stack[-1];
    v0184 = qcar(v0184);
    fn = elt(env, 28); // nth
    v0185 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-1];
    v0184 = qcdr(v0184);
    v0184 = qcar(v0184);
    fn = elt(env, 28); // nth
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0185 = CC_simp(env, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0201:
    v0185 = stack[-5];
    v0184 = qvalue(elt(env, 12)); // t
    fn = elt(env, 29); // errpri2
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0202;

v0202:
    v0184 = nil;
    goto v0034;

v0199:
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0200;

v0198:
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0200;

v0196:
    v0184 = stack[-5];
    v0185 = qcar(v0184);
    v0184 = elt(env, 14); // "operator"
    fn = elt(env, 30); // typerr
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0202;

v0195:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 59); // opfn
#ifdef RECORD_GET
             if (v0184 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0184 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0184 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; else v0184 = lisp_true; }}
#endif
    if (v0184 == nil) goto v0203;
    v0184 = stack[-5];
    fn = elt(env, 31); // opfneval
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    stack[-1] = v0184;
    fn = elt(env, 32); // getrtype
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0185 = v0184;
    if (v0184 == nil) goto v0204;
    v0184 = elt(env, 17); // yetunknowntype
    if (v0185 == v0184) goto v0205;
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0206;

v0206:
    if (v0184 == nil) goto v0207;
    v0184 = stack[-1];
    v0184 = CC_simp(env, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0207:
    v0185 = stack[-5];
    v0184 = elt(env, 18); // "scalar"
    fn = elt(env, 30); // typerr
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0202;

v0205:
    v0184 = stack[-1];
    fn = elt(env, 33); // reval
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    stack[-1] = v0184;
    fn = elt(env, 32); // getrtype
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = (v0184 == nil ? lisp_true : nil);
    goto v0206;

v0204:
    v0184 = stack[-1];
    fn = elt(env, 34); // simp_without_resimp
    v0185 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0203:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 45); // psopfn
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    stack[-1] = v0184;
    if (v0184 == nil) goto v0208;
    stack[0] = stack[-1];
    v0184 = stack[-5];
    fn = elt(env, 35); // argnochk
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = qcdr(v0184);
    v0184 = Lapply1(nil, stack[0], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    stack[-1] = v0184;
    fn = elt(env, 32); // getrtype
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    if (v0184 == nil) goto v0209;
    v0185 = stack[-5];
    v0184 = elt(env, 18); // "scalar"
    fn = elt(env, 30); // typerr
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0202;

v0209:
    v0185 = stack[-1];
    v0184 = stack[-5];
    if (equal(v0185, v0184)) goto v0210;
    v0184 = stack[-1];
    fn = elt(env, 34); // simp_without_resimp
    v0185 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0210:
    v0185 = stack[-1];
    v0184 = (LispObject)17; // 1
    fn = elt(env, 36); // to
    v0185 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = (LispObject)17; // 1
    v0184 = cons(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0185 = ncons(v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = (LispObject)17; // 1
    v0185 = cons(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0208:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 41); // polyfn
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 41), 1);
             else record_get(elt(fastget_names, 41), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 41), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    stack[-1] = v0184;
    if (v0184 == nil) goto v0211;
    v0184 = stack[-5];
    fn = elt(env, 35); // argnochk
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    stack[-4] = stack[-1];
    v0184 = stack[-5];
    v0184 = qcdr(v0184);
    stack[-3] = v0184;
    v0184 = stack[-3];
    if (v0184 == nil) goto v0212;
    v0184 = stack[-3];
    v0184 = qcar(v0184);
    fn = elt(env, 37); // simp!*
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    fn = elt(env, 38); // !*q2f
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = ncons(v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    stack[-1] = v0184;
    stack[-2] = v0184;
    goto v0213;

v0213:
    v0184 = stack[-3];
    v0184 = qcdr(v0184);
    stack[-3] = v0184;
    v0184 = stack[-3];
    if (v0184 == nil) goto v0214;
    stack[0] = stack[-1];
    v0184 = stack[-3];
    v0184 = qcar(v0184);
    fn = elt(env, 37); // simp!*
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    fn = elt(env, 38); // !*q2f
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = ncons(v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = Lrplacd(nil, stack[0], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-1];
    v0184 = qcdr(v0184);
    stack[-1] = v0184;
    goto v0213;

v0214:
    v0184 = stack[-2];
    goto v0215;

v0215:
    fn = elt(env, 39); // lispapply
    v0185 = (*qfn2(fn))(qenv(fn), stack[-4], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = (LispObject)17; // 1
    v0185 = cons(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0212:
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0215;

v0211:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 9); // opmtch
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    if (v0184 == nil) goto v0216;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0185 = nil;
    else { v0185 = qfastgets(v0184);
           if (v0185 != nil) { v0185 = elt(v0185, 22); // simpfn
#ifdef RECORD_GET
             if (v0185 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0185 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0185 == SPID_NOPROP) v0185 = nil; }}
#endif
    v0184 = elt(env, 19); // simpiden
    if (v0185 == v0184) goto v0217;
    v0184 = stack[-5];
    fn = elt(env, 40); // opmtchrevop
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    stack[-1] = v0184;
    goto v0218;

v0218:
    if (v0184 == nil) goto v0216;
    v0184 = stack[-1];
    v0185 = CC_simp(env, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0216:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 22); // simpfn
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    stack[-1] = v0184;
    if (v0184 == nil) goto v0219;
    stack[0] = stack[-1];
    v0185 = stack[-1];
    v0184 = elt(env, 19); // simpiden
    if (v0185 == v0184) goto v0220;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 62); // full
#ifdef RECORD_GET
             if (v0184 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v0184 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v0184 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; else v0184 = lisp_true; }}
#endif
    goto v0221;

v0221:
    if (v0184 == nil) goto v0222;
    v0184 = stack[-5];
    fn = elt(env, 35); // argnochk
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0223;

v0223:
    v0185 = Lapply1(nil, stack[0], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0222:
    v0184 = stack[-5];
    fn = elt(env, 35); // argnochk
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = qcdr(v0184);
    goto v0223;

v0220:
    v0184 = qvalue(elt(env, 12)); // t
    goto v0221;

v0219:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 2); // rtype
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    stack[-1] = v0184;
    if (v0184 == nil) goto v0224;
    v0185 = stack[-1];
    v0184 = elt(env, 20); // getelemfn
    v0184 = get(v0185, v0184);
    env = stack[-7];
    stack[-1] = v0184;
    if (v0184 == nil) goto v0224;
    v0185 = stack[-1];
    v0184 = stack[-5];
    v0184 = Lapply1(nil, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0185 = CC_simp(env, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0224:
    v0184 = stack[-5];
    v0185 = qcar(v0184);
    v0184 = elt(env, 21); // boolean
    v0184 = Lflagp(nil, v0185, v0184);
    env = stack[-7];
    if (v0184 == nil) goto v0225;
    v0184 = qvalue(elt(env, 12)); // t
    goto v0226;

v0226:
    if (v0184 == nil) goto v0227;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 37); // prtch
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    stack[-1] = v0184;
    if (v0184 == nil) goto v0228;
    v0184 = stack[-1];
    v0185 = v0184;
    goto v0229;

v0229:
    v0184 = elt(env, 22); // "algebraic operator"
    fn = elt(env, 30); // typerr
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0202;

v0228:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    v0185 = v0184;
    goto v0229;

v0227:
    v0184 = stack[-5];
    v0185 = qcar(v0184);
    v0184 = elt(env, 23); // nochange
    v0184 = Lflagp(nil, v0185, v0184);
    env = stack[-7];
    if (v0184 == nil) goto v0230;
    v0184 = stack[-5];
    fn = elt(env, 41); // lispeval
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0185 = CC_simp(env, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0230:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 45); // psopfn
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    if (!(v0184 == nil)) goto v0231;
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 19); // rtypefn
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    if (!(v0184 == nil)) goto v0231;
    v0184 = stack[-5];
    v0185 = qcar(v0184);
    v0184 = elt(env, 14); // "operator"
    fn = elt(env, 42); // redmsg
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    fn = elt(env, 43); // mkop
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0185 = stack[-5];
    v0184 = qvalue(elt(env, 1)); // varstack!*
    v0184 = Ldelete(nil, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    qvalue(elt(env, 1)) = v0184; // varstack!*
    v0184 = stack[-5];
    v0185 = CC_simp(env, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0231:
    v0185 = stack[-5];
    v0184 = elt(env, 18); // "scalar"
    fn = elt(env, 30); // typerr
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0202;

v0225:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 23); // infix
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    goto v0226;

v0217:
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0218;

v0193:
    v0184 = stack[-5];
    v0184 = qcar(v0184);
    v0184 = (v0184 == nil ? lisp_true : nil);
    goto v0194;

v0192:
    v0184 = stack[-5];
    fn = elt(env, 44); // simpatom
    v0185 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    v0184 = stack[-5];
    fn = elt(env, 25); // !*ssave
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0190:
    v0185 = stack[-5];
    v0184 = elt(env, 8); // !*sq
    if (!consp(v0185)) goto v0232;
    v0185 = qcar(v0185);
    if (!(v0185 == v0184)) goto v0232;
    v0184 = stack[-5];
    v0184 = qcdr(v0184);
    v0184 = qcdr(v0184);
    v0184 = qcar(v0184);
    if (v0184 == nil) goto v0040;
    v0184 = qvalue(elt(env, 9)); // !*resimp
    v0184 = (v0184 == nil ? lisp_true : nil);
    goto v0233;

v0233:
    if (v0184 == nil) goto v0037;
    v0184 = stack[-5];
    v0184 = qcdr(v0184);
    v0184 = qcar(v0184);
    goto v0034;

v0037:
    v0184 = qvalue(elt(env, 10)); // !*uncached
    if (v0184 == nil) goto v0234;
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0031;

v0031:
    if (v0184 == nil) goto v0191;
    v0184 = stack[-1];
    v0184 = qcar(v0184);
    if (v0184 == nil) goto v0235;
    v0184 = qvalue(elt(env, 12)); // t
    qvalue(elt(env, 13)) = v0184; // !*sub2
    goto v0235;

v0235:
    v0184 = stack[-1];
    v0184 = qcdr(v0184);
    goto v0034;

v0234:
    v0184 = qvalue(elt(env, 11)); // alglist!*
    v0184 = qcar(v0184);
    v0185 = v0184;
    if (v0185 == nil) goto v0029;
    v0185 = stack[-5];
    fn = elt(env, 45); // gethash
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0236;

v0236:
    stack[-1] = v0184;
    goto v0031;

v0029:
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0236;

v0040:
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0233;

v0232:
    v0184 = qvalue(elt(env, 2)); // nil
    goto v0233;

v0187:
    v0185 = qvalue(elt(env, 2)); // nil
    v0184 = (LispObject)17; // 1
    v0184 = cons(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0034;

v0071:
    v0185 = stack[-5];
    v0184 = qvalue(elt(env, 1)); // varstack!*
    v0184 = Lmember(nil, v0185, v0184);
    if (v0184 == nil) goto v0188;
    v0184 = stack[-5];
    fn = elt(env, 46); // recursiveerror
    v0184 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-7];
    goto v0188;
// error exit handlers
v0189:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; // varstack!*
    popv(8);
    return nil;
}



// Code for compactfmatch2

static LispObject CC_compactfmatch2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0053, v0072;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compactfmatch2");
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
    v0053 = stack[0];
    if (!consp(v0053)) goto v0012;
    v0053 = stack[0];
    v0072 = qcar(v0053);
    v0053 = elt(env, 2); // !~
    if (v0072 == v0053) goto v0007;
    v0053 = stack[0];
    v0053 = qcar(v0053);
    stack[-1] = CC_compactfmatch2(env, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    v0053 = CC_compactfmatch2(env, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    {
        LispObject v0068 = stack[-1];
        popv(3);
        return Lappend(nil, v0068, v0053);
    }

v0007:
    v0053 = stack[0];
    popv(3);
    return ncons(v0053);

v0012:
    v0053 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0053); }
// error exit handlers
v0025:
    popv(3);
    return nil;
}



// Code for gcdf1

static LispObject CC_gcdf1(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0251, v0252;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0010;
    stack[-2] = v0000;
// end of prologue
    v0251 = stack[-2];
    if (v0251 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0251 = stack[-1];
    if (v0251 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0252 = stack[-2];
    v0251 = (LispObject)17; // 1
    if (v0252 == v0251) goto v0023;
    v0252 = stack[-1];
    v0251 = (LispObject)17; // 1
    v0251 = (v0252 == v0251 ? lisp_true : nil);
    goto v0074;

v0074:
    if (v0251 == nil) goto v0018;
    v0251 = (LispObject)17; // 1
    { popv(5); return onevalue(v0251); }

v0018:
    v0251 = stack[-2];
    if (!consp(v0251)) goto v0253;
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0251 = (consp(v0251) ? nil : lisp_true);
    goto v0017;

v0017:
    if (v0251 == nil) goto v0179;
    v0252 = stack[-2];
    v0251 = stack[-1];
    {
        popv(5);
        fn = elt(env, 8); // gcdfd
        return (*qfn2(fn))(qenv(fn), v0252, v0251);
    }

v0179:
    v0251 = stack[-1];
    if (!consp(v0251)) goto v0178;
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0251 = (consp(v0251) ? nil : lisp_true);
    goto v0045;

v0045:
    if (v0251 == nil) goto v0022;
    v0252 = stack[-1];
    v0251 = stack[-2];
    {
        popv(5);
        fn = elt(env, 8); // gcdfd
        return (*qfn2(fn))(qenv(fn), v0252, v0251);
    }

v0022:
    v0251 = qvalue(elt(env, 2)); // !*anygcd
    if (v0251 == nil) goto v0254;
    v0251 = stack[-2];
    fn = elt(env, 9); // num!-exponents
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    if (v0251 == nil) goto v0256;
    v0251 = stack[-1];
    fn = elt(env, 9); // num!-exponents
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    v0251 = (v0251 == nil ? lisp_true : nil);
    goto v0257;

v0257:
    if (v0251 == nil) goto v0258;
    v0251 = (LispObject)17; // 1
    { popv(5); return onevalue(v0251); }

v0258:
    v0252 = stack[-2];
    v0251 = stack[-1];
    fn = elt(env, 10); // quotf1
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    if (!(v0251 == nil)) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0252 = stack[-1];
    v0251 = stack[-2];
    fn = elt(env, 10); // quotf1
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    if (!(v0251 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0252 = stack[-2];
    v0251 = stack[-1];
    fn = elt(env, 11); // gcdf2
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    stack[-3] = v0251;
    v0251 = qvalue(elt(env, 3)); // !*gcd
    if (v0251 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0252 = qvalue(elt(env, 4)); // dmode!*
    v0251 = elt(env, 5); // (!:rd!: !:cr!:)
    v0251 = Lmemq(nil, v0252, v0251);
    if (v0251 == nil) goto v0259;
    v0251 = qvalue(elt(env, 6)); // nil
    goto v0260;

v0260:
    if (v0251 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0251 = stack[-2];
    fn = elt(env, 12); // noncomfp
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    if (!(v0251 == nil)) goto v0261;
    v0251 = stack[-1];
    fn = elt(env, 12); // noncomfp
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    if (!(v0251 == nil)) goto v0261;
    stack[0] = elt(env, 7); // "gcdf failed"
    v0251 = stack[-2];
    fn = elt(env, 13); // prepf
    stack[-2] = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    v0251 = stack[-1];
    fn = elt(env, 13); // prepf
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    v0251 = list3(stack[0], stack[-2], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    fn = elt(env, 14); // errach
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0261:
    v0251 = (LispObject)17; // 1
    { popv(5); return onevalue(v0251); }

v0259:
    v0252 = stack[-2];
    v0251 = stack[-3];
    fn = elt(env, 10); // quotf1
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    if (v0251 == nil) goto v0262;
    v0252 = stack[-1];
    v0251 = stack[-3];
    fn = elt(env, 10); // quotf1
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    v0251 = (v0251 == nil ? lisp_true : nil);
    goto v0260;

v0262:
    v0251 = qvalue(elt(env, 1)); // t
    goto v0260;

v0256:
    v0251 = qvalue(elt(env, 1)); // t
    goto v0257;

v0254:
    v0251 = qvalue(elt(env, 1)); // t
    goto v0257;

v0178:
    v0251 = qvalue(elt(env, 1)); // t
    goto v0045;

v0253:
    v0251 = qvalue(elt(env, 1)); // t
    goto v0017;

v0023:
    v0251 = qvalue(elt(env, 1)); // t
    goto v0074;
// error exit handlers
v0255:
    popv(5);
    return nil;
}



// Code for ordn

static LispObject CC_ordn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0179, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordn");
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
    v0016 = v0000;
// end of prologue
    v0179 = v0016;
    if (v0179 == nil) goto v0012;
    v0179 = v0016;
    v0179 = qcdr(v0179);
    if (v0179 == nil) { popv(2); return onevalue(v0016); }
    v0179 = v0016;
    v0179 = qcdr(v0179);
    v0179 = qcdr(v0179);
    if (v0179 == nil) goto v0074;
    v0179 = v0016;
    stack[0] = qcar(v0179);
    v0179 = v0016;
    v0179 = qcdr(v0179);
    v0179 = CC_ordn(env, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-1];
    {
        LispObject v0263 = stack[0];
        popv(2);
        fn = elt(env, 2); // ordad
        return (*qfn2(fn))(qenv(fn), v0263, v0179);
    }

v0074:
    v0179 = v0016;
    v0179 = qcar(v0179);
    v0016 = qcdr(v0016);
    v0016 = qcar(v0016);
    {
        popv(2);
        fn = elt(env, 3); // ord2
        return (*qfn2(fn))(qenv(fn), v0179, v0016);
    }

v0012:
    v0179 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0179); }
// error exit handlers
v0253:
    popv(2);
    return nil;
}



// Code for get_group_in

static LispObject CC_get_group_in(LispObject env,
                         LispObject v0000)
{
    LispObject v0024;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_group_in");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0024 = v0000;
// end of prologue
    v0024 = qcar(v0024);
    return onevalue(v0024);
}



// Code for ofsf_prepat

static LispObject CC_ofsf_prepat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0002;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_prepat");
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
    v0002 = stack[-1];
    stack[-2] = qcar(v0002);
    v0002 = stack[-1];
    v0002 = qcdr(v0002);
    v0002 = qcar(v0002);
    fn = elt(env, 1); // prepf
    stack[0] = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0002 = stack[-1];
    v0002 = qcdr(v0002);
    v0002 = qcdr(v0002);
    v0002 = qcar(v0002);
    fn = elt(env, 1); // prepf
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    {
        LispObject v0187 = stack[-2];
        LispObject v0004 = stack[0];
        popv(4);
        return list3(v0187, v0004, v0002);
    }
// error exit handlers
v0015:
    popv(4);
    return nil;
}



// Code for qsort

static LispObject CC_qsort(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0067, v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qsort");
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
    v0075 = v0000;
// end of prologue
    stack[-2] = nil;
    stack[-1] = nil;
    v0067 = v0075;
    if (v0067 == nil) goto v0264;
    v0067 = v0075;
    v0067 = qcar(v0067);
    stack[-3] = v0067;
    v0067 = v0075;
    v0067 = qcdr(v0067);
    stack[0] = v0067;
    goto v0007;

v0007:
    v0067 = stack[0];
    if (v0067 == nil) goto v0249;
    v0075 = stack[-3];
    v0067 = stack[0];
    v0067 = qcar(v0067);
    fn = elt(env, 2); // ordop
    v0067 = (*qfn2(fn))(qenv(fn), v0075, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-4];
    if (v0067 == nil) goto v0265;
    v0067 = stack[0];
    v0075 = qcar(v0067);
    v0067 = stack[-1];
    v0067 = cons(v0075, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-4];
    stack[-1] = v0067;
    goto v0187;

v0187:
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    stack[0] = v0067;
    goto v0007;

v0265:
    v0067 = stack[0];
    v0075 = qcar(v0067);
    v0067 = stack[-2];
    v0067 = cons(v0075, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-4];
    stack[-2] = v0067;
    goto v0187;

v0249:
    v0067 = stack[-2];
    stack[0] = CC_qsort(env, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-4];
    stack[-2] = stack[-3];
    v0067 = stack[-1];
    v0067 = CC_qsort(env, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-4];
    v0067 = cons(stack[-2], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    {
        LispObject v0266 = stack[0];
        popv(5);
        return Lappend(nil, v0266, v0067);
    }

v0264:
    v0067 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0067); }
// error exit handlers
v0044:
    popv(5);
    return nil;
}



// Code for cgb_buch!-ev_divides!?

static LispObject CC_cgb_buchKev_dividesW(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0009, v0264;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0264 = v0010;
    v0009 = v0000;
// end of prologue
    {
        fn = elt(env, 1); // ev_mtest!?
        return (*qfn2(fn))(qenv(fn), v0264, v0009);
    }
}



// Code for integerom

static LispObject CC_integerom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0267;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for integerom");
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
    v0267 = elt(env, 1); // "<OMI> "
    fn = elt(env, 3); // printout
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-1];
    v0267 = stack[0];
    v0267 = Lprinc(nil, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-1];
    v0267 = elt(env, 2); // " </OMI>"
    v0267 = Lprinc(nil, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    v0267 = nil;
    { popv(2); return onevalue(v0267); }
// error exit handlers
v0264:
    popv(2);
    return nil;
}



// Code for dfn_prop

static LispObject CC_dfn_prop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0070, v0071, v0265;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfn_prop");
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
    v0070 = v0000;
// end of prologue
    v0070 = qcdr(v0070);
    v0070 = Llength(nil, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[0];
    v0265 = v0070;
    v0071 = v0265;
    v0070 = (LispObject)17; // 1
    if (v0071 == v0070) goto v0007;
    v0071 = v0265;
    v0070 = (LispObject)33; // 2
    if (v0071 == v0070) goto v0019;
    v0071 = v0265;
    v0070 = (LispObject)49; // 3
    if (v0071 == v0070) goto v0005;
    v0070 = elt(env, 1); // dfn
    v0071 = v0265;
    {
        popv(1);
        fn = elt(env, 4); // mkid
        return (*qfn2(fn))(qenv(fn), v0070, v0071);
    }

v0005:
    v0070 = elt(env, 3); // dfn3
    { popv(1); return onevalue(v0070); }

v0019:
    v0070 = elt(env, 2); // dfn2
    { popv(1); return onevalue(v0070); }

v0007:
    v0070 = elt(env, 1); // dfn
    { popv(1); return onevalue(v0070); }
// error exit handlers
v0051:
    popv(1);
    return nil;
}



// Code for writepri

static LispObject CC_writepri(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0268, v0237, v0018;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for writepri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0010;
    v0268 = v0000;
// end of prologue
    fn = elt(env, 2); // eval
    v0018 = (*qfn1(fn))(qenv(fn), v0268);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0237 = qvalue(elt(env, 1)); // nil
    v0268 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); // assgnpri
        return (*qfnn(fn))(qenv(fn), 3, v0018, v0237, v0268);
    }
// error exit handlers
v0074:
    popv(2);
    return nil;
}



// Code for getphystypesf

static LispObject CC_getphystypesf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0180;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystypesf");
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

v0271:
    v0180 = stack[0];
    if (v0180 == nil) goto v0007;
    v0180 = stack[0];
    fn = elt(env, 3); // domain!*p
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    goto v0034;

v0034:
    if (v0180 == nil) goto v0018;
    v0180 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0180); }

v0018:
    v0180 = stack[0];
    v0180 = qcar(v0180);
    v0180 = qcar(v0180);
    v0180 = qcar(v0180);
    fn = elt(env, 4); // getphystype
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    if (!(v0180 == nil)) { popv(2); return onevalue(v0180); }
    v0180 = stack[0];
    v0180 = qcar(v0180);
    v0180 = qcdr(v0180);
    stack[0] = v0180;
    goto v0271;

v0007:
    v0180 = qvalue(elt(env, 1)); // t
    goto v0034;
// error exit handlers
v0054:
    popv(2);
    return nil;
}



// Code for tokquote

static LispObject CC_tokquote(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0008;
    LispObject fn;
    argcheck(nargs, 0, "tokquote");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tokquote");
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
    fn = elt(env, 6); // readch1
    v0008 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[0];
    qvalue(elt(env, 1)) = v0008; // crchar!*
    fn = elt(env, 7); // rread
    v0008 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[0];
    v0008 = Lmkquote(nil, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[0];
    qvalue(elt(env, 2)) = v0008; // nxtsym!*
    v0008 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0008; // curescaped!*
    v0008 = (LispObject)65; // 4
    qvalue(elt(env, 5)) = v0008; // ttype!*
    v0008 = qvalue(elt(env, 2)); // nxtsym!*
    { popv(1); return onevalue(v0008); }
// error exit handlers
v0267:
    popv(1);
    return nil;
}



// Code for argnochk

static LispObject CC_argnochk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0277, v0278, v0279;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for argnochk");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0000;
// end of prologue
    v0277 = qvalue(elt(env, 1)); // !*argnochk
    if (v0277 == nil) { LispObject res = stack[-5]; popv(8); return onevalue(res); }
    v0277 = stack[-5];
    v0277 = qcar(v0277);
    fn = elt(env, 12); // argsofopr
    v0277 = (*qfn1(fn))(qenv(fn), v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    stack[-6] = v0277;
    if (v0277 == nil) goto v0262;
    stack[0] = stack[-6];
    v0277 = stack[-5];
    v0277 = qcdr(v0277);
    v0277 = Llength(nil, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    if (equal(stack[0], v0277)) goto v0050;
    v0277 = stack[-5];
    v0277 = qcar(v0277);
    if (!symbolp(v0277)) v0277 = nil;
    else { v0277 = qfastgets(v0277);
           if (v0277 != nil) { v0277 = elt(v0277, 22); // simpfn
#ifdef RECORD_GET
             if (v0277 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0277 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0277 == SPID_NOPROP) v0277 = nil; }}
#endif
    if (!(v0277 == nil)) goto v0053;
    v0277 = stack[-5];
    v0277 = qcar(v0277);
    if (!symbolp(v0277)) v0277 = nil;
    else { v0277 = qfastgets(v0277);
           if (v0277 != nil) { v0277 = elt(v0277, 45); // psopfn
#ifdef RECORD_GET
             if (v0277 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0277 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0277 == SPID_NOPROP) v0277 = nil; }}
#endif
    if (!(v0277 == nil)) goto v0053;
    v0277 = stack[-5];
    v0278 = qcar(v0277);
    v0277 = elt(env, 2); // variadic
    v0277 = Lflagp(nil, v0278, v0277);
    env = stack[-7];
    goto v0053;

v0053:
    v0277 = (v0277 == nil ? lisp_true : nil);
    goto v0002;

v0002:
    if (v0277 == nil) { LispObject res = stack[-5]; popv(8); return onevalue(res); }
    v0277 = qvalue(elt(env, 4)); // !*strict_argcount
    if (v0277 == nil) goto v0280;
    v0277 = elt(env, 5); // "+++++ "
    v0277 = Lprinc(nil, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    v0277 = stack[-5];
    v0277 = Lprint(nil, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    stack[-4] = elt(env, 6); // rlisp
    stack[-3] = (LispObject)177; // 11
    v0277 = stack[-5];
    stack[-2] = qcar(v0277);
    stack[-1] = elt(env, 7); // "called with"
    v0277 = stack[-5];
    v0277 = qcdr(v0277);
    stack[0] = Llength(nil, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    v0277 = stack[-5];
    v0277 = qcdr(v0277);
    v0278 = Llength(nil, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    v0277 = (LispObject)17; // 1
    if (v0278 == v0277) goto v0174;
    v0277 = elt(env, 9); // "arguments"
    v0279 = v0277;
    goto v0281;

v0281:
    v0278 = elt(env, 10); // "instead of"
    v0277 = stack[-6];
    v0277 = list3(v0279, v0278, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    v0277 = list3star(stack[-2], stack[-1], stack[0], v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    fn = elt(env, 13); // rerror
    v0277 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[-3], v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    v0277 = nil;
    { popv(8); return onevalue(v0277); }

v0174:
    v0277 = elt(env, 8); // "argument"
    v0279 = v0277;
    goto v0281;

v0280:
    v0277 = stack[-5];
    stack[-2] = qcar(v0277);
    stack[-1] = elt(env, 7); // "called with"
    v0277 = stack[-5];
    v0277 = qcdr(v0277);
    stack[0] = Llength(nil, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    v0279 = elt(env, 10); // "instead of"
    v0278 = stack[-6];
    v0277 = elt(env, 9); // "arguments"
    v0277 = list3(v0279, v0278, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    v0277 = list3star(stack[-2], stack[-1], stack[0], v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    fn = elt(env, 14); // lprim
    v0277 = (*qfn1(fn))(qenv(fn), v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    { LispObject res = stack[-5]; popv(8); return onevalue(res); }

v0050:
    v0277 = qvalue(elt(env, 3)); // nil
    goto v0002;

v0262:
    v0277 = stack[-5];
    stack[-1] = qcar(v0277);
    stack[0] = elt(env, 11); // number!-of!-args
    v0277 = stack[-5];
    v0277 = qcdr(v0277);
    v0277 = Llength(nil, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-7];
    v0277 = Lputprop(nil, 3, stack[-1], stack[0], v0277);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    { LispObject res = stack[-5]; popv(8); return onevalue(res); }
// error exit handlers
v0194:
    popv(8);
    return nil;
}



// Code for listtest

static LispObject CC_listtest(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0179, v0016, v0017;
    LispObject v0001, v0010, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "listtest");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listtest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0010,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0010;
    stack[-2] = v0000;
// end of prologue

v0024:
    v0179 = stack[-2];
    if (v0179 == nil) goto v0008;
    v0017 = stack[0];
    v0179 = stack[-2];
    v0016 = qcar(v0179);
    v0179 = stack[-1];
    v0179 = Lapply2(nil, 3, v0017, v0016, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-3];
    if (v0179 == nil) goto v0025;
    v0179 = stack[-2];
    v0179 = qcar(v0179);
    if (v0179 == nil) goto v0006;
    v0179 = stack[-2];
    v0179 = qcar(v0179);
    { popv(4); return onevalue(v0179); }

v0006:
    v0179 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0179); }

v0025:
    v0179 = stack[-2];
    v0179 = qcdr(v0179);
    stack[-2] = v0179;
    goto v0024;

v0008:
    v0179 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0179); }
// error exit handlers
v0070:
    popv(4);
    return nil;
}



// Code for rl_external

static LispObject CC_rl_external(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0005, v0006, v0276;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_external");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0010;
    v0005 = v0000;
// end of prologue
    if (!symbolp(v0005)) v0005 = nil;
    else { v0005 = qfastgets(v0005);
           if (v0005 != nil) { v0005 = elt(v0005, 21); // rl_external
#ifdef RECORD_GET
             if (v0005 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v0005 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v0005 == SPID_NOPROP) v0005 = nil; }}
#endif
    v0276 = v0005;
    v0005 = v0276;
    if (v0005 == nil) goto v0008;
    v0005 = v0006;
    v0006 = v0276;
    v0005 = Latsoc(nil, v0005, v0006);
    v0276 = v0005;
    v0005 = v0276;
    if (v0005 == nil) goto v0008;
    v0005 = v0276;
    v0005 = qcdr(v0005);
    return onevalue(v0005);

v0008:
    v0005 = nil;
    return onevalue(v0005);
}



// Code for ibalp_getnewwl

static LispObject CC_ibalp_getnewwl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0038, v0258, v0274, v0283, v0060;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_getnewwl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0060 = v0000;
// end of prologue
    v0274 = nil;
    v0038 = v0060;
    v0038 = qcar(v0038);
    v0283 = v0038;
    goto v0267;

v0267:
    v0038 = v0283;
    if (v0038 == nil) goto v0008;
    v0038 = v0274;
    if (!(v0038 == nil)) goto v0008;
    v0038 = v0283;
    v0038 = qcar(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    if (v0038 == nil) goto v0181;
    v0038 = qvalue(elt(env, 1)); // nil
    goto v0015;

v0015:
    if (v0038 == nil) goto v0002;
    v0038 = v0283;
    v0038 = qcar(v0038);
    v0274 = v0038;
    goto v0002;

v0002:
    v0038 = v0283;
    v0038 = qcdr(v0038);
    v0283 = v0038;
    goto v0267;

v0181:
    v0038 = v0283;
    v0258 = qcar(v0038);
    v0038 = v0060;
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0038 = Lmemq(nil, v0258, v0038);
    v0038 = (v0038 == nil ? lisp_true : nil);
    goto v0015;

v0008:
    v0038 = v0060;
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0283 = v0038;
    goto v0249;

v0249:
    v0038 = v0283;
    if (v0038 == nil) return onevalue(v0274);
    v0038 = v0274;
    if (!(v0038 == nil)) return onevalue(v0274);
    v0038 = v0283;
    v0038 = qcar(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    if (v0038 == nil) goto v0044;
    v0038 = qvalue(elt(env, 1)); // nil
    goto v0066;

v0066:
    if (v0038 == nil) goto v0049;
    v0038 = v0283;
    v0038 = qcar(v0038);
    v0274 = v0038;
    goto v0049;

v0049:
    v0038 = v0283;
    v0038 = qcdr(v0038);
    v0283 = v0038;
    goto v0249;

v0044:
    v0038 = v0283;
    v0258 = qcar(v0038);
    v0038 = v0060;
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0038 = Lmemq(nil, v0258, v0038);
    v0038 = (v0038 == nil ? lisp_true : nil);
    goto v0066;
}



// Code for sfto_davp

static LispObject CC_sfto_davp(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0173, v0041;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_davp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0010;
    stack[-1] = v0000;
// end of prologue

v0024:
    v0173 = stack[-1];
    if (!consp(v0173)) goto v0269;
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    v0173 = (consp(v0173) ? nil : lisp_true);
    goto v0264;

v0264:
    if (v0173 == nil) goto v0187;
    v0173 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0173); }

v0187:
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0041 = qcdr(v0173);
    v0173 = (LispObject)33; // 2
    v0173 = (LispObject)greaterp2(v0041, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    v0173 = v0173 ? lisp_true : nil;
    env = stack[-2];
    if (v0173 == nil) goto v0176;
    v0173 = stack[0];
    if (v0173 == nil) goto v0249;
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0041 = qcar(v0173);
    v0173 = stack[0];
    if (equal(v0041, v0173)) goto v0249;
    v0173 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0173); }

v0249:
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    v0041 = qcdr(v0173);
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0173 = CC_sfto_davp(env, v0041, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    if (v0173 == nil) goto v0077;
    v0173 = stack[-1];
    v0173 = qcdr(v0173);
    v0041 = v0173;
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    stack[0] = v0173;
    v0173 = v0041;
    stack[-1] = v0173;
    goto v0024;

v0077:
    v0173 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0173); }

v0176:
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    v0041 = qcdr(v0173);
    v0173 = stack[0];
    v0173 = CC_sfto_davp(env, v0041, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    if (v0173 == nil) goto v0273;
    v0173 = stack[-1];
    v0173 = qcdr(v0173);
    stack[-1] = v0173;
    goto v0024;

v0273:
    v0173 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0173); }

v0269:
    v0173 = qvalue(elt(env, 1)); // t
    goto v0264;
// error exit handlers
v0038:
    popv(3);
    return nil;
}



// Code for naryrd

static LispObject CC_naryrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0002, v0003;
    LispObject fn;
    argcheck(nargs, 0, "naryrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for naryrd");
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
    fn = elt(env, 1); // mathml
    v0002 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-1];
    v0003 = v0002;
    v0002 = v0003;
    if (v0002 == nil) goto v0034;
    stack[0] = v0003;
    v0002 = CC_naryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    {
        LispObject v0015 = stack[0];
        popv(2);
        return cons(v0015, v0002);
    }

v0034:
    v0002 = nil;
    { popv(2); return onevalue(v0002); }
// error exit handlers
v0183:
    popv(2);
    return nil;
}



// Code for simpexpon1

static LispObject CC_simpexpon1(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0069, v0020;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpexpon1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0010;
    stack[-2] = v0000;
// end of prologue
    v0069 = qvalue(elt(env, 1)); // !*numval
    if (v0069 == nil) goto v0079;
    v0020 = qvalue(elt(env, 2)); // dmode!*
    v0069 = elt(env, 3); // !:rd!:
    if (v0020 == v0069) goto v0264;
    v0020 = qvalue(elt(env, 2)); // dmode!*
    v0069 = elt(env, 5); // !:cr!:
    v0069 = (v0020 == v0069 ? lisp_true : nil);
    goto v0009;

v0009:
    if (v0069 == nil) goto v0079;
    v0020 = stack[-1];
    v0069 = stack[-2];
        popv(5);
        return Lapply1(nil, v0020, v0069);

v0079:
    stack[-3] = qvalue(elt(env, 2)); // dmode!*
    qvalue(elt(env, 2)) = nil; // dmode!*
    stack[0] = qvalue(elt(env, 6)); // alglist!*
    qvalue(elt(env, 6)) = nil; // alglist!*
    v0069 = qvalue(elt(env, 7)); // nil
    v0069 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-4];
    qvalue(elt(env, 6)) = v0069; // alglist!*
    v0020 = stack[-1];
    v0069 = stack[-2];
    v0069 = Lapply1(nil, v0020, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; // alglist!*
    qvalue(elt(env, 2)) = stack[-3]; // dmode!*
    { popv(5); return onevalue(v0069); }

v0264:
    v0069 = qvalue(elt(env, 4)); // t
    goto v0009;
// error exit handlers
v0284:
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; // alglist!*
    qvalue(elt(env, 2)) = stack[-3]; // dmode!*
    popv(5);
    return nil;
}



// Code for c!:extadd

static LispObject CC_cTextadd(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0287, v0032, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:extadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0010;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0007;

v0007:
    v0287 = stack[-1];
    if (v0287 == nil) goto v0264;
    v0287 = stack[0];
    if (v0287 == nil) goto v0237;
    v0287 = stack[-1];
    v0287 = qcar(v0287);
    v0032 = qcar(v0287);
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    if (equal(v0032, v0287)) goto v0053;
    v0287 = stack[-1];
    v0287 = qcar(v0287);
    v0032 = qcar(v0287);
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    fn = elt(env, 2); // c!:ordexp
    v0287 = (*qfn2(fn))(qenv(fn), v0032, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    if (v0287 == nil) goto v0273;
    v0287 = stack[-1];
    v0032 = qcar(v0287);
    v0287 = stack[-2];
    v0287 = cons(v0032, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    stack[-2] = v0287;
    v0287 = stack[-1];
    v0287 = qcdr(v0287);
    stack[-1] = v0287;
    goto v0007;

v0273:
    v0287 = stack[0];
    v0032 = qcar(v0287);
    v0287 = stack[-2];
    v0287 = cons(v0032, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    stack[-2] = v0287;
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = v0287;
    goto v0007;

v0053:
    v0287 = stack[-1];
    v0287 = qcar(v0287);
    v0032 = qcdr(v0287);
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcdr(v0287);
    fn = elt(env, 3); // addf
    v0287 = (*qfn2(fn))(qenv(fn), v0032, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    v0032 = v0287;
    if (v0032 == nil) goto v0026;
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0033 = qcar(v0032);
    v0032 = v0287;
    v0287 = stack[-2];
    v0287 = acons(v0033, v0032, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    stack[-2] = v0287;
    v0287 = stack[-1];
    v0287 = qcdr(v0287);
    stack[-1] = v0287;
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = v0287;
    goto v0007;

v0026:
    v0287 = stack[-1];
    v0287 = qcdr(v0287);
    stack[-1] = v0287;
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = v0287;
    goto v0007;

v0237:
    v0287 = stack[-1];
    v0032 = v0287;
    goto v0275;

v0275:
    v0287 = stack[-2];
    if (v0287 == nil) { popv(4); return onevalue(v0032); }
    v0287 = stack[-2];
    v0287 = qcar(v0287);
    v0287 = cons(v0287, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    v0032 = v0287;
    v0287 = stack[-2];
    v0287 = qcdr(v0287);
    stack[-2] = v0287;
    goto v0275;

v0264:
    v0287 = stack[0];
    v0032 = v0287;
    goto v0275;
// error exit handlers
v0056:
    popv(4);
    return nil;
}



// Code for comm_kernels1

static LispObject CC_comm_kernels1(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0048, v0049;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comm_kernels1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0010;
    v0048 = v0000;
// end of prologue

v0271:
    v0049 = v0048;
    if (!consp(v0049)) goto v0008;
    v0049 = v0048;
    v0049 = qcar(v0049);
    v0049 = (consp(v0049) ? nil : lisp_true);
    goto v0007;

v0007:
    if (!(v0049 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0049 = v0048;
    v0049 = qcar(v0049);
    v0049 = qcar(v0049);
    v0049 = qcar(v0049);
    stack[-3] = v0049;
    v0049 = v0048;
    v0049 = qcar(v0049);
    stack[-1] = qcdr(v0049);
    stack[0] = qcdr(v0048);
    v0049 = stack[-3];
    v0048 = stack[-2];
    v0048 = Lmemq(nil, v0049, v0048);
    if (!(v0048 == nil)) goto v0253;
    v0048 = stack[-3];
    fn = elt(env, 2); // noncomp
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    if (!(v0048 == nil)) goto v0253;
    v0048 = stack[-3];
    v0048 = ncons(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    v0048 = Lappend(nil, stack[-2], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    goto v0068;

v0068:
    v0049 = CC_comm_kernels1(env, stack[0], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    v0048 = stack[-1];
    stack[-2] = v0049;
    goto v0271;

v0253:
    v0048 = stack[-2];
    goto v0068;

v0008:
    v0049 = qvalue(elt(env, 1)); // t
    goto v0007;
// error exit handlers
v0067:
    popv(5);
    return nil;
}



// Code for sc_setmat

static LispObject CC_sc_setmat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0183, v0015;
    LispObject v0035, v0001, v0010, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "sc_setmat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0035 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_setmat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0035,v0001,v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0010,v0001,v0035);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0035;
    stack[-1] = v0001;
    v0183 = v0010;
    v0015 = v0000;
// end of prologue
    stack[-2] = v0015;
    v0183 = sub1(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    stack[-2] = *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)v0183/(16/CELL)));
    v0183 = stack[-1];
    v0015 = sub1(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    v0183 = stack[0];
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)v0015/(16/CELL))) = v0183;
    { popv(4); return onevalue(v0183); }
// error exit handlers
v0006:
    popv(4);
    return nil;
}



// Code for revalind

static LispObject CC_revalind(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0005, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revalind");
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
    stack[0] = qvalue(elt(env, 1)); // alglist!*
    qvalue(elt(env, 1)) = nil; // alglist!*
    v0004 = qvalue(elt(env, 2)); // nil
    v0004 = ncons(v0004);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0004; // alglist!*
    v0004 = qvalue(elt(env, 3)); // subfg!*
    stack[-2] = v0004;
    v0004 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 3)) = v0004; // subfg!*
    v0006 = elt(env, 4); // !0
    v0005 = (LispObject)1; // 0
    v0004 = stack[-1];
    v0004 = Lsubst(nil, 3, v0006, v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    stack[-1] = v0004;
    v0004 = stack[-1];
    fn = elt(env, 5); // simp
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    fn = elt(env, 6); // prepsq
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    v0005 = v0004;
    v0004 = stack[-2];
    qvalue(elt(env, 3)) = v0004; // subfg!*
    v0004 = v0005;
    qvalue(elt(env, 1)) = stack[0]; // alglist!*
    { popv(4); return onevalue(v0004); }
// error exit handlers
v0054:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; // alglist!*
    popv(4);
    return nil;
}



// Code for chknewnam

static LispObject CC_chknewnam(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0072, v0073, v0250, v0025;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chknewnam");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0250 = v0000;
// end of prologue

v0271:
    v0072 = v0250;
    if (!symbolp(v0072)) v0072 = nil;
    else { v0072 = qfastgets(v0072);
           if (v0072 != nil) { v0072 = elt(v0072, 28); // newnam
#ifdef RECORD_GET
             if (v0072 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v0072 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v0072 == SPID_NOPROP) v0072 = nil; }}
#endif
    v0025 = v0072;
    if (v0072 == nil) goto v0009;
    v0073 = v0025;
    v0072 = v0250;
    v0072 = (v0073 == v0072 ? lisp_true : nil);
    goto v0267;

v0267:
    if (!(v0072 == nil)) return onevalue(v0250);
    v0072 = v0025;
    if (!(symbolp(v0072))) return onevalue(v0025);
    v0072 = v0025;
    v0250 = v0072;
    goto v0271;

v0009:
    v0072 = qvalue(elt(env, 1)); // t
    goto v0267;
}



// Code for mv!-pow!-!-

static LispObject CC_mvKpowKK(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0250, v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow--");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0010;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0024;

v0024:
    v0250 = stack[-1];
    if (v0250 == nil) goto v0008;
    v0250 = stack[-1];
    v0025 = qcar(v0250);
    v0250 = stack[0];
    v0250 = qcar(v0250);
    v0025 = difference2(v0025, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-3];
    v0250 = stack[-2];
    v0250 = cons(v0025, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-3];
    stack[-2] = v0250;
    v0250 = stack[-1];
    v0250 = qcdr(v0250);
    stack[-1] = v0250;
    v0250 = stack[0];
    v0250 = qcdr(v0250);
    stack[0] = v0250;
    goto v0024;

v0008:
    v0250 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0250);
    }
// error exit handlers
v0179:
    popv(4);
    return nil;
}



// Code for make!-term

static LispObject CC_makeKterm(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0255, v0306, v0307;
    LispObject fn;
    LispObject v0001, v0010, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "make-term");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0010,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-3] = v0001;
    stack[-4] = v0010;
    stack[-5] = v0000;
// end of prologue
    v0255 = (LispObject)1; // 0
    stack[-2] = v0255;
    v0255 = (LispObject)1; // 0
    stack[0] = v0255;
    goto v0003;

v0003:
    v0306 = stack[-4];
    v0255 = stack[0];
    v0306 = *(LispObject *)((char *)v0306 + (CELL-TAG_VECTOR) + ((int32_t)v0255/(16/CELL)));
    v0255 = (LispObject)1; // 0
    v0255 = (LispObject)lessp2(v0306, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    v0255 = v0255 ? lisp_true : nil;
    env = stack[-7];
    if (v0255 == nil) goto v0079;
    v0255 = (LispObject)-15; // -1
    stack[-2] = v0255;
    goto v0269;

v0269:
    v0255 = (LispObject)49; // 3
    v0255 = Lmkvect(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    env = stack[-7];
    stack[-6] = v0255;
    v0306 = stack[-2];
    v0255 = (LispObject)17; // 1
    if (v0306 == v0255) goto v0044;
    v0306 = stack[-5];
    v0255 = elt(env, 4); // cos
    v0255 = (v0306 == v0255 ? lisp_true : nil);
    goto v0043;

v0043:
    if (v0255 == nil) goto v0248;
    v0307 = stack[-6];
    v0306 = (LispObject)1; // 0
    v0255 = stack[-3];
    *(LispObject *)((char *)v0307 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL))) = v0255;
    goto v0287;

v0287:
    v0307 = stack[-6];
    v0306 = (LispObject)17; // 1
    v0255 = stack[-5];
    *(LispObject *)((char *)v0307 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL))) = v0255;
    v0306 = stack[-2];
    v0255 = (LispObject)-15; // -1
    if (!(v0306 == v0255)) goto v0309;
    v0255 = (LispObject)113; // 7
    v0255 = Lmkvect(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    env = stack[-7];
    stack[-2] = v0255;
    v0255 = (LispObject)1; // 0
    stack[-3] = v0255;
    goto v0243;

v0243:
    v0306 = (LispObject)113; // 7
    v0255 = stack[-3];
    v0255 = difference2(v0306, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    env = stack[-7];
    v0255 = Lminusp(nil, v0255);
    env = stack[-7];
    if (v0255 == nil) goto v0310;
    v0255 = stack[-2];
    stack[-4] = v0255;
    goto v0309;

v0309:
    v0307 = stack[-6];
    v0306 = (LispObject)33; // 2
    v0255 = stack[-4];
    *(LispObject *)((char *)v0307 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL))) = v0255;
    v0306 = stack[-6];
    v0255 = (LispObject)49; // 3
    v0307 = qvalue(elt(env, 2)); // nil
    *(LispObject *)((char *)v0306 + (CELL-TAG_VECTOR) + ((int32_t)v0255/(16/CELL))) = v0307;
    { LispObject res = stack[-6]; popv(8); return onevalue(res); }

v0310:
    stack[-1] = stack[-2];
    stack[0] = stack[-3];
    v0306 = stack[-4];
    v0255 = stack[-3];
    v0255 = *(LispObject *)((char *)v0306 + (CELL-TAG_VECTOR) + ((int32_t)v0255/(16/CELL)));
    v0255 = negate(v0255);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    env = stack[-7];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0255;
    v0255 = stack[-3];
    v0255 = add1(v0255);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    env = stack[-7];
    stack[-3] = v0255;
    goto v0243;

v0248:
    stack[-1] = stack[-6];
    stack[0] = (LispObject)1; // 0
    v0306 = elt(env, 5); // (-1 . 1)
    v0255 = stack[-3];
    fn = elt(env, 6); // multsq
    v0255 = (*qfn2(fn))(qenv(fn), v0306, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    env = stack[-7];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0255;
    goto v0287;

v0044:
    v0255 = qvalue(elt(env, 3)); // t
    goto v0043;

v0079:
    v0306 = stack[-4];
    v0255 = stack[0];
    v0306 = *(LispObject *)((char *)v0306 + (CELL-TAG_VECTOR) + ((int32_t)v0255/(16/CELL)));
    v0255 = (LispObject)1; // 0
    v0255 = (LispObject)greaterp2(v0306, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0308;
    v0255 = v0255 ? lisp_true : nil;
    env = stack[-7];
    if (v0255 == nil) goto v0013;
    v0255 = (LispObject)17; // 1
    stack[-2] = v0255;
    goto v0269;

v0013:
    v0306 = stack[0];
    v0255 = (LispObject)113; // 7
    if (v0306 == v0255) goto v0022;
    v0255 = stack[0];
    v0255 = (LispObject)((int32_t)(v0255) + 0x10);
    stack[0] = v0255;
    goto v0003;

v0022:
    v0306 = stack[-5];
    v0255 = elt(env, 1); // sin
    if (!(v0306 == v0255)) goto v0269;
    v0255 = qvalue(elt(env, 2)); // nil
    { popv(8); return onevalue(v0255); }
// error exit handlers
v0308:
    popv(8);
    return nil;
}



// Code for dp!=mocompare

static LispObject CC_dpMmocompare(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0023, v0002;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=mocompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0023 = v0010;
    v0002 = v0000;
// end of prologue
    v0002 = qcar(v0002);
    v0023 = qcar(v0023);
    fn = elt(env, 1); // mo_compare
    v0002 = (*qfn2(fn))(qenv(fn), v0002, v0023);
    errexit();
    v0023 = (LispObject)17; // 1
        return Leqn(nil, v0002, v0023);
}



// Code for raiseind!:

static LispObject CC_raiseindT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0269, v0270;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for raiseind:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0269 = v0000;
// end of prologue
    v0270 = v0269;
    if (!consp(v0270)) return onevalue(v0269);
    v0269 = qcdr(v0269);
    v0269 = qcar(v0269);
    return onevalue(v0269);
}



// Code for b!:ordexn

static LispObject CC_bTordexn(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0190, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:ordexn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0010;
    stack[-2] = v0000;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
    goto v0008;

v0008:
    v0190 = stack[-1];
    if (v0190 == nil) goto v0007;
    v0039 = stack[-2];
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = (LispObject)lessp2(v0039, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-4];
    if (v0190 == nil) goto v0007;
    v0190 = stack[-1];
    v0039 = qcar(v0190);
    v0190 = stack[-3];
    v0190 = cons(v0039, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    stack[-3] = v0190;
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    stack[-1] = v0190;
    v0190 = stack[0];
    v0190 = (v0190 == nil ? lisp_true : nil);
    stack[0] = v0190;
    goto v0008;

v0007:
    v0190 = stack[-1];
    if (v0190 == nil) goto v0052;
    v0039 = stack[-2];
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = Leqn(nil, v0039, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    if (v0190 == nil) goto v0176;
    v0190 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0190); }

v0176:
    v0039 = stack[-2];
    v0190 = stack[-3];
    v0190 = cons(v0039, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0039 = Lnreverse(nil, v0190);
    env = stack[-4];
    v0190 = stack[-1];
    v0190 = Lnconc(nil, v0039, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    {
        LispObject v0041 = stack[0];
        popv(5);
        return cons(v0041, v0190);
    }

v0052:
    v0039 = stack[-2];
    v0190 = stack[-3];
    v0190 = cons(v0039, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0190 = Lnreverse(nil, v0190);
    {
        LispObject v0042 = stack[0];
        popv(5);
        return cons(v0042, v0190);
    }
// error exit handlers
v0173:
    popv(5);
    return nil;
}



// Code for freeofl

static LispObject CC_freeofl(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0073, v0250;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeofl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0010;
    stack[-1] = v0000;
// end of prologue

v0271:
    v0073 = stack[0];
    if (v0073 == nil) goto v0011;
    v0250 = stack[-1];
    v0073 = stack[0];
    v0073 = qcar(v0073);
    fn = elt(env, 3); // freeof
    v0073 = (*qfn2(fn))(qenv(fn), v0250, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    if (v0073 == nil) goto v0269;
    v0250 = stack[-1];
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    stack[-1] = v0250;
    stack[0] = v0073;
    goto v0271;

v0269:
    v0073 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0073); }

v0011:
    v0073 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0073); }
// error exit handlers
v0079:
    popv(3);
    return nil;
}



// Code for msappend

static LispObject CC_msappend(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0048, v0049;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for msappend");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0010;
    v0048 = v0000;
// end of prologue
    stack[-5] = v0048;
    v0048 = stack[-5];
    if (v0048 == nil) goto v0264;
    v0048 = stack[-5];
    v0048 = qcar(v0048);
    stack[0] = stack[-4];
    v0049 = stack[-4];
    v0048 = Lsublis(nil, v0049, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0048 = Lappend(nil, stack[0], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0048 = ncons(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    stack[-2] = v0048;
    stack[-3] = v0048;
    goto v0007;

v0007:
    v0048 = stack[-5];
    v0048 = qcdr(v0048);
    stack[-5] = v0048;
    v0048 = stack[-5];
    if (v0048 == nil) { LispObject res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0048 = stack[-5];
    v0048 = qcar(v0048);
    stack[0] = stack[-4];
    v0049 = stack[-4];
    v0048 = Lsublis(nil, v0049, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0048 = Lappend(nil, stack[0], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0048 = ncons(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0048 = Lrplacd(nil, stack[-1], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0048 = stack[-2];
    v0048 = qcdr(v0048);
    stack[-2] = v0048;
    goto v0007;

v0264:
    v0048 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0048); }
// error exit handlers
v0076:
    popv(7);
    return nil;
}



// Code for mk!+mat!+mult!+mat

static LispObject CC_mkLmatLmultLmat(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0213, v0359, v0360;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+mat+mult+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-13] = v0010;
    stack[-14] = v0000;
// end of prologue
    v0213 = stack[-14];
    fn = elt(env, 6); // matrix!+p
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    if (!(v0213 == nil)) goto v0270;
    v0213 = elt(env, 1); // "no matrix in mult"
    fn = elt(env, 7); // rederr
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    goto v0270;

v0270:
    v0213 = stack[-13];
    fn = elt(env, 6); // matrix!+p
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    if (!(v0213 == nil)) goto v0003;
    v0213 = elt(env, 1); // "no matrix in mult"
    fn = elt(env, 7); // rederr
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    goto v0003;

v0003:
    v0213 = stack[-14];
    fn = elt(env, 8); // get!+col!+nr
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-15] = v0213;
    v0213 = stack[-14];
    fn = elt(env, 9); // get!+row!+nr
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-12] = v0213;
    v0213 = stack[-13];
    fn = elt(env, 8); // get!+col!+nr
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-11] = v0213;
    stack[0] = stack[-15];
    v0213 = stack[-13];
    fn = elt(env, 9); // get!+row!+nr
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    if (equal(stack[0], v0213)) goto v0073;
    v0213 = elt(env, 2); // "matrices can not be multiplied"
    fn = elt(env, 7); // rederr
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    goto v0073;

v0073:
    v0213 = (LispObject)17; // 1
    stack[-10] = v0213;
    v0359 = stack[-12];
    v0213 = stack[-10];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0020;
    v0213 = qvalue(elt(env, 3)); // nil
    { popv(17); return onevalue(v0213); }

v0020:
    v0213 = (LispObject)17; // 1
    stack[-5] = v0213;
    v0359 = stack[-11];
    v0213 = stack[-5];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0233;
    v0213 = qvalue(elt(env, 3)); // nil
    goto v0065;

v0065:
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-8] = v0213;
    stack[-9] = v0213;
    goto v0052;

v0052:
    v0213 = stack[-10];
    v0213 = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-10] = v0213;
    v0359 = stack[-12];
    v0213 = stack[-10];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (!(v0213 == nil)) { LispObject res = stack[-9]; popv(17); return onevalue(res); }
    stack[-7] = stack[-8];
    v0213 = (LispObject)17; // 1
    stack[-6] = v0213;
    v0359 = stack[-11];
    v0213 = stack[-6];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0362;
    v0213 = qvalue(elt(env, 3)); // nil
    goto v0363;

v0363:
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lrplacd(nil, stack[-7], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = stack[-8];
    v0213 = qcdr(v0213);
    stack[-8] = v0213;
    goto v0052;

v0362:
    v0359 = qvalue(elt(env, 3)); // nil
    v0213 = (LispObject)17; // 1
    v0213 = cons(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[0] = v0213;
    v0213 = (LispObject)17; // 1
    stack[-1] = v0213;
    goto v0364;

v0364:
    v0359 = stack[-15];
    v0213 = stack[-1];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0145;
    v0213 = qvalue(elt(env, 4)); // t
    stack[-1] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0213; // !*sub2
    v0213 = stack[0];
    fn = elt(env, 10); // subs2
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-16];
    stack[0] = v0213;
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    v0213 = stack[0];
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-4] = v0213;
    stack[-5] = v0213;
    goto v0365;

v0365:
    v0213 = stack[-6];
    v0213 = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-6] = v0213;
    v0359 = stack[-11];
    v0213 = stack[-6];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0366;
    v0213 = stack[-5];
    goto v0363;

v0366:
    stack[-3] = stack[-4];
    v0359 = qvalue(elt(env, 3)); // nil
    v0213 = (LispObject)17; // 1
    v0213 = cons(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[0] = v0213;
    v0213 = (LispObject)17; // 1
    stack[-2] = v0213;
    goto v0367;

v0367:
    v0359 = stack[-15];
    v0213 = stack[-2];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0136;
    v0213 = qvalue(elt(env, 4)); // t
    stack[-1] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0213; // !*sub2
    v0213 = stack[0];
    fn = elt(env, 10); // subs2
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-16];
    stack[0] = v0213;
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    v0213 = stack[0];
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lrplacd(nil, stack[-3], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = stack[-4];
    v0213 = qcdr(v0213);
    stack[-4] = v0213;
    goto v0365;

v0136:
    stack[-1] = stack[0];
    v0360 = stack[-14];
    v0359 = stack[-10];
    v0213 = stack[-2];
    fn = elt(env, 11); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0360, v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0360 = stack[-13];
    v0359 = stack[-2];
    v0213 = stack[-6];
    fn = elt(env, 11); // get!+mat!+entry
    v0213 = (*qfnn(fn))(qenv(fn), 3, v0360, v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    fn = elt(env, 12); // multsq
    v0213 = (*qfn2(fn))(qenv(fn), stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    fn = elt(env, 13); // addsq
    v0213 = (*qfn2(fn))(qenv(fn), stack[-1], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[0] = v0213;
    v0213 = stack[-2];
    v0213 = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-2] = v0213;
    goto v0367;

v0145:
    stack[-2] = stack[0];
    v0360 = stack[-14];
    v0359 = stack[-10];
    v0213 = stack[-1];
    fn = elt(env, 11); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0360, v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0360 = stack[-13];
    v0359 = stack[-1];
    v0213 = stack[-6];
    fn = elt(env, 11); // get!+mat!+entry
    v0213 = (*qfnn(fn))(qenv(fn), 3, v0360, v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    fn = elt(env, 12); // multsq
    v0213 = (*qfn2(fn))(qenv(fn), stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    fn = elt(env, 13); // addsq
    v0213 = (*qfn2(fn))(qenv(fn), stack[-2], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[0] = v0213;
    v0213 = stack[-1];
    v0213 = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-1] = v0213;
    goto v0364;

v0233:
    v0359 = qvalue(elt(env, 3)); // nil
    v0213 = (LispObject)17; // 1
    v0213 = cons(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[0] = v0213;
    v0213 = (LispObject)17; // 1
    stack[-1] = v0213;
    goto v0060;

v0060:
    v0359 = stack[-15];
    v0213 = stack[-1];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0369;
    v0213 = qvalue(elt(env, 4)); // t
    stack[-1] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0213; // !*sub2
    v0213 = stack[0];
    fn = elt(env, 10); // subs2
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-16];
    stack[0] = v0213;
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    v0213 = stack[0];
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-3] = v0213;
    stack[-4] = v0213;
    goto v0066;

v0066:
    v0213 = stack[-5];
    v0213 = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-5] = v0213;
    v0359 = stack[-11];
    v0213 = stack[-5];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0195;
    v0213 = stack[-4];
    goto v0065;

v0195:
    stack[-2] = stack[-3];
    v0359 = qvalue(elt(env, 3)); // nil
    v0213 = (LispObject)17; // 1
    v0213 = cons(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[0] = v0213;
    v0213 = (LispObject)17; // 1
    stack[-1] = v0213;
    goto v0168;

v0168:
    v0359 = stack[-15];
    v0213 = stack[-1];
    v0213 = difference2(v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lminusp(nil, v0213);
    env = stack[-16];
    if (v0213 == nil) goto v0291;
    v0213 = qvalue(elt(env, 4)); // t
    stack[-1] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0213; // !*sub2
    v0213 = stack[0];
    fn = elt(env, 10); // subs2
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[0] = v0213;
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    v0213 = stack[0];
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = Lrplacd(nil, stack[-2], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    stack[-3] = v0213;
    goto v0066;

v0291:
    stack[-6] = stack[0];
    v0360 = stack[-14];
    v0359 = stack[-10];
    v0213 = stack[-1];
    fn = elt(env, 11); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0360, v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0360 = stack[-13];
    v0359 = stack[-1];
    v0213 = stack[-5];
    fn = elt(env, 11); // get!+mat!+entry
    v0213 = (*qfnn(fn))(qenv(fn), 3, v0360, v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    fn = elt(env, 12); // multsq
    v0213 = (*qfn2(fn))(qenv(fn), stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    fn = elt(env, 13); // addsq
    v0213 = (*qfn2(fn))(qenv(fn), stack[-6], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[0] = v0213;
    v0213 = stack[-1];
    v0213 = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-1] = v0213;
    goto v0168;

v0369:
    stack[-2] = stack[0];
    v0360 = stack[-14];
    v0359 = stack[-10];
    v0213 = stack[-1];
    fn = elt(env, 11); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0360, v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    v0360 = stack[-13];
    v0359 = stack[-1];
    v0213 = stack[-5];
    fn = elt(env, 11); // get!+mat!+entry
    v0213 = (*qfnn(fn))(qenv(fn), 3, v0360, v0359, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    fn = elt(env, 12); // multsq
    v0213 = (*qfn2(fn))(qenv(fn), stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    fn = elt(env, 13); // addsq
    v0213 = (*qfn2(fn))(qenv(fn), stack[-2], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[0] = v0213;
    v0213 = stack[-1];
    v0213 = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-16];
    stack[-1] = v0213;
    goto v0060;
// error exit handlers
v0371:
    env = stack[-16];
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    popv(17);
    return nil;
v0370:
    env = stack[-16];
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    popv(17);
    return nil;
v0368:
    env = stack[-16];
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    popv(17);
    return nil;
v0214:
    env = stack[-16];
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    popv(17);
    return nil;
v0361:
    popv(17);
    return nil;
}



// Code for cl_fvarl1

static LispObject CC_cl_fvarl1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0011;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_fvarl1");
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
    v0011 = v0000;
// end of prologue
    fn = elt(env, 1); // cl_varl1
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    errexit();
    v0011 = qcar(v0011);
    return onevalue(v0011);
}



// Code for cl_varl2

static LispObject CC_cl_varl2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0396, v0397, v0142, v0398;
    LispObject fn;
    LispObject v0035, v0001, v0010, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_varl2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0035 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_varl2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0035,v0001,v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0010,v0001,v0035);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0035;
    stack[-1] = v0001;
    stack[-2] = v0010;
    stack[-3] = v0000;
// end of prologue

v0271:
    v0396 = stack[-3];
    if (!consp(v0396)) goto v0267;
    v0396 = stack[-3];
    v0396 = qcar(v0396);
    goto v0008;

v0008:
    v0142 = v0396;
    v0397 = v0142;
    v0396 = elt(env, 1); // true
    if (v0397 == v0396) goto v0183;
    v0397 = v0142;
    v0396 = elt(env, 3); // false
    v0396 = (v0397 == v0396 ? lisp_true : nil);
    goto v0182;

v0182:
    if (v0396 == nil) goto v0191;
    v0397 = stack[-2];
    v0396 = stack[0];
    popv(6);
    return cons(v0397, v0396);

v0191:
    v0397 = v0142;
    v0396 = elt(env, 4); // or
    if (v0397 == v0396) goto v0178;
    v0397 = v0142;
    v0396 = elt(env, 5); // and
    v0396 = (v0397 == v0396 ? lisp_true : nil);
    goto v0045;

v0045:
    if (v0396 == nil) goto v0175;
    v0396 = qvalue(elt(env, 2)); // t
    goto v0249;

v0249:
    if (v0396 == nil) goto v0173;
    v0396 = qvalue(elt(env, 2)); // t
    goto v0020;

v0020:
    if (v0396 == nil) goto v0399;
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    stack[-3] = v0396;
    goto v0057;

v0057:
    v0396 = stack[-3];
    if (v0396 == nil) goto v0242;
    v0396 = stack[-3];
    v0396 = qcar(v0396);
    v0398 = v0396;
    v0142 = stack[-2];
    v0397 = stack[-1];
    v0396 = stack[0];
    v0396 = CC_cl_varl2(env, 4, v0398, v0142, v0397, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0397 = v0396;
    v0396 = v0397;
    v0396 = qcar(v0396);
    stack[-2] = v0396;
    v0396 = v0397;
    v0396 = qcdr(v0396);
    stack[0] = v0396;
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    stack[-3] = v0396;
    goto v0057;

v0242:
    v0397 = stack[-2];
    v0396 = stack[0];
    popv(6);
    return cons(v0397, v0396);

v0399:
    v0397 = v0142;
    v0396 = elt(env, 11); // ex
    if (v0397 == v0396) goto v0296;
    v0397 = v0142;
    v0396 = elt(env, 12); // all
    v0396 = (v0397 == v0396 ? lisp_true : nil);
    goto v0400;

v0400:
    if (v0396 == nil) goto v0401;
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    v0396 = qcdr(v0396);
    stack[-4] = qcar(v0396);
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    v0397 = qcar(v0396);
    v0396 = stack[-1];
    fn = elt(env, 15); // lto_insertq
    v0397 = (*qfn2(fn))(qenv(fn), v0397, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0396 = stack[0];
    stack[-3] = stack[-4];
    stack[-1] = v0397;
    stack[0] = v0396;
    goto v0271;

v0401:
    v0397 = v0142;
    v0396 = elt(env, 13); // bex
    if (v0397 == v0396) goto v0402;
    v0397 = v0142;
    v0396 = elt(env, 14); // ball
    v0396 = (v0397 == v0396 ? lisp_true : nil);
    goto v0403;

v0403:
    if (v0396 == nil) goto v0354;
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    v0397 = qcar(v0396);
    v0396 = stack[-1];
    fn = elt(env, 15); // lto_insertq
    v0396 = (*qfn2(fn))(qenv(fn), v0397, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    stack[-1] = v0396;
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    v0396 = qcdr(v0396);
    v0396 = qcdr(v0396);
    v0398 = qcar(v0396);
    v0142 = stack[-2];
    v0397 = stack[-1];
    v0396 = stack[0];
    v0396 = CC_cl_varl2(env, 4, v0398, v0142, v0397, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0397 = v0396;
    v0396 = v0397;
    v0396 = qcar(v0396);
    stack[-2] = v0396;
    v0396 = v0397;
    v0396 = qcdr(v0396);
    stack[0] = v0396;
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    v0396 = qcdr(v0396);
    stack[-4] = qcar(v0396);
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    v0397 = qcar(v0396);
    v0396 = stack[-1];
    fn = elt(env, 15); // lto_insertq
    v0397 = (*qfn2(fn))(qenv(fn), v0397, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0396 = stack[0];
    stack[-3] = stack[-4];
    stack[-1] = v0397;
    stack[0] = v0396;
    goto v0271;

v0354:
    v0396 = stack[-3];
    fn = elt(env, 16); // rl_varlat
    v0396 = (*qfn1(fn))(qenv(fn), v0396);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    stack[-3] = v0396;
    goto v0148;

v0148:
    v0396 = stack[-3];
    if (v0396 == nil) goto v0404;
    v0396 = stack[-3];
    v0396 = qcar(v0396);
    v0142 = v0396;
    v0397 = v0142;
    v0396 = stack[-1];
    v0396 = Lmemq(nil, v0397, v0396);
    if (v0396 == nil) goto v0405;
    v0397 = v0142;
    v0396 = stack[0];
    fn = elt(env, 15); // lto_insertq
    v0396 = (*qfn2(fn))(qenv(fn), v0397, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    stack[0] = v0396;
    goto v0406;

v0406:
    v0396 = stack[-3];
    v0396 = qcdr(v0396);
    stack[-3] = v0396;
    goto v0148;

v0405:
    v0397 = v0142;
    v0396 = stack[-2];
    fn = elt(env, 15); // lto_insertq
    v0396 = (*qfn2(fn))(qenv(fn), v0397, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    stack[-2] = v0396;
    goto v0406;

v0404:
    v0397 = stack[-2];
    v0396 = stack[0];
    popv(6);
    return cons(v0397, v0396);

v0402:
    v0396 = qvalue(elt(env, 2)); // t
    goto v0403;

v0296:
    v0396 = qvalue(elt(env, 2)); // t
    goto v0400;

v0173:
    v0397 = v0142;
    v0396 = elt(env, 7); // impl
    if (v0397 == v0396) goto v0407;
    v0397 = v0142;
    v0396 = elt(env, 8); // repl
    if (v0397 == v0396) goto v0408;
    v0397 = v0142;
    v0396 = elt(env, 9); // equiv
    v0396 = (v0397 == v0396 ? lisp_true : nil);
    goto v0020;

v0408:
    v0396 = qvalue(elt(env, 2)); // t
    goto v0020;

v0407:
    v0396 = qvalue(elt(env, 2)); // t
    goto v0020;

v0175:
    v0397 = v0142;
    v0396 = elt(env, 6); // not
    v0396 = (v0397 == v0396 ? lisp_true : nil);
    goto v0249;

v0178:
    v0396 = qvalue(elt(env, 2)); // t
    goto v0045;

v0183:
    v0396 = qvalue(elt(env, 2)); // t
    goto v0182;

v0267:
    v0396 = stack[-3];
    goto v0008;
// error exit handlers
v0139:
    popv(6);
    return nil;
}



// Code for cl_cflip

static LispObject CC_cl_cflip(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0269, v0270;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_cflip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0269 = v0010;
    v0270 = v0000;
// end of prologue
    if (!(v0269 == nil)) return onevalue(v0270);
    v0269 = v0270;
    {
        fn = elt(env, 1); // cl_flip
        return (*qfn1(fn))(qenv(fn), v0269);
    }
}



// Code for omvir

static LispObject CC_omvir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0014, v0052;
    LispObject fn;
    argcheck(nargs, 0, "omvir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omvir");
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
    v0052 = qvalue(elt(env, 1)); // atts
    v0014 = elt(env, 2); // name
    fn = elt(env, 6); // find
    v0014 = (*qfn2(fn))(qenv(fn), v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    stack[0] = v0014;
    v0052 = qvalue(elt(env, 1)); // atts
    v0014 = elt(env, 3); // hex
    fn = elt(env, 6); // find
    v0014 = (*qfn2(fn))(qenv(fn), v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    if (v0014 == nil) goto v0250;
    v0052 = elt(env, 4); // "wrong att"
    v0014 = (LispObject)33; // 2
    fn = elt(env, 7); // errorml
    v0014 = (*qfn2(fn))(qenv(fn), v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    goto v0250;

v0250:
    v0052 = qvalue(elt(env, 1)); // atts
    v0014 = elt(env, 5); // dec
    fn = elt(env, 6); // find
    v0014 = (*qfn2(fn))(qenv(fn), v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    if (v0014 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0052 = elt(env, 4); // "wrong att"
    v0014 = (LispObject)33; // 2
    fn = elt(env, 7); // errorml
    v0014 = (*qfn2(fn))(qenv(fn), v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0069:
    popv(2);
    return nil;
}



// Code for zeropp

static LispObject CC_zeropp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0183, v0015, v0187;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for zeropp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0187 = v0000;
// end of prologue
    v0183 = v0187;
    if (!consp(v0183)) goto v0012;
    v0183 = v0187;
    v0015 = qcar(v0183);
    v0183 = elt(env, 1); // !:rd!:
    if (v0015 == v0183) goto v0008;
    v0183 = qvalue(elt(env, 2)); // nil
    return onevalue(v0183);

v0008:
    v0183 = v0187;
    {
        fn = elt(env, 3); // rd!:zerop
        return (*qfn1(fn))(qenv(fn), v0183);
    }

v0012:
    v0183 = v0187;
        return Lzerop(nil, v0183);
}



// Code for sc_null

static LispObject CC_sc_null(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0011;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_null");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0011 = v0000;
// end of prologue
    v0011 = qcar(v0011);
    v0011 = (v0011 == nil ? lisp_true : nil);
    return onevalue(v0011);
}



// Code for flatindxl

static LispObject CC_flatindxl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0257, v0254, v0177;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for flatindxl");
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
    v0257 = v0000;
// end of prologue
    stack[-3] = v0257;
    v0257 = stack[-3];
    if (v0257 == nil) goto v0009;
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0177 = v0257;
    v0257 = v0177;
    if (!consp(v0257)) goto v0002;
    v0254 = v0177;
    v0257 = elt(env, 2); // minus
    if (!consp(v0254)) goto v0025;
    v0254 = qcar(v0254);
    if (!(v0254 == v0257)) goto v0025;
    v0257 = v0177;
    v0257 = qcdr(v0257);
    v0257 = qcar(v0257);
    goto v0023;

v0023:
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    stack[-1] = v0257;
    stack[-2] = v0257;
    goto v0034;

v0034:
    v0257 = stack[-3];
    v0257 = qcdr(v0257);
    stack[-3] = v0257;
    v0257 = stack[-3];
    if (v0257 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0177 = v0257;
    v0257 = v0177;
    if (!consp(v0257)) goto v0022;
    v0254 = v0177;
    v0257 = elt(env, 2); // minus
    if (!consp(v0254)) goto v0077;
    v0254 = qcar(v0254);
    if (!(v0254 == v0257)) goto v0077;
    v0257 = v0177;
    v0257 = qcdr(v0257);
    v0257 = qcar(v0257);
    goto v0284;

v0284:
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    v0257 = Lrplacd(nil, stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    v0257 = stack[-1];
    v0257 = qcdr(v0257);
    stack[-1] = v0257;
    goto v0034;

v0077:
    v0257 = v0177;
    v0257 = qcdr(v0257);
    goto v0284;

v0022:
    v0257 = v0177;
    goto v0284;

v0025:
    v0257 = v0177;
    v0257 = qcdr(v0257);
    goto v0023;

v0002:
    v0257 = v0177;
    goto v0023;

v0009:
    v0257 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0257); }
// error exit handlers
v0036:
    popv(5);
    return nil;
}



// Code for dividef

static LispObject CC_dividef(LispObject env,
                         LispObject v0000, LispObject v0010)
{
    LispObject nil = C_nil;
    LispObject v0013, v0014, v0052, v0050;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dividef");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0013 = v0010;
    v0014 = v0000;
// end of prologue
    v0013 = Ldivide(nil, v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[0];
    v0050 = v0013;
    v0013 = v0050;
    v0014 = qcar(v0013);
    v0013 = (LispObject)1; // 0
    if (v0014 == v0013) goto v0023;
    v0013 = v0050;
    v0013 = qcar(v0013);
    v0052 = v0013;
    goto v0068;

v0068:
    v0013 = v0050;
    v0014 = qcdr(v0013);
    v0013 = (LispObject)1; // 0
    if (v0014 == v0013) goto v0250;
    v0013 = v0050;
    v0013 = qcdr(v0013);
    goto v0237;

v0237:
    popv(1);
    return cons(v0052, v0013);

v0250:
    v0013 = qvalue(elt(env, 1)); // nil
    goto v0237;

v0023:
    v0013 = qvalue(elt(env, 1)); // nil
    v0052 = v0013;
    goto v0068;
// error exit handlers
v0069:
    popv(1);
    return nil;
}



// Code for dl_get

static LispObject CC_dl_get(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0267, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dl_get");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0267 = v0000;
// end of prologue
    v0009 = v0267;
    v0267 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // dl_get2
        return (*qfn2(fn))(qenv(fn), v0009, v0267);
    }
}



// Code for rnminus!:

static LispObject CC_rnminusT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0074, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnminus:");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0074 = stack[0];
    stack[-1] = qcar(v0074);
    v0074 = stack[0];
    v0074 = qcdr(v0074);
    v0074 = qcar(v0074);
    fn = elt(env, 1); // !:minus
    v0023 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    v0074 = stack[0];
    v0074 = qcdr(v0074);
    v0074 = qcdr(v0074);
    {
        LispObject v0183 = stack[-1];
        popv(2);
        return list2star(v0183, v0023, v0074);
    }
// error exit handlers
v0182:
    popv(2);
    return nil;
}



setup_type const u10_setup[] =
{
    {"ev_tdeg",                 CC_ev_tdeg,     too_many_1,    wrong_no_1},
    {"omiir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omiir},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"vdplength",               CC_vdplength,   too_many_1,    wrong_no_1},
    {"plus:",                   too_few_2,      CC_plusT,      wrong_no_2},
    {"formc",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_formc},
    {"simp",                    CC_simp,        too_many_1,    wrong_no_1},
    {"compactfmatch2",          CC_compactfmatch2,too_many_1,  wrong_no_1},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"get_group_in",            CC_get_group_in,too_many_1,    wrong_no_1},
    {"ofsf_prepat",             CC_ofsf_prepat, too_many_1,    wrong_no_1},
    {"qsort",                   CC_qsort,       too_many_1,    wrong_no_1},
    {"cgb_buch-ev_divides?",    too_few_2,      CC_cgb_buchKev_dividesW,wrong_no_2},
    {"integerom",               CC_integerom,   too_many_1,    wrong_no_1},
    {"dfn_prop",                CC_dfn_prop,    too_many_1,    wrong_no_1},
    {"writepri",                too_few_2,      CC_writepri,   wrong_no_2},
    {"getphystypesf",           CC_getphystypesf,too_many_1,   wrong_no_1},
    {"tokquote",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_tokquote},
    {"argnochk",                CC_argnochk,    too_many_1,    wrong_no_1},
    {"listtest",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_listtest},
    {"rl_external",             too_few_2,      CC_rl_external,wrong_no_2},
    {"ibalp_getnewwl",          CC_ibalp_getnewwl,too_many_1,  wrong_no_1},
    {"sfto_davp",               too_few_2,      CC_sfto_davp,  wrong_no_2},
    {"naryrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_naryrd},
    {"simpexpon1",              too_few_2,      CC_simpexpon1, wrong_no_2},
    {"c:extadd",                too_few_2,      CC_cTextadd,   wrong_no_2},
    {"comm_kernels1",           too_few_2,      CC_comm_kernels1,wrong_no_2},
    {"sc_setmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sc_setmat},
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"chknewnam",               CC_chknewnam,   too_many_1,    wrong_no_1},
    {"mv-pow--",                too_few_2,      CC_mvKpowKK,   wrong_no_2},
    {"make-term",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKterm},
    {"dp=mocompare",            too_few_2,      CC_dpMmocompare,wrong_no_2},
    {"raiseind:",               CC_raiseindT,   too_many_1,    wrong_no_1},
    {"b:ordexn",                too_few_2,      CC_bTordexn,   wrong_no_2},
    {"freeofl",                 too_few_2,      CC_freeofl,    wrong_no_2},
    {"msappend",                too_few_2,      CC_msappend,   wrong_no_2},
    {"mk+mat+mult+mat",         too_few_2,      CC_mkLmatLmultLmat,wrong_no_2},
    {"cl_fvarl1",               CC_cl_fvarl1,   too_many_1,    wrong_no_1},
    {"cl_varl2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_varl2},
    {"cl_cflip",                too_few_2,      CC_cl_cflip,   wrong_no_2},
    {"omvir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omvir},
    {"zeropp",                  CC_zeropp,      too_many_1,    wrong_no_1},
    {"sc_null",                 CC_sc_null,     too_many_1,    wrong_no_1},
    {"flatindxl",               CC_flatindxl,   too_many_1,    wrong_no_1},
    {"dividef",                 too_few_2,      CC_dividef,    wrong_no_2},
    {"dl_get",                  CC_dl_get,      too_many_1,    wrong_no_1},
    {"rnminus:",                CC_rnminusT,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u10", (two_args *)"17372 926835 5966230", 0}
};

// end of generated code
