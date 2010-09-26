
/* $destdir\u24.c        Machine generated C code */

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


/* Code for matsm1 */

static Lisp_Object CC_matsm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm1");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    goto v110;

v110:
    v107 = stack[-8];
    if (v107 == nil) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v107 = stack[-8];
    v108 = qcar(v107);
    v107 = elt(env, 1); /* !*div */
    if (!consp(v108)) goto v111;
    v108 = qcar(v108);
    if (!(v108 == v107)) goto v111;
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    fn = elt(env, 20); /* matsm */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-2] = v107;
    v107 = stack[-2];
    v107 = qcar(v107);
    stack[0] = Llength(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-1] = stack[0];
    v107 = stack[-2];
    v107 = Llength(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    if (equal(stack[0], v107)) goto v113;
    v107 = elt(env, 11); /* "Non square matrix" */
    v108 = v107;
    v107 = v108;
    qvalue(elt(env, 7)) = v107; /* errmsg!* */
    v107 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v107 == nil)) goto v114;
    v107 = v108;
    fn = elt(env, 21); /* lprie */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v114;

v114:
    v107 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v115;

v115:
    v107 = qvalue(elt(env, 12)); /* subfg!* */
    stack[0] = v107;
    v107 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 12)) = v107; /* subfg!* */
    v107 = stack[-9];
    if (v107 == nil) goto v116;
    v108 = elt(env, 2); /* mat */
    v107 = elt(env, 14); /* lnrsolvefn */
    v107 = get(v108, v107);
    env = stack[-10];
    stack[0] = v107;
    if (v107 == nil) goto v117;
    v108 = elt(env, 2); /* mat */
    v107 = elt(env, 14); /* lnrsolvefn */
    v109 = get(v108, v107);
    env = stack[-10];
    v108 = stack[-2];
    v107 = stack[-9];
    v107 = Lapply2(nil, 3, v109, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-9] = v107;
    goto v118;

v118:
    v107 = stack[0];
    qvalue(elt(env, 12)) = v107; /* subfg!* */
    v107 = stack[-9];
    stack[-7] = v107;
    v107 = stack[-7];
    if (v107 == nil) goto v119;
    v107 = stack[-7];
    v107 = qcar(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v120;
    v107 = stack[-3];
    v107 = qcar(v107);
    v108 = v107;
    v107 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 16)) = v107; /* !*sub2 */
    v107 = v108;
    fn = elt(env, 22); /* subs2 */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-1] = v107;
    stack[-2] = v107;
    goto v121;

v121:
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v122;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v108 = v107;
    v107 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 16)) = v107; /* !*sub2 */
    v107 = v108;
    fn = elt(env, 22); /* subs2 */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    goto v121;

v122:
    v107 = stack[-2];
    goto v123;

v123:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-5] = v107;
    stack[-6] = v107;
    goto v124;

v124:
    v107 = stack[-7];
    v107 = qcdr(v107);
    stack[-7] = v107;
    v107 = stack[-7];
    if (v107 == nil) goto v125;
    stack[-4] = stack[-5];
    v107 = stack[-7];
    v107 = qcar(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v126;
    v107 = stack[-3];
    v107 = qcar(v107);
    v108 = v107;
    v107 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 16)) = v107; /* !*sub2 */
    v107 = v108;
    fn = elt(env, 22); /* subs2 */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-1] = v107;
    stack[-2] = v107;
    goto v127;

v127:
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v128;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v108 = v107;
    v107 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 16)) = v107; /* !*sub2 */
    v107 = v108;
    fn = elt(env, 22); /* subs2 */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    goto v127;

v128:
    v107 = stack[-2];
    goto v129;

v129:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = Lrplacd(nil, stack[-4], v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = stack[-5];
    v107 = qcdr(v107);
    stack[-5] = v107;
    goto v124;

v126:
    v107 = qvalue(elt(env, 5)); /* nil */
    goto v129;

v125:
    v107 = stack[-6];
    goto v130;

v130:
    stack[-9] = v107;
    goto v131;

v131:
    v107 = stack[-8];
    v107 = qcdr(v107);
    stack[-8] = v107;
    goto v110;

v120:
    v107 = qvalue(elt(env, 5)); /* nil */
    goto v123;

v119:
    v107 = qvalue(elt(env, 5)); /* nil */
    goto v130;

v117:
    v108 = elt(env, 2); /* mat */
    v107 = elt(env, 13); /* inversefn */
    v108 = get(v108, v107);
    env = stack[-10];
    v107 = stack[-2];
    v108 = Lapply1(nil, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = stack[-9];
    fn = elt(env, 23); /* multm */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-9] = v107;
    goto v118;

v116:
    v108 = elt(env, 2); /* mat */
    v107 = elt(env, 13); /* inversefn */
    v108 = get(v108, v107);
    env = stack[-10];
    v107 = stack[-2];
    v107 = Lapply1(nil, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-9] = v107;
    goto v118;

v113:
    v107 = stack[-9];
    if (v107 == nil) goto v132;
    stack[0] = stack[-1];
    v107 = stack[-9];
    v107 = Llength(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    if (equal(stack[0], v107)) goto v132;
    v107 = elt(env, 9); /* "Matrix mismatch" */
    v108 = v107;
    v107 = v108;
    qvalue(elt(env, 7)) = v107; /* errmsg!* */
    v107 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v107 == nil)) goto v133;
    v107 = v108;
    fn = elt(env, 21); /* lprie */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v133;

v133:
    v107 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v115;

v132:
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    if (v107 == nil) goto v134;
    v107 = stack[-9];
    if (!(v107 == nil)) goto v131;
    v107 = stack[-1];
    fn = elt(env, 24); /* generateident */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-9] = v107;
    goto v131;

v134:
    v107 = stack[-2];
    v107 = qcdr(v107);
    if (!(v107 == nil)) goto v115;
    v107 = stack[-2];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    if (!(v107 == nil)) goto v115;
    v107 = stack[-2];
    v107 = qcar(v107);
    v107 = qcar(v107);
    v107 = qcar(v107);
    if (!(v107 == nil)) goto v135;
    v107 = elt(env, 17); /* "Zero divisor" */
    v108 = v107;
    v107 = v108;
    qvalue(elt(env, 7)) = v107; /* errmsg!* */
    v107 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v107 == nil)) goto v136;
    v107 = v108;
    fn = elt(env, 21); /* lprie */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v136;

v136:
    v107 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v135;

v135:
    v107 = stack[-2];
    v107 = qcar(v107);
    v107 = qcar(v107);
    v108 = qcdr(v107);
    v107 = stack[-2];
    v107 = qcar(v107);
    v107 = qcar(v107);
    v107 = qcar(v107);
    v107 = cons(v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-2] = v107;
    v107 = stack[-9];
    if (v107 == nil) goto v137;
    v108 = stack[-2];
    v107 = stack[-9];
    fn = elt(env, 25); /* multsm */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v138;

v138:
    stack[-9] = v107;
    goto v131;

v137:
    v107 = stack[-2];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v138;

v111:
    v107 = stack[-8];
    v107 = qcar(v107);
    if (!consp(v107)) goto v139;
    v107 = stack[-8];
    v107 = qcar(v107);
    v108 = qcar(v107);
    v107 = elt(env, 2); /* mat */
    if (v108 == v107) goto v140;
    v107 = stack[-8];
    v107 = qcar(v107);
    v108 = qcar(v107);
    v107 = elt(env, 3); /* matmapfn */
    v107 = Lflagp(nil, v108, v107);
    env = stack[-10];
    if (v107 == nil) goto v141;
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    if (v107 == nil) goto v141;
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    fn = elt(env, 26); /* getrtype */
    v108 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = elt(env, 4); /* matrix */
    if (!(v108 == v107)) goto v141;
    v107 = stack[-8];
    v108 = qcar(v107);
    v107 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 27); /* matrixmap */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    fn = elt(env, 20); /* matsm */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[0] = v107;
    goto v142;

v142:
    v107 = stack[-9];
    if (v107 == nil) goto v143;
    v107 = stack[-9];
    v107 = qcdr(v107);
    if (!(v107 == nil)) goto v144;
    v107 = stack[-9];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    if (!(v107 == nil)) goto v144;
    v107 = stack[-9];
    v107 = qcar(v107);
    v108 = qcar(v107);
    v107 = stack[0];
    fn = elt(env, 25); /* multsm */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v145;

v145:
    stack[-9] = v107;
    goto v131;

v144:
    v108 = stack[0];
    v107 = stack[-9];
    fn = elt(env, 23); /* multm */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v145;

v143:
    v107 = stack[0];
    goto v145;

v141:
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcar(v107);
    if (!consp(v107)) goto v146;
    v108 = elt(env, 6); /* "Apply called with non-id arg" */
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcar(v107);
    v107 = list2(v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v108 = v107;
    v107 = v108;
    qvalue(elt(env, 7)) = v107; /* errmsg!* */
    v107 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v107 == nil)) goto v147;
    v107 = v108;
    fn = elt(env, 21); /* lprie */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v147;

v147:
    v107 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = nil;
    goto v148;

v148:
    stack[0] = v107;
    v108 = stack[0];
    v107 = elt(env, 2); /* mat */
    if (!consp(v108)) goto v142;
    v108 = qcar(v108);
    if (!(v108 == v107)) goto v142;
    v107 = stack[0];
    fn = elt(env, 20); /* matsm */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[0] = v107;
    goto v142;

v146:
    v107 = stack[-8];
    v107 = qcar(v107);
    v108 = qcar(v107);
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    fn = elt(env, 28); /* apply */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v148;

v140:
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    fn = elt(env, 29); /* lchk */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    if (!(v107 == nil)) goto v149;
    v107 = elt(env, 9); /* "Matrix mismatch" */
    v108 = v107;
    v107 = v108;
    qvalue(elt(env, 7)) = v107; /* errmsg!* */
    v107 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v107 == nil)) goto v150;
    v107 = v108;
    fn = elt(env, 21); /* lprie */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v150;

