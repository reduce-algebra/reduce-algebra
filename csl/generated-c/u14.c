
/* $destdir\u14.c        Machine generated C code */

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


/* Code for getmatelem */

static Lisp_Object CC_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getmatelem");
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
    stack[-1] = v0;
/* end of prologue */

v36:
    v33 = stack[-1];
    v34 = Llength(nil, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v33 = (Lisp_Object)49; /* 3 */
    if (v34 == v33) goto v38;
    v34 = stack[-1];
    v33 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 11); /* typerr */
    v33 = (*qfn2(fn))(qenv(fn), v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v38;

v38:
    v33 = stack[-1];
    v34 = qcar(v33);
    v33 = elt(env, 2); /* avalue */
    v33 = get(v34, v33);
    env = stack[-3];
    stack[-2] = v33;
    v33 = stack[-2];
    if (v33 == nil) goto v39;
    v33 = stack[-2];
    v34 = qcar(v33);
    v33 = elt(env, 3); /* matrix */
    if (!(v34 == v33)) goto v39;
    v33 = stack[-2];
    v33 = qcdr(v33);
    v34 = qcar(v33);
    stack[-2] = v34;
    v33 = elt(env, 5); /* mat */
    if (!consp(v34)) goto v40;
    v34 = qcar(v34);
    if (!(v34 == v33)) goto v40;

v41:
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = qcar(v33);
    fn = elt(env, 12); /* reval_without_mod */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    stack[0] = v33;
    v33 = stack[0];
    v33 = integerp(v33);
    if (v33 == nil) goto v42;
    v34 = stack[0];
    v33 = (Lisp_Object)1; /* 0 */
    v33 = (Lisp_Object)lesseq2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v33 = v33 ? lisp_true : nil;
    env = stack[-3];
    if (!(v33 == nil)) goto v42;

v43:
    v33 = stack[-2];
    v34 = qcdr(v33);
    v33 = stack[0];
    fn = elt(env, 13); /* pnth */
    v33 = (*qfn2(fn))(qenv(fn), v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v33 = qcar(v33);
    stack[-2] = v33;
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    v33 = qcar(v33);
    fn = elt(env, 12); /* reval_without_mod */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    stack[0] = v33;
    v33 = stack[0];
    v33 = integerp(v33);
    if (v33 == nil) goto v44;
    v34 = stack[0];
    v33 = (Lisp_Object)1; /* 0 */
    v33 = (Lisp_Object)lesseq2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v33 = v33 ? lisp_true : nil;
    env = stack[-3];
    if (!(v33 == nil)) goto v44;

v45:
    v34 = stack[-2];
    v33 = stack[0];
    fn = elt(env, 13); /* pnth */
    v33 = (*qfn2(fn))(qenv(fn), v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v33 = qcar(v33);
    { popv(4); return onevalue(v33); }

v44:
    v34 = stack[0];
    v33 = elt(env, 10); /* "positive integer" */
    fn = elt(env, 11); /* typerr */
    v33 = (*qfn2(fn))(qenv(fn), v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v45;

v42:
    v34 = stack[0];
    v33 = elt(env, 10); /* "positive integer" */
    fn = elt(env, 11); /* typerr */
    v33 = (*qfn2(fn))(qenv(fn), v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v43;

v40:
    v33 = stack[-2];
    if (symbolp(v33)) goto v46;
    v35 = elt(env, 6); /* "Matrix" */
    v33 = stack[-1];
    v34 = qcar(v33);
    v33 = elt(env, 7); /* "not set" */
    v33 = list3(v35, v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v34 = v33;
    v33 = v34;
    qvalue(elt(env, 8)) = v33; /* errmsg!* */
    v33 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v33 == nil)) goto v47;
    v33 = v34;
    fn = elt(env, 14); /* lprie */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v47;

v47:
    v33 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v41;

v46:
    v34 = stack[-2];
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = cons(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    stack[-1] = v33;
    goto v36;

v39:
    v33 = stack[-1];
    v34 = qcar(v33);
    v33 = elt(env, 4); /* "matrix" */
    fn = elt(env, 11); /* typerr */
    v33 = (*qfn2(fn))(qenv(fn), v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v41;
/* error exit handlers */
v37:
    popv(4);
    return nil;
}



/* Code for nzeros */

static Lisp_Object CC_nzeros(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzeros");
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
    goto v36;

v36:
    v51 = stack[0];
    v50 = (Lisp_Object)1; /* 0 */
    if (v51 == v50) goto v52;
    v51 = (Lisp_Object)1; /* 0 */
    v50 = stack[-1];
    v50 = cons(v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    stack[-1] = v50;
    v50 = stack[0];
    v50 = sub1(v50);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    stack[0] = v50;
    goto v36;

v52:
    v50 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v50);
    }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for dp_times_bcmo */

static Lisp_Object MS_CDECL CC_dp_times_bcmo(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v54,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dp_times_bcmo");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bcmo");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v54,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v66 = v4;
    stack[-5] = v54;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = v66;
    v66 = stack[-7];
    if (v66 == nil) goto v68;
    v66 = stack[-7];
    v66 = qcar(v66);
    stack[-1] = v66;
    v67 = stack[-5];
    v66 = stack[-1];
    v66 = qcar(v66);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    v67 = stack[-6];
    v66 = stack[-1];
    v66 = qcdr(v66);
    fn = elt(env, 3); /* bc_prod */
    v66 = (*qfn2(fn))(qenv(fn), v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    v66 = cons(stack[0], v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    v66 = ncons(v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    stack[-3] = v66;
    stack[-4] = v66;
    goto v69;

v69:
    v66 = stack[-7];
    v66 = qcdr(v66);
    stack[-7] = v66;
    v66 = stack[-7];
    if (v66 == nil) { Lisp_Object res = stack[-4]; popv(9); return onevalue(res); }
    stack[-2] = stack[-3];
    v66 = stack[-7];
    v66 = qcar(v66);
    stack[-1] = v66;
    v67 = stack[-5];
    v66 = stack[-1];
    v66 = qcar(v66);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    v67 = stack[-6];
    v66 = stack[-1];
    v66 = qcdr(v66);
    fn = elt(env, 3); /* bc_prod */
    v66 = (*qfn2(fn))(qenv(fn), v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    v66 = cons(stack[0], v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    v66 = ncons(v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    v66 = Lrplacd(nil, stack[-2], v66);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-8];
    v66 = stack[-3];
    v66 = qcdr(v66);
    stack[-3] = v66;
    goto v69;

v68:
    v66 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v66); }
/* error exit handlers */
v15:
    popv(9);
    return nil;
}



/* Code for eqdummy */

static Lisp_Object CC_eqdummy(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v41, v72;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eqdummy");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v53 = v54;
    v72 = v0;
/* end of prologue */
    v41 = v72;
    if (v41 == nil) goto v62;
    v41 = elt(env, 2); /* dummy */
    v41 = get(v72, v41);
    env = stack[0];
    v72 = qcar(v41);
    v41 = v53;
    v53 = elt(env, 2); /* dummy */
    v53 = get(v41, v53);
    v53 = qcar(v53);
    v53 = (v72 == v53 ? lisp_true : nil);
    { popv(1); return onevalue(v53); }

v62:
    v53 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v53); }
}



/* Code for primep */

static Lisp_Object CC_primep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for primep");
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

v60:
    v85 = stack[0];
    v85 = integerp(v85);
    if (v85 == nil) goto v87;
    v86 = stack[0];
    v85 = (Lisp_Object)1; /* 0 */
    v85 = (Lisp_Object)lessp2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v27;
    v85 = stack[0];
    v85 = negate(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    stack[0] = v85;
    goto v60;

v27:
    v86 = stack[0];
    v85 = (Lisp_Object)17; /* 1 */
    if (v86 == v85) goto v50;
    v86 = stack[0];
    v85 = qvalue(elt(env, 3)); /* !*last!-prime!-in!-list!* */
    v85 = (Lisp_Object)lesseq2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v89;
    v85 = stack[0];
    v86 = qvalue(elt(env, 4)); /* !*primelist!* */
    v85 = Lmember(nil, v85, v86);
    { popv(3); return onevalue(v85); }

v89:
    v86 = stack[0];
    v85 = qvalue(elt(env, 5)); /* !*last!-prime!-squared!* */
    v85 = (Lisp_Object)lesseq2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v90;
    v85 = qvalue(elt(env, 4)); /* !*primelist!* */
    stack[-1] = v85;
    goto v91;

v91:
    v85 = stack[-1];
    if (v85 == nil) goto v92;
    v86 = stack[0];
    v85 = stack[-1];
    v85 = qcar(v85);
    v86 = Cremainder(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    v85 = (Lisp_Object)1; /* 0 */
    if (v86 == v85) goto v92;
    v85 = stack[-1];
    v85 = qcdr(v85);
    stack[-1] = v85;
    goto v91;

v92:
    v85 = stack[-1];
    v85 = (v85 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v85); }

v90:
    v86 = stack[0];
    v85 = qvalue(elt(env, 6)); /* largest!-small!-modulus */
    v85 = (Lisp_Object)greaterp2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v93;
    v85 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* general!-primep */
        return (*qfn1(fn))(qenv(fn), v85);
    }

v93:
    v85 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* small!-primep */
        return (*qfn1(fn))(qenv(fn), v85);
    }

v50:
    v85 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v85); }

v87:
    v86 = stack[0];
    v85 = elt(env, 1); /* "integer" */
    {
        popv(3);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v86, v85);
    }
/* error exit handlers */
v88:
    popv(3);
    return nil;
}



/* Code for degree!-in!-variable */

static Lisp_Object CC_degreeKinKvariable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degree-in-variable");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v54;
    stack[-1] = v0;
/* end of prologue */
    v22 = stack[-1];
    if (!consp(v22)) goto v62;
    v22 = stack[-1];
    v22 = qcar(v22);
    if (!consp(v22)) goto v62;
    v22 = stack[-1];
    v22 = qcar(v22);
    v21 = qcdr(v22);
    v22 = (Lisp_Object)1; /* 0 */
    if (v21 == v22) goto v68;
    v21 = stack[0];
    v22 = stack[-1];
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcar(v22);
    if (equal(v21, v22)) goto v94;
    v22 = stack[-1];
    v22 = qcar(v22);
    v21 = qcdr(v22);
    v22 = stack[0];
    stack[-2] = CC_degreeKinKvariable(env, v21, v22);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    v22 = stack[-1];
    v21 = qcdr(v22);
    v22 = stack[0];
    v22 = CC_degreeKinKvariable(env, v21, v22);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    {
        Lisp_Object v91 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* max */
        return (*qfn2(fn))(qenv(fn), v91, v22);
    }

v94:
    v22 = stack[-1];
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    { popv(4); return onevalue(v22); }

v68:
    v22 = elt(env, 1); /* "Polynomial with a zero coefficient found" */
    {
        popv(4);
        fn = elt(env, 3); /* errorf */
        return (*qfn1(fn))(qenv(fn), v22);
    }

v62:
    v22 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v22); }
/* error exit handlers */
v92:
    popv(4);
    return nil;
}



