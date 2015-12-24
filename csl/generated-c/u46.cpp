
// $destdir/u46.c        Machine generated C code

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



// Code for fs!:zerop!:

static LispObject CC_fsTzeropT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007, v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:zerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0000;
// end of prologue
    v0006 = v0008;
    if (v0006 == nil) goto v0009;
    v0006 = v0008;
    if (is_number(v0006)) goto v0010;
    v0006 = v0008;
    v0006 = qcdr(v0006);
    v0006 = (v0006 == nil ? lisp_true : nil);
    goto v0011;

v0011:
    if (v0006 == nil) goto v0012;
    v0006 = qvalue(elt(env, 1)); // t
    return onevalue(v0006);

v0012:
    v0006 = v0008;
    v0007 = qcdr(v0006);
    v0006 = (LispObject)49; // 3
    v0006 = *(LispObject *)((char *)v0007 + (CELL-TAG_VECTOR) + ((int32_t)v0006/(16/CELL)));
    if (v0006 == nil) goto v0013;
    v0006 = qvalue(elt(env, 2)); // nil
    return onevalue(v0006);

v0013:
    v0006 = v0008;
    v0007 = qcdr(v0006);
    v0006 = (LispObject)1; // 0
    v0006 = *(LispObject *)((char *)v0007 + (CELL-TAG_VECTOR) + ((int32_t)v0006/(16/CELL)));
    v0007 = v0006;
    v0006 = v0007;
    if (is_number(v0006)) goto v0014;
    v0006 = qvalue(elt(env, 2)); // nil
    return onevalue(v0006);

v0014:
    v0006 = v0007;
        return Lzerop(nil, v0006);

v0010:
    v0006 = qvalue(elt(env, 2)); // nil
    goto v0011;

v0009:
    v0006 = qvalue(elt(env, 1)); // t
    return onevalue(v0006);
}



// Code for monic

static LispObject CC_monic(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0028, v0029;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monic");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0015;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0028 = stack[-3];
    v0028 = Lreverse(nil, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    stack[-3] = v0028;
    v0028 = qvalue(elt(env, 1)); // varlist!*
    v0028 = Llength(nil, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    stack[-1] = v0028;
    v0028 = (LispObject)17; // 1
    stack[0] = v0028;
    goto v0010;

v0010:
    v0029 = stack[-1];
    v0028 = stack[0];
    v0028 = difference2(v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    v0028 = Lminusp(nil, v0028);
    env = stack[-5];
    if (v0028 == nil) goto v0031;
    v0028 = qvalue(elt(env, 1)); // varlist!*
    v0028 = qcdr(v0028);
    stack[-3] = v0028;
    v0028 = stack[-3];
    if (v0028 == nil) goto v0032;
    v0028 = (LispObject)1; // 0
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    stack[-1] = v0028;
    stack[-2] = v0028;
    goto v0033;

v0033:
    v0028 = stack[-3];
    v0028 = qcdr(v0028);
    stack[-3] = v0028;
    v0028 = stack[-3];
    if (v0028 == nil) goto v0034;
    stack[0] = stack[-1];
    v0028 = (LispObject)1; // 0
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    v0028 = Lrplacd(nil, stack[0], v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    v0028 = stack[-1];
    v0028 = qcdr(v0028);
    stack[-1] = v0028;
    goto v0033;

v0034:
    v0028 = stack[-2];
    goto v0035;

v0035:
    v0028 = (equal(stack[-4], v0028) ? lisp_true : nil);
    { popv(6); return onevalue(v0028); }

v0032:
    v0028 = qvalue(elt(env, 2)); // nil
    goto v0035;

v0031:
    v0029 = stack[0];
    v0028 = stack[-2];
    if (equal(v0029, v0028)) goto v0036;
    v0029 = stack[-3];
    v0028 = stack[0];
    fn = elt(env, 3); // nth
    v0029 = (*qfn2(fn))(qenv(fn), v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    v0028 = stack[-4];
    v0028 = cons(v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    stack[-4] = v0028;
    goto v0036;

v0036:
    v0028 = stack[0];
    v0028 = add1(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    stack[0] = v0028;
    goto v0010;
// error exit handlers
v0030:
    popv(6);
    return nil;
}



// Code for st_sorttree1

static LispObject CC_st_sorttree1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0131, v0132, v0133;
    LispObject fn;
    LispObject v0059, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_sorttree1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0059 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for st_sorttree1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0059,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0015,v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-8] = v0059;
    stack[-9] = v0015;
    stack[-10] = v0000;
// end of prologue
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v0131 = (LispObject)17; // 1
    stack[-6] = v0131;
    v0131 = stack[-10];
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    if (is_number(v0131)) goto v0134;
    v0131 = stack[-10];
    v0132 = qcar(v0131);
    v0131 = elt(env, 1); // !*
    if (v0132 == v0131) goto v0135;
    v0131 = stack[-10];
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    goto v0136;

v0136:
    v0131 = stack[0];
    if (v0131 == nil) goto v0137;
    v0131 = stack[0];
    v0131 = qcar(v0131);
    v0133 = v0131;
    v0132 = stack[-6];
    v0131 = (LispObject)1; // 0
    if (v0132 == v0131) goto v0138;
    v0132 = stack[-9];
    v0131 = stack[-8];
    v0131 = CC_st_sorttree1(env, 3, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-2] = v0131;
    v0132 = stack[-6];
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = times2(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-6] = v0131;
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    v0133 = qcdr(v0131);
    v0131 = stack[-2];
    v0132 = qcar(v0131);
    v0131 = stack[-1];
    v0131 = acons(v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-1] = v0131;
    goto v0138;

v0138:
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    goto v0136;

v0137:
    v0132 = stack[-6];
    v0131 = (LispObject)1; // 0
    if (v0132 == v0131) goto v0140;
    v0131 = stack[-10];
    v0132 = qcar(v0131);
    v0131 = elt(env, 3); // !+
    if (v0132 == v0131) goto v0141;
    v0132 = stack[-1];
    v0131 = stack[-8];
    fn = elt(env, 4); // cdr_signsort
    v0131 = (*qfn2(fn))(qenv(fn), v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-1] = v0131;
    v0131 = stack[-1];
    v0132 = qcar(v0131);
    v0131 = (LispObject)1; // 0
    if (v0132 == v0131) goto v0142;
    v0132 = stack[-6];
    v0131 = stack[-1];
    v0131 = qcar(v0131);
    v0131 = times2(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-6] = v0131;
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    stack[-1] = v0131;
    goto v0143;

v0143:
    v0131 = stack[-1];
    if (v0131 == nil) goto v0144;
    v0131 = stack[-1];
    v0131 = qcar(v0131);
    v0132 = qcar(v0131);
    v0131 = stack[-7];
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-7] = v0131;
    v0131 = stack[-1];
    v0131 = qcar(v0131);
    v0132 = qcdr(v0131);
    v0131 = stack[-11];
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-11] = v0131;
    v0131 = stack[-1];
    v0131 = qcdr(v0131);
    stack[-1] = v0131;
    goto v0143;

v0144:
    v0131 = stack[-10];
    stack[0] = qcar(v0131);
    v0131 = stack[-7];
    v0131 = Lreverse(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = cons(stack[0], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-7] = v0131;
    v0131 = stack[-11];
    v0131 = Lreverse(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    stack[-11] = v0131;
    v0133 = stack[-11];
    v0132 = stack[-6];
    v0131 = stack[-7];
    popv(13);
    return list2star(v0133, v0132, v0131);

v0142:
    v0132 = qvalue(elt(env, 2)); // nil
    v0131 = (LispObject)1; // 0
    v0133 = qvalue(elt(env, 2)); // nil
    popv(13);
    return list2star(v0132, v0131, v0133);

v0141:
    v0132 = stack[-1];
    v0131 = stack[-8];
    fn = elt(env, 5); // cdr_sort
    v0131 = (*qfn2(fn))(qenv(fn), v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-1] = v0131;
    goto v0143;

v0140:
    v0132 = qvalue(elt(env, 2)); // nil
    v0131 = (LispObject)1; // 0
    v0133 = qvalue(elt(env, 2)); // nil
    popv(13);
    return list2star(v0132, v0131, v0133);

v0135:
    v0131 = stack[-10];
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    goto v0145;

v0145:
    v0131 = stack[0];
    if (v0131 == nil) goto v0146;
    v0131 = stack[0];
    v0131 = qcar(v0131);
    v0133 = v0131;
    v0132 = stack[-6];
    v0131 = (LispObject)1; // 0
    if (v0132 == v0131) goto v0147;
    v0132 = stack[-9];
    v0131 = stack[-8];
    v0131 = CC_st_sorttree1(env, 3, v0133, v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-2] = v0131;
    v0132 = stack[-6];
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    v0131 = times2(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-6] = v0131;
    v0131 = stack[-2];
    v0132 = qcar(v0131);
    v0131 = stack[-11];
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-11] = v0131;
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    v0132 = qcdr(v0131);
    v0131 = stack[-7];
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-7] = v0131;
    goto v0147;

v0147:
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    goto v0145;

v0146:
    v0132 = stack[-6];
    v0131 = (LispObject)1; // 0
    if (v0132 == v0131) goto v0148;
    v0131 = stack[-7];
    v0131 = Lreverse(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-7] = v0131;
    v0131 = stack[-11];
    v0131 = Lreverse(nil, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-11] = v0131;
    stack[0] = stack[-11];
    stack[-1] = stack[-6];
    v0132 = elt(env, 1); // !*
    v0131 = stack[-7];
    v0131 = cons(v0132, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    {
        LispObject v0149 = stack[0];
        LispObject v0150 = stack[-1];
        popv(13);
        return list2star(v0149, v0150, v0131);
    }

v0148:
    v0132 = qvalue(elt(env, 2)); // nil
    v0131 = (LispObject)1; // 0
    v0133 = qvalue(elt(env, 2)); // nil
    popv(13);
    return list2star(v0132, v0131, v0133);

v0134:
    v0131 = stack[-10];
    v0132 = qcar(v0131);
    v0131 = elt(env, 1); // !*
    if (v0132 == v0131) goto v0151;
    v0131 = stack[-10];
    v0131 = qcdr(v0131);
    stack[-5] = v0131;
    v0131 = stack[-5];
    if (v0131 == nil) goto v0152;
    v0131 = stack[-5];
    v0131 = qcar(v0131);
    stack[-1] = v0131;
    stack[0] = stack[-9];
    v0131 = sub1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0131/(16/CELL)));
    v0131 = cons(stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-3] = v0131;
    stack[-4] = v0131;
    goto v0153;

v0153:
    v0131 = stack[-5];
    v0131 = qcdr(v0131);
    stack[-5] = v0131;
    v0131 = stack[-5];
    if (v0131 == nil) goto v0154;
    stack[-2] = stack[-3];
    v0131 = stack[-5];
    v0131 = qcar(v0131);
    stack[-1] = v0131;
    stack[0] = stack[-9];
    v0131 = sub1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0131/(16/CELL)));
    v0131 = cons(stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = Lrplacd(nil, stack[-2], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = stack[-3];
    v0131 = qcdr(v0131);
    stack[-3] = v0131;
    goto v0153;

v0154:
    v0131 = stack[-4];
    goto v0155;

v0155:
    stack[-1] = v0131;
    goto v0137;

v0152:
    v0131 = qvalue(elt(env, 2)); // nil
    goto v0155;

v0151:
    v0131 = stack[-10];
    v0131 = qcdr(v0131);
    stack[-4] = v0131;
    v0131 = stack[-4];
    if (v0131 == nil) goto v0013;
    v0131 = stack[-4];
    v0131 = qcar(v0131);
    stack[0] = stack[-9];
    v0131 = sub1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0131/(16/CELL)));
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    stack[-2] = v0131;
    stack[-3] = v0131;
    goto v0156;

v0156:
    v0131 = stack[-4];
    v0131 = qcdr(v0131);
    stack[-4] = v0131;
    v0131 = stack[-4];
    if (v0131 == nil) goto v0157;
    stack[-1] = stack[-2];
    v0131 = stack[-4];
    v0131 = qcar(v0131);
    stack[0] = stack[-9];
    v0131 = sub1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0131/(16/CELL)));
    v0131 = ncons(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = Lrplacd(nil, stack[-1], v0131);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-12];
    v0131 = stack[-2];
    v0131 = qcdr(v0131);
    stack[-2] = v0131;
    goto v0156;

