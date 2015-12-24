
// $destdir/u26.c        Machine generated C code

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



// Code for subs3t

static LispObject CC_subs3t(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0081, v0082, v0083, v0084;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs3t");
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
    v0082 = v0001;
    stack[-4] = v0000;
// end of prologue
    stack[-5] = nil;
    v0081 = stack[-4];
    stack[0] = qcar(v0081);
    v0081 = stack[-4];
    v0081 = qcdr(v0081);
    if (!consp(v0081)) goto v0085;
    v0081 = stack[-4];
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    v0081 = (consp(v0081) ? nil : lisp_true);
    goto v0086;

v0086:
    if (v0081 == nil) goto v0087;
    v0081 = (LispObject)17; // 1
    fn = elt(env, 7); // sizchk
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    goto v0089;

v0089:
    fn = elt(env, 8); // mtchk
    v0081 = (*qfn2(fn))(qenv(fn), stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    stack[-3] = v0081;
    v0081 = stack[-3];
    if (v0081 == nil) goto v0090;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    if (v0081 == nil) goto v0091;
    v0081 = stack[-4];
    v0083 = qcdr(v0081);
    v0082 = stack[-3];
    v0081 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 9); // subs3f1
    v0081 = (*qfnn(fn))(qenv(fn), 3, v0083, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    stack[-2] = v0081;
    v0081 = qvalue(elt(env, 3)); // mchfg!*
    if (v0081 == nil) goto v0090;
    v0081 = stack[-4];
    v0082 = qcar(v0081);
    v0081 = (LispObject)17; // 1
    v0081 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0082 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = (LispObject)17; // 1
    v0082 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = stack[-2];
    {
        popv(7);
        fn = elt(env, 10); // multsq
        return (*qfn2(fn))(qenv(fn), v0082, v0081);
    }

v0090:
    v0081 = stack[-4];
    v0082 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    v0081 = (LispObject)17; // 1
    popv(7);
    return cons(v0082, v0081);

v0091:
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    v0081 = qcdr(v0081);
    stack[-3] = v0081;
    v0081 = stack[-3];
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    stack[-1] = v0081;
    v0081 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 3)) = v0081; // mchfg!*
    v0081 = stack[-4];
    v0083 = qcdr(v0081);
    v0082 = qvalue(elt(env, 4)); // !*match
    v0081 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 9); // subs3f1
    v0081 = (*qfnn(fn))(qenv(fn), 3, v0083, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    stack[-2] = v0081;
    v0081 = qvalue(elt(env, 1)); // t
    qvalue(elt(env, 3)) = v0081; // mchfg!*
    v0081 = stack[-1];
    v0082 = qcar(v0081);
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    if (equal(v0082, v0081)) goto v0092;
    v0081 = stack[-1];
    v0081 = qcar(v0081);
    fn = elt(env, 11); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    fn = elt(env, 11); // simp
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    if (equal(stack[0], v0081)) goto v0093;
    v0084 = elt(env, 0); // subs3t
    v0083 = stack[-4];
    v0082 = stack[-3];
    v0081 = stack[-1];
    v0081 = list4(v0084, v0083, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    fn = elt(env, 12); // errach
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    goto v0093;

v0093:
    v0081 = stack[-1];
    v0082 = qcdr(v0081);
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    if (equal(v0082, v0081)) goto v0094;
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    stack[0] = qcar(v0081);
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0082 = qcdr(v0081);
    v0081 = stack[-1];
    v0081 = qcdr(v0081);
    v0081 = difference2(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    fn = elt(env, 13); // to
    v0082 = (*qfn2(fn))(qenv(fn), stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = (LispObject)17; // 1
    v0081 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0082 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = (LispObject)17; // 1
    v0082 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = stack[-2];
    fn = elt(env, 10); // multsq
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    stack[-2] = v0081;
    goto v0094;

v0094:
    v0081 = stack[-3];
    fn = elt(env, 14); // simpcar
    v0082 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = stack[-2];
    fn = elt(env, 10); // multsq
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    stack[-2] = v0081;
    v0081 = stack[-3];
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    stack[-3] = v0081;
    v0081 = stack[-3];
    if (v0081 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    v0081 = (LispObject)17; // 1
    stack[-1] = v0081;
    goto v0095;

v0095:
    v0081 = stack[-3];
    if (v0081 == nil) goto v0096;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    if (!consp(v0081)) goto v0097;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    fn = elt(env, 15); // sfp
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    goto v0098;

v0098:
    if (v0081 == nil) goto v0099;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    goto v0100;

v0100:
    stack[0] = v0081;
    v0081 = stack[0];
    fn = elt(env, 16); // noncomp
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    if (!(v0081 == nil)) goto v0101;
    v0081 = qvalue(elt(env, 6)); // !*mcd
    if (!(v0081 == nil)) goto v0102;

v0101:
    v0081 = qvalue(elt(env, 1)); // t
    stack[-5] = v0081;
    goto v0102;

v0102:
    v0081 = stack[-5];
    if (v0081 == nil) goto v0103;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    v0081 = negate(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    goto v0104;

v0104:
    fn = elt(env, 17); // mksp
    v0082 = (*qfn2(fn))(qenv(fn), stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = (LispObject)17; // 1
    v0081 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    fn = elt(env, 18); // multf
    v0081 = (*qfn2(fn))(qenv(fn), stack[-1], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    stack[-1] = v0081;
    v0081 = stack[-3];
    v0081 = qcdr(v0081);
    stack[-3] = v0081;
    goto v0095;

v0103:
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    goto v0104;

v0099:
    v0081 = qvalue(elt(env, 2)); // nil
    stack[-4] = qvalue(elt(env, 5)); // subfg!*
    qvalue(elt(env, 5)) = v0081; // subfg!*
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    fn = elt(env, 11); // simp
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    stack[0] = v0081;
    v0081 = stack[0];
    fn = elt(env, 19); // kernp
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    if (v0081 == nil) goto v0106;
    v0081 = stack[0];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    v0082 = qcar(v0081);
    stack[0] = v0082;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    if (!consp(v0082)) goto v0106;
    v0082 = qcar(v0082);
    if (!(v0082 == v0081)) goto v0106;
    v0081 = stack[0];
    goto v0107;

v0107:
    qvalue(elt(env, 5)) = stack[-4]; // subfg!*
    goto v0100;

v0106:
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    fn = elt(env, 20); // revop1
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    goto v0107;

v0097:
    v0081 = qvalue(elt(env, 1)); // t
    goto v0098;

v0096:
    v0081 = stack[-5];
    if (v0081 == nil) goto v0108;
    v0082 = stack[-1];
    v0081 = stack[-2];
    v0081 = qcar(v0081);
    fn = elt(env, 18); // multf
    v0082 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    v0081 = stack[-2];
    v0081 = qcdr(v0081);
    popv(7);
    return cons(v0082, v0081);

v0108:
    v0081 = stack[-2];
    stack[0] = qcar(v0081);
    v0082 = stack[-1];
    v0081 = stack[-2];
    v0081 = qcdr(v0081);
    fn = elt(env, 18); // multf
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    {
        LispObject v0109 = stack[0];
        popv(7);
        return cons(v0109, v0081);
    }

v0092:
    v0082 = stack[-1];
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    if (equal(v0082, v0081)) goto v0094;
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    stack[0] = qcar(v0081);
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0082 = qcdr(v0081);
    v0081 = stack[-1];
    v0081 = qcdr(v0081);
    v0081 = difference2(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    fn = elt(env, 13); // to
    v0082 = (*qfn2(fn))(qenv(fn), stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = (LispObject)17; // 1
    v0081 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0082 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = (LispObject)17; // 1
    v0082 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    v0081 = stack[-2];
    fn = elt(env, 10); // multsq
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-6];
    stack[-2] = v0081;
    goto v0094;

v0087:
    v0081 = v0082;
    goto v0089;

v0085:
    v0081 = qvalue(elt(env, 1)); // t
    goto v0086;
// error exit handlers
v0105:
    env = stack[-6];
    qvalue(elt(env, 5)) = stack[-4]; // subfg!*
    popv(7);
    return nil;
v0088:
    popv(7);
    return nil;
}



// Code for charnump!:

static LispObject CC_charnumpT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0119, v0120, v0121, v0122;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for charnump:");
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
    v0119 = v0000;
// end of prologue
    stack[-6] = v0119;
    stack[-5] = elt(env, 1); // !0
    stack[-4] = elt(env, 2); // !1
    stack[-3] = elt(env, 3); // !2
    stack[-2] = elt(env, 4); // !3
    stack[-1] = elt(env, 5); // !4
    stack[0] = elt(env, 6); // !5
    v0122 = elt(env, 7); // !6
    v0121 = elt(env, 8); // !7
    v0120 = elt(env, 9); // !8
    v0119 = elt(env, 10); // !9
    v0119 = list4(v0122, v0121, v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-7];
    v0119 = list3star(stack[-2], stack[-1], stack[0], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-7];
    v0119 = list3star(stack[-5], stack[-4], stack[-3], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-7];
    v0119 = Lmember(nil, stack[-6], v0119);
    if (v0119 == nil) goto v0020;
    v0119 = qvalue(elt(env, 11)); // t
    { popv(8); return onevalue(v0119); }

v0020:
    v0119 = nil;
    { popv(8); return onevalue(v0119); }
// error exit handlers
v0123:
    popv(8);
    return nil;
}



// Code for monomcomparedeglex

static LispObject CC_monomcomparedeglex(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0141, v0142, v0059, v0143;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomcomparedeglex");
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
    v0143 = v0000;
// end of prologue
    v0141 = (LispObject)1; // 0
    stack[0] = v0141;
    v0142 = v0143;
    v0141 = (LispObject)1; // 0
    v0059 = *(LispObject *)((char *)v0142 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL)));
    v0142 = stack[-1];
    v0141 = (LispObject)1; // 0
    v0141 = *(LispObject *)((char *)v0142 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL)));
    if (((int32_t)(v0059)) > ((int32_t)(v0141))) goto v0110;
    v0142 = v0143;
    v0141 = (LispObject)1; // 0
    v0059 = *(LispObject *)((char *)v0142 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL)));
    v0142 = stack[-1];
    v0141 = (LispObject)1; // 0
    v0141 = *(LispObject *)((char *)v0142 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL)));
    if (((int32_t)(v0059)) < ((int32_t)(v0141))) goto v0116;
    v0142 = qvalue(elt(env, 1)); // nil
    v0059 = v0143;
    v0141 = (LispObject)17; // 1
    v0141 = *(LispObject *)((char *)v0059 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL)));
    v0141 = cons(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0141 = Lreverse(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0141 = qcdr(v0141);
    stack[-2] = v0141;
    v0059 = qvalue(elt(env, 1)); // nil
    v0142 = stack[-1];
    v0141 = (LispObject)17; // 1
    v0141 = *(LispObject *)((char *)v0142 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL)));
    v0141 = cons(v0059, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0141 = Lreverse(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0141 = qcdr(v0141);
    stack[-1] = v0141;
    goto v0145;

v0145:
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    if (v0141 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    if (v0141 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0141 = stack[-2];
    v0142 = qcar(v0141);
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = (LispObject)lessp2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-3];
    if (v0141 == nil) goto v0062;
    v0141 = (LispObject)17; // 1
    stack[0] = v0141;
    v0141 = qvalue(elt(env, 1)); // nil
    v0141 = ncons(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[-2] = v0141;
    goto v0145;

v0062:
    v0141 = stack[-2];
    v0142 = qcar(v0141);
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = (LispObject)greaterp2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-3];
    if (v0141 == nil) goto v0060;
    v0141 = (LispObject)-15; // -1
    stack[0] = v0141;
    v0141 = qvalue(elt(env, 1)); // nil
    v0141 = ncons(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[-2] = v0141;
    goto v0145;

v0060:
    v0141 = stack[-2];
    v0141 = qcdr(v0141);
    stack[-2] = v0141;
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    stack[-1] = v0141;
    goto v0145;

v0116:
    v0141 = (LispObject)-15; // -1
    stack[0] = v0141;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0110:
    v0141 = (LispObject)17; // 1
    stack[0] = v0141;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }
// error exit handlers
v0144:
    popv(4);
    return nil;
}



// Code for smemberlp

static LispObject CC_smemberlp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0151, v0152;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemberlp");
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

v0153:
    v0151 = stack[0];
    if (v0151 == nil) goto v0020;
    v0151 = stack[0];
    if (!consp(v0151)) goto v0110;
    v0152 = stack[-1];
    v0151 = stack[0];
    v0151 = qcar(v0151);
    v0151 = CC_smemberlp(env, v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    if (!(v0151 == nil)) { popv(3); return onevalue(v0151); }
    v0152 = stack[-1];
    v0151 = stack[0];
    v0151 = qcdr(v0151);
    stack[-1] = v0152;
    stack[0] = v0151;
    goto v0153;

v0110:
    v0152 = stack[0];
    v0151 = stack[-1];
    v0151 = Lmember(nil, v0152, v0151);
    { popv(3); return onevalue(v0151); }

v0020:
    v0151 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0151); }
// error exit handlers
v0078:
    popv(3);
    return nil;
}



