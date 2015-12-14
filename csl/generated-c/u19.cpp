
// $destdir\u19.c        Machine generated C code

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



// Code for cl_susiupdknowl1

static LispObject CC_cl_susiupdknowl1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0016, v0017, v0018;
    LispObject fn;
    LispObject v0003, v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl1");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiupdknowl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0004,v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0015,v0007,v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
    stack[-1] = v0004;
    v0018 = v0007;
    v0016 = v0015;
// end of prologue
    v0017 = v0016;
    v0016 = elt(env, 1); // and
    if (v0017 == v0016) goto v0019;
    v0016 = v0018;
    fn = elt(env, 2); // rl_negateat
    v0017 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0016 = stack[0];
    v0018 = cons(v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0017 = stack[-1];
    v0016 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // cl_susiupdknowl2
        return (*qfnn(fn))(qenv(fn), 3, v0018, v0017, v0016);
    }

v0019:
    v0017 = v0018;
    v0016 = stack[0];
    v0018 = cons(v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0017 = stack[-1];
    v0016 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // cl_susiupdknowl2
        return (*qfnn(fn))(qenv(fn), 3, v0018, v0017, v0016);
    }
// error exit handlers
v0020:
    popv(3);
    return nil;
}



// Code for ibalp_var!-unset

static LispObject CC_ibalp_varKunset(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0044, v0045;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-unset");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0007;
    stack[-4] = v0015;
// end of prologue
    v0044 = stack[-4];
    v0045 = qcdr(v0044);
    v0044 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // setcar
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0044 = stack[-4];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0045 = qcdr(v0044);
    v0044 = (LispObject)-15; // -1
    fn = elt(env, 2); // setcar
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0044 = stack[-4];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0045 = qcdr(v0044);
    v0044 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // setcar
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0044 = stack[-4];
    v0044 = qcar(v0044);
    stack[-5] = v0044;
    v0045 = stack[-3];
    v0044 = (LispObject)17; // 1
    v0044 = Leqn(nil, v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    if (v0044 == nil) goto v0047;
    v0044 = stack[-4];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcar(v0044);
    goto v0048;

v0048:
    stack[-2] = v0044;
    goto v0049;

v0049:
    v0044 = stack[-2];
    if (v0044 == nil) goto v0050;
    v0044 = stack[-2];
    v0044 = qcar(v0044);
    stack[-1] = v0044;
    v0045 = stack[-3];
    v0044 = (LispObject)17; // 1
    v0044 = Leqn(nil, v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    if (v0044 == nil) goto v0051;
    v0044 = stack[-1];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    stack[0] = qcdr(v0044);
    v0044 = stack[-1];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcar(v0044);
    v0044 = add1(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0044 = (*qfn2(fn))(qenv(fn), stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    goto v0052;

v0052:
    v0044 = stack[-2];
    v0044 = qcdr(v0044);
    stack[-2] = v0044;
    goto v0049;

v0051:
    v0044 = stack[-1];
    v0044 = qcdr(v0044);
    stack[0] = qcdr(v0044);
    v0044 = stack[-1];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcar(v0044);
    v0044 = add1(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0044 = (*qfn2(fn))(qenv(fn), stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    goto v0052;

v0050:
    v0045 = stack[-3];
    v0044 = (LispObject)1; // 0
    v0044 = Leqn(nil, v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    if (v0044 == nil) goto v0053;
    v0044 = stack[-4];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcar(v0044);
    goto v0054;

v0054:
    v0045 = v0044;
    v0044 = stack[-5];
    fn = elt(env, 3); // ibalp_unvar!-unsatlist
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    v0044 = stack[-4];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    stack[0] = qcdr(v0044);
    v0044 = stack[-4];
    fn = elt(env, 4); // ibalp_calcmom
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0044 = (*qfn2(fn))(qenv(fn), stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    v0044 = nil;
    { popv(7); return onevalue(v0044); }

v0053:
    v0044 = stack[-4];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcar(v0044);
    goto v0054;

v0047:
    v0044 = stack[-4];
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcar(v0044);
    goto v0048;
// error exit handlers
v0046:
    popv(7);
    return nil;
}



// Code for vsl_boundtype

static LispObject CC_vsl_boundtype(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0057, v0013;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vsl_boundtype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0057 = v0007;
    v0013 = v0015;
// end of prologue
    v0013 = qcdr(v0013);
    v0013 = qcar(v0013);
    {
        fn = elt(env, 1); // vsl_boundtype1
        return (*qfn2(fn))(qenv(fn), v0013, v0057);
    }
}



// Code for my_letmtr

static LispObject CC_my_letmtr(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0054, v0078, v0079;
    LispObject fn;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "my_letmtr");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for my_letmtr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0015,v0007,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-3] = v0004;
    stack[-4] = v0007;
    stack[-5] = v0015;
// end of prologue
    stack[-2] = nil;
    v0078 = stack[-3];
    v0054 = elt(env, 1); // mat
    if (!consp(v0078)) goto v0080;
    v0078 = qcar(v0078);
    if (!(v0078 == v0054)) goto v0080;
    v0054 = stack[-5];
    v0054 = qcdr(v0054);
    stack[-6] = v0054;
    v0054 = stack[-6];
    if (v0054 == nil) goto v0039;
    v0054 = stack[-6];
    v0054 = qcar(v0054);
    v0078 = v0054;
    v0054 = v0078;
    v0054 = integerp(v0054);
    if (v0054 == nil) goto v0081;
    v0054 = v0078;
    goto v0082;

v0082:
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    stack[-1] = v0054;
    stack[-2] = v0054;
    goto v0001;

v0001:
    v0054 = stack[-6];
    v0054 = qcdr(v0054);
    stack[-6] = v0054;
    v0054 = stack[-6];
    if (v0054 == nil) goto v0084;
    stack[0] = stack[-1];
    v0054 = stack[-6];
    v0054 = qcar(v0054);
    v0078 = v0054;
    v0054 = v0078;
    v0054 = integerp(v0054);
    if (v0054 == nil) goto v0085;
    v0054 = v0078;
    goto v0086;

v0086:
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    v0054 = Lrplacd(nil, stack[0], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    stack[-1] = v0054;
    goto v0001;

v0085:
    v0054 = v0078;
    fn = elt(env, 8); // reval
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    goto v0086;

v0084:
    v0054 = stack[-2];
    goto v0006;

v0006:
    stack[-2] = v0054;
    fn = elt(env, 9); // numlis
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    if (v0054 == nil) goto v0041;
    v0054 = stack[-2];
    v0078 = Llength(nil, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    v0054 = (LispObject)33; // 2
    v0054 = Lneq(nil, v0078, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    goto v0000;

v0000:
    if (v0054 == nil) goto v0029;
    v0078 = stack[-5];
    v0054 = elt(env, 7); // hold
    {
        popv(8);
        fn = elt(env, 10); // errpri2
        return (*qfn2(fn))(qenv(fn), v0078, v0054);
    }

v0029:
    v0054 = stack[-3];
    v0078 = qcdr(v0054);
    v0054 = stack[-2];
    v0054 = qcar(v0054);
    fn = elt(env, 11); // nth
    v0078 = (*qfn2(fn))(qenv(fn), v0078, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    v0054 = stack[-2];
    v0054 = qcdr(v0054);
    v0054 = qcar(v0054);
    fn = elt(env, 12); // pnth
    v0078 = (*qfn2(fn))(qenv(fn), v0078, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    v0054 = stack[-4];
    v0054 = Lrplaca(nil, v0078, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    v0054 = nil;
    { popv(8); return onevalue(v0054); }

v0041:
    v0054 = qvalue(elt(env, 6)); // t
    goto v0000;

v0081:
    v0054 = v0078;
    fn = elt(env, 8); // reval
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    goto v0082;

v0039:
    v0054 = qvalue(elt(env, 5)); // nil
    goto v0006;

v0080:
    stack[-1] = elt(env, 2); // matrix
    stack[0] = (LispObject)161; // 10
    v0079 = elt(env, 3); // "Matrix"
    v0054 = stack[-5];
    v0078 = qcar(v0054);
    v0054 = elt(env, 4); // "not set"
    v0054 = list3(v0079, v0078, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    fn = elt(env, 13); // rerror
    v0054 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-7];
    goto v0029;
// error exit handlers
v0083:
    popv(8);
    return nil;
}



// Code for xlcm

static LispObject CC_xlcm(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0030, v0031;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xlcm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0015;
// end of prologue
    stack[-2] = nil;
    goto v0096;

v0096:
    v0030 = stack[-1];
    if (v0030 == nil) goto v0057;
    v0030 = stack[-1];
    v0031 = qcar(v0030);
    v0030 = (LispObject)17; // 1
    v0030 = (v0031 == v0030 ? lisp_true : nil);
    goto v0056;

v0056:
    if (v0030 == nil) goto v0097;
    v0031 = stack[-2];
    v0030 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0031, v0030);
    }

v0097:
    v0030 = stack[0];
    if (v0030 == nil) goto v0074;
    v0030 = stack[0];
    v0031 = qcar(v0030);
    v0030 = (LispObject)17; // 1
    v0030 = (v0031 == v0030 ? lisp_true : nil);
    goto v0073;

v0073:
    if (v0030 == nil) goto v0047;
    v0031 = stack[-2];
    v0030 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0031, v0030);
    }

v0047:
    v0030 = stack[-1];
    v0031 = qcar(v0030);
    v0030 = stack[0];
    v0030 = qcar(v0030);
    if (v0031 == v0030) goto v0098;
    v0030 = stack[-1];
    v0031 = qcar(v0030);
    v0030 = stack[0];
    v0030 = qcar(v0030);
    fn = elt(env, 3); // factorordp
    v0030 = (*qfn2(fn))(qenv(fn), v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    if (v0030 == nil) goto v0099;
    v0030 = stack[-1];
    v0031 = qcar(v0030);
    v0030 = stack[-2];
    v0030 = cons(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    stack[-2] = v0030;
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    stack[-1] = v0030;
    goto v0096;

v0099:
    v0030 = stack[0];
    v0031 = qcar(v0030);
    v0030 = stack[-2];
    v0030 = cons(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    stack[-2] = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    goto v0096;

v0098:
    v0030 = stack[-1];
    v0031 = qcar(v0030);
    v0030 = stack[-2];
    v0030 = cons(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    stack[-2] = v0030;
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    stack[-1] = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    goto v0096;

v0074:
    v0030 = qvalue(elt(env, 1)); // t
    goto v0073;

v0057:
    v0030 = qvalue(elt(env, 1)); // t
    goto v0056;
// error exit handlers
v0063:
    popv(4);
    return nil;
}



// Code for replace1_parents

static LispObject CC_replace1_parents(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0100, v0080, v0101;
    LispObject fn;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace1_parents");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replace1_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0100 = v0004;
    v0080 = v0007;
    v0101 = v0015;
// end of prologue
    v0101 = qcar(v0101);
    v0080 = qcar(v0080);
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    {
        fn = elt(env, 1); // replace2_parents
        return (*qfnn(fn))(qenv(fn), 3, v0101, v0080, v0100);
    }
}



// Code for endstat

static LispObject CC_endstat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0102;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endstat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for endstat");
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
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push(nil);
// end of prologue
    v0102 = qvalue(elt(env, 1)); // cursym!*
    stack[0] = v0102;
    v0102 = elt(env, 2); // end
    fn = elt(env, 3); // comm1
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    v0102 = stack[0];
    popv(1);
    return ncons(v0102);
// error exit handlers
v0055:
    popv(1);
    return nil;
}



// Code for setel

static LispObject CC_setel(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0040, v0020, v0090, v0091;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0007;
    stack[-2] = v0015;
// end of prologue
    v0040 = stack[-2];
    v0020 = qcar(v0040);
    v0040 = elt(env, 1); // dimension
    v0040 = get(v0020, v0040);
    env = stack[-4];
    stack[-3] = v0040;
    v0040 = stack[-3];
    stack[0] = Llength(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-4];
    v0040 = stack[-2];
    v0040 = qcdr(v0040);
    v0040 = Llength(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-4];
    if (equal(stack[0], v0040)) goto v0105;
    v0090 = elt(env, 2); // rlisp
    v0020 = (LispObject)353; // 22
    v0040 = elt(env, 3); // "Incorrect array reference"
    {
        popv(5);
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0090, v0020, v0040);
    }

v0105:
    v0040 = stack[-2];
    v0040 = qcar(v0040);
    if (!symbolp(v0040)) v0040 = nil;
    else { v0040 = qfastgets(v0040);
           if (v0040 != nil) { v0040 = elt(v0040, 4); // avalue
#ifdef RECORD_GET
             if (v0040 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0040 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0040 == SPID_NOPROP) v0040 = nil; }}
#endif
    v0040 = qcdr(v0040);
    v0091 = qcar(v0040);
    v0040 = stack[-2];
    v0090 = qcdr(v0040);
    v0020 = stack[-1];
    v0040 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); // setel1
        return (*qfnn(fn))(qenv(fn), 4, v0091, v0090, v0020, v0040);
    }
// error exit handlers
v0082:
    popv(5);
    return nil;
}



// Code for fs!:prin1

static LispObject CC_fsTprin1(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0119, v0120;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:prin1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0015;
// end of prologue
    v0119 = qvalue(elt(env, 1)); // t
    stack[-3] = v0119;
    v0120 = stack[0];
    v0119 = (LispObject)1; // 0
    v0120 = *(LispObject *)((char *)v0120 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL)));
    v0119 = elt(env, 2); // (1 . 1)
    if (equal(v0120, v0119)) goto v0102;
    v0119 = elt(env, 3); // "("
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0120 = stack[0];
    v0119 = (LispObject)1; // 0
    v0119 = *(LispObject *)((char *)v0120 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL)));
    fn = elt(env, 13); // sqprint
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0119 = elt(env, 4); // ")"
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    goto v0102;

v0102:
    v0119 = stack[0];
    fn = elt(env, 14); // fs!:null!-angle
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    if (v0119 == nil) goto v0122;
    v0120 = stack[0];
    v0119 = (LispObject)1; // 0
    v0120 = *(LispObject *)((char *)v0120 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL)));
    v0119 = elt(env, 2); // (1 . 1)
    if (!(equal(v0120, v0119))) goto v0074;
    v0119 = elt(env, 11); // "1"
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    goto v0074;

v0074:
    v0119 = nil;
    { popv(5); return onevalue(v0119); }

v0122:
    v0120 = stack[0];
    v0119 = (LispObject)17; // 1
    v0119 = *(LispObject *)((char *)v0120 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL)));
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0119 = elt(env, 5); // "["
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0120 = stack[0];
    v0119 = (LispObject)33; // 2
    v0119 = *(LispObject *)((char *)v0120 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL)));
    stack[-2] = v0119;
    v0119 = (LispObject)1; // 0
    stack[0] = v0119;
    goto v0098;

