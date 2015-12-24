
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



// Code for spmultm2

static LispObject CC_spmultm2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0046, v0047, v0048, v0049;
    LispObject fn;
    LispObject v0045, v0031, v0037;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "spmultm2");
    va_start(aa, nargs);
    v0037 = va_arg(aa, LispObject);
    v0031 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spmultm2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0037,v0031,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0046 = v0045;
    stack[-10] = v0031;
    stack[-11] = v0037;
// end of prologue
    v0047 = v0046;
    v0047 = qcdr(v0047);
    v0047 = qcar(v0047);
    fn = elt(env, 3); // mkempspmat
    v0046 = (*qfn2(fn))(qenv(fn), v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-12] = v0046;
    v0046 = stack[-11];
    v0046 = qcdr(v0046);
    v0047 = qcar(v0046);
    v0046 = stack[-11];
    v0046 = qcdr(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    fn = elt(env, 4); // empty
    v0046 = (*qfn2(fn))(qenv(fn), v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    if (v0046 == nil) goto v0051;
    v0046 = stack[-10];
    v0046 = qcdr(v0046);
    v0047 = qcar(v0046);
    v0046 = stack[-10];
    v0046 = qcdr(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    fn = elt(env, 4); // empty
    v0046 = (*qfn2(fn))(qenv(fn), v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0046 = (v0046 == nil ? lisp_true : nil);
    goto v0052;

v0052:
    if (!(v0046 == nil)) { LispObject res = stack[-12]; popv(14); return onevalue(res); }
    v0046 = stack[-11];
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    stack[-9] = v0046;
    v0046 = stack[-10];
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    stack[-8] = v0046;
    v0046 = (LispObject)17; // 1
    stack[-3] = v0046;
    goto v0053;

v0053:
    v0046 = stack[-11];
    v0046 = qcdr(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0047 = qcar(v0046);
    v0046 = stack[-3];
    v0046 = difference2(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0046 = Lminusp(nil, v0046);
    env = stack[-13];
    if (!(v0046 == nil)) { LispObject res = stack[-12]; popv(14); return onevalue(res); }
    v0047 = stack[-9];
    v0046 = stack[-3];
    fn = elt(env, 5); // findrow
    v0046 = (*qfn2(fn))(qenv(fn), v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-7] = v0046;
    v0046 = stack[-7];
    if (v0046 == nil) goto v0054;
    v0046 = (LispObject)17; // 1
    stack[-2] = v0046;
    goto v0055;

v0055:
    v0046 = stack[-10];
    v0046 = qcdr(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0047 = qcar(v0046);
    v0046 = stack[-2];
    v0046 = difference2(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0046 = Lminusp(nil, v0046);
    env = stack[-13];
    if (!(v0046 == nil)) goto v0054;
    v0047 = stack[-8];
    v0046 = stack[-2];
    fn = elt(env, 5); // findrow
    v0046 = (*qfn2(fn))(qenv(fn), v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-6] = v0046;
    v0046 = stack[-6];
    if (v0046 == nil) goto v0056;
    v0046 = (LispObject)1; // 0
    fn = elt(env, 6); // simp
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-4] = v0046;
    v0046 = stack[-7];
    v0046 = qcdr(v0046);
    stack[-1] = v0046;
    goto v0057;

v0057:
    v0046 = stack[-1];
    if (v0046 == nil) goto v0058;
    v0046 = stack[-1];
    v0046 = qcar(v0046);
    v0047 = v0046;
    v0046 = v0047;
    v0046 = qcar(v0046);
    v0047 = qcdr(v0047);
    v0048 = v0047;
    v0047 = v0046;
    v0046 = stack[-6];
    v0046 = Latsoc(nil, v0047, v0046);
    stack[-5] = v0046;
    v0046 = stack[-5];
    if (v0046 == nil) goto v0059;
    v0046 = stack[-5];
    v0046 = qcdr(v0046);
    stack[-5] = v0046;
    v0046 = v0048;
    fn = elt(env, 6); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0046 = stack[-5];
    fn = elt(env, 6); // simp
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    fn = elt(env, 7); // multsq
    v0046 = (*qfn2(fn))(qenv(fn), stack[0], v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[0] = v0046;
    v0047 = stack[-4];
    v0046 = stack[0];
    fn = elt(env, 8); // addsq
    v0046 = (*qfn2(fn))(qenv(fn), v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-4] = v0046;
    goto v0060;

v0060:
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    stack[-1] = v0046;
    goto v0057;

v0059:
    v0046 = stack[-4];
    stack[-4] = v0046;
    goto v0060;

v0058:
    v0046 = stack[-4];
    fn = elt(env, 9); // mk!*sq
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[0] = v0046;
    v0047 = stack[0];
    v0046 = (LispObject)1; // 0
    if (v0047 == v0046) goto v0056;
    v0048 = stack[-12];
    v0047 = stack[-3];
    v0046 = stack[-2];
    v0049 = list3(v0048, v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0048 = stack[0];
    v0047 = stack[-12];
    v0046 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 10); // letmtr3
    v0046 = (*qfnn(fn))(qenv(fn), 4, v0049, v0048, v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    goto v0056;

v0056:
    v0046 = stack[-2];
    v0046 = add1(v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-2] = v0046;
    goto v0055;

v0054:
    v0046 = stack[-3];
    v0046 = add1(v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-3] = v0046;
    goto v0053;

v0051:
    v0046 = qvalue(elt(env, 1)); // t
    goto v0052;
// error exit handlers
v0050:
    popv(14);
    return nil;
}



// Code for bcone!?

static LispObject CC_bconeW(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0066, v0041, v0067;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcone?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0067 = v0037;
// end of prologue
    v0066 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0066 == nil) goto v0068;
    v0041 = v0067;
    v0066 = (LispObject)17; // 1
        return Leqn(nil, v0041, v0066);

v0068:
    v0066 = v0067;
    v0041 = qcdr(v0066);
    v0066 = (LispObject)17; // 1
    if (v0041 == v0066) goto v0069;
    v0066 = qvalue(elt(env, 2)); // nil
    return onevalue(v0066);

v0069:
    v0066 = v0067;
    v0041 = qcar(v0066);
    v0066 = (LispObject)17; // 1
    v0066 = (v0041 == v0066 ? lisp_true : nil);
    return onevalue(v0066);
}



// Code for contrsp

static LispObject CC_contrsp(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0074, v0075, v0076;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contrsp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    stack[-1] = v0037;
// end of prologue
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0076 = qcar(v0074);
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0074 = qcdr(v0074);
    v0075 = qcar(v0074);
    v0074 = stack[0];
    fn = elt(env, 1); // contrsp2
    v0074 = (*qfnn(fn))(qenv(fn), 3, v0076, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    if (!(v0074 == nil)) { popv(3); return onevalue(v0074); }
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0074 = qcdr(v0074);
    v0076 = qcar(v0074);
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0075 = qcar(v0074);
    v0074 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // contrsp2
        return (*qfnn(fn))(qenv(fn), 3, v0076, v0075, v0074);
    }
// error exit handlers
v0067:
    popv(3);
    return nil;
}



// Code for cali_bc_fi

static LispObject CC_cali_bc_fi(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0077, v0078, v0079;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_bc_fi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0079 = v0037;
// end of prologue
    v0078 = v0079;
    v0077 = (LispObject)1; // 0
    if (!(v0078 == v0077)) return onevalue(v0079);
    v0077 = qvalue(elt(env, 1)); // nil
    return onevalue(v0077);
}



// Code for oprin

static LispObject CC_oprin(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0081, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oprin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    v0081 = stack[0];
    if (!symbolp(v0081)) v0081 = nil;
    else { v0081 = qfastgets(v0081);
           if (v0081 != nil) { v0081 = elt(v0081, 37); // prtch
#ifdef RECORD_GET
             if (v0081 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0081 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0081 == SPID_NOPROP) v0081 = nil; }}
#endif
    stack[-1] = v0081;
    v0081 = stack[-1];
    if (v0081 == nil) goto v0025;
    v0081 = qvalue(elt(env, 2)); // !*fort
    if (v0081 == nil) goto v0077;
    v0081 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0081);
    }

v0077:
    v0081 = qvalue(elt(env, 3)); // !*list
    if (v0081 == nil) goto v0083;
    v0081 = qvalue(elt(env, 4)); // obrkp!*
    if (v0081 == nil) goto v0083;
    v0082 = stack[0];
    v0081 = elt(env, 5); // (plus minus)
    v0081 = Lmemq(nil, v0082, v0081);
    if (v0081 == nil) goto v0083;
    v0081 = qvalue(elt(env, 6)); // testing!-width!*
    if (v0081 == nil) goto v0067;
    v0081 = qvalue(elt(env, 7)); // t
    qvalue(elt(env, 8)) = v0081; // overflowed!*
    { popv(3); return onevalue(v0081); }

v0067:
    v0081 = qvalue(elt(env, 7)); // t
    fn = elt(env, 10); // terpri!*
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0081 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0081);
    }

v0083:
    v0081 = stack[0];
    if (!symbolp(v0081)) v0081 = nil;
    else { v0081 = qfastgets(v0081);
           if (v0081 != nil) { v0081 = elt(v0081, 61); // spaced
#ifdef RECORD_GET
             if (v0081 == SPID_NOPROP)
                record_get(elt(fastget_names, 61), 0),
                v0081 = nil;
             else record_get(elt(fastget_names, 61), 1),
                v0081 = lisp_true; }
           else record_get(elt(fastget_names, 61), 0); }
#else
             if (v0081 == SPID_NOPROP) v0081 = nil; else v0081 = lisp_true; }}
#endif
    if (v0081 == nil) goto v0085;
    v0081 = elt(env, 1); // " "
    fn = elt(env, 9); // prin2!*
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0081 = stack[-1];
    fn = elt(env, 9); // prin2!*
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0081 = elt(env, 1); // " "
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0081);
    }

v0085:
    v0081 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0081);
    }

v0025:
    v0081 = elt(env, 1); // " "
    fn = elt(env, 9); // prin2!*
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0081 = stack[0];
    fn = elt(env, 9); // prin2!*
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0081 = elt(env, 1); // " "
    {
        popv(3);
        fn = elt(env, 9); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0081);
    }
// error exit handlers
v0084:
    popv(3);
    return nil;
}



// Code for th_match0

static LispObject CC_th_match0(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0070, v0080, v0062;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for th_match0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    v0062 = v0037;
// end of prologue
    v0070 = v0062;
    v0080 = qcar(v0070);
    v0070 = stack[0];
    v0070 = qcar(v0070);
    if (equal(v0080, v0070)) goto v0073;
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0070); }

