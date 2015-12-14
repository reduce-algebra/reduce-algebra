
// $destdir\u60.c        Machine generated C code

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



// Code for exformp

static LispObject CC_exformp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0011, v0012;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exformp");
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

v0013:
    v0011 = stack[0];
    if (v0011 == nil) goto v0014;
    v0011 = stack[0];
    v0011 = (is_number(v0011) ? lisp_true : nil);
    goto v0015;

v0015:
    if (v0011 == nil) goto v0016;
    v0011 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0011); }

v0016:
    v0011 = stack[0];
    if (!consp(v0011)) goto v0017;
    v0011 = qvalue(elt(env, 2)); // nil
    goto v0018;

v0018:
    if (v0011 == nil) goto v0019;
    v0011 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0011); }

v0019:
    v0011 = stack[0];
    if (!consp(v0011)) goto v0020;
    v0011 = stack[0];
    v0011 = qcar(v0011);
    if (!symbolp(v0011)) v0011 = nil;
    else { v0011 = qfastgets(v0011);
           if (v0011 != nil) { v0011 = elt(v0011, 16); // indexvar
#ifdef RECORD_GET
             if (v0011 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0011 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0011 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0011 == SPID_NOPROP) v0011 = nil; else v0011 = lisp_true; }}
#endif
    if (v0011 == nil) goto v0021;
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    v0012 = Llength(nil, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0011 = stack[0];
    v0011 = qcar(v0011);
    if (!symbolp(v0011)) v0011 = nil;
    else { v0011 = qfastgets(v0011);
           if (v0011 != nil) { v0011 = elt(v0011, 25); // ifdegree
#ifdef RECORD_GET
             if (v0011 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v0011 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v0011 == SPID_NOPROP) v0011 = nil; }}
#endif
    v0011 = Lassoc(nil, v0012, v0011);
    { popv(2); return onevalue(v0011); }

v0021:
    v0011 = stack[0];
    v0012 = qcar(v0011);
    v0011 = elt(env, 4); // !*sq
    if (v0012 == v0011) goto v0023;
    v0011 = stack[0];
    v0012 = qcar(v0011);
    v0011 = elt(env, 5); // (wedge d partdf hodge innerprod liedf)
    v0011 = Lmemq(nil, v0012, v0011);
    if (v0011 == nil) goto v0024;
    v0011 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0011); }

v0024:
    v0011 = stack[0];
    v0011 = qcar(v0011);
    if (!symbolp(v0011)) v0011 = nil;
    else { v0011 = qfastgets(v0011);
           if (v0011 != nil) { v0011 = elt(v0011, 8); // dname
#ifdef RECORD_GET
             if (v0011 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0011 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0011 == SPID_NOPROP) v0011 = nil; }}
#endif
    if (v0011 == nil) goto v0025;
    v0011 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0011); }

v0025:
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    fn = elt(env, 6); // lexformp
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0012 = v0011;
    if (!(v0011 == nil)) { popv(2); return onevalue(v0012); }
    v0011 = stack[0];
    v0011 = qcar(v0011);
    v0011 = CC_exformp(env, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0012 = v0011;
    if (!(v0011 == nil)) { popv(2); return onevalue(v0012); }
    v0011 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0011); }

v0023:
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    v0011 = qcar(v0011);
    fn = elt(env, 7); // prepsq
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    stack[0] = v0011;
    goto v0013;

v0020:
    v0011 = stack[0];
    if (!symbolp(v0011)) v0011 = nil;
    else { v0011 = qfastgets(v0011);
           if (v0011 != nil) { v0011 = elt(v0011, 29); // fdegree
#ifdef RECORD_GET
             if (v0011 != SPID_NOPROP)
                record_get(elt(fastget_names, 29), 1);
             else record_get(elt(fastget_names, 29), 0),
                v0011 = nil; }
           else record_get(elt(fastget_names, 29), 0); }
#else
             if (v0011 == SPID_NOPROP) v0011 = nil; }}
#endif
    { popv(2); return onevalue(v0011); }

v0017:
    v0012 = stack[0];
    v0011 = qvalue(elt(env, 3)); // frlis!*
    v0011 = Lmemq(nil, v0012, v0011);
    goto v0018;

v0014:
    v0011 = qvalue(elt(env, 1)); // t
    goto v0015;
// error exit handlers
v0022:
    popv(2);
    return nil;
}



// Code for gffplus

