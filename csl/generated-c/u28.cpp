
// $destdir\u28.c        Machine generated C code

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



// Code for pasf_cein

static LispObject CC_pasf_cein(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041, v0042;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_cein");
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
    v0042 = stack[-3];
    v0041 = elt(env, 1); // true
    if (v0042 == v0041) goto v0043;
    v0042 = stack[-3];
    v0041 = elt(env, 3); // false
    v0041 = (v0042 == v0041 ? lisp_true : nil);
    goto v0044;

v0044:
    if (v0041 == nil) goto v0045;
    v0041 = qvalue(elt(env, 2)); // t
    goto v0046;

v0046:
    if (!(v0041 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0041 = stack[-3];
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    fn = elt(env, 8); // pasf_deci
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    stack[-2] = v0041;
    v0041 = stack[-2];
    v0041 = qcar(v0041);
    fn = elt(env, 9); // sfto_dcontentf
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    stack[-4] = v0041;
    v0041 = stack[-3];
    stack[-1] = qcar(v0041);
    v0041 = stack[-2];
    stack[0] = qcar(v0041);
    v0041 = stack[-4];
    fn = elt(env, 10); // simp
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0041 = qcar(v0041);
    fn = elt(env, 11); // quotfx
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0042 = stack[-3];
    v0041 = elt(env, 1); // true
    if (v0042 == v0041) goto v0048;
    v0042 = stack[-3];
    v0041 = elt(env, 3); // false
    v0041 = (v0042 == v0041 ? lisp_true : nil);
    goto v0049;

v0049:
    if (v0041 == nil) goto v0050;
    v0041 = stack[-3];
    v0042 = v0041;
    goto v0051;

v0051:
    v0041 = elt(env, 5); // (leq greaterp)
    v0041 = Lmemq(nil, v0042, v0041);
    if (v0041 == nil) goto v0052;
    v0041 = stack[-2];
    v0041 = qcdr(v0041);
    v0042 = negate(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0041 = stack[-4];
    fn = elt(env, 12); // pasf_floor
    v0041 = (*qfn2(fn))(qenv(fn), v0042, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    fn = elt(env, 13); // negf
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    goto v0053;

v0053:
    fn = elt(env, 14); // addf
    v0041 = (*qfn2(fn))(qenv(fn), stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0042 = qvalue(elt(env, 7)); // nil
    {
        LispObject v0054 = stack[-1];
        popv(6);
        return list3(v0054, v0041, v0042);
    }

v0052:
    v0042 = stack[-3];
    v0041 = elt(env, 1); // true
    if (v0042 == v0041) goto v0055;
    v0042 = stack[-3];
    v0041 = elt(env, 3); // false
    v0041 = (v0042 == v0041 ? lisp_true : nil);
    goto v0056;

v0056:
    if (v0041 == nil) goto v0057;
    v0041 = stack[-3];
    v0042 = v0041;
    goto v0058;

v0058:
    v0041 = elt(env, 6); // (geq lessp)
    v0041 = Lmemq(nil, v0042, v0041);
    if (v0041 == nil) goto v0059;
    v0041 = stack[-2];
    v0041 = qcdr(v0041);
    v0042 = negate(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0041 = stack[-4];
    fn = elt(env, 15); // pasf_ceil
    v0041 = (*qfn2(fn))(qenv(fn), v0042, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    fn = elt(env, 13); // negf
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    goto v0053;

v0059:
    v0041 = nil;
    goto v0053;

v0057:
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = Lconsp(nil, v0041);
    env = stack[-5];
    if (v0041 == nil) goto v0060;
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0042 = v0041;
    goto v0058;

v0060:
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0042 = v0041;
    goto v0058;

v0055:
    v0041 = qvalue(elt(env, 2)); // t
    goto v0056;

v0050:
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = Lconsp(nil, v0041);
    env = stack[-5];
    if (v0041 == nil) goto v0061;
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0042 = v0041;
    goto v0051;

v0061:
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0042 = v0041;
    goto v0051;

v0048:
    v0041 = qvalue(elt(env, 2)); // t
    goto v0049;

v0045:
    v0042 = stack[-3];
    v0041 = elt(env, 1); // true
    if (v0042 == v0041) goto v0062;
    v0042 = stack[-3];
    v0041 = elt(env, 3); // false
    v0041 = (v0042 == v0041 ? lisp_true : nil);
    goto v0063;

v0063:
    if (v0041 == nil) goto v0064;
    v0041 = stack[-3];
    v0042 = v0041;
    goto v0065;

v0065:
    v0041 = elt(env, 4); // (leq greaterp geq lessp)
    v0041 = Lmemq(nil, v0042, v0041);
    v0041 = (v0041 == nil ? lisp_true : nil);
    goto v0046;

v0064:
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = Lconsp(nil, v0041);
    env = stack[-5];
    if (v0041 == nil) goto v0066;
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0042 = v0041;
    goto v0065;

v0066:
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0042 = v0041;
    goto v0065;

v0062:
    v0041 = qvalue(elt(env, 2)); // t
    goto v0063;

v0043:
    v0041 = qvalue(elt(env, 2)); // t
    goto v0044;
// error exit handlers
v0047:
    popv(6);
    return nil;
}



// Code for ofsf_sippsignchkf

static LispObject CC_ofsf_sippsignchkf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0018, v0103, v0059, v0104, v0105, v0058, v0106;
    LispObject fn;
    LispObject v0085, v0086, v0087, v0009, v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 7, "ofsf_sippsignchkf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0087 = va_arg(aa, LispObject);
    v0086 = va_arg(aa, LispObject);
    v0085 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_sippsignchkf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0085,v0086,v0087,v0009,v0008,v0088);
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0088,v0008,v0009,v0087,v0086);
        pop(v0085);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0085;
    stack[-2] = v0086;
    stack[-3] = v0087;
    stack[-4] = v0009;
    stack[-5] = v0008;
    stack[-6] = v0088;
    stack[-7] = v0000;
// end of prologue
    v0018 = stack[-7];
    if (!consp(v0018)) goto v0107;
    v0018 = stack[-7];
    v0018 = qcar(v0018);
    v0018 = (consp(v0018) ? nil : lisp_true);
    goto v0108;

v0108:
    if (v0018 == nil) goto v0109;
    v0018 = stack[-7];
    {
        popv(10);
        fn = elt(env, 3); // ofsf_updsigndom
        return (*qfn1(fn))(qenv(fn), v0018);
    }

v0109:
    v0018 = stack[-7];
    v0018 = qcar(v0018);
    v0018 = qcar(v0018);
    v0106 = qcar(v0018);
    v0058 = stack[-6];
    v0105 = stack[-5];
    v0104 = stack[-4];
    v0059 = stack[-3];
    v0103 = stack[-2];
    v0018 = stack[-1];
    fn = elt(env, 4); // ofsf_updsignvar
    v0018 = (*qfnn(fn))(qenv(fn), 7, v0106, v0058, v0105, v0104, v0059, v0103, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-9];
    stack[0] = v0018;
    v0103 = stack[0];
    v0018 = elt(env, 2); // unknown
    if (v0103 == v0018) goto v0110;
    v0018 = stack[-7];
    v0018 = qcar(v0018);
    v0106 = qcdr(v0018);
    v0058 = stack[-6];
    v0105 = stack[-5];
    v0104 = stack[-4];
    v0059 = stack[-3];
    v0103 = stack[-2];
    v0018 = stack[-1];
    v0018 = CC_ofsf_sippsignchkf(env, 7, v0106, v0058, v0105, v0104, v0059, v0103, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-9];
    stack[-8] = v0018;
    v0103 = stack[-8];
    v0018 = elt(env, 2); // unknown
    if (v0103 == v0018) goto v0111;
    v0018 = stack[-7];
    v0106 = qcdr(v0018);
    v0058 = stack[-6];
    v0105 = stack[-5];
    v0104 = stack[-4];
    v0059 = stack[-3];
    v0103 = stack[-2];
    v0018 = stack[-1];
    v0018 = CC_ofsf_sippsignchkf(env, 7, v0106, v0058, v0105, v0104, v0059, v0103, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-9];
    stack[-1] = v0018;
    v0103 = stack[-1];
    v0018 = elt(env, 2); // unknown
    if (v0103 == v0018) goto v0112;
    v0103 = stack[0];
    v0018 = stack[-7];
    v0018 = qcar(v0018);
    v0018 = qcar(v0018);
    v0018 = qcdr(v0018);
    fn = elt(env, 5); // ofsf_updsignpow
    v0018 = (*qfn2(fn))(qenv(fn), v0103, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-9];
    stack[0] = v0018;
    v0103 = stack[-8];
    v0018 = stack[0];
    fn = elt(env, 6); // ofsf_updsignmult
    v0018 = (*qfn2(fn))(qenv(fn), v0103, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-9];
    v0059 = v0018;
    v0103 = v0059;
    v0018 = elt(env, 2); // unknown
    if (v0103 == v0018) goto v0113;
    v0103 = v0059;
    v0018 = stack[-1];
    {
        popv(10);
        fn = elt(env, 7); // ofsf_updsignadd
        return (*qfn2(fn))(qenv(fn), v0103, v0018);
    }

v0113:
    v0018 = elt(env, 2); // unknown
    { popv(10); return onevalue(v0018); }

v0112:
    v0018 = elt(env, 2); // unknown
    { popv(10); return onevalue(v0018); }

v0111:
    v0018 = elt(env, 2); // unknown
    { popv(10); return onevalue(v0018); }

v0110:
    v0018 = elt(env, 2); // unknown
    { popv(10); return onevalue(v0018); }

v0107:
    v0018 = qvalue(elt(env, 1)); // t
    goto v0108;
// error exit handlers
v0052:
    popv(10);
    return nil;
}



// Code for ithlistelem

static LispObject CC_ithlistelem(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0038, v0115;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ithlistelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0088;
    stack[-1] = v0000;
// end of prologue
    v0038 = stack[-1];
    if (v0038 == nil) goto v0085;
    v0038 = stack[-1];
    v0115 = qcar(v0038);
    v0038 = stack[0];
    fn = elt(env, 1); // nth
    stack[-2] = (*qfn2(fn))(qenv(fn), v0115, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0038 = stack[-1];
    v0115 = qcdr(v0038);
    v0038 = stack[0];
    v0038 = CC_ithlistelem(env, v0115, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    {
        LispObject v0117 = stack[-2];
        popv(4);
        return cons(v0117, v0038);
    }

v0085:
    v0038 = nil;
    { popv(4); return onevalue(v0038); }
// error exit handlers
v0116:
    popv(4);
    return nil;
}



// Code for ps!:value

static LispObject CC_psTvalue(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0045, v0100;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:value");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0100 = v0000;
// end of prologue
    v0101 = v0100;
    if (!consp(v0101)) goto v0074;
    v0101 = v0100;
    v0045 = qcar(v0101);
    v0101 = elt(env, 2); // !:ps!:
    if (v0045 == v0101) goto v0118;
    v0101 = v0100;
    v0101 = qcar(v0101);
    if (!symbolp(v0101)) v0101 = nil;
    else { v0101 = qfastgets(v0101);
           if (v0101 != nil) { v0101 = elt(v0101, 8); // dname
#ifdef RECORD_GET
             if (v0101 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0101 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0101 == SPID_NOPROP) v0101 = nil; }}
#endif
    goto v0119;

v0119:
    if (v0101 == nil) goto v0029;
    v0101 = v0100;
    if (!(v0101 == nil)) return onevalue(v0100);
    v0101 = (LispObject)1; // 0
    return onevalue(v0101);

v0029:
    v0045 = v0100;
    v0101 = (LispObject)65; // 4
    {
        fn = elt(env, 4); // ps!:getv
        return (*qfn2(fn))(qenv(fn), v0045, v0101);
    }

v0118:
    v0101 = qvalue(elt(env, 3)); // nil
    goto v0119;

v0074:
    v0101 = qvalue(elt(env, 1)); // t
    goto v0119;
}



// Code for maxl

static LispObject CC_maxl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0122, v0029;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxl");
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
    goto v0085;

v0085:
    v0122 = stack[0];
    if (v0122 == nil) goto v0119;
    v0122 = stack[0];
    v0029 = qcar(v0122);
    v0122 = stack[-1];
    v0122 = cons(v0029, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    stack[-1] = v0122;
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    stack[0] = v0122;
    goto v0085;

v0119:
    v0122 = (LispObject)-159999; // -10000
    v0029 = v0122;
    goto v0074;

v0074:
    v0122 = stack[-1];
    if (v0122 == nil) { popv(3); return onevalue(v0029); }
    v0122 = stack[-1];
    v0122 = qcar(v0122);
    fn = elt(env, 1); // max
    v0122 = (*qfn2(fn))(qenv(fn), v0122, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0029 = v0122;
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    stack[-1] = v0122;
    goto v0074;
// error exit handlers
v0064:
    popv(3);
    return nil;
}



// Code for getrlist

static LispObject CC_getrlist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0029, v0125, v0126;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrlist");
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
    v0126 = v0000;
// end of prologue
    v0125 = v0126;
    v0029 = elt(env, 1); // list
    if (!consp(v0125)) goto v0118;
    v0125 = qcar(v0125);
    if (!(v0125 == v0029)) goto v0118;
    v0029 = v0126;
    v0029 = qcdr(v0029);
    { popv(1); return onevalue(v0029); }

v0118:
    v0125 = v0126;
    v0029 = elt(env, 2); // !*sq
    if (!consp(v0125)) goto v0117;
    v0125 = qcar(v0125);
    if (!(v0125 == v0029)) goto v0117;
    v0029 = v0126;
    v0029 = qcdr(v0029);
    v0029 = qcar(v0029);
    fn = elt(env, 4); // prepsq
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[0];
    v0125 = v0029;
    goto v0120;

v0120:
    v0029 = elt(env, 3); // "list"
    {
        popv(1);
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(qenv(fn), v0125, v0029);
    }

v0117:
    v0029 = v0126;
    v0125 = v0029;
    goto v0120;
// error exit handlers
v0064:
    popv(1);
    return nil;
}



// Code for string2bytelist

static LispObject CC_string2bytelist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0045, v0100;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for string2bytelist");
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
    v0045 = v0000;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 1); // string2list
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[0] = v0045;
    goto v0085;

v0085:
    v0045 = stack[0];
    if (v0045 == nil) goto v0046;
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0045 = Lminusp(nil, v0045);
    env = stack[-2];
    if (v0045 == nil) goto v0129;
    v0100 = (LispObject)4097; // 256
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0100 = plus2(v0100, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    v0045 = stack[-1];
    v0045 = cons(v0100, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[-1] = v0045;
    goto v0130;

v0130:
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    stack[0] = v0045;
    goto v0085;

v0129:
    v0045 = stack[0];
    v0100 = qcar(v0045);
    v0045 = stack[-1];
    v0045 = cons(v0100, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[-1] = v0045;
    goto v0130;

v0046:
    v0045 = stack[-1];
        popv(3);
        return Lnreverse(nil, v0045);
// error exit handlers
v0098:
    popv(3);
    return nil;
}



// Code for calc_coeff

static LispObject CC_calc_coeff(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0100, v0099, v0097;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_coeff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0088;
    stack[-1] = v0000;
// end of prologue
    v0100 = stack[-1];
    if (v0100 == nil) goto v0086;
    v0100 = stack[-1];
    v0099 = qcar(v0100);
    v0100 = stack[0];
    fn = elt(env, 1); // calc_world
    v0100 = (*qfn2(fn))(qenv(fn), v0099, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    v0097 = v0100;
    v0099 = v0097;
    v0100 = (LispObject)1; // 0
    if (v0099 == v0100) goto v0039;
    stack[-2] = v0097;
    v0100 = stack[-1];
    v0099 = qcdr(v0100);
    v0100 = stack[0];
    v0100 = CC_calc_coeff(env, v0099, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    {
        LispObject v0132 = stack[-2];
        popv(4);
        return cons(v0132, v0100);
    }

v0039:
    v0100 = (LispObject)1; // 0
    popv(4);
    return ncons(v0100);

v0086:
    v0100 = (LispObject)17; // 1
    popv(4);
    return ncons(v0100);
// error exit handlers
v0110:
    popv(4);
    return nil;
}



// Code for no!-side!-effectp

static LispObject CC_noKsideKeffectp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0098, v0035;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for no-side-effectp");
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
    v0098 = stack[0];
    if (!consp(v0098)) goto v0087;
    v0098 = stack[0];
    v0035 = qcar(v0098);
    v0098 = elt(env, 2); // quote
    if (v0035 == v0098) goto v0134;
    v0098 = stack[0];
    v0035 = qcar(v0098);
    v0098 = elt(env, 4); // nosideeffects
    v0098 = Lflagp(nil, v0035, v0098);
    env = stack[-1];
    if (v0098 == nil) goto v0100;
    v0098 = stack[0];
    v0098 = qcdr(v0098);
    {
        popv(2);
        fn = elt(env, 5); // no!-side!-effect!-listp
        return (*qfn1(fn))(qenv(fn), v0098);
    }

v0100:
    v0098 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0098); }

v0134:
    v0098 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0098); }

v0087:
    v0098 = stack[0];
    v0098 = (is_number(v0098) ? lisp_true : nil);
    if (!(v0098 == nil)) { popv(2); return onevalue(v0098); }
    v0098 = stack[0];
    if (symbolp(v0098)) goto v0102;
    v0098 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0098); }

v0102:
    v0098 = stack[0];
    v0098 = Lsymbol_specialp(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-1];
    if (!(v0098 == nil)) goto v0120;
    v0098 = stack[0];
    v0098 = Lsymbol_globalp(nil, v0098);
    goto v0120;

v0120:
    v0098 = (v0098 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0098); }
// error exit handlers
v0110:
    popv(2);
    return nil;
}



// Code for listsub

static LispObject CC_listsub(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0110, v0132;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listsub");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0110 = v0088;
    stack[-3] = v0000;
// end of prologue
    v0110 = qcdr(v0110);
    stack[-4] = v0110;
    v0110 = stack[-4];
    if (v0110 == nil) goto v0036;
    v0110 = stack[-4];
    v0110 = qcar(v0110);
    v0132 = stack[-3];
    fn = elt(env, 2); // subeval1
    v0110 = (*qfn2(fn))(qenv(fn), v0132, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0110 = ncons(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    stack[-1] = v0110;
    stack[-2] = v0110;
    goto v0069;

v0069:
    v0110 = stack[-4];
    v0110 = qcdr(v0110);
    stack[-4] = v0110;
    v0110 = stack[-4];
    if (v0110 == nil) goto v0038;
    stack[0] = stack[-1];
    v0110 = stack[-4];
    v0110 = qcar(v0110);
    v0132 = stack[-3];
    fn = elt(env, 2); // subeval1
    v0110 = (*qfn2(fn))(qenv(fn), v0132, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0110 = ncons(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0110 = Lrplacd(nil, stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    stack[-1] = v0110;
    goto v0069;

v0038:
    v0110 = stack[-2];
    goto v0074;

v0074:
    {
        popv(6);
        fn = elt(env, 3); // makelist
        return (*qfn1(fn))(qenv(fn), v0110);
    }

v0036:
    v0110 = qvalue(elt(env, 1)); // nil
    goto v0074;
// error exit handlers
v0096:
    popv(6);
    return nil;
}



// Code for dp_neworder

static LispObject CC_dp_neworder(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0137, v0138;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_neworder");
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
    v0137 = v0000;
// end of prologue
    stack[-4] = v0137;
    v0137 = stack[-4];
    if (v0137 == nil) goto v0130;
    v0137 = stack[-4];
    v0137 = qcar(v0137);
    stack[0] = v0137;
    v0137 = stack[0];
    v0137 = qcar(v0137);
    fn = elt(env, 3); // mo_neworder
    v0138 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0137 = stack[0];
    v0137 = qcdr(v0137);
    v0137 = cons(v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0137 = ncons(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    stack[-2] = v0137;
    stack[-3] = v0137;
    goto v0123;

v0123:
    v0137 = stack[-4];
    v0137 = qcdr(v0137);
    stack[-4] = v0137;
    v0137 = stack[-4];
    if (v0137 == nil) goto v0117;
    stack[-1] = stack[-2];
    v0137 = stack[-4];
    v0137 = qcar(v0137);
    stack[0] = v0137;
    v0137 = stack[0];
    v0137 = qcar(v0137);
    fn = elt(env, 3); // mo_neworder
    v0138 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0137 = stack[0];
    v0137 = qcdr(v0137);
    v0137 = cons(v0138, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0137 = ncons(v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0137 = Lrplacd(nil, stack[-1], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-5];
    v0137 = stack[-2];
    v0137 = qcdr(v0137);
    stack[-2] = v0137;
    goto v0123;

v0117:
    v0137 = stack[-3];
    v0138 = v0137;
    goto v0086;

v0086:
    v0137 = elt(env, 2); // dp!=mocompare
    {
        popv(6);
        fn = elt(env, 4); // sort
        return (*qfn2(fn))(qenv(fn), v0138, v0137);
    }

v0130:
    v0137 = qvalue(elt(env, 1)); // nil
    v0138 = v0137;
    goto v0086;
// error exit handlers
v0139:
    popv(6);
    return nil;
}



// Code for difbf

static LispObject CC_difbf(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0165, v0166, v0167;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for difbf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0088;
    stack[-7] = v0000;
// end of prologue
    v0165 = stack[-7];
    v0165 = qcdr(v0165);
    v0166 = qcar(v0165);
    stack[-8] = v0166;
    v0165 = (LispObject)1; // 0
    if (v0166 == v0165) goto v0036;
    v0165 = stack[-6];
    v0165 = qcdr(v0165);
    v0166 = qcar(v0165);
    stack[-5] = v0166;
    v0165 = (LispObject)1; // 0
    if (v0166 == v0165) goto v0118;
    v0165 = stack[-7];
    v0165 = qcdr(v0165);
    v0166 = qcdr(v0165);
    stack[-4] = v0166;
    v0165 = stack[-6];
    v0165 = qcdr(v0165);
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    v0166 = difference2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    stack[-2] = v0166;
    v0165 = (LispObject)1; // 0
    if (v0166 == v0165) goto v0169;
    stack[-1] = stack[-2];
    v0165 = stack[-8];
    v0165 = Labsval(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    fn = elt(env, 3); // msd
    stack[0] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0165 = stack[-5];
    v0165 = Labsval(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    fn = elt(env, 3); // msd
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0165 = difference2(stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0165 = plus2(stack[-1], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    stack[-1] = v0165;
    v0165 = qvalue(elt(env, 2)); // !:bprec!:
    v0165 = add1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    stack[0] = v0165;
    v0166 = stack[-1];
    v0165 = stack[0];
    v0165 = (LispObject)greaterp2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    v0165 = v0165 ? lisp_true : nil;
    env = stack[-9];
    if (v0165 == nil) goto v0170;
    v0165 = stack[-7];
    goto v0046;

v0046:
    stack[-2] = v0165;
    v0165 = stack[-2];
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    v0167 = v0165;
    v0166 = v0167;
    v0165 = (LispObject)1; // 0
    if (v0166 == v0165) goto v0171;
    v0166 = v0167;
    v0165 = qvalue(elt(env, 2)); // !:bprec!:
    fn = elt(env, 4); // inorm
    v0165 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0167 = v0165;
    stack[-1] = elt(env, 1); // !:rd!:
    v0165 = v0167;
    stack[0] = qcar(v0165);
    v0165 = v0167;
    v0166 = qcdr(v0165);
    v0165 = stack[-2];
    v0165 = qcdr(v0165);
    v0165 = qcdr(v0165);
    v0165 = plus2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    {
        LispObject v0172 = stack[-1];
        LispObject v0173 = stack[0];
        popv(10);
        return list2star(v0172, v0173, v0165);
    }

v0171:
    v0167 = elt(env, 1); // !:rd!:
    v0166 = (LispObject)1; // 0
    v0165 = (LispObject)1; // 0
    popv(10);
    return list2star(v0167, v0166, v0165);

v0170:
    v0165 = stack[0];
    v0165 = negate(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0165 = (LispObject)lessp2(stack[-1], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    v0165 = v0165 ? lisp_true : nil;
    env = stack[-9];
    if (v0165 == nil) goto v0049;
    v0165 = stack[-6];
    fn = elt(env, 5); // minus!:
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    goto v0046;

v0049:
    v0166 = stack[-2];
    v0165 = (LispObject)1; // 0
    v0165 = (LispObject)greaterp2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    v0165 = v0165 ? lisp_true : nil;
    env = stack[-9];
    if (v0165 == nil) goto v0070;
    stack[0] = elt(env, 1); // !:rd!:
    v0166 = stack[-8];
    v0165 = stack[-2];
    fn = elt(env, 6); // ashift
    v0166 = (*qfn2(fn))(qenv(fn), v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0165 = stack[-5];
    v0166 = difference2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0165 = stack[-3];
    v0165 = list2star(stack[0], v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    goto v0046;

v0070:
    stack[0] = elt(env, 1); // !:rd!:
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v0165 = stack[-2];
    v0165 = negate(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    fn = elt(env, 6); // ashift
    v0165 = (*qfn2(fn))(qenv(fn), stack[-3], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0166 = difference2(stack[-1], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0165 = stack[-4];
    v0165 = list2star(stack[0], v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    goto v0046;

v0169:
    stack[0] = elt(env, 1); // !:rd!:
    v0166 = stack[-8];
    v0165 = stack[-5];
    v0166 = difference2(v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    v0165 = stack[-4];
    v0165 = list2star(stack[0], v0166, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    goto v0046;

v0118:
    v0165 = stack[-7];
    goto v0046;

v0036:
    v0165 = stack[-6];
    fn = elt(env, 5); // minus!:
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-9];
    goto v0046;
// error exit handlers
v0168:
    popv(10);
    return nil;
}



// Code for pasf_zcong

static LispObject CC_pasf_zcong(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0145, v0144, v0146;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_zcong");
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
    v0144 = v0000;
// end of prologue
    v0145 = v0144;
    v0145 = Lconsp(nil, v0145);
    env = stack[0];
    if (v0145 == nil) { popv(1); return onevalue(v0144); }
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0145 = Lconsp(nil, v0145);
    env = stack[0];
    if (v0145 == nil) { popv(1); return onevalue(v0144); }
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0146 = qcar(v0145);
    v0145 = elt(env, 1); // (cong ncong)
    v0145 = Lmemq(nil, v0146, v0145);
    if (v0145 == nil) { popv(1); return onevalue(v0144); }
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0145 = qcdr(v0145);
    if (v0145 == nil) goto v0035;
    v0145 = v0144;
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    if (v0145 == nil) goto v0183;
    v0145 = qvalue(elt(env, 8)); // nil
    goto v0184;

v0184:
    if (v0145 == nil) goto v0185;
    v0145 = elt(env, 2); // true
    { popv(1); return onevalue(v0145); }

v0185:
    v0145 = v0144;
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    if (v0145 == nil) goto v0017;
    v0145 = qvalue(elt(env, 8)); // nil
    goto v0072;

v0072:
    if (v0145 == nil) { popv(1); return onevalue(v0144); }
    v0145 = elt(env, 4); // false
    { popv(1); return onevalue(v0145); }

v0017:
    v0146 = v0144;
    v0145 = elt(env, 2); // true
    if (v0146 == v0145) goto v0186;
    v0146 = v0144;
    v0145 = elt(env, 4); // false
    v0145 = (v0146 == v0145 ? lisp_true : nil);
    goto v0187;

v0187:
    if (v0145 == nil) goto v0188;
    v0145 = v0144;
    v0146 = v0145;
    goto v0189;

v0189:
    v0145 = elt(env, 9); // ncong
    v0145 = (v0146 == v0145 ? lisp_true : nil);
    goto v0072;

v0188:
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0145 = Lconsp(nil, v0145);
    env = stack[0];
    if (v0145 == nil) goto v0190;
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0146 = v0145;
    goto v0189;

v0190:
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0146 = v0145;
    goto v0189;

v0186:
    v0145 = qvalue(elt(env, 3)); // t
    goto v0187;

v0183:
    v0146 = v0144;
    v0145 = elt(env, 2); // true
    if (v0146 == v0145) goto v0026;
    v0146 = v0144;
    v0145 = elt(env, 4); // false
    v0145 = (v0146 == v0145 ? lisp_true : nil);
    goto v0191;

v0191:
    if (v0145 == nil) goto v0192;
    v0145 = v0144;
    v0146 = v0145;
    goto v0053;

v0053:
    v0145 = elt(env, 5); // cong
    v0145 = (v0146 == v0145 ? lisp_true : nil);
    goto v0184;

v0192:
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0145 = Lconsp(nil, v0145);
    env = stack[0];
    if (v0145 == nil) goto v0193;
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0146 = v0145;
    goto v0053;

v0193:
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0146 = v0145;
    goto v0053;

v0026:
    v0145 = qvalue(elt(env, 3)); // t
    goto v0191;

v0035:
    v0146 = v0144;
    v0145 = elt(env, 2); // true
    if (v0146 == v0145) goto v0097;
    v0146 = v0144;
    v0145 = elt(env, 4); // false
    v0145 = (v0146 == v0145 ? lisp_true : nil);
    goto v0099;

v0099:
    if (v0145 == nil) goto v0045;
    v0145 = v0144;
    v0146 = v0145;
    goto v0126;

v0126:
    v0145 = elt(env, 5); // cong
    if (v0146 == v0145) goto v0129;
    v0145 = elt(env, 7); // neq
    goto v0115;

v0115:
    v0144 = qcdr(v0144);
    v0144 = qcar(v0144);
    v0146 = qvalue(elt(env, 8)); // nil
    popv(1);
    return list3(v0145, v0144, v0146);

v0129:
    v0145 = elt(env, 6); // equal
    goto v0115;

v0045:
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0145 = Lconsp(nil, v0145);
    env = stack[0];
    if (v0145 == nil) goto v0194;
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0146 = v0145;
    goto v0126;

v0194:
    v0145 = v0144;
    v0145 = qcar(v0145);
    v0146 = v0145;
    goto v0126;

v0097:
    v0145 = qvalue(elt(env, 3)); // t
    goto v0099;
}



// Code for sfto_mvarx

static LispObject CC_sfto_mvarx(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0114;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_mvarx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0114 = v0000;
// end of prologue
    v0039 = v0114;
    if (!consp(v0039)) goto v0074;
    v0039 = v0114;
    v0039 = qcar(v0039);
    v0039 = (consp(v0039) ? nil : lisp_true);
    goto v0119;

v0119:
    if (v0039 == nil) goto v0102;
    v0039 = qvalue(elt(env, 2)); // nil
    return onevalue(v0039);

v0102:
    v0039 = v0114;
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    return onevalue(v0039);

v0074:
    v0039 = qvalue(elt(env, 1)); // t
    goto v0119;
}



// Code for fnrd

static LispObject CC_fnrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0116, v0117;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fnrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fnrd");
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
    stack[0] = nil;
    fn = elt(env, 3); // lex
    v0116 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    v0117 = qvalue(elt(env, 1)); // char
    v0116 = elt(env, 2); // (c i)
    if (equal(v0117, v0116)) goto v0114;
    v0116 = qvalue(elt(env, 1)); // char
    v0117 = Lcompress(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    v0116 = (LispObject)321; // 20
    fn = elt(env, 4); // errorml
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    goto v0085;

v0085:
    v0116 = stack[0];
    if (!(!consp(v0116))) goto v0118;
    v0116 = stack[0];
    v0116 = ncons(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    fn = elt(env, 5); // operator
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    fn = elt(env, 6); // aeval
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    goto v0118;

v0118:
    fn = elt(env, 3); // lex
    v0116 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0114:
    fn = elt(env, 7); // mathml2
    v0116 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    stack[0] = v0116;
    goto v0085;
// error exit handlers
v0129:
    popv(2);
    return nil;
}



// Code for sparpri

static LispObject CC_sparpri(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0162, v0160, v0181;
    LispObject fn;
    LispObject v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sparpri");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sparpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0088,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0008;
    v0162 = v0088;
    v0160 = v0000;
// end of prologue
    stack[-5] = v0162;
    v0162 = v0160;
    stack[-3] = v0162;
    goto v0123;

v0123:
    v0162 = stack[-3];
    if (v0162 == nil) goto v0124;
    v0162 = stack[-3];
    v0162 = qcar(v0162);
    stack[-2] = v0162;
    stack[-1] = elt(env, 2); // quote
    stack[0] = elt(env, 3); // setq
    v0181 = stack[-4];
    v0160 = stack[-5];
    v0162 = stack[-2];
    v0162 = qcar(v0162);
    v0160 = list3(v0181, v0160, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-6];
    v0162 = stack[-2];
    v0162 = qcdr(v0162);
    v0162 = list3(stack[0], v0160, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-6];
    v0160 = list2(stack[-1], v0162);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-6];
    v0162 = elt(env, 4); // first
    fn = elt(env, 7); // writepri
    v0162 = (*qfn2(fn))(qenv(fn), v0160, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-6];
    v0160 = elt(env, 5); // (quote !$)
    v0162 = elt(env, 6); // last
    fn = elt(env, 7); // writepri
    v0162 = (*qfn2(fn))(qenv(fn), v0160, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-6];
    v0162 = stack[-3];
    v0162 = qcdr(v0162);
    stack[-3] = v0162;
    goto v0123;

v0124:
    v0162 = nil;
    { popv(7); return onevalue(v0162); }
// error exit handlers
v0161:
    popv(7);
    return nil;
}



// Code for evequal

static LispObject CC_evequal(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0034, v0110, v0132, v0135, v0164;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0132 = v0088;
    v0135 = v0000;
// end of prologue

v0086:
    v0034 = v0135;
    if (v0034 == nil) goto v0124;
    v0034 = qvalue(elt(env, 1)); // nil
    goto v0046;

v0046:
    if (v0034 == nil) goto v0069;
    v0034 = qvalue(elt(env, 2)); // t
    return onevalue(v0034);

v0069:
    v0034 = v0135;
    if (v0034 == nil) goto v0120;
    v0034 = v0132;
    if (v0034 == nil) goto v0114;
    v0164 = (LispObject)1; // 0
    v0034 = v0135;
    v0110 = qcar(v0034);
    v0034 = v0132;
    v0034 = qcar(v0034);
    v0034 = (LispObject)(int32_t)((int32_t)v0110 - (int32_t)v0034 + TAG_FIXNUM);
    if (v0164 == v0034) goto v0037;
    v0034 = qvalue(elt(env, 1)); // nil
    return onevalue(v0034);

v0037:
    v0034 = v0135;
    v0034 = qcdr(v0034);
    v0135 = v0034;
    v0034 = v0132;
    v0034 = qcdr(v0034);
    v0132 = v0034;
    goto v0086;

v0114:
    v0034 = elt(env, 3); // (0)
    v0132 = v0034;
    goto v0086;

v0120:
    v0034 = elt(env, 3); // (0)
    v0135 = v0034;
    goto v0086;

v0124:
    v0034 = v0132;
    v0034 = (v0034 == nil ? lisp_true : nil);
    goto v0046;
}



// Code for vdpilcomb1

static LispObject CC_vdpilcomb1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0163, v0066, v0161, v0197, v0198, v0030;
    LispObject fn;
    LispObject v0086, v0087, v0009, v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "vdpilcomb1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0087 = va_arg(aa, LispObject);
    v0086 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpilcomb1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0086,v0087,v0009,v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0088,v0008,v0009,v0087,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0086;
    v0163 = v0087;
    stack[-2] = v0009;
    stack[-3] = v0008;
    v0066 = v0088;
    stack[-4] = v0000;
// end of prologue
    v0161 = stack[-4];
    v0161 = qcdr(v0161);
    v0161 = qcdr(v0161);
    v0161 = qcdr(v0161);
    v0030 = qcar(v0161);
    v0198 = v0066;
    v0197 = stack[-3];
    v0066 = stack[-2];
    v0066 = qcdr(v0066);
    v0066 = qcdr(v0066);
    v0066 = qcdr(v0066);
    v0161 = qcar(v0066);
    v0066 = v0163;
    v0163 = stack[-1];
    fn = elt(env, 2); // dipilcomb1
    v0163 = (*qfnn(fn))(qenv(fn), 6, v0030, v0198, v0197, v0161, v0066, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    fn = elt(env, 3); // dip2vdp
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    stack[-5] = v0163;
    v0163 = qvalue(elt(env, 1)); // !*gsugar
    if (v0163 == nil) { LispObject res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v0163 = stack[-4];
    fn = elt(env, 4); // gsugar
    stack[-4] = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    v0163 = stack[-3];
    fn = elt(env, 5); // vevtdeg
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    stack[-3] = plus2(stack[-4], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    v0163 = stack[-2];
    fn = elt(env, 4); // gsugar
    stack[-2] = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    v0163 = stack[-1];
    fn = elt(env, 5); // vevtdeg
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    v0163 = plus2(stack[-2], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    fn = elt(env, 6); // max
    v0163 = (*qfn2(fn))(qenv(fn), stack[-3], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-6];
    fn = elt(env, 7); // gsetsugar
    v0163 = (*qfn2(fn))(qenv(fn), stack[0], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    { LispObject res = stack[-5]; popv(7); return onevalue(res); }
// error exit handlers
v0091:
    popv(7);
    return nil;
}



// Code for gfplus

static LispObject CC_gfplus(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0200, v0134, v0118;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0134 = v0088;
    v0118 = v0000;
// end of prologue
    v0200 = v0118;
    v0200 = qcar(v0200);
    if (!consp(v0200)) goto v0028;
    v0200 = v0118;
    {
        fn = elt(env, 1); // gbfplus
        return (*qfn2(fn))(qenv(fn), v0200, v0134);
    }

v0028:
    v0200 = v0118;
    {
        fn = elt(env, 2); // gffplus
        return (*qfn2(fn))(qenv(fn), v0200, v0134);
    }
}



// Code for sublap

static LispObject CC_sublap(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0091, v0092;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sublap");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0088;
    stack[-1] = v0000;
// end of prologue
    v0091 = stack[-1];
    if (v0091 == nil) goto v0124;
    v0091 = stack[0];
    v0091 = (v0091 == nil ? lisp_true : nil);
    goto v0046;

v0046:
    if (!(v0091 == nil)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0091 = stack[0];
    if (!consp(v0091)) goto v0120;
    v0091 = stack[0];
    v0092 = qcar(v0091);
    v0091 = elt(env, 2); // app
    v0091 = Lflagp(nil, v0092, v0091);
    env = stack[-3];
    if (v0091 == nil) goto v0181;
    v0092 = stack[-1];
    v0091 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); // sublap1
        return (*qfn2(fn))(qenv(fn), v0092, v0091);
    }

v0181:
    v0092 = stack[-1];
    v0091 = stack[0];
    v0091 = qcar(v0091);
    stack[-2] = CC_sublap(env, v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-3];
    v0092 = stack[-1];
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    v0091 = CC_sublap(env, v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    {
        LispObject v0111 = stack[-2];
        popv(4);
        return cons(v0111, v0091);
    }

v0120:
    v0091 = stack[0];
    if (is_number(v0091)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0092 = stack[0];
    v0091 = stack[-1];
    v0091 = Latsoc(nil, v0092, v0091);
    v0092 = v0091;
    if (v0091 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0091 = v0092;
    v0091 = qcdr(v0091);
    { popv(4); return onevalue(v0091); }

v0124:
    v0091 = qvalue(elt(env, 1)); // t
    goto v0046;
// error exit handlers
v0180:
    popv(4);
    return nil;
}



// Code for simppartdf

static LispObject CC_simppartdf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simppartdf");
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
    v0086 = v0000;
// end of prologue
    fn = elt(env, 1); // partitpartdf
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(qenv(fn), v0086);
    }
// error exit handlers
v0085:
    popv(1);
    return nil;
}



// Code for getphystypeall

static LispObject CC_getphystypeall(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0129, v0122;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystypeall");
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
    v0122 = (LispObject)1; // 0
    v0129 = stack[0];
    fn = elt(env, 3); // deleteall
    v0129 = (*qfn2(fn))(qenv(fn), v0122, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    fn = elt(env, 4); // collectphystype
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    v0122 = v0129;
    if (v0129 == nil) goto v0119;
    v0129 = v0122;
    v0129 = qcdr(v0129);
    if (v0129 == nil) goto v0127;
    stack[-1] = elt(env, 0); // getphystypeall
    v0122 = elt(env, 2); // "PHYSOP type mismatch in"
    v0129 = stack[0];
    v0129 = list2(v0122, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    fn = elt(env, 5); // rederr2
    v0129 = (*qfn2(fn))(qenv(fn), stack[-1], v0129);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    v0129 = nil;
    { popv(3); return onevalue(v0129); }

v0127:
    v0129 = v0122;
    v0129 = qcar(v0129);
    { popv(3); return onevalue(v0129); }

v0119:
    v0129 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0129); }
// error exit handlers
v0126:
    popv(3);
    return nil;
}



// Code for realvaluedp

static LispObject CC_realvaluedp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0138, v0162, v0160;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for realvaluedp");
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
    v0162 = v0000;
// end of prologue
    v0138 = v0162;
    if (!consp(v0138)) goto v0087;
    v0138 = v0162;
    v0160 = qcar(v0138);
    stack[0] = v0160;
    v0138 = elt(env, 2); // alwaysrealvalued
    v0138 = Lflagp(nil, v0160, v0138);
    env = stack[-1];
    if (v0138 == nil) goto v0063;
    v0138 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0138); }

v0063:
    v0160 = stack[0];
    v0138 = elt(env, 1); // realvalued
    v0138 = Lflagp(nil, v0160, v0138);
    env = stack[-1];
    if (v0138 == nil) goto v0110;
    v0138 = v0162;
    v0138 = qcdr(v0138);
    fn = elt(env, 6); // realvaluedlist
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-1];
    goto v0125;

v0125:
    if (!(v0138 == nil)) { popv(2); return onevalue(v0138); }
    v0138 = stack[0];
    v0162 = elt(env, 5); // !:rd!:
    v0138 = (v0138 == v0162 ? lisp_true : nil);
    { popv(2); return onevalue(v0138); }

v0110:
    v0138 = qvalue(elt(env, 4)); // nil
    goto v0125;

v0087:
    v0138 = v0162;
    v0138 = (is_number(v0138) ? lisp_true : nil);
    if (!(v0138 == nil)) { popv(2); return onevalue(v0138); }
    v0138 = v0162;
    v0162 = elt(env, 1); // realvalued
        popv(2);
        return Lflagp(nil, v0138, v0162);
// error exit handlers
v0201:
    popv(2);
    return nil;
}



// Code for assert_kernelp

static LispObject CC_assert_kernelp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0126, v0064;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_kernelp");
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
    v0126 = v0000;
// end of prologue
    v0064 = v0126;
    if (symbolp(v0064)) goto v0119;
    v0064 = v0126;
    v0064 = Lconsp(nil, v0064);
    env = stack[0];
    if (v0064 == nil) goto v0123;
    v0064 = v0126;
    v0064 = qcar(v0064);
    if (!symbolp(v0064)) v0064 = nil;
    else { v0064 = qfastgets(v0064);
           if (v0064 != nil) { v0064 = elt(v0064, 38); // fkernfn
#ifdef RECORD_GET
             if (v0064 != SPID_NOPROP)
                record_get(elt(fastget_names, 38), 1);
             else record_get(elt(fastget_names, 38), 0),
                v0064 = nil; }
           else record_get(elt(fastget_names, 38), 0); }
#else
             if (v0064 == SPID_NOPROP) v0064 = nil; }}
#endif
    if (v0064 == nil) goto v0108;
    v0126 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0126); }

v0108:
    v0064 = v0126;
    v0064 = qcar(v0064);
    if (!consp(v0064)) goto v0134;
    v0064 = qvalue(elt(env, 3)); // exlist!*
    goto v0065;

v0065:
    v0126 = Latsoc(nil, v0126, v0064);
    { popv(1); return onevalue(v0126); }

v0134:
    v0064 = v0126;
    v0064 = qcar(v0064);
    if (!symbolp(v0064)) v0064 = nil;
    else { v0064 = qfastgets(v0064);
           if (v0064 != nil) { v0064 = elt(v0064, 24); // klist
#ifdef RECORD_GET
             if (v0064 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0064 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0064 == SPID_NOPROP) v0064 = nil; }}
#endif
    goto v0065;

v0123:
    v0126 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0126); }

v0119:
    v0126 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0126); }
}



// Code for remchkf1

static LispObject CC_remchkf1(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0063, v0062, v0101;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remchkf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0088;
    stack[-1] = v0000;
// end of prologue
    v0063 = stack[-1];
    fn = elt(env, 4); // termsf
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-2] = v0063;
    v0101 = stack[-1];
    v0062 = stack[0];
    v0063 = stack[-2];
    fn = elt(env, 5); // xremf
    v0063 = (*qfnn(fn))(qenv(fn), 3, v0101, v0062, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[0] = v0063;
    v0063 = stack[0];
    if (v0063 == nil) goto v0199;
    v0063 = stack[0];
    v0063 = qcar(v0063);
    stack[0] = v0063;
    fn = elt(env, 4); // termsf
    v0062 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0063 = stack[-2];
    v0063 = (LispObject)geq2(v0062, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    v0063 = v0063 ? lisp_true : nil;
    env = stack[-3];
    goto v0114;

v0114:
    if (!(v0063 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0063 = qvalue(elt(env, 2)); // !*trcompact
    if (v0063 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0063 = elt(env, 3); // "*** Remainder smaller"
    fn = elt(env, 6); // prin2t
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0199:
    v0063 = qvalue(elt(env, 1)); // t
    goto v0114;
// error exit handlers
v0097:
    popv(4);
    return nil;
}



// Code for gvar1

static LispObject CC_gvar1(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0082, v0081, v0051, v0079;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gvar1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0079 = v0088;
    v0051 = v0000;
// end of prologue

v0086:
    v0082 = v0051;
    if (v0082 == nil) goto v0124;
    v0082 = v0051;
    v0082 = (is_number(v0082) ? lisp_true : nil);
    if (!(v0082 == nil)) goto v0046;
    v0081 = v0051;
    v0082 = elt(env, 2); // i
    if (v0081 == v0082) goto v0114;
    v0082 = qvalue(elt(env, 4)); // nil
    goto v0046;

v0046:
    if (!(v0082 == nil)) return onevalue(v0079);
    v0082 = v0051;
    if (!consp(v0082)) goto v0126;
    v0082 = v0051;
    v0082 = qcar(v0082);
    if (!symbolp(v0082)) v0082 = nil;
    else { v0082 = qfastgets(v0082);
           if (v0082 != nil) { v0082 = elt(v0082, 8); // dname
#ifdef RECORD_GET
             if (v0082 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0082 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0082 == SPID_NOPROP) v0082 = nil; }}
#endif
    if (!(v0082 == nil)) return onevalue(v0079);
    v0082 = v0051;
    v0081 = qcar(v0082);
    v0082 = elt(env, 5); // (plus times expt difference minus)
    v0082 = Lmemq(nil, v0081, v0082);
    if (v0082 == nil) goto v0090;
    v0082 = v0051;
    v0082 = qcdr(v0082);
    v0081 = v0079;
    {
        fn = elt(env, 7); // gvarlis1
        return (*qfn2(fn))(qenv(fn), v0082, v0081);
    }

v0090:
    v0082 = v0051;
    v0081 = qcar(v0082);
    v0082 = elt(env, 6); // quotient
    if (v0081 == v0082) goto v0092;
    v0081 = v0051;
    v0082 = v0079;
    v0082 = Lmember(nil, v0081, v0082);
    if (!(v0082 == nil)) return onevalue(v0079);
    v0082 = v0051;
    v0081 = v0079;
    return cons(v0082, v0081);

v0092:
    v0082 = v0051;
    v0082 = qcdr(v0082);
    v0082 = qcar(v0082);
    v0051 = v0082;
    goto v0086;

v0126:
    v0081 = v0051;
    v0082 = v0079;
    v0082 = Lmember(nil, v0081, v0082);
    if (!(v0082 == nil)) return onevalue(v0079);
    v0082 = v0051;
    v0081 = v0079;
    return cons(v0082, v0081);

v0114:
    v0082 = qvalue(elt(env, 3)); // !*complex
    goto v0046;

v0124:
    v0082 = qvalue(elt(env, 1)); // t
    goto v0046;
}



// Code for pasf_anegrel

static LispObject CC_pasf_anegrel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0039, v0114;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_anegrel");
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
    v0114 = v0000;
// end of prologue
    v0039 = v0114;
    v0040 = elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong))
    v0040 = Latsoc(nil, v0039, v0040);
    v0040 = qcdr(v0040);
    if (!(v0040 == nil)) { popv(1); return onevalue(v0040); }
    v0040 = elt(env, 2); // "pasf_anegrel: unknown operator "
    v0039 = v0114;
    v0040 = list2(v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(qenv(fn), v0040);
    }
// error exit handlers
v0199:
    popv(1);
    return nil;
}



// Code for ciml

static LispObject CC_ciml(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0116, v0117;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ciml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ciml");
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
    v0117 = qvalue(elt(env, 2)); // atts
    v0116 = elt(env, 3); // (t y p e)
    fn = elt(env, 5); // search_att
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    fn = elt(env, 6); // lex
    v0116 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    v0116 = qvalue(elt(env, 4)); // char
    stack[0] = v0116;
    fn = elt(env, 6); // lex
    v0116 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    v0116 = stack[0];
    v0116 = Lcompress(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    stack[0] = v0116;
    v0116 = stack[0];
    if (!(is_number(v0116))) goto v0039;
    v0117 = stack[0];
    v0116 = (LispObject)65; // 4
    fn = elt(env, 7); // errorml
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    goto v0039;

v0039:
    v0116 = stack[0];
        popv(2);
        return Lintern(nil, v0116);
// error exit handlers
v0129:
    popv(2);
    return nil;
}



// Code for mconv1

static LispObject CC_mconv1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0062, v0101;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mconv1");
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
    goto v0086;

v0086:
    v0062 = stack[-1];
    if (!consp(v0062)) goto v0124;
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = (consp(v0062) ? nil : lisp_true);
    goto v0046;

v0046:
    if (v0062 == nil) goto v0037;
    stack[0] = stack[-2];
    v0062 = stack[-1];
    fn = elt(env, 2); // drnconv
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    {
        LispObject v0098 = stack[0];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0098, v0062);
    }

v0037:
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    stack[0] = qcar(v0062);
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    v0101 = CC_mconv1(env, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0062 = stack[-2];
    v0062 = acons(stack[0], v0101, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-2] = v0062;
    v0062 = stack[-1];
    v0062 = qcdr(v0062);
    stack[-1] = v0062;
    goto v0086;

v0124:
    v0062 = qvalue(elt(env, 1)); // t
    goto v0046;
// error exit handlers
v0097:
    popv(4);
    return nil;
}



// Code for physoptimes

static LispObject CC_physoptimes(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0211, v0212;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physoptimes");
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
    stack[0] = v0000;
// end of prologue
    stack[-2] = nil;
    v0212 = qvalue(elt(env, 1)); // tstack!*
    v0211 = (LispObject)1; // 0
    if (v0212 == v0211) goto v0102;
    v0211 = qvalue(elt(env, 3)); // nil
    goto v0130;

v0130:
    if (v0211 == nil) goto v0123;
    v0211 = qvalue(elt(env, 2)); // mul!*
    stack[-2] = v0211;
    v0211 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 2)) = v0211; // mul!*
    goto v0123;

v0123:
    v0211 = qvalue(elt(env, 1)); // tstack!*
    v0211 = add1(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    qvalue(elt(env, 1)) = v0211; // tstack!*
    v0211 = stack[0];
    v0211 = qcar(v0211);
    fn = elt(env, 6); // physopsim!*
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0211;
    v0211 = stack[0];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    goto v0129;

v0129:
    v0211 = stack[-1];
    if (v0211 == nil) goto v0028;
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    fn = elt(env, 6); // physopsim!*
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-5] = v0211;
    v0211 = stack[-6];
    fn = elt(env, 7); // getphystype
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-4] = v0211;
    v0211 = stack[-5];
    fn = elt(env, 7); // getphystype
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-3] = v0211;
    v0211 = stack[-4];
    if (v0211 == nil) goto v0164;
    v0211 = stack[-3];
    if (v0211 == nil) goto v0192;
    v0211 = stack[-6];
    fn = elt(env, 8); // physopaeval
    stack[0] = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0211 = stack[-5];
    fn = elt(env, 8); // physopaeval
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 9); // physopordchk
    v0211 = (*qfn2(fn))(qenv(fn), stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    if (v0211 == nil) goto v0016;
    v0212 = stack[-4];
    v0211 = stack[-3];
    if (equal(v0212, v0211)) goto v0148;
    v0211 = qvalue(elt(env, 3)); // nil
    goto v0189;

v0189:
    if (v0211 == nil) goto v0016;
    v0211 = stack[-6];
    fn = elt(env, 10); // physop2sq
    stack[0] = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0211 = stack[-5];
    fn = elt(env, 10); // physop2sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 11); // multsq
    v0211 = (*qfn2(fn))(qenv(fn), stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0211;
    goto v0135;

v0135:
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    goto v0129;

v0016:
    v0212 = stack[-6];
    v0211 = stack[-5];
    fn = elt(env, 13); // multopop!*
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0211;
    goto v0135;

v0148:
    v0212 = stack[-4];
    v0211 = elt(env, 4); // scalar
    v0211 = (v0212 == v0211 ? lisp_true : nil);
    goto v0189;

v0192:
    v0211 = stack[-5];
    v0211 = (LispObject)zerop(v0211);
    v0211 = v0211 ? lisp_true : nil;
    env = stack[-7];
    if (v0211 == nil) goto v0027;
    v0212 = qvalue(elt(env, 3)); // nil
    v0211 = (LispObject)17; // 1
    v0211 = cons(v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0213;

v0213:
    stack[-6] = v0211;
    goto v0135;

v0027:
    v0211 = stack[-5];
    v0211 = Lonep(nil, v0211);
    env = stack[-7];
    if (v0211 == nil) goto v0025;
    v0211 = stack[-6];
    fn = elt(env, 10); // physop2sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0213;

v0025:
    v0211 = stack[-5];
    fn = elt(env, 10); // physop2sq
    stack[0] = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0211 = stack[-6];
    fn = elt(env, 10); // physop2sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 11); // multsq
    v0211 = (*qfn2(fn))(qenv(fn), stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0213;

v0164:
    v0211 = stack[-3];
    if (v0211 == nil) goto v0160;
    v0211 = stack[-6];
    v0211 = (LispObject)zerop(v0211);
    v0211 = v0211 ? lisp_true : nil;
    env = stack[-7];
    if (v0211 == nil) goto v0198;
    v0212 = qvalue(elt(env, 3)); // nil
    v0211 = (LispObject)17; // 1
    v0211 = cons(v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0211;
    goto v0135;

v0198:
    v0211 = stack[-6];
    v0211 = Lonep(nil, v0211);
    env = stack[-7];
    if (v0211 == nil) goto v0214;
    v0211 = stack[-5];
    fn = elt(env, 10); // physop2sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0211;
    goto v0135;

v0214:
    v0211 = stack[-6];
    fn = elt(env, 10); // physop2sq
    stack[0] = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0211 = stack[-5];
    fn = elt(env, 10); // physop2sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 11); // multsq
    v0211 = (*qfn2(fn))(qenv(fn), stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0211;
    goto v0135;

v0160:
    v0211 = stack[-6];
    fn = elt(env, 10); // physop2sq
    stack[0] = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0211 = stack[-5];
    fn = elt(env, 10); // physop2sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 11); // multsq
    v0211 = (*qfn2(fn))(qenv(fn), stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // mk!*sq
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0211;
    goto v0135;

v0028:
    v0211 = qvalue(elt(env, 2)); // mul!*
    if (v0211 == nil) goto v0215;
    v0212 = qvalue(elt(env, 1)); // tstack!*
    v0211 = (LispObject)17; // 1
    v0211 = (LispObject)greaterp2(v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    v0211 = v0211 ? lisp_true : nil;
    env = stack[-7];
    goto v0216;

v0216:
    if (v0211 == nil) goto v0217;
    v0211 = qvalue(elt(env, 1)); // tstack!*
    v0211 = sub1(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    qvalue(elt(env, 1)) = v0211; // tstack!*
    v0212 = qvalue(elt(env, 1)); // tstack!*
    v0211 = (LispObject)1; // 0
    if (!(v0212 == v0211)) { LispObject res = stack[-6]; popv(8); return onevalue(res); }
    v0211 = stack[-2];
    qvalue(elt(env, 2)) = v0211; // mul!*
    { LispObject res = stack[-6]; popv(8); return onevalue(res); }

v0217:
    v0211 = qvalue(elt(env, 2)); // mul!*
    v0212 = qcar(v0211);
    v0211 = stack[-6];
    v0211 = Lapply1(nil, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0211;
    v0211 = qvalue(elt(env, 2)); // mul!*
    v0211 = qcdr(v0211);
    qvalue(elt(env, 2)) = v0211; // mul!*
    goto v0028;

v0215:
    v0211 = qvalue(elt(env, 5)); // t
    goto v0216;

v0102:
    v0211 = qvalue(elt(env, 2)); // mul!*
    goto v0130;
// error exit handlers
v0168:
    popv(8);
    return nil;
}



// Code for prop!-simp1

static LispObject CC_propKsimp1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0213, v0183, v0027;
    LispObject fn;
    LispObject v0087, v0009, v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "prop-simp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0087 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prop-simp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0087,v0009,v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0088,v0008,v0009,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0087;
    stack[0] = v0009;
    stack[-5] = v0008;
    stack[-2] = v0088;
    stack[-6] = v0000;
// end of prologue

v0221:
    v0213 = stack[-2];
    if (v0213 == nil) goto v0107;
    v0183 = stack[-6];
    v0213 = stack[-2];
    v0213 = qcar(v0213);
    fn = elt(env, 1); // prop!-simp2
    v0213 = (*qfn2(fn))(qenv(fn), v0183, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-8];
    stack[-3] = v0213;
    v0213 = stack[-3];
    if (v0213 == nil) goto v0031;
    v0213 = stack[-3];
    stack[-6] = qcdr(v0213);
    v0213 = stack[-2];
    stack[-2] = qcdr(v0213);
    stack[-1] = stack[-5];
    v0213 = stack[0];
    stack[0] = add1(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-8];
    v0213 = stack[-3];
    stack[-7] = qcar(v0213);
    stack[-3] = (LispObject)-15; // -1
    v0213 = stack[-5];
    v0213 = Llength(nil, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-8];
    v0213 = Lexpt(nil, stack[-3], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-8];
    v0213 = times2(stack[-4], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-8];
    v0213 = times2(stack[-7], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-8];
    stack[-5] = stack[-1];
    stack[-4] = v0213;
    goto v0221;

v0031:
    stack[-3] = stack[-6];
    v0213 = stack[-2];
    stack[-1] = qcdr(v0213);
    v0213 = stack[-2];
    v0183 = qcar(v0213);
    v0213 = stack[-5];
    v0027 = cons(v0183, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-8];
    v0183 = stack[0];
    v0213 = stack[-4];
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v0027;
    stack[0] = v0183;
    stack[-4] = v0213;
    goto v0221;

v0107:
    v0183 = stack[0];
    v0213 = stack[-4];
    stack[0] = list2(v0183, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-8];
    stack[-1] = stack[-6];
    v0213 = stack[-5];
    v0213 = Lreverse(nil, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    {
        LispObject v0019 = stack[0];
        LispObject v0209 = stack[-1];
        popv(9);
        return list2star(v0019, v0209, v0213);
    }
// error exit handlers
v0080:
    popv(9);
    return nil;
}



// Code for liennewstruc

static LispObject CC_liennewstruc(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0367, v0368, v0369, v0370;
    LispObject fn;
    LispObject v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "liennewstruc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for liennewstruc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0088,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-12] = v0008;
    stack[-13] = v0088;
    stack[-14] = v0000;
// end of prologue
    v0369 = elt(env, 1); // lie_a
    v0368 = stack[-14];
    v0367 = stack[-14];
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = ncons(v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 12); // matrix
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 13); // aeval
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[0] = elt(env, 1); // lie_a
    v0369 = elt(env, 2); // expt
    v0368 = elt(env, 1); // lie_a
    v0367 = (LispObject)1; // 0
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 13); // aeval
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0367 = (*qfn2(fn))(qenv(fn), stack[0], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-13];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-15] = v0367;
    goto v0101;

v0101:
    stack[0] = elt(env, 3); // difference
    v0369 = elt(env, 3); // difference
    v0368 = stack[-14];
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-15];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0066;
    v0369 = elt(env, 5); // plus
    v0368 = stack[-13];
    v0367 = (LispObject)33; // 2
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-2] = v0367;
    goto v0372;

v0372:
    stack[0] = elt(env, 3); // difference
    v0367 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-2];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0373;
    stack[0] = elt(env, 9); // lientrans
    v0369 = elt(env, 8); // times
    v0368 = elt(env, 1); // lie_a
    v0367 = elt(env, 9); // lientrans
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 13); // aeval
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0367 = (*qfn2(fn))(qenv(fn), stack[0], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0369 = elt(env, 5); // plus
    v0368 = stack[-13];
    v0367 = (LispObject)33; // 2
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-13] = v0367;
    goto v0374;

v0374:
    stack[0] = elt(env, 3); // difference
    v0369 = elt(env, 3); // difference
    v0368 = stack[-14];
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-13];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0375;
    v0367 = elt(env, 1); // lie_a
    v0367 = ncons(v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 17); // clear
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 13); // aeval
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    v0367 = nil;
    { popv(17); return onevalue(v0367); }

v0375:
    v0369 = elt(env, 5); // plus
    v0368 = stack[-13];
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-11] = v0367;
    goto v0376;

v0376:
    stack[0] = elt(env, 3); // difference
    v0367 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-11];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0377;
    v0367 = stack[-13];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-13] = v0367;
    goto v0374;

v0377:
    v0369 = elt(env, 6); // lie_lamb
    v0368 = stack[-13];
    v0367 = stack[-11];
    stack[-10] = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-9] = elt(env, 7); // quotient
    v0367 = (LispObject)17; // 1
    stack[-8] = v0367;
    v0367 = (LispObject)1; // 0
    stack[-7] = v0367;
    goto v0378;

v0378:
    stack[0] = elt(env, 3); // difference
    v0367 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-8];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0379;
    v0367 = stack[-7];
    stack[0] = v0367;
    v0369 = elt(env, 9); // lientrans
    v0368 = (LispObject)17; // 1
    v0367 = stack[-12];
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = list3(stack[-9], stack[0], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0367 = (*qfn2(fn))(qenv(fn), stack[-10], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-11];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-11] = v0367;
    goto v0376;

v0379:
    stack[-6] = elt(env, 5); // plus
    v0367 = (LispObject)17; // 1
    stack[-5] = v0367;
    v0367 = (LispObject)1; // 0
    stack[-4] = v0367;
    goto v0380;

v0380:
    stack[0] = elt(env, 3); // difference
    v0367 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-5];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0381;
    v0367 = stack[-4];
    v0368 = v0367;
    v0367 = stack[-7];
    v0367 = list3(stack[-6], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-7] = v0367;
    v0367 = stack[-8];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-8] = v0367;
    goto v0378;

v0381:
    stack[-3] = elt(env, 5); // plus
    stack[-2] = elt(env, 8); // times
    v0369 = elt(env, 9); // lientrans
    v0368 = stack[-13];
    v0367 = stack[-8];
    stack[-1] = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0369 = elt(env, 9); // lientrans
    v0368 = stack[-11];
    v0367 = stack[-5];
    stack[0] = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0370 = elt(env, 10); // lie_cc
    v0369 = stack[-8];
    v0368 = stack[-5];
    v0367 = stack[-12];
    v0367 = list4(v0370, v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = list4(stack[-2], stack[-1], stack[0], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-4];
    v0367 = list3(stack[-3], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-4] = v0367;
    v0367 = stack[-5];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-5] = v0367;
    goto v0380;

v0373:
    stack[-1] = elt(env, 1); // lie_a
    stack[0] = stack[-2];
    v0369 = elt(env, 5); // plus
    v0368 = stack[-13];
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-1] = list3(stack[-1], stack[0], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[0] = elt(env, 11); // minus
    v0369 = elt(env, 6); // lie_lamb
    v0368 = stack[-13];
    v0367 = stack[-2];
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = list2(stack[0], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0367 = (*qfn2(fn))(qenv(fn), stack[-1], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0369 = elt(env, 1); // lie_a
    v0368 = stack[-2];
    v0367 = stack[-13];
    stack[-1] = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[0] = elt(env, 6); // lie_lamb
    v0369 = elt(env, 5); // plus
    v0368 = stack[-13];
    v0367 = (LispObject)17; // 1
    v0368 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-2];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0367 = (*qfn2(fn))(qenv(fn), stack[-1], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-2];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-2] = v0367;
    goto v0372;

v0066:
    v0369 = elt(env, 5); // plus
    v0368 = stack[-15];
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-11] = v0367;
    goto v0180;

v0180:
    stack[0] = elt(env, 3); // difference
    v0367 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-11];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0192;
    v0367 = stack[-15];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-15] = v0367;
    goto v0101;

v0192:
    v0369 = elt(env, 6); // lie_lamb
    v0368 = stack[-15];
    v0367 = stack[-11];
    stack[-10] = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-9] = elt(env, 7); // quotient
    v0367 = (LispObject)17; // 1
    stack[-8] = v0367;
    v0367 = (LispObject)1; // 0
    stack[-7] = v0367;
    goto v0382;

v0382:
    stack[0] = elt(env, 3); // difference
    v0367 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-8];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0208;
    v0367 = stack[-7];
    stack[0] = v0367;
    v0369 = elt(env, 9); // lientrans
    v0368 = (LispObject)17; // 1
    v0367 = stack[-12];
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = list3(stack[-9], stack[0], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 14); // setk
    v0367 = (*qfn2(fn))(qenv(fn), stack[-10], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-11];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-11] = v0367;
    goto v0180;

