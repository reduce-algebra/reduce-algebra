
// $destdir\u48.c        Machine generated C code

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



// Code for com43

static LispObject CC_com43(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0475, v0476, v0477, v0478;
    LispObject fn;
    LispObject v0332, v0333, v0343, v0344, v0354, v0355;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "com43");
    va_start(aa, nargs);
    v0355 = va_arg(aa, LispObject);
    v0354 = va_arg(aa, LispObject);
    v0344 = va_arg(aa, LispObject);
    v0343 = va_arg(aa, LispObject);
    v0333 = va_arg(aa, LispObject);
    v0332 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for com43");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0332,v0333,v0343,v0344,v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0355,v0354,v0344,v0343,v0333,v0332);
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
    stack[-4] = v0332;
    stack[-5] = v0333;
    stack[-6] = v0343;
    stack[-7] = v0344;
    stack[-8] = v0354;
    stack[-9] = v0355;
// end of prologue
    v0475 = (LispObject)1; // 0
    stack[-15] = v0475;
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)65; // 4
    v0475 = (LispObject)65; // 4
    stack[-1] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 2); // bb
    v0476 = (LispObject)65; // 4
    v0475 = (LispObject)65; // 4
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 3); // ff
    v0476 = (LispObject)49; // 3
    v0475 = (LispObject)49; // 3
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list3(stack[-1], stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 16); // matrix
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = elt(env, 4); // algebraic
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)65; // 4
    v0476 = (LispObject)65; // 4
    v0475 = (LispObject)49; // 3
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = ncons(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 18); // arrayfn
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    stack[-10] = v0475;
    goto v0480;

v0480:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-10];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0481;
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)65; // 4
    v0475 = (LispObject)17; // 1
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0476 = elt(env, 9); // det
    v0475 = elt(env, 1); // liemat
    v0475 = list2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 17); // aeval
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)1; // 0
    fn = elt(env, 20); // evalneq
    v0475 = (*qfn2(fn))(qenv(fn), v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    if (v0475 == nil) goto v0482;
    v0475 = (LispObject)17; // 1
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-15] = v0475;
    goto v0483;

v0483:
    stack[0] = elt(env, 2); // bb
    v0477 = elt(env, 10); // quotient
    v0476 = (LispObject)17; // 1
    v0475 = elt(env, 1); // liemat
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    stack[-14] = v0475;
    goto v0484;

v0484:
    v0476 = (LispObject)49; // 3
    v0475 = stack[-14];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0485;
    v0475 = (LispObject)17; // 1
    stack[-1] = v0475;
    goto v0486;

v0486:
    v0476 = (LispObject)49; // 3
    v0475 = stack[-1];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0487;
    v0475 = (LispObject)1; // 0
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-15] = v0475;
    v0475 = (LispObject)17; // 1
    stack[-1] = v0475;
    goto v0488;

v0488:
    v0476 = (LispObject)49; // 3
    v0475 = stack[-1];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0489;
    v0476 = stack[-15];
    v0475 = (LispObject)1; // 0
    if (v0476 == v0475) goto v0490;
    v0476 = elt(env, 9); // det
    v0475 = elt(env, 3); // ff
    v0475 = list2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 17); // aeval
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)1; // 0
    fn = elt(env, 21); // evalequal
    v0475 = (*qfn2(fn))(qenv(fn), v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    if (v0475 == nil) goto v0491;
    v0475 = elt(env, 14); // comcom1
    v0475 = ncons(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    goto v0492;

v0492:
    v0477 = elt(env, 2); // bb
    v0476 = elt(env, 3); // ff
    v0475 = elt(env, 5); // l_z
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 22); // clear
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    v0475 = nil;
    { popv(17); return onevalue(v0475); }

v0491:
    v0475 = elt(env, 15); // comcom3
    v0475 = ncons(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    goto v0492;

v0490:
    v0475 = elt(env, 13); // comcom0
    v0475 = ncons(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 17); // aeval
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    goto v0492;

v0489:
    v0475 = (LispObject)17; // 1
    stack[0] = v0475;
    goto v0493;

v0493:
    v0476 = (LispObject)49; // 3
    v0475 = stack[0];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0494;
    v0475 = stack[-1];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-1] = v0475;
    goto v0488;

v0494:
    v0477 = elt(env, 3); // ff
    v0476 = stack[-1];
    v0475 = stack[0];
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)1; // 0
    fn = elt(env, 20); // evalneq
    v0475 = (*qfn2(fn))(qenv(fn), v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    if (v0475 == nil) goto v0495;
    v0475 = (LispObject)17; // 1
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-15] = v0475;
    v0475 = (LispObject)49; // 3
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-1] = v0475;
    v0475 = (LispObject)49; // 3
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = v0475;
    goto v0495;

v0495:
    v0475 = stack[0];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = v0475;
    goto v0493;

v0487:
    v0477 = elt(env, 3); // ff
    v0476 = (LispObject)17; // 1
    v0475 = stack[-1];
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)33; // 2
    v0475 = stack[-1];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 3); // ff
    v0476 = (LispObject)33; // 2
    v0475 = stack[-1];
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)49; // 3
    v0475 = stack[-1];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 3); // ff
    v0476 = (LispObject)49; // 3
    v0475 = stack[-1];
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)33; // 2
    v0476 = (LispObject)49; // 3
    v0475 = stack[-1];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-1];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-1] = v0475;
    goto v0486;

v0485:
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)33; // 2
    v0475 = stack[-14];
    stack[-13] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    stack[-12] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-11] = v0475;
    goto v0496;

v0496:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-12];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0497;
    v0475 = stack[-11];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-13], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)49; // 3
    v0475 = stack[-14];
    stack[-13] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    stack[-12] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-11] = v0475;
    goto v0498;

v0498:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-12];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0499;
    v0475 = stack[-11];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-13], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)33; // 2
    v0476 = (LispObject)49; // 3
    v0475 = stack[-14];
    stack[-13] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    stack[-12] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-11] = v0475;
    goto v0500;

v0500:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-12];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0501;
    v0475 = stack[-11];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-13], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)65; // 4
    v0475 = stack[-14];
    stack[-9] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    stack[-8] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-7] = v0475;
    goto v0502;

v0502:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-8];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0503;
    v0475 = stack[-7];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-9], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)33; // 2
    v0476 = (LispObject)65; // 4
    v0475 = stack[-14];
    stack[-9] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    stack[-8] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-7] = v0475;
    goto v0504;

v0504:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-8];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0505;
    v0475 = stack[-7];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-9], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 5); // l_z
    v0477 = (LispObject)49; // 3
    v0476 = (LispObject)65; // 4
    v0475 = stack[-14];
    stack[-9] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    stack[-8] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-7] = v0475;
    goto v0506;

v0506:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-8];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0507;
    v0475 = stack[-7];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-9], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-14];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-14] = v0475;
    goto v0484;

v0507:
    stack[-6] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-5] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-4] = v0475;
    goto v0508;

v0508:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-5];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0509;
    v0475 = stack[-4];
    v0476 = v0475;
    v0475 = stack[-7];
    v0475 = list3(stack[-6], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-7] = v0475;
    v0475 = stack[-8];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-8] = v0475;
    goto v0506;

v0509:
    stack[-3] = elt(env, 11); // plus
    stack[-2] = elt(env, 12); // times
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)49; // 3
    v0475 = stack[-8];
    stack[-1] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-8];
    v0476 = stack[-15];
    v0475 = stack[-5];
    stack[0] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 2); // bb
    v0476 = stack[-5];
    v0475 = stack[-14];
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list4(stack[-2], stack[-1], stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-4];
    v0475 = list3(stack[-3], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-4] = v0475;
    v0475 = stack[-5];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-5] = v0475;
    goto v0508;

v0505:
    stack[-6] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-5] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-4] = v0475;
    goto v0510;

v0510:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-5];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0511;
    v0475 = stack[-4];
    v0476 = v0475;
    v0475 = stack[-7];
    v0475 = list3(stack[-6], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-7] = v0475;
    v0475 = stack[-8];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-8] = v0475;
    goto v0504;

v0511:
    stack[-3] = elt(env, 11); // plus
    stack[-2] = elt(env, 12); // times
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)33; // 2
    v0475 = stack[-8];
    stack[-1] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-8];
    v0476 = stack[-15];
    v0475 = stack[-5];
    stack[0] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 2); // bb
    v0476 = stack[-5];
    v0475 = stack[-14];
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list4(stack[-2], stack[-1], stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-4];
    v0475 = list3(stack[-3], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-4] = v0475;
    v0475 = stack[-5];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-5] = v0475;
    goto v0510;

v0503:
    stack[-6] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-5] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-4] = v0475;
    goto v0512;

v0512:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-5];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0513;
    v0475 = stack[-4];
    v0476 = v0475;
    v0475 = stack[-7];
    v0475 = list3(stack[-6], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-7] = v0475;
    v0475 = stack[-8];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-8] = v0475;
    goto v0502;

v0513:
    stack[-3] = elt(env, 11); // plus
    stack[-2] = elt(env, 12); // times
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)17; // 1
    v0475 = stack[-8];
    stack[-1] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-8];
    v0476 = stack[-15];
    v0475 = stack[-5];
    stack[0] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 2); // bb
    v0476 = stack[-5];
    v0475 = stack[-14];
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list4(stack[-2], stack[-1], stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-4];
    v0475 = list3(stack[-3], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-4] = v0475;
    v0475 = stack[-5];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-5] = v0475;
    goto v0512;

v0501:
    stack[-10] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-9] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-8] = v0475;
    goto v0514;

v0514:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-9];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0515;
    v0475 = stack[-8];
    v0476 = v0475;
    v0475 = stack[-11];
    v0475 = list3(stack[-10], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-11] = v0475;
    v0475 = stack[-12];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-12] = v0475;
    goto v0500;

v0515:
    stack[-7] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-6] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-5] = v0475;
    goto v0516;

v0516:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-6];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0517;
    v0475 = stack[-5];
    v0476 = v0475;
    v0475 = stack[-8];
    v0475 = list3(stack[-7], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-8] = v0475;
    v0475 = stack[-9];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-9] = v0475;
    goto v0514;

v0517:
    stack[-4] = elt(env, 11); // plus
    stack[-3] = elt(env, 12); // times
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)33; // 2
    v0475 = stack[-12];
    stack[-2] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)49; // 3
    v0475 = stack[-9];
    stack[-1] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-12];
    v0476 = stack[-9];
    v0475 = stack[-6];
    stack[0] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 2); // bb
    v0476 = stack[-6];
    v0475 = stack[-14];
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list3star(stack[-3], stack[-2], stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-5];
    v0475 = list3(stack[-4], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-5] = v0475;
    v0475 = stack[-6];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-6] = v0475;
    goto v0516;

v0499:
    stack[-10] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-9] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-8] = v0475;
    goto v0518;

v0518:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-9];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0519;
    v0475 = stack[-8];
    v0476 = v0475;
    v0475 = stack[-11];
    v0475 = list3(stack[-10], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-11] = v0475;
    v0475 = stack[-12];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-12] = v0475;
    goto v0498;

v0519:
    stack[-7] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-6] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-5] = v0475;
    goto v0520;

v0520:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-6];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0521;
    v0475 = stack[-5];
    v0476 = v0475;
    v0475 = stack[-8];
    v0475 = list3(stack[-7], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-8] = v0475;
    v0475 = stack[-9];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-9] = v0475;
    goto v0518;

