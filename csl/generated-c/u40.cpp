
// $destdir\u40.c        Machine generated C code

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



// Code for force!-to!-dm

static LispObject CC_forceKtoKdm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0016, v0017, v0018;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for force-to-dm");
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
    v0017 = v0000;
// end of prologue

v0019:
    v0016 = v0017;
    if (!consp(v0016)) goto v0020;
    v0016 = v0017;
    v0016 = qcar(v0016);
    v0016 = (consp(v0016) ? nil : lisp_true);
    goto v0021;

v0021:
    if (v0016 == nil) goto v0022;
    v0016 = v0017;
    if (v0016 == nil) goto v0023;
    v0016 = v0017;
    if (is_number(v0016)) goto v0024;
    v0016 = v0017;
    v0016 = Lconsp(nil, v0016);
    env = stack[-1];
    if (v0016 == nil) goto v0025;
    v0016 = v0017;
    v0018 = qcar(v0016);
    v0016 = qvalue(elt(env, 3)); // dmode!*
    if (equal(v0018, v0016)) { popv(2); return onevalue(v0017); }
    else goto v0025;

v0025:
    v0016 = v0017;
    v0016 = Lconsp(nil, v0016);
    env = stack[-1];
    if (v0016 == nil) goto v0026;
    v0016 = v0017;
    v0018 = qcar(v0016);
    v0016 = qvalue(elt(env, 3)); // dmode!*
    v0016 = get(v0018, v0016);
    env = stack[-1];
    goto v0027;

v0027:
    v0018 = v0016;
    v0016 = v0018;
    if (v0016 == nil) goto v0028;
    stack[0] = v0018;
    v0016 = v0017;
    v0016 = ncons(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    {
        LispObject v0030 = stack[0];
        popv(2);
        fn = elt(env, 6); // apply
        return (*qfn2(fn))(qenv(fn), v0030, v0016);
    }

v0028:
    v0016 = elt(env, 5); // "conversion error with "
    v0016 = list2(v0016, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 7); // rederr
        return (*qfn1(fn))(qenv(fn), v0016);
    }

v0026:
    v0016 = qvalue(elt(env, 4)); // nil
    goto v0027;

v0024:
    v0016 = qvalue(elt(env, 3)); // dmode!*
    if (!symbolp(v0016)) stack[0] = nil;
    else { stack[0] = qfastgets(v0016);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 34); // i2d
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    v0016 = v0017;
    v0016 = ncons(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    {
        LispObject v0031 = stack[0];
        popv(2);
        fn = elt(env, 6); // apply
        return (*qfn2(fn))(qenv(fn), v0031, v0016);
    }

v0023:
    v0016 = (LispObject)1; // 0
    v0017 = v0016;
    goto v0019;

v0022:
    v0016 = v0017;
    fn = elt(env, 8); // prepf
    v0017 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    v0016 = elt(env, 2); // "number"
    {
        popv(2);
        fn = elt(env, 9); // typerr
        return (*qfn2(fn))(qenv(fn), v0017, v0016);
    }

v0020:
    v0016 = qvalue(elt(env, 1)); // t
    goto v0021;
// error exit handlers
v0029:
    popv(2);
    return nil;
}



// Code for find_triangl_coeff

static LispObject CC_find_triangl_coeff(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0038, v0039, v0040, v0022;
    LispObject fn;
    LispObject v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_triangl_coeff");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find_triangl_coeff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0038 = v0036;
    v0039 = v0037;
    v0040 = v0000;
// end of prologue
    v0022 = v0040;
    v0040 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // find_triangle_coeff
        return (*qfnn(fn))(qenv(fn), 4, v0022, v0040, v0039, v0038);
    }
}



// Code for monic

static LispObject CC_monic(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0002, v0016;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monic");
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
// copy arguments values to proper place
    stack[-2] = v0037;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0002 = stack[-3];
    v0002 = Lreverse(nil, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    stack[-3] = v0002;
    v0002 = qvalue(elt(env, 1)); // varlist!*
    v0002 = Llength(nil, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    stack[-1] = v0002;
    v0002 = (LispObject)17; // 1
    stack[0] = v0002;
    goto v0053;

v0053:
    v0016 = stack[-1];
    v0002 = stack[0];
    v0002 = difference2(v0016, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    v0002 = Lminusp(nil, v0002);
    env = stack[-5];
    if (v0002 == nil) goto v0054;
    v0002 = qvalue(elt(env, 1)); // varlist!*
    v0002 = qcdr(v0002);
    stack[-3] = v0002;
    v0002 = stack[-3];
    if (v0002 == nil) goto v0055;
    v0002 = (LispObject)1; // 0
    v0002 = ncons(v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    stack[-1] = v0002;
    stack[-2] = v0002;
    goto v0056;

v0056:
    v0002 = stack[-3];
    v0002 = qcdr(v0002);
    stack[-3] = v0002;
    v0002 = stack[-3];
    if (v0002 == nil) goto v0057;
    stack[0] = stack[-1];
    v0002 = (LispObject)1; // 0
    v0002 = ncons(v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    v0002 = Lrplacd(nil, stack[0], v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    v0002 = stack[-1];
    v0002 = qcdr(v0002);
    stack[-1] = v0002;
    goto v0056;

v0057:
    v0002 = stack[-2];
    goto v0025;

v0025:
    v0002 = (equal(stack[-4], v0002) ? lisp_true : nil);
    { popv(6); return onevalue(v0002); }

v0055:
    v0002 = qvalue(elt(env, 2)); // nil
    goto v0025;

v0054:
    v0016 = stack[0];
    v0002 = stack[-2];
    if (equal(v0016, v0002)) goto v0058;
    v0016 = stack[-3];
    v0002 = stack[0];
    fn = elt(env, 3); // nth
    v0016 = (*qfn2(fn))(qenv(fn), v0016, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    v0002 = stack[-4];
    v0002 = cons(v0016, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    stack[-4] = v0002;
    goto v0058;

v0058:
    v0002 = stack[0];
    v0002 = add1(v0002);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-5];
    stack[0] = v0002;
    goto v0053;
// error exit handlers
v0031:
    popv(6);
    return nil;
}



// Code for pa_part2list

static LispObject CC_pa_part2list(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0073;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pa_part2list");
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
    v0073 = stack[-6];
    v0073 = qcdr(v0073);
    fn = elt(env, 2); // upbve
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    stack[0] = v0073;
    v0073 = stack[0];
    v0073 = sub1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    v0073 = Lmkvect(nil, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    stack[-7] = v0073;
    v0073 = stack[0];
    stack[-4] = v0073;
    goto v0038;

v0038:
    v0073 = stack[-4];
    v0073 = sub1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    v0073 = Lminusp(nil, v0073);
    env = stack[-8];
    if (v0073 == nil) goto v0014;
    v0073 = stack[-6];
    v0073 = qcar(v0073);
    stack[-4] = v0073;
    goto v0075;

v0075:
    v0073 = stack[-4];
    if (v0073 == nil) goto v0076;
    v0073 = stack[-4];
    v0073 = qcar(v0073);
    stack[0] = stack[-7];
    v0073 = sub1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    v0073 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0073/(16/CELL)));
    fn = elt(env, 3); // copy
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    stack[-3] = v0073;
    v0073 = stack[-3];
    fn = elt(env, 4); // lastpair
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    stack[-2] = v0073;
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    stack[-4] = v0073;
    v0073 = stack[-2];
    if (!consp(v0073)) goto v0075;
    else goto v0077;

v0077:
    v0073 = stack[-4];
    if (v0073 == nil) { LispObject res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v0073 = stack[-4];
    v0073 = qcar(v0073);
    stack[0] = stack[-7];
    v0073 = sub1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    v0073 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0073/(16/CELL)));
    fn = elt(env, 3); // copy
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    v0073 = Lrplacd(nil, stack[-1], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    v0073 = stack[-2];
    fn = elt(env, 4); // lastpair
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    stack[-2] = v0073;
    v0073 = stack[-4];
    v0073 = qcdr(v0073);
    stack[-4] = v0073;
    goto v0077;

v0076:
    v0073 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0073); }

v0014:
    v0073 = stack[-6];
    stack[0] = qcdr(v0073);
    v0073 = stack[-4];
    v0073 = sub1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    v0073 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0073/(16/CELL)));
    stack[-5] = v0073;
    stack[-3] = stack[-7];
    v0073 = stack[-5];
    stack[-2] = sub1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v0073 = stack[-5];
    v0073 = sub1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    v0073 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0073/(16/CELL)));
    v0073 = cons(stack[-1], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v0073;
    v0073 = stack[-4];
    v0073 = sub1(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-8];
    stack[-4] = v0073;
    goto v0038;
// error exit handlers
v0074:
    popv(9);
    return nil;
}



// Code for random!-teeny!-prime

static LispObject CC_randomKteenyKprime(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0044, v0041, v0064;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for random-teeny-prime");
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
    v0041 = stack[0];
    v0044 = elt(env, 1); // all
    if (v0041 == v0044) goto v0085;
    v0044 = stack[0];
    v0041 = Llength(nil, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-2];
    v0044 = (LispObject)161; // 10
    v0044 = (v0041 == v0044 ? lisp_true : nil);
    goto v0087;

v0087:
    if (v0044 == nil) goto v0088;
    v0044 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0044); }

v0088:
    stack[-1] = qvalue(elt(env, 4)); // teeny!-primes
    fn = elt(env, 5); // next!-random!-number
    v0041 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-2];
    v0044 = (LispObject)161; // 10
    v0044 = Cremainder(v0041, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-2];
    v0044 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0044/(16/CELL)));
    v0064 = v0044;
    v0041 = v0064;
    v0044 = stack[0];
    v0044 = Lmember(nil, v0041, v0044);
    if (v0044 == nil) { popv(3); return onevalue(v0064); }
    else goto v0088;

v0085:
    v0044 = qvalue(elt(env, 2)); // t
    goto v0087;
// error exit handlers
v0086:
    popv(3);
    return nil;
}



// Code for equal!+matrices!+p

static LispObject CC_equalLmatricesLp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0097, v0098, v0099;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for equal+matrices+p");
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
    stack[0] = v0037;
    stack[-1] = v0000;
// end of prologue
    v0098 = stack[-1];
    v0097 = stack[0];
    fn = elt(env, 4); // same!+dim!+squared!+p
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    if (v0097 == nil) goto v0074;
    v0098 = (LispObject)-15; // -1
    v0097 = (LispObject)17; // 1
    v0098 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0097 = stack[0];
    fn = elt(env, 5); // mk!+scal!+mult!+mat
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    fn = elt(env, 6); // mk!+mat!+plus!+mat
    v0097 = (*qfn2(fn))(qenv(fn), stack[-1], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    stack[0] = v0097;
    v0098 = qvalue(elt(env, 1)); // nil
    v0097 = (LispObject)17; // 1
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0099 = v0097;
    v0097 = stack[0];
    stack[-3] = v0097;
    goto v0010;

v0010:
    v0097 = stack[-3];
    if (v0097 == nil) goto v0101;
    v0097 = stack[-3];
    v0097 = qcar(v0097);
    stack[-2] = v0097;
    goto v0075;

v0075:
    v0097 = stack[-2];
    if (v0097 == nil) goto v0086;
    v0097 = stack[-2];
    v0097 = qcar(v0097);
    v0098 = v0097;
    v0097 = qvalue(elt(env, 2)); // !*complex
    if (v0097 == nil) goto v0016;
    stack[-1] = v0099;
    stack[0] = v0098;
    v0097 = v0098;
    fn = elt(env, 7); // mk!+conjugate!+sq
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    fn = elt(env, 8); // multsq
    v0097 = (*qfn2(fn))(qenv(fn), stack[0], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    fn = elt(env, 9); // addsq
    v0097 = (*qfn2(fn))(qenv(fn), stack[-1], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0099 = v0097;
    goto v0067;

v0067:
    v0097 = stack[-2];
    v0097 = qcdr(v0097);
    stack[-2] = v0097;
    goto v0075;

v0016:
    stack[0] = v0099;
    v0097 = v0098;
    fn = elt(env, 8); // multsq
    v0097 = (*qfn2(fn))(qenv(fn), v0097, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    fn = elt(env, 9); // addsq
    v0097 = (*qfn2(fn))(qenv(fn), stack[0], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0099 = v0097;
    goto v0067;

v0086:
    v0097 = stack[-3];
    v0097 = qcdr(v0097);
    stack[-3] = v0097;
    goto v0010;

v0101:
    v0097 = v0099;
    fn = elt(env, 10); // change!+sq!+to!+algnull
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0098 = v0097;
    v0097 = (LispObject)1; // 0
    if (v0098 == v0097) goto v0102;
    v0097 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0097); }

v0102:
    v0097 = qvalue(elt(env, 3)); // t
    { popv(5); return onevalue(v0097); }

v0074:
    v0097 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0097); }
// error exit handlers
v0100:
    popv(5);
    return nil;
}



// Code for qqe_length!-graph!-neighbor!-edge