v0073:
    v0070 = v0062;
    v0070 = qcdr(v0070);
    v0070 = qcar(v0070);
    stack[-1] = Llength(nil, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    v0070 = stack[0];
    v0070 = qcdr(v0070);
    v0070 = qcar(v0070);
    v0070 = Llength(nil, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    v0070 = (equal(stack[-1], v0070) ? lisp_true : nil);
    { popv(3); return onevalue(v0070); }
// error exit handlers
v0074:
    popv(3);
    return nil;
}



// Code for mapcons

static LispObject CC_mapcons(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0092, v0093;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mapcons");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0031;
    v0092 = v0037;
// end of prologue
    stack[-4] = v0092;
    v0092 = stack[-4];
    if (v0092 == nil) goto v0013;
    v0092 = stack[-4];
    v0092 = qcar(v0092);
    v0093 = stack[-3];
    v0092 = cons(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0092 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[-1] = v0092;
    stack[-2] = v0092;
    goto v0022;

v0022:
    v0092 = stack[-4];
    v0092 = qcdr(v0092);
    stack[-4] = v0092;
    v0092 = stack[-4];
    if (v0092 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0092 = stack[-4];
    v0092 = qcar(v0092);
    v0093 = stack[-3];
    v0092 = cons(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0092 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0092 = Lrplacd(nil, stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    stack[-1] = v0092;
    goto v0022;

v0013:
    v0092 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0092); }
// error exit handlers
v0082:
    popv(6);
    return nil;
}



// Code for rread1

static LispObject CC_rread1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0057, v0111, v0112;
    LispObject fn;
    argcheck(nargs, 0, "rread1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rread1");
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
    fn = elt(env, 15); // ptoken
    v0057 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    stack[-1] = v0057;
    v0111 = qvalue(elt(env, 1)); // ttype!*
    v0057 = (LispObject)49; // 3
    if (v0111 == v0057) goto v0084;
    v0057 = stack[-1];
    if (symbolp(v0057)) goto v0079;
    v0111 = stack[-1];
    v0057 = elt(env, 4); // !:dn!:
    if (!consp(v0111)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0111 = qcar(v0111);
    if (!(v0111 == v0057)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0112 = stack[-1];
    v0111 = qvalue(elt(env, 5)); // nil
    v0057 = elt(env, 6); // symbolic
    {
        popv(3);
        fn = elt(env, 16); // dnform
        return (*qfnn(fn))(qenv(fn), 3, v0112, v0111, v0057);
    }

v0079:
    v0057 = qvalue(elt(env, 2)); // !*quotenewnam
    if (v0057 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0111 = stack[-1];
    v0057 = elt(env, 3); // quotenewnam
    v0057 = get(v0111, v0057);
    stack[0] = v0057;
    if (v0057 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    else { LispObject res = stack[0]; popv(3); return onevalue(res); }

v0084:
    v0111 = stack[-1];
    v0057 = elt(env, 7); // !(
    if (v0111 == v0057) goto v0114;
    v0111 = stack[-1];
    v0057 = elt(env, 8); // !+
    if (v0111 == v0057) goto v0115;
    v0111 = stack[-1];
    v0057 = elt(env, 10); // !-
    v0057 = (v0111 == v0057 ? lisp_true : nil);
    goto v0116;

v0116:
    if (v0057 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    fn = elt(env, 15); // ptoken
    v0057 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    stack[0] = v0057;
    v0111 = stack[0];
    v0057 = elt(env, 4); // !:dn!:
    if (!consp(v0111)) goto v0117;
    v0111 = qcar(v0111);
    if (!(v0111 == v0057)) goto v0117;
    v0112 = stack[0];
    v0111 = qvalue(elt(env, 5)); // nil
    v0057 = elt(env, 6); // symbolic
    fn = elt(env, 16); // dnform
    v0057 = (*qfnn(fn))(qenv(fn), 3, v0112, v0111, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    stack[0] = v0057;
    goto v0117;

v0117:
    v0057 = stack[0];
    if (is_number(v0057)) goto v0118;
    v0057 = elt(env, 11); // " "
    qvalue(elt(env, 12)) = v0057; // nxtsym!*
    v0111 = elt(env, 13); // "Syntax error: improper number"
    v0057 = qvalue(elt(env, 5)); // nil
    fn = elt(env, 17); // symerr
    v0057 = (*qfn2(fn))(qenv(fn), v0111, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }

v0118:
    v0111 = stack[-1];
    v0057 = elt(env, 10); // !-
    if (!(v0111 == v0057)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0111 = elt(env, 14); // minus
    v0057 = stack[0];
    v0057 = Lapply1(nil, v0111, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    stack[0] = v0057;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }

v0115:
    v0057 = qvalue(elt(env, 9)); // t
    goto v0116;

v0114:
    {
        popv(3);
        fn = elt(env, 18); // rrdls
        return (*qfnn(fn))(qenv(fn), 0);
    }
// error exit handlers
v0113:
    popv(3);
    return nil;
}



// Code for ofsf_ordatp

static LispObject CC_ofsf_ordatp(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0067, v0120, v0121, v0089, v0122, v0042;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0122 = v0031;
    v0042 = v0037;
// end of prologue
    v0067 = v0042;
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    v0089 = v0067;
    v0067 = v0122;
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    v0121 = v0067;
    v0120 = v0089;
    v0067 = v0121;
    if (equal(v0120, v0067)) goto v0080;
    v0067 = v0089;
    v0120 = v0121;
    fn = elt(env, 1); // ordp
    v0067 = (*qfn2(fn))(qenv(fn), v0067, v0120);
    errexit();
    v0067 = (v0067 == nil ? lisp_true : nil);
    return onevalue(v0067);

v0080:
    v0067 = v0042;
    v0067 = qcar(v0067);
    v0120 = v0122;
    v0120 = qcar(v0120);
    {
        fn = elt(env, 2); // ofsf_ordrelp
        return (*qfn2(fn))(qenv(fn), v0067, v0120);
    }
}



// Code for polynommultiplybymonom

static LispObject CC_polynommultiplybymonom(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0042, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynommultiplybymonom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    v0110 = v0037;
// end of prologue
    v0042 = v0110;
    if (v0042 == nil) goto v0034;
    v0042 = v0110;
    fn = elt(env, 2); // polynomclone
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    stack[-1] = v0042;
    v0110 = stack[0];
    v0042 = (LispObject)17; // 1
    v0042 = *(LispObject *)((char *)v0110 + (CELL-TAG_VECTOR) + ((int32_t)v0042/(16/CELL)));
    stack[0] = v0042;
    goto v0063;

v0063:
    v0042 = stack[0];
    v0042 = qcar(v0042);
    if (v0042 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0110 = stack[-1];
    v0042 = stack[0];
    v0042 = qcar(v0042);
    fn = elt(env, 3); // polynommultiplybyvariable
    v0042 = (*qfn2(fn))(qenv(fn), v0110, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0063;

v0034:
    v0042 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0042); }
// error exit handlers
v0123:
    popv(3);
    return nil;
}



// Code for poly!-abs

static LispObject CC_polyKabs(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-abs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    v0023 = stack[0];
    fn = elt(env, 1); // poly!-minusp
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    if (v0023 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0023 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // negf
        return (*qfn1(fn))(qenv(fn), v0023);
    }
// error exit handlers
v0086:
    popv(2);
    return nil;
}



// Code for mri_2pasfat

static LispObject CC_mri_2pasfat(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0086, v0073;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_2pasfat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    v0086 = stack[0];
    fn = elt(env, 2); // mri_op
    stack[-1] = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    v0086 = stack[0];
    fn = elt(env, 3); // mri_arg2l
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    v0073 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0072 = stack[-1];
        popv(3);
        return list3(v0072, v0086, v0073);
    }
// error exit handlers
v0079:
    popv(3);
    return nil;
}



// Code for searchpl

static LispObject CC_searchpl(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0088, v0125;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for searchpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    stack[-1] = nil;
    goto v0028;

v0028:
    v0088 = stack[0];
    if (!consp(v0088)) goto v0086;
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = (consp(v0088) ? nil : lisp_true);
    goto v0065;

v0065:
    if (v0088 == nil) goto v0044;
    v0088 = qvalue(elt(env, 2)); // nil
    v0125 = v0088;
    goto v0022;

v0022:
    v0088 = stack[-1];
    if (v0088 == nil) { popv(3); return onevalue(v0125); }
    v0088 = stack[-1];
    v0088 = qcar(v0088);
    fn = elt(env, 3); // setunion
    v0088 = (*qfn2(fn))(qenv(fn), v0088, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0125 = v0088;
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-1] = v0088;
    goto v0022;

v0044:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    fn = elt(env, 4); // searchtm
    v0125 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0088 = stack[-1];
    v0088 = cons(v0125, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    stack[-1] = v0088;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    goto v0028;

v0086:
    v0088 = qvalue(elt(env, 1)); // t
    goto v0065;
// error exit handlers
v0093:
    popv(3);
    return nil;
}



// Code for rl_gettype

static LispObject CC_rl_gettype(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0073, v0077, v0078;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_gettype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0077 = v0037;
// end of prologue
    v0073 = v0077;
    if (!symbolp(v0073)) v0073 = nil;
    else { v0073 = qfastgets(v0073);
           if (v0073 != nil) { v0073 = elt(v0073, 4); // avalue
#ifdef RECORD_GET
             if (v0073 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0073 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0073 == SPID_NOPROP) v0073 = nil; }}
#endif
    v0078 = v0073;
    v0073 = v0078;
    if (v0073 == nil) goto v0013;
    v0073 = v0078;
    v0073 = qcar(v0073);
    return onevalue(v0073);

v0013:
    v0073 = v0077;
    if (!symbolp(v0073)) v0073 = nil;
    else { v0073 = qfastgets(v0073);
           if (v0073 != nil) { v0073 = elt(v0073, 2); // rtype
#ifdef RECORD_GET
             if (v0073 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0073 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0073 == SPID_NOPROP) v0073 = nil; }}
#endif
    return onevalue(v0073);
}



// Code for vdp_poly

static LispObject CC_vdp_poly(LispObject env,
                         LispObject v0037)
{
    LispObject v0025;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0025 = v0037;
// end of prologue
    v0025 = qcdr(v0025);
    v0025 = qcdr(v0025);
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    return onevalue(v0025);
}



// Code for expression

static LispObject CC_expression(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0117, v0132, v0133;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expression");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0133 = v0037;
// end of prologue
    v0117 = v0133;
    if (!consp(v0117)) goto v0025;
    v0117 = v0133;
    v0132 = qcar(v0117);
    v0117 = elt(env, 1); // !:rd!:
    if (v0132 == v0117) goto v0013;
    v0117 = v0133;
    v0132 = qcar(v0117);
    v0117 = qvalue(elt(env, 2)); // unary!*
    v0117 = Lassoc(nil, v0132, v0117);
    v0132 = v0117;
    if (v0117 == nil) goto v0134;
    v0117 = v0132;
    v0117 = qcdr(v0117);
    v0117 = qcdr(v0117);
    v0117 = qcar(v0117);
    if (v0117 == nil) goto v0042;
    v0117 = v0132;
    v0117 = qcdr(v0117);
    stack[0] = qcar(v0117);
    v0117 = v0133;
    v0117 = qcdr(v0117);
    v0132 = qcdr(v0132);
    v0132 = qcdr(v0132);
    v0132 = qcar(v0132);
    v0117 = list2(v0117, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-1];
    fn = elt(env, 5); // apply
    v0117 = (*qfn2(fn))(qenv(fn), stack[0], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    goto v0028;

v0028:
    v0117 = nil;
    { popv(2); return onevalue(v0117); }

v0042:
    v0117 = v0132;
    v0117 = qcdr(v0117);
    stack[0] = qcar(v0117);
    v0117 = v0133;
    v0117 = qcdr(v0117);
    v0117 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-1];
    fn = elt(env, 5); // apply
    v0117 = (*qfn2(fn))(qenv(fn), stack[0], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    goto v0028;

v0134:
    v0117 = v0133;
    v0132 = qcar(v0117);
    v0117 = elt(env, 3); // !*sq
    if (v0132 == v0117) goto v0136;
    v0117 = v0133;
    fn = elt(env, 6); // operator_fn
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    goto v0028;

v0136:
    v0117 = v0133;
    v0117 = qcdr(v0117);
    v0117 = qcar(v0117);
    fn = elt(env, 7); // prepsq
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-1];
    v0117 = CC_expression(env, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    goto v0028;

v0013:
    v0117 = v0133;
    fn = elt(env, 8); // printout
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    goto v0028;

v0025:
    v0117 = v0133;
    fn = elt(env, 9); // f4
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    goto v0028;
// error exit handlers
v0135:
    popv(2);
    return nil;
}



// Code for exchk2

static LispObject CC_exchk2(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0142, v0001, v0143;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exchk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    stack[-1] = v0037;
// end of prologue

v0028:
    v0142 = stack[-1];
    if (v0142 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0142 = stack[-1];
    v0142 = qcdr(v0142);
    stack[-2] = v0142;
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcdr(v0142);
    fn = elt(env, 6); // prepsqx
    v0142 = (*qfn1(fn))(qenv(fn), v0142);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0143 = v0142;
    v0001 = (LispObject)17; // 1
    if (v0143 == v0001) goto v0038;
    v0001 = qvalue(elt(env, 1)); // !*nosqrts
    if (v0001 == nil) goto v0039;
    v0143 = elt(env, 2); // expt
    v0001 = stack[-1];
    v0001 = qcar(v0001);
    v0001 = qcar(v0001);
    v0142 = list3(v0143, v0001, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0001 = v0142;
    goto v0072;

v0072:
    v0142 = stack[0];
    v0142 = cons(v0001, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[0] = v0142;
    v0142 = stack[-2];
    stack[-1] = v0142;
    goto v0028;

v0039:
    v0143 = v0142;
    v0001 = elt(env, 3); // (quotient 1 2)
    if (equal(v0143, v0001)) goto v0145;
    v0143 = v0142;
    v0001 = elt(env, 5); // 0.5
    if (equal(v0143, v0001)) goto v0104;
    v0143 = elt(env, 2); // expt
    v0001 = stack[-1];
    v0001 = qcar(v0001);
    v0001 = qcar(v0001);
    v0142 = list3(v0143, v0001, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0001 = v0142;
    goto v0072;

v0104:
    v0001 = elt(env, 4); // sqrt
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0142 = list2(v0001, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0001 = v0142;
    goto v0072;

v0145:
    v0001 = elt(env, 4); // sqrt
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0142 = list2(v0001, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0001 = v0142;
    goto v0072;

v0038:
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0001 = v0142;
    goto v0072;
// error exit handlers
v0144:
    popv(4);
    return nil;
}



// Code for off_mod_reval

static LispObject CC_off_mod_reval(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0119;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for off_mod_reval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    v0119 = qvalue(elt(env, 1)); // !*modular
    if (v0119 == nil) goto v0078;
    v0119 = elt(env, 2); // modular
    v0119 = ncons(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    fn = elt(env, 4); // off
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0119 = stack[0];
    fn = elt(env, 5); // reval
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    stack[0] = v0119;
    v0119 = elt(env, 2); // modular
    v0119 = ncons(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    fn = elt(env, 6); // on
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0078:
    v0119 = stack[0];
    fn = elt(env, 5); // reval
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    stack[0] = v0119;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0044:
    popv(2);
    return nil;
}



// Code for has_parents

static LispObject CC_has_parents(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0038, v0052, v0051;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for has_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0038 = v0037;
// end of prologue
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0051 = v0038;
    v0038 = v0051;
    v0052 = qcar(v0038);
    v0038 = elt(env, 1); // !?
    if (v0052 == v0038) goto v0063;
    v0038 = v0051;
    v0038 = qcdr(v0038);
    v0052 = elt(env, 1); // !?
        return Lneq(nil, v0038, v0052);

v0063:
    v0038 = qvalue(elt(env, 2)); // nil
    return onevalue(v0038);
}



// Code for lprim

static LispObject CC_lprim(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0078, v0079;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lprim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0078 = v0037;
// end of prologue
    v0079 = qvalue(elt(env, 1)); // !*msg
    if (v0079 == nil) goto v0006;
    v0079 = elt(env, 3); // "***"
    {
        fn = elt(env, 4); // lpriw
        return (*qfn2(fn))(qenv(fn), v0079, v0078);
    }

v0006:
    v0078 = qvalue(elt(env, 2)); // nil
    return onevalue(v0078);
}



// Code for red_better

static LispObject CC_red_better(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_better");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    v0023 = v0037;
// end of prologue
    fn = elt(env, 1); // bas_dplen
    stack[-1] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0023 = stack[0];
    fn = elt(env, 1); // bas_dplen
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    {
        LispObject v0077 = stack[-1];
        popv(3);
        return Llessp(nil, v0077, v0023);
    }
// error exit handlers
v0073:
    popv(3);
    return nil;
}



// Code for ord

static LispObject CC_ord(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0091, v0063, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ord");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0064 = v0037;
// end of prologue
    v0063 = qvalue(elt(env, 1)); // ordering
    v0091 = elt(env, 2); // lex
    if (v0063 == v0091) goto v0086;
    v0091 = v0064;
    v0091 = qcar(v0091);
    { popv(1); return onevalue(v0091); }

v0086:
    v0091 = elt(env, 3); // plus
    v0063 = v0064;
    v0091 = cons(v0091, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); // eval
        return (*qfn1(fn))(qenv(fn), v0091);
    }
// error exit handlers
v0069:
    popv(1);
    return nil;
}



// Code for sc_kern

static LispObject CC_sc_kern(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0065;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_kern");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0065 = v0037;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // g_sc_ve
    v0065 = sub1(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    v0065 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    v0065 = qcar(v0065);
    { popv(1); return onevalue(v0065); }
// error exit handlers
v0073:
    popv(1);
    return nil;
}



// Code for reduce!-mod!-p

static LispObject CC_reduceKmodKp(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0131, v0092, v0093;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    v0131 = stack[0];
    if (v0131 == nil) goto v0006;
    v0131 = stack[0];
    if (!consp(v0131)) goto v0013;
    v0131 = stack[0];
    v0131 = qcar(v0131);
    v0131 = (consp(v0131) ? nil : lisp_true);
    goto v0007;

v0007:
    if (v0131 == nil) goto v0043;
    v0131 = stack[0];
    v0131 = Lmodular_number(nil, v0131);
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0131);
    }

v0043:
    v0131 = stack[0];
    v0131 = qcar(v0131);
    v0131 = qcdr(v0131);
    stack[-1] = CC_reduceKmodKp(env, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = CC_reduceKmodKp(env, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    v0092 = stack[-1];
    v0093 = v0092;
    if (v0093 == nil) { popv(3); return onevalue(v0131); }
    v0093 = stack[0];
    v0093 = qcar(v0093);
    v0093 = qcar(v0093);
    popv(3);
    return acons(v0093, v0092, v0131);

v0013:
    v0131 = qvalue(elt(env, 2)); // t
    goto v0007;

v0006:
    v0131 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0131); }
// error exit handlers
v0108:
    popv(3);
    return nil;
}



// Code for scan

static LispObject CC_scan(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0261, v0262, v0263;
    LispObject fn;
    argcheck(nargs, 0, "scan");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scan");
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
    v0262 = qvalue(elt(env, 1)); // cursym!*
    v0261 = elt(env, 2); // !*semicol!*
    if (!(v0262 == v0261)) goto v0025;

v0028:
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0261; // escaped!*
    fn = elt(env, 43); // token
    v0261 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    goto v0025;

v0025:
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (!consp(v0261)) goto v0089;
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 44); // toknump
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0261 = (v0261 == nil ? lisp_true : nil);
    goto v0075;

v0075:
    if (v0261 == nil) goto v0125;
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    v0262 = qcar(v0261);
    v0261 = elt(env, 41); // string
    if (!(v0262 == v0261)) goto v0079;
    v0261 = elt(env, 42); // " "
    fn = elt(env, 45); // prin2x
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = qcdr(v0261);
    v0261 = qcar(v0261);
    v0261 = Lmkquote(nil, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    v0261 = qcdr(v0261);
    v0261 = qcar(v0261);
    fn = elt(env, 45); // prin2x
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    goto v0079;

v0079:
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    qvalue(elt(env, 1)) = v0261; // cursym!*
    v0261 = qvalue(elt(env, 4)); // escaped!*
    qvalue(elt(env, 22)) = v0261; // curescaped!*
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0261; // escaped!*
    fn = elt(env, 43); // token
    v0261 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = qvalue(elt(env, 25)); // !$eof!$
    if (v0262 == v0261) goto v0265;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0266;

v0266:
    if (v0261 == nil) goto v0072;
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0072:
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (is_number(v0261)) goto v0267;
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (!consp(v0261)) goto v0268;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0269;

v0269:
    if (!(v0261 == nil)) goto v0267;

v0270:
    v0261 = qvalue(elt(env, 1)); // cursym!*
    {
        popv(4);
        fn = elt(env, 47); // addcomment
        return (*qfn1(fn))(qenv(fn), v0261);
    }

v0267:
    v0261 = elt(env, 42); // " "
    fn = elt(env, 45); // prin2x
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    goto v0270;

v0268:
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v0261)) v0261 = nil;
    else { v0261 = qfastgets(v0261);
           if (v0261 != nil) { v0261 = elt(v0261, 11); // switch!*
#ifdef RECORD_GET
             if (v0261 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0261 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0261 == SPID_NOPROP) v0261 = nil; }}
#endif
    v0261 = (v0261 == nil ? lisp_true : nil);
    goto v0269;

v0265:
    v0262 = qvalue(elt(env, 14)); // ttype!*
    v0261 = (LispObject)49; // 3
    v0261 = (v0262 == v0261 ? lisp_true : nil);
    goto v0266;

v0125:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 6); // else
    if (v0262 == v0261) goto v0087;
    v0262 = qvalue(elt(env, 1)); // cursym!*
    v0261 = elt(env, 2); // !*semicol!*
    v0261 = (v0262 == v0261 ? lisp_true : nil);
    goto v0123;

v0123:
    if (v0261 == nil) goto v0062;
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 8)) = v0261; // outl!*
    goto v0062;

v0062:
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 45); // prin2x
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    goto v0022;

v0022:
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (!(symbolp(v0261))) goto v0079;
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v0261)) v0261 = nil;
    else { v0261 = qfastgets(v0261);
           if (v0261 != nil) { v0261 = elt(v0261, 28); // newnam
#ifdef RECORD_GET
             if (v0261 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v0261 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v0261 == SPID_NOPROP) v0261 = nil; }}
#endif
    stack[-1] = v0261;
    if (v0261 == nil) goto v0271;
    v0262 = stack[-1];
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (equal(v0262, v0261)) goto v0271;
    v0261 = stack[-1];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    v0261 = stack[-1];
    v0261 = Lstringp(nil, v0261);
    env = stack[-3];
    if (!(v0261 == nil)) goto v0079;
    v0261 = stack[-1];
    if (!consp(v0261)) goto v0022;
    else goto v0079;

v0271:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 9); // comment
    if (v0262 == v0261) goto v0035;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 10); // !C!O!M!M!E!N!T
    if (v0262 == v0261) goto v0100;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 11); // !Comment
    v0261 = (v0262 == v0261 ? lisp_true : nil);
    goto v0103;

v0103:
    if (v0261 == nil) goto v0272;
    v0261 = elt(env, 9); // comment
    fn = elt(env, 48); // read!-comment1
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    stack[-1] = v0261;
    v0261 = qvalue(elt(env, 12)); // !*comment
    if (v0261 == nil) goto v0028;
    else { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0272:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 13); // !%
    if (v0262 == v0261) goto v0058;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0027;

v0027:
    if (v0261 == nil) goto v0021;
    v0261 = elt(env, 15); // percent_comment
    fn = elt(env, 48); // read!-comment1
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    stack[-1] = v0261;
    v0261 = qvalue(elt(env, 12)); // !*comment
    if (v0261 == nil) goto v0028;
    else { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0021:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 16); // !#if
    if (v0262 == v0261) goto v0273;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 17); // !#else
    if (v0262 == v0261) goto v0274;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 18); // !#elif
    v0261 = (v0262 == v0261 ? lisp_true : nil);
    goto v0275;

v0275:
    if (v0261 == nil) goto v0276;
    v0261 = qvalue(elt(env, 3)); // nil
    stack[-2] = v0261;
    stack[-1] = v0261;
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    goto v0277;

v0277:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 30); // !#
    if (v0262 == v0261) goto v0278;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0279;

v0279:
    if (v0261 == nil) goto v0280;
    fn = elt(env, 43); // token
    v0261 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    v0262 = qvalue(elt(env, 14)); // ttype!*
    v0261 = (LispObject)1; // 0
    if (!(v0262 == v0261)) goto v0280;
    stack[0] = elt(env, 30); // !#
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = Lexplodec(nil, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0261 = cons(stack[0], v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    fn = elt(env, 49); // list2string
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0261 = Lintern(nil, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    goto v0280;

v0280:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 19); // !#endif
    if (v0262 == v0261) goto v0281;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 16); // !#if
    if (v0262 == v0261) goto v0282;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 17); // !#else
    if (v0262 == v0261) goto v0283;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0284;

v0284:
    if (!(v0261 == nil)) goto v0028;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 18); // !#elif
    if (v0262 == v0261) goto v0285;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0286;

v0286:
    if (!(v0261 == nil)) goto v0273;

v0287:
    fn = elt(env, 43); // token
    v0261 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    v0262 = qvalue(elt(env, 14)); // ttype!*
    v0261 = (LispObject)49; // 3
    if (v0262 == v0261) goto v0288;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0289;

v0289:
    if (v0261 == nil) goto v0277;
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0288:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = qvalue(elt(env, 25)); // !$eof!$
    v0261 = (v0262 == v0261 ? lisp_true : nil);
    goto v0289;

v0273:
    fn = elt(env, 50); // rread
    v0263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0262 = qvalue(elt(env, 21)); // !*backtrace
    v0261 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 51); // errorset
    v0261 = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    stack[-1] = v0261;
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0261; // escaped!*
    qvalue(elt(env, 22)) = v0261; // curescaped!*
    v0261 = stack[-1];
    fn = elt(env, 52); // errorp
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    if (v0261 == nil) goto v0290;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0291;

v0291:
    if (!(v0261 == nil)) goto v0028;
    v0261 = qvalue(elt(env, 3)); // nil
    stack[-1] = v0261;
    v0261 = qvalue(elt(env, 7)); // t
    stack[-2] = v0261;
    goto v0277;

v0290:
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    goto v0291;

v0285:
    v0261 = stack[-1];
    if (v0261 == nil) goto v0292;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0286;

v0292:
    v0261 = stack[-2];
    goto v0286;

v0283:
    v0261 = stack[-1];
    if (v0261 == nil) goto v0293;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0284;

v0293:
    v0261 = stack[-2];
    goto v0284;

v0282:
    v0262 = qvalue(elt(env, 3)); // nil
    v0261 = stack[-1];
    v0261 = cons(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    stack[-1] = v0261;
    goto v0287;

v0281:
    v0261 = stack[-1];
    if (v0261 == nil) goto v0028;
    v0261 = stack[-1];
    v0261 = qcdr(v0261);
    stack[-1] = v0261;
    goto v0287;

v0278:
    v0262 = qvalue(elt(env, 14)); // ttype!*
    v0261 = (LispObject)49; // 3
    if (v0262 == v0261) goto v0294;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0279;

v0294:
    v0261 = qvalue(elt(env, 31)); // crchar!*
    v0261 = Lwhitespace_char_p(nil, v0261);
    env = stack[-3];
    v0261 = (v0261 == nil ? lisp_true : nil);
    goto v0279;

v0276:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 19); // !#endif
    if (v0262 == v0261) goto v0028;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 20); // !#eval
    if (v0262 == v0261) goto v0295;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 23); // !#define
    if (v0262 == v0261) goto v0296;
    v0262 = qvalue(elt(env, 14)); // ttype!*
    v0261 = (LispObject)49; // 3
    if (!(v0262 == v0261)) goto v0079;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = qvalue(elt(env, 25)); // !$eof!$
    if (v0262 == v0261) goto v0297;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 26); // !'
    if (v0262 == v0261) goto v0298;
    v0261 = qvalue(elt(env, 28)); // !*eoldelimp
    if (v0261 == nil) goto v0299;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = qvalue(elt(env, 29)); // !$eol!$
    if (!(v0262 == v0261)) goto v0299;

