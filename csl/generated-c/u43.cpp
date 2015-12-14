
// $destdir\u43.c        Machine generated C code

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



// Code for expvec2a1

static LispObject CC_expvec2a1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015, v0016;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expvec2a1");
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
    goto v0017;

v0017:
    v0014 = stack[-1];
    if (v0014 == nil) goto v0018;
    v0014 = stack[-1];
    v0015 = qcar(v0014);
    v0014 = (LispObject)1; // 0
    if (v0015 == v0014) goto v0019;
    v0014 = stack[-1];
    v0015 = qcar(v0014);
    v0014 = (LispObject)17; // 1
    if (v0015 == v0014) goto v0020;
    v0016 = elt(env, 1); // expt
    v0014 = stack[0];
    v0015 = qcar(v0014);
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    v0015 = list3(v0016, v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-3];
    v0014 = stack[-2];
    v0014 = cons(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-3];
    stack[-2] = v0014;
    v0014 = stack[-1];
    v0014 = qcdr(v0014);
    stack[-1] = v0014;
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    goto v0017;

v0020:
    v0014 = stack[0];
    v0015 = qcar(v0014);
    v0014 = stack[-2];
    v0014 = cons(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-3];
    stack[-2] = v0014;
    v0014 = stack[-1];
    v0014 = qcdr(v0014);
    stack[-1] = v0014;
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    goto v0017;

v0019:
    v0014 = stack[-1];
    v0014 = qcdr(v0014);
    stack[-1] = v0014;
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    goto v0017;

v0018:
    v0014 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0014);
    }
// error exit handlers
v0021:
    popv(4);
    return nil;
}



// Code for deflate1

static LispObject CC_deflate1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0037, v0038, v0039;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deflate1");
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
    v0037 = v0000;
// end of prologue
    stack[-5] = nil;
    fn = elt(env, 2); // ncoeffs
    v0038 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    v0037 = v0038;
    v0038 = qcar(v0038);
    stack[-3] = v0038;
    v0037 = qcdr(v0037);
    v0038 = v0037;
    v0038 = qcar(v0038);
    stack[-2] = v0038;
    v0037 = qcdr(v0037);
    stack[-1] = v0037;
    goto v0041;

