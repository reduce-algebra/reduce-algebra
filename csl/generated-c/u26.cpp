
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



// Code for pasf_sisub

static LispObject CC_pasf_sisub(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0097, v0098, v0099, v0100, v0101, v0102;
    LispObject fn;
    LispObject v0010, v0011, v0012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sisub");
    va_start(aa, nargs);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_sisub");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0012,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-4] = v0010;
    stack[-5] = v0011;
    stack[-1] = v0012;
// end of prologue
    v0097 = stack[-1];
    if (!consp(v0097)) goto v0103;
    v0097 = stack[-1];
    v0097 = qcar(v0097);
    goto v0104;

v0104:
    stack[-6] = v0097;
    v0098 = stack[-6];
    v0097 = elt(env, 1); // ex
    if (v0098 == v0097) goto v0105;
    v0098 = stack[-6];
    v0097 = elt(env, 3); // all
    v0097 = (v0098 == v0097 ? lisp_true : nil);
    goto v0106;

v0106:
    if (v0097 == nil) goto v0107;
    stack[-2] = stack[-6];
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[0] = qcar(v0097);
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0099 = qcar(v0097);
    v0098 = stack[-5];
    v0097 = stack[-4];
    v0097 = CC_pasf_sisub(env, 3, v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    {
        LispObject v0109 = stack[-2];
        LispObject v0110 = stack[0];
        popv(8);
        return list3(v0109, v0110, v0097);
    }

v0107:
    v0098 = stack[-6];
    v0097 = elt(env, 4); // bex
    if (v0098 == v0097) goto v0111;
    v0098 = stack[-6];
    v0097 = elt(env, 5); // ball
    v0097 = (v0098 == v0097 ? lisp_true : nil);
    goto v0112;

v0112:
    if (v0097 == nil) goto v0113;
    stack[-3] = stack[-6];
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[-2] = qcar(v0097);
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0099 = qcar(v0097);
    v0098 = stack[-5];
    v0097 = stack[-4];
    stack[0] = CC_pasf_sisub(env, 3, v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0099 = qcar(v0097);
    v0098 = stack[-5];
    v0097 = stack[-4];
    v0097 = CC_pasf_sisub(env, 3, v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    {
        LispObject v0114 = stack[-3];
        LispObject v0115 = stack[-2];
        LispObject v0116 = stack[0];
        popv(8);
        return list4(v0114, v0115, v0116, v0097);
    }

v0113:
    v0098 = stack[-6];
    v0097 = elt(env, 6); // and
    if (v0098 == v0097) goto v0117;
    v0098 = stack[-6];
    v0097 = elt(env, 9); // or
    if (v0098 == v0097) goto v0118;
    v0098 = stack[-6];
    v0097 = elt(env, 9); // or
    if (v0098 == v0097) goto v0119;
    v0098 = stack[-6];
    v0097 = elt(env, 6); // and
    v0097 = (v0098 == v0097 ? lisp_true : nil);
    goto v0120;

v0120:
    if (v0097 == nil) goto v0121;
    v0097 = qvalue(elt(env, 2)); // t
    goto v0122;

v0122:
    if (v0097 == nil) goto v0123;
    v0097 = qvalue(elt(env, 2)); // t
    goto v0124;

v0124:
    if (v0097 == nil) goto v0125;
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[-3] = v0097;
    v0097 = stack[-3];
    if (v0097 == nil) goto v0126;
    v0097 = stack[-3];
    v0097 = qcar(v0097);
    v0099 = v0097;
    v0098 = stack[-5];
    v0097 = stack[-4];
    v0097 = CC_pasf_sisub(env, 3, v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    stack[-1] = v0097;
    stack[-2] = v0097;
    goto v0127;

v0127:
    v0097 = stack[-3];
    v0097 = qcdr(v0097);
    stack[-3] = v0097;
    v0097 = stack[-3];
    if (v0097 == nil) goto v0128;
    stack[0] = stack[-1];
    v0097 = stack[-3];
    v0097 = qcar(v0097);
    v0099 = v0097;
    v0098 = stack[-5];
    v0097 = stack[-4];
    v0097 = CC_pasf_sisub(env, 3, v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    v0097 = Lrplacd(nil, stack[0], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[-1] = v0097;
    goto v0127;

v0128:
    v0097 = stack[-2];
    goto v0129;

v0129:
    v0098 = v0097;
    v0097 = v0098;
    if (v0097 == nil) goto v0130;
    v0097 = v0098;
    v0097 = qcdr(v0097);
    if (v0097 == nil) goto v0130;
    v0097 = stack[-6];
    popv(8);
    return cons(v0097, v0098);

v0130:
    v0097 = v0098;
    if (v0097 == nil) goto v0131;
    v0097 = v0098;
    v0097 = qcar(v0097);
    { popv(8); return onevalue(v0097); }

v0131:
    v0098 = stack[-6];
    v0097 = elt(env, 6); // and
    if (v0098 == v0097) goto v0132;
    v0097 = elt(env, 8); // false
    { popv(8); return onevalue(v0097); }

v0132:
    v0097 = elt(env, 7); // true
    { popv(8); return onevalue(v0097); }

v0126:
    v0097 = qvalue(elt(env, 14)); // nil
    goto v0129;

v0125:
    v0098 = stack[-6];
    v0097 = elt(env, 7); // true
    if (v0098 == v0097) goto v0133;
    v0098 = stack[-6];
    v0097 = elt(env, 8); // false
    v0097 = (v0098 == v0097 ? lisp_true : nil);
    goto v0134;

v0134:
    if (!(v0097 == nil)) { LispObject res = stack[-1]; popv(8); return onevalue(res); }
    v0097 = stack[-1];
    stack[0] = qcar(v0097);
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[-1] = qcar(v0097);
    v0098 = stack[-5];
    v0097 = stack[-4];
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    fn = elt(env, 15); // subf
    v0097 = (*qfn2(fn))(qenv(fn), stack[-1], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    v0098 = qcar(v0097);
    v0097 = qvalue(elt(env, 14)); // nil
    v0098 = list3(stack[0], v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-7];
    v0097 = stack[-6];
    {
        popv(8);
        fn = elt(env, 16); // pasf_simplat1
        return (*qfn2(fn))(qenv(fn), v0098, v0097);
    }

v0133:
    v0097 = qvalue(elt(env, 2)); // t
    goto v0134;

v0123:
    v0098 = stack[-6];
    v0097 = elt(env, 11); // impl
    if (v0098 == v0097) goto v0135;
    v0098 = stack[-6];
    v0097 = elt(env, 12); // repl
    if (v0098 == v0097) goto v0136;
    v0098 = stack[-6];
    v0097 = elt(env, 13); // equiv
    v0097 = (v0098 == v0097 ? lisp_true : nil);
    goto v0124;

v0136:
    v0097 = qvalue(elt(env, 2)); // t
    goto v0124;

v0135:
    v0097 = qvalue(elt(env, 2)); // t
    goto v0124;

v0121:
    v0098 = stack[-6];
    v0097 = elt(env, 10); // not
    v0097 = (v0098 == v0097 ? lisp_true : nil);
    goto v0122;

v0119:
    v0097 = qvalue(elt(env, 2)); // t
    goto v0120;

v0118:
    v0102 = elt(env, 9); // or
    v0097 = stack[-1];
    v0101 = qcdr(v0097);
    v0100 = stack[-5];
    v0099 = stack[-4];
    v0098 = elt(env, 8); // false
    v0097 = elt(env, 7); // true
    {
        popv(8);
        fn = elt(env, 17); // pasf_sisub!-gand
        return (*qfnn(fn))(qenv(fn), 6, v0102, v0101, v0100, v0099, v0098, v0097);
    }

v0117:
    v0102 = elt(env, 6); // and
    v0097 = stack[-1];
    v0101 = qcdr(v0097);
    v0100 = stack[-5];
    v0099 = stack[-4];
    v0098 = elt(env, 7); // true
    v0097 = elt(env, 8); // false
    {
        popv(8);
        fn = elt(env, 17); // pasf_sisub!-gand
        return (*qfnn(fn))(qenv(fn), 6, v0102, v0101, v0100, v0099, v0098, v0097);
    }

v0111:
    v0097 = qvalue(elt(env, 2)); // t
    goto v0112;

v0105:
    v0097 = qvalue(elt(env, 2)); // t
    goto v0106;

v0103:
    v0097 = stack[-1];
    goto v0104;
// error exit handlers
v0108:
    popv(8);
    return nil;
}



// Code for ev_2a

static LispObject CC_ev_2a(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0137, v0138;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0137 = v0012;
// end of prologue
    v0138 = v0137;
    v0137 = qvalue(elt(env, 1)); // dip_vars!*
    {
        fn = elt(env, 2); // ev_2a1
        return (*qfn2(fn))(qenv(fn), v0138, v0137);
    }
}



// Code for bvarrd

static LispObject CC_bvarrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0081, v0082;
    LispObject fn;
    argcheck(nargs, 0, "bvarrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bvarrd");
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
    fn = elt(env, 8); // lex
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    v0082 = qvalue(elt(env, 1)); // char
    v0081 = elt(env, 2); // (d e g r e e)
    if (!(equal(v0082, v0081))) goto v0096;
    v0082 = elt(env, 3); // "<bvar>"
    v0081 = (LispObject)241; // 15
    fn = elt(env, 9); // errorml
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    goto v0096;

v0096:
    fn = elt(env, 10); // mathml2
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    stack[-1] = v0081;
    fn = elt(env, 8); // lex
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    v0082 = qvalue(elt(env, 1)); // char
    v0081 = elt(env, 2); // (d e g r e e)
    if (equal(v0082, v0081)) goto v0154;
    v0081 = (LispObject)17; // 1
    stack[0] = v0081;
    goto v0088;

v0088:
    v0082 = qvalue(elt(env, 1)); // char
    v0081 = elt(env, 6); // (!/ b v a r)
    if (equal(v0082, v0081)) goto v0111;
    v0082 = elt(env, 7); // "</bvar>"
    v0081 = (LispObject)33; // 2
    fn = elt(env, 9); // errorml
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    v0081 = nil;
    { popv(3); return onevalue(v0081); }

v0111:
    v0082 = stack[-1];
    v0081 = stack[0];
    popv(3);
    return list2(v0082, v0081);

v0154:
    fn = elt(env, 11); // mathml
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    stack[0] = v0081;
    fn = elt(env, 8); // lex
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    v0082 = qvalue(elt(env, 1)); // char
    v0081 = elt(env, 4); // (!/ d e g r e e)
    if (equal(v0082, v0081)) goto v0093;
    v0082 = elt(env, 5); // "</degree>"
    v0081 = (LispObject)33; // 2
    fn = elt(env, 12); // error
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    goto v0093;

v0093:
    fn = elt(env, 8); // lex
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    goto v0088;
// error exit handlers
v0153:
    popv(3);
    return nil;
}



// Code for multdfconst

static LispObject CC_multdfconst(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0086, v0159;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multdfconst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0011;
    stack[-2] = v0012;
// end of prologue
    stack[-3] = nil;
    goto v0160;

v0160:
    v0086 = stack[-1];
    if (v0086 == nil) goto v0161;
    v0086 = stack[-2];
    v0086 = qcar(v0086);
    v0086 = (v0086 == nil ? lisp_true : nil);
    goto v0162;

v0162:
    if (v0086 == nil) goto v0163;
    v0086 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0086);
    }

v0163:
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    stack[0] = qcar(v0086);
    v0159 = stack[-2];
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = qcdr(v0086);
    fn = elt(env, 3); // multsq
    v0086 = (*qfn2(fn))(qenv(fn), v0159, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    fn = elt(env, 4); // subs2q
    v0159 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0086 = stack[-3];
    v0086 = acons(stack[0], v0159, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    stack[-3] = v0086;
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    goto v0160;

v0161:
    v0086 = qvalue(elt(env, 1)); // t
    goto v0162;
// error exit handlers
v0144:
    popv(5);
    return nil;
}



// Code for evaluate!-horner

static LispObject CC_evaluateKhorner(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0158, v0155, v0146;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate-horner");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0012;
// end of prologue
    v0155 = stack[-1];
    v0158 = qvalue(elt(env, 1)); // horner!-cache!*
    v0158 = Lassoc(nil, v0155, v0158);
    stack[-2] = v0158;
    v0158 = stack[-2];
    if (v0158 == nil) goto v0167;
    v0158 = stack[-2];
    v0158 = qcdr(v0158);
    { popv(4); return onevalue(v0158); }

v0167:
    v0158 = stack[-1];
    fn = elt(env, 2); // simp!*
    v0158 = (*qfn1(fn))(qenv(fn), v0158);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    stack[-2] = v0158;
    v0158 = stack[-2];
    v0158 = qcar(v0158);
    fn = elt(env, 3); // hornerf
    stack[0] = (*qfn1(fn))(qenv(fn), v0158);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    v0158 = stack[-2];
    v0158 = qcdr(v0158);
    fn = elt(env, 3); // hornerf
    v0158 = (*qfn1(fn))(qenv(fn), v0158);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    v0158 = cons(stack[0], v0158);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    fn = elt(env, 4); // prepsq
    v0158 = (*qfn1(fn))(qenv(fn), v0158);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    stack[-2] = v0158;
    v0146 = stack[-1];
    v0155 = stack[-2];
    v0158 = qvalue(elt(env, 1)); // horner!-cache!*
    v0158 = acons(v0146, v0155, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0158; // horner!-cache!*
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }
// error exit handlers
v0168:
    popv(4);
    return nil;
}



// Code for !*xadd

static LispObject CC_Hxadd(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0168, v0085, v0087, v0171;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *xadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0171 = v0011;
    stack[0] = v0012;
// end of prologue
    v0168 = v0171;
    v0087 = v0168;
    goto v0103;

v0103:
    v0168 = v0087;
    if (v0168 == nil) goto v0104;
    v0168 = stack[0];
    v0085 = qcar(v0168);
    v0168 = v0087;
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    if (equal(v0085, v0168)) goto v0104;
    v0168 = v0087;
    v0168 = qcdr(v0168);
    v0087 = v0168;
    goto v0103;

v0104:
    v0168 = v0087;
    if (v0168 == nil) goto v0164;
    v0168 = v0087;
    v0168 = qcar(v0168);
    v0085 = v0171;
    v0168 = Ldelete(nil, v0168, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    v0171 = v0168;
    goto v0164;

v0164:
    v0168 = stack[0];
    v0085 = v0171;
    popv(1);
    return cons(v0168, v0085);
// error exit handlers
v0145:
    popv(1);
    return nil;
}



// Code for log_freevars_list

static LispObject CC_log_freevars_list(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0173, v0092;
    LispObject fn;
    LispObject v0010, v0011, v0012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "log_freevars_list");
    va_start(aa, nargs);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log_freevars_list");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0012,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0010;
    stack[-1] = v0011;
    stack[-2] = v0012;
// end of prologue

v0160:
    v0173 = stack[-1];
    if (!consp(v0173)) goto v0103;
    v0173 = stack[0];
    if (v0173 == nil) goto v0170;
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    if (!(!consp(v0173))) goto v0170;
    v0173 = stack[-1];
    v0173 = qcdr(v0173);
    stack[-1] = v0173;
    v0173 = qvalue(elt(env, 2)); // t
    stack[0] = v0173;
    goto v0160;

v0170:
    v0092 = stack[-2];
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    fn = elt(env, 3); // log_freevars
    v0173 = (*qfn2(fn))(qenv(fn), v0092, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    if (v0173 == nil) goto v0174;
    v0173 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0173); }

v0174:
    v0173 = stack[-1];
    v0173 = qcdr(v0173);
    stack[-1] = v0173;
    goto v0160;

v0103:
    v0173 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0173); }
// error exit handlers
v0157:
    popv(4);
    return nil;
}



// Code for dv_ind2var

static LispObject CC_dv_ind2var(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0176, v0174;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_ind2var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue
    stack[-1] = stack[0];
    v0176 = qvalue(elt(env, 1)); // g_dvnames
    fn = elt(env, 3); // upbve
    v0176 = (*qfn1(fn))(qenv(fn), v0176);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    v0176 = (LispObject)lesseq2(stack[-1], v0176);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0176 = v0176 ? lisp_true : nil;
    env = stack[-2];
    if (v0176 == nil) goto v0163;
    stack[-1] = qvalue(elt(env, 1)); // g_dvnames
    v0176 = stack[0];
    v0176 = sub1(v0176);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0176 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0176/(16/CELL)));
    { popv(3); return onevalue(v0176); }

v0163:
    v0174 = qvalue(elt(env, 2)); // g_dvbase
    v0176 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // mkid
        return (*qfn2(fn))(qenv(fn), v0174, v0176);
    }
// error exit handlers
v0177:
    popv(3);
    return nil;
}



