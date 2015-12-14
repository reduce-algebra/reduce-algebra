
// $destdir\u39.c        Machine generated C code

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



// Code for gpexpp

static LispObject CC_gpexpp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0023, v0024;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gpexpp");
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

v0025:
    v0023 = stack[0];
    if (!consp(v0023)) goto v0026;
    v0023 = stack[0];
    v0024 = qcar(v0023);
    v0023 = elt(env, 2); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    v0023 = Lmemq(nil, v0024, v0023);
    if (v0023 == nil) goto v0027;
    v0023 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0023); }

v0027:
    v0023 = stack[0];
    v0024 = qcar(v0023);
    v0023 = elt(env, 4); // plus
    if (v0024 == v0023) goto v0028;
    v0023 = stack[0];
    v0024 = qcar(v0023);
    v0023 = elt(env, 5); // (minus recip)
    v0023 = Lmemq(nil, v0024, v0023);
    if (v0023 == nil) goto v0029;
    v0023 = stack[0];
    v0024 = Llength(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0023 = (LispObject)33; // 2
    if (v0024 == v0023) goto v0031;
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0031:
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    stack[0] = v0023;
    goto v0025;

v0029:
    v0023 = stack[0];
    v0024 = qcar(v0023);
    v0023 = elt(env, 6); // (difference quotient expt)
    v0023 = Lmemq(nil, v0024, v0023);
    if (v0023 == nil) goto v0032;
    v0023 = stack[0];
    v0024 = Llength(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0023 = (LispObject)49; // 3
    if (v0024 == v0023) goto v0033;
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0033:
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    v0023 = CC_gpexpp(env, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    if (v0023 == nil) goto v0034;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    stack[0] = v0023;
    goto v0025;

v0034:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0032:
    v0023 = stack[0];
    v0024 = qcar(v0023);
    v0023 = elt(env, 7); // times
    if (v0024 == v0023) goto v0035;
    v0023 = stack[0];
    v0024 = qcar(v0023);
    v0023 = elt(env, 8); // !:rd!:
    if (v0024 == v0023) goto v0036;
    v0023 = stack[0];
    v0024 = qcar(v0023);
    v0023 = elt(env, 9); // (!:cr!: !:crn!: !:gi!:)
    v0023 = Lmemq(nil, v0024, v0023);
    if (v0023 == nil) goto v0037;
    v0023 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0023); }

v0037:
    v0023 = stack[0];
    v0023 = qcar(v0023);
    fn = elt(env, 10); // unresidp
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    if (v0023 == nil) goto v0038;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    {
        popv(2);
        fn = elt(env, 11); // gparg1p
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0038:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0036:
    v0023 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0023); }

