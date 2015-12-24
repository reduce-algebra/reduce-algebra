
// $destdir/u06.c        Machine generated C code

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



// Code for delete_from_alglist

static LispObject CC_delete_from_alglist(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0004, v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete_from_alglist");
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
    stack[0] = v0001;
    v0005 = v0000;
// end of prologue
    v0004 = stack[0];
    if (v0004 == nil) goto v0006;
    v0004 = stack[0];
    fn = elt(env, 2); // remhash
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }

v0006:
    v0004 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0004); }
// error exit handlers
v0007:
    popv(1);
    return nil;
}



// Code for mri_0mk2

static LispObject CC_mri_0mk2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0003, v0012, v0004, v0005;
    LispObject v0011, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mri_0mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0004 = v0011;
    v0003 = v0001;
    v0012 = v0000;
// end of prologue
    v0005 = qvalue(elt(env, 1)); // nil
    return list4(v0012, v0003, v0005, v0004);
}



// Code for pasf_susipost

static LispObject CC_pasf_susipost(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject v0013, v0006;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_susipost");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0013 = v0001;
    v0006 = v0000;
// end of prologue
    return onevalue(v0006);
}



// Code for sortcolelem

static LispObject CC_sortcolelem(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0028, v0029;
    LispObject v0011, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sortcolelem");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sortcolelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0011,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0011;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    stack[0] = nil;
    v0028 = stack[-2];
    v0028 = qcdr(v0028);
    stack[-4] = v0028;
    goto v0030;

v0030:
    v0028 = stack[0];
    if (v0028 == nil) goto v0009;
    v0028 = nil;
    { popv(6); return onevalue(v0028); }

v0009:
    v0028 = stack[-4];
    if (v0028 == nil) goto v0031;
    v0029 = stack[-3];
    v0028 = stack[-4];
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    v0028 = (LispObject)lessp2(v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0028 = v0028 ? lisp_true : nil;
    env = stack[-5];
    if (v0028 == nil) goto v0033;
    stack[0] = stack[-2];
    v0029 = stack[-3];
    v0028 = stack[-1];
    v0028 = cons(v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0029 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0028 = stack[-4];
    v0028 = Lrplacd(nil, v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0028 = Lrplacd(nil, stack[0], v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0028 = qvalue(elt(env, 2)); // t
    stack[0] = v0028;
    goto v0030;

v0033:
    v0029 = stack[-3];
    v0028 = stack[-4];
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    v0028 = (LispObject)greaterp2(v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0028 = v0028 ? lisp_true : nil;
    env = stack[-5];
    if (v0028 == nil) goto v0030;
    v0028 = qvalue(elt(env, 1)); // nil
    stack[0] = v0028;
    v0028 = stack[-2];
    v0028 = qcdr(v0028);
    stack[-2] = v0028;
    v0028 = stack[-2];
    v0028 = qcdr(v0028);
    stack[-4] = v0028;
    goto v0030;

v0031:
    stack[0] = stack[-2];
    v0029 = stack[-3];
    v0028 = stack[-1];
    v0028 = cons(v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0028 = Lrplacd(nil, stack[0], v0028);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-5];
    v0028 = qvalue(elt(env, 2)); // t
    stack[0] = v0028;
    goto v0030;
// error exit handlers
v0032:
    popv(6);
    return nil;
}



// Code for fast!-column!-dim

static LispObject CC_fastKcolumnKdim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0030, v0036;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fast-column-dim");
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
    v0030 = v0000;
// end of prologue
    v0036 = v0030;
    v0030 = (LispObject)1; // 0
    v0030 = *(LispObject *)((char *)v0036 + (CELL-TAG_VECTOR) + ((int32_t)v0030/(16/CELL)));
    v0030 = Lupbv(nil, v0030);
    errexit();
    return add1(v0030);
}



// Code for evtdeg

static LispObject CC_evtdeg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0031, v0038, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evtdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0038 = v0000;
// end of prologue
    v0031 = (LispObject)1; // 0
    goto v0040;

v0040:
    v0039 = v0038;
    if (v0039 == nil) return onevalue(v0031);
    v0039 = v0038;
    v0039 = qcar(v0039);
    v0031 = (LispObject)(int32_t)((int32_t)v0039 + (int32_t)v0031 - TAG_FIXNUM);
    v0038 = qcdr(v0038);
    goto v0040;
}



// Code for algid

static LispObject CC_algid(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0041, v0031, v0038;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for algid");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0041 = v0001;
    v0031 = v0000;
// end of prologue
    v0038 = v0031;
    v0041 = Latsoc(nil, v0038, v0041);
    if (!(v0041 == nil)) return onevalue(v0031);
    v0041 = v0031;
    if (!symbolp(v0041)) v0041 = nil;
    else { v0041 = qfastgets(v0041);
           if (v0041 != nil) { v0041 = elt(v0041, 17); // share
#ifdef RECORD_GET
             if (v0041 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0041 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0041 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0041 == SPID_NOPROP) v0041 = nil; else v0041 = lisp_true; }}
#endif
    if (!(v0041 == nil)) return onevalue(v0031);
    v0041 = v0031;
        return Lmkquote(nil, v0041);
}



// Code for csl_timbf

static LispObject CC_csl_timbf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0051, v0052, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for csl_timbf");
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
    v0051 = stack[-3];
    v0051 = qcdr(v0051);
    v0052 = qcar(v0051);
    v0051 = stack[-2];
    v0051 = qcdr(v0051);
    v0051 = qcar(v0051);
    v0051 = times2(v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-5];
    v0053 = v0051;
    v0052 = v0053;
    v0051 = (LispObject)1; // 0
    if (v0052 == v0051) goto v0004;
    v0052 = v0053;
    v0051 = qvalue(elt(env, 2)); // !:bprec!:
    fn = elt(env, 4); // inorm
    v0051 = (*qfn2(fn))(qenv(fn), v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-5];
    v0053 = v0051;
    stack[-4] = elt(env, 3); // !:rd!:
    v0051 = v0053;
    stack[-1] = qcar(v0051);
    v0051 = v0053;
    stack[0] = qcdr(v0051);
    v0051 = stack[-3];
    v0051 = qcdr(v0051);
    v0052 = qcdr(v0051);
    v0051 = stack[-2];
    v0051 = qcdr(v0051);
    v0051 = qcdr(v0051);
    v0051 = plus2(v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-5];
    v0051 = plus2(stack[0], v0051);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    {
        LispObject v0055 = stack[-4];
        LispObject v0056 = stack[-1];
        popv(6);
        return list2star(v0055, v0056, v0051);
    }

v0004:
    v0051 = elt(env, 1); // (!:rd!: 0 . 0)
    { popv(6); return onevalue(v0051); }
// error exit handlers
v0054:
    popv(6);
    return nil;
}



// Code for safe!-fp!-minus

static LispObject CC_safeKfpKminus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005, v0057, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for safe-fp-minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0000;
// end of prologue
    v0005 = qvalue(elt(env, 1)); // !*nonegzerominus
    if (v0005 == nil) goto v0002;
    v0057 = v0007;
    v0005 = elt(env, 2); // 0.0
    if (!(equal(v0057, v0005))) goto v0002;
    v0005 = elt(env, 2); // 0.0
    return onevalue(v0005);

v0002:
    v0005 = v0007;
    return negate(v0005);
}



// Code for getrmacro

static LispObject CC_getrmacro(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0046, v0018, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrmacro");
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
    v0046 = stack[0];
    if (symbolp(v0046)) goto v0065;
    v0046 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0046); }

v0065:
    v0046 = stack[0];
    fn = elt(env, 5); // getd
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    v0064 = v0046;
    if (v0046 == nil) goto v0066;
    v0046 = v0064;
    v0018 = qcar(v0046);
    v0046 = elt(env, 2); // macro
    if (v0018 == v0046) { popv(2); return onevalue(v0064); }
    else goto v0066;

v0066:
    v0018 = stack[0];
    v0046 = elt(env, 3); // inline
    v0046 = get(v0018, v0046);
    env = stack[-1];
    v0064 = v0046;
    if (v0046 == nil) goto v0067;
    v0046 = elt(env, 3); // inline
    v0018 = v0064;
    popv(2);
    return cons(v0046, v0018);

v0067:
    v0018 = stack[0];
    v0046 = elt(env, 4); // smacro
    v0046 = get(v0018, v0046);
    env = stack[-1];
    v0064 = v0046;
    if (v0046 == nil) goto v0068;
    v0046 = elt(env, 4); // smacro
    v0018 = v0064;
    popv(2);
    return cons(v0046, v0018);

v0068:
    v0046 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0046); }
// error exit handlers
v0051:
    popv(2);
    return nil;
}



// Code for getelv

static LispObject CC_getelv(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0071, v0072;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getelv");
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
    v0072 = v0000;
// end of prologue
    v0071 = v0072;
    stack[-4] = qcar(v0071);
    v0071 = v0072;
    v0071 = qcdr(v0071);
    stack[-3] = v0071;
    v0071 = stack[-3];
    if (v0071 == nil) goto v0005;
    v0071 = stack[-3];
    v0071 = qcar(v0071);
    fn = elt(env, 2); // reval_without_mod
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0071 = ncons(v0071);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-1] = v0071;
    stack[-2] = v0071;
    goto v0010;

v0010:
    v0071 = stack[-3];
    v0071 = qcdr(v0071);
    stack[-3] = v0071;
    v0071 = stack[-3];
    if (v0071 == nil) goto v0063;
    stack[0] = stack[-1];
    v0071 = stack[-3];
    v0071 = qcar(v0071);
    fn = elt(env, 2); // reval_without_mod
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0071 = ncons(v0071);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0071 = Lrplacd(nil, stack[0], v0071);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0071 = stack[-1];
    v0071 = qcdr(v0071);
    stack[-1] = v0071;
    goto v0010;

v0063:
    v0071 = stack[-2];
    goto v0073;

v0073:
    v0071 = cons(stack[-4], v0071);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 3); // getel
        return (*qfn1(fn))(qenv(fn), v0071);
    }

v0005:
    v0071 = qvalue(elt(env, 1)); // nil
    goto v0073;
// error exit handlers
v0058:
    popv(6);
    return nil;
}



// Code for dp_diff

static LispObject CC_dp_diff(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0030, v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_diff");
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
    v0030 = v0001;
    v0036 = v0000;
// end of prologue
    stack[0] = v0036;
    fn = elt(env, 1); // dp_neg
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    {
        LispObject v0010 = stack[0];
        popv(2);
        fn = elt(env, 2); // dp_sum
        return (*qfn2(fn))(qenv(fn), v0010, v0030);
    }
// error exit handlers
v0008:
    popv(2);
    return nil;
}



// Code for tsym4

static LispObject CC_tsym4(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0076, v0069;
    LispObject fn;
    LispObject v0011, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "tsym4");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tsym4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0011,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0001;
    v0076 = v0000;
// end of prologue

v0073:
    v0069 = v0076;
    if (v0069 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0069 = v0076;
    v0069 = qcdr(v0069);
    stack[-2] = v0069;
    v0069 = stack[-1];
    v0069 = qcdr(v0069);
    v0076 = qcar(v0076);
    fn = elt(env, 1); // pv_applp
    v0069 = (*qfn2(fn))(qenv(fn), v0069, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    v0076 = stack[0];
    fn = elt(env, 2); // sieve_pv
    v0076 = (*qfn2(fn))(qenv(fn), v0069, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    fn = elt(env, 3); // pv_renorm
    v0069 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    v0076 = stack[0];
    fn = elt(env, 4); // insert_pv
    v0076 = (*qfn2(fn))(qenv(fn), v0069, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    stack[0] = v0076;
    v0076 = stack[-2];
    goto v0073;
// error exit handlers
v0022:
    popv(4);
    return nil;
}



// Code for gcddd

static LispObject CC_gcddd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0084, v0085, v0086;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcddd");
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
    v0085 = stack[-1];
    v0084 = (LispObject)17; // 1
    if (v0085 == v0084) goto v0034;
    v0085 = stack[0];
    v0084 = (LispObject)17; // 1
    v0084 = (v0085 == v0084 ? lisp_true : nil);
    goto v0065;

v0065:
    if (v0084 == nil) goto v0040;
    v0084 = (LispObject)17; // 1
    { popv(3); return onevalue(v0084); }

v0040:
    v0084 = stack[-1];
    if (!consp(v0084)) goto v0024;
    v0084 = stack[0];
    if (!consp(v0084)) goto v0087;
    v0084 = stack[-1];
    v0084 = qcar(v0084);
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 3); // field
#ifdef RECORD_GET
             if (v0084 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0084 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0084 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; else v0084 = lisp_true; }}
#endif
    if (v0084 == nil) goto v0088;
    v0084 = qvalue(elt(env, 1)); // t
    goto v0089;

v0089:
    if (v0084 == nil) goto v0090;
    v0084 = (LispObject)17; // 1
    { popv(3); return onevalue(v0084); }

v0090:
    v0086 = stack[-1];
    v0085 = stack[0];
    v0084 = elt(env, 2); // gcd
    {
        popv(3);
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0086, v0085, v0084);
    }

v0088:
    v0084 = stack[0];
    v0084 = qcar(v0084);
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 3); // field
#ifdef RECORD_GET
             if (v0084 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0084 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0084 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; else v0084 = lisp_true; }}
#endif
    goto v0089;

v0087:
    v0084 = stack[-1];
    v0084 = qcar(v0084);
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 3); // field
#ifdef RECORD_GET
             if (v0084 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0084 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0084 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; else v0084 = lisp_true; }}
#endif
    if (v0084 == nil) goto v0055;
    v0084 = (LispObject)17; // 1
    { popv(3); return onevalue(v0084); }

