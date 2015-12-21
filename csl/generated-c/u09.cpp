
// $destdir/u09.c        Machine generated C code

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



// Code for red_better

static LispObject CC_red_better(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_better");
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
    v0004 = v0000;
// end of prologue
    fn = elt(env, 1); // bas_dplen
    stack[-1] = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-2];
    v0004 = stack[0];
    fn = elt(env, 1); // bas_dplen
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    {
        LispObject v0006 = stack[-1];
        popv(3);
        return Llessp(nil, v0006, v0004);
    }
// error exit handlers
v0005:
    popv(3);
    return nil;
}



// Code for ord

static LispObject CC_ord(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0010, v0011, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ord");
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
    v0011 = qvalue(elt(env, 1)); // ordering
    v0010 = elt(env, 2); // lex
    if (v0011 == v0010) goto v0013;
    v0010 = v0012;
    v0010 = qcar(v0010);
    { popv(1); return onevalue(v0010); }

v0013:
    v0010 = elt(env, 3); // plus
    v0011 = v0012;
    v0010 = cons(v0010, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); // eval
        return (*qfn1(fn))(qenv(fn), v0010);
    }
// error exit handlers
v0014:
    popv(1);
    return nil;
}



// Code for reduce!-mod!-p

static LispObject CC_reduceKmodKp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0022, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-p");
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
    v0021 = stack[0];
    if (v0021 == nil) goto v0024;
    v0021 = stack[0];
    if (!consp(v0021)) goto v0009;
    v0021 = stack[0];
    v0021 = qcar(v0021);
    v0021 = (consp(v0021) ? nil : lisp_true);
    goto v0002;

v0002:
    if (v0021 == nil) goto v0025;
    v0021 = stack[0];
    v0021 = Lmodular_number(nil, v0021);
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0021);
    }

v0025:
    v0021 = stack[0];
    v0021 = qcar(v0021);
    v0021 = qcdr(v0021);
    stack[-1] = CC_reduceKmodKp(env, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = CC_reduceKmodKp(env, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0022 = stack[-1];
    v0023 = v0022;
    if (v0023 == nil) { popv(3); return onevalue(v0021); }
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0023 = qcar(v0023);
    popv(3);
    return acons(v0023, v0022, v0021);

v0009:
    v0021 = qvalue(elt(env, 2)); // t
    goto v0002;

v0024:
    v0021 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0021); }
// error exit handlers
v0026:
    popv(3);
    return nil;
}



// Code for cdarx

static LispObject CC_cdarx(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0002, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cdarx");
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
    v0002 = v0000;
// end of prologue
    v0009 = v0002;
    v0002 = elt(env, 1); // cdar
    fn = elt(env, 2); // carx
    v0002 = (*qfn2(fn))(qenv(fn), v0009, v0002);
    errexit();
    v0002 = qcdr(v0002);
    return onevalue(v0002);
}



// Code for mri_2pasfat

static LispObject CC_mri_2pasfat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0013, v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_2pasfat");
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
    v0013 = stack[0];
    fn = elt(env, 2); // mri_op
    stack[-1] = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0013 = stack[0];
    fn = elt(env, 3); // mri_arg2l
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0005 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0007 = stack[-1];
        popv(3);
        return list3(v0007, v0013, v0005);
    }
// error exit handlers
v0029:
    popv(3);
    return nil;
}



// Code for vdp_poly

static LispObject CC_vdp_poly(LispObject env,
                         LispObject v0000)
{
    LispObject v0030;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0030 = v0000;
// end of prologue
    v0030 = qcdr(v0030);
    v0030 = qcdr(v0030);
    v0030 = qcdr(v0030);
    v0030 = qcar(v0030);
    return onevalue(v0030);
}



// Code for expression

static LispObject CC_expression(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0041, v0042;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expression");
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
    v0042 = v0000;
// end of prologue
    v0040 = v0042;
    if (!consp(v0040)) goto v0030;
    v0040 = v0042;
    v0041 = qcar(v0040);
    v0040 = elt(env, 1); // !:rd!:
    if (v0041 == v0040) goto v0009;
    v0040 = v0042;
    v0041 = qcar(v0040);
    v0040 = qvalue(elt(env, 2)); // unary!*
    v0040 = Lassoc(nil, v0041, v0040);
    v0041 = v0040;
    if (v0040 == nil) goto v0043;
    v0040 = v0041;
    v0040 = qcdr(v0040);
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    if (v0040 == nil) goto v0044;
    v0040 = v0041;
    v0040 = qcdr(v0040);
    stack[0] = qcar(v0040);
    v0040 = v0042;
    v0040 = qcdr(v0040);
    v0041 = qcdr(v0041);
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    v0040 = list2(v0040, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    fn = elt(env, 5); // apply
    v0040 = (*qfn2(fn))(qenv(fn), stack[0], v0040);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    goto v0046;

v0046:
    v0040 = nil;
    { popv(2); return onevalue(v0040); }

v0044:
    v0040 = v0041;
    v0040 = qcdr(v0040);
    stack[0] = qcar(v0040);
    v0040 = v0042;
    v0040 = qcdr(v0040);
    v0040 = ncons(v0040);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    fn = elt(env, 5); // apply
    v0040 = (*qfn2(fn))(qenv(fn), stack[0], v0040);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    goto v0046;

v0043:
    v0040 = v0042;
    v0041 = qcar(v0040);
    v0040 = elt(env, 3); // !*sq
    if (v0041 == v0040) goto v0047;
    v0040 = v0042;
    fn = elt(env, 6); // operator_fn
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    goto v0046;

v0047:
    v0040 = v0042;
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    fn = elt(env, 7); // prepsq
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0040 = CC_expression(env, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    goto v0046;

v0009:
    v0040 = v0042;
    fn = elt(env, 8); // printout
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    goto v0046;

v0030:
    v0040 = v0042;
    fn = elt(env, 9); // f4
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    goto v0046;
// error exit handlers
v0045:
    popv(2);
    return nil;
}



// Code for spmultm2

static LispObject CC_spmultm2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0079, v0080, v0081, v0082;
    LispObject fn;
    LispObject v0037, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "spmultm2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spmultm2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0037,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0079 = v0037;
    stack[-10] = v0001;
    stack[-11] = v0000;
// end of prologue
    v0080 = v0079;
    v0080 = qcdr(v0080);
    v0080 = qcar(v0080);
    fn = elt(env, 3); // mkempspmat
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[-12] = v0079;
    v0079 = stack[-11];
    v0079 = qcdr(v0079);
    v0080 = qcar(v0079);
    v0079 = stack[-11];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    fn = elt(env, 4); // empty
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    if (v0079 == nil) goto v0084;
    v0079 = stack[-10];
    v0079 = qcdr(v0079);
    v0080 = qcar(v0079);
    v0079 = stack[-10];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    fn = elt(env, 4); // empty
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    v0079 = (v0079 == nil ? lisp_true : nil);
    goto v0085;

v0085:
    if (!(v0079 == nil)) { LispObject res = stack[-12]; popv(14); return onevalue(res); }
    v0079 = stack[-11];
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    stack[-9] = v0079;
    v0079 = stack[-10];
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    stack[-8] = v0079;
    v0079 = (LispObject)17; // 1
    stack[-3] = v0079;
    goto v0086;

v0086:
    v0079 = stack[-11];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0080 = qcar(v0079);
    v0079 = stack[-3];
    v0079 = difference2(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    v0079 = Lminusp(nil, v0079);
    env = stack[-13];
    if (!(v0079 == nil)) { LispObject res = stack[-12]; popv(14); return onevalue(res); }
    v0080 = stack[-9];
    v0079 = stack[-3];
    fn = elt(env, 5); // findrow
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[-7] = v0079;
    v0079 = stack[-7];
    if (v0079 == nil) goto v0087;
    v0079 = (LispObject)17; // 1
    stack[-2] = v0079;
    goto v0088;

v0088:
    v0079 = stack[-10];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0080 = qcar(v0079);
    v0079 = stack[-2];
    v0079 = difference2(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    v0079 = Lminusp(nil, v0079);
    env = stack[-13];
    if (!(v0079 == nil)) goto v0087;
    v0080 = stack[-8];
    v0079 = stack[-2];
    fn = elt(env, 5); // findrow
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[-6] = v0079;
    v0079 = stack[-6];
    if (v0079 == nil) goto v0089;
    v0079 = (LispObject)1; // 0
    fn = elt(env, 6); // simp
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[-4] = v0079;
    v0079 = stack[-7];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0090;

v0090:
    v0079 = stack[-1];
    if (v0079 == nil) goto v0091;
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0080 = v0079;
    v0079 = v0080;
    v0079 = qcar(v0079);
    v0080 = qcdr(v0080);
    v0081 = v0080;
    v0080 = v0079;
    v0079 = stack[-6];
    v0079 = Latsoc(nil, v0080, v0079);
    stack[-5] = v0079;
    v0079 = stack[-5];
    if (v0079 == nil) goto v0092;
    v0079 = stack[-5];
    v0079 = qcdr(v0079);
    stack[-5] = v0079;
    v0079 = v0081;
    fn = elt(env, 6); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    v0079 = stack[-5];
    fn = elt(env, 6); // simp
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    fn = elt(env, 7); // multsq
    v0079 = (*qfn2(fn))(qenv(fn), stack[0], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[0] = v0079;
    v0080 = stack[-4];
    v0079 = stack[0];
    fn = elt(env, 8); // addsq
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[-4] = v0079;
    goto v0093;

v0093:
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0090;

v0092:
    v0079 = stack[-4];
    stack[-4] = v0079;
    goto v0093;

v0091:
    v0079 = stack[-4];
    fn = elt(env, 9); // mk!*sq
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[0] = v0079;
    v0080 = stack[0];
    v0079 = (LispObject)1; // 0
    if (v0080 == v0079) goto v0089;
    v0081 = stack[-12];
    v0080 = stack[-3];
    v0079 = stack[-2];
    v0082 = list3(v0081, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    v0081 = stack[0];
    v0080 = stack[-12];
    v0079 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 10); // letmtr3
    v0079 = (*qfnn(fn))(qenv(fn), 4, v0082, v0081, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    goto v0089;

v0089:
    v0079 = stack[-2];
    v0079 = add1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[-2] = v0079;
    goto v0088;

v0087:
    v0079 = stack[-3];
    v0079 = add1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-13];
    stack[-3] = v0079;
    goto v0086;

v0084:
    v0079 = qvalue(elt(env, 1)); // t
    goto v0085;
// error exit handlers
v0083:
    popv(14);
    return nil;
}



// Code for exchk2

static LispObject CC_exchk2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0104, v0048, v0105;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exchk2");
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

v0046:
    v0104 = stack[-1];
    if (v0104 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0104 = stack[-1];
    v0104 = qcdr(v0104);
    stack[-2] = v0104;
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    fn = elt(env, 6); // prepsqx
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-3];
    v0105 = v0104;
    v0048 = (LispObject)17; // 1
    if (v0105 == v0048) goto v0074;
    v0048 = qvalue(elt(env, 1)); // !*nosqrts
    if (v0048 == nil) goto v0075;
    v0105 = elt(env, 2); // expt
    v0048 = stack[-1];
    v0048 = qcar(v0048);
    v0048 = qcar(v0048);
    v0104 = list3(v0105, v0048, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-3];
    v0048 = v0104;
    goto v0007;

v0007:
    v0104 = stack[0];
    v0104 = cons(v0048, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-3];
    stack[0] = v0104;
    v0104 = stack[-2];
    stack[-1] = v0104;
    goto v0046;

v0075:
    v0105 = v0104;
    v0048 = elt(env, 3); // (quotient 1 2)
    if (equal(v0105, v0048)) goto v0107;
    v0105 = v0104;
    v0048 = elt(env, 5); // 0.5
    if (equal(v0105, v0048)) goto v0108;
    v0105 = elt(env, 2); // expt
    v0048 = stack[-1];
    v0048 = qcar(v0048);
    v0048 = qcar(v0048);
    v0104 = list3(v0105, v0048, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-3];
    v0048 = v0104;
    goto v0007;

v0108:
    v0048 = elt(env, 4); // sqrt
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = list2(v0048, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-3];
    v0048 = v0104;
    goto v0007;

v0107:
    v0048 = elt(env, 4); // sqrt
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0104 = list2(v0048, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-3];
    v0048 = v0104;
    goto v0007;

v0074:
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0104 = qcar(v0104);
    v0048 = v0104;
    goto v0007;
// error exit handlers
v0106:
    popv(4);
    return nil;
}



// Code for covposp

static LispObject CC_covposp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0109, v0110;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for covposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0109 = v0000;
// end of prologue

v0111:
    v0110 = v0109;
    if (v0110 == nil) goto v0024;
    v0110 = v0109;
    v0110 = qcar(v0110);
    if (!consp(v0110)) goto v0029;
    v0109 = qcdr(v0109);
    goto v0111;

v0029:
    v0109 = qvalue(elt(env, 2)); // nil
    return onevalue(v0109);

v0024:
    v0109 = qvalue(elt(env, 1)); // t
    return onevalue(v0109);
}



// Code for statep!*

static LispObject CC_statepH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0002, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for statep*");
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
    v0002 = v0000;
// end of prologue
    fn = elt(env, 2); // getphystype
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    v0009 = elt(env, 1); // state
    v0002 = (v0002 == v0009 ? lisp_true : nil);
    { popv(1); return onevalue(v0002); }
// error exit handlers
v0004:
    popv(1);
    return nil;
}



// Code for form1

static LispObject CC_form1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0195, v0196, v0197, v0198;
    LispObject fn;
    LispObject v0037, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "form1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for form1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0037,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0037;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue

v0111:
    v0195 = stack[-3];
    if (!consp(v0195)) goto v0020;
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    if (!consp(v0195)) goto v0026;
    v0197 = stack[-3];
    v0196 = stack[-2];
    v0195 = stack[-1];
    {
        popv(6);
        fn = elt(env, 25); // form2
        return (*qfnn(fn))(qenv(fn), 3, v0197, v0196, v0195);
    }

v0026:
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    if (symbolp(v0195)) goto v0032;
    v0195 = stack[-3];
    v0196 = qcar(v0195);
    v0195 = elt(env, 3); // "operator"
    fn = elt(env, 26); // typerr
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    goto v0200;

v0200:
    v0196 = stack[-1];
    v0195 = elt(env, 6); // symbolic
    if (v0196 == v0195) goto v0201;
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    if (!symbolp(v0195)) v0195 = nil;
    else { v0195 = qfastgets(v0195);
           if (v0195 != nil) { v0195 = elt(v0195, 59); // opfn
#ifdef RECORD_GET
             if (v0195 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0195 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0195 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0195 == SPID_NOPROP) v0195 = nil; else v0195 = lisp_true; }}
#endif
    goto v0202;

v0202:
    if (v0195 == nil) goto v0203;
    v0195 = stack[-3];
    fn = elt(env, 27); // argnochk
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    goto v0203;

v0203:
    v0195 = stack[-3];
    v0197 = qcdr(v0195);
    v0196 = stack[-2];
    v0195 = stack[-1];
    fn = elt(env, 28); // formlis
    v0195 = (*qfnn(fn))(qenv(fn), 3, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-4] = v0195;
    v0196 = stack[-4];
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    if (equal(v0196, v0195)) goto v0204;
    v0195 = stack[-3];
    v0196 = qcar(v0195);
    v0195 = stack[-4];
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    goto v0205;

v0205:
    stack[0] = v0195;
    v0196 = stack[-1];
    v0195 = elt(env, 6); // symbolic
    if (v0196 == v0195) goto v0206;
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    if (!symbolp(v0195)) v0195 = nil;
    else { v0195 = qfastgets(v0195);
           if (v0195 != nil) { v0195 = elt(v0195, 36); // stat
#ifdef RECORD_GET
             if (v0195 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0195 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0195 == SPID_NOPROP) v0195 = nil; }}
#endif
    if (!(v0195 == nil)) goto v0207;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    if (v0195 == nil) goto v0208;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0195 = elt(env, 18); // quote
    if (!consp(v0196)) goto v0209;
    v0196 = qcar(v0196);
    if (!(v0196 == v0195)) goto v0209;
    v0195 = qvalue(elt(env, 19)); // !*micro!-version
    if (v0195 == nil) goto v0210;
    v0195 = qvalue(elt(env, 20)); // !*defn
    v0195 = (v0195 == nil ? lisp_true : nil);
    goto v0211;

v0211:
    v0195 = (v0195 == nil ? lisp_true : nil);
    goto v0212;

v0212:
    if (!(v0195 == nil)) goto v0207;
    v0196 = stack[0];
    v0195 = stack[-2];
    fn = elt(env, 29); // intexprnp
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    if (v0195 == nil) goto v0213;
    v0195 = qvalue(elt(env, 21)); // !*composites
    if (v0195 == nil) goto v0214;
    v0195 = qvalue(elt(env, 15)); // nil
    goto v0207;

v0207:
    if (v0195 == nil) goto v0215;
    v0196 = stack[0];
    v0195 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); // macrochk
        return (*qfn2(fn))(qenv(fn), v0196, v0195);
    }

