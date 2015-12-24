
// $destdir/u07.c        Machine generated C code

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



// Code for simp!*

static LispObject CC_simpH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0019, v0020;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp*");
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
    stack[-3] = qvalue(elt(env, 1)); // !*asymp!*
    qvalue(elt(env, 1)) = nil; // !*asymp!*
    v0020 = stack[-2];
    v0019 = elt(env, 2); // !*sq
    if (!consp(v0020)) goto v0021;
    v0020 = qcar(v0020);
    if (!(v0020 == v0019)) goto v0021;
    v0019 = stack[-2];
    v0019 = qcdr(v0019);
    v0019 = qcdr(v0019);
    v0019 = qcar(v0019);
    if (v0019 == nil) goto v0022;
    v0019 = qvalue(elt(env, 4)); // !*resimp
    v0019 = (v0019 == nil ? lisp_true : nil);
    goto v0023;

v0023:
    if (v0019 == nil) goto v0024;
    v0019 = stack[-2];
    v0019 = qcdr(v0019);
    v0019 = qcar(v0019);
    goto v0025;

v0025:
    qvalue(elt(env, 1)) = stack[-3]; // !*asymp!*
    { popv(5); return onevalue(v0019); }

v0024:
    v0020 = qvalue(elt(env, 5)); // mul!*
    v0019 = qvalue(elt(env, 6)); // !*sub2
    v0019 = cons(v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-1] = v0019;
    v0019 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 5)) = v0019; // mul!*
    v0019 = stack[-2];
    fn = elt(env, 14); // simp
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-2] = v0019;
    v0019 = qvalue(elt(env, 7)); // !*nospurp
    if (v0019 == nil) goto v0027;
    v0020 = qvalue(elt(env, 5)); // mul!*
    v0019 = elt(env, 8); // (isimpq)
    fn = elt(env, 15); // union
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    qvalue(elt(env, 5)) = v0019; // mul!*
    goto v0027;

v0027:
    v0019 = qvalue(elt(env, 5)); // mul!*
    stack[0] = v0019;
    goto v0028;

v0028:
    v0019 = stack[0];
    if (v0019 == nil) goto v0029;
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0020 = v0019;
    v0019 = stack[-2];
    v0019 = Lapply1(nil, v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-2] = v0019;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    goto v0028;

v0029:
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    qvalue(elt(env, 5)) = v0019; // mul!*
    v0019 = stack[-2];
    fn = elt(env, 16); // subs2
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-2] = v0019;
    v0019 = qvalue(elt(env, 9)); // !*combinelogs
    if (v0019 == nil) goto v0030;
    v0019 = stack[-2];
    fn = elt(env, 17); // clogsq!*
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-2] = v0019;
    goto v0030;

v0030:
    v0020 = qvalue(elt(env, 10)); // dmode!*
    v0019 = elt(env, 11); // !:gi!:
    if (v0020 == v0019) goto v0031;
    v0019 = qvalue(elt(env, 3)); // nil
    goto v0032;

v0032:
    if (v0019 == nil) goto v0033;
    v0019 = stack[-2];
    fn = elt(env, 18); // girationalize!:
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-2] = v0019;
    goto v0034;

v0034:
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    qvalue(elt(env, 6)) = v0019; // !*sub2
    v0019 = qvalue(elt(env, 1)); // !*asymp!*
    if (v0019 == nil) goto v0035;
    v0019 = qvalue(elt(env, 13)); // !*rationalize
    if (v0019 == nil) goto v0035;
    v0019 = stack[-2];
    fn = elt(env, 19); // gcdchk
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-2] = v0019;
    goto v0035;

v0035:
    v0019 = stack[-2];
    goto v0025;

v0033:
    v0019 = qvalue(elt(env, 13)); // !*rationalize
    if (v0019 == nil) goto v0036;
    v0019 = stack[-2];
    fn = elt(env, 20); // rationalizesq
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-2] = v0019;
    goto v0034;

v0036:
    v0019 = stack[-2];
    fn = elt(env, 21); // rationalizei
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-2] = v0019;
    goto v0034;

v0031:
    v0019 = qvalue(elt(env, 12)); // !*norationalgi
    v0019 = (v0019 == nil ? lisp_true : nil);
    goto v0032;

v0022:
    v0019 = qvalue(elt(env, 3)); // nil
    goto v0023;

v0021:
    v0019 = qvalue(elt(env, 3)); // nil
    goto v0023;
// error exit handlers
v0026:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; // !*asymp!*
    popv(5);
    return nil;
}



// Code for termordp

static LispObject CC_termordp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0039;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    v0039 = v0000;
// end of prologue
    fn = elt(env, 1); // wedgefax
    stack[-1] = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0039 = stack[0];
    fn = elt(env, 1); // wedgefax
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    {
        LispObject v0041 = stack[-1];
        popv(3);
        fn = elt(env, 2); // monordp
        return (*qfn2(fn))(qenv(fn), v0041, v0039);
    }
// error exit handlers
v0040:
    popv(3);
    return nil;
}



// Code for !:plus

static LispObject CC_Tplus(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0051, v0011, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :plus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0011 = v0037;
    v0012 = v0000;
// end of prologue
    v0051 = v0012;
    if (v0051 == nil) { popv(1); return onevalue(v0011); }
    v0051 = v0011;
    if (v0051 == nil) { popv(1); return onevalue(v0012); }
    v0051 = v0012;
    if (!consp(v0051)) goto v0041;
    v0051 = qvalue(elt(env, 1)); // nil
    goto v0040;

v0040:
    if (v0051 == nil) goto v0052;
    v0051 = v0012;
    v0051 = plus2(v0051, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[0];
    v0012 = v0051;
    v0011 = v0012;
    v0051 = (LispObject)1; // 0
    if (!(v0011 == v0051)) { popv(1); return onevalue(v0012); }
    v0051 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0051); }

v0052:
    v0051 = elt(env, 2); // plus
    {
        popv(1);
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0012, v0011, v0051);
    }

v0041:
    v0051 = v0011;
    v0051 = (consp(v0051) ? nil : lisp_true);
    goto v0040;
// error exit handlers
v0010:
    popv(1);
    return nil;
}



// Code for optype

static LispObject CC_optype(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0023;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for optype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0015 = v0000;
// end of prologue
    v0023 = elt(env, 1); // !*optype!*
    return get(v0015, v0023);
}



// Code for setcloc!*

static LispObject CC_setclocH(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0017, v0016, v0056;
    argcheck(nargs, 0, "setcloc*");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcloc*");
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
    v0017 = qvalue(elt(env, 1)); // ifl!*
    if (v0017 == nil) goto v0003;
    v0017 = qvalue(elt(env, 1)); // ifl!*
    v0056 = qcar(v0017);
    v0016 = (LispObject)17; // 1
    v0017 = qvalue(elt(env, 3)); // curline!*
    v0017 = list2star(v0056, v0016, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[0];
    goto v0002;

v0002:
    qvalue(elt(env, 4)) = v0017; // cloc!*
    { popv(1); return onevalue(v0017); }

v0003:
    v0017 = qvalue(elt(env, 2)); // nil
    goto v0002;
// error exit handlers
v0022:
    popv(1);
    return nil;
}



// Code for getrtype2

static LispObject CC_getrtype2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063, v0064, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrtype2");
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
    v0063 = v0064;
    v0063 = qcar(v0063);
    if (!symbolp(v0063)) v0063 = nil;
    else { v0063 = qfastgets(v0063);
           if (v0063 != nil) { v0063 = elt(v0063, 2); // rtype
#ifdef RECORD_GET
             if (v0063 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0063 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0063 == SPID_NOPROP) v0063 = nil; }}
#endif
    v0065 = v0063;
    if (v0063 == nil) goto v0053;
    v0063 = v0065;
    if (!symbolp(v0063)) v0063 = nil;
    else { v0063 = qfastgets(v0063);
           if (v0063 != nil) { v0063 = elt(v0063, 19); // rtypefn
#ifdef RECORD_GET
             if (v0063 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v0063 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v0063 == SPID_NOPROP) v0063 = nil; }}
#endif
    v0065 = v0063;
    if (v0063 == nil) goto v0053;
    v0063 = v0065;
    v0064 = qcdr(v0064);
        popv(1);
        return Lapply1(nil, v0063, v0064);

v0053:
    v0063 = v0064;
    v0063 = qcar(v0063);
    if (!symbolp(v0063)) v0063 = nil;
    else { v0063 = qfastgets(v0063);
           if (v0063 != nil) { v0063 = elt(v0063, 19); // rtypefn
#ifdef RECORD_GET
             if (v0063 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v0063 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v0063 == SPID_NOPROP) v0063 = nil; }}
#endif
    v0065 = v0063;
    if (v0063 == nil) goto v0066;
    v0063 = v0065;
    v0064 = qcdr(v0064);
        popv(1);
        return Lapply1(nil, v0063, v0064);

v0066:
    v0063 = v0064;
    v0065 = qcar(v0063);
    v0063 = elt(env, 1); // matmapfn
    v0063 = Lflagp(nil, v0065, v0063);
    env = stack[0];
    if (v0063 == nil) goto v0067;
    v0063 = v0064;
    v0063 = qcdr(v0063);
    if (v0063 == nil) goto v0052;
    v0063 = v0064;
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    fn = elt(env, 4); // getrtype
    v0064 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[0];
    v0063 = elt(env, 3); // matrix
    v0063 = (v0064 == v0063 ? lisp_true : nil);
    goto v0024;

v0024:
    if (v0063 == nil) goto v0009;
    v0063 = elt(env, 3); // matrix
    { popv(1); return onevalue(v0063); }

v0009:
    v0063 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0063); }

v0052:
    v0063 = qvalue(elt(env, 2)); // nil
    goto v0024;

v0067:
    v0063 = qvalue(elt(env, 2)); // nil
    goto v0024;
// error exit handlers
v0068:
    popv(1);
    return nil;
}



// Code for groeb!=testa

static LispObject CC_groebMtesta(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0069, v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=testa");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    v0069 = v0000;
// end of prologue
    v0070 = v0069;
    v0069 = (LispObject)49; // 3
    fn = elt(env, 1); // nth
    stack[-1] = (*qfn2(fn))(qenv(fn), v0070, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-2];
    v0070 = stack[0];
    v0069 = (LispObject)49; // 3
    fn = elt(env, 1); // nth
    v0069 = (*qfn2(fn))(qenv(fn), v0070, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-2];
    {
        LispObject v0072 = stack[-1];
        popv(3);
        fn = elt(env, 2); // mo_divides!?
        return (*qfn2(fn))(qenv(fn), v0072, v0069);
    }
// error exit handlers
v0071:
    popv(3);
    return nil;
}



// Code for gperm2

static LispObject CC_gperm2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0057, v0024, v0047, v0046;
    LispObject fn;
    LispObject v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gperm2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0037;
    v0057 = v0000;
// end of prologue

v0076:
    v0024 = v0057;
    if (v0024 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0024 = v0057;
    v0024 = qcdr(v0024);
    stack[-2] = v0024;
    v0024 = qcar(v0057);
    v0057 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // rev
    v0046 = (*qfn2(fn))(qenv(fn), v0024, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0047 = stack[-1];
    v0024 = qvalue(elt(env, 1)); // nil
    v0057 = stack[0];
    fn = elt(env, 3); // gperm1
    v0057 = (*qfnn(fn))(qenv(fn), 4, v0046, v0047, v0024, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[0] = v0057;
    v0057 = stack[-2];
    goto v0076;
// error exit handlers
v0014:
    popv(4);
    return nil;
}



// Code for rnplus!:

static LispObject CC_rnplusT(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0079, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    stack[-1] = v0000;
// end of prologue
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    v0060 = qcar(v0079);
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    stack[-2] = times2(v0060, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    v0060 = qcdr(v0079);
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0079 = times2(v0060, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    v0060 = qcdr(v0079);
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = times2(v0060, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    {
        LispObject v0080 = stack[-2];
        popv(4);
        fn = elt(env, 1); // mkrn
        return (*qfn2(fn))(qenv(fn), v0080, v0079);
    }
// error exit handlers
v0052:
    popv(4);
    return nil;
}



// Code for general!-modular!-minus

static LispObject CC_generalKmodularKminus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0022, v0069, v0070;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0070 = v0000;
// end of prologue
    v0069 = v0070;
    v0022 = (LispObject)1; // 0
    if (v0069 == v0022) return onevalue(v0070);
    v0022 = qvalue(elt(env, 1)); // current!-modulus
    v0069 = v0070;
    return difference2(v0022, v0069);
}



// Code for get_first_kernel

static LispObject CC_get_first_kernel(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0082, v0050, v0040;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_first_kernel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0082 = v0037;
    v0050 = v0000;
// end of prologue
    v0040 = v0050;
    v0050 = v0082;
    v0082 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // gfk
        return (*qfnn(fn))(qenv(fn), 3, v0040, v0050, v0082);
    }
}



// Code for convertmode

static LispObject CC_convertmode(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0071, v0072, v0048, v0049;
    LispObject fn;
    LispObject v0003, v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "convertmode");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convertmode");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0002,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0037,v0002,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0002;
    stack[-2] = v0037;
    v0071 = v0000;
// end of prologue
    v0048 = v0071;
    v0072 = stack[-2];
    v0071 = stack[0];
    fn = elt(env, 1); // form1
    v0049 = (*qfnn(fn))(qenv(fn), 3, v0048, v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-3];
    v0048 = stack[-2];
    v0072 = stack[-1];
    v0071 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); // convertmode1
        return (*qfnn(fn))(qenv(fn), 4, v0049, v0048, v0072, v0071);
    }
// error exit handlers
v0062:
    popv(4);
    return nil;
}



