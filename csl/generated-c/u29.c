
/* $destdir\u29.c        Machine generated C code */

/* Signature: 00000000 07-Oct-2010 */

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


/* Code for red!=hide */

static Lisp_Object CC_redMhide(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hide");
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
    v16 = v0;
/* end of prologue */
    stack[-5] = v16;
    v16 = stack[-5];
    if (v16 == nil) goto v18;
    v16 = stack[-5];
    v16 = qcar(v16);
    stack[-1] = v16;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v16 = stack[-1];
    v16 = qcar(v16);
    fn = elt(env, 2); /* mo_neg */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v17 = (*qfn2(fn))(qenv(fn), stack[0], v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v16 = stack[-1];
    v16 = qcdr(v16);
    v16 = cons(v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v16 = ncons(v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    stack[-3] = v16;
    stack[-4] = v16;
    goto v20;

v20:
    v16 = stack[-5];
    v16 = qcdr(v16);
    stack[-5] = v16;
    v16 = stack[-5];
    if (v16 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v16 = stack[-5];
    v16 = qcar(v16);
    stack[-1] = v16;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v16 = stack[-1];
    v16 = qcar(v16);
    fn = elt(env, 2); /* mo_neg */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v17 = (*qfn2(fn))(qenv(fn), stack[0], v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v16 = stack[-1];
    v16 = qcdr(v16);
    v16 = cons(v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v16 = ncons(v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v16 = Lrplacd(nil, stack[-2], v16);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-6];
    v16 = stack[-3];
    v16 = qcdr(v16);
    stack[-3] = v16;
    goto v20;

v18:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v16); }
/* error exit handlers */
v19:
    popv(7);
    return nil;
}



/* Code for clean_numid */

static Lisp_Object CC_clean_numid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clean_numid");
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
    goto v25;

v25:
    v23 = stack[0];
    if (v23 == nil) goto v26;
    v23 = stack[0];
    v23 = qcar(v23);
    fn = elt(env, 1); /* !*id2num */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    if (v23 == nil) goto v28;
    v23 = stack[0];
    v23 = qcdr(v23);
    stack[0] = v23;
    goto v25;

v28:
    v23 = stack[0];
    v24 = qcar(v23);
    v23 = stack[-1];
    v23 = cons(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    stack[-1] = v23;
    v23 = stack[0];
    v23 = qcdr(v23);
    stack[0] = v23;
    goto v25;

v26:
    v23 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v23);
    }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for orddf */

static Lisp_Object CC_orddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for orddf");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */

v25:
    v32 = stack[-1];
    if (v32 == nil) goto v26;
    v32 = stack[0];
    if (v32 == nil) goto v34;
    v32 = stack[-1];
    v33 = qcar(v32);
    v32 = stack[0];
    v32 = qcar(v32);
    fn = elt(env, 6); /* exptcompare */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    if (v32 == nil) goto v36;
    v32 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v32); }

v36:
    v32 = stack[0];
    v33 = qcar(v32);
    v32 = stack[-1];
    v32 = qcar(v32);
    fn = elt(env, 6); /* exptcompare */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    if (v32 == nil) goto v37;
    v32 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v32); }

v37:
    v32 = stack[-1];
    v32 = qcdr(v32);
    stack[-1] = v32;
    v32 = stack[0];
    v32 = qcdr(v32);
    stack[0] = v32;
    goto v25;

v34:
    v32 = elt(env, 3); /* "Orddf u longer than v" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v32);
    }

v26:
    v32 = stack[0];
    if (v32 == nil) goto v38;
    v32 = elt(env, 2); /* "Orddf v longer than u" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v32);
    }

v38:
    v32 = elt(env, 1); /* "Orddf = case" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v35:
    popv(3);
    return nil;
}



/* Code for mk!+mat!+plus!+mat */

static Lisp_Object CC_mkLmatLplusLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+plus+mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v29;
    stack[-11] = v0;
/* end of prologue */
    v104 = stack[-11];
    fn = elt(env, 7); /* matrix!+p */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    if (!(v104 == nil)) goto v108;
    v104 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v104 == nil)) goto v109;
    v104 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 8); /* lprie */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    goto v109;

v109:
    v104 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    goto v108;

v108:
    v104 = stack[-10];
    fn = elt(env, 7); /* matrix!+p */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    if (!(v104 == nil)) goto v110;
    v104 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v104 == nil)) goto v12;
    v104 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 8); /* lprie */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    goto v12;

v12:
    v104 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    goto v110;

v110:
    v104 = stack[-11];
    fn = elt(env, 9); /* get!+col!+nr */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    stack[-12] = v104;
    v104 = stack[-11];
    fn = elt(env, 10); /* get!+row!+nr */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    stack[-9] = v104;
    stack[0] = stack[-12];
    v104 = stack[-10];
    fn = elt(env, 9); /* get!+col!+nr */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    if (equal(stack[0], v104)) goto v4;
    v104 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v104 == nil)) goto v3;
    v104 = elt(env, 3); /* "wrong dimensions in add" */
    fn = elt(env, 8); /* lprie */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    goto v3;

v3:
    v104 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    goto v4;

v4:
    stack[0] = stack[-9];
    v104 = stack[-10];
    fn = elt(env, 10); /* get!+row!+nr */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    if (equal(stack[0], v104)) goto v111;
    v104 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v104 == nil)) goto v19;
    v104 = elt(env, 3); /* "wrong dimensions in add" */
    fn = elt(env, 8); /* lprie */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    goto v19;

v19:
    v104 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    goto v111;