v0055:
    v0086 = stack[-1];
    v0085 = stack[0];
    v0084 = elt(env, 2); // gcd
    {
        popv(3);
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0086, v0085, v0084);
    }

v0024:
    v0084 = stack[0];
    if (!consp(v0084)) goto v0027;
    v0084 = stack[0];
    fn = elt(env, 4); // fieldp
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    if (v0084 == nil) goto v0071;
    v0084 = (LispObject)17; // 1
    { popv(3); return onevalue(v0084); }

v0071:
    v0086 = stack[-1];
    v0085 = stack[0];
    v0084 = elt(env, 2); // gcd
    {
        popv(3);
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0086, v0085, v0084);
    }

v0027:
    v0085 = stack[-1];
    v0084 = stack[0];
        popv(3);
        return Lgcd(nil, v0085, v0084);

v0034:
    v0084 = qvalue(elt(env, 1)); // t
    goto v0065;
// error exit handlers
v0091:
    popv(3);
    return nil;
}



// Code for lalr_action

static LispObject CC_lalr_action(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0012, v0004, v0005;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_action");
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
    v0004 = v0001;
    v0012 = v0000;
// end of prologue
    v0005 = v0004;
    v0004 = v0012;
    v0012 = elt(env, 1); // produces
    v0012 = get(v0004, v0012);
    v0012 = Lassoc(nil, v0005, v0012);
    v0012 = qcdr(v0012);
    return onevalue(v0012);
}



// Code for xread

static LispObject CC_xread(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xread");
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

v0013:
    fn = elt(env, 4); // scan
    v0057 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    v0057 = qvalue(elt(env, 1)); // !*eoldelimp
    if (v0057 == nil) goto v0073;
    v0007 = qvalue(elt(env, 2)); // cursym!*
    v0057 = elt(env, 3); // !*semicol!*
    if (v0007 == v0057) goto v0013;
    else goto v0073;

v0073:
    v0057 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // xread1
        return (*qfn1(fn))(qenv(fn), v0057);
    }
// error exit handlers
v0031:
    popv(2);
    return nil;
}



// Code for sfto_gcdf!*

static LispObject CC_sfto_gcdfH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0036, v0009, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_gcdf*");
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
    v0009 = v0001;
    v0008 = v0000;
// end of prologue
    v0036 = qvalue(elt(env, 1)); // t
    stack[0] = qvalue(elt(env, 2)); // !*gcd
    qvalue(elt(env, 2)) = v0036; // !*gcd
    v0036 = v0008;
    fn = elt(env, 3); // sfto_gcdf
    v0036 = (*qfn2(fn))(qenv(fn), v0036, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*gcd
    { popv(2); return onevalue(v0036); }
// error exit handlers
v0002:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*gcd
    popv(2);
    return nil;
}



// Code for removev

static LispObject CC_removev(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0042, v0022, v0094, v0095;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removev");
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
    v0095 = v0001;
    v0094 = v0000;
// end of prologue

v0006:
    v0042 = v0094;
    if (v0042 == nil) goto v0036;
    v0042 = v0094;
    v0042 = qcdr(v0042);
    v0022 = qcar(v0042);
    v0042 = v0095;
    if (v0022 == v0042) goto v0063;
    v0042 = v0094;
    v0042 = qcdr(v0042);
    v0094 = v0042;
    goto v0006;

v0063:
    v0042 = v0094;
    v0022 = v0094;
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
        popv(1);
        return Lrplacd(nil, v0042, v0022);

v0036:
    v0022 = elt(env, 1); // "Vertex"
    v0094 = v0095;
    v0042 = elt(env, 2); // "is absent."
    v0042 = list3(v0022, v0094, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // cerror
        return (*qfn1(fn))(qenv(fn), v0042);
    }
// error exit handlers
v0023:
    popv(1);
    return nil;
}



// Code for omobj

static LispObject CC_omobj(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0050, v0066;
    LispObject fn;
    argcheck(nargs, 0, "omobj");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omobj");
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
    v0050 = qvalue(elt(env, 1)); // char
    fn = elt(env, 4); // compress!*
    v0066 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    v0050 = qvalue(elt(env, 2)); // omfuncs!*
    v0050 = Lassoc(nil, v0066, v0050);
    v0066 = v0050;
    if (v0050 == nil) goto v0040;
    v0050 = v0066;
    v0050 = qcdr(v0050);
    v0066 = qcar(v0050);
    v0050 = qvalue(elt(env, 3)); // nil
    {
        popv(1);
        fn = elt(env, 5); // apply
        return (*qfn2(fn))(qenv(fn), v0066, v0050);
    }

v0040:
    v0050 = nil;
    { popv(1); return onevalue(v0050); }
// error exit handlers
v0024:
    popv(1);
    return nil;
}



// Code for mk!*sq

static LispObject CC_mkHsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0056, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk*sq");
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
    v0056 = v0000;
// end of prologue
    fn = elt(env, 6); // expchk
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    stack[0] = v0056;
    v0056 = stack[0];
    v0056 = qcar(v0056);
    if (v0056 == nil) goto v0073;
    v0056 = stack[0];
    v0056 = qcar(v0056);
    if (!consp(v0056)) goto v0004;
    v0056 = qvalue(elt(env, 1)); // nil
    goto v0008;

v0008:
    if (v0056 == nil) goto v0036;
    v0056 = stack[0];
    v0056 = qcar(v0056);
    { popv(3); return onevalue(v0056); }

v0036:
    v0056 = stack[0];
    fn = elt(env, 7); // kernp
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    if (v0056 == nil) goto v0017;
    v0056 = stack[0];
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0033 = qcar(v0056);
    v0056 = elt(env, 2); // list
    if (!consp(v0033)) goto v0017;
    v0033 = qcar(v0033);
    if (!(v0033 == v0056)) goto v0017;
    v0056 = stack[0];
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    { popv(3); return onevalue(v0056); }

v0017:
    stack[-1] = elt(env, 3); // !*sq
    v0056 = qvalue(elt(env, 4)); // !*resubs
    if (v0056 == nil) goto v0019;
    v0056 = qvalue(elt(env, 5)); // !*sqvar!*
    goto v0046;

v0046:
    {
        LispObject v0097 = stack[-1];
        LispObject v0014 = stack[0];
        popv(3);
        return list2star(v0097, v0014, v0056);
    }

v0019:
    v0056 = qvalue(elt(env, 1)); // nil
    v0056 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    goto v0046;

v0004:
    v0056 = stack[0];
    v0033 = qcdr(v0056);
    v0056 = (LispObject)17; // 1
    v0056 = (v0033 == v0056 ? lisp_true : nil);
    goto v0008;

v0073:
    v0056 = (LispObject)1; // 0
    { popv(3); return onevalue(v0056); }
// error exit handlers
v0096:
    popv(3);
    return nil;
}



// Code for comm_kernels

static LispObject CC_comm_kernels(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035, v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comm_kernels");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0035 = v0000;
// end of prologue
    v0070 = v0035;
    v0035 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // comm_kernels1
        return (*qfn2(fn))(qenv(fn), v0070, v0035);
    }
}



// Code for !:times

static LispObject CC_Ttimes(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0095, v0023, v0059;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0023 = v0001;
    v0059 = v0000;
// end of prologue
    v0095 = v0059;
    if (v0095 == nil) goto v0034;
    v0095 = v0023;
    v0095 = (v0095 == nil ? lisp_true : nil);
    goto v0065;

v0065:
    if (v0095 == nil) goto v0040;
    v0095 = qvalue(elt(env, 2)); // nil
    return onevalue(v0095);

v0040:
    v0095 = v0059;
    if (!consp(v0095)) goto v0057;
    v0095 = qvalue(elt(env, 2)); // nil
    goto v0005;

v0005:
    if (v0095 == nil) goto v0069;
    v0095 = v0059;
    return times2(v0095, v0023);

v0069:
    v0095 = elt(env, 3); // times
    {
        fn = elt(env, 4); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0059, v0023, v0095);
    }

v0057:
    v0095 = v0023;
    v0095 = (consp(v0095) ? nil : lisp_true);
    goto v0005;

v0034:
    v0095 = qvalue(elt(env, 1)); // t
    goto v0065;
}



// Code for areallindices

static LispObject CC_areallindices(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for areallindices");
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

v0098:
    v0041 = stack[0];
    v0041 = qcar(v0041);
    fn = elt(env, 3); // isanindex
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    if (v0041 == nil) goto v0013;
    v0041 = stack[0];
    v0041 = qcdr(v0041);
    if (v0041 == nil) goto v0009;
    v0041 = stack[0];
    v0041 = qcdr(v0041);
    stack[0] = v0041;
    goto v0098;

v0009:
    v0041 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0041); }

v0013:
    v0041 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0041); }
// error exit handlers
v0038:
    popv(2);
    return nil;
}



// Code for !*ssave

static LispObject CC_Hssave(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0028, v0029, v0100;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *ssave");
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
    v0028 = qvalue(elt(env, 1)); // !*uncached
    if (!(v0028 == nil)) goto v0040;
    stack[-4] = qvalue(elt(env, 2)); // alglist!*
    v0029 = qvalue(elt(env, 3)); // !*sub2
    v0028 = stack[-3];
    v0029 = cons(v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    v0028 = qvalue(elt(env, 2)); // alglist!*
    v0028 = qcar(v0028);
    stack[-1] = v0029;
    stack[0] = v0028;
    v0028 = stack[0];
    if (v0028 == nil) goto v0063;
    v0029 = qvalue(elt(env, 5)); // alglist_count!*
    v0028 = qvalue(elt(env, 6)); // alglist_limit!*
    v0028 = (LispObject)greaterp2(v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    v0028 = v0028 ? lisp_true : nil;
    env = stack[-5];
    goto v0062;

v0062:
    if (v0028 == nil) goto v0056;
    v0028 = (LispObject)1; // 0
    qvalue(elt(env, 5)) = v0028; // alglist_count!*
    v0100 = (LispObject)161; // 10
    v0029 = (LispObject)49; // 3
    v0028 = elt(env, 7); // 2.0
    fn = elt(env, 9); // mkhash
    v0028 = (*qfnn(fn))(qenv(fn), 3, v0100, v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    stack[0] = v0028;
    v0100 = stack[-2];
    v0029 = stack[0];
    v0028 = stack[-1];
    fn = elt(env, 10); // puthash
    v0028 = (*qfnn(fn))(qenv(fn), 3, v0100, v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    v0028 = stack[0];
    goto v0009;

v0009:
    v0028 = Lrplaca(nil, stack[-4], v0028);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    goto v0040;

v0040:
    v0028 = qvalue(elt(env, 8)); // simpcount!*
    v0028 = sub1(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    qvalue(elt(env, 8)) = v0028; // simpcount!*
    { LispObject res = stack[-3]; popv(6); return onevalue(res); }

v0056:
    v0100 = stack[-2];
    v0029 = stack[0];
    v0028 = stack[-1];
    fn = elt(env, 10); // puthash
    v0028 = (*qfnn(fn))(qenv(fn), 3, v0100, v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    v0028 = qvalue(elt(env, 5)); // alglist_count!*
    v0028 = add1(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    qvalue(elt(env, 5)) = v0028; // alglist_count!*
    v0028 = stack[0];
    goto v0009;

v0063:
    v0028 = qvalue(elt(env, 4)); // t
    goto v0062;
// error exit handlers
v0101:
    popv(6);
    return nil;
}



// Code for red!-weight

static LispObject CC_redKweight(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0012, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-weight");
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
    v0012 = stack[-1];
    fn = elt(env, 1); // nonzero!-length
    stack[-2] = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-3];
    v0004 = stack[-1];
    v0012 = stack[0];
    fn = elt(env, 2); // red!-weight1
    v0012 = (*qfn2(fn))(qenv(fn), v0004, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    {
        LispObject v0031 = stack[-2];
        popv(4);
        return cons(v0031, v0012);
    }
// error exit handlers
v0041:
    popv(4);
    return nil;
}



// Code for bc!=simp

static LispObject CC_bcMsimp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0103, v0032;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc=simp");
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
    v0103 = elt(env, 1); // cali
    if (!symbolp(v0103)) v0103 = nil;
    else { v0103 = qfastgets(v0103);
           if (v0103 != nil) { v0103 = elt(v0103, 20); // rules
#ifdef RECORD_GET
             if (v0103 != SPID_NOPROP)
                record_get(elt(fastget_names, 20), 1);
             else record_get(elt(fastget_names, 20), 0),
                v0103 = nil; }
           else record_get(elt(fastget_names, 20), 0); }
#else
             if (v0103 == SPID_NOPROP) v0103 = nil; }}
#endif
    stack[-4] = v0103;
    v0103 = stack[-4];
    if (v0103 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0103 = (LispObject)1; // 0
    stack[0] = v0103;
    v0103 = stack[-4];
    stack[-2] = v0103;
    goto v0004;

v0004:
    v0103 = stack[-2];
    if (v0103 == nil) goto v0081;
    v0032 = stack[0];
    v0103 = (LispObject)16001; // 1000
    v0103 = (LispObject)lessp2(v0032, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    v0103 = v0103 ? lisp_true : nil;
    env = stack[-5];
    if (v0103 == nil) goto v0081;
    v0032 = stack[-3];
    v0103 = stack[-2];
    v0103 = qcar(v0103);
    v0103 = qcar(v0103);
    fn = elt(env, 4); // qremf
    v0103 = (*qfn2(fn))(qenv(fn), v0032, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    stack[-1] = v0103;
    v0103 = stack[-1];
    v0103 = qcar(v0103);
    if (v0103 == nil) goto v0022;
    v0103 = stack[-1];
    v0032 = qcar(v0103);
    v0103 = stack[-2];
    v0103 = qcar(v0103);
    v0103 = qcdr(v0103);
    fn = elt(env, 5); // multf
    v0032 = (*qfn2(fn))(qenv(fn), v0032, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0103 = stack[-1];
    v0103 = qcdr(v0103);
    fn = elt(env, 6); // addf
    v0103 = (*qfn2(fn))(qenv(fn), v0032, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    stack[-3] = v0103;
    v0103 = stack[0];
    v0103 = add1(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    stack[0] = v0103;
    v0103 = stack[-4];
    stack[-2] = v0103;
    goto v0004;

v0022:
    v0103 = stack[-2];
    v0103 = qcdr(v0103);
    stack[-2] = v0103;
    goto v0004;

v0081:
    v0032 = stack[0];
    v0103 = (LispObject)16001; // 1000
    v0103 = (LispObject)lessp2(v0032, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    v0103 = v0103 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0103 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0103 = elt(env, 3); // "recursion depth of bc!=simp too high"
    fn = elt(env, 7); // rederr
    v0103 = (*qfn1(fn))(qenv(fn), v0103);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    v0103 = nil;
    { popv(6); return onevalue(v0103); }
// error exit handlers
v0104:
    popv(6);
    return nil;
}



// Code for vecp

static LispObject CC_vecp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0109, v0110, v0111, v0077;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vecp");
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
    v0111 = v0000;
// end of prologue
    v0109 = v0111;
    if (v0109 == nil) goto v0070;
    v0109 = v0111;
    v0109 = (is_number(v0109) ? lisp_true : nil);
    goto v0035;

v0035:
    if (v0109 == nil) goto v0065;
    v0109 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0109); }

v0065:
    v0109 = v0111;
    if (!consp(v0109)) goto v0039;
    v0109 = v0111;
    v0109 = Lthreevectorp(nil, v0109);
    env = stack[0];
    if (v0109 == nil) goto v0074;
    v0109 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0109); }

v0074:
    v0109 = v0111;
    v0109 = qcar(v0109);
    v0077 = v0109;
    if (!consp(v0109)) goto v0059;
    v0109 = qvalue(elt(env, 2)); // nil
    goto v0042;

v0042:
    if (v0109 == nil) goto v0099;
    v0109 = v0111;
    v0109 = qcdr(v0109);
    v0109 = qcar(v0109);
    {
        popv(1);
        fn = elt(env, 7); // isvectorindex
        return (*qfn1(fn))(qenv(fn), v0109);
    }

v0099:
    v0110 = v0077;
    v0109 = elt(env, 4); // vectorfn
    v0109 = Lflagp(nil, v0110, v0109);
    env = stack[0];
    if (v0109 == nil) goto v0082;
    v0109 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0109); }

v0082:
    v0110 = v0077;
    v0109 = elt(env, 5); // varithop
    v0109 = Lflagp(nil, v0110, v0109);
    env = stack[0];
    if (v0109 == nil) goto v0088;
    v0109 = qvalue(elt(env, 1)); // t
    goto v0096;

v0096:
    if (v0109 == nil) goto v0104;
    v0109 = v0111;
    v0109 = qcdr(v0109);
    {
        popv(1);
        fn = elt(env, 8); // hasonevector
        return (*qfn1(fn))(qenv(fn), v0109);
    }

v0104:
    v0109 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0109); }

v0088:
    v0110 = v0077;
    v0109 = elt(env, 6); // vectormapping
    v0109 = Lflagp(nil, v0110, v0109);
    env = stack[0];
    goto v0096;

v0059:
    v0109 = v0077;
    if (!symbolp(v0109)) v0110 = nil;
    else { v0110 = qfastgets(v0109);
           if (v0110 != nil) { v0110 = elt(v0110, 2); // rtype
#ifdef RECORD_GET
             if (v0110 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0110 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0110 == SPID_NOPROP) v0110 = nil; }}
#endif
    v0109 = elt(env, 3); // !3vector
    v0109 = (v0110 == v0109 ? lisp_true : nil);
    goto v0042;

v0039:
    v0109 = v0111;
    if (!symbolp(v0109)) v0110 = nil;
    else { v0110 = qfastgets(v0109);
           if (v0110 != nil) { v0110 = elt(v0110, 2); // rtype
#ifdef RECORD_GET
             if (v0110 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0110 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0110 == SPID_NOPROP) v0110 = nil; }}
#endif
    v0109 = elt(env, 3); // !3vector
    if (v0110 == v0109) goto v0031;
    v0109 = v0111;
        popv(1);
        return Lthreevectorp(nil, v0109);

v0031:
    v0109 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0109); }

v0070:
    v0109 = qvalue(elt(env, 1)); // t
    goto v0035;
}