// Code for lto_insert

static LispObject CC_lto_insert(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0070, v0078, v0074, v0071;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_insert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0078 = v0037;
    v0074 = v0000;
// end of prologue
    v0071 = v0074;
    v0070 = v0078;
    v0070 = Lmember(nil, v0071, v0070);
    if (!(v0070 == nil)) return onevalue(v0078);
    v0070 = v0074;
    return cons(v0070, v0078);
}



// Code for sfto_davp

static LispObject CC_sfto_davp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0004, v0032;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_davp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    stack[-1] = v0000;
// end of prologue

v0086:
    v0004 = stack[-1];
    if (!consp(v0004)) goto v0039;
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    v0004 = (consp(v0004) ? nil : lisp_true);
    goto v0081;

v0081:
    if (v0004 == nil) goto v0070;
    v0004 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0004); }

v0070:
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    v0004 = qcar(v0004);
    v0032 = qcdr(v0004);
    v0004 = (LispObject)33; // 2
    v0004 = (LispObject)greaterp2(v0032, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    v0004 = v0004 ? lisp_true : nil;
    env = stack[-2];
    if (v0004 == nil) goto v0087;
    v0004 = stack[0];
    if (v0004 == nil) goto v0044;
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    v0004 = qcar(v0004);
    v0032 = qcar(v0004);
    v0004 = stack[0];
    if (equal(v0032, v0004)) goto v0044;
    v0004 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0004); }

v0044:
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    v0032 = qcdr(v0004);
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    v0004 = qcar(v0004);
    v0004 = qcar(v0004);
    v0004 = CC_sfto_davp(env, v0032, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-2];
    if (v0004 == nil) goto v0088;
    v0004 = stack[-1];
    v0004 = qcdr(v0004);
    v0032 = v0004;
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    v0004 = qcar(v0004);
    v0004 = qcar(v0004);
    stack[0] = v0004;
    v0004 = v0032;
    stack[-1] = v0004;
    goto v0086;

v0088:
    v0004 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0004); }

v0087:
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    v0032 = qcdr(v0004);
    v0004 = stack[0];
    v0004 = CC_sfto_davp(env, v0032, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-2];
    if (v0004 == nil) goto v0034;
    v0004 = stack[-1];
    v0004 = qcdr(v0004);
    stack[-1] = v0004;
    goto v0086;

v0034:
    v0004 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0004); }

v0039:
    v0004 = qvalue(elt(env, 1)); // t
    goto v0081;
// error exit handlers
v0030:
    popv(3);
    return nil;
}



// Code for qqe_id!-nyt!-branchb

static LispObject CC_qqe_idKnytKbranchb(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchb");
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
    v0070 = stack[0];
    if (!consp(v0070)) goto v0001;
    v0070 = stack[0];
    v0070 = qcar(v0070);
    fn = elt(env, 1); // qqe_qopaddp
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    if (!(v0070 == nil)) goto v0041;
    v0070 = stack[0];
    v0070 = qcar(v0070);
    fn = elt(env, 2); // qqe_qoptailp
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    goto v0041;

v0041:
    v0070 = (v0070 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0070); }

v0001:
    v0070 = stack[0];
    fn = elt(env, 3); // qqe_btidp
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    if (!(v0070 == nil)) { popv(2); return onevalue(v0070); }
    v0070 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // qqe_nytidp
        return (*qfn1(fn))(qenv(fn), v0070);
    }
// error exit handlers
v0074:
    popv(2);
    return nil;
}



// Code for rationalizei

static LispObject CC_rationalizei(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0093, v0094;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rationalizei");
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
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-2] = v0093;
    v0094 = v0093;
    v0093 = v0094;
    if (!consp(v0093)) goto v0040;
    v0093 = v0094;
    v0093 = qcar(v0093);
    v0093 = (consp(v0093) ? nil : lisp_true);
    goto v0050;

v0050:
    if (!(v0093 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0094 = elt(env, 2); // i
    v0093 = stack[-2];
    v0093 = Lsmemq(nil, v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    if (v0093 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0094 = elt(env, 2); // i
    v0093 = qvalue(elt(env, 3)); // kord!*
    v0093 = cons(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 3)); // kord!*
    qvalue(elt(env, 3)) = v0093; // kord!*
    v0093 = stack[-1];
    fn = elt(env, 6); // reordsq
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-3];
    stack[-2] = v0093;
    qvalue(elt(env, 3)) = stack[0]; // kord!*
    v0093 = stack[-2];
    v0093 = qcdr(v0093);
    stack[0] = v0093;
    v0093 = qcar(v0093);
    v0094 = qcar(v0093);
    v0093 = elt(env, 4); // (i . 1)
    if (equal(v0094, v0093)) goto v0060;
    v0093 = qvalue(elt(env, 5)); // nil
    goto v0079;

v0079:
    if (v0093 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0094 = elt(env, 2); // i
    v0093 = (LispObject)17; // 1
    fn = elt(env, 7); // to
    v0094 = (*qfn2(fn))(qenv(fn), v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0093 = (LispObject)17; // 1
    v0093 = cons(v0094, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    stack[-1] = ncons(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0093 = stack[-2];
    v0093 = qcar(v0093);
    fn = elt(env, 8); // reorder
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    fn = elt(env, 9); // multf
    v0093 = (*qfn2(fn))(qenv(fn), stack[-1], v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    fn = elt(env, 10); // negf
    stack[-1] = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0093 = stack[0];
    v0093 = qcar(v0093);
    v0093 = qcdr(v0093);
    fn = elt(env, 8); // reorder
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    {
        LispObject v0096 = stack[-1];
        popv(4);
        return cons(v0096, v0093);
    }

v0060:
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0093 = (v0093 == nil ? lisp_true : nil);
    goto v0079;

v0040:
    v0093 = qvalue(elt(env, 1)); // t
    goto v0050;
// error exit handlers
v0095:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[0]; // kord!*
    popv(4);
    return nil;
v0006:
    popv(4);
    return nil;
}



// Code for mintype

static LispObject CC_mintype(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0081, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mintype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0081 = v0000;
// end of prologue
    v0039 = v0081;
    if (!consp(v0039)) return onevalue(v0081);
    v0081 = qcar(v0081);
    return onevalue(v0081);
}



// Code for nextarg

static LispObject CC_nextarg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nextarg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0082 = v0000;
// end of prologue
    v0039 = qvalue(elt(env, 1)); // symm
    if (v0039 == nil) goto v0038;
    v0039 = v0082;
    {
        fn = elt(env, 2); // s!-nextarg
        return (*qfn1(fn))(qenv(fn), v0039);
    }

v0038:
    v0039 = v0082;
    {
        fn = elt(env, 3); // o!-nextarg
        return (*qfn1(fn))(qenv(fn), v0039);
    }
}



// Code for bcsum

static LispObject CC_bcsum(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0024, v0047, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcsum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    stack[-1] = v0000;
// end of prologue
    v0024 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0024 == nil) goto v0056;
    v0047 = stack[-1];
    v0024 = stack[0];
    v0024 = plus2(v0047, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); // bcfi
        return (*qfn1(fn))(qenv(fn), v0024);
    }

v0056:
    v0046 = stack[-1];
    v0047 = stack[0];
    v0024 = elt(env, 2); // plus2
    fn = elt(env, 4); // bcint2op
    v0024 = (*qfnn(fn))(qenv(fn), 3, v0046, v0047, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    if (!(v0024 == nil)) { popv(3); return onevalue(v0024); }
    v0047 = stack[-1];
    v0024 = stack[0];
    fn = elt(env, 5); // addsq
    v0024 = (*qfn2(fn))(qenv(fn), v0047, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); // bccheckz
        return (*qfn1(fn))(qenv(fn), v0024);
    }
// error exit handlers
v0013:
    popv(3);
    return nil;
}



// Code for layout!-formula

static LispObject CC_layoutKformula(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0102, v0103;
    LispObject fn;
    LispObject v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "layout-formula");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for layout-formula");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0002;
    stack[-7] = v0037;
    stack[-8] = v0000;
// end of prologue
    stack[-9] = qvalue(elt(env, 1)); // ycoord!*
    qvalue(elt(env, 1)) = nil; // ycoord!*
    stack[-5] = qvalue(elt(env, 2)); // ymin!*
    qvalue(elt(env, 2)) = nil; // ymin!*
    stack[-4] = qvalue(elt(env, 3)); // ymax!*
    qvalue(elt(env, 3)) = nil; // ymax!*
    stack[-3] = qvalue(elt(env, 4)); // posn!*
    qvalue(elt(env, 4)) = nil; // posn!*
    stack[-2] = qvalue(elt(env, 5)); // pline!*
    qvalue(elt(env, 5)) = nil; // pline!*
    stack[-1] = qvalue(elt(env, 6)); // testing!-width!*
    qvalue(elt(env, 6)) = nil; // testing!-width!*
    stack[0] = qvalue(elt(env, 7)); // overflowed!*
    qvalue(elt(env, 7)) = nil; // overflowed!*
    v0102 = qvalue(elt(env, 8)); // nil
    qvalue(elt(env, 7)) = v0102; // overflowed!*
    qvalue(elt(env, 5)) = v0102; // pline!*
    v0102 = (LispObject)1; // 0
    qvalue(elt(env, 3)) = v0102; // ymax!*
    qvalue(elt(env, 2)) = v0102; // ymin!*
    qvalue(elt(env, 1)) = v0102; // ycoord!*
    v0102 = qvalue(elt(env, 9)); // orig!*
    qvalue(elt(env, 4)) = v0102; // posn!*
    v0102 = qvalue(elt(env, 10)); // t
    qvalue(elt(env, 6)) = v0102; // testing!-width!*
    v0102 = stack[-6];
    if (v0102 == nil) goto v0097;
    v0103 = stack[-6];
    v0102 = elt(env, 11); // inbrackets
    if (v0103 == v0102) goto v0022;
    v0102 = stack[-6];
    fn = elt(env, 14); // oprin
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-10];
    goto v0097;

v0097:
    v0103 = stack[-8];
    v0102 = stack[-7];
    fn = elt(env, 15); // maprint
    v0102 = (*qfn2(fn))(qenv(fn), v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-10];
    v0103 = stack[-6];
    v0102 = elt(env, 11); // inbrackets
    if (!(v0103 == v0102)) goto v0014;
    v0102 = elt(env, 13); // ")"
    fn = elt(env, 16); // prin2!*
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-10];
    goto v0014;

v0014:
    v0102 = qvalue(elt(env, 7)); // overflowed!*
    if (v0102 == nil) goto v0104;
    v0102 = qvalue(elt(env, 8)); // nil
    goto v0081;

v0081:
    qvalue(elt(env, 7)) = stack[0]; // overflowed!*
    qvalue(elt(env, 6)) = stack[-1]; // testing!-width!*
    qvalue(elt(env, 5)) = stack[-2]; // pline!*
    qvalue(elt(env, 4)) = stack[-3]; // posn!*
    qvalue(elt(env, 3)) = stack[-4]; // ymax!*
    qvalue(elt(env, 2)) = stack[-5]; // ymin!*
    qvalue(elt(env, 1)) = stack[-9]; // ycoord!*
    { popv(11); return onevalue(v0102); }

v0104:
    stack[-7] = qvalue(elt(env, 5)); // pline!*
    v0103 = qvalue(elt(env, 4)); // posn!*
    v0102 = qvalue(elt(env, 9)); // orig!*
    stack[-6] = difference2(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-10];
    v0103 = qvalue(elt(env, 2)); // ymin!*
    v0102 = qvalue(elt(env, 3)); // ymax!*
    v0102 = cons(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-10];
    v0102 = acons(stack[-7], stack[-6], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-10];
    goto v0081;

v0022:
    v0102 = elt(env, 12); // "("
    fn = elt(env, 16); // prin2!*
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-10];
    goto v0097;
// error exit handlers
v0032:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; // overflowed!*
    qvalue(elt(env, 6)) = stack[-1]; // testing!-width!*
    qvalue(elt(env, 5)) = stack[-2]; // pline!*
    qvalue(elt(env, 4)) = stack[-3]; // posn!*
    qvalue(elt(env, 3)) = stack[-4]; // ymax!*
    qvalue(elt(env, 2)) = stack[-5]; // ymin!*
    qvalue(elt(env, 1)) = stack[-9]; // ycoord!*
    popv(11);
    return nil;
}



// Code for abs!:

static LispObject CC_absT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0062;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for abs:");
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
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0062 = qcar(v0021);
    v0021 = (LispObject)1; // 0
    v0021 = (LispObject)greaterp2(v0062, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    v0021 = v0021 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0021 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); // !:rd!:
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = qcar(v0021);
    v0062 = negate(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = qcdr(v0021);
    {
        LispObject v0097 = stack[-1];
        popv(3);
        return list2star(v0097, v0062, v0021);
    }
// error exit handlers
v0073:
    popv(3);
    return nil;
}



// Code for list2widestring

static LispObject CC_list2widestring(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0190, v0191, v0192;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list2widestring");
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
    v0190 = (LispObject)1; // 0
    stack[-6] = v0190;
    v0190 = stack[-8];
    stack[0] = v0190;
    goto v0053;

v0053:
    v0190 = stack[0];
    if (v0190 == nil) goto v0038;
    v0190 = stack[0];
    v0190 = qcar(v0190);
    stack[-9] = v0190;
    v0190 = stack[0];
    v0190 = qcdr(v0190);
    stack[0] = v0190;
    v0190 = stack[-9];
    if (symbolp(v0190)) goto v0022;
    v0190 = stack[-9];
    v0190 = Lstringp(nil, v0190);
    env = stack[-10];
    if (v0190 == nil) goto v0049;
    v0191 = stack[-9];
    v0190 = elt(env, 1); // ""
    if (equal(v0191, v0190)) goto v0049;
    v0190 = stack[-9];
    fn = elt(env, 5); // widestring2list
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = qcar(v0190);
    stack[-9] = v0190;
    goto v0194;

v0194:
    v0191 = stack[-9];
    v0190 = (LispObject)1; // 0
    v0190 = (LispObject)lessp2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-10];
    if (v0190 == nil) goto v0090;
    v0191 = (LispObject)17; // 1
    v0190 = elt(env, 3); // "Negative integer in list2widestring"
    fn = elt(env, 6); // error
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    goto v0053;