// Code for gen!+can!+bas

static LispObject CC_genLcanLbas(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0200, v0201;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gen+can+bas");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-9] = v0012;
// end of prologue
    v0201 = (LispObject)17; // 1
    v0200 = (LispObject)17; // 1
    v0200 = cons(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    stack[-10] = v0200;
    v0201 = qvalue(elt(env, 1)); // nil
    v0200 = (LispObject)17; // 1
    v0200 = cons(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    stack[-8] = v0200;
    v0200 = (LispObject)17; // 1
    stack[-7] = v0200;
    v0201 = stack[-9];
    v0200 = stack[-7];
    v0200 = difference2(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lminusp(nil, v0200);
    env = stack[-11];
    if (v0200 == nil) goto v0172;
    v0200 = qvalue(elt(env, 1)); // nil
    { popv(12); return onevalue(v0200); }

v0172:
    v0200 = (LispObject)17; // 1
    stack[-3] = v0200;
    v0201 = stack[-9];
    v0200 = stack[-3];
    v0200 = difference2(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lminusp(nil, v0200);
    env = stack[-11];
    if (v0200 == nil) goto v0080;
    v0200 = qvalue(elt(env, 1)); // nil
    goto v0086;

v0086:
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    stack[-5] = v0200;
    stack[-6] = v0200;
    goto v0095;

v0095:
    v0200 = stack[-7];
    v0200 = add1(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    stack[-7] = v0200;
    v0201 = stack[-9];
    v0200 = stack[-7];
    v0200 = difference2(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lminusp(nil, v0200);
    env = stack[-11];
    if (!(v0200 == nil)) { LispObject res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    v0200 = (LispObject)17; // 1
    stack[-3] = v0200;
    v0201 = stack[-9];
    v0200 = stack[-3];
    v0200 = difference2(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lminusp(nil, v0200);
    env = stack[-11];
    if (v0200 == nil) goto v0203;
    v0200 = qvalue(elt(env, 1)); // nil
    goto v0204;

v0204:
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lrplacd(nil, stack[-4], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = stack[-5];
    v0200 = qcdr(v0200);
    stack[-5] = v0200;
    goto v0095;

v0203:
    v0201 = stack[-7];
    v0200 = stack[-3];
    if (equal(v0201, v0200)) goto v0205;
    v0200 = stack[-8];
    goto v0206;

v0206:
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    stack[-1] = v0200;
    stack[-2] = v0200;
    goto v0207;

v0207:
    v0200 = stack[-3];
    v0200 = add1(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    stack[-3] = v0200;
    v0201 = stack[-9];
    v0200 = stack[-3];
    v0200 = difference2(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lminusp(nil, v0200);
    env = stack[-11];
    if (v0200 == nil) goto v0208;
    v0200 = stack[-2];
    goto v0204;

v0208:
    stack[0] = stack[-1];
    v0201 = stack[-7];
    v0200 = stack[-3];
    if (equal(v0201, v0200)) goto v0209;
    v0200 = stack[-8];
    goto v0122;

v0122:
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lrplacd(nil, stack[0], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = stack[-1];
    v0200 = qcdr(v0200);
    stack[-1] = v0200;
    goto v0207;

v0209:
    v0200 = stack[-10];
    goto v0122;

v0205:
    v0200 = stack[-10];
    goto v0206;

v0080:
    v0201 = stack[-7];
    v0200 = stack[-3];
    if (equal(v0201, v0200)) goto v0210;
    v0200 = stack[-8];
    goto v0211;

v0211:
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    stack[-1] = v0200;
    stack[-2] = v0200;
    goto v0159;

v0159:
    v0200 = stack[-3];
    v0200 = add1(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    stack[-3] = v0200;
    v0201 = stack[-9];
    v0200 = stack[-3];
    v0200 = difference2(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lminusp(nil, v0200);
    env = stack[-11];
    if (v0200 == nil) goto v0212;
    v0200 = stack[-2];
    goto v0086;

v0212:
    stack[0] = stack[-1];
    v0201 = stack[-7];
    v0200 = stack[-3];
    if (equal(v0201, v0200)) goto v0213;
    v0200 = stack[-8];
    goto v0073;

v0073:
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = Lrplacd(nil, stack[0], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-11];
    v0200 = stack[-1];
    v0200 = qcdr(v0200);
    stack[-1] = v0200;
    goto v0159;

v0213:
    v0200 = stack[-10];
    goto v0073;

v0210:
    v0200 = stack[-10];
    goto v0211;
// error exit handlers
v0202:
    popv(12);
    return nil;
}



// Code for pasf_smordtable

static LispObject CC_pasf_smordtable(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0155, v0146;
    LispObject fn;
    LispObject v0156, v0010, v0011, v0012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pasf_smordtable");
    va_start(aa, nargs);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    v0156 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smordtable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0156,v0010,v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0012,v0011,v0010,v0156);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0156;
    stack[-1] = v0010;
    stack[-2] = v0011;
    stack[-3] = v0012;
// end of prologue
    v0146 = stack[-1];
    v0155 = stack[0];
    v0155 = (LispObject)lessp2(v0146, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    v0155 = v0155 ? lisp_true : nil;
    env = stack[-4];
    if (v0155 == nil) goto v0214;
    v0146 = stack[-3];
    v0155 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); // pasf_smordtable2
        return (*qfn2(fn))(qenv(fn), v0146, v0155);
    }

v0214:
    v0146 = stack[-1];
    v0155 = stack[0];
    v0155 = (LispObject)greaterp2(v0146, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    v0155 = v0155 ? lisp_true : nil;
    env = stack[-4];
    if (v0155 == nil) goto v0165;
    v0146 = stack[-3];
    v0155 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // pasf_smordtable1
        return (*qfn2(fn))(qenv(fn), v0146, v0155);
    }

v0165:
    v0155 = elt(env, 1); // "abused smordtable"
    v0155 = ncons(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(qenv(fn), v0155);
    }
// error exit handlers
v0085:
    popv(5);
    return nil;
}



// Code for ofsf_entry2at

static LispObject CC_ofsf_entry2at(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0176, v0174, v0149, v0148;
    LispObject fn;
    LispObject v0010, v0011, v0012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_entry2at");
    va_start(aa, nargs);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_entry2at");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0012,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0174 = v0010;
    v0149 = v0011;
    v0148 = v0012;
// end of prologue
    v0176 = qvalue(elt(env, 1)); // !*rlidentify
    if (v0176 == nil) goto v0150;
    v0176 = v0148;
    fn = elt(env, 2); // ofsf_entry2at1
    v0176 = (*qfnn(fn))(qenv(fn), 3, v0176, v0149, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // cl_identifyat
        return (*qfn1(fn))(qenv(fn), v0176);
    }

v0150:
    v0176 = v0148;
    {
        popv(1);
        fn = elt(env, 2); // ofsf_entry2at1
        return (*qfnn(fn))(qenv(fn), 3, v0176, v0149, v0174);
    }
// error exit handlers
v0177:
    popv(1);
    return nil;
}



// Code for sets

static LispObject CC_sets(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0172, v0176;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sets");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue
    v0172 = elt(env, 1); // "<apply>"
    fn = elt(env, 6); // printout
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-2];
    v0172 = elt(env, 2); // "<"
    v0172 = Lprinc(nil, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-2];
    v0172 = stack[0];
    v0172 = Lprinc(nil, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-2];
    v0172 = elt(env, 3); // "/>"
    v0172 = Lprinc(nil, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-2];
    v0176 = qvalue(elt(env, 4)); // indent
    v0172 = (LispObject)49; // 3
    v0172 = plus2(v0176, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0172; // indent
    v0172 = stack[-1];
    fn = elt(env, 7); // multi_elem
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-2];
    v0176 = qvalue(elt(env, 4)); // indent
    v0172 = (LispObject)49; // 3
    v0172 = difference2(v0176, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0172; // indent
    v0172 = elt(env, 5); // "</apply>"
    fn = elt(env, 6); // printout
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    v0172 = nil;
    { popv(3); return onevalue(v0172); }
// error exit handlers
v0148:
    popv(3);
    return nil;
}



// Code for !*a2k

static LispObject CC_Ha2k(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0174, v0149;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *a2k");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue
    v0174 = stack[0];
    fn = elt(env, 2); // simp!*
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-2];
    stack[-1] = v0174;
    fn = elt(env, 3); // kernp
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-2];
    if (v0174 == nil) goto v0175;
    v0174 = stack[-1];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    { popv(3); return onevalue(v0174); }

v0175:
    v0174 = stack[0];
    if (v0174 == nil) goto v0163;
    v0174 = stack[0];
    v0149 = v0174;
    goto v0106;

v0106:
    v0174 = elt(env, 1); // kernel
    fn = elt(env, 4); // typerr
    v0174 = (*qfn2(fn))(qenv(fn), v0149, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    v0174 = nil;
    { popv(3); return onevalue(v0174); }

v0163:
    v0174 = (LispObject)1; // 0
    v0149 = v0174;
    goto v0106;
// error exit handlers
v0173:
    popv(3);
    return nil;
}



// Code for mkempspmat

static LispObject CC_mkempspmat(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0215, v0175;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkempspmat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    v0215 = v0012;
// end of prologue
    stack[-1] = elt(env, 1); // sparsemat
    v0175 = Lmkvect(nil, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    v0215 = stack[0];
    {
        LispObject v0150 = stack[-1];
        popv(2);
        return list3(v0150, v0175, v0215);
    }
// error exit handlers
v0105:
    popv(2);
    return nil;
}



// Code for suchp

static LispObject CC_suchp(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0215, v0175;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for suchp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0175 = v0012;
// end of prologue
    v0215 = v0175;
    if (!consp(v0215)) goto v0152;
    v0215 = v0175;
    v0215 = qcar(v0215);
    v0175 = elt(env, 1); // such!-that
    v0215 = (v0215 == v0175 ? lisp_true : nil);
    return onevalue(v0215);

v0152:
    v0215 = qvalue(elt(env, 2)); // nil
    return onevalue(v0215);
}



// Code for !*pf2sq

static LispObject CC_Hpf2sq(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0194, v0195;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *pf2sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue
    v0195 = qvalue(elt(env, 1)); // nil
    v0194 = (LispObject)17; // 1
    v0194 = cons(v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    stack[-1] = v0194;
    v0194 = stack[0];
    if (v0194 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0194 = stack[0];
    stack[0] = v0194;
    goto v0106;

v0106:
    v0194 = stack[0];
    if (v0194 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0194 = stack[0];
    v0194 = qcar(v0194);
    v0195 = qcar(v0194);
    v0194 = (LispObject)17; // 1
    if (v0195 == v0194) goto v0171;
    v0194 = stack[0];
    v0194 = qcar(v0194);
    v0195 = qcar(v0194);
    v0194 = (LispObject)17; // 1
    fn = elt(env, 2); // to
    v0195 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0194 = (LispObject)17; // 1
    v0194 = cons(v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0195 = ncons(v0194);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0194 = (LispObject)17; // 1
    v0194 = cons(v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0195 = v0194;
    goto v0173;

v0173:
    v0194 = stack[0];
    v0194 = qcar(v0194);
    v0194 = qcdr(v0194);
    fn = elt(env, 3); // multsq
    v0195 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0194 = stack[-1];
    fn = elt(env, 4); // addsq
    v0194 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    stack[-1] = v0194;
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    stack[0] = v0194;
    goto v0106;

v0171:
    v0195 = (LispObject)17; // 1
    v0194 = (LispObject)17; // 1
    v0194 = cons(v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-2];
    v0195 = v0194;
    goto v0173;
// error exit handlers
v0212:
    popv(3);
    return nil;
}



// Code for difference!:

static LispObject CC_differenceT(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0188, v0189, v0231, v0232;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for difference:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0231 = v0011;
    v0232 = v0012;
// end of prologue
    v0188 = v0232;
    v0188 = qcdr(v0188);
    v0189 = qcar(v0188);
    stack[-1] = v0189;
    v0188 = (LispObject)1; // 0
    if (v0189 == v0188) goto v0162;
    v0188 = v0231;
    v0188 = qcdr(v0188);
    v0189 = qcar(v0188);
    stack[0] = v0189;
    v0188 = (LispObject)1; // 0
    if (v0189 == v0188) { popv(6); return onevalue(v0232); }
    v0188 = v0232;
    v0188 = qcdr(v0188);
    v0188 = qcdr(v0188);
    stack[-4] = v0188;
    v0189 = v0231;
    v0189 = qcdr(v0189);
    v0189 = qcdr(v0189);
    stack[-2] = v0189;
    v0189 = difference2(v0188, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    stack[-3] = v0189;
    v0188 = (LispObject)1; // 0
    if (v0189 == v0188) goto v0145;
    v0189 = stack[-3];
    v0188 = (LispObject)1; // 0
    v0188 = (LispObject)greaterp2(v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    v0188 = v0188 ? lisp_true : nil;
    env = stack[-5];
    if (v0188 == nil) goto v0233;
    stack[-4] = elt(env, 1); // !:rd!:
    v0189 = stack[-1];
    v0188 = stack[-3];
    fn = elt(env, 2); // ashift
    v0189 = (*qfn2(fn))(qenv(fn), v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    v0188 = stack[0];
    v0189 = difference2(v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    v0188 = stack[-2];
    {
        LispObject v0068 = stack[-4];
        popv(6);
        return list2star(v0068, v0189, v0188);
    }

v0233:
    stack[-2] = elt(env, 1); // !:rd!:
    v0188 = stack[-3];
    v0188 = negate(v0188);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    fn = elt(env, 2); // ashift
    v0188 = (*qfn2(fn))(qenv(fn), stack[0], v0188);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    v0189 = difference2(stack[-1], v0188);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    v0188 = stack[-4];
    {
        LispObject v0183 = stack[-2];
        popv(6);
        return list2star(v0183, v0189, v0188);
    }

v0145:
    stack[-2] = elt(env, 1); // !:rd!:
    v0189 = stack[-1];
    v0188 = stack[0];
    v0189 = difference2(v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    v0188 = stack[-4];
    {
        LispObject v0117 = stack[-2];
        popv(6);
        return list2star(v0117, v0189, v0188);
    }

v0162:
    v0188 = v0231;
    {
        popv(6);
        fn = elt(env, 3); // minus!:
        return (*qfn1(fn))(qenv(fn), v0188);
    }
// error exit handlers
v0069:
    popv(6);
    return nil;
}



// Code for convprc2

static LispObject CC_convprc2(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0218, v0139, v0140;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convprc2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue
    v0218 = stack[-1];
    fn = elt(env, 4); // convprec
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-2];
    stack[-1] = v0218;
    v0218 = stack[0];
    fn = elt(env, 4); // convprec
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0218; // yy!!
    v0218 = qvalue(elt(env, 2)); // !*roundbf
    if (v0218 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0218 = qvalue(elt(env, 1)); // yy!!
    v0139 = v0218;
    v0139 = Lfloatp(nil, v0139);
    env = stack[-2];
    if (v0139 == nil) goto v0106;
    fn = elt(env, 5); // fl2bf
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-2];
    goto v0151;

v0151:
    qvalue(elt(env, 1)) = v0218; // yy!!
    v0218 = stack[-1];
    v0218 = Lfloatp(nil, v0218);
    env = stack[-2];
    if (v0218 == nil) goto v0145;
    v0218 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); // fl2bf
        return (*qfn1(fn))(qenv(fn), v0218);
    }

v0145:
    v0218 = stack[-1];
    if (!consp(v0218)) goto v0234;
    v0218 = stack[-1];
    goto v0223;

v0223:
    {
        popv(3);
        fn = elt(env, 6); // normbf
        return (*qfn1(fn))(qenv(fn), v0218);
    }

v0234:
    v0218 = stack[-1];
    v0218 = integerp(v0218);
    if (v0218 == nil) goto v0084;
    v0140 = elt(env, 3); // !:rd!:
    v0139 = stack[-1];
    v0218 = (LispObject)1; // 0
    v0218 = list2star(v0140, v0139, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-2];
    goto v0223;

v0084:
    v0218 = stack[-1];
    fn = elt(env, 7); // read!:num
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-2];
    goto v0223;

v0106:
    v0139 = v0218;
    if (!(!consp(v0139))) goto v0170;
    v0139 = v0218;
    v0139 = integerp(v0139);
    if (v0139 == nil) goto v0235;
    v0140 = elt(env, 3); // !:rd!:
    v0139 = v0218;
    v0218 = (LispObject)1; // 0
    v0218 = list2star(v0140, v0139, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-2];
    goto v0170;

v0170:
    fn = elt(env, 6); // normbf
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-2];
    goto v0151;

v0235:
    fn = elt(env, 7); // read!:num
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-2];
    goto v0170;
// error exit handlers
v0228:
    popv(3);
    return nil;
}



// Code for indordl2

static LispObject CC_indordl2(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0172, v0176;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indordl2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue
    v0176 = stack[-1];
    v0172 = stack[0];
    fn = elt(env, 1); // indordlp
    v0172 = (*qfn2(fn))(qenv(fn), v0176, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    if (v0172 == nil) goto v0170;
    v0176 = stack[-1];
    v0172 = stack[0];
    popv(2);
    return list2(v0176, v0172);

v0170:
    v0176 = stack[0];
    v0172 = stack[-1];
    popv(2);
    return list2(v0176, v0172);
// error exit handlers
v0148:
    popv(2);
    return nil;
}



// Code for sign!-of

static LispObject CC_signKof(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0152, v0217;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sign-of");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0152 = v0012;
// end of prologue
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[0];
    fn = elt(env, 2); // simp!-sign
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[0];
    v0152 = qcar(v0152);
    v0217 = v0152;
    v0152 = v0217;
    if (is_number(v0152)) { popv(1); return onevalue(v0217); }
    v0152 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0152); }
// error exit handlers
v0167:
    popv(1);
    return nil;
}



// Code for split_cov_cont_ids

static LispObject CC_split_cov_cont_ids(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0223, v0237, v0234;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split_cov_cont_ids");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0012;
// end of prologue
    stack[-2] = nil;
    stack[0] = nil;
    goto v0104;

v0104:
    v0223 = stack[-1];
    if (v0223 == nil) goto v0168;
    v0223 = stack[-1];
    v0223 = qcar(v0223);
    v0234 = v0223;
    v0237 = v0234;
    v0223 = elt(env, 2); // minus
    if (!consp(v0237)) goto v0165;
    v0237 = qcar(v0237);
    if (!(v0237 == v0223)) goto v0165;
    v0223 = v0234;
    v0223 = qcdr(v0223);
    v0237 = qcar(v0223);
    v0223 = stack[-2];
    v0223 = cons(v0237, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[-2] = v0223;
    goto v0215;

v0215:
    v0223 = stack[-1];
    v0223 = qcdr(v0223);
    stack[-1] = v0223;
    goto v0104;

v0165:
    v0237 = v0234;
    v0223 = stack[0];
    v0223 = cons(v0237, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[0] = v0223;
    goto v0215;

v0168:
    v0223 = stack[-2];
    v0237 = Lnreverse(nil, v0223);
    env = stack[-3];
    v0223 = stack[0];
    v0223 = Lnreverse(nil, v0223);
    popv(4);
    return list2(v0237, v0223);
// error exit handlers
v0089:
    popv(4);
    return nil;
}



// Code for skp_ordp

static LispObject CC_skp_ordp(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0152, v0217, v0167;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for skp_ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0152 = v0011;
    v0217 = v0012;
// end of prologue
    v0167 = qcar(v0217);
    v0217 = qcar(v0152);
    v0152 = elt(env, 1); // atom_compare
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(qenv(fn), 3, v0167, v0217, v0152);
    }
}



// Code for get!*inverse

static LispObject CC_getHinverse(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0166, v0172, v0176;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get*inverse");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0172 = v0011;
    v0166 = v0012;
// end of prologue
    v0176 = v0166;
    v0166 = elt(env, 1); // inverse
    v0166 = get(v0176, v0166);
    env = stack[-1];
    v0176 = v0166;
    v0166 = v0176;
    v0166 = qcdr(v0166);
    stack[0] = qcar(v0166);
    v0166 = v0172;
    v0172 = v0176;
    v0172 = qcar(v0172);
    fn = elt(env, 2); // give!*position
    v0166 = (*qfn2(fn))(qenv(fn), v0166, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-1];
    {
        LispObject v0148 = stack[0];
        popv(2);
        fn = elt(env, 3); // nth
        return (*qfn2(fn))(qenv(fn), v0148, v0166);
    }
// error exit handlers
v0149:
    popv(2);
    return nil;
}



// Code for mri_congp

static LispObject CC_mri_congp(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0138, v0162;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_congp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0138 = v0012;
// end of prologue
    fn = elt(env, 2); // mri_opn
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[0];
    v0162 = elt(env, 1); // (cong ncong)
    v0138 = Lmemq(nil, v0138, v0162);
    { popv(1); return onevalue(v0138); }
// error exit handlers
v0161:
    popv(1);
    return nil;
}



// Code for pasf_floor

static LispObject CC_pasf_floor(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0078, v0072, v0241;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_floor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue
    v0078 = stack[-1];
    if (!consp(v0078)) goto v0161;
    v0078 = stack[-1];
    v0078 = qcar(v0078);
    v0078 = (consp(v0078) ? nil : lisp_true);
    goto v0162;

v0162:
    if (v0078 == nil) goto v0172;
    v0078 = stack[0];
    if (!consp(v0078)) goto v0150;
    v0078 = stack[0];
    v0078 = qcar(v0078);
    v0078 = (consp(v0078) ? nil : lisp_true);
    goto v0104;

v0104:
    if (v0078 == nil) goto v0242;
    v0078 = stack[-1];
    if (v0078 == nil) goto v0177;
    v0072 = stack[-1];
    v0078 = stack[0];
    v0072 = Cremainder(v0072, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-2];
    v0078 = (LispObject)1; // 0
    if (v0072 == v0078) goto v0234;
    v0072 = stack[-1];
    v0078 = stack[0];
    v0072 = times2(v0072, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-2];
    v0078 = (LispObject)1; // 0
    v0078 = (LispObject)greaterp2(v0072, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    v0078 = v0078 ? lisp_true : nil;
    env = stack[-2];
    if (v0078 == nil) goto v0229;
    v0072 = stack[-1];
    v0078 = stack[0];
    v0078 = quot2(v0072, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-2];
    goto v0235;

v0235:
    fn = elt(env, 4); // simp
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    v0078 = qcar(v0078);
    { popv(3); return onevalue(v0078); }

v0229:
    v0072 = stack[-1];
    v0078 = stack[0];
    v0078 = quot2(v0072, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-2];
    v0078 = sub1(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-2];
    goto v0235;

v0234:
    v0072 = stack[-1];
    v0078 = stack[0];
    v0078 = quot2(v0072, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-2];
    goto v0235;

v0177:
    v0078 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0078); }

v0242:
    v0241 = elt(env, 3); // "pasf_floor: not a domain valued sf in input"
    v0072 = stack[-1];
    v0078 = stack[0];
    v0078 = list3(v0241, v0072, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); // rederr
        return (*qfn1(fn))(qenv(fn), v0078);
    }

v0150:
    v0078 = qvalue(elt(env, 1)); // t
    goto v0104;

v0172:
    v0078 = qvalue(elt(env, 2)); // nil
    goto v0104;

v0161:
    v0078 = qvalue(elt(env, 1)); // t
    goto v0162;
// error exit handlers
v0225:
    popv(3);
    return nil;
}



// Code for matrixom

static LispObject CC_matrixom(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0175;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue
    v0175 = elt(env, 1); // "<OMA>"
    fn = elt(env, 6); // printout
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-1];
    v0175 = qvalue(elt(env, 2)); // t
    fn = elt(env, 7); // indent!*
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-1];
    v0175 = elt(env, 3); // "<OMS cd=""linalg1"" name=""matrix""/>"
    fn = elt(env, 6); // printout
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-1];
    v0175 = stack[0];
    v0175 = qcdr(v0175);
    v0175 = qcdr(v0175);
    v0175 = qcdr(v0175);
    v0175 = qcar(v0175);
    fn = elt(env, 8); // matrixrowom
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-1];
    v0175 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 7); // indent!*
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-1];
    v0175 = elt(env, 5); // "</OMA>"
    fn = elt(env, 6); // printout
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0175 = nil;
    { popv(2); return onevalue(v0175); }
// error exit handlers
v0106:
    popv(2);
    return nil;
}



// Code for alg_plus

static LispObject CC_alg_plus(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0217, v0167, v0215;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for alg_plus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0217 = v0011;
    v0167 = v0012;
// end of prologue
    v0215 = elt(env, 1); // plus
    v0217 = list3(v0215, v0167, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // aeval
        return (*qfn1(fn))(qenv(fn), v0217);
    }
// error exit handlers
v0175:
    popv(1);
    return nil;
}



// Code for gftimes

static LispObject CC_gftimes(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0163, v0214, v0154;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gftimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0214 = v0011;
    v0154 = v0012;
// end of prologue
    v0163 = v0154;
    v0163 = qcar(v0163);
    if (!consp(v0163)) goto v0137;
    v0163 = v0154;
    {
        fn = elt(env, 1); // gbftimes
        return (*qfn2(fn))(qenv(fn), v0163, v0214);
    }

v0137:
    v0163 = v0154;
    {
        fn = elt(env, 2); // gfftimes
        return (*qfn2(fn))(qenv(fn), v0163, v0214);
    }
}



// Code for incident

static LispObject CC_incident(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0085, v0087, v0171;
    LispObject fn;
    LispObject v0010, v0011, v0012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "incident");
    va_start(aa, nargs);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for incident");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0012,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0010;
    stack[0] = v0011;
    stack[-2] = v0012;
// end of prologue

v0243:
    v0085 = stack[0];
    if (v0085 == nil) goto v0160;
    v0171 = stack[-2];
    v0085 = stack[0];
    v0087 = qcar(v0085);
    v0085 = stack[-1];
    fn = elt(env, 2); // incident1
    v0085 = (*qfnn(fn))(qenv(fn), 3, v0171, v0087, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-3];
    v0087 = v0085;
    v0085 = v0087;
    if (v0085 == nil) goto v0157;
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    popv(4);
    return cons(v0087, v0085);

v0157:
    v0085 = stack[0];
    stack[0] = qcdr(v0085);
    v0085 = stack[-1];
    v0085 = add1(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-3];
    stack[-1] = v0085;
    goto v0243;

v0160:
    v0085 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0085); }
// error exit handlers
v0236:
    popv(4);
    return nil;
}



// Code for list_is_all_free

static LispObject CC_list_is_all_free(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0091;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list_is_all_free");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue

v0002:
    v0091 = stack[0];
    if (v0091 == nil) goto v0096;
    v0091 = stack[0];
    v0091 = qcar(v0091);
    fn = elt(env, 3); // nodum_varp
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-1];
    if (v0091 == nil) goto v0167;
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    stack[0] = v0091;
    goto v0002;

v0167:
    v0091 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0091); }

v0096:
    v0091 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0091); }
// error exit handlers
v0105:
    popv(2);
    return nil;
}