v111:
    v104 = (Lisp_Object)17; /* 1 */
    stack[-8] = v104;
    v105 = stack[-9];
    v104 = stack[-8];
    v104 = difference2(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lminusp(nil, v104);
    env = stack[-13];
    if (v104 == nil) goto v112;
    v104 = qvalue(elt(env, 4)); /* nil */
    { popv(14); return onevalue(v104); }

v112:
    v104 = (Lisp_Object)17; /* 1 */
    stack[-4] = v104;
    v105 = stack[-12];
    v104 = stack[-4];
    v104 = difference2(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lminusp(nil, v104);
    env = stack[-13];
    if (v104 == nil) goto v113;
    v104 = qvalue(elt(env, 4)); /* nil */
    goto v114;

v114:
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    stack[-6] = v104;
    stack[-7] = v104;
    goto v115;

v115:
    v104 = stack[-8];
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    stack[-8] = v104;
    v105 = stack[-9];
    v104 = stack[-8];
    v104 = difference2(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lminusp(nil, v104);
    env = stack[-13];
    if (!(v104 == nil)) { Lisp_Object res = stack[-7]; popv(14); return onevalue(res); }
    stack[-5] = stack[-6];
    v104 = (Lisp_Object)17; /* 1 */
    stack[-4] = v104;
    v105 = stack[-12];
    v104 = stack[-4];
    v104 = difference2(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lminusp(nil, v104);
    env = stack[-13];
    if (v104 == nil) goto v116;
    v104 = qvalue(elt(env, 4)); /* nil */
    goto v117;

v117:
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lrplacd(nil, stack[-5], v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = stack[-6];
    v104 = qcdr(v104);
    stack[-6] = v104;
    goto v115;

v116:
    v106 = stack[-11];
    v105 = stack[-8];
    v104 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v106, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v106 = stack[-10];
    v105 = stack[-8];
    v104 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v104 = (*qfnn(fn))(qenv(fn), 3, v106, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v105 = v104;
    v104 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v104; /* !*sub2 */
    v104 = v105;
    fn = elt(env, 13); /* subs2 */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-13];
    v105 = v104;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v104 = v105;
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    stack[-2] = v104;
    stack[-3] = v104;
    goto v119;

v119:
    v104 = stack[-4];
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    stack[-4] = v104;
    v105 = stack[-12];
    v104 = stack[-4];
    v104 = difference2(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lminusp(nil, v104);
    env = stack[-13];
    if (v104 == nil) goto v120;
    v104 = stack[-3];
    goto v117;

v120:
    stack[-1] = stack[-2];
    v106 = stack[-11];
    v105 = stack[-8];
    v104 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v106, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v106 = stack[-10];
    v105 = stack[-8];
    v104 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v104 = (*qfnn(fn))(qenv(fn), 3, v106, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v105 = v104;
    v104 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v104; /* !*sub2 */
    v104 = v105;
    fn = elt(env, 13); /* subs2 */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-13];
    v105 = v104;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v104 = v105;
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lrplacd(nil, stack[-1], v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = stack[-2];
    v104 = qcdr(v104);
    stack[-2] = v104;
    goto v119;

v113:
    v106 = stack[-11];
    v105 = stack[-8];
    v104 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v106, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v106 = stack[-10];
    v105 = stack[-8];
    v104 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v104 = (*qfnn(fn))(qenv(fn), 3, v106, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v105 = v104;
    v104 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v104; /* !*sub2 */
    v104 = v105;
    fn = elt(env, 13); /* subs2 */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-13];
    v105 = v104;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v104 = v105;
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    stack[-2] = v104;
    stack[-3] = v104;
    goto v123;

v123:
    v104 = stack[-4];
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    stack[-4] = v104;
    v105 = stack[-12];
    v104 = stack[-4];
    v104 = difference2(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lminusp(nil, v104);
    env = stack[-13];
    if (v104 == nil) goto v124;
    v104 = stack[-3];
    goto v114;

v124:
    stack[-1] = stack[-2];
    v106 = stack[-11];
    v105 = stack[-8];
    v104 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v106, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v106 = stack[-10];
    v105 = stack[-8];
    v104 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v104 = (*qfnn(fn))(qenv(fn), 3, v106, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v105 = v104;
    v104 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v104; /* !*sub2 */
    v104 = v105;
    fn = elt(env, 13); /* subs2 */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-13];
    v105 = v104;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v104 = v105;
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = Lrplacd(nil, stack[-1], v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-13];
    v104 = stack[-2];
    v104 = qcdr(v104);
    stack[-2] = v104;
    goto v123;
/* error exit handlers */
v125:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v122:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v121:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v118:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v107:
    popv(14);
    return nil;
}



/* Code for semanticml */

static Lisp_Object CC_semanticml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for semanticml");
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
    v19 = stack[0];
    v129 = Llength(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = (Lisp_Object)17; /* 1 */
    v19 = (Lisp_Object)greaterp2(v129, v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    v19 = v19 ? lisp_true : nil;
    env = stack[-1];
    if (v19 == nil) goto v25;
    v19 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 3); /* "<fn>" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    goto v25;

v25:
    v19 = elt(env, 5); /* "<semantic>" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 6); /* "<ci><mo>" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcar(v19);
    v19 = qcar(v19);
    v19 = Lprinc(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 7); /* "</mo></ci>" */
    v19 = Lprinc(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 8); /* "<annotation-xml encoding=""OpenMath"">" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 9); /* "<" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcar(v19);
    v19 = qcdr(v19);
    v19 = qcar(v19);
    fn = elt(env, 17); /* list2string */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 10); /* ">" */
    v19 = Lprinc(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 11); /* "</annotation-xml>" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 12); /* "</semantic>" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = stack[0];
    v129 = Llength(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = (Lisp_Object)17; /* 1 */
    v19 = (Lisp_Object)greaterp2(v129, v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    v19 = v19 ? lisp_true : nil;
    env = stack[-1];
    if (v19 == nil) goto v33;
    v19 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 13); /* "</fn>" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcdr(v19);
    fn = elt(env, 18); /* multi_elem */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v19 = elt(env, 14); /* "</apply>" */
    fn = elt(env, 15); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v130;
    goto v33;

v33:
    v19 = nil;
    { popv(2); return onevalue(v19); }
/* error exit handlers */
v130:
    popv(2);
    return nil;
}



/* Code for alg_plus */

static Lisp_Object CC_alg_plus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v13, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for alg_plus");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v132 = v29;
    v13 = v0;
/* end of prologue */
    v133 = elt(env, 1); /* plus */
    v132 = list3(v133, v13, v132);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* aeval */
        return (*qfn1(fn))(qenv(fn), v132);
    }
/* error exit handlers */
v109:
    popv(1);
    return nil;
}



/* Code for crn!:zerop */

static Lisp_Object CC_crnTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v14, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:zerop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v22 = v15;
    v22 = qcdr(v22);
    v22 = qcar(v22);
    v14 = qcar(v22);
    v22 = (Lisp_Object)1; /* 0 */
    if (v14 == v22) goto v133;
    v22 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v22);

v133:
    v22 = v15;
    v22 = qcdr(v22);
    v22 = qcdr(v22);
    v14 = qcar(v22);
    v22 = (Lisp_Object)1; /* 0 */
    v22 = (v14 == v22 ? lisp_true : nil);
    return onevalue(v22);
}



/* Code for findelem2 */

static Lisp_Object MS_CDECL CC_findelem2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v138, v3, v35;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findelem2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findelem2");
#endif
    if (stack >= stacklimit)
    {
        push3(v8,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v29,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v32 = v8;
    v33 = v29;
    v138 = v0;
/* end of prologue */
    v3 = v138;
    v3 = Lconsp(nil, v3);
    env = stack[0];
    if (v3 == nil) goto v139;
    v3 = v138;
    v3 = qcar(v3);
    v35 = elt(env, 1); /* sparsemat */
    if (!(v3 == v35)) goto v139;
    v138 = qcdr(v138);
    v138 = qcar(v138);
    goto v139;

v139:
    v33 = *(Lisp_Object *)((char *)v138 + (CELL-TAG_VECTOR) + ((int32_t)v33/(16/CELL)));
    v32 = Latsoc(nil, v32, v33);
    v33 = v32;
    v32 = v33;
    if (v32 == nil) goto v140;
    v32 = v33;
    v32 = qcdr(v32);
    { popv(1); return onevalue(v32); }

v140:
    v32 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v32); }
}



/* Code for size_of_matrix */

static Lisp_Object CC_size_of_matrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for size_of_matrix");
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
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v21 = stack[0];
    v21 = Llength(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v21 = plus2(stack[-1], v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    stack[-1] = v21;
    v21 = stack[0];
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v21 = Llength(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    v22 = stack[-1];
    popv(3);
    return list2(v22, v21);
/* error exit handlers */
v23:
    popv(3);
    return nil;
}



/* Code for memqcar */

static Lisp_Object CC_memqcar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v141, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for memqcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v141 = v29;
    v34 = v0;
/* end of prologue */
    v109 = v34;
    if (!consp(v109)) goto v25;
    v109 = v34;
    v109 = qcar(v109);
    v109 = Lmemq(nil, v109, v141);
    return onevalue(v109);

v25:
    v109 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v109);
}



/* Code for r2findindex1 */

static Lisp_Object MS_CDECL CC_r2findindex1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v143, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "r2findindex1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2findindex1");
#endif
    if (stack >= stacklimit)
    {
        push3(v8,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v29,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v143 = v8;
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */

v145:
    v142 = stack[0];
    if (v142 == nil) goto v146;
    v144 = stack[-1];
    v142 = stack[0];
    v142 = qcar(v142);
    if (equal(v144, v142)) { popv(3); return onevalue(v143); }
    v142 = stack[0];
    v142 = qcdr(v142);
    stack[0] = v142;
    v142 = v143;
    v142 = add1(v142);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    v143 = v142;
    goto v145;

v146:
    v142 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v142 == nil)) goto v131;
    v142 = elt(env, 2); /* "index not found" */
    fn = elt(env, 3); /* lprie */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    goto v131;

v131:
    v142 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v142 = nil;
    { popv(3); return onevalue(v142); }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



/* Code for quoteequation */

static Lisp_Object CC_quoteequation(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v10;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quoteequation");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v10 = elt(env, 1); /* equation */
    return onevalue(v10);
}



/* Code for statep */

static Lisp_Object CC_statep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v150, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for statep");
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
    v150 = v0;
/* end of prologue */
    v102 = v150;
    if (symbolp(v102)) goto v133;
    v102 = qvalue(elt(env, 1)); /* nil */
    goto v145;

v145:
    if (!(v102 == nil)) { popv(1); return onevalue(v102); }
    v102 = v150;
    if (!consp(v102)) goto v22;
    v102 = v150;
    v102 = qcar(v102);
    if (symbolp(v102)) goto v151;
    v102 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v102); }

v151:
    v102 = v150;
    v150 = qcar(v102);
    v102 = elt(env, 2); /* phystype */
    v102 = get(v150, v102);
    env = stack[0];
    v150 = elt(env, 3); /* state */
    v102 = (v102 == v150 ? lisp_true : nil);
    { popv(1); return onevalue(v102); }

v22:
    v102 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v102); }

v133:
    v32 = v150;
    v102 = elt(env, 2); /* phystype */
    v32 = get(v32, v102);
    env = stack[0];
    v102 = elt(env, 3); /* state */
    v102 = (v32 == v102 ? lisp_true : nil);
    goto v145;
}



/* Code for color!-roads */