v0090:
    v0191 = stack[-9];
    v0190 = (LispObject)2049; // 128
    v0190 = (LispObject)lessp2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-10];
    if (v0190 == nil) goto v0195;
    v0190 = stack[-6];
    v0190 = add1(v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-6] = v0190;
    goto v0053;

v0195:
    v0191 = stack[-9];
    v0190 = (LispObject)32769; // 2048
    v0190 = (LispObject)lessp2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-10];
    if (v0190 == nil) goto v0031;
    v0191 = stack[-6];
    v0190 = (LispObject)33; // 2
    v0190 = plus2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-6] = v0190;
    goto v0053;

v0031:
    v0191 = stack[-9];
    v0190 = (LispObject)1048577; // 65536
    v0190 = (LispObject)lessp2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-10];
    if (v0190 == nil) goto v0196;
    v0191 = stack[-6];
    v0190 = (LispObject)49; // 3
    v0190 = plus2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-6] = v0190;
    goto v0053;

v0196:
    v0191 = stack[-9];
    v0190 = (LispObject)17825793; // 1114112
    v0190 = (LispObject)lessp2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-10];
    if (v0190 == nil) goto v0197;
    v0191 = stack[-6];
    v0190 = (LispObject)65; // 4
    v0190 = plus2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-6] = v0190;
    goto v0053;

v0197:
    v0191 = (LispObject)17; // 1
    v0190 = elt(env, 4); // "Integer too large in list2widestring"
    fn = elt(env, 6); // error
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    goto v0053;

v0049:
    v0190 = stack[-9];
    v0190 = integerp(v0190);
    if (!(v0190 == nil)) goto v0194;
    v0190 = elt(env, 2); // "Invalid item in arg to list2widestring"
    fn = elt(env, 7); // rederr
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    goto v0194;

v0022:
    v0190 = stack[-9];
    v0190 = Lsymbol_name(nil, v0190);
    env = stack[-10];
    fn = elt(env, 5); // widestring2list
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = qcar(v0190);
    stack[-9] = v0190;
    goto v0194;

v0038:
    v0190 = stack[-6];
    fn = elt(env, 8); // allocate!-string
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-7] = v0190;
    v0190 = (LispObject)1; // 0
    stack[-6] = v0190;
    goto v0015;

v0015:
    v0190 = stack[-8];
    if (v0190 == nil) { LispObject res = stack[-7]; popv(11); return onevalue(res); }
    v0190 = stack[-8];
    v0190 = qcar(v0190);
    stack[-9] = v0190;
    v0190 = stack[-9];
    if (symbolp(v0190)) goto v0198;
    v0190 = stack[-9];
    v0190 = Lstringp(nil, v0190);
    env = stack[-10];
    if (v0190 == nil) goto v0199;
    v0191 = stack[-9];
    v0190 = elt(env, 1); // ""
    if (equal(v0191, v0190)) goto v0199;
    v0190 = stack[-9];
    fn = elt(env, 5); // widestring2list
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = qcar(v0190);
    stack[-9] = v0190;
    goto v0199;

v0199:
    v0190 = stack[-8];
    v0190 = qcdr(v0190);
    stack[-8] = v0190;
    v0191 = stack[-9];
    v0190 = (LispObject)2049; // 128
    v0190 = (LispObject)lessp2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-10];
    if (v0190 == nil) goto v0200;
    v0192 = stack[-7];
    v0191 = stack[-6];
    v0190 = stack[-9];
    fn = elt(env, 9); // string!-store
    v0190 = (*qfnn(fn))(qenv(fn), 3, v0192, v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = stack[-6];
    v0190 = add1(v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-6] = v0190;
    goto v0015;

v0200:
    v0191 = stack[-9];
    v0190 = (LispObject)32769; // 2048
    v0190 = (LispObject)lessp2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-10];
    if (v0190 == nil) goto v0201;
    stack[-3] = stack[-7];
    stack[-2] = stack[-6];
    stack[0] = (LispObject)3073; // 192
    v0191 = stack[-9];
    v0190 = (LispObject)-95; // -6
    fn = elt(env, 10); // lshift
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-1] = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[0] = (LispObject)2049; // 128
    v0191 = stack[-9];
    v0190 = (LispObject)1009; // 63
    fn = elt(env, 11); // land
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    fn = elt(env, 12); // string!-store2
    v0190 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[-2], stack[-1], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0191 = stack[-6];
    v0190 = (LispObject)33; // 2
    v0190 = plus2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-6] = v0190;
    goto v0015;

v0201:
    v0191 = stack[-9];
    v0190 = (LispObject)1048577; // 65536
    v0190 = (LispObject)lessp2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-10];
    if (v0190 == nil) goto v0202;
    stack[-4] = stack[-7];
    stack[-3] = stack[-6];
    stack[0] = (LispObject)3585; // 224
    v0191 = stack[-9];
    v0190 = (LispObject)-191; // -12
    fn = elt(env, 10); // lshift
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-2] = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[0] = (LispObject)2049; // 128
    v0191 = stack[-9];
    v0190 = (LispObject)-95; // -6
    fn = elt(env, 10); // lshift
    v0191 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = (LispObject)1009; // 63
    fn = elt(env, 11); // land
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-1] = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[0] = (LispObject)2049; // 128
    v0191 = stack[-9];
    v0190 = (LispObject)1009; // 63
    fn = elt(env, 11); // land
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    fn = elt(env, 13); // string!-store3
    v0190 = (*qfnn(fn))(qenv(fn), 5, stack[-4], stack[-3], stack[-2], stack[-1], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0191 = stack[-6];
    v0190 = (LispObject)49; // 3
    v0190 = plus2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-6] = v0190;
    goto v0015;

v0202:
    stack[-5] = stack[-7];
    stack[-4] = stack[-6];
    stack[0] = (LispObject)3841; // 240
    v0191 = stack[-9];
    v0190 = (LispObject)-287; // -18
    fn = elt(env, 10); // lshift
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-3] = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[0] = (LispObject)2049; // 128
    v0191 = stack[-9];
    v0190 = (LispObject)-191; // -12
    fn = elt(env, 10); // lshift
    v0191 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = (LispObject)1009; // 63
    fn = elt(env, 11); // land
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-2] = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[0] = (LispObject)2049; // 128
    v0191 = stack[-9];
    v0190 = (LispObject)-95; // -6
    fn = elt(env, 10); // lshift
    v0191 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = (LispObject)1009; // 63
    fn = elt(env, 11); // land
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-1] = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[0] = (LispObject)2049; // 128
    v0191 = stack[-9];
    v0190 = (LispObject)1009; // 63
    fn = elt(env, 11); // land
    v0190 = (*qfn2(fn))(qenv(fn), v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = plus2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    fn = elt(env, 14); // string!-store4
    v0190 = (*qfnn(fn))(qenv(fn), 6, stack[-5], stack[-4], stack[-3], stack[-2], stack[-1], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0191 = stack[-6];
    v0190 = (LispObject)65; // 4
    v0190 = plus2(v0191, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    stack[-6] = v0190;
    goto v0015;

v0198:
    v0190 = stack[-9];
    v0190 = Lsymbol_name(nil, v0190);
    env = stack[-10];
    fn = elt(env, 5); // widestring2list
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-10];
    v0190 = qcar(v0190);
    stack[-9] = v0190;
    goto v0199;
// error exit handlers
v0193:
    popv(11);
    return nil;
}



// Code for mv!-pow!-mv!-term!-!+

static LispObject CC_mvKpowKmvKtermKL(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0018, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0037;
    v0018 = v0000;
// end of prologue
    v0017 = v0018;
    v0018 = stack[0];
    v0018 = qcar(v0018);
    fn = elt(env, 1); // mv!-pow!-!+
    v0017 = (*qfn2(fn))(qenv(fn), v0017, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    popv(1);
    return cons(v0017, v0018);
// error exit handlers
v0056:
    popv(1);
    return nil;
}



// Code for yyreadch

static LispObject CC_yyreadch(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0079, v0060, v0027;
    argcheck(nargs, 0, "yyreadch");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for yyreadch");
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
    v0079 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[0];
    qvalue(elt(env, 1)) = v0079; // lex_char
    v0060 = qvalue(elt(env, 1)); // lex_char
    v0079 = qvalue(elt(env, 2)); // !$eol!$
    if (!(equal(v0060, v0079))) goto v0054;
    v0079 = qvalue(elt(env, 3)); // which_line
    v0079 = add1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[0];
    qvalue(elt(env, 3)) = v0079; // which_line
    goto v0054;

v0054:
    v0060 = qvalue(elt(env, 1)); // lex_char
    v0079 = qvalue(elt(env, 4)); // !$eof!$
    if (equal(v0060, v0079)) goto v0040;
    v0079 = qvalue(elt(env, 5)); // last64p
    v0079 = add1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[0];
    qvalue(elt(env, 5)) = v0079; // last64p
    v0060 = qvalue(elt(env, 5)); // last64p
    v0079 = (LispObject)1025; // 64
    if (!(v0060 == v0079)) goto v0097;
    v0079 = (LispObject)1; // 0
    qvalue(elt(env, 5)) = v0079; // last64p
    goto v0097;

v0097:
    v0027 = qvalue(elt(env, 6)); // last64
    v0060 = qvalue(elt(env, 5)); // last64p
    v0079 = qvalue(elt(env, 1)); // lex_char
    *(LispObject *)((char *)v0027 + (CELL-TAG_VECTOR) + ((int32_t)v0060/(16/CELL))) = v0079;
    goto v0040;

v0040:
    v0079 = qvalue(elt(env, 1)); // lex_char
    { popv(1); return onevalue(v0079); }
// error exit handlers
v0058:
    popv(1);
    return nil;
}



// Code for mcharg

static LispObject CC_mcharg(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0207, v0208, v0197;
    LispObject fn;
    LispObject v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mcharg");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mcharg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0002;
    stack[0] = v0037;
    v0197 = v0000;
// end of prologue
    v0208 = elt(env, 1); // minus
    v0207 = stack[0];
    v0207 = Latsoc(nil, v0208, v0207);
    if (v0207 == nil) goto v0076;
    v0208 = v0197;
    v0207 = stack[0];
    fn = elt(env, 4); // reform!-minus
    v0197 = (*qfn2(fn))(qenv(fn), v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0208 = stack[0];
    v0207 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); // mcharg1
        return (*qfnn(fn))(qenv(fn), 3, v0197, v0208, v0207);
    }

v0076:
    v0207 = stack[0];
    if (v0207 == nil) goto v0209;
    v0207 = stack[0];
    v0208 = qcar(v0207);
    v0207 = elt(env, 2); // slash
    if (!consp(v0208)) goto v0209;
    v0208 = qcar(v0208);
    if (!(v0208 == v0207)) goto v0209;
    v0208 = v0197;
    v0207 = stack[0];
    fn = elt(env, 6); // reform!-minus2
    v0207 = (*qfn2(fn))(qenv(fn), v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[-4] = v0207;
    goto v0027;

v0027:
    v0207 = stack[-4];
    if (v0207 == nil) goto v0010;
    v0207 = stack[-4];
    v0207 = qcar(v0207);
    v0208 = v0207;
    v0197 = qcar(v0208);
    v0208 = qcdr(v0207);
    v0207 = stack[-3];
    fn = elt(env, 5); // mcharg1
    v0207 = (*qfnn(fn))(qenv(fn), 3, v0197, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[-2] = v0207;
    v0207 = stack[-2];
    fn = elt(env, 7); // lastpair
    v0207 = (*qfn1(fn))(qenv(fn), v0207);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[-1] = v0207;
    v0207 = stack[-4];
    v0207 = qcdr(v0207);
    stack[-4] = v0207;
    v0207 = stack[-1];
    if (!consp(v0207)) goto v0027;
    else goto v0058;

v0058:
    v0207 = stack[-4];
    if (v0207 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0207 = stack[-4];
    v0207 = qcar(v0207);
    v0208 = v0207;
    v0197 = qcar(v0208);
    v0208 = qcdr(v0207);
    v0207 = stack[-3];
    fn = elt(env, 5); // mcharg1
    v0207 = (*qfnn(fn))(qenv(fn), 3, v0197, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0207 = Lrplacd(nil, stack[0], v0207);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0207 = stack[-1];
    fn = elt(env, 7); // lastpair
    v0207 = (*qfn1(fn))(qenv(fn), v0207);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[-1] = v0207;
    v0207 = stack[-4];
    v0207 = qcdr(v0207);
    stack[-4] = v0207;
    goto v0058;

v0010:
    v0207 = qvalue(elt(env, 3)); // nil
    { popv(6); return onevalue(v0207); }

v0209:
    v0208 = stack[0];
    v0207 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); // mcharg1
        return (*qfnn(fn))(qenv(fn), 3, v0197, v0208, v0207);
    }
// error exit handlers
v0180:
    popv(6);
    return nil;
}



// Code for ibalp_commonlenisone

static LispObject CC_ibalp_commonlenisone(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_commonlenisone");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    stack[-1] = v0000;
// end of prologue
    v0070 = stack[-1];
    if (v0070 == nil) goto v0053;
    v0070 = qvalue(elt(env, 1)); // nil
    goto v0076;

v0076:
    if (!(v0070 == nil)) { popv(3); return onevalue(v0070); }
    v0070 = stack[0];
    if (v0070 == nil) goto v0055;
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0070); }

v0055:
    v0070 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); // ibalp_lenisone
        return (*qfn1(fn))(qenv(fn), v0070);
    }