v0215:
    v0196 = stack[-1];
    v0195 = elt(env, 23); // algebraic
    if (v0196 == v0195) goto v0216;
    v0198 = stack[0];
    v0197 = stack[-2];
    v0196 = stack[-1];
    v0195 = elt(env, 23); // algebraic
    {
        popv(6);
        fn = elt(env, 31); // convertmode
        return (*qfnn(fn))(qenv(fn), 4, v0198, v0197, v0196, v0195);
    }

v0216:
    stack[0] = elt(env, 24); // list
    v0195 = stack[-3];
    v0196 = qcar(v0195);
    v0195 = stack[-2];
    fn = elt(env, 32); // algid
    v0196 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0195 = stack[-4];
    {
        LispObject v0217 = stack[0];
        popv(6);
        return list2star(v0217, v0196, v0195);
    }

v0214:
    v0196 = qvalue(elt(env, 22)); // current!-modulus
    v0195 = (LispObject)17; // 1
    v0195 = (v0196 == v0195 ? lisp_true : nil);
    goto v0207;

v0213:
    v0195 = qvalue(elt(env, 15)); // nil
    goto v0207;

v0210:
    v0195 = qvalue(elt(env, 15)); // nil
    goto v0211;

v0209:
    v0195 = qvalue(elt(env, 15)); // nil
    goto v0212;

v0208:
    v0195 = qvalue(elt(env, 15)); // nil
    goto v0212;

v0206:
    v0195 = qvalue(elt(env, 9)); // t
    goto v0207;

v0204:
    v0195 = stack[-3];
    goto v0205;

v0201:
    v0195 = qvalue(elt(env, 9)); // t
    goto v0202;

v0032:
    v0195 = stack[-3];
    v0196 = qcar(v0195);
    v0195 = elt(env, 4); // comment
    if (v0196 == v0195) goto v0073;
    v0195 = stack[-3];
    v0196 = qcar(v0195);
    v0195 = elt(env, 5); // noform
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-5];
    if (!(v0195 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    fn = elt(env, 33); // arrayp
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    if (v0195 == nil) goto v0218;
    v0196 = stack[-1];
    v0195 = elt(env, 6); // symbolic
    if (!(v0196 == v0195)) goto v0218;
    stack[0] = elt(env, 7); // getel
    v0197 = stack[-3];
    v0196 = stack[-2];
    v0195 = stack[-1];
    fn = elt(env, 34); // intargfn
    v0195 = (*qfnn(fn))(qenv(fn), 3, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    {
        LispObject v0219 = stack[0];
        popv(6);
        return list2(v0219, v0195);
    }

v0218:
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    if (v0195 == nil) goto v0090;
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    if (!symbolp(v0195)) v0196 = nil;
    else { v0196 = qfastgets(v0195);
           if (v0196 != nil) { v0196 = elt(v0196, 2); // rtype
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    v0195 = elt(env, 8); // vector
    if (v0196 == v0195) goto v0220;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = Lsimple_vectorp(nil, v0195);
    env = stack[-5];
    if (!(v0195 == nil)) goto v0221;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0195 = elt(env, 10); // vecfn
    v0195 = Lflagpcar(nil, v0196, v0195);
    env = stack[-5];
    goto v0221;

v0221:
    if (v0195 == nil) goto v0090;
    v0197 = stack[-3];
    v0196 = stack[-2];
    v0195 = stack[-1];
    {
        popv(6);
        fn = elt(env, 35); // getvect
        return (*qfnn(fn))(qenv(fn), 3, v0197, v0196, v0195);
    }

v0090:
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    if (!symbolp(v0195)) v0195 = nil;
    else { v0195 = qfastgets(v0195);
           if (v0195 != nil) { v0195 = elt(v0195, 48); // modefn
#ifdef RECORD_GET
             if (v0195 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0195 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0195 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0195 == SPID_NOPROP) v0195 = nil; else v0195 = lisp_true; }}
#endif
    if (v0195 == nil) goto v0222;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0198 = qcar(v0195);
    v0197 = stack[-2];
    v0196 = stack[-1];
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    {
        popv(6);
        fn = elt(env, 31); // convertmode
        return (*qfnn(fn))(qenv(fn), 4, v0198, v0197, v0196, v0195);
    }

v0222:
    v0195 = stack[-3];
    v0196 = qcar(v0195);
    v0195 = elt(env, 11); // formfn
    v0195 = get(v0196, v0195);
    env = stack[-5];
    stack[-4] = v0195;
    if (v0195 == nil) goto v0081;
    v0198 = stack[-4];
    v0197 = stack[-3];
    v0196 = stack[-2];
    v0195 = stack[-1];
    v0196 = Lapply3(nil, 4, v0198, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0195 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); // macrochk
        return (*qfn2(fn))(qenv(fn), v0196, v0195);
    }

v0081:
    v0195 = stack[-3];
    v0195 = qcar(v0195);
    if (!symbolp(v0195)) v0196 = nil;
    else { v0196 = qfastgets(v0195);
           if (v0196 != nil) { v0196 = elt(v0196, 36); // stat
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    v0195 = elt(env, 12); // rlis
    if (v0196 == v0195) goto v0223;
    v0195 = stack[-3];
    v0196 = qcar(v0195);
    v0195 = elt(env, 13); // !*comma!*
    if (!(v0196 == v0195)) goto v0200;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    if (!consp(v0195)) goto v0224;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    if (!consp(v0195)) goto v0225;
    v0195 = qvalue(elt(env, 15)); // nil
    goto v0226;

v0226:
    if (v0195 == nil) goto v0227;
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = qcar(v0195);
    fn = elt(env, 36); // blocktyperr
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    goto v0200;

v0227:
    stack[-4] = elt(env, 16); // rlisp
    stack[0] = (LispObject)161; // 10
    v0196 = elt(env, 17); // "Syntax error: , invalid after"
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = list2(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    fn = elt(env, 37); // rerror
    v0195 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    goto v0200;

v0225:
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0196 = qcar(v0195);
    v0195 = elt(env, 14); // type
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-5];
    goto v0226;

v0224:
    v0195 = qvalue(elt(env, 15)); // nil
    goto v0226;

v0223:
    v0197 = stack[-3];
    v0196 = stack[-2];
    v0195 = stack[-1];
    fn = elt(env, 38); // formrlis
    v0196 = (*qfnn(fn))(qenv(fn), 3, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0195 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); // macrochk
        return (*qfn2(fn))(qenv(fn), v0196, v0195);
    }

v0220:
    v0195 = qvalue(elt(env, 9)); // t
    goto v0221;

v0073:
    v0195 = stack[-3];
    fn = elt(env, 39); // lastpair
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0197 = qcar(v0195);
    v0196 = stack[-2];
    v0195 = stack[-1];
    stack[-3] = v0197;
    stack[-2] = v0196;
    stack[-1] = v0195;
    goto v0111;

v0020:
    v0195 = stack[-3];
    if (!(symbolp(v0195))) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0196 = stack[-3];
    v0195 = elt(env, 1); // ed
    if (v0196 == v0195) goto v0029;
    v0195 = stack[-3];
    if (!symbolp(v0195)) v0195 = nil;
    else { v0195 = qfastgets(v0195);
           if (v0195 != nil) { v0195 = elt(v0195, 48); // modefn
#ifdef RECORD_GET
             if (v0195 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0195 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0195 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0195 == SPID_NOPROP) v0195 = nil; else v0195 = lisp_true; }}
#endif
    if (v0195 == nil) goto v0228;
    v0195 = stack[-3];
    {
        popv(6);
        fn = elt(env, 40); // set!-global!-mode
        return (*qfn1(fn))(qenv(fn), v0195);
    }

v0228:
    v0196 = stack[-1];
    v0195 = elt(env, 2); // idfn
    v0195 = get(v0196, v0195);
    stack[-4] = v0195;
    if (v0195 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0197 = stack[-4];
    v0196 = stack[-3];
    v0195 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v0197, v0196, v0195);

v0029:
    v0195 = stack[-3];
    popv(6);
    return ncons(v0195);
// error exit handlers
v0199:
    popv(6);
    return nil;
}



// Code for mv!-domainlist!-!-

static LispObject CC_mvKdomainlistKK(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0039, v0102;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-domainlist--");
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
    goto v0046;

v0046:
    v0039 = stack[-1];
    if (v0039 == nil) goto v0003;
    v0039 = stack[-1];
    v0102 = qcar(v0039);
    v0039 = stack[0];
    v0039 = qcar(v0039);
    v0102 = difference2(v0102, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-3];
    v0039 = stack[-2];
    v0039 = cons(v0102, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-3];
    stack[-2] = v0039;
    v0039 = stack[-1];
    v0039 = qcdr(v0039);
    stack[-1] = v0039;
    v0039 = stack[0];
    v0039 = qcdr(v0039);
    stack[0] = v0039;
    goto v0046;

v0003:
    v0039 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0039);
    }
// error exit handlers
v0077:
    popv(4);
    return nil;
}



// Code for gcddd

static LispObject CC_gcddd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0232, v0233, v0106;
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
    v0233 = stack[-1];
    v0232 = (LispObject)17; // 1
    if (v0233 == v0232) goto v0003;
    v0233 = stack[0];
    v0232 = (LispObject)17; // 1
    v0232 = (v0233 == v0232 ? lisp_true : nil);
    goto v0027;

v0027:
    if (v0232 == nil) goto v0046;
    v0232 = (LispObject)17; // 1
    { popv(3); return onevalue(v0232); }

v0046:
    v0232 = stack[-1];
    if (!consp(v0232)) goto v0074;
    v0232 = stack[0];
    if (!consp(v0232)) goto v0234;
    v0232 = stack[-1];
    v0232 = qcar(v0232);
    if (!symbolp(v0232)) v0232 = nil;
    else { v0232 = qfastgets(v0232);
           if (v0232 != nil) { v0232 = elt(v0232, 3); // field
#ifdef RECORD_GET
             if (v0232 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0232 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0232 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0232 == SPID_NOPROP) v0232 = nil; else v0232 = lisp_true; }}
#endif
    if (v0232 == nil) goto v0072;
    v0232 = qvalue(elt(env, 1)); // t
    goto v0031;

v0031:
    if (v0232 == nil) goto v0069;
    v0232 = (LispObject)17; // 1
    { popv(3); return onevalue(v0232); }

v0069:
    v0106 = stack[-1];
    v0233 = stack[0];
    v0232 = elt(env, 2); // gcd
    {
        popv(3);
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0106, v0233, v0232);
    }

v0072:
    v0232 = stack[0];
    v0232 = qcar(v0232);
    if (!symbolp(v0232)) v0232 = nil;
    else { v0232 = qfastgets(v0232);
           if (v0232 != nil) { v0232 = elt(v0232, 3); // field
#ifdef RECORD_GET
             if (v0232 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0232 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0232 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0232 == SPID_NOPROP) v0232 = nil; else v0232 = lisp_true; }}
#endif
    goto v0031;

v0234:
    v0232 = stack[-1];
    v0232 = qcar(v0232);
    if (!symbolp(v0232)) v0232 = nil;
    else { v0232 = qfastgets(v0232);
           if (v0232 != nil) { v0232 = elt(v0232, 3); // field
#ifdef RECORD_GET
             if (v0232 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0232 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0232 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0232 == SPID_NOPROP) v0232 = nil; else v0232 = lisp_true; }}
#endif
    if (v0232 == nil) goto v0235;
    v0232 = (LispObject)17; // 1
    { popv(3); return onevalue(v0232); }

v0235:
    v0106 = stack[-1];
    v0233 = stack[0];
    v0232 = elt(env, 2); // gcd
    {
        popv(3);
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0106, v0233, v0232);
    }