/* Code for freeofl */

static Lisp_Object CC_freeofl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v97, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofl");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v54;
    stack[-1] = v0;
/* end of prologue */

v99:
    v39 = stack[0];
    v39 = (v39 == nil ? lisp_true : nil);
    if (!(v39 == nil)) { popv(3); return onevalue(v39); }
    v39 = stack[0];
    v97 = qcar(v39);
    v39 = stack[-1];
    fn = elt(env, 3); /* smember */
    v39 = (*qfn2(fn))(qenv(fn), v97, v39);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    if (!(v39 == nil)) goto v36;
    v39 = stack[0];
    v98 = qcar(v39);
    v97 = stack[-1];
    v39 = qvalue(elt(env, 1)); /* depl!* */
    v39 = Lassoc(nil, v97, v39);
    v39 = Lmember(nil, v98, v39);
    if (!(v39 == nil)) goto v36;
    v97 = stack[-1];
    v39 = stack[0];
    v39 = qcdr(v39);
    stack[-1] = v97;
    stack[0] = v39;
    goto v99;

v36:
    v39 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v39); }
/* error exit handlers */
v80:
    popv(3);
    return nil;
}



/* Code for rl_simp */

static Lisp_Object CC_rl_simp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simp");
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
    v62 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_simp1 */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* rl_csimpl */
        return (*qfn1(fn))(qenv(fn), v62);
    }
/* error exit handlers */
v61:
    popv(1);
    return nil;
}



/* Code for qqe_ofsf_simplat1 */

static Lisp_Object CC_qqe_ofsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v54;
    stack[-1] = v0;
