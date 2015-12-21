
// $destdir/u05.c        Machine generated C code

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



// Code for depends

static LispObject CC_depends(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0031, v0032, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depends");
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
    v0031 = stack[-1];
    if (v0031 == nil) goto v0034;
    v0031 = stack[-1];
    v0031 = (is_number(v0031) ? lisp_true : nil);
    if (!(v0031 == nil)) goto v0035;
    v0031 = stack[0];
    v0031 = (is_number(v0031) ? lisp_true : nil);
    goto v0035;

v0035:
    if (v0031 == nil) goto v0036;
    v0031 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0031); }

v0036:
    v0032 = stack[-1];
    v0031 = stack[0];
    if (equal(v0032, v0031)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0031 = stack[-1];
    if (!consp(v0031)) goto v0037;
    v0031 = qvalue(elt(env, 2)); // nil
    goto v0038;

v0038:
    if (v0031 == nil) goto v0039;
    v0031 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0031); }

v0039:
    v0032 = stack[-1];
    v0031 = qvalue(elt(env, 4)); // depl!*
    v0031 = Lassoc(nil, v0032, v0031);
    v0032 = v0031;
    v0031 = v0032;
    if (v0031 == nil) goto v0040;
    v0031 = v0032;
    v0032 = qcdr(v0031);
    v0031 = stack[0];
    fn = elt(env, 6); // ldepends
    v0031 = (*qfn2(fn))(qenv(fn), v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    goto v0042;

v0042:
    if (v0031 == nil) goto v0043;
    v0031 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0031); }

v0043:
    v0031 = stack[-1];
    if (!consp(v0031)) goto v0044;
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    if (symbolp(v0031)) goto v0045;
    v0031 = qvalue(elt(env, 2)); // nil
    goto v0046;

v0046:
    if (v0031 == nil) goto v0047;
    v0031 = stack[-1];
    v0032 = qcar(v0031);
    v0031 = elt(env, 5); // domain!-depends!-fn
    v0031 = get(v0032, v0031);
    env = stack[-2];
    v0032 = v0031;
    v0031 = v0032;
    if (v0031 == nil) goto v0048;
    v0033 = v0032;
    v0032 = stack[-1];
    v0031 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v0033, v0032, v0031);

v0048:
    v0031 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0031); }

v0047:
    v0031 = stack[-1];
    if (!consp(v0031)) goto v0049;
    v0031 = stack[-1];
    v0032 = qcdr(v0031);
    v0031 = stack[0];
    fn = elt(env, 6); // ldepends
    v0031 = (*qfn2(fn))(qenv(fn), v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    if (!(v0031 == nil)) goto v0050;
    v0031 = stack[-1];
    v0032 = qcar(v0031);
    v0031 = stack[0];
    v0031 = CC_depends(env, v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    goto v0050;

v0050:
    if (v0031 == nil) goto v0051;
    v0031 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0031); }

v0051:
    v0031 = stack[0];
    if (!consp(v0031)) goto v0052;
    v0031 = stack[0];
    v0031 = qcar(v0031);
    if (symbolp(v0031)) goto v0053;
    v0031 = qvalue(elt(env, 2)); // nil
    goto v0054;

v0054:
    if (v0031 == nil) goto v0055;
    v0031 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0031); }

v0055:
    v0031 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0031); }

v0053:
    v0031 = stack[0];
    v0031 = qcar(v0031);
    if (!symbolp(v0031)) v0031 = nil;
    else { v0031 = qfastgets(v0031);
           if (v0031 != nil) { v0031 = elt(v0031, 8); // dname
#ifdef RECORD_GET
             if (v0031 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0031 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0031 == SPID_NOPROP) v0031 = nil; }}
#endif
    goto v0054;

v0052:
    v0031 = qvalue(elt(env, 1)); // t
    goto v0054;

v0049:
    v0031 = qvalue(elt(env, 2)); // nil
    goto v0050;

v0045:
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    if (!symbolp(v0031)) v0031 = nil;
    else { v0031 = qfastgets(v0031);
           if (v0031 != nil) { v0031 = elt(v0031, 8); // dname
#ifdef RECORD_GET
             if (v0031 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0031 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0031 == SPID_NOPROP) v0031 = nil; }}
#endif
    goto v0046;

v0044:
    v0031 = qvalue(elt(env, 2)); // nil
    goto v0046;

v0040:
    v0031 = qvalue(elt(env, 2)); // nil
    goto v0042;

v0037:
    v0032 = stack[-1];
    v0031 = qvalue(elt(env, 3)); // frlis!*
    v0031 = Lmemq(nil, v0032, v0031);
    goto v0038;

v0034:
    v0031 = qvalue(elt(env, 1)); // t
    goto v0035;
// error exit handlers
v0041:
    popv(3);
    return nil;
}



// Code for prepf1a_reversed

static LispObject CC_prepf1a_reversed(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0048, v0071, v0072;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prepf1a_reversed");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepf1a_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0073:
    v0048 = stack[-2];
    if (v0048 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0048 = stack[-2];
    if (!consp(v0048)) goto v0074;
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    v0048 = (consp(v0048) ? nil : lisp_true);
    goto v0075;

v0075:
    if (v0048 == nil) goto v0076;
    v0048 = stack[-2];
    fn = elt(env, 5); // prepd
    stack[-2] = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    v0048 = stack[-1];
    fn = elt(env, 6); // exchk
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    v0048 = cons(stack[-2], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    fn = elt(env, 7); // retimes
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    v0072 = v0048;
    v0071 = v0072;
    v0048 = elt(env, 2); // plus
    if (!consp(v0071)) goto v0078;
    v0071 = qcar(v0071);
    if (!(v0071 == v0048)) goto v0078;
    v0048 = v0072;
    v0048 = qcdr(v0048);
    stack[-1] = v0048;
    goto v0079;

v0079:
    v0048 = stack[-1];
    if (v0048 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0048 = stack[-1];
    v0048 = qcar(v0048);
    v0071 = v0048;
    v0048 = stack[0];
    v0048 = cons(v0071, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    stack[0] = v0048;
    v0048 = stack[-1];
    v0048 = qcdr(v0048);
    stack[-1] = v0048;
    goto v0079;

v0078:
    v0071 = v0072;
    v0048 = stack[0];
    v0048 = cons(v0071, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    stack[0] = v0048;
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0076:
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    stack[-3] = qcdr(v0048);
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    v0048 = qcar(v0048);
    v0071 = qcar(v0048);
    v0048 = elt(env, 4); // k!*
    if (v0071 == v0048) goto v0080;
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    v0071 = qcar(v0048);
    v0048 = stack[-1];
    v0048 = cons(v0071, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    v0071 = v0048;
    goto v0081;

v0081:
    v0048 = stack[0];
    v0048 = CC_prepf1a_reversed(env, 3, stack[-3], v0071, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    stack[0] = v0048;
    v0048 = stack[-2];
    v0048 = qcdr(v0048);
    stack[-2] = v0048;
    goto v0073;

v0080:
    v0048 = stack[-1];
    v0071 = v0048;
    goto v0081;

v0074:
    v0048 = qvalue(elt(env, 1)); // t
    goto v0075;
// error exit handlers
v0077:
    popv(5);
    return nil;
}



// Code for rd!:onep

static LispObject CC_rdTonep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0038, v0088;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:onep");
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
    v0038 = v0000;
// end of prologue
    v0088 = v0038;
    v0088 = qcdr(v0088);
    if (!consp(v0088)) goto v0075;
    stack[0] = qvalue(elt(env, 3)); // bfone!*
    fn = elt(env, 4); // bftrim!:
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    {
        LispObject v0037 = stack[0];
        popv(2);
        fn = elt(env, 5); // equal!:
        return (*qfn2(fn))(qenv(fn), v0037, v0038);
    }

v0075:
    v0088 = elt(env, 1); // 1.0
    v0038 = qcdr(v0038);
    v0038 = difference2(v0088, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    v0038 = Labsval(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    v0088 = qvalue(elt(env, 2)); // !!fleps1
        popv(2);
        return Llessp(nil, v0038, v0088);
// error exit handlers
v0089:
    popv(2);
    return nil;
}



// Code for groebsearchinlist

static LispObject CC_groebsearchinlist(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0028, v0090;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebsearchinlist");
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

v0091:
    v0028 = stack[0];
    if (v0028 == nil) goto v0035;
    v0028 = stack[0];
    v0028 = qcar(v0028);
    v0028 = qcdr(v0028);
    v0090 = qcar(v0028);
    v0028 = stack[-1];
    fn = elt(env, 2); // buchvevdivides!?
    v0028 = (*qfn2(fn))(qenv(fn), v0090, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    if (v0028 == nil) goto v0092;
    v0028 = stack[0];
    v0028 = qcar(v0028);
    { popv(3); return onevalue(v0028); }

v0092:
    v0028 = stack[0];
    v0028 = qcdr(v0028);
    stack[0] = v0028;
    goto v0091;

v0035:
    v0028 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0028); }
// error exit handlers
v0024:
    popv(3);
    return nil;
}



// Code for int!-equiv!-chk

static LispObject CC_intKequivKchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0099, v0081, v0100;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for int-equiv-chk");
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
    v0099 = qvalue(elt(env, 1)); // !*noequiv
    if (!(v0099 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0099 = stack[0];
    if (!consp(v0099)) goto v0101;
    v0099 = stack[0];
    v0099 = qcar(v0099);
    if (!symbolp(v0099)) v0081 = nil;
    else { v0081 = qfastgets(v0099);
           if (v0081 != nil) { v0081 = elt(v0081, 15); // zerop
#ifdef RECORD_GET
             if (v0081 != SPID_NOPROP)
                record_get(elt(fastget_names, 15), 1);
             else record_get(elt(fastget_names, 15), 0),
                v0081 = nil; }
           else record_get(elt(fastget_names, 15), 0); }
#else
             if (v0081 == SPID_NOPROP) v0081 = nil; }}
#endif
    v0099 = stack[0];
    v0099 = Lapply1(nil, v0081, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    if (v0099 == nil) goto v0103;
    v0099 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0099); }

v0103:
    v0099 = stack[0];
    v0099 = qcar(v0099);
    if (!symbolp(v0099)) v0081 = nil;
    else { v0081 = qfastgets(v0099);
           if (v0081 != nil) { v0081 = elt(v0081, 26); // onep
#ifdef RECORD_GET
             if (v0081 != SPID_NOPROP)
                record_get(elt(fastget_names, 26), 1);
             else record_get(elt(fastget_names, 26), 0),
                v0081 = nil; }
           else record_get(elt(fastget_names, 26), 0); }
#else
             if (v0081 == SPID_NOPROP) v0081 = nil; }}
#endif
    v0099 = stack[0];
    v0099 = Lapply1(nil, v0081, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    if (v0099 == nil) goto v0104;
    v0099 = (LispObject)17; // 1
    { popv(2); return onevalue(v0099); }

v0104:
    v0099 = stack[0];
    v0099 = qcar(v0099);
    if (!symbolp(v0099)) v0099 = nil;
    else { v0099 = qfastgets(v0099);
           if (v0099 != nil) { v0099 = elt(v0099, 33); // intequivfn
#ifdef RECORD_GET
             if (v0099 != SPID_NOPROP)
                record_get(elt(fastget_names, 33), 1);
             else record_get(elt(fastget_names, 33), 0),
                v0099 = nil; }
           else record_get(elt(fastget_names, 33), 0); }
#else
             if (v0099 == SPID_NOPROP) v0099 = nil; }}
#endif
    v0100 = v0099;
    if (v0099 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0081 = v0100;
    v0099 = stack[0];
    v0099 = Lapply1(nil, v0081, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    v0100 = v0099;
    if (v0099 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0081 = v0100;
    v0099 = (LispObject)1; // 0
    if (!(v0081 == v0099)) { popv(2); return onevalue(v0100); }
    v0099 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0099); }

v0101:
    v0081 = stack[0];
    v0099 = (LispObject)1; // 0
    if (!(v0081 == v0099)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0099 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0099); }
// error exit handlers
v0102:
    popv(2);
    return nil;
}



// Code for delallasc

static LispObject CC_delallasc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0037, v0096, v0106;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delallasc");
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
    v0106 = nil;
    goto v0073;

v0073:
    v0037 = stack[0];
    if (v0037 == nil) goto v0034;
    v0096 = stack[-1];
    v0037 = stack[0];
    v0037 = qcar(v0037);
    v0037 = qcar(v0037);
    if (v0096 == v0037) goto v0085;
    v0037 = stack[0];
    v0037 = qcar(v0037);
    v0096 = v0106;
    v0037 = cons(v0037, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    v0106 = v0037;
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    stack[0] = v0037;
    goto v0073;

v0085:
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    stack[0] = v0037;
    goto v0073;

v0034:
    v0037 = v0106;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0037);
    }
// error exit handlers
v0025:
    popv(3);
    return nil;
}



// Code for getrmacro

static LispObject CC_getrmacro(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0066, v0109;
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
    v0040 = stack[0];
    if (symbolp(v0040)) goto v0035;
    v0040 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0040); }

v0035:
    v0040 = stack[0];
    fn = elt(env, 5); // getd
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-1];
    v0109 = v0040;
    if (v0040 == nil) goto v0111;
    v0040 = v0109;
    v0066 = qcar(v0040);
    v0040 = elt(env, 2); // macro
    if (v0066 == v0040) { popv(2); return onevalue(v0109); }
    else goto v0111;

v0111:
    v0066 = stack[0];
    v0040 = elt(env, 3); // inline
    v0040 = get(v0066, v0040);
    env = stack[-1];
    v0109 = v0040;
    if (v0040 == nil) goto v0104;
    v0040 = elt(env, 3); // inline
    v0066 = v0109;
    popv(2);
    return cons(v0040, v0066);

v0104:
    v0066 = stack[0];
    v0040 = elt(env, 4); // smacro
    v0040 = get(v0066, v0040);
    env = stack[-1];
    v0109 = v0040;
    if (v0040 == nil) goto v0021;
    v0040 = elt(env, 4); // smacro
    v0066 = v0109;
    popv(2);
    return cons(v0040, v0066);