v0208:
    stack[-6] = elt(env, 5); // plus
    v0367 = (LispObject)17; // 1
    stack[-5] = v0367;
    v0367 = (LispObject)1; // 0
    stack[-4] = v0367;
    goto v0103;

v0103:
    stack[0] = elt(env, 3); // difference
    v0367 = stack[-14];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-5];
    v0367 = list3(stack[0], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 16); // aminusp!:
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    if (v0367 == nil) goto v0141;
    v0367 = stack[-4];
    v0368 = v0367;
    v0367 = stack[-7];
    v0367 = list3(stack[-6], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-7] = v0367;
    v0367 = stack[-8];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-8] = v0367;
    goto v0382;

v0141:
    stack[-3] = elt(env, 5); // plus
    stack[-2] = elt(env, 8); // times
    v0369 = elt(env, 9); // lientrans
    v0368 = stack[-15];
    v0367 = stack[-8];
    stack[-1] = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0369 = elt(env, 9); // lientrans
    v0368 = stack[-11];
    v0367 = stack[-5];
    stack[0] = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0370 = elt(env, 10); // lie_cc
    v0369 = stack[-8];
    v0368 = stack[-5];
    v0367 = stack[-12];
    v0367 = list4(v0370, v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = list4(stack[-2], stack[-1], stack[0], v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0368 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    v0367 = stack[-4];
    v0367 = list3(stack[-3], v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-4] = v0367;
    v0367 = stack[-5];
    v0369 = elt(env, 5); // plus
    v0368 = v0367;
    v0367 = (LispObject)17; // 1
    v0367 = list3(v0369, v0368, v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    fn = elt(env, 15); // aeval!*
    v0367 = (*qfn1(fn))(qenv(fn), v0367);
    nil = C_nil;
    if (exception_pending()) goto v0371;
    env = stack[-16];
    stack[-5] = v0367;
    goto v0103;
// error exit handlers
v0371:
    popv(17);
    return nil;
}



// Code for subcare

static LispObject CC_subcare(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0198, v0030, v0194;
    LispObject fn;
    LispObject v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subcare");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subcare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0088,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0008;
    stack[-1] = v0088;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0119;

v0119:
    v0198 = stack[0];
    if (v0198 == nil) goto v0028;
    v0030 = stack[-2];
    v0198 = stack[0];
    if (equal(v0030, v0198)) goto v0114;
    v0198 = stack[0];
    if (!consp(v0198)) goto v0133;
    v0198 = stack[0];
    v0030 = qcar(v0198);
    v0198 = elt(env, 2); // subfunc
    v0198 = get(v0030, v0198);
    env = stack[-4];
    goto v0115;

v0115:
    if (v0198 == nil) goto v0033;
    v0030 = stack[-3];
    v0198 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0030, v0198);
    }

v0033:
    v0194 = stack[-2];
    v0030 = stack[-1];
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0030 = CC_subcare(env, 3, v0194, v0030, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    v0198 = stack[-3];
    v0198 = cons(v0030, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    stack[-3] = v0198;
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    stack[0] = v0198;
    goto v0119;

v0133:
    v0198 = qvalue(elt(env, 1)); // t
    goto v0115;

v0114:
    v0030 = stack[-3];
    v0198 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0030, v0198);
    }

v0028:
    v0198 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0198);
    }