// Code for pv_sort2a

static LispObject CC_pv_sort2a(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0090, v0104;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_sort2a");
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

v0006:
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    if (v0090 == nil) goto v0002;
    v0090 = stack[-1];
    v0104 = qcdr(v0090);
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    v0090 = (LispObject)greaterp2(v0104, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0090 = v0090 ? lisp_true : nil;
    env = stack[-3];
    if (v0090 == nil) goto v0105;
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    stack[0] = v0090;
    goto v0006;

v0105:
    v0090 = stack[0];
    v0104 = qcar(v0090);
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    v0090 = cons(v0104, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    stack[-2] = v0090;
    v0104 = stack[0];
    v0090 = stack[-1];
    v0104 = Lrplaca(nil, v0104, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0090 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0104, v0090);

v0002:
    v0090 = stack[-1];
    v0104 = qcdr(v0090);
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    v0090 = (LispObject)greaterp2(v0104, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0090 = v0090 ? lisp_true : nil;
    env = stack[-3];
    if (v0090 == nil) goto v0027;
    v0090 = stack[-1];
    v0090 = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    {
        LispObject v0111 = stack[0];
        popv(4);
        return Lrplacd(nil, v0111, v0090);
    }

v0027:
    v0090 = stack[0];
    v0104 = qcar(v0090);
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    v0090 = cons(v0104, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    stack[-2] = v0090;
    v0104 = stack[0];
    v0090 = stack[-1];
    v0104 = Lrplaca(nil, v0104, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0090 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0104, v0090);
// error exit handlers
v0110:
    popv(4);
    return nil;
}



// Code for minus!-mod!-p

static LispObject CC_minusKmodKp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0072, v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minus-mod-p");
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
    goto v0006;

v0006:
    v0072 = stack[-1];
    if (v0072 == nil) goto v0065;
    v0072 = stack[-1];
    if (!consp(v0072)) goto v0002;
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    v0072 = (consp(v0072) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0072 == nil) goto v0026;
    v0044 = stack[-2];
    v0072 = stack[-1];
    {   int32_t w = int_of_fixnum(v0072);
        if (w != 0) w = current_modulus - w;
        v0072 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0044, v0072);
    }

v0026:
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    stack[0] = qcar(v0072);
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    v0072 = qcdr(v0072);
    v0044 = CC_minusKmodKp(env, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0072 = stack[-2];
    v0072 = acons(stack[0], v0044, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    stack[-2] = v0072;
    v0072 = stack[-1];
    v0072 = qcdr(v0072);
    stack[-1] = v0072;
    goto v0006;

v0002:
    v0072 = qvalue(elt(env, 1)); // t
    goto v0010;

v0065:
    v0072 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0072);
    }
// error exit handlers
v0017:
    popv(4);
    return nil;
}



// Code for set_svf

static LispObject CC_set_svf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0007, v0041, v0031;
    LispObject fn;
    LispObject v0037, v0011, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "set_svf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set_svf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0037,v0011,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0011,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0037;
    v0007 = v0011;
    v0041 = v0001;
    v0031 = v0000;
// end of prologue
    v0041 = list3(v0031, v0041, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0007 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); // setk
        return (*qfn2(fn))(qenv(fn), v0041, v0007);
    }
// error exit handlers
v0039:
    popv(2);
    return nil;
}



// Code for clear!-column

static LispObject CC_clearKcolumn(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0175, v0176, v0177, v0178, v0179, v0180, v0181, v0182, v0183, v0184;
    LispObject v0013, v0037, v0011, v0001;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "clear-column");
    va_start(aa, nargs);
    v0001 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for clear-column");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0013,v0037,v0011,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0001,v0011,v0037,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0037;
    v0175 = v0011;
    stack[-2] = v0001;
// end of prologue
    stack[-3] = qvalue(elt(env, 1)); // null!-space!-basis
    qvalue(elt(env, 1)) = nil; // null!-space!-basis
    qvalue(elt(env, 1)) = v0175; // null!-space!-basis
    v0175 = (LispObject)1; // 0
    goto v0062;

v0062:
    v0177 = stack[-1];
    v0176 = v0175;
    v0177 = *(LispObject *)((char *)v0177 + (CELL-TAG_VECTOR) + ((int32_t)v0176/(16/CELL)));
    v0176 = stack[-2];
    v0177 = *(LispObject *)((char *)v0177 + (CELL-TAG_VECTOR) + ((int32_t)v0176/(16/CELL)));
    v0176 = (LispObject)1; // 0
    if (v0177 == v0176) goto v0057;
    v0177 = v0175;
    v0176 = stack[-2];
    if (((int32_t)(v0177)) < ((int32_t)(v0176))) goto v0099;
    v0176 = qvalue(elt(env, 3)); // nil
    goto v0005;

v0005:
    if (v0176 == nil) goto v0090;
    v0177 = (LispObject)((int32_t)(v0175) + 0x10);
    v0175 = v0177;
    v0176 = stack[0];
    if (!(((int32_t)(v0177)) > ((int32_t)(v0176)))) goto v0062;
    v0176 = stack[-2];
    v0175 = qvalue(elt(env, 1)); // null!-space!-basis
    v0175 = cons(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    goto v0065;

v0065:
    qvalue(elt(env, 1)) = stack[-3]; // null!-space!-basis
    { popv(5); return onevalue(v0175); }

v0090:
    v0177 = stack[-1];
    v0176 = v0175;
    v0176 = *(LispObject *)((char *)v0177 + (CELL-TAG_VECTOR) + ((int32_t)v0176/(16/CELL)));
    v0184 = v0176;
    v0178 = stack[-1];
    v0177 = v0175;
    v0176 = stack[-1];
    v0175 = stack[-2];
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    *(LispObject *)((char *)v0178 + (CELL-TAG_VECTOR) + ((int32_t)v0177/(16/CELL))) = v0175;
    v0176 = stack[-1];
    v0175 = stack[-2];
    v0177 = v0184;
    *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL))) = v0177;
    v0176 = stack[-1];
    v0175 = stack[-2];
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = stack[-2];
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = Lmodular_reciprocal(nil, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0175);
        if (w != 0) w = current_modulus - w;
        v0175 = fixnum_of_int(w);
    }
    v0184 = v0175;
    v0175 = (LispObject)1; // 0
    v0183 = v0175;
    goto v0186;

v0186:
    v0176 = stack[0];
    v0175 = v0183;
    v0175 = (LispObject)(int32_t)((int32_t)v0176 - (int32_t)v0175 + TAG_FIXNUM);
    v0175 = ((intptr_t)(v0175) < 0 ? lisp_true : nil);
    if (v0175 == nil) goto v0187;
    v0175 = stack[-2];
    v0179 = v0175;
    goto v0188;

v0188:
    v0176 = stack[0];
    v0175 = v0179;
    v0175 = (LispObject)(int32_t)((int32_t)v0176 - (int32_t)v0175 + TAG_FIXNUM);
    v0175 = ((intptr_t)(v0175) < 0 ? lisp_true : nil);
    if (v0175 == nil) goto v0189;
    v0175 = qvalue(elt(env, 1)); // null!-space!-basis
    goto v0065;

v0189:
    v0176 = stack[-1];
    v0175 = stack[-2];
    v0178 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0177 = v0179;
    v0176 = stack[-1];
    v0175 = stack[-2];
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = v0179;
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = v0184;
    v0175 = Lmodular_times(nil, v0176, v0175);
    env = stack[-4];
    *(LispObject *)((char *)v0178 + (CELL-TAG_VECTOR) + ((int32_t)v0177/(16/CELL))) = v0175;
    v0175 = v0179;
    v0175 = (LispObject)((int32_t)(v0175) + 0x10);
    v0179 = v0175;
    goto v0188;

v0187:
    v0176 = v0183;
    v0175 = stack[-2];
    if (equal(v0176, v0175)) goto v0190;
    v0176 = stack[-1];
    v0175 = v0183;
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = stack[-2];
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0182 = v0175;
    v0176 = v0182;
    v0175 = (LispObject)1; // 0
    if (v0176 == v0175) goto v0190;
    v0176 = v0182;
    v0175 = v0184;
    v0175 = Lmodular_times(nil, v0176, v0175);
    env = stack[-4];
    v0182 = v0175;
    v0175 = stack[-2];
    v0181 = v0175;
    goto v0191;

v0191:
    v0176 = stack[0];
    v0175 = v0181;
    v0175 = (LispObject)(int32_t)((int32_t)v0176 - (int32_t)v0175 + TAG_FIXNUM);
    v0175 = ((intptr_t)(v0175) < 0 ? lisp_true : nil);
    if (!(v0175 == nil)) goto v0190;
    v0176 = stack[-1];
    v0175 = v0183;
    v0180 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0179 = v0181;
    v0176 = stack[-1];
    v0175 = v0183;
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = v0181;
    v0178 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0177 = v0182;
    v0176 = stack[-1];
    v0175 = stack[-2];
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = v0181;
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = Lmodular_times(nil, v0177, v0175);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0178) + int_of_fixnum(v0175);
        if (w >= current_modulus) w -= current_modulus;
        v0175 = fixnum_of_int(w);
    }
    *(LispObject *)((char *)v0180 + (CELL-TAG_VECTOR) + ((int32_t)v0179/(16/CELL))) = v0175;
    v0175 = v0181;
    v0175 = (LispObject)((int32_t)(v0175) + 0x10);
    v0181 = v0175;
    goto v0191;