v0521:
    stack[-4] = elt(env, 11); // plus
    stack[-3] = elt(env, 12); // times
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)17; // 1
    v0475 = stack[-12];
    stack[-2] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)49; // 3
    v0475 = stack[-9];
    stack[-1] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-12];
    v0476 = stack[-9];
    v0475 = stack[-6];
    stack[0] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 2); // bb
    v0476 = stack[-6];
    v0475 = stack[-14];
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list3star(stack[-3], stack[-2], stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-5];
    v0475 = list3(stack[-4], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-5] = v0475;
    v0475 = stack[-6];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-6] = v0475;
    goto v0520;

v0497:
    stack[-10] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-9] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-8] = v0475;
    goto v0522;

v0522:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-9];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0523;
    v0475 = stack[-8];
    v0476 = v0475;
    v0475 = stack[-11];
    v0475 = list3(stack[-10], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-11] = v0475;
    v0475 = stack[-12];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-12] = v0475;
    goto v0496;

v0523:
    stack[-7] = elt(env, 11); // plus
    v0475 = (LispObject)17; // 1
    stack[-6] = v0475;
    v0475 = (LispObject)1; // 0
    stack[-5] = v0475;
    goto v0524;

v0524:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-6];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (v0475 == nil) goto v0525;
    v0475 = stack[-5];
    v0476 = v0475;
    v0475 = stack[-8];
    v0475 = list3(stack[-7], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-8] = v0475;
    v0475 = stack[-9];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-9] = v0475;
    goto v0522;

v0525:
    stack[-4] = elt(env, 11); // plus
    stack[-3] = elt(env, 12); // times
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)17; // 1
    v0475 = stack[-12];
    stack[-2] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)33; // 2
    v0475 = stack[-9];
    stack[-1] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-12];
    v0476 = stack[-9];
    v0475 = stack[-6];
    stack[0] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 2); // bb
    v0476 = stack[-6];
    v0475 = stack[-14];
    v0475 = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list3star(stack[-3], stack[-2], stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-5];
    v0475 = list3(stack[-4], v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-5] = v0475;
    v0475 = stack[-6];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-6] = v0475;
    goto v0524;

v0482:
    v0475 = (LispObject)33; // 2
    stack[-2] = v0475;
    goto v0526;

v0526:
    v0476 = (LispObject)65; // 4
    v0475 = stack[-2];
    v0475 = difference2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = Lminusp(nil, v0475);
    env = stack[-16];
    if (!(v0475 == nil)) goto v0483;
    stack[-1] = elt(env, 1); // liemat
    stack[0] = (LispObject)65; // 4
    v0475 = stack[-2];
    v0475 = sub1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = list3(stack[-1], stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)1; // 0
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)65; // 4
    v0475 = stack[-2];
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)17; // 1
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0476 = elt(env, 9); // det
    v0475 = elt(env, 1); // liemat
    v0475 = list2(v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0476 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)1; // 0
    fn = elt(env, 20); // evalneq
    v0475 = (*qfn2(fn))(qenv(fn), v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    if (v0475 == nil) goto v0527;
    v0475 = stack[-2];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-15] = v0475;
    v0475 = (LispObject)65; // 4
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-2] = v0475;
    goto v0527;

v0527:
    v0475 = stack[-2];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-2] = v0475;
    goto v0526;