v0021:
    v0040 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0040); }
// error exit handlers
v0110:
    popv(2);
    return nil;
}



// Code for dp_term

static LispObject CC_dp_term(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0112, v0113;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0112 = v0001;
    v0113 = v0000;
// end of prologue
    return cons(v0112, v0113);
}



// Code for pv_applp

static LispObject CC_pv_applp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0117, v0118;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_applp");
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
    stack[-4] = v0001;
    v0117 = v0000;
// end of prologue
    stack[-5] = v0117;
    v0117 = stack[-5];
    if (v0117 == nil) goto v0119;
    v0117 = stack[-5];
    v0117 = qcar(v0117);
    v0118 = v0117;
    v0117 = v0118;
    stack[0] = qcar(v0117);
    v0117 = v0118;
    v0118 = qcdr(v0117);
    v0117 = stack[-4];
    fn = elt(env, 2); // pappl0
    v0117 = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0117 = cons(stack[0], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0117 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    stack[-2] = v0117;
    stack[-3] = v0117;
    goto v0034;

v0034:
    v0117 = stack[-5];
    v0117 = qcdr(v0117);
    stack[-5] = v0117;
    v0117 = stack[-5];
    if (v0117 == nil) goto v0106;
    stack[-1] = stack[-2];
    v0117 = stack[-5];
    v0117 = qcar(v0117);
    v0118 = v0117;
    v0117 = v0118;
    stack[0] = qcar(v0117);
    v0117 = v0118;
    v0118 = qcdr(v0117);
    v0117 = stack[-4];
    fn = elt(env, 2); // pappl0
    v0117 = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0117 = cons(stack[0], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0117 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0117 = Lrplacd(nil, stack[-1], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0117 = stack[-2];
    v0117 = qcdr(v0117);
    stack[-2] = v0117;
    goto v0034;

v0106:
    v0117 = stack[-3];
    goto v0035;

v0035:
    {
        popv(7);
        fn = elt(env, 3); // pv_sort
        return (*qfn1(fn))(qenv(fn), v0117);
    }

v0119:
    v0117 = qvalue(elt(env, 1)); // nil
    goto v0035;
// error exit handlers
v0046:
    popv(7);
    return nil;
}



// Code for mkrn

static LispObject CC_mkrn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0121, v0022;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkrn");
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

v0112:
    v0022 = stack[-1];
    v0121 = (LispObject)1; // 0
    v0121 = (LispObject)lessp2(v0022, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    v0121 = v0121 ? lisp_true : nil;
    env = stack[-4];
    if (v0121 == nil) goto v0036;
    v0121 = stack[-2];
    v0121 = negate(v0121);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[-2] = v0121;
    v0121 = stack[-1];
    v0121 = negate(v0121);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[-1] = v0121;
    goto v0112;

v0036:
    v0022 = stack[-2];
    v0121 = stack[-1];
    v0121 = Lgcd(nil, v0022, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[-3] = v0121;
    stack[0] = elt(env, 1); // !:rn!:
    v0022 = stack[-2];
    v0121 = stack[-3];
    stack[-2] = quot2(v0022, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0022 = stack[-1];
    v0121 = stack[-3];
    v0121 = quot2(v0022, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    {
        LispObject v0040 = stack[0];
        LispObject v0066 = stack[-2];
        popv(5);
        return list2star(v0040, v0066, v0121);
    }
// error exit handlers
v0042:
    popv(5);
    return nil;
}



// Code for gen!-mult!-by!-const!-mod!-p

static LispObject CC_genKmultKbyKconstKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0061, v0062, v0122;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gen-mult-by-const-mod-p");
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
    v0061 = stack[-1];
    if (v0061 == nil) goto v0091;
    v0062 = stack[0];
    v0061 = (LispObject)17; // 1
    if (v0062 == v0061) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0061 = stack[-1];
    if (!consp(v0061)) goto v0087;
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    v0061 = (consp(v0061) ? nil : lisp_true);
    goto v0101;

v0101:
    if (v0061 == nil) goto v0097;
    v0062 = stack[-1];
    v0061 = stack[0];
    fn = elt(env, 3); // general!-modular!-times
    v0061 = (*qfn2(fn))(qenv(fn), v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0061);
    }

v0097:
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    v0062 = qcdr(v0061);
    v0061 = stack[0];
    stack[-2] = CC_genKmultKbyKconstKmodKp(env, v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0061 = stack[-1];
    v0062 = qcdr(v0061);
    v0061 = stack[0];
    v0061 = CC_genKmultKbyKconstKmodKp(env, v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    v0062 = stack[-2];
    v0122 = v0062;
    if (v0122 == nil) { popv(4); return onevalue(v0061); }
    v0122 = stack[-1];
    v0122 = qcar(v0122);
    v0122 = qcar(v0122);
    popv(4);
    return acons(v0122, v0062, v0061);

v0087:
    v0061 = qvalue(elt(env, 2)); // t
    goto v0101;

v0091:
    v0061 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0061); }
// error exit handlers
v0123:
    popv(4);
    return nil;
}



// Code for noncomp!*

static LispObject CC_noncompH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063, v0092;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomp*");
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
    v0063 = stack[0];
    fn = elt(env, 3); // noncomp
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    if (!(v0063 == nil)) { popv(2); return onevalue(v0063); }
    v0092 = stack[0];
    v0063 = elt(env, 1); // expt
    if (!consp(v0092)) goto v0087;
    v0092 = qcar(v0092);
    if (!(v0092 == v0063)) goto v0087;
    v0063 = stack[0];
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    {
        popv(2);
        fn = elt(env, 3); // noncomp
        return (*qfn1(fn))(qenv(fn), v0063);
    }

v0087:
    v0063 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0063); }
// error exit handlers
v0111:
    popv(2);
    return nil;
}



// Code for convprec!*

static LispObject CC_convprecH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0125, v0116;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convprec*");
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
    v0125 = v0000;
// end of prologue
    v0116 = v0125;
    if (!consp(v0116)) goto v0115;
    v0116 = elt(env, 1); // !:rd!:
    v0125 = cons(v0116, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[0];
    goto v0115;

v0115:
    {
        popv(1);
        fn = elt(env, 2); // convchk
        return (*qfn1(fn))(qenv(fn), v0125);
    }
// error exit handlers
v0086:
    popv(1);
    return nil;
}



// Code for subs3q

static LispObject CC_subs3q(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs3q");
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
    v0086 = qvalue(elt(env, 1)); // mchfg!*
    stack[-2] = v0086;
    v0086 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 1)) = v0086; // mchfg!*
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    fn = elt(env, 3); // subs3f
    stack[0] = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    fn = elt(env, 3); // subs3f
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    fn = elt(env, 4); // quotsq
    v0086 = (*qfn2(fn))(qenv(fn), stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    stack[-1] = v0086;
    v0086 = stack[-2];
    qvalue(elt(env, 1)) = v0086; // mchfg!*
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }
// error exit handlers
v0036:
    popv(4);
    return nil;
}



// Code for sort!-factors

static LispObject CC_sortKfactors(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0093, v0112;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sort-factors");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0093 = v0000;
// end of prologue
    v0112 = v0093;
    v0093 = elt(env, 1); // orderfactors
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(qenv(fn), v0112, v0093);
    }
}



// Code for rank

static LispObject CC_rank(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0128, v0129;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rank");
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
    v0128 = qvalue(elt(env, 1)); // !*mcd
    if (v0128 == nil) goto v0112;
    v0128 = stack[-2];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    { popv(5); return onevalue(v0128); }

v0112:
    v0128 = stack[-2];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    stack[-1] = v0128;
    v0128 = stack[-2];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    stack[0] = v0128;
    goto v0124;

v0124:
    v0128 = stack[-2];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    stack[-3] = v0128;
    v0128 = stack[-2];
    v0128 = qcdr(v0128);
    if (v0128 == nil) goto v0037;
    v0128 = stack[-2];
    v0128 = qcdr(v0128);
    stack[-2] = v0128;
    v0129 = stack[-2];
    v0128 = stack[0];
    fn = elt(env, 2); // degr
    v0129 = (*qfn2(fn))(qenv(fn), v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-4];
    v0128 = (LispObject)1; // 0
    if (!(v0129 == v0128)) goto v0124;
    v0129 = stack[-3];
    v0128 = (LispObject)1; // 0
    v0128 = (LispObject)lessp2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0128 = v0128 ? lisp_true : nil;
    env = stack[-4];
    if (v0128 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0129 = stack[-1];
    v0128 = (LispObject)1; // 0
    v0128 = (LispObject)lessp2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0128 = v0128 ? lisp_true : nil;
    if (v0128 == nil) goto v0102;
    v0128 = stack[-3];
    popv(5);
    return negate(v0128);

v0102:
    v0129 = stack[-1];
    v0128 = stack[-3];
    popv(5);
    return difference2(v0129, v0128);

v0037:
    v0129 = stack[-1];
    v0128 = stack[-3];
    popv(5);
    return difference2(v0129, v0128);
// error exit handlers
v0013:
    popv(5);
    return nil;
}



// Code for mathml

static LispObject CC_mathml(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0029;
    LispObject fn;
    argcheck(nargs, 0, "mathml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mathml");
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
    fn = elt(env, 2); // lex
    v0029 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // sub_math
        return (*qfnn(fn))(qenv(fn), 0);
    }
// error exit handlers
v0035:
    popv(1);
    return nil;
}



// Code for multi_isarb_compl

static LispObject CC_multi_isarb_compl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multi_isarb_compl");
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
    v0036 = Lconsp(nil, v0036);
    env = stack[-1];
    if (v0036 == nil) goto v0091;
    v0036 = stack[0];
    if (v0036 == nil) goto v0091;
    v0036 = stack[0];
    v0036 = qcar(v0036);
    fn = elt(env, 2); // isarb_compl
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0036 = stack[0];
    v0036 = qcdr(v0036);
    v0036 = CC_multi_isarb_compl(env, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    goto v0091;

v0091:
    v0036 = nil;
    { popv(2); return onevalue(v0036); }
// error exit handlers
v0092:
    popv(2);
    return nil;
}



// Code for sqform

static LispObject CC_sqform(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0120, v0103, v0069, v0068;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqform");
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
    v0103 = stack[0];
    v0120 = stack[-1];
    v0120 = qcar(v0120);
    stack[-2] = Lapply1(nil, v0103, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    v0103 = stack[0];
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    v0120 = Lapply1(nil, v0103, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    v0068 = stack[-2];
    v0069 = v0120;
    v0103 = v0069;
    v0120 = (LispObject)17; // 1
    if (v0103 == v0120) { popv(4); return onevalue(v0068); }
    v0120 = elt(env, 1); // quotient
    v0103 = v0068;
    popv(4);
    return list3(v0120, v0103, v0069);
// error exit handlers
v0079:
    popv(4);
    return nil;
}



// Code for dm!-difference

static LispObject CC_dmKdifference(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0101, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-difference");
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
    v0101 = v0000;
// end of prologue
    fn = elt(env, 1); // zero2nil
    v0087 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    v0101 = stack[0];
    fn = elt(env, 2); // !:difference
    v0101 = (*qfn2(fn))(qenv(fn), v0087, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    v0087 = v0101;
    v0101 = v0087;
    if (!(v0101 == nil)) { popv(2); return onevalue(v0087); }
    v0101 = (LispObject)1; // 0
    { popv(2); return onevalue(v0101); }
// error exit handlers
v0036:
    popv(2);
    return nil;
}



// Code for freeindexchk

static LispObject CC_freeindexchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0124, v0125;
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
    v0125 = v0000;
// end of prologue
    v0124 = v0125;
    if (v0124 == nil) goto v0030;
    v0124 = qvalue(elt(env, 1)); // indxl!*
    if (v0124 == nil) goto v0030;
    v0124 = v0125;
    fn = elt(env, 4); // indxchk
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[0];
    if (v0124 == nil) goto v0030;
    v0124 = elt(env, 2); // form!-with!-free!-indices
    { popv(1); return onevalue(v0124); }

v0030:
    v0124 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0124); }
// error exit handlers
v0116:
    popv(1);
    return nil;
}



// Code for putpline

