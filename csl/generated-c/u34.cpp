
// $destdir\u34.c        Machine generated C code

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
#define CSL_IGNORE(x) (x = x)
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
#ifdef NILSEG_EXTERNS
#define nil_as_base
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
#else 
#define nil_as_base LispObject nil = C_nil;
#define byteflip BASE[12]
#define codefringe BASE[13]
#define codelimit (*(LispObject volatile *)&BASE[14])
extern LispObject * volatile stacklimit;
#define fringe BASE[18]
#define heaplimit (*(LispObject volatile *)&BASE[19])
#define vheaplimit (*(LispObject volatile *)&BASE[20])
#define vfringe BASE[21]
#define miscflags BASE[22]
#define nwork BASE[24]
#define exit_count BASE[26]
#define gensym_ser BASE[27]
#define print_precision BASE[28]
#define current_modulus BASE[29]
#define fastget_size BASE[30]
#define package_bits BASE[31]
#define modulus_is_large BASE[32]
#define current_package BASE[52]
#define B_reg BASE[53]
#define codevec BASE[54]
#define litvec BASE[55]
#define exit_tag BASE[56]
#define exit_value BASE[57]
#define catch_tags BASE[58]
#define lisp_package BASE[59]
#define boffo BASE[60]
#define charvec BASE[61]
#define sys_hash_table BASE[62]
#define help_index BASE[63]
#define gensym_base BASE[64]
#define err_table BASE[65]
#define supervisor BASE[66]
#define startfn BASE[67]
#define faslvec BASE[68]
#define tracedfn BASE[69]
#define prompt_thing BASE[70]
#define faslgensyms BASE[71]
#define cl_symbols BASE[72]
#define active_stream BASE[73]
#define current_module BASE[74]
#define native_defs BASE[75]
#define append_symbol BASE[90]
#define applyhook BASE[91]
#define cfunarg BASE[92]
#define comma_at_symbol BASE[93]
#define comma_symbol BASE[94]
#define compiler_symbol BASE[95]
#define comp_symbol BASE[96]
#define cons_symbol BASE[97]
#define echo_symbol BASE[98]
#define emsg_star BASE[99]
#define evalhook BASE[100]
#define eval_symbol BASE[101]
#define expr_symbol BASE[102]
#define features_symbol BASE[103]
#define fexpr_symbol BASE[104]
#define funarg BASE[105]
#define function_symbol BASE[106]
#define lambda BASE[107]
#define lisp_true BASE[108]
#define lower_symbol BASE[109]
#define macroexpand_hook BASE[110]
#define macro_symbol BASE[111]
#define opt_key BASE[112]
#define prinl_symbol BASE[113]
#define progn_symbol BASE[114]
#define quote_symbol BASE[115]
#define raise_symbol BASE[116]
#define redef_msg BASE[117]
#define rest_key BASE[118]
#define savedef BASE[119]
#define string_char_sym BASE[120]
#define unset_var BASE[121]
#define work_symbol BASE[122]
#define lex_words BASE[123]
#define get_counts BASE[124]
#define fastget_names BASE[125]
#define input_libraries BASE[126]
#define output_library BASE[127]
#define current_file BASE[128]
#define break_function BASE[129]
#define lisp_work_stream BASE[130]
#define lisp_standard_output BASE[131]
#define lisp_standard_input BASE[132]
#define lisp_debug_io BASE[133]
#define lisp_error_output BASE[134]
#define lisp_query_io BASE[135]
#define lisp_terminal_io BASE[136]
#define lisp_trace_output BASE[137]
#define standard_output BASE[138]
#define standard_input BASE[139]
#define debug_io BASE[140]
#define error_output BASE[141]
#define query_io BASE[142]
#define terminal_io BASE[143]
#define trace_output BASE[144]
#define fasl_stream BASE[145]
#define native_code BASE[146]
#define native_symbol BASE[147]
#define traceprint_symbol BASE[148]
#define loadsource_symbol BASE[149]
#define hankaku_symbol BASE[150]
#define bytecoded_symbol BASE[151]
#define nativecoded_symbol BASE[152]
#define gchook BASE[153]
#define resources BASE[154]
#define callstack BASE[155]
#define procstack BASE[156]
#define procmem BASE[157]
#define trap_time BASE[158]
#define count_high BASE[159]
#ifdef COMMON
#define keyword_package BASE[170]
#define all_packages BASE[171]
#define package_symbol BASE[172]
#define internal_symbol BASE[173]
#define external_symbol BASE[174]
#define inherited_symbol BASE[175]
#define key_key BASE[176]
#define allow_other_keys BASE[177]
#define aux_key BASE[178]
#define format_symbol BASE[179]
#define expand_def_symbol BASE[180]
#define allow_key_key BASE[181]
#endif
#define declare_symbol BASE[182]
#define special_symbol BASE[183]
#define large_modulus BASE[184]
#define used_space BASE[185]
#define avail_space BASE[186]
#define eof_symbol BASE[187]
#define call_stack BASE[188]
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 BASE[200]
#define work_1 BASE[201]
#define mv_1 work_1
#define mv_2 BASE[202]
#define mv_3 BASE[203]
#define work_50 BASE[250]
#endif 
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
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b) ((r) = Idiv10_9(&(q), (a), (b)))
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



// Code for list2vect!*