v0073:
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    qvalue(elt(env, 40)) = v0261; // semic!*
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 22)) = v0261; // curescaped!*
    v0261 = elt(env, 2); // !*semicol!*
    {
        popv(4);
        fn = elt(env, 47); // addcomment
        return (*qfn1(fn))(qenv(fn), v0261);
    }

v0299:
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 30); // !#
    if (v0262 == v0261) goto v0300;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0301;

v0301:
    if (v0261 == nil) goto v0302;
    v0261 = qvalue(elt(env, 3)); // nil
    stack[-2] = v0261;
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v0261)) v0261 = nil;
    else { v0261 = qfastgets(v0261);
           if (v0261 != nil) { v0261 = elt(v0261, 11); // switch!*
#ifdef RECORD_GET
             if (v0261 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0261 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0261 == SPID_NOPROP) v0261 = nil; }}
#endif
    stack[-1] = v0261;
    fn = elt(env, 43); // token
    v0261 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 35); // if
    if (v0262 == v0261) goto v0303;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 6); // else
    if (v0262 == v0261) goto v0304;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 36); // elif
    if (v0262 == v0261) goto v0305;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 37); // endif
    if (v0262 == v0261) goto v0306;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 38); // eval
    if (v0262 == v0261) goto v0307;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = elt(env, 39); // define
    v0261 = (v0262 == v0261 ? lisp_true : nil);
    goto v0308;

