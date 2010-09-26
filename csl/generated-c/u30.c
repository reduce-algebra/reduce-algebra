
/* $destdir\u30.c        Machine generated C code */

/* Signature: 00000000 26-Sep-2010 */

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
#if !defined UNDER_CE && ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
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
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((uint32_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)
#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
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
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif 
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif 
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
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
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
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
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
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;   
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;   
    Lisp_Object env;     
    intptr_t function1;  
    intptr_t function2;  
    intptr_t functionn;  
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;
#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;
#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_ERROR      0x100       
#define UNWIND_UNWIND     0x200       
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define HEADLINE_FLAG 0x08
#define MESSAGES_FLAG 0x10
#define ALWAYS_NOISY  0x20
#define verbos_flag (miscflags & GC_MSG_BITS)
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_no_longer_used       34      
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
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
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
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
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
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
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
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
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow");
#else
#define if_check_stack
#endif
extern int32_t software_ticks, countdown;
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol;
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
#define procstack             BASE[156]
#define procmem               BASE[157]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;
extern int boffop;
extern void packbyte(int c);
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern CSLbool always_noisy;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
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
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
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
extern CSLbool open_output(char *s, int len);
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
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
#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32_t);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 0
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
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
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
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
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for testord */

static Lisp_Object CC_testord(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testord");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v6:
    v4 = stack[-1];
    if (v4 == nil) goto v7;
    v4 = stack[-1];
    v5 = qcar(v4);
    v4 = stack[0];
    v4 = qcar(v4);
    v4 = (Lisp_Object)lesseq2(v5, v4);
    nil = C_nil;
    if (exception_pending()) goto v8;
    v4 = v4 ? lisp_true : nil;
    env = stack[-2];
    if (v4 == nil) goto v9;
    v4 = stack[-1];
    v4 = qcdr(v4);
    stack[-1] = v4;
    v4 = stack[0];
    v4 = qcdr(v4);
    stack[0] = v4;
    goto v6;

v9:
    v4 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v4); }

v7:
    v4 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v4); }
/* error exit handlers */
v8:
    popv(3);
    return nil;
}



/* Code for mk!+resimp!+mat */

static Lisp_Object CC_mkLresimpLmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+resimp+mat");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v26 = v0;
/* end of prologue */
    stack[-7] = v26;
    v26 = stack[-7];
    if (v26 == nil) goto v27;
    v26 = stack[-7];
    v26 = qcar(v26);
    stack[-3] = v26;
    v26 = stack[-3];
    if (v26 == nil) goto v28;
    v26 = stack[-3];
    v26 = qcar(v26);
    fn = elt(env, 2); /* resimp */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    stack[-1] = v26;
    stack[-2] = v26;
    goto v30;

v30:
    v26 = stack[-3];
    v26 = qcdr(v26);
    stack[-3] = v26;
    v26 = stack[-3];
    if (v26 == nil) goto v31;
    stack[0] = stack[-1];
    v26 = stack[-3];
    v26 = qcar(v26);
    fn = elt(env, 2); /* resimp */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = Lrplacd(nil, stack[0], v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = stack[-1];
    v26 = qcdr(v26);
    stack[-1] = v26;
    goto v30;

v31:
    v26 = stack[-2];
    goto v9;

v9:
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    stack[-5] = v26;
    stack[-6] = v26;
    goto v32;

v32:
    v26 = stack[-7];
    v26 = qcdr(v26);
    stack[-7] = v26;
    v26 = stack[-7];
    if (v26 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    stack[-4] = stack[-5];
    v26 = stack[-7];
    v26 = qcar(v26);
    stack[-3] = v26;
    v26 = stack[-3];
    if (v26 == nil) goto v33;
    v26 = stack[-3];
    v26 = qcar(v26);
    fn = elt(env, 2); /* resimp */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    stack[-1] = v26;
    stack[-2] = v26;
    goto v34;

v34:
    v26 = stack[-3];
    v26 = qcdr(v26);
    stack[-3] = v26;
    v26 = stack[-3];
    if (v26 == nil) goto v35;
    stack[0] = stack[-1];
    v26 = stack[-3];
    v26 = qcar(v26);
    fn = elt(env, 2); /* resimp */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = Lrplacd(nil, stack[0], v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = stack[-1];
    v26 = qcdr(v26);
    stack[-1] = v26;
    goto v34;

v35:
    v26 = stack[-2];
    goto v36;

v36:
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = Lrplacd(nil, stack[-4], v26);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    v26 = stack[-5];
    v26 = qcdr(v26);
    stack[-5] = v26;
    goto v32;

v33:
    v26 = qvalue(elt(env, 1)); /* nil */
    goto v36;

v28:
    v26 = qvalue(elt(env, 1)); /* nil */
    goto v9;

v27:
    v26 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v26); }
/* error exit handlers */
v29:
    popv(9);
    return nil;
}



/* Code for aex_0 */

static Lisp_Object MS_CDECL CC_aex_0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "aex_0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_0");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 1); /* ratpoly_0 */
    v37 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* aex_fromrp */
        return (*qfn1(fn))(qenv(fn), v37);
    }
/* error exit handlers */
v38:
    popv(1);
    return nil;
}



/* Code for bvarrd */

static Lisp_Object MS_CDECL CC_bvarrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "bvarrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bvarrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    fn = elt(env, 8); /* lex */
    v48 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v49 = qvalue(elt(env, 1)); /* char */
    v48 = elt(env, 2); /* (d e g r e e) */
    if (!(equal(v49, v48))) goto v18;
    v49 = elt(env, 3); /* "<bvar>" */
    v48 = (Lisp_Object)241; /* 15 */
    fn = elt(env, 9); /* errorml */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    goto v18;

v18:
    fn = elt(env, 10); /* mathml2 */
    v48 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    stack[-1] = v48;
    fn = elt(env, 8); /* lex */
    v48 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v49 = qvalue(elt(env, 1)); /* char */
    v48 = elt(env, 2); /* (d e g r e e) */
    if (equal(v49, v48)) goto v30;
    v48 = (Lisp_Object)17; /* 1 */
    stack[0] = v48;
    goto v51;

v51:
    v49 = qvalue(elt(env, 1)); /* char */
    v48 = elt(env, 6); /* (!/ b v a r) */
    if (equal(v49, v48)) goto v52;
    v49 = elt(env, 7); /* "</bvar>" */
    v48 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* errorml */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v48 = nil;
    { popv(3); return onevalue(v48); }

v52:
    v49 = stack[-1];
    v48 = stack[0];
    popv(3);
    return list2(v49, v48);

v30:
    fn = elt(env, 11); /* mathml */
    v48 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    stack[0] = v48;
    fn = elt(env, 8); /* lex */
    v48 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v49 = qvalue(elt(env, 1)); /* char */
    v48 = elt(env, 4); /* (!/ d e g r e e) */
    if (equal(v49, v48)) goto v53;
    v49 = elt(env, 5); /* "</degree>" */
    v48 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 12); /* error */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    goto v53;

v53:
    fn = elt(env, 8); /* lex */
    v48 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    goto v51;
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for diffp */

static Lisp_Object CC_diffp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v224, v225, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-1] = nil;
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[-6] = v223;
    v223 = stack[-5];
    v223 = qcar(v223);
    stack[-5] = v223;
    v224 = stack[-6];
    v223 = (Lisp_Object)17; /* 1 */
    v223 = (Lisp_Object)greaterp2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v223 = v223 ? lisp_true : nil;
    env = stack[-7];
    if (v223 == nil) goto v228;
    v223 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v223 == nil) goto v228;
    v223 = stack[-5];
    fn = elt(env, 21); /* noncomp1 */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    if (v223 == nil) goto v228;
    v224 = stack[-5];
    v223 = stack[-4];
    v223 = list2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 22); /* simpdf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[0] = stack[-5];
    v223 = stack[-6];
    v223 = sub1(v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = list2(stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 23); /* simpexpt */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v225 = stack[-5];
    v224 = (Lisp_Object)17; /* 1 */
    v223 = (Lisp_Object)17; /* 1 */
    v223 = acons(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v224 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-2] = stack[-5];
    v223 = stack[-6];
    v223 = sub1(v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v224 = cons(stack[-2], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-4];
    v223 = CC_diffp(env, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    v223 = (*qfn2(fn))(qenv(fn), stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    {
        Lisp_Object v229 = stack[-1];
        popv(8);
        fn = elt(env, 25); /* addsq */
        return (*qfn2(fn))(qenv(fn), v229, v223);
    }

v228:
    v224 = stack[-5];
    v223 = stack[-4];
    if (!(v224 == v223)) goto v230;
    v224 = (Lisp_Object)17; /* 1 */
    v223 = (Lisp_Object)17; /* 1 */
    v223 = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    if (!(v223 == nil)) goto v231;

v230:
    v223 = stack[-5];
    if (!consp(v223)) goto v232;
    v223 = stack[-5];
    v223 = qcar(v223);
    if (!consp(v223)) goto v233;
    v224 = stack[-5];
    v223 = stack[-4];
    fn = elt(env, 26); /* difff */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    if (!(v223 == nil)) goto v231;

v233:
    v223 = stack[-5];
    v224 = qcar(v223);
    v223 = elt(env, 2); /* !*sq */
    if (!(v224 == v223)) goto v234;
    v223 = stack[-5];
    v223 = qcdr(v223);
    v224 = qcar(v223);
    v223 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    if (!(v223 == nil)) goto v231;

v234:
    v223 = stack[-5];
    v224 = qcar(v223);
    v223 = elt(env, 3); /* dfform */
    v223 = get(v224, v223);
    env = stack[-7];
    stack[-3] = v223;
    if (v223 == nil) goto v235;
    v226 = stack[-3];
    v225 = stack[-5];
    v224 = stack[-4];
    v223 = stack[-6];
        popv(8);
        return Lapply3(nil, 4, v226, v225, v224, v223);

v235:
    v223 = stack[-5];
    stack[0] = qcar(v223);
    v223 = stack[-5];
    fn = elt(env, 28); /* dfn_prop */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = get(stack[0], v223);
    env = stack[-7];
    stack[-3] = v223;
    if (v223 == nil) goto v236;
    v223 = stack[-3];
    stack[-2] = v223;
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[0] = v223;
    goto v237;

v237:
    v223 = stack[0];
    v223 = qcar(v223);
    fn = elt(env, 29); /* simp */
    v224 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v224 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-1];
    v223 = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    v223 = stack[-1];
    v223 = qcar(v223);
    v223 = qcar(v223);
    if (v223 == nil) goto v238;
    v223 = stack[-2];
    v223 = qcar(v223);
    if (!(v223 == nil)) goto v238;

v239:
    v223 = stack[-5];
    v224 = qcar(v223);
    v223 = elt(env, 15); /* df */
    if (v224 == v223) goto v240;
    v225 = elt(env, 15); /* df */
    v224 = stack[-5];
    v223 = stack[-4];
    v223 = list3(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v241;

v241:
    v223 = stack[-1];
    fn = elt(env, 30); /* opmtch */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-3] = v223;
    if (v223 == nil) goto v242;
    v223 = stack[-3];
    fn = elt(env, 29); /* simp */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v231;

v231:
    v224 = stack[-5];
    v223 = qvalue(elt(env, 6)); /* wtl!* */
    v223 = Latsoc(nil, v224, v223);
    stack[-3] = v223;
    if (v223 == nil) goto v243;
    stack[0] = elt(env, 7); /* k!* */
    v223 = stack[-3];
    v223 = qcdr(v223);
    v224 = negate(v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = (Lisp_Object)17; /* 1 */
    v223 = acons(stack[0], v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v224 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = (Lisp_Object)17; /* 1 */
    v224 = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-1];
    fn = elt(env, 24); /* multsq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v243;

v243:
    v223 = stack[-6];
    v223 = sub1(v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[0] = v223;
    v224 = stack[-6];
    v223 = (Lisp_Object)17; /* 1 */
    if (v224 == v223) goto v244;
    v224 = qvalue(elt(env, 8)); /* dmode!* */
    v223 = elt(env, 9); /* convert */
    v223 = Lflagp(nil, v224, v223);
    env = stack[-7];
    if (v223 == nil) goto v245;
    v224 = qvalue(elt(env, 8)); /* dmode!* */
    v223 = elt(env, 10); /* i2d */
    v224 = get(v224, v223);
    env = stack[-7];
    v223 = stack[-6];
    v223 = Lapply1(nil, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 31); /* int!-equiv!-chk */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-6] = v223;
    if (!(v223 == nil)) goto v245;
    v224 = qvalue(elt(env, 4)); /* nil */
    v223 = (Lisp_Object)17; /* 1 */
    v223 = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    goto v246;

v246:
    {
        popv(8);
        fn = elt(env, 32); /* rationalizesq */
        return (*qfn1(fn))(qenv(fn), v223);
    }

v245:
    v225 = stack[-5];
    v224 = stack[0];
    v223 = stack[-6];
    v223 = acons(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v224 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = (Lisp_Object)17; /* 1 */
    v224 = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-1];
    fn = elt(env, 24); /* multsq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    goto v246;

v244:
    v223 = stack[-1];
    goto v246;

v242:
    v224 = stack[-5];
    v223 = stack[-4];
    fn = elt(env, 33); /* depends */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    if (!(v223 == nil)) goto v247;
    v223 = qvalue(elt(env, 12)); /* !*depend */
    if (!(v223 == nil)) goto v247;
    v224 = qvalue(elt(env, 4)); /* nil */
    v223 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v224, v223);

v247:
    v224 = stack[-1];
    v223 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 34); /* mksq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v231;

v240:
    v223 = stack[-5];
    v223 = qcdr(v223);
    v224 = qcar(v223);
    v223 = stack[-4];
    if (!(v224 == v223)) goto v248;
    v223 = qvalue(elt(env, 16)); /* !*commutedf */
    if (v223 == nil) goto v249;
    v223 = qvalue(elt(env, 12)); /* !*depend */
    if (!(v223 == nil)) goto v249;
    v224 = qvalue(elt(env, 4)); /* nil */
    v223 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v224, v223);