// error exit handlers
v0094:
    popv(5);
    return nil;
}



// Code for horner!-rule!-for!-one!-var

static LispObject CC_hornerKruleKforKoneKvar(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0155, v0385, v0025, v0024, v0386, v0193, v0382;
    LispObject fn;
    LispObject v0087, v0009, v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-for-one-var");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    v0087 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for horner-rule-for-one-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0087,v0009,v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0088,v0008,v0009,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    v0385 = v0087;
    v0025 = v0009;
    v0024 = v0008;
    v0386 = v0088;
    v0193 = v0000;
// end of prologue

v0221:
    v0155 = v0193;
    if (!consp(v0155)) goto v0043;
    v0155 = v0193;
    v0155 = qcar(v0155);
    v0155 = (consp(v0155) ? nil : lisp_true);
    goto v0044;

v0044:
    if (v0155 == nil) goto v0134;
    v0155 = qvalue(elt(env, 1)); // t
    goto v0046;

v0046:
    if (v0155 == nil) goto v0160;
    v0155 = v0024;
    v0155 = (LispObject)zerop(v0155);
    v0155 = v0155 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0155 == nil)) { popv(7); return onevalue(v0193); }
    stack[-1] = v0193;
    stack[0] = v0025;
    v0155 = v0024;
    v0155 = Lexpt(nil, v0155, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    fn = elt(env, 2); // !*n2f
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    fn = elt(env, 3); // multf
    v0155 = (*qfn2(fn))(qenv(fn), stack[0], v0155);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    {
        LispObject v0365 = stack[-1];
        popv(7);
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(qenv(fn), v0365, v0155);
    }

v0160:
    v0155 = v0193;
    v0155 = qcar(v0155);
    v0155 = qcar(v0155);
    v0155 = qcdr(v0155);
    stack[-5] = v0155;
    v0155 = v0193;
    stack[-4] = qcdr(v0155);
    stack[-3] = v0386;
    stack[-2] = v0024;
    v0155 = v0024;
    v0155 = (LispObject)zerop(v0155);
    v0155 = v0155 ? lisp_true : nil;
    env = stack[-6];
    if (v0155 == nil) goto v0220;
    v0155 = v0193;
    v0155 = qcar(v0155);
    v0155 = qcdr(v0155);
    v0385 = v0155;
    goto v0091;

v0091:
    v0155 = stack[-5];
    v0193 = stack[-4];
    v0386 = stack[-3];
    v0024 = stack[-2];
    v0025 = v0385;
    v0385 = v0155;
    goto v0221;

v0220:
    v0155 = v0193;
    v0155 = qcar(v0155);
    stack[-1] = qcdr(v0155);
    stack[0] = v0025;
    v0025 = v0024;
    v0155 = stack[-5];
    v0155 = (LispObject)(int32_t)((int32_t)v0385 - (int32_t)v0155 + TAG_FIXNUM);
    v0155 = Lexpt(nil, v0025, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    fn = elt(env, 2); // !*n2f
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    fn = elt(env, 3); // multf
    v0155 = (*qfn2(fn))(qenv(fn), stack[0], v0155);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    fn = elt(env, 4); // addf
    v0155 = (*qfn2(fn))(qenv(fn), stack[-1], v0155);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-6];
    v0385 = v0155;
    goto v0091;

v0134:
    v0155 = v0193;
    v0155 = qcar(v0155);
    v0155 = qcar(v0155);
    v0382 = qcar(v0155);
    v0155 = v0386;
    v0155 = (equal(v0382, v0155) ? lisp_true : nil);
    v0155 = (v0155 == nil ? lisp_true : nil);
    goto v0046;

v0043:
    v0155 = qvalue(elt(env, 1)); // t
    goto v0044;
// error exit handlers
v0023:
    popv(7);
    return nil;
}