static LispObject CC_gffplus(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0031, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gffplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0026;
    stack[-1] = v0000;
// end of prologue
    v0031 = stack[-1];
    v0032 = qcar(v0031);
    v0031 = stack[0];
    v0031 = qcar(v0031);
    stack[-2] = plus2(v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    v0031 = stack[-1];
    v0032 = qcdr(v0031);
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    v0031 = plus2(v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    {
        LispObject v0033 = stack[-2];
        popv(4);
        return cons(v0033, v0031);
    }
// error exit handlers
v0009:
    popv(4);
    return nil;
}



// Code for mk_edge_name

static LispObject CC_mk_edge_name(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_edge_name");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0026;
    stack[0] = v0000;
// end of prologue
    v0018 = qvalue(elt(env, 1)); // n_edge
    v0018 = add1(v0018);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0018; // n_edge
    v0018 = stack[0];
    stack[-2] = Lexplode(nil, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0018 = qvalue(elt(env, 1)); // n_edge
    stack[0] = Lexplode(nil, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0018 = stack[-1];
    v0018 = Lexplode(nil, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0018 = Lappend(nil, stack[0], v0018);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0018 = Lappend(nil, stack[-2], v0018);
    nil = C_nil;
    if (exception_pending()) goto v0017;
        popv(4);
        return Lcompress(nil, v0018);
// error exit handlers
v0017:
    popv(4);
    return nil;
}



// Code for set_rules

static LispObject CC_set_rules(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0057, v0058, v0059;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set_rules");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0026;
    v0057 = v0000;
// end of prologue
    stack[-6] = qvalue(elt(env, 1)); // !*resimp
    qvalue(elt(env, 1)) = nil; // !*resimp
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = v0057;
    goto v0014;

v0014:
    v0057 = stack[-1];
    if (v0057 == nil) goto v0060;
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    stack[0] = v0057;
    v0058 = stack[0];
    v0057 = elt(env, 3); // replaceby
    if (!consp(v0058)) goto v0028;
    v0058 = qcar(v0058);
    if (!(v0058 == v0057)) goto v0028;
    v0058 = stack[0];
    v0057 = stack[-3];
    v0057 = cons(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    stack[-3] = v0057;
    goto v0018;

v0018:
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    goto v0014;

v0028:
    v0057 = stack[-5];
    if (v0057 == nil) goto v0062;
    v0057 = qvalue(elt(env, 2)); // nil
    goto v0063;

v0063:
    if (v0057 == nil) goto v0064;
    v0057 = elt(env, 5); // "Please use => instead of = in rules"
    fn = elt(env, 8); // lprim
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    v0059 = elt(env, 3); // replaceby
    v0057 = stack[0];
    v0058 = qcdr(v0057);
    v0057 = stack[-3];
    v0057 = acons(v0059, v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    stack[-3] = v0057;
    goto v0018;

v0064:
    v0057 = stack[0];
    fn = elt(env, 9); // validrule
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    stack[-4] = v0057;
    if (!(v0057 == nil)) goto v0065;
    v0057 = stack[0];
    if (!(symbolp(v0057))) goto v0022;
    v0057 = stack[0];
    fn = elt(env, 10); // reval
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    fn = elt(env, 9); // validrule
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    stack[-4] = v0057;
    if (!(v0057 == nil)) goto v0065;

v0022:
    v0058 = stack[0];
    v0057 = elt(env, 7); // "rule list"
    fn = elt(env, 11); // typerr
    v0057 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    goto v0018;

v0065:
    v0057 = stack[-4];
    v0057 = qcar(v0057);
    v0057 = Lreverse(nil, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    stack[-4] = v0057;
    if (v0057 == nil) goto v0018;
    v0058 = stack[-4];
    v0057 = qvalue(elt(env, 6)); // t
    fn = elt(env, 12); // rule!-list
    v0057 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    v0058 = stack[-4];
    v0057 = stack[-2];
    v0057 = cons(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    stack[-2] = v0057;
    goto v0018;

v0062:
    v0058 = stack[0];
    v0057 = elt(env, 4); // equal
    v0057 = Leqcar(nil, v0058, v0057);
    env = stack[-7];
    goto v0063;

v0060:
    v0058 = stack[-3];
    v0057 = qvalue(elt(env, 6)); // t
    fn = elt(env, 12); // rule!-list
    v0057 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    v0058 = stack[-3];
    v0057 = stack[-2];
    v0057 = cons(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; // !*resimp
    { popv(8); return onevalue(v0057); }
// error exit handlers
v0061:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; // !*resimp
    popv(8);
    return nil;
}



// Code for canonical

static LispObject CC_canonical(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0072, v0073;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for canonical");
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
    stack[0] = qvalue(elt(env, 1)); // !*distribute
    qvalue(elt(env, 1)) = nil; // !*distribute
    v0072 = qvalue(elt(env, 2)); // nil
    stack[-1] = v0072;
    v0072 = stack[-2];
    v0072 = qcar(v0072);
    fn = elt(env, 6); // simp!*
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-2] = v0072;
    v0072 = stack[-2];
    v0072 = qcdr(v0072);
    stack[-3] = v0072;
    v0072 = elt(env, 3); // distribute
    v0072 = ncons(v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    fn = elt(env, 7); // on
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0072 = stack[-2];
    v0072 = qcar(v0072);
    fn = elt(env, 8); // distri_pol
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-2] = v0072;
    goto v0019;

v0019:
    v0072 = stack[-2];
    if (!consp(v0072)) goto v0031;
    v0072 = stack[-2];
    v0072 = qcar(v0072);
    v0072 = (consp(v0072) ? nil : lisp_true);
    goto v0017;

v0017:
    if (v0072 == nil) goto v0056;
    v0073 = stack[-1];
    v0072 = stack[-2];
    fn = elt(env, 9); // addf
    v0072 = (*qfn2(fn))(qenv(fn), v0073, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-1] = v0072;
    stack[-2] = elt(env, 5); // !*sq
    v0073 = stack[-1];
    v0072 = stack[-3];
    v0073 = cons(v0073, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0072 = qvalue(elt(env, 2)); // nil
    v0072 = list3(stack[-2], v0073, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    fn = elt(env, 6); // simp!*
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; // !*distribute
    { popv(5); return onevalue(v0072); }

v0056:
    v0072 = stack[-2];
    v0072 = qcar(v0072);
    v0072 = ncons(v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    fn = elt(env, 10); // dv_canon_monomial
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    fn = elt(env, 9); // addf
    v0072 = (*qfn2(fn))(qenv(fn), stack[-1], v0072);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-1] = v0072;
    v0072 = stack[-2];
    v0072 = qcdr(v0072);
    stack[-2] = v0072;
    goto v0019;

v0031:
    v0072 = qvalue(elt(env, 4)); // t
    goto v0017;
// error exit handlers
v0074:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; // !*distribute
    popv(5);
    return nil;
}



// Code for general!-quotient!-mod!-p

static LispObject CC_generalKquotientKmodKp(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0039, v0057, v0058;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-quotient-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0026;
    stack[-1] = v0000;
// end of prologue
    v0039 = stack[0];
    if (v0039 == nil) goto v0013;
    v0039 = stack[0];
    if (!consp(v0039)) goto v0034;
    v0039 = stack[0];
    v0039 = qcar(v0039);
    v0039 = (consp(v0039) ? nil : lisp_true);
    goto v0082;

v0082:
    if (v0039 == nil) goto v0015;
    v0039 = stack[0];
    fn = elt(env, 5); // general!-modular!-reciprocal
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    {
        LispObject v0084 = stack[-1];
        popv(4);
        fn = elt(env, 6); // general!-multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0084, v0039);
    }

v0015:
    v0039 = stack[-1];
    if (v0039 == nil) goto v0085;
    v0039 = stack[-1];
    if (!consp(v0039)) goto v0020;
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = (consp(v0039) ? nil : lisp_true);
    goto v0086;

v0086:
    if (v0039 == nil) goto v0087;
    v0039 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0039; // exact!-quotient!-flag
    { popv(4); return onevalue(v0039); }

v0087:
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0057 = qcar(v0039);
    v0039 = stack[0];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    if (equal(v0057, v0039)) goto v0088;
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0057 = qcar(v0039);
    v0039 = stack[0];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    fn = elt(env, 7); // ordop
    v0039 = (*qfn2(fn))(qenv(fn), v0057, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    if (v0039 == nil) goto v0089;
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0057 = qcdr(v0039);
    v0039 = stack[0];
    stack[-2] = CC_generalKquotientKmodKp(env, v0057, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    v0039 = stack[-1];
    v0057 = qcdr(v0039);
    v0039 = stack[0];
    v0039 = CC_generalKquotientKmodKp(env, v0057, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    v0057 = stack[-2];
    v0058 = v0057;
    if (v0058 == nil) { popv(4); return onevalue(v0039); }
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    popv(4);
    return acons(v0058, v0057, v0039);

v0089:
    v0039 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0039; // exact!-quotient!-flag
    { popv(4); return onevalue(v0039); }

v0088:
    v0058 = stack[-1];
    v0057 = stack[0];
    v0039 = stack[0];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    {
        popv(4);
        fn = elt(env, 8); // general!-xquotient!-mod!-p
        return (*qfnn(fn))(qenv(fn), 3, v0058, v0057, v0039);
    }

v0020:
    v0039 = qvalue(elt(env, 2)); // t
    goto v0086;

v0085:
    v0039 = qvalue(elt(env, 3)); // nil
    { popv(4); return onevalue(v0039); }

v0034:
    v0039 = qvalue(elt(env, 2)); // t
    goto v0082;

v0013:
    v0039 = elt(env, 1); // "B=0 IN GENERAL-QUOTIENT-MOD-P"
    {
        popv(4);
        fn = elt(env, 9); // errorf
        return (*qfn1(fn))(qenv(fn), v0039);
    }
// error exit handlers
v0083:
    popv(4);
    return nil;
}



// Code for simpsqrt

static LispObject CC_simpsqrt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0096, v0097, v0098;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpsqrt");
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
    v0098 = v0000;
// end of prologue
    v0097 = v0098;
    v0096 = (LispObject)1; // 0
    if (v0097 == v0096) goto v0034;
    v0096 = qvalue(elt(env, 2)); // !*keepsqrts
    if (v0096 == nil) goto v0099;
    v0096 = v0098;
    v0096 = qcar(v0096);
    fn = elt(env, 7); // xsimp
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    stack[-1] = v0096;
    v0096 = stack[-1];
    v0096 = qcar(v0096);
    if (v0096 == nil) goto v0101;
    v0096 = stack[-1];
    v0097 = qcdr(v0096);
    v0096 = (LispObject)17; // 1
    if (v0097 == v0096) goto v0021;
    v0096 = qvalue(elt(env, 1)); // nil
    goto v0102;

v0102:
    if (v0096 == nil) goto v0103;
    v0096 = stack[-1];
    v0097 = qcar(v0096);
    v0096 = (LispObject)-15; // -1
    if (v0097 == v0096) goto v0104;
    v0096 = elt(env, 5); // i
    fn = elt(env, 8); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0096 = stack[-1];
    v0096 = qcar(v0096);
    fn = elt(env, 9); // !:minus
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    fn = elt(env, 10); // prepd
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0096 = CC_simpsqrt(env, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    {
        LispObject v0105 = stack[0];
        popv(3);
        fn = elt(env, 11); // multsq
        return (*qfn2(fn))(qenv(fn), v0105, v0096);
    }

v0104:
    v0096 = elt(env, 5); // i
    {
        popv(3);
        fn = elt(env, 8); // simp
        return (*qfn1(fn))(qenv(fn), v0096);
    }

v0103:
    stack[0] = elt(env, 6); // sqrt
    v0096 = stack[-1];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    fn = elt(env, 12); // domainvalchk
    v0096 = (*qfn2(fn))(qenv(fn), stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0097 = v0096;
    if (!(v0096 == nil)) { popv(3); return onevalue(v0097); }
    v0097 = stack[-1];
    v0096 = (LispObject)33; // 2
    {
        popv(3);
        fn = elt(env, 13); // simprad
        return (*qfn2(fn))(qenv(fn), v0097, v0096);
    }

v0021:
    v0096 = stack[-1];
    v0096 = qcar(v0096);
    if (!consp(v0096)) goto v0072;
    v0096 = stack[-1];
    v0096 = qcar(v0096);
    v0096 = qcar(v0096);
    v0096 = (consp(v0096) ? nil : lisp_true);
    goto v0066;

v0066:
    if (v0096 == nil) goto v0025;
    v0096 = stack[-1];
    v0096 = qcar(v0096);
    fn = elt(env, 14); // !:minusp
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    goto v0102;

v0025:
    v0096 = qvalue(elt(env, 1)); // nil
    goto v0102;

v0072:
    v0096 = qvalue(elt(env, 4)); // t
    goto v0066;

v0101:
    v0097 = qvalue(elt(env, 1)); // nil
    v0096 = (LispObject)17; // 1
    popv(3);
    return cons(v0097, v0096);

v0099:
    v0096 = v0098;
    stack[0] = qcar(v0096);
    v0096 = elt(env, 3); // (quotient 1 2)
    fn = elt(env, 15); // simpexpon
    v0097 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0096 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0106 = stack[0];
        popv(3);
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(qenv(fn), 3, v0106, v0097, v0096);
    }

v0034:
    v0097 = qvalue(elt(env, 1)); // nil
    v0096 = (LispObject)17; // 1
    popv(3);
    return cons(v0097, v0096);
// error exit handlers
v0100:
    popv(3);
    return nil;
}



// Code for find!-non!-zero

static LispObject CC_findKnonKzero(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0053, v0054;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find-non-zero");
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
    v0006 = (LispObject)17; // 1
    stack[0] = v0006;
    goto v0036;

v0036:
    v0006 = (LispObject)17; // 1
    v0054 = v0006;
    v0006 = stack[-1];
    v0006 = qcar(v0006);
    stack[-2] = v0006;
    goto v0027;

v0027:
    v0006 = stack[-2];
    v0053 = qcar(v0006);
    v0006 = (LispObject)1; // 0
    if (v0053 == v0006) goto v0029;
    v0006 = stack[0];
    v0053 = v0054;
    popv(4);
    return cons(v0006, v0053);

v0029:
    v0006 = stack[-2];
    v0006 = qcdr(v0006);
    stack[-2] = v0006;
    v0006 = v0054;
    v0006 = add1(v0006);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0054 = v0006;
    v0006 = stack[-2];
    if (!(v0006 == nil)) goto v0027;
    v0006 = stack[-1];
    v0006 = qcdr(v0006);
    stack[-1] = v0006;
    v0006 = stack[0];
    v0006 = add1(v0006);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    stack[0] = v0006;
    v0006 = stack[-1];
    if (!(v0006 == nil)) goto v0036;
    v0006 = elt(env, 0); // find!-non!-zero
    fn = elt(env, 1); // confusion
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    goto v0036;
// error exit handlers
v0107:
    popv(4);
    return nil;
}



// Code for pasf_mkop

static LispObject CC_pasf_mkop(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0095, v0109, v0081, v0086;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_mkop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0081 = v0026;
    v0086 = v0000;
// end of prologue
    v0109 = v0086;
    v0095 = elt(env, 1); // (cong ncong)
    v0095 = Lmemq(nil, v0109, v0095);
    if (v0095 == nil) { popv(2); return onevalue(v0086); }
    stack[0] = v0086;
    v0095 = v0081;
    if (v0095 == nil) goto v0018;
    v0095 = v0081;
    goto v0027;

v0027:
    {
        LispObject v0055 = stack[0];
        popv(2);
        return cons(v0055, v0095);
    }

v0018:
    v0095 = elt(env, 2); // "Modulo 0 congruence created"
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-1];
    fn = elt(env, 3); // rederr
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    goto v0027;
// error exit handlers
v0056:
    popv(2);
    return nil;
}



// Code for iv_congp

static LispObject CC_iv_congp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0110, v0030;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for iv_congp");
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
    v0110 = v0000;
// end of prologue

v0111:
    v0030 = v0110;
    if (v0030 == nil) goto v0013;
    v0030 = v0110;
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    v0030 = Lconsp(nil, v0030);
    env = stack[0];
    if (!(v0030 == nil)) { popv(1); return onevalue(v0030); }
    v0110 = qcdr(v0110);
    goto v0111;

v0013:
    v0110 = nil;
    { popv(1); return onevalue(v0110); }
}



// Code for aex_sgn

static LispObject CC_aex_sgn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0124, v0125;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_sgn");
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
    stack[0] = v0000;
// end of prologue
    v0124 = stack[0];
    fn = elt(env, 6); // aex_simpleratp
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    if (v0124 == nil) goto v0029;
    v0124 = stack[0];
    fn = elt(env, 7); // aex_ex
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 8); // rat_sgn
        return (*qfn1(fn))(qenv(fn), v0124);
    }

v0029:
    v0124 = qvalue(elt(env, 2)); // !*rlanuexsgnopt
    if (v0124 == nil) goto v0099;
    v0124 = stack[0];
    fn = elt(env, 9); // aex_containment
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    stack[-2] = v0124;
    fn = elt(env, 10); // rat_0
    stack[-1] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0124 = stack[-2];
    fn = elt(env, 11); // iv_lb
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 12); // rat_less
    v0124 = (*qfn2(fn))(qenv(fn), stack[-1], v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    if (v0124 == nil) goto v0127;
    v0124 = (LispObject)17; // 1
    { popv(6); return onevalue(v0124); }

v0127:
    v0124 = stack[-2];
    fn = elt(env, 13); // iv_rb
    stack[-1] = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 10); // rat_0
    v0124 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 12); // rat_less
    v0124 = (*qfn2(fn))(qenv(fn), stack[-1], v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    if (v0124 == nil) goto v0099;
    v0124 = (LispObject)-15; // -1
    { popv(6); return onevalue(v0124); }

v0099:
    v0124 = stack[0];
    fn = elt(env, 14); // aex_mvar
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    stack[-4] = v0124;
    v0124 = stack[0];
    fn = elt(env, 15); // aex_ctx
    v0125 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0124 = stack[-4];
    fn = elt(env, 16); // ctx_get
    v0124 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    stack[-3] = v0124;
    v0125 = stack[0];
    v0124 = stack[-4];
    fn = elt(env, 17); // aex_unbind
    v0124 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 18); // aex_reduce
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 19); // aex_mklcnt
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    stack[-1] = v0124;
    v0124 = stack[-1];
    fn = elt(env, 6); // aex_simpleratp
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    if (v0124 == nil) goto v0073;
    v0124 = stack[-1];
    fn = elt(env, 7); // aex_ex
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 8); // rat_sgn
        return (*qfn1(fn))(qenv(fn), v0124);
    }

v0073:
    v0124 = qvalue(elt(env, 3)); // !*rlverbose
    if (v0124 == nil) goto v0080;
    v0124 = qvalue(elt(env, 4)); // !*rlanuexverbose
    if (v0124 == nil) goto v0080;
    v0125 = stack[-1];
    v0124 = stack[-4];
    fn = elt(env, 20); // aex_deg
    v0125 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0124 = (LispObject)1; // 0
    v0124 = (LispObject)lesseq2(v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    v0124 = v0124 ? lisp_true : nil;
    env = stack[-5];
    if (v0124 == nil) goto v0080;
    v0124 = elt(env, 5); // "[aex_sgn:num!]"
    v0124 = Lprinc(nil, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    goto v0080;

v0080:
    v0124 = stack[-3];
    fn = elt(env, 21); // anu_dp
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    stack[0] = v0124;
    v0125 = v0124;
    v0124 = stack[-4];
    fn = elt(env, 22); // aex_diff
    v0125 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0124 = stack[-1];
    fn = elt(env, 23); // aex_mult
    v0125 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    v0124 = stack[-4];
    fn = elt(env, 24); // aex_sturmchain
    v0124 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    stack[-2] = v0124;
    stack[-1] = stack[-2];
    stack[0] = stack[-4];
    v0124 = stack[-3];
    fn = elt(env, 25); // anu_iv
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 11); // iv_lb
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 26); // aex_stchsgnch1
    stack[0] = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    stack[-1] = stack[-2];
    stack[-2] = stack[-4];
    v0124 = stack[-3];
    fn = elt(env, 25); // anu_iv
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 13); // iv_rb
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-5];
    fn = elt(env, 26); // aex_stchsgnch1
    v0124 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-2], v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    {
        LispObject v0128 = stack[0];
        popv(6);
        return difference2(v0128, v0124);
    }
// error exit handlers
v0126:
    popv(6);
    return nil;
}



// Code for cgp_comp

static LispObject CC_cgp_comp(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0082;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_comp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0026;
    v0082 = v0000;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    stack[-1] = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0082 = stack[0];
    fn = elt(env, 1); // cgp_rp
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    {
        LispObject v0110 = stack[-1];
        popv(3);
        fn = elt(env, 2); // dip_comp
        return (*qfn2(fn))(qenv(fn), v0110, v0082);
    }
// error exit handlers
v0029:
    popv(3);
    return nil;
}



// Code for log!:

static LispObject CC_logT(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0197, v0198, v0199;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-10] = v0026;
    stack[0] = v0000;
// end of prologue
    v0197 = stack[0];
    fn = elt(env, 8); // minusp!:
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    if (!(v0197 == nil)) goto v0013;
    v0197 = stack[0];
    fn = elt(env, 9); // bfzerop!:
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    if (!(v0197 == nil)) goto v0013;
    v0197 = stack[-10];
    v0197 = integerp(v0197);
    if (v0197 == nil) goto v0110;
    v0198 = stack[-10];
    v0197 = (LispObject)1; // 0
    v0197 = (LispObject)lesseq2(v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    v0197 = v0197 ? lisp_true : nil;
    env = stack[-12];
    goto v0029;

v0029:
    if (!(v0197 == nil)) goto v0013;
    v0198 = stack[0];
    v0197 = qvalue(elt(env, 2)); // bfone!*
    fn = elt(env, 10); // equal!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    if (v0197 == nil) goto v0069;
    v0197 = qvalue(elt(env, 3)); // bfz!*
    { popv(13); return onevalue(v0197); }

v0069:
    v0198 = stack[-10];
    v0197 = (LispObject)113; // 7
    v0197 = plus2(v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-11] = v0197;
    v0197 = stack[-11];
    fn = elt(env, 11); // !:e
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-2] = v0197;
    v0197 = stack[-11];
    fn = elt(env, 12); // !:e0625
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-1] = v0197;
    v0198 = stack[0];
    v0197 = qvalue(elt(env, 2)); // bfone!*
    fn = elt(env, 13); // greaterp!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    if (v0197 == nil) goto v0002;
    v0197 = qvalue(elt(env, 2)); // bfone!*
    stack[-8] = v0197;
    v0197 = stack[0];
    stack[-6] = v0197;
    goto v0201;