v0157:
    v0131 = stack[-3];
    goto v0158;

v0158:
    stack[-11] = v0131;
    v0133 = stack[-11];
    v0132 = (LispObject)17; // 1
    v0131 = stack[-10];
    popv(13);
    return list2star(v0133, v0132, v0131);

v0013:
    v0131 = qvalue(elt(env, 2)); // nil
    goto v0158;
// error exit handlers
v0139:
    popv(13);
    return nil;
}



// Code for monic!-mod!-p

static LispObject CC_monicKmodKp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0008, v0016, v0160;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monic-mod-p");
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
    v0160 = v0000;
// end of prologue
    v0008 = v0160;
    if (v0008 == nil) goto v0009;
    v0008 = v0160;
    if (!consp(v0008)) goto v0161;
    v0008 = v0160;
    v0008 = qcar(v0008);
    v0008 = (consp(v0008) ? nil : lisp_true);
    goto v0021;

v0021:
    if (v0008 == nil) goto v0162;
    v0008 = (LispObject)17; // 1
    { popv(2); return onevalue(v0008); }

v0162:
    v0008 = v0160;
    v0008 = qcar(v0008);
    v0016 = qcdr(v0008);
    v0008 = (LispObject)17; // 1
    if (v0016 == v0008) { popv(2); return onevalue(v0160); }
    v0008 = v0160;
    v0008 = qcar(v0008);
    v0008 = qcdr(v0008);
    if (!consp(v0008)) goto v0003;
    v0008 = v0160;
    v0008 = qcar(v0008);
    v0008 = qcdr(v0008);
    v0008 = qcar(v0008);
    v0008 = (consp(v0008) ? nil : lisp_true);
    goto v0163;

v0163:
    if (v0008 == nil) goto v0031;
    stack[0] = v0160;
    v0008 = v0160;
    v0008 = qcar(v0008);
    v0008 = qcdr(v0008);
    v0008 = Lmodular_reciprocal(nil, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-1];
    {
        LispObject v0165 = stack[0];
        popv(2);
        fn = elt(env, 4); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0165, v0008);
    }

v0031:
    v0008 = elt(env, 3); // "LC NOT NUMERIC IN MONIC-MOD-P"
    {
        popv(2);
        fn = elt(env, 5); // errorf
        return (*qfn1(fn))(qenv(fn), v0008);
    }

v0003:
    v0008 = qvalue(elt(env, 2)); // t
    goto v0163;

v0161:
    v0008 = qvalue(elt(env, 2)); // t
    goto v0021;

v0009:
    v0008 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0008); }
// error exit handlers
v0164:
    popv(2);
    return nil;
}



// Code for nextu

static LispObject CC_nextu(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0170, v0171, v0172;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nextu");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0171 = v0015;
    stack[0] = v0000;
// end of prologue
    v0170 = stack[0];
    if (v0170 == nil) goto v0042;
    v0172 = v0171;
    v0170 = stack[0];
    v0171 = qcar(v0170);
    v0170 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 3); // subtractinds
    v0170 = (*qfnn(fn))(qenv(fn), 3, v0172, v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    stack[-1] = v0170;
    v0170 = stack[-1];
    if (v0170 == nil) goto v0129;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    v0171 = qcar(v0170);
    v0170 = stack[-1];
    fn = elt(env, 4); // evaluatecoeffts
    v0170 = (*qfn2(fn))(qenv(fn), v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    v0172 = v0170;
    v0170 = v0172;
    if (v0170 == nil) goto v0173;
    v0171 = v0172;
    v0170 = (LispObject)1; // 0
    v0170 = (v0171 == v0170 ? lisp_true : nil);
    goto v0002;

v0002:
    if (v0170 == nil) goto v0007;
    v0170 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0170); }

v0007:
    v0171 = stack[-1];
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    v0170 = qcdr(v0170);
    popv(3);
    return list2star(v0171, v0172, v0170);

v0173:
    v0170 = qvalue(elt(env, 2)); // t
    goto v0002;

v0129:
    v0170 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0170); }

v0042:
    v0170 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0170); }
// error exit handlers
v0125:
    popv(3);
    return nil;
}



// Code for sqfrf

static LispObject CC_sqfrf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0054, v0236, v0237, v0238;
    LispObject fn;
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
    v0054 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 1)) = v0054; // !*gcd
    v0054 = qvalue(elt(env, 4)); // !*rounded
    stack[-1] = v0054;
    if (v0054 == nil) goto v0239;
    v0054 = elt(env, 5); // rational
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    fn = elt(env, 12); // on
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0236 = stack[-9];
    v0054 = (LispObject)17; // 1
    v0054 = cons(v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    fn = elt(env, 13); // resimp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = qcar(v0054);
    stack[-9] = v0054;
    goto v0239;

v0239:
    v0054 = (LispObject)17; // 1
    stack[-10] = v0054;
    v0054 = stack[-9];
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    stack[-4] = v0054;
    v0054 = qvalue(elt(env, 3)); // t
    stack[0] = qvalue(elt(env, 6)); // !*ezgcd
    qvalue(elt(env, 6)) = v0054; // !*ezgcd
    stack[-6] = stack[-9];
    v0236 = stack[-9];
    v0054 = stack[-4];
    fn = elt(env, 14); // diff
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-11];
    fn = elt(env, 15); // gcdf
    v0054 = (*qfn2(fn))(qenv(fn), stack[-6], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-11];
    stack[-6] = v0054;
    qvalue(elt(env, 6)) = stack[0]; // !*ezgcd
    v0236 = stack[-9];
    v0054 = stack[-6];
    fn = elt(env, 16); // quotf!-fail
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-9] = v0054;
    v0054 = qvalue(elt(env, 7)); // dmode!*
    if (!symbolp(v0054)) v0054 = nil;
    else { v0054 = qfastgets(v0054);
           if (v0054 != nil) { v0054 = elt(v0054, 3); // field
#ifdef RECORD_GET
             if (v0054 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0054 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0054 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0054 == SPID_NOPROP) v0054 = nil; else v0054 = lisp_true; }}
#endif
    if (v0054 == nil) goto v0126;
    v0054 = stack[-9];
    fn = elt(env, 17); // lnc
    v0236 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-3] = v0236;
    v0054 = (LispObject)17; // 1
    v0054 = Lneq(nil, v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    goto v0033;

v0033:
    if (v0054 == nil) goto v0242;
    v0054 = stack[-3];
    fn = elt(env, 18); // !:recip
    v0236 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = stack[-9];
    fn = elt(env, 19); // multd
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-9] = v0054;
    v0236 = stack[-3];
    v0054 = stack[-6];
    fn = elt(env, 19); // multd
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-6] = v0054;
    goto v0242;

v0242:
    v0236 = stack[-6];
    v0054 = stack[-4];
    fn = elt(env, 20); // degr
    v0236 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = (LispObject)1; // 0
    v0054 = (LispObject)greaterp2(v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    v0054 = v0054 ? lisp_true : nil;
    env = stack[-11];
    if (v0054 == nil) goto v0153;
    v0236 = stack[-6];
    v0054 = stack[-9];
    fn = elt(env, 15); // gcdf
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[0] = v0054;
    v0236 = stack[-9];
    v0054 = stack[0];
    if (equal(v0236, v0054)) goto v0111;
    v0236 = stack[-9];
    v0054 = stack[0];
    fn = elt(env, 21); // quotf
    v0237 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0236 = stack[-10];
    v0054 = stack[-2];
    v0054 = acons(v0237, v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-2] = v0054;
    goto v0111;

v0111:
    v0236 = stack[-6];
    v0054 = stack[0];
    fn = elt(env, 21); // quotf
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-6] = v0054;
    v0054 = stack[0];
    stack[-9] = v0054;
    v0054 = stack[-10];
    v0054 = add1(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-10] = v0054;
    goto v0242;