// Code for maxfrom1

static LispObject CC_maxfrom1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0038, v0115;
    LispObject fn;
    LispObject v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "maxfrom1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxfrom1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0088,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0008;
    stack[-1] = v0088;
    stack[-2] = v0000;
// end of prologue

v0085:
    v0038 = stack[-2];
    if (v0038 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0038 = stack[-2];
    v0038 = qcar(v0038);
    v0115 = qcar(v0038);
    v0038 = stack[-1];
    fn = elt(env, 1); // nth
    v0115 = (*qfn2(fn))(qenv(fn), v0115, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0038 = stack[0];
    fn = elt(env, 2); // max
    v0038 = (*qfn2(fn))(qenv(fn), v0115, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    stack[0] = v0038;
    v0038 = stack[-2];
    v0038 = qcdr(v0038);
    stack[-2] = v0038;
    goto v0085;
// error exit handlers
v0116:
    popv(4);
    return nil;
}



// Code for mk!+outer!+list

static LispObject CC_mkLouterLlist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0123, v0036;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+outer+list");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0123 = elt(env, 1); // list
    v0036 = ncons(v0123);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0123 = stack[0];
        popv(1);
        return Lappend(nil, v0036, v0123);
// error exit handlers
v0043:
    popv(1);
    return nil;
}



// Code for cl_susicpknowl

static LispObject CC_cl_susicpknowl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0132, v0135;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susicpknowl");
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
    v0132 = v0000;
// end of prologue
    stack[-3] = v0132;
    v0132 = stack[-3];
    if (v0132 == nil) goto v0046;
    v0132 = stack[-3];
    v0132 = qcar(v0132);
    v0135 = v0132;
    v0135 = qcar(v0135);
    v0132 = qcdr(v0132);
    v0132 = cons(v0135, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0132 = ncons(v0132);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    stack[-1] = v0132;
    stack[-2] = v0132;
    goto v0119;

v0119:
    v0132 = stack[-3];
    v0132 = qcdr(v0132);
    stack[-3] = v0132;
    v0132 = stack[-3];
    if (v0132 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0132 = stack[-3];
    v0132 = qcar(v0132);
    v0135 = v0132;
    v0135 = qcar(v0135);
    v0132 = qcdr(v0132);
    v0132 = cons(v0135, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0132 = ncons(v0132);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0132 = Lrplacd(nil, stack[0], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0132 = stack[-1];
    v0132 = qcdr(v0132);
    stack[-1] = v0132;
    goto v0119;

v0046:
    v0132 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0132); }
// error exit handlers
v0096:
    popv(5);
    return nil;
}



// Code for dvfsf_smupdknowl

static LispObject CC_dvfsf_smupdknowl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0117, v0065, v0129, v0122, v0029;
    LispObject fn;
    LispObject v0009, v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_smupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0065 = v0009;
    v0129 = v0008;
    v0122 = v0088;
    v0029 = v0000;
// end of prologue
    v0117 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0117 == nil) goto v0200;
    v0117 = v0029;
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(qenv(fn), 4, v0117, v0122, v0129, v0065);
    }