v0190:
    v0175 = v0183;
    v0175 = (LispObject)((int32_t)(v0175) + 0x10);
    v0183 = v0175;
    goto v0186;

v0099:
    v0177 = stack[-1];
    v0176 = v0175;
    v0177 = *(LispObject *)((char *)v0177 + (CELL-TAG_VECTOR) + ((int32_t)v0176/(16/CELL)));
    v0176 = v0175;
    v0177 = *(LispObject *)((char *)v0177 + (CELL-TAG_VECTOR) + ((int32_t)v0176/(16/CELL)));
    v0176 = (LispObject)1; // 0
    v0176 = (v0177 == v0176 ? lisp_true : nil);
    v0176 = (v0176 == nil ? lisp_true : nil);
    goto v0005;

v0057:
    v0176 = qvalue(elt(env, 2)); // t
    goto v0005;
// error exit handlers
v0185:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; // null!-space!-basis
    popv(5);
    return nil;
}



// Code for checkargcount

static LispObject CC_checkargcount(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0017, v0058, v0068, v0083, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for checkargcount");
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
    v0068 = v0001;
    v0083 = v0000;
// end of prologue
    v0058 = v0083;
    v0017 = elt(env, 1); // naryargs
    v0017 = Lflagp(nil, v0058, v0017);
    env = stack[-3];
    if (v0017 == nil) goto v0073;
    v0017 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0017); }

v0073:
    v0017 = v0083;
    if (!symbolp(v0017)) v0017 = nil;
    else { v0017 = qfastgets(v0017);
           if (v0017 != nil) { v0017 = elt(v0017, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v0017 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v0017 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v0017 == SPID_NOPROP) v0017 = nil; }}
#endif
    v0087 = v0017;
    v0017 = v0087;
    if (v0017 == nil) goto v0039;
    v0058 = v0087;
    v0017 = v0068;
    if (equal(v0058, v0017)) goto v0063;
    stack[-2] = v0083;
    stack[-1] = v0087;
    stack[0] = v0068;
    v0017 = qvalue(elt(env, 3)); // curfun!*
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    fn = elt(env, 4); // instdof
    v0017 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0017);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    goto v0063;

v0063:
    v0017 = nil;
    { popv(4); return onevalue(v0017); }

v0039:
    v0017 = v0083;
    v0058 = v0068;
    {
        popv(4);
        fn = elt(env, 5); // hasarg
        return (*qfn2(fn))(qenv(fn), v0017, v0058);
    }
// error exit handlers
v0047:
    popv(4);
    return nil;
}



// Code for wulessp

static LispObject CC_wulessp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0104;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wulessp");
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
    v0104 = stack[-1];
    fn = elt(env, 2); // wuconstantp
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    if (v0104 == nil) goto v0012;
    v0104 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0104;
    goto v0034;

v0034:
    v0104 = stack[0];
    fn = elt(env, 2); // wuconstantp
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    if (v0104 == nil) goto v0092;
    v0104 = qvalue(elt(env, 1)); // nil
    goto v0035;

v0035:
    fn = elt(env, 3); // symbollessp
    v0104 = (*qfn2(fn))(qenv(fn), stack[-2], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    if (!(v0104 == nil)) { popv(4); return onevalue(v0104); }
    v0104 = stack[-1];
    fn = elt(env, 2); // wuconstantp
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    if (v0104 == nil) goto v0071;
    v0104 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0104;
    goto v0076;

v0076:
    v0104 = stack[0];
    fn = elt(env, 2); // wuconstantp
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    if (v0104 == nil) goto v0064;
    v0104 = qvalue(elt(env, 1)); // nil
    goto v0069;

v0069:
    if (equal(stack[-2], v0104)) goto v0021;
    v0104 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0104); }

v0021:
    v0104 = stack[-1];
    fn = elt(env, 2); // wuconstantp
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    if (v0104 == nil) goto v0081;
    v0104 = (LispObject)1; // 0
    stack[-1] = v0104;
    goto v0114;

v0114:
    v0104 = stack[0];
    fn = elt(env, 2); // wuconstantp
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    if (v0104 == nil) goto v0192;
    v0104 = (LispObject)1; // 0
    goto v0054;

v0054:
    {
        LispObject v0111 = stack[-1];
        popv(4);
        return Llessp(nil, v0111, v0104);
    }

v0192:
    v0104 = stack[0];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    goto v0054;

v0081:
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    stack[-1] = v0104;
    goto v0114;

v0064:
    v0104 = stack[0];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    goto v0069;

v0071:
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    stack[-2] = v0104;
    goto v0076;

v0092:
    v0104 = stack[0];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    goto v0035;

v0012:
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    stack[-2] = v0104;
    goto v0034;
// error exit handlers
v0110:
    popv(4);
    return nil;
}



// Code for mcharg1

static LispObject CC_mcharg1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0146, v0197, v0198;
    LispObject fn;
    LispObject v0011, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mcharg1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mcharg1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0011,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0011;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0146 = stack[-3];
    if (v0146 == nil) goto v0035;
    v0146 = qvalue(elt(env, 1)); // nil
    goto v0034;

v0034:
    if (v0146 == nil) goto v0004;
    v0146 = qvalue(elt(env, 1)); // nil
    popv(6);
    return ncons(v0146);

v0004:
    v0146 = stack[-3];
    v0146 = Llength(nil, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-4] = v0146;
    v0146 = stack[-2];
    v0146 = Llength(nil, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[0] = v0146;
    v0146 = stack[-1];
    if (!symbolp(v0146)) v0146 = nil;
    else { v0146 = qfastgets(v0146);
           if (v0146 != nil) { v0146 = elt(v0146, 35); // nary
#ifdef RECORD_GET
             if (v0146 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v0146 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v0146 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v0146 == SPID_NOPROP) v0146 = nil; else v0146 = lisp_true; }}
#endif
    if (v0146 == nil) goto v0094;
    v0197 = stack[-4];
    v0146 = (LispObject)33; // 2
    v0146 = (LispObject)greaterp2(v0197, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0146 = v0146 ? lisp_true : nil;
    env = stack[-5];
    goto v0049;

v0049:
    if (v0146 == nil) goto v0112;
    v0197 = stack[-4];
    v0146 = qvalue(elt(env, 2)); // matchlength!*
    v0146 = (LispObject)lesseq2(v0197, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0146 = v0146 ? lisp_true : nil;
    env = stack[-5];
    if (v0146 == nil) goto v0105;
    v0146 = stack[-1];
    if (!symbolp(v0146)) v0146 = nil;
    else { v0146 = qfastgets(v0146);
           if (v0146 != nil) { v0146 = elt(v0146, 43); // symmetric
#ifdef RECORD_GET
             if (v0146 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v0146 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v0146 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v0146 == SPID_NOPROP) v0146 = nil; else v0146 = lisp_true; }}
#endif
    if (v0146 == nil) goto v0105;
    v0198 = stack[-3];
    v0197 = stack[-2];
    v0146 = stack[-1];
    {
        popv(6);
        fn = elt(env, 3); // mchcomb
        return (*qfnn(fn))(qenv(fn), 3, v0198, v0197, v0146);
    }

v0105:
    v0197 = stack[0];
    v0146 = (LispObject)33; // 2
    if (v0197 == v0146) goto v0080;
    v0146 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0146); }

v0080:
    v0197 = stack[-1];
    v0146 = stack[-3];
    fn = elt(env, 4); // mkbin
    v0146 = (*qfn2(fn))(qenv(fn), v0197, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0146 = qcdr(v0146);
    stack[-3] = v0146;
    v0146 = (LispObject)33; // 2
    stack[-4] = v0146;
    goto v0112;

v0112:
    v0197 = stack[-4];
    v0146 = stack[0];
    if (equal(v0197, v0146)) goto v0113;
    v0146 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0146); }

v0113:
    v0146 = stack[-1];
    if (!symbolp(v0146)) v0146 = nil;
    else { v0146 = qfastgets(v0146);
           if (v0146 != nil) { v0146 = elt(v0146, 43); // symmetric
#ifdef RECORD_GET
             if (v0146 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v0146 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v0146 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v0146 == SPID_NOPROP) v0146 = nil; else v0146 = lisp_true; }}
#endif
    if (v0146 == nil) goto v0078;
    v0198 = stack[-3];
    v0197 = stack[-2];
    v0146 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); // mchsarg
        return (*qfnn(fn))(qenv(fn), 3, v0198, v0197, v0146);
    }

v0078:
    v0146 = stack[-2];
    fn = elt(env, 6); // mtp
    v0146 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    if (v0146 == nil) goto v0200;
    v0197 = stack[-2];
    v0146 = stack[-3];
    fn = elt(env, 7); // pair
    v0146 = (*qfn2(fn))(qenv(fn), v0197, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    popv(6);
    return ncons(v0146);

v0200:
    stack[0] = stack[-3];
    v0146 = qvalue(elt(env, 1)); // nil
    v0197 = ncons(v0146);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0146 = stack[-1];
    {
        LispObject v0186 = stack[0];
        LispObject v0201 = stack[-2];
        popv(6);
        fn = elt(env, 8); // mcharg2
        return (*qfnn(fn))(qenv(fn), 4, v0186, v0201, v0197, v0146);
    }

v0094:
    v0146 = qvalue(elt(env, 1)); // nil
    goto v0049;

v0035:
    v0146 = stack[-2];
    v0146 = (v0146 == nil ? lisp_true : nil);
    goto v0034;
// error exit handlers
v0199:
    popv(6);
    return nil;
}



// Code for mri_type

static LispObject CC_mri_type(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0012;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_type");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0012 = v0000;
// end of prologue
    v0003 = v0012;
    v0003 = qcdr(v0003);
    v0003 = qcdr(v0003);
    v0003 = qcdr(v0003);
    if (v0003 == nil) goto v0013;
    v0003 = v0012;
    v0003 = qcdr(v0003);
    v0003 = qcdr(v0003);
    v0003 = qcdr(v0003);
    v0003 = qcar(v0003);
    return onevalue(v0003);

v0013:
    v0003 = qvalue(elt(env, 1)); // nil
    return onevalue(v0003);
}



// Code for qqe_prepat

static LispObject CC_qqe_prepat(LispObject env,
                         LispObject v0000)
{
    LispObject v0037;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_prepat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0037 = v0000;
// end of prologue
    return onevalue(v0037);
}



// Code for powers2

static LispObject CC_powers2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0064, v0047, v0051;
    LispObject fn;
    LispObject v0011, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "powers2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0011,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0073:
    v0064 = stack[-2];
    if (!consp(v0064)) goto v0009;
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = (consp(v0064) ? nil : lisp_true);
    goto v0036;

v0036:
    if (v0064 == nil) goto v0027;
    v0064 = stack[-2];
    if (v0064 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0047 = stack[0];
    v0064 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); // powers4
        return (*qfn2(fn))(qenv(fn), v0047, v0064);
    }

v0027:
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = qcdr(v0064);
    stack[-3] = v0064;
    v0064 = stack[-2];
    v0051 = qcdr(v0064);
    v0047 = stack[-1];
    v0064 = stack[0];
    v0064 = CC_powers2(env, 3, v0051, v0047, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    stack[-1] = v0064;
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0047 = qcar(v0064);
    v0064 = stack[0];
    v0064 = cons(v0047, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    stack[0] = v0064;
    v0064 = stack[-3];
    stack[-2] = v0064;
    goto v0073;

v0009:
    v0064 = qvalue(elt(env, 1)); // t
    goto v0036;
// error exit handlers
v0021:
    popv(5);
    return nil;
}



// Code for find

static LispObject CC_find(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0069, v0043, v0067, v0042;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0043 = v0001;
    v0067 = v0000;
// end of prologue

v0034:
    v0042 = v0043;
    v0069 = nil;
    if (v0042 == v0069) goto v0073;
    v0069 = v0043;
    v0069 = qcar(v0069);
    v0067 = Lmember(nil, v0069, v0067);
    v0069 = v0043;
    v0069 = qcdr(v0069);
    v0043 = v0069;
    goto v0034;

v0073:
    v0069 = v0067;
    if (v0069 == nil) goto v0007;
    v0069 = v0067;
    v0069 = qcdr(v0069);
    return onevalue(v0069);

v0007:
    v0069 = elt(env, 1); // (stop)
    return onevalue(v0069);
}



// Code for subscriptedvarp

static LispObject CC_subscriptedvarp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0024;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subscriptedvarp");
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
    v0024 = qvalue(elt(env, 1)); // nil
    v0066 = stack[0];
    fn = elt(env, 3); // symtabget
    v0066 = (*qfn2(fn))(qenv(fn), v0024, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0024 = Llength(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0066 = (LispObject)33; // 2
    v0066 = (LispObject)greaterp2(v0024, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    v0066 = v0066 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0066 == nil)) { popv(2); return onevalue(v0066); }
    v0066 = stack[0];
    v0024 = elt(env, 2); // subscripted
        popv(2);
        return Lflagp(nil, v0066, v0024);
// error exit handlers
v0092:
    popv(2);
    return nil;
}



// Code for exptchk

static LispObject CC_exptchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0087, v0046, v0018;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptchk");
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
    v0087 = stack[0];
    if (!consp(v0087)) goto v0065;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    v0087 = (consp(v0087) ? nil : lisp_true);
    goto v0073;

v0073:
    if (v0087 == nil) goto v0031;
    v0046 = stack[0];
    v0087 = (LispObject)17; // 1
    popv(3);
    return cons(v0046, v0087);

v0031:
    v0087 = stack[0];
    fn = elt(env, 3); // comm_kernels
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-2];
    stack[-1] = v0087;
    v0087 = stack[-1];
    v0046 = Llength(nil, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-2];
    v0087 = (LispObject)33; // 2
    v0087 = (LispObject)lessp2(v0046, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    v0087 = v0087 ? lisp_true : nil;
    env = stack[-2];
    if (v0087 == nil) goto v0071;
    v0046 = stack[0];
    v0087 = (LispObject)17; // 1
    popv(3);
    return cons(v0046, v0087);

v0071:
    v0018 = stack[0];
    v0046 = qvalue(elt(env, 2)); // nil
    v0087 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); // exptchk0
        return (*qfnn(fn))(qenv(fn), 3, v0018, v0046, v0087);
    }