static Lisp_Object CC_colorKroads(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v167, v96;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color-roads");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v29;
    v96 = v0;
/* end of prologue */
    v166 = stack[-4];
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = v96;
    v166 = Lassoc(nil, v167, v166);
    v166 = qcdr(v166);
    stack[-1] = v166;
    v166 = stack[-4];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = v96;
    v166 = Lassoc(nil, v167, v166);
    v166 = qcdr(v166);
    stack[0] = v166;
    v166 = stack[-4];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = v96;
    v166 = Lassoc(nil, v166, v167);
    v166 = qcdr(v166);
    stack[-5] = v166;
    stack[-2] = stack[-1];
    v167 = stack[0];
    v166 = stack[-5];
    v166 = plus2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    v167 = plus2(stack[-2], v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    v166 = (Lisp_Object)33; /* 2 */
    v166 = quot2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    stack[-2] = v166;
    v167 = stack[-2];
    v166 = stack[-1];
    v166 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    stack[-1] = v166;
    v167 = stack[-2];
    v166 = stack[0];
    v166 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    stack[0] = v166;
    v167 = stack[-2];
    v166 = stack[-5];
    v166 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    stack[-5] = v166;
    v166 = stack[-4];
    v166 = qcar(v166);
    stack[-3] = qcar(v166);
    stack[-2] = stack[-1];
    v166 = stack[-4];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    stack[-1] = qcar(v166);
    v166 = stack[-4];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = stack[-5];
    v166 = cons(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    v166 = acons(stack[-1], stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    {
        Lisp_Object v169 = stack[-3];
        Lisp_Object v170 = stack[-2];
        popv(7);
        return acons(v169, v170, v166);
    }
/* error exit handlers */
v168:
    popv(7);
    return nil;
}



/* Code for formbool */

static Lisp_Object MS_CDECL CC_formbool(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v206, v207, v208, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formbool");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formbool");
#endif
    if (stack >= stacklimit)
    {
        push3(v8,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v29,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v8;
    stack[-3] = v29;
    stack[-4] = v0;
/* end of prologue */
    v206 = stack[-2];
    v205 = elt(env, 1); /* symbolic */
    if (v206 == v205) goto v128;
    v205 = stack[-4];
    if (!consp(v205)) goto v23;
    v205 = stack[-4];
    v206 = qcdr(v205);
    v205 = stack[-3];
    fn = elt(env, 10); /* intexprlisp */
    v205 = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    if (v205 == nil) goto v210;
    v205 = stack[-4];
    v206 = qcar(v205);
    v205 = elt(env, 3); /* boolfn */
    v205 = get(v206, v205);
    env = stack[-6];
    if (!(v205 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v210:
    v205 = stack[-4];
    v205 = qcar(v205);
    if (!(symbolp(v205))) goto v211;
    v205 = stack[-4];
    v206 = qcar(v205);
    v205 = elt(env, 3); /* boolfn */
    v205 = get(v206, v205);
    env = stack[-6];
    if (v205 == nil) goto v211;
    v205 = stack[-4];
    v206 = qcar(v205);
    v205 = elt(env, 3); /* boolfn */
    stack[0] = get(v206, v205);
    env = stack[-6];
    v205 = stack[-4];
    v207 = qcdr(v205);
    v206 = stack[-3];
    v205 = stack[-2];
    fn = elt(env, 11); /* formclis */
    v205 = (*qfnn(fn))(qenv(fn), 3, v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v212 = stack[0];
        popv(7);
        return cons(v212, v205);
    }

v211:
    v205 = stack[-4];
    v205 = qcar(v205);
    if (!(symbolp(v205))) goto v213;
    v205 = stack[-4];
    v206 = qcar(v205);
    v205 = elt(env, 4); /* boolean */
    v205 = Lflagp(nil, v206, v205);
    env = stack[-6];
    if (v205 == nil) goto v213;
    v205 = stack[-4];
    stack[0] = qcar(v205);
    v205 = stack[-4];
    v62 = qcdr(v205);
    v208 = stack[-3];
    v207 = stack[-2];
    v205 = stack[-4];
    v206 = qcar(v205);
    v205 = elt(env, 5); /* boolargs */
    v205 = Lflagp(nil, v206, v205);
    env = stack[-6];
    fn = elt(env, 12); /* formboollis */
    v205 = (*qfnn(fn))(qenv(fn), 4, v62, v208, v207, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v214 = stack[0];
        popv(7);
        return cons(v214, v205);
    }

v213:
    v205 = stack[-4];
    v206 = qcar(v205);
    v205 = elt(env, 2); /* boolvalue!* */
    if (v206 == v205) goto v215;
    v205 = stack[-4];
    v206 = qcar(v205);
    v205 = elt(env, 8); /* where */
    if (v206 == v205) goto v216;
    stack[0] = elt(env, 2); /* boolvalue!* */
    v207 = stack[-4];
    v206 = stack[-3];
    v205 = stack[-2];
    fn = elt(env, 13); /* formc!* */
    v205 = (*qfnn(fn))(qenv(fn), 3, v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v217 = stack[0];
        popv(7);
        return list2(v217, v205);
    }

v216:
    stack[-5] = elt(env, 2); /* boolvalue!* */
    stack[-1] = elt(env, 8); /* where */
    stack[0] = elt(env, 9); /* bool!-eval */
    v205 = stack[-4];
    v205 = qcdr(v205);
    v207 = qcar(v205);
    v206 = stack[-3];
    v205 = stack[-2];
    v205 = CC_formbool(env, 3, v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v205 = list2(stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v206 = Lmkquote(nil, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v205 = stack[-4];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcar(v205);
    v207 = list3(stack[-1], v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v206 = stack[-3];
    v205 = stack[-2];
    fn = elt(env, 13); /* formc!* */
    v205 = (*qfnn(fn))(qenv(fn), 3, v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v218 = stack[-5];
        popv(7);
        return list2(v218, v205);
    }

v215:
    v205 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v205 == nil)) goto v83;
    v205 = elt(env, 7); /* "Too many formbools" */
    fn = elt(env, 14); /* lprie */
    v205 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    goto v83;

v83:
    v205 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v205 = nil;
    { popv(7); return onevalue(v205); }

v23:
    v206 = stack[-4];
    v205 = lisp_true;
    if (v206 == v205) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v205 = stack[-4];
    if (!(symbolp(v205))) goto v5;
    v206 = stack[-4];
    v205 = stack[-3];
    v205 = Latsoc(nil, v206, v205);
    if (!(v205 == nil)) goto v5;
    stack[0] = elt(env, 2); /* boolvalue!* */
    v207 = stack[-4];
    v206 = stack[-3];
    v205 = stack[-2];
    fn = elt(env, 13); /* formc!* */
    v205 = (*qfnn(fn))(qenv(fn), 3, v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v219 = stack[0];
        popv(7);
        return list2(v219, v205);
    }

v5:
    v206 = elt(env, 2); /* boolvalue!* */
    v205 = stack[-4];
    popv(7);
    return list2(v206, v205);

v128:
    v207 = stack[-4];
    v206 = stack[-3];
    v205 = stack[-2];
    {
        popv(7);
        fn = elt(env, 15); /* formc */
        return (*qfnn(fn))(qenv(fn), 3, v207, v206, v205);
    }
/* error exit handlers */
v209:
    popv(7);
    return nil;
}



/* Code for getavalue */

static Lisp_Object CC_getavalue(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getavalue");
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
    v34 = v0;
/* end of prologue */
    v28 = v34;
    v34 = elt(env, 1); /* avalue */
    v34 = get(v28, v34);
    env = stack[0];
    v28 = v34;
    v34 = v28;
    if (v34 == nil) goto v133;
    v34 = v28;
    v34 = qcdr(v34);
    v34 = qcar(v34);
    { popv(1); return onevalue(v34); }

v133:
    v34 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v34); }
}



/* Code for msolve!-polyn */

static Lisp_Object CC_msolveKpolyn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-polyn");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v29;
    stack[-9] = v0;
/* end of prologue */
    v39 = stack[-8];
    v39 = qcar(v39);
    stack[-10] = v39;
    v39 = stack[-8];
    v39 = qcdr(v39);
    if (v39 == nil) goto v38;
    v39 = (Lisp_Object)1; /* 0 */
    stack[-7] = v39;
    goto v27;

v27:
    v39 = qvalue(elt(env, 1)); /* current!-modulus */
    v40 = sub1(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = stack[-7];
    v39 = difference2(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = Lminusp(nil, v39);
    env = stack[-11];
    if (v39 == nil) goto v32;
    v39 = qvalue(elt(env, 2)); /* nil */
    { popv(12); return onevalue(v39); }

v32:
    stack[0] = stack[-9];
    v40 = stack[-10];
    v39 = stack[-7];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    fn = elt(env, 3); /* subf */
    v39 = (*qfn2(fn))(qenv(fn), stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v40 = qcar(v39);
    v39 = stack[-8];
    v39 = qcdr(v39);
    v39 = CC_msolveKpolyn(env, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    stack[-3] = v39;
    v39 = stack[-3];
    if (v39 == nil) goto v100;
    v39 = stack[-3];
    v39 = qcar(v39);
    v49 = stack[-10];
    v40 = stack[-7];
    v39 = acons(v49, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    stack[-1] = v39;
    stack[-2] = v39;
    goto v1;

v1:
    v39 = stack[-3];
    v39 = qcdr(v39);
    stack[-3] = v39;
    v39 = stack[-3];
    if (v39 == nil) goto v152;
    stack[0] = stack[-1];
    v39 = stack[-3];
    v39 = qcar(v39);
    v49 = stack[-10];
    v40 = stack[-7];
    v39 = acons(v49, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = Lrplacd(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[-1] = v39;
    goto v1;

v152:
    v39 = stack[-2];
    goto v140;

v140:
    stack[-6] = v39;
    v39 = stack[-6];
    fn = elt(env, 4); /* lastpair */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    stack[-5] = v39;
    v39 = stack[-7];
    v39 = add1(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    stack[-7] = v39;
    v39 = stack[-5];
    if (!consp(v39)) goto v27;
    else goto v198;

v198:
    v39 = qvalue(elt(env, 1)); /* current!-modulus */
    v40 = sub1(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = stack[-7];
    v39 = difference2(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = Lminusp(nil, v39);
    env = stack[-11];
    if (!(v39 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    stack[0] = stack[-9];
    v40 = stack[-10];
    v39 = stack[-7];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    fn = elt(env, 3); /* subf */
    v39 = (*qfn2(fn))(qenv(fn), stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v40 = qcar(v39);
    v39 = stack[-8];
    v39 = qcdr(v39);
    v39 = CC_msolveKpolyn(env, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    stack[-3] = v39;
    v39 = stack[-3];
    if (v39 == nil) goto v242;
    v39 = stack[-3];
    v39 = qcar(v39);
    v49 = stack[-10];
    v40 = stack[-7];
    v39 = acons(v49, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    stack[-1] = v39;
    stack[-2] = v39;
    goto v243;

v243:
    v39 = stack[-3];
    v39 = qcdr(v39);
    stack[-3] = v39;
    v39 = stack[-3];
    if (v39 == nil) goto v79;
    stack[0] = stack[-1];
    v39 = stack[-3];
    v39 = qcar(v39);
    v49 = stack[-10];
    v40 = stack[-7];
    v39 = acons(v49, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = Lrplacd(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[-1] = v39;
    goto v243;

v79:
    v39 = stack[-2];
    goto v244;

v244:
    v39 = Lrplacd(nil, stack[-4], v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    v39 = stack[-5];
    fn = elt(env, 4); /* lastpair */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    stack[-5] = v39;
    v39 = stack[-7];
    v39 = add1(v39);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-11];
    stack[-7] = v39;
    goto v198;

v242:
    v39 = qvalue(elt(env, 2)); /* nil */
    goto v244;

v100:
    v39 = qvalue(elt(env, 2)); /* nil */
    goto v140;

v38:
    v40 = stack[-9];
    v39 = stack[-8];
    v39 = qcar(v39);
    {
        popv(12);
        fn = elt(env, 5); /* msolve!-poly1 */
        return (*qfn2(fn))(qenv(fn), v40, v39);
    }
/* error exit handlers */
v241:
    popv(12);
    return nil;
}



/* Code for basic!-kern */

static Lisp_Object CC_basicKkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basic-kern");
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
    v14 = v0;
/* end of prologue */
    v22 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v22;
    v22 = v14;
    stack[0] = v22;
    goto v20;

v20:
    v22 = stack[0];
    if (v22 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v22 = stack[0];
    v22 = qcar(v22);
    fn = elt(env, 2); /* basic!-kern1 */
    v14 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    v22 = stack[-1];
    fn = elt(env, 3); /* union */
    v22 = (*qfn2(fn))(qenv(fn), v14, v22);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    stack[-1] = v22;
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v20;
/* error exit handlers */
v24:
    popv(3);
    return nil;
}



/* Code for cl_nnf */

static Lisp_Object CC_cl_nnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_nnf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v245 = v0;
/* end of prologue */
    v18 = v245;
    v245 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* cl_nnf1 */
        return (*qfn2(fn))(qenv(fn), v18, v245);
    }
}



/* Code for containerml */

static Lisp_Object CC_containerml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for containerml");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */
    v147 = stack[0];
    v36 = elt(env, 1); /* integer_interval */
    if (!(v147 == v36)) goto v145;
    v36 = elt(env, 2); /* interval */
    stack[0] = v36;
    goto v145;

v145:
    v36 = elt(env, 3); /* "<" */
    fn = elt(env, 9); /* printout */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v36 = stack[0];
    v36 = Lprinc(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v36 = stack[-1];
    v147 = qcar(v36);
    v36 = elt(env, 4); /* "" */
    fn = elt(env, 10); /* attributesml */
    v36 = (*qfn2(fn))(qenv(fn), v147, v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v36 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 11); /* indent!* */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v36 = stack[-1];
    v36 = qcdr(v36);
    fn = elt(env, 12); /* multi_elem */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v36 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 11); /* indent!* */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v36 = elt(env, 7); /* "</" */
    fn = elt(env, 9); /* printout */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v36 = stack[0];
    v36 = Lprinc(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v36 = elt(env, 8); /* ">" */
    v36 = Lprinc(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v151;
    v36 = nil;
    { popv(3); return onevalue(v36); }
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for f2dip1 */

static Lisp_Object MS_CDECL CC_f2dip1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v247, v157, v158, v50, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "f2dip1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip1");
#endif
    if (stack >= stacklimit)
    {
        push3(v8,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v29,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v29;
    stack[-2] = v0;
/* end of prologue */
    v247 = stack[-2];
    if (v247 == nil) goto v145;
    v247 = stack[-2];
    if (!consp(v247)) goto v245;
    v247 = stack[-2];
    v247 = qcar(v247);
    if (!consp(v247)) goto v245;
    v247 = stack[-2];
    v247 = qcar(v247);
    v247 = qcar(v247);
    v71 = qcar(v247);
    v247 = stack[-2];
    v247 = qcar(v247);
    v247 = qcar(v247);
    v50 = qcdr(v247);
    v247 = stack[-2];
    v247 = qcar(v247);
    v158 = qcdr(v247);
    v157 = stack[-1];
    v247 = stack[0];
    fn = elt(env, 2); /* f2dip2 */
    stack[-3] = (*qfnn(fn))(qenv(fn), 5, v71, v50, v158, v157, v247);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    v247 = stack[-2];
    v158 = qcdr(v247);
    v157 = stack[-1];
    v247 = stack[0];
    v247 = CC_f2dip1(env, 3, v158, v157, v247);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    {
        Lisp_Object v248 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* dipsum */
        return (*qfn2(fn))(qenv(fn), v248, v247);
    }

v245:
    v247 = stack[0];
    v247 = (is_number(v247) ? lisp_true : nil);
    if (!(v247 == nil)) goto v12;
    v247 = stack[0];
    fn = elt(env, 4); /* f2dip11 */
    v247 = (*qfn1(fn))(qenv(fn), v247);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    goto v12;

v12:
    v247 = stack[-2];
    fn = elt(env, 5); /* bcfd */
    v247 = (*qfn1(fn))(qenv(fn), v247);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    fn = elt(env, 6); /* bcprod */
    v247 = (*qfn2(fn))(qenv(fn), stack[0], v247);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    v157 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v112 = stack[-1];
        popv(5);
        return list2star(v112, v247, v157);
    }

v145:
    v247 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v247); }
/* error exit handlers */
v237:
    popv(5);
    return nil;
}



/* Code for mkupf */

static Lisp_Object CC_mkupf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v112, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkupf");
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
    v248 = v0;
/* end of prologue */
    v112 = v248;
    v248 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* mksq */
    v248 = (*qfn2(fn))(qenv(fn), v112, v248);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[0];
    v249 = v248;
    v248 = v249;
    v248 = qcar(v248);
    if (v248 == nil) goto v131;
    v248 = v249;
    v248 = qcar(v248);
    if (!consp(v248)) goto v14;
    v248 = v249;
    v248 = qcar(v248);
    v248 = qcar(v248);
    if (!consp(v248)) goto v14;
    v248 = v249;
    v112 = qcdr(v248);
    v248 = (Lisp_Object)17; /* 1 */
    if (!(v112 == v248)) goto v250;
    v248 = v249;
    v248 = qcar(v248);
    v248 = qcar(v248);
    v112 = qcdr(v248);
    v248 = (Lisp_Object)17; /* 1 */
    if (!(v112 == v248)) goto v250;
    v248 = v249;
    v248 = qcar(v248);
    v248 = qcdr(v248);
    if (!(v248 == nil)) goto v250;
    v248 = v249;
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    if (!consp(v248)) goto v204;
    v248 = v249;
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    if (!(!consp(v248))) goto v250;

v204:
    v248 = v249;
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    v249 = qcar(v248);
    v112 = (Lisp_Object)17; /* 1 */
    v248 = (Lisp_Object)17; /* 1 */
    v248 = list2star(v249, v112, v248);
    nil = C_nil;
    if (exception_pending()) goto v153;
    popv(1);
    return ncons(v248);

v250:
    v248 = v249;
    {
        popv(1);
        fn = elt(env, 3); /* partitsq!* */
        return (*qfn1(fn))(qenv(fn), v248);
    }

v14:
    v248 = (Lisp_Object)17; /* 1 */
    v112 = v249;
    v248 = cons(v248, v112);
    nil = C_nil;
    if (exception_pending()) goto v153;
    popv(1);
    return ncons(v248);

v131:
    v248 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v248); }
/* error exit handlers */
v153:
    popv(1);
    return nil;
}



/* Code for getphystypeall */

static Lisp_Object CC_getphystypeall(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypeall");
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
    v36 = (Lisp_Object)1; /* 0 */
    v165 = stack[0];
    fn = elt(env, 3); /* deleteall */
    v165 = (*qfn2(fn))(qenv(fn), v36, v165);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    fn = elt(env, 4); /* collectphystype */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    v36 = v165;
    if (v165 == nil) goto v20;
    v165 = v36;
    v165 = qcdr(v165);
    if (v165 == nil) goto v31;
    stack[-1] = elt(env, 0); /* getphystypeall */
    v36 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v165 = stack[0];
    v165 = list2(v36, v165);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v165 = (*qfn2(fn))(qenv(fn), stack[-1], v165);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v165 = nil;
    { popv(3); return onevalue(v165); }

v31:
    v165 = v36;
    v165 = qcar(v165);
    { popv(3); return onevalue(v165); }

v20:
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v165); }
/* error exit handlers */
v135:
    popv(3);
    return nil;
}



/* Code for fs!:make!-nullangle */

static Lisp_Object MS_CDECL CC_fsTmakeKnullangle(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v142, v143;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fs:make-nullangle");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:make-nullangle");
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
    v31 = (Lisp_Object)113; /* 7 */
    v31 = Lmkvect(nil, v31);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    stack[-1] = v31;
    v31 = (Lisp_Object)1; /* 0 */
    stack[0] = v31;
    goto v132;

v132:
    v142 = (Lisp_Object)113; /* 7 */
    v31 = stack[0];
    v31 = difference2(v142, v31);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v31 = Lminusp(nil, v31);
    env = stack[-2];
    if (!(v31 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v143 = stack[-1];
    v142 = stack[0];
    v31 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v143 + (CELL-TAG_VECTOR) + ((int32_t)v142/(16/CELL))) = v31;
    v31 = stack[0];
    v31 = add1(v31);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    stack[0] = v31;
    goto v132;
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for mo_2a */

static Lisp_Object CC_mo_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_2a");
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
    v108 = v0;
/* end of prologue */
    stack[0] = qcar(v108);
    v108 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 2); /* ring_all_names */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    {
        Lisp_Object v131 = stack[0];
        popv(2);
        fn = elt(env, 3); /* mo!=expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v131, v108);
    }
/* error exit handlers */
v127:
    popv(2);
    return nil;
}



/* Code for msolve!-poly1 */

static Lisp_Object CC_msolveKpoly1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v265, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-poly1");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v29;
    stack[-5] = v0;
/* end of prologue */
    v264 = stack[-5];
    if (!consp(v264)) goto v160;
    v264 = stack[-5];
    v264 = qcar(v264);
    if (!consp(v264)) goto v160;
    v264 = stack[-5];
    v264 = qcar(v264);
    v264 = qcar(v264);
    v265 = qcdr(v264);
    v264 = (Lisp_Object)17; /* 1 */
    if (!(v265 == v264)) goto v160;
    v264 = stack[-5];
    v264 = qcar(v264);
    v264 = qcdr(v264);
    fn = elt(env, 5); /* safe!-modrecip */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[0] = v264;
    v264 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v264; /* erfg!* */
    v264 = stack[0];
    if (v264 == nil) goto v160;
    v264 = stack[-5];
    v264 = qcdr(v264);
    fn = elt(env, 6); /* negf */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    fn = elt(env, 7); /* multf */
    v264 = (*qfn2(fn))(qenv(fn), stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    fn = elt(env, 8); /* moduntag */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[0] = v264;
    v264 = stack[0];
    if (v264 == nil) goto v37;
    v265 = stack[0];
    v264 = (Lisp_Object)1; /* 0 */
    v264 = (Lisp_Object)lessp2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    v264 = v264 ? lisp_true : nil;
    env = stack[-7];
    if (!(v264 == nil)) goto v148;
    v265 = stack[0];
    v264 = qvalue(elt(env, 3)); /* current!-modulus */
    v264 = (Lisp_Object)greaterp2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    v264 = v264 ? lisp_true : nil;
    env = stack[-7];
    if (!(v264 == nil)) goto v148;

v37:
    v264 = stack[0];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[0] = v264;
    goto v26;

v26:
    v264 = stack[0];
    stack[-5] = v264;
    v264 = stack[-5];
    if (v264 == nil) goto v39;
    v264 = stack[-5];
    v264 = qcar(v264);
    stack[0] = stack[-4];
    v265 = v264;
    v264 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 9); /* prepf1 */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v265 = v264;
    v264 = v265;
    if (v264 == nil) goto v268;
    v264 = v265;
    fn = elt(env, 10); /* replus */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    goto v269;

v269:
    v264 = cons(stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[-2] = v264;
    stack[-3] = v264;
    goto v270;

v270:
    v264 = stack[-5];
    v264 = qcdr(v264);
    stack[-5] = v264;
    v264 = stack[-5];
    if (v264 == nil) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v264 = stack[-5];
    v264 = qcar(v264);
    stack[0] = stack[-4];
    v265 = v264;
    v264 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 9); /* prepf1 */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v265 = v264;
    v264 = v265;
    if (v264 == nil) goto v271;
    v264 = v265;
    fn = elt(env, 10); /* replus */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    goto v217;

v217:
    v264 = cons(stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = Lrplacd(nil, stack[-1], v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = stack[-2];
    v264 = qcdr(v264);
    stack[-2] = v264;
    goto v270;

v271:
    v264 = (Lisp_Object)1; /* 0 */
    goto v217;

v268:
    v264 = (Lisp_Object)1; /* 0 */
    goto v269;

v39:
    v264 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v264); }

v148:
    v264 = stack[0];
    fn = elt(env, 11); /* general!-modular!-number */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[0] = v264;
    goto v37;

v160:
    v266 = stack[-5];
    v265 = stack[-4];
    v264 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 12); /* lowestdeg */
    v264 = (*qfnn(fn))(qenv(fn), 3, v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[-6] = v264;
    v265 = stack[-6];
    v264 = (Lisp_Object)1; /* 0 */
    v264 = (Lisp_Object)greaterp2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    v264 = v264 ? lisp_true : nil;
    env = stack[-7];
    if (v264 == nil) goto v68;
    stack[0] = stack[-5];
    v266 = elt(env, 4); /* expt */
    v265 = stack[-4];
    v264 = stack[-6];
    v264 = list3(v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    fn = elt(env, 13); /* simp */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = qcar(v264);
    fn = elt(env, 14); /* quotf */
    v264 = (*qfn2(fn))(qenv(fn), stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[-5] = v264;
    goto v68;

v68:
    v264 = stack[-5];
    fn = elt(env, 8); /* moduntag */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    fn = elt(env, 15); /* general!-reduce!-mod!-p */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[-5] = v264;
    v264 = (Lisp_Object)17; /* 1 */
    stack[-3] = v264;
    goto v88;

v88:
    v264 = qvalue(elt(env, 3)); /* current!-modulus */
    v265 = sub1(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = stack[-3];
    v264 = difference2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = Lminusp(nil, v264);
    env = stack[-7];
    if (v264 == nil) goto v272;
    v264 = qvalue(elt(env, 1)); /* nil */
    goto v96;

v96:
    stack[0] = v264;
    v265 = stack[-6];
    v264 = (Lisp_Object)1; /* 0 */
    v264 = (Lisp_Object)greaterp2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    v264 = v264 ? lisp_true : nil;
    env = stack[-7];
    if (v264 == nil) goto v26;
    v264 = qvalue(elt(env, 1)); /* nil */
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = Lappend(nil, stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[0] = v264;
    goto v26;

v272:
    v266 = stack[-5];
    v265 = stack[-4];
    v264 = stack[-3];
    fn = elt(env, 16); /* general!-evaluate!-mod!-p */
    v264 = (*qfnn(fn))(qenv(fn), 3, v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    if (v264 == nil) goto v89;
    v264 = nil;
    goto v94;

v94:
    stack[-2] = v264;
    v264 = stack[-2];
    fn = elt(env, 17); /* lastpair */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[-1] = v264;
    v264 = stack[-3];
    v264 = add1(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[-3] = v264;
    v264 = stack[-1];
    if (!consp(v264)) goto v88;
    else goto v87;

v87:
    v264 = qvalue(elt(env, 3)); /* current!-modulus */
    v265 = sub1(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = stack[-3];
    v264 = difference2(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = Lminusp(nil, v264);
    env = stack[-7];
    if (v264 == nil) goto v195;
    v264 = stack[-2];
    goto v96;

v195:
    stack[0] = stack[-1];
    v266 = stack[-5];
    v265 = stack[-4];
    v264 = stack[-3];
    fn = elt(env, 16); /* general!-evaluate!-mod!-p */
    v264 = (*qfnn(fn))(qenv(fn), 3, v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    if (v264 == nil) goto v273;
    v264 = nil;
    goto v213;

v213:
    v264 = Lrplacd(nil, stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    v264 = stack[-1];
    fn = elt(env, 17); /* lastpair */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[-1] = v264;
    v264 = stack[-3];
    v264 = add1(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    stack[-3] = v264;
    goto v87;

v273:
    v264 = stack[-3];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    goto v213;

v89:
    v264 = stack[-3];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-7];
    goto v94;
/* error exit handlers */
v267:
    popv(8);
    return nil;
}



/* Code for cl_pnf */

static Lisp_Object CC_cl_pnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pnf");
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
    v25 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_nnf */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* cl_pnf1 */
        return (*qfn1(fn))(qenv(fn), v25);
    }
/* error exit handlers */
v145:
    popv(1);
    return nil;
}



/* Code for ofsf_smordtable */

static Lisp_Object CC_ofsf_smordtable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v137, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smordtable");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v29;
    v137 = v0;
/* end of prologue */
    v11 = elt(env, 1); /* ((equal (equal . false) (neq equal . t) (geq equal . t) (leq . false) (greaterp equal . t) (lessp . false)) (neq (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp))
 (geq (equal . false) (neq geq . t) (geq geq . t) (leq . false) (greaterp geq . t) (lessp . false)) (leq (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp)) (greaterp (equal . false) (neq gr
eaterp . t) (geq greaterp . t) (leq . false) (greaterp greaterp . t) (lessp . false)) (lessp (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp))) 
*/
    v137 = Latsoc(nil, v137, v11);
    v28 = Latsoc(nil, v28, v137);
    v28 = qcdr(v28);
    return onevalue(v28);
}



/* Code for aex_xtothen */

static Lisp_Object CC_aex_xtothen(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v11, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_xtothen");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v137 = v29;
    v11 = v0;
/* end of prologue */
    fn = elt(env, 2); /* ratpoly_xtothen */
    stack[0] = (*qfn2(fn))(qenv(fn), v11, v137);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    fn = elt(env, 3); /* ctx_new */
    v149 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v11 = qvalue(elt(env, 1)); /* t */
    v137 = qvalue(elt(env, 1)); /* t */
    {
        Lisp_Object v21 = stack[0];
        popv(2);
        fn = elt(env, 4); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v21, v149, v11, v137);
    }
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for dip_moncomp */

static Lisp_Object MS_CDECL CC_dip_moncomp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v128, v132;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip_moncomp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_moncomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v131 = v8;
    v128 = v29;
    v132 = v0;
/* end of prologue */
    return list2star(v128, v132, v131);
}



/* Code for matrix_rows */

static Lisp_Object CC_matrix_rows(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix_rows");
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
    v12 = stack[0];
    if (v12 == nil) goto v25;
    v12 = elt(env, 1); /* "<matrixrow>" */
    fn = elt(env, 5); /* printout */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    v27 = qvalue(elt(env, 2)); /* indent */
    v12 = (Lisp_Object)49; /* 3 */
    v12 = plus2(v27, v12);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    qvalue(elt(env, 2)) = v12; /* indent */
    v12 = stack[0];
    v12 = qcar(v12);
    fn = elt(env, 6); /* row */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    v27 = qvalue(elt(env, 2)); /* indent */
    v12 = (Lisp_Object)49; /* 3 */
    v12 = difference2(v27, v12);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    qvalue(elt(env, 2)) = v12; /* indent */
    v12 = elt(env, 3); /* "</matrixrow>" */
    fn = elt(env, 5); /* printout */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    v12 = stack[0];
    v12 = qcdr(v12);
    v12 = CC_matrix_rows(env, v12);
    nil = C_nil;
    if (exception_pending()) goto v142;
    goto v25;

v25:
    v12 = nil;
    { popv(2); return onevalue(v12); }
/* error exit handlers */
v142:
    popv(2);
    return nil;
}



/* Code for ps!:times!-erule */

static Lisp_Object CC_psTtimesKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v276, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:times-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v29;
    v168 = v0;
/* end of prologue */
    v276 = v168;
    v276 = qcdr(v276);
    v276 = qcar(v276);
    stack[-9] = v276;
    v276 = v168;
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    stack[-7] = v276;
    v168 = qvalue(elt(env, 1)); /* nil */
    v276 = (Lisp_Object)17; /* 1 */
    v276 = cons(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[0] = v276;
    v276 = stack[-9];
    fn = elt(env, 3); /* ps!:order */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-6] = v276;
    v276 = qvalue(elt(env, 2)); /* ps */
    fn = elt(env, 3); /* ps!:order */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-5] = v276;
    v276 = stack[-7];
    fn = elt(env, 3); /* ps!:order */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-4] = v276;
    v276 = (Lisp_Object)1; /* 0 */
    stack[-3] = v276;
    goto v30;

v30:
    v168 = stack[-8];
    v276 = stack[-5];
    v168 = difference2(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v276 = stack[-3];
    v276 = difference2(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v276 = Lminusp(nil, v276);
    env = stack[-10];
    if (!(v276 == nil)) { Lisp_Object res = stack[0]; popv(11); return onevalue(res); }
    v168 = stack[-8];
    v276 = stack[-6];
    v168 = difference2(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v276 = stack[-3];
    v168 = difference2(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v276 = stack[-4];
    v276 = (Lisp_Object)geq2(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    v276 = v276 ? lisp_true : nil;
    env = stack[-10];
    if (v276 == nil) goto v32;
    stack[-2] = stack[0];
    stack[0] = stack[-9];
    v168 = stack[-3];
    v276 = stack[-6];
    v276 = plus2(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    fn = elt(env, 4); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[0] = stack[-7];
    v168 = stack[-8];
    v276 = stack[-6];
    v168 = difference2(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v276 = stack[-3];
    v276 = difference2(v168, v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    fn = elt(env, 4); /* ps!:evaluate */
    v276 = (*qfn2(fn))(qenv(fn), stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    fn = elt(env, 5); /* multsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-1], v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    fn = elt(env, 6); /* addsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-2], v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[0] = v276;
    goto v32;

v32:
    v276 = stack[-3];
    v276 = add1(v276);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-3] = v276;
    goto v30;
/* error exit handlers */
v95:
    popv(11);
    return nil;
}



/* Code for look_for_substitute */

static Lisp_Object MS_CDECL CC_look_for_substitute(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v126, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_substitute");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_substitute");
#endif
    if (stack >= stacklimit)
    {
        push3(v8,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v29,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v29;
    stack[-2] = v0;
/* end of prologue */

v277:
    v111 = stack[0];
    if (!consp(v111)) goto v146;
    v240 = stack[-2];
    v126 = stack[-1];
    v111 = stack[0];
    fn = elt(env, 2); /* look_for_rational */
    v111 = (*qfnn(fn))(qenv(fn), 3, v240, v126, v111);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    v126 = v111;
    if (!(v111 == nil)) { popv(4); return onevalue(v126); }
    v240 = stack[-2];
    v126 = stack[-1];
    v111 = stack[0];
    fn = elt(env, 3); /* look_for_quad */
    v111 = (*qfnn(fn))(qenv(fn), 3, v240, v126, v111);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    v126 = v111;
    if (!(v111 == nil)) { popv(4); return onevalue(v126); }
    v240 = stack[-2];
    v126 = stack[-1];
    v111 = stack[0];
    v111 = qcar(v111);
    v111 = CC_look_for_substitute(env, 3, v240, v126, v111);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    v126 = v111;
    if (!(v111 == nil)) { popv(4); return onevalue(v126); }
    v240 = stack[-2];
    v126 = stack[-1];
    v111 = stack[0];
    v111 = qcdr(v111);
    stack[-2] = v240;
    stack[-1] = v126;
    stack[0] = v111;
    goto v277;

v146:
    v111 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v111); }
/* error exit handlers */
v16:
    popv(4);
    return nil;
}



/* Code for init */

static Lisp_Object CC_init(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57, v289, v271;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for init");
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
    v56 = qvalue(elt(env, 1)); /* rowmin */
    stack[-2] = v56;
    goto v128;

v128:
    v57 = qvalue(elt(env, 2)); /* rowmax */
    v56 = stack[-2];
    v56 = difference2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    v56 = Lminusp(nil, v56);
    env = stack[-3];
    if (v56 == nil) goto v21;
    v57 = qvalue(elt(env, 5)); /* maxvar */
    v56 = stack[-1];
    if (equal(v57, v56)) goto v291;
    v57 = (Lisp_Object)33; /* 2 */
    v56 = stack[-1];
    v56 = times2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    v56 = Lmkvect(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    qvalue(elt(env, 4)) = v56; /* codmat */
    goto v292;

v292:
    v56 = qvalue(elt(env, 14)); /* kvarlst */
    if (v56 == nil) goto v293;
    v56 = qvalue(elt(env, 14)); /* kvarlst */
    v271 = v56;
    goto v223;

v223:
    v56 = v271;
    if (v56 == nil) goto v293;
    v56 = v271;
    v56 = qcar(v56);
    v289 = v56;
    v56 = v289;
    v56 = qcdr(v56);
    v57 = qcar(v56);
    v56 = elt(env, 14); /* kvarlst */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v56 = v289;
    v56 = qcdr(v56);
    v57 = qcar(v56);
    v56 = elt(env, 11); /* nex */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v56 = v271;
    v56 = qcdr(v56);
    v271 = v56;
    goto v223;

v293:
    v56 = elt(env, 19); /* (plus minus difference times expt sqrt) */
    v289 = v56;
    goto v294;

v294:
    v56 = v289;
    if (v56 == nil) goto v295;
    v56 = v289;
    v56 = qcar(v56);
    v57 = v56;
    v56 = elt(env, 14); /* kvarlst */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v56 = v289;
    v56 = qcdr(v56);
    v289 = v56;
    goto v294;

v295:
    v56 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 20)) = v56; /* avarlst */
    qvalue(elt(env, 21)) = v56; /* codbexl!* */
    qvalue(elt(env, 14)) = v56; /* kvarlst */
    qvalue(elt(env, 22)) = v56; /* prevlst */
    qvalue(elt(env, 8)) = v56; /* varlst!+ */
    qvalue(elt(env, 9)) = v56; /* varlst!* */
    v56 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 23)) = v56; /* preprefixlist */
    qvalue(elt(env, 24)) = v56; /* malst */
    v56 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 25)) = v56; /* prefixlist */
    v56 = (Lisp_Object)-15; /* -1 */
    qvalue(elt(env, 2)) = v56; /* rowmax */
    v56 = stack[-1];
    qvalue(elt(env, 5)) = v56; /* maxvar */
    v56 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v56; /* rowmin */
    v271 = (Lisp_Object)1; /* 0 */
    v289 = (Lisp_Object)1; /* 0 */
    v57 = (Lisp_Object)1; /* 0 */
    v56 = (Lisp_Object)1; /* 0 */
    v56 = list4(v271, v289, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    qvalue(elt(env, 26)) = v56; /* ops */
    v56 = nil;
    { popv(4); return onevalue(v56); }

v291:
    v56 = (Lisp_Object)1; /* 0 */
    stack[0] = v56;
    goto v190;

v190:
    v57 = (Lisp_Object)33; /* 2 */
    v56 = stack[-1];
    v57 = times2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    v56 = stack[0];
    v56 = difference2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    v56 = Lminusp(nil, v56);
    env = stack[-3];
    if (!(v56 == nil)) goto v292;
    v289 = qvalue(elt(env, 4)); /* codmat */
    v57 = stack[0];
    v56 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v289 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL))) = v56;
    v56 = stack[0];
    v56 = add1(v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    stack[0] = v56;
    goto v190;

v21:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v57 = qvalue(elt(env, 5)); /* maxvar */
    v56 = stack[-2];
    v56 = plus2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    v56 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    if (v56 == nil) goto v11;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v57 = qvalue(elt(env, 5)); /* maxvar */
    v56 = stack[-2];
    v56 = plus2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    v57 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    v56 = (Lisp_Object)49; /* 3 */
    v56 = *(Lisp_Object *)((char *)v57 + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    v289 = v56;
    if (is_number(v56)) goto v11;
    v57 = v289;
    v56 = elt(env, 6); /* npcdvar */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 7); /* nvarlst */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 8); /* varlst!+ */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 9); /* varlst!* */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 10); /* rowindex */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 11); /* nex */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 12); /* inlhs */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 13); /* rowocc */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 14); /* kvarlst */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 15); /* alias */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 16); /* finalalias */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 17); /* aliaslist */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    v57 = v289;
    v56 = elt(env, 18); /* inalias */
    v56 = Lremprop(nil, v57, v56);
    env = stack[-3];
    goto v11;

v11:
    v56 = stack[-2];
    v56 = add1(v56);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    stack[-2] = v56;
    goto v128;
/* error exit handlers */
v290:
    popv(4);
    return nil;
}



/* Code for get!:const */

static Lisp_Object CC_getTconst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get:const");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */
    v157 = stack[-1];
    if (!(!consp(v157))) goto v246;
    v157 = stack[0];
    v157 = integerp(v157);
    if (v157 == nil) goto v246;
    v158 = stack[0];
    v157 = (Lisp_Object)1; /* 0 */
    v157 = (Lisp_Object)greaterp2(v158, v157);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v157 = v157 ? lisp_true : nil;
    env = stack[-2];
    if (v157 == nil) goto v246;
    v158 = stack[-1];
    v157 = elt(env, 1); /* save!:c */
    v157 = get(v158, v157);
    env = stack[-2];
    stack[-1] = v157;
    v157 = stack[-1];
    if (v157 == nil) goto v24;
    v157 = stack[-1];
    v158 = qcar(v157);
    v157 = stack[0];
    v157 = (Lisp_Object)lessp2(v158, v157);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v157 = v157 ? lisp_true : nil;
    env = stack[-2];
    if (!(v157 == nil)) goto v24;
    v157 = stack[-1];
    v158 = qcar(v157);
    v157 = stack[0];
    if (equal(v158, v157)) goto v30;
    v157 = stack[-1];
    v158 = qcdr(v157);
    v157 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v158, v157);
    }

v30:
    v157 = stack[-1];
    v157 = qcdr(v157);
    { popv(3); return onevalue(v157); }

v24:
    v157 = elt(env, 2); /* not_found */
    { popv(3); return onevalue(v157); }

v246:
    stack[0] = (Lisp_Object)1; /* 0 */
    v158 = elt(env, 3); /* "Invalid argument to" */
    v157 = elt(env, 0); /* get!:const */
    v157 = list2(v158, v157);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    {
        Lisp_Object v250 = stack[0];
        popv(3);
        fn = elt(env, 5); /* error */
        return (*qfn2(fn))(qenv(fn), v250, v157);
    }
/* error exit handlers */
v68:
    popv(3);
    return nil;
}



/* Code for nspaces */

static Lisp_Object CC_nspaces(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144, v165;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nspaces");
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
    stack[-2] = nil;
    v143 = (Lisp_Object)17; /* 1 */
    stack[0] = v143;
    goto v128;

v128:
    v144 = stack[-1];
    v143 = stack[0];
    v143 = difference2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v143 = Lminusp(nil, v143);
    env = stack[-3];
    if (v143 == nil) goto v11;
    v143 = stack[-2];
    v143 = Lcompress(nil, v143);
    nil = C_nil;
    if (exception_pending()) goto v135;
        popv(4);
        return Lintern(nil, v143);

v11:
    v165 = elt(env, 2); /* !! */
    v144 = elt(env, 3); /* !  */
    v143 = stack[-2];
    v143 = list2star(v165, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    stack[-2] = v143;
    v143 = stack[0];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    stack[0] = v143;
    goto v128;
/* error exit handlers */
v135:
    popv(4);
    return nil;
}



/* Code for collectphysops */

static Lisp_Object CC_collectphysops(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectphysops");
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
    v103 = stack[0];
    if (!consp(v103)) goto v146;
    v103 = stack[0];
    fn = elt(env, 2); /* physopp */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    if (v103 == nil) goto v145;
    stack[-1] = stack[0];
    v103 = stack[0];
    fn = elt(env, 3); /* collectindices */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    fn = elt(env, 4); /* removeindices */
    v103 = (*qfn2(fn))(qenv(fn), stack[-1], v103);
    nil = C_nil;
    if (exception_pending()) goto v33;
    popv(3);
    return ncons(v103);

v145:
    v103 = stack[0];
    v103 = qcar(v103);
    v102 = v103;
    v103 = stack[0];
    v103 = qcdr(v103);
    stack[0] = v103;
    v103 = v102;
    v103 = CC_collectphysops(env, v103);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    v103 = Lnconc(nil, stack[-1], v103);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    stack[-1] = v103;
    v103 = stack[0];
    if (v103 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else goto v145;

v146:
    v103 = stack[0];
    fn = elt(env, 2); /* physopp */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    if (v103 == nil) goto v109;
    v103 = stack[0];
    popv(3);
    return ncons(v103);

v109:
    v103 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v103); }
/* error exit handlers */
v33:
    popv(3);
    return nil;
}



/* Code for extadd */

static Lisp_Object CC_extadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v29;
    stack[-3] = v0;
/* end of prologue */
    v94 = stack[-3];
    if (v94 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v94 = stack[-2];
    if (v94 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v94 = qvalue(elt(env, 1)); /* nil */
    v94 = ncons(v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    stack[-1] = v94;
    stack[-4] = v94;
    goto v137;

v137:
    v94 = stack[-3];
    if (v94 == nil) goto v202;
    v94 = stack[-2];
    if (v94 == nil) goto v202;
    v94 = stack[-2];
    v94 = qcar(v94);
    v89 = qcar(v94);
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = qcar(v94);
    if (equal(v89, v94)) goto v148;
    v94 = stack[-2];
    v94 = qcar(v94);
    v89 = qcar(v94);
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = qcar(v94);
    fn = elt(env, 2); /* ordexp */
    v94 = (*qfn2(fn))(qenv(fn), v89, v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    if (v94 == nil) goto v262;
    stack[0] = stack[-1];
    v94 = stack[-2];
    v94 = qcar(v94);
    v94 = ncons(v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    v94 = stack[-2];
    v94 = qcdr(v94);
    stack[-2] = v94;
    v94 = stack[-1];
    v94 = qcdr(v94);
    stack[-1] = v94;
    goto v137;

v262:
    stack[0] = stack[-1];
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = ncons(v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    v94 = stack[-3];
    v94 = qcdr(v94);
    stack[-3] = v94;
    v94 = stack[-1];
    v94 = qcdr(v94);
    stack[-1] = v94;
    goto v137;

v148:
    v94 = stack[-3];
    v94 = qcar(v94);
    v89 = qcdr(v94);
    v94 = stack[-2];
    v94 = qcar(v94);
    v94 = qcdr(v94);
    fn = elt(env, 4); /* addf */
    v89 = (*qfn2(fn))(qenv(fn), v89, v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    v94 = v89;
    if (v89 == nil) goto v140;
    stack[0] = stack[-1];
    v89 = stack[-3];
    v89 = qcar(v89);
    v89 = qcar(v89);
    v94 = cons(v89, v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    v94 = ncons(v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-5];
    v94 = stack[-1];
    v94 = qcdr(v94);
    stack[-1] = v94;
    goto v140;

v140:
    v94 = stack[-3];
    v94 = qcdr(v94);
    stack[-3] = v94;
    v94 = stack[-2];
    v94 = qcdr(v94);
    stack[-2] = v94;
    goto v137;

v202:
    v89 = stack[-1];
    v94 = stack[-3];
    if (v94 == nil) goto v199;
    v94 = stack[-3];
    goto v276;

v276:
    fn = elt(env, 3); /* setcdr */
    v94 = (*qfn2(fn))(qenv(fn), v89, v94);
    nil = C_nil;
    if (exception_pending()) goto v244;
    v94 = stack[-4];
    v94 = qcdr(v94);
    { popv(6); return onevalue(v94); }

v199:
    v94 = stack[-2];
    goto v276;
/* error exit handlers */
v244:
    popv(6);
    return nil;
}



/* Code for processpartitie1list1 */

static Lisp_Object CC_processpartitie1list1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for processpartitie1list1");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v29;
    v27 = v0;
/* end of prologue */

v145:
    v31 = v27;
    if (v31 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v31 = v27;
    v31 = qcdr(v31);
    stack[-4] = v31;
    stack[-2] = qcar(v27);
    stack[-1] = (Lisp_Object)1; /* 0 */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v27 = qvalue(elt(env, 1)); /* nil */
    v31 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v27 = stack[-3];
    fn = elt(env, 2); /* processpartitie1 */
    v27 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], v31, v27);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    stack[-3] = v27;
    v27 = stack[-4];
    goto v145;
/* error exit handlers */
v147:
    popv(6);
    return nil;
}



/* Code for omatpir */

static Lisp_Object MS_CDECL CC_omatpir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v134, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omatpir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omatpir");
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
    fn = elt(env, 3); /* lex */
    v149 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    fn = elt(env, 4); /* omsir */
    v149 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    v149 = qcar(v149);
    stack[-1] = v149;
    fn = elt(env, 3); /* lex */
    v149 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v149 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    v149 = qcar(v149);
    stack[0] = v149;
    fn = elt(env, 3); /* lex */
    v149 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    v149 = elt(env, 1); /* (!/ o m a t p) */
    fn = elt(env, 6); /* checktag */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    v110 = stack[-1];
    v134 = stack[0];
    v149 = qvalue(elt(env, 2)); /* nil */
    v149 = list2star(v110, v134, v149);
    nil = C_nil;
    if (exception_pending()) goto v14;
    popv(3);
    return ncons(v149);
/* error exit handlers */
v14:
    popv(3);
    return nil;
}



/* Code for f4 */

static Lisp_Object CC_f4(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v282;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f4");
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
    v282 = stack[0];
    v180 = elt(env, 1); /* pi */
    if (v282 == v180) goto v145;
    v282 = stack[0];
    v180 = elt(env, 3); /* euler_gamma */
    if (v282 == v180) goto v132;
    v282 = stack[0];
    v180 = elt(env, 5); /* true */
    if (v282 == v180) goto v110;
    v282 = stack[0];
    v180 = elt(env, 7); /* false */
    if (v282 == v180) goto v142;
    v282 = stack[0];
    v180 = elt(env, 9); /* !Na!N */
    if (v282 == v180) goto v140;
    v282 = stack[0];
    v180 = elt(env, 11); /* infinity */
    if (v282 == v180) goto v138;
    v282 = stack[0];
    v180 = elt(env, 17); /* e */
    if (v282 == v180) goto v157;
    v282 = stack[0];
    v180 = elt(env, 19); /* i */
    if (v282 == v180) goto v114;
    v180 = stack[0];
    if (!(is_number(v180))) goto v200;
    v180 = elt(env, 21); /* "<cn" */
    fn = elt(env, 34); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v180 = stack[0];
    v180 = Lfloatp(nil, v180);
    env = stack[-1];
    if (v180 == nil) goto v286;
    v180 = qvalue(elt(env, 12)); /* !*web */
    if (v180 == nil) goto v244;
    v180 = elt(env, 23); /* " type=&quot;real&quot;>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v94;

v94:
    v180 = stack[0];
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v180 = elt(env, 16); /* "</cn>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v200;

v200:
    v180 = stack[0];
    if (!(symbolp(v180))) goto v25;
    v180 = elt(env, 27); /* "<ci" */
    fn = elt(env, 34); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v180 = stack[0];
    fn = elt(env, 35); /* listp */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    if (v180 == nil) goto v273;
    v180 = qvalue(elt(env, 12)); /* !*web */
    if (v180 == nil) goto v297;
    v180 = elt(env, 29); /* " type=&quot;list&quot;>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v75;

v75:
    v180 = stack[0];
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v180 = elt(env, 32); /* "</ci>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;

v25:
    v180 = nil;
    { popv(2); return onevalue(v180); }

v297:
    v180 = elt(env, 28); /* " type=""list"">" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v75;

v273:
    v180 = stack[0];
    v180 = Lsimple_vectorp(nil, v180);
    env = stack[-1];
    if (v180 == nil) goto v177;
    v180 = qvalue(elt(env, 12)); /* !*web */
    if (v180 == nil) goto v285;
    v180 = elt(env, 31); /* " type=&quot;vector&quot;>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v75;

v285:
    v180 = elt(env, 30); /* " type=""vector"">" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v75;

v177:
    v180 = elt(env, 26); /* ">" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v75;

v244:
    v180 = elt(env, 22); /* " type=""real"">" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v94;

v286:
    v180 = stack[0];
    v180 = integerp(v180);
    if (v180 == nil) goto v87;
    v180 = qvalue(elt(env, 12)); /* !*web */
    if (v180 == nil) goto v298;
    v180 = elt(env, 25); /* " type=&quot;integer&quot;>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v94;

v298:
    v180 = elt(env, 24); /* " type=""integer"">" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v94;

v87:
    v180 = elt(env, 26); /* ">" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v94;

v114:
    v180 = qvalue(elt(env, 12)); /* !*web */
    if (v180 == nil) goto v156;
    v180 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v155;

v155:
    v180 = elt(env, 20); /* "&ImaginaryI;" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v180 = elt(env, 16); /* "</cn>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;

v156:
    v180 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v155;

v157:
    v180 = qvalue(elt(env, 12)); /* !*web */
    if (v180 == nil) goto v249;
    v180 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v112;

v112:
    v180 = elt(env, 18); /* "&ExponentialE;" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v180 = elt(env, 16); /* "</cn>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;

v249:
    v180 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v112;

v138:
    v180 = qvalue(elt(env, 12)); /* !*web */
    if (v180 == nil) goto v240;
    v180 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v126;

v126:
    v180 = elt(env, 15); /* "&infin;" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v180 = elt(env, 16); /* "</cn>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;

v240:
    v180 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v126;

v140:
    v180 = elt(env, 10); /* "<notanumber/>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;

v142:
    v180 = elt(env, 8); /* "<false/>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;

v110:
    v180 = elt(env, 6); /* "<true/>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;

v132:
    v180 = elt(env, 4); /* "<eulergamma/>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;

v145:
    v180 = elt(env, 2); /* "<pi/>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v25;
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for inszzz */

static Lisp_Object CC_inszzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inszzz");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v29;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v145;

v145:
    v84 = stack[-1];
    if (v84 == nil) goto v149;
    v84 = stack[-1];
    v84 = qcar(v84);
    v72 = qcar(v84);
    v84 = stack[-2];
    v84 = qcar(v84);
    v84 = (Lisp_Object)lessp2(v72, v84);
    nil = C_nil;
    if (exception_pending()) goto v260;
    v84 = v84 ? lisp_true : nil;
    env = stack[-4];
    if (!(v84 == nil)) goto v149;
    v84 = stack[-1];
    v84 = qcar(v84);
    v72 = qcar(v84);
    v84 = stack[-2];
    v84 = qcar(v84);
    if (equal(v72, v84)) goto v37;
    v84 = stack[-1];
    v72 = qcar(v84);
    v84 = stack[-3];
    v84 = cons(v72, v84);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[-3] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v145;

v37:
    v84 = stack[-1];
    v84 = qcar(v84);
    stack[0] = qcdr(v84);
    v84 = stack[-1];
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v72 = qcar(v84);
    v84 = stack[-2];
    v84 = qcdr(v84);
    v84 = qcar(v84);
    fn = elt(env, 1); /* dm!-plus */
    v84 = (*qfn2(fn))(qenv(fn), v72, v84);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v84 = Lrplaca(nil, stack[0], v84);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v84 = stack[-1];
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v84 = qcar(v84);
    fn = elt(env, 2); /* zeropp */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    if (v84 == nil) goto v238;
    v72 = stack[-3];
    v84 = stack[-1];
    v84 = qcdr(v84);
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v72, v84);
    }

v238:
    v72 = stack[-3];
    v84 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v72, v84);
    }

v149:
    stack[0] = stack[-3];
    v72 = stack[-2];
    v84 = stack[-1];
    v84 = cons(v72, v84);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    {
        Lisp_Object v261 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v261, v84);
    }
/* error exit handlers */
v260:
    popv(5);
    return nil;
}



/* Code for specrd!:plus */

static Lisp_Object CC_specrdTplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v304, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for specrd:plus");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */
    v304 = (Lisp_Object)1; /* 0 */
    stack[-2] = v304;
    v304 = stack[-1];
    fn = elt(env, 3); /* add_minus */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-3];
    stack[-1] = v304;
    v304 = stack[0];
    fn = elt(env, 3); /* add_minus */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-3];
    stack[0] = v304;
    v192 = stack[-1];
    v304 = elt(env, 1); /* minus */
    if (!consp(v192)) goto v15;
    v192 = qcar(v192);
    if (!(v192 == v304)) goto v15;
    v304 = stack[-1];
    v304 = qcdr(v304);
    v304 = qcar(v304);
    stack[-1] = v304;
    v304 = (Lisp_Object)17; /* 1 */
    stack[-2] = v304;
    goto v15;

v15:
    v192 = stack[0];
    v304 = elt(env, 1); /* minus */
    if (!consp(v192)) goto v110;
    v192 = qcar(v192);
    if (!(v192 == v304)) goto v110;
    v304 = stack[0];
    v304 = qcdr(v304);
    v304 = qcar(v304);
    stack[0] = v304;
    v192 = stack[-2];
    v304 = (Lisp_Object)33; /* 2 */
    v304 = plus2(v192, v304);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-3];
    stack[-2] = v304;
    goto v110;

v110:
    v304 = stack[-1];
    if (!(!consp(v304))) goto v1;
    v304 = stack[-1];
    v304 = Lfloat(nil, v304);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-3];
    v192 = v304;
    if (!(!consp(v192))) goto v32;
    v192 = elt(env, 2); /* !:rd!: */
    v304 = cons(v192, v304);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-3];
    goto v32;