v0308:
    if (v0261 == nil) goto v0309;
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 45); // prin2x
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    stack[0] = elt(env, 30); // !#
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = Lexplodec(nil, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0261 = cons(stack[0], v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    fn = elt(env, 49); // list2string
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0261 = Lintern(nil, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    goto v0022;

v0309:
    v0262 = qvalue(elt(env, 14)); // ttype!*
    v0261 = (LispObject)49; // 3
    if (!(v0262 == v0261)) goto v0018;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = qvalue(elt(env, 25)); // !$eof!$
    if (v0262 == v0261) goto v0310;
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    if (!(v0261 == nil)) goto v0007;

v0018:
    v0261 = stack[-1];
    v0261 = qcdr(v0261);
    v0261 = qcar(v0261);
    qvalue(elt(env, 1)) = v0261; // cursym!*
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 22)) = v0261; // curescaped!*
    v0262 = qvalue(elt(env, 1)); // cursym!*
    v0261 = elt(env, 32); // !*rpar!*
    if (v0262 == v0261) goto v0072;
    v0261 = qvalue(elt(env, 1)); // cursym!*
    {
        popv(4);
        fn = elt(env, 47); // addcomment
        return (*qfn1(fn))(qenv(fn), v0261);
    }

v0007:
    v0261 = stack[-2];
    if (!(v0261 == nil)) goto v0018;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    v0261 = Latsoc(nil, v0262, v0261);
    stack[0] = v0261;
    if (v0261 == nil) goto v0018;
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 45); // prin2x
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0261 = stack[0];
    v0261 = qcdr(v0261);
    stack[-1] = v0261;
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    if (v0261 == nil) goto v0311;
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0312;

v0312:
    if (v0261 == nil) goto v0019;
    fn = elt(env, 53); // read!-comment
    v0261 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 34)) = v0261; // comment!*
    goto v0028;

v0019:
    fn = elt(env, 43); // token
    v0261 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0261; // nxtsym!*
    v0262 = qvalue(elt(env, 14)); // ttype!*
    v0261 = (LispObject)49; // 3
    if (!(v0262 == v0261)) goto v0018;
    v0262 = qvalue(elt(env, 5)); // nxtsym!*
    v0261 = qvalue(elt(env, 25)); // !$eof!$
    if (v0262 == v0261) goto v0313;
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    if (v0261 == nil) goto v0018;
    else goto v0007;

v0313:
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0311:
    v0261 = stack[-1];
    v0261 = qcdr(v0261);
    v0262 = qcar(v0261);
    v0261 = elt(env, 33); // !*comment!*
    v0261 = (v0262 == v0261 ? lisp_true : nil);
    goto v0312;

v0310:
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0307:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0308;

v0306:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0308;

v0305:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0308;

v0304:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0308;

v0303:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0308;

v0302:
    v0261 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v0261)) v0261 = nil;
    else { v0261 = qfastgets(v0261);
           if (v0261 != nil) { v0261 = elt(v0261, 11); // switch!*
#ifdef RECORD_GET
             if (v0261 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0261 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0261 == SPID_NOPROP) v0261 = nil; }}
#endif
    stack[-1] = v0261;
    if (v0261 == nil) goto v0079;
    v0261 = stack[-1];
    v0262 = qcdr(v0261);
    v0261 = elt(env, 2); // !*semicol!*
    if (!consp(v0262)) goto v0000;
    v0262 = qcar(v0262);
    if (v0262 == v0261) goto v0073;
    else goto v0000;

v0000:
    v0261 = qvalue(elt(env, 31)); // crchar!*
    v0261 = Lwhitespace_char_p(nil, v0261);
    env = stack[-3];
    stack[-2] = v0261;
    goto v0019;

v0300:
    v0261 = qvalue(elt(env, 31)); // crchar!*
    v0261 = Lwhitespace_char_p(nil, v0261);
    env = stack[-3];
    v0261 = (v0261 == nil ? lisp_true : nil);
    goto v0301;

v0298:
    v0261 = elt(env, 27); // "Invalid QUOTE"
    fn = elt(env, 54); // rederr
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    goto v0000;

v0297:
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0296:
    fn = elt(env, 50); // rread
    v0263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0262 = qvalue(elt(env, 21)); // !*backtrace
    v0261 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 51); // errorset
    v0261 = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    stack[-1] = v0261;
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0261; // escaped!*
    qvalue(elt(env, 22)) = v0261; // curescaped!*
    v0261 = stack[-1];
    fn = elt(env, 52); // errorp
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    if (!(v0261 == nil)) goto v0028;
    fn = elt(env, 50); // rread
    v0263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0262 = qvalue(elt(env, 21)); // !*backtrace
    v0261 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 51); // errorset
    v0261 = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    stack[0] = v0261;
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0261; // escaped!*
    qvalue(elt(env, 22)) = v0261; // curescaped!*
    v0261 = stack[0];
    fn = elt(env, 52); // errorp
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    if (!(v0261 == nil)) goto v0028;
    v0263 = stack[-1];
    v0262 = elt(env, 24); // newnam
    v0261 = stack[0];
    v0261 = Lputprop(nil, 3, v0263, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    goto v0028;

v0295:
    fn = elt(env, 50); // rread
    v0263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0262 = qvalue(elt(env, 21)); // !*backtrace
    v0261 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 51); // errorset
    v0261 = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0261 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0261; // escaped!*
    qvalue(elt(env, 22)) = v0261; // curescaped!*
    goto v0028;

v0274:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0275;

v0058:
    v0262 = qvalue(elt(env, 14)); // ttype!*
    v0261 = (LispObject)49; // 3
    v0261 = (v0262 == v0261 ? lisp_true : nil);
    goto v0027;

v0100:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0103;

v0035:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0103;

v0087:
    v0261 = qvalue(elt(env, 7)); // t
    goto v0123;

v0089:
    v0261 = qvalue(elt(env, 3)); // nil
    goto v0075;
// error exit handlers
v0264:
    popv(4);
    return nil;
}



// Code for polynomlistfinddivisor

static LispObject CC_polynomlistfinddivisor(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0126, v0138, v0259;
    LispObject fn;
    LispObject v0045, v0031, v0037;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "polynomlistfinddivisor");
    va_start(aa, nargs);
    v0037 = va_arg(aa, LispObject);
    v0031 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynomlistfinddivisor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0037,v0031,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0045;
    v0138 = v0031;
    v0259 = v0037;
// end of prologue
    v0126 = v0138;
    v0126 = qcar(v0126);
    if (v0126 == nil) goto v0018;
    v0126 = v0259;
    v0126 = qcar(v0126);
    v0126 = (v0126 == nil ? lisp_true : nil);
    goto v0019;

v0019:
    if (v0126 == nil) goto v0068;
    v0126 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0126); }

v0068:
    stack[0] = nil;
    v0126 = v0138;
    v0126 = qcar(v0126);
    stack[-3] = v0126;
    v0126 = v0259;
    stack[-1] = v0126;
    goto v0070;

v0070:
    v0126 = stack[-1];
    v0126 = qcar(v0126);
    if (v0126 == nil) goto v0051;
    v0126 = stack[0];
    if (!(v0126 == nil)) goto v0051;
    v0126 = stack[-2];
    if (v0126 == nil) goto v0042;
    v0138 = stack[-3];
    v0126 = stack[-1];
    v0126 = qcar(v0126);
    v0126 = qcar(v0126);
    fn = elt(env, 3); // monomisdivisibleby
    v0126 = (*qfn2(fn))(qenv(fn), v0138, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-4];
    if (!(v0126 == nil)) goto v0089;

v0042:
    v0126 = stack[-2];
    if (v0126 == nil) goto v0128;
    v0126 = qvalue(elt(env, 2)); // nil
    goto v0082;

v0082:
    if (!(v0126 == nil)) goto v0089;
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    stack[-1] = v0126;
    goto v0070;

v0089:
    v0126 = qvalue(elt(env, 1)); // t
    stack[0] = v0126;
    goto v0070;

v0128:
    v0138 = stack[-3];
    v0126 = stack[-1];
    v0126 = qcar(v0126);
    v0126 = qcar(v0126);
    fn = elt(env, 4); // monomispommaretdivisibleby
    v0126 = (*qfn2(fn))(qenv(fn), v0138, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-4];
    goto v0082;

v0051:
    v0126 = stack[-1];
    v0126 = qcar(v0126);
    { popv(5); return onevalue(v0126); }

v0018:
    v0126 = qvalue(elt(env, 1)); // t
    goto v0019;
// error exit handlers
v0035:
    popv(5);
    return nil;
}



// Code for diffp1

static LispObject CC_diffp1(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0131, v0092, v0093;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0131 = v0031;
    v0093 = v0037;
// end of prologue
    v0092 = v0093;
    v0092 = qcar(v0092);
    if (v0092 == v0131) goto v0078;
    v0131 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0131); }

