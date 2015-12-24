
// $destdir/u34.c        Machine generated C code

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



// Code for cde_replace_nth

static LispObject CC_cde_replace_nth(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0012, v0013;
    LispObject fn;
    LispObject v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cde_replace_nth");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cde_replace_nth");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0004,v0003,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0009;
    stack[-1] = v0003;
    stack[-2] = v0004;
// end of prologue
    stack[-3] = nil;
    goto v0014;

v0014:
    v0012 = stack[-2];
    if (v0012 == nil) goto v0015;
    v0013 = stack[-1];
    v0012 = (LispObject)17; // 1
    if (v0013 == v0012) goto v0016;
    v0012 = stack[-2];
    v0013 = qcar(v0012);
    v0012 = stack[-3];
    v0012 = cons(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-3] = v0012;
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    stack[-2] = v0012;
    v0012 = stack[-1];
    v0012 = sub1(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-1] = v0012;
    goto v0014;

v0016:
    stack[-1] = stack[-3];
    v0013 = stack[0];
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    v0012 = cons(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    {
        LispObject v0018 = stack[-1];
        popv(5);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0018, v0012);
    }

v0015:
    v0012 = stack[-3];
    {
        popv(5);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0012);
    }
// error exit handlers
v0017:
    popv(5);
    return nil;
}



// Code for ofsf_sippsignchkf

static LispObject CC_ofsf_sippsignchkf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0059, v0060, v0061, v0062, v0063, v0064, v0065;
    LispObject fn;
    LispObject v0040, v0041, v0000, v0042, v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "ofsf_sippsignchkf");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0042 = va_arg(aa, LispObject);
    v0000 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_sippsignchkf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0040,v0041,v0000,v0042,v0009,v0003);
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0004,v0003,v0009,v0042,v0000,v0041);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0040;
    stack[-2] = v0041;
    stack[-3] = v0000;
    stack[-4] = v0042;
    stack[-5] = v0009;
    stack[-6] = v0003;
    stack[-7] = v0004;
// end of prologue
    v0059 = stack[-7];
    if (!consp(v0059)) goto v0066;
    v0059 = stack[-7];
    v0059 = qcar(v0059);
    v0059 = (consp(v0059) ? nil : lisp_true);
    goto v0067;

v0067:
    if (v0059 == nil) goto v0068;
    v0059 = stack[-7];
    {
        popv(10);
        fn = elt(env, 3); // ofsf_updsigndom
        return (*qfn1(fn))(qenv(fn), v0059);
    }

v0068:
    v0059 = stack[-7];
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0065 = qcar(v0059);
    v0064 = stack[-6];
    v0063 = stack[-5];
    v0062 = stack[-4];
    v0061 = stack[-3];
    v0060 = stack[-2];
    v0059 = stack[-1];
    fn = elt(env, 4); // ofsf_updsignvar
    v0059 = (*qfnn(fn))(qenv(fn), 7, v0065, v0064, v0063, v0062, v0061, v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-9];
    stack[0] = v0059;
    v0060 = stack[0];
    v0059 = elt(env, 2); // unknown
    if (v0060 == v0059) goto v0012;
    v0059 = stack[-7];
    v0059 = qcar(v0059);
    v0065 = qcdr(v0059);
    v0064 = stack[-6];
    v0063 = stack[-5];
    v0062 = stack[-4];
    v0061 = stack[-3];
    v0060 = stack[-2];
    v0059 = stack[-1];
    v0059 = CC_ofsf_sippsignchkf(env, 7, v0065, v0064, v0063, v0062, v0061, v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-9];
    stack[-8] = v0059;
    v0060 = stack[-8];
    v0059 = elt(env, 2); // unknown
    if (v0060 == v0059) goto v0070;
    v0059 = stack[-7];
    v0065 = qcdr(v0059);
    v0064 = stack[-6];
    v0063 = stack[-5];
    v0062 = stack[-4];
    v0061 = stack[-3];
    v0060 = stack[-2];
    v0059 = stack[-1];
    v0059 = CC_ofsf_sippsignchkf(env, 7, v0065, v0064, v0063, v0062, v0061, v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-9];
    stack[-1] = v0059;
    v0060 = stack[-1];
    v0059 = elt(env, 2); // unknown
    if (v0060 == v0059) goto v0071;
    v0060 = stack[0];
    v0059 = stack[-7];
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0059 = qcdr(v0059);
    fn = elt(env, 5); // ofsf_updsignpow
    v0059 = (*qfn2(fn))(qenv(fn), v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-9];
    stack[0] = v0059;
    v0060 = stack[-8];
    v0059 = stack[0];
    fn = elt(env, 6); // ofsf_updsignmult
    v0059 = (*qfn2(fn))(qenv(fn), v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-9];
    v0061 = v0059;
    v0060 = v0061;
    v0059 = elt(env, 2); // unknown
    if (v0060 == v0059) goto v0072;
    v0060 = v0061;
    v0059 = stack[-1];
    {
        popv(10);
        fn = elt(env, 7); // ofsf_updsignadd
        return (*qfn2(fn))(qenv(fn), v0060, v0059);
    }

v0072:
    v0059 = elt(env, 2); // unknown
    { popv(10); return onevalue(v0059); }

v0071:
    v0059 = elt(env, 2); // unknown
    { popv(10); return onevalue(v0059); }

v0070:
    v0059 = elt(env, 2); // unknown
    { popv(10); return onevalue(v0059); }

v0012:
    v0059 = elt(env, 2); // unknown
    { popv(10); return onevalue(v0059); }

v0066:
    v0059 = qvalue(elt(env, 1)); // t
    goto v0067;
// error exit handlers
v0069:
    popv(10);
    return nil;
}



// Code for ithlistelem