v0041:
    v0037 = stack[-1];
    if (v0037 == nil) goto v0042;
    v0037 = stack[-1];
    v0037 = qcar(v0037);
    stack[0] = v0037;
    v0037 = stack[-3];
    v0037 = sub1(v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    stack[-3] = v0037;
    v0037 = stack[-2];
    v0037 = qcdr(v0037);
    v0038 = qcar(v0037);
    v0037 = (LispObject)1; // 0
    if (v0038 == v0037) goto v0043;
    v0039 = stack[-3];
    v0038 = stack[-2];
    v0037 = stack[-5];
    v0037 = acons(v0039, v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    stack[-5] = v0037;
    goto v0043;

v0043:
    v0038 = stack[-4];
    v0037 = stack[-2];
    fn = elt(env, 3); // times!:
    v0037 = (*qfn2(fn))(qenv(fn), v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    stack[-2] = v0037;
    v0037 = stack[0];
    if (v0037 == nil) goto v0044;
    v0038 = stack[0];
    v0037 = stack[-2];
    fn = elt(env, 4); // plus!:
    v0037 = (*qfn2(fn))(qenv(fn), v0038, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    stack[-2] = v0037;
    goto v0044;

v0044:
    v0037 = stack[-1];
    v0037 = qcdr(v0037);
    stack[-1] = v0037;
    goto v0041;

v0042:
    v0038 = stack[-2];
    v0037 = stack[-5];
    popv(7);
    return cons(v0038, v0037);
// error exit handlers
v0040:
    popv(7);
    return nil;
}



// Code for coeff1_calc

static LispObject CC_coeff1_calc(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0008, v0009, v0052;
    LispObject fn;
    LispObject v0049, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff1_calc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeff1_calc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0049;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0053;

v0053:
    v0008 = stack[0];
    if (v0008 == nil) goto v0019;
    v0052 = stack[-2];
    v0009 = stack[-1];
    v0008 = stack[0];
    v0008 = qcar(v0008);
    fn = elt(env, 1); // calc_coeffmap_
    v0009 = (*qfnn(fn))(qenv(fn), 3, v0052, v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0008 = stack[-3];
    v0008 = cons(v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    stack[-3] = v0008;
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    stack[0] = v0008;
    goto v0053;

v0019:
    stack[0] = stack[-3];
    v0008 = (LispObject)1; // 0
    v0008 = ncons(v0008);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    {
        LispObject v0032 = stack[0];
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0032, v0008);
    }
// error exit handlers
v0054:
    popv(5);
    return nil;
}



// Code for dp_prod

static LispObject CC_dp_prod(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0059, v0010;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_prod");
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
    v0059 = stack[-1];
    stack[-2] = Llength(nil, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0059 = stack[0];
    v0059 = Llength(nil, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0059 = (LispObject)lesseq2(stack[-2], v0059);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0059 = v0059 ? lisp_true : nil;
    env = stack[-3];
    if (v0059 == nil) goto v0061;
    v0010 = stack[-1];
    v0059 = stack[0];
    {
        popv(4);
        fn = elt(env, 1); // dp!=prod
        return (*qfn2(fn))(qenv(fn), v0010, v0059);
    }

v0061:
    v0010 = stack[0];
    v0059 = stack[-1];
    {
        popv(4);
        fn = elt(env, 1); // dp!=prod
        return (*qfn2(fn))(qenv(fn), v0010, v0059);
    }
// error exit handlers
v0060:
    popv(4);
    return nil;
}



// Code for dummy_nam

static LispObject CC_dummy_nam(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0064, v0058;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dummy_nam");
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
    v0064 = v0000;
// end of prologue
    fn = elt(env, 4); // ordn
    v0058 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[0];
    v0064 = elt(env, 1); // symbolic
    fn = elt(env, 5); // list2vect!*
    v0064 = (*qfn2(fn))(qenv(fn), v0058, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[0];
    qvalue(elt(env, 2)) = v0064; // g_dvnames
    v0064 = qvalue(elt(env, 3)); // t
    { popv(1); return onevalue(v0064); }
// error exit handlers
v0019:
    popv(1);
    return nil;
}



// Code for precision1

static LispObject CC_precision1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0088, v0089, v0090;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for precision1");
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
    v0090 = v0001;
    stack[0] = v0000;
// end of prologue
    v0089 = stack[0];
    v0088 = (LispObject)1; // 0
    if (v0089 == v0088) goto v0062;
    v0088 = v0090;
    if (v0088 == nil) goto v0050;
    fn = elt(env, 14); // rmsubs
    v0088 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    goto v0050;

v0050:
    v0088 = qvalue(elt(env, 1)); // !!rdprec
    stack[-3] = v0088;
    v0088 = qvalue(elt(env, 2)); // !*roundbf
    if (v0088 == nil) goto v0060;
    v0088 = stack[0];
    v0089 = v0088;
    goto v0092;

v0092:
    qvalue(elt(env, 1)) = v0089; // !!rdprec
    v0088 = (LispObject)33; // 2
    v0088 = plus2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    qvalue(elt(env, 4)) = v0088; // !:prec!:
    v0088 = qvalue(elt(env, 5)); // !:print!-prec!:
    if (v0088 == nil) goto v0093;
    v0089 = qvalue(elt(env, 5)); // !:print!-prec!:
    v0088 = (LispObject)33; // 2
    v0088 = plus2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    v0088 = (LispObject)lessp2(stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-4];
    if (v0088 == nil) goto v0093;
    v0088 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 5)) = v0088; // !:print!-prec!:
    goto v0093;

v0093:
    v0088 = qvalue(elt(env, 4)); // !:prec!:
    fn = elt(env, 15); // decprec2internal
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    qvalue(elt(env, 7)) = v0088; // !:bprec!:
    stack[-1] = elt(env, 8); // !:rd!:
    stack[0] = (LispObject)17; // 1
    v0089 = qvalue(elt(env, 7)); // !:bprec!:
    v0088 = (LispObject)33; // 2
    v0088 = quot2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    v0088 = negate(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    v0088 = list2star(stack[-1], stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    qvalue(elt(env, 9)) = v0088; // epsqrt!*
    stack[-1] = elt(env, 8); // !:rd!:
    stack[0] = (LispObject)17; // 1
    v0089 = (LispObject)97; // 6
    v0088 = qvalue(elt(env, 7)); // !:bprec!:
    v0088 = difference2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    v0088 = list2star(stack[-1], stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    qvalue(elt(env, 10)) = v0088; // rd!-tolerance!*
    stack[-2] = elt(env, 8); // !:rd!:
    stack[-1] = (LispObject)17; // 1
    stack[0] = (LispObject)33; // 2
    v0089 = (LispObject)97; // 6
    v0088 = qvalue(elt(env, 7)); // !:bprec!:
    v0088 = difference2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    v0088 = times2(stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    v0088 = list2star(stack[-2], stack[-1], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    qvalue(elt(env, 11)) = v0088; // cr!-tolerance!*
    v0089 = qvalue(elt(env, 1)); // !!rdprec
    v0088 = qvalue(elt(env, 12)); // !!flprec
    v0088 = (LispObject)greaterp2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0088 == nil)) goto v0094;
    v0088 = qvalue(elt(env, 2)); // !*roundbf
    goto v0094;

v0094:
    qvalue(elt(env, 13)) = v0088; // !*!*roundbf
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0060:
    v0089 = stack[0];
    v0088 = qvalue(elt(env, 3)); // minprec!#
    fn = elt(env, 16); // max
    v0088 = (*qfn2(fn))(qenv(fn), v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-4];
    v0089 = v0088;
    goto v0092;

v0062:
    v0088 = qvalue(elt(env, 1)); // !!rdprec
    { popv(5); return onevalue(v0088); }
// error exit handlers
v0091:
    popv(5);
    return nil;
}



// Code for texexplode

static LispObject CC_texexplode(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0098, v0025, v0026;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for texexplode");
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
    v0025 = v0000;
// end of prologue
    v0098 = v0025;
    if (v0098 == nil) goto v0062;
    v0098 = v0025;
    if (!(!consp(v0098))) goto v0062;
    v0026 = v0025;
    v0098 = elt(env, 1); // texname
    v0098 = get(v0026, v0098);
    env = stack[0];
    if (!(v0098 == nil)) goto v0099;
    v0098 = v0025;
    if (!symbolp(v0098)) v0098 = nil;
    else { v0098 = qfastgets(v0098);
           if (v0098 != nil) { v0098 = elt(v0098, 7); // class
#ifdef RECORD_GET
             if (v0098 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v0098 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v0098 == SPID_NOPROP) v0098 = nil; }}
#endif
    if (v0098 == nil) goto v0027;
    v0098 = v0025;
    goto v0099;

v0099:
    if (!(v0098 == nil)) goto v0017;
    v0098 = v0025;
    if (is_number(v0098)) goto v0020;
    v0098 = v0025;
    v0098 = Lstringp(nil, v0098);
    env = stack[0];
    if (v0098 == nil) goto v0054;
    v0098 = v0025;
    v0098 = Lexplodec(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    fn = elt(env, 4); // strcollect
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    goto v0017;

v0017:
    v0025 = v0098;
    v0098 = v0025;
    if (v0098 == nil) goto v0100;
    v0098 = v0025;
    if (!(!consp(v0098))) { popv(1); return onevalue(v0025); }
    v0098 = v0025;
    popv(1);
    return ncons(v0098);

v0100:
    v0098 = elt(env, 3); // ! 
    popv(1);
    return ncons(v0098);

v0054:
    v0098 = v0025;
    v0098 = Lexplodec(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    fn = elt(env, 5); // texcollect
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    fn = elt(env, 6); // texexplist
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    goto v0017;

v0020:
    v0098 = v0025;
    v0098 = Lexplode(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    fn = elt(env, 5); // texcollect
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[0];
    goto v0017;

v0027:
    v0098 = qvalue(elt(env, 2)); // nil
    goto v0099;

v0062:
    v0098 = nil;
    goto v0017;
// error exit handlers
v0014:
    popv(1);
    return nil;
}



// Code for simpx1

static LispObject CC_simpx1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0235, v0236, v0237;
    LispObject fn;
    LispObject v0049, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpx1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpx1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-3] = v0049;
    stack[-1] = v0001;
    stack[-4] = v0000;
// end of prologue
    stack[-6] = nil;
    v0236 = stack[-4];
    v0235 = elt(env, 1); // !*minus!*
    if (!consp(v0236)) goto v0064;
    v0236 = qcar(v0236);
    if (!(v0236 == v0235)) goto v0064;
    v0236 = stack[-1];
    v0235 = (LispObject)17; // 1
    if (v0236 == v0235) goto v0045;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0027;

v0027:
    if (!(v0235 == nil)) goto v0090;
    v0236 = stack[-3];
    v0235 = (LispObject)17; // 1
    if (v0236 == v0235) goto v0021;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0085;

v0085:
    if (!(v0235 == nil)) goto v0090;
    v0236 = stack[-1];
    v0235 = (LispObject)17; // 1
    if (v0236 == v0235) goto v0238;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0239;

v0239:
    if (v0235 == nil) goto v0064;
    v0235 = stack[-4];
    v0235 = qcdr(v0235);
    stack[0] = qcar(v0235);
    v0237 = elt(env, 3); // quotient
    v0236 = stack[-1];
    v0235 = stack[-3];
    v0235 = list3(v0237, v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = list2(stack[0], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 20); // negsq
        return (*qfn1(fn))(qenv(fn), v0235);
    }

v0064:
    v0235 = stack[-1];
    if (!(is_number(v0235))) goto v0241;
    v0235 = stack[-3];
    if (!(is_number(v0235))) goto v0241;

v0018:
    v0235 = stack[-1];
    if (is_number(v0235)) goto v0242;
    v0235 = stack[-1];
    if (!consp(v0235)) goto v0243;
    v0235 = stack[-1];
    v0236 = qcar(v0235);
    v0235 = elt(env, 11); // minus
    if (v0236 == v0235) goto v0244;
    v0235 = stack[-1];
    v0236 = qcar(v0235);
    v0235 = elt(env, 12); // plus
    if (v0236 == v0235) goto v0245;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0246;

v0246:
    if (v0235 == nil) goto v0247;
    v0236 = (LispObject)17; // 1
    v0235 = (LispObject)17; // 1
    v0235 = cons(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-5] = v0235;
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    stack[-2] = v0235;
    goto v0248;

v0248:
    v0235 = stack[-2];
    if (v0235 == nil) { LispObject res = stack[-5]; popv(8); return onevalue(res); }
    v0235 = stack[-2];
    v0235 = qcar(v0235);
    stack[-1] = stack[-4];
    stack[0] = elt(env, 3); // quotient
    v0236 = stack[-6];
    if (v0236 == nil) goto v0249;
    v0236 = elt(env, 11); // minus
    v0235 = list2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0236 = v0235;
    goto v0250;

v0250:
    v0235 = stack[-3];
    v0235 = list3(stack[0], v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = list2(stack[-1], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v0236 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = stack[-5];
    fn = elt(env, 21); // multsq
    v0235 = (*qfn2(fn))(qenv(fn), v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-5] = v0235;
    v0235 = stack[-2];
    v0235 = qcdr(v0235);
    stack[-2] = v0235;
    goto v0248;

v0249:
    v0236 = v0235;
    goto v0250;

v0247:
    v0235 = stack[-1];
    v0236 = qcar(v0235);
    v0235 = elt(env, 14); // times
    if (v0236 == v0235) goto v0251;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0252;

v0252:
    if (v0235 == nil) goto v0253;
    v0235 = stack[-3];
    if (is_number(v0235)) goto v0254;
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    stack[-5] = v0235;
    goto v0255;

v0255:
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcdr(v0235);
    v0235 = qcdr(v0235);
    if (v0235 == nil) goto v0256;
    v0236 = elt(env, 14); // times
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcdr(v0235);
    v0235 = cons(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    goto v0257;

v0257:
    stack[-1] = v0235;
    goto v0258;

v0258:
    v0235 = stack[-4];
    if (!(symbolp(v0235))) goto v0259;
    v0236 = stack[-4];
    v0235 = elt(env, 15); // used!*
    v0235 = Lflagp(nil, v0236, v0235);
    env = stack[-7];
    if (!(v0235 == nil)) goto v0259;
    v0235 = stack[-4];
    v0236 = ncons(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = elt(env, 15); // used!*
    v0235 = Lflag(nil, v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    goto v0259;

v0259:
    v0236 = stack[-4];
    v0235 = elt(env, 16); // (minus 1)
    if (equal(v0236, v0235)) goto v0260;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0261;

v0261:
    if (v0235 == nil) goto v0262;
    v0235 = elt(env, 5); // i
    fn = elt(env, 22); // simp
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-4] = v0235;
    v0235 = stack[-6];
    if (v0235 == nil) { LispObject res = stack[-4]; popv(8); return onevalue(res); }
    v0235 = stack[-4];
    {
        popv(8);
        fn = elt(env, 20); // negsq
        return (*qfn1(fn))(qenv(fn), v0235);
    }

v0262:
    stack[0] = elt(env, 4); // expt
    stack[-2] = stack[-4];
    v0236 = stack[-3];
    v0235 = (LispObject)17; // 1
    if (v0236 == v0235) goto v0263;
    v0237 = elt(env, 3); // quotient
    v0236 = stack[-1];
    v0235 = stack[-3];
    v0235 = list3(v0237, v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    goto v0264;

v0264:
    v0235 = list3(stack[0], stack[-2], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-4] = v0235;
    stack[0] = stack[-4];
    v0235 = stack[-6];
    if (v0235 == nil) goto v0265;
    v0235 = stack[-5];
    v0235 = negate(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    goto v0266;

v0266:
    {
        LispObject v0267 = stack[0];
        popv(8);
        fn = elt(env, 23); // mksq
        return (*qfn2(fn))(qenv(fn), v0267, v0235);
    }

v0265:
    v0235 = stack[-5];
    goto v0266;

v0263:
    v0235 = stack[-1];
    goto v0264;

v0260:
    v0236 = stack[-3];
    v0235 = (LispObject)17; // 1
    if (v0236 == v0235) goto v0268;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0261;

v0268:
    v0237 = elt(env, 17); // difference
    v0236 = stack[-1];
    v0235 = elt(env, 18); // (quotient 1 2)
    v0235 = list3(v0237, v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    fn = elt(env, 22); // simp
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = qcar(v0235);
    v0235 = (v0235 == nil ? lisp_true : nil);
    goto v0261;

v0256:
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    goto v0257;

v0254:
    v0236 = stack[-3];
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    v0235 = Lgcd(nil, v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-5] = v0235;
    v0236 = stack[-3];
    v0235 = stack[-5];
    v0235 = quot2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-3] = v0235;
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0236 = qcar(v0235);
    v0235 = stack[-5];
    v0235 = quot2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-5] = v0235;
    goto v0255;

v0253:
    v0235 = stack[-1];
    v0236 = qcar(v0235);
    v0235 = elt(env, 3); // quotient
    if (v0236 == v0235) goto v0269;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0270;

v0270:
    if (v0235 == nil) goto v0271;
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    stack[-3] = v0235;
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    stack[-1] = v0235;
    goto v0018;

v0271:
    v0235 = (LispObject)17; // 1
    stack[-5] = v0235;
    goto v0258;

v0269:
    v0236 = stack[-3];
    v0235 = (LispObject)17; // 1
    if (v0236 == v0235) goto v0272;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0270;

v0272:
    v0235 = qvalue(elt(env, 13)); // !*expandexpt
    goto v0270;

v0251:
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    v0235 = integerp(v0235);
    goto v0252;

v0245:
    v0235 = qvalue(elt(env, 13)); // !*expandexpt
    goto v0246;

v0244:
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    stack[-1] = v0235;
    goto v0063;

v0063:
    v0235 = qvalue(elt(env, 7)); // !*mcd
    if (v0235 == nil) goto v0273;
    v0237 = stack[-4];
    v0236 = stack[-1];
    v0235 = stack[-3];
    v0235 = CC_simpx1(env, 3, v0237, v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 24); // invsq
        return (*qfn1(fn))(qenv(fn), v0235);
    }

v0273:
    v0235 = stack[-6];
    v0235 = (v0235 == nil ? lisp_true : nil);
    stack[-6] = v0235;
    goto v0018;

v0243:
    v0235 = (LispObject)17; // 1
    stack[-5] = v0235;
    goto v0258;

v0242:
    v0235 = stack[-1];
    v0235 = Lminusp(nil, v0235);
    env = stack[-7];
    if (v0235 == nil) goto v0274;
    v0235 = stack[-1];
    v0235 = negate(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-1] = v0235;
    goto v0063;

v0274:
    v0235 = stack[-1];
    v0235 = integerp(v0235);
    if (v0235 == nil) goto v0275;
    v0235 = stack[-3];
    v0235 = integerp(v0235);
    if (v0235 == nil) goto v0276;
    v0235 = stack[-6];
    if (v0235 == nil) goto v0277;
    v0235 = stack[-1];
    v0235 = negate(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-1] = v0235;
    goto v0277;

v0277:
    v0235 = stack[-1];
    stack[-5] = v0235;
    v0235 = qvalue(elt(env, 7)); // !*mcd
    if (v0235 == nil) goto v0278;
    v0235 = stack[-4];
    v0235 = integerp(v0235);
    if (!(v0235 == nil)) goto v0279;
    v0235 = qvalue(elt(env, 8)); // !*notseparate
    if (!(v0235 == nil)) goto v0278;

v0279:
    stack[-2] = stack[-5];
    stack[0] = stack[-3];
    v0236 = stack[-1];
    v0235 = stack[-3];
    v0235 = quot2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-1] = v0235;
    v0235 = times2(stack[0], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = difference2(stack[-2], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-5] = v0235;
    v0236 = stack[-5];
    v0235 = (LispObject)1; // 0
    v0235 = (LispObject)lessp2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    v0235 = v0235 ? lisp_true : nil;
    env = stack[-7];
    if (v0235 == nil) goto v0280;
    v0235 = stack[-1];
    v0235 = sub1(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-1] = v0235;
    v0236 = stack[-5];
    v0235 = stack[-3];
    v0235 = plus2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-5] = v0235;
    goto v0280;

v0280:
    v0236 = stack[-4];
    v0235 = stack[-1];
    v0235 = list2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[0] = v0235;
    v0236 = stack[-5];
    v0235 = (LispObject)1; // 0
    if (v0236 == v0235) { LispObject res = stack[0]; popv(8); return onevalue(res); }
    v0236 = stack[-3];
    v0235 = (LispObject)33; // 2
    if (v0236 == v0235) goto v0281;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0282;

v0282:
    if (v0235 == nil) goto v0283;
    stack[-1] = stack[0];
    v0235 = elt(env, 10); // sqrt
    if (!symbolp(v0235)) stack[0] = nil;
    else { stack[0] = qfastgets(v0235);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 22); // simpfn
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    v0235 = stack[-4];
    v0235 = ncons(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = Lapply1(nil, stack[0], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    fn = elt(env, 21); // multsq
    v0235 = (*qfn2(fn))(qenv(fn), stack[-1], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[0] = v0235;
    v0236 = stack[-5];
    v0235 = (LispObject)1; // 0
    v0235 = (LispObject)lessp2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    v0235 = v0235 ? lisp_true : nil;
    env = stack[-7];
    if (v0235 == nil) goto v0284;
    v0235 = stack[0];
    fn = elt(env, 24); // invsq
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[0] = v0235;
    v0235 = stack[-5];
    v0235 = negate(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    stack[-5] = v0235;
    goto v0284;

v0284:
    v0236 = stack[0];
    v0235 = stack[-5];
    {
        popv(8);
        fn = elt(env, 25); // exptsq
        return (*qfn2(fn))(qenv(fn), v0236, v0235);
    }

v0283:
    v0235 = stack[-4];
    fn = elt(env, 26); // simp!*
    v0236 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = stack[-3];
    fn = elt(env, 27); // simprad
    v0236 = (*qfn2(fn))(qenv(fn), v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = stack[-5];
    fn = elt(env, 25); // exptsq
    v0235 = (*qfn2(fn))(qenv(fn), v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    {
        LispObject v0285 = stack[0];
        popv(8);
        fn = elt(env, 21); // multsq
        return (*qfn2(fn))(qenv(fn), v0285, v0235);
    }

v0281:
    v0235 = qvalue(elt(env, 9)); // !*keepsqrts
    goto v0282;

v0278:
    v0235 = (LispObject)1; // 0
    stack[-1] = v0235;
    goto v0280;

v0276:
    v0235 = stack[-1];
    stack[-5] = v0235;
    v0235 = (LispObject)17; // 1
    stack[-1] = v0235;
    goto v0258;

v0275:
    v0235 = (LispObject)17; // 1
    stack[-5] = v0235;
    goto v0258;

v0241:
    v0236 = qvalue(elt(env, 6)); // frlis!*
    v0235 = stack[-1];
    fn = elt(env, 28); // smemqlp
    v0235 = (*qfn2(fn))(qenv(fn), v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    if (!(v0235 == nil)) goto v0286;
    v0236 = qvalue(elt(env, 6)); // frlis!*
    v0235 = stack[-3];
    fn = elt(env, 28); // smemqlp
    v0235 = (*qfn2(fn))(qenv(fn), v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    if (v0235 == nil) goto v0018;
    else goto v0286;

v0286:
    stack[0] = elt(env, 4); // expt
    stack[-2] = stack[-4];
    v0236 = stack[-3];
    v0235 = (LispObject)17; // 1
    if (v0236 == v0235) goto v0287;
    v0237 = elt(env, 3); // quotient
    v0236 = stack[-1];
    v0235 = stack[-3];
    v0235 = list3(v0237, v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    goto v0288;

v0288:
    v0236 = list3(stack[0], stack[-2], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = (LispObject)17; // 1
    {
        popv(8);
        fn = elt(env, 23); // mksq
        return (*qfn2(fn))(qenv(fn), v0236, v0235);
    }

v0287:
    v0235 = stack[-1];
    goto v0288;

v0238:
    v0235 = stack[-3];
    v0235 = integerp(v0235);
    goto v0239;

v0090:
    stack[-6] = elt(env, 4); // expt
    stack[-5] = elt(env, 5); // i
    stack[-2] = elt(env, 3); // quotient
    stack[0] = (LispObject)17; // 1
    v0236 = stack[-3];
    v0235 = (LispObject)33; // 2
    v0235 = quot2(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = list3(stack[-2], stack[0], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = list3(stack[-6], stack[-5], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    fn = elt(env, 22); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = stack[-4];
    v0235 = qcdr(v0235);
    stack[-2] = qcar(v0235);
    v0237 = elt(env, 3); // quotient
    v0236 = stack[-1];
    v0235 = stack[-3];
    v0235 = list3(v0237, v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = list2(stack[-2], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    {
        LispObject v0289 = stack[0];
        popv(8);
        fn = elt(env, 21); // multsq
        return (*qfn2(fn))(qenv(fn), v0289, v0235);
    }

v0021:
    v0236 = stack[-1];
    v0235 = elt(env, 3); // quotient
    if (!consp(v0236)) goto v0094;
    v0236 = qcar(v0236);
    if (!(v0236 == v0235)) goto v0094;
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0236 = qcar(v0235);
    v0235 = (LispObject)17; // 1
    if (v0236 == v0235) goto v0290;
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0085;

v0290:
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    v0235 = integerp(v0235);
    if (v0235 == nil) goto v0291;
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    v0235 = qcdr(v0235);
    v0236 = qcar(v0235);
    v0235 = (LispObject)33; // 2
    v0236 = Cremainder(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = (LispObject)1; // 0
    v0235 = (v0236 == v0235 ? lisp_true : nil);
    goto v0085;

v0291:
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0085;

v0094:
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0085;

v0045:
    v0235 = stack[-3];
    v0235 = integerp(v0235);
    if (v0235 == nil) goto v0047;
    v0236 = stack[-3];
    v0235 = (LispObject)33; // 2
    v0236 = Cremainder(v0236, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-7];
    v0235 = (LispObject)1; // 0
    v0235 = (v0236 == v0235 ? lisp_true : nil);
    goto v0027;

v0047:
    v0235 = qvalue(elt(env, 2)); // nil
    goto v0027;
// error exit handlers
v0240:
    popv(8);
    return nil;
}



// Code for makecoeffpairs1

static LispObject CC_makecoeffpairs1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0322, v0323, v0288, v0324;
    LispObject fn;
    LispObject v0004, v0049, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makecoeffpairs1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0049,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0049,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-10] = v0004;
    stack[-11] = v0049;
    stack[-12] = v0001;
    stack[-13] = v0000;
// end of prologue
    v0322 = stack[-12];
    if (v0322 == nil) goto v0053;
    v0322 = stack[-13];
    v0324 = qcdr(v0322);
    v0322 = stack[-12];
    v0288 = qcdr(v0322);
    v0322 = stack[-11];
    v0323 = qcdr(v0322);
    v0322 = stack[-10];
    v0322 = qcdr(v0322);
    v0322 = CC_makecoeffpairs1(env, 4, v0324, v0288, v0323, v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    stack[-14] = v0322;
    goto v0041;

v0041:
    v0322 = stack[-14];
    if (v0322 == nil) goto v0060;
    v0322 = stack[-14];
    v0322 = qcar(v0322);
    stack[-6] = v0322;
    v0322 = stack[-13];
    stack[-2] = qcar(v0322);
    v0322 = stack[-12];
    stack[-1] = qcar(v0322);
    v0322 = stack[-11];
    stack[0] = qcar(v0322);
    v0322 = stack[-10];
    v0322 = qcar(v0322);
    fn = elt(env, 3); // tayexp!-minus
    v0322 = (*qfn1(fn))(qenv(fn), v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    fn = elt(env, 4); // makecoeffpairshom
    v0322 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    stack[-5] = v0322;
    v0322 = stack[-5];
    if (v0322 == nil) goto v0098;
    v0322 = stack[-5];
    v0322 = qcar(v0322);
    v0323 = v0322;
    v0322 = v0323;
    stack[-1] = qcar(v0322);
    v0322 = stack[-6];
    stack[0] = qcar(v0322);
    v0322 = v0323;
    v0323 = qcdr(v0322);
    v0322 = stack[-6];
    v0322 = qcdr(v0322);
    v0322 = cons(v0323, v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = acons(stack[-1], stack[0], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = ncons(v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    stack[-3] = v0322;
    stack[-4] = v0322;
    goto v0054;

v0054:
    v0322 = stack[-5];
    v0322 = qcdr(v0322);
    stack[-5] = v0322;
    v0322 = stack[-5];
    if (v0322 == nil) goto v0078;
    stack[-2] = stack[-3];
    v0322 = stack[-5];
    v0322 = qcar(v0322);
    v0323 = v0322;
    v0322 = v0323;
    stack[-1] = qcar(v0322);
    v0322 = stack[-6];
    stack[0] = qcar(v0322);
    v0322 = v0323;
    v0323 = qcdr(v0322);
    v0322 = stack[-6];
    v0322 = qcdr(v0322);
    v0322 = cons(v0323, v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = acons(stack[-1], stack[0], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = ncons(v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = Lrplacd(nil, stack[-2], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = stack[-3];
    v0322 = qcdr(v0322);
    stack[-3] = v0322;
    goto v0054;

v0078:
    v0322 = stack[-4];
    goto v0326;

v0326:
    stack[-9] = v0322;
    v0322 = stack[-9];
    fn = elt(env, 5); // lastpair
    v0322 = (*qfn1(fn))(qenv(fn), v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    stack[-8] = v0322;
    v0322 = stack[-14];
    v0322 = qcdr(v0322);
    stack[-14] = v0322;
    v0322 = stack[-8];
    if (!consp(v0322)) goto v0041;
    else goto v0050;

v0050:
    v0322 = stack[-14];
    if (v0322 == nil) { LispObject res = stack[-9]; popv(16); return onevalue(res); }
    stack[-7] = stack[-8];
    v0322 = stack[-14];
    v0322 = qcar(v0322);
    stack[-6] = v0322;
    v0322 = stack[-13];
    stack[-2] = qcar(v0322);
    v0322 = stack[-12];
    stack[-1] = qcar(v0322);
    v0322 = stack[-11];
    stack[0] = qcar(v0322);
    v0322 = stack[-10];
    v0322 = qcar(v0322);
    fn = elt(env, 3); // tayexp!-minus
    v0322 = (*qfn1(fn))(qenv(fn), v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    fn = elt(env, 4); // makecoeffpairshom
    v0322 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    stack[-5] = v0322;
    v0322 = stack[-5];
    if (v0322 == nil) goto v0327;
    v0322 = stack[-5];
    v0322 = qcar(v0322);
    v0323 = v0322;
    v0322 = v0323;
    stack[-1] = qcar(v0322);
    v0322 = stack[-6];
    stack[0] = qcar(v0322);
    v0322 = v0323;
    v0323 = qcdr(v0322);
    v0322 = stack[-6];
    v0322 = qcdr(v0322);
    v0322 = cons(v0323, v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = acons(stack[-1], stack[0], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = ncons(v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    stack[-3] = v0322;
    stack[-4] = v0322;
    goto v0216;

v0216:
    v0322 = stack[-5];
    v0322 = qcdr(v0322);
    stack[-5] = v0322;
    v0322 = stack[-5];
    if (v0322 == nil) goto v0328;
    stack[-2] = stack[-3];
    v0322 = stack[-5];
    v0322 = qcar(v0322);
    v0323 = v0322;
    v0322 = v0323;
    stack[-1] = qcar(v0322);
    v0322 = stack[-6];
    stack[0] = qcar(v0322);
    v0322 = v0323;
    v0323 = qcdr(v0322);
    v0322 = stack[-6];
    v0322 = qcdr(v0322);
    v0322 = cons(v0323, v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = acons(stack[-1], stack[0], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = ncons(v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = Lrplacd(nil, stack[-2], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = stack[-3];
    v0322 = qcdr(v0322);
    stack[-3] = v0322;
    goto v0216;

v0328:
    v0322 = stack[-4];
    goto v0329;

v0329:
    v0322 = Lrplacd(nil, stack[-7], v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    v0322 = stack[-8];
    fn = elt(env, 5); // lastpair
    v0322 = (*qfn1(fn))(qenv(fn), v0322);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-15];
    stack[-8] = v0322;
    v0322 = stack[-14];
    v0322 = qcdr(v0322);
    stack[-14] = v0322;
    goto v0050;

v0327:
    v0322 = qvalue(elt(env, 2)); // nil
    goto v0329;

v0098:
    v0322 = qvalue(elt(env, 2)); // nil
    goto v0326;

v0060:
    v0322 = qvalue(elt(env, 2)); // nil
    { popv(16); return onevalue(v0322); }

v0053:
    v0322 = elt(env, 1); // ((nil))
    { popv(16); return onevalue(v0322); }
// error exit handlers
v0325:
    popv(16);
    return nil;
}



// Code for pasf_qff2ivl

static LispObject CC_pasf_qff2ivl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0087;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_qff2ivl");
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
    v0087 = stack[0];
    fn = elt(env, 2); // pasf_uprap
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    if (v0087 == nil) goto v0330;
    v0087 = elt(env, 1); // "pasf_qff2ivl : uniform Presburger arithmetic formula in input"
    v0087 = ncons(v0087);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(qenv(fn), v0087);
    }

v0330:
    v0087 = stack[0];
    fn = elt(env, 4); // pasf_dnf
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); // pasf_qff2ivl1
        return (*qfn1(fn))(qenv(fn), v0087);
    }
// error exit handlers
v0041:
    popv(2);
    return nil;
}



// Code for aex_neg

static LispObject CC_aex_neg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_neg");
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
    v0058 = stack[0];
    fn = elt(env, 1); // aex_ex
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-2];
    fn = elt(env, 2); // negsq
    stack[-1] = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-2];
    v0058 = stack[0];
    fn = elt(env, 3); // aex_ctx
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-2];
    {
        LispObject v0099 = stack[-1];
        popv(3);
        fn = elt(env, 4); // aex_mk
        return (*qfn2(fn))(qenv(fn), v0099, v0058);
    }
// error exit handlers
v0087:
    popv(3);
    return nil;
}



// Code for parseml

static LispObject CC_parseml(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0028, v0029;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "parseml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for parseml");
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
    v0028 = qvalue(elt(env, 1)); // nil
    stack[0] = v0028;
    v0028 = (LispObject)513; // 32
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    fn = elt(env, 11); // list2string
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0028 = Lintern(nil, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0028; // space
    v0028 = (LispObject)1; // 0
    qvalue(elt(env, 3)) = v0028; // count
    v0028 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0028; // ch
    v0028 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 5)) = v0028; // temp2
    fn = elt(env, 12); // lex
    v0028 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0029 = qvalue(elt(env, 6)); // char
    v0028 = elt(env, 7); // (m a t h)
    if (equal(v0029, v0028)) goto v0099;
    v0029 = elt(env, 8); // "<math>"
    v0028 = (LispObject)33; // 2
    fn = elt(env, 13); // errorml
    v0028 = (*qfn2(fn))(qenv(fn), v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    goto v0087;

v0087:
    fn = elt(env, 12); // lex
    v0028 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0029 = qvalue(elt(env, 6)); // char
    v0028 = elt(env, 9); // (!/ m a t h)
    if (equal(v0029, v0028)) goto v0060;
    v0029 = elt(env, 10); // "</math>"
    v0028 = (LispObject)305; // 19
    fn = elt(env, 13); // errorml
    v0028 = (*qfn2(fn))(qenv(fn), v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    goto v0020;

v0020:
    v0028 = stack[0];
    {
        popv(2);
        fn = elt(env, 14); // aeval
        return (*qfn1(fn))(qenv(fn), v0028);
    }

v0060:
    v0028 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    goto v0020;

v0099:
    fn = elt(env, 15); // mathml
    v0028 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    stack[0] = v0028;
    goto v0087;
// error exit handlers
v0044:
    popv(2);
    return nil;
}



// Code for tidysqrt

static LispObject CC_tidysqrt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0056, v0059;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tidysqrt");
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
    v0056 = stack[0];
    v0056 = qcar(v0056);
    fn = elt(env, 2); // tidysqrtf
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    stack[-1] = v0056;
    v0056 = stack[-1];
    if (v0056 == nil) goto v0036;
    v0056 = stack[0];
    v0056 = qcdr(v0056);
    fn = elt(env, 2); // tidysqrtf
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    stack[0] = stack[-1];
    fn = elt(env, 3); // invsq
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    {
        LispObject v0020 = stack[0];
        popv(3);
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(qenv(fn), v0020, v0056);
    }

v0036:
    v0059 = qvalue(elt(env, 1)); // nil
    v0056 = (LispObject)17; // 1
    popv(3);
    return cons(v0059, v0056);
// error exit handlers
v0048:
    popv(3);
    return nil;
}



// Code for getvariables

static LispObject CC_getvariables(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getvariables");
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
    stack[0] = qcar(v0050);
    v0050 = v0051;
    v0051 = qcdr(v0050);
    v0050 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // varsinsf
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-1];
    {
        LispObject v0013 = stack[0];
        popv(2);
        fn = elt(env, 2); // varsinsf
        return (*qfn2(fn))(qenv(fn), v0013, v0050);
    }
// error exit handlers
v0012:
    popv(2);
    return nil;
}



// Code for row_dim

static LispObject CC_row_dim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for row_dim");
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
    v0057 = qvalue(elt(env, 1)); // !*fast_la
    if (v0057 == nil) goto v0063;
    v0057 = qvalue(elt(env, 2)); // nil
    goto v0018;

v0018:
    if (v0057 == nil) goto v0024;
    v0057 = elt(env, 3); // "Error in row_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-1];
    goto v0024;

v0024:
    v0057 = stack[0];
    fn = elt(env, 5); // size_of_matrix
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    v0057 = qcar(v0057);
    { popv(2); return onevalue(v0057); }

v0063:
    v0057 = stack[0];
    fn = elt(env, 6); // matrixp
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-1];
    v0057 = (v0057 == nil ? lisp_true : nil);
    goto v0018;
// error exit handlers
v0097:
    popv(2);
    return nil;
}



// Code for multsqpf

static LispObject CC_multsqpf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0313, v0326;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multsqpf");
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
    goto v0017;

v0017:
    v0313 = stack[-1];
    if (v0313 == nil) goto v0058;
    v0313 = stack[-2];
    v0313 = qcar(v0313);
    v0313 = (v0313 == nil ? lisp_true : nil);
    goto v0064;

v0064:
    if (v0313 == nil) goto v0095;
    v0313 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0313);
    }

v0095:
    v0313 = stack[-1];
    v0313 = qcar(v0313);
    stack[0] = qcar(v0313);
    v0326 = stack[-2];
    v0313 = stack[-1];
    v0313 = qcar(v0313);
    v0313 = qcdr(v0313);
    fn = elt(env, 3); // multsq
    v0326 = (*qfn2(fn))(qenv(fn), v0326, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    v0313 = stack[-3];
    v0313 = acons(stack[0], v0326, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    stack[-3] = v0313;
    v0313 = stack[-1];
    v0313 = qcdr(v0313);
    stack[-1] = v0313;
    goto v0017;

v0058:
    v0313 = qvalue(elt(env, 1)); // t
    goto v0064;
// error exit handlers
v0332:
    popv(5);
    return nil;
}



// Code for gffdot

static LispObject CC_gffdot(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0027, v0045;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gffdot");
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
    v0027 = stack[-1];
    v0045 = qcar(v0027);
    v0027 = stack[0];
    v0027 = qcar(v0027);
    stack[-2] = times2(v0045, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-3];
    v0027 = stack[-1];
    v0045 = qcdr(v0027);
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    v0027 = times2(v0045, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    {
        LispObject v0059 = stack[-2];
        popv(4);
        return plus2(v0059, v0027);
    }
// error exit handlers
v0056:
    popv(4);
    return nil;
}



// Code for !*kp2q

static LispObject CC_Hkp2q(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0032, v0030;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *kp2q");
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
    v0030 = stack[0];
    v0032 = (LispObject)1; // 0
    v0032 = (LispObject)greaterp2(v0030, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0032 = v0032 ? lisp_true : nil;
    env = stack[-2];
    if (v0032 == nil) goto v0017;
    v0030 = stack[-1];
    v0032 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); // mksq
        return (*qfn2(fn))(qenv(fn), v0030, v0032);
    }

v0017:
    v0032 = stack[0];
    v0032 = (LispObject)zerop(v0032);
    v0032 = v0032 ? lisp_true : nil;
    env = stack[-2];
    if (v0032 == nil) goto v0060;
    v0030 = (LispObject)17; // 1
    v0032 = (LispObject)17; // 1
    popv(3);
    return cons(v0030, v0032);

v0060:
    v0032 = stack[0];
    v0032 = negate(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    fn = elt(env, 2); // mksq
    v0032 = (*qfn2(fn))(qenv(fn), stack[-1], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    stack[-1] = v0032;
    v0032 = qcar(v0032);
    if (v0032 == nil) goto v0059;
    v0032 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); // revpr
        return (*qfn1(fn))(qenv(fn), v0032);
    }

v0059:
    v0032 = elt(env, 1); // "Zero divisor"
    {
        popv(3);
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(qenv(fn), v0032);
    }
// error exit handlers
v0043:
    popv(3);
    return nil;
}



// Code for physop!*sq

static LispObject CC_physopHsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physop*sq");
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
    v0041 = v0000;
// end of prologue
    v0041 = qcar(v0041);
    fn = elt(env, 3); // !*q2a
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[0];
    fn = elt(env, 4); // !*collectphysops
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[0];
    if (v0041 == nil) goto v0330;
    v0041 = elt(env, 2); // physop
    { popv(1); return onevalue(v0041); }

v0330:
    v0041 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0041); }
// error exit handlers
v0050:
    popv(1);
    return nil;
}



// Code for store_edges

static LispObject CC_store_edges(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0100, v0084;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for store_edges");
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
    v0100 = v0000;
// end of prologue
    stack[-3] = v0100;
    v0100 = stack[-3];
    if (v0100 == nil) goto v0330;
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    v0084 = v0100;
    v0084 = qcar(v0084);
    v0100 = qcdr(v0100);
    v0100 = cons(v0084, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0100 = ncons(v0100);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    stack[-1] = v0100;
    stack[-2] = v0100;
    goto v0053;

v0053:
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    stack[-3] = v0100;
    v0100 = stack[-3];
    if (v0100 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    v0084 = v0100;
    v0084 = qcar(v0084);
    v0100 = qcdr(v0100);
    v0100 = cons(v0084, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0100 = ncons(v0100);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0100 = Lrplacd(nil, stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0100 = stack[-1];
    v0100 = qcdr(v0100);
    stack[-1] = v0100;
    goto v0053;

v0330:
    v0100 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0100); }
// error exit handlers
v0320:
    popv(5);
    return nil;
}



// Code for lchk

static LispObject CC_lchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0029, v0321;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lchk");
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
    v0029 = stack[0];
    if (v0029 == nil) goto v0064;
    v0029 = stack[0];
    v0029 = qcar(v0029);
    v0029 = (consp(v0029) ? nil : lisp_true);
    goto v0330;

v0330:
    if (v0029 == nil) goto v0053;
    v0029 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0029); }

v0053:
    v0029 = stack[0];
    v0029 = qcar(v0029);
    v0029 = Llength(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    stack[-1] = v0029;
    goto v0095;

v0095:
    v0029 = stack[0];
    v0029 = qcdr(v0029);
    stack[0] = v0029;
    v0029 = stack[0];
    if (v0029 == nil) goto v0010;
    v0029 = stack[0];
    v0029 = qcar(v0029);
    if (!consp(v0029)) goto v0034;
    v0029 = stack[0];
    v0029 = qcar(v0029);
    v0321 = Llength(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    v0029 = stack[-1];
    v0029 = Lneq(nil, v0321, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    goto v0059;

v0059:
    if (v0029 == nil) goto v0095;
    v0029 = stack[0];
    v0029 = (v0029 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0029); }

v0034:
    v0029 = qvalue(elt(env, 1)); // t
    goto v0059;

v0010:
    v0029 = qvalue(elt(env, 1)); // t
    goto v0059;

v0064:
    v0029 = qvalue(elt(env, 1)); // t
    goto v0330;
// error exit handlers
v0007:
    popv(3);
    return nil;
}



// Code for compactf1

static LispObject CC_compactf1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0020, v0060, v0047, v0046, v0035;
    LispObject fn;
    LispObject v0004, v0049, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "compactf1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compactf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0049,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0049,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
    stack[-1] = v0049;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0060 = stack[-1];
    v0020 = stack[0];
    fn = elt(env, 1); // intersection
    v0020 = (*qfn2(fn))(qenv(fn), v0060, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-4];
    v0060 = v0020;
    if (v0060 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0035 = stack[-3];
    v0046 = stack[-2];
    v0047 = stack[-1];
    v0060 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); // compactf11
        return (*qfnn(fn))(qenv(fn), 5, v0035, v0046, v0047, v0060, v0020);
    }
// error exit handlers
v0317:
    popv(5);
    return nil;
}



// Code for !*v2j

static LispObject CC_Hv2j(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0048, v0020, v0060;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *v2j");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0060 = v0000;
// end of prologue
    v0020 = qvalue(elt(env, 1)); // ordering
    v0048 = elt(env, 2); // lex
    if (v0020 == v0048) goto v0019;
    stack[0] = (LispObject)17; // 1
    v0020 = v0060;
    v0048 = qvalue(elt(env, 3)); // varlist!*
    fn = elt(env, 4); // sub01
    v0048 = (*qfn2(fn))(qenv(fn), v0020, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    {
        LispObject v0035 = stack[0];
        popv(1);
        return cons(v0035, v0048);
    }

v0019:
    v0020 = v0060;
    v0048 = qvalue(elt(env, 3)); // varlist!*
    {
        popv(1);
        fn = elt(env, 4); // sub01
        return (*qfn2(fn))(qenv(fn), v0020, v0048);
    }
// error exit handlers
v0046:
    popv(1);
    return nil;
}



// Code for rl_simplb

static LispObject CC_rl_simplb(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0041, v0050;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simplb");
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
    v0041 = v0001;
    v0050 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_simplb!*
    v0041 = list2(v0050, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-1];
    {
        LispObject v0012 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0012, v0041);
    }
// error exit handlers
v0234:
    popv(2);
    return nil;
}



// Code for ps!:mkpow

static LispObject CC_psTmkpow(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0320, v0007, v0085, v0005;
    LispObject v0049, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:mkpow");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:mkpow");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0049;
    v0085 = v0001;
    v0005 = v0000;
// end of prologue
    v0007 = v0085;
    v0320 = (LispObject)1; // 0
    if (v0007 == v0320) goto v0017;
    v0007 = v0085;
    v0320 = (LispObject)17; // 1
    if (v0007 == v0320) goto v0234;
    v0320 = elt(env, 1); // expt
    v0007 = v0005;
    v0320 = list3(v0320, v0007, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    goto v0051;

v0051:
    v0007 = stack[0];
    if (v0007 == nil) goto v0028;
    v0085 = elt(env, 2); // quotient
    v0007 = (LispObject)17; // 1
    v0320 = list3(v0085, v0007, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    popv(2);
    return ncons(v0320);

v0028:
    popv(2);
    return ncons(v0320);

v0234:
    v0320 = v0005;
    goto v0051;

v0017:
    v0320 = (LispObject)17; // 1
    popv(2);
    return ncons(v0320);
// error exit handlers
v0006:
    popv(2);
    return nil;
}



// Code for varsinsf

static LispObject CC_varsinsf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0320, v0007;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for varsinsf");
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
    v0320 = v0001;
    stack[-1] = v0000;
// end of prologue
    v0007 = stack[-1];
    if (!consp(v0007)) goto v0018;
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0007 = (consp(v0007) ? nil : lisp_true);
    goto v0062;

v0062:
    if (!(v0007 == nil)) { popv(4); return onevalue(v0320); }

v0096:
    v0007 = stack[-1];
    if (!consp(v0007)) goto v0092;
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0007 = (consp(v0007) ? nil : lisp_true);
    goto v0086;

v0086:
    if (!(v0007 == nil)) { popv(4); return onevalue(v0320); }
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    stack[-2] = qcdr(v0007);
    stack[0] = v0320;
    v0320 = stack[-1];
    v0320 = qcar(v0320);
    v0320 = qcar(v0320);
    v0320 = qcar(v0320);
    v0320 = ncons(v0320);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    fn = elt(env, 3); // union
    v0320 = (*qfn2(fn))(qenv(fn), stack[0], v0320);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0320 = CC_varsinsf(env, stack[-2], v0320);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    stack[-1] = v0007;
    goto v0096;

v0092:
    v0007 = qvalue(elt(env, 1)); // t
    goto v0086;

v0018:
    v0007 = qvalue(elt(env, 1)); // t
    goto v0062;
// error exit handlers
v0006:
    popv(4);
    return nil;
}



// Code for dip!-nc!-ev!-prod

static LispObject CC_dipKncKevKprod(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056, v0059, v0010;
    LispObject fn;
    LispObject v0004, v0049, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dip-nc-ev-prod");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip-nc-ev-prod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0049,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0049,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0055 = v0004;
    v0056 = v0049;
    v0059 = v0001;
    v0010 = v0000;
// end of prologue
    stack[-2] = v0059;
    stack[-1] = (LispObject)17; // 1
    stack[0] = v0055;
    v0055 = v0010;
    fn = elt(env, 2); // bcprod
    v0056 = (*qfn2(fn))(qenv(fn), v0055, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0055 = qvalue(elt(env, 1)); // nil
    v0055 = list2star(stack[0], v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    {
        LispObject v0047 = stack[-2];
        LispObject v0046 = stack[-1];
        popv(4);
        fn = elt(env, 3); // dip!-nc!-ev!-prod1
        return (*qfnn(fn))(qenv(fn), 3, v0047, v0046, v0055);
    }
// error exit handlers
v0060:
    popv(4);
    return nil;
}



// Code for minprec

static LispObject CC_minprec(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0063;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minprec");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minprec");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// end of prologue
    v0063 = qvalue(elt(env, 1)); // !*bftag
    if (v0063 == nil) goto v0053;
    v0063 = qvalue(elt(env, 2)); // !:prec!:
    return onevalue(v0063);

v0053:
    v0063 = qvalue(elt(env, 3)); // !!nfpd
    return onevalue(v0063);
}



// Code for acmemb

static LispObject CC_acmemb(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0027, v0045;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for acmemb");
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

v0024:
    v0027 = stack[0];
    if (v0027 == nil) goto v0062;
    v0045 = stack[-1];
    v0027 = stack[0];
    v0027 = qcar(v0027);
    fn = elt(env, 2); // aceq
    v0027 = (*qfn2(fn))(qenv(fn), v0045, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    if (v0027 == nil) goto v0096;
    v0027 = stack[0];
    v0027 = qcar(v0027);
    { popv(3); return onevalue(v0027); }

v0096:
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    stack[0] = v0027;
    goto v0024;

v0062:
    v0027 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0027); }
// error exit handlers
v0055:
    popv(3);
    return nil;
}



// Code for mo_from_ei

static LispObject CC_mo_from_ei(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061, v0027, v0045;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_from_ei");
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
    v0045 = v0000;
// end of prologue
    v0027 = v0045;
    v0061 = (LispObject)1; // 0
    if (v0027 == v0061) goto v0033;
    v0061 = v0045;
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    stack[0] = v0061;
    fn = elt(env, 1); // mo!=deglist
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    {
        LispObject v0055 = stack[0];
        popv(2);
        return cons(v0055, v0061);
    }

v0033:
    {
        popv(2);
        fn = elt(env, 2); // mo_zero
        return (*qfnn(fn))(qenv(fn), 0);
    }
// error exit handlers
v0092:
    popv(2);
    return nil;
}



// Code for general!-negate!-term

static LispObject CC_generalKnegateKterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058, v0019;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-negate-term");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0019 = v0000;
// end of prologue
    v0058 = v0019;
    stack[0] = qcar(v0058);
    v0058 = v0019;
    v0058 = qcdr(v0058);
    fn = elt(env, 1); // general!-minus!-mod!-p
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    {
        LispObject v0099 = stack[0];
        popv(1);
        return cons(v0099, v0058);
    }
// error exit handlers
v0087:
    popv(1);
    return nil;
}



// Code for addinds

static LispObject CC_addinds(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0320, v0007;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addinds");
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
    goto v0017;

v0017:
    v0320 = stack[-1];
    if (v0320 == nil) goto v0018;
    v0320 = stack[0];
    if (v0320 == nil) goto v0056;
    v0320 = stack[-1];
    v0007 = qcar(v0320);
    v0320 = stack[0];
    v0320 = qcar(v0320);
    v0320 = qcar(v0320);
    v0007 = plus2(v0007, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0320 = stack[-2];
    v0320 = cons(v0007, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    stack[-2] = v0320;
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    stack[-1] = v0320;
    v0320 = stack[0];
    v0320 = qcdr(v0320);
    stack[0] = v0320;
    goto v0017;

v0056:
    stack[0] = stack[-2];
    v0320 = elt(env, 2); // "Powu too long"
    fn = elt(env, 3); // interr
    v0320 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    {
        LispObject v0003 = stack[0];
        popv(4);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0003, v0320);
    }

v0018:
    v0320 = stack[0];
    if (v0320 == nil) goto v0019;
    stack[0] = stack[-2];
    v0320 = elt(env, 1); // "Powrhs too long"
    fn = elt(env, 3); // interr
    v0320 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    {
        LispObject v0333 = stack[0];
        popv(4);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0333, v0320);
    }

v0019:
    v0320 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); // nreverse
        return (*qfn1(fn))(qenv(fn), v0320);
    }
// error exit handlers
v0006:
    popv(4);
    return nil;
}



// Code for available!*p

static LispObject CC_availableHp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for available*p");
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
    if (symbolp(v0050)) goto v0064;
    v0050 = elt(env, 1); // "this is no group identifier"
    fn = elt(env, 3); // rederr
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-1];
    goto v0064;

v0064:
    v0050 = stack[0];
    v0051 = elt(env, 2); // available
        popv(2);
        return Lflagp(nil, v0050, v0051);
// error exit handlers
v0012:
    popv(2);
    return nil;
}



// Code for ofsf_simpat

static LispObject CC_ofsf_simpat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0197, v0350, v0287;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_simpat");
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
    v0197 = stack[-2];
    v0197 = qcar(v0197);
    stack[-3] = v0197;
    v0197 = stack[-2];
    v0197 = qcdr(v0197);
    v0197 = qcar(v0197);
    fn = elt(env, 11); // simp
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    stack[-1] = v0197;
    v0197 = qvalue(elt(env, 1)); // !*rlnzden
    if (!(v0197 == nil)) goto v0087;
    v0197 = qvalue(elt(env, 2)); // !*rlposden
    if (!(v0197 == nil)) goto v0087;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    if (!consp(v0197)) goto v0095;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    v0197 = qcar(v0197);
    v0197 = (consp(v0197) ? nil : lisp_true);
    goto v0097;

v0097:
    if (!(v0197 == nil)) goto v0087;
    v0350 = stack[-2];
    v0197 = elt(env, 4); // "atomic formula"
    fn = elt(env, 12); // typerr
    v0197 = (*qfn2(fn))(qenv(fn), v0350, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    goto v0087;

v0087:
    v0197 = stack[-2];
    v0197 = qcdr(v0197);
    v0197 = qcdr(v0197);
    v0197 = qcar(v0197);
    fn = elt(env, 11); // simp
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    stack[0] = v0197;
    v0197 = qvalue(elt(env, 1)); // !*rlnzden
    if (!(v0197 == nil)) goto v0023;
    v0197 = qvalue(elt(env, 2)); // !*rlposden
    if (!(v0197 == nil)) goto v0023;
    v0197 = stack[0];
    v0197 = qcdr(v0197);
    if (!consp(v0197)) goto v0029;
    v0197 = stack[0];
    v0197 = qcdr(v0197);
    v0197 = qcar(v0197);
    v0197 = (consp(v0197) ? nil : lisp_true);
    goto v0028;

v0028:
    if (!(v0197 == nil)) goto v0023;
    v0350 = stack[-2];
    v0197 = elt(env, 4); // "atomic formula"
    fn = elt(env, 12); // typerr
    v0197 = (*qfn2(fn))(qenv(fn), v0350, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    goto v0023;

v0023:
    v0197 = stack[0];
    fn = elt(env, 13); // negsq
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    fn = elt(env, 14); // addsq
    v0197 = (*qfn2(fn))(qenv(fn), stack[-1], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    stack[-1] = v0197;
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    v0350 = v0197;
    v0197 = qvalue(elt(env, 2)); // !*rlposden
    if (v0197 == nil) goto v0319;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    if (!consp(v0197)) goto v0076;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    v0197 = qcar(v0197);
    v0197 = (consp(v0197) ? nil : lisp_true);
    goto v0075;

v0075:
    if (!(v0197 == nil)) goto v0319;
    v0287 = stack[-3];
    v0197 = qvalue(elt(env, 5)); // nil
    v0197 = list3(v0287, v0350, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    stack[0] = v0197;
    v0197 = qvalue(elt(env, 6)); // !*rladdcond
    if (v0197 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0350 = stack[-3];
    v0197 = elt(env, 7); // (lessp leq greaterp geq)
    v0197 = Lmemq(nil, v0350, v0197);
    if (v0197 == nil) goto v0227;
    stack[-2] = elt(env, 8); // and
    v0287 = elt(env, 9); // greaterp
    v0197 = stack[-1];
    v0350 = qcdr(v0197);
    v0197 = qvalue(elt(env, 5)); // nil
    stack[-1] = list3(v0287, v0350, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    v0197 = stack[0];
    v0197 = ncons(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    v0197 = list2star(stack[-2], stack[-1], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    goto v0233;

v0233:
    stack[0] = v0197;
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0227:
    stack[-2] = elt(env, 8); // and
    v0287 = elt(env, 10); // neq
    v0197 = stack[-1];
    v0350 = qcdr(v0197);
    v0197 = qvalue(elt(env, 5)); // nil
    stack[-1] = list3(v0287, v0350, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    v0197 = stack[0];
    v0197 = ncons(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    v0197 = list2star(stack[-2], stack[-1], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    goto v0233;

v0319:
    v0197 = qvalue(elt(env, 1)); // !*rlnzden
    if (v0197 == nil) goto v0194;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    if (!consp(v0197)) goto v0327;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    v0197 = qcar(v0197);
    v0197 = (consp(v0197) ? nil : lisp_true);
    goto v0352;

v0352:
    if (!(v0197 == nil)) goto v0194;
    v0287 = stack[-3];
    v0197 = elt(env, 7); // (lessp leq greaterp geq)
    v0197 = Lmemq(nil, v0287, v0197);
    if (v0197 == nil) goto v0353;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    fn = elt(env, 15); // multf
    v0197 = (*qfn2(fn))(qenv(fn), v0350, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    v0350 = v0197;
    goto v0353;

v0353:
    v0287 = stack[-3];
    v0197 = qvalue(elt(env, 5)); // nil
    v0197 = list3(v0287, v0350, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    stack[0] = v0197;
    v0197 = qvalue(elt(env, 6)); // !*rladdcond
    if (v0197 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    stack[-2] = elt(env, 8); // and
    v0287 = elt(env, 10); // neq
    v0197 = stack[-1];
    v0350 = qcdr(v0197);
    v0197 = qvalue(elt(env, 5)); // nil
    stack[-1] = list3(v0287, v0350, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    v0197 = stack[0];
    v0197 = ncons(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    env = stack[-4];
    v0197 = list2star(stack[-2], stack[-1], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0351;
    stack[0] = v0197;
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0194:
    v0197 = stack[-3];
    v0287 = qvalue(elt(env, 5)); // nil
    popv(5);
    return list3(v0197, v0350, v0287);

v0327:
    v0197 = qvalue(elt(env, 3)); // t
    goto v0352;

v0076:
    v0197 = qvalue(elt(env, 3)); // t
    goto v0075;

v0029:
    v0197 = qvalue(elt(env, 3)); // t
    goto v0028;

v0095:
    v0197 = qvalue(elt(env, 3)); // t
    goto v0097;
// error exit handlers
v0351:
    popv(5);
    return nil;
}



// Code for cl_simpl

static LispObject CC_cl_simpl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0081, v0080, v0021, v0354;
    LispObject fn;
    LispObject v0049, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_simpl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_simpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0049;
    v0080 = v0001;
    stack[-3] = v0000;
// end of prologue
    v0081 = qvalue(elt(env, 1)); // !*rlsism
    if (v0081 == nil) goto v0058;
    v0081 = v0080;
    fn = elt(env, 6); // cl_sitheo
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0080 = v0081;
    v0021 = v0080;
    v0081 = elt(env, 3); // inctheo
    if (v0021 == v0081) goto v0045;
    stack[-4] = elt(env, 4); // and
    stack[-1] = v0080;
    stack[0] = qvalue(elt(env, 2)); // nil
    v0081 = stack[-2];
    v0081 = add1(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    fn = elt(env, 7); // rl_smupdknowl
    v0081 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-1], stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0080 = v0081;
    v0021 = v0080;
    v0081 = elt(env, 5); // false
    if (v0021 == v0081) goto v0043;
    v0354 = stack[-3];
    v0021 = v0080;
    v0080 = stack[-2];
    v0081 = qvalue(elt(env, 2)); // nil
    {
        popv(6);
        fn = elt(env, 8); // cl_simpl1
        return (*qfnn(fn))(qenv(fn), 4, v0354, v0021, v0080, v0081);
    }

v0043:
    v0081 = elt(env, 3); // inctheo
    { popv(6); return onevalue(v0081); }

v0045:
    v0081 = elt(env, 3); // inctheo
    { popv(6); return onevalue(v0081); }

v0058:
    v0354 = stack[-3];
    v0021 = qvalue(elt(env, 2)); // nil
    v0080 = stack[-2];
    v0081 = qvalue(elt(env, 2)); // nil
    {
        popv(6);
        fn = elt(env, 8); // cl_simpl1
        return (*qfnn(fn))(qenv(fn), 4, v0354, v0021, v0080, v0081);
    }
// error exit handlers
v0082:
    popv(6);
    return nil;
}



// Code for bc_minus!?

static LispObject CC_bc_minusW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0013, v0057;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_minus?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0057 = v0000;
// end of prologue
    v0013 = v0057;
    v0013 = qcar(v0013);
    v0013 = integerp(v0013);
    if (v0013 == nil) goto v0041;
    v0013 = v0057;
    v0057 = qcar(v0013);
    v0013 = (LispObject)1; // 0
        return Llessp(nil, v0057, v0013);

v0041:
    v0013 = v0057;
    v0013 = qcar(v0013);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(qenv(fn), v0013);
    }
}



// Code for cr!:minusp

static LispObject CC_crTminusp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0032, v0030, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cr:minusp");
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
    v0032 = v0000;
// end of prologue
    v0030 = v0032;
    v0030 = qcdr(v0030);
    v0030 = qcar(v0030);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0031 = v0030;
    v0030 = v0032;
    v0032 = v0031;
    if (!consp(v0032)) goto v0064;
    v0032 = v0030;
    v0032 = qcar(v0032);
    v0032 = (LispObject)zerop(v0032);
    v0032 = v0032 ? lisp_true : nil;
    env = stack[0];
    if (v0032 == nil) goto v0010;
    v0032 = v0031;
    v0030 = qcar(v0032);
    v0032 = (LispObject)1; // 0
        popv(1);
        return Llessp(nil, v0030, v0032);

v0010:
    v0032 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0032); }

v0064:
    v0032 = v0030;
    v0032 = (LispObject)zerop(v0032);
    v0032 = v0032 ? lisp_true : nil;
    env = stack[0];
    if (v0032 == nil) goto v0099;
    v0030 = v0031;
    v0032 = (LispObject)1; // 0
        popv(1);
        return Llessp(nil, v0030, v0032);

v0099:
    v0032 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0032); }
}



// Code for matrix_input_test

static LispObject CC_matrix_input_test(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086, v0092, v0055;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrix_input_test");
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
    v0092 = v0000;
// end of prologue
    v0055 = v0092;
    v0086 = elt(env, 1); // mat
    if (!consp(v0055)) goto v0041;
    v0055 = qcar(v0055);
    if (v0055 == v0086) { popv(1); return onevalue(v0092); }
    else goto v0041;

v0041:
    v0055 = elt(env, 2); // "ERROR: `"
    v0086 = elt(env, 3); // "' is non matrix input."
    v0086 = list3(v0055, v0092, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[0];
    fn = elt(env, 4); // rederr
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    v0086 = nil;
    { popv(1); return onevalue(v0086); }
// error exit handlers
v0056:
    popv(1);
    return nil;
}



// Code for column_dim

static LispObject CC_column_dim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0096;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for column_dim");
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
    v0096 = qvalue(elt(env, 1)); // !*fast_la
    if (v0096 == nil) goto v0063;
    v0096 = qvalue(elt(env, 2)); // nil
    goto v0018;

v0018:
    if (v0096 == nil) goto v0024;
    v0096 = elt(env, 3); // "Error in column_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    goto v0024;

v0024:
    v0096 = stack[0];
    fn = elt(env, 5); // size_of_matrix
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    v0096 = qcdr(v0096);
    v0096 = qcar(v0096);
    { popv(2); return onevalue(v0096); }

v0063:
    v0096 = stack[0];
    fn = elt(env, 6); // matrixp
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    v0096 = (v0096 == nil ? lisp_true : nil);
    goto v0018;
// error exit handlers
v0095:
    popv(2);
    return nil;
}



// Code for unshift

static LispObject CC_unshift(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0321, v0044, v0320, v0007;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unshift");
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
    v0007 = v0000;
// end of prologue
    v0321 = qvalue(elt(env, 1)); // !*xo
    v0320 = v0321;
    v0321 = v0320;
    v0321 = qcar(v0321);
    if (!consp(v0321)) goto v0034;
    v0321 = v0320;
    v0321 = qcar(v0321);
    v0321 = qcdr(v0321);
    v0044 = qcar(v0321);
    v0321 = (LispObject)1; // 0
    if (v0044 == v0321) goto v0061;
    v0321 = qvalue(elt(env, 2)); // nil
    goto v0018;

v0018:
    if (!(v0321 == nil)) { popv(1); return onevalue(v0007); }
    v0044 = v0007;
    v0321 = qvalue(elt(env, 1)); // !*xo
    fn = elt(env, 4); // gfplus
    v0321 = (*qfn2(fn))(qenv(fn), v0044, v0321);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); // gfadjust
        return (*qfn1(fn))(qenv(fn), v0321);
    }

v0061:
    v0321 = v0320;
    v0321 = qcdr(v0321);
    v0321 = qcdr(v0321);
    v0044 = qcar(v0321);
    v0321 = (LispObject)1; // 0
    v0321 = (v0044 == v0321 ? lisp_true : nil);
    goto v0018;

v0034:
    v0044 = v0320;
    v0321 = elt(env, 3); // (0.0 . 0.0)
    v0321 = (equal(v0044, v0321) ? lisp_true : nil);
    goto v0018;
// error exit handlers
v0085:
    popv(1);
    return nil;
}



// Code for atlas_edges

static LispObject CC_atlas_edges(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0097;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for atlas_edges");
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
    v0097 = stack[0];
    v0097 = qcar(v0097);
    fn = elt(env, 1); // map__edges
    stack[-1] = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    fn = elt(env, 2); // den__edges
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    fn = elt(env, 3); // union_edges
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    fn = elt(env, 4); // coeff_edges
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    {
        LispObject v0045 = stack[-1];
        popv(3);
        fn = elt(env, 3); // union_edges
        return (*qfn2(fn))(qenv(fn), v0045, v0097);
    }
// error exit handlers
v0027:
    popv(3);
    return nil;
}



// Code for compactf3

static LispObject CC_compactf3(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056, v0059;
    LispObject fn;
    LispObject v0049, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf3");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compactf3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0049,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0049;
    stack[-1] = v0001;
    v0056 = v0000;
// end of prologue
    stack[-2] = qvalue(elt(env, 1)); // mv!-vars!*
    qvalue(elt(env, 1)) = nil; // mv!-vars!*
    v0055 = stack[0];
    qvalue(elt(env, 1)) = v0055; // mv!-vars!*
    v0055 = stack[0];
    fn = elt(env, 3); // sf2mv
    v0059 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    v0056 = stack[-1];
    v0055 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 4); // mv!-compact
    v0056 = (*qfnn(fn))(qenv(fn), 3, v0059, v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    v0055 = stack[0];
    fn = elt(env, 5); // mv2sf
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // mv!-vars!*
    { popv(4); return onevalue(v0055); }
// error exit handlers
v0020:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // mv!-vars!*
    popv(4);
    return nil;
}



// Code for !*sq2fourier

static LispObject CC_Hsq2fourier(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0003, v0333;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *sq2fourier");
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
    stack[0] = v0000;
// end of prologue
    v0006 = stack[0];
    v0006 = qcar(v0006);
    if (v0006 == nil) goto v0033;
    v0006 = (LispObject)49; // 3
    v0006 = Lmkvect(nil, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[-2] = v0006;
    v0333 = stack[-2];
    v0003 = (LispObject)1; // 0
    v0006 = stack[0];
    *(LispObject *)((char *)v0333 + (CELL-TAG_VECTOR) + ((int32_t)v0003/(16/CELL))) = v0006;
    v0333 = stack[-2];
    v0003 = (LispObject)17; // 1
    v0006 = elt(env, 2); // cos
    *(LispObject *)((char *)v0333 + (CELL-TAG_VECTOR) + ((int32_t)v0003/(16/CELL))) = v0006;
    stack[-1] = stack[-2];
    stack[0] = (LispObject)33; // 2
    fn = elt(env, 5); // fs!:make!-nullangle
    v0006 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0006;
    v0333 = stack[-2];
    v0003 = (LispObject)49; // 3
    v0006 = qvalue(elt(env, 1)); // nil
    *(LispObject *)((char *)v0333 + (CELL-TAG_VECTOR) + ((int32_t)v0003/(16/CELL))) = v0006;
    v0003 = elt(env, 3); // fourier
    v0006 = elt(env, 4); // tag
    v0003 = get(v0003, v0006);
    v0006 = stack[-2];
    popv(4);
    return cons(v0003, v0006);

v0033:
    v0006 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0006); }
// error exit handlers
v0014:
    popv(4);
    return nil;
}



// Code for gi

static LispObject CC_gi(LispObject env,
                         LispObject v0001, LispObject v0049)
{
    LispObject nil = C_nil;
    LispObject v0093, v0313;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0049,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0049;
    v0093 = v0001;
// end of prologue
    stack[-4] = qvalue(elt(env, 1)); // gg!*
    qvalue(elt(env, 1)) = nil; // gg!*
    qvalue(elt(env, 1)) = v0093; // gg!*
    stack[-2] = nil;
    v0093 = qvalue(elt(env, 1)); // gg!*
    stack[-1] = v0093;
    goto v0019;

v0019:
    v0093 = stack[-1];
    if (v0093 == nil) goto v0058;
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    stack[0] = v0093;
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    fn = elt(env, 3); // class
    v0313 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0093 = stack[-3];
    if (!(equal(v0313, v0093))) goto v0097;
    v0313 = stack[0];
    v0093 = stack[-2];
    v0093 = cons(v0313, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-2] = v0093;
    goto v0097;

v0097:
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    goto v0019;

v0058:
    v0093 = stack[-2];
    qvalue(elt(env, 1)) = stack[-4]; // gg!*
    { popv(6); return onevalue(v0093); }
// error exit handlers
v0332:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; // gg!*
    popv(6);
    return nil;
}



// Code for r2flbf

static LispObject CC_r2flbf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058, v0019;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for r2flbf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0019 = v0000;
// end of prologue
    v0058 = qvalue(elt(env, 1)); // !*bftag
    if (v0058 == nil) goto v0018;
    v0058 = v0019;
    {
        fn = elt(env, 2); // r2bf
        return (*qfn1(fn))(qenv(fn), v0058);
    }

v0018:
    v0058 = v0019;
    {
        fn = elt(env, 3); // r2fl
        return (*qfn1(fn))(qenv(fn), v0058);
    }
}



// Code for rtypepart

static LispObject CC_rtypepart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0064;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rtypepart");
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
    v0064 = v0000;
// end of prologue
    fn = elt(env, 3); // getrtypecar
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[0];
    if (v0064 == nil) goto v0018;
    v0064 = elt(env, 1); // yetunknowntype
    { popv(1); return onevalue(v0064); }

v0018:
    v0064 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0064); }
// error exit handlers
v0058:
    popv(1);
    return nil;
}



// Code for freeof!-df

static LispObject CC_freeofKdf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0077, v0075;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeof-df");
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

v0024:
    v0077 = stack[-1];
    if (!consp(v0077)) goto v0064;
    v0077 = stack[-1];
    v0075 = qcar(v0077);
    v0077 = elt(env, 2); // !:dn!:
    if (v0075 == v0077) goto v0051;
    v0077 = stack[-1];
    v0077 = qcar(v0077);
    if (!symbolp(v0077)) v0077 = nil;
    else { v0077 = qfastgets(v0077);
           if (v0077 != nil) { v0077 = elt(v0077, 8); // dname
#ifdef RECORD_GET
             if (v0077 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0077 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0077 == SPID_NOPROP) v0077 = nil; }}
#endif
    goto v0330;

v0330:
    if (v0077 == nil) goto v0020;
    v0077 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0077); }

v0020:
    v0077 = stack[-1];
    v0075 = qcar(v0077);
    v0077 = elt(env, 3); // !*sq
    if (v0075 == v0077) goto v0011;
    v0077 = stack[-1];
    v0075 = qcar(v0077);
    v0077 = elt(env, 4); // df
    if (v0075 == v0077) goto v0320;
    v0077 = stack[-1];
    v0075 = qcdr(v0077);
    v0077 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); // freeof!-dfl
        return (*qfn2(fn))(qenv(fn), v0075, v0077);
    }

v0320:
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    v0075 = qcar(v0077);
    v0077 = stack[0];
    v0077 = CC_freeofKdf(env, v0075, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0358;
    env = stack[-2];
    if (v0077 == nil) goto v0022;
    v0075 = stack[0];
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    fn = elt(env, 7); // smember
    v0077 = (*qfn2(fn))(qenv(fn), v0075, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0358;
    v0077 = (v0077 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0077); }

v0022:
    v0077 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0077); }

v0011:
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    fn = elt(env, 8); // prepsq
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0358;
    env = stack[-2];
    stack[-1] = v0077;
    goto v0024;

v0051:
    v0077 = qvalue(elt(env, 1)); // t
    goto v0330;

v0064:
    v0077 = qvalue(elt(env, 1)); // t
    goto v0330;
// error exit handlers
v0358:
    popv(3);
    return nil;
}



// Code for qqe_length!-graph!-bterm

static LispObject CC_qqe_lengthKgraphKbterm(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0005, v0355;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-bterm");
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
    v0005 = stack[-1];
    if (v0005 == nil) goto v0330;
    v0005 = stack[-1];
    v0005 = (consp(v0005) ? nil : lisp_true);
    goto v0063;

v0063:
    if (!(v0005 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0005 = stack[-1];
    fn = elt(env, 4); // qqe_op
    v0355 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-2];
    v0005 = elt(env, 2); // (lhead rhead)
    v0005 = Lmemq(nil, v0355, v0005);
    if (v0005 == nil) goto v0047;
    v0355 = stack[-1];
    v0005 = stack[0];
    fn = elt(env, 5); // qqe_length!-graph!-bterm!-update!-headmin
    v0005 = (*qfn2(fn))(qenv(fn), v0355, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    stack[0] = v0005;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }

v0047:
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    stack[-1] = v0005;
    goto v0009;

v0009:
    v0005 = stack[-1];
    if (v0005 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0005 = stack[-1];
    v0005 = qcar(v0005);
    v0355 = v0005;
    v0005 = stack[0];
    v0005 = CC_qqe_lengthKgraphKbterm(env, v0355, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-2];
    stack[0] = v0005;
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    stack[-1] = v0005;
    goto v0009;

v0330:
    v0005 = qvalue(elt(env, 1)); // t
    goto v0063;
// error exit handlers
v0333:
    popv(3);
    return nil;
}



// Code for quotfx1

static LispObject CC_quotfx1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0393, v0394, v0395, v0186;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfx1");
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
    v0393 = stack[-8];
    if (v0393 == nil) goto v0018;
    v0394 = stack[-8];
    v0393 = stack[-7];
    if (equal(v0394, v0393)) goto v0087;
    v0394 = stack[-7];
    v0393 = (LispObject)17; // 1
    if (v0394 == v0393) { LispObject res = stack[-8]; popv(11); return onevalue(res); }
    v0393 = stack[-7];
    if (!consp(v0393)) goto v0060;
    v0393 = stack[-7];
    v0393 = qcar(v0393);
    v0393 = (consp(v0393) ? nil : lisp_true);
    goto v0020;

v0020:
    if (v0393 == nil) goto v0011;
    v0394 = stack[-8];
    v0393 = stack[-7];
    {
        popv(11);
        fn = elt(env, 2); // quotfdx
        return (*qfn2(fn))(qenv(fn), v0394, v0393);
    }

v0011:
    v0393 = stack[-8];
    if (!consp(v0393)) goto v0084;
    v0393 = stack[-8];
    v0393 = qcar(v0393);
    v0393 = (consp(v0393) ? nil : lisp_true);
    goto v0100;

v0100:
    if (v0393 == nil) goto v0042;
    v0394 = stack[-8];
    v0393 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); // quotfxerr
        return (*qfn2(fn))(qenv(fn), v0394, v0393);
    }

v0042:
    v0393 = stack[-8];
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    v0394 = qcar(v0393);
    v0393 = stack[-7];
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    if (v0394 == v0393) goto v0015;
    v0393 = stack[-8];
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    v0394 = qcar(v0393);
    v0393 = stack[-7];
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    fn = elt(env, 4); // ordop
    v0393 = (*qfn2(fn))(qenv(fn), v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    if (v0393 == nil) goto v0396;
    v0394 = stack[-8];
    v0393 = stack[-7];
    {
        popv(11);
        fn = elt(env, 5); // quotkx
        return (*qfn2(fn))(qenv(fn), v0394, v0393);
    }

v0396:
    v0394 = stack[-8];
    v0393 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); // quotfxerr
        return (*qfn2(fn))(qenv(fn), v0394, v0393);
    }

v0015:
    stack[-9] = nil;
    stack[-1] = nil;
    v0393 = stack[-7];
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    v0393 = qcdr(v0393);
    stack[-5] = v0393;
    goto v0069;

v0069:
    v0393 = stack[-8];
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    v0394 = qcdr(v0393);
    stack[-6] = v0394;
    v0393 = stack[-5];
    v0393 = (LispObject)lessp2(v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    v0393 = v0393 ? lisp_true : nil;
    env = stack[-10];
    if (v0393 == nil) goto v0397;
    v0394 = stack[-8];
    v0393 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); // quotfxerr
        return (*qfn2(fn))(qenv(fn), v0394, v0393);
    }

v0397:
    v0393 = stack[-8];
    fn = elt(env, 6); // lt!*
    v0393 = (*qfn1(fn))(qenv(fn), v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    stack[0] = v0393;
    v0393 = stack[-7];
    fn = elt(env, 6); // lt!*
    v0393 = (*qfn1(fn))(qenv(fn), v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    v0394 = stack[-7];
    v0394 = qcar(v0394);
    v0394 = qcar(v0394);
    v0394 = qcar(v0394);
    stack[-4] = v0394;
    v0394 = stack[0];
    v0394 = qcdr(v0394);
    v0393 = qcdr(v0393);
    v0393 = CC_quotfx1(env, v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    stack[-3] = v0393;
    v0394 = stack[-6];
    v0393 = stack[-5];
    v0393 = (LispObject)(int32_t)((int32_t)v0394 - (int32_t)v0393 + TAG_FIXNUM);
    stack[0] = v0393;
    v0394 = stack[0];
    v0393 = (LispObject)1; // 0
    if (v0394 == v0393) goto v0229;
    v0394 = stack[-4];
    v0393 = stack[0];
    fn = elt(env, 7); // to
    v0393 = (*qfn2(fn))(qenv(fn), v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    stack[-2] = v0393;
    v0393 = stack[-9];
    if (!(v0393 == nil)) goto v0398;
    v0186 = stack[-8];
    v0395 = stack[-4];
    v0394 = stack[-6];
    v0393 = stack[0];
    v0393 = (LispObject)(int32_t)((int32_t)v0394 - (int32_t)v0393 + TAG_FIXNUM);
    v0393 = (LispObject)((int32_t)(v0393) - 0x10);
    fn = elt(env, 8); // cutf
    v0393 = (*qfnn(fn))(qenv(fn), 3, v0186, v0395, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    stack[-8] = v0393;
    goto v0398;

v0398:
    v0393 = qvalue(elt(env, 1)); // t
    stack[-9] = v0393;
    v0186 = stack[-7];
    v0395 = stack[-4];
    v0394 = stack[-5];
    v0393 = stack[0];
    v0393 = (LispObject)(int32_t)((int32_t)v0394 - (int32_t)v0393 + TAG_FIXNUM);
    v0393 = (LispObject)((int32_t)(v0393) - 0x10);
    fn = elt(env, 8); // cutf
    v0393 = (*qfnn(fn))(qenv(fn), 3, v0186, v0395, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    stack[-7] = v0393;
    stack[-6] = stack[-8];
    v0394 = stack[0];
    v0393 = (LispObject)1; // 0
    if (v0394 == v0393) goto v0241;
    v0394 = stack[-2];
    v0393 = (LispObject)17; // 1
    v0393 = cons(v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    v0394 = ncons(v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    v0393 = stack[-7];
    fn = elt(env, 9); // multf
    v0393 = (*qfn2(fn))(qenv(fn), v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    stack[0] = v0393;
    goto v0399;

v0399:
    v0393 = stack[-3];
    fn = elt(env, 10); // negf
    v0393 = (*qfn1(fn))(qenv(fn), v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    fn = elt(env, 9); // multf
    v0393 = (*qfn2(fn))(qenv(fn), stack[0], v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    fn = elt(env, 11); // addf
    v0393 = (*qfn2(fn))(qenv(fn), stack[-6], v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    stack[-8] = v0393;
    v0393 = stack[-8];
    if (v0393 == nil) goto v0400;
    v0393 = stack[-8];
    if (!consp(v0393)) goto v0401;
    v0393 = stack[-8];
    v0393 = qcar(v0393);
    v0393 = (consp(v0393) ? nil : lisp_true);
    goto v0202;

v0202:
    if (v0393 == nil) goto v0199;
    v0393 = qvalue(elt(env, 1)); // t
    goto v0402;

v0402:
    if (v0393 == nil) goto v0400;
    v0394 = stack[-8];
    v0393 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); // quotfxerr
        return (*qfn2(fn))(qenv(fn), v0394, v0393);
    }

v0400:
    stack[0] = stack[-1];
    v0394 = stack[-2];
    v0393 = stack[-3];
    v0393 = cons(v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    fn = elt(env, 12); // aconc!*
    v0393 = (*qfn2(fn))(qenv(fn), stack[0], v0393);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-10];
    stack[-1] = v0393;
    v0393 = stack[-8];
    if (v0393 == nil) { LispObject res = stack[-1]; popv(11); return onevalue(res); }
    else goto v0069;

v0199:
    v0393 = stack[-8];
    v0393 = qcar(v0393);
    v0393 = qcar(v0393);
    v0394 = qcar(v0393);
    v0393 = stack[-4];
    v0393 = (v0394 == v0393 ? lisp_true : nil);
    v0393 = (v0393 == nil ? lisp_true : nil);
    goto v0402;

v0401:
    v0393 = qvalue(elt(env, 1)); // t
    goto v0202;

v0241:
    v0393 = stack[-7];
    stack[0] = v0393;
    goto v0399;

v0229:
    v0394 = stack[-1];
    v0393 = stack[-3];
    {
        popv(11);
        fn = elt(env, 13); // rnconc
        return (*qfn2(fn))(qenv(fn), v0394, v0393);
    }

v0084:
    v0393 = qvalue(elt(env, 1)); // t
    goto v0100;

v0060:
    v0393 = qvalue(elt(env, 1)); // t
    goto v0020;

v0087:
    v0393 = (LispObject)17; // 1
    { popv(11); return onevalue(v0393); }

v0018:
    v0394 = stack[-8];
    v0393 = stack[-7];
    {
        popv(11);
        fn = elt(env, 3); // quotfxerr
        return (*qfn2(fn))(qenv(fn), v0394, v0393);
    }
// error exit handlers
v0185:
    popv(11);
    return nil;
}



// Code for ofsf_factsf

static LispObject CC_ofsf_factsf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0332, v0043;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_factsf");
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
    goto v0019;

v0019:
    v0043 = stack[0];
    v0332 = (LispObject)17; // 1
    v0332 = (LispObject)lesseq2(v0043, v0332);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0332 = v0332 ? lisp_true : nil;
    env = stack[-2];
    if (v0332 == nil) goto v0012;
    v0332 = (LispObject)17; // 1
    v0043 = v0332;
    goto v0062;

v0062:
    v0332 = stack[-1];
    if (v0332 == nil) { popv(3); return onevalue(v0043); }
    v0332 = stack[-1];
    v0332 = qcar(v0332);
    fn = elt(env, 1); // multf
    v0332 = (*qfn2(fn))(qenv(fn), v0332, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0043 = v0332;
    v0332 = stack[-1];
    v0332 = qcdr(v0332);
    stack[-1] = v0332;
    goto v0062;

v0012:
    v0043 = stack[0];
    v0332 = stack[-1];
    v0332 = cons(v0043, v0332);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    stack[-1] = v0332;
    v0332 = (LispObject)17; // 1
    fn = elt(env, 2); // negf
    v0332 = (*qfn1(fn))(qenv(fn), v0332);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    fn = elt(env, 3); // addf
    v0332 = (*qfn2(fn))(qenv(fn), stack[0], v0332);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    stack[0] = v0332;
    goto v0019;
// error exit handlers
v0100:
    popv(3);
    return nil;
}



// Code for expttermp

static LispObject CC_expttermp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0059, v0010, v0011, v0048;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expttermp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0011 = v0001;
    v0048 = v0000;
// end of prologue
    v0010 = v0048;
    v0059 = elt(env, 1); // expt
    if (!consp(v0010)) goto v0061;
    v0010 = qcar(v0010);
    if (!(v0010 == v0059)) goto v0061;
    v0059 = v0048;
    v0059 = qcdr(v0059);
    v0059 = qcar(v0059);
    v0010 = v0011;
    {
        fn = elt(env, 2); // expttermp1
        return (*qfn2(fn))(qenv(fn), v0059, v0010);
    }

v0061:
    v0059 = v0048;
    v0010 = v0011;
    {
        fn = elt(env, 2); // expttermp1
        return (*qfn2(fn))(qenv(fn), v0059, v0010);
    }
}



// Code for xpartitsq

static LispObject CC_xpartitsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0387, v0388, v0342;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xpartitsq");
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
    v0342 = v0000;
// end of prologue
    v0387 = v0342;
    v0388 = qcar(v0387);
    v0387 = v0342;
    v0387 = qcdr(v0387);
    stack[-2] = v0388;
    stack[-1] = v0387;
    v0387 = stack[-2];
    if (v0387 == nil) goto v0063;
    v0387 = stack[-2];
    if (!consp(v0387)) goto v0041;
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0387 = (consp(v0387) ? nil : lisp_true);
    goto v0099;

v0099:
    if (v0387 == nil) goto v0020;
    v0387 = (LispObject)17; // 1
    v0388 = v0342;
    v0387 = cons(v0387, v0388);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    popv(4);
    return ncons(v0387);

v0020:
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 3); // sfp
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    if (v0387 == nil) goto v0052;
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    v0388 = qcar(v0387);
    v0387 = (LispObject)17; // 1
    v0387 = cons(v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0388 = CC_xpartitsq(env, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    v0387 = qcdr(v0387);
    fn = elt(env, 4); // xexptpf
    stack[0] = (*qfn2(fn))(qenv(fn), v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0388 = qcdr(v0387);
    v0387 = stack[-1];
    v0387 = cons(v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    fn = elt(env, 5); // cancel
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = CC_xpartitsq(env, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    fn = elt(env, 6); // wedgepf
    v0387 = (*qfn2(fn))(qenv(fn), stack[0], v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    stack[0] = v0387;
    goto v0303;

v0303:
    v0387 = stack[-2];
    v0388 = qcdr(v0387);
    v0387 = stack[-1];
    v0387 = cons(v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = CC_xpartitsq(env, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    {
        LispObject v0411 = stack[0];
        popv(4);
        fn = elt(env, 7); // addpf
        return (*qfn2(fn))(qenv(fn), v0411, v0387);
    }

v0052:
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 8); // xvarp
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    if (v0387 == nil) goto v0066;
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 9); // xpartitk
    v0388 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0387 = qcar(v0387);
    v0387 = qcdr(v0387);
    fn = elt(env, 4); // xexptpf
    stack[0] = (*qfn2(fn))(qenv(fn), v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0388 = qcdr(v0387);
    v0387 = stack[-1];
    v0387 = cons(v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    fn = elt(env, 5); // cancel
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = CC_xpartitsq(env, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    fn = elt(env, 6); // wedgepf
    v0387 = (*qfn2(fn))(qenv(fn), stack[0], v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    stack[0] = v0387;
    goto v0303;

v0066:
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0388 = qcdr(v0387);
    v0387 = stack[-1];
    v0387 = cons(v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    fn = elt(env, 5); // cancel
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    stack[0] = CC_xpartitsq(env, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = stack[-2];
    v0387 = qcar(v0387);
    v0388 = qcar(v0387);
    v0387 = (LispObject)17; // 1
    v0387 = cons(v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0388 = ncons(v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0387 = (LispObject)17; // 1
    v0387 = cons(v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    fn = elt(env, 10); // multpfsq
    v0387 = (*qfn2(fn))(qenv(fn), stack[0], v0387);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    stack[0] = v0387;
    goto v0303;

v0041:
    v0387 = qvalue(elt(env, 2)); // t
    goto v0099;

v0063:
    v0387 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0387); }
// error exit handlers
v0218:
    popv(4);
    return nil;
}



// Code for evalsubset

static LispObject CC_evalsubset(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0096, v0097, v0095;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalsubset");
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
    v0096 = v0001;
    v0097 = v0000;
// end of prologue
    v0095 = elt(env, 1); // subset
    fn = elt(env, 2); // evalsetbool
    v0096 = (*qfnn(fn))(qenv(fn), 3, v0095, v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[0];
    v0097 = v0096;
    v0096 = v0097;
    if (!consp(v0096)) { popv(1); return onevalue(v0097); }
    v0096 = v0097;
    {
        popv(1);
        fn = elt(env, 3); // evalsymsubset
        return (*qfn1(fn))(qenv(fn), v0096);
    }
// error exit handlers
v0061:
    popv(1);
    return nil;
}



// Code for adjp

static LispObject CC_adjp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0077, v0075;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for adjp");
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
    v0075 = stack[-1];
    v0077 = elt(env, 1); // unit
    if (v0075 == v0077) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0077 = stack[-1];
    if (!consp(v0077)) goto v0041;
    v0077 = stack[-1];
    v0075 = qcar(v0077);
    v0077 = elt(env, 3); // comm
    if (v0075 == v0077) goto v0010;
    v0077 = stack[-1];
    v0075 = qcar(v0077);
    v0077 = elt(env, 4); // anticomm
    if (v0075 == v0077) goto v0321;
    v0077 = stack[-1];
    v0075 = qcar(v0077);
    v0077 = elt(env, 2); // adjoint
    v0075 = get(v0075, v0077);
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    popv(4);
    return cons(v0075, v0077);

v0321:
    stack[-2] = elt(env, 4); // anticomm
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    stack[0] = CC_adjp(env, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-3];
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    v0077 = CC_adjp(env, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    {
        LispObject v0409 = stack[-2];
        LispObject v0412 = stack[0];
        popv(4);
        return list3(v0409, v0412, v0077);
    }

v0010:
    stack[-2] = elt(env, 3); // comm
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    stack[0] = CC_adjp(env, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-3];
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    v0077 = CC_adjp(env, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    {
        LispObject v0078 = stack[-2];
        LispObject v0079 = stack[0];
        popv(4);
        return list3(v0078, v0079, v0077);
    }

v0041:
    v0077 = stack[-1];
    v0075 = elt(env, 2); // adjoint
    popv(4);
    return get(v0077, v0075);
// error exit handlers
v0291:
    popv(4);
    return nil;
}



// Code for calc_world

static LispObject CC_calc_world(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0321, v0044;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_world");
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
    stack[0] = stack[-1];
    v0321 = stack[-2];
    fn = elt(env, 1); // s_world_names
    v0321 = (*qfn1(fn))(qenv(fn), v0321);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-4];
    fn = elt(env, 2); // actual_alst
    v0321 = (*qfn2(fn))(qenv(fn), stack[0], v0321);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-4];
    stack[-1] = v0321;
    v0321 = stack[-2];
    v0321 = qcdr(v0321);
    v0321 = qcar(v0321);
    stack[0] = v0321;
    v0044 = stack[-1];
    v0321 = stack[0];
    v0321 = qcdr(v0321);
    v0321 = Lassoc(nil, v0044, v0321);
    stack[-3] = v0321;
    v0321 = stack[-3];
    if (v0321 == nil) goto v0011;
    v0321 = stack[-3];
    v0321 = qcdr(v0321);
    { popv(5); return onevalue(v0321); }

v0011:
    v0321 = stack[-2];
    v0321 = qcdr(v0321);
    v0321 = qcdr(v0321);
    v0044 = qcar(v0321);
    v0321 = stack[-1];
    fn = elt(env, 3); // calc_atlas
    v0321 = (*qfn2(fn))(qenv(fn), v0044, v0321);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-4];
    fn = elt(env, 4); // reval
    v0321 = (*qfn1(fn))(qenv(fn), v0321);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-4];
    stack[-3] = v0321;
    v0044 = stack[-1];
    v0321 = stack[-3];
    v0321 = cons(v0044, v0321);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-4];
    v0321 = ncons(v0321);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-4];
    v0321 = Lnconc(nil, stack[0], v0321);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }
// error exit handlers
v0355:
    popv(5);
    return nil;
}



setup_type const u43_setup[] =
{
    {"expvec2a1",               too_few_2,      CC_expvec2a1,  wrong_no_2},
    {"deflate1",                too_few_2,      CC_deflate1,   wrong_no_2},
    {"coeff1_calc",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff1_calc},
    {"dp_prod",                 too_few_2,      CC_dp_prod,    wrong_no_2},
    {"dummy_nam",               CC_dummy_nam,   too_many_1,    wrong_no_1},
    {"precision1",              too_few_2,      CC_precision1, wrong_no_2},
    {"texexplode",              CC_texexplode,  too_many_1,    wrong_no_1},
    {"simpx1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpx1},
    {"makecoeffpairs1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs1},
    {"pasf_qff2ivl",            CC_pasf_qff2ivl,too_many_1,    wrong_no_1},
    {"aex_neg",                 CC_aex_neg,     too_many_1,    wrong_no_1},
    {"parseml",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_parseml},
    {"tidysqrt",                CC_tidysqrt,    too_many_1,    wrong_no_1},
    {"getvariables",            CC_getvariables,too_many_1,    wrong_no_1},
    {"row_dim",                 CC_row_dim,     too_many_1,    wrong_no_1},
    {"multsqpf",                too_few_2,      CC_multsqpf,   wrong_no_2},
    {"gffdot",                  too_few_2,      CC_gffdot,     wrong_no_2},
    {"*kp2q",                   too_few_2,      CC_Hkp2q,      wrong_no_2},
    {"physop*sq",               CC_physopHsq,   too_many_1,    wrong_no_1},
    {"store_edges",             CC_store_edges, too_many_1,    wrong_no_1},
    {"lchk",                    CC_lchk,        too_many_1,    wrong_no_1},
    {"compactf1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf1},
    {"*v2j",                    CC_Hv2j,        too_many_1,    wrong_no_1},
    {"rl_simplb",               too_few_2,      CC_rl_simplb,  wrong_no_2},
    {"ps:mkpow",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTmkpow},
    {"varsinsf",                too_few_2,      CC_varsinsf,   wrong_no_2},
    {"dip-nc-ev-prod",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod},
    {"minprec",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minprec},
    {"acmemb",                  too_few_2,      CC_acmemb,     wrong_no_2},
    {"mo_from_ei",              CC_mo_from_ei,  too_many_1,    wrong_no_1},
    {"general-negate-term",     CC_generalKnegateKterm,too_many_1,wrong_no_1},
    {"addinds",                 too_few_2,      CC_addinds,    wrong_no_2},
    {"available*p",             CC_availableHp, too_many_1,    wrong_no_1},
    {"ofsf_simpat",             CC_ofsf_simpat, too_many_1,    wrong_no_1},
    {"cl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_simpl},
    {"bc_minus?",               CC_bc_minusW,   too_many_1,    wrong_no_1},
    {"cr:minusp",               CC_crTminusp,   too_many_1,    wrong_no_1},
    {"matrix_input_test",       CC_matrix_input_test,too_many_1,wrong_no_1},
    {"column_dim",              CC_column_dim,  too_many_1,    wrong_no_1},
    {"unshift",                 CC_unshift,     too_many_1,    wrong_no_1},
    {"atlas_edges",             CC_atlas_edges, too_many_1,    wrong_no_1},
    {"compactf3",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf3},
    {"*sq2fourier",             CC_Hsq2fourier, too_many_1,    wrong_no_1},
    {"gi",                      too_few_2,      CC_gi,         wrong_no_2},
    {"r2flbf",                  CC_r2flbf,      too_many_1,    wrong_no_1},
    {"rtypepart",               CC_rtypepart,   too_many_1,    wrong_no_1},
    {"freeof-df",               too_few_2,      CC_freeofKdf,  wrong_no_2},
    {"qqe_length-graph-bterm",  too_few_2,      CC_qqe_lengthKgraphKbterm,wrong_no_2},
    {"quotfx1",                 too_few_2,      CC_quotfx1,    wrong_no_2},
    {"ofsf_factsf",             CC_ofsf_factsf, too_many_1,    wrong_no_1},
    {"expttermp",               too_few_2,      CC_expttermp,  wrong_no_2},
    {"xpartitsq",               CC_xpartitsq,   too_many_1,    wrong_no_1},
    {"evalsubset",              too_few_2,      CC_evalsubset, wrong_no_2},
    {"adjp",                    CC_adjp,        too_many_1,    wrong_no_1},
    {"calc_world",              too_few_2,      CC_calc_world, wrong_no_2},
    {NULL, (one_args *)"u43", (two_args *)"20229 1430725 5614467", 0}
};

// end of generated code