v32:
    stack[-1] = v304;
    goto v1;

v1:
    v304 = stack[0];
    if (!(!consp(v304))) goto v152;
    v304 = stack[0];
    v304 = Lfloat(nil, v304);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-3];
    v192 = v304;
    if (!(!consp(v192))) goto v210;
    v192 = elt(env, 2); /* !:rd!: */
    v304 = cons(v192, v304);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-3];
    goto v210;

v210:
    stack[0] = v304;
    goto v152;

v152:
    v192 = stack[-2];
    v304 = (Lisp_Object)1; /* 0 */
    if (v192 == v304) goto v99;
    v192 = stack[-2];
    v304 = (Lisp_Object)49; /* 3 */
    if (v192 == v304) goto v155;
    v192 = stack[-2];
    v304 = (Lisp_Object)33; /* 2 */
    if (v192 == v304) goto v94;
    v192 = stack[0];
    v304 = stack[-1];
    {
        popv(4);
        fn = elt(env, 4); /* rd!:difference */
        return (*qfn2(fn))(qenv(fn), v192, v304);
    }

v94:
    v192 = stack[-1];
    v304 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* rd!:difference */
        return (*qfn2(fn))(qenv(fn), v192, v304);
    }

v155:
    stack[-2] = elt(env, 1); /* minus */
    v192 = stack[-1];
    v304 = stack[0];
    fn = elt(env, 5); /* rd!:plus */
    v304 = (*qfn2(fn))(qenv(fn), v192, v304);
    nil = C_nil;
    if (exception_pending()) goto v298;
    {
        Lisp_Object v305 = stack[-2];
        popv(4);
        return list2(v305, v304);
    }