// Code for lambdafun

static LispObject CC_lambdafun(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0013;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambdafun");
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
    v0013 = v0000;
// end of prologue
    v0013 = Lreverse(nil, v0013);
    errexit();
    v0013 = qcar(v0013);
    return onevalue(v0013);
}



// Code for setdmode

static LispObject CC_setdmode(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0167, v0168, v0169;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setdmode");
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
    v0167 = stack[-2];
    if (!symbolp(v0167)) v0167 = nil;
    else { v0167 = qfastgets(v0167);
           if (v0167 != nil) { v0167 = elt(v0167, 8); // dname
#ifdef RECORD_GET
             if (v0167 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0167 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0167 == SPID_NOPROP) v0167 = nil; }}
#endif
    stack[0] = v0167;
    if (v0167 == nil) goto v0148;
    v0167 = stack[0];
    stack[-2] = v0167;
    goto v0148;

v0148:
    v0168 = stack[-2];
    v0167 = elt(env, 1); // complex!-rational
    if (v0168 == v0167) goto v0170;
    v0168 = stack[-2];
    v0167 = elt(env, 5); // complex!-rounded
    if (v0168 == v0167) goto v0079;
    v0168 = stack[-2];
    v0167 = elt(env, 7); // tag
    v0167 = get(v0168, v0167);
    env = stack[-4];
    if (!(v0167 == nil)) goto v0171;
    stack[-3] = elt(env, 8); // poly
    stack[0] = (LispObject)81; // 5
    v0169 = elt(env, 9); // "Domain mode error:"
    v0168 = stack[-2];
    v0167 = elt(env, 10); // "is not a domain mode"
    v0167 = list3(v0169, v0168, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    fn = elt(env, 14); // rerror
    v0167 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0167);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    goto v0171;

v0171:
    v0168 = stack[-2];
    v0167 = elt(env, 11); // package!-name
    v0167 = get(v0168, v0167);
    env = stack[-4];
    stack[0] = v0167;
    if (v0167 == nil) goto v0173;
    v0167 = stack[0];
    fn = elt(env, 15); // load!-package
    v0167 = (*qfn1(fn))(qenv(fn), v0167);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    goto v0173;

v0173:
    v0168 = stack[-2];
    v0167 = elt(env, 3); // complex
    if (v0168 == v0167) goto v0174;
    v0167 = qvalue(elt(env, 13)); // !*complex
    goto v0175;

v0175:
    if (v0167 == nil) goto v0176;
    v0168 = stack[-2];
    v0167 = stack[-1];
    {
        popv(5);
        fn = elt(env, 16); // setcmpxmode
        return (*qfn2(fn))(qenv(fn), v0168, v0167);
    }

v0176:
    v0168 = stack[-2];
    v0167 = stack[-1];
    {
        popv(5);
        fn = elt(env, 17); // setdmode1
        return (*qfn2(fn))(qenv(fn), v0168, v0167);
    }

v0174:
    v0167 = qvalue(elt(env, 12)); // t
    goto v0175;

v0079:
    v0167 = qvalue(elt(env, 2)); // dmode!*
    stack[0] = v0167;
    if (v0167 == nil) goto v0123;
    v0167 = stack[0];
    if (!symbolp(v0167)) v0167 = nil;
    else { v0167 = qfastgets(v0167);
           if (v0167 != nil) { v0167 = elt(v0167, 8); // dname
#ifdef RECORD_GET
             if (v0167 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0167 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0167 == SPID_NOPROP) v0167 = nil; }}
#endif
    stack[0] = v0167;
    goto v0123;

v0123:
    v0168 = elt(env, 3); // complex
    v0167 = stack[-1];
    fn = elt(env, 18); // onoff
    v0167 = (*qfn2(fn))(qenv(fn), v0168, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    v0168 = elt(env, 6); // rounded
    v0167 = stack[-1];
    fn = elt(env, 18); // onoff
    v0167 = (*qfn2(fn))(qenv(fn), v0168, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0170:
    v0167 = qvalue(elt(env, 2)); // dmode!*
    stack[0] = v0167;
    if (v0167 == nil) goto v0139;
    v0167 = stack[0];
    if (!symbolp(v0167)) v0167 = nil;
    else { v0167 = qfastgets(v0167);
           if (v0167 != nil) { v0167 = elt(v0167, 8); // dname
#ifdef RECORD_GET
             if (v0167 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0167 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0167 == SPID_NOPROP) v0167 = nil; }}
#endif
    stack[0] = v0167;
    goto v0139;

v0139:
    v0168 = elt(env, 3); // complex
    v0167 = stack[-1];
    fn = elt(env, 18); // onoff
    v0167 = (*qfn2(fn))(qenv(fn), v0168, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    v0168 = elt(env, 4); // rational
    v0167 = stack[-1];
    fn = elt(env, 18); // onoff
    v0167 = (*qfn2(fn))(qenv(fn), v0168, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    { LispObject res = stack[0]; popv(5); return onevalue(res); }
// error exit handlers
v0172:
    popv(5);
    return nil;
}



// Code for random

static LispObject CC_random(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0141, v0142;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for random");
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
    v0141 = stack[-3];
    if (is_number(v0141)) goto v0189;
    v0141 = qvalue(elt(env, 1)); // t
    goto v0091;

v0091:
    if (v0141 == nil) goto v0013;
    v0142 = stack[-3];
    v0141 = elt(env, 2); // "positive number"
    fn = elt(env, 6); // typerr
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    goto v0013;

v0013:
    v0141 = stack[-3];
    v0141 = Lfloatp(nil, v0141);
    env = stack[-5];
    if (v0141 == nil) goto v0135;
    fn = elt(env, 7); // next!-random!-number
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0142 = Lfloat(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0141 = qvalue(elt(env, 3)); // unidev_fac!*
    v0141 = times2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    stack[-2] = v0141;
    fn = elt(env, 7); // next!-random!-number
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0142 = Lfloat(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0141 = stack[-2];
    stack[0] = plus2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0142 = qvalue(elt(env, 3)); // unidev_fac!*
    v0141 = stack[-3];
    v0141 = times2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    {
        LispObject v0190 = stack[0];
        popv(6);
        return times2(v0190, v0141);
    }

v0135:
    fn = elt(env, 7); // next!-random!-number
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    stack[-2] = v0141;
    v0141 = qvalue(elt(env, 4)); // randommodulus!*
    stack[-4] = v0141;
    goto v0191;

v0191:
    v0142 = stack[-4];
    v0141 = stack[-3];
    v0141 = (LispObject)lessp2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-5];
    if (v0141 == nil) goto v0157;
    v0142 = stack[-4];
    v0141 = qvalue(elt(env, 4)); // randommodulus!*
    v0141 = times2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    stack[-4] = v0141;
    v0142 = qvalue(elt(env, 4)); // randommodulus!*
    v0141 = stack[-2];
    stack[0] = times2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    fn = elt(env, 7); // next!-random!-number
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0141 = plus2(stack[0], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    stack[-2] = v0141;
    goto v0191;

v0157:
    stack[-1] = stack[-2];
    stack[0] = stack[-4];
    v0142 = stack[-4];
    v0141 = stack[-3];
    v0141 = Cremainder(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0141 = difference2(stack[0], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0141 = (LispObject)lessp2(stack[-1], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-5];
    if (v0141 == nil) goto v0135;
    v0142 = stack[-2];
    v0141 = stack[-3];
    popv(6);
    return Cremainder(v0142, v0141);

v0189:
    v0142 = stack[-3];
    v0141 = (LispObject)1; // 0
    v0141 = (LispObject)lesseq2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-5];
    goto v0091;
// error exit handlers
v0144:
    popv(6);
    return nil;
}



// Code for factorial

static LispObject CC_factorial(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0165, v0166;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factorial");
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
    v0165 = stack[-1];
    v0165 = integerp(v0165);
    if (v0165 == nil) goto v0194;
    v0166 = stack[-1];
    v0165 = (LispObject)1; // 0
    v0165 = (LispObject)lessp2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    v0165 = v0165 ? lisp_true : nil;
    env = stack[-3];
    goto v0013;

v0013:
    if (v0165 == nil) goto v0195;
    stack[-2] = elt(env, 2); // arith
    stack[0] = (LispObject)65; // 4
    v0166 = stack[-1];
    v0165 = elt(env, 3); // "invalid factorial argument"
    v0165 = list2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    {
        LispObject v0118 = stack[-2];
        LispObject v0196 = stack[0];
        popv(4);
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0118, v0196, v0165);
    }

v0195:
    v0165 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); // nfactorial
        return (*qfn1(fn))(qenv(fn), v0165);
    }

v0194:
    v0165 = qvalue(elt(env, 1)); // t
    goto v0013;
// error exit handlers
v0117:
    popv(4);
    return nil;
}



// Code for assert_install1

static LispObject CC_assert_install1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0128, v0191, v0203;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_install1");
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
    v0191 = stack[0];
    v0128 = elt(env, 1); // assert_installed
    v0128 = get(v0191, v0128);
    env = stack[-1];
    if (v0128 == nil) goto v0137;
    v0191 = elt(env, 2); // "assert already installed for"
    v0128 = stack[0];
    v0128 = list2(v0191, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 8); // lprim
        return (*qfn1(fn))(qenv(fn), v0128);
    }

v0137:
    v0128 = stack[0];
    fn = elt(env, 9); // getd
    v0191 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-1];
    v0128 = elt(env, 3); // expr
    if (!consp(v0191)) goto v0116;
    v0191 = qcar(v0191);
    if (!(v0191 == v0128)) goto v0116;
    v0191 = stack[0];
    v0128 = elt(env, 5); // assert_noassertfn
    v0191 = get(v0191, v0128);
    env = stack[-1];
    v0128 = stack[0];
    fn = elt(env, 10); // copyd
    v0128 = (*qfn2(fn))(qenv(fn), v0191, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-1];
    v0203 = stack[0];
    v0191 = stack[0];
    v0128 = elt(env, 6); // assert_assertfn
    v0128 = get(v0191, v0128);
    env = stack[-1];
    fn = elt(env, 10); // copyd
    v0128 = (*qfn2(fn))(qenv(fn), v0203, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-1];
    v0191 = stack[0];
    v0128 = elt(env, 1); // assert_installed
    v0203 = qvalue(elt(env, 7)); // t
        popv(2);
        return Lputprop(nil, 3, v0191, v0128, v0203);

v0116:
    v0191 = stack[0];
    v0128 = elt(env, 4); // "is not an expr procedure - ignoring assert"
    v0128 = list2(v0191, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 8); // lprim
        return (*qfn1(fn))(qenv(fn), v0128);
    }
// error exit handlers
v0204:
    popv(2);
    return nil;
}



// Code for repeats

static LispObject CC_repeats(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0150, v0195, v0149;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repeats");
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
    v0149 = nil;
    goto v0020;

v0020:
    v0150 = stack[0];
    if (v0150 == nil) goto v0194;
    v0150 = stack[0];
    v0195 = qcar(v0150);
    v0150 = stack[0];
    v0150 = qcdr(v0150);
    v0150 = Lmember(nil, v0195, v0150);
    if (v0150 == nil) goto v0116;
    v0150 = stack[0];
    v0150 = qcar(v0150);
    v0195 = v0149;
    v0150 = cons(v0150, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    v0149 = v0150;
    v0150 = stack[0];
    v0150 = qcdr(v0150);
    stack[0] = v0150;
    goto v0020;

v0116:
    v0150 = stack[0];
    v0150 = qcdr(v0150);
    stack[0] = v0150;
    goto v0020;

v0194:
    v0150 = v0149;
    {
        popv(2);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0150);
    }
// error exit handlers
v0152:
    popv(2);
    return nil;
}



// Code for mod_eval_uni_poly

