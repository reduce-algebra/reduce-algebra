
// $destdir/u28.c        Machine generated C code

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



// Code for bc_prod

static LispObject CC_bc_prod(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0023, v0024, v0025, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_prod");
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
    v0026 = v0001;
    v0025 = v0000;
// end of prologue
    v0023 = v0025;
    v0024 = qcdr(v0023);
    v0023 = (LispObject)17; // 1
    if (v0024 == v0023) goto v0027;
    v0023 = qvalue(elt(env, 1)); // nil
    goto v0028;

v0028:
    if (v0023 == nil) goto v0029;
    v0023 = v0025;
    v0024 = qcar(v0023);
    v0023 = (LispObject)17; // 1
    if (v0024 == v0023) { popv(1); return onevalue(v0026); }
    v0023 = v0026;
    v0024 = qcar(v0023);
    v0023 = (LispObject)17; // 1
    if (v0024 == v0023) { popv(1); return onevalue(v0025); }
    v0023 = v0025;
    v0023 = qcar(v0023);
    v0024 = v0026;
    v0024 = qcar(v0024);
    v0024 = times2(v0023, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[0];
    v0025 = v0024;
    v0023 = (LispObject)1; // 0
    if (v0024 == v0023) goto v0031;
    v0024 = v0025;
    v0023 = (LispObject)17; // 1
    popv(1);
    return cons(v0024, v0023);

v0031:
    v0024 = qvalue(elt(env, 1)); // nil
    v0023 = (LispObject)17; // 1
    popv(1);
    return cons(v0024, v0023);

v0029:
    v0023 = v0025;
    v0024 = v0026;
    {
        popv(1);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0023, v0024);
    }

v0027:
    v0023 = v0025;
    v0023 = qcar(v0023);
    if (is_number(v0023)) goto v0032;
    v0023 = qvalue(elt(env, 1)); // nil
    goto v0028;

v0032:
    v0023 = v0026;
    v0024 = qcdr(v0023);
    v0023 = (LispObject)17; // 1
    if (v0024 == v0023) goto v0033;
    v0023 = qvalue(elt(env, 1)); // nil
    goto v0028;

v0033:
    v0023 = v0026;
    v0023 = qcar(v0023);
    v0023 = (is_number(v0023) ? lisp_true : nil);
    goto v0028;
// error exit handlers
v0030:
    popv(1);
    return nil;
}



// Code for cnrd

static LispObject CC_cnrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0068, v0069, v0070;
    LispObject fn;
    argcheck(nargs, 0, "cnrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cnrd");
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
    v0069 = qvalue(elt(env, 2)); // atts
    v0068 = elt(env, 3); // type
    fn = elt(env, 16); // find
    v0068 = (*qfn2(fn))(qenv(fn), v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0068 = Lintern(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    stack[-1] = v0068;
    v0069 = qvalue(elt(env, 2)); // atts
    v0068 = elt(env, 4); // base
    fn = elt(env, 16); // find
    v0068 = (*qfn2(fn))(qenv(fn), v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    stack[0] = v0068;
    fn = elt(env, 17); // lex
    v0068 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0068 = qvalue(elt(env, 5)); // char
    stack[-4] = v0068;
    fn = elt(env, 17); // lex
    v0068 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0069 = stack[-1];
    v0068 = elt(env, 6); // constant
    if (v0069 == v0068) goto v0072;
    v0068 = stack[-1];
    if (v0068 == nil) goto v0073;
    v0069 = stack[-1];
    v0068 = elt(env, 7); // (real integer)
    v0068 = Lmember(nil, v0069, v0068);
    if (v0068 == nil) goto v0074;
    v0068 = stack[0];
    if (v0068 == nil) goto v0075;
    stack[-3] = elt(env, 8); // based_integer
    stack[-2] = qvalue(elt(env, 1)); // nil
    stack[-1] = stack[0];
    stack[0] = elt(env, 9); // string
    v0068 = stack[-4];
    fn = elt(env, 18); // compress!*
    v0069 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0068 = qvalue(elt(env, 1)); // nil
    v0069 = list2star(stack[0], v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0068 = qvalue(elt(env, 1)); // nil
    v0068 = list2star(stack[-1], v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    {
        LispObject v0076 = stack[-3];
        LispObject v0077 = stack[-2];
        popv(6);
        return list2star(v0076, v0077, v0068);
    }

v0075:
    v0068 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); // compress!*
        return (*qfn1(fn))(qenv(fn), v0068);
    }

v0074:
    v0068 = stack[-1];
    v0069 = Lintern(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0068 = elt(env, 10); // (rational complex!-cartesian complex!-polar)
    v0068 = Lmember(nil, v0069, v0068);
    if (v0068 == nil) goto v0078;
    fn = elt(env, 19); // seprd
    v0068 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    stack[-2] = v0068;
    v0069 = stack[-1];
    v0068 = elt(env, 11); // rational
    if (v0069 == v0068) goto v0003;
    v0069 = stack[-1];
    v0068 = elt(env, 12); // complex!-cartesian
    if (v0069 == v0068) goto v0079;
    v0069 = stack[-1];
    v0068 = elt(env, 14); // complex!-polar
    if (!(v0069 == v0068)) goto v0078;
    fn = elt(env, 17); // lex
    v0068 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    stack[-1] = elt(env, 15); // complex_polar
    stack[0] = qvalue(elt(env, 1)); // nil
    v0068 = stack[-4];
    fn = elt(env, 18); // compress!*
    v0070 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0069 = stack[-2];
    v0068 = qvalue(elt(env, 1)); // nil
    v0068 = list2star(v0070, v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    {
        LispObject v0080 = stack[-1];
        LispObject v0081 = stack[0];
        popv(6);
        return list2star(v0080, v0081, v0068);
    }

v0078:
    v0068 = nil;
    { popv(6); return onevalue(v0068); }

v0079:
    fn = elt(env, 17); // lex
    v0068 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    stack[-1] = elt(env, 13); // complex_cartesian
    stack[0] = qvalue(elt(env, 1)); // nil
    v0068 = stack[-4];
    fn = elt(env, 18); // compress!*
    v0070 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0069 = stack[-2];
    v0068 = qvalue(elt(env, 1)); // nil
    v0068 = list2star(v0070, v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    {
        LispObject v0082 = stack[-1];
        LispObject v0083 = stack[0];
        popv(6);
        return list2star(v0082, v0083, v0068);
    }

v0003:
    fn = elt(env, 17); // lex
    v0068 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0068 = stack[-4];
    fn = elt(env, 18); // compress!*
    v0069 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-5];
    v0068 = stack[-2];
    {
        popv(6);
        fn = elt(env, 11); // rational
        return (*qfn2(fn))(qenv(fn), v0069, v0068);
    }

v0073:
    v0068 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); // compress!*
        return (*qfn1(fn))(qenv(fn), v0068);
    }

v0072:
    v0068 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); // compress!*
        return (*qfn1(fn))(qenv(fn), v0068);
    }
// error exit handlers
v0071:
    popv(6);
    return nil;
}



// Code for ps!:expression

static LispObject CC_psTexpression(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0088, v0073, v0089;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:expression");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0089 = v0000;
// end of prologue
    v0088 = v0089;
    if (!consp(v0088)) goto v0028;
    v0088 = v0089;
    v0073 = qcar(v0088);
    v0088 = elt(env, 2); // !:ps!:
    if (v0073 == v0088) goto v0090;
    v0088 = v0089;
    v0088 = qcar(v0088);
    if (!symbolp(v0088)) v0088 = nil;
    else { v0088 = qfastgets(v0088);
           if (v0088 != nil) { v0088 = elt(v0088, 8); // dname
#ifdef RECORD_GET
             if (v0088 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0088 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0088 == SPID_NOPROP) v0088 = nil; }}
#endif
    goto v0016;

v0016:
    if (!(v0088 == nil)) return onevalue(v0089);
    v0073 = v0089;
    v0088 = (LispObject)97; // 6
    {
        fn = elt(env, 4); // ps!:getv
        return (*qfn2(fn))(qenv(fn), v0073, v0088);
    }

v0090:
    v0088 = qvalue(elt(env, 3)); // nil
    goto v0016;

v0028:
    v0088 = qvalue(elt(env, 1)); // t
    goto v0016;
}



// Code for bcfd

static LispObject CC_bcfd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0089, v0092, v0093;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcfd");
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
    v0093 = v0000;
// end of prologue
    v0089 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0089 == nil) goto v0028;
    v0089 = v0093;
    v0089 = integerp(v0089);
    if (v0089 == nil) goto v0094;
    v0089 = v0093;
    {
        popv(1);
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(qenv(fn), v0089);
    }

v0094:
    v0089 = v0093;
    v0092 = qcar(v0089);
    v0089 = elt(env, 2); // !:mod!:
    if (v0092 == v0089) goto v0095;
    v0089 = elt(env, 3); // "Invalid modular coefficient"
    v0092 = v0093;
    v0089 = list2(v0089, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); // rederr
        return (*qfn1(fn))(qenv(fn), v0089);
    }

v0095:
    v0089 = v0093;
    v0089 = qcdr(v0089);
    {
        popv(1);
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(qenv(fn), v0089);
    }

v0028:
    v0092 = v0093;
    v0089 = (LispObject)17; // 1
    {
        popv(1);
        fn = elt(env, 6); // mkbc
        return (*qfn2(fn))(qenv(fn), v0092, v0089);
    }
// error exit handlers
v0096:
    popv(1);
    return nil;
}



// Code for critical_element

static LispObject CC_critical_element(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0099, v0091;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for critical_element");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0099 = v0000;
// end of prologue
    v0091 = v0099;
    v0091 = qcdr(v0091);
    v0091 = qcar(v0091);
        return Lapply1(nil, v0091, v0099);
}



// Code for prop!-simp

static LispObject CC_propKsimp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0101, v0102, v0103, v0094, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prop-simp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0101 = v0001;
    v0102 = v0000;
// end of prologue
    v0065 = v0102;
    v0094 = v0101;
    v0103 = qvalue(elt(env, 1)); // nil
    v0102 = (LispObject)1; // 0
    v0101 = (LispObject)17; // 1
    {
        fn = elt(env, 2); // prop!-simp1
        return (*qfnn(fn))(qenv(fn), 5, v0065, v0094, v0103, v0102, v0101);
    }
}



// Code for assert_declarestat1