v0035:
    v0023 = stack[0];
    v0024 = Llength(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0023 = (LispObject)49; // 3
    v0023 = (LispObject)geq2(v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-1];
    if (v0023 == nil) goto v0039;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    v0023 = CC_gpexpp(env, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    if (v0023 == nil) goto v0040;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    v0023 = CC_gpexpp(env, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    if (v0023 == nil) goto v0041;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    {
        popv(2);
        fn = elt(env, 12); // gpexp1p
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0041:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0040:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0039:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0028:
    v0023 = stack[0];
    v0024 = Llength(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0023 = (LispObject)33; // 2
    v0023 = (LispObject)geq2(v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-1];
    if (v0023 == nil) goto v0042;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    v0023 = CC_gpexpp(env, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    if (v0023 == nil) goto v0043;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    {
        popv(2);
        fn = elt(env, 12); // gpexp1p
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0043:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0042:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }

v0026:
    v0023 = stack[0];
    v0023 = Lsymbolp(nil, v0023);
    env = stack[-1];
    v0024 = v0023;
    if (!(v0023 == nil)) { popv(2); return onevalue(v0024); }
    v0023 = stack[0];
    v0023 = (is_number(v0023) ? lisp_true : nil);
    v0024 = v0023;
    if (!(v0023 == nil)) { popv(2); return onevalue(v0024); }
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0023); }
// error exit handlers
v0030:
    popv(2);
    return nil;
}



// Code for physopsubs

static LispObject CC_physopsubs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0033, v0064, v0065;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopsubs");
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
    stack[-2] = qvalue(elt(env, 1)); // alglist!*
    qvalue(elt(env, 1)) = nil; // alglist!*
    v0033 = qvalue(elt(env, 2)); // nil
    v0033 = ncons(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0033; // alglist!*
    v0033 = stack[-1];
    fn = elt(env, 11); // physop2sq
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    stack[-1] = v0033;
    v0033 = qvalue(elt(env, 3)); // physoplist!*
    stack[0] = v0033;
    goto v0067;

v0067:
    v0033 = stack[0];
    if (v0033 == nil) goto v0019;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    v0065 = v0033;
    v0064 = v0065;
    v0033 = elt(env, 4); // rtype
    v0033 = Lremprop(nil, v0064, v0033);
    env = stack[-3];
    v0064 = elt(env, 5); // simpfn
    v0033 = elt(env, 6); // simpiden
    v0033 = Lputprop(nil, 3, v0065, v0064, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0067;

v0019:
    v0064 = elt(env, 7); // (dot)
    v0033 = elt(env, 8); // physopfn
    v0033 = Lremflag(nil, v0064, v0033);
    env = stack[-3];
    v0065 = elt(env, 9); // dot
    v0064 = elt(env, 5); // simpfn
    v0033 = elt(env, 6); // simpiden
    v0033 = Lputprop(nil, 3, v0065, v0064, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    v0033 = stack[-1];
    fn = elt(env, 12); // subs2
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    stack[-1] = v0033;
    v0033 = stack[-1];
    fn = elt(env, 13); // !*q2a
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    stack[-1] = v0033;
    v0033 = qvalue(elt(env, 3)); // physoplist!*
    stack[0] = v0033;
    goto v0068;

v0068:
    v0033 = stack[0];
    if (v0033 == nil) goto v0069;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    v0065 = v0033;
    v0064 = v0065;
    v0033 = elt(env, 5); // simpfn
    v0033 = Lremprop(nil, v0064, v0033);
    env = stack[-3];
    v0064 = elt(env, 4); // rtype
    v0033 = elt(env, 10); // physop
    v0033 = Lputprop(nil, 3, v0065, v0064, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0068;

v0069:
    v0064 = elt(env, 9); // dot
    v0033 = elt(env, 5); // simpfn
    v0033 = Lremprop(nil, v0064, v0033);
    env = stack[-3];
    v0064 = elt(env, 7); // (dot)
    v0033 = elt(env, 8); // physopfn
    v0033 = Lflag(nil, v0064, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    v0033 = stack[-1];
    qvalue(elt(env, 1)) = stack[-2]; // alglist!*
    { popv(4); return onevalue(v0033); }
// error exit handlers
v0066:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // alglist!*
    popv(4);
    return nil;
}



// Code for free

static LispObject CC_free(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0070;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for free");
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
    v0070 = qcdr(v0070);
    v0070 = qcar(v0070);
    fn = elt(env, 2); // freeind
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    if (v0070 == nil) goto v0044;
    v0070 = stack[0];
    v0070 = qcdr(v0070);
    v0070 = qcdr(v0070);
    v0070 = qcar(v0070);
    {
        popv(2);
        fn = elt(env, 2); // freeind
        return (*qfn1(fn))(qenv(fn), v0070);
    }

v0044:
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0070); }
// error exit handlers
v0071:
    popv(2);
    return nil;
}



// Code for expand!-imrepartpow

static LispObject CC_expandKimrepartpow(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0089, v0090;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expand-imrepartpow");
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
    stack[-3] = qvalue(elt(env, 1)); // !*exp
    qvalue(elt(env, 1)) = nil; // !*exp
    v0089 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0089; // !*exp
    v0089 = stack[-2];
    v0089 = qcar(v0089);
    if (symbolp(v0089)) goto v0091;
    v0089 = stack[-2];
    v0089 = qcar(v0089);
    v0090 = qcar(v0089);
    v0089 = elt(env, 3); // cmpxsplitfn
    v0089 = get(v0090, v0089);
    env = stack[-4];
    goto v0026;

v0026:
    v0090 = v0089;
    v0089 = v0090;
    if (v0089 == nil) goto v0059;
    v0089 = stack[-2];
    v0089 = qcar(v0089);
    v0089 = Lapply1(nil, v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0090 = v0089;
    goto v0093;

v0093:
    v0089 = stack[-2];
    v0089 = qcdr(v0089);
    fn = elt(env, 6); // exptsq
    v0089 = (*qfn2(fn))(qenv(fn), v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; // !*exp
    { popv(5); return onevalue(v0089); }

v0059:
    v0089 = stack[-2];
    v0090 = qcar(v0089);
    v0089 = elt(env, 5); // i
    if (v0090 == v0089) goto v0053;
    v0089 = stack[-2];
    v0089 = qcar(v0089);
    fn = elt(env, 7); // mkrepart
    stack[-1] = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = elt(env, 5); // i
    fn = elt(env, 8); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = stack[-2];
    v0089 = qcar(v0089);
    fn = elt(env, 9); // mkimpart
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    fn = elt(env, 10); // multsq
    v0089 = (*qfn2(fn))(qenv(fn), stack[0], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    fn = elt(env, 11); // addsq
    v0089 = (*qfn2(fn))(qenv(fn), stack[-1], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    goto v0094;

v0094:
    v0090 = v0089;
    goto v0093;

v0053:
    v0090 = elt(env, 5); // i
    v0089 = (LispObject)17; // 1
    fn = elt(env, 12); // to
    v0090 = (*qfn2(fn))(qenv(fn), v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = (LispObject)17; // 1
    v0089 = cons(v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0090 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = (LispObject)17; // 1
    v0089 = cons(v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    goto v0094;

v0091:
    v0089 = qvalue(elt(env, 4)); // nil
    goto v0026;
// error exit handlers
v0092:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; // !*exp
    popv(5);
    return nil;
}



// Code for groeb!=testb

static LispObject CC_groebMtestb(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0047, v0110;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=testb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0095;
    stack[-1] = v0000;
// end of prologue
    v0047 = stack[-1];
    fn = elt(env, 2); // mo_comp
    v0110 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0047 = stack[0];
    v0047 = qcar(v0047);
    if (equal(v0110, v0047)) goto v0087;
    v0047 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0047); }

v0087:
    stack[-2] = stack[-1];
    v0110 = stack[0];
    v0047 = (LispObject)49; // 3
    fn = elt(env, 3); // nth
    v0047 = (*qfn2(fn))(qenv(fn), v0110, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    fn = elt(env, 4); // mo_divides!?
    v0047 = (*qfn2(fn))(qenv(fn), stack[-2], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    if (v0047 == nil) goto v0070;
    v0110 = stack[0];
    v0047 = (LispObject)81; // 5
    fn = elt(env, 3); // nth
    v0047 = (*qfn2(fn))(qenv(fn), v0110, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    fn = elt(env, 5); // bas_dpoly
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    fn = elt(env, 6); // dp_lmon
    v0110 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0047 = stack[-1];
    fn = elt(env, 7); // mo_lcm
    stack[-2] = (*qfn2(fn))(qenv(fn), v0110, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0110 = stack[0];
    v0047 = (LispObject)49; // 3
    fn = elt(env, 3); // nth
    v0047 = (*qfn2(fn))(qenv(fn), v0110, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    fn = elt(env, 8); // mo_equal!?
    v0047 = (*qfn2(fn))(qenv(fn), stack[-2], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    if (v0047 == nil) goto v0016;
    v0047 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0047); }

v0016:
    v0110 = stack[0];
    v0047 = (LispObject)65; // 4
    fn = elt(env, 3); // nth
    v0047 = (*qfn2(fn))(qenv(fn), v0110, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    fn = elt(env, 5); // bas_dpoly
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    fn = elt(env, 6); // dp_lmon
    v0110 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0047 = stack[-1];
    fn = elt(env, 7); // mo_lcm
    stack[-1] = (*qfn2(fn))(qenv(fn), v0110, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0110 = stack[0];
    v0047 = (LispObject)49; // 3
    fn = elt(env, 3); // nth
    v0047 = (*qfn2(fn))(qenv(fn), v0110, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    fn = elt(env, 8); // mo_equal!?
    v0047 = (*qfn2(fn))(qenv(fn), stack[-1], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    v0047 = (v0047 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v0047); }

v0070:
    v0047 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0047); }
// error exit handlers
v0011:
    popv(4);
    return nil;
}



// Code for gigcd!:

static LispObject CC_gigcdT(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0106, v0112;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gigcd:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0095;
    stack[-1] = v0000;
// end of prologue

v0113:
    v0106 = stack[0];
    fn = elt(env, 1); // gizerop!:
    v0106 = (*qfn1(fn))(qenv(fn), v0106);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-3];
    if (v0106 == nil) goto v0109;
    v0106 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); // fqa
        return (*qfn1(fn))(qenv(fn), v0106);
    }

v0109:
    v0106 = stack[0];
    stack[-2] = v0106;
    v0112 = stack[-1];
    v0106 = stack[0];
    fn = elt(env, 3); // giremainder
    v0106 = (*qfn2(fn))(qenv(fn), v0112, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-3];
    stack[0] = v0106;
    v0106 = stack[-2];
    stack[-1] = v0106;
    goto v0113;
// error exit handlers
v0062:
    popv(4);
    return nil;
}



// Code for mri_simplfloor1

static LispObject CC_mri_simplfloor1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0052, v0083;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_simplfloor1");
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
    v0052 = stack[-1];
    if (!consp(v0052)) goto v0116;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    v0052 = (consp(v0052) ? nil : lisp_true);
    goto v0108;

v0108:
    if (!(v0052 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    v0052 = qcdr(v0052);
    fn = elt(env, 2); // mri_simplfloor
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    stack[0] = v0052;
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    fn = elt(env, 2); // mri_simplfloor
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    stack[-2] = v0052;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    fn = elt(env, 3); // mri_irsplit
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0083 = v0052;
    v0083 = qcar(v0083);
    v0052 = qcdr(v0052);
    fn = elt(env, 4); // addf
    v0083 = (*qfn2(fn))(qenv(fn), v0083, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    v0052 = qcdr(v0052);
    fn = elt(env, 5); // exptf
    v0052 = (*qfn2(fn))(qenv(fn), v0083, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    fn = elt(env, 6); // multf
    v0083 = (*qfn2(fn))(qenv(fn), stack[0], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0052 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(qenv(fn), v0083, v0052);
    }

v0116:
    v0052 = qvalue(elt(env, 1)); // t
    goto v0108;
// error exit handlers
v0117:
    popv(4);
    return nil;
}



// Code for coeffs

static LispObject CC_coeffs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0128, v0129;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeffs");
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
    stack[-4] = v0000;
// end of prologue
    stack[-2] = nil;
    v0128 = stack[-4];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    stack[-1] = v0128;
    v0128 = stack[-4];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    stack[-5] = v0128;
    goto v0071;

v0071:
    v0128 = stack[-4];
    if (!consp(v0128)) goto v0061;
    v0128 = stack[-4];
    v0128 = qcar(v0128);
    v0128 = (consp(v0128) ? nil : lisp_true);
    goto v0130;

v0130:
    if (v0128 == nil) goto v0027;
    v0128 = qvalue(elt(env, 2)); // nil
    goto v0105;

v0105:
    if (v0128 == nil) goto v0131;
    v0128 = stack[-4];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    stack[-3] = v0128;
    v0128 = (LispObject)17; // 1
    stack[0] = v0128;
    goto v0132;

v0132:
    v0129 = stack[-5];
    v0128 = stack[-3];
    v0128 = difference2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    v0129 = sub1(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    v0128 = stack[0];
    v0128 = difference2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    v0128 = Lminusp(nil, v0128);
    env = stack[-6];
    if (v0128 == nil) goto v0015;
    v0128 = stack[-4];
    v0128 = qcar(v0128);
    v0129 = qcdr(v0128);
    v0128 = stack[-2];
    v0128 = cons(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    stack[-2] = v0128;
    v0128 = stack[-4];
    v0128 = qcdr(v0128);
    stack[-4] = v0128;
    v0128 = stack[-3];
    stack[-5] = v0128;
    goto v0071;

v0015:
    v0129 = qvalue(elt(env, 2)); // nil
    v0128 = stack[-2];
    v0128 = cons(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    stack[-2] = v0128;
    v0128 = stack[0];
    v0128 = add1(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    stack[0] = v0128;
    goto v0132;

v0131:
    v0128 = (LispObject)17; // 1
    stack[0] = v0128;
    goto v0134;

v0134:
    v0128 = stack[-5];
    v0129 = sub1(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    v0128 = stack[0];
    v0128 = difference2(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    v0128 = Lminusp(nil, v0128);
    env = stack[-6];
    if (v0128 == nil) goto v0010;
    v0129 = stack[-4];
    v0128 = stack[-2];
    v0128 = cons(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
        popv(7);
        return Lnreverse(nil, v0128);

v0010:
    v0129 = qvalue(elt(env, 2)); // nil
    v0128 = stack[-2];
    v0128 = cons(v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    stack[-2] = v0128;
    v0128 = stack[0];
    v0128 = add1(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-6];
    stack[0] = v0128;
    goto v0134;

v0027:
    v0128 = stack[-4];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    v0129 = qcar(v0128);
    v0128 = stack[-1];
    v0128 = (v0129 == v0128 ? lisp_true : nil);
    goto v0105;

v0061:
    v0128 = qvalue(elt(env, 1)); // t
    goto v0130;
// error exit handlers
v0133:
    popv(7);
    return nil;
}



// Code for lengthn

static LispObject CC_lengthn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0130;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthn");
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
    v0130 = stack[0];
    if (v0130 == nil) goto v0044;
    v0130 = stack[0];
    v0130 = qcar(v0130);
    if (is_number(v0130)) goto v0116;
    v0130 = stack[0];
    v0130 = qcdr(v0130);
    v0130 = CC_lengthn(env, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    popv(3);
    return add1(v0130);

v0116:
    v0130 = stack[0];
    v0130 = qcar(v0130);
    stack[-1] = sub1(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-2];
    v0130 = stack[0];
    v0130 = qcdr(v0130);
    v0130 = CC_lengthn(env, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    {
        LispObject v0021 = stack[-1];
        popv(3);
        return plus2(v0021, v0130);
    }

v0044:
    v0130 = (LispObject)1; // 0
    { popv(3); return onevalue(v0130); }
// error exit handlers
v0107:
    popv(3);
    return nil;
}



// Code for ezgcdf1

static LispObject CC_ezgcdf1(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0109, v0135, v0136;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ezgcdf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0135 = v0095;
    v0136 = v0000;
// end of prologue
    v0109 = (LispObject)1; // 0
    stack[0] = qvalue(elt(env, 1)); // factor!-level
    qvalue(elt(env, 1)) = v0109; // factor!-level
    v0109 = v0136;
    v0109 = list2(v0109, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    fn = elt(env, 2); // gcdlist
    v0109 = (*qfn1(fn))(qenv(fn), v0109);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    fn = elt(env, 3); // poly!-abs
    v0109 = (*qfn1(fn))(qenv(fn), v0109);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // factor!-level
    { popv(2); return onevalue(v0109); }
// error exit handlers
v0131:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // factor!-level
    popv(2);
    return nil;
}



// Code for maprintla

static LispObject CC_maprintla(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0174, v0175, v0176;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maprintla");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0095;
    stack[-2] = v0000;
// end of prologue

v0177:
    v0174 = stack[-2];
    if (v0174 == nil) goto v0063;
    v0174 = stack[-2];
    if (is_number(v0174)) goto v0178;
    v0174 = stack[-2];
    if (!consp(v0174)) goto v0070;
    v0174 = stack[-2];
    v0174 = Lstringp(nil, v0174);
    env = stack[-4];
    if (v0174 == nil) goto v0060;
    v0174 = stack[-2];
    {
        popv(5);
        fn = elt(env, 17); // prin2la
        return (*qfn1(fn))(qenv(fn), v0174);
    }

v0060:
    v0174 = stack[-2];
    v0174 = qcar(v0174);
    if (!consp(v0174)) goto v0020;
    v0174 = stack[-2];
    v0175 = qcar(v0174);
    v0174 = stack[-1];
    stack[-2] = v0175;
    stack[-1] = v0174;
    goto v0177;

v0020:
    v0174 = stack[-2];
    v0175 = qcar(v0174);
    v0174 = elt(env, 2); // laprifn
    v0174 = get(v0175, v0174);
    env = stack[-4];
    stack[-3] = v0174;
    if (v0174 == nil) goto v0179;
    v0174 = stack[-2];
    v0175 = qcar(v0174);
    v0174 = elt(env, 3); // fulla
    v0174 = Lflagp(nil, v0175, v0174);
    env = stack[-4];
    if (v0174 == nil) goto v0180;
    v0174 = qvalue(elt(env, 1)); // nil
    goto v0018;

v0018:
    if (v0174 == nil) goto v0089;
    v0174 = qvalue(elt(env, 5)); // t
    goto v0181;

v0181:
    if (!(v0174 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0179:
    v0174 = stack[-2];
    v0175 = qcar(v0174);
    v0174 = elt(env, 6); // indexed
    v0174 = get(v0175, v0174);
    env = stack[-4];
    stack[-3] = v0174;
    if (v0174 == nil) goto v0034;
    v0174 = stack[-2];
    v0176 = qcar(v0174);
    v0174 = stack[-2];
    v0175 = qcdr(v0174);
    v0174 = stack[-3];
    {
        popv(5);
        fn = elt(env, 18); // prinidop
        return (*qfnn(fn))(qenv(fn), 3, v0176, v0175, v0174);
    }

v0034:
    v0174 = stack[-2];
    v0174 = qcar(v0174);
    if (!symbolp(v0174)) v0174 = nil;
    else { v0174 = qfastgets(v0174);
           if (v0174 != nil) { v0174 = elt(v0174, 23); // infix
#ifdef RECORD_GET
             if (v0174 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0174 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0174 == SPID_NOPROP) v0174 = nil; }}
#endif
    stack[-3] = v0174;
    if (v0174 == nil) goto v0182;
    v0175 = stack[-3];
    v0174 = stack[-1];
    v0174 = (LispObject)greaterp2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-4];
    stack[-1] = v0174;
    v0174 = stack[-1];
    if (v0174 == nil) goto v0184;
    v0174 = qvalue(elt(env, 1)); // nil
    goto v0185;

v0185:
    if (v0174 == nil) goto v0186;
    v0174 = qvalue(elt(env, 5)); // t
    stack[-1] = v0174;
    goto v0186;

v0186:
    v0174 = stack[-1];
    if (!(v0174 == nil)) goto v0187;
    v0174 = elt(env, 14); // !(
    fn = elt(env, 19); // prinlatom
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    goto v0187;

v0187:
    v0174 = stack[-2];
    v0176 = qcar(v0174);
    v0175 = stack[-3];
    v0174 = stack[-2];
    v0174 = qcdr(v0174);
    fn = elt(env, 20); // inprinla
    v0174 = (*qfnn(fn))(qenv(fn), 3, v0176, v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0174 = stack[-1];
    if (!(v0174 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0174 = elt(env, 15); // !)
    fn = elt(env, 19); // prinlatom
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0184:
    v0174 = stack[-2];
    v0175 = qcar(v0174);
    v0174 = elt(env, 13); // equal
    v0174 = (v0175 == v0174 ? lisp_true : nil);
    goto v0185;

v0182:
    v0174 = stack[-2];
    v0175 = qcar(v0174);
    v0174 = elt(env, 7); // !:rd!:
    if (v0175 == v0174) goto v0006;
    v0174 = stack[-2];
    v0174 = qcar(v0174);
    fn = elt(env, 21); // oprinla
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0174 = stack[-2];
    v0176 = qcar(v0174);
    v0174 = stack[-2];
    v0175 = qcdr(v0174);
    v0174 = stack[-1];
    fn = elt(env, 22); // prinpopargs
    v0174 = (*qfnn(fn))(qenv(fn), 3, v0176, v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0006:
    stack[-1] = qvalue(elt(env, 8)); // !*nat
    qvalue(elt(env, 8)) = nil; // !*nat
    v0174 = stack[-2];
    v0174 = qcdr(v0174);
    v0174 = Lfloatp(nil, v0174);
    env = stack[-4];
    if (v0174 == nil) goto v0188;
    v0174 = stack[-2];
    v0174 = qcdr(v0174);
    v0174 = Llengthc(nil, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0190;

v0190:
    stack[0] = v0174;
    v0175 = qvalue(elt(env, 9)); // ncharspr!*
    v0174 = stack[0];
    v0175 = plus2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0174 = qvalue(elt(env, 10)); // laline!*
    v0174 = (LispObject)greaterp2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-4];
    if (v0174 == nil) goto v0191;
    v0174 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0174 = stack[0];
    qvalue(elt(env, 9)) = v0174; // ncharspr!*
    goto v0192;

v0192:
    v0174 = qvalue(elt(env, 11)); // orig!*
    qvalue(elt(env, 12)) = v0174; // posn!*
    v0174 = stack[-2];
    fn = elt(env, 23); // rd!:prin
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0174 = nil;
    qvalue(elt(env, 8)) = stack[-1]; // !*nat
    { popv(5); return onevalue(v0174); }

v0191:
    v0175 = qvalue(elt(env, 9)); // ncharspr!*
    v0174 = stack[0];
    v0174 = plus2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    qvalue(elt(env, 9)) = v0174; // ncharspr!*
    goto v0192;

v0188:
    v0174 = stack[-2];
    v0174 = qcdr(v0174);
    v0174 = qcar(v0174);
    stack[0] = Llengthc(nil, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0174 = stack[-2];
    v0174 = qcdr(v0174);
    v0174 = qcdr(v0174);
    v0175 = Llengthc(nil, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0174 = (LispObject)81; // 5
    v0174 = plus2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    v0174 = plus2(stack[0], v0174);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-4];
    goto v0190;

v0089:
    v0174 = stack[-2];
    v0175 = qcar(v0174);
    v0174 = elt(env, 3); // fulla
    v0174 = Lflagp(nil, v0175, v0174);
    env = stack[-4];
    if (v0174 == nil) goto v0193;
    stack[0] = stack[-3];
    v0175 = stack[-2];
    v0174 = stack[-1];
    v0174 = list2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    fn = elt(env, 24); // apply
    v0175 = (*qfn2(fn))(qenv(fn), stack[0], v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0174 = elt(env, 4); // failed
    v0174 = (v0175 == v0174 ? lisp_true : nil);
    v0174 = (v0174 == nil ? lisp_true : nil);
    goto v0181;

v0193:
    v0174 = qvalue(elt(env, 1)); // nil
    goto v0181;

v0180:
    stack[0] = stack[-3];
    v0174 = stack[-2];
    v0175 = qcdr(v0174);
    v0174 = stack[-1];
    v0174 = list2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    fn = elt(env, 24); // apply
    v0175 = (*qfn2(fn))(qenv(fn), stack[0], v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0174 = elt(env, 4); // failed
    v0174 = (v0175 == v0174 ? lisp_true : nil);
    v0174 = (v0174 == nil ? lisp_true : nil);
    goto v0018;

v0070:
    v0174 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); // prinlatom
        return (*qfn1(fn))(qenv(fn), v0174);
    }

v0178:
    v0175 = stack[-2];
    v0174 = (LispObject)1; // 0
    v0174 = (LispObject)lessp2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-4];
    if (v0174 == nil) goto v0194;
    v0175 = stack[-1];
    v0174 = elt(env, 16); // minus
    if (!symbolp(v0174)) v0174 = nil;
    else { v0174 = qfastgets(v0174);
           if (v0174 != nil) { v0174 = elt(v0174, 23); // infix
#ifdef RECORD_GET
             if (v0174 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0174 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0174 == SPID_NOPROP) v0174 = nil; }}
#endif
    v0174 = (LispObject)lessp2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-4];
    goto v0195;

v0195:
    if (v0174 == nil) goto v0196;
    v0174 = stack[-2];
    {
        popv(5);
        fn = elt(env, 17); // prin2la
        return (*qfn1(fn))(qenv(fn), v0174);
    }

v0196:
    v0174 = elt(env, 14); // !(
    fn = elt(env, 17); // prin2la
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0174 = stack[-2];
    fn = elt(env, 17); // prin2la
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0174 = elt(env, 15); // !)
    fn = elt(env, 17); // prin2la
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0194:
    v0174 = qvalue(elt(env, 5)); // t
    goto v0195;

v0063:
    v0174 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0174); }
// error exit handlers
v0189:
    env = stack[-4];
    qvalue(elt(env, 8)) = stack[-1]; // !*nat
    popv(5);
    return nil;
v0183:
    popv(5);
    return nil;
}



// Code for defined_vertex

static LispObject CC_defined_vertex(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0062, v0107;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for defined_vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0095;
    stack[-1] = v0000;
// end of prologue

v0025:
    v0062 = stack[-1];
    if (v0062 == nil) goto v0026;
    v0062 = stack[-1];
    v0107 = qcar(v0062);
    v0062 = stack[0];
    fn = elt(env, 3); // memq_edgelist
    v0062 = (*qfn2(fn))(qenv(fn), v0107, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    if (v0062 == nil) goto v0093;
    v0062 = stack[-1];
    v0062 = qcdr(v0062);
    stack[-1] = v0062;
    goto v0025;

v0093:
    v0062 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0062); }

v0026:
    v0062 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0062); }
// error exit handlers
v0197:
    popv(3);
    return nil;
}



// Code for general!-modular!-difference

static LispObject CC_generalKmodularKdifference(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0022, v0197;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0022 = v0095;
    v0197 = v0000;
// end of prologue
    v0022 = difference2(v0197, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    stack[0] = v0022;
    v0197 = stack[0];
    v0022 = (LispObject)1; // 0
    v0022 = (LispObject)lessp2(v0197, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-1];
    if (v0022 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0197 = stack[0];
    v0022 = qvalue(elt(env, 1)); // current!-modulus
    v0022 = plus2(v0197, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    stack[0] = v0022;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0094:
    popv(2);
    return nil;
}



// Code for domainp_list

static LispObject CC_domainp_list(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0107, v0021;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for domainp_list");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0107 = v0000;
// end of prologue

v0177:
    v0021 = v0107;
    if (v0021 == nil) goto v0044;
    v0021 = v0107;
    v0021 = qcar(v0021);
    if (!consp(v0021)) goto v0135;
    v0021 = v0107;
    v0021 = qcar(v0021);
    v0021 = qcar(v0021);
    v0021 = (consp(v0021) ? nil : lisp_true);
    goto v0109;

v0109:
    if (v0021 == nil) goto v0130;
    v0107 = qcdr(v0107);
    goto v0177;

v0130:
    v0107 = qvalue(elt(env, 2)); // nil
    return onevalue(v0107);

v0135:
    v0021 = qvalue(elt(env, 1)); // t
    goto v0109;

v0044:
    v0107 = qvalue(elt(env, 1)); // t
    return onevalue(v0107);
}



// Code for change!+sq!+to!+int

static LispObject CC_changeLsqLtoLint(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0105, v0106, v0112;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for change+sq+to+int");
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
    v0105 = v0000;
// end of prologue
    fn = elt(env, 2); // prepsq
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[0];
    fn = elt(env, 3); // simp!*
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[0];
    v0112 = v0105;
    v0105 = v0112;
    v0106 = qcdr(v0105);
    v0105 = (LispObject)17; // 1
    if (v0106 == v0105) goto v0198;
    v0105 = elt(env, 1); // "no integer in change!+sq!+to!+int"
    fn = elt(env, 4); // rederr
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    v0105 = nil;
    { popv(1); return onevalue(v0105); }

v0198:
    v0105 = v0112;
    v0105 = qcar(v0105);
    { popv(1); return onevalue(v0105); }
// error exit handlers
v0093:
    popv(1);
    return nil;
}



// Code for rl_fvarl

static LispObject CC_rl_fvarl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_fvarl");
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
    v0063 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_fvarl!*
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    {
        LispObject v0067 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0067, v0063);
    }
// error exit handlers
v0116:
    popv(2);
    return nil;
}



// Code for ctx_get

static LispObject CC_ctx_get(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0027, v0059, v0057;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ctx_get");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0095;
    v0027 = v0000;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 2); // ctx_ial
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    v0057 = v0027;
    goto v0063;

v0063:
    v0027 = v0057;
    if (v0027 == nil) { LispObject res = stack[-1]; popv(2); return onevalue(res); }
    v0027 = stack[-1];
    if (!(v0027 == nil)) { LispObject res = stack[-1]; popv(2); return onevalue(res); }
    v0027 = v0057;
    v0027 = qcar(v0027);
    v0059 = qcar(v0027);
    v0027 = stack[0];
    if (!(v0059 == v0027)) goto v0088;
    v0027 = v0057;
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    stack[-1] = v0027;
    goto v0088;

v0088:
    v0027 = v0057;
    v0027 = qcdr(v0027);
    v0057 = v0027;
    goto v0063;
// error exit handlers
v0200:
    popv(2);
    return nil;
}



// Code for ezgcd!-comfac

static LispObject CC_ezgcdKcomfac(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0203, v0005, v0204;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ezgcd-comfac");
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
    v0203 = stack[-1];
    if (!consp(v0203)) goto v0026;
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = (consp(v0203) ? nil : lisp_true);
    goto v0086;

v0086:
    if (v0203 == nil) goto v0025;
    stack[0] = qvalue(elt(env, 2)); // nil
    v0203 = stack[-1];
    fn = elt(env, 3); // poly!-abs
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    {
        LispObject v0206 = stack[0];
        popv(4);
        return cons(v0206, v0203);
    }

v0025:
    v0203 = stack[-1];
    v0203 = qcdr(v0203);
    if (v0203 == nil) goto v0061;
    stack[-2] = nil;
    v0204 = nil;
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    stack[0] = v0203;
    goto v0103;

v0103:
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0005 = qcar(v0203);
    v0203 = stack[0];
    if (equal(v0005, v0203)) goto v0053;
    v0203 = qvalue(elt(env, 2)); // nil
    goto v0055;

v0055:
    if (v0203 == nil) goto v0122;
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcdr(v0203);
    v0005 = v0204;
    v0203 = cons(v0203, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-3];
    v0204 = v0203;
    v0203 = stack[-1];
    v0203 = qcdr(v0203);
    stack[-1] = v0203;
    goto v0103;

v0122:
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    v0005 = qcar(v0203);
    v0203 = stack[0];
    if (equal(v0005, v0203)) goto v0134;
    v0203 = stack[-1];
    v0005 = v0204;
    v0203 = cons(v0203, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-3];
    v0204 = v0203;
    goto v0207;

v0207:
    stack[0] = stack[-2];
    v0203 = v0204;
    fn = elt(env, 4); // gcdlist
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    {
        LispObject v0208 = stack[0];
        popv(4);
        return cons(v0208, v0203);
    }

v0134:
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcdr(v0203);
    v0005 = v0204;
    v0203 = cons(v0203, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-3];
    v0204 = v0203;
    v0203 = stack[-1];
    v0203 = qcdr(v0203);
    if (v0203 == nil) goto v0209;
    v0203 = stack[-1];
    v0203 = qcdr(v0203);
    v0005 = v0204;
    v0203 = cons(v0203, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-3];
    v0204 = v0203;
    goto v0207;

v0209:
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcar(v0203);
    stack[-2] = v0203;
    goto v0207;

v0053:
    v0203 = stack[-1];
    v0203 = qcdr(v0203);
    if (!consp(v0203)) goto v0132;
    v0203 = stack[-1];
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    v0203 = (consp(v0203) ? nil : lisp_true);
    goto v0042;

v0042:
    v0203 = (v0203 == nil ? lisp_true : nil);
    goto v0055;

v0132:
    v0203 = qvalue(elt(env, 1)); // t
    goto v0042;

v0061:
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    stack[0] = qcar(v0203);
    v0203 = stack[-1];
    v0203 = qcar(v0203);
    v0203 = qcdr(v0203);
    fn = elt(env, 3); // poly!-abs
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    {
        LispObject v0210 = stack[0];
        popv(4);
        return cons(v0210, v0203);
    }

v0026:
    v0203 = qvalue(elt(env, 1)); // t
    goto v0086;
// error exit handlers
v0205:
    popv(4);
    return nil;
}



// Code for ps!:zerop!:

static LispObject CC_psTzeropT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0109, v0135;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:zerop:");
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
    v0109 = v0000;
// end of prologue
    fn = elt(env, 2); // ps!:value
    v0109 = (*qfn1(fn))(qenv(fn), v0109);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[0];
    v0135 = v0109;
    v0109 = v0135;
    if (is_number(v0109)) goto v0063;
    v0109 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0109); }

v0063:
    v0109 = v0135;
        popv(1);
        return Lzerop(nil, v0109);
// error exit handlers
v0136:
    popv(1);
    return nil;
}



// Code for reset_opnums

static LispObject CC_reset_opnums(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0084, v0052, v0083;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "reset_opnums");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reset_opnums");
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
    v0084 = qvalue(elt(env, 1)); // oporder!*
    stack[-4] = v0084;
    v0084 = (LispObject)17; // 1
    stack[-3] = v0084;
    goto v0026;

v0026:
    v0084 = stack[-4];
    if (v0084 == nil) goto v0116;
    v0084 = stack[-4];
    v0084 = qcar(v0084);
    v0052 = v0084;
    v0084 = stack[-4];
    v0084 = qcdr(v0084);
    stack[-4] = v0084;
    v0084 = v0052;
    if (symbolp(v0084)) goto v0091;
    v0084 = v0052;
    v0084 = qcar(v0084);
    stack[-2] = v0084;
    v0084 = v0052;
    v0084 = qcdr(v0084);
    goto v0022;

v0022:
    stack[-1] = stack[-2];
    stack[0] = elt(env, 3); // opnum
    v0052 = v0084;
    v0084 = stack[-3];
    v0083 = cons(v0052, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-5];
    v0052 = stack[-2];
    v0084 = elt(env, 3); // opnum
    v0084 = get(v0052, v0084);
    env = stack[-5];
    fn = elt(env, 4); // !*xadd
    v0084 = (*qfn2(fn))(qenv(fn), v0083, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-5];
    v0084 = Lputprop(nil, 3, stack[-1], stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-5];
    v0084 = stack[-3];
    v0084 = add1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-5];
    stack[-3] = v0084;
    goto v0026;

v0091:
    v0084 = v0052;
    stack[-2] = v0084;
    v0084 = qvalue(elt(env, 2)); // nil
    goto v0022;

v0116:
    v0084 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0084); }
// error exit handlers
v0042:
    popv(6);
    return nil;
}



// Code for fs!:subang

static LispObject CC_fsTsubang(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0161, v0190, v0223, v0224;
    LispObject fn;
    LispObject v0072, v0095, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fs:subang");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0095 = va_arg(aa, LispObject);
    v0072 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:subang");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0072,v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0095,v0072);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0072;
    stack[-6] = v0095;
    stack[-7] = v0000;
// end of prologue
    v0161 = stack[-7];
    if (v0161 == nil) goto v0113;
    v0161 = (LispObject)113; // 7
    v0161 = Lmkvect(nil, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-9];
    stack[-8] = v0161;
    v0190 = stack[-7];
    v0161 = (LispObject)33; // 2
    v0190 = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    v0161 = stack[-6];
    v0161 = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    stack[-4] = v0161;
    v0161 = (LispObject)1; // 0
    stack[-3] = v0161;
    goto v0211;

v0211:
    v0190 = (LispObject)113; // 7
    v0161 = stack[-3];
    v0161 = difference2(v0190, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-9];
    v0161 = Lminusp(nil, v0161);
    env = stack[-9];
    if (v0161 == nil) goto v0181;
    v0190 = stack[-7];
    v0161 = (LispObject)49; // 3
    v0223 = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    v0190 = stack[-6];
    v0161 = stack[-5];
    stack[0] = CC_fsTsubang(env, 3, v0223, v0190, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-9];
    v0190 = stack[-7];
    v0161 = (LispObject)17; // 1
    v0224 = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    v0223 = stack[-8];
    v0190 = stack[-7];
    v0161 = (LispObject)1; // 0
    v0161 = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    fn = elt(env, 2); // make!-term
    v0161 = (*qfnn(fn))(qenv(fn), 3, v0224, v0223, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-9];
    {
        LispObject v0225 = stack[0];
        popv(10);
        fn = elt(env, 3); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0225, v0161);
    }

v0181:
    v0190 = stack[-3];
    v0161 = stack[-6];
    if (equal(v0190, v0161)) goto v0053;
    stack[-2] = stack[-8];
    stack[-1] = stack[-3];
    v0190 = stack[-7];
    v0161 = (LispObject)33; // 2
    v0190 = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    v0161 = stack[-3];
    stack[0] = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    v0223 = stack[-4];
    v0190 = stack[-5];
    v0161 = stack[-3];
    v0161 = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    v0161 = times2(v0223, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-9];
    v0161 = plus2(stack[0], v0161);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-9];
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0161;
    goto v0028;

v0028:
    v0161 = stack[-3];
    v0161 = add1(v0161);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-9];
    stack[-3] = v0161;
    goto v0211;

v0053:
    stack[-1] = stack[-8];
    stack[0] = stack[-3];
    v0223 = stack[-4];
    v0190 = stack[-5];
    v0161 = stack[-3];
    v0161 = *(LispObject *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0161/(16/CELL)));
    v0161 = times2(v0223, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-9];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0161;
    goto v0028;

v0113:
    v0161 = qvalue(elt(env, 1)); // nil
    { popv(10); return onevalue(v0161); }
// error exit handlers
v0188:
    popv(10);
    return nil;
}



// Code for mo_support

static LispObject CC_mo_support(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0200, v0020;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_support");
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
    v0200 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 3); // ring_names
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-4];
    stack[-1] = v0200;
    goto v0026;

v0026:
    v0200 = stack[-1];
    if (v0200 == nil) goto v0086;
    v0200 = stack[-1];
    v0200 = qcar(v0200);
    stack[0] = v0200;
    v0200 = stack[0];
    fn = elt(env, 4); // mo_from_a
    v0020 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-4];
    v0200 = stack[-2];
    fn = elt(env, 5); // mo_divides!?
    v0200 = (*qfn2(fn))(qenv(fn), v0020, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-4];
    if (v0200 == nil) goto v0087;
    v0020 = stack[0];
    v0200 = stack[-3];
    v0200 = cons(v0020, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-4];
    stack[-3] = v0200;
    goto v0087;

v0087:
    v0200 = stack[-1];
    v0200 = qcdr(v0200);
    stack[-1] = v0200;
    goto v0026;

v0086:
    v0200 = stack[-3];
        popv(5);
        return Lnreverse(nil, v0200);
// error exit handlers
v0226:
    popv(5);
    return nil;
}



// Code for sub01

static LispObject CC_sub01(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0059, v0057, v0058;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sub01");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0095;
    stack[-1] = v0000;
// end of prologue
    v0058 = nil;
    goto v0113;

v0113:
    v0059 = stack[0];
    if (v0059 == nil) goto v0077;
    v0059 = stack[0];
    v0057 = qcar(v0059);
    v0059 = stack[-1];
    if (equal(v0057, v0059)) goto v0071;
    v0059 = (LispObject)1; // 0
    goto v0109;

v0109:
    v0057 = v0058;
    v0059 = cons(v0059, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0058 = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0113;

v0071:
    v0059 = (LispObject)17; // 1
    goto v0109;

v0077:
    v0059 = v0058;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0059);
    }
// error exit handlers
v0020:
    popv(3);
    return nil;
}



// Code for flattens1

static LispObject CC_flattens1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0062;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for flattens1");
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
    v0062 = stack[0];
    if (!consp(v0062)) goto v0086;
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    if (v0062 == nil) goto v0112;
    v0062 = stack[0];
    v0062 = qcar(v0062);
    stack[-1] = CC_flattens1(env, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    v0062 = stack[0];
    v0062 = qcdr(v0062);
    v0062 = CC_flattens1(env, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    {
        LispObject v0197 = stack[-1];
        popv(3);
        return Lappend(nil, v0197, v0062);
    }

v0112:
    v0062 = stack[0];
    v0062 = qcar(v0062);
    stack[0] = v0062;
    goto v0044;

v0086:
    v0062 = stack[0];
    popv(3);
    return ncons(v0062);
// error exit handlers
v0022:
    popv(3);
    return nil;
}



// Code for dv_skel2factor

static LispObject CC_dv_skel2factor(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0015, v0016;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_skel2factor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    v0016 = v0095;
    stack[-4] = v0000;
// end of prologue
    v0015 = stack[-4];
    v0015 = qcdr(v0015);
    if (v0015 == nil) goto v0199;
    v0015 = stack[-4];
    v0015 = qcdr(v0015);
    v0015 = Lsublis(nil, v0016, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-6];
    stack[-5] = v0015;
    v0015 = stack[-5];
    fn = elt(env, 2); // st_ad_numsorttree
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-6];
    stack[-5] = v0015;
    v0015 = stack[-5];
    v0015 = qcdr(v0015);
    fn = elt(env, 3); // st_flatten
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-6];
    stack[-3] = v0015;
    v0015 = stack[-3];
    if (v0015 == nil) goto v0077;
    v0015 = stack[-3];
    v0015 = qcar(v0015);
    fn = elt(env, 4); // dv_ind2var
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-6];
    v0015 = ncons(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-6];
    stack[-1] = v0015;
    stack[-2] = v0015;
    goto v0061;

v0061:
    v0015 = stack[-3];
    v0015 = qcdr(v0015);
    stack[-3] = v0015;
    v0015 = stack[-3];
    if (v0015 == nil) goto v0226;
    stack[0] = stack[-1];
    v0015 = stack[-3];
    v0015 = qcar(v0015);
    fn = elt(env, 4); // dv_ind2var
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-6];
    v0015 = ncons(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-6];
    v0015 = Lrplacd(nil, stack[0], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-6];
    v0015 = stack[-1];
    v0015 = qcdr(v0015);
    stack[-1] = v0015;
    goto v0061;

v0226:
    v0015 = stack[-2];
    goto v0082;

v0082:
    v0016 = stack[-5];
    stack[0] = qcar(v0016);
    v0016 = stack[-4];
    v0016 = qcar(v0016);
    fn = elt(env, 5); // dv_skel2factor1
    v0015 = (*qfn2(fn))(qenv(fn), v0016, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    {
        LispObject v0097 = stack[0];
        popv(7);
        return cons(v0097, v0015);
    }

v0077:
    v0015 = qvalue(elt(env, 1)); // nil
    goto v0082;

v0199:
    v0015 = stack[-4];
    v0015 = qcar(v0015);
    { popv(7); return onevalue(v0015); }
// error exit handlers
v0100:
    popv(7);
    return nil;
}



// Code for add!-factor

static LispObject CC_addKfactor(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0114, v0084, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add-factor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0095;
    stack[-1] = v0000;
// end of prologue
    v0114 = stack[0];
    v0114 = Lconsp(nil, v0114);
    env = stack[-2];
    if (v0114 == nil) goto v0021;
    v0084 = stack[-1];
    v0114 = stack[0];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0114 = (LispObject)greaterp2(v0084, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    v0114 = v0114 ? lisp_true : nil;
    env = stack[-2];
    if (v0114 == nil) goto v0105;
    v0114 = qvalue(elt(env, 1)); // nil
    goto v0044;

v0044:
    v0084 = v0114;
    v0114 = v0084;
    if (v0114 == nil) goto v0213;
    stack[-1] = v0084;
    v0114 = v0084;
    v0114 = qcdr(v0114);
    v0114 = add1(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    v0114 = Lrplacd(nil, stack[-1], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }

v0213:
    v0052 = stack[-1];
    v0084 = (LispObject)17; // 1
    v0114 = stack[0];
    popv(3);
    return acons(v0052, v0084, v0114);

v0105:
    v0084 = stack[-1];
    v0114 = stack[0];
    v0114 = Lassoc(nil, v0084, v0114);
    goto v0044;

v0021:
    v0114 = qvalue(elt(env, 1)); // nil
    goto v0044;
// error exit handlers
v0068:
    popv(3);
    return nil;
}



// Code for mk_resimp_rep

static LispObject CC_mk_resimp_rep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_resimp_rep");
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
    v0050 = stack[-5];
    fn = elt(env, 2); // get_group_in
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    stack[-6] = v0050;
    v0050 = stack[-6];
    fn = elt(env, 3); // get!*elements
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    stack[-4] = v0050;
    v0050 = stack[-4];
    if (v0050 == nil) goto v0131;
    v0050 = stack[-4];
    v0050 = qcar(v0050);
    stack[0] = v0050;
    v0051 = v0050;
    v0050 = stack[-5];
    fn = elt(env, 4); // get_rep_matrix_in
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    fn = elt(env, 5); // mk!+resimp!+mat
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    v0050 = list2(stack[0], v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    v0050 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    stack[-2] = v0050;
    stack[-3] = v0050;
    goto v0067;

v0067:
    v0050 = stack[-4];
    v0050 = qcdr(v0050);
    stack[-4] = v0050;
    v0050 = stack[-4];
    if (v0050 == nil) goto v0019;
    stack[-1] = stack[-2];
    v0050 = stack[-4];
    v0050 = qcar(v0050);
    stack[0] = v0050;
    v0051 = v0050;
    v0050 = stack[-5];
    fn = elt(env, 4); // get_rep_matrix_in
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    fn = elt(env, 5); // mk!+resimp!+mat
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    v0050 = list2(stack[0], v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    v0050 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    v0050 = Lrplacd(nil, stack[-1], v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-7];
    v0050 = stack[-2];
    v0050 = qcdr(v0050);
    stack[-2] = v0050;
    goto v0067;

v0019:
    v0050 = stack[-3];
    goto v0116;

v0116:
    stack[0] = v0050;
    v0050 = stack[-6];
    v0051 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    v0050 = stack[0];
        popv(8);
        return Lappend(nil, v0051, v0050);

v0131:
    v0050 = qvalue(elt(env, 1)); // nil
    goto v0116;
// error exit handlers
v0218:
    popv(8);
    return nil;
}



// Code for ofsf_pop

static LispObject CC_ofsf_pop(LispObject env,
                         LispObject v0000)
{
    LispObject v0076;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_pop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0076 = v0000;
// end of prologue
    return onevalue(v0076);
}



// Code for reprod

static LispObject CC_reprod(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0062, v0107;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0095;
    stack[-1] = v0000;
// end of prologue

v0025:
    v0062 = stack[-1];
    if (v0062 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0062 = stack[-1];
    v0107 = qcar(v0062);
    v0062 = (LispObject)17; // 1
    v0062 = cons(v0107, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0107 = ncons(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    v0062 = stack[0];
    fn = elt(env, 2); // multf
    v0062 = (*qfn2(fn))(qenv(fn), v0107, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-2];
    stack[0] = v0062;
    v0062 = stack[-1];
    v0062 = qcdr(v0062);
    stack[-1] = v0062;
    goto v0025;
// error exit handlers
v0197:
    popv(3);
    return nil;
}



// Code for groebcplistsort

static LispObject CC_groebcplistsort(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0093, v0130;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebcplistsort");
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
    v0093 = v0000;
// end of prologue
    v0130 = qvalue(elt(env, 1)); // nil
    stack[0] = v0093;
    goto v0086;

v0086:
    v0093 = stack[0];
    if (v0093 == nil) { popv(2); return onevalue(v0130); }
    v0093 = stack[0];
    v0093 = qcar(v0093);
    fn = elt(env, 2); // groebcplistsortin
    v0093 = (*qfn2(fn))(qenv(fn), v0093, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0130 = v0093;
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    stack[0] = v0093;
    goto v0086;
// error exit handlers
v0062:
    popv(2);
    return nil;
}



// Code for pnth!*

static LispObject CC_pnthH(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0112, v0093, v0130;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pnth*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0093 = v0095;
    stack[0] = v0000;
// end of prologue

v0025:
    v0112 = stack[0];
    if (v0112 == nil) goto v0026;
    v0130 = v0093;
    v0112 = (LispObject)17; // 1
    if (v0130 == v0112) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    stack[0] = v0112;
    v0112 = v0093;
    v0112 = sub1(v0112);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0093 = v0112;
    goto v0025;

v0026:
    v0112 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0112); }
// error exit handlers
v0062:
    popv(2);
    return nil;
}



// Code for mk_names_map_2

static LispObject CC_mk_names_map_2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028, v0104;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_names_map_2");
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
    v0028 = v0000;
// end of prologue
    v0104 = v0028;
    v0104 = qcar(v0104);
    v0028 = qcdr(v0028);
    v0028 = Lappend(nil, v0104, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[-3] = v0028;
    v0028 = stack[-3];
    if (v0028 == nil) goto v0071;
    v0028 = stack[-3];
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[-1] = v0028;
    stack[-2] = v0028;
    goto v0086;

v0086:
    v0028 = stack[-3];
    v0028 = qcdr(v0028);
    stack[-3] = v0028;
    v0028 = stack[-3];
    if (v0028 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0028 = stack[-3];
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0028 = Lrplacd(nil, stack[0], v0028);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0028 = stack[-1];
    v0028 = qcdr(v0028);
    stack[-1] = v0028;
    goto v0086;

v0071:
    v0028 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0028); }
// error exit handlers
v0124:
    popv(5);
    return nil;
}



// Code for rd!:prin

static LispObject CC_rdTprin(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0094;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:prin");
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
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    if (!consp(v0094)) goto v0026;
    v0094 = qvalue(elt(env, 1)); // nil
    goto v0086;

v0086:
    if (v0094 == nil) goto v0088;
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    {
        popv(2);
        fn = elt(env, 2); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0094);
    }

v0088:
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    if (!consp(v0094)) goto v0112;
    v0094 = stack[0];
    goto v0106;

v0106:
    fn = elt(env, 3); // bftrim!:
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); // bfprin!:
        return (*qfn1(fn))(qenv(fn), v0094);
    }

v0112:
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    fn = elt(env, 5); // fl2bf
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    goto v0106;

v0026:
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    fn = elt(env, 6); // fp!-finite
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    v0094 = (v0094 == nil ? lisp_true : nil);
    goto v0086;
// error exit handlers
v0027:
    popv(2);
    return nil;
}



// Code for nextu

static LispObject CC_nextu(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0132, v0180, v0096;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nextu");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0180 = v0095;
    stack[0] = v0000;
// end of prologue
    v0132 = stack[0];
    if (v0132 == nil) goto v0025;
    v0096 = v0180;
    v0132 = stack[0];
    v0180 = qcar(v0132);
    v0132 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 3); // subtractinds
    v0132 = (*qfnn(fn))(qenv(fn), 3, v0096, v0180, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    stack[-1] = v0132;
    v0132 = stack[-1];
    if (v0132 == nil) goto v0093;
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    v0180 = qcar(v0132);
    v0132 = stack[-1];
    fn = elt(env, 4); // evaluatecoeffts
    v0132 = (*qfn2(fn))(qenv(fn), v0180, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0096 = v0132;
    v0132 = v0096;
    if (v0132 == nil) goto v0127;
    v0180 = v0096;
    v0132 = (LispObject)1; // 0
    v0132 = (v0180 == v0132 ? lisp_true : nil);
    goto v0085;

v0085:
    if (v0132 == nil) goto v0103;
    v0132 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0132); }

v0103:
    v0180 = stack[-1];
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    v0132 = qcdr(v0132);
    popv(3);
    return list2star(v0180, v0096, v0132);

v0127:
    v0132 = qvalue(elt(env, 2)); // t
    goto v0085;

v0093:
    v0132 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0132); }

v0025:
    v0132 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0132); }
// error exit handlers
v0049:
    popv(3);
    return nil;
}



// Code for depend!-p

static LispObject CC_dependKp(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0055, v0053, v0054, v0103;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depend-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0054 = v0095;
    v0103 = v0000;
// end of prologue
    v0053 = v0103;
    v0055 = v0054;
    if (v0053 == v0055) goto v0025;
    v0055 = v0103;
    if (!consp(v0055)) goto v0109;
    v0055 = v0103;
    v0055 = qcar(v0055);
    if (!consp(v0055)) goto v0107;
    v0055 = v0103;
    v0053 = v0054;
    {
        fn = elt(env, 4); // depend!-f
        return (*qfn2(fn))(qenv(fn), v0055, v0053);
    }

v0107:
    v0055 = v0103;
    v0053 = qcar(v0055);
    v0055 = elt(env, 3); // !*sq
    if (v0053 == v0055) goto v0057;
    v0055 = v0103;
    v0055 = qcdr(v0055);
    v0053 = v0054;
    {
        fn = elt(env, 5); // depend!-l
        return (*qfn2(fn))(qenv(fn), v0055, v0053);
    }

v0057:
    v0055 = v0103;
    v0055 = qcdr(v0055);
    v0055 = qcar(v0055);
    v0053 = v0054;
    {
        fn = elt(env, 6); // depend!-sq
        return (*qfn2(fn))(qenv(fn), v0055, v0053);
    }

v0109:
    v0055 = qvalue(elt(env, 2)); // nil
    return onevalue(v0055);

v0025:
    v0055 = qvalue(elt(env, 1)); // t
    return onevalue(v0055);
}



// Code for pasf_lnegrel

static LispObject CC_pasf_lnegrel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0100, v0097, v0219;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_lnegrel");
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
    v0219 = v0000;
// end of prologue
    v0097 = v0219;
    v0100 = elt(env, 1); // equal
    if (v0097 == v0100) goto v0044;
    v0097 = v0219;
    v0100 = elt(env, 2); // neq
    if (v0097 == v0100) goto v0067;
    v0097 = v0219;
    v0100 = elt(env, 3); // leq
    if (v0097 == v0100) goto v0060;
    v0097 = v0219;
    v0100 = elt(env, 5); // lessp
    if (v0097 == v0100) goto v0021;
    v0097 = v0219;
    v0100 = elt(env, 6); // geq
    if (v0097 == v0100) goto v0211;
    v0097 = v0219;
    v0100 = elt(env, 4); // greaterp
    if (v0097 == v0100) goto v0104;
    v0097 = v0219;
    v0100 = elt(env, 7); // cong
    if (v0097 == v0100) goto v0054;
    v0097 = v0219;
    v0100 = elt(env, 8); // ncong
    if (v0097 == v0100) goto v0117;
    v0100 = elt(env, 9); // "pasf_lnegrel: unknown operator"
    v0097 = v0219;
    v0100 = list2(v0100, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(qenv(fn), v0100);
    }

v0117:
    v0100 = elt(env, 7); // cong
    { popv(1); return onevalue(v0100); }

v0054:
    v0100 = elt(env, 8); // ncong
    { popv(1); return onevalue(v0100); }

v0104:
    v0100 = elt(env, 3); // leq
    { popv(1); return onevalue(v0100); }

v0211:
    v0100 = elt(env, 5); // lessp
    { popv(1); return onevalue(v0100); }

v0021:
    v0100 = elt(env, 6); // geq
    { popv(1); return onevalue(v0100); }

v0060:
    v0100 = elt(env, 4); // greaterp
    { popv(1); return onevalue(v0100); }

v0067:
    v0100 = elt(env, 1); // equal
    { popv(1); return onevalue(v0100); }

v0044:
    v0100 = elt(env, 2); // neq
    { popv(1); return onevalue(v0100); }
// error exit handlers
v0218:
    popv(1);
    return nil;
}



// Code for vdp_sugar

static LispObject CC_vdp_sugar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0105, v0106;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_sugar");
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
    v0105 = stack[0];
    fn = elt(env, 3); // vdp_zero!?
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    if (!(v0105 == nil)) goto v0044;
    v0105 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v0105 == nil) goto v0044;
    v0106 = stack[0];
    v0105 = elt(env, 2); // sugar
    fn = elt(env, 4); // vdp_getprop
    v0105 = (*qfn2(fn))(qenv(fn), v0106, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    if (!(v0105 == nil)) { popv(2); return onevalue(v0105); }
    v0105 = (LispObject)1; // 0
    { popv(2); return onevalue(v0105); }

v0044:
    v0105 = (LispObject)1; // 0
    { popv(2); return onevalue(v0105); }
// error exit handlers
v0093:
    popv(2);
    return nil;
}