v249:
    v223 = qvalue(elt(env, 17)); /* !*simpnoncomdf */
    if (v223 == nil) goto v250;
    v224 = stack[-4];
    v223 = qvalue(elt(env, 14)); /* depl!* */
    v223 = Latsoc(nil, v224, v223);
    stack[-1] = v223;
    if (v223 == nil) goto v250;
    v223 = stack[-1];
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    if (!(v223 == nil)) goto v250;
    v223 = stack[-5];
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    v223 = qcar(v223);
    stack[-3] = v223;
    v225 = elt(env, 15); /* df */
    v224 = stack[-5];
    v223 = stack[-3];
    v223 = list3(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v225 = elt(env, 15); /* df */
    v224 = stack[-4];
    v223 = stack[-3];
    v223 = list3(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 35); /* invsq */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    v223 = (*qfn2(fn))(qenv(fn), stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v231;

v250:
    v223 = stack[-5];
    v223 = qcdr(v223);
    v224 = qcar(v223);
    v223 = elt(env, 18); /* int */
    if (!consp(v224)) goto v248;
    v224 = qcar(v224);
    if (!(v224 == v223)) goto v248;
    v223 = stack[-5];
    v223 = qcdr(v223);
    v223 = qcar(v223);
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    v224 = qcar(v223);
    v223 = stack[-4];
    if (v224 == v223) goto v251;
    v223 = qvalue(elt(env, 19)); /* !*allowdfint */
    if (v223 == nil) goto v248;
    v223 = stack[-5];
    v223 = qcdr(v223);
    v223 = qcar(v223);
    v223 = qcdr(v223);
    v223 = qcar(v223);
    fn = elt(env, 36); /* simp!* */
    v224 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    fn = elt(env, 37); /* not_df_p */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    if (v223 == nil) goto v248;
    stack[-2] = elt(env, 15); /* df */
    stack[0] = elt(env, 18); /* int */
    v223 = stack[-1];
    fn = elt(env, 38); /* mk!*sq */
    v224 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-5];
    v223 = qcdr(v223);
    v223 = qcar(v223);
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    v223 = qcar(v223);
    v223 = list3(stack[0], v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 39); /* reval */
    v224 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-5];
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    v223 = list2star(stack[-2], v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v241;

v248:
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[0] = qcar(v223);
    v224 = stack[-5];
    v223 = stack[-4];
    fn = elt(env, 40); /* merge!-ind!-vars */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v225 = cons(stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v225;
    v224 = elt(env, 15); /* df */
    v223 = elt(env, 20); /* kvalue */
    v223 = get(v224, v223);
    env = stack[-7];
    fn = elt(env, 41); /* find_sub_df */
    v223 = (*qfn2(fn))(qenv(fn), v225, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-3] = v223;
    if (v223 == nil) goto v252;
    v223 = stack[-3];
    v223 = qcar(v223);
    fn = elt(env, 29); /* simp */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    v223 = stack[-3];
    v223 = qcdr(v223);
    stack[-3] = v223;
    goto v253;

v253:
    v223 = stack[-3];
    if (v223 == nil) goto v231;
    v223 = stack[-3];
    v223 = qcar(v223);
    stack[-2] = v223;
    v223 = (Lisp_Object)17; /* 1 */
    stack[0] = v223;
    goto v254;

v254:
    v223 = stack[-2];
    v224 = qcdr(v223);
    v223 = stack[0];
    v223 = difference2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = Lminusp(nil, v223);
    env = stack[-7];
    if (v223 == nil) goto v255;
    v223 = stack[-3];
    v223 = qcdr(v223);
    stack[-3] = v223;
    goto v253;

v255:
    v224 = stack[-1];
    v223 = stack[-2];
    v223 = qcar(v223);
    fn = elt(env, 27); /* diffsq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    v223 = stack[0];
    v223 = add1(v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[0] = v223;
    goto v254;

v252:
    v224 = elt(env, 15); /* df */
    v223 = stack[-1];
    v223 = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v241;

v251:
    v225 = elt(env, 15); /* df */
    v223 = stack[-5];
    v223 = qcdr(v223);
    v223 = qcar(v223);
    v223 = qcdr(v223);
    v224 = qcar(v223);
    v223 = stack[-5];
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    v223 = list2star(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v241;

v238:
    v223 = stack[-2];
    v223 = qcdr(v223);
    stack[-2] = v223;
    v223 = stack[0];
    v223 = qcdr(v223);
    stack[0] = v223;
    v223 = stack[0];
    if (v223 == nil) goto v256;
    v223 = stack[-2];
    if (!(v223 == nil)) goto v237;

v256:
    v223 = stack[0];
    if (!(v223 == nil)) goto v239;
    v223 = stack[-2];
    if (!(v223 == nil)) goto v239;
    v223 = stack[-1];
    v223 = Lreverse(nil, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-2] = v223;
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[0] = v223;
    v224 = qvalue(elt(env, 4)); /* nil */
    v223 = (Lisp_Object)17; /* 1 */
    v223 = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v32;

v32:
    v223 = stack[-2];
    v223 = qcar(v223);
    v223 = qcar(v223);
    if (v223 == nil) goto v257;
    v223 = stack[-2];
    stack[-4] = qcar(v223);
    v223 = stack[-3];
    v223 = qcar(v223);
    v224 = qcar(v223);
    v223 = stack[0];
    fn = elt(env, 42); /* pair */
    v224 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-3];
    v223 = qcar(v223);
    v223 = qcdr(v223);
    v223 = Lsubla(nil, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    v224 = (*qfn2(fn))(qenv(fn), stack[-4], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-1];
    fn = elt(env, 25); /* addsq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    goto v257;

v257:
    v223 = stack[-3];
    v223 = qcdr(v223);
    stack[-3] = v223;
    v223 = stack[-2];
    v223 = qcdr(v223);
    stack[-2] = v223;
    v223 = stack[-2];
    if (v223 == nil) goto v231;
    else goto v32;

v236:
    v223 = stack[-5];
    v224 = qcar(v223);
    v223 = elt(env, 5); /* plus */
    if (!(v224 == v223)) goto v239;
    v223 = stack[-5];
    fn = elt(env, 29); /* simp */
    v224 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v223 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    if (v223 == nil) goto v239;
    else goto v231;

v232:
    v224 = stack[-5];
    v223 = stack[-4];
    fn = elt(env, 33); /* depends */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    if (!(v223 == nil)) goto v258;
    v224 = stack[-5];
    v223 = qvalue(elt(env, 11)); /* powlis!* */
    v223 = Latsoc(nil, v224, v223);
    stack[-3] = v223;
    if (v223 == nil) goto v259;
    v223 = stack[-3];
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    v224 = qcar(v223);
    v223 = stack[-4];
    fn = elt(env, 33); /* depends */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    if (!(v223 == nil)) goto v258;

v259:
    v223 = qvalue(elt(env, 12)); /* !*depend */
    if (!(v223 == nil)) goto v258;
    v224 = qvalue(elt(env, 4)); /* nil */
    v223 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v224, v223);

v258:
    v223 = qvalue(elt(env, 13)); /* !*expanddf */
    if (v223 == nil) goto v260;
    v225 = stack[-4];
    v224 = stack[-5];
    v223 = qvalue(elt(env, 14)); /* depl!* */
    v223 = Latsoc(nil, v224, v223);
    v223 = qcdr(v223);
    stack[-3] = v223;
    v223 = Lmemq(nil, v225, v223);
    if (!(v223 == nil)) goto v260;
    v224 = qvalue(elt(env, 4)); /* nil */
    v223 = (Lisp_Object)17; /* 1 */
    v223 = cons(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    v223 = stack[-3];
    stack[-3] = v223;
    goto v261;

v261:
    v223 = stack[-3];
    if (v223 == nil) goto v231;
    v223 = stack[-3];
    v223 = qcar(v223);
    stack[-2] = v223;
    v225 = elt(env, 15); /* df */
    v224 = stack[-5];
    v223 = stack[-2];
    v223 = list3(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v225 = elt(env, 15); /* df */
    v224 = stack[-2];
    v223 = stack[-4];
    v223 = list3(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    v223 = (*qfn2(fn))(qenv(fn), stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 25); /* addsq */
    v223 = (*qfn2(fn))(qenv(fn), stack[-1], v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    v223 = stack[-3];
    v223 = qcdr(v223);
    stack[-3] = v223;
    goto v261;

v260:
    v225 = elt(env, 15); /* df */
    v224 = stack[-5];
    v223 = stack[-4];
    v223 = list3(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-1] = v223;
    v223 = stack[-1];
    fn = elt(env, 30); /* opmtch */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-3] = v223;
    if (v223 == nil) goto v262;
    v223 = stack[-3];
    fn = elt(env, 29); /* simp */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    goto v263;

v263:
    stack[-1] = v223;
    goto v231;

v262:
    v224 = stack[-1];
    v223 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 34); /* mksq */
    v223 = (*qfn2(fn))(qenv(fn), v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    goto v263;
/* error exit handlers */
v227:
    popv(8);
    return nil;
}



/* Code for simpimpart */

static Lisp_Object CC_simpimpart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpimpart");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    v7 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*factor */
    qvalue(elt(env, 2)) = v7; /* !*factor */
    v7 = v19;
    v7 = qcar(v7);
    fn = elt(env, 3); /* simp!* */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-1];
    fn = elt(env, 4); /* impartsq */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    { popv(2); return onevalue(v7); }
/* error exit handlers */
v264:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    popv(2);
    return nil;
}



/* Code for extbrsea */

static Lisp_Object MS_CDECL CC_extbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v305, v306, v307;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "extbrsea");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extbrsea");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    v305 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v305;
    goto v47;

v47:
    v306 = qvalue(elt(env, 2)); /* rowmax */
    v305 = stack[-1];
    v305 = difference2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v305 = Lminusp(nil, v305);
    env = stack[-2];
    if (v305 == nil) goto v309;
    fn = elt(env, 8); /* initbrsea */
    v305 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v305 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    goto v310;

v310:
    fn = elt(env, 10); /* expandprod */
    v305 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v305 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v305;
    goto v311;

v311:
    v306 = qvalue(elt(env, 2)); /* rowmax */
    v305 = stack[-1];
    v305 = difference2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v305 = Lminusp(nil, v305);
    env = stack[-2];
    if (v305 == nil) goto v312;
    fn = elt(env, 8); /* initbrsea */
    v305 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v305 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    fn = elt(env, 11); /* shrinkprod */
    v305 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    if (!(v305 == nil)) goto v310;
    v305 = nil;
    { popv(3); return onevalue(v305); }

v312:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v306 = qvalue(elt(env, 5)); /* maxvar */
    v305 = stack[-1];
    v305 = plus2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v306 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v305 = (Lisp_Object)49; /* 3 */
    v306 = *(Lisp_Object *)((char *)v306 + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v305 = (Lisp_Object)-15; /* -1 */
    if (v306 == v305) goto v313;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v306 = qvalue(elt(env, 5)); /* maxvar */
    v305 = stack[-1];
    v305 = plus2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v306 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v305 = (Lisp_Object)33; /* 2 */
    v306 = *(Lisp_Object *)((char *)v306 + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v305 = elt(env, 7); /* times */
    if (!(v306 == v305)) goto v313;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v306 = qvalue(elt(env, 5)); /* maxvar */
    v305 = stack[-1];
    v305 = plus2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v307 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v306 = (Lisp_Object)1; /* 0 */
    v305 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v307 + (CELL-TAG_VECTOR) + ((int32_t)v306/(16/CELL))) = v305;
    goto v314;

v314:
    v305 = stack[-1];
    v305 = add1(v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    stack[-1] = v305;
    goto v311;

v313:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v306 = qvalue(elt(env, 5)); /* maxvar */
    v305 = stack[-1];
    v305 = plus2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v307 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v306 = (Lisp_Object)1; /* 0 */
    v305 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v307 + (CELL-TAG_VECTOR) + ((int32_t)v306/(16/CELL))) = v305;
    goto v314;

v309:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v306 = qvalue(elt(env, 5)); /* maxvar */
    v305 = stack[-1];
    v305 = plus2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v306 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v305 = (Lisp_Object)49; /* 3 */
    v306 = *(Lisp_Object *)((char *)v306 + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v305 = (Lisp_Object)-15; /* -1 */
    if (v306 == v305) goto v48;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v306 = qvalue(elt(env, 5)); /* maxvar */
    v305 = stack[-1];
    v305 = plus2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v306 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v305 = (Lisp_Object)49; /* 3 */
    v306 = *(Lisp_Object *)((char *)v306 + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v305 = (Lisp_Object)-31; /* -2 */
    if (v306 == v305) goto v48;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v306 = qvalue(elt(env, 5)); /* maxvar */
    v305 = stack[-1];
    v305 = plus2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v307 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v306 = (Lisp_Object)1; /* 0 */
    v305 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v307 + (CELL-TAG_VECTOR) + ((int32_t)v306/(16/CELL))) = v305;
    goto v23;

v23:
    v305 = stack[-1];
    v305 = add1(v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    stack[-1] = v305;
    goto v47;

v48:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v306 = qvalue(elt(env, 5)); /* maxvar */
    v305 = stack[-1];
    v305 = plus2(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-2];
    v307 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v305/(16/CELL)));
    v306 = (Lisp_Object)1; /* 0 */
    v305 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v307 + (CELL-TAG_VECTOR) + ((int32_t)v306/(16/CELL))) = v305;
    goto v23;
/* error exit handlers */
v308:
    popv(3);
    return nil;
}



