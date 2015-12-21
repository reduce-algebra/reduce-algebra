
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



// Code for mo_lcm

static LispObject CC_mo_lcm(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0013, v0014;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_lcm");
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
    v0014 = v0001;
    v0013 = v0000;
// end of prologue
    stack[-2] = nil;
    v0013 = qcar(v0013);
    stack[-1] = v0013;
    v0013 = v0014;
    v0013 = qcar(v0013);
    stack[0] = v0013;
    goto v0015;

v0015:
    v0013 = stack[-1];
    if (v0013 == nil) goto v0016;
    v0013 = stack[0];
    if (v0013 == nil) goto v0016;
    v0013 = stack[-1];
    v0014 = qcar(v0013);
    v0013 = stack[0];
    v0013 = qcar(v0013);
    if (((int32_t)(v0014)) > ((int32_t)(v0013))) goto v0017;
    v0013 = stack[0];
    v0013 = qcar(v0013);
    v0014 = v0013;
    goto v0018;

v0018:
    v0013 = stack[-2];
    v0013 = cons(v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    stack[-2] = v0013;
    v0013 = stack[-1];
    v0013 = qcdr(v0013);
    stack[-1] = v0013;
    v0013 = stack[0];
    v0013 = qcdr(v0013);
    stack[0] = v0013;
    goto v0015;

v0017:
    v0013 = stack[-1];
    v0013 = qcar(v0013);
    v0014 = v0013;
    goto v0018;

v0016:
    v0013 = stack[-2];
    v0014 = Lnreverse(nil, v0013);
    env = stack[-3];
    v0013 = stack[-1];
    if (v0013 == nil) goto v0020;
    v0013 = stack[-1];
    goto v0021;

v0021:
    v0013 = Lappend(nil, v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    stack[-2] = v0013;
    v0013 = stack[-2];
    fn = elt(env, 2); // mo!=shorten
    stack[0] = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    v0013 = stack[-2];
    fn = elt(env, 3); // mo!=deglist
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    {
        LispObject v0022 = stack[0];
        popv(4);
        return cons(v0022, v0013);
    }

v0020:
    v0013 = stack[0];
    goto v0021;
// error exit handlers
v0019:
    popv(4);
    return nil;
}



// Code for b!:ordexp

static LispObject CC_bTordexp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0029, v0030;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:ordexp");
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

v0031:
    v0029 = stack[-1];
    if (v0029 == nil) goto v0007;
    v0029 = stack[-1];
    v0030 = qcar(v0029);
    v0029 = stack[0];
    v0029 = qcar(v0029);
    v0029 = (LispObject)greaterp2(v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0029 = v0029 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0029 == nil)) { popv(3); return onevalue(v0029); }
    v0029 = stack[-1];
    v0030 = qcar(v0029);
    v0029 = stack[0];
    v0029 = qcar(v0029);
    if (equal(v0030, v0029)) goto v0033;
    v0029 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0029); }

v0033:
    v0029 = stack[-1];
    v0030 = qcdr(v0029);
    v0029 = stack[0];
    v0029 = qcdr(v0029);
    stack[-1] = v0030;
    stack[0] = v0029;
    goto v0031;

v0007:
    v0029 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0029); }
// error exit handlers
v0032:
    popv(3);
    return nil;
}



// Code for exptf

static LispObject CC_exptf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0043, v0044, v0045;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptf");
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
    v0044 = stack[0];
    v0043 = (LispObject)1; // 0
    v0043 = (LispObject)lessp2(v0044, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    v0043 = v0043 ? lisp_true : nil;
    env = stack[-2];
    if (v0043 == nil) goto v0047;
    v0045 = elt(env, 1); // "exptf"
    v0044 = stack[-1];
    v0043 = stack[0];
    v0043 = list3(v0045, v0044, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); // errach
        return (*qfn1(fn))(qenv(fn), v0043);
    }

v0047:
    v0043 = stack[-1];
    if (!consp(v0043)) goto v0048;
    v0043 = stack[-1];
    v0043 = qcar(v0043);
    v0043 = (consp(v0043) ? nil : lisp_true);
    goto v0009;

v0009:
    if (v0043 == nil) goto v0049;
    v0044 = stack[-1];
    v0043 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); // !:expt
        return (*qfn2(fn))(qenv(fn), v0044, v0043);
    }

v0049:
    v0043 = qvalue(elt(env, 3)); // !*exp
    if (!(v0043 == nil)) goto v0050;
    v0043 = stack[-1];
    fn = elt(env, 6); // kernlp
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    if (!(v0043 == nil)) goto v0050;
    v0044 = stack[-1];
    v0043 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // mksfpf
        return (*qfn2(fn))(qenv(fn), v0044, v0043);
    }

v0050:
    v0044 = stack[-1];
    v0043 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); // exptf1
        return (*qfn2(fn))(qenv(fn), v0044, v0043);
    }

v0048:
    v0043 = qvalue(elt(env, 2)); // t
    goto v0009;
// error exit handlers
v0046:
    popv(3);
    return nil;
}



// Code for exc

static LispObject CC_exc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0015, v0051;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0015 = v0001;
    v0051 = v0000;
// end of prologue
    v0051 = qcdr(v0051);
    if (v0051 == nil) return onevalue(v0015);
    v0015 = (v0015 == nil ? lisp_true : nil);
    return onevalue(v0015);
}



// Code for qqe_arg!-check

static LispObject CC_qqe_argKcheck(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0054, v0055;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check");
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
    v0054 = stack[0];
    v0054 = qcar(v0054);
    stack[-1] = v0054;
    v0054 = stack[-1];
    fn = elt(env, 4); // qqe_rqopp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (v0054 == nil) goto v0057;
    v0054 = stack[0];
    fn = elt(env, 5); // qqe_arg!-check!-lq!-rq
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    goto v0047;

v0047:
    v0054 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0054); }

v0057:
    v0054 = stack[-1];
    fn = elt(env, 6); // qqe_rbopp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (v0054 == nil) goto v0015;
    v0054 = stack[0];
    fn = elt(env, 7); // qqe_arg!-check!-lb!-rb
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    goto v0047;

v0015:
    v0054 = stack[-1];
    fn = elt(env, 8); // qqe_qopheadp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (!(v0054 == nil)) goto v0058;
    v0054 = stack[-1];
    fn = elt(env, 9); // qqe_qoptailp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (!(v0054 == nil)) goto v0058;
    v0054 = stack[-1];
    fn = elt(env, 10); // qqe_qopaddp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (v0054 == nil) goto v0059;
    v0054 = stack[0];
    fn = elt(env, 11); // qqe_arg!-check!-lb!-rq
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    goto v0047;

v0059:
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[-1] = v0054;
    goto v0060;

v0060:
    v0054 = stack[-1];
    if (v0054 == nil) goto v0047;
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    fn = elt(env, 12); // qqe_arg!-check!-b
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (!(v0054 == nil)) goto v0061;
    fn = elt(env, 13); // qqe_arg!-check!-marked!-ids!-rollback
    v0054 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    v0055 = stack[0];
    v0054 = elt(env, 3); // "some arguments are not of basic type"
    fn = elt(env, 14); // typerr
    v0054 = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    goto v0061;

v0061:
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    stack[-1] = v0054;
    goto v0060;

v0058:
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    v0054 = qcar(v0054);
    fn = elt(env, 15); // qqe_arg!-check!-q
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (!(v0054 == nil)) goto v0047;
    fn = elt(env, 13); // qqe_arg!-check!-marked!-ids!-rollback
    v0054 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    v0055 = stack[0];
    v0054 = elt(env, 1); // "some arguments are not of queue type"
    fn = elt(env, 14); // typerr
    v0054 = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    goto v0047;
// error exit handlers
v0056:
    popv(3);
    return nil;
}



// Code for cl_qb

static LispObject CC_cl_qb(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0020, v0066, v0061, v0034, v0035;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_qb");
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
    v0035 = nil;
    v0020 = (LispObject)1; // 0
    v0034 = v0020;
    goto v0067;

v0067:
    v0020 = stack[0];
    if (!consp(v0020)) goto v0068;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    goto v0069;

v0069:
    stack[-1] = v0020;
    v0061 = v0020;
    v0066 = v0061;
    v0020 = elt(env, 1); // ex
    if (v0066 == v0020) goto v0049;
    v0066 = v0061;
    v0020 = elt(env, 3); // all
    v0020 = (v0066 == v0020 ? lisp_true : nil);
    goto v0018;

v0018:
    if (v0020 == nil) { popv(3); return onevalue(v0034); }
    v0066 = stack[-1];
    v0020 = v0035;
    if (equal(v0066, v0020)) goto v0029;
    v0020 = v0034;
    v0020 = add1(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    v0034 = v0020;
    v0020 = stack[-1];
    v0035 = v0020;
    goto v0029;

v0029:
    v0020 = stack[0];
    v0020 = qcdr(v0020);
    v0020 = qcdr(v0020);
    v0020 = qcar(v0020);
    stack[0] = v0020;
    goto v0067;

v0049:
    v0020 = qvalue(elt(env, 2)); // t
    goto v0018;

v0068:
    v0020 = stack[0];
    goto v0069;
// error exit handlers
v0045:
    popv(3);
    return nil;
}



// Code for cl_atfp

static LispObject CC_cl_atfp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0094, v0095, v0096;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atfp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0095 = v0000;
// end of prologue
    v0094 = v0095;
    if (!consp(v0094)) goto v0008;
    v0094 = v0095;
    v0094 = qcar(v0094);
    goto v0004;

v0004:
    v0096 = v0094;
    v0095 = v0096;
    v0094 = elt(env, 1); // true
    if (v0095 == v0094) goto v0058;
    v0095 = v0096;
    v0094 = elt(env, 3); // false
    v0094 = (v0095 == v0094 ? lisp_true : nil);
    goto v0097;

v0097:
    if (v0094 == nil) goto v0021;
    v0094 = qvalue(elt(env, 2)); // t
    goto v0015;

v0015:
    v0094 = (v0094 == nil ? lisp_true : nil);
    return onevalue(v0094);

v0021:
    v0095 = v0096;
    v0094 = elt(env, 4); // or
    if (v0095 == v0094) goto v0050;
    v0095 = v0096;
    v0094 = elt(env, 5); // and
    v0094 = (v0095 == v0094 ? lisp_true : nil);
    goto v0016;

v0016:
    if (v0094 == nil) goto v0002;
    v0094 = qvalue(elt(env, 2)); // t
    goto v0030;

v0030:
    if (v0094 == nil) goto v0098;
    v0094 = qvalue(elt(env, 2)); // t
    goto v0037;

v0037:
    if (v0094 == nil) goto v0099;
    v0094 = qvalue(elt(env, 2)); // t
    goto v0015;

v0099:
    v0095 = v0096;
    v0094 = elt(env, 10); // ex
    if (v0095 == v0094) goto v0100;
    v0095 = v0096;
    v0094 = elt(env, 11); // all
    v0094 = (v0095 == v0094 ? lisp_true : nil);
    goto v0101;

v0101:
    if (v0094 == nil) goto v0102;
    v0094 = qvalue(elt(env, 2)); // t
    goto v0015;

v0102:
    v0095 = v0096;
    v0094 = elt(env, 12); // bex
    if (v0095 == v0094) goto v0103;
    v0095 = v0096;
    v0094 = elt(env, 13); // ball
    v0094 = (v0095 == v0094 ? lisp_true : nil);
    goto v0104;

v0104:
    if (v0094 == nil) goto v0105;
    v0094 = qvalue(elt(env, 2)); // t
    goto v0015;

v0105:
    v0094 = v0096;
    if (!symbolp(v0094)) v0094 = nil;
    else { v0094 = qfastgets(v0094);
           if (v0094 != nil) { v0094 = elt(v0094, 21); // rl_external
#ifdef RECORD_GET
             if (v0094 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v0094 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v0094 == SPID_NOPROP) v0094 = nil; }}
#endif
    goto v0015;

v0103:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0104;

v0100:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0101;

v0098:
    v0095 = v0096;
    v0094 = elt(env, 7); // impl
    if (v0095 == v0094) goto v0056;
    v0095 = v0096;
    v0094 = elt(env, 8); // repl
    if (v0095 == v0094) goto v0106;
    v0095 = v0096;
    v0094 = elt(env, 9); // equiv
    v0094 = (v0095 == v0094 ? lisp_true : nil);
    goto v0037;

v0106:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0037;

v0056:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0037;

v0002:
    v0095 = v0096;
    v0094 = elt(env, 6); // not
    v0094 = (v0095 == v0094 ? lisp_true : nil);
    goto v0030;

v0050:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0016;

v0058:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0097;

v0008:
    v0094 = v0095;
    goto v0004;
}



// Code for reln