v0078:
    v0131 = v0093;
    v0092 = qcdr(v0131);
    v0131 = (LispObject)17; // 1
    if (v0092 == v0131) goto v0073;
    v0131 = v0093;
    stack[-1] = qcdr(v0131);
    v0131 = v0093;
    stack[0] = qcar(v0131);
    v0131 = v0093;
    v0131 = qcdr(v0131);
    v0131 = sub1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    fn = elt(env, 2); // to
    v0092 = (*qfn2(fn))(qenv(fn), stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0131 = (LispObject)17; // 1
    v0131 = cons(v0092, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    {
        LispObject v0315 = stack[-1];
        popv(3);
        fn = elt(env, 3); // multd
        return (*qfn2(fn))(qenv(fn), v0315, v0131);
    }

v0073:
    v0131 = (LispObject)17; // 1
    { popv(3); return onevalue(v0131); }
// error exit handlers
v0108:
    popv(3);
    return nil;
}



// Code for tayexp!-difference

static LispObject CC_tayexpKdifference(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0317, v0134, v0140;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    v0134 = v0037;
// end of prologue
    v0317 = v0134;
    if (!consp(v0317)) goto v0019;
    v0317 = qvalue(elt(env, 1)); // nil
    goto v0022;

v0022:
    if (v0317 == nil) goto v0044;
    v0317 = stack[0];
    popv(3);
    return difference2(v0134, v0317);

v0044:
    v0317 = v0134;
    if (!consp(v0317)) goto v0070;
    v0317 = stack[0];
    if (!consp(v0317)) goto v0121;
    v0317 = stack[0];
    fn = elt(env, 2); // rndifference!:
    v0317 = (*qfn2(fn))(qenv(fn), v0134, v0317);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    goto v0064;

v0064:
    v0140 = v0317;
    v0317 = v0140;
    v0317 = qcdr(v0317);
    v0134 = qcdr(v0317);
    v0317 = (LispObject)17; // 1
    if (!(v0134 == v0317)) { popv(3); return onevalue(v0140); }
    v0317 = v0140;
    v0317 = qcdr(v0317);
    v0317 = qcar(v0317);
    { popv(3); return onevalue(v0317); }

v0121:
    stack[-1] = v0134;
    v0317 = stack[0];
    fn = elt(env, 3); // !*i2rn
    v0317 = (*qfn1(fn))(qenv(fn), v0317);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    fn = elt(env, 2); // rndifference!:
    v0317 = (*qfn2(fn))(qenv(fn), stack[-1], v0317);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    goto v0064;

v0070:
    v0317 = v0134;
    fn = elt(env, 3); // !*i2rn
    v0134 = (*qfn1(fn))(qenv(fn), v0317);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0317 = stack[0];
    fn = elt(env, 2); // rndifference!:
    v0317 = (*qfn2(fn))(qenv(fn), v0134, v0317);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    goto v0064;

v0019:
    v0317 = stack[0];
    v0317 = (consp(v0317) ? nil : lisp_true);
    goto v0022;
// error exit handlers
v0053:
    popv(3);
    return nil;
}



// Code for ofsf_prepat

static LispObject CC_ofsf_prepat(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0068;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_prepat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0037;
// end of prologue
    v0068 = stack[-1];
    stack[-2] = qcar(v0068);
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    v0068 = qcar(v0068);
    fn = elt(env, 1); // prepf
    stack[0] = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-3];
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    v0068 = qcdr(v0068);
    v0068 = qcar(v0068);
    fn = elt(env, 1); // prepf
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    {
        LispObject v0091 = stack[-2];
        LispObject v0063 = stack[0];
        popv(4);
        return list3(v0091, v0063, v0068);
    }
// error exit handlers
v0044:
    popv(4);
    return nil;
}



// Code for ibalp_simpat

static LispObject CC_ibalp_simpat(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0068;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_simpat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0037;
// end of prologue
    v0068 = stack[-1];
    stack[-2] = qcar(v0068);
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    v0068 = qcar(v0068);
    fn = elt(env, 1); // ibalp_simpterm
    stack[0] = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-3];
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    v0068 = qcdr(v0068);
    v0068 = qcar(v0068);
    fn = elt(env, 1); // ibalp_simpterm
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-3];
    {
        LispObject v0091 = stack[-2];
        LispObject v0063 = stack[0];
        popv(4);
        fn = elt(env, 2); // ibalp_mk2
        return (*qfnn(fn))(qenv(fn), 3, v0091, v0063, v0068);
    }
// error exit handlers
v0044:
    popv(4);
    return nil;
}



// Code for omair

static LispObject CC_omair(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0051, v0070;
    LispObject fn;
    argcheck(nargs, 0, "omair");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omair");
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
    stack[0] = nil;
    fn = elt(env, 4); // lex
    v0051 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    fn = elt(env, 5); // omobj
    v0051 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    stack[-1] = v0051;
    v0051 = stack[-1];
    v0070 = qcar(v0051);
    v0051 = elt(env, 1); // matrix
    if (v0070 == v0051) goto v0044;
    fn = elt(env, 4); // lex
    v0051 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    fn = elt(env, 6); // omobjs
    v0051 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    stack[0] = v0051;
    v0051 = elt(env, 2); // (!/ o m a)
    fn = elt(env, 7); // checktag
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    goto v0044;

v0044:
    v0070 = stack[-1];
    v0051 = stack[0];
        popv(3);
        return Lappend(nil, v0070, v0051);
// error exit handlers
v0061:
    popv(3);
    return nil;
}



// Code for vdpgetprop

static LispObject CC_vdpgetprop(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0040, v0084, v0145, v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpgetprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0145 = v0031;
    v0128 = v0037;
// end of prologue
    v0040 = v0128;
    if (v0040 == nil) goto v0034;
    v0084 = v0128;
    v0040 = elt(env, 2); // vdp
    if (!consp(v0084)) goto v0072;
    v0084 = qcar(v0084);
    if (!(v0084 == v0040)) goto v0072;
    v0040 = v0145;
    v0084 = v0128;
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    v0040 = Lassoc(nil, v0040, v0084);
    v0084 = v0040;
    v0040 = v0084;
    if (v0040 == nil) goto v0081;
    v0040 = v0084;
    v0040 = qcdr(v0040);
    { popv(3); return onevalue(v0040); }

v0081:
    v0040 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0040); }

v0072:
    stack[-1] = elt(env, 3); // dipoly
    stack[0] = (LispObject)113; // 7
    v0040 = elt(env, 4); // "vdpgetprop given a non-vdp as 1st parameter"
    v0084 = v0128;
    v0040 = list3(v0040, v0084, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-2];
    {
        LispObject v0106 = stack[-1];
        LispObject v0314 = stack[0];
        popv(3);
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0106, v0314, v0040);
    }

v0034:
    v0040 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0040); }
// error exit handlers
v0107:
    popv(3);
    return nil;
}



// Code for xord_lex

static LispObject CC_xord_lex(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0316, v0141, v0000, v0116;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xord_lex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0141 = v0031;
    v0000 = v0037;
// end of prologue

v0034:
    v0316 = v0000;
    if (v0316 == nil) goto v0013;
    v0316 = v0000;
    v0116 = qcar(v0316);
    v0316 = (LispObject)17; // 1
    v0316 = (v0116 == v0316 ? lisp_true : nil);
    goto v0007;

v0007:
    if (v0316 == nil) goto v0019;
    v0316 = qvalue(elt(env, 2)); // nil
    return onevalue(v0316);

v0019:
    v0316 = v0141;
    if (v0316 == nil) goto v0051;
    v0316 = v0141;
    v0116 = qcar(v0316);
    v0316 = (LispObject)17; // 1
    v0316 = (v0116 == v0316 ? lisp_true : nil);
    goto v0052;

v0052:
    if (v0316 == nil) goto v0109;
    v0316 = qvalue(elt(env, 1)); // t
    return onevalue(v0316);

v0109:
    v0316 = v0000;
    v0116 = qcar(v0316);
    v0316 = v0141;
    v0316 = qcar(v0316);
    if (v0116 == v0316) goto v0042;
    v0316 = v0000;
    v0316 = qcar(v0316);
    v0141 = qcar(v0141);
    {
        fn = elt(env, 3); // factorordp
        return (*qfn2(fn))(qenv(fn), v0316, v0141);
    }

v0042:
    v0316 = v0000;
    v0316 = qcdr(v0316);
    v0000 = v0316;
    v0316 = v0141;
    v0316 = qcdr(v0316);
    v0141 = v0316;
    goto v0034;

v0051:
    v0316 = qvalue(elt(env, 1)); // t
    goto v0052;

v0013:
    v0316 = qvalue(elt(env, 1)); // t
    goto v0007;
}



// Code for getphystype

static LispObject CC_getphystype(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0258, v0135;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    v0258 = stack[0];
    fn = elt(env, 8); // physopp
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    if (v0258 == nil) goto v0022;
    v0258 = stack[0];
    fn = elt(env, 9); // scalopp
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    if (v0258 == nil) goto v0065;
    v0258 = elt(env, 1); // scalar
    { popv(3); return onevalue(v0258); }

v0065:
    v0258 = stack[0];
    fn = elt(env, 10); // vecopp
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    if (v0258 == nil) goto v0079;
    v0258 = elt(env, 2); // vector
    { popv(3); return onevalue(v0258); }

v0079:
    v0258 = stack[0];
    fn = elt(env, 11); // tensopp
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    if (v0258 == nil) goto v0043;
    v0258 = elt(env, 3); // tensor
    { popv(3); return onevalue(v0258); }

v0043:
    v0258 = stack[0];
    fn = elt(env, 12); // po!:statep
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    if (v0258 == nil) goto v0070;
    v0258 = elt(env, 4); // state
    { popv(3); return onevalue(v0258); }

v0070:
    v0258 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0258); }

v0022:
    v0258 = stack[0];
    if (!consp(v0258)) goto v0061;
    v0258 = stack[0];
    v0258 = qcar(v0258);
    if (!symbolp(v0258)) v0135 = nil;
    else { v0135 = qfastgets(v0258);
           if (v0135 != nil) { v0135 = elt(v0135, 18); // phystype
#ifdef RECORD_GET
             if (v0135 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0135 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0135 == SPID_NOPROP) v0135 = nil; }}
#endif
    v0258 = v0135;
    if (!(v0135 == nil)) { popv(3); return onevalue(v0258); }
    v0258 = stack[0];
    v0135 = qcar(v0258);
    v0258 = elt(env, 6); // phystypefn
    v0135 = get(v0135, v0258);
    env = stack[-2];
    v0258 = v0135;
    if (v0135 == nil) goto v0122;
    v0135 = v0258;
    v0258 = stack[0];
    v0258 = qcdr(v0258);
        popv(3);
        return Lapply1(nil, v0135, v0258);

v0122:
    v0258 = stack[0];
    fn = elt(env, 13); // collectphystype
    v0135 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    v0258 = v0135;
    if (v0135 == nil) goto v0040;
    v0135 = v0258;
    v0135 = qcdr(v0135);
    if (v0135 == nil) goto v0260;
    v0135 = elt(env, 4); // state
    v0258 = Lmember(nil, v0135, v0258);
    if (v0258 == nil) goto v0126;
    v0258 = elt(env, 4); // state
    { popv(3); return onevalue(v0258); }

v0126:
    stack[-1] = elt(env, 0); // getphystype
    v0135 = elt(env, 7); // "PHYSOP type conflict in"
    v0258 = stack[0];
    v0258 = list2(v0135, v0258);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    {
        LispObject v0054 = stack[-1];
        popv(3);
        fn = elt(env, 14); // rederr2
        return (*qfn2(fn))(qenv(fn), v0054, v0258);
    }

v0260:
    v0258 = qcar(v0258);
    { popv(3); return onevalue(v0258); }

v0040:
    v0258 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0258); }

v0061:
    v0258 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0258); }
// error exit handlers
v0137:
    popv(3);
    return nil;
}



// Code for mv!-domainlist!-!-

static LispObject CC_mvKdomainlistKK(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0071, v0074;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-domainlist--");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    stack[-1] = v0037;
// end of prologue
    stack[-2] = nil;
    goto v0028;

v0028:
    v0071 = stack[-1];
    if (v0071 == nil) goto v0019;
    v0071 = stack[-1];
    v0074 = qcar(v0071);
    v0071 = stack[0];
    v0071 = qcar(v0071);
    v0074 = difference2(v0074, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-3];
    v0071 = stack[-2];
    v0071 = cons(v0074, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-3];
    stack[-2] = v0071;
    v0071 = stack[-1];
    v0071 = qcdr(v0071);
    stack[-1] = v0071;
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    stack[0] = v0071;
    goto v0028;

v0019:
    v0071 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0071);
    }
// error exit handlers
v0041:
    popv(4);
    return nil;
}



// Code for !*id2num

static LispObject CC_Hid2num(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0079, v0072;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *id2num");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0079 = v0037;
// end of prologue
    v0072 = qvalue(elt(env, 1)); // pair_id_num!*
    v0079 = Lassoc(nil, v0079, v0072);
    v0072 = v0079;
    if (v0079 == nil) goto v0028;
    v0079 = v0072;
    v0079 = qcdr(v0079);
    return onevalue(v0079);

v0028:
    v0079 = nil;
    return onevalue(v0079);
}



// Code for exptf

static LispObject CC_exptf(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0106, v0314, v0316;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    stack[-1] = v0037;
// end of prologue
    v0314 = stack[0];
    v0106 = (LispObject)1; // 0
    v0106 = (LispObject)lessp2(v0314, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0106 = v0106 ? lisp_true : nil;
    env = stack[-2];
    if (v0106 == nil) goto v0028;
    v0316 = elt(env, 1); // "exptf"
    v0314 = stack[-1];
    v0106 = stack[0];
    v0106 = list3(v0316, v0314, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); // errach
        return (*qfn1(fn))(qenv(fn), v0106);
    }

v0028:
    v0106 = stack[-1];
    if (!consp(v0106)) goto v0052;
    v0106 = stack[-1];
    v0106 = qcar(v0106);
    v0106 = (consp(v0106) ? nil : lisp_true);
    goto v0038;

v0038:
    if (v0106 == nil) goto v0064;
    v0314 = stack[-1];
    v0106 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); // !:expt
        return (*qfn2(fn))(qenv(fn), v0314, v0106);
    }