v0065:
    v0087 = qvalue(elt(env, 1)); // t
    goto v0073;
// error exit handlers
v0051:
    popv(3);
    return nil;
}



// Code for diplength

static LispObject CC_diplength(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0060, v0076;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diplength");
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
    goto v0040;

v0040:
    v0060 = stack[0];
    if (v0060 == nil) goto v0073;
    v0076 = (LispObject)17; // 1
    v0060 = stack[-1];
    v0060 = cons(v0076, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    stack[-1] = v0060;
    v0060 = stack[0];
    v0060 = qcdr(v0060);
    v0060 = qcdr(v0060);
    stack[0] = v0060;
    goto v0040;

v0073:
    v0060 = (LispObject)1; // 0
    v0076 = v0060;
    goto v0065;

v0065:
    v0060 = stack[-1];
    if (v0060 == nil) { popv(3); return onevalue(v0076); }
    v0060 = stack[-1];
    v0060 = qcar(v0060);
    v0060 = plus2(v0060, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    v0076 = v0060;
    v0060 = stack[-1];
    v0060 = qcdr(v0060);
    stack[-1] = v0060;
    goto v0065;
// error exit handlers
v0067:
    popv(3);
    return nil;
}



// Code for freeindexchk

static LispObject CC_freeindexchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeindexchk");
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
    v0012 = v0000;
// end of prologue
    v0003 = v0012;
    if (v0003 == nil) goto v0008;
    v0003 = qvalue(elt(env, 1)); // indxl!*
    if (v0003 == nil) goto v0008;
    v0003 = v0012;
    fn = elt(env, 4); // indxchk
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    if (v0003 == nil) goto v0008;
    v0003 = elt(env, 2); // form!-with!-free!-indices
    { popv(1); return onevalue(v0003); }

v0008:
    v0003 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0003); }
// error exit handlers
v0004:
    popv(1);
    return nil;
}



// Code for boundindp

static LispObject CC_boundindp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0092, v0093, v0062, v0063;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for boundindp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0063 = v0001;
    v0062 = v0000;
// end of prologue

v0006:
    v0092 = v0062;
    if (v0092 == nil) goto v0065;
    v0092 = v0062;
    v0093 = qcar(v0092);
    v0092 = v0063;
    v0092 = Lmember(nil, v0093, v0092);
    if (v0092 == nil) goto v0066;
    v0092 = v0062;
    v0092 = qcdr(v0092);
    v0062 = v0092;
    goto v0006;

v0066:
    v0092 = qvalue(elt(env, 2)); // nil
    return onevalue(v0092);

v0065:
    v0092 = qvalue(elt(env, 1)); // t
    return onevalue(v0092);
}



// Code for make!-set

static LispObject CC_makeKset(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0070, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-set");
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
    v0030 = v0070;
    v0070 = elt(env, 1); // set!-ordp
    fn = elt(env, 2); // sort
    v0070 = (*qfn2(fn))(qenv(fn), v0030, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // makelist
        return (*qfn1(fn))(qenv(fn), v0070);
    }
// error exit handlers
v0036:
    popv(1);
    return nil;
}



// Code for chundexp

static LispObject CC_chundexp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0056, v0033;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chundexp");
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
    v0056 = stack[-1];
    v0056 = Lexplodec(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-1] = v0056;
    v0056 = stack[-1];
    stack[-2] = v0056;
    v0033 = stack[-1];
    v0056 = elt(env, 1); // !_
    if (!consp(v0033)) goto v0050;
    v0033 = qcar(v0033);
    if (!(v0033 == v0056)) goto v0050;
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    goto v0008;

v0008:
    if (v0056 == nil) goto v0006;
    v0033 = elt(env, 3); // !\ (backslash)
    v0056 = stack[-1];
    v0056 = cons(v0033, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-1] = v0056;
    goto v0006;

v0006:
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    if (v0056 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    v0033 = qcar(v0056);
    v0056 = elt(env, 1); // !_
    if (!(v0033 == v0056)) goto v0043;
    stack[0] = stack[-2];
    v0033 = elt(env, 3); // !\ (backslash)
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    v0056 = cons(v0033, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0056 = Lrplacd(nil, stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    stack[-2] = v0056;
    goto v0043;

v0043:
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    stack[-2] = v0056;
    goto v0006;

v0050:
    v0056 = qvalue(elt(env, 2)); // nil
    goto v0008;
// error exit handlers
v0097:
    popv(4);
    return nil;
}



// Code for physopp!*

static LispObject CC_physoppH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0099, v0020;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopp*");
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
    v0099 = stack[0];
    fn = elt(env, 6); // physopp
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    if (!(v0099 == nil)) { popv(2); return onevalue(v0099); }
    v0099 = stack[0];
    if (!consp(v0099)) goto v0051;
    v0099 = stack[0];
    v0020 = qcar(v0099);
    v0099 = elt(env, 1); // physopfn
    v0099 = Lflagp(nil, v0020, v0099);
    env = stack[-1];
    if (v0099 == nil) goto v0048;
    v0099 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0099); }

v0048:
    v0099 = stack[0];
    v0020 = qcar(v0099);
    v0099 = elt(env, 3); // physoparith
    v0099 = Lflagp(nil, v0020, v0099);
    env = stack[-1];
    if (v0099 == nil) goto v0067;
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    fn = elt(env, 7); // hasonephysop
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    goto v0092;

v0092:
    if (!(v0099 == nil)) { popv(2); return onevalue(v0099); }
    v0099 = stack[0];
    v0020 = qcar(v0099);
    v0099 = elt(env, 5); // physopmapping
    v0099 = Lflagp(nil, v0020, v0099);
    env = stack[-1];
    if (v0099 == nil) goto v0018;
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    {
        popv(2);
        fn = elt(env, 7); // hasonephysop
        return (*qfn1(fn))(qenv(fn), v0099);
    }

v0018:
    v0099 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0099); }

v0067:
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0092;

v0051:
    v0099 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0099); }
// error exit handlers
v0019:
    popv(2);
    return nil;
}



// Code for getel

static LispObject CC_getel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0072, v0044, v0045;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getel");
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
    v0072 = stack[-1];
    v0044 = qcar(v0072);
    v0072 = elt(env, 1); // dimension
    v0072 = get(v0044, v0072);
    env = stack[-3];
    stack[-2] = v0072;
    v0072 = stack[-2];
    stack[0] = Llength(nil, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-3];
    v0072 = stack[-1];
    v0072 = qcdr(v0072);
    v0072 = Llength(nil, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-3];
    if (equal(stack[0], v0072)) goto v0075;
    v0045 = elt(env, 2); // rlisp
    v0044 = (LispObject)337; // 21
    v0072 = elt(env, 3); // "Incorrect array reference"
    {
        popv(4);
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0045, v0044, v0072);
    }

v0075:
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    if (!symbolp(v0072)) v0072 = nil;
    else { v0072 = qfastgets(v0072);
           if (v0072 != nil) { v0072 = elt(v0072, 4); // avalue
#ifdef RECORD_GET
             if (v0072 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0072 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0072 == SPID_NOPROP) v0072 = nil; }}
#endif
    v0072 = qcdr(v0072);
    v0045 = qcar(v0072);
    v0072 = stack[-1];
    v0044 = qcdr(v0072);
    v0072 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); // getel1
        return (*qfnn(fn))(qenv(fn), 3, v0045, v0044, v0072);
    }
// error exit handlers
v0058:
    popv(4);
    return nil;
}



// Code for mo!=lexcomp

static LispObject CC_moMlexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0071, v0072, v0044, v0045;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=lexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0072 = v0001;
    v0044 = v0000;
// end of prologue

v0006:
    v0071 = v0044;
    if (v0071 == nil) goto v0065;
    v0071 = v0072;
    if (v0071 == nil) goto v0004;
    v0071 = v0044;
    v0045 = qcar(v0071);
    v0071 = v0072;
    v0071 = qcar(v0071);
    if (equal(v0045, v0071)) goto v0041;
    v0071 = v0044;
    v0071 = qcar(v0071);
    v0072 = qcar(v0072);
    if (((int32_t)(v0071)) > ((int32_t)(v0072))) goto v0027;
    v0071 = (LispObject)-15; // -1
    return onevalue(v0071);

v0027:
    v0071 = (LispObject)17; // 1
    return onevalue(v0071);

v0041:
    v0071 = v0044;
    v0071 = qcdr(v0071);
    v0044 = v0071;
    v0071 = v0072;
    v0071 = qcdr(v0071);
    v0072 = v0071;
    goto v0006;

v0004:
    v0071 = elt(env, 1); // (0)
    v0072 = v0071;
    goto v0006;

v0065:
    v0071 = v0072;
    if (v0071 == nil) goto v0036;
    v0071 = elt(env, 1); // (0)
    v0044 = v0071;
    goto v0006;

v0036:
    v0071 = (LispObject)1; // 0
    return onevalue(v0071);
}



// Code for gperm

static LispObject CC_gperm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0019;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm");
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
    stack[0] = v0000;
// end of prologue
    stack[-1] = nil;
    goto v0036;