v0074:
    v0232 = stack[0];
    if (!consp(v0232)) goto v0228;
    v0232 = stack[0];
    fn = elt(env, 4); // fieldp
    v0232 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0232 == nil) goto v0015;
    v0232 = (LispObject)17; // 1
    { popv(3); return onevalue(v0232); }

v0015:
    v0106 = stack[-1];
    v0233 = stack[0];
    v0232 = elt(env, 2); // gcd
    {
        popv(3);
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0106, v0233, v0232);
    }

v0228:
    v0233 = stack[-1];
    v0232 = stack[0];
        popv(3);
        return Lgcd(nil, v0233, v0232);

v0003:
    v0232 = qvalue(elt(env, 1)); // t
    goto v0027;
// error exit handlers
v0236:
    popv(3);
    return nil;
}



// Code for sc_kern

static LispObject CC_sc_kern(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_kern");
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
    v0028 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // g_sc_ve
    v0028 = sub1(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    v0028 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0028/(16/CELL)));
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    { popv(1); return onevalue(v0028); }
// error exit handlers
v0005:
    popv(1);
    return nil;
}



// Code for primep

static LispObject CC_primep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0106, v0186;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for primep");
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

v0024:
    v0106 = stack[0];
    v0106 = integerp(v0106);
    if (v0106 == nil) goto v0009;
    v0186 = stack[0];
    v0106 = (LispObject)1; // 0
    v0106 = (LispObject)lessp2(v0186, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    v0106 = v0106 ? lisp_true : nil;
    env = stack[-2];
    if (v0106 == nil) goto v0019;
    v0106 = stack[0];
    v0106 = negate(v0106);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-2];
    stack[0] = v0106;
    goto v0024;

v0019:
    v0186 = stack[0];
    v0106 = (LispObject)17; // 1
    if (v0186 == v0106) goto v0085;
    v0186 = stack[0];
    v0106 = qvalue(elt(env, 3)); // !*last!-prime!-in!-list!*
    v0106 = (LispObject)lesseq2(v0186, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    v0106 = v0106 ? lisp_true : nil;
    env = stack[-2];
    if (v0106 == nil) goto v0230;
    v0106 = stack[0];
    v0186 = qvalue(elt(env, 4)); // !*primelist!*
    v0106 = Lmember(nil, v0106, v0186);
    { popv(3); return onevalue(v0106); }

v0230:
    v0186 = stack[0];
    v0106 = qvalue(elt(env, 5)); // !*last!-prime!-squared!*
    v0106 = (LispObject)lesseq2(v0186, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    v0106 = v0106 ? lisp_true : nil;
    env = stack[-2];
    if (v0106 == nil) goto v0045;
    v0106 = qvalue(elt(env, 4)); // !*primelist!*
    stack[-1] = v0106;
    goto v0244;

v0244:
    v0106 = stack[-1];
    if (v0106 == nil) goto v0192;
    v0186 = stack[0];
    v0106 = stack[-1];
    v0106 = qcar(v0106);
    v0186 = Cremainder(v0186, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-2];
    v0106 = (LispObject)1; // 0
    if (v0186 == v0106) goto v0192;
    v0106 = stack[-1];
    v0106 = qcdr(v0106);
    stack[-1] = v0106;
    goto v0244;

v0192:
    v0106 = stack[-1];
    v0106 = (v0106 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0106); }

v0045:
    v0186 = stack[0];
    v0106 = qvalue(elt(env, 6)); // largest!-small!-modulus
    v0106 = (LispObject)greaterp2(v0186, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    v0106 = v0106 ? lisp_true : nil;
    env = stack[-2];
    if (v0106 == nil) goto v0105;
    v0106 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // general!-primep
        return (*qfn1(fn))(qenv(fn), v0106);
    }

v0105:
    v0106 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); // small!-primep
        return (*qfn1(fn))(qenv(fn), v0106);
    }

v0085:
    v0106 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0106); }

v0009:
    v0186 = stack[0];
    v0106 = elt(env, 1); // "integer"
    {
        popv(3);
        fn = elt(env, 9); // typerr
        return (*qfn2(fn))(qenv(fn), v0186, v0106);
    }
// error exit handlers
v0243:
    popv(3);
    return nil;
}



// Code for mapcons

static LispObject CC_mapcons(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0022, v0023;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mapcons");
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
    v0022 = v0000;
// end of prologue
    stack[-4] = v0022;
    v0022 = stack[-4];
    if (v0022 == nil) goto v0009;
    v0022 = stack[-4];
    v0022 = qcar(v0022);
    v0023 = stack[-3];
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0022 = ncons(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    stack[-1] = v0022;
    stack[-2] = v0022;
    goto v0027;

v0027:
    v0022 = stack[-4];
    v0022 = qcdr(v0022);
    stack[-4] = v0022;
    v0022 = stack[-4];
    if (v0022 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0022 = stack[-4];
    v0022 = qcar(v0022);
    v0023 = stack[-3];
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0022 = ncons(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0022 = Lrplacd(nil, stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    stack[-1] = v0022;
    goto v0027;

v0009:
    v0022 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0022); }
// error exit handlers
v0234:
    popv(6);
    return nil;
}



// Code for ibalp_litp

static LispObject CC_ibalp_litp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0018, v0247;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_litp");
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
    v0018 = stack[0];
    fn = elt(env, 3); // ibalp_atomp
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    if (!(v0018 == nil)) { popv(2); return onevalue(v0018); }
    v0018 = stack[0];
    if (!consp(v0018)) goto v0242;
    v0018 = stack[0];
    v0018 = qcar(v0018);
    v0247 = v0018;
    goto v0004;

v0004:
    v0018 = elt(env, 1); // not
    if (v0247 == v0018) goto v0003;
    v0018 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0018); }

v0003:
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    v0018 = qcar(v0018);
    {
        popv(2);
        fn = elt(env, 3); // ibalp_atomp
        return (*qfn1(fn))(qenv(fn), v0018);
    }

v0242:
    v0018 = stack[0];
    v0247 = v0018;
    goto v0004;
// error exit handlers
v0039:
    popv(2);
    return nil;
}



// Code for on

static LispObject CC_on(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for on");
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
    v0007 = v0000;
// end of prologue
    stack[0] = v0007;
    goto v0071;

v0071:
    v0007 = stack[0];
    if (v0007 == nil) goto v0003;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 2); // on1
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0071;

v0003:
    v0007 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0007); }
// error exit handlers
v0109:
    popv(2);
    return nil;
}



// Code for vdpgetprop

static LispObject CC_vdpgetprop(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0076, v0239, v0107, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpgetprop");
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
    v0107 = v0001;
    v0033 = v0000;
// end of prologue
    v0076 = v0033;
    if (v0076 == nil) goto v0071;
    v0239 = v0033;
    v0076 = elt(env, 2); // vdp
    if (!consp(v0239)) goto v0007;
    v0239 = qcar(v0239);
    if (!(v0239 == v0076)) goto v0007;
    v0076 = v0107;
    v0239 = v0033;
    v0239 = qcdr(v0239);
    v0239 = qcdr(v0239);
    v0239 = qcdr(v0239);
    v0239 = qcdr(v0239);
    v0239 = qcar(v0239);
    v0076 = Lassoc(nil, v0076, v0239);
    v0239 = v0076;
    v0076 = v0239;
    if (v0076 == nil) goto v0231;
    v0076 = v0239;
    v0076 = qcdr(v0076);
    { popv(3); return onevalue(v0076); }

v0231:
    v0076 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0076); }

v0007:
    stack[-1] = elt(env, 3); // dipoly
    stack[0] = (LispObject)113; // 7
    v0076 = elt(env, 4); // "vdpgetprop given a non-vdp as 1st parameter"
    v0239 = v0033;
    v0076 = list3(v0076, v0239, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    {
        LispObject v0099 = stack[-1];
        LispObject v0192 = stack[0];
        popv(3);
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0099, v0192, v0076);
    }

v0071:
    v0076 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0076); }
// error exit handlers
v0191:
    popv(3);
    return nil;
}



// Code for xord_lex

static LispObject CC_xord_lex(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0244, v0100, v0035, v0235;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xord_lex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0100 = v0001;
    v0035 = v0000;
// end of prologue

v0071:
    v0244 = v0035;
    if (v0244 == nil) goto v0009;
    v0244 = v0035;
    v0235 = qcar(v0244);
    v0244 = (LispObject)17; // 1
    v0244 = (v0235 == v0244 ? lisp_true : nil);
    goto v0002;

v0002:
    if (v0244 == nil) goto v0003;
    v0244 = qvalue(elt(env, 2)); // nil
    return onevalue(v0244);

v0003:
    v0244 = v0100;
    if (v0244 == nil) goto v0084;
    v0244 = v0100;
    v0235 = qcar(v0244);
    v0244 = (LispObject)17; // 1
    v0244 = (v0235 == v0244 ? lisp_true : nil);
    goto v0085;

v0085:
    if (v0244 == nil) goto v0241;
    v0244 = qvalue(elt(env, 1)); // t
    return onevalue(v0244);

v0241:
    v0244 = v0035;
    v0235 = qcar(v0244);
    v0244 = v0100;
    v0244 = qcar(v0244);
    if (v0235 == v0244) goto v0044;
    v0244 = v0035;
    v0244 = qcar(v0244);
    v0100 = qcar(v0100);
    {
        fn = elt(env, 3); // factorordp
        return (*qfn2(fn))(qenv(fn), v0244, v0100);
    }

v0044:
    v0244 = v0035;
    v0244 = qcdr(v0244);
    v0035 = v0244;
    v0244 = v0100;
    v0244 = qcdr(v0244);
    v0100 = v0244;
    goto v0071;

v0084:
    v0244 = qvalue(elt(env, 1)); // t
    goto v0085;

v0009:
    v0244 = qvalue(elt(env, 1)); // t
    goto v0002;
}