static LispObject CC_ithlistelem(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0076, v0077;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ithlistelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
// end of prologue
    v0076 = stack[-1];
    if (v0076 == nil) goto v0040;
    v0076 = stack[-1];
    v0077 = qcar(v0076);
    v0076 = stack[0];
    fn = elt(env, 1); // nth
    stack[-2] = (*qfn2(fn))(qenv(fn), v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-3];
    v0076 = stack[-1];
    v0077 = qcdr(v0076);
    v0076 = stack[0];
    v0076 = CC_ithlistelem(env, v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    {
        LispObject v0078 = stack[-2];
        popv(4);
        return cons(v0078, v0076);
    }

v0040:
    v0076 = nil;
    { popv(4); return onevalue(v0076); }
// error exit handlers
v0008:
    popv(4);
    return nil;
}



// Code for maxl

static LispObject CC_maxl(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0080, v0081;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
// end of prologue
    stack[-1] = nil;
    goto v0040;

v0040:
    v0080 = stack[0];
    if (v0080 == nil) goto v0014;
    v0080 = stack[0];
    v0081 = qcar(v0080);
    v0080 = stack[-1];
    v0080 = cons(v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    stack[-1] = v0080;
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    stack[0] = v0080;
    goto v0040;

v0014:
    v0080 = (LispObject)-159999; // -10000
    v0081 = v0080;
    goto v0028;

v0028:
    v0080 = stack[-1];
    if (v0080 == nil) { popv(3); return onevalue(v0081); }
    v0080 = stack[-1];
    v0080 = qcar(v0080);
    fn = elt(env, 1); // max
    v0080 = (*qfn2(fn))(qenv(fn), v0080, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    v0081 = v0080;
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    stack[-1] = v0080;
    goto v0028;
// error exit handlers
v0082:
    popv(3);
    return nil;
}



// Code for make!-unique!-freevars

static LispObject CC_makeKuniqueKfreevars(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0093, v0094, v0095;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-unique-freevars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0094 = v0004;
// end of prologue
    v0093 = v0094;
    if (!consp(v0093)) goto v0096;
    v0093 = v0094;
    stack[-3] = v0093;
    v0093 = stack[-3];
    if (v0093 == nil) goto v0097;
    v0093 = stack[-3];
    v0093 = qcar(v0093);
    v0093 = CC_makeKuniqueKfreevars(env, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    v0093 = ncons(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    stack[-1] = v0093;
    stack[-2] = v0093;
    goto v0099;

v0099:
    v0093 = stack[-3];
    v0093 = qcdr(v0093);
    stack[-3] = v0093;
    v0093 = stack[-3];
    if (v0093 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0093 = stack[-3];
    v0093 = qcar(v0093);
    v0093 = CC_makeKuniqueKfreevars(env, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    v0093 = ncons(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    v0093 = Lrplacd(nil, stack[0], v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    goto v0099;

v0097:
    v0093 = qvalue(elt(env, 4)); // nil
    { popv(5); return onevalue(v0093); }

v0096:
    v0095 = v0094;
    v0093 = elt(env, 1); // gen
    v0093 = get(v0095, v0093);
    env = stack[-4];
    if (v0093 == nil) { popv(5); return onevalue(v0094); }
    v0095 = v0094;
    v0093 = qvalue(elt(env, 2)); // freevarlist!*
    v0093 = Latsoc(nil, v0095, v0093);
    stack[0] = v0093;
    v0093 = stack[0];
    if (!(v0093 == nil)) goto v0006;
    stack[0] = v0094;
    fn = elt(env, 5); // pm!:gensym
    v0093 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    v0093 = cons(stack[0], v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    stack[0] = v0093;
    v0093 = stack[0];
    v0095 = qcdr(v0093);
    v0094 = elt(env, 1); // gen
    v0093 = qvalue(elt(env, 3)); // t
    v0093 = Lputprop(nil, 3, v0095, v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    v0094 = stack[0];
    v0093 = qvalue(elt(env, 2)); // freevarlist!*
    v0093 = cons(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0093; // freevarlist!*
    goto v0006;

v0006:
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    { popv(5); return onevalue(v0093); }
// error exit handlers
v0098:
    popv(5);
    return nil;
}



// Code for sc_subtrsq

static LispObject CC_sc_subtrsq(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0096, v0100;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_subtrsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0096 = v0003;
    v0100 = v0004;
// end of prologue
    stack[0] = v0100;
    fn = elt(env, 1); // negsq
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    {
        LispObject v0073 = stack[0];
        popv(2);
        fn = elt(env, 2); // addsq
        return (*qfn2(fn))(qenv(fn), v0073, v0096);
    }
// error exit handlers
v0101:
    popv(2);
    return nil;
}



// Code for getrlist

static LispObject CC_getrlist(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0081, v0102, v0103;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0103 = v0004;
// end of prologue
    v0102 = v0103;
    v0081 = elt(env, 1); // list
    if (!consp(v0102)) goto v0104;
    v0102 = qcar(v0102);
    if (!(v0102 == v0081)) goto v0104;
    v0081 = v0103;
    v0081 = qcdr(v0081);
    { popv(1); return onevalue(v0081); }

v0104:
    v0102 = v0103;
    v0081 = elt(env, 2); // !*sq
    if (!consp(v0102)) goto v0078;
    v0102 = qcar(v0102);
    if (!(v0102 == v0081)) goto v0078;
    v0081 = v0103;
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    fn = elt(env, 4); // prepsq
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[0];
    v0102 = v0081;
    goto v0079;

v0079:
    v0081 = elt(env, 3); // "list"
    {
        popv(1);
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(qenv(fn), v0102, v0081);
    }

v0078:
    v0081 = v0103;
    v0102 = v0081;
    goto v0079;
// error exit handlers
v0082:
    popv(1);
    return nil;
}



// Code for chkint!*

static LispObject CC_chkintH(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0112, v0113, v0114;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chkint*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0004;
// end of prologue
    v0112 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v0112 == nil) goto v0080;
    v0112 = stack[0];
    v0112 = Lfloatp(nil, v0112);
    env = stack[-1];
    if (v0112 == nil) goto v0101;
    v0112 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // fl2bf
        return (*qfn1(fn))(qenv(fn), v0112);
    }

v0101:
    v0112 = stack[0];
    if (!consp(v0112)) goto v0079;
    v0112 = stack[0];
    goto v0067;

v0067:
    {
        popv(2);
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(qenv(fn), v0112);
    }

v0079:
    v0112 = stack[0];
    v0112 = integerp(v0112);
    if (v0112 == nil) goto v0008;
    v0114 = elt(env, 2); // !:rd!:
    v0113 = stack[0];
    v0112 = (LispObject)1; // 0
    v0112 = list2star(v0114, v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    goto v0067;

v0008:
    v0112 = stack[0];
    fn = elt(env, 6); // read!:num
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    goto v0067;

v0080:
    v0112 = stack[0];
    v0112 = Labsval(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0113 = v0112;
    v0112 = stack[0];
    v0112 = Lfloatp(nil, v0112);
    env = stack[-1];
    if (!(v0112 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0112 = v0113;
    fn = elt(env, 7); // msd
    v0113 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0112 = qvalue(elt(env, 3)); // !!maxbflexp
    v0112 = (LispObject)lesseq2(v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    v0112 = v0112 ? lisp_true : nil;
    env = stack[-1];
    if (v0112 == nil) goto v0116;
    v0112 = stack[0];
        popv(2);
        return Lfloat(nil, v0112);

v0116:
    fn = elt(env, 8); // rndbfon
    v0112 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0112 = stack[0];
    v0112 = Lfloatp(nil, v0112);
    env = stack[-1];
    if (v0112 == nil) goto v0097;
    v0112 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // fl2bf
        return (*qfn1(fn))(qenv(fn), v0112);
    }

v0097:
    v0112 = stack[0];
    if (!consp(v0112)) goto v0117;
    v0112 = stack[0];
    goto v0118;

v0118:
    {
        popv(2);
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(qenv(fn), v0112);
    }

v0117:
    v0112 = stack[0];
    v0112 = integerp(v0112);
    if (v0112 == nil) goto v0043;
    v0114 = elt(env, 2); // !:rd!:
    v0113 = stack[0];
    v0112 = (LispObject)1; // 0
    v0112 = list2star(v0114, v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    goto v0118;

v0043:
    v0112 = stack[0];
    fn = elt(env, 6); // read!:num
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    goto v0118;
// error exit handlers
v0115:
    popv(2);
    return nil;
}



// Code for indordl2

static LispObject CC_indordl2(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0074, v0076;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indordl2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
// end of prologue
    v0076 = stack[-1];
    v0074 = stack[0];
    fn = elt(env, 1); // indordlp
    v0074 = (*qfn2(fn))(qenv(fn), v0076, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    if (v0074 == nil) goto v0120;
    v0076 = stack[-1];
    v0074 = stack[0];
    popv(2);
    return list2(v0076, v0074);

v0120:
    v0076 = stack[0];
    v0074 = stack[-1];
    popv(2);
    return list2(v0076, v0074);
// error exit handlers
v0007:
    popv(2);
    return nil;
}



// Code for calc_coeff

static LispObject CC_calc_coeff(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0056, v0054, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_coeff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
// end of prologue
    v0056 = stack[-1];
    if (v0056 == nil) goto v0041;
    v0056 = stack[-1];
    v0054 = qcar(v0056);
    v0056 = stack[0];
    fn = elt(env, 1); // calc_world
    v0056 = (*qfn2(fn))(qenv(fn), v0054, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-3];
    v0015 = v0056;
    v0054 = v0015;
    v0056 = (LispObject)1; // 0
    if (v0054 == v0056) goto v0075;
    stack[-2] = v0015;
    v0056 = stack[-1];
    v0054 = qcdr(v0056);
    v0056 = stack[0];
    v0056 = CC_calc_coeff(env, v0054, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    {
        LispObject v0013 = stack[-2];
        popv(4);
        return cons(v0013, v0056);
    }

v0075:
    v0056 = (LispObject)1; // 0
    popv(4);
    return ncons(v0056);

v0041:
    v0056 = (LispObject)17; // 1
    popv(4);
    return ncons(v0056);
// error exit handlers
v0012:
    popv(4);
    return nil;
}



// Code for liennewstruc

static LispObject CC_liennewstruc(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0292, v0293, v0294, v0295;
    LispObject fn;
    LispObject v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "liennewstruc");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for liennewstruc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0004,v0003,v0009);
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
    stack[-12] = v0009;
    stack[-13] = v0003;
    stack[-14] = v0004;
// end of prologue
    v0294 = elt(env, 1); // lie_a
    v0293 = stack[-14];
    v0292 = stack[-14];
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = ncons(v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 12); // matrix
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 13); // aeval
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[0] = elt(env, 1); // lie_a
    v0294 = elt(env, 2); // expt
    v0293 = elt(env, 1); // lie_a
    v0292 = (LispObject)1; // 0
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 13); // aeval
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0292 = (*qfn2(fn))(qenv(fn), stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-13];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-15] = v0292;
    goto v0057;

v0057:
    stack[0] = elt(env, 3); // difference
    v0294 = elt(env, 3); // difference
    v0293 = stack[-14];
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-15];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0097;
    v0294 = elt(env, 5); // plus
    v0293 = stack[-13];
    v0292 = (LispObject)33; // 2
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-2] = v0292;
    goto v0297;

v0297:
    stack[0] = elt(env, 3); // difference
    v0292 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-2];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0298;
    stack[0] = elt(env, 9); // lientrans
    v0294 = elt(env, 8); // times
    v0293 = elt(env, 1); // lie_a
    v0292 = elt(env, 9); // lientrans
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 13); // aeval
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0292 = (*qfn2(fn))(qenv(fn), stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0294 = elt(env, 5); // plus
    v0293 = stack[-13];
    v0292 = (LispObject)33; // 2
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-13] = v0292;
    goto v0299;

v0299:
    stack[0] = elt(env, 3); // difference
    v0294 = elt(env, 3); // difference
    v0293 = stack[-14];
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-13];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0300;
    v0292 = elt(env, 1); // lie_a
    v0292 = ncons(v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 17); // clear
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 13); // aeval
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    v0292 = nil;
    { popv(17); return onevalue(v0292); }

v0300:
    v0294 = elt(env, 5); // plus
    v0293 = stack[-13];
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-11] = v0292;
    goto v0301;

v0301:
    stack[0] = elt(env, 3); // difference
    v0292 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-11];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0302;
    v0292 = stack[-13];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-13] = v0292;
    goto v0299;

v0302:
    v0294 = elt(env, 6); // lie_lamb
    v0293 = stack[-13];
    v0292 = stack[-11];
    stack[-10] = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-9] = elt(env, 7); // quotient
    v0292 = (LispObject)17; // 1
    stack[-8] = v0292;
    v0292 = (LispObject)1; // 0
    stack[-7] = v0292;
    goto v0303;

v0303:
    stack[0] = elt(env, 3); // difference
    v0292 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-8];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0304;
    v0292 = stack[-7];
    stack[0] = v0292;
    v0294 = elt(env, 9); // lientrans
    v0293 = (LispObject)17; // 1
    v0292 = stack[-12];
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = list3(stack[-9], stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0292 = (*qfn2(fn))(qenv(fn), stack[-10], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-11];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-11] = v0292;
    goto v0301;

v0304:
    stack[-6] = elt(env, 5); // plus
    v0292 = (LispObject)17; // 1
    stack[-5] = v0292;
    v0292 = (LispObject)1; // 0
    stack[-4] = v0292;
    goto v0305;

v0305:
    stack[0] = elt(env, 3); // difference
    v0292 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-5];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0306;
    v0292 = stack[-4];
    v0293 = v0292;
    v0292 = stack[-7];
    v0292 = list3(stack[-6], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-7] = v0292;
    v0292 = stack[-8];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-8] = v0292;
    goto v0303;

v0306:
    stack[-3] = elt(env, 5); // plus
    stack[-2] = elt(env, 8); // times
    v0294 = elt(env, 9); // lientrans
    v0293 = stack[-13];
    v0292 = stack[-8];
    stack[-1] = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0294 = elt(env, 9); // lientrans
    v0293 = stack[-11];
    v0292 = stack[-5];
    stack[0] = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0295 = elt(env, 10); // lie_cc
    v0294 = stack[-8];
    v0293 = stack[-5];
    v0292 = stack[-12];
    v0292 = list4(v0295, v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = list4(stack[-2], stack[-1], stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-4];
    v0292 = list3(stack[-3], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-4] = v0292;
    v0292 = stack[-5];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-5] = v0292;
    goto v0305;

v0298:
    stack[-1] = elt(env, 1); // lie_a
    stack[0] = stack[-2];
    v0294 = elt(env, 5); // plus
    v0293 = stack[-13];
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-1] = list3(stack[-1], stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[0] = elt(env, 11); // minus
    v0294 = elt(env, 6); // lie_lamb
    v0293 = stack[-13];
    v0292 = stack[-2];
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = list2(stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0292 = (*qfn2(fn))(qenv(fn), stack[-1], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0294 = elt(env, 1); // lie_a
    v0293 = stack[-2];
    v0292 = stack[-13];
    stack[-1] = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[0] = elt(env, 6); // lie_lamb
    v0294 = elt(env, 5); // plus
    v0293 = stack[-13];
    v0292 = (LispObject)17; // 1
    v0293 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-2];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0292 = (*qfn2(fn))(qenv(fn), stack[-1], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-2];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-2] = v0292;
    goto v0297;

v0097:
    v0294 = elt(env, 5); // plus
    v0293 = stack[-15];
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-11] = v0292;
    goto v0307;

v0307:
    stack[0] = elt(env, 3); // difference
    v0292 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-11];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0095;
    v0292 = stack[-15];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-15] = v0292;
    goto v0057;

v0095:
    v0294 = elt(env, 6); // lie_lamb
    v0293 = stack[-15];
    v0292 = stack[-11];
    stack[-10] = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-9] = elt(env, 7); // quotient
    v0292 = (LispObject)17; // 1
    stack[-8] = v0292;
    v0292 = (LispObject)1; // 0
    stack[-7] = v0292;
    goto v0308;

v0308:
    stack[0] = elt(env, 3); // difference
    v0292 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-8];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0309;
    v0292 = stack[-7];
    stack[0] = v0292;
    v0294 = elt(env, 9); // lientrans
    v0293 = (LispObject)17; // 1
    v0292 = stack[-12];
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = list3(stack[-9], stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0292 = (*qfn2(fn))(qenv(fn), stack[-10], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-11];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-11] = v0292;
    goto v0307;

v0309:
    stack[-6] = elt(env, 5); // plus
    v0292 = (LispObject)17; // 1
    stack[-5] = v0292;
    v0292 = (LispObject)1; // 0
    stack[-4] = v0292;
    goto v0060;

v0060:
    stack[0] = elt(env, 3); // difference
    v0292 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-5];
    v0292 = list3(stack[0], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    if (v0292 == nil) goto v0310;
    v0292 = stack[-4];
    v0293 = v0292;
    v0292 = stack[-7];
    v0292 = list3(stack[-6], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-7] = v0292;
    v0292 = stack[-8];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-8] = v0292;
    goto v0308;

v0310:
    stack[-3] = elt(env, 5); // plus
    stack[-2] = elt(env, 8); // times
    v0294 = elt(env, 9); // lientrans
    v0293 = stack[-15];
    v0292 = stack[-8];
    stack[-1] = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0294 = elt(env, 9); // lientrans
    v0293 = stack[-11];
    v0292 = stack[-5];
    stack[0] = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0295 = elt(env, 10); // lie_cc
    v0294 = stack[-8];
    v0293 = stack[-5];
    v0292 = stack[-12];
    v0292 = list4(v0295, v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = list4(stack[-2], stack[-1], stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    v0292 = stack[-4];
    v0292 = list3(stack[-3], v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-4] = v0292;
    v0292 = stack[-5];
    v0294 = elt(env, 5); // plus
    v0293 = v0292;
    v0292 = (LispObject)17; // 1
    v0292 = list3(v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-16];
    stack[-5] = v0292;
    goto v0060;
// error exit handlers
v0296:
    popv(17);
    return nil;
}



// Code for listsub

static LispObject CC_listsub(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0012, v0013;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listsub");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0012 = v0003;
    stack[-3] = v0004;
// end of prologue
    v0012 = qcdr(v0012);
    stack[-4] = v0012;
    v0012 = stack[-4];
    if (v0012 == nil) goto v0119;
    v0012 = stack[-4];
    v0012 = qcar(v0012);
    v0013 = stack[-3];
    fn = elt(env, 2); // subeval1
    v0012 = (*qfn2(fn))(qenv(fn), v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-5];
    v0012 = ncons(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-5];
    stack[-1] = v0012;
    stack[-2] = v0012;
    goto v0021;

v0021:
    v0012 = stack[-4];
    v0012 = qcdr(v0012);
    stack[-4] = v0012;
    v0012 = stack[-4];
    if (v0012 == nil) goto v0076;
    stack[0] = stack[-1];
    v0012 = stack[-4];
    v0012 = qcar(v0012);
    v0013 = stack[-3];
    fn = elt(env, 2); // subeval1
    v0012 = (*qfn2(fn))(qenv(fn), v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-5];
    v0012 = ncons(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-5];
    v0012 = Lrplacd(nil, stack[0], v0012);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-5];
    v0012 = stack[-1];
    v0012 = qcdr(v0012);
    stack[-1] = v0012;
    goto v0021;

v0076:
    v0012 = stack[-2];
    goto v0028;

v0028:
    {
        popv(6);
        fn = elt(env, 3); // makelist
        return (*qfn1(fn))(qenv(fn), v0012);
    }

v0119:
    v0012 = qvalue(elt(env, 1)); // nil
    goto v0028;
// error exit handlers
v0018:
    popv(6);
    return nil;
}