v0036:
    v0019 = stack[0];
    v0021 = (LispObject)1; // 0
    v0021 = (LispObject)greaterp2(v0019, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    v0021 = v0021 ? lisp_true : nil;
    env = stack[-4];
    if (v0021 == nil) goto v0040;
    v0019 = stack[0];
    v0021 = stack[-1];
    v0021 = cons(v0019, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    stack[-1] = v0021;
    v0021 = stack[0];
    v0021 = sub1(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    stack[0] = v0021;
    goto v0036;

v0040:
    v0021 = stack[-1];
    fn = elt(env, 2); // gperm0
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    stack[-3] = v0021;
    v0021 = stack[-3];
    if (v0021 == nil) goto v0074;
    v0021 = stack[-3];
    v0021 = qcar(v0021);
    fn = elt(env, 3); // pkp
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0021 = ncons(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    stack[-1] = v0021;
    stack[-2] = v0021;
    goto v0048;

v0048:
    v0021 = stack[-3];
    v0021 = qcdr(v0021);
    stack[-3] = v0021;
    v0021 = stack[-3];
    if (v0021 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0021 = stack[-3];
    v0021 = qcar(v0021);
    fn = elt(env, 3); // pkp
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0021 = ncons(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0021 = Lrplacd(nil, stack[0], v0021);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0021 = stack[-1];
    v0021 = qcdr(v0021);
    stack[-1] = v0021;
    goto v0048;

v0074:
    v0021 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0021); }
// error exit handlers
v0033:
    popv(5);
    return nil;
}



// Code for copy

static LispObject CC_copy(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0093, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for copy");
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
    goto v0006;

v0006:
    v0093 = stack[0];
    if (!consp(v0093)) goto v0030;
    v0093 = stack[0];
    v0093 = qcar(v0093);
    v0062 = CC_copy(env, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0093 = stack[-1];
    v0093 = cons(v0062, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    stack[-1] = v0093;
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    stack[0] = v0093;
    goto v0006;

v0030:
    v0062 = stack[-1];
    v0093 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0062, v0093);
    }
// error exit handlers
v0049:
    popv(3);
    return nil;
}



// Code for general!-modular!-quotient

static LispObject CC_generalKmodularKquotient(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0030, v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-quotient");
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
    v0030 = v0001;
    v0036 = v0000;
// end of prologue
    stack[0] = v0036;
    fn = elt(env, 1); // general!-modular!-reciprocal
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    {
        LispObject v0010 = stack[0];
        popv(2);
        fn = elt(env, 2); // general!-modular!-times
        return (*qfn2(fn))(qenv(fn), v0010, v0030);
    }
// error exit handlers
v0008:
    popv(2);
    return nil;
}



// Code for times!-term!-mod!-p

static LispObject CC_timesKtermKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0211, v0212, v0213;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for times-term-mod-p");
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
    goto v0065;

v0065:
    v0211 = stack[-1];
    if (v0211 == nil) goto v0030;
    v0211 = stack[-1];
    if (!consp(v0211)) goto v0004;
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    v0211 = (consp(v0211) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0211 == nil) goto v0083;
    v0211 = stack[-2];
    v0212 = qcdr(v0211);
    v0211 = stack[-1];
    fn = elt(env, 3); // multiply!-by!-constant!-mod!-p
    v0212 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0211 = qvalue(elt(env, 1)); // nil
    v0213 = v0212;
    if (v0213 == nil) goto v0061;
    v0213 = stack[-2];
    v0213 = qcar(v0213);
    v0211 = acons(v0213, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    goto v0061;

v0061:
    v0212 = v0211;
    goto v0215;

v0215:
    v0211 = stack[-3];
    if (v0211 == nil) { popv(5); return onevalue(v0212); }
    v0211 = stack[-3];
    v0211 = qcdr(v0211);
    stack[0] = v0211;
    v0211 = stack[-3];
    v0211 = qcar(v0211);
    v0211 = qcdr(v0211);
    if (v0211 == nil) goto v0155;
    v0211 = stack[-3];
    v0211 = Lrplacd(nil, v0211, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0211 = stack[-3];
    v0212 = v0211;
    goto v0155;

v0155:
    v0211 = stack[0];
    stack[-3] = v0211;
    goto v0215;

v0083:
    v0211 = stack[-2];
    v0211 = qcar(v0211);
    v0212 = qcar(v0211);
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    v0211 = qcar(v0211);
    v0211 = qcar(v0211);
    if (equal(v0212, v0211)) goto v0097;
    v0211 = stack[-2];
    v0211 = qcar(v0211);
    v0212 = qcar(v0211);
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    v0211 = qcar(v0211);
    v0211 = qcar(v0211);
    fn = elt(env, 4); // ordop
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    if (v0211 == nil) goto v0201;
    v0211 = stack[-2];
    v0212 = qcdr(v0211);
    v0211 = stack[-1];
    fn = elt(env, 5); // times!-mod!-p
    v0212 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0211 = qvalue(elt(env, 1)); // nil
    v0213 = v0212;
    if (v0213 == nil) goto v0216;
    v0213 = stack[-2];
    v0213 = qcar(v0213);
    v0211 = acons(v0213, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    goto v0216;

v0216:
    v0212 = v0211;
    goto v0215;

v0201:
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    stack[0] = qcar(v0211);
    v0212 = stack[-2];
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    v0211 = qcdr(v0211);
    v0212 = CC_timesKtermKmodKp(env, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0211 = stack[-3];
    v0211 = acons(stack[0], v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[-3] = v0211;
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    goto v0065;

v0097:
    v0211 = stack[-2];
    v0211 = qcar(v0211);
    v0213 = qcar(v0211);
    v0211 = stack[-2];
    v0211 = qcar(v0211);
    v0212 = qcdr(v0211);
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    v0211 = qcar(v0211);
    v0211 = qcdr(v0211);
    v0211 = (LispObject)(int32_t)((int32_t)v0212 + (int32_t)v0211 - TAG_FIXNUM);
    fn = elt(env, 6); // mksp
    stack[0] = (*qfn2(fn))(qenv(fn), v0213, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0211 = stack[-2];
    v0212 = qcdr(v0211);
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    v0211 = qcdr(v0211);
    fn = elt(env, 5); // times!-mod!-p
    v0212 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0211 = stack[-3];
    v0211 = acons(stack[0], v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[-3] = v0211;
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    goto v0065;

v0004:
    v0211 = qvalue(elt(env, 2)); // t
    goto v0012;

v0030:
    v0211 = qvalue(elt(env, 1)); // nil
    v0212 = v0211;
    goto v0215;
// error exit handlers
v0214:
    popv(5);
    return nil;
}



// Code for cancel

static LispObject CC_cancel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0114, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cancel");
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
    v0114 = qvalue(elt(env, 1)); // !*mcd
    if (!(v0114 == nil)) goto v0041;
    v0114 = stack[0];
    v0054 = qcdr(v0114);
    v0114 = (LispObject)17; // 1
    if (v0054 == v0114) goto v0041;
    v0114 = stack[0];
    v0054 = qcar(v0114);
    v0114 = (LispObject)17; // 1
    stack[-1] = cons(v0054, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    v0114 = stack[0];
    v0054 = qcdr(v0114);
    v0114 = (LispObject)17; // 1
    v0114 = cons(v0054, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    fn = elt(env, 2); // mk!*sq
    v0054 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    v0114 = (LispObject)-15; // -1
    v0114 = list2(v0054, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    fn = elt(env, 3); // simpexpt
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    {
        LispObject v0174 = stack[-1];
        popv(3);
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(qenv(fn), v0174, v0114);
    }

v0041:
    v0114 = stack[0];
    v0054 = qcar(v0114);
    v0114 = (LispObject)17; // 1
    stack[-1] = cons(v0054, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    v0054 = (LispObject)17; // 1
    v0114 = stack[0];
    v0114 = qcdr(v0114);
    v0114 = cons(v0054, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    {
        LispObject v0105 = stack[-1];
        popv(3);
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(qenv(fn), v0105, v0114);
    }
// error exit handlers
v0033:
    popv(3);
    return nil;
}



// Code for raddf

static LispObject CC_raddf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0222, v0199;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for raddf");
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
    goto v0040;

v0040:
    v0222 = stack[-2];
    if (v0222 == nil) goto v0036;
    v0222 = stack[-1];
    if (v0222 == nil) goto v0041;
    v0222 = stack[-2];
    if (!consp(v0222)) goto v0063;
    v0222 = stack[-2];
    v0222 = qcar(v0222);
    v0222 = (consp(v0222) ? nil : lisp_true);
    goto v0062;

v0062:
    if (v0222 == nil) goto v0092;
    stack[0] = stack[-3];
    v0199 = stack[-2];
    v0222 = stack[-1];
    fn = elt(env, 2); // addd
    v0222 = (*qfn2(fn))(qenv(fn), v0199, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    {
        LispObject v0161 = stack[0];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0161, v0222);
    }

v0092:
    v0222 = stack[-1];
    if (!consp(v0222)) goto v0083;
    v0222 = stack[-1];
    v0222 = qcar(v0222);
    v0222 = (consp(v0222) ? nil : lisp_true);
    goto v0068;

v0068:
    if (v0222 == nil) goto v0224;
    stack[0] = stack[-3];
    v0199 = stack[-1];
    v0222 = stack[-2];
    fn = elt(env, 2); // addd
    v0222 = (*qfn2(fn))(qenv(fn), v0199, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    {
        LispObject v0162 = stack[0];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0162, v0222);
    }

v0224:
    v0222 = stack[-2];
    v0222 = qcar(v0222);
    v0199 = qcar(v0222);
    v0222 = stack[-1];
    v0222 = qcar(v0222);
    v0222 = qcar(v0222);
    if (equal(v0199, v0222)) goto v0103;
    v0222 = stack[-2];
    v0222 = qcar(v0222);
    v0199 = qcar(v0222);
    v0222 = stack[-1];
    v0222 = qcar(v0222);
    v0222 = qcar(v0222);
    fn = elt(env, 4); // ordpp
    v0222 = (*qfn2(fn))(qenv(fn), v0199, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    if (v0222 == nil) goto v0164;
    v0222 = stack[-2];
    v0199 = qcar(v0222);
    v0222 = stack[-3];
    v0222 = cons(v0199, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-3] = v0222;
    v0222 = stack[-2];
    v0222 = qcdr(v0222);
    stack[-2] = v0222;
    goto v0040;

v0164:
    v0222 = stack[-1];
    v0199 = qcar(v0222);
    v0222 = stack[-3];
    v0222 = cons(v0199, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-3] = v0222;
    v0222 = stack[-1];
    v0222 = qcdr(v0222);
    stack[-1] = v0222;
    goto v0040;

v0103:
    v0222 = stack[-2];
    v0222 = qcar(v0222);
    stack[0] = qcar(v0222);
    v0222 = stack[-2];
    v0222 = qcar(v0222);
    v0199 = qcdr(v0222);
    v0222 = stack[-1];
    v0222 = qcar(v0222);
    v0222 = qcdr(v0222);
    v0199 = CC_raddf(env, v0199, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    v0222 = stack[-3];
    v0222 = acons(stack[0], v0199, v0222);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-3] = v0222;
    v0222 = stack[-2];
    v0222 = qcdr(v0222);
    stack[-2] = v0222;
    v0222 = stack[-1];
    v0222 = qcdr(v0222);
    stack[-1] = v0222;
    goto v0040;

v0083:
    v0222 = qvalue(elt(env, 1)); // t
    goto v0068;

v0063:
    v0222 = qvalue(elt(env, 1)); // t
    goto v0062;

v0041:
    v0199 = stack[-3];
    v0222 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0199, v0222);
    }

v0036:
    v0199 = stack[-3];
    v0222 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0199, v0222);
    }
// error exit handlers
v0223:
    popv(5);
    return nil;
}



// Code for mri_simplfloor

static LispObject CC_mri_simplfloor(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_simplfloor");
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
    v0036 = stack[0];
    fn = elt(env, 1); // mri_floorkernelp
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    if (v0036 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0036 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // mri_simplfloor1
        return (*qfn1(fn))(qenv(fn), v0036);
    }
// error exit handlers
v0008:
    popv(2);
    return nil;
}



// Code for rl_simpat

static LispObject CC_rl_simpat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simpat");
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
    v0070 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_simpat!*
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    {
        LispObject v0009 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0009, v0070);
    }
// error exit handlers
v0036:
    popv(2);
    return nil;
}



// Code for kernord

static LispObject CC_kernord(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0007, v0041;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernord");
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
    v0007 = v0001;
    stack[0] = v0000;
// end of prologue
    v0041 = stack[0];
    fn = elt(env, 1); // kernord!-split
    v0007 = (*qfn2(fn))(qenv(fn), v0041, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    stack[0] = v0007;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 2); // kernord!-sort
    stack[-1] = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    fn = elt(env, 2); // kernord!-sort
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    {
        LispObject v0050 = stack[-1];
        popv(3);
        return Lappend(nil, v0050, v0007);
    }
// error exit handlers
v0039:
    popv(3);
    return nil;
}



// Code for quotfd

static LispObject CC_quotfd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0108, v0016, v0017, v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0017 = v0001;
    v0058 = v0000;
// end of prologue
    v0016 = v0058;
    v0108 = v0017;
    if (equal(v0016, v0108)) goto v0006;
    v0108 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0108)) v0108 = nil;
    else { v0108 = qfastgets(v0108);
           if (v0108 != nil) { v0108 = elt(v0108, 3); // field
#ifdef RECORD_GET
             if (v0108 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0108 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0108 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0108 == SPID_NOPROP) v0108 = nil; else v0108 = lisp_true; }}
#endif
    if (v0108 == nil) goto v0010;
    v0108 = v0058;
    v0016 = v0017;
    {
        fn = elt(env, 3); // divd
        return (*qfn2(fn))(qenv(fn), v0108, v0016);
    }

v0010:
    v0108 = v0058;
    if (!consp(v0108)) goto v0025;
    v0108 = v0058;
    v0108 = qcar(v0108);
    v0108 = (consp(v0108) ? nil : lisp_true);
    goto v0024;

v0024:
    if (v0108 == nil) goto v0095;
    v0108 = v0058;
    v0016 = v0017;
    {
        fn = elt(env, 4); // quotdd
        return (*qfn2(fn))(qenv(fn), v0108, v0016);
    }

v0095:
    v0108 = v0058;
    v0016 = v0017;
    {
        fn = elt(env, 5); // quotk
        return (*qfn2(fn))(qenv(fn), v0108, v0016);
    }

v0025:
    v0108 = qvalue(elt(env, 2)); // t
    goto v0024;

v0006:
    v0108 = (LispObject)17; // 1
    return onevalue(v0108);
}



// Code for downwght

static LispObject CC_downwght(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0008, v0010;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for downwght");
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
    v0008 = stack[-1];
    fn = elt(env, 1); // delhisto
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0010 = stack[-1];
    v0008 = stack[0];
    fn = elt(env, 2); // downwght1
    v0008 = (*qfn2(fn))(qenv(fn), v0010, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0008 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); // inshisto
        return (*qfn1(fn))(qenv(fn), v0008);
    }
// error exit handlers
v0012:
    popv(3);
    return nil;
}



// Code for freexp

static LispObject CC_freexp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freexp");
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

v0098:
    v0004 = stack[0];
    if (!consp(v0004)) goto v0013;
    v0004 = stack[0];
    v0004 = qcar(v0004);
    v0004 = CC_freexp(env, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-1];
    if (!(v0004 == nil)) { popv(2); return onevalue(v0004); }
    v0004 = stack[0];
    v0004 = qcdr(v0004);
    stack[0] = v0004;
    goto v0098;

v0013:
    v0004 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); // pm!:free
        return (*qfn1(fn))(qenv(fn), v0004);
    }
// error exit handlers
v0057:
    popv(2);
    return nil;
}



// Code for prepd

static LispObject CC_prepd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0174, v0105;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepd");
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
    v0174 = stack[0];
    if (!consp(v0174)) goto v0030;
    v0174 = stack[0];
    v0174 = qcar(v0174);
    if (!symbolp(v0174)) v0105 = nil;
    else { v0105 = qfastgets(v0174);
           if (v0105 != nil) { v0105 = elt(v0105, 30); // minusp
#ifdef RECORD_GET
             if (v0105 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0105 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0105 == SPID_NOPROP) v0105 = nil; }}
#endif
    v0174 = stack[0];
    v0174 = Lapply1(nil, v0105, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    if (v0174 == nil) goto v0099;
    v0174 = stack[0];
    fn = elt(env, 3); // !:minus
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    fn = elt(env, 4); // prepd1
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    v0105 = v0174;
    v0174 = v0105;
    if (v0174 == nil) goto v0022;
    v0174 = elt(env, 1); // minus
    popv(3);
    return list2(v0174, v0105);

v0022:
    v0174 = (LispObject)1; // 0
    { popv(3); return onevalue(v0174); }

v0099:
    v0174 = stack[0];
    v0105 = qcar(v0174);
    v0174 = elt(env, 2); // prepfn
    v0105 = get(v0105, v0174);
    v0174 = stack[0];
        popv(3);
        return Lapply1(nil, v0105, v0174);

v0030:
    v0105 = stack[0];
    v0174 = (LispObject)1; // 0
    v0174 = (LispObject)lessp2(v0105, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-2];
    if (v0174 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); // minus
    v0174 = stack[0];
    v0174 = negate(v0174);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    {
        LispObject v0081 = stack[-1];
        popv(3);
        return list2(v0081, v0174);
    }
// error exit handlers
v0014:
    popv(3);
    return nil;
}



// Code for quotematrix