v0053:
    v0070 = stack[0];
    fn = elt(env, 2); // ibalp_lenisone
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-2];
    goto v0076;
// error exit handlers
v0071:
    popv(3);
    return nil;
}



// Code for omobjs

static LispObject CC_omobjs(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0047, v0046;
    LispObject fn;
    argcheck(nargs, 0, "omobjs");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omobjs");
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
    v0046 = qvalue(elt(env, 1)); // char
    v0047 = elt(env, 2); // (!/ o m a)
    if (equal(v0046, v0047)) goto v0086;
    fn = elt(env, 4); // omobj
    v0047 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    stack[0] = v0047;
    fn = elt(env, 5); // lex
    v0047 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0047 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    v0046 = stack[0];
    if (v0046 == nil) goto v0069;
    v0046 = stack[0];
    popv(2);
    return cons(v0046, v0047);

v0069:
    v0046 = stack[0];
        popv(2);
        return Lappend(nil, v0046, v0047);

v0086:
    v0047 = nil;
    { popv(2); return onevalue(v0047); }
// error exit handlers
v0066:
    popv(2);
    return nil;
}



// Code for letmtr3

static LispObject CC_letmtr3(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0132, v0110, v0246, v0247;
    LispObject fn;
    LispObject v0003, v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "letmtr3");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for letmtr3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0002,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0037,v0002,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-2] = v0003;
    stack[-3] = v0002;
    stack[-4] = v0037;
    stack[-5] = v0000;