v0200:
    v0117 = v0029;
    {
        fn = elt(env, 3); // cl_smupdknowl
        return (*qfnn(fn))(qenv(fn), 4, v0117, v0122, v0129, v0065);
    }
}



// Code for symbolsom

static LispObject CC_symbolsom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0024, v0386, v0193;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbolsom");
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
    stack[-1] = nil;
    v0024 = stack[-4];
    v0386 = qcar(v0024);
    v0024 = qvalue(elt(env, 1)); // valid_om!*
    v0024 = Lassoc(nil, v0386, v0024);
    stack[-5] = v0024;
    v0024 = stack[-5];
    if (v0024 == nil) goto v0108;
    v0024 = stack[-5];
    v0024 = qcdr(v0024);
    v0024 = qcar(v0024);
    stack[-5] = v0024;
    goto v0108;

v0108:
    v0024 = stack[-4];
    v0024 = qcar(v0024);
    stack[0] = v0024;
    v0024 = stack[-4];
    v0024 = qcdr(v0024);
    v0024 = qcdr(v0024);
    v0024 = qcar(v0024);
    stack[-3] = v0024;
    v0024 = stack[-4];
    v0024 = Lreverse(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = qcar(v0024);
    stack[-2] = v0024;
    v0386 = stack[0];
    v0024 = elt(env, 2); // diff
    if (v0386 == v0024) goto v0133;
    v0024 = stack[-4];
    v0024 = qcdr(v0024);
    v0024 = qcdr(v0024);
    v0024 = qcdr(v0024);
    v0024 = qcar(v0024);
    stack[-1] = v0024;
    goto v0133;

v0133:
    v0024 = stack[-1];
    if (v0024 == nil) goto v0045;
    v0024 = stack[-1];
    v0386 = qcar(v0024);
    v0024 = elt(env, 3); // condition
    if (!(v0386 == v0024)) goto v0045;
    v0386 = elt(env, 4); // "<condition> tag not supported in MathML"
    v0024 = (LispObject)17; // 1
    fn = elt(env, 15); // errorml
    v0024 = (*qfn2(fn))(qenv(fn), v0386, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    goto v0045;

v0045:
    v0024 = elt(env, 5); // "<OMA>"
    fn = elt(env, 16); // printout
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = qvalue(elt(env, 6)); // t
    fn = elt(env, 17); // indent!*
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = stack[-1];
    if (v0024 == nil) goto v0159;
    v0386 = stack[0];
    v0024 = elt(env, 7); // int
    v0024 = (v0386 == v0024 ? lisp_true : nil);
    goto v0387;

v0387:
    if (v0024 == nil) goto v0197;
    v0024 = elt(env, 9); // defint
    stack[0] = v0024;
    goto v0197;

v0197:
    v0024 = elt(env, 10); // "<OMS cd="""
    fn = elt(env, 16); // printout
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = stack[-5];
    v0024 = Lprinc(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = elt(env, 11); // """ name="""
    v0024 = Lprinc(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = stack[0];
    v0024 = Lprinc(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = elt(env, 12); // """/>"
    v0024 = Lprinc(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = stack[-1];
    if (v0024 == nil) goto v0027;
    v0024 = stack[-1];
    fn = elt(env, 18); // objectom
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    goto v0027;

v0027:
    stack[-1] = elt(env, 13); // lambda
    stack[0] = qvalue(elt(env, 8)); // nil
    v0193 = stack[-3];
    v0386 = stack[-2];
    v0024 = qvalue(elt(env, 8)); // nil
    v0024 = list2star(v0193, v0386, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = list2star(stack[-1], stack[0], v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    fn = elt(env, 19); // lambdaom
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 17); // indent!*
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-6];
    v0024 = elt(env, 14); // "</OMA>"
    fn = elt(env, 16); // printout
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0024 = nil;
    { popv(7); return onevalue(v0024); }

v0159:
    v0024 = qvalue(elt(env, 8)); // nil
    goto v0387;
// error exit handlers
v0022:
    popv(7);
    return nil;
}



// Code for simpwedge

static LispObject CC_simpwedge(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpwedge");
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
    v0086 = v0000;
// end of prologue
    fn = elt(env, 1); // partitwedge
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(qenv(fn), v0086);
    }
// error exit handlers
v0085:
    popv(1);
    return nil;
}



// Code for r2findindex1

static LispObject CC_r2findindex1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0131, v0109, v0037;
    LispObject fn;
    LispObject v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "r2findindex1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for r2findindex1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0088,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0109 = v0008;
    stack[0] = v0088;
    stack[-1] = v0000;
// end of prologue

v0085:
    v0131 = stack[0];
    if (v0131 == nil) goto v0069;
    v0037 = stack[-1];
    v0131 = stack[0];
    v0131 = qcar(v0131);
    if (equal(v0037, v0131)) { popv(3); return onevalue(v0109); }
    v0131 = stack[0];
    v0131 = qcdr(v0131);
    stack[0] = v0131;
    v0131 = v0109;
    v0131 = add1(v0131);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0109 = v0131;
    goto v0085;

v0069:
    v0131 = elt(env, 1); // "index not found"
    {
        popv(3);
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(qenv(fn), v0131);
    }
// error exit handlers
v0133:
    popv(3);
    return nil;
}



// Code for evalgreaterp

static LispObject CC_evalgreaterp(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0210, v0163, v0066;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalgreaterp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0163 = v0088;
    v0210 = v0000;
// end of prologue
    v0066 = elt(env, 1); // difference
    v0210 = list3(v0066, v0163, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-1];
    fn = elt(env, 5); // simp!*
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-1];
    stack[0] = v0210;
    v0210 = stack[0];
    v0210 = qcdr(v0210);
    if (!consp(v0210)) goto v0200;
    v0210 = qvalue(elt(env, 2)); // t
    goto v0120;

v0120:
    if (v0210 == nil) goto v0182;
    v0210 = stack[0];
    v0210 = qcar(v0210);
    fn = elt(env, 6); // minusf
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-1];
    if (v0210 == nil) goto v0110;
    v0210 = stack[0];
    fn = elt(env, 7); // negsq
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-1];
    goto v0101;

v0101:
    fn = elt(env, 8); // mk!*sq
    v0163 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-1];
    v0210 = elt(env, 3); // "number"
    {
        popv(2);
        fn = elt(env, 9); // typerr
        return (*qfn2(fn))(qenv(fn), v0163, v0210);
    }

