
// $destdir\u32.c        Machine generated C code

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



// Code for inszzz

static LispObject CC_inszzz(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0022, v0023;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inszzz");
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
    goto v0024;

v0024:
    v0022 = stack[-1];
    if (v0022 == nil) goto v0025;
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0023 = qcar(v0022);
    v0022 = stack[-2];
    v0022 = qcar(v0022);
    v0022 = (LispObject)lessp2(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-4];
    goto v0027;

v0027:
    if (v0022 == nil) goto v0028;
    stack[0] = stack[-3];
    v0023 = stack[-2];
    v0022 = stack[-1];
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    {
        LispObject v0029 = stack[0];
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0029, v0022);
    }

v0028:
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0023 = qcar(v0022);
    v0022 = stack[-2];
    v0022 = qcar(v0022);
    if (equal(v0023, v0022)) goto v0030;
    v0022 = stack[-1];
    v0023 = qcar(v0022);
    v0022 = stack[-3];
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-3] = v0022;
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    stack[-1] = v0022;
    goto v0024;

v0030:
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    stack[0] = qcdr(v0022);
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0022 = qcdr(v0022);
    v0023 = qcar(v0022);
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    fn = elt(env, 3); // dm!-plus
    v0022 = (*qfn2(fn))(qenv(fn), v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0022 = Lrplaca(nil, stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    fn = elt(env, 4); // zeropp
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    if (v0022 == nil) goto v0031;
    v0023 = stack[-3];
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0023, v0022);
    }

v0031:
    v0023 = stack[-3];
    v0022 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0023, v0022);
    }

v0025:
    v0022 = qvalue(elt(env, 1)); // t
    goto v0027;
// error exit handlers
v0026:
    popv(5);
    return nil;
}



// Code for suspend

static LispObject CC_suspend(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0046, v0047, v0048, v0049;
    LispObject fn;
    LispObject v0040, v0024, v0045, v0044, v0004;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "suspend");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0044 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for suspend");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0040,v0024,v0045,v0044,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0004,v0044,v0045,v0024,v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0040;
    v0047 = v0024;
    v0048 = v0045;
    v0049 = v0044;
    v0046 = v0004;
// end of prologue
    stack[-8] = qvalue(elt(env, 1)); // op
    qvalue(elt(env, 1)) = nil; // op
    stack[-6] = qvalue(elt(env, 2)); // r
    qvalue(elt(env, 2)) = nil; // r
    stack[-5] = qvalue(elt(env, 3)); // p
    qvalue(elt(env, 3)) = nil; // p
    qvalue(elt(env, 1)) = v0046; // op
    v0046 = v0049;
    qvalue(elt(env, 2)) = v0046; // r
    v0046 = v0048;
    qvalue(elt(env, 3)) = v0046; // p
    v0046 = qvalue(elt(env, 2)); // r
    stack[-4] = qcar(v0046);
    v0046 = qvalue(elt(env, 3)); // p
    stack[-3] = qcar(v0046);
    stack[-2] = v0047;
    stack[-1] = qvalue(elt(env, 1)); // op
    v0046 = qvalue(elt(env, 2)); // r
    stack[0] = qcdr(v0046);
    v0047 = qvalue(elt(env, 1)); // op
    v0046 = qvalue(elt(env, 3)); // p
    v0046 = qcdr(v0046);
    v0046 = cons(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-9];
    v0046 = ncons(v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-9];
    v0047 = acons(stack[-1], stack[0], v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-9];
    v0046 = stack[-7];
    v0046 = cons(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-9];
    fn = elt(env, 4); // amatch
    v0046 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-3], stack[-2], v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; // p
    qvalue(elt(env, 2)) = stack[-6]; // r
    qvalue(elt(env, 1)) = stack[-8]; // op
    { popv(10); return onevalue(v0046); }
// error exit handlers
v0050:
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; // p
    qvalue(elt(env, 2)) = stack[-6]; // r
    qvalue(elt(env, 1)) = stack[-8]; // op
    popv(10);
    return nil;
}



// Code for copy_mat

static LispObject CC_copy_mat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for copy_mat");
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
    goto v0045;

v0045:
    v0055 = stack[0];
    v0055 = Lconsp(nil, v0055);
    env = stack[-2];
    if (v0055 == nil) goto v0020;
    v0055 = stack[0];
    v0055 = qcar(v0055);
    v0056 = CC_copy_mat(env, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0055 = stack[-1];
    v0055 = cons(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    stack[-1] = v0055;
    v0055 = stack[0];
    v0055 = qcdr(v0055);
    stack[0] = v0055;
    goto v0045;

v0020:
    v0056 = stack[-1];
    v0055 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0056, v0055);
    }
// error exit handlers
v0038:
    popv(3);
    return nil;
}



// Code for mkupf

static LispObject CC_mkupf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0002, v0003;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkupf");
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
    v0066 = v0000;
// end of prologue
    v0002 = v0066;
    v0066 = (LispObject)17; // 1
    fn = elt(env, 3); // mksq
    v0066 = (*qfn2(fn))(qenv(fn), v0002, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    stack[0] = v0066;
    v0066 = stack[0];
    v0066 = qcar(v0066);
    if (v0066 == nil) goto v0068;
    v0066 = stack[0];
    v0066 = qcar(v0066);
    if (!consp(v0066)) goto v0069;
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0066 = (consp(v0066) ? nil : lisp_true);
    goto v0070;

v0070:
    if (v0066 == nil) goto v0071;
    v0002 = (LispObject)17; // 1
    v0066 = stack[0];
    v0066 = cons(v0002, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    popv(2);
    return ncons(v0066);

v0071:
    v0066 = stack[0];
    v0002 = qcdr(v0066);
    v0066 = (LispObject)17; // 1
    if (v0002 == v0066) goto v0048;
    v0066 = qvalue(elt(env, 1)); // nil
    goto v0028;

v0028:
    if (v0066 == nil) goto v0072;
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0003 = qcar(v0066);
    v0002 = (LispObject)17; // 1
    v0066 = (LispObject)17; // 1
    v0066 = list2star(v0003, v0002, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    popv(2);
    return ncons(v0066);

v0072:
    v0066 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // partitsq!*
        return (*qfn1(fn))(qenv(fn), v0066);
    }

v0048:
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0002 = qcdr(v0066);
    v0066 = (LispObject)17; // 1
    if (v0002 == v0066) goto v0046;
    v0066 = qvalue(elt(env, 1)); // nil
    goto v0028;

v0046:
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    if (v0066 == nil) goto v0073;
    v0066 = qvalue(elt(env, 1)); // nil
    goto v0028;

v0073:
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    fn = elt(env, 5); // sfp
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0066 = (v0066 == nil ? lisp_true : nil);
    goto v0028;

v0069:
    v0066 = qvalue(elt(env, 2)); // t
    goto v0070;

v0068:
    v0066 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0066); }
// error exit handlers
v0067:
    popv(2);
    return nil;
}



// Code for getupper

static LispObject CC_getupper(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0019, v0027;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getupper");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0019 = v0000;
// end of prologue
    v0027 = qvalue(elt(env, 1)); // metricu!*
    v0019 = Latsoc(nil, v0019, v0027);
    v0019 = qcdr(v0019);
    return onevalue(v0019);
}



// Code for s_noparents

static LispObject CC_s_noparents(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0055;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s_noparents");
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
    goto v0045;

v0045:
    v0051 = stack[0];
    if (v0051 == nil) goto v0074;
    v0051 = stack[0];
    v0051 = qcar(v0051);
    fn = elt(env, 1); // has_parents
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    if (v0051 == nil) goto v0070;
    v0051 = stack[0];
    v0051 = qcdr(v0051);
    stack[0] = v0051;
    goto v0045;

v0070:
    v0051 = stack[0];
    v0055 = qcar(v0051);
    v0051 = stack[-1];
    v0051 = cons(v0055, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    stack[-1] = v0051;
    v0051 = stack[0];
    v0051 = qcdr(v0051);
    stack[0] = v0051;
    goto v0045;

v0074:
    v0051 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0051);
    }
// error exit handlers
v0016:
    popv(3);
    return nil;
}



// Code for in_list1a

static LispObject CC_in_list1a(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0107, v0108, v0109;
    LispObject fn;
    LispObject v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "in_list1a");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for in_list1a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0052);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0052;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    stack[0] = nil;
    v0107 = qvalue(elt(env, 1)); // !*echo
    stack[-5] = v0107;
    v0107 = qvalue(elt(env, 2)); // !*reduce4
    if (v0107 == nil) goto v0110;
    v0107 = stack[-4];
    fn = elt(env, 19); // type
    v0108 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0107 = elt(env, 3); // string
    if (v0108 == v0107) goto v0038;
    v0108 = stack[-4];
    v0107 = elt(env, 3); // string
    fn = elt(env, 20); // typerr
    v0107 = (*qfn2(fn))(qenv(fn), v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    goto v0110;

v0110:
    v0107 = stack[-4];
    fn = elt(env, 21); // mkfil!*
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-4] = v0107;
    v0107 = stack[-4];
    v0107 = Lexplodec(nil, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-1] = v0107;
    v0108 = stack[-1];
    v0107 = elt(env, 4); // !|
    if (!consp(v0108)) goto v0112;
    v0108 = qcar(v0108);
    if (!(v0108 == v0107)) goto v0112;
    v0107 = qvalue(elt(env, 5)); // t
    stack[0] = v0107;
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    fn = elt(env, 22); // list2string
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-4] = v0107;
    goto v0028;

