
// $destdir/u18.c        Machine generated C code

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



// Code for add2resultbuf

static LispObject CC_add2resultbuf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0023, v0024, v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add2resultbuf");
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
    v0023 = qvalue(elt(env, 1)); // !*libreduce_active
    if (v0023 == nil) goto v0026;
    fn = elt(env, 15); // lr_result
    v0023 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0024 = qvalue(elt(env, 2)); // semic!*
    v0023 = elt(env, 3); // !$
    if (v0024 == v0023) goto v0028;
    v0024 = stack[-1];
    v0023 = stack[0];
    fn = elt(env, 16); // lr_printer
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    goto v0028;

v0028:
    fn = elt(env, 17); // lr_statcounter
    v0023 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0023 = qvalue(elt(env, 4)); // statcounter
    v0023 = Lprinc(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    fn = elt(env, 18); // lr_mode
    v0023 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0024 = qvalue(elt(env, 5)); // !*mode
    v0023 = elt(env, 6); // symbolic
    if (v0024 == v0023) goto v0029;
    v0023 = (LispObject)1; // 0
    goto v0030;

v0030:
    v0023 = Lprinc(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    fn = elt(env, 19); // lr_posttext
    v0023 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0023 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    goto v0026;

v0026:
    v0024 = stack[0];
    v0023 = elt(env, 6); // symbolic
    if (v0024 == v0023) goto v0031;
    v0023 = stack[-1];
    if (v0023 == nil) goto v0032;
    v0023 = qvalue(elt(env, 10)); // nil
    goto v0033;

v0033:
    if (v0023 == nil) goto v0034;
    v0023 = qvalue(elt(env, 7)); // t
    goto v0035;

v0035:
    if (v0023 == nil) goto v0036;
    v0023 = qvalue(elt(env, 10)); // nil
    { popv(3); return onevalue(v0023); }

v0036:
    v0023 = qvalue(elt(env, 8)); // !*reduce4
    if (v0023 == nil) goto v0037;
    v0025 = elt(env, 12); // ws
    v0024 = stack[-1];
    v0023 = stack[0];
    fn = elt(env, 20); // putobject
    v0023 = (*qfnn(fn))(qenv(fn), 3, v0025, v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    goto v0038;

v0038:
    fn = elt(env, 21); // terminalp
    v0023 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    if (v0023 == nil) goto v0039;
    v0025 = qvalue(elt(env, 4)); // statcounter
    v0024 = stack[-1];
    v0023 = qvalue(elt(env, 14)); // resultbuflis!*
    v0023 = acons(v0025, v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    qvalue(elt(env, 14)) = v0023; // resultbuflis!*
    goto v0039;

v0039:
    v0023 = nil;
    { popv(3); return onevalue(v0023); }

v0037:
    v0023 = qvalue(elt(env, 10)); // nil
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    qvalue(elt(env, 13)) = v0023; // alglist!*
    v0023 = stack[-1];
    qvalue(elt(env, 12)) = v0023; // ws
    goto v0038;

v0034:
    v0023 = qvalue(elt(env, 11)); // !*nosave!*
    goto v0035;

v0032:
    v0023 = qvalue(elt(env, 8)); // !*reduce4
    if (v0023 == nil) goto v0040;
    v0024 = stack[0];
    v0023 = elt(env, 9); // empty_list
    v0023 = (v0024 == v0023 ? lisp_true : nil);
    v0023 = (v0023 == nil ? lisp_true : nil);
    goto v0033;

v0040:
    v0023 = qvalue(elt(env, 7)); // t
    goto v0033;

v0031:
    v0023 = qvalue(elt(env, 7)); // t
    goto v0035;

v0029:
    v0023 = (LispObject)17; // 1
    goto v0030;
// error exit handlers
v0027:
    popv(3);
    return nil;
}



// Code for mo_from_a

static LispObject CC_mo_from_a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_from_a");
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
    stack[0] = stack[-3];
    v0055 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 4); // ring_all_names
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    v0055 = Lmember(nil, stack[0], v0055);
    if (v0055 == nil) goto v0058;
    v0055 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 4); // ring_all_names
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    stack[-4] = v0055;
    v0055 = stack[-4];
    if (v0055 == nil) goto v0059;
    v0055 = stack[-4];
    v0055 = qcar(v0055);
    v0056 = v0055;
    v0055 = stack[-3];
    if (equal(v0056, v0055)) goto v0060;
    v0055 = (LispObject)1; // 0
    goto v0061;

v0061:
    v0055 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    stack[-1] = v0055;
    stack[-2] = v0055;
    goto v0016;

v0016:
    v0055 = stack[-4];
    v0055 = qcdr(v0055);
    stack[-4] = v0055;
    v0055 = stack[-4];
    if (v0055 == nil) goto v0062;
    stack[0] = stack[-1];
    v0055 = stack[-4];
    v0055 = qcar(v0055);
    v0056 = v0055;
    v0055 = stack[-3];
    if (equal(v0056, v0055)) goto v0063;
    v0055 = (LispObject)1; // 0
    goto v0064;

v0064:
    v0055 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    v0055 = Lrplacd(nil, stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    v0055 = stack[-1];
    v0055 = qcdr(v0055);
    stack[-1] = v0055;
    goto v0016;

v0063:
    v0055 = (LispObject)17; // 1
    goto v0064;

v0062:
    v0055 = stack[-2];
    goto v0065;

v0065:
    fn = elt(env, 5); // mo!=shorten
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    stack[0] = v0055;
    fn = elt(env, 6); // mo!=deglist
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    {
        LispObject v0066 = stack[0];
        popv(6);
        return cons(v0066, v0055);
    }

v0060:
    v0055 = (LispObject)17; // 1
    goto v0061;

v0059:
    v0055 = qvalue(elt(env, 3)); // nil
    goto v0065;

v0058:
    v0056 = stack[-3];
    v0055 = elt(env, 2); // "dpoly variable"
    {
        popv(6);
        fn = elt(env, 7); // typerr
        return (*qfn2(fn))(qenv(fn), v0056, v0055);
    }
// error exit handlers
v0057:
    popv(6);
    return nil;
}



// Code for class

static LispObject CC_class(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0030, v0029;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for class");
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
    v0030 = stack[0];
    fn = elt(env, 3); // ord
    v0029 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    v0030 = (LispObject)1; // 0
    if (v0029 == v0030) goto v0070;
    v0029 = qvalue(elt(env, 1)); // ordering
    v0030 = elt(env, 2); // lex
    if (v0029 == v0030) goto v0022;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    goto v0021;

v0021:
    v0030 = Lreverse(nil, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    fn = elt(env, 4); // leftzeros
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    v0030 = (LispObject)((int32_t)(v0030) + 0x10);
    { popv(2); return onevalue(v0030); }

v0022:
    v0030 = stack[0];
    goto v0021;

v0070:
    v0030 = (LispObject)1; // 0
    { popv(2); return onevalue(v0030); }
// error exit handlers
v0069:
    popv(2);
    return nil;
}



// Code for moduntag

static LispObject CC_moduntag(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0075, v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for moduntag");
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
    goto v0054;

v0054:
    v0036 = stack[0];
    v0075 = elt(env, 1); // !:mod!:
    if (!consp(v0036)) goto v0076;
    v0036 = qcar(v0036);
    if (!(v0036 == v0075)) goto v0076;
    v0036 = stack[-1];
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    {
        popv(3);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0036, v0075);
    }

v0076:
    v0075 = stack[0];
    if (!consp(v0075)) goto v0050;
    v0075 = stack[0];
    v0075 = qcar(v0075);
    v0036 = CC_moduntag(env, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-2];
    v0075 = stack[-1];
    v0075 = cons(v0036, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-2];
    stack[-1] = v0075;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    stack[0] = v0075;
    goto v0054;

v0050:
    v0036 = stack[-1];
    v0075 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0036, v0075);
    }
// error exit handlers
v0008:
    popv(3);
    return nil;
}



// Code for gcref_select

static LispObject CC_gcref_select(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056, v0086;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcref_select");
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
    v0055 = v0000;
// end of prologue
    stack[-3] = v0055;
    goto v0087;

v0087:
    v0055 = stack[-3];
    if (v0055 == nil) goto v0028;
    v0055 = stack[-3];
    v0055 = qcar(v0055);
    v0086 = v0055;
    v0056 = v0086;
    v0055 = elt(env, 2); // defd
    v0055 = Lflagp(nil, v0056, v0055);
    env = stack[-4];
    if (v0055 == nil) goto v0017;
    v0056 = v0086;
    v0055 = qvalue(elt(env, 3)); // gcref_nolist!*
    v0055 = Lmemq(nil, v0056, v0055);
    v0055 = (v0055 == nil ? lisp_true : nil);
    goto v0073;

v0073:
    if (v0055 == nil) goto v0053;
    v0055 = v0086;
    v0055 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-4];
    goto v0021;

v0021:
    stack[-2] = v0055;
    v0055 = stack[-2];
    fn = elt(env, 4); // lastpair
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-4];
    stack[-1] = v0055;
    v0055 = stack[-3];
    v0055 = qcdr(v0055);
    stack[-3] = v0055;
    v0055 = stack[-1];
    if (!consp(v0055)) goto v0087;
    else goto v0088;

v0088:
    v0055 = stack[-3];
    if (v0055 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0055 = stack[-3];
    v0055 = qcar(v0055);
    v0086 = v0055;
    v0056 = v0086;
    v0055 = elt(env, 2); // defd
    v0055 = Lflagp(nil, v0056, v0055);
    env = stack[-4];
    if (v0055 == nil) goto v0089;
    v0056 = v0086;
    v0055 = qvalue(elt(env, 3)); // gcref_nolist!*
    v0055 = Lmemq(nil, v0056, v0055);
    v0055 = (v0055 == nil ? lisp_true : nil);
    goto v0011;

v0011:
    if (v0055 == nil) goto v0044;
    v0055 = v0086;
    v0055 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-4];
    goto v0090;

v0090:
    v0055 = Lrplacd(nil, stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-4];
    v0055 = stack[-1];
    fn = elt(env, 4); // lastpair
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-4];
    stack[-1] = v0055;
    v0055 = stack[-3];
    v0055 = qcdr(v0055);
    stack[-3] = v0055;
    goto v0088;

v0044:
    v0055 = nil;
    goto v0090;

v0089:
    v0055 = qvalue(elt(env, 1)); // nil
    goto v0011;

v0053:
    v0055 = nil;
    goto v0021;

v0017:
    v0055 = qvalue(elt(env, 1)); // nil
    goto v0073;

v0028:
    v0055 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0055); }
// error exit handlers
v0057:
    popv(5);
    return nil;
}



// Code for ofsf_entry2at

static LispObject CC_ofsf_entry2at(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0065, v0016, v0030, v0029;
    LispObject fn;
    LispObject v0072, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_entry2at");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0072 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_entry2at");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0072,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0072);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0016 = v0072;
    v0030 = v0001;
    v0029 = v0000;
// end of prologue
    v0065 = qvalue(elt(env, 1)); // !*rlidentify
    if (v0065 == nil) goto v0073;
    v0065 = v0029;
    fn = elt(env, 2); // ofsf_entry2at1
    v0065 = (*qfnn(fn))(qenv(fn), 3, v0065, v0030, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // cl_identifyat
        return (*qfn1(fn))(qenv(fn), v0065);
    }

v0073:
    v0065 = v0029;
    {
        popv(1);
        fn = elt(env, 2); // ofsf_entry2at1
        return (*qfnn(fn))(qenv(fn), 3, v0065, v0030, v0016);
    }
// error exit handlers
v0091:
    popv(1);
    return nil;
}



// Code for simp!*sq

static LispObject CC_simpHsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0067, v0021;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp*sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0021 = v0000;
// end of prologue
    v0067 = v0021;
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    if (v0067 == nil) goto v0092;
    v0067 = qvalue(elt(env, 1)); // !*resimp
    if (!(v0067 == nil)) goto v0092;
    v0067 = v0021;
    v0067 = qcar(v0067);
    return onevalue(v0067);

v0092:
    v0067 = v0021;
    v0067 = qcar(v0067);
    {
        fn = elt(env, 2); // resimp1
        return (*qfn1(fn))(qenv(fn), v0067);
    }
}



// Code for rl_nnf

static LispObject CC_rl_nnf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_nnf");
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
    v0054 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_nnf!*
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-1];
    {
        LispObject v0092 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0092, v0054);
    }
// error exit handlers
v0068:
    popv(2);
    return nil;
}



// Code for qqe_simplterm