v0481:
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)33; // 2
    v0476 = (LispObject)17; // 1
    v0475 = stack[-10];
    stack[-1] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = elt(env, 8); // minus
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)33; // 2
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)49; // 3
    v0476 = (LispObject)17; // 1
    v0475 = stack[-10];
    stack[-1] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = elt(env, 8); // minus
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)49; // 3
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)49; // 3
    v0476 = (LispObject)33; // 2
    v0475 = stack[-10];
    stack[-1] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = elt(env, 8); // minus
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)33; // 2
    v0476 = (LispObject)49; // 3
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)65; // 4
    v0476 = (LispObject)17; // 1
    v0475 = stack[-10];
    stack[-1] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = elt(env, 8); // minus
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)65; // 4
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)65; // 4
    v0476 = (LispObject)33; // 2
    v0475 = stack[-10];
    stack[-1] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = elt(env, 8); // minus
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)33; // 2
    v0476 = (LispObject)65; // 4
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)65; // 4
    v0476 = (LispObject)49; // 3
    v0475 = stack[-10];
    stack[-1] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[0] = elt(env, 8); // minus
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)49; // 3
    v0476 = (LispObject)65; // 4
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = list2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)17; // 1
    v0476 = (LispObject)17; // 1
    v0475 = stack[-10];
    stack[-3] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)33; // 2
    v0476 = (LispObject)33; // 2
    v0475 = stack[-10];
    stack[-2] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)49; // 3
    v0476 = (LispObject)49; // 3
    v0475 = stack[-10];
    stack[-1] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = (LispObject)65; // 4
    v0476 = (LispObject)65; // 4
    v0475 = stack[-10];
    stack[0] = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = (LispObject)1; // 0
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-2], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[-3], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)17; // 1
    v0475 = stack[-10];
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-9];
    v0476 = stack[-8];
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)33; // 2
    v0475 = stack[-10];
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-7];
    v0476 = stack[-6];
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0477 = elt(env, 1); // liemat
    v0476 = (LispObject)49; // 3
    v0475 = stack[-10];
    stack[0] = list3(v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0478 = elt(env, 7); // cc
    v0477 = stack[-5];
    v0476 = stack[-4];
    v0475 = stack[-10];
    v0475 = list4(v0478, v0477, v0476, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 23); // aeval!*
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    fn = elt(env, 19); // setk
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    v0475 = stack[-10];
    v0475 = add1(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0479;
    env = stack[-16];
    stack[-10] = v0475;
    goto v0480;
// error exit handlers
v0479:
    popv(17);
    return nil;
}



// Code for formclear

static LispObject CC_formclear(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0532, v0533, v0534;
    LispObject fn;
    LispObject v0344, v0354, v0355;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclear");
    va_start(aa, nargs);
    v0355 = va_arg(aa, LispObject);
    v0354 = va_arg(aa, LispObject);
    v0344 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formclear");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0344,v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0355,v0354,v0344);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0532 = v0344;
    v0533 = v0354;
    v0534 = v0355;
// end of prologue
    stack[0] = elt(env, 1); // clear
    v0534 = qcdr(v0534);
    fn = elt(env, 2); // formclear1
    v0532 = (*qfnn(fn))(qenv(fn), 3, v0534, v0533, v0532);
    nil = C_nil;
    if (exception_pending()) goto v0535;
    {
        LispObject v0536 = stack[0];
        popv(1);
        return list2(v0536, v0532);
    }
// error exit handlers
v0535:
    popv(1);
    return nil;
}



// Code for cdr_signsort

static LispObject CC_cdr_signsort(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0557, v0430;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cdr_signsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0354;
    v0557 = v0355;
// end of prologue
    fn = elt(env, 3); // copy
    v0557 = (*qfn1(fn))(qenv(fn), v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    stack[-6] = v0557;
    v0557 = (LispObject)17; // 1
    stack[-1] = v0557;
    v0557 = qvalue(elt(env, 1)); // nil
    stack[-4] = v0557;
    goto v0559;

v0559:
    v0557 = stack[-6];
    if (v0557 == nil) goto v0560;
    v0557 = stack[-4];
    if (v0557 == nil) goto v0472;
    v0557 = stack[-6];
    v0557 = qcar(v0557);
    v0430 = qcdr(v0557);
    v0557 = stack[-4];
    v0557 = qcar(v0557);
    v0557 = qcdr(v0557);
    if (equal(v0430, v0557)) goto v0469;
    stack[0] = stack[-5];
    v0557 = stack[-4];
    v0557 = qcar(v0557);
    v0430 = qcdr(v0557);
    v0557 = stack[-6];
    v0557 = qcar(v0557);
    v0557 = qcdr(v0557);
    v0557 = list2(v0430, v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    fn = elt(env, 4); // apply
    v0557 = (*qfn2(fn))(qenv(fn), stack[0], v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    if (v0557 == nil) goto v0561;
    v0557 = stack[-6];
    v0430 = qcar(v0557);
    v0557 = stack[-4];
    v0557 = cons(v0430, v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    stack[-4] = v0557;
    v0557 = stack[-6];
    v0557 = qcdr(v0557);
    stack[-6] = v0557;
    goto v0559;

v0561:
    v0557 = stack[-1];
    v0557 = negate(v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    stack[-1] = v0557;
    v0557 = stack[-4];
    stack[-3] = v0557;
    v0557 = qvalue(elt(env, 2)); // t
    stack[-2] = v0557;
    goto v0562;

v0562:
    v0557 = stack[-2];
    if (v0557 == nil) goto v0563;
    v0557 = stack[-3];
    v0557 = qcdr(v0557);
    if (v0557 == nil) goto v0564;
    v0557 = stack[-3];
    v0557 = qcdr(v0557);
    v0557 = qcar(v0557);
    v0430 = qcdr(v0557);
    v0557 = stack[-6];
    v0557 = qcar(v0557);
    v0557 = qcdr(v0557);
    if (equal(v0430, v0557)) goto v0453;
    stack[0] = stack[-5];
    v0557 = stack[-3];
    v0557 = qcdr(v0557);
    v0557 = qcar(v0557);
    v0430 = qcdr(v0557);
    v0557 = stack[-6];
    v0557 = qcar(v0557);
    v0557 = qcdr(v0557);
    v0557 = list2(v0430, v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    fn = elt(env, 4); // apply
    v0557 = (*qfn2(fn))(qenv(fn), stack[0], v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    if (v0557 == nil) goto v0565;
    v0557 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0557;
    goto v0562;

v0565:
    v0557 = stack[-3];
    v0557 = qcdr(v0557);
    stack[-3] = v0557;
    v0557 = stack[-1];
    v0557 = negate(v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    stack[-1] = v0557;
    goto v0562;

v0453:
    v0557 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0557;
    v0557 = (LispObject)1; // 0
    stack[-1] = v0557;
    v0557 = qvalue(elt(env, 1)); // nil
    stack[-6] = v0557;
    stack[-4] = v0557;
    goto v0562;

v0564:
    v0557 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0557;
    goto v0562;

v0563:
    v0557 = stack[-6];
    if (v0557 == nil) goto v0559;
    stack[0] = stack[-3];
    v0557 = stack[-6];
    v0430 = qcar(v0557);
    v0557 = stack[-3];
    v0557 = qcdr(v0557);
    v0557 = cons(v0430, v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    v0557 = Lrplacd(nil, stack[0], v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    v0557 = stack[-6];
    v0557 = qcdr(v0557);
    stack[-6] = v0557;
    goto v0559;

v0469:
    v0557 = (LispObject)1; // 0
    stack[-1] = v0557;
    v0557 = qvalue(elt(env, 1)); // nil
    stack[-6] = v0557;
    stack[-4] = v0557;
    goto v0559;

v0472:
    v0557 = stack[-6];
    v0430 = qcar(v0557);
    v0557 = stack[-4];
    v0557 = cons(v0430, v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    env = stack[-7];
    stack[-4] = v0557;
    v0557 = stack[-6];
    v0557 = qcdr(v0557);
    stack[-6] = v0557;
    goto v0559;

v0560:
    stack[0] = stack[-1];
    v0557 = stack[-4];
    v0557 = Lreverse(nil, v0557);
    nil = C_nil;
    if (exception_pending()) goto v0558;
    {
        LispObject v0566 = stack[0];
        popv(8);
        return cons(v0566, v0557);
    }
// error exit handlers
v0558:
    popv(8);
    return nil;
}



// Code for distri_pol

static LispObject CC_distri_pol(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0578, v0445;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for distri_pol");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0355;
// end of prologue
    v0578 = stack[-1];
    if (v0578 == nil) goto v0333;
    v0578 = stack[-1];
    if (!consp(v0578)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0578 = stack[-1];
    v0578 = qcdr(v0578);
    if (v0578 == nil) goto v0474;
    v0578 = stack[-1];
    v0578 = qcar(v0578);
    v0578 = ncons(v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    stack[0] = CC_distri_pol(env, v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    v0578 = stack[-1];
    v0578 = qcdr(v0578);
    v0578 = CC_distri_pol(env, v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    {
        LispObject v0580 = stack[0];
        popv(4);
        fn = elt(env, 2); // addfd
        return (*qfn2(fn))(qenv(fn), v0580, v0578);
    }

v0474:
    v0578 = (LispObject)17; // 1
    stack[0] = v0578;
    v0578 = stack[-1];
    stack[-2] = v0578;
    goto v0581;

v0581:
    v0578 = stack[-2];
    if (!consp(v0578)) goto v0466;
    v0578 = stack[-2];
    v0578 = qcdr(v0578);
    v0578 = (v0578 == nil ? lisp_true : nil);
    goto v0582;

v0582:
    if (v0578 == nil) goto v0583;
    v0578 = stack[-2];
    v0578 = qcar(v0578);
    v0445 = qcar(v0578);
    v0578 = (LispObject)17; // 1
    v0578 = cons(v0445, v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    v0578 = ncons(v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    fn = elt(env, 3); // multf
    v0578 = (*qfn2(fn))(qenv(fn), stack[0], v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    stack[0] = v0578;
    v0578 = stack[-2];
    v0578 = qcar(v0578);
    v0578 = qcdr(v0578);
    stack[-2] = v0578;
    goto v0581;

v0583:
    v0578 = stack[-2];
    if (!consp(v0578)) goto v0584;
    stack[-1] = stack[0];
    v0578 = stack[-2];
    v0578 = qcar(v0578);
    v0578 = ncons(v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    v0578 = CC_distri_pol(env, v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    fn = elt(env, 3); // multf
    v0578 = (*qfn2(fn))(qenv(fn), stack[-1], v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    stack[-1] = CC_distri_pol(env, v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    v0578 = stack[-2];
    v0578 = qcdr(v0578);
    v0578 = CC_distri_pol(env, v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    fn = elt(env, 3); // multf
    v0578 = (*qfn2(fn))(qenv(fn), stack[0], v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    v0578 = CC_distri_pol(env, v0578);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-3];
    {
        LispObject v0585 = stack[-1];
        popv(4);
        fn = elt(env, 2); // addfd
        return (*qfn2(fn))(qenv(fn), v0585, v0578);
    }

v0584:
    v0445 = stack[0];
    v0578 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); // multf
        return (*qfn2(fn))(qenv(fn), v0445, v0578);
    }

v0466:
    v0578 = qvalue(elt(env, 1)); // nil
    goto v0582;

v0333:
    v0578 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0578); }
// error exit handlers
v0579:
    popv(4);
    return nil;
}



// Code for spreadvar

static LispObject CC_spreadvar(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0550, v0480, v0572;
    LispObject v0344, v0354, v0355;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spreadvar");
    va_start(aa, nargs);
    v0355 = va_arg(aa, LispObject);
    v0354 = va_arg(aa, LispObject);
    v0344 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spreadvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0344,v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0355,v0354,v0344);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0480 = v0344;
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue

v0009:
    v0550 = stack[-1];
    if (!consp(v0550)) goto v0591;
    v0550 = stack[-1];
    v0550 = qcar(v0550);
    v0550 = (consp(v0550) ? nil : lisp_true);
    goto v0592;

v0592:
    if (!(v0550 == nil)) { popv(4); return onevalue(v0480); }
    v0550 = stack[-1];
    v0550 = qcar(v0550);
    v0550 = qcar(v0550);
    v0572 = qcar(v0550);
    v0550 = stack[0];
    if (equal(v0572, v0550)) goto v0576;
    v0550 = qvalue(elt(env, 2)); // nil
    goto v0473;

v0473:
    if (v0550 == nil) goto v0535;
    v0550 = stack[-1];
    v0550 = qcar(v0550);
    v0550 = qcar(v0550);
    v0550 = qcdr(v0550);
    v0550 = cons(v0550, v0480);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    env = stack[-3];
    v0480 = v0550;
    goto v0535;

v0535:
    v0550 = stack[-1];
    v0550 = qcdr(v0550);
    stack[-2] = v0550;
    v0550 = stack[-1];
    v0550 = qcar(v0550);
    v0572 = qcdr(v0550);
    v0550 = stack[0];
    v0550 = CC_spreadvar(env, 3, v0572, v0550, v0480);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    env = stack[-3];
    v0480 = v0550;
    v0550 = stack[-2];
    stack[-1] = v0550;
    goto v0009;

v0576:
    v0550 = stack[-1];
    v0550 = qcar(v0550);
    v0550 = qcar(v0550);
    v0572 = qcdr(v0550);
    v0550 = v0480;
    v0550 = Lmember(nil, v0572, v0550);
    v0550 = (v0550 == nil ? lisp_true : nil);
    goto v0473;

v0591:
    v0550 = qvalue(elt(env, 1)); // t
    goto v0592;
// error exit handlers
v0455:
    popv(4);
    return nil;
}



// Code for mri_dettype

static LispObject CC_mri_dettype(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0574, v0575;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_dettype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0574 = v0355;
// end of prologue
    stack[-1] = nil;
    stack[0] = nil;
    fn = elt(env, 5); // mri_arg2l
    v0574 = (*qfn1(fn))(qenv(fn), v0574);
    nil = C_nil;
    if (exception_pending()) goto v0588;
    env = stack[-4];
    fn = elt(env, 6); // kernels
    v0574 = (*qfn1(fn))(qenv(fn), v0574);
    nil = C_nil;
    if (exception_pending()) goto v0588;
    env = stack[-4];
    stack[-3] = v0574;
    v0574 = stack[-3];
    if (v0574 == nil) goto v0591;
    v0574 = qvalue(elt(env, 2)); // t
    stack[-2] = v0574;
    goto v0465;

v0465:
    v0574 = stack[-2];
    if (v0574 == nil) goto v0531;
    v0574 = stack[-3];
    if (v0574 == nil) goto v0531;
    v0574 = stack[-3];
    v0574 = qcar(v0574);
    v0575 = v0574;
    v0574 = stack[-3];
    v0574 = qcdr(v0574);
    stack[-3] = v0574;
    v0574 = v0575;
    fn = elt(env, 7); // mri_realvarp
    v0574 = (*qfn1(fn))(qenv(fn), v0574);
    nil = C_nil;
    if (exception_pending()) goto v0588;
    env = stack[-4];
    if (v0574 == nil) goto v0583;
    v0574 = stack[0];
    if (v0574 == nil) goto v0593;
    v0574 = qvalue(elt(env, 3)); // nil
    stack[-1] = v0574;
    stack[0] = v0574;
    stack[-2] = v0574;
    goto v0465;

v0593:
    v0574 = elt(env, 4); // real
    stack[-1] = v0574;
    goto v0465;

v0583:
    v0574 = stack[-1];
    if (v0574 == nil) goto v0594;
    v0574 = qvalue(elt(env, 3)); // nil
    stack[-1] = v0574;
    stack[0] = v0574;
    stack[-2] = v0574;
    goto v0465;

v0594:
    v0574 = elt(env, 1); // int
    stack[0] = v0574;
    goto v0465;

v0531:
    v0574 = stack[0];
    if (v0574 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    else { popv(5); return onevalue(v0574); }

v0591:
    v0574 = elt(env, 1); // int
    { popv(5); return onevalue(v0574); }
// error exit handlers
v0588:
    popv(5);
    return nil;
}



// Code for lto_alunion

static LispObject CC_lto_alunion(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0529, v0528;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_alunion");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0529 = v0355;
// end of prologue
    v0528 = v0529;
    v0529 = elt(env, 1); // union
    {
        fn = elt(env, 2); // lto_almerge
        return (*qfn2(fn))(qenv(fn), v0528, v0529);
    }
}



// Code for mkarg

static LispObject CC_mkarg(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0573, v0561;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkarg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue
    v0573 = stack[-1];
    if (v0573 == nil) goto v0596;
    v0573 = stack[-1];
    v0573 = Lconstantp(nil, v0573);
    env = stack[-3];
    goto v0595;

v0595:
    if (!(v0573 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0573 = stack[-1];
    if (!consp(v0573)) goto v0534;
    v0573 = stack[-1];
    v0561 = qcar(v0573);
    v0573 = elt(env, 2); // (quote !:dn!: !:int!:)
    v0573 = Lmemq(nil, v0561, v0573);
    if (v0573 == nil) goto v0468;
    v0573 = stack[-1];
        popv(4);
        return Lmkquote(nil, v0573);

v0468:
    stack[-2] = nil;
    goto v0598;

v0598:
    v0573 = stack[-1];
    if (v0573 == nil) goto v0575;
    v0573 = stack[-1];
    v0561 = qcar(v0573);
    v0573 = stack[0];
    v0561 = CC_mkarg(env, v0561, v0573);
    nil = C_nil;
    if (exception_pending()) goto v0599;
    env = stack[-3];
    v0573 = stack[-2];
    v0573 = cons(v0561, v0573);
    nil = C_nil;
    if (exception_pending()) goto v0599;
    env = stack[-3];
    stack[-2] = v0573;
    v0573 = stack[-1];
    v0573 = qcdr(v0573);
    stack[-1] = v0573;
    goto v0598;

v0575:
    stack[0] = elt(env, 3); // list
    v0573 = stack[-2];
    fn = elt(env, 4); // reversip!*
    v0573 = (*qfn1(fn))(qenv(fn), v0573);
    nil = C_nil;
    if (exception_pending()) goto v0599;
    {
        LispObject v0600 = stack[0];
        popv(4);
        return cons(v0600, v0573);
    }

v0534:
    v0561 = stack[-1];
    v0573 = stack[0];
    v0573 = Latsoc(nil, v0561, v0573);
    if (!(v0573 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0573 = stack[-1];
        popv(4);
        return Lmkquote(nil, v0573);

v0596:
    v0573 = qvalue(elt(env, 1)); // t
    goto v0595;
// error exit handlers
v0599:
    popv(4);
    return nil;
}



// Code for negdf

static LispObject CC_negdf(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0601, v0602;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negdf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0355;
// end of prologue
    stack[-2] = nil;
    goto v0332;

v0332:
    v0601 = stack[-1];
    if (v0601 == nil) goto v0595;
    v0601 = stack[-1];
    v0601 = qcar(v0601);
    stack[0] = qcar(v0601);
    v0601 = stack[-1];
    v0601 = qcar(v0601);
    v0601 = qcdr(v0601);
    fn = elt(env, 1); // negsq
    v0602 = (*qfn1(fn))(qenv(fn), v0601);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-3];
    v0601 = stack[-2];
    v0601 = acons(stack[0], v0602, v0601);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-3];
    stack[-2] = v0601;
    v0601 = stack[-1];
    v0601 = qcdr(v0601);
    stack[-1] = v0601;
    goto v0332;

v0595:
    v0601 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0601);
    }
// error exit handlers
v0583:
    popv(4);
    return nil;
}



// Code for ps!:find!-order

static LispObject CC_psTfindKorder(LispObject env,
                         LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0600, v0605, v0563;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:find-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0354);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0600 = v0354;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // ps
    qvalue(elt(env, 1)) = nil; // ps
    qvalue(elt(env, 1)) = v0600; // ps
    v0600 = qvalue(elt(env, 1)); // ps
    if (v0600 == nil) goto v0596;
    v0600 = qvalue(elt(env, 1)); // ps
    if (symbolp(v0600)) goto v0592;
    v0600 = qvalue(elt(env, 1)); // ps
    v0563 = v0600;
    v0600 = v0563;
    v0600 = (is_number(v0600) ? lisp_true : nil);
    if (!(v0600 == nil)) goto v0530;
    v0600 = v0563;
    v0600 = Lconsp(nil, v0600);
    env = stack[-1];
    if (v0600 == nil) goto v0536;
    v0600 = v0563;
    v0605 = qcar(v0600);
    v0600 = elt(env, 3); // !:ps!:
    if (v0605 == v0600) goto v0554;
    v0600 = v0563;
    v0600 = qcar(v0600);
    if (!symbolp(v0600)) v0600 = nil;
    else { v0600 = qfastgets(v0600);
           if (v0600 != nil) { v0600 = elt(v0600, 8); // dname
#ifdef RECORD_GET
             if (v0600 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0600 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0600 == SPID_NOPROP) v0600 = nil; }}
#endif
    goto v0530;

v0530:
    if (v0600 == nil) goto v0606;
    v0600 = (LispObject)1; // 0
    goto v0332;

v0332:
    qvalue(elt(env, 1)) = stack[0]; // ps
    { popv(2); return onevalue(v0600); }

v0606:
    v0605 = qvalue(elt(env, 1)); // ps
    v0600 = elt(env, 3); // !:ps!:
    if (!consp(v0605)) goto v0549;
    v0605 = qcar(v0605);
    if (!(v0605 == v0600)) goto v0549;
    v0600 = qvalue(elt(env, 1)); // ps
    v0600 = qcdr(v0600);
    if (symbolp(v0600)) goto v0552;
    v0600 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 6); // ps!:expression
    v0600 = (*qfn1(fn))(qenv(fn), v0600);
    nil = C_nil;
    if (exception_pending()) goto v0607;
    env = stack[-1];
    if (!consp(v0600)) goto v0462;
    v0600 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 7); // ps!:find!-order1
    v0600 = (*qfn1(fn))(qenv(fn), v0600);
    nil = C_nil;
    if (exception_pending()) goto v0607;
    env = stack[-1];
    goto v0332;

v0462:
    v0600 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 8); // ps!:order
    v0600 = (*qfn1(fn))(qenv(fn), v0600);
    nil = C_nil;
    if (exception_pending()) goto v0607;
    env = stack[-1];
    goto v0332;

v0552:
    v0600 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 9); // ps!:unknown!-order
    v0600 = (*qfn1(fn))(qenv(fn), v0600);
    nil = C_nil;
    if (exception_pending()) goto v0607;
    env = stack[-1];
    goto v0332;

v0549:
    v0563 = elt(env, 4); // tps
    v0605 = (LispObject)337; // 21
    v0600 = elt(env, 5); // "Unexpected form in ps!:find!-order"
    fn = elt(env, 10); // rerror
    v0600 = (*qfnn(fn))(qenv(fn), 3, v0563, v0605, v0600);
    nil = C_nil;
    if (exception_pending()) goto v0607;
    env = stack[-1];
    goto v0332;

v0554:
    v0600 = qvalue(elt(env, 2)); // nil
    goto v0530;

v0536:
    v0600 = qvalue(elt(env, 2)); // nil
    goto v0530;

v0592:
    v0600 = qvalue(elt(env, 1)); // ps
    goto v0332;

v0596:
    v0600 = (LispObject)1; // 0
    goto v0332;
// error exit handlers
v0607:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // ps
    popv(2);
    return nil;
}



// Code for multup

static LispObject CC_multup(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0473, v0463;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multup");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0473 = v0355;
// end of prologue
    v0463 = (LispObject)17; // 1
    stack[0] = v0473;
    goto v0596;

v0596:
    v0473 = stack[0];
    if (v0473 == nil) { popv(2); return onevalue(v0463); }
    v0473 = stack[0];
    v0473 = qcar(v0473);
    fn = elt(env, 2); // multf
    v0473 = (*qfn2(fn))(qenv(fn), v0463, v0473);
    nil = C_nil;
    if (exception_pending()) goto v0602;
    env = stack[-1];
    v0463 = v0473;
    v0473 = stack[0];
    v0473 = qcdr(v0473);
    stack[0] = v0473;
    goto v0596;
// error exit handlers
v0602:
    popv(2);
    return nil;
}



// Code for pm!:gensym

static LispObject CC_pmTgensym(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0609;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pm:gensym");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pm:gensym");
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
    stack[-1] = elt(env, 1); // !?
    stack[0] = elt(env, 2); // !_
    v0609 = qvalue(elt(env, 3)); // pm!:gensym!-count!*
    v0609 = add1(v0609);
    nil = C_nil;
    if (exception_pending()) goto v0610;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0609; // pm!:gensym!-count!*
    v0609 = Lexplode(nil, v0609);
    nil = C_nil;
    if (exception_pending()) goto v0610;
    env = stack[-2];
    v0609 = list2star(stack[-1], stack[0], v0609);
    nil = C_nil;
    if (exception_pending()) goto v0610;
        popv(3);
        return Lcompress(nil, v0609);
// error exit handlers
v0610:
    popv(3);
    return nil;
}



// Code for dipbcprod

static LispObject CC_dipbcprod(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0534, v0577;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipbcprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue
    v0534 = stack[0];
    fn = elt(env, 2); // bczero!?
    v0534 = (*qfn1(fn))(qenv(fn), v0534);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-2];
    if (v0534 == nil) goto v0548;
    v0534 = qvalue(elt(env, 1)); // dipzero
    { popv(3); return onevalue(v0534); }

v0548:
    v0534 = stack[0];
    fn = elt(env, 3); // bcone!?
    v0534 = (*qfn1(fn))(qenv(fn), v0534);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-2];
    if (!(v0534 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0577 = stack[-1];
    v0534 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // dipbcprodin
        return (*qfn2(fn))(qenv(fn), v0577, v0534);
    }
// error exit handlers
v0474:
    popv(3);
    return nil;
}



// Code for groebsimpcontnormalform

static LispObject CC_groebsimpcontnormalform(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0615, v0616;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebsimpcontnormalform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0355;
// end of prologue
    v0615 = stack[-2];
    if (v0615 == nil) goto v0595;
    v0615 = stack[-2];
    v0615 = qcdr(v0615);
    v0615 = qcdr(v0615);
    v0615 = qcdr(v0615);
    v0615 = qcar(v0615);
    v0615 = (v0615 == nil ? lisp_true : nil);
    goto v0009;

v0009:
    if (!(v0615 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0615 = stack[-2];
    fn = elt(env, 4); // gsugar
    v0615 = (*qfn1(fn))(qenv(fn), v0615);
    nil = C_nil;
    if (exception_pending()) goto v0549;
    env = stack[-4];
    stack[0] = v0615;
    v0615 = stack[-2];
    v0615 = qcdr(v0615);
    v0615 = qcdr(v0615);
    v0615 = qcar(v0615);
    stack[-3] = v0615;
    v0615 = stack[-2];
    fn = elt(env, 5); // vdpsimpcont
    v0615 = (*qfn1(fn))(qenv(fn), v0615);
    nil = C_nil;
    if (exception_pending()) goto v0549;
    env = stack[-4];
    stack[-2] = v0615;
    v0616 = stack[-2];
    v0615 = stack[0];
    fn = elt(env, 6); // gsetsugar
    v0615 = (*qfn2(fn))(qenv(fn), v0616, v0615);
    nil = C_nil;
    if (exception_pending()) goto v0549;
    env = stack[-4];
    v0615 = qvalue(elt(env, 2)); // !*groebprot
    if (v0615 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0616 = stack[-3];
    v0615 = stack[-2];
    v0615 = qcdr(v0615);
    v0615 = qcdr(v0615);
    v0615 = qcar(v0615);
    if (equal(v0616, v0615)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[-1] = elt(env, 3); // quotient
    v0615 = stack[-2];
    v0615 = qcdr(v0615);
    v0615 = qcdr(v0615);
    v0615 = qcar(v0615);
    fn = elt(env, 7); // vbc2a
    stack[0] = (*qfn1(fn))(qenv(fn), v0615);
    nil = C_nil;
    if (exception_pending()) goto v0549;
    env = stack[-4];
    v0615 = stack[-3];
    fn = elt(env, 7); // vbc2a
    v0615 = (*qfn1(fn))(qenv(fn), v0615);
    nil = C_nil;
    if (exception_pending()) goto v0549;
    env = stack[-4];
    v0615 = list3(stack[-1], stack[0], v0615);
    nil = C_nil;
    if (exception_pending()) goto v0549;
    env = stack[-4];
    fn = elt(env, 8); // reval
    v0615 = (*qfn1(fn))(qenv(fn), v0615);
    nil = C_nil;
    if (exception_pending()) goto v0549;
    env = stack[-4];
    fn = elt(env, 9); // groebreductionprotocol2
    v0615 = (*qfn1(fn))(qenv(fn), v0615);
    nil = C_nil;
    if (exception_pending()) goto v0549;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0595:
    v0615 = qvalue(elt(env, 1)); // t
    goto v0009;
// error exit handlers
v0549:
    popv(5);
    return nil;
}



// Code for add!-to!-sorted!-tree

static LispObject CC_addKtoKsortedKtree(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0620, v0567, v0454;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add-to-sorted-tree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue
    stack[-2] = nil;
    goto v0548;

v0548:
    v0620 = stack[0];
    if (v0620 == nil) goto v0592;
    v0567 = stack[-1];
    v0620 = stack[0];
    v0620 = qcdr(v0620);
    v0620 = qcar(v0620);
    if (equal(v0567, v0620)) goto v0470;
    v0567 = stack[-1];
    v0620 = stack[0];
    v0620 = qcdr(v0620);
    v0620 = qcar(v0620);
    v0620 = Lorderp(nil, v0567, v0620);
    nil = C_nil;
    if (exception_pending()) goto v0444;
    env = stack[-3];
    if (v0620 == nil) goto v0572;
    v0567 = stack[-1];
    v0620 = stack[0];
    v0620 = qcar(v0620);
    v0567 = CC_addKtoKsortedKtree(env, v0567, v0620);
    nil = C_nil;
    if (exception_pending()) goto v0444;
    env = stack[-3];
    v0620 = stack[0];
    v0620 = qcdr(v0620);
    v0620 = cons(v0567, v0620);
    nil = C_nil;
    if (exception_pending()) goto v0444;
    env = stack[-3];
    {
        LispObject v0621 = stack[-2];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0621, v0620);
    }

v0572:
    v0620 = stack[0];
    v0567 = qcar(v0620);
    v0620 = stack[-2];
    v0620 = cons(v0567, v0620);
    nil = C_nil;
    if (exception_pending()) goto v0444;
    env = stack[-3];
    stack[-2] = v0620;
    v0620 = stack[0];
    v0620 = qcdr(v0620);
    v0567 = qcar(v0620);
    v0620 = stack[-2];
    v0620 = cons(v0567, v0620);
    nil = C_nil;
    if (exception_pending()) goto v0444;
    env = stack[-3];
    stack[-2] = v0620;
    v0620 = stack[0];
    v0620 = qcdr(v0620);
    v0620 = qcdr(v0620);
    stack[0] = v0620;
    goto v0548;

v0470:
    v0567 = stack[-2];
    v0620 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0567, v0620);
    }

v0592:
    stack[0] = stack[-2];
    v0454 = qvalue(elt(env, 1)); // nil
    v0567 = stack[-1];
    v0620 = qvalue(elt(env, 1)); // nil
    v0620 = list2star(v0454, v0567, v0620);
    nil = C_nil;
    if (exception_pending()) goto v0444;
    env = stack[-3];
    {
        LispObject v0568 = stack[0];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0568, v0620);
    }
// error exit handlers
v0444:
    popv(4);
    return nil;
}



// Code for !:quotient

static LispObject CC_Tquotient(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0445, v0446, v0625;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :quotient");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0446 = v0354;
    stack[0] = v0355;
// end of prologue
    v0445 = stack[0];
    if (v0445 == nil) goto v0596;
    v0625 = stack[0];
    v0445 = (LispObject)1; // 0
    v0445 = (v0625 == v0445 ? lisp_true : nil);
    goto v0595;

v0595:
    if (v0445 == nil) goto v0548;
    v0445 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0445); }

v0548:
    v0445 = v0446;
    if (v0445 == nil) goto v0536;
    v0625 = v0446;
    v0445 = (LispObject)1; // 0
    v0445 = (v0625 == v0445 ? lisp_true : nil);
    goto v0535;

v0535:
    if (v0445 == nil) goto v0534;
    v0625 = elt(env, 3); // poly
    v0446 = (LispObject)193; // 12
    v0445 = elt(env, 4); // "Zero divisor"
    {
        popv(2);
        fn = elt(env, 8); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0625, v0446, v0445);
    }

v0534:
    v0445 = stack[0];
    if (!consp(v0445)) goto v0606;
    v0445 = qvalue(elt(env, 2)); // nil
    goto v0598;

v0598:
    if (v0445 == nil) goto v0453;
    v0445 = qvalue(elt(env, 5)); // dmode!*
    if (v0445 == nil) goto v0611;
    v0445 = v0446;
    fn = elt(env, 9); // !:recip
    v0445 = (*qfn1(fn))(qenv(fn), v0445);
    nil = C_nil;
    if (exception_pending()) goto v0579;
    env = stack[-1];
    v0446 = v0445;
    if (!consp(v0446)) goto v0573;
    v0625 = stack[0];
    v0446 = v0445;
    v0445 = elt(env, 6); // times
    {
        popv(2);
        fn = elt(env, 10); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0625, v0446, v0445);
    }

v0573:
    v0446 = stack[0];
    popv(2);
    return times2(v0446, v0445);

v0611:
    v0445 = stack[0];
    popv(2);
    return quot2(v0445, v0446);

v0453:
    v0625 = stack[0];
    v0445 = elt(env, 7); // quotient
    {
        popv(2);
        fn = elt(env, 10); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0625, v0446, v0445);
    }

v0606:
    v0445 = v0446;
    v0445 = (consp(v0445) ? nil : lisp_true);
    goto v0598;

v0536:
    v0445 = qvalue(elt(env, 1)); // t
    goto v0535;

v0596:
    v0445 = qvalue(elt(env, 1)); // t
    goto v0595;
// error exit handlers
v0579:
    popv(2);
    return nil;
}



// Code for lispcondp

static LispObject CC_lispcondp(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0529, v0528;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispcondp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0529 = v0355;
// end of prologue
    v0528 = elt(env, 1); // cond
        return Leqcar(nil, v0529, v0528);
}



// Code for kernelp

static LispObject CC_kernelp(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0576, v0582;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernelp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0355;
// end of prologue
    v0576 = stack[0];
    if (v0576 == nil) goto v0595;
    v0576 = stack[0];
    fn = elt(env, 4); // domain!*p
    v0576 = (*qfn1(fn))(qenv(fn), v0576);
    nil = C_nil;
    if (exception_pending()) goto v0593;
    env = stack[-1];
    goto v0009;

v0009:
    if (v0576 == nil) goto v0332;
    v0576 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0576); }

v0332:
    v0576 = stack[0];
    if (symbolp(v0576)) goto v0559;
    v0576 = stack[0];
    fn = elt(env, 5); // listp
    v0576 = (*qfn1(fn))(qenv(fn), v0576);
    nil = C_nil;
    if (exception_pending()) goto v0593;
    env = stack[-1];
    if (v0576 == nil) goto v0469;
    v0576 = stack[0];
    v0576 = qcar(v0576);
    if (!(symbolp(v0576))) goto v0469;
    v0576 = stack[0];
    v0582 = qcar(v0576);
    v0576 = elt(env, 3); // (!*sq set setq plus minus difference times quotient)
    v0576 = Lmemq(nil, v0582, v0576);
    if (!(v0576 == nil)) goto v0469;
    v0576 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0576); }

v0469:
    v0576 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0576); }

v0559:
    v0576 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0576); }

v0595:
    v0576 = qvalue(elt(env, 1)); // t
    goto v0009;
// error exit handlers
v0593:
    popv(2);
    return nil;
}



