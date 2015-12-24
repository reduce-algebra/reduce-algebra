
// $destdir/u42.c        Machine generated C code

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



// Code for conditionrd

static LispObject CC_conditionrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
    argcheck(nargs, 0, "conditionrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for conditionrd");
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
    fn = elt(env, 3); // lex
    v0003 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-1];
    v0004 = qvalue(elt(env, 1)); // char
    v0003 = elt(env, 2); // (r e l n)
    if (equal(v0004, v0003)) goto v0006;
    fn = elt(env, 4); // mathml
    v0003 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-1];
    stack[0] = v0003;
    goto v0007;

v0007:
    fn = elt(env, 3); // lex
    v0003 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0006:
    fn = elt(env, 5); // relnrd
    v0003 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-1];
    stack[0] = v0003;
    goto v0007;
// error exit handlers
v0005:
    popv(2);
    return nil;
}



// Code for ieval

static LispObject CC_ieval(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ieval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0009 = v0008;
// end of prologue
    fn = elt(env, 1); // reval
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*s2i
        return (*qfn1(fn))(qenv(fn), v0009);
    }
// error exit handlers
v0007:
    popv(1);
    return nil;
}



// Code for znumrnil

static LispObject CC_znumrnil(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0010, v0011;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for znumrnil");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0008;
// end of prologue
    v0010 = stack[0];
    fn = elt(env, 2); // znumr
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    if (v0010 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0011 = qvalue(elt(env, 1)); // nil
    v0010 = (LispObject)17; // 1
    popv(2);
    return cons(v0011, v0010);
// error exit handlers
v0003:
    popv(2);
    return nil;
}



// Code for diffp

static LispObject CC_diffp(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0288, v0289, v0290, v0291, v0292;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0000;
    stack[-8] = v0008;
// end of prologue
    stack[0] = nil;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    stack[-9] = v0288;
    v0288 = stack[-8];
    v0288 = qcar(v0288);
    stack[-8] = v0288;
    v0289 = stack[-9];
    v0288 = (LispObject)17; // 1
    v0288 = (LispObject)greaterp2(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    v0288 = v0288 ? lisp_true : nil;
    env = stack[-10];
    if (v0288 == nil) goto v0294;
    v0288 = stack[-8];
    fn = elt(env, 24); // noncomp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (v0288 == nil) goto v0294;
    v0289 = stack[-8];
    v0288 = stack[-7];
    v0288 = list2(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 25); // simpdf
    stack[-1] = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = stack[-8];
    v0288 = stack[-9];
    v0288 = sub1(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = list2(stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 26); // simpexpt
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 27); // multsq
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0289 = stack[-8];
    v0288 = (LispObject)17; // 1
    fn = elt(env, 28); // to
    v0289 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (LispObject)17; // 1
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0289 = ncons(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (LispObject)17; // 1
    stack[0] = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-2] = stack[-8];
    v0288 = stack[-9];
    v0288 = sub1(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0289 = cons(stack[-2], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-7];
    v0288 = CC_diffp(env, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 27); // multsq
    v0288 = (*qfn2(fn))(qenv(fn), stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    {
        LispObject v0295 = stack[-1];
        popv(11);
        fn = elt(env, 29); // addsq
        return (*qfn2(fn))(qenv(fn), v0295, v0288);
    }

v0294:
    v0289 = stack[-8];
    v0288 = stack[-7];
    if (v0289 == v0288) goto v0296;
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0297;

v0297:
    if (!(v0288 == nil)) goto v0298;
    v0288 = stack[-8];
    if (!consp(v0288)) goto v0299;
    v0288 = stack[-8];
    v0288 = qcar(v0288);
    if (!consp(v0288)) goto v0300;
    v0289 = stack[-8];
    v0288 = stack[-7];
    fn = elt(env, 30); // difff
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0301;

v0301:
    if (!(v0288 == nil)) goto v0298;
    v0288 = stack[-8];
    v0289 = qcar(v0288);
    v0288 = elt(env, 2); // !*sq
    if (v0289 == v0288) goto v0302;
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0303;

v0303:
    if (!(v0288 == nil)) goto v0298;
    v0288 = stack[-8];
    v0289 = qcar(v0288);
    v0288 = elt(env, 3); // dfform
    v0288 = get(v0289, v0288);
    env = stack[-10];
    stack[-6] = v0288;
    if (v0288 == nil) goto v0304;
    v0291 = stack[-6];
    v0290 = stack[-8];
    v0289 = stack[-7];
    v0288 = stack[-9];
        popv(11);
        return Lapply3(nil, 4, v0291, v0290, v0289, v0288);

v0304:
    v0288 = stack[-8];
    stack[-1] = qcar(v0288);
    v0288 = stack[-8];
    fn = elt(env, 31); // dfn_prop
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = get(stack[-1], v0288);
    env = stack[-10];
    stack[-6] = v0288;
    if (v0288 == nil) goto v0305;
    v0288 = stack[-6];
    stack[-5] = v0288;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    stack[-4] = v0288;
    goto v0306;

v0306:
    v0288 = stack[-4];
    v0288 = qcar(v0288);
    fn = elt(env, 32); // simp
    v0289 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-7];
    fn = elt(env, 33); // diffsq
    v0289 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[0];
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    v0288 = stack[0];
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    if (v0288 == nil) goto v0307;
    v0288 = stack[-5];
    v0288 = qcar(v0288);
    if (!(v0288 == nil)) goto v0307;

v0308:
    v0288 = stack[-8];
    v0289 = qcar(v0288);
    v0288 = elt(env, 13); // df
    if (v0289 == v0288) goto v0309;
    v0288 = qvalue(elt(env, 18)); // !*df_partial
    if (v0288 == nil) goto v0310;
    v0288 = qvalue(elt(env, 11)); // !*expanddf
    if (v0288 == nil) goto v0310;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    if (!consp(v0288)) goto v0310;
    v0288 = stack[-8];
    v0288 = qcar(v0288);
    v0289 = Lexplode(nil, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = elt(env, 19); // (!! !! !_)
    v0288 = Lnconc(nil, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = Lcompress(nil, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = Lintern(nil, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-6] = v0288;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    stack[-5] = v0288;
    v0289 = qvalue(elt(env, 1)); // nil
    v0288 = (LispObject)17; // 1
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    v0288 = (LispObject)1; // 0
    stack[-3] = v0288;
    v0288 = stack[-5];
    stack[-2] = v0288;
    goto v0311;

v0311:
    v0288 = stack[-2];
    if (v0288 == nil) goto v0298;
    v0288 = stack[-2];
    v0288 = qcar(v0288);
    stack[-1] = v0288;
    v0288 = stack[-3];
    v0288 = add1(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-3] = v0288;
    v0290 = elt(env, 13); // df
    v0289 = stack[-1];
    v0288 = stack[-7];
    v0288 = list3(v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 32); // simp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-1] = v0288;
    v0288 = qcar(v0288);
    if (v0288 == nil) goto v0312;
    v0289 = stack[-6];
    v0288 = stack[-3];
    fn = elt(env, 34); // mkid
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-4] = v0288;
    v0290 = stack[-4];
    v0289 = elt(env, 20); // simpfn
    v0288 = elt(env, 21); // simpiden
    v0288 = Lputprop(nil, 3, v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0289 = stack[-4];
    v0288 = stack[-5];
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 32); // simp
    v0289 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-1];
    fn = elt(env, 27); // multsq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 29); // addsq
    v0288 = (*qfn2(fn))(qenv(fn), stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0312;

v0312:
    v0288 = stack[-2];
    v0288 = qcdr(v0288);
    stack[-2] = v0288;
    goto v0311;

v0298:
    v0289 = stack[-8];
    v0288 = qvalue(elt(env, 5)); // wtl!*
    v0288 = Latsoc(nil, v0289, v0288);
    stack[-6] = v0288;
    if (v0288 == nil) goto v0313;
    stack[-1] = elt(env, 6); // k!*
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    v0288 = negate(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 28); // to
    v0289 = (*qfn2(fn))(qenv(fn), stack[-1], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (LispObject)17; // 1
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0289 = ncons(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (LispObject)17; // 1
    v0289 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[0];
    fn = elt(env, 27); // multsq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0313;

v0313:
    v0288 = stack[-9];
    v0288 = sub1(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-3] = v0288;
    v0289 = stack[-9];
    v0288 = (LispObject)17; // 1
    if (v0289 == v0288) goto v0314;
    v0288 = qvalue(elt(env, 7)); // dmode!*
    if (!symbolp(v0288)) v0288 = nil;
    else { v0288 = qfastgets(v0288);
           if (v0288 != nil) { v0288 = elt(v0288, 5); // convert
#ifdef RECORD_GET
             if (v0288 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0288 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0288 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0288 == SPID_NOPROP) v0288 = nil; else v0288 = lisp_true; }}
#endif
    if (v0288 == nil) goto v0315;
    v0288 = qvalue(elt(env, 7)); // dmode!*
    if (!symbolp(v0288)) v0289 = nil;
    else { v0289 = qfastgets(v0288);
           if (v0289 != nil) { v0289 = elt(v0289, 34); // i2d
#ifdef RECORD_GET
             if (v0289 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0289 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0289 == SPID_NOPROP) v0289 = nil; }}
#endif
    v0288 = stack[-9];
    v0288 = Lapply1(nil, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 35); // int!-equiv!-chk
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-9] = v0288;
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0316;

v0316:
    if (v0288 == nil) goto v0317;
    v0289 = qvalue(elt(env, 1)); // nil
    v0288 = (LispObject)17; // 1
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    goto v0318;

v0318:
    {
        popv(11);
        fn = elt(env, 36); // rationalizesq
        return (*qfn1(fn))(qenv(fn), v0288);
    }

v0317:
    v0289 = stack[-8];
    v0288 = stack[-3];
    fn = elt(env, 28); // to
    v0289 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-9];
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0289 = ncons(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (LispObject)17; // 1
    v0289 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[0];
    fn = elt(env, 27); // multsq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    goto v0318;

v0315:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0316;

v0314:
    v0288 = stack[0];
    goto v0318;

v0310:
    v0290 = elt(env, 13); // df
    v0289 = stack[-8];
    v0288 = stack[-7];
    v0288 = list3(v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0319;

v0319:
    v0288 = stack[0];
    fn = elt(env, 37); // opmtch
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-6] = v0288;
    if (v0288 == nil) goto v0320;
    v0288 = stack[-6];
    fn = elt(env, 32); // simp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0320:
    v0289 = stack[-8];
    v0288 = stack[-7];
    fn = elt(env, 38); // depends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (v0288 == nil) goto v0321;
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0322;

v0322:
    if (v0288 == nil) goto v0323;
    v0289 = qvalue(elt(env, 1)); // nil
    v0288 = (LispObject)17; // 1
    popv(11);
    return cons(v0289, v0288);

v0323:
    v0288 = qvalue(elt(env, 11)); // !*expanddf
    if (v0288 == nil) goto v0324;
    v0288 = stack[-8];
    if (!consp(v0288)) goto v0325;
    v0288 = stack[0];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    if (v0288 == nil) goto v0326;
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0327;

v0327:
    if (v0288 == nil) goto v0324;
    v0289 = stack[-8];
    v0288 = qvalue(elt(env, 12)); // depl!*
    v0288 = Lassoc(nil, v0289, v0288);
    stack[-6] = v0288;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    if (v0288 == nil) goto v0328;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    fn = elt(env, 39); // get!-all!-kernels
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    goto v0329;

v0329:
    stack[-5] = v0288;
    v0288 = stack[-6];
    if (v0288 == nil) goto v0330;
    v0288 = stack[-5];
    if (v0288 == nil) goto v0330;
    v0289 = stack[-7];
    v0288 = stack[-5];
    v0289 = Ldelete(nil, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-7];
    fn = elt(env, 40); // ldepends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (v0288 == nil) goto v0330;
    v0292 = elt(env, 23); // "Possible inconsistent dependencies in"
    v0291 = stack[-8];
    v0290 = qvalue(elt(env, 1)); // nil
    v0289 = qvalue(elt(env, 1)); // nil
    v0288 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 41); // msgpri
    v0288 = (*qfnn(fn))(qenv(fn), 5, v0292, v0291, v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0289 = stack[0];
    v0288 = (LispObject)17; // 1
    fn = elt(env, 42); // mksq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0330:
    v0288 = stack[-6];
    if (v0288 == nil) goto v0331;
    v0289 = stack[-7];
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    stack[-6] = v0288;
    v0288 = Lmemq(nil, v0289, v0288);
    if (v0288 == nil) goto v0332;
    v0289 = stack[0];
    v0288 = (LispObject)17; // 1
    fn = elt(env, 42); // mksq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0332:
    v0290 = stack[-8];
    v0289 = stack[-7];
    v0288 = stack[-6];
    fn = elt(env, 43); // df!-chain!-rule
    v0288 = (*qfnn(fn))(qenv(fn), 3, v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0331:
    v0288 = stack[-5];
    if (v0288 == nil) goto v0333;
    v0289 = stack[-7];
    v0288 = stack[-5];
    fn = elt(env, 44); // smember
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (v0288 == nil) goto v0334;
    v0289 = stack[0];
    v0288 = (LispObject)17; // 1
    fn = elt(env, 42); // mksq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    goto v0335;

v0335:
    stack[0] = v0288;
    goto v0298;

v0334:
    v0290 = stack[-8];
    v0289 = stack[-7];
    v0288 = stack[-5];
    fn = elt(env, 43); // df!-chain!-rule
    v0288 = (*qfnn(fn))(qenv(fn), 3, v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    goto v0335;

v0333:
    v0289 = stack[0];
    v0288 = (LispObject)17; // 1
    fn = elt(env, 42); // mksq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0328:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0329;

v0324:
    v0289 = stack[0];
    v0288 = (LispObject)17; // 1
    fn = elt(env, 42); // mksq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0326:
    v0288 = stack[-8];
    v0289 = qcar(v0288);
    v0288 = elt(env, 22); // (df int)
    v0288 = Lmemq(nil, v0289, v0288);
    if (v0288 == nil) goto v0336;
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0327;

v0336:
    v0289 = stack[-7];
    v0288 = stack[-8];
    fn = elt(env, 44); // smember
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (v0288 == nil) goto v0337;
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0327;

v0337:
    v0289 = stack[-8];
    v0288 = qvalue(elt(env, 8)); // powlis!*
    v0288 = Latsoc(nil, v0289, v0288);
    stack[-6] = v0288;
    if (v0288 == nil) goto v0338;
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-7];
    fn = elt(env, 38); // depends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0327;

v0338:
    v0288 = qvalue(elt(env, 9)); // t
    goto v0327;

v0325:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0327;

v0321:
    v0288 = stack[0];
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    stack[-8] = v0289;
    v0288 = qvalue(elt(env, 8)); // powlis!*
    v0288 = Latsoc(nil, v0289, v0288);
    stack[-6] = v0288;
    if (v0288 == nil) goto v0339;
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[0];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    fn = elt(env, 45); // dependsl
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0340;

v0340:
    if (v0288 == nil) goto v0341;
    v0288 = qvalue(elt(env, 10)); // !*depend
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0322;

v0341:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0322;

v0339:
    v0288 = qvalue(elt(env, 9)); // t
    goto v0340;

v0309:
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-7];
    if (v0289 == v0288) goto v0342;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = elt(env, 16); // int
    if (!consp(v0289)) goto v0343;
    v0289 = qcar(v0289);
    if (!(v0289 == v0288)) goto v0343;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-7];
    if (v0289 == v0288) goto v0344;
    v0288 = qvalue(elt(env, 17)); // !*allowdfint
    if (v0288 == nil) goto v0343;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    fn = elt(env, 46); // simp!*
    v0289 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-7];
    fn = elt(env, 33); // diffsq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    fn = elt(env, 47); // not_df_p
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (v0288 == nil) goto v0343;
    stack[-2] = elt(env, 13); // df
    stack[-1] = elt(env, 16); // int
    v0288 = stack[0];
    fn = elt(env, 48); // mk!*sq
    v0289 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    v0288 = list3(stack[-1], v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 49); // reval
    v0289 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = list2star(stack[-2], v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0319;

v0343:
    v0288 = qvalue(elt(env, 11)); // !*expanddf
    if (v0288 == nil) goto v0345;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-7];
    fn = elt(env, 38); // depends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (v0288 == nil) goto v0345;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = qvalue(elt(env, 8)); // powlis!*
    v0288 = Latsoc(nil, v0289, v0288);
    stack[-6] = v0288;
    if (v0288 == nil) goto v0346;
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-7];
    fn = elt(env, 38); // depends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0347;

v0347:
    if (v0288 == nil) goto v0345;
    v0289 = stack[-7];
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    fn = elt(env, 44); // smember
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (!(v0288 == nil)) goto v0345;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = qvalue(elt(env, 12)); // depl!*
    v0288 = Lassoc(nil, v0289, v0288);
    stack[-6] = v0288;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    if (!consp(v0288)) goto v0348;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    v0288 = qcdr(v0288);
    if (v0288 == nil) goto v0349;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    v0288 = qcdr(v0288);
    fn = elt(env, 39); // get!-all!-kernels
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    goto v0350;

v0350:
    stack[-5] = v0288;
    v0288 = stack[-6];
    if (v0288 == nil) goto v0351;
    v0288 = stack[-5];
    if (v0288 == nil) goto v0351;
    v0289 = stack[-7];
    v0288 = stack[-5];
    v0289 = Ldelete(nil, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-7];
    fn = elt(env, 40); // ldepends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (!(v0288 == nil)) goto v0345;

v0351:
    v0288 = stack[-6];
    if (v0288 == nil) goto v0352;
    v0289 = stack[-7];
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    stack[-6] = v0288;
    v0288 = Lmemq(nil, v0289, v0288);
    if (!(v0288 == nil)) goto v0352;
    v0290 = stack[-8];
    v0289 = stack[-7];
    v0288 = stack[-6];
    fn = elt(env, 43); // df!-chain!-rule
    v0288 = (*qfnn(fn))(qenv(fn), 3, v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0352:
    v0288 = stack[-5];
    if (v0288 == nil) goto v0345;
    v0289 = stack[-7];
    v0288 = stack[-5];
    fn = elt(env, 44); // smember
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (!(v0288 == nil)) goto v0345;
    v0290 = stack[-8];
    v0289 = stack[-7];
    v0288 = stack[-5];
    fn = elt(env, 43); // df!-chain!-rule
    v0288 = (*qfnn(fn))(qenv(fn), 3, v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0345:
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    stack[0] = qcar(v0288);
    v0289 = stack[-8];
    v0288 = stack[-7];
    fn = elt(env, 50); // merge!-ind!-vars
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0289 = cons(stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0289;
    v0288 = elt(env, 13); // df
    if (!symbolp(v0288)) v0288 = nil;
    else { v0288 = qfastgets(v0288);
           if (v0288 != nil) { v0288 = elt(v0288, 50); // kvalue
#ifdef RECORD_GET
             if (v0288 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0288 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0288 == SPID_NOPROP) v0288 = nil; }}
#endif
    fn = elt(env, 51); // find_sub_df
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-6] = v0288;
    if (v0288 == nil) goto v0353;
    v0288 = stack[-6];
    v0288 = qcar(v0288);
    fn = elt(env, 32); // simp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    stack[-3] = v0288;
    goto v0354;

v0354:
    v0288 = stack[-3];
    if (v0288 == nil) goto v0298;
    v0288 = stack[-3];
    v0288 = qcar(v0288);
    stack[-2] = v0288;
    v0288 = (LispObject)17; // 1
    stack[-1] = v0288;
    goto v0355;

v0355:
    v0288 = stack[-2];
    v0289 = qcdr(v0288);
    v0288 = stack[-1];
    v0288 = difference2(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = Lminusp(nil, v0288);
    env = stack[-10];
    if (v0288 == nil) goto v0356;
    v0288 = stack[-3];
    v0288 = qcdr(v0288);
    stack[-3] = v0288;
    goto v0354;

v0356:
    v0289 = stack[0];
    v0288 = stack[-2];
    v0288 = qcar(v0288);
    fn = elt(env, 33); // diffsq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    v0288 = stack[-1];
    v0288 = add1(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-1] = v0288;
    goto v0355;

v0353:
    v0289 = elt(env, 13); // df
    v0288 = stack[0];
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0319;

v0349:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0350;

v0348:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0350;

v0346:
    v0288 = qvalue(elt(env, 9)); // t
    goto v0347;

v0344:
    v0290 = elt(env, 13); // df
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = list2star(v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0319;

v0342:
    v0288 = qvalue(elt(env, 14)); // !*commutedf
    if (v0288 == nil) goto v0357;
    v0288 = qvalue(elt(env, 10)); // !*depend
    if (!(v0288 == nil)) goto v0357;
    v0289 = qvalue(elt(env, 1)); // nil
    v0288 = (LispObject)17; // 1
    popv(11);
    return cons(v0289, v0288);

v0357:
    v0288 = qvalue(elt(env, 15)); // !*simpnoncomdf
    if (v0288 == nil) goto v0343;
    v0289 = stack[-7];
    v0288 = qvalue(elt(env, 12)); // depl!*
    v0288 = Latsoc(nil, v0289, v0288);
    stack[0] = v0288;
    if (v0288 == nil) goto v0343;
    v0288 = stack[0];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    if (!(v0288 == nil)) goto v0343;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    stack[-6] = v0288;
    v0290 = elt(env, 13); // df
    v0289 = stack[-8];
    v0288 = stack[-6];
    v0288 = list3(v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 32); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0290 = elt(env, 13); // df
    v0289 = stack[-7];
    v0288 = stack[-6];
    v0288 = list3(v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 32); // simp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 52); // quotsq
    v0288 = (*qfn2(fn))(qenv(fn), stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0307:
    v0288 = stack[-5];
    v0288 = qcdr(v0288);
    stack[-5] = v0288;
    v0288 = stack[-4];
    v0288 = qcdr(v0288);
    stack[-4] = v0288;
    v0288 = stack[-4];
    if (v0288 == nil) goto v0358;
    v0288 = stack[-5];
    if (!(v0288 == nil)) goto v0306;

v0358:
    v0288 = stack[-4];
    if (!(v0288 == nil)) goto v0308;
    v0288 = stack[-5];
    if (!(v0288 == nil)) goto v0308;
    v0288 = stack[0];
    v0288 = Lreverse(nil, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-5] = v0288;
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    stack[-4] = v0288;
    v0289 = qvalue(elt(env, 1)); // nil
    v0288 = (LispObject)17; // 1
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0359;

v0359:
    v0288 = stack[-5];
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    if (v0288 == nil) goto v0360;
    v0288 = stack[-5];
    stack[-1] = qcar(v0288);
    v0288 = stack[-6];
    v0288 = qcar(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-4];
    fn = elt(env, 53); // pair
    v0289 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-6];
    v0288 = qcar(v0288);
    v0288 = qcdr(v0288);
    v0288 = Lsubla(nil, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 32); // simp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    fn = elt(env, 27); // multsq
    v0289 = (*qfn2(fn))(qenv(fn), stack[-1], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[0];
    fn = elt(env, 29); // addsq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0360;

v0360:
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    stack[-6] = v0288;
    v0288 = stack[-5];
    v0288 = qcdr(v0288);
    stack[-5] = v0288;
    v0288 = stack[-5];
    if (v0288 == nil) goto v0298;
    else goto v0359;

v0305:
    v0288 = stack[-8];
    v0289 = qcar(v0288);
    v0288 = elt(env, 4); // plus
    if (v0289 == v0288) goto v0361;
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0362;

v0362:
    if (v0288 == nil) goto v0308;
    else goto v0298;

v0361:
    v0288 = stack[-8];
    fn = elt(env, 32); // simp
    v0289 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = stack[-7];
    fn = elt(env, 33); // diffsq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0362;

v0302:
    v0288 = stack[-8];
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-7];
    fn = elt(env, 33); // diffsq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0303;

v0300:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0301;

v0299:
    v0289 = stack[-8];
    v0288 = stack[-7];
    fn = elt(env, 38); // depends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    if (v0288 == nil) goto v0363;
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0364;

v0364:
    if (v0288 == nil) goto v0365;
    v0289 = qvalue(elt(env, 1)); // nil
    v0288 = (LispObject)17; // 1
    popv(11);
    return cons(v0289, v0288);

v0365:
    v0288 = qvalue(elt(env, 11)); // !*expanddf
    if (v0288 == nil) goto v0366;
    v0289 = stack[-8];
    v0288 = qvalue(elt(env, 8)); // powlis!*
    v0288 = Latsoc(nil, v0289, v0288);
    stack[-6] = v0288;
    if (v0288 == nil) goto v0367;
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-7];
    fn = elt(env, 38); // depends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0368;

v0368:
    if (v0288 == nil) goto v0369;
    v0289 = stack[-8];
    v0288 = qvalue(elt(env, 12)); // depl!*
    v0288 = Latsoc(nil, v0289, v0288);
    stack[-6] = v0288;
    if (v0288 == nil) goto v0370;
    v0289 = stack[-7];
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    stack[-6] = v0288;
    v0288 = Lmemq(nil, v0289, v0288);
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0371;

v0371:
    if (v0288 == nil) goto v0366;
    v0290 = stack[-8];
    v0289 = stack[-7];
    v0288 = stack[-6];
    fn = elt(env, 43); // df!-chain!-rule
    v0288 = (*qfnn(fn))(qenv(fn), 3, v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0298;

v0366:
    v0290 = elt(env, 13); // df
    v0289 = stack[-8];
    v0288 = stack[-7];
    v0288 = list3(v0290, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    v0288 = stack[0];
    fn = elt(env, 37); // opmtch
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[-6] = v0288;
    if (v0288 == nil) goto v0372;
    v0288 = stack[-6];
    fn = elt(env, 32); // simp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    goto v0373;

v0373:
    stack[0] = v0288;
    goto v0298;

v0372:
    v0289 = stack[0];
    v0288 = (LispObject)17; // 1
    fn = elt(env, 42); // mksq
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    goto v0373;

v0370:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0371;

v0369:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0371;

v0367:
    v0288 = qvalue(elt(env, 9)); // t
    goto v0368;

v0363:
    v0289 = stack[-8];
    v0288 = qvalue(elt(env, 8)); // powlis!*
    v0288 = Latsoc(nil, v0289, v0288);
    stack[-6] = v0288;
    if (v0288 == nil) goto v0374;
    v0288 = stack[-6];
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0288 = qcdr(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[-7];
    fn = elt(env, 38); // depends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0375;

v0375:
    if (v0288 == nil) goto v0376;
    v0288 = qvalue(elt(env, 10)); // !*depend
    v0288 = (v0288 == nil ? lisp_true : nil);
    goto v0364;

v0376:
    v0288 = qvalue(elt(env, 1)); // nil
    goto v0364;

v0374:
    v0288 = qvalue(elt(env, 9)); // t
    goto v0375;

v0296:
    v0289 = (LispObject)17; // 1
    v0288 = (LispObject)17; // 1
    v0288 = cons(v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-10];
    stack[0] = v0288;
    goto v0297;
// error exit handlers
v0293:
    popv(11);
    return nil;
}



// Code for letmtr

static LispObject CC_letmtr(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0273, v0267, v0394;
    LispObject fn;
    LispObject v0381, v0000, v0008;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "letmtr");
    va_start(aa, nargs);
    v0008 = va_arg(aa, LispObject);
    v0000 = va_arg(aa, LispObject);
    v0381 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for letmtr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0381,v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0008,v0000,v0381);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0381;
    stack[-3] = v0000;
    stack[-4] = v0008;
// end of prologue
    stack[-5] = nil;
    v0267 = stack[-2];
    v0273 = elt(env, 1); // mat
    if (!consp(v0267)) goto v0011;
    v0267 = qcar(v0267);
    if (!(v0267 == v0273)) goto v0011;
    v0273 = stack[-4];
    v0273 = qcdr(v0273);
    fn = elt(env, 7); // revlis
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-6];
    stack[-5] = v0273;
    fn = elt(env, 8); // numlis
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-6];
    if (v0273 == nil) goto v0396;
    v0273 = stack[-5];
    v0267 = Llength(nil, v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-6];
    v0273 = (LispObject)33; // 2
    v0273 = Lneq(nil, v0267, v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-6];
    goto v0264;

v0264:
    if (v0273 == nil) goto v0397;
    v0267 = stack[-4];
    v0273 = elt(env, 6); // hold
    {
        popv(7);
        fn = elt(env, 9); // errpri2
        return (*qfn2(fn))(qenv(fn), v0267, v0273);
    }

v0397:
    v0273 = stack[-2];
    v0267 = qcdr(v0273);
    v0273 = stack[-5];
    v0273 = qcar(v0273);
    fn = elt(env, 10); // nth
    v0267 = (*qfn2(fn))(qenv(fn), v0267, v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-6];
    v0273 = stack[-5];
    v0273 = qcdr(v0273);
    v0273 = qcar(v0273);
    fn = elt(env, 11); // pnth
    v0267 = (*qfn2(fn))(qenv(fn), v0267, v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-6];
    v0273 = stack[-3];
    v0273 = Lrplaca(nil, v0267, v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    v0273 = nil;
    { popv(7); return onevalue(v0273); }

v0396:
    v0273 = qvalue(elt(env, 5)); // t
    goto v0264;

v0011:
    stack[-1] = elt(env, 2); // matrix
    stack[0] = (LispObject)161; // 10
    v0394 = elt(env, 3); // "Matrix"
    v0273 = stack[-4];
    v0267 = qcar(v0273);
    v0273 = elt(env, 4); // "not set"
    v0273 = list3(v0394, v0267, v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-6];
    fn = elt(env, 12); // rerror
    v0273 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0273);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-6];
    goto v0397;
// error exit handlers
v0395:
    popv(7);
    return nil;
}



// Code for xpartitop

static LispObject CC_xpartitop(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xpartitop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0009 = v0008;
// end of prologue
    fn = elt(env, 1); // simp!*
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // xpartitsq
        return (*qfn1(fn))(qenv(fn), v0009);
    }
// error exit handlers
v0007:
    popv(1);
    return nil;
}



// Code for r2oaddspecies

static LispObject CC_r2oaddspecies(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0401, v0389;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for r2oaddspecies");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    v0389 = stack[-1];
    v0401 = stack[0];
    v0401 = Lassoc(nil, v0389, v0401);
    if (!(v0401 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0401 = elt(env, 1); // "new species: "
    v0401 = Lprinc(nil, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-2];
    v0401 = stack[-1];
    fn = elt(env, 2); // prin2t
    v0401 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-2];
    v0389 = stack[-1];
    v0401 = (LispObject)1; // 0
    v0401 = cons(v0389, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-2];
    v0401 = ncons(v0401);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    {
        LispObject v0383 = stack[0];
        popv(3);
        return Lappend(nil, v0383, v0401);
    }
// error exit handlers
v0402:
    popv(3);
    return nil;
}



// Code for mk_simpl_map_

static LispObject CC_mk_simpl_map_(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0404, v0405;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_simpl_map_");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0404 = v0008;
// end of prologue
    v0405 = v0404;
    v0404 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // mk_simpl_map_1
        return (*qfn2(fn))(qenv(fn), v0405, v0404);
    }
}



// Code for dfp!-rule!-found

static LispObject CC_dfpKruleKfound(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0386, v0387, v0407, v0408;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfp-rule-found");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0407 = v0000;
    v0408 = v0008;
// end of prologue
    v0387 = v0408;
    v0386 = elt(env, 1); // dfp
    if (!consp(v0387)) goto v0009;
    v0387 = qcar(v0387);
    if (!(v0387 == v0386)) goto v0009;
    v0386 = v0408;
    v0386 = qcdr(v0386);
    v0386 = qcar(v0386);
    v0387 = v0407;
        return Lneq(nil, v0386, v0387);

v0009:
    v0386 = qvalue(elt(env, 2)); // t
    return onevalue(v0386);
}



// Code for mv!-compact2

static LispObject CC_mvKcompact2(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0385, v0415, v0416;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-compact2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    v0415 = stack[-1];
    v0385 = stack[0];
    fn = elt(env, 2); // equiv!-coeffs
    v0385 = (*qfn2(fn))(qenv(fn), v0415, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-3];
    stack[-2] = v0385;
    v0385 = stack[0];
    fn = elt(env, 3); // mv!-domainlist
    v0385 = (*qfn1(fn))(qenv(fn), v0385);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-3];
    v0415 = stack[-2];
    fn = elt(env, 4); // reduce
    v0385 = (*qfn2(fn))(qenv(fn), v0415, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-3];
    v0416 = v0385;
    v0415 = v0416;
    v0385 = stack[-2];
    if (equal(v0415, v0385)) goto v0386;
    v0415 = v0416;
    v0385 = stack[-2];
    fn = elt(env, 5); // mv!-domainlist!-!-
    v0385 = (*qfn2(fn))(qenv(fn), v0415, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-3];
    fn = elt(env, 6); // mv!-coeff!-replace
    v0415 = (*qfn2(fn))(qenv(fn), stack[0], v0385);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-3];
    v0385 = stack[-1];
    {
        popv(4);
        fn = elt(env, 7); // mv!-!+
        return (*qfn2(fn))(qenv(fn), v0415, v0385);
    }

v0386:
    v0385 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0385); }