// Code for mk!+real!+inner!+product

static LispObject CC_mkLrealLinnerLproduct(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0220, v0221;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+real+inner+product");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0011;
    stack[-3] = v0012;
// end of prologue
    v0220 = stack[-3];
    fn = elt(env, 5); // get!+vec!+dim
    stack[0] = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0220 = stack[-2];
    fn = elt(env, 5); // get!+vec!+dim
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    if (equal(stack[0], v0220)) goto v0105;
    v0220 = elt(env, 1); // "wrong dimensions in innerproduct"
    fn = elt(env, 6); // rederr
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    goto v0105;

v0105:
    v0221 = qvalue(elt(env, 2)); // nil
    v0220 = (LispObject)17; // 1
    v0220 = cons(v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[0] = v0220;
    v0220 = (LispObject)17; // 1
    stack[-4] = v0220;
    goto v0093;

v0093:
    v0220 = stack[-3];
    fn = elt(env, 5); // get!+vec!+dim
    v0221 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0220 = stack[-4];
    v0220 = difference2(v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0220 = Lminusp(nil, v0220);
    env = stack[-5];
    if (v0220 == nil) goto v0086;
    v0220 = qvalue(elt(env, 3)); // t
    stack[-1] = qvalue(elt(env, 4)); // !*sub2
    qvalue(elt(env, 4)) = v0220; // !*sub2
    v0220 = stack[0];
    fn = elt(env, 7); // subs2
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-5];
    stack[0] = v0220;
    qvalue(elt(env, 4)) = stack[-1]; // !*sub2
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0086:
    stack[-1] = stack[0];
    v0221 = stack[-3];
    v0220 = stack[-4];
    fn = elt(env, 8); // get!+vec!+entry
    stack[0] = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0221 = stack[-2];
    v0220 = stack[-4];
    fn = elt(env, 8); // get!+vec!+entry
    v0220 = (*qfn2(fn))(qenv(fn), v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    fn = elt(env, 9); // multsq
    v0220 = (*qfn2(fn))(qenv(fn), stack[0], v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    fn = elt(env, 10); // addsq
    v0220 = (*qfn2(fn))(qenv(fn), stack[-1], v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[0] = v0220;
    v0220 = stack[-4];
    v0220 = add1(v0220);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[-4] = v0220;
    goto v0093;
// error exit handlers
v0228:
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; // !*sub2
    popv(6);
    return nil;
v0082:
    popv(6);
    return nil;
}



// Code for pasf_smordtable1

static LispObject CC_pasf_smordtable1(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0105, v0150, v0184;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smordtable1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0105 = v0011;
    v0150 = v0012;
// end of prologue
    v0184 = elt(env, 1); // ((lessp (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (leq (lessp 1) (leq 1)
// (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (equal (lessp 1) (leq 1) (equal false) (neq 1)
// (geq false) (greaterp false) (cong nil) (ncong nil)) (neq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2)
// (cong nil) (ncong nil)) (geq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)) (greaterp
// (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)))
    v0150 = Latsoc(nil, v0150, v0184);
    v0105 = Latsoc(nil, v0105, v0150);
    v0105 = qcdr(v0105);
    return onevalue(v0105);
}



// Code for ctx_idl

static LispObject CC_ctx_idl(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0164;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ctx_idl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0164 = v0012;
// end of prologue
    fn = elt(env, 2); // ctx_ial
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-3] = v0164;
    v0164 = stack[-3];
    if (v0164 == nil) goto v0162;
    v0164 = stack[-3];
    v0164 = qcar(v0164);
    v0164 = qcar(v0164);
    v0164 = ncons(v0164);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-1] = v0164;
    stack[-2] = v0164;
    goto v0096;

v0096:
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    stack[-3] = v0164;
    v0164 = stack[-3];
    if (v0164 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0164 = stack[-3];
    v0164 = qcar(v0164);
    v0164 = qcar(v0164);
    v0164 = ncons(v0164);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0164 = Lrplacd(nil, stack[0], v0164);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0164 = stack[-1];
    v0164 = qcdr(v0164);
    stack[-1] = v0164;
    goto v0096;

v0162:
    v0164 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0164); }
// error exit handlers
v0147:
    popv(5);
    return nil;
}



// Code for max!-degree

static LispObject CC_maxKdegree(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0090, v0088, v0089, v0196;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for max-degree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0088 = v0011;
    v0089 = v0012;
// end of prologue

v0160:
    v0090 = v0089;
    if (!consp(v0090)) goto v0161;
    v0090 = v0089;
    v0090 = qcar(v0090);
    v0090 = (consp(v0090) ? nil : lisp_true);
    goto v0162;

v0162:
    if (!(v0090 == nil)) { popv(2); return onevalue(v0088); }
    v0196 = v0088;
    v0090 = v0089;
    v0090 = qcar(v0090);
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    if (((int32_t)(v0196)) > ((int32_t)(v0090))) goto v0105;
    v0090 = v0089;
    v0090 = qcdr(v0090);
    stack[0] = v0090;
    v0090 = v0089;
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    v0088 = v0089;
    v0088 = qcar(v0088);
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    v0090 = CC_maxKdegree(env, v0090, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-1];
    v0088 = v0090;
    v0090 = stack[0];
    v0089 = v0090;
    goto v0160;

v0105:
    v0090 = v0089;
    v0090 = qcdr(v0090);
    stack[0] = v0090;
    v0090 = v0089;
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    v0090 = CC_maxKdegree(env, v0090, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-1];
    v0088 = v0090;
    v0090 = stack[0];
    v0089 = v0090;
    goto v0160;

v0161:
    v0090 = qvalue(elt(env, 1)); // t
    goto v0162;
// error exit handlers
v0210:
    popv(2);
    return nil;
}



// Code for applyfnrd

static LispObject CC_applyfnrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0106, v0105;
    LispObject fn;
    argcheck(nargs, 0, "applyfnrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for applyfnrd");
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
    fn = elt(env, 2); // fnrd
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    stack[0] = v0106;
    fn = elt(env, 3); // stats_getargs
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0105 = stack[0];
    v0106 = cons(v0105, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); // aeval
        return (*qfn1(fn))(qenv(fn), v0106);
    }