v99:
    v192 = stack[-1];
    v304 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* rd!:plus */
        return (*qfn2(fn))(qenv(fn), v192, v304);
    }
/* error exit handlers */
v298:
    popv(4);
    return nil;
}



setup_type const u29_setup[] =
{
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {"clean_numid",             CC_clean_numid, too_many_1,    wrong_no_1},
    {"orddf",                   too_few_2,      CC_orddf,      wrong_no_2},
    {"mk+mat+plus+mat",         too_few_2,      CC_mkLmatLplusLmat,wrong_no_2},
    {"semanticml",              CC_semanticml,  too_many_1,    wrong_no_1},
    {"alg_plus",                too_few_2,      CC_alg_plus,   wrong_no_2},
    {"crn:zerop",               CC_crnTzerop,   too_many_1,    wrong_no_1},
    {"findelem2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_findelem2},
    {"size_of_matrix",          CC_size_of_matrix,too_many_1,  wrong_no_1},
    {"memqcar",                 too_few_2,      CC_memqcar,    wrong_no_2},
    {"r2findindex1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2findindex1},
    {"quoteequation",           CC_quoteequation,too_many_1,   wrong_no_1},
    {"statep",                  CC_statep,      too_many_1,    wrong_no_1},
    {"color-roads",             too_few_2,      CC_colorKroads,wrong_no_2},
    {"formbool",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formbool},
    {"getavalue",               CC_getavalue,   too_many_1,    wrong_no_1},
    {"msolve-polyn",            too_few_2,      CC_msolveKpolyn,wrong_no_2},
    {"basic-kern",              CC_basicKkern,  too_many_1,    wrong_no_1},
    {"cl_nnf",                  CC_cl_nnf,      too_many_1,    wrong_no_1},
    {"containerml",             too_few_2,      CC_containerml,wrong_no_2},
    {"f2dip1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip1},
    {"mkupf",                   CC_mkupf,       too_many_1,    wrong_no_1},
    {"getphystypeall",          CC_getphystypeall,too_many_1,  wrong_no_1},
    {"fs:make-nullangle",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTmakeKnullangle},
    {"mo_2a",                   CC_mo_2a,       too_many_1,    wrong_no_1},
    {"msolve-poly1",            too_few_2,      CC_msolveKpoly1,wrong_no_2},
    {"cl_pnf",                  CC_cl_pnf,      too_many_1,    wrong_no_1},
    {"ofsf_smordtable",         too_few_2,      CC_ofsf_smordtable,wrong_no_2},
    {"aex_xtothen",             too_few_2,      CC_aex_xtothen,wrong_no_2},
    {"dip_moncomp",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_dip_moncomp},
    {"matrix_rows",             CC_matrix_rows, too_many_1,    wrong_no_1},
    {"ps:times-erule",          too_few_2,      CC_psTtimesKerule,wrong_no_2},
    {"look_for_substitute",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_substitute},
    {"init",                    CC_init,        too_many_1,    wrong_no_1},
    {"get:const",               too_few_2,      CC_getTconst,  wrong_no_2},
    {"nspaces",                 CC_nspaces,     too_many_1,    wrong_no_1},
    {"collectphysops",          CC_collectphysops,too_many_1,  wrong_no_1},
    {"extadd",                  too_few_2,      CC_extadd,     wrong_no_2},
    {"processpartitie1list1",   too_few_2,      CC_processpartitie1list1,wrong_no_2},
    {"omatpir",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_omatpir},
    {"f4",                      CC_f4,          too_many_1,    wrong_no_1},
    {"inszzz",                  too_few_2,      CC_inszzz,     wrong_no_2},
    {"specrd:plus",             too_few_2,      CC_specrdTplus,wrong_no_2},
    {NULL, (one_args *)"u29", (two_args *)"17457 5135420 309567", 0}
};

/* end of generated code */