/* Code for f2dip11 */

static Lisp_Object CC_f2dip11(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip11");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v316:
    v315 = qvalue(elt(env, 1)); /* !*notestparameters */
    if (!(v315 == nil)) { popv(2); return onevalue(v315); }
    v217 = stack[0];
    v315 = qvalue(elt(env, 2)); /* vdpvars!* */
    v315 = Lmember(nil, v217, v315);
    if (v315 == nil) goto v18;
    v315 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v315 == nil)) goto v2;
    v217 = stack[0];
    v315 = elt(env, 4); /* "occurs in a parameter and is member of the groebner variables." 
*/
    v315 = list2(v217, v315);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    fn = elt(env, 7); /* lprie */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    goto v2;

v2:
    v315 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    goto v18;

v18:
    v315 = stack[0];
    if (!consp(v315)) goto v302;
    v315 = stack[0];
    v315 = qcar(v315);
    v315 = CC_f2dip11(env, v315);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    v315 = stack[0];
    v315 = qcdr(v315);
    stack[0] = v315;
    goto v316;

v302:
    v217 = stack[0];
    v315 = elt(env, 5); /* list */
    if (v217 == v315) goto v317;
    v315 = nil;
    { popv(2); return onevalue(v315); }

v317:
    v315 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v315 == nil)) goto v215;
    v315 = elt(env, 6); /* "groebner: LIST not allowed." */
    fn = elt(env, 7); /* lprie */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    goto v215;

v215:
    v315 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v315 = nil;
    { popv(2); return onevalue(v315); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for indordl2 */

static Lisp_Object CC_indordl2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordl2");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v221 = stack[-1];
    v28 = stack[0];
    fn = elt(env, 1); /* indordlp */
    v28 = (*qfn2(fn))(qenv(fn), v221, v28);
    nil = C_nil;
    if (exception_pending()) goto v45;
    if (v28 == nil) goto v24;
    v221 = stack[-1];
    v28 = stack[0];
    popv(2);
    return list2(v221, v28);

v24:
    v221 = stack[0];
    v28 = stack[-1];
    popv(2);
    return list2(v221, v28);
/* error exit handlers */
v45:
    popv(2);
    return nil;
}



/* Code for contr2 */

static Lisp_Object MS_CDECL CC_contr2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v324, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contr2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr2");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v18;

v18:
    v324 = stack[-1];
    if (v324 == nil) goto v320;
    v324 = stack[0];
    if (v324 == nil) goto v5;
    v51 = stack[-2];
    v324 = stack[-1];
    v324 = qcar(v324);
    fn = elt(env, 1); /* split!-road */
    v51 = (*qfn2(fn))(qenv(fn), v51, v324);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    v324 = stack[-3];
    v324 = cons(v51, v324);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    stack[-3] = v324;
    v324 = stack[-1];
    v324 = qcdr(v324);
    stack[-1] = v324;
    goto v18;

v5:
    stack[0] = stack[-3];
    v51 = stack[-2];
    v324 = stack[-1];
    fn = elt(env, 2); /* contr */
    v324 = (*qfn2(fn))(qenv(fn), v51, v324);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    {
        Lisp_Object v42 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v42, v324);
    }

v320:
    stack[-1] = stack[-3];
    v51 = stack[-2];
    v324 = stack[0];
    fn = elt(env, 2); /* contr */
    v324 = (*qfn2(fn))(qenv(fn), v51, v324);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    {
        Lisp_Object v325 = stack[-1];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v325, v324);
    }
/* error exit handlers */
v41:
    popv(5);
    return nil;
}



/* Code for remchkf1 */

static Lisp_Object CC_remchkf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v43, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remchkf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v206 = stack[-1];
    fn = elt(env, 3); /* termsf */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    stack[-2] = v206;
    v44 = stack[-1];
    v43 = stack[0];
    v206 = stack[-2];
    fn = elt(env, 4); /* xremf */
    v206 = (*qfnn(fn))(qenv(fn), 3, v44, v43, v206);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    stack[0] = v206;
    v206 = stack[0];
    if (v206 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v206 = stack[0];
    v206 = qcar(v206);
    stack[0] = v206;
    fn = elt(env, 3); /* termsf */
    v43 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    v206 = stack[-2];
    v206 = (Lisp_Object)geq2(v43, v206);
    nil = C_nil;
    if (exception_pending()) goto v215;
    v206 = v206 ? lisp_true : nil;
    env = stack[-3];
    if (!(v206 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v206 = qvalue(elt(env, 1)); /* !*trcompact */
    if (v206 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v206 = elt(env, 2); /* "*** Remainder smaller" */
    v206 = Lprinc(nil, v206);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    v206 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v215;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v215:
    popv(4);
    return nil;
}



/* Code for harmonicp */

static Lisp_Object CC_harmonicp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v327, v264;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for harmonicp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v327 = v0;
/* end of prologue */
    v264 = elt(env, 1); /* fourier!-angle */
    return get(v327, v264);
}



/* Code for dp_neworder */

static Lisp_Object CC_dp_neworder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neworder");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v315 = v0;
/* end of prologue */
    stack[-4] = v315;
    v315 = stack[-4];
    if (v315 == nil) goto v241;
    v315 = stack[-4];
    v315 = qcar(v315);
    stack[0] = v315;
    v315 = stack[0];
    v315 = qcar(v315);
    fn = elt(env, 3); /* mo_neworder */
    v217 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-5];
    v315 = stack[0];
    v315 = qcdr(v315);
    v315 = cons(v217, v315);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-5];
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-5];
    stack[-2] = v315;
    stack[-3] = v315;
    goto v319;