// error exit handlers
v0184:
    popv(2);
    return nil;
}



// Code for close_forall

static LispObject CC_close_forall(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0152, v0217;
    LispObject fn;
    argcheck(nargs, 0, "close_forall");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for close_forall");
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
// end of prologue
    v0217 = qvalue(elt(env, 1)); // flagg
    v0152 = (LispObject)17; // 1
    if (!(v0217 == v0152)) goto v0002;
    v0152 = elt(env, 2); // "</apply>"
    fn = elt(env, 3); // printout
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    errexit();
    goto v0002;

v0002:
    v0152 = nil;
    return onevalue(v0152);
}



// Code for delyzz

static LispObject CC_delyzz(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0169, v0165, v0157;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delyzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue
    v0157 = nil;
    goto v0138;

v0138:
    v0165 = stack[-1];
    v0169 = stack[0];
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    if (equal(v0165, v0169)) goto v0091;
    v0169 = stack[0];
    v0169 = qcar(v0169);
    v0165 = v0157;
    v0169 = cons(v0169, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-2];
    v0157 = v0169;
    v0169 = stack[0];
    v0169 = qcdr(v0169);
    stack[0] = v0169;
    goto v0138;

v0091:
    v0165 = v0157;
    v0169 = stack[0];
    v0169 = qcdr(v0169);
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0165, v0169);
    }