// end of prologue
    stack[-6] = nil;
    v0132 = stack[-5];
    v0132 = qcdr(v0132);
    v0132 = qcdr(v0132);
    if (v0132 == nil) goto v0074;
    v0110 = stack[-3];
    v0132 = elt(env, 1); // sparsemat
    if (!consp(v0110)) goto v0248;
    v0110 = qcar(v0110);
    if (!(v0110 == v0132)) goto v0248;
    v0132 = stack[-5];
    v0132 = qcdr(v0132);
    fn = elt(env, 9); // revlis
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    stack[-6] = v0132;
    fn = elt(env, 10); // numlis
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    if (v0132 == nil) goto v0197;
    v0132 = stack[-6];
    v0110 = Llength(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    v0132 = (LispObject)33; // 2
    v0132 = Lneq(nil, v0110, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    goto v0208;

v0208:
    if (v0132 == nil) goto v0250;
    v0110 = stack[-5];
    v0132 = elt(env, 6); // hold
    {
        popv(8);
        fn = elt(env, 11); // errpri2
        return (*qfn2(fn))(qenv(fn), v0110, v0132);
    }

v0250:
    v0132 = stack[-3];
    v0132 = qcdr(v0132);
    v0110 = qcar(v0132);
    v0132 = stack[-6];
    v0132 = qcar(v0132);
    v0132 = *(LispObject *)((char *)v0110 + (CELL-TAG_VECTOR) + ((int32_t)v0132/(16/CELL)));
    v0247 = v0132;
    v0132 = v0247;
    if (v0132 == nil) goto v0251;
    v0132 = stack[-6];
    v0132 = qcdr(v0132);
    v0110 = qcar(v0132);
    v0132 = v0247;
    v0132 = Latsoc(nil, v0110, v0132);
    v0246 = v0132;
    v0132 = v0246;
    if (v0132 == nil) goto v0156;
    v0110 = stack[-4];
    v0132 = (LispObject)1; // 0
    if (v0110 == v0132) goto v0252;
    v0132 = qvalue(elt(env, 7)); // nil
    goto v0253;

v0253:
    if (v0132 == nil) goto v0254;
    v0132 = v0247;
    v0132 = qcdr(v0132);
    v0132 = qcdr(v0132);
    if (v0132 == nil) goto v0255;
    stack[0] = v0247;
    v0132 = v0246;
    v0110 = v0247;
    v0132 = Ldelete(nil, v0132, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    v0132 = qcdr(v0132);
    v0132 = Lrplacd(nil, stack[0], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    goto v0041;

v0041:
    v0132 = nil;
    { popv(8); return onevalue(v0132); }

v0255:
    v0132 = stack[-3];
    v0132 = qcdr(v0132);
    v0110 = qcar(v0132);
    v0132 = stack[-6];
    v0132 = qcar(v0132);
    v0246 = qvalue(elt(env, 7)); // nil
    *(LispObject *)((char *)v0110 + (CELL-TAG_VECTOR) + ((int32_t)v0132/(16/CELL))) = v0246;
    goto v0041;

v0254:
    v0110 = v0246;
    v0132 = stack[-4];
    v0132 = Lrplacd(nil, v0110, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    goto v0041;

v0252:
    v0110 = stack[-2];
    v0132 = elt(env, 8); // cx
    v0132 = (v0110 == v0132 ? lisp_true : nil);
    v0132 = (v0132 == nil ? lisp_true : nil);
    goto v0253;

v0156:
    v0110 = stack[-4];
    v0132 = (LispObject)1; // 0
    if (v0110 == v0132) goto v0256;
    v0132 = qvalue(elt(env, 7)); // nil
    goto v0257;

v0257:
    if (!(v0132 == nil)) goto v0041;
    v0132 = stack[-6];
    v0132 = qcdr(v0132);
    v0110 = qcar(v0132);
    v0246 = v0247;
    v0132 = stack[-4];
    fn = elt(env, 12); // sortcolelem
    v0132 = (*qfnn(fn))(qenv(fn), 3, v0110, v0246, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    goto v0041;

v0256:
    v0110 = stack[-2];
    v0132 = elt(env, 8); // cx
    v0132 = (v0110 == v0132 ? lisp_true : nil);
    v0132 = (v0132 == nil ? lisp_true : nil);
    goto v0257;

v0251:
    v0110 = stack[-4];
    v0132 = (LispObject)1; // 0
    if (v0110 == v0132) goto v0258;
    v0132 = qvalue(elt(env, 7)); // nil
    goto v0259;

v0259:
    if (!(v0132 == nil)) goto v0041;
    v0132 = stack[-3];
    v0132 = qcdr(v0132);
    stack[-2] = qcar(v0132);
    v0132 = stack[-6];
    stack[-1] = qcar(v0132);
    v0132 = qvalue(elt(env, 7)); // nil
    stack[0] = ncons(v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    v0132 = stack[-6];
    v0132 = qcdr(v0132);
    v0110 = qcar(v0132);
    v0132 = stack[-4];
    v0132 = cons(v0110, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    v0132 = list2(stack[0], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0132;
    goto v0041;

v0258:
    v0110 = stack[-2];
    v0132 = elt(env, 8); // cx
    v0132 = (v0110 == v0132 ? lisp_true : nil);
    v0132 = (v0132 == nil ? lisp_true : nil);
    goto v0259;

v0197:
    v0132 = qvalue(elt(env, 5)); // t
    goto v0208;

v0248:
    stack[-1] = elt(env, 2); // matrix
    stack[0] = (LispObject)161; // 10
    v0246 = elt(env, 3); // "Matrix"
    v0132 = stack[-5];
    v0110 = qcar(v0132);
    v0132 = elt(env, 4); // "not set"
    v0132 = list3(v0246, v0110, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    fn = elt(env, 13); // rerror
    v0132 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    goto v0250;

v0074:
    v0110 = stack[-3];
    v0132 = elt(env, 1); // sparsemat
    if (!consp(v0110)) goto v0062;
    v0110 = qcar(v0110);
    if (!(v0110 == v0132)) goto v0062;
    v0132 = stack[-5];
    v0132 = qcdr(v0132);
    fn = elt(env, 9); // revlis
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    stack[-6] = v0132;
    fn = elt(env, 10); // numlis
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    if (v0132 == nil) goto v0044;
    v0132 = stack[-6];
    v0110 = Llength(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    v0132 = (LispObject)17; // 1
    v0132 = Lneq(nil, v0110, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    goto v0043;

v0043:
    if (v0132 == nil) goto v0260;
    v0110 = stack[-5];
    v0132 = elt(env, 6); // hold
    {
        popv(8);
        fn = elt(env, 11); // errpri2
        return (*qfn2(fn))(qenv(fn), v0110, v0132);
    }

v0260:
    v0132 = stack[-3];
    v0132 = qcdr(v0132);
    v0246 = qcar(v0132);
    v0132 = stack[-5];
    v0132 = qcdr(v0132);
    v0110 = qcar(v0132);
    v0132 = stack[-4];
    *(LispObject *)((char *)v0246 + (CELL-TAG_VECTOR) + ((int32_t)v0110/(16/CELL))) = v0132;
    goto v0041;

v0044:
    v0132 = qvalue(elt(env, 5)); // t
    goto v0043;

v0062:
    stack[-1] = elt(env, 2); // matrix
    stack[0] = (LispObject)161; // 10
    v0246 = elt(env, 3); // "Matrix"
    v0132 = stack[-5];
    v0110 = qcar(v0132);
    v0132 = elt(env, 4); // "not set"
    v0132 = list3(v0246, v0110, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-7];
    fn = elt(env, 13); // rerror
    v0132 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    goto v0260;
// error exit handlers
v0249:
    popv(8);
    return nil;
}



// Code for bound

static LispObject CC_bound(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bound");
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
    v0017 = v0000;
// end of prologue
    fn = elt(env, 3); // binding
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[0];
    v0016 = v0017;
    v0017 = v0016;
    if (v0017 == nil) goto v0076;
    v0017 = v0016;
    v0016 = elt(env, 2); // unbound
        popv(1);
        return Lneq(nil, v0017, v0016);

v0076:
    v0017 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0017); }
// error exit handlers
v0056:
    popv(1);
    return nil;
}



// Code for vecopp

static LispObject CC_vecopp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0079, v0060, v0027;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vecopp");
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
    v0027 = v0000;
// end of prologue
    v0079 = v0027;
    if (symbolp(v0079)) goto v0039;
    v0079 = qvalue(elt(env, 1)); // nil
    goto v0086;

v0086:
    if (!(v0079 == nil)) return onevalue(v0079);
    v0079 = v0027;
    if (!consp(v0079)) goto v0014;
    v0079 = v0027;
    v0079 = qcar(v0079);
    if (!symbolp(v0079)) v0060 = nil;
    else { v0060 = qfastgets(v0079);
           if (v0060 != nil) { v0060 = elt(v0060, 18); // phystype
#ifdef RECORD_GET
             if (v0060 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0060 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0060 == SPID_NOPROP) v0060 = nil; }}
#endif
    v0079 = elt(env, 2); // vector
    if (v0060 == v0079) goto v0071;
    v0079 = qvalue(elt(env, 1)); // nil
    return onevalue(v0079);

v0071:
    v0079 = v0027;
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    fn = elt(env, 3); // isanindex
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    errexit();
    v0079 = (v0079 == nil ? lisp_true : nil);
    return onevalue(v0079);

v0014:
    v0079 = qvalue(elt(env, 1)); // nil
    return onevalue(v0079);

v0039:
    v0079 = v0027;
    if (!symbolp(v0079)) v0060 = nil;
    else { v0060 = qfastgets(v0079);
           if (v0060 != nil) { v0060 = elt(v0060, 18); // phystype
#ifdef RECORD_GET
             if (v0060 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0060 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0060 == SPID_NOPROP) v0060 = nil; }}
#endif
    v0079 = elt(env, 2); // vector
    v0079 = (v0060 == v0079 ? lisp_true : nil);
    goto v0086;
}



// Code for sroad

static LispObject CC_sroad(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0058, v0245, v0052;
    LispObject fn;
    LispObject v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sroad");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sroad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0037;
    stack[-2] = v0000;
// end of prologue
    v0052 = nil;
    goto v0076;

v0076:
    v0058 = stack[0];
    if (v0058 == nil) goto v0015;
    v0245 = stack[-2];
    v0058 = stack[0];
    v0058 = qcar(v0058);
    if (equal(v0245, v0058)) goto v0070;
    v0058 = stack[0];
    v0058 = qcar(v0058);
    v0245 = v0052;
    v0058 = cons(v0058, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0052 = v0058;
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    stack[0] = v0058;
    goto v0076;

v0070:
    stack[-2] = v0052;
    v0245 = stack[-1];
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    v0058 = Lappend(nil, v0245, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    {
        LispObject v0044 = stack[-2];
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0044, v0058);
    }

v0015:
    v0058 = v0052;
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0058);
    }
// error exit handlers
v0043:
    popv(4);
    return nil;
}



// Code for simpplus

static LispObject CC_simpplus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0066;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpplus");
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
    v0101 = stack[0];
    v0066 = Llength(nil, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    v0101 = (LispObject)33; // 2
    if (!(v0066 == v0101)) goto v0017;
    v0101 = stack[0];
    fn = elt(env, 2); // ckpreci!#
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    goto v0017;

v0017:
    v0066 = qvalue(elt(env, 1)); // nil
    v0101 = (LispObject)17; // 1
    v0101 = cons(v0066, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    stack[-1] = v0101;
    goto v0025;

v0025:
    v0101 = stack[0];
    if (v0101 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0101 = stack[0];
    fn = elt(env, 3); // simpcar
    v0066 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    v0101 = stack[-1];
    fn = elt(env, 4); // addsq
    v0101 = (*qfn2(fn))(qenv(fn), v0066, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    stack[-1] = v0101;
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0025;
// error exit handlers
v0203:
    popv(3);
    return nil;
}



// Code for red!-weight1

static LispObject CC_redKweight1(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0245, v0052;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-weight1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0076;

v0076:
    v0245 = stack[-1];
    if (v0245 == nil) goto v0053;
    v0245 = stack[-1];
    v0245 = qcar(v0245);
    v0052 = Labsval(nil, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0245 = stack[0];
    v0245 = qcar(v0245);
    v0052 = times2(v0052, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0245 = stack[-2];
    v0245 = cons(v0052, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    stack[-2] = v0245;
    v0245 = stack[-1];
    v0245 = qcdr(v0245);
    stack[-1] = v0245;
    v0245 = stack[0];
    v0245 = qcdr(v0245);
    stack[0] = v0245;
    goto v0076;

v0053:
    v0245 = (LispObject)1; // 0
    v0052 = v0245;
    goto v0038;

v0038:
    v0245 = stack[-2];
    if (v0245 == nil) { popv(4); return onevalue(v0052); }
    v0245 = stack[-2];
    v0245 = qcar(v0245);
    v0245 = plus2(v0245, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0052 = v0245;
    v0245 = stack[-2];
    v0245 = qcdr(v0245);
    stack[-2] = v0245;
    goto v0038;
// error exit handlers
v0043:
    popv(4);
    return nil;
}



// Code for dp_times_bc

static LispObject CC_dp_times_bc(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0262, v0090;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_times_bc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    v0262 = v0037;
    stack[-4] = v0000;
// end of prologue
    stack[-5] = v0262;
    v0262 = stack[-5];
    if (v0262 == nil) goto v0081;
    v0262 = stack[-5];
    v0262 = qcar(v0262);
    v0090 = v0262;
    stack[0] = qcar(v0090);
    v0090 = stack[-4];
    v0262 = qcdr(v0262);
    fn = elt(env, 2); // cali_bc_prod
    v0262 = (*qfn2(fn))(qenv(fn), v0090, v0262);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-6];
    v0262 = cons(stack[0], v0262);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-6];
    v0262 = ncons(v0262);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-6];
    stack[-2] = v0262;
    stack[-3] = v0262;
    goto v0053;

v0053:
    v0262 = stack[-5];
    v0262 = qcdr(v0262);
    stack[-5] = v0262;
    v0262 = stack[-5];
    if (v0262 == nil) { LispObject res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0262 = stack[-5];
    v0262 = qcar(v0262);
    v0090 = v0262;
    stack[0] = qcar(v0090);
    v0090 = stack[-4];
    v0262 = qcdr(v0262);
    fn = elt(env, 2); // cali_bc_prod
    v0262 = (*qfn2(fn))(qenv(fn), v0090, v0262);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-6];
    v0262 = cons(stack[0], v0262);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-6];
    v0262 = ncons(v0262);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-6];
    v0262 = Lrplacd(nil, stack[-1], v0262);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-6];
    v0262 = stack[-2];
    v0262 = qcdr(v0262);
    stack[-2] = v0262;
    goto v0053;

v0081:
    v0262 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0262); }
// error exit handlers
v0065:
    popv(7);
    return nil;
}



// Code for dv_skelhead

static LispObject CC_dv_skelhead(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_skelhead");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0025 = v0000;
// end of prologue
    v0025 = qcar(v0025);
    {
        fn = elt(env, 1); // dv_cambhead
        return (*qfn1(fn))(qenv(fn), v0025);
    }
}



// Code for general!-plus!-mod!-p

static LispObject CC_generalKplusKmodKp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0280, v0281, v0201;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-plus-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0037;
    stack[-2] = v0000;
// end of prologue
    stack[0] = nil;
    goto v0086;

v0086:
    v0280 = stack[-2];
    if (v0280 == nil) goto v0039;
    v0280 = stack[-1];
    if (v0280 == nil) goto v0022;
    v0280 = stack[-2];
    if (!consp(v0280)) goto v0021;
    v0280 = stack[-2];
    v0280 = qcar(v0280);
    v0280 = (consp(v0280) ? nil : lisp_true);
    goto v0085;

v0085:
    if (v0280 == nil) goto v0049;
    v0280 = stack[-1];
    if (!consp(v0280)) goto v0077;
    v0280 = stack[-1];
    v0280 = qcar(v0280);
    v0280 = (consp(v0280) ? nil : lisp_true);
    goto v0203;

v0203:
    if (v0280 == nil) goto v0009;
    v0281 = stack[-2];
    v0280 = stack[-1];
    fn = elt(env, 3); // general!-modular!-plus
    v0280 = (*qfn2(fn))(qenv(fn), v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    fn = elt(env, 4); // !*n2f
    v0280 = (*qfn1(fn))(qenv(fn), v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    {
        LispObject v0155 = stack[0];
        popv(5);
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(qenv(fn), v0155, v0280);
    }

v0009:
    v0280 = stack[-1];
    v0281 = qcar(v0280);
    v0280 = stack[0];
    v0280 = cons(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    stack[0] = v0280;
    v0280 = stack[-1];
    v0280 = qcdr(v0280);
    stack[-1] = v0280;
    goto v0086;

v0077:
    v0280 = qvalue(elt(env, 1)); // t
    goto v0203;

v0049:
    v0280 = stack[-1];
    if (!consp(v0280)) goto v0100;
    v0280 = stack[-1];
    v0280 = qcar(v0280);
    v0280 = (consp(v0280) ? nil : lisp_true);
    goto v0099;

v0099:
    if (v0280 == nil) goto v0006;
    v0280 = stack[-2];
    v0281 = qcar(v0280);
    v0280 = stack[0];
    v0280 = cons(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    stack[0] = v0280;
    v0280 = stack[-2];
    v0280 = qcdr(v0280);
    stack[-2] = v0280;
    goto v0086;

v0006:
    v0280 = stack[-2];
    v0280 = qcar(v0280);
    v0281 = qcar(v0280);
    v0280 = stack[-1];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    if (equal(v0281, v0280)) goto v0242;
    v0280 = stack[-2];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    v0281 = qcar(v0280);
    v0280 = stack[-1];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    if (equal(v0281, v0280)) goto v0175;
    v0280 = qvalue(elt(env, 2)); // nil
    goto v0178;

v0178:
    if (!(v0280 == nil)) goto v0282;
    v0280 = stack[-2];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    v0281 = qcar(v0280);
    v0280 = stack[-1];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    if (equal(v0281, v0280)) goto v0283;
    v0280 = stack[-2];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    v0281 = qcar(v0280);
    v0280 = stack[-1];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    fn = elt(env, 6); // ordop
    v0280 = (*qfn2(fn))(qenv(fn), v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    goto v0284;

v0284:
    if (!(v0280 == nil)) goto v0282;
    v0280 = stack[-1];
    v0281 = qcar(v0280);
    v0280 = stack[0];
    v0280 = cons(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    stack[0] = v0280;
    v0280 = stack[-1];
    v0280 = qcdr(v0280);
    stack[-1] = v0280;
    goto v0086;

v0282:
    v0280 = stack[-2];
    v0281 = qcar(v0280);
    v0280 = stack[0];
    v0280 = cons(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    stack[0] = v0280;
    v0280 = stack[-2];
    v0280 = qcdr(v0280);
    stack[-2] = v0280;
    goto v0086;

v0283:
    v0280 = qvalue(elt(env, 2)); // nil
    goto v0284;

v0175:
    v0280 = stack[-2];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    v0281 = qcdr(v0280);
    v0280 = stack[-1];
    v0280 = qcar(v0280);
    v0280 = qcar(v0280);
    v0280 = qcdr(v0280);
    v0280 = ((intptr_t)v0281 > (intptr_t)v0280) ? lisp_true : nil;
    goto v0178;

v0242:
    stack[-3] = stack[0];
    v0280 = stack[-2];
    v0280 = qcar(v0280);
    v0281 = qcdr(v0280);
    v0280 = stack[-1];
    v0280 = qcar(v0280);
    v0280 = qcdr(v0280);
    stack[0] = CC_generalKplusKmodKp(env, v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0280 = stack[-2];
    v0281 = qcdr(v0280);
    v0280 = stack[-1];
    v0280 = qcdr(v0280);
    v0280 = CC_generalKplusKmodKp(env, v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0281 = stack[0];
    v0201 = v0281;
    if (v0201 == nil) goto v0183;
    v0201 = stack[-2];
    v0201 = qcar(v0201);
    v0201 = qcar(v0201);
    v0280 = acons(v0201, v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    goto v0183;

v0183:
    {
        LispObject v0223 = stack[-3];
        popv(5);
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(qenv(fn), v0223, v0280);
    }

v0100:
    v0280 = qvalue(elt(env, 1)); // t
    goto v0099;

v0021:
    v0280 = qvalue(elt(env, 1)); // t
    goto v0085;

v0022:
    v0281 = stack[0];
    v0280 = stack[-2];
    {
        popv(5);
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(qenv(fn), v0281, v0280);
    }

v0039:
    v0281 = stack[0];
    v0280 = stack[-1];
    {
        popv(5);
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(qenv(fn), v0281, v0280);
    }
// error exit handlers
v0154:
    popv(5);
    return nil;
}



// Code for divide!:

static LispObject CC_divideT(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0029, v0028;
    LispObject fn;
    LispObject v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "divide:");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for divide:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    stack[-2] = v0037;
    stack[-3] = v0000;
// end of prologue
    stack[0] = stack[-1];
    v0029 = stack[-2];
    v0029 = qcdr(v0029);
    v0029 = qcar(v0029);
    v0029 = Labsval(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-5];
    fn = elt(env, 2); // msd
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-5];
    v0029 = add1(v0029);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-5];
    v0029 = plus2(stack[0], v0029);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-5];
    fn = elt(env, 3); // conv!:mt
    v0029 = (*qfn2(fn))(qenv(fn), stack[-3], v0029);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-5];
    stack[-3] = v0029;
    stack[-4] = elt(env, 1); // !:rd!:
    v0029 = stack[-3];
    v0029 = qcdr(v0029);
    v0028 = qcar(v0029);
    v0029 = stack[-2];
    v0029 = qcdr(v0029);
    v0029 = qcar(v0029);
    stack[0] = quot2(v0028, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-5];
    v0029 = stack[-3];
    v0029 = qcdr(v0029);
    v0028 = qcdr(v0029);
    v0029 = stack[-2];
    v0029 = qcdr(v0029);
    v0029 = qcdr(v0029);
    v0029 = difference2(v0028, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-5];
    v0029 = list2star(stack[-4], stack[0], v0029);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-5];
    stack[-3] = v0029;
    v0028 = stack[-3];
    v0029 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); // round!:mt
        return (*qfn2(fn))(qenv(fn), v0028, v0029);
    }
// error exit handlers
v0067:
    popv(6);
    return nil;
}



// Code for mcharg2

static LispObject CC_mcharg2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0243, v0181, v0182;
    LispObject fn;
    LispObject v0003, v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "mcharg2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mcharg2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0002,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0037,v0002,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-6] = v0003;
    stack[-7] = v0002;
    stack[-8] = v0037;
    stack[-9] = v0000;
// end of prologue
    v0243 = stack[-9];
    if (v0243 == nil) { LispObject res = stack[-7]; popv(12); return onevalue(res); }
    v0243 = stack[-9];
    v0181 = qcar(v0243);
    v0243 = stack[-8];
    v0243 = qcar(v0243);
    fn = elt(env, 2); // mchk
    v0243 = (*qfn2(fn))(qenv(fn), v0181, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    v0181 = v0243;
    v0243 = stack[-9];
    v0243 = qcdr(v0243);
    stack[-9] = v0243;
    v0243 = stack[-8];
    v0243 = qcdr(v0243);
    stack[-8] = v0243;
    v0243 = v0181;
    stack[-10] = v0243;
    goto v0045;

v0045:
    v0243 = stack[-10];
    if (v0243 == nil) goto v0061;
    v0243 = stack[-10];
    v0243 = qcar(v0243);
    stack[-2] = v0243;
    stack[-1] = stack[-9];
    v0182 = stack[-2];
    v0181 = stack[-8];
    v0243 = stack[-6];
    fn = elt(env, 3); // updtemplate
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0182, v0181, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    v0181 = stack[-7];
    v0243 = stack[-2];
    fn = elt(env, 4); // msappend
    v0181 = (*qfn2(fn))(qenv(fn), v0181, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    v0243 = stack[-6];
    v0243 = CC_mcharg2(env, 4, stack[-1], stack[0], v0181, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    stack[-5] = v0243;
    v0243 = stack[-5];
    fn = elt(env, 5); // lastpair
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    stack[-4] = v0243;
    v0243 = stack[-10];
    v0243 = qcdr(v0243);
    stack[-10] = v0243;
    v0243 = stack[-4];
    if (!consp(v0243)) goto v0045;
    else goto v0085;

v0085:
    v0243 = stack[-10];
    if (v0243 == nil) { LispObject res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v0243 = stack[-10];
    v0243 = qcar(v0243);
    stack[-2] = v0243;
    stack[-1] = stack[-9];
    v0182 = stack[-2];
    v0181 = stack[-8];
    v0243 = stack[-6];
    fn = elt(env, 3); // updtemplate
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0182, v0181, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    v0181 = stack[-7];
    v0243 = stack[-2];
    fn = elt(env, 4); // msappend
    v0181 = (*qfn2(fn))(qenv(fn), v0181, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    v0243 = stack[-6];
    v0243 = CC_mcharg2(env, 4, stack[-1], stack[0], v0181, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    v0243 = Lrplacd(nil, stack[-3], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    v0243 = stack[-4];
    fn = elt(env, 5); // lastpair
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-11];
    stack[-4] = v0243;
    v0243 = stack[-10];
    v0243 = qcdr(v0243);
    stack[-10] = v0243;
    goto v0085;

v0061:
    v0243 = qvalue(elt(env, 1)); // nil
    { popv(12); return onevalue(v0243); }
// error exit handlers
v0026:
    popv(12);
    return nil;
}



// Code for totallessp

static LispObject CC_totallessp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0055, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for totallessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0055 = v0037;
    v0054 = v0000;
// end of prologue
    fn = elt(env, 2); // totalcompare
    v0055 = (*qfn2(fn))(qenv(fn), v0054, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[0];
    v0054 = elt(env, 1); // less
    v0055 = (v0055 == v0054 ? lisp_true : nil);
    { popv(1); return onevalue(v0055); }
// error exit handlers
v0018:
    popv(1);
    return nil;
}



// Code for powers1

static LispObject CC_powers1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0018, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers1");
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
    v0018 = v0000;
// end of prologue
    stack[0] = v0018;
    v0017 = v0018;
    v0018 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // powers3
    v0017 = (*qfn2(fn))(qenv(fn), v0017, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-1];
    v0018 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0022 = stack[0];
        popv(2);
        fn = elt(env, 3); // powers2
        return (*qfnn(fn))(qenv(fn), 3, v0022, v0017, v0018);
    }
// error exit handlers
v0056:
    popv(2);
    return nil;
}



// Code for ibalp_varlat

static LispObject CC_ibalp_varlat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_varlat");
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
    v0082 = stack[0];
    fn = elt(env, 1); // ibalp_arg2l
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    fn = elt(env, 2); // ibalp_varlt
    stack[-1] = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    v0082 = stack[0];
    fn = elt(env, 3); // ibalp_arg2r
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    fn = elt(env, 2); // ibalp_varlt
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    {
        LispObject v0055 = stack[-1];
        popv(3);
        fn = elt(env, 4); // union
        return (*qfn2(fn))(qenv(fn), v0055, v0082);
    }
// error exit handlers
v0041:
    popv(3);
    return nil;
}



// Code for retattributes

static LispObject CC_retattributes(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0012, v0010;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for retattributes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    stack[-1] = v0000;
// end of prologue

v0286:
    v0012 = stack[0];
    if (v0012 == nil) goto v0076;
    v0010 = stack[-1];
    v0012 = stack[0];
    v0012 = qcar(v0012);
    fn = elt(env, 2); // find
    v0012 = (*qfn2(fn))(qenv(fn), v0010, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    v0010 = v0012;
    if (v0010 == nil) goto v0245;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    stack[-2] = list2(v0010, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    v0010 = stack[-1];
    v0012 = stack[0];
    v0012 = qcdr(v0012);
    v0012 = CC_retattributes(env, v0010, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    {
        LispObject v0261 = stack[-2];
        popv(4);
        return cons(v0261, v0012);
    }

v0245:
    v0010 = stack[-1];
    v0012 = stack[0];
    v0012 = qcdr(v0012);
    stack[-1] = v0010;
    stack[0] = v0012;
    goto v0286;

v0076:
    v0012 = nil;
    { popv(4); return onevalue(v0012); }
// error exit handlers
v0104:
    popv(4);
    return nil;
}



// Code for retimes1

static LispObject CC_retimes1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0287, v0185;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for retimes1");
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
    goto v0025;

v0025:
    v0287 = stack[0];
    if (v0287 == nil) goto v0053;
    v0287 = stack[0];
    v0185 = qcar(v0287);
    v0287 = (LispObject)17; // 1
    if (v0185 == v0287) goto v0039;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = Lminusp(nil, v0287);
    env = stack[-2];
    if (v0287 == nil) goto v0070;
    v0287 = qvalue(elt(env, 1)); // !*bool
    v0287 = (v0287 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0287; // !*bool
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0185 = negate(v0287);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-2];
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    v0287 = cons(v0185, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-2];
    stack[0] = v0287;
    goto v0025;

v0070:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    if (!consp(v0287)) goto v0014;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0185 = qcar(v0287);
    v0287 = elt(env, 2); // minus
    if (v0185 == v0287) goto v0194;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0185 = qcar(v0287);
    v0287 = elt(env, 3); // times
    if (v0185 == v0287) goto v0288;
    v0287 = stack[0];
    v0185 = qcar(v0287);
    v0287 = stack[-1];
    v0287 = cons(v0185, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-2];
    stack[-1] = v0287;
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = v0287;
    goto v0025;

v0288:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0185 = qcdr(v0287);
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    v0287 = Lappend(nil, v0185, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-2];
    stack[0] = v0287;
    goto v0025;

v0194:
    v0287 = qvalue(elt(env, 1)); // !*bool
    v0287 = (v0287 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0287; // !*bool
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcdr(v0287);
    v0185 = qcar(v0287);
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    v0287 = cons(v0185, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-2];
    stack[0] = v0287;
    goto v0025;

v0014:
    v0287 = stack[0];
    v0185 = qcar(v0287);
    v0287 = stack[-1];
    v0287 = cons(v0185, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-2];
    stack[-1] = v0287;
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = v0287;
    goto v0025;

v0039:
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = v0287;
    goto v0025;

v0053:
    v0287 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); // nreverse
        return (*qfn1(fn))(qenv(fn), v0287);
    }
// error exit handlers
v0206:
    popv(3);
    return nil;
}



// Code for variables

static LispObject CC_variables(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0020, v0289;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for variables");
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
    v0020 = (LispObject)1; // 0
    stack[-4] = v0020;
    v0020 = stack[-5];
    if (v0020 == nil) goto v0041;
    v0020 = qvalue(elt(env, 2)); // dipvars!*
    v0020 = Llength(nil, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-7];
    stack[-6] = v0020;
    v0020 = (LispObject)17; // 1
    stack[-3] = v0020;
    v0289 = stack[-6];
    v0020 = stack[-3];
    v0020 = difference2(v0289, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-7];
    v0020 = Lminusp(nil, v0020);
    env = stack[-7];
    if (v0020 == nil) goto v0048;
    v0020 = qvalue(elt(env, 1)); // nil
    goto v0078;

v0078:
    stack[0] = v0020;
    goto v0015;

v0015:
    v0020 = stack[-5];
    v0020 = qcar(v0020);
    v0020 = qcdr(v0020);
    v0020 = qcdr(v0020);
    v0020 = qcdr(v0020);
    v0020 = qcar(v0020);
    stack[-2] = v0020;
    goto v0023;

v0023:
    v0020 = stack[-2];
    v0020 = qcar(v0020);
    stack[-3] = v0020;
    v0020 = stack[0];
    stack[-1] = v0020;
    goto v0260;

v0260:
    v0020 = stack[-3];
    v0289 = qcar(v0020);
    v0020 = (LispObject)1; // 0
    if (!(((int32_t)(v0289)) > ((int32_t)(v0020)))) goto v0188;
    v0020 = stack[-1];
    v0020 = qcar(v0020);
    if (!(v0020 == nil)) goto v0188;
    v0289 = stack[-1];
    v0020 = qvalue(elt(env, 3)); // t
    fn = elt(env, 4); // setcar
    v0020 = (*qfn2(fn))(qenv(fn), v0289, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-7];
    v0020 = stack[-4];
    v0020 = (LispObject)((int32_t)(v0020) + 0x10);
    stack[-4] = v0020;
    goto v0188;

v0188:
    v0289 = stack[-4];
    v0020 = stack[-6];
    if (v0289 == v0020) { LispObject res = stack[0]; popv(8); return onevalue(res); }
    v0020 = stack[-3];
    v0020 = qcdr(v0020);
    stack[-3] = v0020;
    v0020 = stack[-3];
    if (v0020 == nil) goto v0285;
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    stack[-1] = v0020;
    goto v0260;

v0285:
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    v0020 = qcdr(v0020);
    stack[-2] = v0020;
    v0020 = stack[-2];
    if (!(v0020 == nil)) goto v0023;
    v0020 = stack[-5];
    v0020 = qcdr(v0020);
    stack[-5] = v0020;
    v0020 = stack[-5];
    if (v0020 == nil) { LispObject res = stack[0]; popv(8); return onevalue(res); }
    else goto v0015;

v0048:
    v0020 = qvalue(elt(env, 1)); // nil
    v0020 = ncons(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-7];
    stack[-1] = v0020;
    stack[-2] = v0020;
    goto v0074;

v0074:
    v0020 = stack[-3];
    v0020 = add1(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-7];
    stack[-3] = v0020;
    v0289 = stack[-6];
    v0020 = stack[-3];
    v0020 = difference2(v0289, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-7];
    v0020 = Lminusp(nil, v0020);
    env = stack[-7];
    if (v0020 == nil) goto v0011;
    v0020 = stack[-2];
    goto v0078;

v0011:
    stack[0] = stack[-1];
    v0020 = qvalue(elt(env, 1)); // nil
    v0020 = ncons(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-7];
    v0020 = Lrplacd(nil, stack[0], v0020);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-7];
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    stack[-1] = v0020;
    goto v0074;

v0041:
    v0020 = qvalue(elt(env, 1)); // nil
    { popv(8); return onevalue(v0020); }
// error exit handlers
v0274:
    popv(8);
    return nil;
}



// Code for worderp

static LispObject CC_worderp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0292, v0293, v0294;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for worderp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0037;
    stack[-1] = v0000;
// end of prologue

v0025:
    v0292 = stack[-1];
    if (!consp(v0292)) goto v0062;
    v0292 = stack[-1];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 16); // indexvar
#ifdef RECORD_GET
             if (v0292 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0292 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0292 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; else v0292 = lisp_true; }}
#endif
    if (v0292 == nil) goto v0045;
    v0292 = stack[0];
    if (!consp(v0292)) goto v0072;
    v0292 = stack[0];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 16); // indexvar
#ifdef RECORD_GET
             if (v0292 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0292 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0292 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; else v0292 = lisp_true; }}
#endif
    goto v0023;

v0023:
    if (v0292 == nil) goto v0038;
    v0293 = stack[-1];
    v0292 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // indexvarordp
        return (*qfn2(fn))(qenv(fn), v0293, v0292);
    }

v0038:
    v0292 = stack[-1];
    if (!consp(v0292)) goto v0079;
    v0293 = stack[-1];
    v0292 = qvalue(elt(env, 3)); // kord!*
    v0292 = Lmemq(nil, v0293, v0292);
    goto v0077;

v0077:
    if (v0292 == nil) goto v0014;
    v0292 = stack[0];
    if (!consp(v0292)) goto v0189;
    v0293 = stack[0];
    v0292 = qvalue(elt(env, 3)); // kord!*
    v0292 = Lmemq(nil, v0293, v0292);
    goto v0261;

v0261:
    if (v0292 == nil) goto v0102;
    v0293 = stack[-1];
    v0292 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); // ordop
        return (*qfn2(fn))(qenv(fn), v0293, v0292);
    }

v0102:
    v0292 = stack[0];
    fn = elt(env, 6); // peel
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-2];
    v0294 = v0292;
    v0293 = stack[-1];
    v0292 = v0294;
    if (v0293 == v0292) goto v0244;
    v0292 = stack[-1];
    v0293 = v0294;
    stack[-1] = v0292;
    stack[0] = v0293;
    goto v0025;

v0244:
    v0292 = qvalue(elt(env, 2)); // t
    { popv(3); return onevalue(v0292); }

v0189:
    v0292 = qvalue(elt(env, 2)); // t
    goto v0261;

v0014:
    v0292 = stack[0];
    if (!consp(v0292)) goto v0196;
    v0293 = stack[0];
    v0292 = qvalue(elt(env, 3)); // kord!*
    v0292 = Lmemq(nil, v0293, v0292);
    goto v0285;

v0285:
    if (v0292 == nil) goto v0295;
    v0292 = stack[-1];
    fn = elt(env, 6); // peel
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-2];
    v0294 = v0292;
    v0293 = v0294;
    v0292 = stack[0];
    if (v0293 == v0292) goto v0277;
    v0293 = v0294;
    v0292 = stack[0];
    stack[-1] = v0293;
    stack[0] = v0292;
    goto v0025;