v0201:
    v0198 = stack[-6];
    v0197 = stack[-2];
    fn = elt(env, 14); // lessp!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    if (v0197 == nil) goto v0042;
    v0197 = (LispObject)1; // 0
    stack[-9] = v0197;
    v0197 = stack[-6];
    stack[-5] = v0197;
    goto v0202;

v0202:
    v0199 = elt(env, 6); // !:rd!:
    v0198 = stack[-9];
    v0197 = (LispObject)1; // 0
    v0197 = list2star(v0199, v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-7] = v0197;
    v0197 = qvalue(elt(env, 7)); // !:bf!-0!.0625
    stack[-6] = v0197;
    goto v0203;

v0203:
    v0198 = stack[-5];
    v0197 = stack[-1];
    fn = elt(env, 13); // greaterp!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    if (v0197 == nil) goto v0204;
    v0198 = stack[-7];
    v0197 = stack[-6];
    fn = elt(env, 15); // plus!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-7] = v0197;
    v0199 = stack[-5];
    v0198 = stack[-1];
    v0197 = stack[-11];
    fn = elt(env, 16); // divide!:
    v0197 = (*qfnn(fn))(qenv(fn), 3, v0199, v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-5] = v0197;
    goto v0203;

v0204:
    v0198 = stack[-5];
    v0197 = qvalue(elt(env, 2)); // bfone!*
    fn = elt(env, 17); // difference!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-5] = v0197;
    v0197 = stack[-5];
    stack[-2] = v0197;
    stack[0] = v0197;
    stack[-6] = v0197;
    v0197 = stack[-5];
    fn = elt(env, 18); // minus!:
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-5] = v0197;
    stack[-3] = elt(env, 6); // !:rd!:
    stack[-1] = (LispObject)33; // 2
    v0197 = stack[-11];
    v0197 = negate(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = list2star(stack[-3], stack[-1], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-3] = v0197;
    v0197 = (LispObject)17; // 1
    stack[-9] = v0197;
    goto v0205;

v0205:
    v0197 = stack[0];
    fn = elt(env, 19); // abs!:
    v0198 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = stack[-3];
    fn = elt(env, 13); // greaterp!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    if (v0197 == nil) goto v0206;
    v0198 = stack[-2];
    v0197 = stack[-5];
    fn = elt(env, 20); // times!:
    stack[0] = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = stack[-11];
    v0197 = negate(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    fn = elt(env, 21); // cut!:ep
    v0197 = (*qfn2(fn))(qenv(fn), stack[0], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-2] = v0197;
    stack[-1] = (LispObject)17; // 1
    stack[0] = stack[-11];
    v0197 = stack[-2];
    fn = elt(env, 22); // order!:
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = plus2(stack[0], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    fn = elt(env, 23); // max
    v0197 = (*qfn2(fn))(qenv(fn), stack[-1], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-4] = v0197;
    stack[-1] = stack[-2];
    stack[0] = elt(env, 6); // !:rd!:
    v0197 = stack[-9];
    v0198 = add1(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-9] = v0198;
    v0197 = (LispObject)1; // 0
    v0198 = list2star(stack[0], v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = stack[-4];
    fn = elt(env, 16); // divide!:
    v0197 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[0] = v0197;
    v0198 = stack[-6];
    v0197 = stack[0];
    fn = elt(env, 15); // plus!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-6] = v0197;
    v0198 = stack[-9];
    v0197 = (LispObject)161; // 10
    v0197 = Cremainder(v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = (LispObject)zerop(v0197);
    v0197 = v0197 ? lisp_true : nil;
    env = stack[-12];
    if (v0197 == nil) goto v0205;
    stack[-1] = stack[-6];
    v0197 = stack[-11];
    v0197 = negate(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    fn = elt(env, 21); // cut!:ep
    v0197 = (*qfn2(fn))(qenv(fn), stack[-1], v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-6] = v0197;
    goto v0205;

v0206:
    v0198 = stack[-6];
    v0197 = stack[-7];
    fn = elt(env, 15); // plus!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-6] = v0197;
    v0198 = stack[-8];
    v0197 = stack[-6];
    fn = elt(env, 20); // times!:
    v0198 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = stack[-10];
    {
        popv(13);
        fn = elt(env, 24); // round!:mt
        return (*qfn2(fn))(qenv(fn), v0198, v0197);
    }

v0042:
    v0197 = stack[-6];
    fn = elt(env, 22); // order!:
    v0198 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = (LispObject)1105; // 69
    v0198 = times2(v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    v0197 = (LispObject)1601; // 100
    v0198 = quot2(v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-9] = v0198;
    v0197 = (LispObject)1; // 0
    if (v0198 == v0197) goto v0207;
    v0197 = stack[-11];
    stack[0] = qvalue(elt(env, 4)); // !:bprec!:
    qvalue(elt(env, 4)) = v0197; // !:bprec!:
    stack[-3] = stack[-6];
    v0198 = stack[-2];
    v0197 = stack[-9];
    fn = elt(env, 25); // texpt!:
    v0198 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-12];
    v0197 = stack[-11];
    fn = elt(env, 16); // divide!:
    v0197 = (*qfnn(fn))(qenv(fn), 3, stack[-3], v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-12];
    stack[-5] = v0197;
    qvalue(elt(env, 4)) = stack[0]; // !:bprec!:
    goto v0113;

v0113:
    v0198 = stack[-5];
    v0197 = stack[-2];
    fn = elt(env, 13); // greaterp!:
    v0197 = (*qfn2(fn))(qenv(fn), v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    if (v0197 == nil) goto v0202;
    v0197 = stack[-9];
    v0197 = add1(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-9] = v0197;
    v0199 = stack[-5];
    v0198 = stack[-2];
    v0197 = stack[-11];
    fn = elt(env, 16); // divide!:
    v0197 = (*qfnn(fn))(qenv(fn), 3, v0199, v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-5] = v0197;
    goto v0113;

v0207:
    v0197 = stack[-6];
    stack[-5] = v0197;
    goto v0113;

v0002:
    v0197 = qvalue(elt(env, 2)); // bfone!*
    fn = elt(env, 18); // minus!:
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-8] = v0197;
    v0199 = qvalue(elt(env, 2)); // bfone!*
    v0198 = stack[0];
    v0197 = stack[-11];
    fn = elt(env, 16); // divide!:
    v0197 = (*qfnn(fn))(qenv(fn), 3, v0199, v0198, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-12];
    stack[-6] = v0197;
    goto v0201;

v0013:
    v0197 = elt(env, 0); // log!:
    {
        popv(13);
        fn = elt(env, 26); // bflerrmsg
        return (*qfn1(fn))(qenv(fn), v0197);
    }

v0110:
    v0197 = qvalue(elt(env, 1)); // t
    goto v0029;
// error exit handlers
v0208:
    env = stack[-12];
    qvalue(elt(env, 4)) = stack[0]; // !:bprec!:
    popv(13);
    return nil;
v0200:
    popv(13);
    return nil;
}



// Code for f2vdp

static LispObject CC_f2vdp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0072, v0073;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for f2vdp");
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
    v0073 = v0000;
// end of prologue
    v0072 = v0073;
    v0066 = (LispObject)1; // 0
    if (v0072 == v0066) goto v0209;
    v0066 = v0073;
    v0066 = (v0066 == nil ? lisp_true : nil);
    goto v0036;

v0036:
    if (v0066 == nil) goto v0127;
    stack[-2] = elt(env, 2); // vdp
    stack[-1] = qvalue(elt(env, 3)); // nil
    v0072 = qvalue(elt(env, 3)); // nil
    v0066 = (LispObject)17; // 1
    stack[0] = cons(v0072, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-3];
    v0072 = qvalue(elt(env, 3)); // nil
    v0066 = qvalue(elt(env, 3)); // nil
    v0066 = list2(v0072, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    {
        LispObject v0074 = stack[-2];
        LispObject v0210 = stack[-1];
        LispObject v0211 = stack[0];
        popv(4);
        return list3star(v0074, v0210, v0211, v0066);
    }

v0127:
    v0066 = v0073;
    fn = elt(env, 4); // f2dip
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-3];
    v0072 = v0066;
    stack[-2] = elt(env, 2); // vdp
    v0066 = v0072;
    stack[-1] = qcar(v0066);
    v0066 = v0072;
    v0066 = qcdr(v0066);
    stack[0] = qcar(v0066);
    v0066 = qvalue(elt(env, 3)); // nil
    v0066 = list2(v0072, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    {
        LispObject v0212 = stack[-2];
        LispObject v0080 = stack[-1];
        LispObject v0213 = stack[0];
        popv(4);
        return list3star(v0212, v0080, v0213, v0066);
    }

v0209:
    v0066 = qvalue(elt(env, 1)); // t
    goto v0036;
// error exit handlers
v0002:
    popv(4);
    return nil;
}



// Code for evalsymsubset

static LispObject CC_evalsymsubset(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0215, v0043, v0044, v0216;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalsymsubset");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0215 = v0000;
// end of prologue
    v0043 = v0215;
    v0043 = qcar(v0043);
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    v0216 = v0043;
    v0044 = v0215;
    v0043 = v0044;
    v0215 = elt(env, 1); // union
    if (!consp(v0043)) goto v0008;
    v0043 = qcar(v0043);
    if (!(v0043 == v0215)) goto v0008;
    v0043 = v0216;
    v0215 = v0044;
    v0215 = qcdr(v0215);
    v0215 = Lmember(nil, v0043, v0215);
    goto v0082;

v0082:
    if (!(v0215 == nil)) return onevalue(v0215);
    v0043 = v0216;
    v0215 = elt(env, 3); // intersection
    if (!consp(v0043)) goto v0069;
    v0043 = qcar(v0043);
    if (!(v0043 == v0215)) goto v0069;
    v0043 = v0044;
    v0215 = v0216;
    v0215 = qcdr(v0215);
    v0215 = Lmember(nil, v0043, v0215);
    goto v0020;

v0020:
    if (!(v0215 == nil)) return onevalue(v0215);
    v0043 = v0216;
    v0215 = elt(env, 4); // setdiff
    if (!consp(v0043)) goto v0217;
    v0043 = qcar(v0043);
    if (!(v0043 == v0215)) goto v0217;
    v0215 = v0216;
    v0215 = qcdr(v0215);
    v0043 = qcar(v0215);
    v0215 = v0044;
    if (equal(v0043, v0215)) goto v0024;
    v0043 = v0044;
    v0215 = elt(env, 1); // union
    if (!consp(v0043)) goto v0012;
    v0043 = qcar(v0043);
    if (!(v0043 == v0215)) goto v0012;
    v0215 = v0216;
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    v0043 = v0044;
    v0043 = qcdr(v0043);
    v0215 = Lmember(nil, v0215, v0043);
    return onevalue(v0215);

v0012:
    v0215 = qvalue(elt(env, 2)); // nil
    return onevalue(v0215);

v0024:
    v0215 = qvalue(elt(env, 5)); // t
    return onevalue(v0215);

v0217:
    v0215 = qvalue(elt(env, 2)); // nil
    return onevalue(v0215);

v0069:
    v0215 = qvalue(elt(env, 2)); // nil
    goto v0020;

v0008:
    v0215 = qvalue(elt(env, 2)); // nil
    goto v0082;
}



// Code for bftimes

static LispObject CC_bftimes(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0028, v0071, v0017;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bftimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0071 = v0026;
    v0017 = v0000;
// end of prologue
    v0028 = v0017;
    if (!consp(v0028)) goto v0016;
    v0028 = v0017;
    {
        fn = elt(env, 1); // csl_timbf
        return (*qfn2(fn))(qenv(fn), v0028, v0071);
    }

v0016:
    v0028 = v0017;
    return times2(v0028, v0071);
}



// Code for compactf

static LispObject CC_compactf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0210, v0211, v0212;
    LispObject fn;
    LispObject v0070, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0026 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compactf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0070,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0070;
    stack[-2] = v0026;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0210 = (LispObject)1; // 0
    stack[0] = v0210;
    v0210 = qvalue(elt(env, 1)); // !*trcompact
    if (v0210 == nil) goto v0194;
    v0210 = elt(env, 2); // "*** Arguments on entering compactf:"
    fn = elt(env, 6); // prin2t
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0211 = stack[-3];
    v0210 = (LispObject)17; // 1
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    fn = elt(env, 7); // mk!*sq
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    fn = elt(env, 8); // mathprint
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0211 = stack[-2];
    v0210 = (LispObject)17; // 1
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    fn = elt(env, 7); // mk!*sq
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    fn = elt(env, 8); // mathprint
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    goto v0194;

v0194:
    v0211 = stack[-4];
    v0210 = stack[-3];
    if (equal(v0211, v0210)) goto v0109;
    v0210 = stack[-3];
    stack[-4] = v0210;
    v0212 = stack[-3];
    v0211 = stack[-2];
    v0210 = stack[-1];
    fn = elt(env, 9); // compactf0
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    stack[-3] = v0210;
    v0210 = stack[0];
    v0210 = add1(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    stack[0] = v0210;
    goto v0194;

v0109:
    v0210 = qvalue(elt(env, 1)); // !*trcompact
    if (v0210 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0211 = stack[0];
    v0210 = (LispObject)33; // 2
    v0210 = (LispObject)greaterp2(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    v0210 = v0210 ? lisp_true : nil;
    env = stack[-5];
    if (v0210 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0210 = elt(env, 4); // " *** Compactf looped "
    v0210 = Lprinc(nil, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0210 = stack[0];
    v0210 = Lprinc(nil, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0210 = elt(env, 5); // " times"
    fn = elt(env, 6); // prin2t
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    { LispObject res = stack[-3]; popv(6); return onevalue(res); }
// error exit handlers
v0079:
    popv(6);
    return nil;
}



// Code for pst_equitable1

static LispObject CC_pst_equitable1(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0144, v0240, v0241;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_equitable1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-8] = v0026;
    stack[-9] = v0000;
// end of prologue
    v0144 = stack[-8];
    if (v0144 == nil) goto v0108;
    v0144 = stack[-9];
    stack[-3] = v0144;
    v0144 = stack[-9];
    v0144 = Llength(nil, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-2] = v0144;
    v0144 = stack[-8];
    v0144 = qcdr(v0144);
    fn = elt(env, 2); // upbve
    v0240 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = stack[-2];
    v0144 = plus2(v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = sub1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = Lmkvect(nil, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-10] = v0144;
    v0144 = (LispObject)17; // 1
    stack[-4] = v0144;
    goto v0062;

v0062:
    v0144 = stack[-8];
    v0144 = qcdr(v0144);
    fn = elt(env, 2); // upbve
    v0240 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = stack[-4];
    v0144 = difference2(v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = Lminusp(nil, v0144);
    env = stack[-11];
    if (v0144 == nil) goto v0107;
    v0144 = stack[-8];
    v0144 = qcar(v0144);
    stack[-7] = v0144;
    v0144 = stack[-8];
    v0144 = qcdr(v0144);
    fn = elt(env, 2); // upbve
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = add1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-2] = v0144;
    goto v0243;

v0243:
    v0144 = stack[-10];
    fn = elt(env, 2); // upbve
    v0240 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = stack[-2];
    v0144 = difference2(v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = Lminusp(nil, v0144);
    env = stack[-11];
    if (v0144 == nil) goto v0244;
    v0144 = stack[-7];
    fn = elt(env, 3); // fullcopy
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-5] = v0144;
    v0144 = stack[-5];
    v0144 = Llength(nil, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-2] = v0144;
    v0144 = stack[-10];
    fn = elt(env, 2); // upbve
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[0] = v0144;
    goto v0119;

v0119:
    v0144 = stack[-7];
    if (v0144 == nil) goto v0245;
    v0240 = stack[-2];
    v0144 = stack[0];
    v0144 = (LispObject)lessp2(v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    v0144 = v0144 ? lisp_true : nil;
    env = stack[-11];
    if (v0144 == nil) goto v0245;
    v0144 = stack[-7];
    v0144 = qcar(v0144);
    stack[-6] = v0144;
    v0144 = stack[-7];
    v0144 = qcdr(v0144);
    stack[-7] = v0144;
    v0144 = qvalue(elt(env, 1)); // nil
    stack[-4] = v0144;
    v0144 = (LispObject)1; // 0
    stack[-2] = v0144;
    goto v0246;

v0246:
    v0144 = stack[-5];
    if (v0144 == nil) goto v0247;
    v0144 = stack[-5];
    v0144 = qcar(v0144);
    v0240 = v0144;
    v0144 = stack[-5];
    v0144 = qcdr(v0144);
    stack[-5] = v0144;
    v0144 = v0240;
    v0144 = qcdr(v0144);
    if (v0144 == nil) goto v0248;
    v0241 = v0240;
    v0240 = stack[-6];
    v0144 = stack[-10];
    fn = elt(env, 4); // pst_partition
    v0144 = (*qfnn(fn))(qenv(fn), 3, v0241, v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    goto v0249;

v0249:
    stack[-3] = v0144;
    v0144 = stack[-3];
    v0144 = Llength(nil, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-1] = v0144;
    v0240 = stack[-4];
    v0144 = stack[-3];
    v0144 = Lappend(nil, v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-4] = v0144;
    v0240 = stack[-2];
    v0144 = stack[-1];
    v0144 = plus2(v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-2] = v0144;
    v0240 = stack[-1];
    v0144 = (LispObject)33; // 2
    v0144 = (LispObject)geq2(v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    v0144 = v0144 ? lisp_true : nil;
    env = stack[-11];
    if (v0144 == nil) goto v0246;
    v0144 = stack[-3];
    v0240 = qcdr(v0144);
    v0144 = stack[-7];
    v0144 = Lappend(nil, v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-7] = v0144;
    goto v0246;

v0248:
    v0144 = v0240;
    v0144 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    goto v0249;

v0247:
    v0144 = stack[-4];
    stack[-5] = v0144;
    goto v0119;

v0245:
    stack[0] = stack[-5];
    v0144 = stack[-9];
    v0144 = Llength(nil, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = add1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    fn = elt(env, 5); // pnth
    v0144 = (*qfn2(fn))(qenv(fn), stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-4] = v0144;
    v0144 = stack[-8];
    fn = elt(env, 6); // pst_termnodep
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    if (!(v0144 == nil)) goto v0250;
    v0144 = (LispObject)17; // 1
    stack[-3] = v0144;
    goto v0251;

v0251:
    v0144 = stack[-8];
    v0144 = qcdr(v0144);
    fn = elt(env, 2); // upbve
    v0240 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = stack[-3];
    v0144 = difference2(v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = Lminusp(nil, v0144);
    env = stack[-11];
    if (!(v0144 == nil)) goto v0250;
    v0144 = stack[-8];
    stack[0] = qcdr(v0144);
    v0144 = stack[-3];
    v0144 = sub1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0144/(16/CELL)));
    stack[-5] = v0144;
    v0144 = stack[-8];
    stack[-2] = qcdr(v0144);
    v0144 = stack[-3];
    stack[-1] = sub1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = stack[-5];
    stack[0] = qcar(v0144);
    v0240 = stack[-9];
    v0144 = stack[-5];
    v0144 = qcdr(v0144);
    v0144 = CC_pst_equitable1(env, v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = cons(stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0144;
    v0144 = stack[-3];
    v0144 = add1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-3] = v0144;
    goto v0251;

v0250:
    v0240 = stack[-4];
    v0144 = stack[-8];
    v0144 = qcdr(v0144);
    popv(12);
    return cons(v0240, v0144);

v0244:
    stack[-1] = stack[-10];
    v0144 = stack[-2];
    stack[0] = sub1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = stack[-3];
    v0144 = qcar(v0144);
    v0144 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0144;
    v0144 = stack[-3];
    v0144 = qcdr(v0144);
    stack[-3] = v0144;
    v0144 = stack[-2];
    v0240 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = stack[-7];
    v0144 = cons(v0240, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-7] = v0144;
    v0144 = stack[-2];
    v0144 = add1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-2] = v0144;
    goto v0243;

v0107:
    stack[-2] = stack[-10];
    v0144 = stack[-4];
    stack[-1] = sub1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = stack[-8];
    stack[0] = qcdr(v0144);
    v0144 = stack[-4];
    v0144 = sub1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    v0144 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0144/(16/CELL)));
    v0144 = qcar(v0144);
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0144;
    v0144 = stack[-4];
    v0144 = add1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-11];
    stack[-4] = v0144;
    goto v0062;

v0108:
    v0144 = qvalue(elt(env, 1)); // nil
    { popv(12); return onevalue(v0144); }
// error exit handlers
v0242:
    popv(12);
    return nil;
}



// Code for form!-sum!-and!-product!-mod!-p

static LispObject CC_formKsumKandKproductKmodKp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0068, v0069, v0107;
    LispObject fn;
    LispObject v0070, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form-sum-and-product-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0026 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for form-sum-and-product-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0070,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0070;
    stack[-2] = v0026;
    stack[-3] = v0000;
// end of prologue
    v0068 = qvalue(elt(env, 1)); // polyzero
    stack[-4] = v0068;
    v0068 = (LispObject)17; // 1
    stack[0] = v0068;
    goto v0027;

v0027:
    v0069 = stack[-1];
    v0068 = stack[0];
    v0068 = difference2(v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-5];
    v0068 = Lminusp(nil, v0068);
    env = stack[-5];
    if (!(v0068 == nil)) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0069 = stack[-3];
    v0068 = stack[0];
    v0107 = *(LispObject *)((char *)v0069 + (CELL-TAG_VECTOR) + ((int32_t)v0068/(16/CELL)));
    v0069 = stack[-2];
    v0068 = stack[0];
    v0068 = *(LispObject *)((char *)v0069 + (CELL-TAG_VECTOR) + ((int32_t)v0068/(16/CELL)));
    fn = elt(env, 3); // times!-mod!-p
    v0069 = (*qfn2(fn))(qenv(fn), v0107, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-5];
    v0068 = stack[-4];
    fn = elt(env, 4); // plus!-mod!-p
    v0068 = (*qfn2(fn))(qenv(fn), v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-5];
    stack[-4] = v0068;
    v0068 = stack[0];
    v0068 = add1(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-5];
    stack[0] = v0068;
    goto v0027;
// error exit handlers
v0122:
    popv(6);
    return nil;
}



// Code for qqe_clause!-update!-lengths

static LispObject CC_qqe_clauseKupdateKlengths(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0014, v0082;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_clause-update-lengths");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0014 = v0026;
    v0082 = v0000;
// end of prologue
    fn = elt(env, 1); // qqe_length!-graph!-clause
    v0014 = (*qfn2(fn))(qenv(fn), v0082, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // qqe_length!-graph!-update!-lengths
        return (*qfn1(fn))(qenv(fn), v0014);
    }
// error exit handlers
v0034:
    popv(1);
    return nil;
}



// Code for division!-test

static LispObject CC_divisionKtest(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0017, v0031;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for division-test");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0026;
    stack[-1] = v0000;
// end of prologue

v0013:
    v0017 = stack[0];
    if (v0017 == nil) goto v0209;
    v0017 = stack[0];
    v0031 = qcar(v0017);
    v0017 = stack[-1];
    fn = elt(env, 3); // quotf
    v0017 = (*qfn2(fn))(qenv(fn), v0031, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    if (v0017 == nil) goto v0014;
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    stack[0] = v0017;
    goto v0013;

v0014:
    v0017 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0017); }

v0209:
    v0017 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0017); }
// error exit handlers
v0085:
    popv(3);
    return nil;
}



// Code for xvarlistp

static LispObject CC_xvarlistp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xvarlistp");
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

v0111:
    v0007 = stack[0];
    if (v0007 == nil) goto v0047;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 3); // xvarp
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    if (v0007 == nil) goto v0014;
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0111;

v0014:
    v0007 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0007); }

v0047:
    v0007 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0007); }
// error exit handlers
v0099:
    popv(2);
    return nil;
}