// Code for convertmode1

static LispObject CC_convertmode1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0255, v0256, v0257, v0258, v0067, v0068, v0259;
    LispObject fn;
    LispObject v0103, v0037, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "convertmode1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0103 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convertmode1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0103,v0037,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0037,v0103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0257 = v0103;
    v0258 = v0037;
    v0067 = v0001;
    v0068 = v0000;
// end of prologue
    v0256 = v0257;
    v0255 = elt(env, 1); // real
    if (!(v0256 == v0255)) goto v0025;
    v0255 = elt(env, 2); // algebraic
    v0257 = v0255;
    goto v0025;

v0025:
    v0256 = v0258;
    v0255 = elt(env, 1); // real
    if (!(v0256 == v0255)) goto v0038;
    v0255 = elt(env, 2); // algebraic
    v0258 = v0255;
    goto v0038;

v0038:
    v0256 = v0258;
    v0255 = v0257;
    if (v0256 == v0255) { popv(1); return onevalue(v0068); }
    v0255 = v0068;
    if (!(symbolp(v0255))) goto v0041;
    v0256 = v0068;
    v0255 = v0067;
    v0255 = Latsoc(nil, v0256, v0255);
    v0259 = v0255;
    if (v0255 == nil) goto v0041;
    v0255 = v0259;
    v0256 = qcdr(v0255);
    v0255 = elt(env, 3); // (integer scalar real)
    v0255 = Lmemq(nil, v0256, v0255);
    if (v0255 == nil) goto v0191;
    v0255 = qvalue(elt(env, 4)); // nil
    goto v0075;

v0075:
    if (v0255 == nil) goto v0041;
    v0255 = v0068;
    v0256 = v0067;
    v0257 = v0258;
    v0258 = v0259;
    v0258 = qcdr(v0258);
    {
        popv(1);
        fn = elt(env, 5); // convertmode
        return (*qfnn(fn))(qenv(fn), 4, v0255, v0256, v0257, v0258);
    }

v0041:
    v0256 = v0257;
    v0255 = v0258;
    v0255 = get(v0256, v0255);
    env = stack[0];
    v0259 = v0255;
    if (v0255 == nil) goto v0094;
    v0255 = v0259;
    v0256 = v0068;
    v0257 = v0067;
        popv(1);
        return Lapply2(nil, 3, v0255, v0256, v0257);

v0094:
    v0255 = v0257;
    v0256 = v0258;
    fn = elt(env, 6); // typerr
    v0255 = (*qfn2(fn))(qenv(fn), v0255, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0255 = nil;
    { popv(1); return onevalue(v0255); }

v0191:
    v0255 = v0259;
    v0256 = qcdr(v0255);
    v0255 = v0257;
    v0255 = (v0256 == v0255 ? lisp_true : nil);
    v0255 = (v0255 == nil ? lisp_true : nil);
    goto v0075;
// error exit handlers
v0260:
    popv(1);
    return nil;
}



// Code for formop

static LispObject CC_formop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0234, v0101;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formop");
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
    goto v0046;

v0046:
    v0234 = stack[-1];
    if (!consp(v0234)) goto v0013;
    v0234 = stack[-1];
    v0234 = qcar(v0234);
    v0234 = (consp(v0234) ? nil : lisp_true);
    goto v0028;

v0028:
    if (v0234 == nil) goto v0085;
    v0234 = stack[-1];
    v0101 = v0234;
    goto v0027;

v0027:
    v0234 = stack[-2];
    if (v0234 == nil) { popv(4); return onevalue(v0101); }
    v0234 = stack[-2];
    v0234 = qcar(v0234);
    fn = elt(env, 2); // raddf
    v0234 = (*qfn2(fn))(qenv(fn), v0234, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    v0101 = v0234;
    v0234 = stack[-2];
    v0234 = qcdr(v0234);
    stack[-2] = v0234;
    goto v0027;

v0085:
    v0234 = stack[-1];
    v0234 = qcar(v0234);
    stack[0] = qcar(v0234);
    v0234 = stack[-1];
    v0234 = qcar(v0234);
    v0234 = qcdr(v0234);
    v0234 = CC_formop(env, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    fn = elt(env, 3); // multop
    v0101 = (*qfn2(fn))(qenv(fn), stack[0], v0234);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    v0234 = stack[-2];
    v0234 = cons(v0101, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    stack[-2] = v0234;
    v0234 = stack[-1];
    v0234 = qcdr(v0234);
    stack[-1] = v0234;
    goto v0046;

v0013:
    v0234 = qvalue(elt(env, 1)); // t
    goto v0028;
// error exit handlers
v0033:
    popv(4);
    return nil;
}



// Code for leftzeros

static LispObject CC_leftzeros(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0023, v0252;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for leftzeros");
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
    goto v0046;

v0046:
    v0023 = stack[0];
    if (v0023 == nil) goto v0013;
    v0023 = stack[0];
    v0252 = qcar(v0023);
    v0023 = (LispObject)1; // 0
    v0023 = Lneq(nil, v0252, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-2];
    goto v0028;

v0028:
    if (v0023 == nil) goto v0085;
    v0023 = (LispObject)1; // 0
    v0252 = v0023;
    goto v0027;

v0027:
    v0023 = stack[-1];
    if (v0023 == nil) { popv(3); return onevalue(v0252); }
    v0023 = stack[-1];
    v0023 = qcar(v0023);
    v0023 = (LispObject)(int32_t)((int32_t)v0023 + (int32_t)v0252 - TAG_FIXNUM);
    v0252 = v0023;
    v0023 = stack[-1];
    v0023 = qcdr(v0023);
    stack[-1] = v0023;
    goto v0027;

v0085:
    v0252 = (LispObject)17; // 1
    v0023 = stack[-1];
    v0023 = cons(v0252, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-2];
    stack[-1] = v0023;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[0] = v0023;
    goto v0046;

v0013:
    v0023 = qvalue(elt(env, 1)); // t
    goto v0028;
// error exit handlers
v0230:
    popv(3);
    return nil;
}



// Code for !*id2num

static LispObject CC_Hid2num(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0029, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *id2num");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0029 = v0000;
// end of prologue
    v0007 = qvalue(elt(env, 1)); // pair_id_num!*
    v0029 = Lassoc(nil, v0029, v0007);
    v0007 = v0029;
    if (v0029 == nil) goto v0046;
    v0029 = v0007;
    v0029 = qcdr(v0029);
    return onevalue(v0029);

v0046:
    v0029 = nil;
    return onevalue(v0029);
}



// Code for arintequiv!:

static LispObject CC_arintequivT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0246, v0248, v0044;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0044 = v0000;
// end of prologue
    v0246 = v0044;
    v0246 = qcdr(v0246);
    if (is_number(v0246)) goto v0024;
    v0246 = v0044;
    v0246 = qcdr(v0246);
    v0248 = qcar(v0246);
    v0246 = elt(env, 1); // !:rn!:
    if (v0248 == v0246) goto v0078;
    v0246 = qvalue(elt(env, 2)); // nil
    goto v0004;

v0004:
    if (v0246 == nil) goto v0245;
    v0246 = v0044;
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0246 = qcar(v0246);
    return onevalue(v0246);

v0245:
    v0246 = qvalue(elt(env, 2)); // nil
    return onevalue(v0246);

v0078:
    v0246 = v0044;
    v0246 = qcdr(v0246);
    v0246 = qcdr(v0246);
    v0248 = qcdr(v0246);
    v0246 = (LispObject)17; // 1
    v0246 = (v0248 == v0246 ? lisp_true : nil);
    goto v0004;

v0024:
    v0246 = v0044;
    v0246 = qcdr(v0246);
    return onevalue(v0246);
}



// Code for ibalp_atomp

static LispObject CC_ibalp_atomp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0076, v0239;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_atomp");
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
    v0239 = stack[0];
    v0076 = elt(env, 1); // true
    if (v0239 == v0076) goto v0027;
    v0239 = stack[0];
    v0076 = elt(env, 3); // false
    v0076 = (v0239 == v0076 ? lisp_true : nil);
    goto v0030;

v0030:
    if (v0076 == nil) goto v0247;
    v0076 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0076); }

v0247:
    v0076 = stack[0];
    if (!consp(v0076)) goto v0077;
    v0076 = stack[0];
    v0076 = qcar(v0076);
    v0239 = v0076;
    goto v0039;

v0039:
    v0076 = elt(env, 4); // equal
    if (v0239 == v0076) goto v0019;
    v0076 = qvalue(elt(env, 5)); // nil
    { popv(2); return onevalue(v0076); }

v0019:
    v0076 = stack[0];
    fn = elt(env, 6); // ibalp_arg2l
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-1];
    if (symbolp(v0076)) goto v0023;
    v0076 = qvalue(elt(env, 5)); // nil
    { popv(2); return onevalue(v0076); }

v0023:
    v0076 = stack[0];
    fn = elt(env, 7); // ibalp_arg2r
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    v0076 = (is_number(v0076) ? lisp_true : nil);
    { popv(2); return onevalue(v0076); }

v0077:
    v0076 = stack[0];
    v0239 = v0076;
    goto v0039;

v0027:
    v0076 = qvalue(elt(env, 2)); // t
    goto v0030;
// error exit handlers
v0033:
    popv(2);
    return nil;
}



// Code for ps!:minusp!:

static LispObject CC_psTminuspT(LispObject env,
                         LispObject v0000)
{
    LispObject v0103;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0103 = v0000;
// end of prologue
    v0103 = qvalue(elt(env, 1)); // nil
    return onevalue(v0103);
}



// Code for off

static LispObject CC_off(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for off");
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
    v0007 = v0000;
// end of prologue
    stack[0] = v0007;
    goto v0071;

v0071:
    v0007 = stack[0];
    if (v0007 == nil) goto v0003;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 2); // off1
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0071;

v0003:
    v0007 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0007); }
// error exit handlers
v0109:
    popv(2);
    return nil;
}



// Code for addpf

static LispObject CC_addpf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0270, v0271, v0272;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addpf");
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
    stack[0] = nil;
    goto v0046;

v0046:
    v0270 = stack[-2];
    if (v0270 == nil) goto v0004;
    v0270 = stack[-1];
    if (v0270 == nil) goto v0025;
    v0270 = stack[-2];
    v0270 = qcar(v0270);
    v0271 = qcar(v0270);
    v0270 = (LispObject)17; // 1
    if (v0271 == v0270) goto v0241;
    v0270 = stack[-1];
    v0270 = qcar(v0270);
    v0271 = qcar(v0270);
    v0270 = (LispObject)17; // 1
    if (v0271 == v0270) goto v0100;
    v0270 = stack[-2];
    v0270 = qcar(v0270);
    v0271 = qcar(v0270);
    v0270 = stack[-1];
    v0270 = qcar(v0270);
    v0270 = qcar(v0270);
    if (equal(v0271, v0270)) goto v0189;
    v0270 = stack[-2];
    v0270 = qcar(v0270);
    v0271 = qcar(v0270);
    v0270 = stack[-1];
    v0270 = qcar(v0270);
    v0270 = qcar(v0270);
    fn = elt(env, 1); // ordop
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    if (v0270 == nil) goto v0062;
    v0270 = stack[-2];
    v0271 = qcar(v0270);
    v0270 = stack[0];
    v0270 = cons(v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    stack[0] = v0270;
    v0270 = stack[-2];
    v0270 = qcdr(v0270);
    stack[-2] = v0270;
    goto v0046;

v0062:
    v0270 = stack[-1];
    v0271 = qcar(v0270);
    v0270 = stack[0];
    v0270 = cons(v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    stack[0] = v0270;
    v0270 = stack[-1];
    v0270 = qcdr(v0270);
    stack[-1] = v0270;
    goto v0046;

v0189:
    stack[-3] = stack[0];
    v0270 = stack[-2];
    v0270 = qcar(v0270);
    v0271 = qcdr(v0270);
    v0270 = stack[-1];
    v0270 = qcar(v0270);
    v0270 = qcdr(v0270);
    fn = elt(env, 2); // addsq
    stack[0] = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    v0270 = stack[-2];
    v0271 = qcdr(v0270);
    v0270 = stack[-1];
    v0270 = qcdr(v0270);
    v0270 = CC_addpf(env, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    v0271 = stack[0];
    v0272 = v0271;
    v0272 = qcar(v0272);
    if (v0272 == nil) goto v0274;
    v0272 = stack[-2];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0270 = acons(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    goto v0274;

v0274:
    {
        LispObject v0061 = stack[-3];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0061, v0270);
    }

v0100:
    v0271 = stack[-1];
    v0270 = stack[-2];
    fn = elt(env, 4); // addmpf
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    {
        LispObject v0275 = stack[0];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0275, v0270);
    }

v0241:
    v0271 = stack[-2];
    v0270 = stack[-1];
    fn = elt(env, 4); // addmpf
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    {
        LispObject v0276 = stack[0];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0276, v0270);
    }

v0025:
    v0271 = stack[0];
    v0270 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0271, v0270);
    }