// Code for propagator

static LispObject CC_propagator(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0581, v0471;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for propagator");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue
    v0581 = stack[-1];
    if (v0581 == nil) goto v0332;
    v0581 = stack[-1];
    fn = elt(env, 2); // repeatsp
    v0581 = (*qfn1(fn))(qenv(fn), v0581);
    nil = C_nil;
    if (exception_pending()) goto v0576;
    env = stack[-3];
    if (!(v0581 == nil)) goto v0596;
    v0581 = stack[0];
    fn = elt(env, 2); // repeatsp
    v0581 = (*qfn1(fn))(qenv(fn), v0581);
    nil = C_nil;
    if (exception_pending()) goto v0576;
    env = stack[-3];
    if (!(v0581 == nil)) goto v0596;
    stack[-2] = elt(env, 1); // plus
    v0581 = stack[0];
    fn = elt(env, 3); // permutations
    v0471 = (*qfn1(fn))(qenv(fn), v0581);
    nil = C_nil;
    if (exception_pending()) goto v0576;
    env = stack[-3];
    v0581 = stack[0];
    fn = elt(env, 4); // propag
    v0581 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v0471, v0581);
    nil = C_nil;
    if (exception_pending()) goto v0576;
    {
        LispObject v0582 = stack[-2];
        popv(4);
        return cons(v0582, v0581);
    }