v0110:
    v0210 = stack[0];
    goto v0101;

v0182:
    v0210 = stack[0];
    v0210 = qcar(v0210);
    if (v0210 == nil) goto v0032;
    v0210 = stack[0];
    v0210 = qcar(v0210);
    {
        popv(2);
        fn = elt(env, 10); // !:minusp
        return (*qfn1(fn))(qenv(fn), v0210);
    }

v0032:
    v0210 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0210); }

v0200:
    v0210 = stack[0];
    v0210 = qcar(v0210);
    if (!consp(v0210)) goto v0131;
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0210 = qcar(v0210);
    v0210 = (consp(v0210) ? nil : lisp_true);
    goto v0195;

v0195:
    v0210 = (v0210 == nil ? lisp_true : nil);
    goto v0120;

v0131:
    v0210 = qvalue(elt(env, 2)); // t
    goto v0195;
// error exit handlers
v0197:
    popv(2);
    return nil;
}



// Code for mo!=zero

static LispObject CC_moMzero(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0134, v0118, v0195;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=zero");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0118 = v0000;
// end of prologue

v0221:
    v0134 = v0118;
    if (v0134 == nil) goto v0087;
    v0134 = v0118;
    v0195 = qcar(v0134);
    v0134 = (LispObject)1; // 0
    if (v0195 == v0134) goto v0124;
    v0134 = qvalue(elt(env, 2)); // nil
    return onevalue(v0134);

v0124:
    v0134 = v0118;
    v0134 = qcdr(v0134);
    v0118 = v0134;
    goto v0221;

v0087:
    v0134 = qvalue(elt(env, 1)); // t
    return onevalue(v0134);
}