static LispObject CC_list2vectH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0015, v0016;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list2vect*");
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
    v0015 = stack[-4];
    v0015 = Llength(nil, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    v0015 = sub1(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    v0015 = Lmkvect(nil, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    stack[-5] = v0015;
    v0015 = (LispObject)17; // 1
    stack[-2] = v0015;
    goto v0018;

v0018:
    v0015 = stack[-5];
    v0015 = Lupbv(nil, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    v0016 = add1(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    v0015 = stack[-2];
    v0015 = difference2(v0016, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    v0015 = Lminusp(nil, v0015);
    env = stack[-6];
    if (!(v0015 == nil)) { LispObject res = stack[-5]; popv(7); return onevalue(res); }
    stack[-1] = stack[-5];
    v0015 = stack[-2];
    stack[0] = sub1(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    v0016 = stack[-3];
    v0015 = elt(env, 2); // algebraic
    if (v0016 == v0015) goto v0019;
    v0016 = stack[-4];
    v0015 = stack[-2];
    fn = elt(env, 3); // nth
    v0015 = (*qfn2(fn))(qenv(fn), v0016, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    goto v0020;

v0020:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0015;
    v0015 = stack[-2];
    v0015 = add1(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    stack[-2] = v0015;
    goto v0018;

v0019:
    v0016 = stack[-4];
    v0015 = stack[-2];
    fn = elt(env, 3); // nth
    v0015 = (*qfn2(fn))(qenv(fn), v0016, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    fn = elt(env, 4); // symb_to_alg
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-6];
    goto v0020;
// error exit handlers
v0017:
    popv(7);
    return nil;
}



// Code for noncomfree

static LispObject CC_noncomfree(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomfree");
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

v0022:
    v0021 = stack[0];
    if (symbolp(v0021)) goto v0023;
    v0021 = stack[0];
    if (!consp(v0021)) goto v0024;
    v0021 = stack[0];
    v0021 = qcar(v0021);
    v0021 = CC_noncomfree(env, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    if (v0021 == nil) goto v0026;
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    stack[0] = v0021;
    goto v0022;

v0026:
    v0021 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0021); }

v0024:
    v0021 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0021); }

v0023:
    v0021 = stack[0];
    if (!symbolp(v0021)) v0021 = nil;
    else { v0021 = qfastgets(v0021);
           if (v0021 != nil) { v0021 = elt(v0021, 0); // noncom
#ifdef RECORD_GET
             if (v0021 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0021 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0021 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0021 == SPID_NOPROP) v0021 = nil; else v0021 = lisp_true; }}
#endif
    v0021 = (v0021 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0021); }
// error exit handlers
v0025:
    popv(2);
    return nil;
}



// Code for extadd

static LispObject CC_extadd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0045, v0046;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extadd");
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
    v0045 = stack[-3];
    if (v0045 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0045 = stack[-2];
    if (v0045 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0045 = qvalue(elt(env, 1)); // nil
    v0045 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    stack[-1] = v0045;
    stack[-4] = v0045;
    goto v0048;

v0048:
    v0045 = stack[-3];
    if (v0045 == nil) goto v0049;
    v0045 = stack[-2];
    if (v0045 == nil) goto v0049;
    v0045 = stack[-2];
    v0045 = qcar(v0045);
    v0046 = qcar(v0045);
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    if (equal(v0046, v0045)) goto v0019;
    v0045 = stack[-2];
    v0045 = qcar(v0045);
    v0046 = qcar(v0045);
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    fn = elt(env, 2); // ordexp
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    if (v0045 == nil) goto v0050;
    stack[0] = stack[-1];
    v0045 = stack[-2];
    v0045 = qcar(v0045);
    v0045 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    fn = elt(env, 3); // setcdr
    v0045 = (*qfn2(fn))(qenv(fn), stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    stack[-2] = v0045;
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    goto v0048;

v0050:
    stack[0] = stack[-1];
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    fn = elt(env, 3); // setcdr
    v0045 = (*qfn2(fn))(qenv(fn), stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0045 = stack[-3];
    v0045 = qcdr(v0045);
    stack[-3] = v0045;
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    goto v0048;

v0019:
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0046 = qcdr(v0045);
    v0045 = stack[-2];
    v0045 = qcar(v0045);
    v0045 = qcdr(v0045);
    fn = elt(env, 4); // addf
    v0046 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0045 = v0046;
    if (v0046 == nil) goto v0011;
    stack[0] = stack[-1];
    v0046 = stack[-3];
    v0046 = qcar(v0046);
    v0046 = qcar(v0046);
    v0045 = cons(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0045 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    fn = elt(env, 3); // setcdr
    v0045 = (*qfn2(fn))(qenv(fn), stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    goto v0011;

v0011:
    v0045 = stack[-3];
    v0045 = qcdr(v0045);
    stack[-3] = v0045;
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    stack[-2] = v0045;
    goto v0048;

v0049:
    v0046 = stack[-1];
    v0045 = stack[-3];
    if (v0045 == nil) goto v0051;
    v0045 = stack[-3];
    goto v0052;

v0052:
    fn = elt(env, 3); // setcdr
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    v0045 = stack[-4];
    v0045 = qcdr(v0045);
    { popv(6); return onevalue(v0045); }

v0051:
    v0045 = stack[-2];
    goto v0052;
// error exit handlers
v0047:
    popv(6);
    return nil;
}



// Code for isimp1

static LispObject CC_isimp1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0076, v0077, v0078, v0079, v0080;
    LispObject fn;
    LispObject v0023, v0012, v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "isimp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0012 = va_arg(aa, LispObject);
    v0023 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isimp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0023,v0012,v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0058,v0012,v0023);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[0] = v0023;
    stack[-1] = v0012;
    stack[-2] = v0058;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    v0076 = stack[-4];
    if (v0076 == nil) goto v0081;
    v0076 = stack[-4];
    if (!consp(v0076)) goto v0040;
    v0076 = stack[-4];
    v0076 = qcar(v0076);
    v0076 = (consp(v0076) ? nil : lisp_true);
    goto v0029;

v0029:
    if (v0076 == nil) goto v0082;
    v0076 = stack[0];
    if (v0076 == nil) goto v0083;
    v0076 = stack[0];
    v0080 = qcar(v0076);
    v0079 = stack[-3];
    v0078 = stack[-2];
    v0077 = stack[-1];
    v0076 = stack[0];
    v0076 = qcdr(v0076);
    fn = elt(env, 5); // spur0
    v0076 = (*qfnn(fn))(qenv(fn), 5, v0080, v0079, v0078, v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-6];
    {
        LispObject v0085 = stack[-4];
        popv(7);
        fn = elt(env, 6); // multd
        return (*qfn2(fn))(qenv(fn), v0085, v0076);
    }

v0083:
    v0076 = stack[-2];
    if (v0076 == nil) goto v0086;
    stack[-3] = elt(env, 3); // hephys
    stack[-1] = (LispObject)97; // 6
    stack[0] = elt(env, 4); // "Unmatched index"
    v0076 = stack[-2];
    fn = elt(env, 7); // mapovercar
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-6];
    v0076 = cons(stack[0], v0076);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-6];
    {
        LispObject v0087 = stack[-3];
        LispObject v0088 = stack[-1];
        popv(7);
        fn = elt(env, 8); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0087, v0088, v0076);
    }

v0086:
    v0076 = stack[-1];
    if (v0076 == nil) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    v0076 = stack[-1];
    fn = elt(env, 9); // emult
    stack[-1] = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-6];
    v0080 = stack[-4];
    v0079 = stack[-3];
    v0078 = stack[-2];
    v0077 = qvalue(elt(env, 1)); // nil
    v0076 = stack[0];
    v0076 = CC_isimp1(env, 5, v0080, v0079, v0078, v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-6];
    {
        LispObject v0089 = stack[-1];
        popv(7);
        fn = elt(env, 10); // multf
        return (*qfn2(fn))(qenv(fn), v0089, v0076);
    }

v0082:
    v0076 = stack[-4];
    v0080 = qcar(v0076);
    v0079 = stack[-3];
    v0078 = stack[-2];
    v0077 = stack[-1];
    v0076 = stack[0];
    fn = elt(env, 11); // isimp2
    stack[-5] = (*qfnn(fn))(qenv(fn), 5, v0080, v0079, v0078, v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-6];
    v0076 = stack[-4];
    v0080 = qcdr(v0076);
    v0079 = stack[-3];
    v0078 = stack[-2];
    v0077 = stack[-1];
    v0076 = stack[0];
    v0076 = CC_isimp1(env, 5, v0080, v0079, v0078, v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-6];
    {
        LispObject v0090 = stack[-5];
        popv(7);
        fn = elt(env, 12); // addf
        return (*qfn2(fn))(qenv(fn), v0090, v0076);
    }

v0040:
    v0076 = qvalue(elt(env, 2)); // t
    goto v0029;

v0081:
    v0076 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0076); }
// error exit handlers
v0084:
    popv(7);
    return nil;
}



// Code for iv_cutcongs2

static LispObject CC_iv_cutcongs2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for iv_cutcongs2");
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
    v0037 = v0000;
// end of prologue
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0007 = qcar(v0006);
    v0006 = elt(env, 1); // cong
    if (v0007 == v0006) goto v0083;
    v0006 = stack[0];
    v0006 = qcdr(v0006);
    v0007 = v0037;
    v0007 = difference2(v0006, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-1];
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = qcdr(v0006);
    v0007 = Cremainder(v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0006 = (LispObject)1; // 0
    v0006 = (v0007 == v0006 ? lisp_true : nil);
    v0006 = (v0006 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0006); }

v0083:
    v0006 = stack[0];
    v0006 = qcdr(v0006);
    v0007 = v0037;
    v0007 = difference2(v0006, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-1];
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = qcdr(v0006);
    v0007 = Cremainder(v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0006 = (LispObject)1; // 0
    v0006 = (v0007 == v0006 ? lisp_true : nil);
    { popv(2); return onevalue(v0006); }
// error exit handlers
v0096:
    popv(2);
    return nil;
}



// Code for vunion

static LispObject CC_vunion(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0067, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vunion");
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
    v0067 = stack[-2];
    if (v0067 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0067 = stack[-2];
    v0067 = qcar(v0067);
    v0065 = qcar(v0067);
    v0067 = stack[-1];
    v0067 = Lassoc(nil, v0065, v0067);
    stack[-3] = v0067;
    if (v0067 == nil) goto v0104;
    v0067 = stack[-2];
    v0067 = qcar(v0067);
    v0065 = qcdr(v0067);
    v0067 = stack[-3];
    v0067 = qcdr(v0067);
    v0067 = (LispObject)greaterp2(v0065, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    v0067 = v0067 ? lisp_true : nil;
    env = stack[-4];
    if (v0067 == nil) goto v0039;
    v0067 = stack[-2];
    stack[0] = qcar(v0067);
    v0067 = stack[-2];
    stack[-2] = qcdr(v0067);
    v0065 = stack[-3];
    v0067 = stack[-1];
    v0067 = Ldelete(nil, v0065, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0067 = CC_vunion(env, stack[-2], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    {
        LispObject v0034 = stack[0];
        popv(5);
        return cons(v0034, v0067);
    }

v0039:
    stack[0] = stack[-3];
    v0067 = stack[-2];
    stack[-2] = qcdr(v0067);
    v0065 = stack[-3];
    v0067 = stack[-1];
    v0067 = Ldelete(nil, v0065, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0067 = CC_vunion(env, stack[-2], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    {
        LispObject v0105 = stack[0];
        popv(5);
        return cons(v0105, v0067);
    }

v0104:
    v0067 = stack[-2];
    stack[0] = qcar(v0067);
    v0067 = stack[-2];
    v0065 = qcdr(v0067);
    v0067 = stack[-1];
    v0067 = CC_vunion(env, v0065, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    {
        LispObject v0106 = stack[0];
        popv(5);
        return cons(v0106, v0067);
    }
// error exit handlers
v0033:
    popv(5);
    return nil;
}



// Code for ofsf_smwupdknowl

static LispObject CC_ofsf_smwupdknowl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0103, v0004, v0109, v0110, v0111;
    LispObject fn;
    LispObject v0012, v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0012 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smwupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0004 = v0012;
    v0109 = v0058;
    v0110 = v0001;
    v0111 = v0000;
// end of prologue
    v0103 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0103 == nil) goto v0094;
    v0103 = v0111;
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(qenv(fn), 4, v0103, v0110, v0109, v0004);
    }

v0094:
    v0103 = v0111;
    {
        fn = elt(env, 3); // ofsf_smupdknowl
        return (*qfnn(fn))(qenv(fn), 4, v0103, v0110, v0109, v0004);
    }
}



// Code for prsubsetrd

static LispObject CC_prsubsetrd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0098, v0099;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prsubsetrd");
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
    v0098 = qvalue(elt(env, 1)); // t
    stack[-1] = v0098;
    goto v0029;

v0029:
    v0098 = stack[-3];
    v0099 = Llength(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    v0098 = (LispObject)17; // 1
    v0098 = (LispObject)greaterp2(v0099, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    v0098 = v0098 ? lisp_true : nil;
    env = stack[-4];
    if (v0098 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0098 = stack[-3];
    stack[0] = qcar(v0098);
    v0098 = stack[-3];
    v0098 = qcar(v0098);
    fn = elt(env, 4); // reval
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    if (equal(stack[0], v0098)) goto v0114;
    v0098 = stack[-3];
    v0098 = qcdr(v0098);
    stack[0] = qcar(v0098);
    v0098 = stack[-3];
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    fn = elt(env, 4); // reval
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    v0098 = (equal(stack[0], v0098) ? lisp_true : nil);
    goto v0014;

v0014:
    if (v0098 == nil) goto v0070;
    v0098 = nil;
    stack[-3] = v0098;
    stack[0] = elt(env, 3); // prsubset
    v0098 = stack[-2];
    fn = elt(env, 5); // eval_list_sets
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    v0098 = cons(stack[0], v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    stack[-1] = v0098;
    goto v0029;

v0070:
    v0098 = stack[-1];
    if (v0098 == nil) goto v0038;
    v0098 = stack[-3];
    v0098 = qcar(v0098);
    fn = elt(env, 4); // reval
    stack[0] = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    v0098 = stack[-3];
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    fn = elt(env, 4); // reval
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    fn = elt(env, 6); // alg_prsubset
    v0098 = (*qfn2(fn))(qenv(fn), stack[0], v0098);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    goto v0037;

v0037:
    stack[-1] = v0098;
    v0098 = stack[-3];
    v0098 = qcdr(v0098);
    stack[-3] = v0098;
    goto v0029;

v0038:
    v0098 = qvalue(elt(env, 2)); // nil
    goto v0037;

v0114:
    v0098 = qvalue(elt(env, 1)); // t
    goto v0014;
// error exit handlers
v0113:
    popv(5);
    return nil;
}



// Code for !*!*s2a

static LispObject CC_HHs2a(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject v0023, v0115;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for **s2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0023 = v0001;
    v0115 = v0000;
// end of prologue
    return onevalue(v0115);
}



// Code for insertocc

static LispObject CC_insertocc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0075, v0073, v0019;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insertocc");
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
    v0019 = v0001;
    stack[-1] = v0000;
// end of prologue
    v0073 = v0019;
    v0075 = stack[-1];
    v0075 = Lassoc(nil, v0073, v0075);
    stack[-2] = v0075;
    if (v0075 == nil) goto v0110;
    stack[0] = v0019;
    v0075 = stack[-2];
    v0075 = qcdr(v0075);
    v0075 = add1(v0075);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0019 = cons(stack[0], v0075);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0073 = stack[-2];
    v0075 = stack[-1];
    v0075 = Lsubst(nil, 3, v0019, v0073, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    stack[-1] = v0075;
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0110:
    v0073 = (LispObject)17; // 1
    v0075 = stack[-1];
    v0075 = acons(v0019, v0073, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    stack[-1] = v0075;
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }
// error exit handlers
v0117:
    popv(4);
    return nil;
}



// Code for xreadlist

static LispObject CC_xreadlist(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0122, v0123;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "xreadlist");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xreadlist");
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
    push4(nil, nil, nil, nil);
// end of prologue
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    fn = elt(env, 10); // scan
    v0123 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0122 = elt(env, 1); // !*rcbkt!*
    if (!(v0123 == v0122)) goto v0125;
    fn = elt(env, 10); // scan
    v0122 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0122 = elt(env, 2); // list
    popv(5);
    return ncons(v0122);

v0125:
    v0122 = stack[-1];
    if (v0122 == nil) goto v0083;
    v0122 = elt(env, 3); // group
    fn = elt(env, 11); // xread1
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0122 = ncons(v0122);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    fn = elt(env, 12); // nconc2
    v0122 = (*qfn2(fn))(qenv(fn), stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[0] = v0122;
    goto v0108;

v0108:
    v0122 = qvalue(elt(env, 4)); // cursym!*
    stack[-3] = v0122;
    v0123 = stack[-3];
    v0122 = elt(env, 5); // !*semicol!*
    if (v0123 == v0122) goto v0041;
    fn = elt(env, 10); // scan
    v0123 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0122 = elt(env, 1); // !*rcbkt!*
    if (v0123 == v0122) goto v0039;
    v0122 = qvalue(elt(env, 7)); // nil
    goto v0037;

v0037:
    if (v0122 == nil) goto v0065;
    v0123 = elt(env, 9); // "Syntax error: invalid comma in list"
    v0122 = qvalue(elt(env, 7)); // nil
    fn = elt(env, 13); // symerr
    v0122 = (*qfn2(fn))(qenv(fn), v0123, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    goto v0065;

v0065:
    v0123 = stack[-3];
    v0122 = elt(env, 1); // !*rcbkt!*
    if (v0123 == v0122) goto v0106;
    v0122 = stack[-2];
    if (!(v0122 == nil)) goto v0125;
    v0122 = stack[-3];
    stack[-2] = v0122;
    goto v0125;

v0106:
    v0123 = elt(env, 2); // list
    v0122 = stack[-1];
    popv(5);
    return cons(v0123, v0122);

v0039:
    v0123 = stack[-3];
    v0122 = elt(env, 8); // !*comma!*
    v0122 = (v0123 == v0122 ? lisp_true : nil);
    goto v0037;

v0041:
    v0123 = elt(env, 6); // "Syntax error: semicolon in list"
    v0122 = qvalue(elt(env, 7)); // nil
    fn = elt(env, 13); // symerr
    v0122 = (*qfn2(fn))(qenv(fn), v0123, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    goto v0065;

v0083:
    stack[0] = stack[-1];
    v0122 = elt(env, 3); // group
    fn = elt(env, 11); // xread1
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    fn = elt(env, 14); // aconc
    v0122 = (*qfn2(fn))(qenv(fn), stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[0] = v0122;
    stack[-1] = v0122;
    goto v0108;
// error exit handlers
v0124:
    popv(5);
    return nil;
}



// Code for numprintlen

static LispObject CC_numprintlen(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0133, v0134;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numprintlen");
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
    stack[-1] = v0000;
// end of prologue

v0023:
    v0133 = stack[-1];
    if (!consp(v0133)) goto v0125;
    v0133 = stack[-1];
    v0133 = Llength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = Lonep(nil, v0133);
    env = stack[-6];
    if (v0133 == nil) goto v0026;
    v0133 = stack[-1];
    v0133 = qcar(v0133);
    stack[-1] = v0133;
    goto v0023;

v0026:
    v0133 = stack[-1];
    v0134 = qcar(v0133);
    v0133 = elt(env, 1); // !:rd!:
    if (v0134 == v0133) goto v0107;
    v0133 = stack[-1];
    v0134 = qcar(v0133);
    v0133 = elt(env, 2); // (!:cr!: !:crn!: !:gi!:)
    v0133 = Lmemq(nil, v0134, v0133);
    if (v0133 == nil) goto v0136;
    v0134 = elt(env, 1); // !:rd!:
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    v0133 = cons(v0134, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    fn = elt(env, 5); // rd!:explode
    stack[0] = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0134 = elt(env, 1); // !:rd!:
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0133 = qcdr(v0133);
    v0133 = cons(v0134, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    fn = elt(env, 5); // rd!:explode
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = cons(stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    stack[-1] = v0133;
    stack[-4] = (LispObject)193; // 12
    v0133 = stack[-1];
    v0133 = qcar(v0133);
    v0133 = qcar(v0133);
    stack[-3] = Llength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = stack[-1];
    v0133 = qcar(v0133);
    v0133 = qcdr(v0133);
    v0133 = Lexplode(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    stack[-2] = Llength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    stack[0] = Llength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0133 = qcdr(v0133);
    v0133 = Lexplode(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = Llength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = plus2(stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = plus2(stack[-2], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = plus2(stack[-3], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    {
        LispObject v0137 = stack[-4];
        popv(7);
        return plus2(v0137, v0133);
    }

v0136:
    v0133 = stack[-1];
    stack[-5] = Llength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    stack[-4] = elt(env, 3); // plus
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    stack[-3] = v0133;
    v0133 = stack[-3];
    if (v0133 == nil) goto v0138;
    v0133 = stack[-3];
    v0133 = qcar(v0133);
    v0133 = CC_numprintlen(env, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = ncons(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    stack[-1] = v0133;
    stack[-2] = v0133;
    goto v0047;

v0047:
    v0133 = stack[-3];
    v0133 = qcdr(v0133);
    stack[-3] = v0133;
    v0133 = stack[-3];
    if (v0133 == nil) goto v0139;
    stack[0] = stack[-1];
    v0133 = stack[-3];
    v0133 = qcar(v0133);
    v0133 = CC_numprintlen(env, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = ncons(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = Lrplacd(nil, stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    stack[-1] = v0133;
    goto v0047;

v0139:
    v0133 = stack[-2];
    goto v0055;

v0055:
    v0133 = cons(stack[-4], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    fn = elt(env, 6); // lispeval
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    {
        LispObject v0140 = stack[-5];
        popv(7);
        return plus2(v0140, v0133);
    }

v0138:
    v0133 = qvalue(elt(env, 4)); // nil
    goto v0055;

v0107:
    v0133 = stack[-1];
    fn = elt(env, 5); // rd!:explode
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    stack[-1] = v0133;
    stack[-2] = (LispObject)33; // 2
    v0133 = stack[-1];
    v0133 = qcar(v0133);
    stack[0] = Llength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    v0133 = Lexplode(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = Llength(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-6];
    v0133 = plus2(stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    {
        LispObject v0141 = stack[-2];
        popv(7);
        return plus2(v0141, v0133);
    }

v0125:
    v0133 = stack[-1];
    v0133 = Lexplode(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0135;
        popv(7);
        return Llength(nil, v0133);
// error exit handlers
v0135:
    popv(7);
    return nil;
}



// Code for mk_binding

static LispObject CC_mk_binding(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0083, v0014;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_binding");
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
    v0083 = stack[-1];
    v0014 = qcar(v0083);
    v0083 = stack[0];
    fn = elt(env, 2); // can_be_proved
    v0083 = (*qfn2(fn))(qenv(fn), v0014, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    if (v0083 == nil) goto v0115;
    v0083 = stack[-1];
    v0014 = qcdr(v0083);
    v0083 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // edge_bind
        return (*qfn2(fn))(qenv(fn), v0014, v0083);
    }

v0115:
    v0083 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0083); }
// error exit handlers
v0101:
    popv(3);
    return nil;
}



// Code for splitup

static LispObject CC_splitup(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0016, v0071, v0100;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for splitup");
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
    v0100 = v0001;
    stack[0] = v0000;
// end of prologue
    v0016 = stack[0];
    if (v0016 == nil) goto v0144;
    v0016 = stack[0];
    v0016 = qcar(v0016);
    v0016 = qcar(v0016);
    v0016 = qcar(v0016);
    v0071 = v0016;
    v0016 = v0071;
    if (v0016 == nil) goto v0104;
    v0016 = v0100;
    v0016 = Lmemq(nil, v0071, v0016);
    goto v0048;

v0048:
    if (v0016 == nil) goto v0011;
    v0071 = qvalue(elt(env, 1)); // nil
    v0016 = stack[0];
    popv(3);
    return list2(v0071, v0016);

v0011:
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    v0071 = v0100;
    v0016 = CC_splitup(env, v0016, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0071 = v0016;
    v0016 = stack[0];
    stack[-1] = qcar(v0016);
    v0016 = v0071;
    stack[0] = qcar(v0016);
    v0016 = v0071;
    v0016 = qcdr(v0016);
    v0016 = qcar(v0016);
    v0016 = ncons(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    {
        LispObject v0039 = stack[-1];
        LispObject v0017 = stack[0];
        popv(3);
        return acons(v0039, v0017, v0016);
    }

v0104:
    v0016 = qvalue(elt(env, 2)); // t
    goto v0048;

v0144:
    v0016 = qvalue(elt(env, 1)); // nil
    v0071 = qvalue(elt(env, 1)); // nil
    popv(3);
    return list2(v0016, v0071);
// error exit handlers
v0120:
    popv(3);
    return nil;
}



// Code for nonmult

static LispObject CC_nonmult(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0018, v0026;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nonmult");
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
    v0018 = qvalue(elt(env, 1)); // vjets!*
    v0026 = Lreverse(nil, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    v0018 = stack[0];
    fn = elt(env, 2); // nth
    stack[0] = (*qfn2(fn))(qenv(fn), v0026, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    v0018 = qvalue(elt(env, 1)); // vjets!*
    v0018 = Lreverse(nil, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    v0018 = Lmember(nil, stack[0], v0018);
    v0018 = qcdr(v0018);
        popv(2);
        return Lreverse(nil, v0018);
// error exit handlers
v0048:
    popv(2);
    return nil;
}



// Code for min2!-order

static LispObject CC_min2Korder(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0112, v0147;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "min2-order");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for min2-order");
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
    stack[-4] = nil;
    goto v0125;

v0125:
    v0112 = stack[-3];
    if (v0112 == nil) goto v0002;
    v0112 = stack[-1];
    v0112 = qcar(v0112);
    stack[0] = v0112;
    v0112 = (LispObject)1; // 0
    v0147 = v0112;
    goto v0094;

v0094:
    v0112 = stack[0];
    if (v0112 == nil) goto v0021;
    v0112 = stack[0];
    v0112 = qcar(v0112);
    fn = elt(env, 1); // tayexp!-plus2
    v0112 = (*qfn2(fn))(qenv(fn), v0112, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-5];
    v0147 = v0112;
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    stack[0] = v0112;
    goto v0094;

v0021:
    v0112 = v0147;
    stack[0] = v0112;
    v0147 = stack[0];
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    fn = elt(env, 2); // tayexp!-greaterp
    v0112 = (*qfn2(fn))(qenv(fn), v0147, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-5];
    if (v0112 == nil) goto v0096;
    v0147 = stack[0];
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    fn = elt(env, 3); // tayexp!-min2
    v0112 = (*qfn2(fn))(qenv(fn), v0147, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-5];
    v0147 = v0112;
    goto v0107;

v0107:
    v0112 = stack[-4];
    v0112 = cons(v0147, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-5];
    stack[-4] = v0112;
    v0112 = stack[-3];
    v0112 = qcdr(v0112);
    stack[-3] = v0112;
    v0112 = stack[-2];
    v0112 = qcdr(v0112);
    stack[-2] = v0112;
    v0112 = stack[-1];
    v0112 = qcdr(v0112);
    stack[-1] = v0112;
    goto v0125;

v0096:
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    v0147 = v0112;
    goto v0107;

v0002:
    v0112 = stack[-4];
    {
        popv(6);
        fn = elt(env, 4); // nreverse
        return (*qfn1(fn))(qenv(fn), v0112);
    }
// error exit handlers
v0132:
    popv(6);
    return nil;
}



// Code for rl_sacatlp

static LispObject CC_rl_sacatlp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0121, v0148;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_sacatlp");
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
    v0121 = v0001;
    v0148 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_sacatlp!*
    v0121 = list2(v0148, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    {
        LispObject v0026 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0026, v0121);
    }
// error exit handlers
v0018:
    popv(2);
    return nil;
}



// Code for fctrf

static LispObject CC_fctrf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0165, v0166, v0167;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fctrf");
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
    stack[-5] = v0000;
// end of prologue
    v0166 = qvalue(elt(env, 1)); // !*exp
    v0165 = qvalue(elt(env, 2)); // ncmp!*
    stack[-6] = qvalue(elt(env, 1)); // !*exp
    qvalue(elt(env, 1)) = v0166; // !*exp
    stack[-4] = qvalue(elt(env, 2)); // ncmp!*
    qvalue(elt(env, 2)) = v0165; // ncmp!*
    stack[-3] = qvalue(elt(env, 3)); // !*ezgcd
    qvalue(elt(env, 3)) = nil; // !*ezgcd
    stack[-2] = qvalue(elt(env, 4)); // !*gcd
    qvalue(elt(env, 4)) = nil; // !*gcd
    stack[-1] = nil;
    v0165 = stack[-5];
    if (!consp(v0165)) goto v0148;
    v0165 = stack[-5];
    v0165 = qcar(v0165);
    v0165 = (consp(v0165) ? nil : lisp_true);
    goto v0121;

v0121:
    if (v0165 == nil) goto v0040;
    v0165 = stack[-5];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0169;

v0169:
    qvalue(elt(env, 4)) = stack[-2]; // !*gcd
    qvalue(elt(env, 3)) = stack[-3]; // !*ezgcd
    qvalue(elt(env, 2)) = stack[-4]; // ncmp!*
    qvalue(elt(env, 1)) = stack[-6]; // !*exp
    { popv(8); return onevalue(v0165); }

v0040:
    v0165 = qvalue(elt(env, 2)); // ncmp!*
    if (v0165 == nil) goto v0024;
    v0165 = stack[-5];
    fn = elt(env, 16); // noncomfp
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    if (!(v0165 == nil)) goto v0024;
    v0165 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 2)) = v0165; // ncmp!*
    goto v0024;

v0024:
    v0165 = qvalue(elt(env, 5)); // t
    qvalue(elt(env, 4)) = v0165; // !*gcd
    v0165 = qvalue(elt(env, 7)); // !*limitedfactors
    if (v0165 == nil) goto v0043;
    v0165 = qvalue(elt(env, 6)); // nil
    goto v0111;

v0111:
    if (v0165 == nil) goto v0103;
    v0165 = qvalue(elt(env, 5)); // t
    qvalue(elt(env, 3)) = v0165; // !*ezgcd
    goto v0103;

v0103:
    v0165 = qvalue(elt(env, 9)); // !*mcd
    if (v0165 == nil) goto v0009;
    v0165 = qvalue(elt(env, 1)); // !*exp
    if (!(v0165 == nil)) goto v0131;
    v0165 = qvalue(elt(env, 5)); // t
    qvalue(elt(env, 1)) = v0165; // !*exp
    v0166 = stack[-5];
    v0165 = (LispObject)17; // 1
    v0165 = cons(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 17); // resimp
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 18); // !*q2f
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-5] = v0165;
    goto v0131;

v0131:
    v0166 = qvalue(elt(env, 8)); // dmode!*
    v0165 = elt(env, 12); // !:rn!:
    if (!(v0166 == v0165)) goto v0147;
    v0165 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 8)) = v0165; // dmode!*
    v0165 = qvalue(elt(env, 6)); // nil
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    qvalue(elt(env, 13)) = v0165; // alglist!*
    v0165 = stack[-5];
    fn = elt(env, 19); // prepf
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 20); // simp
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[0] = v0165;
    v0165 = stack[0];
    v0165 = qcdr(v0165);
    if (!consp(v0165)) goto v0067;
    v0165 = (LispObject)17; // 1
    stack[-1] = v0165;
    goto v0147;

v0147:
    v0165 = qvalue(elt(env, 2)); // ncmp!*
    if (!(v0165 == nil)) goto v0130;
    v0165 = stack[-5];
    fn = elt(env, 21); // sf2ss
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[0] = v0165;
    v0165 = stack[0];
    fn = elt(env, 22); // homogp
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    if (v0165 == nil) goto v0130;
    v0165 = qvalue(elt(env, 14)); // !*trfac
    if (v0165 == nil) goto v0054;
    v0165 = elt(env, 15); // "This polynomial is homogeneous - variables scaled"
    fn = elt(env, 23); // prin2t
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0054;

v0054:
    v0165 = stack[0];
    v0165 = qcar(v0165);
    v0165 = qcar(v0165);
    stack[-1] = qcar(v0165);
    v0165 = stack[0];
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    v0165 = qcar(v0165);
    v0165 = qcar(v0165);
    fn = elt(env, 24); // listsum
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0165 = cons(stack[-1], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-5] = v0165;
    v0165 = stack[0];
    stack[-1] = qcar(v0165);
    v0165 = stack[0];
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    fn = elt(env, 25); // subs0
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0166 = Lreverse(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0165 = (LispObject)17; // 1
    v0165 = list2star(stack[-1], v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 26); // ss2sf
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 27); // fctrf1
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[0] = v0165;
    v0166 = stack[-5];
    v0165 = stack[0];
    fn = elt(env, 28); // rconst
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[0] = v0165;
    v0165 = stack[0];
    stack[-1] = qcar(v0165);
    v0165 = stack[0];
    v0165 = qcdr(v0165);
    fn = elt(env, 29); // sort!-factors
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0165 = cons(stack[-1], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0169;

v0130:
    v0165 = stack[-5];
    fn = elt(env, 27); // fctrf1
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-5] = v0165;
    v0165 = stack[-1];
    if (v0165 == nil) goto v0170;
    v0165 = qvalue(elt(env, 6)); // nil
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    qvalue(elt(env, 13)) = v0165; // alglist!*
    v0165 = elt(env, 12); // !:rn!:
    qvalue(elt(env, 8)) = v0165; // dmode!*
    stack[0] = stack[-5];
    v0165 = stack[-5];
    v0166 = qcar(v0165);
    v0165 = stack[-1];
    fn = elt(env, 30); // quotf!*
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 31); // setcar
    v0165 = (*qfn2(fn))(qenv(fn), stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0170;

v0170:
    v0165 = stack[-5];
    stack[0] = qcar(v0165);
    v0165 = stack[-5];
    v0165 = qcdr(v0165);
    fn = elt(env, 29); // sort!-factors
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0165 = cons(stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0169;

v0067:
    v0165 = stack[0];
    v0165 = qcdr(v0165);
    stack[-1] = v0165;
    v0165 = stack[0];
    v0165 = qcar(v0165);
    stack[-5] = v0165;
    goto v0147;

v0009:
    v0167 = elt(env, 10); // poly
    v0166 = (LispObject)241; // 15
    v0165 = elt(env, 11); // "Factorization invalid with MCD off"
    fn = elt(env, 32); // rerror
    v0165 = (*qfnn(fn))(qenv(fn), 3, v0167, v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0131;

v0043:
    v0165 = qvalue(elt(env, 8)); // dmode!*
    v0165 = (v0165 == nil ? lisp_true : nil);
    goto v0111;

v0148:
    v0165 = qvalue(elt(env, 5)); // t
    goto v0121;
// error exit handlers
v0168:
    env = stack[-7];
    qvalue(elt(env, 4)) = stack[-2]; // !*gcd
    qvalue(elt(env, 3)) = stack[-3]; // !*ezgcd
    qvalue(elt(env, 2)) = stack[-4]; // ncmp!*
    qvalue(elt(env, 1)) = stack[-6]; // !*exp
    popv(8);
    return nil;
}



// Code for ofsf_anegrel

static LispObject CC_ofsf_anegrel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0048, v0104;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_anegrel");
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
    v0104 = v0000;
// end of prologue
    v0048 = v0104;
    v0108 = elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp))
    v0108 = Latsoc(nil, v0048, v0108);
    v0108 = qcdr(v0108);
    if (!(v0108 == nil)) { popv(1); return onevalue(v0108); }
    v0108 = elt(env, 2); // "ofsf_anegrel: unknown operator "
    v0048 = v0104;
    v0108 = list2(v0108, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(qenv(fn), v0108);
    }
// error exit handlers
v0013:
    popv(1);
    return nil;
}



// Code for ciom

static LispObject CC_ciom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0145, v0042;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ciom");
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
    v0145 = elt(env, 1); // "<OMATTR>"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = qvalue(elt(env, 2)); // t
    fn = elt(env, 12); // indent!*
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = elt(env, 3); // "<OMATP>"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = qvalue(elt(env, 2)); // t
    fn = elt(env, 12); // indent!*
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = elt(env, 4); // "<OMS cd=""typmml"" name=""type"">"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = elt(env, 5); // "<OMS cd=""typmml"" name="""
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = stack[0];
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0042 = Lintern(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = qvalue(elt(env, 6)); // mmltypes!*
    v0145 = Lassoc(nil, v0042, v0145);
    v0145 = Lprinc(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = stack[0];
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0042 = Lintern(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = qvalue(elt(env, 6)); // mmltypes!*
    v0145 = Lassoc(nil, v0042, v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0145 = Lprinc(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = elt(env, 7); // """>"
    v0145 = Lprinc(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 12); // indent!*
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = elt(env, 9); // "</OMATP>"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = stack[0];
    v0145 = qcdr(v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    fn = elt(env, 13); // objectom
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 12); // indent!*
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0145 = elt(env, 10); // "</OMATTR>"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0145 = nil;
    { popv(2); return onevalue(v0145); }
// error exit handlers
v0091:
    popv(2);
    return nil;
}



// Code for countof

static LispObject CC_countof(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0043, v0143;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for countof");
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
    v0143 = stack[-1];
    v0043 = stack[0];
    if (equal(v0143, v0043)) goto v0115;
    v0043 = stack[0];
    if (!consp(v0043)) goto v0029;
    v0143 = stack[-1];
    v0043 = stack[0];
    v0043 = qcar(v0043);
    stack[-2] = CC_countof(env, v0143, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0143 = stack[-1];
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = CC_countof(env, v0143, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    {
        LispObject v0010 = stack[-2];
        popv(4);
        return plus2(v0010, v0043);
    }

v0029:
    v0043 = (LispObject)1; // 0
    { popv(4); return onevalue(v0043); }

v0115:
    v0043 = (LispObject)17; // 1
    { popv(4); return onevalue(v0043); }
// error exit handlers
v0011:
    popv(4);
    return nil;
}



// Code for ieval

static LispObject CC_ieval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0115;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ieval");
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
    v0115 = v0000;
// end of prologue
    fn = elt(env, 1); // reval
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*s2i
        return (*qfn1(fn))(qenv(fn), v0115);
    }
// error exit handlers
v0149:
    popv(1);
    return nil;
}



// Code for !*rn2rd

static LispObject CC_Hrn2rd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0125;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *rn2rd");
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
    v0125 = qcdr(v0125);
    fn = elt(env, 1); // r2bf
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[0];
    fn = elt(env, 2); // chkrn!*
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // mkround
        return (*qfn1(fn))(qenv(fn), v0125);
    }
// error exit handlers
v0081:
    popv(1);
    return nil;
}



// Code for findoptrow

static LispObject CC_findoptrow(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0128, v0129, v0181, v0182;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findoptrow");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findoptrow");
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
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0058;
    stack[0] = v0001;
    stack[-6] = v0000;
// end of prologue
    stack[-7] = nil;
    stack[-2] = stack[0];
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0129 = qvalue(elt(env, 2)); // maxvar
    v0128 = stack[-6];
    v0128 = plus2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0129 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0128/(16/CELL)));
    v0128 = (LispObject)65; // 4
    v0128 = *(LispObject *)((char *)v0129 + (CELL-TAG_VECTOR) + ((int32_t)v0128/(16/CELL)));
    fn = elt(env, 8); // pnthxzz
    v0128 = (*qfn2(fn))(qenv(fn), stack[-2], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    v0128 = qcar(v0128);
    stack[-3] = v0128;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0129 = qvalue(elt(env, 2)); // maxvar
    v0128 = stack[0];
    v0128 = plus2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0129 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0128/(16/CELL)));
    v0128 = (LispObject)65; // 4
    v0128 = *(LispObject *)((char *)v0129 + (CELL-TAG_VECTOR) + ((int32_t)v0128/(16/CELL)));
    stack[-2] = v0128;
    goto v0143;

v0143:
    v0128 = stack[-2];
    if (v0128 == nil) { LispObject res = stack[-7]; popv(9); return onevalue(res); }
    v0128 = stack[-2];
    v0128 = qcar(v0128);
    stack[-1] = v0128;
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0129 = qvalue(elt(env, 2)); // maxvar
    v0128 = stack[-1];
    v0128 = qcar(v0128);
    stack[-4] = v0128;
    v0128 = plus2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0129 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0128/(16/CELL)));
    v0128 = (LispObject)1; // 0
    v0128 = *(LispObject *)((char *)v0129 + (CELL-TAG_VECTOR) + ((int32_t)v0128/(16/CELL)));
    if (v0128 == nil) goto v0119;
    v0182 = stack[-4];
    v0181 = stack[-6];
    v0128 = stack[-1];
    v0128 = qcdr(v0128);
    v0129 = qcar(v0128);
    v0128 = stack[-3];
    fn = elt(env, 9); // testpr
    v0128 = (*qfnn(fn))(qenv(fn), 4, v0182, v0181, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[0] = v0128;
    v0128 = qcdr(v0128);
    if (v0128 == nil) goto v0184;
    v0128 = stack[0];
    v0129 = Llength(nil, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-1] = v0129;
    v0128 = stack[-5];
    v0128 = (LispObject)greaterp2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0128 = v0128 ? lisp_true : nil;
    env = stack[-8];
    if (v0128 == nil) goto v0076;
    v0128 = stack[-1];
    stack[-5] = v0128;
    qvalue(elt(env, 5)) = v0128; // newnjsi
    v0128 = stack[-4];
    stack[-7] = v0128;
    v0128 = stack[0];
    qvalue(elt(env, 6)) = v0128; // newjsi
    goto v0076;

v0076:
    v0129 = stack[-4];
    v0128 = qvalue(elt(env, 7)); // roccup2
    v0128 = cons(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    qvalue(elt(env, 7)) = v0128; // roccup2
    goto v0088;

v0088:
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0129 = qvalue(elt(env, 2)); // maxvar
    v0128 = stack[-4];
    v0128 = plus2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0181 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0128/(16/CELL)));
    v0129 = (LispObject)1; // 0
    v0128 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0181 + (CELL-TAG_VECTOR) + ((int32_t)v0129/(16/CELL))) = v0128;
    goto v0119;

v0119:
    v0128 = stack[-2];
    v0128 = qcdr(v0128);
    stack[-2] = v0128;
    goto v0143;

v0184:
    v0129 = stack[-4];
    v0128 = qvalue(elt(env, 4)); // roccup1
    v0128 = cons(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    qvalue(elt(env, 4)) = v0128; // roccup1
    goto v0088;
// error exit handlers
v0183:
    popv(9);
    return nil;
}



// Code for new_simpexpt

static LispObject CC_new_simpexpt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0068, v0036;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for new_simpexpt");
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
    stack[-5] = v0000;
// end of prologue
    stack[-6] = qvalue(elt(env, 1)); // !*precise
    qvalue(elt(env, 1)) = nil; // !*precise
    stack[-4] = qvalue(elt(env, 2)); // !*factor
    qvalue(elt(env, 2)) = nil; // !*factor
    stack[-3] = qvalue(elt(env, 3)); // !*exp
    qvalue(elt(env, 3)) = nil; // !*exp
    stack[-2] = qvalue(elt(env, 4)); // !*mcd
    qvalue(elt(env, 4)) = nil; // !*mcd
    stack[-1] = qvalue(elt(env, 5)); // !*allfac
    qvalue(elt(env, 5)) = nil; // !*allfac
    v0036 = elt(env, 6); // exp
    v0068 = elt(env, 7); // mcd
    v0068 = list2(v0036, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    fn = elt(env, 15); // on
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    v0036 = elt(env, 8); // precise
    v0068 = elt(env, 9); // allfac
    v0068 = list2(v0036, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    fn = elt(env, 16); // off
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    v0068 = stack[-5];
    v0036 = qcar(v0068);
    v0068 = elt(env, 10); // minus
    if (!consp(v0036)) goto v0014;
    v0036 = qcar(v0036);
    if (!(v0036 == v0068)) goto v0014;
    v0036 = elt(env, 10); // minus
    v0068 = (LispObject)17; // 1
    v0036 = list2(v0036, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    v0068 = stack[-5];
    v0068 = qcdr(v0068);
    v0068 = qcar(v0068);
    v0068 = list2(v0036, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    fn = elt(env, 14); // original_simpexpt
    stack[0] = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    v0068 = stack[-5];
    v0068 = qcar(v0068);
    v0068 = qcdr(v0068);
    v0036 = qcar(v0068);
    v0068 = stack[-5];
    v0068 = qcdr(v0068);
    v0068 = qcar(v0068);
    v0068 = list2(v0036, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    v0068 = CC_new_simpexpt(env, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    fn = elt(env, 17); // multsq
    v0068 = (*qfn2(fn))(qenv(fn), stack[0], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    goto v0144;

v0144:
    qvalue(elt(env, 5)) = stack[-1]; // !*allfac
    qvalue(elt(env, 4)) = stack[-2]; // !*mcd
    qvalue(elt(env, 3)) = stack[-3]; // !*exp
    qvalue(elt(env, 2)) = stack[-4]; // !*factor
    qvalue(elt(env, 1)) = stack[-6]; // !*precise
    { popv(8); return onevalue(v0068); }

v0014:
    v0068 = qvalue(elt(env, 11)); // !*redefmsg
    stack[0] = v0068;
    v0068 = qvalue(elt(env, 12)); // nil
    qvalue(elt(env, 11)) = v0068; // !*redefmsg
    v0036 = elt(env, 13); // simpexpt
    v0068 = elt(env, 14); // original_simpexpt
    fn = elt(env, 18); // copyd
    v0068 = (*qfn2(fn))(qenv(fn), v0036, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    v0068 = stack[-5];
    fn = elt(env, 13); // simpexpt
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    stack[-5] = v0068;
    v0036 = elt(env, 13); // simpexpt
    v0068 = elt(env, 0); // new_simpexpt
    fn = elt(env, 18); // copyd
    v0068 = (*qfn2(fn))(qenv(fn), v0036, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-7];
    v0068 = stack[0];
    qvalue(elt(env, 11)) = v0068; // !*redefmsg
    v0068 = stack[-5];
    goto v0144;
// error exit handlers
v0034:
    env = stack[-7];
    qvalue(elt(env, 5)) = stack[-1]; // !*allfac
    qvalue(elt(env, 4)) = stack[-2]; // !*mcd
    qvalue(elt(env, 3)) = stack[-3]; // !*exp
    qvalue(elt(env, 2)) = stack[-4]; // !*factor
    qvalue(elt(env, 1)) = stack[-6]; // !*precise
    popv(8);
    return nil;
}



// Code for exdf0

static LispObject CC_exdf0(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0072, v0003;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exdf0");
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
    v0072 = stack[0];
    v0072 = qcar(v0072);
    fn = elt(env, 1); // exdff0
    stack[-1] = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    v0072 = stack[0];
    v0072 = qcdr(v0072);
    fn = elt(env, 2); // negf
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    fn = elt(env, 1); // exdff0
    v0003 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    v0072 = stack[0];
    fn = elt(env, 3); // multpfsq
    v0072 = (*qfn2(fn))(qenv(fn), v0003, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    fn = elt(env, 4); // addpf
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    v0003 = (LispObject)17; // 1
    v0072 = stack[0];
    v0072 = qcdr(v0072);
    v0072 = cons(v0003, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    {
        LispObject v0109 = stack[-1];
        popv(3);
        fn = elt(env, 3); // multpfsq
        return (*qfn2(fn))(qenv(fn), v0109, v0072);
    }
// error exit handlers
v0004:
    popv(3);
    return nil;
}



// Code for listpri

static LispObject CC_listpri(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0164, v0112;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listpri");
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
    v0164 = stack[-2];
    stack[0] = v0164;
    v0164 = stack[-2];
    v0164 = qcdr(v0164);
    stack[-2] = v0164;
    v0164 = elt(env, 1); // !*lcbkt!*
    if (!symbolp(v0164)) v0164 = nil;
    else { v0164 = qfastgets(v0164);
           if (v0164 != nil) { v0164 = elt(v0164, 37); // prtch
#ifdef RECORD_GET
             if (v0164 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0164 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0164 == SPID_NOPROP) v0164 = nil; }}
#endif
    fn = elt(env, 7); // prin2!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0164 = qvalue(elt(env, 2)); // orig!*
    stack[-3] = v0164;
    v0112 = qvalue(elt(env, 3)); // posn!*
    v0164 = (LispObject)289; // 18
    v0164 = (LispObject)lessp2(v0112, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-4];
    if (v0164 == nil) goto v0101;
    v0164 = qvalue(elt(env, 3)); // posn!*
    goto v0030;

v0030:
    qvalue(elt(env, 2)) = v0164; // orig!*
    v0164 = stack[-2];
    if (v0164 == nil) goto v0081;
    v0112 = stack[-2];
    v0164 = (LispObject)641; // 40
    fn = elt(env, 8); // treesizep
    v0164 = (*qfn2(fn))(qenv(fn), v0112, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    stack[-1] = v0164;
    goto v0073;

v0073:
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    fn = elt(env, 9); // negnumberchk
    v0112 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0164 = (LispObject)1; // 0
    fn = elt(env, 10); // maprint
    v0164 = (*qfn2(fn))(qenv(fn), v0112, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0164 = stack[-2];
    v0164 = qcdr(v0164);
    stack[-2] = v0164;
    v0164 = stack[-2];
    if (v0164 == nil) goto v0081;
    v0164 = elt(env, 4); // !*comma!*
    fn = elt(env, 11); // oprin
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0164 = stack[-1];
    if (v0164 == nil) goto v0073;
    v0164 = qvalue(elt(env, 5)); // t
    fn = elt(env, 12); // terpri!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    goto v0073;

v0081:
    v0164 = elt(env, 6); // !*rcbkt!*
    if (!symbolp(v0164)) v0164 = nil;
    else { v0164 = qfastgets(v0164);
           if (v0164 != nil) { v0164 = elt(v0164, 37); // prtch
#ifdef RECORD_GET
             if (v0164 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0164 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0164 == SPID_NOPROP) v0164 = nil; }}
#endif
    fn = elt(env, 7); // prin2!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0164 = stack[-3];
    qvalue(elt(env, 2)) = v0164; // orig!*
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0101:
    v0112 = qvalue(elt(env, 2)); // orig!*
    v0164 = (LispObject)49; // 3
    v0164 = plus2(v0112, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    goto v0030;
// error exit handlers
v0064:
    popv(5);
    return nil;
}



// Code for physoppri

static LispObject CC_physoppri(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0211, v0212, v0213, v0214;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physoppri");
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
// copy arguments values to proper place
    stack[-8] = v0000;
// end of prologue
    stack[-6] = nil;
    v0211 = stack[-8];
    if (symbolp(v0211)) goto v0150;
    v0211 = stack[-8];
    v0211 = qcar(v0211);
    goto v0002;

v0002:
    stack[-9] = v0211;
    v0211 = stack[-8];
    if (symbolp(v0211)) goto v0018;
    v0211 = stack[-8];
    v0211 = qcdr(v0211);
    goto v0107;

v0107:
    stack[-7] = v0211;
    stack[-5] = elt(env, 0); // physoppri
    stack[-4] = elt(env, 2); // "x= "
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); // " y= "
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); // "nat= "
    v0213 = elt(env, 5); // !*nat
    v0212 = elt(env, 6); // " contract= "
    v0211 = elt(env, 7); // !*contract
    v0211 = list3(v0213, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = list3star(stack[-2], stack[-1], stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = list3star(stack[-5], stack[-4], stack[-3], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    fn = elt(env, 20); // trwrite
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = qvalue(elt(env, 5)); // !*nat
    if (v0211 == nil) goto v0164;
    v0211 = qvalue(elt(env, 7)); // !*contract
    if (!(v0211 == nil)) goto v0164;
    v0211 = stack[-9];
    v0211 = Lexplode(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lreverse(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[-9] = v0211;
    v0211 = stack[-9];
    v0212 = Llength(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = (LispObject)33; // 2
    v0211 = (LispObject)greaterp2(v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    v0211 = v0211 ? lisp_true : nil;
    env = stack[-10];
    if (v0211 == nil) goto v0216;
    v0211 = stack[-9];
    v0211 = qcdr(v0211);
    v0212 = qcar(v0211);
    v0211 = elt(env, 14); // !-
    if (v0212 == v0211) goto v0057;
    v0211 = stack[-9];
    v0212 = qcar(v0211);
    v0211 = elt(env, 16); // !+
    if (v0212 == v0211) goto v0088;
    v0211 = stack[-9];
    v0211 = Lreverse(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lcompress(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[-9] = v0211;
    goto v0141;

v0141:
    stack[0] = elt(env, 8); // !"
    v0211 = stack[-9];
    v0211 = Lexplode(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[0] = cons(stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = elt(env, 8); // !"
    v0211 = ncons(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lappend(nil, stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lcompress(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[-9] = v0211;
    v0211 = stack[-7];
    if (v0211 == nil) goto v0217;
    v0212 = stack[-9];
    v0211 = stack[-7];
    v0211 = cons(v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    goto v0218;

v0218:
    stack[-3] = v0211;
    stack[-2] = elt(env, 0); // physoppri
    stack[-1] = elt(env, 2); // "x= "
    stack[0] = stack[-9];
    v0214 = elt(env, 17); // " z= "
    v0213 = stack[-6];
    v0212 = elt(env, 18); // " x1= "
    v0211 = stack[-3];
    v0211 = list4(v0214, v0213, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = list3star(stack[-2], stack[-1], stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    fn = elt(env, 20); // trwrite
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = stack[-6];
    if (v0211 == nil) goto v0219;
    v0213 = elt(env, 19); // expt
    v0212 = stack[-3];
    v0211 = stack[-6];
    v0212 = list3(v0213, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = elt(env, 19); // expt
    if (!symbolp(v0211)) v0211 = nil;
    else { v0211 = qfastgets(v0211);
           if (v0211 != nil) { v0211 = elt(v0211, 23); // infix
#ifdef RECORD_GET
             if (v0211 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0211 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0211 == SPID_NOPROP) v0211 = nil; }}
#endif
    fn = elt(env, 21); // exptpri
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    { LispObject res = stack[-8]; popv(11); return onevalue(res); }

v0219:
    v0211 = stack[-9];
    fn = elt(env, 22); // prin2!*
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = stack[-7];
    if (v0211 == nil) { LispObject res = stack[-8]; popv(11); return onevalue(res); }
    v0211 = elt(env, 9); // "("
    fn = elt(env, 22); // prin2!*
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 10)) = v0211; // obrkp!*
    v0213 = elt(env, 11); // !*comma!*
    v0212 = (LispObject)1; // 0
    v0211 = stack[-7];
    fn = elt(env, 23); // inprint
    v0211 = (*qfnn(fn))(qenv(fn), 3, v0213, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = qvalue(elt(env, 12)); // t
    qvalue(elt(env, 10)) = v0211; // obrkp!*
    v0211 = elt(env, 13); // ")"
    fn = elt(env, 22); // prin2!*
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    { LispObject res = stack[-8]; popv(11); return onevalue(res); }

v0217:
    v0211 = stack[-9];
    goto v0218;

v0088:
    v0211 = elt(env, 16); // !+
    stack[-6] = v0211;
    v0212 = stack[-9];
    v0211 = (LispObject)49; // 3
    fn = elt(env, 24); // pnth
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lreverse(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lcompress(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[-9] = v0211;
    goto v0141;

v0057:
    v0212 = elt(env, 14); // !-
    v0211 = elt(env, 15); // !1
    v0211 = list2(v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lcompress(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[-6] = v0211;
    v0212 = stack[-9];
    v0211 = (LispObject)65; // 4
    fn = elt(env, 24); // pnth
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lreverse(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lcompress(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[-9] = v0211;
    goto v0141;

v0216:
    v0211 = stack[-9];
    v0211 = Lreverse(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lcompress(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[-9] = v0211;
    goto v0141;

v0164:
    stack[0] = elt(env, 8); // !"
    v0211 = stack[-9];
    v0211 = Lexplode(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[0] = cons(stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = elt(env, 8); // !"
    v0211 = ncons(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lappend(nil, stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = Lcompress(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    stack[-9] = v0211;
    v0211 = stack[-9];
    fn = elt(env, 22); // prin2!*
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = stack[-7];
    if (v0211 == nil) { LispObject res = stack[-8]; popv(11); return onevalue(res); }
    v0211 = elt(env, 9); // "("
    fn = elt(env, 22); // prin2!*
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 10)) = v0211; // obrkp!*
    v0213 = elt(env, 11); // !*comma!*
    v0212 = (LispObject)1; // 0
    v0211 = stack[-7];
    fn = elt(env, 23); // inprint
    v0211 = (*qfnn(fn))(qenv(fn), 3, v0213, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-10];
    v0211 = qvalue(elt(env, 12)); // t
    qvalue(elt(env, 10)) = v0211; // obrkp!*
    v0211 = elt(env, 13); // ")"
    fn = elt(env, 22); // prin2!*
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    { LispObject res = stack[-8]; popv(11); return onevalue(res); }

v0018:
    v0211 = qvalue(elt(env, 1)); // nil
    goto v0107;

v0150:
    v0211 = stack[-8];
    goto v0002;
// error exit handlers
v0215:
    popv(11);
    return nil;
}



// Code for set!-weights

static LispObject CC_setKweights(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0074;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-weights");
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
    v0074 = v0000;
// end of prologue
    stack[-4] = (LispObject)1; // 0
    v0074 = qcdr(v0074);
    stack[-3] = v0074;
    v0074 = stack[-3];
    if (v0074 == nil) goto v0048;
    v0074 = (LispObject)17; // 1
    v0074 = ncons(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-5];
    stack[-1] = v0074;
    stack[-2] = v0074;
    goto v0148;

v0148:
    v0074 = stack[-3];
    v0074 = qcdr(v0074);
    stack[-3] = v0074;
    v0074 = stack[-3];
    if (v0074 == nil) goto v0072;
    stack[0] = stack[-1];
    v0074 = (LispObject)17; // 1
    v0074 = ncons(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-5];
    v0074 = Lrplacd(nil, stack[0], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-5];
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    stack[-1] = v0074;
    goto v0148;

v0072:
    v0074 = stack[-2];
    goto v0150;

v0150:
    v0074 = cons(stack[-4], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0041;
        popv(6);
        return Lnreverse(nil, v0074);

v0048:
    v0074 = qvalue(elt(env, 1)); // nil
    goto v0150;
// error exit handlers
v0041:
    popv(6);
    return nil;
}



// Code for cl_bnfsimpl

static LispObject CC_cl_bnfsimpl(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0148, v0107, v0018;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_bnfsimpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0107 = v0001;
    v0018 = v0000;
// end of prologue
    v0148 = qvalue(elt(env, 1)); // !*rlbnfsac
    if (v0148 == nil) return onevalue(v0018);
    v0148 = v0018;
    {
        fn = elt(env, 2); // cl_sac
        return (*qfn2(fn))(qenv(fn), v0148, v0107);
    }
}



// Code for lto_sgnchg1

static LispObject CC_lto_sgnchg1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0110;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_sgnchg1");
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

v0023:
    v0110 = stack[0];
    if (v0110 == nil) goto v0150;
    v0110 = stack[0];
    v0110 = qcdr(v0110);
    v0110 = (v0110 == nil ? lisp_true : nil);
    goto v0002;

v0002:
    if (v0110 == nil) goto v0108;
    v0110 = (LispObject)1; // 0
    { popv(3); return onevalue(v0110); }

v0108:
    v0110 = stack[0];
    v0110 = qcar(v0110);
    fn = elt(env, 2); // sgn
    stack[-1] = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-2];
    v0110 = stack[0];
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    fn = elt(env, 2); // sgn
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-2];
    if (stack[-1] == v0110) goto v0018;
    v0110 = stack[0];
    v0110 = qcdr(v0110);
    v0110 = CC_lto_sgnchg1(env, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    popv(3);
    return add1(v0110);

v0018:
    v0110 = stack[0];
    v0110 = qcdr(v0110);
    stack[0] = v0110;
    goto v0023;

v0150:
    v0110 = qvalue(elt(env, 1)); // t
    goto v0002;
// error exit handlers
v0143:
    popv(3);
    return nil;
}



// Code for cgp_greenp

static LispObject CC_cgp_greenp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0115;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_greenp");
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
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0115 = v0000;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    errexit();
    v0115 = (v0115 == nil ? lisp_true : nil);
    return onevalue(v0115);
}



// Code for conditionml

static LispObject CC_conditionml(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0029;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for conditionml");
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
    v0029 = elt(env, 1); // "<condition>"
    fn = elt(env, 5); // printout
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0029 = qvalue(elt(env, 2)); // t
    fn = elt(env, 6); // indent!*
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0029 = stack[0];
    v0029 = qcar(v0029);
    fn = elt(env, 7); // expression
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0029 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 6); // indent!*
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0029 = elt(env, 4); // "</condition>"
    fn = elt(env, 5); // printout
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    v0029 = nil;
    { popv(2); return onevalue(v0029); }
// error exit handlers
v0030:
    popv(2);
    return nil;
}



// Code for consrecip

static LispObject CC_consrecip(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0109, v0110, v0111;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for consrecip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0111 = v0000;
// end of prologue
    v0109 = v0111;
    v0110 = qcar(v0109);
    v0109 = (LispObject)17; // 1
    if (v0110 == v0109) goto v0081;
    v0109 = v0111;
    v0110 = qcar(v0109);
    v0109 = (LispObject)-15; // -1
    v0109 = (v0110 == v0109 ? lisp_true : nil);
    goto v0125;

v0125:
    if (v0109 == nil) goto v0025;
    v0109 = v0111;
    v0109 = qcar(v0109);
    return onevalue(v0109);

v0025:
    v0109 = elt(env, 2); // recip
    v0110 = v0111;
    return cons(v0109, v0110);

v0081:
    v0109 = qvalue(elt(env, 1)); // t
    goto v0125;
}



// Code for reduce!-columns

static LispObject CC_reduceKcolumns(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0056, v0057;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-columns");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-columns");
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
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0058;
    stack[-5] = v0001;
    stack[-6] = v0000;
// end of prologue
    v0056 = stack[-6];
    stack[-3] = v0056;
    v0056 = stack[-5];
    stack[-2] = v0056;
    stack[0] = stack[-6];
    v0057 = stack[-6];
    v0056 = stack[-4];
    fn = elt(env, 3); // red!-weight
    v0056 = (*qfn2(fn))(qenv(fn), v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    v0056 = cons(stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    stack[-7] = v0056;
    goto v0150;

v0150:
    v0056 = stack[-3];
    if (v0056 == nil) goto v0102;
    v0056 = stack[-3];
    v0057 = qcar(v0056);
    v0056 = (LispObject)1; // 0
    if (v0057 == v0056) goto v0103;
    v0056 = stack[-2];
    v0057 = qcar(v0056);
    v0056 = (LispObject)1; // 0
    v0056 = (v0057 == v0056 ? lisp_true : nil);
    goto v0005;

v0005:
    if (!(v0056 == nil)) goto v0114;
    v0056 = stack[-3];
    v0057 = qcar(v0056);
    v0056 = stack[-2];
    v0056 = qcar(v0056);
    v0056 = Ldivide(nil, v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    stack[-1] = v0056;
    v0057 = qcdr(v0056);
    v0056 = (LispObject)1; // 0
    if (!(v0057 == v0056)) goto v0114;
    stack[0] = stack[-6];
    v0056 = stack[-1];
    v0057 = qcar(v0056);
    v0056 = stack[-5];
    fn = elt(env, 4); // mv!-domainlist!-!*
    v0056 = (*qfn2(fn))(qenv(fn), v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    fn = elt(env, 5); // mv!-domainlist!-!-
    v0056 = (*qfn2(fn))(qenv(fn), stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    stack[-1] = v0056;
    v0057 = stack[-1];
    v0056 = stack[-4];
    fn = elt(env, 3); // red!-weight
    v0056 = (*qfn2(fn))(qenv(fn), v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    stack[0] = v0056;
    v0057 = stack[0];
    v0056 = stack[-7];
    v0056 = qcdr(v0056);
    fn = elt(env, 6); // red!-weight!-less!-p
    v0056 = (*qfn2(fn))(qenv(fn), v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    if (v0056 == nil) goto v0114;
    v0057 = stack[-1];
    v0056 = stack[0];
    v0057 = cons(v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    v0056 = stack[-7];
    fn = elt(env, 7); // more!-apartp
    v0056 = (*qfn2(fn))(qenv(fn), v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    if (!(v0056 == nil)) goto v0114;
    v0057 = stack[-1];
    v0056 = stack[0];
    v0056 = cons(v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-8];
    stack[-7] = v0056;
    goto v0114;

v0114:
    v0056 = stack[-3];
    v0056 = qcdr(v0056);
    stack[-3] = v0056;
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    stack[-2] = v0056;
    goto v0150;

v0103:
    v0056 = qvalue(elt(env, 1)); // t
    goto v0005;

v0102:
    v0056 = stack[-7];
    v0056 = qcar(v0056);
    { popv(9); return onevalue(v0056); }
// error exit handlers
v0047:
    popv(9);
    return nil;
}



// Code for prepreform1

static LispObject CC_prepreform1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0225, v0183;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepreform1");
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
    stack[-5] = v0001;
    stack[0] = v0000;
// end of prologue

v0022:
    v0225 = stack[0];
    if (!consp(v0225)) goto v0144;
    v0225 = stack[0];
    v0225 = qcar(v0225);
    if (!symbolp(v0225)) v0225 = nil;
    else { v0225 = qfastgets(v0225);
           if (v0225 != nil) { v0225 = elt(v0225, 8); // dname
#ifdef RECORD_GET
             if (v0225 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0225 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0225 == SPID_NOPROP) v0225 = nil; }}
#endif
    goto v0081;

v0081:
    if (!(v0225 == nil)) { LispObject res = stack[0]; popv(8); return onevalue(res); }
    stack[-6] = nil;
    v0225 = stack[-5];
    stack[-1] = v0225;
    goto v0083;

v0083:
    v0225 = stack[-6];
    if (v0225 == nil) goto v0025;
    v0225 = qvalue(elt(env, 2)); // nil
    goto v0095;

v0095:
    if (v0225 == nil) goto v0094;
    v0225 = stack[-1];
    v0183 = qcar(v0225);
    v0225 = stack[0];
    v0225 = qcdr(v0225);
    v0225 = Lsmemq(nil, v0183, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    if (v0225 == nil) goto v0117;
    v0225 = qvalue(elt(env, 1)); // t
    stack[-6] = v0225;
    goto v0083;

v0117:
    v0225 = stack[-1];
    v0225 = qcdr(v0225);
    stack[-1] = v0225;
    goto v0083;

v0094:
    v0225 = stack[-6];
    if (v0225 == nil) { LispObject res = stack[0]; popv(8); return onevalue(res); }
    v0225 = stack[0];
    v0183 = qcar(v0225);
    v0225 = elt(env, 3); // (plus difference minus times quotient)
    v0225 = Lmemq(nil, v0183, v0225);
    if (!(v0225 == nil)) goto v0007;
    v0225 = stack[0];
    v0225 = qcar(v0225);
    if (!symbolp(v0225)) v0225 = nil;
    else { v0225 = qfastgets(v0225);
           if (v0225 != nil) { v0225 = elt(v0225, 22); // simpfn
#ifdef RECORD_GET
             if (v0225 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0225 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0225 == SPID_NOPROP) v0225 = nil; }}
#endif
    if (!(v0225 == nil)) goto v0132;

v0007:
    v0225 = qvalue(elt(env, 2)); // nil
    stack[-6] = v0225;
    goto v0132;

v0132:
    v0225 = stack[0];
    v0183 = qcar(v0225);
    v0225 = elt(env, 4); // !*sq
    if (v0183 == v0225) goto v0113;
    v0225 = stack[0];
    stack[-4] = qcar(v0225);
    v0225 = stack[0];
    v0225 = qcdr(v0225);
    stack[-3] = v0225;
    v0225 = stack[-3];
    if (v0225 == nil) goto v0061;
    v0225 = stack[-3];
    v0225 = qcar(v0225);
    v0183 = v0225;
    v0225 = stack[-6];
    if (v0225 == nil) goto v0077;
    v0225 = v0183;
    fn = elt(env, 5); // simp!*
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    fn = elt(env, 6); // sqhorner!*
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    fn = elt(env, 7); // prepsq!*
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    v0183 = v0225;
    goto v0220;

v0220:
    v0225 = stack[-5];
    v0225 = CC_prepreform1(env, v0183, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    v0225 = ncons(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    stack[-1] = v0225;
    stack[-2] = v0225;
    goto v0032;

v0032:
    v0225 = stack[-3];
    v0225 = qcdr(v0225);
    stack[-3] = v0225;
    v0225 = stack[-3];
    if (v0225 == nil) goto v0160;
    stack[0] = stack[-1];
    v0225 = stack[-3];
    v0225 = qcar(v0225);
    v0183 = v0225;
    v0225 = stack[-6];
    if (v0225 == nil) goto v0226;
    v0225 = v0183;
    fn = elt(env, 5); // simp!*
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    fn = elt(env, 6); // sqhorner!*
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    fn = elt(env, 7); // prepsq!*
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    v0183 = v0225;
    goto v0177;

v0177:
    v0225 = stack[-5];
    v0225 = CC_prepreform1(env, v0183, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    v0225 = ncons(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    v0225 = Lrplacd(nil, stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    v0225 = stack[-1];
    v0225 = qcdr(v0225);
    stack[-1] = v0225;
    goto v0032;

v0226:
    v0225 = v0183;
    v0183 = v0225;
    goto v0177;

v0160:
    v0225 = stack[-2];
    goto v0053;

v0053:
    {
        LispObject v0227 = stack[-4];
        popv(8);
        return cons(v0227, v0225);
    }

v0077:
    v0225 = v0183;
    v0183 = v0225;
    goto v0220;

v0061:
    v0225 = qvalue(elt(env, 2)); // nil
    goto v0053;

v0113:
    v0225 = stack[0];
    v0225 = qcdr(v0225);
    v0225 = qcar(v0225);
    fn = elt(env, 6); // sqhorner!*
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    fn = elt(env, 7); // prepsq!*
    v0183 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-7];
    v0225 = stack[-5];
    stack[0] = v0183;
    stack[-5] = v0225;
    goto v0022;

v0025:
    v0225 = stack[-1];
    goto v0095;

v0144:
    v0225 = qvalue(elt(env, 1)); // t
    goto v0081;
// error exit handlers
v0141:
    popv(8);
    return nil;
}



// Code for vecsimp!*

static LispObject CC_vecsimpH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0171;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vecsimp*");
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
    v0171 = stack[0];
    fn = elt(env, 1); // vecp
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    if (v0171 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0171 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // vecsm!*
        return (*qfn1(fn))(qenv(fn), v0171);
    }
// error exit handlers
v0029:
    popv(2);
    return nil;
}



// Code for !*n2a

static LispObject CC_Hn2a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0171, v0024;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *n2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0024 = v0000;
// end of prologue
    v0171 = v0024;
    v0171 = integerp(v0171);
    if (!(v0171 == nil)) return onevalue(v0024);
    v0171 = v0024;
    {
        fn = elt(env, 1); // !*q2a
        return (*qfn1(fn))(qenv(fn), v0171);
    }
}



// Code for prepsq!*0

static LispObject CC_prepsqH0(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0096, v0015, v0016;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq*0");
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
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    if (v0096 == nil) goto v0081;
    v0096 = stack[-2];
    v0015 = qcar(v0096);
    v0096 = stack[-2];
    v0096 = qcdr(v0096);
    fn = elt(env, 2); // gcdf
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    stack[-3] = v0015;
    v0096 = (LispObject)17; // 1
    if (v0015 == v0096) goto v0041;
    v0096 = stack[-2];
    v0015 = qcar(v0096);
    v0096 = stack[-3];
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(qenv(fn), v0015, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    v0096 = stack[-2];
    v0015 = qcdr(v0096);
    v0096 = stack[-3];
    fn = elt(env, 3); // quotf!-fail
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    v0096 = stack[-1];
    {
        LispObject v0039 = stack[0];
        popv(5);
        fn = elt(env, 4); // prepsq!*1
        return (*qfnn(fn))(qenv(fn), 3, v0039, v0015, v0096);
    }

v0041:
    v0096 = stack[-2];
    v0016 = qcar(v0096);
    v0096 = stack[-2];
    v0015 = qcdr(v0096);
    v0096 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); // prepsq!*1
        return (*qfnn(fn))(qenv(fn), 3, v0016, v0015, v0096);
    }

v0081:
    v0096 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0096); }
// error exit handlers
v0120:
    popv(5);
    return nil;
}



// Code for subtractinds

static LispObject CC_subtractinds(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0145, v0042;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subtractinds");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subtractinds");
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

v0081:
    v0145 = stack[-2];
    if (v0145 == nil) goto v0150;
    v0145 = stack[-3];
    v0042 = qcar(v0145);
    v0145 = stack[-2];
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0042 = difference2(v0042, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-5];
    v0145 = (LispObject)1; // 0
    v0145 = (LispObject)lessp2(v0042, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    v0145 = v0145 ? lisp_true : nil;
    env = stack[-5];
    if (v0145 == nil) goto v0072;
    v0145 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0145); }

v0072:
    v0145 = stack[-3];
    v0145 = qcdr(v0145);
    stack[-4] = v0145;
    v0145 = stack[-2];
    v0145 = qcdr(v0145);
    stack[0] = v0145;
    v0145 = stack[-3];
    v0042 = qcar(v0145);
    v0145 = stack[-2];
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0042 = difference2(v0042, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-5];
    v0145 = stack[-1];
    v0145 = cons(v0042, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-5];
    stack[-1] = v0145;
    v0145 = stack[0];
    stack[-2] = v0145;
    v0145 = stack[-4];
    stack[-3] = v0145;
    goto v0081;

v0150:
    v0145 = stack[-1];
        popv(6);
        return Lnreverse(nil, v0145);
// error exit handlers
v0007:
    popv(6);
    return nil;
}



// Code for expf

static LispObject CC_expf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0203, v0218, v0233;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expf");
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
    v0203 = stack[-1];
    if (v0203 == nil) goto v0115;
    v0218 = stack[-1];
    v0203 = (LispObject)17; // 1
    if (v0218 == v0203) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0203 = stack[-1];
    if (!consp(v0203)) goto v0108;
    v0203 = stack[-1];
    if (!consp(v0203)) goto v0109;
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = (consp(v0203) ? nil : lisp_true);
    goto v0004;

v0004:
    if (v0203 == nil) goto v0005;
    v0218 = stack[-1];
    v0203 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // !:expt
        return (*qfn2(fn))(qenv(fn), v0218, v0203);
    }

v0005:
    v0203 = stack[-1];
    v0203 = qcdr(v0203);
    if (v0203 == nil) goto v0096;
    v0218 = stack[-1];
    v0203 = stack[0];
    {
        popv(4);
        fn = elt(env, 6); // mksp!*
        return (*qfn2(fn))(qenv(fn), v0218, v0203);
    }

v0096:
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0218 = qcdr(v0203);
    v0203 = qvalue(elt(env, 3)); // frlis!*
    v0203 = Lmemq(nil, v0218, v0203);
    if (v0203 == nil) goto v0062;
    v0233 = elt(env, 4); // expt
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0218 = qcar(v0203);
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0203 = qcdr(v0203);
    v0203 = list3(v0233, v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    fn = elt(env, 7); // fkern
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0218 = qcar(v0203);
    v0203 = stack[0];
    fn = elt(env, 8); // to
    stack[-2] = (*qfn2(fn))(qenv(fn), v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0218 = qcdr(v0203);
    v0203 = stack[0];
    v0203 = CC_expf(env, v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0203 = cons(stack[-2], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    popv(4);
    return ncons(v0203);

v0062:
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0218 = qcdr(v0203);
    v0203 = stack[0];
    v0203 = times2(v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    stack[-2] = v0203;
    v0218 = stack[-2];
    v0203 = (LispObject)1; // 0
    v0203 = (LispObject)greaterp2(v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    v0203 = v0203 ? lisp_true : nil;
    env = stack[-3];
    if (v0203 == nil) goto v0134;
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    fn = elt(env, 9); // sfp
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    if (v0203 == nil) goto v0134;
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0218 = qcar(v0203);
    v0203 = stack[-2];
    fn = elt(env, 10); // exptf
    stack[-2] = (*qfn2(fn))(qenv(fn), v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0218 = qcdr(v0203);
    v0203 = stack[0];
    v0203 = CC_expf(env, v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    {
        LispObject v0165 = stack[-2];
        popv(4);
        fn = elt(env, 11); // multf
        return (*qfn2(fn))(qenv(fn), v0165, v0203);
    }

v0134:
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0218 = qcar(v0203);
    v0203 = stack[-2];
    fn = elt(env, 8); // to
    stack[-2] = (*qfn2(fn))(qenv(fn), v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0218 = qcdr(v0203);
    v0203 = stack[0];
    v0203 = CC_expf(env, v0218, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0203 = cons(stack[-2], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    popv(4);
    return ncons(v0203);

v0109:
    v0203 = qvalue(elt(env, 2)); // t
    goto v0004;

v0108:
    stack[-2] = (LispObject)17; // 1
    v0203 = stack[0];
    v0203 = negate(v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    v0203 = Lexpt(nil, stack[-1], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-3];
    {
        LispObject v0166 = stack[-2];
        popv(4);
        fn = elt(env, 12); // mkrn
        return (*qfn2(fn))(qenv(fn), v0166, v0203);
    }

v0115:
    v0203 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0203); }
// error exit handlers
v0234:
    popv(4);
    return nil;
}



// Code for replace!-next

static LispObject CC_replaceKnext(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0010, v0075, v0073, v0019;
    LispObject fn;
    CSL_IGNORE(nil);
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
    goto v0149;

v0149:
    v0010 = stack[-1];
    if (v0010 == nil) goto v0144;
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    v0019 = qcar(v0010);
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    v0010 = qcdr(v0010);
    v0073 = qcar(v0010);
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    v0010 = qcdr(v0010);
    v0010 = qcdr(v0010);
    v0075 = qcar(v0010);
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0075 = list4(v0019, v0073, v0075, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0010 = stack[-2];
    v0010 = cons(v0075, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    stack[-2] = v0010;
    v0010 = stack[-1];
    v0010 = qcdr(v0010);
    stack[-1] = v0010;
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    stack[0] = v0010;
    goto v0149;

v0144:
    v0010 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0010);
    }
// error exit handlers
v0117:
    popv(4);
    return nil;
}



// Code for pasf_or

static LispObject CC_pasf_or(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0269, v0270;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_or");
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
    v0270 = stack[0];
    v0269 = elt(env, 1); // true
    if (v0270 == v0269) goto v0029;
    v0270 = stack[0];
    v0269 = elt(env, 3); // false
    v0269 = (v0270 == v0269 ? lisp_true : nil);
    goto v0024;

v0024:
    if (v0269 == nil) goto v0010;
    v0269 = qvalue(elt(env, 2)); // t
    goto v0002;

v0002:
    if (!(v0269 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0269 = stack[0];
    v0269 = qcdr(v0269);
    v0269 = qcar(v0269);
    fn = elt(env, 10); // pasf_deci
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    stack[-1] = v0269;
    v0270 = stack[0];
    v0269 = elt(env, 1); // true
    if (v0270 == v0269) goto v0033;
    v0270 = stack[0];
    v0269 = elt(env, 3); // false
    v0269 = (v0270 == v0269 ? lisp_true : nil);
    goto v0272;

v0272:
    if (v0269 == nil) goto v0232;
    v0269 = stack[0];
    v0270 = v0269;
    goto v0113;

v0113:
    v0269 = elt(env, 5); // lessp
    if (v0270 == v0269) goto v0162;
    v0269 = qvalue(elt(env, 6)); // nil
    goto v0099;

v0099:
    if (v0269 == nil) goto v0225;
    stack[-1] = elt(env, 7); // leq
    v0269 = stack[0];
    v0269 = qcdr(v0269);
    stack[0] = qcar(v0269);
    v0269 = (LispObject)17; // 1
    fn = elt(env, 11); // simp
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0269 = qcar(v0269);
    fn = elt(env, 12); // addf
    v0269 = (*qfn2(fn))(qenv(fn), stack[0], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0270 = qvalue(elt(env, 6)); // nil
    {
        LispObject v0273 = stack[-1];
        popv(3);
        return list3(v0273, v0269, v0270);
    }

v0225:
    v0270 = stack[0];
    v0269 = elt(env, 1); // true
    if (v0270 == v0269) goto v0133;
    v0270 = stack[0];
    v0269 = elt(env, 3); // false
    v0269 = (v0270 == v0269 ? lisp_true : nil);
    goto v0222;

v0222:
    if (v0269 == nil) goto v0274;
    v0269 = stack[0];
    v0270 = v0269;
    goto v0128;

v0128:
    v0269 = elt(env, 7); // leq
    if (v0270 == v0269) goto v0275;
    v0269 = qvalue(elt(env, 6)); // nil
    goto v0173;

v0173:
    if (v0269 == nil) goto v0276;
    stack[-1] = elt(env, 5); // lessp
    v0269 = stack[0];
    v0269 = qcdr(v0269);
    stack[0] = qcar(v0269);
    v0269 = (LispObject)17; // 1
    fn = elt(env, 11); // simp
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0269 = qcar(v0269);
    fn = elt(env, 13); // negf
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    fn = elt(env, 12); // addf
    v0269 = (*qfn2(fn))(qenv(fn), stack[0], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0270 = qvalue(elt(env, 6)); // nil
    {
        LispObject v0277 = stack[-1];
        popv(3);
        return list3(v0277, v0269, v0270);
    }

v0276:
    v0270 = stack[0];
    v0269 = elt(env, 1); // true
    if (v0270 == v0269) goto v0278;
    v0270 = stack[0];
    v0269 = elt(env, 3); // false
    v0269 = (v0270 == v0269 ? lisp_true : nil);
    goto v0191;

v0191:
    if (v0269 == nil) goto v0192;
    v0269 = stack[0];
    v0270 = v0269;
    goto v0279;

v0279:
    v0269 = elt(env, 8); // greaterp
    if (v0270 == v0269) goto v0280;
    v0269 = qvalue(elt(env, 6)); // nil
    goto v0281;

v0281:
    if (v0269 == nil) goto v0282;
    stack[-1] = elt(env, 9); // geq
    v0269 = stack[0];
    v0269 = qcdr(v0269);
    stack[0] = qcar(v0269);
    v0269 = (LispObject)17; // 1
    fn = elt(env, 11); // simp
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0269 = qcar(v0269);
    fn = elt(env, 13); // negf
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    fn = elt(env, 12); // addf
    v0269 = (*qfn2(fn))(qenv(fn), stack[0], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0270 = qvalue(elt(env, 6)); // nil
    {
        LispObject v0283 = stack[-1];
        popv(3);
        return list3(v0283, v0269, v0270);
    }

v0282:
    v0270 = stack[0];
    v0269 = elt(env, 1); // true
    if (v0270 == v0269) goto v0284;
    v0270 = stack[0];
    v0269 = elt(env, 3); // false
    v0269 = (v0270 == v0269 ? lisp_true : nil);
    goto v0285;

v0285:
    if (v0269 == nil) goto v0286;
    v0269 = stack[0];
    v0270 = v0269;
    goto v0287;

v0287:
    v0269 = elt(env, 9); // geq
    if (v0270 == v0269) goto v0288;
    v0269 = qvalue(elt(env, 6)); // nil
    goto v0289;

v0289:
    if (v0269 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 8); // greaterp
    v0269 = stack[0];
    v0269 = qcdr(v0269);
    stack[0] = qcar(v0269);
    v0269 = (LispObject)17; // 1
    fn = elt(env, 11); // simp
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0269 = qcar(v0269);
    fn = elt(env, 12); // addf
    v0269 = (*qfn2(fn))(qenv(fn), stack[0], v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0270 = qvalue(elt(env, 6)); // nil
    {
        LispObject v0290 = stack[-1];
        popv(3);
        return list3(v0290, v0269, v0270);
    }

v0288:
    v0269 = stack[-1];
    v0270 = qcdr(v0269);
    v0269 = (LispObject)1; // 0
    v0269 = (LispObject)lessp2(v0270, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-2];
    goto v0289;

v0286:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = Lconsp(nil, v0269);
    env = stack[-2];
    if (v0269 == nil) goto v0291;
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0287;

v0291:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0287;

v0284:
    v0269 = qvalue(elt(env, 2)); // t
    goto v0285;

v0280:
    v0269 = stack[-1];
    v0270 = qcdr(v0269);
    v0269 = (LispObject)1; // 0
    v0269 = (LispObject)greaterp2(v0270, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-2];
    goto v0281;

v0192:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = Lconsp(nil, v0269);
    env = stack[-2];
    if (v0269 == nil) goto v0212;
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0279;

v0212:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0279;

v0278:
    v0269 = qvalue(elt(env, 2)); // t
    goto v0191;

v0275:
    v0269 = stack[-1];
    v0270 = qcdr(v0269);
    v0269 = (LispObject)1; // 0
    v0269 = (LispObject)greaterp2(v0270, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-2];
    goto v0173;

v0274:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = Lconsp(nil, v0269);
    env = stack[-2];
    if (v0269 == nil) goto v0166;
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0128;

v0166:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0128;

v0133:
    v0269 = qvalue(elt(env, 2)); // t
    goto v0222;

v0162:
    v0269 = stack[-1];
    v0270 = qcdr(v0269);
    v0269 = (LispObject)1; // 0
    v0269 = (LispObject)lessp2(v0270, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-2];
    goto v0099;

v0232:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = Lconsp(nil, v0269);
    env = stack[-2];
    if (v0269 == nil) goto v0136;
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0113;

v0136:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0113;

v0033:
    v0269 = qvalue(elt(env, 2)); // t
    goto v0272;

v0010:
    v0270 = stack[0];
    v0269 = elt(env, 1); // true
    if (v0270 == v0269) goto v0116;
    v0270 = stack[0];
    v0269 = elt(env, 3); // false
    v0269 = (v0270 == v0269 ? lisp_true : nil);
    goto v0044;

v0044:
    if (v0269 == nil) goto v0143;
    v0269 = stack[0];
    v0270 = v0269;
    goto v0103;

v0103:
    v0269 = elt(env, 4); // (lessp greaterp leq geq)
    v0269 = Lmemq(nil, v0270, v0269);
    v0269 = (v0269 == nil ? lisp_true : nil);
    goto v0002;

v0143:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = Lconsp(nil, v0269);
    env = stack[-2];
    if (v0269 == nil) goto v0186;
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0103;

v0186:
    v0269 = stack[0];
    v0269 = qcar(v0269);
    v0270 = v0269;
    goto v0103;

v0116:
    v0269 = qvalue(elt(env, 2)); // t
    goto v0044;

v0029:
    v0269 = qvalue(elt(env, 2)); // t
    goto v0024;
// error exit handlers
v0271:
    popv(3);
    return nil;
}



// Code for integralir

static LispObject CC_integralir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0039, v0017;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "integralir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for integralir");
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
    v0017 = qvalue(elt(env, 1)); // atts
    v0039 = elt(env, 2); // name
    fn = elt(env, 7); // find
    v0039 = (*qfn2(fn))(qenv(fn), v0017, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0039 = Lintern(nil, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-1] = v0039;
    v0039 = elt(env, 3); // (bvar x 1)
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[0] = v0039;
    v0017 = stack[-1];
    v0039 = elt(env, 5); // defint
    if (!(v0017 == v0039)) goto v0107;
    fn = elt(env, 8); // lex
    v0039 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    fn = elt(env, 9); // omobj
    v0039 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    goto v0107;

v0107:
    fn = elt(env, 8); // lex
    v0039 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    fn = elt(env, 9); // omobj
    v0039 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-2] = v0039;
    v0039 = stack[-2];
    v0039 = Lconsp(nil, v0039);
    env = stack[-3];
    if (v0039 == nil) goto v0092;
    v0039 = stack[-2];
    v0017 = qcar(v0039);
    v0039 = elt(env, 6); // lambda
    if (!(v0017 == v0039)) goto v0092;
    v0039 = stack[-2];
    fn = elt(env, 10); // lambdavar
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[0] = v0039;
    v0039 = stack[-2];
    fn = elt(env, 11); // lambdafun
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-2] = v0039;
    goto v0092;

v0092:
    v0017 = stack[-1];
    v0039 = qvalue(elt(env, 4)); // nil
    stack[-1] = list2(v0017, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0039 = stack[-2];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0039 = Lappend(nil, stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    {
        LispObject v0063 = stack[-1];
        popv(4);
        return Lappend(nil, v0063, v0039);
    }
// error exit handlers
v0097:
    popv(4);
    return nil;
}



// Code for simpu

static LispObject CC_simpu(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005, v0103;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpu");
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
    v0103 = v0000;
// end of prologue
    stack[-1] = elt(env, 1); // u
    v0005 = v0103;
    stack[0] = qcar(v0005);
    v0005 = v0103;
    v0005 = qcdr(v0005);
    fn = elt(env, 2); // ordn
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    v0005 = Lreverse(nil, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    v0103 = list2star(stack[-1], stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    v0005 = (LispObject)17; // 1
    fn = elt(env, 3); // mksp
    v0103 = (*qfn2(fn))(qenv(fn), v0103, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    v0005 = (LispObject)17; // 1
    v0005 = cons(v0103, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    v0103 = ncons(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0005 = (LispObject)17; // 1
    popv(3);
    return cons(v0103, v0005);
// error exit handlers
v0110:
    popv(3);
    return nil;
}



// Code for specrd!:times

static LispObject CC_specrdTtimes(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0064, v0292;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for specrd:times");
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
    v0064 = stack[-1];
    fn = elt(env, 3); // add_minus
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[-1] = v0064;
    v0064 = stack[0];
    fn = elt(env, 3); // add_minus
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[0] = v0064;
    v0292 = stack[-1];
    v0064 = elt(env, 1); // minus
    if (!consp(v0292)) goto v0102;
    v0292 = qcar(v0292);
    if (!(v0292 == v0064)) goto v0102;
    v0064 = stack[-1];
    v0064 = qcdr(v0064);
    v0064 = qcar(v0064);
    stack[-1] = v0064;
    v0064 = qvalue(elt(env, 2)); // t
    stack[-2] = v0064;
    goto v0102;

v0102:
    v0292 = stack[0];
    v0064 = elt(env, 1); // minus
    if (!consp(v0292)) goto v0094;
    v0292 = qcar(v0292);
    if (!(v0292 == v0064)) goto v0094;
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    v0064 = qcar(v0064);
    stack[0] = v0064;
    v0064 = stack[-2];
    v0064 = (v0064 == nil ? lisp_true : nil);
    stack[-2] = v0064;
    goto v0094;

v0094:
    v0064 = stack[-1];
    if (!(!consp(v0064))) goto v0111;
    v0064 = stack[-1];
    v0064 = Lfloat(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 4); // mkround
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[-1] = v0064;
    goto v0111;

v0111:
    v0064 = stack[0];
    if (!(!consp(v0064))) goto v0075;
    v0064 = stack[0];
    v0064 = Lfloat(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 4); // mkround
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[0] = v0064;
    goto v0075;

v0075:
    v0064 = stack[-2];
    if (v0064 == nil) goto v0017;
    stack[-2] = elt(env, 1); // minus
    v0292 = stack[-1];
    v0064 = stack[0];
    fn = elt(env, 5); // rd!:times
    v0064 = (*qfn2(fn))(qenv(fn), v0292, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    {
        LispObject v0099 = stack[-2];
        popv(4);
        return list2(v0099, v0064);
    }

v0017:
    v0292 = stack[-1];
    v0064 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // rd!:times
        return (*qfn2(fn))(qenv(fn), v0292, v0064);
    }
// error exit handlers
v0098:
    popv(4);
    return nil;
}



// Code for letmtr

static LispObject CC_letmtr(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0185, v0118, v0035;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "letmtr");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for letmtr");
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
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0058;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    stack[-5] = nil;
    v0118 = stack[-2];
    v0185 = elt(env, 1); // mat
    if (!consp(v0118)) goto v0107;
    v0118 = qcar(v0118);
    if (!(v0118 == v0185)) goto v0107;
    v0185 = stack[-4];
    v0185 = qcdr(v0185);
    fn = elt(env, 7); // revlis
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-6];
    stack[-5] = v0185;
    fn = elt(env, 8); // numlis
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-6];
    if (v0185 == nil) goto v0043;
    v0185 = stack[-5];
    v0118 = Llength(nil, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-6];
    v0185 = (LispObject)33; // 2
    v0185 = Lneq(nil, v0118, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-6];
    goto v0111;

v0111:
    if (v0185 == nil) goto v0112;
    v0118 = stack[-4];
    v0185 = elt(env, 6); // hold
    {
        popv(7);
        fn = elt(env, 9); // errpri2
        return (*qfn2(fn))(qenv(fn), v0118, v0185);
    }

v0112:
    v0185 = stack[-2];
    v0118 = qcdr(v0185);
    v0185 = stack[-5];
    v0185 = qcar(v0185);
    fn = elt(env, 10); // nth
    v0118 = (*qfn2(fn))(qenv(fn), v0118, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-6];
    v0185 = stack[-5];
    v0185 = qcdr(v0185);
    v0185 = qcar(v0185);
    fn = elt(env, 11); // pnth
    v0118 = (*qfn2(fn))(qenv(fn), v0118, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-6];
    v0185 = stack[-3];
    v0185 = Lrplaca(nil, v0118, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    v0185 = nil;
    { popv(7); return onevalue(v0185); }

v0043:
    v0185 = qvalue(elt(env, 5)); // t
    goto v0111;

v0107:
    stack[-1] = elt(env, 2); // matrix
    stack[0] = (LispObject)161; // 10
    v0035 = elt(env, 3); // "Matrix"
    v0185 = stack[-4];
    v0118 = qcar(v0185);
    v0185 = elt(env, 4); // "not set"
    v0185 = list3(v0035, v0118, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-6];
    fn = elt(env, 12); // rerror
    v0185 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-6];
    goto v0112;
// error exit handlers
v0232:
    popv(7);
    return nil;
}



// Code for a2vdp

static LispObject CC_a2vdp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0119, v0120, v0039;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for a2vdp");
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
    v0039 = v0000;
// end of prologue
    v0120 = v0039;
    v0119 = (LispObject)1; // 0
    if (v0120 == v0119) goto v0081;
    v0119 = v0039;
    v0119 = (v0119 == nil ? lisp_true : nil);
    goto v0125;

v0125:
    if (v0119 == nil) goto v0011;
    stack[-2] = elt(env, 2); // vdp
    stack[-1] = qvalue(elt(env, 3)); // nil
    v0120 = qvalue(elt(env, 3)); // nil
    v0119 = (LispObject)17; // 1
    stack[0] = cons(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-3];
    v0120 = qvalue(elt(env, 3)); // nil
    v0119 = qvalue(elt(env, 3)); // nil
    v0119 = list2(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    {
        LispObject v0097 = stack[-2];
        LispObject v0063 = stack[-1];
        LispObject v0131 = stack[0];
        popv(4);
        return list3star(v0097, v0063, v0131, v0119);
    }

v0011:
    v0119 = v0039;
    fn = elt(env, 4); // a2dip
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-3];
    v0120 = v0119;
    stack[-2] = elt(env, 2); // vdp
    v0119 = v0120;
    stack[-1] = qcar(v0119);
    v0119 = v0120;
    v0119 = qcdr(v0119);
    stack[0] = qcar(v0119);
    v0119 = qvalue(elt(env, 3)); // nil
    v0119 = list2(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    {
        LispObject v0064 = stack[-2];
        LispObject v0292 = stack[-1];
        LispObject v0132 = stack[0];
        popv(4);
        return list3star(v0064, v0292, v0132, v0119);
    }

v0081:
    v0119 = qvalue(elt(env, 1)); // t
    goto v0125;
// error exit handlers
v0147:
    popv(4);
    return nil;
}



// Code for remove_least_item

static LispObject CC_remove_least_item(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0013, v0094;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove_least_item");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0013 = v0000;
// end of prologue

v0023:
    v0094 = v0013;
    v0094 = qcdr(v0094);
    if (v0094 == nil) goto v0125;
    v0094 = v0013;
    v0094 = qcdr(v0094);
    v0094 = qcar(v0094);
    v0094 = qcdr(v0094);
    if (v0094 == nil) goto v0171;
    v0013 = qcdr(v0013);
    v0013 = qcar(v0013);
    goto v0023;

v0171:
    {
        fn = elt(env, 2); // remove_root_item
        return (*qfn1(fn))(qenv(fn), v0013);
    }

v0125:
    v0013 = elt(env, 1); // "How did we get here?"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(qenv(fn), v0013);
    }
}



// Code for mkassign

static LispObject CC_mkassign(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0024, v0029, v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkassign");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0024 = v0001;
    v0029 = v0000;
// end of prologue
    v0040 = elt(env, 1); // setq
    return list3(v0040, v0029, v0024);
}



// Code for find_bubles_coeff

static LispObject CC_find_bubles_coeff(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0121, v0148, v0107, v0018;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_bubles_coeff");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find_bubles_coeff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0121 = v0058;
    v0148 = v0001;
    v0107 = v0000;
// end of prologue
    v0018 = v0107;
    v0107 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // find_bubles1_coeff
        return (*qfnn(fn))(qenv(fn), 4, v0018, v0107, v0148, v0121);
    }
}



setup_type const u34_setup[] =
{
    {"list2vect*",              too_few_2,      CC_list2vectH, wrong_no_2},
    {"noncomfree",              CC_noncomfree,  too_many_1,    wrong_no_1},
    {"extadd",                  too_few_2,      CC_extadd,     wrong_no_2},
    {"isimp1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_isimp1},
    {"iv_cutcongs2",            too_few_2,      CC_iv_cutcongs2,wrong_no_2},
    {"vunion",                  too_few_2,      CC_vunion,     wrong_no_2},
    {"ofsf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwupdknowl},
    {"prsubsetrd",              CC_prsubsetrd,  too_many_1,    wrong_no_1},
    {"**s2a",                   too_few_2,      CC_HHs2a,      wrong_no_2},
    {"insertocc",               too_few_2,      CC_insertocc,  wrong_no_2},
    {"xreadlist",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreadlist},
    {"numprintlen",             CC_numprintlen, too_many_1,    wrong_no_1},
    {"mk_binding",              too_few_2,      CC_mk_binding, wrong_no_2},
    {"splitup",                 too_few_2,      CC_splitup,    wrong_no_2},
    {"nonmult",                 CC_nonmult,     too_many_1,    wrong_no_1},
    {"min2-order",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_min2Korder},
    {"rl_sacatlp",              too_few_2,      CC_rl_sacatlp, wrong_no_2},
    {"fctrf",                   CC_fctrf,       too_many_1,    wrong_no_1},
    {"ofsf_anegrel",            CC_ofsf_anegrel,too_many_1,    wrong_no_1},
    {"ciom",                    CC_ciom,        too_many_1,    wrong_no_1},
    {"countof",                 too_few_2,      CC_countof,    wrong_no_2},
    {"ieval",                   CC_ieval,       too_many_1,    wrong_no_1},
    {"*rn2rd",                  CC_Hrn2rd,      too_many_1,    wrong_no_1},
    {"findoptrow",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_findoptrow},
    {"new_simpexpt",            CC_new_simpexpt,too_many_1,    wrong_no_1},
    {"exdf0",                   CC_exdf0,       too_many_1,    wrong_no_1},
    {"listpri",                 CC_listpri,     too_many_1,    wrong_no_1},
    {"physoppri",               CC_physoppri,   too_many_1,    wrong_no_1},
    {"set-weights",             CC_setKweights, too_many_1,    wrong_no_1},
    {"cl_bnfsimpl",             too_few_2,      CC_cl_bnfsimpl,wrong_no_2},
    {"lto_sgnchg1",             CC_lto_sgnchg1, too_many_1,    wrong_no_1},
    {"cgp_greenp",              CC_cgp_greenp,  too_many_1,    wrong_no_1},
    {"conditionml",             CC_conditionml, too_many_1,    wrong_no_1},
    {"consrecip",               CC_consrecip,   too_many_1,    wrong_no_1},
    {"reduce-columns",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKcolumns},
    {"prepreform1",             too_few_2,      CC_prepreform1,wrong_no_2},
    {"vecsimp*",                CC_vecsimpH,    too_many_1,    wrong_no_1},
    {"*n2a",                    CC_Hn2a,        too_many_1,    wrong_no_1},
    {"prepsq*0",                too_few_2,      CC_prepsqH0,   wrong_no_2},
    {"subtractinds",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_subtractinds},
    {"expf",                    too_few_2,      CC_expf,       wrong_no_2},
    {"replace-next",            too_few_2,      CC_replaceKnext,wrong_no_2},
    {"pasf_or",                 CC_pasf_or,     too_many_1,    wrong_no_1},
    {"integralir",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_integralir},
    {"simpu",                   CC_simpu,       too_many_1,    wrong_no_1},
    {"specrd:times",            too_few_2,      CC_specrdTtimes,wrong_no_2},
    {"letmtr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr},
    {"a2vdp",                   CC_a2vdp,       too_many_1,    wrong_no_1},
    {"remove_least_item",       CC_remove_least_item,too_many_1,wrong_no_1},
    {"mkassign",                too_few_2,      CC_mkassign,   wrong_no_2},
    {"find_bubles_coeff",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles_coeff},
    {NULL, (one_args *)"u34", (two_args *)"21948 8881704 3197114", 0}
};

// end of generated code