v0098:
    v0120 = (LispObject)113; // 7
    v0119 = stack[0];
    v0119 = difference2(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0119 = Lminusp(nil, v0119);
    env = stack[-4];
    if (v0119 == nil) goto v0069;
    v0119 = elt(env, 10); // "]"
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    goto v0074;

v0069:
    v0120 = stack[-2];
    v0119 = stack[0];
    v0120 = *(LispObject *)((char *)v0120 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL)));
    stack[-1] = v0120;
    v0119 = (LispObject)1; // 0
    if (v0120 == v0119) goto v0032;
    v0120 = stack[-1];
    v0119 = (LispObject)1; // 0
    v0119 = (LispObject)lessp2(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    v0119 = v0119 ? lisp_true : nil;
    env = stack[-4];
    if (v0119 == nil) goto v0123;
    v0119 = qvalue(elt(env, 1)); // t
    stack[-3] = v0119;
    v0119 = elt(env, 7); // "-"
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0119 = stack[-1];
    v0119 = negate(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    stack[-1] = v0119;
    goto v0123;

v0123:
    v0119 = stack[-3];
    if (!(v0119 == nil)) goto v0124;
    v0119 = elt(env, 8); // "+"
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    goto v0124;

v0124:
    v0120 = stack[-1];
    v0119 = (LispObject)17; // 1
    if (v0120 == v0119) goto v0125;
    v0119 = stack[-1];
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    goto v0125;

v0125:
    v0119 = qvalue(elt(env, 6)); // nil
    stack[-3] = v0119;
    v0120 = qvalue(elt(env, 9)); // fourier!-name!*
    v0119 = stack[0];
    v0119 = *(LispObject *)((char *)v0120 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL)));
    fn = elt(env, 12); // prin2!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    goto v0032;

v0032:
    v0119 = stack[0];
    v0119 = add1(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    stack[0] = v0119;
    goto v0098;
// error exit handlers
v0121:
    popv(5);
    return nil;
}



// Code for st_sorttree

static LispObject CC_st_sorttree(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0043, v0077, v0076;
    LispObject fn;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for st_sorttree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0015,v0007,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0043 = v0004;
    v0077 = v0007;
    v0076 = v0015;
// end of prologue
    fn = elt(env, 1); // st_sorttree1
    v0043 = (*qfnn(fn))(qenv(fn), 3, v0076, v0077, v0043);
    errexit();
    v0043 = qcdr(v0043);
    return onevalue(v0043);
}



// Code for poly!-multfnc