v319:
    v315 = stack[-4];
    v315 = qcdr(v315);
    stack[-4] = v315;
    v315 = stack[-4];
    if (v315 == nil) goto v331;
    stack[-1] = stack[-2];
    v315 = stack[-4];
    v315 = qcar(v315);
    stack[0] = v315;
    v315 = stack[0];
    v315 = qcar(v315);
    fn = elt(env, 3); /* mo_neworder */
    v217 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-5];
    v315 = stack[0];
    v315 = qcdr(v315);
    v315 = cons(v217, v315);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-5];
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-5];
    v315 = Lrplacd(nil, stack[-1], v315);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-5];
    v315 = stack[-2];
    v315 = qcdr(v315);
    stack[-2] = v315;
    goto v319;

v331:
    v315 = stack[-3];
    v217 = v315;
    goto v6;

v6:
    v315 = elt(env, 2); /* dp!=mocompare */
    {
        popv(6);
        fn = elt(env, 4); /* sort */
        return (*qfn2(fn))(qenv(fn), v217, v315);
    }

v241:
    v315 = qvalue(elt(env, 1)); /* nil */
    v217 = v315;
    goto v6;
/* error exit handlers */
v330:
    popv(6);
    return nil;
}



/* Code for multerm */

static Lisp_Object CC_multerm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multerm");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v28 = stack[-1];
    v221 = qcdr(v28);
    v28 = stack[0];
    v28 = qcdr(v28);
    fn = elt(env, 1); /* !*multsq */
    v28 = (*qfn2(fn))(qenv(fn), v221, v28);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-3];
    stack[-2] = v28;
    v28 = stack[-1];
    v221 = qcar(v28);
    v28 = stack[0];
    v28 = qcar(v28);
    fn = elt(env, 2); /* mulpower */
    v28 = (*qfn2(fn))(qenv(fn), v221, v28);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-3];
    {
        Lisp_Object v333 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multdfconst */
        return (*qfn2(fn))(qenv(fn), v333, v28);
    }
/* error exit handlers */
v309:
    popv(4);
    return nil;
}



/* Code for tayfkern */

static Lisp_Object CC_tayfkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v217, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayfkern");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v217 = v0;
/* end of prologue */
    v315 = qvalue(elt(env, 1)); /* !*tayinternal!* */
    if (!(v315 == nil)) { popv(3); return onevalue(v217); }
    v218 = elt(env, 2); /* taylor!* */
    v315 = elt(env, 3); /* klist */
    v315 = get(v218, v315);
    env = stack[-2];
    stack[0] = v315;
    v218 = v217;
    v315 = stack[0];
    v315 = Lassoc(nil, v218, v315);
    stack[-1] = v315;
    v315 = stack[-1];
    if (!(v315 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v315 = qvalue(elt(env, 4)); /* nil */
    v315 = list2(v217, v315);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-2];
    stack[-1] = v315;
    v217 = stack[-1];
    v315 = stack[0];
    fn = elt(env, 7); /* ordad */
    v315 = (*qfn2(fn))(qenv(fn), v217, v315);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-2];
    stack[0] = v315;
    v217 = elt(env, 5); /* (taylor!*) */
    v315 = qvalue(elt(env, 6)); /* kprops!* */
    fn = elt(env, 8); /* union */
    v315 = (*qfn2(fn))(qenv(fn), v217, v315);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-2];
    qvalue(elt(env, 6)) = v315; /* kprops!* */
    v218 = elt(env, 2); /* taylor!* */
    v217 = elt(env, 3); /* klist */
    v315 = stack[0];
    v315 = Lputprop(nil, 3, v218, v217, v315);
    nil = C_nil;
    if (exception_pending()) goto v325;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v325:
    popv(3);
    return nil;
}



/* Code for mk!+squared!+norm */

static Lisp_Object CC_mkLsquaredLnorm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v319;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+squared+norm");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v319 = v32;
    {
        fn = elt(env, 1); /* mk!+inner!+product */
        return (*qfn2(fn))(qenv(fn), v319, v32);
    }
}



/* Code for cl_susiinter */

static Lisp_Object MS_CDECL CC_cl_susiinter(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v291, v337, v338, v339;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_susiinter");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiinter");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v40;
    stack[-4] = v1;
    v291 = v0;
/* end of prologue */
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = v291;
    goto v32;

v32:
    v291 = stack[0];
    if (v291 == nil) goto v212;
    v291 = stack[0];
    v291 = qcar(v291);
    v338 = v291;
    v291 = v338;
    v337 = qcar(v291);
    v291 = elt(env, 2); /* ignore */
    if (v337 == v291) goto v25;
    v291 = v338;
    v337 = qcar(v291);
    v291 = elt(env, 4); /* delete */
    if (v337 == v291) goto v220;
    v291 = v338;
    v337 = qcar(v291);
    v291 = elt(env, 5); /* add */
    if (!(v337 == v291)) goto v23;
    v291 = v338;
    v337 = qcdr(v291);
    v291 = stack[-5];
    v291 = cons(v337, v291);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    stack[-5] = v291;
    goto v23;

v23:
    v291 = stack[0];
    v291 = qcdr(v291);
    stack[0] = v291;
    goto v32;

v220:
    v291 = v338;
    v291 = qcdr(v291);
    if (v291 == nil) goto v297;
    v291 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v291;
    goto v23;

v297:
    v337 = stack[-3];
    v291 = stack[-4];
    fn = elt(env, 6); /* delqip */
    v291 = (*qfn2(fn))(qenv(fn), v337, v291);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    stack[-4] = v291;
    goto v23;

v25:
    v291 = v338;
    v291 = qcdr(v291);
    if (v291 == nil) goto v298;
    v291 = qvalue(elt(env, 3)); /* t */
    stack[-2] = v291;
    v291 = v338;
    v337 = qcdr(v291);
    v291 = stack[-5];
    v291 = cons(v337, v291);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    stack[-5] = v291;
    goto v23;

v298:
    v337 = stack[-3];
    v291 = elt(env, 2); /* ignore */
    fn = elt(env, 7); /* setcdr */
    v291 = (*qfn2(fn))(qenv(fn), v337, v291);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    goto v23;

v212:
    v339 = stack[-4];
    v338 = stack[-5];
    v337 = stack[-2];
    v291 = stack[-1];
    popv(7);
    return list4(v339, v338, v337, v291);
/* error exit handlers */
v289:
    popv(7);
    return nil;
}



/* Code for ratpoly_0 */

static Lisp_Object MS_CDECL CC_ratpoly_0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_0");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v37 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v37);
    }
}



/* Code for minusml */

static Lisp_Object CC_minusml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusml");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v24 = elt(env, 1); /* "<apply><minus/>" */
    fn = elt(env, 4); /* printout */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    v20 = qvalue(elt(env, 2)); /* indent */
    v24 = (Lisp_Object)49; /* 3 */
    v24 = plus2(v20, v24);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    qvalue(elt(env, 2)) = v24; /* indent */
    v24 = stack[0];
    fn = elt(env, 5); /* multiminus */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    v20 = qvalue(elt(env, 2)); /* indent */
    v24 = (Lisp_Object)49; /* 3 */
    v24 = difference2(v20, v24);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    qvalue(elt(env, 2)) = v24; /* indent */
    v24 = elt(env, 3); /* "</apply>" */
    fn = elt(env, 4); /* printout */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v24 = nil;
    { popv(2); return onevalue(v24); }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for maxl */

static Lisp_Object CC_maxl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v302;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxl");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v169;

v169:
    v301 = stack[0];
    if (v301 == nil) goto v18;
    v301 = stack[0];
    v302 = qcar(v301);
    v301 = stack[-1];
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    stack[-1] = v301;
    v301 = stack[0];
    v301 = qcdr(v301);
    stack[0] = v301;
    goto v169;

v18:
    v301 = (Lisp_Object)-159999; /* -10000 */
    v302 = v301;
    goto v7;

v7:
    v301 = stack[-1];
    if (v301 == nil) { popv(3); return onevalue(v302); }
    v301 = stack[-1];
    v301 = qcar(v301);
    fn = elt(env, 1); /* max */
    v301 = (*qfn2(fn))(qenv(fn), v301, v302);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v302 = v301;
    v301 = stack[-1];
    v301 = qcdr(v301);
    stack[-1] = v301;
    goto v7;
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for remzzzz */

static Lisp_Object CC_remzzzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v303, v299;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remzzzz");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v299 = nil;
    goto v169;

v169:
    v44 = stack[-1];
    if (v44 == nil) goto v319;
    v44 = stack[-1];
    v44 = qcar(v44);
    v303 = qcar(v44);
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = qcar(v44);
    if (equal(v303, v44)) goto v304;
    v44 = stack[0];
    v44 = qcar(v44);
    v303 = v299;
    v44 = cons(v44, v303);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    v299 = v44;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v169;

v304:
    v44 = stack[-1];
    v44 = qcdr(v44);
    stack[-1] = v44;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v169;

v319:
    v303 = v299;
    v44 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v303, v44);
    }
/* error exit handlers */
v298:
    popv(3);
    return nil;
}



/* Code for dipequal */

static Lisp_Object CC_dipequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v321, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v6:
    v321 = stack[-1];
    if (v321 == nil) goto v7;
    v321 = stack[0];
    if (v321 == nil) goto v319;
    v321 = stack[-1];
    v321 = qcdr(v321);
    v219 = qcar(v321);
    v321 = stack[0];
    v321 = qcdr(v321);
    v321 = qcar(v321);
    if (equal(v219, v321)) goto v333;
    v321 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v321); }

v333:
    v321 = stack[-1];
    v219 = qcar(v321);
    v321 = stack[0];
    v321 = qcar(v321);
    fn = elt(env, 2); /* evequal */
    v321 = (*qfn2(fn))(qenv(fn), v219, v321);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-2];
    if (v321 == nil) goto v215;
    v321 = stack[-1];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    stack[-1] = v321;
    v321 = stack[0];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    stack[0] = v321;
    goto v6;

v215:
    v321 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v321); }

v319:
    v321 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v321); }

v7:
    v321 = stack[0];
    v321 = (v321 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v321); }
/* error exit handlers */
v341:
    popv(3);
    return nil;
}



/* Code for evinsert */

