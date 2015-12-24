
// $destdir/u17.c        Machine generated C code

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



// Code for findremainder

static LispObject CC_findremainder(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0007, v0008, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findremainder");
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
    v0007 = v0001;
    v0008 = v0000;
// end of prologue
    stack[0] = v0007;
    goto v0010;

v0010:
    v0007 = stack[0];
    if (v0007 == nil) { popv(2); return onevalue(v0008); }
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0009 = v0008;
    v0008 = v0007;
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    fn = elt(env, 2); // wupseudodivide
    v0007 = (*qfnn(fn))(qenv(fn), 3, v0009, v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    v0007 = qcdr(v0007);
    v0008 = v0007;
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0010;
// error exit handlers
v0011:
    popv(2);
    return nil;
}



// Code for nary

static LispObject CC_nary(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0019, v0020;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nary");
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
    v0019 = stack[-1];
    v0020 = qcar(v0019);
    v0019 = elt(env, 1); // e
    if (v0020 == v0019) goto v0021;
    v0019 = qvalue(elt(env, 3)); // nil
    goto v0022;

v0022:
    if (v0019 == nil) goto v0023;
    v0019 = stack[-1];
    v0020 = qcdr(v0019);
    v0019 = elt(env, 4); // exp
    fn = elt(env, 10); // unary
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    goto v0010;

v0010:
    v0019 = nil;
    { popv(3); return onevalue(v0019); }

v0023:
    v0019 = elt(env, 5); // "<apply>"
    fn = elt(env, 11); // printout
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0019 = elt(env, 6); // "<"
    v0019 = Lprinc(nil, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0019 = stack[0];
    v0019 = Lprinc(nil, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0019 = stack[-1];
    v0020 = qcar(v0019);
    v0019 = elt(env, 7); // "/"
    fn = elt(env, 12); // attributesml
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0019 = qvalue(elt(env, 8)); // t
    fn = elt(env, 13); // indent!*
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    fn = elt(env, 14); // multi_elem
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0019 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 13); // indent!*
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0019 = elt(env, 9); // "</apply>"
    fn = elt(env, 11); // printout
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    goto v0010;

v0021:
    v0020 = stack[0];
    v0019 = elt(env, 2); // power
    v0019 = (v0020 == v0019 ? lisp_true : nil);
    goto v0022;
// error exit handlers
v0024:
    popv(3);
    return nil;
}



// Code for spband_matrix

static LispObject CC_spband_matrix(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0073, v0074, v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spband_matrix");
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
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0001;
    stack[-8] = v0000;
// end of prologue
    stack[0] = stack[-7];
    v0075 = elt(env, 1); // spm
    v0074 = stack[-7];
    v0073 = stack[-7];
    v0073 = list3(v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    fn = elt(env, 9); // mkempspmat
    v0073 = (*qfn2(fn))(qenv(fn), stack[0], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    stack[-9] = v0073;
    v0073 = stack[-7];
    v0073 = integerp(v0073);
    if (!(v0073 == nil)) goto v0007;
    v0073 = elt(env, 2); // "Error in spband_matrix(second argument): should be an integer."
    fn = elt(env, 10); // rederr
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    goto v0007;

v0007:
    v0073 = stack[-8];
    if (!consp(v0073)) goto v0077;
    v0073 = stack[-8];
    v0074 = qcar(v0073);
    v0073 = elt(env, 3); // list
    if (v0074 == v0073) goto v0078;
    v0073 = elt(env, 4); // "Error in spband_matrix(first argument): should be single value or list."
    fn = elt(env, 10); // rederr
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    goto v0079;

v0079:
    v0073 = stack[-8];
    v0073 = Llength(nil, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    stack[-4] = v0073;
    v0073 = stack[-4];
    v0073 = Levenp(nil, v0073);
    env = stack[-10];
    if (v0073 == nil) goto v0080;
    v0073 = elt(env, 5); // "Error in spband matrix(first argument): number of elements must be odd."
    fn = elt(env, 10); // rederr
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    goto v0080;

v0080:
    stack[0] = elt(env, 6); // quotient
    v0073 = stack[-4];
    v0074 = add1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0073 = (LispObject)33; // 2
    v0073 = list3(stack[0], v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    fn = elt(env, 11); // reval
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    stack[-3] = v0073;
    v0073 = stack[-3];
    v0073 = integerp(v0073);
    if (v0073 == nil) goto v0081;
    v0073 = stack[-3];
    v0074 = v0073;
    goto v0082;

v0082:
    v0073 = stack[-7];
    v0073 = (LispObject)greaterp2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0073 = v0073 ? lisp_true : nil;
    env = stack[-10];
    if (v0073 == nil) goto v0083;
    v0073 = elt(env, 7); // "Error in spband_matrix: too many elements. Band matrix is overflowing."
    fn = elt(env, 10); // rederr
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    goto v0083;

v0083:
    v0073 = (LispObject)33; // 2
    stack[-5] = v0073;
    v0073 = (LispObject)17; // 1
    stack[-2] = v0073;
    goto v0084;

v0084:
    v0074 = stack[-7];
    v0073 = stack[-2];
    v0073 = difference2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0073 = Lminusp(nil, v0073);
    env = stack[-10];
    if (!(v0073 == nil)) { LispObject res = stack[-9]; popv(11); return onevalue(res); }
    v0074 = stack[-2];
    v0073 = stack[-3];
    v0073 = (LispObject)lesseq2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0073 = v0073 ? lisp_true : nil;
    env = stack[-10];
    if (v0073 == nil) goto v0085;
    v0073 = (LispObject)17; // 1
    stack[-6] = v0073;
    goto v0086;

v0086:
    v0074 = stack[-3];
    v0073 = stack[-2];
    v0074 = difference2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0073 = stack[-6];
    v0074 = plus2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0073 = (LispObject)1; // 0
    v0073 = (LispObject)greaterp2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0073 = v0073 ? lisp_true : nil;
    env = stack[-10];
    if (v0073 == nil) goto v0087;
    v0074 = stack[-6];
    v0073 = stack[-7];
    v0073 = (LispObject)lesseq2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0073 = v0073 ? lisp_true : nil;
    env = stack[-10];
    if (v0073 == nil) goto v0087;
    v0074 = stack[-3];
    v0073 = stack[-2];
    v0074 = difference2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0073 = stack[-6];
    v0074 = plus2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0073 = stack[-4];
    v0073 = (LispObject)lesseq2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0073 = v0073 ? lisp_true : nil;
    env = stack[-10];
    if (v0073 == nil) goto v0087;
    v0075 = stack[-9];
    v0074 = stack[-2];
    v0073 = stack[-6];
    stack[-1] = list3(v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    stack[0] = stack[-8];
    v0074 = stack[-3];
    v0073 = stack[-2];
    v0074 = difference2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0073 = stack[-6];
    v0073 = plus2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    fn = elt(env, 12); // nth
    v0075 = (*qfn2(fn))(qenv(fn), stack[0], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0074 = stack[-9];
    v0073 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 13); // letmtr3
    v0073 = (*qfnn(fn))(qenv(fn), 4, stack[-1], v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0073 = stack[-6];
    v0073 = add1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    stack[-6] = v0073;
    goto v0086;

v0087:
    v0074 = stack[-2];
    v0073 = stack[-3];
    v0073 = (LispObject)greaterp2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0073 = v0073 ? lisp_true : nil;
    env = stack[-10];
    if (v0073 == nil) goto v0088;
    v0073 = stack[-5];
    v0073 = add1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    stack[-5] = v0073;
    goto v0088;

v0088:
    v0073 = stack[-2];
    v0073 = add1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    stack[-2] = v0073;
    goto v0084;

v0085:
    v0073 = stack[-5];
    stack[-6] = v0073;
    goto v0086;

v0081:
    v0073 = stack[-3];
    fn = elt(env, 11); // reval
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    v0074 = v0073;
    goto v0082;

v0078:
    v0073 = stack[-8];
    v0073 = qcdr(v0073);
    stack[-8] = v0073;
    goto v0079;

v0077:
    v0073 = stack[-8];
    v0073 = ncons(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-10];
    stack[-8] = v0073;
    goto v0079;
// error exit handlers
v0076:
    popv(11);
    return nil;
}



// Code for inshisto

static LispObject CC_inshisto(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0118, v0119, v0120;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inshisto");
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
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0119 = qvalue(elt(env, 2)); // maxvar
    v0118 = stack[-3];
    v0118 = plus2(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-5];
    v0119 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    v0118 = (LispObject)1; // 0
    v0118 = *(LispObject *)((char *)v0119 + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    if (v0118 == nil) goto v0032;
    v0119 = stack[-3];
    v0118 = (LispObject)1; // 0
    v0118 = (LispObject)geq2(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    v0118 = v0118 ? lisp_true : nil;
    env = stack[-5];
    if (v0118 == nil) goto v0032;
    stack[0] = qvalue(elt(env, 3)); // codhisto
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0119 = qvalue(elt(env, 2)); // maxvar
    v0118 = stack[-3];
    v0118 = plus2(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-5];
    v0119 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    v0118 = (LispObject)17; // 1
    v0118 = *(LispObject *)((char *)v0119 + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    v0119 = qcdr(v0118);
    v0118 = (LispObject)3201; // 200
    fn = elt(env, 6); // min
    v0118 = (*qfn2(fn))(qenv(fn), v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-5];
    stack[-2] = v0118;
    v0118 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    stack[-4] = v0118;
    if (v0118 == nil) goto v0122;
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0119 = qvalue(elt(env, 2)); // maxvar
    v0118 = stack[-4];
    v0118 = plus2(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-5];
    v0119 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    v0118 = (LispObject)113; // 7
    v0119 = *(LispObject *)((char *)v0119 + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    v0118 = stack[-3];
    v0118 = Lrplaca(nil, v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-5];
    goto v0061;

v0061:
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0119 = qvalue(elt(env, 2)); // maxvar
    v0118 = stack[-3];
    v0118 = plus2(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-5];
    stack[-1] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    stack[0] = (LispObject)113; // 7
    v0119 = qvalue(elt(env, 5)); // nil
    v0118 = stack[-4];
    v0118 = cons(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-5];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0118;
    v0120 = qvalue(elt(env, 3)); // codhisto
    v0119 = stack[-2];
    v0118 = stack[-3];
    *(LispObject *)((char *)v0120 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL))) = v0118;
    v0118 = nil;
    { popv(6); return onevalue(v0118); }

v0122:
    v0119 = stack[-2];
    v0118 = qvalue(elt(env, 4)); // headhisto
    v0118 = (LispObject)greaterp2(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    v0118 = v0118 ? lisp_true : nil;
    env = stack[-5];
    if (v0118 == nil) goto v0061;
    v0118 = stack[-2];
    qvalue(elt(env, 4)) = v0118; // headhisto
    goto v0061;

v0032:
    v0118 = nil;
    { popv(6); return onevalue(v0118); }
// error exit handlers
v0121:
    popv(6);
    return nil;
}



// Code for bcplus!?

static LispObject CC_bcplusW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0068;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcplus?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0021 = v0000;
// end of prologue
    v0021 = qcar(v0021);
    v0068 = v0021;
    v0021 = v0068;
    if (is_number(v0021)) goto v0005;
    v0021 = qvalue(elt(env, 1)); // nil
    return onevalue(v0021);

v0005:
    v0021 = (LispObject)1; // 0
        return Lgreaterp(nil, v0068, v0021);
}



// Code for groebbuchcrit4t

static LispObject CC_groebbuchcrit4t(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0125, v0126;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebbuchcrit4t");
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

v0032:
    v0125 = stack[-1];
    if (v0125 == nil) goto v0127;
    v0125 = stack[0];
    v0125 = (v0125 == nil ? lisp_true : nil);
    goto v0128;

v0128:
    if (v0125 == nil) goto v0016;
    v0125 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0125); }

v0016:
    v0125 = stack[-1];
    v0126 = qcar(v0125);
    v0125 = (LispObject)1; // 0
    if (v0126 == v0125) goto v0077;
    v0125 = stack[0];
    v0126 = qcar(v0125);
    v0125 = (LispObject)1; // 0
    v0125 = Lneq(nil, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    goto v0117;

v0117:
    if (v0125 == nil) goto v0129;
    v0125 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0125); }

v0129:
    v0125 = stack[-1];
    v0125 = qcdr(v0125);
    stack[-1] = v0125;
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    stack[0] = v0125;
    goto v0032;

v0077:
    v0125 = qvalue(elt(env, 2)); // nil
    goto v0117;

v0127:
    v0125 = qvalue(elt(env, 1)); // t
    goto v0128;
// error exit handlers
v0067:
    popv(3);
    return nil;
}



// Code for !*pf2wedgepf

static LispObject CC_Hpf2wedgepf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0071, v0124, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *pf2wedgepf");
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
    goto v0032;

v0032:
    v0071 = stack[0];
    if (v0071 == nil) goto v0028;
    v0071 = stack[0];
    v0071 = qcar(v0071);
    v0071 = qcar(v0071);
    fn = elt(env, 1); // wedgefax
    v0007 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    v0071 = stack[0];
    v0071 = qcar(v0071);
    v0124 = qcdr(v0071);
    v0071 = stack[-1];
    v0071 = acons(v0007, v0124, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    stack[-1] = v0071;
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    stack[0] = v0071;
    goto v0032;

v0028:
    v0071 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0071);
    }
// error exit handlers
v0095:
    popv(3);
    return nil;
}



// Code for list!+list

static LispObject CC_listLlist(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0009, v0095;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list+list");
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
    goto v0010;

v0010:
    v0009 = stack[-1];
    if (v0009 == nil) goto v0015;
    v0009 = stack[-1];
    v0095 = qcar(v0009);
    v0009 = stack[0];
    v0009 = qcar(v0009);
    fn = elt(env, 1); // !:plus
    v0095 = (*qfn2(fn))(qenv(fn), v0095, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0009 = stack[-2];
    v0009 = cons(v0095, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    stack[-2] = v0009;
    v0009 = stack[-1];
    v0009 = qcdr(v0009);
    stack[-1] = v0009;
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    stack[0] = v0009;
    goto v0010;

v0015:
    v0009 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0009);
    }
// error exit handlers
v0123:
    popv(4);
    return nil;
}



// Code for copyd

static LispObject CC_copyd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0137, v0138, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for copyd");
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
    v0137 = stack[-1];
    fn = elt(env, 5); // getd
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    v0138 = v0137;
    if (v0138 == nil) goto v0115;
    v0062 = stack[-2];
    v0138 = v0137;
    v0138 = qcar(v0138);
    v0137 = qcdr(v0137);
    fn = elt(env, 6); // putd
    v0137 = (*qfnn(fn))(qenv(fn), 3, v0062, v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    v0137 = stack[-1];
    if (!symbolp(v0137)) v0137 = nil;
    else { v0137 = qfastgets(v0137);
           if (v0137 != nil) { v0137 = elt(v0137, 1); // lose
#ifdef RECORD_GET
             if (v0137 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v0137 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v0137 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v0137 == SPID_NOPROP) v0137 = nil; else v0137 = lisp_true; }}
#endif
    if (v0137 == nil) goto v0080;
    v0137 = stack[-2];
    v0138 = ncons(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    v0137 = elt(env, 4); // lose
    v0137 = Lflag(nil, v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    goto v0080;

v0080:
    v0138 = stack[-1];
    v0137 = elt(env, 1); // !*savedef
    v0138 = get(v0138, v0137);
    env = stack[-4];
    v0137 = v0138;
    if (v0138 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0062 = stack[-2];
    v0138 = elt(env, 1); // !*savedef
    v0137 = Lputprop(nil, 3, v0062, v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0115:
    v0138 = qvalue(elt(env, 1)); // !*savedef
    v0137 = elt(env, 1); // !*savedef
    if (v0138 == v0137) goto v0080;
    stack[-3] = elt(env, 2); // rlisp
    stack[0] = (LispObject)17; // 1
    v0138 = stack[-1];
    v0137 = elt(env, 3); // "has no definition in copyd"
    v0137 = list2(v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    fn = elt(env, 7); // rerror
    v0137 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-4];
    goto v0080;
// error exit handlers
v0139:
    popv(5);
    return nil;
}



// Code for mkcr

static LispObject CC_mkcr(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkcr");
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
    v0005 = v0000;
// end of prologue
    stack[-2] = elt(env, 1); // !:cr!:
    fn = elt(env, 2); // striptag
    stack[0] = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    v0005 = stack[-1];
    fn = elt(env, 2); // striptag
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    {
        LispObject v0021 = stack[-2];
        LispObject v0068 = stack[0];
        popv(4);
        return list2star(v0021, v0068, v0005);
    }
// error exit handlers
v0018:
    popv(4);
    return nil;
}



// Code for simpiden

static LispObject CC_simpiden(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0200, v0201, v0202;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpiden");
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
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    v0200 = stack[0];
    v0200 = qcar(v0200);
    stack[-7] = v0200;
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    stack[0] = v0200;
    v0201 = stack[-7];
    v0200 = elt(env, 1); // !:rn!:
    v0200 = get(v0201, v0200);
    env = stack[-8];
    if (!(v0200 == nil)) goto v0011;
    v0201 = stack[-7];
    v0200 = elt(env, 2); // !:rd!:
    v0200 = get(v0201, v0200);
    env = stack[-8];
    if (!(v0200 == nil)) goto v0011;

v0203:
    v0200 = stack[0];
    if (v0200 == nil) goto v0129;
    v0200 = stack[0];
    v0201 = qcar(v0200);
    v0200 = elt(env, 3); // list
    if (!consp(v0201)) goto v0204;
    v0201 = qcar(v0201);
    if (!(v0201 == v0200)) goto v0204;
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    v0200 = (v0200 == nil ? lisp_true : nil);
    goto v0126;

v0126:
    if (v0200 == nil) goto v0129;
    stack[-1] = stack[-7];
    v0200 = stack[0];
    v0200 = qcar(v0200);
    fn = elt(env, 14); // aeval
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0201 = list2(stack[-1], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = (LispObject)17; // 1
    {
        popv(9);
        fn = elt(env, 15); // mksq
        return (*qfn2(fn))(qenv(fn), v0201, v0200);
    }

v0129:
    v0200 = stack[0];
    stack[-3] = v0200;
    v0200 = stack[-3];
    if (v0200 == nil) goto v0103;
    v0200 = stack[-3];
    v0200 = qcar(v0200);
    fn = elt(env, 14); // aeval
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-1] = v0200;
    stack[-2] = v0200;
    goto v0082;

v0082:
    v0200 = stack[-3];
    v0200 = qcdr(v0200);
    stack[-3] = v0200;
    v0200 = stack[-3];
    if (v0200 == nil) goto v0025;
    stack[0] = stack[-1];
    v0200 = stack[-3];
    v0200 = qcar(v0200);
    fn = elt(env, 14); // aeval
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = Lrplacd(nil, stack[0], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = stack[-1];
    v0200 = qcdr(v0200);
    stack[-1] = v0200;
    goto v0082;

v0025:
    v0200 = stack[-2];
    goto v0133;

v0133:
    stack[-6] = v0200;
    v0200 = stack[-6];
    stack[-3] = v0200;
    v0200 = stack[-3];
    if (v0200 == nil) goto v0206;
    v0200 = stack[-3];
    v0200 = qcar(v0200);
    v0202 = v0200;
    v0201 = v0202;
    v0200 = elt(env, 5); // !*sq
    if (!consp(v0201)) goto v0093;
    v0201 = qcar(v0201);
    if (!(v0201 == v0200)) goto v0093;
    v0200 = v0202;
    v0200 = qcdr(v0200);
    v0200 = qcar(v0200);
    fn = elt(env, 16); // prepsqxx
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    goto v0207;

v0207:
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-1] = v0200;
    stack[-2] = v0200;
    goto v0208;

v0208:
    v0200 = stack[-3];
    v0200 = qcdr(v0200);
    stack[-3] = v0200;
    v0200 = stack[-3];
    if (v0200 == nil) goto v0053;
    stack[0] = stack[-1];
    v0200 = stack[-3];
    v0200 = qcar(v0200);
    v0202 = v0200;
    v0201 = v0202;
    v0200 = elt(env, 5); // !*sq
    if (!consp(v0201)) goto v0043;
    v0201 = qcar(v0201);
    if (!(v0201 == v0200)) goto v0043;
    v0200 = v0202;
    v0200 = qcdr(v0200);
    v0200 = qcar(v0200);
    fn = elt(env, 16); // prepsqxx
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    goto v0209;

v0209:
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = Lrplacd(nil, stack[0], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = stack[-1];
    v0200 = qcdr(v0200);
    stack[-1] = v0200;
    goto v0208;

v0043:
    v0200 = v0202;
    if (is_number(v0200)) goto v0049;
    v0200 = v0202;
    goto v0209;

v0049:
    v0200 = v0202;
    goto v0209;

v0053:
    v0200 = stack[-2];
    goto v0097;

v0097:
    stack[0] = v0200;
    v0200 = stack[0];
    if (v0200 == nil) goto v0210;
    v0200 = stack[0];
    v0201 = qcar(v0200);
    v0200 = (LispObject)1; // 0
    if (v0201 == v0200) goto v0211;
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0212;

v0212:
    if (v0200 == nil) goto v0210;
    v0201 = qvalue(elt(env, 4)); // nil
    v0200 = (LispObject)17; // 1
    popv(9);
    return cons(v0201, v0200);

v0210:
    v0201 = stack[-7];
    v0200 = stack[0];
    v0200 = cons(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[0] = v0200;
    v0200 = stack[-7];
    if (!symbolp(v0200)) v0200 = nil;
    else { v0200 = qfastgets(v0200);
           if (v0200 != nil) { v0200 = elt(v0200, 0); // noncom
#ifdef RECORD_GET
             if (v0200 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0200 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0200 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0200 == SPID_NOPROP) v0200 = nil; else v0200 = lisp_true; }}
#endif
    if (v0200 == nil) goto v0213;
    v0200 = qvalue(elt(env, 6)); // t
    qvalue(elt(env, 9)) = v0200; // ncmp!*
    goto v0213;

v0213:
    v0200 = qvalue(elt(env, 10)); // subfg!*
    if (v0200 == nil) goto v0015;
    v0201 = stack[-7];
    v0200 = elt(env, 11); // linear
    v0200 = Lflagp(nil, v0201, v0200);
    env = stack[-8];
    if (v0200 == nil) goto v0214;
    v0200 = stack[0];
    fn = elt(env, 17); // formlnr
    v0201 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-4] = v0201;
    v0200 = stack[0];
    v0200 = Lneq(nil, v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    goto v0215;

v0215:
    if (v0200 == nil) goto v0216;
    v0200 = stack[-4];
    {
        popv(9);
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(qenv(fn), v0200);
    }

v0216:
    v0200 = stack[0];
    fn = elt(env, 19); // opmtch
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-4] = v0200;
    if (v0200 == nil) goto v0015;
    v0200 = stack[-4];
    {
        popv(9);
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(qenv(fn), v0200);
    }

v0015:
    v0200 = stack[-7];
    if (!symbolp(v0200)) v0200 = nil;
    else { v0200 = qfastgets(v0200);
           if (v0200 != nil) { v0200 = elt(v0200, 43); // symmetric
#ifdef RECORD_GET
             if (v0200 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v0200 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v0200 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v0200 == SPID_NOPROP) v0200 = nil; else v0200 = lisp_true; }}
#endif
    if (v0200 == nil) goto v0217;
    stack[-1] = stack[-7];
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    fn = elt(env, 20); // ordn
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = cons(stack[-1], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[0] = v0200;
    goto v0218;

v0218:
    v0201 = stack[-7];
    v0200 = elt(env, 13); // even
    v0200 = Lflagp(nil, v0201, v0200);
    env = stack[-8];
    if (v0200 == nil) goto v0219;
    v0200 = qvalue(elt(env, 6)); // t
    goto v0220;

v0220:
    if (v0200 == nil) goto v0221;
    v0200 = stack[-6];
    if (v0200 == nil) goto v0222;
    v0200 = stack[-6];
    v0200 = qcar(v0200);
    fn = elt(env, 18); // simp
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-6] = v0200;
    v0200 = qcar(v0200);
    fn = elt(env, 21); // minusf
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    goto v0223;

v0223:
    if (v0200 == nil) goto v0224;
    v0201 = stack[-7];
    v0200 = elt(env, 13); // even
    v0200 = Lflagp(nil, v0201, v0200);
    env = stack[-8];
    if (!(v0200 == nil)) goto v0225;
    v0200 = stack[-5];
    v0200 = (v0200 == nil ? lisp_true : nil);
    stack[-5] = v0200;
    goto v0225;

v0225:
    stack[-1] = stack[-7];
    v0200 = stack[-6];
    fn = elt(env, 22); // negsq
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    fn = elt(env, 16); // prepsqxx
    v0201 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    v0200 = qcdr(v0200);
    v0200 = list2star(stack[-1], v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[0] = v0200;
    v0200 = stack[0];
    fn = elt(env, 19); // opmtch
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-4] = v0200;
    if (v0200 == nil) goto v0224;
    v0200 = stack[-5];
    if (v0200 == nil) goto v0226;
    v0200 = stack[-4];
    fn = elt(env, 18); // simp
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 22); // negsq
        return (*qfn1(fn))(qenv(fn), v0200);
    }

v0226:
    v0200 = stack[-4];
    {
        popv(9);
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(qenv(fn), v0200);
    }

v0224:
    v0201 = stack[0];
    v0200 = (LispObject)17; // 1
    fn = elt(env, 15); // mksq
    v0200 = (*qfn2(fn))(qenv(fn), v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[0] = v0200;
    v0200 = stack[-5];
    if (v0200 == nil) { LispObject res = stack[0]; popv(9); return onevalue(res); }
    v0200 = stack[0];
    {
        popv(9);
        fn = elt(env, 22); // negsq
        return (*qfn1(fn))(qenv(fn), v0200);
    }

v0222:
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0223;

v0221:
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0223;

v0219:
    v0201 = stack[-7];
    v0200 = elt(env, 7); // odd
    v0200 = Lflagp(nil, v0201, v0200);
    env = stack[-8];
    goto v0220;

v0217:
    v0201 = stack[-7];
    v0200 = elt(env, 12); // antisymmetric
    v0200 = Lflagp(nil, v0201, v0200);
    env = stack[-8];
    if (v0200 == nil) goto v0218;
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    fn = elt(env, 23); // repeats
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    if (v0200 == nil) goto v0227;
    v0201 = qvalue(elt(env, 4)); // nil
    v0200 = (LispObject)17; // 1
    popv(9);
    return cons(v0201, v0200);

v0227:
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    fn = elt(env, 20); // ordn
    v0201 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-4] = v0201;
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    fn = elt(env, 24); // permp
    v0200 = (*qfn2(fn))(qenv(fn), v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    if (!(v0200 == nil)) goto v0228;
    v0200 = qvalue(elt(env, 6)); // t
    stack[-5] = v0200;
    goto v0228;

v0228:
    v0200 = stack[0];
    v0201 = qcar(v0200);
    v0200 = stack[-4];
    v0200 = cons(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-7] = v0200;
    v0201 = stack[-4];
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    if (equal(v0201, v0200)) goto v0229;
    v0200 = stack[-7];
    fn = elt(env, 19); // opmtch
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-4] = v0200;
    goto v0230;

v0230:
    if (v0200 == nil) goto v0231;
    v0200 = stack[-5];
    if (v0200 == nil) goto v0232;
    v0200 = stack[-4];
    fn = elt(env, 18); // simp
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 22); // negsq
        return (*qfn1(fn))(qenv(fn), v0200);
    }

v0232:
    v0200 = stack[-4];
    {
        popv(9);
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(qenv(fn), v0200);
    }

v0231:
    v0200 = stack[-7];
    stack[0] = v0200;
    goto v0218;

v0229:
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0230;

v0214:
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0215;

v0211:
    v0201 = stack[-7];
    v0200 = elt(env, 7); // odd
    v0200 = Lflagp(nil, v0201, v0200);
    env = stack[-8];
    if (v0200 == nil) goto v0233;
    v0201 = stack[-7];
    v0200 = elt(env, 8); // nonzero
    v0200 = Lflagp(nil, v0201, v0200);
    env = stack[-8];
    v0200 = (v0200 == nil ? lisp_true : nil);
    goto v0212;

v0233:
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0212;

v0093:
    v0200 = v0202;
    if (is_number(v0200)) goto v0119;
    v0200 = v0202;
    goto v0207;

v0119:
    v0200 = v0202;
    goto v0207;

v0206:
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0097;

v0103:
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0133;

v0204:
    v0200 = qvalue(elt(env, 4)); // nil
    goto v0126;

v0011:
    v0201 = stack[-7];
    v0200 = stack[0];
    fn = elt(env, 25); // valuechk
    v0200 = (*qfn2(fn))(qenv(fn), v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-8];
    stack[-6] = v0200;
    if (v0200 == nil) goto v0203;
    else { LispObject res = stack[-6]; popv(9); return onevalue(res); }
// error exit handlers
v0205:
    popv(9);
    return nil;
}



// Code for traput

static LispObject CC_traput(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0238, v0198, v0197, v0019, v0020;
    LispObject v0131, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "traput");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0131 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for traput");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0131,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0198 = v0131;
    v0197 = v0001;
    v0019 = v0000;
// end of prologue
    v0020 = v0019;
    v0238 = v0197;
    v0238 = get(v0020, v0238);
    env = stack[-2];
    v0020 = v0238;
    if (v0238 == nil) goto v0239;
    v0238 = qvalue(elt(env, 1)); // toplv!*
    if (!(v0238 == nil)) goto v0028;
    v0197 = v0198;
    v0238 = v0020;
    v0238 = Lmemq(nil, v0197, v0238);
    if (!(v0238 == nil)) goto v0028;
    stack[0] = v0020;
    v0238 = v0198;
    v0198 = v0020;
    v0198 = qcdr(v0198);
    v0238 = cons(v0238, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0238 = Lrplacd(nil, stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    goto v0028;

v0028:
    v0238 = nil;
    { popv(3); return onevalue(v0238); }

v0239:
    stack[-1] = v0019;
    stack[0] = v0197;
    v0238 = v0198;
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0238 = Lputprop(nil, 3, stack[-1], stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    goto v0028;
// error exit handlers
v0024:
    popv(3);
    return nil;
}



// Code for polynomheadreduceby

static LispObject CC_polynomheadreduceby(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0019, v0020;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynomheadreduceby");
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
    goto v0015;

v0015:
    v0019 = stack[-2];
    v0019 = qcar(v0019);
    if (v0019 == nil) goto v0028;
    v0019 = stack[-3];
    if (!(v0019 == nil)) goto v0028;
    v0019 = stack[-2];
    v0020 = qcar(v0019);
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    fn = elt(env, 4); // monomisdivisibleby
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    if (v0019 == nil) goto v0236;
    v0019 = stack[-2];
    v0020 = qcar(v0019);
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    fn = elt(env, 5); // monomdivide
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    stack[0] = stack[-2];
    v0020 = stack[-1];
    fn = elt(env, 6); // polynommultiplybymonom
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    fn = elt(env, 7); // polynomadd
    v0019 = (*qfn2(fn))(qenv(fn), stack[0], v0019);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    goto v0015;

v0236:
    v0019 = qvalue(elt(env, 2)); // t
    stack[-3] = v0019;
    goto v0015;

v0028:
    v0019 = qvalue(elt(env, 3)); // fluidbibasisreductionsmade
    v0019 = (LispObject)((int32_t)(v0019) + 0x10);
    qvalue(elt(env, 3)) = v0019; // fluidbibasisreductionsmade
    v0019 = nil;
    { popv(5); return onevalue(v0019); }
// error exit handlers
v0241:
    popv(5);
    return nil;
}



// Code for exptcompare

static LispObject CC_exptcompare(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0014, v0023, v0123;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptcompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0023 = v0001;
    v0123 = v0000;
// end of prologue
    v0014 = v0123;
    if (!consp(v0014)) goto v0032;
    v0014 = v0023;
    if (!consp(v0014)) goto v0117;
    v0014 = v0123;
    v0014 = qcar(v0014);
    v0023 = qcar(v0023);
        return Lgreaterp(nil, v0014, v0023);

v0117:
    v0014 = qvalue(elt(env, 2)); // t
    return onevalue(v0014);

v0032:
    v0014 = v0023;
    if (!consp(v0014)) goto v0140;
    v0014 = qvalue(elt(env, 1)); // nil
    return onevalue(v0014);

v0140:
    v0014 = v0123;
        return Lgreaterp(nil, v0014, v0023);
}



// Code for qqe_number!-of!-adds!-in!-qterm

static LispObject CC_qqe_numberKofKaddsKinKqterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0072;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_number-of-adds-in-qterm");
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

v0146:
    v0003 = stack[0];
    if (!consp(v0003)) goto v0045;
    v0003 = stack[0];
    fn = elt(env, 2); // qqe_op
    v0072 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    v0003 = elt(env, 1); // (ladd radd)
    v0003 = Lmemq(nil, v0072, v0003);
    if (v0003 == nil) goto v0002;
    v0003 = stack[0];
    fn = elt(env, 3); // qqe_arg2r
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    v0003 = CC_qqe_numberKofKaddsKinKqterm(env, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    popv(2);
    return add1(v0003);

v0002:
    v0003 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    stack[0] = v0003;
    goto v0146;

v0045:
    v0003 = (LispObject)1; // 0
    { popv(2); return onevalue(v0003); }
// error exit handlers
v0071:
    popv(2);
    return nil;
}



// Code for ibalp_initwl

static LispObject CC_ibalp_initwl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035, v0251;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_initwl");
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
    v0035 = v0000;
// end of prologue
    stack[-4] = nil;
    stack[-2] = v0035;
    goto v0022;

v0022:
    v0035 = stack[-2];
    if (v0035 == nil) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    v0035 = stack[-2];
    v0035 = qcar(v0035);
    stack[-1] = v0035;
    v0035 = (LispObject)1; // 0
    stack[-5] = v0035;
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    stack[-3] = v0035;
    goto v0008;

v0008:
    v0251 = stack[-5];
    v0035 = (LispObject)33; // 2
    v0035 = Leqn(nil, v0251, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    if (v0035 == nil) goto v0071;
    v0035 = qvalue(elt(env, 1)); // nil
    goto v0070;

v0070:
    if (v0035 == nil) goto v0004;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    stack[0] = qcdr(v0035);
    v0035 = stack[-3];
    v0251 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    v0035 = cons(v0251, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0035 = (*qfn2(fn))(qenv(fn), stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    v0035 = stack[-3];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    stack[0] = qcdr(v0035);
    v0251 = stack[-1];
    v0035 = stack[-3];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    v0035 = cons(v0251, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0035 = (*qfn2(fn))(qenv(fn), stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    v0035 = stack[-5];
    v0035 = add1(v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    stack[-5] = v0035;
    v0035 = stack[-3];
    v0035 = qcdr(v0035);
    stack[-3] = v0035;
    goto v0008;

v0004:
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    stack[-3] = v0035;
    goto v0186;

v0186:
    v0251 = stack[-5];
    v0035 = (LispObject)33; // 2
    v0035 = Leqn(nil, v0251, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    if (v0035 == nil) goto v0252;
    v0035 = qvalue(elt(env, 1)); // nil
    goto v0061;

v0061:
    if (v0035 == nil) goto v0033;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    stack[0] = qcdr(v0035);
    v0035 = stack[-3];
    v0251 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    v0035 = cons(v0251, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0035 = (*qfn2(fn))(qenv(fn), stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    v0035 = stack[-3];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    stack[0] = qcdr(v0035);
    v0251 = stack[-1];
    v0035 = stack[-3];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    v0035 = cons(v0251, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0035 = (*qfn2(fn))(qenv(fn), stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    v0035 = stack[-5];
    v0035 = add1(v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    stack[-5] = v0035;
    v0035 = stack[-3];
    v0035 = qcdr(v0035);
    stack[-3] = v0035;
    goto v0186;

v0033:
    v0251 = stack[-5];
    v0035 = (LispObject)33; // 2
    v0035 = (LispObject)lessp2(v0251, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0035 = v0035 ? lisp_true : nil;
    env = stack[-6];
    if (v0035 == nil) goto v0253;
    v0251 = stack[-1];
    v0035 = stack[-4];
    v0035 = cons(v0251, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-6];
    stack[-4] = v0035;
    goto v0253;

v0253:
    v0035 = stack[-2];
    v0035 = qcdr(v0035);
    stack[-2] = v0035;
    goto v0022;

v0252:
    v0035 = stack[-3];
    goto v0061;

v0071:
    v0035 = stack[-3];
    goto v0070;
// error exit handlers
v0177:
    popv(7);
    return nil;
}



// Code for sf_member

static LispObject CC_sf_member(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0013, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf_member");
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

v0254:
    v0013 = stack[0];
    if (!consp(v0013)) goto v0015;
    v0013 = stack[0];
    v0013 = qcar(v0013);
    v0013 = (consp(v0013) ? nil : lisp_true);
    goto v0028;

v0028:
    if (v0013 == nil) goto v0068;
    v0013 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0013); }

v0068:
    v0067 = stack[-1];
    v0013 = stack[0];
    v0013 = qcar(v0013);
    v0013 = qcar(v0013);
    v0013 = qcar(v0013);
    fn = elt(env, 3); // mvar_member
    v0013 = (*qfn2(fn))(qenv(fn), v0067, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-2];
    if (!(v0013 == nil)) { popv(3); return onevalue(v0013); }
    v0067 = stack[-1];
    v0013 = stack[0];
    v0013 = qcar(v0013);
    v0013 = qcdr(v0013);
    v0013 = CC_sf_member(env, v0067, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-2];
    if (!(v0013 == nil)) { popv(3); return onevalue(v0013); }
    v0067 = stack[-1];
    v0013 = stack[0];
    v0013 = qcdr(v0013);
    stack[-1] = v0067;
    stack[0] = v0013;
    goto v0254;

v0015:
    v0013 = qvalue(elt(env, 1)); // t
    goto v0028;
// error exit handlers
v0234:
    popv(3);
    return nil;
}



// Code for variableom

static LispObject CC_variableom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0126, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for variableom");
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
    v0126 = stack[0];
    v0012 = Lintern(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = qvalue(elt(env, 1)); // constantsom!*
    v0126 = Lassoc(nil, v0012, v0126);
    stack[-1] = v0126;
    v0126 = stack[-1];
    if (v0126 == nil) goto v0011;
    v0126 = elt(env, 2); // "<OMS "
    fn = elt(env, 9); // printout
    v0126 = (*qfn1(fn))(qenv(fn), v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = elt(env, 3); // "cd="""
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    v0126 = qcar(v0126);
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = elt(env, 4); // """ "
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = elt(env, 5); // "name="""
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0126 = qcar(v0126);
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = elt(env, 6); // """/>"
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    goto v0203;

v0203:
    v0126 = nil;
    { popv(3); return onevalue(v0126); }

v0011:
    v0126 = stack[0];
    if (v0126 == nil) goto v0203;
    v0126 = elt(env, 8); // "<OMV "
    fn = elt(env, 9); // printout
    v0126 = (*qfn1(fn))(qenv(fn), v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = elt(env, 5); // "name="""
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = stack[0];
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-2];
    v0126 = elt(env, 6); // """/>"
    v0126 = Lprinc(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    goto v0203;
// error exit handlers
v0255:
    popv(3);
    return nil;
}



// Code for onoff

static LispObject CC_onoff(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0261, v0262, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for onoff");
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
    stack[0] = v0000;
// end of prologue
    v0261 = stack[0];
    if (symbolp(v0261)) goto v0022;
    v0262 = stack[0];
    v0261 = elt(env, 1); // "switch"
    fn = elt(env, 10); // typerr
    v0261 = (*qfn2(fn))(qenv(fn), v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    goto v0199;

v0199:
    stack[-1] = elt(env, 4); // !*
    v0261 = stack[0];
    v0261 = Lexplodec(nil, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    v0261 = cons(stack[-1], v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    fn = elt(env, 11); // list2string
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    v0261 = Lintern(nil, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    stack[-3] = v0261;
    v0261 = qvalue(elt(env, 5)); // !*switchcheck
    if (v0261 == nil) goto v0024;
    v0261 = stack[-3];
    fn = elt(env, 12); // lispeval
    v0262 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    v0261 = stack[-2];
    if (!(v0262 == v0261)) goto v0024;
    v0261 = qvalue(elt(env, 6)); // nil
    { popv(5); return onevalue(v0261); }

v0024:
    v0060 = stack[-2];
    v0262 = stack[0];
    v0261 = elt(env, 7); // simpfg
    v0261 = get(v0262, v0261);
    env = stack[-4];
    v0261 = Latsoc(nil, v0060, v0261);
    v0262 = v0261;
    if (v0261 == nil) goto v0125;
    stack[-1] = elt(env, 8); // progn
    v0261 = v0262;
    stack[0] = qcdr(v0261);
    v0261 = qvalue(elt(env, 6)); // nil
    v0261 = ncons(v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    v0261 = Lappend(nil, stack[0], v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    v0261 = cons(stack[-1], v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    fn = elt(env, 12); // lispeval
    v0261 = (*qfn1(fn))(qenv(fn), v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    goto v0125;

v0125:
    v0261 = stack[-2];
    if (v0261 == nil) goto v0098;
    v0262 = stack[-3];
    v0261 = elt(env, 9); // !*raise
    if (!(v0262 == v0261)) goto v0098;
    v0261 = elt(env, 9); // !*raise
    stack[-3] = v0261;
    goto v0098;

v0098:
    v0262 = stack[-3];
    v0261 = stack[-2];
    v0261 = Lset(nil, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    v0261 = nil;
    { popv(5); return onevalue(v0261); }

v0022:
    v0261 = stack[0];
    if (!symbolp(v0261)) v0261 = nil;
    else { v0261 = qfastgets(v0261);
           if (v0261 != nil) { v0261 = elt(v0261, 51); // switch
#ifdef RECORD_GET
             if (v0261 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v0261 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v0261 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v0261 == SPID_NOPROP) v0261 = nil; else v0261 = lisp_true; }}
#endif
    if (!(v0261 == nil)) goto v0199;
    stack[-3] = elt(env, 2); // rlisp
    stack[-1] = (LispObject)401; // 25
    v0262 = stack[0];
    v0261 = elt(env, 3); // "not defined as switch"
    v0261 = list2(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    fn = elt(env, 13); // rerror
    v0261 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-1], v0261);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-4];
    goto v0199;
// error exit handlers
v0186:
    popv(5);
    return nil;
}



// Code for guesspftype

static LispObject CC_guesspftype(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0077, v0199;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for guesspftype");
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
    v0077 = stack[0];
    if (!consp(v0077)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0077 = stack[0];
    v0199 = qcar(v0077);
    v0077 = elt(env, 1); // (wedge d partdf hodge innerprod liedf)
    v0077 = Lmemq(nil, v0199, v0077);
    if (!(v0077 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    v0199 = Llength(nil, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-1];
    v0077 = stack[0];
    v0077 = qcar(v0077);
    if (!symbolp(v0077)) v0077 = nil;
    else { v0077 = qfastgets(v0077);
           if (v0077 != nil) { v0077 = elt(v0077, 25); // ifdegree
#ifdef RECORD_GET
             if (v0077 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v0077 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v0077 == SPID_NOPROP) v0077 = nil; }}
#endif
    v0077 = Lassoc(nil, v0199, v0077);
    if (v0077 == nil) goto v0014;
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    fn = elt(env, 2); // xvarlistp
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-1];
    if (v0077 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    else goto v0014;

v0014:
    v0077 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); // mknwedge
        return (*qfn1(fn))(qenv(fn), v0077);
    }
// error exit handlers
v0237:
    popv(2);
    return nil;
}



// Code for deleteall

static LispObject CC_deleteall(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0095, v0011, v0014, v0023;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deleteall");
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
    v0014 = nil;
    goto v0045;

v0045:
    v0095 = stack[0];
    if (v0095 == nil) { popv(4); return onevalue(v0014); }
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0023 = v0095;
    v0095 = stack[0];
    v0095 = qcdr(v0095);
    stack[0] = v0095;
    v0011 = v0023;
    v0095 = stack[-1];
    if (equal(v0011, v0095)) goto v0045;
    stack[-2] = v0014;
    v0095 = v0023;
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    v0095 = Lnconc(nil, stack[-2], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    v0014 = v0095;
    goto v0045;
// error exit handlers
v0199:
    popv(4);
    return nil;
}



// Code for cstimes

static LispObject CC_cstimes(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0236, v0234, v0235, v0264;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cstimes");
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
    v0234 = v0001;
    v0235 = v0000;
// end of prologue

v0010:
    v0236 = v0235;
    if (v0236 == nil) goto v0015;
    v0236 = v0235;
    v0264 = qcar(v0236);
    v0236 = (LispObject)17; // 1
    if (v0264 == v0236) goto v0124;
    v0236 = v0235;
    v0236 = qcdr(v0236);
    stack[0] = v0236;
    v0236 = v0235;
    v0236 = qcar(v0236);
    v0236 = cons(v0236, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-1];
    v0234 = v0236;
    v0236 = stack[0];
    v0235 = v0236;
    goto v0010;

v0124:
    v0236 = v0235;
    v0236 = qcdr(v0236);
    v0235 = v0236;
    goto v0010;

v0015:
    v0236 = v0234;
    if (v0236 == nil) goto v0140;
    v0236 = v0234;
    v0236 = qcdr(v0236);
    if (v0236 == nil) goto v0116;
    v0236 = elt(env, 1); // times
    popv(2);
    return cons(v0236, v0234);

v0116:
    v0236 = v0234;
    v0236 = qcar(v0236);
    { popv(2); return onevalue(v0236); }

v0140:
    v0236 = (LispObject)17; // 1
    { popv(2); return onevalue(v0236); }
// error exit handlers
v0198:
    popv(2);
    return nil;
}



// Code for lesspcdr

static LispObject CC_lesspcdr(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0265, v0140;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lesspcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0265 = v0001;
    v0140 = v0000;
// end of prologue
    v0140 = qcdr(v0140);
    v0265 = qcdr(v0265);
        return Llessp(nil, v0140, v0265);
}



// Code for sqp

static LispObject CC_sqp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0117;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqp");
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
    v0117 = stack[0];
    v0117 = Lconsp(nil, v0117);
    env = stack[-1];
    if (v0117 == nil) goto v0146;
    v0117 = stack[0];
    v0117 = qcar(v0117);
    fn = elt(env, 2); // sfpx
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    if (v0117 == nil) goto v0265;
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    {
        popv(2);
        fn = elt(env, 2); // sfpx
        return (*qfn1(fn))(qenv(fn), v0117);
    }

v0265:
    v0117 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0117); }

v0146:
    v0117 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0117); }
// error exit handlers
v0002:
    popv(2);
    return nil;
}



// Code for ra_refine1

static LispObject CC_ra_refine1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0139, v0268, v0081;
    LispObject fn;
    LispObject v0006, v0131, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ra_refine1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0131 = va_arg(aa, LispObject);
    v0006 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_refine1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0006,v0131,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0131,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-2] = v0006;
    stack[-3] = v0131;
    stack[-4] = v0001;
    stack[-5] = v0000;
// end of prologue
    v0139 = (LispObject)17; // 1
    stack[-1] = v0139;
    goto v0017;

v0017:
    v0268 = stack[-2];
    v0139 = stack[-1];
    v0139 = difference2(v0268, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    v0139 = Lminusp(nil, v0139);
    env = stack[-7];
    if (v0139 == nil) goto v0263;
    v0268 = stack[-4];
    v0139 = stack[-3];
    popv(8);
    return cons(v0268, v0139);

v0263:
    v0268 = stack[-4];
    v0139 = stack[-3];
    fn = elt(env, 3); // sfto_avgq
    v0139 = (*qfn2(fn))(qenv(fn), v0268, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    stack[-6] = v0139;
    stack[0] = stack[-5];
    v0268 = elt(env, 2); // x
    v0139 = stack[-6];
    v0139 = cons(v0268, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    v0139 = ncons(v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    fn = elt(env, 4); // sfto_qsub1
    v0139 = (*qfn2(fn))(qenv(fn), stack[0], v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    v0139 = qcar(v0139);
    if (v0139 == nil) goto v0013;
    v0081 = stack[-5];
    v0268 = stack[-4];
    v0139 = stack[-6];
    fn = elt(env, 5); // ra_budancount
    v0268 = (*qfnn(fn))(qenv(fn), 3, v0081, v0268, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    v0139 = (LispObject)17; // 1
    v0139 = Leqn(nil, v0268, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    if (v0139 == nil) goto v0269;
    v0139 = stack[-6];
    stack[-3] = v0139;
    goto v0008;

v0008:
    v0139 = stack[-1];
    v0139 = add1(v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    stack[-1] = v0139;
    goto v0017;

v0269:
    v0139 = stack[-6];
    stack[-4] = v0139;
    goto v0008;

v0013:
    v0268 = stack[-4];
    v0139 = stack[-6];
    fn = elt(env, 3); // sfto_avgq
    v0139 = (*qfn2(fn))(qenv(fn), v0268, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-7];
    stack[-4] = v0139;
    goto v0008;
// error exit handlers
v0025:
    popv(8);
    return nil;
}



// Code for putd

static LispObject CC_putd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0272, v0273, v0274;
    LispObject fn;
    LispObject v0131, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "putd");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0131 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for putd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0131,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0131;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0273 = stack[0];
    v0272 = elt(env, 1); // funarg
    if (!consp(v0273)) goto v0032;
    v0273 = qcar(v0273);
    if (!(v0273 == v0272)) goto v0032;
    v0273 = elt(env, 2); // lambda
    v0272 = stack[0];
    v0272 = qcdr(v0272);
    v0272 = qcdr(v0272);
    v0272 = cons(v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    stack[0] = v0272;
    goto v0032;

v0032:
    v0272 = stack[-2];
    if (!symbolp(v0272)) v0272 = nil;
    else { v0272 = qfastgets(v0272);
           if (v0272 != nil) { v0272 = elt(v0272, 1); // lose
#ifdef RECORD_GET
             if (v0272 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v0272 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v0272 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v0272 == SPID_NOPROP) v0272 = nil; else v0272 = lisp_true; }}
#endif
    if (v0272 == nil) goto v0014;
    v0272 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    v0272 = elt(env, 3); // "+++ "
    v0272 = Lprinc(nil, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    v0272 = stack[-2];
    v0272 = Lprin(nil, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    v0272 = elt(env, 4); // " not defined (LOSE flag)"
    v0272 = Lprintc(nil, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    v0272 = qvalue(elt(env, 5)); // nil
    { popv(4); return onevalue(v0272); }

v0014:
    v0272 = qvalue(elt(env, 6)); // !*redefmsg
    if (v0272 == nil) goto v0235;
    v0272 = stack[-2];
    fn = elt(env, 15); // getd
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    if (v0272 == nil) goto v0235;
    v0272 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    v0272 = elt(env, 3); // "+++ "
    v0272 = Lprinc(nil, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    v0272 = stack[-2];
    v0272 = Lprin(nil, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    v0272 = elt(env, 7); // " redefined"
    v0272 = Lprintc(nil, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    goto v0235;

v0235:
    v0273 = stack[-1];
    v0272 = elt(env, 8); // expr
    if (v0273 == v0272) goto v0204;
    v0273 = stack[-1];
    v0272 = elt(env, 9); // subr
    if (v0273 == v0272) goto v0065;
    v0273 = stack[-1];
    v0272 = elt(env, 10); // macro
    if (v0273 == v0272) goto v0102;
    v0272 = qvalue(elt(env, 5)); // nil
    goto v0138;

v0138:
    if (v0272 == nil) goto v0208;
    v0274 = elt(env, 11); // dm
    v0273 = stack[-2];
    v0272 = stack[0];
    v0272 = qcdr(v0272);
    v0272 = list2star(v0274, v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    fn = elt(env, 16); // eval
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0208:
    v0273 = stack[-1];
    v0272 = elt(env, 12); // fexpr
    if (v0273 == v0272) goto v0085;
    v0272 = qvalue(elt(env, 5)); // nil
    goto v0186;

v0186:
    if (v0272 == nil) goto v0276;
    v0274 = elt(env, 13); // df
    v0273 = stack[-2];
    v0272 = stack[0];
    v0272 = qcdr(v0272);
    v0272 = list2star(v0274, v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-3];
    fn = elt(env, 16); // eval
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0276:
    v0273 = elt(env, 14); // "Bad type ~S in putd"
    v0272 = stack[-1];
    fn = elt(env, 17); // error
    v0272 = (*qfn2(fn))(qenv(fn), v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0085:
    v0273 = stack[0];
    v0272 = elt(env, 2); // lambda
    v0272 = Leqcar(nil, v0273, v0272);
    env = stack[-3];
    goto v0186;

v0102:
    v0273 = stack[0];
    v0272 = elt(env, 2); // lambda
    v0272 = Leqcar(nil, v0273, v0272);
    env = stack[-3];
    goto v0138;

v0065:
    v0273 = stack[-2];
    v0272 = stack[0];
    v0272 = Lsymbol_set_definition(nil, v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0204:
    v0273 = stack[-2];
    v0272 = stack[0];
    v0272 = Lsymbol_set_definition(nil, v0273, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }
// error exit handlers
v0275:
    popv(4);
    return nil;
}



// Code for replus

static LispObject CC_replus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0130, v0003;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replus");
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
    v0003 = v0000;
// end of prologue
    v0130 = v0003;
    if (v0130 == nil) goto v0146;
    v0130 = v0003;
    if (!consp(v0130)) { popv(1); return onevalue(v0003); }
    v0130 = v0003;
    v0130 = qcdr(v0130);
    if (v0130 == nil) goto v0127;
    stack[0] = elt(env, 1); // plus
    v0130 = v0003;
    fn = elt(env, 2); // unplus
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    {
        LispObject v0071 = stack[0];
        popv(1);
        return cons(v0071, v0130);
    }

v0127:
    v0130 = v0003;
    v0130 = qcar(v0130);
    { popv(1); return onevalue(v0130); }

v0146:
    v0130 = (LispObject)1; // 0
    { popv(1); return onevalue(v0130); }
// error exit handlers
v0070:
    popv(1);
    return nil;
}



// Code for wusort

static LispObject CC_wusort(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0022, v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wusort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0022 = v0000;
// end of prologue
    v0128 = v0022;
    v0022 = elt(env, 1); // wulessp!*
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(qenv(fn), v0128, v0022);
    }
}



// Code for expnd1

static LispObject CC_expnd1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0257, v0261;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expnd1");
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
    goto v0010;

v0010:
    v0257 = stack[-1];
    if (!consp(v0257)) goto v0203;
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = (consp(v0257) ? nil : lisp_true);
    goto v0140;

v0140:
    if (v0257 == nil) goto v0004;
    v0257 = stack[-1];
    v0261 = v0257;
    goto v0028;

v0028:
    v0257 = stack[-2];
    if (v0257 == nil) { popv(4); return onevalue(v0261); }
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    fn = elt(env, 2); // addf
    v0257 = (*qfn2(fn))(qenv(fn), v0257, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    v0261 = v0257;
    v0257 = stack[-2];
    v0257 = qcdr(v0257);
    stack[-2] = v0257;
    goto v0028;

v0004:
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    fn = elt(env, 3); // sfp
    v0257 = (*qfn1(fn))(qenv(fn), v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    if (v0257 == nil) goto v0008;
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0261 = qcdr(v0257);
    v0257 = (LispObject)1; // 0
    v0257 = (LispObject)lessp2(v0261, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    v0257 = v0257 ? lisp_true : nil;
    env = stack[-3];
    goto v0007;

v0007:
    if (v0257 == nil) goto v0065;
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0261 = qcar(v0257);
    v0257 = (LispObject)17; // 1
    v0257 = cons(v0261, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    stack[0] = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    v0257 = CC_expnd1(env, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    fn = elt(env, 4); // multf
    v0257 = (*qfn2(fn))(qenv(fn), stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    v0261 = v0257;
    goto v0016;

v0016:
    v0257 = stack[-2];
    v0257 = cons(v0261, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    stack[-2] = v0257;
    v0257 = stack[-1];
    v0257 = qcdr(v0257);
    stack[-1] = v0257;
    goto v0010;

v0065:
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0261 = CC_expnd1(env, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    fn = elt(env, 5); // exptf
    stack[0] = (*qfn2(fn))(qenv(fn), v0261, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    v0257 = CC_expnd1(env, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    fn = elt(env, 4); // multf
    v0257 = (*qfn2(fn))(qenv(fn), stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-3];
    v0261 = v0257;
    goto v0016;

v0008:
    v0257 = qvalue(elt(env, 1)); // t
    goto v0007;

v0203:
    v0257 = qvalue(elt(env, 1)); // t
    goto v0140;
// error exit handlers
v0252:
    popv(4);
    return nil;
}



// Code for aex_simplenullp

static LispObject CC_aex_simplenullp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0010;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_simplenullp");
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
    v0010 = v0000;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    errexit();
    v0010 = qcar(v0010);
    v0010 = (v0010 == nil ? lisp_true : nil);
    return onevalue(v0010);
}



// Code for mml2om

static LispObject CC_mml2om(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0203;
    LispObject fn;
    argcheck(nargs, 0, "mml2om");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mml2om");
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
    fn = elt(env, 3); // mml2ir
    v0203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    stack[0] = v0203;
    v0203 = qvalue(elt(env, 1)); // t
    fn = elt(env, 4); // terpri!*
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0203 = elt(env, 2); // "Intermediate representation: "
    v0203 = Lprinc(nil, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0203 = qvalue(elt(env, 1)); // t
    fn = elt(env, 4); // terpri!*
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0203 = stack[0];
    v0203 = Lprint(nil, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0203 = stack[0];
    fn = elt(env, 5); // ir2om
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    v0203 = nil;
    { popv(2); return onevalue(v0203); }
// error exit handlers
v0115:
    popv(2);
    return nil;
}



// Code for unchecked_getmatelem

static LispObject CC_unchecked_getmatelem(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0264, v0238, v0198;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unchecked_getmatelem");
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
    v0264 = stack[-1];
    v0238 = qcar(v0264);
    v0198 = v0238;
    v0264 = elt(env, 1); // mat
    if (!consp(v0238)) goto v0017;
    v0238 = qcar(v0238);
    if (!(v0238 == v0264)) goto v0017;
    v0264 = v0198;
    v0238 = qcdr(v0264);
    v0264 = stack[-1];
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    fn = elt(env, 5); // nth
    v0238 = (*qfn2(fn))(qenv(fn), v0238, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-3];
    v0264 = stack[-1];
    v0264 = qcdr(v0264);
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    {
        popv(4);
        fn = elt(env, 5); // nth
        return (*qfn2(fn))(qenv(fn), v0238, v0264);
    }

v0017:
    stack[-2] = elt(env, 2); // matrix
    stack[0] = (LispObject)17; // 1
    v0198 = elt(env, 3); // "Matrix"
    v0264 = stack[-1];
    v0238 = qcar(v0264);
    v0264 = elt(env, 4); // "not set"
    v0264 = list3(v0198, v0238, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-3];
    fn = elt(env, 6); // rerror
    v0264 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0264);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    v0264 = nil;
    { popv(4); return onevalue(v0264); }
// error exit handlers
v0112:
    popv(4);
    return nil;
}



// Code for equalreplaceby

static LispObject CC_equalreplaceby(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0022, v0128;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for equalreplaceby");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0022 = v0000;
// end of prologue
    v0128 = elt(env, 1); // replaceby
    return cons(v0128, v0022);
}



// Code for command

static LispObject CC_command(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0289, v0290, v0291, v0292;
    LispObject fn;
    argcheck(nargs, 0, "command");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for command");
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
    stack[-2] = qvalue(elt(env, 1)); // errmsg!*
    qvalue(elt(env, 1)) = nil; // errmsg!*
    stack[-1] = qvalue(elt(env, 2)); // loopdelimslist!*
    qvalue(elt(env, 2)) = nil; // loopdelimslist!*
    v0289 = qvalue(elt(env, 3)); // !*demo
    if (v0289 == nil) goto v0140;
    v0289 = qvalue(elt(env, 4)); // ifl!*
    if (v0289 == nil) goto v0140;
    fn = elt(env, 29); // commdemo
    v0289 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0045;

v0045:
    qvalue(elt(env, 2)) = stack[-1]; // loopdelimslist!*
    qvalue(elt(env, 1)) = stack[-2]; // errmsg!*
    { popv(4); return onevalue(v0289); }

v0140:
    v0289 = qvalue(elt(env, 5)); // !*slin
    if (v0289 == nil) goto v0117;
    v0289 = qvalue(elt(env, 7)); // !*reduce4
    goto v0069;

v0069:
    if (!(v0289 == nil)) goto v0028;
    fn = elt(env, 30); // setcloc!*
    v0289 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    v0289 = qvalue(elt(env, 8)); // lreadfn!*
    if (v0289 == nil) goto v0199;
    v0290 = qvalue(elt(env, 8)); // lreadfn!*
    v0289 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 31); // lispapply
    v0289 = (*qfn2(fn))(qenv(fn), v0290, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0071;

v0071:
    stack[0] = v0289;
    goto v0015;

v0015:
    v0289 = qvalue(elt(env, 7)); // !*reduce4
    if (v0289 == nil) goto v0238;
    v0289 = qvalue(elt(env, 25)); // !*debug
    if (v0289 == nil) goto v0294;
    v0289 = elt(env, 26); // "Parse: "
    v0289 = Lprinc(nil, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    v0289 = stack[0];
    fn = elt(env, 32); // prettyprint
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0294;

v0294:
    v0290 = qvalue(elt(env, 18)); // key!*
    v0289 = elt(env, 27); // !*semicol!*
    if (v0290 == v0289) goto v0028;
    v0289 = qvalue(elt(env, 7)); // !*reduce4
    if (v0289 == nil) goto v0295;
    v0289 = stack[0];
    fn = elt(env, 33); // n_form
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    stack[0] = v0289;
    goto v0215;

v0215:
    v0289 = qvalue(elt(env, 25)); // !*debug
    if (v0289 == nil) goto v0296;
    v0289 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    v0289 = elt(env, 28); // "Form: "
    v0289 = Lprinc(nil, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    v0289 = stack[0];
    fn = elt(env, 32); // prettyprint
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0296;

v0296:
    v0289 = stack[0];
    goto v0045;

v0295:
    v0289 = stack[0];
    fn = elt(env, 34); // form
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    stack[0] = v0289;
    goto v0215;

v0028:
    fn = elt(env, 35); // readch1
    v0289 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    qvalue(elt(env, 10)) = v0289; // crchar!*
    v0290 = qvalue(elt(env, 10)); // crchar!*
    v0289 = qvalue(elt(env, 11)); // !$eol!$
    if (equal(v0290, v0289)) goto v0028;
    fn = elt(env, 36); // command1
    v0289 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    stack[0] = v0289;
    goto v0015;

v0238:
    v0289 = qvalue(elt(env, 12)); // !*struct
    if (v0289 == nil) goto v0235;
    v0289 = stack[0];
    fn = elt(env, 37); // structchk
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    stack[0] = v0289;
    goto v0235;

v0235:
    v0289 = qvalue(elt(env, 13)); // !*pret
    if (v0289 == nil) goto v0266;
    v0289 = stack[0];
    if (!consp(v0289)) goto v0109;
    v0289 = stack[0];
    v0290 = qcar(v0289);
    v0289 = elt(env, 14); // (in out shut)
    v0289 = Lmemq(nil, v0290, v0289);
    v0289 = (v0289 == nil ? lisp_true : nil);
    goto v0195;

v0195:
    if (v0289 == nil) goto v0266;
    v0289 = stack[0];
    if (v0289 == nil) goto v0081;
    v0289 = qvalue(elt(env, 9)); // nil
    goto v0249;

v0249:
    if (v0289 == nil) goto v0297;
    v0289 = elt(env, 16); // end
    fn = elt(env, 38); // rprint
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0266;

v0266:
    v0289 = qvalue(elt(env, 5)); // !*slin
    if (v0289 == nil) goto v0084;
    v0290 = elt(env, 17); // symbolic
    v0289 = stack[0];
    v0289 = list2(v0290, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0045;

v0084:
    v0289 = stack[0];
    fn = elt(env, 34); // form
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    v0290 = v0289;
    v0289 = qvalue(elt(env, 18)); // key!*
    if (!symbolp(v0289)) v0289 = nil;
    else { v0289 = qfastgets(v0289);
           if (v0289 != nil) { v0289 = elt(v0289, 48); // modefn
#ifdef RECORD_GET
             if (v0289 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0289 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0289 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0289 == SPID_NOPROP) v0289 = nil; else v0289 = lisp_true; }}
#endif
    if (v0289 == nil) goto v0206;
    v0289 = qvalue(elt(env, 18)); // key!*
    goto v0037;

v0037:
    stack[0] = v0289;
    v0292 = v0290;
    v0291 = qvalue(elt(env, 9)); // nil
    v0290 = elt(env, 17); // symbolic
    fn = elt(env, 39); // convertmode1
    v0289 = (*qfnn(fn))(qenv(fn), 4, v0292, v0291, v0290, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    v0289 = list2(stack[0], v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0045;

v0206:
    v0289 = v0290;
    if (!consp(v0289)) goto v0036;
    v0289 = v0290;
    v0291 = qcar(v0289);
    v0289 = elt(env, 19); // quote
    if (v0291 == v0289) goto v0298;
    v0289 = v0290;
    v0289 = qcar(v0289);
    if (!(symbolp(v0289))) goto v0120;
    v0289 = v0290;
    v0291 = qcar(v0289);
    v0289 = elt(env, 20); // nochange
    v0289 = Lflagp(nil, v0291, v0289);
    env = stack[-3];
    if (v0289 == nil) goto v0209;
    v0289 = qvalue(elt(env, 6)); // t
    goto v0299;

v0299:
    if (v0289 == nil) goto v0120;
    v0289 = v0290;
    v0291 = qcar(v0289);
    v0289 = elt(env, 23); // (setq setel setf)
    v0289 = Lmemq(nil, v0291, v0289);
    if (v0289 == nil) goto v0253;
    v0289 = v0290;
    v0289 = qcdr(v0289);
    v0289 = qcdr(v0289);
    v0291 = qcar(v0289);
    v0289 = elt(env, 19); // quote
    v0289 = Leqcar(nil, v0291, v0289);
    env = stack[-3];
    goto v0189;

v0189:
    if (v0289 == nil) goto v0300;
    v0289 = elt(env, 17); // symbolic
    goto v0037;

v0300:
    v0289 = qvalue(elt(env, 24)); // !*mode
    goto v0037;

v0253:
    v0289 = qvalue(elt(env, 9)); // nil
    goto v0189;

v0120:
    v0289 = qvalue(elt(env, 6)); // t
    goto v0189;

v0209:
    v0289 = v0290;
    v0291 = qcar(v0289);
    v0289 = elt(env, 21); // intfn
    v0289 = Lflagp(nil, v0291, v0289);
    env = stack[-3];
    if (v0289 == nil) goto v0301;
    v0289 = qvalue(elt(env, 6)); // t
    goto v0299;

v0301:
    v0289 = v0290;
    v0291 = qcar(v0289);
    v0289 = elt(env, 22); // list
    v0289 = (v0291 == v0289 ? lisp_true : nil);
    goto v0299;

v0298:
    v0289 = qvalue(elt(env, 9)); // nil
    goto v0189;

v0036:
    v0289 = qvalue(elt(env, 9)); // nil
    goto v0189;

v0297:
    v0289 = stack[0];
    fn = elt(env, 38); // rprint
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    v0289 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0266;

v0081:
    v0290 = qvalue(elt(env, 15)); // cursym!*
    v0289 = elt(env, 16); // end
    v0289 = (v0290 == v0289 ? lisp_true : nil);
    goto v0249;

v0109:
    v0289 = qvalue(elt(env, 6)); // t
    goto v0195;

v0199:
    v0289 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-3];
    goto v0071;

v0117:
    v0289 = qvalue(elt(env, 6)); // t
    goto v0069;
// error exit handlers
v0293:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; // loopdelimslist!*
    qvalue(elt(env, 1)) = stack[-2]; // errmsg!*
    popv(4);
    return nil;
}



// Code for ord2

static LispObject CC_ord2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0071, v0124;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ord2");
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
    v0124 = stack[-1];
    v0071 = stack[0];
    fn = elt(env, 1); // ordp
    v0071 = (*qfn2(fn))(qenv(fn), v0124, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    if (v0071 == nil) goto v0002;
    v0124 = stack[-1];
    v0071 = stack[0];
    popv(2);
    return list2(v0124, v0071);

v0002:
    v0124 = stack[0];
    v0071 = stack[-1];
    popv(2);
    return list2(v0124, v0071);
// error exit handlers
v0009:
    popv(2);
    return nil;
}



// Code for b!:extadd

static LispObject CC_bTextadd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0261, v0262, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:extadd");
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
    goto v0028;

v0028:
    v0261 = stack[-1];
    if (v0261 == nil) goto v0127;
    v0261 = stack[0];
    if (v0261 == nil) goto v0005;
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    v0262 = qcar(v0261);
    v0261 = stack[0];
    v0261 = qcar(v0261);
    v0261 = qcar(v0261);
    if (equal(v0262, v0261)) goto v0124;
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    v0262 = qcar(v0261);
    v0261 = stack[0];
    v0261 = qcar(v0261);
    v0261 = qcar(v0261);
    fn = elt(env, 2); // b!:ordexp
    v0261 = (*qfn2(fn))(qenv(fn), v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-3];
    if (v0261 == nil) goto v0082;
    v0261 = stack[-1];
    v0262 = qcar(v0261);
    v0261 = stack[-2];
    v0261 = cons(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-3];
    stack[-2] = v0261;
    v0261 = stack[-1];
    v0261 = qcdr(v0261);
    stack[-1] = v0261;
    goto v0028;

v0082:
    v0261 = stack[0];
    v0262 = qcar(v0261);
    v0261 = stack[-2];
    v0261 = cons(v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-3];
    stack[-2] = v0261;
    v0261 = stack[0];
    v0261 = qcdr(v0261);
    stack[0] = v0261;
    goto v0028;

v0124:
    v0261 = stack[-1];
    v0261 = qcar(v0261);
    v0262 = qcdr(v0261);
    v0261 = stack[0];
    v0261 = qcar(v0261);
    v0261 = qcdr(v0261);
    fn = elt(env, 3); // addf
    v0261 = (*qfn2(fn))(qenv(fn), v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-3];
    v0262 = v0261;
    if (v0262 == nil) goto v0267;
    v0262 = stack[-1];
    v0262 = qcar(v0262);
    v0060 = qcar(v0262);
    v0262 = v0261;
    v0261 = stack[-2];
    v0261 = acons(v0060, v0262, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-3];
    stack[-2] = v0261;
    goto v0267;

v0267:
    v0261 = stack[-1];
    v0261 = qcdr(v0261);
    stack[-1] = v0261;
    v0261 = stack[0];
    v0261 = qcdr(v0261);
    stack[0] = v0261;
    goto v0028;

v0005:
    v0261 = stack[-1];
    v0262 = v0261;
    goto v0106;

v0106:
    v0261 = stack[-2];
    if (v0261 == nil) { popv(4); return onevalue(v0262); }
    v0261 = stack[-2];
    v0261 = qcdr(v0261);
    stack[-1] = v0261;
    v0261 = stack[-2];
    v0261 = Lrplacd(nil, v0261, v0262);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-3];
    v0261 = stack[-2];
    v0262 = v0261;
    v0261 = stack[-1];
    stack[-2] = v0261;
    goto v0106;

v0127:
    v0261 = stack[0];
    v0262 = v0261;
    goto v0106;
// error exit handlers
v0187:
    popv(4);
    return nil;
}



// Code for general!-reduce!-degree!-mod!-p

static LispObject CC_generalKreduceKdegreeKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0062, v0103, v0104;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-reduce-degree-mod-p");
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
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    fn = elt(env, 1); // general!-modular!-minus
    v0103 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-3];
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    fn = elt(env, 2); // general!-modular!-quotient
    v0062 = (*qfn2(fn))(qenv(fn), v0103, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-3];
    stack[-2] = v0062;
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0103 = qcdr(v0062);
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    v0062 = (LispObject)(int32_t)((int32_t)v0103 - (int32_t)v0062 + TAG_FIXNUM);
    v0104 = v0062;
    v0103 = v0104;
    v0062 = (LispObject)1; // 0
    if (v0103 == v0062) goto v0267;
    v0062 = stack[-1];
    stack[-1] = qcdr(v0062);
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0103 = v0104;
    fn = elt(env, 3); // mksp
    v0103 = (*qfn2(fn))(qenv(fn), v0062, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-3];
    v0062 = stack[-2];
    v0103 = cons(v0103, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-3];
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    fn = elt(env, 4); // general!-times!-term!-mod!-p
    v0062 = (*qfn2(fn))(qenv(fn), v0103, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-3];
    {
        LispObject v0081 = stack[-1];
        popv(4);
        fn = elt(env, 5); // general!-plus!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0081, v0062);
    }

v0267:
    v0062 = stack[-1];
    stack[-1] = qcdr(v0062);
    v0062 = stack[0];
    v0103 = qcdr(v0062);
    v0062 = stack[-2];
    fn = elt(env, 6); // general!-multiply!-by!-constant!-mod!-p
    v0062 = (*qfn2(fn))(qenv(fn), v0103, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-3];
    {
        LispObject v0105 = stack[-1];
        popv(4);
        fn = elt(env, 5); // general!-plus!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0105, v0062);
    }
// error exit handlers
v0268:
    popv(4);
    return nil;
}



// Code for expt!-mod!-p

static LispObject CC_exptKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0080, v0111, v0195;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expt-mod-p");
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
    v0195 = v0001;
    stack[0] = v0000;
// end of prologue
    v0111 = v0195;
    v0080 = (LispObject)1; // 0
    if (v0111 == v0080) goto v0032;
    v0111 = v0195;
    v0080 = (LispObject)17; // 1
    if (v0111 == v0080) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0111 = v0195;
    v0080 = (LispObject)33; // 2
    v0080 = Ldivide(nil, v0111, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    stack[-1] = v0080;
    v0111 = stack[0];
    v0080 = stack[-1];
    v0080 = qcar(v0080);
    v0080 = CC_exptKmodKp(env, v0111, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    v0195 = v0080;
    v0080 = v0195;
    v0111 = v0195;
    fn = elt(env, 1); // times!-mod!-p
    v0080 = (*qfn2(fn))(qenv(fn), v0080, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    v0195 = v0080;
    v0080 = stack[-1];
    v0111 = qcdr(v0080);
    v0080 = (LispObject)1; // 0
    if (v0111 == v0080) { popv(3); return onevalue(v0195); }
    v0111 = v0195;
    v0080 = stack[0];
    fn = elt(env, 1); // times!-mod!-p
    v0080 = (*qfn2(fn))(qenv(fn), v0111, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    v0195 = v0080;
    { popv(3); return onevalue(v0195); }

v0032:
    v0080 = (LispObject)17; // 1
    { popv(3); return onevalue(v0080); }
// error exit handlers
v0135:
    popv(3);
    return nil;
}



// Code for crprcd2

static LispObject CC_crprcd2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0028;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crprcd2");
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
    v0028 = stack[-1];
    fn = elt(env, 2); // crprcd
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    stack[-1] = v0028;
    v0028 = stack[0];
    fn = elt(env, 2); // crprcd
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0028; // yy!!
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0128:
    popv(3);
    return nil;
}



// Code for sf2ss

static LispObject CC_sf2ss(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0239, v0125;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf2ss");
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
    v0239 = stack[-1];
    if (!consp(v0239)) goto v0127;
    v0239 = stack[-1];
    v0239 = qcar(v0239);
    v0239 = (consp(v0239) ? nil : lisp_true);
    goto v0128;

v0128:
    if (!(v0239 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0239 = stack[-1];
    fn = elt(env, 2); // searchpl
    v0239 = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    stack[-2] = v0239;
    v0239 = stack[-2];
    fn = elt(env, 3); // qsort
    stack[0] = (*qfn1(fn))(qenv(fn), v0239);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    v0239 = stack[-2];
    v0239 = Llength(nil, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    v0239 = cons(stack[0], v0239);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    stack[0] = v0239;
    v0125 = stack[-1];
    fn = elt(env, 4); // sq2sspl
    v0125 = (*qfn2(fn))(qenv(fn), v0125, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    v0239 = (LispObject)17; // 1
    v0239 = list2star(stack[0], v0125, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); // lx2xx
        return (*qfn1(fn))(qenv(fn), v0239);
    }

v0127:
    v0239 = qvalue(elt(env, 1)); // t
    goto v0128;
// error exit handlers
v0067:
    popv(4);
    return nil;
}



// Code for ibalp_unvar!-unsatlist

static LispObject CC_ibalp_unvarKunsatlist(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0162, v0315;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_unvar-unsatlist");
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
    v0162 = v0000;
// end of prologue
    stack[-5] = v0162;
    goto v0015;

v0015:
    v0162 = stack[-5];
    if (v0162 == nil) goto v0028;
    v0162 = stack[-5];
    v0162 = qcar(v0162);
    stack[-3] = v0162;
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0315 = stack[-4];
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    fn = elt(env, 2); // delq
    v0162 = (*qfn2(fn))(qenv(fn), v0315, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    if (!(v0162 == nil)) goto v0199;
    v0162 = stack[-3];
    v0162 = qcar(v0162);
    stack[-2] = v0162;
    goto v0013;

v0013:
    v0162 = stack[-2];
    if (v0162 == nil) goto v0012;
    v0162 = stack[-2];
    v0162 = qcar(v0162);
    stack[-1] = v0162;
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    v0162 = add1(v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0162 = stack[-1];
    fn = elt(env, 4); // ibalp_calcmom
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-2];
    v0162 = qcdr(v0162);
    stack[-2] = v0162;
    goto v0013;

v0012:
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    stack[-2] = v0162;
    goto v0317;

v0317:
    v0162 = stack[-2];
    if (v0162 == nil) goto v0101;
    v0162 = stack[-2];
    v0162 = qcar(v0162);
    stack[-1] = v0162;
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    v0162 = add1(v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0162 = stack[-1];
    fn = elt(env, 4); // ibalp_calcmom
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-2];
    v0162 = qcdr(v0162);
    stack[-2] = v0162;
    goto v0317;

v0101:
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    stack[-1] = v0162;
    goto v0318;

v0318:
    v0162 = stack[-1];
    if (v0162 == nil) goto v0242;
    v0162 = stack[-1];
    v0162 = qcar(v0162);
    v0315 = v0162;
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    stack[0] = qcdr(v0315);
    v0315 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    fn = elt(env, 2); // delq
    v0162 = (*qfn2(fn))(qenv(fn), v0315, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    stack[-1] = v0162;
    goto v0318;

v0242:
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0315 = qcdr(v0162);
    v0162 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), v0315, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-3];
    fn = elt(env, 5); // ibalp_getnewwl
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    stack[-1] = v0162;
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0315 = stack[-1];
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    v0162 = cons(v0315, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0315 = stack[-3];
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    v0162 = cons(v0315, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-3];
    fn = elt(env, 5); // ibalp_getnewwl
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    stack[-1] = v0162;
    v0162 = stack[-1];
    if (v0162 == nil) goto v0199;
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0315 = stack[-1];
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    v0162 = cons(v0315, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    stack[0] = qcdr(v0162);
    v0315 = stack[-3];
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    v0162 = cons(v0315, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    fn = elt(env, 3); // setcar
    v0162 = (*qfn2(fn))(qenv(fn), stack[0], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    goto v0199;

v0199:
    v0162 = stack[-5];
    v0162 = qcdr(v0162);
    stack[-5] = v0162;
    goto v0015;

v0028:
    v0162 = nil;
    { popv(7); return onevalue(v0162); }
// error exit handlers
v0316:
    popv(7);
    return nil;
}



// Code for exptpri

static LispObject CC_exptpri(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0339, v0340, v0341;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptpri");
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
    v0339 = v0001;
    stack[-5] = v0000;
// end of prologue
    v0340 = qvalue(elt(env, 1)); // !*utf8
    if (v0340 == nil) goto v0005;
    v0340 = stack[-5];
    {
        popv(8);
        fn = elt(env, 20); // utf8_exptpri
        return (*qfn2(fn))(qenv(fn), v0340, v0339);
    }

v0005:
    stack[-6] = qvalue(elt(env, 2)); // !*list
    qvalue(elt(env, 2)) = nil; // !*list
    stack[0] = nil;
    v0340 = qvalue(elt(env, 3)); // !*nat
    if (v0340 == nil) goto v0070;
    v0340 = qvalue(elt(env, 5)); // !*fort
    goto v0072;

v0072:
    if (v0340 == nil) goto v0023;
    v0339 = elt(env, 6); // failed
    goto v0004;

v0004:
    qvalue(elt(env, 2)) = stack[-6]; // !*list
    { popv(8); return onevalue(v0339); }

v0023:
    v0340 = elt(env, 7); // expt
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 23); // infix
#ifdef RECORD_GET
             if (v0340 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0340 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; }}
#endif
    stack[-2] = v0340;
    v0339 = (LispObject)greaterp2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    v0339 = v0339 ? lisp_true : nil;
    env = stack[-7];
    v0339 = (v0339 == nil ? lisp_true : nil);
    stack[-4] = v0339;
    v0339 = stack[-5];
    v0339 = qcdr(v0339);
    v0339 = qcar(v0339);
    stack[-1] = v0339;
    v0339 = stack[-5];
    v0339 = qcdr(v0339);
    v0339 = qcdr(v0339);
    v0339 = qcar(v0339);
    stack[-3] = v0339;
    v0339 = qvalue(elt(env, 8)); // !*eraise
    if (v0339 == nil) goto v0250;
    v0339 = stack[-1];
    if (!consp(v0339)) goto v0133;
    v0339 = stack[-1];
    v0339 = qcar(v0339);
    if (!symbolp(v0339)) v0339 = nil;
    else { v0339 = qfastgets(v0339);
           if (v0339 != nil) { v0339 = elt(v0339, 57); // prifn
#ifdef RECORD_GET
             if (v0339 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0339 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0339 == SPID_NOPROP) v0339 = nil; }}
#endif
    stack[0] = v0339;
    if (v0339 == nil) goto v0024;
    v0340 = stack[0];
    v0339 = elt(env, 7); // expt
    v0340 = get(v0340, v0339);
    env = stack[-7];
    v0339 = elt(env, 10); // inbrackets
    v0339 = (v0340 == v0339 ? lisp_true : nil);
    goto v0198;

v0198:
    if (v0339 == nil) goto v0250;
    v0341 = stack[-1];
    v0340 = (LispObject)1; // 0
    v0339 = elt(env, 10); // inbrackets
    fn = elt(env, 21); // layout!-formula
    v0339 = (*qfnn(fn))(qenv(fn), 3, v0341, v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    stack[-1] = v0339;
    goto v0067;

v0067:
    v0339 = stack[-1];
    if (v0339 == nil) goto v0343;
    stack[-5] = qvalue(elt(env, 12)); // !*ratpri
    qvalue(elt(env, 12)) = nil; // !*ratpri
    v0340 = stack[-3];
    v0339 = elt(env, 13); // quotient
    if (!consp(v0340)) goto v0344;
    v0340 = qcar(v0340);
    if (!(v0340 == v0339)) goto v0344;
    v0339 = stack[-3];
    v0339 = qcdr(v0339);
    v0340 = qcar(v0339);
    v0339 = elt(env, 14); // minus
    v0339 = Leqcar(nil, v0340, v0339);
    env = stack[-7];
    goto v0054;

v0054:
    if (v0339 == nil) goto v0253;
    stack[0] = elt(env, 14); // minus
    v0339 = stack[-3];
    v0341 = qcar(v0339);
    v0339 = stack[-3];
    v0339 = qcdr(v0339);
    v0339 = qcar(v0339);
    v0339 = qcdr(v0339);
    v0340 = qcar(v0339);
    v0339 = stack[-3];
    v0339 = qcdr(v0339);
    v0339 = qcdr(v0339);
    v0339 = qcar(v0339);
    v0339 = list3(v0341, v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-7];
    v0339 = list2(stack[0], v0339);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-7];
    stack[-3] = v0339;
    goto v0314;

v0314:
    v0341 = stack[-3];
    v0339 = qvalue(elt(env, 8)); // !*eraise
    if (v0339 == nil) goto v0175;
    v0339 = (LispObject)1; // 0
    v0340 = v0339;
    goto v0242;

v0242:
    v0339 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 21); // layout!-formula
    v0339 = (*qfnn(fn))(qenv(fn), 3, v0341, v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-7];
    stack[-3] = v0339;
    qvalue(elt(env, 12)) = stack[-5]; // !*ratpri
    v0339 = stack[-3];
    if (v0339 == nil) goto v0298;
    v0339 = stack[-1];
    v0339 = qcar(v0339);
    v0340 = qcdr(v0339);
    v0339 = stack[-3];
    v0339 = qcar(v0339);
    v0339 = qcdr(v0339);
    v0339 = plus2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    stack[-5] = v0339;
    v0339 = stack[-4];
    if (v0339 == nil) goto v0346;
    v0340 = stack[-5];
    v0339 = (LispObject)33; // 2
    v0339 = plus2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    stack[-5] = v0339;
    goto v0346;

v0346:
    stack[0] = stack[-5];
    v0339 = qvalue(elt(env, 9)); // nil
    v0340 = Llinelength(nil, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = qvalue(elt(env, 15)); // spare!*
    v0340 = difference2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = qvalue(elt(env, 16)); // orig!*
    v0339 = difference2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = (LispObject)greaterp2(stack[0], v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    v0339 = v0339 ? lisp_true : nil;
    env = stack[-7];
    if (v0339 == nil) goto v0173;
    v0339 = elt(env, 6); // failed
    goto v0004;

v0173:
    stack[0] = stack[-5];
    v0339 = qvalue(elt(env, 9)); // nil
    v0340 = Llinelength(nil, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = qvalue(elt(env, 15)); // spare!*
    v0340 = difference2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = qvalue(elt(env, 17)); // posn!*
    v0339 = difference2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = (LispObject)greaterp2(stack[0], v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    v0339 = v0339 ? lisp_true : nil;
    env = stack[-7];
    if (v0339 == nil) goto v0347;
    v0339 = qvalue(elt(env, 4)); // t
    fn = elt(env, 22); // terpri!*
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    goto v0347;

v0347:
    v0339 = stack[-4];
    if (v0339 == nil) goto v0348;
    v0339 = elt(env, 18); // "("
    fn = elt(env, 23); // prin2!*
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    goto v0348;

v0348:
    v0339 = stack[-1];
    fn = elt(env, 24); // putpline
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = qvalue(elt(env, 8)); // !*eraise
    if (v0339 == nil) goto v0349;
    v0340 = (LispObject)17; // 1
    v0339 = stack[-3];
    v0339 = qcdr(v0339);
    v0339 = qcar(v0339);
    v0339 = difference2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    stack[-5] = v0339;
    goto v0350;

v0350:
    v0341 = (LispObject)1; // 0
    v0340 = stack[-5];
    v0339 = stack[-3];
    v0339 = qcar(v0339);
    v0339 = qcar(v0339);
    fn = elt(env, 25); // update!-pline
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0341, v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = stack[-3];
    v0339 = qcar(v0339);
    stack[-1] = qcdr(v0339);
    v0339 = stack[-3];
    v0339 = qcdr(v0339);
    v0340 = qcar(v0339);
    v0339 = stack[-5];
    stack[0] = plus2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = stack[-3];
    v0339 = qcdr(v0339);
    v0340 = qcdr(v0339);
    v0339 = stack[-5];
    v0339 = plus2(v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = cons(stack[0], v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = acons(stack[-2], stack[-1], v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    fn = elt(env, 24); // putpline
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = stack[-4];
    if (v0339 == nil) goto v0351;
    v0339 = elt(env, 19); // ")"
    fn = elt(env, 23); // prin2!*
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    goto v0351;

v0351:
    v0339 = nil;
    goto v0004;

v0349:
    v0339 = elt(env, 7); // expt
    fn = elt(env, 26); // oprin
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = (LispObject)1; // 0
    stack[-5] = v0339;
    goto v0350;

v0298:
    v0339 = elt(env, 6); // failed
    goto v0004;

v0175:
    v0339 = stack[-2];
    v0340 = v0339;
    goto v0242;

v0253:
    v0339 = stack[-3];
    fn = elt(env, 27); // negnumberchk
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0345;
    env = stack[-7];
    stack[-3] = v0339;
    goto v0314;

v0344:
    v0339 = qvalue(elt(env, 9)); // nil
    goto v0054;

v0343:
    v0339 = elt(env, 6); // failed
    goto v0004;

v0250:
    v0340 = stack[0];
    v0339 = elt(env, 11); // indexprin
    if (v0340 == v0339) goto v0261;
    v0339 = qvalue(elt(env, 9)); // nil
    goto v0101;

v0101:
    if (v0339 == nil) goto v0091;
    v0339 = qvalue(elt(env, 9)); // nil
    goto v0004;

v0091:
    v0341 = stack[-1];
    v0340 = stack[-2];
    v0339 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 21); // layout!-formula
    v0339 = (*qfnn(fn))(qenv(fn), 3, v0341, v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    stack[-1] = v0339;
    goto v0067;

v0261:
    v0340 = stack[-1];
    v0339 = stack[-3];
    fn = elt(env, 28); // indexpower
    v0340 = (*qfn2(fn))(qenv(fn), v0340, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-7];
    v0339 = elt(env, 6); // failed
    v0339 = (v0340 == v0339 ? lisp_true : nil);
    v0339 = (v0339 == nil ? lisp_true : nil);
    goto v0101;

v0024:
    v0339 = qvalue(elt(env, 9)); // nil
    goto v0198;

v0133:
    v0339 = qvalue(elt(env, 9)); // nil
    goto v0198;

v0070:
    v0340 = qvalue(elt(env, 4)); // t
    goto v0072;
// error exit handlers
v0345:
    env = stack[-7];
    qvalue(elt(env, 12)) = stack[-5]; // !*ratpri
    qvalue(elt(env, 2)) = stack[-6]; // !*list
    popv(8);
    return nil;
v0342:
    env = stack[-7];
    qvalue(elt(env, 2)) = stack[-6]; // !*list
    popv(8);
    return nil;
}



// Code for vdpputprop

static LispObject CC_vdpputprop(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0192, v0084, v0256, v0257;
    LispObject fn;
    LispObject v0131, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdpputprop");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0131 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpputprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0131,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0131;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    stack[-5] = nil;
    v0192 = stack[-4];
    v0192 = Lconsp(nil, v0192);
    env = stack[-6];
    if (v0192 == nil) goto v0140;
    v0192 = stack[-4];
    v0192 = qcdr(v0192);
    stack[-5] = v0192;
    v0192 = Lconsp(nil, v0192);
    env = stack[-6];
    if (v0192 == nil) goto v0069;
    v0192 = stack[-5];
    v0192 = qcdr(v0192);
    stack[-5] = v0192;
    v0192 = Lconsp(nil, v0192);
    env = stack[-6];
    if (v0192 == nil) goto v0071;
    v0192 = stack[-5];
    v0192 = qcdr(v0192);
    stack[-5] = v0192;
    v0192 = Lconsp(nil, v0192);
    env = stack[-6];
    if (v0192 == nil) goto v0079;
    v0192 = stack[-5];
    v0192 = qcdr(v0192);
    stack[-5] = v0192;
    v0192 = Lconsp(nil, v0192);
    env = stack[-6];
    v0192 = (v0192 == nil ? lisp_true : nil);
    goto v0265;

v0265:
    if (v0192 == nil) goto v0195;
    stack[-1] = elt(env, 2); // dipoly
    stack[0] = (LispObject)97; // 6
    v0257 = elt(env, 3); // "vdpputprop given a non-vdp as 1st parameter"
    v0256 = stack[-4];
    v0084 = stack[-3];
    v0192 = stack[-2];
    v0192 = list4(v0257, v0256, v0084, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-6];
    fn = elt(env, 4); // rerror
    v0192 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-6];
    goto v0195;

v0195:
    v0084 = stack[-3];
    v0192 = stack[-5];
    v0192 = qcar(v0192);
    v0192 = Lassoc(nil, v0084, v0192);
    v0084 = v0192;
    v0192 = v0084;
    if (v0192 == nil) goto v0268;
    v0192 = stack[-2];
    v0192 = Lrplacd(nil, v0084, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    { LispObject res = stack[-4]; popv(7); return onevalue(res); }

v0268:
    stack[0] = stack[-5];
    v0256 = stack[-3];
    v0084 = stack[-2];
    v0192 = stack[-5];
    v0192 = qcar(v0192);
    v0192 = acons(v0256, v0084, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-6];
    v0192 = Lrplaca(nil, stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    { LispObject res = stack[-4]; popv(7); return onevalue(res); }

v0079:
    v0192 = qvalue(elt(env, 1)); // t
    goto v0265;

v0071:
    v0192 = qvalue(elt(env, 1)); // t
    goto v0265;

v0069:
    v0192 = qvalue(elt(env, 1)); // t
    goto v0265;

v0140:
    v0192 = qvalue(elt(env, 1)); // t
    goto v0265;
// error exit handlers
v0187:
    popv(7);
    return nil;
}



// Code for gpexp1p

static LispObject CC_gpexp1p(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0069;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gpexp1p");
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

v0254:
    v0069 = stack[0];
    if (v0069 == nil) goto v0146;
    v0069 = stack[0];
    v0069 = qcar(v0069);
    fn = elt(env, 3); // gpexpp
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    if (v0069 == nil) goto v0127;
    v0069 = stack[0];
    v0069 = qcdr(v0069);
    stack[0] = v0069;
    goto v0254;

v0127:
    v0069 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0069); }

v0146:
    v0069 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0069); }
// error exit handlers
v0004:
    popv(2);
    return nil;
}



setup_type const u17_setup[] =
{
    {"findremainder",           too_few_2,      CC_findremainder,wrong_no_2},
    {"nary",                    too_few_2,      CC_nary,       wrong_no_2},
    {"spband_matrix",           too_few_2,      CC_spband_matrix,wrong_no_2},
    {"inshisto",                CC_inshisto,    too_many_1,    wrong_no_1},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"groebbuchcrit4t",         too_few_2,      CC_groebbuchcrit4t,wrong_no_2},
    {"*pf2wedgepf",             CC_Hpf2wedgepf, too_many_1,    wrong_no_1},
    {"list+list",               too_few_2,      CC_listLlist,  wrong_no_2},
    {"copyd",                   too_few_2,      CC_copyd,      wrong_no_2},
    {"mkcr",                    too_few_2,      CC_mkcr,       wrong_no_2},
    {"simpiden",                CC_simpiden,    too_many_1,    wrong_no_1},
    {"traput",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_traput},
    {"polynomheadreduceby",     too_few_2,      CC_polynomheadreduceby,wrong_no_2},
    {"exptcompare",             too_few_2,      CC_exptcompare,wrong_no_2},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,too_many_1,wrong_no_1},
    {"ibalp_initwl",            CC_ibalp_initwl,too_many_1,    wrong_no_1},
    {"sf_member",               too_few_2,      CC_sf_member,  wrong_no_2},
    {"variableom",              CC_variableom,  too_many_1,    wrong_no_1},
    {"onoff",                   too_few_2,      CC_onoff,      wrong_no_2},
    {"guesspftype",             CC_guesspftype, too_many_1,    wrong_no_1},
    {"deleteall",               too_few_2,      CC_deleteall,  wrong_no_2},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"lesspcdr",                too_few_2,      CC_lesspcdr,   wrong_no_2},
    {"sqp",                     CC_sqp,         too_many_1,    wrong_no_1},
    {"ra_refine1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_ra_refine1},
    {"putd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_putd},
    {"replus",                  CC_replus,      too_many_1,    wrong_no_1},
    {"wusort",                  CC_wusort,      too_many_1,    wrong_no_1},
    {"expnd1",                  CC_expnd1,      too_many_1,    wrong_no_1},
    {"aex_simplenullp",         CC_aex_simplenullp,too_many_1, wrong_no_1},
    {"mml2om",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mml2om},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"equalreplaceby",          CC_equalreplaceby,too_many_1,  wrong_no_1},
    {"command",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_command},
    {"ord2",                    too_few_2,      CC_ord2,       wrong_no_2},
    {"b:extadd",                too_few_2,      CC_bTextadd,   wrong_no_2},
    {"general-reduce-degree-mod-p",too_few_2,   CC_generalKreduceKdegreeKmodKp,wrong_no_2},
    {"expt-mod-p",              too_few_2,      CC_exptKmodKp, wrong_no_2},
    {"crprcd2",                 too_few_2,      CC_crprcd2,    wrong_no_2},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ibalp_unvar-unsatlist",   too_few_2,      CC_ibalp_unvarKunsatlist,wrong_no_2},
    {"exptpri",                 too_few_2,      CC_exptpri,    wrong_no_2},
    {"vdpputprop",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpputprop},
    {"gpexp1p",                 CC_gpexp1p,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u17", (two_args *)"9771 845578 714476", 0}
};

// end of generated code