/* end of prologue */
    v102 = stack[-1];
    v101 = stack[0];
    fn = elt(env, 2); /* qqe_simplat1 */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v101;
    v102 = stack[-2];
    v101 = elt(env, 1); /* (true false) */
    v101 = Lmemq(nil, v102, v101);
    if (!(v101 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v101 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    fn = elt(env, 4); /* qqe_rqopp */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    if (!(v101 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v102 = stack[-2];
    v101 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ofsf_simplat1 */
        return (*qfn2(fn))(qenv(fn), v102, v101);
    }
/* error exit handlers */
v103:
    popv(4);
    return nil;
}



/* Code for image!-of!-power */

static Lisp_Object CC_imageKofKpower(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v103, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for image-of-power");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v54;
    stack[-1] = v0;
/* end of prologue */
    v103 = stack[-1];
    v64 = qvalue(elt(env, 1)); /* image!-set */
    v64 = Lassoc(nil, v103, v64);
    stack[-2] = v64;
    v64 = stack[-2];
    if (v64 == nil) goto v49;
    v64 = stack[-2];
    v64 = qcdr(v64);
    stack[-2] = v64;
    goto v72;

v72:
    v103 = stack[-2];
    v64 = stack[0];
        popv(4);
        return Lmodular_expt(nil, v103, v64);

v49:
    fn = elt(env, 2); /* next!-random!-number */
    v64 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    v64 = Lmodular_number(nil, v64);
    env = stack[-3];
    stack[-2] = v64;
    v106 = stack[-1];
    v103 = stack[-2];
    v64 = qvalue(elt(env, 1)); /* image!-set */
    v64 = acons(v106, v103, v64);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    qvalue(elt(env, 1)) = v64; /* image!-set */
    goto v72;
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for constsml */

static Lisp_Object CC_constsml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constsml");
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
    v108 = stack[0];
    if (!(is_number(v108))) goto v62;
    v108 = elt(env, 1); /* "<cn" */
    fn = elt(env, 13); /* printout */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v108 = stack[0];
    v108 = Lfloatp(nil, v108);
    env = stack[-1];
    if (v108 == nil) goto v109;
    v108 = elt(env, 2); /* " type=""real""> " */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    goto v87;

v87:
    v108 = stack[0];
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v108 = elt(env, 5); /* " </cn>" */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    goto v62;

v62:
    v108 = stack[0];
    if (!(symbolp(v108))) goto v28;
    v108 = stack[0];
    v20 = Lintern(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v108 = qvalue(elt(env, 6)); /* constants!* */
    v108 = Lmember(nil, v20, v108);
    if (v108 == nil) goto v23;
    v108 = elt(env, 7); /* "<cn type=""constant""> " */
    fn = elt(env, 13); /* printout */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v108 = stack[0];
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v108 = elt(env, 5); /* " </cn>" */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    goto v28;

v28:
    v108 = nil;
    { popv(2); return onevalue(v108); }

v23:
    v108 = elt(env, 8); /* "<ci" */
    fn = elt(env, 13); /* printout */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v108 = stack[0];
    fn = elt(env, 14); /* listp */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    if (v108 == nil) goto v110;
    v108 = elt(env, 9); /* " type=""list""> " */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    goto v89;

v89:
    v108 = stack[0];
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v108 = elt(env, 11); /* " </ci>" */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    goto v28;

v110:
    v108 = stack[0];
    v108 = Lsimple_vectorp(nil, v108);
    env = stack[-1];
    if (v108 == nil) goto v91;
    v108 = elt(env, 10); /* " type=""vector""> " */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    goto v89;

v91:
    v108 = elt(env, 4); /* "> " */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    goto v89;

v109:
    v108 = stack[0];
    v108 = integerp(v108);
    if (v108 == nil) goto v30;
    v108 = elt(env, 3); /* " type=""integer""> " */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    goto v87;

v30:
    v108 = elt(env, 4); /* "> " */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    goto v87;
/* error exit handlers */
v57:
    popv(2);
    return nil;
}



/* Code for subs4q */

static Lisp_Object CC_subs4q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v130, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs4q");
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
    stack[-5] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v130 = elt(env, 1); /* slash */
    v129 = elt(env, 2); /* opmtch */
    v129 = get(v130, v129);
    env = stack[-7];
    stack[-6] = v129;
    if (v129 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v129 = stack[-5];
    v129 = qcar(v129);
    if (v129 == nil) goto v71;
    v130 = stack[-5];
    v129 = elt(env, 3); /* prepf */
    fn = elt(env, 8); /* sqform */
    v129 = (*qfn2(fn))(qenv(fn), v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    goto v70;

v70:
    stack[-4] = v129;
    v130 = elt(env, 1); /* slash */
    v129 = elt(env, 2); /* opmtch */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-7];
    v7 = elt(env, 4); /* slash!* */
    v130 = elt(env, 2); /* opmtch */
    v129 = stack[-6];
    v129 = Lputprop(nil, 3, v7, v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    goto v40;

v40:
    v129 = stack[-4];
    if (v129 == nil) goto v24;
    v130 = stack[-4];
    stack[-3] = v130;
    v129 = elt(env, 5); /* quotient */
    if (!consp(v130)) goto v24;
    v130 = qcar(v130);
    if (!(v130 == v129)) goto v24;
    v130 = elt(env, 4); /* slash!* */
    v129 = stack[-4];
    v129 = qcdr(v129);
    v129 = cons(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    fn = elt(env, 2); /* opmtch */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    if (!(v129 == nil)) goto v131;
    v130 = elt(env, 7); /* minus */
    v129 = stack[-4];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v129 = qcar(v129);
    v129 = Lsmemq(nil, v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    if (v129 == nil) goto v67;
    stack[-1] = elt(env, 4); /* slash!* */
    v130 = elt(env, 7); /* minus */
    v129 = stack[-4];
    v129 = qcdr(v129);
    v129 = qcar(v129);
    v129 = list2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    fn = elt(env, 9); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    v130 = elt(env, 7); /* minus */
    v129 = stack[-4];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v129 = qcar(v129);
    v129 = list2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    fn = elt(env, 9); /* reval */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    v129 = list3(stack[-1], stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    fn = elt(env, 2); /* opmtch */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    goto v131;

v131:
    stack[-4] = v129;
    v129 = stack[-2];
    if (!(v129 == nil)) goto v43;
    v129 = stack[-4];
    goto v43;

v43:
    stack[-2] = v129;
    goto v40;

v67:
    v129 = qvalue(elt(env, 6)); /* nil */
    goto v131;

v24:
    v129 = stack[-2];
    if (v129 == nil) goto v132;
    v129 = stack[-3];
    fn = elt(env, 10); /* simp!* */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    goto v133;

v133:
    stack[-5] = v129;
    v7 = elt(env, 1); /* slash */
    v130 = elt(env, 2); /* opmtch */
    v129 = stack[-6];
    v129 = Lputprop(nil, 3, v7, v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v5;
    { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v132:
    v129 = stack[-5];
    goto v133;

v71:
    v129 = (Lisp_Object)1; /* 0 */
    goto v70;
/* error exit handlers */
v5:
    popv(8);
    return nil;
}



/* Code for opmtch */

static Lisp_Object CC_opmtch(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v147, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtch");
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
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    v146 = stack[-6];
    v147 = qcar(v146);
    v146 = elt(env, 0); /* opmtch */
    v146 = get(v147, v146);
    env = stack[-8];
    stack[-5] = v146;
    if (v146 == nil) goto v68;
    v146 = qvalue(elt(env, 2)); /* subfg!* */
    if (v146 == nil) goto v30;
    v146 = qvalue(elt(env, 3)); /* !*uncached */
    if (!(v146 == nil)) goto v87;
    v147 = stack[-6];
    v146 = qvalue(elt(env, 4)); /* alglist!* */
    v146 = qcdr(v146);
    v146 = Lassoc(nil, v147, v146);
    stack[-7] = v146;
    if (v146 == nil) goto v87;
    v146 = stack[-7];
    v146 = qcdr(v146);
    { popv(9); return onevalue(v146); }

v87:
    v146 = stack[-6];
    v146 = qcdr(v146);
    stack[-4] = v146;
    v146 = stack[-4];
    if (v146 == nil) goto v124;
    v146 = stack[-4];
    v146 = qcar(v146);
    stack[0] = v146;
    v146 = stack[0];
    if (!consp(v146)) goto v149;
    v146 = stack[0];
    v146 = CC_opmtch(env, v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    v147 = v146;
    v146 = v147;
    if (v146 == nil) goto v151;
    v146 = v147;
    goto v110;

v110:
    v146 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    stack[-2] = v146;
    stack[-3] = v146;
    goto v81;

v81:
    v146 = stack[-4];
    v146 = qcdr(v146);
    stack[-4] = v146;
    v146 = stack[-4];
    if (v146 == nil) goto v57;
    stack[-1] = stack[-2];
    v146 = stack[-4];
    v146 = qcar(v146);
    stack[0] = v146;
    v146 = stack[0];
    if (!consp(v146)) goto v152;
    v146 = stack[0];
    v146 = CC_opmtch(env, v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    v147 = v146;
    v146 = v147;
    if (v146 == nil) goto v85;
    v146 = v147;
    goto v121;

v121:
    v146 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    v146 = Lrplacd(nil, stack[-1], v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    v146 = stack[-2];
    v146 = qcdr(v146);
    stack[-2] = v146;
    goto v81;

v85:
    v146 = stack[0];
    goto v121;

v152:
    v146 = stack[0];
    goto v121;

v57:
    v146 = stack[-3];
    goto v26;

v26:
    stack[0] = v146;
    goto v52;

v52:
    v146 = stack[-5];
    if (v146 == nil) goto v36;
    v148 = stack[0];
    v146 = stack[-5];
    v146 = qcar(v146);
    v147 = qcar(v146);
    v146 = stack[-6];
    v146 = qcar(v146);
    fn = elt(env, 5); /* mcharg */
    v146 = (*qfnn(fn))(qenv(fn), 3, v148, v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    stack[-1] = v146;
    goto v69;

v69:
    v146 = stack[-1];
    if (v146 == nil) goto v114;
    v146 = stack[-1];
    v147 = qcar(v146);
    v146 = stack[-5];
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = Lsubla(nil, v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    fn = elt(env, 6); /* eval */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    if (v146 == nil) goto v153;
    v146 = stack[-1];
    v147 = qcar(v146);
    v146 = stack[-5];
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    v146 = Lsubla(nil, v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    stack[-7] = v146;
    goto v36;

v36:
    v146 = qvalue(elt(env, 3)); /* !*uncached */
    if (!(v146 == nil)) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    stack[0] = qvalue(elt(env, 4)); /* alglist!* */
    v148 = stack[-6];
    v147 = stack[-7];
    v146 = qvalue(elt(env, 4)); /* alglist!* */
    v146 = qcdr(v146);
    v146 = acons(v148, v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    v146 = Lrplacd(nil, stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v150;
    { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }

v153:
    v146 = stack[-1];
    v146 = qcdr(v146);
    stack[-1] = v146;
    goto v69;

v114:
    v146 = stack[-5];
    v146 = qcdr(v146);
    stack[-5] = v146;
    goto v52;

v151:
    v146 = stack[0];
    goto v110;

v149:
    v146 = stack[0];
    goto v110;

v124:
    v146 = qvalue(elt(env, 1)); /* nil */
    goto v26;

v30:
    v146 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v146); }

v68:
    v146 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v146); }
/* error exit handlers */
v150:
    popv(9);
    return nil;
}



/* Code for evaluate1 */

static Lisp_Object CC_evaluate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v159, v153, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate1");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v159 = v54;
    v153 = v0;
/* end of prologue */
    v141 = v153;
    if (is_number(v141)) goto v62;
    v141 = v153;
    if (v141 == nil) goto v62;
    v141 = v153;
    v141 = Lconsp(nil, v141);
    env = stack[0];
    if (v141 == nil) goto v50;
    v141 = v153;
    v114 = qcar(v141);
    v141 = elt(env, 1); /* dname */
    v141 = get(v114, v141);
    env = stack[0];
    if (!(v141 == nil)) { popv(1); return onevalue(v153); }

v50:
    v114 = v153;
    v141 = v159;
    v141 = Lassoc(nil, v114, v141);
    v114 = v141;
    v141 = v114;
    if (v141 == nil) goto v104;
    v141 = v114;
    v141 = qcdr(v141);
    { popv(1); return onevalue(v141); }

v104:
    v141 = v153;
    if (!consp(v141)) goto v125;
    v141 = v153;
    v141 = qcar(v141);
    v153 = qcdr(v153);
    {
        popv(1);
        fn = elt(env, 13); /* evaluate2 */
        return (*qfnn(fn))(qenv(fn), 3, v141, v153, v159);
    }

v125:
    v159 = v153;
    v141 = elt(env, 2); /* i */
    if (v159 == v141) goto v160;
    v159 = v153;
    v141 = elt(env, 8); /* e */
    if (v159 == v141) goto v77;
    v159 = v153;
    v141 = elt(env, 9); /* pi */
    if (v159 == v141) goto v77;
    v141 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 11)) = v141; /* !*evaluateerror */
    v159 = v153;
    v141 = elt(env, 12); /* "number" */
    {
        popv(1);
        fn = elt(env, 14); /* typerr */
        return (*qfn2(fn))(qenv(fn), v159, v141);
    }

v77:
    v141 = v153;
    fn = elt(env, 15); /* simp */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[0];
    v141 = qcar(v141);
    {
        popv(1);
        fn = elt(env, 16); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v141);
    }

v160:
    v159 = qvalue(elt(env, 3)); /* dmode!* */
    v141 = elt(env, 4); /* ivalue */
    v141 = get(v159, v141);
    env = stack[0];
    v153 = v141;
    if (v141 == nil) goto v161;
    v159 = v153;
    v141 = elt(env, 5); /* (nil) */
    fn = elt(env, 17); /* apply */
    v141 = (*qfn2(fn))(qenv(fn), v159, v141);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v141 = qcar(v141);
    { popv(1); return onevalue(v141); }

v161:
    v141 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v141 == nil)) goto v57;
    v141 = elt(env, 7); /* "i used as indeterminate value" */
    fn = elt(env, 18); /* lprie */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[0];
    goto v57;

v57:
    v141 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v141 = nil;
    { popv(1); return onevalue(v141); }

v62:
    v141 = v153;
    {
        popv(1);
        fn = elt(env, 16); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v141);
    }
/* error exit handlers */
v133:
    popv(1);
    return nil;
}



/* Code for procstat */

static Lisp_Object MS_CDECL CC_procstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "procstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for procstat");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v3 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* procstat1 */
        return (*qfn1(fn))(qenv(fn), v3);
    }
}



/* Code for dp_neg */

static Lisp_Object CC_dp_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neg");
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
    v89 = v0;
/* end of prologue */
    stack[-4] = v89;
    v89 = stack[-4];
    if (v89 == nil) goto v100;
    v89 = stack[-4];
    v89 = qcar(v89);
    v58 = v89;
    v89 = v58;
    stack[0] = qcar(v89);
    v89 = v58;
    v89 = qcdr(v89);
    fn = elt(env, 2); /* bc_neg */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v89 = cons(stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v89 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    stack[-2] = v89;
    stack[-3] = v89;
    goto v162;

v162:
    v89 = stack[-4];
    v89 = qcdr(v89);
    stack[-4] = v89;
    v89 = stack[-4];
    if (v89 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v89 = stack[-4];
    v89 = qcar(v89);
    v58 = v89;
    v89 = v58;
    stack[0] = qcar(v89);
    v89 = v58;
    v89 = qcdr(v89);
    fn = elt(env, 2); /* bc_neg */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v89 = cons(stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v89 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v89 = Lrplacd(nil, stack[-1], v89);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v89 = stack[-2];
    v89 = qcdr(v89);
    stack[-2] = v89;
    goto v162;

v100:
    v89 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v89); }
/* error exit handlers */
v22:
    popv(6);
    return nil;
}



/* Code for pappend */

static Lisp_Object CC_pappend(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappend");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v54;
    stack[-4] = v0;
/* end of prologue */
    v91 = stack[-4];
    fn = elt(env, 2); /* unpkp */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    stack[-4] = v91;
    v91 = stack[-4];
    v91 = Llength(nil, v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    stack[-5] = v91;
    v91 = stack[0];
    fn = elt(env, 2); /* unpkp */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    stack[0] = v91;
    v91 = stack[0];
    stack[-3] = v91;
    v91 = stack[-3];
    if (v91 == nil) goto v96;
    v91 = stack[-3];
    v91 = qcar(v91);
    v59 = v91;
    v91 = stack[-5];
    v91 = plus2(v59, v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    stack[-1] = v91;
    stack[-2] = v91;
    goto v31;

v31:
    v91 = stack[-3];
    v91 = qcdr(v91);
    stack[-3] = v91;
    v91 = stack[-3];
    if (v91 == nil) goto v102;
    stack[0] = stack[-1];
    v91 = stack[-3];
    v91 = qcar(v91);
    v59 = v91;
    v91 = stack[-5];
    v91 = plus2(v59, v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v91 = Lrplacd(nil, stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v91 = stack[-1];
    v91 = qcdr(v91);
    stack[-1] = v91;
    goto v31;

v102:
    v91 = stack[-2];
    goto v49;

v49:
    stack[0] = v91;
    v59 = stack[-4];
    v91 = stack[0];
    v91 = Lappend(nil, v59, v91);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v91);
    }

v96:
    v91 = qvalue(elt(env, 1)); /* nil */
    goto v49;
/* error exit handlers */
v19:
    popv(7);
    return nil;
}



/* Code for idcons_ordp */

static Lisp_Object CC_idcons_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v32, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idcons_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v109 = v54;
    v32 = v0;
/* end of prologue */
    v49 = v32;
    v32 = v109;
    v109 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v49, v32, v109);
    }
}



/* Code for negate!-term */

static Lisp_Object CC_negateKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negate-term");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v109 = v0;
/* end of prologue */
    v68 = v109;
    stack[0] = qcar(v68);
    v68 = v109;
    v68 = qcdr(v68);
    fn = elt(env, 1); /* minus!-mod!-p */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v49;
    {
        Lisp_Object v31 = stack[0];
        popv(1);
        return cons(v31, v68);
    }
/* error exit handlers */
v49:
    popv(1);
    return nil;
}



/* Code for extmult */

static Lisp_Object CC_extmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v54;
    stack[-3] = v0;
/* end of prologue */
    v13 = stack[-3];
    if (v13 == nil) goto v62;
    v13 = stack[-2];
    if (v13 == nil) goto v62;
    v13 = stack[-3];
    v13 = qcar(v13);
    v13 = qcar(v13);
    v14 = qcar(v13);
    v13 = stack[-2];
    v13 = qcar(v13);
    v13 = qcar(v13);
    fn = elt(env, 2); /* ordexn */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v14 = v13;
    v13 = v14;
    if (v13 == nil) goto v73;
    v13 = v14;
    stack[-4] = qcdr(v13);
    v13 = v14;
    v13 = qcar(v13);
    if (v13 == nil) goto v149;
    v13 = stack[-3];
    v13 = qcar(v13);
    v14 = qcdr(v13);
    v13 = stack[-2];
    v13 = qcar(v13);
    v13 = qcdr(v13);
    fn = elt(env, 3); /* c!:subs2multf */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    fn = elt(env, 4); /* negf */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    stack[-1] = v13;
    goto v19;

v19:
    v13 = stack[-3];
    v13 = qcar(v13);
    v14 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v13 = stack[-2];
    v13 = qcdr(v13);
    stack[0] = CC_extmult(env, v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v13 = stack[-3];
    v14 = qcdr(v13);
    v13 = stack[-2];
    v13 = CC_extmult(env, v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    fn = elt(env, 5); /* extadd */
    v13 = (*qfn2(fn))(qenv(fn), stack[0], v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    {
        Lisp_Object v11 = stack[-4];
        Lisp_Object v12 = stack[-1];
        popv(6);
        return acons(v11, v12, v13);
    }

v149:
    v13 = stack[-3];
    v13 = qcar(v13);
    v14 = qcdr(v13);
    v13 = stack[-2];
    v13 = qcar(v13);
    v13 = qcdr(v13);
    fn = elt(env, 3); /* c!:subs2multf */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    stack[-1] = v13;
    goto v19;

v73:
    v13 = stack[-3];
    v14 = qcdr(v13);
    v13 = stack[-2];
    stack[0] = CC_extmult(env, v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v13 = stack[-3];
    v13 = qcar(v13);
    v14 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v13 = stack[-2];
    v13 = qcdr(v13);
    v13 = CC_extmult(env, v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    {
        Lisp_Object v127 = stack[0];
        popv(6);
        fn = elt(env, 5); /* extadd */
        return (*qfn2(fn))(qenv(fn), v127, v13);
    }

v62:
    v13 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v13); }
/* error exit handlers */
v142:
    popv(6);
    return nil;
}



/* Code for qqe_id!-nyt!-branchq */

static Lisp_Object CC_qqe_idKnytKbranchq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchq");
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
    v30 = stack[0];
    if (!consp(v30)) goto v60;
    v30 = stack[0];
    v30 = qcar(v30);
    fn = elt(env, 1); /* qqe_qopaddp */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    if (!(v30 == nil)) { popv(2); return onevalue(v30); }
    v30 = stack[0];
    v30 = qcar(v30);
    {
        popv(2);
        fn = elt(env, 2); /* qqe_qoptailp */
        return (*qfn1(fn))(qenv(fn), v30);
    }

v60:
    v30 = stack[0];
    fn = elt(env, 3); /* qqe_qtidp */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    if (!(v30 == nil)) { popv(2); return onevalue(v30); }
    v30 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* qqe_nytidp */
        return (*qfn1(fn))(qenv(fn), v30);
    }
/* error exit handlers */
v38:
    popv(2);
    return nil;
}



/* Code for cl_susiupdknowl1 */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v54,
                         Lisp_Object v4, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v80, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl1");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v4,v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v54,v4,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v4;
    v23 = v54;
    v124 = v0;
/* end of prologue */
    v80 = v124;
    v124 = elt(env, 1); /* and */
    if (v80 == v124) goto v30;
    v124 = v23;
    fn = elt(env, 2); /* rl_negateat */
    v80 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    v124 = stack[0];
    v23 = cons(v80, v124);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    v80 = stack[-1];
    v124 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v23, v80, v124);
    }