static LispObject CC_putpline(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0128, v0129, v0134;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for putpline");
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
    v0129 = qvalue(elt(env, 1)); // posn!*
    v0128 = stack[0];
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    stack[-1] = (LispObject)(int32_t)((int32_t)v0129 + (int32_t)v0128 - TAG_FIXNUM);
    v0128 = qvalue(elt(env, 2)); // nil
    v0129 = Llinelength(nil, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0128 = qvalue(elt(env, 3)); // spare!*
    v0128 = (LispObject)(int32_t)((int32_t)v0129 - (int32_t)v0128 + TAG_FIXNUM);
    v0128 = (LispObject)greaterp2(stack[-1], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    v0128 = v0128 ? lisp_true : nil;
    env = stack[-2];
    if (v0128 == nil) goto v0103;
    v0128 = qvalue(elt(env, 4)); // t
    fn = elt(env, 10); // terpri!*
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    goto v0103;

v0103:
    v0129 = qvalue(elt(env, 1)); // posn!*
    v0128 = qvalue(elt(env, 5)); // orig!*
    v0134 = (LispObject)(int32_t)((int32_t)v0129 - (int32_t)v0128 + TAG_FIXNUM);
    v0129 = qvalue(elt(env, 6)); // ycoord!*
    v0128 = stack[0];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    fn = elt(env, 11); // update!-pline
    v0129 = (*qfnn(fn))(qenv(fn), 3, v0134, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0128 = qvalue(elt(env, 7)); // pline!*
    v0128 = Lappend(nil, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    qvalue(elt(env, 7)) = v0128; // pline!*
    v0129 = qvalue(elt(env, 1)); // posn!*
    v0128 = stack[0];
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    v0128 = (LispObject)(int32_t)((int32_t)v0129 + (int32_t)v0128 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v0128; // posn!*
    v0134 = qvalue(elt(env, 8)); // ymin!*
    v0128 = stack[0];
    v0128 = qcdr(v0128);
    v0129 = qcar(v0128);
    v0128 = qvalue(elt(env, 6)); // ycoord!*
    v0128 = (LispObject)(int32_t)((int32_t)v0129 + (int32_t)v0128 - TAG_FIXNUM);
    fn = elt(env, 12); // min
    v0128 = (*qfn2(fn))(qenv(fn), v0134, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0128; // ymin!*
    v0134 = qvalue(elt(env, 9)); // ymax!*
    v0128 = stack[0];
    v0128 = qcdr(v0128);
    v0129 = qcdr(v0128);
    v0128 = qvalue(elt(env, 6)); // ycoord!*
    v0128 = (LispObject)(int32_t)((int32_t)v0129 + (int32_t)v0128 - TAG_FIXNUM);
    fn = elt(env, 13); // max
    v0128 = (*qfn2(fn))(qenv(fn), v0134, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    qvalue(elt(env, 9)) = v0128; // ymax!*
    v0128 = nil;
    { popv(3); return onevalue(v0128); }
// error exit handlers
v0015:
    popv(3);
    return nil;
}



// Code for !:times

static LispObject CC_Ttimes(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0068, v0067, v0043;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0067 = v0001;
    v0043 = v0000;
// end of prologue
    v0068 = v0043;
    if (v0068 == nil) goto v0034;
    v0068 = v0067;
    v0068 = (v0068 == nil ? lisp_true : nil);
    goto v0035;

v0035:
    if (v0068 == nil) goto v0073;
    v0068 = qvalue(elt(env, 2)); // nil
    return onevalue(v0068);

v0073:
    v0068 = v0043;
    if (!consp(v0068)) goto v0101;
    v0068 = qvalue(elt(env, 2)); // nil
    goto v0086;

v0086:
    if (v0068 == nil) goto v0025;
    v0068 = v0043;
    return times2(v0068, v0067);

v0025:
    v0068 = elt(env, 3); // times
    {
        fn = elt(env, 4); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0043, v0067, v0068);
    }

v0101:
    v0068 = v0067;
    v0068 = (consp(v0068) ? nil : lisp_true);
    goto v0086;

v0034:
    v0068 = qvalue(elt(env, 1)); // t
    goto v0035;
}



// Code for dp!=ecart

static LispObject CC_dpMecart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0097, v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=ecart");
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
    goto v0073;

v0073:
    v0097 = stack[0];
    if (v0097 == nil) goto v0029;
    v0097 = stack[0];
    fn = elt(env, 1); // dp_lmon
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    fn = elt(env, 2); // mo_ecart
    v0025 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0097 = stack[-1];
    v0097 = cons(v0025, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    stack[-1] = v0097;
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    stack[0] = v0097;
    goto v0073;

v0029:
    v0097 = (LispObject)1; // 0
    v0025 = v0097;
    goto v0035;

v0035:
    v0097 = stack[-1];
    if (v0097 == nil) { popv(3); return onevalue(v0025); }
    v0097 = stack[-1];
    v0097 = qcar(v0097);
    v0097 = Lmax2(nil, v0097, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0025 = v0097;
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[-1] = v0097;
    goto v0035;
// error exit handlers
v0120:
    popv(3);
    return nil;
}



// Code for gcdf!*

static LispObject CC_gcdfH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0030, v0075, v0074;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf*");
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
    v0075 = v0001;
    v0074 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // !*gcd
    qvalue(elt(env, 1)) = nil; // !*gcd
    v0030 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0030; // !*gcd
    v0030 = v0074;
    fn = elt(env, 3); // gcdf
    v0030 = (*qfn2(fn))(qenv(fn), v0030, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*gcd
    { popv(2); return onevalue(v0030); }
// error exit handlers
v0125:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*gcd
    popv(2);
    return nil;
}



// Code for gperm1

static LispObject CC_gperm1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0018, v0042, v0040;
    LispObject fn;
    LispObject v0105, v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "gperm1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0105 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0105,v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0058,v0105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0105;
    stack[-2] = v0058;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue

v0034:
    v0018 = stack[-4];
    if (v0018 == nil) goto v0075;
    v0018 = stack[-4];
    v0018 = qcdr(v0018);
    stack[-5] = v0018;
    v0018 = stack[-4];
    v0042 = qcar(v0018);
    v0018 = stack[-2];
    v0018 = cons(v0042, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-6];
    stack[0] = v0018;
    v0042 = stack[-3];
    v0018 = stack[-2];
    v0018 = cons(v0042, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-6];
    fn = elt(env, 1); // rev
    v0042 = (*qfn2(fn))(qenv(fn), stack[-4], v0018);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-6];
    v0018 = stack[-1];
    v0018 = cons(v0042, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-6];
    stack[-1] = v0018;
    v0018 = stack[0];
    stack[-2] = v0018;
    v0018 = stack[-5];
    stack[-4] = v0018;
    goto v0034;

v0075:
    v0040 = stack[-3];
    v0042 = stack[-2];
    v0018 = stack[-1];
    popv(7);
    return acons(v0040, v0042, v0018);
// error exit handlers
v0094:
    popv(7);
    return nil;
}



// Code for mod!#

static LispObject CC_modC(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0083, v0024;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mod#");
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
    v0024 = v0083;
    v0083 = qvalue(elt(env, 1)); // current!-modulus
    v0083 = Cremainder(v0024, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-1];
    stack[0] = v0083;
    v0024 = stack[0];
    v0083 = (LispObject)1; // 0
    v0083 = (LispObject)lessp2(v0024, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    v0083 = v0083 ? lisp_true : nil;
    env = stack[-1];
    if (v0083 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0083 = stack[0];
    v0024 = qvalue(elt(env, 1)); // current!-modulus
    popv(2);
    return plus2(v0083, v0024);
// error exit handlers
v0088:
    popv(2);
    return nil;
}



// Code for times!-in!-vector

static LispObject CC_timesKinKvector(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0052, v0148, v0149, v0150, v0151, v0152, v0003, v0153, v0154, v0155, v0156, v0157, v0158, v0053, v0159;
    LispObject v0115, v0105, v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "times-in-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0105 = va_arg(aa, LispObject);
    v0115 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for times-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0115,v0105,v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0058,v0105,v0115);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0155 = v0115;
    v0156 = v0105;
    v0157 = v0058;
    v0158 = v0001;
    v0053 = v0000;
// end of prologue
    v0148 = v0158;
    v0052 = (LispObject)1; // 0
    if (((int32_t)(v0148)) < ((int32_t)(v0052))) goto v0119;
    v0148 = v0156;
    v0052 = (LispObject)1; // 0
    if (((int32_t)(v0148)) < ((int32_t)(v0052))) goto v0119;
    v0148 = v0158;
    v0052 = v0156;
    v0052 = (LispObject)(int32_t)((int32_t)v0148 + (int32_t)v0052 - TAG_FIXNUM);
    v0159 = v0052;
    v0052 = (LispObject)1; // 0
    v0150 = v0052;
    goto v0103;

v0103:
    v0148 = v0159;
    v0052 = v0150;
    v0052 = (LispObject)(int32_t)((int32_t)v0148 - (int32_t)v0052 + TAG_FIXNUM);
    v0052 = ((intptr_t)(v0052) < 0 ? lisp_true : nil);
    if (v0052 == nil) goto v0022;
    v0052 = (LispObject)1; // 0
    v0153 = v0052;
    goto v0078;

v0078:
    v0148 = v0158;
    v0052 = v0153;
    v0052 = (LispObject)(int32_t)((int32_t)v0148 - (int32_t)v0052 + TAG_FIXNUM);
    v0052 = ((intptr_t)(v0052) < 0 ? lisp_true : nil);
    if (!(v0052 == nil)) { popv(1); return onevalue(v0159); }
    v0148 = v0053;
    v0052 = v0153;
    v0052 = *(LispObject *)((char *)v0148 + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL)));
    v0154 = v0052;
    v0052 = (LispObject)1; // 0
    v0003 = v0052;
    goto v0129;

v0129:
    v0148 = v0156;
    v0052 = v0003;
    v0052 = (LispObject)(int32_t)((int32_t)v0148 - (int32_t)v0052 + TAG_FIXNUM);
    v0052 = ((intptr_t)(v0052) < 0 ? lisp_true : nil);
    if (v0052 == nil) goto v0160;
    v0052 = v0153;
    v0052 = (LispObject)((int32_t)(v0052) + 0x10);
    v0153 = v0052;
    goto v0078;

v0160:
    v0148 = v0153;
    v0052 = v0003;
    v0052 = (LispObject)(int32_t)((int32_t)v0148 + (int32_t)v0052 - TAG_FIXNUM);
    v0152 = v0155;
    v0151 = v0052;
    v0148 = v0155;
    v0150 = *(LispObject *)((char *)v0148 + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL)));
    v0149 = v0154;
    v0148 = v0157;
    v0052 = v0003;
    v0052 = *(LispObject *)((char *)v0148 + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL)));
    v0052 = Lmodular_times(nil, v0149, v0052);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v0150) + int_of_fixnum(v0052);
        if (w >= current_modulus) w -= current_modulus;
        v0052 = fixnum_of_int(w);
    }
    *(LispObject *)((char *)v0152 + (CELL-TAG_VECTOR) + ((int32_t)v0151/(16/CELL))) = v0052;
    v0052 = v0003;
    v0052 = (LispObject)((int32_t)(v0052) + 0x10);
    v0003 = v0052;
    goto v0129;

v0022:
    v0149 = v0155;
    v0148 = v0150;
    v0052 = (LispObject)1; // 0
    *(LispObject *)((char *)v0149 + (CELL-TAG_VECTOR) + ((int32_t)v0148/(16/CELL))) = v0052;
    v0052 = v0150;
    v0052 = (LispObject)((int32_t)(v0052) + 0x10);
    v0150 = v0052;
    goto v0103;

v0119:
    v0052 = (LispObject)-15; // -1
    { popv(1); return onevalue(v0052); }
}



// Code for qqe_qtidp

static LispObject CC_qqe_qtidp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0112, v0113;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qtidp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0112 = v0000;
// end of prologue
    if (!symbolp(v0112)) v0112 = nil;
    else { v0112 = qfastgets(v0112);
           if (v0112 != nil) { v0112 = elt(v0112, 10); // idtype
#ifdef RECORD_GET
             if (v0112 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v0112 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v0112 == SPID_NOPROP) v0112 = nil; }}
#endif
    v0113 = elt(env, 1); // qt
    v0112 = (v0112 == v0113 ? lisp_true : nil);
    return onevalue(v0112);
}



// Code for pasf_susipost

static LispObject CC_pasf_susipost(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject v0115, v0091;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_susipost");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0115 = v0001;
    v0091 = v0000;
// end of prologue
    return onevalue(v0091);
}



// Code for omobj

static LispObject CC_omobj(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0098, v0111;
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
    v0098 = qvalue(elt(env, 1)); // char
    fn = elt(env, 4); // compress!*
    v0111 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[0];
    v0098 = qvalue(elt(env, 2)); // omfuncs!*
    v0098 = Lassoc(nil, v0111, v0098);
    v0111 = v0098;
    if (v0098 == nil) goto v0073;
    v0098 = v0111;
    v0098 = qcdr(v0098);
    v0111 = qcar(v0098);
    v0098 = qvalue(elt(env, 3)); // nil
    {
        popv(1);
        fn = elt(env, 5); // apply
        return (*qfn2(fn))(qenv(fn), v0111, v0098);
    }

v0073:
    v0098 = nil;
    { popv(1); return onevalue(v0098); }
// error exit handlers
v0027:
    popv(1);
    return nil;
}



// Code for emtch

static LispObject CC_emtch(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for emtch");
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
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0101 = stack[0];
    if (!consp(v0101)) { LispObject res = stack[0]; popv(1); return onevalue(res); }
    v0101 = stack[0];
    fn = elt(env, 1); // opmtch
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    v0087 = v0101;
    v0101 = v0087;
    if (v0101 == nil) { LispObject res = stack[0]; popv(1); return onevalue(res); }
    else { popv(1); return onevalue(v0087); }
// error exit handlers
v0036:
    popv(1);
    return nil;
}



// Code for sortcolelem