v0004:
    v0271 = stack[0];
    v0270 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0271, v0270);
    }
// error exit handlers
v0273:
    popv(5);
    return nil;
}



// Code for cut!:ep

static LispObject CC_cutTep(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0278, v0238;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cut:ep");
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
    v0238 = stack[-2];
    v0278 = elt(env, 1); // !:rd!:
    if (!consp(v0238)) goto v0011;
    v0238 = qcar(v0238);
    if (!(v0238 == v0278)) goto v0011;
    v0278 = stack[-2];
    v0278 = qcdr(v0278);
    v0278 = (consp(v0278) ? nil : lisp_true);
    v0278 = (v0278 == nil ? lisp_true : nil);
    goto v0009;

v0009:
    if (v0278 == nil) goto v0084;
    v0278 = stack[-1];
    v0278 = integerp(v0278);
    goto v0027;

v0027:
    if (v0278 == nil) goto v0279;
    v0238 = stack[-1];
    v0278 = stack[-2];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0238 = difference2(v0238, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-1] = v0238;
    v0278 = (LispObject)1; // 0
    v0278 = (LispObject)lesseq2(v0238, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    v0278 = v0278 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0278 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); // !:rd!:
    v0278 = stack[-2];
    v0278 = qcdr(v0278);
    stack[0] = qcar(v0278);
    v0278 = stack[-1];
    v0278 = negate(v0278);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    fn = elt(env, 3); // ashift
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0278);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    v0278 = stack[-2];
    v0278 = qcdr(v0278);
    v0238 = qcdr(v0278);
    v0278 = stack[-1];
    v0278 = plus2(v0238, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    {
        LispObject v0274 = stack[-3];
        LispObject v0280 = stack[0];
        popv(5);
        return list2star(v0274, v0280, v0278);
    }

v0279:
    v0278 = elt(env, 0); // cut!:ep
    {
        popv(5);
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(qenv(fn), v0278);
    }

v0084:
    v0278 = qvalue(elt(env, 2)); // nil
    goto v0027;

v0011:
    v0278 = qvalue(elt(env, 2)); // nil
    goto v0009;
// error exit handlers
v0073:
    popv(5);
    return nil;
}



// Code for contr1!-strand

static LispObject CC_contr1Kstrand(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0006, v0242, v0029, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contr1-strand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0001;
    v0242 = v0000;
// end of prologue
    v0007 = v0242;
    v0029 = v0006;
    v0242 = qvalue(elt(env, 1)); // nil
    v0006 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // contr2!-strand
        return (*qfnn(fn))(qenv(fn), 4, v0007, v0029, v0242, v0006);
    }
}



// Code for scan

static LispObject CC_scan(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0365, v0366, v0367;
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
    v0366 = qvalue(elt(env, 1)); // cursym!*
    v0365 = elt(env, 2); // !*semicol!*
    if (!(v0366 == v0365)) goto v0030;

v0046:
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0365; // escaped!*
    fn = elt(env, 43); // token
    v0365 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    goto v0030;

v0030:
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (!consp(v0365)) goto v0246;
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 44); // toknump
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0365 = (v0365 == nil ? lisp_true : nil);
    goto v0228;

v0228:
    if (v0365 == nil) goto v0017;
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    v0366 = qcar(v0365);
    v0365 = elt(env, 41); // string
    if (!(v0366 == v0365)) goto v0029;
    v0365 = elt(env, 42); // " "
    fn = elt(env, 45); // prin2x
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = qcdr(v0365);
    v0365 = qcar(v0365);
    v0365 = Lmkquote(nil, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    v0365 = qcdr(v0365);
    v0365 = qcar(v0365);
    fn = elt(env, 45); // prin2x
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    goto v0029;

v0029:
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    qvalue(elt(env, 1)) = v0365; // cursym!*
    v0365 = qvalue(elt(env, 4)); // escaped!*
    qvalue(elt(env, 22)) = v0365; // curescaped!*
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0365; // escaped!*
    fn = elt(env, 43); // token
    v0365 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = qvalue(elt(env, 25)); // !$eof!$
    if (v0366 == v0365) goto v0369;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0370;

v0370:
    if (v0365 == nil) goto v0007;
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0007:
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (is_number(v0365)) goto v0371;
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (!consp(v0365)) goto v0372;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0373;

v0373:
    if (!(v0365 == nil)) goto v0371;

v0374:
    v0365 = qvalue(elt(env, 1)); // cursym!*
    {
        popv(4);
        fn = elt(env, 47); // addcomment
        return (*qfn1(fn))(qenv(fn), v0365);
    }

v0371:
    v0365 = elt(env, 42); // " "
    fn = elt(env, 45); // prin2x
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    goto v0374;

v0372:
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v0365)) v0365 = nil;
    else { v0365 = qfastgets(v0365);
           if (v0365 != nil) { v0365 = elt(v0365, 11); // switch!*
#ifdef RECORD_GET
             if (v0365 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0365 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0365 == SPID_NOPROP) v0365 = nil; }}
#endif
    v0365 = (v0365 == nil ? lisp_true : nil);
    goto v0373;

v0369:
    v0366 = qvalue(elt(env, 14)); // ttype!*
    v0365 = (LispObject)49; // 3
    v0365 = (v0366 == v0365 ? lisp_true : nil);
    goto v0370;

v0017:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 6); // else
    if (v0366 == v0365) goto v0016;
    v0366 = qvalue(elt(env, 1)); // cursym!*
    v0365 = elt(env, 2); // !*semicol!*
    v0365 = (v0366 == v0365 ? lisp_true : nil);
    goto v0375;

v0375:
    if (v0365 == nil) goto v0247;
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 8)) = v0365; // outl!*
    goto v0247;

v0247:
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 45); // prin2x
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    goto v0027;

v0027:
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (!(symbolp(v0365))) goto v0029;
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v0365)) v0365 = nil;
    else { v0365 = qfastgets(v0365);
           if (v0365 != nil) { v0365 = elt(v0365, 28); // newnam
#ifdef RECORD_GET
             if (v0365 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v0365 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v0365 == SPID_NOPROP) v0365 = nil; }}
#endif
    stack[-1] = v0365;
    if (v0365 == nil) goto v0274;
    v0366 = stack[-1];
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (equal(v0366, v0365)) goto v0274;
    v0365 = stack[-1];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    v0365 = stack[-1];
    v0365 = Lstringp(nil, v0365);
    env = stack[-3];
    if (!(v0365 == nil)) goto v0029;
    v0365 = stack[-1];
    if (!consp(v0365)) goto v0027;
    else goto v0029;

v0274:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 9); // comment
    if (v0366 == v0365) goto v0072;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 10); // !C!O!M!M!E!N!T
    if (v0366 == v0365) goto v0237;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 11); // !Comment
    v0365 = (v0366 == v0365 ? lisp_true : nil);
    goto v0189;

v0189:
    if (v0365 == nil) goto v0267;
    v0365 = elt(env, 9); // comment
    fn = elt(env, 48); // read!-comment1
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    stack[-1] = v0365;
    v0365 = qvalue(elt(env, 12)); // !*comment
    if (v0365 == nil) goto v0046;
    else { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0267:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 13); // !%
    if (v0366 == v0365) goto v0091;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0066;

v0066:
    if (v0365 == nil) goto v0063;
    v0365 = elt(env, 15); // percent_comment
    fn = elt(env, 48); // read!-comment1
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    stack[-1] = v0365;
    v0365 = qvalue(elt(env, 12)); // !*comment
    if (v0365 == nil) goto v0046;
    else { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0063:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 16); // !#if
    if (v0366 == v0365) goto v0376;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 17); // !#else
    if (v0366 == v0365) goto v0272;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 18); // !#elif
    v0365 = (v0366 == v0365 ? lisp_true : nil);
    goto v0271;

v0271:
    if (v0365 == nil) goto v0377;
    v0365 = qvalue(elt(env, 3)); // nil
    stack[-2] = v0365;
    stack[-1] = v0365;
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    goto v0378;

v0378:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 30); // !#
    if (v0366 == v0365) goto v0379;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0380;

v0380:
    if (v0365 == nil) goto v0381;
    fn = elt(env, 43); // token
    v0365 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    v0366 = qvalue(elt(env, 14)); // ttype!*
    v0365 = (LispObject)1; // 0
    if (!(v0366 == v0365)) goto v0381;
    stack[0] = elt(env, 30); // !#
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = Lexplodec(nil, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0365 = cons(stack[0], v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    fn = elt(env, 49); // list2string
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0365 = Lintern(nil, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    goto v0381;

v0381:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 19); // !#endif
    if (v0366 == v0365) goto v0382;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 16); // !#if
    if (v0366 == v0365) goto v0383;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 17); // !#else
    if (v0366 == v0365) goto v0384;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0385;

v0385:
    if (!(v0365 == nil)) goto v0046;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 18); // !#elif
    if (v0366 == v0365) goto v0386;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0387;

v0387:
    if (!(v0365 == nil)) goto v0376;

v0388:
    fn = elt(env, 43); // token
    v0365 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    v0366 = qvalue(elt(env, 14)); // ttype!*
    v0365 = (LispObject)49; // 3
    if (v0366 == v0365) goto v0389;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0390;

v0390:
    if (v0365 == nil) goto v0378;
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0389:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = qvalue(elt(env, 25)); // !$eof!$
    v0365 = (v0366 == v0365 ? lisp_true : nil);
    goto v0390;

v0376:
    fn = elt(env, 50); // rread
    v0367 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0366 = qvalue(elt(env, 21)); // !*backtrace
    v0365 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 51); // errorset
    v0365 = (*qfnn(fn))(qenv(fn), 3, v0367, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    stack[-1] = v0365;
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0365; // escaped!*
    qvalue(elt(env, 22)) = v0365; // curescaped!*
    v0365 = stack[-1];
    fn = elt(env, 52); // errorp
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    if (v0365 == nil) goto v0391;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0392;

v0392:
    if (!(v0365 == nil)) goto v0046;
    v0365 = qvalue(elt(env, 3)); // nil
    stack[-1] = v0365;
    v0365 = qvalue(elt(env, 7)); // t
    stack[-2] = v0365;
    goto v0378;

v0391:
    v0365 = stack[-1];
    v0365 = qcar(v0365);
    goto v0392;

v0386:
    v0365 = stack[-1];
    if (v0365 == nil) goto v0393;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0387;

v0393:
    v0365 = stack[-2];
    goto v0387;

v0384:
    v0365 = stack[-1];
    if (v0365 == nil) goto v0394;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0385;

v0394:
    v0365 = stack[-2];
    goto v0385;

v0383:
    v0366 = qvalue(elt(env, 3)); // nil
    v0365 = stack[-1];
    v0365 = cons(v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    stack[-1] = v0365;
    goto v0388;

v0382:
    v0365 = stack[-1];
    if (v0365 == nil) goto v0046;
    v0365 = stack[-1];
    v0365 = qcdr(v0365);
    stack[-1] = v0365;
    goto v0388;

v0379:
    v0366 = qvalue(elt(env, 14)); // ttype!*
    v0365 = (LispObject)49; // 3
    if (v0366 == v0365) goto v0395;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0380;

v0395:
    v0365 = qvalue(elt(env, 31)); // crchar!*
    v0365 = Lwhitespace_char_p(nil, v0365);
    env = stack[-3];
    v0365 = (v0365 == nil ? lisp_true : nil);
    goto v0380;

v0377:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 19); // !#endif
    if (v0366 == v0365) goto v0046;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 20); // !#eval
    if (v0366 == v0365) goto v0396;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 23); // !#define
    if (v0366 == v0365) goto v0397;
    v0366 = qvalue(elt(env, 14)); // ttype!*
    v0365 = (LispObject)49; // 3
    if (!(v0366 == v0365)) goto v0029;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = qvalue(elt(env, 25)); // !$eof!$
    if (v0366 == v0365) goto v0398;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 26); // !'
    if (v0366 == v0365) goto v0399;
    v0365 = qvalue(elt(env, 28)); // !*eoldelimp
    if (v0365 == nil) goto v0400;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = qvalue(elt(env, 29)); // !$eol!$
    if (!(v0366 == v0365)) goto v0400;