// Code for rl_simpl

static LispObject CC_rl_simpl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0121, v0040, v0039;
    LispObject fn;
    LispObject v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_simpl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0088,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0121 = v0008;
    v0040 = v0088;
    v0039 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_simpl!*
    v0121 = list3(v0039, v0040, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-1];
    {
        LispObject v0200 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0200, v0121);
    }
// error exit handlers
v0199:
    popv(2);
    return nil;
}



// Code for vdp_setsugar

static LispObject CC_vdp_setsugar(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0121, v0040, v0039;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_setsugar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0121 = v0088;
    v0039 = v0000;
// end of prologue
    v0040 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v0040 == nil) return onevalue(v0039);
    v0040 = elt(env, 2); // sugar
    {
        fn = elt(env, 3); // vdp_putprop
        return (*qfnn(fn))(qenv(fn), 3, v0039, v0040, v0121);
    }
}



// Code for setrd

static LispObject CC_setrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0114, v0199;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setrd");
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
    v0114 = elt(env, 1); // (t y p e != s e t !$)
    qvalue(elt(env, 2)) = v0114; // atts
    stack[0] = elt(env, 3); // list
    fn = elt(env, 4); // stats_getargs
    v0114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-1];
    v0114 = cons(stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-1];
    v0199 = v0114;
    v0114 = v0199;
    stack[0] = qcar(v0114);
    v0114 = v0199;
    v0114 = qcdr(v0114);
    fn = elt(env, 5); // norepeat
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    {
        LispObject v0118 = stack[0];
        popv(2);
        return cons(v0118, v0114);
    }