static LispObject CC_sortcolelem(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0045, v0102;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sortcolelem");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sortcolelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0058;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    stack[0] = nil;
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    stack[-4] = v0045;
    goto v0113;

v0113:
    v0045 = stack[0];
    if (v0045 == nil) goto v0085;
    v0045 = nil;
    { popv(6); return onevalue(v0045); }

v0085:
    v0045 = stack[-4];
    if (v0045 == nil) goto v0036;
    v0102 = stack[-3];
    v0045 = stack[-4];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0045 = (LispObject)lessp2(v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    v0045 = v0045 ? lisp_true : nil;
    env = stack[-5];
    if (v0045 == nil) goto v0078;
    stack[0] = stack[-2];
    v0102 = stack[-3];
    v0045 = stack[-1];
    v0045 = cons(v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0102 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0045 = stack[-4];
    v0045 = Lrplacd(nil, v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0045 = Lrplacd(nil, stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0045 = qvalue(elt(env, 2)); // t
    stack[0] = v0045;
    goto v0113;

v0078:
    v0102 = stack[-3];
    v0045 = stack[-4];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0045 = (LispObject)greaterp2(v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    v0045 = v0045 ? lisp_true : nil;
    env = stack[-5];
    if (v0045 == nil) goto v0113;
    v0045 = qvalue(elt(env, 1)); // nil
    stack[0] = v0045;
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    stack[-2] = v0045;
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    stack[-4] = v0045;
    goto v0113;

v0036:
    stack[0] = stack[-2];
    v0102 = stack[-3];
    v0045 = stack[-1];
    v0045 = cons(v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0045 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0045 = Lrplacd(nil, stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0045 = qvalue(elt(env, 2)); // t
    stack[0] = v0045;
    goto v0113;
// error exit handlers
v0126:
    popv(6);
    return nil;
}



// Code for fast!-column!-dim

static LispObject CC_fastKcolumnKdim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0113, v0119;
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
    v0113 = v0000;
// end of prologue
    v0119 = v0113;
    v0113 = (LispObject)1; // 0
    v0113 = *(LispObject *)((char *)v0119 + (CELL-TAG_VECTOR) + ((int32_t)v0113/(16/CELL)));
    v0113 = Lupbv(nil, v0113);
    errexit();
    return add1(v0113);
}



// Code for mknwedge

static LispObject CC_mknwedge(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0116, v0086;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mknwedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0086 = v0000;
// end of prologue
    v0116 = v0086;
    v0116 = qcdr(v0116);
    if (v0116 == nil) goto v0075;
    v0116 = elt(env, 1); // wedge
    return cons(v0116, v0086);

v0075:
    v0116 = v0086;
    v0116 = qcar(v0116);
    return onevalue(v0116);
}



// Code for smemql

static LispObject CC_smemql(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0037, v0096;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemql");
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
    goto v0073;

v0073:
    v0037 = stack[-1];
    if (v0037 == nil) goto v0034;
    v0037 = stack[-1];
    v0096 = qcar(v0037);
    v0037 = stack[0];
    v0037 = Lsmemq(nil, v0096, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    if (v0037 == nil) goto v0038;
    v0037 = stack[-1];
    v0096 = qcar(v0037);
    v0037 = stack[-2];
    v0037 = cons(v0096, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    stack[-2] = v0037;
    v0037 = stack[-1];
    v0037 = qcdr(v0037);
    stack[-1] = v0037;
    goto v0073;

v0038:
    v0037 = stack[-1];
    v0037 = qcdr(v0037);
    stack[-1] = v0037;
    goto v0073;

v0034:
    v0037 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0037);
    }
// error exit handlers
v0025:
    popv(4);
    return nil;
}



// Code for get!-print!-name

static LispObject CC_getKprintKname(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0075, v0074;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-print-name");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0074 = v0000;
// end of prologue
    v0075 = v0074;
    if (symbolp(v0075)) goto v0112;
    v0075 = qvalue(elt(env, 1)); // nil
    goto v0073;

v0073:
    if (v0075 == nil) return onevalue(v0074);
    else return onevalue(v0075);

v0112:
    v0075 = v0074;
    if (!symbolp(v0075)) v0075 = nil;
    else { v0075 = qfastgets(v0075);
           if (v0075 != nil) { v0075 = elt(v0075, 12); // oldnam
#ifdef RECORD_GET
             if (v0075 != SPID_NOPROP)
                record_get(elt(fastget_names, 12), 1);
             else record_get(elt(fastget_names, 12), 0),
                v0075 = nil; }
           else record_get(elt(fastget_names, 12), 0); }
#else
             if (v0075 == SPID_NOPROP) v0075 = nil; }}
#endif
    goto v0073;
}



// Code for getelv

static LispObject CC_getelv(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0079;
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
    v0079 = v0000;
// end of prologue
    v0039 = v0079;
    stack[-4] = qcar(v0039);
    v0039 = v0079;
    v0039 = qcdr(v0039);
    stack[-3] = v0039;
    v0039 = stack[-3];
    if (v0039 == nil) goto v0086;
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    fn = elt(env, 2); // reval_without_mod
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-5];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-5];
    stack[-1] = v0039;
    stack[-2] = v0039;
    goto v0075;

v0075:
    v0039 = stack[-3];
    v0039 = qcdr(v0039);
    stack[-3] = v0039;
    v0039 = stack[-3];
    if (v0039 == nil) goto v0024;
    stack[0] = stack[-1];
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    fn = elt(env, 2); // reval_without_mod
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-5];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-5];
    v0039 = Lrplacd(nil, stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-5];
    v0039 = stack[-1];
    v0039 = qcdr(v0039);
    stack[-1] = v0039;
    goto v0075;

v0024:
    v0039 = stack[-2];
    goto v0029;

v0029:
    v0039 = cons(stack[-4], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 3); // getel
        return (*qfn1(fn))(qenv(fn), v0039);
    }

v0086:
    v0039 = qvalue(elt(env, 1)); // nil
    goto v0029;
// error exit handlers
v0107:
    popv(6);
    return nil;
}



// Code for dp_diff

static LispObject CC_dp_diff(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0113, v0119;
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
    v0113 = v0001;
    v0119 = v0000;
// end of prologue
    stack[0] = v0119;
    fn = elt(env, 1); // dp_neg
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    {
        LispObject v0075 = stack[0];
        popv(2);
        fn = elt(env, 2); // dp_sum
        return (*qfn2(fn))(qenv(fn), v0075, v0113);
    }
// error exit handlers
v0030:
    popv(2);
    return nil;
}



// Code for vecp

static LispObject CC_vecp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0013, v0146, v0162;
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
    v0146 = v0000;
// end of prologue
    v0015 = v0146;
    if (v0015 == nil) goto v0112;
    v0015 = v0146;
    v0015 = (is_number(v0015) ? lisp_true : nil);
    goto v0093;

v0093:
    if (v0015 == nil) goto v0035;
    v0015 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0015); }

v0035:
    v0015 = v0146;
    if (!consp(v0015)) goto v0092;
    v0015 = v0146;
    v0015 = Lthreevectorp(nil, v0015);
    env = stack[0];
    if (v0015 == nil) goto v0096;
    v0015 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0015); }

v0096:
    v0015 = v0146;
    v0015 = qcar(v0015);
    v0162 = v0015;
    if (!consp(v0015)) goto v0043;
    v0015 = qvalue(elt(env, 2)); // nil
    goto v0120;

v0120:
    if (v0015 == nil) goto v0094;
    v0015 = v0146;
    v0015 = qcdr(v0015);
    v0015 = qcar(v0015);
    {
        popv(1);
        fn = elt(env, 7); // isvectorindex
        return (*qfn1(fn))(qenv(fn), v0015);
    }

v0094:
    v0013 = v0162;
    v0015 = elt(env, 4); // vectorfn
    v0015 = Lflagp(nil, v0013, v0015);
    env = stack[0];
    if (v0015 == nil) goto v0122;
    v0015 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0015); }

v0122:
    v0013 = v0162;
    v0015 = elt(env, 5); // varithop
    v0015 = Lflagp(nil, v0013, v0015);
    env = stack[0];
    if (v0015 == nil) goto v0057;
    v0015 = qvalue(elt(env, 1)); // t
    goto v0016;

v0016:
    if (v0015 == nil) goto v0134;
    v0015 = v0146;
    v0015 = qcdr(v0015);
    {
        popv(1);
        fn = elt(env, 8); // hasonevector
        return (*qfn1(fn))(qenv(fn), v0015);
    }

v0134:
    v0015 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0015); }

v0057:
    v0013 = v0162;
    v0015 = elt(env, 6); // vectormapping
    v0015 = Lflagp(nil, v0013, v0015);
    env = stack[0];
    goto v0016;

v0043:
    v0015 = v0162;
    if (!symbolp(v0015)) v0013 = nil;
    else { v0013 = qfastgets(v0015);
           if (v0013 != nil) { v0013 = elt(v0013, 2); // rtype
#ifdef RECORD_GET
             if (v0013 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0013 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0013 == SPID_NOPROP) v0013 = nil; }}
#endif
    v0015 = elt(env, 3); // !3vector
    v0015 = (v0013 == v0015 ? lisp_true : nil);
    goto v0120;

v0092:
    v0015 = v0146;
    if (!symbolp(v0015)) v0013 = nil;
    else { v0013 = qfastgets(v0015);
           if (v0013 != nil) { v0013 = elt(v0013, 2); // rtype
#ifdef RECORD_GET
             if (v0013 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0013 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0013 == SPID_NOPROP) v0013 = nil; }}
#endif
    v0015 = elt(env, 3); // !3vector
    if (v0013 == v0015) goto v0036;
    v0015 = v0146;
        popv(1);
        return Lthreevectorp(nil, v0015);

v0036:
    v0015 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0015); }

v0112:
    v0015 = qvalue(elt(env, 1)); // t
    goto v0093;
}



// Code for tsym4

static LispObject CC_tsym4(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0097, v0025;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "tsym4");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tsym4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0001;
    v0097 = v0000;
// end of prologue

v0029:
    v0025 = v0097;
    if (v0025 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0025 = v0097;
    v0025 = qcdr(v0025);
    stack[-2] = v0025;
    v0025 = stack[-1];
    v0025 = qcdr(v0025);
    v0097 = qcar(v0097);
    fn = elt(env, 1); // pv_applp
    v0025 = (*qfn2(fn))(qenv(fn), v0025, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-3];
    v0097 = stack[0];
    fn = elt(env, 2); // sieve_pv
    v0097 = (*qfn2(fn))(qenv(fn), v0025, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-3];
    fn = elt(env, 3); // pv_renorm
    v0025 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-3];
    v0097 = stack[0];
    fn = elt(env, 4); // insert_pv
    v0097 = (*qfn2(fn))(qenv(fn), v0025, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-3];
    stack[0] = v0097;
    v0097 = stack[-2];
    goto v0029;
// error exit handlers
v0103:
    popv(4);
    return nil;
}



// Code for exptmod!:

static LispObject CC_exptmodT(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0119, v0085;
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
    v0119 = v0001;
    v0085 = v0000;
// end of prologue
    v0085 = qcdr(v0085);
    fn = elt(env, 1); // general!-modular!-expt
    v0119 = (*qfn2(fn))(qenv(fn), v0085, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(qenv(fn), v0119);
    }
// error exit handlers
v0030:
    popv(1);
    return nil;
}



// Code for sfto_dcontentf1

static LispObject CC_sfto_dcontentf1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0114, v0095, v0121;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dcontentf1");
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
    v0095 = v0000;
// end of prologue

v0112:
    v0121 = stack[0];
    v0114 = (LispObject)17; // 1
    if (v0121 == v0114) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0114 = v0095;
    if (!consp(v0114)) goto v0087;
    v0114 = v0095;
    v0114 = qcar(v0114);
    v0114 = (consp(v0114) ? nil : lisp_true);
    goto v0101;

v0101:
    if (v0114 == nil) goto v0096;
    v0114 = v0095;
    fn = elt(env, 2); // absf
    v0095 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-2];
    v0114 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // sfto_gcdf
        return (*qfn2(fn))(qenv(fn), v0095, v0114);
    }

v0096:
    v0114 = v0095;
    v0114 = qcdr(v0114);
    stack[-1] = v0114;
    v0114 = v0095;
    v0114 = qcar(v0114);
    v0095 = qcdr(v0114);
    v0114 = stack[0];
    v0114 = CC_sfto_dcontentf1(env, v0095, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-2];
    stack[0] = v0114;
    v0114 = stack[-1];
    v0095 = v0114;
    goto v0112;

v0087:
    v0114 = qvalue(elt(env, 1)); // t
    goto v0101;
// error exit handlers
v0107:
    popv(3);
    return nil;
}



// Code for quotfd

static LispObject CC_quotfd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0121, v0022, v0023, v0107;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0023 = v0001;
    v0107 = v0000;
// end of prologue
    v0022 = v0107;
    v0121 = v0023;
    if (equal(v0022, v0121)) goto v0091;
    v0121 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0121)) v0121 = nil;
    else { v0121 = qfastgets(v0121);
           if (v0121 != nil) { v0121 = elt(v0121, 3); // field
#ifdef RECORD_GET
             if (v0121 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0121 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0121 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0121 == SPID_NOPROP) v0121 = nil; else v0121 = lisp_true; }}
#endif
    if (v0121 == nil) goto v0075;
    v0121 = v0107;
    v0022 = v0023;
    {
        fn = elt(env, 3); // divd
        return (*qfn2(fn))(qenv(fn), v0121, v0022);
    }

v0075:
    v0121 = v0107;
    if (!consp(v0121)) goto v0028;
    v0121 = v0107;
    v0121 = qcar(v0121);
    v0121 = (consp(v0121) ? nil : lisp_true);
    goto v0027;

v0027:
    if (v0121 == nil) goto v0068;
    v0121 = v0107;
    v0022 = v0023;
    {
        fn = elt(env, 4); // quotdd
        return (*qfn2(fn))(qenv(fn), v0121, v0022);
    }

v0068:
    v0121 = v0107;
    v0022 = v0023;
    {
        fn = elt(env, 5); // quotk
        return (*qfn2(fn))(qenv(fn), v0121, v0022);
    }

v0028:
    v0121 = qvalue(elt(env, 2)); // t
    goto v0027;

v0091:
    v0121 = (LispObject)17; // 1
    return onevalue(v0121);
}



// Code for mk!*sq

static LispObject CC_mkHsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0020, v0078;
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
    v0020 = v0000;
// end of prologue
    fn = elt(env, 6); // expchk
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    stack[0] = v0020;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    if (v0020 == nil) goto v0029;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    if (!consp(v0020)) goto v0116;
    v0020 = qvalue(elt(env, 1)); // nil
    goto v0030;

v0030:
    if (v0020 == nil) goto v0119;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    { popv(3); return onevalue(v0020); }

v0119:
    v0020 = stack[0];
    fn = elt(env, 7); // kernp
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    if (v0020 == nil) goto v0023;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0078 = qcar(v0020);
    v0020 = elt(env, 2); // list
    if (!consp(v0078)) goto v0023;
    v0078 = qcar(v0078);
    if (!(v0078 == v0020)) goto v0023;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    { popv(3); return onevalue(v0020); }

v0023:
    stack[-1] = elt(env, 3); // !*sq
    v0020 = qvalue(elt(env, 4)); // !*resubs
    if (v0020 == nil) goto v0161;
    v0020 = qvalue(elt(env, 5)); // !*sqvar!*
    goto v0040;

v0040:
    {
        LispObject v0046 = stack[-1];
        LispObject v0061 = stack[0];
        popv(3);
        return list2star(v0046, v0061, v0020);
    }

v0161:
    v0020 = qvalue(elt(env, 1)); // nil
    v0020 = ncons(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0040;

v0116:
    v0020 = stack[0];
    v0078 = qcdr(v0020);
    v0020 = (LispObject)17; // 1
    v0020 = (v0078 == v0020 ? lisp_true : nil);
    goto v0030;

v0029:
    v0020 = (LispObject)1; // 0
    { popv(3); return onevalue(v0020); }
// error exit handlers
v0016:
    popv(3);
    return nil;
}