static Lisp_Object MS_CDECL CC_evinsert(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v321, v219, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "evinsert");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evinsert");
#endif
    if (stack >= stacklimit)
    {
        push4(v37,v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v40,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v40;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v220 = nil;
    goto v7;

v7:
    v321 = stack[-3];
    if (v321 == nil) goto v264;
    v321 = stack[0];
    if (v321 == nil) goto v264;
    v321 = stack[0];
    v219 = qcar(v321);
    v321 = stack[-2];
    if (equal(v219, v321)) goto v332;
    v321 = stack[-3];
    v321 = qcar(v321);
    v219 = v220;
    v321 = cons(v321, v219);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v220 = v321;
    v321 = stack[-3];
    v321 = qcdr(v321);
    stack[-3] = v321;
    v321 = stack[0];
    v321 = qcdr(v321);
    stack[0] = v321;
    goto v7;

v332:
    stack[0] = v220;
    v219 = stack[-1];
    v321 = stack[-3];
    v321 = qcdr(v321);
    v321 = cons(v219, v321);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    {
        Lisp_Object v328 = stack[0];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v328, v321);
    }

v264:
    v321 = v220;
    {
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v321);
    }
/* error exit handlers */
v51:
    popv(5);
    return nil;
}



/* Code for getrlist */

static Lisp_Object CC_getrlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v220, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrlist");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v216 = v0;
/* end of prologue */
    v220 = v216;
    v219 = elt(env, 1); /* list */
    if (!consp(v220)) goto v30;
    v220 = qcar(v220);
    if (!(v220 == v219)) goto v30;
    v219 = v216;
    v219 = qcdr(v219);
    { popv(1); return onevalue(v219); }

v30:
    v220 = v216;
    v219 = elt(env, 2); /* !*sq */
    if (!consp(v220)) goto v21;
    v220 = qcar(v220);
    if (!(v220 == v219)) goto v21;
    v219 = v216;
    v219 = qcdr(v219);
    v219 = qcar(v219);
    v219 = qcar(v219);
    if (v219 == nil) goto v309;
    v219 = v216;
    v219 = qcdr(v219);
    v220 = qcar(v219);
    v219 = elt(env, 3); /* prepf */
    fn = elt(env, 5); /* sqform */
    v219 = (*qfn2(fn))(qenv(fn), v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[0];
    goto v45;

v45:
    v220 = v219;
    goto v2;

v2:
    v219 = elt(env, 4); /* "list" */
    {
        popv(1);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v220, v219);
    }

v309:
    v219 = (Lisp_Object)1; /* 0 */
    goto v45;

v21:
    v219 = v216;
    v220 = v219;
    goto v2;
/* error exit handlers */
v341:
    popv(1);
    return nil;
}



/* Code for reduce */

static Lisp_Object CC_reduce(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v334, v21, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    v334 = v0;
/* end of prologue */
    stack[0] = v334;
    v334 = qvalue(elt(env, 1)); /* !*yyy */
    if (v334 == nil) goto v19;
    v21 = stack[0];
    v334 = stack[-1];
    fn = elt(env, 3); /* reduce!-ratios */
    v334 = (*qfn2(fn))(qenv(fn), v21, v334);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-3];
    stack[0] = v334;
    goto v19;

v19:
    v334 = stack[-1];
    fn = elt(env, 4); /* set!-weights */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-3];
    stack[-2] = v334;
    v334 = qvalue(elt(env, 2)); /* !*xxx */
    if (v334 == nil) goto v23;
    v22 = stack[0];
    v21 = stack[-1];
    v334 = stack[-2];
    fn = elt(env, 5); /* reduce!-columns */
    v334 = (*qfnn(fn))(qenv(fn), 3, v22, v21, v334);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-3];
    stack[0] = v334;
    goto v23;

v23:
    v334 = qvalue(elt(env, 2)); /* !*xxx */
    if (v334 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v22 = stack[0];
    v21 = stack[-1];
    v334 = stack[-2];
    fn = elt(env, 6); /* reduce!-weights */
    v334 = (*qfnn(fn))(qenv(fn), 3, v22, v21, v334);
    nil = C_nil;
    if (exception_pending()) goto v220;
    stack[0] = v334;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v220:
    popv(4);
    return nil;
}



/* Code for sqprint */