static LispObject CC_reln(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0108, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reln");
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
    v0108 = elt(env, 1); // "<reln>"
    fn = elt(env, 6); // printout
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0108 = elt(env, 2); // "<"
    v0108 = Lprinc(nil, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0108 = stack[0];
    v0108 = Lprinc(nil, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0108 = elt(env, 3); // "/>"
    v0108 = Lprinc(nil, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0023 = qvalue(elt(env, 4)); // indent
    v0108 = (LispObject)49; // 3
    v0108 = plus2(v0023, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0108; // indent
    v0108 = stack[-1];
    fn = elt(env, 7); // multi_elem
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0023 = qvalue(elt(env, 4)); // indent
    v0108 = (LispObject)49; // 3
    v0108 = difference2(v0023, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0108; // indent
    v0108 = elt(env, 5); // "</reln>"
    fn = elt(env, 6); // printout
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    v0108 = nil;
    { popv(3); return onevalue(v0108); }
// error exit handlers
v0093:
    popv(3);
    return nil;
}



// Code for xdegreecheck

static LispObject CC_xdegreecheck(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058, v0107;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xdegreecheck");
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
    v0107 = v0000;
// end of prologue
    v0058 = qvalue(elt(env, 1)); // xtruncate!*
    if (v0058 == nil) goto v0008;
    v0058 = v0107;
    fn = elt(env, 3); // xdegree
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[0];
    v0107 = qvalue(elt(env, 1)); // xtruncate!*
        popv(1);
        return Lgreaterp(nil, v0058, v0107);

v0008:
    v0058 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0058); }
// error exit handlers
v0025:
    popv(1);
    return nil;
}



// Code for aconc

static LispObject CC_aconc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0070, v0042;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aconc");
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
    v0070 = v0001;
    v0042 = v0000;
// end of prologue
    stack[0] = v0042;
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    {
        LispObject v0069 = stack[0];
        popv(1);
        return Lnconc(nil, v0069, v0070);
    }
// error exit handlers
v0051:
    popv(1);
    return nil;
}



// Code for bytelist2id

static LispObject CC_bytelist2id(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bytelist2id");
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
    v0007 = v0000;
// end of prologue
    fn = elt(env, 1); // list2string
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    errexit();
        return Lintern(nil, v0007);
}



// Code for fortexp

static LispObject CC_fortexp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0067, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fortexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0067 = v0000;
// end of prologue
    v0110 = v0067;
    v0067 = (LispObject)1; // 0
    {
        fn = elt(env, 1); // fortexp1
        return (*qfn2(fn))(qenv(fn), v0110, v0067);
    }
}



// Code for indordp

static LispObject CC_indordp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0005, v0036, v0006, v0092, v0091;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0092 = v0001;
    v0091 = v0000;
// end of prologue
    v0005 = qvalue(elt(env, 1)); // indxl!*
    v0006 = v0005;
    v0036 = v0091;
    v0005 = v0006;
    v0005 = Lmemq(nil, v0036, v0005);
    if (!(v0005 == nil)) goto v0047;
    v0005 = qvalue(elt(env, 2)); // t
    return onevalue(v0005);

v0047:
    v0005 = v0006;
    if (v0005 == nil) goto v0018;
    v0036 = v0091;
    v0005 = v0006;
    v0005 = qcar(v0005);
    if (v0036 == v0005) goto v0024;
    v0036 = v0092;
    v0005 = v0006;
    v0005 = qcar(v0005);
    if (v0036 == v0005) goto v0037;
    v0005 = v0006;
    v0005 = qcdr(v0005);
    v0006 = v0005;
    goto v0047;

v0037:
    v0005 = qvalue(elt(env, 3)); // nil
    return onevalue(v0005);

v0024:
    v0005 = qvalue(elt(env, 2)); // t
    return onevalue(v0005);

v0018:
    v0005 = v0091;
    v0036 = v0092;
        return Lorderp(nil, v0005, v0036);
}



// Code for collectphystype

static LispObject CC_collectphystype(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for collectphystype");
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
    v0005 = stack[0];
    fn = elt(env, 2); // physopp
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    if (v0005 == nil) goto v0007;
    v0005 = stack[0];
    fn = elt(env, 3); // getphystype
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    popv(5);
    return ncons(v0005);

v0007:
    v0005 = stack[0];
    if (!consp(v0005)) goto v0110;
    v0005 = stack[0];
    stack[-3] = v0005;
    v0005 = stack[-3];
    if (v0005 == nil) goto v0018;
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    fn = elt(env, 3); // getphystype
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0005 = ncons(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-1] = v0005;
    stack[-2] = v0005;
    goto v0026;

v0026:
    v0005 = stack[-3];
    v0005 = qcdr(v0005);
    stack[-3] = v0005;
    v0005 = stack[-3];
    if (v0005 == nil) goto v0112;
    stack[0] = stack[-1];
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    fn = elt(env, 3); // getphystype
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0005 = ncons(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0005 = Lrplacd(nil, stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    stack[-1] = v0005;
    goto v0026;

v0112:
    v0005 = stack[-2];
    goto v0113;

v0113:
    {
        popv(5);
        fn = elt(env, 4); // deletemult!*
        return (*qfn1(fn))(qenv(fn), v0005);
    }

v0018:
    v0005 = qvalue(elt(env, 1)); // nil
    goto v0113;

v0110:
    v0005 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0005); }
// error exit handlers
v0111:
    popv(5);
    return nil;
}



// Code for symbvarlst

static LispObject CC_symbvarlst(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0118, v0106, v0119;
    LispObject fn;
    LispObject v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "symbvarlst");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbvarlst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0118 = v0063;
    stack[-3] = v0001;
    v0119 = v0000;
// end of prologue
    v0106 = v0118;
    v0118 = elt(env, 1); // symbolic
    if (v0106 == v0118) goto v0067;
    v0118 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0118); }

v0067:
    v0118 = v0119;
    stack[-4] = v0118;
    goto v0057;

v0057:
    v0118 = stack[-4];
    if (v0118 == nil) goto v0041;
    v0118 = stack[-4];
    v0118 = qcar(v0118);
    v0118 = Lconsp(nil, v0118);
    env = stack[-5];
    if (v0118 == nil) goto v0033;
    v0118 = stack[-4];
    v0118 = qcar(v0118);
    v0118 = qcar(v0118);
    goto v0038;

v0038:
    stack[0] = v0118;
    v0118 = stack[0];
    v0118 = Lsymbol_specialp(nil, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-5];
    if (v0118 == nil) goto v0120;
    v0118 = qvalue(elt(env, 2)); // nil
    goto v0037;

v0037:
    if (v0118 == nil) goto v0053;
    stack[-2] = elt(env, 4); // "local variable"
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); // "in procedure"
    v0106 = qvalue(elt(env, 6)); // fname!*
    v0118 = elt(env, 7); // "not used"
    v0118 = list2(v0106, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-5];
    v0118 = list3star(stack[-2], stack[-1], stack[0], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-5];
    fn = elt(env, 8); // lprim
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-5];
    goto v0053;

v0053:
    v0118 = stack[-4];
    v0118 = qcdr(v0118);
    stack[-4] = v0118;
    goto v0057;

v0120:
    v0118 = stack[0];
    v0118 = Lsymbol_globalp(nil, v0118);
    env = stack[-5];
    if (v0118 == nil) goto v0092;
    v0118 = qvalue(elt(env, 2)); // nil
    goto v0037;

v0092:
    v0106 = stack[0];
    v0118 = stack[-3];
    v0118 = Lsmemq(nil, v0106, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-5];
    if (v0118 == nil) goto v0005;
    v0118 = qvalue(elt(env, 2)); // nil
    goto v0037;

v0005:
    v0118 = qvalue(elt(env, 3)); // !*novarmsg
    v0118 = (v0118 == nil ? lisp_true : nil);
    goto v0037;

v0033:
    v0118 = stack[-4];
    v0118 = qcar(v0118);
    goto v0038;

v0041:
    v0118 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0118); }
// error exit handlers
v0086:
    popv(6);
    return nil;
}



// Code for fs!:times

static LispObject CC_fsTtimes(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0120, v0010;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:times");
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
    v0120 = stack[-1];
    if (v0120 == nil) goto v0007;
    v0120 = stack[0];
    if (v0120 == nil) goto v0109;
    v0010 = stack[-1];
    v0120 = stack[0];
    fn = elt(env, 2); // fs!:timesterm
    v0120 = (*qfn2(fn))(qenv(fn), v0010, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    stack[-2] = v0120;
    v0010 = stack[-1];
    v0120 = (LispObject)49; // 3
    v0010 = *(LispObject *)((char *)v0010 + (CELL-TAG_VECTOR) + ((int32_t)v0120/(16/CELL)));
    v0120 = stack[0];
    v0120 = CC_fsTtimes(env, v0010, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    {
        LispObject v0032 = stack[-2];
        popv(4);
        fn = elt(env, 3); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0032, v0120);
    }

v0109:
    v0120 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0120); }

v0007:
    v0120 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0120); }
// error exit handlers
v0121:
    popv(4);
    return nil;
}



// Code for tensorp

static LispObject CC_tensorp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058, v0107;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tensorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0107 = v0000;
// end of prologue
    v0058 = v0107;
    if (!consp(v0058)) goto v0069;
    v0058 = v0107;
    v0058 = qcar(v0058);
    v0107 = elt(env, 1); // tensor
        return Lflagp(nil, v0058, v0107);

v0069:
    v0058 = qvalue(elt(env, 2)); // nil
    return onevalue(v0058);
}



// Code for ad_numsort

static LispObject CC_ad_numsort(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0067, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ad_numsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0067 = v0000;
// end of prologue
    v0110 = v0067;
    v0067 = elt(env, 1); // lambda_u9iz36vfudu4
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(qenv(fn), v0110, v0067);
    }
}



// Code for lambda_u9iz36vfudu4

static LispObject CC_lambda_u9iz36vfudu4(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0110, v0070;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_u9iz36vfudu4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0110 = v0001;
    v0070 = v0000;
// end of prologue
        return Lleq(nil, v0070, v0110);
}



// Code for qqe_eta!-in!-term

static LispObject CC_qqe_etaKinKterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0122, v0003;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_eta-in-term");
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
    v0122 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0122;
    v0122 = stack[0];
    if (!consp(v0122)) goto v0109;
    v0122 = stack[0];
    fn = elt(env, 3); // qqe_op
    v0003 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    v0122 = elt(env, 2); // (lhead rhead)
    v0122 = Lmemq(nil, v0003, v0122);
    if (v0122 == nil) goto v0040;
    v0122 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // qqe_eta!-in!-term1
        return (*qfn1(fn))(qenv(fn), v0122);
    }

v0040:
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    stack[0] = v0122;
    goto v0017;

v0017:
    v0122 = stack[0];
    if (v0122 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0122 = stack[-1];
    if (!(v0122 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0122 = stack[0];
    v0122 = qcar(v0122);
    if (!consp(v0122)) goto v0053;
    v0122 = stack[0];
    v0122 = qcar(v0122);
    fn = elt(env, 3); // qqe_op
    v0003 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    v0122 = elt(env, 2); // (lhead rhead)
    v0122 = Lmemq(nil, v0003, v0122);
    if (v0122 == nil) goto v0111;
    v0122 = stack[0];
    v0122 = qcar(v0122);
    fn = elt(env, 4); // qqe_eta!-in!-term1
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    stack[-1] = v0122;
    goto v0053;

v0053:
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    stack[0] = v0122;
    goto v0017;

v0111:
    v0122 = stack[0];
    v0122 = qcar(v0122);
    v0122 = CC_qqe_etaKinKterm(env, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    stack[-1] = v0122;
    goto v0053;

v0109:
    v0122 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0122); }
// error exit handlers
v0123:
    popv(3);
    return nil;
}



// Code for ibalp_negatet

static LispObject CC_ibalp_negatet(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0023, v0065, v0024;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_negatet");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0024 = v0000;
// end of prologue
    v0065 = v0024;
    v0023 = (LispObject)1; // 0
    if (v0065 == v0023) goto v0008;
    v0065 = v0024;
    v0023 = (LispObject)17; // 1
    if (v0065 == v0023) goto v0015;
    v0023 = elt(env, 1); // bnot
    v0065 = v0024;
    return list2(v0023, v0065);

v0015:
    v0023 = (LispObject)1; // 0
    return onevalue(v0023);

v0008:
    v0023 = (LispObject)17; // 1
    return onevalue(v0023);
}



// Code for sfto_dprpartksf

static LispObject CC_sfto_dprpartksf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dprpartksf");
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
    v0110 = v0000;
// end of prologue
    stack[0] = v0110;
    fn = elt(env, 1); // sfto_dcontentf
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    {
        LispObject v0015 = stack[0];
        popv(2);
        fn = elt(env, 2); // quotf
        return (*qfn2(fn))(qenv(fn), v0015, v0110);
    }
// error exit handlers
v0042:
    popv(2);
    return nil;
}



// Code for !*!*a2s