// error exit handlers
v0158:
    popv(3);
    return nil;
}



// Code for reval3

static LispObject CC_reval3(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0096;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reval3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0096 = v0012;
// end of prologue
    fn = elt(env, 1); // simp
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // mk!*sq
        return (*qfn1(fn))(qenv(fn), v0096);
    }
// error exit handlers
v0104:
    popv(1);
    return nil;
}



// Code for s_actual_world1

static LispObject CC_s_actual_world1(LispObject env,
                         LispObject v0012)
{
    LispObject v0160;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s_actual_world1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0160 = v0012;
// end of prologue
    v0160 = qcar(v0160);
    v0160 = qcar(v0160);
    v0160 = qcar(v0160);
    return onevalue(v0160);
}



// Code for assert_procstat!-argl

static LispObject CC_assert_procstatKargl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0206, v0205, v0249;
    LispObject fn;
    argcheck(nargs, 0, "assert_procstat-argl");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_procstat-argl");
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
    stack[0] = nil;
    goto v0216;

v0216:
    v0205 = qvalue(elt(env, 1)); // cursym!*
    v0206 = elt(env, 2); // !*rpar!*
    if (v0205 == v0206) goto v0078;
    fn = elt(env, 14); // eolcheck
    v0206 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    v0206 = qvalue(elt(env, 1)); // cursym!*
    if (symbolp(v0206)) goto v0150;
    v0205 = elt(env, 4); // "Expecting identifier but found"
    v0206 = qvalue(elt(env, 1)); // cursym!*
    v0206 = list2(v0205, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    fn = elt(env, 15); // assert_rederr
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    goto v0150;

v0150:
    v0206 = qvalue(elt(env, 1)); // cursym!*
    stack[-2] = v0206;
    fn = elt(env, 16); // scan
    v0206 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    v0205 = qvalue(elt(env, 1)); // cursym!*
    v0206 = elt(env, 5); // !*colon!*
    if (v0205 == v0206) goto v0093;
    v0206 = nil;
    goto v0211;

v0211:
    v0249 = stack[-2];
    v0205 = v0206;
    v0206 = stack[0];
    v0206 = acons(v0249, v0205, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    stack[0] = v0206;
    v0205 = qvalue(elt(env, 1)); // cursym!*
    v0206 = elt(env, 7); // (!*comma!* !*rpar!*)
    v0206 = Lmemq(nil, v0205, v0206);
    if (!(v0206 == nil)) goto v0071;
    v0205 = elt(env, 8); // "Expecting ',' or ')' but found"
    v0206 = qvalue(elt(env, 1)); // cursym!*
    v0206 = list2(v0205, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    fn = elt(env, 15); // assert_rederr
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    goto v0071;

v0071:
    v0205 = qvalue(elt(env, 1)); // cursym!*
    v0206 = elt(env, 9); // !*comma!*
    if (!(v0205 == v0206)) goto v0216;
    fn = elt(env, 16); // scan
    v0206 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    goto v0216;

v0093:
    fn = elt(env, 16); // scan
    v0206 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    v0206 = qvalue(elt(env, 1)); // cursym!*
    fn = elt(env, 17); // assert_typesyntaxp
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    if (!(v0206 == nil)) goto v0159;
    v0205 = elt(env, 6); // "Expecting type but found"
    v0206 = qvalue(elt(env, 1)); // cursym!*
    v0206 = list2(v0205, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    fn = elt(env, 15); // assert_rederr
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    goto v0159;

v0159:
    v0206 = qvalue(elt(env, 1)); // cursym!*
    stack[-1] = v0206;
    fn = elt(env, 16); // scan
    v0206 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    v0206 = stack[-1];
    goto v0211;

v0078:
    v0205 = qvalue(elt(env, 10)); // nxtsym!*
    v0206 = elt(env, 5); // !*colon!*
    if (v0205 == v0206) goto v0079;
    v0205 = qvalue(elt(env, 10)); // nxtsym!*
    v0206 = elt(env, 12); // !:
    v0206 = (v0205 == v0206 ? lisp_true : nil);
    goto v0238;

v0238:
    if (v0206 == nil) goto v0192;
    fn = elt(env, 16); // scan
    v0206 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    fn = elt(env, 16); // scan
    v0206 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    v0206 = qvalue(elt(env, 1)); // cursym!*
    fn = elt(env, 17); // assert_typesyntaxp
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    if (!(v0206 == nil)) goto v0251;
    v0205 = elt(env, 6); // "Expecting type but found"
    v0206 = qvalue(elt(env, 1)); // cursym!*
    v0206 = list2(v0205, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    fn = elt(env, 15); // assert_rederr
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-3];
    goto v0251;

v0251:
    v0206 = qvalue(elt(env, 1)); // cursym!*
    goto v0252;

v0252:
    v0249 = elt(env, 13); // returnvalue
    v0205 = v0206;
    v0206 = stack[0];
    v0206 = acons(v0249, v0205, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    stack[0] = v0206;
    v0206 = stack[0];
        popv(4);
        return Lnreverse(nil, v0206);

v0192:
    v0206 = nil;
    goto v0252;

v0079:
    v0206 = qvalue(elt(env, 11)); // t
    goto v0238;
// error exit handlers
v0250:
    popv(4);
    return nil;
}



// Code for subs2chk

static LispObject CC_subs2chk(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0150, v0184, v0170;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2chk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue
    v0150 = qvalue(elt(env, 1)); // subfg!*
    if (v0150 == nil) { LispObject res = stack[0]; popv(1); return onevalue(res); }
    v0150 = stack[0];
    fn = elt(env, 2); // subs2f
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0170 = v0150;
    v0184 = qcdr(v0150);
    v0150 = (LispObject)17; // 1
    if (!(v0184 == v0150)) { LispObject res = stack[0]; popv(1); return onevalue(res); }
    v0150 = v0170;
    v0150 = qcar(v0150);
    stack[0] = v0150;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }
// error exit handlers
v0214:
    popv(1);
    return nil;
}



// Code for remchkf

static LispObject CC_remchkf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0089, v0196, v0211;
    LispObject fn;
    LispObject v0010, v0011, v0012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "remchkf");
    va_start(aa, nargs);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remchkf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0012,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0010;
    stack[-1] = v0011;
    stack[-2] = v0012;
// end of prologue
    v0196 = stack[-2];
    v0089 = stack[-1];
    fn = elt(env, 2); // remchkf1
    v0089 = (*qfn2(fn))(qenv(fn), v0196, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-3] = v0089;
    v0089 = stack[-3];
    if (!consp(v0089)) goto v0105;
    v0089 = stack[-3];
    v0089 = qcar(v0089);
    v0089 = (consp(v0089) ? nil : lisp_true);
    goto v0106;

v0106:
    if (v0089 == nil) goto v0149;
    v0089 = qvalue(elt(env, 1)); // t
    goto v0167;

v0167:
    if (!(v0089 == nil)) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0089 = stack[-3];
    stack[-2] = qcar(v0089);
    v0089 = stack[-3];
    v0211 = qcdr(v0089);
    v0196 = stack[-1];
    v0089 = stack[0];
    v0089 = CC_remchkf(env, 3, v0211, v0196, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    {
        LispObject v0253 = stack[-2];
        popv(5);
        return cons(v0253, v0089);
    }

v0149:
    v0089 = stack[-2];
    fn = elt(env, 3); // kernels
    v0196 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0089 = stack[0];
    fn = elt(env, 4); // intersection
    v0089 = (*qfn2(fn))(qenv(fn), v0196, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0089 = (v0089 == nil ? lisp_true : nil);
    goto v0167;

v0105:
    v0089 = qvalue(elt(env, 1)); // t
    goto v0106;
// error exit handlers
v0111:
    popv(5);
    return nil;
}



// Code for fs!:onep!:

static LispObject CC_fsTonepT(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0224;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:onep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0224 = v0012;
// end of prologue
    v0224 = qcdr(v0224);
    {
        fn = elt(env, 1); // fs!:onep
        return (*qfn1(fn))(qenv(fn), v0224);
    }
}



// Code for dfprintfn

static LispObject CC_dfprintfn(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0087, v0171, v0144;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfprintfn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0087 = v0012;
// end of prologue
    v0171 = qvalue(elt(env, 1)); // !*nat
    if (v0171 == nil) goto v0104;
    v0171 = qvalue(elt(env, 3)); // !*fort
    if (!(v0171 == nil)) goto v0096;
    v0171 = qvalue(elt(env, 4)); // !*dfprint
    v0171 = (v0171 == nil ? lisp_true : nil);
    goto v0096;

v0096:
    if (v0171 == nil) goto v0174;
    v0087 = elt(env, 5); // failed
    { popv(1); return onevalue(v0087); }

v0174:
    v0171 = elt(env, 6); // !!df!!
    v0087 = qcdr(v0087);
    v0144 = cons(v0171, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[0];
    v0171 = (LispObject)1; // 0
    v0087 = qvalue(elt(env, 7)); // nil
    fn = elt(env, 8); // layout!-formula
    v0087 = (*qfnn(fn))(qenv(fn), 3, v0144, v0171, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[0];
    v0171 = v0087;
    v0087 = v0171;
    if (v0087 == nil) goto v0158;
    v0087 = v0171;
    fn = elt(env, 9); // putpline
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    v0087 = nil;
    { popv(1); return onevalue(v0087); }

v0158:
    v0087 = elt(env, 5); // failed
    { popv(1); return onevalue(v0087); }

v0104:
    v0171 = qvalue(elt(env, 2)); // t
    goto v0096;
// error exit handlers
v0145:
    popv(1);
    return nil;
}



// Code for ad_splitname

static LispObject CC_ad_splitname(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0234, v0199;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ad_splitname");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0199 = v0012;
// end of prologue
    v0234 = v0199;
    if (symbolp(v0234)) goto v0002;
    v0234 = nil;
    { popv(3); return onevalue(v0234); }

v0002:
    stack[0] = nil;
    v0234 = v0199;
    v0234 = Lexplode(nil, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0234 = Lreverse(nil, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    stack[-1] = v0234;
    goto v0152;

v0152:
    v0234 = stack[-1];
    if (v0234 == nil) goto v0151;
    v0234 = stack[-1];
    v0234 = qcar(v0234);
    fn = elt(env, 2); // charnump!:
    v0234 = (*qfn1(fn))(qenv(fn), v0234);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0234 == nil) goto v0151;
    v0234 = stack[-1];
    v0199 = qcar(v0234);
    v0234 = stack[0];
    v0234 = cons(v0199, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    stack[0] = v0234;
    v0234 = stack[-1];
    v0234 = qcdr(v0234);
    stack[-1] = v0234;
    goto v0152;

v0151:
    v0234 = stack[-1];
    if (v0234 == nil) goto v0093;
    v0234 = stack[-1];
    v0234 = Lreverse(nil, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0234 = Lcompress(nil, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0234 = Lintern(nil, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    stack[-1] = v0234;
    goto v0093;

v0093:
    v0234 = stack[0];
    if (v0234 == nil) goto v0144;
    v0234 = stack[0];
    v0234 = Lcompress(nil, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    stack[0] = v0234;
    goto v0144;

v0144:
    v0199 = stack[-1];
    v0234 = stack[0];
    popv(3);
    return cons(v0199, v0234);
// error exit handlers
v0089:
    popv(3);
    return nil;
}



// Code for comb

static LispObject CC_comb(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0213, v0247, v0242;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0011;
    stack[-4] = v0012;
// end of prologue
    stack[-5] = nil;
    v0247 = stack[-3];
    v0213 = (LispObject)1; // 0
    if (v0247 == v0213) goto v0138;
    v0213 = stack[-4];
    v0247 = Llength(nil, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-6];
    v0213 = stack[-3];
    v0247 = difference2(v0247, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-6];
    stack[-2] = v0247;
    v0213 = (LispObject)1; // 0
    v0213 = (LispObject)lessp2(v0247, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0213 = v0213 ? lisp_true : nil;
    env = stack[-6];
    if (v0213 == nil) goto v0137;
    v0213 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0213); }

v0137:
    v0213 = (LispObject)17; // 1
    stack[-1] = v0213;
    goto v0159;

v0159:
    v0247 = stack[-2];
    v0213 = stack[-1];
    v0213 = difference2(v0247, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-6];
    v0213 = Lminusp(nil, v0213);
    env = stack[-6];
    if (v0213 == nil) goto v0222;
    v0247 = stack[-4];
    v0213 = stack[-5];
    popv(7);
    return cons(v0247, v0213);

v0222:
    v0213 = stack[-4];
    stack[0] = qcdr(v0213);
    v0213 = stack[-3];
    v0213 = sub1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-6];
    v0213 = CC_comb(env, stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-6];
    stack[0] = v0213;
    goto v0080;

v0080:
    v0213 = stack[0];
    if (v0213 == nil) goto v0143;
    v0213 = stack[0];
    v0213 = qcar(v0213);
    v0247 = stack[-4];
    v0242 = qcar(v0247);
    v0247 = v0213;
    v0213 = stack[-5];
    v0213 = acons(v0242, v0247, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-6];
    stack[-5] = v0213;
    v0213 = stack[0];
    v0213 = qcdr(v0213);
    stack[0] = v0213;
    goto v0080;

v0143:
    v0213 = stack[-4];
    v0213 = qcdr(v0213);
    stack[-4] = v0213;
    v0213 = stack[-1];
    v0213 = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-6];
    stack[-1] = v0213;
    goto v0159;

v0138:
    v0213 = qvalue(elt(env, 1)); // nil
    popv(7);
    return ncons(v0213);
// error exit handlers
v0238:
    popv(7);
    return nil;
}



// Code for qqe_ofsf_varlat

static LispObject CC_qqe_ofsf_varlat(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0154, v0095;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_varlat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0154 = v0012;
// end of prologue
    fn = elt(env, 2); // qqe_ofsf_prepat
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-2];
    stack[-1] = v0154;
    v0154 = stack[-1];
    fn = elt(env, 3); // qqe_arg2l
    v0095 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-2];
    v0154 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 4); // qqe_ofsf_varlterm
    stack[0] = (*qfn2(fn))(qenv(fn), v0095, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-2];
    v0154 = stack[-1];
    fn = elt(env, 5); // qqe_arg2r
    v0095 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-2];
    v0154 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 4); // qqe_ofsf_varlterm
    v0154 = (*qfn2(fn))(qenv(fn), v0095, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-2];
    {
        LispObject v0176 = stack[0];
        popv(3);
        fn = elt(env, 6); // union
        return (*qfn2(fn))(qenv(fn), v0176, v0154);
    }
// error exit handlers
v0172:
    popv(3);
    return nil;
}



// Code for iv_cutcongs1

static LispObject CC_iv_cutcongs1(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0166, v0172;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for iv_cutcongs1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue

v0224:
    v0166 = stack[0];
    if (v0166 == nil) goto v0154;
    v0172 = stack[-1];
    v0166 = stack[0];
    v0166 = qcar(v0166);
    fn = elt(env, 3); // iv_cutcongs2
    v0166 = (*qfn2(fn))(qenv(fn), v0172, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (v0166 == nil) goto v0170;
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    stack[0] = v0166;
    goto v0224;

v0170:
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0166); }

v0154:
    v0166 = qvalue(elt(env, 2)); // t
    { popv(3); return onevalue(v0166); }
// error exit handlers
v0149:
    popv(3);
    return nil;
}



// Code for aex_subrat1

static LispObject CC_aex_subrat1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0092, v0093, v0169;
    LispObject fn;
    LispObject v0010, v0011, v0012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_subrat1");
    va_start(aa, nargs);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_subrat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0012,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0010;
    stack[-1] = v0011;
    stack[-2] = v0012;
// end of prologue
    v0092 = stack[-2];
    fn = elt(env, 1); // aex_ex
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    v0169 = qcar(v0092);
    v0093 = stack[-1];
    v0092 = stack[0];
    fn = elt(env, 2); // sfto_qsubhor1
    v0092 = (*qfnn(fn))(qenv(fn), 3, v0169, v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    stack[-1] = v0092;
    v0092 = qcar(v0092);
    fn = elt(env, 3); // kernels
    stack[0] = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    v0092 = stack[-2];
    fn = elt(env, 4); // aex_ctx
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    fn = elt(env, 5); // ctx_filter
    v0092 = (*qfn2(fn))(qenv(fn), stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    {
        LispObject v0158 = stack[-1];
        popv(4);
        fn = elt(env, 6); // aex_mk
        return (*qfn2(fn))(qenv(fn), v0158, v0092);
    }
// error exit handlers
v0235:
    popv(4);
    return nil;
}



// Code for bc_mkat

static LispObject CC_bc_mkat(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0151, v0152, v0217;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_mkat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0151 = v0011;
    v0152 = v0012;
// end of prologue
    v0151 = qcar(v0151);
    v0217 = qvalue(elt(env, 1)); // nil
    return list3(v0152, v0151, v0217);
}



// Code for vectorml

static LispObject CC_vectorml(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0163, v0214;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vectorml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue
    v0163 = elt(env, 1); // "<vector>"
    fn = elt(env, 4); // printout
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    v0214 = qvalue(elt(env, 2)); // indent
    v0163 = (LispObject)49; // 3
    v0163 = plus2(v0214, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0163; // indent
    v0163 = stack[0];
    v0163 = qcar(v0163);
    fn = elt(env, 5); // multi_elem
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    v0214 = qvalue(elt(env, 2)); // indent
    v0163 = (LispObject)49; // 3
    v0163 = difference2(v0214, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0163; // indent
    v0163 = elt(env, 3); // "</vector>"
    fn = elt(env, 4); // printout
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    v0163 = nil;
    { popv(2); return onevalue(v0163); }
// error exit handlers
v0095:
    popv(2);
    return nil;
}



// Code for sc_subtrsq

static LispObject CC_sc_subtrsq(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0162, v0161;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_subtrsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0162 = v0011;
    v0161 = v0012;
// end of prologue
    stack[0] = v0161;
    fn = elt(env, 1); // negsq
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-1];
    {
        LispObject v0152 = stack[0];
        popv(2);
        fn = elt(env, 2); // addsq
        return (*qfn2(fn))(qenv(fn), v0152, v0162);
    }
// error exit handlers
v0151:
    popv(2);
    return nil;
}



// Code for toolongexpp

static LispObject CC_toolongexpp(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0138, v0162;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for toolongexpp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0138 = v0012;
// end of prologue
    fn = elt(env, 2); // numprintlen
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[0];
    v0162 = qvalue(elt(env, 1)); // maxexpprintlen!*
        popv(1);
        return Lgreaterp(nil, v0138, v0162);
// error exit handlers
v0161:
    popv(1);
    return nil;
}



// Code for find_buble

static LispObject CC_find_buble(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0166, v0172;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find_buble");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue

v0243:
    v0166 = stack[0];
    if (v0166 == nil) goto v0224;
    v0172 = stack[-1];
    v0166 = stack[0];
    v0166 = qcar(v0166);
    fn = elt(env, 2); // is_buble
    v0166 = (*qfn2(fn))(qenv(fn), v0172, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (!(v0166 == nil)) { popv(3); return onevalue(v0166); }
    v0172 = stack[-1];
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    stack[-1] = v0172;
    stack[0] = v0166;
    goto v0243;

v0224:
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0166); }
// error exit handlers
v0149:
    popv(3);
    return nil;
}



// Code for assert_structstat

static LispObject CC_assert_structstat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0259, v0260, v0261;
    LispObject fn;
    argcheck(nargs, 0, "assert_structstat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_structstat");
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
    push5(nil, nil, nil, nil, nil);
// end of prologue
    fn = elt(env, 17); // scan
    v0259 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    stack[0] = v0259;
    stack[-1] = elt(env, 1); // flag
    v0259 = stack[0];
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    v0260 = Lmkquote(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    v0259 = elt(env, 2); // (quote assert_dyntype)
    v0259 = list3(stack[-1], v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    stack[-3] = v0259;
    fn = elt(env, 17); // scan
    v0259 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    v0259 = qvalue(elt(env, 3)); // cursym!*
    if (!symbolp(v0259)) v0259 = nil;
    else { v0259 = qfastgets(v0259);
           if (v0259 != nil) { v0259 = elt(v0259, 55); // delim
#ifdef RECORD_GET
             if (v0259 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0259 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0259 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0259 == SPID_NOPROP) v0259 = nil; else v0259 = lisp_true; }}
#endif
    if (v0259 == nil) goto v0085;
    v0259 = qvalue(elt(env, 4)); // !*msg
    if (v0259 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0261 = elt(env, 5); // "struct"
    v0260 = stack[0];
    v0259 = elt(env, 6); // "is not checked"
    v0259 = list3(v0261, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    fn = elt(env, 18); // lprim
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    { LispObject res = stack[-3]; popv(6); return onevalue(res); }

v0085:
    v0260 = qvalue(elt(env, 3)); // cursym!*
    v0259 = elt(env, 7); // checked
    if (v0260 == v0259) goto v0196;
    v0260 = qvalue(elt(env, 3)); // cursym!*
    v0259 = elt(env, 8); // asserted
    v0259 = Lneq(nil, v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    goto v0086;

v0086:
    if (v0259 == nil) goto v0240;
    v0260 = elt(env, 10); // "expecting 'asserted by' in struct but found"
    v0259 = qvalue(elt(env, 3)); // cursym!*
    v0259 = list2(v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    fn = elt(env, 19); // rederr
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    goto v0240;

v0240:
    fn = elt(env, 17); // scan
    v0260 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    v0259 = elt(env, 11); // by
    if (v0260 == v0259) goto v0084;
    v0260 = elt(env, 12); // "expecting 'by' in struct but found"
    v0259 = qvalue(elt(env, 3)); // cursym!*
    v0259 = list2(v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    fn = elt(env, 19); // rederr
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    goto v0084;

v0084:
    fn = elt(env, 17); // scan
    v0259 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    stack[-4] = v0259;
    fn = elt(env, 17); // scan
    v0259 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    if (!symbolp(v0259)) v0259 = nil;
    else { v0259 = qfastgets(v0259);
           if (v0259 != nil) { v0259 = elt(v0259, 55); // delim
#ifdef RECORD_GET
             if (v0259 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0259 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0259 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0259 == SPID_NOPROP) v0259 = nil; else v0259 = lisp_true; }}
#endif
    if (!(v0259 == nil)) goto v0193;
    v0260 = elt(env, 13); // "expecting end of struct but found"
    v0259 = qvalue(elt(env, 3)); // cursym!*
    v0259 = list2(v0260, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    fn = elt(env, 19); // rederr
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    goto v0193;

v0193:
    stack[-2] = elt(env, 14); // put
    v0259 = stack[0];
    stack[-1] = Lmkquote(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    stack[0] = elt(env, 15); // (quote assert_dyntypechk)
    v0259 = stack[-4];
    v0259 = Lmkquote(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    v0259 = list4(stack[-2], stack[-1], stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    v0261 = elt(env, 16); // progn
    v0260 = v0259;
    v0259 = stack[-3];
    popv(6);
    return list3(v0261, v0260, v0259);

v0196:
    v0259 = qvalue(elt(env, 9)); // nil
    goto v0086;
// error exit handlers
v0178:
    popv(6);
    return nil;
}



// Code for fs!:prin

static LispObject CC_fsTprin(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0148, v0177;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:prin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue
    v0148 = stack[0];
    if (!(v0148 == nil)) goto v0161;
    v0148 = elt(env, 1); // " 0 "
    {
        popv(2);
        fn = elt(env, 4); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0148);
    }

v0161:
    v0148 = stack[0];
    if (v0148 == nil) goto v0152;
    v0148 = stack[0];
    fn = elt(env, 5); // fs!:prin1
    v0148 = (*qfn1(fn))(qenv(fn), v0148);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0177 = stack[0];
    v0148 = (LispObject)49; // 3
    v0148 = *(LispObject *)((char *)v0177 + (CELL-TAG_VECTOR) + ((int32_t)v0148/(16/CELL)));
    stack[0] = v0148;
    v0148 = stack[0];
    if (v0148 == nil) goto v0161;
    v0148 = elt(env, 3); // " + "
    fn = elt(env, 4); // prin2!*
    v0148 = (*qfn1(fn))(qenv(fn), v0148);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    goto v0161;

v0152:
    v0148 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0148); }
// error exit handlers
v0092:
    popv(2);
    return nil;
}



// Code for mo_zero!?

static LispObject CC_mo_zeroW(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0224;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_zero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0224 = v0012;
// end of prologue
    v0224 = qcar(v0224);
    {
        fn = elt(env, 1); // mo!=zero
        return (*qfn1(fn))(qenv(fn), v0224);
    }
}



// Code for plusdf

static LispObject CC_plusdf(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0076, v0074, v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plusdf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0011;
    stack[-2] = v0012;
// end of prologue
    stack[0] = nil;
    goto v0160;

v0160:
    v0076 = stack[-2];
    if (v0076 == nil) goto v0161;
    v0076 = stack[-1];
    if (v0076 == nil) goto v0150;
    v0076 = stack[-2];
    v0076 = qcar(v0076);
    v0074 = qcar(v0076);
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    v0076 = qcar(v0076);
    if (equal(v0074, v0076)) goto v0164;
    v0076 = stack[-2];
    v0076 = qcar(v0076);
    v0074 = qcar(v0076);
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    v0076 = qcar(v0076);
    fn = elt(env, 1); // orddf
    v0076 = (*qfn2(fn))(qenv(fn), v0074, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    if (v0076 == nil) goto v0263;
    v0076 = stack[-2];
    v0074 = qcar(v0076);
    v0076 = stack[0];
    v0076 = cons(v0074, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    stack[0] = v0076;
    v0076 = stack[-2];
    v0076 = qcdr(v0076);
    stack[-2] = v0076;
    goto v0160;

v0263:
    v0076 = stack[-1];
    v0074 = qcar(v0076);
    v0076 = stack[0];
    v0076 = cons(v0074, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    stack[0] = v0076;
    v0076 = stack[-1];
    v0076 = qcdr(v0076);
    stack[-1] = v0076;
    goto v0160;

v0164:
    stack[-3] = stack[0];
    v0076 = stack[-2];
    v0076 = qcar(v0076);
    v0074 = qcdr(v0076);
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    v0076 = qcdr(v0076);
    fn = elt(env, 2); // !*addsq
    stack[0] = (*qfn2(fn))(qenv(fn), v0074, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    v0076 = stack[-2];
    v0074 = qcdr(v0076);
    v0076 = stack[-1];
    v0076 = qcdr(v0076);
    v0076 = CC_plusdf(env, v0074, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    v0074 = stack[0];
    v0075 = v0074;
    v0075 = qcar(v0075);
    if (v0075 == nil) goto v0155;
    v0075 = stack[-2];
    v0075 = qcar(v0075);
    v0075 = qcar(v0075);
    v0076 = acons(v0075, v0074, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-4];
    goto v0155;

v0155:
    {
        LispObject v0251 = stack[-3];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0251, v0076);
    }

v0150:
    v0074 = stack[0];
    v0076 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0074, v0076);
    }

v0161:
    v0074 = stack[0];
    v0076 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0074, v0076);
    }
// error exit handlers
v0113:
    popv(5);
    return nil;
}



// Code for tayexp!-max2

static LispObject CC_tayexpKmax2(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0215, v0175;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-max2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue
    v0175 = stack[-1];
    v0215 = stack[0];
    fn = elt(env, 1); // tayexp!-lessp
    v0215 = (*qfn2(fn))(qenv(fn), v0175, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    if (v0215 == nil) { LispObject res = stack[-1]; popv(2); return onevalue(res); }
    else { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0105:
    popv(2);
    return nil;
}



// Code for give!*position

static LispObject CC_giveHposition(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0090, v0088;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for give*position");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0011;
    stack[-3] = v0012;
// end of prologue
    v0090 = (LispObject)17; // 1
    stack[-4] = v0090;
    v0090 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0090;
    goto v0138;

v0138:
    v0090 = stack[-1];
    if (v0090 == nil) goto v0106;
    v0090 = qvalue(elt(env, 1)); // nil
    goto v0217;

v0217:
    if (v0090 == nil) goto v0137;
    v0088 = stack[-2];
    v0090 = stack[-4];
    fn = elt(env, 4); // nth
    v0088 = (*qfn2(fn))(qenv(fn), v0088, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-5];
    v0090 = stack[-3];
    if (equal(v0088, v0090)) goto v0149;
    v0090 = stack[-4];
    v0090 = add1(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-5];
    stack[-4] = v0090;
    goto v0138;

v0149:
    v0090 = qvalue(elt(env, 2)); // t
    stack[-1] = v0090;
    goto v0138;

v0137:
    v0090 = stack[-1];
    if (!(v0090 == nil)) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0090 = elt(env, 3); // "error in give position"
    fn = elt(env, 5); // rederr
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    { LispObject res = stack[-4]; popv(6); return onevalue(res); }

v0106:
    stack[0] = stack[-4];
    v0090 = stack[-2];
    v0090 = Llength(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-5];
    v0090 = (LispObject)lesseq2(stack[0], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    v0090 = v0090 ? lisp_true : nil;
    env = stack[-5];
    goto v0217;
// error exit handlers
v0080:
    popv(6);
    return nil;
}



// Code for listrd

static LispObject CC_listrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0140, v0081, v0082;
    LispObject fn;
    argcheck(nargs, 0, "listrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listrd");
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
    v0081 = qvalue(elt(env, 1)); // atts
    v0140 = elt(env, 2); // (o r d e r)
    fn = elt(env, 11); // search_att
    v0140 = (*qfn2(fn))(qenv(fn), v0081, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    stack[-1] = v0140;
    v0140 = elt(env, 3); // (t y p e != l i s t !$)
    qvalue(elt(env, 1)) = v0140; // atts
    stack[0] = elt(env, 4); // list
    fn = elt(env, 12); // stats_getargs
    v0140 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    v0140 = cons(stack[0], v0140);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    v0081 = v0140;
    stack[0] = v0081;
    v0082 = stack[-1];
    v0081 = elt(env, 5); // (l e x i c o g r a p h i c)
    if (!(equal(v0082, v0081))) goto v0086;
    v0081 = elt(env, 6); // sortlist
    v0082 = v0140;
    v0140 = elt(env, 7); // lexog
    v0140 = list3(v0081, v0082, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    fn = elt(env, 13); // aeval
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    goto v0086;

v0086:
    v0082 = stack[-1];
    v0081 = elt(env, 8); // (n u m e r i c)
    if (equal(v0082, v0081)) goto v0236;
    v0082 = elt(env, 6); // sortlist
    v0081 = v0140;
    v0140 = elt(env, 10); // pred
    v0140 = list3(v0082, v0081, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    fn = elt(env, 13); // aeval
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    goto v0155;

v0155:
    v0081 = v0140;
    if (!(v0081 == nil)) { popv(3); return onevalue(v0140); }
    v0140 = stack[0];
    { popv(3); return onevalue(v0140); }

v0236:
    v0082 = elt(env, 6); // sortlist
    v0081 = v0140;
    v0140 = elt(env, 9); // numer
    v0140 = list3(v0082, v0081, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    fn = elt(env, 13); // aeval
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    goto v0155;
// error exit handlers
v0153:
    popv(3);
    return nil;
}



// Code for multerm

static LispObject CC_multerm(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0172, v0176;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multerm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0012;
// end of prologue
    v0172 = stack[-1];
    v0176 = qcdr(v0172);
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    fn = elt(env, 1); // !*multsq
    v0172 = (*qfn2(fn))(qenv(fn), v0176, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-3];
    stack[-2] = v0172;
    v0172 = stack[-1];
    v0176 = qcar(v0172);
    v0172 = stack[0];
    v0172 = qcar(v0172);
    fn = elt(env, 2); // mulpower
    v0172 = (*qfn2(fn))(qenv(fn), v0176, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-3];
    {
        LispObject v0173 = stack[-2];
        popv(4);
        fn = elt(env, 3); // multdfconst
        return (*qfn2(fn))(qenv(fn), v0173, v0172);
    }
// error exit handlers
v0177:
    popv(4);
    return nil;
}



// Code for matrixp

static LispObject CC_matrixp(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0167, v0215;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0167 = v0012;
// end of prologue
    v0215 = v0167;
    v0167 = elt(env, 1); // mat
    if (!consp(v0215)) goto v0002;
    v0215 = qcar(v0215);
    if (!(v0215 == v0167)) goto v0002;
    v0167 = qvalue(elt(env, 3)); // t
    return onevalue(v0167);

v0002:
    v0167 = qvalue(elt(env, 2)); // nil
    return onevalue(v0167);
}



// Code for make!-unique!-freevars

static LispObject CC_makeKuniqueKfreevars(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0242, v0233, v0244;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-unique-freevars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0233 = v0012;
// end of prologue
    v0242 = v0233;
    if (!consp(v0242)) goto v0162;
    v0242 = v0233;
    stack[-3] = v0242;
    v0242 = stack[-3];
    if (v0242 == nil) goto v0197;
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = CC_makeKuniqueKfreevars(env, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    v0242 = ncons(v0242);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    stack[-1] = v0242;
    stack[-2] = v0242;
    goto v0111;

v0111:
    v0242 = stack[-3];
    v0242 = qcdr(v0242);
    stack[-3] = v0242;
    v0242 = stack[-3];
    if (v0242 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = CC_makeKuniqueKfreevars(env, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    v0242 = ncons(v0242);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    v0242 = Lrplacd(nil, stack[0], v0242);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    v0242 = stack[-1];
    v0242 = qcdr(v0242);
    stack[-1] = v0242;
    goto v0111;

v0197:
    v0242 = qvalue(elt(env, 4)); // nil
    { popv(5); return onevalue(v0242); }

v0162:
    v0244 = v0233;
    v0242 = elt(env, 1); // gen
    v0242 = get(v0244, v0242);
    env = stack[-4];
    if (v0242 == nil) { popv(5); return onevalue(v0233); }
    v0244 = v0233;
    v0242 = qvalue(elt(env, 2)); // freevarlist!*
    v0242 = Latsoc(nil, v0244, v0242);
    stack[0] = v0242;
    v0242 = stack[0];
    if (!(v0242 == nil)) goto v0094;
    stack[0] = v0233;
    fn = elt(env, 5); // pm!:gensym
    v0242 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    v0242 = cons(stack[0], v0242);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    stack[0] = v0242;
    v0242 = stack[0];
    v0244 = qcdr(v0242);
    v0233 = elt(env, 1); // gen
    v0242 = qvalue(elt(env, 3)); // t
    v0242 = Lputprop(nil, 3, v0244, v0233, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    v0233 = stack[0];
    v0242 = qvalue(elt(env, 2)); // freevarlist!*
    v0242 = cons(v0233, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0242; // freevarlist!*
    goto v0094;

v0094:
    v0242 = stack[0];
    v0242 = qcdr(v0242);
    { popv(5); return onevalue(v0242); }
// error exit handlers
v0238:
    popv(5);
    return nil;
}



// Code for fieldp

static LispObject CC_fieldp(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0161, v0216;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fieldp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0216 = v0012;
// end of prologue
    v0161 = v0216;
    if (!consp(v0161)) goto v0137;
    v0161 = v0216;
    v0161 = qcar(v0161);
    if (!symbolp(v0161)) v0161 = nil;
    else { v0161 = qfastgets(v0161);
           if (v0161 != nil) { v0161 = elt(v0161, 3); // field
#ifdef RECORD_GET
             if (v0161 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0161 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0161 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0161 == SPID_NOPROP) v0161 = nil; else v0161 = lisp_true; }}
#endif
    return onevalue(v0161);

v0137:
    v0161 = qvalue(elt(env, 1)); // nil
    return onevalue(v0161);
}



// Code for noncomexpf

static LispObject CC_noncomexpf(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0177;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomexpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue

v0243:
    v0177 = stack[0];
    if (!consp(v0177)) goto v0104;
    v0177 = stack[0];
    v0177 = qcar(v0177);
    v0177 = (consp(v0177) ? nil : lisp_true);
    goto v0096;

v0096:
    if (v0177 == nil) goto v0002;
    v0177 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0177); }

v0002:
    v0177 = stack[0];
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    v0177 = qcar(v0177);
    fn = elt(env, 3); // noncomp
    v0177 = (*qfn1(fn))(qenv(fn), v0177);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    if (!(v0177 == nil)) { popv(2); return onevalue(v0177); }
    v0177 = stack[0];
    v0177 = qcar(v0177);
    v0177 = qcdr(v0177);
    v0177 = CC_noncomexpf(env, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    if (!(v0177 == nil)) { popv(2); return onevalue(v0177); }
    v0177 = stack[0];
    v0177 = qcdr(v0177);
    stack[0] = v0177;
    goto v0243;

v0104:
    v0177 = qvalue(elt(env, 1)); // t
    goto v0096;
// error exit handlers
v0092:
    popv(2);
    return nil;
}



// Code for sc_mkmatrix

static LispObject CC_sc_mkmatrix(LispObject env,
                         LispObject v0012, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0084, v0083, v0230;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_mkmatrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0011;
    stack[-6] = v0012;
// end of prologue
    v0084 = stack[-6];
    v0084 = sub1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    v0084 = Lmkvect(nil, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    stack[-7] = v0084;
    v0084 = (LispObject)1; // 0
    stack[-3] = v0084;
    goto v0091;

v0091:
    v0084 = stack[-6];
    v0083 = sub1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    v0084 = stack[-3];
    v0084 = difference2(v0083, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    v0084 = Lminusp(nil, v0084);
    env = stack[-8];
    if (!(v0084 == nil)) { LispObject res = stack[-7]; popv(9); return onevalue(res); }
    v0084 = stack[-5];
    v0084 = sub1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    v0084 = Lmkvect(nil, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    stack[-4] = v0084;
    v0084 = (LispObject)1; // 0
    stack[-2] = v0084;
    goto v0157;

v0157:
    v0084 = stack[-5];
    v0083 = sub1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    v0084 = stack[-2];
    v0084 = difference2(v0083, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    v0084 = Lminusp(nil, v0084);
    env = stack[-8];
    if (v0084 == nil) goto v0085;
    v0230 = stack[-7];
    v0083 = stack[-3];
    v0084 = stack[-4];
    fn = elt(env, 2); // sc_iputv
    v0084 = (*qfnn(fn))(qenv(fn), 3, v0230, v0083, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    v0084 = stack[-3];
    v0084 = add1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    stack[-3] = v0084;
    goto v0091;

v0085:
    stack[-1] = stack[-4];
    stack[0] = stack[-2];
    v0084 = (LispObject)1; // 0
    fn = elt(env, 3); // sc_simp
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    fn = elt(env, 2); // sc_iputv
    v0084 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    v0084 = stack[-2];
    v0084 = add1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-8];
    stack[-2] = v0084;
    goto v0157;
// error exit handlers
v0082:
    popv(9);
    return nil;
}



// Code for exdfprn

static LispObject CC_exdfprn(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0104;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exdfprn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0012;
// end of prologue
    v0104 = elt(env, 1); // "d"
    fn = elt(env, 2); // prin2!*
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-1];
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    v0104 = qcar(v0104);
    {
        popv(2);
        fn = elt(env, 3); // rembras
        return (*qfn1(fn))(qenv(fn), v0104);
    }
// error exit handlers
v0137:
    popv(2);
    return nil;
}



// Code for evalb

static LispObject CC_evalb(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0106, v0105, v0150;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0106 = v0012;
// end of prologue
    v0150 = v0106;
    v0105 = qvalue(elt(env, 1)); // nil
    v0106 = elt(env, 2); // algebraic
    fn = elt(env, 5); // formbool
    v0106 = (*qfnn(fn))(qenv(fn), 3, v0150, v0105, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[0];
    fn = elt(env, 6); // eval
    v0106 = (*qfn1(fn))(qenv(fn), v0106);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[0];
    if (v0106 == nil) goto v0215;
    v0106 = elt(env, 3); // true
    { popv(1); return onevalue(v0106); }

v0215:
    v0106 = elt(env, 4); // false
    { popv(1); return onevalue(v0106); }
// error exit handlers
v0184:
    popv(1);
    return nil;
}



// Code for lispreadp

static LispObject CC_lispreadp(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0137, v0138;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispreadp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0137 = v0012;
// end of prologue
    v0138 = elt(env, 1); // read
        return Leqcar(nil, v0137, v0138);
}



// Code for indexsymmetrize

static LispObject CC_indexsymmetrize(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0080, v0112, v0111;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indexsymmetrize");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0012;
// end of prologue
    v0080 = stack[-2];
    v0112 = qcar(v0080);
    v0080 = elt(env, 1); // indxsymmetrize
    v0080 = get(v0112, v0080);
    env = stack[-4];
    stack[-3] = v0080;
    v0080 = (LispObject)17; // 1
    stack[0] = v0080;
    v0112 = (LispObject)17; // 1
    v0080 = stack[-2];
    v0080 = qcdr(v0080);
    v0080 = cons(v0112, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    stack[-1] = v0080;
    goto v0096;

v0096:
    v0080 = stack[-3];
    if (v0080 == nil) goto v0176;
    v0080 = stack[-3];
    v0112 = qcar(v0080);
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    v0080 = Lapply1(nil, v0112, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    stack[-1] = v0080;
    v0080 = stack[-1];
    if (v0080 == nil) goto v0145;
    v0080 = stack[-1];
    v0112 = qcar(v0080);
    v0080 = stack[0];
    v0080 = times2(v0112, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    stack[0] = v0080;
    v0080 = stack[-3];
    v0080 = qcdr(v0080);
    stack[-3] = v0080;
    goto v0096;

v0145:
    v0080 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0080); }

v0176:
    v0111 = stack[0];
    v0080 = stack[-2];
    v0112 = qcar(v0080);
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    popv(5);
    return list2star(v0111, v0112, v0080);
// error exit handlers
v0142:
    popv(5);
    return nil;
}



// Code for po!:statep

static LispObject CC_poTstatep(LispObject env,
                         LispObject v0012)
{
    LispObject nil = C_nil;
    LispObject v0146, v0147, v0086;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for po:statep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0086 = v0012;
// end of prologue
    v0146 = v0086;
    if (symbolp(v0146)) goto v0161;
    v0146 = qvalue(elt(env, 1)); // nil
    goto v0160;

v0160:
    if (!(v0146 == nil)) return onevalue(v0146);
    v0146 = v0086;
    if (!consp(v0146)) goto v0235;
    v0146 = v0086;
    v0146 = qcar(v0146);
    if (symbolp(v0146)) goto v0149;
    v0146 = qvalue(elt(env, 1)); // nil
    return onevalue(v0146);

v0149:
    v0146 = v0086;
    v0146 = qcar(v0146);
    if (!symbolp(v0146)) v0146 = nil;
    else { v0146 = qfastgets(v0146);
           if (v0146 != nil) { v0146 = elt(v0146, 18); // phystype
#ifdef RECORD_GET
             if (v0146 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0146 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0146 == SPID_NOPROP) v0146 = nil; }}
#endif
    v0147 = elt(env, 2); // state
    v0146 = (v0146 == v0147 ? lisp_true : nil);
    return onevalue(v0146);

v0235:
    v0146 = qvalue(elt(env, 1)); // nil
    return onevalue(v0146);

v0161:
    v0146 = v0086;
    if (!symbolp(v0146)) v0147 = nil;
    else { v0147 = qfastgets(v0146);
           if (v0147 != nil) { v0147 = elt(v0147, 18); // phystype
#ifdef RECORD_GET
             if (v0147 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0147 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0147 == SPID_NOPROP) v0147 = nil; }}
#endif
    v0146 = elt(env, 2); // state
    v0146 = (v0147 == v0146 ? lisp_true : nil);
    goto v0160;
}



setup_type const u26_setup[] =
{
    {"pasf_sisub",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sisub},
    {"ev_2a",                   CC_ev_2a,       too_many_1,    wrong_no_1},
    {"bvarrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_bvarrd},
    {"multdfconst",             too_few_2,      CC_multdfconst,wrong_no_2},
    {"evaluate-horner",         CC_evaluateKhorner,too_many_1, wrong_no_1},
    {"*xadd",                   too_few_2,      CC_Hxadd,      wrong_no_2},
    {"log_freevars_list",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_log_freevars_list},
    {"dv_ind2var",              CC_dv_ind2var,  too_many_1,    wrong_no_1},
    {"gen+can+bas",             CC_genLcanLbas, too_many_1,    wrong_no_1},
    {"pasf_smordtable",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smordtable},
    {"ofsf_entry2at",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at},
    {"sets",                    too_few_2,      CC_sets,       wrong_no_2},
    {"*a2k",                    CC_Ha2k,        too_many_1,    wrong_no_1},
    {"mkempspmat",              too_few_2,      CC_mkempspmat, wrong_no_2},
    {"suchp",                   CC_suchp,       too_many_1,    wrong_no_1},
    {"*pf2sq",                  CC_Hpf2sq,      too_many_1,    wrong_no_1},
    {"difference:",             too_few_2,      CC_differenceT,wrong_no_2},
    {"convprc2",                too_few_2,      CC_convprc2,   wrong_no_2},
    {"indordl2",                too_few_2,      CC_indordl2,   wrong_no_2},
    {"sign-of",                 CC_signKof,     too_many_1,    wrong_no_1},
    {"split_cov_cont_ids",      CC_split_cov_cont_ids,too_many_1,wrong_no_1},
    {"skp_ordp",                too_few_2,      CC_skp_ordp,   wrong_no_2},
    {"get*inverse",             too_few_2,      CC_getHinverse,wrong_no_2},
    {"mri_congp",               CC_mri_congp,   too_many_1,    wrong_no_1},
    {"pasf_floor",              too_few_2,      CC_pasf_floor, wrong_no_2},
    {"matrixom",                CC_matrixom,    too_many_1,    wrong_no_1},
    {"alg_plus",                too_few_2,      CC_alg_plus,   wrong_no_2},
    {"gftimes",                 too_few_2,      CC_gftimes,    wrong_no_2},
    {"incident",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident},
    {"list_is_all_free",        CC_list_is_all_free,too_many_1,wrong_no_1},
    {"mk+real+inner+product",   too_few_2,      CC_mkLrealLinnerLproduct,wrong_no_2},
    {"pasf_smordtable1",        too_few_2,      CC_pasf_smordtable1,wrong_no_2},
    {"ctx_idl",                 CC_ctx_idl,     too_many_1,    wrong_no_1},
    {"max-degree",              too_few_2,      CC_maxKdegree, wrong_no_2},
    {"applyfnrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyfnrd},
    {"close_forall",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_close_forall},
    {"delyzz",                  too_few_2,      CC_delyzz,     wrong_no_2},
    {"reval3",                  CC_reval3,      too_many_1,    wrong_no_1},
    {"s_actual_world1",         CC_s_actual_world1,too_many_1, wrong_no_1},
    {"assert_procstat-argl",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_procstatKargl},
    {"subs2chk",                CC_subs2chk,    too_many_1,    wrong_no_1},
    {"remchkf",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_remchkf},
    {"fs:onep:",                CC_fsTonepT,    too_many_1,    wrong_no_1},
    {"dfprintfn",               CC_dfprintfn,   too_many_1,    wrong_no_1},
    {"ad_splitname",            CC_ad_splitname,too_many_1,    wrong_no_1},
    {"comb",                    too_few_2,      CC_comb,       wrong_no_2},
    {"qqe_ofsf_varlat",         CC_qqe_ofsf_varlat,too_many_1, wrong_no_1},
    {"iv_cutcongs1",            too_few_2,      CC_iv_cutcongs1,wrong_no_2},
    {"aex_subrat1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrat1},
    {"bc_mkat",                 too_few_2,      CC_bc_mkat,    wrong_no_2},
    {"vectorml",                CC_vectorml,    too_many_1,    wrong_no_1},
    {"sc_subtrsq",              too_few_2,      CC_sc_subtrsq, wrong_no_2},
    {"toolongexpp",             CC_toolongexpp, too_many_1,    wrong_no_1},
    {"find_buble",              too_few_2,      CC_find_buble, wrong_no_2},
    {"assert_structstat",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_structstat},
    {"fs:prin",                 CC_fsTprin,     too_many_1,    wrong_no_1},
    {"mo_zero?",                CC_mo_zeroW,    too_many_1,    wrong_no_1},
    {"plusdf",                  too_few_2,      CC_plusdf,     wrong_no_2},
    {"tayexp-max2",             too_few_2,      CC_tayexpKmax2,wrong_no_2},
    {"give*position",           too_few_2,      CC_giveHposition,wrong_no_2},
    {"listrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_listrd},
    {"multerm",                 too_few_2,      CC_multerm,    wrong_no_2},
    {"matrixp",                 CC_matrixp,     too_many_1,    wrong_no_1},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,too_many_1,wrong_no_1},
    {"fieldp",                  CC_fieldp,      too_many_1,    wrong_no_1},
    {"noncomexpf",              CC_noncomexpf,  too_many_1,    wrong_no_1},
    {"sc_mkmatrix",             too_few_2,      CC_sc_mkmatrix,wrong_no_2},
    {"exdfprn",                 CC_exdfprn,     too_many_1,    wrong_no_1},
    {"evalb",                   CC_evalb,       too_many_1,    wrong_no_1},
    {"lispreadp",               CC_lispreadp,   too_many_1,    wrong_no_1},
    {"indexsymmetrize",         CC_indexsymmetrize,too_many_1, wrong_no_1},
    {"po:statep",               CC_poTstatep,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u26", (two_args *)"9418 364609 9919005", 0}
};

// end of generated code