v150:
    v107 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v149;

v149:
    v107 = stack[-8];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    stack[-7] = v107;
    v107 = stack[-7];
    if (v107 == nil) goto v151;
    v107 = stack[-7];
    v107 = qcar(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v152;
    v107 = stack[-3];
    v107 = qcar(v107);
    fn = elt(env, 30); /* simp!* */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v108 = v107;
    v107 = qvalue(elt(env, 10)); /* !*exp */
    if (v107 == nil) goto v153;
    v107 = v108;
    goto v154;

v154:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-1] = v107;
    stack[-2] = v107;
    goto v155;

v155:
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v156;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    fn = elt(env, 30); /* simp!* */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v108 = v107;
    v107 = qvalue(elt(env, 10)); /* !*exp */
    if (v107 == nil) goto v157;
    v107 = v108;
    goto v158;

v158:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    goto v155;

v157:
    v107 = v108;
    fn = elt(env, 31); /* offexpchk */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v158;

v156:
    v107 = stack[-2];
    goto v159;

v159:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-5] = v107;
    stack[-6] = v107;
    goto v160;

v160:
    v107 = stack[-7];
    v107 = qcdr(v107);
    stack[-7] = v107;
    v107 = stack[-7];
    if (v107 == nil) goto v161;
    stack[-4] = stack[-5];
    v107 = stack[-7];
    v107 = qcar(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v162;
    v107 = stack[-3];
    v107 = qcar(v107);
    fn = elt(env, 30); /* simp!* */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v108 = v107;
    v107 = qvalue(elt(env, 10)); /* !*exp */
    if (v107 == nil) goto v163;
    v107 = v108;
    goto v164;

v164:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    stack[-1] = v107;
    stack[-2] = v107;
    goto v165;

v165:
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v166;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    fn = elt(env, 30); /* simp!* */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v108 = v107;
    v107 = qvalue(elt(env, 10)); /* !*exp */
    if (v107 == nil) goto v167;
    v107 = v108;
    goto v168;

v168:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    goto v165;

v167:
    v107 = v108;
    fn = elt(env, 31); /* offexpchk */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v168;

v166:
    v107 = stack[-2];
    goto v169;

v169:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = Lrplacd(nil, stack[-4], v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v107 = stack[-5];
    v107 = qcdr(v107);
    stack[-5] = v107;
    goto v160;

v163:
    v107 = v108;
    fn = elt(env, 31); /* offexpchk */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v164;

v162:
    v107 = qvalue(elt(env, 5)); /* nil */
    goto v169;

v161:
    v107 = stack[-6];
    goto v170;

v170:
    stack[0] = v107;
    goto v142;

v153:
    v107 = v108;
    fn = elt(env, 31); /* offexpchk */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v154;

v152:
    v107 = qvalue(elt(env, 5)); /* nil */
    goto v159;

v151:
    v107 = qvalue(elt(env, 5)); /* nil */
    goto v170;

v139:
    v109 = elt(env, 18); /* "Matrix" */
    v107 = stack[-8];
    v108 = qcar(v107);
    v107 = elt(env, 19); /* "not set" */
    v107 = list3(v109, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    v108 = v107;
    v107 = v108;
    qvalue(elt(env, 7)) = v107; /* errmsg!* */
    v107 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v107 == nil)) goto v171;
    v107 = v108;
    fn = elt(env, 21); /* lprie */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-10];
    goto v171;

v171:
    v107 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    v107 = nil;
    { popv(11); return onevalue(v107); }
/* error exit handlers */
v112:
    popv(11);
    return nil;
}



/* Code for unify */

static Lisp_Object MS_CDECL CC_unify(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v6,
                         Lisp_Object v5, Lisp_Object v172,
                         Lisp_Object v173, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v101, v170, v160, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "unify");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unify");
#endif
    if (stack >= stacklimit)
    {
        push5(v173,v172,v5,v6,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v9,v6,v5,v172,v173);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-13] = v173;
    stack[-14] = v172;
    v101 = v5;
    v170 = v6;
    v66 = v9;
/* end of prologue */
    stack[-15] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-12] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-11] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v66; /* op */
    v66 = v170;
    qvalue(elt(env, 2)) = v66; /* r */
    v66 = v101;
    qvalue(elt(env, 3)) = v66; /* p */
    v66 = qvalue(elt(env, 2)); /* r */
    if (!(v66 == nil)) goto v203;
    v66 = qvalue(elt(env, 3)); /* p */
    if (!(v66 == nil)) goto v203;
    v101 = stack[-14];
    v66 = stack[-13];
    fn = elt(env, 14); /* resume */
    v66 = (*qfn2(fn))(qenv(fn), v101, v66);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-16];
    goto v204;

v204:
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    { popv(17); return onevalue(v66); }

v203:
    v66 = qvalue(elt(env, 2)); /* r */
    if (v66 == nil) goto v99;
    v66 = qvalue(elt(env, 3)); /* p */
    if (!(v66 == nil)) goto v205;
    v66 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 15); /* ident */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-16];
    if (!(v66 == nil)) goto v205;
    v66 = qvalue(elt(env, 2)); /* r */
    v66 = qcar(v66);
    fn = elt(env, 16); /* mgenp */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-16];
    if (!(v66 == nil)) goto v205;
    v66 = qvalue(elt(env, 5)); /* nil */
    goto v204;

v205:
    stack[0] = nil;
    stack[-8] = qvalue(elt(env, 6)); /* symm */
    qvalue(elt(env, 6)) = nil; /* symm */
    stack[-7] = qvalue(elt(env, 7)); /* comb */
    qvalue(elt(env, 7)) = nil; /* comb */
    stack[-6] = qvalue(elt(env, 8)); /* identity */
    qvalue(elt(env, 8)) = nil; /* identity */
    stack[-5] = qvalue(elt(env, 9)); /* mcontract */
    qvalue(elt(env, 9)) = nil; /* mcontract */
    stack[-4] = qvalue(elt(env, 10)); /* acontract */
    qvalue(elt(env, 10)) = nil; /* acontract */
    stack[-3] = qvalue(elt(env, 11)); /* expand */
    qvalue(elt(env, 11)) = nil; /* expand */
    stack[-2] = qvalue(elt(env, 12)); /* i */
    qvalue(elt(env, 12)) = nil; /* i */
    stack[-1] = qvalue(elt(env, 13)); /* upb */
    qvalue(elt(env, 13)) = nil; /* upb */
    v66 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v66; /* i */
    v66 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 13)) = v66; /* upb */
    v66 = qvalue(elt(env, 2)); /* r */
    v66 = qcar(v66);
    fn = elt(env, 17); /* pm!:free */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    if (v66 == nil) goto v93;
    v66 = qvalue(elt(env, 2)); /* r */
    v66 = qcar(v66);
    fn = elt(env, 18); /* genp */
    v101 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    v66 = stack[-14];
    v66 = cons(v101, v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    stack[-14] = v66;
    goto v93;

v93:
    v66 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 19); /* initarg */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    goto v206;

v206:
    v66 = stack[0];
    if (!(v66 == nil)) goto v148;
    v66 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 20); /* nextarg */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    stack[-9] = v66;
    if (v66 == nil) goto v148;
    v66 = qvalue(elt(env, 2)); /* r */
    v66 = qcar(v66);
    if (!consp(v66)) goto v207;
    v202 = qvalue(elt(env, 1)); /* op */
    v160 = qvalue(elt(env, 2)); /* r */
    v170 = stack[-9];
    v101 = stack[-14];
    v66 = stack[-13];
    fn = elt(env, 21); /* suspend */
    v66 = (*qfnn(fn))(qenv(fn), 5, v202, v160, v170, v101, v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    stack[0] = v66;
    goto v206;

v207:
    v66 = qvalue(elt(env, 2)); /* r */
    v66 = qcar(v66);
    fn = elt(env, 17); /* pm!:free */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    if (v66 == nil) goto v208;
    v66 = qvalue(elt(env, 2)); /* r */
    v101 = qcar(v66);
    v66 = stack[-9];
    v66 = qcar(v66);
    fn = elt(env, 22); /* bind */
    v66 = (*qfn2(fn))(qenv(fn), v101, v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    v66 = stack[-14];
    fn = elt(env, 23); /* chk */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    stack[-10] = v66;
    if (v66 == nil) goto v209;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v66 = qvalue(elt(env, 2)); /* r */
    v66 = qcdr(v66);
    fn = elt(env, 24); /* mval */
    v160 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    v66 = stack[-9];
    v170 = qcdr(v66);
    v101 = stack[-10];
    v66 = stack[-13];
    v66 = CC_unify(env, 5, stack[0], v160, v170, v101, v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    stack[0] = v66;
    goto v209;

v209:
    v66 = qvalue(elt(env, 2)); /* r */
    v66 = qcar(v66);
    fn = elt(env, 25); /* unbind */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    goto v206;

v208:
    v66 = qvalue(elt(env, 2)); /* r */
    v101 = qcar(v66);
    v66 = stack[-9];
    v66 = qcar(v66);
    fn = elt(env, 26); /* meq */
    v66 = (*qfn2(fn))(qenv(fn), v101, v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    if (v66 == nil) goto v206;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v66 = qvalue(elt(env, 2)); /* r */
    v66 = qcdr(v66);
    fn = elt(env, 24); /* mval */
    v160 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    v66 = stack[-9];
    v170 = qcdr(v66);
    v101 = stack[-14];
    v66 = stack[-13];
    v66 = CC_unify(env, 5, stack[0], v160, v170, v101, v66);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-16];
    stack[0] = v66;
    goto v206;

v148:
    v66 = stack[0];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    goto v204;

v99:
    v66 = elt(env, 4); /* "UNIFY:pattern over-run for function " */
    v66 = Lprinc(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-16];
    v66 = qvalue(elt(env, 1)); /* op */
    v66 = Lprint(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-16];
    v66 = qvalue(elt(env, 5)); /* nil */
    goto v204;
/* error exit handlers */
v155:
    env = stack[-16];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
v159:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
}



/* Code for vdpvevlcomp */

static Lisp_Object CC_vdpvevlcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpvevlcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v212 = v210;
    v203 = v0;
/* end of prologue */
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    v203 = qcar(v203);
    v212 = qcdr(v212);
    v212 = qcdr(v212);
    v212 = qcdr(v212);
    v212 = qcar(v212);
    {
        fn = elt(env, 1); /* dipevlcomp */
        return (*qfn2(fn))(qenv(fn), v203, v212);
    }
}



/* Code for mkfortterpri */

static Lisp_Object MS_CDECL CC_mkfortterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkfortterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkfortterpri");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v9 = elt(env, 1); /* fortterpri */
    return ncons(v9);
}



