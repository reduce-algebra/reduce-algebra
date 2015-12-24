
// $destdir/u45.c        Machine generated C code

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



// Code for monomcomparelex

static LispObject CC_monomcomparelex(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0023, v0024, v0025;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomcomparelex");
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
    v0023 = v0000;
// end of prologue
    v0025 = qvalue(elt(env, 1)); // nil
    v0024 = v0023;
    v0023 = (LispObject)17; // 1
    v0023 = *(LispObject *)((char *)v0024 + (CELL-TAG_VECTOR) + ((int32_t)v0023/(16/CELL)));
    v0023 = cons(v0025, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    v0023 = Lreverse(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    v0023 = qcdr(v0023);
    stack[-2] = v0023;
    v0025 = qvalue(elt(env, 1)); // nil
    v0024 = stack[0];
    v0023 = (LispObject)17; // 1
    v0023 = *(LispObject *)((char *)v0024 + (CELL-TAG_VECTOR) + ((int32_t)v0023/(16/CELL)));
    v0023 = cons(v0025, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    v0023 = Lreverse(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    v0023 = qcdr(v0023);
    stack[-1] = v0023;
    v0023 = (LispObject)1; // 0
    stack[0] = v0023;
    goto v0027;

v0027:
    v0023 = stack[-2];
    v0023 = qcar(v0023);
    if (v0023 == nil) goto v0028;
    v0023 = stack[-1];
    v0023 = qcar(v0023);
    if (v0023 == nil) goto v0028;
    v0023 = stack[-2];
    v0024 = qcar(v0023);
    v0023 = stack[-1];
    v0023 = qcar(v0023);
    v0023 = (LispObject)lessp2(v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-3];
    if (v0023 == nil) goto v0029;
    v0023 = (LispObject)17; // 1
    stack[0] = v0023;
    v0023 = qvalue(elt(env, 1)); // nil
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    stack[-2] = v0023;
    goto v0027;

v0029:
    v0023 = stack[-2];
    v0024 = qcar(v0023);
    v0023 = stack[-1];
    v0023 = qcar(v0023);
    v0023 = (LispObject)greaterp2(v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-3];
    if (v0023 == nil) goto v0030;
    v0023 = (LispObject)-15; // -1
    stack[0] = v0023;
    v0023 = qvalue(elt(env, 1)); // nil
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-3];
    stack[-2] = v0023;
    goto v0027;

v0030:
    v0023 = stack[-2];
    v0023 = qcdr(v0023);
    stack[-2] = v0023;
    v0023 = stack[-1];
    v0023 = qcdr(v0023);
    stack[-1] = v0023;
    goto v0027;

v0028:
    v0024 = stack[0];
    v0023 = (LispObject)1; // 0
    if (v0024 == v0023) goto v0031;
    v0023 = qvalue(elt(env, 1)); // nil
    goto v0032;

v0032:
    if (v0023 == nil) goto v0033;
    v0023 = (LispObject)17; // 1
    stack[0] = v0023;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0033:
    v0024 = stack[0];
    v0023 = (LispObject)1; // 0
    if (v0024 == v0023) goto v0034;
    v0023 = qvalue(elt(env, 1)); // nil
    goto v0035;

v0035:
    if (v0023 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0023 = (LispObject)-15; // -1
    stack[0] = v0023;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0034:
    v0023 = stack[-1];
    v0023 = qcar(v0023);
    goto v0035;

v0031:
    v0023 = stack[-2];
    v0023 = qcar(v0023);
    goto v0032;
// error exit handlers
v0026:
    popv(4);
    return nil;
}



// Code for rl_subat

static LispObject CC_rl_subat(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0039, v0040;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_subat");
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
    v0039 = v0001;
    v0040 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_subat!*
    v0039 = list2(v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    {
        LispObject v0021 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0021, v0039);
    }
// error exit handlers
v0041:
    popv(2);
    return nil;
}



// Code for bc_dcont

static LispObject CC_bc_dcont(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_dcont");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0003 = qcar(v0003);
    {
        fn = elt(env, 1); // sfto_dcontentf
        return (*qfn1(fn))(qenv(fn), v0003);
    }
}



// Code for safe!-fp!-quot

static LispObject CC_safeKfpKquot(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0055, v0030, v0056;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for safe-fp-quot");
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
    v0056 = v0001;
    stack[0] = v0000;
// end of prologue
    v0030 = v0056;
    v0055 = elt(env, 1); // 0.0
    if (equal(v0030, v0055)) goto v0057;
    v0055 = qvalue(elt(env, 3)); // !*nonegzerotimes
    if (v0055 == nil) goto v0058;
    v0030 = stack[0];
    v0055 = elt(env, 1); // 0.0
    if (!(equal(v0030, v0055))) goto v0058;
    v0055 = elt(env, 1); // 0.0
    { popv(3); return onevalue(v0055); }

v0058:
    v0055 = stack[0];
    v0030 = v0056;
    v0055 = quot2(v0055, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    stack[-1] = v0055;
    v0030 = stack[-1];
    v0055 = qvalue(elt(env, 4)); // !!minnorm
    v0055 = (LispObject)lessp2(v0030, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-2];
    if (v0055 == nil) goto v0029;
    v0030 = stack[-1];
    v0055 = qvalue(elt(env, 5)); // !!minnegnorm
    v0055 = (LispObject)greaterp2(v0030, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-2];
    if (v0055 == nil) goto v0029;
    v0030 = stack[0];
    v0055 = elt(env, 1); // 0.0
    if (equal(v0030, v0055)) goto v0029;
    v0055 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0055); }

v0029:
    v0030 = stack[-1];
    v0055 = stack[-1];
    v0030 = difference2(v0030, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0055 = elt(env, 1); // 0.0
    if (equal(v0030, v0055)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0055 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0055); }

v0057:
    v0055 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0055); }
// error exit handlers
v0059:
    popv(3);
    return nil;
}



// Code for gfquotient

static LispObject CC_gfquotient(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0062, v0052, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfquotient");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0052 = v0001;
    v0053 = v0000;
// end of prologue
    v0062 = v0053;
    v0062 = qcar(v0062);
    if (!consp(v0062)) goto v0037;
    v0062 = v0053;
    {
        fn = elt(env, 1); // gbfquot
        return (*qfn2(fn))(qenv(fn), v0062, v0052);
    }

v0037:
    v0062 = v0053;
    {
        fn = elt(env, 2); // gffquot
        return (*qfn2(fn))(qenv(fn), v0062, v0052);
    }
}



// Code for mkdmoderr

static LispObject CC_mkdmoderr(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0061;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkdmoderr");
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
    stack[-3] = v0001;
    v0061 = v0000;
// end of prologue
    stack[-4] = elt(env, 1); // lambda
    stack[-2] = elt(env, 2); // (!*x!*)
    stack[-1] = elt(env, 3); // dmoderr
    stack[0] = Lmkquote(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0061 = stack[-3];
    v0061 = Lmkquote(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0061 = list3(stack[-1], stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    {
        LispObject v0015 = stack[-4];
        LispObject v0066 = stack[-2];
        popv(6);
        return list3(v0015, v0066, v0061);
    }
// error exit handlers
v0058:
    popv(6);
    return nil;
}



// Code for physopsubs

static LispObject CC_physopsubs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0085, v0086, v0002;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopsubs");
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
    stack[-2] = qvalue(elt(env, 1)); // alglist!*
    qvalue(elt(env, 1)) = nil; // alglist!*
    v0085 = qvalue(elt(env, 2)); // nil
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0085; // alglist!*
    v0085 = stack[-1];
    fn = elt(env, 11); // physop2sq
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    stack[-1] = v0085;
    v0085 = qvalue(elt(env, 3)); // physoplist!*
    stack[0] = v0085;
    goto v0087;

v0087:
    v0085 = stack[0];
    if (v0085 == nil) goto v0088;
    v0085 = stack[0];
    v0085 = qcar(v0085);
    v0002 = v0085;
    v0086 = v0002;
    v0085 = elt(env, 4); // rtype
    v0085 = Lremprop(nil, v0086, v0085);
    env = stack[-3];
    v0086 = elt(env, 5); // simpfn
    v0085 = elt(env, 6); // simpiden
    v0085 = Lputprop(nil, 3, v0002, v0086, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    stack[0] = v0085;
    goto v0087;

v0088:
    v0086 = elt(env, 7); // (dot)
    v0085 = elt(env, 8); // physopfn
    v0085 = Lremflag(nil, v0086, v0085);
    env = stack[-3];
    v0002 = elt(env, 9); // dot
    v0086 = elt(env, 5); // simpfn
    v0085 = elt(env, 6); // simpiden
    v0085 = Lputprop(nil, 3, v0002, v0086, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    v0085 = stack[-1];
    fn = elt(env, 12); // subs2
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    stack[-1] = v0085;
    v0085 = stack[-1];
    fn = elt(env, 13); // !*q2a
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    stack[-1] = v0085;
    v0085 = qvalue(elt(env, 3)); // physoplist!*
    stack[0] = v0085;
    goto v0089;

v0089:
    v0085 = stack[0];
    if (v0085 == nil) goto v0031;
    v0085 = stack[0];
    v0085 = qcar(v0085);
    v0002 = v0085;
    v0086 = v0002;
    v0085 = elt(env, 5); // simpfn
    v0085 = Lremprop(nil, v0086, v0085);
    env = stack[-3];
    v0086 = elt(env, 4); // rtype
    v0085 = elt(env, 10); // physop
    v0085 = Lputprop(nil, 3, v0002, v0086, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    stack[0] = v0085;
    goto v0089;

v0031:
    v0086 = elt(env, 9); // dot
    v0085 = elt(env, 5); // simpfn
    v0085 = Lremprop(nil, v0086, v0085);
    env = stack[-3];
    v0086 = elt(env, 7); // (dot)
    v0085 = elt(env, 8); // physopfn
    v0085 = Lflag(nil, v0086, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    v0085 = stack[-1];
    qvalue(elt(env, 1)) = stack[-2]; // alglist!*
    { popv(4); return onevalue(v0085); }
// error exit handlers
v0033:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // alglist!*
    popv(4);
    return nil;
}



// Code for listquotient

static LispObject CC_listquotient(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0051, v0017, v0018, v0016;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listquotient");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0018 = v0001;
    v0016 = v0000;
// end of prologue
    v0017 = v0018;
    v0051 = (LispObject)17; // 1
    if (v0017 == v0051) return onevalue(v0016);
    v0017 = v0018;
    v0051 = v0016;
    if (equal(v0017, v0051)) goto v0054;
    v0051 = elt(env, 1); // quotient
    v0017 = v0016;
    return list3(v0051, v0017, v0018);

v0054:
    v0051 = (LispObject)17; // 1
    return onevalue(v0051);
}



// Code for fs!:prin!:

static LispObject CC_fsTprinT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:prin:");
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
    v0036 = elt(env, 1); // "["
    fn = elt(env, 3); // prin2!*
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-1];
    v0036 = stack[0];
    v0036 = qcdr(v0036);
    fn = elt(env, 4); // fs!:prin
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-1];
    v0036 = elt(env, 2); // "]"
    {
        popv(2);
        fn = elt(env, 3); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0036);
    }
// error exit handlers
v0064:
    popv(2);
    return nil;
}



// Code for verify_tens_ids

static LispObject CC_verify_tens_ids(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0093, v0094;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for verify_tens_ids");
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
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    v0094 = v0093;
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    v0093 = qcar(v0093);
    stack[0] = v0093;
    v0093 = v0094;
    fn = elt(env, 4); // extract_dummy_ids
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    fn = elt(env, 5); // repeats
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    if (!(v0093 == nil)) goto v0020;
    v0093 = stack[0];
    fn = elt(env, 4); // extract_dummy_ids
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    fn = elt(env, 5); // repeats
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    if (!(v0093 == nil)) goto v0020;
    v0093 = qvalue(elt(env, 3)); // t
    { popv(4); return onevalue(v0093); }

v0020:
    stack[-2] = elt(env, 1); // cantens
    stack[0] = (LispObject)33; // 2
    v0093 = stack[-1];
    v0094 = qcar(v0093);
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    v0093 = qcar(v0093);
    v0094 = list2(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    v0093 = elt(env, 2); // "are inconsistent lists of indices"
    v0093 = list2(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    fn = elt(env, 6); // rerror
    v0093 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    v0093 = nil;
    { popv(4); return onevalue(v0093); }
// error exit handlers
v0095:
    popv(4);
    return nil;
}



// Code for my_freeof

static LispObject CC_my_freeof(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0053, v0096, v0084;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for my_freeof");
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
    v0096 = stack[0];
    v0053 = stack[-1];
    fn = elt(env, 3); // smember
    v0053 = (*qfn2(fn))(qenv(fn), v0096, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-2];
    if (v0053 == nil) goto v0019;
    v0053 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0053); }

v0019:
    v0084 = qvalue(elt(env, 1)); // depl!*
    v0096 = stack[-1];
    v0053 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // freeofdepl
        return (*qfnn(fn))(qenv(fn), 3, v0084, v0096, v0053);
    }
// error exit handlers
v0066:
    popv(3);
    return nil;
}



// Code for makecoeffpairs

static LispObject CC_makecoeffpairs(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0041, v0021, v0022, v0020;
    LispObject fn;
    LispObject v0008, v0097, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairs");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0097 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makecoeffpairs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0008,v0097,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0097,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0041 = v0008;
    v0021 = v0097;
    v0022 = v0001;
    v0020 = v0000;
// end of prologue
    fn = elt(env, 1); // makecoeffpairs1
    v0041 = (*qfnn(fn))(qenv(fn), 4, v0020, v0022, v0021, v0041);
    errexit();
    v0041 = qcdr(v0041);
        return Lnreverse(nil, v0041);
}



// Code for ofsf_updsignpow

static LispObject CC_ofsf_updsignpow(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0017, v0018, v0016, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_updsignpow");
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
    v0016 = v0001;
    v0082 = v0000;
// end of prologue
    v0018 = v0082;
    v0017 = elt(env, 1); // (equal greaterp geq neq)
    v0017 = Lmemq(nil, v0018, v0017);
    if (!(v0017 == nil)) { popv(1); return onevalue(v0082); }
    v0018 = v0082;
    v0017 = elt(env, 2); // (lessp leq)
    v0017 = Lmemq(nil, v0018, v0017);
    if (v0017 == nil) goto v0090;
    v0017 = v0082;
    v0018 = v0016;
    v0018 = Levenp(nil, v0018);
    env = stack[0];
    v0018 = (v0018 == nil ? lisp_true : nil);
    {
        popv(1);
        fn = elt(env, 4); // ofsf_canegrel
        return (*qfn2(fn))(qenv(fn), v0017, v0018);
    }

v0090:
    v0017 = elt(env, 3); // unknown
    { popv(1); return onevalue(v0017); }
}



// Code for spinnerprod

static LispObject CC_spinnerprod(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0110, v0111, v0112, v0113;
    LispObject v0003, v0004, v0008, v0097, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "spinnerprod");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0097 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spinnerprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0003,v0004,v0008,v0097,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0097,v0008,v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0003;
    v0110 = v0004;
    v0111 = v0008;
    stack[-5] = v0097;
    v0112 = v0001;
    v0113 = v0000;
// end of prologue
    stack[-6] = v0111;
    v0111 = stack[-6];
    stack[-3] = v0111;
    v0110 = qcdr(v0110);
    stack[-1] = v0110;
    goto v0040;

v0040:
    v0110 = stack[-1];
    if (v0110 == nil) { LispObject res = stack[-3]; popv(9); return onevalue(res); }
    v0110 = stack[-1];
    v0110 = qcar(v0110);
    v0111 = v0110;
    v0110 = v0111;
    v0110 = qcar(v0110);
    stack[-7] = v0110;
    v0110 = stack[-7];
    if (!(v0110 == nil)) goto v0066;
    v0110 = (LispObject)1; // 0
    stack[-7] = v0110;
    goto v0066;

v0066:
    v0110 = v0111;
    v0110 = qcdr(v0110);
    stack[-2] = v0110;
    v0110 = stack[-2];
    if (v0110 == nil) goto v0088;
    stack[0] = stack[-2];
    v0110 = qvalue(elt(env, 1)); // nil
    v0110 = ncons(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-8];
    v0110 = (equal(stack[0], v0110) ? lisp_true : nil);
    goto v0027;

v0027:
    if (v0110 == nil) goto v0045;
    v0110 = (LispObject)1; // 0
    stack[-2] = v0110;
    goto v0045;

v0045:
    v0111 = stack[-7];
    v0110 = stack[-5];
    v0110 = (LispObject)lesseq2(v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0110 = v0110 ? lisp_true : nil;
    env = stack[-8];
    if (v0110 == nil) goto v0078;
    v0111 = stack[-7];
    v0110 = stack[-4];
    v0110 = Latsoc(nil, v0111, v0110);
    stack[-7] = v0110;
    v0110 = stack[-7];
    if (v0110 == nil) goto v0075;
    stack[0] = stack[-7];
    v0110 = qvalue(elt(env, 1)); // nil
    v0110 = ncons(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-8];
    v0110 = (equal(stack[0], v0110) ? lisp_true : nil);
    goto v0114;

v0114:
    if (!(v0110 == nil)) goto v0078;
    stack[0] = elt(env, 3); // plus
    stack[-3] = stack[-6];
    v0112 = elt(env, 4); // times
    v0111 = stack[-2];
    v0110 = stack[-7];
    v0110 = qcdr(v0110);
    v0110 = list3(v0112, v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-8];
    v0110 = list3(stack[0], stack[-3], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-8];
    stack[-6] = v0110;
    v0110 = stack[-6];
    stack[-3] = v0110;
    goto v0078;

v0078:
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    stack[-1] = v0110;
    goto v0040;

v0075:
    v0110 = qvalue(elt(env, 2)); // t
    goto v0114;

v0088:
    v0110 = qvalue(elt(env, 2)); // t
    goto v0027;
// error exit handlers
v0026:
    popv(9);
    return nil;
}



// Code for vdplsort

static LispObject CC_vdplsort(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0037, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdplsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0037 = v0000;
// end of prologue
    v0064 = v0037;
    v0037 = elt(env, 1); // vdpvevlcomp
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(qenv(fn), v0064, v0037);
    }
}



// Code for indordln

static LispObject CC_indordln(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0082, v0083;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indordln");
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
    v0083 = v0000;
// end of prologue
    v0082 = v0083;
    if (v0082 == nil) goto v0004;
    v0082 = v0083;
    v0082 = qcdr(v0082);
    if (v0082 == nil) { popv(2); return onevalue(v0083); }
    v0082 = v0083;
    v0082 = qcdr(v0082);
    v0082 = qcdr(v0082);
    if (v0082 == nil) goto v0040;
    v0082 = v0083;
    stack[0] = qcar(v0082);
    v0082 = v0083;
    v0082 = qcdr(v0082);
    v0082 = CC_indordln(env, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    {
        LispObject v0027 = stack[0];
        popv(2);
        fn = elt(env, 2); // indordlad
        return (*qfn2(fn))(qenv(fn), v0027, v0082);
    }

v0040:
    v0082 = v0083;
    v0082 = qcar(v0082);
    v0083 = qcdr(v0083);
    v0083 = qcar(v0083);
    {
        popv(2);
        fn = elt(env, 3); // indordl2
        return (*qfn2(fn))(qenv(fn), v0082, v0083);
    }

v0004:
    v0082 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0082); }
// error exit handlers
v0108:
    popv(2);
    return nil;
}