// Code for mk_spec_atlas

static LispObject CC_mk_spec_atlas(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0099, v0028;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_spec_atlas");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0026;
    stack[-1] = v0000;
// end of prologue
    v0099 = stack[-1];
    fn = elt(env, 1); // atlas_edges
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    stack[-2] = v0099;
    fn = elt(env, 2); // edges_parents
    v0028 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    v0099 = stack[0];
    fn = elt(env, 3); // diff_edges
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0099 = stack[-1];
    {
        LispObject v0196 = stack[-2];
        popv(4);
        return acons(v0196, v0028, v0099);
    }
// error exit handlers
v0032:
    popv(4);
    return nil;
}



// Code for mv!-reduced!-coeffs

static LispObject CC_mvKreducedKcoeffs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0102, v0021, v0193;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-reduced-coeffs");
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
    v0102 = stack[0];
    v0102 = qcar(v0102);
    v0102 = qcdr(v0102);
    v0193 = v0102;
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0082;

v0082:
    v0102 = stack[-1];
    if (v0102 == nil) goto v0052;
    v0021 = v0193;
    v0102 = (LispObject)17; // 1
    if (v0021 == v0102) goto v0052;
    v0021 = v0193;
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    v0102 = qcdr(v0102);
    v0102 = Lgcd(nil, v0021, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-2];
    v0193 = v0102;
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0082;