static LispObject CC_qqe_lengthKgraphKneighborKedge(LispObject env,
                         LispObject v0000)
{
    LispObject v0083;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbor-edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0083 = v0000;
// end of prologue
    v0083 = qcdr(v0083);
    v0083 = qcdr(v0083);
    v0083 = qcar(v0083);
    return onevalue(v0083);
}



// Code for sqfrf

static LispObject CC_sqfrf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0172, v0173, v0174, v0175;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqfrf");
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
    stack[-8] = qvalue(elt(env, 1)); // !*gcd
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-7] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-5] = qvalue(elt(env, 2)); // !*msg
    qvalue(elt(env, 2)) = nil; // !*msg
    v0172 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 1)) = v0172; // !*gcd
    v0172 = qvalue(elt(env, 4)); // !*rounded
    stack[-1] = v0172;
    if (v0172 == nil) goto v0035;
    v0172 = elt(env, 5); // rational
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    fn = elt(env, 12); // on
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0173 = stack[-9];
    v0172 = (LispObject)17; // 1
    v0172 = cons(v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    fn = elt(env, 13); // resimp
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = qcar(v0172);
    stack[-9] = v0172;
    goto v0035;

v0035:
    v0172 = (LispObject)17; // 1
    stack[-10] = v0172;
    v0172 = stack[-9];
    v0172 = qcar(v0172);
    v0172 = qcar(v0172);
    v0172 = qcar(v0172);
    stack[-4] = v0172;
    v0172 = qvalue(elt(env, 3)); // t
    stack[0] = qvalue(elt(env, 6)); // !*ezgcd
    qvalue(elt(env, 6)) = v0172; // !*ezgcd
    stack[-6] = stack[-9];
    v0173 = stack[-9];
    v0172 = stack[-4];
    fn = elt(env, 14); // diff
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-11];
    fn = elt(env, 15); // gcdf
    v0172 = (*qfn2(fn))(qenv(fn), stack[-6], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-11];
    stack[-6] = v0172;
    qvalue(elt(env, 6)) = stack[0]; // !*ezgcd
    v0173 = stack[-9];
    v0172 = stack[-6];
    fn = elt(env, 16); // quotf!-fail
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-9] = v0172;
    v0172 = qvalue(elt(env, 7)); // dmode!*
    if (!symbolp(v0172)) v0172 = nil;
    else { v0172 = qfastgets(v0172);
           if (v0172 != nil) { v0172 = elt(v0172, 3); // field
#ifdef RECORD_GET
             if (v0172 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0172 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0172 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0172 == SPID_NOPROP) v0172 = nil; else v0172 = lisp_true; }}
#endif
    if (v0172 == nil) goto v0178;
    v0172 = stack[-9];
    fn = elt(env, 17); // lnc
    v0173 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-3] = v0173;
    v0172 = (LispObject)17; // 1
    v0172 = Lneq(nil, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    goto v0056;

v0056:
    if (v0172 == nil) goto v0179;
    v0172 = stack[-3];
    fn = elt(env, 18); // !:recip
    v0173 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = stack[-9];
    fn = elt(env, 19); // multd
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-9] = v0172;
    v0173 = stack[-3];
    v0172 = stack[-6];
    fn = elt(env, 19); // multd
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-6] = v0172;
    goto v0179;

v0179:
    v0173 = stack[-6];
    v0172 = stack[-4];
    fn = elt(env, 20); // degr
    v0173 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = (LispObject)1; // 0
    v0172 = (LispObject)greaterp2(v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    v0172 = v0172 ? lisp_true : nil;
    env = stack[-11];
    if (v0172 == nil) goto v0180;
    v0173 = stack[-6];
    v0172 = stack[-9];
    fn = elt(env, 15); // gcdf
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[0] = v0172;
    v0173 = stack[-9];
    v0172 = stack[0];
    if (equal(v0173, v0172)) goto v0181;
    v0173 = stack[-9];
    v0172 = stack[0];
    fn = elt(env, 21); // quotf
    v0174 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0173 = stack[-10];
    v0172 = stack[-2];
    v0172 = acons(v0174, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-2] = v0172;
    goto v0181;

v0181:
    v0173 = stack[-6];
    v0172 = stack[0];
    fn = elt(env, 21); // quotf
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-6] = v0172;
    v0172 = stack[0];
    stack[-9] = v0172;
    v0172 = stack[-10];
    v0172 = add1(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-10] = v0172;
    goto v0179;

v0180:
    v0172 = stack[-1];
    if (v0172 == nil) goto v0182;
    v0172 = elt(env, 9); // rounded
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    fn = elt(env, 12); // on
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0173 = stack[-9];
    v0172 = (LispObject)17; // 1
    v0172 = cons(v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    fn = elt(env, 13); // resimp
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = qcar(v0172);
    stack[-9] = v0172;
    v0172 = stack[-2];
    stack[-4] = v0172;
    v0172 = stack[-4];
    if (v0172 == nil) goto v0183;
    v0172 = stack[-4];
    v0172 = qcar(v0172);
    stack[0] = v0172;
    v0172 = stack[0];
    v0173 = qcar(v0172);
    v0172 = (LispObject)17; // 1
    v0172 = cons(v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    fn = elt(env, 13); // resimp
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0173 = qcar(v0172);
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    v0172 = cons(v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-2] = v0172;
    stack[-3] = v0172;
    goto v0184;

v0184:
    v0172 = stack[-4];
    v0172 = qcdr(v0172);
    stack[-4] = v0172;
    v0172 = stack[-4];
    if (v0172 == nil) goto v0185;
    stack[-1] = stack[-2];
    v0172 = stack[-4];
    v0172 = qcar(v0172);
    stack[0] = v0172;
    v0172 = stack[0];
    v0173 = qcar(v0172);
    v0172 = (LispObject)17; // 1
    v0172 = cons(v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    fn = elt(env, 13); // resimp
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0173 = qcar(v0172);
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    v0172 = cons(v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = Lrplacd(nil, stack[-1], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = stack[-2];
    v0172 = qcdr(v0172);
    stack[-2] = v0172;
    goto v0184;

v0185:
    v0172 = stack[-3];
    goto v0186;

v0186:
    stack[-2] = v0172;
    goto v0182;

v0182:
    v0173 = stack[-6];
    v0172 = (LispObject)17; // 1
    if (v0173 == v0172) goto v0187;
    v0173 = stack[-6];
    v0172 = stack[-7];
    v0172 = Lassoc(nil, v0173, v0172);
    goto v0188;

v0188:
    if (v0172 == nil) goto v0189;
    v0172 = (LispObject)17; // 1
    stack[-6] = v0172;
    goto v0189;

v0189:
    v0173 = stack[-6];
    v0172 = (LispObject)17; // 1
    if (v0173 == v0172) goto v0190;
    v0173 = stack[-10];
    v0172 = (LispObject)17; // 1
    if (v0173 == v0172) goto v0191;
    v0173 = (LispObject)17; // 1
    v0172 = stack[-2];
    fn = elt(env, 22); // rassoc
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[0] = v0172;
    if (v0172 == nil) goto v0192;
    stack[-1] = stack[0];
    v0173 = stack[-6];
    v0172 = stack[0];
    v0172 = qcar(v0172);
    fn = elt(env, 23); // multf
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    v0172 = Lrplaca(nil, stack[-1], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    goto v0190;

v0190:
    v0174 = stack[-9];
    v0173 = stack[-10];
    v0172 = stack[-2];
    v0172 = acons(v0174, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    qvalue(elt(env, 2)) = stack[-5]; // !*msg
    qvalue(elt(env, 1)) = stack[-8]; // !*gcd
    { popv(12); return onevalue(v0172); }

v0192:
    v0172 = stack[-2];
    if (v0172 == nil) goto v0193;
    v0172 = qvalue(elt(env, 8)); // nil
    goto v0194;

v0194:
    if (v0172 == nil) goto v0195;
    v0173 = stack[0];
    v0172 = stack[-9];
    fn = elt(env, 23); // multf
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-9] = v0172;
    goto v0190;

v0195:
    v0172 = stack[-6];
    if (!consp(v0172)) goto v0196;
    v0172 = stack[-6];
    v0172 = qcar(v0172);
    v0172 = (consp(v0172) ? nil : lisp_true);
    goto v0197;

v0197:
    if (v0172 == nil) goto v0198;
    v0175 = elt(env, 11); // "sqfrf failure"
    v0174 = stack[-9];
    v0173 = stack[-10];
    v0172 = stack[-2];
    v0172 = list4(v0175, v0174, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    fn = elt(env, 24); // errach
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    goto v0190;

v0198:
    stack[0] = stack[-2];
    v0173 = stack[-6];
    v0172 = (LispObject)17; // 1
    v0172 = cons(v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    fn = elt(env, 25); // aconc
    v0172 = (*qfn2(fn))(qenv(fn), stack[0], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-2] = v0172;
    goto v0190;

v0196:
    v0172 = qvalue(elt(env, 3)); // t
    goto v0197;

v0193:
    v0173 = stack[-6];
    v0172 = stack[-10];
    fn = elt(env, 26); // rootxf
    v0173 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[0] = v0173;
    v0172 = elt(env, 10); // failed
    v0172 = Lneq(nil, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    goto v0194;

v0191:
    v0173 = stack[-6];
    v0172 = stack[-9];
    fn = elt(env, 23); // multf
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-11];
    stack[-9] = v0172;
    goto v0190;

v0187:
    v0172 = qvalue(elt(env, 8)); // nil
    goto v0188;

v0183:
    v0172 = qvalue(elt(env, 8)); // nil
    goto v0186;

v0178:
    v0172 = qvalue(elt(env, 8)); // nil
    goto v0056;
// error exit handlers
v0177:
    env = stack[-11];
    qvalue(elt(env, 6)) = stack[0]; // !*ezgcd
    qvalue(elt(env, 2)) = stack[-5]; // !*msg
    qvalue(elt(env, 1)) = stack[-8]; // !*gcd
    popv(12);
    return nil;
v0176:
    env = stack[-11];
    qvalue(elt(env, 2)) = stack[-5]; // !*msg
    qvalue(elt(env, 1)) = stack[-8]; // !*gcd
    popv(12);
    return nil;
}



// Code for !*invsq

static LispObject CC_Hinvsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0032, v0033;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *invsq");
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
    v0033 = v0000;
// end of prologue
    v0032 = qvalue(elt(env, 1)); // sqrtflag
    if (v0032 == nil) goto v0021;
    v0032 = v0033;
    fn = elt(env, 2); // invsq
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // sqrt2top
        return (*qfn1(fn))(qenv(fn), v0032);
    }

v0021:
    v0032 = v0033;
    {
        popv(1);
        fn = elt(env, 2); // invsq
        return (*qfn1(fn))(qenv(fn), v0032);
    }
// error exit handlers
v0034:
    popv(1);
    return nil;
}



// Code for parfool

static LispObject CC_parfool(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for parfool");
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
    v0050 = qcar(v0050);
    if (v0050 == nil) goto v0019;
    v0050 = stack[0];
    v0050 = qcar(v0050);
    if (!(is_number(v0050))) goto v0200;
    v0050 = stack[0];
    v0051 = qcdr(v0050);
    v0050 = (LispObject)17; // 1
    v0050 = Leqn(nil, v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    if (v0050 == nil) goto v0200;
    v0050 = stack[0];
    v0051 = qcdr(v0050);
    v0050 = (LispObject)1; // 0
    v0050 = (LispObject)lessp2(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    v0050 = v0050 ? lisp_true : nil;
    env = stack[-1];
    if (v0050 == nil) goto v0200;
    v0050 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0050); }

v0200:
    v0050 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0050); }

v0019:
    v0050 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0050); }
// error exit handlers
v0011:
    popv(2);
    return nil;
}



// Code for dim!<!=deg

static LispObject CC_dimRMdeg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0088, v0050;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dim<=deg");
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
    v0088 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // dimex!*
    fn = elt(env, 4); // deg!*form
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-1];
    fn = elt(env, 5); // negf
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-1];
    fn = elt(env, 6); // addf
    v0088 = (*qfn2(fn))(qenv(fn), stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-1];
    v0050 = v0088;
    v0088 = v0050;
    if (v0088 == nil) goto v0033;
    v0088 = v0050;
    v0088 = integerp(v0088);
    if (v0088 == nil) goto v0095;
    v0088 = (LispObject)1; // 0
        popv(2);
        return Lleq(nil, v0050, v0088);

v0095:
    v0088 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0088); }

v0033:
    v0088 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0088); }
// error exit handlers
v0201:
    popv(2);
    return nil;
}



// Code for ratmean

static LispObject CC_ratmean(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0032, v0033, v0034;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratmean");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0032 = v0037;
    v0033 = v0000;
// end of prologue
    v0034 = v0033;
    v0033 = v0032;
    v0032 = qvalue(elt(env, 1)); // t
    {
        fn = elt(env, 2); // ratplusm
        return (*qfnn(fn))(qenv(fn), 3, v0034, v0033, v0032);
    }
}



// Code for endofstmtp