// Code for free

static LispObject CC_free(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for free");
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
    v0039 = stack[0];
    v0039 = qcdr(v0039);
    v0039 = qcar(v0039);
    fn = elt(env, 2); // freeind
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    if (v0039 == nil) goto v0004;
    v0039 = stack[0];
    v0039 = qcdr(v0039);
    v0039 = qcdr(v0039);
    v0039 = qcar(v0039);
    {
        popv(2);
        fn = elt(env, 2); // freeind
        return (*qfn1(fn))(qenv(fn), v0039);
    }

v0004:
    v0039 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0039); }
// error exit handlers
v0115:
    popv(2);
    return nil;
}



// Code for expand!-imrepartpow

static LispObject CC_expandKimrepartpow(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028, v0121;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expand-imrepartpow");
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
    stack[-3] = qvalue(elt(env, 1)); // !*exp
    qvalue(elt(env, 1)) = nil; // !*exp
    v0028 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0028; // !*exp
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    if (symbolp(v0028)) goto v0022;
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    v0121 = qcar(v0028);
    v0028 = elt(env, 3); // cmpxsplitfn
    v0028 = get(v0121, v0028);
    env = stack[-4];
    goto v0057;

v0057:
    v0121 = v0028;
    v0028 = v0121;
    if (v0028 == nil) goto v0016;
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    v0028 = Lapply1(nil, v0121, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0121 = v0028;
    goto v0053;

v0053:
    v0028 = stack[-2];
    v0028 = qcdr(v0028);
    fn = elt(env, 6); // exptsq
    v0028 = (*qfn2(fn))(qenv(fn), v0121, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; // !*exp
    { popv(5); return onevalue(v0028); }

v0016:
    v0028 = stack[-2];
    v0121 = qcar(v0028);
    v0028 = elt(env, 5); // i
    if (v0121 == v0028) goto v0077;
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    fn = elt(env, 7); // mkrepart
    stack[-1] = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0028 = elt(env, 5); // i
    fn = elt(env, 8); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    fn = elt(env, 9); // mkimpart
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    fn = elt(env, 10); // multsq
    v0028 = (*qfn2(fn))(qenv(fn), stack[0], v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    fn = elt(env, 11); // addsq
    v0028 = (*qfn2(fn))(qenv(fn), stack[-1], v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    goto v0051;

v0051:
    v0121 = v0028;
    goto v0053;

v0077:
    v0121 = elt(env, 5); // i
    v0028 = (LispObject)17; // 1
    fn = elt(env, 12); // to
    v0121 = (*qfn2(fn))(qenv(fn), v0121, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0028 = (LispObject)17; // 1
    v0028 = cons(v0121, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0121 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0028 = (LispObject)17; // 1
    v0028 = cons(v0121, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    goto v0051;

v0022:
    v0028 = qvalue(elt(env, 4)); // nil
    goto v0057;
// error exit handlers
v0010:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; // !*exp
    popv(5);
    return nil;
}



// Code for generic_arguments

static LispObject CC_generic_arguments(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0040, v0115;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for generic_arguments");
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
    v0039 = v0000;
// end of prologue
    v0115 = elt(env, 1); // list
    v0040 = qcar(v0039);
    v0039 = elt(env, 2); // generic_function
    v0039 = get(v0040, v0039);
    return cons(v0115, v0039);
}



// Code for groeb!=testb

static LispObject CC_groebMtestb(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0070, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=testb");
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
    v0070 = stack[-1];
    fn = elt(env, 2); // mo_comp
    v0009 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    v0070 = stack[0];
    v0070 = qcar(v0070);
    if (equal(v0009, v0070)) goto v0041;
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0070); }

v0041:
    stack[-2] = stack[-1];
    v0009 = stack[0];
    v0070 = (LispObject)49; // 3
    fn = elt(env, 3); // nth
    v0070 = (*qfn2(fn))(qenv(fn), v0009, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 4); // mo_divides!?
    v0070 = (*qfn2(fn))(qenv(fn), stack[-2], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    if (v0070 == nil) goto v0039;
    v0009 = stack[0];
    v0070 = (LispObject)81; // 5
    fn = elt(env, 3); // nth
    v0070 = (*qfn2(fn))(qenv(fn), v0009, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 5); // bas_dpoly
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 6); // dp_lmon
    v0009 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    v0070 = stack[-1];
    fn = elt(env, 7); // mo_lcm
    stack[-2] = (*qfn2(fn))(qenv(fn), v0009, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    v0009 = stack[0];
    v0070 = (LispObject)49; // 3
    fn = elt(env, 3); // nth
    v0070 = (*qfn2(fn))(qenv(fn), v0009, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 8); // mo_equal!?
    v0070 = (*qfn2(fn))(qenv(fn), stack[-2], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    if (v0070 == nil) goto v0114;
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0070); }

v0114:
    v0009 = stack[0];
    v0070 = (LispObject)65; // 4
    fn = elt(env, 3); // nth
    v0070 = (*qfn2(fn))(qenv(fn), v0009, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 5); // bas_dpoly
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 6); // dp_lmon
    v0009 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    v0070 = stack[-1];
    fn = elt(env, 7); // mo_lcm
    stack[-1] = (*qfn2(fn))(qenv(fn), v0009, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    v0009 = stack[0];
    v0070 = (LispObject)49; // 3
    fn = elt(env, 3); // nth
    v0070 = (*qfn2(fn))(qenv(fn), v0009, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 8); // mo_equal!?
    v0070 = (*qfn2(fn))(qenv(fn), stack[-1], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    v0070 = (v0070 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v0070); }

v0039:
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0070); }
// error exit handlers
v0098:
    popv(4);
    return nil;
}



// Code for njets

static LispObject CC_njets(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0040, v0115;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for njets");
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
    v0040 = v0001;
    v0115 = v0000;
// end of prologue
    stack[-1] = v0040;
    stack[0] = v0040;
    v0040 = v0115;
    v0040 = sub1(v0040);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    v0040 = plus2(stack[0], v0040);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    {
        LispObject v0020 = stack[-1];
        popv(3);
        fn = elt(env, 1); // combin
        return (*qfn2(fn))(qenv(fn), v0020, v0040);
    }
// error exit handlers
v0022:
    popv(3);
    return nil;
}



// Code for taylorp

static LispObject CC_taylorp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0053, v0096;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for taylorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0096 = v0000;
// end of prologue
    v0053 = v0096;
    if (!consp(v0053)) goto v0061;
    v0053 = v0096;
    v0053 = qcar(v0053);
    if (!consp(v0053)) goto v0022;
    v0053 = v0096;
    v0053 = qcar(v0053);
    v0053 = qcar(v0053);
    v0096 = elt(env, 1); // taylor
        return Lflagp(nil, v0053, v0096);

v0022:
    v0053 = qvalue(elt(env, 2)); // nil
    return onevalue(v0053);

v0061:
    v0053 = qvalue(elt(env, 2)); // nil
    return onevalue(v0053);
}



// Code for domainp_list

static LispObject CC_domainp_list(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0066;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for domainp_list");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0015 = v0000;
// end of prologue

v0125:
    v0066 = v0015;
    if (v0066 == nil) goto v0004;
    v0066 = v0015;
    v0066 = qcar(v0066);
    if (!consp(v0066)) goto v0019;
    v0066 = v0015;
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0066 = (consp(v0066) ? nil : lisp_true);
    goto v0054;

v0054:
    if (v0066 == nil) goto v0096;
    v0015 = qcdr(v0015);
    goto v0125;

v0096:
    v0015 = qvalue(elt(env, 2)); // nil
    return onevalue(v0015);

v0019:
    v0066 = qvalue(elt(env, 1)); // t
    goto v0054;

v0004:
    v0015 = qvalue(elt(env, 1)); // t
    return onevalue(v0015);
}



// Code for janettreeinsert

static LispObject CC_janettreeinsert(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0157, v0158, v0159;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for janettreeinsert");
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
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0000;
// end of prologue
    v0158 = stack[-7];
    v0157 = (LispObject)17; // 1
    v0157 = *(LispObject *)((char *)v0158 + (CELL-TAG_VECTOR) + ((int32_t)v0157/(16/CELL)));
    v0157 = qcar(v0157);
    stack[-3] = v0157;
    v0158 = stack[-3];
    v0157 = (LispObject)1; // 0
    v0157 = *(LispObject *)((char *)v0158 + (CELL-TAG_VECTOR) + ((int32_t)v0157/(16/CELL)));
    stack[-6] = v0157;
    v0157 = (LispObject)17; // 1
    stack[-8] = v0157;
    v0157 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    if (v0157 == nil) goto v0091;
    v0157 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    stack[-5] = v0157;
    goto v0160;

v0160:
    v0158 = stack[-6];
    v0157 = (LispObject)1; // 0
    v0157 = (LispObject)greaterp2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    v0157 = v0157 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0157 == nil)) goto v0162;

v0096:
    v0157 = nil;
    { popv(10); return onevalue(v0157); }

v0162:
    v0157 = stack[-5];
    if (v0157 == nil) goto v0163;
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    stack[0] = qcar(v0157);
    v0158 = stack[-3];
    v0157 = stack[-8];
    fn = elt(env, 3); // monomgetvariabledegree
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    v0157 = (LispObject)lessp2(stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    v0157 = v0157 ? lisp_true : nil;
    env = stack[-9];
    if (v0157 == nil) goto v0163;
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    if (v0157 == nil) goto v0163;
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    stack[-5] = v0157;
    goto v0162;

v0163:
    v0157 = stack[-5];
    if (v0157 == nil) goto v0031;
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    stack[0] = qcar(v0157);
    v0158 = stack[-3];
    v0157 = stack[-8];
    fn = elt(env, 3); // monomgetvariabledegree
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    v0157 = (LispObject)greaterp2(stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    v0157 = v0157 ? lisp_true : nil;
    env = stack[-9];
    if (v0157 == nil) goto v0031;
    v0159 = stack[-6];
    v0158 = stack[-8];
    v0157 = stack[-7];
    fn = elt(env, 4); // janettreenodebuild
    v0157 = (*qfnn(fn))(qenv(fn), 3, v0159, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    stack[-4] = v0157;
    v0157 = (LispObject)1; // 0
    stack[-6] = v0157;
    v0157 = stack[-5];
    stack[-2] = qcdr(v0157);
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    stack[-1] = qcar(v0157);
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    stack[0] = qcdr(v0157);
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0158 = qcar(v0157);
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    v0157 = acons(stack[-1], stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    fn = elt(env, 5); // setcar
    v0157 = (*qfn2(fn))(qenv(fn), stack[-2], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    v0157 = stack[-5];
    v0158 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    fn = elt(env, 6); // setcdr
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    v0157 = stack[-5];
    v0158 = qcar(v0157);
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    v0157 = qcar(v0157);
    fn = elt(env, 5); // setcar
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    v0157 = stack[-5];
    v0158 = qcar(v0157);
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    fn = elt(env, 6); // setcdr
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    goto v0160;

v0031:
    v0157 = stack[-5];
    if (v0157 == nil) goto v0164;
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    stack[0] = qcar(v0157);
    v0158 = stack[-3];
    v0157 = stack[-8];
    fn = elt(env, 3); // monomgetvariabledegree
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    if (equal(stack[0], v0157)) goto v0165;
    v0157 = qvalue(elt(env, 2)); // nil
    goto v0166;

v0166:
    if (v0157 == nil) goto v0164;
    stack[0] = stack[-6];
    v0158 = stack[-3];
    v0157 = stack[-8];
    fn = elt(env, 3); // monomgetvariabledegree
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    v0157 = difference2(stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    stack[-6] = v0157;
    v0157 = stack[-8];
    v0157 = add1(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    stack[-8] = v0157;
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    stack[-5] = v0157;
    goto v0160;

v0164:
    v0157 = stack[-5];
    if (v0157 == nil) goto v0160;
    v0157 = stack[-5];
    stack[0] = qcdr(v0157);
    v0159 = stack[-6];
    v0158 = stack[-8];
    v0157 = stack[-7];
    fn = elt(env, 4); // janettreenodebuild
    v0157 = (*qfnn(fn))(qenv(fn), 3, v0159, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    fn = elt(env, 5); // setcar
    v0157 = (*qfn2(fn))(qenv(fn), stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    v0157 = (LispObject)1; // 0
    stack[-6] = v0157;
    goto v0160;

v0165:
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    goto v0166;

v0091:
    v0159 = stack[-6];
    v0158 = stack[-8];
    v0157 = stack[-7];
    fn = elt(env, 4); // janettreenodebuild
    v0157 = (*qfnn(fn))(qenv(fn), 3, v0159, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0157; // fluidbibasisjanettreerootnode
    goto v0096;
// error exit handlers
v0161:
    popv(10);
    return nil;
}



// Code for mri_simplat1

static LispObject CC_mri_simplat1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0059, v0167;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_simplat1");
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
    v0059 = qvalue(elt(env, 1)); // !*rlsimplfloor
    if (v0059 == nil) goto v0057;
    v0059 = stack[-2];
    fn = elt(env, 4); // mri_op
    stack[-3] = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    v0059 = stack[-2];
    fn = elt(env, 5); // mri_arg2l
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    fn = elt(env, 6); // mri_simplfloor
    stack[0] = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    v0059 = stack[-2];
    fn = elt(env, 7); // mri_type
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    fn = elt(env, 8); // mri_0mk2
    v0059 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    stack[-2] = v0059;
    goto v0057;

v0057:
    v0059 = stack[-2];
    fn = elt(env, 7); // mri_type
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    if (!(v0059 == nil)) goto v0052;
    v0059 = stack[-2];
    fn = elt(env, 9); // mri_dettype
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    goto v0052;

v0052:
    stack[0] = v0059;
    v0167 = stack[0];
    v0059 = elt(env, 2); // int
    if (v0167 == v0059) goto v0080;
    v0059 = stack[-2];
    fn = elt(env, 10); // mri_congp
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    if (v0059 == nil) goto v0107;
    v0059 = stack[-2];
    fn = elt(env, 4); // mri_op
    stack[-1] = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    v0059 = stack[-2];
    fn = elt(env, 5); // mri_arg2l
    v0167 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    v0059 = stack[0];
    {
        LispObject v0007 = stack[-1];
        popv(5);
        fn = elt(env, 8); // mri_0mk2
        return (*qfnn(fn))(qenv(fn), 3, v0007, v0167, v0059);
    }

v0107:
    v0059 = stack[-2];
    fn = elt(env, 11); // mri_2ofsfat
    v0167 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    v0059 = stack[-1];
    fn = elt(env, 12); // ofsf_simplat1
    v0167 = (*qfn2(fn))(qenv(fn), v0167, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    v0059 = elt(env, 3); // real
    {
        popv(5);
        fn = elt(env, 13); // mri_ofsf2mri
        return (*qfn2(fn))(qenv(fn), v0167, v0059);
    }

v0080:
    v0059 = stack[-2];
    fn = elt(env, 14); // mri_2pasfat
    v0167 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    v0059 = stack[-1];
    fn = elt(env, 15); // pasf_simplat1
    v0167 = (*qfn2(fn))(qenv(fn), v0167, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-4];
    v0059 = elt(env, 2); // int
    {
        popv(5);
        fn = elt(env, 16); // mri_pasf2mri
        return (*qfn2(fn))(qenv(fn), v0167, v0059);
    }
// error exit handlers
v0117:
    popv(5);
    return nil;
}



// Code for cr!:prep

static LispObject CC_crTprep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0084, v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cr:prep");
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
    v0058 = elt(env, 1); // !:rd!:
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    v0084 = cons(v0058, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    fn = elt(env, 2); // rd!:prep
    stack[-1] = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    v0058 = elt(env, 1); // !:rd!:
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    v0084 = cons(v0058, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    fn = elt(env, 2); // rd!:prep
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    v0084 = cons(stack[-1], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); // crprep1
        return (*qfn1(fn))(qenv(fn), v0084);
    }
// error exit handlers
v0091:
    popv(3);
    return nil;
}



// Code for matsm!*

static LispObject CC_matsmH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0135, v0103;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matsm*");
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
    v0135 = v0001;
    v0103 = v0000;
// end of prologue
    v0135 = v0103;
    fn = elt(env, 1); // matsm
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // matsm!*1
        return (*qfn1(fn))(qenv(fn), v0135);
    }
// error exit handlers
v0057:
    popv(1);
    return nil;
}



// Code for f2dip

static LispObject CC_f2dip(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for f2dip");
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
    v0087 = v0000;
// end of prologue
    stack[-1] = v0087;
    fn = elt(env, 1); // evzero
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0087 = (LispObject)17; // 1
    fn = elt(env, 2); // bcfd
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    {
        LispObject v0039 = stack[-1];
        LispObject v0040 = stack[0];
        popv(3);
        fn = elt(env, 3); // f2dip1
        return (*qfnn(fn))(qenv(fn), 3, v0039, v0040, v0087);
    }
// error exit handlers
v0038:
    popv(3);
    return nil;
}



// Code for reset_opnums

static LispObject CC_reset_opnums(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0045, v0013, v0119;
    LispObject fn;
    argcheck(nargs, 0, "reset_opnums");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reset_opnums");
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
    push5(nil, nil, nil, nil, nil);
// end of prologue
    v0045 = qvalue(elt(env, 1)); // oporder!*
    stack[-4] = v0045;
    v0045 = (LispObject)17; // 1
    stack[-3] = v0045;
    goto v0057;

v0057:
    v0045 = stack[-4];
    if (v0045 == nil) goto v0065;
    v0045 = stack[-4];
    v0045 = qcar(v0045);
    v0013 = v0045;
    v0045 = stack[-4];
    v0045 = qcdr(v0045);
    stack[-4] = v0045;
    v0045 = v0013;
    if (symbolp(v0045)) goto v0022;
    v0045 = v0013;
    v0045 = qcar(v0045);
    stack[-2] = v0045;
    v0045 = v0013;
    v0045 = qcdr(v0045);
    goto v0091;

v0091:
    stack[-1] = stack[-2];
    stack[0] = elt(env, 3); // opnum
    v0013 = v0045;
    v0045 = stack[-3];
    v0119 = cons(v0013, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0013 = stack[-2];
    v0045 = elt(env, 3); // opnum
    v0045 = get(v0013, v0045);
    env = stack[-5];
    fn = elt(env, 4); // !*xadd
    v0045 = (*qfn2(fn))(qenv(fn), v0119, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0045 = Lputprop(nil, 3, stack[-1], stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0045 = stack[-3];
    v0045 = add1(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    stack[-3] = v0045;
    goto v0057;

v0022:
    v0045 = v0013;
    stack[-2] = v0045;
    v0045 = qvalue(elt(env, 2)); // nil
    goto v0091;

v0065:
    v0045 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0045); }
// error exit handlers
v0169:
    popv(6);
    return nil;
}



// Code for delete_edge

static LispObject CC_delete_edge(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0120, v0092, v0048;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete_edge");
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
    v0048 = nil;
    goto v0135;

v0135:
    v0120 = stack[0];
    if (v0120 == nil) goto v0036;
    v0120 = stack[-1];
    v0092 = qcar(v0120);
    v0120 = stack[0];
    v0120 = qcar(v0120);
    v0120 = qcar(v0120);
    if (v0092 == v0120) goto v0062;
    v0120 = stack[0];
    v0120 = qcar(v0120);
    v0092 = v0048;
    v0120 = cons(v0120, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-2];
    v0048 = v0120;
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    stack[0] = v0120;
    goto v0135;

v0062:
    v0092 = v0048;
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0092, v0120);
    }

v0036:
    v0120 = v0048;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0120);
    }
// error exit handlers
v0081:
    popv(3);
    return nil;
}



// Code for reduce!-ratios

static LispObject CC_reduceKratios(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0045, v0013;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-ratios");
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

v0064:
    v0013 = stack[-2];
    v0045 = stack[-1];
    fn = elt(env, 1); // red!-ratios1
    v0045 = (*qfn2(fn))(qenv(fn), v0013, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    stack[-3] = v0045;
    if (v0045 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0045 = stack[-3];
    v0013 = qcar(v0045);
    v0045 = stack[-2];
    fn = elt(env, 2); // mv!-domainlist!-!*
    stack[0] = (*qfn2(fn))(qenv(fn), v0013, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    v0045 = stack[-3];
    v0013 = qcdr(v0045);
    v0045 = stack[-1];
    fn = elt(env, 2); // mv!-domainlist!-!*
    v0045 = (*qfn2(fn))(qenv(fn), v0013, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    fn = elt(env, 3); // mv!-domainlist!-!-
    v0045 = (*qfn2(fn))(qenv(fn), stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    stack[-3] = v0045;
    v0045 = stack[-2];
    fn = elt(env, 4); // reddom_zeros
    stack[0] = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    v0045 = stack[-3];
    fn = elt(env, 4); // reddom_zeros
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    v0045 = (LispObject)geq2(stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    v0045 = v0045 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0045 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0013 = stack[-3];
    v0045 = stack[-1];
    stack[-2] = v0013;
    stack[-1] = v0045;
    goto v0064;
// error exit handlers
v0107:
    popv(5);
    return nil;
}



// Code for fs!:subang

static LispObject CC_fsTsubang(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0182, v0183, v0184, v0185;
    LispObject fn;
    LispObject v0097, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "fs:subang");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0097 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:subang");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0097;
    stack[-6] = v0001;
    stack[-7] = v0000;
// end of prologue
    v0182 = stack[-7];
    if (v0182 == nil) goto v0135;
    v0182 = (LispObject)113; // 7
    v0182 = Lmkvect(nil, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-9];
    stack[-8] = v0182;
    v0183 = stack[-7];
    v0182 = (LispObject)33; // 2
    v0183 = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    v0182 = stack[-6];
    v0182 = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    stack[-4] = v0182;
    v0182 = (LispObject)1; // 0
    stack[-3] = v0182;
    goto v0156;

v0156:
    v0183 = (LispObject)113; // 7
    v0182 = stack[-3];
    v0182 = difference2(v0183, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-9];
    v0182 = Lminusp(nil, v0182);
    env = stack[-9];
    if (v0182 == nil) goto v0168;
    v0183 = stack[-7];
    v0182 = (LispObject)49; // 3
    v0184 = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    v0183 = stack[-6];
    v0182 = stack[-5];
    stack[0] = CC_fsTsubang(env, 3, v0184, v0183, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-9];
    v0183 = stack[-7];
    v0182 = (LispObject)17; // 1
    v0185 = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    v0184 = stack[-8];
    v0183 = stack[-7];
    v0182 = (LispObject)1; // 0
    v0182 = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    fn = elt(env, 2); // make!-term
    v0182 = (*qfnn(fn))(qenv(fn), 3, v0185, v0184, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-9];
    {
        LispObject v0187 = stack[0];
        popv(10);
        fn = elt(env, 3); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0187, v0182);
    }

v0168:
    v0183 = stack[-3];
    v0182 = stack[-6];
    if (equal(v0183, v0182)) goto v0077;
    stack[-2] = stack[-8];
    stack[-1] = stack[-3];
    v0183 = stack[-7];
    v0182 = (LispObject)33; // 2
    v0183 = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    v0182 = stack[-3];
    stack[0] = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    v0184 = stack[-4];
    v0183 = stack[-5];
    v0182 = stack[-3];
    v0182 = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    v0182 = times2(v0184, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-9];
    v0182 = plus2(stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-9];
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0182;
    goto v0081;

v0081:
    v0182 = stack[-3];
    v0182 = add1(v0182);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-9];
    stack[-3] = v0182;
    goto v0156;

v0077:
    stack[-1] = stack[-8];
    stack[0] = stack[-3];
    v0184 = stack[-4];
    v0183 = stack[-5];
    v0182 = stack[-3];
    v0182 = *(LispObject *)((char *)v0183 + (CELL-TAG_VECTOR) + ((int32_t)v0182/(16/CELL)));
    v0182 = times2(v0184, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-9];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0182;
    goto v0081;

v0135:
    v0182 = qvalue(elt(env, 1)); // nil
    { popv(10); return onevalue(v0182); }
// error exit handlers
v0186:
    popv(10);
    return nil;
}



// Code for addnew

static LispObject CC_addnew(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0120, v0092, v0048, v0049, v0080;
    LispObject fn;
    LispObject v0097, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "addnew");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0097 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addnew");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0097;
    v0049 = v0001;
    v0080 = v0000;
// end of prologue
    v0048 = qvalue(elt(env, 1)); // gv!*
    v0092 = v0049;
    v0120 = v0080;
    *(LispObject *)((char *)v0048 + (CELL-TAG_VECTOR) + ((int32_t)v0092/(16/CELL))) = v0120;
    v0048 = qvalue(elt(env, 2)); // bv!*
    v0092 = v0049;
    v0120 = qvalue(elt(env, 3)); // t
    *(LispObject *)((char *)v0048 + (CELL-TAG_VECTOR) + ((int32_t)v0092/(16/CELL))) = v0120;
    v0120 = v0080;
    if (v0120 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = v0049;
    v0120 = v0080;
    fn = elt(env, 4); // ljet
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    v0092 = cons(stack[-1], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    v0120 = stack[0];
    fn = elt(env, 5); // insert
    v0120 = (*qfn2(fn))(qenv(fn), v0092, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    { popv(3); return onevalue(v0120); }
// error exit handlers
v0094:
    popv(3);
    return nil;
}



// Code for flattens1

static LispObject CC_flattens1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for flattens1");
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

v0004:
    v0058 = stack[0];
    if (!consp(v0058)) goto v0103;
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    if (v0058 == nil) goto v0052;
    v0058 = stack[0];
    v0058 = qcar(v0058);
    stack[-1] = CC_flattens1(env, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    v0058 = CC_flattens1(env, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    {
        LispObject v0090 = stack[-1];
        popv(3);
        return Lappend(nil, v0090, v0058);
    }

v0052:
    v0058 = stack[0];
    v0058 = qcar(v0058);
    stack[0] = v0058;
    goto v0004;

v0103:
    v0058 = stack[0];
    popv(3);
    return ncons(v0058);
// error exit handlers
v0091:
    popv(3);
    return nil;
}



// Code for pst_mkpst

static LispObject CC_pst_mkpst(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_mkpst");
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
    v0063 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // pst_mkpst1
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    v0063 = cons(stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // pst_equitable
        return (*qfn1(fn))(qenv(fn), v0063);
    }
// error exit handlers
v0087:
    popv(2);
    return nil;
}



// Code for !*q2f

static LispObject CC_Hq2f(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0062, v0052, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *q2f");
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
    v0053 = v0000;
// end of prologue
    v0062 = v0053;
    v0052 = qcdr(v0062);
    v0062 = (LispObject)17; // 1
    if (v0052 == v0062) goto v0004;
    v0062 = v0053;
    fn = elt(env, 2); // prepsq
    v0052 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[0];
    v0062 = elt(env, 1); // polynomial
    {
        popv(1);
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(qenv(fn), v0052, v0062);
    }

v0004:
    v0062 = v0053;
    v0062 = qcar(v0062);
    { popv(1); return onevalue(v0062); }
// error exit handlers
v0096:
    popv(1);
    return nil;
}



// Code for min2!-order

static LispObject CC_min2Korder(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0044, v0011;
    LispObject fn;
    LispObject v0097, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "min2-order");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0097 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for min2-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0097;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    goto v0103;

v0103:
    v0044 = stack[-3];
    if (v0044 == nil) goto v0037;
    v0044 = stack[-1];
    v0044 = qcar(v0044);
    stack[0] = v0044;
    v0044 = (LispObject)1; // 0
    v0011 = v0044;
    goto v0062;

v0062:
    v0044 = stack[0];
    if (v0044 == nil) goto v0015;
    v0044 = stack[0];
    v0044 = qcar(v0044);
    fn = elt(env, 1); // tayexp!-plus2
    v0044 = (*qfn2(fn))(qenv(fn), v0044, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-5];
    v0011 = v0044;
    v0044 = stack[0];
    v0044 = qcdr(v0044);
    stack[0] = v0044;
    goto v0062;

v0015:
    v0044 = v0011;
    stack[0] = v0044;
    v0011 = stack[0];
    v0044 = stack[-2];
    v0044 = qcar(v0044);
    fn = elt(env, 2); // tayexp!-greaterp
    v0044 = (*qfn2(fn))(qenv(fn), v0011, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-5];
    if (v0044 == nil) goto v0106;
    v0011 = stack[0];
    v0044 = stack[-3];
    v0044 = qcar(v0044);
    fn = elt(env, 3); // tayexp!-min2
    v0044 = (*qfn2(fn))(qenv(fn), v0011, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-5];
    v0011 = v0044;
    goto v0115;

v0115:
    v0044 = stack[-4];
    v0044 = cons(v0011, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-5];
    stack[-4] = v0044;
    v0044 = stack[-3];
    v0044 = qcdr(v0044);
    stack[-3] = v0044;
    v0044 = stack[-2];
    v0044 = qcdr(v0044);
    stack[-2] = v0044;
    v0044 = stack[-1];
    v0044 = qcdr(v0044);
    stack[-1] = v0044;
    goto v0103;

v0106:
    v0044 = stack[-3];
    v0044 = qcar(v0044);
    v0011 = v0044;
    goto v0115;

v0037:
    v0044 = stack[-4];
    {
        popv(6);
        fn = elt(env, 4); // nreverse
        return (*qfn1(fn))(qenv(fn), v0044);
    }
// error exit handlers
v0055:
    popv(6);
    return nil;
}



// Code for evalgeq

static LispObject CC_evalgeq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0063, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalgeq");
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
    v0063 = v0001;
    v0065 = v0000;
// end of prologue
    fn = elt(env, 1); // evallessp
    v0063 = (*qfn2(fn))(qenv(fn), v0065, v0063);
    errexit();
    v0063 = (v0063 == nil ? lisp_true : nil);
    return onevalue(v0063);
}



// Code for exp!*

static LispObject CC_expH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0037, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exp*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0037 = v0000;
// end of prologue
    v0064 = v0037;
    v0037 = qvalue(elt(env, 1)); // !:bprec!:
    {
        fn = elt(env, 2); // exp!:
        return (*qfn2(fn))(qenv(fn), v0064, v0037);
    }
}



// Code for simpsqrt2

static LispObject CC_simpsqrt2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0120, v0092;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpsqrt2");
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
    v0120 = stack[0];
    fn = elt(env, 2); // minusf
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    if (v0120 == nil) goto v0156;
    v0092 = stack[0];
    v0120 = (LispObject)-15; // -1
    fn = elt(env, 3); // iequal
    v0120 = (*qfn2(fn))(qenv(fn), v0092, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    if (v0120 == nil) goto v0041;
    v0120 = qvalue(elt(env, 1)); // gaussiani
    { popv(2); return onevalue(v0120); }

v0041:
    v0120 = stack[0];
    fn = elt(env, 4); // negf
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0092 = v0120;
    v0120 = v0092;
    if (is_number(v0120)) goto v0066;
    v0120 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // simpsqrt3
        return (*qfn1(fn))(qenv(fn), v0120);
    }

v0066:
    stack[0] = qvalue(elt(env, 1)); // gaussiani
    v0120 = v0092;
    fn = elt(env, 5); // simpsqrt3
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    {
        LispObject v0080 = stack[0];
        popv(2);
        fn = elt(env, 6); // multf
        return (*qfn2(fn))(qenv(fn), v0080, v0120);
    }

v0156:
    v0120 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // simpsqrt3
        return (*qfn1(fn))(qenv(fn), v0120);
    }
// error exit handlers
v0049:
    popv(2);
    return nil;
}



// Code for general!-modular!-difference

static LispObject CC_generalKmodularKdifference(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0091, v0090;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-difference");
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
    v0091 = v0001;
    v0090 = v0000;
// end of prologue
    v0091 = difference2(v0090, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    stack[0] = v0091;
    v0090 = stack[0];
    v0091 = (LispObject)1; // 0
    v0091 = (LispObject)lessp2(v0090, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    v0091 = v0091 ? lisp_true : nil;
    env = stack[-1];
    if (v0091 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0090 = stack[0];
    v0091 = qvalue(elt(env, 1)); // current!-modulus
    v0091 = plus2(v0090, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    stack[0] = v0091;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0051:
    popv(2);
    return nil;
}



// Code for ofsf_smmkatl!-and1

static LispObject CC_ofsf_smmkatlKand1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0193, v0194, v0146;
    LispObject fn;
    LispObject v0097, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-and1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0097 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smmkatl-and1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0097;
    stack[0] = v0001;
    stack[-6] = v0000;
// end of prologue
    v0193 = stack[0];
    v0194 = qcar(v0193);
    v0193 = (LispObject)17; // 1
    v0193 = cons(v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    stack[-7] = v0193;
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    stack[-4] = v0193;
    goto v0021;

v0021:
    v0193 = stack[-4];
    if (v0193 == nil) goto v0052;
    v0193 = stack[-4];
    v0193 = qcar(v0193);
    stack[0] = v0193;
    v0193 = stack[0];
    v0194 = qcar(v0193);
    v0193 = stack[-5];
    if (equal(v0194, v0193)) goto v0080;
    v0193 = nil;
    goto v0090;

v0090:
    stack[-3] = v0193;
    v0193 = stack[-3];
    fn = elt(env, 4); // lastpair
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    stack[-2] = v0193;
    v0193 = stack[-4];
    v0193 = qcdr(v0193);
    stack[-4] = v0193;
    v0193 = stack[-2];
    if (!consp(v0193)) goto v0021;
    else goto v0022;

v0022:
    v0193 = stack[-4];
    if (v0193 == nil) { LispObject res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v0193 = stack[-4];
    v0193 = qcar(v0193);
    stack[0] = v0193;
    v0193 = stack[0];
    v0194 = qcar(v0193);
    v0193 = stack[-5];
    if (equal(v0194, v0193)) goto v0154;
    v0193 = nil;
    goto v0009;

v0009:
    v0193 = Lrplacd(nil, stack[-1], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    v0193 = stack[-2];
    fn = elt(env, 4); // lastpair
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    stack[-2] = v0193;
    v0193 = stack[-4];
    v0193 = qcdr(v0193);
    stack[-4] = v0193;
    goto v0022;

v0154:
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0194 = qcar(v0193);
    v0193 = elt(env, 2); // (lessp greaterp)
    v0193 = Lmemq(nil, v0194, v0193);
    if (v0193 == nil) goto v0196;
    v0193 = stack[-6];
    v0146 = qcdr(v0193);
    v0193 = stack[0];
    v0194 = qcdr(v0193);
    v0193 = stack[-7];
    fn = elt(env, 5); // ofsf_smmkat!-and2
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0146, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    v0194 = v0193;
    if (v0193 == nil) goto v0196;
    v0193 = v0194;
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    goto v0009;

v0196:
    v0146 = elt(env, 3); // and
    v0193 = stack[0];
    v0194 = qcdr(v0193);
    v0193 = stack[-7];
    fn = elt(env, 6); // ofsf_entry2at
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0146, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    goto v0009;

v0080:
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0194 = qcar(v0193);
    v0193 = elt(env, 2); // (lessp greaterp)
    v0193 = Lmemq(nil, v0194, v0193);
    if (v0193 == nil) goto v0074;
    v0193 = stack[-6];
    v0146 = qcdr(v0193);
    v0193 = stack[0];
    v0194 = qcdr(v0193);
    v0193 = stack[-7];
    fn = elt(env, 5); // ofsf_smmkat!-and2
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0146, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    v0194 = v0193;
    if (v0193 == nil) goto v0074;
    v0193 = v0194;
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    goto v0090;

v0074:
    v0146 = elt(env, 3); // and
    v0193 = stack[0];
    v0194 = qcdr(v0193);
    v0193 = stack[-7];
    fn = elt(env, 6); // ofsf_entry2at
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0146, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-8];
    goto v0090;

v0052:
    v0193 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0193); }
// error exit handlers
v0195:
    popv(9);
    return nil;
}



// Code for sfchk

static LispObject CC_sfchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfchk");
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
    v0065 = stack[0];
    fn = elt(env, 1); // sfp
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    if (v0065 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0065 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // prepf
        return (*qfn1(fn))(qenv(fn), v0065);
    }
// error exit handlers
v0054:
    popv(2);
    return nil;
}



// Code for depend!-sq

static LispObject CC_dependKsq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0020, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depend-sq");
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
    v0020 = stack[-1];
    v0060 = qcar(v0020);
    v0020 = stack[0];
    fn = elt(env, 1); // depend!-f
    v0020 = (*qfn2(fn))(qenv(fn), v0060, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    if (!(v0020 == nil)) { popv(3); return onevalue(v0020); }
    v0020 = stack[-1];
    v0060 = qcdr(v0020);
    v0020 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // depend!-f
        return (*qfn2(fn))(qenv(fn), v0060, v0020);
    }
// error exit handlers
v0052:
    popv(3);
    return nil;
}



// Code for mri_simplfloor1

static LispObject CC_mri_simplfloor1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0013, v0119;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_simplfloor1");
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
    v0013 = stack[-1];
    if (!consp(v0013)) goto v0065;
    v0013 = stack[-1];
    v0013 = qcar(v0013);
    v0013 = (consp(v0013) ? nil : lisp_true);
    goto v0063;

v0063:
    if (!(v0013 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0013 = stack[-1];
    v0013 = qcar(v0013);
    v0013 = qcdr(v0013);
    fn = elt(env, 2); // mri_simplfloor
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    stack[0] = v0013;
    v0013 = stack[-1];
    v0013 = qcdr(v0013);
    fn = elt(env, 2); // mri_simplfloor
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    stack[-2] = v0013;
    v0013 = stack[-1];
    v0013 = qcar(v0013);
    v0013 = qcar(v0013);
    v0013 = qcar(v0013);
    fn = elt(env, 3); // mri_irsplit
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0119 = v0013;
    v0119 = qcar(v0119);
    v0013 = qcdr(v0013);
    fn = elt(env, 4); // addf
    v0119 = (*qfn2(fn))(qenv(fn), v0119, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0013 = stack[-1];
    v0013 = qcar(v0013);
    v0013 = qcar(v0013);
    v0013 = qcdr(v0013);
    fn = elt(env, 5); // exptf
    v0013 = (*qfn2(fn))(qenv(fn), v0119, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    fn = elt(env, 6); // multf
    v0119 = (*qfn2(fn))(qenv(fn), stack[0], v0013);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0013 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(qenv(fn), v0119, v0013);
    }

v0065:
    v0013 = qvalue(elt(env, 1)); // t
    goto v0063;
// error exit handlers
v0107:
    popv(4);
    return nil;
}



// Code for ctx_get

static LispObject CC_ctx_get(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0018, v0016, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ctx_get");
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
    v0018 = v0000;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 2); // ctx_ial
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    v0082 = v0018;
    goto v0064;

v0064:
    v0018 = v0082;
    if (v0018 == nil) { LispObject res = stack[-1]; popv(2); return onevalue(res); }
    v0018 = stack[-1];
    if (!(v0018 == nil)) { LispObject res = stack[-1]; popv(2); return onevalue(res); }
    v0018 = v0082;
    v0018 = qcar(v0018);
    v0016 = qcar(v0018);
    v0018 = stack[0];
    if (!(v0016 == v0018)) goto v0021;
    v0018 = v0082;
    v0018 = qcar(v0018);
    v0018 = qcdr(v0018);
    stack[-1] = v0018;
    goto v0021;

v0021:
    v0018 = v0082;
    v0018 = qcdr(v0018);
    v0082 = v0018;
    goto v0064;
// error exit handlers
v0108:
    popv(2);
    return nil;
}



// Code for ezgcd!-comfac

static LispObject CC_ezgcdKcomfac(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0152, v0199, v0200;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ezgcd-comfac");
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
    v0152 = stack[-1];
    if (!consp(v0152)) goto v0057;
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = (consp(v0152) ? nil : lisp_true);
    goto v0103;

v0103:
    if (v0152 == nil) goto v0003;
    stack[0] = qvalue(elt(env, 2)); // nil
    v0152 = stack[-1];
    fn = elt(env, 3); // poly!-abs
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    {
        LispObject v0172 = stack[0];
        popv(4);
        return cons(v0172, v0152);
    }

v0003:
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    if (v0152 == nil) goto v0084;
    stack[-2] = nil;
    v0200 = nil;
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = qcar(v0152);
    v0152 = qcar(v0152);
    stack[0] = v0152;
    goto v0124;

v0124:
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = qcar(v0152);
    v0199 = qcar(v0152);
    v0152 = stack[0];
    if (equal(v0199, v0152)) goto v0077;
    v0152 = qvalue(elt(env, 2)); // nil
    goto v0079;

v0079:
    if (v0152 == nil) goto v0201;
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = qcdr(v0152);
    v0199 = v0200;
    v0152 = cons(v0152, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-3];
    v0200 = v0152;
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    stack[-1] = v0152;
    goto v0124;

v0201:
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = qcar(v0152);
    v0199 = qcar(v0152);
    v0152 = stack[0];
    if (equal(v0199, v0152)) goto v0202;
    v0152 = stack[-1];
    v0199 = v0200;
    v0152 = cons(v0152, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-3];
    v0200 = v0152;
    goto v0150;

v0150:
    stack[0] = stack[-2];
    v0152 = v0200;
    fn = elt(env, 4); // gcdlist
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    {
        LispObject v0170 = stack[0];
        popv(4);
        return cons(v0170, v0152);
    }

v0202:
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = qcdr(v0152);
    v0199 = v0200;
    v0152 = cons(v0152, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-3];
    v0200 = v0152;
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    if (v0152 == nil) goto v0180;
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    v0199 = v0200;
    v0152 = cons(v0152, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-3];
    v0200 = v0152;
    goto v0150;

v0180:
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = qcar(v0152);
    stack[-2] = v0152;
    goto v0150;

v0077:
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    if (!consp(v0152)) goto v0188;
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    v0152 = (consp(v0152) ? nil : lisp_true);
    goto v0169;

v0169:
    v0152 = (v0152 == nil ? lisp_true : nil);
    goto v0079;

v0188:
    v0152 = qvalue(elt(env, 1)); // t
    goto v0169;

v0084:
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    stack[0] = qcar(v0152);
    v0152 = stack[-1];
    v0152 = qcar(v0152);
    v0152 = qcdr(v0152);
    fn = elt(env, 3); // poly!-abs
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    {
        LispObject v0203 = stack[0];
        popv(4);
        return cons(v0203, v0152);
    }

v0057:
    v0152 = qvalue(elt(env, 1)); // t
    goto v0103;
// error exit handlers
v0175:
    popv(4);
    return nil;
}



// Code for addexptsdf

static LispObject CC_addexptsdf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0124, v0163;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addexptsdf");
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
    goto v0135;

v0135:
    v0124 = stack[-1];
    if (v0124 == nil) goto v0036;
    v0124 = stack[0];
    if (v0124 == nil) goto v0066;
    v0124 = stack[-1];
    v0163 = qcar(v0124);
    v0124 = stack[0];
    v0124 = qcar(v0124);
    fn = elt(env, 3); // exptplus
    v0163 = (*qfn2(fn))(qenv(fn), v0163, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    v0124 = stack[-2];
    v0124 = cons(v0163, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    stack[-2] = v0124;
    v0124 = stack[-1];
    v0124 = qcdr(v0124);
    stack[-1] = v0124;
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    stack[0] = v0124;
    goto v0135;

v0066:
    stack[0] = stack[-2];
    v0124 = elt(env, 2); // "Y too long"
    fn = elt(env, 4); // interr
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    {
        LispObject v0014 = stack[0];
        popv(4);
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(qenv(fn), v0014, v0124);
    }

v0036:
    v0124 = stack[0];
    if (v0124 == nil) goto v0087;
    stack[0] = stack[-2];
    v0124 = elt(env, 1); // "X too long"
    fn = elt(env, 4); // interr
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    {
        LispObject v0089 = stack[0];
        popv(4);
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(qenv(fn), v0089, v0124);
    }

v0087:
    v0124 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); // nreverse
        return (*qfn1(fn))(qenv(fn), v0124);
    }
// error exit handlers
v0119:
    popv(4);
    return nil;
}



// Code for den

static LispObject CC_den(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0065, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for den");
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
    v0065 = v0000;
// end of prologue
    fn = elt(env, 1); // simp!*
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[0];
    v0087 = qcdr(v0065);
    v0065 = (LispObject)17; // 1
    v0065 = cons(v0087, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // mk!*sq
        return (*qfn1(fn))(qenv(fn), v0065);
    }
// error exit handlers
v0054:
    popv(1);
    return nil;
}



// Code for !:log2

static LispObject CC_Tlog2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0082, v0083;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :log2");
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
    v0083 = elt(env, 0); // !:log2
    v0082 = stack[0];
    fn = elt(env, 3); // get!:const
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[-1] = v0082;
    v0083 = stack[-1];
    v0082 = elt(env, 1); // not_found
    if (!(v0083 == v0082)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0083 = qvalue(elt(env, 2)); // bftwo!*
    v0082 = stack[0];
    fn = elt(env, 4); // log!:
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[-1] = v0082;
    v0083 = elt(env, 0); // !:log2
    v0082 = stack[-1];
    fn = elt(env, 5); // save!:const
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0027:
    popv(3);
    return nil;
}



// Code for exptbf

static LispObject CC_exptbf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0092, v0048;
    LispObject fn;
    LispObject v0097, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "exptbf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0097 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptbf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0097;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0135:
    v0092 = stack[-1];
    v0092 = Levenp(nil, v0092);
    env = stack[-3];
    if (!(v0092 == nil)) goto v0021;
    v0048 = stack[0];
    v0092 = stack[-2];
    fn = elt(env, 1); // csl_timbf
    v0092 = (*qfn2(fn))(qenv(fn), v0048, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    stack[0] = v0092;
    goto v0021;

v0021:
    v0048 = stack[-1];
    v0092 = (LispObject)-15; // -1
    fn = elt(env, 2); // lshift
    v0092 = (*qfn2(fn))(qenv(fn), v0048, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    stack[-1] = v0092;
    v0048 = stack[-1];
    v0092 = (LispObject)1; // 0
    if (v0048 == v0092) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0048 = stack[-2];
    v0092 = stack[-2];
    fn = elt(env, 1); // csl_timbf
    v0092 = (*qfn2(fn))(qenv(fn), v0048, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    stack[-2] = v0092;
    goto v0135;
// error exit handlers
v0093:
    popv(4);
    return nil;
}



// Code for mk_names_map_2

static LispObject CC_mk_names_map_2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0081, v0093;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_names_map_2");
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
    v0081 = v0000;
// end of prologue
    v0093 = v0081;
    v0093 = qcar(v0093);
    v0081 = qcdr(v0081);
    v0081 = Lappend(nil, v0093, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    stack[-3] = v0081;
    v0081 = stack[-3];
    if (v0081 == nil) goto v0115;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    stack[-1] = v0081;
    stack[-2] = v0081;
    goto v0103;

v0103:
    v0081 = stack[-3];
    v0081 = qcdr(v0081);
    stack[-3] = v0081;
    v0081 = stack[-3];
    if (v0081 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    v0081 = Lrplacd(nil, stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    v0081 = stack[-1];
    v0081 = qcdr(v0081);
    stack[-1] = v0081;
    goto v0103;

v0115:
    v0081 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0081); }
// error exit handlers
v0095:
    popv(5);
    return nil;
}



// Code for mo_support

static LispObject CC_mo_support(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0027;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_support");
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
    stack[-3] = nil;
    v0108 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 3); // ring_names
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    stack[-1] = v0108;
    goto v0057;

v0057:
    v0108 = stack[-1];
    if (v0108 == nil) goto v0103;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    stack[0] = v0108;
    v0108 = stack[0];
    fn = elt(env, 4); // mo_from_a
    v0027 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    v0108 = stack[-2];
    fn = elt(env, 5); // mo_divides!?
    v0108 = (*qfn2(fn))(qenv(fn), v0027, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    if (v0108 == nil) goto v0041;
    v0027 = stack[0];
    v0108 = stack[-3];
    v0108 = cons(v0027, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    stack[-3] = v0108;
    goto v0041;

v0041:
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[-1] = v0108;
    goto v0057;

v0103:
    v0108 = stack[-3];
        popv(5);
        return Lnreverse(nil, v0108);
// error exit handlers
v0049:
    popv(5);
    return nil;
}



// Code for dv_skel2factor

static LispObject CC_dv_skel2factor(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0012, v0114;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_skel2factor");
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
    push(nil);
// copy arguments values to proper place
    v0114 = v0001;
    stack[-4] = v0000;
// end of prologue
    v0012 = stack[-4];
    v0012 = qcdr(v0012);
    if (v0012 == nil) goto v0036;
    v0012 = stack[-4];
    v0012 = qcdr(v0012);
    v0012 = Lsublis(nil, v0114, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    stack[-5] = v0012;
    v0012 = stack[-5];
    fn = elt(env, 2); // st_ad_numsorttree
    v0012 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    stack[-5] = v0012;
    v0012 = stack[-5];
    v0012 = qcdr(v0012);
    fn = elt(env, 3); // st_flatten
    v0012 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    stack[-3] = v0012;
    v0012 = stack[-3];
    if (v0012 == nil) goto v0050;
    v0012 = stack[-3];
    v0012 = qcar(v0012);
    fn = elt(env, 4); // dv_ind2var
    v0012 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0012 = ncons(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    stack[-1] = v0012;
    stack[-2] = v0012;
    goto v0084;

v0084:
    v0012 = stack[-3];
    v0012 = qcdr(v0012);
    stack[-3] = v0012;
    v0012 = stack[-3];
    if (v0012 == nil) goto v0049;
    stack[0] = stack[-1];
    v0012 = stack[-3];
    v0012 = qcar(v0012);
    fn = elt(env, 4); // dv_ind2var
    v0012 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0012 = ncons(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0012 = Lrplacd(nil, stack[0], v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0012 = stack[-1];
    v0012 = qcdr(v0012);
    stack[-1] = v0012;
    goto v0084;

v0049:
    v0012 = stack[-2];
    goto v0014;

v0014:
    v0114 = stack[-5];
    stack[0] = qcar(v0114);
    v0114 = stack[-4];
    v0114 = qcar(v0114);
    fn = elt(env, 5); // dv_skel2factor1
    v0012 = (*qfn2(fn))(qenv(fn), v0114, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    {
        LispObject v0059 = stack[0];
        popv(7);
        return cons(v0059, v0012);
    }

v0050:
    v0012 = qvalue(elt(env, 1)); // nil
    goto v0014;

v0036:
    v0012 = stack[-4];
    v0012 = qcar(v0012);
    { popv(7); return onevalue(v0012); }
// error exit handlers
v0122:
    popv(7);
    return nil;
}



// Code for add!-factor

static LispObject CC_addKfactor(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0162, v0045, v0013;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add-factor");
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
    v0162 = stack[0];
    v0162 = Lconsp(nil, v0162);
    env = stack[-2];
    if (v0162 == nil) goto v0066;
    v0045 = stack[-1];
    v0162 = stack[0];
    v0162 = qcar(v0162);
    v0162 = qcar(v0162);
    v0162 = (LispObject)greaterp2(v0045, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0162 = v0162 ? lisp_true : nil;
    env = stack[-2];
    if (v0162 == nil) goto v0061;
    v0162 = qvalue(elt(env, 1)); // nil
    goto v0004;

v0004:
    v0045 = v0162;
    v0162 = v0045;
    if (v0162 == nil) goto v0160;
    stack[-1] = v0045;
    v0162 = v0045;
    v0162 = qcdr(v0162);
    v0162 = add1(v0162);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0162 = Lrplacd(nil, stack[-1], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }

v0160:
    v0013 = stack[-1];
    v0045 = (LispObject)17; // 1
    v0162 = stack[0];
    popv(3);
    return acons(v0013, v0045, v0162);

v0061:
    v0045 = stack[-1];
    v0162 = stack[0];
    v0162 = Lassoc(nil, v0045, v0162);
    goto v0004;

v0066:
    v0162 = qvalue(elt(env, 1)); // nil
    goto v0004;
// error exit handlers
v0089:
    popv(3);
    return nil;
}



// Code for remainder!-mod!-p

static LispObject CC_remainderKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0093, v0094, v0168;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remainder-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0093 = v0001;
    v0168 = v0000;
// end of prologue
    v0094 = v0093;
    if (v0094 == nil) goto v0003;
    v0094 = v0093;
    if (!consp(v0094)) goto v0087;
    v0094 = v0093;
    v0094 = qcar(v0094);
    v0094 = (consp(v0094) ? nil : lisp_true);
    goto v0065;

v0065:
    if (v0094 == nil) goto v0064;
    v0093 = qvalue(elt(env, 3)); // nil
    return onevalue(v0093);

v0064:
    v0094 = v0168;
    if (!consp(v0094)) goto v0052;
    v0094 = v0168;
    v0094 = qcar(v0094);
    v0094 = (consp(v0094) ? nil : lisp_true);
    goto v0062;

v0062:
    if (!(v0094 == nil)) return onevalue(v0168);
    v0094 = v0093;
    v0093 = qcar(v0093);
    v0093 = qcar(v0093);
    v0093 = qcar(v0093);
    {
        fn = elt(env, 4); // xremainder!-mod!-p
        return (*qfnn(fn))(qenv(fn), 3, v0168, v0094, v0093);
    }

v0052:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0062;

v0087:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0065;

v0003:
    v0093 = elt(env, 1); // "B=0 IN REMAINDER-MOD-P"
    {
        fn = elt(env, 5); // errorf
        return (*qfn1(fn))(qenv(fn), v0093);
    }
}



// Code for lengthn

static LispObject CC_lengthn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0096;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthn");
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
    v0096 = stack[0];
    if (v0096 == nil) goto v0004;
    v0096 = stack[0];
    v0096 = qcar(v0096);
    if (is_number(v0096)) goto v0065;
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    v0096 = CC_lengthn(env, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    popv(3);
    return add1(v0096);

v0065:
    v0096 = stack[0];
    v0096 = qcar(v0096);
    stack[-1] = sub1(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    v0096 = CC_lengthn(env, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    {
        LispObject v0066 = stack[-1];
        popv(3);
        return plus2(v0066, v0096);
    }

v0004:
    v0096 = (LispObject)1; // 0
    { popv(3); return onevalue(v0096); }
// error exit handlers
v0015:
    popv(3);
    return nil;
}



// Code for spmatlength

static LispObject CC_spmatlength(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0106, v0107, v0192, v0169;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spmatlength");
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
    v0192 = v0000;
// end of prologue
    v0106 = v0192;
    v0106 = Lconsp(nil, v0106);
    env = stack[-2];
    if (v0106 == nil) goto v0065;
    v0106 = v0192;
    goto v0103;

v0103:
    v0107 = v0106;
    v0107 = qcdr(v0107);
    v0107 = qcdr(v0107);
    v0107 = qcar(v0107);
    v0107 = qcdr(v0107);
    v0169 = v0107;
    v0107 = v0106;
    v0106 = elt(env, 1); // sparsemat
    if (!consp(v0107)) goto v0050;
    v0107 = qcar(v0107);
    if (!(v0107 == v0106)) goto v0050;
    v0107 = elt(env, 5); // list
    v0106 = v0169;
    v0106 = qcar(v0106);
    v0192 = v0169;
    v0192 = qcdr(v0192);
    v0192 = qcar(v0192);
    popv(3);
    return list3(v0107, v0106, v0192);

v0050:
    stack[-1] = elt(env, 2); // matrix
    stack[0] = (LispObject)33; // 2
    v0107 = elt(env, 3); // "Matrix"
    v0106 = elt(env, 4); // "not set"
    v0106 = list3(v0107, v0192, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    fn = elt(env, 6); // rerror
    v0106 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0106);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    v0106 = nil;
    { popv(3); return onevalue(v0106); }

v0065:
    v0106 = v0192;
    if (!symbolp(v0106)) v0106 = nil;
    else { v0106 = qfastgets(v0106);
           if (v0106 != nil) { v0106 = elt(v0106, 4); // avalue
#ifdef RECORD_GET
             if (v0106 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0106 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0106 == SPID_NOPROP) v0106 = nil; }}
#endif
    v0106 = qcdr(v0106);
    v0106 = qcar(v0106);
    goto v0103;
// error exit handlers
v0029:
    popv(3);
    return nil;
}



// Code for groebcplistsort

static LispObject CC_groebcplistsort(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0053, v0096;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebcplistsort");
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
    v0053 = v0000;
// end of prologue
    v0096 = qvalue(elt(env, 1)); // nil
    stack[0] = v0053;
    goto v0103;

v0103:
    v0053 = stack[0];
    if (v0053 == nil) { popv(2); return onevalue(v0096); }
    v0053 = stack[0];
    v0053 = qcar(v0053);
    fn = elt(env, 2); // groebcplistsortin
    v0053 = (*qfn2(fn))(qenv(fn), v0053, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    v0096 = v0053;
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    stack[0] = v0053;
    goto v0103;
// error exit handlers
v0058:
    popv(2);
    return nil;
}



// Code for maprintla

static LispObject CC_maprintla(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0232, v0233, v0234;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maprintla");
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

v0125:
    v0232 = stack[-2];
    if (v0232 == nil) goto v0064;
    v0232 = stack[-2];
    if (is_number(v0232)) goto v0235;
    v0232 = stack[-2];
    if (!consp(v0232)) goto v0039;
    v0232 = stack[-2];
    v0232 = Lstringp(nil, v0232);
    env = stack[-4];
    if (v0232 == nil) goto v0020;
    v0232 = stack[-2];
    {
        popv(5);
        fn = elt(env, 17); // prin2la
        return (*qfn1(fn))(qenv(fn), v0232);
    }

v0020:
    v0232 = stack[-2];
    v0232 = qcar(v0232);
    if (!consp(v0232)) goto v0027;
    v0232 = stack[-2];
    v0233 = qcar(v0232);
    v0232 = stack[-1];
    stack[-2] = v0233;
    stack[-1] = v0232;
    goto v0125;

v0027:
    v0232 = stack[-2];
    v0233 = qcar(v0232);
    v0232 = elt(env, 2); // laprifn
    v0232 = get(v0233, v0232);
    env = stack[-4];
    stack[-3] = v0232;
    if (v0232 == nil) goto v0147;
    v0232 = stack[-2];
    v0233 = qcar(v0232);
    v0232 = elt(env, 3); // fulla
    v0232 = Lflagp(nil, v0233, v0232);
    env = stack[-4];
    if (v0232 == nil) goto v0042;
    v0232 = qvalue(elt(env, 1)); // nil
    goto v0046;

v0046:
    if (v0232 == nil) goto v0028;
    v0232 = qvalue(elt(env, 5)); // t
    goto v0168;

v0168:
    if (!(v0232 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0147:
    v0232 = stack[-2];
    v0233 = qcar(v0232);
    v0232 = elt(env, 6); // indexed
    v0232 = get(v0233, v0232);
    env = stack[-4];
    stack[-3] = v0232;
    if (v0232 == nil) goto v0024;
    v0232 = stack[-2];
    v0234 = qcar(v0232);
    v0232 = stack[-2];
    v0233 = qcdr(v0232);
    v0232 = stack[-3];
    {
        popv(5);
        fn = elt(env, 18); // prinidop
        return (*qfnn(fn))(qenv(fn), 3, v0234, v0233, v0232);
    }

v0024:
    v0232 = stack[-2];
    v0232 = qcar(v0232);
    if (!symbolp(v0232)) v0232 = nil;
    else { v0232 = qfastgets(v0232);
           if (v0232 != nil) { v0232 = elt(v0232, 23); // infix
#ifdef RECORD_GET
             if (v0232 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0232 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0232 == SPID_NOPROP) v0232 = nil; }}
#endif
    stack[-3] = v0232;
    if (v0232 == nil) goto v0174;
    v0233 = stack[-3];
    v0232 = stack[-1];
    v0232 = (LispObject)greaterp2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    v0232 = v0232 ? lisp_true : nil;
    env = stack[-4];
    stack[-1] = v0232;
    v0232 = stack[-1];
    if (v0232 == nil) goto v0159;
    v0232 = qvalue(elt(env, 1)); // nil
    goto v0237;

v0237:
    if (v0232 == nil) goto v0128;
    v0232 = qvalue(elt(env, 5)); // t
    stack[-1] = v0232;
    goto v0128;

v0128:
    v0232 = stack[-1];
    if (!(v0232 == nil)) goto v0238;
    v0232 = elt(env, 14); // !(
    fn = elt(env, 19); // prinlatom
    v0232 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    goto v0238;

v0238:
    v0232 = stack[-2];
    v0234 = qcar(v0232);
    v0233 = stack[-3];
    v0232 = stack[-2];
    v0232 = qcdr(v0232);
    fn = elt(env, 20); // inprinla
    v0232 = (*qfnn(fn))(qenv(fn), 3, v0234, v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0232 = stack[-1];
    if (!(v0232 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0232 = elt(env, 15); // !)
    fn = elt(env, 19); // prinlatom
    v0232 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0159:
    v0232 = stack[-2];
    v0233 = qcar(v0232);
    v0232 = elt(env, 13); // equal
    v0232 = (v0233 == v0232 ? lisp_true : nil);
    goto v0237;

v0174:
    v0232 = stack[-2];
    v0233 = qcar(v0232);
    v0232 = elt(env, 7); // !:rd!:
    if (v0233 == v0232) goto v0153;
    v0232 = stack[-2];
    v0232 = qcar(v0232);
    fn = elt(env, 21); // oprinla
    v0232 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0232 = stack[-2];
    v0234 = qcar(v0232);
    v0232 = stack[-2];
    v0233 = qcdr(v0232);
    v0232 = stack[-1];
    fn = elt(env, 22); // prinpopargs
    v0232 = (*qfnn(fn))(qenv(fn), 3, v0234, v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0153:
    stack[-1] = qvalue(elt(env, 8)); // !*nat
    qvalue(elt(env, 8)) = nil; // !*nat
    v0232 = stack[-2];
    v0232 = qcdr(v0232);
    v0232 = Lfloatp(nil, v0232);
    env = stack[-4];
    if (v0232 == nil) goto v0186;
    v0232 = stack[-2];
    v0232 = qcdr(v0232);
    v0232 = Llengthc(nil, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    goto v0183;

v0183:
    stack[0] = v0232;
    v0233 = qvalue(elt(env, 9)); // ncharspr!*
    v0232 = stack[0];
    v0233 = plus2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    v0232 = qvalue(elt(env, 10)); // laline!*
    v0232 = (LispObject)greaterp2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    v0232 = v0232 ? lisp_true : nil;
    env = stack[-4];
    if (v0232 == nil) goto v0240;
    v0232 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    v0232 = stack[0];
    qvalue(elt(env, 9)) = v0232; // ncharspr!*
    goto v0241;

v0241:
    v0232 = qvalue(elt(env, 11)); // orig!*
    qvalue(elt(env, 12)) = v0232; // posn!*
    v0232 = stack[-2];
    fn = elt(env, 23); // rd!:prin
    v0232 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    v0232 = nil;
    qvalue(elt(env, 8)) = stack[-1]; // !*nat
    { popv(5); return onevalue(v0232); }

v0240:
    v0233 = qvalue(elt(env, 9)); // ncharspr!*
    v0232 = stack[0];
    v0232 = plus2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    qvalue(elt(env, 9)) = v0232; // ncharspr!*
    goto v0241;

v0186:
    v0232 = stack[-2];
    v0232 = qcdr(v0232);
    v0232 = qcar(v0232);
    stack[0] = Llengthc(nil, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    v0232 = stack[-2];
    v0232 = qcdr(v0232);
    v0232 = qcdr(v0232);
    v0233 = Llengthc(nil, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    v0232 = (LispObject)81; // 5
    v0232 = plus2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    v0232 = plus2(stack[0], v0232);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-4];
    goto v0183;

v0028:
    v0232 = stack[-2];
    v0233 = qcar(v0232);
    v0232 = elt(env, 3); // fulla
    v0232 = Lflagp(nil, v0233, v0232);
    env = stack[-4];
    if (v0232 == nil) goto v0112;
    stack[0] = stack[-3];
    v0233 = stack[-2];
    v0232 = stack[-1];
    v0232 = list2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    fn = elt(env, 24); // apply
    v0233 = (*qfn2(fn))(qenv(fn), stack[0], v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0232 = elt(env, 4); // failed
    v0232 = (v0233 == v0232 ? lisp_true : nil);
    v0232 = (v0232 == nil ? lisp_true : nil);
    goto v0168;

v0112:
    v0232 = qvalue(elt(env, 1)); // nil
    goto v0168;

v0042:
    stack[0] = stack[-3];
    v0232 = stack[-2];
    v0233 = qcdr(v0232);
    v0232 = stack[-1];
    v0232 = list2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    fn = elt(env, 24); // apply
    v0233 = (*qfn2(fn))(qenv(fn), stack[0], v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0232 = elt(env, 4); // failed
    v0232 = (v0233 == v0232 ? lisp_true : nil);
    v0232 = (v0232 == nil ? lisp_true : nil);
    goto v0046;

v0039:
    v0232 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); // prinlatom
        return (*qfn1(fn))(qenv(fn), v0232);
    }

v0235:
    v0233 = stack[-2];
    v0232 = (LispObject)1; // 0
    v0232 = (LispObject)lessp2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    v0232 = v0232 ? lisp_true : nil;
    env = stack[-4];
    if (v0232 == nil) goto v0242;
    v0233 = stack[-1];
    v0232 = elt(env, 16); // minus
    if (!symbolp(v0232)) v0232 = nil;
    else { v0232 = qfastgets(v0232);
           if (v0232 != nil) { v0232 = elt(v0232, 23); // infix
#ifdef RECORD_GET
             if (v0232 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0232 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0232 == SPID_NOPROP) v0232 = nil; }}
#endif
    v0232 = (LispObject)lessp2(v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    v0232 = v0232 ? lisp_true : nil;
    env = stack[-4];
    goto v0243;

v0243:
    if (v0232 == nil) goto v0244;
    v0232 = stack[-2];
    {
        popv(5);
        fn = elt(env, 17); // prin2la
        return (*qfn1(fn))(qenv(fn), v0232);
    }

v0244:
    v0232 = elt(env, 14); // !(
    fn = elt(env, 17); // prin2la
    v0232 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0232 = stack[-2];
    fn = elt(env, 17); // prin2la
    v0232 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-4];
    v0232 = elt(env, 15); // !)
    fn = elt(env, 17); // prin2la
    v0232 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0242:
    v0232 = qvalue(elt(env, 5)); // t
    goto v0243;

v0064:
    v0232 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0232); }
// error exit handlers
v0239:
    env = stack[-4];
    qvalue(elt(env, 8)) = stack[-1]; // !*nat
    popv(5);
    return nil;
v0236:
    popv(5);
    return nil;
}



// Code for !:log10

static LispObject CC_Tlog10(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0082, v0083;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :log10");
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
    v0083 = elt(env, 0); // !:log10
    v0082 = stack[0];
    fn = elt(env, 3); // get!:const
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[-1] = v0082;
    v0083 = stack[-1];
    v0082 = elt(env, 1); // not_found
    if (!(v0083 == v0082)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0083 = qvalue(elt(env, 2)); // bften!*
    v0082 = stack[0];
    fn = elt(env, 4); // log!:
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[-1] = v0082;
    v0083 = elt(env, 0); // !:log10
    v0082 = stack[-1];
    fn = elt(env, 5); // save!:const
    v0082 = (*qfn2(fn))(qenv(fn), v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0027:
    popv(3);
    return nil;
}



// Code for find_triangl_coeff

static LispObject CC_find_triangl_coeff(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0039, v0040, v0115, v0041;
    LispObject fn;
    LispObject v0097, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "find_triangl_coeff");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0097 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find_triangl_coeff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0039 = v0097;
    v0040 = v0001;
    v0115 = v0000;
// end of prologue
    v0041 = v0115;
    v0115 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // find_triangle_coeff
        return (*qfnn(fn))(qenv(fn), 4, v0041, v0115, v0040, v0039);
    }
}



// Code for sub01

static LispObject CC_sub01(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0016, v0082, v0083;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sub01");
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
    v0083 = nil;
    goto v0135;

v0135:
    v0016 = stack[0];
    if (v0016 == nil) goto v0050;
    v0016 = stack[0];
    v0082 = qcar(v0016);
    v0016 = stack[-1];
    if (equal(v0082, v0016)) goto v0115;
    v0016 = (LispObject)1; // 0
    goto v0054;

v0054:
    v0082 = v0083;
    v0016 = cons(v0016, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0083 = v0016;
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    stack[0] = v0016;
    goto v0135;

v0115:
    v0016 = (LispObject)17; // 1
    goto v0054;

v0050:
    v0016 = v0083;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0016);
    }
// error exit handlers
v0027:
    popv(3);
    return nil;
}



// Code for dfdeg

static LispObject CC_dfdeg(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0051, v0017;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0017 = v0001;
    v0051 = v0000;
// end of prologue
    v0017 = Lmember(nil, v0017, v0051);
    v0051 = v0017;
    if (v0017 == nil) goto v0003;
    v0017 = v0051;
    v0017 = qcdr(v0017);
    if (v0017 == nil) goto v0115;
    v0017 = v0051;
    v0017 = qcdr(v0017);
    v0017 = qcar(v0017);
    v0017 = integerp(v0017);
    v0017 = (v0017 == nil ? lisp_true : nil);
    goto v0040;

v0040:
    if (v0017 == nil) goto v0015;
    v0051 = (LispObject)17; // 1
    return onevalue(v0051);

v0015:
    v0051 = qcdr(v0051);
    v0051 = qcar(v0051);
    return onevalue(v0051);

v0115:
    v0017 = qvalue(elt(env, 1)); // t
    goto v0040;

v0003:
    v0051 = (LispObject)1; // 0
    return onevalue(v0051);
}



// Code for replace!-next

static LispObject CC_replaceKnext(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0049, v0080, v0081, v0093;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replace-next");
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
    goto v0135;

v0135:
    v0049 = stack[-1];
    if (v0049 == nil) goto v0036;
    v0049 = stack[-1];
    v0049 = qcar(v0049);
    v0093 = qcar(v0049);
    v0049 = stack[-1];
    v0049 = qcar(v0049);
    v0049 = qcdr(v0049);
    v0081 = qcar(v0049);
    v0049 = stack[-1];
    v0049 = qcar(v0049);
    v0049 = qcdr(v0049);
    v0049 = qcdr(v0049);
    v0080 = qcar(v0049);
    v0049 = stack[0];
    v0049 = qcar(v0049);
    v0080 = list4(v0093, v0081, v0080, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    v0049 = stack[-2];
    v0049 = cons(v0080, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    stack[-2] = v0049;
    v0049 = stack[-1];
    v0049 = qcdr(v0049);
    stack[-1] = v0049;
    v0049 = stack[0];
    v0049 = qcdr(v0049);
    stack[0] = v0049;
    goto v0135;

v0036:
    v0049 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0049);
    }
// error exit handlers
v0109:
    popv(4);
    return nil;
}



// Code for mk!+inner!+product

static LispObject CC_mkLinnerLproduct(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0167, v0179;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+inner+product");
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
    stack[-1] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0167 = stack[-3];
    fn = elt(env, 6); // get!+vec!+dim
    stack[0] = (*qfn1(fn))(qenv(fn), v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0167 = stack[-1];
    fn = elt(env, 6); // get!+vec!+dim
    v0167 = (*qfn1(fn))(qenv(fn), v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    if (equal(stack[0], v0167)) goto v0020;
    v0167 = elt(env, 1); // "Error in Gram_schmidt: each list in input must be the same length."
    fn = elt(env, 7); // rederr
    v0167 = (*qfn1(fn))(qenv(fn), v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    goto v0020;

v0020:
    v0179 = qvalue(elt(env, 2)); // nil
    v0167 = (LispObject)17; // 1
    v0167 = cons(v0179, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    stack[0] = v0167;
    v0167 = qvalue(elt(env, 3)); // !*complex
    if (v0167 == nil) goto v0051;
    v0167 = stack[-1];
    fn = elt(env, 8); // mk!+conjugate!+vec
    v0167 = (*qfn1(fn))(qenv(fn), v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    stack[-4] = v0167;
    goto v0058;

v0058:
    v0167 = (LispObject)17; // 1
    stack[-2] = v0167;
    goto v0080;

v0080:
    v0167 = stack[-3];
    fn = elt(env, 6); // get!+vec!+dim
    v0179 = (*qfn1(fn))(qenv(fn), v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0167 = stack[-2];
    v0167 = difference2(v0179, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0167 = Lminusp(nil, v0167);
    env = stack[-5];
    if (v0167 == nil) goto v0079;
    v0167 = qvalue(elt(env, 4)); // t
    stack[-1] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0167; // !*sub2
    v0167 = stack[0];
    fn = elt(env, 9); // subs2
    v0167 = (*qfn1(fn))(qenv(fn), v0167);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    stack[0] = v0167;
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0079:
    stack[-1] = stack[0];
    v0179 = stack[-3];
    v0167 = stack[-2];
    fn = elt(env, 10); // get!+vec!+entry
    stack[0] = (*qfn2(fn))(qenv(fn), v0179, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0179 = stack[-4];
    v0167 = stack[-2];
    fn = elt(env, 10); // get!+vec!+entry
    v0167 = (*qfn2(fn))(qenv(fn), v0179, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    fn = elt(env, 11); // multsq
    v0167 = (*qfn2(fn))(qenv(fn), stack[0], v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    fn = elt(env, 12); // addsq
    v0167 = (*qfn2(fn))(qenv(fn), stack[-1], v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    stack[0] = v0167;
    v0167 = stack[-2];
    v0167 = add1(v0167);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    stack[-2] = v0167;
    goto v0080;

v0051:
    v0167 = stack[-1];
    stack[-4] = v0167;
    goto v0058;
// error exit handlers
v0031:
    env = stack[-5];
    qvalue(elt(env, 5)) = stack[-1]; // !*sub2
    popv(6);
    return nil;
v0032:
    popv(6);
    return nil;
}



// Code for pasf_lnegrel

static LispObject CC_pasf_lnegrel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0122, v0059, v0167;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_lnegrel");
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
    v0167 = v0000;
// end of prologue
    v0059 = v0167;
    v0122 = elt(env, 1); // equal
    if (v0059 == v0122) goto v0004;
    v0059 = v0167;
    v0122 = elt(env, 2); // neq
    if (v0059 == v0122) goto v0087;
    v0059 = v0167;
    v0122 = elt(env, 3); // leq
    if (v0059 == v0122) goto v0020;
    v0059 = v0167;
    v0122 = elt(env, 5); // lessp
    if (v0059 == v0122) goto v0066;
    v0059 = v0167;
    v0122 = elt(env, 6); // geq
    if (v0059 == v0122) goto v0156;
    v0059 = v0167;
    v0122 = elt(env, 4); // greaterp
    if (v0059 == v0122) goto v0093;
    v0059 = v0167;
    v0122 = elt(env, 7); // cong
    if (v0059 == v0122) goto v0078;
    v0059 = v0167;
    v0122 = elt(env, 8); // ncong
    if (v0059 == v0122) goto v0107;
    v0122 = elt(env, 9); // "pasf_lnegrel: unknown operator"
    v0059 = v0167;
    v0122 = list2(v0122, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(qenv(fn), v0122);
    }

v0107:
    v0122 = elt(env, 7); // cong
    { popv(1); return onevalue(v0122); }

v0078:
    v0122 = elt(env, 8); // ncong
    { popv(1); return onevalue(v0122); }

v0093:
    v0122 = elt(env, 3); // leq
    { popv(1); return onevalue(v0122); }

v0156:
    v0122 = elt(env, 5); // lessp
    { popv(1); return onevalue(v0122); }

v0066:
    v0122 = elt(env, 6); // geq
    { popv(1); return onevalue(v0122); }

v0020:
    v0122 = elt(env, 4); // greaterp
    { popv(1); return onevalue(v0122); }

v0087:
    v0122 = elt(env, 1); // equal
    { popv(1); return onevalue(v0122); }

v0004:
    v0122 = elt(env, 2); // neq
    { popv(1); return onevalue(v0122); }
// error exit handlers
v0179:
    popv(1);
    return nil;
}



// Code for ofsf_pop

static LispObject CC_ofsf_pop(LispObject env,
                         LispObject v0000)
{
    LispObject v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_pop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0000;
// end of prologue
    return onevalue(v0008);
}



// Code for parfool

static LispObject CC_parfool(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0018;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for parfool");
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
    v0017 = stack[0];
    v0017 = qcar(v0017);
    if (v0017 == nil) goto v0004;
    v0017 = stack[0];
    v0017 = qcar(v0017);
    if (!(is_number(v0017))) goto v0090;
    v0017 = stack[0];
    v0018 = qcdr(v0017);
    v0017 = (LispObject)17; // 1
    v0017 = Leqn(nil, v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    if (v0017 == nil) goto v0090;
    v0017 = stack[0];
    v0018 = qcdr(v0017);
    v0017 = (LispObject)1; // 0
    v0017 = (LispObject)lessp2(v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    v0017 = v0017 ? lisp_true : nil;
    env = stack[-1];
    if (v0017 == nil) goto v0090;
    v0017 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0017); }

v0090:
    v0017 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0017); }

v0004:
    v0017 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0017); }
// error exit handlers
v0082:
    popv(2);
    return nil;
}



// Code for dim!<!=deg

static LispObject CC_dimRMdeg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dim<=deg");
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
    v0051 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // dimex!*
    fn = elt(env, 4); // deg!*form
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    fn = elt(env, 5); // negf
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    fn = elt(env, 6); // addf
    v0051 = (*qfn2(fn))(qenv(fn), stack[0], v0051);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0017 = v0051;
    v0051 = v0017;
    if (v0051 == nil) goto v0054;
    v0051 = v0017;
    v0051 = integerp(v0051);
    if (v0051 == nil) goto v0022;
    v0051 = (LispObject)1; // 0
        popv(2);
        return Lleq(nil, v0017, v0051);

v0022:
    v0051 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0051); }

v0054:
    v0051 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0051); }
// error exit handlers
v0016:
    popv(2);
    return nil;
}



// Code for endofstmtp

static LispObject CC_endofstmtp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0087, v0054;
    argcheck(nargs, 0, "endofstmtp");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for endofstmtp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0054 = qvalue(elt(env, 1)); // cursym!*
    v0087 = elt(env, 2); // (!*semicol!* !*rsqbkt!* end)
    v0087 = Lmember(nil, v0054, v0087);
    if (v0087 == nil) goto v0004;
    v0087 = qvalue(elt(env, 3)); // t
    return onevalue(v0087);

v0004:
    v0087 = nil;
    return onevalue(v0087);
}



// Code for pnth!*

static LispObject CC_pnthH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0052, v0053, v0096;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pnth*");
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
    v0053 = v0001;
    stack[0] = v0000;
// end of prologue

v0003:
    v0052 = stack[0];
    if (v0052 == nil) goto v0057;
    v0096 = v0053;
    v0052 = (LispObject)17; // 1
    if (v0096 == v0052) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    v0052 = v0053;
    v0052 = sub1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    v0053 = v0052;
    goto v0003;

v0057:
    v0052 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0052); }
// error exit handlers
v0058:
    popv(2);
    return nil;
}



setup_type const u45_setup[] =
{
    {"monomcomparelex",         too_few_2,      CC_monomcomparelex,wrong_no_2},
    {"rl_subat",                too_few_2,      CC_rl_subat,   wrong_no_2},
    {"bc_dcont",                CC_bc_dcont,    too_many_1,    wrong_no_1},
    {"safe-fp-quot",            too_few_2,      CC_safeKfpKquot,wrong_no_2},
    {"gfquotient",              too_few_2,      CC_gfquotient, wrong_no_2},
    {"mkdmoderr",               too_few_2,      CC_mkdmoderr,  wrong_no_2},
    {"physopsubs",              CC_physopsubs,  too_many_1,    wrong_no_1},
    {"listquotient",            too_few_2,      CC_listquotient,wrong_no_2},
    {"fs:prin:",                CC_fsTprinT,    too_many_1,    wrong_no_1},
    {"verify_tens_ids",         CC_verify_tens_ids,too_many_1, wrong_no_1},
    {"my_freeof",               too_few_2,      CC_my_freeof,  wrong_no_2},
    {"makecoeffpairs",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs},
    {"ofsf_updsignpow",         too_few_2,      CC_ofsf_updsignpow,wrong_no_2},
    {"spinnerprod",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_spinnerprod},
    {"vdplsort",                CC_vdplsort,    too_many_1,    wrong_no_1},
    {"indordln",                CC_indordln,    too_many_1,    wrong_no_1},
    {"free",                    CC_free,        too_many_1,    wrong_no_1},
    {"expand-imrepartpow",      CC_expandKimrepartpow,too_many_1,wrong_no_1},
    {"generic_arguments",       CC_generic_arguments,too_many_1,wrong_no_1},
    {"groeb=testb",             too_few_2,      CC_groebMtestb,wrong_no_2},
    {"njets",                   too_few_2,      CC_njets,      wrong_no_2},
    {"taylorp",                 CC_taylorp,     too_many_1,    wrong_no_1},
    {"domainp_list",            CC_domainp_list,too_many_1,    wrong_no_1},
    {"janettreeinsert",         CC_janettreeinsert,too_many_1, wrong_no_1},
    {"mri_simplat1",            too_few_2,      CC_mri_simplat1,wrong_no_2},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"matsm*",                  too_few_2,      CC_matsmH,     wrong_no_2},
    {"f2dip",                   CC_f2dip,       too_many_1,    wrong_no_1},
    {"reset_opnums",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_reset_opnums},
    {"delete_edge",             too_few_2,      CC_delete_edge,wrong_no_2},
    {"reduce-ratios",           too_few_2,      CC_reduceKratios,wrong_no_2},
    {"fs:subang",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTsubang},
    {"addnew",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_addnew},
    {"flattens1",               CC_flattens1,   too_many_1,    wrong_no_1},
    {"pst_mkpst",               CC_pst_mkpst,   too_many_1,    wrong_no_1},
    {"*q2f",                    CC_Hq2f,        too_many_1,    wrong_no_1},
    {"min2-order",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_min2Korder},
    {"evalgeq",                 too_few_2,      CC_evalgeq,    wrong_no_2},
    {"exp*",                    CC_expH,        too_many_1,    wrong_no_1},
    {"simpsqrt2",               CC_simpsqrt2,   too_many_1,    wrong_no_1},
    {"general-modular-difference",too_few_2,    CC_generalKmodularKdifference,wrong_no_2},
    {"ofsf_smmkatl-and1",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKand1},
    {"sfchk",                   CC_sfchk,       too_many_1,    wrong_no_1},
    {"depend-sq",               too_few_2,      CC_dependKsq,  wrong_no_2},
    {"mri_simplfloor1",         CC_mri_simplfloor1,too_many_1, wrong_no_1},
    {"ctx_get",                 too_few_2,      CC_ctx_get,    wrong_no_2},
    {"ezgcd-comfac",            CC_ezgcdKcomfac,too_many_1,    wrong_no_1},
    {"addexptsdf",              too_few_2,      CC_addexptsdf, wrong_no_2},
    {"den",                     CC_den,         too_many_1,    wrong_no_1},
    {":log2",                   CC_Tlog2,       too_many_1,    wrong_no_1},
    {"exptbf",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exptbf},
    {"mk_names_map_2",          CC_mk_names_map_2,too_many_1,  wrong_no_1},
    {"mo_support",              CC_mo_support,  too_many_1,    wrong_no_1},
    {"dv_skel2factor",          too_few_2,      CC_dv_skel2factor,wrong_no_2},
    {"add-factor",              too_few_2,      CC_addKfactor, wrong_no_2},
    {"remainder-mod-p",         too_few_2,      CC_remainderKmodKp,wrong_no_2},
    {"lengthn",                 CC_lengthn,     too_many_1,    wrong_no_1},
    {"spmatlength",             CC_spmatlength, too_many_1,    wrong_no_1},
    {"groebcplistsort",         CC_groebcplistsort,too_many_1, wrong_no_1},
    {"maprintla",               too_few_2,      CC_maprintla,  wrong_no_2},
    {":log10",                  CC_Tlog10,      too_many_1,    wrong_no_1},
    {"find_triangl_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_triangl_coeff},
    {"sub01",                   too_few_2,      CC_sub01,      wrong_no_2},
    {"dfdeg",                   too_few_2,      CC_dfdeg,      wrong_no_2},
    {"replace-next",            too_few_2,      CC_replaceKnext,wrong_no_2},
    {"mk+inner+product",        too_few_2,      CC_mkLinnerLproduct,wrong_no_2},
    {"pasf_lnegrel",            CC_pasf_lnegrel,too_many_1,    wrong_no_1},
    {"ofsf_pop",                CC_ofsf_pop,    too_many_1,    wrong_no_1},
    {"parfool",                 CC_parfool,     too_many_1,    wrong_no_1},
    {"dim<=deg",                CC_dimRMdeg,    too_many_1,    wrong_no_1},
    {"endofstmtp",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_endofstmtp},
    {"pnth*",                   too_few_2,      CC_pnthH,      wrong_no_2},
    {NULL, (one_args *)"u45", (two_args *)"11485 8338178 5980904", 0}
};

// end of generated code