v0052:
    v0021 = v0193;
    v0102 = (LispObject)17; // 1
    if (v0021 == v0102) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0102 = stack[0];
    v0021 = v0193;
    {
        popv(3);
        fn = elt(env, 2); // mv!-!/
        return (*qfn2(fn))(qenv(fn), v0102, v0021);
    }
// error exit handlers
v0239:
    popv(3);
    return nil;
}



// Code for dv_null_first_kern

static LispObject CC_dv_null_first_kern(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0045, v0046, v0011;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_null_first_kern");
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
    v0046 = v0000;
// end of prologue
    v0045 = qvalue(elt(env, 1)); // nil
    stack[-5] = v0045;
    v0045 = v0046;
    fn = elt(env, 5); // pa_vect2list
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-6];
    stack[-3] = v0045;
    goto v0030;

v0030:
    v0045 = stack[-3];
    if (v0045 == nil) { LispObject res = stack[-5]; popv(7); return onevalue(res); }
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    stack[-2] = v0045;
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    if (v0045 == nil) goto v0032;
    v0045 = stack[-5];
    if (!(v0045 == nil)) goto v0032;
    v0045 = (LispObject)1; // 0
    stack[-4] = v0045;
    v0045 = (LispObject)17; // 1
    stack[-1] = v0045;
    goto v0127;

v0127:
    v0045 = qvalue(elt(env, 2)); // g_sc_ve
    fn = elt(env, 6); // upbve
    v0046 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-6];
    v0045 = stack[-1];
    v0045 = difference2(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-6];
    v0045 = Lminusp(nil, v0045);
    env = stack[-6];
    if (v0045 == nil) goto v0094;
    v0045 = stack[-4];
    v0045 = Loddp(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-6];
    if (v0045 == nil) goto v0032;
    v0045 = qvalue(elt(env, 4)); // t
    stack[-5] = v0045;
    goto v0032;

v0032:
    v0045 = stack[-3];
    v0045 = qcdr(v0045);
    stack[-3] = v0045;
    goto v0030;

v0094:
    stack[0] = qvalue(elt(env, 2)); // g_sc_ve
    v0045 = stack[-1];
    v0045 = sub1(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-6];
    v0045 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0045/(16/CELL)));
    v0045 = qcar(v0045);
    v0011 = v0045;
    v0046 = qcar(v0045);
    v0045 = elt(env, 3); // !-
    if (v0046 == v0045) goto v0001;
    v0045 = qvalue(elt(env, 1)); // nil
    goto v0021;

v0021:
    if (v0045 == nil) goto v0069;
    v0045 = stack[-4];
    v0045 = add1(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-6];
    stack[-4] = v0045;
    goto v0069;

v0069:
    v0045 = stack[-1];
    v0045 = add1(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-6];
    stack[-1] = v0045;
    goto v0127;

v0001:
    v0045 = stack[-2];
    v0045 = qcar(v0045);
    v0046 = v0011;
    v0045 = Lmember(nil, v0045, v0046);
    goto v0021;
// error exit handlers
v0215:
    popv(7);
    return nil;
}



// Code for xprint