static LispObject CC_endofstmtp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0032, v0033;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endofstmtp");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for endofstmtp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// end of prologue
    v0033 = qvalue(elt(env, 1)); // cursym!*
    v0032 = elt(env, 2); // (!*semicol!* !*rsqbkt!* end)
    v0032 = Lmember(nil, v0033, v0032);
    if (v0032 == nil) goto v0019;
    v0032 = qvalue(elt(env, 3)); // t
    return onevalue(v0032);

v0019:
    v0032 = nil;
    return onevalue(v0032);
}



// Code for reddom_zeros

static LispObject CC_reddom_zeros(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0023, v0203, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reddom_zeros");
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
    v0203 = v0000;
// end of prologue

v0019:
    v0023 = v0203;
    if (v0023 == nil) goto v0087;
    v0023 = v0203;
    v0058 = qcar(v0023);
    v0023 = (LispObject)1; // 0
    if (v0058 == v0023) goto v0020;
    v0023 = v0203;
    v0023 = qcdr(v0023);
    v0203 = v0023;
    goto v0019;

v0020:
    v0023 = v0203;
    v0023 = qcdr(v0023);
    v0023 = CC_reddom_zeros(env, v0023);
    errexit();
    return add1(v0023);

v0087:
    v0023 = (LispObject)1; // 0
    return onevalue(v0023);
}



// Code for fs!:zerop!:

static LispObject CC_fsTzeropT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027, v0026, v0044;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:zerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0044 = v0000;
// end of prologue
    v0027 = v0044;
    if (v0027 == nil) goto v0019;
    v0027 = v0044;
    if (is_number(v0027)) goto v0053;
    v0027 = v0044;
    v0027 = qcdr(v0027);
    v0027 = (v0027 == nil ? lisp_true : nil);
    goto v0033;

v0033:
    if (v0027 == nil) goto v0078;
    v0027 = qvalue(elt(env, 1)); // t
    return onevalue(v0027);

v0078:
    v0027 = v0044;
    v0026 = qcdr(v0027);
    v0027 = (LispObject)49; // 3
    v0027 = *(LispObject *)((char *)v0026 + (CELL-TAG_VECTOR) + ((int32_t)v0027/(16/CELL)));
    if (v0027 == nil) goto v0201;
    v0027 = qvalue(elt(env, 2)); // nil
    return onevalue(v0027);

v0201:
    v0027 = v0044;
    v0026 = qcdr(v0027);
    v0027 = (LispObject)1; // 0
    v0027 = *(LispObject *)((char *)v0026 + (CELL-TAG_VECTOR) + ((int32_t)v0027/(16/CELL)));
    v0026 = v0027;
    v0027 = v0026;
    if (is_number(v0027)) goto v0101;
    v0027 = qvalue(elt(env, 2)); // nil
    return onevalue(v0027);

v0101:
    v0027 = v0026;
        return Lzerop(nil, v0027);

v0053:
    v0027 = qvalue(elt(env, 2)); // nil
    goto v0033;

v0019:
    v0027 = qvalue(elt(env, 1)); // t
    return onevalue(v0027);
}



// Code for red_prepare

static LispObject CC_red_prepare(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0096;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_prepare");
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
    v0096 = stack[-1];
    fn = elt(env, 1); // bas_nr
    stack[-2] = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0096 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    stack[0] = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0096 = stack[-1];
    fn = elt(env, 3); // bas_rep
    stack[-1] = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0096 = (LispObject)1; // 0
    fn = elt(env, 4); // dp_from_ei
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    fn = elt(env, 5); // dp_sum
    v0096 = (*qfn2(fn))(qenv(fn), stack[-1], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    {
        LispObject v0023 = stack[-2];
        LispObject v0203 = stack[0];
        popv(4);
        fn = elt(env, 6); // bas_make1
        return (*qfnn(fn))(qenv(fn), 3, v0023, v0203, v0096);
    }
// error exit handlers
v0014:
    popv(4);
    return nil;
}



// Code for cl_atml1

static LispObject CC_cl_atml1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0020;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atml1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0021 = v0000;
// end of prologue
    v0020 = v0021;
    v0021 = elt(env, 1); // cl_atmlc
    {
        fn = elt(env, 2); // cl_f2ml
        return (*qfn2(fn))(qenv(fn), v0020, v0021);
    }
}



// Code for pasf_leqp

static LispObject CC_pasf_leqp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0207, v0057, v0208, v0209;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_leqp");
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
    v0057 = v0037;
    v0208 = v0000;
// end of prologue
    v0207 = v0208;
    if (!(v0207 == nil)) goto v0083;
    v0207 = (LispObject)1; // 0
    v0208 = v0207;
    goto v0083;

v0083:
    v0207 = v0057;
    if (!(v0207 == nil)) goto v0084;
    v0207 = (LispObject)1; // 0
    v0057 = v0207;
    goto v0084;

v0084:
    v0209 = v0208;
    v0207 = elt(env, 1); // minf
    if (v0209 == v0207) goto v0095;
    v0209 = v0057;
    v0207 = elt(env, 3); // pinf
    if (v0209 == v0207) goto v0024;
    v0209 = v0208;
    v0207 = elt(env, 3); // pinf
    if (v0209 == v0207) goto v0091;
    v0209 = v0057;
    v0207 = elt(env, 1); // minf
    if (v0209 == v0207) goto v0007;
    v0207 = v0208;
    v0207 = (LispObject)lesseq2(v0207, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    v0207 = v0207 ? lisp_true : nil;
    env = stack[0];
    goto v0053;

v0053:
    if (v0207 == nil) goto v0040;
    v0207 = qvalue(elt(env, 2)); // t
    { popv(1); return onevalue(v0207); }

v0040:
    v0207 = nil;
    { popv(1); return onevalue(v0207); }

v0007:
    v0207 = qvalue(elt(env, 4)); // nil
    goto v0053;

v0091:
    v0207 = qvalue(elt(env, 4)); // nil
    goto v0053;

v0024:
    v0207 = qvalue(elt(env, 2)); // t
    goto v0053;

v0095:
    v0207 = qvalue(elt(env, 2)); // t
    goto v0053;
// error exit handlers
v0210:
    popv(1);
    return nil;
}



// Code for vsl_boundtype1

static LispObject CC_vsl_boundtype1(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0081, v0082, v0211, v0048;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vsl_boundtype1");
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
    v0048 = v0037;
    v0211 = v0000;
// end of prologue

v0115:
    v0081 = v0211;
    if (!consp(v0081)) goto v0103;
    v0081 = v0211;
    v0081 = qcar(v0081);
    v0081 = (consp(v0081) ? nil : lisp_true);
    goto v0020;

v0020:
    if (v0081 == nil) goto v0096;
    v0081 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0081); }

v0096:
    v0081 = v0211;
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    v0082 = qcar(v0081);
    v0081 = v0048;
    if (v0082 == v0081) goto v0053;
    v0081 = v0211;
    v0081 = qcdr(v0081);
    v0211 = v0081;
    goto v0115;

v0053:
    v0081 = v0211;
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    fn = elt(env, 5); // minusf
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[0];
    if (v0081 == nil) goto v0080;
    v0081 = elt(env, 3); // ub
    { popv(1); return onevalue(v0081); }

v0080:
    v0081 = elt(env, 4); // lb
    { popv(1); return onevalue(v0081); }

v0103:
    v0081 = qvalue(elt(env, 1)); // t
    goto v0020;
// error exit handlers
v0049:
    popv(1);
    return nil;
}



// Code for intconv

static LispObject CC_intconv(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0054, v0072, v0200;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intconv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0200 = v0000;
// end of prologue
    v0054 = qvalue(elt(env, 1)); // dmode!*
    if (v0054 == nil) goto v0085;
    v0072 = qvalue(elt(env, 1)); // dmode!*
    v0054 = elt(env, 3); // (!:rd!: !:cr!:)
    v0054 = Lmemq(nil, v0072, v0054);
    goto v0087;

v0087:
    if (!(v0054 == nil)) return onevalue(v0200);
    v0054 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0054)) v0054 = nil;
    else { v0054 = qfastgets(v0054);
           if (v0054 != nil) { v0054 = elt(v0054, 34); // i2d
#ifdef RECORD_GET
             if (v0054 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0054 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0054 == SPID_NOPROP) v0054 = nil; }}
#endif
    v0072 = v0200;
        return Lapply1(nil, v0054, v0072);

v0085:
    v0054 = qvalue(elt(env, 2)); // t
    goto v0087;
}



// Code for sprow_dim

static LispObject CC_sprow_dim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0052;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sprow_dim");
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
    v0052 = qvalue(elt(env, 1)); // !*fast_la
    if (v0052 == nil) goto v0020;
    v0052 = qvalue(elt(env, 2)); // nil
    goto v0021;

v0021:
    if (v0052 == nil) goto v0083;
    v0052 = elt(env, 3); // "Error in sprow_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    goto v0083;

v0083:
    v0052 = stack[0];
    fn = elt(env, 5); // spmatlength
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    v0052 = qcdr(v0052);
    v0052 = qcar(v0052);
    { popv(2); return onevalue(v0052); }

v0020:
    v0052 = stack[0];
    fn = elt(env, 6); // matrixp
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    v0052 = (v0052 == nil ? lisp_true : nil);
    goto v0021;
// error exit handlers
v0023:
    popv(2);
    return nil;
}



// Code for vdpsimpcont