/* Code for indordn */

static Lisp_Object CC_indordn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordn");
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
    v218 = v0;
/* end of prologue */
    v217 = v218;
    if (v217 == nil) goto v6;
    v217 = v218;
    v217 = qcdr(v217);
    if (v217 == nil) { popv(2); return onevalue(v218); }
    v217 = v218;
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    if (v217 == nil) goto v212;
    v217 = v218;
    stack[0] = qcar(v217);
    v217 = v218;
    v217 = qcdr(v217);
    v217 = CC_indordn(env, v217);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-1];
    {
        Lisp_Object v220 = stack[0];
        popv(2);
        fn = elt(env, 2); /* indordad */
        return (*qfn2(fn))(qenv(fn), v220, v217);
    }

v212:
    v217 = v218;
    v217 = qcar(v217);
    v218 = qcdr(v218);
    v218 = qcar(v218);
    {
        popv(2);
        fn = elt(env, 3); /* indord2 */
        return (*qfn2(fn))(qenv(fn), v217, v218);
    }

v6:
    v217 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v217); }
/* error exit handlers */
v219:
    popv(2);
    return nil;
}



/* Code for fieldconv */

static Lisp_Object CC_fieldconv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v249, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fieldconv");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v210;
    stack[-2] = v0;
/* end of prologue */
    v153 = stack[-1];
    v153 = qcar(v153);
    stack[-3] = v153;
    v153 = stack[-1];
    v153 = qcdr(v153);
    stack[0] = v153;
    v153 = qvalue(elt(env, 1)); /* dmode!* */
    if (v153 == nil) goto v251;
    v153 = stack[0];
    if (!consp(v153)) goto v252;
    v153 = stack[0];
    v153 = qcar(v153);
    if (!consp(v153)) goto v252;
    v249 = stack[-3];
    v153 = stack[-2];
    fn = elt(env, 12); /* divd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v249 = stack[0];
    v153 = stack[-2];
    fn = elt(env, 12); /* divd */
    v153 = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    {
        Lisp_Object v156 = stack[-1];
        popv(5);
        return cons(v156, v153);
    }

v252:
    v249 = stack[-3];
    v153 = stack[0];
    fn = elt(env, 12); /* divd */
    v249 = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    v153 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v249, v153);

v251:
    v249 = stack[-2];
    v153 = elt(env, 2); /* !:rn!: */
    if (!consp(v249)) goto v254;
    v249 = qcar(v249);
    if (!(v249 == v153)) goto v254;