static LispObject CC_qqe_simplterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0093, v0094, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_simplterm");
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
    v0093 = stack[0];
    if (!consp(v0093)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0093 = stack[0];
    fn = elt(env, 4); // qqe_op
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    v0008 = v0093;
    v0094 = v0008;
    v0093 = elt(env, 1); // (ltail rtail)
    v0093 = Lmemq(nil, v0094, v0093);
    if (v0093 == nil) goto v0020;
    v0093 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // qqe_simplterm!-tail
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0020:
    v0094 = v0008;
    v0093 = elt(env, 2); // (lhead rhead)
    v0093 = Lmemq(nil, v0094, v0093);
    if (v0093 == nil) goto v0085;
    v0093 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); // qqe_simplterm!-head
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0085:
    v0094 = v0008;
    v0093 = elt(env, 3); // (ladd radd)
    v0093 = Lmemq(nil, v0094, v0093);
    if (v0093 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0093 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); // qqe_simplterm!-add
        return (*qfn1(fn))(qenv(fn), v0093);
    }
// error exit handlers
v0031:
    popv(2);
    return nil;
}



// Code for rl_susipost

static LispObject CC_rl_susipost(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0083, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_susipost");
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
    v0083 = v0001;
    v0067 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_susipost!*
    v0083 = list2(v0067, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    {
        LispObject v0053 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0053, v0083);
    }
// error exit handlers
v0022:
    popv(2);
    return nil;
}



// Code for rl_simp1

static LispObject CC_rl_simp1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0124, v0125, v0126, v0127;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simp1");
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
    stack[0] = v0000;
// end of prologue