v0005:
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    qvalue(elt(env, 40)) = v0365; // semic!*
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 22)) = v0365; // curescaped!*
    v0365 = elt(env, 2); // !*semicol!*
    {
        popv(4);
        fn = elt(env, 47); // addcomment
        return (*qfn1(fn))(qenv(fn), v0365);
    }

v0400:
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 30); // !#
    if (v0366 == v0365) goto v0227;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0401;

v0401:
    if (v0365 == nil) goto v0402;
    v0365 = qvalue(elt(env, 3)); // nil
    stack[-2] = v0365;
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v0365)) v0365 = nil;
    else { v0365 = qfastgets(v0365);
           if (v0365 != nil) { v0365 = elt(v0365, 11); // switch!*
#ifdef RECORD_GET
             if (v0365 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0365 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0365 == SPID_NOPROP) v0365 = nil; }}
#endif
    stack[-1] = v0365;
    fn = elt(env, 43); // token
    v0365 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 35); // if
    if (v0366 == v0365) goto v0403;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 6); // else
    if (v0366 == v0365) goto v0404;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 36); // elif
    if (v0366 == v0365) goto v0405;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 37); // endif
    if (v0366 == v0365) goto v0406;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 38); // eval
    if (v0366 == v0365) goto v0121;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = elt(env, 39); // define
    v0365 = (v0366 == v0365 ? lisp_true : nil);
    goto v0407;

v0407:
    if (v0365 == nil) goto v0408;
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 45); // prin2x
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    stack[0] = elt(env, 30); // !#
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = Lexplodec(nil, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0365 = cons(stack[0], v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    fn = elt(env, 49); // list2string
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0365 = Lintern(nil, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    goto v0027;

v0408:
    v0366 = qvalue(elt(env, 14)); // ttype!*
    v0365 = (LispObject)49; // 3
    if (!(v0366 == v0365)) goto v0020;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = qvalue(elt(env, 25)); // !$eof!$
    if (v0366 == v0365) goto v0409;
    v0365 = stack[-1];
    v0365 = qcar(v0365);
    if (!(v0365 == nil)) goto v0002;

v0020:
    v0365 = stack[-1];
    v0365 = qcdr(v0365);
    v0365 = qcar(v0365);
    qvalue(elt(env, 1)) = v0365; // cursym!*
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 22)) = v0365; // curescaped!*
    v0366 = qvalue(elt(env, 1)); // cursym!*
    v0365 = elt(env, 32); // !*rpar!*
    if (v0366 == v0365) goto v0007;
    v0365 = qvalue(elt(env, 1)); // cursym!*
    {
        popv(4);
        fn = elt(env, 47); // addcomment
        return (*qfn1(fn))(qenv(fn), v0365);
    }

v0002:
    v0365 = stack[-2];
    if (!(v0365 == nil)) goto v0020;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = stack[-1];
    v0365 = qcar(v0365);
    v0365 = Latsoc(nil, v0366, v0365);
    stack[0] = v0365;
    if (v0365 == nil) goto v0020;
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 45); // prin2x
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0365 = stack[0];
    v0365 = qcdr(v0365);
    stack[-1] = v0365;
    v0365 = stack[-1];
    v0365 = qcar(v0365);
    if (v0365 == nil) goto v0410;
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0411;

v0411:
    if (v0365 == nil) goto v0003;
    fn = elt(env, 53); // read!-comment
    v0365 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 34)) = v0365; // comment!*
    goto v0046;

v0003:
    fn = elt(env, 43); // token
    v0365 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0365; // nxtsym!*
    v0366 = qvalue(elt(env, 14)); // ttype!*
    v0365 = (LispObject)49; // 3
    if (!(v0366 == v0365)) goto v0020;
    v0366 = qvalue(elt(env, 5)); // nxtsym!*
    v0365 = qvalue(elt(env, 25)); // !$eof!$
    if (v0366 == v0365) goto v0412;
    v0365 = stack[-1];
    v0365 = qcar(v0365);
    if (v0365 == nil) goto v0020;
    else goto v0002;

v0412:
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0410:
    v0365 = stack[-1];
    v0365 = qcdr(v0365);
    v0366 = qcar(v0365);
    v0365 = elt(env, 33); // !*comment!*
    v0365 = (v0366 == v0365 ? lisp_true : nil);
    goto v0411;

v0409:
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0121:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0407;

v0406:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0407;

v0405:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0407;

v0404:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0407;

v0403:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0407;

v0402:
    v0365 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v0365)) v0365 = nil;
    else { v0365 = qfastgets(v0365);
           if (v0365 != nil) { v0365 = elt(v0365, 11); // switch!*
#ifdef RECORD_GET
             if (v0365 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0365 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0365 == SPID_NOPROP) v0365 = nil; }}
#endif
    stack[-1] = v0365;
    if (v0365 == nil) goto v0029;
    v0365 = stack[-1];
    v0366 = qcdr(v0365);
    v0365 = elt(env, 2); // !*semicol!*
    if (!consp(v0366)) goto v0035;
    v0366 = qcar(v0366);
    if (v0366 == v0365) goto v0005;
    else goto v0035;

v0035:
    v0365 = qvalue(elt(env, 31)); // crchar!*
    v0365 = Lwhitespace_char_p(nil, v0365);
    env = stack[-3];
    stack[-2] = v0365;
    goto v0003;

v0227:
    v0365 = qvalue(elt(env, 31)); // crchar!*
    v0365 = Lwhitespace_char_p(nil, v0365);
    env = stack[-3];
    v0365 = (v0365 == nil ? lisp_true : nil);
    goto v0401;

v0399:
    v0365 = elt(env, 27); // "Invalid QUOTE"
    fn = elt(env, 54); // rederr
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    goto v0035;

v0398:
    {
        popv(4);
        fn = elt(env, 46); // filenderr
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0397:
    fn = elt(env, 50); // rread
    v0367 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0366 = qvalue(elt(env, 21)); // !*backtrace
    v0365 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 51); // errorset
    v0365 = (*qfnn(fn))(qenv(fn), 3, v0367, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    stack[-1] = v0365;
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0365; // escaped!*
    qvalue(elt(env, 22)) = v0365; // curescaped!*
    v0365 = stack[-1];
    fn = elt(env, 52); // errorp
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    if (!(v0365 == nil)) goto v0046;
    fn = elt(env, 50); // rread
    v0367 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0366 = qvalue(elt(env, 21)); // !*backtrace
    v0365 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 51); // errorset
    v0365 = (*qfnn(fn))(qenv(fn), 3, v0367, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    stack[0] = v0365;
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0365; // escaped!*
    qvalue(elt(env, 22)) = v0365; // curescaped!*
    v0365 = stack[0];
    fn = elt(env, 52); // errorp
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    if (!(v0365 == nil)) goto v0046;
    v0367 = stack[-1];
    v0366 = elt(env, 24); // newnam
    v0365 = stack[0];
    v0365 = Lputprop(nil, 3, v0367, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    goto v0046;

v0396:
    fn = elt(env, 50); // rread
    v0367 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0366 = qvalue(elt(env, 21)); // !*backtrace
    v0365 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 51); // errorset
    v0365 = (*qfnn(fn))(qenv(fn), 3, v0367, v0366, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    v0365 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0365; // escaped!*
    qvalue(elt(env, 22)) = v0365; // curescaped!*
    goto v0046;

v0272:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0271;

v0091:
    v0366 = qvalue(elt(env, 14)); // ttype!*
    v0365 = (LispObject)49; // 3
    v0365 = (v0366 == v0365 ? lisp_true : nil);
    goto v0066;

v0237:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0189;

v0072:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0189;

v0016:
    v0365 = qvalue(elt(env, 7)); // t
    goto v0375;

v0246:
    v0365 = qvalue(elt(env, 3)); // nil
    goto v0228;
// error exit handlers
v0368:
    popv(4);
    return nil;
}



// Code for multop

static LispObject CC_multop(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0194, v0246, v0248;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multop");
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
    v0248 = v0000;
// end of prologue
    v0194 = qvalue(elt(env, 1)); // kord!*
    if (v0194 == nil) goto v0005;
    v0194 = v0248;
    v0246 = qcar(v0194);
    v0194 = elt(env, 2); // k!*
    if (v0246 == v0194) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0246 = v0248;
    v0194 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); // rmultpf
        return (*qfn2(fn))(qenv(fn), v0246, v0194);
    }

v0005:
    v0246 = v0248;
    v0194 = (LispObject)17; // 1
    v0194 = cons(v0246, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-1];
    v0246 = ncons(v0194);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-1];
    v0194 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // multf
        return (*qfn2(fn))(qenv(fn), v0246, v0194);
    }
// error exit handlers
v0240:
    popv(2);
    return nil;
}



// Code for red_divtest

static LispObject CC_red_divtest(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0085, v0084;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_divtest");
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

v0071:
    v0085 = stack[-1];
    if (v0085 == nil) goto v0027;
    v0085 = stack[-1];
    v0085 = qcar(v0085);
    fn = elt(env, 2); // bas_dpoly
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v0084 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    v0085 = stack[0];
    fn = elt(env, 4); // mo_vdivides!?
    v0085 = (*qfn2(fn))(qenv(fn), v0084, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    if (v0085 == nil) goto v0011;
    v0085 = stack[-1];
    v0085 = qcar(v0085);
    { popv(3); return onevalue(v0085); }

v0011:
    v0085 = stack[-1];
    v0085 = qcdr(v0085);
    stack[-1] = v0085;
    goto v0071;

v0027:
    v0085 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0085); }
// error exit handlers
v0247:
    popv(3);
    return nil;
}



// Code for prepsq!*2

static LispObject CC_prepsqH2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028, v0013, v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq*2");
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
    v0028 = v0000;
// end of prologue
    v0005 = v0028;
    v0013 = (LispObject)17; // 1
    v0028 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // prepsq!*1
    v0028 = (*qfnn(fn))(qenv(fn), 3, v0005, v0013, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // replus
        return (*qfn1(fn))(qenv(fn), v0028);
    }
// error exit handlers
v0006:
    popv(1);
    return nil;
}



// Code for qqe_number!-of!-tails!-in!-qterm

static LispObject CC_qqe_numberKofKtailsKinKqterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0074, v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_number-of-tails-in-qterm");
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

v0024:
    v0074 = stack[0];
    if (!consp(v0074)) goto v0030;
    v0074 = stack[0];
    fn = elt(env, 2); // qqe_op
    v0085 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    v0074 = elt(env, 1); // (ladd radd)
    v0074 = Lmemq(nil, v0085, v0074);
    if (v0074 == nil) goto v0025;
    v0074 = stack[0];
    fn = elt(env, 3); // qqe_arg2r
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    stack[0] = v0074;
    goto v0024;

v0025:
    v0074 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    v0074 = CC_qqe_numberKofKtailsKinKqterm(env, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    popv(2);
    return add1(v0074);

v0030:
    v0074 = (LispObject)1; // 0
    { popv(2); return onevalue(v0074); }
// error exit handlers
v0019:
    popv(2);
    return nil;
}



// Code for quotfx

static LispObject CC_quotfx(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0247, v0038, v0039;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0038 = v0001;
    v0039 = v0000;
// end of prologue
    v0247 = qvalue(elt(env, 1)); // !*exp
    if (v0247 == nil) goto v0003;
    v0247 = qvalue(elt(env, 3)); // !*mcd
    v0247 = (v0247 == nil ? lisp_true : nil);
    goto v0027;

v0027:
    if (v0247 == nil) goto v0012;
    v0247 = v0039;
    {
        fn = elt(env, 4); // quotf
        return (*qfn2(fn))(qenv(fn), v0247, v0038);
    }

v0012:
    v0247 = v0039;
    {
        fn = elt(env, 5); // quotfx1
        return (*qfn2(fn))(qenv(fn), v0247, v0038);
    }

v0003:
    v0247 = qvalue(elt(env, 2)); // t
    goto v0027;
}



// Code for ibalp_vmember

static LispObject CC_ibalp_vmember(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0084, v0019;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_vmember");
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

v0111:
    v0084 = stack[0];
    if (v0084 == nil) goto v0071;
    v0019 = stack[-1];
    v0084 = stack[0];
    v0084 = qcar(v0084);
    fn = elt(env, 2); // ibalp_vequal
    v0084 = (*qfn2(fn))(qenv(fn), v0019, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    if (!(v0084 == nil)) { popv(3); return onevalue(v0084); }
    v0019 = stack[-1];
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    stack[-1] = v0019;
    stack[0] = v0084;
    goto v0111;

v0071:
    v0084 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0084); }