v0596:
    v0581 = (LispObject)1; // 0
    { popv(4); return onevalue(v0581); }

v0332:
    v0581 = (LispObject)17; // 1
    { popv(4); return onevalue(v0581); }
// error exit handlers
v0576:
    popv(4);
    return nil;
}



// Code for red!=recover

static LispObject CC_redMrecover(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0611, v0462;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red=recover");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0355;
// end of prologue
    stack[-4] = nil;
    stack[-2] = nil;
    v0611 = stack[-3];
    fn = elt(env, 2); // bas_rep
    v0611 = (*qfn1(fn))(qenv(fn), v0611);
    nil = C_nil;
    if (exception_pending()) goto v0626;
    env = stack[-5];
    stack[-1] = v0611;
    goto v0596;

v0596:
    v0611 = stack[-1];
    if (v0611 == nil) goto v0598;
    v0611 = stack[-1];
    v0611 = qcar(v0611);
    stack[0] = v0611;
    v0611 = stack[0];
    v0611 = qcar(v0611);
    fn = elt(env, 3); // mo_comp
    v0462 = (*qfn1(fn))(qenv(fn), v0611);
    nil = C_nil;
    if (exception_pending()) goto v0626;
    env = stack[-5];
    v0611 = (LispObject)1; // 0
    v0611 = (LispObject)lessp2(v0462, v0611);
    nil = C_nil;
    if (exception_pending()) goto v0626;
    v0611 = v0611 ? lisp_true : nil;
    env = stack[-5];
    if (v0611 == nil) goto v0597;
    v0462 = stack[0];
    v0611 = stack[-4];
    v0611 = cons(v0462, v0611);
    nil = C_nil;
    if (exception_pending()) goto v0626;
    env = stack[-5];
    stack[-4] = v0611;
    goto v0530;

v0530:
    v0611 = stack[-1];
    v0611 = qcdr(v0611);
    stack[-1] = v0611;
    goto v0596;

v0597:
    v0462 = stack[0];
    v0611 = stack[-2];
    v0611 = cons(v0462, v0611);
    nil = C_nil;
    if (exception_pending()) goto v0626;
    env = stack[-5];
    stack[-2] = v0611;
    goto v0530;

v0598:
    v0611 = stack[-3];
    fn = elt(env, 4); // bas_nr
    stack[0] = (*qfn1(fn))(qenv(fn), v0611);
    nil = C_nil;
    if (exception_pending()) goto v0626;
    env = stack[-5];
    v0611 = stack[-4];
    fn = elt(env, 5); // red!=hide
    v0611 = (*qfn1(fn))(qenv(fn), v0611);
    nil = C_nil;
    if (exception_pending()) goto v0626;
    env = stack[-5];
    v0611 = Lnreverse(nil, v0611);
    env = stack[-5];
    fn = elt(env, 6); // dp_neworder
    v0462 = (*qfn1(fn))(qenv(fn), v0611);
    nil = C_nil;
    if (exception_pending()) goto v0626;
    env = stack[-5];
    v0611 = stack[-2];
    v0611 = Lnreverse(nil, v0611);
    env = stack[-5];
    {
        LispObject v0615 = stack[0];
        popv(6);
        fn = elt(env, 7); // bas_make1
        return (*qfnn(fn))(qenv(fn), 3, v0615, v0462, v0611);
    }
// error exit handlers
v0626:
    popv(6);
    return nil;
}



// Code for modroots2

static LispObject CC_modroots2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0447, v0448, v0628, v0543;
    LispObject fn;
    LispObject v0344, v0354, v0355;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "modroots2");
    va_start(aa, nargs);
    v0355 = va_arg(aa, LispObject);
    v0354 = va_arg(aa, LispObject);
    v0344 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modroots2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0344,v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0355,v0354,v0344);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0628 = v0344;
    stack[-3] = v0354;
    v0543 = v0355;
// end of prologue
    v0447 = v0543;
    if (!consp(v0447)) goto v0591;
    v0447 = v0543;
    v0447 = qcar(v0447);
    v0447 = (consp(v0447) ? nil : lisp_true);
    goto v0592;