v0277:
    v0292 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0292); }

v0295:
    v0292 = stack[-1];
    fn = elt(env, 6); // peel
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-2];
    stack[-1] = v0292;
    v0292 = stack[0];
    fn = elt(env, 6); // peel
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-2];
    stack[0] = v0292;
    goto v0025;

v0196:
    v0292 = qvalue(elt(env, 2)); // t
    goto v0285;

v0079:
    v0292 = qvalue(elt(env, 2)); // t
    goto v0077;

v0072:
    v0292 = qvalue(elt(env, 1)); // nil
    goto v0023;

v0045:
    v0292 = qvalue(elt(env, 1)); // nil
    goto v0023;

v0062:
    v0292 = qvalue(elt(env, 1)); // nil
    goto v0023;
// error exit handlers
v0272:
    popv(3);
    return nil;
}



// Code for evaluate0

static LispObject CC_evaluate0(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0081, v0039;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0037;
    v0081 = v0000;
// end of prologue
    fn = elt(env, 1); // evaluate!-horner
    v0039 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-1];
    v0081 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // evaluate1
        return (*qfn2(fn))(qenv(fn), v0039, v0081);
    }
// error exit handlers
v0050:
    popv(2);
    return nil;
}



// Code for eofcheck

static LispObject CC_eofcheck(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0048, v0049;
    argcheck(nargs, 0, "eofcheck");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for eofcheck");
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
    v0049 = qvalue(elt(env, 1)); // program!*
    v0048 = qvalue(elt(env, 2)); // !$eof!$
    if (v0049 == v0048) goto v0040;
    v0048 = qvalue(elt(env, 5)); // nil
    { popv(1); return onevalue(v0048); }

v0040:
    v0049 = qvalue(elt(env, 3)); // ttype!*
    v0048 = (LispObject)49; // 3
    if (v0049 == v0048) goto v0082;
    v0048 = qvalue(elt(env, 5)); // nil
    { popv(1); return onevalue(v0048); }

v0082:
    v0048 = qvalue(elt(env, 4)); // eof!*
    v0048 = add1(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[0];
    qvalue(elt(env, 4)) = v0048; // eof!*
    { popv(1); return onevalue(v0048); }
// error exit handlers
v0045:
    popv(1);
    return nil;
}



// Code for dp_ecart

static LispObject CC_dp_ecart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_ecart");
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
    v0017 = stack[0];
    if (v0017 == nil) goto v0001;
    v0017 = stack[0];
    fn = elt(env, 1); // dp!=ecart
    stack[-1] = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    v0017 = stack[0];
    fn = elt(env, 2); // dp_lmon
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    fn = elt(env, 3); // mo_ecart
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    {
        LispObject v0069 = stack[-1];
        popv(3);
        return difference2(v0069, v0017);
    }

v0001:
    v0017 = (LispObject)1; // 0
    { popv(3); return onevalue(v0017); }
// error exit handlers
v0022:
    popv(3);
    return nil;
}