v0028:
    v0107 = stack[0];
    if (v0107 == nil) goto v0113;
    v0108 = stack[-4];
    v0107 = elt(env, 13); // input
    fn = elt(env, 23); // pipe!-open
    v0107 = (*qfn2(fn))(qenv(fn), v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    goto v0114;

v0114:
    stack[-1] = v0107;
    v0107 = stack[-1];
    v0107 = Lrds(nil, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[0] = v0107;
    v0108 = stack[-4];
    v0107 = qvalue(elt(env, 14)); // linelist!*
    v0107 = Lassoc(nil, v0108, v0107);
    if (!(v0107 == nil)) goto v0115;

v0115:
    v0107 = (LispObject)17; // 1
    qvalue(elt(env, 15)) = v0107; // curline!*
    v0109 = stack[-4];
    v0108 = stack[-1];
    v0107 = (LispObject)17; // 1
    v0107 = list3(v0109, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    qvalue(elt(env, 10)) = v0107; // ifl!*
    v0108 = qvalue(elt(env, 10)); // ifl!*
    v0107 = qvalue(elt(env, 16)); // ipl!*
    v0107 = cons(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    qvalue(elt(env, 16)) = v0107; // ipl!*
    v0107 = stack[-3];
    qvalue(elt(env, 1)) = v0107; // !*echo
    v0107 = stack[-2];
    fn = elt(env, 24); // begin1a
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0107 = stack[0];
    v0107 = Lrds(nil, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0107 = stack[-1];
    v0107 = Lclose(nil, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0107 = stack[-5];
    qvalue(elt(env, 1)) = v0107; // !*echo
    v0107 = qvalue(elt(env, 16)); // ipl!*
    if (v0107 == nil) goto v0116;
    v0107 = qvalue(elt(env, 9)); // nil
    goto v0117;

v0117:
    if (v0107 == nil) goto v0118;
    v0107 = qvalue(elt(env, 9)); // nil
    { popv(7); return onevalue(v0107); }

v0118:
    v0107 = qvalue(elt(env, 16)); // ipl!*
    if (v0107 == nil) goto v0119;
    v0108 = stack[-4];
    v0107 = qvalue(elt(env, 16)); // ipl!*
    v0107 = qcar(v0107);
    v0107 = qcar(v0107);
    v0107 = (v0108 == v0107 ? lisp_true : nil);
    v0107 = (v0107 == nil ? lisp_true : nil);
    goto v0120;

v0120:
    if (v0107 == nil) goto v0121;
    v0109 = elt(env, 18); // "FILE STACK CONFUSION"
    v0108 = stack[-4];
    v0107 = qvalue(elt(env, 16)); // ipl!*
    v0107 = list3(v0109, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    fn = elt(env, 25); // rederr
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    goto v0122;

v0122:
    v0107 = nil;
    { popv(7); return onevalue(v0107); }

v0121:
    v0107 = qvalue(elt(env, 16)); // ipl!*
    v0107 = qcdr(v0107);
    qvalue(elt(env, 16)) = v0107; // ipl!*
    goto v0122;

v0119:
    v0107 = qvalue(elt(env, 5)); // t
    goto v0120;

v0116:
    v0107 = qvalue(elt(env, 17)); // contl!*
    goto v0117;

v0113:
    v0108 = stack[-4];
    v0107 = elt(env, 13); // input
    fn = elt(env, 26); // open
    v0107 = (*qfn2(fn))(qenv(fn), v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    goto v0114;

v0112:
    v0108 = stack[-1];
    v0107 = elt(env, 6); // !$
    if (!consp(v0108)) goto v0123;
    v0108 = qcar(v0108);
    if (!(v0108 == v0107)) goto v0123;
    v0107 = stack[-1];
    v0108 = qcdr(v0107);
    v0107 = elt(env, 7); // !/
    if (!consp(v0108)) goto v0124;
    v0108 = qcar(v0108);
    if (!(v0108 == v0107)) goto v0124;
    v0107 = qvalue(elt(env, 5)); // t
    goto v0009;

v0009:
    if (v0107 == nil) goto v0028;
    v0107 = qvalue(elt(env, 10)); // ifl!*
    if (v0107 == nil) goto v0072;
    v0107 = qvalue(elt(env, 10)); // ifl!*
    v0107 = qcar(v0107);
    v0107 = Lexplodec(nil, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0107 = Lreverse(nil, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0109 = v0107;
    goto v0029;

v0029:
    v0107 = v0109;
    if (v0107 == nil) goto v0026;
    v0108 = v0109;
    v0107 = elt(env, 7); // !/
    if (!consp(v0108)) goto v0125;
    v0108 = qcar(v0108);
    if (!(v0108 == v0107)) goto v0125;
    v0107 = qvalue(elt(env, 5)); // t
    goto v0126;

v0126:
    if (!(v0107 == nil)) goto v0026;
    v0107 = v0109;
    v0107 = qcdr(v0107);
    v0109 = v0107;
    goto v0029;

v0026:
    v0107 = v0109;
    if (!(v0107 == nil)) goto v0127;
    v0107 = elt(env, 12); // (!/ !.)
    v0109 = v0107;
    goto v0127;

v0127:
    v0107 = v0109;
    v0108 = Lreverse(nil, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    v0107 = qcdr(v0107);
    v0107 = Lappend(nil, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-1] = v0107;
    v0107 = stack[-1];
    fn = elt(env, 22); // list2string
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-4] = v0107;
    goto v0028;

v0125:
    v0108 = v0109;
    v0107 = elt(env, 8); // !\ (backslash)
    v0107 = Leqcar(nil, v0108, v0107);
    env = stack[-6];
    goto v0126;

v0072:
    v0108 = elt(env, 11); // !.
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    v0107 = cons(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    fn = elt(env, 22); // list2string
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-4] = v0107;
    goto v0028;

v0124:
    v0107 = stack[-1];
    v0108 = qcdr(v0107);
    v0107 = elt(env, 8); // !\ (backslash)
    v0107 = Leqcar(nil, v0108, v0107);
    env = stack[-6];
    goto v0009;

v0123:
    v0107 = qvalue(elt(env, 9)); // nil
    goto v0009;

v0038:
    v0107 = stack[-4];
    fn = elt(env, 27); // value
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-4] = v0107;
    goto v0110;
// error exit handlers
v0111:
    popv(7);
    return nil;
}



// Code for xremf

static LispObject CC_xremf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0175, v0176, v0177;
    LispObject fn;
    LispObject v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xremf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0052);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0052;
    stack[-6] = v0001;
    stack[-7] = v0000;
// end of prologue
    stack[-1] = nil;
    v0175 = (LispObject)1; // 0
    stack[-8] = v0175;
    v0175 = stack[-6];
    if (!consp(v0175)) goto v0065;
    v0175 = stack[-6];
    v0175 = qcar(v0175);
    v0175 = (consp(v0175) ? nil : lisp_true);
    goto v0054;

v0054:
    if (v0175 == nil) goto v0178;
    v0176 = stack[-7];
    v0175 = stack[-6];
    fn = elt(env, 3); // qremd
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0175 = qcdr(v0175);
    popv(10);
    return ncons(v0175);

v0178:
    v0175 = stack[-7];
    fn = elt(env, 4); // termsf
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[0] = v0175;
    goto v0041;

v0041:
    v0176 = stack[-5];
    v0175 = (LispObject)1; // 0
    v0175 = (LispObject)lesseq2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0175 = v0175 ? lisp_true : nil;
    env = stack[-9];
    if (v0175 == nil) goto v0043;
    v0175 = qvalue(elt(env, 2)); // nil
    { popv(10); return onevalue(v0175); }

v0043:
    v0175 = stack[-7];
    if (!consp(v0175)) goto v0046;
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0175 = (consp(v0175) ? nil : lisp_true);
    goto v0039;

v0039:
    if (v0175 == nil) goto v0180;
    v0176 = stack[-1];
    v0175 = stack[-7];
    fn = elt(env, 5); // addf
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    popv(10);
    return ncons(v0175);

v0180:
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0176 = qcar(v0175);
    v0175 = stack[-6];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    if (v0176 == v0175) goto v0181;
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0176 = qcar(v0175);
    v0175 = stack[-6];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    fn = elt(env, 6); // ordop
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    if (v0175 == nil) goto v0182;
    v0176 = stack[-5];
    v0175 = stack[-8];
    v0175 = plus2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-5] = v0175;
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0177 = qcdr(v0175);
    v0176 = stack[-6];
    v0175 = stack[-5];
    v0175 = CC_xremf(env, 3, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-3] = v0175;
    v0175 = stack[-3];
    if (v0175 == nil) goto v0183;
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0176 = qcar(v0175);
    v0175 = (LispObject)17; // 1
    v0175 = cons(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0176 = ncons(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0175 = stack[-3];
    v0175 = qcar(v0175);
    fn = elt(env, 7); // multf
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    fn = elt(env, 5); // addf
    v0175 = (*qfn2(fn))(qenv(fn), stack[-1], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-1] = v0175;
    v0175 = stack[-1];
    fn = elt(env, 4); // termsf
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-8] = v0175;
    v0176 = stack[-5];
    v0175 = stack[-8];
    v0175 = difference2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-5] = v0175;
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    stack[-7] = v0175;
    goto v0041;

v0183:
    v0175 = qvalue(elt(env, 2)); // nil
    { popv(10); return onevalue(v0175); }

v0182:
    v0176 = stack[-1];
    v0175 = stack[-7];
    fn = elt(env, 5); // addf
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    popv(10);
    return ncons(v0175);

v0181:
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0176 = qcdr(v0175);
    v0175 = stack[-6];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0175 = qcdr(v0175);
    v0176 = difference2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-4] = v0176;
    v0175 = (LispObject)1; // 0
    v0175 = (LispObject)lessp2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0175 = v0175 ? lisp_true : nil;
    env = stack[-9];
    if (v0175 == nil) goto v0184;
    v0176 = stack[-1];
    v0175 = stack[-7];
    fn = elt(env, 5); // addf
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    popv(10);
    return ncons(v0175);

v0184:
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0176 = qcdr(v0175);
    v0175 = stack[-6];
    v0175 = qcar(v0175);
    v0175 = qcdr(v0175);
    fn = elt(env, 8); // qremf
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-3] = v0175;
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0176 = qcar(v0175);
    v0175 = (LispObject)17; // 1
    v0175 = cons(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0176 = ncons(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0175 = stack[-3];
    v0175 = qcdr(v0175);
    fn = elt(env, 7); // multf
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-2] = v0175;
    v0176 = stack[-5];
    v0175 = stack[-8];
    v0175 = plus2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-5] = v0175;
    v0176 = stack[-1];
    v0175 = stack[-2];
    fn = elt(env, 5); // addf
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-1] = v0175;
    v0175 = stack[-1];
    fn = elt(env, 4); // termsf
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-8] = v0175;
    v0176 = stack[-5];
    v0175 = stack[-8];
    v0176 = difference2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0175 = stack[0];
    v0175 = plus2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-5] = v0175;
    v0175 = stack[-3];
    v0175 = qcar(v0175);
    if (v0175 == nil) goto v0185;
    stack[0] = stack[-7];
    v0176 = stack[-4];
    v0175 = (LispObject)1; // 0
    if (v0176 == v0175) goto v0186;
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0175 = qcar(v0175);
    v0176 = qcar(v0175);
    v0175 = stack[-4];
    fn = elt(env, 9); // to
    v0176 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0175 = (LispObject)17; // 1
    v0175 = cons(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0176 = ncons(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0175 = stack[-6];
    fn = elt(env, 7); // multf
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-4] = v0175;
    goto v0187;

v0187:
    v0175 = stack[-3];
    v0175 = qcar(v0175);
    fn = elt(env, 10); // negf
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    fn = elt(env, 7); // multf
    v0175 = (*qfn2(fn))(qenv(fn), stack[-4], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    fn = elt(env, 5); // addf
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    v0175 = stack[-2];
    fn = elt(env, 10); // negf
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    fn = elt(env, 5); // addf
    v0175 = (*qfn2(fn))(qenv(fn), stack[0], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    goto v0188;

v0188:
    stack[-7] = v0175;
    v0175 = stack[-7];
    fn = elt(env, 4); // termsf
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[0] = v0175;
    v0176 = stack[-5];
    v0175 = stack[0];
    v0175 = difference2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-9];
    stack[-5] = v0175;
    goto v0041;

v0186:
    v0175 = stack[-6];
    stack[-4] = v0175;
    goto v0187;

v0185:
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    goto v0188;

v0046:
    v0175 = qvalue(elt(env, 1)); // t
    goto v0039;

v0065:
    v0175 = qvalue(elt(env, 1)); // t
    goto v0054;
// error exit handlers
v0179:
    popv(10);
    return nil;
}



// Code for cali!=min

static LispObject CC_caliMmin(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0063, v0030, v0039;
    LispObject fn;
    LispObject v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cali=min");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali=min");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0052);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0052;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0024:
    v0063 = stack[-1];
    if (v0063 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0039 = stack[-2];
    v0063 = stack[-1];
    v0030 = qcar(v0063);
    v0063 = stack[0];
    fn = elt(env, 1); // listtest
    v0063 = (*qfnn(fn))(qenv(fn), 3, v0039, v0030, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    if (!(v0063 == nil)) goto v0025;
    v0063 = stack[-1];
    v0039 = qcdr(v0063);
    v0063 = stack[-1];
    v0030 = qcar(v0063);
    v0063 = stack[0];
    fn = elt(env, 1); // listtest
    v0063 = (*qfnn(fn))(qenv(fn), 3, v0039, v0030, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    if (!(v0063 == nil)) goto v0025;
    v0063 = stack[-1];
    v0030 = qcar(v0063);
    v0063 = stack[-2];
    v0063 = cons(v0030, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    stack[-2] = v0063;
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    goto v0024;

v0025:
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    goto v0024;
// error exit handlers
v0049:
    popv(4);
    return nil;
}



// Code for pst_subpst

static LispObject CC_pst_subpst(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0025, v0110;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_subpst");
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
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0110 = v0001;
    v0025 = v0000;
// end of prologue
    stack[0] = qcdr(v0025);
    v0025 = v0110;
    v0025 = sub1(v0025);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    v0025 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0025/(16/CELL)));
    { popv(1); return onevalue(v0025); }
// error exit handlers
v0192:
    popv(1);
    return nil;
}



// Code for lpos

static LispObject CC_lpos(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0036, v0021, v0037, v0034;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lpos");
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
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0037 = v0001;
    v0034 = v0000;
// end of prologue
    v0021 = v0034;
    v0036 = v0037;
    v0036 = qcar(v0036);
    if (v0021 == v0036) goto v0045;
    v0036 = v0034;
    v0021 = v0037;
    v0021 = qcdr(v0021);
    v0036 = CC_lpos(env, v0036, v0021);
    errexit();
    return add1(v0036);

v0045:
    v0036 = (LispObject)17; // 1
    return onevalue(v0036);
}



// Code for bfrsq

static LispObject CC_bfrsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0046;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bfrsq");
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
    v0046 = v0000;
// end of prologue
    v0039 = v0046;
    v0039 = qcar(v0039);
    v0046 = qcdr(v0046);
    stack[-1] = v0046;
    v0046 = v0039;
    if (!consp(v0046)) goto v0174;
    v0046 = v0039;
    fn = elt(env, 1); // csl_timbf
    stack[0] = (*qfn2(fn))(qenv(fn), v0046, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0046 = stack[-1];
    v0039 = stack[-1];
    fn = elt(env, 1); // csl_timbf
    v0039 = (*qfn2(fn))(qenv(fn), v0046, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    {
        LispObject v0102 = stack[0];
        popv(3);
        fn = elt(env, 2); // plubf
        return (*qfn2(fn))(qenv(fn), v0102, v0039);
    }

v0174:
    v0046 = v0039;
    stack[0] = times2(v0046, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0046 = stack[-1];
    v0039 = stack[-1];
    v0039 = times2(v0046, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    {
        LispObject v0009 = stack[0];
        popv(3);
        return plus2(v0009, v0039);
    }
// error exit handlers
v0049:
    popv(3);
    return nil;
}



// Code for rl_onp

static LispObject CC_rl_onp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0068;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_onp");
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
    v0068 = elt(env, 1); // !*
    stack[-1] = Lexplode(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0068 = stack[0];
    v0068 = Lexplode(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0068 = Lappend(nil, stack[-1], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0068 = Lcompress(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0068 = Lintern(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 2); // eval
        return (*qfn1(fn))(qenv(fn), v0068);
    }
// error exit handlers
v0053:
    popv(3);
    return nil;
}



// Code for rl_multsurep

static LispObject CC_rl_multsurep(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0053, v0195;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_multsurep");
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
    v0053 = v0001;
    v0195 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_multsurep!*
    v0053 = list2(v0195, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    {
        LispObject v0065 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0065, v0053);
    }
// error exit handlers
v0054:
    popv(2);
    return nil;
}



// Code for matrixrd

static LispObject CC_matrixrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0198, v0106;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixrd");
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
    v0198 = (LispObject)1; // 0
    stack[-1] = v0198;
    v0198 = nil;
    stack[0] = v0198;
    goto v0192;

v0192:
    v0106 = stack[-1];
    v0198 = (LispObject)1; // 0
    if (v0106 == v0198) goto v0025;
    v0106 = elt(env, 6); // mat
    v0198 = stack[0];
    v0198 = cons(v0106, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); // aeval
        return (*qfn1(fn))(qenv(fn), v0198);
    }

v0025:
    fn = elt(env, 8); // lex
    v0198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    v0106 = qvalue(elt(env, 2)); // char
    v0198 = elt(env, 3); // (m a t r i x r o w)
    if (equal(v0106, v0198)) goto v0020;
    v0198 = (LispObject)17; // 1
    stack[-1] = v0198;
    goto v0192;

v0020:
    fn = elt(env, 9); // matrixrowrd
    v0198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    v0106 = v0198;
    v0198 = stack[0];
    if (v0198 == nil) goto v0194;
    v0198 = v0106;
    v0198 = ncons(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    v0198 = Lappend(nil, stack[0], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    stack[0] = v0198;
    goto v0039;

v0039:
    v0106 = qvalue(elt(env, 2)); // char
    v0198 = elt(env, 4); // (!/ m a t r i x r o w)
    if (equal(v0106, v0198)) goto v0192;
    v0106 = elt(env, 5); // "</matrixrow>"
    v0198 = (LispObject)33; // 2
    fn = elt(env, 10); // errorml
    v0198 = (*qfn2(fn))(qenv(fn), v0106, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    goto v0192;

v0194:
    v0198 = v0106;
    v0198 = ncons(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    stack[0] = v0198;
    goto v0039;
// error exit handlers
v0199:
    popv(3);
    return nil;
}



// Code for compl

static LispObject CC_compl(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0189, v0190, v0064;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compl");
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
    v0064 = nil;
    goto v0024;

v0024:
    v0189 = stack[-1];
    if (v0189 == nil) goto v0033;
    v0189 = stack[-1];
    v0190 = qcar(v0189);
    v0189 = stack[0];
    v0189 = Lmember(nil, v0190, v0189);
    if (v0189 == nil) goto v0037;
    v0189 = stack[-1];
    v0189 = qcdr(v0189);
    stack[-1] = v0189;
    goto v0024;

v0037:
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0190 = v0064;
    v0189 = cons(v0189, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    v0064 = v0189;
    v0189 = stack[-1];
    v0189 = qcdr(v0189);
    stack[-1] = v0189;
    goto v0024;

v0033:
    v0189 = v0064;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0189);
    }
// error exit handlers
v0200:
    popv(3);
    return nil;
}



// Code for spcol_dim

static LispObject CC_spcol_dim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0036;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spcol_dim");
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
    v0036 = qvalue(elt(env, 1)); // !*fast_la
    if (v0036 == nil) goto v0019;
    v0036 = qvalue(elt(env, 2)); // nil
    goto v0032;

v0032:
    if (v0036 == nil) goto v0024;
    v0036 = elt(env, 3); // "Error in spcol_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    goto v0024;

v0024:
    v0036 = stack[0];
    fn = elt(env, 5); // spmatlength
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    v0036 = qcdr(v0036);
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    { popv(2); return onevalue(v0036); }

v0019:
    v0036 = stack[0];
    fn = elt(env, 6); // matrixp
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    v0036 = (v0036 == nil ? lisp_true : nil);
    goto v0032;
// error exit handlers
v0037:
    popv(2);
    return nil;
}



// Code for mkbc

static LispObject CC_mkbc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0206, v0059;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkbc");
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

v0045:
    v0206 = stack[-1];
    v0206 = (is_number(v0206) ? lisp_true : nil);
    if (!(v0206 == nil)) goto v0040;
    v0206 = stack[-1];
    fn = elt(env, 3); // f2dip11
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    goto v0040;

v0040:
    v0206 = stack[0];
    v0206 = (is_number(v0206) ? lisp_true : nil);
    if (!(v0206 == nil)) goto v0110;
    v0206 = stack[0];
    fn = elt(env, 3); // f2dip11
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    goto v0110;

v0110:
    v0206 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0206 == nil) goto v0016;
    v0206 = stack[0];
    v0206 = Lmodular_reciprocal(nil, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    v0206 = times2(stack[-1], v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(qenv(fn), v0206);
    }

v0016:
    v0059 = stack[0];
    v0206 = (LispObject)17; // 1
    if (v0059 == v0206) goto v0041;
    v0206 = stack[0];
    fn = elt(env, 5); // minusf
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    if (v0206 == nil) goto v0171;
    v0206 = stack[-1];
    fn = elt(env, 6); // negf
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    stack[-1] = v0206;
    v0206 = stack[0];
    fn = elt(env, 6); // negf
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    stack[0] = v0206;
    goto v0045;

v0171:
    v0059 = stack[-1];
    v0206 = stack[0];
    fn = elt(env, 7); // gcdf
    v0206 = (*qfn2(fn))(qenv(fn), v0059, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    stack[-2] = v0206;
    v0059 = stack[-1];
    v0206 = stack[-2];
    fn = elt(env, 8); // quotfx
    stack[-1] = (*qfn2(fn))(qenv(fn), v0059, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    v0059 = stack[0];
    v0206 = stack[-2];
    fn = elt(env, 8); // quotfx
    v0206 = (*qfn2(fn))(qenv(fn), v0059, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        LispObject v0207 = stack[-1];
        popv(4);
        return cons(v0207, v0206);
    }

v0041:
    v0059 = stack[-1];
    v0206 = (LispObject)17; // 1
    if (v0059 == v0206) goto v0043;
    v0059 = stack[-1];
    v0206 = stack[0];
    popv(4);
    return cons(v0059, v0206);

v0043:
    v0206 = elt(env, 2); // (1 . 1)
    { popv(4); return onevalue(v0206); }
// error exit handlers
v0169:
    popv(4);
    return nil;
}



// Code for applysetop

static LispObject CC_applysetop(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0223, v0224, v0225;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for applysetop");
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
    v0224 = v0001;
    stack[-6] = v0000;
// end of prologue
    stack[-5] = nil;
    v0223 = (LispObject)1; // 0
    stack[-7] = v0223;
    v0223 = v0224;
    stack[-4] = v0223;
    v0223 = stack[-4];
    if (v0223 == nil) goto v0053;
    v0223 = stack[-4];
    v0223 = qcar(v0223);
    stack[0] = v0223;
    v0223 = stack[0];
    fn = elt(env, 6); // reval
    v0224 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    stack[0] = v0224;
    v0223 = elt(env, 2); // list
    if (!consp(v0224)) goto v0021;
    v0224 = qcar(v0224);
    if (!(v0224 == v0223)) goto v0021;
    v0223 = stack[0];
    v0223 = qcdr(v0223);
    fn = elt(env, 7); // delete!-dups
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    stack[0] = v0223;
    v0224 = stack[-7];
    v0223 = (LispObject)1; // 0
    if (v0224 == v0223) goto v0018;
    v0225 = stack[-6];
    v0224 = stack[-7];
    v0223 = stack[0];
    v0223 = Lapply2(nil, 3, v0225, v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    goto v0017;

v0017:
    stack[-7] = v0223;
    v0223 = stack[0];
    fn = elt(env, 8); // make!-set
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    goto v0020;

v0020:
    v0223 = ncons(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    stack[-2] = v0223;
    stack[-3] = v0223;
    goto v0110;

v0110:
    v0223 = stack[-4];
    v0223 = qcdr(v0223);
    stack[-4] = v0223;
    v0223 = stack[-4];
    if (v0223 == nil) goto v0226;
    stack[-1] = stack[-2];
    v0223 = stack[-4];
    v0223 = qcar(v0223);
    stack[0] = v0223;
    v0223 = stack[0];
    fn = elt(env, 6); // reval
    v0224 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    stack[0] = v0224;
    v0223 = elt(env, 2); // list
    if (!consp(v0224)) goto v0166;
    v0224 = qcar(v0224);
    if (!(v0224 == v0223)) goto v0166;
    v0223 = stack[0];
    v0223 = qcdr(v0223);
    fn = elt(env, 7); // delete!-dups
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    stack[0] = v0223;
    v0224 = stack[-7];
    v0223 = (LispObject)1; // 0
    if (v0224 == v0223) goto v0227;
    v0225 = stack[-6];
    v0224 = stack[-7];
    v0223 = stack[0];
    v0223 = Lapply2(nil, 3, v0225, v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    goto v0228;

v0228:
    stack[-7] = v0223;
    v0223 = stack[0];
    fn = elt(env, 8); // make!-set
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    goto v0229;

v0229:
    v0223 = ncons(v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    v0223 = Lrplacd(nil, stack[-1], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    stack[-2] = v0223;
    goto v0110;

v0227:
    v0223 = stack[0];
    goto v0228;

v0166:
    v0223 = stack[0];
    if (symbolp(v0223)) goto v0091;
    v0223 = stack[0];
    v0223 = Lconsp(nil, v0223);
    env = stack[-8];
    if (v0223 == nil) goto v0149;
    v0223 = stack[0];
    v0224 = qcar(v0223);
    v0223 = elt(env, 3); // setvalued
    v0223 = Lflagp(nil, v0224, v0223);
    env = stack[-8];
    if (!(v0223 == nil)) goto v0091;

v0149:
    v0224 = stack[0];
    v0223 = elt(env, 4); // "set"
    fn = elt(env, 9); // typerr
    v0223 = (*qfn2(fn))(qenv(fn), v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    goto v0229;

v0091:
    v0224 = stack[0];
    v0223 = stack[-5];
    v0223 = Lmember(nil, v0224, v0223);
    if (!(v0223 == nil)) goto v0230;
    v0224 = stack[0];
    v0223 = stack[-5];
    v0223 = cons(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    stack[-5] = v0223;
    goto v0230;

v0230:
    v0223 = stack[0];
    goto v0229;

v0226:
    v0223 = stack[-3];
    goto v0025;

v0025:
    v0225 = v0223;
    v0223 = stack[-5];
    if (v0223 == nil) goto v0144;
    stack[0] = stack[-6];
    v0224 = stack[-6];
    v0223 = elt(env, 5); // setdiff
    if (v0224 == v0223) goto v0231;
    v0224 = stack[-7];
    v0223 = (LispObject)1; // 0
    if (v0224 == v0223) goto v0232;
    v0223 = stack[-7];
    fn = elt(env, 8); // make!-set
    v0224 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    v0223 = stack[-5];
    v0223 = cons(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    goto v0233;

v0233:
    {
        LispObject v0121 = stack[0];
        popv(9);
        return cons(v0121, v0223);
    }

v0232:
    v0223 = stack[-5];
    goto v0233;

v0231:
    v0223 = v0225;
    goto v0233;

v0144:
    v0223 = stack[-7];
    fn = elt(env, 8); // make!-set
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 10); // aeval
        return (*qfn1(fn))(qenv(fn), v0223);
    }

v0018:
    v0223 = stack[0];
    goto v0017;

v0021:
    v0223 = stack[0];
    if (symbolp(v0223)) goto v0201;
    v0223 = stack[0];
    v0223 = Lconsp(nil, v0223);
    env = stack[-8];
    if (v0223 == nil) goto v0072;
    v0223 = stack[0];
    v0224 = qcar(v0223);
    v0223 = elt(env, 3); // setvalued
    v0223 = Lflagp(nil, v0224, v0223);
    env = stack[-8];
    if (!(v0223 == nil)) goto v0201;

v0072:
    v0224 = stack[0];
    v0223 = elt(env, 4); // "set"
    fn = elt(env, 9); // typerr
    v0223 = (*qfn2(fn))(qenv(fn), v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    goto v0020;

v0201:
    v0224 = stack[0];
    v0223 = stack[-5];
    v0223 = Lmember(nil, v0224, v0223);
    if (!(v0223 == nil)) goto v0105;
    v0224 = stack[0];
    v0223 = stack[-5];
    v0223 = cons(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-8];
    stack[-5] = v0223;
    goto v0105;

v0105:
    v0223 = stack[0];
    goto v0020;

v0053:
    v0223 = qvalue(elt(env, 1)); // nil
    goto v0025;
// error exit handlers
v0076:
    popv(9);
    return nil;
}



// Code for aceq

static LispObject CC_aceq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0018, v0200, v0043, v0028;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aceq");
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
    v0200 = v0001;
    v0043 = v0000;
// end of prologue

v0024:
    v0018 = v0043;
    if (v0018 == nil) goto v0033;
    v0018 = v0200;
    if (v0018 == nil) goto v0110;
    v0018 = v0043;
    v0028 = qcar(v0018);
    v0018 = v0200;
    v0018 = Lmember(nil, v0028, v0018);
    if (v0018 == nil) goto v0190;
    v0018 = v0043;
    v0018 = qcdr(v0018);
    stack[0] = v0018;
    v0018 = v0043;
    v0018 = qcar(v0018);
    v0018 = Ldelete(nil, v0018, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    v0200 = v0018;
    v0018 = stack[0];
    v0043 = v0018;
    goto v0024;

v0190:
    v0018 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0018); }

v0110:
    v0018 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0018); }

v0033:
    v0018 = v0200;
    v0018 = (v0018 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0018); }
// error exit handlers
v0042:
    popv(2);
    return nil;
}



// Code for calc_atlas

static LispObject CC_calc_atlas(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0070, v0069, v0193, v0191;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_atlas");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0070 = v0001;
    v0069 = v0000;
// end of prologue
    v0193 = v0069;
    v0191 = qcar(v0193);
    v0193 = v0069;
    v0193 = qcdr(v0193);
    v0193 = qcdr(v0193);
    v0193 = qcar(v0193);
    v0069 = qcdr(v0069);
    v0069 = qcar(v0069);
    {
        fn = elt(env, 1); // calc_map_2d
        return (*qfnn(fn))(qenv(fn), 4, v0191, v0193, v0069, v0070);
    }
}



// Code for formsetq0

static LispObject CC_formsetq0(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0296, v0297, v0298, v0299;
    LispObject fn;
    LispObject v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq0");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formsetq0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0052);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0052;
    stack[-4] = v0001;
    stack[0] = v0000;
// end of prologue
    stack[-1] = nil;
    v0296 = stack[0];
    v0296 = qcdr(v0296);
    stack[0] = v0296;
    v0296 = qcar(v0296);
    stack[-2] = v0296;
    if (!(symbolp(v0296))) goto v0021;
    v0297 = stack[-2];
    v0296 = stack[-4];
    v0296 = Latsoc(nil, v0297, v0296);
    stack[-1] = v0296;
    goto v0021;

v0021:
    v0296 = stack[0];
    v0296 = qcdr(v0296);
    v0297 = qcar(v0296);
    v0296 = elt(env, 1); // quote
    if (!consp(v0297)) goto v0189;
    v0297 = qcar(v0297);
    if (!(v0297 == v0296)) goto v0189;
    v0296 = elt(env, 2); // symbolic
    stack[-3] = v0296;
    goto v0189;

v0189:
    v0296 = stack[0];
    v0296 = qcdr(v0296);
    v0299 = qcar(v0296);
    v0298 = stack[-4];
    v0297 = elt(env, 2); // symbolic
    v0296 = stack[-3];
    fn = elt(env, 24); // convertmode
    v0296 = (*qfnn(fn))(qenv(fn), 4, v0299, v0298, v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    stack[-5] = v0296;
    v0296 = stack[-2];
    if (!consp(v0296)) goto v0168;
    v0296 = qvalue(elt(env, 3)); // !*savedef
    if (v0296 == nil) goto v0009;
    v0296 = stack[-2];
    v0297 = qcar(v0296);
    v0296 = elt(env, 4); // inline
    v0296 = get(v0297, v0296);
    env = stack[-6];
    if (!(v0296 == nil)) goto v0010;
    v0296 = stack[-2];
    v0297 = qcar(v0296);
    v0296 = elt(env, 5); // smacro
    v0296 = get(v0297, v0296);
    env = stack[-6];
    if (!(v0296 == nil)) goto v0010;

v0009:
    v0296 = qvalue(elt(env, 7)); // t
    goto v0046;

v0046:
    if (v0296 == nil) goto v0030;
    v0296 = stack[-2];
    v0296 = qcar(v0296);
    if (symbolp(v0296)) goto v0029;
    v0297 = stack[-2];
    v0296 = elt(env, 9); // "assignment"
    {
        popv(7);
        fn = elt(env, 25); // typerr
        return (*qfn2(fn))(qenv(fn), v0297, v0296);
    }

v0029:
    v0297 = stack[-2];
    v0296 = stack[-3];
    fn = elt(env, 26); // macrochk
    v0296 = (*qfn2(fn))(qenv(fn), v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    stack[-2] = v0296;
    if (!consp(v0296)) goto v0165;
    v0296 = stack[-2];
    v0296 = qcar(v0296);
    fn = elt(env, 27); // arrayp
    v0296 = (*qfn1(fn))(qenv(fn), v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    goto v0301;

v0301:
    if (v0296 == nil) goto v0023;
    stack[0] = elt(env, 10); // setel
    v0298 = stack[-2];
    v0297 = stack[-4];
    v0296 = stack[-3];
    fn = elt(env, 28); // intargfn
    v0297 = (*qfnn(fn))(qenv(fn), 3, v0298, v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    v0296 = stack[-5];
    {
        LispObject v0302 = stack[0];
        popv(7);
        return list3(v0302, v0297, v0296);
    }

v0023:
    v0296 = stack[-2];
    if (!consp(v0296)) goto v0303;
    v0296 = stack[-2];
    v0296 = qcdr(v0296);
    if (v0296 == nil) goto v0304;
    v0296 = stack[-2];
    v0296 = qcar(v0296);
    if (!symbolp(v0296)) v0297 = nil;
    else { v0297 = qfastgets(v0296);
           if (v0297 != nil) { v0297 = elt(v0297, 2); // rtype
#ifdef RECORD_GET
             if (v0297 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0297 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0297 == SPID_NOPROP) v0297 = nil; }}
#endif
    v0296 = elt(env, 11); // vector
    if (v0297 == v0296) goto v0305;
    v0296 = stack[-2];
    v0296 = qcdr(v0296);
    v0296 = qcar(v0296);
    v0296 = Lsimple_vectorp(nil, v0296);
    env = stack[-6];
    if (!(v0296 == nil)) goto v0306;
    v0296 = stack[-2];
    v0296 = qcdr(v0296);
    v0297 = qcar(v0296);
    v0296 = elt(env, 12); // vecfn
    v0296 = Lflagpcar(nil, v0297, v0296);
    env = stack[-6];
    goto v0306;

v0306:
    if (v0296 == nil) goto v0086;
    v0298 = stack[0];
    v0297 = stack[-4];
    v0296 = stack[-3];
    {
        popv(7);
        fn = elt(env, 29); // putvect
        return (*qfnn(fn))(qenv(fn), 3, v0298, v0297, v0296);
    }

v0086:
    v0297 = stack[-2];
    v0296 = elt(env, 13); // part
    if (!consp(v0297)) goto v0307;
    v0297 = qcar(v0297);
    if (!(v0297 == v0296)) goto v0307;
    stack[-1] = elt(env, 14); // list
    v0296 = elt(env, 15); // setpart!*
    stack[0] = Lmkquote(nil, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0296 = stack[-2];
    v0298 = qcdr(v0296);
    v0297 = stack[-4];
    v0296 = stack[-3];
    fn = elt(env, 30); // formlis
    v0296 = (*qfnn(fn))(qenv(fn), 3, v0298, v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0297 = list2star(stack[-1], stack[0], v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0296 = stack[-5];
    {
        popv(7);
        fn = elt(env, 31); // aconc
        return (*qfn2(fn))(qenv(fn), v0297, v0296);
    }

v0307:
    v0296 = stack[-2];
    if (!consp(v0296)) goto v0308;
    v0296 = stack[-2];
    v0297 = qcar(v0296);
    v0296 = elt(env, 16); // setqfn
    v0296 = get(v0297, v0296);
    env = stack[-6];
    stack[-1] = v0296;
    goto v0309;

v0309:
    if (v0296 == nil) goto v0310;
    v0296 = stack[-2];
    v0297 = qcdr(v0296);
    v0296 = stack[0];
    v0296 = qcdr(v0296);
    v0297 = Lappend(nil, v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0296 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 32); // applsmacro
    v0298 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0297 = stack[-4];
    v0296 = stack[-3];
    {
        popv(7);
        fn = elt(env, 33); // form1
        return (*qfnn(fn))(qenv(fn), 3, v0298, v0297, v0296);
    }

v0310:
    v0297 = stack[-3];
    v0296 = elt(env, 2); // symbolic
    if (v0297 == v0296) goto v0311;
    v0296 = qvalue(elt(env, 8)); // nil
    goto v0312;

v0312:
    if (v0296 == nil) goto v0313;
    stack[0] = elt(env, 19); // rsetf
    v0298 = stack[-2];
    v0297 = stack[-4];
    v0296 = stack[-3];
    fn = elt(env, 33); // form1
    v0297 = (*qfnn(fn))(qenv(fn), 3, v0298, v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    v0296 = stack[-5];
    {
        LispObject v0314 = stack[0];
        popv(7);
        return list3(v0314, v0297, v0296);
    }

v0313:
    stack[0] = elt(env, 20); // setk
    v0298 = stack[-2];
    v0297 = stack[-4];
    v0296 = elt(env, 21); // algebraic
    fn = elt(env, 33); // form1
    v0297 = (*qfnn(fn))(qenv(fn), 3, v0298, v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    v0296 = stack[-5];
    {
        LispObject v0315 = stack[0];
        popv(7);
        return list3(v0315, v0297, v0296);
    }

v0311:
    v0296 = qvalue(elt(env, 17)); // !*rlisp88
    if (!(v0296 == nil)) goto v0312;
    v0297 = stack[-2];
    v0296 = elt(env, 18); // structfetch
    v0296 = Leqcar(nil, v0297, v0296);
    env = stack[-6];
    goto v0312;

v0308:
    v0296 = qvalue(elt(env, 8)); // nil
    goto v0309;

v0305:
    v0296 = qvalue(elt(env, 7)); // t
    goto v0306;

v0304:
    v0296 = qvalue(elt(env, 8)); // nil
    goto v0306;

v0303:
    v0296 = qvalue(elt(env, 8)); // nil
    goto v0306;

v0165:
    v0296 = qvalue(elt(env, 8)); // nil
    goto v0301;

v0030:
    v0296 = stack[-2];
    if (symbolp(v0296)) goto v0316;
    v0297 = stack[-2];
    v0296 = elt(env, 9); // "assignment"
    {
        popv(7);
        fn = elt(env, 25); // typerr
        return (*qfn2(fn))(qenv(fn), v0297, v0296);
    }

v0316:
    v0297 = stack[-2];
    v0296 = elt(env, 22); // reserved
    v0296 = Lflagp(nil, v0297, v0296);
    env = stack[-6];
    if (v0296 == nil) goto v0317;
    v0297 = stack[-2];
    v0296 = stack[-4];
    v0296 = Latsoc(nil, v0297, v0296);
    v0296 = (v0296 == nil ? lisp_true : nil);
    goto v0318;

v0318:
    if (v0296 == nil) goto v0319;
    v0296 = stack[-2];
    {
        popv(7);
        fn = elt(env, 34); // rsverr
        return (*qfn1(fn))(qenv(fn), v0296);
    }

v0319:
    v0296 = stack[-2];
    if (!symbolp(v0296)) v0296 = nil;
    else { v0296 = qfastgets(v0296);
           if (v0296 != nil) { v0296 = elt(v0296, 17); // share
#ifdef RECORD_GET
             if (v0296 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0296 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0296 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0296 == SPID_NOPROP) v0296 = nil; else v0296 = lisp_true; }}
#endif
    if (v0296 == nil) goto v0320;
    v0297 = stack[-2];
    v0296 = stack[-4];
    fn = elt(env, 35); // symbid
    v0297 = (*qfn2(fn))(qenv(fn), v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0296 = stack[-5];
    {
        popv(7);
        fn = elt(env, 36); // mksetshare
        return (*qfn2(fn))(qenv(fn), v0297, v0296);
    }

v0320:
    v0297 = stack[-3];
    v0296 = elt(env, 2); // symbolic
    if (v0297 == v0296) goto v0321;
    v0296 = stack[-1];
    if (!(v0296 == nil)) goto v0322;
    v0297 = stack[-5];
    v0296 = elt(env, 1); // quote
    v0296 = Leqcar(nil, v0297, v0296);
    env = stack[-6];
    goto v0322;

v0322:
    if (v0296 == nil) goto v0323;
    v0297 = stack[-2];
    v0296 = stack[-4];
    fn = elt(env, 35); // symbid
    v0297 = (*qfn2(fn))(qenv(fn), v0297, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0296 = stack[-5];
    {
        popv(7);
        fn = elt(env, 37); // mksetq
        return (*qfn2(fn))(qenv(fn), v0297, v0296);
    }

v0323:
    v0296 = stack[0];
    v0296 = qcdr(v0296);
    v0296 = qcar(v0296);
    v0296 = Lsimple_vectorp(nil, v0296);
    env = stack[-6];
    if (!(v0296 == nil)) goto v0324;
    v0296 = stack[0];
    v0296 = qcdr(v0296);
    v0297 = qcar(v0296);
    v0296 = elt(env, 12); // vecfn
    v0296 = Lflagpcar(nil, v0297, v0296);
    env = stack[-6];
    if (!(v0296 == nil)) goto v0324;
    stack[0] = elt(env, 20); // setk
    v0296 = stack[-2];
    v0297 = Lmkquote(nil, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    v0296 = stack[-5];
    {
        LispObject v0325 = stack[0];
        popv(7);
        return list3(v0325, v0297, v0296);
    }

v0324:
    stack[-1] = elt(env, 23); // setv
    v0296 = stack[-2];
    v0297 = Lmkquote(nil, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    v0296 = stack[0];
    v0296 = qcdr(v0296);
    v0296 = qcar(v0296);
    {
        LispObject v0326 = stack[-1];
        popv(7);
        return list3(v0326, v0297, v0296);
    }

v0321:
    v0296 = qvalue(elt(env, 7)); // t
    goto v0322;

v0317:
    v0296 = qvalue(elt(env, 8)); // nil
    goto v0318;

v0010:
    v0296 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0296 = (LispObject)zerop(v0296);
    v0296 = v0296 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0296 == nil)) goto v0170;
    v0296 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    goto v0170;

v0170:
    v0296 = elt(env, 6); // "+++ Assign via inline or smacro: "
    v0296 = Lprinc(nil, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    v0296 = stack[-2];
    v0296 = Lprint(nil, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0300;
    env = stack[-6];
    goto v0009;

v0168:
    v0296 = qvalue(elt(env, 8)); // nil
    goto v0046;
// error exit handlers
v0300:
    popv(7);
    return nil;
}



// Code for reduce

static LispObject CC_reduce(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0014, v0063, v0030;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce");
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
    v0014 = v0000;
// end of prologue
    stack[0] = v0014;
    v0014 = qvalue(elt(env, 1)); // !*yyy
    if (v0014 == nil) goto v0033;
    v0063 = stack[0];
    v0014 = stack[-1];
    fn = elt(env, 3); // reduce!-ratios
    v0014 = (*qfn2(fn))(qenv(fn), v0063, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    stack[0] = v0014;
    goto v0033;

v0033:
    v0014 = stack[-1];
    fn = elt(env, 4); // set!-weights
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    stack[-2] = v0014;
    v0014 = qvalue(elt(env, 2)); // !*xxx
    if (v0014 == nil) goto v0069;
    v0030 = stack[0];
    v0063 = stack[-1];
    v0014 = stack[-2];
    fn = elt(env, 5); // reduce!-columns
    v0014 = (*qfnn(fn))(qenv(fn), 3, v0030, v0063, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    stack[0] = v0014;
    goto v0069;

v0069:
    v0014 = qvalue(elt(env, 2)); // !*xxx
    if (v0014 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0030 = stack[0];
    v0063 = stack[-1];
    v0014 = stack[-2];
    fn = elt(env, 6); // reduce!-weights
    v0014 = (*qfnn(fn))(qenv(fn), 3, v0030, v0063, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    stack[0] = v0014;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }
// error exit handlers
v0048:
    popv(4);
    return nil;
}



// Code for fs!:minusp!:

static LispObject CC_fsTminuspT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0045;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0045 = v0000;
// end of prologue
    v0045 = qcdr(v0045);
    {
        fn = elt(env, 1); // fs!:minusp
        return (*qfn1(fn))(qenv(fn), v0045);
    }
}



// Code for giintgcd

static LispObject CC_giintgcd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0012, v0295, v0180, v0327;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for giintgcd");
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
    v0295 = v0001;
    v0180 = v0000;
// end of prologue

v0019:
    v0327 = v0295;
    v0012 = (LispObject)17; // 1
    if (v0327 == v0012) goto v0033;
    v0012 = v0180;
    if (v0012 == nil) { popv(2); return onevalue(v0295); }
    v0012 = v0180;
    if (!consp(v0012)) goto v0020;
    v0327 = v0180;
    v0012 = elt(env, 1); // !:gi!:
    if (!consp(v0327)) goto v0049;
    v0327 = qcar(v0327);
    if (!(v0327 == v0012)) goto v0049;
    v0012 = v0180;
    v0012 = qcdr(v0012);
    stack[0] = qcar(v0012);
    v0012 = v0180;
    v0012 = qcdr(v0012);
    v0012 = qcdr(v0012);
    v0012 = Lgcd(nil, v0012, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    {
        LispObject v0196 = stack[0];
        popv(2);
        return Lgcd(nil, v0196, v0012);
    }

v0049:
    v0012 = v0180;
    v0012 = qcar(v0012);
    v0012 = qcdr(v0012);
    stack[0] = v0012;
    v0012 = v0180;
    v0012 = qcdr(v0012);
    v0012 = CC_giintgcd(env, v0012, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-1];
    v0295 = v0012;
    v0012 = stack[0];
    v0180 = v0012;
    goto v0019;

v0020:
    v0012 = v0180;
        popv(2);
        return Lgcd(nil, v0012, v0295);

v0033:
    v0012 = (LispObject)17; // 1
    { popv(2); return onevalue(v0012); }
// error exit handlers
v0205:
    popv(2);
    return nil;
}



// Code for maxfrom

static LispObject CC_maxfrom(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0068, v0192;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxfrom");
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
    v0068 = v0001;
    v0192 = v0000;
// end of prologue
    stack[0] = v0192;
    v0192 = add1(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0068 = (LispObject)1; // 0
    {
        LispObject v0195 = stack[0];
        popv(2);
        fn = elt(env, 1); // maxfrom1
        return (*qfnn(fn))(qenv(fn), 3, v0195, v0192, v0068);
    }
// error exit handlers
v0053:
    popv(2);
    return nil;
}



// Code for mk!+equation

static LispObject CC_mkLequation(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0192, v0178, v0053;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+equation");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0192 = v0001;
    v0178 = v0000;
// end of prologue
    v0053 = elt(env, 1); // equal
    return list3(v0053, v0178, v0192);
}



// Code for cl_smsimpl!-junct

static LispObject CC_cl_smsimplKjunct(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0097, v0098, v0293, v0164, v0292, v0333, v0219;
    LispObject fn;
    LispObject v0004, v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_smsimpl-junct");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_smsimpl-junct");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0052,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0004;
    stack[-6] = v0052;
    stack[0] = v0001;
    stack[-7] = v0000;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    v0097 = qvalue(elt(env, 1)); // !*rlsism
    if (v0097 == nil) goto v0053;
    v0097 = stack[-6];
    fn = elt(env, 5); // rl_smcpknowl
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-9];
    stack[-2] = v0097;
    v0293 = elt(env, 3); // false
    v0098 = stack[-7];
    v0097 = elt(env, 4); // and
    v0097 = (v0098 == v0097 ? lisp_true : nil);
    fn = elt(env, 6); // cl_cflip
    v0097 = (*qfn2(fn))(qenv(fn), v0293, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-9];
    stack[-8] = v0097;
    v0097 = stack[0];
    stack[-1] = v0097;
    goto v0194;

v0194:
    v0097 = stack[-1];
    if (v0097 == nil) goto v0006;
    v0097 = stack[-1];
    v0097 = qcar(v0097);
    stack[0] = v0097;
    v0097 = stack[0];
    fn = elt(env, 7); // cl_atfp
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-9];
    if (v0097 == nil) goto v0103;
    v0098 = stack[0];
    v0097 = stack[-7];
    fn = elt(env, 8); // cl_simplat
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-9];
    goto v0049;

v0049:
    stack[0] = v0097;
    v0097 = stack[0];
    fn = elt(env, 7); // cl_atfp
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-9];
    if (v0097 == nil) goto v0008;
    v0098 = stack[0];
    v0097 = stack[-4];
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-9];
    stack[-4] = v0097;
    goto v0180;

v0180:
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[-1] = v0097;
    goto v0194;

v0008:
    v0098 = stack[0];
    v0097 = stack[-3];
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-9];
    stack[-3] = v0097;
    goto v0180;

v0103:
    v0097 = stack[0];
    goto v0049;

v0006:
    v0164 = stack[-7];
    v0293 = stack[-4];
    v0098 = stack[-2];
    v0097 = stack[-5];
    fn = elt(env, 9); // rl_smupdknowl
    v0097 = (*qfnn(fn))(qenv(fn), 4, v0164, v0293, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-9];
    stack[-2] = v0097;
    v0098 = stack[-2];
    v0097 = elt(env, 3); // false
    if (v0098 == v0097) goto v0023;
    v0219 = stack[-7];
    v0333 = stack[-4];
    v0097 = stack[-3];
    v0292 = Lnreverse(nil, v0097);
    env = stack[-9];
    v0164 = stack[-6];
    v0293 = stack[-2];
    v0098 = stack[-5];
    v0097 = stack[-8];
    {
        popv(10);
        fn = elt(env, 10); // cl_smsimpl!-junct1
        return (*qfnn(fn))(qenv(fn), 7, v0219, v0333, v0292, v0164, v0293, v0098, v0097);
    }

v0023:
    v0097 = stack[-8];
    popv(10);
    return ncons(v0097);

v0053:
    v0164 = stack[0];
    v0293 = stack[-5];
    v0098 = stack[-7];
    v0097 = qvalue(elt(env, 2)); // nil
    {
        popv(10);
        fn = elt(env, 11); // cl_gand!-col
        return (*qfnn(fn))(qenv(fn), 4, v0164, v0293, v0098, v0097);
    }
// error exit handlers
v0334:
    popv(10);
    return nil;
}



// Code for sfto_qsubhor1

static LispObject CC_sfto_qsubhor1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0104, v0031;
    LispObject fn;
    LispObject v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sfto_qsubhor1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_qsubhor1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0052);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0052;
    v0104 = v0001;
    stack[0] = v0000;
// end of prologue
    v0031 = stack[0];
    fn = elt(env, 2); // sfto_mvartest
    v0104 = (*qfn2(fn))(qenv(fn), v0031, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    if (v0104 == nil) goto v0020;
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    stack[-4] = v0104;
    v0104 = stack[-1];
    v0104 = qcdr(v0104);
    stack[-3] = v0104;
    v0104 = (LispObject)17; // 1
    stack[-2] = v0104;
    v0104 = stack[0];
    fn = elt(env, 3); // coeffs
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0031 = v0104;
    v0104 = v0031;
    v0104 = qcar(v0104);
    stack[-5] = v0104;
    v0104 = v0031;
    v0104 = qcdr(v0104);
    stack[-1] = v0104;
    goto v0043;

v0043:
    v0104 = stack[-1];
    if (v0104 == nil) goto v0201;
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    stack[0] = v0104;
    v0031 = stack[-2];
    v0104 = stack[-3];
    v0104 = times2(v0031, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    stack[-2] = v0104;
    v0031 = stack[0];
    v0104 = stack[-2];
    fn = elt(env, 4); // multf
    stack[0] = (*qfn2(fn))(qenv(fn), v0031, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    v0031 = stack[-5];
    v0104 = stack[-4];
    fn = elt(env, 4); // multf
    v0104 = (*qfn2(fn))(qenv(fn), v0031, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    fn = elt(env, 5); // addf
    v0104 = (*qfn2(fn))(qenv(fn), stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-6];
    stack[-5] = v0104;
    v0104 = stack[-1];
    v0104 = qcdr(v0104);
    stack[-1] = v0104;
    goto v0043;

v0201:
    v0104 = stack[-5];
    fn = elt(env, 6); // sfto_dprpartksf
    v0031 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    v0104 = (LispObject)17; // 1
    popv(7);
    return cons(v0031, v0104);

v0020:
    v0031 = stack[0];
    v0104 = (LispObject)17; // 1
    popv(7);
    return cons(v0031, v0104);
// error exit handlers
v0206:
    popv(7);
    return nil;
}



// Code for upperlimitrd

static LispObject CC_upperlimitrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0036, v0021;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "upperlimitrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for upperlimitrd");
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
    fn = elt(env, 4); // mathml
    v0036 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-1];
    stack[0] = v0036;
    fn = elt(env, 5); // lex
    v0036 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-1];
    v0021 = qvalue(elt(env, 1)); // char
    v0036 = elt(env, 2); // (!/ u p l i m i t)
    if (equal(v0021, v0036)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0021 = elt(env, 3); // "</uplimit>"
    v0036 = (LispObject)33; // 2
    fn = elt(env, 6); // errorml
    v0036 = (*qfn2(fn))(qenv(fn), v0021, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    v0036 = nil;
    { popv(2); return onevalue(v0036); }
// error exit handlers
v0034:
    popv(2);
    return nil;
}



// Code for prlist

static LispObject CC_prlist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0055;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prlist");
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
    v0055 = nil;
    goto v0045;

v0045:
    v0051 = stack[0];
    if (v0051 == nil) goto v0074;
    v0051 = stack[0];
    v0051 = qcar(v0051);
    v0051 = Lconsp(nil, v0051);
    env = stack[-1];
    if (v0051 == nil) goto v0021;
    v0051 = stack[0];
    v0051 = qcar(v0051);
    v0051 = cons(v0051, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    v0055 = v0051;
    v0051 = stack[0];
    v0051 = qcdr(v0051);
    stack[0] = v0051;
    goto v0045;

v0021:
    v0051 = stack[0];
    v0051 = qcdr(v0051);
    stack[0] = v0051;
    goto v0045;

v0074:
    v0051 = v0055;
    {
        popv(2);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0051);
    }
// error exit handlers
v0015:
    popv(2);
    return nil;
}



// Code for assgnpri

static LispObject CC_assgnpri(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0339, v0079, v0144;
    LispObject fn;
    LispObject v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assgnpri");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assgnpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0052);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0052;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0339 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 2)) = v0339; // overflowed!*
    qvalue(elt(env, 3)) = v0339; // testing!-width!*
    v0339 = stack[-3];
    if (!(v0339 == nil)) goto v0032;
    v0339 = (LispObject)1; // 0
    stack[-3] = v0339;
    goto v0032;

v0032:
    v0339 = qvalue(elt(env, 4)); // !*nero
    if (v0339 == nil) goto v0192;
    v0079 = stack[-3];
    v0339 = (LispObject)1; // 0
    if (!(v0079 == v0339)) goto v0192;
    v0339 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0339); }

v0192:
    v0339 = qvalue(elt(env, 5)); // !*tex
    if (v0339 == nil) goto v0051;
    v0144 = stack[-3];
    v0079 = stack[-2];
    v0339 = stack[-1];
    {
        popv(6);
        fn = elt(env, 22); // texpri
        return (*qfnn(fn))(qenv(fn), 3, v0144, v0079, v0339);
    }

v0051:
    v0339 = elt(env, 6); // vecp
    fn = elt(env, 23); // getd
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    if (v0339 == nil) goto v0340;
    v0339 = stack[-3];
    fn = elt(env, 6); // vecp
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    if (v0339 == nil) goto v0340;
    v0079 = stack[-3];
    v0339 = elt(env, 7); // mat
    {
        popv(6);
        fn = elt(env, 24); // vecpri
        return (*qfn2(fn))(qenv(fn), v0079, v0339);
    }

v0340:
    v0079 = elt(env, 8); // csl
    v0339 = qvalue(elt(env, 9)); // lispsystem!*
    v0339 = Lmemq(nil, v0079, v0339);
    if (v0339 == nil) goto v0049;
    v0339 = elt(env, 10); // math!-display
    fn = elt(env, 23); // getd
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    if (v0339 == nil) goto v0049;
    v0339 = (LispObject)1; // 0
    fn = elt(env, 10); // math!-display
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    if (v0339 == nil) goto v0049;
    v0079 = qvalue(elt(env, 11)); // outputhandler!*
    v0339 = elt(env, 12); // fancy!-output
    if (v0079 == v0339) goto v0198;
    v0339 = qvalue(elt(env, 1)); // nil
    goto v0197;

v0197:
    if (v0339 == nil) goto v0049;
    v0339 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 25); // fmp!-switch
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    v0339 = qvalue(elt(env, 13)); // t
    stack[-4] = v0339;
    goto v0049;

v0049:
    v0339 = stack[-3];
    fn = elt(env, 26); // getrtype
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    v0144 = v0339;
    if (v0339 == nil) goto v0304;
    v0079 = v0144;
    v0339 = elt(env, 14); // sprifn
    v0339 = Lflagp(nil, v0079, v0339);
    env = stack[-5];
    if (v0339 == nil) goto v0167;
    v0339 = qvalue(elt(env, 11)); // outputhandler!*
    v0339 = (v0339 == nil ? lisp_true : nil);
    goto v0169;

v0169:
    if (v0339 == nil) goto v0304;
    v0339 = stack[-2];
    if (v0339 == nil) goto v0341;
    v0144 = elt(env, 16); // setq
    v0339 = stack[-2];
    v0079 = qcar(v0339);
    v0339 = stack[-3];
    v0339 = list3(v0144, v0079, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    fn = elt(env, 27); // maprin
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0181;

v0181:
    v0339 = stack[-4];
    if (v0339 == nil) goto v0309;
    v0339 = qvalue(elt(env, 13)); // t
    fn = elt(env, 25); // fmp!-switch
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0309;

v0309:
    v0339 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0339); }

v0341:
    v0079 = v0144;
    v0339 = elt(env, 15); // tag
    v0339 = get(v0079, v0339);
    env = stack[-5];
    if (!symbolp(v0339)) v0079 = nil;
    else { v0079 = qfastgets(v0339);
           if (v0079 != nil) { v0079 = elt(v0079, 57); // prifn
#ifdef RECORD_GET
             if (v0079 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0079 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; }}
#endif
    v0339 = stack[-3];
    v0339 = Lapply1(nil, v0079, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0181;

v0304:
    v0079 = stack[-1];
    v0339 = elt(env, 17); // (first only)
    v0339 = Lmemq(nil, v0079, v0339);
    if (v0339 == nil) goto v0162;
    v0339 = qvalue(elt(env, 13)); // t
    fn = elt(env, 28); // terpri!*
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0162;

v0162:
    v0339 = stack[-2];
    fn = elt(env, 29); // evalvars
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    stack[-2] = v0339;
    v0339 = qvalue(elt(env, 18)); // !*fort
    if (v0339 == nil) goto v0342;
    v0144 = stack[-3];
    v0079 = stack[-2];
    v0339 = stack[-1];
    fn = elt(env, 30); // fvarpri
    v0339 = (*qfnn(fn))(qenv(fn), 3, v0144, v0079, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    v0339 = stack[-4];
    if (v0339 == nil) goto v0230;
    v0339 = qvalue(elt(env, 13)); // t
    fn = elt(env, 25); // fmp!-switch
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0230;

v0230:
    v0339 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0339); }

v0342:
    v0339 = stack[-2];
    if (v0339 == nil) goto v0086;
    stack[0] = elt(env, 16); // setq
    v0079 = stack[-2];
    v0339 = stack[-3];
    fn = elt(env, 31); // aconc
    v0339 = (*qfn2(fn))(qenv(fn), v0079, v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    v0339 = cons(stack[0], v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0215;

v0215:
    fn = elt(env, 27); // maprin
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    v0339 = stack[-1];
    if (v0339 == nil) goto v0082;
    v0079 = stack[-1];
    v0339 = elt(env, 19); // first
    v0339 = (v0079 == v0339 ? lisp_true : nil);
    goto v0343;

v0343:
    if (v0339 == nil) goto v0286;
    v0339 = stack[-4];
    if (v0339 == nil) goto v0117;
    v0339 = qvalue(elt(env, 13)); // t
    fn = elt(env, 25); // fmp!-switch
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0117;

v0117:
    v0339 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0339); }

v0286:
    v0339 = qvalue(elt(env, 20)); // !*nat
    if (!(v0339 == nil)) goto v0155;
    v0339 = elt(env, 21); // "$"
    fn = elt(env, 32); // prin2!*
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0155;

v0155:
    v0339 = qvalue(elt(env, 20)); // !*nat
    v0339 = (v0339 == nil ? lisp_true : nil);
    fn = elt(env, 28); // terpri!*
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0181;

v0082:
    v0339 = qvalue(elt(env, 13)); // t
    goto v0343;

v0086:
    v0339 = stack[-3];
    goto v0215;

v0167:
    v0339 = qvalue(elt(env, 1)); // nil
    goto v0169;

v0198:
    v0339 = stack[-3];
    fn = elt(env, 33); // would!-be!-huge
    v0339 = (*qfn1(fn))(qenv(fn), v0339);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-5];
    goto v0197;
// error exit handlers
v0224:
    popv(6);
    return nil;
}



// Code for extbrsea

static LispObject CC_extbrsea(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0107, v0108, v0109;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "extbrsea");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extbrsea");
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
    v0107 = qvalue(elt(env, 1)); // rowmin
    stack[-1] = v0107;
    goto v0068;

v0068:
    v0108 = qvalue(elt(env, 2)); // rowmax
    v0107 = stack[-1];
    v0107 = difference2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0107 = Lminusp(nil, v0107);
    env = stack[-2];
    if (v0107 == nil) goto v0190;
    fn = elt(env, 8); // initbrsea
    v0107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    fn = elt(env, 9); // extbrsea1
    v0107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    goto v0163;

v0163:
    fn = elt(env, 10); // expandprod
    v0107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0107 = qvalue(elt(env, 1)); // rowmin
    stack[-1] = v0107;
    goto v0292;

v0292:
    v0108 = qvalue(elt(env, 2)); // rowmax
    v0107 = stack[-1];
    v0107 = difference2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0107 = Lminusp(nil, v0107);
    env = stack[-2];
    if (v0107 == nil) goto v0289;
    fn = elt(env, 8); // initbrsea
    v0107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    fn = elt(env, 9); // extbrsea1
    v0107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    fn = elt(env, 11); // shrinkprod
    v0107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    if (!(v0107 == nil)) goto v0163;
    v0107 = nil;
    { popv(3); return onevalue(v0107); }

v0289:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0108 = qvalue(elt(env, 5)); // maxvar
    v0107 = stack[-1];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0108 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (LispObject)49; // 3
    v0108 = *(LispObject *)((char *)v0108 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (LispObject)-15; // -1
    if (v0108 == v0107) goto v0286;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0108 = qvalue(elt(env, 5)); // maxvar
    v0107 = stack[-1];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0108 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (LispObject)33; // 2
    v0108 = *(LispObject *)((char *)v0108 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = elt(env, 7); // times
    v0107 = (v0108 == v0107 ? lisp_true : nil);
    goto v0094;

v0094:
    if (v0107 == nil) goto v0357;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0108 = qvalue(elt(env, 5)); // maxvar
    v0107 = stack[-1];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0109 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0108 = (LispObject)1; // 0
    v0107 = qvalue(elt(env, 6)); // t
    *(LispObject *)((char *)v0109 + (CELL-TAG_VECTOR) + ((int32_t)v0108/(16/CELL))) = v0107;
    goto v0358;

v0358:
    v0107 = stack[-1];
    v0107 = add1(v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    stack[-1] = v0107;
    goto v0292;

v0357:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0108 = qvalue(elt(env, 5)); // maxvar
    v0107 = stack[-1];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0109 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0108 = (LispObject)1; // 0
    v0107 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0109 + (CELL-TAG_VECTOR) + ((int32_t)v0108/(16/CELL))) = v0107;
    goto v0358;

v0286:
    v0107 = qvalue(elt(env, 3)); // nil
    goto v0094;

v0190:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0108 = qvalue(elt(env, 5)); // maxvar
    v0107 = stack[-1];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0108 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (LispObject)49; // 3
    v0108 = *(LispObject *)((char *)v0108 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (LispObject)-15; // -1
    if (v0108 == v0107) goto v0021;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0108 = qvalue(elt(env, 5)); // maxvar
    v0107 = stack[-1];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0108 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (LispObject)49; // 3
    v0108 = *(LispObject *)((char *)v0108 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (LispObject)-31; // -2
    v0107 = (v0108 == v0107 ? lisp_true : nil);
    goto v0036;

v0036:
    if (v0107 == nil) goto v0359;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0108 = qvalue(elt(env, 5)); // maxvar
    v0107 = stack[-1];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0109 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0108 = (LispObject)1; // 0
    v0107 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0109 + (CELL-TAG_VECTOR) + ((int32_t)v0108/(16/CELL))) = v0107;
    goto v0069;

v0069:
    v0107 = stack[-1];
    v0107 = add1(v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    stack[-1] = v0107;
    goto v0068;

v0359:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0108 = qvalue(elt(env, 5)); // maxvar
    v0107 = stack[-1];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0109 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0108 = (LispObject)1; // 0
    v0107 = qvalue(elt(env, 6)); // t
    *(LispObject *)((char *)v0109 + (CELL-TAG_VECTOR) + ((int32_t)v0108/(16/CELL))) = v0107;
    goto v0069;

v0021:
    v0107 = qvalue(elt(env, 6)); // t
    goto v0036;
// error exit handlers
v0356:
    popv(3);
    return nil;
}



// Code for size_of_matrix

static LispObject CC_size_of_matrix(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for size_of_matrix");
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
    stack[-1] = (LispObject)-15; // -1
    v0021 = stack[0];
    v0021 = Llength(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-2];
    v0021 = plus2(stack[-1], v0021);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-2];
    stack[-1] = v0021;
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = qcar(v0021);
    v0021 = Llength(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    v0037 = stack[-1];
    popv(3);
    return list2(v0037, v0021);
// error exit handlers
v0051:
    popv(3);
    return nil;
}



// Code for add_item

static LispObject CC_add_item(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0047, v0048;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add_item");
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

v0045:
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    if (v0047 == nil) goto v0025;
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0048 = qcar(v0047);
    v0047 = stack[-1];
    v0047 = qcar(v0047);
    fn = elt(env, 3); // monordp
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    if (v0047 == nil) goto v0014;
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    v0047 = qcar(v0047);
    stack[0] = v0047;
    goto v0045;

v0014:
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0045;

v0025:
    v0048 = stack[0];
    v0047 = stack[-1];
    fn = elt(env, 4); // setcar
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[-1] = elt(env, 1); // !*xset!*
    stack[0] = qvalue(elt(env, 2)); // nil
    v0047 = elt(env, 1); // !*xset!*
    v0047 = ncons(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    v0047 = acons(stack[-1], stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    fn = elt(env, 5); // setcdr
    v0047 = (*qfn2(fn))(qenv(fn), stack[-2], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    v0047 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0047); }
// error exit handlers
v0010:
    popv(4);
    return nil;
}



// Code for list!-evaluate

static LispObject CC_listKevaluate(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0102, v0009, v0010;
    LispObject fn;
    LispObject v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "list-evaluate");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list-evaluate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0052);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0052;
    stack[-4] = v0001;
    v0102 = v0000;
// end of prologue
    stack[-5] = v0102;
    v0102 = stack[-5];
    if (v0102 == nil) goto v0025;
    v0102 = stack[-5];
    v0102 = qcar(v0102);
    v0010 = v0102;
    v0009 = stack[-4];
    v0102 = stack[-3];
    fn = elt(env, 2); // evaluate
    v0102 = (*qfnn(fn))(qenv(fn), 3, v0010, v0009, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    stack[-1] = v0102;
    stack[-2] = v0102;
    goto v0033;

v0033:
    v0102 = stack[-5];
    v0102 = qcdr(v0102);
    stack[-5] = v0102;
    v0102 = stack[-5];
    if (v0102 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0102 = stack[-5];
    v0102 = qcar(v0102);
    v0010 = v0102;
    v0009 = stack[-4];
    v0102 = stack[-3];
    fn = elt(env, 2); // evaluate
    v0102 = (*qfnn(fn))(qenv(fn), 3, v0010, v0009, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0102 = Lrplacd(nil, stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0033;

v0025:
    v0102 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0102); }
// error exit handlers
v0050:
    popv(7);
    return nil;
}



// Code for replace2_parents

static LispObject CC_replace2_parents(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0018, v0200;
    LispObject v0052, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace2_parents");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replace2_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0052,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0052);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0052;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0200 = stack[-2];
    v0018 = stack[0];
    v0018 = qcar(v0018);
    if (!(equal(v0200, v0018))) goto v0036;
    v0200 = stack[0];
    v0018 = stack[-1];
    v0018 = Lrplaca(nil, v0200, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    goto v0036;

v0036:
    v0200 = stack[-2];
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    if (equal(v0200, v0018)) goto v0016;
    v0018 = nil;
    { popv(3); return onevalue(v0018); }

v0016:
    v0200 = stack[0];
    v0018 = stack[-1];
        popv(3);
        return Lrplacd(nil, v0200, v0018);
// error exit handlers
v0042:
    popv(3);
    return nil;
}



// Code for redall

static LispObject CC_redall(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0119, v0147, v0283;
    LispObject fn;
    LispObject v0004, v0052, v0001;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "redall");
    va_start(aa, nargs);
    v0001 = va_arg(aa, LispObject);
    v0052 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for redall");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0052,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0001,v0052,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0004;
    v0147 = v0052;
    v0119 = v0001;
// end of prologue
    stack[-8] = qvalue(elt(env, 1)); // gg!*
    qvalue(elt(env, 1)) = nil; // gg!*
    qvalue(elt(env, 1)) = v0119; // gg!*
    v0119 = v0147;
    stack[-6] = v0119;
    v0119 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 3)) = v0119; // shortway!*
    qvalue(elt(env, 4)) = v0119; // thirdway!*
    v0119 = qvalue(elt(env, 5)); // t
    stack[-1] = v0119;
    goto v0065;

v0065:
    v0119 = stack[-6];
    if (v0119 == nil) goto v0054;
    v0119 = stack[-6];
    v0119 = Lreverse(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = qcar(v0119);
    stack[-5] = v0119;
    v0147 = stack[-5];
    v0119 = stack[-6];
    v0119 = Ldelete(nil, v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    stack[-6] = v0119;
    v0119 = stack[-5];
    v0119 = qcar(v0119);
    stack[-2] = v0119;
    v0147 = qvalue(elt(env, 6)); // gv!*
    v0119 = stack[-2];
    v0119 = *(LispObject *)((char *)v0147 + (CELL-TAG_VECTOR) + ((int32_t)v0119/(16/CELL)));
    stack[-4] = v0119;
    v0119 = qvalue(elt(env, 7)); // path
    if (v0119 == nil) goto v0011;
    v0119 = stack[-1];
    if (v0119 == nil) goto v0010;
    v0119 = stack[-4];
    fn = elt(env, 12); // ljet
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = Lprinc(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = elt(env, 8); // " ==> "
    v0119 = Lprinc(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    goto v0011;

v0011:
    stack[-3] = qvalue(elt(env, 6)); // gv!*
    stack[0] = stack[-2];
    v0283 = stack[-4];
    v0147 = qvalue(elt(env, 1)); // gg!*
    v0119 = stack[-7];
    fn = elt(env, 13); // nf
    v0119 = (*qfnn(fn))(qenv(fn), 3, v0283, v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0119;
    stack[-5] = v0119;
    v0119 = stack[-5];
    if (v0119 == nil) goto v0332;
    v0119 = stack[-5];
    fn = elt(env, 12); // ljet
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    goto v0008;

v0008:
    stack[-3] = v0119;
    v0119 = qvalue(elt(env, 7)); // path
    if (v0119 == nil) goto v0006;
    v0119 = stack[-3];
    v0119 = Lprinc(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    goto v0006;

v0006:
    v0119 = stack[-5];
    if (v0119 == nil) goto v0065;
    v0119 = stack[-3];
    fn = elt(env, 14); // ord
    v0147 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = (LispObject)1; // 0
    if (v0147 == v0119) goto v0365;
    v0119 = stack[-5];
    fn = elt(env, 12); // ljet
    stack[0] = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = stack[-4];
    fn = elt(env, 12); // ljet
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    if (equal(stack[0], v0119)) goto v0341;
    v0119 = qvalue(elt(env, 5)); // t
    qvalue(elt(env, 3)) = v0119; // shortway!*
    goto v0341;

v0341:
    v0119 = stack[-1];
    if (v0119 == nil) goto v0306;
    v0119 = qvalue(elt(env, 2)); // nil
    goto v0164;

v0164:
    if (v0119 == nil) goto v0227;
    v0119 = qvalue(elt(env, 5)); // t
    qvalue(elt(env, 4)) = v0119; // thirdway!*
    goto v0227;

v0227:
    v0119 = qvalue(elt(env, 1)); // gg!*
    stack[-4] = v0119;
    goto v0366;

v0366:
    v0119 = stack[-4];
    if (v0119 == nil) goto v0210;
    v0119 = stack[-4];
    v0119 = qcar(v0119);
    stack[-1] = v0119;
    v0147 = stack[-3];
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    fn = elt(env, 15); // dd
    stack[0] = (*qfn2(fn))(qenv(fn), v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0147 = stack[-7];
    v0119 = (LispObject)33; // 2
    v0119 = plus2(v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = (LispObject)geq2(stack[0], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0119 = v0119 ? lisp_true : nil;
    env = stack[-9];
    if (v0119 == nil) goto v0158;
    v0147 = stack[-1];
    v0119 = qvalue(elt(env, 1)); // gg!*
    v0119 = Ldelete(nil, v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0119; // gg!*
    v0147 = stack[-1];
    v0119 = stack[-6];
    fn = elt(env, 16); // insert
    v0119 = (*qfn2(fn))(qenv(fn), v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    stack[-6] = v0119;
    v0283 = qvalue(elt(env, 11)); // bv!*
    v0119 = stack[-1];
    v0147 = qcar(v0119);
    v0119 = qvalue(elt(env, 5)); // t
    *(LispObject *)((char *)v0283 + (CELL-TAG_VECTOR) + ((int32_t)v0147/(16/CELL))) = v0119;
    goto v0158;

v0158:
    v0119 = stack[-4];
    v0119 = qcdr(v0119);
    stack[-4] = v0119;
    goto v0366;

v0210:
    v0147 = stack[-2];
    v0119 = stack[-3];
    v0147 = cons(v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = qvalue(elt(env, 1)); // gg!*
    fn = elt(env, 16); // insert
    v0119 = (*qfn2(fn))(qenv(fn), v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0119; // gg!*
    v0119 = qvalue(elt(env, 2)); // nil
    stack[-1] = v0119;
    goto v0065;

v0306:
    v0147 = stack[-5];
    v0119 = stack[-4];
    v0119 = Lneq(nil, v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    goto v0164;

v0365:
    v0147 = stack[-5];
    v0119 = qvalue(elt(env, 10)); // conds!*
    v0119 = cons(v0147, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    qvalue(elt(env, 10)) = v0119; // conds!*
    goto v0065;

v0332:
    v0119 = (LispObject)1; // 0
    goto v0008;

v0010:
    v0119 = stack[-4];
    fn = elt(env, 12); // ljet
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = Lprinc(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    v0119 = elt(env, 9); // " --> "
    v0119 = Lprinc(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-9];
    goto v0011;

v0054:
    v0119 = qvalue(elt(env, 1)); // gg!*
    qvalue(elt(env, 1)) = stack[-8]; // gg!*
    { popv(10); return onevalue(v0119); }
// error exit handlers
v0144:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; // gg!*
    popv(10);
    return nil;
}



// Code for fd2q

static LispObject CC_fd2q(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0327, v0204;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fd2q");
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

v0044:
    v0327 = stack[0];
    if (!consp(v0327)) goto v0019;
    v0327 = stack[0];
    v0204 = qcar(v0327);
    v0327 = elt(env, 1); // !:ar!:
    if (v0204 == v0327) goto v0053;
    v0327 = stack[0];
    v0204 = qcar(v0327);
    v0327 = elt(env, 2); // !:rn!:
    if (v0204 == v0327) goto v0037;
    v0327 = stack[0];
    v0327 = qcar(v0327);
    v0204 = qcar(v0327);
    v0327 = (LispObject)17; // 1
    v0327 = cons(v0204, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0204 = ncons(v0327);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0327 = (LispObject)17; // 1
    stack[-1] = cons(v0204, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0327 = stack[0];
    v0327 = qcar(v0327);
    v0327 = qcdr(v0327);
    v0327 = CC_fd2q(env, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    fn = elt(env, 3); // multsq
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0327);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0327 = stack[0];
    v0327 = qcdr(v0327);
    v0327 = CC_fd2q(env, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    {
        LispObject v0198 = stack[-1];
        popv(3);
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(qenv(fn), v0198, v0327);
    }

v0037:
    v0327 = stack[0];
    v0327 = qcdr(v0327);
    { popv(3); return onevalue(v0327); }

v0053:
    v0327 = stack[0];
    v0327 = qcdr(v0327);
    stack[0] = v0327;
    goto v0044;

v0019:
    v0204 = stack[0];
    v0327 = (LispObject)17; // 1
    popv(3);
    return cons(v0204, v0327);
// error exit handlers
v0197:
    popv(3);
    return nil;
}



// Code for basic!-kern

static LispObject CC_basicKkern(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0037, v0034;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for basic-kern");
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
    v0034 = v0000;
// end of prologue
    v0037 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0037;
    v0037 = v0034;
    stack[0] = v0037;
    goto v0040;

v0040:
    v0037 = stack[0];
    if (v0037 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0037 = stack[0];
    v0037 = qcar(v0037);
    fn = elt(env, 2); // basic!-kern1
    v0034 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    v0037 = stack[-1];
    fn = elt(env, 3); // union
    v0037 = (*qfn2(fn))(qenv(fn), v0034, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    stack[-1] = v0037;
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    stack[0] = v0037;
    goto v0040;
// error exit handlers
v0055:
    popv(3);
    return nil;
}



// Code for algmodep

static LispObject CC_algmodep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0195, v0174;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for algmodep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0174 = v0000;
// end of prologue
    v0195 = v0174;
    if (!consp(v0195)) goto v0192;
    v0195 = v0174;
    v0195 = qcar(v0195);
    v0174 = elt(env, 1); // (aeval aeval!*)
    v0195 = Lmemq(nil, v0195, v0174);
    return onevalue(v0195);

v0192:
    v0195 = qvalue(elt(env, 2)); // nil
    return onevalue(v0195);
}



// Code for tayfkern

static LispObject CC_tayfkern(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0049, v0102, v0009;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayfkern");
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
    v0009 = v0000;
// end of prologue
    v0049 = qvalue(elt(env, 1)); // !*tayinternal!*
    if (!(v0049 == nil)) { popv(3); return onevalue(v0009); }
    v0049 = elt(env, 2); // taylor!*
    if (!symbolp(v0049)) v0049 = nil;
    else { v0049 = qfastgets(v0049);
           if (v0049 != nil) { v0049 = elt(v0049, 24); // klist
#ifdef RECORD_GET
             if (v0049 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0049 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0049 == SPID_NOPROP) v0049 = nil; }}
#endif
    stack[0] = v0049;
    v0102 = v0009;
    v0049 = stack[0];
    v0049 = Lassoc(nil, v0102, v0049);
    stack[-1] = v0049;
    v0049 = stack[-1];
    if (!(v0049 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0102 = v0009;
    v0049 = qvalue(elt(env, 3)); // nil
    v0049 = list2(v0102, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0367;
    env = stack[-2];
    stack[-1] = v0049;
    v0102 = stack[-1];
    v0049 = stack[0];
    fn = elt(env, 7); // ordad
    v0049 = (*qfn2(fn))(qenv(fn), v0102, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0367;
    env = stack[-2];
    stack[0] = v0049;
    v0102 = elt(env, 4); // (taylor!*)
    v0049 = qvalue(elt(env, 5)); // kprops!*
    fn = elt(env, 8); // union
    v0049 = (*qfn2(fn))(qenv(fn), v0102, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0367;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0049; // kprops!*
    v0009 = elt(env, 2); // taylor!*
    v0102 = elt(env, 6); // klist
    v0049 = stack[0];
    v0049 = Lputprop(nil, 3, v0009, v0102, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0367;
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0367:
    popv(3);
    return nil;
}



// Code for depend!-f

static LispObject CC_dependKf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0063, v0030;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depend-f");
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

v0368:
    v0063 = stack[-1];
    if (!consp(v0063)) goto v0033;
    v0063 = stack[-1];
    v0063 = qcar(v0063);
    v0063 = (consp(v0063) ? nil : lisp_true);
    goto v0074;

v0074:
    if (v0063 == nil) goto v0193;
    v0063 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0063); }

v0193:
    v0063 = stack[-1];
    v0063 = qcar(v0063);
    v0063 = qcar(v0063);
    v0030 = qcar(v0063);
    v0063 = stack[0];
    fn = elt(env, 3); // depend!-p
    v0063 = (*qfn2(fn))(qenv(fn), v0030, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    if (!(v0063 == nil)) { popv(3); return onevalue(v0063); }
    v0063 = stack[-1];
    v0063 = qcar(v0063);
    v0030 = qcdr(v0063);
    v0063 = stack[0];
    v0063 = CC_dependKf(env, v0030, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    if (!(v0063 == nil)) { popv(3); return onevalue(v0063); }
    v0063 = stack[-1];
    v0030 = qcdr(v0063);
    v0063 = stack[0];
    stack[-1] = v0030;
    stack[0] = v0063;
    goto v0368;

v0033:
    v0063 = qvalue(elt(env, 1)); // t
    goto v0074;
// error exit handlers
v0047:
    popv(3);
    return nil;
}



// Code for pasf_fact

static LispObject CC_pasf_fact(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0342, v0157, v0370;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_fact");
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
    stack[-1] = v0000;
// end of prologue
    v0157 = stack[-1];
    v0342 = elt(env, 1); // true
    if (v0157 == v0342) goto v0025;
    v0157 = stack[-1];
    v0342 = elt(env, 3); // false
    v0342 = (v0157 == v0342 ? lisp_true : nil);
    goto v0027;

v0027:
    if (!(v0342 == nil)) { LispObject res = stack[-1]; popv(7); return onevalue(res); }
    v0342 = stack[-1];
    v0342 = qcar(v0342);
    stack[-5] = v0342;
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    v0342 = qcar(v0342);
    fn = elt(env, 10); // fctrf
    v0342 = (*qfn1(fn))(qenv(fn), v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    stack[0] = v0342;
    v0342 = stack[0];
    v0157 = Llength(nil, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0342 = (LispObject)49; // 3
    v0342 = (LispObject)lessp2(v0157, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    v0342 = v0342 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0342 == nil)) { LispObject res = stack[-1]; popv(7); return onevalue(res); }
    v0157 = stack[-5];
    v0342 = elt(env, 4); // (equal neq)
    v0342 = Lmemq(nil, v0157, v0342);
    if (v0342 == nil) goto v0228;
    v0157 = stack[-5];
    v0342 = elt(env, 5); // equal
    if (v0157 == v0342) goto v0073;
    v0342 = elt(env, 7); // and
    stack[-4] = v0342;
    goto v0112;

v0112:
    v0342 = stack[0];
    v0342 = qcdr(v0342);
    stack[-3] = v0342;
    v0342 = stack[-3];
    if (v0342 == nil) goto v0202;
    v0342 = stack[-3];
    v0342 = qcar(v0342);
    v0370 = stack[-5];
    v0157 = qcar(v0342);
    v0342 = qvalue(elt(env, 8)); // nil
    v0342 = list3(v0370, v0157, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0342 = ncons(v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    stack[-1] = v0342;
    stack[-2] = v0342;
    goto v0170;

v0170:
    v0342 = stack[-3];
    v0342 = qcdr(v0342);
    stack[-3] = v0342;
    v0342 = stack[-3];
    if (v0342 == nil) goto v0023;
    stack[0] = stack[-1];
    v0342 = stack[-3];
    v0342 = qcar(v0342);
    v0370 = stack[-5];
    v0157 = qcar(v0342);
    v0342 = qvalue(elt(env, 8)); // nil
    v0342 = list3(v0370, v0157, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0342 = ncons(v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0342 = Lrplacd(nil, stack[0], v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    stack[-1] = v0342;
    goto v0170;

v0023:
    v0342 = stack[-2];
    goto v0062;

v0062:
    {
        LispObject v0145 = stack[-4];
        popv(7);
        return cons(v0145, v0342);
    }

v0202:
    v0342 = qvalue(elt(env, 8)); // nil
    goto v0062;

v0073:
    v0342 = elt(env, 6); // or
    stack[-4] = v0342;
    goto v0112;

v0228:
    v0157 = stack[-5];
    v0342 = elt(env, 9); // (leq lessp geq greaterp)
    v0342 = Lmemq(nil, v0157, v0342);
    if (v0342 == nil) { LispObject res = stack[-1]; popv(7); return onevalue(res); }
    v0342 = stack[0];
    stack[-1] = qcdr(v0342);
    v0342 = stack[0];
    v0342 = qcar(v0342);
    fn = elt(env, 11); // minusf
    v0342 = (*qfn1(fn))(qenv(fn), v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    if (v0342 == nil) goto v0305;
    v0342 = stack[-5];
    fn = elt(env, 12); // pasf_anegrel
    v0342 = (*qfn1(fn))(qenv(fn), v0342);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    goto v0161;

v0161:
    {
        LispObject v0188 = stack[-1];
        popv(7);
        fn = elt(env, 13); // pasf_fact1
        return (*qfn2(fn))(qenv(fn), v0188, v0342);
    }

v0305:
    v0342 = stack[-5];
    goto v0161;

v0025:
    v0342 = qvalue(elt(env, 2)); // t
    goto v0027;
// error exit handlers
v0093:
    popv(7);
    return nil;
}



// Code for intervalrd

static LispObject CC_intervalrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0016, v0038;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "intervalrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intervalrd");
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
    fn = elt(env, 4); // mathml
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    stack[-1] = v0016;
    fn = elt(env, 4); // mathml
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    stack[0] = v0016;
    fn = elt(env, 5); // lex
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    v0038 = qvalue(elt(env, 1)); // char
    v0016 = elt(env, 2); // (!/ i n t e r v a l)
    if (equal(v0038, v0016)) goto v0174;
    v0038 = elt(env, 3); // "</interval>"
    v0016 = (LispObject)33; // 2
    fn = elt(env, 6); // errorml
    v0016 = (*qfn2(fn))(qenv(fn), v0038, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    v0016 = nil;
    { popv(3); return onevalue(v0016); }

v0174:
    v0038 = stack[-1];
    v0016 = stack[0];
    popv(3);
    return list2(v0038, v0016);
// error exit handlers
v0190:
    popv(3);
    return nil;
}



setup_type const u32_setup[] =
{
    {"inszzz",                  too_few_2,      CC_inszzz,     wrong_no_2},
    {"suspend",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_suspend},
    {"copy_mat",                CC_copy_mat,    too_many_1,    wrong_no_1},
    {"mkupf",                   CC_mkupf,       too_many_1,    wrong_no_1},
    {"getupper",                CC_getupper,    too_many_1,    wrong_no_1},
    {"s_noparents",             CC_s_noparents, too_many_1,    wrong_no_1},
    {"in_list1a",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_in_list1a},
    {"xremf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremf},
    {"cali=min",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_caliMmin},
    {"pst_subpst",              too_few_2,      CC_pst_subpst, wrong_no_2},
    {"lpos",                    too_few_2,      CC_lpos,       wrong_no_2},
    {"bfrsq",                   CC_bfrsq,       too_many_1,    wrong_no_1},
    {"rl_onp",                  CC_rl_onp,      too_many_1,    wrong_no_1},
    {"rl_multsurep",            too_few_2,      CC_rl_multsurep,wrong_no_2},
    {"matrixrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrd},
    {"compl",                   too_few_2,      CC_compl,      wrong_no_2},
    {"spcol_dim",               CC_spcol_dim,   too_many_1,    wrong_no_1},
    {"mkbc",                    too_few_2,      CC_mkbc,       wrong_no_2},
    {"applysetop",              too_few_2,      CC_applysetop, wrong_no_2},
    {"aceq",                    too_few_2,      CC_aceq,       wrong_no_2},
    {"calc_atlas",              too_few_2,      CC_calc_atlas, wrong_no_2},
    {"formsetq0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq0},
    {"reduce",                  too_few_2,      CC_reduce,     wrong_no_2},
    {"fs:minusp:",              CC_fsTminuspT,  too_many_1,    wrong_no_1},
    {"giintgcd",                too_few_2,      CC_giintgcd,   wrong_no_2},
    {"maxfrom",                 too_few_2,      CC_maxfrom,    wrong_no_2},
    {"mk+equation",             too_few_2,      CC_mkLequation,wrong_no_2},
    {"cl_smsimpl-junct",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct},
    {"sfto_qsubhor1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_sfto_qsubhor1},
    {"upperlimitrd",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_upperlimitrd},
    {"prlist",                  CC_prlist,      too_many_1,    wrong_no_1},
    {"assgnpri",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_assgnpri},
    {"extbrsea",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_extbrsea},
    {"size_of_matrix",          CC_size_of_matrix,too_many_1,  wrong_no_1},
    {"add_item",                too_few_2,      CC_add_item,   wrong_no_2},
    {"list-evaluate",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_listKevaluate},
    {"replace2_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace2_parents},
    {"redall",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_redall},
    {"fd2q",                    CC_fd2q,        too_many_1,    wrong_no_1},
    {"basic-kern",              CC_basicKkern,  too_many_1,    wrong_no_1},
    {"algmodep",                CC_algmodep,    too_many_1,    wrong_no_1},
    {"tayfkern",                CC_tayfkern,    too_many_1,    wrong_no_1},
    {"depend-f",                too_few_2,      CC_dependKf,   wrong_no_2},
    {"pasf_fact",               CC_pasf_fact,   too_many_1,    wrong_no_1},
    {"intervalrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_intervalrd},
    {NULL, (one_args *)"u32", (two_args *)"6700 2529108 4112317", 0}
};

// end of generated code