v30:
    v80 = v23;
    v124 = stack[0];
    v23 = cons(v80, v124);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    v80 = stack[-1];
    v124 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v23, v80, v124);
    }
/* error exit handlers */
v55:
    popv(3);
    return nil;
}



/* Code for ibalp_var!-satlist */

static Lisp_Object CC_ibalp_varKsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-satlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v54;
    v178 = v0;
/* end of prologue */
    stack[-5] = v178;
    goto v61;

v61:
    v178 = stack[-5];
    if (v178 == nil) goto v36;
    v178 = stack[-5];
    v178 = qcar(v178);
    stack[-3] = v178;
    v178 = stack[-3];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcar(v178);
    if (!(v178 == nil)) goto v180;
    v178 = stack[-3];
    v178 = qcar(v178);
    stack[-2] = v178;
    goto v105;

v105:
    v178 = stack[-2];
    if (v178 == nil) goto v95;
    v178 = stack[-2];
    v178 = qcar(v178);
    stack[-1] = v178;
    v178 = stack[-1];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    stack[0] = qcdr(v178);
    v178 = stack[-1];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcar(v178);
    v178 = sub1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v178 = stack[-1];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    stack[0] = qcdr(v178);
    v178 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v178 = stack[-2];
    v178 = qcdr(v178);
    stack[-2] = v178;
    goto v105;

v95:
    v178 = stack[-3];
    v178 = qcdr(v178);
    v178 = qcar(v178);
    stack[-2] = v178;
    goto v20;

v20:
    v178 = stack[-2];
    if (v178 == nil) goto v108;
    v178 = stack[-2];
    v178 = qcar(v178);
    stack[-1] = v178;
    v178 = stack[-1];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    stack[0] = qcdr(v178);
    v178 = stack[-1];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcar(v178);
    v178 = sub1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v178 = stack[-1];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    stack[0] = qcdr(v178);
    v178 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v178 = stack[-2];
    v178 = qcdr(v178);
    stack[-2] = v178;
    goto v20;

v108:
    v178 = stack[-3];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcar(v178);
    stack[-1] = v178;
    goto v159;

v159:
    v178 = stack[-1];
    if (v178 == nil) goto v182;
    v178 = stack[-1];
    v178 = qcar(v178);
    v179 = v178;
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    stack[0] = qcdr(v179);
    v179 = stack[-3];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcar(v178);
    fn = elt(env, 4); /* delq */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v178 = stack[-1];
    v178 = qcdr(v178);
    stack[-1] = v178;
    goto v159;

v182:
    v178 = stack[-3];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v179 = qcdr(v178);
    v178 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    goto v180;

v180:
    v178 = stack[-3];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    stack[0] = qcdr(v178);
    v179 = stack[-4];
    v178 = stack[-3];
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcar(v178);
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v178 = stack[-5];
    v178 = qcdr(v178);
    stack[-5] = v178;
    goto v61;

v36:
    v178 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v178); }
/* error exit handlers */
v181:
    popv(7);
    return nil;
}



/* Code for ofsf_sacatlp */

static Lisp_Object CC_ofsf_sacatlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v83, v82, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacatlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v54;
    v101 = v0;
/* end of prologue */
    v72 = qcar(v72);
    v82 = v72;
    v72 = v101;
    v72 = qcdr(v72);
    v83 = qcar(v72);
    v72 = v82;
    v72 = qcdr(v72);
    v72 = qcar(v72);
    if (equal(v83, v72)) goto v52;
    v72 = v101;
    v72 = qcdr(v72);
    v72 = qcar(v72);
    v83 = v82;
    v83 = qcdr(v83);
    v83 = qcar(v83);
    fn = elt(env, 2); /* ordp */
    v72 = (*qfn2(fn))(qenv(fn), v72, v83);
    errexit();
    goto v162;

v162:
    v72 = (v72 == nil ? lisp_true : nil);
    return onevalue(v72);

v52:
    v72 = qvalue(elt(env, 1)); /* nil */
    goto v162;
}



/* Code for terpri!* */

static Lisp_Object CC_terpriH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v165, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for terpri*");
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
    v166 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v166 == nil) goto v69;
    v165 = qvalue(elt(env, 1)); /* outputhandler!* */
    v77 = elt(env, 2); /* terpri */
    v166 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v165, v77, v166);

v69:
    v166 = qvalue(elt(env, 3)); /* testing!-width!* */
    if (v166 == nil) goto v71;
    v166 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 5)) = v166; /* overflowed!* */
    { popv(3); return onevalue(v166); }

v71:
    v166 = qvalue(elt(env, 6)); /* !*fort */
    if (v166 == nil) goto v38;
    v165 = qvalue(elt(env, 7)); /* posn!* */
    v166 = (Lisp_Object)1; /* 0 */
    if (v165 == v166) goto v105;
    v166 = stack[0];
    if (v166 == nil) goto v105;
    v166 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    goto v105;

v105:
    v166 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v166; /* posn!* */
    { popv(3); return onevalue(v166); }

v38:
    v166 = qvalue(elt(env, 8)); /* !*nat */
    if (v166 == nil) goto v162;
    v166 = qvalue(elt(env, 9)); /* pline!* */
    if (v166 == nil) goto v162;
    v166 = qvalue(elt(env, 9)); /* pline!* */
    v166 = Lreverse(nil, v166);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    qvalue(elt(env, 9)) = v166; /* pline!* */
    v166 = qvalue(elt(env, 10)); /* ymax!* */
    stack[-1] = v166;
    goto v110;

v110:
    v165 = stack[-1];
    v166 = qvalue(elt(env, 11)); /* ymin!* */
    v166 = difference2(v165, v166);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v166 = Lminusp(nil, v166);
    env = stack[-2];
    if (v166 == nil) goto v123;
    v166 = qvalue(elt(env, 12)); /* nil */
    qvalue(elt(env, 9)) = v166; /* pline!* */
    goto v162;

v162:
    v166 = stack[0];
    if (v166 == nil) goto v20;
    v166 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    goto v20;

v20:
    v166 = qvalue(elt(env, 13)); /* orig!* */
    qvalue(elt(env, 7)) = v166; /* posn!* */
    v166 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 11)) = v166; /* ymin!* */
    qvalue(elt(env, 10)) = v166; /* ymax!* */
    qvalue(elt(env, 14)) = v166; /* ycoord!* */
    v166 = nil;
    { popv(3); return onevalue(v166); }

v123:
    v165 = qvalue(elt(env, 9)); /* pline!* */
    v166 = stack[-1];
    fn = elt(env, 15); /* scprint */
    v166 = (*qfn2(fn))(qenv(fn), v165, v166);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v166 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v166 = stack[-1];
    v166 = sub1(v166);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[-1] = v166;
    goto v110;
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for find_sub_df */

static Lisp_Object CC_find_sub_df(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_sub_df");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v54;
    stack[-1] = v0;
/* end of prologue */

v99:
    v51 = stack[0];
    if (v51 == nil) goto v62;
    v27 = stack[-1];
    v51 = stack[0];
    v51 = qcar(v51);
    fn = elt(env, 2); /* is_sub_df */
    v51 = (*qfn2(fn))(qenv(fn), v27, v51);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    if (!(v51 == nil)) { popv(3); return onevalue(v51); }
    v27 = stack[-1];
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[-1] = v27;
    stack[0] = v51;
    goto v99;

v62:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for zeropp */

static Lisp_Object CC_zeropp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v64, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zeropp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v103 = v0;
/* end of prologue */
    v104 = v103;
    if (!consp(v104)) goto v60;
    v104 = v103;
    v64 = qcar(v104);
    v104 = elt(env, 1); /* !:rd!: */
    if (v64 == v104) goto v69;
    v104 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v104);

v69:
    v104 = v103;
    v104 = qcdr(v104);
    if (!consp(v104)) goto v96;
    v104 = v103;
    v104 = qcdr(v104);
    v64 = qcar(v104);
    v104 = (Lisp_Object)1; /* 0 */
    v104 = (v64 == v104 ? lisp_true : nil);
    return onevalue(v104);

v96:
    v104 = v103;
    v104 = qcdr(v104);
        return Lzerop(nil, v104);

v60:
    v104 = v103;
        return Lzerop(nil, v104);
}



/* Code for list!-mgen */

static Lisp_Object CC_listKmgen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-mgen");
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
    v53 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v28 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v28; /* i */
    v28 = v53;
    stack[0] = v28;
    goto v69;

v69:
    v28 = stack[0];
    if (v28 == nil) goto v52;
    v28 = stack[0];
    v28 = qcar(v28);
    v53 = v28;
    v28 = v53;
    if (!(!consp(v28))) goto v96;
    v28 = v53;
    fn = elt(env, 3); /* mgenp */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-2];
    if (v28 == nil) goto v96;
    v28 = qvalue(elt(env, 1)); /* i */
    v28 = add1(v28);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-2];
    qvalue(elt(env, 1)) = v28; /* i */
    goto v96;

v96:
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v69;

v52:
    v28 = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    { popv(3); return onevalue(v28); }