static LispObject CC_HHa2s(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0019, v0022;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for **a2s");
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
    v0019 = v0001;
    stack[-3] = v0000;
// end of prologue
    v0019 = stack[-3];
    if (v0019 == nil) goto v0007;
    v0022 = stack[-3];
    v0019 = elt(env, 2); // nochange
    v0019 = Lflagpcar(nil, v0022, v0019);
    env = stack[-5];
    if (v0019 == nil) goto v0023;
    v0019 = stack[-3];
    v0022 = qcar(v0019);
    v0019 = elt(env, 3); // getel
    if (!(v0022 == v0019)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }

v0023:
    v0022 = elt(env, 4); // random
    v0019 = stack[-3];
    fn = elt(env, 11); // smember
    v0019 = (*qfn2(fn))(qenv(fn), v0022, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-5];
    if (v0019 == nil) goto v0002;
    stack[-4] = elt(env, 5); // lambda
    stack[-2] = elt(env, 6); // (!*uncached)
    stack[-1] = elt(env, 7); // progn
    stack[0] = elt(env, 8); // (declare (special !*uncached))
    v0022 = qvalue(elt(env, 9)); // !*!*a2sfn
    v0019 = stack[-3];
    v0019 = list2(v0022, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-5];
    v0019 = list3(stack[-1], stack[0], v0019);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-5];
    v0019 = list3(stack[-4], stack[-2], v0019);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-5];
    v0022 = qvalue(elt(env, 10)); // t
    popv(6);
    return list2(v0019, v0022);

v0002:
    v0022 = qvalue(elt(env, 9)); // !*!*a2sfn
    v0019 = stack[-3];
    popv(6);
    return list2(v0022, v0019);

v0007:
    v0019 = elt(env, 1); // "tell Hearn!!"
    {
        popv(6);
        fn = elt(env, 12); // rederr
        return (*qfn1(fn))(qenv(fn), v0019);
    }
// error exit handlers
v0115:
    popv(6);
    return nil;
}



// Code for diffsq

static LispObject CC_diffsq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0029, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffsq");
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
    v0029 = stack[-2];
    v0030 = qcar(v0029);
    v0029 = stack[-1];
    fn = elt(env, 1); // difff
    stack[-3] = (*qfn2(fn))(qenv(fn), v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    stack[0] = stack[-2];
    v0029 = stack[-2];
    v0030 = qcdr(v0029);
    v0029 = stack[-1];
    fn = elt(env, 1); // difff
    v0029 = (*qfn2(fn))(qenv(fn), v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    fn = elt(env, 2); // multsq
    v0029 = (*qfn2(fn))(qenv(fn), stack[0], v0029);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    fn = elt(env, 3); // negsq
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    fn = elt(env, 4); // addsq
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0029);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0030 = (LispObject)17; // 1
    v0029 = stack[-2];
    v0029 = qcdr(v0029);
    v0029 = cons(v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    {
        LispObject v0060 = stack[0];
        popv(5);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0060, v0029);
    }
// error exit handlers
v0050:
    popv(5);
    return nil;
}



// Code for evdif

static LispObject CC_evdif(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0030, v0059, v0121;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evdif");
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
    v0121 = nil;
    goto v0057;

v0057:
    v0030 = stack[0];
    if (v0030 == nil) goto v0053;
    v0030 = stack[-1];
    if (!(v0030 == nil)) goto v0018;
    v0030 = elt(env, 2); // (0)
    stack[-1] = v0030;
    goto v0018;

v0018:
    v0030 = stack[-1];
    v0059 = qcar(v0030);
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0030 = (LispObject)(int32_t)((int32_t)v0059 - (int32_t)v0030 + TAG_FIXNUM);
    v0059 = v0121;
    v0030 = cons(v0030, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    v0121 = v0030;
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    stack[-1] = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    goto v0057;

v0053:
    v0030 = v0121;
    v0059 = Lnreverse(nil, v0030);
    v0030 = stack[-1];
        popv(3);
        return Lnconc(nil, v0059, v0030);
// error exit handlers
v0050:
    popv(3);
    return nil;
}



// Code for arg2of2

static LispObject CC_arg2of2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject v0008, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arg2of2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0001;
    v0007 = v0000;
// end of prologue
    return onevalue(v0008);
}



// Code for wedgek2

static LispObject CC_wedgek2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0151, v0152, v0153;
    LispObject fn;
    LispObject v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "wedgek2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgek2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0063;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue

v0051:
    v0152 = stack[-4];
    v0151 = stack[-3];
    v0151 = qcar(v0151);
    if (v0152 == v0151) goto v0041;
    v0151 = qvalue(elt(env, 2)); // nil
    goto v0070;