// Code for subs2pf

static LispObject CC_subs2pf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0094, v0202, v0027;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2pf");
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

v0177:
    v0094 = stack[0];
    if (v0094 == nil) goto v0025;
    v0094 = stack[0];
    v0094 = qcar(v0094);
    v0094 = qcdr(v0094);
    fn = elt(env, 1); // resimp
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-1];
    fn = elt(env, 2); // subs2
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-1];
    v0202 = v0094;
    v0202 = qcar(v0202);
    if (v0202 == nil) goto v0107;
    v0202 = stack[0];
    v0202 = qcar(v0202);
    v0027 = qcar(v0202);
    v0202 = v0094;
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    popv(2);
    return acons(v0027, v0202, v0094);

v0107:
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    stack[0] = v0094;
    goto v0177;

v0025:
    v0094 = nil;
    { popv(2); return onevalue(v0094); }
// error exit handlers
v0057:
    popv(2);
    return nil;
}



// Code for lispcodeexp

static LispObject CC_lispcodeexp(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0298, v0299, v0300;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispcodeexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0095;
    stack[-2] = v0000;
// end of prologue

v0177:
    v0298 = stack[-2];
    if (is_number(v0298)) goto v0086;
    v0299 = stack[-2];
    v0298 = elt(env, 1); // e
    if (v0299 == v0298) goto v0197;
    v0298 = stack[-2];
    if (!consp(v0298)) goto v0085;
    v0298 = stack[-2];
    v0299 = qcar(v0298);
    v0298 = elt(env, 5); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    v0298 = Lmemq(nil, v0299, v0298);
    goto v0019;

v0019:
    if (v0298 == nil) goto v0078;
    v0298 = qvalue(elt(env, 6)); // irena!-constants
    if (v0298 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0298 = stack[-2];
    if (v0298 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0298 = stack[-2];
    v0298 = Lstringp(nil, v0298);
    env = stack[-5];
    if (!(v0298 == nil)) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0298 = stack[-2];
    fn = elt(env, 21); // check!-for!-irena!-constants
    v0298 = (*qfn1(fn))(qenv(fn), v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    { LispObject res = stack[-2]; popv(6); return onevalue(res); }

v0078:
    v0298 = stack[-2];
    v0299 = qcar(v0298);
    v0298 = elt(env, 7); // expt
    if (v0299 == v0298) goto v0031;
    v0298 = stack[-2];
    v0299 = qcar(v0298);
    v0298 = elt(env, 12); // quotient
    if (v0299 == v0298) goto v0145;
    v0298 = stack[-2];
    v0299 = qcar(v0298);
    v0298 = elt(env, 14); // recip
    if (v0299 == v0298) goto v0302;
    v0298 = stack[-2];
    v0299 = qcar(v0298);
    v0298 = elt(env, 16); // difference
    if (v0299 == v0298) goto v0303;
    v0298 = stack[-2];
    v0299 = qcar(v0298);
    v0298 = qvalue(elt(env, 19)); // !*lisparithexpops!*
    v0298 = Lmemq(nil, v0299, v0298);
    if (v0298 == nil) goto v0304;
    v0298 = qvalue(elt(env, 13)); // nil
    goto v0305;

v0305:
    if (v0298 == nil) goto v0306;
    v0298 = stack[-2];
    stack[-3] = v0298;
    v0298 = stack[-3];
    if (v0298 == nil) goto v0307;
    v0298 = stack[-3];
    v0298 = qcar(v0298);
    v0299 = v0298;
    v0298 = qvalue(elt(env, 13)); // nil
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    stack[-1] = v0298;
    stack[-2] = v0298;
    goto v0308;

v0308:
    v0298 = stack[-3];
    v0298 = qcdr(v0298);
    stack[-3] = v0298;
    v0298 = stack[-3];
    if (v0298 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0298 = stack[-3];
    v0298 = qcar(v0298);
    v0299 = v0298;
    v0298 = qvalue(elt(env, 13)); // nil
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = Lrplacd(nil, stack[0], v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    stack[-1] = v0298;
    goto v0308;

v0307:
    v0298 = qvalue(elt(env, 13)); // nil
    { popv(6); return onevalue(v0298); }

v0306:
    v0298 = stack[-2];
    stack[-4] = v0298;
    v0298 = stack[-4];
    if (v0298 == nil) goto v0309;
    v0298 = stack[-4];
    v0298 = qcar(v0298);
    v0299 = v0298;
    v0298 = stack[-3];
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    stack[-1] = v0298;
    stack[-2] = v0298;
    goto v0310;

v0310:
    v0298 = stack[-4];
    v0298 = qcdr(v0298);
    stack[-4] = v0298;
    v0298 = stack[-4];
    if (v0298 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0298 = stack[-4];
    v0298 = qcar(v0298);
    v0299 = v0298;
    v0298 = stack[-3];
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = Lrplacd(nil, stack[0], v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    stack[-1] = v0298;
    goto v0310;

v0309:
    v0298 = qvalue(elt(env, 13)); // nil
    { popv(6); return onevalue(v0298); }

v0304:
    v0298 = stack[-2];
    v0299 = qcar(v0298);
    v0298 = qvalue(elt(env, 20)); // !*lisplogexpops!*
    v0298 = Lmemq(nil, v0299, v0298);
    v0298 = (v0298 == nil ? lisp_true : nil);
    goto v0305;

v0303:
    stack[-4] = elt(env, 17); // plus
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    stack[0] = elt(env, 18); // minus
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = stack[-3];
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = list2(stack[0], v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    {
        LispObject v0311 = stack[-4];
        LispObject v0312 = stack[-1];
        popv(6);
        return list3(v0311, v0312, v0298);
    }

v0302:
    v0298 = qvalue(elt(env, 15)); // !*period
    if (v0298 == nil) goto v0313;
    stack[-1] = elt(env, 12); // quotient
    stack[0] = elt(env, 3); // 1.0
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = stack[-3];
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    {
        LispObject v0314 = stack[-1];
        LispObject v0315 = stack[0];
        popv(6);
        return list3(v0314, v0315, v0298);
    }

v0313:
    stack[-1] = elt(env, 12); // quotient
    stack[0] = (LispObject)17; // 1
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = stack[-3];
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    {
        LispObject v0316 = stack[-1];
        LispObject v0317 = stack[0];
        popv(6);
        return list3(v0316, v0317, v0298);
    }

v0145:
    stack[-1] = elt(env, 12); // quotient
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = qvalue(elt(env, 4)); // t
    stack[0] = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = qvalue(elt(env, 4)); // t
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    {
        LispObject v0318 = stack[-1];
        LispObject v0319 = stack[0];
        popv(6);
        return list3(v0318, v0319, v0298);
    }

v0031:
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = elt(env, 1); // e
    if (v0299 == v0298) goto v0090;
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = elt(env, 8); // (quotient 1 2)
    if (equal(v0299, v0298)) goto v0193;
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = elt(env, 10); // !:rd!:
    if (!consp(v0299)) goto v0320;
    v0299 = qcar(v0299);
    if (!(v0299 == v0298)) goto v0320;
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0298 = qcar(v0298);
    fn = elt(env, 22); // realrat
    v0298 = (*qfn1(fn))(qenv(fn), v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    stack[-1] = v0298;
    v0299 = stack[-1];
    v0298 = elt(env, 11); // (1 . 2)
    if (equal(v0299, v0298)) goto v0154;
    stack[0] = elt(env, 7); // expt
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = stack[-3];
    stack[-2] = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0300 = elt(env, 12); // quotient
    v0298 = stack[-1];
    v0299 = qcar(v0298);
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    v0299 = list3(v0300, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = qvalue(elt(env, 13)); // nil
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    {
        LispObject v0321 = stack[0];
        LispObject v0322 = stack[-2];
        popv(6);
        return list3(v0321, v0322, v0298);
    }

v0154:
    stack[0] = elt(env, 9); // sqrt
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = stack[-3];
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    {
        LispObject v0323 = stack[0];
        popv(6);
        return list2(v0323, v0298);
    }

v0320:
    stack[0] = elt(env, 7); // expt
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0299 = qcar(v0298);
    v0298 = qvalue(elt(env, 13)); // nil
    v0298 = CC_lispcodeexp(env, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    {
        LispObject v0324 = stack[0];
        LispObject v0325 = stack[-1];
        popv(6);
        return list3(v0324, v0325, v0298);
    }

v0193:
    v0299 = elt(env, 9); // sqrt
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0298 = qcar(v0298);
    v0299 = list2(v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = stack[-3];
    stack[-2] = v0299;
    stack[-3] = v0298;
    goto v0177;

v0090:
    v0299 = elt(env, 2); // exp
    v0298 = stack[-2];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0298 = qcar(v0298);
    v0299 = list2(v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = stack[-3];
    stack[-2] = v0299;
    stack[-3] = v0298;
    goto v0177;

v0085:
    v0298 = qvalue(elt(env, 4)); // t
    goto v0019;

v0197:
    v0299 = elt(env, 2); // exp
    v0298 = elt(env, 3); // 1.0
    v0299 = list2(v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0301;
    env = stack[-5];
    v0298 = stack[-3];
    stack[-2] = v0299;
    stack[-3] = v0298;
    goto v0177;

v0086:
    v0298 = stack[-3];
    if (v0298 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0298 = stack[-2];
        popv(6);
        return Lfloat(nil, v0298);
// error exit handlers
v0301:
    popv(6);
    return nil;
}



// Code for st_sorttree1

static LispObject CC_st_sorttree1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0364, v0365, v0366;
    LispObject fn;
    LispObject v0072, v0095, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0095 = va_arg(aa, LispObject);
    v0072 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for st_sorttree1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0072,v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0095,v0072);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-8] = v0072;
    stack[-9] = v0095;
    stack[-10] = v0000;
// end of prologue
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v0364 = (LispObject)17; // 1
    stack[-6] = v0364;
    v0364 = stack[-10];
    v0364 = qcdr(v0364);
    v0364 = qcar(v0364);
    if (is_number(v0364)) goto v0091;
    v0364 = stack[-10];
    v0365 = qcar(v0364);
    v0364 = elt(env, 1); // !*
    if (v0365 == v0364) goto v0206;
    v0364 = stack[-10];
    v0364 = qcdr(v0364);
    stack[0] = v0364;
    goto v0367;

v0367:
    v0364 = stack[0];
    if (v0364 == nil) goto v0368;
    v0364 = stack[0];
    v0364 = qcar(v0364);
    v0366 = v0364;
    v0365 = stack[-6];
    v0364 = (LispObject)1; // 0
    if (v0365 == v0364) goto v0369;
    v0365 = stack[-9];
    v0364 = stack[-8];
    v0364 = CC_st_sorttree1(env, 3, v0366, v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-2] = v0364;
    v0365 = stack[-6];
    v0364 = stack[-2];
    v0364 = qcdr(v0364);
    v0364 = qcar(v0364);
    v0364 = times2(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-6] = v0364;
    v0364 = stack[-2];
    v0364 = qcdr(v0364);
    v0366 = qcdr(v0364);
    v0364 = stack[-2];
    v0365 = qcar(v0364);
    v0364 = stack[-1];
    v0364 = acons(v0366, v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-1] = v0364;
    goto v0369;

v0369:
    v0364 = stack[0];
    v0364 = qcdr(v0364);
    stack[0] = v0364;
    goto v0367;

v0368:
    v0365 = stack[-6];
    v0364 = (LispObject)1; // 0
    if (v0365 == v0364) goto v0303;
    v0364 = stack[-10];
    v0365 = qcar(v0364);
    v0364 = elt(env, 3); // !+
    if (v0365 == v0364) goto v0371;
    v0365 = stack[-1];
    v0364 = stack[-8];
    fn = elt(env, 4); // cdr_signsort
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-1] = v0364;
    v0364 = stack[-1];
    v0365 = qcar(v0364);
    v0364 = (LispObject)1; // 0
    if (v0365 == v0364) goto v0372;
    v0365 = stack[-6];
    v0364 = stack[-1];
    v0364 = qcar(v0364);
    v0364 = times2(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-6] = v0364;
    v0364 = stack[-1];
    v0364 = qcdr(v0364);
    stack[-1] = v0364;
    goto v0373;

v0373:
    v0364 = stack[-1];
    if (v0364 == nil) goto v0374;
    v0364 = stack[-1];
    v0364 = qcar(v0364);
    v0365 = qcar(v0364);
    v0364 = stack[-7];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-7] = v0364;
    v0364 = stack[-1];
    v0364 = qcar(v0364);
    v0365 = qcdr(v0364);
    v0364 = stack[-11];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-11] = v0364;
    v0364 = stack[-1];
    v0364 = qcdr(v0364);
    stack[-1] = v0364;
    goto v0373;

v0374:
    v0364 = stack[-10];
    stack[0] = qcar(v0364);
    v0364 = stack[-7];
    v0364 = Lreverse(nil, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = cons(stack[0], v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-7] = v0364;
    v0364 = stack[-11];
    v0364 = Lreverse(nil, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    stack[-11] = v0364;
    v0366 = stack[-11];
    v0365 = stack[-6];
    v0364 = stack[-7];
    popv(13);
    return list2star(v0366, v0365, v0364);

v0372:
    v0365 = qvalue(elt(env, 2)); // nil
    v0364 = (LispObject)1; // 0
    v0366 = qvalue(elt(env, 2)); // nil
    popv(13);
    return list2star(v0365, v0364, v0366);

v0371:
    v0365 = stack[-1];
    v0364 = stack[-8];
    fn = elt(env, 5); // cdr_sort
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-1] = v0364;
    goto v0373;

v0303:
    v0365 = qvalue(elt(env, 2)); // nil
    v0364 = (LispObject)1; // 0
    v0366 = qvalue(elt(env, 2)); // nil
    popv(13);
    return list2star(v0365, v0364, v0366);

v0206:
    v0364 = stack[-10];
    v0364 = qcdr(v0364);
    stack[0] = v0364;
    goto v0224;

v0224:
    v0364 = stack[0];
    if (v0364 == nil) goto v0286;
    v0364 = stack[0];
    v0364 = qcar(v0364);
    v0366 = v0364;
    v0365 = stack[-6];
    v0364 = (LispObject)1; // 0
    if (v0365 == v0364) goto v0375;
    v0365 = stack[-9];
    v0364 = stack[-8];
    v0364 = CC_st_sorttree1(env, 3, v0366, v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-2] = v0364;
    v0365 = stack[-6];
    v0364 = stack[-2];
    v0364 = qcdr(v0364);
    v0364 = qcar(v0364);
    v0364 = times2(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-6] = v0364;
    v0364 = stack[-2];
    v0365 = qcar(v0364);
    v0364 = stack[-11];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-11] = v0364;
    v0364 = stack[-2];
    v0364 = qcdr(v0364);
    v0365 = qcdr(v0364);
    v0364 = stack[-7];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-7] = v0364;
    goto v0375;

v0375:
    v0364 = stack[0];
    v0364 = qcdr(v0364);
    stack[0] = v0364;
    goto v0224;

v0286:
    v0365 = stack[-6];
    v0364 = (LispObject)1; // 0
    if (v0365 == v0364) goto v0150;
    v0364 = stack[-7];
    v0364 = Lreverse(nil, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-7] = v0364;
    v0364 = stack[-11];
    v0364 = Lreverse(nil, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-11] = v0364;
    stack[0] = stack[-11];
    stack[-1] = stack[-6];
    v0365 = elt(env, 1); // !*
    v0364 = stack[-7];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    {
        LispObject v0376 = stack[0];
        LispObject v0377 = stack[-1];
        popv(13);
        return list2star(v0376, v0377, v0364);
    }

v0150:
    v0365 = qvalue(elt(env, 2)); // nil
    v0364 = (LispObject)1; // 0
    v0366 = qvalue(elt(env, 2)); // nil
    popv(13);
    return list2star(v0365, v0364, v0366);

v0091:
    v0364 = stack[-10];
    v0365 = qcar(v0364);
    v0364 = elt(env, 1); // !*
    if (v0365 == v0364) goto v0087;
    v0364 = stack[-10];
    v0364 = qcdr(v0364);
    stack[-5] = v0364;
    v0364 = stack[-5];
    if (v0364 == nil) goto v0122;
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    stack[-1] = v0364;
    stack[0] = stack[-9];
    v0364 = sub1(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0364/(16/CELL)));
    v0364 = cons(stack[-1], v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = ncons(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-3] = v0364;
    stack[-4] = v0364;
    goto v0075;

v0075:
    v0364 = stack[-5];
    v0364 = qcdr(v0364);
    stack[-5] = v0364;
    v0364 = stack[-5];
    if (v0364 == nil) goto v0297;
    stack[-2] = stack[-3];
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    stack[-1] = v0364;
    stack[0] = stack[-9];
    v0364 = sub1(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0364/(16/CELL)));
    v0364 = cons(stack[-1], v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = ncons(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = Lrplacd(nil, stack[-2], v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = stack[-3];
    v0364 = qcdr(v0364);
    stack[-3] = v0364;
    goto v0075;

v0297:
    v0364 = stack[-4];
    goto v0098;

v0098:
    stack[-1] = v0364;
    goto v0368;

v0122:
    v0364 = qvalue(elt(env, 2)); // nil
    goto v0098;

v0087:
    v0364 = stack[-10];
    v0364 = qcdr(v0364);
    stack[-4] = v0364;
    v0364 = stack[-4];
    if (v0364 == nil) goto v0059;
    v0364 = stack[-4];
    v0364 = qcar(v0364);
    stack[0] = stack[-9];
    v0364 = sub1(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0364/(16/CELL)));
    v0364 = ncons(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    stack[-2] = v0364;
    stack[-3] = v0364;
    goto v0197;

v0197:
    v0364 = stack[-4];
    v0364 = qcdr(v0364);
    stack[-4] = v0364;
    v0364 = stack[-4];
    if (v0364 == nil) goto v0055;
    stack[-1] = stack[-2];
    v0364 = stack[-4];
    v0364 = qcar(v0364);
    stack[0] = stack[-9];
    v0364 = sub1(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0364/(16/CELL)));
    v0364 = ncons(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = Lrplacd(nil, stack[-1], v0364);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-12];
    v0364 = stack[-2];
    v0364 = qcdr(v0364);
    stack[-2] = v0364;
    goto v0197;

v0055:
    v0364 = stack[-3];
    goto v0022;

v0022:
    stack[-11] = v0364;
    v0366 = stack[-11];
    v0365 = (LispObject)17; // 1
    v0364 = stack[-10];
    popv(13);
    return list2star(v0366, v0365, v0364);

v0059:
    v0364 = qvalue(elt(env, 2)); // nil
    goto v0022;
// error exit handlers
v0370:
    popv(13);
    return nil;
}



// Code for mri_irsplit1

static LispObject CC_mri_irsplit1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0193, v0378;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_irsplit1");
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
    stack[0] = v0000;
// end of prologue
    v0193 = stack[0];
    if (!consp(v0193)) goto v0109;
    v0193 = stack[0];
    v0193 = qcar(v0193);
    v0193 = (consp(v0193) ? nil : lisp_true);
    goto v0067;

v0067:
    if (v0193 == nil) goto v0198;
    v0193 = stack[0];
    popv(5);
    return ncons(v0193);

v0198:
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    v0193 = CC_mri_irsplit1(env, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    stack[-2] = v0193;
    v0193 = stack[0];
    v0193 = qcar(v0193);
    v0193 = qcar(v0193);
    v0193 = qcdr(v0193);
    stack[-1] = v0193;
    v0193 = stack[0];
    v0193 = qcar(v0193);
    v0193 = qcar(v0193);
    v0378 = qcar(v0193);
    v0193 = (LispObject)17; // 1
    fn = elt(env, 2); // to
    v0378 = (*qfn2(fn))(qenv(fn), v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    v0193 = (LispObject)17; // 1
    v0193 = cons(v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    v0378 = ncons(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    v0193 = stack[-1];
    fn = elt(env, 3); // exptf
    v0193 = (*qfn2(fn))(qenv(fn), v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    stack[-1] = v0193;
    v0193 = stack[-1];
    v0193 = qcar(v0193);
    v0193 = qcar(v0193);
    v0193 = qcar(v0193);
    fn = elt(env, 4); // mri_realvarp
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    if (v0193 == nil) goto v0018;
    v0193 = stack[-2];
    stack[-3] = qcar(v0193);
    v0193 = stack[0];
    v0193 = qcar(v0193);
    v0378 = qcdr(v0193);
    v0193 = stack[-1];
    fn = elt(env, 5); // multf
    v0378 = (*qfn2(fn))(qenv(fn), v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    v0193 = stack[-2];
    v0193 = qcdr(v0193);
    fn = elt(env, 6); // addf
    v0193 = (*qfn2(fn))(qenv(fn), v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    {
        LispObject v0179 = stack[-3];
        popv(5);
        return cons(v0179, v0193);
    }

v0018:
    v0193 = stack[0];
    v0193 = qcar(v0193);
    v0193 = qcdr(v0193);
    v0193 = CC_mri_irsplit1(env, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    stack[-3] = v0193;
    v0193 = stack[-3];
    v0378 = qcar(v0193);
    v0193 = stack[-1];
    fn = elt(env, 5); // multf
    v0378 = (*qfn2(fn))(qenv(fn), v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    v0193 = stack[-2];
    v0193 = qcar(v0193);
    fn = elt(env, 6); // addf
    stack[0] = (*qfn2(fn))(qenv(fn), v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    v0193 = stack[-3];
    v0378 = qcdr(v0193);
    v0193 = stack[-1];
    fn = elt(env, 5); // multf
    v0378 = (*qfn2(fn))(qenv(fn), v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    env = stack[-4];
    v0193 = stack[-2];
    v0193 = qcdr(v0193);
    fn = elt(env, 6); // addf
    v0193 = (*qfn2(fn))(qenv(fn), v0378, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0379;
    {
        LispObject v0118 = stack[0];
        popv(5);
        return cons(v0118, v0193);
    }

v0109:
    v0193 = qvalue(elt(env, 1)); // t
    goto v0067;
// error exit handlers
v0379:
    popv(5);
    return nil;
}



// Code for pasf_ordatp

static LispObject CC_pasf_ordatp(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0011, v0012, v0045, v0046, v0134, v0033;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_ordatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0046 = v0095;
    v0134 = v0000;
// end of prologue
    v0011 = v0134;
    v0011 = qcdr(v0011);
    v0011 = qcar(v0011);
    v0033 = v0011;
    v0011 = v0046;
    v0011 = qcdr(v0011);
    v0011 = qcar(v0011);
    v0045 = v0011;
    v0012 = v0033;
    v0011 = v0045;
    if (equal(v0012, v0011)) goto v0020;
    v0011 = v0033;
    v0012 = v0045;
    {
        popv(1);
        fn = elt(env, 4); // ordp
        return (*qfn2(fn))(qenv(fn), v0011, v0012);
    }

v0020:
    v0012 = v0134;
    v0011 = elt(env, 1); // true
    if (v0012 == v0011) goto v0211;
    v0012 = v0134;
    v0011 = elt(env, 3); // false
    v0011 = (v0012 == v0011 ? lisp_true : nil);
    goto v0058;

v0058:
    if (v0011 == nil) goto v0059;
    v0011 = v0134;
    v0045 = v0011;
    goto v0099;

v0099:
    v0012 = v0046;
    v0011 = elt(env, 1); // true
    if (v0012 == v0011) goto v0079;
    v0012 = v0046;
    v0011 = elt(env, 3); // false
    v0011 = (v0012 == v0011 ? lisp_true : nil);
    goto v0049;

v0049:
    if (v0011 == nil) goto v0078;
    v0011 = v0046;
    goto v0197;

v0197:
    {
        popv(1);
        fn = elt(env, 5); // pasf_ordrelp
        return (*qfn2(fn))(qenv(fn), v0045, v0011);
    }

v0078:
    v0011 = v0046;
    v0011 = qcar(v0011);
    v0011 = Lconsp(nil, v0011);
    env = stack[0];
    if (v0011 == nil) goto v0110;
    v0011 = v0046;
    v0011 = qcar(v0011);
    v0011 = qcar(v0011);
    goto v0197;

v0110:
    v0011 = v0046;
    v0011 = qcar(v0011);
    goto v0197;

v0079:
    v0011 = qvalue(elt(env, 2)); // t
    goto v0049;

v0059:
    v0011 = v0134;
    v0011 = qcar(v0011);
    v0011 = Lconsp(nil, v0011);
    env = stack[0];
    if (v0011 == nil) goto v0043;
    v0011 = v0134;
    v0011 = qcar(v0011);
    v0011 = qcar(v0011);
    v0045 = v0011;
    goto v0099;

v0043:
    v0011 = v0134;
    v0011 = qcar(v0011);
    v0045 = v0011;
    goto v0099;

v0211:
    v0011 = qvalue(elt(env, 2)); // t
    goto v0058;
}



// Code for dipcontenti

static LispObject CC_dipcontenti(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0053, v0054, v0103;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipcontenti");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0103 = v0000;
// end of prologue
    v0055 = v0103;
    if (v0055 == nil) goto v0044;
    v0055 = v0103;
    v0055 = qcdr(v0055);
    v0055 = qcdr(v0055);
    v0054 = v0055;
    v0055 = v0054;
    if (v0055 == nil) goto v0071;
    v0055 = v0103;
    v0055 = qcdr(v0055);
    v0053 = qcar(v0055);
    v0055 = qvalue(elt(env, 1)); // !*groebrm
    if (v0055 == nil) goto v0017;
    v0055 = v0103;
    v0055 = qcar(v0055);
    goto v0020;

v0020:
    {
        fn = elt(env, 3); // dipcontenti1
        return (*qfnn(fn))(qenv(fn), 3, v0053, v0055, v0054);
    }

v0017:
    v0055 = qvalue(elt(env, 2)); // nil
    goto v0020;

v0071:
    v0055 = v0103;
    v0055 = qcdr(v0055);
    v0053 = qcar(v0055);
    v0055 = qvalue(elt(env, 1)); // !*groebrm
    if (v0055 == nil) goto v0022;
    v0055 = v0103;
    v0055 = qcar(v0055);
    goto v0091;

v0091:
    return cons(v0053, v0055);

v0022:
    v0055 = qvalue(elt(env, 2)); // nil
    goto v0091;

v0044:
    v0055 = (LispObject)17; // 1
    return onevalue(v0055);
}



// Code for sqprla

static LispObject CC_sqprla(LispObject env,
                         LispObject v0000, LispObject v0095)
{
    LispObject nil = C_nil;
    LispObject v0116, v0067;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqprla");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0095,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0095);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0095;
    v0116 = v0000;
// end of prologue
    v0116 = qcar(v0116);
    fn = elt(env, 1); // prepsq!*
    v0067 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-1];
    v0116 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // maprintla
        return (*qfn2(fn))(qenv(fn), v0067, v0116);
    }
// error exit handlers
v0135:
    popv(2);
    return nil;
}



setup_type const u39_setup[] =
{
    {"gpexpp",                  CC_gpexpp,      too_many_1,    wrong_no_1},
    {"physopsubs",              CC_physopsubs,  too_many_1,    wrong_no_1},
    {"free",                    CC_free,        too_many_1,    wrong_no_1},
    {"expand-imrepartpow",      CC_expandKimrepartpow,too_many_1,wrong_no_1},
    {"groeb=testb",             too_few_2,      CC_groebMtestb,wrong_no_2},
    {"gigcd:",                  too_few_2,      CC_gigcdT,     wrong_no_2},
    {"mri_simplfloor1",         CC_mri_simplfloor1,too_many_1, wrong_no_1},
    {"coeffs",                  CC_coeffs,      too_many_1,    wrong_no_1},
    {"lengthn",                 CC_lengthn,     too_many_1,    wrong_no_1},
    {"ezgcdf1",                 too_few_2,      CC_ezgcdf1,    wrong_no_2},
    {"maprintla",               too_few_2,      CC_maprintla,  wrong_no_2},
    {"defined_vertex",          too_few_2,      CC_defined_vertex,wrong_no_2},
    {"general-modular-difference",too_few_2,    CC_generalKmodularKdifference,wrong_no_2},
    {"domainp_list",            CC_domainp_list,too_many_1,    wrong_no_1},
    {"change+sq+to+int",        CC_changeLsqLtoLint,too_many_1,wrong_no_1},
    {"rl_fvarl",                CC_rl_fvarl,    too_many_1,    wrong_no_1},
    {"ctx_get",                 too_few_2,      CC_ctx_get,    wrong_no_2},
    {"ezgcd-comfac",            CC_ezgcdKcomfac,too_many_1,    wrong_no_1},
    {"ps:zerop:",               CC_psTzeropT,   too_many_1,    wrong_no_1},
    {"reset_opnums",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_reset_opnums},
    {"fs:subang",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTsubang},
    {"mo_support",              CC_mo_support,  too_many_1,    wrong_no_1},
    {"sub01",                   too_few_2,      CC_sub01,      wrong_no_2},
    {"flattens1",               CC_flattens1,   too_many_1,    wrong_no_1},
    {"dv_skel2factor",          too_few_2,      CC_dv_skel2factor,wrong_no_2},
    {"add-factor",              too_few_2,      CC_addKfactor, wrong_no_2},
    {"mk_resimp_rep",           CC_mk_resimp_rep,too_many_1,   wrong_no_1},
    {"ofsf_pop",                CC_ofsf_pop,    too_many_1,    wrong_no_1},
    {"reprod",                  too_few_2,      CC_reprod,     wrong_no_2},
    {"groebcplistsort",         CC_groebcplistsort,too_many_1, wrong_no_1},
    {"pnth*",                   too_few_2,      CC_pnthH,      wrong_no_2},
    {"mk_names_map_2",          CC_mk_names_map_2,too_many_1,  wrong_no_1},
    {"rd:prin",                 CC_rdTprin,     too_many_1,    wrong_no_1},
    {"nextu",                   too_few_2,      CC_nextu,      wrong_no_2},
    {"depend-p",                too_few_2,      CC_dependKp,   wrong_no_2},
    {"pasf_lnegrel",            CC_pasf_lnegrel,too_many_1,    wrong_no_1},
    {"vdp_sugar",               CC_vdp_sugar,   too_many_1,    wrong_no_1},
    {"subs2pf",                 CC_subs2pf,     too_many_1,    wrong_no_1},
    {"lispcodeexp",             too_few_2,      CC_lispcodeexp,wrong_no_2},
    {"st_sorttree1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree1},
    {"mri_irsplit1",            CC_mri_irsplit1,too_many_1,    wrong_no_1},
    {"pasf_ordatp",             too_few_2,      CC_pasf_ordatp,wrong_no_2},
    {"dipcontenti",             CC_dipcontenti, too_many_1,    wrong_no_1},
    {"sqprla",                  too_few_2,      CC_sqprla,     wrong_no_2},
    {NULL, (one_args *)"u39", (two_args *)"7103 5284779 7266597", 0}
};

// end of generated code