// error exit handlers
v0417:
    popv(4);
    return nil;
}



// Code for prepcadr

static LispObject CC_prepcadr(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepcadr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0008;
// end of prologue
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    {
        fn = elt(env, 1); // prepsq
        return (*qfn1(fn))(qenv(fn), v0007);
    }
}



// Code for general!-multiply!-by!-constant!-mod!-p

static LispObject CC_generalKmultiplyKbyKconstantKmodKp(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0421, v0422, v0423;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-multiply-by-constant-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    v0421 = stack[-1];
    if (v0421 == nil) goto v0009;
    v0422 = stack[0];
    v0421 = (LispObject)17; // 1
    if (v0422 == v0421) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0421 = stack[-1];
    if (!consp(v0421)) goto v0004;
    v0421 = stack[-1];
    v0421 = qcar(v0421);
    v0421 = (consp(v0421) ? nil : lisp_true);
    goto v0003;

v0003:
    if (v0421 == nil) goto v0264;
    v0422 = stack[-1];
    v0421 = stack[0];
    fn = elt(env, 3); // general!-modular!-times
    v0421 = (*qfn2(fn))(qenv(fn), v0422, v0421);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0421);
    }

v0264:
    v0421 = stack[-1];
    v0421 = qcar(v0421);
    v0422 = qcdr(v0421);
    v0421 = stack[0];
    stack[-2] = CC_generalKmultiplyKbyKconstantKmodKp(env, v0422, v0421);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    env = stack[-3];
    v0421 = stack[-1];
    v0422 = qcdr(v0421);
    v0421 = stack[0];
    v0421 = CC_generalKmultiplyKbyKconstantKmodKp(env, v0422, v0421);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    v0422 = stack[-2];
    v0423 = v0422;
    if (v0423 == nil) { popv(4); return onevalue(v0421); }
    v0423 = stack[-1];
    v0423 = qcar(v0423);
    v0423 = qcar(v0423);
    popv(4);
    return acons(v0423, v0422, v0421);