v255:
    v153 = stack[-2];
    v250 = qcar(v153);
    v153 = stack[-2];
    v153 = qcdr(v153);
    v249 = qcdr(v153);
    v153 = stack[-2];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = list2star(v250, v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    stack[-2] = v153;
    v153 = stack[0];
    if (!consp(v153)) goto v80;
    v153 = stack[0];
    v153 = qcar(v153);
    if (!consp(v153)) goto v80;
    v249 = stack[-2];
    v153 = stack[-3];
    fn = elt(env, 13); /* multd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v249 = stack[-2];
    v153 = stack[0];
    fn = elt(env, 13); /* multd */
    v153 = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v153 = cons(stack[-1], v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    goto v256;

v256:
    {
        popv(5);
        fn = elt(env, 14); /* simpgd */
        return (*qfn1(fn))(qenv(fn), v153);
    }

v80:
    v249 = stack[-2];
    v153 = stack[-3];
    fn = elt(env, 13); /* multd */
    v249 = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v153 = (Lisp_Object)17; /* 1 */
    v153 = cons(v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    goto v256;

v254:
    v153 = stack[-2];
    v249 = qcar(v153);
    v153 = elt(env, 2); /* !:rn!: */
    v153 = get(v249, v153);
    env = stack[-4];
    v249 = v153;
    if (v153 == nil) goto v183;
    v153 = v249;
    if (!(!consp(v153))) goto v183;
    v153 = stack[-2];
    v153 = Lapply1(nil, v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    stack[-2] = v153;
    goto v255;

v183:
    v153 = stack[-2];
    v249 = qcar(v153);
    v153 = elt(env, 3); /* quotient */
    v153 = get(v249, v153);
    env = stack[-4];
    if (v153 == nil) goto v257;
    v250 = (Lisp_Object)17; /* 1 */
    v249 = stack[-2];
    v153 = elt(env, 3); /* quotient */
    fn = elt(env, 15); /* dcombine */
    v153 = (*qfnn(fn))(qenv(fn), 3, v250, v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    stack[-2] = v153;
    v249 = stack[-2];
    v153 = stack[-1];
    v153 = qcar(v153);
    fn = elt(env, 13); /* multd */
    stack[0] = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v249 = stack[-2];
    v153 = stack[-1];
    v153 = qcdr(v153);
    fn = elt(env, 13); /* multd */
    v153 = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    {
        Lisp_Object v258 = stack[0];
        popv(5);
        return cons(v258, v153);
    }

v257:
    v153 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 16); /* terpri!* */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v153 = elt(env, 5); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 17); /* lprie */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v249 = elt(env, 6); /* "field conversion" */
    v153 = stack[-2];
    v153 = list2(v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    fn = elt(env, 18); /* printty */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v249 = elt(env, 7); /* " " */
    v153 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 19); /* lpriw */
    v153 = (*qfn2(fn))(qenv(fn), v249, v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    v153 = elt(env, 9); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v249 = v153;
    v153 = v249;
    qvalue(elt(env, 10)) = v153; /* errmsg!* */
    v153 = qvalue(elt(env, 11)); /* !*protfg */
    if (!(v153 == nil)) goto v259;
    v153 = v249;
    fn = elt(env, 17); /* lprie */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    goto v259;

v259:
    v153 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    goto v255;
/* error exit handlers */
v253:
    popv(5);
    return nil;
}



/* Code for groeb!=newpair */

static Lisp_Object MS_CDECL CC_groebMnewpair(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v210,
                         Lisp_Object v29, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v264, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=newpair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=newpair");
#endif
    if (stack >= stacklimit)
    {
        push3(v29,v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v210,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v29;
    stack[-3] = v210;
    stack[-1] = v0;
/* end of prologue */
    v98 = stack[-3];
    fn = elt(env, 1); /* bas_dpoly */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    v98 = stack[-2];
    fn = elt(env, 1); /* bas_dpoly */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    fn = elt(env, 3); /* mo_lcm */
    v98 = (*qfn2(fn))(qenv(fn), stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    stack[0] = v98;
    stack[-4] = stack[-1];
    v265 = stack[0];
    v264 = stack[-3];
    v98 = stack[-2];
    fn = elt(env, 4); /* groeb!=weight */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v265, v264, v98);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    v264 = stack[-3];
    v98 = stack[-2];
    v98 = list2(v264, v98);
    nil = C_nil;
    if (exception_pending()) goto v183;
    {
        Lisp_Object v193 = stack[-4];
        Lisp_Object v187 = stack[-1];
        Lisp_Object v181 = stack[0];
        popv(6);
        return list3star(v193, v187, v181, v98);
    }
/* error exit handlers */
v183:
    popv(6);
    return nil;
}



/* Code for simp!-prop1 */

static Lisp_Object CC_simpKprop1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v319, v320, v321;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop1");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v210;
    stack[-4] = v0;
/* end of prologue */

v322:
    v319 = stack[-4];
    if (!consp(v319)) goto v169;
    v319 = stack[-4];
    v320 = qcar(v319);
    v319 = qvalue(elt(env, 1)); /* !'and */
    if (!(equal(v320, v319))) goto v201;
    v319 = stack[-3];
    if (!(v319 == nil)) goto v323;

v201:
    v319 = stack[-4];
    v320 = qcar(v319);
    v319 = qvalue(elt(env, 2)); /* !'or */
    if (!(equal(v320, v319))) goto v324;
    v319 = stack[-3];
    if (!(v319 == nil)) goto v324;

v323:
    v319 = (Lisp_Object)17; /* 1 */
    stack[0] = v319;
    v319 = stack[-4];
    v319 = qcdr(v319);
    stack[-1] = v319;
    goto v219;

v219:
    v319 = stack[-1];
    if (v319 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v319 = stack[-1];
    v319 = qcar(v319);
    v320 = v319;
    v319 = stack[-3];
    v319 = CC_simpKprop1(env, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    fn = elt(env, 18); /* multf */
    v319 = (*qfn2(fn))(qenv(fn), stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    stack[0] = v319;
    v319 = stack[-1];
    v319 = qcdr(v319);
    stack[-1] = v319;
    goto v219;

v324:
    v319 = stack[-4];
    v320 = qcar(v319);
    v319 = qvalue(elt(env, 2)); /* !'or */
    if (!(equal(v320, v319))) goto v84;
    v319 = stack[-3];
    if (!(v319 == nil)) goto v244;

v84:
    v319 = stack[-4];
    v320 = qcar(v319);
    v319 = qvalue(elt(env, 1)); /* !'and */
    if (!(equal(v320, v319))) goto v326;
    v319 = stack[-3];
    if (!(v319 == nil)) goto v326;

v244:
    v319 = qvalue(elt(env, 3)); /* nil */
    stack[0] = v319;
    v319 = stack[-4];
    v319 = qcdr(v319);
    stack[-1] = v319;
    goto v327;

v327:
    v319 = stack[-1];
    if (v319 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v319 = stack[-1];
    v319 = qcar(v319);
    v320 = v319;
    v319 = stack[-3];
    v319 = CC_simpKprop1(env, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    fn = elt(env, 19); /* addf */
    v319 = (*qfn2(fn))(qenv(fn), stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    stack[0] = v319;
    v319 = stack[-1];
    v319 = qcdr(v319);
    stack[-1] = v319;
    goto v327;

v326:
    v319 = stack[-4];
    v320 = qcar(v319);
    v319 = elt(env, 4); /* not */
    if (v320 == v319) goto v82;
    v319 = stack[-4];
    v320 = qcar(v319);
    v319 = elt(env, 5); /* implies */
    if (v320 == v319) goto v229;
    v319 = stack[-4];
    v320 = qcar(v319);
    v319 = elt(env, 8); /* equiv */
    if (!(v320 == v319)) goto v173;
    stack[-5] = elt(env, 6); /* or */
    v321 = elt(env, 9); /* and */
    v319 = stack[-4];
    v319 = qcdr(v319);
    v320 = qcar(v319);
    v319 = stack[-4];
    v319 = qcdr(v319);
    v319 = qcdr(v319);
    v319 = qcar(v319);
    stack[-2] = list3(v321, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    stack[-1] = elt(env, 9); /* and */
    v320 = elt(env, 4); /* not */
    v319 = stack[-4];
    v319 = qcdr(v319);
    v319 = qcar(v319);
    stack[0] = list2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v320 = elt(env, 4); /* not */
    v319 = stack[-4];
    v319 = qcdr(v319);
    v319 = qcdr(v319);
    v319 = qcar(v319);
    v319 = list2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v319 = list3(stack[-1], stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v320 = list3(stack[-5], stack[-2], v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v319 = stack[-3];
    v319 = CC_simpKprop1(env, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    stack[0] = v319;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v173:
    v319 = stack[-4];
    fn = elt(env, 20); /* reval */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    stack[-4] = v319;
    v320 = stack[-4];
    v319 = elt(env, 14); /* boolean */
    if (!consp(v320)) goto v48;
    v320 = qcar(v320);
    if (!(v320 == v319)) goto v48;
    v319 = stack[-4];
    v319 = qcdr(v319);
    v320 = qcar(v319);
    v319 = stack[-3];
    stack[-4] = v320;
    stack[-3] = v319;
    goto v322;

v48:
    v319 = stack[-3];
    if (v319 == nil) goto v328;
    v319 = elt(env, 15); /* prop!* */
    v320 = v319;
    goto v329;

v329:
    v319 = stack[-4];
    v319 = list2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    fn = elt(env, 21); /* simp */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v319 = qcar(v319);
    stack[0] = v319;
    v320 = stack[-4];
    v319 = qvalue(elt(env, 17)); /* propvars!* */
    v319 = Lmember(nil, v320, v319);
    if (!(v319 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v320 = stack[-4];
    v319 = qvalue(elt(env, 17)); /* propvars!* */
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    qvalue(elt(env, 17)) = v319; /* propvars!* */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v328:
    v319 = elt(env, 16); /* not_prop!* */
    v320 = v319;
    goto v329;

v229:
    v319 = stack[-3];
    if (v319 == nil) goto v101;
    stack[0] = elt(env, 6); /* or */
    v320 = elt(env, 4); /* not */
    v319 = stack[-4];
    v319 = qcdr(v319);
    v319 = qcar(v319);
    v320 = list2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v319 = stack[-4];
    v319 = qcdr(v319);
    v319 = qcdr(v319);
    v319 = qcar(v319);
    v320 = list3(stack[0], v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v319 = qvalue(elt(env, 7)); /* t */
    v319 = CC_simpKprop1(env, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    stack[0] = v319;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v101:
    stack[0] = elt(env, 6); /* or */
    v320 = elt(env, 4); /* not */
    v319 = stack[-4];
    v319 = qcdr(v319);
    v319 = qcdr(v319);
    v319 = qcar(v319);
    v320 = list2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v319 = stack[-4];
    v319 = qcdr(v319);
    v319 = qcar(v319);
    v320 = list3(stack[0], v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-6];
    v319 = qvalue(elt(env, 7)); /* t */
    v319 = CC_simpKprop1(env, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    stack[0] = v319;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v82:
    v319 = stack[-4];
    v319 = qcdr(v319);
    v320 = qcar(v319);
    v319 = stack[-3];
    v319 = (v319 == nil ? lisp_true : nil);
    v319 = CC_simpKprop1(env, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v325;
    stack[0] = v319;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v169:
    v320 = stack[-4];
    v319 = (Lisp_Object)17; /* 1 */
    if (v320 == v319) goto v62;
    v320 = stack[-4];
    v319 = qvalue(elt(env, 7)); /* t */
    if (equal(v320, v319)) goto v62;
    v320 = stack[-4];
    v319 = elt(env, 10); /* true */
    if (v320 == v319) goto v62;
    v320 = stack[-4];
    v319 = (Lisp_Object)1; /* 0 */
    if (v320 == v319) goto v330;
    v319 = stack[-4];
    if (v319 == nil) goto v330;
    v320 = stack[-4];
    v319 = elt(env, 11); /* false */
    if (!(v320 == v319)) goto v331;

v330:
    v319 = stack[-3];
    v319 = (v319 == nil ? lisp_true : nil);
    stack[-4] = v319;
    goto v331;

v331:
    v320 = stack[-4];
    v319 = qvalue(elt(env, 7)); /* t */
    if (equal(v320, v319)) goto v332;
    v319 = stack[-4];
    if (!(v319 == nil)) goto v173;
    v320 = elt(env, 13); /* (and !*true (not !*true)) */
    v319 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v320;
    stack[-3] = v319;
    goto v322;

v332:
    v320 = elt(env, 12); /* (or !*true (not !*true)) */
    v319 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v320;
    stack[-3] = v319;
    goto v322;

v62:
    v319 = stack[-3];
    stack[-4] = v319;
    goto v331;
/* error exit handlers */
v325:
    popv(7);
    return nil;
}



/* Code for ad_splitname */

static Lisp_Object CC_ad_splitname(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_splitname");
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
    v176 = v0;
/* end of prologue */
    v178 = v176;
    if (symbolp(v178)) goto v6;
    v178 = nil;
    { popv(3); return onevalue(v178); }

v6:
    stack[0] = nil;
    v178 = v176;
    v178 = Lexplode(nil, v178);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-2];
    v178 = Lreverse(nil, v178);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-2];
    stack[-1] = v178;
    goto v261;

v261:
    v178 = stack[-1];
    if (v178 == nil) goto v323;
    v178 = stack[-1];
    v178 = qcar(v178);
    fn = elt(env, 2); /* charnump!: */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-2];
    if (v178 == nil) goto v323;
    v178 = stack[-1];
    v176 = qcar(v178);
    v178 = stack[0];
    v178 = cons(v176, v178);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-2];
    stack[0] = v178;
    v178 = stack[-1];
    v178 = qcdr(v178);
    stack[-1] = v178;
    goto v261;

v323:
    v178 = stack[-1];
    if (v178 == nil) goto v247;
    v178 = stack[-1];
    v178 = Lreverse(nil, v178);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-2];
    v178 = Lcompress(nil, v178);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-2];
    v178 = Lintern(nil, v178);
    nil = C_nil;
    if (exception_pending()) goto v333;
    env = stack[-2];
    stack[-1] = v178;
    goto v247;

v247:
    v178 = stack[0];
    if (v178 == nil) goto v193;
    v178 = stack[0];
    v178 = Lcompress(nil, v178);
    nil = C_nil;
    if (exception_pending()) goto v333;
    stack[0] = v178;
    goto v193;

v193:
    v176 = stack[-1];
    v178 = stack[0];
    popv(3);
    return cons(v176, v178);
/* error exit handlers */
v333:
    popv(3);
    return nil;
}



/* Code for bfrsq */

static Lisp_Object CC_bfrsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfrsq");
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
    v95 = v0;
/* end of prologue */
    v181 = v95;
    v181 = qcar(v181);
    v95 = qcdr(v95);
    stack[-1] = v95;
    v95 = v181;
    if (!consp(v95)) goto v203;
    v95 = v181;
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v95, v181);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-2];
    v95 = stack[-1];
    v181 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v181 = (*qfn2(fn))(qenv(fn), v95, v181);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-2];
    {
        Lisp_Object v178 = stack[0];
        popv(3);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v178, v181);
    }

v203:
    v95 = v181;
    stack[0] = times2(v95, v181);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-2];
    v95 = stack[-1];
    v181 = stack[-1];
    v181 = times2(v95, v181);
    nil = C_nil;
    if (exception_pending()) goto v180;
    {
        Lisp_Object v176 = stack[0];
        popv(3);
        return plus2(v176, v181);
    }
/* error exit handlers */
v180:
    popv(3);
    return nil;
}



/* Code for gen!+can!+bas */

static Lisp_Object CC_genLcanLbas(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v298, v346;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gen+can+bas");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0;
/* end of prologue */
    v346 = (Lisp_Object)17; /* 1 */
    v298 = (Lisp_Object)17; /* 1 */
    v298 = cons(v346, v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    stack[-10] = v298;
    v346 = qvalue(elt(env, 1)); /* nil */
    v298 = (Lisp_Object)17; /* 1 */
    v298 = cons(v346, v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    stack[-8] = v298;
    v298 = (Lisp_Object)17; /* 1 */
    stack[-7] = v298;
    v346 = stack[-9];
    v298 = stack[-7];
    v298 = difference2(v346, v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lminusp(nil, v298);
    env = stack[-11];
    if (v298 == nil) goto v99;
    v298 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v298); }

v99:
    v298 = (Lisp_Object)17; /* 1 */
    stack[-3] = v298;
    v346 = stack[-9];
    v298 = stack[-3];
    v298 = difference2(v346, v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lminusp(nil, v298);
    env = stack[-11];
    if (v298 == nil) goto v243;
    v298 = qvalue(elt(env, 1)); /* nil */
    goto v245;

v245:
    v298 = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    stack[-5] = v298;
    stack[-6] = v298;
    goto v347;

v347:
    v298 = stack[-7];
    v298 = add1(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    stack[-7] = v298;
    v346 = stack[-9];
    v298 = stack[-7];
    v298 = difference2(v346, v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lminusp(nil, v298);
    env = stack[-11];
    if (!(v298 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    v298 = (Lisp_Object)17; /* 1 */
    stack[-3] = v298;
    v346 = stack[-9];
    v298 = stack[-3];
    v298 = difference2(v346, v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lminusp(nil, v298);
    env = stack[-11];
    if (v298 == nil) goto v144;
    v298 = qvalue(elt(env, 1)); /* nil */
    goto v306;

v306:
    v298 = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lrplacd(nil, stack[-4], v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = stack[-5];
    v298 = qcdr(v298);
    stack[-5] = v298;
    goto v347;

v144:
    v346 = stack[-7];
    v298 = stack[-3];
    if (equal(v346, v298)) goto v348;
    v298 = stack[-8];
    goto v349;

v349:
    v298 = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    stack[-1] = v298;
    stack[-2] = v298;
    goto v229;

v229:
    v298 = stack[-3];
    v298 = add1(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    stack[-3] = v298;
    v346 = stack[-9];
    v298 = stack[-3];
    v298 = difference2(v346, v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lminusp(nil, v298);
    env = stack[-11];
    if (v298 == nil) goto v185;
    v298 = stack[-2];
    goto v306;

v185:
    stack[0] = stack[-1];
    v346 = stack[-7];
    v298 = stack[-3];
    if (equal(v346, v298)) goto v350;
    v298 = stack[-8];
    goto v202;

v202:
    v298 = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lrplacd(nil, stack[0], v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = stack[-1];
    v298 = qcdr(v298);
    stack[-1] = v298;
    goto v229;

v350:
    v298 = stack[-10];
    goto v202;

v348:
    v298 = stack[-10];
    goto v349;

v243:
    v346 = stack[-7];
    v298 = stack[-3];
    if (equal(v346, v298)) goto v312;
    v298 = stack[-8];
    goto v311;

v311:
    v298 = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    stack[-1] = v298;
    stack[-2] = v298;
    goto v246;

v246:
    v298 = stack[-3];
    v298 = add1(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    stack[-3] = v298;
    v346 = stack[-9];
    v298 = stack[-3];
    v298 = difference2(v346, v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lminusp(nil, v298);
    env = stack[-11];
    if (v298 == nil) goto v308;
    v298 = stack[-2];
    goto v245;

v308:
    stack[0] = stack[-1];
    v346 = stack[-7];
    v298 = stack[-3];
    if (equal(v346, v298)) goto v351;
    v298 = stack[-8];
    goto v87;

v87:
    v298 = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = Lrplacd(nil, stack[0], v298);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-11];
    v298 = stack[-1];
    v298 = qcdr(v298);
    stack[-1] = v298;
    goto v246;

v351:
    v298 = stack[-10];
    goto v87;

v312:
    v298 = stack[-10];
    goto v311;
/* error exit handlers */
v76:
    popv(12);
    return nil;
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v334, v254;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for carx");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v334 = v210;
    v254 = v0;
/* end of prologue */
    v99 = v254;
    v99 = qcdr(v99);
    if (v99 == nil) goto v5;
    v99 = elt(env, 1); /* "Wrong number of arguments to" */
    v99 = list2(v99, v334);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[0];
    v334 = v99;
    v99 = v334;
    qvalue(elt(env, 2)) = v99; /* errmsg!* */
    v99 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v99 == nil)) goto v313;
    v99 = v334;
    fn = elt(env, 4); /* lprie */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[0];
    goto v313;

v313:
    v99 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v263;
    v99 = nil;
    { popv(1); return onevalue(v99); }

v5:
    v99 = v254;
    v99 = qcar(v99);
    { popv(1); return onevalue(v99); }
/* error exit handlers */
v263:
    popv(1);
    return nil;
}



/* Code for qqe_simplterm!-tail */

static Lisp_Object CC_qqe_simpltermKtail(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v356, v357, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplterm-tail");
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
    v356 = stack[-2];
    fn = elt(env, 7); /* qqe_arg2l */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    stack[-3] = v356;
    v357 = stack[-3];
    v356 = elt(env, 1); /* qepsilon */
    if (v357 == v356) goto v140;
    v356 = stack[-3];
    if (!consp(v356)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v356 = stack[-2];
    fn = elt(env, 8); /* qqe_op */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    stack[-1] = v356;
    v356 = stack[-3];
    fn = elt(env, 8); /* qqe_op */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    stack[0] = v356;
    v357 = stack[0];
    v356 = elt(env, 2); /* (ladd radd) */
    v356 = Lmemq(nil, v357, v356);
    if (v356 == nil) goto v347;
    v356 = stack[-3];
    fn = elt(env, 9); /* qqe_arg2r */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    v146 = v356;
    v357 = v146;
    v356 = elt(env, 1); /* qepsilon */
    if (v357 == v356) goto v220;
    v357 = stack[-1];
    v356 = elt(env, 3); /* ltail */
    if (!(v357 == v356)) goto v324;
    v357 = stack[0];
    v356 = elt(env, 4); /* radd */
    if (v357 == v356) { popv(5); return onevalue(v146); }
    else goto v324;

v324:
    v357 = stack[-1];
    v356 = elt(env, 5); /* rtail */
    if (!(v357 == v356)) goto v347;
    v357 = stack[0];
    v356 = elt(env, 6); /* ladd */
    if (v357 == v356) { popv(5); return onevalue(v146); }
    else goto v347;

v347:
    v356 = stack[-3];
    fn = elt(env, 10); /* qqe_simplterm */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    v146 = v356;
    v357 = v146;
    v356 = stack[-3];
    if (equal(v357, v356)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v356 = stack[-1];
    v357 = v146;
    v356 = list2(v356, v357);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 10); /* qqe_simplterm */
        return (*qfn1(fn))(qenv(fn), v356);
    }

v220:
    v356 = elt(env, 1); /* qepsilon */
    { popv(5); return onevalue(v356); }

v140:
    v356 = elt(env, 1); /* qepsilon */
    { popv(5); return onevalue(v356); }
/* error exit handlers */
v196:
    popv(5);
    return nil;
}



/* Code for fctrf1 */

static Lisp_Object CC_fctrf1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v364, v286, v284;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctrf1");
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
    stack[-3] = v0;
/* end of prologue */
    stack[-1] = nil;
    v364 = stack[-3];
    if (!consp(v364)) goto v142;
    v364 = stack[-3];
    v364 = qcar(v364);
    if (!consp(v364)) goto v142;
    v286 = qvalue(elt(env, 1)); /* dmode!* */
    v364 = elt(env, 2); /* field */
    v364 = Lflagp(nil, v286, v364);
    env = stack[-5];
    if (v364 == nil) goto v352;
    v364 = stack[-3];
    fn = elt(env, 4); /* lnc */
    v286 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-1] = v286;
    v364 = (Lisp_Object)17; /* 1 */
    if (v286 == v364) goto v352;
    v364 = stack[-1];
    fn = elt(env, 5); /* !:recip */
    v286 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-3];
    fn = elt(env, 6); /* multd */
    v364 = (*qfn2(fn))(qenv(fn), v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-3] = v364;
    goto v212;

v212:
    v364 = stack[-3];
    fn = elt(env, 7); /* comfac */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-4] = v364;
    stack[0] = stack[-3];
    v364 = stack[-4];
    v364 = qcar(v364);
    if (v364 == nil) goto v309;
    v364 = stack[-4];
    v364 = ncons(v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    goto v206;

v206:
    fn = elt(env, 8); /* quotf */
    v364 = (*qfn2(fn))(qenv(fn), stack[0], v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-3] = v364;
    v364 = stack[-4];
    v364 = qcdr(v364);
    v364 = CC_fctrf1(env, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-2] = v364;
    v364 = stack[-4];
    v364 = qcar(v364);
    if (v364 == nil) goto v366;
    v364 = stack[-2];
    stack[0] = qcar(v364);
    v364 = stack[-4];
    v364 = qcar(v364);
    v284 = qcar(v364);
    v286 = (Lisp_Object)17; /* 1 */
    v364 = (Lisp_Object)17; /* 1 */
    v364 = acons(v284, v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v286 = ncons(v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-4];
    v364 = qcar(v364);
    v364 = qcdr(v364);
    v286 = cons(v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-2];
    v364 = qcdr(v364);
    v364 = list2star(stack[0], v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-2] = v364;
    goto v366;

v366:
    v364 = stack[-1];
    if (v364 == nil) goto v236;
    v286 = stack[-1];
    v364 = (Lisp_Object)17; /* 1 */
    if (v286 == v364) goto v236;
    v286 = stack[-1];
    v364 = stack[-2];
    v364 = qcar(v364);
    fn = elt(env, 6); /* multd */
    v286 = (*qfn2(fn))(qenv(fn), v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-2];
    v364 = qcdr(v364);
    v364 = cons(v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-2] = v364;
    goto v236;

v236:
    v364 = stack[-3];
    if (!consp(v364)) goto v150;
    v364 = stack[-3];
    v364 = qcar(v364);
    if (!consp(v364)) goto v150;
    v364 = stack[-3];
    fn = elt(env, 9); /* minusf */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    if (v364 == nil) goto v188;
    v364 = stack[-3];
    fn = elt(env, 10); /* negf */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-3] = v364;
    v364 = stack[-2];
    v364 = qcar(v364);
    fn = elt(env, 10); /* negf */
    v286 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-2];
    v364 = qcdr(v364);
    v364 = cons(v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-2] = v364;
    goto v188;

v188:
    v364 = stack[-3];
    fn = elt(env, 11); /* factor!-prim!-f */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-1] = v364;
    v364 = stack[-1];
    v286 = qcar(v364);
    v364 = stack[-2];
    v364 = qcar(v364);
    fn = elt(env, 12); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-1];
    v286 = qcdr(v364);
    v364 = stack[-2];
    v364 = qcdr(v364);
    v364 = Lappend(nil, v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    {
        Lisp_Object v367 = stack[0];
        popv(6);
        return cons(v367, v364);
    }

v150:
    v286 = stack[-3];
    v364 = stack[-2];
    v364 = qcar(v364);
    fn = elt(env, 12); /* multf */
    v286 = (*qfn2(fn))(qenv(fn), v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v364 = stack[-2];
    v364 = qcdr(v364);
    popv(6);
    return cons(v286, v364);

v309:
    v364 = stack[-4];
    v364 = qcdr(v364);
    goto v206;

v352:
    v364 = qvalue(elt(env, 1)); /* dmode!* */
    if (v364 == nil) goto v212;
    v286 = qvalue(elt(env, 1)); /* dmode!* */
    v364 = elt(env, 3); /* unitsfn */
    v364 = get(v286, v364);
    env = stack[-5];
    stack[-2] = v364;
    if (v364 == nil) goto v212;
    stack[-1] = stack[-2];
    v286 = (Lisp_Object)17; /* 1 */
    v364 = stack[-3];
    stack[0] = cons(v286, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-3];
    fn = elt(env, 4); /* lnc */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = Lapply2(nil, 3, stack[-1], stack[0], v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-4] = v364;
    v364 = stack[-4];
    v364 = qcdr(v364);
    stack[-3] = v364;
    v364 = stack[-4];
    v364 = qcar(v364);
    fn = elt(env, 5); /* !:recip */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-1] = v364;
    goto v212;

v142:
    v364 = stack[-3];
    popv(6);
    return ncons(v364);
/* error exit handlers */
v365:
    popv(6);
    return nil;
}



/* Code for aex_boundids */

static Lisp_Object CC_aex_boundids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_boundids");
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
    v204 = stack[0];
    fn = elt(env, 1); /* aex_ids */
    stack[-1] = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v204 = stack[0];
    fn = elt(env, 2); /* aex_ctx */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    fn = elt(env, 3); /* ctx_idl */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    {
        Lisp_Object v175 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* intersection */
        return (*qfn2(fn))(qenv(fn), v175, v204);
    }
/* error exit handlers */
v261:
    popv(3);
    return nil;
}



/* Code for cnrd */

static Lisp_Object MS_CDECL CC_cnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v379, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cnrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    v379 = qvalue(elt(env, 2)); /* atts */
    v233 = elt(env, 3); /* type */
    fn = elt(env, 16); /* find */
    v233 = (*qfn2(fn))(qenv(fn), v379, v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v233 = Lintern(nil, v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-1] = v233;
    v379 = qvalue(elt(env, 2)); /* atts */
    v233 = elt(env, 4); /* base */
    fn = elt(env, 16); /* find */
    v233 = (*qfn2(fn))(qenv(fn), v379, v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[0] = v233;
    fn = elt(env, 17); /* lex */
    v233 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v233 = qvalue(elt(env, 5)); /* char */
    stack[-4] = v233;
    fn = elt(env, 17); /* lex */
    v233 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v379 = stack[-1];
    v233 = elt(env, 6); /* constant */
    if (v379 == v233) goto v201;
    v233 = stack[-1];
    if (v233 == nil) goto v344;
    v379 = stack[-1];
    v233 = elt(env, 7); /* (real integer) */
    v233 = Lmember(nil, v379, v233);
    if (v233 == nil) goto v90;
    v233 = stack[0];
    if (v233 == nil) goto v180;
    stack[-3] = elt(env, 8); /* based_integer */
    stack[-2] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = stack[0];
    stack[0] = elt(env, 9); /* string */
    v233 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v379 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v233 = qvalue(elt(env, 1)); /* nil */
    v379 = list2star(stack[0], v379, v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v233 = qvalue(elt(env, 1)); /* nil */
    v233 = list2star(stack[-1], v379, v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v160 = stack[-3];
        Lisp_Object v202 = stack[-2];
        popv(6);
        return list2star(v160, v202, v233);
    }

v180:
    v233 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v233);
    }

v90:
    v233 = stack[-1];
    v379 = Lintern(nil, v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v233 = elt(env, 10); /* (rational complex!-cartesian complex!-polar) 
*/
    v233 = Lmember(nil, v379, v233);
    if (v233 == nil) goto v89;
    fn = elt(env, 19); /* seprd */
    v233 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-2] = v233;
    v379 = stack[-1];
    v233 = elt(env, 11); /* rational */
    if (v379 == v233) goto v341;
    v379 = stack[-1];
    v233 = elt(env, 12); /* complex!-cartesian */
    if (v379 == v233) goto v380;
    v379 = stack[-1];
    v233 = elt(env, 14); /* complex!-polar */
    if (!(v379 == v233)) goto v89;
    fn = elt(env, 17); /* lex */
    v233 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-1] = elt(env, 15); /* complex_polar */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v233 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v185 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v379 = stack[-2];
    v233 = qvalue(elt(env, 1)); /* nil */
    v233 = list2star(v185, v379, v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v350 = stack[-1];
        Lisp_Object v381 = stack[0];
        popv(6);
        return list2star(v350, v381, v233);
    }

v89:
    v233 = nil;
    { popv(6); return onevalue(v233); }

v380:
    fn = elt(env, 17); /* lex */
    v233 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-1] = elt(env, 13); /* complex_cartesian */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v233 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v185 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v379 = stack[-2];
    v233 = qvalue(elt(env, 1)); /* nil */
    v233 = list2star(v185, v379, v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v382 = stack[-1];
        Lisp_Object v299 = stack[0];
        popv(6);
        return list2star(v382, v299, v233);
    }

v341:
    fn = elt(env, 17); /* lex */
    v233 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v233 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v379 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v233 = stack[-2];
    {
        popv(6);
        fn = elt(env, 11); /* rational */
        return (*qfn2(fn))(qenv(fn), v379, v233);
    }

v344:
    v233 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v233);
    }

v201:
    v233 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v233);
    }
/* error exit handlers */
v170:
    popv(6);
    return nil;
}



/* Code for gcd2 */

static Lisp_Object CC_gcd2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v263, v262, v213;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd2");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v210;
    v262 = v0;
/* end of prologue */

v142:
    v263 = stack[0];
    v263 = Cremainder(v262, v263);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-1];
    v213 = v263;
    v262 = v213;
    v263 = (Lisp_Object)1; /* 0 */
    if (v262 == v263) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v262 = stack[0];
    v263 = v213;
    stack[0] = v263;
    goto v142;
/* error exit handlers */
v260:
    popv(2);
    return nil;
}



/* Code for intrdsortin */

static Lisp_Object CC_intrdsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v333;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intrdsortin");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v210;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v172;

v172:
    v182 = stack[0];
    if (v182 == nil) goto v204;
    v182 = stack[-1];
    v333 = qcar(v182);
    v182 = stack[0];
    v182 = qcar(v182);
    v182 = qcar(v182);
    fn = elt(env, 1); /* !:difference */
    v182 = (*qfn2(fn))(qenv(fn), v333, v182);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    fn = elt(env, 2); /* !:minusp */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    if (v182 == nil) goto v95;
    v182 = stack[0];
    v333 = qcar(v182);
    v182 = stack[-2];
    v182 = cons(v333, v182);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    stack[-2] = v182;
    v182 = stack[0];
    v182 = qcdr(v182);
    stack[0] = v182;
    goto v172;

v95:
    v333 = stack[-1];
    v182 = stack[0];
    v182 = cons(v333, v182);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    {
        Lisp_Object v243 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v243, v182);
    }

v204:
    stack[0] = stack[-2];
    v182 = stack[-1];
    v182 = ncons(v182);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    {
        Lisp_Object v244 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v244, v182);
    }
/* error exit handlers */
v93:
    popv(4);
    return nil;
}



/* Code for smemberl */

static Lisp_Object CC_smemberl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemberl");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v210;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v172;

v172:
    v97 = stack[-1];
    if (v97 == nil) goto v218;
    v97 = stack[0];
    if (v97 == nil) goto v218;
    v97 = stack[-1];
    v98 = qcar(v97);
    v97 = stack[0];
    fn = elt(env, 1); /* smember */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    if (v97 == nil) goto v214;
    v97 = stack[-1];
    v98 = qcar(v97);
    v97 = stack[-2];
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    stack[-2] = v97;
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-1] = v97;
    goto v172;