static LispObject CC_mod_eval_uni_poly(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0210, v0126, v0211;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mod_eval_uni_poly");
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
    v0210 = stack[-2];
    if (!consp(v0210)) goto v0020;
    v0210 = stack[-2];
    v0210 = qcar(v0210);
    v0210 = qcdr(v0210);
    fn = elt(env, 3); // mod!#
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    v0211 = v0210;
    v0210 = stack[-2];
    v0210 = qcar(v0210);
    v0210 = qcar(v0210);
    v0210 = qcdr(v0210);
    v0126 = v0210;
    v0210 = stack[-2];
    v0210 = qcdr(v0210);
    stack[-2] = v0210;
    goto v0080;

v0080:
    v0210 = stack[-2];
    if (!consp(v0210)) goto v0204;
    stack[-3] = v0211;
    stack[0] = stack[-1];
    v0210 = stack[-2];
    v0210 = qcar(v0210);
    v0210 = qcar(v0210);
    v0210 = qcdr(v0210);
    v0210 = difference2(v0126, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    fn = elt(env, 4); // general!-modular!-expt
    v0210 = (*qfn2(fn))(qenv(fn), stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    v0126 = times2(stack[-3], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    v0210 = qvalue(elt(env, 2)); // current!-modulus
    stack[0] = Cremainder(v0126, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    v0210 = stack[-2];
    v0210 = qcar(v0210);
    v0210 = qcdr(v0210);
    fn = elt(env, 3); // mod!#
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    fn = elt(env, 5); // general!-modular!-plus
    v0210 = (*qfn2(fn))(qenv(fn), stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    v0211 = v0210;
    v0210 = stack[-2];
    v0210 = qcar(v0210);
    v0210 = qcar(v0210);
    v0210 = qcdr(v0210);
    v0126 = v0210;
    v0210 = stack[-2];
    v0210 = qcdr(v0210);
    stack[-2] = v0210;
    goto v0080;

v0204:
    stack[0] = v0211;
    v0210 = stack[-1];
    fn = elt(env, 4); // general!-modular!-expt
    v0210 = (*qfn2(fn))(qenv(fn), v0210, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    v0126 = times2(stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    v0210 = qvalue(elt(env, 2)); // current!-modulus
    v0210 = Cremainder(v0126, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    v0211 = v0210;
    v0210 = stack[-2];
    if (v0210 == nil) { popv(5); return onevalue(v0211); }
    stack[0] = v0211;
    v0210 = stack[-2];
    fn = elt(env, 3); // mod!#
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-4];
    fn = elt(env, 5); // general!-modular!-plus
    v0210 = (*qfn2(fn))(qenv(fn), stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    v0211 = v0210;
    { popv(5); return onevalue(v0211); }

v0020:
    v0210 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // mod!#
        return (*qfn1(fn))(qenv(fn), v0210);
    }
// error exit handlers
v0212:
    popv(5);
    return nil;
}



// Code for super_der_simp

static LispObject CC_super_der_simp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0274, v0275, v0276;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for super_der_simp");
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
    v0274 = stack[-9];
    v0275 = Llength(nil, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = (LispObject)33; // 2
    if (v0275 == v0274) goto v0038;
    v0274 = stack[-9];
    {
        popv(12);
        fn = elt(env, 7); // simpiden
        return (*qfn1(fn))(qenv(fn), v0274);
    }

v0038:
    v0274 = stack[-9];
    v0274 = qcar(v0274);
    fn = elt(env, 8); // reval
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-10] = v0274;
    v0275 = stack[-10];
    v0274 = elt(env, 1); // variables
    v0274 = get(v0275, v0274);
    env = stack[-11];
    stack[-8] = v0274;
    v0274 = stack[-9];
    v0274 = qcdr(v0274);
    v0274 = qcar(v0274);
    fn = elt(env, 9); // simp!*
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-9] = v0274;
    v0274 = stack[-9];
    v0275 = qcar(v0274);
    v0274 = elt(env, 2); // (ext)
    fn = elt(env, 10); // split_form
    v0274 = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-7] = v0274;
    v0274 = elt(env, 3); // ext
    v0276 = ncons(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = stack[-7];
    v0275 = qcar(v0274);
    v0274 = stack[-7];
    v0274 = qcdr(v0274);
    v0274 = acons(v0276, v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-7] = v0274;
    v0274 = stack[-9];
    v0275 = qcdr(v0274);
    v0274 = elt(env, 2); // (ext)
    fn = elt(env, 10); // split_form
    v0274 = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-6] = v0274;
    v0274 = elt(env, 3); // ext
    v0276 = ncons(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = stack[-6];
    v0275 = qcar(v0274);
    v0274 = stack[-6];
    v0274 = qcdr(v0274);
    v0274 = acons(v0276, v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-6] = v0274;
    v0274 = (LispObject)17; // 1
    stack[-5] = v0274;
    v0275 = stack[-10];
    v0274 = elt(env, 4); // even_dimension
    v0275 = get(v0275, v0274);
    env = stack[-11];
    v0274 = stack[-5];
    v0274 = difference2(v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = Lminusp(nil, v0274);
    env = stack[-11];
    if (v0274 == nil) goto v0278;
    v0274 = qvalue(elt(env, 5)); // nil
    goto v0191;

v0191:
    stack[-5] = v0274;
    v0274 = (LispObject)17; // 1
    stack[-4] = v0274;
    v0275 = stack[-10];
    v0274 = elt(env, 6); // odd_dimension
    v0275 = get(v0275, v0274);
    env = stack[-11];
    v0274 = stack[-4];
    v0274 = difference2(v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = Lminusp(nil, v0274);
    env = stack[-11];
    if (v0274 == nil) goto v0099;
    v0274 = qvalue(elt(env, 5)); // nil
    goto v0279;

v0279:
    stack[-1] = v0274;
    v0275 = stack[-5];
    v0274 = stack[-7];
    fn = elt(env, 11); // even_action
    stack[0] = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0275 = stack[-1];
    v0274 = stack[-7];
    fn = elt(env, 12); // odd_action
    v0274 = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 13); // addsq
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = stack[-9];
    v0275 = qcdr(v0274);
    v0274 = (LispObject)17; // 1
    v0274 = cons(v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 14); // quotsq
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0275 = stack[-5];
    v0274 = stack[-6];
    fn = elt(env, 11); // even_action
    stack[-1] = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = stack[-9];
    v0275 = qcar(v0274);
    v0274 = (LispObject)17; // 1
    v0274 = cons(v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 15); // super_product_sq
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = stack[-9];
    v0275 = qcdr(v0274);
    v0274 = stack[-9];
    v0274 = qcdr(v0274);
    fn = elt(env, 16); // multf
    v0275 = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = (LispObject)17; // 1
    v0274 = cons(v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 14); // quotsq
    v0274 = (*qfn2(fn))(qenv(fn), stack[-1], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 17); // negsq
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    {
        LispObject v0280 = stack[0];
        popv(12);
        fn = elt(env, 13); // addsq
        return (*qfn2(fn))(qenv(fn), v0280, v0274);
    }

v0099:
    v0276 = stack[-10];
    v0275 = (LispObject)17; // 1
    v0274 = stack[-4];
    v0274 = list3(v0276, v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 9); // simp!*
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[0] = stack[-4];
    v0275 = v0274;
    v0274 = elt(env, 2); // (ext)
    fn = elt(env, 18); // split_ext
    v0274 = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = cons(stack[0], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = ncons(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-2] = v0274;
    stack[-3] = v0274;
    goto v0281;

v0281:
    v0274 = stack[-4];
    v0274 = add1(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-4] = v0274;
    v0275 = stack[-10];
    v0274 = elt(env, 6); // odd_dimension
    v0275 = get(v0275, v0274);
    env = stack[-11];
    v0274 = stack[-4];
    v0274 = difference2(v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = Lminusp(nil, v0274);
    env = stack[-11];
    if (v0274 == nil) goto v0282;
    v0274 = stack[-3];
    goto v0279;

v0282:
    stack[-1] = stack[-2];
    v0276 = stack[-10];
    v0275 = (LispObject)17; // 1
    v0274 = stack[-4];
    v0274 = list3(v0276, v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 9); // simp!*
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[0] = stack[-4];
    v0275 = v0274;
    v0274 = elt(env, 2); // (ext)
    fn = elt(env, 18); // split_ext
    v0274 = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = cons(stack[0], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = ncons(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = Lrplacd(nil, stack[-1], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = stack[-2];
    v0274 = qcdr(v0274);
    stack[-2] = v0274;
    goto v0281;

v0278:
    v0276 = stack[-10];
    v0275 = (LispObject)1; // 0
    v0274 = stack[-5];
    v0274 = list3(v0276, v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 9); // simp!*
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-1] = v0274;
    v0275 = stack[-8];
    v0274 = stack[-5];
    fn = elt(env, 19); // nth
    stack[0] = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0275 = stack[-1];
    v0274 = elt(env, 2); // (ext)
    fn = elt(env, 18); // split_ext
    v0274 = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = cons(stack[0], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = ncons(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-3] = v0274;
    stack[-4] = v0274;
    goto v0203;

v0203:
    v0274 = stack[-5];
    v0274 = add1(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-5] = v0274;
    v0275 = stack[-10];
    v0274 = elt(env, 4); // even_dimension
    v0275 = get(v0275, v0274);
    env = stack[-11];
    v0274 = stack[-5];
    v0274 = difference2(v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = Lminusp(nil, v0274);
    env = stack[-11];
    if (v0274 == nil) goto v0283;
    v0274 = stack[-4];
    goto v0191;

v0283:
    stack[-2] = stack[-3];
    v0276 = stack[-10];
    v0275 = (LispObject)1; // 0
    v0274 = stack[-5];
    v0274 = list3(v0276, v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 9); // simp!*
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-1] = v0274;
    v0275 = stack[-8];
    v0274 = stack[-5];
    fn = elt(env, 19); // nth
    stack[0] = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0275 = stack[-1];
    v0274 = elt(env, 2); // (ext)
    fn = elt(env, 18); // split_ext
    v0274 = (*qfn2(fn))(qenv(fn), v0275, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = cons(stack[0], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = ncons(v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = Lrplacd(nil, stack[-2], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0274 = stack[-3];
    v0274 = qcdr(v0274);
    stack[-3] = v0274;
    goto v0203;
// error exit handlers
v0277:
    popv(12);
    return nil;
}



// Code for formrlis

static LispObject CC_formrlis(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0268, v0125, v0286;
    LispObject fn;
    LispObject v0181, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formrlis");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0181 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formrlis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0181,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0181);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0268 = v0181;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0268 = stack[-2];
    v0125 = qcar(v0268);
    v0268 = elt(env, 1); // flagop
    v0268 = Lflagp(nil, v0125, v0268);
    env = stack[-4];
    if (v0268 == nil) goto v0147;
    v0268 = stack[-2];
    v0268 = qcdr(v0268);
    fn = elt(env, 8); // idlistp
    v0268 = (*qfn1(fn))(qenv(fn), v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    if (v0268 == nil) goto v0207;
    stack[-3] = elt(env, 7); // flag
    stack[0] = elt(env, 2); // list
    v0268 = stack[-2];
    v0286 = qcdr(v0268);
    v0125 = stack[-1];
    v0268 = elt(env, 4); // algebraic
    fn = elt(env, 9); // formlis
    v0268 = (*qfnn(fn))(qenv(fn), 3, v0286, v0125, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    stack[0] = cons(stack[0], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    v0268 = stack[-2];
    v0268 = qcar(v0268);
    v0268 = Lmkquote(nil, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    {
        LispObject v0267 = stack[-3];
        LispObject v0061 = stack[0];
        popv(5);
        return list3(v0267, v0061, v0268);
    }

v0207:
    v0125 = elt(env, 5); // !*comma!*
    v0268 = stack[-2];
    v0268 = qcdr(v0268);
    v0125 = cons(v0125, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    v0268 = elt(env, 6); // "identifier list"
    {
        popv(5);
        fn = elt(env, 10); // typerr
        return (*qfn2(fn))(qenv(fn), v0125, v0268);
    }

v0147:
    v0268 = stack[-2];
    stack[-3] = qcar(v0268);
    stack[0] = elt(env, 2); // list
    v0268 = stack[-2];
    v0125 = qcar(v0268);
    v0268 = elt(env, 3); // share
    if (v0125 == v0268) goto v0138;
    v0268 = stack[-2];
    v0286 = qcdr(v0268);
    v0125 = stack[-1];
    v0268 = elt(env, 4); // algebraic
    fn = elt(env, 9); // formlis
    v0268 = (*qfnn(fn))(qenv(fn), 3, v0286, v0125, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    goto v0086;

v0086:
    v0268 = cons(stack[0], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    {
        LispObject v0287 = stack[-3];
        popv(5);
        return list2(v0287, v0268);
    }

v0138:
    stack[-1] = nil;
    v0268 = stack[-2];
    v0268 = qcdr(v0268);
    stack[-2] = v0268;
    goto v0079;

v0079:
    v0268 = stack[-2];
    if (v0268 == nil) goto v0208;
    v0268 = stack[-2];
    v0268 = qcar(v0268);
    v0125 = Lmkquote(nil, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    v0268 = stack[-1];
    v0268 = cons(v0125, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    stack[-1] = v0268;
    v0268 = stack[-2];
    v0268 = qcdr(v0268);
    stack[-2] = v0268;
    goto v0079;

v0208:
    v0268 = stack[-1];
    fn = elt(env, 11); // reversip!*
    v0268 = (*qfn1(fn))(qenv(fn), v0268);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    goto v0086;
// error exit handlers
v0266:
    popv(5);
    return nil;
}



// Code for simpcv

static LispObject CC_simpcv(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0135, v0133;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpcv");
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
    v0135 = stack[-1];
    v0133 = Llength(nil, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0135 = (LispObject)49; // 3
    if (v0133 == v0135) goto v0085;
    v0133 = elt(env, 1); // "Invalid number of edges in vertex"
    v0135 = stack[-1];
    v0135 = list2(v0133, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); // cerror
        return (*qfn1(fn))(qenv(fn), v0135);
    }

v0085:
    v0133 = elt(env, 2); // simpcgraph
    v0135 = qvalue(elt(env, 3)); // mul!*
    v0135 = Lmemq(nil, v0133, v0135);
    if (!(v0135 == nil)) goto v0199;
    v0133 = qvalue(elt(env, 3)); // mul!*
    v0135 = elt(env, 2); // simpcgraph
    fn = elt(env, 5); // aconc!*
    v0135 = (*qfn2(fn))(qenv(fn), v0133, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0135; // mul!*
    goto v0199;

v0199:
    v0133 = stack[0];
    v0135 = stack[-1];
    v0133 = cons(v0133, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0135 = (LispObject)17; // 1
    fn = elt(env, 6); // to
    v0133 = (*qfn2(fn))(qenv(fn), v0133, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0135 = (LispObject)17; // 1
    v0135 = cons(v0133, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0133 = ncons(v0135);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    v0135 = (LispObject)17; // 1
    popv(3);
    return cons(v0133, v0135);
// error exit handlers
v0271:
    popv(3);
    return nil;
}



// Code for matrixrowom

static LispObject CC_matrixrowom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0137;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixrowom");
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
    v0137 = stack[0];
    if (v0137 == nil) goto v0020;
    v0137 = elt(env, 1); // "<OMA>"
    fn = elt(env, 6); // printout
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    v0137 = qvalue(elt(env, 2)); // t
    fn = elt(env, 7); // indent!*
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    v0137 = elt(env, 3); // "<OMS cd=""linalg1"" name=""matrixrow""/>"
    fn = elt(env, 6); // printout
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    v0137 = stack[0];
    v0137 = qcar(v0137);
    fn = elt(env, 8); // multiom
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    v0137 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 7); // indent!*
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    v0137 = elt(env, 5); // "</OMA>"
    fn = elt(env, 6); // printout
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    v0137 = stack[0];
    v0137 = qcdr(v0137);
    v0137 = CC_matrixrowom(env, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    goto v0020;

v0020:
    v0137 = nil;
    { popv(2); return onevalue(v0137); }
// error exit handlers
v0080:
    popv(2);
    return nil;
}



// Code for ft!:zerop

static LispObject CC_ftTzerop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0151, v0152;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ft:zerop");
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
    v0151 = v0000;
// end of prologue
    stack[0] = v0151;
    v0152 = (LispObject)161; // 10
    v0151 = qvalue(elt(env, 1)); // !:prec!:
    v0151 = Lexpt(nil, v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-1];
    v0151 = times2(stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-1];
    stack[0] = v0151;
    v0152 = stack[0];
    v0151 = (LispObject)-799; // -50
    v0151 = (LispObject)greaterp2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    v0151 = v0151 ? lisp_true : nil;
    env = stack[-1];
    if (v0151 == nil) goto v0112;
    v0152 = stack[0];
    v0151 = (LispObject)801; // 50
        popv(2);
        return Llessp(nil, v0152, v0151);

v0112:
    v0151 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0151); }
// error exit handlers
v0166:
    popv(2);
    return nil;
}



// Code for freeoff

static LispObject CC_freeoff(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0288, v0289;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeoff");
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

v0020:
    v0288 = stack[-1];
    if (!consp(v0288)) goto v0110;
    v0288 = stack[-1];
    v0288 = qcar(v0288);
    v0288 = (consp(v0288) ? nil : lisp_true);
    goto v0091;

v0091:
    if (v0288 == nil) goto v0290;
    v0288 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0288); }

v0290:
    v0288 = stack[-1];
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    fn = elt(env, 3); // sfp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-2];
    if (v0288 == nil) goto v0074;
    v0288 = stack[-1];
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[0];
    v0288 = CC_freeoff(env, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-2];
    if (v0288 == nil) goto v0187;
    v0288 = stack[-1];
    v0288 = qcar(v0288);
    v0289 = qcdr(v0288);
    v0288 = stack[0];
    v0288 = CC_freeoff(env, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-2];
    if (v0288 == nil) goto v0209;
    v0288 = stack[-1];
    v0288 = qcdr(v0288);
    stack[-1] = v0288;
    goto v0020;

v0209:
    v0288 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0288); }

v0187:
    v0288 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0288); }

v0074:
    v0288 = stack[-1];
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    v0289 = qcar(v0288);
    v0288 = stack[0];
    fn = elt(env, 4); // ndepends
    v0288 = (*qfn2(fn))(qenv(fn), v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-2];
    if (v0288 == nil) goto v0203;
    v0288 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0288); }

v0203:
    v0288 = stack[-1];
    v0288 = qcar(v0288);
    v0289 = qcdr(v0288);
    v0288 = stack[0];
    v0288 = CC_freeoff(env, v0289, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-2];
    if (v0288 == nil) goto v0071;
    v0288 = stack[-1];
    v0288 = qcdr(v0288);
    stack[-1] = v0288;
    goto v0020;

v0071:
    v0288 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0288); }

v0110:
    v0288 = qvalue(elt(env, 1)); // t
    goto v0091;
// error exit handlers
v0066:
    popv(3);
    return nil;
}



// Code for oprinla

static LispObject CC_oprinla(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0151, v0152, v0165;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oprinla");
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
    v0152 = v0000;
// end of prologue
    v0165 = v0152;
    v0151 = elt(env, 1); // lapr
    v0151 = get(v0165, v0151);
    env = stack[0];
    v0165 = v0151;
    if (v0151 == nil) goto v0194;
    v0151 = v0165;
    fn = elt(env, 4); // prin2la
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    goto v0004;

v0004:
    v0151 = nil;
    { popv(1); return onevalue(v0151); }

v0194:
    v0151 = v0152;
    if (!symbolp(v0151)) v0151 = nil;
    else { v0151 = qfastgets(v0151);
           if (v0151 != nil) { v0151 = elt(v0151, 37); // prtch
#ifdef RECORD_GET
             if (v0151 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0151 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0151 == SPID_NOPROP) v0151 = nil; }}
#endif
    v0165 = v0151;
    if (v0151 == nil) goto v0080;
    v0151 = v0165;
    fn = elt(env, 4); // prin2la
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    goto v0004;

v0080:
    v0165 = v0152;
    v0151 = elt(env, 2); // lapop
    v0151 = get(v0165, v0151);
    env = stack[0];
    v0165 = v0151;
    if (v0151 == nil) goto v0192;
    v0151 = v0165;
    fn = elt(env, 4); // prin2la
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[0];
    v0151 = elt(env, 3); // ! 
    fn = elt(env, 4); // prin2la
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    goto v0004;

v0192:
    v0151 = v0152;
    fn = elt(env, 5); // prinlatom
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    goto v0004;
// error exit handlers
v0166:
    popv(1);
    return nil;
}



// Code for physopordchk!*

static LispObject CC_physopordchkH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0287, v0291;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopordchk*");
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

v0153:
    v0287 = stack[-1];
    v0287 = qcar(v0287);
    stack[-4] = v0287;
    v0287 = stack[-1];
    v0287 = qcdr(v0287);
    stack[-1] = v0287;
    v0287 = stack[-1];
    if (v0287 == nil) goto v0096;
    v0287 = stack[-4];
    v0291 = ncons(v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0287 = stack[0];
    v0287 = CC_physopordchkH(env, v0291, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    if (v0287 == nil) goto v0292;
    v0291 = stack[-1];
    v0287 = stack[0];
    stack[-1] = v0291;
    stack[0] = v0287;
    goto v0153;

v0292:
    v0287 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0287); }

v0096:
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    if (v0287 == nil) goto v0080;
    v0287 = stack[0];
    stack[-3] = v0287;
    v0287 = stack[-3];
    if (v0287 == nil) goto v0186;
    v0287 = stack[-3];
    v0287 = qcar(v0287);
    v0291 = stack[-4];
    fn = elt(env, 3); // ncmpchk
    v0287 = (*qfn2(fn))(qenv(fn), v0291, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0287 = ncons(v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    stack[-1] = v0287;
    stack[-2] = v0287;
    goto v0122;

v0122:
    v0287 = stack[-3];
    v0287 = qcdr(v0287);
    stack[-3] = v0287;
    v0287 = stack[-3];
    if (v0287 == nil) goto v0285;
    stack[0] = stack[-1];
    v0287 = stack[-3];
    v0287 = qcar(v0287);
    v0291 = stack[-4];
    fn = elt(env, 3); // ncmpchk
    v0287 = (*qfn2(fn))(qenv(fn), v0291, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0287 = ncons(v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0287 = Lrplacd(nil, stack[0], v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0287 = stack[-1];
    v0287 = qcdr(v0287);
    stack[-1] = v0287;
    goto v0122;

v0285:
    v0287 = stack[-2];
    goto v0293;

v0293:
    v0291 = qvalue(elt(env, 1)); // nil
    v0287 = Lmember(nil, v0291, v0287);
    if (v0287 == nil) goto v0171;
    v0287 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0287); }

v0171:
    v0287 = qvalue(elt(env, 2)); // t
    { popv(6); return onevalue(v0287); }

v0186:
    v0287 = qvalue(elt(env, 1)); // nil
    goto v0293;

v0080:
    v0291 = stack[-4];
    v0287 = stack[0];
    v0287 = qcar(v0287);
    fn = elt(env, 3); // ncmpchk
    v0287 = (*qfn2(fn))(qenv(fn), v0291, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    if (v0287 == nil) goto v0111;
    v0287 = stack[-4];
    fn = elt(env, 4); // invp
    v0291 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = (equal(v0291, v0287) ? lisp_true : nil);
    v0287 = (v0287 == nil ? lisp_true : nil);
    { popv(6); return onevalue(v0287); }

v0111:
    v0287 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0287); }
// error exit handlers
v0059:
    popv(6);
    return nil;
}



// Code for fieldconv

static LispObject CC_fieldconv(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0304, v0305, v0306;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fieldconv");
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
    v0304 = stack[-1];
    v0304 = qcar(v0304);
    stack[-3] = v0304;
    v0304 = stack[-1];
    v0304 = qcdr(v0304);
    stack[0] = v0304;
    v0304 = qvalue(elt(env, 1)); // dmode!*
    if (v0304 == nil) goto v0112;
    v0304 = stack[0];
    if (!consp(v0304)) goto v0264;
    v0304 = stack[0];
    v0304 = qcar(v0304);
    v0304 = (consp(v0304) ? nil : lisp_true);
    goto v0055;

v0055:
    if (v0304 == nil) goto v0281;
    v0305 = stack[-3];
    v0304 = stack[0];
    fn = elt(env, 6); // divd
    v0305 = (*qfn2(fn))(qenv(fn), v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    v0304 = (LispObject)17; // 1
    popv(5);
    return cons(v0305, v0304);

v0281:
    v0305 = stack[-3];
    v0304 = stack[-2];
    fn = elt(env, 6); // divd
    stack[-1] = (*qfn2(fn))(qenv(fn), v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    v0305 = stack[0];
    v0304 = stack[-2];
    fn = elt(env, 6); // divd
    v0304 = (*qfn2(fn))(qenv(fn), v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    {
        LispObject v0308 = stack[-1];
        popv(5);
        return cons(v0308, v0304);
    }

v0264:
    v0304 = qvalue(elt(env, 5)); // t
    goto v0055;

v0112:
    v0305 = stack[-2];
    v0304 = elt(env, 2); // !:rn!:
    if (!consp(v0305)) goto v0115;
    v0305 = qcar(v0305);
    if (!(v0305 == v0304)) goto v0115;

v0065:
    v0304 = stack[-2];
    v0306 = qcar(v0304);
    v0304 = stack[-2];
    v0304 = qcdr(v0304);
    v0305 = qcdr(v0304);
    v0304 = stack[-2];
    v0304 = qcdr(v0304);
    v0304 = qcar(v0304);
    v0304 = list2star(v0306, v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    stack[-2] = v0304;
    v0304 = stack[0];
    if (!consp(v0304)) goto v0175;
    v0304 = stack[0];
    v0304 = qcar(v0304);
    v0304 = (consp(v0304) ? nil : lisp_true);
    goto v0063;

v0063:
    if (v0304 == nil) goto v0168;
    v0305 = stack[-2];
    v0304 = stack[-3];
    fn = elt(env, 7); // multd
    v0305 = (*qfn2(fn))(qenv(fn), v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    v0304 = (LispObject)17; // 1
    v0304 = cons(v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    goto v0309;

v0309:
    {
        popv(5);
        fn = elt(env, 8); // simpgd
        return (*qfn1(fn))(qenv(fn), v0304);
    }

v0168:
    v0305 = stack[-2];
    v0304 = stack[-3];
    fn = elt(env, 7); // multd
    stack[-1] = (*qfn2(fn))(qenv(fn), v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    v0305 = stack[-2];
    v0304 = stack[0];
    fn = elt(env, 7); // multd
    v0304 = (*qfn2(fn))(qenv(fn), v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    v0304 = cons(stack[-1], v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    goto v0309;

v0175:
    v0304 = qvalue(elt(env, 5)); // t
    goto v0063;

v0115:
    v0304 = stack[-2];
    v0305 = qcar(v0304);
    v0304 = elt(env, 2); // !:rn!:
    v0304 = get(v0305, v0304);
    env = stack[-4];
    v0305 = v0304;
    if (v0304 == nil) goto v0121;
    v0304 = v0305;
    if (!(!consp(v0304))) goto v0121;
    v0304 = stack[-2];
    v0304 = Lapply1(nil, v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    stack[-2] = v0304;
    goto v0065;

v0121:
    v0304 = stack[-2];
    v0305 = qcar(v0304);
    v0304 = elt(env, 3); // quotient
    v0304 = get(v0305, v0304);
    env = stack[-4];
    if (v0304 == nil) goto v0159;
    v0306 = (LispObject)17; // 1
    v0305 = stack[-2];
    v0304 = elt(env, 3); // quotient
    fn = elt(env, 9); // dcombine
    v0304 = (*qfnn(fn))(qenv(fn), 3, v0306, v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    stack[-2] = v0304;
    v0305 = stack[-2];
    v0304 = stack[-1];
    v0304 = qcar(v0304);
    fn = elt(env, 7); // multd
    stack[0] = (*qfn2(fn))(qenv(fn), v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    v0305 = stack[-2];
    v0304 = stack[-1];
    v0304 = qcdr(v0304);
    fn = elt(env, 7); // multd
    v0304 = (*qfn2(fn))(qenv(fn), v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    {
        LispObject v0310 = stack[0];
        popv(5);
        return cons(v0310, v0304);
    }

v0159:
    v0305 = elt(env, 4); // "field conversion"
    v0304 = stack[-2];
    v0304 = list2(v0305, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    fn = elt(env, 10); // errach
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-4];
    goto v0065;
// error exit handlers
v0307:
    popv(5);
    return nil;
}



// Code for reduce!-mod!-p!*

static LispObject CC_reduceKmodKpH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0013, v0194;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-p*");
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
    v0013 = v0001;
    v0194 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // current!-modulus
    qvalue(elt(env, 1)) = v0013; // current!-modulus
    v0013 = v0194;
    fn = elt(env, 2); // general!-reduce!-mod!-p
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // current!-modulus
    { popv(2); return onevalue(v0013); }
// error exit handlers
v0188:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // current!-modulus
    popv(2);
    return nil;
}



// Code for gcref_remprops

static LispObject CC_gcref_remprops(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0200, v0273, v0132;
    LispObject fn;
    argcheck(nargs, 0, "gcref_remprops");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcref_remprops");
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
    v0273 = qvalue(elt(env, 1)); // seen!*
    v0200 = elt(env, 2); // (gall calls globs calledby alsois sameas)
    fn = elt(env, 13); // rempropss
    v0200 = (*qfn2(fn))(qenv(fn), v0273, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[0];
    v0273 = qvalue(elt(env, 1)); // seen!*
    v0200 = elt(env, 3); // (seen cinthis defd)
    fn = elt(env, 14); // remflagss
    v0200 = (*qfn2(fn))(qenv(fn), v0273, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[0];
    v0273 = qvalue(elt(env, 4)); // gcref_exportl!*
    v0200 = elt(env, 5); // (exported)
    fn = elt(env, 14); // remflagss
    v0200 = (*qfn2(fn))(qenv(fn), v0273, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[0];
    v0273 = qvalue(elt(env, 6)); // gseen!*
    v0200 = elt(env, 7); // (usedby usedunby boundby setby)
    fn = elt(env, 13); // rempropss
    v0200 = (*qfn2(fn))(qenv(fn), v0273, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[0];
    v0273 = qvalue(elt(env, 6)); // gseen!*
    v0200 = elt(env, 8); // (dclglb gseen glb2rf glb2bd glb2st)
    fn = elt(env, 14); // remflagss
    v0200 = (*qfn2(fn))(qenv(fn), v0273, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[0];
    v0200 = qvalue(elt(env, 9)); // tseen!*
    v0132 = v0200;
    goto v0152;

v0152:
    v0200 = v0132;
    if (v0200 == nil) goto v0151;
    v0200 = v0132;
    v0200 = qcar(v0200);
    v0273 = qcar(v0200);
    v0200 = elt(env, 11); // funs
    v0200 = Lremprop(nil, v0273, v0200);
    env = stack[0];
    v0200 = v0132;
    v0200 = qcdr(v0200);
    v0132 = v0200;
    goto v0152;

v0151:
    v0200 = qvalue(elt(env, 10)); // nil
    qvalue(elt(env, 9)) = v0200; // tseen!*
    qvalue(elt(env, 1)) = v0200; // seen!*
    qvalue(elt(env, 6)) = v0200; // gseen!*
    qvalue(elt(env, 12)) = v0200; // haveargs!*
    { popv(1); return onevalue(v0200); }
// error exit handlers
v0164:
    popv(1);
    return nil;
}



// Code for ofsf_smmkatl

static LispObject CC_ofsf_smmkatl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0117, v0118, v0196, v0208;
    LispObject fn;
    LispObject v0031, v0181, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smmkatl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0181 = va_arg(aa, LispObject);
    v0031 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0031,v0181,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0181,v0031);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0117 = v0031;
    stack[0] = v0181;
    v0118 = v0001;
    v0208 = v0000;
// end of prologue
    v0196 = qvalue(elt(env, 1)); // !*rlsippatl
    if (v0196 == nil) goto v0192;
    stack[-1] = v0208;
    v0196 = v0118;
    v0118 = stack[0];
    fn = elt(env, 2); // ofsf_smmkatl1
    v0118 = (*qfnn(fn))(qenv(fn), 4, v0208, v0196, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    v0117 = stack[0];
    {
        LispObject v0122 = stack[-1];
        popv(3);
        fn = elt(env, 3); // ofsf_sippatl
        return (*qfnn(fn))(qenv(fn), 3, v0122, v0118, v0117);
    }

v0192:
    v0196 = v0118;
    v0118 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); // ofsf_smmkatl1
        return (*qfnn(fn))(qenv(fn), 4, v0208, v0196, v0118, v0117);
    }
// error exit handlers
v0121:
    popv(3);
    return nil;
}



// Code for vsl_subatsq

static LispObject CC_vsl_subatsq(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0086, v0085, v0146, v0139;
    LispObject fn;
    LispObject v0181, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vsl_subatsq");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0181 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vsl_subatsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0181,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0181);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0085 = v0181;
    v0146 = v0001;
    v0139 = v0000;
// end of prologue
    v0086 = v0139;
    stack[0] = qcar(v0086);
    v0086 = v0139;
    v0086 = qcdr(v0086);
    v0086 = qcar(v0086);
    fn = elt(env, 2); // ofsf_subf
    v0086 = (*qfnn(fn))(qenv(fn), 3, v0086, v0146, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    v0086 = qcar(v0086);
    v0085 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0115 = stack[0];
        popv(2);
        return list3(v0115, v0086, v0085);
    }
// error exit handlers
v0138:
    popv(2);
    return nil;
}



// Code for unaryir

static LispObject CC_unaryir(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0192, v0150;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unaryir");
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
    v0150 = qvalue(elt(env, 1)); // atts
    v0192 = elt(env, 2); // name
    fn = elt(env, 4); // find
    v0192 = (*qfn2(fn))(qenv(fn), v0150, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    v0192 = Lintern(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    stack[-2] = v0192;
    v0150 = qvalue(elt(env, 1)); // atts
    v0192 = elt(env, 3); // cd
    fn = elt(env, 4); // find
    v0192 = (*qfn2(fn))(qenv(fn), v0150, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    v0192 = Lintern(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-3];
    v0150 = v0192;
    v0192 = stack[-1];
    if (equal(v0150, v0192)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0192 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); // encodeir
        return (*qfn1(fn))(qenv(fn), v0192);
    }
// error exit handlers
v0152:
    popv(4);
    return nil;
}



// Code for atomlis

static LispObject CC_atomlis(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0112, v0076;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for atomlis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0112 = v0000;
// end of prologue

v0153:
    v0076 = v0112;
    if (v0076 == nil) goto v0038;
    v0076 = v0112;
    v0076 = qcar(v0076);
    if (!consp(v0076)) goto v0110;
    v0112 = qvalue(elt(env, 2)); // nil
    return onevalue(v0112);

v0110:
    v0112 = qcdr(v0112);
    goto v0153;

v0038:
    v0112 = qvalue(elt(env, 1)); // t
    return onevalue(v0112);
}



// Code for rootextractsq

static LispObject CC_rootextractsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0137, v0303;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rootextractsq");
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
    v0303 = v0000;
// end of prologue
    v0137 = v0303;
    v0137 = qcar(v0137);
    if (v0137 == nil) { popv(3); return onevalue(v0303); }
    v0137 = v0303;
    fn = elt(env, 1); // subs2q
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    stack[-1] = v0137;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    fn = elt(env, 2); // rootextractf
    stack[0] = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    v0137 = stack[-1];
    v0137 = qcdr(v0137);
    fn = elt(env, 2); // rootextractf
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    {
        LispObject v0146 = stack[0];
        popv(3);
        return cons(v0146, v0137);
    }
// error exit handlers
v0085:
    popv(3);
    return nil;
}



// Code for extract_dummy_ids

static LispObject CC_extract_dummy_ids(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0192, v0150, v0195;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extract_dummy_ids");
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
    v0195 = nil;
    goto v0020;

v0020:
    v0192 = stack[0];
    if (v0192 == nil) goto v0194;
    v0192 = stack[0];
    v0150 = qcar(v0192);
    v0192 = qvalue(elt(env, 1)); // dummy_id!*
    v0192 = Lmemq(nil, v0150, v0192);
    if (v0192 == nil) goto v0115;
    v0192 = stack[0];
    v0192 = qcar(v0192);
    v0150 = v0195;
    v0192 = cons(v0192, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-1];
    v0195 = v0192;
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    stack[0] = v0192;
    goto v0020;

v0115:
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    stack[0] = v0192;
    goto v0020;

v0194:
    v0192 = v0195;
    {
        popv(2);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0192);
    }
// error exit handlers
v0151:
    popv(2);
    return nil;
}



// Code for sc_rep

static LispObject CC_sc_rep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0095;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_rep");
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
    v0095 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // g_sc_ve
    v0095 = sub1(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0095 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0095/(16/CELL)));
    v0095 = qcdr(v0095);
    v0095 = qcar(v0095);
    { popv(1); return onevalue(v0095); }
// error exit handlers
v0170:
    popv(1);
    return nil;
}



// Code for let3

static LispObject CC_let3(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0258, v0315, v0316, v0238, v0241, v0240;
    LispObject fn;
    LispObject v0038, v0031, v0181, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "let3");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0181 = va_arg(aa, LispObject);
    v0031 = va_arg(aa, LispObject);
    v0038 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for let3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0038,v0031,v0181,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0181,v0031,v0038);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-1] = v0038;
    stack[-2] = v0031;
    stack[-3] = v0181;
    stack[-4] = v0001;
    stack[-5] = v0000;
// end of prologue
    v0258 = stack[-5];
    stack[-6] = v0258;
    v0258 = stack[-6];
    if (v0258 == nil) goto v0170;
    v0258 = stack[-6];
    if (is_number(v0258)) goto v0193;
    v0258 = stack[-4];
    fn = elt(env, 6); // getrtype
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-7];
    stack[0] = v0258;
    v0258 = stack[-2];
    if (v0258 == nil) goto v0086;
    v0258 = stack[-6];
    if (!(symbolp(v0258))) goto v0086;
    v0315 = stack[-6];
    v0258 = elt(env, 1); // rtype
    v0258 = Lremprop(nil, v0315, v0258);
    env = stack[-7];
    v0315 = stack[-6];
    v0258 = elt(env, 2); // avalue
    v0258 = Lremprop(nil, v0315, v0258);
    env = stack[-7];
    goto v0086;

v0086:
    v0258 = stack[-6];
    fn = elt(env, 6); // getrtype
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-7];
    v0316 = v0258;
    if (v0258 == nil) goto v0120;
    v0315 = v0316;
    v0258 = elt(env, 3); // typeletfn
    v0258 = get(v0315, v0258);
    env = stack[-7];
    v0315 = v0258;
    if (v0258 == nil) goto v0068;
    stack[-3] = v0315;
    stack[-5] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v0316;
    v0258 = stack[-4];
    fn = elt(env, 6); // getrtype
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-7];
    v0258 = list2(stack[-2], v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-7];
    v0258 = list3star(stack[-5], stack[-1], stack[0], v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-7];
    {
        LispObject v0100 = stack[-3];
        popv(8);
        fn = elt(env, 7); // lispapply
        return (*qfn2(fn))(qenv(fn), v0100, v0258);
    }

v0068:
    stack[-3] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v0316;
    v0258 = stack[-4];
    fn = elt(env, 6); // getrtype
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-7];
    {
        LispObject v0294 = stack[-3];
        LispObject v0317 = stack[-1];
        LispObject v0045 = stack[0];
        LispObject v0098 = stack[-2];
        popv(8);
        fn = elt(env, 8); // typelet
        return (*qfnn(fn))(qenv(fn), 5, v0294, v0317, v0045, v0098, v0258);
    }

v0120:
    v0258 = stack[0];
    if (v0258 == nil) goto v0318;
    v0315 = stack[0];
    v0258 = elt(env, 4); // yetunknowntype
    if (v0315 == v0258) goto v0318;
    v0315 = stack[0];
    v0258 = elt(env, 3); // typeletfn
    v0258 = get(v0315, v0258);
    env = stack[-7];
    v0315 = v0258;
    if (v0258 == nil) goto v0319;
    stack[-3] = v0315;
    stack[-5] = stack[-6];
    stack[-1] = qvalue(elt(env, 5)); // nil
    v0315 = stack[-2];
    v0258 = stack[0];
    v0258 = list2(v0315, v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-7];
    v0258 = list3star(stack[-5], stack[-4], stack[-1], v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-7];
    {
        LispObject v0097 = stack[-3];
        popv(8);
        fn = elt(env, 7); // lispapply
        return (*qfn2(fn))(qenv(fn), v0097, v0258);
    }

v0319:
    v0241 = stack[-6];
    v0238 = stack[-4];
    v0316 = qvalue(elt(env, 5)); // nil
    v0315 = stack[-2];
    v0258 = stack[0];
    {
        popv(8);
        fn = elt(env, 8); // typelet
        return (*qfnn(fn))(qenv(fn), 5, v0241, v0238, v0316, v0315, v0258);
    }

v0318:
    v0240 = stack[-5];
    v0241 = stack[-4];
    v0238 = stack[-3];
    v0316 = stack[-6];
    v0315 = stack[-2];
    v0258 = stack[-1];
    fn = elt(env, 9); // letscalar
    v0258 = (*qfnn(fn))(qenv(fn), 6, v0240, v0241, v0238, v0316, v0315, v0258);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    v0258 = nil;
    { popv(8); return onevalue(v0258); }

v0193:
    v0258 = stack[-5];
    {
        popv(8);
        fn = elt(env, 10); // errpri1
        return (*qfn1(fn))(qenv(fn), v0258);
    }

v0170:
    v0258 = (LispObject)1; // 0
    stack[-5] = v0258;
    v0258 = stack[-5];
    {
        popv(8);
        fn = elt(env, 10); // errpri1
        return (*qfn1(fn))(qenv(fn), v0258);
    }
// error exit handlers
v0039:
    popv(8);
    return nil;
}



// Code for termorder

static LispObject CC_termorder(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0132, v0164, v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termorder");
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
    v0132 = stack[-1];
    if (v0132 == nil) goto v0194;
    v0132 = stack[-1];
    v0132 = (LispObject)zerop(v0132);
    v0132 = v0132 ? lisp_true : nil;
    env = stack[-3];
    if (v0132 == nil) goto v0096;
    v0132 = stack[0];
    v0132 = (LispObject)zerop(v0132);
    v0132 = v0132 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0132 == nil)) goto v0194;

v0096:
    v0132 = stack[-1];
    v0132 = (LispObject)zerop(v0132);
    v0132 = v0132 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0132 == nil)) goto v0194;
    v0132 = stack[0];
    v0132 = (LispObject)zerop(v0132);
    v0132 = v0132 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0132 == nil)) goto v0194;

v0194:
    v0132 = stack[-1];
    fn = elt(env, 1); // listsum
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    stack[-2] = v0132;
    v0132 = stack[0];
    fn = elt(env, 1); // listsum
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-3];
    v0075 = v0132;
    v0164 = stack[-2];
    v0132 = v0075;
    if (equal(v0164, v0132)) goto v0079;
    v0132 = stack[-2];
    v0164 = v0075;
    v0132 = (LispObject)lessp2(v0132, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0132 = v0132 ? lisp_true : nil;
    if (v0132 == nil) goto v0199;
    v0132 = (LispObject)-15; // -1
    { popv(4); return onevalue(v0132); }

v0199:
    v0132 = (LispObject)17; // 1
    { popv(4); return onevalue(v0132); }

v0079:
    v0164 = stack[-1];
    v0132 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); // termorder1
        return (*qfn2(fn))(qenv(fn), v0164, v0132);
    }
// error exit handlers
v0134:
    popv(4);
    return nil;
}



// Code for comm1

static LispObject CC_comm1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0272, v0198;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comm1");
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
    v0198 = stack[0];
    v0272 = elt(env, 1); // end
    if (!(v0198 == v0272)) goto v0137;

v0004:
    fn = elt(env, 8); // scan
    v0272 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    goto v0137;

v0137:
    v0198 = qvalue(elt(env, 2)); // cursym!*
    v0272 = elt(env, 3); // !*semicol!*
    if (v0198 == v0272) goto v0077;
    v0198 = stack[0];
    v0272 = elt(env, 1); // end
    if (v0198 == v0272) goto v0078;
    v0272 = qvalue(elt(env, 6)); // nil
    goto v0076;

v0076:
    if (v0272 == nil) goto v0123;
    v0272 = qvalue(elt(env, 6)); // nil
    { popv(3); return onevalue(v0272); }

v0123:
    v0198 = stack[0];
    v0272 = elt(env, 1); // end
    if (v0198 == v0272) goto v0187;
    v0272 = qvalue(elt(env, 6)); // nil
    goto v0302;

v0302:
    if (v0272 == nil) goto v0004;
    v0272 = elt(env, 7); // "END-COMMENT NO LONGER SUPPORTED"
    v0272 = ncons(v0272);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    fn = elt(env, 9); // lprim
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    v0272 = qvalue(elt(env, 4)); // t
    stack[-1] = v0272;
    goto v0004;

v0187:
    v0272 = stack[-1];
    v0272 = (v0272 == nil ? lisp_true : nil);
    goto v0302;

v0078:
    v0198 = qvalue(elt(env, 2)); // cursym!*
    v0272 = elt(env, 5); // (end else then until !*rpar!* !*rsqbkt!*)
    v0272 = Lmemq(nil, v0198, v0272);
    goto v0076;

v0077:
    v0272 = qvalue(elt(env, 4)); // t
    goto v0076;
// error exit handlers
v0128:
    popv(3);
    return nil;
}



// Code for createtriplewithancestor

static LispObject CC_createtriplewithancestor(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0196, v0208, v0119;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for createtriplewithancestor");
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
    v0196 = (LispObject)49; // 3
    v0196 = Lmkvect(nil, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    stack[-2] = v0196;
    v0119 = stack[-2];
    v0208 = (LispObject)1; // 0
    v0196 = qvalue(elt(env, 1)); // fluidbibasistripleid
    *(LispObject *)((char *)v0119 + (CELL-TAG_VECTOR) + ((int32_t)v0208/(16/CELL))) = v0196;
    v0119 = stack[-2];
    v0208 = (LispObject)17; // 1
    v0196 = stack[-1];
    *(LispObject *)((char *)v0119 + (CELL-TAG_VECTOR) + ((int32_t)v0208/(16/CELL))) = v0196;
    v0119 = stack[-2];
    v0208 = (LispObject)33; // 2
    v0196 = stack[0];
    *(LispObject *)((char *)v0119 + (CELL-TAG_VECTOR) + ((int32_t)v0208/(16/CELL))) = v0196;
    stack[-1] = stack[-2];
    stack[0] = (LispObject)49; // 3
    v0196 = qvalue(elt(env, 2)); // nil
    v0196 = ncons(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0196;
    v0196 = qvalue(elt(env, 1)); // fluidbibasistripleid
    v0196 = (LispObject)((int32_t)(v0196) + 0x10);
    qvalue(elt(env, 1)) = v0196; // fluidbibasistripleid
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }
// error exit handlers
v0136:
    popv(4);
    return nil;
}



// Code for ofsf_negateat

static LispObject CC_ofsf_negateat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0139, v0140, v0138;
    LispObject fn;
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
    v0140 = qcar(v0139);
    v0139 = stack[0];
    v0139 = qcdr(v0139);
    v0139 = qcdr(v0139);
    v0139 = qcar(v0139);
    v0139 = list2(v0140, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    stack[-1] = v0139;
    v0139 = stack[0];
    v0139 = qcar(v0139);
    fn = elt(env, 1); // ofsf_lnegrel
    v0138 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    v0139 = stack[-1];
    v0140 = qcar(v0139);
    v0139 = stack[-1];
    v0139 = qcdr(v0139);
    v0139 = qcar(v0139);
    popv(3);
    return list3(v0138, v0140, v0139);
// error exit handlers
v0113:
    popv(3);
    return nil;
}



// Code for get!-free!-form

static LispObject CC_getKfreeKform(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0133, v0162, v0163;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-free-form");
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
    v0162 = stack[-1];
    v0133 = qvalue(elt(env, 1)); // frasc!*
    v0133 = Latsoc(nil, v0162, v0133);
    stack[0] = v0133;
    if (v0133 == nil) goto v0111;
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    { popv(4); return onevalue(v0133); }

v0111:
    v0162 = stack[-1];
    v0133 = elt(env, 2); // !~
    if (!consp(v0162)) goto v0113;
    v0162 = qcar(v0162);
    if (!(v0162 == v0133)) goto v0113;
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    stack[-1] = v0133;
    v0133 = elt(env, 3); // (!! !~ !! !~)
    stack[0] = v0133;
    v0133 = qvalue(elt(env, 4)); // t
    stack[-2] = v0133;
    goto v0165;

v0165:
    v0133 = stack[-1];
    v0133 = Lexplode(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0133 = Lappend(nil, stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0133 = Lcompress(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0133 = Lintern(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    stack[0] = v0133;
    v0163 = stack[-1];
    v0162 = stack[0];
    v0133 = qvalue(elt(env, 1)); // frasc!*
    v0133 = acons(v0163, v0162, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0133; // frasc!*
    v0133 = stack[-2];
    if (v0133 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0133 = stack[0];
    v0162 = ncons(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0133 = elt(env, 6); // optional
    v0133 = Lflag(nil, v0162, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0113:
    v0133 = elt(env, 5); // (!! !~)
    stack[0] = v0133;
    goto v0165;
// error exit handlers
v0198:
    popv(4);
    return nil;
}



// Code for matpri

static LispObject CC_matpri(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0091, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0091 = v0000;
// end of prologue
    v0110 = qcdr(v0091);
    v0091 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // matpri1
        return (*qfn2(fn))(qenv(fn), v0110, v0091);
    }
}



// Code for fctrf1

static LispObject CC_fctrf1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0254, v0252;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fctrf1");
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
    stack[-1] = nil;
    v0254 = stack[-3];
    if (!consp(v0254)) goto v0095;
    v0254 = stack[-3];
    v0254 = qcar(v0254);
    v0254 = (consp(v0254) ? nil : lisp_true);
    goto v0110;

v0110:
    if (v0254 == nil) goto v0194;
    v0254 = stack[-3];
    popv(6);
    return ncons(v0254);

v0194:
    v0254 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0254)) v0254 = nil;
    else { v0254 = qfastgets(v0254);
           if (v0254 != nil) { v0254 = elt(v0254, 3); // field
#ifdef RECORD_GET
             if (v0254 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0254 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0254 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0254 == SPID_NOPROP) v0254 = nil; else v0254 = lisp_true; }}
#endif
    if (v0254 == nil) goto v0151;
    v0254 = stack[-3];
    fn = elt(env, 5); // lnc
    v0252 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-1] = v0252;
    v0254 = (LispObject)17; // 1
    v0254 = Lneq(nil, v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    goto v0086;

v0086:
    if (v0254 == nil) goto v0303;
    v0254 = stack[-1];
    fn = elt(env, 6); // !:recip
    v0252 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = stack[-3];
    fn = elt(env, 7); // multd
    v0254 = (*qfn2(fn))(qenv(fn), v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-3] = v0254;
    goto v0111;

v0111:
    v0254 = stack[-3];
    fn = elt(env, 8); // comfac
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-4] = v0254;
    stack[0] = stack[-3];
    v0254 = stack[-4];
    fn = elt(env, 9); // comfac!-to!-poly
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    fn = elt(env, 10); // quotf
    v0254 = (*qfn2(fn))(qenv(fn), stack[0], v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-3] = v0254;
    v0254 = stack[-4];
    v0254 = qcdr(v0254);
    v0254 = CC_fctrf1(env, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-2] = v0254;
    v0254 = stack[-4];
    v0254 = qcar(v0254);
    if (v0254 == nil) goto v0269;
    v0254 = stack[-2];
    stack[0] = qcar(v0254);
    v0254 = stack[-4];
    v0254 = qcar(v0254);
    v0252 = qcar(v0254);
    v0254 = (LispObject)17; // 1
    fn = elt(env, 11); // to
    v0252 = (*qfn2(fn))(qenv(fn), v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = (LispObject)17; // 1
    v0254 = cons(v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0252 = ncons(v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = stack[-4];
    v0254 = qcar(v0254);
    v0254 = qcdr(v0254);
    v0252 = cons(v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = stack[-2];
    v0254 = qcdr(v0254);
    v0254 = list2star(stack[0], v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-2] = v0254;
    goto v0269;

v0269:
    v0254 = stack[-1];
    if (v0254 == nil) goto v0177;
    v0252 = stack[-1];
    v0254 = (LispObject)17; // 1
    if (v0252 == v0254) goto v0177;
    v0252 = stack[-1];
    v0254 = stack[-2];
    v0254 = qcar(v0254);
    fn = elt(env, 7); // multd
    v0252 = (*qfn2(fn))(qenv(fn), v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = stack[-2];
    v0254 = qcdr(v0254);
    v0254 = cons(v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-2] = v0254;
    goto v0177;

v0177:
    v0254 = stack[-3];
    if (!consp(v0254)) goto v0262;
    v0254 = stack[-3];
    v0254 = qcar(v0254);
    v0254 = (consp(v0254) ? nil : lisp_true);
    goto v0264;

v0264:
    if (v0254 == nil) goto v0054;
    v0252 = stack[-3];
    v0254 = stack[-2];
    v0254 = qcar(v0254);
    fn = elt(env, 12); // multf
    v0252 = (*qfn2(fn))(qenv(fn), v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    v0254 = stack[-2];
    v0254 = qcdr(v0254);
    popv(6);
    return cons(v0252, v0254);

v0054:
    v0254 = stack[-3];
    fn = elt(env, 13); // minusf
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    if (v0254 == nil) goto v0322;
    v0254 = stack[-3];
    fn = elt(env, 14); // negf
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-3] = v0254;
    v0254 = stack[-2];
    v0254 = qcar(v0254);
    fn = elt(env, 14); // negf
    v0252 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = stack[-2];
    v0254 = qcdr(v0254);
    v0254 = cons(v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-2] = v0254;
    goto v0322;

v0322:
    v0254 = stack[-3];
    fn = elt(env, 15); // factor!-prim!-f
    v0252 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = stack[-2];
    {
        popv(6);
        fn = elt(env, 16); // fac!-merge
        return (*qfn2(fn))(qenv(fn), v0252, v0254);
    }

v0262:
    v0254 = qvalue(elt(env, 1)); // t
    goto v0264;

v0303:
    v0254 = qvalue(elt(env, 2)); // dmode!*
    if (v0254 == nil) goto v0111;
    v0252 = qvalue(elt(env, 2)); // dmode!*
    v0254 = elt(env, 4); // unitsfn
    v0254 = get(v0252, v0254);
    env = stack[-5];
    stack[-2] = v0254;
    if (v0254 == nil) goto v0111;
    stack[-1] = stack[-2];
    v0252 = (LispObject)17; // 1
    v0254 = stack[-3];
    stack[0] = cons(v0252, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = stack[-3];
    fn = elt(env, 5); // lnc
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    v0254 = Lapply2(nil, 3, stack[-1], stack[0], v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-4] = v0254;
    v0254 = stack[-4];
    v0254 = qcdr(v0254);
    stack[-3] = v0254;
    v0254 = stack[-4];
    v0254 = qcar(v0254);
    fn = elt(env, 6); // !:recip
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-5];
    stack[-1] = v0254;
    goto v0111;

v0151:
    v0254 = qvalue(elt(env, 3)); // nil
    goto v0086;

v0095:
    v0254 = qvalue(elt(env, 1)); // t
    goto v0110;
// error exit handlers
v0321:
    popv(6);
    return nil;
}



// Code for ofsf_updsigndom

static LispObject CC_ofsf_updsigndom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0195, v0149;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_updsigndom");
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
    v0195 = stack[0];
    if (v0195 == nil) goto v0038;
    v0149 = stack[0];
    v0195 = (LispObject)1; // 0
    v0195 = (LispObject)greaterp2(v0149, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    v0195 = v0195 ? lisp_true : nil;
    env = stack[-1];
    if (v0195 == nil) goto v0112;
    v0195 = elt(env, 2); // greaterp
    { popv(2); return onevalue(v0195); }

v0112:
    v0149 = stack[0];
    v0195 = (LispObject)1; // 0
    v0195 = (LispObject)lessp2(v0149, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    v0195 = v0195 ? lisp_true : nil;
    env = stack[-1];
    if (v0195 == nil) goto v0138;
    v0195 = elt(env, 3); // lessp
    { popv(2); return onevalue(v0195); }

v0138:
    v0149 = elt(env, 4); // "something wrong in ofsf_updSignDom:"
    v0195 = stack[0];
    v0195 = list2(v0149, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); // rederr
        return (*qfn1(fn))(qenv(fn), v0195);
    }

v0038:
    v0195 = elt(env, 1); // equal
    { popv(2); return onevalue(v0195); }
// error exit handlers
v0152:
    popv(2);
    return nil;
}



// Code for oldmtch

static LispObject CC_oldmtch(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0074, v0201, v0134;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oldmtch");
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
    v0074 = stack[-2];
    v0134 = qcdr(v0074);
    v0074 = stack[-1];
    v0201 = qcar(v0074);
    v0074 = stack[-2];
    v0074 = qcar(v0074);
    fn = elt(env, 2); // mcharg
    v0074 = (*qfnn(fn))(qenv(fn), 3, v0134, v0201, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-4];
    stack[0] = v0074;
    goto v0076;

v0076:
    v0074 = stack[0];
    if (v0074 == nil) goto v0112;
    v0074 = stack[-3];
    if (!(v0074 == nil)) goto v0112;
    v0074 = stack[0];
    v0201 = qcar(v0074);
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0074 = qcar(v0074);
    v0074 = qcdr(v0074);
    v0074 = Lsubla(nil, v0201, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-4];
    fn = elt(env, 3); // eval
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-4];
    if (v0074 == nil) goto v0116;
    v0074 = stack[0];
    v0201 = qcar(v0074);
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0074 = qcdr(v0074);
    v0074 = qcar(v0074);
    v0074 = Lsubla(nil, v0201, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-4];
    goto v0138;

v0138:
    stack[-3] = v0074;
    v0074 = stack[0];
    v0074 = qcdr(v0074);
    stack[0] = v0074;
    goto v0076;

v0116:
    v0074 = nil;
    goto v0138;

v0112:
    v0074 = stack[-3];
    if (v0074 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    else { LispObject res = stack[-3]; popv(5); return onevalue(res); }
// error exit handlers
v0271:
    popv(5);
    return nil;
}



// Code for gcompatible

static LispObject CC_gcompatible(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0137, v0303, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcompatible");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0303 = v0001;
    v0080 = v0000;
// end of prologue
    v0137 = qvalue(elt(env, 1)); // gmodule!*
    if (v0137 == nil) goto v0020;
    v0137 = v0080;
    v0137 = qcdr(v0137);
    v0080 = qcar(v0137);
    v0137 = v0303;
    v0137 = qcdr(v0137);
    v0303 = qcar(v0137);
    v0137 = qvalue(elt(env, 1)); // gmodule!*
    {
        fn = elt(env, 3); // gevcompatible1
        return (*qfnn(fn))(qenv(fn), 3, v0080, v0303, v0137);
    }

v0020:
    v0137 = qvalue(elt(env, 2)); // t
    return onevalue(v0137);
}



// Code for indxchk

static LispObject CC_indxchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0074, v0201;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indxchk");
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
    v0074 = v0000;
// end of prologue
    stack[-1] = v0074;
    v0201 = qvalue(elt(env, 1)); // indxl!*
    v0074 = qvalue(elt(env, 2)); // nosuml!*
    fn = elt(env, 5); // union
    v0074 = (*qfn2(fn))(qenv(fn), v0201, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    stack[0] = v0074;
    goto v0004;

v0004:
    v0074 = stack[-1];
    if (v0074 == nil) goto v0147;
    v0074 = stack[-1];
    v0074 = qcar(v0074);
    if (!consp(v0074)) goto v0140;
    v0074 = stack[-1];
    v0074 = qcar(v0074);
    v0074 = qcdr(v0074);
    v0074 = qcar(v0074);
    if (is_number(v0074)) goto v0118;
    v0074 = stack[-1];
    v0074 = qcar(v0074);
    v0074 = qcdr(v0074);
    v0074 = qcar(v0074);
    v0201 = v0074;
    goto v0080;

v0080:
    v0074 = stack[0];
    v0074 = Lmemq(nil, v0201, v0074);
    if (v0074 == nil) goto v0077;
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    stack[-1] = v0074;
    goto v0004;

v0077:
    v0074 = qvalue(elt(env, 4)); // t
    { popv(3); return onevalue(v0074); }

v0118:
    v0074 = stack[-1];
    v0074 = qcar(v0074);
    v0074 = qcdr(v0074);
    v0074 = qcar(v0074);
    fn = elt(env, 6); // !*num2id
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0201 = v0074;
    goto v0080;

v0140:
    v0074 = stack[-1];
    v0074 = qcar(v0074);
    if (is_number(v0074)) goto v0192;
    v0074 = stack[-1];
    v0074 = qcar(v0074);
    goto v0114;

v0114:
    v0201 = v0074;
    goto v0080;

v0192:
    v0074 = stack[-1];
    v0074 = qcar(v0074);
    v0074 = Labsval(nil, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    fn = elt(env, 6); // !*num2id
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    goto v0114;

v0147:
    v0074 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0074); }
// error exit handlers
v0133:
    popv(3);
    return nil;
}



// Code for red!=subst1

static LispObject CC_redMsubst1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0259, v0324, v0325;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red=subst1");
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
    stack[-5] = v0001;
    stack[-6] = v0000;
// end of prologue
    v0259 = stack[-6];
    fn = elt(env, 5); // bas_dpoly
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[0] = v0259;
    v0259 = stack[0];
    fn = elt(env, 6); // dp_lc
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-1] = v0259;
    v0259 = stack[-6];
    fn = elt(env, 7); // bas_rep
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-7] = v0259;
    v0259 = stack[-5];
    fn = elt(env, 5); // bas_dpoly
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-3] = v0259;
    v0259 = stack[-3];
    fn = elt(env, 6); // dp_lc
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-2] = v0259;
    v0259 = qvalue(elt(env, 1)); // !*bcsimp
    if (v0259 == nil) goto v0201;
    v0259 = stack[-2];
    fn = elt(env, 8); // cali_bc_inv
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-4] = v0259;
    if (v0259 == nil) goto v0079;
    v0324 = stack[-1];
    v0259 = stack[-4];
    fn = elt(env, 9); // cali_bc_prod
    v0259 = (*qfn2(fn))(qenv(fn), v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-1] = v0259;
    v0259 = (LispObject)17; // 1
    fn = elt(env, 10); // cali_bc_fi
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-2] = v0259;
    goto v0201;

v0201:
    v0259 = stack[0];
    fn = elt(env, 11); // dp_lmon
    stack[-4] = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = stack[-3];
    fn = elt(env, 11); // dp_lmon
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    fn = elt(env, 12); // mo_diff
    v0259 = (*qfn2(fn))(qenv(fn), stack[-4], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-4] = v0259;
    v0324 = stack[-2];
    v0259 = stack[0];
    fn = elt(env, 13); // dp_times_bc
    stack[0] = (*qfn2(fn))(qenv(fn), v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0325 = stack[-1];
    v0324 = stack[-4];
    v0259 = stack[-3];
    fn = elt(env, 14); // dp_times_bcmo
    v0259 = (*qfnn(fn))(qenv(fn), 3, v0325, v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    fn = elt(env, 15); // dp_diff
    v0259 = (*qfn2(fn))(qenv(fn), stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[0] = v0259;
    v0324 = stack[-2];
    v0259 = stack[-7];
    fn = elt(env, 13); // dp_times_bc
    stack[-2] = (*qfn2(fn))(qenv(fn), v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = stack[-5];
    fn = elt(env, 7); // bas_rep
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    fn = elt(env, 14); // dp_times_bcmo
    v0259 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-4], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    fn = elt(env, 15); // dp_diff
    v0259 = (*qfn2(fn))(qenv(fn), stack[-2], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-1] = v0259;
    fn = elt(env, 16); // cali_trace
    v0324 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = (LispObject)1265; // 79
    v0259 = (LispObject)greaterp2(v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0259 = v0259 ? lisp_true : nil;
    env = stack[-8];
    if (v0259 == nil) goto v0141;
    v0259 = elt(env, 2); // "---> "
    v0259 = Lprinc(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = stack[0];
    fn = elt(env, 17); // dp_print
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    goto v0169;

v0169:
    fn = elt(env, 16); // cali_trace
    v0324 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = (LispObject)1425; // 89
    v0259 = (LispObject)greaterp2(v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0259 = v0259 ? lisp_true : nil;
    env = stack[-8];
    if (v0259 == nil) goto v0300;
    v0259 = elt(env, 4); // " uses "
    v0259 = Lprinc(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = stack[-3];
    fn = elt(env, 17); // dp_print
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    goto v0300;

v0300:
    v0259 = stack[-6];
    fn = elt(env, 18); // bas_nr
    v0325 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0324 = stack[0];
    v0259 = stack[-1];
    {
        popv(9);
        fn = elt(env, 19); // bas_make1
        return (*qfnn(fn))(qenv(fn), 3, v0325, v0324, v0259);
    }

v0141:
    fn = elt(env, 16); // cali_trace
    v0324 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = (LispObject)1; // 0
    v0259 = (LispObject)greaterp2(v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0259 = v0259 ? lisp_true : nil;
    env = stack[-8];
    if (v0259 == nil) goto v0169;
    v0259 = elt(env, 3); // "."
    v0259 = Lprinc(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    goto v0169;

v0079:
    v0324 = stack[-2];
    v0259 = stack[-1];
    fn = elt(env, 20); // cali_bc_gcd
    v0259 = (*qfn2(fn))(qenv(fn), v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    stack[-4] = v0259;
    v0324 = stack[-2];
    v0259 = stack[-4];
    fn = elt(env, 21); // cali_bc_divmod
    v0259 = (*qfn2(fn))(qenv(fn), v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = qcar(v0259);
    stack[-2] = v0259;
    v0324 = stack[-1];
    v0259 = stack[-4];
    fn = elt(env, 21); // cali_bc_divmod
    v0259 = (*qfn2(fn))(qenv(fn), v0324, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-8];
    v0259 = qcar(v0259);
    stack[-1] = v0259;
    goto v0201;
// error exit handlers
v0094:
    popv(9);
    return nil;
}



// Code for pcdiv

static LispObject CC_pcdiv(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0134, v0135;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pcdiv");
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
    v0134 = v0000;
// end of prologue
    stack[-5] = v0134;
    v0134 = stack[-5];
    if (v0134 == nil) goto v0110;
    v0134 = stack[-5];
    v0134 = qcar(v0134);
    v0135 = v0134;
    v0134 = v0135;
    stack[0] = qcar(v0134);
    v0134 = v0135;
    v0135 = qcdr(v0134);
    v0134 = stack[-4];
    fn = elt(env, 2); // cdiv
    v0134 = (*qfn2(fn))(qenv(fn), v0135, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0134 = cons(stack[0], v0134);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0134 = ncons(v0134);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    stack[-2] = v0134;
    stack[-3] = v0134;
    goto v0194;

v0194:
    v0134 = stack[-5];
    v0134 = qcdr(v0134);
    stack[-5] = v0134;
    v0134 = stack[-5];
    if (v0134 == nil) { LispObject res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0134 = stack[-5];
    v0134 = qcar(v0134);
    v0135 = v0134;
    v0134 = v0135;
    stack[0] = qcar(v0134);
    v0134 = v0135;
    v0135 = qcdr(v0134);
    v0134 = stack[-4];
    fn = elt(env, 2); // cdiv
    v0134 = (*qfn2(fn))(qenv(fn), v0135, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0134 = cons(stack[0], v0134);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0134 = ncons(v0134);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0134 = Lrplacd(nil, stack[-1], v0134);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-6];
    v0134 = stack[-2];
    v0134 = qcdr(v0134);
    stack[-2] = v0134;
    goto v0194;

v0110:
    v0134 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0134); }
// error exit handlers
v0198:
    popv(7);
    return nil;
}



// Code for dv_cambhead

static LispObject CC_dv_cambhead(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0151, v0152;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_cambhead");
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

v0153:
    v0151 = stack[0];
    fn = elt(env, 4); // listp
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    if (v0151 == nil) goto v0020;
    v0151 = stack[0];
    stack[-1] = qcar(v0151);
    v0152 = elt(env, 1); // expt
    v0151 = elt(env, 2); // minus
    v0151 = list2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    v0151 = Lmember(nil, stack[-1], v0151);
    if (v0151 == nil) goto v0091;
    v0151 = stack[0];
    v0151 = qcdr(v0151);
    v0151 = qcar(v0151);
    stack[0] = v0151;
    goto v0153;

v0091:
    v0151 = stack[0];
    fn = elt(env, 4); // listp
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    if (v0151 == nil) goto v0020;
    v0151 = stack[0];
    v0151 = qcar(v0151);
    { popv(3); return onevalue(v0151); }

v0020:
    v0151 = nil;
    { popv(3); return onevalue(v0151); }
// error exit handlers
v0078:
    popv(3);
    return nil;
}



// Code for hasarg

static LispObject CC_hasarg(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0202, v0209, v0186;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for hasarg");
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
    v0209 = stack[-1];
    v0202 = qvalue(elt(env, 1)); // haveargs!*
    v0202 = cons(v0209, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0202; // haveargs!*
    v0209 = stack[0];
    v0202 = qvalue(elt(env, 2)); // maxarg!*
    v0202 = (LispObject)greaterp2(v0209, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    v0202 = v0202 ? lisp_true : nil;
    env = stack[-2];
    if (v0202 == nil) goto v0195;
    v0202 = (LispObject)1; // 0
    fn = elt(env, 8); // qerline
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    v0202 = elt(env, 3); // "**** "
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    v0202 = stack[-1];
    v0202 = Lprin(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    v0202 = elt(env, 4); // " has "
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    v0202 = stack[0];
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    v0202 = elt(env, 5); // " arguments"
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    v0202 = (LispObject)1; // 0
    fn = elt(env, 9); // newline
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-2];
    goto v0195;

v0195:
    v0209 = stack[-1];
    v0202 = elt(env, 6); // bldmsg
    if (v0209 == v0202) goto v0150;
    v0209 = stack[-1];
    v0186 = elt(env, 7); // number!-of!-args
    v0202 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v0209, v0186, v0202);

v0150:
    v0202 = nil;
    { popv(3); return onevalue(v0202); }
// error exit handlers
v0185:
    popv(3);
    return nil;
}



// Code for get_char_value

static LispObject CC_get_char_value(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0273, v0132;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_char_value");
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
    v0132 = v0000;
// end of prologue
    stack[-1] = nil;
    v0273 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0273;
    v0273 = v0132;
    v0273 = qcdr(v0273);
    stack[0] = v0273;
    goto v0095;

v0095:
    v0273 = stack[-3];
    if (v0273 == nil) goto v0077;
    v0273 = qvalue(elt(env, 1)); // nil
    goto v0189;

v0189:
    if (v0273 == nil) goto v0110;
    v0273 = stack[0];
    v0273 = qcar(v0273);
    v0132 = qcar(v0273);
    v0273 = stack[-2];
    if (!(equal(v0132, v0273))) goto v0113;
    v0273 = stack[0];
    v0273 = qcar(v0273);
    v0273 = qcdr(v0273);
    v0273 = qcar(v0273);
    stack[-1] = v0273;
    v0273 = qvalue(elt(env, 2)); // t
    stack[-3] = v0273;
    goto v0113;

v0113:
    v0273 = stack[0];
    v0273 = qcdr(v0273);
    stack[0] = v0273;
    goto v0095;

v0110:
    v0273 = stack[-3];
    if (!(v0273 == nil)) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0273 = elt(env, 3); // "error in get character element"
    fn = elt(env, 4); // rederr
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    v0273 = nil;
    { popv(5); return onevalue(v0273); }

v0077:
    v0273 = stack[0];
    v0132 = Llength(nil, v0273);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0273 = (LispObject)1; // 0
    v0273 = (LispObject)greaterp2(v0132, v0273);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    v0273 = v0273 ? lisp_true : nil;
    env = stack[-4];
    goto v0189;
// error exit handlers
v0201:
    popv(5);
    return nil;
}



// Code for aex_mvartest

static LispObject CC_aex_mvartest(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0095, v0096;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_mvartest");
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
    v0095 = v0000;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-1];
    v0096 = qcar(v0095);
    v0095 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // sfto_mvartest
        return (*qfn2(fn))(qenv(fn), v0096, v0095);
    }
// error exit handlers
v0224:
    popv(2);
    return nil;
}



// Code for multi_args

static LispObject CC_multi_args(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0224;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multi_args");
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
    v0224 = stack[0];
    if (v0224 == nil) goto v0020;
    v0224 = stack[0];
    v0224 = qcar(v0224);
    fn = elt(env, 2); // expression
    v0224 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-1];
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = CC_multi_args(env, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    goto v0020;

v0020:
    v0224 = nil;
    { popv(2); return onevalue(v0224); }
// error exit handlers
v0147:
    popv(2);
    return nil;
}



setup_type const u26_setup[] =
{
    {"subs3t",                  too_few_2,      CC_subs3t,     wrong_no_2},
    {"charnump:",               CC_charnumpT,   too_many_1,    wrong_no_1},
    {"monomcomparedeglex",      too_few_2,      CC_monomcomparedeglex,wrong_no_2},
    {"smemberlp",               too_few_2,      CC_smemberlp,  wrong_no_2},
    {"lambdafun",               CC_lambdafun,   too_many_1,    wrong_no_1},
    {"setdmode",                too_few_2,      CC_setdmode,   wrong_no_2},
    {"random",                  CC_random,      too_many_1,    wrong_no_1},
    {"factorial",               CC_factorial,   too_many_1,    wrong_no_1},
    {"assert_install1",         CC_assert_install1,too_many_1, wrong_no_1},
    {"repeats",                 CC_repeats,     too_many_1,    wrong_no_1},
    {"mod_eval_uni_poly",       too_few_2,      CC_mod_eval_uni_poly,wrong_no_2},
    {"super_der_simp",          CC_super_der_simp,too_many_1,  wrong_no_1},
    {"formrlis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formrlis},
    {"simpcv",                  too_few_2,      CC_simpcv,     wrong_no_2},
    {"matrixrowom",             CC_matrixrowom, too_many_1,    wrong_no_1},
    {"ft:zerop",                CC_ftTzerop,    too_many_1,    wrong_no_1},
    {"freeoff",                 too_few_2,      CC_freeoff,    wrong_no_2},
    {"oprinla",                 CC_oprinla,     too_many_1,    wrong_no_1},
    {"physopordchk*",           too_few_2,      CC_physopordchkH,wrong_no_2},
    {"fieldconv",               too_few_2,      CC_fieldconv,  wrong_no_2},
    {"reduce-mod-p*",           too_few_2,      CC_reduceKmodKpH,wrong_no_2},
    {"gcref_remprops",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcref_remprops},
    {"ofsf_smmkatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatl},
    {"vsl_subatsq",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_vsl_subatsq},
    {"unaryir",                 too_few_2,      CC_unaryir,    wrong_no_2},
    {"atomlis",                 CC_atomlis,     too_many_1,    wrong_no_1},
    {"rootextractsq",           CC_rootextractsq,too_many_1,   wrong_no_1},
    {"extract_dummy_ids",       CC_extract_dummy_ids,too_many_1,wrong_no_1},
    {"sc_rep",                  CC_sc_rep,      too_many_1,    wrong_no_1},
    {"let3",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let3},
    {"termorder",               too_few_2,      CC_termorder,  wrong_no_2},
    {"comm1",                   CC_comm1,       too_many_1,    wrong_no_1},
    {"createtriplewithancestor",too_few_2,      CC_createtriplewithancestor,wrong_no_2},
    {"ofsf_negateat",           CC_ofsf_negateat,too_many_1,   wrong_no_1},
    {"get-free-form",           CC_getKfreeKform,too_many_1,   wrong_no_1},
    {"matpri",                  CC_matpri,      too_many_1,    wrong_no_1},
    {"fctrf1",                  CC_fctrf1,      too_many_1,    wrong_no_1},
    {"ofsf_updsigndom",         CC_ofsf_updsigndom,too_many_1, wrong_no_1},
    {"oldmtch",                 too_few_2,      CC_oldmtch,    wrong_no_2},
    {"gcompatible",             too_few_2,      CC_gcompatible,wrong_no_2},
    {"indxchk",                 CC_indxchk,     too_many_1,    wrong_no_1},
    {"red=subst1",              too_few_2,      CC_redMsubst1, wrong_no_2},
    {"pcdiv",                   too_few_2,      CC_pcdiv,      wrong_no_2},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"hasarg",                  too_few_2,      CC_hasarg,     wrong_no_2},
    {"get_char_value",          too_few_2,      CC_get_char_value,wrong_no_2},
    {"aex_mvartest",            too_few_2,      CC_aex_mvartest,wrong_no_2},
    {"multi_args",              CC_multi_args,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u26", (two_args *)"20314 5759177 3130231", 0}
};

// end of generated code
