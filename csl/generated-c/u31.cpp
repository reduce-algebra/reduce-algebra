
// $destdir\u31.c        Machine generated C code

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



// Code for lengthreval

static LispObject CC_lengthreval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026, v0027, v0028;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthreval");
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
    stack[0] = nil;
    v0026 = stack[-1];
    v0027 = Llength(nil, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0026 = (LispObject)17; // 1
    if (v0027 == v0026) goto v0030;
    v0028 = elt(env, 1); // alg
    v0027 = (LispObject)177; // 11
    v0026 = elt(env, 2); // "LENGTH called with wrong number of arguments"
    fn = elt(env, 9); // rerror
    v0026 = (*qfnn(fn))(qenv(fn), 3, v0028, v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    goto v0030;

v0030:
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    stack[-1] = v0026;
    v0026 = stack[-1];
    if (!(symbolp(v0026))) goto v0031;
    v0026 = stack[-1];
    fn = elt(env, 10); // arrayp
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    if (v0026 == nil) goto v0031;
    v0028 = elt(env, 3); // list
    v0027 = stack[-1];
    v0026 = elt(env, 4); // dimension
    v0026 = get(v0027, v0026);
    popv(4);
    return cons(v0028, v0026);

v0031:
    v0026 = stack[-1];
    fn = elt(env, 11); // aeval
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    stack[-2] = v0026;
    v0026 = stack[-2];
    fn = elt(env, 12); // getrtype
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0028 = v0026;
    if (v0026 == nil) goto v0032;
    v0027 = v0028;
    v0026 = elt(env, 5); // lengthfn
    v0026 = get(v0027, v0026);
    env = stack[-3];
    stack[0] = v0026;
    if (v0026 == nil) goto v0032;
    v0027 = stack[0];
    v0026 = stack[-2];
        popv(4);
        return Lapply1(nil, v0027, v0026);

v0032:
    v0026 = stack[-2];
    if (!consp(v0026)) goto v0033;
    v0026 = stack[-2];
    v0026 = qcar(v0026);
    if (symbolp(v0026)) goto v0034;
    v0026 = qvalue(elt(env, 6)); // t
    goto v0035;

v0035:
    if (v0026 == nil) goto v0036;
    v0026 = v0028;
    if (v0026 == nil) goto v0037;
    v0026 = elt(env, 7); // "LENGTH not defined for argument of type"
    v0027 = v0028;
    v0026 = list2(v0026, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    fn = elt(env, 13); // lprie
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    goto v0038;

v0038:
    v0026 = nil;
    { popv(4); return onevalue(v0026); }

v0037:
    v0027 = stack[-1];
    v0026 = elt(env, 8); // "LENGTH argument"
    fn = elt(env, 14); // typerr
    v0026 = (*qfn2(fn))(qenv(fn), v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    goto v0038;

v0036:
    v0027 = stack[0];
    v0026 = stack[-2];
    v0026 = qcdr(v0026);
        popv(4);
        return Lapply1(nil, v0027, v0026);

v0034:
    v0026 = stack[-2];
    v0027 = qcar(v0026);
    v0026 = elt(env, 5); // lengthfn
    v0026 = get(v0027, v0026);
    env = stack[-3];
    stack[0] = v0026;
    v0026 = (v0026 == nil ? lisp_true : nil);
    goto v0035;

v0033:
    v0026 = (LispObject)17; // 1
    { popv(4); return onevalue(v0026); }
// error exit handlers
v0029:
    popv(4);
    return nil;
}



// Code for build!-null!-vector

static LispObject CC_buildKnullKvector(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051, v0015, v0016, v0052, v0053, v0054, v0055;
    LispObject v0003, v0041, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "build-null-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for build-null-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0052 = v0003;
    v0053 = v0041;
    v0054 = v0000;
// end of prologue
    v0050 = (LispObject)17; // 1
    v0055 = v0050;
    goto v0056;

v0056:
    v0050 = v0054;
    v0051 = (LispObject)((int32_t)(v0050) - 0x10);
    v0050 = v0055;
    v0050 = (LispObject)(int32_t)((int32_t)v0051 - (int32_t)v0050 + TAG_FIXNUM);
    v0050 = ((intptr_t)(v0050) < 0 ? lisp_true : nil);
    if (v0050 == nil) goto v0057;
    v0015 = v0053;
    v0051 = v0054;
    v0050 = (LispObject)17; // 1
    *(LispObject *)((char *)v0015 + (CELL-TAG_VECTOR) + ((int32_t)v0051/(16/CELL))) = v0050;
    v0050 = v0053;
    v0051 = v0054;
    return cons(v0050, v0051);

v0057:
    v0016 = v0053;
    v0015 = v0055;
    v0051 = v0052;
    v0050 = v0055;
    v0051 = *(LispObject *)((char *)v0051 + (CELL-TAG_VECTOR) + ((int32_t)v0050/(16/CELL)));
    v0050 = v0054;
    v0050 = *(LispObject *)((char *)v0051 + (CELL-TAG_VECTOR) + ((int32_t)v0050/(16/CELL)));
    *(LispObject *)((char *)v0016 + (CELL-TAG_VECTOR) + ((int32_t)v0015/(16/CELL))) = v0050;
    v0050 = v0055;
    v0050 = (LispObject)((int32_t)(v0050) + 0x10);
    v0055 = v0050;
    goto v0056;
}



// Code for makeqn!-maybe

static LispObject CC_makeqnKmaybe(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0059, v0060, v0061;
    LispObject v0003, v0041, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeqn-maybe");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makeqn-maybe");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0059 = v0003;
    v0060 = v0041;
    v0061 = v0000;
// end of prologue
    if (!(v0059 == nil)) return onevalue(v0060);
    v0059 = elt(env, 1); // equal
    return list3(v0059, v0061, v0060);
}



// Code for mk!+mat!+plus!+mat

static LispObject CC_mkLmatLplusLmat(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0115, v0116, v0117;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+mat+plus+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-10] = v0041;
    stack[-11] = v0000;
// end of prologue
    v0115 = stack[-11];
    fn = elt(env, 6); // matrix!+p
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    if (!(v0115 == nil)) goto v0119;
    v0115 = elt(env, 1); // "no matrix in add"
    fn = elt(env, 7); // rederr
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    goto v0119;

v0119:
    v0115 = stack[-10];
    fn = elt(env, 6); // matrix!+p
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    if (!(v0115 == nil)) goto v0058;
    v0115 = elt(env, 1); // "no matrix in add"
    fn = elt(env, 7); // rederr
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    goto v0058;

v0058:
    v0115 = stack[-11];
    fn = elt(env, 8); // get!+col!+nr
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    stack[-12] = v0115;
    v0115 = stack[-11];
    fn = elt(env, 9); // get!+row!+nr
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    stack[-9] = v0115;
    stack[0] = stack[-12];
    v0115 = stack[-10];
    fn = elt(env, 8); // get!+col!+nr
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    if (equal(stack[0], v0115)) goto v0043;
    v0115 = elt(env, 2); // "wrong dimensions in add"
    fn = elt(env, 7); // rederr
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    goto v0043;

v0043:
    stack[0] = stack[-9];
    v0115 = stack[-10];
    fn = elt(env, 9); // get!+row!+nr
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    if (equal(stack[0], v0115)) goto v0046;
    v0115 = elt(env, 2); // "wrong dimensions in add"
    fn = elt(env, 7); // rederr
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    goto v0046;

v0046:
    v0115 = (LispObject)17; // 1
    stack[-8] = v0115;
    v0116 = stack[-9];
    v0115 = stack[-8];
    v0115 = difference2(v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lminusp(nil, v0115);
    env = stack[-13];
    if (v0115 == nil) goto v0120;
    v0115 = qvalue(elt(env, 3)); // nil
    { popv(14); return onevalue(v0115); }

v0120:
    v0115 = (LispObject)17; // 1
    stack[-4] = v0115;
    v0116 = stack[-12];
    v0115 = stack[-4];
    v0115 = difference2(v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lminusp(nil, v0115);
    env = stack[-13];
    if (v0115 == nil) goto v0121;
    v0115 = qvalue(elt(env, 3)); // nil
    goto v0122;

v0122:
    v0115 = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    stack[-6] = v0115;
    stack[-7] = v0115;
    goto v0123;

v0123:
    v0115 = stack[-8];
    v0115 = add1(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    stack[-8] = v0115;
    v0116 = stack[-9];
    v0115 = stack[-8];
    v0115 = difference2(v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lminusp(nil, v0115);
    env = stack[-13];
    if (!(v0115 == nil)) { LispObject res = stack[-7]; popv(14); return onevalue(res); }
    stack[-5] = stack[-6];
    v0115 = (LispObject)17; // 1
    stack[-4] = v0115;
    v0116 = stack[-12];
    v0115 = stack[-4];
    v0115 = difference2(v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lminusp(nil, v0115);
    env = stack[-13];
    if (v0115 == nil) goto v0124;
    v0115 = qvalue(elt(env, 3)); // nil
    goto v0125;

v0125:
    v0115 = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lrplacd(nil, stack[-5], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = stack[-6];
    v0115 = qcdr(v0115);
    stack[-6] = v0115;
    goto v0123;

v0124:
    v0117 = stack[-11];
    v0116 = stack[-8];
    v0115 = stack[-4];
    fn = elt(env, 10); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0117, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0117 = stack[-10];
    v0116 = stack[-8];
    v0115 = stack[-4];
    fn = elt(env, 10); // get!+mat!+entry
    v0115 = (*qfnn(fn))(qenv(fn), 3, v0117, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    fn = elt(env, 11); // addsq
    v0115 = (*qfn2(fn))(qenv(fn), stack[0], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0116 = v0115;
    v0115 = qvalue(elt(env, 4)); // t
    stack[0] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0115; // !*sub2
    v0115 = v0116;
    fn = elt(env, 12); // subs2
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-13];
    v0116 = v0115;
    qvalue(elt(env, 5)) = stack[0]; // !*sub2
    v0115 = v0116;
    v0115 = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    stack[-2] = v0115;
    stack[-3] = v0115;
    goto v0127;

v0127:
    v0115 = stack[-4];
    v0115 = add1(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    stack[-4] = v0115;
    v0116 = stack[-12];
    v0115 = stack[-4];
    v0115 = difference2(v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lminusp(nil, v0115);
    env = stack[-13];
    if (v0115 == nil) goto v0128;
    v0115 = stack[-3];
    goto v0125;

v0128:
    stack[-1] = stack[-2];
    v0117 = stack[-11];
    v0116 = stack[-8];
    v0115 = stack[-4];
    fn = elt(env, 10); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0117, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0117 = stack[-10];
    v0116 = stack[-8];
    v0115 = stack[-4];
    fn = elt(env, 10); // get!+mat!+entry
    v0115 = (*qfnn(fn))(qenv(fn), 3, v0117, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    fn = elt(env, 11); // addsq
    v0115 = (*qfn2(fn))(qenv(fn), stack[0], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0116 = v0115;
    v0115 = qvalue(elt(env, 4)); // t
    stack[0] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0115; // !*sub2
    v0115 = v0116;
    fn = elt(env, 12); // subs2
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-13];
    v0116 = v0115;
    qvalue(elt(env, 5)) = stack[0]; // !*sub2
    v0115 = v0116;
    v0115 = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lrplacd(nil, stack[-1], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = stack[-2];
    v0115 = qcdr(v0115);
    stack[-2] = v0115;
    goto v0127;

v0121:
    v0117 = stack[-11];
    v0116 = stack[-8];
    v0115 = stack[-4];
    fn = elt(env, 10); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0117, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0117 = stack[-10];
    v0116 = stack[-8];
    v0115 = stack[-4];
    fn = elt(env, 10); // get!+mat!+entry
    v0115 = (*qfnn(fn))(qenv(fn), 3, v0117, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    fn = elt(env, 11); // addsq
    v0115 = (*qfn2(fn))(qenv(fn), stack[0], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0116 = v0115;
    v0115 = qvalue(elt(env, 4)); // t
    stack[0] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0115; // !*sub2
    v0115 = v0116;
    fn = elt(env, 12); // subs2
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-13];
    v0116 = v0115;
    qvalue(elt(env, 5)) = stack[0]; // !*sub2
    v0115 = v0116;
    v0115 = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    stack[-2] = v0115;
    stack[-3] = v0115;
    goto v0131;

v0131:
    v0115 = stack[-4];
    v0115 = add1(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    stack[-4] = v0115;
    v0116 = stack[-12];
    v0115 = stack[-4];
    v0115 = difference2(v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lminusp(nil, v0115);
    env = stack[-13];
    if (v0115 == nil) goto v0132;
    v0115 = stack[-3];
    goto v0122;

v0132:
    stack[-1] = stack[-2];
    v0117 = stack[-11];
    v0116 = stack[-8];
    v0115 = stack[-4];
    fn = elt(env, 10); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0117, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0117 = stack[-10];
    v0116 = stack[-8];
    v0115 = stack[-4];
    fn = elt(env, 10); // get!+mat!+entry
    v0115 = (*qfnn(fn))(qenv(fn), 3, v0117, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    fn = elt(env, 11); // addsq
    v0115 = (*qfn2(fn))(qenv(fn), stack[0], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0116 = v0115;
    v0115 = qvalue(elt(env, 4)); // t
    stack[0] = qvalue(elt(env, 5)); // !*sub2
    qvalue(elt(env, 5)) = v0115; // !*sub2
    v0115 = v0116;
    fn = elt(env, 12); // subs2
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-13];
    v0116 = v0115;
    qvalue(elt(env, 5)) = stack[0]; // !*sub2
    v0115 = v0116;
    v0115 = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = Lrplacd(nil, stack[-1], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-13];
    v0115 = stack[-2];
    v0115 = qcdr(v0115);
    stack[-2] = v0115;
    goto v0131;
// error exit handlers
v0133:
    env = stack[-13];
    qvalue(elt(env, 5)) = stack[0]; // !*sub2
    popv(14);
    return nil;
v0130:
    env = stack[-13];
    qvalue(elt(env, 5)) = stack[0]; // !*sub2
    popv(14);
    return nil;
v0129:
    env = stack[-13];
    qvalue(elt(env, 5)) = stack[0]; // !*sub2
    popv(14);
    return nil;
v0126:
    env = stack[-13];
    qvalue(elt(env, 5)) = stack[0]; // !*sub2
    popv(14);
    return nil;
v0118:
    popv(14);
    return nil;
}



// Code for pasf_premf

static LispObject CC_pasf_premf(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0025, v0136;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_premf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0041;
    v0025 = v0000;
// end of prologue
    v0136 = v0025;
    v0025 = stack[0];
    fn = elt(env, 1); // remf
    v0136 = (*qfn2(fn))(qenv(fn), v0136, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    v0025 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // pasf_premf1
        return (*qfn2(fn))(qenv(fn), v0136, v0025);
    }
// error exit handlers
v0048:
    popv(2);
    return nil;
}



// Code for vdp_make

static LispObject CC_vdp_make(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0061, v0057, v0023;
    LispObject v0003, v0041, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdp_make");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_make");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0003,v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0041,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0061 = v0003;
    v0057 = v0041;
    v0023 = v0000;
// end of prologue
    stack[-2] = elt(env, 1); // vdp
    stack[-1] = v0057;
    stack[0] = v0023;
    v0057 = v0061;
    v0061 = qvalue(elt(env, 2)); // nil
    v0061 = list2(v0057, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    {
        LispObject v0139 = stack[-2];
        LispObject v0031 = stack[-1];
        LispObject v0044 = stack[0];
        popv(3);
        return list3star(v0139, v0031, v0044, v0061);
    }
// error exit handlers
v0138:
    popv(3);
    return nil;
}



// Code for matrixelems

static LispObject CC_matrixelems(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0022;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixelems");
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
    v0022 = nil;
    goto v0140;

v0140:
    v0021 = stack[0];
    if (v0021 == nil) goto v0060;
    v0021 = stack[0];
    v0021 = qcar(v0021);
    v0021 = qcdr(v0021);
    v0021 = qcdr(v0021);
    v0021 = cons(v0021, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    v0022 = v0021;
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    stack[0] = v0021;
    goto v0140;

v0060:
    v0021 = v0022;
    {
        popv(2);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0021);
    }
// error exit handlers
v0138:
    popv(2);
    return nil;
}



// Code for transmat1

static LispObject CC_transmat1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0096, v0157, v0158, v0159;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for transmat1");
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
    stack[-6] = v0000;
// end of prologue
    v0096 = stack[-6];
    v0096 = qcar(v0096);
    fn = elt(env, 6); // aeval
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    v0096 = qcdr(v0096);
    stack[0] = v0096;
    v0096 = (LispObject)1; // 0
    stack[-5] = v0096;
    v0096 = (LispObject)1; // 0
    stack[-4] = v0096;
    v0096 = stack[-6];
    v0096 = qcar(v0096);
    fn = elt(env, 6); // aeval
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    fn = elt(env, 7); // matlength
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    v0096 = qcdr(v0096);
    v0157 = v0096;
    stack[-1] = qcar(v0157);
    v0157 = elt(env, 1); // spm
    v0096 = cons(v0157, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    fn = elt(env, 8); // mkempspmat
    v0096 = (*qfn2(fn))(qenv(fn), stack[-1], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    stack[-7] = v0096;
    v0096 = qvalue(elt(env, 2)); // nil
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    stack[-2] = v0096;
    v0096 = stack[0];
    stack[-1] = v0096;
    goto v0045;

v0045:
    v0096 = stack[-1];
    if (v0096 == nil) goto v0161;
    v0096 = stack[-1];
    v0096 = qcar(v0096);
    stack[0] = v0096;
    v0096 = stack[-5];
    v0096 = add1(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    stack[-5] = v0096;
    v0096 = stack[0];
    stack[0] = v0096;
    goto v0162;

v0162:
    v0096 = stack[0];
    if (v0096 == nil) goto v0032;
    v0096 = stack[0];
    v0096 = qcar(v0096);
    stack[-3] = v0096;
    v0096 = stack[-4];
    v0096 = add1(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    stack[-4] = v0096;
    v0157 = stack[-3];
    v0096 = (LispObject)1; // 0
    if (v0157 == v0096) goto v0055;
    v0158 = stack[-4];
    v0157 = stack[-3];
    v0096 = stack[-2];
    v0096 = acons(v0158, v0157, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    stack[-2] = v0096;
    goto v0055;

v0055:
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    stack[0] = v0096;
    goto v0162;

v0032:
    v0096 = stack[-2];
    v0096 = Lreverse(nil, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    stack[-2] = v0096;
    stack[0] = stack[-2];
    v0096 = qvalue(elt(env, 2)); // nil
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    if (equal(stack[0], v0096)) goto v0163;
    v0157 = stack[-7];
    v0096 = stack[-5];
    v0159 = list2(v0157, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    v0158 = stack[-2];
    v0157 = stack[-7];
    v0096 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 9); // letmtr3
    v0096 = (*qfnn(fn))(qenv(fn), 4, v0159, v0158, v0157, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    goto v0163;

v0163:
    v0096 = (LispObject)1; // 0
    stack[-4] = v0096;
    v0096 = qvalue(elt(env, 2)); // nil
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    stack[-2] = v0096;
    v0096 = stack[-1];
    v0096 = qcdr(v0096);
    stack[-1] = v0096;
    goto v0045;

v0161:
    v0096 = stack[-6];
    stack[-1] = qcar(v0096);
    stack[0] = elt(env, 3); // avalue
    v0157 = elt(env, 4); // sparse
    v0096 = stack[-7];
    v0096 = list2(v0157, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    v0096 = Lputprop(nil, 3, stack[-1], stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-8];
    v0096 = stack[-6];
    v0158 = qcar(v0096);
    v0157 = elt(env, 5); // rtype
    v0096 = elt(env, 4); // sparse
    v0096 = Lputprop(nil, 3, v0158, v0157, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    v0096 = nil;
    { popv(9); return onevalue(v0096); }
// error exit handlers
v0160:
    popv(9);
    return nil;
}



// Code for dipcontevmin

static LispObject CC_dipcontevmin(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0051, v0015, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipcontevmin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0041;
    stack[-1] = v0000;
// end of prologue
    v0016 = nil;
    goto v0030;

v0030:
    v0051 = stack[-1];
    if (v0051 == nil) goto v0168;
    v0051 = stack[0];
    if (v0051 == nil) goto v0168;
    v0051 = stack[-1];
    v0015 = qcar(v0051);
    v0051 = stack[0];
    v0051 = qcar(v0051);
    if (((int32_t)(v0015)) < ((int32_t)(v0051))) goto v0057;
    v0051 = stack[0];
    v0051 = qcar(v0051);
    goto v0048;

v0048:
    v0015 = v0016;
    v0051 = cons(v0051, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0016 = v0051;
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    stack[-1] = v0051;
    v0051 = stack[0];
    v0051 = qcdr(v0051);
    stack[0] = v0051;
    goto v0030;

v0057:
    v0051 = stack[-1];
    v0051 = qcar(v0051);
    goto v0048;

v0168:
    v0051 = v0016;
    if (v0051 == nil) goto v0043;
    v0015 = (LispObject)1; // 0
    v0051 = v0016;
    v0051 = qcar(v0051);
    if (!(v0015 == v0051)) goto v0043;
    v0051 = v0016;
    v0051 = qcdr(v0051);
    v0016 = v0051;
    goto v0168;

v0043:
    v0051 = v0016;
        popv(3);
        return Lnreverse(nil, v0051);
// error exit handlers
v0054:
    popv(3);
    return nil;
}



// Code for f2dip1

static LispObject CC_f2dip1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0175, v0176, v0177, v0178, v0034;
    LispObject fn;
    LispObject v0003, v0041, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "f2dip1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for f2dip1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0003,v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0041,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0041;
    stack[-2] = v0000;
// end of prologue
    v0175 = stack[-2];
    if (v0175 == nil) goto v0047;
    v0175 = stack[-2];
    if (!consp(v0175)) goto v0137;
    v0175 = stack[-2];
    v0175 = qcar(v0175);
    v0175 = (consp(v0175) ? nil : lisp_true);
    goto v0179;

v0179:
    if (v0175 == nil) goto v0180;
    v0175 = stack[0];
    v0175 = (is_number(v0175) ? lisp_true : nil);
    if (!(v0175 == nil)) goto v0153;
    v0175 = stack[0];
    fn = elt(env, 3); // f2dip11
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-4];
    goto v0153;

v0153:
    v0175 = stack[-2];
    fn = elt(env, 4); // bcfd
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-4];
    fn = elt(env, 5); // bcprod
    v0175 = (*qfn2(fn))(qenv(fn), stack[0], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-4];
    v0176 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0011 = stack[-1];
        popv(5);
        return list2star(v0011, v0175, v0176);
    }

v0180:
    v0175 = stack[-2];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0034 = qcar(v0175);
    v0175 = stack[-2];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0178 = qcdr(v0175);
    v0175 = stack[-2];
    v0175 = qcar(v0175);
    v0177 = qcdr(v0175);
    v0176 = stack[-1];
    v0175 = stack[0];
    fn = elt(env, 6); // f2dip2
    stack[-3] = (*qfnn(fn))(qenv(fn), 5, v0034, v0178, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-4];
    v0175 = stack[-2];
    v0177 = qcdr(v0175);
    v0176 = stack[-1];
    v0175 = stack[0];
    v0175 = CC_f2dip1(env, 3, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-4];
    {
        LispObject v0012 = stack[-3];
        popv(5);
        fn = elt(env, 7); // dipsum
        return (*qfn2(fn))(qenv(fn), v0012, v0175);
    }

v0137:
    v0175 = qvalue(elt(env, 2)); // t
    goto v0179;

v0047:
    v0175 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0175); }
// error exit handlers
v0181:
    popv(5);
    return nil;
}



// Code for contposp

static LispObject CC_contposp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0049, v0059;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0049 = v0000;
// end of prologue

v0182:
    v0059 = v0049;
    if (v0059 == nil) goto v0004;
    v0059 = v0049;
    v0059 = qcar(v0059);
    if (!consp(v0059)) goto v0119;
    v0049 = qvalue(elt(env, 2)); // nil
    return onevalue(v0049);

v0119:
    v0049 = qcdr(v0049);
    goto v0182;

v0004:
    v0049 = qvalue(elt(env, 1)); // t
    return onevalue(v0049);
}



// Code for indxsymp

static LispObject CC_indxsymp(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0167, v0155;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indxsymp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0041;
    stack[-1] = v0000;
// end of prologue

v0182:
    v0167 = stack[0];
    if (v0167 == nil) goto v0140;
    v0167 = stack[0];
    v0155 = qcar(v0167);
    v0167 = stack[-1];
    v0167 = Lapply1(nil, v0155, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    if (v0167 == nil) goto v0179;
    v0155 = stack[-1];
    v0167 = stack[0];
    v0167 = qcdr(v0167);
    stack[-1] = v0155;
    stack[0] = v0167;
    goto v0182;

v0179:
    v0167 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0167); }

v0140:
    v0167 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0167); }
// error exit handlers
v0114:
    popv(3);
    return nil;
}



// Code for getphystypeexpt

static LispObject CC_getphystypeexpt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0022;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystypeexpt");
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
    v0021 = stack[0];
    fn = elt(env, 3); // getphystypecar
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    v0022 = v0021;
    v0021 = v0022;
    if (v0021 == nil) goto v0134;
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = qcar(v0021);
    if (!(is_number(v0021))) { popv(2); return onevalue(v0022); }
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = qcar(v0021);
    v0021 = Levenp(nil, v0021);
    env = stack[-1];
    if (v0021 == nil) { popv(2); return onevalue(v0022); }
    v0021 = elt(env, 2); // scalar
    { popv(2); return onevalue(v0021); }

v0134:
    v0021 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0021); }
// error exit handlers
v0138:
    popv(2);
    return nil;
}



// Code for calc_coeffmap_

static LispObject CC_calc_coeffmap_(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0045, v0046, v0018;
    LispObject fn;
    LispObject v0003, v0041, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "calc_coeffmap_");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_coeffmap_");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0003,v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0041,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0003;
    stack[-2] = v0041;
    v0045 = v0000;
// end of prologue
    v0046 = v0045;
    v0045 = stack[-1];
    fn = elt(env, 2); // calc_map_
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-4];
    v0018 = v0045;
    v0046 = v0018;
    v0045 = (LispObject)1; // 0
    if (v0046 == v0045) goto v0056;
    stack[-3] = elt(env, 1); // times
    stack[0] = v0018;
    v0046 = stack[-2];
    v0045 = stack[-1];
    fn = elt(env, 3); // calc_coeff
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    {
        LispObject v0188 = stack[-3];
        LispObject v0019 = stack[0];
        popv(5);
        return list2star(v0188, v0019, v0045);
    }

v0056:
    v0045 = (LispObject)1; // 0
    { popv(5); return onevalue(v0045); }
// error exit handlers
v0187:
    popv(5);
    return nil;
}



// Code for s!:prinl1

static LispObject CC_sTprinl1(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0198, v0090, v0091;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s:prinl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0041;
    stack[-3] = v0000;
// end of prologue
    v0198 = qvalue(elt(env, 1)); // !*print!-level!*
    v0198 = integerp(v0198);
    if (v0198 == nil) goto v0134;
    v0090 = stack[-2];
    v0198 = qvalue(elt(env, 1)); // !*print!-level!*
    v0198 = (LispObject)greaterp2(v0090, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0198 = v0198 ? lisp_true : nil;
    env = stack[-5];
    if (v0198 == nil) goto v0134;
    v0198 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0198); }

v0134:
    v0198 = (LispObject)1; // 0
    stack[-4] = v0198;
    goto v0152;

v0152:
    v0198 = stack[-3];
    if (!consp(v0198)) goto v0139;
    v0198 = qvalue(elt(env, 2)); // nil
    goto v0138;

v0138:
    if (v0198 == nil) goto v0180;
    v0198 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0198); }

v0180:
    v0090 = stack[-3];
    v0198 = qvalue(elt(env, 3)); // !*prinl!-visited!-nodes!*
    fn = elt(env, 7); // gethash
    v0198 = (*qfn2(fn))(qenv(fn), v0090, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0090 = v0198;
    if (v0198 == nil) goto v0171;
    v0198 = (LispObject)1; // 0
    if (!(v0090 == v0198)) goto v0200;
    v0198 = qvalue(elt(env, 4)); // !*prinl!-index!*
    v0198 = add1(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    qvalue(elt(env, 4)) = v0198; // !*prinl!-index!*
    v0091 = stack[-3];
    v0090 = qvalue(elt(env, 3)); // !*prinl!-visited!-nodes!*
    v0198 = qvalue(elt(env, 4)); // !*prinl!-index!*
    fn = elt(env, 8); // puthash
    v0198 = (*qfnn(fn))(qenv(fn), 3, v0091, v0090, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    goto v0200;

v0200:
    v0198 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0198); }

v0171:
    v0091 = stack[-3];
    v0090 = qvalue(elt(env, 3)); // !*prinl!-visited!-nodes!*
    v0198 = (LispObject)1; // 0
    fn = elt(env, 8); // puthash
    v0198 = (*qfnn(fn))(qenv(fn), 3, v0091, v0090, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0198 = stack[-3];
    fn = elt(env, 9); // simple!-vector!-p
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    if (v0198 == nil) goto v0201;
    v0198 = qvalue(elt(env, 5)); // !*print!-array!*
    if (v0198 == nil) goto v0023;
    v0198 = stack[-3];
    v0198 = Lupbv(nil, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-4] = v0198;
    v0198 = qvalue(elt(env, 6)); // !*print!-length!*
    v0198 = integerp(v0198);
    if (v0198 == nil) goto v0109;
    v0090 = qvalue(elt(env, 6)); // !*print!-length!*
    v0198 = stack[-4];
    v0198 = (LispObject)lessp2(v0090, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0198 = v0198 ? lisp_true : nil;
    env = stack[-5];
    if (v0198 == nil) goto v0109;
    v0198 = qvalue(elt(env, 6)); // !*print!-length!*
    stack[-4] = v0198;
    goto v0109;

v0109:
    v0198 = (LispObject)1; // 0
    stack[-1] = v0198;
    goto v0028;

v0028:
    v0090 = stack[-4];
    v0198 = stack[-1];
    v0198 = difference2(v0090, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0198 = Lminusp(nil, v0198);
    env = stack[-5];
    if (!(v0198 == nil)) goto v0023;
    v0090 = stack[-3];
    v0198 = stack[-1];
    stack[0] = *(LispObject *)((char *)v0090 + (CELL-TAG_VECTOR) + ((int32_t)v0198/(16/CELL)));
    v0198 = stack[-2];
    v0198 = add1(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0198 = CC_sTprinl1(env, stack[0], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0198 = stack[-1];
    v0198 = add1(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-1] = v0198;
    goto v0028;

v0023:
    v0198 = nil;
    { popv(6); return onevalue(v0198); }

v0201:
    v0198 = stack[-3];
    if (!consp(v0198)) goto v0023;
    v0198 = stack[-3];
    stack[0] = qcar(v0198);
    v0198 = stack[-2];
    v0198 = add1(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0198 = CC_sTprinl1(env, stack[0], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0198 = qvalue(elt(env, 6)); // !*print!-length!*
    v0198 = integerp(v0198);
    if (v0198 == nil) goto v0202;
    v0198 = stack[-4];
    v0090 = add1(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    stack[-4] = v0090;
    v0198 = qvalue(elt(env, 6)); // !*print!-length!*
    v0198 = (LispObject)greaterp2(v0090, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0198 = v0198 ? lisp_true : nil;
    env = stack[-5];
    if (v0198 == nil) goto v0202;
    v0198 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0198); }

v0202:
    v0198 = stack[-3];
    v0198 = qcdr(v0198);
    stack[-3] = v0198;
    goto v0152;

v0139:
    v0198 = stack[-3];
    fn = elt(env, 9); // simple!-vector!-p
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    if (v0198 == nil) goto v0155;
    v0198 = qvalue(elt(env, 2)); // nil
    goto v0138;

v0155:
    v0198 = stack[-3];
    fn = elt(env, 10); // gensymp
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-5];
    v0198 = (v0198 == nil ? lisp_true : nil);
    goto v0138;
// error exit handlers
v0199:
    popv(6);
    return nil;
}



// Code for squashsqrt

static LispObject CC_squashsqrt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0209, v0190, v0210;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for squashsqrt");
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

v0182:
    v0209 = qvalue(elt(env, 1)); // sqrtflag
    if (v0209 == nil) goto v0030;
    v0209 = stack[-1];
    if (!consp(v0209)) goto v0024;
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = (consp(v0209) ? nil : lisp_true);
    goto v0152;

v0152:
    if (!(v0209 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0190 = qcar(v0209);
    v0209 = elt(env, 3); // sqrt
    if (v0190 == v0209) goto v0046;
    v0209 = qvalue(elt(env, 4)); // nil
    goto v0138;

v0138:
    if (v0209 == nil) goto v0171;
    v0209 = stack[-1];
    v0209 = qcdr(v0209);
    stack[0] = CC_squashsqrt(env, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0210 = qcar(v0209);
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0190 = qcdr(v0209);
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcdr(v0209);
    fn = elt(env, 6); // !*multfsqrt
    v0209 = (*qfnn(fn))(qenv(fn), 3, v0210, v0190, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    {
        LispObject v0091 = stack[0];
        popv(4);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0091, v0209);
    }

v0171:
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0190 = qcar(v0209);
    v0209 = elt(env, 5); // expt
    if (v0190 == v0209) goto v0172;
    v0209 = qvalue(elt(env, 4)); // nil
    goto v0211;

v0211:
    if (v0209 == nil) goto v0201;
    v0209 = stack[-1];
    v0209 = qcdr(v0209);
    stack[0] = CC_squashsqrt(env, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0210 = qcar(v0209);
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0190 = qcdr(v0209);
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcdr(v0209);
    fn = elt(env, 8); // !*multfexpt
    v0209 = (*qfnn(fn))(qenv(fn), 3, v0210, v0190, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    {
        LispObject v0212 = stack[0];
        popv(4);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0212, v0209);
    }

v0201:
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcdr(v0209);
    v0209 = CC_squashsqrt(env, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0190 = v0209;
    v0209 = v0190;
    if (v0209 == nil) goto v0158;
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    stack[-2] = qcar(v0209);
    stack[0] = v0190;
    v0209 = stack[-1];
    v0209 = qcdr(v0209);
    v0209 = CC_squashsqrt(env, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    {
        LispObject v0213 = stack[-2];
        LispObject v0214 = stack[0];
        popv(4);
        return acons(v0213, v0214, v0209);
    }

v0158:
    v0209 = stack[-1];
    v0209 = qcdr(v0209);
    stack[-1] = v0209;
    goto v0182;

v0172:
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcar(v0209);
    fn = elt(env, 9); // prefix!-rational!-numberp
    v0209 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    if (v0209 == nil) goto v0163;
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0190 = qcdr(v0209);
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcar(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcar(v0209);
    v0209 = (LispObject)geq2(v0190, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0209 = v0209 ? lisp_true : nil;
    env = stack[-3];
    goto v0211;

v0163:
    v0209 = qvalue(elt(env, 4)); // nil
    goto v0211;

v0046:
    v0209 = stack[-1];
    v0209 = qcar(v0209);
    v0209 = qcar(v0209);
    v0190 = qcdr(v0209);
    v0209 = (LispObject)17; // 1
    v0209 = (LispObject)greaterp2(v0190, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0209 = v0209 ? lisp_true : nil;
    env = stack[-3];
    goto v0138;

v0024:
    v0209 = qvalue(elt(env, 2)); // t
    goto v0152;

v0030:
    v0209 = qvalue(elt(env, 2)); // t
    goto v0152;
// error exit handlers
v0090:
    popv(4);
    return nil;
}



// Code for ofsf_simplat1

static LispObject CC_ofsf_simplat1(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0221, v0222, v0198;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0041;
    v0198 = v0000;
// end of prologue
    v0221 = v0198;
    v0221 = qcar(v0221);
    stack[-3] = v0221;
    v0222 = stack[-3];
    v0221 = elt(env, 1); // (equal neq leq geq lessp greaterp)
    v0221 = Lmemq(nil, v0222, v0221);
    if (v0221 == nil) goto v0186;
    v0221 = v0198;
    v0221 = qcdr(v0221);
    v0221 = qcar(v0221);
    stack[-1] = v0221;
    v0221 = stack[-1];
    if (!consp(v0221)) goto v0138;
    v0221 = stack[-1];
    v0221 = qcar(v0221);
    v0221 = (consp(v0221) ? nil : lisp_true);
    goto v0154;

v0154:
    if (v0221 == nil) goto v0169;
    v0222 = stack[-3];
    v0221 = stack[-1];
    fn = elt(env, 13); // ofsf_evalatp
    v0221 = (*qfn2(fn))(qenv(fn), v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    if (v0221 == nil) goto v0188;
    v0221 = elt(env, 4); // true
    { popv(5); return onevalue(v0221); }

v0188:
    v0221 = elt(env, 5); // false
    { popv(5); return onevalue(v0221); }

v0169:
    stack[0] = stack[-1];
    v0221 = stack[-1];
    fn = elt(env, 14); // sfto_dcontentf
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    fn = elt(env, 15); // quotf
    v0221 = (*qfn2(fn))(qenv(fn), stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[-1] = v0221;
    v0221 = stack[-1];
    fn = elt(env, 16); // minusf
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    if (v0221 == nil) goto v0200;
    v0221 = stack[-1];
    fn = elt(env, 17); // negf
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[-1] = v0221;
    v0221 = stack[-3];
    fn = elt(env, 18); // ofsf_anegrel
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[-3] = v0221;
    goto v0200;

v0200:
    v0221 = qvalue(elt(env, 6)); // !*rlsiatadv
    if (v0221 == nil) goto v0013;
    v0222 = stack[-3];
    v0221 = elt(env, 7); // equal
    if (v0222 == v0221) goto v0181;
    v0222 = stack[-3];
    v0221 = elt(env, 8); // neq
    if (v0222 == v0221) goto v0223;
    v0222 = stack[-3];
    v0221 = elt(env, 9); // leq
    if (v0222 == v0221) goto v0001;
    v0222 = stack[-3];
    v0221 = elt(env, 10); // geq
    if (v0222 == v0221) goto v0224;
    v0222 = stack[-3];
    v0221 = elt(env, 11); // lessp
    if (v0222 == v0221) goto v0158;
    v0222 = stack[-3];
    v0221 = elt(env, 12); // greaterp
    if (v0222 == v0221) goto v0203;
    v0221 = nil;
    { popv(5); return onevalue(v0221); }

v0203:
    v0222 = stack[-1];
    v0221 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); // ofsf_simplgreaterp
        return (*qfn2(fn))(qenv(fn), v0222, v0221);
    }

v0158:
    v0222 = stack[-1];
    v0221 = stack[-2];
    {
        popv(5);
        fn = elt(env, 20); // ofsf_simpllessp
        return (*qfn2(fn))(qenv(fn), v0222, v0221);
    }

v0224:
    v0222 = stack[-1];
    v0221 = stack[-2];
    {
        popv(5);
        fn = elt(env, 21); // ofsf_simplgeq
        return (*qfn2(fn))(qenv(fn), v0222, v0221);
    }

v0001:
    v0222 = stack[-1];
    v0221 = stack[-2];
    {
        popv(5);
        fn = elt(env, 22); // ofsf_simplleq
        return (*qfn2(fn))(qenv(fn), v0222, v0221);
    }

v0223:
    v0222 = stack[-1];
    v0221 = stack[-2];
    {
        popv(5);
        fn = elt(env, 23); // ofsf_simplneq
        return (*qfn2(fn))(qenv(fn), v0222, v0221);
    }

v0181:
    v0222 = stack[-1];
    v0221 = stack[-2];
    {
        popv(5);
        fn = elt(env, 24); // ofsf_simplequal
        return (*qfn2(fn))(qenv(fn), v0222, v0221);
    }

v0013:
    v0222 = stack[-3];
    v0221 = stack[-1];
    v0198 = qvalue(elt(env, 2)); // nil
    popv(5);
    return list3(v0222, v0221, v0198);

v0138:
    v0221 = qvalue(elt(env, 3)); // t
    goto v0154;

v0186:
    v0221 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0221); }
// error exit handlers
v0214:
    popv(5);
    return nil;
}



// Code for ofsf_negateat

static LispObject CC_ofsf_negateat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0139, v0031, v0044;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_negateat");
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
    v0139 = stack[0];
    v0139 = qcdr(v0139);
    v0031 = qcar(v0139);
    v0139 = stack[0];
    v0139 = qcdr(v0139);
    v0139 = qcdr(v0139);
    v0139 = qcar(v0139);
    v0139 = list2(v0031, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-2];
    stack[-1] = v0139;
    v0139 = stack[0];
    v0139 = qcar(v0139);
    fn = elt(env, 1); // ofsf_lnegrel
    v0044 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    v0139 = stack[-1];
    v0031 = qcar(v0139);
    v0139 = stack[-1];
    v0139 = qcdr(v0139);
    v0139 = qcar(v0139);
    popv(3);
    return list3(v0044, v0031, v0139);
// error exit handlers
v0155:
    popv(3);
    return nil;
}



// Code for sfto_subfwd

static LispObject CC_sfto_subfwd(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0177, v0178;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_subfwd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0041;
    stack[-2] = v0000;
// end of prologue
    v0177 = stack[-2];
    if (!consp(v0177)) goto v0137;
    v0177 = stack[-2];
    v0177 = qcar(v0177);
    v0177 = (consp(v0177) ? nil : lisp_true);
    goto v0179;

v0179:
    if (!(v0177 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0177 = stack[-2];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0178 = qcar(v0177);
    v0177 = stack[-1];
    v0177 = Latsoc(nil, v0178, v0177);
    v0178 = v0177;
    if (v0178 == nil) goto v0187;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0177 = qcdr(v0177);
    v0177 = quot2(v0178, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    goto v0120;

v0120:
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    fn = elt(env, 2); // to
    stack[-3] = (*qfn2(fn))(qenv(fn), v0178, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0177 = stack[-2];
    v0177 = qcar(v0177);
    v0178 = qcdr(v0177);
    v0177 = stack[-1];
    stack[0] = CC_sfto_subfwd(env, v0178, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0177 = stack[-2];
    v0178 = qcdr(v0177);
    v0177 = stack[-1];
    v0177 = CC_sfto_subfwd(env, v0178, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    {
        LispObject v0181 = stack[-3];
        LispObject v0011 = stack[0];
        popv(5);
        return acons(v0181, v0011, v0177);
    }

v0187:
    v0177 = stack[-2];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcdr(v0177);
    goto v0120;

v0137:
    v0177 = qvalue(elt(env, 1)); // t
    goto v0179;
// error exit handlers
v0196:
    popv(5);
    return nil;
}



// Code for fnom

static LispObject CC_fnom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0166;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fnom");
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
    v0166 = elt(env, 1); // "<OMA>"
    fn = elt(env, 13); // printout
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = qvalue(elt(env, 2)); // t
    fn = elt(env, 14); // indent!*
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 3); // "<OMATTR>"
    fn = elt(env, 13); // printout
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = qvalue(elt(env, 2)); // t
    fn = elt(env, 14); // indent!*
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 4); // "<OMATP>"
    fn = elt(env, 13); // printout
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = qvalue(elt(env, 2)); // t
    fn = elt(env, 14); // indent!*
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 5); // "<OMS cd=""typmml"" name=""type""/>"
    fn = elt(env, 13); // printout
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 6); // "<OMS cd=""typmml"" name="""
    fn = elt(env, 13); // printout
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 7); // "fn_type"
    v0166 = Lprinc(nil, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 8); // """/>"
    v0166 = Lprinc(nil, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 14); // indent!*
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 10); // "</OMATP>"
    fn = elt(env, 13); // printout
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = stack[0];
    v0166 = qcar(v0166);
    fn = elt(env, 15); // objectom
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 14); // indent!*
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 11); // "</OMATTR>"
    fn = elt(env, 13); // printout
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    v0166 = qcdr(v0166);
    fn = elt(env, 16); // multiom
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 14); // indent!*
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0166 = elt(env, 12); // "</OMA>"
    fn = elt(env, 13); // printout
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    v0166 = nil;
    { popv(2); return onevalue(v0166); }
// error exit handlers
v0045:
    popv(2);
    return nil;
}



// Code for a2bc

static LispObject CC_a2bc(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0174, v0114;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for a2bc");
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
    v0174 = v0000;
// end of prologue
    v0114 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0114 == nil) goto v0183;
    v0114 = v0174;
    if (!consp(v0114)) goto v0179;
    v0114 = v0174;
    v0114 = qcar(v0114);
    v0114 = (consp(v0114) ? nil : lisp_true);
    goto v0119;

v0119:
    if (v0114 == nil) goto v0060;
    {
        popv(1);
        fn = elt(env, 4); // bcfd
        return (*qfn1(fn))(qenv(fn), v0174);
    }

v0060:
    v0114 = elt(env, 3); // " Invalid coefficient "
    v0174 = list2(v0114, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); // rederr
        return (*qfn1(fn))(qenv(fn), v0174);
    }

v0179:
    v0114 = qvalue(elt(env, 2)); // t
    goto v0119;

v0183:
    {
        popv(1);
        fn = elt(env, 6); // simp!*
        return (*qfn1(fn))(qenv(fn), v0174);
    }
// error exit handlers
v0113:
    popv(1);
    return nil;
}



// Code for gfdiffer

static LispObject CC_gfdiffer(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0023, v0021, v0022;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfdiffer");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0021 = v0041;
    v0022 = v0000;
// end of prologue
    v0023 = v0022;
    v0023 = qcar(v0023);
    if (!consp(v0023)) goto v0185;
    v0023 = v0022;
    {
        fn = elt(env, 1); // gbfdiff
        return (*qfn2(fn))(qenv(fn), v0023, v0021);
    }

v0185:
    v0023 = v0022;
    {
        fn = elt(env, 2); // gffdiff
        return (*qfn2(fn))(qenv(fn), v0023, v0021);
    }
}



// Code for procstat1

static LispObject CC_procstat1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0243, v0244, v0245;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for procstat1");
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
    stack[-4] = nil;
    stack[0] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v0243 = qvalue(elt(env, 1)); // erfg!*
    stack[-6] = v0243;
    v0243 = qvalue(elt(env, 2)); // fname!*
    if (v0243 == nil) goto v0060;
    v0243 = qvalue(elt(env, 3)); // t
    stack[-6] = v0243;
    goto v0246;

v0246:
    v0244 = elt(env, 21); // (symerr (quote procedure) t)
    v0243 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 22); // errorset!*
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    goto v0247;

v0247:
    v0244 = qvalue(elt(env, 17)); // eof!*
    v0243 = (LispObject)1; // 0
    v0243 = (LispObject)greaterp2(v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0243 = v0243 ? lisp_true : nil;
    env = stack[-7];
    if (v0243 == nil) goto v0248;
    v0243 = elt(env, 18); // !*semicol!*
    qvalue(elt(env, 4)) = v0243; // cursym!*
    v0243 = qvalue(elt(env, 9)); // nil
    qvalue(elt(env, 19)) = v0243; // curescaped!*
    goto v0066;

v0066:
    v0243 = qvalue(elt(env, 2)); // fname!*
    v0244 = ncons(v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    v0243 = elt(env, 16); // fnc
    v0243 = Lremflag(nil, v0244, v0243);
    env = stack[-7];
    v0243 = qvalue(elt(env, 9)); // nil
    qvalue(elt(env, 2)) = v0243; // fname!*
    v0243 = qvalue(elt(env, 1)); // erfg!*
    if (v0243 == nil) { LispObject res = stack[-2]; popv(8); return onevalue(res); }
    v0243 = qvalue(elt(env, 9)); // nil
    stack[-2] = v0243;
    v0243 = stack[-6];
    if (!(v0243 == nil)) { LispObject res = stack[-2]; popv(8); return onevalue(res); }
    v0243 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    { LispObject res = stack[-2]; popv(8); return onevalue(res); }

v0248:
    v0244 = elt(env, 20); // (xread t)
    v0243 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 22); // errorset!*
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[-2] = v0243;
    v0243 = stack[-2];
    fn = elt(env, 23); // errorp
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    if (!(v0243 == nil)) goto v0249;
    v0243 = stack[-2];
    v0243 = qcar(v0243);
    stack[-2] = v0243;
    goto v0249;

v0249:
    v0243 = qvalue(elt(env, 1)); // erfg!*
    if (!(v0243 == nil)) goto v0066;
    stack[-1] = elt(env, 5); // procedure
    v0243 = qvalue(elt(env, 7)); // !*reduce4
    if (v0243 == nil) goto v0250;
    v0243 = qvalue(elt(env, 2)); // fname!*
    stack[0] = v0243;
    goto v0251;

v0251:
    v0245 = stack[-4];
    v0244 = stack[-3];
    v0243 = stack[-2];
    v0243 = list3(v0245, v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    v0243 = list3star(stack[-1], stack[0], stack[-5], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[-2] = v0243;
    goto v0066;

v0250:
    v0243 = stack[0];
    v0243 = qcar(v0243);
    stack[0] = v0243;
    goto v0251;

v0060:
    v0244 = qvalue(elt(env, 4)); // cursym!*
    v0243 = elt(env, 5); // procedure
    if (v0244 == v0243) goto v0049;
    v0243 = qvalue(elt(env, 4)); // cursym!*
    stack[-4] = v0243;
    fn = elt(env, 24); // scan
    v0243 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    goto v0114;

v0114:
    v0244 = qvalue(elt(env, 4)); // cursym!*
    v0243 = elt(env, 5); // procedure
    if (!(v0244 == v0243)) goto v0246;
    v0243 = qvalue(elt(env, 7)); // !*reduce4
    if (v0243 == nil) goto v0188;
    fn = elt(env, 24); // scan
    v0243 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    qvalue(elt(env, 2)) = v0243; // fname!*
    v0243 = qvalue(elt(env, 2)); // fname!*
    if (symbolp(v0243)) goto v0252;
    v0244 = qvalue(elt(env, 2)); // fname!*
    v0243 = elt(env, 13); // "procedure name"
    fn = elt(env, 25); // typerr
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    goto v0247;

v0252:
    fn = elt(env, 24); // scan
    v0243 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[-1] = elt(env, 14); // read_param_list
    v0243 = stack[-5];
    v0243 = Lmkquote(nil, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    v0244 = list2(stack[-1], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    v0243 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 22); // errorset!*
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[-3] = v0243;
    v0243 = stack[-3];
    fn = elt(env, 23); // errorp
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    if (!(v0243 == nil)) goto v0247;
    v0243 = stack[-3];
    v0243 = qcar(v0243);
    stack[-3] = v0243;
    v0244 = qvalue(elt(env, 4)); // cursym!*
    v0243 = elt(env, 15); // !*colon!*
    if (!(v0244 == v0243)) goto v0186;
    fn = elt(env, 26); // read_type
    v0243 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[-5] = v0243;
    goto v0186;

v0186:
    v0243 = qvalue(elt(env, 2)); // fname!*
    if (!(symbolp(v0243))) goto v0247;
    v0243 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 27); // getd
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    if (!(v0243 == nil)) goto v0247;
    v0243 = qvalue(elt(env, 2)); // fname!*
    v0244 = ncons(v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    v0243 = elt(env, 16); // fnc
    v0243 = Lflag(nil, v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    goto v0247;

v0188:
    v0244 = elt(env, 8); // (xread (quote proc))
    v0243 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 22); // errorset!*
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[0] = v0243;
    v0243 = stack[0];
    fn = elt(env, 23); // errorp
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    if (!(v0243 == nil)) goto v0247;
    v0243 = stack[0];
    v0243 = qcar(v0243);
    stack[0] = v0243;
    if (!(!consp(v0243))) goto v0032;
    v0243 = stack[0];
    v0243 = ncons(v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[0] = v0243;
    goto v0032;

v0032:
    v0243 = stack[0];
    v0243 = qcar(v0243);
    qvalue(elt(env, 2)) = v0243; // fname!*
    v0243 = qvalue(elt(env, 2)); // fname!*
    if (!(symbolp(v0243))) goto v0053;
    v0243 = qvalue(elt(env, 2)); // fname!*
    if (v0243 == nil) goto v0122;
    v0244 = qvalue(elt(env, 2)); // fname!*
    v0243 = lisp_true;
    v0243 = (v0244 == v0243 ? lisp_true : nil);
    goto v0092;

v0092:
    if (v0243 == nil) goto v0033;
    v0243 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 28); // rsverr
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    goto v0247;

v0033:
    v0243 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 29); // gettype
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[-2] = v0243;
    if (v0243 == nil) goto v0053;
    v0244 = stack[-2];
    v0243 = elt(env, 10); // (procedure operator)
    v0243 = Lmemq(nil, v0244, v0243);
    if (!(v0243 == nil)) goto v0053;
    v0244 = stack[-2];
    v0243 = qvalue(elt(env, 2)); // fname!*
    v0244 = list2(v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    v0243 = elt(env, 11); // "procedure"
    fn = elt(env, 25); // typerr
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    goto v0247;

v0053:
    v0243 = stack[0];
    v0243 = qcdr(v0243);
    stack[-3] = v0243;
    v0243 = stack[-3];
    fn = elt(env, 30); // idlistp
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    if (v0243 == nil) goto v0253;
    v0243 = stack[0];
    v0244 = qcar(v0243);
    v0243 = stack[-3];
    v0243 = cons(v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    stack[0] = v0243;
    goto v0186;

v0253:
    v0244 = stack[-3];
    v0243 = elt(env, 12); // "invalid as parameter list"
    v0243 = list2(v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    fn = elt(env, 31); // lprie
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-7];
    goto v0186;

v0122:
    v0243 = qvalue(elt(env, 3)); // t
    goto v0092;

v0049:
    v0243 = elt(env, 6); // expr
    stack[-4] = v0243;
    goto v0114;
// error exit handlers
v0116:
    popv(8);
    return nil;
}



// Code for fs!:minusp

static LispObject CC_fsTminusp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0113, v0153, v0166;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0153 = v0000;
// end of prologue

v0004:
    v0113 = v0153;
    if (v0113 == nil) goto v0152;
    v0166 = v0153;
    v0113 = (LispObject)49; // 3
    v0113 = *(LispObject *)((char *)v0166 + (CELL-TAG_VECTOR) + ((int32_t)v0113/(16/CELL)));
    if (v0113 == nil) goto v0060;
    v0113 = (LispObject)49; // 3
    v0113 = *(LispObject *)((char *)v0153 + (CELL-TAG_VECTOR) + ((int32_t)v0113/(16/CELL)));
    v0153 = v0113;
    goto v0004;

v0060:
    v0113 = (LispObject)1; // 0
    v0113 = *(LispObject *)((char *)v0153 + (CELL-TAG_VECTOR) + ((int32_t)v0113/(16/CELL)));
    v0113 = qcar(v0113);
    {
        fn = elt(env, 2); // minusf
        return (*qfn1(fn))(qenv(fn), v0113);
    }

v0152:
    v0113 = qvalue(elt(env, 1)); // nil
    return onevalue(v0113);
}



// Code for !*multf

static LispObject CC_Hmultf(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0319, v0320, v0321;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *multf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0041;
    stack[-3] = v0000;
// end of prologue
    v0319 = stack[-3];
    if (v0319 == nil) goto v0056;
    v0319 = stack[-2];
    v0319 = (v0319 == nil ? lisp_true : nil);
    goto v0137;

v0137:
    if (v0319 == nil) goto v0057;
    v0319 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0319); }

v0057:
    v0320 = stack[-3];
    v0319 = (LispObject)17; // 1
    if (v0320 == v0319) goto v0060;
    v0320 = stack[-2];
    v0319 = (LispObject)17; // 1
    if (v0320 == v0319) goto v0183;
    v0319 = stack[-3];
    if (!consp(v0319)) goto v0168;
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = (consp(v0319) ? nil : lisp_true);
    goto v0043;

v0043:
    if (v0319 == nil) goto v0018;
    stack[0] = stack[-3];
    v0319 = stack[-2];
    fn = elt(env, 7); // squashsqrt
    v0319 = (*qfn1(fn))(qenv(fn), v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    {
        LispObject v0323 = stack[0];
        popv(6);
        fn = elt(env, 8); // multd
        return (*qfn2(fn))(qenv(fn), v0323, v0319);
    }

v0018:
    v0319 = stack[-2];
    if (!consp(v0319)) goto v0015;
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = (consp(v0319) ? nil : lisp_true);
    goto v0051;

v0051:
    if (v0319 == nil) goto v0039;
    stack[0] = stack[-2];
    v0319 = stack[-3];
    fn = elt(env, 7); // squashsqrt
    v0319 = (*qfn1(fn))(qenv(fn), v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    {
        LispObject v0324 = stack[0];
        popv(6);
        fn = elt(env, 8); // multd
        return (*qfn2(fn))(qenv(fn), v0324, v0319);
    }

v0039:
    v0319 = qvalue(elt(env, 3)); // !*noncomp
    if (v0319 == nil) goto v0185;
    v0320 = stack[-3];
    v0319 = stack[-2];
    {
        popv(6);
        fn = elt(env, 9); // multf
        return (*qfn2(fn))(qenv(fn), v0320, v0319);
    }

v0185:
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    stack[0] = v0319;
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    stack[-1] = v0319;
    v0320 = stack[0];
    v0319 = stack[-1];
    if (v0320 == v0319) goto v0325;
    v0320 = stack[0];
    v0319 = stack[-1];
    fn = elt(env, 10); // ordop
    v0319 = (*qfn2(fn))(qenv(fn), v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    if (v0319 == nil) goto v0194;
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[0] = v0319;
    v0319 = stack[-3];
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[-1] = v0319;
    v0319 = stack[0];
    if (v0319 == nil) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    if (!consp(v0319)) goto v0066;
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = qcar(v0319);
    v0319 = (consp(v0319) ? nil : lisp_true);
    goto v0065;

v0065:
    if (v0319 == nil) goto v0074;
    v0319 = qvalue(elt(env, 2)); // nil
    goto v0326;

v0326:
    if (v0319 == nil) goto v0327;
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0320 = qcar(v0319);
    v0319 = (LispObject)17; // 1
    v0319 = cons(v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0320 = ncons(v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[0];
    v0320 = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0320, v0319);
    }

v0327:
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0321 = qcar(v0319);
    v0320 = stack[0];
    v0319 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); // makeupsf
        return (*qfnn(fn))(qenv(fn), 3, v0321, v0320, v0319);
    }

v0074:
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0320 = qcar(v0319);
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    if (v0320 == v0319) goto v0075;
    v0319 = qvalue(elt(env, 2)); // nil
    goto v0326;

v0075:
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    if (!consp(v0319)) goto v0328;
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0320 = qcar(v0319);
    v0319 = elt(env, 4); // (expt sqrt)
    v0319 = Lmemq(nil, v0320, v0319);
    goto v0326;

v0328:
    v0319 = qvalue(elt(env, 2)); // nil
    goto v0326;

v0066:
    v0319 = qvalue(elt(env, 1)); // t
    goto v0065;

v0194:
    v0320 = stack[-3];
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[0] = v0319;
    v0320 = stack[-3];
    v0319 = stack[-2];
    v0319 = qcdr(v0319);
    v0319 = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[-1] = v0319;
    v0319 = stack[0];
    if (v0319 == nil) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    if (!consp(v0319)) goto v0144;
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = qcar(v0319);
    v0319 = (consp(v0319) ? nil : lisp_true);
    goto v0208;

v0208:
    if (v0319 == nil) goto v0159;
    v0319 = qvalue(elt(env, 2)); // nil
    goto v0093;

v0093:
    if (v0319 == nil) goto v0329;
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0320 = qcar(v0319);
    v0319 = (LispObject)17; // 1
    v0319 = cons(v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = ncons(v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0320 = CC_Hmultf(env, stack[0], v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0320, v0319);
    }

v0329:
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0321 = qcar(v0319);
    v0320 = stack[0];
    v0319 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); // makeupsf
        return (*qfnn(fn))(qenv(fn), 3, v0321, v0320, v0319);
    }

v0159:
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0320 = qcar(v0319);
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    if (v0320 == v0319) goto v0157;
    v0319 = qvalue(elt(env, 2)); // nil
    goto v0093;

v0157:
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    if (!consp(v0319)) goto v0199;
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0320 = qcar(v0319);
    v0319 = elt(env, 4); // (expt sqrt)
    v0319 = Lmemq(nil, v0320, v0319);
    goto v0093;

v0199:
    v0319 = qvalue(elt(env, 2)); // nil
    goto v0093;

v0144:
    v0319 = qvalue(elt(env, 1)); // t
    goto v0208;

v0325:
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0320 = ncons(v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[-2];
    v0319 = qcdr(v0319);
    stack[-1] = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[-3];
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    fn = elt(env, 11); // addf
    v0319 = (*qfn2(fn))(qenv(fn), stack[-1], v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[-1] = v0319;
    v0320 = stack[0];
    v0319 = elt(env, 5); // sqrt
    if (!consp(v0320)) goto v0330;
    v0320 = qcar(v0320);
    if (!(v0320 == v0319)) goto v0330;
    v0319 = stack[-1];
    fn = elt(env, 7); // squashsqrt
    stack[-4] = (*qfn1(fn))(qenv(fn), v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[-1] = stack[0];
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    stack[0] = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = plus2(v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    fn = elt(env, 13); // !*multfsqrt
    v0319 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    {
        LispObject v0331 = stack[-4];
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0331, v0319);
    }

v0330:
    v0320 = stack[0];
    v0319 = elt(env, 6); // expt
    if (!consp(v0320)) goto v0332;
    v0320 = qcar(v0320);
    if (!(v0320 == v0319)) goto v0332;
    v0319 = stack[0];
    v0319 = qcdr(v0319);
    v0319 = qcdr(v0319);
    v0319 = qcar(v0319);
    fn = elt(env, 14); // prefix!-rational!-numberp
    v0319 = (*qfn1(fn))(qenv(fn), v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    goto v0333;

v0333:
    if (v0319 == nil) goto v0334;
    v0319 = stack[-1];
    fn = elt(env, 7); // squashsqrt
    stack[-4] = (*qfn1(fn))(qenv(fn), v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[-1] = stack[0];
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    stack[0] = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = plus2(v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    fn = elt(env, 15); // !*multfexpt
    v0319 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    {
        LispObject v0335 = stack[-4];
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0335, v0319);
    }

v0334:
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = plus2(v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    fn = elt(env, 16); // mkspm
    v0319 = (*qfn2(fn))(qenv(fn), stack[0], v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[0] = v0319;
    v0319 = stack[0];
    if (v0319 == nil) goto v0336;
    v0319 = stack[-3];
    v0319 = qcar(v0319);
    v0320 = qcdr(v0319);
    v0319 = stack[-2];
    v0319 = qcar(v0319);
    v0319 = qcdr(v0319);
    v0319 = CC_Hmultf(env, v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    stack[-3] = v0319;
    v0319 = (v0319 == nil ? lisp_true : nil);
    goto v0337;

v0337:
    if (!(v0319 == nil)) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0320 = stack[0];
    v0319 = (LispObject)17; // 1
    v0319 = cons(v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0320 = ncons(v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[-3];
    fn = elt(env, 9); // multf
    v0320 = (*qfn2(fn))(qenv(fn), v0320, v0319);
    nil = C_nil;
    if (exception_pending()) goto v0322;
    env = stack[-5];
    v0319 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); // addf
        return (*qfn2(fn))(qenv(fn), v0320, v0319);
    }

v0336:
    v0319 = qvalue(elt(env, 1)); // t
    goto v0337;

v0332:
    v0319 = qvalue(elt(env, 2)); // nil
    goto v0333;

v0015:
    v0319 = qvalue(elt(env, 1)); // t
    goto v0051;

v0168:
    v0319 = qvalue(elt(env, 1)); // t
    goto v0043;

v0183:
    v0319 = stack[-3];
    {
        popv(6);
        fn = elt(env, 7); // squashsqrt
        return (*qfn1(fn))(qenv(fn), v0319);
    }

v0060:
    v0319 = stack[-2];
    {
        popv(6);
        fn = elt(env, 7); // squashsqrt
        return (*qfn1(fn))(qenv(fn), v0319);
    }

v0056:
    v0319 = qvalue(elt(env, 1)); // t
    goto v0137;
// error exit handlers
v0322:
    popv(6);
    return nil;
}



// Code for solvealgdepends

static LispObject CC_solvealgdepends(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0092, v0122;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for solvealgdepends");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0041;
    stack[-1] = v0000;
// end of prologue

v0186:
    v0122 = stack[-1];
    v0092 = stack[0];
    if (equal(v0122, v0092)) goto v0134;
    v0092 = stack[-1];
    if (!consp(v0092)) goto v0136;
    v0122 = stack[-1];
    v0092 = elt(env, 3); // root_of
    if (!consp(v0122)) goto v0042;
    v0122 = qcar(v0122);
    if (!(v0122 == v0092)) goto v0042;
    v0122 = stack[0];
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    if (equal(v0122, v0092)) goto v0183;
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    stack[-1] = v0092;
    goto v0186;

v0183:
    v0092 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0092); }

v0042:
    v0092 = stack[-1];
    v0122 = qcar(v0092);
    v0092 = stack[0];
    v0092 = CC_solvealgdepends(env, v0122, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0122 = v0092;
    if (!(v0092 == nil)) { popv(3); return onevalue(v0122); }
    v0092 = stack[-1];
    v0122 = qcdr(v0092);
    v0092 = stack[0];
    v0092 = CC_solvealgdepends(env, v0122, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0122 = v0092;
    if (!(v0092 == nil)) { popv(3); return onevalue(v0122); }
    v0092 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0092); }

v0136:
    v0092 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0092); }

v0134:
    v0092 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0092); }
// error exit handlers
v0010:
    popv(3);
    return nil;
}



// Code for makecoeffpairshom

static LispObject CC_makecoeffpairshom(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0354, v0355, v0118, v0126;
    LispObject fn;
    LispObject v0009, v0003, v0041, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairshom");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makecoeffpairshom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0003,v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0041,v0003,v0009);
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
    stack[-11] = v0009;
    stack[-12] = v0003;
    stack[-13] = v0041;
    stack[-14] = v0000;
// end of prologue
    v0354 = stack[-12];
    if (v0354 == nil) goto v0152;
    v0354 = stack[-13];
    v0354 = qcar(v0354);
    stack[-15] = v0354;
    goto v0021;

v0021:
    stack[0] = stack[-11];
    v0354 = stack[-14];
    v0355 = qcar(v0354);
    v0354 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    fn = elt(env, 4); // tayexp!-times2
    v0354 = (*qfn2(fn))(qenv(fn), stack[0], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    fn = elt(env, 5); // tayexp!-minusp
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    if (v0354 == nil) goto v0220;
    v0354 = qvalue(elt(env, 2)); // nil
    { popv(17); return onevalue(v0354); }

v0220:
    v0354 = stack[-14];
    v0126 = qcdr(v0354);
    v0354 = stack[-13];
    v0118 = qcdr(v0354);
    v0354 = stack[-12];
    v0355 = qcdr(v0354);
    v0354 = stack[-11];
    v0354 = CC_makecoeffpairshom(env, 4, v0126, v0118, v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    stack[-7] = v0354;
    v0354 = stack[-7];
    if (v0354 == nil) goto v0039;
    v0354 = stack[-7];
    v0354 = qcar(v0354);
    stack[-3] = v0354;
    stack[-2] = stack[-15];
    v0354 = stack[-3];
    stack[-1] = qcar(v0354);
    v0354 = stack[-13];
    stack[0] = qcar(v0354);
    v0354 = stack[-12];
    v0355 = qcar(v0354);
    v0354 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    fn = elt(env, 6); // tayexp!-plus2
    v0355 = (*qfn2(fn))(qenv(fn), stack[0], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = stack[-3];
    v0354 = qcdr(v0354);
    v0354 = cons(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = acons(stack[-2], stack[-1], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = ncons(v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    stack[-5] = v0354;
    stack[-6] = v0354;
    goto v0043;

v0043:
    v0354 = stack[-7];
    v0354 = qcdr(v0354);
    stack[-7] = v0354;
    v0354 = stack[-7];
    if (v0354 == nil) goto v0109;
    stack[-4] = stack[-5];
    v0354 = stack[-7];
    v0354 = qcar(v0354);
    stack[-3] = v0354;
    stack[-2] = stack[-15];
    v0354 = stack[-3];
    stack[-1] = qcar(v0354);
    v0354 = stack[-13];
    stack[0] = qcar(v0354);
    v0354 = stack[-12];
    v0355 = qcar(v0354);
    v0354 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    fn = elt(env, 6); // tayexp!-plus2
    v0355 = (*qfn2(fn))(qenv(fn), stack[0], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = stack[-3];
    v0354 = qcdr(v0354);
    v0354 = cons(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = acons(stack[-2], stack[-1], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = ncons(v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = Lrplacd(nil, stack[-4], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = stack[-5];
    v0354 = qcdr(v0354);
    stack[-5] = v0354;
    goto v0043;

v0109:
    v0354 = stack[-6];
    goto v0017;

v0017:
    stack[-10] = v0354;
    v0354 = stack[-10];
    fn = elt(env, 7); // lastpair
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    stack[-9] = v0354;
    v0355 = stack[-15];
    v0354 = stack[-11];
    fn = elt(env, 6); // tayexp!-plus2
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    stack[-15] = v0354;
    v0354 = stack[-9];
    if (!consp(v0354)) goto v0021;
    else goto v0356;

v0356:
    stack[0] = stack[-11];
    v0354 = stack[-14];
    v0355 = qcar(v0354);
    v0354 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    fn = elt(env, 4); // tayexp!-times2
    v0354 = (*qfn2(fn))(qenv(fn), stack[0], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    fn = elt(env, 5); // tayexp!-minusp
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    if (!(v0354 == nil)) { LispObject res = stack[-10]; popv(17); return onevalue(res); }
    stack[-8] = stack[-9];
    v0354 = stack[-14];
    v0126 = qcdr(v0354);
    v0354 = stack[-13];
    v0118 = qcdr(v0354);
    v0354 = stack[-12];
    v0355 = qcdr(v0354);
    v0354 = stack[-11];
    v0354 = CC_makecoeffpairshom(env, 4, v0126, v0118, v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    stack[-7] = v0354;
    v0354 = stack[-7];
    if (v0354 == nil) goto v0235;
    v0354 = stack[-7];
    v0354 = qcar(v0354);
    stack[-3] = v0354;
    stack[-2] = stack[-15];
    v0354 = stack[-3];
    stack[-1] = qcar(v0354);
    v0354 = stack[-13];
    stack[0] = qcar(v0354);
    v0354 = stack[-12];
    v0355 = qcar(v0354);
    v0354 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    fn = elt(env, 6); // tayexp!-plus2
    v0355 = (*qfn2(fn))(qenv(fn), stack[0], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = stack[-3];
    v0354 = qcdr(v0354);
    v0354 = cons(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = acons(stack[-2], stack[-1], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = ncons(v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    stack[-5] = v0354;
    stack[-6] = v0354;
    goto v0072;

v0072:
    v0354 = stack[-7];
    v0354 = qcdr(v0354);
    stack[-7] = v0354;
    v0354 = stack[-7];
    if (v0354 == nil) goto v0078;
    stack[-4] = stack[-5];
    v0354 = stack[-7];
    v0354 = qcar(v0354);
    stack[-3] = v0354;
    stack[-2] = stack[-15];
    v0354 = stack[-3];
    stack[-1] = qcar(v0354);
    v0354 = stack[-13];
    stack[0] = qcar(v0354);
    v0354 = stack[-12];
    v0355 = qcar(v0354);
    v0354 = stack[-15];
    fn = elt(env, 3); // tayexp!-difference
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    fn = elt(env, 6); // tayexp!-plus2
    v0355 = (*qfn2(fn))(qenv(fn), stack[0], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = stack[-3];
    v0354 = qcdr(v0354);
    v0354 = cons(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = acons(stack[-2], stack[-1], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = ncons(v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = Lrplacd(nil, stack[-4], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = stack[-5];
    v0354 = qcdr(v0354);
    stack[-5] = v0354;
    goto v0072;

v0078:
    v0354 = stack[-6];
    goto v0213;

v0213:
    v0354 = Lrplacd(nil, stack[-8], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    v0354 = stack[-9];
    fn = elt(env, 7); // lastpair
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    stack[-9] = v0354;
    v0355 = stack[-15];
    v0354 = stack[-11];
    fn = elt(env, 6); // tayexp!-plus2
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-16];
    stack[-15] = v0354;
    goto v0356;

v0235:
    v0354 = qvalue(elt(env, 2)); // nil
    goto v0213;

v0039:
    v0354 = qvalue(elt(env, 2)); // nil
    goto v0017;

v0152:
    v0354 = elt(env, 1); // ((nil))
    { popv(17); return onevalue(v0354); }
// error exit handlers
v0301:
    popv(17);
    return nil;
}



// Code for termorder1

static LispObject CC_termorder1(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0164, v0123;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termorder1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0041;
    stack[-1] = v0000;
// end of prologue

v0140:
    v0164 = stack[-1];
    if (v0164 == nil) goto v0030;
    v0164 = stack[-1];
    v0164 = (LispObject)zerop(v0164);
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-2];
    if (v0164 == nil) goto v0179;
    v0164 = stack[0];
    v0164 = (LispObject)zerop(v0164);
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-2];
    if (v0164 == nil) goto v0179;
    v0164 = (LispObject)1; // 0
    { popv(3); return onevalue(v0164); }

v0179:
    v0164 = stack[-1];
    v0164 = (LispObject)zerop(v0164);
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-2];
    if (v0164 == nil) goto v0049;
    v0164 = (LispObject)-15; // -1
    { popv(3); return onevalue(v0164); }

v0049:
    v0164 = stack[0];
    v0164 = (LispObject)zerop(v0164);
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-2];
    if (v0164 == nil) goto v0044;
    v0164 = (LispObject)17; // 1
    { popv(3); return onevalue(v0164); }

v0044:
    v0164 = stack[-1];
    v0123 = qcar(v0164);
    v0164 = stack[0];
    v0164 = qcar(v0164);
    v0164 = (LispObject)lessp2(v0123, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-2];
    if (v0164 == nil) goto v0018;
    v0164 = (LispObject)-15; // -1
    { popv(3); return onevalue(v0164); }

v0018:
    v0164 = stack[-1];
    v0123 = qcar(v0164);
    v0164 = stack[0];
    v0164 = qcar(v0164);
    v0164 = (LispObject)greaterp2(v0123, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-2];
    if (v0164 == nil) goto v0169;
    v0164 = (LispObject)17; // 1
    { popv(3); return onevalue(v0164); }

v0169:
    v0164 = stack[-1];
    v0164 = qcdr(v0164);
    stack[-1] = v0164;
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    stack[0] = v0164;
    goto v0140;

v0030:
    v0164 = (LispObject)1; // 0
    { popv(3); return onevalue(v0164); }
// error exit handlers
v0120:
    popv(3);
    return nil;
}



// Code for degree!-order

static LispObject CC_degreeKorder(LispObject env,
                         LispObject v0000, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0043, v0168, v0220;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for degree-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0168 = v0041;
    v0220 = v0000;
// end of prologue
    v0043 = v0220;
    if (!consp(v0043)) goto v0134;
    v0043 = v0220;
    v0043 = qcar(v0043);
    v0043 = (consp(v0043) ? nil : lisp_true);
    goto v0030;

v0030:
    if (v0043 == nil) goto v0047;
    v0043 = qvalue(elt(env, 1)); // t
    return onevalue(v0043);

v0047:
    v0043 = v0168;
    if (!consp(v0043)) goto v0059;
    v0043 = v0168;
    v0043 = qcar(v0043);
    v0043 = (consp(v0043) ? nil : lisp_true);
    goto v0049;

v0049:
    if (v0043 == nil) goto v0167;
    v0043 = qvalue(elt(env, 2)); // nil
    return onevalue(v0043);

v0167:
    v0043 = v0220;
    v0043 = qcar(v0043);
    v0043 = qcar(v0043);
    v0043 = qcdr(v0043);
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    v0168 = qcdr(v0168);
        return Llessp(nil, v0043, v0168);

v0059:
    v0043 = qvalue(elt(env, 1)); // t
    goto v0049;

v0134:
    v0043 = qvalue(elt(env, 1)); // t
    goto v0030;
}



// Code for vectorrd

static LispObject CC_vectorrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0024, v0135;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vectorrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vectorrd");
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
    fn = elt(env, 3); // matrixrowrd
    v0024 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[0];
    v0135 = elt(env, 2); // mat
    v0024 = list2(v0135, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); // aeval
        return (*qfn1(fn))(qenv(fn), v0024);
    }
// error exit handlers
v0025:
    popv(1);
    return nil;
}



// Code for simpimpart

static LispObject CC_simpimpart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0030, v0134;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpimpart");
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
    v0134 = v0000;
// end of prologue
    v0030 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 2)); // !*factor
    qvalue(elt(env, 2)) = v0030; // !*factor
    v0030 = v0134;
    v0030 = qcar(v0030);
    fn = elt(env, 3); // simp!*
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-1];
    fn = elt(env, 4); // impartsq
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*factor
    { popv(2); return onevalue(v0030); }
// error exit handlers
v0186:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*factor
    popv(2);
    return nil;
}



// Code for on!-double1

static LispObject CC_onKdouble1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0022;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for on-double1");
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

v0004:
    v0022 = stack[0];
    v0022 = Lconsp(nil, v0022);
    env = stack[-1];
    if (v0022 == nil) goto v0057;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    fn = elt(env, 3); // doublep
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    if (v0022 == nil) goto v0136;
    v0022 = lisp_true;
    qvalue(elt(env, 1)) = v0022; // !*double
    { popv(2); return onevalue(v0022); }

v0136:
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = CC_onKdouble1(env, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    goto v0004;

v0057:
    v0022 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0022); }
// error exit handlers
v0138:
    popv(2);
    return nil;
}



// Code for genexp

static LispObject CC_genexp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for genexp");
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

v0182:
    v0058 = stack[0];
    if (!consp(v0058)) goto v0004;
    v0058 = stack[0];
    v0058 = qcar(v0058);
    v0058 = CC_genexp(env, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    if (!(v0058 == nil)) { popv(2); return onevalue(v0058); }
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    stack[0] = v0058;
    goto v0182;

v0004:
    v0058 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); // genp
        return (*qfn1(fn))(qenv(fn), v0058);
    }
// error exit handlers
v0049:
    popv(2);
    return nil;
}



// Code for xpartitop

static LispObject CC_xpartitop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0140;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xpartitop");
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
    v0140 = v0000;
// end of prologue
    fn = elt(env, 1); // simp!*
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // xpartitsq
        return (*qfn1(fn))(qenv(fn), v0140);
    }
// error exit handlers
v0047:
    popv(1);
    return nil;
}



// Code for simpunion

static LispObject CC_simpunion(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0053, v0054, v0055;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpunion");
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
    v0054 = elt(env, 1); // union
    fn = elt(env, 3); // applysetop
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    v0055 = v0053;
    v0053 = v0055;
    v0054 = qcar(v0053);
    v0053 = elt(env, 1); // union
    if (v0054 == v0053) goto v0018;
    v0053 = v0055;
    v0054 = v0053;
    goto v0023;

v0023:
    v0053 = (LispObject)17; // 1
    fn = elt(env, 4); // mksp
    v0054 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    v0053 = (LispObject)17; // 1
    v0053 = cons(v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    v0054 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    v0053 = (LispObject)17; // 1
    popv(2);
    return cons(v0054, v0053);

v0018:
    v0053 = qvalue(elt(env, 2)); // empty_set
    v0054 = v0055;
    v0054 = qcdr(v0054);
    v0053 = Ldelete(nil, v0053, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    v0055 = v0053;
    v0053 = qcdr(v0053);
    if (v0053 == nil) goto v0165;
    stack[0] = elt(env, 1); // union
    v0053 = v0055;
    fn = elt(env, 5); // ordn
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    v0053 = cons(stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    goto v0166;

v0166:
    v0054 = v0053;
    goto v0023;

v0165:
    v0053 = v0055;
    v0053 = qcar(v0053);
    goto v0166;
// error exit handlers
v0173:
    popv(2);
    return nil;
}



// Code for spp

static LispObject CC_spp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0137, v0056;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spp");
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
    v0137 = v0000;
// end of prologue
    v0056 = v0137;
    v0056 = Lconsp(nil, v0056);
    env = stack[0];
    if (v0056 == nil) goto v0004;
    v0137 = qcar(v0137);
    {
        popv(1);
        fn = elt(env, 2); // kernelp
        return (*qfn1(fn))(qenv(fn), v0137);
    }

v0004:
    v0137 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0137); }
}



// Code for s_world_names

static LispObject CC_s_world_names(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0045;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s_world_names");
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
    v0045 = v0000;
// end of prologue
    v0045 = qcar(v0045);
    stack[-3] = v0045;
    v0045 = stack[-3];
    if (v0045 == nil) goto v0119;
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0045 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-4];
    stack[-1] = v0045;
    stack[-2] = v0045;
    goto v0152;

v0152:
    v0045 = stack[-3];
    v0045 = qcdr(v0045);
    stack[-3] = v0045;
    v0045 = stack[-3];
    if (v0045 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0045 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-4];
    v0045 = Lrplacd(nil, stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-4];
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    goto v0152;

v0119:
    v0045 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0045); }
// error exit handlers
v0168:
    popv(5);
    return nil;
}



// Code for factor!-prim!-f

static LispObject CC_factorKprimKf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0221, v0222, v0198;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factor-prim-f");
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
    stack[-1] = nil;
    v0221 = qvalue(elt(env, 1)); // ncmp!*
    if (v0221 == nil) goto v0134;
    stack[0] = (LispObject)17; // 1
    v0222 = stack[-2];
    v0221 = (LispObject)17; // 1
    v0221 = cons(v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    {
        LispObject v0317 = stack[0];
        popv(5);
        return list2(v0317, v0221);
    }

v0134:
    v0221 = qvalue(elt(env, 2)); // dmode!*
    if (v0221 == nil) goto v0138;
    v0222 = qvalue(elt(env, 2)); // dmode!*
    v0221 = elt(env, 3); // sqfrfactorfn
    v0221 = get(v0222, v0221);
    env = stack[-4];
    stack[-1] = v0221;
    if (v0221 == nil) goto v0138;
    v0221 = qvalue(elt(env, 4)); // !*factor
    if (v0221 == nil) goto v0038;
    v0222 = stack[-1];
    v0221 = stack[-2];
    v0221 = Lapply1(nil, v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[0] = v0221;
    goto v0022;

v0022:
    v0221 = stack[-1];
    if (v0221 == nil) goto v0362;
    v0198 = stack[-1];
    v0222 = qvalue(elt(env, 2)); // dmode!*
    v0221 = elt(env, 6); // factorfn
    v0221 = get(v0222, v0221);
    env = stack[-4];
    if (v0198 == v0221) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    else goto v0362;

v0362:
    v0221 = stack[0];
    v0221 = qcar(v0221);
    v0221 = ncons(v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[-3] = v0221;
    v0221 = stack[0];
    v0221 = qcdr(v0221);
    stack[0] = v0221;
    goto v0363;

v0363:
    v0221 = stack[0];
    if (v0221 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0221 = stack[0];
    v0221 = qcar(v0221);
    fn = elt(env, 7); // factor!-prim!-sqfree!-f
    v0222 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0221 = stack[-3];
    fn = elt(env, 8); // fac!-merge
    v0221 = (*qfn2(fn))(qenv(fn), v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[-3] = v0221;
    v0221 = stack[0];
    v0221 = qcdr(v0221);
    stack[0] = v0221;
    goto v0363;

v0038:
    stack[0] = (LispObject)17; // 1
    v0222 = stack[-2];
    v0221 = (LispObject)17; // 1
    v0221 = cons(v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0221 = list2(stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[0] = v0221;
    goto v0022;

v0138:
    v0221 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0221)) v0221 = nil;
    else { v0221 = qfastgets(v0221);
           if (v0221 != nil) { v0221 = elt(v0221, 3); // field
#ifdef RECORD_GET
             if (v0221 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0221 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0221 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0221 == SPID_NOPROP) v0221 = nil; else v0221 = lisp_true; }}
#endif
    if (v0221 == nil) goto v0211;
    v0221 = stack[-2];
    fn = elt(env, 9); // lnc
    v0222 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[-3] = v0222;
    v0221 = (LispObject)17; // 1
    v0221 = Lneq(nil, v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    goto v0054;

v0054:
    if (v0221 == nil) goto v0052;
    stack[0] = stack[-3];
    v0221 = stack[-3];
    fn = elt(env, 10); // !:recip
    v0222 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0221 = stack[-2];
    fn = elt(env, 11); // multd
    v0221 = (*qfn2(fn))(qenv(fn), v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    fn = elt(env, 12); // sqfrf
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0221 = cons(stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[0] = v0221;
    goto v0022;

v0052:
    v0221 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0221)) v0221 = nil;
    else { v0221 = qfastgets(v0221);
           if (v0221 != nil) { v0221 = elt(v0221, 27); // units
#ifdef RECORD_GET
             if (v0221 != SPID_NOPROP)
                record_get(elt(fastget_names, 27), 1);
             else record_get(elt(fastget_names, 27), 0),
                v0221 = nil; }
           else record_get(elt(fastget_names, 27), 0); }
#else
             if (v0221 == SPID_NOPROP) v0221 = nil; }}
#endif
    stack[-3] = v0221;
    if (v0221 == nil) goto v0364;
    v0221 = stack[-2];
    fn = elt(env, 9); // lnc
    v0222 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0198 = v0222;
    v0221 = stack[-3];
    v0221 = Lassoc(nil, v0222, v0221);
    stack[-3] = v0221;
    if (v0221 == nil) goto v0364;
    stack[0] = v0198;
    v0221 = stack[-3];
    v0222 = qcdr(v0221);
    v0221 = stack[-2];
    fn = elt(env, 11); // multd
    v0221 = (*qfn2(fn))(qenv(fn), v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    fn = elt(env, 12); // sqfrf
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0221 = cons(stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[0] = v0221;
    goto v0022;

v0364:
    stack[0] = (LispObject)17; // 1
    v0221 = stack[-2];
    fn = elt(env, 12); // sqfrf
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    v0221 = cons(stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-4];
    stack[0] = v0221;
    goto v0022;

v0211:
    v0221 = qvalue(elt(env, 5)); // nil
    goto v0054;
// error exit handlers
v0214:
    popv(5);
    return nil;
}



// Code for ofsf_updsignvar

static LispObject CC_ofsf_updsignvar(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0173, v0014, v0013, v0033, v0103, v0092, v0122, v0131;
    LispObject v0047, v0140, v0004, v0009, v0003, v0041, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 7, "ofsf_updsignvar");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0140 = va_arg(aa, LispObject);
    v0047 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_updsignvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0013 = v0047;
    v0033 = v0140;
    v0103 = v0004;
    v0092 = v0009;
    v0122 = v0003;
    v0173 = v0041;
    v0131 = v0000;
// end of prologue
    v0014 = v0131;
    v0173 = Lmemq(nil, v0014, v0173);
    if (v0173 == nil) goto v0059;
    v0173 = elt(env, 1); // equal
    return onevalue(v0173);

v0059:
    v0173 = v0131;
    v0014 = v0122;
    v0173 = Lmemq(nil, v0173, v0014);
    if (v0173 == nil) goto v0044;
    v0173 = elt(env, 2); // greaterp
    return onevalue(v0173);

v0044:
    v0173 = v0131;
    v0014 = v0092;
    v0173 = Lmemq(nil, v0173, v0014);
    if (v0173 == nil) goto v0045;
    v0173 = elt(env, 3); // lessp
    return onevalue(v0173);

v0045:
    v0173 = v0131;
    v0014 = v0103;
    v0173 = Lmemq(nil, v0173, v0014);
    if (v0173 == nil) goto v0365;
    v0173 = elt(env, 4); // geq
    return onevalue(v0173);

v0365:
    v0173 = v0131;
    v0014 = v0033;
    v0173 = Lmemq(nil, v0173, v0014);
    if (v0173 == nil) goto v0120;
    v0173 = elt(env, 5); // leq
    return onevalue(v0173);

v0120:
    v0173 = v0131;
    v0014 = v0013;
    v0173 = Lmemq(nil, v0173, v0014);
    if (v0173 == nil) goto v0054;
    v0173 = elt(env, 6); // neq
    return onevalue(v0173);

v0054:
    v0173 = elt(env, 7); // unknown
    return onevalue(v0173);
}



// Code for make!-modular!-symmetric

static LispObject CC_makeKmodularKsymmetric(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0112, v0173;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-modular-symmetric");
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
    v0055 = stack[0];
    if (v0055 == nil) goto v0004;
    v0055 = stack[0];
    if (!consp(v0055)) goto v0119;
    v0055 = stack[0];
    v0055 = qcar(v0055);
    v0055 = (consp(v0055) ? nil : lisp_true);
    goto v0186;

v0186:
    if (v0055 == nil) goto v0045;
    v0112 = stack[0];
    v0055 = qvalue(elt(env, 3)); // modulus!/2
    v0055 = (LispObject)greaterp2(v0112, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-2];
    if (v0055 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0112 = stack[0];
    v0055 = qvalue(elt(env, 4)); // current!-modulus
    v0055 = difference2(v0112, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0055);
    }

v0045:
    v0055 = stack[0];
    v0055 = qcar(v0055);
    v0055 = qcdr(v0055);
    stack[-1] = CC_makeKmodularKsymmetric(env, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    v0055 = stack[0];
    v0055 = qcdr(v0055);
    v0055 = CC_makeKmodularKsymmetric(env, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    v0112 = stack[-1];
    v0173 = v0112;
    if (v0173 == nil) { popv(3); return onevalue(v0055); }
    v0173 = stack[0];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    popv(3);
    return acons(v0173, v0112, v0055);

v0119:
    v0055 = qvalue(elt(env, 2)); // t
    goto v0186;

v0004:
    v0055 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0055); }
// error exit handlers
v0033:
    popv(3);
    return nil;
}



// Code for lowupperlimitrd

static LispObject CC_lowupperlimitrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0113, v0153;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lowupperlimitrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lowupperlimitrd");
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
    stack[-2] = nil;
    fn = elt(env, 5); // mathml
    v0113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    stack[0] = v0113;
    fn = elt(env, 6); // lex
    v0113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    v0153 = qvalue(elt(env, 1)); // char
    v0113 = elt(env, 2); // (!/ l o w l i m i t)
    if (equal(v0153, v0113)) goto v0134;
    v0153 = elt(env, 3); // "</lowlimit>"
    v0113 = (LispObject)33; // 2
    fn = elt(env, 7); // errorml
    v0113 = (*qfn2(fn))(qenv(fn), v0153, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    goto v0154;

v0154:
    stack[-1] = elt(env, 4); // lowupperlimit
    v0113 = stack[-2];
    v0113 = ncons(v0113);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    {
        LispObject v0018 = stack[-1];
        LispObject v0017 = stack[0];
        popv(4);
        return list2star(v0018, v0017, v0113);
    }

v0134:
    fn = elt(env, 8); // upperlimitrd
    v0113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    stack[-2] = v0113;
    goto v0154;
// error exit handlers
v0046:
    popv(4);
    return nil;
}



// Code for plusrd

static LispObject CC_plusrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0049, v0059;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "plusrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plusrd");
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
    fn = elt(env, 2); // mathml
    v0049 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    v0059 = v0049;
    v0049 = v0059;
    if (v0049 == nil) goto v0030;
    stack[0] = v0059;
    v0049 = CC_plusrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    {
        LispObject v0057 = stack[0];
        popv(2);
        fn = elt(env, 3); // alg_plus
        return (*qfn2(fn))(qenv(fn), v0057, v0049);
    }

v0030:
    v0049 = (LispObject)1; // 0
    { popv(2); return onevalue(v0049); }
// error exit handlers
v0061:
    popv(2);
    return nil;
}



// Code for ldf!-simp

static LispObject CC_ldfKsimp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldf-simp");
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
    v0050 = v0051;
    if (v0050 == nil) goto v0004;
    v0050 = v0051;
    v0050 = qcdr(v0050);
    if (v0050 == nil) goto v0049;
    v0050 = v0051;
    fn = elt(env, 3); // prepf
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    fn = elt(env, 4); // simp
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0050 = qcar(v0050);
    v0051 = v0050;
    v0050 = v0051;
    if (!consp(v0050)) goto v0043;
    v0050 = v0051;
    v0050 = qcar(v0050);
    v0050 = (consp(v0050) ? nil : lisp_true);
    goto v0017;

v0017:
    if (!(v0050 == nil)) goto v0184;
    stack[0] = v0051;
    v0050 = v0051;
    fn = elt(env, 5); // comfac
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0050 = qcdr(v0050);
    fn = elt(env, 6); // quotf
    v0050 = (*qfn2(fn))(qenv(fn), stack[0], v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0051 = v0050;
    goto v0184;

v0184:
    v0050 = v0051;
    {
        popv(2);
        fn = elt(env, 7); // absf
        return (*qfn1(fn))(qenv(fn), v0050);
    }

v0043:
    v0050 = qvalue(elt(env, 2)); // t
    goto v0017;

v0049:
    v0050 = v0051;
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0051 = qcar(v0050);
    v0050 = (LispObject)17; // 1
    fn = elt(env, 8); // to
    v0051 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0050 = (LispObject)17; // 1
    v0050 = cons(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0050 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    fn = elt(env, 3); // prepf
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    fn = elt(env, 4); // simp
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0050 = qcar(v0050);
    { popv(2); return onevalue(v0050); }

v0004:
    v0050 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0050); }
// error exit handlers
v0016:
    popv(2);
    return nil;
}



setup_type const u31_setup[] =
{
    {"lengthreval",             CC_lengthreval, too_many_1,    wrong_no_1},
    {"build-null-vector",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_buildKnullKvector},
    {"makeqn-maybe",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeqnKmaybe},
    {"mk+mat+plus+mat",         too_few_2,      CC_mkLmatLplusLmat,wrong_no_2},
    {"pasf_premf",              too_few_2,      CC_pasf_premf, wrong_no_2},
    {"vdp_make",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_make},
    {"matrixelems",             CC_matrixelems, too_many_1,    wrong_no_1},
    {"transmat1",               CC_transmat1,   too_many_1,    wrong_no_1},
    {"dipcontevmin",            too_few_2,      CC_dipcontevmin,wrong_no_2},
    {"f2dip1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip1},
    {"contposp",                CC_contposp,    too_many_1,    wrong_no_1},
    {"indxsymp",                too_few_2,      CC_indxsymp,   wrong_no_2},
    {"getphystypeexpt",         CC_getphystypeexpt,too_many_1, wrong_no_1},
    {"calc_coeffmap_",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_calc_coeffmap_},
    {"s:prinl1",                too_few_2,      CC_sTprinl1,   wrong_no_2},
    {"squashsqrt",              CC_squashsqrt,  too_many_1,    wrong_no_1},
    {"ofsf_simplat1",           too_few_2,      CC_ofsf_simplat1,wrong_no_2},
    {"ofsf_negateat",           CC_ofsf_negateat,too_many_1,   wrong_no_1},
    {"sfto_subfwd",             too_few_2,      CC_sfto_subfwd,wrong_no_2},
    {"fnom",                    CC_fnom,        too_many_1,    wrong_no_1},
    {"a2bc",                    CC_a2bc,        too_many_1,    wrong_no_1},
    {"gfdiffer",                too_few_2,      CC_gfdiffer,   wrong_no_2},
    {"procstat1",               CC_procstat1,   too_many_1,    wrong_no_1},
    {"fs:minusp",               CC_fsTminusp,   too_many_1,    wrong_no_1},
    {"*multf",                  too_few_2,      CC_Hmultf,     wrong_no_2},
    {"solvealgdepends",         too_few_2,      CC_solvealgdepends,wrong_no_2},
    {"makecoeffpairshom",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairshom},
    {"termorder1",              too_few_2,      CC_termorder1, wrong_no_2},
    {"degree-order",            too_few_2,      CC_degreeKorder,wrong_no_2},
    {"vectorrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vectorrd},
    {"simpimpart",              CC_simpimpart,  too_many_1,    wrong_no_1},
    {"on-double1",              CC_onKdouble1,  too_many_1,    wrong_no_1},
    {"genexp",                  CC_genexp,      too_many_1,    wrong_no_1},
    {"xpartitop",               CC_xpartitop,   too_many_1,    wrong_no_1},
    {"simpunion",               CC_simpunion,   too_many_1,    wrong_no_1},
    {"spp",                     CC_spp,         too_many_1,    wrong_no_1},
    {"s_world_names",           CC_s_world_names,too_many_1,   wrong_no_1},
    {"factor-prim-f",           CC_factorKprimKf,too_many_1,   wrong_no_1},
    {"ofsf_updsignvar",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_updsignvar},
    {"make-modular-symmetric",  CC_makeKmodularKsymmetric,too_many_1,wrong_no_1},
    {"lowupperlimitrd",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowupperlimitrd},
    {"plusrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_plusrd},
    {"ldf-simp",                CC_ldfKsimp,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u31", (two_args *)"2436 1651131 6213390", 0}
};

// end of generated code