// Code for pnthxzz

static LispObject CC_pnthxzz(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0082, v0083, v0024, v0038;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pnthxzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0024 = v0001;
    v0038 = v0000;
// end of prologue

v0091:
    v0082 = v0024;
    if (v0082 == nil) goto v0113;
    v0082 = v0024;
    v0082 = qcar(v0082);
    v0083 = qcar(v0082);
    v0082 = v0038;
    v0082 = (equal(v0083, v0082) ? lisp_true : nil);
    goto v0112;

v0112:
    if (!(v0082 == nil)) return onevalue(v0024);
    v0082 = v0024;
    v0082 = qcdr(v0082);
    v0024 = v0082;
    goto v0091;

v0113:
    v0082 = qvalue(elt(env, 1)); // t
    goto v0112;
}



// Code for sqchk

static LispObject CC_sqchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0038, v0088, v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0070 = v0000;
// end of prologue
    v0038 = v0070;
    if (!consp(v0038)) return onevalue(v0070);
    v0038 = v0070;
    v0038 = qcar(v0038);
    if (!symbolp(v0038)) v0038 = nil;
    else { v0038 = qfastgets(v0038);
           if (v0038 != nil) { v0038 = elt(v0038, 44); // prepfn2
#ifdef RECORD_GET
             if (v0038 != SPID_NOPROP)
                record_get(elt(fastget_names, 44), 1);
             else record_get(elt(fastget_names, 44), 0),
                v0038 = nil; }
           else record_get(elt(fastget_names, 44), 0); }
#else
             if (v0038 == SPID_NOPROP) v0038 = nil; }}
#endif
    v0088 = v0038;
    v0038 = v0088;
    if (v0038 == nil) goto v0074;
    v0038 = v0088;
    v0088 = v0070;
        return Lapply1(nil, v0038, v0088);

v0074:
    v0038 = v0070;
    v0038 = qcar(v0038);
    if (!consp(v0038)) return onevalue(v0070);
    v0038 = v0070;
    {
        fn = elt(env, 1); // prepf
        return (*qfn1(fn))(qenv(fn), v0038);
    }
}



// Code for evtdeg

static LispObject CC_evtdeg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0036, v0063, v0092;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evtdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0063 = v0000;
// end of prologue
    v0036 = (LispObject)1; // 0
    goto v0073;

v0073:
    v0092 = v0063;
    if (v0092 == nil) return onevalue(v0036);
    v0092 = v0063;
    v0092 = qcar(v0092);
    v0036 = (LispObject)(int32_t)((int32_t)v0092 + (int32_t)v0036 - TAG_FIXNUM);
    v0063 = qcdr(v0063);
    goto v0073;
}



// Code for eolcheck

static LispObject CC_eolcheck(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0070, v0089;
    LispObject fn;
    argcheck(nargs, 0, "eolcheck");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for eolcheck");
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
    v0070 = qvalue(elt(env, 1)); // !*eoldelimp
    if (!(v0070 == nil)) goto v0075;
    v0070 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0070); }

v0075:
    v0089 = qvalue(elt(env, 3)); // nxtsym!*
    v0070 = qvalue(elt(env, 4)); // !$eol!$
    if (v0089 == v0070) goto v0092;
    v0070 = nil;
    { popv(1); return onevalue(v0070); }

v0092:
    v0089 = qvalue(elt(env, 5)); // cursym!*
    v0070 = elt(env, 6); // end
    if (v0089 == v0070) goto v0036;
    fn = elt(env, 8); // token
    v0070 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[0];
    goto v0084;

v0084:
    qvalue(elt(env, 3)) = v0070; // nxtsym!*
    goto v0075;

v0036:
    v0070 = elt(env, 7); // !;
    goto v0084;
// error exit handlers
v0037:
    popv(1);
    return nil;
}



// Code for !*ssave

static LispObject CC_Hssave(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0045, v0102, v0163;
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
    v0045 = qvalue(elt(env, 1)); // !*uncached
    if (!(v0045 == nil)) goto v0073;
    stack[-4] = qvalue(elt(env, 2)); // alglist!*
    v0102 = qvalue(elt(env, 3)); // !*sub2
    v0045 = stack[-3];
    v0102 = cons(v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0045 = qvalue(elt(env, 2)); // alglist!*
    v0045 = qcar(v0045);
    stack[-1] = v0102;
    stack[0] = v0045;
    v0045 = stack[0];
    if (v0045 == nil) goto v0024;
    v0102 = qvalue(elt(env, 5)); // alglist_count!*
    v0045 = qvalue(elt(env, 6)); // alglist_limit!*
    v0045 = (LispObject)greaterp2(v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0045 = v0045 ? lisp_true : nil;
    env = stack[-5];
    goto v0083;

v0083:
    if (v0045 == nil) goto v0020;
    v0045 = (LispObject)1; // 0
    qvalue(elt(env, 5)) = v0045; // alglist_count!*
    v0163 = (LispObject)161; // 10
    v0102 = (LispObject)49; // 3
    v0045 = elt(env, 7); // 2.0
    fn = elt(env, 9); // mkhash
    v0045 = (*qfnn(fn))(qenv(fn), 3, v0163, v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[0] = v0045;
    v0163 = stack[-2];
    v0102 = stack[0];
    v0045 = stack[-1];
    fn = elt(env, 10); // puthash
    v0045 = (*qfnn(fn))(qenv(fn), 3, v0163, v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0045 = stack[0];
    goto v0085;

v0085:
    v0045 = Lrplaca(nil, stack[-4], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0073;

v0073:
    v0045 = qvalue(elt(env, 8)); // simpcount!*
    v0045 = sub1(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    qvalue(elt(env, 8)) = v0045; // simpcount!*
    { LispObject res = stack[-3]; popv(6); return onevalue(res); }

v0020:
    v0163 = stack[-2];
    v0102 = stack[0];
    v0045 = stack[-1];
    fn = elt(env, 10); // puthash
    v0045 = (*qfnn(fn))(qenv(fn), 3, v0163, v0102, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0045 = qvalue(elt(env, 5)); // alglist_count!*
    v0045 = add1(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    qvalue(elt(env, 5)) = v0045; // alglist_count!*
    v0045 = stack[0];
    goto v0085;

v0024:
    v0045 = qvalue(elt(env, 4)); // t
    goto v0083;
// error exit handlers
v0131:
    popv(6);
    return nil;
}



// Code for red!-weight

static LispObject CC_redKweight(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0125, v0116;
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
    v0125 = stack[-1];
    fn = elt(env, 1); // nonzero!-length
    stack[-2] = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    v0116 = stack[-1];
    v0125 = stack[0];
    fn = elt(env, 2); // red!-weight1
    v0125 = (*qfn2(fn))(qenv(fn), v0116, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    {
        LispObject v0036 = stack[-2];
        popv(4);
        return cons(v0036, v0125);
    }
// error exit handlers
v0084:
    popv(4);
    return nil;
}



// Code for bc!=simp

static LispObject CC_bcMsimp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0080, v0126;
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
    v0080 = elt(env, 1); // cali
    if (!symbolp(v0080)) v0080 = nil;
    else { v0080 = qfastgets(v0080);
           if (v0080 != nil) { v0080 = elt(v0080, 20); // rules
#ifdef RECORD_GET
             if (v0080 != SPID_NOPROP)
                record_get(elt(fastget_names, 20), 1);
             else record_get(elt(fastget_names, 20), 0),
                v0080 = nil; }
           else record_get(elt(fastget_names, 20), 0); }
#else
             if (v0080 == SPID_NOPROP) v0080 = nil; }}
#endif
    stack[-4] = v0080;
    v0080 = stack[-4];
    if (v0080 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0080 = (LispObject)1; // 0
    stack[0] = v0080;
    v0080 = stack[-4];
    stack[-2] = v0080;
    goto v0116;

v0116:
    v0080 = stack[-2];
    if (v0080 == nil) goto v0062;
    v0126 = stack[0];
    v0080 = (LispObject)16001; // 1000
    v0080 = (LispObject)lessp2(v0126, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0080 = v0080 ? lisp_true : nil;
    env = stack[-5];
    if (v0080 == nil) goto v0062;
    v0126 = stack[-3];
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    v0080 = qcar(v0080);
    fn = elt(env, 4); // qremf
    v0080 = (*qfn2(fn))(qenv(fn), v0126, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    stack[-1] = v0080;
    v0080 = stack[-1];
    v0080 = qcar(v0080);
    if (v0080 == nil) goto v0103;
    v0080 = stack[-1];
    v0126 = qcar(v0080);
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    v0080 = qcdr(v0080);
    fn = elt(env, 5); // multf
    v0126 = (*qfn2(fn))(qenv(fn), v0126, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    fn = elt(env, 6); // addf
    v0080 = (*qfn2(fn))(qenv(fn), v0126, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    stack[-3] = v0080;
    v0080 = stack[0];
    v0080 = add1(v0080);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    stack[0] = v0080;
    v0080 = stack[-4];
    stack[-2] = v0080;
    goto v0116;

v0103:
    v0080 = stack[-2];
    v0080 = qcdr(v0080);
    stack[-2] = v0080;
    goto v0116;

v0062:
    v0126 = stack[0];
    v0080 = (LispObject)16001; // 1000
    v0080 = (LispObject)lessp2(v0126, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0080 = v0080 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0080 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0080 = elt(env, 3); // "recursion depth of bc!=simp too high"
    fn = elt(env, 7); // rederr
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0080 = nil;
    { popv(6); return onevalue(v0080); }
// error exit handlers
v0134:
    popv(6);
    return nil;
}



// Code for pv_sort2a

static LispObject CC_pv_sort2a(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0129, v0134;
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

v0091:
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    if (v0129 == nil) goto v0074;
    v0129 = stack[-1];
    v0134 = qcdr(v0129);
    v0129 = stack[0];
    v0129 = qcar(v0129);
    v0129 = qcdr(v0129);
    v0129 = (LispObject)greaterp2(v0134, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0129 = v0129 ? lisp_true : nil;
    env = stack[-3];
    if (v0129 == nil) goto v0047;
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    stack[0] = v0129;
    goto v0091;

v0047:
    v0129 = stack[0];
    v0134 = qcar(v0129);
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    v0129 = cons(v0134, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    stack[-2] = v0129;
    v0134 = stack[0];
    v0129 = stack[-1];
    v0134 = Lrplaca(nil, v0134, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0129 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0134, v0129);

v0074:
    v0129 = stack[-1];
    v0134 = qcdr(v0129);
    v0129 = stack[0];
    v0129 = qcar(v0129);
    v0129 = qcdr(v0129);
    v0129 = (LispObject)greaterp2(v0134, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0129 = v0129 ? lisp_true : nil;
    env = stack[-3];
    if (v0129 == nil) goto v0089;
    v0129 = stack[-1];
    v0129 = ncons(v0129);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    {
        LispObject v0146 = stack[0];
        popv(4);
        return Lrplacd(nil, v0146, v0129);
    }

v0089:
    v0129 = stack[0];
    v0134 = qcar(v0129);
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    v0129 = cons(v0134, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    stack[-2] = v0129;
    v0134 = stack[0];
    v0129 = stack[-1];
    v0134 = Lrplaca(nil, v0134, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0129 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0134, v0129);
// error exit handlers
v0013:
    popv(4);
    return nil;
}



// Code for minus!-mod!-p

static LispObject CC_minusKmodKp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0079, v0114;
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
    goto v0091;

v0091:
    v0079 = stack[-1];
    if (v0079 == nil) goto v0035;
    v0079 = stack[-1];
    if (!consp(v0079)) goto v0074;
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = (consp(v0079) ? nil : lisp_true);
    goto v0075;

v0075:
    if (v0079 == nil) goto v0070;
    v0114 = stack[-2];
    v0079 = stack[-1];
    {   int32_t w = int_of_fixnum(v0079);
        if (w != 0) w = current_modulus - w;
        v0079 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0114, v0079);
    }

v0070:
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    stack[0] = qcar(v0079);
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0114 = CC_minusKmodKp(env, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    v0079 = stack[-2];
    v0079 = acons(stack[0], v0114, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    stack[-2] = v0079;
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0091;

v0074:
    v0079 = qvalue(elt(env, 1)); // t
    goto v0075;

v0035:
    v0079 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0079);
    }
// error exit handlers
v0023:
    popv(4);
    return nil;
}



// Code for mcharg1

static LispObject CC_mcharg1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0007, v0049, v0140;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mcharg1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mcharg1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0058;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0007 = stack[-3];
    if (v0007 == nil) goto v0093;
    v0007 = qvalue(elt(env, 1)); // nil
    goto v0034;

v0034:
    if (v0007 == nil) goto v0116;
    v0007 = qvalue(elt(env, 1)); // nil
    popv(6);
    return ncons(v0007);

v0116:
    v0007 = stack[-3];
    v0007 = Llength(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-5];
    stack[-4] = v0007;
    v0007 = stack[-2];
    v0007 = Llength(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-5];
    stack[0] = v0007;
    v0007 = stack[-1];
    if (!symbolp(v0007)) v0007 = nil;
    else { v0007 = qfastgets(v0007);
           if (v0007 != nil) { v0007 = elt(v0007, 35); // nary
#ifdef RECORD_GET
             if (v0007 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v0007 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v0007 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v0007 == SPID_NOPROP) v0007 = nil; else v0007 = lisp_true; }}
#endif
    if (v0007 == nil) goto v0069;
    v0049 = stack[-4];
    v0007 = (LispObject)33; // 2
    v0007 = (LispObject)greaterp2(v0049, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    v0007 = v0007 ? lisp_true : nil;
    env = stack[-5];
    goto v0088;

v0088:
    if (v0007 == nil) goto v0128;
    v0049 = stack[-4];
    v0007 = qvalue(elt(env, 2)); // matchlength!*
    v0007 = (LispObject)lesseq2(v0049, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    v0007 = v0007 ? lisp_true : nil;
    env = stack[-5];
    if (v0007 == nil) goto v0047;
    v0007 = stack[-1];
    if (!symbolp(v0007)) v0007 = nil;
    else { v0007 = qfastgets(v0007);
           if (v0007 != nil) { v0007 = elt(v0007, 43); // symmetric
#ifdef RECORD_GET
             if (v0007 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v0007 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v0007 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v0007 == SPID_NOPROP) v0007 = nil; else v0007 = lisp_true; }}
#endif
    if (v0007 == nil) goto v0047;
    v0140 = stack[-3];
    v0049 = stack[-2];
    v0007 = stack[-1];
    {
        popv(6);
        fn = elt(env, 3); // mchcomb
        return (*qfnn(fn))(qenv(fn), 3, v0140, v0049, v0007);
    }

v0047:
    v0049 = stack[0];
    v0007 = (LispObject)33; // 2
    if (v0049 == v0007) goto v0127;
    v0007 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0007); }

v0127:
    v0049 = stack[-1];
    v0007 = stack[-3];
    fn = elt(env, 4); // mkbin
    v0007 = (*qfn2(fn))(qenv(fn), v0049, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-5];
    v0007 = qcdr(v0007);
    stack[-3] = v0007;
    v0007 = (LispObject)33; // 2
    stack[-4] = v0007;
    goto v0128;

v0128:
    v0049 = stack[-4];
    v0007 = stack[0];
    if (equal(v0049, v0007)) goto v0130;
    v0007 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0007); }

v0130:
    v0007 = stack[-1];
    if (!symbolp(v0007)) v0007 = nil;
    else { v0007 = qfastgets(v0007);
           if (v0007 != nil) { v0007 = elt(v0007, 43); // symmetric
#ifdef RECORD_GET
             if (v0007 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v0007 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v0007 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v0007 == SPID_NOPROP) v0007 = nil; else v0007 = lisp_true; }}
#endif
    if (v0007 == nil) goto v0169;
    v0140 = stack[-3];
    v0049 = stack[-2];
    v0007 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); // mchsarg
        return (*qfnn(fn))(qenv(fn), 3, v0140, v0049, v0007);
    }

v0169:
    v0007 = stack[-2];
    fn = elt(env, 6); // mtp
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-5];
    if (v0007 == nil) goto v0142;
    v0049 = stack[-2];
    v0007 = stack[-3];
    fn = elt(env, 7); // pair
    v0007 = (*qfn2(fn))(qenv(fn), v0049, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    popv(6);
    return ncons(v0007);

v0142:
    stack[0] = stack[-3];
    v0007 = qvalue(elt(env, 1)); // nil
    v0049 = ncons(v0007);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-5];
    v0007 = stack[-1];
    {
        LispObject v0052 = stack[0];
        LispObject v0148 = stack[-2];
        popv(6);
        fn = elt(env, 8); // mcharg2
        return (*qfnn(fn))(qenv(fn), 4, v0052, v0148, v0049, v0007);
    }

v0069:
    v0007 = qvalue(elt(env, 1)); // nil
    goto v0088;

v0093:
    v0007 = stack[-2];
    v0007 = (v0007 == nil ? lisp_true : nil);
    goto v0034;
// error exit handlers
v0054:
    popv(6);
    return nil;
}



// Code for quotf!-fail

static LispObject CC_quotfKfail(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0047, v0016, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotf-fail");
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
    v0047 = stack[-2];
    if (v0047 == nil) goto v0091;
    v0016 = stack[-2];
    v0047 = stack[-1];
    fn = elt(env, 6); // quotf
    v0047 = (*qfn2(fn))(qenv(fn), v0016, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    v0016 = v0047;
    v0047 = v0016;
    if (v0047 == nil) goto v0098;
    v0047 = qvalue(elt(env, 1)); // nil
    goto v0092;

v0092:
    if (v0047 == nil) goto v0087;
    v0047 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 3)); // !*roundall
    qvalue(elt(env, 3)) = v0047; // !*roundall
    v0016 = stack[-2];
    v0047 = stack[-1];
    fn = elt(env, 6); // quotf
    v0047 = (*qfn2(fn))(qenv(fn), v0016, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-4];
    v0016 = v0047;
    qvalue(elt(env, 3)) = stack[0]; // !*roundall
    goto v0087;

v0087:
    v0047 = v0016;
    if (!(v0047 == nil)) { popv(5); return onevalue(v0016); }
    stack[-3] = elt(env, 4); // poly
    stack[0] = (LispObject)1585; // 99
    v0046 = elt(env, 5); // "UNEXPECTED DIVISION FAILURE"
    v0016 = stack[-2];
    v0047 = stack[-1];
    v0047 = list3(v0046, v0016, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-4];
    fn = elt(env, 7); // rerror
    v0047 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0047 = nil;
    { popv(5); return onevalue(v0047); }

v0098:
    v0047 = qvalue(elt(env, 2)); // !*rounded
    if (v0047 == nil) goto v0082;
    v0047 = qvalue(elt(env, 3)); // !*roundall
    goto v0092;

v0082:
    v0047 = qvalue(elt(env, 1)); // nil
    goto v0092;

v0091:
    v0047 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0047); }
// error exit handlers
v0127:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[0]; // !*roundall
    popv(5);
    return nil;
v0076:
    popv(5);
    return nil;
}



// Code for mri_0mk2

static LispObject CC_mri_0mk2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0124, v0125, v0116, v0086;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mri_0mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0116 = v0058;
    v0124 = v0001;
    v0125 = v0000;
// end of prologue
    v0086 = qvalue(elt(env, 1)); // nil
    return list4(v0125, v0124, v0086, v0116);
}



// Code for qqe_id!-nyt!-branchb

static LispObject CC_qqe_idKnytKbranchb(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchb");
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
    v0063 = stack[0];
    if (!consp(v0063)) goto v0115;
    v0063 = stack[0];
    v0063 = qcar(v0063);
    fn = elt(env, 1); // qqe_qopaddp
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-1];
    if (!(v0063 == nil)) goto v0074;
    v0063 = stack[0];
    v0063 = qcar(v0063);
    fn = elt(env, 2); // qqe_qoptailp
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    goto v0074;

v0074:
    v0063 = (v0063 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0063); }

v0115:
    v0063 = stack[0];
    fn = elt(env, 3); // qqe_btidp
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-1];
    if (!(v0063 == nil)) { popv(2); return onevalue(v0063); }
    v0063 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // qqe_nytidp
        return (*qfn1(fn))(qenv(fn), v0063);
    }
// error exit handlers
v0098:
    popv(2);
    return nil;
}