static LispObject CC_xprint(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0238, v0215, v0043;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0026;
    stack[-2] = v0000;
// end of prologue
    v0238 = stack[-2];
    v0238 = qcdr(v0238);
    stack[-3] = v0238;
    v0238 = stack[-2];
    v0238 = qcar(v0238);
    stack[-2] = v0238;
    v0238 = stack[-3];
    fn = elt(env, 6); // kernlp
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    stack[0] = v0238;
    if (v0238 == nil) goto v0014;
    v0238 = stack[0];
    fn = elt(env, 7); // !:onep
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    if (!(v0238 == nil)) goto v0014;
    v0215 = stack[-3];
    v0238 = stack[0];
    fn = elt(env, 8); // quotf
    v0238 = (*qfn2(fn))(qenv(fn), v0215, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    stack[-3] = v0238;
    v0238 = stack[0];
    fn = elt(env, 9); // minusf
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    if (v0238 == nil) goto v0014;
    v0238 = elt(env, 1); // minus
    fn = elt(env, 10); // oprin
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    v0238 = stack[0];
    fn = elt(env, 11); // !:minus
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    stack[0] = v0238;
    v0238 = qvalue(elt(env, 2)); // nil
    stack[-1] = v0238;
    goto v0014;

v0014:
    v0238 = stack[-1];
    if (v0238 == nil) goto v0055;
    v0238 = elt(env, 3); // plus
    fn = elt(env, 10); // oprin
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    goto v0055;

v0055:
    v0238 = stack[0];
    if (v0238 == nil) goto v0140;
    v0238 = stack[0];
    fn = elt(env, 7); // !:onep
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    if (!(v0238 == nil)) goto v0140;
    v0238 = stack[0];
    if (!consp(v0238)) goto v0023;
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0238 = (consp(v0238) ? nil : lisp_true);
    goto v0107;

v0107:
    if (v0238 == nil) goto v0050;
    v0238 = stack[0];
    fn = elt(env, 12); // maprin
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    goto v0054;

v0054:
    v0238 = elt(env, 5); // times
    fn = elt(env, 10); // oprin
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    goto v0140;

v0140:
    v0238 = stack[-2];
    fn = elt(env, 13); // xprinp
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    v0238 = stack[-3];
    if (!consp(v0238)) goto v0213;
    v0238 = stack[-3];
    v0238 = qcar(v0238);
    v0238 = (consp(v0238) ? nil : lisp_true);
    goto v0080;

v0080:
    if (v0238 == nil) goto v0104;
    v0238 = stack[-3];
    fn = elt(env, 7); // !:onep
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    goto v0074;

v0074:
    if (!(v0238 == nil)) goto v0192;
    v0238 = elt(env, 5); // times
    fn = elt(env, 10); // oprin
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    v0043 = stack[-3];
    v0238 = stack[-3];
    v0215 = qcdr(v0238);
    v0238 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 14); // xprinf
    v0238 = (*qfnn(fn))(qenv(fn), 3, v0043, v0215, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    goto v0192;

v0192:
    v0238 = nil;
    { popv(5); return onevalue(v0238); }

v0104:
    v0238 = qvalue(elt(env, 2)); // nil
    goto v0074;

v0213:
    v0238 = qvalue(elt(env, 4)); // t
    goto v0080;

v0050:
    v0238 = stack[0];
    fn = elt(env, 15); // prin2!*
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    goto v0054;

v0023:
    v0238 = qvalue(elt(env, 4)); // t
    goto v0107;
// error exit handlers
v0060:
    popv(5);
    return nil;
}



// Code for algint!-subsublis

static LispObject CC_algintKsubsublis(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0075, v0077, v0089;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for algint-subsublis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0026;
    stack[-3] = v0000;
// end of prologue
    v0077 = stack[0];
    v0075 = stack[-3];
    v0075 = Lassoc(nil, v0077, v0075);
    v0077 = v0075;
    if (v0075 == nil) goto v0016;
    v0075 = v0077;
    v0075 = qcdr(v0075);
    { popv(6); return onevalue(v0075); }

v0016:
    v0075 = stack[0];
    if (!consp(v0075)) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    v0075 = stack[0];
    v0077 = qcar(v0075);
    v0075 = elt(env, 1); // !*sq
    if (v0077 == v0075) goto v0033;
    v0075 = stack[0];
    v0077 = qcar(v0075);
    v0075 = elt(env, 2); // subfunc
    v0075 = get(v0077, v0075);
    env = stack[-5];
    v0077 = v0075;
    if (v0075 == nil) goto v0066;
    v0089 = v0077;
    v0077 = stack[-3];
    v0075 = stack[0];
        popv(6);
        return Lapply2(nil, 3, v0089, v0077, v0075);

v0066:
    v0075 = stack[0];
    stack[-4] = v0075;
    v0075 = stack[-4];
    if (v0075 == nil) goto v0080;
    v0075 = stack[-4];
    v0075 = qcar(v0075);
    v0077 = stack[-3];
    v0075 = CC_algintKsubsublis(env, v0077, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0075 = ncons(v0075);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    stack[-1] = v0075;
    stack[-2] = v0075;
    goto v0074;

v0074:
    v0075 = stack[-4];
    v0075 = qcdr(v0075);
    stack[-4] = v0075;
    v0075 = stack[-4];
    if (v0075 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0075 = stack[-4];
    v0075 = qcar(v0075);
    v0077 = stack[-3];
    v0075 = CC_algintKsubsublis(env, v0077, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0075 = ncons(v0075);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0075 = Lrplacd(nil, stack[0], v0075);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-5];
    v0075 = stack[-1];
    v0075 = qcdr(v0075);
    stack[-1] = v0075;
    goto v0074;

v0080:
    v0075 = qvalue(elt(env, 3)); // nil
    { popv(6); return onevalue(v0075); }

v0033:
    stack[-1] = elt(env, 1); // !*sq
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0077 = qcar(v0075);
    v0075 = stack[-3];
    fn = elt(env, 4); // algint!-subsq
    v0077 = (*qfn2(fn))(qenv(fn), v0077, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcar(v0075);
    {
        LispObject v0119 = stack[-1];
        popv(6);
        return list3(v0119, v0077, v0075);
    }
// error exit handlers
v0059:
    popv(6);
    return nil;
}



// Code for general!-monic!-mod!-p

static LispObject CC_generalKmonicKmodKp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0088, v0122, v0239;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-monic-mod-p");
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
    v0239 = v0000;
// end of prologue
    v0088 = v0239;
    if (v0088 == nil) goto v0047;
    v0088 = v0239;
    if (!consp(v0088)) goto v0014;
    v0088 = v0239;
    v0088 = qcar(v0088);
    v0088 = (consp(v0088) ? nil : lisp_true);
    goto v0015;

v0015:
    if (v0088 == nil) goto v0018;
    v0088 = (LispObject)17; // 1
    { popv(2); return onevalue(v0088); }

v0018:
    v0088 = v0239;
    v0088 = qcar(v0088);
    v0122 = qcdr(v0088);
    v0088 = (LispObject)17; // 1
    if (v0122 == v0088) { popv(2); return onevalue(v0239); }
    v0088 = v0239;
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    if (!consp(v0088)) goto v0081;
    v0088 = v0239;
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    v0088 = (consp(v0088) ? nil : lisp_true);
    goto v0109;

v0109:
    if (v0088 == nil) goto v0009;
    stack[0] = v0239;
    v0088 = v0239;
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    fn = elt(env, 4); // general!-modular!-reciprocal
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    {
        LispObject v0003 = stack[0];
        popv(2);
        fn = elt(env, 5); // general!-multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0003, v0088);
    }

v0009:
    v0088 = elt(env, 3); // "LC NOT NUMERIC IN GENERAL-MONIC-MOD-P"
    {
        popv(2);
        fn = elt(env, 6); // errorf
        return (*qfn1(fn))(qenv(fn), v0088);
    }

v0081:
    v0088 = qvalue(elt(env, 2)); // t
    goto v0109;

v0014:
    v0088 = qvalue(elt(env, 2)); // t
    goto v0015;

v0047:
    v0088 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0088); }
// error exit handlers
v0004:
    popv(2);
    return nil;
}



// Code for fillin

static LispObject CC_fillin(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035, v0108;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fillin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0035 = v0000;
// end of prologue
    v0108 = v0035;
    if (v0108 == nil) goto v0047;
    v0108 = v0035;
    v0035 = qcar(v0035);
    v0035 = qcar(v0035);
    {
        fn = elt(env, 2); // fillin1
        return (*qfn2(fn))(qenv(fn), v0108, v0035);
    }

v0047:
    v0035 = qvalue(elt(env, 1)); // nil
    return onevalue(v0035);
}



// Code for elimpt_bvl

static LispObject CC_elimpt_bvl(LispObject env,
                         LispObject v0000)
{
    LispObject v0209;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for elimpt_bvl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0209 = v0000;
// end of prologue
    v0209 = qcdr(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcdr(v0209);
    v0209 = qcar(v0209);
    return onevalue(v0209);
}



// Code for dvfsf_qesubq

static LispObject CC_dvfsf_qesubq(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0019, v0007, v0018;
    LispObject fn;
    LispObject v0070, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dvfsf_qesubq");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0026 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_qesubq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0070,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0019 = v0070;
    v0007 = v0026;
    v0018 = v0000;
// end of prologue
    stack[-1] = v0018;
    stack[0] = elt(env, 1); // dvfsf_qesubqat
    v0019 = list2(v0007, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-2];
    {
        LispObject v0017 = stack[-1];
        LispObject v0031 = stack[0];
        popv(3);
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(qenv(fn), 3, v0017, v0031, v0019);
    }
// error exit handlers
v0071:
    popv(3);
    return nil;
}



// Code for ps!:sqrt!-erule

static LispObject CC_psTsqrtKerule(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0268, v0269, v0270;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:sqrt-erule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0026;
    v0268 = v0000;
// end of prologue
    v0268 = qcdr(v0268);
    v0268 = qcar(v0268);
    stack[-8] = v0268;
    v0269 = qvalue(elt(env, 1)); // nil
    v0268 = (LispObject)17; // 1
    v0268 = cons(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    stack[0] = v0268;
    v0268 = stack[-8];
    fn = elt(env, 4); // ps!:order
    v0268 = (*qfn1(fn))(qenv(fn), v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    stack[-5] = v0268;
    v0268 = qvalue(elt(env, 2)); // ps
    fn = elt(env, 4); // ps!:order
    v0268 = (*qfn1(fn))(qenv(fn), v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    stack[-6] = v0268;
    v0269 = stack[-7];
    v0268 = stack[-6];
    if (equal(v0269, v0268)) goto v0064;
    v0268 = (LispObject)17; // 1
    stack[-4] = v0268;
    goto v0123;

v0123:
    v0269 = stack[-7];
    v0268 = stack[-6];
    v0269 = difference2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0268 = stack[-4];
    v0268 = difference2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0268 = Lminusp(nil, v0268);
    env = stack[-9];
    if (v0268 == nil) goto v0066;
    stack[-1] = stack[0];
    stack[0] = (LispObject)33; // 2
    v0269 = stack[-7];
    v0268 = stack[-6];
    v0268 = difference2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0269 = times2(stack[0], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0268 = (LispObject)17; // 1
    stack[0] = cons(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0269 = stack[-8];
    v0268 = stack[-5];
    fn = elt(env, 5); // ps!:evaluate
    v0268 = (*qfn2(fn))(qenv(fn), v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    fn = elt(env, 6); // multsq
    v0268 = (*qfn2(fn))(qenv(fn), stack[0], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    {
        LispObject v0272 = stack[-1];
        popv(10);
        fn = elt(env, 7); // quotsq
        return (*qfn2(fn))(qenv(fn), v0272, v0268);
    }

v0066:
    stack[-3] = stack[0];
    v0269 = stack[-4];
    v0268 = (LispObject)49; // 3
    stack[0] = times2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0269 = (LispObject)33; // 2
    v0268 = stack[-7];
    v0268 = times2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0269 = difference2(stack[0], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0268 = stack[-5];
    v0268 = plus2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0270 = v0268;
    v0269 = v0270;
    v0268 = (LispObject)1; // 0
    if (v0269 == v0268) goto v0118;
    v0268 = v0270;
    v0269 = v0268;
    goto v0025;

v0025:
    v0268 = (LispObject)17; // 1
    stack[-2] = cons(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    stack[0] = stack[-8];
    v0269 = stack[-4];
    v0268 = stack[-5];
    v0268 = plus2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    fn = elt(env, 5); // ps!:evaluate
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 2)); // ps
    v0269 = stack[-7];
    v0268 = stack[-4];
    v0268 = difference2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    fn = elt(env, 5); // ps!:evaluate
    v0268 = (*qfn2(fn))(qenv(fn), stack[0], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    fn = elt(env, 6); // multsq
    v0268 = (*qfn2(fn))(qenv(fn), stack[-1], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    fn = elt(env, 6); // multsq
    v0268 = (*qfn2(fn))(qenv(fn), stack[-2], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    fn = elt(env, 8); // addsq
    v0268 = (*qfn2(fn))(qenv(fn), stack[-3], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    stack[0] = v0268;
    v0268 = stack[-4];
    v0268 = add1(v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    stack[-4] = v0268;
    goto v0123;

v0118:
    v0268 = qvalue(elt(env, 1)); // nil
    v0269 = v0268;
    goto v0025;

v0064:
    v0269 = stack[-8];
    v0268 = stack[-5];
    fn = elt(env, 5); // ps!:evaluate
    v0268 = (*qfn2(fn))(qenv(fn), v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    fn = elt(env, 9); // prepsqxx
    v0269 = (*qfn1(fn))(qenv(fn), v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    v0268 = elt(env, 3); // (quotient 1 2)
    v0268 = list2(v0269, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-9];
    {
        popv(10);
        fn = elt(env, 10); // simpexpt
        return (*qfn1(fn))(qenv(fn), v0268);
    }
// error exit handlers
v0271:
    popv(10);
    return nil;
}



// Code for empty

static LispObject CC_empty(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0062, v0087;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for empty");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0026;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0062 = (LispObject)17; // 1
    stack[-1] = v0062;
    goto v0010;

v0010:
    v0062 = stack[-4];
    if (v0062 == nil) goto v0035;
    v0062 = qvalue(elt(env, 1)); // nil
    goto v0029;

v0029:
    if (v0062 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0087 = stack[-3];
    v0062 = stack[-1];
    v0062 = *(LispObject *)((char *)v0087 + (CELL-TAG_VECTOR) + ((int32_t)v0062/(16/CELL)));
    if (v0062 == nil) goto v0033;
    v0062 = qvalue(elt(env, 2)); // t
    stack[-4] = v0062;
    goto v0033;

v0033:
    v0062 = stack[-1];
    v0062 = add1(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-5];
    stack[-1] = v0062;
    goto v0010;

v0035:
    stack[0] = stack[-1];
    v0062 = stack[-2];
    v0062 = add1(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-5];
    v0062 = (equal(stack[0], v0062) ? lisp_true : nil);
    v0062 = (v0062 == nil ? lisp_true : nil);
    goto v0029;
// error exit handlers
v0005:
    popv(6);
    return nil;
}



// Code for revise2

static LispObject CC_revise2(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0288, v0156, v0289;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revise2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0026;
    stack[0] = v0000;
// end of prologue
    v0288 = stack[0];
    if (!consp(v0288)) goto v0209;
    v0288 = stack[0];
    fn = elt(env, 7); // constp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    if (!(v0288 == nil)) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0288 = stack[0];
    v0288 = qcar(v0288);
    fn = elt(env, 8); // subscriptedvarp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    if (v0288 == nil) goto v0260;
    v0288 = stack[0];
    v0156 = qcar(v0288);
    v0288 = elt(env, 1); // aliaslist
    v0288 = get(v0156, v0288);
    env = stack[-6];
    if (v0288 == nil) goto v0051;
    v0288 = stack[0];
    stack[-5] = qcar(v0288);
    v0288 = stack[0];
    fn = elt(env, 9); // ireval
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = qcdr(v0288);
    stack[-3] = v0288;
    v0288 = stack[-3];
    if (v0288 == nil) goto v0048;
    v0288 = stack[-3];
    v0288 = qcar(v0288);
    v0156 = v0288;
    v0288 = stack[-4];
    v0288 = CC_revise2(env, v0156, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = ncons(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    stack[-1] = v0288;
    stack[-2] = v0288;
    goto v0191;

v0191:
    v0288 = stack[-3];
    v0288 = qcdr(v0288);
    stack[-3] = v0288;
    v0288 = stack[-3];
    if (v0288 == nil) goto v0216;
    stack[0] = stack[-1];
    v0288 = stack[-3];
    v0288 = qcar(v0288);
    v0156 = v0288;
    v0288 = stack[-4];
    v0288 = CC_revise2(env, v0156, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = ncons(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = Lrplacd(nil, stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = stack[-1];
    v0288 = qcdr(v0288);
    stack[-1] = v0288;
    goto v0191;

v0216:
    v0288 = stack[-2];
    goto v0211;

v0211:
    v0288 = cons(stack[-5], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    stack[0] = v0288;
    v0289 = stack[0];
    v0288 = stack[0];
    v0156 = qcar(v0288);
    v0288 = elt(env, 2); // finalalias
    v0288 = get(v0156, v0288);
    env = stack[-6];
    v0288 = Lassoc(nil, v0289, v0288);
    v0156 = v0288;
    if (v0288 == nil) goto v0061;
    v0288 = v0156;
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    { popv(7); return onevalue(v0288); }

v0061:
    v0288 = qvalue(elt(env, 5)); // !*vectorc
    if (v0288 == nil) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0288 = stack[0];
    fn = elt(env, 10); // introduce!-alias
    v0289 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0156 = stack[0];
    v0288 = qvalue(elt(env, 6)); // rhsaliases
    v0288 = acons(v0289, v0156, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    qvalue(elt(env, 6)) = v0288; // rhsaliases
    v0288 = qvalue(elt(env, 6)); // rhsaliases
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    { popv(7); return onevalue(v0288); }

v0048:
    v0288 = qvalue(elt(env, 4)); // nil
    goto v0211;

v0051:
    v0288 = qvalue(elt(env, 5)); // !*vectorc
    if (v0288 == nil) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0288 = stack[0];
    fn = elt(env, 10); // introduce!-alias
    v0289 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0156 = stack[0];
    v0288 = qvalue(elt(env, 6)); // rhsaliases
    v0288 = acons(v0289, v0156, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    qvalue(elt(env, 6)) = v0288; // rhsaliases
    v0288 = qvalue(elt(env, 6)); // rhsaliases
    v0288 = qcar(v0288);
    v0288 = qcar(v0288);
    { popv(7); return onevalue(v0288); }

v0260:
    v0156 = stack[0];
    v0288 = stack[-4];
    v0288 = Lassoc(nil, v0156, v0288);
    v0156 = v0288;
    if (v0288 == nil) goto v0173;
    v0288 = v0156;
    v0288 = qcdr(v0288);
    v0288 = qcar(v0288);
    { popv(7); return onevalue(v0288); }

v0173:
    v0288 = stack[0];
    stack[-5] = qcar(v0288);
    v0288 = stack[0];
    v0288 = qcdr(v0288);
    stack[-3] = v0288;
    v0288 = stack[-3];
    if (v0288 == nil) goto v0290;
    v0288 = stack[-3];
    v0288 = qcar(v0288);
    v0156 = v0288;
    v0288 = stack[-4];
    v0288 = CC_revise2(env, v0156, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = ncons(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    stack[-1] = v0288;
    stack[-2] = v0288;
    goto v0291;

v0291:
    v0288 = stack[-3];
    v0288 = qcdr(v0288);
    stack[-3] = v0288;
    v0288 = stack[-3];
    if (v0288 == nil) goto v0292;
    stack[0] = stack[-1];
    v0288 = stack[-3];
    v0288 = qcar(v0288);
    v0156 = v0288;
    v0288 = stack[-4];
    v0288 = CC_revise2(env, v0156, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = ncons(v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = Lrplacd(nil, stack[0], v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0288 = stack[-1];
    v0288 = qcdr(v0288);
    stack[-1] = v0288;
    goto v0291;

v0292:
    v0288 = stack[-2];
    goto v0293;

v0293:
    {
        LispObject v0294 = stack[-5];
        popv(7);
        return cons(v0294, v0288);
    }

v0290:
    v0288 = qvalue(elt(env, 4)); // nil
    goto v0293;

v0209:
    v0288 = stack[0];
    fn = elt(env, 7); // constp
    v0288 = (*qfn1(fn))(qenv(fn), v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    if (!(v0288 == nil)) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0156 = stack[0];
    v0288 = elt(env, 1); // aliaslist
    v0288 = get(v0156, v0288);
    env = stack[-6];
    if (v0288 == nil) goto v0056;
    v0288 = stack[0];
    v0156 = elt(env, 2); // finalalias
    popv(7);
    return get(v0288, v0156);

v0056:
    v0156 = stack[0];
    v0288 = qvalue(elt(env, 3)); // known
    v0288 = Lmember(nil, v0156, v0288);
    if (!(v0288 == nil)) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0156 = stack[0];
    v0288 = qvalue(elt(env, 3)); // known
    v0288 = cons(v0156, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    qvalue(elt(env, 3)) = v0288; // known
    { LispObject res = stack[0]; popv(7); return onevalue(res); }
// error exit handlers
v0157:
    popv(7);
    return nil;
}



// Code for sc_transpose

static LispObject CC_sc_transpose(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0074, v0210, v0211;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_transpose");
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
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0000;
// end of prologue
    v0074 = stack[-7];
    fn = elt(env, 2); // fast!-row!-dim
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    stack[-5] = v0074;
    v0074 = stack[-7];
    fn = elt(env, 3); // fast!-column!-dim
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    stack[-6] = v0074;
    v0210 = stack[-6];
    v0074 = stack[-5];
    fn = elt(env, 4); // sc_mkmatrix
    v0074 = (*qfn2(fn))(qenv(fn), v0210, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    stack[-8] = v0074;
    v0074 = (LispObject)17; // 1
    stack[-4] = v0074;
    goto v0032;

v0032:
    v0210 = stack[-6];
    v0074 = stack[-4];
    v0074 = difference2(v0210, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    v0074 = Lminusp(nil, v0074);
    env = stack[-9];
    if (!(v0074 == nil)) { LispObject res = stack[-8]; popv(10); return onevalue(res); }
    v0074 = (LispObject)17; // 1
    stack[-3] = v0074;
    goto v0182;

v0182:
    v0210 = stack[-5];
    v0074 = stack[-3];
    v0074 = difference2(v0210, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    v0074 = Lminusp(nil, v0074);
    env = stack[-9];
    if (v0074 == nil) goto v0005;
    v0074 = stack[-4];
    v0074 = add1(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    stack[-4] = v0074;
    goto v0032;

v0005:
    stack[-2] = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v0211 = stack[-7];
    v0210 = stack[-3];
    v0074 = stack[-4];
    fn = elt(env, 5); // sc_getmat
    v0074 = (*qfnn(fn))(qenv(fn), 3, v0211, v0210, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    fn = elt(env, 6); // sc_setmat
    v0074 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    v0074 = stack[-3];
    v0074 = add1(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-9];
    stack[-3] = v0074;
    goto v0182;
// error exit handlers
v0189:
    popv(10);
    return nil;
}



// Code for evweightedcomp2

static LispObject CC_evweightedcomp2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0024, v0067, v0066, v0072, v0073;
    LispObject v0070, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evweightedcomp2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0026 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evweightedcomp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0067 = v0070;
    v0066 = v0026;
    v0072 = v0000;
// end of prologue

v0040:
    v0024 = v0066;
    if (v0024 == nil) return onevalue(v0072);
    v0024 = v0067;
    if (v0024 == nil) goto v0082;
    v0024 = v0067;
    v0073 = qcar(v0024);
    v0024 = (LispObject)1; // 0
    if (v0073 == v0024) goto v0110;
    v0024 = v0067;
    v0073 = qcar(v0024);
    v0024 = (LispObject)17; // 1
    if (v0073 == v0024) goto v0194;
    v0024 = v0066;
    v0073 = qcar(v0024);
    v0024 = v0067;
    v0024 = qcar(v0024);
    v0024 = fixnum_of_int((int32_t)(int_of_fixnum(v0073) * int_of_fixnum(v0024)));
    v0024 = (LispObject)(int32_t)((int32_t)v0024 + (int32_t)v0072 - TAG_FIXNUM);
    v0072 = v0024;
    v0024 = v0066;
    v0024 = qcdr(v0024);
    v0066 = v0024;
    v0024 = v0067;
    v0024 = qcdr(v0024);
    v0067 = v0024;
    goto v0040;

v0194:
    v0024 = v0066;
    v0024 = qcar(v0024);
    v0024 = (LispObject)(int32_t)((int32_t)v0072 + (int32_t)v0024 - TAG_FIXNUM);
    v0072 = v0024;
    v0024 = v0066;
    v0024 = qcdr(v0024);
    v0066 = v0024;
    v0024 = v0067;
    v0024 = qcdr(v0024);
    v0067 = v0024;
    goto v0040;

v0110:
    v0024 = v0066;
    v0024 = qcdr(v0024);
    v0066 = v0024;
    v0024 = v0067;
    v0024 = qcdr(v0024);
    v0067 = v0024;
    goto v0040;

v0082:
    v0024 = elt(env, 1); // (1 1 1 1 1)
    v0067 = v0024;
    goto v0040;
}



// Code for formclear1

static LispObject CC_formclear1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0213, v0286, v0287;
    LispObject fn;
    LispObject v0070, v0026, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclear1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0026 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formclear1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0070,v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0026,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-4] = v0070;
    stack[-5] = v0026;
    v0213 = v0000;
// end of prologue
    stack[-6] = elt(env, 1); // list
    stack[-3] = v0213;
    v0213 = stack[-3];
    if (v0213 == nil) goto v0035;
    v0213 = stack[-3];
    v0213 = qcar(v0213);
    v0286 = v0213;
    v0213 = v0286;
    if (!symbolp(v0213)) v0213 = nil;
    else { v0213 = qfastgets(v0213);
           if (v0213 != nil) { v0213 = elt(v0213, 17); // share
#ifdef RECORD_GET
             if (v0213 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0213 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0213 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0213 == SPID_NOPROP) v0213 = nil; else v0213 = lisp_true; }}
#endif
    if (v0213 == nil) goto v0086;
    v0213 = v0286;
    v0213 = Lmkquote(nil, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-7];
    goto v0031;

v0031:
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-7];
    stack[-1] = v0213;
    stack[-2] = v0213;
    goto v0029;

v0029:
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    stack[-3] = v0213;
    v0213 = stack[-3];
    if (v0213 == nil) goto v0101;
    stack[0] = stack[-1];
    v0213 = stack[-3];
    v0213 = qcar(v0213);
    v0286 = v0213;
    v0213 = v0286;
    if (!symbolp(v0213)) v0213 = nil;
    else { v0213 = qfastgets(v0213);
           if (v0213 != nil) { v0213 = elt(v0213, 17); // share
#ifdef RECORD_GET
             if (v0213 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0213 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0213 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0213 == SPID_NOPROP) v0213 = nil; else v0213 = lisp_true; }}
#endif
    if (v0213 == nil) goto v0066;
    v0213 = v0286;
    v0213 = Lmkquote(nil, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-7];
    goto v0123;

v0123:
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-7];
    v0213 = Lrplacd(nil, stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-7];
    v0213 = stack[-1];
    v0213 = qcdr(v0213);
    stack[-1] = v0213;
    goto v0029;

v0066:
    v0287 = v0286;
    v0286 = stack[-5];
    v0213 = stack[-4];
    fn = elt(env, 3); // form1
    v0213 = (*qfnn(fn))(qenv(fn), 3, v0287, v0286, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-7];
    goto v0123;

v0101:
    v0213 = stack[-2];
    goto v0209;

v0209:
    {
        LispObject v0104 = stack[-6];
        popv(8);
        return cons(v0104, v0213);
    }

v0086:
    v0287 = v0286;
    v0286 = stack[-5];
    v0213 = stack[-4];
    fn = elt(env, 3); // form1
    v0213 = (*qfnn(fn))(qenv(fn), 3, v0287, v0286, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-7];
    goto v0031;

v0035:
    v0213 = qvalue(elt(env, 2)); // nil
    goto v0209;
// error exit handlers
v0214:
    popv(8);
    return nil;
}



// Code for intcollectint

static LispObject CC_intcollectint(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0033, v0095;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intcollectint");
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
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 2); // lastpair
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-2];
    v0033 = qcar(v0033);
    stack[-1] = v0033;
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0010;

v0010:
    v0033 = stack[0];
    if (v0033 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 2); // lastpair
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-2];
    v0095 = qcar(v0033);
    v0033 = stack[-1];
    fn = elt(env, 3); // !:plus
    v0033 = (*qfn2(fn))(qenv(fn), v0095, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-2];
    stack[-1] = v0033;
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0010;
// error exit handlers
v0086:
    popv(3);
    return nil;
}



// Code for getlower

static LispObject CC_getlower(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getlower");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0015 = v0000;
// end of prologue
    v0014 = qvalue(elt(env, 1)); // metricd!*
    v0015 = Latsoc(nil, v0015, v0014);
    v0015 = qcdr(v0015);
    return onevalue(v0015);
}



// Code for addns

static LispObject CC_addns(LispObject env,
                         LispObject v0000, LispObject v0026)
{
    LispObject nil = C_nil;
    LispObject v0295, v0121, v0296;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addns");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0026,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0026);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0026;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0040;

v0040:
    v0295 = stack[0];
    if (v0295 == nil) goto v0082;
    v0295 = stack[-1];
    v0121 = qcdr(v0295);
    v0295 = stack[0];
    v0295 = qcar(v0295);
    v0295 = qcdr(v0295);
    if (equal(v0121, v0295)) goto v0055;
    v0295 = stack[-1];
    v0121 = qcdr(v0295);
    v0295 = stack[0];
    v0295 = qcar(v0295);
    v0295 = qcdr(v0295);
    fn = elt(env, 1); // ordp
    v0295 = (*qfn2(fn))(qenv(fn), v0121, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    if (v0295 == nil) goto v0297;
    v0121 = stack[-1];
    v0295 = stack[0];
    v0295 = cons(v0121, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    {
        LispObject v0011 = stack[-2];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0011, v0295);
    }

v0297:
    v0295 = stack[0];
    v0121 = qcar(v0295);
    v0295 = stack[-2];
    v0295 = cons(v0121, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    stack[-2] = v0295;
    v0295 = stack[0];
    v0295 = qcdr(v0295);
    stack[0] = v0295;
    goto v0040;

v0055:
    v0295 = stack[-1];
    v0121 = qcar(v0295);
    v0295 = stack[0];
    v0295 = qcar(v0295);
    v0295 = qcar(v0295);
    fn = elt(env, 3); // addsq
    v0295 = (*qfn2(fn))(qenv(fn), v0121, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    v0296 = v0295;
    v0295 = stack[-1];
    v0121 = qcdr(v0295);
    v0295 = stack[0];
    v0295 = qcdr(v0295);
    v0295 = acons(v0296, v0121, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    {
        LispObject v0012 = stack[-2];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0012, v0295);
    }

v0082:
    stack[0] = stack[-2];
    v0295 = stack[-1];
    v0295 = ncons(v0295);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    {
        LispObject v0078 = stack[0];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0078, v0295);
    }
// error exit handlers
v0046:
    popv(4);
    return nil;
}



// Code for checku1

static LispObject CC_checku1(LispObject env,
                         LispObject v0026, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0182, v0127;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for checku1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0026);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0026,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0182 = v0070;
    stack[0] = v0026;
// end of prologue
    stack[-1] = qvalue(elt(env, 1)); // rhs!*
    qvalue(elt(env, 1)) = nil; // rhs!*
    qvalue(elt(env, 1)) = v0182; // rhs!*
    goto v0010;

v0010:
    v0182 = qvalue(elt(env, 1)); // rhs!*
    if (v0182 == nil) goto v0082;
    v0127 = stack[0];
    v0182 = qvalue(elt(env, 1)); // rhs!*
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    fn = elt(env, 4); // negind
    v0182 = (*qfn2(fn))(qenv(fn), v0127, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    if (v0182 == nil) goto v0030;
    v0182 = qvalue(elt(env, 1)); // rhs!*
    v0182 = qcar(v0182);
    v0182 = qcdr(v0182);
    v0127 = qcar(v0182);
    v0182 = stack[0];
    fn = elt(env, 5); // evaluatecoeffts
    v0182 = (*qfn2(fn))(qenv(fn), v0127, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    if (v0182 == nil) goto v0030;
    v0182 = qvalue(elt(env, 3)); // t
    goto v0040;

v0040:
    qvalue(elt(env, 1)) = stack[-1]; // rhs!*
    { popv(3); return onevalue(v0182); }

v0030:
    v0182 = qvalue(elt(env, 1)); // rhs!*
    v0182 = qcdr(v0182);
    qvalue(elt(env, 1)) = v0182; // rhs!*
    goto v0010;

v0082:
    v0182 = qvalue(elt(env, 2)); // nil
    goto v0040;
// error exit handlers
v0101:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; // rhs!*
    popv(3);
    return nil;
}



// Code for tildepri

static LispObject CC_tildepri(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0209;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tildepri");
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
    v0209 = elt(env, 1); // "~"
    fn = elt(env, 2); // prin2!*
    v0209 = (*qfn1(fn))(qenv(fn), v0209);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0209 = stack[0];
    v0209 = qcdr(v0209);
    v0209 = qcar(v0209);
    {
        popv(2);
        fn = elt(env, 2); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0209);
    }
// error exit handlers
v0010:
    popv(2);
    return nil;
}



// Code for validrule1

static LispObject CC_validrule1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0049, v0201, v0295;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for validrule1");
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
    v0295 = v0000;
// end of prologue
    v0049 = v0295;
    if (!consp(v0049)) goto v0047;
    v0049 = v0295;
    v0201 = qcar(v0049);
    v0049 = elt(env, 2); // list
    if (v0201 == v0049) goto v0209;
    v0049 = v0295;
    v0201 = qcar(v0049);
    v0049 = elt(env, 3); // replaceby
    if (v0201 == v0049) { popv(5); return onevalue(v0295); }
    v0049 = v0295;
    v0201 = qcar(v0049);
    v0049 = elt(env, 4); // equal
    if (v0201 == v0049) goto v0287;
    v0049 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0049); }

v0287:
    v0049 = elt(env, 3); // replaceby
    v0201 = v0295;
    v0201 = qcdr(v0201);
    popv(5);
    return cons(v0049, v0201);

v0209:
    v0049 = v0295;
    v0049 = qcdr(v0049);
    if (v0049 == nil) goto v0035;
    v0049 = v0295;
    v0049 = qcdr(v0049);
    stack[-3] = v0049;
    v0049 = stack[-3];
    if (v0049 == nil) goto v0081;
    v0049 = stack[-3];
    v0049 = qcar(v0049);
    v0049 = CC_validrule1(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    v0049 = ncons(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    stack[-1] = v0049;
    stack[-2] = v0049;
    goto v0008;

v0008:
    v0049 = stack[-3];
    v0049 = qcdr(v0049);
    stack[-3] = v0049;
    v0049 = stack[-3];
    if (v0049 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0049 = stack[-3];
    v0049 = qcar(v0049);
    v0049 = CC_validrule1(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    v0049 = ncons(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    v0049 = Lrplacd(nil, stack[0], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-4];
    v0049 = stack[-1];
    v0049 = qcdr(v0049);
    stack[-1] = v0049;
    goto v0008;

v0081:
    v0049 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0049); }

v0035:
    v0049 = qvalue(elt(env, 1)); // nil
    popv(5);
    return ncons(v0049);

v0047:
    v0049 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0049); }
// error exit handlers
v0045:
    popv(5);
    return nil;
}



// Code for ioto_cterpri

static LispObject CC_ioto_cterpri(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0034, v0195;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ioto_cterpri");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ioto_cterpri");
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
    v0195 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[0];
    v0034 = (LispObject)1; // 0
    v0034 = (LispObject)greaterp2(v0195, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    v0034 = v0034 ? lisp_true : nil;
    if (v0034 == nil) goto v0047;
        popv(1);
        return Lterpri(nil, 0);

v0047:
    v0034 = nil;
    { popv(1); return onevalue(v0034); }
// error exit handlers
v0029:
    popv(1);
    return nil;
}



setup_type const u60_setup[] =
{
    {"exformp",                 CC_exformp,     too_many_1,    wrong_no_1},
    {"gffplus",                 too_few_2,      CC_gffplus,    wrong_no_2},
    {"mk_edge_name",            too_few_2,      CC_mk_edge_name,wrong_no_2},
    {"set_rules",               too_few_2,      CC_set_rules,  wrong_no_2},
    {"canonical",               CC_canonical,   too_many_1,    wrong_no_1},
    {"general-quotient-mod-p",  too_few_2,      CC_generalKquotientKmodKp,wrong_no_2},
    {"simpsqrt",                CC_simpsqrt,    too_many_1,    wrong_no_1},
    {"find-non-zero",           CC_findKnonKzero,too_many_1,   wrong_no_1},
    {"pasf_mkop",               too_few_2,      CC_pasf_mkop,  wrong_no_2},
    {"iv_congp",                CC_iv_congp,    too_many_1,    wrong_no_1},
    {"aex_sgn",                 CC_aex_sgn,     too_many_1,    wrong_no_1},
    {"cgp_comp",                too_few_2,      CC_cgp_comp,   wrong_no_2},
    {"log:",                    too_few_2,      CC_logT,       wrong_no_2},
    {"f2vdp",                   CC_f2vdp,       too_many_1,    wrong_no_1},
    {"evalsymsubset",           CC_evalsymsubset,too_many_1,   wrong_no_1},
    {"bftimes",                 too_few_2,      CC_bftimes,    wrong_no_2},
    {"compactf",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf},
    {"pst_equitable1",          too_few_2,      CC_pst_equitable1,wrong_no_2},
    {"form-sum-and-product-mod-p",wrong_no_na,  wrong_no_nb,   (n_args *)CC_formKsumKandKproductKmodKp},
    {"qqe_clause-update-lengths",too_few_2,     CC_qqe_clauseKupdateKlengths,wrong_no_2},
    {"division-test",           too_few_2,      CC_divisionKtest,wrong_no_2},
    {"xvarlistp",               CC_xvarlistp,   too_many_1,    wrong_no_1},
    {"mk_spec_atlas",           too_few_2,      CC_mk_spec_atlas,wrong_no_2},
    {"mv-reduced-coeffs",       CC_mvKreducedKcoeffs,too_many_1,wrong_no_1},
    {"dv_null_first_kern",      CC_dv_null_first_kern,too_many_1,wrong_no_1},
    {"xprint",                  too_few_2,      CC_xprint,     wrong_no_2},
    {"algint-subsublis",        too_few_2,      CC_algintKsubsublis,wrong_no_2},
    {"general-monic-mod-p",     CC_generalKmonicKmodKp,too_many_1,wrong_no_1},
    {"fillin",                  CC_fillin,      too_many_1,    wrong_no_1},
    {"elimpt_bvl",              CC_elimpt_bvl,  too_many_1,    wrong_no_1},
    {"dvfsf_qesubq",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_qesubq},
    {"ps:sqrt-erule",           too_few_2,      CC_psTsqrtKerule,wrong_no_2},
    {"empty",                   too_few_2,      CC_empty,      wrong_no_2},
    {"revise2",                 too_few_2,      CC_revise2,    wrong_no_2},
    {"sc_transpose",            CC_sc_transpose,too_many_1,    wrong_no_1},
    {"evweightedcomp2",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_evweightedcomp2},
    {"formclear1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclear1},
    {"intcollectint",           CC_intcollectint,too_many_1,   wrong_no_1},
    {"getlower",                CC_getlower,    too_many_1,    wrong_no_1},
    {"addns",                   too_few_2,      CC_addns,      wrong_no_2},
    {"checku1",                 too_few_2,      CC_checku1,    wrong_no_2},
    {"tildepri",                CC_tildepri,    too_many_1,    wrong_no_1},
    {"validrule1",              CC_validrule1,  too_many_1,    wrong_no_1},
    {"ioto_cterpri",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ioto_cterpri},
    {NULL, (one_args *)"u60", (two_args *)"8433 2012520 4208099", 0}
};

// end of generated code