// error exit handlers
v0038:
    popv(3);
    return nil;
}



// Code for basicom

static LispObject CC_basicom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0074;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for basicom");
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
    v0074 = stack[0];
    if (is_number(v0074)) goto v0046;
    v0074 = stack[0];
    if (!(symbolp(v0074))) goto v0071;
    v0074 = stack[0];
    fn = elt(env, 1); // variableom
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    goto v0071;

v0071:
    v0074 = nil;
    { popv(2); return onevalue(v0074); }

v0046:
    v0074 = stack[0];
    v0074 = integerp(v0074);
    if (v0074 == nil) goto v0020;
    v0074 = stack[0];
    fn = elt(env, 2); // integerom
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    goto v0020;

v0020:
    v0074 = stack[0];
    v0074 = Lfloatp(nil, v0074);
    env = stack[-1];
    if (v0074 == nil) goto v0071;
    v0074 = stack[0];
    fn = elt(env, 3); // floatom
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    goto v0071;
// error exit handlers
v0084:
    popv(2);
    return nil;
}



// Code for smtp

static LispObject CC_smtp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0418, v0178, v0058, v0059;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smtp");
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
    stack[-6] = v0001;
    stack[0] = v0000;
// end of prologue
    v0418 = stack[0];
    if (!consp(v0418)) goto v0005;
    v0178 = stack[0];
    v0418 = elt(env, 1); // sparsemat
    if (!consp(v0178)) goto v0194;
    v0178 = qcar(v0178);
    if (!(v0178 == v0418)) goto v0194;
    v0418 = stack[0];
    stack[-7] = v0418;
    v0418 = stack[-7];
    v0418 = qcdr(v0418);
    v0418 = qcdr(v0418);
    v0418 = qcar(v0418);
    v0178 = v0418;
    goto v0013;