static Lisp_Object CC_sqprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190, v193, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqprint");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*prin!# */
    qvalue(elt(env, 1)) = nil; /* !*prin!# */
    v190 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v190; /* !*prin!# */
    v190 = qvalue(elt(env, 3)); /* orig!* */
    stack[-1] = v190;
    v190 = qvalue(elt(env, 4)); /* !*nat */
    if (v190 == nil) goto v327;
    v193 = qvalue(elt(env, 5)); /* posn!* */
    v190 = (Lisp_Object)321; /* 20 */
    v190 = (Lisp_Object)lessp2(v193, v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    v190 = v190 ? lisp_true : nil;
    env = stack[-4];
    if (v190 == nil) goto v327;
    v190 = qvalue(elt(env, 5)); /* posn!* */
    qvalue(elt(env, 3)) = v190; /* orig!* */
    goto v327;

v327:
    v190 = qvalue(elt(env, 6)); /* !*pri */
    if (!(v190 == nil)) goto v221;
    v190 = qvalue(elt(env, 7)); /* wtl!* */
    if (!(v190 == nil)) goto v221;
    v190 = stack[-2];
    v193 = qcdr(v190);
    v190 = (Lisp_Object)17; /* 1 */
    if (v193 == v190) goto v347;
    v190 = stack[-2];
    v190 = qcar(v190);
    if (!consp(v190)) goto v34;
    v190 = stack[-2];
    v190 = qcar(v190);
    v190 = qcar(v190);
    if (!consp(v190)) goto v34;
    v190 = stack[-2];
    v190 = qcar(v190);
    v190 = qcdr(v190);
    goto v36;

v36:
    stack[-3] = v190;
    v190 = stack[-3];
    if (v190 == nil) goto v35;
    v190 = elt(env, 14); /* "(" */
    fn = elt(env, 17); /* prin2!* */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    goto v35;

v35:
    v190 = stack[-2];
    v190 = qcar(v190);
    fn = elt(env, 18); /* xprinf2 */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v190 = stack[-3];
    if (v190 == nil) goto v292;
    v190 = elt(env, 15); /* ")" */
    fn = elt(env, 17); /* prin2!* */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    goto v292;

v292:
    v190 = elt(env, 16); /* " / " */
    fn = elt(env, 17); /* prin2!* */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v190 = stack[-2];
    v190 = qcdr(v190);
    if (!consp(v190)) goto v289;
    v190 = stack[-2];
    v190 = qcdr(v190);
    v190 = qcar(v190);
    if (!consp(v190)) goto v289;
    v190 = stack[-2];
    v190 = qcdr(v190);
    v190 = qcdr(v190);
    if (!(v190 == nil)) goto v290;
    v190 = stack[-2];
    v190 = qcdr(v190);
    v190 = qcar(v190);
    v193 = qcdr(v190);
    v190 = (Lisp_Object)17; /* 1 */
    v190 = Lneq(nil, v193, v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    goto v290;

v290:
    stack[-3] = v190;
    v190 = stack[-3];
    if (v190 == nil) goto v348;
    v190 = elt(env, 14); /* "(" */
    fn = elt(env, 17); /* prin2!* */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    goto v348;

v348:
    v190 = stack[-2];
    v190 = qcdr(v190);
    fn = elt(env, 18); /* xprinf2 */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v190 = stack[-3];
    if (v190 == nil) goto v24;
    v190 = elt(env, 15); /* ")" */
    fn = elt(env, 17); /* prin2!* */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    goto v24;

v24:
    v190 = stack[-1];
    qvalue(elt(env, 3)) = v190; /* orig!* */
    qvalue(elt(env, 1)) = stack[0]; /* !*prin!# */
    { popv(5); return onevalue(v190); }

v289:
    v190 = qvalue(elt(env, 13)); /* nil */
    goto v290;

v34:
    v190 = qvalue(elt(env, 13)); /* nil */
    goto v36;

v347:
    v190 = stack[-2];
    v190 = qcar(v190);
    fn = elt(env, 18); /* xprinf2 */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    goto v24;

v221:
    v190 = stack[-2];
    fn = elt(env, 19); /* sqhorner!* */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    fn = elt(env, 20); /* prepsq!* */
    stack[-2] = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v193 = qvalue(elt(env, 8)); /* ordl!* */
    v190 = qvalue(elt(env, 9)); /* factors!* */
    v190 = Lappend(nil, v193, v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    fn = elt(env, 21); /* prepreform1 */
    v190 = (*qfn2(fn))(qenv(fn), stack[-2], v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    v193 = qvalue(elt(env, 10)); /* outputhandler!* */
    if (v193 == nil) goto v215;
    v192 = qvalue(elt(env, 10)); /* outputhandler!* */
    v193 = elt(env, 11); /* maprin */
    v190 = Lapply2(nil, 3, v192, v193, v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    goto v24;

v215:
    v193 = qvalue(elt(env, 12)); /* overflowed!* */
    if (!(v193 == nil)) goto v24;
    v193 = v190;
    v190 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 22); /* maprint */
    v190 = (*qfn2(fn))(qenv(fn), v193, v190);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-4];
    goto v24;
/* error exit handlers */
v346:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*prin!# */
    popv(5);
    return nil;
}



/* Code for simpiden */

static Lisp_Object CC_simpiden(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v392, v393, v394;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpiden");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    v392 = stack[0];
    v392 = qcar(v392);
    stack[-6] = v392;
    v392 = stack[0];
    v392 = qcdr(v392);
    stack[0] = v392;
    v393 = stack[-6];
    v392 = elt(env, 1); /* !:rn!: */
    v392 = get(v393, v392);
    env = stack[-7];
    if (!(v392 == nil)) goto v333;
    v393 = stack[-6];
    v392 = elt(env, 2); /* !:rd!: */
    v392 = get(v393, v392);
    env = stack[-7];
    if (!(v392 == nil)) goto v333;

v47:
    v392 = stack[0];
    if (v392 == nil) goto v206;
    v392 = stack[0];
    v393 = qcar(v392);
    v392 = elt(env, 3); /* list */
    if (!consp(v393)) goto v206;
    v393 = qcar(v393);
    if (!(v393 == v392)) goto v206;
    v392 = stack[0];
    v392 = qcdr(v392);
    if (!(v392 == nil)) goto v206;
    stack[-1] = stack[-6];
    v392 = stack[0];
    v392 = qcar(v392);
    fn = elt(env, 15); /* aeval */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v393 = list2(stack[-1], v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 16); /* mksq */
        return (*qfn2(fn))(qenv(fn), v393, v392);
    }

v206:
    v392 = stack[0];
    stack[-3] = v392;
    v392 = stack[-3];
    if (v392 == nil) goto v48;
    v392 = stack[-3];
    v392 = qcar(v392);
    fn = elt(env, 15); /* aeval */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = ncons(v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-1] = v392;
    stack[-2] = v392;
    goto v12;

v12:
    v392 = stack[-3];
    v392 = qcdr(v392);
    stack[-3] = v392;
    v392 = stack[-3];
    if (v392 == nil) goto v292;
    stack[0] = stack[-1];
    v392 = stack[-3];
    v392 = qcar(v392);
    fn = elt(env, 15); /* aeval */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = ncons(v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = Lrplacd(nil, stack[0], v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = stack[-1];
    v392 = qcdr(v392);
    stack[-1] = v392;
    goto v12;

v292:
    v392 = stack[-2];
    goto v16;

v16:
    stack[-5] = v392;
    v392 = stack[-5];
    stack[-3] = v392;
    v392 = stack[-3];
    if (v392 == nil) goto v289;
    v392 = stack[-3];
    v392 = qcar(v392);
    v394 = v392;
    v393 = v394;
    v392 = elt(env, 5); /* !*sq */
    if (!consp(v393)) goto v396;
    v393 = qcar(v393);
    if (!(v393 == v392)) goto v396;
    v392 = v394;
    v392 = qcdr(v392);
    v392 = qcar(v392);
    fn = elt(env, 17); /* prepsqxx */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    goto v265;

v265:
    v392 = ncons(v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-1] = v392;
    stack[-2] = v392;
    goto v26;

v26:
    v392 = stack[-3];
    v392 = qcdr(v392);
    stack[-3] = v392;
    v392 = stack[-3];
    if (v392 == nil) goto v196;
    stack[0] = stack[-1];
    v392 = stack[-3];
    v392 = qcar(v392);
    v394 = v392;
    v393 = v394;
    v392 = elt(env, 5); /* !*sq */
    if (!consp(v393)) goto v347;
    v393 = qcar(v393);
    if (!(v393 == v392)) goto v347;
    v392 = v394;
    v392 = qcdr(v392);
    v392 = qcar(v392);
    fn = elt(env, 17); /* prepsqxx */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    goto v397;

v397:
    v392 = ncons(v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = Lrplacd(nil, stack[0], v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = stack[-1];
    v392 = qcdr(v392);
    stack[-1] = v392;
    goto v26;

v347:
    v392 = v394;
    if (is_number(v392)) goto v346;
    v392 = v394;
    goto v397;

v346:
    v392 = v394;
    goto v397;

v196:
    v392 = stack[-2];
    goto v398;

v398:
    stack[0] = v392;
    v392 = stack[0];
    if (v392 == nil) goto v399;
    v392 = stack[0];
    v393 = qcar(v392);
    v392 = (Lisp_Object)1; /* 0 */
    if (!(v393 == v392)) goto v399;
    v393 = stack[-6];
    v392 = elt(env, 7); /* odd */
    v392 = Lflagp(nil, v393, v392);
    env = stack[-7];
    if (v392 == nil) goto v399;
    v393 = stack[-6];
    v392 = elt(env, 8); /* nonzero */
    v392 = Lflagp(nil, v393, v392);
    env = stack[-7];
    if (!(v392 == nil)) goto v399;
    v393 = qvalue(elt(env, 4)); /* nil */
    v392 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v393, v392);

v399:
    v393 = stack[-6];
    v392 = stack[0];
    v392 = cons(v393, v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[0] = v392;
    v392 = stack[-6];
    if (!symbolp(v392)) v392 = nil;
    else { v392 = qfastgets(v392);
           if (v392 != nil) { v392 = elt(v392, 0); /* noncom */
#ifdef RECORD_GET
             if (v392 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v392 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v392 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v392 == SPID_NOPROP) v392 = nil; else v392 = lisp_true; }}
#endif
    if (v392 == nil) goto v400;
    v392 = qvalue(elt(env, 6)); /* t */
    qvalue(elt(env, 9)) = v392; /* ncmp!* */
    goto v400;

v400:
    v392 = qvalue(elt(env, 10)); /* subfg!* */
    if (v392 == nil) goto v401;
    v393 = stack[-6];
    v392 = elt(env, 11); /* linear */
    v392 = Lflagp(nil, v393, v392);
    env = stack[-7];
    if (v392 == nil) goto v266;
    v392 = stack[0];
    fn = elt(env, 18); /* formlnr */
    v393 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-1] = v393;
    v392 = stack[0];
    if (equal(v393, v392)) goto v266;
    v392 = stack[-1];
    {
        popv(8);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v392);
    }

v266:
    v392 = stack[0];
    fn = elt(env, 20); /* opmtch */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-1] = v392;
    if (v392 == nil) goto v401;
    v392 = stack[-1];
    {
        popv(8);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v392);
    }

v401:
    v393 = stack[-6];
    v392 = elt(env, 12); /* symmetric */
    v392 = Lflagp(nil, v393, v392);
    env = stack[-7];
    if (v392 == nil) goto v402;
    stack[-1] = stack[-6];
    v392 = stack[0];
    v392 = qcdr(v392);
    fn = elt(env, 21); /* ordn */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = cons(stack[-1], v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[0] = v392;
    goto v403;

v403:
    v393 = stack[-6];
    v392 = elt(env, 14); /* even */
    v392 = Lflagp(nil, v393, v392);
    env = stack[-7];
    if (!(v392 == nil)) goto v404;
    v393 = stack[-6];
    v392 = elt(env, 7); /* odd */
    v392 = Lflagp(nil, v393, v392);
    env = stack[-7];
    if (!(v392 == nil)) goto v404;

v134:
    v393 = stack[0];
    v392 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksq */
    v392 = (*qfn2(fn))(qenv(fn), v393, v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[0] = v392;
    v392 = stack[-4];
    if (v392 == nil) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v392 = stack[0];
    v392 = qcar(v392);
    fn = elt(env, 22); /* negf */
    v393 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    v392 = stack[0];
    v392 = qcdr(v392);
    popv(8);
    return cons(v393, v392);

v404:
    v392 = stack[-5];
    if (v392 == nil) goto v134;
    v392 = stack[-5];
    v392 = qcar(v392);
    fn = elt(env, 19); /* simp */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-5] = v392;
    v392 = qcar(v392);
    fn = elt(env, 23); /* minusf */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    if (v392 == nil) goto v134;
    v393 = stack[-6];
    v392 = elt(env, 14); /* even */
    v392 = Lflagp(nil, v393, v392);
    env = stack[-7];
    if (!(v392 == nil)) goto v405;
    v392 = stack[-4];
    v392 = (v392 == nil ? lisp_true : nil);
    stack[-4] = v392;
    goto v405;

v405:
    stack[-1] = stack[-6];
    v392 = stack[-5];
    v392 = qcar(v392);
    fn = elt(env, 22); /* negf */
    v393 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = stack[-5];
    v392 = qcdr(v392);
    v392 = cons(v393, v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    fn = elt(env, 17); /* prepsqxx */
    v393 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    v392 = stack[0];
    v392 = qcdr(v392);
    v392 = qcdr(v392);
    v392 = list2star(stack[-1], v393, v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[0] = v392;
    v392 = stack[0];
    fn = elt(env, 20); /* opmtch */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-1] = v392;
    if (v392 == nil) goto v134;
    v392 = stack[-4];
    if (v392 == nil) goto v406;
    v392 = stack[-1];
    fn = elt(env, 19); /* simp */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[0] = v392;
    v392 = stack[0];
    v392 = qcar(v392);
    fn = elt(env, 22); /* negf */
    v393 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    v392 = stack[0];
    v392 = qcdr(v392);
    popv(8);
    return cons(v393, v392);

v406:
    v392 = stack[-1];
    {
        popv(8);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v392);
    }

v402:
    v393 = stack[-6];
    v392 = elt(env, 13); /* antisymmetric */
    v392 = Lflagp(nil, v393, v392);
    env = stack[-7];
    if (v392 == nil) goto v403;
    v392 = stack[0];
    v392 = qcdr(v392);
    fn = elt(env, 24); /* repeats */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    if (v392 == nil) goto v407;
    v393 = qvalue(elt(env, 4)); /* nil */
    v392 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v393, v392);

v407:
    v392 = stack[0];
    v392 = qcdr(v392);
    fn = elt(env, 21); /* ordn */
    v393 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-1] = v393;
    v392 = stack[0];
    v392 = qcdr(v392);
    fn = elt(env, 25); /* permp */
    v392 = (*qfn2(fn))(qenv(fn), v393, v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    if (!(v392 == nil)) goto v408;
    v392 = qvalue(elt(env, 6)); /* t */
    stack[-4] = v392;
    goto v408;

v408:
    v392 = stack[0];
    v393 = qcar(v392);
    v392 = stack[-1];
    v392 = cons(v393, v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-6] = v392;
    v393 = stack[-1];
    v392 = stack[0];
    v392 = qcdr(v392);
    if (equal(v393, v392)) goto v409;
    v392 = stack[-6];
    fn = elt(env, 20); /* opmtch */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-1] = v392;
    if (v392 == nil) goto v409;
    v392 = stack[-4];
    if (v392 == nil) goto v410;
    v392 = stack[-1];
    fn = elt(env, 19); /* simp */
    v392 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[0] = v392;
    v392 = stack[0];
    v392 = qcar(v392);
    fn = elt(env, 22); /* negf */
    v393 = (*qfn1(fn))(qenv(fn), v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    v392 = stack[0];
    v392 = qcdr(v392);
    popv(8);
    return cons(v393, v392);

v410:
    v392 = stack[-1];
    {
        popv(8);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v392);
    }

v409:
    v392 = stack[-6];
    stack[0] = v392;
    goto v403;

v396:
    v392 = v394;
    if (is_number(v392)) goto v411;
    v392 = v394;
    goto v265;

v411:
    v392 = v394;
    goto v265;

v289:
    v392 = qvalue(elt(env, 4)); /* nil */
    goto v398;

v48:
    v392 = qvalue(elt(env, 4)); /* nil */
    goto v16;

v333:
    v393 = stack[-6];
    v392 = stack[0];
    fn = elt(env, 26); /* valuechk */
    v392 = (*qfn2(fn))(qenv(fn), v393, v392);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-7];
    stack[-5] = v392;
    if (v392 == nil) goto v47;
    else { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
/* error exit handlers */
v395:
    popv(8);
    return nil;
}



/* Code for skp_ordp */

static Lisp_Object CC_skp_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v241, v326;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for skp_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v1;
    v241 = v0;
/* end of prologue */
    v326 = qcar(v241);
    v241 = qcar(v27);
    v27 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v326, v241, v27);
    }
}



/* Code for lpos */

static Lisp_Object CC_lpos(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v30, v332, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpos");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v332 = v1;
    v4 = v0;
/* end of prologue */
    v30 = v4;
    v9 = v332;
    v9 = qcar(v9);
    if (v30 == v9) goto v6;
    v9 = v4;
    v30 = v332;
    v30 = qcdr(v30);
    v9 = CC_lpos(env, v9, v30);
    errexit();
    return add1(v9);

v6:
    v9 = (Lisp_Object)17; /* 1 */
    return onevalue(v9);
}