v0004:
    v0421 = qvalue(elt(env, 2)); // t
    goto v0003;

v0009:
    v0421 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0421); }
// error exit handlers
v0424:
    popv(4);
    return nil;
}



// Code for rl_nnfnot

static LispObject CC_rl_nnfnot(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0405;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_nnfnot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0405 = v0008;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_nnfnot!*
    v0405 = ncons(v0405);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-1];
    {
        LispObject v0001 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0001, v0405);
    }
// error exit handlers
v0400:
    popv(2);
    return nil;
}



// Code for ofsf_simplequal

static LispObject CC_ofsf_simplequal(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0380, v0427, v0276;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_simplequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
    stack[-2] = v0008;
// end of prologue
    v0380 = stack[-2];
    fn = elt(env, 8); // ofsf_posdefp
    v0380 = (*qfn1(fn))(qenv(fn), v0380);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-4];
    stack[-3] = v0380;
    v0427 = stack[-3];
    v0380 = elt(env, 1); // stsq
    if (v0427 == v0380) goto v0399;
    v0380 = stack[-2];
    fn = elt(env, 9); // sfto_sqfpartf
    v0380 = (*qfn1(fn))(qenv(fn), v0380);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-4];
    stack[0] = v0380;
    v0380 = stack[0];
    fn = elt(env, 8); // ofsf_posdefp
    v0380 = (*qfn1(fn))(qenv(fn), v0380);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-4];
    v0276 = v0380;
    v0427 = v0276;
    v0380 = elt(env, 1); // stsq
    if (v0427 == v0380) goto v0386;
    v0380 = qvalue(elt(env, 3)); // !*rlsitsqspl
    if (v0380 == nil) goto v0421;
    v0380 = qvalue(elt(env, 4)); // !*rlsiexpla
    if (!(v0380 == nil)) goto v0385;
    v0380 = qvalue(elt(env, 5)); // !*rlsiexpl
    if (v0380 == nil) goto v0421;
    v0427 = stack[-1];
    v0380 = elt(env, 6); // and
    if (!(v0427 == v0380)) goto v0421;