/* error exit handlers */
v83:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    popv(3);
    return nil;
}



/* Code for vdplength */

static Lisp_Object CC_vdplength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdplength");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v52 = v0;
/* end of prologue */
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    v52 = qcar(v52);
    {
        fn = elt(env, 1); /* diplength */
        return (*qfn1(fn))(qenv(fn), v52);
    }
}



/* Code for simpindexvar */

static Lisp_Object CC_simpindexvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpindexvar");
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
    v62 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitindexvar */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v62);
    }
/* error exit handlers */
v61:
    popv(1);
    return nil;
}



/* Code for xread */

static Lisp_Object CC_xread(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xread");
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

v60:
    fn = elt(env, 4); /* scan */
    v70 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    v70 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (v70 == nil) goto v162;
    v71 = qvalue(elt(env, 2)); /* cursym!* */
    v70 = elt(env, 3); /* !*semicol!* */
    if (v71 == v70) goto v60;
    else goto v162;

v162:
    v70 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v70);
    }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for mkarray1 */

static Lisp_Object CC_mkarray1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v59;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarray1");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v54;
    stack[-5] = v0;
/* end of prologue */
    v91 = stack[-5];
    if (v91 == nil) goto v87;
    v91 = stack[-5];
    v91 = qcar(v91);
    v91 = sub1(v91);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    stack[-6] = v91;
    v91 = stack[-6];
    v91 = Lmkvect(nil, v91);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    stack[-3] = v91;
    v91 = (Lisp_Object)1; /* 0 */
    stack[-2] = v91;
    goto v106;

v106:
    v59 = stack[-6];
    v91 = stack[-2];
    v91 = difference2(v59, v91);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    v91 = Lminusp(nil, v91);
    env = stack[-7];
    if (!(v91 == nil)) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-3];
    stack[0] = stack[-2];
    v91 = stack[-5];
    v59 = qcdr(v91);
    v91 = stack[-4];
    v91 = CC_mkarray1(env, v59, v91);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v91;
    v91 = stack[-2];
    v91 = add1(v91);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    stack[-2] = v91;
    goto v106;

v87:
    v59 = stack[-4];
    v91 = elt(env, 1); /* symbolic */
    if (v59 == v91) goto v36;
    v91 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v91); }

v36:
    v91 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v91); }
/* error exit handlers */
v108:
    popv(8);
    return nil;
}



/* Code for rnminus!: */

static Lisp_Object CC_rnminusT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnminus:");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v126 = stack[0];
    stack[-1] = qcar(v126);
    v126 = stack[0];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    fn = elt(env, 1); /* !:minus */
    v65 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v126 = stack[0];
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    {
        Lisp_Object v29 = stack[-1];
        popv(2);
        return list2star(v29, v65, v126);
    }
/* error exit handlers */
v71:
    popv(2);
    return nil;
}



/* Code for dp!=mocompare */

static Lisp_Object CC_dpMmocompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=mocompare");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v54;
    v96 = v0;
/* end of prologue */
    v96 = qcar(v96);
    v65 = qcar(v65);
    fn = elt(env, 1); /* mo_compare */
    v96 = (*qfn2(fn))(qenv(fn), v96, v65);
    errexit();
    v65 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v96, v65);
}



/* Code for difference!-mod!-p */

static Lisp_Object CC_differenceKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v87 = v54;
    v68 = v0;
/* end of prologue */
    stack[0] = v68;
    fn = elt(env, 1); /* minus!-mod!-p */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    {
        Lisp_Object v49 = stack[0];
        popv(2);
        fn = elt(env, 2); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v49, v87);
    }
/* error exit handlers */
v32:
    popv(2);
    return nil;
}



/* Code for rl_simpl */

static Lisp_Object MS_CDECL CC_rl_simpl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v54,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_simpl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpl");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v54,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v70 = v4;
    v71 = v54;
    v29 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simpl!* */
    v70 = list3(v29, v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    {
        Lisp_Object v38 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v38, v70);
    }
/* error exit handlers */
v94:
    popv(2);
    return nil;
}



/* Code for kernord!-split */

static Lisp_Object CC_kernordKsplit(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v116, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord-split");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v54;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = nil;
    v116 = stack[-3];
    v120 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* powers0 */
    v120 = (*qfn2(fn))(qenv(fn), v116, v120);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[-3] = v120;
    v116 = stack[-2];
    v120 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* powers0 */
    v120 = (*qfn2(fn))(qenv(fn), v116, v120);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[-2] = v120;
    v120 = stack[-3];
    stack[0] = v120;
    goto v94;

v94:
    v120 = stack[0];
    if (v120 == nil) goto v30;
    v120 = stack[0];
    v120 = qcar(v120);
    v163 = v120;
    v120 = v163;
    v116 = qcar(v120);
    v120 = stack[-2];
    v120 = Lassoc(nil, v116, v120);
    if (v120 == nil) goto v167;
    v116 = v163;
    v120 = stack[-1];
    v120 = cons(v116, v120);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[-1] = v120;
    goto v83;

v83:
    v120 = stack[0];
    v120 = qcdr(v120);
    stack[0] = v120;
    goto v94;

v167:
    v116 = v163;
    v120 = stack[-4];
    v120 = cons(v116, v120);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[-4] = v120;
    goto v83;

v30:
    v120 = stack[-2];
    stack[0] = v120;
    goto v123;

v123:
    v120 = stack[0];
    if (v120 == nil) goto v164;
    v120 = stack[0];
    v120 = qcar(v120);
    v163 = v120;
    v120 = v163;
    v116 = qcar(v120);
    v120 = stack[-3];
    v120 = Lassoc(nil, v116, v120);
    if (v120 == nil) goto v185;
    v116 = v163;
    v120 = stack[-1];
    v120 = cons(v116, v120);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[-1] = v120;
    goto v20;

v20:
    v120 = stack[0];
    v120 = qcdr(v120);
    stack[0] = v120;
    goto v123;

v185:
    v116 = v163;
    v120 = stack[-4];
    v120 = cons(v116, v120);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-5];
    stack[-4] = v120;
    goto v20;

v164:
    v120 = stack[-4];
    v116 = Lnreverse(nil, v120);
    env = stack[-5];
    v120 = stack[-1];
    v120 = Lnreverse(nil, v120);
    popv(6);
    return cons(v116, v120);
/* error exit handlers */
v118:
    popv(6);
    return nil;
}



/* Code for attributesml */

static Lisp_Object CC_attributesml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for attributesml");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v54;
    stack[-1] = v0;
/* end of prologue */
    v151 = stack[-1];
    if (v151 == nil) goto v162;
    v151 = elt(env, 2); /* " " */
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    v151 = stack[-1];
    v151 = qcar(v151);
    v151 = qcar(v151);
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    v151 = elt(env, 3); /* "=""" */
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    v151 = stack[-1];
    v151 = qcar(v151);
    v186 = qcar(v151);
    v151 = elt(env, 4); /* definitionurl */
    if (v186 == v151) goto v167;
    v151 = stack[-1];
    v151 = qcar(v151);
    v151 = qcdr(v151);
    v186 = qcar(v151);
    v151 = elt(env, 5); /* vectorml */
    if (v186 == v151) goto v82;
    v151 = stack[-1];
    v151 = qcar(v151);
    v151 = qcdr(v151);
    v151 = qcar(v151);
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    goto v30;

v30:
    v151 = elt(env, 8); /* """" */
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    v151 = stack[-1];
    v186 = qcdr(v151);
    v151 = stack[0];
    v151 = CC_attributesml(env, v186, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    goto v61;

v61:
    v151 = nil;
    { popv(3); return onevalue(v151); }

v82:
    v151 = elt(env, 6); /* "vector" */
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    goto v30;

v167:
    v151 = stack[-1];
    v151 = qcar(v151);
    v151 = qcdr(v151);
    v151 = qcar(v151);
    fn = elt(env, 9); /* list2string */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    goto v30;

v162:
    v151 = stack[0];
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    v151 = elt(env, 1); /* ">" */
    v151 = Lprinc(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v108;
    goto v61;
/* error exit handlers */
v108:
    popv(3);
    return nil;
}



/* Code for testredzz */

static Lisp_Object CC_testredzz(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testredzz");
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
    v63 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v104 = qvalue(elt(env, 2)); /* maxvar */
    v63 = plus2(v104, v63);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v104 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v63/(16/CELL)));
    v63 = (Lisp_Object)65; /* 4 */
    v63 = *(Lisp_Object *)((char *)v104 + (CELL-TAG_VECTOR) + ((int32_t)v63/(16/CELL)));
    stack[0] = v63;
    goto v62;

v62:
    v63 = stack[0];
    if (v63 == nil) goto v105;
    v63 = stack[0];
    v63 = qcar(v63);
    v63 = qcar(v63);
    fn = elt(env, 4); /* testredh */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v63 = stack[0];
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v62;

v105:
    v63 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v63); }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for modminusp!: */

static Lisp_Object CC_modminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modminusp:");
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
    v94 = v0;
/* end of prologue */
    v38 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v38 == nil) goto v71;
    v38 = (Lisp_Object)33; /* 2 */
    v94 = qcdr(v94);
    v94 = times2(v38, v94);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[0];
    v38 = qvalue(elt(env, 2)); /* current!-modulus */
        popv(1);
        return Lgreaterp(nil, v94, v38);

v71:
    v94 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v94); }
/* error exit handlers */
v48:
    popv(1);
    return nil;
}



/* Code for unchecked_getmatelem */

static Lisp_Object CC_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unchecked_getmatelem");
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
    v78 = stack[0];
    v79 = qcar(v78);
    v22 = v79;
    v78 = elt(env, 1); /* mat */
    if (!consp(v79)) goto v126;
    v79 = qcar(v79);
    if (!(v79 == v78)) goto v126;
    v78 = v22;
    v79 = qcdr(v78);
    v78 = stack[0];
    v78 = qcdr(v78);
    v78 = qcar(v78);
    fn = elt(env, 6); /* pnth */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-1];
    v79 = qcar(v78);
    v78 = stack[0];
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    fn = elt(env, 6); /* pnth */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v157;
    v78 = qcar(v78);
    { popv(2); return onevalue(v78); }

v126:
    v22 = elt(env, 2); /* "Matrix" */
    v78 = stack[0];
    v79 = qcar(v78);
    v78 = elt(env, 3); /* "not set" */
    v78 = list3(v22, v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-1];
    v79 = v78;
    v78 = v79;
    qvalue(elt(env, 4)) = v78; /* errmsg!* */
    v78 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v78 == nil)) goto v53;
    v78 = v79;
    fn = elt(env, 7); /* lprie */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-1];
    goto v53;

v53:
    v78 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v157;
    v78 = nil;
    { popv(2); return onevalue(v78); }
/* error exit handlers */
v157:
    popv(2);
    return nil;
}



/* Code for bcplus!? */

static Lisp_Object CC_bcplusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcplus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v96 = v0;
/* end of prologue */
    v96 = qcar(v96);
    v70 = v96;
    v96 = v70;
    if (is_number(v96)) goto v49;
    v96 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v96);