static LispObject CC_quotematrix(LispObject env,
                         LispObject v0000)
{
    LispObject v0037;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotematrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0037 = v0000;
// end of prologue
    v0037 = elt(env, 1); // matrix
    return onevalue(v0037);
}



// Code for deg!*farg

static LispObject CC_degHfarg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deg*farg");
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
    v0060 = v0000;
// end of prologue
    v0061 = v0060;
    v0061 = qcdr(v0061);
    if (v0061 == nil) goto v0013;
    stack[-1] = nil;
    v0061 = v0060;
    stack[0] = v0061;
    goto v0012;

v0012:
    v0061 = stack[0];
    if (v0061 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0061 = stack[0];
    v0061 = qcar(v0061);
    fn = elt(env, 2); // deg!*form
    v0060 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    v0061 = stack[-1];
    fn = elt(env, 3); // addf
    v0061 = (*qfn2(fn))(qenv(fn), v0060, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    stack[-1] = v0061;
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    stack[0] = v0061;
    goto v0012;

v0013:
    v0061 = v0060;
    v0061 = qcar(v0061);
    {
        popv(3);
        fn = elt(env, 2); // deg!*form
        return (*qfn1(fn))(qenv(fn), v0061);
    }
// error exit handlers
v0043:
    popv(3);
    return nil;
}



// Code for round!:mt

static LispObject CC_roundTmt(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0171, v0226;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for round:mt");
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
    v0226 = stack[-2];
    v0171 = elt(env, 1); // !:rd!:
    if (!consp(v0226)) goto v0039;
    v0226 = qcar(v0226);
    if (!(v0226 == v0171)) goto v0039;
    v0171 = stack[-2];
    v0171 = qcdr(v0171);
    v0171 = (consp(v0171) ? nil : lisp_true);
    v0171 = (v0171 == nil ? lisp_true : nil);
    goto v0030;

v0030:
    if (v0171 == nil) goto v0067;
    v0171 = stack[-1];
    v0171 = integerp(v0171);
    if (v0171 == nil) goto v0092;
    v0226 = stack[-1];
    v0171 = (LispObject)1; // 0
    v0171 = (LispObject)greaterp2(v0226, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    v0171 = v0171 ? lisp_true : nil;
    env = stack[-4];
    goto v0065;

v0065:
    if (v0171 == nil) goto v0086;
    v0171 = stack[-2];
    v0171 = qcdr(v0171);
    v0171 = qcar(v0171);
    v0171 = Labsval(nil, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    fn = elt(env, 3); // msd
    v0226 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    v0171 = stack[-1];
    v0171 = difference2(v0226, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    v0226 = sub1(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    stack[-1] = v0226;
    v0171 = (LispObject)1; // 0
    v0171 = (LispObject)lessp2(v0226, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    v0171 = v0171 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0171 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0226 = stack[-1];
    v0171 = (LispObject)1; // 0
    if (v0226 == v0171) goto v0019;
    stack[-3] = elt(env, 1); // !:rd!:
    v0171 = stack[-2];
    v0171 = qcdr(v0171);
    stack[0] = qcar(v0171);
    v0171 = stack[-1];
    v0171 = negate(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    fn = elt(env, 4); // ashift
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    v0171 = stack[-2];
    v0171 = qcdr(v0171);
    v0226 = qcdr(v0171);
    v0171 = stack[-1];
    v0171 = plus2(v0226, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    v0171 = list2star(stack[-3], stack[0], v0171);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); // round!:last
        return (*qfn1(fn))(qenv(fn), v0171);
    }

v0019:
    v0171 = stack[-2];
    {
        popv(5);
        fn = elt(env, 5); // round!:last
        return (*qfn1(fn))(qenv(fn), v0171);
    }

v0086:
    v0171 = elt(env, 0); // round!:mt
    {
        popv(5);
        fn = elt(env, 6); // bflerrmsg
        return (*qfn1(fn))(qenv(fn), v0171);
    }

v0092:
    v0171 = qvalue(elt(env, 2)); // nil
    goto v0065;

v0067:
    v0171 = qvalue(elt(env, 2)); // nil
    goto v0065;

v0039:
    v0171 = qvalue(elt(env, 2)); // nil
    goto v0030;
// error exit handlers
v0172:
    popv(5);
    return nil;
}



// Code for gizerop!:

static LispObject CC_gizeropT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0066, v0024;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gizerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0024 = v0000;
// end of prologue
    v0050 = v0024;
    v0050 = qcdr(v0050);
    v0066 = qcar(v0050);
    v0050 = (LispObject)1; // 0
    if (v0066 == v0050) goto v0008;
    v0050 = qvalue(elt(env, 1)); // nil
    return onevalue(v0050);

v0008:
    v0050 = v0024;
    v0050 = qcdr(v0050);
    v0066 = qcdr(v0050);
    v0050 = (LispObject)1; // 0
    v0050 = (v0066 == v0050 ? lisp_true : nil);
    return onevalue(v0050);
}



// Code for red!-char!-downcase

static LispObject CC_redKcharKdowncase(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005, v0057, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-char-downcase");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0057 = v0000;
// end of prologue
    v0005 = v0057;
    v0007 = qvalue(elt(env, 1)); // charassoc!*
    v0005 = Latsoc(nil, v0005, v0007);
    v0007 = v0005;
    v0005 = v0007;
    if (v0005 == nil) return onevalue(v0057);
    v0005 = v0007;
    v0005 = qcdr(v0005);
    return onevalue(v0005);
}



// Code for repeatsp

static LispObject CC_repeatsp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0038, v0039, v0050;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repeatsp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0039 = v0000;
// end of prologue

v0098:
    v0038 = v0039;
    if (v0038 == nil) goto v0013;
    v0038 = v0039;
    v0050 = qcar(v0038);
    v0038 = v0039;
    v0038 = qcdr(v0038);
    v0038 = Lmember(nil, v0050, v0038);
    if (!(v0038 == nil)) return onevalue(v0038);
    v0038 = v0039;
    v0038 = qcdr(v0038);
    v0039 = v0038;
    goto v0098;

v0013:
    v0038 = qvalue(elt(env, 1)); // nil
    return onevalue(v0038);
}



// Code for macrochk

static LispObject CC_macrochk(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0020, v0021, v0019, v0114;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for macrochk");
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
    if (!consp(v0020)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0020 = stack[-1];
    v0020 = qcar(v0020);
    fn = elt(env, 5); // expdrmacro
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    v0021 = v0020;
    if (v0020 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0019 = stack[0];
    v0020 = elt(env, 1); // symbolic
    if (v0019 == v0020) goto v0005;
    v0020 = stack[-1];
    v0020 = qcar(v0020);
    if (symbolp(v0020)) goto v0075;
    v0020 = qvalue(elt(env, 3)); // nil
    goto v0004;

v0004:
    if (v0020 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0020 = v0021;
    v0019 = qcar(v0020);
    v0020 = elt(env, 4); // macrofn
    v0114 = get(v0019, v0020);
    v0020 = v0021;
    v0019 = qcdr(v0020);
    v0020 = stack[-1];
    v0021 = qcdr(v0020);
    v0020 = stack[-1];
    v0020 = qcar(v0020);
        popv(3);
        return Lapply3(nil, 4, v0114, v0019, v0021, v0020);

v0075:
    v0020 = stack[-1];
    v0020 = qcar(v0020);
    if (!symbolp(v0020)) v0020 = nil;
    else { v0020 = qfastgets(v0020);
           if (v0020 != nil) { v0020 = elt(v0020, 59); // opfn
#ifdef RECORD_GET
             if (v0020 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0020 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0020 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0020 == SPID_NOPROP) v0020 = nil; else v0020 = lisp_true; }}
#endif
    goto v0004;

v0005:
    v0020 = qvalue(elt(env, 2)); // t
    goto v0004;
// error exit handlers
v0056:
    popv(3);
    return nil;
}



// Code for red_divtestbe

static LispObject CC_red_divtestbe(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0076, v0069;
    LispObject fn;
    LispObject v0011, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "red_divtestbe");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_divtestbe");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0011,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0040:
    v0076 = stack[-2];
    if (v0076 == nil) goto v0034;
    v0076 = stack[-2];
    v0076 = qcar(v0076);
    fn = elt(env, 2); // bas_dpecart
    v0069 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    v0076 = stack[0];
    v0076 = (LispObject)lesseq2(v0069, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0076 = v0076 ? lisp_true : nil;
    env = stack[-3];
    if (v0076 == nil) goto v0075;
    v0076 = stack[-2];
    v0076 = qcar(v0076);
    fn = elt(env, 3); // bas_dpoly
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    fn = elt(env, 4); // dp_lmon
    v0069 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    v0076 = stack[-1];
    fn = elt(env, 5); // mo_vdivides!?
    v0076 = (*qfn2(fn))(qenv(fn), v0069, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    if (v0076 == nil) goto v0075;
    v0076 = stack[-2];
    v0076 = qcar(v0076);
    { popv(4); return onevalue(v0076); }

v0075:
    v0076 = stack[-2];
    v0076 = qcdr(v0076);
    stack[-2] = v0076;
    goto v0040;

v0034:
    v0076 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0076); }
// error exit handlers
v0022:
    popv(4);
    return nil;
}



// Code for resimp1

static LispObject CC_resimp1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0024, v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resimp1");
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
    v0024 = stack[0];
    v0025 = qcar(v0024);
    v0024 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 4); // subf1
    stack[-1] = (*qfn2(fn))(qenv(fn), v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    v0024 = stack[0];
    v0025 = qcdr(v0024);
    v0024 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 4); // subf1
    v0024 = (*qfn2(fn))(qenv(fn), v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    fn = elt(env, 5); // quotsq
    v0024 = (*qfn2(fn))(qenv(fn), stack[-1], v0024);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    stack[0] = v0024;
    v0024 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 3)) = v0024; // !*sub2
    { LispObject res = stack[0]; popv(3); return onevalue(res); }
// error exit handlers
v0062:
    popv(3);
    return nil;
}



// Code for pappl_pv

static LispObject CC_pappl_pv(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0114, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl_pv");
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
    stack[-5] = v0114;
    v0114 = stack[-5];
    if (v0114 == nil) goto v0036;
    v0114 = stack[-5];
    v0114 = qcar(v0114);
    v0054 = v0114;
    stack[0] = qcar(v0054);
    v0054 = stack[-4];
    v0114 = qcdr(v0114);
    fn = elt(env, 2); // pappl0
    v0114 = (*qfn2(fn))(qenv(fn), v0054, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0114 = cons(stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-2] = v0114;
    stack[-3] = v0114;
    goto v0034;

v0034:
    v0114 = stack[-5];
    v0114 = qcdr(v0114);
    stack[-5] = v0114;
    v0114 = stack[-5];
    if (v0114 == nil) goto v0061;
    stack[-1] = stack[-2];
    v0114 = stack[-5];
    v0114 = qcar(v0114);
    v0054 = v0114;
    stack[0] = qcar(v0054);
    v0054 = stack[-4];
    v0114 = qcdr(v0114);
    fn = elt(env, 2); // pappl0
    v0114 = (*qfn2(fn))(qenv(fn), v0054, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0114 = cons(stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0114 = Lrplacd(nil, stack[-1], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    stack[-2] = v0114;
    goto v0034;

v0061:
    v0114 = stack[-3];
    goto v0065;

v0065:
    {
        popv(7);
        fn = elt(env, 3); // pv_sort
        return (*qfn1(fn))(qenv(fn), v0114);
    }

v0036:
    v0114 = qvalue(elt(env, 1)); // nil
    goto v0065;
// error exit handlers
v0097:
    popv(7);
    return nil;
}



// Code for !*i2ar

static LispObject CC_Hi2ar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035, v0070;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2ar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0035 = v0000;
// end of prologue
    v0070 = elt(env, 1); // !:ar!:
    return cons(v0070, v0035);
}



// Code for !*modular2f

static LispObject CC_Hmodular2f(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0227, v0103;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *modular2f");
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

v0034:
    v0103 = stack[0];
    v0227 = (LispObject)1; // 0
    if (v0103 == v0227) goto v0073;
    v0227 = qvalue(elt(env, 2)); // !*balanced_mod
    if (v0227 == nil) goto v0107;
    v0103 = stack[0];
    v0227 = stack[0];
    v0103 = plus2(v0103, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    v0227 = qvalue(elt(env, 3)); // current!-modulus
    v0227 = (LispObject)greaterp2(v0103, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-2];
    if (v0227 == nil) goto v0083;
    stack[-1] = elt(env, 4); // !:mod!:
    v0103 = stack[0];
    v0227 = qvalue(elt(env, 3)); // current!-modulus
    v0227 = difference2(v0103, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    {
        LispObject v0113 = stack[-1];
        popv(3);
        return cons(v0113, v0227);
    }

v0083:
    v0103 = stack[0];
    v0227 = stack[0];
    stack[-1] = plus2(v0103, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    v0227 = qvalue(elt(env, 3)); // current!-modulus
    v0227 = negate(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    v0227 = (LispObject)lesseq2(stack[-1], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-2];
    if (v0227 == nil) goto v0096;
    v0103 = stack[0];
    v0227 = qvalue(elt(env, 3)); // current!-modulus
    v0227 = plus2(v0103, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    stack[0] = v0227;
    goto v0034;

v0096:
    v0103 = elt(env, 4); // !:mod!:
    v0227 = stack[0];
    popv(3);
    return cons(v0103, v0227);

v0107:
    v0103 = elt(env, 4); // !:mod!:
    v0227 = stack[0];
    popv(3);
    return cons(v0103, v0227);

v0073:
    v0227 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0227); }
// error exit handlers
v0106:
    popv(3);
    return nil;
}



// Code for exptmod!:

static LispObject CC_exptmodT(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0036, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptmod:");
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
    v0036 = v0001;
    v0009 = v0000;
// end of prologue
    v0009 = qcdr(v0009);
    fn = elt(env, 1); // general!-modular!-expt
    v0036 = (*qfn2(fn))(qenv(fn), v0009, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(qenv(fn), v0036);
    }
// error exit handlers
v0008:
    popv(1);
    return nil;
}



// Code for lalr_insert_core

static LispObject CC_lalr_insert_core(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0080, v0089, v0102;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_insert_core");
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
    goto v0040;

v0040:
    v0080 = stack[0];
    if (v0080 == nil) goto v0036;
    v0089 = stack[-1];
    v0080 = stack[0];
    v0080 = qcar(v0080);
    fn = elt(env, 2); // lalr_same_core
    v0080 = (*qfn2(fn))(qenv(fn), v0089, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    if (v0080 == nil) goto v0033;
    v0080 = stack[-1];
    v0102 = qcdr(v0080);
    v0080 = stack[0];
    v0080 = qcar(v0080);
    v0089 = qcdr(v0080);
    v0080 = qvalue(elt(env, 1)); // renamings
    v0080 = acons(v0102, v0089, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0080; // renamings
    v0080 = stack[-1];
    v0089 = qcar(v0080);
    v0080 = stack[0];
    v0080 = qcar(v0080);
    v0080 = qcar(v0080);
    fn = elt(env, 3); // union
    v0102 = (*qfn2(fn))(qenv(fn), v0089, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0080 = stack[0];
    v0080 = qcar(v0080);
    v0089 = qcdr(v0080);
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    v0080 = acons(v0102, v0089, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    {
        LispObject v0100 = stack[-2];
        popv(4);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0100, v0080);
    }

v0033:
    v0080 = stack[0];
    v0089 = qcar(v0080);
    v0080 = stack[-2];
    v0080 = cons(v0089, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    stack[-2] = v0080;
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    stack[0] = v0080;
    goto v0040;

v0036:
    stack[0] = stack[-2];
    v0080 = stack[-1];
    v0080 = ncons(v0080);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    {
        LispObject v0088 = stack[0];
        popv(4);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0088, v0080);
    }
// error exit handlers
v0029:
    popv(4);
    return nil;
}



// Code for procstat

static LispObject CC_procstat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0037;
    LispObject fn;
    argcheck(nargs, 0, "procstat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for procstat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0037 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // procstat1
        return (*qfn1(fn))(qenv(fn), v0037);
    }
}



// Code for sfto_gcdf

static LispObject CC_sfto_gcdf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0044, v0045;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_gcdf");
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
    v0044 = qvalue(elt(env, 1)); // !*rldavgcd
    if (v0044 == nil) goto v0034;
    v0045 = stack[-1];
    v0044 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 4); // sfto_davp
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-3];
    if (!(v0044 == nil)) goto v0010;
    v0045 = stack[0];
    v0044 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 4); // sfto_davp
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-3];
    if (!(v0044 == nil)) goto v0010;
    v0045 = stack[-1];
    v0044 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // ezgcdf
        return (*qfn2(fn))(qenv(fn), v0045, v0044);
    }

v0010:
    v0044 = qvalue(elt(env, 2)); // nil
    stack[-2] = qvalue(elt(env, 3)); // !*ezgcd
    qvalue(elt(env, 3)) = v0044; // !*ezgcd
    v0045 = stack[-1];
    v0044 = stack[0];
    fn = elt(env, 6); // gcdf
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; // !*ezgcd
    { popv(4); return onevalue(v0044); }

v0034:
    v0045 = stack[-1];
    v0044 = stack[0];
    {
        popv(4);
        fn = elt(env, 6); // gcdf
        return (*qfn2(fn))(qenv(fn), v0045, v0044);
    }
// error exit handlers
v0068:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; // !*ezgcd
    popv(4);
    return nil;
v0058:
    popv(4);
    return nil;
}



// Code for gcdf1

static LispObject CC_gcdf1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0236, v0237;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf1");
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
    v0236 = stack[-2];
    if (v0236 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0236 = stack[-1];
    if (v0236 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0237 = stack[-2];
    v0236 = (LispObject)17; // 1
    if (v0237 == v0236) goto v0004;
    v0237 = stack[-1];
    v0236 = (LispObject)17; // 1
    v0236 = (v0237 == v0236 ? lisp_true : nil);
    goto v0012;

v0012:
    if (v0236 == nil) goto v0002;
    v0236 = (LispObject)17; // 1
    { popv(5); return onevalue(v0236); }

v0002:
    v0236 = stack[-2];
    if (!consp(v0236)) goto v0069;
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    v0236 = (consp(v0236) ? nil : lisp_true);
    goto v0076;

v0076:
    if (v0236 == nil) goto v0061;
    v0237 = stack[-2];
    v0236 = stack[-1];
    {
        popv(5);
        fn = elt(env, 8); // gcdfd
        return (*qfn2(fn))(qenv(fn), v0237, v0236);
    }

v0061:
    v0236 = stack[-1];
    if (!consp(v0236)) goto v0018;
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = (consp(v0236) ? nil : lisp_true);
    goto v0046;

v0046:
    if (v0236 == nil) goto v0083;
    v0237 = stack[-1];
    v0236 = stack[-2];
    {
        popv(5);
        fn = elt(env, 8); // gcdfd
        return (*qfn2(fn))(qenv(fn), v0237, v0236);
    }

v0083:
    v0236 = qvalue(elt(env, 2)); // !*anygcd
    if (v0236 == nil) goto v0082;
    v0236 = stack[-2];
    fn = elt(env, 9); // num!-exponents
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    if (v0236 == nil) goto v0028;
    v0236 = stack[-1];
    fn = elt(env, 9); // num!-exponents
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0081;

v0081:
    if (v0236 == nil) goto v0225;
    v0236 = (LispObject)17; // 1
    { popv(5); return onevalue(v0236); }

v0225:
    v0237 = stack[-2];
    v0236 = stack[-1];
    fn = elt(env, 10); // quotf1
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    if (!(v0236 == nil)) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0237 = stack[-1];
    v0236 = stack[-2];
    fn = elt(env, 10); // quotf1
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    if (!(v0236 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0237 = stack[-2];
    v0236 = stack[-1];
    fn = elt(env, 11); // gcdf2
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    stack[-3] = v0236;
    v0236 = qvalue(elt(env, 3)); // !*gcd
    if (v0236 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0237 = qvalue(elt(env, 4)); // dmode!*
    v0236 = elt(env, 5); // (!:rd!: !:cr!:)
    v0236 = Lmemq(nil, v0237, v0236);
    if (v0236 == nil) goto v0197;
    v0236 = qvalue(elt(env, 6)); // nil
    goto v0208;

v0208:
    if (v0236 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0236 = stack[-2];
    fn = elt(env, 12); // noncomfp
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    if (!(v0236 == nil)) goto v0238;
    v0236 = stack[-1];
    fn = elt(env, 12); // noncomfp
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    if (!(v0236 == nil)) goto v0238;
    stack[0] = elt(env, 7); // "gcdf failed"
    v0236 = stack[-2];
    fn = elt(env, 13); // prepf
    stack[-2] = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    v0236 = stack[-1];
    fn = elt(env, 13); // prepf
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    v0236 = list3(stack[0], stack[-2], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    fn = elt(env, 14); // errach
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0238:
    v0236 = (LispObject)17; // 1
    { popv(5); return onevalue(v0236); }

v0197:
    v0237 = stack[-2];
    v0236 = stack[-3];
    fn = elt(env, 10); // quotf1
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    if (v0236 == nil) goto v0239;
    v0237 = stack[-1];
    v0236 = stack[-3];
    fn = elt(env, 10); // quotf1
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0208;

v0239:
    v0236 = qvalue(elt(env, 1)); // t
    goto v0208;

v0028:
    v0236 = qvalue(elt(env, 1)); // t
    goto v0081;

v0082:
    v0236 = qvalue(elt(env, 1)); // t
    goto v0081;

v0018:
    v0236 = qvalue(elt(env, 1)); // t
    goto v0046;

v0069:
    v0236 = qvalue(elt(env, 1)); // t
    goto v0076;

v0004:
    v0236 = qvalue(elt(env, 1)); // t
    goto v0012;
// error exit handlers
v0153:
    popv(5);
    return nil;
}



// Code for ibalp_calcmom

static LispObject CC_ibalp_calcmom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0059, v0071;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_calcmom");
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
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0071 = qcar(v0059);
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcar(v0059);
    v0071 = plus2(v0071, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    v0059 = (LispObject)513; // 32
    stack[-1] = times2(v0071, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0071 = qcar(v0059);
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcdr(v0059);
    v0059 = qcar(v0059);
    v0059 = times2(v0071, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    {
        LispObject v0108 = stack[-1];
        popv(3);
        return plus2(v0108, v0059);
    }
// error exit handlers
v0045:
    popv(3);
    return nil;
}



// Code for multi_elem

static LispObject CC_multi_elem(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0066;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multi_elem");
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
    v0050 = stack[0];
    v0066 = Llength(nil, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    v0050 = (LispObject)17; // 1
    if (v0066 == v0050) goto v0040;
    v0050 = stack[0];
    v0050 = qcar(v0050);
    fn = elt(env, 2); // expression
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    v0050 = CC_multi_elem(env, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    goto v0006;

v0006:
    v0050 = nil;
    { popv(2); return onevalue(v0050); }

v0040:
    v0050 = stack[0];
    v0050 = qcar(v0050);
    fn = elt(env, 2); // expression
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    goto v0006;
// error exit handlers
v0025:
    popv(2);
    return nil;
}



setup_type const u06_setup[] =
{
    {"delete_from_alglist",     too_few_2,      CC_delete_from_alglist,wrong_no_2},
    {"mri_0mk2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mri_0mk2},
    {"pasf_susipost",           too_few_2,      CC_pasf_susipost,wrong_no_2},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"fast-column-dim",         CC_fastKcolumnKdim,too_many_1, wrong_no_1},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"algid",                   too_few_2,      CC_algid,      wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {"safe-fp-minus",           CC_safeKfpKminus,too_many_1,   wrong_no_1},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"getelv",                  CC_getelv,      too_many_1,    wrong_no_1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"lalr_action",             too_few_2,      CC_lalr_action,wrong_no_2},
    {"xread",                   CC_xread,       too_many_1,    wrong_no_1},
    {"sfto_gcdf*",              too_few_2,      CC_sfto_gcdfH, wrong_no_2},
    {"removev",                 too_few_2,      CC_removev,    wrong_no_2},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"mk*sq",                   CC_mkHsq,       too_many_1,    wrong_no_1},
    {"comm_kernels",            CC_comm_kernels,too_many_1,    wrong_no_1},
    {":times",                  too_few_2,      CC_Ttimes,     wrong_no_2},
    {"areallindices",           CC_areallindices,too_many_1,   wrong_no_1},
    {"*ssave",                  too_few_2,      CC_Hssave,     wrong_no_2},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"bc=simp",                 CC_bcMsimp,     too_many_1,    wrong_no_1},
    {"vecp",                    CC_vecp,        too_many_1,    wrong_no_1},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"set_svf",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_set_svf},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"checkargcount",           too_few_2,      CC_checkargcount,wrong_no_2},
    {"wulessp",                 too_few_2,      CC_wulessp,    wrong_no_2},
    {"mcharg1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg1},
    {"mri_type",                CC_mri_type,    too_many_1,    wrong_no_1},
    {"qqe_prepat",              CC_qqe_prepat,  too_many_1,    wrong_no_1},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"exptchk",                 CC_exptchk,     too_many_1,    wrong_no_1},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"freeindexchk",            CC_freeindexchk,too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"chundexp",                CC_chundexp,    too_many_1,    wrong_no_1},
    {"physopp*",                CC_physoppH,    too_many_1,    wrong_no_1},
    {"getel",                   CC_getel,       too_many_1,    wrong_no_1},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"copy",                    CC_copy,        too_many_1,    wrong_no_1},
    {"general-modular-quotient",too_few_2,      CC_generalKmodularKquotient,wrong_no_2},
    {"times-term-mod-p",        too_few_2,      CC_timesKtermKmodKp,wrong_no_2},
    {"cancel",                  CC_cancel,      too_many_1,    wrong_no_1},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"mri_simplfloor",          CC_mri_simplfloor,too_many_1,  wrong_no_1},
    {"rl_simpat",               CC_rl_simpat,   too_many_1,    wrong_no_1},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"freexp",                  CC_freexp,      too_many_1,    wrong_no_1},
    {"prepd",                   CC_prepd,       too_many_1,    wrong_no_1},
    {"quotematrix",             CC_quotematrix, too_many_1,    wrong_no_1},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"round:mt",                too_few_2,      CC_roundTmt,   wrong_no_2},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"red-char-downcase",       CC_redKcharKdowncase,too_many_1,wrong_no_1},
    {"repeatsp",                CC_repeatsp,    too_many_1,    wrong_no_1},
    {"macrochk",                too_few_2,      CC_macrochk,   wrong_no_2},
    {"red_divtestbe",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_divtestbe},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"*i2ar",                   CC_Hi2ar,       too_many_1,    wrong_no_1},
    {"*modular2f",              CC_Hmodular2f,  too_many_1,    wrong_no_1},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"lalr_insert_core",        too_few_2,      CC_lalr_insert_core,wrong_no_2},
    {"procstat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_procstat},
    {"sfto_gcdf",               too_few_2,      CC_sfto_gcdf,  wrong_no_2},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"ibalp_calcmom",           CC_ibalp_calcmom,too_many_1,   wrong_no_1},
    {"multi_elem",              CC_multi_elem,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u06", (two_args *)"1207 8275650 9292302", 0}
};

// end of generated code