v0064:
    v0106 = qvalue(elt(env, 3)); // !*exp
    if (!(v0106 == nil)) goto v0131;
    v0106 = stack[-1];
    fn = elt(env, 6); // kernlp
    v0106 = (*qfn1(fn))(qenv(fn), v0106);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-2];
    if (!(v0106 == nil)) goto v0131;
    v0314 = stack[-1];
    v0106 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // mksfpf
        return (*qfn2(fn))(qenv(fn), v0314, v0106);
    }

v0131:
    v0314 = stack[-1];
    v0106 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); // exptf1
        return (*qfn2(fn))(qenv(fn), v0314, v0106);
    }

v0052:
    v0106 = qvalue(elt(env, 2)); // t
    goto v0038;
// error exit handlers
v0116:
    popv(3);
    return nil;
}



// Code for rrdls

static LispObject CC_rrdls(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0102, v0103, v0035;
    LispObject fn;
    argcheck(nargs, 0, "rrdls");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rrdls");
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
    stack[0] = nil;
    goto v0028;

v0028:
    fn = elt(env, 9); // rread1
    v0102 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0319;
    env = stack[-2];
    stack[-1] = v0102;
    v0103 = qvalue(elt(env, 1)); // ttype!*
    v0102 = (LispObject)49; // 3
    if (!(v0103 == v0102)) goto v0127;
    v0103 = stack[-1];
    v0102 = elt(env, 2); // !)
    if (v0103 == v0102) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0103 = stack[-1];
    v0102 = elt(env, 3); // !.
    if (!(v0103 == v0102)) goto v0127;
    fn = elt(env, 9); // rread1
    v0102 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0319;
    env = stack[-2];
    stack[-1] = v0102;
    fn = elt(env, 10); // ptoken
    v0102 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0319;
    env = stack[-2];
    v0035 = v0102;
    v0103 = qvalue(elt(env, 1)); // ttype!*
    v0102 = (LispObject)49; // 3
    if (v0103 == v0102) goto v0085;
    v0102 = qvalue(elt(env, 4)); // t
    goto v0089;

v0089:
    if (v0102 == nil) goto v0320;
    v0102 = elt(env, 5); // " "
    qvalue(elt(env, 6)) = v0102; // nxtsym!*
    v0103 = elt(env, 7); // "Invalid S-expression"
    v0102 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 11); // symerr
    v0102 = (*qfn2(fn))(qenv(fn), v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0319;
    env = stack[-2];
    goto v0127;

v0127:
    v0102 = stack[-1];
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0319;
    env = stack[-2];
    v0102 = Lnconc(nil, stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0319;
    env = stack[-2];
    stack[0] = v0102;
    goto v0028;

v0320:
    v0103 = stack[0];
    v0102 = stack[-1];
        popv(3);
        return Lnconc(nil, v0103, v0102);

v0085:
    v0103 = v0035;
    v0102 = elt(env, 2); // !)
    v0102 = (v0103 == v0102 ? lisp_true : nil);
    v0102 = (v0102 == nil ? lisp_true : nil);
    goto v0089;
// error exit handlers
v0319:
    popv(3);
    return nil;
}



// Code for ofsf_posvarpat

static LispObject CC_ofsf_posvarpat(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0120, v0121, v0089;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_posvarpat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    v0089 = v0037;
// end of prologue
    v0120 = v0089;
    if (!consp(v0120)) goto v0022;
    v0120 = v0089;
    v0120 = qcar(v0120);
    goto v0025;

v0025:
    stack[-1] = v0120;
    v0121 = stack[-1];
    v0120 = elt(env, 1); // (greaterp geq)
    v0120 = Lmemq(nil, v0121, v0120);
    if (v0120 == nil) goto v0078;
    v0120 = v0089;
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    fn = elt(env, 3); // sfto_varp
    v0121 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0120 = stack[0];
    if (v0121 == v0120) { LispObject res = stack[-1]; popv(2); return onevalue(res); }
    v0120 = nil;
    { popv(2); return onevalue(v0120); }

v0078:
    v0120 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0120); }

v0022:
    v0120 = v0089;
    goto v0025;
// error exit handlers
v0110:
    popv(2);
    return nil;
}



// Code for janettreefind

static LispObject CC_janettreefind(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0324, v0029;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for janettreefind");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0037;
// end of prologue
    v0324 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    if (v0324 == nil) goto v0006;
    stack[-5] = nil;
    v0324 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    stack[-3] = v0324;
    v0029 = stack[-4];
    v0324 = (LispObject)1; // 0
    v0324 = *(LispObject *)((char *)v0029 + (CELL-TAG_VECTOR) + ((int32_t)v0324/(16/CELL)));
    stack[-2] = v0324;
    v0324 = (LispObject)17; // 1
    stack[-1] = v0324;
    goto v0062;

v0062:
    v0029 = stack[-2];
    v0324 = (LispObject)1; // 0
    if (!(((int32_t)(v0029)) > ((int32_t)(v0324)))) { LispObject res = stack[-5]; popv(7); return onevalue(res); }

v0123:
    v0324 = stack[-3];
    v0324 = qcar(v0324);
    stack[0] = qcar(v0324);
    v0029 = stack[-4];
    v0324 = stack[-1];
    fn = elt(env, 3); // monomgetvariabledegree
    v0324 = (*qfn2(fn))(qenv(fn), v0029, v0324);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-6];
    v0324 = (LispObject)lessp2(stack[0], v0324);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    v0324 = v0324 ? lisp_true : nil;
    env = stack[-6];
    if (v0324 == nil) goto v0130;
    v0324 = stack[-3];
    v0324 = qcdr(v0324);
    v0324 = qcar(v0324);
    if (v0324 == nil) goto v0130;
    v0324 = stack[-3];
    v0324 = qcdr(v0324);
    v0324 = qcar(v0324);
    stack[-3] = v0324;
    goto v0123;

v0130:
    v0324 = stack[-3];
    v0324 = qcar(v0324);
    stack[0] = qcar(v0324);
    v0029 = stack[-4];
    v0324 = stack[-1];
    fn = elt(env, 3); // monomgetvariabledegree
    v0324 = (*qfn2(fn))(qenv(fn), v0029, v0324);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-6];
    if (equal(stack[0], v0324)) goto v0320;
    v0324 = (LispObject)1; // 0
    stack[-2] = v0324;
    goto v0062;

v0320:
    v0324 = stack[-3];
    v0324 = qcdr(v0324);
    v0324 = qcdr(v0324);
    if (v0324 == nil) goto v0055;
    stack[0] = stack[-2];
    v0029 = stack[-4];
    v0324 = stack[-1];
    fn = elt(env, 3); // monomgetvariabledegree
    v0324 = (*qfn2(fn))(qenv(fn), v0029, v0324);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-6];
    v0324 = (LispObject)(int32_t)((int32_t)stack[0] - (int32_t)v0324 + TAG_FIXNUM);
    stack[-2] = v0324;
    v0324 = stack[-1];
    v0324 = (LispObject)((int32_t)(v0324) + 0x10);
    stack[-1] = v0324;
    v0324 = stack[-3];
    v0324 = qcdr(v0324);
    v0324 = qcdr(v0324);
    stack[-3] = v0324;
    goto v0062;

v0055:
    v0324 = (LispObject)1; // 0
    stack[-2] = v0324;
    v0324 = stack[-3];
    v0324 = qcar(v0324);
    v0324 = qcdr(v0324);
    stack[-5] = v0324;
    goto v0062;

v0006:
    v0324 = qvalue(elt(env, 2)); // nil
    { popv(7); return onevalue(v0324); }
// error exit handlers
v0325:
    popv(7);
    return nil;
}



// Code for cl_varl1

static LispObject CC_cl_varl1(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0073, v0077, v0078, v0079;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_varl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0073 = v0037;
// end of prologue
    v0079 = v0073;
    v0078 = qvalue(elt(env, 1)); // nil
    v0077 = qvalue(elt(env, 1)); // nil
    v0073 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // cl_varl2
        return (*qfnn(fn))(qenv(fn), 4, v0079, v0078, v0077, v0073);
    }
}



// Code for revv0

static LispObject CC_revv0(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0129, v0260;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revv0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0031;
    stack[-1] = v0037;
// end of prologue

v0025:
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0260 = qcar(v0129);
    v0129 = stack[0];
    if (v0260 == v0129) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    stack[-2] = v0129;
    v0129 = stack[-1];
    v0260 = qcdr(v0129);
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    v0129 = Lrplaca(nil, v0260, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-3];
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0260 = qcdr(v0129);
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0129 = qcdr(v0129);
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    v0129 = Lrplaca(nil, v0260, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-3];
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    v0129 = qcdr(v0129);
    v0260 = qcdr(v0129);
    v0129 = stack[-2];
    v0129 = Lrplaca(nil, v0260, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-3];
    v0260 = stack[-1];
    v0129 = stack[0];
    stack[-1] = v0260;
    stack[0] = v0129;
    goto v0025;
// error exit handlers
v0316:
    popv(4);
    return nil;
}



// Code for cl_simplat

static LispObject CC_cl_simplat(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0070, v0080, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_simplat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0080 = v0031;
    v0062 = v0037;
// end of prologue
    v0070 = qvalue(elt(env, 1)); // !*rlidentify
    if (v0070 == nil) goto v0019;
    v0070 = v0062;
    fn = elt(env, 3); // rl_simplat1
    v0080 = (*qfn2(fn))(qenv(fn), v0070, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[0];
    v0070 = elt(env, 2); // cl_identifyat
    {
        popv(1);
        fn = elt(env, 4); // cl_apply2ats
        return (*qfn2(fn))(qenv(fn), v0080, v0070);
    }

v0019:
    v0070 = v0062;
    {
        popv(1);
        fn = elt(env, 3); // rl_simplat1
        return (*qfn2(fn))(qenv(fn), v0070, v0080);
    }
// error exit handlers
v0061:
    popv(1);
    return nil;
}



// Code for ibalp_litp

static LispObject CC_ibalp_litp(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0080, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_litp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    v0080 = stack[0];
    fn = elt(env, 3); // ibalp_atomp
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    if (!(v0080 == nil)) { popv(2); return onevalue(v0080); }
    v0080 = stack[0];
    if (!consp(v0080)) goto v0078;
    v0080 = stack[0];
    v0080 = qcar(v0080);
    v0062 = v0080;
    goto v0023;

v0023:
    v0080 = elt(env, 1); // not
    if (v0062 == v0080) goto v0019;
    v0080 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0080); }

v0019:
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    v0080 = qcar(v0080);
    {
        popv(2);
        fn = elt(env, 3); // ibalp_atomp
        return (*qfn1(fn))(qenv(fn), v0080);
    }

v0078:
    v0080 = stack[0];
    v0062 = v0080;
    goto v0023;
// error exit handlers
v0071:
    popv(2);
    return nil;
}



// Code for smtp