v49:
    v96 = (Lisp_Object)1; /* 0 */
        return Lgreaterp(nil, v70, v96);
}



/* Code for insertparens */

static Lisp_Object CC_insertparens(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertparens");
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
    v84 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !( */
    stack[0] = v84;
    v84 = elt(env, 2); /* !) */
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v84 = Lappend(nil, stack[0], v84);
    nil = C_nil;
    if (exception_pending()) goto v96;
    {
        Lisp_Object v70 = stack[-1];
        popv(3);
        return cons(v70, v84);
    }
/* error exit handlers */
v96:
    popv(3);
    return nil;
}



/* Code for zero!-roads */

static Lisp_Object CC_zeroKroads(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero-roads");
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

v99:
    v28 = stack[0];
    if (v28 == nil) goto v60;
    v28 = stack[0];
    v28 = qcar(v28);
    fn = elt(env, 2); /* z!-roads */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-2];
    v53 = v28;
    v28 = v53;
    if (v28 == nil) goto v95;
    stack[-1] = v53;
    v28 = stack[0];
    v28 = qcdr(v28);
    v28 = CC_zeroKroads(env, v28);
    nil = C_nil;
    if (exception_pending()) goto v83;
    {
        Lisp_Object v82 = stack[-1];
        popv(3);
        return cons(v82, v28);
    }

v95:
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v99;

v60:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v28); }
/* error exit handlers */
v83:
    popv(3);
    return nil;
}



/* Code for begin11 */

static Lisp_Object CC_begin11(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v242, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for begin11");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-3] = nil;
    stack[-2] = qvalue(elt(env, 2)); /* newrule!* */
    qvalue(elt(env, 2)) = nil; /* newrule!* */
    v242 = qvalue(elt(env, 3)); /* cursym!* */
    v241 = elt(env, 4); /* end */
    if (v242 == v241) goto v36;
    v241 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v241 == nil) goto v97;
    v241 = stack[-4];
    v242 = v241;
    goto v104;

v104:
    v241 = elt(env, 13); /* retry */
    if (!consp(v242)) goto v69;
    v242 = qcar(v242);
    if (!(v242 == v241)) goto v69;
    v241 = qvalue(elt(env, 14)); /* programl!* */
    if (v241 == nil) goto v110;
    v241 = qvalue(elt(env, 14)); /* programl!* */
    stack[-4] = v241;
    goto v69;

v69:
    v241 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (!(v241 == nil)) goto v108;
    v241 = stack[-4];
    v241 = qcar(v241);
    stack[-3] = v241;
    v241 = stack[-4];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    stack[-4] = v241;
    goto v108;

v108:
    v241 = stack[-4];
    qvalue(elt(env, 18)) = v241; /* program!* */
    v242 = qvalue(elt(env, 18)); /* program!* */
    v241 = qvalue(elt(env, 19)); /* !$eof!$ */
    if (!(v242 == v241)) goto v164;
    v242 = qvalue(elt(env, 20)); /* ttype!* */
    v241 = (Lisp_Object)49; /* 3 */
    if (!(v242 == v241)) goto v164;
    v241 = qvalue(elt(env, 21)); /* eof!* */
    v241 = add1(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    qvalue(elt(env, 21)) = v241; /* eof!* */
    if (v241 == nil) goto v164;
    v241 = elt(env, 22); /* c */
    goto v162;

v162:
    qvalue(elt(env, 2)) = stack[-2]; /* newrule!* */
    qvalue(elt(env, 1)) = stack[-5]; /* errmsg!* */
    { popv(7); return onevalue(v241); }

v164:
    v241 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 21)) = v241; /* eof!* */
    v241 = qvalue(elt(env, 5)); /* !*int */
    if (v241 == nil) goto v245;
    v241 = qvalue(elt(env, 6)); /* ifl!* */
    if (!(v241 == nil)) goto v245;
    v241 = qvalue(elt(env, 10)); /* !*nosave!* */
    if (!(v241 == nil)) goto v245;
    v243 = qvalue(elt(env, 23)); /* statcounter */
    v241 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v241 == nil) goto v246;
    v241 = qvalue(elt(env, 11)); /* nil */
    v242 = v241;
    goto v133;

v133:
    v241 = stack[-4];
    v242 = list3(v243, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = qvalue(elt(env, 24)); /* inputbuflis!* */
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    qvalue(elt(env, 24)) = v241; /* inputbuflis!* */
    goto v245;

v245:
    v241 = stack[-4];
    if (!consp(v241)) goto v111;
    v241 = stack[-4];
    v242 = qcar(v241);
    v241 = elt(env, 25); /* (bye quit) */
    v241 = Lmemq(nil, v242, v241);
    if (v241 == nil) goto v111;
    v241 = elt(env, 26); /* bye */
    fn = elt(env, 55); /* getd */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    if (v241 == nil) goto v247;
    v241 = stack[-4];
    fn = elt(env, 36); /* eval */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 10)) = v241; /* !*nosave!* */
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v247:
    v241 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 27)) = v241; /* !*byeflag!* */
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v111:
    v241 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (!(v241 == nil)) goto v134;
    v242 = stack[-4];
    v241 = elt(env, 28); /* ed */
    if (!consp(v242)) goto v134;
    v242 = qcar(v242);
    if (!(v242 == v241)) goto v134;
    v241 = elt(env, 29); /* cedit */
    fn = elt(env, 55); /* getd */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    if (v241 == nil) goto v248;
    v241 = qvalue(elt(env, 5)); /* !*int */
    if (v241 == nil) goto v248;
    v241 = qvalue(elt(env, 6)); /* ifl!* */
    if (!(v241 == nil)) goto v248;
    v241 = stack[-4];
    v241 = qcdr(v241);
    fn = elt(env, 29); /* cedit */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    goto v249;

v249:
    v241 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 10)) = v241; /* !*nosave!* */
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v248:
    v241 = qvalue(elt(env, 15)); /* !*msg */
    if (v241 == nil) goto v249;
    v242 = elt(env, 16); /* "***" */
    v241 = elt(env, 30); /* "ED not supported" */
    fn = elt(env, 56); /* lpriw */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    goto v249;

v134:
    v241 = qvalue(elt(env, 31)); /* !*defn */
    if (v241 == nil) goto v250;
    v241 = qvalue(elt(env, 32)); /* erfg!* */
    if (v241 == nil) goto v251;
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v251:
    v242 = qvalue(elt(env, 33)); /* key!* */
    v241 = elt(env, 34); /* ignore */
    v241 = Lflagp(nil, v242, v241);
    env = stack[-6];
    if (!(v241 == nil)) goto v250;
    v242 = stack[-4];
    v241 = elt(env, 35); /* quote */
    if (!consp(v242)) goto v181;
    v242 = qcar(v242);
    if (!(v242 == v241)) goto v181;

v250:
    v241 = qvalue(elt(env, 37)); /* !*output */
    if (v241 == nil) goto v252;
    v241 = qvalue(elt(env, 6)); /* ifl!* */
    if (v241 == nil) goto v252;
    v241 = qvalue(elt(env, 38)); /* !*echo */
    if (v241 == nil) goto v252;
    v241 = qvalue(elt(env, 39)); /* !*lessspace */
    if (!(v241 == nil)) goto v252;
    v241 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    goto v252;

v252:
    v243 = stack[-4];
    v242 = qvalue(elt(env, 9)); /* t */
    v241 = qvalue(elt(env, 40)); /* !*backtrace */
    fn = elt(env, 57); /* errorset */
    v241 = (*qfnn(fn))(qenv(fn), 3, v243, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[0] = v241;
    v241 = stack[0];
    if (!consp(v241)) goto v253;
    v241 = stack[0];
    v241 = qcdr(v241);
    if (!(v241 == nil)) goto v253;
    v241 = qvalue(elt(env, 32)); /* erfg!* */
    if (!(v241 == nil)) goto v253;
    v241 = qvalue(elt(env, 31)); /* !*defn */
    if (v241 == nil) goto v254;
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v254:
    v241 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v241 == nil) goto v255;
    v241 = stack[0];
    v241 = qcar(v241);
    stack[0] = v241;
    v241 = stack[0];
    if (!(v241 == nil)) goto v256;
    v242 = qvalue(elt(env, 11)); /* nil */
    v241 = elt(env, 43); /* noval */
    fn = elt(env, 58); /* mkobject */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[0] = v241;
    goto v256;

v256:
    v241 = stack[0];
    fn = elt(env, 59); /* type */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[-3] = v241;
    v241 = stack[0];
    fn = elt(env, 60); /* value */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[0] = v241;
    goto v257;

v257:
    v241 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v241 == nil) goto v258;
    v241 = stack[0];
    v242 = v241;
    goto v259;