v214:
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-1] = v97;
    goto v172;

v218:
    v97 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v97);
    }
/* error exit handlers */
v246:
    popv(4);
    return nil;
}



/* Code for dummyp */

static Lisp_Object CC_dummyp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v206, v383;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dummyp");
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
    stack[-3] = v0;
/* end of prologue */
    v148 = (Lisp_Object)1; /* 0 */
    stack[-2] = v148;
    v148 = stack[-3];
    if (symbolp(v148)) goto v131;
    v148 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v148); }

v131:
    v148 = (Lisp_Object)17; /* 1 */
    stack[-4] = v148;
    goto v111;

v111:
    stack[0] = stack[-4];
    v148 = qvalue(elt(env, 2)); /* g_dvnames */
    fn = elt(env, 4); /* upbve */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    v148 = (Lisp_Object)lesseq2(stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v257;
    v148 = v148 ? lisp_true : nil;
    env = stack[-5];
    if (v148 == nil) goto v176;
    stack[-1] = stack[-3];
    stack[0] = qvalue(elt(env, 2)); /* g_dvnames */
    v148 = stack[-4];
    v148 = sub1(v148);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    v148 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v148/(16/CELL)));
    if (equal(stack[-1], v148)) goto v254;
    v148 = stack[-4];
    v148 = add1(v148);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[-4] = v148;
    goto v111;