// Code for gcdf

static LispObject CC_gcdf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0130, v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf");
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
    stack[-4] = qvalue(elt(env, 1)); // !*exp
    qvalue(elt(env, 1)) = nil; // !*exp
    stack[-1] = qvalue(elt(env, 2)); // !*rounded
    qvalue(elt(env, 2)) = nil; // !*rounded
    v0130 = qvalue(elt(env, 3)); // !*mcd
    stack[0] = v0130;
    v0130 = qvalue(elt(env, 4)); // t
    qvalue(elt(env, 1)) = v0130; // !*exp
    v0130 = stack[-3];
    if (!consp(v0130)) goto v0116;
    v0130 = stack[-3];
    v0130 = qcar(v0130);
    v0130 = (consp(v0130) ? nil : lisp_true);
    goto v0125;

v0125:
    if (v0130 == nil) goto v0027;
    v0130 = qvalue(elt(env, 4)); // t
    goto v0030;

v0030:
    if (v0130 == nil) goto v0062;
    v0130 = qvalue(elt(env, 7)); // !*combineexpt
    if (v0130 == nil) goto v0117;
    v0130 = qvalue(elt(env, 4)); // t
    qvalue(elt(env, 3)) = v0130; // !*mcd
    goto v0117;

v0117:
    v0128 = stack[-3];
    v0130 = stack[-2];
    fn = elt(env, 8); // gcdf1
    v0130 = (*qfn2(fn))(qenv(fn), v0128, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-5];
    goto v0112;

v0112:
    stack[-3] = v0130;
    v0130 = stack[0];
    qvalue(elt(env, 3)) = v0130; // !*mcd
    v0130 = stack[-3];
    fn = elt(env, 9); // minusf
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-5];
    if (v0130 == nil) goto v0126;
    v0130 = stack[-3];
    fn = elt(env, 10); // negf
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-5];
    goto v0029;

v0029:
    qvalue(elt(env, 2)) = stack[-1]; // !*rounded
    qvalue(elt(env, 1)) = stack[-4]; // !*exp
    { popv(6); return onevalue(v0130); }

v0126:
    v0130 = stack[-3];
    goto v0029;

v0062:
    v0128 = stack[-3];
    v0130 = stack[-2];
    fn = elt(env, 11); // ezgcdf
    v0130 = (*qfn2(fn))(qenv(fn), v0128, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-5];
    goto v0112;

v0027:
    v0130 = stack[-2];
    if (!consp(v0130)) goto v0070;
    v0130 = stack[-2];
    v0130 = qcar(v0130);
    v0130 = (consp(v0130) ? nil : lisp_true);
    goto v0088;

v0088:
    if (v0130 == nil) goto v0120;
    v0130 = qvalue(elt(env, 4)); // t
    goto v0030;

v0120:
    v0130 = qvalue(elt(env, 5)); // !*ezgcd
    if (v0130 == nil) goto v0067;
    v0130 = qvalue(elt(env, 6)); // dmode!*
    if (!(v0130 == nil)) goto v0030;
    v0130 = stack[-3];
    fn = elt(env, 12); // free!-powerp
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-5];
    if (!(v0130 == nil)) goto v0030;
    v0130 = stack[-2];
    fn = elt(env, 12); // free!-powerp
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-5];
    goto v0030;

v0067:
    v0130 = qvalue(elt(env, 4)); // t
    goto v0030;

v0070:
    v0130 = qvalue(elt(env, 4)); // t
    goto v0088;

v0116:
    v0130 = qvalue(elt(env, 4)); // t
    goto v0125;
// error exit handlers
v0013:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-1]; // !*rounded
    qvalue(elt(env, 1)) = stack[-4]; // !*exp
    popv(6);
    return nil;
}



// Code for find

static LispObject CC_find(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0025, v0026, v0104, v0120;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0026 = v0001;
    v0104 = v0000;
// end of prologue

v0034:
    v0120 = v0026;
    v0025 = nil;
    if (v0120 == v0025) goto v0029;
    v0025 = v0026;
    v0025 = qcar(v0025);
    v0104 = Lmember(nil, v0025, v0104);
    v0025 = v0026;
    v0025 = qcdr(v0025);
    v0026 = v0025;
    goto v0034;

v0029:
    v0025 = v0104;
    if (v0025 == nil) goto v0087;
    v0025 = v0104;
    v0025 = qcdr(v0025);
    return onevalue(v0025);

v0087:
    v0025 = elt(env, 1); // (stop)
    return onevalue(v0025);
}



// Code for comm_kernels

static LispObject CC_comm_kernels(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0093, v0112;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comm_kernels");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0093 = v0000;
// end of prologue
    v0112 = v0093;
    v0093 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // comm_kernels1
        return (*qfn2(fn))(qenv(fn), v0112, v0093);
    }
}



// Code for atomf

static LispObject CC_atomf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0119, v0085;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for atomf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0085 = v0000;
// end of prologue
    v0119 = v0085;
    if (!consp(v0119)) goto v0115;
    v0119 = v0085;
    v0119 = qcar(v0119);
    if (!symbolp(v0119)) v0119 = nil;
    else { v0119 = qfastgets(v0119);
           if (v0119 != nil) { v0119 = elt(v0119, 16); // indexvar
#ifdef RECORD_GET
             if (v0119 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0119 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0119 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0119 == SPID_NOPROP) v0119 = nil; else v0119 = lisp_true; }}
#endif
    return onevalue(v0119);

v0115:
    v0119 = qvalue(elt(env, 1)); // t
    return onevalue(v0119);
}



// Code for make!-set

static LispObject CC_makeKset(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0112, v0113;
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
    v0112 = v0000;
// end of prologue
    v0113 = v0112;
    v0112 = elt(env, 1); // set!-ordp
    fn = elt(env, 2); // sort
    v0112 = (*qfn2(fn))(qenv(fn), v0113, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // makelist
        return (*qfn1(fn))(qenv(fn), v0112);
    }
// error exit handlers
v0119:
    popv(1);
    return nil;
}



// Code for algid

static LispObject CC_algid(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0084, v0036, v0063;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for algid");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0084 = v0001;
    v0036 = v0000;
// end of prologue
    v0063 = v0036;
    v0084 = Latsoc(nil, v0063, v0084);
    if (!(v0084 == nil)) return onevalue(v0036);
    v0084 = v0036;
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 17); // share
#ifdef RECORD_GET
             if (v0084 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0084 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0084 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; else v0084 = lisp_true; }}
#endif
    if (!(v0084 == nil)) return onevalue(v0036);
    v0084 = v0036;
        return Lmkquote(nil, v0084);
}



// Code for csl_timbf

static LispObject CC_csl_timbf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0110, v0133, v0145;
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
    v0110 = stack[-3];
    v0110 = qcdr(v0110);
    v0133 = qcar(v0110);
    v0110 = stack[-2];
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    v0110 = times2(v0133, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-5];
    v0145 = v0110;
    v0133 = v0145;
    v0110 = (LispObject)1; // 0
    if (v0133 == v0110) goto v0116;
    v0133 = v0145;
    v0110 = qvalue(elt(env, 2)); // !:bprec!:
    fn = elt(env, 4); // inorm
    v0110 = (*qfn2(fn))(qenv(fn), v0133, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-5];
    v0145 = v0110;
    stack[-4] = elt(env, 3); // !:rd!:
    v0110 = v0145;
    stack[-1] = qcar(v0110);
    v0110 = v0145;
    stack[0] = qcdr(v0110);
    v0110 = stack[-3];
    v0110 = qcdr(v0110);
    v0133 = qcdr(v0110);
    v0110 = stack[-2];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = plus2(v0133, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-5];
    v0110 = plus2(stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    {
        LispObject v0019 = stack[-4];
        LispObject v0020 = stack[-1];
        popv(6);
        return list2star(v0019, v0020, v0110);
    }

v0116:
    v0110 = elt(env, 1); // (!:rd!: 0 . 0)
    { popv(6); return onevalue(v0110); }
// error exit handlers
v0118:
    popv(6);
    return nil;
}