/* Code for nonlnr */

static Lisp_Object CC_nonlnr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v413;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonlnr");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v316:
    v208 = stack[-1];
    if (!consp(v208)) goto v6;
    v208 = stack[-1];
    v208 = qcar(v208);
    if (!consp(v208)) goto v6;
    v208 = stack[-1];
    v208 = qcar(v208);
    v208 = qcar(v208);
    v413 = qcar(v208);
    v208 = stack[0];
    v208 = Lmember(nil, v413, v208);
    if (v208 == nil) goto v51;
    v208 = stack[-1];
    v208 = qcar(v208);
    v208 = qcar(v208);
    v413 = qcdr(v208);
    v208 = (Lisp_Object)17; /* 1 */
    v208 = (Lisp_Object)greaterp2(v413, v208);
    nil = C_nil;
    if (exception_pending()) goto v414;
    v208 = v208 ? lisp_true : nil;
    env = stack[-2];
    if (!(v208 == nil)) { popv(3); return onevalue(v208); }
    v208 = stack[-1];
    v208 = qcar(v208);
    v413 = qcdr(v208);
    v208 = stack[0];
    fn = elt(env, 2); /* freeofl */
    v208 = (*qfn2(fn))(qenv(fn), v413, v208);
    nil = C_nil;
    if (exception_pending()) goto v414;
    env = stack[-2];
    v208 = (v208 == nil ? lisp_true : nil);
    if (!(v208 == nil)) { popv(3); return onevalue(v208); }
    v208 = stack[-1];
    v413 = qcdr(v208);
    v208 = stack[0];
    stack[-1] = v413;
    stack[0] = v208;
    goto v316;

v51:
    v208 = stack[-1];
    v208 = qcar(v208);
    v208 = qcar(v208);
    v413 = qcar(v208);
    v208 = stack[0];
    fn = elt(env, 2); /* freeofl */
    v208 = (*qfn2(fn))(qenv(fn), v413, v208);
    nil = C_nil;
    if (exception_pending()) goto v414;
    env = stack[-2];
    v208 = (v208 == nil ? lisp_true : nil);
    if (!(v208 == nil)) { popv(3); return onevalue(v208); }
    v208 = stack[-1];
    v208 = qcar(v208);
    v413 = qcdr(v208);
    v208 = stack[0];
    v208 = CC_nonlnr(env, v413, v208);
    nil = C_nil;
    if (exception_pending()) goto v414;
    env = stack[-2];
    if (!(v208 == nil)) { popv(3); return onevalue(v208); }
    v208 = stack[-1];
    v413 = qcdr(v208);
    v208 = stack[0];
    stack[-1] = v413;
    stack[0] = v208;
    goto v316;

v6:
    v208 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v208); }
/* error exit handlers */
v414:
    popv(3);
    return nil;
}



/* Code for ofsf_smcpknowl */

static Lisp_Object CC_ofsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v325, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smcpknowl");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v325 = v0;
/* end of prologue */
    stack[-4] = v325;
    v325 = stack[-4];
    if (v325 == nil) goto v264;
    v325 = stack[-4];
    v325 = qcar(v325);
    v52 = v325;
    v325 = v52;
    stack[0] = qcar(v325);
    v325 = v52;
    v52 = qcdr(v325);
    v325 = qvalue(elt(env, 1)); /* nil */
    v325 = Lappend(nil, v52, v325);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-5];
    v325 = cons(stack[0], v325);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-5];
    v325 = ncons(v325);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-5];
    stack[-2] = v325;
    stack[-3] = v325;
    goto v18;

v18:
    v325 = stack[-4];
    v325 = qcdr(v325);
    stack[-4] = v325;
    v325 = stack[-4];
    if (v325 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v325 = stack[-4];
    v325 = qcar(v325);
    v52 = v325;
    v325 = v52;
    stack[0] = qcar(v325);
    v325 = v52;
    v52 = qcdr(v325);
    v325 = qvalue(elt(env, 1)); /* nil */
    v325 = Lappend(nil, v52, v325);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-5];
    v325 = cons(stack[0], v325);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-5];
    v325 = ncons(v325);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-5];
    v325 = Lrplacd(nil, stack[-1], v325);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-5];
    v325 = stack[-2];
    v325 = qcdr(v325);
    stack[-2] = v325;
    goto v18;

v264:
    v325 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v325); }
/* error exit handlers */
v11:
    popv(6);
    return nil;
}



/* Code for mk!+conjugate!+sq */

static Lisp_Object CC_mkLconjugateLsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+conjugate+sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v169 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* conjsq */
        return (*qfn1(fn))(qenv(fn), v169);
    }
}



/* Code for multiminus */

static Lisp_Object CC_multiminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiminus");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v3 = stack[0];
    v3 = qcar(v3);
    fn = elt(env, 1); /* expression */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    v3 = stack[0];
    v23 = Llength(nil, v3);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    v3 = (Lisp_Object)33; /* 2 */
    if (!(v23 == v3)) goto v7;
    v3 = stack[0];
    v3 = qcdr(v3);
    v3 = qcar(v3);
    fn = elt(env, 1); /* expression */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v24;
    goto v7;

v7:
    v3 = nil;
    { popv(2); return onevalue(v3); }
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for close_forall */

static Lisp_Object MS_CDECL CC_close_forall(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "close_forall");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for close_forall");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* end of prologue */
    v241 = qvalue(elt(env, 1)); /* flagg */
    v27 = (Lisp_Object)17; /* 1 */
    if (!(v241 == v27)) goto v38;
    v27 = elt(env, 2); /* "</apply>" */
    fn = elt(env, 3); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    errexit();
    goto v38;

v38:
    v27 = nil;
    return onevalue(v27);
}



/* Code for degreef */

static Lisp_Object CC_degreef(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v334, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degreef");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v334 = stack[-1];
    if (!consp(v334)) goto v6;
    v334 = stack[-1];
    v334 = qcar(v334);
    if (!consp(v334)) goto v6;
    v334 = stack[-1];
    v334 = qcar(v334);
    v334 = qcar(v334);
    v21 = qcar(v334);
    v334 = stack[0];
    if (v21 == v334) goto v319;
    v334 = stack[-1];
    v334 = qcar(v334);
    v21 = qcdr(v334);
    v334 = stack[0];
    stack[-2] = CC_degreef(env, v21, v334);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-3];
    v334 = stack[-1];
    v21 = qcdr(v334);
    v334 = stack[0];
    v334 = CC_degreef(env, v21, v334);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-3];
    {
        Lisp_Object v220 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* max */
        return (*qfn2(fn))(qenv(fn), v220, v334);
    }

v319:
    v334 = stack[-1];
    v334 = qcar(v334);
    v334 = qcar(v334);
    v334 = qcdr(v334);
    { popv(4); return onevalue(v334); }

v6:
    v334 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v334); }
/* error exit handlers */
v219:
    popv(4);
    return nil;
}



/* Code for a2vdp */

static Lisp_Object CC_a2vdp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v325, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for a2vdp");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v52 = v0;
/* end of prologue */
    v325 = v52;
    v42 = (Lisp_Object)1; /* 0 */
    if (v325 == v42) goto v241;
    v42 = v52;
    if (v42 == nil) goto v241;
    v42 = v52;
    fn = elt(env, 3); /* a2dip */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v325 = v42;
    stack[-2] = elt(env, 1); /* vdp */
    v42 = v325;
    stack[-1] = qcar(v42);
    v42 = v325;
    v42 = qcdr(v42);
    stack[0] = qcar(v42);
    v42 = qvalue(elt(env, 2)); /* nil */
    v42 = list2(v325, v42);
    nil = C_nil;
    if (exception_pending()) goto v207;
    {
        Lisp_Object v10 = stack[-2];
        Lisp_Object v11 = stack[-1];
        Lisp_Object v297 = stack[0];
        popv(4);
        return list3star(v10, v11, v297, v42);
    }

v241:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v325 = qvalue(elt(env, 2)); /* nil */
    v42 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v325, v42);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v325 = qvalue(elt(env, 2)); /* nil */
    v42 = qvalue(elt(env, 2)); /* nil */
    v42 = list2(v325, v42);
    nil = C_nil;
    if (exception_pending()) goto v207;
    {
        Lisp_Object v296 = stack[-2];
        Lisp_Object v295 = stack[-1];
        Lisp_Object v15 = stack[0];
        popv(4);
        return list3star(v296, v295, v15, v42);
    }
/* error exit handlers */
v207:
    popv(4);
    return nil;
}



/* Code for r2speclist1 */

static Lisp_Object CC_r2speclist1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v302, v322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2speclist1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v301 = v0;
/* end of prologue */
    v322 = v301;
    v302 = elt(env, 1); /* times */
    if (!consp(v322)) goto v46;
    v322 = qcar(v322);
    if (!(v322 == v302)) goto v46;
    v302 = v301;
    v302 = qcdr(v302);
    v322 = qcar(v302);
    v302 = v301;
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v301 = qcdr(v301);
    v301 = qcdr(v301);
    v301 = qcdr(v301);
    {
        fn = elt(env, 2); /* r2speclist2 */
        return (*qfnn(fn))(qenv(fn), 3, v322, v302, v301);
    }

v46:
    v302 = (Lisp_Object)17; /* 1 */
    return cons(v302, v301);
}



/* Code for apply_e */

static Lisp_Object CC_apply_e(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for apply_e");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v30 = v9;
    v9 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* apply */
    v30 = (*qfn2(fn))(qenv(fn), v30, v9);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[0];
    v9 = v30;
    v30 = integerp(v30);
    if (!(v30 == nil)) { popv(1); return onevalue(v9); }
    v9 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v9 == nil)) goto v2;
    v9 = elt(env, 3); /* "randpoly expons function must return an integer" 
*/
    fn = elt(env, 5); /* lprie */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[0];
    goto v2;

v2:
    v9 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v332;
    v9 = nil;
    { popv(1); return onevalue(v9); }
/* error exit handlers */
v332:
    popv(1);
    return nil;
}



/* Code for lispcodeexp */

static Lisp_Object CC_lispcodeexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v127, v459;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispcodeexp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-2] = v0;
/* end of prologue */