v254:
    v148 = stack[-4];
    stack[-2] = v148;
    v148 = qvalue(elt(env, 2)); /* g_dvnames */
    fn = elt(env, 4); /* upbve */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    v148 = add1(v148);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[-4] = v148;
    goto v111;

v176:
    v206 = stack[-2];
    v148 = (Lisp_Object)1; /* 0 */
    if (!(v206 == v148)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v148 = stack[-3];
    fn = elt(env, 5); /* ad_splitname */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    v206 = v148;
    v148 = v206;
    v148 = qcar(v148);
    v383 = qvalue(elt(env, 3)); /* g_dvbase */
    if (v148 == v383) goto v384;
    v148 = nil;
    { popv(6); return onevalue(v148); }

v384:
    v148 = v206;
    v148 = qcdr(v148);
    { popv(6); return onevalue(v148); }
/* error exit handlers */
v257:
    popv(6);
    return nil;
}



/* Code for reverse!-num1 */

static Lisp_Object CC_reverseKnum1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v359, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reverse-num1");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v210;
    stack[0] = v0;
/* end of prologue */
    v78 = stack[0];
    v359 = (Lisp_Object)1; /* 0 */
    if (v78 == v359) goto v5;
    v78 = stack[-2];
    v359 = (Lisp_Object)17; /* 1 */
    if (v78 == v359) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v78 = stack[-2];
    v359 = (Lisp_Object)33; /* 2 */
    if (v78 == v359) goto v334;
    v78 = stack[-2];
    v359 = (Lisp_Object)49; /* 3 */
    if (v78 == v359) goto v187;
    v78 = stack[-2];
    v359 = (Lisp_Object)65; /* 4 */
    if (v78 == v359) goto v391;
    stack[-1] = (Lisp_Object)33; /* 2 */
    v78 = stack[-2];
    v359 = (Lisp_Object)33; /* 2 */
    v359 = quot2(v78, v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v359 = Lexpt(nil, stack[-1], v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    stack[-3] = v359;
    v78 = stack[0];
    v359 = stack[-3];
    v359 = Ldivide(nil, v78, v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    stack[-1] = v359;
    v359 = stack[-2];
    v359 = Levenp(nil, v359);
    env = stack[-4];
    if (!(v359 == nil)) goto v209;
    v78 = stack[-3];
    v359 = (Lisp_Object)33; /* 2 */
    v359 = times2(v78, v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    stack[-3] = v359;
    goto v209;

v209:
    v359 = stack[-1];
    stack[0] = qcdr(v359);
    v78 = stack[-2];
    v359 = (Lisp_Object)33; /* 2 */
    v359 = quot2(v78, v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v78 = CC_reverseKnum1(env, stack[0], v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v359 = stack[-3];
    stack[0] = times2(v78, v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v359 = stack[-1];
    stack[-1] = qcar(v359);
    v359 = stack[-2];
    v78 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v359 = (Lisp_Object)33; /* 2 */
    v359 = quot2(v78, v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v359 = CC_reverseKnum1(env, stack[-1], v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    {
        Lisp_Object v230 = stack[0];
        popv(5);
        return plus2(v230, v359);
    }

v391:
    v78 = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v359 = stack[0];
    v359 = *(Lisp_Object *)((char *)v78 + (CELL-TAG_VECTOR) + ((int32_t)v359/(16/CELL)));
    { popv(5); return onevalue(v359); }

v187:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v78 = (Lisp_Object)33; /* 2 */
    v359 = stack[0];
    v359 = times2(v78, v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v359 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v359/(16/CELL)));
    { popv(5); return onevalue(v359); }

v334:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v78 = (Lisp_Object)65; /* 4 */
    v359 = stack[0];
    v359 = times2(v78, v359);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v359 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v359/(16/CELL)));
    { popv(5); return onevalue(v359); }

v5:
    v359 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v359); }
/* error exit handlers */
v149:
    popv(5);
    return nil;
}



/* Code for sgn1 */

static Lisp_Object CC_sgn1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v341, v353;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sgn1");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v353 = v210;
    stack[-4] = v0;
/* end of prologue */
    v341 = stack[-4];
    if (!consp(v341)) goto v204;
    v341 = v353;
    v341 = qcar(v341);
    stack[-2] = v341;
    v341 = v353;
    v341 = qcdr(v341);
    stack[-1] = v341;
    v341 = (Lisp_Object)1; /* 0 */
    stack[-3] = v341;
    v341 = (Lisp_Object)17; /* 1 */
    stack[-5] = v341;
    v341 = stack[-4];
    v341 = qcdr(v341);
    stack[-4] = v341;
    goto v96;

v96:
    v353 = stack[-5];
    v341 = stack[-4];
    v341 = qcar(v341);
    stack[0] = times2(v353, v341);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    v353 = stack[-2];
    v341 = stack[-3];
    v341 = times2(v353, v341);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    v341 = plus2(stack[0], v341);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    stack[-3] = v341;
    v353 = stack[-5];
    v341 = stack[-1];
    v341 = times2(v353, v341);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    stack[-5] = v341;
    v341 = stack[-4];
    v341 = qcdr(v341);
    stack[-4] = v341;
    if (!(v341 == nil)) goto v96;
    v353 = stack[-3];
    v341 = (Lisp_Object)1; /* 0 */
    v341 = (Lisp_Object)greaterp2(v353, v341);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v341 = v341 ? lisp_true : nil;
    env = stack[-6];
    if (v341 == nil) goto v88;
    v341 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v341); }

v88:
    v353 = stack[-3];
    v341 = (Lisp_Object)1; /* 0 */
    v341 = (Lisp_Object)lessp2(v353, v341);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v341 = v341 ? lisp_true : nil;
    if (v341 == nil) goto v238;
    v341 = (Lisp_Object)-15; /* -1 */
    { popv(7); return onevalue(v341); }

v238:
    v341 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v341); }