v259:
    v241 = stack[-3];
    fn = elt(env, 61); /* add2resultbuf */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = qvalue(elt(env, 37)); /* !*output */
    if (v241 == nil) goto v260;
    v242 = qvalue(elt(env, 44)); /* semic!* */
    v241 = elt(env, 45); /* !$ */
    if (v242 == v241) goto v261;
    v241 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v241 == nil) goto v262;
    v241 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v242 = stack[-3];
    v241 = elt(env, 43); /* noval */
    if (v242 == v241) goto v261;
    v241 = qvalue(elt(env, 46)); /* !*debug */
    if (v241 == nil) goto v263;
    v241 = elt(env, 47); /* "Value:" */
    v241 = Lprinc(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    goto v263;

v263:
    stack[-1] = elt(env, 48); /* print */
    v242 = stack[-3];
    v241 = stack[0];
    v241 = list2(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    fn = elt(env, 62); /* rapply1 */
    v241 = (*qfn2(fn))(qenv(fn), stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    goto v261;

v261:
    v241 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v241 == nil) goto v264;
    v242 = qvalue(elt(env, 49)); /* !*mode */
    v241 = elt(env, 43); /* noval */
    if (v242 == v241) goto v265;
    v241 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = elt(env, 54); /* "of type: " */
    v241 = Lprinc(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = stack[-3];
    v241 = Lprint(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    goto v265;

v265:
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v264:
    v241 = stack[0];
    if (!consp(v241)) goto v266;
    v241 = stack[0];
    v241 = qcdr(v241);
    if (!(v241 == nil)) goto v266;
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v266:
    v241 = elt(env, 53); /* err3 */
    goto v162;

v262:
    v242 = stack[-3];
    v241 = elt(env, 42); /* symbolic */
    if (v242 == v241) goto v267;
    v241 = stack[0];
    v241 = qcar(v241);
    if (v241 == nil) goto v261;
    stack[-1] = elt(env, 50); /* assgnpri */
    v241 = stack[0];
    v241 = qcar(v241);
    stack[0] = Lmkquote(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = stack[-4];
    if (v241 == nil) goto v268;
    v242 = elt(env, 51); /* list */
    v241 = stack[-4];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[-4] = v241;
    goto v269;

v269:
    v241 = elt(env, 52); /* only */
    v241 = Lmkquote(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v243 = list4(stack[-1], stack[0], stack[-4], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v242 = qvalue(elt(env, 9)); /* t */
    v241 = qvalue(elt(env, 40)); /* !*backtrace */
    fn = elt(env, 57); /* errorset */
    v241 = (*qfnn(fn))(qenv(fn), 3, v243, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[0] = v241;
    goto v261;

v268:
    v241 = qvalue(elt(env, 11)); /* nil */
    stack[-4] = v241;
    goto v269;

v267:
    v241 = stack[0];
    v241 = qcar(v241);
    if (!(v241 == nil)) goto v270;
    v242 = qvalue(elt(env, 49)); /* !*mode */
    v241 = elt(env, 42); /* symbolic */
    if (!(v242 == v241)) goto v261;

v270:
    v241 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[-1] = elt(env, 48); /* print */
    v241 = stack[0];
    v241 = qcar(v241);
    v241 = Lmkquote(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v243 = list2(stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v242 = qvalue(elt(env, 9)); /* t */
    v241 = qvalue(elt(env, 40)); /* !*backtrace */
    fn = elt(env, 57); /* errorset */
    v241 = (*qfnn(fn))(qenv(fn), 3, v243, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[0] = v241;
    goto v261;

v260:
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v258:
    v241 = stack[0];
    v241 = qcar(v241);
    v242 = v241;
    goto v259;

v255:
    v242 = stack[-3];
    v241 = elt(env, 42); /* symbolic */
    if (v242 == v241) goto v257;
    v241 = stack[-4];
    fn = elt(env, 63); /* getsetvars */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[-4] = v241;
    goto v257;

v253:
    v242 = stack[-3];
    v241 = stack[-4];
    v241 = list2(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    qvalue(elt(env, 14)) = v241; /* programl!* */
    v241 = elt(env, 41); /* err2 */
    goto v162;

v181:
    v241 = stack[-4];
    if (v241 == nil) goto v271;
    v241 = stack[-4];
    fn = elt(env, 64); /* dfprint */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    goto v271;

v271:
    v242 = qvalue(elt(env, 33)); /* key!* */
    v241 = elt(env, 36); /* eval */
    v241 = Lflagp(nil, v242, v241);
    env = stack[-6];
    if (!(v241 == nil)) goto v250;
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v246:
    v241 = stack[-3];
    v242 = v241;
    goto v133;

v110:
    v241 = qvalue(elt(env, 15)); /* !*msg */
    if (v241 == nil) goto v78;
    v242 = elt(env, 16); /* "***" */
    v241 = elt(env, 17); /* "No previous expression" */
    fn = elt(env, 56); /* lpriw */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    goto v78;

v78:
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v97:
    v241 = stack[-4];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v242 = v241;
    goto v104;

v36:
    v241 = qvalue(elt(env, 5)); /* !*int */
    if (v241 == nil) goto v27;
    v241 = qvalue(elt(env, 6)); /* ifl!* */
    if (!(v241 == nil)) goto v27;
    v241 = qvalue(elt(env, 7)); /* !*lisp_hook */
    if (!(v241 == nil)) goto v27;
    v241 = elt(env, 8); /* !*semicol!* */
    qvalue(elt(env, 3)) = v241; /* cursym!* */
    v241 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 10)) = v241; /* !*nosave!* */
    v241 = qvalue(elt(env, 11)); /* nil */
    goto v162;

v27:
    v241 = elt(env, 4); /* end */
    fn = elt(env, 65); /* comm1 */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v241 = elt(env, 4); /* end */
    goto v162;
/* error exit handlers */
v244:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; /* newrule!* */
    qvalue(elt(env, 1)) = stack[-5]; /* errmsg!* */
    popv(7);
    return nil;
}



/* Code for mv2sf1 */

static Lisp_Object MS_CDECL CC_mv2sf1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v54,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v80, v23, v24, v40;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv2sf1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv2sf1");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v54,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v23 = v4;
    v40 = v54;
    v24 = v0;
/* end of prologue */

v61:
    v124 = v24;
    if (v124 == nil) { popv(3); return onevalue(v40); }
    v124 = v24;
    v80 = qcar(v124);
    v124 = (Lisp_Object)1; /* 0 */
    if (v80 == v124) goto v68;
    v124 = v23;
    stack[-1] = qcar(v124);
    v124 = v24;
    stack[0] = qcar(v124);
    v124 = v24;
    v124 = qcdr(v124);
    v80 = v40;
    v23 = qcdr(v23);
    v124 = CC_mv2sf1(env, 3, v124, v80, v23);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v124 = acons(stack[-1], stack[0], v124);
    nil = C_nil;
    if (exception_pending()) goto v89;
    popv(3);
    return ncons(v124);

v68:
    v124 = v24;
    v124 = qcdr(v124);
    v24 = v124;
    v124 = v23;
    v124 = qcdr(v124);
    v23 = v124;
    goto v61;
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for bc_fi */

static Lisp_Object CC_bc_fi(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v84, v126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_fi");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v126 = v0;
/* end of prologue */
    v84 = v126;
    v31 = (Lisp_Object)1; /* 0 */
    if (!(v84 == v31)) return onevalue(v126);
    v31 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v31);
}



/* Code for pv_times2 */

static Lisp_Object MS_CDECL CC_pv_times2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v54,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pv_times2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times2");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v54,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v41 = v54;
    stack[-1] = v0;
/* end of prologue */

v162:
    v72 = v41;
    if (v72 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v72 = v41;
    v72 = qcdr(v72);
    stack[-2] = v72;
    v72 = stack[-1];
    v41 = qcar(v41);
    fn = elt(env, 1); /* pv_times3 */
    v41 = (*qfn2(fn))(qenv(fn), v72, v41);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v72 = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v41 = stack[0];
    fn = elt(env, 2); /* pv_add */
    v41 = (*qfn2(fn))(qenv(fn), v72, v41);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    stack[0] = v41;
    v41 = stack[-2];
    goto v162;
/* error exit handlers */
v102:
    popv(4);
    return nil;
}



/* Code for charnump!: */

static Lisp_Object CC_charnumpT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v124, v80, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for charnump:");
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
    v125 = v0;
/* end of prologue */
    stack[-6] = v125;
    stack[-5] = elt(env, 1); /* !0 */
    stack[-4] = elt(env, 2); /* !1 */
    stack[-3] = elt(env, 3); /* !2 */
    stack[-2] = elt(env, 4); /* !3 */
    stack[-1] = elt(env, 5); /* !4 */
    stack[0] = elt(env, 6); /* !5 */
    v23 = elt(env, 7); /* !6 */
    v80 = elt(env, 8); /* !7 */
    v124 = elt(env, 9); /* !8 */
    v125 = elt(env, 10); /* !9 */
    v125 = list4(v23, v80, v124, v125);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    v125 = list3star(stack[-2], stack[-1], stack[0], v125);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    v125 = list3star(stack[-5], stack[-4], stack[-3], v125);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    v125 = Lmember(nil, stack[-6], v125);
    if (v125 == nil) goto v62;
    v125 = qvalue(elt(env, 11)); /* t */
    { popv(8); return onevalue(v125); }

v62:
    v125 = nil;
    { popv(8); return onevalue(v125); }
/* error exit handlers */
v149:
    popv(8);
    return nil;
}



/* Code for b!:extadd */

static Lisp_Object CC_bTextadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v272, v118, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:extadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v54;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v61;

v61:
    v272 = stack[-2];
    if (v272 == nil) goto v68;
    v272 = stack[-1];
    if (v272 == nil) goto v29;
    v272 = stack[-2];
    v272 = qcar(v272);
    v118 = qcar(v272);
    v272 = stack[-1];
    v272 = qcar(v272);
    v272 = qcar(v272);
    if (equal(v118, v272)) goto v103;
    v272 = stack[-2];
    v272 = qcar(v272);
    v118 = qcar(v272);
    v272 = stack[-1];
    v272 = qcar(v272);
    v272 = qcar(v272);
    fn = elt(env, 1); /* b!:ordexp */
    v272 = (*qfn2(fn))(qenv(fn), v118, v272);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    if (v272 == nil) goto v119;
    v272 = stack[-2];
    v118 = qcar(v272);
    v272 = stack[0];
    v272 = cons(v118, v272);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    stack[0] = v272;
    v272 = stack[-2];
    v272 = qcdr(v272);
    stack[-2] = v272;
    goto v61;

v119:
    v272 = stack[-1];
    v118 = qcar(v272);
    v272 = stack[0];
    v272 = cons(v118, v272);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    stack[0] = v272;
    v272 = stack[-1];
    v272 = qcdr(v272);
    stack[-1] = v272;
    goto v61;

v103:
    stack[-3] = stack[0];
    v272 = stack[-2];
    v272 = qcar(v272);
    v118 = qcdr(v272);
    v272 = stack[-1];
    v272 = qcar(v272);
    v272 = qcdr(v272);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v118, v272);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v272 = stack[-2];
    v118 = qcdr(v272);
    v272 = stack[-1];
    v272 = qcdr(v272);
    v272 = CC_bTextadd(env, v118, v272);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v118 = stack[0];
    v176 = v118;
    if (v176 == nil) goto v25;
    v176 = stack[-2];
    v176 = qcar(v176);
    v176 = qcar(v176);
    v272 = acons(v176, v118, v272);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    goto v25;

v25:
    {
        Lisp_Object v141 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v141, v272);
    }

v29:
    v118 = stack[0];
    v272 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v118, v272);
    }

v68:
    v118 = stack[0];
    v272 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v118, v272);
    }
/* error exit handlers */
v43:
    popv(5);
    return nil;
}



/* Code for sfto_ucontentf */

static Lisp_Object CC_sfto_ucontentf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_ucontentf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v94 = v30;
    if (!consp(v94)) return onevalue(v30);
    v94 = v30;
    v94 = qcar(v94);
    if (!consp(v94)) return onevalue(v30);
    v94 = v30;
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    {
        fn = elt(env, 1); /* sfto_ucontentf1 */
        return (*qfn2(fn))(qenv(fn), v94, v30);
    }
}



/* Code for qremf */

