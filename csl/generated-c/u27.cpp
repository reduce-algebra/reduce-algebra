
// $destdir\u27.c        Machine generated C code

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



// Code for color!-roads

static LispObject CC_colorKroads(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0032, v0033, v0034;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for color-roads");
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
    v0034 = v0000;
// end of prologue
    v0032 = stack[-4];
    v0032 = qcar(v0032);
    v0033 = qcar(v0032);
    v0032 = v0034;
    v0032 = Lassoc(nil, v0033, v0032);
    v0032 = qcdr(v0032);
    stack[-1] = v0032;
    v0032 = stack[-4];
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    v0033 = qcar(v0032);
    v0032 = v0034;
    v0032 = Lassoc(nil, v0033, v0032);
    v0032 = qcdr(v0032);
    stack[0] = v0032;
    v0032 = stack[-4];
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    v0032 = qcar(v0032);
    v0033 = v0034;
    v0032 = Lassoc(nil, v0032, v0033);
    v0032 = qcdr(v0032);
    stack[-5] = v0032;
    stack[-2] = stack[-1];
    v0033 = stack[0];
    v0032 = stack[-5];
    v0032 = plus2(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-6];
    v0033 = plus2(stack[-2], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-6];
    v0032 = (LispObject)33; // 2
    v0032 = quot2(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-6];
    stack[-2] = v0032;
    v0033 = stack[-2];
    v0032 = stack[-1];
    v0032 = difference2(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-6];
    stack[-1] = v0032;
    v0033 = stack[-2];
    v0032 = stack[0];
    v0032 = difference2(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-6];
    stack[0] = v0032;
    v0033 = stack[-2];
    v0032 = stack[-5];
    v0032 = difference2(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-6];
    stack[-5] = v0032;
    v0032 = stack[-4];
    v0032 = qcar(v0032);
    stack[-3] = qcar(v0032);
    stack[-2] = stack[-1];
    v0032 = stack[-4];
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    stack[-1] = qcar(v0032);
    v0032 = stack[-4];
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    v0033 = qcar(v0032);
    v0032 = stack[-5];
    v0032 = cons(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-6];
    v0032 = ncons(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-6];
    v0032 = acons(stack[-1], stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    {
        LispObject v0036 = stack[-3];
        LispObject v0037 = stack[-2];
        popv(7);
        return acons(v0036, v0037, v0032);
    }
// error exit handlers
v0035:
    popv(7);
    return nil;
}



// Code for greaterpcdr

static LispObject CC_greaterpcdr(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0040, v0041;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for greaterpcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0040 = v0001;
    v0041 = v0000;
// end of prologue
    v0041 = qcdr(v0041);
    v0040 = qcdr(v0040);
        return Lgreaterp(nil, v0041, v0040);
}



// Code for formproc

static LispObject CC_formproc(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0193, v0194, v0195, v0196;
    LispObject fn;
    LispObject v0088, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formproc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formproc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0088,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0088;
    stack[-1] = v0001;
    stack[0] = v0000;
// end of prologue
    stack[-6] = qvalue(elt(env, 1)); // fname!*
    qvalue(elt(env, 1)) = nil; // fname!*
    stack[-8] = nil;
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    stack[0] = v0193;
    v0193 = stack[0];
    v0193 = qcar(v0193);
    qvalue(elt(env, 1)) = v0193; // fname!*
    stack[-5] = v0193;
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    if (v0193 == nil) goto v0197;
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    stack[-2] = v0193;
    goto v0197;

v0197:
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0193 = qcdr(v0193);
    stack[0] = v0193;
    v0193 = stack[0];
    v0193 = qcar(v0193);
    qvalue(elt(env, 2)) = v0193; // ftype!*
    stack[-4] = v0193;
    v0193 = stack[-5];
    if (!symbolp(v0193)) v0193 = nil;
    else { v0193 = qfastgets(v0193);
           if (v0193 != nil) { v0193 = elt(v0193, 1); // lose
#ifdef RECORD_GET
             if (v0193 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v0193 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v0193 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v0193 == SPID_NOPROP) v0193 = nil; else v0193 = lisp_true; }}
#endif
    if (v0193 == nil) goto v0198;
    v0193 = qvalue(elt(env, 3)); // !*lose
    if (!(v0193 == nil)) goto v0199;
    v0193 = qvalue(elt(env, 4)); // !*defn
    v0193 = (v0193 == nil ? lisp_true : nil);
    goto v0199;

v0199:
    if (v0193 == nil) goto v0027;
    v0194 = stack[-5];
    v0193 = elt(env, 6); // "not defined (LOSE flag)"
    v0193 = list2(v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    fn = elt(env, 49); // lprim
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = elt(env, 7); // (quote nil)
    goto v0201;

v0201:
    qvalue(elt(env, 1)) = stack[-6]; // fname!*
    { popv(11); return onevalue(v0193); }

v0027:
    v0193 = qvalue(elt(env, 8)); // !*redeflg!*
    if (v0193 == nil) goto v0202;
    v0193 = stack[-5];
    fn = elt(env, 50); // getd
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    if (v0193 == nil) goto v0202;
    v0194 = stack[-5];
    v0193 = elt(env, 9); // "redefined"
    v0193 = list2(v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    fn = elt(env, 49); // lprim
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0202;

v0202:
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    stack[-3] = v0193;
    v0193 = stack[-3];
    if (v0193 == nil) goto v0031;
    v0193 = stack[-3];
    v0193 = qcar(v0193);
    if (v0193 == nil) goto v0203;
    v0193 = stack[-3];
    v0194 = qcar(v0193);
    v0193 = lisp_true;
    v0193 = (v0194 == v0193 ? lisp_true : nil);
    goto v0204;

v0204:
    if (v0193 == nil) goto v0031;
    v0193 = stack[-3];
    v0193 = qcar(v0193);
    fn = elt(env, 51); // rsverr
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0031;

v0031:
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    stack[-3] = v0193;
    goto v0205;

v0205:
    v0193 = stack[-3];
    if (v0193 == nil) goto v0206;
    v0193 = stack[-3];
    v0193 = qcar(v0193);
    v0193 = Lsymbol_specialp(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    if (!(v0193 == nil)) goto v0037;
    v0193 = stack[-3];
    v0193 = qcar(v0193);
    v0193 = Lsymbol_globalp(nil, v0193);
    env = stack[-10];
    if (!(v0193 == nil)) goto v0037;

v0009:
    v0193 = stack[-3];
    v0193 = qcdr(v0193);
    stack[-3] = v0193;
    goto v0205;

v0037:
    v0193 = stack[-3];
    v0194 = qcar(v0193);
    v0193 = stack[-8];
    v0193 = cons(v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-8] = v0193;
    goto v0009;

v0206:
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    stack[-3] = v0193;
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    stack[-7] = v0193;
    v0194 = stack[-7];
    v0193 = elt(env, 11); // rblock
    if (!consp(v0194)) goto v0207;
    v0194 = qcar(v0194);
    if (!(v0194 == v0193)) goto v0207;
    v0193 = stack[-7];
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    goto v0208;

v0208:
    stack[0] = v0193;
    v0196 = stack[-3];
    v0195 = stack[0];
    v0194 = stack[-1];
    v0193 = stack[-2];
    fn = elt(env, 52); // pairxvars
    v0193 = (*qfnn(fn))(qenv(fn), 4, v0196, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-1] = v0193;
    v0193 = stack[0];
    if (v0193 == nil) goto v0209;
    v0193 = stack[-7];
    stack[0] = qcar(v0193);
    v0193 = stack[-7];
    v0194 = qcdr(v0193);
    v0193 = stack[-1];
    v0193 = qcdr(v0193);
    fn = elt(env, 53); // rplaca!*
    v0193 = (*qfn2(fn))(qenv(fn), v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = cons(stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0209;

v0209:
    v0194 = stack[-5];
    v0193 = elt(env, 12); // formc
    v0193 = Lflagp(nil, v0194, v0193);
    env = stack[-10];
    if (v0193 == nil) goto v0210;
    v0195 = stack[-7];
    v0193 = stack[-1];
    v0194 = qcar(v0193);
    v0193 = stack[-2];
    fn = elt(env, 12); // formc
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0211;

v0211:
    stack[-7] = v0193;
    v0193 = qvalue(elt(env, 13)); // !*noinlines
    if (v0193 == nil) goto v0212;
    v0194 = stack[-4];
    v0193 = elt(env, 14); // inline
    if (!(v0194 == v0193)) goto v0212;
    v0193 = elt(env, 15); // expr
    stack[-4] = v0193;
    goto v0212;

v0212:
    v0193 = stack[-8];
    if (v0193 == nil) goto v0213;
    v0194 = stack[-4];
    v0193 = elt(env, 16); // (expr fexpr macro)
    v0193 = Lmemq(nil, v0194, v0193);
    if (v0193 == nil) goto v0213;
    stack[-1] = elt(env, 17); // progn
    stack[0] = elt(env, 18); // declare
    v0194 = elt(env, 19); // special
    v0193 = stack[-8];
    v0193 = cons(v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0194 = list2(stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = stack[-7];
    v0193 = list3(stack[-1], v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0213;

v0213:
    v0193 = stack[-7];
    stack[-8] = v0193;
    v0194 = stack[-4];
    v0193 = elt(env, 14); // inline
    if (!(v0194 == v0193)) goto v0214;
    v0195 = elt(env, 20); // lambda
    v0194 = stack[-3];
    v0193 = stack[-7];
    v0193 = list3(v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[0] = v0193;
    v0195 = stack[0];
    v0194 = stack[-5];
    v0193 = elt(env, 14); // inline
    v0193 = get(v0194, v0193);
    env = stack[-10];
    if (equal(v0195, v0193)) goto v0214;
    v0193 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = (LispObject)zerop(v0193);
    v0193 = v0193 ? lisp_true : nil;
    env = stack[-10];
    if (!(v0193 == nil)) goto v0215;
    v0193 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0215;

v0215:
    v0193 = elt(env, 21); // "+++ Record new inline definition:"
    v0193 = Lprinc(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0196 = elt(env, 22); // de
    v0195 = stack[-5];
    v0194 = stack[-3];
    v0193 = stack[-7];
    v0193 = list4(v0196, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = Lprint(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0195 = stack[-5];
    v0194 = stack[0];
    v0193 = qvalue(elt(env, 23)); // new_inline_definitions
    v0193 = acons(v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    qvalue(elt(env, 23)) = v0193; // new_inline_definitions
    goto v0214;

v0214:
    v0194 = stack[-4];
    v0193 = elt(env, 14); // inline
    if (v0194 == v0193) goto v0216;
    v0194 = stack[-5];
    v0193 = elt(env, 14); // inline
    v0193 = get(v0194, v0193);
    env = stack[-10];
    goto v0217;

v0217:
    if (!(v0193 == nil)) goto v0218;
    v0194 = stack[-4];
    v0193 = elt(env, 24); // smacro
    if (v0194 == v0193) goto v0219;
    v0194 = stack[-5];
    v0193 = elt(env, 24); // smacro
    v0193 = get(v0194, v0193);
    env = stack[-10];
    goto v0220;

v0220:
    if (!(v0193 == nil)) goto v0218;

v0221:
    v0195 = stack[-3];
    v0194 = stack[-7];
    v0193 = stack[-2];
    fn = elt(env, 54); // symbvarlst
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0194 = stack[-4];
    v0193 = elt(env, 15); // expr
    if (v0194 == v0193) goto v0222;
    v0194 = stack[-4];
    v0193 = elt(env, 26); // fexpr
    if (v0194 == v0193) goto v0223;
    v0194 = stack[-4];
    v0193 = elt(env, 28); // macro
    if (v0194 == v0193) goto v0224;
    v0194 = stack[-4];
    v0193 = elt(env, 30); // procfn
    v0193 = get(v0194, v0193);
    env = stack[-10];
    stack[0] = v0193;
    if (v0193 == nil) goto v0225;
    v0196 = stack[0];
    v0195 = stack[-5];
    v0194 = stack[-3];
    v0193 = stack[-7];
    v0193 = Lapply3(nil, 4, v0196, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0201;

v0225:
    stack[-9] = elt(env, 31); // putc
    v0193 = stack[-5];
    stack[-1] = Lmkquote(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = stack[-4];
    stack[0] = Lmkquote(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0195 = elt(env, 20); // lambda
    v0194 = stack[-3];
    v0193 = stack[-7];
    v0193 = list3(v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = Lmkquote(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = list4(stack[-9], stack[-1], stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0226;

v0226:
    v0194 = stack[-2];
    v0193 = elt(env, 32); // symbolic
    if (v0194 == v0193) goto v0227;
    stack[-1] = elt(env, 33); // flag
    v0193 = stack[-5];
    v0193 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[0] = Lmkquote(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = elt(env, 34); // opfn
    v0193 = Lmkquote(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0194 = list3(stack[-1], stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = stack[-7];
    fn = elt(env, 55); // mkprogn
    v0193 = (*qfn2(fn))(qenv(fn), v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0227;

v0227:
    v0193 = qvalue(elt(env, 35)); // !*argnochk
    if (v0193 == nil) goto v0228;
    v0194 = stack[-4];
    v0193 = elt(env, 36); // (expr inline smacro)
    v0193 = Lmemq(nil, v0194, v0193);
    if (v0193 == nil) goto v0228;
    v0193 = stack[-5];
    if (!symbolp(v0193)) v0193 = nil;
    else { v0193 = qfastgets(v0193);
           if (v0193 != nil) { v0193 = elt(v0193, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v0193 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v0193 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v0193 == SPID_NOPROP) v0193 = nil; }}
#endif
    stack[-9] = v0193;
    if (v0193 == nil) goto v0229;
    v0194 = stack[-5];
    v0193 = elt(env, 37); // variadic
    v0193 = Lflagp(nil, v0194, v0193);
    env = stack[-10];
    if (v0193 == nil) goto v0230;
    v0193 = qvalue(elt(env, 5)); // nil
    goto v0231;

v0231:
    if (v0193 == nil) goto v0229;
    v0193 = qvalue(elt(env, 38)); // !*strict_argcount
    if (v0193 == nil) goto v0232;
    v0195 = elt(env, 39); // "Definition of"
    v0194 = stack[-5];
    v0193 = elt(env, 40); // "different count from args previously called with"
    v0193 = list3(v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    fn = elt(env, 56); // lprie
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0229;

v0229:
    stack[-2] = elt(env, 44); // put
    v0193 = stack[-5];
    stack[-1] = Lmkquote(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = elt(env, 45); // number!-of!-args
    stack[0] = Lmkquote(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = stack[-3];
    v0193 = Llength(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0194 = list4(stack[-2], stack[-1], stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = stack[-7];
    fn = elt(env, 55); // mkprogn
    v0193 = (*qfn2(fn))(qenv(fn), v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0228;

v0228:
    v0193 = qvalue(elt(env, 4)); // !*defn
    if (v0193 == nil) goto v0233;
    v0194 = stack[-4];
    v0193 = elt(env, 46); // (fexpr macro inline smacro)
    v0193 = Lmemq(nil, v0194, v0193);
    if (v0193 == nil) goto v0233;
    v0193 = stack[-7];
    fn = elt(env, 57); // lispeval
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0233;

v0233:
    v0194 = stack[-4];
    v0193 = elt(env, 14); // inline
    if (!(v0194 == v0193)) goto v0234;
    v0196 = elt(env, 22); // de
    v0195 = stack[-5];
    v0194 = stack[-3];
    v0193 = stack[-8];
    v0194 = list4(v0196, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = stack[-7];
    fn = elt(env, 55); // mkprogn
    v0193 = (*qfn2(fn))(qenv(fn), v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = Lprint(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0234;

v0234:
    v0193 = qvalue(elt(env, 47)); // !*micro!-version
    if (v0193 == nil) goto v0235;
    v0194 = stack[-4];
    v0193 = elt(env, 48); // (fexpr macro smacro)
    v0193 = Lmemq(nil, v0194, v0193);
    if (v0193 == nil) goto v0235;
    v0193 = qvalue(elt(env, 5)); // nil
    goto v0201;

v0235:
    v0193 = stack[-7];
    goto v0201;

v0232:
    stack[-2] = stack[-5];
    stack[-1] = elt(env, 41); // "defined with"
    v0193 = stack[-3];
    stack[0] = Llength(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0195 = elt(env, 42); // "but previously called with"
    v0194 = stack[-9];
    v0193 = elt(env, 43); // "arguments"
    v0193 = list3(v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = list3star(stack[-2], stack[-1], stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    fn = elt(env, 49); // lprim
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0229;

v0230:
    stack[0] = stack[-9];
    v0193 = stack[-3];
    v0193 = Llength(nil, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    v0193 = Lneq(nil, stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0231;

v0224:
    v0196 = elt(env, 29); // dm
    v0195 = stack[-5];
    v0194 = stack[-3];
    v0193 = stack[-7];
    v0193 = list4(v0196, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0226;

v0223:
    v0196 = elt(env, 27); // df
    v0195 = stack[-5];
    v0194 = stack[-3];
    v0193 = stack[-7];
    v0193 = list4(v0196, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0226;

v0222:
    v0196 = elt(env, 22); // de
    v0195 = stack[-5];
    v0194 = stack[-3];
    v0193 = stack[-7];
    v0193 = list4(v0196, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    stack[-7] = v0193;
    goto v0226;

v0218:
    v0195 = elt(env, 25); // "SMACRO/INLINE"
    v0194 = stack[-5];
    v0193 = elt(env, 9); // "redefined"
    v0193 = list3(v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    fn = elt(env, 49); // lprim
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0221;

v0219:
    v0193 = qvalue(elt(env, 5)); // nil
    goto v0220;

v0216:
    v0193 = qvalue(elt(env, 5)); // nil
    goto v0217;

v0210:
    v0195 = stack[-7];
    v0193 = stack[-1];
    v0194 = qcar(v0193);
    v0193 = stack[-2];
    fn = elt(env, 58); // form1
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-10];
    goto v0211;

v0207:
    v0193 = qvalue(elt(env, 5)); // nil
    goto v0208;

v0203:
    v0193 = qvalue(elt(env, 10)); // t
    goto v0204;

v0198:
    v0193 = qvalue(elt(env, 5)); // nil
    goto v0199;
// error exit handlers
v0200:
    env = stack[-10];
    qvalue(elt(env, 1)) = stack[-6]; // fname!*
    popv(11);
    return nil;
}



// Code for subeval1

static LispObject CC_subeval1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0245, v0246, v0003;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subeval1");
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

v0052:
    v0245 = stack[-2];
    if (v0245 == nil) goto v0045;
    v0245 = stack[-2];
    v0245 = qcar(v0245);
    v0246 = qcar(v0245);
    v0245 = stack[-2];
    v0245 = qcar(v0245);
    v0245 = qcdr(v0245);
    if (!(equal(v0246, v0245))) goto v0045;
    v0245 = stack[-2];
    v0245 = qcdr(v0245);
    stack[-2] = v0245;
    goto v0052;

v0045:
    v0245 = stack[-2];
    if (v0245 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0245 = stack[-1];
    fn = elt(env, 7); // getrtype
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-4];
    v0003 = v0245;
    if (v0245 == nil) goto v0248;
    v0246 = v0003;
    v0245 = elt(env, 2); // subfn
    v0245 = get(v0246, v0245);
    env = stack[-4];
    v0246 = v0245;
    if (v0245 == nil) goto v0249;
    v0003 = v0246;
    v0246 = stack[-2];
    v0245 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v0003, v0246, v0245);

v0249:
    stack[-3] = elt(env, 3); // alg
    stack[0] = (LispObject)369; // 23
    v0245 = elt(env, 4); // "No substitution defined for type"
    v0246 = v0003;
    v0245 = list2(v0245, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-4];
    fn = elt(env, 8); // rerror
    v0245 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0245);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-4];
    goto v0248;

v0248:
    v0245 = stack[-1];
    fn = elt(env, 9); // simp
    v0246 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-4];
    v0245 = stack[-2];
    fn = elt(env, 10); // subsq
    v0245 = (*qfn2(fn))(qenv(fn), v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-4];
    stack[-2] = v0245;
    v0245 = qvalue(elt(env, 5)); // t
    stack[0] = qvalue(elt(env, 6)); // !*sub2
    qvalue(elt(env, 6)) = v0245; // !*sub2
    v0245 = stack[-2];
    fn = elt(env, 11); // subs2
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-4];
    stack[-2] = v0245;
    qvalue(elt(env, 6)) = stack[0]; // !*sub2
    v0245 = stack[-2];
    {
        popv(5);
        fn = elt(env, 12); // mk!*sq
        return (*qfn1(fn))(qenv(fn), v0245);
    }
// error exit handlers
v0250:
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; // !*sub2
    popv(5);
    return nil;
v0247:
    popv(5);
    return nil;
}



// Code for red_tailreddriver

static LispObject CC_red_tailreddriver(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0023;
    LispObject fn;
    LispObject v0088, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_tailreddriver");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_tailreddriver");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0088,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0088;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0023 = stack[-2];
    fn = elt(env, 3); // bas_dpoly
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    if (v0023 == nil) goto v0039;
    v0023 = stack[-2];
    fn = elt(env, 3); // bas_dpoly
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    v0023 = qcdr(v0023);
    if (v0023 == nil) goto v0206;
    v0023 = stack[-3];
    v0023 = (v0023 == nil ? lisp_true : nil);
    goto v0052;

v0052:
    if (!(v0023 == nil)) { LispObject res = stack[-2]; popv(6); return onevalue(res); }

v0253:
    v0023 = stack[-2];
    fn = elt(env, 3); // bas_dpoly
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    if (v0023 == nil) goto v0254;
    stack[-4] = stack[-1];
    stack[0] = stack[-3];
    v0023 = stack[-2];
    fn = elt(env, 4); // red!=hidelt
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    v0023 = Lapply2(nil, 3, stack[-4], stack[0], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    stack[-2] = v0023;
    goto v0253;

v0254:
    v0023 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); // red!=recover
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0206:
    v0023 = qvalue(elt(env, 1)); // t
    goto v0052;

v0039:
    v0023 = qvalue(elt(env, 1)); // t
    goto v0052;
// error exit handlers
v0024:
    popv(6);
    return nil;
}



// Code for dummyp

static LispObject CC_dummyp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0260, v0236, v0261;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dummyp");
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
    v0260 = (LispObject)1; // 0
    stack[-2] = v0260;
    v0260 = stack[-3];
    if (symbolp(v0260)) goto v0039;
    v0260 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0260); }

v0039:
    v0260 = (LispObject)17; // 1
    stack[-4] = v0260;
    goto v0243;

v0243:
    stack[0] = stack[-4];
    v0260 = qvalue(elt(env, 2)); // g_dvnames
    fn = elt(env, 4); // upbve
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-5];
    v0260 = (LispObject)lesseq2(stack[0], v0260);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    v0260 = v0260 ? lisp_true : nil;
    env = stack[-5];
    if (v0260 == nil) goto v0025;
    stack[-1] = stack[-3];
    stack[0] = qvalue(elt(env, 2)); // g_dvnames
    v0260 = stack[-4];
    v0260 = sub1(v0260);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-5];
    v0260 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0260/(16/CELL)));
    if (equal(stack[-1], v0260)) goto v0254;
    v0260 = stack[-4];
    v0260 = add1(v0260);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-5];
    stack[-4] = v0260;
    goto v0243;

v0254:
    v0260 = stack[-4];
    stack[-2] = v0260;
    v0260 = qvalue(elt(env, 2)); // g_dvnames
    fn = elt(env, 4); // upbve
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-5];
    v0260 = add1(v0260);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-5];
    stack[-4] = v0260;
    goto v0243;

v0025:
    v0236 = stack[-2];
    v0260 = (LispObject)1; // 0
    if (!(v0236 == v0260)) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0260 = stack[-3];
    fn = elt(env, 5); // ad_splitname
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-5];
    v0236 = v0260;
    v0260 = v0236;
    v0260 = qcar(v0260);
    v0261 = qvalue(elt(env, 3)); // g_dvbase
    if (v0260 == v0261) goto v0238;
    v0260 = nil;
    { popv(6); return onevalue(v0260); }

v0238:
    v0260 = v0236;
    v0260 = qcdr(v0260);
    { popv(6); return onevalue(v0260); }
// error exit handlers
v0245:
    popv(6);
    return nil;
}



// Code for msolve!-poly1

static LispObject CC_msolveKpoly1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0154, v0292, v0293;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for msolve-poly1");
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
    v0154 = stack[-5];
    if (!consp(v0154)) goto v0201;
    v0154 = stack[-5];
    v0154 = qcar(v0154);
    v0154 = (consp(v0154) ? nil : lisp_true);
    goto v0041;

v0041:
    if (!(v0154 == nil)) goto v0294;
    v0154 = stack[-5];
    v0154 = qcar(v0154);
    v0154 = qcar(v0154);
    v0292 = qcdr(v0154);
    v0154 = (LispObject)17; // 1
    if (!(v0292 == v0154)) goto v0294;
    v0154 = stack[-5];
    v0154 = qcar(v0154);
    v0154 = qcdr(v0154);
    fn = elt(env, 6); // safe!-modrecip
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[0] = v0154;
    v0154 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 3)) = v0154; // erfg!*
    v0154 = stack[0];
    if (v0154 == nil) goto v0294;
    v0154 = stack[-5];
    v0154 = qcdr(v0154);
    fn = elt(env, 7); // negf
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    fn = elt(env, 8); // multf
    v0154 = (*qfn2(fn))(qenv(fn), stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    fn = elt(env, 9); // moduntag
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[0] = v0154;
    v0154 = stack[0];
    if (v0154 == nil) goto v0296;
    v0292 = stack[0];
    v0154 = (LispObject)1; // 0
    v0154 = (LispObject)lessp2(v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    v0154 = v0154 ? lisp_true : nil;
    env = stack[-7];
    if (!(v0154 == nil)) goto v0297;
    v0292 = stack[0];
    v0154 = qvalue(elt(env, 4)); // current!-modulus
    v0154 = (LispObject)greaterp2(v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    v0154 = v0154 ? lisp_true : nil;
    env = stack[-7];
    if (!(v0154 == nil)) goto v0297;

v0296:
    v0154 = stack[0];
    v0154 = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[0] = v0154;
    goto v0045;

v0045:
    v0154 = stack[0];
    stack[-5] = v0154;
    v0154 = stack[-5];
    if (v0154 == nil) goto v0298;
    v0154 = stack[-5];
    v0154 = qcar(v0154);
    stack[0] = stack[-4];
    fn = elt(env, 10); // prepf
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = cons(stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[-2] = v0154;
    stack[-3] = v0154;
    goto v0212;

v0212:
    v0154 = stack[-5];
    v0154 = qcdr(v0154);
    stack[-5] = v0154;
    v0154 = stack[-5];
    if (v0154 == nil) { LispObject res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v0154 = stack[-5];
    v0154 = qcar(v0154);
    stack[0] = stack[-4];
    fn = elt(env, 10); // prepf
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = cons(stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = Lrplacd(nil, stack[-1], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = stack[-2];
    v0154 = qcdr(v0154);
    stack[-2] = v0154;
    goto v0212;

v0298:
    v0154 = qvalue(elt(env, 2)); // nil
    { popv(8); return onevalue(v0154); }

v0297:
    v0154 = stack[0];
    fn = elt(env, 11); // general!-modular!-number
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[0] = v0154;
    goto v0296;

v0294:
    v0293 = stack[-5];
    v0292 = stack[-4];
    v0154 = (LispObject)1; // 0
    fn = elt(env, 12); // lowestdeg
    v0154 = (*qfnn(fn))(qenv(fn), 3, v0293, v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[-6] = v0154;
    v0292 = stack[-6];
    v0154 = (LispObject)1; // 0
    v0154 = (LispObject)greaterp2(v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    v0154 = v0154 ? lisp_true : nil;
    env = stack[-7];
    if (v0154 == nil) goto v0245;
    stack[0] = stack[-5];
    v0293 = elt(env, 5); // expt
    v0292 = stack[-4];
    v0154 = stack[-6];
    v0154 = list3(v0293, v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    fn = elt(env, 13); // simp
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = qcar(v0154);
    fn = elt(env, 14); // quotf
    v0154 = (*qfn2(fn))(qenv(fn), stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[-5] = v0154;
    goto v0245;

v0245:
    v0154 = stack[-5];
    fn = elt(env, 9); // moduntag
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    fn = elt(env, 15); // general!-reduce!-mod!-p
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[-5] = v0154;
    v0154 = (LispObject)17; // 1
    stack[-3] = v0154;
    goto v0186;

v0186:
    v0154 = qvalue(elt(env, 4)); // current!-modulus
    v0292 = sub1(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = stack[-3];
    v0154 = difference2(v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = Lminusp(nil, v0154);
    env = stack[-7];
    if (v0154 == nil) goto v0299;
    v0154 = qvalue(elt(env, 2)); // nil
    goto v0300;

v0300:
    stack[0] = v0154;
    v0292 = stack[-6];
    v0154 = (LispObject)1; // 0
    v0154 = (LispObject)greaterp2(v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    v0154 = v0154 ? lisp_true : nil;
    env = stack[-7];
    if (v0154 == nil) goto v0045;
    v0154 = qvalue(elt(env, 2)); // nil
    v0154 = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = Lappend(nil, stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[0] = v0154;
    goto v0045;

v0299:
    v0293 = stack[-5];
    v0292 = stack[-4];
    v0154 = stack[-3];
    fn = elt(env, 16); // general!-evaluate!-mod!-p
    v0154 = (*qfnn(fn))(qenv(fn), 3, v0293, v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    if (v0154 == nil) goto v0208;
    v0154 = nil;
    goto v0182;

v0182:
    stack[-2] = v0154;
    v0154 = stack[-2];
    fn = elt(env, 17); // lastpair
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[-1] = v0154;
    v0154 = stack[-3];
    v0154 = add1(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[-3] = v0154;
    v0154 = stack[-1];
    if (!consp(v0154)) goto v0186;
    else goto v0179;

v0179:
    v0154 = qvalue(elt(env, 4)); // current!-modulus
    v0292 = sub1(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = stack[-3];
    v0154 = difference2(v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = Lminusp(nil, v0154);
    env = stack[-7];
    if (v0154 == nil) goto v0301;
    v0154 = stack[-2];
    goto v0300;

v0301:
    stack[0] = stack[-1];
    v0293 = stack[-5];
    v0292 = stack[-4];
    v0154 = stack[-3];
    fn = elt(env, 16); // general!-evaluate!-mod!-p
    v0154 = (*qfnn(fn))(qenv(fn), 3, v0293, v0292, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    if (v0154 == nil) goto v0302;
    v0154 = nil;
    goto v0174;

v0174:
    v0154 = Lrplacd(nil, stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    v0154 = stack[-1];
    fn = elt(env, 17); // lastpair
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[-1] = v0154;
    v0154 = stack[-3];
    v0154 = add1(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    stack[-3] = v0154;
    goto v0179;

v0302:
    v0154 = stack[-3];
    v0154 = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    goto v0174;

v0208:
    v0154 = stack[-3];
    v0154 = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-7];
    goto v0182;

v0201:
    v0154 = qvalue(elt(env, 1)); // t
    goto v0041;
// error exit handlers
v0295:
    popv(8);
    return nil;
}



// Code for reduce!-mod!-eigf

static LispObject CC_reduceKmodKeigf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0254, v0253;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-eigf");
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
    v0254 = v0000;
// end of prologue
    v0253 = qvalue(elt(env, 1)); // !*sub2
    stack[-2] = qvalue(elt(env, 1)); // !*sub2
    qvalue(elt(env, 1)) = v0253; // !*sub2
    v0253 = v0254;
    v0253 = qcar(v0253);
    stack[0] = qcar(v0253);
    v0253 = v0254;
    v0253 = qcdr(v0253);
    v0254 = qcar(v0254);
    v0254 = qcdr(v0254);
    v0254 = cons(v0253, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    fn = elt(env, 2); // cancel
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    fn = elt(env, 3); // negsq
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0253 = cons(stack[0], v0254);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0254 = stack[-1];
    fn = elt(env, 4); // reduce!-eival!-powers
    v0254 = (*qfn2(fn))(qenv(fn), v0253, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    fn = elt(env, 5); // subs2
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // !*sub2
    { popv(4); return onevalue(v0254); }
// error exit handlers
v0202:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // !*sub2
    popv(4);
    return nil;
}



// Code for domainvalchk

static LispObject CC_domainvalchk(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0307, v0256, v0257;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for domainvalchk");
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
    v0256 = qvalue(elt(env, 1)); // dmode!*
    v0307 = elt(env, 0); // domainvalchk
    v0307 = get(v0256, v0307);
    env = stack[-3];
    stack[-2] = v0307;
    if (v0307 == nil) goto v0045;
    v0257 = stack[-2];
    v0256 = stack[-1];
    v0307 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v0257, v0256, v0307);

v0045:
    v0307 = stack[0];
    v0307 = Lreverse(nil, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-3];
    stack[0] = v0307;
    goto v0015;

v0015:
    v0307 = stack[0];
    if (v0307 == nil) goto v0308;
    v0307 = stack[0];
    v0307 = qcar(v0307);
    v0256 = qcdr(v0307);
    v0307 = (LispObject)17; // 1
    if (v0256 == v0307) goto v0023;
    v0307 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0307); }

v0023:
    v0307 = stack[0];
    v0307 = qcar(v0307);
    fn = elt(env, 3); // mk!*sq
    v0256 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-3];
    v0307 = stack[-2];
    v0307 = cons(v0256, v0307);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-3];
    stack[-2] = v0307;
    v0307 = stack[0];
    v0307 = qcdr(v0307);
    stack[0] = v0307;
    goto v0015;

v0308:
    v0256 = stack[-1];
    v0307 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); // valuechk
        return (*qfn2(fn))(qenv(fn), v0256, v0307);
    }
// error exit handlers
v0237:
    popv(4);
    return nil;
}



// Code for dvfsf_smcpknowl

static LispObject CC_dvfsf_smcpknowl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0041;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_smcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0041 = v0000;
// end of prologue
    v0040 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0040 == nil) goto v0052;
    v0040 = v0041;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(qenv(fn), v0040);
    }

v0052:
    v0040 = v0041;
    {
        fn = elt(env, 3); // cl_smcpknowl
        return (*qfn1(fn))(qenv(fn), v0040);
    }
}



// Code for getargsrd

static LispObject CC_getargsrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0197, v0310;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "getargsrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getargsrd");
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
    v0310 = qvalue(elt(env, 1)); // char
    v0197 = elt(env, 2); // (b v a r)
    if (equal(v0310, v0197)) goto v0015;
    v0197 = nil;
    { popv(2); return onevalue(v0197); }

v0015:
    fn = elt(env, 3); // bvarrd
    v0197 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-1];
    stack[0] = v0197;
    fn = elt(env, 4); // lex
    v0197 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-1];
    v0197 = CC_getargsrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    {
        LispObject v0029 = stack[0];
        popv(2);
        return cons(v0029, v0197);
    }
// error exit handlers
v0028:
    popv(2);
    return nil;
}



// Code for matsm1

static LispObject CC_matsm1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0067, v0064;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matsm1");
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
    stack[-9] = nil;
    goto v0045;

v0045:
    v0066 = stack[-8];
    if (v0066 == nil) { LispObject res = stack[-9]; popv(11); return onevalue(res); }
    v0066 = stack[-8];
    v0067 = qcar(v0066);
    v0066 = elt(env, 1); // !*div
    if (!consp(v0067)) goto v0243;
    v0067 = qcar(v0067);
    if (!(v0067 == v0066)) goto v0243;
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = qcar(v0066);
    fn = elt(env, 16); // matsm
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-2] = v0066;
    v0066 = stack[-2];
    v0066 = qcar(v0066);
    stack[0] = Llength(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-1] = stack[0];
    v0066 = stack[-2];
    v0066 = Llength(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    if (equal(stack[0], v0066)) goto v0379;
    v0064 = elt(env, 5); // matrix
    v0067 = (LispObject)65; // 4
    v0066 = elt(env, 7); // "Non square matrix"
    fn = elt(env, 17); // rerror
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0064, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0380;

v0380:
    v0066 = qvalue(elt(env, 8)); // subfg!*
    stack[0] = v0066;
    v0066 = qvalue(elt(env, 4)); // nil
    qvalue(elt(env, 8)) = v0066; // subfg!*
    v0066 = stack[-9];
    if (v0066 == nil) goto v0381;
    v0067 = elt(env, 2); // mat
    v0066 = elt(env, 10); // lnrsolvefn
    v0066 = get(v0067, v0066);
    env = stack[-10];
    stack[0] = v0066;
    if (v0066 == nil) goto v0382;
    v0067 = elt(env, 2); // mat
    v0066 = elt(env, 10); // lnrsolvefn
    v0064 = get(v0067, v0066);
    env = stack[-10];
    v0067 = stack[-2];
    v0066 = stack[-9];
    v0066 = Lapply2(nil, 3, v0064, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0066;
    goto v0130;

v0130:
    v0066 = stack[0];
    qvalue(elt(env, 8)) = v0066; // subfg!*
    v0066 = stack[-9];
    stack[-7] = v0066;
    v0066 = stack[-7];
    if (v0066 == nil) goto v0108;
    v0066 = stack[-7];
    v0066 = qcar(v0066);
    stack[-3] = v0066;
    v0066 = stack[-3];
    if (v0066 == nil) goto v0383;
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0067 = v0066;
    v0066 = qvalue(elt(env, 11)); // t
    qvalue(elt(env, 12)) = v0066; // !*sub2
    v0066 = v0067;
    fn = elt(env, 18); // subs2
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-1] = v0066;
    stack[-2] = v0066;
    goto v0384;

v0384:
    v0066 = stack[-3];
    v0066 = qcdr(v0066);
    stack[-3] = v0066;
    v0066 = stack[-3];
    if (v0066 == nil) goto v0385;
    stack[0] = stack[-1];
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0067 = v0066;
    v0066 = qvalue(elt(env, 11)); // t
    qvalue(elt(env, 12)) = v0066; // !*sub2
    v0066 = v0067;
    fn = elt(env, 18); // subs2
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = Lrplacd(nil, stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = stack[-1];
    v0066 = qcdr(v0066);
    stack[-1] = v0066;
    goto v0384;

v0385:
    v0066 = stack[-2];
    goto v0224;

v0224:
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-5] = v0066;
    stack[-6] = v0066;
    goto v0386;

v0386:
    v0066 = stack[-7];
    v0066 = qcdr(v0066);
    stack[-7] = v0066;
    v0066 = stack[-7];
    if (v0066 == nil) goto v0387;
    stack[-4] = stack[-5];
    v0066 = stack[-7];
    v0066 = qcar(v0066);
    stack[-3] = v0066;
    v0066 = stack[-3];
    if (v0066 == nil) goto v0388;
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0067 = v0066;
    v0066 = qvalue(elt(env, 11)); // t
    qvalue(elt(env, 12)) = v0066; // !*sub2
    v0066 = v0067;
    fn = elt(env, 18); // subs2
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-1] = v0066;
    stack[-2] = v0066;
    goto v0093;

v0093:
    v0066 = stack[-3];
    v0066 = qcdr(v0066);
    stack[-3] = v0066;
    v0066 = stack[-3];
    if (v0066 == nil) goto v0081;
    stack[0] = stack[-1];
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0067 = v0066;
    v0066 = qvalue(elt(env, 11)); // t
    qvalue(elt(env, 12)) = v0066; // !*sub2
    v0066 = v0067;
    fn = elt(env, 18); // subs2
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = Lrplacd(nil, stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = stack[-1];
    v0066 = qcdr(v0066);
    stack[-1] = v0066;
    goto v0093;

v0081:
    v0066 = stack[-2];
    goto v0095;

v0095:
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = Lrplacd(nil, stack[-4], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = stack[-5];
    v0066 = qcdr(v0066);
    stack[-5] = v0066;
    goto v0386;

v0388:
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0095;

v0387:
    v0066 = stack[-6];
    goto v0389;

v0389:
    stack[-9] = v0066;
    goto v0039;

v0039:
    v0066 = stack[-8];
    v0066 = qcdr(v0066);
    stack[-8] = v0066;
    goto v0045;

v0383:
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0224;

v0108:
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0389;

v0382:
    v0067 = elt(env, 2); // mat
    v0066 = elt(env, 9); // inversefn
    v0067 = get(v0067, v0066);
    env = stack[-10];
    v0066 = stack[-2];
    v0067 = Lapply1(nil, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = stack[-9];
    fn = elt(env, 19); // multm
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0066;
    goto v0130;

v0381:
    v0067 = elt(env, 2); // mat
    v0066 = elt(env, 9); // inversefn
    v0067 = get(v0067, v0066);
    env = stack[-10];
    v0066 = stack[-2];
    v0066 = Lapply1(nil, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0066;
    goto v0130;

v0379:
    v0066 = stack[-9];
    if (v0066 == nil) goto v0390;
    stack[0] = stack[-1];
    v0066 = stack[-9];
    v0066 = Llength(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    if (equal(stack[0], v0066)) goto v0390;
    v0064 = elt(env, 5); // matrix
    v0067 = (LispObject)81; // 5
    v0066 = elt(env, 6); // "Matrix mismatch"
    fn = elt(env, 17); // rerror
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0064, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0380;

v0390:
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = qcdr(v0066);
    if (v0066 == nil) goto v0135;
    v0066 = stack[-9];
    if (!(v0066 == nil)) goto v0039;
    v0066 = stack[-1];
    fn = elt(env, 20); // generateident
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0066;
    goto v0039;

v0135:
    v0066 = stack[-2];
    v0066 = qcdr(v0066);
    if (v0066 == nil) goto v0216;
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0133;

v0133:
    if (v0066 == nil) goto v0380;
    v0066 = stack[-2];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    if (!(v0066 == nil)) goto v0391;
    v0064 = elt(env, 5); // matrix
    v0067 = (LispObject)97; // 6
    v0066 = elt(env, 13); // "Zero divisor"
    fn = elt(env, 17); // rerror
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0064, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0391;

v0391:
    v0066 = stack[-2];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    fn = elt(env, 21); // revpr
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-2] = v0066;
    v0066 = stack[-9];
    if (v0066 == nil) goto v0392;
    v0067 = stack[-2];
    v0066 = stack[-9];
    fn = elt(env, 22); // multsm
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0393;

v0393:
    stack[-9] = v0066;
    goto v0039;

v0392:
    v0066 = stack[-2];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0393;

v0216:
    v0066 = stack[-2];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = (v0066 == nil ? lisp_true : nil);
    goto v0133;

v0243:
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    if (!consp(v0066)) goto v0394;
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0067 = qcar(v0066);
    v0066 = elt(env, 2); // mat
    if (v0067 == v0066) goto v0168;
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0067 = qcar(v0066);
    v0066 = elt(env, 3); // matmapfn
    v0066 = Lflagp(nil, v0067, v0066);
    env = stack[-10];
    if (v0066 == nil) goto v0395;
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    if (v0066 == nil) goto v0249;
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = qcar(v0066);
    fn = elt(env, 23); // getrtype
    v0067 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = elt(env, 5); // matrix
    v0066 = (v0067 == v0066 ? lisp_true : nil);
    goto v0242;

v0242:
    if (v0066 == nil) goto v0396;
    v0066 = stack[-8];
    v0067 = qcar(v0066);
    v0066 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 24); // matrixmap
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    fn = elt(env, 16); // matsm
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[0] = v0066;
    goto v0052;

v0052:
    v0066 = stack[-9];
    if (v0066 == nil) goto v0299;
    v0066 = stack[-9];
    v0066 = qcdr(v0066);
    if (v0066 == nil) goto v0283;
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0183;

v0183:
    if (v0066 == nil) goto v0280;
    v0066 = stack[-9];
    v0066 = qcar(v0066);
    v0067 = qcar(v0066);
    v0066 = stack[0];
    fn = elt(env, 22); // multsm
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0397;

v0397:
    stack[-9] = v0066;
    goto v0039;

v0280:
    v0067 = stack[0];
    v0066 = stack[-9];
    fn = elt(env, 19); // multm
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0397;

v0283:
    v0066 = stack[-9];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = (v0066 == nil ? lisp_true : nil);
    goto v0183;

v0299:
    v0066 = stack[0];
    goto v0397;

v0396:
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    if (!symbolp(v0066)) v0066 = nil;
    else { v0066 = qfastgets(v0066);
           if (v0066 != nil) { v0066 = elt(v0066, 45); // psopfn
#ifdef RECORD_GET
             if (v0066 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0066 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0066 == SPID_NOPROP) v0066 = nil; }}
#endif
    stack[0] = v0066;
    if (v0066 == nil) goto v0279;
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    fn = elt(env, 25); // lispapply
    v0066 = (*qfn2(fn))(qenv(fn), stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[0] = v0066;
    v0067 = stack[0];
    v0066 = elt(env, 2); // mat
    if (!consp(v0067)) goto v0052;
    v0067 = qcar(v0067);
    if (!(v0067 == v0066)) goto v0052;
    v0066 = stack[0];
    fn = elt(env, 16); // matsm
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[0] = v0066;
    goto v0052;

v0279:
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0067 = qcar(v0066);
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    fn = elt(env, 25); // lispapply
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[0] = v0066;
    v0067 = stack[0];
    v0066 = elt(env, 2); // mat
    if (!consp(v0067)) goto v0052;
    v0067 = qcar(v0067);
    if (!(v0067 == v0066)) goto v0052;
    v0066 = stack[0];
    fn = elt(env, 16); // matsm
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[0] = v0066;
    goto v0052;

v0249:
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0242;

v0395:
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0242;

v0168:
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    fn = elt(env, 26); // lchk
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    if (!(v0066 == nil)) goto v0273;
    v0064 = elt(env, 5); // matrix
    v0067 = (LispObject)49; // 3
    v0066 = elt(env, 6); // "Matrix mismatch"
    fn = elt(env, 17); // rerror
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0064, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0273;

v0273:
    v0066 = stack[-8];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    stack[-7] = v0066;
    v0066 = stack[-7];
    if (v0066 == nil) goto v0171;
    v0066 = stack[-7];
    v0066 = qcar(v0066);
    stack[-3] = v0066;
    v0066 = stack[-3];
    if (v0066 == nil) goto v0166;
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    fn = elt(env, 27); // xsimp
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-1] = v0066;
    stack[-2] = v0066;
    goto v0398;

v0398:
    v0066 = stack[-3];
    v0066 = qcdr(v0066);
    stack[-3] = v0066;
    v0066 = stack[-3];
    if (v0066 == nil) goto v0163;
    stack[0] = stack[-1];
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    fn = elt(env, 27); // xsimp
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = Lrplacd(nil, stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = stack[-1];
    v0066 = qcdr(v0066);
    stack[-1] = v0066;
    goto v0398;

v0163:
    v0066 = stack[-2];
    goto v0270;

v0270:
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-5] = v0066;
    stack[-6] = v0066;
    goto v0399;

v0399:
    v0066 = stack[-7];
    v0066 = qcdr(v0066);
    stack[-7] = v0066;
    v0066 = stack[-7];
    if (v0066 == nil) goto v0400;
    stack[-4] = stack[-5];
    v0066 = stack[-7];
    v0066 = qcar(v0066);
    stack[-3] = v0066;
    v0066 = stack[-3];
    if (v0066 == nil) goto v0401;
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    fn = elt(env, 27); // xsimp
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-1] = v0066;
    stack[-2] = v0066;
    goto v0293;

v0293:
    v0066 = stack[-3];
    v0066 = qcdr(v0066);
    stack[-3] = v0066;
    v0066 = stack[-3];
    if (v0066 == nil) goto v0402;
    stack[0] = stack[-1];
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    fn = elt(env, 27); // xsimp
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = Lrplacd(nil, stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = stack[-1];
    v0066 = qcdr(v0066);
    stack[-1] = v0066;
    goto v0293;

v0402:
    v0066 = stack[-2];
    goto v0292;

v0292:
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = Lrplacd(nil, stack[-4], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0066 = stack[-5];
    v0066 = qcdr(v0066);
    stack[-5] = v0066;
    goto v0399;

v0401:
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0292;

v0400:
    v0066 = stack[-6];
    goto v0403;

v0403:
    stack[0] = v0066;
    goto v0052;

v0166:
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0270;

v0171:
    v0066 = qvalue(elt(env, 4)); // nil
    goto v0403;

v0394:
    stack[-1] = elt(env, 5); // matrix
    stack[0] = (LispObject)113; // 7
    v0064 = elt(env, 14); // "Matrix"
    v0066 = stack[-8];
    v0067 = qcar(v0066);
    v0066 = elt(env, 15); // "not set"
    v0066 = list3(v0064, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    fn = elt(env, 17); // rerror
    v0066 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    v0066 = nil;
    { popv(11); return onevalue(v0066); }
// error exit handlers
v0068:
    popv(11);
    return nil;
}



// Code for amatch

static LispObject CC_amatch(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0276, v0279, v0275, v0272;
    LispObject fn;
    LispObject v0010, v0011, v0012, v0088;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "amatch");
    va_start(aa, nargs);
    v0088 = va_arg(aa, LispObject);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for amatch");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0010,v0011,v0012,v0088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0088,v0012,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0010;
    stack[-4] = v0011;
    v0279 = v0012;
    v0276 = v0088;
// end of prologue
    stack[-5] = qvalue(elt(env, 1)); // r
    qvalue(elt(env, 1)) = nil; // r
    stack[-2] = qvalue(elt(env, 2)); // p
    qvalue(elt(env, 2)) = nil; // p
    qvalue(elt(env, 1)) = v0276; // r
    v0276 = v0279;
    qvalue(elt(env, 2)) = v0276; // p
    goto v0030;

v0030:
    v0276 = qvalue(elt(env, 1)); // r
    if (!consp(v0276)) goto v0309;
    v0276 = qvalue(elt(env, 2)); // p
    if (!consp(v0276)) goto v0406;
    v0276 = qvalue(elt(env, 1)); // r
    v0279 = qcar(v0276);
    v0276 = qvalue(elt(env, 2)); // p
    v0276 = qcar(v0276);
    v0276 = Lneq(nil, v0279, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    goto v0408;

v0408:
    if (v0276 == nil) goto v0241;
    v0276 = qvalue(elt(env, 1)); // r
    fn = elt(env, 7); // suchp
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    if (v0276 == nil) goto v0255;
    v0276 = qvalue(elt(env, 1)); // r
    v0276 = qcdr(v0276);
    v0276 = qcar(v0276);
    stack[0] = v0276;
    v0276 = qvalue(elt(env, 1)); // r
    v0276 = qcdr(v0276);
    v0276 = qcdr(v0276);
    v0279 = qcar(v0276);
    v0276 = stack[-4];
    v0276 = cons(v0279, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    stack[-4] = v0276;
    v0276 = stack[0];
    qvalue(elt(env, 1)) = v0276; // r
    goto v0030;

v0255:
    v0276 = qvalue(elt(env, 5)); // !*semantic
    if (v0276 == nil) goto v0033;
    v0275 = elt(env, 6); // equal
    v0279 = qvalue(elt(env, 1)); // r
    v0276 = qvalue(elt(env, 2)); // p
    v0279 = list3(v0275, v0279, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0276 = stack[-4];
    v0279 = cons(v0279, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0276 = stack[-3];
    fn = elt(env, 8); // resume
    v0276 = (*qfn2(fn))(qenv(fn), v0279, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    goto v0039;

v0039:
    qvalue(elt(env, 2)) = stack[-2]; // p
    qvalue(elt(env, 1)) = stack[-5]; // r
    { popv(7); return onevalue(v0276); }

v0033:
    v0276 = qvalue(elt(env, 3)); // nil
    goto v0039;

v0241:
    v0276 = qvalue(elt(env, 1)); // r
    stack[0] = qcar(v0276);
    v0276 = qvalue(elt(env, 1)); // r
    v0276 = qcdr(v0276);
    fn = elt(env, 9); // mval
    v0272 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0276 = qvalue(elt(env, 2)); // p
    v0275 = qcdr(v0276);
    v0279 = stack[-4];
    v0276 = stack[-3];
    fn = elt(env, 10); // unify
    v0276 = (*qfnn(fn))(qenv(fn), 5, stack[0], v0272, v0275, v0279, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    goto v0039;

v0406:
    v0276 = qvalue(elt(env, 4)); // t
    goto v0408;

v0309:
    stack[-1] = qvalue(elt(env, 3)); // nil
    v0276 = qvalue(elt(env, 1)); // r
    v0276 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    fn = elt(env, 9); // mval
    stack[0] = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0276 = qvalue(elt(env, 2)); // p
    v0275 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0279 = stack[-4];
    v0276 = stack[-3];
    fn = elt(env, 10); // unify
    v0276 = (*qfnn(fn))(qenv(fn), 5, stack[-1], stack[0], v0275, v0279, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    goto v0039;
// error exit handlers
v0407:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; // p
    qvalue(elt(env, 1)) = stack[-5]; // r
    popv(7);
    return nil;
}



// Code for evinvlexcomp

static LispObject CC_evinvlexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0294, v0013;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evinvlexcomp");
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

v0010:
    v0294 = stack[-1];
    if (v0294 == nil) goto v0045;
    v0294 = stack[0];
    if (v0294 == nil) goto v0243;
    v0294 = stack[-1];
    v0013 = qcar(v0294);
    v0294 = stack[0];
    v0294 = qcar(v0294);
    fn = elt(env, 2); // iequal
    v0294 = (*qfn2(fn))(qenv(fn), v0013, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    if (v0294 == nil) goto v0396;
    v0294 = stack[-1];
    v0294 = qcdr(v0294);
    stack[-1] = v0294;
    v0294 = stack[0];
    v0294 = qcdr(v0294);
    stack[0] = v0294;
    goto v0010;

v0396:
    v0294 = stack[-1];
    v0013 = qcdr(v0294);
    v0294 = stack[0];
    v0294 = qcdr(v0294);
    v0294 = CC_evinvlexcomp(env, v0013, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    stack[-2] = v0294;
    v0013 = stack[-2];
    v0294 = (LispObject)1; // 0
    fn = elt(env, 2); // iequal
    v0294 = (*qfn2(fn))(qenv(fn), v0013, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    if (v0294 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0294 = stack[0];
    v0013 = qcar(v0294);
    v0294 = stack[-1];
    v0294 = qcar(v0294);
    if (((int32_t)(v0013)) > ((int32_t)(v0294))) goto v0018;
    v0294 = (LispObject)-15; // -1
    { popv(4); return onevalue(v0294); }

v0018:
    v0294 = (LispObject)17; // 1
    { popv(4); return onevalue(v0294); }

v0243:
    v0013 = stack[-1];
    v0294 = elt(env, 1); // (0)
    {
        popv(4);
        fn = elt(env, 3); // evlexcomp
        return (*qfn2(fn))(qenv(fn), v0013, v0294);
    }

v0045:
    v0294 = stack[0];
    if (v0294 == nil) goto v0040;
    v0294 = elt(env, 1); // (0)
    stack[-1] = v0294;
    goto v0010;

v0040:
    v0294 = (LispObject)1; // 0
    { popv(4); return onevalue(v0294); }
// error exit handlers
v0261:
    popv(4);
    return nil;
}



// Code for dipprodin

static LispObject CC_dipprodin(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0021, v0249, v0410;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipprodin");
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
    goto v0053;

v0053:
    v0021 = stack[-1];
    if (v0021 == nil) goto v0030;
    v0021 = stack[0];
    v0021 = (v0021 == nil ? lisp_true : nil);
    goto v0201;

v0201:
    if (v0021 == nil) goto v0411;
    v0021 = qvalue(elt(env, 2)); // dipzero
    v0249 = v0021;
    goto v0052;

v0052:
    v0021 = stack[-2];
    if (v0021 == nil) { popv(4); return onevalue(v0249); }
    v0021 = stack[-2];
    v0021 = qcar(v0021);
    fn = elt(env, 3); // dipsum
    v0021 = (*qfn2(fn))(qenv(fn), v0021, v0249);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-3];
    v0249 = v0021;
    v0021 = stack[-2];
    v0021 = qcdr(v0021);
    stack[-2] = v0021;
    goto v0052;

v0411:
    v0021 = stack[-1];
    v0021 = qcdr(v0021);
    v0410 = qcar(v0021);
    v0021 = stack[-1];
    v0249 = qcar(v0021);
    v0021 = stack[0];
    fn = elt(env, 4); // dipprodin1
    v0249 = (*qfnn(fn))(qenv(fn), 3, v0410, v0249, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-3];
    v0021 = stack[-2];
    v0021 = cons(v0249, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-3];
    stack[-2] = v0021;
    v0021 = stack[-1];
    v0021 = qcdr(v0021);
    v0021 = qcdr(v0021);
    stack[-1] = v0021;
    goto v0053;

v0030:
    v0021 = qvalue(elt(env, 1)); // t
    goto v0201;
// error exit handlers
v0291:
    popv(4);
    return nil;
}



// Code for unplus

static LispObject CC_unplus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0255, v0248, v0412;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unplus");
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
    v0412 = nil;
    goto v0010;

v0010:
    v0255 = stack[-1];
    if (!consp(v0255)) goto v0038;
    v0255 = stack[-1];
    v0248 = qcar(v0255);
    v0255 = elt(env, 1); // plus
    if (v0248 == v0255) goto v0206;
    v0255 = stack[-1];
    v0255 = qcar(v0255);
    if (!consp(v0255)) goto v0254;
    v0255 = stack[-1];
    v0248 = qcar(v0255);
    v0255 = elt(env, 1); // plus
    v0255 = Leqcar(nil, v0248, v0255);
    env = stack[-3];
    v0255 = (v0255 == nil ? lisp_true : nil);
    goto v0303;

v0303:
    if (v0255 == nil) goto v0021;
    v0255 = stack[-1];
    v0255 = qcar(v0255);
    v0248 = v0412;
    v0255 = cons(v0255, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0412 = v0255;
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    stack[-1] = v0255;
    goto v0010;

v0021:
    stack[-2] = v0412;
    v0255 = stack[-1];
    v0255 = qcar(v0255);
    stack[0] = qcdr(v0255);
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    v0255 = CC_unplus(env, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0255 = Lappend(nil, stack[0], v0255);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    {
        LispObject v0260 = stack[-2];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0260, v0255);
    }

v0254:
    v0255 = qvalue(elt(env, 2)); // t
    goto v0303;

v0206:
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    stack[-1] = v0255;
    goto v0010;

v0038:
    v0248 = v0412;
    v0255 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0248, v0255);
    }
// error exit handlers
v0014:
    popv(4);
    return nil;
}



// Code for chkint!*

static LispObject CC_chkintH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0250, v0288, v0289;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chkint*");
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
    v0250 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v0250 == nil) goto v0191;
    v0250 = stack[0];
    v0250 = Lfloatp(nil, v0250);
    env = stack[-1];
    if (v0250 == nil) goto v0201;
    v0250 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // fl2bf
        return (*qfn1(fn))(qenv(fn), v0250);
    }

v0201:
    v0250 = stack[0];
    if (!consp(v0250)) goto v0305;
    v0250 = stack[0];
    goto v0206;

v0206:
    {
        popv(2);
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(qenv(fn), v0250);
    }

v0305:
    v0250 = stack[0];
    v0250 = integerp(v0250);
    if (v0250 == nil) goto v0414;
    v0289 = elt(env, 2); // !:rd!:
    v0288 = stack[0];
    v0250 = (LispObject)1; // 0
    v0250 = list2star(v0289, v0288, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    goto v0206;

v0414:
    v0250 = stack[0];
    fn = elt(env, 6); // read!:num
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    goto v0206;

v0191:
    v0250 = stack[0];
    v0250 = Labsval(nil, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0288 = v0250;
    v0250 = stack[0];
    v0250 = Lfloatp(nil, v0250);
    env = stack[-1];
    if (!(v0250 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0250 = v0288;
    fn = elt(env, 7); // msd
    v0288 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0250 = qvalue(elt(env, 3)); // !!maxbflexp
    v0250 = (LispObject)lesseq2(v0288, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    v0250 = v0250 ? lisp_true : nil;
    env = stack[-1];
    if (v0250 == nil) goto v0410;
    v0250 = stack[0];
        popv(2);
        return Lfloat(nil, v0250);

v0410:
    fn = elt(env, 8); // rndbfon
    v0250 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0250 = stack[0];
    v0250 = Lfloatp(nil, v0250);
    env = stack[-1];
    if (v0250 == nil) goto v0415;
    v0250 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // fl2bf
        return (*qfn1(fn))(qenv(fn), v0250);
    }

v0415:
    v0250 = stack[0];
    if (!consp(v0250)) goto v0248;
    v0250 = stack[0];
    goto v0190;

v0190:
    {
        popv(2);
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(qenv(fn), v0250);
    }

v0248:
    v0250 = stack[0];
    v0250 = integerp(v0250);
    if (v0250 == nil) goto v0004;
    v0289 = elt(env, 2); // !:rd!:
    v0288 = stack[0];
    v0250 = (LispObject)1; // 0
    v0250 = list2star(v0289, v0288, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    goto v0190;

v0004:
    v0250 = stack[0];
    fn = elt(env, 6); // read!:num
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    goto v0190;
// error exit handlers
v0188:
    popv(2);
    return nil;
}



// Code for color!-strand

static LispObject CC_colorKstrand(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0202, v0026, v0027;
    LispObject fn;
    LispObject v0088, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color-strand");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for color-strand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0088,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0088;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0053;

v0053:
    v0202 = stack[-1];
    if (v0202 == nil) goto v0039;
    v0026 = stack[-2];
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    fn = elt(env, 1); // color!-roads
    v0027 = (*qfn2(fn))(qenv(fn), v0026, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-4];
    v0026 = stack[0];
    v0202 = stack[-3];
    v0202 = acons(v0027, v0026, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-4];
    stack[-3] = v0202;
    v0202 = stack[-1];
    v0202 = qcdr(v0202);
    stack[-1] = v0202;
    v0202 = stack[0];
    v0202 = add1(v0202);
    nil = C_nil;
    if (exception_pending()) goto v0372;
    env = stack[-4];
    stack[0] = v0202;
    goto v0053;

v0039:
    v0202 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0202);
    }
// error exit handlers
v0372:
    popv(5);
    return nil;
}



// Code for mkfil!*

static LispObject CC_mkfilH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027, v0191;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkfil*");
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
    v0191 = nil;
    v0027 = stack[0];
    v0027 = Lstringp(nil, v0027);
    env = stack[-1];
    if (!(v0027 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0027 = stack[0];
    if (symbolp(v0027)) goto v0040;
    v0191 = stack[0];
    v0027 = elt(env, 1); // "file name"
    {
        popv(2);
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(qenv(fn), v0191, v0027);
    }

v0040:
    v0027 = stack[0];
    if (!symbolp(v0027)) v0027 = nil;
    else { v0027 = qfastgets(v0027);
           if (v0027 != nil) { v0027 = elt(v0027, 17); // share
#ifdef RECORD_GET
             if (v0027 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0027 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0027 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0027 == SPID_NOPROP) v0027 = nil; else v0027 = lisp_true; }}
#endif
    if (v0027 == nil) goto v0303;
    v0027 = stack[0];
    fn = elt(env, 4); // eval
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-1];
    v0191 = v0027;
    v0027 = Lstringp(nil, v0027);
    env = stack[-1];
    goto v0310;

v0310:
    if (!(v0027 == nil)) { popv(2); return onevalue(v0191); }
    v0027 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // string!-downcase
        return (*qfn1(fn))(qenv(fn), v0027);
    }

v0303:
    v0027 = qvalue(elt(env, 2)); // nil
    goto v0310;
// error exit handlers
v0408:
    popv(2);
    return nil;
}



// Code for ratfunpri1

static LispObject CC_ratfunpri1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0440, v0441, v0442;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratfunpri1");
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
    v0441 = qvalue(elt(env, 1)); // spare!*
    v0440 = (LispObject)33; // 2
    v0440 = plus2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    qvalue(elt(env, 1)) = v0440; // spare!*
    v0440 = stack[0];
    v0440 = qcdr(v0440);
    v0442 = qcar(v0440);
    v0441 = (LispObject)1; // 0
    v0440 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 15); // layout!-formula
    v0440 = (*qfnn(fn))(qenv(fn), 3, v0442, v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-7] = v0440;
    if (v0440 == nil) goto v0444;
    v0440 = stack[0];
    v0440 = qcdr(v0440);
    v0440 = qcdr(v0440);
    v0442 = qcar(v0440);
    v0441 = (LispObject)1; // 0
    v0440 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 15); // layout!-formula
    v0440 = (*qfnn(fn))(qenv(fn), 3, v0442, v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-6] = v0440;
    if (v0440 == nil) goto v0444;
    v0441 = qvalue(elt(env, 1)); // spare!*
    v0440 = (LispObject)33; // 2
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    qvalue(elt(env, 1)) = v0440; // spare!*
    stack[0] = (LispObject)33; // 2
    v0440 = stack[-7];
    v0440 = qcar(v0440);
    v0441 = qcdr(v0440);
    v0440 = stack[-6];
    v0440 = qcar(v0440);
    v0440 = qcdr(v0440);
    fn = elt(env, 16); // max
    v0440 = (*qfn2(fn))(qenv(fn), v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = plus2(stack[0], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-2] = v0440;
    stack[0] = stack[-2];
    v0440 = qvalue(elt(env, 2)); // nil
    v0441 = Llinelength(nil, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = qvalue(elt(env, 1)); // spare!*
    v0441 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = qvalue(elt(env, 3)); // posn!*
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = (LispObject)greaterp2(stack[0], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    v0440 = v0440 ? lisp_true : nil;
    env = stack[-8];
    if (v0440 == nil) goto v0445;
    v0440 = qvalue(elt(env, 4)); // t
    fn = elt(env, 17); // terpri!*
    v0440 = (*qfn1(fn))(qenv(fn), v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    goto v0445;

v0445:
    v0440 = stack[-7];
    v0440 = qcar(v0440);
    v0441 = qcdr(v0440);
    v0440 = stack[-6];
    v0440 = qcar(v0440);
    v0440 = qcdr(v0440);
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-1] = v0440;
    v0441 = stack[-1];
    v0440 = (LispObject)1; // 0
    v0440 = (LispObject)greaterp2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    v0440 = v0440 ? lisp_true : nil;
    env = stack[-8];
    if (v0440 == nil) goto v0286;
    v0440 = (LispObject)1; // 0
    stack[0] = v0440;
    v0441 = stack[-1];
    v0440 = (LispObject)33; // 2
    v0440 = quot2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-3] = v0440;
    goto v0446;

v0446:
    v0440 = stack[-7];
    v0440 = qcdr(v0440);
    v0441 = qcdr(v0440);
    v0440 = stack[-7];
    v0440 = qcdr(v0440);
    v0440 = qcar(v0440);
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = add1(v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-5] = v0440;
    v0440 = stack[-6];
    v0440 = qcdr(v0440);
    v0441 = qcdr(v0440);
    v0440 = stack[-6];
    v0440 = qcdr(v0440);
    v0440 = qcar(v0440);
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = add1(v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-4] = v0440;
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 3)); // posn!*
    v0441 = (LispObject)17; // 1
    v0440 = qvalue(elt(env, 5)); // orig!*
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = plus2(stack[0], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[0] = plus2(stack[-1], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0441 = (LispObject)17; // 1
    v0440 = stack[-7];
    v0440 = qcdr(v0440);
    v0440 = qcar(v0440);
    v0441 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = qvalue(elt(env, 6)); // ycoord!*
    v0441 = plus2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = stack[-7];
    v0440 = qcar(v0440);
    v0440 = qcar(v0440);
    fn = elt(env, 18); // update!-pline
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[0], v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[0] = qvalue(elt(env, 3)); // posn!*
    v0441 = (LispObject)17; // 1
    v0440 = qvalue(elt(env, 5)); // orig!*
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = plus2(stack[0], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[0] = plus2(stack[-3], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0441 = qvalue(elt(env, 6)); // ycoord!*
    v0440 = stack[-6];
    v0440 = qcdr(v0440);
    v0440 = qcdr(v0440);
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0441 = sub1(v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = stack[-6];
    v0440 = qcar(v0440);
    v0440 = qcar(v0440);
    fn = elt(env, 18); // update!-pline
    v0441 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = qvalue(elt(env, 7)); // pline!*
    v0440 = Lappend(nil, v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = Lappend(nil, stack[-1], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    qvalue(elt(env, 7)) = v0440; // pline!*
    stack[0] = qvalue(elt(env, 8)); // ymin!*
    v0441 = qvalue(elt(env, 6)); // ycoord!*
    v0440 = stack[-4];
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    fn = elt(env, 19); // min
    v0440 = (*qfn2(fn))(qenv(fn), stack[0], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    qvalue(elt(env, 8)) = v0440; // ymin!*
    stack[0] = qvalue(elt(env, 9)); // ymax!*
    v0441 = qvalue(elt(env, 6)); // ycoord!*
    v0440 = stack[-5];
    v0440 = plus2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    fn = elt(env, 16); // max
    v0440 = (*qfn2(fn))(qenv(fn), stack[0], v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    qvalue(elt(env, 9)) = v0440; // ymax!*
    v0440 = elt(env, 10); // bar
    fn = elt(env, 20); // symbol
    v0440 = (*qfn1(fn))(qenv(fn), v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-1] = v0440;
    v0440 = (LispObject)17; // 1
    stack[0] = v0440;
    goto v0447;

v0447:
    v0441 = stack[-2];
    v0440 = stack[0];
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = Lminusp(nil, v0440);
    env = stack[-8];
    if (!(v0440 == nil)) goto v0259;
    v0440 = stack[-1];
    fn = elt(env, 21); // prin2!*
    v0440 = (*qfn1(fn))(qenv(fn), v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = stack[0];
    v0440 = add1(v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[0] = v0440;
    goto v0447;

v0259:
    v0440 = nil;
    { popv(9); return onevalue(v0440); }

v0286:
    v0440 = stack[-1];
    v0441 = negate(v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = (LispObject)33; // 2
    v0440 = quot2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[0] = v0440;
    v0440 = (LispObject)1; // 0
    stack[-3] = v0440;
    goto v0446;

v0444:
    v0441 = qvalue(elt(env, 1)); // spare!*
    v0440 = (LispObject)33; // 2
    v0440 = difference2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    qvalue(elt(env, 1)) = v0440; // spare!*
    v0440 = stack[0];
    v0440 = qcdr(v0440);
    stack[0] = v0440;
    v0440 = elt(env, 11); // quotient
    if (!symbolp(v0440)) v0440 = nil;
    else { v0440 = qfastgets(v0440);
           if (v0440 != nil) { v0440 = elt(v0440, 23); // infix
#ifdef RECORD_GET
             if (v0440 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0440 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0440 == SPID_NOPROP) v0440 = nil; }}
#endif
    stack[-2] = v0440;
    v0440 = qvalue(elt(env, 12)); // p!*!*
    if (v0440 == nil) goto v0448;
    v0441 = qvalue(elt(env, 12)); // p!*!*
    v0440 = stack[-2];
    v0440 = (LispObject)greaterp2(v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    v0440 = v0440 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v0440;
    goto v0449;

v0449:
    v0440 = stack[-1];
    if (v0440 == nil) goto v0450;
    v0440 = elt(env, 13); // "("
    fn = elt(env, 21); // prin2!*
    v0440 = (*qfn1(fn))(qenv(fn), v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    goto v0450;

v0450:
    v0440 = stack[0];
    v0441 = qcar(v0440);
    v0440 = stack[-2];
    fn = elt(env, 22); // maprint
    v0440 = (*qfn2(fn))(qenv(fn), v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = elt(env, 11); // quotient
    fn = elt(env, 23); // oprin
    v0440 = (*qfn1(fn))(qenv(fn), v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = stack[0];
    v0440 = qcdr(v0440);
    v0440 = qcar(v0440);
    fn = elt(env, 24); // negnumberchk
    v0441 = (*qfn1(fn))(qenv(fn), v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = stack[-2];
    fn = elt(env, 22); // maprint
    v0440 = (*qfn2(fn))(qenv(fn), v0441, v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0440 = stack[-1];
    if (v0440 == nil) goto v0259;
    v0440 = elt(env, 14); // ")"
    fn = elt(env, 21); // prin2!*
    v0440 = (*qfn1(fn))(qenv(fn), v0440);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    goto v0259;

v0448:
    v0440 = qvalue(elt(env, 2)); // nil
    stack[-1] = v0440;
    goto v0449;
// error exit handlers
v0443:
    popv(9);
    return nil;
}



// Code for !*f2di

static LispObject CC_Hf2di(LispObject env,
                         LispObject v0001, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0169, v0170;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *f2di");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    v0169 = v0088;
    stack[-5] = v0001;
// end of prologue
    stack[-6] = qvalue(elt(env, 1)); // varlist!*
    qvalue(elt(env, 1)) = nil; // varlist!*
    qvalue(elt(env, 1)) = v0169; // varlist!*
    v0169 = stack[-5];
    if (v0169 == nil) goto v0039;
    v0169 = stack[-5];
    if (!consp(v0169)) goto v0205;
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0169 = (consp(v0169) ? nil : lisp_true);
    goto v0031;

v0031:
    if (v0169 == nil) goto v0294;
    v0169 = qvalue(elt(env, 1)); // varlist!*
    stack[-3] = v0169;
    v0169 = stack[-3];
    if (v0169 == nil) goto v0199;
    v0169 = (LispObject)1; // 0
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    stack[-1] = v0169;
    stack[-2] = v0169;
    goto v0202;

v0202:
    v0169 = stack[-3];
    v0169 = qcdr(v0169);
    stack[-3] = v0169;
    v0169 = stack[-3];
    if (v0169 == nil) goto v0022;
    stack[0] = stack[-1];
    v0169 = (LispObject)1; // 0
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = Lrplacd(nil, stack[0], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = stack[-1];
    v0169 = qcdr(v0169);
    stack[-1] = v0169;
    goto v0202;

v0022:
    v0169 = stack[-2];
    goto v0414;

v0414:
    fn = elt(env, 4); // addgt
    v0170 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = stack[-5];
    v0169 = cons(v0170, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    goto v0015;

v0015:
    qvalue(elt(env, 1)) = stack[-6]; // varlist!*
    { popv(8); return onevalue(v0169); }

v0199:
    v0169 = qvalue(elt(env, 2)); // nil
    goto v0414;

v0294:
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    v0170 = qcar(v0169);
    v0169 = qvalue(elt(env, 1)); // varlist!*
    v0169 = Lmember(nil, v0170, v0169);
    if (v0169 == nil) goto v0459;
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0170 = qcdr(v0169);
    v0169 = qvalue(elt(env, 1)); // varlist!*
    stack[-4] = CC_Hf2di(env, v0170, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = qvalue(elt(env, 1)); // varlist!*
    stack[-3] = v0169;
    v0169 = stack[-3];
    if (v0169 == nil) goto v0405;
    v0169 = stack[-3];
    v0169 = qcar(v0169);
    v0170 = v0169;
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    if (equal(v0170, v0169)) goto v0275;
    v0169 = (LispObject)1; // 0
    goto v0279;

v0279:
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    stack[-1] = v0169;
    stack[-2] = v0169;
    goto v0460;

v0460:
    v0169 = stack[-3];
    v0169 = qcdr(v0169);
    stack[-3] = v0169;
    v0169 = stack[-3];
    if (v0169 == nil) goto v0208;
    stack[0] = stack[-1];
    v0169 = stack[-3];
    v0169 = qcar(v0169);
    v0170 = v0169;
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    if (equal(v0170, v0169)) goto v0436;
    v0169 = (LispObject)1; // 0
    goto v0461;

v0461:
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = Lrplacd(nil, stack[0], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = stack[-1];
    v0169 = qcdr(v0169);
    stack[-1] = v0169;
    goto v0460;

v0436:
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    v0169 = qcdr(v0169);
    goto v0461;

v0208:
    v0169 = stack[-2];
    goto v0462;

v0462:
    fn = elt(env, 4); // addgt
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    fn = elt(env, 5); // pdmult
    v0169 = (*qfn2(fn))(qenv(fn), stack[-4], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    stack[0] = v0169;
    goto v0399;

v0399:
    v0169 = stack[-5];
    v0170 = qcdr(v0169);
    v0169 = qvalue(elt(env, 1)); // varlist!*
    v0169 = CC_Hf2di(env, v0170, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    fn = elt(env, 6); // psum
    v0169 = (*qfn2(fn))(qenv(fn), stack[0], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    goto v0015;

v0275:
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    v0169 = qcdr(v0169);
    goto v0279;

v0405:
    v0169 = qvalue(elt(env, 2)); // nil
    goto v0462;

v0459:
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0170 = qcdr(v0169);
    v0169 = qvalue(elt(env, 1)); // varlist!*
    stack[0] = CC_Hf2di(env, v0170, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = stack[-5];
    v0169 = qcar(v0169);
    v0170 = qcar(v0169);
    v0169 = (LispObject)17; // 1
    v0169 = cons(v0170, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    fn = elt(env, 7); // pcmult
    v0169 = (*qfn2(fn))(qenv(fn), stack[0], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-7];
    stack[0] = v0169;
    goto v0399;

v0205:
    v0169 = qvalue(elt(env, 3)); // t
    goto v0031;

v0039:
    v0169 = qvalue(elt(env, 2)); // nil
    goto v0015;
// error exit handlers
v0269:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; // varlist!*
    popv(8);
    return nil;
}



// Code for msolve!-polyn

static LispObject CC_msolveKpolyn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0166, v0471, v0212;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for msolve-polyn");
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
    push(nil);
// copy arguments values to proper place
    stack[-8] = v0001;
    stack[-9] = v0000;
// end of prologue
    v0166 = stack[-8];
    v0166 = qcar(v0166);
    stack[-10] = v0166;
    v0166 = stack[-8];
    v0166 = qcdr(v0166);
    if (v0166 == nil) goto v0040;
    v0166 = (LispObject)1; // 0
    stack[-7] = v0166;
    goto v0413;

v0413:
    v0166 = qvalue(elt(env, 1)); // current!-modulus
    v0471 = sub1(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = stack[-7];
    v0166 = difference2(v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = Lminusp(nil, v0166);
    env = stack[-11];
    if (v0166 == nil) goto v0296;
    v0166 = qvalue(elt(env, 2)); // nil
    { popv(12); return onevalue(v0166); }

v0296:
    stack[0] = stack[-9];
    v0471 = stack[-10];
    v0166 = stack[-7];
    v0166 = cons(v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    fn = elt(env, 3); // subf
    v0166 = (*qfn2(fn))(qenv(fn), stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0471 = qcar(v0166);
    v0166 = stack[-8];
    v0166 = qcdr(v0166);
    v0166 = CC_msolveKpolyn(env, v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    stack[-3] = v0166;
    v0166 = stack[-3];
    if (v0166 == nil) goto v0415;
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    v0212 = stack[-10];
    v0471 = stack[-7];
    v0166 = acons(v0212, v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    stack[-1] = v0166;
    stack[-2] = v0166;
    goto v0020;

v0020:
    v0166 = stack[-3];
    v0166 = qcdr(v0166);
    stack[-3] = v0166;
    v0166 = stack[-3];
    if (v0166 == nil) goto v0002;
    stack[0] = stack[-1];
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    v0212 = stack[-10];
    v0471 = stack[-7];
    v0166 = acons(v0212, v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = Lrplacd(nil, stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    stack[-1] = v0166;
    goto v0020;

v0002:
    v0166 = stack[-2];
    goto v0396;

v0396:
    stack[-6] = v0166;
    v0166 = stack[-6];
    fn = elt(env, 4); // lastpair
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    stack[-5] = v0166;
    v0166 = stack[-7];
    v0166 = add1(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    stack[-7] = v0166;
    v0166 = stack[-5];
    if (!consp(v0166)) goto v0413;
    else goto v0472;

v0472:
    v0166 = qvalue(elt(env, 1)); // current!-modulus
    v0471 = sub1(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = stack[-7];
    v0166 = difference2(v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = Lminusp(nil, v0166);
    env = stack[-11];
    if (!(v0166 == nil)) { LispObject res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    stack[0] = stack[-9];
    v0471 = stack[-10];
    v0166 = stack[-7];
    v0166 = cons(v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    fn = elt(env, 3); // subf
    v0166 = (*qfn2(fn))(qenv(fn), stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0471 = qcar(v0166);
    v0166 = stack[-8];
    v0166 = qcdr(v0166);
    v0166 = CC_msolveKpolyn(env, v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    stack[-3] = v0166;
    v0166 = stack[-3];
    if (v0166 == nil) goto v0473;
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    v0212 = stack[-10];
    v0471 = stack[-7];
    v0166 = acons(v0212, v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    stack[-1] = v0166;
    stack[-2] = v0166;
    goto v0474;

v0474:
    v0166 = stack[-3];
    v0166 = qcdr(v0166);
    stack[-3] = v0166;
    v0166 = stack[-3];
    if (v0166 == nil) goto v0209;
    stack[0] = stack[-1];
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    v0212 = stack[-10];
    v0471 = stack[-7];
    v0166 = acons(v0212, v0471, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = Lrplacd(nil, stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    stack[-1] = v0166;
    goto v0474;

v0209:
    v0166 = stack[-2];
    goto v0208;

v0208:
    v0166 = Lrplacd(nil, stack[-4], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    v0166 = stack[-5];
    fn = elt(env, 4); // lastpair
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    stack[-5] = v0166;
    v0166 = stack[-7];
    v0166 = add1(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-11];
    stack[-7] = v0166;
    goto v0472;

v0473:
    v0166 = qvalue(elt(env, 2)); // nil
    goto v0208;

v0415:
    v0166 = qvalue(elt(env, 2)); // nil
    goto v0396;

v0040:
    v0471 = stack[-9];
    v0166 = stack[-8];
    v0166 = qcar(v0166);
    {
        popv(12);
        fn = elt(env, 5); // msolve!-poly1
        return (*qfn2(fn))(qenv(fn), v0471, v0166);
    }
// error exit handlers
v0163:
    popv(12);
    return nil;
}



// Code for cl_atmlc

static LispObject CC_cl_atmlc(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0168, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atmlc");
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
    v0168 = v0000;
// end of prologue
    v0038 = v0168;
    v0168 = (LispObject)17; // 1
    v0168 = cons(v0038, v0168);
    errexit();
    return ncons(v0168);
}



// Code for ofsf_facequal!*

static LispObject CC_ofsf_facequalH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0308, v0414, v0202;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_facequal*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0414 = v0001;
    v0202 = v0000;
// end of prologue
    v0308 = qvalue(elt(env, 1)); // !*rlsifac
    if (v0308 == nil) goto v0028;
    v0308 = qvalue(elt(env, 2)); // !*rlsiexpla
    if (!(v0308 == nil)) goto v0010;
    v0308 = qvalue(elt(env, 3)); // !*rlsiexpl
    if (v0308 == nil) goto v0028;
    v0308 = elt(env, 4); // or
    if (!(v0414 == v0308)) goto v0028;

v0010:
    v0308 = v0202;
    {
        fn = elt(env, 7); // ofsf_facequal
        return (*qfn1(fn))(qenv(fn), v0308);
    }

v0028:
    v0308 = elt(env, 5); // equal
    v0414 = v0202;
    v0202 = qvalue(elt(env, 6)); // nil
    return list3(v0308, v0414, v0202);
}



setup_type const u27_setup[] =
{
    {"color-roads",             too_few_2,      CC_colorKroads,wrong_no_2},
    {"greaterpcdr",             too_few_2,      CC_greaterpcdr,wrong_no_2},
    {"formproc",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formproc},
    {"subeval1",                too_few_2,      CC_subeval1,   wrong_no_2},
    {"red_tailreddriver",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_tailreddriver},
    {"dummyp",                  CC_dummyp,      too_many_1,    wrong_no_1},
    {"msolve-poly1",            too_few_2,      CC_msolveKpoly1,wrong_no_2},
    {"reduce-mod-eigf",         too_few_2,      CC_reduceKmodKeigf,wrong_no_2},
    {"domainvalchk",            too_few_2,      CC_domainvalchk,wrong_no_2},
    {"dvfsf_smcpknowl",         CC_dvfsf_smcpknowl,too_many_1, wrong_no_1},
    {"getargsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_getargsrd},
    {"matsm1",                  CC_matsm1,      too_many_1,    wrong_no_1},
    {"amatch",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_amatch},
    {"evinvlexcomp",            too_few_2,      CC_evinvlexcomp,wrong_no_2},
    {"dipprodin",               too_few_2,      CC_dipprodin,  wrong_no_2},
    {"unplus",                  CC_unplus,      too_many_1,    wrong_no_1},
    {"chkint*",                 CC_chkintH,     too_many_1,    wrong_no_1},
    {"color-strand",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_colorKstrand},
    {"mkfil*",                  CC_mkfilH,      too_many_1,    wrong_no_1},
    {"ratfunpri1",              CC_ratfunpri1,  too_many_1,    wrong_no_1},
    {"*f2di",                   too_few_2,      CC_Hf2di,      wrong_no_2},
    {"msolve-polyn",            too_few_2,      CC_msolveKpolyn,wrong_no_2},
    {"cl_atmlc",                CC_cl_atmlc,    too_many_1,    wrong_no_1},
    {"ofsf_facequal*",          too_few_2,      CC_ofsf_facequalH,wrong_no_2},
    {NULL, (one_args *)"u27", (two_args *)"1637 9302526 7318811", 0}
};

// end of generated code