v204:
    v353 = stack[-4];
    v341 = (Lisp_Object)1; /* 0 */
    v341 = (Lisp_Object)greaterp2(v353, v341);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v341 = v341 ? lisp_true : nil;
    env = stack[-6];
    if (v341 == nil) goto v111;
    v341 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v341); }

v111:
    v353 = stack[-4];
    v341 = (Lisp_Object)1; /* 0 */
    v341 = (Lisp_Object)lessp2(v353, v341);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v341 = v341 ? lisp_true : nil;
    if (v341 == nil) goto v100;
    v341 = (Lisp_Object)-15; /* -1 */
    { popv(7); return onevalue(v341); }

v100:
    v341 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v341); }
/* error exit handlers */
v195:
    popv(7);
    return nil;
}



/* Code for horner!-rule!-for!-one!-var */

static Lisp_Object MS_CDECL CC_hornerKruleKforKoneKvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v210,
                         Lisp_Object v29, Lisp_Object v9,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v143, v337, v305, v236, v306, v229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-for-one-var");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-for-one-var");
#endif
    if (stack >= stacklimit)
    {
        push5(v6,v9,v29,v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v210,v29,v9,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v143 = v6;
    v337 = v9;
    v305 = v29;
    v236 = v210;
    v306 = v0;
/* end of prologue */

v322:
    v145 = v306;
    if (!consp(v145)) goto v110;
    v145 = v306;
    v145 = qcar(v145);
    if (!consp(v145)) goto v110;
    v145 = v306;
    v145 = qcar(v145);
    v145 = qcar(v145);
    v229 = qcar(v145);
    v145 = v236;
    if (!(equal(v229, v145))) goto v110;
    v145 = v306;
    v145 = qcar(v145);
    v145 = qcar(v145);
    v145 = qcdr(v145);
    stack[-5] = v145;
    v145 = v306;
    stack[-4] = qcdr(v145);
    stack[-3] = v236;
    stack[-2] = v305;
    v145 = v305;
    v145 = (Lisp_Object)zerop(v145);
    v145 = v145 ? lisp_true : nil;
    env = stack[-6];
    if (v145 == nil) goto v90;
    v145 = v306;
    v145 = qcar(v145);
    v145 = qcdr(v145);
    v143 = v145;
    goto v92;

v92:
    v145 = stack[-5];
    v306 = stack[-4];
    v236 = stack[-3];
    v305 = stack[-2];
    v337 = v143;
    v143 = v145;
    goto v322;

v90:
    v145 = v306;
    v145 = qcar(v145);
    stack[-1] = qcdr(v145);
    stack[0] = v337;
    v337 = v305;
    v145 = stack[-5];
    v145 = (Lisp_Object)(int32_t)((int32_t)v143 - (int32_t)v145 + TAG_FIXNUM);
    v145 = Lexpt(nil, v337, v145);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-6];
    v143 = v145;
    v145 = v143;
    v145 = (Lisp_Object)zerop(v145);
    v145 = v145 ? lisp_true : nil;
    env = stack[-6];
    if (v145 == nil) goto v82;
    v145 = qvalue(elt(env, 1)); /* nil */
    goto v341;

v341:
    fn = elt(env, 2); /* multf */
    v145 = (*qfn2(fn))(qenv(fn), stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-6];
    fn = elt(env, 3); /* addf */
    v145 = (*qfn2(fn))(qenv(fn), stack[-1], v145);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-6];
    v143 = v145;
    goto v92;