v0070:
    if (v0151 == nil) goto v0122;
    v0151 = stack[-4];
    fn = elt(env, 3); // deg!*form
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    v0152 = v0151;
    v0151 = v0152;
    v0151 = integerp(v0151);
    if (v0151 == nil) goto v0028;
    v0151 = v0152;
    v0151 = Loddp(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    goto v0053;

v0053:
    if (v0151 == nil) goto v0091;
    v0151 = qvalue(elt(env, 2)); // nil
    { popv(7); return onevalue(v0151); }

v0091:
    v0152 = stack[-4];
    v0151 = stack[-3];
    v0151 = cons(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    fn = elt(env, 4); // wedgef
    stack[0] = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    v0151 = stack[-2];
    fn = elt(env, 5); // mksgnsq
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    {
        LispObject v0155 = stack[0];
        popv(7);
        fn = elt(env, 6); // multpfsq
        return (*qfn2(fn))(qenv(fn), v0155, v0151);
    }

v0028:
    v0151 = qvalue(elt(env, 2)); // nil
    goto v0053;

v0122:
    v0151 = stack[-3];
    v0152 = qcar(v0151);
    v0151 = elt(env, 1); // wedge
    if (!consp(v0152)) goto v0081;
    v0152 = qcar(v0152);
    if (!(v0152 == v0151)) goto v0081;
    v0151 = stack[-3];
    v0151 = qcar(v0151);
    v0151 = qcdr(v0151);
    stack[-3] = v0151;
    goto v0051;

v0081:
    v0152 = stack[-4];
    v0151 = elt(env, 1); // wedge
    if (!consp(v0152)) goto v0156;
    v0152 = qcar(v0152);
    if (!(v0152 == v0151)) goto v0156;
    v0151 = stack[-4];
    v0152 = qcdr(v0151);
    v0151 = stack[-3];
    fn = elt(env, 7); // wedgewedge
    stack[0] = (*qfn2(fn))(qenv(fn), v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    v0151 = stack[-2];
    fn = elt(env, 5); // mksgnsq
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    {
        LispObject v0157 = stack[0];
        popv(7);
        fn = elt(env, 6); // multpfsq
        return (*qfn2(fn))(qenv(fn), v0157, v0151);
    }

v0156:
    v0152 = stack[-4];
    v0151 = stack[-3];
    v0151 = qcar(v0151);
    fn = elt(env, 8); // worderp
    v0151 = (*qfn2(fn))(qenv(fn), v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    if (v0151 == nil) goto v0158;
    v0152 = stack[-4];
    v0151 = stack[-3];
    v0151 = cons(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    fn = elt(env, 4); // wedgef
    stack[0] = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    v0151 = stack[-2];
    fn = elt(env, 5); // mksgnsq
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    {
        LispObject v0159 = stack[0];
        popv(7);
        fn = elt(env, 6); // multpfsq
        return (*qfn2(fn))(qenv(fn), v0159, v0151);
    }

v0158:
    v0151 = stack[-3];
    v0151 = qcdr(v0151);
    if (v0151 == nil) goto v0160;
    v0151 = stack[-3];
    v0153 = qcar(v0151);
    v0152 = (LispObject)17; // 1
    v0151 = (LispObject)17; // 1
    v0151 = list2star(v0153, v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    stack[-5] = ncons(v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    stack[-1] = stack[-4];
    v0151 = stack[-3];
    stack[0] = qcdr(v0151);
    v0151 = stack[-4];
    fn = elt(env, 3); // deg!*form
    stack[-4] = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    v0151 = stack[-3];
    v0151 = qcar(v0151);
    fn = elt(env, 3); // deg!*form
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    fn = elt(env, 9); // multf
    v0151 = (*qfn2(fn))(qenv(fn), stack[-4], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    fn = elt(env, 10); // addf
    v0151 = (*qfn2(fn))(qenv(fn), stack[-2], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    v0151 = CC_wedgek2(env, 3, stack[-1], stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    {
        LispObject v0161 = stack[-5];
        popv(7);
        fn = elt(env, 11); // wedgepf2
        return (*qfn2(fn))(qenv(fn), v0161, v0151);
    }

v0160:
    v0151 = stack[-3];
    v0152 = qcar(v0151);
    v0151 = stack[-4];
    v0151 = list2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    fn = elt(env, 4); // wedgef
    stack[0] = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    stack[-1] = stack[-2];
    v0151 = stack[-4];
    fn = elt(env, 3); // deg!*form
    stack[-2] = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    v0151 = stack[-3];
    v0151 = qcar(v0151);
    fn = elt(env, 3); // deg!*form
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    fn = elt(env, 9); // multf
    v0151 = (*qfn2(fn))(qenv(fn), stack[-2], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    fn = elt(env, 10); // addf
    v0151 = (*qfn2(fn))(qenv(fn), stack[-1], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    fn = elt(env, 5); // mksgnsq
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-6];
    {
        LispObject v0162 = stack[0];
        popv(7);
        fn = elt(env, 6); // multpfsq
        return (*qfn2(fn))(qenv(fn), v0162, v0151);
    }

v0041:
    v0152 = stack[-4];
    v0151 = elt(env, 1); // wedge
    v0151 = Leqcar(nil, v0152, v0151);
    env = stack[-6];
    v0151 = (v0151 == nil ? lisp_true : nil);
    goto v0070;
// error exit handlers
v0154:
    popv(7);
    return nil;
}



// Code for one!-entry!-listp

static LispObject CC_oneKentryKlistp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0024, v0093;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for one-entry-listp");
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

v0031:
    v0024 = stack[-1];
    if (v0024 == nil) goto v0007;
    v0024 = stack[-1];
    v0093 = qcar(v0024);
    v0024 = stack[0];
    fn = elt(env, 3); // one!-entryp
    v0024 = (*qfn2(fn))(qenv(fn), v0093, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    if (v0024 == nil) goto v0042;
    v0024 = stack[-1];
    v0093 = qcdr(v0024);
    v0024 = stack[0];
    stack[-1] = v0093;
    stack[0] = v0024;
    goto v0031;

v0042:
    v0024 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0024); }

v0007:
    v0024 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0024); }
// error exit handlers
v0011:
    popv(3);
    return nil;
}



// Code for prepd1

static LispObject CC_prepd1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0018, v0049;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepd1");
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
    v0049 = v0000;
// end of prologue
    v0040 = v0049;
    if (!consp(v0040)) return onevalue(v0049);
    v0040 = v0049;
    v0018 = qcar(v0040);
    v0040 = elt(env, 1); // prepfn
    v0040 = get(v0018, v0040);
    v0018 = v0049;
        return Lapply1(nil, v0040, v0018);
}



// Code for simpexpt

static LispObject CC_simpexpt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0093, v0033, v0126;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpexpt");
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
    v0093 = qvalue(elt(env, 1)); // nil
    stack[-1] = qvalue(elt(env, 2)); // kord!*
    qvalue(elt(env, 2)) = v0093; // kord!*
    v0093 = stack[0];
    v0033 = qcdr(v0093);
    v0093 = elt(env, 3); // expt
    fn = elt(env, 5); // carx
    v0093 = (*qfn2(fn))(qenv(fn), v0033, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    fn = elt(env, 6); // simpexpon
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; // kord!*
    v0033 = v0093;
    v0093 = elt(env, 4); // resimp
    fn = elt(env, 7); // simpexpon1
    v0093 = (*qfn2(fn))(qenv(fn), v0033, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0033 = stack[0];
    v0126 = qcar(v0033);
    v0033 = v0093;
    v0093 = qvalue(elt(env, 1)); // nil
    {
        popv(3);
        fn = elt(env, 8); // simpexpt1
        return (*qfnn(fn))(qenv(fn), 3, v0126, v0033, v0093);
    }
// error exit handlers
v0053:
    popv(3);
    return nil;
v0012:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; // kord!*
    popv(3);
    return nil;
}



// Code for pasf_smwcpknowl

static LispObject CC_pasf_smwcpknowl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smwcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0015 = v0000;
// end of prologue
    v0042 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0042 == nil) goto v0109;
    v0042 = v0015;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(qenv(fn), v0042);
    }

v0109:
    v0042 = v0015;
    {
        fn = elt(env, 3); // cl_smcpknowl
        return (*qfn1(fn))(qenv(fn), v0042);
    }
}



// Code for ibalp_isinminclause

static LispObject CC_ibalp_isinminclause(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0076, v0101;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_isinminclause");
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
    v0076 = stack[-2];
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    stack[-3] = v0076;
    goto v0042;

v0042:
    v0076 = stack[-3];
    if (v0076 == nil) goto v0070;
    v0076 = stack[0];
    if (!(v0076 == nil)) goto v0070;
    v0076 = stack[-3];
    v0076 = qcar(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    if (v0076 == nil) goto v0064;
    v0076 = qvalue(elt(env, 1)); // nil
    goto v0049;

v0049:
    if (v0076 == nil) goto v0041;
    v0076 = qvalue(elt(env, 2)); // t
    stack[0] = v0076;
    goto v0041;

v0041:
    v0076 = stack[-3];
    v0076 = qcdr(v0076);
    stack[-3] = v0076;
    goto v0042;

v0064:
    v0076 = stack[-3];
    v0076 = qcar(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0101 = qcar(v0076);
    v0076 = stack[-3];
    v0076 = qcar(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    v0101 = plus2(v0101, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0076 = stack[-1];
    v0076 = Leqn(nil, v0101, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    goto v0049;

v0070:
    v0076 = stack[-2];
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    stack[-3] = v0076;
    goto v0122;

v0122:
    v0076 = stack[-3];
    if (v0076 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0076 = stack[0];
    if (!(v0076 == nil)) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0076 = stack[-3];
    v0076 = qcar(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    if (v0076 == nil) goto v0164;
    v0076 = qvalue(elt(env, 1)); // nil
    goto v0165;

v0165:
    if (v0076 == nil) goto v0022;
    v0076 = qvalue(elt(env, 2)); // t
    stack[0] = v0076;
    goto v0022;

v0022:
    v0076 = stack[-3];
    v0076 = qcdr(v0076);
    stack[-3] = v0076;
    goto v0122;

v0164:
    v0076 = stack[-3];
    v0076 = qcar(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0101 = qcar(v0076);
    v0076 = stack[-3];
    v0076 = qcar(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    v0101 = plus2(v0101, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0076 = stack[-1];
    v0076 = Leqn(nil, v0101, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    goto v0165;
// error exit handlers
v0144:
    popv(5);
    return nil;
}



// Code for ofsf_subf

static LispObject CC_ofsf_subf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0168, v0141, v0169;
    LispObject fn;
    LispObject v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_subf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_subf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0063;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0168 = stack[-2];
    if (!consp(v0168)) goto v0042;
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = (consp(v0168) ? nil : lisp_true);
    goto v0070;

v0070:
    if (v0168 == nil) goto v0048;
    v0141 = stack[-2];
    v0168 = (LispObject)17; // 1
    popv(5);
    return cons(v0141, v0168);

v0048:
    v0168 = stack[-2];
    v0169 = qcdr(v0168);
    v0141 = stack[-1];
    v0168 = stack[0];
    v0168 = CC_ofsf_subf(env, 3, v0169, v0141, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    stack[-3] = v0168;
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    v0141 = qcar(v0168);
    v0168 = stack[-1];
    if (v0141 == v0168) goto v0066;
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0169 = qcdr(v0168);
    v0141 = stack[-1];
    v0168 = stack[0];
    stack[0] = CC_ofsf_subf(env, 3, v0169, v0141, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    v0141 = qcar(v0168);
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    v0168 = qcdr(v0168);
    fn = elt(env, 2); // ofsf_pow2q
    v0168 = (*qfn2(fn))(qenv(fn), v0141, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    fn = elt(env, 3); // multsq
    v0141 = (*qfn2(fn))(qenv(fn), stack[0], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0168 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(qenv(fn), v0141, v0168);
    }

v0066:
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0141 = qcdr(v0168);
    v0168 = (LispObject)17; // 1
    stack[-1] = cons(v0141, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0141 = stack[0];
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    v0168 = qcdr(v0168);
    fn = elt(env, 5); // exptsq
    v0168 = (*qfn2(fn))(qenv(fn), v0141, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    fn = elt(env, 3); // multsq
    v0141 = (*qfn2(fn))(qenv(fn), stack[-1], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-4];
    v0168 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(qenv(fn), v0141, v0168);
    }

v0042:
    v0168 = qvalue(elt(env, 1)); // t
    goto v0070;
// error exit handlers
v0099:
    popv(5);
    return nil;
}



// Code for ev_lexcomp

static LispObject CC_ev_lexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0053, v0028;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_lexcomp");
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

v0007:
    v0053 = stack[-1];
    if (v0053 == nil) goto v0057;
    v0053 = stack[-1];
    v0028 = qcar(v0053);
    v0053 = stack[0];
    v0053 = qcar(v0053);
    fn = elt(env, 1); // iequal
    v0053 = (*qfn2(fn))(qenv(fn), v0028, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    if (v0053 == nil) goto v0009;
    v0053 = stack[-1];
    v0053 = qcdr(v0053);
    stack[-1] = v0053;
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    stack[0] = v0053;
    goto v0007;

v0009:
    v0053 = stack[-1];
    v0028 = qcar(v0053);
    v0053 = stack[0];
    v0053 = qcar(v0053);
    if (((int32_t)(v0028)) > ((int32_t)(v0053))) goto v0049;
    v0053 = (LispObject)-15; // -1
    { popv(3); return onevalue(v0053); }

v0049:
    v0053 = (LispObject)17; // 1
    { popv(3); return onevalue(v0053); }

v0057:
    v0053 = (LispObject)1; // 0
    { popv(3); return onevalue(v0053); }
// error exit handlers
v0037:
    popv(3);
    return nil;
}



// Code for mchkopt1

static LispObject CC_mchkopt1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0179, v0180, v0140;
    LispObject fn;
    LispObject v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mchkopt1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchkopt1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0063;
    v0179 = v0001;
    v0140 = v0000;
// end of prologue
    v0179 = qcdr(v0179);
    v0180 = v0179;
    if (v0179 == nil) goto v0110;
    v0179 = v0180;
    v0179 = qcar(v0179);
    stack[-3] = v0179;
    v0179 = v0180;
    v0179 = qcdr(v0179);
    v0180 = v0179;
    if (v0179 == nil) goto v0107;
    v0179 = v0180;
    v0179 = qcar(v0179);
    stack[-5] = v0179;
    v0179 = v0180;
    v0179 = qcdr(v0179);
    if (v0179 == nil) goto v0049;
    v0179 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0179); }

v0049:
    v0179 = stack[-3];
    if (!symbolp(v0179)) v0179 = nil;
    else { v0179 = qfastgets(v0179);
           if (v0179 != nil) { v0179 = elt(v0179, 6); // optional
#ifdef RECORD_GET
             if (v0179 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v0179 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v0179 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v0179 == SPID_NOPROP) v0179 = nil; else v0179 = lisp_true; }}
#endif
    if (v0179 == nil) goto v0093;
    v0180 = v0140;
    v0179 = stack[-5];
    fn = elt(env, 2); // mchk
    v0179 = (*qfn2(fn))(qenv(fn), v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    stack[-5] = v0179;
    v0179 = stack[-5];
    if (v0179 == nil) goto v0050;
    v0179 = stack[-5];
    v0179 = qcar(v0179);
    v0140 = stack[-3];
    v0180 = stack[-4];
    v0180 = qcar(v0180);
    v0179 = acons(v0140, v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    v0179 = ncons(v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    stack[-1] = v0179;
    stack[-2] = v0179;
    goto v0064;

v0064:
    v0179 = stack[-5];
    v0179 = qcdr(v0179);
    stack[-5] = v0179;
    v0179 = stack[-5];
    if (v0179 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0179 = stack[-5];
    v0179 = qcar(v0179);
    v0140 = stack[-3];
    v0180 = stack[-4];
    v0180 = qcar(v0180);
    v0179 = acons(v0140, v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    v0179 = ncons(v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    v0179 = Lrplacd(nil, stack[0], v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    v0179 = stack[-1];
    v0179 = qcdr(v0179);
    stack[-1] = v0179;
    goto v0064;

v0050:
    v0179 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0179); }

v0093:
    v0179 = stack[-5];
    if (!symbolp(v0179)) v0179 = nil;
    else { v0179 = qfastgets(v0179);
           if (v0179 != nil) { v0179 = elt(v0179, 6); // optional
#ifdef RECORD_GET
             if (v0179 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v0179 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v0179 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v0179 == SPID_NOPROP) v0179 = nil; else v0179 = lisp_true; }}
#endif
    if (v0179 == nil) goto v0182;
    v0180 = v0140;
    v0179 = stack[-3];
    fn = elt(env, 2); // mchk
    v0179 = (*qfn2(fn))(qenv(fn), v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    stack[-3] = v0179;
    v0179 = stack[-3];
    if (v0179 == nil) goto v0166;
    v0179 = stack[-3];
    v0179 = qcar(v0179);
    v0140 = stack[-5];
    v0180 = stack[-4];
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    v0179 = acons(v0140, v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    v0179 = ncons(v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    stack[-1] = v0179;
    stack[-2] = v0179;
    goto v0163;

v0163:
    v0179 = stack[-3];
    v0179 = qcdr(v0179);
    stack[-3] = v0179;
    v0179 = stack[-3];
    if (v0179 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0179 = stack[-3];
    v0179 = qcar(v0179);
    v0140 = stack[-5];
    v0180 = stack[-4];
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    v0179 = acons(v0140, v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    v0179 = ncons(v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    v0179 = Lrplacd(nil, stack[0], v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-6];
    v0179 = stack[-1];
    v0179 = qcdr(v0179);
    stack[-1] = v0179;
    goto v0163;

v0166:
    v0179 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0179); }

v0182:
    v0179 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0179); }

v0107:
    v0179 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0179); }

v0110:
    v0179 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0179); }
// error exit handlers
v0181:
    popv(7);
    return nil;
}



// Code for inttovec1

static LispObject CC_inttovec1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0016, v0050;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inttovec1");
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
    v0050 = stack[-1];
    v0016 = (LispObject)17; // 1
    if (v0050 == v0016) goto v0007;
    v0016 = stack[-1];
    v0050 = sub1(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    fn = elt(env, 1); // inttovec!-solve
    v0016 = (*qfn2(fn))(qenv(fn), v0050, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    stack[-2] = v0016;
    v0016 = stack[0];
    v0050 = qcar(v0016);
    v0016 = stack[-2];
    v0016 = qcar(v0016);
    stack[0] = difference2(v0050, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    v0016 = stack[-1];
    v0050 = sub1(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    v0016 = stack[-2];
    v0016 = CC_inttovec1(env, v0050, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    {
        LispObject v0036 = stack[0];
        popv(4);
        return cons(v0036, v0016);
    }

v0007:
    v0016 = stack[0];
    v0016 = qcar(v0016);
    popv(4);
    return ncons(v0016);
// error exit handlers
v0005:
    popv(4);
    return nil;
}



// Code for mkfortterpri

static LispObject CC_mkfortterpri(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0004;
    argcheck(nargs, 0, "mkfortterpri");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkfortterpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0004 = elt(env, 1); // fortterpri
    return ncons(v0004);
}



// Code for trwrite

static LispObject CC_trwrite(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0112;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for trwrite");
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
    v0112 = stack[0];
    v0112 = qcar(v0112);
    if (!symbolp(v0112)) v0112 = nil;
    else { v0112 = qfastgets(v0112);
           if (v0112 != nil) { v0112 = elt(v0112, 53); // tracing
#ifdef RECORD_GET
             if (v0112 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v0112 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v0112 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v0112 == SPID_NOPROP) v0112 = nil; else v0112 = lisp_true; }}
#endif
    if (v0112 == nil) goto v0183;
    v0112 = elt(env, 2); // "**in procedure: "
    v0112 = Lprinc(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0112 = stack[0];
    v0112 = qcar(v0112);
    v0112 = Lprinc(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0112 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    stack[0] = v0112;
    goto v0026;

v0026:
    v0112 = stack[0];
    if (v0112 == nil) goto v0113;
    v0112 = stack[0];
    v0112 = qcar(v0112);
    v0112 = Lprinc(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    stack[0] = v0112;
    goto v0026;

v0113:
    v0112 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    v0112 = nil;
    { popv(2); return onevalue(v0112); }

v0183:
    v0112 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0112); }
// error exit handlers
v0053:
    popv(2);
    return nil;
}



// Code for setelv

static LispObject CC_setelv(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0036, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setelv");
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
    v0006 = v0000;
// end of prologue
    v0036 = v0006;
    stack[-5] = qcar(v0036);
    v0036 = v0006;
    v0036 = qcdr(v0036);
    stack[-3] = v0036;
    v0036 = stack[-3];
    if (v0036 == nil) goto v0018;
    v0036 = stack[-3];
    v0036 = qcar(v0036);
    fn = elt(env, 2); // reval_without_mod
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    v0036 = ncons(v0036);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    stack[-1] = v0036;
    stack[-2] = v0036;
    goto v0113;

v0113:
    v0036 = stack[-3];
    v0036 = qcdr(v0036);
    stack[-3] = v0036;
    v0036 = stack[-3];
    if (v0036 == nil) goto v0112;
    stack[0] = stack[-1];
    v0036 = stack[-3];
    v0036 = qcar(v0036);
    fn = elt(env, 2); // reval_without_mod
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    v0036 = ncons(v0036);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    v0036 = Lrplacd(nil, stack[0], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    v0036 = stack[-1];
    v0036 = qcdr(v0036);
    stack[-1] = v0036;
    goto v0113;

v0112:
    v0036 = stack[-2];
    goto v0042;

v0042:
    v0006 = cons(stack[-5], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-6];
    v0036 = stack[-4];
    {
        popv(7);
        fn = elt(env, 3); // setel
        return (*qfn2(fn))(qenv(fn), v0006, v0036);
    }

v0018:
    v0036 = qvalue(elt(env, 1)); // nil
    goto v0042;
// error exit handlers
v0066:
    popv(7);
    return nil;
}



// Code for moid_member

static LispObject CC_moid_member(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0017, v0108;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for moid_member");
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

v0031:
    v0017 = stack[0];
    if (v0017 == nil) goto v0007;
    v0017 = stack[0];
    v0108 = qcar(v0017);
    v0017 = stack[-1];
    fn = elt(env, 2); // mo_vdivides!?
    v0017 = (*qfn2(fn))(qenv(fn), v0108, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    if (!(v0017 == nil)) { popv(3); return onevalue(v0017); }
    v0108 = stack[-1];
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    stack[-1] = v0108;
    stack[0] = v0017;
    goto v0031;

v0007:
    v0017 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0017); }
// error exit handlers
v0024:
    popv(3);
    return nil;
}



// Code for pst_termnodep

static LispObject CC_pst_termnodep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0015;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0042 = v0000;
// end of prologue
    v0015 = qcdr(v0042);
    v0042 = (LispObject)1; // 0
    v0042 = *(LispObject *)((char *)v0015 + (CELL-TAG_VECTOR) + ((int32_t)v0042/(16/CELL)));
    v0042 = qcdr(v0042);
    v0042 = (v0042 == nil ? lisp_true : nil);
    return onevalue(v0042);
}



// Code for ratn

static LispObject CC_ratn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0030, v0059, v0121;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0121 = v0000;
// end of prologue
    v0030 = v0121;
    if (v0030 == nil) goto v0057;
    v0030 = v0121;
    if (!consp(v0030)) goto v0058;
    v0030 = v0121;
    v0059 = qcar(v0030);
    v0030 = elt(env, 1); // !:rn!:
    if (v0059 == v0030) goto v0040;
    v0121 = elt(env, 2); // arnum
    v0059 = (LispObject)97; // 6
    v0030 = elt(env, 3); // "Illegal domain in :ar:"
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0121, v0059, v0030);
    }

v0040:
    v0030 = v0121;
    v0030 = qcdr(v0030);
    return onevalue(v0030);

v0058:
    v0059 = v0121;
    v0030 = (LispObject)17; // 1
    return cons(v0059, v0030);

v0057:
    v0059 = (LispObject)1; // 0
    v0030 = (LispObject)17; // 1
    return cons(v0059, v0030);
}



// Code for replus

static LispObject CC_replus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0038, v0009;
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
    v0009 = v0000;
// end of prologue
    v0038 = v0009;
    if (v0038 == nil) goto v0008;
    v0038 = v0009;
    if (!consp(v0038)) { popv(1); return onevalue(v0009); }
    v0038 = v0009;
    v0038 = qcdr(v0038);
    if (v0038 == nil) goto v0070;
    stack[0] = elt(env, 1); // plus
    v0038 = v0009;
    fn = elt(env, 2); // unplus
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    {
        LispObject v0108 = stack[0];
        popv(1);
        return cons(v0108, v0038);
    }

v0070:
    v0038 = v0009;
    v0038 = qcar(v0038);
    { popv(1); return onevalue(v0038); }

v0008:
    v0038 = (LispObject)1; // 0
    { popv(1); return onevalue(v0038); }
// error exit handlers
v0017:
    popv(1);
    return nil;
}



// Code for ibalp_var!-set

static LispObject CC_ibalp_varKset(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0100, v0176;
    LispObject fn;
    LispObject v0004, v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ibalp_var-set");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-set");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0063,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
    stack[-1] = v0063;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0100 = stack[-3];
    v0176 = qcdr(v0100);
    v0100 = stack[-2];
    fn = elt(env, 1); // setcar
    v0100 = (*qfn2(fn))(qenv(fn), v0176, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0176 = qcdr(v0100);
    v0100 = stack[-1];
    fn = elt(env, 1); // setcar
    v0100 = (*qfn2(fn))(qenv(fn), v0176, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0176 = qcdr(v0100);
    v0100 = stack[0];
    fn = elt(env, 1); // setcar
    v0100 = (*qfn2(fn))(qenv(fn), v0176, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    stack[0] = v0100;
    v0176 = stack[-2];
    v0100 = (LispObject)1; // 0
    v0100 = Leqn(nil, v0176, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    if (v0100 == nil) goto v0125;
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    goto v0044;

v0044:
    v0176 = v0100;
    v0100 = stack[0];
    fn = elt(env, 2); // ibalp_var!-satlist
    v0100 = (*qfn2(fn))(qenv(fn), v0176, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0176 = stack[-2];
    v0100 = (LispObject)17; // 1
    v0100 = Leqn(nil, v0176, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    if (v0100 == nil) goto v0185;
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    goto v0118;

v0118:
    v0176 = v0100;
    v0100 = stack[-2];
    fn = elt(env, 3); // ibalp_var!-unsatlist
    v0100 = (*qfn2(fn))(qenv(fn), v0176, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0100 = stack[-3];
    fn = elt(env, 4); // ibalp_var!-wclist
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    stack[-1] = v0100;
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    stack[0] = qcdr(v0100);
    v0100 = stack[-3];
    fn = elt(env, 5); // ibalp_calcmom
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    fn = elt(env, 1); // setcar
    v0100 = (*qfn2(fn))(qenv(fn), stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    { LispObject res = stack[-1]; popv(5); return onevalue(res); }

v0185:
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    goto v0118;

v0125:
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    goto v0044;
// error exit handlers
v0184:
    popv(5);
    return nil;
}



// Code for unaryrd

static LispObject CC_unaryrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0057;
    LispObject fn;
    argcheck(nargs, 0, "unaryrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unaryrd");
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
    v0057 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    stack[0] = v0057;
    fn = elt(env, 2); // lex
    v0057 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    v0057 = stack[0];
    popv(2);
    return ncons(v0057);
// error exit handlers
v0067:
    popv(2);
    return nil;
}



// Code for dm!-minus

static LispObject CC_dmKminus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0051;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-minus");
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
    v0015 = v0000;
// end of prologue
    fn = elt(env, 1); // !:minus
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    errexit();
    v0051 = v0015;
    v0015 = v0051;
    if (!(v0015 == nil)) return onevalue(v0051);
    v0015 = (LispObject)1; // 0
    return onevalue(v0015);
}



// Code for quoteequation

static LispObject CC_quoteequation(LispObject env,
                         LispObject v0000)
{
    LispObject v0004;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quoteequation");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0004 = v0000;
// end of prologue
    v0004 = elt(env, 1); // equation
    return onevalue(v0004);
}



// Code for evgradlexcomp

static LispObject CC_evgradlexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0014, v0052;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evgradlexcomp");
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

v0007:
    v0014 = stack[-2];
    if (v0014 == nil) goto v0057;
    v0014 = stack[-1];
    if (v0014 == nil) goto v0070;
    v0014 = stack[-2];
    v0052 = qcar(v0014);
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    fn = elt(env, 2); // iequal
    v0014 = (*qfn2(fn))(qenv(fn), v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    if (v0014 == nil) goto v0017;
    v0014 = stack[-2];
    v0014 = qcdr(v0014);
    stack[-2] = v0014;
    v0014 = stack[-1];
    v0014 = qcdr(v0014);
    stack[-1] = v0014;
    goto v0007;

v0017:
    v0014 = stack[-2];
    fn = elt(env, 3); // evtdeg
    stack[0] = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0014 = stack[-1];
    fn = elt(env, 3); // evtdeg
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0014;
    v0052 = stack[-3];
    v0014 = stack[0];
    fn = elt(env, 2); // iequal
    v0014 = (*qfn2(fn))(qenv(fn), v0052, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    if (v0014 == nil) goto v0034;
    v0014 = stack[-2];
    v0052 = qcar(v0014);
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    if (((int32_t)(v0052)) > ((int32_t)(v0014))) goto v0032;
    v0014 = (LispObject)-15; // -1
    { popv(5); return onevalue(v0014); }

v0032:
    v0014 = (LispObject)17; // 1
    { popv(5); return onevalue(v0014); }

v0034:
    v0052 = stack[-3];
    v0014 = stack[0];
    if (((int32_t)(v0052)) > ((int32_t)(v0014))) goto v0066;
    v0014 = (LispObject)-15; // -1
    { popv(5); return onevalue(v0014); }

v0066:
    v0014 = (LispObject)17; // 1
    { popv(5); return onevalue(v0014); }

v0070:
    v0014 = elt(env, 1); // (0)
    stack[-1] = v0014;
    goto v0007;

v0057:
    v0014 = (LispObject)1; // 0
    { popv(5); return onevalue(v0014); }
// error exit handlers
v0054:
    popv(5);
    return nil;
}



// Code for physopsm!*

static LispObject CC_physopsmH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0208, v0209, v0210, v0211;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopsm*");
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
    stack[0] = nil;
    v0208 = stack[-3];
    if (v0208 == nil) goto v0051;
    v0208 = stack[-3];
    v0208 = (is_number(v0208) ? lisp_true : nil);
    goto v0015;

v0015:
    if (v0208 == nil) goto v0070;
    v0208 = stack[-3];
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0070:
    v0208 = stack[-3];
    fn = elt(env, 13); // physopp
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    if (v0208 == nil) goto v0039;
    v0208 = stack[-3];
    if (!symbolp(v0208)) v0208 = nil;
    else { v0208 = qfastgets(v0208);
           if (v0208 != nil) { v0208 = elt(v0208, 46); // rvalue
#ifdef RECORD_GET
             if (v0208 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v0208 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v0208 == SPID_NOPROP) v0208 = nil; }}
#endif
    stack[-1] = v0208;
    if (v0208 == nil) goto v0048;
    v0208 = stack[-1];
    fn = elt(env, 14); // physopaeval
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    goto v0038;

v0038:
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0048:
    v0208 = stack[-3];
    if (symbolp(v0208)) goto v0024;
    v0208 = stack[-3];
    v0209 = qcar(v0208);
    v0208 = elt(env, 2); // psimpfn
    v0208 = get(v0209, v0208);
    env = stack[-5];
    stack[-1] = v0208;
    if (v0208 == nil) goto v0112;
    v0209 = stack[-1];
    v0208 = stack[-3];
    v0208 = Lapply1(nil, v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    goto v0038;

v0112:
    v0208 = stack[-3];
    v0208 = qcar(v0208);
    if (!symbolp(v0208)) v0208 = nil;
    else { v0208 = qfastgets(v0208);
           if (v0208 != nil) { v0208 = elt(v0208, 9); // opmtch
#ifdef RECORD_GET
             if (v0208 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0208 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0208 == SPID_NOPROP) v0208 = nil; }}
#endif
    if (v0208 == nil) goto v0066;
    v0208 = stack[-3];
    fn = elt(env, 15); // opmtch!*
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    stack[-1] = v0208;
    if (v0208 == nil) goto v0066;
    v0208 = stack[-1];
    goto v0038;

v0066:
    v0208 = stack[-3];
    goto v0038;

v0024:
    v0208 = stack[-3];
    goto v0038;

v0039:
    v0208 = stack[-3];
    if (!consp(v0208)) goto v0035;
    v0208 = stack[-3];
    v0208 = qcar(v0208);
    stack[-4] = v0208;
    v0208 = stack[-3];
    v0208 = qcdr(v0208);
    stack[-2] = v0208;
    v0209 = stack[-4];
    v0208 = elt(env, 3); // physopfunction
    v0208 = get(v0209, v0208);
    env = stack[-5];
    stack[-1] = v0208;
    if (v0208 == nil) goto v0213;
    v0209 = stack[-4];
    v0208 = elt(env, 4); // physoparith
    v0208 = Lflagp(nil, v0209, v0208);
    env = stack[-5];
    if (v0208 == nil) goto v0176;
    v0208 = stack[-2];
    fn = elt(env, 16); // hasonephysop
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    if (v0208 == nil) goto v0178;
    stack[0] = stack[-1];
    v0208 = stack[-2];
    v0208 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    fn = elt(env, 17); // apply
    v0208 = (*qfn2(fn))(qenv(fn), stack[0], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0178:
    v0209 = stack[-4];
    v0208 = stack[-2];
    v0208 = cons(v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    fn = elt(env, 18); // reval3
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0176:
    v0209 = stack[-4];
    v0208 = elt(env, 5); // physopfn
    v0208 = Lflagp(nil, v0209, v0208);
    env = stack[-5];
    if (v0208 == nil) goto v0182;
    v0208 = stack[-2];
    fn = elt(env, 19); // areallphysops
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    if (v0208 == nil) goto v0214;
    stack[0] = stack[-1];
    v0208 = stack[-2];
    v0208 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    fn = elt(env, 17); // apply
    v0208 = (*qfn2(fn))(qenv(fn), stack[0], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0214:
    stack[-1] = elt(env, 0); // physopsm!*
    v0211 = elt(env, 6); // "invalid call of "
    v0210 = stack[-4];
    v0209 = elt(env, 7); // " with args: "
    v0208 = stack[-2];
    v0208 = list4(v0211, v0210, v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    fn = elt(env, 20); // rederr2
    v0208 = (*qfn2(fn))(qenv(fn), stack[-1], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0182:
    stack[-1] = elt(env, 0); // physopsm!*
    v0210 = stack[-4];
    v0209 = elt(env, 8); // " has been flagged Physopfunction"
    v0208 = elt(env, 9); // " but is not defined"
    v0208 = list3(v0210, v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    fn = elt(env, 20); // rederr2
    v0208 = (*qfn2(fn))(qenv(fn), stack[-1], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0213:
    v0209 = stack[-4];
    v0208 = elt(env, 10); // physopmapping
    v0208 = Lflagp(nil, v0209, v0208);
    env = stack[-5];
    if (v0208 == nil) goto v0215;
    v0208 = stack[-2];
    fn = elt(env, 21); // !*physopp!*
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    goto v0160;

v0160:
    if (v0208 == nil) goto v0216;
    v0209 = stack[-4];
    v0208 = stack[-2];
    v0209 = cons(v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    v0208 = (LispObject)17; // 1
    fn = elt(env, 22); // to
    v0209 = (*qfn2(fn))(qenv(fn), v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    v0208 = (LispObject)17; // 1
    v0208 = cons(v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    v0209 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    v0208 = (LispObject)17; // 1
    v0208 = cons(v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    fn = elt(env, 23); // mk!*sq
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0216:
    v0209 = stack[-4];
    v0208 = elt(env, 12); // prog
    if (v0209 == v0208) goto v0217;
    v0208 = stack[-3];
    fn = elt(env, 24); // aeval
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0217:
    v0208 = stack[-2];
    fn = elt(env, 25); // physopprog
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0215:
    v0208 = qvalue(elt(env, 11)); // nil
    goto v0160;

v0035:
    v0208 = stack[-3];
    fn = elt(env, 24); // aeval
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    stack[0] = v0208;
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0051:
    v0208 = qvalue(elt(env, 1)); // t
    goto v0015;
// error exit handlers
v0212:
    popv(6);
    return nil;
}



// Code for mktails1

static LispObject CC_mktails1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0143, v0144, v0142;
    LispObject fn;
    LispObject v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mktails1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mktails1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0063;
    v0143 = v0001;
    stack[-1] = v0000;
// end of prologue
    v0144 = stack[-1];
    fn = elt(env, 3); // getroad
    v0143 = (*qfn2(fn))(qenv(fn), v0144, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0144 = v0143;
    v0142 = (LispObject)1; // 0
    v0143 = v0144;
    if (v0142 == v0143) goto v0038;
    v0142 = (LispObject)1; // 0
    v0143 = stack[-1];
    v0143 = qcdr(v0143);
    if (v0142 == v0143) goto v0062;
    v0142 = stack[-1];
    v0143 = stack[0];
    v0143 = Lassoc(nil, v0142, v0143);
    v0142 = v0143;
    v0143 = v0142;
    if (v0143 == nil) goto v0002;
    v0143 = v0142;
    v0143 = qcdr(v0143);
    v0143 = qcdr(v0143);
    if (v0143 == nil) goto v0165;
    v0143 = v0142;
    v0143 = qcdr(v0143);
    v0144 = Lreverse(nil, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    v0143 = stack[0];
    popv(4);
    return cons(v0144, v0143);

v0165:
    v0143 = v0142;
    v0144 = qcdr(v0143);
    v0143 = stack[0];
    popv(4);
    return cons(v0144, v0143);

v0002:
    v0143 = stack[-1];
    fn = elt(env, 4); // mkinds
    v0143 = (*qfn2(fn))(qenv(fn), v0143, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0142 = v0143;
    stack[-2] = v0142;
    v0143 = stack[-1];
    v0144 = v0142;
    v0144 = cons(v0143, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    v0143 = stack[0];
    {
        LispObject v0175 = stack[-2];
        popv(4);
        return list2star(v0175, v0144, v0143);
    }

v0062:
    v0143 = stack[-1];
    v0144 = qcar(v0143);
    v0143 = elt(env, 2); // replace_by_vector
    v0143 = get(v0144, v0143);
    env = stack[-3];
    if (!(v0143 == nil)) goto v0050;
    v0143 = stack[-1];
    v0143 = qcar(v0143);
    goto v0050;

v0050:
    v0144 = ncons(v0143);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    v0143 = stack[0];
    popv(4);
    return cons(v0144, v0143);

v0038:
    v0144 = qvalue(elt(env, 1)); // nil
    v0143 = stack[0];
    popv(4);
    return cons(v0144, v0143);
// error exit handlers
v0219:
    popv(4);
    return nil;
}



// Code for pairxvars

static LispObject CC_pairxvars(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0184, v0080, v0079;
    LispObject fn;
    LispObject v0004, v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pairxvars");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pairxvars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0063,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0004;
    stack[-2] = v0063;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    stack[-5] = nil;
    goto v0109;

v0109:
    v0184 = stack[-4];
    if (v0184 == nil) goto v0113;
    v0184 = stack[-4];
    v0080 = qcar(v0184);
    v0184 = stack[-3];
    v0184 = Latsoc(nil, v0080, v0184);
    stack[0] = v0184;
    if (v0184 == nil) goto v0017;
    v0080 = stack[0];
    v0184 = stack[-3];
    v0184 = Ldelete(nil, v0080, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-6];
    stack[-3] = v0184;
    v0184 = stack[0];
    v0080 = qcdr(v0184);
    v0184 = elt(env, 1); // scalar
    if (v0080 == v0184) goto v0046;
    v0184 = stack[-4];
    v0079 = qcar(v0184);
    v0184 = stack[0];
    v0080 = qcdr(v0184);
    v0184 = stack[-5];
    v0184 = acons(v0079, v0080, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-6];
    stack[-5] = v0184;
    goto v0110;

v0110:
    v0184 = stack[-4];
    v0184 = qcdr(v0184);
    stack[-4] = v0184;
    goto v0109;

v0046:
    v0184 = stack[-4];
    v0079 = qcar(v0184);
    v0080 = stack[-1];
    v0184 = stack[-5];
    v0184 = acons(v0079, v0080, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-6];
    stack[-5] = v0184;
    goto v0110;

v0017:
    v0184 = stack[-4];
    v0184 = qcar(v0184);
    if (symbolp(v0184)) goto v0185;
    v0184 = qvalue(elt(env, 2)); // t
    goto v0056;

v0056:
    if (v0184 == nil) goto v0167;
    v0080 = elt(env, 3); // "Invalid parameter:"
    v0184 = stack[-4];
    v0184 = qcar(v0184);
    v0080 = list2(v0080, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-6];
    v0184 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 5); // symerr
    v0184 = (*qfn2(fn))(qenv(fn), v0080, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-6];
    goto v0110;

v0167:
    v0184 = stack[-4];
    v0079 = qcar(v0184);
    v0080 = stack[-1];
    v0184 = stack[-5];
    v0184 = acons(v0079, v0080, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-6];
    stack[-5] = v0184;
    goto v0110;

v0185:
    v0184 = stack[-4];
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
    if (!(v0184 == nil)) goto v0056;
    v0184 = stack[-4];
    v0184 = qcar(v0184);
    if (!symbolp(v0184)) v0184 = nil;
    else { v0184 = qfastgets(v0184);
           if (v0184 != nil) { v0184 = elt(v0184, 36); // stat
#ifdef RECORD_GET
             if (v0184 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0184 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0184 == SPID_NOPROP) v0184 = nil; }}
#endif
    goto v0056;

v0113:
    v0184 = stack[-5];
    fn = elt(env, 6); // reversip!*
    v0080 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-6];
    v0184 = stack[-2];
    v0080 = Lappend(nil, v0080, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    v0184 = stack[-3];
    popv(7);
    return cons(v0080, v0184);
// error exit handlers
v0221:
    popv(7);
    return nil;
}



// Code for setel1

static LispObject CC_setel1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0054, v0055, v0081;
    LispObject fn;
    LispObject v0004, v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "setel1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setel1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0063,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
    stack[-1] = v0063;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue

v0183:
    v0054 = stack[-2];
    v0054 = qcar(v0054);
    v0054 = integerp(v0054);
    if (v0054 == nil) goto v0069;
    v0054 = stack[-2];
    v0055 = qcar(v0054);
    v0054 = stack[0];
    v0054 = qcar(v0054);
    v0054 = (LispObject)geq2(v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0054 = v0054 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0054 == nil)) goto v0120;
    v0054 = stack[-2];
    v0055 = qcar(v0054);
    v0054 = (LispObject)1; // 0
    v0054 = (LispObject)lessp2(v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0054 = v0054 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0054 == nil)) goto v0120;
    v0054 = stack[-2];
    v0054 = qcdr(v0054);
    if (v0054 == nil) goto v0006;
    v0055 = stack[-3];
    v0054 = stack[-2];
    v0054 = qcar(v0054);
    v0054 = *(LispObject *)((char *)v0055 + (CELL-TAG_VECTOR) + ((int32_t)v0054/(16/CELL)));
    stack[-3] = v0054;
    v0054 = stack[-2];
    v0054 = qcdr(v0054);
    stack[-2] = v0054;
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[0] = v0054;
    goto v0183;

v0006:
    v0081 = stack[-3];
    v0054 = stack[-2];
    v0055 = qcar(v0054);
    v0054 = stack[-1];
    *(LispObject *)((char *)v0081 + (CELL-TAG_VECTOR) + ((int32_t)v0055/(16/CELL))) = v0054;
    { popv(5); return onevalue(v0054); }

v0120:
    v0081 = elt(env, 2); // rlisp
    v0055 = (LispObject)369; // 23
    v0054 = elt(env, 3); // "Array out of bounds"
    {
        popv(5);
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0081, v0055, v0054);
    }

v0069:
    v0054 = stack[-2];
    v0055 = qcar(v0054);
    v0054 = elt(env, 1); // "array index"
    {
        popv(5);
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(qenv(fn), v0055, v0054);
    }
// error exit handlers
v0114:
    popv(5);
    return nil;
}



// Code for red!=cancelsimp

static LispObject CC_redMcancelsimp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0009, v0048;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red=cancelsimp");
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
    v0048 = stack[-1];
    v0009 = stack[0];
    fn = elt(env, 2); // red_better
    v0009 = (*qfn2(fn))(qenv(fn), v0048, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    if (v0009 == nil) goto v0007;
    v0009 = stack[-1];
    fn = elt(env, 3); // bas_dpoly
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    fn = elt(env, 4); // dp_lmon
    stack[-1] = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0009 = stack[0];
    fn = elt(env, 3); // bas_dpoly
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    fn = elt(env, 4); // dp_lmon
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    {
        LispObject v0065 = stack[-1];
        popv(3);
        fn = elt(env, 5); // mo_vdivides!?
        return (*qfn2(fn))(qenv(fn), v0065, v0009);
    }

v0007:
    v0009 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0009); }
// error exit handlers
v0023:
    popv(3);
    return nil;
}



// Code for simp!-prop!-order

static LispObject CC_simpKpropKorder(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0028, v0064, v0027, v0037;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-prop-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0064 = v0001;
    v0027 = v0000;
// end of prologue

v0007:
    v0028 = v0027;
    if (v0028 == nil) goto v0057;
    v0028 = v0027;
    v0028 = qcar(v0028);
    v0037 = qcar(v0028);
    v0028 = v0064;
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    if (equal(v0037, v0028)) goto v0070;
    v0028 = v0027;
    v0028 = qcar(v0028);
    v0064 = qcar(v0028);
    v0028 = elt(env, 2); // prop!*
    if (v0064 == v0028) goto v0038;
    v0028 = qvalue(elt(env, 1)); // nil
    return onevalue(v0028);

v0038:
    v0028 = qvalue(elt(env, 3)); // t
    return onevalue(v0028);

v0070:
    v0028 = v0027;
    v0028 = qcdr(v0028);
    v0027 = v0028;
    v0028 = v0064;
    v0028 = qcdr(v0028);
    v0064 = v0028;
    goto v0007;

v0057:
    v0028 = qvalue(elt(env, 1)); // nil
    return onevalue(v0028);
}



// Code for splitlist!:

static LispObject CC_splitlistT(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0011, v0112, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for splitlist:");
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
    v0012 = nil;
    goto v0047;

v0047:
    v0011 = stack[-1];
    if (v0011 == nil) goto v0109;
    v0011 = stack[-1];
    v0112 = qcar(v0011);
    v0011 = stack[0];
    if (!consp(v0112)) goto v0024;
    v0112 = qcar(v0112);
    if (!(v0112 == v0011)) goto v0024;
    v0011 = stack[-1];
    v0011 = qcar(v0011);
    v0112 = v0012;
    v0011 = cons(v0011, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0012 = v0011;
    v0011 = stack[-1];
    v0011 = qcdr(v0011);
    stack[-1] = v0011;
    goto v0047;

v0024:
    v0011 = stack[-1];
    v0011 = qcdr(v0011);
    stack[-1] = v0011;
    goto v0047;

v0109:
    v0011 = v0012;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0011);
    }
// error exit handlers
v0064:
    popv(3);
    return nil;
}



// Code for innprodkp

static LispObject CC_innprodkp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0016, v0050, v0060;
    LispObject fn;
    LispObject v0004, v0063, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "innprodkp");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for innprodkp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0063,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0063,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
    stack[-1] = v0063;
    stack[-2] = v0001;
    v0050 = v0000;
// end of prologue

v0183:
    v0016 = stack[-1];
    if (v0016 == nil) goto v0067;
    v0060 = stack[-2];
    v0016 = stack[-1];
    v0016 = qcar(v0016);
    if (equal(v0060, v0016)) goto v0023;
    v0016 = stack[-1];
    v0016 = qcar(v0016);
    v0016 = cons(v0016, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0050 = v0016;
    v0016 = stack[-1];
    v0016 = qcdr(v0016);
    stack[-1] = v0016;
    v0016 = stack[0];
    v0016 = (v0016 == nil ? lisp_true : nil);
    stack[0] = v0016;
    goto v0183;

v0023:
    v0016 = stack[-1];
    v0016 = qcdr(v0016);
    fn = elt(env, 2); // reversip2
    v0016 = (*qfn2(fn))(qenv(fn), v0050, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        LispObject v0006 = stack[0];
        popv(4);
        return cons(v0006, v0016);
    }

v0067:
    v0016 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0016); }
// error exit handlers
v0036:
    popv(4);
    return nil;
}



// Code for ibalp_readform

static LispObject CC_ibalp_readform(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0205, v0225;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_readform");
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
    v0205 = v0000;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-3] = nil;
    v0225 = (LispObject)1; // 0
    stack[0] = v0225;
    v0225 = v0205;
    v0205 = elt(env, 1); // and
    fn = elt(env, 9); // cl_mkstrict
    v0205 = (*qfn2(fn))(qenv(fn), v0225, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    v0205 = qcdr(v0205);
    stack[-2] = v0205;
    v0205 = qvalue(elt(env, 2)); // t
    stack[-1] = v0205;
    goto v0040;

v0040:
    v0205 = stack[-1];
    if (v0205 == nil) goto v0039;
    v0205 = stack[-2];
    if (v0205 == nil) goto v0039;
    v0205 = stack[-2];
    v0205 = qcar(v0205);
    v0225 = v0205;
    v0205 = stack[-2];
    v0205 = qcdr(v0205);
    stack[-2] = v0205;
    v0205 = stack[-4];
    fn = elt(env, 10); // ibalp_readclause
    v0205 = (*qfn2(fn))(qenv(fn), v0225, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    stack[-6] = v0205;
    v0205 = stack[-6];
    v0205 = qcar(v0205);
    stack[-3] = v0205;
    v0205 = stack[-6];
    v0205 = qcdr(v0205);
    stack[-4] = v0205;
    v0225 = stack[-3];
    v0205 = elt(env, 4); // true
    if (v0225 == v0205) goto v0040;
    v0205 = stack[-3];
    fn = elt(env, 11); // ibalp_emptyclausep
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    if (v0205 == nil) goto v0046;
    v0205 = qvalue(elt(env, 3)); // nil
    stack[-1] = v0205;
    goto v0040;

v0046:
    v0225 = stack[-3];
    v0205 = stack[-5];
    fn = elt(env, 12); // ibalp_clmember
    v0205 = (*qfn2(fn))(qenv(fn), v0225, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    if (!(v0205 == nil)) goto v0044;
    v0205 = stack[-3];
    fn = elt(env, 13); // ibalp_redclause
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    if (!(v0205 == nil)) goto v0044;
    v0205 = stack[-6];
    v0225 = qcar(v0205);
    v0205 = stack[-5];
    v0205 = cons(v0225, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    stack[-5] = v0205;
    goto v0040;

v0044:
    v0205 = stack[-3];
    fn = elt(env, 14); // ibalp_undoclause
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    v0205 = stack[0];
    v0205 = add1(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    stack[0] = v0205;
    goto v0040;

v0039:
    v0205 = stack[-1];
    if (v0205 == nil) goto v0118;
    v0205 = stack[-5];
    if (v0205 == nil) goto v0220;
    v0205 = qvalue(elt(env, 5)); // !*rlverbose
    if (v0205 == nil) goto v0174;
    v0225 = elt(env, 8); // "Deleted redundant clauses: "
    v0205 = stack[0];
    v0205 = list2(v0225, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    fn = elt(env, 15); // ioto_tprin2t
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    goto v0174;

v0174:
    v0225 = stack[-5];
    v0205 = stack[-4];
    popv(8);
    return cons(v0225, v0205);

v0220:
    v0205 = qvalue(elt(env, 5)); // !*rlverbose
    if (v0205 == nil) goto v0177;
    v0205 = elt(env, 7); // "Tautology detected"
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    fn = elt(env, 15); // ioto_tprin2t
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    goto v0177;

v0177:
    v0205 = qvalue(elt(env, 3)); // nil
    popv(8);
    return ncons(v0205);

v0118:
    v0205 = qvalue(elt(env, 5)); // !*rlverbose
    if (v0205 == nil) goto v0226;
    v0205 = elt(env, 6); // "Detected empty clause"
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    fn = elt(env, 15); // ioto_tprin2t
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-7];
    goto v0226;

v0226:
    v0205 = stack[-3];
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    popv(8);
    return ncons(v0205);
// error exit handlers
v0135:
    popv(8);
    return nil;
}



// Code for poly!-minusp

static LispObject CC_polyKminusp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0048, v0017;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0048 = v0000;
// end of prologue

v0008:
    v0017 = v0048;
    if (v0017 == nil) goto v0183;
    v0017 = v0048;
    if (!consp(v0017)) goto v0051;
    v0017 = v0048;
    v0017 = qcar(v0017);
    v0017 = (consp(v0017) ? nil : lisp_true);
    goto v0015;

v0015:
    if (v0017 == nil) goto v0040;
        return Lminusp(nil, v0048);

v0040:
    v0048 = qcar(v0048);
    v0048 = qcdr(v0048);
    goto v0008;

v0051:
    v0017 = qvalue(elt(env, 2)); // t
    goto v0015;

v0183:
    v0048 = qvalue(elt(env, 1)); // nil
    return onevalue(v0048);
}



// Code for naryom

static LispObject CC_naryom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0098, v0114;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for naryom");
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
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    stack[0] = v0098;
    v0114 = stack[0];
    v0098 = elt(env, 1); // var
    if (!(v0114 == v0098)) goto v0107;
    v0098 = elt(env, 2); // variance
    stack[0] = v0098;
    goto v0107;

v0107:
    v0114 = stack[0];
    v0098 = qvalue(elt(env, 3)); // valid_om!*
    v0098 = Lassoc(nil, v0114, v0098);
    stack[-2] = v0098;
    v0098 = stack[-2];
    if (v0098 == nil) goto v0038;
    v0098 = stack[-2];
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    stack[-2] = v0098;
    goto v0038;

v0038:
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    if (v0098 == nil) goto v0093;
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    v0114 = qcar(v0098);
    v0098 = elt(env, 4); // multiset
    if (!(v0114 == v0098)) goto v0093;
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    stack[-2] = v0098;
    goto v0093;

v0093:
    v0098 = elt(env, 6); // "<OMA>"
    fn = elt(env, 12); // printout
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0114 = qvalue(elt(env, 7)); // indent
    v0098 = (LispObject)33; // 2
    v0098 = plus2(v0114, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    qvalue(elt(env, 7)) = v0098; // indent
    v0098 = elt(env, 8); // "<OMS cd="""
    fn = elt(env, 12); // printout
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0098 = stack[-2];
    v0098 = Lprinc(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0098 = elt(env, 9); // """ name="""
    v0098 = Lprinc(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0098 = stack[0];
    v0098 = Lprinc(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0098 = elt(env, 10); // """>"
    v0098 = Lprinc(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    v0098 = qcdr(v0098);
    fn = elt(env, 13); // multiom
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0114 = qvalue(elt(env, 7)); // indent
    v0098 = (LispObject)33; // 2
    v0098 = difference2(v0114, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    qvalue(elt(env, 7)) = v0098; // indent
    v0098 = elt(env, 11); // "</OMA>"
    fn = elt(env, 12); // printout
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    v0098 = nil;
    { popv(4); return onevalue(v0098); }
// error exit handlers
v0088:
    popv(4);
    return nil;
}



// Code for makeset

static LispObject CC_makeset(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0011, v0112, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makeset");
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
    v0012 = nil;
    goto v0007;

v0007:
    v0011 = stack[0];
    if (v0011 == nil) goto v0057;
    v0011 = stack[0];
    v0112 = qcar(v0011);
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    v0011 = Lmember(nil, v0112, v0011);
    if (v0011 == nil) goto v0009;
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    stack[0] = v0011;
    goto v0007;

v0009:
    v0011 = stack[0];
    v0011 = qcar(v0011);
    v0112 = v0012;
    v0011 = cons(v0011, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-1];
    v0012 = v0011;
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    stack[0] = v0011;
    goto v0007;

v0057:
    v0011 = v0012;
    {
        popv(2);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0011);
    }
// error exit handlers
v0028:
    popv(2);
    return nil;
}



// Code for groedeletip

static LispObject CC_groedeletip(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0035, v0043;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groedeletip");
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

v0057:
    v0035 = stack[0];
    if (v0035 == nil) goto v0183;
    v0043 = stack[-1];
    v0035 = stack[0];
    v0035 = qcar(v0035);
    if (!(equal(v0043, v0035))) goto v0183;
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    stack[0] = v0035;
    goto v0057;

v0183:
    v0035 = stack[0];
    if (v0035 == nil) goto v0038;
    v0035 = stack[0];
    stack[-2] = v0035;
    goto v0024;

v0024:
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    if (v0035 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0043 = stack[-1];
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    if (equal(v0043, v0035)) goto v0021;
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    stack[0] = v0035;
    goto v0024;

v0021:
    v0043 = stack[0];
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    fn = elt(env, 2); // setcdr
    v0035 = (*qfn2(fn))(qenv(fn), v0043, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    goto v0024;

v0038:
    v0035 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0035); }
// error exit handlers
v0003:
    popv(4);
    return nil;
}



// Code for physopordchk

static LispObject CC_physopordchk(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0060, v0021, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopordchk");
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
    v0060 = v0000;
// end of prologue
    fn = elt(env, 4); // !*collectphysops
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    fn = elt(env, 5); // deletemult!*
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    stack[-1] = v0060;
    v0060 = stack[0];
    fn = elt(env, 4); // !*collectphysops
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    fn = elt(env, 5); // deletemult!*
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    v0062 = v0060;
    v0060 = stack[-1];
    if (v0060 == nil) goto v0097;
    v0060 = v0062;
    if (v0060 == nil) goto v0113;
    v0021 = elt(env, 3); // unit
    v0060 = stack[-1];
    v0060 = Lmember(nil, v0021, v0060);
    if (!(v0060 == nil)) goto v0040;
    v0021 = elt(env, 3); // unit
    v0060 = v0062;
    v0060 = Lmember(nil, v0021, v0060);
    if (!(v0060 == nil)) goto v0040;
    v0060 = stack[-1];
    v0021 = v0062;
    {
        popv(3);
        fn = elt(env, 6); // physopordchk!*
        return (*qfn2(fn))(qenv(fn), v0060, v0021);
    }

v0040:
    v0060 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0060); }

v0113:
    v0060 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0060); }

v0097:
    v0060 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0060); }
// error exit handlers
v0006:
    popv(3);
    return nil;
}



// Code for set!-global!-mode

static LispObject CC_setKglobalKmode(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-global-mode");
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
    v0040 = qvalue(elt(env, 1)); // nil
    v0040 = ncons(v0040);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0040; // alglist!*
    v0040 = stack[-2];
    qvalue(elt(env, 3)) = v0040; // !*mode
    stack[-3] = elt(env, 4); // null
    stack[-1] = elt(env, 5); // setq
    stack[0] = elt(env, 3); // !*mode
    v0040 = stack[-2];
    v0040 = Lmkquote(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    v0040 = list3(stack[-1], stack[0], v0040);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    {
        LispObject v0017 = stack[-3];
        popv(5);
        return list2(v0017, v0040);
    }
// error exit handlers
v0048:
    popv(5);
    return nil;
}



// Code for scalprod

static LispObject CC_scalprod(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0122, v0003, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scalprod");
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
    v0122 = stack[-1];
    if (v0122 == nil) goto v0109;
    v0122 = qvalue(elt(env, 1)); // nil
    goto v0057;

v0057:
    if (v0122 == nil) goto v0047;
    v0003 = qvalue(elt(env, 1)); // nil
    v0122 = (LispObject)17; // 1
    popv(4);
    return cons(v0003, v0122);

v0047:
    v0122 = stack[-1];
    if (v0122 == nil) goto v0038;
    v0122 = stack[0];
    v0122 = (v0122 == nil ? lisp_true : nil);
    goto v0049;

v0049:
    if (v0122 == nil) goto v0060;
    v0046 = elt(env, 3); // matrix
    v0003 = (LispObject)145; // 9
    v0122 = elt(env, 4); // "Matrix mismatch"
    {
        popv(4);
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0046, v0003, v0122);
    }

v0060:
    v0122 = stack[-1];
    v0003 = qcar(v0122);
    v0122 = stack[0];
    v0122 = qcar(v0122);
    fn = elt(env, 6); // multsq
    stack[-2] = (*qfn2(fn))(qenv(fn), v0003, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0122 = stack[-1];
    v0003 = qcdr(v0122);
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    v0122 = CC_scalprod(env, v0003, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    {
        LispObject v0052 = stack[-2];
        popv(4);
        fn = elt(env, 7); // addsq
        return (*qfn2(fn))(qenv(fn), v0052, v0122);
    }

v0038:
    v0122 = qvalue(elt(env, 2)); // t
    goto v0049;

v0109:
    v0122 = stack[0];
    v0122 = (v0122 == nil ? lisp_true : nil);
    goto v0057;
// error exit handlers
v0014:
    popv(4);
    return nil;
}



// Code for mo_equal!?

static LispObject CC_mo_equalW(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0051;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_equal?");
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
    v0051 = v0000;
// end of prologue
    v0051 = qcar(v0051);
    fn = elt(env, 1); // mo!=shorten
    stack[-1] = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-2];
    v0051 = stack[0];
    v0051 = qcar(v0051);
    fn = elt(env, 1); // mo!=shorten
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    v0051 = (equal(stack[-1], v0051) ? lisp_true : nil);
    { popv(3); return onevalue(v0051); }
// error exit handlers
v0097:
    popv(3);
    return nil;
}



// Code for resimpf

static LispObject CC_resimpf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resimpf");
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
    v0015 = v0000;
// end of prologue
    v0042 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 2)); // varstack!*
    qvalue(elt(env, 2)) = v0042; // varstack!*
    v0042 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 3); // subf1
    v0042 = (*qfn2(fn))(qenv(fn), v0015, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    v0042 = qcar(v0042);
    qvalue(elt(env, 2)) = stack[0]; // varstack!*
    { popv(2); return onevalue(v0042); }
// error exit handlers
v0069:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // varstack!*
    popv(2);
    return nil;
}



// Code for general!-modular!-expt

static LispObject CC_generalKmodularKexpt(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0172, v0229, v0230;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-expt");
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

v0067:
    v0229 = stack[-1];
    v0172 = (LispObject)1; // 0
    if (v0229 == v0172) goto v0025;
    v0229 = stack[0];
    v0172 = (LispObject)1; // 0
    if (v0229 == v0172) goto v0012;
    v0229 = stack[0];
    v0172 = (LispObject)17; // 1
    if (v0229 == v0172) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[0];
    v0172 = qvalue(elt(env, 3)); // current!-modulus
    v0172 = sub1(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0172 = (LispObject)geq2(stack[-2], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    v0172 = v0172 ? lisp_true : nil;
    env = stack[-3];
    if (v0172 == nil) goto v0098;
    v0172 = qvalue(elt(env, 3)); // current!-modulus
    fn = elt(env, 5); // primep
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    if (v0172 == nil) goto v0098;
    v0172 = qvalue(elt(env, 3)); // current!-modulus
    v0172 = sub1(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0172 = Cremainder(stack[0], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[0] = v0172;
    goto v0067;

v0098:
    v0172 = stack[0];
    v0172 = Levenp(nil, v0172);
    env = stack[-3];
    if (v0172 == nil) goto v0115;
    v0229 = stack[0];
    v0172 = (LispObject)33; // 2
    v0172 = quot2(v0229, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[0] = v0172;
    v0229 = stack[-1];
    v0172 = stack[-1];
    fn = elt(env, 6); // general!-modular!-times
    v0172 = (*qfn2(fn))(qenv(fn), v0229, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[-1] = v0172;
    goto v0098;

v0115:
    v0172 = stack[0];
    fn = elt(env, 7); // reverse!-num
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[0] = v0172;
    v0172 = (LispObject)17; // 1
    stack[-2] = v0172;
    goto v0166;

v0166:
    v0229 = stack[0];
    v0172 = (LispObject)1; // 0
    v0172 = (LispObject)greaterp2(v0229, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    v0172 = v0172 ? lisp_true : nil;
    env = stack[-3];
    if (v0172 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0229 = stack[-2];
    v0172 = stack[-2];
    fn = elt(env, 6); // general!-modular!-times
    v0172 = (*qfn2(fn))(qenv(fn), v0229, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[-2] = v0172;
    v0172 = stack[0];
    v0172 = Levenp(nil, v0172);
    env = stack[-3];
    if (!(v0172 == nil)) goto v0232;
    v0229 = stack[-2];
    v0172 = stack[-1];
    fn = elt(env, 6); // general!-modular!-times
    v0172 = (*qfn2(fn))(qenv(fn), v0229, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[-2] = v0172;
    goto v0232;

v0232:
    v0229 = stack[0];
    v0172 = (LispObject)33; // 2
    v0172 = quot2(v0229, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[0] = v0172;
    goto v0166;

v0012:
    v0172 = (LispObject)17; // 1
    { popv(4); return onevalue(v0172); }

v0025:
    v0229 = stack[0];
    v0172 = (LispObject)1; // 0
    if (v0229 == v0172) goto v0038;
    v0172 = (LispObject)1; // 0
    { popv(4); return onevalue(v0172); }

v0038:
    v0230 = elt(env, 1); // alg
    v0229 = (LispObject)1617; // 101
    v0172 = elt(env, 2); // "0^0 formed"
    {
        popv(4);
        fn = elt(env, 8); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0230, v0229, v0172);
    }
// error exit handlers
v0231:
    popv(4);
    return nil;
}



// Code for gf2cr!:

static LispObject CC_gf2crT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0068;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gf2cr:");
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
    stack[-2] = elt(env, 1); // !:cr!:
    v0068 = stack[-1];
    v0068 = qcar(v0068);
    fn = elt(env, 2); // striptag
    stack[0] = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    fn = elt(env, 2); // striptag
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    {
        LispObject v0113 = stack[-2];
        LispObject v0026 = stack[0];
        popv(4);
        return list2star(v0113, v0026, v0068);
    }
// error exit handlers
v0025:
    popv(4);
    return nil;
}



setup_type const u18_setup[] =
{
    {"mo_lcm",                  too_few_2,      CC_mo_lcm,     wrong_no_2},
    {"b:ordexp",                too_few_2,      CC_bTordexp,   wrong_no_2},
    {"exptf",                   too_few_2,      CC_exptf,      wrong_no_2},
    {"exc",                     too_few_2,      CC_exc,        wrong_no_2},
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"cl_qb",                   CC_cl_qb,       too_many_1,    wrong_no_1},
    {"cl_atfp",                 CC_cl_atfp,     too_many_1,    wrong_no_1},
    {"reln",                    too_few_2,      CC_reln,       wrong_no_2},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {"aconc",                   too_few_2,      CC_aconc,      wrong_no_2},
    {"bytelist2id",             CC_bytelist2id, too_many_1,    wrong_no_1},
    {"fortexp",                 CC_fortexp,     too_many_1,    wrong_no_1},
    {"indordp",                 too_few_2,      CC_indordp,    wrong_no_2},
    {"collectphystype",         CC_collectphystype,too_many_1, wrong_no_1},
    {"symbvarlst",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbvarlst},
    {"fs:times",                too_few_2,      CC_fsTtimes,   wrong_no_2},
    {"tensorp",                 CC_tensorp,     too_many_1,    wrong_no_1},
    {"ad_numsort",              CC_ad_numsort,  too_many_1,    wrong_no_1},
    {"lambda_u9iz36vfudu4",     too_few_2,      CC_lambda_u9iz36vfudu4,wrong_no_2},
    {"qqe_eta-in-term",         CC_qqe_etaKinKterm,too_many_1, wrong_no_1},
    {"ibalp_negatet",           CC_ibalp_negatet,too_many_1,   wrong_no_1},
    {"sfto_dprpartksf",         CC_sfto_dprpartksf,too_many_1, wrong_no_1},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"diffsq",                  too_few_2,      CC_diffsq,     wrong_no_2},
    {"evdif",                   too_few_2,      CC_evdif,      wrong_no_2},
    {"arg2of2",                 too_few_2,      CC_arg2of2,    wrong_no_2},
    {"wedgek2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_wedgek2},
    {"one-entry-listp",         too_few_2,      CC_oneKentryKlistp,wrong_no_2},
    {"prepd1",                  CC_prepd1,      too_many_1,    wrong_no_1},
    {"simpexpt",                CC_simpexpt,    too_many_1,    wrong_no_1},
    {"pasf_smwcpknowl",         CC_pasf_smwcpknowl,too_many_1, wrong_no_1},
    {"ibalp_isinminclause",     too_few_2,      CC_ibalp_isinminclause,wrong_no_2},
    {"ofsf_subf",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_subf},
    {"ev_lexcomp",              too_few_2,      CC_ev_lexcomp, wrong_no_2},
    {"mchkopt1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchkopt1},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"mkfortterpri",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkfortterpri},
    {"trwrite",                 CC_trwrite,     too_many_1,    wrong_no_1},
    {"setelv",                  too_few_2,      CC_setelv,     wrong_no_2},
    {"moid_member",             too_few_2,      CC_moid_member,wrong_no_2},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {"ratn",                    CC_ratn,        too_many_1,    wrong_no_1},
    {"replus",                  CC_replus,      too_many_1,    wrong_no_1},
    {"ibalp_var-set",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_varKset},
    {"unaryrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_unaryrd},
    {"dm-minus",                CC_dmKminus,    too_many_1,    wrong_no_1},
    {"quoteequation",           CC_quoteequation,too_many_1,   wrong_no_1},
    {"evgradlexcomp",           too_few_2,      CC_evgradlexcomp,wrong_no_2},
    {"physopsm*",               CC_physopsmH,   too_many_1,    wrong_no_1},
    {"mktails1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails1},
    {"pairxvars",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pairxvars},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"red=cancelsimp",          too_few_2,      CC_redMcancelsimp,wrong_no_2},
    {"simp-prop-order",         too_few_2,      CC_simpKpropKorder,wrong_no_2},
    {"splitlist:",              too_few_2,      CC_splitlistT, wrong_no_2},
    {"innprodkp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_innprodkp},
    {"ibalp_readform",          CC_ibalp_readform,too_many_1,  wrong_no_1},
    {"poly-minusp",             CC_polyKminusp, too_many_1,    wrong_no_1},
    {"naryom",                  CC_naryom,      too_many_1,    wrong_no_1},
    {"makeset",                 CC_makeset,     too_many_1,    wrong_no_1},
    {"groedeletip",             too_few_2,      CC_groedeletip,wrong_no_2},
    {"physopordchk",            too_few_2,      CC_physopordchk,wrong_no_2},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"scalprod",                too_few_2,      CC_scalprod,   wrong_no_2},
    {"mo_equal?",               too_few_2,      CC_mo_equalW,  wrong_no_2},
    {"resimpf",                 CC_resimpf,     too_many_1,    wrong_no_1},
    {"general-modular-expt",    too_few_2,      CC_generalKmodularKexpt,wrong_no_2},
    {"gf2cr:",                  CC_gf2crT,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u18", (two_args *)"16528 3935697 1268409", 0}
};

// end of generated code