v0592:
    if (v0447 == nil) goto v0533;
    v0447 = v0543;
    goto v0596;

v0596:
    if (v0447 == nil) goto v0009;
    v0447 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0447); }

v0009:
    v0447 = v0543;
    if (v0447 == nil) goto v0581;
    v0448 = stack[-3];
    v0447 = (LispObject)33; // 2
    if (v0448 == v0447) goto v0444;
    v0448 = v0543;
    v0447 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); // modroots3
        return (*qfn2(fn))(qenv(fn), v0448, v0447);
    }

v0444:
    v0448 = v0543;
    v0447 = qvalue(elt(env, 1)); // t
    {
        popv(6);
        fn = elt(env, 5); // modroots4
        return (*qfnn(fn))(qenv(fn), 3, v0448, v0447, v0628);
    }

v0581:
    v0448 = stack[-3];
    v0447 = (LispObject)33; // 2
    if (v0448 == v0447) goto v0556;
    v0447 = qvalue(elt(env, 2)); // nil
    goto v0555;

v0555:
    if (v0447 == nil) goto v0468;
    v0447 = elt(env, 3); // (-1 0 1)
    { popv(6); return onevalue(v0447); }

v0468:
    v0447 = (LispObject)1; // 0
    stack[-4] = v0447;
    v0447 = stack[-3];
    v0448 = sub1(v0447);
    nil = C_nil;
    if (exception_pending()) goto v0629;
    env = stack[-5];
    v0447 = stack[-4];
    v0447 = difference2(v0448, v0447);
    nil = C_nil;
    if (exception_pending()) goto v0629;
    env = stack[-5];
    v0447 = Lminusp(nil, v0447);
    env = stack[-5];
    if (v0447 == nil) goto v0458;
    v0447 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0447); }

v0458:
    v0447 = stack[-4];
    v0447 = ncons(v0447);
    nil = C_nil;
    if (exception_pending()) goto v0629;
    env = stack[-5];
    stack[-1] = v0447;
    stack[-2] = v0447;
    goto v0630;

v0630:
    v0447 = stack[-4];
    v0447 = add1(v0447);
    nil = C_nil;
    if (exception_pending()) goto v0629;
    env = stack[-5];
    stack[-4] = v0447;
    v0447 = stack[-3];
    v0448 = sub1(v0447);
    nil = C_nil;
    if (exception_pending()) goto v0629;
    env = stack[-5];
    v0447 = stack[-4];
    v0447 = difference2(v0448, v0447);
    nil = C_nil;
    if (exception_pending()) goto v0629;
    env = stack[-5];
    v0447 = Lminusp(nil, v0447);
    env = stack[-5];
    if (!(v0447 == nil)) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0447 = stack[-4];
    v0447 = ncons(v0447);
    nil = C_nil;
    if (exception_pending()) goto v0629;
    env = stack[-5];
    v0447 = Lrplacd(nil, stack[0], v0447);
    nil = C_nil;
    if (exception_pending()) goto v0629;
    env = stack[-5];
    v0447 = stack[-1];
    v0447 = qcdr(v0447);
    stack[-1] = v0447;
    goto v0630;

v0556:
    v0447 = v0628;
    goto v0555;

v0533:
    v0447 = qvalue(elt(env, 2)); // nil
    goto v0596;

v0591:
    v0447 = qvalue(elt(env, 1)); // t
    goto v0592;
// error exit handlers
v0629:
    popv(6);
    return nil;
}



// Code for conjsq

static LispObject CC_conjsq(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0463, v0601;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for conjsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0355;
// end of prologue
    v0463 = stack[0];
    fn = elt(env, 2); // impartsq
    v0463 = (*qfn1(fn))(qenv(fn), v0463);
    nil = C_nil;
    if (exception_pending()) goto v0555;
    env = stack[-2];
    stack[-1] = v0463;
    v0463 = stack[-1];
    v0463 = qcar(v0463);
    if (v0463 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0463 = stack[0];
    fn = elt(env, 3); // repartsq
    stack[0] = (*qfn1(fn))(qenv(fn), v0463);
    nil = C_nil;
    if (exception_pending()) goto v0555;
    env = stack[-2];
    v0463 = elt(env, 1); // i
    fn = elt(env, 4); // simp
    v0601 = (*qfn1(fn))(qenv(fn), v0463);
    nil = C_nil;
    if (exception_pending()) goto v0555;
    env = stack[-2];
    v0463 = stack[-1];
    fn = elt(env, 5); // multsq
    v0463 = (*qfn2(fn))(qenv(fn), v0601, v0463);
    nil = C_nil;
    if (exception_pending()) goto v0555;
    env = stack[-2];
    fn = elt(env, 6); // negsq
    v0463 = (*qfn1(fn))(qenv(fn), v0463);
    nil = C_nil;
    if (exception_pending()) goto v0555;
    env = stack[-2];
    {
        LispObject v0556 = stack[0];
        popv(3);
        fn = elt(env, 7); // addsq
        return (*qfn2(fn))(qenv(fn), v0556, v0463);
    }
// error exit handlers
v0555:
    popv(3);
    return nil;
}



// Code for rl_b2atl

static LispObject CC_rl_b2atl(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0610, v0608;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_b2atl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0610 = v0354;
    v0608 = v0355;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_b2atl!*
    v0610 = list2(v0608, v0610);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-1];
    {
        LispObject v0530 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0530, v0610);
    }
// error exit handlers
v0465:
    popv(2);
    return nil;
}



// Code for ofsf_updsignadd

static LispObject CC_ofsf_updsignadd(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0636, v0539;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_updsignadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue
    v0636 = stack[-1];
    if (v0636 == nil) goto v0596;
    v0539 = stack[-1];
    v0636 = elt(env, 2); // equal
    v0636 = (v0539 == v0636 ? lisp_true : nil);
    goto v0595;

v0595:
    if (!(v0636 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0539 = stack[0];
    v0636 = elt(env, 2); // equal
    if (v0539 == v0636) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0539 = stack[-1];
    v0636 = stack[0];
    if (v0539 == v0636) goto v0619;
    v0636 = qvalue(elt(env, 4)); // nil
    goto v0556;

v0556:
    if (!(v0636 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0539 = stack[-1];
    v0636 = elt(env, 5); // leq
    if (v0539 == v0636) goto v0327;
    v0636 = qvalue(elt(env, 4)); // nil
    goto v0552;

v0552:
    if (v0636 == nil) goto v0599;
    v0636 = qvalue(elt(env, 1)); // t
    goto v0574;

v0574:
    if (v0636 == nil) goto v0446;
    v0636 = elt(env, 6); // lessp
    { popv(3); return onevalue(v0636); }

v0446:
    v0539 = stack[-1];
    v0636 = elt(env, 7); // geq
    if (v0539 == v0636) goto v0565;
    v0636 = qvalue(elt(env, 4)); // nil
    goto v0623;

v0623:
    if (v0636 == nil) goto v0545;
    v0636 = qvalue(elt(env, 1)); // t
    goto v0621;

v0621:
    if (v0636 == nil) goto v0637;
    v0636 = elt(env, 8); // greaterp
    { popv(3); return onevalue(v0636); }

v0637:
    v0636 = elt(env, 9); // unknown
    { popv(3); return onevalue(v0636); }

v0545:
    v0539 = stack[-1];
    v0636 = elt(env, 8); // greaterp
    if (v0539 == v0636) goto v0439;
    v0636 = qvalue(elt(env, 4)); // nil
    goto v0621;

v0439:
    v0539 = stack[0];
    v0636 = elt(env, 7); // geq
    v0636 = (v0539 == v0636 ? lisp_true : nil);
    goto v0621;

v0565:
    v0539 = stack[0];
    v0636 = elt(env, 8); // greaterp
    v0636 = (v0539 == v0636 ? lisp_true : nil);
    goto v0623;

v0599:
    v0539 = stack[-1];
    v0636 = elt(env, 6); // lessp
    if (v0539 == v0636) goto v0443;
    v0636 = qvalue(elt(env, 4)); // nil
    goto v0574;

v0443:
    v0539 = stack[0];
    v0636 = elt(env, 5); // leq
    v0636 = (v0539 == v0636 ? lisp_true : nil);
    goto v0574;

v0327:
    v0539 = stack[0];
    v0636 = elt(env, 6); // lessp
    v0636 = (v0539 == v0636 ? lisp_true : nil);
    goto v0552;

v0619:
    v0539 = stack[-1];
    v0636 = elt(env, 3); // neq
    v0636 = Lneq(nil, v0539, v0636);
    nil = C_nil;
    if (exception_pending()) goto v0638;
    env = stack[-2];
    goto v0556;

v0596:
    v0636 = qvalue(elt(env, 1)); // t
    goto v0595;
// error exit handlers
v0638:
    popv(3);
    return nil;
}



// Code for cd_ordatp

static LispObject CC_cd_ordatp(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0461, v0459, v0460, v0327;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cd_ordatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0460 = v0354;
    v0327 = v0355;
// end of prologue
    v0461 = v0327;
    v0459 = qcar(v0461);
    v0461 = elt(env, 1); // neq
    if (v0459 == v0461) goto v0608;
    v0461 = qvalue(elt(env, 3)); // nil
    goto v0595;

v0595:
    if (v0461 == nil) goto v0583;
    v0461 = qvalue(elt(env, 4)); // t
    return onevalue(v0461);

v0583:
    v0461 = v0327;
    v0459 = qcar(v0461);
    v0461 = elt(env, 2); // equal
    if (v0459 == v0461) goto v0597;
    v0461 = qvalue(elt(env, 3)); // nil
    goto v0604;

v0604:
    if (v0461 == nil) goto v0574;
    v0461 = qvalue(elt(env, 3)); // nil
    return onevalue(v0461);

v0574:
    v0461 = v0327;
    v0461 = qcdr(v0461);
    v0461 = qcar(v0461);
    v0459 = v0460;
    v0459 = qcdr(v0459);
    v0459 = qcar(v0459);
    {
        fn = elt(env, 5); // ordp
        return (*qfn2(fn))(qenv(fn), v0461, v0459);
    }

v0597:
    v0461 = v0460;
    v0459 = qcar(v0461);
    v0461 = elt(env, 1); // neq
    v0461 = (v0459 == v0461 ? lisp_true : nil);
    goto v0604;

v0608:
    v0461 = v0460;
    v0459 = qcar(v0461);
    v0461 = elt(env, 2); // equal
    v0461 = (v0459 == v0461 ? lisp_true : nil);
    goto v0595;
}



// Code for unary

static LispObject CC_unary(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0602, v0604;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unary");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue
    v0602 = elt(env, 1); // "<apply>"
    fn = elt(env, 6); // printout
    v0602 = (*qfn1(fn))(qenv(fn), v0602);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-2];
    v0602 = elt(env, 2); // "<"
    v0602 = Lprinc(nil, v0602);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-2];
    v0602 = stack[0];
    v0602 = Lprinc(nil, v0602);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-2];
    v0602 = elt(env, 3); // "/>"
    v0602 = Lprinc(nil, v0602);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-2];
    v0604 = qvalue(elt(env, 4)); // indent
    v0602 = (LispObject)49; // 3
    v0602 = plus2(v0604, v0602);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0602; // indent
    v0602 = stack[-1];
    v0602 = qcar(v0602);
    fn = elt(env, 7); // expression
    v0602 = (*qfn1(fn))(qenv(fn), v0602);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-2];
    v0604 = qvalue(elt(env, 4)); // indent
    v0602 = (LispObject)49; // 3
    v0602 = difference2(v0604, v0602);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0602; // indent
    v0602 = elt(env, 5); // "</apply>"
    fn = elt(env, 6); // printout
    v0602 = (*qfn1(fn))(qenv(fn), v0602);
    nil = C_nil;
    if (exception_pending()) goto v0583;
    v0602 = nil;
    { popv(3); return onevalue(v0602); }