v82:
    v145 = v143;
    goto v341;

v110:
    v145 = v305;
    v145 = (Lisp_Object)zerop(v145);
    v145 = v145 ? lisp_true : nil;
    env = stack[-6];
    if (!(v145 == nil)) { popv(7); return onevalue(v306); }
    stack[-1] = v306;
    stack[0] = v337;
    v145 = v305;
    v145 = Lexpt(nil, v145, v143);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-6];
    v143 = v145;
    v145 = v143;
    v145 = (Lisp_Object)zerop(v145);
    v145 = v145 ? lisp_true : nil;
    env = stack[-6];
    if (v145 == nil) goto v177;
    v145 = qvalue(elt(env, 1)); /* nil */
    goto v97;

v97:
    fn = elt(env, 2); /* multf */
    v145 = (*qfn2(fn))(qenv(fn), stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-6];
    {
        Lisp_Object v304 = stack[-1];
        popv(7);
        fn = elt(env, 3); /* addf */
        return (*qfn2(fn))(qenv(fn), v304, v145);
    }

v177:
    v145 = v143;
    goto v97;
/* error exit handlers */
v386:
    popv(7);
    return nil;
}



/* Code for cl_identifyonoff */

static Lisp_Object CC_cl_identifyonoff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyonoff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v9 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v9; /* cl_identify!-atl!* */
    return onevalue(v9);
}



/* Code for multdfconst */

static Lisp_Object CC_multdfconst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v210)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdfconst");
#endif
    if (stack >= stacklimit)
    {
        push2(v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v210);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v210;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v172;

v172:
    v219 = stack[-1];
    if (v219 == nil) goto v142;
    v219 = stack[-2];
    v219 = qcar(v219);
    if (v219 == nil) goto v142;
    v219 = stack[-1];
    v219 = qcar(v219);
    stack[0] = qcar(v219);
    v220 = stack[-2];
    v219 = stack[-1];
    v219 = qcar(v219);
    v219 = qcdr(v219);
    fn = elt(env, 1); /* multsq */
    v219 = (*qfn2(fn))(qenv(fn), v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    fn = elt(env, 2); /* subs2q */
    v220 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v219 = stack[-3];
    v219 = acons(stack[0], v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    stack[-3] = v219;
    v219 = stack[-1];
    v219 = qcdr(v219);
    stack[-1] = v219;
    goto v172;

v142:
    v219 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v219);
    }
/* error exit handlers */
v245:
    popv(5);
    return nil;
}



/* Code for expnd */

static Lisp_Object CC_expnd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v262, v213, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expnd");
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
    v262 = qvalue(elt(env, 1)); /* !*really_off_exp */
    if (!(v262 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v262 = stack[0];
    fn = elt(env, 3); /* expnd1 */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-2];
    stack[0] = v262;
    v262 = qvalue(elt(env, 2)); /* !*sub2 */
    if (v262 == nil) goto v334;
    v262 = stack[0];
    fn = elt(env, 4); /* subs2f */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-2];
    v214 = v262;
    v213 = qcdr(v262);
    v262 = (Lisp_Object)17; /* 1 */
    if (!(v213 == v262)) goto v334;
    v262 = v214;
    v262 = qcar(v262);
    goto v204;

v204:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    { popv(3); return onevalue(v262); }

v334:
    v262 = stack[0];
    goto v204;
/* error exit handlers */
v217:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    popv(3);
    return nil;
}



/* Code for cl_susiupdknowl2 */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v210,
                         Lisp_Object v29, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v395, v234, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_susiupdknowl2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl2");
#endif
    if (stack >= stacklimit)
    {
        push3(v29,v210,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v210,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v29;
    stack[-5] = v210;
    stack[-6] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v303 = stack[-5];
    stack[-2] = v303;
    v303 = qvalue(elt(env, 1)); /* nil */
    v77 = v303;
    v303 = stack[-5];
    v234 = v303;
    goto v211;

v211:
    v303 = v234;
    if (v303 == nil) goto v175;
    v303 = v234;
    v303 = qcar(v303);
    v395 = stack[-6];
    if (!(equal(v395, v303))) goto v347;
    v303 = lisp_true;
    v77 = v303;
    goto v347;

v347:
    v303 = v234;
    v303 = qcdr(v303);
    v234 = v303;
    goto v211;

v175:
    v303 = v77;
    if (!(v303 == nil)) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }

v245:
    v303 = stack[-2];
    if (v303 == nil) goto v389;
    v303 = stack[-2];
    v303 = qcar(v303);
    stack[-7] = v303;
    v303 = stack[-2];
    v303 = qcdr(v303);
    stack[-2] = v303;
    v395 = stack[-7];
    v303 = stack[-6];
    fn = elt(env, 4); /* rl_susibin */
    v303 = (*qfn2(fn))(qenv(fn), v395, v303);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-8];
    stack[-3] = v303;
    v395 = stack[-3];
    v303 = elt(env, 2); /* false */
    if (v395 == v303) goto v93;
    v234 = stack[-3];
    v395 = stack[-5];
    v303 = stack[-7];
    fn = elt(env, 5); /* cl_susiinter */
    v303 = (*qfnn(fn))(qenv(fn), 3, v234, v395, v303);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-8];
    stack[-3] = v303;
    v395 = stack[0];
    v303 = stack[-3];
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v303 = Lnconc(nil, v395, v303);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-8];
    stack[0] = v303;
    v303 = stack[-3];
    v303 = qcar(v303);
    stack[-5] = v303;
    v303 = stack[-3];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    if (!(v303 == nil)) goto v207;

v207:
    v303 = stack[-3];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    if (v303 == nil) goto v245;
    v303 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v303;
    v303 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v303;
    goto v245;

v93:
    v303 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v303;
    goto v245;

v389:
    v395 = stack[-3];
    v303 = elt(env, 2); /* false */
    if (v395 == v303) goto v85;
    v303 = stack[-1];
    if (!(v303 == nil)) goto v229;
    v395 = stack[-6];
    v303 = stack[-5];
    v303 = cons(v395, v303);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-8];
    stack[-5] = v303;
    goto v229;

v229:
    v303 = stack[0];
    if (v303 == nil) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v303 = stack[0];
    v234 = qcar(v303);
    v395 = stack[-5];
    v303 = stack[-4];
    v303 = CC_cl_susiupdknowl2(env, 3, v234, v395, v303);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-8];
    stack[-5] = v303;
    v395 = stack[-5];
    v303 = elt(env, 2); /* false */
    if (v395 == v303) goto v144;
    v303 = stack[0];
    v303 = qcdr(v303);
    stack[0] = v303;
    goto v229;

v144:
    v303 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v303;
    goto v229;

v85:
    v303 = elt(env, 2); /* false */
    { popv(9); return onevalue(v303); }
/* error exit handlers */
v379:
    popv(9);
    return nil;
}



/* Code for expvec2a */

static Lisp_Object CC_expvec2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expvec2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v131 = v0;
/* end of prologue */
    v140 = v131;
    v131 = qvalue(elt(env, 1)); /* dipvars!* */
    {
        fn = elt(env, 2); /* expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v140, v131);
    }
}



setup_type const u24_setup[] =
{
    {"matsm1",                  CC_matsm1,      too_many_1,    wrong_no_1},
    {"unify",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_unify},
    {"vdpvevlcomp",             too_few_2,      CC_vdpvevlcomp,wrong_no_2},
    {"mkfortterpri",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkfortterpri},
    {"indordn",                 CC_indordn,     too_many_1,    wrong_no_1},
    {"fieldconv",               too_few_2,      CC_fieldconv,  wrong_no_2},
    {"groeb=newpair",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMnewpair},
    {"simp-prop1",              too_few_2,      CC_simpKprop1, wrong_no_2},
    {"ad_splitname",            CC_ad_splitname,too_many_1,    wrong_no_1},
    {"bfrsq",                   CC_bfrsq,       too_many_1,    wrong_no_1},
    {"gen+can+bas",             CC_genLcanLbas, too_many_1,    wrong_no_1},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"qqe_simplterm-tail",      CC_qqe_simpltermKtail,too_many_1,wrong_no_1},
    {"fctrf1",                  CC_fctrf1,      too_many_1,    wrong_no_1},
    {"aex_boundids",            CC_aex_boundids,too_many_1,    wrong_no_1},
    {"cnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnrd},
    {"gcd2",                    too_few_2,      CC_gcd2,       wrong_no_2},
    {"intrdsortin",             too_few_2,      CC_intrdsortin,wrong_no_2},
    {"smemberl",                too_few_2,      CC_smemberl,   wrong_no_2},
    {"dummyp",                  CC_dummyp,      too_many_1,    wrong_no_1},
    {"reverse-num1",            too_few_2,      CC_reverseKnum1,wrong_no_2},
    {"sgn1",                    too_few_2,      CC_sgn1,       wrong_no_2},
    {"horner-rule-for-one-var", wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"cl_identifyonoff",        CC_cl_identifyonoff,too_many_1,wrong_no_1},
    {"multdfconst",             too_few_2,      CC_multdfconst,wrong_no_2},
    {"expnd",                   CC_expnd,       too_many_1,    wrong_no_1},
    {"cl_susiupdknowl2",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl2},
    {"expvec2a",                CC_expvec2a,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u24", (two_args *)"10692 6424872 1409422", 0}
};

/* end of generated code */