v0128:
    v0124 = qvalue(elt(env, 1)); // rl_cid!*
    if (!(v0124 == nil)) goto v0087;
    v0124 = elt(env, 2); // "select a context"
    v0124 = ncons(v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    fn = elt(env, 12); // rederr
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    goto v0087;

v0087:
    v0124 = stack[0];
    if (!consp(v0124)) goto v0058;
    v0124 = qvalue(elt(env, 3)); // t
    stack[-1] = qvalue(elt(env, 4)); // !*strict_argcount
    qvalue(elt(env, 4)) = v0124; // !*strict_argcount
    v0124 = stack[0];
    fn = elt(env, 13); // argnochk
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; // !*strict_argcount
    v0124 = stack[0];
    v0125 = qcar(v0124);
    v0124 = elt(env, 5); // rl_simpfn
    v0124 = get(v0125, v0124);
    env = stack[-5];
    v0125 = v0124;
    if (v0124 == nil) goto v0009;
    v0124 = v0125;
    if (!symbolp(v0124)) v0124 = nil;
    else { v0124 = qfastgets(v0124);
           if (v0124 != nil) { v0124 = elt(v0124, 62); // full
#ifdef RECORD_GET
             if (v0124 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v0124 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v0124 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v0124 == SPID_NOPROP) v0124 = nil; else v0124 = lisp_true; }}
#endif
    if (v0124 == nil) goto v0008;
    stack[-1] = v0125;
    v0124 = stack[0];
    v0124 = ncons(v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    {
        LispObject v0131 = stack[-1];
        popv(6);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0131, v0124);
    }

v0008:
    stack[-1] = v0125;
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    v0124 = ncons(v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    {
        LispObject v0132 = stack[-1];
        popv(6);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0132, v0124);
    }

v0009:
    v0124 = stack[0];
    v0126 = qcar(v0124);
    v0124 = qvalue(elt(env, 1)); // rl_cid!*
    v0125 = qcar(v0124);
    v0124 = elt(env, 6); // simpfnname
    v0124 = get(v0125, v0124);
    env = stack[-5];
    v0124 = get(v0126, v0124);
    env = stack[-5];
    v0125 = v0124;
    if (v0124 == nil) goto v0015;
    v0124 = v0125;
    if (!symbolp(v0124)) v0124 = nil;
    else { v0124 = qfastgets(v0124);
           if (v0124 != nil) { v0124 = elt(v0124, 62); // full
#ifdef RECORD_GET
             if (v0124 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v0124 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v0124 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v0124 == SPID_NOPROP) v0124 = nil; else v0124 = lisp_true; }}
#endif
    if (v0124 == nil) goto v0133;
    stack[-1] = v0125;
    v0124 = stack[0];
    v0124 = ncons(v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    {
        LispObject v0134 = stack[-1];
        popv(6);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0134, v0124);
    }

v0133:
    stack[-1] = v0125;
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    v0124 = ncons(v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    {
        LispObject v0135 = stack[-1];
        popv(6);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0135, v0124);
    }

v0015:
    v0124 = stack[0];
    v0124 = qcar(v0124);
    if (!symbolp(v0124)) v0124 = nil;
    else { v0124 = qfastgets(v0124);
           if (v0124 != nil) { v0124 = elt(v0124, 45); // psopfn
#ifdef RECORD_GET
             if (v0124 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0124 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0124 == SPID_NOPROP) v0124 = nil; }}
#endif
    v0125 = v0124;
    if (v0124 == nil) goto v0136;
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    v0124 = Lapply1(nil, v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[-1] = v0124;
    v0125 = stack[-1];
    v0124 = stack[0];
    if (equal(v0125, v0124)) goto v0136;
    v0124 = stack[-1];
    stack[0] = v0124;
    goto v0128;

v0136:
    v0124 = stack[0];
    v0124 = qcar(v0124);
    if (!symbolp(v0124)) v0124 = nil;
    else { v0124 = qfastgets(v0124);
           if (v0124 != nil) { v0124 = elt(v0124, 59); // opfn
#ifdef RECORD_GET
             if (v0124 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0124 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0124 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0124 == SPID_NOPROP) v0124 = nil; else v0124 = lisp_true; }}
#endif
    if (v0124 == nil) goto v0025;
    v0124 = stack[0];
    stack[-4] = qcar(v0124);
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    stack[-3] = v0124;
    v0124 = stack[-3];
    if (v0124 == nil) goto v0137;
    v0124 = stack[-3];
    v0124 = qcar(v0124);
    fn = elt(env, 15); // reval
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0124 = ncons(v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[-1] = v0124;
    stack[-2] = v0124;
    goto v0138;

v0138:
    v0124 = stack[-3];
    v0124 = qcdr(v0124);
    stack[-3] = v0124;
    v0124 = stack[-3];
    if (v0124 == nil) goto v0139;
    stack[0] = stack[-1];
    v0124 = stack[-3];
    v0124 = qcar(v0124);
    fn = elt(env, 15); // reval
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0124 = ncons(v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0124 = Lrplacd(nil, stack[0], v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0124 = stack[-1];
    v0124 = qcdr(v0124);
    stack[-1] = v0124;
    goto v0138;

v0139:
    v0124 = stack[-2];
    goto v0140;

v0140:
    fn = elt(env, 14); // apply
    v0124 = (*qfn2(fn))(qenv(fn), stack[-4], v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[0] = v0124;
    goto v0128;

v0137:
    v0124 = qvalue(elt(env, 7)); // nil
    goto v0140;

v0025:
    v0124 = stack[0];
    v0124 = qcar(v0124);
    if (!symbolp(v0124)) v0124 = nil;
    else { v0124 = qfastgets(v0124);
           if (v0124 != nil) { v0124 = elt(v0124, 44); // prepfn2
#ifdef RECORD_GET
             if (v0124 != SPID_NOPROP)
                record_get(elt(fastget_names, 44), 1);
             else record_get(elt(fastget_names, 44), 0),
                v0124 = nil; }
           else record_get(elt(fastget_names, 44), 0); }
#else
             if (v0124 == SPID_NOPROP) v0124 = nil; }}
#endif
    v0125 = v0124;
    if (v0124 == nil) goto v0141;
    stack[-1] = v0125;
    v0124 = stack[0];
    v0124 = ncons(v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    fn = elt(env, 14); // apply
    v0124 = (*qfn2(fn))(qenv(fn), stack[-1], v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[0] = v0124;
    goto v0128;

v0141:
    v0124 = stack[0];
    v0124 = qcar(v0124);
    fn = elt(env, 16); // ioto_form2str
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[-1] = v0124;
    v0124 = stack[0];
    v0124 = qcar(v0124);
    if (!symbolp(v0124)) v0124 = nil;
    else { v0124 = qfastgets(v0124);
           if (v0124 != nil) { v0124 = elt(v0124, 37); // prtch
#ifdef RECORD_GET
             if (v0124 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0124 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0124 == SPID_NOPROP) v0124 = nil; }}
#endif
    v0125 = v0124;
    if (v0124 == nil) goto v0142;
    v0124 = v0125;
    fn = elt(env, 16); // ioto_form2str
    v0127 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0126 = elt(env, 8); // " ("
    v0125 = stack[-1];
    v0124 = elt(env, 9); // ")"
    v0124 = list4(v0127, v0126, v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    fn = elt(env, 17); // lto_sconcat
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[-1] = v0124;
    goto v0142;

v0142:
    v0125 = stack[-1];
    v0124 = elt(env, 10); // "predicate"
    fn = elt(env, 18); // redmsg
    v0124 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0124 = stack[0];
    v0127 = qcar(v0124);
    v0124 = qvalue(elt(env, 1)); // rl_cid!*
    v0125 = qcar(v0124);
    v0124 = elt(env, 6); // simpfnname
    v0126 = get(v0125, v0124);
    env = stack[-5];
    v0124 = qvalue(elt(env, 1)); // rl_cid!*
    v0125 = qcar(v0124);
    v0124 = elt(env, 11); // simpdefault
    v0124 = get(v0125, v0124);
    env = stack[-5];
    v0124 = Lputprop(nil, 3, v0127, v0126, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0124 = stack[0];
    stack[0] = v0124;
    goto v0128;

v0058:
    v0124 = stack[0];
    {
        popv(6);
        fn = elt(env, 19); // rl_simpatom
        return (*qfn1(fn))(qenv(fn), v0124);
    }
// error exit handlers
v0130:
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; // !*strict_argcount
    popv(6);
    return nil;
v0129:
    popv(6);
    return nil;
}



// Code for aex_simpleratp

static LispObject CC_aex_simpleratp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0048, v0050;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_simpleratp");
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
    v0048 = v0000;
// end of prologue
    fn = elt(env, 2); // aex_ex
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-1];
    stack[0] = v0048;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    if (is_number(v0048)) goto v0083;
    v0048 = qvalue(elt(env, 1)); // nil
    goto v0076;

v0076:
    if (!(v0048 == nil)) { popv(2); return onevalue(v0048); }
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0048 = (v0048 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0048); }

v0083:
    v0048 = stack[0];
    v0050 = qcar(v0048);
    v0048 = (LispObject)1; // 0
    v0048 = Leqn(nil, v0050, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0048 = (v0048 == nil ? lisp_true : nil);
    goto v0076;
// error exit handlers
v0043:
    popv(2);
    return nil;
}



// Code for powers4

static LispObject CC_powers4(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0178, v0179, v0180;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers4");
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
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0181;

v0181:
    v0178 = stack[-1];
    if (v0178 == nil) goto v0068;
    v0178 = stack[0];
    if (v0178 == nil) goto v0081;
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0179 = qcar(v0178);
    v0178 = stack[0];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    if (equal(v0179, v0178)) goto v0182;
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0179 = qcar(v0178);
    v0178 = stack[0];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    fn = elt(env, 2); // ordop
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    if (v0178 == nil) goto v0184;
    v0178 = stack[0];
    v0178 = qcar(v0178);
    v0179 = qcdr(v0178);
    v0178 = (LispObject)1; // 0
    v0178 = Lrplacd(nil, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    stack[-2] = stack[0];
    v0179 = stack[-1];
    v0178 = stack[0];
    v0178 = qcdr(v0178);
    v0178 = CC_powers4(env, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = Lrplacd(nil, stack[-2], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    {
        LispObject v0185 = stack[-3];
        popv(6);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0185, v0178);
    }

v0184:
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    stack[-2] = qcar(v0178);
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0179 = qcdr(v0178);
    v0178 = (LispObject)1; // 0
    v0179 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = stack[-3];
    v0178 = acons(stack[-2], v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    stack[-3] = v0178;
    v0178 = stack[-1];
    v0178 = qcdr(v0178);
    stack[-1] = v0178;
    goto v0181;

v0182:
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0179 = qcdr(v0178);
    v0178 = stack[0];
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    v0178 = (LispObject)greaterp2(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0178 = v0178 ? lisp_true : nil;
    env = stack[-5];
    if (v0178 == nil) goto v0186;
    v0178 = stack[0];
    v0178 = qcar(v0178);
    v0179 = qcdr(v0178);
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0178 = Lrplaca(nil, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    goto v0186;

v0186:
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0179 = qcdr(v0178);
    v0178 = stack[0];
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = (LispObject)lessp2(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0178 = v0178 ? lisp_true : nil;
    env = stack[-5];
    if (v0178 == nil) goto v0187;
    v0178 = stack[0];
    v0178 = qcar(v0178);
    v0179 = qcdr(v0178);
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0178 = Lrplacd(nil, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    goto v0187;

v0187:
    stack[-2] = stack[0];
    v0178 = stack[-1];
    v0179 = qcdr(v0178);
    v0178 = stack[0];
    v0178 = qcdr(v0178);
    v0178 = CC_powers4(env, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = Lrplacd(nil, stack[-2], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    {
        LispObject v0188 = stack[-3];
        popv(6);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0188, v0178);
    }

v0081:
    stack[-4] = stack[-3];
    v0178 = stack[-1];
    stack[-3] = v0178;
    v0178 = stack[-3];
    if (v0178 == nil) goto v0133;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0179 = v0178;
    v0180 = qcar(v0179);
    v0179 = qcdr(v0178);
    v0178 = (LispObject)1; // 0
    v0178 = list2star(v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    stack[-1] = v0178;
    stack[-2] = v0178;
    goto v0034;

v0034:
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    stack[-3] = v0178;
    v0178 = stack[-3];
    if (v0178 == nil) goto v0189;
    stack[0] = stack[-1];
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0179 = v0178;
    v0180 = qcar(v0179);
    v0179 = qcdr(v0178);
    v0178 = (LispObject)1; // 0
    v0178 = list2star(v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = Lrplacd(nil, stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = stack[-1];
    v0178 = qcdr(v0178);
    stack[-1] = v0178;
    goto v0034;

v0189:
    v0178 = stack[-2];
    goto v0012;

v0012:
    {
        LispObject v0190 = stack[-4];
        popv(6);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0190, v0178);
    }

v0133:
    v0178 = qvalue(elt(env, 1)); // nil
    goto v0012;

v0068:
    stack[-4] = stack[-3];
    v0178 = stack[0];
    stack[-3] = v0178;
    v0178 = stack[-3];
    if (v0178 == nil) goto v0019;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0179 = v0178;
    v0180 = qcar(v0179);
    v0178 = qcdr(v0178);
    v0179 = qcar(v0178);
    v0178 = (LispObject)1; // 0
    v0178 = list2star(v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    stack[-1] = v0178;
    stack[-2] = v0178;
    goto v0073;

v0073:
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    stack[-3] = v0178;
    v0178 = stack[-3];
    if (v0178 == nil) goto v0093;
    stack[0] = stack[-1];
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0179 = v0178;
    v0180 = qcar(v0179);
    v0178 = qcdr(v0178);
    v0179 = qcar(v0178);
    v0178 = (LispObject)1; // 0
    v0178 = list2star(v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = Lrplacd(nil, stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = stack[-1];
    v0178 = qcdr(v0178);
    stack[-1] = v0178;
    goto v0073;

v0093:
    v0178 = stack[-2];
    goto v0058;

v0058:
    {
        LispObject v0191 = stack[-4];
        popv(6);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0191, v0178);
    }

v0019:
    v0178 = qvalue(elt(env, 1)); // nil
    goto v0058;
// error exit handlers
v0183:
    popv(6);
    return nil;
}



// Code for tobvarir

static LispObject CC_tobvarir(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0048, v0050;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tobvarir");
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
    v0048 = stack[-1];
    if (v0048 == nil) goto v0193;
    stack[-2] = elt(env, 1); // bvar
    v0048 = stack[-1];
    v0050 = qcar(v0048);
    v0048 = (LispObject)17; // 1
    stack[0] = list2(v0050, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    v0048 = stack[-1];
    v0048 = qcdr(v0048);
    v0048 = CC_tobvarir(env, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    {
        LispObject v0030 = stack[-2];
        LispObject v0029 = stack[0];
        popv(4);
        return acons(v0030, v0029, v0048);
    }

v0193:
    v0048 = nil;
    { popv(4); return onevalue(v0048); }
// error exit handlers
v0016:
    popv(4);
    return nil;
}



// Code for floatprop

static LispObject CC_floatprop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0194, v0058;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for floatprop");
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
    v0194 = v0000;
// end of prologue
    v0058 = v0194;
    v0058 = Lfloatp(nil, v0058);
    env = stack[0];
    if (!(v0058 == nil)) { popv(1); return onevalue(v0058); }
    v0058 = elt(env, 1); // !:rd!:
        popv(1);
        return Leqcar(nil, v0194, v0058);
}



// Code for inttovec

static LispObject CC_inttovec(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0083, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inttovec");
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
    v0067 = v0001;
    v0083 = v0000;
// end of prologue
    stack[0] = v0067;
    fn = elt(env, 1); // inttovec!-solve
    v0083 = (*qfn2(fn))(qenv(fn), v0067, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    {
        LispObject v0053 = stack[0];
        popv(2);
        fn = elt(env, 2); // inttovec1
        return (*qfn2(fn))(qenv(fn), v0053, v0083);
    }
// error exit handlers
v0022:
    popv(2);
    return nil;
}



// Code for physopaeval

static LispObject CC_physopaeval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0119, v0089, v0034;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopaeval");
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
    v0119 = stack[0];
    fn = elt(env, 4); // physopp
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-1];
    if (v0119 == nil) goto v0088;
    v0119 = stack[0];
    if (!symbolp(v0119)) v0119 = nil;
    else { v0119 = qfastgets(v0119);
           if (v0119 != nil) { v0119 = elt(v0119, 46); // rvalue
#ifdef RECORD_GET
             if (v0119 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v0119 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v0119 == SPID_NOPROP) v0119 = nil; }}
#endif
    v0034 = v0119;
    if (v0119 == nil) goto v0092;
    v0119 = v0034;
    v0089 = qcar(v0119);
    v0119 = elt(env, 1); // !*sq
    if (!(v0089 == v0119)) { popv(2); return onevalue(v0034); }
    v0119 = v0034;
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    {
        popv(2);
        fn = elt(env, 5); // !*q2a
        return (*qfn1(fn))(qenv(fn), v0119);
    }

v0092:
    v0119 = stack[0];
    if (!consp(v0119)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0119 = stack[0];
    v0089 = qcar(v0119);
    v0119 = elt(env, 2); // psimpfn
    v0119 = get(v0089, v0119);
    env = stack[-1];
    v0034 = v0119;
    if (v0119 == nil) goto v0085;
    v0089 = v0034;
    v0119 = stack[0];
        popv(2);
        return Lapply1(nil, v0089, v0119);

v0085:
    v0119 = stack[0];
    v0119 = qcar(v0119);
    if (!symbolp(v0119)) v0119 = nil;
    else { v0119 = qfastgets(v0119);
           if (v0119 != nil) { v0119 = elt(v0119, 9); // opmtch
#ifdef RECORD_GET
             if (v0119 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0119 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0119 == SPID_NOPROP) v0119 = nil; }}
#endif
    if (v0119 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0119 = stack[0];
    fn = elt(env, 6); // opmtch!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    v0034 = v0119;
    if (v0119 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0034); }

v0088:
    v0119 = stack[0];
    if (!consp(v0119)) goto v0080;
    v0119 = stack[0];
    v0089 = qcar(v0119);
    v0119 = elt(env, 1); // !*sq
    v0119 = (v0089 == v0119 ? lisp_true : nil);
    goto v0033;

v0033:
    if (v0119 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0119 = stack[0];
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    {
        popv(2);
        fn = elt(env, 5); // !*q2a
        return (*qfn1(fn))(qenv(fn), v0119);
    }

v0080:
    v0119 = qvalue(elt(env, 3)); // nil
    goto v0033;
// error exit handlers
v0196:
    popv(2);
    return nil;
}



// Code for mkarray1

static LispObject CC_mkarray1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0033, v0032;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkarray1");
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
    stack[-4] = v0001;
    stack[-5] = v0000;
// end of prologue
    v0033 = stack[-5];
    if (v0033 == nil) goto v0028;
    v0033 = stack[-5];
    v0033 = qcar(v0033);
    v0033 = sub1(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    stack[-6] = v0033;
    v0033 = stack[-6];
    v0033 = Lmkvect(nil, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    stack[-3] = v0033;
    v0033 = (LispObject)1; // 0
    stack[-2] = v0033;
    goto v0071;

v0071:
    v0032 = stack[-6];
    v0033 = stack[-2];
    v0033 = difference2(v0032, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0033 = Lminusp(nil, v0033);
    env = stack[-7];
    if (!(v0033 == nil)) { LispObject res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-3];
    stack[0] = stack[-2];
    v0033 = stack[-5];
    v0032 = qcdr(v0033);
    v0033 = stack[-4];
    v0033 = CC_mkarray1(env, v0032, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0033;
    v0033 = stack[-2];
    v0033 = add1(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    stack[-2] = v0033;
    goto v0071;

v0028:
    v0032 = stack[-4];
    v0033 = elt(env, 1); // symbolic
    if (v0032 == v0033) goto v0095;
    v0033 = (LispObject)1; // 0
    { popv(8); return onevalue(v0033); }

v0095:
    v0033 = qvalue(elt(env, 2)); // nil
    { popv(8); return onevalue(v0033); }
// error exit handlers
v0063:
    popv(8);
    return nil;
}



// Code for idcons_ordp

static LispObject CC_idcons_ordp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0092, v0194, v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for idcons_ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0092 = v0001;
    v0194 = v0000;
// end of prologue
    v0058 = v0194;
    v0194 = v0092;
    v0092 = elt(env, 1); // atom_compare
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(qenv(fn), 3, v0058, v0194, v0092);
    }
}



// Code for general!-expt!-mod!-p

static LispObject CC_generalKexptKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0044, v0045, v0011;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-expt-mod-p");
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
    v0011 = v0001;
    stack[0] = v0000;
// end of prologue
    v0045 = v0011;
    v0044 = (LispObject)1; // 0
    if (v0045 == v0044) goto v0193;
    v0045 = v0011;
    v0044 = (LispObject)17; // 1
    if (v0045 == v0044) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0045 = v0011;
    v0044 = (LispObject)33; // 2
    v0044 = Ldivide(nil, v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    stack[-1] = v0044;
    v0045 = stack[0];
    v0044 = stack[-1];
    v0044 = qcar(v0044);
    v0044 = CC_generalKexptKmodKp(env, v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0011 = v0044;
    v0044 = v0011;
    v0045 = v0011;
    fn = elt(env, 1); // general!-times!-mod!-p
    v0044 = (*qfn2(fn))(qenv(fn), v0044, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0011 = v0044;
    v0044 = stack[-1];
    v0045 = qcdr(v0044);
    v0044 = (LispObject)1; // 0
    if (v0045 == v0044) { popv(3); return onevalue(v0011); }
    v0045 = v0011;
    v0044 = stack[0];
    fn = elt(env, 1); // general!-times!-mod!-p
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    v0011 = v0044;
    { popv(3); return onevalue(v0011); }

v0193:
    v0044 = (LispObject)17; // 1
    { popv(3); return onevalue(v0044); }
// error exit handlers
v0046:
    popv(3);
    return nil;
}



// Code for !:expt

static LispObject CC_Texpt(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0110, v0162, v0218;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :expt");
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
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    v0110 = stack[-4];
    if (v0110 == nil) goto v0028;
    v0162 = stack[-3];
    v0110 = (LispObject)1; // 0
    if (v0162 == v0110) goto v0043;
    v0162 = stack[-3];
    v0110 = (LispObject)17; // 1
    if (v0162 == v0110) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    v0162 = stack[-4];
    v0110 = (LispObject)17; // 1
    if (v0162 == v0110) goto v0036;
    v0162 = stack[-3];
    v0110 = (LispObject)1; // 0
    v0110 = (LispObject)lessp2(v0162, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    v0110 = v0110 ? lisp_true : nil;
    env = stack[-6];
    if (v0110 == nil) goto v0177;
    v0110 = stack[-4];
    fn = elt(env, 5); // fieldp
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    if (v0110 == nil) goto v0046;
    v0110 = stack[-4];
    stack[0] = v0110;
    goto v0044;

v0044:
    v0110 = stack[-3];
    v0110 = negate(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    v0110 = CC_Texpt(env, stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 6); // !:recip
        return (*qfn1(fn))(qenv(fn), v0110);
    }

v0046:
    v0110 = stack[-4];
    fn = elt(env, 7); // mkratnum
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    stack[0] = v0110;
    goto v0044;

v0177:
    v0110 = stack[-4];
    if (!consp(v0110)) goto v0172;
    v0110 = stack[-4];
    v0162 = qcar(v0110);
    v0110 = elt(env, 4); // expt
    v0110 = get(v0162, v0110);
    env = stack[-6];
    stack[-2] = v0110;
    if (v0110 == nil) goto v0220;
    v0218 = stack[-2];
    v0162 = stack[-4];
    v0110 = stack[-3];
        popv(7);
        return Lapply2(nil, 3, v0218, v0162, v0110);

v0220:
    v0110 = stack[-4];
    v0110 = qcar(v0110);
    if (!symbolp(v0110)) v0162 = nil;
    else { v0162 = qfastgets(v0110);
           if (v0162 != nil) { v0162 = elt(v0162, 34); // i2d
#ifdef RECORD_GET
             if (v0162 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0162 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0162 == SPID_NOPROP) v0162 = nil; }}
#endif
    v0110 = (LispObject)17; // 1
    v0110 = Lapply1(nil, v0162, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    stack[-5] = v0110;
    v0110 = stack[-4];
    v0110 = qcar(v0110);
    if (!symbolp(v0110)) v0110 = nil;
    else { v0110 = qfastgets(v0110);
           if (v0110 != nil) { v0110 = elt(v0110, 54); // times
#ifdef RECORD_GET
             if (v0110 != SPID_NOPROP)
                record_get(elt(fastget_names, 54), 1);
             else record_get(elt(fastget_names, 54), 0),
                v0110 = nil; }
           else record_get(elt(fastget_names, 54), 0); }
#else
             if (v0110 == SPID_NOPROP) v0110 = nil; }}
#endif
    stack[-2] = v0110;
    goto v0176;

v0176:
    v0110 = stack[-3];
    stack[-1] = v0110;
    stack[0] = (LispObject)33; // 2
    v0162 = stack[-3];
    v0110 = (LispObject)33; // 2
    v0110 = quot2(v0162, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    stack[-3] = v0110;
    v0110 = times2(stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    v0162 = difference2(stack[-1], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    v0110 = (LispObject)1; // 0
    if (v0162 == v0110) goto v0163;
    v0218 = stack[-2];
    v0162 = stack[-4];
    v0110 = stack[-5];
    v0110 = Lapply2(nil, 3, v0218, v0162, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    stack[-5] = v0110;
    goto v0163;

v0163:
    v0162 = stack[-3];
    v0110 = (LispObject)1; // 0
    if (v0162 == v0110) { LispObject res = stack[-5]; popv(7); return onevalue(res); }
    v0218 = stack[-2];
    v0162 = stack[-4];
    v0110 = stack[-4];
    v0110 = Lapply2(nil, 3, v0218, v0162, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    stack[-4] = v0110;
    goto v0176;

v0172:
    v0162 = stack[-4];
    v0110 = stack[-3];
        popv(7);
        return Lexpt(nil, v0162, v0110);

v0036:
    v0110 = (LispObject)17; // 1
    { popv(7); return onevalue(v0110); }

v0043:
    v0110 = (LispObject)17; // 1
    { popv(7); return onevalue(v0110); }

v0028:
    v0162 = stack[-3];
    v0110 = (LispObject)1; // 0
    if (v0162 == v0110) goto v0021;
    v0110 = qvalue(elt(env, 3)); // nil
    { popv(7); return onevalue(v0110); }

v0021:
    v0218 = elt(env, 1); // poly
    v0162 = (LispObject)177; // 11
    v0110 = elt(env, 2); // "0/0 formed"
    {
        popv(7);
        fn = elt(env, 8); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0218, v0162, v0110);
    }
// error exit handlers
v0219:
    popv(7);
    return nil;
}



// Code for ofsf_smmkatl1

static LispObject CC_ofsf_smmkatl1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0059, v0085, v0221, v0222, v0017;
    LispObject fn;
    LispObject v0082, v0072, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smmkatl1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0072 = va_arg(aa, LispObject);
    v0082 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smmkatl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0221 = v0082;
    v0222 = v0072;
    v0017 = v0001;
    v0059 = v0000;
// end of prologue
    v0085 = v0059;
    v0059 = elt(env, 1); // and
    if (v0085 == v0059) goto v0074;
    v0059 = v0017;
    v0085 = v0222;
    {
        fn = elt(env, 2); // ofsf_smmkatl!-or
        return (*qfnn(fn))(qenv(fn), 3, v0059, v0085, v0221);
    }

v0074:
    v0059 = v0017;
    v0085 = v0222;
    {
        fn = elt(env, 3); // ofsf_smmkatl!-and
        return (*qfnn(fn))(qenv(fn), 3, v0059, v0085, v0221);
    }
}



// Code for ibalp_process!-var

static LispObject CC_ibalp_processKvar(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0131, v0132, v0134;
    LispObject fn;
    LispObject v0082, v0072, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ibalp_process-var");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0072 = va_arg(aa, LispObject);
    v0082 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_process-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0082,v0072,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0072,v0082);
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
    stack[-11] = v0082;
    stack[-12] = v0072;
    stack[-13] = v0001;
    stack[-14] = v0000;
// end of prologue
    stack[0] = elt(env, 1); // !!
    v0131 = stack[-12];
    v0131 = Lexplode(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = cons(stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = Lcompress(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = Lintern(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    stack[-12] = v0131;
    v0132 = stack[-12];
    v0131 = stack[-13];
    v0131 = Latsoc(nil, v0132, v0131);
    v0132 = v0131;
    if (v0131 == nil) goto v0029;
    v0131 = v0132;
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    goto v0057;

v0057:
    v0132 = stack[-11];
    v0131 = (LispObject)17; // 1
    v0131 = Leqn(nil, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    if (v0131 == nil) goto v0236;
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    stack[-1] = qcdr(v0131);
    v0132 = stack[-14];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    fn = elt(env, 3); // setcar
    v0131 = (*qfn2(fn))(qenv(fn), stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    stack[-1] = qcdr(v0131);
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = add1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    fn = elt(env, 3); // setcar
    v0131 = (*qfn2(fn))(qenv(fn), stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    stack[-1] = qcdr(v0131);
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = add1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    fn = elt(env, 3); // setcar
    v0131 = (*qfn2(fn))(qenv(fn), stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    stack[-1] = stack[-14];
    v0132 = stack[0];
    v0131 = stack[-14];
    v0131 = qcar(v0131);
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    fn = elt(env, 3); // setcar
    v0131 = (*qfn2(fn))(qenv(fn), stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    { LispObject res = stack[-13]; popv(17); return onevalue(res); }

v0236:
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    stack[-1] = qcdr(v0131);
    v0132 = stack[-14];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    fn = elt(env, 3); // setcar
    v0131 = (*qfn2(fn))(qenv(fn), stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    stack[-1] = qcdr(v0131);
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = add1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    fn = elt(env, 3); // setcar
    v0131 = (*qfn2(fn))(qenv(fn), stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    stack[-1] = qcdr(v0131);
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = add1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    fn = elt(env, 3); // setcar
    v0131 = (*qfn2(fn))(qenv(fn), stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = stack[-14];
    stack[-1] = qcdr(v0131);
    v0132 = stack[0];
    v0131 = stack[-14];
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    fn = elt(env, 3); // setcar
    v0131 = (*qfn2(fn))(qenv(fn), stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    { LispObject res = stack[-13]; popv(17); return onevalue(res); }

v0029:
    stack[-15] = stack[-12];
    stack[-10] = qvalue(elt(env, 2)); // nil
    stack[-9] = qvalue(elt(env, 2)); // nil
    stack[-8] = qvalue(elt(env, 2)); // nil
    stack[-7] = (LispObject)1; // 0
    stack[-6] = (LispObject)1; // 0
    stack[-5] = (LispObject)-15; // -1
    stack[-4] = qvalue(elt(env, 2)); // nil
    stack[-3] = (LispObject)1; // 0
    stack[-2] = (LispObject)1; // 0
    stack[-1] = qvalue(elt(env, 2)); // nil
    stack[0] = (LispObject)1; // 0
    v0134 = qvalue(elt(env, 2)); // nil
    v0132 = (LispObject)1; // 0
    v0131 = qvalue(elt(env, 2)); // nil
    v0131 = list3(v0134, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = list3star(stack[-2], stack[-1], stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = list3star(stack[-5], stack[-4], stack[-3], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = list3star(stack[-8], stack[-7], stack[-6], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    v0131 = list3star(stack[-15], stack[-10], stack[-9], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    stack[0] = v0131;
    v0134 = stack[-12];
    v0132 = stack[0];
    v0131 = stack[-13];
    v0131 = acons(v0134, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-16];
    stack[-13] = v0131;
    goto v0057;
// error exit handlers
v0235:
    popv(17);
    return nil;
}



// Code for mvar_member

static LispObject CC_mvar_member(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0065, v0016, v0030, v0029;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mvar_member");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0030 = v0001;
    v0029 = v0000;
// end of prologue
    v0016 = v0029;
    v0065 = v0030;
    if (equal(v0016, v0065)) goto v0193;
    v0065 = v0030;
    if (!consp(v0065)) goto v0050;
    v0065 = v0029;
    v0016 = v0030;
    v0016 = qcdr(v0016);
    {
        fn = elt(env, 3); // arglist_member
        return (*qfn2(fn))(qenv(fn), v0065, v0016);
    }

v0050:
    v0065 = qvalue(elt(env, 2)); // nil
    return onevalue(v0065);

v0193:
    v0065 = qvalue(elt(env, 1)); // t
    return onevalue(v0065);
}



// Code for om2mml

static LispObject CC_om2mml(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0074;
    LispObject fn;
    argcheck(nargs, 0, "om2mml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for om2mml");
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
    fn = elt(env, 3); // om2ir
    v0074 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    stack[0] = v0074;
    v0074 = qvalue(elt(env, 1)); // t
    fn = elt(env, 4); // terpri!*
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0074 = elt(env, 2); // "Intermediate representation:"
    v0074 = Lprinc(nil, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0074 = qvalue(elt(env, 1)); // t
    fn = elt(env, 4); // terpri!*
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0074 = stack[0];
    v0074 = Lprinc(nil, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0074 = qvalue(elt(env, 1)); // t
    fn = elt(env, 4); // terpri!*
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0074 = stack[0];
    fn = elt(env, 5); // ir2mml
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    v0074 = nil;
    { popv(2); return onevalue(v0074); }
// error exit handlers
v0067:
    popv(2);
    return nil;
}



// Code for evmtest!?

static LispObject CC_evmtestW(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0091, v0069, v0059, v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmtest?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0069 = v0001;
    v0059 = v0000;
// end of prologue

v0193:
    v0091 = v0059;
    if (v0091 == nil) goto v0065;
    v0091 = v0069;
    if (v0091 == nil) goto v0065;
    v0091 = v0059;
    v0085 = qcar(v0091);
    v0091 = v0069;
    v0091 = qcar(v0091);
    if (((int32_t)(v0085)) < ((int32_t)(v0091))) goto v0050;
    v0091 = v0059;
    v0091 = qcdr(v0091);
    v0059 = v0091;
    v0091 = v0069;
    v0091 = qcdr(v0091);
    v0069 = v0091;
    goto v0193;

v0050:
    v0091 = qvalue(elt(env, 1)); // nil
    return onevalue(v0091);

v0065:
    v0091 = v0069;
    {
        fn = elt(env, 2); // evzero!?
        return (*qfn1(fn))(qenv(fn), v0091);
    }
}



// Code for !*wedgepf2pf

static LispObject CC_Hwedgepf2pf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0043, v0065, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *wedgepf2pf");
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
    goto v0193;

v0193:
    v0043 = stack[0];
    if (v0043 == nil) goto v0088;
    v0043 = stack[0];
    v0043 = qcar(v0043);
    v0043 = qcar(v0043);
    fn = elt(env, 1); // mkuwedge
    v0016 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    v0043 = stack[0];
    v0043 = qcar(v0043);
    v0065 = qcdr(v0043);
    v0043 = stack[-1];
    v0043 = acons(v0016, v0065, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    stack[-1] = v0043;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    stack[0] = v0043;
    goto v0193;

v0088:
    v0043 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0043);
    }
// error exit handlers
v0091:
    popv(3);
    return nil;
}



// Code for delete!-dups

static LispObject CC_deleteKdups(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0018, v0071;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete-dups");
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
    v0071 = nil;
    goto v0193;

v0193:
    v0017 = stack[0];
    if (v0017 == nil) goto v0059;
    v0017 = stack[0];
    v0018 = qcar(v0017);
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    v0017 = Lmember(nil, v0018, v0017);
    if (v0017 == nil) goto v0048;
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    stack[0] = v0017;
    goto v0193;

v0048:
    v0017 = stack[0];
    v0017 = qcar(v0017);
    v0018 = v0071;
    v0017 = cons(v0017, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    v0071 = v0017;
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    stack[0] = v0017;
    goto v0193;

v0059:
    v0017 = v0071;
    {
        popv(2);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0017);
    }
// error exit handlers
v0051:
    popv(2);
    return nil;
}



// Code for scal!*list

static LispObject CC_scalHlist(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0065, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scal*list");
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
    goto v0181;

v0181:
    v0065 = stack[0];
    if (v0065 == nil) goto v0076;
    v0016 = stack[-1];
    v0065 = stack[0];
    v0065 = qcar(v0065);
    fn = elt(env, 1); // !:times
    v0016 = (*qfn2(fn))(qenv(fn), v0016, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    v0065 = stack[-2];
    v0065 = cons(v0016, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    stack[-2] = v0065;
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    stack[0] = v0065;
    goto v0181;

v0076:
    v0065 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0065);
    }
// error exit handlers
v0069:
    popv(4);
    return nil;
}



// Code for physop!-ordop

static LispObject CC_physopKordop(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0166, v0241;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physop-ordop");
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
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue

v0128:
    v0166 = stack[-1];
    fn = elt(env, 5); // !*physopp
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-4];
    if (v0166 == nil) goto v0028;
    v0166 = stack[0];
    fn = elt(env, 5); // !*physopp
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-4];
    if (v0166 == nil) goto v0028;
    v0166 = stack[-1];
    if (symbolp(v0166)) goto v0051;
    v0166 = stack[-1];
    v0241 = qcar(v0166);
    v0166 = elt(env, 3); // physopname
    v0166 = get(v0241, v0166);
    env = stack[-4];
    stack[-3] = v0166;
    v0241 = stack[-3];
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    v0166 = cons(v0241, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-4];
    stack[-3] = v0166;
    v0166 = stack[-1];
    v0166 = qcar(v0166);
    stack[-1] = v0166;
    goto v0046;

v0046:
    v0241 = stack[-1];
    v0166 = qvalue(elt(env, 4)); // specoplist!*
    v0166 = Lmember(nil, v0241, v0166);
    if (v0166 == nil) goto v0011;
    v0166 = qvalue(elt(env, 2)); // t
    { popv(5); return onevalue(v0166); }

v0011:
    v0166 = stack[0];
    if (symbolp(v0166)) goto v0172;
    v0166 = stack[0];
    v0241 = qcar(v0166);
    v0166 = elt(env, 3); // physopname
    v0166 = get(v0241, v0166);
    env = stack[-4];
    stack[-2] = v0166;
    v0241 = stack[-2];
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    v0166 = cons(v0241, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-4];
    stack[-2] = v0166;
    v0166 = stack[0];
    v0166 = qcar(v0166);
    stack[0] = v0166;
    goto v0232;

v0232:
    v0241 = stack[0];
    v0166 = qvalue(elt(env, 4)); // specoplist!*
    v0166 = Lmember(nil, v0241, v0166);
    if (v0166 == nil) goto v0118;
    v0166 = qvalue(elt(env, 2)); // t
    { popv(5); return onevalue(v0166); }

v0118:
    v0166 = stack[-3];
    fn = elt(env, 6); // opnum!*
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-4];
    stack[-1] = v0166;
    v0166 = stack[-2];
    fn = elt(env, 6); // opnum!*
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-4];
    stack[0] = v0166;
    v0241 = stack[-1];
    v0166 = stack[0];
    v0166 = (LispObject)lessp2(v0241, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    v0166 = v0166 ? lisp_true : nil;
    env = stack[-4];
    if (v0166 == nil) goto v0116;
    v0166 = qvalue(elt(env, 2)); // t
    { popv(5); return onevalue(v0166); }

v0116:
    v0241 = stack[-1];
    v0166 = stack[0];
    v0166 = (LispObject)greaterp2(v0241, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    v0166 = v0166 ? lisp_true : nil;
    env = stack[-4];
    if (v0166 == nil) goto v0115;
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0166); }

v0115:
    v0166 = stack[-3];
    if (symbolp(v0166)) goto v0137;
    v0166 = stack[-2];
    if (symbolp(v0166)) goto v0206;
    v0166 = stack[-3];
    v0241 = qcdr(v0166);
    v0166 = stack[-2];
    v0166 = qcdr(v0166);
    stack[-1] = v0241;
    stack[0] = v0166;
    goto v0128;

v0206:
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0166); }

v0137:
    v0166 = qvalue(elt(env, 2)); // t
    { popv(5); return onevalue(v0166); }

v0172:
    v0241 = stack[0];
    v0166 = elt(env, 3); // physopname
    v0166 = get(v0241, v0166);
    env = stack[-4];
    stack[-2] = v0166;
    goto v0232;

v0051:
    v0241 = stack[-1];
    v0166 = elt(env, 3); // physopname
    v0166 = get(v0241, v0166);
    env = stack[-4];
    stack[-3] = v0166;
    goto v0046;

v0028:
    v0166 = stack[-1];
    fn = elt(env, 5); // !*physopp
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-4];
    if (v0166 == nil) goto v0084;
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0166); }

v0084:
    v0166 = stack[0];
    fn = elt(env, 5); // !*physopp
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-4];
    if (v0166 == nil) goto v0016;
    v0166 = qvalue(elt(env, 2)); // t
    { popv(5); return onevalue(v0166); }

v0016:
    v0241 = stack[-1];
    v0166 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); // ordop2
        return (*qfn2(fn))(qenv(fn), v0241, v0166);
    }
// error exit handlers
v0242:
    popv(5);
    return nil;
}



// Code for zero!-roads

static LispObject CC_zeroKroads(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0065, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for zero-roads");
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

v0128:
    v0065 = stack[0];
    if (v0065 == nil) goto v0070;
    v0065 = stack[0];
    v0065 = qcar(v0065);
    fn = elt(env, 2); // z!-roads
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    v0016 = v0065;
    v0065 = v0016;
    if (v0065 == nil) goto v0020;
    stack[-1] = v0016;
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = CC_zeroKroads(env, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    {
        LispObject v0069 = stack[-1];
        popv(3);
        return cons(v0069, v0065);
    }

v0020:
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    stack[0] = v0065;
    goto v0128;

v0070:
    v0065 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0065); }
// error exit handlers
v0091:
    popv(3);
    return nil;
}



// Code for revalx

static LispObject CC_revalx(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0073, v0143;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revalx");
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
    v0143 = v0000;
// end of prologue
    v0073 = v0143;
    if (!consp(v0073)) goto v0058;
    v0073 = v0143;
    v0073 = qcar(v0073);
    v0073 = (consp(v0073) ? nil : lisp_true);
    v0073 = (v0073 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0073 == nil) goto v0022;
    v0073 = v0143;
    fn = elt(env, 2); // prepf
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[0];
    goto v0070;

v0070:
    {
        popv(1);
        fn = elt(env, 3); // reval
        return (*qfn1(fn))(qenv(fn), v0073);
    }

v0022:
    v0073 = v0143;
    goto v0070;

v0058:
    v0073 = qvalue(elt(env, 1)); // nil
    goto v0088;
// error exit handlers
v0042:
    popv(1);
    return nil;
}



// Code for repasc

static LispObject CC_repasc(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0063, v0120, v0195;
    LispObject fn;
    LispObject v0072, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "repasc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0072 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repasc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0072,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0072);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0072;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0195 = nil;
    goto v0087;

v0087:
    v0063 = stack[0];
    if (v0063 == nil) goto v0092;
    v0120 = stack[-2];
    v0063 = stack[0];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    if (equal(v0120, v0063)) goto v0036;
    v0063 = stack[0];
    v0063 = qcar(v0063);
    v0120 = v0195;
    v0063 = cons(v0063, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    v0195 = v0063;
    v0063 = stack[0];
    v0063 = qcdr(v0063);
    stack[0] = v0063;
    goto v0087;

v0036:
    stack[-3] = v0195;
    v0195 = stack[-2];
    v0120 = stack[-1];
    v0063 = stack[0];
    v0063 = qcdr(v0063);
    v0063 = acons(v0195, v0120, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    {
        LispObject v0012 = stack[-3];
        popv(5);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0012, v0063);
    }

v0092:
    stack[-3] = v0195;
    stack[-1] = elt(env, 1); // alg
    stack[0] = (LispObject)113; // 7
    v0195 = elt(env, 2); // "key"
    v0120 = stack[-2];
    v0063 = elt(env, 3); // "not found"
    v0063 = list3(v0195, v0120, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    fn = elt(env, 5); // rerror
    v0063 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    {
        LispObject v0013 = stack[-3];
        popv(5);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0013, v0063);
    }
// error exit handlers
v0047:
    popv(5);
    return nil;
}



// Code for di_restore

static LispObject CC_di_restore(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0095, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for di_restore");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0095 = v0000;
// end of prologue
    v0054 = v0095;
    v0095 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // di_restore1
        return (*qfn2(fn))(qenv(fn), v0054, v0095);
    }
}



// Code for general!-reduce!-mod!-p

static LispObject CC_generalKreduceKmodKp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0008, v0035, v0031;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-reduce-mod-p");
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
    v0008 = stack[0];
    if (v0008 == nil) goto v0070;
    v0008 = stack[0];
    if (!consp(v0008)) goto v0028;
    v0008 = stack[0];
    v0008 = qcar(v0008);
    v0008 = (consp(v0008) ? nil : lisp_true);
    goto v0054;

v0054:
    if (v0008 == nil) goto v0073;
    v0008 = stack[0];
    fn = elt(env, 3); // general!-modular!-number
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0008);
    }

v0073:
    v0008 = stack[0];
    v0008 = qcar(v0008);
    v0008 = qcdr(v0008);
    stack[-1] = CC_generalKreduceKmodKp(env, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    v0008 = CC_generalKreduceKmodKp(env, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    v0035 = stack[-1];
    v0031 = v0035;
    if (v0031 == nil) { popv(3); return onevalue(v0008); }
    v0031 = stack[0];
    v0031 = qcar(v0031);
    v0031 = qcar(v0031);
    popv(3);
    return acons(v0031, v0035, v0008);

v0028:
    v0008 = qvalue(elt(env, 2)); // t
    goto v0054;

v0070:
    v0008 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0008); }
// error exit handlers
v0121:
    popv(3);
    return nil;
}



// Code for formcond

static LispObject CC_formcond(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0084, v0073, v0143;
    LispObject fn;
    LispObject v0072, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formcond");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0072 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formcond");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0072,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0072);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0084 = v0072;
    v0073 = v0001;
    v0143 = v0000;
// end of prologue
    stack[0] = elt(env, 1); // cond
    v0143 = qcdr(v0143);
    fn = elt(env, 2); // formcond1
    v0084 = (*qfnn(fn))(qenv(fn), 3, v0143, v0073, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    {
        LispObject v0019 = stack[0];
        popv(1);
        return cons(v0019, v0084);
    }
// error exit handlers
v0192:
    popv(1);
    return nil;
}



// Code for monomdivide

static LispObject CC_monomdivide(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0175, v0243, v0173;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomdivide");
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
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    stack[-2] = nil;
    v0175 = (LispObject)17; // 1
    v0175 = Lmkvect(nil, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-6];
    stack[-5] = v0175;
    stack[-1] = stack[-5];
    stack[0] = (LispObject)1; // 0
    v0243 = stack[-4];
    v0175 = (LispObject)1; // 0
    v0173 = *(LispObject *)((char *)v0243 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0243 = stack[-3];
    v0175 = (LispObject)1; // 0
    v0175 = *(LispObject *)((char *)v0243 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = difference2(v0173, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-6];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0175;
    v0243 = stack[-4];
    v0175 = (LispObject)17; // 1
    v0175 = *(LispObject *)((char *)v0243 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    stack[0] = v0175;
    v0243 = stack[-3];
    v0175 = (LispObject)17; // 1
    v0175 = *(LispObject *)((char *)v0243 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    stack[-1] = v0175;
    goto v0026;

v0026:
    v0175 = stack[0];
    v0175 = qcar(v0175);
    if (v0175 == nil) goto v0196;
    v0175 = stack[0];
    v0243 = qcar(v0175);
    v0175 = stack[-1];
    v0175 = qcar(v0175);
    if (equal(v0243, v0175)) goto v0009;
    v0175 = stack[0];
    v0243 = qcar(v0175);
    v0175 = stack[-2];
    v0175 = cons(v0243, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-6];
    stack[-2] = v0175;
    v0175 = stack[0];
    v0175 = qcdr(v0175);
    stack[0] = v0175;
    goto v0026;

v0009:
    v0175 = stack[0];
    v0175 = qcdr(v0175);
    stack[0] = v0175;
    v0175 = stack[-1];
    v0175 = qcdr(v0175);
    stack[-1] = v0175;
    goto v0026;

v0196:
    v0243 = qvalue(elt(env, 1)); // nil
    v0175 = stack[-2];
    v0175 = cons(v0243, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-6];
    stack[-2] = v0175;
    stack[-1] = stack[-5];
    stack[0] = (LispObject)17; // 1
    v0175 = stack[-2];
    v0175 = Lreverse(nil, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0175;
    { LispObject res = stack[-5]; popv(7); return onevalue(res); }
// error exit handlers
v0231:
    popv(7);
    return nil;
}



// Code for sfto_ucontentf1

static LispObject CC_sfto_ucontentf1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0077, v0010;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_ucontentf1");
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
    goto v0087;

v0087:
    v0077 = stack[-1];
    if (!consp(v0077)) goto v0021;
    v0077 = stack[-1];
    v0077 = qcar(v0077);
    v0077 = (consp(v0077) ? nil : lisp_true);
    goto v0067;

v0067:
    if (v0077 == nil) goto v0043;
    v0077 = qvalue(elt(env, 1)); // t
    goto v0194;

v0194:
    if (v0077 == nil) goto v0017;
    v0077 = stack[-1];
    v0010 = v0077;
    goto v0076;

v0076:
    v0077 = stack[-2];
    if (v0077 == nil) { popv(4); return onevalue(v0010); }
    v0077 = stack[-2];
    v0077 = qcar(v0077);
    fn = elt(env, 2); // sfto_gcdf!*
    v0077 = (*qfn2(fn))(qenv(fn), v0077, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    v0010 = v0077;
    v0077 = stack[-2];
    v0077 = qcdr(v0077);
    stack[-2] = v0077;
    goto v0076;

v0017:
    v0077 = stack[-1];
    v0077 = qcar(v0077);
    v0010 = qcdr(v0077);
    v0077 = stack[-2];
    v0077 = cons(v0010, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    stack[-2] = v0077;
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    stack[-1] = v0077;
    goto v0087;

v0043:
    v0077 = stack[-1];
    v0077 = qcar(v0077);
    v0077 = qcar(v0077);
    v0010 = qcar(v0077);
    v0077 = stack[0];
    v0077 = Lneq(nil, v0010, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    goto v0194;

v0021:
    v0077 = qvalue(elt(env, 1)); // t
    goto v0067;
// error exit handlers
v0045:
    popv(4);
    return nil;
}



// Code for findnthroot

static LispObject CC_findnthroot(LispObject env,
                         LispObject v0000)
{
    LispObject v0082;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findnthroot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0082 = v0000;
// end of prologue
    v0082 = qvalue(elt(env, 1)); // nil
    return onevalue(v0082);
}



// Code for prepsq!*

static LispObject CC_prepsqH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0260, v0261, v0262;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq*");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-9] = v0000;
// end of prologue
    stack[-8] = qvalue(elt(env, 1)); // !*combinelogs
    qvalue(elt(env, 1)) = nil; // !*combinelogs
    v0260 = stack[-9];
    v0260 = qcar(v0260);
    if (v0260 == nil) goto v0076;
    v0260 = qvalue(elt(env, 2)); // ordl!*
    fn = elt(env, 15); // setkorder
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    stack[-10] = v0260;
    v0260 = qvalue(elt(env, 3)); // factors!*
    stack[-7] = v0260;
    goto v0065;

v0065:
    v0260 = stack[-7];
    if (v0260 == nil) goto v0069;
    v0260 = stack[-7];
    v0260 = qcar(v0260);
    v0261 = v0260;
    v0260 = v0261;
    if (symbolp(v0260)) goto v0094;
    v0260 = qvalue(elt(env, 4)); // nil
    goto v0052;

v0052:
    stack[-6] = v0260;
    v0260 = stack[-6];
    fn = elt(env, 16); // lastpair
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    stack[-5] = v0260;
    v0260 = stack[-7];
    v0260 = qcdr(v0260);
    stack[-7] = v0260;
    v0260 = stack[-5];
    if (!consp(v0260)) goto v0065;
    else goto v0016;

v0016:
    v0260 = stack[-7];
    if (v0260 == nil) goto v0189;
    stack[-4] = stack[-5];
    v0260 = stack[-7];
    v0260 = qcar(v0260);
    v0261 = v0260;
    if (symbolp(v0261)) goto v0230;
    v0260 = qvalue(elt(env, 4)); // nil
    goto v0220;

v0220:
    v0260 = Lrplacd(nil, stack[-4], v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = stack[-5];
    fn = elt(env, 16); // lastpair
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    stack[-5] = v0260;
    v0260 = stack[-7];
    v0260 = qcdr(v0260);
    stack[-7] = v0260;
    goto v0016;

v0230:
    v0262 = v0260;
    v0261 = elt(env, 5); // prepsq!*fn
    v0261 = get(v0262, v0261);
    env = stack[-11];
    v0262 = v0261;
    if (v0261 == nil) goto v0264;
    v0261 = stack[-9];
    v0260 = Lapply2(nil, 3, v0262, v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    goto v0220;

v0264:
    if (!symbolp(v0260)) v0260 = nil;
    else { v0260 = qfastgets(v0260);
           if (v0260 != nil) { v0260 = elt(v0260, 24); // klist
#ifdef RECORD_GET
             if (v0260 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0260 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0260 == SPID_NOPROP) v0260 = nil; }}
#endif
    stack[-3] = v0260;
    v0260 = stack[-3];
    if (v0260 == nil) goto v0139;
    v0260 = stack[-3];
    v0260 = qcar(v0260);
    v0260 = qcar(v0260);
    v0260 = ncons(v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    stack[-1] = v0260;
    stack[-2] = v0260;
    goto v0182;

v0182:
    v0260 = stack[-3];
    v0260 = qcdr(v0260);
    stack[-3] = v0260;
    v0260 = stack[-3];
    if (v0260 == nil) goto v0265;
    stack[0] = stack[-1];
    v0260 = stack[-3];
    v0260 = qcar(v0260);
    v0260 = qcar(v0260);
    v0260 = ncons(v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = Lrplacd(nil, stack[0], v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = stack[-1];
    v0260 = qcdr(v0260);
    stack[-1] = v0260;
    goto v0182;

v0265:
    v0260 = stack[-2];
    goto v0220;

v0139:
    v0260 = qvalue(elt(env, 4)); // nil
    goto v0220;

v0189:
    v0260 = stack[-6];
    v0261 = v0260;
    goto v0042;

v0042:
    v0260 = elt(env, 6); // ordop
    fn = elt(env, 17); // sort
    stack[0] = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0261 = qvalue(elt(env, 3)); // factors!*
    v0260 = elt(env, 6); // ordop
    fn = elt(env, 17); // sort
    v0261 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = qvalue(elt(env, 2)); // ordl!*
    v0260 = Lappend(nil, v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = Lappend(nil, stack[0], v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    fn = elt(env, 15); // setkorder
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0261 = qvalue(elt(env, 7)); // kord!*
    v0260 = stack[-10];
    if (equal(v0261, v0260)) goto v0104;
    v0260 = qvalue(elt(env, 8)); // t
    goto v0266;

v0266:
    if (v0260 == nil) goto v0155;
    v0260 = stack[-9];
    v0260 = qcar(v0260);
    fn = elt(env, 18); // formop
    stack[0] = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = stack[-9];
    v0260 = qcdr(v0260);
    fn = elt(env, 18); // formop
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = cons(stack[0], v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    stack[-9] = v0260;
    goto v0155;

v0155:
    v0260 = qvalue(elt(env, 10)); // !*rat
    if (!(v0260 == nil)) goto v0124;
    v0260 = qvalue(elt(env, 11)); // !*div
    if (!(v0260 == nil)) goto v0124;
    v0260 = qvalue(elt(env, 12)); // upl!*
    if (!(v0260 == nil)) goto v0124;
    v0260 = qvalue(elt(env, 13)); // dnl!*
    if (!(v0260 == nil)) goto v0124;
    v0261 = stack[-9];
    v0260 = elt(env, 14); // prepsq!*2
    fn = elt(env, 19); // sqform
    v0260 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    goto v0154;

v0154:
    stack[-9] = v0260;
    v0260 = stack[-10];
    fn = elt(env, 15); // setkorder
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = stack[-9];
    goto v0181;

v0181:
    qvalue(elt(env, 1)) = stack[-8]; // !*combinelogs
    { popv(12); return onevalue(v0260); }

v0124:
    v0260 = stack[-9];
    v0262 = qcar(v0260);
    v0260 = stack[-9];
    v0261 = qcdr(v0260);
    v0260 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 20); // prepsq!*1
    v0260 = (*qfnn(fn))(qenv(fn), 3, v0262, v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    fn = elt(env, 21); // replus
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    goto v0154;

v0104:
    v0260 = qvalue(elt(env, 9)); // wtl!*
    goto v0266;

v0094:
    v0262 = v0261;
    v0260 = elt(env, 5); // prepsq!*fn
    v0260 = get(v0262, v0260);
    env = stack[-11];
    v0262 = v0260;
    if (v0260 == nil) goto v0077;
    v0260 = stack[-9];
    v0260 = Lapply2(nil, 3, v0262, v0260, v0261);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    goto v0052;

v0077:
    v0260 = v0261;
    if (!symbolp(v0260)) v0260 = nil;
    else { v0260 = qfastgets(v0260);
           if (v0260 != nil) { v0260 = elt(v0260, 24); // klist
#ifdef RECORD_GET
             if (v0260 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0260 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0260 == SPID_NOPROP) v0260 = nil; }}
#endif
    stack[-3] = v0260;
    v0260 = stack[-3];
    if (v0260 == nil) goto v0120;
    v0260 = stack[-3];
    v0260 = qcar(v0260);
    v0260 = qcar(v0260);
    v0260 = ncons(v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    stack[-1] = v0260;
    stack[-2] = v0260;
    goto v0216;

v0216:
    v0260 = stack[-3];
    v0260 = qcdr(v0260);
    stack[-3] = v0260;
    v0260 = stack[-3];
    if (v0260 == nil) goto v0089;
    stack[0] = stack[-1];
    v0260 = stack[-3];
    v0260 = qcar(v0260);
    v0260 = qcar(v0260);
    v0260 = ncons(v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = Lrplacd(nil, stack[0], v0260);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-11];
    v0260 = stack[-1];
    v0260 = qcdr(v0260);
    stack[-1] = v0260;
    goto v0216;

v0089:
    v0260 = stack[-2];
    goto v0052;

v0120:
    v0260 = qvalue(elt(env, 4)); // nil
    goto v0052;

v0069:
    v0260 = qvalue(elt(env, 4)); // nil
    v0261 = v0260;
    goto v0042;

v0076:
    v0260 = (LispObject)1; // 0
    goto v0181;
// error exit handlers
v0263:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-8]; // !*combinelogs
    popv(12);
    return nil;
}



// Code for ibalp_readclause

static LispObject CC_ibalp_readclause(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0276, v0277, v0249, v0098;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_readclause");
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
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0001;
    v0276 = v0000;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v0276 = qcdr(v0276);
    stack[-4] = v0276;
    stack[-5] = qvalue(elt(env, 1)); // nil
    stack[-1] = qvalue(elt(env, 1)); // nil
    stack[0] = (LispObject)1; // 0
    v0098 = (LispObject)1; // 0
    v0249 = qvalue(elt(env, 1)); // nil
    v0277 = qvalue(elt(env, 1)); // nil
    v0276 = qvalue(elt(env, 1)); // nil
    v0276 = list4(v0098, v0249, v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    v0276 = list3star(stack[-5], stack[-1], stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    stack[-5] = v0276;
    v0276 = qvalue(elt(env, 2)); // t
    stack[-1] = v0276;
    goto v0018;

v0018:
    v0276 = stack[-1];
    if (v0276 == nil) goto v0017;
    v0276 = stack[-4];
    if (v0276 == nil) goto v0017;
    v0276 = stack[-4];
    v0276 = qcar(v0276);
    stack[-8] = v0276;
    v0277 = stack[-8];
    v0276 = elt(env, 3); // true
    if (v0277 == v0276) goto v0233;
    v0276 = stack[-4];
    v0276 = qcdr(v0276);
    stack[-4] = v0276;
    v0277 = stack[-8];
    v0276 = elt(env, 4); // false
    if (v0277 == v0276) goto v0018;
    v0276 = stack[-8];
    if (!consp(v0276)) goto v0078;
    v0276 = stack[-8];
    v0276 = qcar(v0276);
    v0277 = v0276;
    goto v0278;

v0278:
    v0276 = elt(env, 5); // not
    if (v0277 == v0276) goto v0195;
    v0276 = stack[-8];
    fn = elt(env, 6); // ibalp_arg2l
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    stack[-6] = v0276;
    v0276 = stack[-8];
    fn = elt(env, 7); // ibalp_arg2r
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    goto v0231;

v0231:
    v0277 = v0276;
    v0276 = (LispObject)17; // 1
    fn = elt(env, 8); // iequal
    v0276 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    if (v0276 == nil) goto v0201;
    v0277 = stack[-6];
    v0276 = stack[-3];
    v0276 = Lmemq(nil, v0277, v0276);
    if (!(v0276 == nil)) goto v0018;
    v0276 = stack[-5];
    v0276 = qcdr(v0276);
    stack[0] = qcdr(v0276);
    v0276 = stack[-5];
    v0276 = qcdr(v0276);
    v0276 = qcdr(v0276);
    v0276 = qcar(v0276);
    v0276 = add1(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    fn = elt(env, 9); // setcar
    v0276 = (*qfn2(fn))(qenv(fn), stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    v0277 = stack[-6];
    v0276 = stack[-3];
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    stack[-3] = v0276;
    v0098 = stack[-5];
    v0249 = stack[-7];
    v0277 = stack[-6];
    v0276 = (LispObject)17; // 1
    fn = elt(env, 10); // ibalp_process!-var
    v0276 = (*qfnn(fn))(qenv(fn), 4, v0098, v0249, v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    stack[-7] = v0276;
    goto v0018;

v0201:
    v0277 = stack[-6];
    v0276 = stack[-2];
    v0276 = Lmemq(nil, v0277, v0276);
    if (!(v0276 == nil)) goto v0018;
    v0276 = stack[-5];
    v0276 = qcdr(v0276);
    v0276 = qcdr(v0276);
    stack[0] = qcdr(v0276);
    v0276 = stack[-5];
    v0276 = qcdr(v0276);
    v0276 = qcdr(v0276);
    v0276 = qcdr(v0276);
    v0276 = qcar(v0276);
    v0276 = add1(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    fn = elt(env, 9); // setcar
    v0276 = (*qfn2(fn))(qenv(fn), stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    v0277 = stack[-6];
    v0276 = stack[-2];
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    stack[-2] = v0276;
    v0098 = stack[-5];
    v0249 = stack[-7];
    v0277 = stack[-6];
    v0276 = (LispObject)1; // 0
    fn = elt(env, 10); // ibalp_process!-var
    v0276 = (*qfnn(fn))(qenv(fn), 4, v0098, v0249, v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    stack[-7] = v0276;
    goto v0018;

v0195:
    v0276 = stack[-8];
    v0276 = qcdr(v0276);
    v0276 = qcar(v0276);
    fn = elt(env, 6); // ibalp_arg2l
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    stack[-6] = v0276;
    stack[0] = (LispObject)17; // 1
    v0276 = stack[-8];
    v0276 = qcdr(v0276);
    v0276 = qcar(v0276);
    fn = elt(env, 7); // ibalp_arg2r
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-9];
    v0276 = (LispObject)(int32_t)((int32_t)stack[0] - (int32_t)v0276 + TAG_FIXNUM);
    goto v0231;

v0078:
    v0276 = stack[-8];
    v0277 = v0276;
    goto v0278;

v0233:
    v0276 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0276;
    goto v0018;

v0017:
    v0276 = stack[-1];
    if (v0276 == nil) goto v0106;
    v0277 = stack[-5];
    v0276 = stack[-7];
    popv(10);
    return cons(v0277, v0276);

v0106:
    v0277 = elt(env, 3); // true
    v0276 = stack[-7];
    popv(10);
    return cons(v0277, v0276);
// error exit handlers
v0097:
    popv(10);
    return nil;
}



// Code for binomial!-coefft!-mod!-p

static LispObject CC_binomialKcoefftKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0006, v0037, v0175, v0243, v0173;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for binomial-coefft-mod-p");
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
    v0037 = stack[-2];
    v0006 = stack[-1];
    v0006 = (LispObject)lessp2(v0037, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0006 = v0006 ? lisp_true : nil;
    env = stack[-4];
    if (v0006 == nil) goto v0083;
    v0006 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0006); }

v0083:
    v0037 = stack[-2];
    v0006 = stack[-1];
    if (equal(v0037, v0006)) goto v0058;
    v0037 = stack[-1];
    v0006 = (LispObject)17; // 1
    if (v0037 == v0006) goto v0042;
    v0006 = (LispObject)17; // 1
    stack[-3] = v0006;
    stack[0] = stack[-1];
    v0037 = stack[-2];
    v0006 = stack[-1];
    v0006 = difference2(v0037, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    fn = elt(env, 2); // min
    v0006 = (*qfn2(fn))(qenv(fn), stack[0], v0006);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    stack[0] = v0006;
    v0006 = stack[-2];
    v0006 = Lmodular_number(nil, v0006);
    env = stack[-4];
    stack[-2] = v0006;
    v0006 = stack[-1];
    v0006 = Lmodular_number(nil, v0006);
    env = stack[-4];
    v0006 = (LispObject)17; // 1
    stack[-1] = v0006;
    goto v0032;

v0032:
    v0037 = stack[0];
    v0006 = stack[-1];
    v0006 = difference2(v0037, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    v0006 = Lminusp(nil, v0006);
    env = stack[-4];
    if (v0006 == nil) goto v0198;
    v0006 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0006);
    }

v0198:
    v0006 = stack[-1];
    v0006 = Lmodular_number(nil, v0006);
    env = stack[-4];
    v0173 = v0006;
    v0243 = stack[-3];
    v0175 = stack[-2];
    v0037 = v0173;
    v0006 = (LispObject)17; // 1
    {   int32_t w = int_of_fixnum(v0037) - int_of_fixnum(v0006);
        if (w < 0) w += current_modulus;
        v0006 = fixnum_of_int(w);
    }
    {   int32_t w = int_of_fixnum(v0175) - int_of_fixnum(v0006);
        if (w < 0) w += current_modulus;
        v0006 = fixnum_of_int(w);
    }
    v0006 = Lmodular_times(nil, v0243, v0006);
    env = stack[-4];
    v0037 = v0173;
    v0006 = Lmodular_quotient(nil, v0006, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    stack[-3] = v0006;
    v0006 = stack[-1];
    v0006 = add1(v0006);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    stack[-1] = v0006;
    goto v0032;

v0042:
    v0006 = stack[-2];
    v0006 = Lmodular_number(nil, v0006);
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0006);
    }

v0058:
    v0006 = (LispObject)17; // 1
    { popv(5); return onevalue(v0006); }
// error exit handlers
v0118:
    popv(5);
    return nil;
}



// Code for variablesir

static LispObject CC_variablesir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0222, v0017;
    LispObject fn;
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for variablesir");
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
    v0017 = qvalue(elt(env, 1)); // char
    v0222 = elt(env, 2); // (!/ o m b v a r)
    if (equal(v0017, v0222)) goto v0181;
    fn = elt(env, 4); // omvir
    v0222 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    stack[0] = v0222;
    fn = elt(env, 5); // lex
    v0222 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    v0222 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    v0017 = stack[0];
    if (v0017 == nil) goto v0143;
    v0017 = stack[0];
    popv(2);
    return cons(v0017, v0222);

v0143:
    v0017 = stack[0];
        popv(2);
        return Lappend(nil, v0017, v0222);

v0181:
    v0222 = nil;
    { popv(2); return onevalue(v0222); }
// error exit handlers
v0071:
    popv(2);
    return nil;
}



// Code for xord_deglex

static LispObject CC_xord_deglex(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0177, v0014, v0015, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xord_deglex");
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
    v0177 = stack[-1];
    v0014 = qcar(v0177);
    v0177 = (LispObject)17; // 1
    if (v0014 == v0177) goto v0193;
    v0177 = stack[0];
    v0014 = qcar(v0177);
    v0177 = (LispObject)17; // 1
    if (v0014 == v0177) goto v0058;
    v0177 = stack[-1];
    fn = elt(env, 3); // xdegreemon
    stack[-2] = (*qfn1(fn))(qenv(fn), v0177);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0177 = stack[0];
    fn = elt(env, 3); // xdegreemon
    v0177 = (*qfn1(fn))(qenv(fn), v0177);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0062 = stack[-2];
    v0015 = v0177;
    v0014 = v0062;
    v0177 = v0015;
    if (equal(v0014, v0177)) goto v0052;
    v0177 = v0062;
    v0014 = v0015;
        popv(4);
        return Lgreaterp(nil, v0177, v0014);

v0052:
    v0014 = stack[-1];
    v0177 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); // xord_lex
        return (*qfn2(fn))(qenv(fn), v0014, v0177);
    }

v0058:
    v0177 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0177); }

v0193:
    v0177 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0177); }
// error exit handlers
v0198:
    popv(4);
    return nil;
}



// Code for invp

static LispObject CC_invp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0062, v0090;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for invp");
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
    v0090 = v0000;
// end of prologue
    v0062 = v0090;
    v0015 = elt(env, 1); // unit
    if (v0062 == v0015) return onevalue(v0090);
    v0015 = v0090;
    if (!consp(v0015)) goto v0083;
    v0015 = v0090;
    v0062 = qcar(v0015);
    v0015 = elt(env, 3); // (comm anticomm)
    v0015 = Lmember(nil, v0062, v0015);
    if (v0015 == nil) goto v0008;
    v0062 = elt(env, 4); // quotient
    v0015 = (LispObject)17; // 1
    return list3(v0062, v0015, v0090);

v0008:
    v0015 = v0090;
    v0062 = qcar(v0015);
    v0015 = elt(env, 2); // inverse
    v0015 = get(v0062, v0015);
    v0062 = v0090;
    v0062 = qcdr(v0062);
    return cons(v0015, v0062);

v0083:
    v0015 = v0090;
    v0062 = elt(env, 2); // inverse
    return get(v0015, v0062);
}



// Code for contr

static LispObject CC_contr(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0065, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contr");
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
    goto v0181;

v0181:
    v0065 = stack[0];
    if (v0065 == nil) goto v0076;
    v0016 = stack[-1];
    v0065 = stack[0];
    v0065 = qcar(v0065);
    fn = elt(env, 1); // split!-road
    v0016 = (*qfn2(fn))(qenv(fn), v0016, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    v0065 = stack[-2];
    v0065 = cons(v0016, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    stack[-2] = v0065;
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    stack[0] = v0065;
    goto v0181;

v0076:
    v0065 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0065);
    }
// error exit handlers
v0069:
    popv(4);
    return nil;
}



// Code for addgt

static LispObject CC_addgt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0049, v0043;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addgt");
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
    v0043 = qvalue(elt(env, 1)); // ordering
    v0049 = elt(env, 2); // lex
    if (v0043 == v0049) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0043 = elt(env, 3); // plus
    v0049 = stack[0];
    v0049 = cons(v0043, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    fn = elt(env, 4); // eval
    v0043 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0049 = stack[0];
    popv(2);
    return cons(v0043, v0049);
// error exit handlers
v0016:
    popv(2);
    return nil;
}



// Code for il_simp

static LispObject CC_il_simp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0095, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for il_simp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0095 = v0000;
// end of prologue
    v0054 = v0095;
    v0095 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // il_simp1
        return (*qfn2(fn))(qenv(fn), v0054, v0095);
    }
}



// Code for ordexn

static LispObject CC_ordexn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0012, v0013;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordexn");
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
    stack[-3] = nil;
    goto v0087;

v0087:
    v0012 = stack[-1];
    if (v0012 == nil) goto v0053;
    v0013 = stack[-2];
    v0012 = stack[-1];
    v0012 = qcar(v0012);
    if (v0013 == v0012) goto v0020;
    v0012 = stack[-2];
    if (v0012 == nil) goto v0216;
    v0013 = stack[-2];
    v0012 = stack[-1];
    v0012 = qcar(v0012);
    fn = elt(env, 2); // ordop
    v0012 = (*qfn2(fn))(qenv(fn), v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    if (v0012 == nil) goto v0216;
    v0013 = stack[-2];
    v0012 = stack[-3];
    v0012 = cons(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0013 = Lreverse(nil, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0012 = stack[-1];
    v0012 = Lappend(nil, v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    {
        LispObject v0089 = stack[0];
        popv(5);
        return cons(v0089, v0012);
    }

v0216:
    v0012 = stack[-1];
    v0013 = qcar(v0012);
    v0012 = stack[-3];
    v0012 = cons(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    stack[-3] = v0012;
    v0012 = stack[-1];
    v0012 = qcdr(v0012);
    stack[-1] = v0012;
    v0012 = stack[0];
    v0012 = (v0012 == nil ? lisp_true : nil);
    stack[0] = v0012;
    goto v0087;

v0020:
    v0012 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0012); }

v0053:
    v0013 = stack[-2];
    v0012 = stack[-3];
    v0012 = cons(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0012 = Lreverse(nil, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    {
        LispObject v0034 = stack[0];
        popv(5);
        return cons(v0034, v0012);
    }
// error exit handlers
v0119:
    popv(5);
    return nil;
}



// Code for lalr_most_common_dest

static LispObject CC_lalr_most_common_dest(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0078, v0079, v0172;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_most_common_dest");
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
    v0078 = v0000;
// end of prologue
    stack[-3] = nil;
    stack[-1] = v0078;
    goto v0076;

v0076:
    v0078 = stack[-1];
    if (v0078 == nil) goto v0088;
    v0078 = stack[-1];
    v0078 = qcar(v0078);
    v0172 = v0078;
    v0078 = v0172;
    v0079 = qcdr(v0078);
    v0078 = stack[-3];
    v0078 = Lassoc(nil, v0079, v0078);
    stack[-2] = v0078;
    if (v0078 == nil) goto v0071;
    stack[0] = stack[-2];
    v0078 = stack[-2];
    v0078 = qcdr(v0078);
    v0078 = add1(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0078 = Lrplacd(nil, stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    goto v0022;

v0022:
    v0078 = stack[-1];
    v0078 = qcdr(v0078);
    stack[-1] = v0078;
    goto v0076;

v0071:
    v0078 = v0172;
    v0172 = qcdr(v0078);
    v0079 = (LispObject)17; // 1
    v0078 = stack[-3];
    v0078 = acons(v0172, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    stack[-3] = v0078;
    goto v0022;

v0088:
    v0078 = stack[-3];
    v0078 = qcar(v0078);
    stack[-2] = v0078;
    v0078 = stack[-3];
    v0078 = qcdr(v0078);
    stack[-1] = v0078;
    goto v0177;

v0177:
    v0078 = stack[-1];
    if (v0078 == nil) goto v0197;
    v0078 = stack[-1];
    v0078 = qcar(v0078);
    stack[0] = v0078;
    v0078 = stack[0];
    v0079 = qcdr(v0078);
    v0078 = stack[-2];
    v0078 = qcdr(v0078);
    v0078 = (LispObject)greaterp2(v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    v0078 = v0078 ? lisp_true : nil;
    env = stack[-4];
    if (v0078 == nil) goto v0044;
    v0078 = stack[0];
    stack[-2] = v0078;
    goto v0044;

v0044:
    v0078 = stack[-1];
    v0078 = qcdr(v0078);
    stack[-1] = v0078;
    goto v0177;

v0197:
    v0078 = stack[-2];
    v0078 = qcar(v0078);
    { popv(5); return onevalue(v0078); }
// error exit handlers
v0196:
    popv(5);
    return nil;
}



// Code for sfto_varp

static LispObject CC_sfto_varp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_varp");
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
    v0014 = stack[0];
    if (!consp(v0014)) goto v0028;
    v0014 = stack[0];
    v0014 = qcar(v0014);
    v0014 = (consp(v0014) ? nil : lisp_true);
    goto v0054;

v0054:
    if (v0014 == nil) goto v0088;
    v0014 = qvalue(elt(env, 2)); // nil
    goto v0087;

v0087:
    if (v0014 == nil) goto v0193;
    v0014 = stack[0];
    v0014 = qcar(v0014);
    v0014 = qcar(v0014);
    v0014 = qcar(v0014);
    { popv(2); return onevalue(v0014); }

v0193:
    v0014 = nil;
    { popv(2); return onevalue(v0014); }

v0088:
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    if (v0014 == nil) goto v0049;
    v0014 = qvalue(elt(env, 2)); // nil
    goto v0087;

v0049:
    v0014 = stack[0];
    v0014 = qcar(v0014);
    v0015 = qcdr(v0014);
    v0014 = (LispObject)17; // 1
    v0014 = Leqn(nil, v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    if (v0014 == nil) goto v0020;
    v0014 = stack[0];
    v0014 = qcar(v0014);
    v0014 = qcar(v0014);
    v0015 = qcdr(v0014);
    v0014 = (LispObject)17; // 1
    v0014 = Leqn(nil, v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    goto v0087;

v0020:
    v0014 = qvalue(elt(env, 2)); // nil
    goto v0087;

v0028:
    v0014 = qvalue(elt(env, 1)); // t
    goto v0054;
// error exit handlers
v0090:
    popv(2);
    return nil;
}



// Code for simpg3

static LispObject CC_simpg3(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0095, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpg3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0095 = v0000;
// end of prologue
    v0054 = v0095;
    v0095 = elt(env, 1); // g3
    {
        fn = elt(env, 2); // simpcv
        return (*qfn2(fn))(qenv(fn), v0054, v0095);
    }
}



// Code for ibalp_recalcv

static LispObject CC_ibalp_recalcv(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0080, v0081;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_recalcv");
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
    v0080 = v0000;
// end of prologue
    stack[-2] = v0080;
    goto v0193;

v0193:
    v0080 = stack[-2];
    if (v0080 == nil) goto v0076;
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    stack[-1] = v0080;
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    stack[0] = qcdr(v0080);
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0081 = qcar(v0080);
    v0080 = elt(env, 2); // 0.05
    v0080 = difference2(v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    fn = elt(env, 3); // setcar
    v0080 = (*qfn2(fn))(qenv(fn), stack[0], v0080);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    stack[0] = qcdr(v0080);
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0081 = qcar(v0080);
    v0080 = elt(env, 2); // 0.05
    v0080 = difference2(v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    fn = elt(env, 3); // setcar
    v0080 = (*qfn2(fn))(qenv(fn), stack[0], v0080);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    v0080 = stack[-2];
    v0080 = qcdr(v0080);
    stack[-2] = v0080;
    goto v0193;

v0076:
    v0080 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0080); }
// error exit handlers
v0013:
    popv(4);
    return nil;
}



// Code for mapins

static LispObject CC_mapins(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0059, v0085, v0221;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mapins");
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
    goto v0181;

v0181:
    v0059 = stack[0];
    if (v0059 == nil) goto v0076;
    v0085 = stack[-1];
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0221 = cons(v0085, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-3];
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0085 = qcdr(v0059);
    v0059 = stack[-2];
    v0059 = acons(v0221, v0085, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-3];
    stack[-2] = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0181;

v0076:
    v0059 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0059);
    }
// error exit handlers
v0071:
    popv(4);
    return nil;
}



// Code for ir2om

static LispObject CC_ir2om(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ir2om");
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
    v0058 = (LispObject)33; // 2
    qvalue(elt(env, 1)) = v0058; // ind
    v0058 = (LispObject)1; // 0
    qvalue(elt(env, 2)) = v0058; // indent
    v0058 = elt(env, 3); // "<OMOBJ>"
    fn = elt(env, 7); // printout
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    v0058 = qvalue(elt(env, 4)); // t
    fn = elt(env, 8); // indent!*
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    v0058 = stack[0];
    fn = elt(env, 9); // objectom
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    v0058 = qvalue(elt(env, 5)); // nil
    fn = elt(env, 8); // indent!*
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    v0058 = elt(env, 6); // "</OMOBJ>"
    fn = elt(env, 7); // printout
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    v0058 = nil;
    { popv(2); return onevalue(v0058); }
// error exit handlers
v0083:
    popv(2);
    return nil;
}



// Code for groebcplistsortin

static LispObject CC_groebcplistsortin(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0022, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebcplistsortin");
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
    v0053 = v0000;
// end of prologue
    v0022 = stack[0];
    if (v0022 == nil) goto v0193;
    v0022 = stack[0];
    fn = elt(env, 1); // groebcplistsortin1
    v0022 = (*qfn2(fn))(qenv(fn), v0053, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }

v0193:
    v0022 = v0053;
    popv(1);
    return ncons(v0022);
// error exit handlers
v0073:
    popv(1);
    return nil;
}



// Code for assert_uninstall

static LispObject CC_assert_uninstall(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_uninstall");
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
    v0021 = v0000;
// end of prologue
    stack[0] = v0021;
    goto v0193;

v0193:
    v0021 = stack[0];
    if (v0021 == nil) goto v0076;
    v0021 = stack[0];
    v0021 = qcar(v0021);
    fn = elt(env, 2); // assert_uninstall1
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    stack[0] = v0021;
    goto v0193;

v0076:
    v0021 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0021); }
// error exit handlers
v0053:
    popv(2);
    return nil;
}



setup_type const u18_setup[] =
{
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"mo_from_a",               CC_mo_from_a,   too_many_1,    wrong_no_1},
    {"class",                   CC_class,       too_many_1,    wrong_no_1},
    {"moduntag",                CC_moduntag,    too_many_1,    wrong_no_1},
    {"gcref_select",            CC_gcref_select,too_many_1,    wrong_no_1},
    {"ofsf_entry2at",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"rl_nnf",                  CC_rl_nnf,      too_many_1,    wrong_no_1},
    {"qqe_simplterm",           CC_qqe_simplterm,too_many_1,   wrong_no_1},
    {"rl_susipost",             too_few_2,      CC_rl_susipost,wrong_no_2},
    {"rl_simp1",                CC_rl_simp1,    too_many_1,    wrong_no_1},
    {"aex_simpleratp",          CC_aex_simpleratp,too_many_1,  wrong_no_1},
    {"powers4",                 too_few_2,      CC_powers4,    wrong_no_2},
    {"tobvarir",                CC_tobvarir,    too_many_1,    wrong_no_1},
    {"floatprop",               CC_floatprop,   too_many_1,    wrong_no_1},
    {"inttovec",                too_few_2,      CC_inttovec,   wrong_no_2},
    {"physopaeval",             CC_physopaeval, too_many_1,    wrong_no_1},
    {"mkarray1",                too_few_2,      CC_mkarray1,   wrong_no_2},
    {"idcons_ordp",             too_few_2,      CC_idcons_ordp,wrong_no_2},
    {"general-expt-mod-p",      too_few_2,      CC_generalKexptKmodKp,wrong_no_2},
    {":expt",                   too_few_2,      CC_Texpt,      wrong_no_2},
    {"ofsf_smmkatl1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatl1},
    {"ibalp_process-var",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_processKvar},
    {"mvar_member",             too_few_2,      CC_mvar_member,wrong_no_2},
    {"om2mml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2mml},
    {"evmtest?",                too_few_2,      CC_evmtestW,   wrong_no_2},
    {"*wedgepf2pf",             CC_Hwedgepf2pf, too_many_1,    wrong_no_1},
    {"delete-dups",             CC_deleteKdups, too_many_1,    wrong_no_1},
    {"scal*list",               too_few_2,      CC_scalHlist,  wrong_no_2},
    {"physop-ordop",            too_few_2,      CC_physopKordop,wrong_no_2},
    {"zero-roads",              CC_zeroKroads,  too_many_1,    wrong_no_1},
    {"revalx",                  CC_revalx,      too_many_1,    wrong_no_1},
    {"repasc",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_repasc},
    {"di_restore",              CC_di_restore,  too_many_1,    wrong_no_1},
    {"general-reduce-mod-p",    CC_generalKreduceKmodKp,too_many_1,wrong_no_1},
    {"formcond",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond},
    {"monomdivide",             too_few_2,      CC_monomdivide,wrong_no_2},
    {"sfto_ucontentf1",         too_few_2,      CC_sfto_ucontentf1,wrong_no_2},
    {"findnthroot",             CC_findnthroot, too_many_1,    wrong_no_1},
    {"prepsq*",                 CC_prepsqH,     too_many_1,    wrong_no_1},
    {"ibalp_readclause",        too_few_2,      CC_ibalp_readclause,wrong_no_2},
    {"binomial-coefft-mod-p",   too_few_2,      CC_binomialKcoefftKmodKp,wrong_no_2},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"xord_deglex",             too_few_2,      CC_xord_deglex,wrong_no_2},
    {"invp",                    CC_invp,        too_many_1,    wrong_no_1},
    {"contr",                   too_few_2,      CC_contr,      wrong_no_2},
    {"addgt",                   CC_addgt,       too_many_1,    wrong_no_1},
    {"il_simp",                 CC_il_simp,     too_many_1,    wrong_no_1},
    {"ordexn",                  too_few_2,      CC_ordexn,     wrong_no_2},
    {"lalr_most_common_dest",   CC_lalr_most_common_dest,too_many_1,wrong_no_1},
    {"sfto_varp",               CC_sfto_varp,   too_many_1,    wrong_no_1},
    {"simpg3",                  CC_simpg3,      too_many_1,    wrong_no_1},
    {"ibalp_recalcv",           CC_ibalp_recalcv,too_many_1,   wrong_no_1},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"ir2om",                   CC_ir2om,       too_many_1,    wrong_no_1},
    {"groebcplistsortin",       too_few_2,      CC_groebcplistsortin,wrong_no_2},
    {"assert_uninstall",        CC_assert_uninstall,too_many_1,wrong_no_1},
    {NULL, (one_args *)"u18", (two_args *)"2869 6632201 5565139", 0}
};

// end of generated code