static LispObject CC_smtp(LispObject env,
                         LispObject v0037, LispObject v0031)
{
    LispObject nil = C_nil;
    LispObject v0333, v0334, v0014, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smtp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0037,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0031;
    stack[0] = v0037;
// end of prologue
    v0333 = stack[0];
    if (!consp(v0333)) goto v0073;
    v0334 = stack[0];
    v0333 = elt(env, 1); // sparsemat
    if (!consp(v0334)) goto v0121;
    v0334 = qcar(v0334);
    if (!(v0334 == v0333)) goto v0121;
    v0333 = stack[0];
    stack[-7] = v0333;
    v0333 = stack[-7];
    v0333 = qcdr(v0333);
    v0333 = qcdr(v0333);
    v0333 = qcar(v0333);
    v0334 = v0333;
    goto v0086;

v0086:
    v0333 = v0334;
    v0333 = qcdr(v0333);
    v0333 = qcar(v0333);
    stack[-4] = v0333;
    v0333 = v0334;
    v0333 = qcdr(v0333);
    v0333 = qcdr(v0333);
    v0333 = qcar(v0333);
    stack[-1] = v0333;
    v0014 = elt(env, 2); // spm
    v0334 = v0333;
    v0333 = stack[-4];
    v0333 = list3(v0014, v0334, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    fn = elt(env, 7); // mkempspmat
    v0333 = (*qfn2(fn))(qenv(fn), stack[-1], v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    stack[-5] = v0333;
    v0334 = stack[-7];
    v0333 = elt(env, 1); // sparsemat
    if (!consp(v0334)) goto v0102;
    v0334 = qcar(v0334);
    if (!(v0334 == v0333)) goto v0102;
    v0333 = (LispObject)17; // 1
    stack[-1] = v0333;
    goto v0255;

v0255:
    v0334 = stack[-4];
    v0333 = stack[-1];
    v0333 = difference2(v0334, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    v0333 = Lminusp(nil, v0333);
    env = stack[-8];
    if (!(v0333 == nil)) { LispObject res = stack[-5]; popv(9); return onevalue(res); }
    v0334 = stack[-7];
    v0333 = stack[-1];
    fn = elt(env, 8); // findrow
    v0333 = (*qfn2(fn))(qenv(fn), v0334, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    v0334 = v0333;
    v0333 = v0334;
    if (v0333 == nil) goto v0095;
    v0333 = stack[-1];
    stack[-3] = v0333;
    v0333 = v0334;
    v0333 = qcdr(v0333);
    stack[0] = v0333;
    goto v0094;

v0094:
    v0333 = stack[0];
    if (v0333 == nil) goto v0095;
    v0333 = stack[0];
    v0333 = qcar(v0333);
    v0334 = v0333;
    v0333 = v0334;
    v0333 = qcar(v0333);
    v0334 = qcdr(v0334);
    stack[-2] = v0334;
    v0014 = stack[-5];
    v0334 = v0333;
    v0333 = stack[-3];
    v0015 = list3(v0014, v0334, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    v0014 = stack[-2];
    v0334 = stack[-5];
    v0333 = stack[-6];
    fn = elt(env, 9); // letmtr3
    v0333 = (*qfnn(fn))(qenv(fn), 4, v0015, v0014, v0334, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    v0333 = stack[0];
    v0333 = qcdr(v0333);
    stack[0] = v0333;
    goto v0094;

v0095:
    v0333 = stack[-1];
    v0333 = add1(v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    stack[-1] = v0333;
    goto v0255;

v0102:
    stack[-2] = elt(env, 3); // matrix
    stack[-1] = (LispObject)33; // 2
    v0014 = elt(env, 4); // "Matrix"
    v0334 = stack[0];
    v0333 = elt(env, 5); // "not set"
    v0333 = list3(v0014, v0334, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    fn = elt(env, 10); // rerror
    v0333 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    { LispObject res = stack[-5]; popv(9); return onevalue(res); }

v0121:
    v0333 = stack[0];
    v0333 = qcdr(v0333);
    v0334 = qcar(v0333);
    v0333 = stack[-6];
    v0333 = CC_smtp(env, v0334, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-8];
    stack[-7] = v0333;
    v0333 = stack[-7];
    v0333 = qcdr(v0333);
    v0333 = qcdr(v0333);
    v0333 = qcar(v0333);
    v0334 = v0333;
    goto v0086;

v0073:
    v0333 = stack[0];
    if (!symbolp(v0333)) v0333 = nil;
    else { v0333 = qfastgets(v0333);
           if (v0333 != nil) { v0333 = elt(v0333, 4); // avalue
#ifdef RECORD_GET
             if (v0333 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0333 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0333 == SPID_NOPROP) v0333 = nil; }}
#endif
    v0333 = qcdr(v0333);
    v0333 = qcar(v0333);
    stack[-7] = v0333;
    v0333 = stack[-7];
    v0333 = qcdr(v0333);
    v0333 = qcdr(v0333);
    v0333 = qcar(v0333);
    v0334 = v0333;
    goto v0086;
// error exit handlers
v0335:
    popv(9);
    return nil;
}



// Code for on

static LispObject CC_on(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0072;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for on");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0072 = v0037;
// end of prologue
    stack[0] = v0072;
    goto v0034;

v0034:
    v0072 = stack[0];
    if (v0072 == nil) goto v0019;
    v0072 = stack[0];
    v0072 = qcar(v0072);
    fn = elt(env, 2); // on1
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    v0072 = stack[0];
    v0072 = qcdr(v0072);
    stack[0] = v0072;
    goto v0034;

v0019:
    v0072 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0072); }
// error exit handlers
v0083:
    popv(2);
    return nil;
}



// Code for mkuwedge

static LispObject CC_mkuwedge(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0083, v0119;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkuwedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0083 = v0037;
// end of prologue
    v0119 = v0083;
    v0119 = qcdr(v0119);
    if (v0119 == nil) goto v0078;
    v0119 = elt(env, 1); // wedge
    v0083 = cons(v0119, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[0];
    fn = elt(env, 2); // fkern
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0083 = qcar(v0083);
    { popv(1); return onevalue(v0083); }

v0078:
    v0083 = qcar(v0083);
    { popv(1); return onevalue(v0083); }
// error exit handlers
v0043:
    popv(1);
    return nil;
}



// Code for form1

static LispObject CC_form1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0390, v0190, v0189, v0391;
    LispObject fn;
    LispObject v0045, v0031, v0037;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "form1");
    va_start(aa, nargs);
    v0037 = va_arg(aa, LispObject);
    v0031 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for form1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0031,v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0037,v0031,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0045;
    stack[-2] = v0031;
    stack[-3] = v0037;
// end of prologue

v0392:
    v0390 = stack[-3];
    if (!consp(v0390)) goto v0018;
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    if (!consp(v0390)) goto v0108;
    v0189 = stack[-3];
    v0190 = stack[-2];
    v0390 = stack[-1];
    {
        popv(6);
        fn = elt(env, 25); // form2
        return (*qfnn(fn))(qenv(fn), 3, v0189, v0190, v0390);
    }

v0108:
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    if (symbolp(v0390)) goto v0127;
    v0390 = stack[-3];
    v0190 = qcar(v0390);
    v0390 = elt(env, 3); // "operator"
    fn = elt(env, 26); // typerr
    v0390 = (*qfn2(fn))(qenv(fn), v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    goto v0394;

v0394:
    v0190 = stack[-1];
    v0390 = elt(env, 6); // symbolic
    if (v0190 == v0390) goto v0395;
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    if (!symbolp(v0390)) v0390 = nil;
    else { v0390 = qfastgets(v0390);
           if (v0390 != nil) { v0390 = elt(v0390, 59); // opfn
#ifdef RECORD_GET
             if (v0390 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0390 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0390 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0390 == SPID_NOPROP) v0390 = nil; else v0390 = lisp_true; }}
#endif
    goto v0396;

v0396:
    if (v0390 == nil) goto v0220;
    v0390 = stack[-3];
    fn = elt(env, 27); // argnochk
    v0390 = (*qfn1(fn))(qenv(fn), v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    goto v0220;

v0220:
    v0390 = stack[-3];
    v0189 = qcdr(v0390);
    v0190 = stack[-2];
    v0390 = stack[-1];
    fn = elt(env, 28); // formlis
    v0390 = (*qfnn(fn))(qenv(fn), 3, v0189, v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    stack[-4] = v0390;
    v0190 = stack[-4];
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    if (equal(v0190, v0390)) goto v0397;
    v0390 = stack[-3];
    v0190 = qcar(v0390);
    v0390 = stack[-4];
    v0390 = cons(v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    goto v0398;

v0398:
    stack[0] = v0390;
    v0190 = stack[-1];
    v0390 = elt(env, 6); // symbolic
    if (v0190 == v0390) goto v0399;
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    if (!symbolp(v0390)) v0390 = nil;
    else { v0390 = qfastgets(v0390);
           if (v0390 != nil) { v0390 = elt(v0390, 36); // stat
#ifdef RECORD_GET
             if (v0390 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0390 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0390 == SPID_NOPROP) v0390 = nil; }}
#endif
    if (!(v0390 == nil)) goto v0400;
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    if (v0390 == nil) goto v0401;
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0190 = qcar(v0390);
    v0390 = elt(env, 18); // quote
    if (!consp(v0190)) goto v0209;
    v0190 = qcar(v0190);
    if (!(v0190 == v0390)) goto v0209;
    v0390 = qvalue(elt(env, 19)); // !*micro!-version
    if (v0390 == nil) goto v0193;
    v0390 = qvalue(elt(env, 20)); // !*defn
    v0390 = (v0390 == nil ? lisp_true : nil);
    goto v0402;

v0402:
    v0390 = (v0390 == nil ? lisp_true : nil);
    goto v0403;

v0403:
    if (!(v0390 == nil)) goto v0400;
    v0190 = stack[0];
    v0390 = stack[-2];
    fn = elt(env, 29); // intexprnp
    v0390 = (*qfn2(fn))(qenv(fn), v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    if (v0390 == nil) goto v0194;
    v0390 = qvalue(elt(env, 21)); // !*composites
    if (v0390 == nil) goto v0404;
    v0390 = qvalue(elt(env, 15)); // nil
    goto v0400;

v0400:
    if (v0390 == nil) goto v0405;
    v0190 = stack[0];
    v0390 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); // macrochk
        return (*qfn2(fn))(qenv(fn), v0190, v0390);
    }

v0405:
    v0190 = stack[-1];
    v0390 = elt(env, 23); // algebraic
    if (v0190 == v0390) goto v0406;
    v0391 = stack[0];
    v0189 = stack[-2];
    v0190 = stack[-1];
    v0390 = elt(env, 23); // algebraic
    {
        popv(6);
        fn = elt(env, 31); // convertmode
        return (*qfnn(fn))(qenv(fn), 4, v0391, v0189, v0190, v0390);
    }

v0406:
    stack[0] = elt(env, 24); // list
    v0390 = stack[-3];
    v0190 = qcar(v0390);
    v0390 = stack[-2];
    fn = elt(env, 32); // algid
    v0190 = (*qfn2(fn))(qenv(fn), v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    v0390 = stack[-4];
    {
        LispObject v0407 = stack[0];
        popv(6);
        return list2star(v0407, v0190, v0390);
    }

v0404:
    v0190 = qvalue(elt(env, 22)); // current!-modulus
    v0390 = (LispObject)17; // 1
    v0390 = (v0190 == v0390 ? lisp_true : nil);
    goto v0400;

v0194:
    v0390 = qvalue(elt(env, 15)); // nil
    goto v0400;

v0193:
    v0390 = qvalue(elt(env, 15)); // nil
    goto v0402;

v0209:
    v0390 = qvalue(elt(env, 15)); // nil
    goto v0403;

v0401:
    v0390 = qvalue(elt(env, 15)); // nil
    goto v0403;

v0399:
    v0390 = qvalue(elt(env, 9)); // t
    goto v0400;

v0397:
    v0390 = stack[-3];
    goto v0398;

v0395:
    v0390 = qvalue(elt(env, 9)); // t
    goto v0396;

v0127:
    v0390 = stack[-3];
    v0190 = qcar(v0390);
    v0390 = elt(env, 4); // comment
    if (v0190 == v0390) goto v0036;
    v0390 = stack[-3];
    v0190 = qcar(v0390);
    v0390 = elt(env, 5); // noform
    v0390 = Lflagp(nil, v0190, v0390);
    env = stack[-5];
    if (!(v0390 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    fn = elt(env, 33); // arrayp
    v0390 = (*qfn1(fn))(qenv(fn), v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    if (v0390 == nil) goto v0408;
    v0190 = stack[-1];
    v0390 = elt(env, 6); // symbolic
    if (!(v0190 == v0390)) goto v0408;
    stack[0] = elt(env, 7); // getel
    v0189 = stack[-3];
    v0190 = stack[-2];
    v0390 = stack[-1];
    fn = elt(env, 34); // intargfn
    v0390 = (*qfnn(fn))(qenv(fn), 3, v0189, v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    {
        LispObject v0409 = stack[0];
        popv(6);
        return list2(v0409, v0390);
    }

v0408:
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    if (v0390 == nil) goto v0057;
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    if (!symbolp(v0390)) v0190 = nil;
    else { v0190 = qfastgets(v0390);
           if (v0190 != nil) { v0190 = elt(v0190, 2); // rtype
#ifdef RECORD_GET
             if (v0190 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0190 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0190 == SPID_NOPROP) v0190 = nil; }}
#endif
    v0390 = elt(env, 8); // vector
    if (v0190 == v0390) goto v0410;
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0390 = qcar(v0390);
    v0390 = Lsimple_vectorp(nil, v0390);
    env = stack[-5];
    if (!(v0390 == nil)) goto v0411;
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0190 = qcar(v0390);
    v0390 = elt(env, 10); // vecfn
    v0390 = Lflagpcar(nil, v0190, v0390);
    env = stack[-5];
    goto v0411;

v0411:
    if (v0390 == nil) goto v0057;
    v0189 = stack[-3];
    v0190 = stack[-2];
    v0390 = stack[-1];
    {
        popv(6);
        fn = elt(env, 35); // getvect
        return (*qfnn(fn))(qenv(fn), 3, v0189, v0190, v0390);
    }

v0057:
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    if (!symbolp(v0390)) v0390 = nil;
    else { v0390 = qfastgets(v0390);
           if (v0390 != nil) { v0390 = elt(v0390, 48); // modefn
#ifdef RECORD_GET
             if (v0390 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0390 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0390 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0390 == SPID_NOPROP) v0390 = nil; else v0390 = lisp_true; }}
#endif
    if (v0390 == nil) goto v0412;
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0391 = qcar(v0390);
    v0189 = stack[-2];
    v0190 = stack[-1];
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    {
        popv(6);
        fn = elt(env, 31); // convertmode
        return (*qfnn(fn))(qenv(fn), 4, v0391, v0189, v0190, v0390);
    }

v0412:
    v0390 = stack[-3];
    v0190 = qcar(v0390);
    v0390 = elt(env, 11); // formfn
    v0390 = get(v0190, v0390);
    env = stack[-5];
    stack[-4] = v0390;
    if (v0390 == nil) goto v0048;
    v0391 = stack[-4];
    v0189 = stack[-3];
    v0190 = stack[-2];
    v0390 = stack[-1];
    v0190 = Lapply3(nil, 4, v0391, v0189, v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    v0390 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); // macrochk
        return (*qfn2(fn))(qenv(fn), v0190, v0390);
    }

v0048:
    v0390 = stack[-3];
    v0390 = qcar(v0390);
    if (!symbolp(v0390)) v0190 = nil;
    else { v0190 = qfastgets(v0390);
           if (v0190 != nil) { v0190 = elt(v0190, 36); // stat
#ifdef RECORD_GET
             if (v0190 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0190 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0190 == SPID_NOPROP) v0190 = nil; }}
#endif
    v0390 = elt(env, 12); // rlis
    if (v0190 == v0390) goto v0237;
    v0390 = stack[-3];
    v0190 = qcar(v0390);
    v0390 = elt(env, 13); // !*comma!*
    if (!(v0190 == v0390)) goto v0394;
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0390 = qcar(v0390);
    if (!consp(v0390)) goto v0413;
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0390 = qcdr(v0390);
    v0390 = qcar(v0390);
    if (!consp(v0390)) goto v0414;
    v0390 = qvalue(elt(env, 15)); // nil
    goto v0232;

v0232:
    if (v0390 == nil) goto v0300;
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0390 = qcar(v0390);
    v0390 = qcar(v0390);
    fn = elt(env, 36); // blocktyperr
    v0390 = (*qfn1(fn))(qenv(fn), v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    goto v0394;

v0300:
    stack[-4] = elt(env, 16); // rlisp
    stack[0] = (LispObject)161; // 10
    v0190 = elt(env, 17); // "Syntax error: , invalid after"
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0390 = qcar(v0390);
    v0390 = list2(v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    fn = elt(env, 37); // rerror
    v0390 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[0], v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    goto v0394;

v0414:
    v0390 = stack[-3];
    v0390 = qcdr(v0390);
    v0390 = qcar(v0390);
    v0190 = qcar(v0390);
    v0390 = elt(env, 14); // type
    v0390 = Lflagp(nil, v0190, v0390);
    env = stack[-5];
    goto v0232;

v0413:
    v0390 = qvalue(elt(env, 15)); // nil
    goto v0232;

v0237:
    v0189 = stack[-3];
    v0190 = stack[-2];
    v0390 = stack[-1];
    fn = elt(env, 38); // formrlis
    v0190 = (*qfnn(fn))(qenv(fn), 3, v0189, v0190, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    v0390 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); // macrochk
        return (*qfn2(fn))(qenv(fn), v0190, v0390);
    }

v0410:
    v0390 = qvalue(elt(env, 9)); // t
    goto v0411;

v0036:
    v0390 = stack[-3];
    fn = elt(env, 39); // lastpair
    v0390 = (*qfn1(fn))(qenv(fn), v0390);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-5];
    v0189 = qcar(v0390);
    v0190 = stack[-2];
    v0390 = stack[-1];
    stack[-3] = v0189;
    stack[-2] = v0190;
    stack[-1] = v0390;
    goto v0392;

v0018:
    v0390 = stack[-3];
    if (!(symbolp(v0390))) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0190 = stack[-3];
    v0390 = elt(env, 1); // ed
    if (v0190 == v0390) goto v0079;
    v0390 = stack[-3];
    if (!symbolp(v0390)) v0390 = nil;
    else { v0390 = qfastgets(v0390);
           if (v0390 != nil) { v0390 = elt(v0390, 48); // modefn
#ifdef RECORD_GET
             if (v0390 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0390 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0390 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0390 == SPID_NOPROP) v0390 = nil; else v0390 = lisp_true; }}
#endif
    if (v0390 == nil) goto v0075;
    v0390 = stack[-3];
    {
        popv(6);
        fn = elt(env, 40); // set!-global!-mode
        return (*qfn1(fn))(qenv(fn), v0390);
    }

v0075:
    v0190 = stack[-1];
    v0390 = elt(env, 2); // idfn
    v0390 = get(v0190, v0390);
    stack[-4] = v0390;
    if (v0390 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0189 = stack[-4];
    v0190 = stack[-3];
    v0390 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v0189, v0190, v0390);

v0079:
    v0390 = stack[-3];
    popv(6);
    return ncons(v0390);
// error exit handlers
v0393:
    popv(6);
    return nil;
}



// Code for formop

static LispObject CC_formop(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0082, v0114;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0037;
// end of prologue
    stack[-2] = nil;
    goto v0028;

v0028:
    v0082 = stack[-1];
    if (!consp(v0082)) goto v0086;
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    v0082 = (consp(v0082) ? nil : lisp_true);
    goto v0065;

v0065:
    if (v0082 == nil) goto v0052;
    v0082 = stack[-1];
    v0114 = v0082;
    goto v0022;

v0022:
    v0082 = stack[-2];
    if (v0082 == nil) { popv(4); return onevalue(v0114); }
    v0082 = stack[-2];
    v0082 = qcar(v0082);
    fn = elt(env, 2); // raddf
    v0082 = (*qfn2(fn))(qenv(fn), v0082, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-3];
    v0114 = v0082;
    v0082 = stack[-2];
    v0082 = qcdr(v0082);
    stack[-2] = v0082;
    goto v0022;

v0052:
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    stack[0] = qcar(v0082);
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    v0082 = qcdr(v0082);
    v0082 = CC_formop(env, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-3];
    fn = elt(env, 3); // multop
    v0114 = (*qfn2(fn))(qenv(fn), stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-3];
    v0082 = stack[-2];
    v0082 = cons(v0114, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-3];
    stack[-2] = v0082;
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    stack[-1] = v0082;
    goto v0028;

v0086:
    v0082 = qvalue(elt(env, 1)); // t
    goto v0065;
// error exit handlers
v0128:
    popv(4);
    return nil;
}



// Code for leftzeros

static LispObject CC_leftzeros(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0093, v0085;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for leftzeros");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    stack[-1] = nil;
    goto v0028;

v0028:
    v0093 = stack[0];
    if (v0093 == nil) goto v0086;
    v0093 = stack[0];
    v0085 = qcar(v0093);
    v0093 = (LispObject)1; // 0
    v0093 = Lneq(nil, v0085, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-2];
    goto v0065;

v0065:
    if (v0093 == nil) goto v0052;
    v0093 = (LispObject)1; // 0
    v0085 = v0093;
    goto v0022;

v0022:
    v0093 = stack[-1];
    if (v0093 == nil) { popv(3); return onevalue(v0085); }
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    v0093 = (LispObject)(int32_t)((int32_t)v0093 + (int32_t)v0085 - TAG_FIXNUM);
    v0085 = v0093;
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    goto v0022;

v0052:
    v0085 = (LispObject)17; // 1
    v0093 = stack[-1];
    v0093 = cons(v0085, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-2];
    stack[-1] = v0093;
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    stack[0] = v0093;
    goto v0028;

v0086:
    v0093 = qvalue(elt(env, 1)); // t
    goto v0065;
// error exit handlers
v0315:
    popv(3);
    return nil;
}



// Code for arintequiv!:

static LispObject CC_arintequivT(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0089, v0122, v0042;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0042 = v0037;
// end of prologue
    v0089 = v0042;
    v0089 = qcdr(v0089);
    if (is_number(v0089)) goto v0006;
    v0089 = v0042;
    v0089 = qcdr(v0089);
    v0122 = qcar(v0089);
    v0089 = elt(env, 1); // !:rn!:
    if (v0122 == v0089) goto v0044;
    v0089 = qvalue(elt(env, 2)); // nil
    goto v0023;

v0023:
    if (v0089 == nil) goto v0067;
    v0089 = v0042;
    v0089 = qcdr(v0089);
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    return onevalue(v0089);

v0067:
    v0089 = qvalue(elt(env, 2)); // nil
    return onevalue(v0089);

v0044:
    v0089 = v0042;
    v0089 = qcdr(v0089);
    v0089 = qcdr(v0089);
    v0122 = qcdr(v0089);
    v0089 = (LispObject)17; // 1
    v0089 = (v0122 == v0089 ? lisp_true : nil);
    goto v0023;

v0006:
    v0089 = v0042;
    v0089 = qcdr(v0089);
    return onevalue(v0089);
}



// Code for mconv

static LispObject CC_mconv(LispObject env,
                         LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0028;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mconv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0037);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0037;
// end of prologue
    v0028 = qvalue(elt(env, 1)); // dmode!*
    fn = elt(env, 2); // dmconv0
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0028 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); // mconv1
        return (*qfn1(fn))(qenv(fn), v0028);
    }
// error exit handlers
v0022:
    popv(2);
    return nil;
}



setup_type const u10_setup[] =
{
    {"spmultm2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_spmultm2},
    {"bcone?",                  CC_bconeW,      too_many_1,    wrong_no_1},
    {"contrsp",                 too_few_2,      CC_contrsp,    wrong_no_2},
    {"cali_bc_fi",              CC_cali_bc_fi,  too_many_1,    wrong_no_1},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"th_match0",               too_few_2,      CC_th_match0,  wrong_no_2},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {"rread1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread1},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"polynommultiplybymonom",  too_few_2,      CC_polynommultiplybymonom,wrong_no_2},
    {"poly-abs",                CC_polyKabs,    too_many_1,    wrong_no_1},
    {"mri_2pasfat",             CC_mri_2pasfat, too_many_1,    wrong_no_1},
    {"searchpl",                CC_searchpl,    too_many_1,    wrong_no_1},
    {"rl_gettype",              CC_rl_gettype,  too_many_1,    wrong_no_1},
    {"vdp_poly",                CC_vdp_poly,    too_many_1,    wrong_no_1},
    {"expression",              CC_expression,  too_many_1,    wrong_no_1},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"lprim",                   CC_lprim,       too_many_1,    wrong_no_1},
    {"red_better",              too_few_2,      CC_red_better, wrong_no_2},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"scan",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_scan},
    {"polynomlistfinddivisor",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_polynomlistfinddivisor},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"tayexp-difference",       too_few_2,      CC_tayexpKdifference,wrong_no_2},
    {"ofsf_prepat",             CC_ofsf_prepat, too_many_1,    wrong_no_1},
    {"ibalp_simpat",            CC_ibalp_simpat,too_many_1,    wrong_no_1},
    {"omair",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omair},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"xord_lex",                too_few_2,      CC_xord_lex,   wrong_no_2},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"mv-domainlist--",         too_few_2,      CC_mvKdomainlistKK,wrong_no_2},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"exptf",                   too_few_2,      CC_exptf,      wrong_no_2},
    {"rrdls",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_rrdls},
    {"ofsf_posvarpat",          too_few_2,      CC_ofsf_posvarpat,wrong_no_2},
    {"janettreefind",           CC_janettreefind,too_many_1,   wrong_no_1},
    {"cl_varl1",                CC_cl_varl1,    too_many_1,    wrong_no_1},
    {"revv0",                   too_few_2,      CC_revv0,      wrong_no_2},
    {"cl_simplat",              too_few_2,      CC_cl_simplat, wrong_no_2},
    {"ibalp_litp",              CC_ibalp_litp,  too_many_1,    wrong_no_1},
    {"smtp",                    too_few_2,      CC_smtp,       wrong_no_2},
    {"on",                      CC_on,          too_many_1,    wrong_no_1},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"formop",                  CC_formop,      too_many_1,    wrong_no_1},
    {"leftzeros",               CC_leftzeros,   too_many_1,    wrong_no_1},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"mconv",                   CC_mconv,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u10", (two_args *)"13958 545620 2512529", 0}
};

// end of generated code