// Code for red_tailreddriver

static LispObject CC_red_tailreddriver(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0290;
    LispObject fn;
    LispObject v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "red_tailreddriver");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_tailreddriver");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0004,v0003,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0009;
    stack[-2] = v0003;
    stack[-3] = v0004;
// end of prologue
    v0290 = stack[-2];
    fn = elt(env, 3); // bas_dpoly
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    if (v0290 == nil) goto v0027;
    v0290 = stack[-2];
    fn = elt(env, 3); // bas_dpoly
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    v0290 = qcdr(v0290);
    if (v0290 == nil) goto v0067;
    v0290 = stack[-3];
    v0290 = (v0290 == nil ? lisp_true : nil);
    goto v0021;

v0021:
    if (!(v0290 == nil)) { LispObject res = stack[-2]; popv(6); return onevalue(res); }

v0111:
    v0290 = stack[-2];
    fn = elt(env, 3); // bas_dpoly
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    if (v0290 == nil) goto v0077;
    stack[-4] = stack[-1];
    stack[0] = stack[-3];
    v0290 = stack[-2];
    fn = elt(env, 4); // red!=hidelt
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    v0290 = Lapply2(nil, 3, stack[-4], stack[0], v0290);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    stack[-2] = v0290;
    goto v0111;

v0077:
    v0290 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); // red!=recover
        return (*qfn1(fn))(qenv(fn), v0290);
    }

v0067:
    v0290 = qvalue(elt(env, 1)); // t
    goto v0021;

v0027:
    v0290 = qvalue(elt(env, 1)); // t
    goto v0021;
// error exit handlers
v0312:
    popv(6);
    return nil;
}



// Code for ext_mult

static LispObject CC_ext_mult(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0314, v0315, v0316;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ext_mult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0314 = v0003;
    v0315 = v0004;
// end of prologue
    v0315 = qcdr(v0315);
    v0314 = qcdr(v0314);
    fn = elt(env, 3); // merge_lists
    v0314 = (*qfn2(fn))(qenv(fn), v0315, v0314);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-1];
    stack[0] = v0314;
    v0314 = stack[0];
    if (v0314 == nil) goto v0066;
    v0314 = stack[0];
    v0314 = qcdr(v0314);
    if (v0314 == nil) goto v0068;
    v0315 = elt(env, 2); // ext
    v0314 = stack[0];
    v0314 = qcdr(v0314);
    v0314 = cons(v0315, v0314);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-1];
    fn = elt(env, 4); // !*a2k
    v0315 = (*qfn1(fn))(qenv(fn), v0314);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-1];
    v0314 = (LispObject)17; // 1
    fn = elt(env, 5); // to
    v0315 = (*qfn2(fn))(qenv(fn), v0315, v0314);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-1];
    v0314 = stack[0];
    v0314 = qcar(v0314);
    v0315 = cons(v0315, v0314);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-1];
    v0316 = qvalue(elt(env, 1)); // nil
    v0314 = (LispObject)17; // 1
    popv(2);
    return acons(v0315, v0316, v0314);

v0068:
    v0315 = (LispObject)17; // 1
    v0314 = (LispObject)17; // 1
    popv(2);
    return cons(v0315, v0314);

v0066:
    v0315 = qvalue(elt(env, 1)); // nil
    v0314 = (LispObject)17; // 1
    popv(2);
    return cons(v0315, v0314);
// error exit handlers
v0317:
    popv(2);
    return nil;
}



// Code for ra_qmk