static Lisp_Object CC_qremf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v54)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v323, v262, v324;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qremf");
#endif
    if (stack >= stacklimit)
    {
        push2(v54,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v54);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v54;
    stack[-7] = v0;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    v323 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v323; /* !*exp */
    v323 = stack[-6];
    if (!consp(v323)) goto v71;
    v323 = stack[-6];
    v323 = qcar(v323);
    if (!consp(v323)) goto v71;
    v323 = qvalue(elt(env, 3)); /* nil */
    v323 = ncons(v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-2] = v323;
    goto v36;

v36:
    v323 = stack[-7];
    if (!consp(v323)) goto v63;
    v323 = stack[-7];
    v323 = qcar(v323);
    if (!consp(v323)) goto v63;
    v323 = stack[-7];
    v323 = qcar(v323);
    v323 = qcar(v323);
    v262 = qcar(v323);
    v323 = stack[-6];
    v323 = qcar(v323);
    v323 = qcar(v323);
    v323 = qcar(v323);
    if (v262 == v323) goto v143;
    v323 = stack[-7];
    v323 = qcar(v323);
    v323 = qcar(v323);
    v262 = qcar(v323);
    v323 = stack[-6];
    v323 = qcar(v323);
    v323 = qcar(v323);
    v323 = qcar(v323);
    fn = elt(env, 4); /* ordop */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    if (v323 == nil) goto v326;
    v323 = stack[-7];
    v323 = qcar(v323);
    v262 = qcdr(v323);
    v323 = stack[-6];
    v323 = CC_qremf(env, v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-4] = v323;
    v323 = stack[-7];
    v323 = qcar(v323);
    v262 = qcar(v323);
    v323 = (Lisp_Object)17; /* 1 */
    v323 = cons(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v262 = ncons(v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-4];
    v323 = qcar(v323);
    fn = elt(env, 5); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-7];
    v323 = qcar(v323);
    v262 = qcar(v323);
    v323 = (Lisp_Object)17; /* 1 */
    v323 = cons(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v262 = ncons(v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-4];
    v323 = qcdr(v323);
    fn = elt(env, 5); /* multf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = cons(stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-1] = v323;
    v323 = stack[-2];
    v262 = qcar(v323);
    v323 = stack[-1];
    v323 = qcar(v323);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-2];
    v262 = qcdr(v323);
    v323 = stack[-1];
    v323 = qcdr(v323);
    fn = elt(env, 6); /* addf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = cons(stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-2] = v323;
    v323 = stack[-7];
    v323 = qcdr(v323);
    stack[-7] = v323;
    goto v36;

v326:
    v262 = qvalue(elt(env, 3)); /* nil */
    v323 = stack[-7];
    v323 = cons(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-1] = v323;
    v323 = stack[-2];
    v262 = qcar(v323);
    v323 = stack[-1];
    v323 = qcar(v323);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-2];
    v262 = qcdr(v323);
    v323 = stack[-1];
    v323 = qcdr(v323);
    fn = elt(env, 6); /* addf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = cons(stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    goto v69;

v69:
    qvalue(elt(env, 1)) = stack[-5]; /* !*exp */
    { popv(10); return onevalue(v323); }

v143:
    v323 = stack[-7];
    v323 = qcar(v323);
    v323 = qcar(v323);
    v262 = qcdr(v323);
    v323 = stack[-6];
    v323 = qcar(v323);
    v323 = qcar(v323);
    v323 = qcdr(v323);
    v262 = difference2(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-8] = v262;
    v323 = (Lisp_Object)1; /* 0 */
    v323 = (Lisp_Object)lessp2(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-9];
    if (v323 == nil) goto v327;
    v262 = qvalue(elt(env, 3)); /* nil */
    v323 = stack[-7];
    v323 = cons(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-1] = v323;
    v323 = stack[-2];
    v262 = qcar(v323);
    v323 = stack[-1];
    v323 = qcar(v323);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-2];
    v262 = qcdr(v323);
    v323 = stack[-1];
    v323 = qcdr(v323);
    fn = elt(env, 6); /* addf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = cons(stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    goto v69;

v327:
    v323 = stack[-7];
    v323 = qcar(v323);
    v262 = qcdr(v323);
    v323 = stack[-6];
    v323 = qcar(v323);
    v323 = qcdr(v323);
    v323 = CC_qremf(env, v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-4] = v323;
    v323 = stack[-7];
    v323 = qcar(v323);
    v262 = qcar(v323);
    v323 = (Lisp_Object)17; /* 1 */
    v323 = cons(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v262 = ncons(v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-4];
    v323 = qcdr(v323);
    fn = elt(env, 5); /* multf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-3] = v323;
    v262 = stack[-8];
    v323 = (Lisp_Object)1; /* 0 */
    if (v262 == v323) goto v134;
    v323 = stack[-7];
    v323 = qcar(v323);
    v323 = qcar(v323);
    v324 = qcar(v323);
    v262 = stack[-8];
    v323 = (Lisp_Object)17; /* 1 */
    v323 = acons(v324, v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v262 = ncons(v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-4];
    v323 = qcar(v323);
    fn = elt(env, 5); /* multf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v262 = v323;
    goto v247;

v247:
    v323 = stack[-3];
    v323 = cons(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-1] = v323;
    v323 = stack[-2];
    v262 = qcar(v323);
    v323 = stack[-1];
    v323 = qcar(v323);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-2];
    v262 = qcdr(v323);
    v323 = stack[-1];
    v323 = qcdr(v323);
    fn = elt(env, 6); /* addf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = cons(stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-2] = v323;
    v323 = stack[-4];
    v323 = qcar(v323);
    if (v323 == nil) goto v232;
    stack[0] = stack[-7];
    v262 = stack[-8];
    v323 = (Lisp_Object)1; /* 0 */
    if (v262 == v323) goto v328;
    v323 = stack[-7];
    v323 = qcar(v323);
    v323 = qcar(v323);
    v324 = qcar(v323);
    v262 = stack[-8];
    v323 = (Lisp_Object)17; /* 1 */
    v323 = acons(v324, v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v262 = ncons(v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-6];
    fn = elt(env, 5); /* multf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-1] = v323;
    goto v329;

v329:
    v323 = stack[-4];
    v323 = qcar(v323);
    fn = elt(env, 7); /* negf */
    v323 = (*qfn1(fn))(qenv(fn), v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    fn = elt(env, 5); /* multf */
    v323 = (*qfn2(fn))(qenv(fn), stack[-1], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-3];
    fn = elt(env, 7); /* negf */
    v323 = (*qfn1(fn))(qenv(fn), v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    fn = elt(env, 6); /* addf */
    v323 = (*qfn2(fn))(qenv(fn), stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    goto v231;

v231:
    stack[-7] = v323;
    goto v36;

v328:
    v323 = stack[-6];
    stack[-1] = v323;
    goto v329;

v232:
    v323 = stack[-7];
    v323 = qcdr(v323);
    goto v231;

v134:
    v323 = stack[-4];
    v323 = qcar(v323);
    v262 = v323;
    goto v247;

v63:
    v262 = qvalue(elt(env, 3)); /* nil */
    v323 = stack[-7];
    v323 = cons(v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    stack[-1] = v323;
    v323 = stack[-2];
    v262 = qcar(v323);
    v323 = stack[-1];
    v323 = qcar(v323);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = stack[-2];
    v262 = qcdr(v323);
    v323 = stack[-1];
    v323 = qcdr(v323);
    fn = elt(env, 6); /* addf */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    v323 = cons(stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    goto v69;

v71:
    v262 = stack[-7];
    v323 = stack[-6];
    fn = elt(env, 8); /* qremd */
    v323 = (*qfn2(fn))(qenv(fn), v262, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-9];
    goto v69;
/* error exit handlers */
v325:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-5]; /* !*exp */
    popv(10);
    return nil;
}



setup_type const u14_setup[] =
{
    {"getmatelem",              CC_getmatelem,  too_many_1,    wrong_no_1},
    {"nzeros",                  CC_nzeros,      too_many_1,    wrong_no_1},
    {"dp_times_bcmo",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dp_times_bcmo},
    {"eqdummy",                 too_few_2,      CC_eqdummy,    wrong_no_2},
    {"primep",                  CC_primep,      too_many_1,    wrong_no_1},
    {"degree-in-variable",      too_few_2,      CC_degreeKinKvariable,wrong_no_2},
    {"freeofl",                 too_few_2,      CC_freeofl,    wrong_no_2},
    {"rl_simp",                 CC_rl_simp,     too_many_1,    wrong_no_1},
    {"qqe_ofsf_simplat1",       too_few_2,      CC_qqe_ofsf_simplat1,wrong_no_2},
    {"image-of-power",          too_few_2,      CC_imageKofKpower,wrong_no_2},
    {"constsml",                CC_constsml,    too_many_1,    wrong_no_1},
    {"subs4q",                  CC_subs4q,      too_many_1,    wrong_no_1},
    {"opmtch",                  CC_opmtch,      too_many_1,    wrong_no_1},
    {"evaluate1",               too_few_2,      CC_evaluate1,  wrong_no_2},
    {"procstat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_procstat},
    {"dp_neg",                  CC_dp_neg,      too_many_1,    wrong_no_1},
    {"pappend",                 too_few_2,      CC_pappend,    wrong_no_2},
    {"idcons_ordp",             too_few_2,      CC_idcons_ordp,wrong_no_2},
    {"negate-term",             CC_negateKterm, too_many_1,    wrong_no_1},
    {"extmult",                 too_few_2,      CC_extmult,    wrong_no_2},
    {"qqe_id-nyt-branchq",      CC_qqe_idKnytKbranchq,too_many_1,wrong_no_1},
    {"cl_susiupdknowl1",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl1},
    {"ibalp_var-satlist",       too_few_2,      CC_ibalp_varKsatlist,wrong_no_2},
    {"ofsf_sacatlp",            too_few_2,      CC_ofsf_sacatlp,wrong_no_2},
    {"terpri*",                 CC_terpriH,     too_many_1,    wrong_no_1},
    {"find_sub_df",             too_few_2,      CC_find_sub_df,wrong_no_2},
    {"zeropp",                  CC_zeropp,      too_many_1,    wrong_no_1},
    {"list-mgen",               CC_listKmgen,   too_many_1,    wrong_no_1},
    {"vdplength",               CC_vdplength,   too_many_1,    wrong_no_1},
    {"simpindexvar",            CC_simpindexvar,too_many_1,    wrong_no_1},
    {"xread",                   CC_xread,       too_many_1,    wrong_no_1},
    {"mkarray1",                too_few_2,      CC_mkarray1,   wrong_no_2},
    {"rnminus:",                CC_rnminusT,    too_many_1,    wrong_no_1},
    {"dp=mocompare",            too_few_2,      CC_dpMmocompare,wrong_no_2},
    {"difference-mod-p",        too_few_2,      CC_differenceKmodKp,wrong_no_2},
    {"rl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_simpl},
    {"kernord-split",           too_few_2,      CC_kernordKsplit,wrong_no_2},
    {"attributesml",            too_few_2,      CC_attributesml,wrong_no_2},
    {"testredzz",               CC_testredzz,   too_many_1,    wrong_no_1},
    {"modminusp:",              CC_modminuspT,  too_many_1,    wrong_no_1},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"insertparens",            CC_insertparens,too_many_1,    wrong_no_1},
    {"zero-roads",              CC_zeroKroads,  too_many_1,    wrong_no_1},
    {"begin11",                 CC_begin11,     too_many_1,    wrong_no_1},
    {"mv2sf1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mv2sf1},
    {"bc_fi",                   CC_bc_fi,       too_many_1,    wrong_no_1},
    {"pv_times2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pv_times2},
    {"charnump:",               CC_charnumpT,   too_many_1,    wrong_no_1},
    {"b:extadd",                too_few_2,      CC_bTextadd,   wrong_no_2},
    {"sfto_ucontentf",          CC_sfto_ucontentf,too_many_1,  wrong_no_1},
    {"qremf",                   too_few_2,      CC_qremf,      wrong_no_2},
    {NULL, (one_args *)"u14", (two_args *)"2767 8412160 3195035", 0}
};

/* end of generated code */