// Code for pdmult

static LispObject CC_pdmult(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0259, v0302;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pdmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-8] = v0037;
    v0259 = v0000;
// end of prologue
    stack[-9] = v0259;
    v0259 = stack[-9];
    if (v0259 == nil) goto v0081;
    v0259 = stack[-9];
    v0259 = qcar(v0259);
    stack[-4] = v0259;
    v0259 = stack[-4];
    v0302 = qcar(v0259);
    v0259 = stack[-8];
    fn = elt(env, 2); // pair
    v0259 = (*qfn2(fn))(qenv(fn), v0302, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    stack[-3] = v0259;
    v0259 = stack[-3];
    if (v0259 == nil) goto v0047;
    v0259 = stack[-3];
    v0259 = qcar(v0259);
    v0302 = v0259;
    v0302 = qcar(v0302);
    v0259 = qcdr(v0259);
    v0259 = (LispObject)(int32_t)((int32_t)v0302 + (int32_t)v0259 - TAG_FIXNUM);
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    stack[-1] = v0259;
    stack[-2] = v0259;
    goto v0048;

v0048:
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    stack[-3] = v0259;
    v0259 = stack[-3];
    if (v0259 == nil) goto v0010;
    stack[0] = stack[-1];
    v0259 = stack[-3];
    v0259 = qcar(v0259);
    v0302 = v0259;
    v0302 = qcar(v0302);
    v0259 = qcdr(v0259);
    v0259 = (LispObject)(int32_t)((int32_t)v0302 + (int32_t)v0259 - TAG_FIXNUM);
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    v0259 = Lrplacd(nil, stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    stack[-1] = v0259;
    goto v0048;

v0010:
    v0259 = stack[-2];
    v0302 = v0259;
    goto v0056;

v0056:
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = cons(v0302, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    stack[-6] = v0259;
    stack[-7] = v0259;
    goto v0053;

v0053:
    v0259 = stack[-9];
    v0259 = qcdr(v0259);
    stack[-9] = v0259;
    v0259 = stack[-9];
    if (v0259 == nil) { LispObject res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v0259 = stack[-9];
    v0259 = qcar(v0259);
    stack[-4] = v0259;
    v0259 = stack[-4];
    v0302 = qcar(v0259);
    v0259 = stack[-8];
    fn = elt(env, 2); // pair
    v0259 = (*qfn2(fn))(qenv(fn), v0302, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    stack[-3] = v0259;
    v0259 = stack[-3];
    if (v0259 == nil) goto v0243;
    v0259 = stack[-3];
    v0259 = qcar(v0259);
    v0302 = v0259;
    v0302 = qcar(v0302);
    v0259 = qcdr(v0259);
    v0259 = (LispObject)(int32_t)((int32_t)v0302 + (int32_t)v0259 - TAG_FIXNUM);
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    stack[-1] = v0259;
    stack[-2] = v0259;
    goto v0196;

v0196:
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    stack[-3] = v0259;
    v0259 = stack[-3];
    if (v0259 == nil) goto v0304;
    stack[0] = stack[-1];
    v0259 = stack[-3];
    v0259 = qcar(v0259);
    v0302 = v0259;
    v0302 = qcar(v0302);
    v0259 = qcdr(v0259);
    v0259 = (LispObject)(int32_t)((int32_t)v0302 + (int32_t)v0259 - TAG_FIXNUM);
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    v0259 = Lrplacd(nil, stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    stack[-1] = v0259;
    goto v0196;

v0304:
    v0259 = stack[-2];
    v0302 = v0259;
    goto v0096;

v0096:
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    v0259 = cons(v0302, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    v0259 = Lrplacd(nil, stack[-5], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-10];
    v0259 = stack[-6];
    v0259 = qcdr(v0259);
    stack[-6] = v0259;
    goto v0053;

v0243:
    v0259 = qvalue(elt(env, 1)); // nil
    v0302 = v0259;
    goto v0096;

v0047:
    v0259 = qvalue(elt(env, 1)); // nil
    v0302 = v0259;
    goto v0056;

v0081:
    v0259 = qvalue(elt(env, 1)); // nil
    { popv(11); return onevalue(v0259); }
// error exit handlers
v0303:
    popv(11);
    return nil;
}



// Code for canonsq

static LispObject CC_canonsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0309, v0310, v0311;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for canonsq");
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
    v0309 = stack[-2];
    v0310 = qcdr(v0309);
    v0309 = (LispObject)17; // 1
    if (v0310 == v0309) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0309 = stack[-2];
    v0309 = qcar(v0309);
    if (v0309 == nil) goto v0018;
    stack[-1] = nil;
    v0309 = qvalue(elt(env, 2)); // asymplis!*
    if (v0309 == nil) goto v0085;
    v0309 = stack[-2];
    v0310 = qcar(v0309);
    v0309 = stack[-2];
    v0309 = qcdr(v0309);
    fn = elt(env, 7); // gcdf
    v0310 = (*qfn2(fn))(qenv(fn), v0310, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    stack[-3] = v0310;
    v0309 = (LispObject)17; // 1
    if (v0310 == v0309) goto v0085;
    v0309 = stack[-2];
    v0310 = qcar(v0309);
    v0309 = stack[-3];
    fn = elt(env, 8); // quotf!-fail
    stack[0] = (*qfn2(fn))(qenv(fn), v0310, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    v0309 = stack[-2];
    v0310 = qcdr(v0309);
    v0309 = stack[-3];
    fn = elt(env, 8); // quotf!-fail
    v0309 = (*qfn2(fn))(qenv(fn), v0310, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    v0309 = cons(stack[0], v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    stack[-2] = v0309;
    goto v0085;

v0085:
    v0309 = stack[-2];
    v0309 = qcdr(v0309);
    fn = elt(env, 9); // lnc
    v0309 = (*qfn1(fn))(qenv(fn), v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    stack[-3] = v0309;
    v0310 = stack[-3];
    v0309 = (LispObject)17; // 1
    if (v0310 == v0309) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0309 = stack[-3];
    if (!consp(v0309)) goto v0288;
    v0309 = stack[-3];
    v0309 = qcar(v0309);
    if (!symbolp(v0309)) v0310 = nil;
    else { v0310 = qfastgets(v0309);
           if (v0310 != nil) { v0310 = elt(v0310, 30); // minusp
#ifdef RECORD_GET
             if (v0310 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0310 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0310 == SPID_NOPROP) v0310 = nil; }}
#endif
    v0309 = stack[-3];
    v0309 = Lapply1(nil, v0310, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    if (v0309 == nil) goto v0068;
    v0309 = stack[-2];
    v0309 = qcar(v0309);
    fn = elt(env, 10); // negf
    stack[0] = (*qfn1(fn))(qenv(fn), v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    v0309 = stack[-2];
    v0309 = qcdr(v0309);
    fn = elt(env, 10); // negf
    v0309 = (*qfn1(fn))(qenv(fn), v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    v0309 = cons(stack[0], v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    stack[-2] = v0309;
    v0309 = stack[-3];
    v0310 = qcar(v0309);
    v0309 = elt(env, 3); // difference
    stack[0] = get(v0310, v0309);
    env = stack[-4];
    v0309 = stack[-3];
    v0309 = qcar(v0309);
    if (!symbolp(v0309)) v0310 = nil;
    else { v0310 = qfastgets(v0309);
           if (v0310 != nil) { v0310 = elt(v0310, 34); // i2d
#ifdef RECORD_GET
             if (v0310 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0310 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0310 == SPID_NOPROP) v0310 = nil; }}
#endif
    v0309 = (LispObject)1; // 0
    v0310 = Lapply1(nil, v0310, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    v0309 = stack[-3];
    v0309 = Lapply2(nil, 3, stack[0], v0310, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    stack[-3] = v0309;
    goto v0068;

v0068:
    v0309 = stack[-3];
    if (is_number(v0309)) goto v0302;
    v0310 = qvalue(elt(env, 4)); // dmode!*
    v0309 = elt(env, 5); // unitsfn
    v0309 = get(v0310, v0309);
    env = stack[-4];
    stack[-1] = v0309;
    goto v0313;

v0313:
    if (v0309 == nil) goto v0271;
    v0311 = stack[-1];
    v0310 = stack[-2];
    v0309 = stack[-3];
        popv(5);
        return Lapply2(nil, 3, v0311, v0310, v0309);

v0271:
    v0309 = qvalue(elt(env, 4)); // dmode!*
    if (!symbolp(v0309)) v0309 = nil;
    else { v0309 = qfastgets(v0309);
           if (v0309 != nil) { v0309 = elt(v0309, 3); // field
#ifdef RECORD_GET
             if (v0309 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0309 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0309 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0309 == SPID_NOPROP) v0309 = nil; else v0309 = lisp_true; }}
#endif
    if (v0309 == nil) goto v0314;
    v0309 = qvalue(elt(env, 6)); // t
    goto v0174;

v0174:
    if (v0309 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0310 = stack[-3];
    v0309 = stack[-2];
    {
        popv(5);
        fn = elt(env, 11); // fieldconv
        return (*qfn2(fn))(qenv(fn), v0310, v0309);
    }

v0314:
    v0309 = stack[-3];
    if (!consp(v0309)) goto v0228;
    v0309 = stack[-3];
    v0309 = qcar(v0309);
    if (!symbolp(v0309)) v0309 = nil;
    else { v0309 = qfastgets(v0309);
           if (v0309 != nil) { v0309 = elt(v0309, 3); // field
#ifdef RECORD_GET
             if (v0309 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0309 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0309 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0309 == SPID_NOPROP) v0309 = nil; else v0309 = lisp_true; }}
#endif
    goto v0174;

v0228:
    v0309 = qvalue(elt(env, 1)); // nil
    goto v0174;

v0302:
    v0309 = qvalue(elt(env, 1)); // nil
    goto v0313;

v0288:
    v0309 = stack[-3];
    v0309 = Lminusp(nil, v0309);
    env = stack[-4];
    if (v0309 == nil) goto v0068;
    v0309 = stack[-2];
    v0309 = qcar(v0309);
    fn = elt(env, 10); // negf
    stack[0] = (*qfn1(fn))(qenv(fn), v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    v0309 = stack[-2];
    v0309 = qcdr(v0309);
    fn = elt(env, 10); // negf
    v0309 = (*qfn1(fn))(qenv(fn), v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    v0309 = cons(stack[0], v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    stack[-2] = v0309;
    v0309 = stack[-3];
    v0309 = negate(v0309);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-4];
    stack[-3] = v0309;
    goto v0068;

v0018:
    v0310 = qvalue(elt(env, 1)); // nil
    v0309 = (LispObject)17; // 1
    popv(5);
    return cons(v0310, v0309);
// error exit handlers
v0312:
    popv(5);
    return nil;
}



// Code for get_action_without_lookahead

static LispObject CC_get_action_without_lookahead(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0024, v0047;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_action_without_lookahead");
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
    v0024 = v0000;
// end of prologue
    v0047 = qvalue(elt(env, 1)); // action_index
    fn = elt(env, 5); // getv16
    v0024 = (*qfn2(fn))(qenv(fn), v0047, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    stack[0] = v0024;
    v0047 = qvalue(elt(env, 2)); // action_terminal
    v0024 = stack[0];
    fn = elt(env, 5); // getv16
    v0047 = (*qfn2(fn))(qenv(fn), v0047, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    v0024 = (LispObject)-15; // -1
    if (v0047 == v0024) goto v0021;
    v0024 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0024); }

v0021:
    v0047 = qvalue(elt(env, 4)); // action_result
    v0024 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // getv16
        return (*qfn2(fn))(qenv(fn), v0047, v0024);
    }
// error exit handlers
v0101:
    popv(2);
    return nil;
}



// Code for ibalp_mk2

static LispObject CC_ibalp_mk2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0050, v0040, v0041;
    LispObject v0002, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ibalp_mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0050 = v0002;
    v0040 = v0037;
    v0041 = v0000;
// end of prologue
    return list3(v0041, v0040, v0050);
}



// Code for checktag

static LispObject CC_checktag(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0056, v0022;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for checktag");
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
    v0056 = v0000;
// end of prologue
    v0022 = qvalue(elt(env, 1)); // char
    if (equal(v0022, v0056)) goto v0025;
    v0022 = elt(env, 2); // "Problem"
    v0056 = elt(env, 3); // "problem"
    fn = elt(env, 4); // errorml
    v0056 = (*qfn2(fn))(qenv(fn), v0022, v0056);
    errexit();
    goto v0025;

v0025:
    v0056 = nil;
    return onevalue(v0056);
}



// Code for reval1

static LispObject CC_reval1(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0350, v0351, v0352;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reval1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0037);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0037;
    stack[-2] = v0000;
// end of prologue
    v0350 = qvalue(elt(env, 1)); // !*revalp
    if (v0350 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0350 = qvalue(elt(env, 2)); // varstack!*
    stack[-3] = qvalue(elt(env, 2)); // varstack!*
    qvalue(elt(env, 2)) = v0350; // varstack!*
    v0350 = stack[-2];
    if (v0350 == nil) goto v0054;
    v0350 = stack[-2];
    v0350 = Lstringp(nil, v0350);
    env = stack[-4];
    if (v0350 == nil) goto v0022;
    v0350 = stack[-2];
    goto v0040;

v0040:
    qvalue(elt(env, 2)) = stack[-3]; // varstack!*
    { popv(5); return onevalue(v0350); }

v0022:
    v0350 = stack[-2];
    v0350 = integerp(v0350);
    if (v0350 == nil) goto v0071;
    v0350 = qvalue(elt(env, 4)); // dmode!*
    if (!symbolp(v0350)) v0350 = nil;
    else { v0350 = qfastgets(v0350);
           if (v0350 != nil) { v0350 = elt(v0350, 5); // convert
#ifdef RECORD_GET
             if (v0350 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0350 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0350 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0350 == SPID_NOPROP) v0350 = nil; else v0350 = lisp_true; }}
#endif
    if (v0350 == nil) goto v0066;
    v0351 = stack[-2];
    v0350 = stack[-1];
    fn = elt(env, 21); // reval2
    v0350 = (*qfn2(fn))(qenv(fn), v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0066:
    v0350 = stack[-2];
    goto v0040;

v0071:
    v0350 = stack[-2];
    if (!consp(v0350)) goto v0203;
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    if (symbolp(v0350)) goto v0238;
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    v0351 = qcar(v0350);
    v0350 = elt(env, 7); // structfn
    v0350 = get(v0351, v0350);
    env = stack[-4];
    stack[0] = v0350;
    if (v0350 == nil) goto v0304;
    v0350 = stack[-2];
    v0350 = ncons(v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    fn = elt(env, 22); // apply
    v0350 = (*qfn2(fn))(qenv(fn), stack[0], v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0304:
    v0351 = stack[-2];
    v0350 = qvalue(elt(env, 8)); // t
    fn = elt(env, 23); // errpri2
    v0350 = (*qfn2(fn))(qenv(fn), v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0055;

v0055:
    v0350 = stack[-2];
    fn = elt(env, 24); // getrtype
    v0350 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    stack[0] = v0350;
    if (v0350 == nil) goto v0354;
    v0351 = stack[0];
    v0350 = elt(env, 6); // evfn
    v0350 = get(v0351, v0350);
    env = stack[-4];
    v0352 = v0350;
    if (v0350 == nil) goto v0355;
    v0351 = stack[-2];
    v0350 = stack[-1];
    v0350 = Lapply2(nil, 3, v0352, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0355:
    stack[-2] = elt(env, 12); // alg
    stack[-1] = (LispObject)1617; // 101
    v0351 = elt(env, 13); // "Missing evaluation for type"
    v0350 = stack[0];
    v0350 = list2(v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    fn = elt(env, 25); // rerror
    v0350 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0354:
    v0350 = stack[-2];
    if (!consp(v0350)) goto v0356;
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    if (!consp(v0350)) goto v0357;
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    v0350 = qcar(v0350);
    fn = elt(env, 24); // getrtype
    v0350 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    v0352 = v0350;
    if (v0350 == nil) goto v0214;
    v0351 = v0352;
    v0350 = elt(env, 14); // list
    if (v0351 == v0350) goto v0358;
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0359;

v0359:
    if (v0350 == nil) goto v0360;
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0140;

v0140:
    if (v0350 == nil) goto v0361;
    v0352 = stack[0];
    v0351 = stack[-2];
    v0350 = stack[-1];
    v0350 = Lapply2(nil, 3, v0352, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0361:
    v0351 = stack[-2];
    v0350 = stack[-1];
    fn = elt(env, 21); // reval2
    v0350 = (*qfn2(fn))(qenv(fn), v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0360:
    v0351 = v0352;
    v0350 = elt(env, 15); // aggregatefn
    v0350 = get(v0351, v0350);
    env = stack[-4];
    stack[0] = v0350;
    if (v0350 == nil) goto v0210;
    v0351 = stack[0];
    v0350 = elt(env, 16); // matrixmap
    if (v0351 == v0350) goto v0362;
    v0350 = qvalue(elt(env, 8)); // t
    goto v0363;

v0363:
    if (v0350 == nil) goto v0191;
    v0350 = stack[-2];
    v0351 = qcar(v0350);
    v0350 = elt(env, 18); // boolean
    v0350 = Lflagp(nil, v0351, v0350);
    env = stack[-4];
    if (v0350 == nil) goto v0364;
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0140;

v0364:
    v0350 = qvalue(elt(env, 19)); // !*listargs
    if (v0350 == nil) goto v0365;
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0140;

v0365:
    v0350 = stack[-2];
    v0351 = qcar(v0350);
    v0350 = elt(env, 20); // listargp
    v0350 = Lflagp(nil, v0351, v0350);
    env = stack[-4];
    v0350 = (v0350 == nil ? lisp_true : nil);
    goto v0140;

v0191:
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0140;

v0362:
    v0350 = stack[-2];
    v0351 = qcar(v0350);
    v0350 = elt(env, 17); // matmapfn
    v0350 = Lflagp(nil, v0351, v0350);
    env = stack[-4];
    goto v0363;

v0210:
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0140;

v0358:
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    v0350 = qcdr(v0350);
    goto v0359;

v0214:
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0140;

v0357:
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0140;

v0356:
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0140;

v0238:
    v0350 = stack[-2];
    v0351 = qcar(v0350);
    v0350 = elt(env, 9); // !*sq
    if (v0351 == v0350) goto v0366;
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    if (!symbolp(v0350)) v0350 = nil;
    else { v0350 = qfastgets(v0350);
           if (v0350 != nil) { v0350 = elt(v0350, 39); // remember
#ifdef RECORD_GET
             if (v0350 == SPID_NOPROP)
                record_get(elt(fastget_names, 39), 0),
                v0350 = nil;
             else record_get(elt(fastget_names, 39), 1),
                v0350 = lisp_true; }
           else record_get(elt(fastget_names, 39), 0); }
#else
             if (v0350 == SPID_NOPROP) v0350 = nil; else v0350 = lisp_true; }}
#endif
    if (v0350 == nil) goto v0173;
    v0351 = stack[-2];
    v0350 = stack[-1];
    fn = elt(env, 26); // rmmbreval
    v0350 = (*qfn2(fn))(qenv(fn), v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0173:
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    if (!symbolp(v0350)) v0350 = nil;
    else { v0350 = qfastgets(v0350);
           if (v0350 != nil) { v0350 = elt(v0350, 59); // opfn
#ifdef RECORD_GET
             if (v0350 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0350 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0350 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0350 == SPID_NOPROP) v0350 = nil; else v0350 = lisp_true; }}
#endif
    if (v0350 == nil) goto v0367;
    v0350 = stack[-2];
    fn = elt(env, 27); // opfneval
    v0351 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    v0350 = stack[-1];
    v0350 = CC_reval1(env, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0367:
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    if (!symbolp(v0350)) v0350 = nil;
    else { v0350 = qfastgets(v0350);
           if (v0350 != nil) { v0350 = elt(v0350, 45); // psopfn
#ifdef RECORD_GET
             if (v0350 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0350 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0350 == SPID_NOPROP) v0350 = nil; }}
#endif
    stack[0] = v0350;
    if (v0350 == nil) goto v0368;
    v0351 = stack[0];
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    v0350 = Lapply1(nil, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    stack[-2] = v0350;
    v0351 = stack[0];
    v0350 = elt(env, 11); // cleanupfn
    v0350 = get(v0351, v0350);
    env = stack[-4];
    stack[0] = v0350;
    if (v0350 == nil) goto v0282;
    v0352 = stack[0];
    v0351 = stack[-2];
    v0350 = stack[-1];
    v0350 = Lapply2(nil, 3, v0352, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    stack[-2] = v0350;
    goto v0282;

v0282:
    v0350 = stack[-2];
    goto v0040;

v0368:
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    fn = elt(env, 28); // arrayp
    v0350 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    if (v0350 == nil) goto v0055;
    v0350 = stack[-2];
    fn = elt(env, 29); // getelv
    v0351 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    v0350 = stack[-1];
    v0350 = CC_reval1(env, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0366:
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    v0350 = qcdr(v0350);
    v0350 = qcar(v0350);
    if (v0350 == nil) goto v0303;
    v0350 = qvalue(elt(env, 10)); // !*resimp
    if (!(v0350 == nil)) goto v0303;
    v0350 = stack[-1];
    if (v0350 == nil) goto v0232;
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    v0350 = qcar(v0350);
    fn = elt(env, 30); // prepsqxx
    v0350 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0232:
    v0350 = stack[-2];
    goto v0040;

v0303:
    v0351 = stack[-2];
    v0350 = stack[-1];
    fn = elt(env, 21); // reval2
    v0350 = (*qfn2(fn))(qenv(fn), v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0203:
    v0350 = qvalue(elt(env, 5)); // subfg!*
    if (v0350 == nil) goto v0058;
    v0350 = stack[-2];
    if (!(symbolp(v0350))) goto v0055;
    v0350 = stack[-2];
    if (!symbolp(v0350)) v0350 = nil;
    else { v0350 = qfastgets(v0350);
           if (v0350 != nil) { v0350 = elt(v0350, 4); // avalue
#ifdef RECORD_GET
             if (v0350 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0350 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0350 == SPID_NOPROP) v0350 = nil; }}
#endif
    stack[0] = v0350;
    if (v0350 == nil) goto v0055;
    v0351 = stack[-2];
    v0350 = qvalue(elt(env, 2)); // varstack!*
    v0350 = Lmemq(nil, v0351, v0350);
    if (v0350 == nil) goto v0064;
    v0350 = stack[-2];
    fn = elt(env, 31); // recursiveerror
    v0350 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0055;

v0064:
    v0351 = stack[-2];
    v0350 = qvalue(elt(env, 2)); // varstack!*
    v0350 = cons(v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0350; // varstack!*
    v0350 = stack[0];
    v0351 = qcar(v0350);
    v0350 = elt(env, 6); // evfn
    v0350 = get(v0351, v0350);
    env = stack[-4];
    v0352 = v0350;
    if (v0350 == nil) goto v0096;
    v0351 = stack[-2];
    v0350 = stack[-1];
    v0350 = Lapply2(nil, 3, v0352, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0096:
    v0350 = stack[0];
    v0350 = qcdr(v0350);
    v0351 = qcar(v0350);
    v0350 = stack[-1];
    v0350 = CC_reval1(env, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0353;
    env = stack[-4];
    goto v0040;

v0058:
    v0350 = stack[-2];
    goto v0040;

v0054:
    v0350 = qvalue(elt(env, 3)); // nil
    goto v0040;
// error exit handlers
v0353:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; // varstack!*
    popv(5);
    return nil;
}



setup_type const u07_setup[] =
{
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {":plus",                   too_few_2,      CC_Tplus,      wrong_no_2},
    {"optype",                  CC_optype,      too_many_1,    wrong_no_1},
    {"setcloc*",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_setclocH},
    {"getrtype2",               CC_getrtype2,   too_many_1,    wrong_no_1},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"general-modular-minus",   CC_generalKmodularKminus,too_many_1,wrong_no_1},
    {"get_first_kernel",        too_few_2,      CC_get_first_kernel,wrong_no_2},
    {"convertmode",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode},
    {"lto_insert",              too_few_2,      CC_lto_insert, wrong_no_2},
    {"sfto_davp",               too_few_2,      CC_sfto_davp,  wrong_no_2},
    {"qqe_id-nyt-branchb",      CC_qqe_idKnytKbranchb,too_many_1,wrong_no_1},
    {"rationalizei",            CC_rationalizei,too_many_1,    wrong_no_1},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"nextarg",                 CC_nextarg,     too_many_1,    wrong_no_1},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"abs:",                    CC_absT,        too_many_1,    wrong_no_1},
    {"list2widestring",         CC_list2widestring,too_many_1, wrong_no_1},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"yyreadch",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_yyreadch},
    {"mcharg",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg},
    {"ibalp_commonlenisone",    too_few_2,      CC_ibalp_commonlenisone,wrong_no_2},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"bound",                   CC_bound,       too_many_1,    wrong_no_1},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"red-weight1",             too_few_2,      CC_redKweight1,wrong_no_2},
    {"dp_times_bc",             too_few_2,      CC_dp_times_bc,wrong_no_2},
    {"dv_skelhead",             CC_dv_skelhead, too_many_1,    wrong_no_1},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"totallessp",              too_few_2,      CC_totallessp, wrong_no_2},
    {"powers1",                 CC_powers1,     too_many_1,    wrong_no_1},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"variables",               CC_variables,   too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"eofcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eofcheck},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"canonsq",                 CC_canonsq,     too_many_1,    wrong_no_1},
    {"get_action_without_lookahead",CC_get_action_without_lookahead,too_many_1,wrong_no_1},
    {"ibalp_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_mk2},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {NULL, (one_args *)"u07", (two_args *)"20697 8424112 8178951", 0}
};

// end of generated code