// error exit handlers
v0134:
    popv(2);
    return nil;
}



// Code for i2ps

static LispObject CC_i2ps(LispObject env,
                         LispObject v0000)
{
    LispObject v0009;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for i2ps");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0009 = v0000;
// end of prologue
    return onevalue(v0009);
}



// Code for xnsiz

static LispObject CC_xnsiz(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0124, v0123;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xnsiz");
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
    v0124 = v0000;
// end of prologue
    fn = elt(env, 2); // xnsiz1
    v0123 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[0];
    v0124 = qvalue(elt(env, 1)); // !!log2of10
    v0124 = quot2(v0123, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // ceiling
        return (*qfn1(fn))(qenv(fn), v0124);
    }
// error exit handlers
v0036:
    popv(1);
    return nil;
}



// Code for !:!:quotient

static LispObject CC_TTquotient(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0120, v0121;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ::quotient");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0121 = v0088;
    v0120 = v0000;
// end of prologue
    stack[0] = v0120;
    v0120 = v0121;
    v0120 = integerp(v0120);
    if (v0120 == nil) goto v0102;
    v0120 = v0121;
    fn = elt(env, 1); // i2rd!*
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    goto v0119;

v0119:
    {
        LispObject v0114 = stack[0];
        popv(2);
        fn = elt(env, 2); // !:quotient
        return (*qfn2(fn))(qenv(fn), v0114, v0120);
    }

v0102:
    v0120 = v0121;
    goto v0119;
// error exit handlers
v0039:
    popv(2);
    return nil;
}



// Code for collectphysops_reversed

static LispObject CC_collectphysops_reversed(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0033, v0137;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for collectphysops_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0088;
    stack[-1] = v0000;
// end of prologue
    v0033 = stack[-1];
    if (!consp(v0033)) goto v0119;
    v0033 = stack[-1];
    fn = elt(env, 2); // physopp
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-3];
    if (v0033 == nil) goto v0063;
    stack[-2] = stack[-1];
    v0033 = stack[-1];
    fn = elt(env, 3); // collectindices
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-3];
    fn = elt(env, 4); // removeindices
    v0137 = (*qfn2(fn))(qenv(fn), stack[-2], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    v0033 = stack[0];
    popv(4);
    return cons(v0137, v0033);

v0063:
    v0033 = stack[-1];
    if (!consp(v0033)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0033 = stack[-1];
    v0137 = qcar(v0033);
    v0033 = stack[0];
    v0033 = CC_collectphysops_reversed(env, v0137, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-3];
    stack[0] = v0033;
    v0033 = stack[-1];
    v0033 = qcdr(v0033);
    stack[-1] = v0033;
    goto v0063;

v0119:
    v0033 = stack[-1];
    fn = elt(env, 2); // physopp
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    if (v0033 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0137 = stack[-1];
    v0033 = stack[0];
    popv(4);
    return cons(v0137, v0033);
// error exit handlers
v0181:
    popv(4);
    return nil;
}



// Code for deletez1

static LispObject CC_deletez1(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0031, v0063, v0062, v0101;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deletez1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0088;
    stack[-1] = v0000;
// end of prologue
    v0101 = nil;
    goto v0085;

v0085:
    v0031 = stack[-1];
    if (v0031 == nil) goto v0069;
    v0062 = (LispObject)1; // 0
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    v0063 = qcar(v0031);
    v0031 = stack[0];
    v0031 = Lassoc(nil, v0063, v0031);
    v0031 = qcdr(v0031);
    if (v0062 == v0031) goto v0036;
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    v0063 = v0101;
    v0031 = cons(v0031, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-2];
    v0101 = v0031;
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    goto v0085;

v0036:
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    goto v0085;

v0069:
    v0031 = v0101;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0031);
    }
// error exit handlers
v0099:
    popv(3);
    return nil;
}



// Code for groeb!=crita

static LispObject CC_groebMcrita(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028, v0046;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=crita");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0028 = v0000;
// end of prologue
    v0046 = v0028;
    v0028 = elt(env, 1); // groeb!=testa
    {
        fn = elt(env, 2); // listminimize
        return (*qfn2(fn))(qenv(fn), v0046, v0028);
    }
}



// Code for ratlessp

static LispObject CC_ratlessp(LispObject env,
                         LispObject v0000, LispObject v0088)
{
    LispObject nil = C_nil;
    LispObject v0108, v0107;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratlessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0088,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0088);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0108 = v0088;
    v0107 = v0000;
// end of prologue
    fn = elt(env, 1); // ratdif
    v0108 = (*qfn2(fn))(qenv(fn), v0107, v0108);
    errexit();
    v0107 = qcar(v0108);
    v0108 = (LispObject)1; // 0
        return Llessp(nil, v0107, v0108);
}



// Code for drnconv

static LispObject CC_drnconv(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0110, v0132, v0135;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for drnconv");
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
    v0132 = v0000;
// end of prologue
    v0110 = v0132;
    if (v0110 == nil) goto v0074;
    v0110 = v0132;
    v0110 = (is_number(v0110) ? lisp_true : nil);
    if (!(v0110 == nil)) goto v0119;
    v0135 = v0132;
    v0110 = qvalue(elt(env, 2)); // dmd!*
    v0110 = Leqcar(nil, v0135, v0110);
    env = stack[0];
    goto v0119;

v0119:
    if (!(v0110 == nil)) { popv(1); return onevalue(v0132); }
    v0110 = v0132;
    v0135 = qcar(v0110);
    v0110 = qvalue(elt(env, 2)); // dmd!*
    v0110 = get(v0135, v0110);
    v0135 = v0110;
    v0110 = v0135;
    if (v0110 == nil) { popv(1); return onevalue(v0132); }
    v0110 = v0135;
    if (!(!consp(v0110))) { popv(1); return onevalue(v0132); }
    v0110 = v0135;
        popv(1);
        return Lapply1(nil, v0110, v0132);

v0074:
    v0110 = qvalue(elt(env, 1)); // t
    goto v0119;
}



// Code for valuecoefft

static LispObject CC_valuecoefft(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0064, v0031, v0063, v0062, v0101;
    LispObject fn;
    LispObject v0008, v0088, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "valuecoefft");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0088 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for valuecoefft");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0063 = v0008;
    v0062 = v0088;
    v0101 = v0000;
// end of prologue

v0085:
    v0064 = v0063;
    if (v0064 == nil) goto v0069;
    v0031 = v0101;
    v0064 = v0063;
    v0064 = qcar(v0064);
    if (v0031 == v0064) goto v0134;
    v0064 = v0062;
    v0064 = qcdr(v0064);
    v0062 = v0064;
    v0064 = v0063;
    v0064 = qcdr(v0064);
    v0063 = v0064;
    goto v0085;

v0134:
    v0064 = v0062;
    v0031 = qcar(v0064);
    v0064 = (LispObject)1; // 0
    if (v0031 == v0064) goto v0199;
    v0064 = v0062;
    v0064 = qcar(v0064);
    return onevalue(v0064);

v0199:
    v0064 = qvalue(elt(env, 2)); // nil
    return onevalue(v0064);

v0069:
    v0064 = elt(env, 1); // "Valuecoefft - no value"
    {
        fn = elt(env, 3); // interr
        return (*qfn1(fn))(qenv(fn), v0064);
    }
}



// Code for my!+nullsq!+p

static LispObject CC_myLnullsqLp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0046;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for my+nullsq+p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0046 = v0000;
// end of prologue
    v0046 = qcar(v0046);
    if (v0046 == nil) goto v0085;
    v0046 = nil;
    return onevalue(v0046);

v0085:
    v0046 = qvalue(elt(env, 1)); // t
    return onevalue(v0046);
}



// Code for pasf_uprap

static LispObject CC_pasf_uprap(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028, v0046;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_uprap");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0028 = v0000;
// end of prologue
    v0046 = v0028;
    v0028 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // pasf_uprap1
        return (*qfn2(fn))(qenv(fn), v0046, v0028);
    }
}



setup_type const u28_setup[] =
{
    {"pasf_cein",               CC_pasf_cein,   too_many_1,    wrong_no_1},
    {"ofsf_sippsignchkf",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sippsignchkf},
    {"ithlistelem",             too_few_2,      CC_ithlistelem,wrong_no_2},
    {"ps:value",                CC_psTvalue,    too_many_1,    wrong_no_1},
    {"maxl",                    CC_maxl,        too_many_1,    wrong_no_1},
    {"getrlist",                CC_getrlist,    too_many_1,    wrong_no_1},
    {"string2bytelist",         CC_string2bytelist,too_many_1, wrong_no_1},
    {"calc_coeff",              too_few_2,      CC_calc_coeff, wrong_no_2},
    {"no-side-effectp",         CC_noKsideKeffectp,too_many_1, wrong_no_1},
    {"listsub",                 too_few_2,      CC_listsub,    wrong_no_2},
    {"dp_neworder",             CC_dp_neworder, too_many_1,    wrong_no_1},
    {"difbf",                   too_few_2,      CC_difbf,      wrong_no_2},
    {"pasf_zcong",              CC_pasf_zcong,  too_many_1,    wrong_no_1},
    {"sfto_mvarx",              CC_sfto_mvarx,  too_many_1,    wrong_no_1},
    {"fnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnrd},
    {"sparpri",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_sparpri},
    {"evequal",                 too_few_2,      CC_evequal,    wrong_no_2},
    {"vdpilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpilcomb1},
    {"gfplus",                  too_few_2,      CC_gfplus,     wrong_no_2},
    {"sublap",                  too_few_2,      CC_sublap,     wrong_no_2},
    {"simppartdf",              CC_simppartdf,  too_many_1,    wrong_no_1},
    {"getphystypeall",          CC_getphystypeall,too_many_1,  wrong_no_1},
    {"realvaluedp",             CC_realvaluedp, too_many_1,    wrong_no_1},
    {"assert_kernelp",          CC_assert_kernelp,too_many_1,  wrong_no_1},
    {"remchkf1",                too_few_2,      CC_remchkf1,   wrong_no_2},
    {"gvar1",                   too_few_2,      CC_gvar1,      wrong_no_2},
    {"pasf_anegrel",            CC_pasf_anegrel,too_many_1,    wrong_no_1},
    {"ciml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_ciml},
    {"mconv1",                  CC_mconv1,      too_many_1,    wrong_no_1},
    {"physoptimes",             CC_physoptimes, too_many_1,    wrong_no_1},
    {"prop-simp1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_propKsimp1},
    {"liennewstruc",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_liennewstruc},
    {"subcare",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subcare},
    {"horner-rule-for-one-var", wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"maxfrom1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_maxfrom1},
    {"mk+outer+list",           CC_mkLouterLlist,too_many_1,   wrong_no_1},
    {"cl_susicpknowl",          CC_cl_susicpknowl,too_many_1,  wrong_no_1},
    {"dvfsf_smupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_smupdknowl},
    {"symbolsom",               CC_symbolsom,   too_many_1,    wrong_no_1},
    {"simpwedge",               CC_simpwedge,   too_many_1,    wrong_no_1},
    {"r2findindex1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2findindex1},
    {"evalgreaterp",            too_few_2,      CC_evalgreaterp,wrong_no_2},
    {"mo=zero",                 CC_moMzero,     too_many_1,    wrong_no_1},
    {"rl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_simpl},
    {"vdp_setsugar",            too_few_2,      CC_vdp_setsugar,wrong_no_2},
    {"setrd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrd},
    {"i2ps",                    CC_i2ps,        too_many_1,    wrong_no_1},
    {"xnsiz",                   CC_xnsiz,       too_many_1,    wrong_no_1},
    {"::quotient",              too_few_2,      CC_TTquotient, wrong_no_2},
    {"collectphysops_reversed", too_few_2,      CC_collectphysops_reversed,wrong_no_2},
    {"deletez1",                too_few_2,      CC_deletez1,   wrong_no_2},
    {"groeb=crita",             CC_groebMcrita, too_many_1,    wrong_no_1},
    {"ratlessp",                too_few_2,      CC_ratlessp,   wrong_no_2},
    {"drnconv",                 CC_drnconv,     too_many_1,    wrong_no_1},
    {"valuecoefft",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_valuecoefft},
    {"my+nullsq+p",             CC_myLnullsqLp, too_many_1,    wrong_no_1},
    {"pasf_uprap",              CC_pasf_uprap,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u28", (two_args *)"21752 4926415 58509", 0}
};

// end of generated code