static LispObject CC_ra_qmk(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0010, v0011, v0075;
    LispObject fn;
    LispObject v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ra_qmk");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_qmk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0004,v0003,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0010 = v0009;
    v0011 = v0003;
    v0075 = v0004;
// end of prologue
    stack[-1] = elt(env, 1); // !:ra!:
    stack[0] = v0075;
    fn = elt(env, 2); // riv_mk
    v0010 = (*qfn2(fn))(qenv(fn), v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    {
        LispObject v0091 = stack[-1];
        LispObject v0104 = stack[0];
        popv(2);
        return list3(v0091, v0104, v0010);
    }
// error exit handlers
v0090:
    popv(2);
    return nil;
}



// Code for polynomcompare

static LispObject CC_polynomcompare(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0051, v0049, v0050;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynomcompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0049 = v0003;
    v0051 = v0004;
// end of prologue
    stack[-1] = v0051;
    v0051 = v0049;
    stack[0] = v0051;
    goto v0100;

v0100:
    v0051 = stack[-1];
    v0051 = qcar(v0051);
    if (v0051 == nil) goto v0096;
    v0051 = stack[0];
    v0051 = qcar(v0051);
    if (v0051 == nil) goto v0096;
    v0051 = stack[-1];
    v0049 = qcar(v0051);
    v0051 = stack[0];
    v0051 = qcar(v0051);
    fn = elt(env, 2); // monomcompare
    v0051 = (*qfn2(fn))(qenv(fn), v0049, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    v0050 = v0051;
    v0049 = v0050;
    v0051 = (LispObject)17; // 1
    if (v0049 == v0051) goto v0007;
    v0049 = v0050;
    v0051 = (LispObject)-15; // -1
    if (v0049 == v0051) goto v0001;
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    stack[-1] = v0051;
    v0051 = stack[0];
    v0051 = qcdr(v0051);
    stack[0] = v0051;
    goto v0100;

v0001:
    v0051 = qvalue(elt(env, 1)); // nil
    v0051 = ncons(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    stack[-1] = v0051;
    goto v0100;

v0007:
    v0051 = qvalue(elt(env, 1)); // nil
    v0051 = ncons(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    stack[0] = v0051;
    goto v0100;

v0096:
    v0051 = stack[-1];
    v0051 = qcar(v0051);
    if (v0051 == nil) goto v0084;
    v0051 = (LispObject)17; // 1
    { popv(3); return onevalue(v0051); }

v0084:
    v0051 = stack[0];
    v0051 = qcar(v0051);
    if (v0051 == nil) goto v0118;
    v0051 = (LispObject)-15; // -1
    { popv(3); return onevalue(v0051); }

v0118:
    v0051 = (LispObject)1; // 0
    { popv(3); return onevalue(v0051); }
// error exit handlers
v0045:
    popv(3);
    return nil;
}



// Code for maxfrom1

static LispObject CC_maxfrom1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0076, v0077;
    LispObject fn;
    LispObject v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "maxfrom1");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxfrom1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0004,v0003,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0009;
    stack[-1] = v0003;
    stack[-2] = v0004;
// end of prologue

v0040:
    v0076 = stack[-2];
    if (v0076 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0076 = stack[-2];
    v0076 = qcar(v0076);
    v0077 = qcar(v0076);
    v0076 = stack[-1];
    fn = elt(env, 1); // nth
    v0077 = (*qfn2(fn))(qenv(fn), v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-3];
    v0076 = stack[0];
    fn = elt(env, 2); // max
    v0076 = (*qfn2(fn))(qenv(fn), v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-3];
    stack[0] = v0076;
    v0076 = stack[-2];
    v0076 = qcdr(v0076);
    stack[-2] = v0076;
    goto v0040;
// error exit handlers
v0008:
    popv(4);
    return nil;
}



// Code for get!-denom!-l

static LispObject CC_getKdenomKl(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-denom-l");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0056 = v0004;
// end of prologue
    v0055 = v0056;
    v0055 = qcar(v0055);
    if (!consp(v0055)) goto v0000;
    v0055 = v0056;
    v0055 = qcar(v0055);
    v0055 = qcdr(v0055);
    v0055 = qcdr(v0055);
    goto v0042;

v0042:
    v0056 = qcdr(v0056);
    stack[0] = v0056;
    goto v0067;

v0067:
    v0056 = stack[0];
    if (v0056 == nil) { popv(2); return onevalue(v0055); }
    v0056 = stack[0];
    v0056 = qcar(v0056);
    v0054 = v0056;
    v0056 = v0055;
    v0055 = v0054;
    if (!consp(v0055)) goto v0078;
    v0055 = v0054;
    v0055 = qcdr(v0055);
    v0055 = qcdr(v0055);
    goto v0077;

v0077:
    fn = elt(env, 2); // lcmn
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0056 = stack[0];
    v0056 = qcdr(v0056);
    stack[0] = v0056;
    goto v0067;

v0078:
    v0055 = (LispObject)17; // 1
    goto v0077;

v0000:
    v0055 = (LispObject)17; // 1
    goto v0042;
// error exit handlers
v0053:
    popv(2);
    return nil;
}



// Code for mk!+real!+inner!+product

static LispObject CC_mkLrealLinnerLproduct(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0289, v0051;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+real+inner+product");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0003;
    stack[-3] = v0004;
// end of prologue
    v0289 = stack[-3];
    fn = elt(env, 5); // get!+vec!+dim
    stack[0] = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    v0289 = stack[-2];
    fn = elt(env, 5); // get!+vec!+dim
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    if (equal(stack[0], v0289)) goto v0011;
    v0289 = elt(env, 1); // "wrong dimensions in innerproduct"
    fn = elt(env, 6); // rederr
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    goto v0011;

v0011:
    v0051 = qvalue(elt(env, 2)); // nil
    v0289 = (LispObject)17; // 1
    v0289 = cons(v0051, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    stack[0] = v0289;
    v0289 = (LispObject)17; // 1
    stack[-4] = v0289;
    goto v0088;

v0088:
    v0289 = stack[-3];
    fn = elt(env, 5); // get!+vec!+dim
    v0051 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    v0289 = stack[-4];
    v0289 = difference2(v0051, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    v0289 = Lminusp(nil, v0289);
    env = stack[-5];
    if (v0289 == nil) goto v0057;
    v0289 = qvalue(elt(env, 3)); // t
    stack[-1] = qvalue(elt(env, 4)); // !*sub2
    qvalue(elt(env, 4)) = v0289; // !*sub2
    v0289 = stack[0];
    fn = elt(env, 7); // subs2
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0319;
    env = stack[-5];
    stack[0] = v0289;
    qvalue(elt(env, 4)) = stack[-1]; // !*sub2
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0057:
    stack[-1] = stack[0];
    v0051 = stack[-3];
    v0289 = stack[-4];
    fn = elt(env, 8); // get!+vec!+entry
    stack[0] = (*qfn2(fn))(qenv(fn), v0051, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    v0051 = stack[-2];
    v0289 = stack[-4];
    fn = elt(env, 8); // get!+vec!+entry
    v0289 = (*qfn2(fn))(qenv(fn), v0051, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    fn = elt(env, 9); // multsq
    v0289 = (*qfn2(fn))(qenv(fn), stack[0], v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    fn = elt(env, 10); // addsq
    v0289 = (*qfn2(fn))(qenv(fn), stack[-1], v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    stack[0] = v0289;
    v0289 = stack[-4];
    v0289 = add1(v0289);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-5];
    stack[-4] = v0289;
    goto v0088;
// error exit handlers
v0319:
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; // !*sub2
    popv(6);
    return nil;
v0046:
    popv(6);
    return nil;
}



// Code for iv_cutcongs1

static LispObject CC_iv_cutcongs1(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0068, v0074;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for iv_cutcongs1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
// end of prologue

v0041:
    v0068 = stack[0];
    if (v0068 == nil) goto v0104;
    v0074 = stack[-1];
    v0068 = stack[0];
    v0068 = qcar(v0068);
    fn = elt(env, 3); // iv_cutcongs2
    v0068 = (*qfn2(fn))(qenv(fn), v0074, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    if (v0068 == nil) goto v0120;
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0041;

v0120:
    v0068 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0068); }

v0104:
    v0068 = qvalue(elt(env, 2)); // t
    { popv(3); return onevalue(v0068); }
// error exit handlers
v0111:
    popv(3);
    return nil;
}



// Code for sfto_mvarx

static LispObject CC_sfto_mvarx(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0075, v0016;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_mvarx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0016 = v0004;
// end of prologue
    v0075 = v0016;
    if (!consp(v0075)) goto v0028;
    v0075 = v0016;
    v0075 = qcar(v0075);
    v0075 = (consp(v0075) ? nil : lisp_true);
    goto v0014;

v0014:
    if (v0075 == nil) goto v0058;
    v0075 = qvalue(elt(env, 2)); // nil
    return onevalue(v0075);

v0058:
    v0075 = v0016;
    v0075 = qcar(v0075);
    v0075 = qcar(v0075);
    v0075 = qcar(v0075);
    return onevalue(v0075);

v0028:
    v0075 = qvalue(elt(env, 1)); // t
    goto v0014;
}



// Code for dip_moncomp

static LispObject CC_dip_moncomp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0101, v0073, v0092;
    LispObject v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip_moncomp");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip_moncomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0101 = v0009;
    v0073 = v0003;
    v0092 = v0004;
// end of prologue
    return list2star(v0073, v0092, v0101);
}



// Code for getargsrd

static LispObject CC_getargsrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0016, v0120;
    LispObject fn;
    argcheck(nargs, 0, "getargsrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getargsrd");
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
    v0120 = qvalue(elt(env, 1)); // char
    v0016 = elt(env, 2); // (b v a r)
    if (equal(v0120, v0016)) goto v0040;
    v0016 = nil;
    { popv(2); return onevalue(v0016); }

v0040:
    fn = elt(env, 3); // bvarrd
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    stack[0] = v0016;
    fn = elt(env, 4); // lex
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0016 = CC_getargsrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    {
        LispObject v0104 = stack[0];
        popv(2);
        return cons(v0104, v0016);
    }
// error exit handlers
v0091:
    popv(2);
    return nil;
}



// Code for evequal

static LispObject CC_evequal(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0290, v0012, v0013, v0086, v0087;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0013 = v0003;
    v0086 = v0004;
// end of prologue

v0041:
    v0290 = v0086;
    if (v0290 == nil) goto v0096;
    v0290 = qvalue(elt(env, 1)); // nil
    goto v0022;

v0022:
    if (v0290 == nil) goto v0021;
    v0290 = qvalue(elt(env, 2)); // t
    return onevalue(v0290);

v0021:
    v0290 = v0086;
    if (v0290 == nil) goto v0079;
    v0290 = v0013;
    if (v0290 == nil) goto v0016;
    v0087 = (LispObject)1; // 0
    v0290 = v0086;
    v0012 = qcar(v0290);
    v0290 = v0013;
    v0290 = qcar(v0290);
    v0290 = (LispObject)(int32_t)((int32_t)v0012 - (int32_t)v0290 + TAG_FIXNUM);
    if (v0087 == v0290) goto v0074;
    v0290 = qvalue(elt(env, 1)); // nil
    return onevalue(v0290);

v0074:
    v0290 = v0086;
    v0290 = qcdr(v0290);
    v0086 = v0290;
    v0290 = v0013;
    v0290 = qcdr(v0290);
    v0013 = v0290;
    goto v0041;

v0016:
    v0290 = elt(env, 3); // (0)
    v0013 = v0290;
    goto v0041;

v0079:
    v0290 = elt(env, 3); // (0)
    v0086 = v0290;
    goto v0041;

v0096:
    v0290 = v0013;
    v0290 = (v0290 == nil ? lisp_true : nil);
    goto v0022;
}



// Code for evalb

static LispObject CC_evalb(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0010, v0011, v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0010 = v0004;
// end of prologue
    v0075 = v0010;
    v0011 = qvalue(elt(env, 1)); // nil
    v0010 = elt(env, 2); // algebraic
    fn = elt(env, 5); // formbool
    v0010 = (*qfnn(fn))(qenv(fn), 3, v0075, v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    fn = elt(env, 6); // eval
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    if (v0010 == nil) goto v0067;
    v0010 = elt(env, 3); // true
    { popv(1); return onevalue(v0010); }

v0067:
    v0010 = elt(env, 4); // false
    { popv(1); return onevalue(v0010); }
// error exit handlers
v0016:
    popv(1);
    return nil;
}



// Code for min0

static LispObject CC_min0(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0058, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for min0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0058 = v0003;
    v0067 = v0004;
// end of prologue
    fn = elt(env, 1); // min
    v0067 = (*qfn2(fn))(qenv(fn), v0067, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[0];
    v0058 = (LispObject)1; // 0
    {
        popv(1);
        fn = elt(env, 2); // max
        return (*qfn2(fn))(qenv(fn), v0067, v0058);
    }
// error exit handlers
v0066:
    popv(1);
    return nil;
}



// Code for physoptimes

static LispObject CC_physoptimes(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0335, v0336;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physoptimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
// end of prologue
    stack[-2] = nil;
    v0336 = qvalue(elt(env, 1)); // tstack!*
    v0335 = (LispObject)1; // 0
    if (v0336 == v0335) goto v0058;
    v0335 = qvalue(elt(env, 3)); // nil
    goto v0092;

v0092:
    if (v0335 == nil) goto v0100;
    v0335 = qvalue(elt(env, 2)); // mul!*
    stack[-2] = v0335;
    v0335 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 2)) = v0335; // mul!*
    goto v0100;

v0100:
    v0335 = qvalue(elt(env, 1)); // tstack!*
    v0335 = add1(v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    qvalue(elt(env, 1)) = v0335; // tstack!*
    v0335 = stack[0];
    v0335 = qcar(v0335);
    fn = elt(env, 6); // physopsim!*
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-6] = v0335;
    v0335 = stack[0];
    v0335 = qcdr(v0335);
    stack[-1] = v0335;
    goto v0089;

v0089:
    v0335 = stack[-1];
    if (v0335 == nil) goto v0027;
    v0335 = stack[-1];
    v0335 = qcar(v0335);
    fn = elt(env, 6); // physopsim!*
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-5] = v0335;
    v0335 = stack[-6];
    fn = elt(env, 7); // getphystype
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-4] = v0335;
    v0335 = stack[-5];
    fn = elt(env, 7); // getphystype
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-3] = v0335;
    v0335 = stack[-4];
    if (v0335 == nil) goto v0087;
    v0335 = stack[-3];
    if (v0335 == nil) goto v0095;
    v0335 = stack[-6];
    fn = elt(env, 8); // physopaeval
    stack[0] = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    v0335 = stack[-5];
    fn = elt(env, 8); // physopaeval
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 9); // physopordchk
    v0335 = (*qfn2(fn))(qenv(fn), stack[0], v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    if (v0335 == nil) goto v0337;
    v0336 = stack[-4];
    v0335 = stack[-3];
    if (equal(v0336, v0335)) goto v0338;
    v0335 = qvalue(elt(env, 3)); // nil
    goto v0339;

v0339:
    if (v0335 == nil) goto v0337;
    v0335 = stack[-6];
    fn = elt(env, 10); // physop2sq
    stack[0] = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    v0335 = stack[-5];
    fn = elt(env, 10); // physop2sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 11); // multsq
    v0335 = (*qfn2(fn))(qenv(fn), stack[0], v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-6] = v0335;
    goto v0086;

v0086:
    v0335 = stack[-1];
    v0335 = qcdr(v0335);
    stack[-1] = v0335;
    goto v0089;

v0337:
    v0336 = stack[-6];
    v0335 = stack[-5];
    fn = elt(env, 13); // multopop!*
    v0335 = (*qfn2(fn))(qenv(fn), v0336, v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-6] = v0335;
    goto v0086;

v0338:
    v0336 = stack[-4];
    v0335 = elt(env, 4); // scalar
    v0335 = (v0336 == v0335 ? lisp_true : nil);
    goto v0339;

v0095:
    v0335 = stack[-5];
    v0335 = (LispObject)zerop(v0335);
    v0335 = v0335 ? lisp_true : nil;
    env = stack[-7];
    if (v0335 == nil) goto v0340;
    v0336 = qvalue(elt(env, 3)); // nil
    v0335 = (LispObject)17; // 1
    v0335 = cons(v0336, v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    goto v0341;

v0341:
    stack[-6] = v0335;
    goto v0086;

v0340:
    v0335 = stack[-5];
    v0335 = Lonep(nil, v0335);
    env = stack[-7];
    if (v0335 == nil) goto v0342;
    v0335 = stack[-6];
    fn = elt(env, 10); // physop2sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    goto v0341;

v0342:
    v0335 = stack[-5];
    fn = elt(env, 10); // physop2sq
    stack[0] = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    v0335 = stack[-6];
    fn = elt(env, 10); // physop2sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 11); // multsq
    v0335 = (*qfn2(fn))(qenv(fn), stack[0], v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    goto v0341;

v0087:
    v0335 = stack[-3];
    if (v0335 == nil) goto v0084;
    v0335 = stack[-6];
    v0335 = (LispObject)zerop(v0335);
    v0335 = v0335 ? lisp_true : nil;
    env = stack[-7];
    if (v0335 == nil) goto v0105;
    v0336 = qvalue(elt(env, 3)); // nil
    v0335 = (LispObject)17; // 1
    v0335 = cons(v0336, v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-6] = v0335;
    goto v0086;

v0105:
    v0335 = stack[-6];
    v0335 = Lonep(nil, v0335);
    env = stack[-7];
    if (v0335 == nil) goto v0288;
    v0335 = stack[-5];
    fn = elt(env, 10); // physop2sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-6] = v0335;
    goto v0086;

v0288:
    v0335 = stack[-6];
    fn = elt(env, 10); // physop2sq
    stack[0] = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    v0335 = stack[-5];
    fn = elt(env, 10); // physop2sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 11); // multsq
    v0335 = (*qfn2(fn))(qenv(fn), stack[0], v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-6] = v0335;
    goto v0086;

v0084:
    v0335 = stack[-6];
    fn = elt(env, 10); // physop2sq
    stack[0] = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    v0335 = stack[-5];
    fn = elt(env, 10); // physop2sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 11); // multsq
    v0335 = (*qfn2(fn))(qenv(fn), stack[0], v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0335 = (*qfn1(fn))(qenv(fn), v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-6] = v0335;
    goto v0086;

v0027:
    v0335 = qvalue(elt(env, 2)); // mul!*
    if (v0335 == nil) goto v0343;
    v0336 = qvalue(elt(env, 1)); // tstack!*
    v0335 = (LispObject)17; // 1
    v0335 = (LispObject)greaterp2(v0336, v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    v0335 = v0335 ? lisp_true : nil;
    env = stack[-7];
    goto v0269;

v0269:
    if (v0335 == nil) goto v0344;
    v0335 = qvalue(elt(env, 1)); // tstack!*
    v0335 = sub1(v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    qvalue(elt(env, 1)) = v0335; // tstack!*
    v0336 = qvalue(elt(env, 1)); // tstack!*
    v0335 = (LispObject)1; // 0
    if (!(v0336 == v0335)) { LispObject res = stack[-6]; popv(8); return onevalue(res); }
    v0335 = stack[-2];
    qvalue(elt(env, 2)) = v0335; // mul!*
    { LispObject res = stack[-6]; popv(8); return onevalue(res); }

v0344:
    v0335 = qvalue(elt(env, 2)); // mul!*
    v0336 = qcar(v0335);
    v0335 = stack[-6];
    v0335 = Lapply1(nil, v0336, v0335);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-7];
    stack[-6] = v0335;
    v0335 = qvalue(elt(env, 2)); // mul!*
    v0335 = qcdr(v0335);
    qvalue(elt(env, 2)) = v0335; // mul!*
    goto v0027;

v0343:
    v0335 = qvalue(elt(env, 5)); // t
    goto v0269;

v0058:
    v0335 = qvalue(elt(env, 2)); // mul!*
    goto v0092;
// error exit handlers
v0259:
    popv(8);
    return nil;
}



// Code for remchkf1

static LispObject CC_remchkf1(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0001, v0002, v0057;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remchkf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
// end of prologue
    v0001 = stack[-1];
    fn = elt(env, 4); // termsf
    v0001 = (*qfn1(fn))(qenv(fn), v0001);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[-2] = v0001;
    v0057 = stack[-1];
    v0002 = stack[0];
    v0001 = stack[-2];
    fn = elt(env, 5); // xremf
    v0001 = (*qfnn(fn))(qenv(fn), 3, v0057, v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[0] = v0001;
    v0001 = stack[0];
    if (v0001 == nil) goto v0120;
    v0001 = stack[0];
    v0001 = qcar(v0001);
    stack[0] = v0001;
    fn = elt(env, 4); // termsf
    v0002 = (*qfn1(fn))(qenv(fn), v0001);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0001 = stack[-2];
    v0001 = (LispObject)geq2(v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    v0001 = v0001 ? lisp_true : nil;
    env = stack[-3];
    goto v0016;

v0016:
    if (!(v0001 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0001 = qvalue(elt(env, 2)); // !*trcompact
    if (v0001 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0001 = elt(env, 3); // "*** Remainder smaller"
    fn = elt(env, 6); // prin2t
    v0001 = (*qfn1(fn))(qenv(fn), v0001);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0120:
    v0001 = qvalue(elt(env, 1)); // t
    goto v0016;
// error exit handlers
v0015:
    popv(4);
    return nil;
}



// Code for horner!-rule!-for!-one!-var

static LispObject CC_hornerKruleKforKoneKvar(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0349, v0350, v0342, v0351, v0352, v0353, v0308;
    LispObject fn;
    LispObject v0000, v0042, v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "horner-rule-for-one-var");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0042 = va_arg(aa, LispObject);
    v0000 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for horner-rule-for-one-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0000,v0042,v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0004,v0003,v0009,v0042,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    v0350 = v0000;
    v0342 = v0042;
    v0351 = v0009;
    v0352 = v0003;
    v0353 = v0004;
// end of prologue

v0354:
    v0349 = v0353;
    if (!consp(v0349)) goto v0073;
    v0349 = v0353;
    v0349 = qcar(v0349);
    v0349 = (consp(v0349) ? nil : lisp_true);
    goto v0101;

v0101:
    if (v0349 == nil) goto v0091;
    v0349 = qvalue(elt(env, 1)); // t
    goto v0022;

v0022:
    if (v0349 == nil) goto v0084;
    v0349 = v0351;
    v0349 = (LispObject)zerop(v0349);
    v0349 = v0349 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0349 == nil)) { popv(7); return onevalue(v0353); }
    stack[-1] = v0353;
    stack[0] = v0342;
    v0349 = v0351;
    v0349 = Lexpt(nil, v0349, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    fn = elt(env, 2); // !*n2f
    v0349 = (*qfn1(fn))(qenv(fn), v0349);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    fn = elt(env, 3); // multf
    v0349 = (*qfn2(fn))(qenv(fn), stack[0], v0349);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    {
        LispObject v0283 = stack[-1];
        popv(7);
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(qenv(fn), v0283, v0349);
    }

v0084:
    v0349 = v0353;
    v0349 = qcar(v0349);
    v0349 = qcar(v0349);
    v0349 = qcdr(v0349);
    stack[-5] = v0349;
    v0349 = v0353;
    stack[-4] = qcdr(v0349);
    stack[-3] = v0352;
    stack[-2] = v0351;
    v0349 = v0351;
    v0349 = (LispObject)zerop(v0349);
    v0349 = v0349 ? lisp_true : nil;
    env = stack[-6];
    if (v0349 == nil) goto v0114;
    v0349 = v0353;
    v0349 = qcar(v0349);
    v0349 = qcdr(v0349);
    v0350 = v0349;
    goto v0047;

v0047:
    v0349 = stack[-5];
    v0353 = stack[-4];
    v0352 = stack[-3];
    v0351 = stack[-2];
    v0342 = v0350;
    v0350 = v0349;
    goto v0354;

v0114:
    v0349 = v0353;
    v0349 = qcar(v0349);
    stack[-1] = qcdr(v0349);
    stack[0] = v0342;
    v0342 = v0351;
    v0349 = stack[-5];
    v0349 = (LispObject)(int32_t)((int32_t)v0350 - (int32_t)v0349 + TAG_FIXNUM);
    v0349 = Lexpt(nil, v0342, v0349);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    fn = elt(env, 2); // !*n2f
    v0349 = (*qfn1(fn))(qenv(fn), v0349);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    fn = elt(env, 3); // multf
    v0349 = (*qfn2(fn))(qenv(fn), stack[0], v0349);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    fn = elt(env, 4); // addf
    v0349 = (*qfn2(fn))(qenv(fn), stack[-1], v0349);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    v0350 = v0349;
    goto v0047;

v0091:
    v0349 = v0353;
    v0349 = qcar(v0349);
    v0349 = qcar(v0349);
    v0308 = qcar(v0349);
    v0349 = v0352;
    v0349 = (equal(v0308, v0349) ? lisp_true : nil);
    v0349 = (v0349 == nil ? lisp_true : nil);
    goto v0022;

v0073:
    v0349 = qvalue(elt(env, 1)); // t
    goto v0101;
// error exit handlers
v0285:
    popv(7);
    return nil;
}



// Code for drnconv

static LispObject CC_drnconv(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0012, v0013, v0086;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for drnconv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0013 = v0004;
// end of prologue
    v0012 = v0013;
    if (v0012 == nil) goto v0028;
    v0012 = v0013;
    v0012 = (is_number(v0012) ? lisp_true : nil);
    if (!(v0012 == nil)) goto v0014;
    v0086 = v0013;
    v0012 = qvalue(elt(env, 2)); // dmd!*
    v0012 = Leqcar(nil, v0086, v0012);
    env = stack[0];
    goto v0014;

v0014:
    if (!(v0012 == nil)) { popv(1); return onevalue(v0013); }
    v0012 = v0013;
    v0086 = qcar(v0012);
    v0012 = qvalue(elt(env, 2)); // dmd!*
    v0012 = get(v0086, v0012);
    v0086 = v0012;
    v0012 = v0086;
    if (v0012 == nil) { popv(1); return onevalue(v0013); }
    v0012 = v0086;
    if (!(!consp(v0012))) { popv(1); return onevalue(v0013); }
    v0012 = v0086;
        popv(1);
        return Lapply1(nil, v0012, v0013);

v0028:
    v0012 = qvalue(elt(env, 1)); // t
    goto v0014;
}



// Code for order_of_der_mind

static LispObject CC_order_of_der_mind(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0040;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for order_of_der_mind");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0040 = v0004;
// end of prologue
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    {
        fn = elt(env, 1); // length_multiindex
        return (*qfn1(fn))(qenv(fn), v0040);
    }
}



// Code for even_action_sf

static LispObject CC_even_action_sf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0013, v0086, v0087, v0109;
    LispObject fn;
    LispObject v0042, v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_sf");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0042 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for even_action_sf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0042,v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0004,v0003,v0009,v0042);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0042;
    stack[-1] = v0009;
    stack[-2] = v0003;
    stack[-3] = v0004;
// end of prologue
    v0086 = qvalue(elt(env, 1)); // nil
    v0013 = (LispObject)17; // 1
    v0013 = cons(v0086, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-5];
    v0086 = v0013;
    goto v0058;

v0058:
    v0013 = stack[-2];
    if (!consp(v0013)) goto v0016;
    v0013 = stack[-2];
    v0013 = qcar(v0013);
    v0013 = (consp(v0013) ? nil : lisp_true);
    goto v0075;

v0075:
    if (!(v0013 == nil)) { popv(6); return onevalue(v0086); }
    stack[-4] = v0086;
    v0109 = stack[-3];
    v0013 = stack[-2];
    v0087 = qcar(v0013);
    v0086 = stack[-1];
    v0013 = stack[0];
    fn = elt(env, 3); // even_action_term
    v0013 = (*qfnn(fn))(qenv(fn), 4, v0109, v0087, v0086, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-5];
    fn = elt(env, 4); // addsq
    v0013 = (*qfn2(fn))(qenv(fn), stack[-4], v0013);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-5];
    v0086 = v0013;
    v0013 = stack[-2];
    v0013 = qcdr(v0013);
    stack[-2] = v0013;
    goto v0058;

v0016:
    v0013 = qvalue(elt(env, 2)); // t
    goto v0075;
// error exit handlers
v0291:
    popv(6);
    return nil;
}



// Code for rl_fvarl

static LispObject CC_rl_fvarl(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0022;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_fvarl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0022 = v0004;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_fvarl!*
    v0022 = ncons(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    {
        LispObject v0119 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0119, v0022);
    }
// error exit handlers
v0100:
    popv(2);
    return nil;
}



// Code for pasf_smordtable1

static LispObject CC_pasf_smordtable1(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0011, v0075, v0016;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smordtable1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0011 = v0003;
    v0075 = v0004;
// end of prologue
    v0016 = elt(env, 1); // ((lessp (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (leq (lessp 1) (leq 1)
// (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (equal (lessp 1) (leq 1) (equal false) (neq 1)
// (geq false) (greaterp false) (cong nil) (ncong nil)) (neq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2)
// (cong nil) (ncong nil)) (geq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)) (greaterp
// (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)))
    v0075 = Latsoc(nil, v0075, v0016);
    v0011 = Latsoc(nil, v0011, v0075);
    v0011 = qcdr(v0011);
    return onevalue(v0011);
}



// Code for symbolsom

static LispObject CC_symbolsom(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0351, v0352, v0353;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbolsom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0004;
// end of prologue
    stack[-1] = nil;
    v0351 = stack[-4];
    v0352 = qcar(v0351);
    v0351 = qvalue(elt(env, 1)); // valid_om!*
    v0351 = Lassoc(nil, v0352, v0351);
    stack[-5] = v0351;
    v0351 = stack[-5];
    if (v0351 == nil) goto v0067;
    v0351 = stack[-5];
    v0351 = qcdr(v0351);
    v0351 = qcar(v0351);
    stack[-5] = v0351;
    goto v0067;

v0067:
    v0351 = stack[-4];
    v0351 = qcar(v0351);
    stack[0] = v0351;
    v0351 = stack[-4];
    v0351 = qcdr(v0351);
    v0351 = qcdr(v0351);
    v0351 = qcar(v0351);
    stack[-3] = v0351;
    v0351 = stack[-4];
    v0351 = Lreverse(nil, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = qcar(v0351);
    stack[-2] = v0351;
    v0352 = stack[0];
    v0351 = elt(env, 2); // diff
    if (v0352 == v0351) goto v0111;
    v0351 = stack[-4];
    v0351 = qcdr(v0351);
    v0351 = qcdr(v0351);
    v0351 = qcdr(v0351);
    v0351 = qcar(v0351);
    stack[-1] = v0351;
    goto v0111;

v0111:
    v0351 = stack[-1];
    if (v0351 == nil) goto v0055;
    v0351 = stack[-1];
    v0352 = qcar(v0351);
    v0351 = elt(env, 3); // condition
    if (!(v0352 == v0351)) goto v0055;
    v0352 = elt(env, 4); // "<condition> tag not supported in MathML"
    v0351 = (LispObject)17; // 1
    fn = elt(env, 15); // errorml
    v0351 = (*qfn2(fn))(qenv(fn), v0352, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    goto v0055;

v0055:
    v0351 = elt(env, 5); // "<OMA>"
    fn = elt(env, 16); // printout
    v0351 = (*qfn1(fn))(qenv(fn), v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = qvalue(elt(env, 6)); // t
    fn = elt(env, 17); // indent!*
    v0351 = (*qfn1(fn))(qenv(fn), v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = stack[-1];
    if (v0351 == nil) goto v0348;
    v0352 = stack[0];
    v0351 = elt(env, 7); // int
    v0351 = (v0352 == v0351 ? lisp_true : nil);
    goto v0117;

v0117:
    if (v0351 == nil) goto v0357;
    v0351 = elt(env, 9); // defint
    stack[0] = v0351;
    goto v0357;

v0357:
    v0351 = elt(env, 10); // "<OMS cd="""
    fn = elt(env, 16); // printout
    v0351 = (*qfn1(fn))(qenv(fn), v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = stack[-5];
    v0351 = Lprinc(nil, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = elt(env, 11); // """ name="""
    v0351 = Lprinc(nil, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = stack[0];
    v0351 = Lprinc(nil, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = elt(env, 12); // """/>"
    v0351 = Lprinc(nil, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = stack[-1];
    if (v0351 == nil) goto v0340;
    v0351 = stack[-1];
    fn = elt(env, 18); // objectom
    v0351 = (*qfn1(fn))(qenv(fn), v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    goto v0340;

v0340:
    stack[-1] = elt(env, 13); // lambda
    stack[0] = qvalue(elt(env, 8)); // nil
    v0353 = stack[-3];
    v0352 = stack[-2];
    v0351 = qvalue(elt(env, 8)); // nil
    v0351 = list2star(v0353, v0352, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = list2star(stack[-1], stack[0], v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    fn = elt(env, 19); // lambdaom
    v0351 = (*qfn1(fn))(qenv(fn), v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 17); // indent!*
    v0351 = (*qfn1(fn))(qenv(fn), v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-6];
    v0351 = elt(env, 14); // "</OMA>"
    fn = elt(env, 16); // printout
    v0351 = (*qfn1(fn))(qenv(fn), v0351);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    v0351 = nil;
    { popv(7); return onevalue(v0351); }

v0348:
    v0351 = qvalue(elt(env, 8)); // nil
    goto v0117;
// error exit handlers
v0356:
    popv(7);
    return nil;
}



// Code for close_forall

static LispObject CC_close_forall(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0073, v0092;
    LispObject fn;
    argcheck(nargs, 0, "close_forall");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for close_forall");
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
// end of prologue
    v0092 = qvalue(elt(env, 1)); // flagg
    v0073 = (LispObject)17; // 1
    if (!(v0092 == v0073)) goto v0000;
    v0073 = elt(env, 2); // "</apply>"
    fn = elt(env, 3); // printout
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    errexit();
    goto v0000;

v0000:
    v0073 = nil;
    return onevalue(v0073);
}



// Code for sparpri

static LispObject CC_sparpri(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0085, v0084, v0243;
    LispObject fn;
    LispObject v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sparpri");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sparpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0004,v0003,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0009;
    v0085 = v0003;
    v0084 = v0004;
// end of prologue
    stack[-5] = v0085;
    v0085 = v0084;
    stack[-3] = v0085;
    goto v0100;

v0100:
    v0085 = stack[-3];
    if (v0085 == nil) goto v0096;
    v0085 = stack[-3];
    v0085 = qcar(v0085);
    stack[-2] = v0085;
    stack[-1] = elt(env, 2); // quote
    stack[0] = elt(env, 3); // setq
    v0243 = stack[-4];
    v0084 = stack[-5];
    v0085 = stack[-2];
    v0085 = qcar(v0085);
    v0084 = list3(v0243, v0084, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-6];
    v0085 = stack[-2];
    v0085 = qcdr(v0085);
    v0085 = list3(stack[0], v0084, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-6];
    v0084 = list2(stack[-1], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-6];
    v0085 = elt(env, 4); // first
    fn = elt(env, 7); // writepri
    v0085 = (*qfn2(fn))(qenv(fn), v0084, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-6];
    v0084 = elt(env, 5); // (quote !$)
    v0085 = elt(env, 6); // last
    fn = elt(env, 7); // writepri
    v0085 = (*qfn2(fn))(qenv(fn), v0084, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-6];
    v0085 = stack[-3];
    v0085 = qcdr(v0085);
    stack[-3] = v0085;
    goto v0100;

v0096:
    v0085 = nil;
    { popv(7); return onevalue(v0085); }
// error exit handlers
v0317:
    popv(7);
    return nil;
}



// Code for sc_mkmatrix

static LispObject CC_sc_mkmatrix(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0105, v0118, v0355;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_mkmatrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0003;
    stack[-6] = v0004;
// end of prologue
    v0105 = stack[-6];
    v0105 = sub1(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    v0105 = Lmkvect(nil, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    stack[-7] = v0105;
    v0105 = (LispObject)1; // 0
    stack[-3] = v0105;
    goto v0079;

v0079:
    v0105 = stack[-6];
    v0118 = sub1(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    v0105 = stack[-3];
    v0105 = difference2(v0118, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    v0105 = Lminusp(nil, v0105);
    env = stack[-8];
    if (!(v0105 == nil)) { LispObject res = stack[-7]; popv(9); return onevalue(res); }
    v0105 = stack[-5];
    v0105 = sub1(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    v0105 = Lmkvect(nil, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    stack[-4] = v0105;
    v0105 = (LispObject)1; // 0
    stack[-2] = v0105;
    goto v0081;

v0081:
    v0105 = stack[-5];
    v0118 = sub1(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    v0105 = stack[-2];
    v0105 = difference2(v0118, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    v0105 = Lminusp(nil, v0105);
    env = stack[-8];
    if (v0105 == nil) goto v0054;
    v0355 = stack[-7];
    v0118 = stack[-3];
    v0105 = stack[-4];
    fn = elt(env, 2); // sc_iputv
    v0105 = (*qfnn(fn))(qenv(fn), 3, v0355, v0118, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    v0105 = stack[-3];
    v0105 = add1(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    stack[-3] = v0105;
    goto v0079;

v0054:
    stack[-1] = stack[-4];
    stack[0] = stack[-2];
    v0105 = (LispObject)1; // 0
    fn = elt(env, 3); // sc_simp
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    fn = elt(env, 2); // sc_iputv
    v0105 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    v0105 = stack[-2];
    v0105 = add1(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-8];
    stack[-2] = v0105;
    goto v0081;
// error exit handlers
v0046:
    popv(9);
    return nil;
}



// Code for string2bytelist

static LispObject CC_string2bytelist(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for string2bytelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0055 = v0004;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 1); // string2list
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    stack[0] = v0055;
    goto v0040;

v0040:
    v0055 = stack[0];
    if (v0055 == nil) goto v0022;
    v0055 = stack[0];
    v0055 = qcar(v0055);
    v0055 = Lminusp(nil, v0055);
    env = stack[-2];
    if (v0055 == nil) goto v0089;
    v0056 = (LispObject)4097; // 256
    v0055 = stack[0];
    v0055 = qcar(v0055);
    v0056 = plus2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0055 = stack[-1];
    v0055 = cons(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    stack[-1] = v0055;
    goto v0092;

v0092:
    v0055 = stack[0];
    v0055 = qcdr(v0055);
    stack[0] = v0055;
    goto v0040;

v0089:
    v0055 = stack[0];
    v0056 = qcar(v0055);
    v0055 = stack[-1];
    v0055 = cons(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    stack[-1] = v0055;
    goto v0092;

v0022:
    v0055 = stack[-1];
        popv(3);
        return Lnreverse(nil, v0055);
// error exit handlers
v0053:
    popv(3);
    return nil;
}



// Code for sublap

static LispObject CC_sublap(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0047, v0048;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sublap");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
// end of prologue
    v0047 = stack[-1];
    if (v0047 == nil) goto v0096;
    v0047 = stack[0];
    v0047 = (v0047 == nil ? lisp_true : nil);
    goto v0022;

v0022:
    if (!(v0047 == nil)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0047 = stack[0];
    if (!consp(v0047)) goto v0079;
    v0047 = stack[0];
    v0048 = qcar(v0047);
    v0047 = elt(env, 2); // app
    v0047 = Lflagp(nil, v0048, v0047);
    env = stack[-3];
    if (v0047 == nil) goto v0243;
    v0048 = stack[-1];
    v0047 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); // sublap1
        return (*qfn2(fn))(qenv(fn), v0048, v0047);
    }

v0243:
    v0048 = stack[-1];
    v0047 = stack[0];
    v0047 = qcar(v0047);
    stack[-2] = CC_sublap(env, v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-3];
    v0048 = stack[-1];
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    v0047 = CC_sublap(env, v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    {
        LispObject v0070 = stack[-2];
        popv(4);
        return cons(v0070, v0047);
    }

v0079:
    v0047 = stack[0];
    if (is_number(v0047)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0048 = stack[0];
    v0047 = stack[-1];
    v0047 = Latsoc(nil, v0048, v0047);
    v0048 = v0047;
    if (v0047 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0047 = v0048;
    v0047 = qcdr(v0047);
    { popv(4); return onevalue(v0047); }

v0096:
    v0047 = qvalue(elt(env, 1)); // t
    goto v0022;
// error exit handlers
v0307:
    popv(4);
    return nil;
}



// Code for prop!-simp1

static LispObject CC_propKsimp1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0341, v0098, v0340;
    LispObject fn;
    LispObject v0000, v0042, v0009, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "prop-simp1");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0042 = va_arg(aa, LispObject);
    v0000 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prop-simp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0000,v0042,v0009,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0004,v0003,v0009,v0042,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0000;
    stack[0] = v0042;
    stack[-5] = v0009;
    stack[-2] = v0003;
    stack[-6] = v0004;
// end of prologue

v0354:
    v0341 = stack[-2];
    if (v0341 == nil) goto v0066;
    v0098 = stack[-6];
    v0341 = stack[-2];
    v0341 = qcar(v0341);
    fn = elt(env, 1); // prop!-simp2
    v0341 = (*qfn2(fn))(qenv(fn), v0098, v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-8];
    stack[-3] = v0341;
    v0341 = stack[-3];
    if (v0341 == nil) goto v0311;
    v0341 = stack[-3];
    stack[-6] = qcdr(v0341);
    v0341 = stack[-2];
    stack[-2] = qcdr(v0341);
    stack[-1] = stack[-5];
    v0341 = stack[0];
    stack[0] = add1(v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-8];
    v0341 = stack[-3];
    stack[-7] = qcar(v0341);
    stack[-3] = (LispObject)-15; // -1
    v0341 = stack[-5];
    v0341 = Llength(nil, v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-8];
    v0341 = Lexpt(nil, stack[-3], v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-8];
    v0341 = times2(stack[-4], v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-8];
    v0341 = times2(stack[-7], v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-8];
    stack[-5] = stack[-1];
    stack[-4] = v0341;
    goto v0354;

v0311:
    stack[-3] = stack[-6];
    v0341 = stack[-2];
    stack[-1] = qcdr(v0341);
    v0341 = stack[-2];
    v0098 = qcar(v0341);
    v0341 = stack[-5];
    v0340 = cons(v0098, v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-8];
    v0098 = stack[0];
    v0341 = stack[-4];
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v0340;
    stack[0] = v0098;
    stack[-4] = v0341;
    goto v0354;

v0066:
    v0098 = stack[0];
    v0341 = stack[-4];
    stack[0] = list2(v0098, v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-8];
    stack[-1] = stack[-6];
    v0341 = stack[-5];
    v0341 = Lreverse(nil, v0341);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    {
        LispObject v0331 = stack[0];
        LispObject v0332 = stack[-1];
        popv(9);
        return list2star(v0331, v0332, v0341);
    }
// error exit handlers
v0034:
    popv(9);
    return nil;
}



// Code for no!-side!-effectp

static LispObject CC_noKsideKeffectp(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0053, v0318;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for no-side-effectp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0004;
// end of prologue
    v0053 = stack[0];
    if (!consp(v0053)) goto v0000;
    v0053 = stack[0];
    v0318 = qcar(v0053);
    v0053 = elt(env, 2); // quote
    if (v0318 == v0053) goto v0091;
    v0053 = stack[0];
    v0318 = qcar(v0053);
    v0053 = elt(env, 4); // nosideeffects
    v0053 = Lflagp(nil, v0318, v0053);
    env = stack[-1];
    if (v0053 == nil) goto v0056;
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    {
        popv(2);
        fn = elt(env, 5); // no!-side!-effect!-listp
        return (*qfn1(fn))(qenv(fn), v0053);
    }

v0056:
    v0053 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0053); }

v0091:
    v0053 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0053); }

v0000:
    v0053 = stack[0];
    v0053 = (is_number(v0053) ? lisp_true : nil);
    if (!(v0053 == nil)) { popv(2); return onevalue(v0053); }
    v0053 = stack[0];
    if (symbolp(v0053)) goto v0058;
    v0053 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0053); }

v0058:
    v0053 = stack[0];
    v0053 = Lsymbol_specialp(nil, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-1];
    if (!(v0053 == nil)) goto v0079;
    v0053 = stack[0];
    v0053 = Lsymbol_globalp(nil, v0053);
    goto v0079;

v0079:
    v0053 = (v0053 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0053); }
// error exit handlers
v0012:
    popv(2);
    return nil;
}



// Code for !*!*a2i

static LispObject CC_HHa2i(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0120, v0090;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for **a2i");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0120 = v0003;
    stack[0] = v0004;
// end of prologue
    v0090 = stack[0];
    fn = elt(env, 2); // intexprnp
    v0120 = (*qfn2(fn))(qenv(fn), v0090, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    if (!(v0120 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0090 = elt(env, 1); // ieval
    v0120 = stack[0];
    popv(2);
    return list2(v0090, v0120);
// error exit handlers
v0104:
    popv(2);
    return nil;
}



// Code for groeb!=crita

static LispObject CC_groebMcrita(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0027, v0022;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=crita");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0027 = v0004;
// end of prologue
    v0022 = v0027;
    v0027 = elt(env, 1); // groeb!=testa
    {
        fn = elt(env, 2); // listminimize
        return (*qfn2(fn))(qenv(fn), v0022, v0027);
    }
}



// Code for gvar1

static LispObject CC_gvar1(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0037, v0035, v0036, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gvar1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0033 = v0003;
    v0036 = v0004;
// end of prologue

v0041:
    v0037 = v0036;
    if (v0037 == nil) goto v0096;
    v0037 = v0036;
    v0037 = (is_number(v0037) ? lisp_true : nil);
    if (!(v0037 == nil)) goto v0022;
    v0035 = v0036;
    v0037 = elt(env, 2); // i
    if (v0035 == v0037) goto v0016;
    v0037 = qvalue(elt(env, 4)); // nil
    goto v0022;

v0022:
    if (!(v0037 == nil)) return onevalue(v0033);
    v0037 = v0036;
    if (!consp(v0037)) goto v0103;
    v0037 = v0036;
    v0037 = qcar(v0037);
    if (!symbolp(v0037)) v0037 = nil;
    else { v0037 = qfastgets(v0037);
           if (v0037 != nil) { v0037 = elt(v0037, 8); // dname
#ifdef RECORD_GET
             if (v0037 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0037 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0037 == SPID_NOPROP) v0037 = nil; }}
#endif
    if (!(v0037 == nil)) return onevalue(v0033);
    v0037 = v0036;
    v0035 = qcar(v0037);
    v0037 = elt(env, 5); // (plus times expt difference minus)
    v0037 = Lmemq(nil, v0035, v0037);
    if (v0037 == nil) goto v0046;
    v0037 = v0036;
    v0037 = qcdr(v0037);
    v0035 = v0033;
    {
        fn = elt(env, 7); // gvarlis1
        return (*qfn2(fn))(qenv(fn), v0037, v0035);
    }

v0046:
    v0037 = v0036;
    v0035 = qcar(v0037);
    v0037 = elt(env, 6); // quotient
    if (v0035 == v0037) goto v0048;
    v0035 = v0036;
    v0037 = v0033;
    v0037 = Lmember(nil, v0035, v0037);
    if (!(v0037 == nil)) return onevalue(v0033);
    v0037 = v0036;
    v0035 = v0033;
    return cons(v0037, v0035);

v0048:
    v0037 = v0036;
    v0037 = qcdr(v0037);
    v0037 = qcar(v0037);
    v0036 = v0037;
    goto v0041;

v0103:
    v0035 = v0036;
    v0037 = v0033;
    v0037 = Lmember(nil, v0035, v0037);
    if (!(v0037 == nil)) return onevalue(v0033);
    v0037 = v0036;
    v0035 = v0033;
    return cons(v0037, v0035);

v0016:
    v0037 = qvalue(elt(env, 3)); // !*complex
    goto v0022;

v0096:
    v0037 = qvalue(elt(env, 1)); // t
    goto v0022;
}



// Code for multivariatep

static LispObject CC_multivariatep(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multivariatep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
// end of prologue

v0041:
    v0055 = stack[-1];
    if (!consp(v0055)) goto v0096;
    v0055 = stack[-1];
    v0055 = qcar(v0055);
    v0055 = (consp(v0055) ? nil : lisp_true);
    goto v0022;

v0022:
    if (v0055 == nil) goto v0075;
    v0055 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0055); }

v0075:
    v0055 = stack[-1];
    v0055 = qcar(v0055);
    v0055 = qcar(v0055);
    v0056 = qcar(v0055);
    v0055 = stack[0];
    if (v0056 == v0055) goto v0110;
    v0055 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0055); }

v0110:
    v0055 = stack[-1];
    v0055 = qcar(v0055);
    v0056 = qcdr(v0055);
    v0055 = stack[0];
    v0055 = CC_multivariatep(env, v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    if (v0055 == nil) goto v0311;
    v0055 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0055); }

v0311:
    v0055 = stack[-1];
    v0055 = qcdr(v0055);
    stack[-1] = v0055;
    goto v0041;

v0096:
    v0055 = qvalue(elt(env, 1)); // t
    goto v0022;
// error exit handlers
v0053:
    popv(3);
    return nil;
}



// Code for dvfsf_v

static LispObject CC_dvfsf_v(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0075, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_v");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0075 = v0004;
// end of prologue
    v0016 = v0075;
    v0075 = qvalue(elt(env, 1)); // dvfsf_p!*
    fn = elt(env, 2); // qremf
    v0075 = (*qfn2(fn))(qenv(fn), v0016, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[0];
    v0016 = v0075;
    v0075 = v0016;
    v0075 = qcdr(v0075);
    if (v0075 == nil) goto v0100;
    v0075 = (LispObject)1; // 0
    { popv(1); return onevalue(v0075); }

v0100:
    v0075 = v0016;
    v0075 = qcar(v0075);
    v0075 = CC_dvfsf_v(env, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    popv(1);
    return add1(v0075);
// error exit handlers
v0120:
    popv(1);
    return nil;
}



// Code for cl_rename!-vars

static LispObject CC_cl_renameKvars(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0096;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_rename-vars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0096 = v0004;
// end of prologue
    stack[0] = v0096;
    fn = elt(env, 1); // cl_replace!-varl
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-1];
    fn = elt(env, 2); // cl_rename!-vars1
    v0096 = (*qfn2(fn))(qenv(fn), stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    v0096 = qcar(v0096);
    { popv(2); return onevalue(v0096); }
// error exit handlers
v0119:
    popv(2);
    return nil;
}



// Code for sfto_lmultf

static LispObject CC_sfto_lmultf(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0080, v0081;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_lmultf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
// end of prologue
    stack[-1] = nil;
    goto v0040;

v0040:
    v0080 = stack[0];
    if (v0080 == nil) goto v0014;
    v0080 = stack[0];
    v0081 = qcar(v0080);
    v0080 = stack[-1];
    v0080 = cons(v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    stack[-1] = v0080;
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    stack[0] = v0080;
    goto v0040;

v0014:
    v0080 = (LispObject)17; // 1
    v0081 = v0080;
    goto v0028;

v0028:
    v0080 = stack[-1];
    if (v0080 == nil) { popv(3); return onevalue(v0081); }
    v0080 = stack[-1];
    v0080 = qcar(v0080);
    fn = elt(env, 1); // multf
    v0080 = (*qfn2(fn))(qenv(fn), v0080, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    v0081 = v0080;
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    stack[-1] = v0080;
    goto v0028;
// error exit handlers
v0082:
    popv(3);
    return nil;
}



// Code for give!*position

static LispObject CC_giveHposition(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0018, v0052;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for give*position");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0003;
    stack[-3] = v0004;
// end of prologue
    v0018 = (LispObject)17; // 1
    stack[-4] = v0018;
    v0018 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0018;
    goto v0022;

v0022:
    v0018 = stack[-1];
    if (v0018 == nil) goto v0010;
    v0018 = qvalue(elt(env, 1)); // nil
    goto v0092;

v0092:
    if (v0018 == nil) goto v0027;
    v0052 = stack[-2];
    v0018 = stack[-4];
    fn = elt(env, 4); // nth
    v0052 = (*qfn2(fn))(qenv(fn), v0052, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-5];
    v0018 = stack[-3];
    if (equal(v0052, v0018)) goto v0111;
    v0018 = stack[-4];
    v0018 = add1(v0018);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-5];
    stack[-4] = v0018;
    goto v0022;

v0111:
    v0018 = qvalue(elt(env, 2)); // t
    stack[-1] = v0018;
    goto v0022;

v0027:
    v0018 = stack[-1];
    if (!(v0018 == nil)) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0018 = elt(env, 3); // "error in give position"
    fn = elt(env, 5); // rederr
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    { LispObject res = stack[-4]; popv(6); return onevalue(res); }

v0010:
    stack[0] = stack[-4];
    v0018 = stack[-2];
    v0018 = Llength(nil, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-5];
    v0018 = (LispObject)lesseq2(stack[0], v0018);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    v0018 = v0018 ? lisp_true : nil;
    env = stack[-5];
    goto v0092;
// error exit handlers
v0243:
    popv(6);
    return nil;
}



// Code for mconv1

static LispObject CC_mconv1(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0002, v0057;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mconv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0004;
// end of prologue
    stack[-2] = nil;
    goto v0041;

v0041:
    v0002 = stack[-1];
    if (!consp(v0002)) goto v0096;
    v0002 = stack[-1];
    v0002 = qcar(v0002);
    v0002 = (consp(v0002) ? nil : lisp_true);
    goto v0022;

v0022:
    if (v0002 == nil) goto v0074;
    stack[0] = stack[-2];
    v0002 = stack[-1];
    fn = elt(env, 2); // drnconv
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    {
        LispObject v0053 = stack[0];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0053, v0002);
    }

v0074:
    v0002 = stack[-1];
    v0002 = qcar(v0002);
    stack[0] = qcar(v0002);
    v0002 = stack[-1];
    v0002 = qcar(v0002);
    v0002 = qcdr(v0002);
    v0057 = CC_mconv1(env, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0002 = stack[-2];
    v0002 = acons(stack[0], v0057, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[-2] = v0002;
    v0002 = stack[-1];
    v0002 = qcdr(v0002);
    stack[-1] = v0002;
    goto v0041;

v0096:
    v0002 = qvalue(elt(env, 1)); // t
    goto v0022;
// error exit handlers
v0015:
    popv(4);
    return nil;
}



// Code for pasf_uprap

static LispObject CC_pasf_uprap(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0027, v0022;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_uprap");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0027 = v0004;
// end of prologue
    v0022 = v0027;
    v0027 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // pasf_uprap1
        return (*qfn2(fn))(qenv(fn), v0022, v0027);
    }
}



// Code for vdp_setsugar

static LispObject CC_vdp_setsugar(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0010, v0011, v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_setsugar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0010 = v0003;
    v0075 = v0004;
// end of prologue
    v0011 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v0011 == nil) return onevalue(v0075);
    v0011 = elt(env, 2); // sugar
    {
        fn = elt(env, 3); // vdp_putprop
        return (*qfnn(fn))(qenv(fn), 3, v0075, v0011, v0010);
    }
}



// Code for sfto_b!:extadd

static LispObject CC_sfto_bTextadd(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0255, v0257, v0244;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_b:extadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0003;
    stack[-2] = v0004;
// end of prologue
    stack[0] = nil;
    goto v0040;

v0040:
    v0255 = stack[-2];
    if (v0255 == nil) goto v0100;
    v0255 = stack[-1];
    if (v0255 == nil) goto v0075;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0257 = qcar(v0255);
    v0255 = stack[-1];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    if (equal(v0257, v0255)) goto v0102;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0257 = qcar(v0255);
    v0255 = stack[-1];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    fn = elt(env, 1); // sfto_b!:ordexp
    v0255 = (*qfn2(fn))(qenv(fn), v0257, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    env = stack[-4];
    if (v0255 == nil) goto v0039;
    v0255 = stack[-2];
    v0257 = qcar(v0255);
    v0255 = stack[0];
    v0255 = cons(v0257, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    env = stack[-4];
    stack[0] = v0255;
    v0255 = stack[-2];
    v0255 = qcdr(v0255);
    stack[-2] = v0255;
    goto v0040;

v0039:
    v0255 = stack[-1];
    v0257 = qcar(v0255);
    v0255 = stack[0];
    v0255 = cons(v0257, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    env = stack[-4];
    stack[0] = v0255;
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    stack[-1] = v0255;
    goto v0040;

v0102:
    stack[-3] = stack[0];
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0257 = qcdr(v0255);
    v0255 = stack[-1];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    fn = elt(env, 2); // addf
    stack[0] = (*qfn2(fn))(qenv(fn), v0257, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    env = stack[-4];
    v0255 = stack[-2];
    v0257 = qcdr(v0255);
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    v0255 = CC_sfto_bTextadd(env, v0257, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    env = stack[-4];
    v0257 = stack[0];
    v0244 = v0257;
    if (v0244 == nil) goto v0311;
    v0244 = stack[-2];
    v0244 = qcar(v0244);
    v0244 = qcar(v0244);
    v0255 = acons(v0244, v0257, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0349;
    env = stack[-4];
    goto v0311;

v0311:
    {
        LispObject v0350 = stack[-3];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0350, v0255);
    }

v0075:
    v0257 = stack[0];
    v0255 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0257, v0255);
    }

v0100:
    v0257 = stack[0];
    v0255 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0257, v0255);
    }
// error exit handlers
v0349:
    popv(5);
    return nil;
}



// Code for ciml

static LispObject CC_ciml(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0008, v0078;
    LispObject fn;
    argcheck(nargs, 0, "ciml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ciml");
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
    v0078 = qvalue(elt(env, 2)); // atts
    v0008 = elt(env, 3); // (t y p e)
    fn = elt(env, 5); // search_att
    v0008 = (*qfn2(fn))(qenv(fn), v0078, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    fn = elt(env, 6); // lex
    v0008 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    v0008 = qvalue(elt(env, 4)); // char
    stack[0] = v0008;
    fn = elt(env, 6); // lex
    v0008 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    v0008 = stack[0];
    v0008 = Lcompress(nil, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    stack[0] = v0008;
    v0008 = stack[0];
    if (!(is_number(v0008))) goto v0075;
    v0078 = stack[0];
    v0008 = (LispObject)65; // 4
    fn = elt(env, 7); // errorml
    v0008 = (*qfn2(fn))(qenv(fn), v0078, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    goto v0075;

v0075:
    v0008 = stack[0];
        popv(2);
        return Lintern(nil, v0008);
// error exit handlers
v0089:
    popv(2);
    return nil;
}



// Code for matrixp

static LispObject CC_matrixp(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0058, v0067;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0058 = v0004;
// end of prologue
    v0067 = v0058;
    v0058 = elt(env, 1); // mat
    if (!consp(v0067)) goto v0000;
    v0067 = qcar(v0067);
    if (!(v0067 == v0058)) goto v0000;
    v0058 = qvalue(elt(env, 3)); // t
    return onevalue(v0058);

v0000:
    v0058 = qvalue(elt(env, 2)); // nil
    return onevalue(v0058);
}



// Code for exdff0

static LispObject CC_exdff0(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0288, v0360;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exdff0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0004;
// end of prologue
    stack[-3] = nil;
    goto v0040;

v0040:
    v0288 = stack[-2];
    if (!consp(v0288)) goto v0101;
    v0288 = stack[-2];
    v0288 = qcar(v0288);
    v0288 = (consp(v0288) ? nil : lisp_true);
    goto v0119;

v0119:
    if (v0288 == nil) goto v0002;
    v0288 = qvalue(elt(env, 2)); // nil
    v0360 = v0288;
    goto v0028;

v0028:
    v0288 = stack[-3];
    if (v0288 == nil) { popv(5); return onevalue(v0360); }
    v0288 = stack[-3];
    v0288 = qcar(v0288);
    fn = elt(env, 3); // addpf
    v0288 = (*qfn2(fn))(qenv(fn), v0288, v0360);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0360 = v0288;
    v0288 = stack[-3];
    v0288 = qcdr(v0288);
    stack[-3] = v0288;
    goto v0028;

v0002:
    v0288 = stack[-2];
    v0288 = qcar(v0288);
    v0360 = qcar(v0288);
    v0288 = (LispObject)17; // 1
    v0288 = cons(v0360, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0360 = ncons(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0288 = (LispObject)17; // 1
    stack[0] = cons(v0360, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0288 = stack[-2];
    v0288 = qcar(v0288);
    v0288 = qcdr(v0288);
    v0288 = CC_exdff0(env, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    fn = elt(env, 4); // multsqpf
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0288 = stack[-2];
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    fn = elt(env, 5); // exdfp0
    stack[0] = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0288 = stack[-2];
    v0288 = qcar(v0288);
    v0360 = qcdr(v0288);
    v0288 = (LispObject)17; // 1
    v0288 = cons(v0360, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    fn = elt(env, 6); // multpfsq
    v0288 = (*qfn2(fn))(qenv(fn), stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    fn = elt(env, 3); // addpf
    v0360 = (*qfn2(fn))(qenv(fn), stack[-1], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0288 = stack[-3];
    v0288 = cons(v0360, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    stack[-3] = v0288;
    v0288 = stack[-2];
    v0288 = qcdr(v0288);
    stack[-2] = v0288;
    goto v0040;

v0101:
    v0288 = qvalue(elt(env, 1)); // t
    goto v0119;
// error exit handlers
v0115:
    popv(5);
    return nil;
}



// Code for gftimes

static LispObject CC_gftimes(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0090, v0091, v0104;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gftimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0091 = v0003;
    v0104 = v0004;
// end of prologue
    v0090 = v0104;
    v0090 = qcar(v0090);
    if (!consp(v0090)) goto v0027;
    v0090 = v0104;
    {
        fn = elt(env, 1); // gbftimes
        return (*qfn2(fn))(qenv(fn), v0090, v0091);
    }

v0027:
    v0090 = v0104;
    {
        fn = elt(env, 2); // gfftimes
        return (*qfn2(fn))(qenv(fn), v0090, v0091);
    }
}



// Code for getphystypeall

static LispObject CC_getphystypeall(LispObject env,
                         LispObject v0004)
{
    LispObject nil = C_nil;
    LispObject v0089, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystypeall");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
// end of prologue
    v0080 = (LispObject)1; // 0
    v0089 = stack[0];
    fn = elt(env, 3); // deleteall
    v0089 = (*qfn2(fn))(qenv(fn), v0080, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    fn = elt(env, 4); // collectphystype
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0080 = v0089;
    if (v0089 == nil) goto v0014;
    v0089 = v0080;
    v0089 = qcdr(v0089);
    if (v0089 == nil) goto v0110;
    stack[-1] = elt(env, 0); // getphystypeall
    v0080 = elt(env, 2); // "PHYSOP type mismatch in"
    v0089 = stack[0];
    v0089 = list2(v0080, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    fn = elt(env, 5); // rederr2
    v0089 = (*qfn2(fn))(qenv(fn), stack[-1], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    v0089 = nil;
    { popv(3); return onevalue(v0089); }

v0110:
    v0089 = v0080;
    v0089 = qcar(v0089);
    { popv(3); return onevalue(v0089); }

v0014:
    v0089 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0089); }
// error exit handlers
v0103:
    popv(3);
    return nil;
}



// Code for deletez1

static LispObject CC_deletez1(LispObject env,
                         LispObject v0004, LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0311, v0001, v0002, v0057;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deletez1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
// end of prologue
    v0057 = nil;
    goto v0040;

v0040:
    v0311 = stack[-1];
    if (v0311 == nil) goto v0021;
    v0002 = (LispObject)1; // 0
    v0311 = stack[-1];
    v0311 = qcar(v0311);
    v0001 = qcar(v0311);
    v0311 = stack[0];
    v0311 = Lassoc(nil, v0001, v0311);
    v0311 = qcdr(v0311);
    if (v0002 == v0311) goto v0119;
    v0311 = stack[-1];
    v0311 = qcar(v0311);
    v0001 = v0057;
    v0311 = cons(v0311, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0057 = v0311;
    v0311 = stack[-1];
    v0311 = qcdr(v0311);
    stack[-1] = v0311;
    goto v0040;

v0119:
    v0311 = stack[-1];
    v0311 = qcdr(v0311);
    stack[-1] = v0311;
    goto v0040;

v0021:
    v0311 = v0057;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0311);
    }
// error exit handlers
v0054:
    popv(3);
    return nil;
}



setup_type const u34_setup[] =
{
    {"cde_replace_nth",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_cde_replace_nth},
    {"ofsf_sippsignchkf",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sippsignchkf},
    {"ithlistelem",             too_few_2,      CC_ithlistelem,wrong_no_2},
    {"maxl",                    CC_maxl,        too_many_1,    wrong_no_1},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,too_many_1,wrong_no_1},
    {"sc_subtrsq",              too_few_2,      CC_sc_subtrsq, wrong_no_2},
    {"getrlist",                CC_getrlist,    too_many_1,    wrong_no_1},
    {"chkint*",                 CC_chkintH,     too_many_1,    wrong_no_1},
    {"indordl2",                too_few_2,      CC_indordl2,   wrong_no_2},
    {"calc_coeff",              too_few_2,      CC_calc_coeff, wrong_no_2},
    {"liennewstruc",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_liennewstruc},
    {"listsub",                 too_few_2,      CC_listsub,    wrong_no_2},
    {"red_tailreddriver",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_tailreddriver},
    {"ext_mult",                too_few_2,      CC_ext_mult,   wrong_no_2},
    {"ra_qmk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_ra_qmk},
    {"polynomcompare",          too_few_2,      CC_polynomcompare,wrong_no_2},
    {"maxfrom1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_maxfrom1},
    {"get-denom-l",             CC_getKdenomKl, too_many_1,    wrong_no_1},
    {"mk+real+inner+product",   too_few_2,      CC_mkLrealLinnerLproduct,wrong_no_2},
    {"iv_cutcongs1",            too_few_2,      CC_iv_cutcongs1,wrong_no_2},
    {"sfto_mvarx",              CC_sfto_mvarx,  too_many_1,    wrong_no_1},
    {"dip_moncomp",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_dip_moncomp},
    {"getargsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_getargsrd},
    {"evequal",                 too_few_2,      CC_evequal,    wrong_no_2},
    {"evalb",                   CC_evalb,       too_many_1,    wrong_no_1},
    {"min0",                    too_few_2,      CC_min0,       wrong_no_2},
    {"physoptimes",             CC_physoptimes, too_many_1,    wrong_no_1},
    {"remchkf1",                too_few_2,      CC_remchkf1,   wrong_no_2},
    {"horner-rule-for-one-var", wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"drnconv",                 CC_drnconv,     too_many_1,    wrong_no_1},
    {"order_of_der_mind",       CC_order_of_der_mind,too_many_1,wrong_no_1},
    {"even_action_sf",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_sf},
    {"rl_fvarl",                CC_rl_fvarl,    too_many_1,    wrong_no_1},
    {"pasf_smordtable1",        too_few_2,      CC_pasf_smordtable1,wrong_no_2},
    {"symbolsom",               CC_symbolsom,   too_many_1,    wrong_no_1},
    {"close_forall",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_close_forall},
    {"sparpri",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_sparpri},
    {"sc_mkmatrix",             too_few_2,      CC_sc_mkmatrix,wrong_no_2},
    {"string2bytelist",         CC_string2bytelist,too_many_1, wrong_no_1},
    {"sublap",                  too_few_2,      CC_sublap,     wrong_no_2},
    {"prop-simp1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_propKsimp1},
    {"no-side-effectp",         CC_noKsideKeffectp,too_many_1, wrong_no_1},
    {"**a2i",                   too_few_2,      CC_HHa2i,      wrong_no_2},
    {"groeb=crita",             CC_groebMcrita, too_many_1,    wrong_no_1},
    {"gvar1",                   too_few_2,      CC_gvar1,      wrong_no_2},
    {"multivariatep",           too_few_2,      CC_multivariatep,wrong_no_2},
    {"dvfsf_v",                 CC_dvfsf_v,     too_many_1,    wrong_no_1},
    {"cl_rename-vars",          CC_cl_renameKvars,too_many_1,  wrong_no_1},
    {"sfto_lmultf",             CC_sfto_lmultf, too_many_1,    wrong_no_1},
    {"give*position",           too_few_2,      CC_giveHposition,wrong_no_2},
    {"mconv1",                  CC_mconv1,      too_many_1,    wrong_no_1},
    {"pasf_uprap",              CC_pasf_uprap,  too_many_1,    wrong_no_1},
    {"vdp_setsugar",            too_few_2,      CC_vdp_setsugar,wrong_no_2},
    {"sfto_b:extadd",           too_few_2,      CC_sfto_bTextadd,wrong_no_2},
    {"ciml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_ciml},
    {"matrixp",                 CC_matrixp,     too_many_1,    wrong_no_1},
    {"exdff0",                  CC_exdff0,      too_many_1,    wrong_no_1},
    {"gftimes",                 too_few_2,      CC_gftimes,    wrong_no_2},
    {"getphystypeall",          CC_getphystypeall,too_many_1,  wrong_no_1},
    {"deletez1",                too_few_2,      CC_deletez1,   wrong_no_2},
    {NULL, (one_args *)"u34", (two_args *)"18713 7087883 4907594", 0}
};

// end of generated code