v0013:
    v0418 = v0178;
    v0418 = qcdr(v0418);
    v0418 = qcar(v0418);
    stack[-4] = v0418;
    v0418 = v0178;
    v0418 = qcdr(v0418);
    v0418 = qcdr(v0418);
    v0418 = qcar(v0418);
    stack[-1] = v0418;
    v0058 = elt(env, 2); // spm
    v0178 = v0418;
    v0418 = stack[-4];
    v0418 = list3(v0058, v0178, v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    fn = elt(env, 7); // mkempspmat
    v0418 = (*qfn2(fn))(qenv(fn), stack[-1], v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    stack[-5] = v0418;
    v0178 = stack[-7];
    v0418 = elt(env, 1); // sparsemat
    if (!consp(v0178)) goto v0188;
    v0178 = qcar(v0178);
    if (!(v0178 == v0418)) goto v0188;
    v0418 = (LispObject)17; // 1
    stack[-1] = v0418;
    goto v0249;

v0249:
    v0178 = stack[-4];
    v0418 = stack[-1];
    v0418 = difference2(v0178, v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    v0418 = Lminusp(nil, v0418);
    env = stack[-8];
    if (!(v0418 == nil)) { LispObject res = stack[-5]; popv(9); return onevalue(res); }
    v0178 = stack[-7];
    v0418 = stack[-1];
    fn = elt(env, 8); // findrow
    v0418 = (*qfn2(fn))(qenv(fn), v0178, v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    v0178 = v0418;
    v0418 = v0178;
    if (v0418 == nil) goto v0268;
    v0418 = stack[-1];
    stack[-3] = v0418;
    v0418 = v0178;
    v0418 = qcdr(v0418);
    stack[0] = v0418;
    goto v0184;

v0184:
    v0418 = stack[0];
    if (v0418 == nil) goto v0268;
    v0418 = stack[0];
    v0418 = qcar(v0418);
    v0178 = v0418;
    v0418 = v0178;
    v0418 = qcar(v0418);
    v0178 = qcdr(v0178);
    stack[-2] = v0178;
    v0058 = stack[-5];
    v0178 = v0418;
    v0418 = stack[-3];
    v0059 = list3(v0058, v0178, v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    v0058 = stack[-2];
    v0178 = stack[-5];
    v0418 = stack[-6];
    fn = elt(env, 9); // letmtr3
    v0418 = (*qfnn(fn))(qenv(fn), 4, v0059, v0058, v0178, v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    v0418 = stack[0];
    v0418 = qcdr(v0418);
    stack[0] = v0418;
    goto v0184;

v0268:
    v0418 = stack[-1];
    v0418 = add1(v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    stack[-1] = v0418;
    goto v0249;

v0188:
    stack[-2] = elt(env, 3); // matrix
    stack[-1] = (LispObject)33; // 2
    v0058 = elt(env, 4); // "Matrix"
    v0178 = stack[0];
    v0418 = elt(env, 5); // "not set"
    v0418 = list3(v0058, v0178, v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    fn = elt(env, 10); // rerror
    v0418 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    { LispObject res = stack[-5]; popv(9); return onevalue(res); }

v0194:
    v0418 = stack[0];
    v0418 = qcdr(v0418);
    v0178 = qcar(v0418);
    v0418 = stack[-6];
    v0418 = CC_smtp(env, v0178, v0418);
    nil = C_nil;
    if (exception_pending()) goto v0419;
    env = stack[-8];
    stack[-7] = v0418;
    v0418 = stack[-7];
    v0418 = qcdr(v0418);
    v0418 = qcdr(v0418);
    v0418 = qcar(v0418);
    v0178 = v0418;
    goto v0013;

v0005:
    v0418 = stack[0];
    if (!symbolp(v0418)) v0418 = nil;
    else { v0418 = qfastgets(v0418);
           if (v0418 != nil) { v0418 = elt(v0418, 4); // avalue
#ifdef RECORD_GET
             if (v0418 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0418 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0418 == SPID_NOPROP) v0418 = nil; }}
#endif
    v0418 = qcdr(v0418);
    v0418 = qcar(v0418);
    stack[-7] = v0418;
    v0418 = stack[-7];
    v0418 = qcdr(v0418);
    v0418 = qcdr(v0418);
    v0418 = qcar(v0418);
    v0178 = v0418;
    goto v0013;
// error exit handlers
v0419:
    popv(9);
    return nil;
}



// Code for initwght

static LispObject CC_initwght(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0256, v0257;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for initwght");
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
    stack[-3] = v0000;
// end of prologue
    v0256 = (LispObject)1; // 0
    stack[-5] = v0256;
    stack[0] = v0256;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0257 = qvalue(elt(env, 2)); // maxvar
    v0256 = stack[-3];
    v0256 = plus2(v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    v0257 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0256/(16/CELL)));
    v0256 = (LispObject)65; // 4
    v0256 = *(LispObject *)((char *)v0257 + (CELL-TAG_VECTOR) + ((int32_t)v0256/(16/CELL)));
    stack[-4] = v0256;
    goto v0020;

v0020:
    v0256 = stack[-4];
    if (v0256 == nil) goto v0031;
    v0256 = stack[-4];
    v0256 = qcar(v0256);
    stack[-2] = v0256;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0257 = qvalue(elt(env, 2)); // maxvar
    v0256 = stack[-2];
    v0256 = qcar(v0256);
    v0256 = plus2(v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    v0257 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0256/(16/CELL)));
    v0256 = (LispObject)1; // 0
    v0256 = *(LispObject *)((char *)v0257 + (CELL-TAG_VECTOR) + ((int32_t)v0256/(16/CELL)));
    if (v0256 == nil) goto v0245;
    v0256 = stack[-2];
    v0256 = qcdr(v0256);
    v0256 = qcar(v0256);
    fn = elt(env, 4); // dm!-abs
    v0256 = (*qfn1(fn))(qenv(fn), v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    fn = elt(env, 5); // !:onep
    v0256 = (*qfn1(fn))(qenv(fn), v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    if (!(v0256 == nil)) goto v0034;
    v0256 = stack[-5];
    v0256 = add1(v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    stack[-5] = v0256;
    goto v0034;

v0034:
    v0256 = stack[0];
    v0256 = add1(v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    stack[0] = v0256;
    goto v0245;

v0245:
    v0256 = stack[-4];
    v0256 = qcdr(v0256);
    stack[-4] = v0256;
    goto v0020;

v0031:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0257 = qvalue(elt(env, 2)); // maxvar
    v0256 = stack[-3];
    v0256 = plus2(v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    stack[-4] = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0256/(16/CELL)));
    stack[-3] = (LispObject)17; // 1
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v0257 = (LispObject)49; // 3
    v0256 = stack[-5];
    v0256 = times2(v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    v0256 = plus2(stack[0], v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    env = stack[-6];
    v0256 = acons(stack[-2], stack[-1], v0256);
    nil = C_nil;
    if (exception_pending()) goto v0420;
    *(LispObject *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v0256;
    v0256 = nil;
    { popv(7); return onevalue(v0256); }
// error exit handlers
v0420:
    popv(7);
    return nil;
}



// Code for convchk

static LispObject CC_convchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0252, v0075, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convchk");
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
    v0252 = v0000;
// end of prologue
    v0075 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v0075 == nil) goto v0071;
    v0075 = v0252;
    if (!(!consp(v0075))) { popv(1); return onevalue(v0252); }
    v0075 = v0252;
    v0075 = Lfloatp(nil, v0075);
    env = stack[0];
    if (v0075 == nil) goto v0007;
    {
        popv(1);
        fn = elt(env, 3); // fl2bf
        return (*qfn1(fn))(qenv(fn), v0252);
    }

v0007:
    v0075 = v0252;
    if (!(!consp(v0075))) goto v0025;
    v0075 = v0252;
    v0075 = integerp(v0075);
    if (v0075 == nil) goto v0193;
    v0026 = elt(env, 2); // !:rd!:
    v0075 = v0252;
    v0252 = (LispObject)1; // 0
    v0252 = list2star(v0026, v0075, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[0];
    goto v0025;

v0025:
    {
        popv(1);
        fn = elt(env, 4); // normbf
        return (*qfn1(fn))(qenv(fn), v0252);
    }

v0193:
    fn = elt(env, 5); // read!:num
    v0252 = (*qfn1(fn))(qenv(fn), v0252);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[0];
    goto v0025;

v0071:
    v0075 = v0252;
    if (!consp(v0075)) { popv(1); return onevalue(v0252); }
    {
        popv(1);
        fn = elt(env, 6); // bf2flck
        return (*qfn1(fn))(qenv(fn), v0252);
    }
// error exit handlers
v0230:
    popv(1);
    return nil;
}



// Code for split!-road

static LispObject CC_splitKroad(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0193, v0194, v0246;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split-road");
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
    v0193 = stack[-1];
    stack[-3] = qcar(v0193);
    v0193 = stack[-2];
    v0246 = qcar(v0193);
    v0193 = stack[-2];
    v0194 = qcdr(v0193);
    v0193 = stack[-1];
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    fn = elt(env, 1); // sroad
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0246, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-4];
    v0193 = stack[-2];
    v0246 = qcar(v0193);
    v0193 = stack[-2];
    v0194 = qcdr(v0193);
    v0193 = stack[-1];
    v0193 = qcdr(v0193);
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    fn = elt(env, 1); // sroad
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0246, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    {
        LispObject v0375 = stack[-3];
        LispObject v0016 = stack[0];
        popv(5);
        return list3(v0375, v0016, v0193);
    }
// error exit handlers
v0277:
    popv(5);
    return nil;
}



// Code for condterpri

static LispObject CC_condterpri(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0023;
    argcheck(nargs, 0, "condterpri");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for condterpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0023 = qvalue(elt(env, 1)); // !*output
    if (v0023 == nil) goto v0103;
    v0023 = qvalue(elt(env, 3)); // !*echo
    if (v0023 == nil) goto v0002;
    v0023 = qvalue(elt(env, 4)); // !*extraecho
    if (v0023 == nil) goto v0029;
    v0023 = qvalue(elt(env, 5)); // !*int
    if (v0023 == nil) goto v0085;
    v0023 = qvalue(elt(env, 7)); // ifl!*
    goto v0074;

v0074:
    if (v0023 == nil) goto v0011;
    v0023 = qvalue(elt(env, 8)); // !*defn
    if (v0023 == nil) goto v0245;
    v0023 = qvalue(elt(env, 2)); // nil
    return onevalue(v0023);

v0245:
    v0023 = qvalue(elt(env, 9)); // !*demo
    if (v0023 == nil) goto v0044;
    v0023 = qvalue(elt(env, 2)); // nil
    return onevalue(v0023);

v0044:
        return Lterpri(nil, 0);

v0011:
    v0023 = qvalue(elt(env, 2)); // nil
    return onevalue(v0023);

v0085:
    v0023 = qvalue(elt(env, 6)); // t
    goto v0074;

v0029:
    v0023 = qvalue(elt(env, 2)); // nil
    return onevalue(v0023);

v0002:
    v0023 = qvalue(elt(env, 2)); // nil
    return onevalue(v0023);

v0103:
    v0023 = qvalue(elt(env, 2)); // nil
    return onevalue(v0023);
}



// Code for red!-weight!-less!-p

static LispObject CC_redKweightKlessKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0102, v0228, v0261, v0254;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-weight-less-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0228 = v0001;
    v0261 = v0000;
// end of prologue
    v0102 = v0261;
    v0254 = qcar(v0102);
    v0102 = v0228;
    v0102 = qcar(v0102);
    if (equal(v0254, v0102)) goto v0006;
    v0102 = v0261;
    v0102 = qcar(v0102);
    v0228 = qcar(v0228);
        return Llessp(nil, v0102, v0228);

v0006:
    v0102 = v0261;
    v0102 = qcdr(v0102);
    v0228 = qcdr(v0228);
        return Llessp(nil, v0102, v0228);
}



// Code for pv_neg

static LispObject CC_pv_neg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0247, v0038, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_neg");
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
    goto v0030;

v0030:
    v0247 = stack[0];
    if (v0247 == nil) goto v0046;
    v0247 = stack[0];
    v0247 = qcar(v0247);
    v0247 = qcar(v0247);
    v0039 = negate(v0247);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-2];
    v0247 = stack[0];
    v0247 = qcar(v0247);
    v0038 = qcdr(v0247);
    v0247 = stack[-1];
    v0247 = acons(v0039, v0038, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-2];
    stack[-1] = v0247;
    v0247 = stack[0];
    v0247 = qcdr(v0247);
    stack[0] = v0247;
    goto v0030;

v0046:
    v0247 = stack[-1];
        popv(3);
        return Lnreverse(nil, v0247);
// error exit handlers
v0261:
    popv(3);
    return nil;
}



// Code for exceeds!-order

static LispObject CC_exceedsKorder(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0231, v0234;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exceeds-order");
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

v0111:
    v0231 = stack[-1];
    if (v0231 == nil) goto v0071;
    v0231 = stack[0];
    v0231 = qcar(v0231);
    stack[-2] = v0231;
    v0231 = (LispObject)1; // 0
    v0234 = v0231;
    goto v0078;

v0078:
    v0231 = stack[-2];
    if (v0231 == nil) goto v0085;
    v0231 = stack[-2];
    v0231 = qcar(v0231);
    fn = elt(env, 3); // tayexp!-plus2
    v0231 = (*qfn2(fn))(qenv(fn), v0231, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0234 = v0231;
    v0231 = stack[-2];
    v0231 = qcdr(v0231);
    stack[-2] = v0231;
    goto v0078;

v0085:
    v0231 = v0234;
    v0234 = v0231;
    v0231 = stack[-1];
    v0231 = qcar(v0231);
    fn = elt(env, 4); // tayexp!-lessp
    v0231 = (*qfn2(fn))(qenv(fn), v0234, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    if (v0231 == nil) goto v0004;
    v0231 = stack[-1];
    v0234 = qcdr(v0231);
    v0231 = stack[0];
    v0231 = qcdr(v0231);
    stack[-1] = v0234;
    stack[0] = v0231;
    goto v0111;

v0004:
    v0231 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0231); }

v0071:
    v0231 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0231); }
// error exit handlers
v0107:
    popv(4);
    return nil;
}



// Code for get_rep_matrix_in

static LispObject CC_get_rep_matrix_in(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0107, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_rep_matrix_in");
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
    v0033 = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-1] = nil;
    v0107 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0107;
    v0107 = v0033;
    v0107 = qcdr(v0107);
    stack[0] = v0107;
    goto v0004;

v0004:
    v0107 = stack[-3];
    if (v0107 == nil) goto v0025;
    v0107 = qvalue(elt(env, 1)); // nil
    goto v0029;

v0029:
    if (v0107 == nil) goto v0009;
    v0107 = stack[0];
    v0107 = qcar(v0107);
    v0033 = qcar(v0107);
    v0107 = stack[-2];
    if (!(equal(v0033, v0107))) goto v0039;
    v0107 = stack[0];
    v0107 = qcar(v0107);
    v0107 = qcdr(v0107);
    v0107 = qcar(v0107);
    stack[-1] = v0107;
    v0107 = qvalue(elt(env, 2)); // t
    stack[-3] = v0107;
    goto v0039;

v0039:
    v0107 = stack[0];
    v0107 = qcdr(v0107);
    stack[0] = v0107;
    goto v0004;

v0009:
    v0107 = stack[-3];
    if (!(v0107 == nil)) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0107 = elt(env, 3); // "error in get representation matrix"
    fn = elt(env, 4); // rederr
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    v0107 = nil;
    { popv(5); return onevalue(v0107); }

v0025:
    v0107 = stack[0];
    v0033 = Llength(nil, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0107 = (LispObject)1; // 0
    v0107 = (LispObject)greaterp2(v0033, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    v0107 = v0107 ? lisp_true : nil;
    env = stack[-4];
    goto v0029;
// error exit handlers
v0192:
    popv(5);
    return nil;
}



// Code for lastnondomain

static LispObject CC_lastnondomain(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0240, v0241;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lastnondomain");
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
    v0240 = v0000;
// end of prologue

v0024:
    v0241 = v0240;
    if (!consp(v0241)) goto v0002;
    v0241 = v0240;
    v0241 = qcar(v0241);
    v0241 = (consp(v0241) ? nil : lisp_true);
    goto v0020;

v0020:
    if (v0241 == nil) goto v0027;
    v0241 = elt(env, 2); // "non-domain"
    v0240 = list2(v0241, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // errach
        return (*qfn1(fn))(qenv(fn), v0240);
    }

v0027:
    v0241 = v0240;
    v0241 = qcdr(v0241);
    if (!consp(v0241)) goto v0019;
    v0241 = v0240;
    v0241 = qcdr(v0241);
    v0241 = qcar(v0241);
    v0241 = (consp(v0241) ? nil : lisp_true);
    goto v0084;

v0084:
    if (!(v0241 == nil)) { popv(1); return onevalue(v0240); }
    v0240 = qcdr(v0240);
    goto v0024;

v0019:
    v0241 = qvalue(elt(env, 1)); // t
    goto v0084;

v0002:
    v0241 = qvalue(elt(env, 1)); // t
    goto v0020;
// error exit handlers
v0277:
    popv(1);
    return nil;
}



// Code for ibalp_getvar!-zmom

static LispObject CC_ibalp_getvarKzmom(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0218, v0088;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_getvar-zmom");
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
    v0218 = v0001;
    stack[0] = v0000;
// end of prologue
    stack[-4] = nil;
    stack[-2] = nil;
    fn = elt(env, 2); // ibalp_minclnr
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    stack[-5] = v0218;
    v0218 = (LispObject)-15; // -1
    stack[-3] = v0218;
    v0218 = stack[0];
    stack[-1] = v0218;
    goto v0005;

v0005:
    v0218 = stack[-1];
    if (v0218 == nil) goto v0190;
    v0218 = stack[-1];
    v0218 = qcar(v0218);
    stack[0] = v0218;
    v0218 = stack[0];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcar(v0218);
    if (v0218 == nil) goto v0261;
    v0218 = qvalue(elt(env, 1)); // nil
    goto v0084;

v0084:
    if (v0218 == nil) goto v0012;
    v0218 = stack[0];
    v0088 = qcdr(v0218);
    v0218 = stack[-5];
    fn = elt(env, 3); // ibalp_isinminclause
    v0218 = (*qfn2(fn))(qenv(fn), v0088, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    if (v0218 == nil) goto v0012;
    v0218 = stack[0];
    v0218 = qcdr(v0218);
    stack[-4] = v0218;
    v0218 = stack[-2];
    stack[-3] = v0218;
    goto v0012;

v0012:
    v0218 = stack[-1];
    v0218 = qcdr(v0218);
    stack[-1] = v0218;
    goto v0005;

v0261:
    v0218 = stack[0];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0088 = qcar(v0218);
    stack[-2] = v0088;
    v0218 = stack[-3];
    v0218 = (LispObject)greaterp2(v0088, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    v0218 = v0218 ? lisp_true : nil;
    env = stack[-6];
    goto v0084;

v0190:
    v0218 = stack[-4];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0088 = qcar(v0218);
    v0218 = stack[-4];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcar(v0218);
    v0218 = (LispObject)greaterp2(v0088, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    v0218 = v0218 ? lisp_true : nil;
    if (v0218 == nil) goto v0104;
    v0218 = (LispObject)17; // 1
    goto v0232;

v0232:
    v0088 = stack[-4];
    popv(7);
    return cons(v0088, v0218);

v0104:
    v0218 = (LispObject)1; // 0
    goto v0232;
// error exit handlers
v0256:
    popv(7);
    return nil;
}



// Code for sgn

static LispObject CC_sgn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0074;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sgn");
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
    v0074 = stack[0];
    v0014 = (LispObject)1; // 0
    v0014 = (LispObject)greaterp2(v0074, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    v0014 = v0014 ? lisp_true : nil;
    env = stack[-1];
    if (v0014 == nil) goto v0242;
    v0014 = (LispObject)17; // 1
    { popv(2); return onevalue(v0014); }

v0242:
    v0074 = stack[0];
    v0014 = (LispObject)1; // 0
    v0014 = (LispObject)lessp2(v0074, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    v0014 = v0014 ? lisp_true : nil;
    if (v0014 == nil) goto v0010;
    v0014 = (LispObject)-15; // -1
    { popv(2); return onevalue(v0014); }

v0010:
    v0014 = (LispObject)1; // 0
    { popv(2); return onevalue(v0014); }
// error exit handlers
v0084:
    popv(2);
    return nil;
}



setup_type const u09_setup[] =
{
    {"red_better",              too_few_2,      CC_red_better, wrong_no_2},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"cdarx",                   CC_cdarx,       too_many_1,    wrong_no_1},
    {"mri_2pasfat",             CC_mri_2pasfat, too_many_1,    wrong_no_1},
    {"vdp_poly",                CC_vdp_poly,    too_many_1,    wrong_no_1},
    {"expression",              CC_expression,  too_many_1,    wrong_no_1},
    {"spmultm2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_spmultm2},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"covposp",                 CC_covposp,     too_many_1,    wrong_no_1},
    {"statep*",                 CC_statepH,     too_many_1,    wrong_no_1},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"mv-domainlist--",         too_few_2,      CC_mvKdomainlistKK,wrong_no_2},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"primep",                  CC_primep,      too_many_1,    wrong_no_1},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {"ibalp_litp",              CC_ibalp_litp,  too_many_1,    wrong_no_1},
    {"on",                      CC_on,          too_many_1,    wrong_no_1},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"xord_lex",                too_few_2,      CC_xord_lex,   wrong_no_2},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"formop",                  CC_formop,      too_many_1,    wrong_no_1},
    {"leftzeros",               CC_leftzeros,   too_many_1,    wrong_no_1},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"ibalp_atomp",             CC_ibalp_atomp, too_many_1,    wrong_no_1},
    {"ps:minusp:",              CC_psTminuspT,  too_many_1,    wrong_no_1},
    {"off",                     CC_off,         too_many_1,    wrong_no_1},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"scan",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_scan},
    {"multop",                  too_few_2,      CC_multop,     wrong_no_2},
    {"red_divtest",             too_few_2,      CC_red_divtest,wrong_no_2},
    {"prepsq*2",                CC_prepsqH2,    too_many_1,    wrong_no_1},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,too_many_1,wrong_no_1},
    {"quotfx",                  too_few_2,      CC_quotfx,     wrong_no_2},
    {"ibalp_vmember",           too_few_2,      CC_ibalp_vmember,wrong_no_2},
    {"basicom",                 CC_basicom,     too_many_1,    wrong_no_1},
    {"smtp",                    too_few_2,      CC_smtp,       wrong_no_2},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"split-road",              too_few_2,      CC_splitKroad, wrong_no_2},
    {"condterpri",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_condterpri},
    {"red-weight-less-p",       too_few_2,      CC_redKweightKlessKp,wrong_no_2},
    {"pv_neg",                  CC_pv_neg,      too_many_1,    wrong_no_1},
    {"exceeds-order",           too_few_2,      CC_exceedsKorder,wrong_no_2},
    {"get_rep_matrix_in",       too_few_2,      CC_get_rep_matrix_in,wrong_no_2},
    {"lastnondomain",           CC_lastnondomain,too_many_1,   wrong_no_1},
    {"ibalp_getvar-zmom",       too_few_2,      CC_ibalp_getvarKzmom,wrong_no_2},
    {"sgn",                     CC_sgn,         too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u09", (two_args *)"1571 9976621 7548567", 0}
};

// end of generated code