static LispObject CC_assert_declarestat1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0152, v0153, v0154, v0155;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_declarestat1");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[-4] = v0000;
// end of prologue
    stack[-10] = nil;
    v0152 = (LispObject)1; // 0
    stack[-7] = v0152;
    v0152 = stack[-4];
    v0152 = qcar(v0152);
    v0152 = Lexplode(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[0] = v0152;
    v0152 = elt(env, 1); // assert!:
    v0153 = Lexplode(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[0];
    v0152 = Lnconc(nil, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = Lcompress(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = Lintern(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-9] = v0152;
    v0152 = elt(env, 2); // noassert!:
    v0153 = Lexplode(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[0];
    v0152 = Lnconc(nil, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = Lcompress(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = Lintern(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-5] = v0152;
    v0152 = stack[-4];
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    stack[-6] = v0152;
    v0152 = stack[-6];
    if (v0152 == nil) goto v0157;
    stack[0] = elt(env, 4); // a
    v0152 = stack[-7];
    v0152 = add1(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-7] = v0152;
    fn = elt(env, 19); // mkid
    v0152 = (*qfn2(fn))(qenv(fn), stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-2] = v0152;
    stack[-3] = v0152;
    goto v0093;

v0093:
    v0152 = stack[-6];
    v0152 = qcdr(v0152);
    stack[-6] = v0152;
    v0152 = stack[-6];
    if (v0152 == nil) goto v0158;
    stack[-1] = stack[-2];
    stack[0] = elt(env, 4); // a
    v0152 = stack[-7];
    v0152 = add1(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-7] = v0152;
    fn = elt(env, 19); // mkid
    v0152 = (*qfn2(fn))(qenv(fn), stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = Lrplacd(nil, stack[-1], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[-2];
    v0152 = qcdr(v0152);
    stack[-2] = v0152;
    goto v0093;

v0158:
    v0152 = stack[-3];
    goto v0092;

v0092:
    stack[-3] = v0152;
    v0152 = stack[-4];
    v0152 = qcar(v0152);
    v0152 = Lmkquote(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-8] = v0152;
    v0152 = stack[-5];
    v0152 = Lmkquote(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-7] = v0152;
    v0153 = elt(env, 5); // list
    v0152 = stack[-3];
    v0152 = cons(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-6] = v0152;
    stack[-11] = elt(env, 5); // list
    v0152 = stack[-4];
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    stack[-5] = v0152;
    v0152 = stack[-5];
    if (v0152 == nil) goto v0159;
    v0152 = stack[-5];
    v0152 = qcar(v0152);
    v0152 = Lmkquote(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-1] = v0152;
    stack[-2] = v0152;
    goto v0054;

v0054:
    v0152 = stack[-5];
    v0152 = qcdr(v0152);
    stack[-5] = v0152;
    v0152 = stack[-5];
    if (v0152 == nil) goto v0051;
    stack[0] = stack[-1];
    v0152 = stack[-5];
    v0152 = qcar(v0152);
    v0152 = Lmkquote(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = Lrplacd(nil, stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    stack[-1] = v0152;
    goto v0054;

v0051:
    v0152 = stack[-2];
    goto v0002;

v0002:
    v0152 = cons(stack[-11], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-11] = v0152;
    v0152 = stack[-4];
    v0152 = qcdr(v0152);
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    v0152 = Lmkquote(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-5] = elt(env, 6); // de
    stack[-4] = stack[-9];
    stack[-2] = elt(env, 7); // assert_check1
    stack[-1] = stack[-8];
    stack[0] = stack[-7];
    v0154 = stack[-6];
    v0153 = stack[-11];
    v0152 = list3(v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = list3star(stack[-2], stack[-1], stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0153 = list4(stack[-5], stack[-4], stack[-3], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[-10];
    v0152 = cons(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-10] = v0152;
    stack[-2] = elt(env, 8); // put
    stack[-1] = stack[-8];
    stack[0] = elt(env, 9); // (quote assert_assertfn)
    v0152 = stack[-9];
    v0152 = Lmkquote(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0153 = list4(stack[-2], stack[-1], stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[-10];
    v0152 = cons(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-10] = v0152;
    v0155 = elt(env, 8); // put
    v0154 = stack[-8];
    v0153 = elt(env, 10); // (quote assert_noassertfn)
    v0152 = stack[-7];
    v0153 = list4(v0155, v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[-10];
    v0152 = cons(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-10] = v0152;
    v0155 = elt(env, 8); // put
    v0154 = stack[-8];
    v0153 = elt(env, 11); // (quote assert_installed)
    v0152 = qvalue(elt(env, 3)); // nil
    v0153 = list4(v0155, v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[-10];
    v0152 = cons(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-10] = v0152;
    stack[-3] = elt(env, 12); // cond
    stack[0] = elt(env, 13); // not
    v0154 = elt(env, 14); // member
    v0153 = stack[-8];
    v0152 = elt(env, 15); // assert_functionl!*
    v0152 = list3(v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-2] = list2(stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-1] = elt(env, 16); // setq
    stack[0] = elt(env, 15); // assert_functionl!*
    v0154 = elt(env, 17); // cons
    v0153 = stack[-8];
    v0152 = elt(env, 15); // assert_functionl!*
    v0152 = list3(v0154, v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = list3(stack[-1], stack[0], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = list2(stack[-2], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0153 = list2(stack[-3], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    v0152 = stack[-10];
    v0152 = cons(v0153, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-12];
    stack[-10] = v0152;
    v0153 = elt(env, 18); // progn
    v0152 = stack[-10];
    v0152 = Lnreverse(nil, v0152);
    popv(13);
    return cons(v0153, v0152);

v0159:
    v0152 = qvalue(elt(env, 3)); // nil
    goto v0002;

v0157:
    v0152 = qvalue(elt(env, 3)); // nil
    goto v0092;
// error exit handlers
v0156:
    popv(13);
    return nil;
}



// Code for sf2mv

static LispObject CC_sf2mv(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0087, v0100, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf2mv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0087 = v0001;
    v0100 = v0000;
// end of prologue
    v0067 = v0100;
    v0100 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // sf2mv1
        return (*qfnn(fn))(qenv(fn), 3, v0067, v0100, v0087);
    }
}



// Code for fs!:prepfn!:

static LispObject CC_fsTprepfnT(LispObject env,
                         LispObject v0000)
{
    LispObject v0041;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:prepfn:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0041 = v0000;
// end of prologue
    return onevalue(v0041);
}



// Code for ratminus

static LispObject CC_ratminus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0091, v0087;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratminus");
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
    stack[0] = v0000;
// end of prologue
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0087 = negate(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    popv(1);
    return cons(v0087, v0091);
// error exit handlers
v0067:
    popv(1);
    return nil;
}



// Code for setk1

static LispObject CC_setk1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0178, v0179, v0180, v0106, v0181;
    LispObject fn;
    LispObject v0040, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "setk1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setk1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-1] = v0040;
    stack[0] = v0001;
    stack[-5] = v0000;
// end of prologue
    stack[-6] = nil;
    stack[-2] = qvalue(elt(env, 1)); // !*uncached
    qvalue(elt(env, 1)) = nil; // !*uncached
    v0178 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0178; // !*uncached
    v0178 = stack[-5];
    if (!consp(v0178)) goto v0091;
    v0178 = stack[-5];
    v0178 = qcar(v0178);
    if (!consp(v0178)) goto v0060;
    v0180 = elt(env, 7); // alg
    v0179 = (LispObject)401; // 25
    v0178 = elt(env, 8); // "Invalid syntax: improper assignment"
    fn = elt(env, 12); // rerror
    v0178 = (*qfnn(fn))(qenv(fn), 3, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    goto v0060;

v0060:
    v0178 = stack[-5];
    stack[-3] = qcar(v0178);
    v0178 = stack[-5];
    v0178 = qcdr(v0178);
    fn = elt(env, 13); // revlis
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    v0178 = cons(stack[-3], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    stack[-5] = v0178;
    v0178 = stack[-1];
    if (v0178 == nil) goto v0183;
    v0178 = stack[-5];
    v0178 = qcar(v0178);
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 50); // kvalue
#ifdef RECORD_GET
             if (v0178 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0178 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; }}
#endif
    stack[-4] = v0178;
    if (v0178 == nil) goto v0135;
    v0179 = stack[-5];
    v0178 = stack[-4];
    v0178 = Lassoc(nil, v0179, v0178);
    stack[-6] = v0178;
    if (v0178 == nil) goto v0184;
    v0179 = stack[-5];
    v0178 = stack[0];
    fn = elt(env, 14); // updoldrules
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    v0178 = stack[-6];
    v0179 = qcar(v0178);
    v0178 = stack[-4];
    fn = elt(env, 15); // delasc
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    stack[-4] = v0178;
    goto v0184;

v0184:
    v0178 = stack[-5];
    v0106 = qcar(v0178);
    v0180 = stack[-4];
    v0179 = stack[-5];
    v0178 = stack[0];
    fn = elt(env, 16); // put!-kvalue
    v0178 = (*qfnn(fn))(qenv(fn), 4, v0106, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    goto v0029;

v0029:
    v0178 = stack[0];
    goto v0027;

v0027:
    qvalue(elt(env, 1)) = stack[-2]; // !*uncached
    { popv(8); return onevalue(v0178); }

v0135:
    v0178 = stack[-5];
    v0106 = qcar(v0178);
    v0180 = qvalue(elt(env, 3)); // nil
    v0179 = stack[-5];
    v0178 = stack[0];
    fn = elt(env, 16); // put!-kvalue
    v0178 = (*qfnn(fn))(qenv(fn), 4, v0106, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    goto v0029;

v0183:
    v0179 = stack[-5];
    v0178 = qvalue(elt(env, 9)); // wtl!*
    v0178 = Lassoc(nil, v0179, v0178);
    stack[-3] = v0178;
    v0178 = stack[-5];
    v0178 = qcar(v0178);
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 50); // kvalue
#ifdef RECORD_GET
             if (v0178 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0178 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; }}
#endif
    stack[-4] = v0178;
    if (v0178 == nil) goto v0185;
    v0179 = stack[-5];
    v0178 = stack[-4];
    v0178 = Lassoc(nil, v0179, v0178);
    stack[-6] = v0178;
    v0178 = (v0178 == nil ? lisp_true : nil);
    goto v0186;

v0186:
    if (v0178 == nil) goto v0187;
    v0178 = stack[-3];
    if (v0178 == nil) goto v0188;
    v0178 = qvalue(elt(env, 3)); // nil
    goto v0189;

v0189:
    if (v0178 == nil) goto v0054;
    v0181 = qvalue(elt(env, 3)); // nil
    v0106 = stack[-5];
    v0180 = elt(env, 4); // "not found"
    v0179 = qvalue(elt(env, 3)); // nil
    v0178 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 17); // msgpri
    v0178 = (*qfnn(fn))(qenv(fn), 5, v0181, v0106, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    goto v0054;

v0054:
    v0178 = stack[-3];
    if (v0178 == nil) goto v0038;
    v0179 = stack[-5];
    v0178 = qvalue(elt(env, 9)); // wtl!*
    fn = elt(env, 15); // delasc
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    qvalue(elt(env, 9)) = v0178; // wtl!*
    goto v0038;

v0038:
    v0178 = qvalue(elt(env, 3)); // nil
    goto v0027;

v0188:
    v0178 = qvalue(elt(env, 10)); // !*sqrtrulep
    v0178 = (v0178 == nil ? lisp_true : nil);
    goto v0189;

v0187:
    v0178 = stack[-5];
    stack[-1] = qcar(v0178);
    stack[0] = elt(env, 11); // kvalue
    v0179 = stack[-6];
    v0178 = stack[-4];
    v0178 = Ldelete(nil, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    v0178 = Lputprop(nil, 3, stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    goto v0054;

v0185:
    v0178 = qvalue(elt(env, 2)); // t
    goto v0186;

v0091:
    v0178 = stack[-1];
    if (v0178 == nil) goto v0022;
    v0178 = stack[-5];
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 4); // avalue
#ifdef RECORD_GET
             if (v0178 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0178 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; }}
#endif
    stack[-6] = v0178;
    if (v0178 == nil) goto v0158;
    v0180 = stack[-5];
    v0178 = stack[-6];
    v0179 = qcar(v0178);
    v0178 = stack[0];
    fn = elt(env, 18); // put!-avalue
    v0178 = (*qfnn(fn))(qenv(fn), 3, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    goto v0021;

v0021:
    v0178 = stack[0];
    goto v0027;

v0158:
    v0180 = stack[-5];
    v0179 = elt(env, 6); // scalar
    v0178 = stack[0];
    fn = elt(env, 18); // put!-avalue
    v0178 = (*qfnn(fn))(qenv(fn), 3, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    goto v0021;

v0022:
    v0178 = stack[-5];
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 4); // avalue
#ifdef RECORD_GET
             if (v0178 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0178 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; }}
#endif
    if (v0178 == nil) goto v0018;
    v0179 = stack[-5];
    v0178 = elt(env, 5); // avalue
    v0178 = Lremprop(nil, v0179, v0178);
    env = stack[-7];
    goto v0103;

v0103:
    v0178 = qvalue(elt(env, 3)); // nil
    goto v0027;

v0018:
    v0181 = qvalue(elt(env, 3)); // nil
    v0106 = stack[-5];
    v0180 = elt(env, 4); // "not found"
    v0179 = qvalue(elt(env, 3)); // nil
    v0178 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 17); // msgpri
    v0178 = (*qfnn(fn))(qenv(fn), 5, v0181, v0106, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-7];
    goto v0103;
// error exit handlers
v0182:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-2]; // !*uncached
    popv(8);
    return nil;
}



// Code for cquotegex

static LispObject CC_cquotegex(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cquotegex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0028 = v0000;
// end of prologue
    v0028 = qvalue(elt(env, 1)); // !*guardian
    if (v0028 == nil) goto v0145;
    v0028 = elt(env, 2); // gex
    return onevalue(v0028);

v0145:
    v0028 = nil;
    return onevalue(v0028);
}



// Code for simpexpt11

static LispObject CC_simpexpt11(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0197, v0054, v0055;
    LispObject fn;
    LispObject v0040, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt11");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpexpt11");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0040;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0197 = qvalue(elt(env, 1)); // !*precise_complex
    if (v0197 == nil) goto v0098;
    v0055 = stack[-3];
    v0054 = stack[-2];
    v0197 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); // simpexpt2
        return (*qfnn(fn))(qenv(fn), 3, v0055, v0054, v0197);
    }

v0098:
    v0197 = stack[-2];
    v0197 = qcdr(v0197);
    if (!consp(v0197)) goto v0072;
    v0197 = stack[-2];
    v0197 = qcdr(v0197);
    v0197 = qcar(v0197);
    v0197 = (consp(v0197) ? nil : lisp_true);
    goto v0033;

v0033:
    if (v0197 == nil) goto v0198;
    v0197 = qvalue(elt(env, 2)); // t
    goto v0199;

v0199:
    if (v0197 == nil) goto v0200;
    v0055 = stack[-3];
    v0054 = stack[-2];
    v0197 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); // simpexpt2
        return (*qfnn(fn))(qenv(fn), 3, v0055, v0054, v0197);
    }

v0200:
    stack[0] = stack[-3];
    v0197 = stack[-4];
    v0054 = qcar(v0197);
    v0197 = (LispObject)17; // 1
    v0054 = cons(v0054, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    v0197 = stack[-1];
    fn = elt(env, 5); // simpexpt1
    stack[0] = (*qfnn(fn))(qenv(fn), 3, stack[0], v0054, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    v0197 = stack[-4];
    v0054 = qcdr(v0197);
    v0197 = stack[-2];
    v0197 = qcdr(v0197);
    v0054 = cons(v0054, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    v0197 = stack[-1];
    fn = elt(env, 5); // simpexpt1
    v0197 = (*qfnn(fn))(qenv(fn), 3, stack[-3], v0054, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    {
        LispObject v0202 = stack[0];
        popv(6);
        fn = elt(env, 6); // multsq
        return (*qfn2(fn))(qenv(fn), v0202, v0197);
    }

v0198:
    v0197 = stack[-2];
    v0054 = qcar(v0197);
    v0197 = stack[-2];
    v0197 = qcdr(v0197);
    fn = elt(env, 7); // qremf
    v0197 = (*qfn2(fn))(qenv(fn), v0054, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-5];
    stack[-4] = v0197;
    v0197 = qcar(v0197);
    if (v0197 == nil) goto v0093;
    v0197 = stack[-4];
    v0197 = qcdr(v0197);
    goto v0092;

v0092:
    v0197 = (v0197 == nil ? lisp_true : nil);
    goto v0199;

v0093:
    v0197 = qvalue(elt(env, 3)); // nil
    goto v0092;

v0072:
    v0197 = qvalue(elt(env, 2)); // t
    goto v0033;
// error exit handlers
v0201:
    popv(6);
    return nil;
}



// Code for rndifference!:

static LispObject CC_rndifferenceT(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0205, v0177;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rndifference:");
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
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    v0177 = qcar(v0205);
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    v0205 = qcdr(v0205);
    stack[-2] = times2(v0177, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    v0177 = qcdr(v0205);
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    v0205 = qcar(v0205);
    v0205 = times2(v0177, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[-2] = difference2(stack[-2], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    v0177 = qcdr(v0205);
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    v0205 = qcdr(v0205);
    v0205 = times2(v0177, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    {
        LispObject v0206 = stack[-2];
        popv(4);
        fn = elt(env, 1); // mkrn
        return (*qfn2(fn))(qenv(fn), v0206, v0205);
    }
// error exit handlers
v0196:
    popv(4);
    return nil;
}



// Code for mk!+trace

static LispObject CC_mkLtrace(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0150, v0151, v0176;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+trace");
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
    v0150 = stack[-1];
    fn = elt(env, 5); // squared!+matrix!+p
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    if (!(v0150 == nil)) goto v0100;
    v0150 = elt(env, 1); // "no square matrix in add"
    fn = elt(env, 6); // rederr
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    goto v0100;

v0100:
    v0151 = qvalue(elt(env, 2)); // nil
    v0150 = (LispObject)17; // 1
    v0150 = cons(v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    stack[0] = v0150;
    v0150 = (LispObject)17; // 1
    stack[-2] = v0150;
    goto v0209;

v0209:
    v0150 = stack[-1];
    fn = elt(env, 7); // get!+row!+nr
    v0151 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    v0150 = stack[-2];
    v0150 = difference2(v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    v0150 = Lminusp(nil, v0150);
    env = stack[-3];
    if (v0150 == nil) goto v0198;
    v0150 = qvalue(elt(env, 3)); // t
    stack[-1] = qvalue(elt(env, 4)); // !*sub2
    qvalue(elt(env, 4)) = v0150; // !*sub2
    v0150 = stack[0];
    fn = elt(env, 8); // subs2
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    stack[0] = v0150;
    qvalue(elt(env, 4)) = stack[-1]; // !*sub2
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0198:
    v0176 = stack[-1];
    v0151 = stack[-2];
    v0150 = stack[-2];
    fn = elt(env, 9); // get!+mat!+entry
    v0150 = (*qfnn(fn))(qenv(fn), 3, v0176, v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    fn = elt(env, 10); // addsq
    v0150 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    stack[0] = v0150;
    v0150 = stack[-2];
    v0150 = add1(v0150);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-3];
    stack[-2] = v0150;
    goto v0209;
// error exit handlers
v0158:
    env = stack[-3];
    qvalue(elt(env, 4)) = stack[-1]; // !*sub2
    popv(4);
    return nil;
v0208:
    popv(4);
    return nil;
}



// Code for aex_bvarl

static LispObject CC_aex_bvarl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0145;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_bvarl");
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
    v0145 = v0000;
// end of prologue
    fn = elt(env, 1); // aex_ctx
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // ctx_idl
        return (*qfn1(fn))(qenv(fn), v0145);
    }
// error exit handlers
v0086:
    popv(1);
    return nil;
}



// Code for opfneval

static LispObject CC_opfneval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0223, v0224;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opfneval");
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
    stack[-2] = v0000;
// end of prologue
    v0223 = stack[-2];
    v0223 = qcar(v0223);
    if (!symbolp(v0223)) v0223 = nil;
    else { v0223 = qfastgets(v0223);
           if (v0223 != nil) { v0223 = elt(v0223, 39); // remember
#ifdef RECORD_GET
             if (v0223 == SPID_NOPROP)
                record_get(elt(fastget_names, 39), 0),
                v0223 = nil;
             else record_get(elt(fastget_names, 39), 1),
                v0223 = lisp_true; }
           else record_get(elt(fastget_names, 39), 0); }
#else
             if (v0223 == SPID_NOPROP) v0223 = nil; else v0223 = lisp_true; }}
#endif
    if (v0223 == nil) goto v0225;
    v0223 = stack[-2];
    v0224 = qcar(v0223);
    v0223 = elt(env, 1); // noval
    v0223 = Lflagp(nil, v0224, v0223);
    env = stack[-5];
    if (v0223 == nil) goto v0204;
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    goto v0102;

v0102:
    stack[-4] = v0223;
    v0223 = stack[-4];
    if (v0223 == nil) goto v0085;
    v0223 = stack[-4];
    v0223 = qcar(v0223);
    v0224 = v0223;
    v0223 = v0224;
    v0223 = integerp(v0223);
    if (v0223 == nil) goto v0206;
    v0223 = v0224;
    goto v0205;

v0205:
    v0223 = ncons(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    stack[-1] = v0223;
    stack[-3] = v0223;
    goto v0017;

v0017:
    v0223 = stack[-4];
    v0223 = qcdr(v0223);
    stack[-4] = v0223;
    v0223 = stack[-4];
    if (v0223 == nil) goto v0227;
    stack[0] = stack[-1];
    v0223 = stack[-4];
    v0223 = qcar(v0223);
    v0224 = v0223;
    v0223 = v0224;
    v0223 = integerp(v0223);
    if (v0223 == nil) goto v0010;
    v0223 = v0224;
    goto v0175;

v0175:
    v0223 = ncons(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0223 = Lrplacd(nil, stack[0], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0223 = stack[-1];
    v0223 = qcdr(v0223);
    stack[-1] = v0223;
    goto v0017;

v0010:
    v0223 = v0224;
    v0223 = Lmkquote(nil, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    goto v0175;

v0227:
    v0223 = stack[-3];
    goto v0022;

v0022:
    stack[-4] = v0223;
    v0223 = stack[-2];
    v0224 = qcar(v0223);
    v0223 = stack[-4];
    v0224 = cons(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0223 = stack[-2];
    v0223 = qcar(v0223);
    if (!symbolp(v0223)) v0223 = nil;
    else { v0223 = qfastgets(v0223);
           if (v0223 != nil) { v0223 = elt(v0223, 50); // kvalue
#ifdef RECORD_GET
             if (v0223 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0223 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0223 == SPID_NOPROP) v0223 = nil; }}
#endif
    v0223 = Lassoc(nil, v0224, v0223);
    v0224 = v0223;
    if (v0223 == nil) goto v0024;
    v0223 = v0224;
    v0223 = qcdr(v0223);
    v0223 = qcar(v0223);
    { popv(6); return onevalue(v0223); }

v0024:
    v0223 = stack[-2];
    v0224 = qcar(v0223);
    v0223 = stack[-4];
    v0223 = cons(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    fn = elt(env, 3); // lispeval
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    stack[-3] = v0223;
    v0223 = stack[-2];
    stack[-1] = qcar(v0223);
    v0223 = stack[-2];
    v0223 = qcar(v0223);
    if (!symbolp(v0223)) stack[0] = nil;
    else { stack[0] = qfastgets(v0223);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 50); // kvalue
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    v0223 = stack[-2];
    v0224 = qcar(v0223);
    v0223 = stack[-4];
    v0224 = cons(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0223 = stack[-3];
    fn = elt(env, 4); // put!-kvalue
    v0223 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    { LispObject res = stack[-3]; popv(6); return onevalue(res); }

v0206:
    v0223 = v0224;
    v0223 = Lmkquote(nil, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    goto v0205;

v0085:
    v0223 = qvalue(elt(env, 2)); // nil
    goto v0022;

v0204:
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    fn = elt(env, 5); // revlis
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    goto v0102;

v0225:
    v0223 = stack[-2];
    stack[-4] = qcar(v0223);
    v0223 = stack[-2];
    v0224 = qcar(v0223);
    v0223 = elt(env, 1); // noval
    v0223 = Lflagp(nil, v0224, v0223);
    env = stack[-5];
    if (v0223 == nil) goto v0142;
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    goto v0228;

v0228:
    stack[-3] = v0223;
    v0223 = stack[-3];
    if (v0223 == nil) goto v0229;
    v0223 = stack[-3];
    v0223 = qcar(v0223);
    v0223 = Lmkquote(nil, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0223 = ncons(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    stack[-1] = v0223;
    stack[-2] = v0223;
    goto v0230;

v0230:
    v0223 = stack[-3];
    v0223 = qcdr(v0223);
    stack[-3] = v0223;
    v0223 = stack[-3];
    if (v0223 == nil) goto v0231;
    stack[0] = stack[-1];
    v0223 = stack[-3];
    v0223 = qcar(v0223);
    v0223 = Lmkquote(nil, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0223 = ncons(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0223 = Lrplacd(nil, stack[0], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0223 = stack[-1];
    v0223 = qcdr(v0223);
    stack[-1] = v0223;
    goto v0230;

v0231:
    v0223 = stack[-2];
    goto v0232;

v0232:
    v0223 = cons(stack[-4], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 3); // lispeval
        return (*qfn1(fn))(qenv(fn), v0223);
    }

v0229:
    v0223 = qvalue(elt(env, 2)); // nil
    goto v0232;

v0142:
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    fn = elt(env, 5); // revlis
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    goto v0228;
// error exit handlers
v0226:
    popv(6);
    return nil;
}



// Code for doublep

static LispObject CC_doublep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0102, v0103;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for doublep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0103 = v0000;
// end of prologue
    v0102 = v0103;
    v0101 = elt(env, 1); // !:rd!:
    if (!consp(v0102)) goto v0021;
    v0102 = qcar(v0102);
    if (!(v0102 == v0101)) goto v0021;
    v0101 = v0103;
    v0101 = qcdr(v0101);
        return Lconsp(nil, v0101);

v0021:
    v0101 = qvalue(elt(env, 2)); // nil
    return onevalue(v0101);
}



// Code for sc_geq

static LispObject CC_sc_geq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0091, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_geq");
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
    v0091 = v0001;
    v0087 = v0000;
// end of prologue
    fn = elt(env, 1); // sc_subtrsq
    v0091 = (*qfn2(fn))(qenv(fn), v0087, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[0];
    fn = elt(env, 2); // sc_minussq
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0091 = (v0091 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0091); }
// error exit handlers
v0100:
    popv(1);
    return nil;
}



// Code for evrevgradlexcomp

static LispObject CC_evrevgradlexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0208, v0158;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evrevgradlexcomp");
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

v0145:
    v0208 = stack[-2];
    if (v0208 == nil) goto v0028;
    v0208 = stack[-1];
    if (v0208 == nil) goto v0099;
    v0208 = stack[-2];
    v0158 = qcar(v0208);
    v0208 = stack[-1];
    v0208 = qcar(v0208);
    fn = elt(env, 2); // iequal
    v0208 = (*qfn2(fn))(qenv(fn), v0158, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    if (v0208 == nil) goto v0032;
    v0208 = stack[-2];
    v0208 = qcdr(v0208);
    stack[-2] = v0208;
    v0208 = stack[-1];
    v0208 = qcdr(v0208);
    stack[-1] = v0208;
    goto v0145;

v0032:
    v0208 = stack[-2];
    fn = elt(env, 3); // evtdeg
    stack[0] = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    v0208 = stack[-1];
    fn = elt(env, 3); // evtdeg
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0208;
    v0158 = stack[-3];
    v0208 = stack[0];
    fn = elt(env, 2); // iequal
    v0208 = (*qfn2(fn))(qenv(fn), v0158, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    if (v0208 == nil) goto v0233;
    v0158 = stack[-2];
    v0208 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); // evinvlexcomp
        return (*qfn2(fn))(qenv(fn), v0158, v0208);
    }

v0233:
    v0158 = stack[-3];
    v0208 = stack[0];
    if (((int32_t)(v0158)) > ((int32_t)(v0208))) goto v0015;
    v0208 = (LispObject)-15; // -1
    { popv(5); return onevalue(v0208); }

v0015:
    v0208 = (LispObject)17; // 1
    { popv(5); return onevalue(v0208); }

v0099:
    v0208 = elt(env, 1); // (0)
    stack[-1] = v0208;
    goto v0145;

v0028:
    v0208 = (LispObject)1; // 0
    { popv(5); return onevalue(v0208); }
// error exit handlers
v0058:
    popv(5);
    return nil;
}



// Code for physop!-multfnc

static LispObject CC_physopKmultfnc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0257, v0258, v0259;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physop-multfnc");
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
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    stack[0] = qcdr(v0257);
    v0257 = stack[-1];
    v0257 = qcar(v0257);
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    fn = elt(env, 5); // physop!-multf
    v0257 = (*qfn2(fn))(qenv(fn), stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-3] = v0257;
    v0257 = stack[-3];
    if (v0257 == nil) goto v0261;
    v0257 = stack[-3];
    if (!consp(v0257)) goto v0209;
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = (consp(v0257) ? nil : lisp_true);
    goto v0032;

v0032:
    if (v0257 == nil) goto v0092;
    v0257 = qvalue(elt(env, 1)); // nil
    goto v0018;

v0018:
    if (v0257 == nil) goto v0199;
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    stack[0] = qcar(v0257);
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0258 = qcdr(v0257);
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    v0257 = plus2(v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    fn = elt(env, 6); // mkspm
    v0257 = (*qfn2(fn))(qenv(fn), stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0259 = v0257;
    if (v0257 == nil) goto v0200;
    v0258 = v0259;
    v0257 = (LispObject)17; // 1
    if (v0258 == v0257) goto v0057;
    v0258 = v0259;
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    v0257 = cons(v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[0] = v0257;
    goto v0262;

v0262:
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = (LispObject)17; // 1
    v0257 = cons(v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0258 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = stack[-3];
    v0257 = qcdr(v0257);
    fn = elt(env, 5); // physop!-multf
    v0257 = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    fn = elt(env, 7); // addf
    v0257 = (*qfn2(fn))(qenv(fn), stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-3] = v0257;
    goto v0261;

v0261:
    v0257 = stack[-2];
    v0258 = qcdr(v0257);
    v0257 = stack[-1];
    fn = elt(env, 5); // physop!-multf
    stack[0] = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0258 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = stack[-1];
    v0257 = qcdr(v0257);
    fn = elt(env, 5); // physop!-multf
    v0257 = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    fn = elt(env, 7); // addf
    v0257 = (*qfn2(fn))(qenv(fn), stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    {
        LispObject v0263 = stack[-3];
        popv(5);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0263, v0257);
    }

v0057:
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    stack[0] = v0257;
    goto v0262;

v0200:
    v0257 = qvalue(elt(env, 1)); // nil
    stack[0] = v0257;
    goto v0262;

v0199:
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    if (!consp(v0257)) goto v0232;
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    if (!symbolp(v0257)) v0257 = nil;
    else { v0257 = qfastgets(v0257);
           if (v0257 != nil) { v0257 = elt(v0257, 0); // noncom
#ifdef RECORD_GET
             if (v0257 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0257 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0257 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0257 == SPID_NOPROP) v0257 = nil; else v0257 = lisp_true; }}
#endif
    goto v0264;

v0264:
    if (v0257 == nil) goto v0111;
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    fn = elt(env, 8); // noncommuting
    v0257 = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    if (v0257 == nil) goto v0070;
    v0257 = qvalue(elt(env, 1)); // nil
    goto v0143;

v0143:
    if (v0257 == nil) goto v0265;
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = (LispObject)17; // 1
    v0257 = cons(v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0258 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcdr(v0257);
    fn = elt(env, 5); // physop!-multf
    v0257 = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0259 = v0257;
    if (v0257 == nil) goto v0133;
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0258 = v0259;
    v0257 = cons(v0257, v0258);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[0] = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = (LispObject)17; // 1
    v0257 = cons(v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0258 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = stack[-3];
    v0257 = qcdr(v0257);
    fn = elt(env, 5); // physop!-multf
    v0257 = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    fn = elt(env, 7); // addf
    v0257 = (*qfn2(fn))(qenv(fn), stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-3] = v0257;
    goto v0261;

v0133:
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = (LispObject)17; // 1
    v0257 = cons(v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0258 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = stack[-3];
    v0257 = qcdr(v0257);
    fn = elt(env, 5); // physop!-multf
    v0257 = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-3] = v0257;
    goto v0261;

v0265:
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = stack[-3];
    v0257 = cons(v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-3] = v0257;
    goto v0261;

v0070:
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    fn = elt(env, 9); // physop!-ordop
    v0257 = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0257 = (v0257 == nil ? lisp_true : nil);
    goto v0143;

v0111:
    v0257 = qvalue(elt(env, 2)); // t
    stack[0] = qvalue(elt(env, 4)); // !*!*processed
    qvalue(elt(env, 4)) = v0257; // !*!*processed
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = (LispObject)17; // 1
    v0257 = cons(v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    v0258 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    v0257 = stack[-3];
    fn = elt(env, 5); // physop!-multf
    v0257 = (*qfn2(fn))(qenv(fn), v0258, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-4];
    stack[-3] = v0257;
    qvalue(elt(env, 4)) = stack[0]; // !*!*processed
    goto v0261;

v0232:
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    if (!symbolp(v0257)) v0257 = nil;
    else { v0257 = qfastgets(v0257);
           if (v0257 != nil) { v0257 = elt(v0257, 0); // noncom
#ifdef RECORD_GET
             if (v0257 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0257 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0257 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0257 == SPID_NOPROP) v0257 = nil; else v0257 = lisp_true; }}
#endif
    goto v0264;

v0092:
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0258 = qcar(v0257);
    v0257 = stack[-2];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    if (v0258 == v0257) goto v0073;
    v0257 = qvalue(elt(env, 1)); // nil
    goto v0018;

v0073:
    v0257 = stack[-3];
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    v0257 = qcar(v0257);
    fn = elt(env, 10); // physopp
    v0257 = (*qfn1(fn))(qenv(fn), v0257);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    if (v0257 == nil) goto v0267;
    v0257 = qvalue(elt(env, 3)); // !*contract2
    goto v0018;

v0267:
    v0257 = qvalue(elt(env, 2)); // t
    goto v0018;

v0209:
    v0257 = qvalue(elt(env, 2)); // t
    goto v0032;
// error exit handlers
v0266:
    env = stack[-4];
    qvalue(elt(env, 4)) = stack[0]; // !*!*processed
    popv(5);
    return nil;
v0260:
    popv(5);
    return nil;
}



// Code for l!-subst

static LispObject CC_lKsubst(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0096, v0207, v0198;
    LispObject fn;
    LispObject v0040, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "l-subst");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for l-subst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0040;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0198 = nil;
    goto v0016;

v0016:
    v0096 = stack[0];
    if (v0096 == nil) goto v0098;
    v0207 = stack[-1];
    v0096 = stack[0];
    v0096 = qcar(v0096);
    if (equal(v0207, v0096)) goto v0199;
    v0096 = stack[0];
    v0096 = qcar(v0096);
    v0207 = v0198;
    v0096 = cons(v0096, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0198 = v0096;
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    stack[0] = v0096;
    goto v0016;

v0199:
    v0096 = stack[-2];
    v0207 = v0198;
    v0096 = cons(v0096, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0198 = v0096;
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    stack[0] = v0096;
    goto v0016;

v0098:
    v0096 = v0198;
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0096);
    }
// error exit handlers
v0256:
    popv(4);
    return nil;
}



// Code for no!-side!-effect!-listp

static LispObject CC_noKsideKeffectKlistp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0094;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for no-side-effect-listp");
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

v0268:
    v0094 = stack[0];
    if (v0094 == nil) goto v0063;
    v0094 = stack[0];
    v0094 = qcar(v0094);
    fn = elt(env, 3); // no!-side!-effectp
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    if (v0094 == nil) goto v0099;
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    stack[0] = v0094;
    goto v0268;

v0099:
    v0094 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0094); }

v0063:
    v0094 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0094); }
// error exit handlers
v0066:
    popv(2);
    return nil;
}



// Code for red_tailred

static LispObject CC_red_tailred(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0032, v0209, v0269;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_tailred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0032 = v0001;
    v0269 = v0000;
// end of prologue
    v0209 = qvalue(elt(env, 1)); // !*noetherian
    if (v0209 == nil) goto v0065;
    v0209 = v0032;
    v0032 = elt(env, 2); // red_topred
    {
        fn = elt(env, 4); // red_tailreddriver
        return (*qfnn(fn))(qenv(fn), 3, v0269, v0209, v0032);
    }

v0065:
    v0209 = v0032;
    v0032 = elt(env, 3); // red_topredbe
    {
        fn = elt(env, 4); // red_tailreddriver
        return (*qfnn(fn))(qenv(fn), 3, v0269, v0209, v0032);
    }
}



// Code for st_consolidate

static LispObject CC_st_consolidate(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0169, v0189;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for st_consolidate");
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
    v0169 = stack[-3];
    if (v0169 == nil) goto v0027;
    v0169 = stack[-3];
    v0169 = qcdr(v0169);
    v0169 = qcar(v0169);
    if (is_number(v0169)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0169 = qvalue(elt(env, 2)); // t
    stack[-2] = v0169;
    v0169 = stack[-3];
    v0169 = qcdr(v0169);
    v0169 = Lreverse(nil, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    stack[0] = v0169;
    goto v0066;

v0066:
    v0169 = stack[0];
    if (v0169 == nil) goto v0065;
    v0169 = stack[0];
    v0169 = qcar(v0169);
    v0169 = CC_st_consolidate(env, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    v0189 = v0169;
    if (v0189 == nil) goto v0084;
    v0189 = v0169;
    v0189 = qcdr(v0189);
    v0189 = qcdr(v0189);
    if (v0189 == nil) goto v0196;
    v0189 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0189;
    goto v0273;

v0273:
    v0189 = v0169;
    v0169 = stack[-1];
    v0169 = cons(v0189, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    stack[-1] = v0169;
    goto v0084;

v0084:
    v0169 = stack[0];
    v0169 = qcdr(v0169);
    stack[0] = v0169;
    goto v0066;

v0196:
    v0189 = elt(env, 3); // !*
    v0169 = qcdr(v0169);
    v0169 = qcar(v0169);
    v0169 = list2(v0189, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    goto v0273;

v0065:
    v0169 = stack[-1];
    if (v0169 == nil) goto v0274;
    v0169 = stack[-1];
    v0169 = qcdr(v0169);
    if (v0169 == nil) goto v0146;
    v0169 = stack[-2];
    if (v0169 == nil) goto v0217;
    v0169 = stack[-1];
    stack[-4] = v0169;
    v0169 = stack[-4];
    if (v0169 == nil) goto v0190;
    v0169 = stack[-4];
    v0169 = qcar(v0169);
    v0169 = qcdr(v0169);
    v0169 = qcar(v0169);
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    stack[-1] = v0169;
    stack[-2] = v0169;
    goto v0062;

v0062:
    v0169 = stack[-4];
    v0169 = qcdr(v0169);
    stack[-4] = v0169;
    v0169 = stack[-4];
    if (v0169 == nil) goto v0023;
    stack[0] = stack[-1];
    v0169 = stack[-4];
    v0169 = qcar(v0169);
    v0169 = qcdr(v0169);
    v0169 = qcar(v0169);
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    v0169 = Lrplacd(nil, stack[0], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    v0169 = stack[-1];
    v0169 = qcdr(v0169);
    stack[-1] = v0169;
    goto v0062;

v0023:
    v0169 = stack[-2];
    goto v0172;

v0172:
    stack[-1] = v0169;
    goto v0217;

v0217:
    v0169 = stack[-3];
    v0189 = qcar(v0169);
    v0169 = stack[-1];
    popv(6);
    return cons(v0189, v0169);

v0190:
    v0169 = qvalue(elt(env, 1)); // nil
    goto v0172;

v0146:
    v0169 = stack[-1];
    v0169 = qcar(v0169);
    { popv(6); return onevalue(v0169); }

v0274:
    v0169 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0169); }

v0027:
    v0169 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0169); }
// error exit handlers
v0225:
    popv(6);
    return nil;
}



// Code for gcref_off

static LispObject CC_gcref_off(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0062, v0060, v0193;
    LispObject fn;
    argcheck(nargs, 0, "gcref_off");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcref_off");
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
    fn = elt(env, 8); // gcref_off1
    v0062 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    v0060 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    v0062 = qvalue(elt(env, 1)); // btime!*
    v0062 = difference2(v0060, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    v0062 = qvalue(elt(env, 2)); // pfiles!*
    stack[-4] = v0062;
    v0062 = stack[-4];
    if (v0062 == nil) goto v0103;
    v0062 = stack[-4];
    v0062 = qcar(v0062);
    stack[0] = v0062;
    v0062 = stack[0];
    v0193 = qcdr(v0062);
    v0060 = elt(env, 4); // cref_name
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0062 = Lputprop(nil, 3, v0193, v0060, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    v0062 = ncons(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    stack[-2] = v0062;
    stack[-3] = v0062;
    goto v0022;

v0022:
    v0062 = stack[-4];
    v0062 = qcdr(v0062);
    stack[-4] = v0062;
    v0062 = stack[-4];
    if (v0062 == nil) goto v0207;
    stack[-1] = stack[-2];
    v0062 = stack[-4];
    v0062 = qcar(v0062);
    stack[0] = v0062;
    v0062 = stack[0];
    v0193 = qcdr(v0062);
    v0060 = elt(env, 4); // cref_name
    v0062 = stack[0];
    v0062 = qcar(v0062);
    v0062 = Lputprop(nil, 3, v0193, v0060, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    v0062 = ncons(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    v0062 = Lrplacd(nil, stack[-1], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    v0062 = stack[-2];
    v0062 = qcdr(v0062);
    stack[-2] = v0062;
    goto v0022;

v0207:
    v0062 = stack[-3];
    goto v0021;

v0021:
    qvalue(elt(env, 2)) = v0062; // pfiles!*
    v0062 = qvalue(elt(env, 5)); // !*gcrefall
    if (v0062 == nil) goto v0011;
    v0062 = qvalue(elt(env, 6)); // seen!*
    fn = elt(env, 9); // gcref_select
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    fn = elt(env, 10); // gcref_mkgraph
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    goto v0173;

v0173:
    v0062 = qvalue(elt(env, 7)); // !*saveprops
    if (!(v0062 == nil)) goto v0148;
    fn = elt(env, 11); // gcref_remprops
    v0062 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    goto v0148;

v0148:
    v0062 = nil;
    { popv(6); return onevalue(v0062); }

v0011:
    v0062 = qvalue(elt(env, 6)); // seen!*
    fn = elt(env, 12); // gcref_eselect
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    fn = elt(env, 13); // gcref_mkegraph
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-5];
    goto v0173;

v0103:
    v0062 = qvalue(elt(env, 3)); // nil
    goto v0021;
// error exit handlers
v0004:
    popv(6);
    return nil;
}



// Code for cl_atl1

static LispObject CC_cl_atl1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0089;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atl1");
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
    v0089 = v0000;
// end of prologue
    fn = elt(env, 2); // cl_atml1
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    stack[-3] = v0089;
    v0089 = stack[-3];
    if (v0089 == nil) goto v0099;
    v0089 = stack[-3];
    v0089 = qcar(v0089);
    v0089 = qcar(v0089);
    v0089 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    stack[-1] = v0089;
    stack[-2] = v0089;
    goto v0016;

v0016:
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    stack[-3] = v0089;
    v0089 = stack[-3];
    if (v0089 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0089 = stack[-3];
    v0089 = qcar(v0089);
    v0089 = qcar(v0089);
    v0089 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0089 = Lrplacd(nil, stack[0], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-1] = v0089;
    goto v0016;

v0099:
    v0089 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0089); }
// error exit handlers
v0198:
    popv(5);
    return nil;
}



// Code for tayexp!-minus

static LispObject CC_tayexpKminus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0091, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0087 = v0000;
// end of prologue
    v0091 = v0087;
    if (!consp(v0091)) goto v0063;
    v0091 = v0087;
    {
        fn = elt(env, 1); // rnminus!:
        return (*qfn1(fn))(qenv(fn), v0091);
    }

v0063:
    v0091 = v0087;
    return negate(v0091);
}



// Code for pasf_sisub!-gand

static LispObject CC_pasf_sisubKgand(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0024, v0025, v0026;
    LispObject fn;
    LispObject v0145, v0063, v0041, v0040, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "pasf_sisub-gand");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0063 = va_arg(aa, LispObject);
    v0145 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_sisub-gand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0145,v0063,v0041,v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0040,v0041,v0063,v0145);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0145;
    stack[-2] = v0063;
    stack[-3] = v0041;
    stack[-4] = v0040;
    stack[-5] = v0001;
    stack[-6] = v0000;
// end of prologue
    stack[0] = nil;
    v0024 = qvalue(elt(env, 1)); // t
    stack[-7] = v0024;
    goto v0067;

v0067:
    v0024 = stack[-7];
    if (v0024 == nil) goto v0100;
    v0024 = stack[-5];
    if (v0024 == nil) goto v0100;
    v0024 = stack[-5];
    v0024 = qcar(v0024);
    v0025 = v0024;
    v0024 = stack[-5];
    v0024 = qcdr(v0024);
    stack[-5] = v0024;
    v0024 = v0025;
    v0026 = v0024;
    v0025 = stack[-4];
    v0024 = stack[-3];
    fn = elt(env, 6); // pasf_sisub
    v0024 = (*qfnn(fn))(qenv(fn), 3, v0026, v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-8];
    v0026 = v0024;
    v0025 = v0026;
    v0024 = stack[-1];
    if (v0025 == v0024) goto v0096;
    v0025 = v0026;
    v0024 = stack[-2];
    if (equal(v0025, v0024)) goto v0067;
    v0025 = v0026;
    v0024 = stack[0];
    v0024 = cons(v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-8];
    stack[0] = v0024;
    goto v0067;

v0096:
    v0024 = qvalue(elt(env, 2)); // nil
    stack[-7] = v0024;
    goto v0067;

v0100:
    v0024 = stack[-7];
    if (v0024 == nil) { LispObject res = stack[-1]; popv(9); return onevalue(res); }
    v0024 = stack[0];
    if (v0024 == nil) goto v0146;
    v0024 = stack[0];
    v0024 = qcdr(v0024);
    if (v0024 == nil) goto v0146;
    v0025 = stack[-6];
    v0024 = stack[0];
    popv(9);
    return cons(v0025, v0024);

v0146:
    v0024 = stack[0];
    if (v0024 == nil) goto v0278;
    v0024 = stack[0];
    v0024 = qcar(v0024);
    { popv(9); return onevalue(v0024); }

v0278:
    v0025 = stack[-6];
    v0024 = elt(env, 3); // and
    if (v0025 == v0024) goto v0078;
    v0024 = elt(env, 5); // false
    { popv(9); return onevalue(v0024); }

v0078:
    v0024 = elt(env, 4); // true
    { popv(9); return onevalue(v0024); }
// error exit handlers
v0159:
    popv(9);
    return nil;
}



// Code for dm!-mkfloat

static LispObject CC_dmKmkfloat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0102;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-mkfloat");
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
    v0101 = v0000;
// end of prologue
    v0102 = v0101;
    v0102 = Lintegerp(nil, v0102);
    env = stack[0];
    if (v0102 == nil) { popv(1); return onevalue(v0101); }
    v0102 = elt(env, 1); // !:rd!:
    if (!symbolp(v0102)) v0102 = nil;
    else { v0102 = qfastgets(v0102);
           if (v0102 != nil) { v0102 = elt(v0102, 34); // i2d
#ifdef RECORD_GET
             if (v0102 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0102 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0102 == SPID_NOPROP) v0102 = nil; }}
#endif
        popv(1);
        return Lapply1(nil, v0102, v0101);
}



// Code for rd!:times

static LispObject CC_rdTtimes(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0282, v0187, v0215;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:times");
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
    v0282 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0282;
    v0282 = qvalue(elt(env, 2)); // !*!*roundbf
    if (v0282 == nil) goto v0097;
    v0282 = qvalue(elt(env, 1)); // nil
    goto v0098;

v0098:
    if (v0282 == nil) goto v0015;
    v0187 = elt(env, 3); // !:rd!:
    v0282 = stack[-2];
    popv(4);
    return cons(v0187, v0282);

v0015:
    v0187 = stack[-1];
    v0282 = stack[0];
    fn = elt(env, 5); // convprc2
    v0282 = (*qfn2(fn))(qenv(fn), v0187, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    stack[-1] = v0282;
    v0282 = qvalue(elt(env, 4)); // yy!!
    stack[0] = v0282;
    v0282 = stack[-1];
    if (!consp(v0282)) goto v0147;
    v0187 = stack[-1];
    v0282 = stack[0];
    fn = elt(env, 6); // csl_timbf
    v0282 = (*qfn2(fn))(qenv(fn), v0187, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0012;

v0012:
    {
        popv(4);
        fn = elt(env, 7); // mkround
        return (*qfn1(fn))(qenv(fn), v0282);
    }

v0147:
    v0187 = stack[-1];
    v0282 = stack[0];
    v0282 = times2(v0187, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    stack[-2] = v0282;
    v0282 = stack[-2];
    fn = elt(env, 8); // fp!-infinite
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    if (v0282 == nil) goto v0043;
    fn = elt(env, 9); // rndbfon
    v0282 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0282 = stack[-1];
    v0282 = Lfloatp(nil, v0282);
    env = stack[-3];
    if (v0282 == nil) goto v0057;
    v0282 = stack[-1];
    fn = elt(env, 10); // fl2bf
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    stack[-1] = v0282;
    goto v0193;

v0193:
    v0282 = stack[0];
    v0282 = Lfloatp(nil, v0282);
    env = stack[-3];
    if (v0282 == nil) goto v0283;
    v0282 = stack[0];
    fn = elt(env, 10); // fl2bf
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0078;

v0078:
    fn = elt(env, 6); // csl_timbf
    v0282 = (*qfn2(fn))(qenv(fn), stack[-1], v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0012;

v0283:
    v0282 = stack[0];
    if (!consp(v0282)) goto v0045;
    v0282 = stack[0];
    goto v0188;

v0188:
    fn = elt(env, 11); // normbf
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0078;

v0045:
    v0282 = stack[0];
    v0282 = integerp(v0282);
    if (v0282 == nil) goto v0168;
    v0215 = elt(env, 3); // !:rd!:
    v0187 = stack[0];
    v0282 = (LispObject)1; // 0
    v0282 = list2star(v0215, v0187, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0188;

v0168:
    v0282 = stack[0];
    fn = elt(env, 12); // read!:num
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0188;

v0057:
    v0282 = stack[-1];
    if (!consp(v0282)) goto v0023;
    v0282 = stack[-1];
    goto v0002;

v0002:
    fn = elt(env, 11); // normbf
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    stack[-1] = v0282;
    goto v0193;

v0023:
    v0282 = stack[-1];
    v0282 = integerp(v0282);
    if (v0282 == nil) goto v0079;
    v0215 = elt(env, 3); // !:rd!:
    v0187 = stack[-1];
    v0282 = (LispObject)1; // 0
    v0282 = list2star(v0215, v0187, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0002;

v0079:
    v0282 = stack[-1];
    fn = elt(env, 12); // read!:num
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0002;

v0043:
    v0282 = stack[-2];
    goto v0012;

v0097:
    v0282 = stack[-1];
    v0282 = qcdr(v0282);
    if (!consp(v0282)) goto v0067;
    v0282 = qvalue(elt(env, 1)); // nil
    goto v0098;

v0067:
    v0282 = stack[0];
    v0282 = qcdr(v0282);
    if (!consp(v0282)) goto v0203;
    v0282 = qvalue(elt(env, 1)); // nil
    goto v0098;

v0203:
    v0282 = stack[-1];
    v0187 = qcdr(v0282);
    v0282 = stack[0];
    v0282 = qcdr(v0282);
    fn = elt(env, 13); // safe!-fp!-times
    v0282 = (*qfn2(fn))(qenv(fn), v0187, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    stack[-2] = v0282;
    goto v0098;
// error exit handlers
v0142:
    popv(4);
    return nil;
}



// Code for permp

static LispObject CC_permp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0177, v0157, v0256, v0277;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for permp");
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
    v0157 = v0001;
    v0256 = v0000;
// end of prologue

v0145:
    v0177 = v0256;
    if (v0177 == nil) goto v0028;
    v0177 = v0256;
    v0277 = qcar(v0177);
    v0177 = v0157;
    v0177 = qcar(v0177);
    if (equal(v0277, v0177)) goto v0099;
    v0177 = v0256;
    stack[0] = qcdr(v0177);
    v0177 = v0157;
    v0177 = qcar(v0177);
    v0256 = qcar(v0256);
    v0157 = qcdr(v0157);
    v0177 = Lsubst(nil, 3, v0177, v0256, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-1];
    v0177 = CC_permp(env, stack[0], v0177);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    v0177 = (v0177 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0177); }

v0099:
    v0177 = v0256;
    v0177 = qcdr(v0177);
    v0256 = v0177;
    v0177 = v0157;
    v0177 = qcdr(v0177);
    v0157 = v0177;
    goto v0145;

v0028:
    v0177 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0177); }
// error exit handlers
v0206:
    popv(2);
    return nil;
}



// Code for contract!-strand

static LispObject CC_contractKstrand(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0099, v0091;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contract-strand");
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
    v0099 = v0001;
    v0091 = v0000;
// end of prologue
    stack[0] = v0091;
    fn = elt(env, 1); // zero!-roads
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    {
        LispObject v0067 = stack[0];
        popv(2);
        fn = elt(env, 2); // contr!-strand
        return (*qfn2(fn))(qenv(fn), v0067, v0099);
    }
// error exit handlers
v0100:
    popv(2);
    return nil;
}



// Code for subla!-q

static LispObject CC_sublaKq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0215, v0216;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subla-q");
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
    v0215 = stack[-1];
    if (v0215 == nil) goto v0099;
    v0215 = stack[0];
    v0215 = (v0215 == nil ? lisp_true : nil);
    goto v0097;

v0097:
    if (!(v0215 == nil)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0215 = stack[0];
    if (!consp(v0215)) goto v0018;
    v0215 = stack[0];
    v0216 = qcar(v0215);
    v0215 = elt(env, 2); // quote
    if (v0216 == v0215) goto v0089;
    v0215 = stack[0];
    v0216 = qcar(v0215);
    v0215 = elt(env, 3); // go
    v0215 = (v0216 == v0215 ? lisp_true : nil);
    goto v0073;

v0073:
    if (!(v0215 == nil)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0216 = stack[0];
    v0215 = elt(env, 4); // lambda
    if (!consp(v0216)) goto v0008;
    v0216 = qcar(v0216);
    if (!(v0216 == v0215)) goto v0008;
    v0215 = qvalue(elt(env, 1)); // t
    goto v0194;

v0194:
    if (v0215 == nil) goto v0060;
    v0215 = stack[0];
    v0215 = qcdr(v0215);
    v0215 = (consp(v0215) ? nil : lisp_true);
    v0215 = (v0215 == nil ? lisp_true : nil);
    goto v0013;

v0013:
    if (v0215 == nil) goto v0049;
    v0215 = stack[0];
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    stack[-2] = v0215;
    goto v0222;

v0222:
    v0215 = stack[-2];
    if (v0215 == nil) goto v0254;
    v0215 = stack[-2];
    v0215 = qcar(v0215);
    v0216 = v0215;
    v0215 = stack[-1];
    fn = elt(env, 7); // delasc
    v0215 = (*qfn2(fn))(qenv(fn), v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[-1] = v0215;
    v0215 = stack[-2];
    v0215 = qcdr(v0215);
    stack[-2] = v0215;
    goto v0222;

v0254:
    v0216 = stack[-1];
    v0215 = stack[0];
    v0215 = qcar(v0215);
    stack[-2] = CC_sublaKq(env, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0216 = stack[-1];
    v0215 = stack[0];
    v0215 = qcdr(v0215);
    v0215 = CC_sublaKq(env, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    {
        LispObject v0034 = stack[-2];
        popv(4);
        return cons(v0034, v0215);
    }

v0049:
    v0216 = stack[-1];
    v0215 = stack[0];
    v0215 = qcar(v0215);
    stack[-2] = CC_sublaKq(env, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0216 = stack[-1];
    v0215 = stack[0];
    v0215 = qcdr(v0215);
    v0215 = CC_sublaKq(env, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    {
        LispObject v0036 = stack[-2];
        popv(4);
        return cons(v0036, v0215);
    }

v0060:
    v0215 = qvalue(elt(env, 6)); // nil
    goto v0013;

v0008:
    v0216 = stack[0];
    v0215 = elt(env, 5); // prog
    v0215 = Leqcar(nil, v0216, v0215);
    env = stack[-3];
    goto v0194;

v0089:
    v0215 = qvalue(elt(env, 1)); // t
    goto v0073;

v0018:
    v0216 = stack[0];
    v0215 = stack[-1];
    v0216 = Latsoc(nil, v0216, v0215);
    v0215 = v0216;
    if (v0216 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0215 = qcdr(v0215);
    { popv(4); return onevalue(v0215); }

v0099:
    v0215 = qvalue(elt(env, 1)); // t
    goto v0097;
// error exit handlers
v0035:
    popv(4);
    return nil;
}



// Code for groeb!=rf1

static LispObject CC_groebMrf1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0022, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=rf1");
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
    v0022 = v0000;
// end of prologue
    v0017 = stack[0];
    fn = elt(env, 1); // red_totalred
    v0017 = (*qfn2(fn))(qenv(fn), v0017, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    v0022 = stack[0];
    popv(1);
    return list2(v0017, v0022);
// error exit handlers
v0102:
    popv(1);
    return nil;
}



// Code for negind

static LispObject CC_negind(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0085, v0088;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negind");
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

v0268:
    v0085 = stack[-1];
    if (v0085 == nil) goto v0145;
    v0085 = stack[-1];
    v0088 = qcar(v0085);
    v0085 = stack[0];
    v0085 = qcar(v0085);
    v0085 = qcar(v0085);
    v0088 = plus2(v0088, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    v0085 = (LispObject)1; // 0
    v0085 = (LispObject)lessp2(v0088, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    v0085 = v0085 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0085 == nil)) { popv(3); return onevalue(v0085); }
    v0085 = stack[-1];
    v0088 = qcdr(v0085);
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    stack[-1] = v0088;
    stack[0] = v0085;
    goto v0268;

v0145:
    v0085 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0085); }
// error exit handlers
v0092:
    popv(3);
    return nil;
}



// Code for qqe_arg!-check!-lb!-rb

static LispObject CC_qqe_argKcheckKlbKrb(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0089, v0092;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check-lb-rb");
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
    v0089 = stack[0];
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    v0092 = v0089;
    v0089 = stack[0];
    v0089 = qcdr(v0089);
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    stack[-1] = v0089;
    v0089 = v0092;
    fn = elt(env, 3); // qqe_arg!-check!-b
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    if (!(v0089 == nil)) goto v0087;
    fn = elt(env, 4); // qqe_arg!-check!-marked!-ids!-rollback
    v0089 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    v0092 = stack[0];
    v0089 = elt(env, 1); // "type conflict: arguments don't fit
//             binary op with basic type args"
    fn = elt(env, 5); // typerr
    v0089 = (*qfn2(fn))(qenv(fn), v0092, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    goto v0087;

v0087:
    v0089 = stack[-1];
    fn = elt(env, 3); // qqe_arg!-check!-b
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    if (!(v0089 == nil)) goto v0033;
    fn = elt(env, 4); // qqe_arg!-check!-marked!-ids!-rollback
    v0089 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    v0092 = stack[0];
    v0089 = elt(env, 1); // "type conflict: arguments don't fit
//             binary op with basic type args"
    fn = elt(env, 5); // typerr
    v0089 = (*qfn2(fn))(qenv(fn), v0092, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    goto v0033;

v0033:
    v0089 = nil;
    { popv(3); return onevalue(v0089); }
// error exit handlers
v0207:
    popv(3);
    return nil;
}



// Code for dvfsf_0mk2

static LispObject CC_dvfsf_0mk2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0087, v0100, v0067;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0087 = v0001;
    v0100 = v0000;
// end of prologue
    v0067 = qvalue(elt(env, 1)); // nil
    return list3(v0100, v0087, v0067);
}



// Code for get!-height

static LispObject CC_getKheight(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0018;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-height");
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
    v0018 = stack[0];
    if (v0018 == nil) goto v0063;
    v0018 = stack[0];
    if (is_number(v0018)) goto v0028;
    v0018 = stack[0];
    v0018 = qcar(v0018);
    v0018 = qcdr(v0018);
    stack[-1] = CC_getKheight(env, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    v0018 = CC_getKheight(env, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    {
        LispObject v0032 = stack[-1];
        popv(3);
        fn = elt(env, 1); // max
        return (*qfn2(fn))(qenv(fn), v0032, v0018);
    }

v0028:
    v0018 = stack[0];
        popv(3);
        return Labsval(nil, v0018);

v0063:
    v0018 = (LispObject)1; // 0
    { popv(3); return onevalue(v0018); }
// error exit handlers
v0072:
    popv(3);
    return nil;
}



// Code for getdec

static LispObject CC_getdec(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0102, v0103;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getdec");
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
    v0103 = qvalue(elt(env, 1)); // nil
    v0102 = stack[0];
    fn = elt(env, 2); // symtabget
    v0102 = (*qfn2(fn))(qenv(fn), v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-1];
    v0103 = v0102;
    v0102 = v0103;
    if (!(v0102 == nil)) { popv(2); return onevalue(v0103); }
    v0102 = stack[0];
    fn = elt(env, 3); // implicitdec
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0103 = v0102;
    { popv(2); return onevalue(v0103); }
// error exit handlers
v0065:
    popv(2);
    return nil;
}



// Code for plubf

static LispObject CC_plubf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0133, v0131, v0132;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plubf");
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
    stack[-6] = v0001;
    stack[-7] = v0000;
// end of prologue
    v0133 = stack[-7];
    v0133 = qcdr(v0133);
    v0131 = qcar(v0133);
    stack[-8] = v0131;
    v0133 = (LispObject)1; // 0
    if (v0131 == v0133) goto v0087;
    v0133 = stack[-6];
    v0133 = qcdr(v0133);
    v0131 = qcar(v0133);
    stack[-5] = v0131;
    v0133 = (LispObject)1; // 0
    if (v0131 == v0133) goto v0018;
    v0133 = stack[-7];
    v0133 = qcdr(v0133);
    v0131 = qcdr(v0133);
    stack[-4] = v0131;
    v0133 = stack[-6];
    v0133 = qcdr(v0133);
    v0133 = qcdr(v0133);
    stack[-3] = v0133;
    v0131 = difference2(v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    stack[-2] = v0131;
    v0133 = (LispObject)1; // 0
    if (v0131 == v0133) goto v0075;
    stack[-1] = stack[-2];
    v0133 = stack[-8];
    v0133 = Labsval(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    fn = elt(env, 3); // msd
    stack[0] = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0133 = stack[-5];
    v0133 = Labsval(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    fn = elt(env, 3); // msd
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0133 = difference2(stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0133 = plus2(stack[-1], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    stack[-1] = v0133;
    v0133 = qvalue(elt(env, 2)); // !:bprec!:
    v0133 = add1(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    stack[0] = v0133;
    v0131 = stack[-1];
    v0133 = stack[0];
    v0133 = (LispObject)greaterp2(v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-9];
    if (v0133 == nil) goto v0025;
    v0133 = stack[-7];
    goto v0097;

v0097:
    stack[-2] = v0133;
    v0133 = stack[-2];
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    v0132 = v0133;
    v0131 = v0132;
    v0133 = (LispObject)1; // 0
    if (v0131 == v0133) goto v0080;
    v0131 = v0132;
    v0133 = qvalue(elt(env, 2)); // !:bprec!:
    fn = elt(env, 4); // inorm
    v0133 = (*qfn2(fn))(qenv(fn), v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0132 = v0133;
    stack[-1] = elt(env, 1); // !:rd!:
    v0133 = v0132;
    stack[0] = qcar(v0133);
    v0133 = v0132;
    v0131 = qcdr(v0133);
    v0133 = stack[-2];
    v0133 = qcdr(v0133);
    v0133 = qcdr(v0133);
    v0133 = plus2(v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    {
        LispObject v0184 = stack[-1];
        LispObject v0296 = stack[0];
        popv(10);
        return list2star(v0184, v0296, v0133);
    }

v0080:
    v0132 = elt(env, 1); // !:rd!:
    v0131 = (LispObject)1; // 0
    v0133 = (LispObject)1; // 0
    popv(10);
    return list2star(v0132, v0131, v0133);

v0025:
    v0133 = stack[0];
    v0133 = negate(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0133 = (LispObject)lessp2(stack[-1], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-9];
    if (v0133 == nil) goto v0202;
    v0133 = stack[-6];
    goto v0097;

v0202:
    v0131 = stack[-2];
    v0133 = (LispObject)1; // 0
    v0133 = (LispObject)greaterp2(v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-9];
    if (v0133 == nil) goto v0048;
    stack[0] = elt(env, 1); // !:rd!:
    v0131 = stack[-8];
    v0133 = stack[-2];
    fn = elt(env, 5); // ashift
    v0131 = (*qfn2(fn))(qenv(fn), v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0133 = stack[-5];
    v0131 = plus2(v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0133 = stack[-3];
    v0133 = list2star(stack[0], v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    goto v0097;

v0048:
    stack[0] = elt(env, 1); // !:rd!:
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v0133 = stack[-2];
    v0133 = negate(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    fn = elt(env, 5); // ashift
    v0133 = (*qfn2(fn))(qenv(fn), stack[-3], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0131 = plus2(stack[-1], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0133 = stack[-4];
    v0133 = list2star(stack[0], v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    goto v0097;

v0075:
    stack[0] = elt(env, 1); // !:rd!:
    v0131 = stack[-8];
    v0133 = stack[-5];
    v0131 = plus2(v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    v0133 = stack[-4];
    v0133 = list2star(stack[0], v0131, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-9];
    goto v0097;

v0018:
    v0133 = stack[-7];
    goto v0097;

v0087:
    v0133 = stack[-6];
    goto v0097;
// error exit handlers
v0295:
    popv(10);
    return nil;
}



// Code for unresidp

static LispObject CC_unresidp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0097, v0099;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unresidp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0097 = v0000;
// end of prologue
    v0099 = qvalue(elt(env, 1)); // !*reservedops!*
    v0097 = Lmemq(nil, v0097, v0099);
    v0097 = (v0097 == nil ? lisp_true : nil);
    return onevalue(v0097);
}



// Code for log_inlines

static LispObject CC_log_inlines(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0032, v0209;
    LispObject fn;
    LispObject v0040, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "log_inlines");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log_inlines");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0032 = v0040;
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0209 = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 2); // log_assignment
    v0032 = (*qfn2(fn))(qenv(fn), v0209, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-2];
    if (v0032 == nil) goto v0065;
    v0032 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0032); }

v0065:
    v0209 = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 3); // log_freevars
    v0032 = (*qfn2(fn))(qenv(fn), v0209, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-2];
    if (v0032 == nil) goto v0101;
    v0032 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0032); }

v0101:
    v0032 = nil;
    { popv(3); return onevalue(v0032); }
// error exit handlers
v0275:
    popv(3);
    return nil;
}



// Code for quotpri

static LispObject CC_quotpri(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0206, v0064, v0014;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotpri");
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
    v0064 = v0000;
// end of prologue
    stack[0] = nil;
    v0206 = qvalue(elt(env, 1)); // !*ratpri
    if (v0206 == nil) goto v0097;
    v0206 = qvalue(elt(env, 3)); // !*nat
    if (v0206 == nil) goto v0017;
    v0206 = qvalue(elt(env, 4)); // !*fort
    if (!(v0206 == nil)) goto v0098;
    v0206 = qvalue(elt(env, 5)); // !*list
    if (!(v0206 == nil)) goto v0098;
    v0206 = qvalue(elt(env, 6)); // !*mcd
    v0206 = (v0206 == nil ? lisp_true : nil);
    goto v0098;

v0098:
    if (v0206 == nil) goto v0020;
    v0206 = elt(env, 7); // failed
    { popv(2); return onevalue(v0206); }

v0020:
    v0014 = qvalue(elt(env, 8)); // dmode!*
    v0206 = elt(env, 9); // ratmode
    v0206 = Lflagp(nil, v0014, v0206);
    env = stack[-1];
    if (v0206 == nil) goto v0086;
    v0206 = qvalue(elt(env, 8)); // dmode!*
    stack[0] = v0206;
    v0206 = qvalue(elt(env, 10)); // nil
    qvalue(elt(env, 8)) = v0206; // dmode!*
    goto v0086;

v0086:
    v0206 = v0064;
    fn = elt(env, 11); // ratfunpri1
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-1];
    v0064 = v0206;
    v0206 = stack[0];
    if (v0206 == nil) { popv(2); return onevalue(v0064); }
    v0206 = stack[0];
    qvalue(elt(env, 8)) = v0206; // dmode!*
    { popv(2); return onevalue(v0064); }

v0017:
    v0206 = qvalue(elt(env, 2)); // t
    goto v0098;

v0097:
    v0206 = qvalue(elt(env, 2)); // t
    goto v0098;
// error exit handlers
v0267:
    popv(2);
    return nil;
}



// Code for mo_2a

static LispObject CC_mo_2a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0099;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_2a");
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
    v0099 = v0000;
// end of prologue
    stack[0] = qcar(v0099);
    v0099 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 2); // ring_all_names
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    {
        LispObject v0100 = stack[0];
        popv(2);
        fn = elt(env, 3); // mo!=expvec2a1
        return (*qfn2(fn))(qenv(fn), v0100, v0099);
    }
// error exit handlers
v0087:
    popv(2);
    return nil;
}



// Code for delasc

static LispObject CC_delasc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0205, v0177;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delasc");
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
    goto v0028;

v0028:
    v0205 = stack[0];
    if (v0205 == nil) goto v0016;
    v0205 = stack[0];
    v0205 = qcar(v0205);
    if (!consp(v0205)) goto v0102;
    v0177 = stack[-1];
    v0205 = stack[0];
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0205 = Lneq(nil, v0177, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    goto v0101;

v0101:
    if (v0205 == nil) goto v0067;
    v0205 = stack[0];
    v0177 = qcar(v0205);
    v0205 = stack[-2];
    v0205 = cons(v0177, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[-2] = v0205;
    goto v0067;

v0067:
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    stack[0] = v0205;
    goto v0028;

v0102:
    v0205 = qvalue(elt(env, 2)); // t
    goto v0101;

v0016:
    v0205 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0205);
// error exit handlers
v0196:
    popv(4);
    return nil;
}



// Code for qtypnm

static LispObject CC_qtypnm(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0187, v0215, v0216;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qtypnm");
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
    v0215 = stack[-3];
    v0187 = elt(env, 1); // function
    v0187 = Lflagp(nil, v0215, v0187);
    env = stack[-6];
    if (v0187 == nil) goto v0064;
    v0215 = stack[-4];
    v0187 = elt(env, 2); // seen
    v0187 = Lflagp(nil, v0215, v0187);
    env = stack[-6];
    if (!(v0187 == nil)) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    v0187 = stack[-4];
    v0215 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = elt(env, 2); // seen
    v0187 = Lflag(nil, v0215, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0215 = stack[-4];
    v0187 = qvalue(elt(env, 3)); // seen!*
    v0187 = cons(v0215, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    qvalue(elt(env, 3)) = v0187; // seen!*
    { LispObject res = stack[-4]; popv(7); return onevalue(res); }

v0064:
    v0215 = stack[-3];
    v0187 = elt(env, 4); // tseen
    v0187 = get(v0215, v0187);
    env = stack[-6];
    stack[-2] = v0187;
    if (v0187 == nil) goto v0157;
    v0215 = stack[-4];
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0187 = Latsoc(nil, v0215, v0187);
    stack[-5] = v0187;
    if (v0187 == nil) goto v0157;
    v0187 = stack[-5];
    v0187 = qcdr(v0187);
    { popv(7); return onevalue(v0187); }

v0157:
    v0187 = stack[-2];
    if (!(v0187 == nil)) goto v0059;
    stack[-1] = elt(env, 5); // !(
    v0187 = stack[-3];
    stack[0] = Lexplode(nil, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = elt(env, 6); // !)
    v0187 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = Lnconc(nil, stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = cons(stack[-1], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    stack[-2] = v0187;
    v0216 = stack[-3];
    v0215 = elt(env, 4); // tseen
    v0187 = stack[-2];
    v0187 = Lputprop(nil, 3, v0216, v0215, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0215 = stack[-3];
    v0187 = qvalue(elt(env, 7)); // tseen!*
    v0187 = cons(v0215, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    qvalue(elt(env, 7)) = v0187; // tseen!*
    goto v0059;

v0059:
    v0187 = stack[-4];
    v0187 = Lexplode(nil, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    stack[-1] = v0187;
    v0187 = Lcompress(nil, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    stack[-5] = v0187;
    stack[0] = stack[-2];
    v0216 = stack[-4];
    v0215 = stack[-5];
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0187 = acons(v0216, v0215, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = Lrplacd(nil, stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = stack[-2];
    v0215 = qcar(v0187);
    v0187 = stack[-1];
    v0187 = Lappend(nil, v0215, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    stack[-2] = v0187;
    stack[-1] = stack[-5];
    stack[0] = elt(env, 8); // rccnam
    v0187 = stack[-2];
    v0215 = Llength(nil, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = stack[-2];
    v0187 = cons(v0215, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0187 = Lputprop(nil, 3, stack[-1], stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-6];
    v0216 = stack[-3];
    v0215 = elt(env, 9); // funs
    v0187 = stack[-5];
    fn = elt(env, 10); // traput
    v0187 = (*qfnn(fn))(qenv(fn), 3, v0216, v0215, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    { LispObject res = stack[-5]; popv(7); return onevalue(res); }
// error exit handlers
v0165:
    popv(7);
    return nil;
}



// Code for pushback

static LispObject CC_pushback(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0073, v0089;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pushback");
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
    v0073 = v0000;
// end of prologue

v0027:
    v0089 = v0073;
    v0089 = qcar(v0089);
    if (v0089 == nil) goto v0203;
    v0073 = qcdr(v0073);
    goto v0027;

v0203:
    stack[-1] = v0073;
    v0089 = v0073;
    v0089 = qcar(v0089);
    v0073 = qcdr(v0073);
    v0073 = cons(v0089, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    v0089 = Lrplacd(nil, stack[-1], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    v0073 = stack[0];
    v0073 = Lrplaca(nil, v0089, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0073 = nil;
    { popv(3); return onevalue(v0073); }
// error exit handlers
v0096:
    popv(3);
    return nil;
}



// Code for qqe_ofsf_simpat

static LispObject CC_qqe_ofsf_simpat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0072, v0032;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_simpat");
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
    v0072 = stack[0];
    fn = elt(env, 2); // qqe_arg2l
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-1];
    fn = elt(env, 3); // qqe_ofsf_chsimpterm
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-1];
    v0072 = stack[0];
    fn = elt(env, 4); // qqe_arg2r
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-1];
    fn = elt(env, 3); // qqe_ofsf_chsimpterm
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-1];
    v0072 = stack[0];
    fn = elt(env, 5); // qqe_arg!-check
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-1];
    v0072 = stack[0];
    fn = elt(env, 6); // qqe_op
    v0032 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-1];
    v0072 = elt(env, 1); // (qequal qneq)
    v0072 = Lmemq(nil, v0032, v0072);
    if (v0072 == nil) goto v0203;
    v0072 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); // qqe_simpat
        return (*qfn1(fn))(qenv(fn), v0072);
    }

v0203:
    v0072 = stack[0];
    {
        popv(2);
        fn = elt(env, 8); // ofsf_simpat
        return (*qfn1(fn))(qenv(fn), v0072);
    }
// error exit handlers
v0269:
    popv(2);
    return nil;
}



// Code for pasf_pdp

static LispObject CC_pasf_pdp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0290, v0300, v0301;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_pdp");
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
    v0290 = stack[0];
    if (!consp(v0290)) goto v0099;
    v0290 = stack[0];
    v0290 = qcar(v0290);
    v0290 = (consp(v0290) ? nil : lisp_true);
    goto v0097;

v0097:
    if (v0290 == nil) goto v0016;
    v0290 = stack[0];
    if (v0290 == nil) goto v0094;
    v0300 = stack[0];
    v0290 = (LispObject)1; // 0
    v0290 = (LispObject)lessp2(v0300, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-2];
    if (v0290 == nil) goto v0084;
    v0290 = elt(env, 3); // ndef
    { popv(3); return onevalue(v0290); }

v0084:
    v0300 = stack[0];
    v0290 = (LispObject)1; // 0
    v0290 = (LispObject)greaterp2(v0300, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-2];
    if (v0290 == nil) goto v0207;
    v0290 = elt(env, 4); // pdef
    { popv(3); return onevalue(v0290); }

v0207:
    v0290 = elt(env, 2); // indef
    { popv(3); return onevalue(v0290); }

v0094:
    v0290 = elt(env, 2); // indef
    { popv(3); return onevalue(v0290); }

v0016:
    v0290 = stack[0];
    v0290 = qcar(v0290);
    v0290 = qcar(v0290);
    v0290 = qcdr(v0290);
    v0290 = Levenp(nil, v0290);
    env = stack[-2];
    if (v0290 == nil) goto v0157;
    v0290 = stack[0];
    v0290 = qcar(v0290);
    v0290 = qcdr(v0290);
    v0290 = CC_pasf_pdp(env, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    stack[-1] = v0290;
    v0290 = stack[0];
    v0290 = qcdr(v0290);
    v0290 = CC_pasf_pdp(env, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    v0301 = v0290;
    v0290 = v0301;
    if (v0290 == nil) goto v0175;
    v0290 = qvalue(elt(env, 6)); // nil
    goto v0208;

v0208:
    if (v0290 == nil) goto v0176;
    v0290 = elt(env, 5); // psdef
    { popv(3); return onevalue(v0290); }

v0176:
    v0290 = v0301;
    if (v0290 == nil) goto v0183;
    v0290 = qvalue(elt(env, 6)); // nil
    goto v0004;

v0004:
    if (v0290 == nil) goto v0262;
    v0290 = elt(env, 7); // nsdef
    { popv(3); return onevalue(v0290); }

v0262:
    v0300 = v0301;
    v0290 = elt(env, 4); // pdef
    if (v0300 == v0290) goto v0046;
    v0290 = qvalue(elt(env, 6)); // nil
    goto v0171;

v0171:
    if (v0290 == nil) goto v0035;
    v0290 = elt(env, 4); // pdef
    { popv(3); return onevalue(v0290); }

v0035:
    v0300 = v0301;
    v0290 = elt(env, 3); // ndef
    if (v0300 == v0290) goto v0144;
    v0290 = qvalue(elt(env, 6)); // nil
    goto v0252;

v0252:
    if (v0290 == nil) goto v0157;
    v0290 = elt(env, 3); // ndef
    { popv(3); return onevalue(v0290); }

v0157:
    v0290 = elt(env, 2); // indef
    { popv(3); return onevalue(v0290); }

v0144:
    v0300 = stack[-1];
    v0290 = elt(env, 7); // nsdef
    if (v0300 == v0290) goto v0302;
    v0300 = stack[-1];
    v0290 = elt(env, 3); // ndef
    v0290 = (v0300 == v0290 ? lisp_true : nil);
    goto v0252;

v0302:
    v0290 = qvalue(elt(env, 1)); // t
    goto v0252;

v0046:
    v0300 = stack[-1];
    v0290 = elt(env, 5); // psdef
    if (v0300 == v0290) goto v0045;
    v0300 = stack[-1];
    v0290 = elt(env, 4); // pdef
    v0290 = (v0300 == v0290 ? lisp_true : nil);
    goto v0171;

v0045:
    v0290 = qvalue(elt(env, 1)); // t
    goto v0171;

v0183:
    v0300 = stack[-1];
    v0290 = elt(env, 7); // nsdef
    if (v0300 == v0290) goto v0303;
    v0300 = stack[-1];
    v0290 = elt(env, 3); // ndef
    v0290 = (v0300 == v0290 ? lisp_true : nil);
    goto v0004;

v0303:
    v0290 = qvalue(elt(env, 1)); // t
    goto v0004;

v0175:
    v0300 = stack[-1];
    v0290 = elt(env, 5); // psdef
    if (v0300 == v0290) goto v0058;
    v0300 = stack[-1];
    v0290 = elt(env, 4); // pdef
    v0290 = (v0300 == v0290 ? lisp_true : nil);
    goto v0208;

v0058:
    v0290 = qvalue(elt(env, 1)); // t
    goto v0208;

v0099:
    v0290 = qvalue(elt(env, 1)); // t
    goto v0097;
// error exit handlers
v0223:
    popv(3);
    return nil;
}



// Code for sfto_b!:ordexn

static LispObject CC_sfto_bTordexn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0031, v0192;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_b:ordexn");
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
    goto v0016;

v0016:
    v0031 = stack[-1];
    if (v0031 == nil) goto v0103;
    v0192 = stack[-2];
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    if (equal(v0192, v0031)) goto v0090;
    v0031 = stack[-2];
    if (v0031 == nil) goto v0009;
    v0192 = stack[-2];
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    v0031 = (LispObject)greaterp2(v0192, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    v0031 = v0031 ? lisp_true : nil;
    env = stack[-4];
    if (v0031 == nil) goto v0009;
    v0192 = stack[-2];
    v0031 = stack[-3];
    v0031 = cons(v0192, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    v0192 = Lreverse(nil, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    v0031 = stack[-1];
    v0031 = Lappend(nil, v0192, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    {
        LispObject v0172 = stack[0];
        popv(5);
        return cons(v0172, v0031);
    }

v0009:
    v0031 = stack[-1];
    v0192 = qcar(v0031);
    v0031 = stack[-3];
    v0031 = cons(v0192, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    stack[-3] = v0031;
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    v0031 = stack[0];
    v0031 = (v0031 == nil ? lisp_true : nil);
    stack[0] = v0031;
    goto v0016;

v0090:
    v0031 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0031); }

v0103:
    v0192 = stack[-2];
    v0031 = stack[-3];
    v0031 = cons(v0192, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    v0031 = Lreverse(nil, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    {
        LispObject v0062 = stack[0];
        popv(5);
        return cons(v0062, v0031);
    }
// error exit handlers
v0006:
    popv(5);
    return nil;
}



setup_type const u28_setup[] =
{
    {"bc_prod",                 too_few_2,      CC_bc_prod,    wrong_no_2},
    {"cnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnrd},
    {"ps:expression",           CC_psTexpression,too_many_1,   wrong_no_1},
    {"bcfd",                    CC_bcfd,        too_many_1,    wrong_no_1},
    {"critical_element",        CC_critical_element,too_many_1,wrong_no_1},
    {"prop-simp",               too_few_2,      CC_propKsimp,  wrong_no_2},
    {"assert_declarestat1",     CC_assert_declarestat1,too_many_1,wrong_no_1},
    {"sf2mv",                   too_few_2,      CC_sf2mv,      wrong_no_2},
    {"fs:prepfn:",              CC_fsTprepfnT,  too_many_1,    wrong_no_1},
    {"ratminus",                CC_ratminus,    too_many_1,    wrong_no_1},
    {"setk1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setk1},
    {"cquotegex",               CC_cquotegex,   too_many_1,    wrong_no_1},
    {"simpexpt11",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt11},
    {"rndifference:",           too_few_2,      CC_rndifferenceT,wrong_no_2},
    {"mk+trace",                CC_mkLtrace,    too_many_1,    wrong_no_1},
    {"aex_bvarl",               CC_aex_bvarl,   too_many_1,    wrong_no_1},
    {"opfneval",                CC_opfneval,    too_many_1,    wrong_no_1},
    {"doublep",                 CC_doublep,     too_many_1,    wrong_no_1},
    {"sc_geq",                  too_few_2,      CC_sc_geq,     wrong_no_2},
    {"evrevgradlexcomp",        too_few_2,      CC_evrevgradlexcomp,wrong_no_2},
    {"physop-multfnc",          too_few_2,      CC_physopKmultfnc,wrong_no_2},
    {"l-subst",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_lKsubst},
    {"no-side-effect-listp",    CC_noKsideKeffectKlistp,too_many_1,wrong_no_1},
    {"red_tailred",             too_few_2,      CC_red_tailred,wrong_no_2},
    {"st_consolidate",          CC_st_consolidate,too_many_1,  wrong_no_1},
    {"gcref_off",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcref_off},
    {"cl_atl1",                 CC_cl_atl1,     too_many_1,    wrong_no_1},
    {"tayexp-minus",            CC_tayexpKminus,too_many_1,    wrong_no_1},
    {"pasf_sisub-gand",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sisubKgand},
    {"dm-mkfloat",              CC_dmKmkfloat,  too_many_1,    wrong_no_1},
    {"rd:times",                too_few_2,      CC_rdTtimes,   wrong_no_2},
    {"permp",                   too_few_2,      CC_permp,      wrong_no_2},
    {"contract-strand",         too_few_2,      CC_contractKstrand,wrong_no_2},
    {"subla-q",                 too_few_2,      CC_sublaKq,    wrong_no_2},
    {"groeb=rf1",               too_few_2,      CC_groebMrf1,  wrong_no_2},
    {"negind",                  too_few_2,      CC_negind,     wrong_no_2},
    {"qqe_arg-check-lb-rb",     CC_qqe_argKcheckKlbKrb,too_many_1,wrong_no_1},
    {"dvfsf_0mk2",              too_few_2,      CC_dvfsf_0mk2, wrong_no_2},
    {"get-height",              CC_getKheight,  too_many_1,    wrong_no_1},
    {"getdec",                  CC_getdec,      too_many_1,    wrong_no_1},
    {"plubf",                   too_few_2,      CC_plubf,      wrong_no_2},
    {"unresidp",                CC_unresidp,    too_many_1,    wrong_no_1},
    {"log_inlines",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_log_inlines},
    {"quotpri",                 CC_quotpri,     too_many_1,    wrong_no_1},
    {"mo_2a",                   CC_mo_2a,       too_many_1,    wrong_no_1},
    {"delasc",                  too_few_2,      CC_delasc,     wrong_no_2},
    {"qtypnm",                  too_few_2,      CC_qtypnm,     wrong_no_2},
    {"pushback",                too_few_2,      CC_pushback,   wrong_no_2},
    {"qqe_ofsf_simpat",         CC_qqe_ofsf_simpat,too_many_1, wrong_no_1},
    {"pasf_pdp",                CC_pasf_pdp,    too_many_1,    wrong_no_1},
    {"sfto_b:ordexn",           too_few_2,      CC_sfto_bTordexn,wrong_no_2},
    {NULL, (one_args *)"u28", (two_args *)"4857 6701410 2417777", 0}
};

// end of generated code