v316:
    v129 = stack[-2];
    if (is_number(v129)) goto v18;
    v127 = stack[-2];
    v129 = elt(env, 1); /* e */
    if (v127 == v129) goto v46;
    v129 = stack[-2];
    if (!consp(v129)) goto v302;
    v129 = stack[-2];
    v127 = qcar(v129);
    v129 = elt(env, 4); /* (!:rd!: !:cr!: !:crn!: !:gi!:) */
    v129 = Lmemq(nil, v127, v129);
    if (!(v129 == nil)) goto v302;
    v129 = stack[-2];
    v127 = qcar(v129);
    v129 = elt(env, 6); /* expt */
    if (v127 == v129) goto v17;
    v129 = stack[-2];
    v127 = qcar(v129);
    v129 = elt(env, 11); /* quotient */
    if (v127 == v129) goto v460;
    v129 = stack[-2];
    v127 = qcar(v129);
    v129 = elt(env, 14); /* recip */
    if (v127 == v129) goto v461;
    v129 = stack[-2];
    v127 = qcar(v129);
    v129 = elt(env, 16); /* difference */
    if (v127 == v129) goto v462;
    v129 = stack[-2];
    v127 = qcar(v129);
    v129 = qvalue(elt(env, 19)); /* !*lisparithexpops!* */
    v129 = Lmemq(nil, v127, v129);
    if (!(v129 == nil)) goto v138;
    v129 = stack[-2];
    v127 = qcar(v129);
    v129 = qvalue(elt(env, 20)); /* !*lisplogexpops!* */
    v129 = Lmemq(nil, v127, v129);
    if (!(v129 == nil)) goto v138;
    v129 = stack[-2];
    stack[-3] = v129;
    v129 = stack[-3];
    if (v129 == nil) goto v463;
    v129 = stack[-3];
    v129 = qcar(v129);
    v127 = v129;
    v129 = qvalue(elt(env, 12)); /* nil */
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    stack[-1] = v129;
    stack[-2] = v129;
    goto v151;

v151:
    v129 = stack[-3];
    v129 = qcdr(v129);
    stack[-3] = v129;
    v129 = stack[-3];
    if (v129 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v129 = stack[-3];
    v129 = qcar(v129);
    v127 = v129;
    v129 = qvalue(elt(env, 12)); /* nil */
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = Lrplacd(nil, stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v151;

v463:
    v129 = qvalue(elt(env, 12)); /* nil */
    { popv(6); return onevalue(v129); }

v138:
    v129 = stack[-2];
    stack[-4] = v129;
    v129 = stack[-4];
    if (v129 == nil) goto v465;
    v129 = stack[-4];
    v129 = qcar(v129);
    v127 = v129;
    v129 = stack[-3];
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    stack[-1] = v129;
    stack[-2] = v129;
    goto v466;

v466:
    v129 = stack[-4];
    v129 = qcdr(v129);
    stack[-4] = v129;
    v129 = stack[-4];
    if (v129 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v129 = stack[-4];
    v129 = qcar(v129);
    v127 = v129;
    v129 = stack[-3];
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = Lrplacd(nil, stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v466;

v465:
    v129 = qvalue(elt(env, 12)); /* nil */
    { popv(6); return onevalue(v129); }

v462:
    stack[-4] = elt(env, 17); /* plus */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    stack[0] = elt(env, 18); /* minus */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = stack[-3];
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = list2(stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    {
        Lisp_Object v467 = stack[-4];
        Lisp_Object v468 = stack[-1];
        popv(6);
        return list3(v467, v468, v129);
    }

v461:
    v129 = qvalue(elt(env, 15)); /* !*period */
    if (v129 == nil) goto v469;
    stack[-1] = elt(env, 11); /* quotient */
    stack[0] = elt(env, 3); /* 1.0 */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = stack[-3];
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    {
        Lisp_Object v470 = stack[-1];
        Lisp_Object v471 = stack[0];
        popv(6);
        return list3(v470, v471, v129);
    }

v469:
    stack[-1] = elt(env, 11); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = stack[-3];
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    {
        Lisp_Object v472 = stack[-1];
        Lisp_Object v123 = stack[0];
        popv(6);
        return list3(v472, v123, v129);
    }

v460:
    stack[-1] = elt(env, 11); /* quotient */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = qvalue(elt(env, 13)); /* t */
    stack[0] = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = stack[-2];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = qvalue(elt(env, 13)); /* t */
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    {
        Lisp_Object v473 = stack[-1];
        Lisp_Object v474 = stack[0];
        popv(6);
        return list3(v473, v474, v129);
    }

v17:
    v129 = stack[-2];
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = elt(env, 1); /* e */
    if (v127 == v129) goto v414;
    v129 = stack[-2];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = elt(env, 7); /* (quotient 1 2) */
    if (equal(v127, v129)) goto v203;
    v129 = stack[-2];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = elt(env, 9); /* !:rd!: */
    if (!consp(v127)) goto v475;
    v127 = qcar(v127);
    if (!(v127 == v129)) goto v475;
    v129 = stack[-2];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v129 = qcar(v129);
    fn = elt(env, 21); /* realrat */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    stack[-1] = v129;
    v127 = stack[-1];
    v129 = elt(env, 10); /* (1 . 2) */
    if (equal(v127, v129)) goto v234;
    stack[0] = elt(env, 6); /* expt */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = stack[-3];
    stack[-2] = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v459 = elt(env, 11); /* quotient */
    v129 = stack[-1];
    v127 = qcar(v129);
    v129 = stack[-1];
    v129 = qcdr(v129);
    v127 = list3(v459, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = qvalue(elt(env, 12)); /* nil */
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    {
        Lisp_Object v476 = stack[0];
        Lisp_Object v477 = stack[-2];
        popv(6);
        return list3(v476, v477, v129);
    }

v234:
    stack[0] = elt(env, 8); /* sqrt */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = stack[-3];
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    {
        Lisp_Object v478 = stack[0];
        popv(6);
        return list2(v478, v129);
    }

v475:
    stack[0] = elt(env, 6); /* expt */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = stack[-2];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v127 = qcar(v129);
    v129 = qvalue(elt(env, 12)); /* nil */
    v129 = CC_lispcodeexp(env, v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    {
        Lisp_Object v479 = stack[0];
        Lisp_Object v116 = stack[-1];
        popv(6);
        return list3(v479, v116, v129);
    }

v203:
    v127 = elt(env, 8); /* sqrt */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v129 = qcar(v129);
    v127 = list2(v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = stack[-3];
    stack[-2] = v127;
    stack[-3] = v129;
    goto v316;

v414:
    v127 = elt(env, 2); /* exp */
    v129 = stack[-2];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v129 = qcar(v129);
    v127 = list2(v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = stack[-3];
    stack[-2] = v127;
    stack[-3] = v129;
    goto v316;

v302:
    v129 = qvalue(elt(env, 5)); /* irena!-constants */
    if (v129 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v129 = stack[-2];
    if (v129 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v129 = stack[-2];
    v129 = Lstringp(nil, v129);
    env = stack[-5];
    if (!(v129 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v129 = stack[-2];
    fn = elt(env, 22); /* check!-for!-irena!-constants */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v46:
    v127 = elt(env, 2); /* exp */
    v129 = elt(env, 3); /* 1.0 */
    v127 = list2(v127, v129);
    nil = C_nil;
    if (exception_pending()) goto v464;
    env = stack[-5];
    v129 = stack[-3];
    stack[-2] = v127;
    stack[-3] = v129;
    goto v316;

v18:
    v129 = stack[-3];
    if (v129 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v129 = stack[-2];
        popv(6);
        return Lfloat(nil, v129);
/* error exit handlers */
v464:
    popv(6);
    return nil;
}



/* Code for ofsf_negateat */

static Lisp_Object CC_ofsf_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v28, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_negateat");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v5 = stack[0];
    v5 = qcdr(v5);
    v28 = qcar(v5);
    v5 = stack[0];
    v5 = qcdr(v5);
    v5 = qcdr(v5);
    v5 = qcar(v5);
    v5 = list2(v28, v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    stack[-1] = v5;
    v5 = stack[0];
    v5 = qcar(v5);
    fn = elt(env, 1); /* ofsf_lnegrel */
    v221 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v5 = stack[-1];
    v28 = qcar(v5);
    v5 = stack[-1];
    v5 = qcdr(v5);
    v5 = qcar(v5);
    popv(3);
    return list3(v221, v28, v5);
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



setup_type const u30_setup[] =
{
    {"testord",                 too_few_2,      CC_testord,    wrong_no_2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,too_many_1,   wrong_no_1},
    {"aex_0",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_0},
    {"bvarrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_bvarrd},
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"simpimpart",              CC_simpimpart,  too_many_1,    wrong_no_1},
    {"extbrsea",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_extbrsea},
    {"f2dip11",                 CC_f2dip11,     too_many_1,    wrong_no_1},
    {"indordl2",                too_few_2,      CC_indordl2,   wrong_no_2},
    {"contr2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_contr2},
    {"remchkf1",                too_few_2,      CC_remchkf1,   wrong_no_2},
    {"harmonicp",               CC_harmonicp,   too_many_1,    wrong_no_1},
    {"dp_neworder",             CC_dp_neworder, too_many_1,    wrong_no_1},
    {"multerm",                 too_few_2,      CC_multerm,    wrong_no_2},
    {"tayfkern",                CC_tayfkern,    too_many_1,    wrong_no_1},
    {"mk+squared+norm",         CC_mkLsquaredLnorm,too_many_1, wrong_no_1},
    {"cl_susiinter",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiinter},
    {"ratpoly_0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_0},
    {"minusml",                 CC_minusml,     too_many_1,    wrong_no_1},
    {"maxl",                    CC_maxl,        too_many_1,    wrong_no_1},
    {"remzzzz",                 too_few_2,      CC_remzzzz,    wrong_no_2},
    {"dipequal",                too_few_2,      CC_dipequal,   wrong_no_2},
    {"evinsert",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evinsert},
    {"getrlist",                CC_getrlist,    too_many_1,    wrong_no_1},
    {"reduce",                  too_few_2,      CC_reduce,     wrong_no_2},
    {"sqprint",                 CC_sqprint,     too_many_1,    wrong_no_1},
    {"simpiden",                CC_simpiden,    too_many_1,    wrong_no_1},
    {"skp_ordp",                too_few_2,      CC_skp_ordp,   wrong_no_2},
    {"lpos",                    too_few_2,      CC_lpos,       wrong_no_2},
    {"nonlnr",                  too_few_2,      CC_nonlnr,     wrong_no_2},
    {"ofsf_smcpknowl",          CC_ofsf_smcpknowl,too_many_1,  wrong_no_1},
    {"mk+conjugate+sq",         CC_mkLconjugateLsq,too_many_1, wrong_no_1},
    {"multiminus",              CC_multiminus,  too_many_1,    wrong_no_1},
    {"close_forall",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_close_forall},
    {"degreef",                 too_few_2,      CC_degreef,    wrong_no_2},
    {"a2vdp",                   CC_a2vdp,       too_many_1,    wrong_no_1},
    {"r2speclist1",             CC_r2speclist1, too_many_1,    wrong_no_1},
    {"apply_e",                 CC_apply_e,     too_many_1,    wrong_no_1},
    {"lispcodeexp",             too_few_2,      CC_lispcodeexp,wrong_no_2},
    {"ofsf_negateat",           CC_ofsf_negateat,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u30", (two_args *)"19661 8045168 3301462", 0}
};

/* end of generated code */