// Code for !:plus

static LispObject CC_Tplus(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0021, v0018, v0042;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :plus");
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
    v0018 = v0001;
    v0042 = v0000;
// end of prologue
    v0021 = v0042;
    if (v0021 == nil) { popv(1); return onevalue(v0018); }
    v0021 = v0018;
    if (v0021 == nil) { popv(1); return onevalue(v0042); }
    v0021 = v0042;
    if (!consp(v0021)) goto v0074;
    v0021 = qvalue(elt(env, 1)); // nil
    goto v0075;

v0075:
    if (v0021 == nil) goto v0114;
    v0021 = v0042;
    v0021 = plus2(v0021, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[0];
    v0042 = v0021;
    v0018 = v0042;
    v0021 = (LispObject)1; // 0
    if (!(v0018 == v0021)) { popv(1); return onevalue(v0042); }
    v0021 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0021); }

v0114:
    v0021 = elt(env, 2); // plus
    {
        popv(1);
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0042, v0018, v0021);
    }

v0074:
    v0021 = v0018;
    v0021 = (consp(v0021) ? nil : lisp_true);
    goto v0075;
// error exit handlers
v0040:
    popv(1);
    return nil;
}



// Code for macrochk

static LispObject CC_macrochk(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0064, v0065, v0161, v0117;
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
    v0064 = stack[-1];
    if (!consp(v0064)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0064 = stack[-1];
    v0064 = qcar(v0064);
    fn = elt(env, 5); // expdrmacro
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0065 = v0064;
    if (v0064 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0161 = stack[0];
    v0064 = elt(env, 1); // symbolic
    if (v0161 == v0064) goto v0086;
    v0064 = stack[-1];
    v0064 = qcar(v0064);
    if (symbolp(v0064)) goto v0037;
    v0064 = qvalue(elt(env, 3)); // nil
    goto v0116;

v0116:
    if (v0064 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0064 = v0065;
    v0161 = qcar(v0064);
    v0064 = elt(env, 4); // macrofn
    v0117 = get(v0161, v0064);
    v0064 = v0065;
    v0161 = qcdr(v0064);
    v0064 = stack[-1];
    v0065 = qcdr(v0064);
    v0064 = stack[-1];
    v0064 = qcar(v0064);
        popv(3);
        return Lapply3(nil, 4, v0117, v0161, v0065, v0064);

v0037:
    v0064 = stack[-1];
    v0064 = qcar(v0064);
    if (!symbolp(v0064)) v0064 = nil;
    else { v0064 = qfastgets(v0064);
           if (v0064 != nil) { v0064 = elt(v0064, 59); // opfn
#ifdef RECORD_GET
             if (v0064 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0064 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0064 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0064 == SPID_NOPROP) v0064 = nil; else v0064 = lisp_true; }}
#endif
    goto v0116;

v0086:
    v0064 = qvalue(elt(env, 2)); // t
    goto v0116;
// error exit handlers
v0020:
    popv(3);
    return nil;
}



// Code for getel

static LispObject CC_getel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0079, v0114, v0095;
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
    v0079 = stack[-1];
    v0114 = qcar(v0079);
    v0079 = elt(env, 1); // dimension
    v0079 = get(v0114, v0079);
    env = stack[-3];
    stack[-2] = v0079;
    v0079 = stack[-2];
    stack[0] = Llength(nil, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    v0079 = Llength(nil, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    if (equal(stack[0], v0079)) goto v0037;
    v0095 = elt(env, 2); // rlisp
    v0114 = (LispObject)337; // 21
    v0079 = elt(env, 3); // "Incorrect array reference"
    {
        popv(4);
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0095, v0114, v0079);
    }

v0037:
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    if (!symbolp(v0079)) v0079 = nil;
    else { v0079 = qfastgets(v0079);
           if (v0079 != nil) { v0079 = elt(v0079, 4); // avalue
#ifdef RECORD_GET
             if (v0079 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0079 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; }}
#endif
    v0079 = qcdr(v0079);
    v0095 = qcar(v0079);
    v0079 = stack[-1];
    v0114 = qcdr(v0079);
    v0079 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); // getel1
        return (*qfnn(fn))(qenv(fn), 3, v0095, v0114, v0079);
    }
// error exit handlers
v0107:
    popv(4);
    return nil;
}



// Code for mo!=lexcomp

static LispObject CC_moMlexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0039, v0079, v0114, v0095;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=lexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0079 = v0001;
    v0114 = v0000;
// end of prologue

v0091:
    v0039 = v0114;
    if (v0039 == nil) goto v0035;
    v0039 = v0079;
    if (v0039 == nil) goto v0116;
    v0039 = v0114;
    v0095 = qcar(v0039);
    v0039 = v0079;
    v0039 = qcar(v0039);
    if (equal(v0095, v0039)) goto v0084;
    v0039 = v0114;
    v0039 = qcar(v0039);
    v0079 = qcar(v0079);
    if (((int32_t)(v0039)) > ((int32_t)(v0079))) goto v0089;
    v0039 = (LispObject)-15; // -1
    return onevalue(v0039);

v0089:
    v0039 = (LispObject)17; // 1
    return onevalue(v0039);

v0084:
    v0039 = v0114;
    v0039 = qcdr(v0039);
    v0114 = v0039;
    v0039 = v0079;
    v0039 = qcdr(v0039);
    v0079 = v0039;
    goto v0091;

v0116:
    v0039 = elt(env, 1); // (0)
    v0079 = v0039;
    goto v0091;

v0035:
    v0039 = v0079;
    if (v0039 == nil) goto v0119;
    v0039 = elt(env, 1); // (0)
    v0114 = v0039;
    goto v0091;

v0119:
    v0039 = (LispObject)1; // 0
    return onevalue(v0039);
}



// Code for resimp1

static LispObject CC_resimp1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027, v0028;
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
    v0027 = stack[0];
    v0028 = qcar(v0027);
    v0027 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 4); // subf1
    stack[-1] = (*qfn2(fn))(qenv(fn), v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-2];
    v0027 = stack[0];
    v0028 = qcdr(v0027);
    v0027 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 4); // subf1
    v0027 = (*qfn2(fn))(qenv(fn), v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-2];
    fn = elt(env, 5); // quotsq
    v0027 = (*qfn2(fn))(qenv(fn), stack[-1], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-2];
    stack[0] = v0027;
    v0027 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 3)) = v0027; // !*sub2
    { LispObject res = stack[0]; popv(3); return onevalue(res); }
// error exit handlers
v0083:
    popv(3);
    return nil;
}



// Code for gperm

static LispObject CC_gperm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0065, v0161;
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
    goto v0119;

v0119:
    v0161 = stack[0];
    v0065 = (LispObject)1; // 0
    v0065 = (LispObject)greaterp2(v0161, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    v0065 = v0065 ? lisp_true : nil;
    env = stack[-4];
    if (v0065 == nil) goto v0073;
    v0161 = stack[0];
    v0065 = stack[-1];
    v0065 = cons(v0161, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    stack[-1] = v0065;
    v0065 = stack[0];
    v0065 = sub1(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    stack[0] = v0065;
    goto v0119;

v0073:
    v0065 = stack[-1];
    fn = elt(env, 2); // gperm0
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    stack[-3] = v0065;
    v0065 = stack[-3];
    if (v0065 == nil) goto v0096;
    v0065 = stack[-3];
    v0065 = qcar(v0065);
    fn = elt(env, 3); // pkp
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    stack[-1] = v0065;
    stack[-2] = v0065;
    goto v0038;

v0038:
    v0065 = stack[-3];
    v0065 = qcdr(v0065);
    stack[-3] = v0065;
    v0065 = stack[-3];
    if (v0065 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0065 = stack[-3];
    v0065 = qcar(v0065);
    fn = elt(env, 3); // pkp
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    v0065 = Lrplacd(nil, stack[0], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    stack[-1] = v0065;
    goto v0038;

v0096:
    v0065 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0065); }
// error exit handlers
v0078:
    popv(5);
    return nil;
}



// Code for copy

static LispObject CC_copy(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0082, v0083;
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
    goto v0091;

v0091:
    v0082 = stack[0];
    if (!consp(v0082)) goto v0113;
    v0082 = stack[0];
    v0082 = qcar(v0082);
    v0083 = CC_copy(env, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0082 = stack[-1];
    v0082 = cons(v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    stack[-1] = v0082;
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    stack[0] = v0082;
    goto v0091;

v0113:
    v0083 = stack[-1];
    v0082 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0083, v0082);
    }
// error exit handlers
v0088:
    popv(3);
    return nil;
}



// Code for ofsf_posdefp

static LispObject CC_ofsf_posdefp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0119, v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_posdefp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0085 = v0000;
// end of prologue
    v0119 = qvalue(elt(env, 1)); // !*rlpos
    if (v0119 == nil) goto v0034;
    v0119 = v0085;
    {
        fn = elt(env, 2); // ofsf_posdefp!-pos
        return (*qfn1(fn))(qenv(fn), v0119);
    }

v0034:
    v0119 = v0085;
    {
        fn = elt(env, 3); // sfto_tsqsumf
        return (*qfn1(fn))(qenv(fn), v0119);
    }
}



// Code for kernord

static LispObject CC_kernord(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0087, v0084;
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
    v0087 = v0001;
    stack[0] = v0000;
// end of prologue
    v0084 = stack[0];
    fn = elt(env, 1); // kernord!-split
    v0087 = (*qfn2(fn))(qenv(fn), v0084, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    stack[0] = v0087;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    fn = elt(env, 2); // kernord!-sort
    stack[-1] = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    fn = elt(env, 2); // kernord!-sort
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    {
        LispObject v0098 = stack[-1];
        popv(3);
        return Lappend(nil, v0098, v0087);
    }
// error exit handlers
v0092:
    popv(3);
    return nil;
}



// Code for powers2

static LispObject CC_powers2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0109, v0147, v0110;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "powers2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0029:
    v0109 = stack[-2];
    if (!consp(v0109)) goto v0085;
    v0109 = stack[-2];
    v0109 = qcar(v0109);
    v0109 = (consp(v0109) ? nil : lisp_true);
    goto v0119;

v0119:
    if (v0109 == nil) goto v0089;
    v0109 = stack[-2];
    if (v0109 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0147 = stack[0];
    v0109 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); // powers4
        return (*qfn2(fn))(qenv(fn), v0147, v0109);
    }

v0089:
    v0109 = stack[-2];
    v0109 = qcar(v0109);
    v0109 = qcdr(v0109);
    stack[-3] = v0109;
    v0109 = stack[-2];
    v0110 = qcdr(v0109);
    v0147 = stack[-1];
    v0109 = stack[0];
    v0109 = CC_powers2(env, 3, v0110, v0147, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-4];
    stack[-1] = v0109;
    v0109 = stack[-2];
    v0109 = qcar(v0109);
    v0147 = qcar(v0109);
    v0109 = stack[0];
    v0109 = cons(v0147, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-4];
    stack[0] = v0109;
    v0109 = stack[-3];
    stack[-2] = v0109;
    goto v0029;

v0085:
    v0109 = qvalue(elt(env, 1)); // t
    goto v0119;
// error exit handlers
v0065:
    popv(5);
    return nil;
}



// Code for subscriptedvarp

static LispObject CC_subscriptedvarp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0111, v0027;
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
    v0027 = qvalue(elt(env, 1)); // nil
    v0111 = stack[0];
    fn = elt(env, 3); // symtabget
    v0111 = (*qfn2(fn))(qenv(fn), v0027, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    v0027 = Llength(nil, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    v0111 = (LispObject)33; // 2
    v0111 = (LispObject)greaterp2(v0027, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0111 = v0111 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0111 == nil)) { popv(2); return onevalue(v0111); }
    v0111 = stack[0];
    v0027 = elt(env, 2); // subscripted
        popv(2);
        return Lflagp(nil, v0111, v0027);
// error exit handlers
v0090:
    popv(2);
    return nil;
}



// Code for prepd

static LispObject CC_prepd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0170, v0047;
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
    v0170 = stack[0];
    if (!consp(v0170)) goto v0113;
    v0170 = stack[0];
    v0170 = qcar(v0170);
    if (!symbolp(v0170)) v0047 = nil;
    else { v0047 = qfastgets(v0170);
           if (v0047 != nil) { v0047 = elt(v0047, 30); // minusp
#ifdef RECORD_GET
             if (v0047 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0047 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0047 == SPID_NOPROP) v0047 = nil; }}
#endif
    v0170 = stack[0];
    v0170 = Lapply1(nil, v0047, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    if (v0170 == nil) goto v0094;
    v0170 = stack[0];
    fn = elt(env, 3); // !:minus
    v0170 = (*qfn1(fn))(qenv(fn), v0170);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    fn = elt(env, 4); // prepd1
    v0170 = (*qfn1(fn))(qenv(fn), v0170);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-2];
    v0047 = v0170;
    v0170 = v0047;
    if (v0170 == nil) goto v0103;
    v0170 = elt(env, 1); // minus
    popv(3);
    return list2(v0170, v0047);

v0103:
    v0170 = (LispObject)1; // 0
    { popv(3); return onevalue(v0170); }

v0094:
    v0170 = stack[0];
    v0047 = qcar(v0170);
    v0170 = elt(env, 2); // prepfn
    v0047 = get(v0047, v0170);
    v0170 = stack[0];
        popv(3);
        return Lapply1(nil, v0047, v0170);