v0153:
    v0054 = stack[-1];
    if (v0054 == nil) goto v0243;
    v0054 = elt(env, 9); // rounded
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    fn = elt(env, 12); // on
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0236 = stack[-9];
    v0054 = (LispObject)17; // 1
    v0054 = cons(v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    fn = elt(env, 13); // resimp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = qcar(v0054);
    stack[-9] = v0054;
    v0054 = stack[-2];
    stack[-4] = v0054;
    v0054 = stack[-4];
    if (v0054 == nil) goto v0147;
    v0054 = stack[-4];
    v0054 = qcar(v0054);
    stack[0] = v0054;
    v0054 = stack[0];
    v0236 = qcar(v0054);
    v0054 = (LispObject)17; // 1
    v0054 = cons(v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    fn = elt(env, 13); // resimp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0236 = qcar(v0054);
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    v0054 = cons(v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-2] = v0054;
    stack[-3] = v0054;
    goto v0244;

v0244:
    v0054 = stack[-4];
    v0054 = qcdr(v0054);
    stack[-4] = v0054;
    v0054 = stack[-4];
    if (v0054 == nil) goto v0245;
    stack[-1] = stack[-2];
    v0054 = stack[-4];
    v0054 = qcar(v0054);
    stack[0] = v0054;
    v0054 = stack[0];
    v0236 = qcar(v0054);
    v0054 = (LispObject)17; // 1
    v0054 = cons(v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    fn = elt(env, 13); // resimp
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0236 = qcar(v0054);
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    v0054 = cons(v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = Lrplacd(nil, stack[-1], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = stack[-2];
    v0054 = qcdr(v0054);
    stack[-2] = v0054;
    goto v0244;

v0245:
    v0054 = stack[-3];
    goto v0246;

v0246:
    stack[-2] = v0054;
    goto v0243;

v0243:
    v0236 = stack[-6];
    v0054 = (LispObject)17; // 1
    if (v0236 == v0054) goto v0081;
    v0236 = stack[-6];
    v0054 = stack[-7];
    v0054 = Lassoc(nil, v0236, v0054);
    goto v0087;

v0087:
    if (v0054 == nil) goto v0085;
    v0054 = (LispObject)17; // 1
    stack[-6] = v0054;
    goto v0085;

v0085:
    v0236 = stack[-6];
    v0054 = (LispObject)17; // 1
    if (v0236 == v0054) goto v0247;
    v0236 = stack[-10];
    v0054 = (LispObject)17; // 1
    if (v0236 == v0054) goto v0248;
    v0236 = (LispObject)17; // 1
    v0054 = stack[-2];
    fn = elt(env, 22); // rassoc
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[0] = v0054;
    if (v0054 == nil) goto v0078;
    stack[-1] = stack[0];
    v0236 = stack[-6];
    v0054 = stack[0];
    v0054 = qcar(v0054);
    fn = elt(env, 23); // multf
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    v0054 = Lrplaca(nil, stack[-1], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    goto v0247;

v0247:
    v0237 = stack[-9];
    v0236 = stack[-10];
    v0054 = stack[-2];
    v0054 = acons(v0237, v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    qvalue(elt(env, 2)) = stack[-5]; // !*msg
    qvalue(elt(env, 1)) = stack[-8]; // !*gcd
    { popv(12); return onevalue(v0054); }

v0078:
    v0054 = stack[-2];
    if (v0054 == nil) goto v0249;
    v0054 = qvalue(elt(env, 8)); // nil
    goto v0250;

v0250:
    if (v0054 == nil) goto v0251;
    v0236 = stack[0];
    v0054 = stack[-9];
    fn = elt(env, 23); // multf
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-9] = v0054;
    goto v0247;

v0251:
    v0054 = stack[-6];
    if (!consp(v0054)) goto v0252;
    v0054 = stack[-6];
    v0054 = qcar(v0054);
    v0054 = (consp(v0054) ? nil : lisp_true);
    goto v0066;

v0066:
    if (v0054 == nil) goto v0062;
    v0238 = elt(env, 11); // "sqfrf failure"
    v0237 = stack[-9];
    v0236 = stack[-10];
    v0054 = stack[-2];
    v0054 = list4(v0238, v0237, v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    fn = elt(env, 24); // errach
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    goto v0247;

v0062:
    stack[0] = stack[-2];
    v0236 = stack[-6];
    v0054 = (LispObject)17; // 1
    v0054 = cons(v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    fn = elt(env, 25); // aconc
    v0054 = (*qfn2(fn))(qenv(fn), stack[0], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-2] = v0054;
    goto v0247;

v0252:
    v0054 = qvalue(elt(env, 3)); // t
    goto v0066;

v0249:
    v0236 = stack[-6];
    v0054 = stack[-10];
    fn = elt(env, 26); // rootxf
    v0236 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[0] = v0236;
    v0054 = elt(env, 10); // failed
    v0054 = Lneq(nil, v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    goto v0250;

v0248:
    v0236 = stack[-6];
    v0054 = stack[-9];
    fn = elt(env, 23); // multf
    v0054 = (*qfn2(fn))(qenv(fn), v0236, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-11];
    stack[-9] = v0054;
    goto v0247;

v0081:
    v0054 = qvalue(elt(env, 8)); // nil
    goto v0087;

v0147:
    v0054 = qvalue(elt(env, 8)); // nil
    goto v0246;

v0126:
    v0054 = qvalue(elt(env, 8)); // nil
    goto v0033;
// error exit handlers
v0241:
    env = stack[-11];
    qvalue(elt(env, 6)) = stack[0]; // !*ezgcd
    qvalue(elt(env, 2)) = stack[-5]; // !*msg
    qvalue(elt(env, 1)) = stack[-8]; // !*gcd
    popv(12);
    return nil;
v0240:
    env = stack[-11];
    qvalue(elt(env, 2)) = stack[-5]; // !*msg
    qvalue(elt(env, 1)) = stack[-8]; // !*gcd
    popv(12);
    return nil;
}



// Code for dipcontenti

static LispObject CC_dipcontenti(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0157, v0017, v0006, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipcontenti");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0000;
// end of prologue
    v0157 = v0007;
    if (v0157 == nil) goto v0009;
    v0157 = v0007;
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0006 = v0157;
    v0157 = v0006;
    if (v0157 == nil) goto v0256;
    v0157 = v0007;
    v0157 = qcdr(v0157);
    v0017 = qcar(v0157);
    v0157 = qvalue(elt(env, 1)); // !*groebrm
    if (v0157 == nil) goto v0257;
    v0157 = v0007;
    v0157 = qcar(v0157);
    goto v0258;

v0258:
    {
        fn = elt(env, 3); // dipcontenti1
        return (*qfnn(fn))(qenv(fn), 3, v0017, v0157, v0006);
    }

v0257:
    v0157 = qvalue(elt(env, 2)); // nil
    goto v0258;

v0256:
    v0157 = v0007;
    v0157 = qcdr(v0157);
    v0017 = qcar(v0157);
    v0157 = qvalue(elt(env, 1)); // !*groebrm
    if (v0157 == nil) goto v0158;
    v0157 = v0007;
    v0157 = qcar(v0157);
    goto v0134;

v0134:
    return cons(v0017, v0157);

v0158:
    v0157 = qvalue(elt(env, 2)); // nil
    goto v0134;

v0009:
    v0157 = (LispObject)17; // 1
    return onevalue(v0157);
}



// Code for ratmean

static LispObject CC_ratmean(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0005, v0011, v0259;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratmean");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0005 = v0015;
    v0011 = v0000;
// end of prologue
    v0259 = v0011;
    v0011 = v0005;
    v0005 = qvalue(elt(env, 1)); // t
    {
        fn = elt(env, 2); // ratplusm
        return (*qfnn(fn))(qenv(fn), 3, v0259, v0011, v0005);
    }
}



// Code for mk_parents_prim

static LispObject CC_mk_parents_prim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
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
    v0003 = stack[0];
    v0004 = Llength(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    v0003 = (LispObject)49; // 3
    if (!(v0004 == v0003)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0003 = stack[0];
    fn = elt(env, 1); // s_noparents
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    v0004 = v0003;
    if (v0004 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0004 = stack[0];
    v0003 = qcar(v0003);
    fn = elt(env, 2); // mk_edge_parents
    v0003 = (*qfn2(fn))(qenv(fn), v0004, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0013:
    popv(2);
    return nil;
}



// Code for mo!=expvec2a1

static LispObject CC_moMexpvec2a1(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0170, v0171, v0172;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=expvec2a1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0015;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0040;

v0040:
    v0170 = stack[-1];
    if (v0170 == nil) goto v0175;
    v0170 = stack[-1];
    v0171 = qcar(v0170);
    v0170 = (LispObject)1; // 0
    if (v0171 == v0170) goto v0005;
    v0170 = stack[-1];
    v0171 = qcar(v0170);
    v0170 = (LispObject)17; // 1
    if (v0171 == v0170) goto v0004;
    v0172 = elt(env, 1); // expt
    v0170 = stack[0];
    v0171 = qcar(v0170);
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0171 = list3(v0172, v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    v0170 = stack[-2];
    v0170 = cons(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    stack[-2] = v0170;
    v0170 = stack[-1];
    v0170 = qcdr(v0170);
    stack[-1] = v0170;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    stack[0] = v0170;
    goto v0040;

v0004:
    v0170 = stack[0];
    v0171 = qcar(v0170);
    v0170 = stack[-2];
    v0170 = cons(v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    stack[-2] = v0170;
    v0170 = stack[-1];
    v0170 = qcdr(v0170);
    stack[-1] = v0170;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    stack[0] = v0170;
    goto v0040;

v0005:
    v0170 = stack[-1];
    v0170 = qcdr(v0170);
    stack[-1] = v0170;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    stack[0] = v0170;
    goto v0040;

v0175:
    v0170 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0170);
    }
// error exit handlers
v0126:
    popv(4);
    return nil;
}



// Code for impartsq

static LispObject CC_impartsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0032, v0264, v0127, v0170;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for impartsq");
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
    v0032 = stack[0];
    v0032 = qcar(v0032);
    fn = elt(env, 1); // splitcomplex
    stack[-1] = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    fn = elt(env, 1); // splitcomplex
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0264 = stack[-1];
    v0127 = v0264;
    v0170 = qcar(v0127);
    v0127 = qcdr(v0264);
    v0264 = v0032;
    v0264 = qcar(v0264);
    v0032 = qcdr(v0032);
    stack[-3] = v0170;
    stack[-2] = v0264;
    stack[-1] = v0032;
    v0264 = v0127;
    v0032 = stack[-2];
    fn = elt(env, 2); // multsq
    stack[0] = (*qfn2(fn))(qenv(fn), v0264, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0264 = stack[-3];
    v0032 = stack[-1];
    fn = elt(env, 2); // multsq
    v0032 = (*qfn2(fn))(qenv(fn), v0264, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    fn = elt(env, 3); // negsq
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    fn = elt(env, 4); // addsq
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0264 = stack[-2];
    v0032 = stack[-2];
    fn = elt(env, 2); // multsq
    stack[-2] = (*qfn2(fn))(qenv(fn), v0264, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0264 = stack[-1];
    v0032 = stack[-1];
    fn = elt(env, 2); // multsq
    v0032 = (*qfn2(fn))(qenv(fn), v0264, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    fn = elt(env, 4); // addsq
    v0032 = (*qfn2(fn))(qenv(fn), stack[-2], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    fn = elt(env, 5); // invsq
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    {
        LispObject v0126 = stack[0];
        popv(5);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0126, v0032);
    }
// error exit handlers
v0125:
    popv(5);
    return nil;
}



// Code for mri_irsplit1

static LispObject CC_mri_irsplit1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0276, v0277;
    LispObject fn;
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
    v0276 = stack[0];
    if (!consp(v0276)) goto v0011;
    v0276 = stack[0];
    v0276 = qcar(v0276);
    v0276 = (consp(v0276) ? nil : lisp_true);
    goto v0005;

v0005:
    if (v0276 == nil) goto v0159;
    v0276 = stack[0];
    popv(5);
    return ncons(v0276);

v0159:
    v0276 = stack[0];
    v0276 = qcdr(v0276);
    v0276 = CC_mri_irsplit1(env, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-2] = v0276;
    v0276 = stack[0];
    v0276 = qcar(v0276);
    v0276 = qcar(v0276);
    v0276 = qcdr(v0276);
    stack[-1] = v0276;
    v0276 = stack[0];
    v0276 = qcar(v0276);
    v0276 = qcar(v0276);
    v0277 = qcar(v0276);
    v0276 = (LispObject)17; // 1
    fn = elt(env, 2); // to
    v0277 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0276 = (LispObject)17; // 1
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0277 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0276 = stack[-1];
    fn = elt(env, 3); // exptf
    v0276 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-1] = v0276;
    v0276 = stack[-1];
    v0276 = qcar(v0276);
    v0276 = qcar(v0276);
    v0276 = qcar(v0276);
    fn = elt(env, 4); // mri_realvarp
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    if (v0276 == nil) goto v0166;
    v0276 = stack[-2];
    stack[-3] = qcar(v0276);
    v0276 = stack[0];
    v0276 = qcar(v0276);
    v0277 = qcdr(v0276);
    v0276 = stack[-1];
    fn = elt(env, 5); // multf
    v0277 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0276 = stack[-2];
    v0276 = qcdr(v0276);
    fn = elt(env, 6); // addf
    v0276 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    {
        LispObject v0278 = stack[-3];
        popv(5);
        return cons(v0278, v0276);
    }

v0166:
    v0276 = stack[0];
    v0276 = qcar(v0276);
    v0276 = qcdr(v0276);
    v0276 = CC_mri_irsplit1(env, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-3] = v0276;
    v0276 = stack[-3];
    v0277 = qcar(v0276);
    v0276 = stack[-1];
    fn = elt(env, 5); // multf
    v0277 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0276 = stack[-2];
    v0276 = qcar(v0276);
    fn = elt(env, 6); // addf
    stack[0] = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0276 = stack[-3];
    v0277 = qcdr(v0276);
    v0276 = stack[-1];
    fn = elt(env, 5); // multf
    v0277 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0276 = stack[-2];
    v0276 = qcdr(v0276);
    fn = elt(env, 6); // addf
    v0276 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    {
        LispObject v0279 = stack[0];
        popv(5);
        return cons(v0279, v0276);
    }

v0011:
    v0276 = qvalue(elt(env, 1)); // t
    goto v0005;
// error exit handlers
v0228:
    popv(5);
    return nil;
}



// Code for qqe_length!-graph!-neighbor!-edge

static LispObject CC_qqe_lengthKgraphKneighborKedge(LispObject env,
                         LispObject v0000)
{
    LispObject v0040;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbor-edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0040 = v0000;
// end of prologue
    v0040 = qcdr(v0040);
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    return onevalue(v0040);
}



// Code for pasf_dnf

static LispObject CC_pasf_dnf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0169, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_dnf");
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
    v0026 = stack[0];
    v0169 = elt(env, 1); // and
    fn = elt(env, 3); // pasf_puregconp
    v0169 = (*qfn2(fn))(qenv(fn), v0026, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    if (!(v0169 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0169 = stack[0];
    fn = elt(env, 4); // pasf_pnf
    v0026 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    v0169 = elt(env, 2); // dnf
    {
        popv(2);
        fn = elt(env, 5); // pasf_pbnf
        return (*qfn2(fn))(qenv(fn), v0026, v0169);
    }
// error exit handlers
v0129:
    popv(2);
    return nil;
}



// Code for subs2pf

static LispObject CC_subs2pf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004, v0025;
    LispObject fn;
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

v0280:
    v0003 = stack[0];
    if (v0003 == nil) goto v0042;
    v0003 = stack[0];
    v0003 = qcar(v0003);
    v0003 = qcdr(v0003);
    fn = elt(env, 1); // resimp
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    fn = elt(env, 2); // subs2
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    v0004 = v0003;
    v0004 = qcar(v0004);
    if (v0004 == nil) goto v0128;
    v0004 = stack[0];
    v0004 = qcar(v0004);
    v0025 = qcar(v0004);
    v0004 = v0003;
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    popv(2);
    return acons(v0025, v0004, v0003);

v0128:
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    stack[0] = v0003;
    goto v0280;

v0042:
    v0003 = nil;
    { popv(2); return onevalue(v0003); }
// error exit handlers
v0167:
    popv(2);
    return nil;
}



// Code for lispcodeexp

static LispObject CC_lispcodeexp(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0337, v0338, v0339;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispcodeexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0015;
    stack[-2] = v0000;
// end of prologue

v0280:
    v0337 = stack[-2];
    if (is_number(v0337)) goto v0041;
    v0338 = stack[-2];
    v0337 = elt(env, 1); // e
    if (v0338 == v0337) goto v0156;
    v0337 = stack[-2];
    if (!consp(v0337)) goto v0002;
    v0337 = stack[-2];
    v0338 = qcar(v0337);
    v0337 = elt(env, 5); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    v0337 = Lmemq(nil, v0338, v0337);
    goto v0001;

v0001:
    if (v0337 == nil) goto v0235;
    v0337 = qvalue(elt(env, 6)); // irena!-constants
    if (v0337 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0337 = stack[-2];
    if (v0337 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0337 = stack[-2];
    v0337 = Lstringp(nil, v0337);
    env = stack[-5];
    if (!(v0337 == nil)) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0337 = stack[-2];
    fn = elt(env, 21); // check!-for!-irena!-constants
    v0337 = (*qfn1(fn))(qenv(fn), v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    { LispObject res = stack[-2]; popv(6); return onevalue(res); }

v0235:
    v0337 = stack[-2];
    v0338 = qcar(v0337);
    v0337 = elt(env, 7); // expt
    if (v0338 == v0337) goto v0233;
    v0337 = stack[-2];
    v0338 = qcar(v0337);
    v0337 = elt(env, 12); // quotient
    if (v0338 == v0337) goto v0202;
    v0337 = stack[-2];
    v0338 = qcar(v0337);
    v0337 = elt(env, 14); // recip
    if (v0338 == v0337) goto v0341;
    v0337 = stack[-2];
    v0338 = qcar(v0337);
    v0337 = elt(env, 16); // difference
    if (v0338 == v0337) goto v0140;
    v0337 = stack[-2];
    v0338 = qcar(v0337);
    v0337 = qvalue(elt(env, 19)); // !*lisparithexpops!*
    v0337 = Lmemq(nil, v0338, v0337);
    if (v0337 == nil) goto v0055;
    v0337 = qvalue(elt(env, 13)); // nil
    goto v0058;

v0058:
    if (v0337 == nil) goto v0342;
    v0337 = stack[-2];
    stack[-3] = v0337;
    v0337 = stack[-3];
    if (v0337 == nil) goto v0051;
    v0337 = stack[-3];
    v0337 = qcar(v0337);
    v0338 = v0337;
    v0337 = qvalue(elt(env, 13)); // nil
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = ncons(v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    stack[-1] = v0337;
    stack[-2] = v0337;
    goto v0343;

v0343:
    v0337 = stack[-3];
    v0337 = qcdr(v0337);
    stack[-3] = v0337;
    v0337 = stack[-3];
    if (v0337 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0337 = stack[-3];
    v0337 = qcar(v0337);
    v0338 = v0337;
    v0337 = qvalue(elt(env, 13)); // nil
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = ncons(v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = Lrplacd(nil, stack[0], v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = stack[-1];
    v0337 = qcdr(v0337);
    stack[-1] = v0337;
    goto v0343;

v0051:
    v0337 = qvalue(elt(env, 13)); // nil
    { popv(6); return onevalue(v0337); }

v0342:
    v0337 = stack[-2];
    stack[-4] = v0337;
    v0337 = stack[-4];
    if (v0337 == nil) goto v0038;
    v0337 = stack[-4];
    v0337 = qcar(v0337);
    v0338 = v0337;
    v0337 = stack[-3];
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = ncons(v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    stack[-1] = v0337;
    stack[-2] = v0337;
    goto v0344;

v0344:
    v0337 = stack[-4];
    v0337 = qcdr(v0337);
    stack[-4] = v0337;
    v0337 = stack[-4];
    if (v0337 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0337 = stack[-4];
    v0337 = qcar(v0337);
    v0338 = v0337;
    v0337 = stack[-3];
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = ncons(v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = Lrplacd(nil, stack[0], v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = stack[-1];
    v0337 = qcdr(v0337);
    stack[-1] = v0337;
    goto v0344;

v0038:
    v0337 = qvalue(elt(env, 13)); // nil
    { popv(6); return onevalue(v0337); }

v0055:
    v0337 = stack[-2];
    v0338 = qcar(v0337);
    v0337 = qvalue(elt(env, 20)); // !*lisplogexpops!*
    v0337 = Lmemq(nil, v0338, v0337);
    v0337 = (v0337 == nil ? lisp_true : nil);
    goto v0058;

v0140:
    stack[-4] = elt(env, 17); // plus
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    stack[0] = elt(env, 18); // minus
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = stack[-3];
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = list2(stack[0], v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    {
        LispObject v0345 = stack[-4];
        LispObject v0346 = stack[-1];
        popv(6);
        return list3(v0345, v0346, v0337);
    }

v0341:
    v0337 = qvalue(elt(env, 15)); // !*period
    if (v0337 == nil) goto v0191;
    stack[-1] = elt(env, 12); // quotient
    stack[0] = elt(env, 3); // 1.0
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = stack[-3];
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    {
        LispObject v0347 = stack[-1];
        LispObject v0348 = stack[0];
        popv(6);
        return list3(v0347, v0348, v0337);
    }

v0191:
    stack[-1] = elt(env, 12); // quotient
    stack[0] = (LispObject)17; // 1
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = stack[-3];
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    {
        LispObject v0349 = stack[-1];
        LispObject v0350 = stack[0];
        popv(6);
        return list3(v0349, v0350, v0337);
    }

v0202:
    stack[-1] = elt(env, 12); // quotient
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = qvalue(elt(env, 4)); // t
    stack[0] = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = qvalue(elt(env, 4)); // t
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    {
        LispObject v0351 = stack[-1];
        LispObject v0352 = stack[0];
        popv(6);
        return list3(v0351, v0352, v0337);
    }

v0233:
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = elt(env, 1); // e
    if (v0338 == v0337) goto v0353;
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = elt(env, 8); // (quotient 1 2)
    if (equal(v0338, v0337)) goto v0276;
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = elt(env, 10); // !:rd!:
    if (!consp(v0338)) goto v0354;
    v0338 = qcar(v0338);
    if (!(v0338 == v0337)) goto v0354;
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0337 = qcdr(v0337);
    v0337 = qcar(v0337);
    fn = elt(env, 22); // realrat
    v0337 = (*qfn1(fn))(qenv(fn), v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    stack[-1] = v0337;
    v0338 = stack[-1];
    v0337 = elt(env, 11); // (1 . 2)
    if (equal(v0338, v0337)) goto v0355;
    stack[0] = elt(env, 7); // expt
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = stack[-3];
    stack[-2] = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0339 = elt(env, 12); // quotient
    v0337 = stack[-1];
    v0338 = qcar(v0337);
    v0337 = stack[-1];
    v0337 = qcdr(v0337);
    v0338 = list3(v0339, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = qvalue(elt(env, 13)); // nil
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    {
        LispObject v0356 = stack[0];
        LispObject v0357 = stack[-2];
        popv(6);
        return list3(v0356, v0357, v0337);
    }

v0355:
    stack[0] = elt(env, 9); // sqrt
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = stack[-3];
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    {
        LispObject v0358 = stack[0];
        popv(6);
        return list2(v0358, v0337);
    }

v0354:
    stack[0] = elt(env, 7); // expt
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0337 = qcdr(v0337);
    v0338 = qcar(v0337);
    v0337 = qvalue(elt(env, 13)); // nil
    v0337 = CC_lispcodeexp(env, v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    {
        LispObject v0359 = stack[0];
        LispObject v0360 = stack[-1];
        popv(6);
        return list3(v0359, v0360, v0337);
    }

v0276:
    v0338 = elt(env, 9); // sqrt
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0337 = qcar(v0337);
    v0338 = list2(v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = stack[-3];
    stack[-2] = v0338;
    stack[-3] = v0337;
    goto v0280;

v0353:
    v0338 = elt(env, 2); // exp
    v0337 = stack[-2];
    v0337 = qcdr(v0337);
    v0337 = qcdr(v0337);
    v0337 = qcar(v0337);
    v0338 = list2(v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = stack[-3];
    stack[-2] = v0338;
    stack[-3] = v0337;
    goto v0280;

v0002:
    v0337 = qvalue(elt(env, 4)); // t
    goto v0001;

v0156:
    v0338 = elt(env, 2); // exp
    v0337 = elt(env, 3); // 1.0
    v0338 = list2(v0338, v0337);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0337 = stack[-3];
    stack[-2] = v0338;
    stack[-3] = v0337;
    goto v0280;

v0041:
    v0337 = stack[-3];
    if (v0337 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0337 = stack[-2];
        popv(6);
        return Lfloat(nil, v0337);
// error exit handlers
v0340:
    popv(6);
    return nil;
}



// Code for defined_vertex

static LispObject CC_defined_vertex(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0012, v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for defined_vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0015;
    stack[-1] = v0000;
// end of prologue

v0042:
    v0012 = stack[-1];
    if (v0012 == nil) goto v0047;
    v0012 = stack[-1];
    v0128 = qcar(v0012);
    v0012 = stack[0];
    fn = elt(env, 3); // memq_edgelist
    v0012 = (*qfn2(fn))(qenv(fn), v0128, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-2];
    if (v0012 == nil) goto v0129;
    v0012 = stack[-1];
    v0012 = qcdr(v0012);
    stack[-1] = v0012;
    goto v0042;

v0129:
    v0012 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0012); }

v0047:
    v0012 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0012); }
// error exit handlers
v0156:
    popv(3);
    return nil;
}



// Code for reddom_zeros

static LispObject CC_reddom_zeros(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0129, v0130, v0036;
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
// copy arguments values to proper place
    v0130 = v0000;
// end of prologue

v0009:
    v0129 = v0130;
    if (v0129 == nil) goto v0041;
    v0129 = v0130;
    v0036 = qcar(v0129);
    v0129 = (LispObject)1; // 0
    if (v0036 == v0129) goto v0021;
    v0129 = v0130;
    v0129 = qcdr(v0129);
    v0130 = v0129;
    goto v0009;

v0021:
    v0129 = v0130;
    v0129 = qcdr(v0129);
    v0129 = CC_reddom_zeros(env, v0129);
    errexit();
    return add1(v0129);

v0041:
    v0129 = (LispObject)1; // 0
    return onevalue(v0129);
}



// Code for get!-all!-kernels

static LispObject CC_getKallKkernels(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0257;
    LispObject fn;
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
    goto v0040;

v0040:
    v0014 = stack[-2];
    if (!consp(v0014)) goto v0041;
    v0014 = stack[-2];
    v0014 = qcar(v0014);
    fn = elt(env, 2); // simp
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-1] = v0014;
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    fn = elt(env, 3); // kernels
    stack[0] = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0014 = stack[-1];
    v0014 = qcdr(v0014);
    fn = elt(env, 3); // kernels
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    fn = elt(env, 4); // union
    v0257 = (*qfn2(fn))(qenv(fn), stack[0], v0014);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0014 = stack[-3];
    v0014 = cons(v0257, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-3] = v0014;
    v0014 = stack[-2];
    v0014 = qcdr(v0014);
    stack[-2] = v0014;
    goto v0040;

v0041:
    v0014 = qvalue(elt(env, 1)); // nil
    v0257 = v0014;
    goto v0047;

v0047:
    v0014 = stack[-3];
    if (v0014 == nil) { popv(5); return onevalue(v0257); }
    v0014 = stack[-3];
    v0014 = qcar(v0014);
    fn = elt(env, 4); // union
    v0014 = (*qfn2(fn))(qenv(fn), v0014, v0257);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0257 = v0014;
    v0014 = stack[-3];
    v0014 = qcdr(v0014);
    stack[-3] = v0014;
    goto v0047;
// error exit handlers
v0017:
    popv(5);
    return nil;
}



// Code for dp!=retimes

static LispObject CC_dpMretimes(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0361, v0262, v0258;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=retimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0262 = v0000;
// end of prologue

v0175:
    v0361 = v0262;
    v0258 = qcar(v0361);
    v0361 = (LispObject)17; // 1
    if (v0258 == v0361) goto v0041;
    v0361 = v0262;
    v0361 = qcdr(v0361);
    if (v0361 == nil) goto v0027;
    v0361 = elt(env, 1); // times
    return cons(v0361, v0262);

v0027:
    v0361 = v0262;
    v0361 = qcar(v0361);
    return onevalue(v0361);

v0041:
    v0361 = v0262;
    v0361 = qcdr(v0361);
    if (v0361 == nil) goto v0168;
    v0361 = v0262;
    v0361 = qcdr(v0361);
    v0262 = v0361;
    goto v0175;

v0168:
    v0361 = (LispObject)17; // 1
    return onevalue(v0361);
}



// Code for pa_part2list

static LispObject CC_pa_part2list(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0267;
    LispObject fn;
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
    v0267 = stack[-6];
    v0267 = qcdr(v0267);
    fn = elt(env, 2); // upbve
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    stack[0] = v0267;
    v0267 = stack[0];
    v0267 = sub1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0267 = Lmkvect(nil, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    stack[-7] = v0267;
    v0267 = stack[0];
    stack[-4] = v0267;
    goto v0263;

v0263:
    v0267 = stack[-4];
    v0267 = sub1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0267 = Lminusp(nil, v0267);
    env = stack[-8];
    if (v0267 == nil) goto v0027;
    v0267 = stack[-6];
    v0267 = qcar(v0267);
    stack[-4] = v0267;
    goto v0123;

v0123:
    v0267 = stack[-4];
    if (v0267 == nil) goto v0171;
    v0267 = stack[-4];
    v0267 = qcar(v0267);
    stack[0] = stack[-7];
    v0267 = sub1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0267 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0267/(16/CELL)));
    fn = elt(env, 3); // copy
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    stack[-3] = v0267;
    v0267 = stack[-3];
    fn = elt(env, 4); // lastpair
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    stack[-2] = v0267;
    v0267 = stack[-4];
    v0267 = qcdr(v0267);
    stack[-4] = v0267;
    v0267 = stack[-2];
    if (!consp(v0267)) goto v0123;
    else goto v0124;

v0124:
    v0267 = stack[-4];
    if (v0267 == nil) { LispObject res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v0267 = stack[-4];
    v0267 = qcar(v0267);
    stack[0] = stack[-7];
    v0267 = sub1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0267 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0267/(16/CELL)));
    fn = elt(env, 3); // copy
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0267 = Lrplacd(nil, stack[-1], v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0267 = stack[-2];
    fn = elt(env, 4); // lastpair
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    stack[-2] = v0267;
    v0267 = stack[-4];
    v0267 = qcdr(v0267);
    stack[-4] = v0267;
    goto v0124;

v0171:
    v0267 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0267); }

v0027:
    v0267 = stack[-6];
    stack[0] = qcdr(v0267);
    v0267 = stack[-4];
    v0267 = sub1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0267 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0267/(16/CELL)));
    stack[-5] = v0267;
    stack[-3] = stack[-7];
    v0267 = stack[-5];
    stack[-2] = sub1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v0267 = stack[-5];
    v0267 = sub1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0267 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0267/(16/CELL)));
    v0267 = cons(stack[-1], v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v0267;
    v0267 = stack[-4];
    v0267 = sub1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    stack[-4] = v0267;
    goto v0263;
// error exit handlers
v0229:
    popv(9);
    return nil;
}



// Code for gd_simpl

static LispObject CC_gd_simpl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0151, v0010, v0134, v0162;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gd_simpl");
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
    v0162 = v0000;
// end of prologue
    v0134 = qvalue(elt(env, 1)); // nil
    v0010 = qvalue(elt(env, 2)); // t
    v0151 = qvalue(elt(env, 1)); // nil
    stack[-2] = qvalue(elt(env, 3)); // !*guardian
    qvalue(elt(env, 3)) = v0134; // !*guardian
    stack[-1] = qvalue(elt(env, 4)); // !*rlnzden
    qvalue(elt(env, 4)) = v0010; // !*rlnzden
    stack[0] = qvalue(elt(env, 5)); // !*rladdcond
    qvalue(elt(env, 5)) = v0151; // !*rladdcond
    v0151 = v0162;
    fn = elt(env, 6); // rl_simp
    v0134 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    v0010 = qvalue(elt(env, 1)); // nil
    v0151 = (LispObject)-15; // -1
    fn = elt(env, 7); // rl_simpl
    v0151 = (*qfnn(fn))(qenv(fn), 3, v0134, v0010, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    fn = elt(env, 8); // rl_prepfof
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; // !*rladdcond
    qvalue(elt(env, 4)) = stack[-1]; // !*rlnzden
    qvalue(elt(env, 3)) = stack[-2]; // !*guardian
    { popv(4); return onevalue(v0151); }
// error exit handlers
v0027:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; // !*rladdcond
    qvalue(elt(env, 4)) = stack[-1]; // !*rlnzden
    qvalue(elt(env, 3)) = stack[-2]; // !*guardian
    popv(4);
    return nil;
}



// Code for ofsf_sippatl

static LispObject CC_ofsf_sippatl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0354, v0205, v0206, v0378, v0379, v0208, v0380;
    LispObject fn;
    LispObject v0059, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_sippatl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0059 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_sippatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0059,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0015,v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0059;
    stack[-12] = v0015;
    stack[-13] = v0000;
// end of prologue
    stack[-1] = nil;
    v0206 = elt(env, 1); // true
    v0205 = stack[-13];
    v0354 = elt(env, 2); // and
    v0354 = (v0205 == v0354 ? lisp_true : nil);
    fn = elt(env, 10); // cl_cflip
    v0354 = (*qfn2(fn))(qenv(fn), v0206, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    stack[-14] = v0354;
    v0206 = elt(env, 3); // false
    v0205 = stack[-13];
    v0354 = elt(env, 2); // and
    v0354 = (v0205 == v0354 ? lisp_true : nil);
    fn = elt(env, 10); // cl_cflip
    v0354 = (*qfn2(fn))(qenv(fn), v0206, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    stack[-11] = v0354;
    v0206 = elt(env, 4); // equal
    v0205 = stack[-13];
    v0354 = elt(env, 2); // and
    v0354 = (v0205 == v0354 ? lisp_true : nil);
    fn = elt(env, 11); // ofsf_clnegrel
    v0354 = (*qfn2(fn))(qenv(fn), v0206, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    stack[-10] = v0354;
    v0354 = stack[0];
    fn = elt(env, 12); // ofsf_exploitknowl
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    v0205 = v0354;
    v0354 = v0205;
    v0354 = qcar(v0354);
    stack[-9] = v0354;
    v0354 = v0205;
    v0354 = qcdr(v0354);
    v0205 = v0354;
    v0354 = v0205;
    v0354 = qcar(v0354);
    stack[-8] = v0354;
    v0354 = v0205;
    v0354 = qcdr(v0354);
    v0205 = v0354;
    v0354 = v0205;
    v0354 = qcar(v0354);
    stack[-7] = v0354;
    v0354 = v0205;
    v0354 = qcdr(v0354);
    v0205 = v0354;
    v0354 = v0205;
    v0354 = qcar(v0354);
    stack[-6] = v0354;
    v0354 = v0205;
    v0354 = qcdr(v0354);
    v0205 = v0354;
    v0354 = v0205;
    v0354 = qcar(v0354);
    stack[-5] = v0354;
    v0354 = v0205;
    v0354 = qcdr(v0354);
    v0205 = v0354;
    v0354 = v0205;
    v0354 = qcar(v0354);
    stack[-4] = v0354;
    v0354 = v0205;
    v0354 = qcdr(v0354);
    v0205 = v0354;
    v0354 = v0205;
    v0354 = qcar(v0354);
    stack[-3] = v0354;
    goto v0115;

v0115:
    v0354 = stack[-12];
    if (v0354 == nil) { LispObject res = stack[-1]; popv(16); return onevalue(res); }
    v0354 = stack[-12];
    v0354 = qcar(v0354);
    v0205 = v0354;
    v0354 = stack[-12];
    v0354 = qcdr(v0354);
    stack[-12] = v0354;
    v0354 = v0205;
    stack[-2] = v0354;
    v0354 = qvalue(elt(env, 6)); // !*rlsippsubst
    if (v0354 == nil) goto v0109;
    v0205 = stack[-10];
    v0354 = stack[-2];
    fn = elt(env, 13); // ofsf_vareqnp
    v0354 = (*qfn2(fn))(qenv(fn), v0205, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    if (!(v0354 == nil)) goto v0109;
    v0205 = stack[-2];
    v0354 = stack[-9];
    fn = elt(env, 14); // ofsf_sippsubst
    v0354 = (*qfn2(fn))(qenv(fn), v0205, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    stack[-2] = v0354;
    v0354 = qvalue(elt(env, 5)); // nil
    stack[0] = qvalue(elt(env, 7)); // !*rlsiatadv
    qvalue(elt(env, 7)) = v0354; // !*rlsiatadv
    v0205 = stack[-2];
    v0354 = stack[-13];
    fn = elt(env, 15); // ofsf_simplat1
    v0354 = (*qfn2(fn))(qenv(fn), v0205, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-15];
    stack[-2] = v0354;
    qvalue(elt(env, 7)) = stack[0]; // !*rlsiatadv
    goto v0109;

v0109:
    v0205 = stack[-2];
    v0354 = elt(env, 1); // true
    if (v0205 == v0354) goto v0381;
    v0205 = stack[-2];
    v0354 = elt(env, 3); // false
    v0354 = (v0205 == v0354 ? lisp_true : nil);
    goto v0382;

v0382:
    if (!(v0354 == nil)) goto v0383;
    v0354 = qvalue(elt(env, 9)); // !*rlsippsignchk
    if (v0354 == nil) goto v0383;
    v0354 = stack[-2];
    v0354 = qcdr(v0354);
    v0354 = qcar(v0354);
    fn = elt(env, 16); // sfto_varisnump
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    if (!(v0354 == nil)) goto v0383;
    v0380 = stack[-2];
    v0208 = stack[-8];
    v0379 = stack[-7];
    v0378 = stack[-6];
    v0206 = stack[-5];
    v0205 = stack[-4];
    v0354 = stack[-3];
    fn = elt(env, 17); // ofsf_sippsignchk
    v0354 = (*qfnn(fn))(qenv(fn), 7, v0380, v0208, v0379, v0378, v0206, v0205, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    stack[-2] = v0354;
    goto v0383;

v0383:
    v0205 = stack[-2];
    v0354 = stack[-11];
    if (v0205 == v0354) goto v0384;
    v0205 = stack[-2];
    v0354 = stack[-14];
    if (equal(v0205, v0354)) goto v0115;
    v0205 = stack[-2];
    v0354 = stack[-1];
    fn = elt(env, 18); // lto_insert
    v0354 = (*qfn2(fn))(qenv(fn), v0205, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-15];
    stack[-1] = v0354;
    goto v0115;

v0384:
    v0354 = stack[-11];
    stack[-1] = v0354;
    v0354 = qvalue(elt(env, 5)); // nil
    stack[-12] = v0354;
    goto v0115;

v0381:
    v0354 = qvalue(elt(env, 8)); // t
    goto v0382;
// error exit handlers
v0090:
    env = stack[-15];
    qvalue(elt(env, 7)) = stack[0]; // !*rlsiatadv
    popv(16);
    return nil;
v0089:
    popv(16);
    return nil;
}



// Code for get_dimension_in

static LispObject CC_get_dimension_in(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005, v0011;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_dimension_in");
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
    v0005 = v0000;
// end of prologue
    v0011 = elt(env, 1); // id
    fn = elt(env, 2); // get_rep_matrix_in
    v0005 = (*qfn2(fn))(qenv(fn), v0011, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[0];
    fn = elt(env, 3); // mk!+trace
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); // change!+sq!+to!+int
        return (*qfn1(fn))(qenv(fn), v0005);
    }
// error exit handlers
v0259:
    popv(1);
    return nil;
}



// Code for pasf_leqp

static LispObject CC_pasf_leqp(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0335, v0034, v0385, v0386;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_leqp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0034 = v0015;
    v0385 = v0000;
// end of prologue
    v0335 = v0385;
    if (!(v0335 == nil)) goto v0040;
    v0335 = (LispObject)1; // 0
    v0385 = v0335;
    goto v0040;

v0040:
    v0335 = v0034;
    if (!(v0335 == nil)) goto v0168;
    v0335 = (LispObject)1; // 0
    v0034 = v0335;
    goto v0168;

v0168:
    v0386 = v0385;
    v0335 = elt(env, 1); // minf
    if (v0386 == v0335) goto v0134;
    v0386 = v0034;
    v0335 = elt(env, 3); // pinf
    if (v0386 == v0335) goto v0163;
    v0386 = v0385;
    v0335 = elt(env, 3); // pinf
    if (v0386 == v0335) goto v0125;
    v0386 = v0034;
    v0335 = elt(env, 1); // minf
    if (v0386 == v0335) goto v0172;
    v0335 = v0385;
    v0335 = (LispObject)lesseq2(v0335, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    v0335 = v0335 ? lisp_true : nil;
    env = stack[0];
    goto v0010;

v0010:
    if (v0335 == nil) goto v0256;
    v0335 = qvalue(elt(env, 2)); // t
    { popv(1); return onevalue(v0335); }

v0256:
    v0335 = nil;
    { popv(1); return onevalue(v0335); }

v0172:
    v0335 = qvalue(elt(env, 4)); // nil
    goto v0010;

v0125:
    v0335 = qvalue(elt(env, 4)); // nil
    goto v0010;

v0163:
    v0335 = qvalue(elt(env, 2)); // t
    goto v0010;

v0134:
    v0335 = qvalue(elt(env, 2)); // t
    goto v0010;
// error exit handlers
v0273:
    popv(1);
    return nil;
}



// Code for vdp_sugar

static LispObject CC_vdp_sugar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0169, v0026;
    LispObject fn;
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
    v0169 = stack[0];
    fn = elt(env, 3); // vdp_zero!?
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    if (!(v0169 == nil)) goto v0009;
    v0169 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v0169 == nil) goto v0009;
    v0026 = stack[0];
    v0169 = elt(env, 2); // sugar
    fn = elt(env, 4); // vdp_getprop
    v0169 = (*qfn2(fn))(qenv(fn), v0026, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    if (!(v0169 == nil)) { popv(2); return onevalue(v0169); }
    v0169 = (LispObject)1; // 0
    { popv(2); return onevalue(v0169); }

v0009:
    v0169 = (LispObject)1; // 0
    { popv(2); return onevalue(v0169); }
// error exit handlers
v0129:
    popv(2);
    return nil;
}



// Code for acfsf_0mk2

static LispObject CC_acfsf_0mk2(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0005, v0011, v0259;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for acfsf_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0005 = v0015;
    v0011 = v0000;
// end of prologue
    v0259 = qvalue(elt(env, 1)); // nil
    return list3(v0011, v0005, v0259);
}



// Code for prload

static LispObject CC_prload(LispObject env, int nargs, ...)
{
    LispObject v0059;
    argcheck(nargs, 0, "prload");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prload");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0059 = qvalue(elt(env, 1)); // nil
    return onevalue(v0059);
}



// Code for dm!-lt

static LispObject CC_dmKlt(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0161, v0255;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-lt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0161 = v0015;
    v0255 = v0000;
// end of prologue
    fn = elt(env, 1); // dm!-difference
    v0161 = (*qfn2(fn))(qenv(fn), v0255, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !:minusp
        return (*qfn1(fn))(qenv(fn), v0161);
    }
// error exit handlers
v0005:
    popv(1);
    return nil;
}



// Code for vdpsimpcont

static LispObject CC_vdpsimpcont(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007, v0008;
    LispObject fn;
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
    v0006 = stack[-1];
    v0006 = qcdr(v0006);
    v0006 = qcdr(v0006);
    v0006 = qcdr(v0006);
    v0006 = qcar(v0006);
    stack[0] = v0006;
    v0006 = stack[0];
    if (v0006 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0006 = stack[0];
    fn = elt(env, 3); // dipsimpcont
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-3];
    stack[-2] = v0006;
    v0006 = stack[-2];
    v0006 = qcdr(v0006);
    fn = elt(env, 4); // dip2vdp
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-3];
    stack[-1] = v0006;
    v0006 = stack[-2];
    v0006 = qcar(v0006);
    stack[-2] = v0006;
    v0006 = stack[-2];
    fn = elt(env, 5); // evzero!?
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-3];
    if (v0006 == nil) goto v0130;
    v0006 = qvalue(elt(env, 1)); // nil
    goto v0129;

v0129:
    if (v0006 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0008 = stack[-1];
    v0007 = elt(env, 2); // monfac
    v0006 = stack[-2];
    fn = elt(env, 6); // vdpputprop
    v0006 = (*qfnn(fn))(qenv(fn), 3, v0008, v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0130:
    v0006 = stack[0];
    v0006 = qcdr(v0006);
    v0006 = qcdr(v0006);
    if (!(v0006 == nil)) goto v0129;
    v0006 = stack[-2];
    fn = elt(env, 7); // evtdeg
    v0007 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-3];
    v0006 = (LispObject)17; // 1
    v0006 = (LispObject)greaterp2(v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    v0006 = v0006 ? lisp_true : nil;
    env = stack[-3];
    goto v0129;
// error exit handlers
v0164:
    popv(4);
    return nil;
}



// Code for newvar

static LispObject CC_newvar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027, v0129;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for newvar");
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
    v0027 = stack[0];
    if (symbolp(v0027)) goto v0260;
    v0129 = stack[0];
    v0027 = elt(env, 1); // "free variable"
    {
        popv(3);
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(qenv(fn), v0129, v0027);
    }

v0260:
    v0027 = elt(env, 2); // !=
    fn = elt(env, 4); // id2bytelist
    stack[-1] = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0027 = stack[0];
    fn = elt(env, 4); // id2bytelist
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0027 = Lappend(nil, stack[-1], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); // bytelist2id
        return (*qfn1(fn))(qenv(fn), v0027);
    }
// error exit handlers
v0012:
    popv(3);
    return nil;
}



// Code for red_prepare

static LispObject CC_red_prepare(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0162;
    LispObject fn;
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
    v0162 = stack[-1];
    fn = elt(env, 1); // bas_nr
    stack[-2] = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    v0162 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    stack[0] = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    v0162 = stack[-1];
    fn = elt(env, 3); // bas_rep
    stack[-1] = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    v0162 = (LispObject)1; // 0
    fn = elt(env, 4); // dp_from_ei
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    fn = elt(env, 5); // dp_sum
    v0162 = (*qfn2(fn))(qenv(fn), stack[-1], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    {
        LispObject v0129 = stack[-2];
        LispObject v0130 = stack[0];
        popv(4);
        fn = elt(env, 6); // bas_make1
        return (*qfnn(fn))(qenv(fn), 3, v0129, v0130, v0162);
    }
// error exit handlers
v0027:
    popv(4);
    return nil;
}



// Code for bagp

static LispObject CC_bagp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0260, v0256;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bagp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0256 = v0000;
// end of prologue
    v0260 = v0256;
    if (!consp(v0260)) goto v0259;
    v0260 = v0256;
    v0260 = qcar(v0260);
    v0256 = elt(env, 1); // bag
        return Lflagp(nil, v0260, v0256);

v0259:
    v0260 = qvalue(elt(env, 2)); // nil
    return onevalue(v0260);
}



// Code for ofsf_smdbgetrel

static LispObject CC_ofsf_smdbgetrel(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0128, v0031, v0158, v0156;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smdbgetrel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0158 = v0015;
    v0156 = v0000;
// end of prologue

v0159:
    v0031 = v0156;
    v0128 = v0158;
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    v0128 = qcdr(v0128);
    if (equal(v0031, v0128)) goto v0047;
    v0128 = v0158;
    v0128 = qcdr(v0128);
    if (v0128 == nil) goto v0130;
    v0128 = v0158;
    v0128 = qcdr(v0128);
    v0158 = v0128;
    goto v0159;

v0130:
    v0128 = qvalue(elt(env, 1)); // nil
    return onevalue(v0128);

v0047:
    v0128 = v0158;
    v0128 = qcar(v0128);
    v0128 = qcdr(v0128);
    v0128 = qcar(v0128);
    return onevalue(v0128);
}



// Code for !*ff2a

static LispObject CC_Hff2a(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0162, v0168;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *ff2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0162 = v0015;
    v0168 = v0000;
// end of prologue
    v0162 = cons(v0168, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[0];
    fn = elt(env, 2); // cancel
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[0];
    v0168 = v0162;
    v0162 = qvalue(elt(env, 1)); // wtl!*
    if (v0162 == nil) goto v0256;
    v0162 = v0168;
    {
        popv(1);
        fn = elt(env, 3); // prepsq
        return (*qfn1(fn))(qenv(fn), v0162);
    }

v0256:
    v0162 = v0168;
    {
        popv(1);
        fn = elt(env, 4); // mk!*sq
        return (*qfn1(fn))(qenv(fn), v0162);
    }
// error exit handlers
v0169:
    popv(1);
    return nil;
}



// Code for mktag

static LispObject CC_mktag(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0385, v0386, v0273;
    LispObject fn;
    LispObject v0059, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mktag");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0059 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mktag");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0059,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0015,v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0059;
    stack[-2] = v0015;
    v0385 = v0000;
// end of prologue
    v0386 = v0385;
    if (v0386 == nil) goto v0040;
    v0386 = v0385;
    if (!consp(v0386)) goto v0159;
    v0386 = v0385;
    v0273 = qcar(v0386);
    v0386 = elt(env, 2); // texprec
    v0386 = get(v0273, v0386);
    env = stack[-4];
    if (!(v0386 == nil)) goto v0010;
    v0386 = (LispObject)15985; // 999
    goto v0010;

v0010:
    stack[-3] = v0386;
    v0386 = v0385;
    v0273 = qcar(v0386);
    v0386 = qcdr(v0385);
    v0385 = stack[-3];
    fn = elt(env, 5); // makefunc
    v0385 = (*qfnn(fn))(qenv(fn), 3, v0273, v0386, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[0] = v0385;
    v0385 = stack[-1];
    if (v0385 == nil) goto v0006;
    v0386 = stack[-2];
    v0385 = stack[-3];
    if (!(equal(v0386, v0385))) goto v0006;

v0171:
    v0386 = elt(env, 3); // !\!(
    v0385 = stack[0];
    stack[0] = cons(v0386, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0385 = elt(env, 4); // !\!)
    v0385 = ncons(v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0385 = Lnconc(nil, stack[0], v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    stack[0] = v0385;
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0006:
    v0386 = stack[-3];
    v0385 = stack[-2];
    v0385 = (LispObject)lessp2(v0386, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    v0385 = v0385 ? lisp_true : nil;
    env = stack[-4];
    if (v0385 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    else goto v0171;

v0159:
    {
        popv(5);
        fn = elt(env, 6); // texexplode
        return (*qfn1(fn))(qenv(fn), v0385);
    }

v0040:
    v0385 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0385); }
// error exit handlers
v0388:
    popv(5);
    return nil;
}



// Code for pasf_subfof

static LispObject CC_pasf_subfof(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0010, v0134, v0162;
    LispObject fn;
    LispObject v0059, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_subfof");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0059 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_subfof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0059,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0015,v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0010 = v0059;
    v0134 = v0015;
    v0162 = v0000;
// end of prologue
    stack[-1] = v0010;
    stack[0] = elt(env, 1); // pasf_subfof1
    v0010 = v0162;
    v0010 = list2(v0010, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    {
        LispObject v0027 = stack[-1];
        LispObject v0129 = stack[0];
        popv(3);
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(qenv(fn), 3, v0027, v0129, v0010);
    }
// error exit handlers
v0026:
    popv(3);
    return nil;
}



// Code for ofsf_boundchk

static LispObject CC_ofsf_boundchk(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0112, v0392, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_boundchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0015;
    stack[-2] = v0000;
// end of prologue
    v0112 = stack[-1];
    v0112 = ncons(v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    fn = elt(env, 9); // setkorder
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    stack[0] = v0112;
    v0112 = stack[-2];
    v0112 = qcdr(v0112);
    v0112 = qcar(v0112);
    fn = elt(env, 10); // reorder
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    stack[-3] = v0112;
    v0112 = stack[0];
    fn = elt(env, 9); // setkorder
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    v0112 = stack[-3];
    if (!consp(v0112)) goto v0027;
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    v0112 = (consp(v0112) ? nil : lisp_true);
    goto v0026;

v0026:
    if (v0112 == nil) goto v0013;
    v0112 = qvalue(elt(env, 1)); // t
    goto v0134;

v0134:
    if (v0112 == nil) goto v0275;
    v0112 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0112); }

v0275:
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    v0392 = qcdr(v0112);
    v0112 = (LispObject)17; // 1
    if (v0392 == v0112) goto v0387;
    v0110 = elt(env, 3); // "ofsf_boundchk:"
    v0392 = stack[-1];
    v0112 = elt(env, 4); // "not linear"
    v0112 = list3(v0110, v0392, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    fn = elt(env, 11); // rederr
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    goto v0387;

v0387:
    v0112 = stack[-3];
    v0112 = qcdr(v0112);
    fn = elt(env, 10); // reorder
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    fn = elt(env, 12); // negf
    v0392 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    v0112 = (LispObject)17; // 1
    stack[0] = cons(v0392, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    fn = elt(env, 10); // reorder
    v0392 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    v0112 = (LispObject)17; // 1
    v0112 = cons(v0392, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    fn = elt(env, 13); // quotsq
    v0112 = (*qfn2(fn))(qenv(fn), stack[0], v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    stack[0] = v0112;
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    v0110 = v0112;
    v0392 = v0110;
    v0112 = elt(env, 5); // equal
    if (v0392 == v0112) goto v0270;
    v0392 = v0110;
    v0112 = elt(env, 6); // geq
    stack[-1] = (v0392 == v0112 ? lisp_true : nil);
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    v0112 = qcdr(v0112);
    fn = elt(env, 14); // minusf
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    fn = elt(env, 15); // ofsf_xor
    v0112 = (*qfn2(fn))(qenv(fn), stack[-1], v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    if (v0112 == nil) goto v0109;
    v0392 = elt(env, 7); // lb
    v0112 = stack[0];
    popv(5);
    return cons(v0392, v0112);

v0109:
    v0392 = elt(env, 8); // ub
    v0112 = stack[0];
    popv(5);
    return cons(v0392, v0112);

v0270:
    v0392 = elt(env, 5); // equal
    v0112 = stack[0];
    popv(5);
    return cons(v0392, v0112);

v0013:
    v0112 = stack[-3];
    v0112 = qcar(v0112);
    v0112 = qcar(v0112);
    v0392 = qcar(v0112);
    v0112 = stack[-1];
    v0112 = Lneq(nil, v0392, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    goto v0134;

v0027:
    v0112 = qvalue(elt(env, 1)); // t
    goto v0026;
// error exit handlers
v0393:
    popv(5);
    return nil;
}



// Code for intconv

static LispObject CC_intconv(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0031, v0158, v0156;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intconv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0156 = v0000;
// end of prologue
    v0031 = qvalue(elt(env, 1)); // dmode!*
    if (v0031 == nil) goto v0047;
    v0158 = qvalue(elt(env, 1)); // dmode!*
    v0031 = elt(env, 3); // (!:rd!: !:cr!:)
    v0031 = Lmemq(nil, v0158, v0031);
    goto v0041;

v0041:
    if (!(v0031 == nil)) return onevalue(v0156);
    v0031 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0031)) v0031 = nil;
    else { v0031 = qfastgets(v0031);
           if (v0031 != nil) { v0031 = elt(v0031, 34); // i2d
#ifdef RECORD_GET
             if (v0031 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0031 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0031 == SPID_NOPROP) v0031 = nil; }}
#endif
    v0158 = v0156;
        return Lapply1(nil, v0031, v0158);

v0047:
    v0031 = qvalue(elt(env, 2)); // t
    goto v0041;
}



// Code for qsimpcomb_standard_integer_part_sf

static LispObject CC_qsimpcomb_standard_integer_part_sf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0126, v0364, v0387;
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
    v0126 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0126;
    goto v0159;

v0159:
    v0126 = stack[-2];
    v0126 = Lconsp(nil, v0126);
    env = stack[-4];
    if (v0126 == nil) goto v0175;
    v0126 = stack[-2];
    v0126 = qcar(v0126);
    v0126 = qcdr(v0126);
    v0126 = CC_qsimpcomb_standard_integer_part_sf(env, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    stack[-1] = v0126;
    v0126 = stack[-2];
    v0126 = qcar(v0126);
    v0126 = qcar(v0126);
    v0364 = qcar(v0126);
    v0126 = stack[-2];
    v0126 = qcar(v0126);
    v0126 = qcar(v0126);
    v0126 = qcdr(v0126);
    v0126 = cons(v0364, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    stack[0] = v0126;
    goto v0002;

v0002:
    v0364 = stack[0];
    v0126 = stack[-1];
    v0126 = qcar(v0126);
    v0387 = cons(v0364, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    v0364 = qvalue(elt(env, 1)); // nil
    v0126 = stack[-3];
    v0126 = acons(v0387, v0364, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-4];
    stack[-3] = v0126;
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    stack[-1] = v0126;
    v0126 = stack[-1];
    if (!(v0126 == nil)) goto v0002;
    v0126 = stack[-2];
    v0126 = qcdr(v0126);
    stack[-2] = v0126;
    goto v0159;

v0175:
    v0126 = stack[-2];
    if (v0126 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0364 = stack[-2];
    v0126 = stack[-3];
    v0126 = cons(v0364, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    stack[-3] = v0126;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }
// error exit handlers
v0273:
    popv(5);
    return nil;
}



// Code for force!-to!-dm

static LispObject CC_forceKtoKdm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0029, v0353, v0152;
    LispObject fn;
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
    v0353 = v0000;
// end of prologue

v0009:
    v0029 = v0353;
    if (!consp(v0029)) goto v0021;
    v0029 = v0353;
    v0029 = qcar(v0029);
    v0029 = (consp(v0029) ? nil : lisp_true);
    goto v0159;

v0159:
    if (v0029 == nil) goto v0151;
    v0029 = v0353;
    if (v0029 == nil) goto v0129;
    v0029 = v0353;
    if (is_number(v0029)) goto v0163;
    v0029 = v0353;
    v0029 = Lconsp(nil, v0029);
    env = stack[-1];
    if (v0029 == nil) goto v0035;
    v0029 = v0353;
    v0152 = qcar(v0029);
    v0029 = qvalue(elt(env, 3)); // dmode!*
    if (equal(v0152, v0029)) { popv(2); return onevalue(v0353); }
    else goto v0035;

v0035:
    v0029 = v0353;
    v0029 = Lconsp(nil, v0029);
    env = stack[-1];
    if (v0029 == nil) goto v0007;
    v0029 = v0353;
    v0152 = qcar(v0029);
    v0029 = qvalue(elt(env, 3)); // dmode!*
    v0029 = get(v0152, v0029);
    env = stack[-1];
    goto v0006;

v0006:
    v0152 = v0029;
    v0029 = v0152;
    if (v0029 == nil) goto v0116;
    stack[0] = v0152;
    v0029 = v0353;
    v0029 = ncons(v0029);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-1];
    {
        LispObject v0396 = stack[0];
        popv(2);
        fn = elt(env, 6); // apply
        return (*qfn2(fn))(qenv(fn), v0396, v0029);
    }

v0116:
    v0029 = elt(env, 5); // "conversion error with "
    v0029 = list2(v0029, v0353);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 7); // rederr
        return (*qfn1(fn))(qenv(fn), v0029);
    }

v0007:
    v0029 = qvalue(elt(env, 4)); // nil
    goto v0006;

v0163:
    v0029 = qvalue(elt(env, 3)); // dmode!*
    if (!symbolp(v0029)) stack[0] = nil;
    else { stack[0] = qfastgets(v0029);
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
    v0029 = v0353;
    v0029 = ncons(v0029);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-1];
    {
        LispObject v0030 = stack[0];
        popv(2);
        fn = elt(env, 6); // apply
        return (*qfn2(fn))(qenv(fn), v0030, v0029);
    }

v0129:
    v0029 = (LispObject)1; // 0
    v0353 = v0029;
    goto v0009;

v0151:
    v0029 = v0353;
    fn = elt(env, 8); // prepf
    v0353 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-1];
    v0029 = elt(env, 2); // "number"
    {
        popv(2);
        fn = elt(env, 9); // typerr
        return (*qfn2(fn))(qenv(fn), v0353, v0029);
    }

v0021:
    v0029 = qvalue(elt(env, 1)); // t
    goto v0159;
// error exit handlers
v0395:
    popv(2);
    return nil;
}



// Code for mk_world1

static LispObject CC_mk_world1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0259, v0239, v0263;
    LispObject fn;
    LispObject v0059, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mk_world1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0059 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_world1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0059,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0015,v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0059;
    stack[-1] = v0015;
    v0259 = v0000;
// end of prologue
    fn = elt(env, 1); // map_2_from_map_1
    v0263 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    v0239 = stack[-1];
    v0259 = stack[0];
    popv(2);
    return list3(v0263, v0239, v0259);
// error exit handlers
v0151:
    popv(2);
    return nil;
}



// Code for cali_bc_power

static LispObject CC_cali_bc_power(LispObject env,
                         LispObject v0000, LispObject v0015)
{
    LispObject nil = C_nil;
    LispObject v0161, v0255;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_bc_power");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0161 = v0015;
    v0255 = v0000;
// end of prologue
    fn = elt(env, 1); // exptf
    v0161 = (*qfn2(fn))(qenv(fn), v0255, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // bc!=simp
        return (*qfn1(fn))(qenv(fn), v0161);
    }
// error exit handlers
v0005:
    popv(1);
    return nil;
}



// Code for isimp2

static LispObject CC_isimp2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0105, v0103, v0332, v0331, v0145;
    LispObject fn;
    LispObject v0009, v0020, v0059, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "isimp2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0059 = va_arg(aa, LispObject);
    v0020 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isimp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0009,v0020,v0059,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0015,v0059,v0020,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[0] = v0009;
    stack[-1] = v0020;
    stack[-2] = v0059;
    stack[-3] = v0015;
    stack[-4] = v0000;
// end of prologue
    v0105 = stack[-4];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    stack[-5] = v0105;
    if (!consp(v0105)) goto v0028;
    v0105 = stack[-5];
    v0103 = qcar(v0105);
    v0105 = elt(env, 1); // cons
    if (v0103 == v0105) goto v0128;
    v0105 = qvalue(elt(env, 2)); // nil
    goto v0151;

v0151:
    if (v0105 == nil) goto v0017;
    v0145 = stack[-4];
    v0331 = stack[-3];
    v0332 = stack[-2];
    v0103 = stack[-1];
    v0105 = stack[0];
    {
        popv(7);
        fn = elt(env, 5); // dotsum
        return (*qfnn(fn))(qenv(fn), 5, v0145, v0331, v0332, v0103, v0105);
    }

v0017:
    v0105 = stack[-5];
    v0103 = qcar(v0105);
    v0105 = elt(env, 3); // g
    if (v0103 == v0105) goto v0376;
    v0105 = stack[-5];
    v0103 = qcar(v0105);
    v0105 = elt(env, 4); // eps
    if (!(v0103 == v0105)) goto v0028;
    v0145 = stack[-4];
    v0331 = stack[-3];
    v0332 = stack[-2];
    v0103 = stack[-1];
    v0105 = stack[0];
    {
        popv(7);
        fn = elt(env, 6); // esum
        return (*qfnn(fn))(qenv(fn), 5, v0145, v0331, v0332, v0103, v0105);
    }

v0028:
    v0105 = stack[-4];
    v0103 = qcar(v0105);
    v0105 = (LispObject)17; // 1
    v0105 = cons(v0103, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-6];
    stack[-5] = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-6];
    v0105 = stack[-4];
    v0145 = qcdr(v0105);
    v0331 = stack[-3];
    v0332 = stack[-2];
    v0103 = stack[-1];
    v0105 = stack[0];
    fn = elt(env, 7); // isimp1
    v0105 = (*qfnn(fn))(qenv(fn), 5, v0145, v0331, v0332, v0103, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-6];
    {
        LispObject v0246 = stack[-5];
        popv(7);
        fn = elt(env, 8); // multf
        return (*qfn2(fn))(qenv(fn), v0246, v0105);
    }

v0376:
    v0105 = stack[-5];
    v0105 = qcdr(v0105);
    v0103 = qcdr(v0105);
    v0105 = stack[-4];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    fn = elt(env, 9); // appn
    v0332 = (*qfn2(fn))(qenv(fn), v0103, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-6];
    v0103 = stack[0];
    v0105 = stack[-5];
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    fn = elt(env, 10); // gadd
    v0105 = (*qfnn(fn))(qenv(fn), 3, v0332, v0103, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-6];
    stack[-5] = v0105;
    v0105 = stack[-5];
    v0105 = qcar(v0105);
    fn = elt(env, 11); // nb
    v0103 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-6];
    v0105 = stack[-4];
    v0105 = qcdr(v0105);
    fn = elt(env, 12); // multd!*
    v0145 = (*qfn2(fn))(qenv(fn), v0103, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-6];
    v0331 = stack[-3];
    v0332 = stack[-2];
    v0103 = stack[-1];
    v0105 = stack[-5];
    v0105 = qcdr(v0105);
    {
        popv(7);
        fn = elt(env, 7); // isimp1
        return (*qfnn(fn))(qenv(fn), 5, v0145, v0331, v0332, v0103, v0105);
    }

v0128:
    v0105 = stack[-5];
    v0103 = qcdr(v0105);
    v0105 = stack[-3];
    fn = elt(env, 13); // xnp
    v0105 = (*qfn2(fn))(qenv(fn), v0103, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-6];
    goto v0151;
// error exit handlers
v0204:
    popv(7);
    return nil;
}



// Code for ofsf_sminsert1

static LispObject CC_ofsf_sminsert1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0219, v0220, v0404;
    LispObject fn;
    LispObject v0009, v0020, v0059, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "ofsf_sminsert1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0059 = va_arg(aa, LispObject);
    v0020 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_sminsert1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0009,v0020,v0059,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0015,v0059,v0020,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[0] = v0009;
    stack[-1] = v0020;
    stack[-2] = v0059;
    stack[-3] = v0015;
    stack[-4] = v0000;
// end of prologue
    stack[-5] = stack[-3];
    v0219 = stack[-1];
    fn = elt(env, 4); // negsq
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0405;
    env = stack[-6];
    fn = elt(env, 5); // addsq
    v0219 = (*qfn2(fn))(qenv(fn), stack[-5], v0219);
    nil = C_nil;
    if (exception_pending()) goto v0405;
    env = stack[-6];
    v0219 = qcar(v0219);
    v0220 = v0219;
    v0219 = v0220;
    if (v0219 == nil) goto v0169;
    v0219 = v0220;
    fn = elt(env, 6); // minusf
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0405;
    env = stack[-6];
    if (v0219 == nil) goto v0118;
    v0220 = stack[-4];
    v0219 = stack[-2];
    fn = elt(env, 7); // ofsf_smordtable
    v0219 = (*qfn2(fn))(qenv(fn), v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0405;
    env = stack[-6];
    v0404 = v0219;
    v0219 = v0404;
    if (!consp(v0219)) { popv(7); return onevalue(v0404); }
    v0220 = v0404;
    v0219 = stack[-4];
    if (!consp(v0220)) goto v0028;
    v0220 = qcar(v0220);
    if (!(v0220 == v0219)) goto v0028;
    v0219 = v0404;
    v0219 = qcdr(v0219);
    goto v0272;

v0272:
    if (v0219 == nil) goto v0395;
    v0219 = elt(env, 2); // true
    { popv(7); return onevalue(v0219); }

v0395:
    v0220 = stack[0];
    v0219 = v0404;
    v0219 = qcar(v0219);
    v0404 = qcdr(v0404);
    if (v0404 == nil) goto v0402;
    v0404 = stack[-3];
    goto v0121;

v0121:
    popv(7);
    return list2star(v0220, v0219, v0404);

v0402:
    v0404 = stack[-1];
    goto v0121;

v0028:
    v0219 = qvalue(elt(env, 3)); // nil
    goto v0272;

v0118:
    v0220 = stack[-2];
    v0219 = stack[-4];
    fn = elt(env, 7); // ofsf_smordtable
    v0219 = (*qfn2(fn))(qenv(fn), v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0405;
    env = stack[-6];
    v0404 = v0219;
    v0219 = v0404;
    if (!consp(v0219)) { popv(7); return onevalue(v0404); }
    v0220 = v0404;
    v0219 = stack[-4];
    if (!consp(v0220)) goto v0111;
    v0220 = qcar(v0220);
    if (!(v0220 == v0219)) goto v0111;
    v0219 = v0404;
    v0219 = qcdr(v0219);
    v0219 = (v0219 == nil ? lisp_true : nil);
    goto v0406;

v0406:
    if (v0219 == nil) goto v0221;
    v0219 = elt(env, 2); // true
    { popv(7); return onevalue(v0219); }

v0221:
    v0220 = stack[0];
    v0219 = v0404;
    v0219 = qcar(v0219);
    v0404 = qcdr(v0404);
    if (v0404 == nil) goto v0332;
    v0404 = stack[-1];
    goto v0373;

v0373:
    popv(7);
    return list2star(v0220, v0219, v0404);

v0332:
    v0404 = stack[-3];
    goto v0373;

v0111:
    v0219 = qvalue(elt(env, 3)); // nil
    goto v0406;

v0169:
    v0220 = stack[-4];
    v0219 = stack[-2];
    fn = elt(env, 8); // ofsf_smeqtable
    v0219 = (*qfn2(fn))(qenv(fn), v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0405;
    env = stack[-6];
    v0404 = v0219;
    v0220 = v0404;
    v0219 = elt(env, 1); // false
    if (v0220 == v0219) goto v0158;
    v0220 = stack[-4];
    v0219 = v0404;
    if (v0220 == v0219) goto v0001;
    v0220 = stack[0];
    v0219 = stack[-3];
    popv(7);
    return list2star(v0220, v0404, v0219);

v0001:
    v0219 = elt(env, 2); // true
    { popv(7); return onevalue(v0219); }

v0158:
    v0219 = elt(env, 1); // false
    { popv(7); return onevalue(v0219); }
// error exit handlers
v0405:
    popv(7);
    return nil;
}



setup_type const u46_setup[] =
{
    {"fs:zerop:",               CC_fsTzeropT,   too_many_1,    wrong_no_1},
    {"monic",                   too_few_2,      CC_monic,      wrong_no_2},
    {"st_sorttree1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree1},
    {"monic-mod-p",             CC_monicKmodKp, too_many_1,    wrong_no_1},
    {"nextu",                   too_few_2,      CC_nextu,      wrong_no_2},
    {"sqfrf",                   CC_sqfrf,       too_many_1,    wrong_no_1},
    {"dipcontenti",             CC_dipcontenti, too_many_1,    wrong_no_1},
    {"ratmean",                 too_few_2,      CC_ratmean,    wrong_no_2},
    {"mk_parents_prim",         CC_mk_parents_prim,too_many_1, wrong_no_1},
    {"mo=expvec2a1",            too_few_2,      CC_moMexpvec2a1,wrong_no_2},
    {"impartsq",                CC_impartsq,    too_many_1,    wrong_no_1},
    {"mri_irsplit1",            CC_mri_irsplit1,too_many_1,    wrong_no_1},
    {"qqe_length-graph-neighbor-edge",CC_qqe_lengthKgraphKneighborKedge,too_many_1,wrong_no_1},
    {"pasf_dnf",                CC_pasf_dnf,    too_many_1,    wrong_no_1},
    {"subs2pf",                 CC_subs2pf,     too_many_1,    wrong_no_1},
    {"lispcodeexp",             too_few_2,      CC_lispcodeexp,wrong_no_2},
    {"defined_vertex",          too_few_2,      CC_defined_vertex,wrong_no_2},
    {"reddom_zeros",            CC_reddom_zeros,too_many_1,    wrong_no_1},
    {"get-all-kernels",         CC_getKallKkernels,too_many_1, wrong_no_1},
    {"dp=retimes",              CC_dpMretimes,  too_many_1,    wrong_no_1},
    {"pa_part2list",            CC_pa_part2list,too_many_1,    wrong_no_1},
    {"gd_simpl",                CC_gd_simpl,    too_many_1,    wrong_no_1},
    {"ofsf_sippatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sippatl},
    {"get_dimension_in",        CC_get_dimension_in,too_many_1,wrong_no_1},
    {"pasf_leqp",               too_few_2,      CC_pasf_leqp,  wrong_no_2},
    {"vdp_sugar",               CC_vdp_sugar,   too_many_1,    wrong_no_1},
    {"acfsf_0mk2",              too_few_2,      CC_acfsf_0mk2, wrong_no_2},
    {"prload",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_prload},
    {"dm-lt",                   too_few_2,      CC_dmKlt,      wrong_no_2},
    {"vdpsimpcont",             CC_vdpsimpcont, too_many_1,    wrong_no_1},
    {"newvar",                  CC_newvar,      too_many_1,    wrong_no_1},
    {"red_prepare",             CC_red_prepare, too_many_1,    wrong_no_1},
    {"bagp",                    CC_bagp,        too_many_1,    wrong_no_1},
    {"ofsf_smdbgetrel",         too_few_2,      CC_ofsf_smdbgetrel,wrong_no_2},
    {"*ff2a",                   too_few_2,      CC_Hff2a,      wrong_no_2},
    {"mktag",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktag},
    {"pasf_subfof",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof},
    {"ofsf_boundchk",           too_few_2,      CC_ofsf_boundchk,wrong_no_2},
    {"intconv",                 CC_intconv,     too_many_1,    wrong_no_1},
    {"qsimpcomb_standard_integer_part_sf",CC_qsimpcomb_standard_integer_part_sf,too_many_1,wrong_no_1},
    {"force-to-dm",             CC_forceKtoKdm, too_many_1,    wrong_no_1},
    {"mk_world1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mk_world1},
    {"cali_bc_power",           too_few_2,      CC_cali_bc_power,wrong_no_2},
    {"isimp2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_isimp2},
    {"ofsf_sminsert1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sminsert1},
    {NULL, (one_args *)"u46", (two_args *)"15711 7743877 1231653", 0}
};

// end of generated code