// error exit handlers
v0583:
    popv(3);
    return nil;
}



// Code for new_edge

static LispObject CC_new_edge(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0468, v0466;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for new_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue
    v0468 = stack[-1];
    v0466 = qcar(v0468);
    v0468 = stack[0];
    v0468 = qcar(v0468);
    fn = elt(env, 3); // mk_edge_name
    stack[-2] = (*qfn2(fn))(qenv(fn), v0466, v0468);
    nil = C_nil;
    if (exception_pending()) goto v0598;
    env = stack[-3];
    v0468 = stack[-1];
    v0466 = qcar(v0468);
    v0468 = stack[0];
    v0468 = qcar(v0468);
    v0466 = cons(v0466, v0468);
    nil = C_nil;
    if (exception_pending()) goto v0598;
    env = stack[-3];
    v0468 = qvalue(elt(env, 1)); // nil
    v0468 = list3(stack[-2], v0466, v0468);
    nil = C_nil;
    if (exception_pending()) goto v0598;
    env = stack[-3];
    stack[0] = v0468;
    v0466 = stack[0];
    v0468 = qvalue(elt(env, 2)); // new_edge_list
    v0468 = cons(v0466, v0468);
    nil = C_nil;
    if (exception_pending()) goto v0598;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0468; // new_edge_list
    { LispObject res = stack[0]; popv(4); return onevalue(res); }
// error exit handlers
v0598:
    popv(4);
    return nil;
}



// Code for partsym_zerop

static LispObject CC_partsym_zerop(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0619, v0639, v0554;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for partsym_zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue

v0640:
    v0619 = stack[-1];
    if (v0619 == nil) goto v0332;
    v0619 = stack[-1];
    v0619 = qcar(v0619);
    fn = elt(env, 3); // repeats
    v0619 = (*qfn1(fn))(qenv(fn), v0619);
    nil = C_nil;
    if (exception_pending()) goto v0467;
    env = stack[-2];
    v0554 = v0619;
    v0619 = stack[0];
    v0639 = qcar(v0619);
    v0619 = elt(env, 2); // !-
    if (v0639 == v0619) goto v0465;
    v0619 = qvalue(elt(env, 1)); // nil
    goto v0531;

v0531:
    if (!(v0619 == nil)) { popv(3); return onevalue(v0554); }
    v0619 = stack[-1];
    v0639 = qcdr(v0619);
    v0619 = stack[0];
    v0619 = qcdr(v0619);
    stack[-1] = v0639;
    stack[0] = v0619;
    goto v0640;

v0465:
    v0619 = v0554;
    goto v0531;

v0332:
    v0619 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0619); }
// error exit handlers
v0467:
    popv(3);
    return nil;
}



// Code for sc_repkern