static LispObject CC_polyKmultfnc(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0144, v0145, v0146;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-multfnc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0007;
    stack[-2] = v0015;
// end of prologue
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    stack[0] = qcdr(v0144);
    v0144 = stack[-1];
    v0144 = qcar(v0144);
    v0144 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    fn = elt(env, 4); // poly!-multf
    v0144 = (*qfn2(fn))(qenv(fn), stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-3] = v0144;
    v0144 = stack[-3];
    if (v0144 == nil) goto v0148;
    v0144 = stack[-3];
    if (!consp(v0144)) goto v0010;
    v0144 = stack[-3];
    v0144 = qcar(v0144);
    v0144 = (consp(v0144) ? nil : lisp_true);
    goto v0009;

v0009:
    if (v0144 == nil) goto v0149;
    v0144 = qvalue(elt(env, 1)); // nil
    goto v0071;

v0071:
    if (v0144 == nil) goto v0095;
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    stack[0] = qcar(v0144);
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    v0145 = qcdr(v0144);
    v0144 = stack[-3];
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    v0144 = qcdr(v0144);
    v0144 = plus2(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    fn = elt(env, 5); // mkspm
    v0144 = (*qfn2(fn))(qenv(fn), stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0146 = v0144;
    if (v0144 == nil) goto v0082;
    v0145 = v0146;
    v0144 = (LispObject)17; // 1
    if (v0145 == v0144) goto v0150;
    v0145 = v0146;
    v0144 = stack[-3];
    v0144 = qcar(v0144);
    v0144 = qcdr(v0144);
    v0144 = cons(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0144 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[0] = v0144;
    goto v0062;

v0062:
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    v0145 = qcar(v0144);
    v0144 = (LispObject)17; // 1
    v0144 = cons(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0145 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0144 = stack[-3];
    v0144 = qcdr(v0144);
    fn = elt(env, 4); // poly!-multf
    v0144 = (*qfn2(fn))(qenv(fn), v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    fn = elt(env, 6); // addf
    v0144 = (*qfn2(fn))(qenv(fn), stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-3] = v0144;
    goto v0148;

v0148:
    v0144 = stack[-2];
    v0145 = qcdr(v0144);
    v0144 = stack[-1];
    fn = elt(env, 4); // poly!-multf
    stack[0] = (*qfn2(fn))(qenv(fn), v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    v0145 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0144 = stack[-1];
    v0144 = qcdr(v0144);
    fn = elt(env, 4); // poly!-multf
    v0144 = (*qfn2(fn))(qenv(fn), v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    fn = elt(env, 6); // addf
    v0144 = (*qfn2(fn))(qenv(fn), stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    {
        LispObject v0151 = stack[-3];
        popv(5);
        fn = elt(env, 6); // addf
        return (*qfn2(fn))(qenv(fn), v0151, v0144);
    }

v0150:
    v0144 = stack[-3];
    v0144 = qcar(v0144);
    v0144 = qcdr(v0144);
    stack[0] = v0144;
    goto v0062;

v0082:
    v0144 = qvalue(elt(env, 1)); // nil
    stack[0] = v0144;
    goto v0062;

v0095:
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    fn = elt(env, 7); // noncomp
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    if (v0144 == nil) goto v0078;
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    v0145 = qcar(v0144);
    v0144 = stack[-3];
    v0144 = cons(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0144 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-3] = v0144;
    goto v0148;

v0078:
    v0144 = qvalue(elt(env, 2)); // t
    stack[0] = qvalue(elt(env, 3)); // !*!*processed
    qvalue(elt(env, 3)) = v0144; // !*!*processed
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    v0145 = qcar(v0144);
    v0144 = (LispObject)17; // 1
    v0144 = cons(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    v0145 = ncons(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    v0144 = stack[-3];
    fn = elt(env, 4); // poly!-multf
    v0144 = (*qfn2(fn))(qenv(fn), v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-4];
    stack[-3] = v0144;
    qvalue(elt(env, 3)) = stack[0]; // !*!*processed
    goto v0148;

v0149:
    v0144 = stack[-3];
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    v0145 = qcar(v0144);
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    v0144 = (v0145 == v0144 ? lisp_true : nil);
    goto v0071;

v0010:
    v0144 = qvalue(elt(env, 2)); // t
    goto v0009;
// error exit handlers
v0152:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[0]; // !*!*processed
    popv(5);
    return nil;
v0147:
    popv(5);
    return nil;
}



// Code for ofsf_sippsubst

static LispObject CC_ofsf_sippsubst(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0100, v0080, v0101;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_sippsubst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0080 = v0007;
    v0101 = v0015;
// end of prologue
    v0100 = v0080;
    if (v0100 == nil) return onevalue(v0101);
    v0100 = v0101;
    {
        fn = elt(env, 1); // ofsf_sippsubst1
        return (*qfn2(fn))(qenv(fn), v0100, v0080);
    }
}



// Code for inprint

static LispObject CC_inprint(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0196, v0197, v0198;
    LispObject fn;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprint");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0015,v0007,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0004;
    stack[-2] = v0007;
    stack[-3] = v0015;
// end of prologue
    stack[-4] = nil;
    stack[0] = nil;
    v0197 = stack[-3];
    v0196 = elt(env, 1); // times
    if (v0197 == v0196) goto v0014;
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0013;

v0013:
    if (v0196 == nil) goto v0199;
    v0196 = elt(env, 5); // times2
    stack[-3] = v0196;
    v0198 = elt(env, 5); // times2
    v0197 = elt(env, 6); // infix
    v0196 = elt(env, 1); // times
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 23); // infix
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    v0196 = Lputprop(nil, 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0198 = elt(env, 5); // times2
    v0197 = elt(env, 7); // prtch
    v0196 = elt(env, 8); // " "
    v0196 = Lputprop(nil, 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0199;

v0199:
    v0197 = stack[-3];
    v0196 = elt(env, 9); // plus
    if (v0197 == v0196) goto v0082;
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0070;

v0070:
    if (v0196 == nil) goto v0091;
    v0196 = stack[-1];
    v0196 = Lreverse(nil, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    stack[-1] = v0196;
    goto v0091;

v0091:
    v0196 = stack[-3];
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 49); // alt
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    if (!(v0196 == nil)) goto v0201;
    v0197 = stack[-3];
    v0196 = elt(env, 11); // not
    if (v0197 == v0196) goto v0202;
    v0197 = stack[-3];
    v0196 = elt(env, 12); // setq
    if (v0197 == v0196) goto v0203;
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0204;

v0204:
    if (v0196 == nil) goto v0205;
    v0198 = stack[0];
    v0196 = stack[-1];
    v0197 = qcar(v0196);
    v0196 = stack[-4];
        popv(6);
        return Lapply2(nil, 3, v0198, v0197, v0196);

v0205:
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    if (!consp(v0196)) goto v0206;
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    v0196 = qcar(v0196);
    if (symbolp(v0196)) goto v0046;
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0134;

v0134:
    if (v0196 == nil) goto v0136;
    v0196 = elt(env, 16); // "("
    fn = elt(env, 22); // prin2!*
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0196 = stack[-1];
    v0197 = qcar(v0196);
    v0196 = stack[-2];
    fn = elt(env, 23); // maprint
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0196 = elt(env, 17); // ")"
    fn = elt(env, 22); // prin2!*
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0207;

v0207:
    v0196 = stack[-1];
    v0196 = qcdr(v0196);
    stack[-1] = v0196;
    goto v0201;

v0201:
    v0196 = qvalue(elt(env, 18)); // !*nosplit
    if (v0196 == nil) goto v0208;
    v0196 = qvalue(elt(env, 19)); // testing!-width!*
    if (!(v0196 == nil)) goto v0208;
    v0196 = stack[-1];
    stack[-1] = v0196;
    goto v0209;

v0209:
    v0196 = stack[-1];
    if (v0196 == nil) goto v0210;
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    stack[0] = v0196;
    v0196 = stack[0];
    if (!consp(v0196)) goto v0211;
    v0197 = stack[-3];
    v0196 = stack[0];
    v0196 = qcar(v0196);
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 49); // alt
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    v0196 = (v0197 == v0196 ? lisp_true : nil);
    v0196 = (v0196 == nil ? lisp_true : nil);
    goto v0212;

v0212:
    if (v0196 == nil) goto v0213;
    v0197 = stack[-3];
    v0196 = elt(env, 21); // (setq !*comma!*)
    v0196 = Lmemq(nil, v0197, v0196);
    if (v0196 == nil) goto v0214;
    v0196 = stack[-3];
    fn = elt(env, 24); // oprin
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0196 = stack[0];
    fn = elt(env, 25); // negnumberchk
    v0198 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0197 = stack[-2];
    v0196 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 26); // prinfit
    v0196 = (*qfnn(fn))(qenv(fn), 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0215;

v0215:
    v0196 = stack[-1];
    v0196 = qcdr(v0196);
    stack[-1] = v0196;
    goto v0209;

v0214:
    v0196 = stack[0];
    fn = elt(env, 25); // negnumberchk
    v0198 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0197 = stack[-2];
    v0196 = stack[-3];
    fn = elt(env, 26); // prinfit
    v0196 = (*qfnn(fn))(qenv(fn), 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0215;

v0213:
    v0198 = stack[0];
    v0197 = stack[-2];
    v0196 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 26); // prinfit
    v0196 = (*qfnn(fn))(qenv(fn), 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0215;

v0211:
    v0196 = qvalue(elt(env, 20)); // t
    goto v0212;

v0210:
    v0196 = nil;
    { popv(6); return onevalue(v0196); }

v0208:
    v0196 = stack[-1];
    stack[-1] = v0196;
    goto v0216;

v0216:
    v0196 = stack[-1];
    if (v0196 == nil) goto v0210;
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    stack[0] = v0196;
    v0196 = stack[0];
    if (!consp(v0196)) goto v0217;
    v0197 = stack[-3];
    v0196 = stack[0];
    v0196 = qcar(v0196);
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 49); // alt
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    v0196 = (v0197 == v0196 ? lisp_true : nil);
    v0196 = (v0196 == nil ? lisp_true : nil);
    goto v0218;

v0218:
    if (v0196 == nil) goto v0219;
    v0196 = stack[-3];
    fn = elt(env, 24); // oprin
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0196 = stack[0];
    fn = elt(env, 25); // negnumberchk
    v0197 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0196 = stack[-2];
    fn = elt(env, 23); // maprint
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0220;

v0220:
    v0196 = stack[-1];
    v0196 = qcdr(v0196);
    stack[-1] = v0196;
    goto v0216;

v0219:
    v0197 = stack[0];
    v0196 = stack[-2];
    fn = elt(env, 23); // maprint
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0220;

v0217:
    v0196 = qvalue(elt(env, 20)); // t
    goto v0218;

v0136:
    v0196 = qvalue(elt(env, 18)); // !*nosplit
    if (v0196 == nil) goto v0221;
    v0196 = qvalue(elt(env, 19)); // testing!-width!*
    if (!(v0196 == nil)) goto v0221;
    v0196 = stack[-1];
    v0198 = qcar(v0196);
    v0197 = stack[-2];
    v0196 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 26); // prinfit
    v0196 = (*qfnn(fn))(qenv(fn), 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0207;

v0221:
    v0196 = stack[-1];
    v0197 = qcar(v0196);
    v0196 = stack[-2];
    fn = elt(env, 23); // maprint
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0207;

v0046:
    v0196 = qvalue(elt(env, 2)); // !*nat
    if (v0196 == nil) goto v0222;
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    v0196 = qcar(v0196);
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 57); // prifn
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    stack[-4] = v0196;
    if (!(v0196 == nil)) goto v0223;
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    v0196 = qcar(v0196);
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 60); // pprifn
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 60), 1);
             else record_get(elt(fastget_names, 60), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 60), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    stack[-4] = v0196;
    if (!(v0196 == nil)) goto v0223;
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0134;

v0223:
    v0197 = stack[-4];
    v0196 = stack[-3];
    v0197 = get(v0197, v0196);
    env = stack[-5];
    v0196 = elt(env, 15); // inbrackets
    v0196 = (v0197 == v0196 ? lisp_true : nil);
    goto v0134;

v0222:
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0134;

v0206:
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0134;

v0203:
    v0196 = stack[-1];
    v0196 = Lreverse(nil, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0196 = qcar(v0196);
    stack[-4] = v0196;
    if (!consp(v0196)) goto v0059;
    v0196 = stack[-4];
    v0196 = qcar(v0196);
    if (symbolp(v0196)) goto v0063;
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0204;

v0063:
    v0196 = stack[-4];
    fn = elt(env, 27); // getrtype
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    stack[0] = v0196;
    if (v0196 == nil) goto v0224;
    v0197 = stack[0];
    v0196 = elt(env, 13); // tag
    v0197 = get(v0197, v0196);
    env = stack[-5];
    v0196 = elt(env, 14); // setprifn
    v0196 = get(v0197, v0196);
    env = stack[-5];
    stack[0] = v0196;
    goto v0204;

v0224:
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0204;

v0059:
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0204;

v0202:
    v0196 = stack[-3];
    fn = elt(env, 24); // oprin
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    goto v0205;

v0082:
    v0196 = qvalue(elt(env, 10)); // !*revpri
    goto v0070;

v0014:
    v0196 = qvalue(elt(env, 2)); // !*nat
    if (v0196 == nil) goto v0095;
    v0196 = qvalue(elt(env, 4)); // !*asterisk
    v0196 = (v0196 == nil ? lisp_true : nil);
    goto v0013;

v0095:
    v0196 = qvalue(elt(env, 3)); // nil
    goto v0013;
// error exit handlers
v0200:
    popv(6);
    return nil;
}



// Code for xregister_wedge_pair

static LispObject CC_xregister_wedge_pair(LispObject env, int nargs, ...)
{
    LispObject v0004;
    argcheck(nargs, 0, "xregister_wedge_pair");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xregister_wedge_pair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// end of prologue
    v0004 = qvalue(elt(env, 1)); // nil
    return onevalue(v0004);
}



// Code for cos!*

static LispObject CC_cosH(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0097, v0055;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cos*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0097 = v0015;
// end of prologue
    v0055 = v0097;
    v0097 = qvalue(elt(env, 1)); // !:bprec!:
    {
        fn = elt(env, 2); // cos!:
        return (*qfn2(fn))(qenv(fn), v0055, v0097);
    }
}



// Code for def_edge

static LispObject CC_def_edge(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0009, v0010, v0093, v0094;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for def_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0094 = v0007;
    v0009 = v0015;
// end of prologue
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    v0093 = v0009;
    v0009 = v0093;
    v0010 = qcar(v0009);
    v0009 = v0094;
    v0009 = Lassoc(nil, v0010, v0009);
    if (v0009 == nil) goto v0102;
    v0009 = v0093;
    v0009 = qcdr(v0009);
    v0010 = v0094;
    v0009 = Lassoc(nil, v0009, v0010);
    return onevalue(v0009);

v0102:
    v0009 = qvalue(elt(env, 1)); // nil
    return onevalue(v0009);
}



// Code for repartf

static LispObject CC_repartf(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0227, v0030;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repartf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0015;
// end of prologue
    v0030 = elt(env, 1); // i
    v0227 = qvalue(elt(env, 2)); // kord!*
    v0227 = cons(v0030, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); // kord!*
    qvalue(elt(env, 2)) = v0227; // kord!*
    v0227 = stack[0];
    fn = elt(env, 5); // reorder
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[-2] = v0227;
    v0227 = stack[-2];
    if (!consp(v0227)) goto v0080;
    v0227 = stack[-2];
    v0227 = qcar(v0227);
    v0227 = (consp(v0227) ? nil : lisp_true);
    goto v0100;

v0100:
    if (v0227 == nil) goto v0228;
    v0227 = stack[-2];
    if (!consp(v0227)) goto v0012;
    v0227 = stack[-2];
    v0030 = qcar(v0227);
    v0227 = elt(env, 4); // cmpxfn
    v0227 = get(v0030, v0227);
    env = stack[-4];
    if (v0227 == nil) goto v0229;
    v0227 = stack[-2];
    stack[-1] = qcar(v0227);
    v0227 = stack[-2];
    v0227 = qcdr(v0227);
    stack[0] = qcar(v0227);
    v0227 = stack[-2];
    v0227 = qcar(v0227);
    if (!symbolp(v0227)) v0030 = nil;
    else { v0030 = qfastgets(v0227);
           if (v0030 != nil) { v0030 = elt(v0030, 34); // i2d
#ifdef RECORD_GET
             if (v0030 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0030 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0030 == SPID_NOPROP) v0030 = nil; }}
#endif
    v0227 = (LispObject)1; // 0
    v0227 = Lapply1(nil, v0030, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0227 = qcdr(v0227);
    v0227 = qcar(v0227);
    v0227 = list2star(stack[-1], stack[0], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    fn = elt(env, 6); // int!-equiv!-chk
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    goto v0014;

v0014:
    qvalue(elt(env, 2)) = stack[-3]; // kord!*
    { popv(5); return onevalue(v0227); }

v0229:
    v0227 = stack[-2];
    goto v0014;

v0012:
    v0227 = stack[-2];
    goto v0014;

v0228:
    v0227 = stack[-2];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0030 = qcar(v0227);
    v0227 = elt(env, 1); // i
    if (v0030 == v0227) goto v0098;
    v0227 = stack[-2];
    v0227 = qcar(v0227);
    v0030 = qcar(v0227);
    v0227 = (LispObject)17; // 1
    v0227 = cons(v0030, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[0] = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0227 = stack[-2];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    v0227 = CC_repartf(env, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    fn = elt(env, 7); // multf
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0227 = stack[-2];
    v0227 = qcdr(v0227);
    v0227 = CC_repartf(env, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    fn = elt(env, 8); // addf
    v0227 = (*qfn2(fn))(qenv(fn), stack[0], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    goto v0014;

v0098:
    v0227 = stack[-2];
    v0227 = qcdr(v0227);
    v0227 = CC_repartf(env, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    goto v0014;

v0080:
    v0227 = qvalue(elt(env, 3)); // t
    goto v0100;
// error exit handlers
v0124:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; // kord!*
    popv(5);
    return nil;
v0063:
    popv(5);
    return nil;
}



// Code for total!-degree!-in!-powers

static LispObject CC_totalKdegreeKinKpowers(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0190, v0139, v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for total-degree-in-powers");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0015;
// end of prologue

v0232:
    v0190 = stack[-1];
    if (v0190 == nil) goto v0102;
    v0190 = stack[-1];
    if (!consp(v0190)) goto v0077;
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = (consp(v0190) ? nil : lisp_true);
    goto v0225;

v0225:
    if (!(v0190 == nil)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0139 = qcar(v0190);
    v0190 = stack[0];
    v0190 = Latsoc(nil, v0139, v0190);
    stack[-2] = v0190;
    if (v0190 == nil) goto v0117;
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0139 = qcdr(v0190);
    v0190 = stack[-2];
    v0190 = qcdr(v0190);
    v0190 = (LispObject)greaterp2(v0139, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    v0190 = v0190 ? lisp_true : nil;
    env = stack[-3];
    if (v0190 == nil) goto v0086;
    v0139 = stack[-2];
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0190 = qcdr(v0190);
    v0190 = Lrplacd(nil, v0139, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    goto v0086;

v0086:
    v0190 = stack[-1];
    stack[-2] = qcdr(v0190);
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0139 = qcdr(v0190);
    v0190 = stack[0];
    v0190 = CC_totalKdegreeKinKpowers(env, v0139, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v0190;
    goto v0232;

v0117:
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0051 = qcar(v0190);
    v0190 = stack[-1];
    v0190 = qcar(v0190);
    v0190 = qcar(v0190);
    v0139 = qcdr(v0190);
    v0190 = stack[0];
    v0190 = acons(v0051, v0139, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    stack[0] = v0190;
    goto v0086;

v0077:
    v0190 = qvalue(elt(env, 1)); // t
    goto v0225;

v0102:
    v0190 = qvalue(elt(env, 1)); // t
    goto v0225;
// error exit handlers
v0066:
    popv(4);
    return nil;
}



// Code for fs!:null!-angle

static LispObject CC_fsTnullKangle(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0006, v0001;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:null-angle");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0006 = v0015;
// end of prologue
    v0001 = v0006;
    v0006 = (LispObject)33; // 2
    v0006 = *(LispObject *)((char *)v0001 + (CELL-TAG_VECTOR) + ((int32_t)v0006/(16/CELL)));
    stack[0] = v0006;
    v0006 = qvalue(elt(env, 1)); // t
    stack[-2] = v0006;
    v0006 = (LispObject)1; // 0
    stack[-1] = v0006;
    goto v0072;

v0072:
    v0001 = stack[0];
    v0006 = stack[-1];
    v0001 = *(LispObject *)((char *)v0001 + (CELL-TAG_VECTOR) + ((int32_t)v0006/(16/CELL)));
    v0006 = (LispObject)1; // 0
    if (v0001 == v0006) goto v0100;
    v0006 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0006); }

v0100:
    v0006 = stack[-1];
    v0006 = add1(v0006);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    stack[-1] = v0006;
    v0001 = stack[-1];
    v0006 = (LispObject)129; // 8
    v0006 = (LispObject)lessp2(v0001, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    v0006 = v0006 ? lisp_true : nil;
    env = stack[-3];
    if (v0006 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    else goto v0072;
// error exit handlers
v0018:
    popv(4);
    return nil;
}



// Code for gcdout

static LispObject CC_gcdout(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0052, v0233, v0143;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdout");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0015;
// end of prologue
    v0052 = qvalue(elt(env, 1)); // !*modular
    if (!(v0052 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0052 = stack[0];
    if (v0052 == nil) goto v0225;
    v0052 = stack[0];
    fn = elt(env, 3); // ljet
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    fn = elt(env, 4); // ord
    v0233 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    v0052 = (LispObject)1; // 0
    if (v0233 == v0052) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0052 = stack[0];
    stack[-1] = v0052;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    v0052 = qcdr(v0052);
    v0143 = v0052;
    goto v0103;

v0103:
    v0052 = stack[-1];
    if (v0052 == nil) goto v0234;
    v0233 = v0143;
    v0052 = (LispObject)17; // 1
    if (v0233 == v0052) goto v0234;
    v0233 = v0143;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    v0052 = qcdr(v0052);
    fn = elt(env, 5); // gcdf!*
    v0052 = (*qfn2(fn))(qenv(fn), v0233, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    v0143 = v0052;
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    stack[-1] = v0052;
    goto v0103;

v0234:
    v0233 = v0143;
    v0052 = (LispObject)17; // 1
    if (v0233 == v0052) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0052 = stack[0];
    v0233 = v0143;
    {
        popv(3);
        fn = elt(env, 6); // pcdiv
        return (*qfn2(fn))(qenv(fn), v0052, v0233);
    }

v0225:
    v0052 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0052); }
// error exit handlers
v0068:
    popv(3);
    return nil;
}



// Code for numlist_ordp

static LispObject CC_numlist_ordp(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0013, v0014, v0043;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numlist_ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0013 = v0007;
    v0014 = v0015;
// end of prologue
    v0043 = v0014;
    v0014 = v0013;
    v0013 = elt(env, 1); // lambda_u9iz36vfudu4
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(qenv(fn), 3, v0043, v0014, v0013);
    }
}



// Code for lambda_u9iz36vfudu4

static LispObject CC_lambda_u9iz36vfudu4(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_u9iz36vfudu4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0055 = v0007;
    v0056 = v0015;
// end of prologue
        return Lleq(nil, v0056, v0055);
}



// Code for subf

static LispObject CC_subf(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0238, v0132;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0007;
    stack[-7] = v0015;
// end of prologue
    stack[-8] = qvalue(elt(env, 1)); // alglist!*
    qvalue(elt(env, 1)) = nil; // alglist!*
    stack[-5] = nil;
    stack[-4] = nil;
    v0238 = qvalue(elt(env, 2)); // nil
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0238; // alglist!*
    v0238 = stack[-7];
    if (!consp(v0238)) goto v0077;
    v0238 = stack[-7];
    v0238 = qcar(v0238);
    v0238 = (consp(v0238) ? nil : lisp_true);
    goto v0043;

v0043:
    if (v0238 == nil) goto v0013;
    v0238 = stack[-7];
    fn = elt(env, 7); // !*d2q
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    goto v0225;

v0225:
    qvalue(elt(env, 1)) = stack[-8]; // alglist!*
    { popv(10); return onevalue(v0238); }

v0013:
    v0238 = qvalue(elt(env, 4)); // ncmp!*
    if (v0238 == nil) goto v0041;
    v0238 = stack[-7];
    fn = elt(env, 8); // noncomexpf
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    if (v0238 == nil) goto v0041;
    v0132 = stack[-7];
    v0238 = stack[-6];
    fn = elt(env, 9); // subf1
    v0238 = (*qfn2(fn))(qenv(fn), v0132, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    goto v0225;

v0041:
    v0238 = stack[-6];
    stack[-3] = v0238;
    v0238 = stack[-3];
    if (v0238 == nil) goto v0040;
    v0238 = stack[-3];
    v0238 = qcar(v0238);
    v0238 = qcar(v0238);
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    stack[-1] = v0238;
    stack[-2] = v0238;
    goto v0016;

v0016:
    v0238 = stack[-3];
    v0238 = qcdr(v0238);
    stack[-3] = v0238;
    v0238 = stack[-3];
    if (v0238 == nil) goto v0081;
    stack[0] = stack[-1];
    v0238 = stack[-3];
    v0238 = qcar(v0238);
    v0238 = qcar(v0238);
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = Lrplacd(nil, stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = stack[-1];
    v0238 = qcdr(v0238);
    stack[-1] = v0238;
    goto v0016;

v0081:
    v0238 = stack[-2];
    stack[0] = v0238;
    goto v0240;

v0240:
    v0132 = stack[-7];
    v0238 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 10); // kernord
    v0238 = (*qfn2(fn))(qenv(fn), v0132, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    fn = elt(env, 11); // intersection
    v0238 = (*qfn2(fn))(qenv(fn), stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = Lreverse(nil, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    stack[0] = v0238;
    v0238 = stack[0];
    fn = elt(env, 12); // setkorder
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    stack[0] = v0238;
    v0238 = stack[-7];
    fn = elt(env, 13); // reorder
    v0132 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = stack[-6];
    fn = elt(env, 9); // subf1
    v0238 = (*qfn2(fn))(qenv(fn), v0132, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    stack[-7] = v0238;
    goto v0227;

v0227:
    v0132 = stack[-7];
    v0238 = stack[-4];
    v0238 = Lmember(nil, v0132, v0238);
    if (v0238 == nil) goto v0058;
    v0238 = qvalue(elt(env, 2)); // nil
    goto v0087;

v0087:
    if (v0238 == nil) goto v0114;
    v0132 = stack[-7];
    v0238 = stack[-4];
    v0238 = cons(v0132, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    stack[-4] = v0238;
    v0238 = stack[-5];
    fn = elt(env, 14); // simp
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    stack[-7] = v0238;
    goto v0227;

v0114:
    v0238 = stack[0];
    fn = elt(env, 12); // setkorder
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = stack[-7];
    v0238 = qcar(v0238);
    fn = elt(env, 13); // reorder
    stack[0] = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = stack[-7];
    v0238 = qcdr(v0238);
    fn = elt(env, 13); // reorder
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = cons(stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    goto v0225;

v0058:
    stack[-1] = elt(env, 5); // expt
    v0238 = stack[-7];
    v0238 = qcar(v0238);
    fn = elt(env, 15); // kernels
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = Latsoc(nil, stack[-1], v0238);
    if (!(v0238 == nil)) goto v0135;
    stack[-1] = elt(env, 5); // expt
    v0238 = stack[-7];
    v0238 = qcdr(v0238);
    fn = elt(env, 15); // kernels
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    v0238 = Latsoc(nil, stack[-1], v0238);
    if (!(v0238 == nil)) goto v0135;
    v0238 = qvalue(elt(env, 2)); // nil
    goto v0087;

v0135:
    v0238 = stack[-7];
    fn = elt(env, 16); // prepsq
    v0132 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0239;
    env = stack[-9];
    stack[-5] = v0132;
    v0238 = qvalue(elt(env, 6)); // varstack!*
    v0238 = Lmember(nil, v0132, v0238);
    v0238 = (v0238 == nil ? lisp_true : nil);
    goto v0087;

v0040:
    v0238 = qvalue(elt(env, 2)); // nil
    stack[0] = v0238;
    goto v0240;

v0077:
    v0238 = qvalue(elt(env, 3)); // t
    goto v0043;
// error exit handlers
v0239:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; // alglist!*
    popv(10);
    return nil;
}



// Code for pasf_smwupdknowl

static LispObject CC_pasf_smwupdknowl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0074, v0105, v0149, v0064, v0000;
    LispObject fn;
    LispObject v0003, v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwupdknowl");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0003 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smwupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0105 = v0003;
    v0149 = v0004;
    v0064 = v0007;
    v0000 = v0015;
// end of prologue
    v0074 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0074 == nil) goto v0072;
    v0074 = v0000;
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(qenv(fn), 4, v0074, v0064, v0149, v0105);
    }

v0072:
    v0074 = v0000;
    {
        fn = elt(env, 3); // cl_smupdknowl
        return (*qfnn(fn))(qenv(fn), 4, v0074, v0064, v0149, v0105);
    }
}



// Code for row

static LispObject CC_row(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0043;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for row");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0015;
// end of prologue
    v0043 = stack[0];
    if (v0043 == nil) goto v0026;
    v0043 = stack[0];
    v0043 = qcar(v0043);
    fn = elt(env, 2); // expression
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-1];
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = CC_row(env, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    goto v0026;

v0026:
    v0043 = nil;
    { popv(2); return onevalue(v0043); }
// error exit handlers
v0076:
    popv(2);
    return nil;
}



// Code for subs4q

static LispObject CC_subs4q(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0111, v0243, v0053;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs4q");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0015;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v0111 = elt(env, 1); // slash
    if (!symbolp(v0111)) v0111 = nil;
    else { v0111 = qfastgets(v0111);
           if (v0111 != nil) { v0111 = elt(v0111, 9); // opmtch
#ifdef RECORD_GET
             if (v0111 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0111 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0111 == SPID_NOPROP) v0111 = nil; }}
#endif
    stack[-6] = v0111;
    if (v0111 == nil) { LispObject res = stack[-5]; popv(8); return onevalue(res); }
    v0111 = stack[-5];
    fn = elt(env, 7); // prepsq
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    stack[-4] = v0111;
    v0243 = elt(env, 1); // slash
    v0111 = elt(env, 2); // opmtch
    v0111 = Lremprop(nil, v0243, v0111);
    env = stack[-7];
    v0053 = elt(env, 3); // slash!*
    v0243 = elt(env, 2); // opmtch
    v0111 = stack[-6];
    v0111 = Lputprop(nil, 3, v0053, v0243, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    goto v0092;

v0092:
    v0111 = stack[-4];
    if (v0111 == nil) goto v0075;
    v0243 = stack[-4];
    stack[-3] = v0243;
    v0111 = elt(env, 4); // quotient
    if (!consp(v0243)) goto v0075;
    v0243 = qcar(v0243);
    if (!(v0243 == v0111)) goto v0075;
    v0243 = elt(env, 3); // slash!*
    v0111 = stack[-4];
    v0111 = qcdr(v0111);
    v0111 = cons(v0243, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    fn = elt(env, 2); // opmtch
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    if (!(v0111 == nil)) goto v0017;
    v0243 = elt(env, 6); // minus
    v0111 = stack[-4];
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcar(v0111);
    v0111 = Lsmemq(nil, v0243, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    if (v0111 == nil) goto v0244;
    stack[-1] = elt(env, 3); // slash!*
    v0243 = elt(env, 6); // minus
    v0111 = stack[-4];
    v0111 = qcdr(v0111);
    v0111 = qcar(v0111);
    v0111 = list2(v0243, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    fn = elt(env, 8); // reval
    stack[0] = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    v0243 = elt(env, 6); // minus
    v0111 = stack[-4];
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcar(v0111);
    v0111 = list2(v0243, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    fn = elt(env, 8); // reval
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    v0111 = list3(stack[-1], stack[0], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    fn = elt(env, 2); // opmtch
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    goto v0017;

v0017:
    stack[-4] = v0111;
    v0111 = stack[-2];
    if (!(v0111 == nil)) goto v0066;
    v0111 = stack[-4];
    goto v0066;

v0066:
    stack[-2] = v0111;
    goto v0092;

v0244:
    v0111 = qvalue(elt(env, 5)); // nil
    goto v0017;

v0075:
    v0111 = stack[-2];
    if (v0111 == nil) goto v0027;
    v0111 = stack[-3];
    fn = elt(env, 9); // simp!*
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-7];
    goto v0137;

v0137:
    stack[-5] = v0111;
    v0053 = elt(env, 1); // slash
    v0243 = elt(env, 2); // opmtch
    v0111 = stack[-6];
    v0111 = Lputprop(nil, 3, v0053, v0243, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    { LispObject res = stack[-5]; popv(8); return onevalue(res); }

v0027:
    v0111 = stack[-5];
    goto v0137;
// error exit handlers
v0078:
    popv(8);
    return nil;
}



// Code for gbfdot

static LispObject CC_gbfdot(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0042, v0011;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gbfdot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0015;
// end of prologue
    v0042 = stack[-1];
    v0011 = qcar(v0042);
    v0042 = stack[0];
    v0042 = qcar(v0042);
    fn = elt(env, 1); // csl_timbf
    stack[-2] = (*qfn2(fn))(qenv(fn), v0011, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    v0042 = stack[-1];
    v0011 = qcdr(v0042);
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    fn = elt(env, 1); // csl_timbf
    v0042 = (*qfn2(fn))(qenv(fn), v0011, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-3];
    {
        LispObject v0094 = stack[-2];
        popv(4);
        fn = elt(env, 2); // plubf
        return (*qfn2(fn))(qenv(fn), v0094, v0042);
    }
// error exit handlers
v0093:
    popv(4);
    return nil;
}



// Code for !:dmpluslst

static LispObject CC_Tdmpluslst(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0072, v0071;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :dmpluslst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0071 = v0015;
// end of prologue
    v0072 = v0071;
    if (v0072 == nil) goto v0025;
    v0072 = v0071;
    v0072 = qcdr(v0072);
    if (v0072 == nil) goto v0225;
    v0072 = v0071;
    stack[0] = qcar(v0072);
    v0072 = v0071;
    v0072 = qcdr(v0072);
    v0072 = CC_Tdmpluslst(env, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    {
        LispObject v0012 = stack[0];
        popv(2);
        fn = elt(env, 1); // !:plus
        return (*qfn2(fn))(qenv(fn), v0012, v0072);
    }

v0225:
    v0072 = v0071;
    v0072 = qcar(v0072);
    { popv(2); return onevalue(v0072); }

v0025:
    v0072 = (LispObject)1; // 0
    { popv(2); return onevalue(v0072); }
// error exit handlers
v0011:
    popv(2);
    return nil;
}



// Code for mktails

static LispObject CC_mktails(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0082, v0234, v0199;
    LispObject fn;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mktails");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0015,v0007,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0234 = v0004;
    stack[-2] = v0007;
    v0199 = v0015;
// end of prologue
    stack[0] = nil;
    v0082 = v0199;
    if (v0082 == nil) goto v0043;
    v0082 = v0199;
    stack[-3] = v0082;
    v0082 = v0234;
    stack[-1] = v0082;
    goto v0072;

v0072:
    v0082 = stack[-3];
    if (v0082 == nil) goto v0020;
    v0082 = stack[-3];
    v0199 = qcar(v0082);
    v0234 = stack[-2];
    v0082 = stack[-1];
    fn = elt(env, 2); // mktails1
    v0082 = (*qfnn(fn))(qenv(fn), 3, v0199, v0234, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    v0234 = v0082;
    v0082 = v0234;
    v0082 = qcdr(v0082);
    stack[-1] = v0082;
    v0082 = v0234;
    v0234 = qcar(v0082);
    v0082 = stack[0];
    v0082 = Lappend(nil, v0234, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-4];
    stack[0] = v0082;
    v0082 = stack[-3];
    v0082 = qcdr(v0082);
    stack[-3] = v0082;
    goto v0072;

v0020:
    v0234 = stack[0];
    v0082 = stack[-1];
    popv(5);
    return cons(v0234, v0082);

v0043:
    v0082 = qvalue(elt(env, 1)); // nil
    popv(5);
    return cons(v0082, v0234);
// error exit handlers
v0049:
    popv(5);
    return nil;
}



// Code for putd

static LispObject CC_putd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0021, v0022, v0246;
    LispObject fn;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "putd");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for putd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0015,v0007,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
    stack[-1] = v0007;
    stack[-2] = v0015;
// end of prologue
    v0022 = stack[0];
    v0021 = elt(env, 1); // funarg
    if (!consp(v0022)) goto v0026;
    v0022 = qcar(v0022);
    if (!(v0022 == v0021)) goto v0026;
    v0022 = elt(env, 2); // lambda
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = qcdr(v0021);
    v0021 = cons(v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    stack[0] = v0021;
    goto v0026;

v0026:
    v0021 = stack[-2];
    if (!symbolp(v0021)) v0021 = nil;
    else { v0021 = qfastgets(v0021);
           if (v0021 != nil) { v0021 = elt(v0021, 1); // lose
#ifdef RECORD_GET
             if (v0021 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v0021 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v0021 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v0021 == SPID_NOPROP) v0021 = nil; else v0021 = lisp_true; }}
#endif
    if (v0021 == nil) goto v0074;
    v0021 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    v0021 = elt(env, 3); // "+++ "
    v0021 = Lprinc(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    v0021 = stack[-2];
    v0021 = Lprin(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    v0021 = elt(env, 4); // " not defined (LOSE flag)"
    v0021 = Lprintc(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    v0021 = qvalue(elt(env, 5)); // nil
    { popv(4); return onevalue(v0021); }

v0074:
    v0021 = qvalue(elt(env, 6)); // !*redefmsg
    if (v0021 == nil) goto v0091;
    v0021 = stack[-2];
    fn = elt(env, 15); // getd
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    if (v0021 == nil) goto v0091;
    v0021 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    v0021 = elt(env, 3); // "+++ "
    v0021 = Lprinc(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    v0021 = stack[-2];
    v0021 = Lprin(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    v0021 = elt(env, 7); // " redefined"
    v0021 = Lprintc(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    goto v0091;

v0091:
    v0022 = stack[-1];
    v0021 = elt(env, 8); // expr
    if (v0022 == v0021) goto v0244;
    v0022 = stack[-1];
    v0021 = elt(env, 9); // subr
    if (v0022 == v0021) goto v0233;
    v0022 = stack[-1];
    v0021 = elt(env, 10); // macro
    if (v0022 == v0021) goto v0236;
    v0021 = qvalue(elt(env, 5)); // nil
    goto v0086;

v0086:
    if (v0021 == nil) goto v0138;
    v0246 = elt(env, 11); // dm
    v0022 = stack[-2];
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = list2star(v0246, v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    fn = elt(env, 16); // eval
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0138:
    v0022 = stack[-1];
    v0021 = elt(env, 12); // fexpr
    if (v0022 == v0021) goto v0110;
    v0021 = qvalue(elt(env, 5)); // nil
    goto v0112;

v0112:
    if (v0021 == nil) goto v0120;
    v0246 = elt(env, 13); // df
    v0022 = stack[-2];
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = list2star(v0246, v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-3];
    fn = elt(env, 16); // eval
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0120:
    v0022 = elt(env, 14); // "Bad type ~S in putd"
    v0021 = stack[-1];
    fn = elt(env, 17); // error
    v0021 = (*qfn2(fn))(qenv(fn), v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0110:
    v0022 = stack[0];
    v0021 = elt(env, 2); // lambda
    v0021 = Leqcar(nil, v0022, v0021);
    env = stack[-3];
    goto v0112;

v0236:
    v0022 = stack[0];
    v0021 = elt(env, 2); // lambda
    v0021 = Leqcar(nil, v0022, v0021);
    env = stack[-3];
    goto v0086;

v0233:
    v0022 = stack[-2];
    v0021 = stack[0];
    v0021 = Lsymbol_set_definition(nil, v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0244:
    v0022 = stack[-2];
    v0021 = stack[0];
    v0021 = Lsymbol_set_definition(nil, v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }
// error exit handlers
v0127:
    popv(4);
    return nil;
}



// Code for setk

static LispObject CC_setk(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0036, v0086, v0088;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    v0086 = v0015;
// end of prologue
    v0036 = v0086;
    if (!consp(v0036)) goto v0068;
    v0036 = v0086;
    v0088 = qcar(v0036);
    v0036 = elt(env, 1); // evalargfn
    v0036 = get(v0088, v0036);
    env = stack[-2];
    v0088 = v0036;
    v0036 = v0088;
    if (v0036 == nil) goto v0048;
    v0036 = v0086;
    stack[-1] = qcar(v0036);
    v0036 = v0088;
    v0086 = qcdr(v0086);
    v0036 = Lapply1(nil, v0036, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-2];
    v0086 = cons(stack[-1], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-2];
    v0036 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(qenv(fn), v0086, v0036);
    }

v0048:
    v0036 = v0086;
    v0036 = qcar(v0036);
    if (!symbolp(v0036)) v0088 = nil;
    else { v0088 = qfastgets(v0036);
           if (v0088 != nil) { v0088 = elt(v0088, 2); // rtype
#ifdef RECORD_GET
             if (v0088 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0088 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0088 == SPID_NOPROP) v0088 = nil; }}
#endif
    v0036 = elt(env, 2); // matrix
    if (v0088 == v0036) goto v0090;
    v0036 = v0086;
    stack[-1] = qcar(v0036);
    v0036 = v0086;
    v0036 = qcdr(v0036);
    fn = elt(env, 4); // revlis
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-2];
    v0086 = cons(stack[-1], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-2];
    v0036 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(qenv(fn), v0086, v0036);
    }

v0090:
    v0036 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(qenv(fn), v0086, v0036);
    }

v0068:
    v0036 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(qenv(fn), v0086, v0036);
    }
// error exit handlers
v0140:
    popv(3);
    return nil;
}



// Code for red_totalred

static LispObject CC_red_totalred(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0076, v0100;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_totalred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0076 = v0007;
    v0100 = v0015;
// end of prologue
    stack[0] = v0100;
    fn = elt(env, 1); // red_topred
    v0076 = (*qfn2(fn))(qenv(fn), v0100, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    {
        LispObject v0104 = stack[0];
        popv(2);
        fn = elt(env, 2); // red_tailred
        return (*qfn2(fn))(qenv(fn), v0104, v0076);
    }
// error exit handlers
v0101:
    popv(2);
    return nil;
}



// Code for comfac

static LispObject CC_comfac(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0248, v0108;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comfac");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0015;
// end of prologue
    stack[-3] = nil;
    v0248 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0248)) v0248 = nil;
    else { v0248 = qfastgets(v0248);
           if (v0248 != nil) { v0248 = elt(v0248, 3); // field
#ifdef RECORD_GET
             if (v0248 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0248 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0248 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0248 == SPID_NOPROP) v0248 = nil; else v0248 = lisp_true; }}
#endif
    if (v0248 == nil) goto v0095;
    v0248 = stack[-2];
    fn = elt(env, 4); // lnc
    v0108 = (*qfn1(fn))(qenv(fn), v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    stack[-3] = v0108;
    v0248 = (LispObject)17; // 1
    v0248 = Lneq(nil, v0108, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    goto v0056;

v0056:
    if (v0248 == nil) goto v0225;
    v0248 = stack[-3];
    fn = elt(env, 5); // !:recip
    v0108 = (*qfn1(fn))(qenv(fn), v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    v0248 = stack[-2];
    fn = elt(env, 6); // multd
    v0248 = (*qfn2(fn))(qenv(fn), v0108, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    stack[-2] = v0248;
    goto v0225;

v0225:
    v0248 = stack[-2];
    v0248 = qcdr(v0248);
    if (v0248 == nil) goto v0074;
    v0248 = stack[-2];
    v0248 = qcar(v0248);
    v0248 = qcdr(v0248);
    stack[-3] = v0248;
    v0248 = stack[-2];
    v0248 = qcar(v0248);
    v0248 = qcar(v0248);
    v0248 = qcar(v0248);
    stack[-1] = v0248;
    goto v0096;

v0096:
    v0248 = stack[-2];
    v0248 = qcdr(v0248);
    stack[-2] = v0248;
    v0108 = stack[-2];
    v0248 = stack[-1];
    fn = elt(env, 7); // degr
    v0108 = (*qfn2(fn))(qenv(fn), v0108, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    v0248 = (LispObject)1; // 0
    if (v0108 == v0248) goto v0049;
    v0248 = stack[-2];
    v0248 = qcdr(v0248);
    if (v0248 == nil) goto v0245;
    v0248 = stack[-2];
    v0248 = qcar(v0248);
    v0108 = qcdr(v0248);
    v0248 = stack[-3];
    fn = elt(env, 8); // gcdf
    v0248 = (*qfn2(fn))(qenv(fn), v0108, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    stack[-3] = v0248;
    goto v0096;

v0245:
    v0248 = stack[-2];
    v0248 = qcar(v0248);
    stack[0] = qcar(v0248);
    v0108 = stack[-3];
    v0248 = stack[-2];
    v0248 = qcar(v0248);
    v0248 = qcdr(v0248);
    fn = elt(env, 8); // gcdf
    v0248 = (*qfn2(fn))(qenv(fn), v0108, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    {
        LispObject v0119 = stack[0];
        popv(5);
        return cons(v0119, v0248);
    }

v0049:
    stack[0] = qvalue(elt(env, 2)); // nil
    v0248 = stack[-2];
    if (!consp(v0248)) goto v0202;
    v0248 = stack[-2];
    v0248 = qcar(v0248);
    v0248 = (consp(v0248) ? nil : lisp_true);
    goto v0205;

v0205:
    if (v0248 == nil) goto v0116;
    v0248 = qvalue(elt(env, 3)); // t
    goto v0226;

v0226:
    if (v0248 == nil) goto v0137;
    v0108 = stack[-3];
    v0248 = stack[-2];
    fn = elt(env, 8); // gcdf
    v0248 = (*qfn2(fn))(qenv(fn), v0108, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    goto v0228;

v0228:
    {
        LispObject v0120 = stack[0];
        popv(5);
        return cons(v0120, v0248);
    }

v0137:
    v0248 = (LispObject)17; // 1
    goto v0228;

v0116:
    v0248 = stack[-1];
    fn = elt(env, 9); // noncomp
    v0248 = (*qfn1(fn))(qenv(fn), v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    if (v0248 == nil) goto v0204;
    v0248 = stack[-2];
    v0248 = qcar(v0248);
    v0248 = qcar(v0248);
    v0248 = qcar(v0248);
    fn = elt(env, 9); // noncomp
    v0248 = (*qfn1(fn))(qenv(fn), v0248);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    goto v0085;

v0085:
    v0248 = (v0248 == nil ? lisp_true : nil);
    goto v0226;

v0204:
    v0248 = qvalue(elt(env, 2)); // nil
    goto v0085;

v0202:
    v0248 = qvalue(elt(env, 3)); // t
    goto v0205;

v0074:
    v0248 = stack[-2];
    v0248 = qcar(v0248);
    { popv(5); return onevalue(v0248); }

v0095:
    v0248 = qvalue(elt(env, 2)); // nil
    goto v0056;
// error exit handlers
v0249:
    popv(5);
    return nil;
}



// Code for bc_zero!?

static LispObject CC_bc_zeroW(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_zero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0026 = v0015;
// end of prologue
    v0026 = qcar(v0026);
    v0026 = (v0026 == nil ? lisp_true : nil);
    return onevalue(v0026);
}



// Code for diff!-k!-times!-mod!-p

static LispObject CC_diffKkKtimesKmodKp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0127, v0251, v0252;
    LispObject fn;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-k-times-mod-p");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diff-k-times-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0015,v0007,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0004;
    stack[-2] = v0007;
    stack[-3] = v0015;
// end of prologue
    v0127 = stack[-3];
    if (!consp(v0127)) goto v0097;
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0127 = (consp(v0127) ? nil : lisp_true);
    goto v0102;

v0102:
    if (v0127 == nil) goto v0104;
    v0127 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0127); }

v0104:
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0127 = qcar(v0127);
    v0251 = qcar(v0127);
    v0127 = stack[-1];
    if (equal(v0251, v0127)) goto v0075;
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0252 = qcdr(v0127);
    v0251 = stack[-2];
    v0127 = stack[-1];
    stack[0] = CC_diffKkKtimesKmodKp(env, 3, v0252, v0251, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-5];
    v0127 = stack[-3];
    v0252 = qcdr(v0127);
    v0251 = stack[-2];
    v0127 = stack[-1];
    v0127 = CC_diffKkKtimesKmodKp(env, 3, v0252, v0251, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0251 = stack[0];
    v0252 = v0251;
    if (v0252 == nil) { popv(6); return onevalue(v0127); }
    v0252 = stack[-3];
    v0252 = qcar(v0252);
    v0252 = qcar(v0252);
    popv(6);
    return acons(v0252, v0251, v0127);

v0075:
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0127 = qcar(v0127);
    v0251 = qcdr(v0127);
    v0127 = stack[-2];
    v0127 = (LispObject)lessp2(v0251, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0127 = v0127 ? lisp_true : nil;
    env = stack[-5];
    if (v0127 == nil) goto v0005;
    v0127 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0127); }

v0005:
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0127 = qcar(v0127);
    v0251 = qcdr(v0127);
    v0127 = stack[-2];
    if (equal(v0251, v0127)) goto v0038;
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0127 = qcar(v0127);
    v0251 = qcdr(v0127);
    v0127 = stack[-2];
    fn = elt(env, 3); // binomial!-coefft!-mod!-p
    v0251 = (*qfn2(fn))(qenv(fn), v0251, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-5];
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0127 = qcdr(v0127);
    fn = elt(env, 4); // times!-mod!-p
    stack[0] = (*qfn2(fn))(qenv(fn), v0251, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-5];
    v0127 = stack[-3];
    v0252 = qcdr(v0127);
    v0251 = stack[-2];
    v0127 = stack[-1];
    v0127 = CC_diffKkKtimesKmodKp(env, 3, v0252, v0251, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v0127;
    v0127 = stack[-4];
    if (v0127 == nil) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0127 = qcar(v0127);
    v0251 = qcdr(v0127);
    v0127 = stack[-2];
    v0127 = difference2(v0251, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-5];
    fn = elt(env, 5); // mksp
    v0252 = (*qfn2(fn))(qenv(fn), stack[-1], v0127);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0251 = stack[-4];
    v0127 = stack[0];
    popv(6);
    return acons(v0252, v0251, v0127);

v0038:
    v0127 = stack[-3];
    v0127 = qcar(v0127);
    v0127 = qcdr(v0127);
    { popv(6); return onevalue(v0127); }

v0097:
    v0127 = qvalue(elt(env, 1)); // t
    goto v0102;
// error exit handlers
v0253:
    popv(6);
    return nil;
}



// Code for bvarml

static LispObject CC_bvarml(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0093, v0094;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bvarml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0015;
// end of prologue
    v0093 = elt(env, 1); // "<bvar>"
    fn = elt(env, 5); // printout
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0093 = qvalue(elt(env, 2)); // t
    fn = elt(env, 6); // indent!*
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0093 = stack[0];
    v0093 = qcar(v0093);
    fn = elt(env, 7); // expression
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0094 = qcar(v0093);
    v0093 = (LispObject)17; // 1
    if (v0094 == v0093) goto v0056;
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0093 = qcar(v0093);
    v0093 = ncons(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    fn = elt(env, 8); // degreeml
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    goto v0056;

v0056:
    v0093 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 6); // indent!*
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0093 = elt(env, 4); // "</bvar>"
    fn = elt(env, 5); // printout
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    v0093 = nil;
    { popv(2); return onevalue(v0093); }
// error exit handlers
v0075:
    popv(2);
    return nil;
}



// Code for dipev2f

static LispObject CC_dipev2f(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0091, v0254;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipev2f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0015;
// end of prologue

v0026:
    v0091 = stack[-1];
    if (v0091 == nil) goto v0225;
    v0091 = stack[-1];
    v0254 = qcar(v0091);
    v0091 = (LispObject)1; // 0
    if (v0254 == v0091) goto v0056;
    v0091 = stack[0];
    v0254 = qcar(v0091);
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    fn = elt(env, 1); // to
    v0254 = (*qfn2(fn))(qenv(fn), v0254, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    v0091 = (LispObject)17; // 1
    v0091 = cons(v0254, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    stack[-2] = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    v0091 = stack[-1];
    v0254 = qcdr(v0091);
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    v0091 = CC_dipev2f(env, v0254, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    {
        LispObject v0234 = stack[-2];
        popv(4);
        fn = elt(env, 2); // multf
        return (*qfn2(fn))(qenv(fn), v0234, v0091);
    }

v0056:
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    stack[0] = v0091;
    goto v0026;

v0225:
    v0091 = (LispObject)17; // 1
    { popv(4); return onevalue(v0091); }
// error exit handlers
v0082:
    popv(4);
    return nil;
}



// Code for freeoffl

static LispObject CC_freeoffl(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0103, v0075;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeoffl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0015;
// end of prologue

v0232:
    v0103 = stack[0];
    if (v0103 == nil) goto v0026;
    v0075 = stack[-1];
    v0103 = stack[0];
    v0103 = qcar(v0103);
    fn = elt(env, 3); // freeoff
    v0103 = (*qfn2(fn))(qenv(fn), v0075, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    if (v0103 == nil) goto v0057;
    v0075 = stack[-1];
    v0103 = stack[0];
    v0103 = qcdr(v0103);
    stack[-1] = v0075;
    stack[0] = v0103;
    goto v0232;

v0057:
    v0103 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0103); }

v0026:
    v0103 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0103); }
// error exit handlers
v0074:
    popv(3);
    return nil;
}



// Code for red_topredbe

static LispObject CC_red_topredbe(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0228, v0141;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_topredbe");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0007;
    stack[-2] = v0015;
// end of prologue
    v0228 = stack[-1];
    fn = elt(env, 4); // bas_dpoly
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    if (v0228 == nil) goto v0102;
    v0228 = stack[-2];
    v0228 = (v0228 == nil ? lisp_true : nil);
    goto v0225;

v0225:
    if (!(v0228 == nil)) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    fn = elt(env, 5); // cali_trace
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0228 = (LispObject)1265; // 79
    v0228 = (LispObject)greaterp2(v0141, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    v0228 = v0228 ? lisp_true : nil;
    env = stack[-4];
    if (v0228 == nil) goto v0041;
    v0228 = elt(env, 2); // " reduce "
    v0228 = Lprinc(nil, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0228 = stack[-1];
    fn = elt(env, 4); // bas_dpoly
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    fn = elt(env, 6); // dp_print
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0041;

v0041:
    v0228 = stack[-1];
    fn = elt(env, 4); // bas_dpoly
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0141 = v0228;
    if (v0228 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    stack[-3] = stack[-2];
    v0228 = v0141;
    fn = elt(env, 7); // dp_lmon
    stack[0] = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0228 = stack[-1];
    fn = elt(env, 8); // bas_dpecart
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    fn = elt(env, 9); // red_divtestbe
    v0141 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0228 = v0141;
    if (v0141 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0141 = stack[-1];
    fn = elt(env, 10); // red_subst
    v0228 = (*qfn2(fn))(qenv(fn), v0141, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[-1] = v0228;
    goto v0041;

v0102:
    v0228 = qvalue(elt(env, 1)); // t
    goto v0225;
// error exit handlers
v0201:
    popv(5);
    return nil;
}



// Code for ilog2

static LispObject CC_ilog2(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0062, v0063;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ilog2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0015;
// end of prologue
    v0063 = stack[-2];
    v0062 = (LispObject)1; // 0
    v0062 = (LispObject)lesseq2(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    v0062 = v0062 ? lisp_true : nil;
    env = stack[-4];
    if (v0062 == nil) goto v0225;
    v0063 = stack[-2];
    v0062 = elt(env, 0); // ilog2
    fn = elt(env, 2); // terrlst
    v0062 = (*qfn2(fn))(qenv(fn), v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    goto v0225;

v0225:
    v0062 = (LispObject)33; // 2
    stack[0] = v0062;
    v0062 = stack[0];
    v0062 = ncons(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[-1] = v0062;
    goto v0092;

v0092:
    v0063 = stack[-2];
    v0062 = stack[0];
    v0062 = (LispObject)greaterp2(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    v0062 = v0062 ? lisp_true : nil;
    env = stack[-4];
    if (v0062 == nil) goto v0012;
    v0063 = stack[0];
    v0062 = stack[-1];
    v0062 = cons(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[-1] = v0062;
    v0063 = stack[0];
    v0062 = stack[0];
    v0062 = times2(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[0] = v0062;
    goto v0092;

v0012:
    v0062 = (LispObject)1; // 0
    stack[-3] = v0062;
    goto v0244;

v0244:
    v0062 = stack[-1];
    v0063 = qcar(v0062);
    stack[0] = v0063;
    v0062 = (LispObject)33; // 2
    if (v0063 == v0062) goto v0255;
    v0062 = stack[-1];
    v0062 = qcdr(v0062);
    stack[-1] = v0062;
    v0063 = stack[-2];
    v0062 = stack[0];
    v0062 = (LispObject)geq2(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    v0062 = v0062 ? lisp_true : nil;
    env = stack[-4];
    if (v0062 == nil) goto v0203;
    v0063 = stack[-2];
    v0062 = stack[0];
    v0062 = quot2(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[-2] = v0062;
    v0062 = stack[-3];
    v0062 = add1(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[-3] = v0062;
    goto v0203;

v0203:
    v0063 = stack[-3];
    v0062 = (LispObject)33; // 2
    v0062 = times2(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[-3] = v0062;
    goto v0244;

v0255:
    v0063 = stack[-2];
    v0062 = (LispObject)33; // 2
    v0062 = (LispObject)geq2(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    v0062 = v0062 ? lisp_true : nil;
    env = stack[-4];
    if (v0062 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0062 = stack[-3];
    v0062 = add1(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    stack[-3] = v0062;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }
// error exit handlers
v0245:
    popv(5);
    return nil;
}



// Code for bndtst

static LispObject CC_bndtst(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bndtst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0055 = v0015;
// end of prologue
    fn = elt(env, 2); // abs!:
    v0056 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[0];
    v0055 = qvalue(elt(env, 1)); // tentothetenth!*!*
    {
        popv(1);
        fn = elt(env, 3); // greaterp!:
        return (*qfn2(fn))(qenv(fn), v0056, v0055);
    }
// error exit handlers
v0057:
    popv(1);
    return nil;
}



// Code for rndifference!:

static LispObject CC_rndifferenceT(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0067, v0006;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rndifference:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0015;
// end of prologue
    v0067 = stack[-1];
    v0067 = qcdr(v0067);
    v0006 = qcar(v0067);
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = qcdr(v0067);
    stack[-2] = times2(v0006, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0067 = stack[-1];
    v0067 = qcdr(v0067);
    v0006 = qcdr(v0067);
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    v0067 = times2(v0006, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    stack[-2] = difference2(stack[-2], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    v0067 = stack[-1];
    v0067 = qcdr(v0067);
    v0006 = qcdr(v0067);
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = qcdr(v0067);
    v0067 = times2(v0006, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    {
        LispObject v0018 = stack[-2];
        popv(4);
        fn = elt(env, 1); // mkrn
        return (*qfn2(fn))(qenv(fn), v0018, v0067);
    }
// error exit handlers
v0017:
    popv(4);
    return nil;
}



// Code for mri_pasf2mri

static LispObject CC_mri_pasf2mri(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0014, v0043;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_pasf2mri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0014 = v0007;
    v0043 = v0015;
// end of prologue
    stack[-1] = v0043;
    stack[0] = elt(env, 1); // mri_pasf2mriat
    v0014 = ncons(v0014);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    {
        LispObject v0080 = stack[-1];
        LispObject v0101 = stack[0];
        popv(3);
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(qenv(fn), 3, v0080, v0101, v0014);
    }
// error exit handlers
v0100:
    popv(3);
    return nil;
}



// Code for pasf_sacat

static LispObject CC_pasf_sacat(LispObject env, int nargs, ...)
{
    LispObject v0026, v0096, v0231;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sacat");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_sacat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0026 = v0004;
    v0096 = v0007;
    v0231 = v0015;
// end of prologue
    v0026 = qvalue(elt(env, 1)); // nil
    return onevalue(v0026);
}



// Code for rl_updcache

static LispObject CC_rl_updcache(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0255, v0065;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rl_updcache");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_updcache");
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
    v0255 = qvalue(elt(env, 1)); // rl_bbl!*
    stack[0] = v0255;
    goto v0025;

v0025:
    v0255 = stack[0];
    if (v0255 == nil) goto v0011;
    v0255 = stack[0];
    v0255 = qcar(v0255);
    v0065 = v0255;
    v0255 = qvalue(elt(env, 2)); // nil
    v0255 = Lset(nil, v0065, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    stack[0] = v0255;
    goto v0025;

v0011:
    v0255 = qvalue(elt(env, 3)); // rl_cid!*
    v0065 = qcar(v0255);
    v0255 = elt(env, 4); // rl_params
    v0255 = get(v0065, v0255);
    env = stack[-1];
    stack[0] = v0255;
    goto v0071;

v0071:
    v0255 = stack[0];
    if (v0255 == nil) goto v0072;
    v0255 = stack[0];
    v0255 = qcar(v0255);
    v0065 = v0255;
    v0065 = qcar(v0065);
    v0255 = qcdr(v0255);
    v0255 = Lset(nil, v0065, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    stack[0] = v0255;
    goto v0071;

v0072:
    v0255 = qvalue(elt(env, 5)); // rl_servl!*
    stack[0] = v0255;
    goto v0091;

v0091:
    v0255 = stack[0];
    if (v0255 == nil) goto v0143;
    v0255 = stack[0];
    v0255 = qcar(v0255);
    v0065 = v0255;
    v0255 = qvalue(elt(env, 2)); // nil
    v0255 = Lset(nil, v0065, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    stack[0] = v0255;
    goto v0091;

v0143:
    v0255 = qvalue(elt(env, 3)); // rl_cid!*
    v0065 = qcar(v0255);
    v0255 = elt(env, 6); // rl_services
    v0255 = get(v0065, v0255);
    env = stack[-1];
    stack[0] = v0255;
    goto v0052;

v0052:
    v0255 = stack[0];
    if (v0255 == nil) goto v0088;
    v0255 = stack[0];
    v0255 = qcar(v0255);
    v0065 = v0255;
    v0065 = qcar(v0065);
    v0255 = qcdr(v0255);
    v0255 = Lset(nil, v0065, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    stack[0] = v0255;
    goto v0052;

v0088:
    v0255 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0255); }
// error exit handlers
v0066:
    popv(2);
    return nil;
}



// Code for sfto_tsqsumf

static LispObject CC_sfto_tsqsumf(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0090;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_tsqsumf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0015;
// end of prologue

v0025:
    v0090 = stack[0];
    if (!consp(v0090)) goto v0055;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = (consp(v0090) ? nil : lisp_true);
    goto v0097;

v0097:
    if (v0090 == nil) goto v0093;
    v0090 = stack[0];
    if (v0090 == nil) goto v0104;
    v0090 = stack[0];
    fn = elt(env, 5); // minusf
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0254;
    env = stack[-1];
    if (v0090 == nil) goto v0095;
    v0090 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0090); }

v0095:
    v0090 = elt(env, 3); // stsq
    { popv(2); return onevalue(v0090); }

v0104:
    v0090 = elt(env, 2); // tsq
    { popv(2); return onevalue(v0090); }

v0093:
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    v0090 = Levenp(nil, v0090);
    env = stack[-1];
    if (v0090 == nil) goto v0039;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    v0090 = CC_sfto_tsqsumf(env, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0254;
    env = stack[-1];
    if (v0090 == nil) goto v0016;
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    stack[0] = v0090;
    goto v0025;

v0016:
    v0090 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0090); }

v0039:
    v0090 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0090); }

v0055:
    v0090 = qvalue(elt(env, 1)); // t
    goto v0097;
// error exit handlers
v0254:
    popv(2);
    return nil;
}



// Code for om2ir

static LispObject CC_om2ir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0254, v0109;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2ir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for om2ir");
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
    v0254 = qvalue(elt(env, 1)); // nil
    stack[0] = v0254;
    v0254 = elt(env, 2); // (safe_atts char ch atts count temp space temp2)
    fn = elt(env, 12); // fluid
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    v0254 = (LispObject)513; // 32
    v0254 = ncons(v0254);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    fn = elt(env, 13); // list2string
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    v0254 = Lintern(nil, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0254; // space
    v0254 = (LispObject)1; // 0
    qvalue(elt(env, 4)) = v0254; // count
    v0254 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0254; // ch
    v0254 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 6)) = v0254; // temp2
    fn = elt(env, 14); // lex
    v0254 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    v0109 = qvalue(elt(env, 7)); // char
    v0254 = elt(env, 8); // (o m o b j)
    if (equal(v0109, v0254)) goto v0077;
    v0109 = elt(env, 9); // "<omobj>"
    v0254 = (LispObject)33; // 2
    fn = elt(env, 15); // errorml
    v0254 = (*qfn2(fn))(qenv(fn), v0109, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    goto v0043;

v0043:
    fn = elt(env, 14); // lex
    v0254 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    v0109 = qvalue(elt(env, 7)); // char
    v0254 = elt(env, 10); // (!/ o m o b j)
    if (equal(v0109, v0254)) goto v0149;
    v0109 = elt(env, 11); // "</omobj>"
    v0254 = (LispObject)305; // 19
    fn = elt(env, 15); // errorml
    v0254 = (*qfn2(fn))(qenv(fn), v0109, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0149:
    v0254 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0077:
    fn = elt(env, 14); // lex
    v0254 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    fn = elt(env, 16); // omobj
    v0254 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    stack[0] = v0254;
    goto v0043;
// error exit handlers
v0070:
    popv(2);
    return nil;
}



// Code for rationalizesq

static LispObject CC_rationalizesq(LispObject env,
                         LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0190, v0139;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rationalizesq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0015;
// end of prologue
    stack[-4] = qvalue(elt(env, 1)); // !*structure
    qvalue(elt(env, 1)) = nil; // !*structure
    stack[-2] = qvalue(elt(env, 2)); // !*sub2
    qvalue(elt(env, 2)) = nil; // !*sub2
    v0139 = qvalue(elt(env, 3)); // dmode!*
    v0190 = elt(env, 4); // rationalizefn
    v0190 = get(v0139, v0190);
    env = stack[-5];
    stack[0] = v0190;
    if (v0190 == nil) goto v0042;
    v0139 = stack[0];
    v0190 = stack[-3];
    v0190 = Lapply1(nil, v0139, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    stack[-3] = v0190;
    goto v0042;

v0042:
    v0139 = elt(env, 5); // (i 2 (nil . t) -1 nil)
    v0190 = qvalue(elt(env, 6)); // powlis!*
    v0190 = cons(v0139, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0190; // powlis!*
    v0190 = stack[-3];
    fn = elt(env, 11); // subs2q
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    stack[-1] = v0190;
    v0190 = qvalue(elt(env, 6)); // powlis!*
    v0190 = qcdr(v0190);
    qvalue(elt(env, 6)) = v0190; // powlis!*
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    if (!consp(v0190)) goto v0122;
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    v0190 = qcar(v0190);
    v0190 = (consp(v0190) ? nil : lisp_true);
    goto v0041;

v0041:
    if (v0190 == nil) goto v0020;
    v0190 = stack[-1];
    goto v0231;

v0231:
    qvalue(elt(env, 2)) = stack[-2]; // !*sub2
    qvalue(elt(env, 1)) = stack[-4]; // !*structure
    { popv(6); return onevalue(v0190); }

v0020:
    v0190 = stack[-1];
    v0190 = qcdr(v0190);
    fn = elt(env, 12); // rationalizef
    v0139 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    stack[0] = v0139;
    v0190 = (LispObject)17; // 1
    if (v0139 == v0190) goto v0113;
    v0190 = stack[-1];
    v0139 = qcar(v0190);
    v0190 = stack[0];
    fn = elt(env, 13); // multf
    stack[-3] = (*qfn2(fn))(qenv(fn), v0139, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    v0190 = stack[-1];
    v0139 = qcdr(v0190);
    v0190 = stack[0];
    fn = elt(env, 13); // multf
    v0190 = (*qfn2(fn))(qenv(fn), v0139, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    v0190 = cons(stack[-3], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    stack[-1] = v0190;
    v0190 = qvalue(elt(env, 8)); // !*algint
    if (v0190 == nil) goto v0115;
    v0190 = qvalue(elt(env, 10)); // nil
    goto v0088;

v0088:
    if (v0190 == nil) goto v0150;
    v0190 = stack[-1];
    fn = elt(env, 14); // gcdchk
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    stack[-1] = v0190;
    goto v0150;

v0150:
    v0190 = stack[-1];
    fn = elt(env, 11); // subs2q
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-5];
    goto v0231;

v0115:
    v0190 = qvalue(elt(env, 9)); // !*rationalize
    v0190 = (v0190 == nil ? lisp_true : nil);
    goto v0088;

v0113:
    v0190 = stack[-3];
    goto v0231;

v0122:
    v0190 = qvalue(elt(env, 7)); // t
    goto v0041;
// error exit handlers
v0191:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-2]; // !*sub2
    qvalue(elt(env, 1)) = stack[-4]; // !*structure
    popv(6);
    return nil;
}



// Code for mkmatrix

static LispObject CC_mkmatrix(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0257, v0135;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkmatrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-8] = v0007;
    stack[-9] = v0015;
// end of prologue
    stack[-10] = elt(env, 1); // mat
    v0257 = (LispObject)17; // 1
    stack[-7] = v0257;
    v0135 = stack[-9];
    v0257 = stack[-7];
    v0257 = difference2(v0135, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lminusp(nil, v0257);
    env = stack[-11];
    if (v0257 == nil) goto v0076;
    v0257 = qvalue(elt(env, 2)); // nil
    goto v0231;

v0231:
    {
        LispObject v0258 = stack[-10];
        popv(12);
        return cons(v0258, v0257);
    }

v0076:
    v0257 = (LispObject)17; // 1
    stack[-3] = v0257;
    v0135 = stack[-8];
    v0257 = stack[-3];
    v0257 = difference2(v0135, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lminusp(nil, v0257);
    env = stack[-11];
    if (v0257 == nil) goto v0074;
    v0257 = qvalue(elt(env, 2)); // nil
    goto v0103;

v0103:
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    stack[-5] = v0257;
    stack[-6] = v0257;
    goto v0014;

v0014:
    v0257 = stack[-7];
    v0257 = add1(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    stack[-7] = v0257;
    v0135 = stack[-9];
    v0257 = stack[-7];
    v0257 = difference2(v0135, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lminusp(nil, v0257);
    env = stack[-11];
    if (v0257 == nil) goto v0115;
    v0257 = stack[-6];
    goto v0231;

v0115:
    stack[-4] = stack[-5];
    v0257 = (LispObject)17; // 1
    stack[-3] = v0257;
    v0135 = stack[-8];
    v0257 = stack[-3];
    v0257 = difference2(v0135, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lminusp(nil, v0257);
    env = stack[-11];
    if (v0257 == nil) goto v0190;
    v0257 = qvalue(elt(env, 2)); // nil
    goto v0237;

v0237:
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lrplacd(nil, stack[-4], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = stack[-5];
    v0257 = qcdr(v0257);
    stack[-5] = v0257;
    goto v0014;

v0190:
    v0257 = (LispObject)1; // 0
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    stack[-1] = v0257;
    stack[-2] = v0257;
    goto v0113;

v0113:
    v0257 = stack[-3];
    v0257 = add1(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    stack[-3] = v0257;
    v0135 = stack[-8];
    v0257 = stack[-3];
    v0257 = difference2(v0135, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lminusp(nil, v0257);
    env = stack[-11];
    if (v0257 == nil) goto v0111;
    v0257 = stack[-2];
    goto v0237;

v0111:
    stack[0] = stack[-1];
    v0257 = (LispObject)1; // 0
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lrplacd(nil, stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = stack[-1];
    v0257 = qcdr(v0257);
    stack[-1] = v0257;
    goto v0113;

v0074:
    v0257 = (LispObject)1; // 0
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    stack[-1] = v0257;
    stack[-2] = v0257;
    goto v0075;

v0075:
    v0257 = stack[-3];
    v0257 = add1(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    stack[-3] = v0257;
    v0135 = stack[-8];
    v0257 = stack[-3];
    v0257 = difference2(v0135, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lminusp(nil, v0257);
    env = stack[-11];
    if (v0257 == nil) goto v0229;
    v0257 = stack[-2];
    goto v0103;

v0229:
    stack[0] = stack[-1];
    v0257 = (LispObject)1; // 0
    v0257 = ncons(v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = Lrplacd(nil, stack[0], v0257);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-11];
    v0257 = stack[-1];
    v0257 = qcdr(v0257);
    stack[-1] = v0257;
    goto v0075;
// error exit handlers
v0120:
    popv(12);
    return nil;
}



// Code for formc!*

static LispObject CC_formcH(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0100, v0080, v0101, v0104;
    LispObject fn;
    LispObject v0004, v0007, v0015;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc*");
    va_start(aa, nargs);
    v0015 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formc*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0015,v0007,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0080 = v0004;
    v0101 = v0007;
    v0104 = v0015;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // !*!*a2sfn
    qvalue(elt(env, 1)) = nil; // !*!*a2sfn
    v0100 = elt(env, 2); // revalx
    qvalue(elt(env, 1)) = v0100; // !*!*a2sfn
    v0100 = v0104;
    fn = elt(env, 3); // formc
    v0100 = (*qfnn(fn))(qenv(fn), 3, v0100, v0101, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*!*a2sfn
    { popv(2); return onevalue(v0100); }
// error exit handlers
v0008:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*!*a2sfn
    popv(2);
    return nil;
}



// Code for evaluate1

static LispObject CC_evaluate1(LispObject env,
                         LispObject v0015, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0112, v0058, v0050, v0138;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0058 = v0007;
    v0050 = v0015;
// end of prologue
    v0112 = v0050;
    if (is_number(v0112)) goto v0026;
    v0112 = v0050;
    if (v0112 == nil) goto v0026;
    v0112 = v0050;
    v0112 = Lconsp(nil, v0112);
    env = stack[0];
    if (v0112 == nil) goto v0019;
    v0112 = v0050;
    v0112 = qcar(v0112);
    if (!symbolp(v0112)) v0112 = nil;
    else { v0112 = qfastgets(v0112);
           if (v0112 != nil) { v0112 = elt(v0112, 8); // dname
#ifdef RECORD_GET
             if (v0112 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0112 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0112 == SPID_NOPROP) v0112 = nil; }}
#endif
    if (!(v0112 == nil)) { popv(1); return onevalue(v0050); }

v0019:
    v0138 = v0050;
    v0112 = v0058;
    v0112 = Lassoc(nil, v0138, v0112);
    v0138 = v0112;
    v0112 = v0138;
    if (v0112 == nil) goto v0075;
    v0112 = v0138;
    v0112 = qcdr(v0112);
    { popv(1); return onevalue(v0112); }

v0075:
    v0112 = v0050;
    if (!consp(v0112)) goto v0038;
    v0112 = v0050;
    v0112 = qcar(v0112);
    v0050 = qcdr(v0050);
    {
        popv(1);
        fn = elt(env, 11); // evaluate2
        return (*qfnn(fn))(qenv(fn), 3, v0112, v0050, v0058);
    }

v0038:
    v0058 = v0050;
    v0112 = elt(env, 1); // i
    if (v0058 == v0112) goto v0020;
    v0058 = v0050;
    v0112 = elt(env, 6); // e
    if (v0058 == v0112) goto v0032;
    v0058 = v0050;
    v0112 = elt(env, 8); // pi
    v0112 = (v0058 == v0112 ? lisp_true : nil);
    goto v0201;

v0201:
    if (v0112 == nil) goto v0236;
    v0112 = v0050;
    fn = elt(env, 12); // simp
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[0];
    v0112 = qcar(v0112);
    {
        popv(1);
        fn = elt(env, 13); // force!-to!-dm
        return (*qfn1(fn))(qenv(fn), v0112);
    }

v0236:
    v0112 = qvalue(elt(env, 7)); // t
    qvalue(elt(env, 9)) = v0112; // !*evaluateerror
    v0058 = v0050;
    v0112 = elt(env, 10); // "number"
    {
        popv(1);
        fn = elt(env, 14); // typerr
        return (*qfn2(fn))(qenv(fn), v0058, v0112);
    }

v0032:
    v0112 = qvalue(elt(env, 7)); // t
    goto v0201;

v0020:
    v0058 = qvalue(elt(env, 2)); // dmode!*
    v0112 = elt(env, 3); // ivalue
    v0112 = get(v0058, v0112);
    env = stack[0];
    v0050 = v0112;
    if (v0112 == nil) goto v0230;
    v0058 = v0050;
    v0112 = elt(env, 4); // (nil)
    fn = elt(env, 15); // apply
    v0112 = (*qfn2(fn))(qenv(fn), v0058, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    v0112 = qcar(v0112);
    { popv(1); return onevalue(v0112); }

v0230:
    v0112 = elt(env, 5); // "i used as indeterminate value"
    {
        popv(1);
        fn = elt(env, 16); // rederr
        return (*qfn1(fn))(qenv(fn), v0112);
    }

v0026:
    v0112 = v0050;
    {
        popv(1);
        fn = elt(env, 13); // force!-to!-dm
        return (*qfn1(fn))(qenv(fn), v0112);
    }
// error exit handlers
v0259:
    popv(1);
    return nil;
}



setup_type const u19_setup[] =
{
    {"cl_susiupdknowl1",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl1},
    {"ibalp_var-unset",         too_few_2,      CC_ibalp_varKunset,wrong_no_2},
    {"vsl_boundtype",           too_few_2,      CC_vsl_boundtype,wrong_no_2},
    {"my_letmtr",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_my_letmtr},
    {"xlcm",                    too_few_2,      CC_xlcm,       wrong_no_2},
    {"replace1_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace1_parents},
    {"endstat",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_endstat},
    {"setel",                   too_few_2,      CC_setel,      wrong_no_2},
    {"fs:prin1",                CC_fsTprin1,    too_many_1,    wrong_no_1},
    {"st_sorttree",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree},
    {"poly-multfnc",            too_few_2,      CC_polyKmultfnc,wrong_no_2},
    {"ofsf_sippsubst",          too_few_2,      CC_ofsf_sippsubst,wrong_no_2},
    {"inprint",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprint},
    {"xregister_wedge_pair",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_xregister_wedge_pair},
    {"cos*",                    CC_cosH,        too_many_1,    wrong_no_1},
    {"def_edge",                too_few_2,      CC_def_edge,   wrong_no_2},
    {"repartf",                 CC_repartf,     too_many_1,    wrong_no_1},
    {"total-degree-in-powers",  too_few_2,      CC_totalKdegreeKinKpowers,wrong_no_2},
    {"fs:null-angle",           CC_fsTnullKangle,too_many_1,   wrong_no_1},
    {"gcdout",                  CC_gcdout,      too_many_1,    wrong_no_1},
    {"numlist_ordp",            too_few_2,      CC_numlist_ordp,wrong_no_2},
    {"lambda_u9iz36vfudu4",     too_few_2,      CC_lambda_u9iz36vfudu4,wrong_no_2},
    {"subf",                    too_few_2,      CC_subf,       wrong_no_2},
    {"pasf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwupdknowl},
    {"row",                     CC_row,         too_many_1,    wrong_no_1},
    {"subs4q",                  CC_subs4q,      too_many_1,    wrong_no_1},
    {"gbfdot",                  too_few_2,      CC_gbfdot,     wrong_no_2},
    {":dmpluslst",              CC_Tdmpluslst,  too_many_1,    wrong_no_1},
    {"mktails",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails},
    {"putd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_putd},
    {"setk",                    too_few_2,      CC_setk,       wrong_no_2},
    {"red_totalred",            too_few_2,      CC_red_totalred,wrong_no_2},
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"bc_zero?",                CC_bc_zeroW,    too_many_1,    wrong_no_1},
    {"diff-k-times-mod-p",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKkKtimesKmodKp},
    {"bvarml",                  CC_bvarml,      too_many_1,    wrong_no_1},
    {"dipev2f",                 too_few_2,      CC_dipev2f,    wrong_no_2},
    {"freeoffl",                too_few_2,      CC_freeoffl,   wrong_no_2},
    {"red_topredbe",            too_few_2,      CC_red_topredbe,wrong_no_2},
    {"ilog2",                   CC_ilog2,       too_many_1,    wrong_no_1},
    {"bndtst",                  CC_bndtst,      too_many_1,    wrong_no_1},
    {"rndifference:",           too_few_2,      CC_rndifferenceT,wrong_no_2},
    {"mri_pasf2mri",            too_few_2,      CC_mri_pasf2mri,wrong_no_2},
    {"pasf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sacat},
    {"rl_updcache",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_updcache},
    {"sfto_tsqsumf",            CC_sfto_tsqsumf,too_many_1,    wrong_no_1},
    {"om2ir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2ir},
    {"rationalizesq",           CC_rationalizesq,too_many_1,   wrong_no_1},
    {"mkmatrix",                too_few_2,      CC_mkmatrix,   wrong_no_2},
    {"formc*",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcH},
    {"evaluate1",               too_few_2,      CC_evaluate1,  wrong_no_2},
    {NULL, (one_args *)"u19", (two_args *)"10353 8238029 9782093", 0}
};

// end of generated code