v0113:
    v0047 = stack[0];
    v0170 = (LispObject)1; // 0
    v0170 = (LispObject)lessp2(v0047, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    v0170 = v0170 ? lisp_true : nil;
    env = stack[-2];
    if (v0170 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); // minus
    v0170 = stack[0];
    v0170 = negate(v0170);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    {
        LispObject v0062 = stack[-1];
        popv(3);
        return list2(v0062, v0170);
    }
// error exit handlers
v0061:
    popv(3);
    return nil;
}



// Code for exptchk

static LispObject CC_exptchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0040, v0066;
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
    v0042 = stack[0];
    if (!consp(v0042)) goto v0035;
    v0042 = stack[0];
    v0042 = qcar(v0042);
    v0042 = (consp(v0042) ? nil : lisp_true);
    goto v0029;

v0029:
    if (v0042 == nil) goto v0036;
    v0040 = stack[0];
    v0042 = (LispObject)17; // 1
    popv(3);
    return cons(v0040, v0042);

v0036:
    v0042 = stack[0];
    fn = elt(env, 3); // comm_kernels
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    stack[-1] = v0042;
    v0042 = stack[-1];
    v0040 = Llength(nil, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    v0042 = (LispObject)33; // 2
    v0042 = (LispObject)lessp2(v0040, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0042 = v0042 ? lisp_true : nil;
    env = stack[-2];
    if (v0042 == nil) goto v0039;
    v0040 = stack[0];
    v0042 = (LispObject)17; // 1
    popv(3);
    return cons(v0040, v0042);

v0039:
    v0066 = stack[0];
    v0040 = qvalue(elt(env, 2)); // nil
    v0042 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); // exptchk0
        return (*qfnn(fn))(qenv(fn), 3, v0066, v0040, v0042);
    }

v0035:
    v0042 = qvalue(elt(env, 1)); // t
    goto v0029;
// error exit handlers
v0110:
    popv(3);
    return nil;
}



// Code for diplength

static LispObject CC_diplength(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0097;
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
    goto v0073;

v0073:
    v0108 = stack[0];
    if (v0108 == nil) goto v0029;
    v0097 = (LispObject)17; // 1
    v0108 = stack[-1];
    v0108 = cons(v0097, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-2];
    stack[-1] = v0108;
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    v0108 = qcdr(v0108);
    stack[0] = v0108;
    goto v0073;

v0029:
    v0108 = (LispObject)1; // 0
    v0097 = v0108;
    goto v0035;

v0035:
    v0108 = stack[-1];
    if (v0108 == nil) { popv(3); return onevalue(v0097); }
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = plus2(v0108, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-2];
    v0097 = v0108;
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[-1] = v0108;
    goto v0035;
// error exit handlers
v0104:
    popv(3);
    return nil;
}



// Code for boundindp

static LispObject CC_boundindp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0090, v0082, v0083, v0024;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for boundindp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0024 = v0001;
    v0083 = v0000;
// end of prologue

v0091:
    v0090 = v0083;
    if (v0090 == nil) goto v0035;
    v0090 = v0083;
    v0082 = qcar(v0090);
    v0090 = v0024;
    v0090 = Lmember(nil, v0082, v0090);
    if (v0090 == nil) goto v0111;
    v0090 = v0083;
    v0090 = qcdr(v0090);
    v0083 = v0090;
    goto v0091;

v0111:
    v0090 = qvalue(elt(env, 2)); // nil
    return onevalue(v0090);

v0035:
    v0090 = qvalue(elt(env, 1)); // t
    return onevalue(v0090);
}



// Code for chundexp

static LispObject CC_chundexp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0020, v0078;
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
    v0020 = stack[-1];
    v0020 = Lexplodec(nil, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    stack[-1] = v0020;
    v0020 = stack[-1];
    stack[-2] = v0020;
    v0078 = stack[-1];
    v0020 = elt(env, 1); // !_
    if (!consp(v0078)) goto v0098;
    v0078 = qcar(v0078);
    if (!(v0078 == v0020)) goto v0098;
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    goto v0030;

v0030:
    if (v0020 == nil) goto v0091;
    v0078 = elt(env, 3); // !\ (backslash)
    v0020 = stack[-1];
    v0020 = cons(v0078, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    stack[-1] = v0020;
    goto v0091;

v0091:
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    if (v0020 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    v0078 = qcar(v0020);
    v0020 = elt(env, 1); // !_
    if (!(v0078 == v0020)) goto v0026;
    stack[0] = stack[-2];
    v0078 = elt(env, 3); // !\ (backslash)
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    v0020 = cons(v0078, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    v0020 = Lrplacd(nil, stack[0], v0020);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    stack[-2] = v0020;
    goto v0026;

v0026:
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    stack[-2] = v0020;
    goto v0091;

v0098:
    v0020 = qvalue(elt(env, 2)); // nil
    goto v0030;
// error exit handlers
v0046:
    popv(4);
    return nil;
}



// Code for round!:mt

static LispObject CC_roundTmt(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0144, v0059;
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
    v0059 = stack[-2];
    v0144 = elt(env, 1); // !:rd!:
    if (!consp(v0059)) goto v0092;
    v0059 = qcar(v0059);
    if (!(v0059 == v0144)) goto v0092;
    v0144 = stack[-2];
    v0144 = qcdr(v0144);
    v0144 = (consp(v0144) ? nil : lisp_true);
    v0144 = (v0144 == nil ? lisp_true : nil);
    goto v0113;

v0113:
    if (v0144 == nil) goto v0104;
    v0144 = stack[-1];
    v0144 = integerp(v0144);
    if (v0144 == nil) goto v0090;
    v0059 = stack[-1];
    v0144 = (LispObject)1; // 0
    v0144 = (LispObject)greaterp2(v0059, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    v0144 = v0144 ? lisp_true : nil;
    env = stack[-4];
    goto v0035;

v0035:
    if (v0144 == nil) goto v0173;
    v0144 = stack[-2];
    v0144 = qcdr(v0144);
    v0144 = qcar(v0144);
    v0144 = Labsval(nil, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    fn = elt(env, 3); // msd
    v0059 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    v0144 = stack[-1];
    v0144 = difference2(v0059, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    v0059 = sub1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    stack[-1] = v0059;
    v0144 = (LispObject)1; // 0
    v0144 = (LispObject)lessp2(v0059, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    v0144 = v0144 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0144 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0059 = stack[-1];
    v0144 = (LispObject)1; // 0
    if (v0059 == v0144) goto v0161;
    stack[-3] = elt(env, 1); // !:rd!:
    v0144 = stack[-2];
    v0144 = qcdr(v0144);
    stack[0] = qcar(v0144);
    v0144 = stack[-1];
    v0144 = negate(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    fn = elt(env, 4); // ashift
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    v0144 = stack[-2];
    v0144 = qcdr(v0144);
    v0059 = qcdr(v0144);
    v0144 = stack[-1];
    v0144 = plus2(v0059, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    v0144 = list2star(stack[-3], stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); // round!:last
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0161:
    v0144 = stack[-2];
    {
        popv(5);
        fn = elt(env, 5); // round!:last
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0173:
    v0144 = elt(env, 0); // round!:mt
    {
        popv(5);
        fn = elt(env, 6); // bflerrmsg
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0090:
    v0144 = qvalue(elt(env, 2)); // nil
    goto v0035;

v0104:
    v0144 = qvalue(elt(env, 2)); // nil
    goto v0035;

v0092:
    v0144 = qvalue(elt(env, 2)); // nil
    goto v0113;
// error exit handlers
v0048:
    popv(5);
    return nil;
}



// Code for evaluate0

static LispObject CC_evaluate0(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0113, v0119;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate0");
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
    v0113 = v0000;
// end of prologue
    fn = elt(env, 1); // evaluate!-horner
    v0119 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0113 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // evaluate1
        return (*qfn2(fn))(qenv(fn), v0119, v0113);
    }
// error exit handlers
v0030:
    popv(2);
    return nil;
}



// Code for red!-char!-downcase

static LispObject CC_redKcharKdowncase(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086, v0101, v0087;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-char-downcase");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0101 = v0000;
// end of prologue
    v0086 = v0101;
    v0087 = qvalue(elt(env, 1)); // charassoc!*
    v0086 = Latsoc(nil, v0086, v0087);
    v0087 = v0086;
    v0086 = v0087;
    if (v0086 == nil) return onevalue(v0101);
    v0086 = v0087;
    v0086 = qcdr(v0086);
    return onevalue(v0086);
}



// Code for maxdeg

static LispObject CC_maxdeg(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0024, v0038;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxdeg");
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

v0073:
    v0024 = stack[-1];
    if (v0024 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    v0038 = qcdr(v0024);
    v0024 = stack[0];
    v0024 = qcdr(v0024);
    v0024 = (LispObject)greaterp2(v0038, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0024 = v0024 ? lisp_true : nil;
    env = stack[-2];
    if (v0024 == nil) goto v0028;
    v0024 = stack[-1];
    v0024 = qcdr(v0024);
    v0038 = v0024;
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    stack[0] = v0024;
    v0024 = v0038;
    stack[-1] = v0024;
    goto v0073;

v0028:
    v0024 = stack[-1];
    v0024 = qcdr(v0024);
    stack[-1] = v0024;
    goto v0073;
// error exit handlers
v0089:
    popv(3);
    return nil;
}



// Code for repeatsp

static LispObject CC_repeatsp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063, v0092, v0098;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repeatsp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0092 = v0000;
// end of prologue

v0174:
    v0063 = v0092;
    if (v0063 == nil) goto v0115;
    v0063 = v0092;
    v0098 = qcar(v0063);
    v0063 = v0092;
    v0063 = qcdr(v0063);
    v0063 = Lmember(nil, v0098, v0063);
    if (!(v0063 == nil)) return onevalue(v0063);
    v0063 = v0092;
    v0063 = qcdr(v0063);
    v0092 = v0063;
    goto v0174;

v0115:
    v0063 = qvalue(elt(env, 1)); // nil
    return onevalue(v0063);
}



setup_type const u05_setup[] =
{
    {"depends",                 too_few_2,      CC_depends,    wrong_no_2},
    {"prepf1a_reversed",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_prepf1a_reversed},
    {"rd:onep",                 CC_rdTonep,     too_many_1,    wrong_no_1},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"int-equiv-chk",           CC_intKequivKchk,too_many_1,   wrong_no_1},
    {"delallasc",               too_few_2,      CC_delallasc,  wrong_no_2},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"mkrn",                    too_few_2,      CC_mkrn,       wrong_no_2},
    {"gen-mult-by-const-mod-p", too_few_2,      CC_genKmultKbyKconstKmodKp,wrong_no_2},
    {"noncomp*",                CC_noncompH,    too_many_1,    wrong_no_1},
    {"convprec*",               CC_convprecH,   too_many_1,    wrong_no_1},
    {"subs3q",                  CC_subs3q,      too_many_1,    wrong_no_1},
    {"sort-factors",            CC_sortKfactors,too_many_1,    wrong_no_1},
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"multi_isarb_compl",       CC_multi_isarb_compl,too_many_1,wrong_no_1},
    {"sqform",                  too_few_2,      CC_sqform,     wrong_no_2},
    {"dm-difference",           too_few_2,      CC_dmKdifference,wrong_no_2},
    {"freeindexchk",            CC_freeindexchk,too_many_1,    wrong_no_1},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {":times",                  too_few_2,      CC_Ttimes,     wrong_no_2},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"mod#",                    CC_modC,        too_many_1,    wrong_no_1},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"pasf_susipost",           too_few_2,      CC_pasf_susipost,wrong_no_2},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"emtch",                   CC_emtch,       too_many_1,    wrong_no_1},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"fast-column-dim",         CC_fastKcolumnKdim,too_many_1, wrong_no_1},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"smemql",                  too_few_2,      CC_smemql,     wrong_no_2},
    {"get-print-name",          CC_getKprintKname,too_many_1,  wrong_no_1},
    {"getelv",                  CC_getelv,      too_many_1,    wrong_no_1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"vecp",                    CC_vecp,        too_many_1,    wrong_no_1},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"sfto_dcontentf1",         too_few_2,      CC_sfto_dcontentf1,wrong_no_2},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"mk*sq",                   CC_mkHsq,       too_many_1,    wrong_no_1},
    {"pnthxzz",                 too_few_2,      CC_pnthxzz,    wrong_no_2},
    {"sqchk",                   CC_sqchk,       too_many_1,    wrong_no_1},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"eolcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eolcheck},
    {"*ssave",                  too_few_2,      CC_Hssave,     wrong_no_2},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"bc=simp",                 CC_bcMsimp,     too_many_1,    wrong_no_1},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"mcharg1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg1},
    {"quotf-fail",              too_few_2,      CC_quotfKfail, wrong_no_2},
    {"mri_0mk2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mri_0mk2},
    {"qqe_id-nyt-branchb",      CC_qqe_idKnytKbranchb,too_many_1,wrong_no_1},
    {"gcdf",                    too_few_2,      CC_gcdf,       wrong_no_2},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"comm_kernels",            CC_comm_kernels,too_many_1,    wrong_no_1},
    {"atomf",                   CC_atomf,       too_many_1,    wrong_no_1},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"algid",                   too_few_2,      CC_algid,      wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {":plus",                   too_few_2,      CC_Tplus,      wrong_no_2},
    {"macrochk",                too_few_2,      CC_macrochk,   wrong_no_2},
    {"getel",                   CC_getel,       too_many_1,    wrong_no_1},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"copy",                    CC_copy,        too_many_1,    wrong_no_1},
    {"ofsf_posdefp",            CC_ofsf_posdefp,too_many_1,    wrong_no_1},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"prepd",                   CC_prepd,       too_many_1,    wrong_no_1},
    {"exptchk",                 CC_exptchk,     too_many_1,    wrong_no_1},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"chundexp",                CC_chundexp,    too_many_1,    wrong_no_1},
    {"round:mt",                too_few_2,      CC_roundTmt,   wrong_no_2},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"red-char-downcase",       CC_redKcharKdowncase,too_many_1,wrong_no_1},
    {"maxdeg",                  too_few_2,      CC_maxdeg,     wrong_no_2},
    {"repeatsp",                CC_repeatsp,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u05", (two_args *)"8170 5465926 6750381", 0}
};

// end of generated code