v0385:
    v0427 = v0276;
    v0380 = elt(env, 7); // tsq
    if (v0427 == v0380) goto v0384;
    v0427 = stack[-3];
    v0380 = elt(env, 7); // tsq
    if (!(v0427 == v0380)) goto v0421;
    v0380 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); // ofsf_tsqsplequal
        return (*qfn1(fn))(qenv(fn), v0380);
    }

v0421:
    v0427 = stack[0];
    v0380 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); // ofsf_facequal!*
        return (*qfn2(fn))(qenv(fn), v0427, v0380);
    }

v0384:
    v0380 = stack[0];
    {
        popv(5);
        fn = elt(env, 10); // ofsf_tsqsplequal
        return (*qfn1(fn))(qenv(fn), v0380);
    }

v0386:
    v0380 = elt(env, 2); // false
    { popv(5); return onevalue(v0380); }

v0399:
    v0380 = elt(env, 2); // false
    { popv(5); return onevalue(v0380); }
// error exit handlers
v0394:
    popv(5);
    return nil;
}



// Code for enter!-sorted

static LispObject CC_enterKsorted(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0385, v0415;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for enter-sorted");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    stack[-2] = nil;
    goto v0007;

v0007:
    v0385 = stack[0];
    if (v0385 == nil) goto v0400;
    v0385 = stack[-1];
    v0415 = qcar(v0385);
    v0385 = stack[0];
    v0385 = qcar(v0385);
    v0385 = qcar(v0385);
    fn = elt(env, 1); // taydegree!<
    v0385 = (*qfn2(fn))(qenv(fn), v0415, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0281;
    env = stack[-3];
    if (v0385 == nil) goto v0411;
    v0415 = stack[-1];
    v0385 = stack[0];
    v0385 = cons(v0415, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0281;
    env = stack[-3];
    {
        LispObject v0417 = stack[-2];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0417, v0385);
    }

v0411:
    v0385 = stack[0];
    v0415 = qcar(v0385);
    v0385 = stack[-2];
    v0385 = cons(v0415, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0281;
    env = stack[-3];
    stack[-2] = v0385;
    v0385 = stack[0];
    v0385 = qcdr(v0385);
    stack[0] = v0385;
    goto v0007;

v0400:
    stack[0] = stack[-2];
    v0385 = stack[-1];
    v0385 = ncons(v0385);
    nil = C_nil;
    if (exception_pending()) goto v0281;
    env = stack[-3];
    {
        LispObject v0265 = stack[0];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0265, v0385);
    }
// error exit handlers
v0281:
    popv(4);
    return nil;
}



// Code for factor!-prim!-sqfree!-f

static LispObject CC_factorKprimKsqfreeKf(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0462, v0463, v0464;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factor-prim-sqfree-f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0008;
// end of prologue
    stack[-7] = qvalue(elt(env, 1)); // !*msg
    qvalue(elt(env, 1)) = nil; // !*msg
    v0462 = qvalue(elt(env, 2)); // !*rounded
    stack[-5] = v0462;
    v0462 = stack[-5];
    if (v0462 == nil) goto v0400;
    v0462 = stack[-6];
    v0462 = qcar(v0462);
    fn = elt(env, 13); // univariatep
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    if (v0462 == nil) goto v0400;
    v0462 = stack[-6];
    v0462 = qcar(v0462);
    v0462 = qcar(v0462);
    v0463 = qcdr(v0462);
    v0462 = (LispObject)17; // 1
    if (v0463 == v0462) goto v0398;
    v0462 = qvalue(elt(env, 3)); // nil
    goto v0004;

v0004:
    if (v0462 == nil) goto v0400;
    v0462 = stack[-6];
    fn = elt(env, 14); // unifactor
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    goto v0006;

v0006:
    qvalue(elt(env, 1)) = stack[-7]; // !*msg
    { popv(9); return onevalue(v0462); }

v0400:
    v0462 = stack[-5];
    if (!(v0462 == nil)) goto v0278;
    v0462 = qvalue(elt(env, 4)); // !*complex
    if (!(v0462 == nil)) goto v0278;
    v0462 = qvalue(elt(env, 5)); // !*rational
    if (!(v0462 == nil)) goto v0278;

v0405:
    v0462 = qvalue(elt(env, 7)); // !*limitedfactors
    if (!(v0462 == nil)) goto v0466;
    v0462 = qvalue(elt(env, 8)); // dmode!*
    if (v0462 == nil) goto v0427;
    v0463 = qvalue(elt(env, 8)); // dmode!*
    v0462 = elt(env, 10); // sqfrfactorfn
    v0462 = get(v0463, v0462);
    env = stack[-8];
    v0464 = v0462;
    v0463 = qvalue(elt(env, 8)); // dmode!*
    v0462 = elt(env, 11); // factorfn
    v0462 = get(v0463, v0462);
    env = stack[-8];
    stack[0] = v0462;
    v0462 = v0464;
    if (v0462 == nil) goto v0380;
    v0463 = v0464;
    v0462 = stack[0];
    if (v0463 == v0462) goto v0380;
    v0462 = elt(env, 9); // factorf
    stack[0] = v0462;
    goto v0380;

v0380:
    v0462 = stack[0];
    if (v0462 == nil) goto v0466;
    v0463 = stack[0];
    v0462 = stack[-6];
    v0462 = qcar(v0462);
    v0462 = Lapply1(nil, v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    stack[0] = v0462;
    v0462 = stack[0];
    v0463 = qcar(v0462);
    v0462 = stack[-6];
    v0462 = qcdr(v0462);
    fn = elt(env, 15); // exptf
    stack[-4] = (*qfn2(fn))(qenv(fn), v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = stack[0];
    v0462 = qcdr(v0462);
    stack[-3] = v0462;
    v0462 = stack[-3];
    if (v0462 == nil) goto v0467;
    v0462 = stack[-3];
    v0462 = qcar(v0462);
    v0463 = qcar(v0462);
    v0462 = stack[-6];
    v0462 = qcdr(v0462);
    v0462 = cons(v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = ncons(v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    stack[-1] = v0462;
    stack[-2] = v0462;
    goto v0468;

v0468:
    v0462 = stack[-3];
    v0462 = qcdr(v0462);
    stack[-3] = v0462;
    v0462 = stack[-3];
    if (v0462 == nil) goto v0469;
    stack[0] = stack[-1];
    v0462 = stack[-3];
    v0462 = qcar(v0462);
    v0463 = qcar(v0462);
    v0462 = stack[-6];
    v0462 = qcdr(v0462);
    v0462 = cons(v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = ncons(v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = Lrplacd(nil, stack[0], v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = stack[-1];
    v0462 = qcdr(v0462);
    stack[-1] = v0462;
    goto v0468;

v0469:
    v0462 = stack[-2];
    goto v0470;

v0470:
    v0462 = cons(stack[-4], v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    stack[-6] = v0462;
    goto v0084;

v0084:
    v0462 = stack[-5];
    if (v0462 == nil) goto v0471;
    v0462 = elt(env, 12); // rounded
    v0462 = ncons(v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    fn = elt(env, 16); // on
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = stack[-6];
    stack[-4] = qcar(v0462);
    v0462 = stack[-6];
    v0462 = qcdr(v0462);
    stack[-5] = v0462;
    v0462 = stack[-5];
    if (v0462 == nil) goto v0472;
    v0462 = stack[-5];
    v0462 = qcar(v0462);
    stack[0] = v0462;
    v0462 = stack[0];
    v0463 = qcar(v0462);
    v0462 = (LispObject)17; // 1
    v0462 = cons(v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    fn = elt(env, 17); // resimp
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0463 = qcar(v0462);
    v0462 = stack[0];
    v0462 = qcdr(v0462);
    v0462 = cons(v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = ncons(v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    stack[-2] = v0462;
    stack[-3] = v0462;
    goto v0473;

v0473:
    v0462 = stack[-5];
    v0462 = qcdr(v0462);
    stack[-5] = v0462;
    v0462 = stack[-5];
    if (v0462 == nil) goto v0474;
    stack[-1] = stack[-2];
    v0462 = stack[-5];
    v0462 = qcar(v0462);
    stack[0] = v0462;
    v0462 = stack[0];
    v0463 = qcar(v0462);
    v0462 = (LispObject)17; // 1
    v0462 = cons(v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    fn = elt(env, 17); // resimp
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0463 = qcar(v0462);
    v0462 = stack[0];
    v0462 = qcdr(v0462);
    v0462 = cons(v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = ncons(v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = Lrplacd(nil, stack[-1], v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0462 = stack[-2];
    v0462 = qcdr(v0462);
    stack[-2] = v0462;
    goto v0473;

v0474:
    v0462 = stack[-3];
    goto v0475;

v0475:
    v0462 = cons(stack[-4], v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    stack[-6] = v0462;
    goto v0471;

v0471:
    v0462 = stack[-6];
    goto v0006;

v0472:
    v0462 = qvalue(elt(env, 3)); // nil
    goto v0475;

v0467:
    v0462 = qvalue(elt(env, 3)); // nil
    goto v0470;

v0466:
    v0462 = stack[-6];
    v0463 = qcar(v0462);
    v0462 = stack[-6];
    v0462 = qcdr(v0462);
    fn = elt(env, 18); // factor!-prim!-sqfree!-f!-1
    v0462 = (*qfn2(fn))(qenv(fn), v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    stack[-6] = v0462;
    goto v0084;

v0427:
    v0462 = elt(env, 9); // factorf
    stack[0] = v0462;
    goto v0380;

v0278:
    v0462 = stack[-5];
    if (v0462 == nil) goto v0266;
    v0462 = elt(env, 6); // rational
    v0462 = ncons(v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    fn = elt(env, 16); // on
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    goto v0266;

v0266:
    v0462 = stack[-6];
    v0463 = qcar(v0462);
    v0462 = (LispObject)17; // 1
    v0462 = cons(v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    fn = elt(env, 17); // resimp
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    v0463 = qcar(v0462);
    v0462 = stack[-6];
    v0462 = qcdr(v0462);
    v0462 = cons(v0463, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-8];
    stack[-6] = v0462;
    goto v0405;

v0398:
    v0462 = stack[-6];
    v0463 = qcdr(v0462);
    v0462 = (LispObject)17; // 1
    v0462 = (v0463 == v0462 ? lisp_true : nil);
    goto v0004;
// error exit handlers
v0465:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-7]; // !*msg
    popv(9);
    return nil;
}



// Code for cols2rows2

static LispObject CC_cols2rows2(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0389, v0390;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cols2rows2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    v0390 = stack[0];
    v0389 = (LispObject)1; // 0
    if (v0390 == v0389) goto v0007;
    v0390 = stack[-1];
    v0389 = stack[0];
    fn = elt(env, 1); // ithlistelem
    stack[-2] = (*qfn2(fn))(qenv(fn), v0390, v0389);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0389 = stack[0];
    v0389 = sub1(v0389);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-3];
    v0389 = CC_cols2rows2(env, stack[-1], v0389);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    {
        LispObject v0396 = stack[-2];
        popv(4);
        return cons(v0396, v0389);
    }

v0007:
    v0389 = nil;
    { popv(4); return onevalue(v0389); }
// error exit handlers
v0264:
    popv(4);
    return nil;
}



// Code for ldf!-dep!-var

static LispObject CC_ldfKdepKvar(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0412, v0476;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldf-dep-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0412 = v0008;
// end of prologue
    stack[-2] = nil;
    stack[-1] = v0412;
    goto v0084;

v0084:
    v0412 = stack[-1];
    if (v0412 == nil) goto v0006;
    v0412 = stack[-1];
    v0412 = qcar(v0412);
    stack[0] = v0412;
    v0412 = stack[0];
    fn = elt(env, 3); // ldt!-tvar
    v0476 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-3];
    v0412 = qvalue(elt(env, 2)); // depl!*
    v0412 = Lassoc(nil, v0476, v0412);
    if (v0412 == nil) goto v0011;
    v0412 = stack[0];
    fn = elt(env, 3); // ldt!-tvar
    v0476 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-3];
    v0412 = qvalue(elt(env, 2)); // depl!*
    v0412 = Lassoc(nil, v0476, v0412);
    v0476 = qcdr(v0412);
    v0412 = stack[-2];
    v0412 = Lappend(nil, v0476, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0283;
    env = stack[-3];
    stack[-2] = v0412;
    goto v0011;

v0011:
    v0412 = stack[-1];
    v0412 = qcdr(v0412);
    stack[-1] = v0412;
    goto v0084;

v0006:
    v0412 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); // makeset
        return (*qfn1(fn))(qenv(fn), v0412);
    }
// error exit handlers
v0283:
    popv(4);
    return nil;
}



// Code for dipdivmon

static LispObject CC_dipdivmon(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0412, v0476;
    LispObject fn;
    LispObject v0381, v0000, v0008;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dipdivmon");
    va_start(aa, nargs);
    v0008 = va_arg(aa, LispObject);
    v0000 = va_arg(aa, LispObject);
    v0381 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipdivmon");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0381,v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0008,v0000,v0381);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0381;
    stack[-1] = v0000;
    stack[-2] = v0008;
// end of prologue
    stack[-3] = nil;
    goto v0006;

v0006:
    v0412 = stack[-2];
    if (v0412 == nil) goto v0404;
    v0412 = stack[-2];
    v0476 = qcar(v0412);
    v0412 = stack[0];
    fn = elt(env, 1); // evdif
    v0476 = (*qfn2(fn))(qenv(fn), v0476, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-4];
    v0412 = stack[-3];
    v0412 = cons(v0476, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-4];
    stack[-3] = v0412;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    v0476 = qcar(v0412);
    v0412 = stack[-1];
    fn = elt(env, 2); // bcquot
    v0476 = (*qfn2(fn))(qenv(fn), v0476, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-4];
    v0412 = stack[-3];
    v0412 = cons(v0476, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-4];
    stack[-3] = v0412;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    stack[-2] = v0412;
    goto v0006;

v0404:
    v0412 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0412);
    }
// error exit handlers
v0279:
    popv(5);
    return nil;
}



// Code for ndepends

static LispObject CC_ndepends(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0251, v0303;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ndepends");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    v0251 = stack[-1];
    if (v0251 == nil) goto v0403;
    v0251 = stack[-1];
    v0251 = (is_number(v0251) ? lisp_true : nil);
    if (!(v0251 == nil)) goto v0084;
    v0251 = stack[0];
    v0251 = (is_number(v0251) ? lisp_true : nil);
    goto v0084;

v0084:
    if (v0251 == nil) goto v0005;
    v0251 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0251); }

v0005:
    v0303 = stack[-1];
    v0251 = stack[0];
    if (equal(v0303, v0251)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0251 = stack[-1];
    if (!consp(v0251)) goto v0390;
    v0251 = qvalue(elt(env, 2)); // nil
    goto v0398;

v0398:
    if (v0251 == nil) goto v0476;
    v0251 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0251); }

v0476:
    v0303 = stack[-1];
    v0251 = qvalue(elt(env, 4)); // depl!*
    v0251 = Lassoc(nil, v0303, v0251);
    v0303 = v0251;
    v0251 = v0303;
    if (v0251 == nil) goto v0486;
    v0251 = v0303;
    v0303 = qcdr(v0251);
    v0251 = stack[0];
    fn = elt(env, 5); // lndepends
    v0251 = (*qfn2(fn))(qenv(fn), v0303, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0487;
    env = stack[-2];
    goto v0416;

v0416:
    if (v0251 == nil) goto v0412;
    v0251 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0251); }

v0412:
    v0251 = stack[-1];
    if (!consp(v0251)) goto v0488;
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    if (symbolp(v0251)) goto v0277;
    v0251 = qvalue(elt(env, 2)); // nil
    goto v0397;

v0397:
    if (v0251 == nil) goto v0418;
    v0251 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0251); }

v0418:
    v0251 = stack[-1];
    fn = elt(env, 6); // atomf
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0487;
    env = stack[-2];
    if (v0251 == nil) goto v0259;
    v0251 = qvalue(elt(env, 2)); // nil
    goto v0489;

v0489:
    if (v0251 == nil) goto v0461;
    v0251 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0251); }

v0461:
    v0251 = stack[0];
    fn = elt(env, 6); // atomf
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0487;
    env = stack[-2];
    if (!(v0251 == nil)) goto v0490;
    v0251 = stack[0];
    v0251 = qcar(v0251);
    if (!(symbolp(v0251))) goto v0491;
    v0251 = stack[0];
    v0251 = qcar(v0251);
    if (!symbolp(v0251)) v0251 = nil;
    else { v0251 = qfastgets(v0251);
           if (v0251 != nil) { v0251 = elt(v0251, 8); // dname
#ifdef RECORD_GET
             if (v0251 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0251 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0251 == SPID_NOPROP) v0251 = nil; }}
#endif
    if (!(v0251 == nil)) goto v0490;

v0491:
    v0303 = stack[-1];
    v0251 = stack[0];
    v0251 = qcdr(v0251);
    {
        popv(3);
        fn = elt(env, 7); // ndependsl
        return (*qfn2(fn))(qenv(fn), v0303, v0251);
    }

v0490:
    v0251 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0251); }

v0259:
    v0251 = stack[-1];
    v0303 = qcdr(v0251);
    v0251 = stack[0];
    fn = elt(env, 5); // lndepends
    v0251 = (*qfn2(fn))(qenv(fn), v0303, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0487;
    env = stack[-2];
    if (!(v0251 == nil)) goto v0489;
    v0251 = stack[-1];
    v0303 = qcar(v0251);
    v0251 = stack[0];
    v0251 = CC_ndepends(env, v0303, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0487;
    env = stack[-2];
    goto v0489;

v0277:
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    if (!symbolp(v0251)) v0251 = nil;
    else { v0251 = qfastgets(v0251);
           if (v0251 != nil) { v0251 = elt(v0251, 8); // dname
#ifdef RECORD_GET
             if (v0251 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0251 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0251 == SPID_NOPROP) v0251 = nil; }}
#endif
    goto v0397;

v0488:
    v0251 = qvalue(elt(env, 2)); // nil
    goto v0397;

v0486:
    v0251 = qvalue(elt(env, 2)); // nil
    goto v0416;

v0390:
    v0303 = stack[-1];
    v0251 = qvalue(elt(env, 3)); // frlis!*
    v0251 = Lmemq(nil, v0303, v0251);
    goto v0398;

v0403:
    v0251 = qvalue(elt(env, 1)); // t
    goto v0084;
// error exit handlers
v0487:
    popv(3);
    return nil;
}



// Code for make_spoly_pair

static LispObject CC_make_spoly_pair(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0394, v0488, v0493, v0494;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make_spoly_pair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0000;
    stack[-3] = v0008;
// end of prologue

v0399:
    v0488 = stack[-2];
    v0394 = stack[-3];
    fn = elt(env, 3); // pfordp
    v0394 = (*qfn2(fn))(qenv(fn), v0488, v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    if (v0394 == nil) goto v0005;
    v0394 = stack[-2];
    v0488 = v0394;
    v0394 = stack[-3];
    stack[-2] = v0394;
    v0394 = v0488;
    stack[-3] = v0394;
    goto v0399;

v0005:
    v0394 = stack[-3];
    fn = elt(env, 4); // xval
    stack[0] = (*qfn1(fn))(qenv(fn), v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    v0394 = stack[-2];
    fn = elt(env, 4); // xval
    v0394 = (*qfn1(fn))(qenv(fn), v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    fn = elt(env, 5); // xlcm
    v0394 = (*qfn2(fn))(qenv(fn), stack[0], v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    stack[-4] = v0394;
    v0394 = stack[-3];
    v0394 = qcdr(v0394);
    if (!(v0394 == nil)) goto v0282;
    v0394 = stack[-2];
    v0394 = qcdr(v0394);
    if (!(v0394 == nil)) goto v0282;
    v0394 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0394); }

v0282:
    stack[-1] = stack[-4];
    v0394 = stack[-3];
    fn = elt(env, 4); // xval
    stack[0] = (*qfn1(fn))(qenv(fn), v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    v0394 = stack[-2];
    fn = elt(env, 4); // xval
    v0394 = (*qfn1(fn))(qenv(fn), v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    fn = elt(env, 6); // triviallcm
    v0394 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    if (v0394 == nil) goto v0476;
    v0394 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0394); }

v0476:
    v0394 = stack[-4];
    fn = elt(env, 7); // mknwedge
    v0394 = (*qfn1(fn))(qenv(fn), v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    fn = elt(env, 8); // xdegreecheck
    v0394 = (*qfn1(fn))(qenv(fn), v0394);
    nil = C_nil;
    if (exception_pending()) goto v0495;
    env = stack[-5];
    if (v0394 == nil) goto v0377;
    v0394 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0394); }

v0377:
    v0493 = stack[-4];
    v0494 = elt(env, 2); // spoly_pair
    v0488 = stack[-3];
    v0394 = stack[-2];
    popv(6);
    return list4(v0493, v0494, v0488, v0394);
// error exit handlers
v0495:
    popv(6);
    return nil;
}



// Code for ev!-poles

static LispObject CC_evKpoles(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0413, v0398, v0391, v0401;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev-poles");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0401 = v0000;
    v0391 = v0008;
// end of prologue

v0009:
    v0413 = v0391;
    if (v0413 == nil) goto v0084;
    v0413 = v0391;
    v0398 = qcar(v0413);
    v0413 = v0401;
    v0413 = Lassoc(nil, v0398, v0413);
    v0398 = qcdr(v0413);
    v0413 = (LispObject)1; // 0
    if (!(v0398 == v0413)) return onevalue(v0391);
    v0413 = v0391;
    v0413 = qcdr(v0413);
    v0391 = v0413;
    goto v0009;

v0084:
    v0413 = qvalue(elt(env, 1)); // nil
    return onevalue(v0413);
}



// Code for evaluate!-in!-order!-mod!-p

static LispObject CC_evaluateKinKorderKmodKp(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0265, v0382, v0497, v0498;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate-in-order-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue

v0009:
    v0265 = stack[-1];
    if (!consp(v0265)) goto v0399;
    v0265 = stack[-1];
    v0265 = qcar(v0265);
    v0265 = (consp(v0265) ? nil : lisp_true);
    goto v0405;

v0405:
    if (v0265 == nil) goto v0005;
    v0265 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); // !*d2n
        return (*qfn1(fn))(qenv(fn), v0265);
    }

v0005:
    v0265 = stack[-1];
    v0265 = qcar(v0265);
    v0265 = qcar(v0265);
    v0382 = qcar(v0265);
    v0265 = stack[0];
    v0265 = qcar(v0265);
    v0265 = qcar(v0265);
    if (equal(v0382, v0265)) goto v0430;
    v0265 = stack[0];
    v0265 = qcdr(v0265);
    stack[0] = v0265;
    goto v0009;

v0430:
    v0265 = stack[-1];
    v0265 = qcar(v0265);
    v0382 = qcdr(v0265);
    v0265 = stack[0];
    v0265 = qcdr(v0265);
    v0498 = CC_evaluateKinKorderKmodKp(env, v0382, v0265);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-2];
    v0265 = stack[-1];
    v0265 = qcar(v0265);
    v0265 = qcar(v0265);
    v0497 = qcdr(v0265);
    v0265 = stack[-1];
    v0382 = qcdr(v0265);
    v0265 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // horner!-rule!-in!-order!-mod!-p
        return (*qfnn(fn))(qenv(fn), 4, v0498, v0497, v0382, v0265);
    }

v0399:
    v0265 = qvalue(elt(env, 1)); // t
    goto v0405;
// error exit handlers
v0266:
    popv(3);
    return nil;
}



// Code for mkcrn

static LispObject CC_mkcrn(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0001, v0002, v0319;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkcrn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0001 = v0000;
    v0002 = v0008;
// end of prologue
    v0319 = elt(env, 1); // !:crn!:
    return list2star(v0319, v0002, v0001);
}



// Code for even_action

static LispObject CC_even_action(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0476, v0496, v0426, v0282;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for even_action");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    v0496 = qvalue(elt(env, 1)); // nil
    v0476 = (LispObject)17; // 1
    v0476 = cons(v0496, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-3];
    v0496 = v0476;
    v0476 = stack[0];
    stack[-2] = v0476;
    goto v0393;

v0393:
    v0476 = stack[-2];
    if (v0476 == nil) { popv(4); return onevalue(v0496); }
    v0476 = stack[-2];
    v0476 = qcar(v0476);
    stack[0] = v0496;
    v0282 = stack[-1];
    v0496 = v0476;
    v0426 = qcdr(v0496);
    v0496 = qcar(v0476);
    v0476 = (LispObject)17; // 1
    fn = elt(env, 2); // even_action_sf
    v0476 = (*qfnn(fn))(qenv(fn), 4, v0282, v0426, v0496, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-3];
    fn = elt(env, 3); // addsq
    v0476 = (*qfn2(fn))(qenv(fn), stack[0], v0476);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-3];
    v0496 = v0476;
    v0476 = stack[-2];
    v0476 = qcdr(v0476);
    stack[-2] = v0476;
    goto v0393;
// error exit handlers
v0410:
    popv(4);
    return nil;
}



// Code for rule

static LispObject CC_rule(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0243, v0244, v0512, v0513, v0514;
    LispObject fn;
    LispObject v0204, v0381, v0000, v0008;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "rule");
    va_start(aa, nargs);
    v0008 = va_arg(aa, LispObject);
    v0000 = va_arg(aa, LispObject);
    v0381 = va_arg(aa, LispObject);
    v0204 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0204,v0381,v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0008,v0000,v0381,v0204);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0204;
    stack[0] = v0381;
    stack[-5] = v0000;
    stack[-6] = v0008;
// end of prologue
    stack[-7] = nil;
    v0244 = stack[0];
    v0243 = stack[-6];
    v0243 = Lsubla(nil, v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    stack[-2] = v0243;
    v0244 = stack[-2];
    v0243 = stack[-6];
    if (equal(v0244, v0243)) goto v0383;
    v0243 = stack[-2];
    if (!consp(v0243)) goto v0284;
    v0243 = qvalue(elt(env, 1)); // t
    stack[-7] = v0243;
    v0243 = stack[-2];
    stack[-6] = v0243;
    goto v0383;

v0383:
    v0244 = stack[0];
    v0243 = stack[-5];
    v0243 = Lsubla(nil, v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    stack[-2] = v0243;
    v0244 = stack[-2];
    v0243 = stack[-5];
    if (equal(v0244, v0243)) goto v0419;
    v0243 = stack[-2];
    stack[-5] = v0243;
    v0244 = stack[-5];
    v0243 = elt(env, 2); // !*sq!*
    if (!consp(v0244)) goto v0419;
    v0244 = qcar(v0244);
    if (!(v0244 == v0243)) goto v0419;
    v0243 = stack[-5];
    v0243 = qcdr(v0243);
    v0243 = qcar(v0243);
    fn = elt(env, 9); // prepsq!*
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    stack[-5] = v0243;
    goto v0419;

v0419:
    v0243 = stack[0];
    stack[-3] = v0243;
    v0243 = stack[-3];
    if (v0243 == nil) goto v0423;
    v0243 = stack[-3];
    v0243 = qcar(v0243);
    v0243 = qcdr(v0243);
    v0243 = ncons(v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    stack[-1] = v0243;
    stack[-2] = v0243;
    goto v0378;

v0378:
    v0243 = stack[-3];
    v0243 = qcdr(v0243);
    stack[-3] = v0243;
    v0243 = stack[-3];
    if (v0243 == nil) goto v0493;
    stack[0] = stack[-1];
    v0243 = stack[-3];
    v0243 = qcar(v0243);
    v0243 = qcdr(v0243);
    v0243 = ncons(v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    v0243 = Lrplacd(nil, stack[0], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    v0243 = stack[-1];
    v0243 = qcdr(v0243);
    stack[-1] = v0243;
    goto v0378;

v0493:
    v0243 = stack[-2];
    goto v0418;

v0418:
    stack[0] = v0243;
    v0244 = stack[0];
    v0243 = qvalue(elt(env, 4)); // mcond!*
    fn = elt(env, 10); // smemql
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    stack[-2] = v0243;
    v0244 = stack[0];
    v0243 = stack[-6];
    fn = elt(env, 10); // smemql
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    stack[-1] = v0243;
    v0244 = stack[-2];
    v0243 = stack[-1];
    fn = elt(env, 11); // setdiff
    v0244 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    v0243 = v0244;
    if (!(v0244 == nil)) goto v0516;
    v0244 = stack[0];
    v0243 = stack[-5];
    fn = elt(env, 10); // smemql
    v0244 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    v0243 = stack[-2];
    fn = elt(env, 11); // setdiff
    stack[0] = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    v0244 = stack[-1];
    v0243 = stack[-2];
    fn = elt(env, 11); // setdiff
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    fn = elt(env, 11); // setdiff
    v0244 = (*qfn2(fn))(qenv(fn), stack[0], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    v0243 = v0244;
    if (!(v0244 == nil)) goto v0516;
    v0244 = stack[-6];
    v0243 = elt(env, 8); // getel
    if (!consp(v0244)) goto v0517;
    v0244 = qcar(v0244);
    if (!(v0244 == v0243)) goto v0517;
    v0243 = stack[-6];
    v0243 = qcdr(v0243);
    v0243 = qcar(v0243);
    fn = elt(env, 12); // lispeval
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    stack[-6] = v0243;
    goto v0517;

v0517:
    v0514 = stack[-6];
    v0513 = stack[-5];
    v0512 = qvalue(elt(env, 3)); // nil
    v0244 = stack[-4];
    v0243 = stack[-7];
    {
        popv(9);
        fn = elt(env, 13); // let3
        return (*qfnn(fn))(qenv(fn), 5, v0514, v0513, v0512, v0244, v0243);
    }

v0516:
    v0244 = elt(env, 5); // "Unmatched free variable(s)"
    v0243 = cons(v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    fn = elt(env, 14); // lprie
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0515;
    env = stack[-8];
    v0243 = elt(env, 6); // hold
    qvalue(elt(env, 7)) = v0243; // erfg!*
    v0243 = qvalue(elt(env, 3)); // nil
    { popv(9); return onevalue(v0243); }

v0423:
    v0243 = qvalue(elt(env, 3)); // nil
    goto v0418;

v0284:
    v0243 = stack[-6];
    {
        popv(9);
        fn = elt(env, 15); // errpri1
        return (*qfn1(fn))(qenv(fn), v0243);
    }
// error exit handlers
v0515:
    popv(9);
    return nil;
}



// Code for nlist

static LispObject CC_nlist(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0478, v0284;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    stack[-2] = nil;
    goto v0405;

v0405:
    v0284 = stack[0];
    v0478 = (LispObject)1; // 0
    if (v0284 == v0478) goto v0403;
    v0284 = stack[-1];
    v0478 = stack[-2];
    v0478 = cons(v0284, v0478);
    nil = C_nil;
    if (exception_pending()) goto v0391;
    env = stack[-3];
    stack[-2] = v0478;
    v0478 = stack[0];
    v0478 = sub1(v0478);
    nil = C_nil;
    if (exception_pending()) goto v0391;
    env = stack[-3];
    stack[0] = v0478;
    goto v0405;

v0403:
    v0478 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0478);
    }
// error exit handlers
v0391:
    popv(4);
    return nil;
}



// Code for makecoeffpairshom

static LispObject CC_makecoeffpairshom(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0544, v0545, v0546, v0230;
    LispObject fn;
    LispObject v0204, v0381, v0000, v0008;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairshom");
    va_start(aa, nargs);
    v0008 = va_arg(aa, LispObject);
    v0000 = va_arg(aa, LispObject);
    v0381 = va_arg(aa, LispObject);
    v0204 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makecoeffpairshom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0204,v0381,v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0008,v0000,v0381,v0204);
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
    stack[-11] = v0204;
    stack[-12] = v0381;
    stack[-13] = v0000;
    stack[-14] = v0008;
// end of prologue
    v0544 = stack[-12];
    if (v0544 == nil) goto v0006;
    v0544 = stack[-13];
    v0544 = qcar(v0544);
    stack[-15] = v0544;
    goto v0386;

v0386:
    stack[0] = stack[-11];
    v0544 = stack[-14];
    v0545 = qcar(v0544);
    v0544 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0544 = (*qfn2(fn))(qenv(fn), v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    fn = elt(env, 4); // tayexp!-times2
    v0544 = (*qfn2(fn))(qenv(fn), stack[0], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    fn = elt(env, 5); // tayexp!-minusp
    v0544 = (*qfn1(fn))(qenv(fn), v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    if (v0544 == nil) goto v0419;
    v0544 = qvalue(elt(env, 2)); // nil
    { popv(17); return onevalue(v0544); }

v0419:
    v0544 = stack[-14];
    v0230 = qcdr(v0544);
    v0544 = stack[-13];
    v0546 = qcdr(v0544);
    v0544 = stack[-12];
    v0545 = qcdr(v0544);
    v0544 = stack[-11];
    v0544 = CC_makecoeffpairshom(env, 4, v0230, v0546, v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    stack[-7] = v0544;
    v0544 = stack[-7];
    if (v0544 == nil) goto v0265;
    v0544 = stack[-7];
    v0544 = qcar(v0544);
    stack[-3] = v0544;
    stack[-2] = stack[-15];
    v0544 = stack[-3];
    stack[-1] = qcar(v0544);
    v0544 = stack[-13];
    stack[0] = qcar(v0544);
    v0544 = stack[-12];
    v0545 = qcar(v0544);
    v0544 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0544 = (*qfn2(fn))(qenv(fn), v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    fn = elt(env, 6); // tayexp!-plus2
    v0545 = (*qfn2(fn))(qenv(fn), stack[0], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = stack[-3];
    v0544 = qcdr(v0544);
    v0544 = cons(v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = acons(stack[-2], stack[-1], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = ncons(v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    stack[-5] = v0544;
    stack[-6] = v0544;
    goto v0477;

v0477:
    v0544 = stack[-7];
    v0544 = qcdr(v0544);
    stack[-7] = v0544;
    v0544 = stack[-7];
    if (v0544 == nil) goto v0297;
    stack[-4] = stack[-5];
    v0544 = stack[-7];
    v0544 = qcar(v0544);
    stack[-3] = v0544;
    stack[-2] = stack[-15];
    v0544 = stack[-3];
    stack[-1] = qcar(v0544);
    v0544 = stack[-13];
    stack[0] = qcar(v0544);
    v0544 = stack[-12];
    v0545 = qcar(v0544);
    v0544 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0544 = (*qfn2(fn))(qenv(fn), v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    fn = elt(env, 6); // tayexp!-plus2
    v0545 = (*qfn2(fn))(qenv(fn), stack[0], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = stack[-3];
    v0544 = qcdr(v0544);
    v0544 = cons(v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = acons(stack[-2], stack[-1], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = ncons(v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = Lrplacd(nil, stack[-4], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = stack[-5];
    v0544 = qcdr(v0544);
    stack[-5] = v0544;
    goto v0477;

v0297:
    v0544 = stack[-6];
    goto v0430;

v0430:
    stack[-10] = v0544;
    v0544 = stack[-10];
    fn = elt(env, 7); // lastpair
    v0544 = (*qfn1(fn))(qenv(fn), v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    stack[-9] = v0544;
    v0545 = stack[-15];
    v0544 = stack[-11];
    fn = elt(env, 6); // tayexp!-plus2
    v0544 = (*qfn2(fn))(qenv(fn), v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    stack[-15] = v0544;
    v0544 = stack[-9];
    if (!consp(v0544)) goto v0386;
    else goto v0548;

v0548:
    stack[0] = stack[-11];
    v0544 = stack[-14];
    v0545 = qcar(v0544);
    v0544 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0544 = (*qfn2(fn))(qenv(fn), v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    fn = elt(env, 4); // tayexp!-times2
    v0544 = (*qfn2(fn))(qenv(fn), stack[0], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    fn = elt(env, 5); // tayexp!-minusp
    v0544 = (*qfn1(fn))(qenv(fn), v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    if (!(v0544 == nil)) { LispObject res = stack[-10]; popv(17); return onevalue(res); }
    stack[-8] = stack[-9];
    v0544 = stack[-14];
    v0230 = qcdr(v0544);
    v0544 = stack[-13];
    v0546 = qcdr(v0544);
    v0544 = stack[-12];
    v0545 = qcdr(v0544);
    v0544 = stack[-11];
    v0544 = CC_makecoeffpairshom(env, 4, v0230, v0546, v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    stack[-7] = v0544;
    v0544 = stack[-7];
    if (v0544 == nil) goto v0549;
    v0544 = stack[-7];
    v0544 = qcar(v0544);
    stack[-3] = v0544;
    stack[-2] = stack[-15];
    v0544 = stack[-3];
    stack[-1] = qcar(v0544);
    v0544 = stack[-13];
    stack[0] = qcar(v0544);
    v0544 = stack[-12];
    v0545 = qcar(v0544);
    v0544 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0544 = (*qfn2(fn))(qenv(fn), v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    fn = elt(env, 6); // tayexp!-plus2
    v0545 = (*qfn2(fn))(qenv(fn), stack[0], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = stack[-3];
    v0544 = qcdr(v0544);
    v0544 = cons(v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = acons(stack[-2], stack[-1], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = ncons(v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    stack[-5] = v0544;
    stack[-6] = v0544;
    goto v0501;

v0501:
    v0544 = stack[-7];
    v0544 = qcdr(v0544);
    stack[-7] = v0544;
    v0544 = stack[-7];
    if (v0544 == nil) goto v0550;
    stack[-4] = stack[-5];
    v0544 = stack[-7];
    v0544 = qcar(v0544);
    stack[-3] = v0544;
    stack[-2] = stack[-15];
    v0544 = stack[-3];
    stack[-1] = qcar(v0544);
    v0544 = stack[-13];
    stack[0] = qcar(v0544);
    v0544 = stack[-12];
    v0545 = qcar(v0544);
    v0544 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0544 = (*qfn2(fn))(qenv(fn), v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    fn = elt(env, 6); // tayexp!-plus2
    v0545 = (*qfn2(fn))(qenv(fn), stack[0], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = stack[-3];
    v0544 = qcdr(v0544);
    v0544 = cons(v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = acons(stack[-2], stack[-1], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = ncons(v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = Lrplacd(nil, stack[-4], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = stack[-5];
    v0544 = qcdr(v0544);
    stack[-5] = v0544;
    goto v0501;

v0550:
    v0544 = stack[-6];
    goto v0247;

v0247:
    v0544 = Lrplacd(nil, stack[-8], v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    v0544 = stack[-9];
    fn = elt(env, 7); // lastpair
    v0544 = (*qfn1(fn))(qenv(fn), v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    stack[-9] = v0544;
    v0545 = stack[-15];
    v0544 = stack[-11];
    fn = elt(env, 6); // tayexp!-plus2
    v0544 = (*qfn2(fn))(qenv(fn), v0545, v0544);
    nil = C_nil;
    if (exception_pending()) goto v0547;
    env = stack[-16];
    stack[-15] = v0544;
    goto v0548;

v0549:
    v0544 = qvalue(elt(env, 2)); // nil
    goto v0247;

v0265:
    v0544 = qvalue(elt(env, 2)); // nil
    goto v0430;

v0006:
    v0544 = elt(env, 1); // ((nil))
    { popv(17); return onevalue(v0544); }
// error exit handlers
v0547:
    popv(17);
    return nil;
}



// Code for depend!-f

static LispObject CC_dependKf(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0282, v0283;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depend-f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue

v0551:
    v0282 = stack[-1];
    if (!consp(v0282)) goto v0403;
    v0282 = stack[-1];
    v0282 = qcar(v0282);
    v0282 = (consp(v0282) ? nil : lisp_true);
    goto v0084;

v0084:
    if (v0282 == nil) goto v0005;
    v0282 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0282); }

v0005:
    v0282 = stack[-1];
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    v0283 = qcar(v0282);
    v0282 = stack[0];
    fn = elt(env, 3); // depend!-p
    v0282 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-2];
    if (!(v0282 == nil)) { popv(3); return onevalue(v0282); }
    v0282 = stack[-1];
    v0282 = qcar(v0282);
    v0283 = qcdr(v0282);
    v0282 = stack[0];
    v0282 = CC_dependKf(env, v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-2];
    if (!(v0282 == nil)) { popv(3); return onevalue(v0282); }
    v0282 = stack[-1];
    v0283 = qcdr(v0282);
    v0282 = stack[0];
    stack[-1] = v0283;
    stack[0] = v0282;
    goto v0551;

v0403:
    v0282 = qvalue(elt(env, 1)); // t
    goto v0084;
// error exit handlers
v0410:
    popv(3);
    return nil;
}



// Code for iv_cutn

static LispObject CC_iv_cutn(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0004, v0414;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for iv_cutn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0414 = v0008;
// end of prologue
    v0004 = v0414;
    v0004 = qcdr(v0004);
    if (v0004 == nil) goto v0010;
    v0004 = v0414;
    stack[0] = qcar(v0004);
    v0004 = v0414;
    v0004 = qcdr(v0004);
    v0004 = CC_iv_cutn(env, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-1];
    {
        LispObject v0388 = stack[0];
        popv(2);
        fn = elt(env, 1); // iv_cut
        return (*qfn2(fn))(qenv(fn), v0388, v0004);
    }

v0010:
    v0004 = v0414;
    v0004 = qcar(v0004);
    { popv(2); return onevalue(v0004); }
// error exit handlers
v0406:
    popv(2);
    return nil;
}



// Code for vdp_getprop

static LispObject CC_vdp_getprop(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0414;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_getprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0004 = v0000;
    v0414 = v0008;
// end of prologue
    stack[0] = v0004;
    v0004 = v0414;
    fn = elt(env, 2); // vdp_plist
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0406;
    env = stack[-1];
    v0004 = Latsoc(nil, stack[0], v0004);
    v0414 = v0004;
    v0004 = v0414;
    if (v0004 == nil) goto v0011;
    v0004 = v0414;
    v0004 = qcdr(v0004);
    { popv(2); return onevalue(v0004); }

v0011:
    v0004 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0004); }
// error exit handlers
v0406:
    popv(2);
    return nil;
}



// Code for lowupperlimitml

static LispObject CC_lowupperlimitml(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0387;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lowupperlimitml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0008;
// end of prologue
    v0387 = elt(env, 1); // "<lowlimit>"
    fn = elt(env, 7); // printout
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = qvalue(elt(env, 2)); // t
    fn = elt(env, 8); // indent!*
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = stack[0];
    v0387 = qcdr(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 9); // expression
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 8); // indent!*
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = elt(env, 4); // "</lowlimit>"
    fn = elt(env, 7); // printout
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = elt(env, 5); // "<uplimit>"
    fn = elt(env, 7); // printout
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = qvalue(elt(env, 2)); // t
    fn = elt(env, 8); // indent!*
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = stack[0];
    v0387 = qcdr(v0387);
    v0387 = qcdr(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 9); // expression
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 8); // indent!*
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0387 = elt(env, 6); // "</uplimit>"
    fn = elt(env, 7); // printout
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    v0387 = nil;
    { popv(2); return onevalue(v0387); }
// error exit handlers
v0408:
    popv(2);
    return nil;
}



// Code for findhr

static LispObject CC_findhr(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0511, v0552, v0266;
    argcheck(nargs, 0, "findhr");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findhr");
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
    stack[-1] = nil;
    goto v0400;

v0400:
    v0552 = qvalue(elt(env, 1)); // headhisto
    v0511 = (LispObject)1; // 0
    v0511 = (LispObject)greaterp2(v0552, v0511);
    nil = C_nil;
    if (exception_pending()) goto v0484;
    v0511 = v0511 ? lisp_true : nil;
    env = stack[-2];
    if (v0511 == nil) goto v0009;
    v0552 = qvalue(elt(env, 2)); // codhisto
    v0511 = qvalue(elt(env, 1)); // headhisto
    v0511 = *(LispObject *)((char *)v0552 + (CELL-TAG_VECTOR) + ((int32_t)v0511/(16/CELL)));
    stack[-1] = v0511;
    if (!(v0511 == nil)) goto v0009;
    v0511 = qvalue(elt(env, 1)); // headhisto
    v0511 = sub1(v0511);
    nil = C_nil;
    if (exception_pending()) goto v0484;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0511; // headhisto
    goto v0400;

v0009:
    v0511 = stack[-1];
    if (v0511 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0511 = stack[-1];
    v0511 = ncons(v0511);
    nil = C_nil;
    if (exception_pending()) goto v0484;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0511; // psi
    v0511 = (LispObject)17; // 1
    qvalue(elt(env, 5)) = v0511; // npsi
    stack[0] = qvalue(elt(env, 6)); // codmat
    v0552 = qvalue(elt(env, 7)); // maxvar
    v0511 = stack[-1];
    v0511 = plus2(v0552, v0511);
    nil = C_nil;
    if (exception_pending()) goto v0484;
    env = stack[-2];
    v0266 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0511/(16/CELL)));
    v0552 = (LispObject)1; // 0
    v0511 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0266 + (CELL-TAG_VECTOR) + ((int32_t)v0552/(16/CELL))) = v0511;
    v0552 = stack[-1];
    v0511 = qvalue(elt(env, 8)); // rcoccup
    v0511 = cons(v0552, v0511);
    nil = C_nil;
    if (exception_pending()) goto v0484;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0511; // rcoccup
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0484:
    popv(3);
    return nil;
}



// Code for wedgewedge

static LispObject CC_wedgewedge(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0274, v0492, v0379;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgewedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
    stack[-1] = v0008;
// end of prologue
    stack[-2] = nil;
    goto v0006;

v0006:
    v0274 = stack[-1];
    v0274 = qcdr(v0274);
    if (v0274 == nil) goto v0430;
    v0274 = stack[-1];
    v0379 = qcar(v0274);
    v0492 = (LispObject)17; // 1
    v0274 = (LispObject)17; // 1
    v0379 = list2star(v0379, v0492, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    v0492 = qvalue(elt(env, 1)); // nil
    v0274 = stack[-2];
    v0274 = acons(v0379, v0492, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    stack[-2] = v0274;
    v0274 = stack[-1];
    v0274 = qcdr(v0274);
    stack[-1] = v0274;
    goto v0006;

v0430:
    v0274 = stack[-1];
    v0379 = qcar(v0274);
    v0492 = (LispObject)17; // 1
    v0274 = (LispObject)17; // 1
    v0274 = list2star(v0379, v0492, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    stack[-1] = ncons(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    v0379 = stack[0];
    v0492 = (LispObject)17; // 1
    v0274 = (LispObject)17; // 1
    v0274 = list2star(v0379, v0492, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    v0274 = ncons(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    fn = elt(env, 2); // wedgepf2
    v0274 = (*qfn2(fn))(qenv(fn), stack[-1], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    v0492 = v0274;
    goto v0403;

v0403:
    v0274 = stack[-2];
    if (v0274 == nil) { popv(4); return onevalue(v0492); }
    v0274 = stack[-2];
    v0274 = qcar(v0274);
    fn = elt(env, 2); // wedgepf2
    v0274 = (*qfn2(fn))(qenv(fn), v0274, v0492);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    v0492 = v0274;
    v0274 = stack[-2];
    v0274 = qcdr(v0274);
    stack[-2] = v0274;
    goto v0403;
// error exit handlers
v0276:
    popv(4);
    return nil;
}



// Code for gfstorval

static LispObject CC_gfstorval(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0001, v0002, v0319;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfstorval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0001 = v0000;
    v0002 = v0008;
// end of prologue
    v0319 = v0002;
    v0002 = v0001;
    v0001 = qvalue(elt(env, 1)); // !*xnlist
    v0001 = acons(v0319, v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[0];
    qvalue(elt(env, 1)) = v0001; // !*xnlist
    { popv(1); return onevalue(v0001); }
// error exit handlers
v0393:
    popv(1);
    return nil;
}



// Code for all_defined_map_

static LispObject CC_all_defined_map_(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0001, v0002, v0319;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for all_defined_map_");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0001 = v0000;
    v0002 = v0008;
// end of prologue
    v0319 = v0002;
    v0002 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // al1_defined_map_
        return (*qfnn(fn))(qenv(fn), 3, v0319, v0002, v0001);
    }
}



// Code for evalletsub

static LispObject CC_evalletsub(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0408, v0478, v0284;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalletsub");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0408 = v0000;
    stack[0] = v0008;
// end of prologue
    v0478 = stack[0];
    fn = elt(env, 3); // evalletsub2
    v0408 = (*qfn2(fn))(qenv(fn), v0478, v0408);
    nil = C_nil;
    if (exception_pending()) goto v0413;
    env = stack[-1];
    stack[0] = v0408;
    fn = elt(env, 4); // errorp
    v0408 = (*qfn1(fn))(qenv(fn), v0408);
    nil = C_nil;
    if (exception_pending()) goto v0413;
    env = stack[-1];
    if (v0408 == nil) goto v0388;
    v0284 = elt(env, 1); // alg
    v0478 = (LispObject)385; // 24
    v0408 = elt(env, 2); // "Invalid simplification"
    {
        popv(2);
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0284, v0478, v0408);
    }

v0388:
    v0408 = stack[0];
    v0408 = qcar(v0408);
    { popv(2); return onevalue(v0408); }
// error exit handlers
v0413:
    popv(2);
    return nil;
}



// Code for prim!-part

static LispObject CC_primKpart(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0399;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prim-part");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0399 = v0008;
// end of prologue
    stack[0] = v0399;
    fn = elt(env, 1); // comfac
    v0399 = (*qfn1(fn))(qenv(fn), v0399);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-1];
    fn = elt(env, 2); // comfac!-to!-poly
    v0399 = (*qfn1(fn))(qenv(fn), v0399);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-1];
    {
        LispObject v0002 = stack[0];
        popv(2);
        fn = elt(env, 3); // quotf1
        return (*qfn2(fn))(qenv(fn), v0002, v0399);
    }
// error exit handlers
v0001:
    popv(2);
    return nil;
}



// Code for lto_setminus

static LispObject CC_lto_setminus(LispObject env,
                         LispObject v0008, LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0377, v0484, v0485;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_setminus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0008,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0000;
    v0377 = v0008;
// end of prologue
    stack[-4] = v0377;
    goto v0084;

v0084:
    v0377 = stack[-4];
    if (v0377 == nil) goto v0400;
    v0377 = stack[-4];
    v0377 = qcar(v0377);
    v0485 = v0377;
    v0484 = v0485;
    v0377 = stack[-3];
    v0377 = Lmember(nil, v0484, v0377);
    if (v0377 == nil) goto v0003;
    v0377 = nil;
    goto v0420;

v0420:
    stack[-2] = v0377;
    v0377 = stack[-2];
    fn = elt(env, 2); // lastpair
    v0377 = (*qfn1(fn))(qenv(fn), v0377);
    nil = C_nil;
    if (exception_pending()) goto v0421;
    env = stack[-5];
    stack[-1] = v0377;
    v0377 = stack[-4];
    v0377 = qcdr(v0377);
    stack[-4] = v0377;
    v0377 = stack[-1];
    if (!consp(v0377)) goto v0084;
    else goto v0403;

v0403:
    v0377 = stack[-4];
    if (v0377 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0377 = stack[-4];
    v0377 = qcar(v0377);
    v0485 = v0377;
    v0484 = v0485;
    v0377 = stack[-3];
    v0377 = Lmember(nil, v0484, v0377);
    if (v0377 == nil) goto v0410;
    v0377 = nil;
    goto v0412;

v0412:
    v0377 = Lrplacd(nil, stack[0], v0377);
    nil = C_nil;
    if (exception_pending()) goto v0421;
    env = stack[-5];
    v0377 = stack[-1];
    fn = elt(env, 2); // lastpair
    v0377 = (*qfn1(fn))(qenv(fn), v0377);
    nil = C_nil;
    if (exception_pending()) goto v0421;
    env = stack[-5];
    stack[-1] = v0377;
    v0377 = stack[-4];
    v0377 = qcdr(v0377);
    stack[-4] = v0377;
    goto v0403;

v0410:
    v0377 = v0485;
    v0377 = ncons(v0377);
    nil = C_nil;
    if (exception_pending()) goto v0421;
    env = stack[-5];
    goto v0412;

v0003:
    v0377 = v0485;
    v0377 = ncons(v0377);
    nil = C_nil;
    if (exception_pending()) goto v0421;
    env = stack[-5];
    goto v0420;

v0400:
    v0377 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0377); }
// error exit handlers
v0421:
    popv(6);
    return nil;
}



// Code for quotientml

static LispObject CC_quotientml(LispObject env,
                         LispObject v0008)
{
    LispObject nil = C_nil;
    LispObject v0280, v0281;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotientml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0008);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0008;
// end of prologue
    v0280 = stack[0];
    v0280 = qcar(v0280);
    if (!(is_number(v0280))) goto v0391;
    v0280 = stack[0];
    v0280 = qcdr(v0280);
    v0280 = qcar(v0280);
    if (!(is_number(v0280))) goto v0391;
    v0280 = qvalue(elt(env, 1)); // !*web
    if (v0280 == nil) goto v0393;
    v0280 = elt(env, 3); // "<cn type=&quot;rational&quot;> "
    fn = elt(env, 9); // printout
    v0280 = (*qfn1(fn))(qenv(fn), v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    goto v0319;

v0319:
    v0280 = stack[0];
    v0280 = qcar(v0280);
    v0280 = Lprinc(nil, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    v0280 = elt(env, 4); // " <sep/> "
    v0280 = Lprinc(nil, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    v0280 = stack[0];
    v0280 = qcdr(v0280);
    v0280 = qcar(v0280);
    v0280 = Lprinc(nil, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    v0280 = elt(env, 5); // " </cn>"
    v0280 = Lprinc(nil, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    goto v0009;

v0009:
    v0280 = nil;
    { popv(2); return onevalue(v0280); }

v0393:
    v0280 = elt(env, 2); // "<cn type=""rational""> "
    fn = elt(env, 9); // printout
    v0280 = (*qfn1(fn))(qenv(fn), v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    goto v0319;

v0391:
    v0280 = elt(env, 6); // "<apply><divide/>"
    fn = elt(env, 9); // printout
    v0280 = (*qfn1(fn))(qenv(fn), v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    v0281 = qvalue(elt(env, 7)); // indent
    v0280 = (LispObject)49; // 3
    v0280 = plus2(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    qvalue(elt(env, 7)) = v0280; // indent
    v0280 = stack[0];
    v0280 = qcar(v0280);
    fn = elt(env, 10); // expression
    v0280 = (*qfn1(fn))(qenv(fn), v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    v0280 = stack[0];
    v0280 = qcdr(v0280);
    v0280 = qcar(v0280);
    fn = elt(env, 10); // expression
    v0280 = (*qfn1(fn))(qenv(fn), v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    v0281 = qvalue(elt(env, 7)); // indent
    v0280 = (LispObject)49; // 3
    v0280 = difference2(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-1];
    qvalue(elt(env, 7)) = v0280; // indent
    v0280 = elt(env, 8); // "</apply>"
    fn = elt(env, 9); // printout
    v0280 = (*qfn1(fn))(qenv(fn), v0280);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    goto v0009;
// error exit handlers
v0265:
    popv(2);
    return nil;
}



setup_type const u42_setup[] =
{
    {"conditionrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_conditionrd},
    {"ieval",                   CC_ieval,       too_many_1,    wrong_no_1},
    {"znumrnil",                CC_znumrnil,    too_many_1,    wrong_no_1},
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"letmtr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr},
    {"xpartitop",               CC_xpartitop,   too_many_1,    wrong_no_1},
    {"r2oaddspecies",           too_few_2,      CC_r2oaddspecies,wrong_no_2},
    {"mk_simpl_map_",           CC_mk_simpl_map_,too_many_1,   wrong_no_1},
    {"dfp-rule-found",          too_few_2,      CC_dfpKruleKfound,wrong_no_2},
    {"mv-compact2",             too_few_2,      CC_mvKcompact2,wrong_no_2},
    {"prepcadr",                CC_prepcadr,    too_many_1,    wrong_no_1},
    {"general-multiply-by-constant-mod-p",too_few_2,CC_generalKmultiplyKbyKconstantKmodKp,wrong_no_2},
    {"rl_nnfnot",               CC_rl_nnfnot,   too_many_1,    wrong_no_1},
    {"ofsf_simplequal",         too_few_2,      CC_ofsf_simplequal,wrong_no_2},
    {"enter-sorted",            too_few_2,      CC_enterKsorted,wrong_no_2},
    {"factor-prim-sqfree-f",    CC_factorKprimKsqfreeKf,too_many_1,wrong_no_1},
    {"cols2rows2",              too_few_2,      CC_cols2rows2, wrong_no_2},
    {"ldf-dep-var",             CC_ldfKdepKvar, too_many_1,    wrong_no_1},
    {"dipdivmon",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipdivmon},
    {"ndepends",                too_few_2,      CC_ndepends,   wrong_no_2},
    {"make_spoly_pair",         too_few_2,      CC_make_spoly_pair,wrong_no_2},
    {"ev-poles",                too_few_2,      CC_evKpoles,   wrong_no_2},
    {"evaluate-in-order-mod-p", too_few_2,      CC_evaluateKinKorderKmodKp,wrong_no_2},
    {"mkcrn",                   too_few_2,      CC_mkcrn,      wrong_no_2},
    {"even_action",             too_few_2,      CC_even_action,wrong_no_2},
    {"rule",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_rule},
    {"nlist",                   too_few_2,      CC_nlist,      wrong_no_2},
    {"makecoeffpairshom",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairshom},
    {"depend-f",                too_few_2,      CC_dependKf,   wrong_no_2},
    {"iv_cutn",                 CC_iv_cutn,     too_many_1,    wrong_no_1},
    {"vdp_getprop",             too_few_2,      CC_vdp_getprop,wrong_no_2},
    {"lowupperlimitml",         CC_lowupperlimitml,too_many_1, wrong_no_1},
    {"findhr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_findhr},
    {"wedgewedge",              too_few_2,      CC_wedgewedge, wrong_no_2},
    {"gfstorval",               too_few_2,      CC_gfstorval,  wrong_no_2},
    {"all_defined_map_",        too_few_2,      CC_all_defined_map_,wrong_no_2},
    {"evalletsub",              too_few_2,      CC_evalletsub, wrong_no_2},
    {"prim-part",               CC_primKpart,   too_many_1,    wrong_no_1},
    {"lto_setminus",            too_few_2,      CC_lto_setminus,wrong_no_2},
    {"quotientml",              CC_quotientml,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u42", (two_args *)"5886 9180773 4933778", 0}
};

// end of generated code