static LispObject CC_sc_repkern(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0399, v0400, v0657;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_repkern");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0354;
    v0400 = v0355;
// end of prologue
    v0399 = v0400;
    v0657 = qcar(v0399);
    v0399 = elt(env, 1); // !*
    if (v0657 == v0399) goto v0332;
    stack[-1] = nil;
    stack[-6] = nil;
    stack[-4] = nil;
    v0399 = v0400;
    v0399 = qcdr(v0399);
    v0400 = v0399;
    v0399 = v0400;
    stack[-2] = v0399;
    goto v0658;

v0658:
    v0399 = stack[-2];
    if (v0399 == nil) goto v0429;
    v0399 = stack[-2];
    v0399 = qcar(v0399);
    v0400 = v0399;
    v0657 = v0400;
    v0399 = stack[-1];
    v0399 = Lassoc(nil, v0657, v0399);
    v0657 = v0399;
    if (v0399 == nil) goto v0659;
    stack[0] = v0657;
    v0399 = v0657;
    v0399 = qcdr(v0399);
    v0399 = add1(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    v0399 = Lrplacd(nil, stack[0], v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    goto v0661;

v0661:
    v0399 = stack[-2];
    v0399 = qcdr(v0399);
    stack[-2] = v0399;
    goto v0658;

v0659:
    v0657 = v0400;
    v0400 = (LispObject)17; // 1
    v0399 = stack[-1];
    v0399 = acons(v0657, v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-1] = v0399;
    goto v0661;

v0429:
    v0400 = stack[-1];
    v0399 = elt(env, 3); // lambda_pbthn8t73vcc
    fn = elt(env, 4); // sort
    v0399 = (*qfn2(fn))(qenv(fn), v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-1] = v0399;
    v0399 = (LispObject)1; // 0
    stack[-3] = v0399;
    v0399 = stack[-1];
    stack[-2] = v0399;
    goto v0422;

v0422:
    v0399 = stack[-2];
    if (v0399 == nil) goto v0662;
    v0399 = stack[-2];
    v0399 = qcar(v0399);
    stack[-1] = v0399;
    v0399 = stack[-1];
    v0400 = qcdr(v0399);
    v0399 = stack[-3];
    if (equal(v0400, v0399)) goto v0663;
    v0399 = stack[-1];
    v0657 = qcdr(v0399);
    v0400 = (LispObject)17; // 1
    v0399 = stack[-6];
    v0399 = acons(v0657, v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-6] = v0399;
    v0399 = stack[-1];
    v0399 = qcar(v0399);
    v0400 = ncons(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    v0399 = stack[-4];
    v0399 = cons(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-4] = v0399;
    v0399 = stack[-1];
    v0399 = qcdr(v0399);
    stack[-3] = v0399;
    goto v0423;

v0423:
    v0399 = stack[-2];
    v0399 = qcdr(v0399);
    stack[-2] = v0399;
    goto v0422;

v0663:
    v0399 = stack[-6];
    stack[0] = qcar(v0399);
    v0399 = stack[-6];
    v0399 = qcar(v0399);
    v0399 = qcdr(v0399);
    v0399 = add1(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    v0399 = Lrplacd(nil, stack[0], v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[0] = stack[-4];
    v0399 = stack[-1];
    v0400 = qcar(v0399);
    v0399 = stack[-4];
    v0399 = qcar(v0399);
    v0399 = cons(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    v0399 = Lrplaca(nil, stack[0], v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    goto v0423;

v0662:
    stack[0] = stack[-6];
    v0400 = stack[-4];
    v0399 = stack[-5];
    fn = elt(env, 5); // pa_list2vect
    v0399 = (*qfn2(fn))(qenv(fn), v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    {
        LispObject v0664 = stack[0];
        popv(8);
        return list2(v0664, v0399);
    }

v0332:
    stack[-6] = nil;
    v0399 = v0400;
    v0399 = qcdr(v0399);
    stack[0] = v0399;
    v0399 = (LispObject)1; // 0
    stack[-2] = v0399;
    goto v0474;

v0474:
    v0399 = stack[0];
    if (v0399 == nil) goto v0568;
    v0399 = stack[0];
    v0399 = qcar(v0399);
    stack[-3] = v0399;
    v0399 = stack[-3];
    v0400 = ncons(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    v0399 = stack[-6];
    v0399 = cons(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-6] = v0399;
    v0399 = stack[0];
    v0399 = qcdr(v0399);
    stack[0] = v0399;
    v0399 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0399;
    v0400 = stack[-2];
    v0399 = (LispObject)33; // 2
    v0399 = times2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    v0399 = add1(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-2] = v0399;
    v0399 = stack[0];
    stack[-1] = v0399;
    goto v0574;

v0574:
    v0399 = stack[-1];
    if (v0399 == nil) goto v0458;
    v0399 = stack[-1];
    v0399 = qcar(v0399);
    stack[0] = v0399;
    v0400 = stack[0];
    v0399 = stack[-3];
    if (v0400 == v0399) goto v0550;
    v0400 = stack[-2];
    v0399 = (LispObject)33; // 2
    v0399 = times2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-2] = v0399;
    v0400 = stack[0];
    v0399 = stack[-4];
    v0399 = cons(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-4] = v0399;
    goto v0459;

v0459:
    v0399 = stack[-1];
    v0399 = qcdr(v0399);
    stack[-1] = v0399;
    goto v0574;

v0550:
    v0400 = stack[-2];
    v0399 = (LispObject)33; // 2
    v0399 = times2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    v0399 = add1(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[-2] = v0399;
    goto v0459;

v0458:
    v0399 = stack[-4];
    v0399 = Lreverse(nil, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    stack[0] = v0399;
    goto v0474;

v0568:
    stack[0] = stack[-2];
    v0399 = stack[-6];
    v0400 = Lreverse(nil, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-7];
    v0399 = stack[-5];
    fn = elt(env, 5); // pa_list2vect
    v0399 = (*qfn2(fn))(qenv(fn), v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    {
        LispObject v0665 = stack[0];
        popv(8);
        return list2(v0665, v0399);
    }
// error exit handlers
v0660:
    popv(8);
    return nil;
}



// Code for lambda_pbthn8t73vcc

static LispObject CC_lambda_pbthn8t73vcc(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0592, v0591;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_pbthn8t73vcc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0592 = v0354;
    v0591 = v0355;
// end of prologue
    v0591 = qcdr(v0591);
    v0592 = qcdr(v0592);
        return Lleq(nil, v0591, v0592);
}



// Code for makeupsf

static LispObject CC_makeupsf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0419, v0560, v0670, v0671;
    LispObject fn;
    LispObject v0344, v0354, v0355;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeupsf");
    va_start(aa, nargs);
    v0355 = va_arg(aa, LispObject);
    v0354 = va_arg(aa, LispObject);
    v0344 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makeupsf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0344,v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0355,v0354,v0344);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0344;
    stack[-1] = v0354;
    v0671 = v0355;
// end of prologue
    v0419 = v0671;
    v0419 = qcar(v0419);
    if (!consp(v0419)) goto v0529;
    v0419 = v0671;
    v0560 = qcdr(v0419);
    v0419 = (LispObject)17; // 1
    v0419 = (v0560 == v0419 ? lisp_true : nil);
    goto v0596;

v0596:
    if (v0419 == nil) goto v0468;
    v0560 = v0671;
    v0419 = (LispObject)17; // 1
    v0419 = cons(v0560, v0419);
    nil = C_nil;
    if (exception_pending()) goto v0538;
    env = stack[-2];
    v0560 = ncons(v0419);
    nil = C_nil;
    if (exception_pending()) goto v0538;
    env = stack[-2];
    v0419 = stack[-1];
    fn = elt(env, 6); // multf
    v0560 = (*qfn2(fn))(qenv(fn), v0560, v0419);
    nil = C_nil;
    if (exception_pending()) goto v0538;
    env = stack[-2];
    v0419 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0560, v0419);
    }

v0468:
    v0419 = v0671;
    v0419 = qcar(v0419);
    v0560 = qcar(v0419);
    v0419 = elt(env, 2); // sqrt
    if (v0560 == v0419) goto v0618;
    v0419 = v0671;
    v0419 = qcar(v0419);
    v0670 = v0419;
    v0419 = v0670;
    v0560 = qcar(v0419);
    v0419 = elt(env, 3); // expt
    if (v0560 == v0419) goto v0572;
    v0419 = qvalue(elt(env, 4)); // nil
    goto v0586;

v0586:
    if (v0419 == nil) goto v0437;
    v0419 = v0671;
    v0560 = qcar(v0419);
    v0419 = stack[-1];
    v0670 = v0671;
    v0670 = qcdr(v0670);
    fn = elt(env, 8); // !*multfexpt
    v0560 = (*qfnn(fn))(qenv(fn), 3, v0560, v0419, v0670);
    nil = C_nil;
    if (exception_pending()) goto v0538;
    env = stack[-2];
    v0419 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0560, v0419);
    }

v0437:
    v0560 = v0671;
    v0419 = (LispObject)17; // 1
    v0419 = cons(v0560, v0419);
    nil = C_nil;
    if (exception_pending()) goto v0538;
    env = stack[-2];
    v0560 = ncons(v0419);
    nil = C_nil;
    if (exception_pending()) goto v0538;
    env = stack[-2];
    v0419 = stack[-1];
    fn = elt(env, 6); // multf
    v0560 = (*qfn2(fn))(qenv(fn), v0560, v0419);
    nil = C_nil;
    if (exception_pending()) goto v0538;
    env = stack[-2];
    v0419 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0560, v0419);
    }

v0572:
    v0419 = v0670;
    v0419 = qcdr(v0419);
    v0419 = qcdr(v0419);
    v0419 = qcar(v0419);
    v0670 = v0419;
    v0419 = v0670;
    if (!consp(v0419)) goto v0571;
    v0419 = v0670;
    v0560 = qcar(v0419);
    v0419 = elt(env, 5); // quotient
    if (v0560 == v0419) goto v0453;
    v0419 = qvalue(elt(env, 4)); // nil
    goto v0586;

v0453:
    v0419 = v0670;
    v0419 = qcdr(v0419);
    v0419 = qcar(v0419);
    if (is_number(v0419)) goto v0565;
    v0419 = qvalue(elt(env, 4)); // nil
    goto v0586;

v0565:
    v0419 = v0670;
    v0419 = qcdr(v0419);
    v0419 = qcdr(v0419);
    v0419 = qcar(v0419);
    v0419 = (is_number(v0419) ? lisp_true : nil);
    goto v0586;

v0571:
    v0419 = qvalue(elt(env, 4)); // nil
    goto v0586;

v0618:
    v0419 = v0671;
    v0560 = qcar(v0419);
    v0419 = stack[-1];
    v0670 = v0671;
    v0670 = qcdr(v0670);
    fn = elt(env, 9); // !*multfsqrt
    v0560 = (*qfnn(fn))(qenv(fn), 3, v0560, v0419, v0670);
    nil = C_nil;
    if (exception_pending()) goto v0538;
    env = stack[-2];
    v0419 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0560, v0419);
    }

v0529:
    v0419 = qvalue(elt(env, 1)); // t
    goto v0596;
// error exit handlers
v0538:
    popv(3);
    return nil;
}



// Code for quotfail

static LispObject CC_quotfail(LispObject env,
                         LispObject v0355, LispObject v0354)
{
    LispObject nil = C_nil;
    LispObject v0470, v0464, v0576;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfail");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0354,v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0355,v0354);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0354;
    stack[-1] = v0355;
// end of prologue
    v0470 = stack[-1];
    if (v0470 == nil) goto v0332;
    v0464 = stack[-1];
    v0470 = stack[0];
    fn = elt(env, 3); // quotf
    v0470 = (*qfn2(fn))(qenv(fn), v0464, v0470);
    nil = C_nil;
    if (exception_pending()) goto v0593;
    env = stack[-2];
    v0464 = v0470;
    v0470 = v0464;
    if (!(v0470 == nil)) { popv(3); return onevalue(v0464); }
    v0576 = elt(env, 2); // "UNEXPECTED DIVISION FAILURE"
    v0464 = stack[-1];
    v0470 = stack[0];
    v0470 = list3(v0576, v0464, v0470);
    nil = C_nil;
    if (exception_pending()) goto v0593;
    env = stack[-2];
    fn = elt(env, 4); // errorf
    v0470 = (*qfn1(fn))(qenv(fn), v0470);
    nil = C_nil;
    if (exception_pending()) goto v0593;
    v0470 = nil;
    { popv(3); return onevalue(v0470); }

v0332:
    v0470 = qvalue(elt(env, 1)); // polyzero
    { popv(3); return onevalue(v0470); }
// error exit handlers
v0593:
    popv(3);
    return nil;
}



// Code for conjgd

static LispObject CC_conjgd(LispObject env,
                         LispObject v0355)
{
    LispObject nil = C_nil;
    LispObject v0434, v0674;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for conjgd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0355);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0355;
// end of prologue
    v0674 = nil;
    v0434 = stack[-1];
    if (!consp(v0434)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0434 = stack[-1];
    if (!consp(v0434)) goto v0608;
    v0434 = stack[-1];
    v0434 = qcar(v0434);
    v0434 = (consp(v0434) ? nil : lisp_true);
    goto v0610;

v0610:
    if (v0434 == nil) goto v0556;
    v0434 = stack[-1];
    v0674 = qcar(v0434);
    v0434 = elt(env, 2); // cmpxfn
    v0434 = get(v0674, v0434);
    env = stack[-3];
    v0674 = v0434;
    goto v0591;

v0591:
    if (v0434 == nil) goto v0590;
    stack[-2] = v0674;
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    stack[0] = qcar(v0434);
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    v0434 = qcdr(v0434);
    if (is_number(v0434)) goto v0594;
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    v0434 = qcdr(v0434);
    if (!consp(v0434)) goto v0611;
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    v0434 = qcdr(v0434);
    v0434 = qcar(v0434);
    v0434 = (consp(v0434) ? nil : lisp_true);
    goto v0612;

v0612:
    if (v0434 == nil) goto v0561;
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    v0434 = qcdr(v0434);
    v0434 = qcar(v0434);
    v0434 = (is_number(v0434) ? lisp_true : nil);
    v0434 = (v0434 == nil ? lisp_true : nil);
    goto v0552;

v0552:
    if (v0434 == nil) goto v0564;
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    v0434 = qcdr(v0434);
    fn = elt(env, 5); // !:minus
    v0434 = (*qfn1(fn))(qenv(fn), v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    goto v0597;

v0597:
    {
        LispObject v0539 = stack[-2];
        LispObject v0540 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v0539, v0540, v0434);
    }

v0564:
    v0434 = stack[-1];
    v0674 = qcar(v0434);
    v0434 = elt(env, 4); // realtype
    v0674 = get(v0674, v0434);
    env = stack[-3];
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    v0434 = qcdr(v0434);
    v0434 = cons(v0674, v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    fn = elt(env, 5); // !:minus
    v0434 = (*qfn1(fn))(qenv(fn), v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    v0434 = qcdr(v0434);
    goto v0597;

v0561:
    v0434 = qvalue(elt(env, 3)); // nil
    goto v0552;

v0611:
    v0434 = qvalue(elt(env, 1)); // t
    goto v0612;

v0594:
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    v0434 = qcdr(v0434);
    v0434 = negate(v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    goto v0597;

v0590:
    v0434 = stack[-1];
    if (!consp(v0434)) goto v0446;
    v0434 = stack[-1];
    v0434 = qcar(v0434);
    v0434 = (consp(v0434) ? nil : lisp_true);
    goto v0445;

v0445:
    if (!(v0434 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0434 = stack[-1];
    v0434 = qcar(v0434);
    v0674 = qcar(v0434);
    v0434 = (LispObject)17; // 1
    v0434 = cons(v0674, v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    stack[0] = ncons(v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    v0434 = stack[-1];
    v0434 = qcar(v0434);
    v0434 = qcdr(v0434);
    v0434 = CC_conjgd(env, v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    v0434 = stack[-1];
    v0434 = qcdr(v0434);
    v0434 = CC_conjgd(env, v0434);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    {
        LispObject v0675 = stack[0];
        popv(4);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0675, v0434);
    }

v0446:
    v0434 = qvalue(elt(env, 1)); // t
    goto v0445;

v0556:
    v0434 = qvalue(elt(env, 3)); // nil
    goto v0591;

v0608:
    v0434 = qvalue(elt(env, 1)); // t
    goto v0610;
// error exit handlers
v0636:
    popv(4);
    return nil;
}



setup_type const u48_setup[] =
{
    {"com43",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_com43},
    {"formclear",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclear},
    {"cdr_signsort",            too_few_2,      CC_cdr_signsort,wrong_no_2},
    {"distri_pol",              CC_distri_pol,  too_many_1,    wrong_no_1},
    {"spreadvar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_spreadvar},
    {"mri_dettype",             CC_mri_dettype, too_many_1,    wrong_no_1},
    {"lto_alunion",             CC_lto_alunion, too_many_1,    wrong_no_1},
    {"mkarg",                   too_few_2,      CC_mkarg,      wrong_no_2},
    {"negdf",                   CC_negdf,       too_many_1,    wrong_no_1},
    {"ps:find-order",           CC_psTfindKorder,too_many_1,   wrong_no_1},
    {"multup",                  CC_multup,      too_many_1,    wrong_no_1},
    {"pm:gensym",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pmTgensym},
    {"dipbcprod",               too_few_2,      CC_dipbcprod,  wrong_no_2},
    {"groebsimpcontnormalform", CC_groebsimpcontnormalform,too_many_1,wrong_no_1},
    {"add-to-sorted-tree",      too_few_2,      CC_addKtoKsortedKtree,wrong_no_2},
    {":quotient",               too_few_2,      CC_Tquotient,  wrong_no_2},
    {"lispcondp",               CC_lispcondp,   too_many_1,    wrong_no_1},
    {"kernelp",                 CC_kernelp,     too_many_1,    wrong_no_1},
    {"propagator",              too_few_2,      CC_propagator, wrong_no_2},
    {"red=recover",             CC_redMrecover, too_many_1,    wrong_no_1},
    {"modroots2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modroots2},
    {"conjsq",                  CC_conjsq,      too_many_1,    wrong_no_1},
    {"rl_b2atl",                too_few_2,      CC_rl_b2atl,   wrong_no_2},
    {"ofsf_updsignadd",         too_few_2,      CC_ofsf_updsignadd,wrong_no_2},
    {"cd_ordatp",               too_few_2,      CC_cd_ordatp,  wrong_no_2},
    {"unary",                   too_few_2,      CC_unary,      wrong_no_2},
    {"new_edge",                too_few_2,      CC_new_edge,   wrong_no_2},
    {"partsym_zerop",           too_few_2,      CC_partsym_zerop,wrong_no_2},
    {"sc_repkern",              too_few_2,      CC_sc_repkern, wrong_no_2},
    {"lambda_pbthn8t73vcc",     too_few_2,      CC_lambda_pbthn8t73vcc,wrong_no_2},
    {"makeupsf",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeupsf},
    {"quotfail",                too_few_2,      CC_quotfail,   wrong_no_2},
    {"conjgd",                  CC_conjgd,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u48", (two_args *)"1454 9444333 8475270", 0}
};

// end of generated code