static LispObject CC_vdpsimpcont(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027, v0026, v0044;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpsimpcont");
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
    v0027 = stack[-1];
    v0027 = qcdr(v0027);
    v0027 = qcdr(v0027);
    v0027 = qcdr(v0027);
    v0027 = qcar(v0027);
    stack[0] = v0027;
    v0027 = stack[0];
    if (v0027 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0027 = stack[0];
    fn = elt(env, 3); // dipsimpcont
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    stack[-2] = v0027;
    v0027 = stack[-2];
    v0027 = qcdr(v0027);
    fn = elt(env, 4); // dip2vdp
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    stack[-1] = v0027;
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    stack[-2] = v0027;
    v0027 = stack[-2];
    fn = elt(env, 5); // evzero!?
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    if (v0027 == nil) goto v0203;
    v0027 = qvalue(elt(env, 1)); // nil
    goto v0023;

v0023:
    if (v0027 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0044 = stack[-1];
    v0026 = elt(env, 2); // monfac
    v0027 = stack[-2];
    fn = elt(env, 6); // vdpputprop
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0044, v0026, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0203:
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    v0027 = qcdr(v0027);
    if (!(v0027 == nil)) goto v0023;
    v0027 = stack[-2];
    fn = elt(env, 7); // evtdeg
    v0026 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    v0027 = (LispObject)17; // 1
    v0027 = (LispObject)greaterp2(v0026, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    v0027 = v0027 ? lisp_true : nil;
    env = stack[-3];
    goto v0023;
// error exit handlers
v0206:
    popv(4);
    return nil;
}



// Code for mk_parents_prim

static LispObject CC_mk_parents_prim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0088, v0050;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_parents_prim");
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
    v0088 = stack[0];
    v0050 = Llength(nil, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-1];
    v0088 = (LispObject)49; // 3
    if (!(v0050 == v0088)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0088 = stack[0];
    fn = elt(env, 1); // s_noparents
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-1];
    v0050 = v0088;
    if (v0050 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0050 = stack[0];
    v0088 = qcar(v0088);
    fn = elt(env, 2); // mk_edge_parents
    v0088 = (*qfn2(fn))(qenv(fn), v0050, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0201:
    popv(2);
    return nil;
}



// Code for get!-all!-kernels

static LispObject CC_getKallKkernels(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0010;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-all-kernels");
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
    goto v0083;

v0083:
    v0101 = stack[-2];
    if (!consp(v0101)) goto v0087;
    v0101 = stack[-2];
    v0101 = qcar(v0101);
    fn = elt(env, 2); // simp
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    stack[-1] = v0101;
    v0101 = stack[-1];
    v0101 = qcar(v0101);
    fn = elt(env, 3); // kernels
    stack[0] = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    v0101 = stack[-1];
    v0101 = qcdr(v0101);
    fn = elt(env, 3); // kernels
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    fn = elt(env, 4); // union
    v0010 = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    v0101 = stack[-3];
    v0101 = cons(v0010, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    stack[-3] = v0101;
    v0101 = stack[-2];
    v0101 = qcdr(v0101);
    stack[-2] = v0101;
    goto v0083;

v0087:
    v0101 = qvalue(elt(env, 1)); // nil
    v0010 = v0101;
    goto v0085;

v0085:
    v0101 = stack[-3];
    if (v0101 == nil) { popv(5); return onevalue(v0010); }
    v0101 = stack[-3];
    v0101 = qcar(v0101);
    fn = elt(env, 4); // union
    v0101 = (*qfn2(fn))(qenv(fn), v0101, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-4];
    v0010 = v0101;
    v0101 = stack[-3];
    v0101 = qcdr(v0101);
    stack[-3] = v0101;
    goto v0085;
// error exit handlers
v0006:
    popv(5);
    return nil;
}



// Code for test!-bool

static LispObject CC_testKbool(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0085;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for test-bool");
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
    v0085 = v0000;
// end of prologue
    v0085 = qcar(v0085);
    fn = elt(env, 1); // boolean!-eval1
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[0];
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[0];
    fn = elt(env, 2); // simp!-prop
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // mk!*sq
        return (*qfn1(fn))(qenv(fn), v0085);
    }
// error exit handlers
v0015:
    popv(1);
    return nil;
}



// Code for bagp

static LispObject CC_bagp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bagp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0040 = v0000;
// end of prologue
    v0039 = v0040;
    if (!consp(v0039)) goto v0034;
    v0039 = v0040;
    v0039 = qcar(v0039);
    v0040 = elt(env, 1); // bag
        return Lflagp(nil, v0039, v0040);

v0034:
    v0039 = qvalue(elt(env, 2)); // nil
    return onevalue(v0039);
}



// Code for sq_member

static LispObject CC_sq_member(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0096, v0084;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sq_member");
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
    v0084 = stack[-1];
    v0096 = stack[0];
    v0096 = qcar(v0096);
    fn = elt(env, 1); // sf_member
    v0096 = (*qfn2(fn))(qenv(fn), v0084, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    if (!(v0096 == nil)) { popv(3); return onevalue(v0096); }
    v0084 = stack[-1];
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    {
        popv(3);
        fn = elt(env, 1); // sf_member
        return (*qfn2(fn))(qenv(fn), v0084, v0096);
    }
// error exit handlers
v0014:
    popv(3);
    return nil;
}



// Code for xadd!*

static LispObject CC_xaddH(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0230, v0231, v0232;
    LispObject fn;
    LispObject v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xadd*");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xadd*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0036,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-9] = v0036;
    stack[-10] = v0037;
    stack[-11] = v0000;
// end of prologue
    v0230 = stack[-10];
    stack[-12] = v0230;
    goto v0020;

v0020:
    v0230 = stack[-12];
    if (v0230 == nil) goto v0021;
    v0230 = stack[-11];
    v0231 = qcar(v0230);
    v0230 = stack[-12];
    v0230 = qcar(v0230);
    v0230 = qcar(v0230);
    if (equal(v0231, v0230)) goto v0199;
    v0230 = qvalue(elt(env, 1)); // nil
    goto v0040;

v0040:
    if (!(v0230 == nil)) goto v0021;
    v0230 = stack[-12];
    v0230 = qcdr(v0230);
    stack[-12] = v0230;
    goto v0020;

v0021:
    v0230 = stack[-12];
    if (v0230 == nil) goto v0048;
    v0230 = stack[-12];
    v0231 = qcar(v0230);
    v0230 = stack[-10];
    v0230 = Ldelete(nil, v0231, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    stack[-10] = v0230;
    v0230 = stack[-12];
    v0230 = qcar(v0230);
    stack[-12] = v0230;
    v0230 = stack[-9];
    if (v0230 == nil) goto v0048;
    v0230 = qvalue(elt(env, 2)); // newrule!*
    if (v0230 == nil) goto v0048;
    v0230 = stack[-12];
    v0231 = qcar(v0230);
    v0230 = qvalue(elt(env, 2)); // newrule!*
    v0230 = qcar(v0230);
    stack[0] = v0230;
    if (equal(v0231, v0230)) goto v0234;
    v0230 = stack[-12];
    v0230 = qcar(v0230);
    fn = elt(env, 7); // powlisp
    v0230 = (*qfn1(fn))(qenv(fn), v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    goto v0005;

v0005:
    if (v0230 == nil) goto v0235;
    stack[-8] = elt(env, 3); // plus
    stack[-7] = stack[0];
    stack[-6] = elt(env, 4); // difference
    v0230 = stack[-12];
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    stack[-5] = qcar(v0230);
    stack[-4] = elt(env, 5); // times
    v0230 = stack[-12];
    v0230 = qcar(v0230);
    stack[-3] = v0230;
    v0230 = stack[-3];
    if (v0230 == nil) goto v0097;
    v0230 = stack[-3];
    v0230 = qcar(v0230);
    v0232 = elt(env, 6); // expt
    v0231 = v0230;
    v0231 = qcar(v0231);
    v0230 = qcdr(v0230);
    v0230 = list3(v0232, v0231, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    v0230 = ncons(v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    stack[-1] = v0230;
    stack[-2] = v0230;
    goto v0236;

v0236:
    v0230 = stack[-3];
    v0230 = qcdr(v0230);
    stack[-3] = v0230;
    v0230 = stack[-3];
    if (v0230 == nil) goto v0237;
    stack[0] = stack[-1];
    v0230 = stack[-3];
    v0230 = qcar(v0230);
    v0232 = elt(env, 6); // expt
    v0231 = v0230;
    v0231 = qcar(v0231);
    v0230 = qcdr(v0230);
    v0230 = list3(v0232, v0231, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    v0230 = ncons(v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    v0230 = Lrplacd(nil, stack[0], v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    v0230 = stack[-1];
    v0230 = qcdr(v0230);
    stack[-1] = v0230;
    goto v0236;

v0237:
    v0230 = stack[-2];
    goto v0073;

v0073:
    v0230 = cons(stack[-4], v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    v0230 = list3(stack[-6], stack[-5], v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    v0230 = list3(stack[-8], stack[-7], v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    fn = elt(env, 8); // simp
    v0230 = (*qfn1(fn))(qenv(fn), v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    fn = elt(env, 9); // prepsq
    v0231 = (*qfn1(fn))(qenv(fn), v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    v0230 = stack[-12];
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    fn = elt(env, 10); // updoldrules
    v0230 = (*qfn2(fn))(qenv(fn), v0231, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    goto v0048;

v0048:
    v0230 = stack[-9];
    if (v0230 == nil) { LispObject res = stack[-10]; popv(14); return onevalue(res); }
    v0231 = stack[-11];
    v0230 = stack[-10];
    v0230 = cons(v0231, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    stack[-10] = v0230;
    { LispObject res = stack[-10]; popv(14); return onevalue(res); }

v0097:
    v0230 = qvalue(elt(env, 1)); // nil
    goto v0073;

v0235:
    v0230 = stack[-12];
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0231 = qcar(v0230);
    v0230 = stack[-12];
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    fn = elt(env, 10); // updoldrules
    v0230 = (*qfn2(fn))(qenv(fn), v0231, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-13];
    goto v0048;

v0234:
    v0230 = qvalue(elt(env, 1)); // nil
    goto v0005;

v0199:
    v0230 = stack[-11];
    v0230 = qcdr(v0230);
    v0231 = qcar(v0230);
    v0230 = stack[-12];
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    v0230 = (equal(v0231, v0230) ? lisp_true : nil);
    goto v0040;
// error exit handlers
v0233:
    popv(14);
    return nil;
}



// Code for cl_simpl1

static LispObject CC_cl_simpl1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0328, v0329, v0330, v0331;
    LispObject fn;
    LispObject v0045, v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_simpl1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_simpl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0045,v0036,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0037,v0036,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0045;
    stack[-1] = v0036;
    stack[-2] = v0037;
    stack[-3] = v0000;
// end of prologue
    v0329 = stack[-1];
    v0328 = (LispObject)1; // 0
    v0328 = Leqn(nil, v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    if (!(v0328 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0328 = stack[-3];
    if (!consp(v0328)) goto v0013;
    v0328 = stack[-3];
    v0328 = qcar(v0328);
    goto v0084;

v0084:
    stack[-4] = v0328;
    v0329 = stack[-4];
    v0328 = elt(env, 1); // true
    if (v0329 == v0328) goto v0051;
    v0329 = stack[-4];
    v0328 = elt(env, 3); // false
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0050;

v0050:
    if (!(v0328 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0329 = stack[-4];
    v0328 = elt(env, 4); // or
    if (v0329 == v0328) goto v0041;
    v0329 = stack[-4];
    v0328 = elt(env, 5); // and
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0044;

v0044:
    if (v0328 == nil) goto v0333;
    v0331 = stack[-4];
    v0328 = stack[-3];
    v0330 = qcdr(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    fn = elt(env, 17); // cl_smsimpl!-junct
    v0328 = (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    v0328 = v0329;
    if (v0328 == nil) goto v0002;
    v0328 = v0329;
    v0328 = qcdr(v0328);
    if (v0328 == nil) goto v0002;
    v0328 = stack[-4];
    popv(6);
    return cons(v0328, v0329);

v0002:
    v0328 = v0329;
    if (v0328 == nil) goto v0062;
    v0328 = v0329;
    v0328 = qcar(v0328);
    { popv(6); return onevalue(v0328); }

v0062:
    v0329 = stack[-4];
    v0328 = elt(env, 5); // and
    if (v0329 == v0328) goto v0219;
    v0328 = elt(env, 3); // false
    { popv(6); return onevalue(v0328); }

v0219:
    v0328 = elt(env, 1); // true
    { popv(6); return onevalue(v0328); }

v0333:
    v0329 = stack[-4];
    v0328 = elt(env, 6); // not
    if (v0329 == v0328) goto v0100;
    v0329 = stack[-4];
    v0328 = elt(env, 7); // ex
    if (v0329 == v0328) goto v0334;
    v0329 = stack[-4];
    v0328 = elt(env, 8); // all
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0335;

v0335:
    if (v0328 == nil) goto v0336;
    v0328 = qvalue(elt(env, 9)); // !*rlsism
    if (v0328 == nil) goto v0337;
    v0329 = stack[-2];
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcar(v0328);
    fn = elt(env, 18); // rl_smrmknowl
    v0328 = (*qfn2(fn))(qenv(fn), v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-2] = v0328;
    goto v0337;

v0337:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcdr(v0328);
    stack[0] = qcar(v0328);
    v0328 = stack[-1];
    v0329 = sub1(v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0328 = stack[-4];
    v0328 = CC_cl_simpl1(env, 4, stack[0], stack[-2], v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-1] = v0328;
    v0329 = stack[-1];
    v0328 = elt(env, 1); // true
    if (v0329 == v0328) goto v0188;
    v0329 = stack[-1];
    v0328 = elt(env, 3); // false
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0136;

v0136:
    if (!(v0328 == nil)) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    stack[0] = qcar(v0328);
    v0328 = stack[-1];
    fn = elt(env, 19); // cl_fvarl
    v0328 = (*qfn1(fn))(qenv(fn), v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    v0328 = Lmemq(nil, stack[0], v0328);
    if (v0328 == nil) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0330 = stack[-4];
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0329 = qcar(v0328);
    v0328 = stack[-1];
    popv(6);
    return list3(v0330, v0329, v0328);

v0188:
    v0328 = qvalue(elt(env, 2)); // t
    goto v0136;

v0336:
    v0329 = stack[-4];
    v0328 = elt(env, 10); // bex
    if (v0329 == v0328) goto v0338;
    v0329 = stack[-4];
    v0328 = elt(env, 11); // ball
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0339;

v0339:
    if (v0328 == nil) goto v0340;
    v0328 = qvalue(elt(env, 9)); // !*rlsism
    if (v0328 == nil) goto v0193;
    v0329 = stack[-2];
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcar(v0328);
    fn = elt(env, 18); // rl_smrmknowl
    v0328 = (*qfn2(fn))(qenv(fn), v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-2] = v0328;
    goto v0193;

v0193:
    v0330 = stack[-3];
    v0329 = stack[-2];
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 20); // cl_simplbq
        return (*qfnn(fn))(qenv(fn), 3, v0330, v0329, v0328);
    }

v0340:
    v0329 = stack[-4];
    v0328 = elt(env, 12); // impl
    if (v0329 == v0328) goto v0197;
    v0329 = stack[-4];
    v0328 = elt(env, 13); // repl
    if (v0329 == v0328) goto v0341;
    v0329 = stack[-4];
    v0328 = elt(env, 14); // equiv
    if (v0329 == v0328) goto v0342;
    v0329 = stack[-4];
    v0328 = elt(env, 15); // cl_simpl
    fn = elt(env, 21); // rl_external
    v0328 = (*qfn2(fn))(qenv(fn), v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    if (v0328 == nil) goto v0343;
    stack[0] = v0329;
    v0328 = stack[-3];
    v0328 = ncons(v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    {
        LispObject v0344 = stack[0];
        popv(6);
        fn = elt(env, 22); // apply
        return (*qfn2(fn))(qenv(fn), v0344, v0328);
    }

v0343:
    v0329 = stack[-3];
    v0328 = stack[0];
    fn = elt(env, 23); // cl_simplat
    v0328 = (*qfn2(fn))(qenv(fn), v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    v0328 = qvalue(elt(env, 9)); // !*rlsism
    if (v0328 == nil) goto v0345;
    v0328 = v0329;
    if (!consp(v0328)) goto v0346;
    v0328 = v0329;
    v0328 = qcar(v0328);
    goto v0347;

v0347:
    stack[-4] = v0328;
    v0330 = stack[-4];
    v0328 = elt(env, 4); // or
    if (v0330 == v0328) goto v0348;
    v0330 = stack[-4];
    v0328 = elt(env, 5); // and
    v0328 = (v0330 == v0328 ? lisp_true : nil);
    goto v0349;

v0349:
    if (v0328 == nil) goto v0350;
    v0331 = stack[-4];
    v0328 = v0329;
    v0330 = qcdr(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    fn = elt(env, 17); // cl_smsimpl!-junct
    v0328 = (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    v0328 = v0329;
    if (v0328 == nil) goto v0351;
    v0328 = v0329;
    v0328 = qcdr(v0328);
    if (v0328 == nil) goto v0351;
    v0328 = stack[-4];
    popv(6);
    return cons(v0328, v0329);

v0351:
    v0328 = v0329;
    if (v0328 == nil) goto v0352;
    v0328 = v0329;
    v0328 = qcar(v0328);
    { popv(6); return onevalue(v0328); }

v0352:
    v0329 = stack[-4];
    v0328 = elt(env, 5); // and
    if (v0329 == v0328) goto v0353;
    v0328 = elt(env, 3); // false
    { popv(6); return onevalue(v0328); }

v0353:
    v0328 = elt(env, 1); // true
    { popv(6); return onevalue(v0328); }

v0350:
    v0330 = stack[-4];
    v0328 = elt(env, 1); // true
    if (v0330 == v0328) goto v0354;
    v0330 = stack[-4];
    v0328 = elt(env, 3); // false
    v0328 = (v0330 == v0328 ? lisp_true : nil);
    goto v0355;

v0355:
    if (!(v0328 == nil)) { popv(6); return onevalue(v0329); }
    stack[-3] = elt(env, 5); // and
    v0328 = v0329;
    stack[0] = ncons(v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0328 = stack[-2];
    fn = elt(env, 24); // rl_smcpknowl
    v0329 = (*qfn1(fn))(qenv(fn), v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0328 = stack[-1];
    fn = elt(env, 25); // rl_smupdknowl
    v0328 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[0], v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = v0328;
    v0329 = elt(env, 3); // false
    if (v0330 == v0329) goto v0356;
    v0331 = elt(env, 5); // and
    v0330 = stack[-2];
    v0329 = v0328;
    v0328 = stack[-1];
    fn = elt(env, 26); // rl_smmkatl
    v0328 = (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0329 = v0328;
    v0330 = v0329;
    v0328 = elt(env, 3); // false
    if (v0330 == v0328) goto v0357;
    v0328 = v0329;
    if (v0328 == nil) goto v0358;
    v0328 = v0329;
    v0328 = qcdr(v0328);
    if (v0328 == nil) goto v0358;
    v0328 = elt(env, 5); // and
    popv(6);
    return cons(v0328, v0329);

v0358:
    v0328 = v0329;
    if (v0328 == nil) goto v0359;
    v0328 = v0329;
    v0328 = qcar(v0328);
    { popv(6); return onevalue(v0328); }

v0359:
    v0329 = elt(env, 5); // and
    v0328 = elt(env, 5); // and
    if (v0329 == v0328) goto v0360;
    v0328 = elt(env, 3); // false
    { popv(6); return onevalue(v0328); }

v0360:
    v0328 = elt(env, 1); // true
    { popv(6); return onevalue(v0328); }

v0357:
    v0328 = elt(env, 3); // false
    { popv(6); return onevalue(v0328); }

v0356:
    v0328 = elt(env, 3); // false
    { popv(6); return onevalue(v0328); }

v0354:
    v0328 = qvalue(elt(env, 2)); // t
    goto v0355;

v0348:
    v0328 = qvalue(elt(env, 2)); // t
    goto v0349;

v0346:
    v0328 = v0329;
    goto v0347;

v0345:
    v0328 = v0329;
    if (!(v0328 == nil)) { popv(6); return onevalue(v0329); }
    v0329 = elt(env, 16); // "cl_simpl1(): unknown operator"
    v0328 = stack[-4];
    v0328 = list2(v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    fn = elt(env, 27); // rederr
    v0328 = (*qfn1(fn))(qenv(fn), v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    v0328 = nil;
    { popv(6); return onevalue(v0328); }

v0342:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0331 = qcar(v0328);
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcdr(v0328);
    v0330 = qcar(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 28); // cl_smsimpl!-equiv
        return (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    }

v0341:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcdr(v0328);
    v0331 = qcar(v0328);
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0330 = qcar(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 29); // cl_smsimpl!-imprep
        return (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    }

v0197:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0331 = qcar(v0328);
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    v0328 = qcdr(v0328);
    v0330 = qcar(v0328);
    v0329 = stack[-2];
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 29); // cl_smsimpl!-imprep
        return (*qfnn(fn))(qenv(fn), 4, v0331, v0330, v0329, v0328);
    }

v0338:
    v0328 = qvalue(elt(env, 2)); // t
    goto v0339;

v0334:
    v0328 = qvalue(elt(env, 2)); // t
    goto v0335;

v0100:
    v0328 = stack[-3];
    v0328 = qcdr(v0328);
    stack[0] = qcar(v0328);
    v0328 = stack[-1];
    v0329 = sub1(v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0328 = elt(env, 6); // not
    v0328 = CC_cl_simpl1(env, 4, stack[0], stack[-2], v0329, v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-1] = v0328;
    v0329 = stack[-1];
    v0328 = elt(env, 1); // true
    if (v0329 == v0328) goto v0361;
    v0329 = stack[-1];
    v0328 = elt(env, 3); // false
    v0328 = (v0329 == v0328 ? lisp_true : nil);
    goto v0362;

v0362:
    if (v0328 == nil) goto v0363;
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); // cl_flip
        return (*qfn1(fn))(qenv(fn), v0328);
    }

v0363:
    v0328 = stack[-1];
    fn = elt(env, 31); // cl_atfp
    v0328 = (*qfn1(fn))(qenv(fn), v0328);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    if (v0328 == nil) goto v0223;
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 32); // rl_negateat
        return (*qfn1(fn))(qenv(fn), v0328);
    }

v0223:
    v0328 = stack[-1];
    {
        popv(6);
        fn = elt(env, 33); // cl_negate!-invol
        return (*qfn1(fn))(qenv(fn), v0328);
    }

v0361:
    v0328 = qvalue(elt(env, 2)); // t
    goto v0362;

v0041:
    v0328 = qvalue(elt(env, 2)); // t
    goto v0044;

v0051:
    v0328 = qvalue(elt(env, 2)); // t
    goto v0050;

v0013:
    v0328 = stack[-3];
    goto v0084;
// error exit handlers
v0332:
    popv(6);
    return nil;
}



// Code for pasf_subfof

static LispObject CC_pasf_subfof(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0053, v0095, v0096;
    LispObject fn;
    LispObject v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_subfof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0036,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0053 = v0036;
    v0095 = v0037;
    v0096 = v0000;
// end of prologue
    stack[-1] = v0053;
    stack[0] = elt(env, 1); // pasf_subfof1
    v0053 = v0096;
    v0053 = list2(v0053, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    {
        LispObject v0014 = stack[-1];
        LispObject v0023 = stack[0];
        popv(3);
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(qenv(fn), 3, v0014, v0023, v0053);
    }
// error exit handlers
v0052:
    popv(3);
    return nil;
}



// Code for ofsf_boundchk

static LispObject CC_ofsf_boundchk(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0227, v0321, v0228;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_boundchk");
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
    v0227 = stack[-1];
    v0227 = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    fn = elt(env, 9); // setkorder
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    stack[0] = v0227;
    v0227 = stack[-2];
    v0227 = qcdr(v0227);
    v0227 = qcar(v0227);
    fn = elt(env, 10); // reorder
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    stack[-3] = v0227;
    v0227 = stack[0];
    fn = elt(env, 9); // setkorder
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    v0227 = stack[-3];
    if (!consp(v0227)) goto v0014;
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = (consp(v0227) ? nil : lisp_true);
    goto v0052;

v0052:
    if (v0227 == nil) goto v0201;
    v0227 = qvalue(elt(env, 1)); // t
    goto v0095;

v0095:
    if (v0227 == nil) goto v0368;
    v0227 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0227); }

v0368:
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0321 = qcdr(v0227);
    v0227 = (LispObject)17; // 1
    if (v0321 == v0227) goto v0326;
    v0228 = elt(env, 3); // "ofsf_boundchk:"
    v0321 = stack[-1];
    v0227 = elt(env, 4); // "not linear"
    v0227 = list3(v0228, v0321, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    fn = elt(env, 11); // rederr
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    goto v0326;

v0326:
    v0227 = stack[-3];
    v0227 = qcdr(v0227);
    fn = elt(env, 10); // reorder
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    fn = elt(env, 12); // negf
    v0321 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    v0227 = (LispObject)17; // 1
    stack[0] = cons(v0321, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    fn = elt(env, 10); // reorder
    v0321 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    v0227 = (LispObject)17; // 1
    v0227 = cons(v0321, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    fn = elt(env, 13); // quotsq
    v0227 = (*qfn2(fn))(qenv(fn), stack[0], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    stack[0] = v0227;
    v0227 = stack[-2];
    v0227 = qcar(v0227);
    v0228 = v0227;
    v0321 = v0228;
    v0227 = elt(env, 5); // equal
    if (v0321 == v0227) goto v0060;
    v0321 = v0228;
    v0227 = elt(env, 6); // geq
    stack[-1] = (v0321 == v0227 ? lisp_true : nil);
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    fn = elt(env, 14); // minusf
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    fn = elt(env, 15); // ofsf_xor
    v0227 = (*qfn2(fn))(qenv(fn), stack[-1], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    if (v0227 == nil) goto v0369;
    v0321 = elt(env, 7); // lb
    v0227 = stack[0];
    popv(5);
    return cons(v0321, v0227);

v0369:
    v0321 = elt(env, 8); // ub
    v0227 = stack[0];
    popv(5);
    return cons(v0321, v0227);

v0060:
    v0321 = elt(env, 5); // equal
    v0227 = stack[0];
    popv(5);
    return cons(v0321, v0227);

v0201:
    v0227 = stack[-3];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0321 = qcar(v0227);
    v0227 = stack[-1];
    v0227 = Lneq(nil, v0321, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-4];
    goto v0095;

v0014:
    v0227 = qvalue(elt(env, 1)); // t
    goto v0052;
// error exit handlers
v0237:
    popv(5);
    return nil;
}



// Code for mkunarywedge

static LispObject CC_mkunarywedge(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0199, v0054, v0072;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkunarywedge");
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
    goto v0115;

v0115:
    v0199 = stack[0];
    if (v0199 == nil) goto v0085;
    v0199 = stack[0];
    v0199 = qcar(v0199);
    v0199 = qcar(v0199);
    v0072 = ncons(v0199);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0199 = stack[0];
    v0199 = qcar(v0199);
    v0054 = qcdr(v0199);
    v0199 = stack[-1];
    v0199 = acons(v0072, v0054, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    stack[-1] = v0199;
    v0199 = stack[0];
    v0199 = qcdr(v0199);
    stack[0] = v0199;
    goto v0115;

v0085:
    v0199 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0199);
    }
// error exit handlers
v0088:
    popv(3);
    return nil;
}



// Code for mo!=expvec2a1

static LispObject CC_moMexpvec2a1(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0205, v0076, v0007;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=expvec2a1");
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
    goto v0083;

v0083:
    v0205 = stack[-1];
    if (v0205 == nil) goto v0015;
    v0205 = stack[-1];
    v0076 = qcar(v0205);
    v0205 = (LispObject)1; // 0
    if (v0076 == v0205) goto v0032;
    v0205 = stack[-1];
    v0076 = qcar(v0205);
    v0205 = (LispObject)17; // 1
    if (v0076 == v0205) goto v0050;
    v0007 = elt(env, 1); // expt
    v0205 = stack[0];
    v0076 = qcar(v0205);
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0076 = list3(v0007, v0076, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    v0205 = stack[-2];
    v0205 = cons(v0076, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    stack[-2] = v0205;
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    stack[-1] = v0205;
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    stack[0] = v0205;
    goto v0083;

v0050:
    v0205 = stack[0];
    v0076 = qcar(v0205);
    v0205 = stack[-2];
    v0205 = cons(v0076, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    stack[-2] = v0205;
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    stack[-1] = v0205;
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    stack[0] = v0205;
    goto v0083;

v0032:
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    stack[-1] = v0205;
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    stack[0] = v0205;
    goto v0083;

v0015:
    v0205 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0205);
    }
// error exit handlers
v0178:
    popv(4);
    return nil;
}



// Code for gcd!-in!-vector

static LispObject CC_gcdKinKvector(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0385, v0386, v0387, v0311, v0139, v0140;
    LispObject fn;
    LispObject v0045, v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gcd-in-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcd-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0045,v0036,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0037,v0036,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0045;
    stack[-1] = v0036;
    stack[-2] = v0037;
    stack[-3] = v0000;
// end of prologue
    v0386 = stack[-2];
    v0385 = (LispObject)1; // 0
    if (v0386 == v0385) goto v0033;
    v0386 = stack[0];
    v0385 = (LispObject)1; // 0
    v0385 = (v0386 == v0385 ? lisp_true : nil);
    goto v0032;

v0032:
    if (v0385 == nil) goto v0204;
    v0387 = stack[-3];
    v0386 = (LispObject)1; // 0
    v0385 = (LispObject)17; // 1
    *(LispObject *)((char *)v0387 + (CELL-TAG_VECTOR) + ((int32_t)v0386/(16/CELL))) = v0385;
    v0385 = (LispObject)1; // 0
    { popv(5); return onevalue(v0385); }

v0204:
    v0386 = stack[-2];
    v0385 = (LispObject)1; // 0
    if (((int32_t)(v0386)) < ((int32_t)(v0385))) goto v0070;
    v0386 = stack[0];
    v0385 = (LispObject)1; // 0
    if (!(((int32_t)(v0386)) < ((int32_t)(v0385)))) goto v0041;

v0070:
    v0385 = elt(env, 2); // "GCD with zero not allowed"
    fn = elt(env, 4); // errorf
    v0385 = (*qfn1(fn))(qenv(fn), v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    goto v0041;

v0041:
    v0311 = stack[-3];
    v0387 = stack[-2];
    v0386 = stack[-1];
    v0385 = stack[0];
    fn = elt(env, 5); // remainder!-in!-vector
    v0385 = (*qfnn(fn))(qenv(fn), 4, v0311, v0387, v0386, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0385;
    v0386 = stack[-2];
    v0385 = (LispObject)1; // 0
    if (v0386 == v0385) goto v0065;
    v0386 = stack[-2];
    v0385 = (LispObject)-15; // -1
    if (v0386 == v0385) goto v0030;
    v0311 = stack[-1];
    v0387 = stack[0];
    v0386 = stack[-3];
    v0385 = stack[-2];
    fn = elt(env, 5); // remainder!-in!-vector
    v0385 = (*qfnn(fn))(qenv(fn), 4, v0311, v0387, v0386, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[0] = v0385;
    v0386 = stack[0];
    v0385 = (LispObject)1; // 0
    if (v0386 == v0385) goto v0389;
    v0386 = stack[0];
    v0385 = (LispObject)-15; // -1
    if (!(v0386 == v0385)) goto v0041;
    v0386 = stack[-3];
    v0385 = stack[-2];
    v0385 = *(LispObject *)((char *)v0386 + (CELL-TAG_VECTOR) + ((int32_t)v0385/(16/CELL)));
    v0385 = Lmodular_reciprocal(nil, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0140 = v0385;
    v0386 = v0140;
    v0385 = (LispObject)17; // 1
    if (v0386 == v0385) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0385 = (LispObject)1; // 0
    v0139 = v0385;
    goto v0390;

v0390:
    v0386 = stack[-2];
    v0385 = v0139;
    v0385 = (LispObject)(int32_t)((int32_t)v0386 - (int32_t)v0385 + TAG_FIXNUM);
    v0385 = ((intptr_t)(v0385) < 0 ? lisp_true : nil);
    if (!(v0385 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0311 = stack[-3];
    v0387 = v0139;
    v0386 = stack[-3];
    v0385 = v0139;
    v0386 = *(LispObject *)((char *)v0386 + (CELL-TAG_VECTOR) + ((int32_t)v0385/(16/CELL)));
    v0385 = v0140;
    v0385 = Lmodular_times(nil, v0386, v0385);
    env = stack[-4];
    *(LispObject *)((char *)v0311 + (CELL-TAG_VECTOR) + ((int32_t)v0387/(16/CELL))) = v0385;
    v0385 = v0139;
    v0385 = (LispObject)((int32_t)(v0385) + 0x10);
    v0139 = v0385;
    goto v0390;

v0389:
    v0387 = stack[-3];
    v0386 = (LispObject)1; // 0
    v0385 = (LispObject)17; // 1
    *(LispObject *)((char *)v0387 + (CELL-TAG_VECTOR) + ((int32_t)v0386/(16/CELL))) = v0385;
    v0385 = (LispObject)1; // 0
    { popv(5); return onevalue(v0385); }

v0030:
    v0386 = stack[-1];
    v0385 = stack[0];
    v0385 = *(LispObject *)((char *)v0386 + (CELL-TAG_VECTOR) + ((int32_t)v0385/(16/CELL)));
    v0385 = Lmodular_reciprocal(nil, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0140 = v0385;
    v0385 = (LispObject)1; // 0
    v0139 = v0385;
    goto v0102;

v0102:
    v0386 = stack[0];
    v0385 = v0139;
    v0385 = (LispObject)(int32_t)((int32_t)v0386 - (int32_t)v0385 + TAG_FIXNUM);
    v0385 = ((intptr_t)(v0385) < 0 ? lisp_true : nil);
    if (!(v0385 == nil)) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0311 = stack[-3];
    v0387 = v0139;
    v0386 = stack[-1];
    v0385 = v0139;
    v0386 = *(LispObject *)((char *)v0386 + (CELL-TAG_VECTOR) + ((int32_t)v0385/(16/CELL)));
    v0385 = v0140;
    v0385 = Lmodular_times(nil, v0386, v0385);
    env = stack[-4];
    *(LispObject *)((char *)v0311 + (CELL-TAG_VECTOR) + ((int32_t)v0387/(16/CELL))) = v0385;
    v0385 = v0139;
    v0385 = (LispObject)((int32_t)(v0385) + 0x10);
    v0139 = v0385;
    goto v0102;

v0065:
    v0387 = stack[-3];
    v0386 = (LispObject)1; // 0
    v0385 = (LispObject)17; // 1
    *(LispObject *)((char *)v0387 + (CELL-TAG_VECTOR) + ((int32_t)v0386/(16/CELL))) = v0385;
    v0385 = (LispObject)1; // 0
    { popv(5); return onevalue(v0385); }

v0033:
    v0385 = qvalue(elt(env, 1)); // t
    goto v0032;
// error exit handlers
v0388:
    popv(5);
    return nil;
}



// Code for isimp2

static LispObject CC_isimp2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0320, v0397, v0224, v0398, v0399;
    LispObject fn;
    LispObject v0019, v0045, v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "isimp2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    v0019 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isimp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0019,v0045,v0036,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0037,v0036,v0045,v0019);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[0] = v0019;
    stack[-1] = v0045;
    stack[-2] = v0036;
    stack[-3] = v0037;
    stack[-4] = v0000;
// end of prologue
    v0320 = stack[-4];
    v0320 = qcar(v0320);
    v0320 = qcar(v0320);
    stack[-5] = v0320;
    if (!consp(v0320)) goto v0002;
    v0320 = stack[-5];
    v0397 = qcar(v0320);
    v0320 = elt(env, 1); // cons
    if (v0397 == v0320) goto v0199;
    v0320 = qvalue(elt(env, 2)); // nil
    goto v0022;

v0022:
    if (v0320 == nil) goto v0006;
    v0399 = stack[-4];
    v0398 = stack[-3];
    v0224 = stack[-2];
    v0397 = stack[-1];
    v0320 = stack[0];
    {
        popv(7);
        fn = elt(env, 5); // dotsum
        return (*qfnn(fn))(qenv(fn), 5, v0399, v0398, v0224, v0397, v0320);
    }

v0006:
    v0320 = stack[-5];
    v0397 = qcar(v0320);
    v0320 = elt(env, 3); // g
    if (v0397 == v0320) goto v0400;
    v0320 = stack[-5];
    v0397 = qcar(v0320);
    v0320 = elt(env, 4); // eps
    if (!(v0397 == v0320)) goto v0002;
    v0399 = stack[-4];
    v0398 = stack[-3];
    v0224 = stack[-2];
    v0397 = stack[-1];
    v0320 = stack[0];
    {
        popv(7);
        fn = elt(env, 6); // esum
        return (*qfnn(fn))(qenv(fn), 5, v0399, v0398, v0224, v0397, v0320);
    }

v0002:
    v0320 = stack[-4];
    v0397 = qcar(v0320);
    v0320 = (LispObject)17; // 1
    v0320 = cons(v0397, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    stack[-5] = ncons(v0320);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    v0320 = stack[-4];
    v0399 = qcdr(v0320);
    v0398 = stack[-3];
    v0224 = stack[-2];
    v0397 = stack[-1];
    v0320 = stack[0];
    fn = elt(env, 7); // isimp1
    v0320 = (*qfnn(fn))(qenv(fn), 5, v0399, v0398, v0224, v0397, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    {
        LispObject v0186 = stack[-5];
        popv(7);
        fn = elt(env, 8); // multf
        return (*qfn2(fn))(qenv(fn), v0186, v0320);
    }

v0400:
    v0320 = stack[-5];
    v0320 = qcdr(v0320);
    v0397 = qcdr(v0320);
    v0320 = stack[-4];
    v0320 = qcar(v0320);
    v0320 = qcdr(v0320);
    fn = elt(env, 9); // appn
    v0224 = (*qfn2(fn))(qenv(fn), v0397, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    v0397 = stack[0];
    v0320 = stack[-5];
    v0320 = qcdr(v0320);
    v0320 = qcar(v0320);
    fn = elt(env, 10); // gadd
    v0320 = (*qfnn(fn))(qenv(fn), 3, v0224, v0397, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    stack[-5] = v0320;
    v0320 = stack[-5];
    v0320 = qcar(v0320);
    fn = elt(env, 11); // nb
    v0397 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    v0320 = stack[-4];
    v0320 = qcdr(v0320);
    fn = elt(env, 12); // multd!*
    v0399 = (*qfn2(fn))(qenv(fn), v0397, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    v0398 = stack[-3];
    v0224 = stack[-2];
    v0397 = stack[-1];
    v0320 = stack[-5];
    v0320 = qcdr(v0320);
    {
        popv(7);
        fn = elt(env, 7); // isimp1
        return (*qfnn(fn))(qenv(fn), 5, v0399, v0398, v0224, v0397, v0320);
    }

v0199:
    v0320 = stack[-5];
    v0397 = qcdr(v0320);
    v0320 = stack[-3];
    fn = elt(env, 13); // xnp
    v0320 = (*qfn2(fn))(qenv(fn), v0397, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    goto v0022;
// error exit handlers
v0141:
    popv(7);
    return nil;
}



// Code for get!*nr!*real!*irred!*reps

static LispObject CC_getHnrHrealHirredHreps(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0103, v0202;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get*nr*real*irred*reps");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0103 = v0000;
// end of prologue
    v0202 = elt(env, 1); // realrepnumber
    return get(v0103, v0202);
}



// Code for qqe_length!-graph!-neighbors

static LispObject CC_qqe_lengthKgraphKneighbors(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbors");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0021 = v0000;
// end of prologue
    v0020 = elt(env, 1); // neighbors
    return get(v0021, v0020);
}



// Code for delqip

static LispObject CC_delqip(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0078, v0199, v0054;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delqip");
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
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0037;
    v0054 = v0000;
// end of prologue
    v0078 = stack[0];
    if (!consp(v0078)) { LispObject res = stack[0]; popv(1); return onevalue(res); }
    v0199 = v0054;
    v0078 = stack[0];
    v0078 = qcar(v0078);
    if (v0199 == v0078) goto v0015;
    v0199 = v0054;
    v0078 = stack[0];
    fn = elt(env, 1); // delqip1
    v0078 = (*qfn2(fn))(qenv(fn), v0199, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }

v0015:
    v0078 = stack[0];
    v0078 = qcdr(v0078);
    { popv(1); return onevalue(v0078); }
// error exit handlers
v0200:
    popv(1);
    return nil;
}



// Code for acfsf_0mk2

static LispObject CC_acfsf_0mk2(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0032, v0033, v0034;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for acfsf_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0032 = v0037;
    v0033 = v0000;
// end of prologue
    v0034 = qvalue(elt(env, 1)); // nil
    return list3(v0033, v0032, v0034);
}



// Code for prload

static LispObject CC_prload(LispObject env, int nargs, ...)
{
    LispObject v0036;
    argcheck(nargs, 0, "prload");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prload");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// end of prologue
    v0036 = qvalue(elt(env, 1)); // nil
    return onevalue(v0036);
}



// Code for qsimpcomb_standard_integer_part_sf

static LispObject CC_qsimpcomb_standard_integer_part_sf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0178, v0067, v0326;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qsimpcomb_standard_integer_part_sf");
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
    v0178 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0178;
    goto v0021;

v0021:
    v0178 = stack[-2];
    v0178 = Lconsp(nil, v0178);
    env = stack[-4];
    if (v0178 == nil) goto v0015;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0178 = CC_qsimpcomb_standard_integer_part_sf(env, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-4];
    stack[-1] = v0178;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0067 = qcar(v0178);
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0178 = cons(v0067, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-4];
    stack[0] = v0178;
    goto v0069;

v0069:
    v0067 = stack[0];
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0326 = cons(v0067, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-4];
    v0067 = qvalue(elt(env, 1)); // nil
    v0178 = stack[-3];
    v0178 = acons(v0326, v0067, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-4];
    stack[-3] = v0178;
    v0178 = stack[-1];
    v0178 = qcdr(v0178);
    stack[-1] = v0178;
    v0178 = stack[-1];
    if (!(v0178 == nil)) goto v0069;
    v0178 = stack[-2];
    v0178 = qcdr(v0178);
    stack[-2] = v0178;
    goto v0021;

v0015:
    v0178 = stack[-2];
    if (v0178 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0067 = stack[-2];
    v0178 = stack[-3];
    v0178 = cons(v0067, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    stack[-3] = v0178;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }
// error exit handlers
v0210:
    popv(5);
    return nil;
}



// Code for groebreduceonestepint

static LispObject CC_groebreduceonestepint(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0228, v0391, v0159;
    LispObject fn;
    LispObject v0019, v0045, v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "groebreduceonestepint");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    v0019 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebreduceonestepint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0019,v0045,v0036,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0037,v0036,v0045,v0019);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0019;
    stack[-4] = v0045;
    stack[-3] = v0036;
    stack[-6] = v0037;
    stack[-2] = v0000;
// end of prologue
    v0228 = stack[-1];
    fn = elt(env, 8); // vdpred
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    stack[0] = v0228;
    v0391 = v0228;
    v0228 = v0391;
    if (v0228 == nil) goto v0095;
    v0228 = v0391;
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    v0228 = (v0228 == nil ? lisp_true : nil);
    goto v0053;

v0053:
    if (v0228 == nil) goto v0051;
    v0228 = stack[-2];
    fn = elt(env, 8); // vdpred
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    stack[-2] = v0228;
    v0228 = stack[-6];
    qvalue(elt(env, 2)) = v0228; // secondvalue!*
    { LispObject res = stack[-2]; popv(9); return onevalue(res); }

v0051:
    v0391 = stack[-4];
    v0228 = stack[-1];
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    fn = elt(env, 9); // vevdif
    v0228 = (*qfn2(fn))(qenv(fn), v0391, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    stack[-7] = v0228;
    v0228 = stack[-1];
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    stack[-5] = v0228;
    v0228 = qvalue(elt(env, 3)); // !*groebdivide
    if (v0228 == nil) goto v0047;
    v0391 = stack[-3];
    v0228 = stack[-5];
    fn = elt(env, 10); // vbcgcd
    v0228 = (*qfn2(fn))(qenv(fn), v0391, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    goto v0049;

v0049:
    stack[-4] = v0228;
    v0391 = stack[-5];
    v0228 = stack[-4];
    fn = elt(env, 11); // vbcquot
    v0228 = (*qfn2(fn))(qenv(fn), v0391, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    stack[-5] = v0228;
    v0391 = stack[-3];
    v0228 = stack[-4];
    fn = elt(env, 11); // vbcquot
    v0228 = (*qfn2(fn))(qenv(fn), v0391, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    stack[-4] = v0228;
    v0228 = stack[-6];
    if (v0228 == nil) goto v0057;
    v0228 = stack[-6];
    if (v0228 == nil) goto v0092;
    v0228 = stack[-6];
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    v0228 = (v0228 == nil ? lisp_true : nil);
    goto v0004;

v0004:
    if (!(v0228 == nil)) goto v0057;
    v0391 = stack[-6];
    v0228 = stack[-5];
    fn = elt(env, 12); // vdpvbcprod
    v0228 = (*qfn2(fn))(qenv(fn), v0391, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    stack[-6] = v0228;
    goto v0057;

v0057:
    v0228 = qvalue(elt(env, 4)); // !*groebprot
    if (v0228 == nil) goto v0089;
    stack[-3] = stack[-5];
    v0228 = stack[-4];
    fn = elt(env, 13); // vbcneg
    v0159 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    v0391 = stack[-7];
    v0228 = stack[-1];
    fn = elt(env, 14); // groebreductionprotocol
    v0228 = (*qfnn(fn))(qenv(fn), 4, stack[-3], v0159, v0391, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    goto v0089;

v0089:
    v0228 = stack[-2];
    fn = elt(env, 8); // vdpred
    stack[-3] = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    stack[-2] = stack[-5];
    v0391 = qvalue(elt(env, 5)); // vdpvars!*
    v0228 = qvalue(elt(env, 6)); // nil
    fn = elt(env, 15); // vevmaptozero1
    stack[-1] = (*qfn2(fn))(qenv(fn), v0391, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    v0228 = stack[-4];
    fn = elt(env, 13); // vbcneg
    v0391 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    v0228 = stack[-7];
    fn = elt(env, 16); // vdpilcomb1
    v0228 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], v0391, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    stack[-2] = v0228;
    v0228 = stack[-6];
    qvalue(elt(env, 2)) = v0228; // secondvalue!*
    v0228 = stack[-5];
    qvalue(elt(env, 7)) = v0228; // thirdvalue!*
    { LispObject res = stack[-2]; popv(9); return onevalue(res); }

v0092:
    v0228 = qvalue(elt(env, 1)); // t
    goto v0004;

v0047:
    v0228 = (LispObject)17; // 1
    fn = elt(env, 17); // vbcfi
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0380;
    env = stack[-8];
    goto v0049;

v0095:
    v0228 = qvalue(elt(env, 1)); // t
    goto v0053;
// error exit handlers
v0380:
    popv(9);
    return nil;
}



// Code for groebmakepair

static LispObject CC_groebmakepair(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0042, v0043, v0325;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebmakepair");
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
// copy arguments values to proper place
    stack[-2] = v0037;
    stack[-3] = v0000;
// end of prologue
    v0042 = stack[-3];
    v0042 = qcdr(v0042);
    v0043 = qcar(v0042);
    v0042 = stack[-2];
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    fn = elt(env, 2); // vevlcm
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    stack[-4] = v0042;
    v0042 = qvalue(elt(env, 1)); // !*gsugar
    if (v0042 == nil) goto v0057;
    v0042 = stack[-3];
    fn = elt(env, 3); // gsugar
    stack[0] = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    v0043 = stack[-4];
    v0042 = stack[-3];
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    fn = elt(env, 4); // vevdif
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    fn = elt(env, 5); // vevtdeg
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    v0042 = (LispObject)(int32_t)((int32_t)stack[0] + (int32_t)v0042 - TAG_FIXNUM);
    stack[-1] = v0042;
    v0042 = stack[-2];
    fn = elt(env, 3); // gsugar
    stack[0] = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    v0043 = stack[-4];
    v0042 = stack[-2];
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    fn = elt(env, 4); // vevdif
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    fn = elt(env, 5); // vevtdeg
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-5];
    v0042 = (LispObject)(int32_t)((int32_t)stack[0] + (int32_t)v0042 - TAG_FIXNUM);
    stack[0] = stack[-4];
    v0043 = stack[-1];
    fn = elt(env, 6); // max
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    {
        LispObject v0002 = stack[0];
        LispObject v0016 = stack[-3];
        LispObject v0017 = stack[-2];
        popv(6);
        return list4(v0002, v0016, v0017, v0042);
    }

v0057:
    v0325 = stack[-4];
    v0043 = stack[-3];
    v0042 = stack[-2];
    popv(6);
    return list3(v0325, v0043, v0042);
// error exit handlers
v0001:
    popv(6);
    return nil;
}



// Code for make_wedge_pair

static LispObject CC_make_wedge_pair(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0066, v0003, v0004;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make_wedge_pair");
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
    v0003 = stack[-2];
    v0066 = stack[-2];
    stack[0] = list2(v0003, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-4];
    v0066 = stack[-1];
    fn = elt(env, 5); // xval
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-4];
    fn = elt(env, 6); // xlcm
    v0066 = (*qfn2(fn))(qenv(fn), stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-4];
    stack[-3] = v0066;
    v0066 = qvalue(elt(env, 1)); // !*twosided
    if (v0066 == nil) goto v0203;
    v0066 = qvalue(elt(env, 2)); // xtruncate!*
    if (!(v0066 == nil)) goto v0203;

v0046:
    v0003 = stack[-2];
    v0066 = stack[-1];
    fn = elt(env, 7); // overall_factor
    v0066 = (*qfn2(fn))(qenv(fn), v0003, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-4];
    if (v0066 == nil) goto v0012;
    v0066 = qvalue(elt(env, 3)); // nil
    { popv(5); return onevalue(v0066); }

v0012:
    v0066 = stack[-3];
    fn = elt(env, 8); // mknwedge
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-4];
    fn = elt(env, 9); // xdegreecheck
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-4];
    if (v0066 == nil) goto v0027;
    v0066 = qvalue(elt(env, 3)); // nil
    { popv(5); return onevalue(v0066); }

v0027:
    stack[0] = elt(env, 4); // wedge_pair
    v0004 = stack[-2];
    v0003 = (LispObject)17; // 1
    v0066 = (LispObject)17; // 1
    v0066 = list2star(v0004, v0003, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-4];
    v0003 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    v0066 = stack[-1];
    {
        LispObject v0028 = stack[-3];
        LispObject v0093 = stack[0];
        popv(5);
        return list4(v0028, v0093, v0003, v0066);
    }

v0203:
    stack[0] = stack[-2];
    v0066 = stack[-1];
    fn = elt(env, 5); // xval
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0325;
    env = stack[-4];
    v0066 = Lmemq(nil, stack[0], v0066);
    if (!(v0066 == nil)) goto v0046;
    v0066 = qvalue(elt(env, 3)); // nil
    { popv(5); return onevalue(v0066); }
// error exit handlers
v0325:
    popv(5);
    return nil;
}



// Code for mk_world1

static LispObject CC_mk_world1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0034, v0035, v0038;
    LispObject fn;
    LispObject v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk_world1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_world1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0036,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0036;
    stack[-1] = v0037;
    v0034 = v0000;
// end of prologue
    fn = elt(env, 1); // map_2_from_map_1
    v0038 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0035 = stack[-1];
    v0034 = stack[0];
    popv(2);
    return list3(v0038, v0035, v0034);
// error exit handlers
v0022:
    popv(2);
    return nil;
}



// Code for delasc

static LispObject CC_delasc(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0082, v0211;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delasc");
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
    goto v0085;

v0085:
    v0082 = stack[0];
    if (v0082 == nil) goto v0087;
    v0082 = stack[0];
    v0082 = qcar(v0082);
    if (!consp(v0082)) goto v0022;
    v0211 = stack[-1];
    v0082 = stack[0];
    v0082 = qcar(v0082);
    v0082 = qcar(v0082);
    v0082 = Lneq(nil, v0211, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    goto v0040;

v0040:
    if (v0082 == nil) goto v0034;
    v0082 = stack[0];
    v0211 = qcar(v0082);
    v0082 = stack[-2];
    v0082 = cons(v0211, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-3];
    stack[-2] = v0082;
    goto v0034;

v0034:
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    stack[0] = v0082;
    goto v0085;

v0022:
    v0082 = qvalue(elt(env, 2)); // t
    goto v0040;

v0087:
    v0082 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0082);
// error exit handlers
v0368:
    popv(4);
    return nil;
}



// Code for df!-chain!-rule

static LispObject CC_dfKchainKrule(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0056, v0206, v0086;
    LispObject fn;
    LispObject v0036, v0037, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "df-chain-rule");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for df-chain-rule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0036,v0037,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0037,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[0] = v0036;
    stack[-3] = v0037;
    stack[-4] = v0000;
// end of prologue
    v0206 = qvalue(elt(env, 1)); // nil
    v0056 = (LispObject)17; // 1
    v0056 = cons(v0206, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0206 = v0056;
    v0056 = stack[0];
    stack[-5] = v0056;
    goto v0038;

v0038:
    v0056 = stack[-5];
    if (v0056 == nil) { popv(7); return onevalue(v0206); }
    v0056 = stack[-5];
    v0056 = qcar(v0056);
    stack[-2] = v0056;
    stack[-1] = v0206;
    v0086 = elt(env, 2); // df
    v0206 = stack[-4];
    v0056 = stack[-2];
    v0056 = list3(v0086, v0206, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    fn = elt(env, 3); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0086 = elt(env, 2); // df
    v0206 = stack[-2];
    v0056 = stack[-3];
    v0056 = list3(v0086, v0206, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    fn = elt(env, 3); // simp
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    fn = elt(env, 4); // multsq
    v0056 = (*qfn2(fn))(qenv(fn), stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    fn = elt(env, 5); // addsq
    v0056 = (*qfn2(fn))(qenv(fn), stack[-1], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-6];
    v0206 = v0056;
    v0056 = stack[-5];
    v0056 = qcdr(v0056);
    stack[-5] = v0056;
    goto v0038;
// error exit handlers
v0076:
    popv(7);
    return nil;
}



// Code for dp!=retimes

static LispObject CC_dpMretimes(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0012, v0068, v0070;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=retimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0068 = v0000;
// end of prologue

v0015:
    v0012 = v0068;
    v0070 = qcar(v0012);
    v0012 = (LispObject)17; // 1
    if (v0070 == v0012) goto v0087;
    v0012 = v0068;
    v0012 = qcdr(v0012);
    if (v0012 == nil) goto v0014;
    v0012 = elt(env, 1); // times
    return cons(v0012, v0068);

v0014:
    v0012 = v0068;
    v0012 = qcar(v0012);
    return onevalue(v0012);

v0087:
    v0012 = v0068;
    v0012 = qcdr(v0012);
    if (v0012 == nil) goto v0084;
    v0012 = v0068;
    v0012 = qcdr(v0012);
    v0068 = v0012;
    goto v0015;

v0084:
    v0012 = (LispObject)17; // 1
    return onevalue(v0012);
}



// Code for general!-difference!-mod!-p

static LispObject CC_generalKdifferenceKmodKp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0103, v0202;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-difference-mod-p");
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
    v0103 = v0037;
    v0202 = v0000;
// end of prologue
    stack[0] = v0202;
    fn = elt(env, 1); // general!-minus!-mod!-p
    v0103 = (*qfn1(fn))(qenv(fn), v0103);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-1];
    {
        LispObject v0034 = stack[0];
        popv(2);
        fn = elt(env, 2); // general!-plus!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0034, v0103);
    }
// error exit handlers
v0033:
    popv(2);
    return nil;
}



// Code for null!+vec!+p

static LispObject CC_nullLvecLp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0103;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for null+vec+p");
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
    v0103 = v0000;
// end of prologue
    fn = elt(env, 2); // mk!+squared!+norm
    v0103 = (*qfn1(fn))(qenv(fn), v0103);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[0];
    fn = elt(env, 3); // my!+nullsq!+p
    v0103 = (*qfn1(fn))(qenv(fn), v0103);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[0];
    if (v0103 == nil) goto v0115;
    v0103 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0103); }

v0115:
    v0103 = nil;
    { popv(1); return onevalue(v0103); }
// error exit handlers
v0202:
    popv(1);
    return nil;
}



// Code for qqe_length!-graph!-marked

static LispObject CC_qqe_lengthKgraphKmarked(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-marked");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0021 = v0000;
// end of prologue
    v0020 = elt(env, 1); // blockmark
    return get(v0021, v0020);
}



// Code for pasf_negateat

static LispObject CC_pasf_negateat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0316, v0335, v0334;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_negateat");
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
    v0335 = stack[0];
    v0316 = elt(env, 1); // true
    if (v0335 == v0316) goto v0085;
    v0335 = stack[0];
    v0316 = elt(env, 3); // false
    v0316 = (v0335 == v0316 ? lisp_true : nil);
    goto v0087;

v0087:
    if (v0316 == nil) goto v0010;
    v0335 = stack[0];
    v0316 = elt(env, 3); // false
    if (v0335 == v0316) goto v0203;
    v0316 = elt(env, 3); // false
    { popv(2); return onevalue(v0316); }

v0203:
    v0316 = elt(env, 1); // true
    { popv(2); return onevalue(v0316); }

v0010:
    v0335 = stack[0];
    v0316 = elt(env, 1); // true
    if (v0335 == v0316) goto v0368;
    v0335 = stack[0];
    v0316 = elt(env, 3); // false
    v0316 = (v0335 == v0316 ? lisp_true : nil);
    goto v0047;

v0047:
    if (v0316 == nil) goto v0048;
    v0316 = stack[0];
    v0335 = v0316;
    goto v0046;

v0046:
    v0316 = elt(env, 4); // (cong ncong)
    v0316 = Lmemq(nil, v0335, v0316);
    if (v0316 == nil) goto v0319;
    v0335 = stack[0];
    v0316 = elt(env, 1); // true
    if (v0335 == v0316) goto v0030;
    v0335 = stack[0];
    v0316 = elt(env, 3); // false
    v0316 = (v0335 == v0316 ? lisp_true : nil);
    goto v0029;

v0029:
    if (v0316 == nil) goto v0018;
    v0316 = stack[0];
    goto v0016;

v0016:
    fn = elt(env, 5); // pasf_lnegrel
    v0335 = (*qfn1(fn))(qenv(fn), v0316);
    nil = C_nil;
    if (exception_pending()) goto v0404;
    env = stack[-1];
    v0316 = stack[0];
    v0316 = qcar(v0316);
    v0316 = qcdr(v0316);
    fn = elt(env, 6); // pasf_mkop
    v0334 = (*qfn2(fn))(qenv(fn), v0335, v0316);
    nil = C_nil;
    if (exception_pending()) goto v0404;
    v0316 = stack[0];
    v0316 = qcdr(v0316);
    v0335 = qcar(v0316);
    v0316 = stack[0];
    v0316 = qcdr(v0316);
    v0316 = qcdr(v0316);
    v0316 = qcar(v0316);
    popv(2);
    return list3(v0334, v0335, v0316);

v0018:
    v0316 = stack[0];
    v0316 = qcar(v0316);
    v0316 = Lconsp(nil, v0316);
    env = stack[-1];
    if (v0316 == nil) goto v0400;
    v0316 = stack[0];
    v0316 = qcar(v0316);
    v0316 = qcar(v0316);
    goto v0016;

v0400:
    v0316 = stack[0];
    v0316 = qcar(v0316);
    goto v0016;

v0030:
    v0316 = qvalue(elt(env, 2)); // t
    goto v0029;

v0319:
    v0335 = stack[0];
    v0316 = elt(env, 1); // true
    if (v0335 == v0316) goto v0237;
    v0335 = stack[0];
    v0316 = elt(env, 3); // false
    v0316 = (v0335 == v0316 ? lisp_true : nil);
    goto v0363;

v0363:
    if (v0316 == nil) goto v0159;
    v0316 = stack[0];
    goto v0228;

v0228:
    fn = elt(env, 5); // pasf_lnegrel
    v0334 = (*qfn1(fn))(qenv(fn), v0316);
    nil = C_nil;
    if (exception_pending()) goto v0404;
    v0316 = stack[0];
    v0316 = qcdr(v0316);
    v0335 = qcar(v0316);
    v0316 = stack[0];
    v0316 = qcdr(v0316);
    v0316 = qcdr(v0316);
    v0316 = qcar(v0316);
    popv(2);
    return list3(v0334, v0335, v0316);

v0159:
    v0316 = stack[0];
    v0316 = qcar(v0316);
    v0316 = Lconsp(nil, v0316);
    env = stack[-1];
    if (v0316 == nil) goto v0183;
    v0316 = stack[0];
    v0316 = qcar(v0316);
    v0316 = qcar(v0316);
    goto v0228;

v0183:
    v0316 = stack[0];
    v0316 = qcar(v0316);
    goto v0228;

v0237:
    v0316 = qvalue(elt(env, 2)); // t
    goto v0363;

v0048:
    v0316 = stack[0];
    v0316 = qcar(v0316);
    v0316 = Lconsp(nil, v0316);
    env = stack[-1];
    if (v0316 == nil) goto v0326;
    v0316 = stack[0];
    v0316 = qcar(v0316);
    v0316 = qcar(v0316);
    v0335 = v0316;
    goto v0046;

v0326:
    v0316 = stack[0];
    v0316 = qcar(v0316);
    v0335 = v0316;
    goto v0046;

v0368:
    v0316 = qvalue(elt(env, 2)); // t
    goto v0047;

v0085:
    v0316 = qvalue(elt(env, 2)); // t
    goto v0087;
// error exit handlers
v0404:
    popv(2);
    return nil;
}



// Code for sfto_kexp

static LispObject CC_sfto_kexp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_kexp");
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
    v0051 = stack[0];
    v0050 = (LispObject)1; // 0
    v0050 = Leqn(nil, v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-2];
    if (v0050 == nil) goto v0058;
    v0050 = (LispObject)17; // 1
    { popv(3); return onevalue(v0050); }

v0058:
    v0051 = stack[-1];
    v0050 = stack[0];
    fn = elt(env, 2); // to
    v0051 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-2];
    v0050 = (LispObject)17; // 1
    v0050 = cons(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    popv(3);
    return ncons(v0050);
// error exit handlers
v0080:
    popv(3);
    return nil;
}



// Code for make!-image!-mod!-p

static LispObject CC_makeKimageKmodKp(LispObject env,
                         LispObject v0000, LispObject v0037)
{
    LispObject nil = C_nil;
    LispObject v0011, v0080;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-image-mod-p");
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
    v0080 = stack[-1];
    v0011 = stack[0];
    fn = elt(env, 3); // degree!-in!-variable
    v0011 = (*qfn2(fn))(qenv(fn), v0080, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    stack[-2] = v0011;
    v0080 = stack[-1];
    v0011 = stack[0];
    fn = elt(env, 4); // make!-univariate!-image!-mod!-p
    v0011 = (*qfn2(fn))(qenv(fn), v0080, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    stack[-1] = v0011;
    v0080 = stack[-1];
    v0011 = stack[0];
    fn = elt(env, 3); // degree!-in!-variable
    v0080 = (*qfn2(fn))(qenv(fn), v0080, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    v0011 = stack[-2];
    if (equal(v0080, v0011)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0011 = qvalue(elt(env, 1)); // t
    qvalue(elt(env, 2)) = v0011; // unlucky!-case
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }
// error exit handlers
v0046:
    popv(4);
    return nil;
}



setup_type const u40_setup[] =
{
    {"force-to-dm",             CC_forceKtoKdm, too_many_1,    wrong_no_1},
    {"find_triangl_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_triangl_coeff},
    {"monic",                   too_few_2,      CC_monic,      wrong_no_2},
    {"pa_part2list",            CC_pa_part2list,too_many_1,    wrong_no_1},
    {"random-teeny-prime",      CC_randomKteenyKprime,too_many_1,wrong_no_1},
    {"equal+matrices+p",        too_few_2,      CC_equalLmatricesLp,wrong_no_2},
    {"qqe_length-graph-neighbor-edge",CC_qqe_lengthKgraphKneighborKedge,too_many_1,wrong_no_1},
    {"sqfrf",                   CC_sqfrf,       too_many_1,    wrong_no_1},
    {"*invsq",                  CC_Hinvsq,      too_many_1,    wrong_no_1},
    {"parfool",                 CC_parfool,     too_many_1,    wrong_no_1},
    {"dim<=deg",                CC_dimRMdeg,    too_many_1,    wrong_no_1},
    {"ratmean",                 too_few_2,      CC_ratmean,    wrong_no_2},
    {"endofstmtp",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_endofstmtp},
    {"reddom_zeros",            CC_reddom_zeros,too_many_1,    wrong_no_1},
    {"fs:zerop:",               CC_fsTzeropT,   too_many_1,    wrong_no_1},
    {"red_prepare",             CC_red_prepare, too_many_1,    wrong_no_1},
    {"cl_atml1",                CC_cl_atml1,    too_many_1,    wrong_no_1},
    {"pasf_leqp",               too_few_2,      CC_pasf_leqp,  wrong_no_2},
    {"vsl_boundtype1",          too_few_2,      CC_vsl_boundtype1,wrong_no_2},
    {"intconv",                 CC_intconv,     too_many_1,    wrong_no_1},
    {"sprow_dim",               CC_sprow_dim,   too_many_1,    wrong_no_1},
    {"vdpsimpcont",             CC_vdpsimpcont, too_many_1,    wrong_no_1},
    {"mk_parents_prim",         CC_mk_parents_prim,too_many_1, wrong_no_1},
    {"get-all-kernels",         CC_getKallKkernels,too_many_1, wrong_no_1},
    {"test-bool",               CC_testKbool,   too_many_1,    wrong_no_1},
    {"bagp",                    CC_bagp,        too_many_1,    wrong_no_1},
    {"sq_member",               too_few_2,      CC_sq_member,  wrong_no_2},
    {"xadd*",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xaddH},
    {"cl_simpl1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_simpl1},
    {"pasf_subfof",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof},
    {"ofsf_boundchk",           too_few_2,      CC_ofsf_boundchk,wrong_no_2},
    {"mkunarywedge",            CC_mkunarywedge,too_many_1,    wrong_no_1},
    {"mo=expvec2a1",            too_few_2,      CC_moMexpvec2a1,wrong_no_2},
    {"gcd-in-vector",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcdKinKvector},
    {"isimp2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_isimp2},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,too_many_1,wrong_no_1},
    {"qqe_length-graph-neighbors",CC_qqe_lengthKgraphKneighbors,too_many_1,wrong_no_1},
    {"delqip",                  too_few_2,      CC_delqip,     wrong_no_2},
    {"acfsf_0mk2",              too_few_2,      CC_acfsf_0mk2, wrong_no_2},
    {"prload",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_prload},
    {"qsimpcomb_standard_integer_part_sf",CC_qsimpcomb_standard_integer_part_sf,too_many_1,wrong_no_1},
    {"groebreduceonestepint",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebreduceonestepint},
    {"groebmakepair",           too_few_2,      CC_groebmakepair,wrong_no_2},
    {"make_wedge_pair",         too_few_2,      CC_make_wedge_pair,wrong_no_2},
    {"mk_world1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mk_world1},
    {"delasc",                  too_few_2,      CC_delasc,     wrong_no_2},
    {"df-chain-rule",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dfKchainKrule},
    {"dp=retimes",              CC_dpMretimes,  too_many_1,    wrong_no_1},
    {"general-difference-mod-p",too_few_2,      CC_generalKdifferenceKmodKp,wrong_no_2},
    {"null+vec+p",              CC_nullLvecLp,  too_many_1,    wrong_no_1},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,too_many_1,wrong_no_1},
    {"pasf_negateat",           CC_pasf_negateat,too_many_1,   wrong_no_1},
    {"sfto_kexp",               too_few_2,      CC_sfto_kexp,  wrong_no_2},
    {"make-image-mod-p",        too_few_2,      CC_makeKimageKmodKp,wrong_no_2},
    {NULL, (one_args *)"u40", (two_args *)"18142 4147086 4949371", 0}
};

// end of generated code
