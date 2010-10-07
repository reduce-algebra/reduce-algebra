
/* $destdir\u24.c        Machine generated C code */

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


/* Code for cl_apply2ats1 */

static Lisp_Object MS_CDECL CC_cl_apply2ats1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_apply2ats1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_apply2ats1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    stack[-5] = v1;
    stack[-1] = v0;
/* end of prologue */
    v64 = stack[-1];
    if (!consp(v64)) goto v67;
    v64 = stack[-1];
    v64 = qcar(v64);
    goto v68;

v68:
    v66 = v64;
    v65 = v66;
    v64 = elt(env, 1); /* true */
    if (v65 == v64) { Lisp_Object res = stack[-1]; popv(8); return onevalue(res); }
    v65 = v66;
    v64 = elt(env, 2); /* false */
    if (v65 == v64) { Lisp_Object res = stack[-1]; popv(8); return onevalue(res); }
    v65 = v66;
    v64 = elt(env, 3); /* ex */
    if (v65 == v64) goto v69;
    v65 = v66;
    v64 = elt(env, 4); /* all */
    if (v65 == v64) goto v69;
    v65 = v66;
    v64 = elt(env, 5); /* bex */
    if (v65 == v64) goto v70;
    v65 = v66;
    v64 = elt(env, 6); /* ball */
    if (v65 == v64) goto v70;
    v65 = v66;
    v64 = elt(env, 7); /* or */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 8); /* and */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 9); /* not */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 10); /* impl */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 11); /* repl */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 12); /* equiv */
    if (v65 == v64) goto v71;
    stack[0] = stack[-5];
    v65 = stack[-1];
    v64 = stack[-4];
    v64 = cons(v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    {
        Lisp_Object v73 = stack[0];
        popv(8);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v73, v64);
    }

v71:
    stack[-6] = v66;
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-3] = v64;
    v64 = stack[-3];
    if (v64 == nil) goto v74;
    v64 = stack[-3];
    v64 = qcar(v64);
    v66 = v64;
    v65 = stack[-5];
    v64 = stack[-4];
    v64 = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    stack[-1] = v64;
    stack[-2] = v64;
    goto v75;

v75:
    v64 = stack[-3];
    v64 = qcdr(v64);
    stack[-3] = v64;
    v64 = stack[-3];
    if (v64 == nil) goto v76;
    stack[0] = stack[-1];
    v64 = stack[-3];
    v64 = qcar(v64);
    v66 = v64;
    v65 = stack[-5];
    v64 = stack[-4];
    v64 = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = Lrplacd(nil, stack[0], v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-1] = v64;
    goto v75;

v76:
    v64 = stack[-2];
    goto v77;

v77:
    {
        Lisp_Object v78 = stack[-6];
        popv(8);
        return cons(v78, v64);
    }

v74:
    v64 = qvalue(elt(env, 13)); /* nil */
    goto v77;

v70:
    stack[-3] = v66;
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-2] = qcar(v64);
    v64 = stack[-1];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v66 = qcar(v64);
    v65 = stack[-5];
    v64 = stack[-4];
    stack[0] = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = stack[-1];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v66 = qcar(v64);
    v65 = stack[-5];
    v64 = stack[-4];
    v64 = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    {
        Lisp_Object v79 = stack[-3];
        Lisp_Object v80 = stack[-2];
        Lisp_Object v81 = stack[0];
        popv(8);
        return list4(v79, v80, v81, v64);
    }

v69:
    stack[-2] = v66;
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[0] = qcar(v64);
    v64 = stack[-1];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v66 = qcar(v64);
    v65 = stack[-5];
    v64 = stack[-4];
    v64 = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    {
        Lisp_Object v82 = stack[-2];
        Lisp_Object v83 = stack[0];
        popv(8);
        return list3(v82, v83, v64);
    }

v67:
    v64 = stack[-1];
    goto v68;
/* error exit handlers */
v72:
    popv(8);
    return nil;
}



/* Code for aex_freeids */

static Lisp_Object CC_aex_freeids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_freeids");
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
    v85 = stack[0];
    fn = elt(env, 1); /* aex_ex */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    fn = elt(env, 2); /* ratpoly_idl */
    stack[-1] = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v85 = stack[0];
    fn = elt(env, 3); /* aex_ctx */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    fn = elt(env, 4); /* ctx_idl */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    {
        Lisp_Object v87 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* lto_setminus */
        return (*qfn2(fn))(qenv(fn), v87, v85);
    }
/* error exit handlers */
v86:
    popv(3);
    return nil;
}



/* Code for ps!:value */

static Lisp_Object CC_psTvalue(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v58, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:value");
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
    v58 = v0;
/* end of prologue */
    v92 = v58;
    if (!consp(v92)) goto v22;
    v92 = v58;
    v57 = qcar(v92);
    v92 = elt(env, 1); /* !:ps!: */
    if (v57 == v92) goto v93;
    v92 = v58;
    v57 = qcar(v92);
    v92 = elt(env, 2); /* dname */
    v92 = get(v57, v92);
    env = stack[0];
    if (!(v92 == nil)) goto v22;

v93:
    v92 = (Lisp_Object)65; /* 4 */
    {
        popv(1);
        fn = elt(env, 3); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v58, v92);
    }

v22:
    v92 = v58;
    if (!(v92 == nil)) { popv(1); return onevalue(v58); }
    v92 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v92); }
}



/* Code for rootextractsq */

static Lisp_Object CC_rootextractsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootextractsq");
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
    v62 = v0;
/* end of prologue */
    v90 = v62;
    v90 = qcar(v90);
    if (v90 == nil) { popv(3); return onevalue(v62); }
    v90 = v62;
    fn = elt(env, 1); /* subs2q */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    stack[-1] = v90;
    v90 = stack[-1];
    v90 = qcar(v90);
    fn = elt(env, 2); /* rootextractf */
    stack[0] = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    v90 = stack[-1];
    v90 = qcdr(v90);
    fn = elt(env, 2); /* rootextractf */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v97;
    {
        Lisp_Object v98 = stack[0];
        popv(3);
        return cons(v98, v90);
    }
/* error exit handlers */
v97:
    popv(3);
    return nil;
}



/* Code for getdec */

static Lisp_Object CC_getdec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getdec");
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
    v101 = qvalue(elt(env, 1)); /* nil */
    v100 = stack[0];
    fn = elt(env, 2); /* symtabget */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v101 = v100;
    v100 = v101;
    if (!(v100 == nil)) { popv(2); return onevalue(v101); }
    v100 = stack[0];
    fn = elt(env, 3); /* implicitdec */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v101 = v100;
    { popv(2); return onevalue(v101); }
/* error exit handlers */
v102:
    popv(2);
    return nil;
}



/* Code for groebsavelterm */

static Lisp_Object CC_groebsavelterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsavelterm");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v94 = v0;
/* end of prologue */
    v101 = qvalue(elt(env, 1)); /* !*groelterms */
    if (v101 == nil) goto v103;
    v101 = v94;
    if (v101 == nil) goto v103;
    v101 = v94;
    v101 = qcdr(v101);
    v101 = qcdr(v101);
    v101 = qcdr(v101);
    v101 = qcar(v101);
    if (v101 == nil) goto v103;
    v101 = v94;
    v101 = qcdr(v101);
    v101 = qcdr(v101);
    v101 = qcar(v101);
    {
        fn = elt(env, 2); /* groebsaveltermbc */
        return (*qfn1(fn))(qenv(fn), v101);
    }

v103:
    v101 = nil;
    return onevalue(v101);
}



/* Code for coordp */

static Lisp_Object CC_coordp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v84;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v0;
/* end of prologue */
    v84 = qvalue(elt(env, 1)); /* coord!* */
    v104 = Lmemq(nil, v104, v84);
    return onevalue(v104);
}



/* Code for l!-subst */

static Lisp_Object MS_CDECL CC_lKsubst(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v57, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "l-subst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for l-subst");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v107 = nil;
    goto v63;

v63:
    v58 = stack[0];
    if (v58 == nil) goto v104;
    v57 = stack[-1];
    v58 = stack[0];
    v58 = qcar(v58);
    if (equal(v57, v58)) goto v90;
    v58 = stack[0];
    v58 = qcar(v58);
    v57 = v107;
    v58 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    v107 = v58;
    v58 = stack[0];
    v58 = qcdr(v58);
    stack[0] = v58;
    goto v63;

v90:
    v58 = stack[-2];
    v57 = v107;
    v58 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    v107 = v58;
    v58 = stack[0];
    v58 = qcdr(v58);
    stack[0] = v58;
    goto v63;

v104:
    v58 = v107;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v58);
    }
/* error exit handlers */
v108:
    popv(4);
    return nil;
}



/* Code for comm1 */

static Lisp_Object CC_comm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm1");
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
    v54 = stack[0];
    v115 = elt(env, 1); /* end */
    if (!(v54 == v115)) goto v94;

v116:
    fn = elt(env, 10); /* scan */
    v115 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    goto v94;

v94:
    v54 = qvalue(elt(env, 2)); /* cursym!* */
    v115 = elt(env, 3); /* !*semicol!* */
    if (v54 == v115) goto v95;
    v54 = stack[0];
    v115 = elt(env, 1); /* end */
    if (!(v54 == v115)) goto v118;
    v54 = qvalue(elt(env, 2)); /* cursym!* */
    v115 = elt(env, 4); /* (end else then until !*rpar!* !*rsqbkt!*) */
    v115 = Lmemq(nil, v54, v115);
    if (!(v115 == nil)) goto v95;

v118:
    v54 = stack[0];
    v115 = elt(env, 1); /* end */
    if (!(v54 == v115)) goto v116;
    v115 = stack[-1];
    if (!(v115 == nil)) goto v116;
    v115 = qvalue(elt(env, 6)); /* !*msg */
    if (v115 == nil) goto v119;
    stack[-1] = elt(env, 7); /* "***" */
    v115 = elt(env, 8); /* "END-COMMENT NO LONGER SUPPORTED" */
    v115 = ncons(v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    fn = elt(env, 11); /* lpriw */
    v115 = (*qfn2(fn))(qenv(fn), stack[-1], v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    goto v119;

v119:
    v115 = qvalue(elt(env, 9)); /* t */
    stack[-1] = v115;
    goto v116;

v95:
    v115 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v115); }
/* error exit handlers */
v117:
    popv(3);
    return nil;
}



/* Code for dfprintfn */

static Lisp_Object CC_dfprintfn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v58, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfprintfn");
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
    v92 = v0;
/* end of prologue */
    v58 = qvalue(elt(env, 1)); /* !*nat */
    if (v58 == nil) goto v22;
    v58 = qvalue(elt(env, 2)); /* !*fort */
    if (!(v58 == nil)) goto v22;
    v58 = qvalue(elt(env, 3)); /* !*dfprint */
    if (v58 == nil) goto v22;
    v58 = elt(env, 5); /* !!df!! */
    v92 = qcdr(v92);
    v57 = cons(v58, v92);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[0];
    v58 = (Lisp_Object)1; /* 0 */
    v92 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 7); /* layout!-formula */
    v92 = (*qfnn(fn))(qenv(fn), 3, v57, v58, v92);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[0];
    v58 = v92;
    v92 = v58;
    if (v92 == nil) goto v122;
    v92 = v58;
    fn = elt(env, 8); /* putpline */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v107;
    v92 = nil;
    { popv(1); return onevalue(v92); }

v122:
    v92 = elt(env, 4); /* failed */
    { popv(1); return onevalue(v92); }

v22:
    v92 = elt(env, 4); /* failed */
    { popv(1); return onevalue(v92); }
/* error exit handlers */
v107:
    popv(1);
    return nil;
}



/* Code for ratn */

static Lisp_Object CC_ratn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v108, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratn");
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
    v126 = v0;
/* end of prologue */
    v125 = v126;
    if (v125 == nil) goto v68;
    v125 = v126;
    if (!consp(v125)) goto v127;
    v125 = v126;
    v108 = qcar(v125);
    v125 = elt(env, 1); /* !:rn!: */
    if (v108 == v125) goto v90;
    v125 = elt(env, 2); /* "Illegal domain in :ar:" */
    v108 = v125;
    v125 = v108;
    qvalue(elt(env, 3)) = v125; /* errmsg!* */
    v125 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v125 == nil)) goto v89;
    v125 = v108;
    fn = elt(env, 5); /* lprie */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[0];
    goto v89;

v89:
    v125 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v56;
    v125 = nil;
    { popv(1); return onevalue(v125); }

v90:
    v125 = v126;
    v125 = qcdr(v125);
    { popv(1); return onevalue(v125); }

v127:
    v108 = v126;
    v125 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v108, v125);

v68:
    v108 = (Lisp_Object)1; /* 0 */
    v125 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v108, v125);
/* error exit handlers */
v56:
    popv(1);
    return nil;
}



/* Code for subsublis */

static Lisp_Object CC_subsublis(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v157, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsublis");
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
    stack[0] = v1;
    stack[-3] = v0;
/* end of prologue */

v104:
    v157 = stack[0];
    v156 = stack[-3];
    v156 = Lassoc(nil, v157, v156);
    v157 = v156;
    if (v156 == nil) goto v102;
    v156 = v157;
    v156 = qcdr(v156);
    { popv(6); return onevalue(v156); }

v102:
    v157 = stack[0];
    v156 = elt(env, 1); /* sqrt */
    if (!consp(v157)) goto v100;
    v157 = qcar(v157);
    if (!(v157 == v156)) goto v100;
    v158 = elt(env, 2); /* expt */
    v156 = stack[0];
    v156 = qcdr(v156);
    v157 = qcar(v156);
    v156 = elt(env, 3); /* (quotient 1 2) */
    v157 = list3(v158, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = stack[-3];
    v156 = Lassoc(nil, v157, v156);
    v157 = v156;
    if (v156 == nil) goto v100;
    v156 = v157;
    v156 = qcdr(v156);
    { popv(6); return onevalue(v156); }

v100:
    v156 = stack[0];
    if (!consp(v156)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v156 = stack[0];
    v156 = qcar(v156);
    if (symbolp(v156)) goto v159;
    v156 = stack[0];
    stack[-4] = v156;
    v156 = stack[-4];
    if (v156 == nil) goto v160;
    v156 = stack[-4];
    v156 = qcar(v156);
    v157 = stack[-3];
    v156 = CC_subsublis(env, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    stack[-1] = v156;
    stack[-2] = v156;
    goto v161;

v161:
    v156 = stack[-4];
    v156 = qcdr(v156);
    stack[-4] = v156;
    v156 = stack[-4];
    if (v156 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v156 = stack[-4];
    v156 = qcar(v156);
    v157 = stack[-3];
    v156 = CC_subsublis(env, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = Lrplacd(nil, stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = stack[-1];
    v156 = qcdr(v156);
    stack[-1] = v156;
    goto v161;

v160:
    v156 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v156); }

v159:
    v156 = stack[0];
    v157 = qcar(v156);
    v156 = elt(env, 5); /* subfunc */
    v156 = get(v157, v156);
    env = stack[-5];
    v157 = v156;
    if (v156 == nil) goto v162;
    v158 = v157;
    v157 = stack[-3];
    v156 = stack[0];
        popv(6);
        return Lapply2(nil, 3, v158, v157, v156);

v162:
    v156 = stack[0];
    v157 = qcar(v156);
    v156 = elt(env, 6); /* dname */
    v156 = get(v157, v156);
    env = stack[-5];
    if (!(v156 == nil)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v156 = stack[0];
    v157 = qcar(v156);
    v156 = elt(env, 7); /* !*sq */
    if (v157 == v156) goto v163;
    v156 = stack[0];
    stack[-4] = v156;
    v156 = stack[-4];
    if (v156 == nil) goto v164;
    v156 = stack[-4];
    v156 = qcar(v156);
    v157 = stack[-3];
    v156 = CC_subsublis(env, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    stack[-1] = v156;
    stack[-2] = v156;
    goto v165;

v165:
    v156 = stack[-4];
    v156 = qcdr(v156);
    stack[-4] = v156;
    v156 = stack[-4];
    if (v156 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v156 = stack[-4];
    v156 = qcar(v156);
    v157 = stack[-3];
    v156 = CC_subsublis(env, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = Lrplacd(nil, stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v156 = stack[-1];
    v156 = qcdr(v156);
    stack[-1] = v156;
    goto v165;

v164:
    v156 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v156); }

v163:
    stack[-1] = stack[-3];
    v156 = stack[0];
    v156 = qcdr(v156);
    v156 = qcar(v156);
    v156 = qcar(v156);
    if (v156 == nil) goto v166;
    v156 = stack[0];
    v156 = qcdr(v156);
    v157 = qcar(v156);
    v156 = elt(env, 8); /* prepf */
    fn = elt(env, 9); /* sqform */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    goto v167;

v167:
    stack[-3] = stack[-1];
    stack[0] = v156;
    goto v104;

v166:
    v156 = (Lisp_Object)1; /* 0 */
    goto v167;
/* error exit handlers */
v10:
    popv(6);
    return nil;
}



/* Code for wureducedp */

static Lisp_Object CC_wureducedp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wureducedp");
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
    v123 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    if (!(v123 == nil)) { popv(3); return onevalue(v123); }
    v123 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    if (!(v123 == nil)) { popv(3); return onevalue(v123); }
    v123 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    if (v123 == nil) goto v98;
    v123 = qvalue(elt(env, 1)); /* nil */
    goto v100;

v100:
    fn = elt(env, 3); /* deginvar */
    v93 = (*qfn2(fn))(qenv(fn), stack[-1], v123);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v123 = stack[0];
    v123 = qcar(v123);
    v123 = qcar(v123);
    v123 = qcdr(v123);
        popv(3);
        return Llessp(nil, v93, v123);

v98:
    v123 = stack[0];
    v123 = qcar(v123);
    v123 = qcar(v123);
    v123 = qcar(v123);
    goto v100;
/* error exit handlers */
v88:
    popv(3);
    return nil;
}



/* Code for ratpoly_quot */

static Lisp_Object CC_ratpoly_quot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_quot");
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
    push(nil);
/* copy arguments values to proper place */
    v99 = v1;
    v96 = v0;
/* end of prologue */
    stack[0] = v96;
    fn = elt(env, 1); /* invsq */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-1];
    {
        Lisp_Object v91 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v91, v99);
    }
/* error exit handlers */
v120:
    popv(2);
    return nil;
}



/* Code for cgp_mk */

static Lisp_Object MS_CDECL CC_cgp_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v144,
                         Lisp_Object v22, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v106, v169, v121;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "cgp_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_mk");
#endif
    if (stack >= stacklimit)
    {
        push5(v22,v144,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v144,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v97 = v22;
    v98 = v144;
    v106 = v2;
    v169 = v1;
    v121 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* cgp */
    stack[-1] = v121;
    stack[0] = v169;
    v97 = list3(v106, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v113;
    {
        Lisp_Object v122 = stack[-2];
        Lisp_Object v168 = stack[-1];
        Lisp_Object v123 = stack[0];
        popv(3);
        return list3star(v122, v168, v123, v97);
    }
/* error exit handlers */
v113:
    popv(3);
    return nil;
}



/* Code for unaryir */

static Lisp_Object CC_unaryir(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unaryir");
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
    v168 = qvalue(elt(env, 1)); /* atts */
    v122 = elt(env, 2); /* name */
    fn = elt(env, 4); /* find */
    v122 = (*qfn2(fn))(qenv(fn), v168, v122);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-3];
    v122 = Lintern(nil, v122);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-3];
    stack[-2] = v122;
    v168 = qvalue(elt(env, 1)); /* atts */
    v122 = elt(env, 3); /* cd */
    fn = elt(env, 4); /* find */
    v122 = (*qfn2(fn))(qenv(fn), v168, v122);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-3];
    v122 = Lintern(nil, v122);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-3];
    v168 = v122;
    v122 = stack[-1];
    if (equal(v168, v122)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v122 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* encodeir */
        return (*qfn1(fn))(qenv(fn), v122);
    }
/* error exit handlers */
v105:
    popv(4);
    return nil;
}



/* Code for ps!:depvar */

static Lisp_Object CC_psTdepvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v168, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:depvar");
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
    v168 = v0;
/* end of prologue */
    v122 = v168;
    if (!consp(v122)) goto v22;
    v122 = v168;
    v123 = qcar(v122);
    v122 = elt(env, 1); /* !:ps!: */
    if (v123 == v122) goto v121;
    v122 = v168;
    v123 = qcar(v122);
    v122 = elt(env, 2); /* dname */
    v122 = get(v123, v122);
    env = stack[0];
    if (!(v122 == nil)) goto v22;

v121:
    v122 = (Lisp_Object)33; /* 2 */
    {
        popv(1);
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v168, v122);
    }

v22:
    v122 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v122); }
}



/* Code for matsm1 */

static Lisp_Object CC_matsm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v257, v258;
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
    goto v68;

v68:
    v256 = stack[-8];
    if (v256 == nil) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v256 = stack[-8];
    v257 = qcar(v256);
    v256 = elt(env, 1); /* !*div */
    if (!consp(v257)) goto v102;
    v257 = qcar(v257);
    if (!(v257 == v256)) goto v102;
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    v256 = qcar(v256);
    fn = elt(env, 20); /* matsm */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-2] = v256;
    v256 = stack[-2];
    v256 = qcar(v256);
    stack[0] = Llength(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-1] = stack[0];
    v256 = stack[-2];
    v256 = Llength(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    if (equal(stack[0], v256)) goto v260;
    v256 = elt(env, 11); /* "Non square matrix" */
    v257 = v256;
    v256 = v257;
    qvalue(elt(env, 7)) = v256; /* errmsg!* */
    v256 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v256 == nil)) goto v261;
    v256 = v257;
    fn = elt(env, 21); /* lprie */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v261;

v261:
    v256 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v262;

v262:
    v256 = qvalue(elt(env, 12)); /* subfg!* */
    stack[0] = v256;
    v256 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 12)) = v256; /* subfg!* */
    v256 = stack[-9];
    if (v256 == nil) goto v263;
    v257 = elt(env, 2); /* mat */
    v256 = elt(env, 14); /* lnrsolvefn */
    v256 = get(v257, v256);
    env = stack[-10];
    stack[0] = v256;
    if (v256 == nil) goto v264;
    v257 = elt(env, 2); /* mat */
    v256 = elt(env, 14); /* lnrsolvefn */
    v258 = get(v257, v256);
    env = stack[-10];
    v257 = stack[-2];
    v256 = stack[-9];
    v256 = Lapply2(nil, 3, v258, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-9] = v256;
    goto v265;

v265:
    v256 = stack[0];
    qvalue(elt(env, 12)) = v256; /* subfg!* */
    v256 = stack[-9];
    stack[-7] = v256;
    v256 = stack[-7];
    if (v256 == nil) goto v266;
    v256 = stack[-7];
    v256 = qcar(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v267;
    v256 = stack[-3];
    v256 = qcar(v256);
    v257 = v256;
    v256 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 16)) = v256; /* !*sub2 */
    v256 = v257;
    fn = elt(env, 22); /* subs2 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-1] = v256;
    stack[-2] = v256;
    goto v268;

v268:
    v256 = stack[-3];
    v256 = qcdr(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v269;
    stack[0] = stack[-1];
    v256 = stack[-3];
    v256 = qcar(v256);
    v257 = v256;
    v256 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 16)) = v256; /* !*sub2 */
    v256 = v257;
    fn = elt(env, 22); /* subs2 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v268;

v269:
    v256 = stack[-2];
    goto v270;

v270:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-5] = v256;
    stack[-6] = v256;
    goto v271;

v271:
    v256 = stack[-7];
    v256 = qcdr(v256);
    stack[-7] = v256;
    v256 = stack[-7];
    if (v256 == nil) goto v272;
    stack[-4] = stack[-5];
    v256 = stack[-7];
    v256 = qcar(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v273;
    v256 = stack[-3];
    v256 = qcar(v256);
    v257 = v256;
    v256 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 16)) = v256; /* !*sub2 */
    v256 = v257;
    fn = elt(env, 22); /* subs2 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-1] = v256;
    stack[-2] = v256;
    goto v274;

v274:
    v256 = stack[-3];
    v256 = qcdr(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v275;
    stack[0] = stack[-1];
    v256 = stack[-3];
    v256 = qcar(v256);
    v257 = v256;
    v256 = qvalue(elt(env, 15)); /* t */
    qvalue(elt(env, 16)) = v256; /* !*sub2 */
    v256 = v257;
    fn = elt(env, 22); /* subs2 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v274;

v275:
    v256 = stack[-2];
    goto v276;

v276:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[-4], v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = stack[-5];
    v256 = qcdr(v256);
    stack[-5] = v256;
    goto v271;

v273:
    v256 = qvalue(elt(env, 5)); /* nil */
    goto v276;

v272:
    v256 = stack[-6];
    goto v277;

v277:
    stack[-9] = v256;
    goto v104;

v104:
    v256 = stack[-8];
    v256 = qcdr(v256);
    stack[-8] = v256;
    goto v68;

v267:
    v256 = qvalue(elt(env, 5)); /* nil */
    goto v270;

v266:
    v256 = qvalue(elt(env, 5)); /* nil */
    goto v277;

v264:
    v257 = elt(env, 2); /* mat */
    v256 = elt(env, 13); /* inversefn */
    v257 = get(v257, v256);
    env = stack[-10];
    v256 = stack[-2];
    v257 = Lapply1(nil, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = stack[-9];
    fn = elt(env, 23); /* multm */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-9] = v256;
    goto v265;

v263:
    v257 = elt(env, 2); /* mat */
    v256 = elt(env, 13); /* inversefn */
    v257 = get(v257, v256);
    env = stack[-10];
    v256 = stack[-2];
    v256 = Lapply1(nil, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-9] = v256;
    goto v265;

v260:
    v256 = stack[-9];
    if (v256 == nil) goto v278;
    stack[0] = stack[-1];
    v256 = stack[-9];
    v256 = Llength(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    if (equal(stack[0], v256)) goto v278;
    v256 = elt(env, 9); /* "Matrix mismatch" */
    v257 = v256;
    v256 = v257;
    qvalue(elt(env, 7)) = v256; /* errmsg!* */
    v256 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v256 == nil)) goto v279;
    v256 = v257;
    fn = elt(env, 21); /* lprie */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v279;

v279:
    v256 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v262;

v278:
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    if (v256 == nil) goto v280;
    v256 = stack[-9];
    if (!(v256 == nil)) goto v104;
    v256 = stack[-1];
    fn = elt(env, 24); /* generateident */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-9] = v256;
    goto v104;

v280:
    v256 = stack[-2];
    v256 = qcdr(v256);
    if (!(v256 == nil)) goto v262;
    v256 = stack[-2];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    if (!(v256 == nil)) goto v262;
    v256 = stack[-2];
    v256 = qcar(v256);
    v256 = qcar(v256);
    v256 = qcar(v256);
    if (!(v256 == nil)) goto v281;
    v256 = elt(env, 17); /* "Zero divisor" */
    v257 = v256;
    v256 = v257;
    qvalue(elt(env, 7)) = v256; /* errmsg!* */
    v256 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v256 == nil)) goto v282;
    v256 = v257;
    fn = elt(env, 21); /* lprie */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v282;

v282:
    v256 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v281;

v281:
    v256 = stack[-2];
    v256 = qcar(v256);
    v256 = qcar(v256);
    v257 = qcdr(v256);
    v256 = stack[-2];
    v256 = qcar(v256);
    v256 = qcar(v256);
    v256 = qcar(v256);
    v256 = cons(v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-2] = v256;
    v256 = stack[-9];
    if (v256 == nil) goto v283;
    v257 = stack[-2];
    v256 = stack[-9];
    fn = elt(env, 25); /* multsm */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v284;

v284:
    stack[-9] = v256;
    goto v104;

v283:
    v256 = stack[-2];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v284;

v102:
    v256 = stack[-8];
    v256 = qcar(v256);
    if (!consp(v256)) goto v285;
    v256 = stack[-8];
    v256 = qcar(v256);
    v257 = qcar(v256);
    v256 = elt(env, 2); /* mat */
    if (v257 == v256) goto v84;
    v256 = stack[-8];
    v256 = qcar(v256);
    v257 = qcar(v256);
    v256 = elt(env, 3); /* matmapfn */
    v256 = Lflagp(nil, v257, v256);
    env = stack[-10];
    if (v256 == nil) goto v286;
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    if (v256 == nil) goto v286;
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    v256 = qcar(v256);
    fn = elt(env, 26); /* getrtype */
    v257 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = elt(env, 4); /* matrix */
    if (!(v257 == v256)) goto v286;
    v256 = stack[-8];
    v257 = qcar(v256);
    v256 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 27); /* matrixmap */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    fn = elt(env, 20); /* matsm */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[0] = v256;
    goto v67;

v67:
    v256 = stack[-9];
    if (v256 == nil) goto v287;
    v256 = stack[-9];
    v256 = qcdr(v256);
    if (!(v256 == nil)) goto v30;
    v256 = stack[-9];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    if (!(v256 == nil)) goto v30;
    v256 = stack[-9];
    v256 = qcar(v256);
    v257 = qcar(v256);
    v256 = stack[0];
    fn = elt(env, 25); /* multsm */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v140;

v140:
    stack[-9] = v256;
    goto v104;

v30:
    v257 = stack[0];
    v256 = stack[-9];
    fn = elt(env, 23); /* multm */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v140;

v287:
    v256 = stack[0];
    goto v140;

v286:
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcar(v256);
    if (!consp(v256)) goto v288;
    v257 = elt(env, 6); /* "Apply called with non-id arg" */
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcar(v256);
    v256 = list2(v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v257 = v256;
    v256 = v257;
    qvalue(elt(env, 7)) = v256; /* errmsg!* */
    v256 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v256 == nil)) goto v148;
    v256 = v257;
    fn = elt(env, 21); /* lprie */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v148;

v148:
    v256 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = nil;
    goto v289;

v289:
    stack[0] = v256;
    v257 = stack[0];
    v256 = elt(env, 2); /* mat */
    if (!consp(v257)) goto v67;
    v257 = qcar(v257);
    if (!(v257 == v256)) goto v67;
    v256 = stack[0];
    fn = elt(env, 20); /* matsm */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[0] = v256;
    goto v67;

v288:
    v256 = stack[-8];
    v256 = qcar(v256);
    v257 = qcar(v256);
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    fn = elt(env, 28); /* apply */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v289;

v84:
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    fn = elt(env, 29); /* lchk */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    if (!(v256 == nil)) goto v27;
    v256 = elt(env, 9); /* "Matrix mismatch" */
    v257 = v256;
    v256 = v257;
    qvalue(elt(env, 7)) = v256; /* errmsg!* */
    v256 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v256 == nil)) goto v290;
    v256 = v257;
    fn = elt(env, 21); /* lprie */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v290;

v290:
    v256 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v27;

v27:
    v256 = stack[-8];
    v256 = qcar(v256);
    v256 = qcdr(v256);
    stack[-7] = v256;
    v256 = stack[-7];
    if (v256 == nil) goto v291;
    v256 = stack[-7];
    v256 = qcar(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v132;
    v256 = stack[-3];
    v256 = qcar(v256);
    fn = elt(env, 30); /* simp!* */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v257 = v256;
    v256 = qvalue(elt(env, 10)); /* !*exp */
    if (v256 == nil) goto v292;
    v256 = v257;
    goto v156;

v156:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-1] = v256;
    stack[-2] = v256;
    goto v128;

v128:
    v256 = stack[-3];
    v256 = qcdr(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v293;
    stack[0] = stack[-1];
    v256 = stack[-3];
    v256 = qcar(v256);
    fn = elt(env, 30); /* simp!* */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v257 = v256;
    v256 = qvalue(elt(env, 10)); /* !*exp */
    if (v256 == nil) goto v294;
    v256 = v257;
    goto v4;

v4:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v128;

v294:
    v256 = v257;
    fn = elt(env, 31); /* offexpchk */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v4;

v293:
    v256 = stack[-2];
    goto v295;

v295:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-5] = v256;
    stack[-6] = v256;
    goto v17;

v17:
    v256 = stack[-7];
    v256 = qcdr(v256);
    stack[-7] = v256;
    v256 = stack[-7];
    if (v256 == nil) goto v296;
    stack[-4] = stack[-5];
    v256 = stack[-7];
    v256 = qcar(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v297;
    v256 = stack[-3];
    v256 = qcar(v256);
    fn = elt(env, 30); /* simp!* */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v257 = v256;
    v256 = qvalue(elt(env, 10)); /* !*exp */
    if (v256 == nil) goto v298;
    v256 = v257;
    goto v299;

v299:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    stack[-1] = v256;
    stack[-2] = v256;
    goto v300;

v300:
    v256 = stack[-3];
    v256 = qcdr(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v301;
    stack[0] = stack[-1];
    v256 = stack[-3];
    v256 = qcar(v256);
    fn = elt(env, 30); /* simp!* */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v257 = v256;
    v256 = qvalue(elt(env, 10)); /* !*exp */
    if (v256 == nil) goto v302;
    v256 = v257;
    goto v303;

v303:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v300;

v302:
    v256 = v257;
    fn = elt(env, 31); /* offexpchk */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v303;

v301:
    v256 = stack[-2];
    goto v304;

v304:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[-4], v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v256 = stack[-5];
    v256 = qcdr(v256);
    stack[-5] = v256;
    goto v17;

v298:
    v256 = v257;
    fn = elt(env, 31); /* offexpchk */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v299;

v297:
    v256 = qvalue(elt(env, 5)); /* nil */
    goto v304;

v296:
    v256 = stack[-6];
    goto v15;

v15:
    stack[0] = v256;
    goto v67;

v292:
    v256 = v257;
    fn = elt(env, 31); /* offexpchk */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v156;

v132:
    v256 = qvalue(elt(env, 5)); /* nil */
    goto v295;

v291:
    v256 = qvalue(elt(env, 5)); /* nil */
    goto v15;

v285:
    v258 = elt(env, 18); /* "Matrix" */
    v256 = stack[-8];
    v257 = qcar(v256);
    v256 = elt(env, 19); /* "not set" */
    v256 = list3(v258, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    v257 = v256;
    v256 = v257;
    qvalue(elt(env, 7)) = v256; /* errmsg!* */
    v256 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v256 == nil)) goto v305;
    v256 = v257;
    fn = elt(env, 21); /* lprie */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-10];
    goto v305;

v305:
    v256 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v259;
    v256 = nil;
    { popv(11); return onevalue(v256); }
/* error exit handlers */
v259:
    popv(11);
    return nil;
}



/* Code for unify */

static Lisp_Object MS_CDECL CC_unify(Lisp_Object env, int nargs,
                         Lisp_Object v144, Lisp_Object v22,
                         Lisp_Object v103, Lisp_Object v116,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v8, v15, v17, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "unify");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unify");
#endif
    if (stack >= stacklimit)
    {
        push5(v63,v116,v103,v22,v144);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v144,v22,v103,v116,v63);
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
    stack[-13] = v63;
    stack[-14] = v116;
    v8 = v103;
    v15 = v22;
    v230 = v144;
/* end of prologue */
    stack[-15] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-12] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-11] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v230; /* op */
    v230 = v15;
    qvalue(elt(env, 2)) = v230; /* r */
    v230 = v8;
    qvalue(elt(env, 3)) = v230; /* p */
    v230 = qvalue(elt(env, 2)); /* r */
    if (!(v230 == nil)) goto v95;
    v230 = qvalue(elt(env, 3)); /* p */
    if (!(v230 == nil)) goto v95;
    v8 = stack[-14];
    v230 = stack[-13];
    fn = elt(env, 14); /* resume */
    v230 = (*qfn2(fn))(qenv(fn), v8, v230);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-16];
    goto v96;

v96:
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    { popv(17); return onevalue(v230); }

v95:
    v230 = qvalue(elt(env, 2)); /* r */
    if (v230 == nil) goto v169;
    v230 = qvalue(elt(env, 3)); /* p */
    if (!(v230 == nil)) goto v108;
    v230 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 15); /* ident */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-16];
    if (!(v230 == nil)) goto v108;
    v230 = qvalue(elt(env, 2)); /* r */
    v230 = qcar(v230);
    fn = elt(env, 16); /* mgenp */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-16];
    if (!(v230 == nil)) goto v108;
    v230 = qvalue(elt(env, 5)); /* nil */
    goto v96;

v108:
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
    v230 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v230; /* i */
    v230 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 13)) = v230; /* upb */
    v230 = qvalue(elt(env, 2)); /* r */
    v230 = qcar(v230);
    fn = elt(env, 17); /* pm!:free */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    if (v230 == nil) goto v249;
    v230 = qvalue(elt(env, 2)); /* r */
    v230 = qcar(v230);
    fn = elt(env, 18); /* genp */
    v8 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    v230 = stack[-14];
    v230 = cons(v8, v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    stack[-14] = v230;
    goto v249;

v249:
    v230 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 19); /* initarg */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    goto v314;

v314:
    v230 = stack[0];
    if (!(v230 == nil)) goto v289;
    v230 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 20); /* nextarg */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    stack[-9] = v230;
    if (v230 == nil) goto v289;
    v230 = qvalue(elt(env, 2)); /* r */
    v230 = qcar(v230);
    if (!consp(v230)) goto v315;
    v16 = qvalue(elt(env, 1)); /* op */
    v17 = qvalue(elt(env, 2)); /* r */
    v15 = stack[-9];
    v8 = stack[-14];
    v230 = stack[-13];
    fn = elt(env, 21); /* suspend */
    v230 = (*qfnn(fn))(qenv(fn), 5, v16, v17, v15, v8, v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    stack[0] = v230;
    goto v314;

v315:
    v230 = qvalue(elt(env, 2)); /* r */
    v230 = qcar(v230);
    fn = elt(env, 17); /* pm!:free */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    if (v230 == nil) goto v316;
    v230 = qvalue(elt(env, 2)); /* r */
    v8 = qcar(v230);
    v230 = stack[-9];
    v230 = qcar(v230);
    fn = elt(env, 22); /* bind */
    v230 = (*qfn2(fn))(qenv(fn), v8, v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    v230 = stack[-14];
    fn = elt(env, 23); /* chk */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    stack[-10] = v230;
    if (v230 == nil) goto v40;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v230 = qvalue(elt(env, 2)); /* r */
    v230 = qcdr(v230);
    fn = elt(env, 24); /* mval */
    v17 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    v230 = stack[-9];
    v15 = qcdr(v230);
    v8 = stack[-10];
    v230 = stack[-13];
    v230 = CC_unify(env, 5, stack[0], v17, v15, v8, v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    stack[0] = v230;
    goto v40;

v40:
    v230 = qvalue(elt(env, 2)); /* r */
    v230 = qcar(v230);
    fn = elt(env, 25); /* unbind */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    goto v314;

v316:
    v230 = qvalue(elt(env, 2)); /* r */
    v8 = qcar(v230);
    v230 = stack[-9];
    v230 = qcar(v230);
    fn = elt(env, 26); /* meq */
    v230 = (*qfn2(fn))(qenv(fn), v8, v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    if (v230 == nil) goto v314;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v230 = qvalue(elt(env, 2)); /* r */
    v230 = qcdr(v230);
    fn = elt(env, 24); /* mval */
    v17 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    v230 = stack[-9];
    v15 = qcdr(v230);
    v8 = stack[-14];
    v230 = stack[-13];
    v230 = CC_unify(env, 5, stack[0], v17, v15, v8, v230);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-16];
    stack[0] = v230;
    goto v314;

v289:
    v230 = stack[0];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    goto v96;

v169:
    v230 = elt(env, 4); /* "UNIFY:pattern over-run for function " */
    v230 = Lprinc(nil, v230);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-16];
    v230 = qvalue(elt(env, 1)); /* op */
    v230 = Lprint(nil, v230);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-16];
    v230 = qvalue(elt(env, 5)); /* nil */
    goto v96;
/* error exit handlers */
v128:
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
v295:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
}



/* Code for vdpvevlcomp */

static Lisp_Object CC_vdpvevlcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpvevlcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v127 = v1;
    v95 = v0;
/* end of prologue */
    v95 = qcdr(v95);
    v95 = qcdr(v95);
    v95 = qcdr(v95);
    v95 = qcar(v95);
    v127 = qcdr(v127);
    v127 = qcdr(v127);
    v127 = qcdr(v127);
    v127 = qcar(v127);
    {
        fn = elt(env, 1); /* dipevlcomp */
        return (*qfn2(fn))(qenv(fn), v95, v127);
    }
}



/* Code for mkfortterpri */

static Lisp_Object MS_CDECL CC_mkfortterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkfortterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkfortterpri");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v144 = elt(env, 1); /* fortterpri */
    return ncons(v144);
}



/* Code for indordn */

static Lisp_Object CC_indordn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v317;
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
    v317 = v0;
/* end of prologue */
    v93 = v317;
    if (v93 == nil) goto v22;
    v93 = v317;
    v93 = qcdr(v93);
    if (v93 == nil) { popv(2); return onevalue(v317); }
    v93 = v317;
    v93 = qcdr(v93);
    v93 = qcdr(v93);
    if (v93 == nil) goto v127;
    v93 = v317;
    stack[0] = qcar(v93);
    v93 = v317;
    v93 = qcdr(v93);
    v93 = CC_indordn(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-1];
    {
        Lisp_Object v89 = stack[0];
        popv(2);
        fn = elt(env, 2); /* indordad */
        return (*qfn2(fn))(qenv(fn), v89, v93);
    }

v127:
    v93 = v317;
    v93 = qcar(v93);
    v317 = qcdr(v317);
    v317 = qcar(v317);
    {
        popv(2);
        fn = elt(env, 3); /* indord2 */
        return (*qfn2(fn))(qenv(fn), v93, v317);
    }

v22:
    v93 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v93); }
/* error exit handlers */
v88:
    popv(2);
    return nil;
}



/* Code for fieldconv */

static Lisp_Object CC_fieldconv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v292, v333, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fieldconv");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v292 = stack[-1];
    v292 = qcar(v292);
    stack[-3] = v292;
    v292 = stack[-1];
    v292 = qcdr(v292);
    stack[0] = v292;
    v292 = qvalue(elt(env, 1)); /* dmode!* */
    if (v292 == nil) goto v101;
    v292 = stack[0];
    if (!consp(v292)) goto v334;
    v292 = stack[0];
    v292 = qcar(v292);
    if (!consp(v292)) goto v334;
    v333 = stack[-3];
    v292 = stack[-2];
    fn = elt(env, 12); /* divd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v333 = stack[0];
    v292 = stack[-2];
    fn = elt(env, 12); /* divd */
    v292 = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    {
        Lisp_Object v293 = stack[-1];
        popv(5);
        return cons(v293, v292);
    }

v334:
    v333 = stack[-3];
    v292 = stack[0];
    fn = elt(env, 12); /* divd */
    v333 = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    v292 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v333, v292);

v101:
    v333 = stack[-2];
    v292 = elt(env, 2); /* !:rn!: */
    if (!consp(v333)) goto v60;
    v333 = qcar(v333);
    if (!(v333 == v292)) goto v60;

v336:
    v292 = stack[-2];
    v9 = qcar(v292);
    v292 = stack[-2];
    v292 = qcdr(v292);
    v333 = qcdr(v292);
    v292 = stack[-2];
    v292 = qcdr(v292);
    v292 = qcar(v292);
    v292 = list2star(v9, v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    stack[-2] = v292;
    v292 = stack[0];
    if (!consp(v292)) goto v241;
    v292 = stack[0];
    v292 = qcar(v292);
    if (!consp(v292)) goto v241;
    v333 = stack[-2];
    v292 = stack[-3];
    fn = elt(env, 13); /* multd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v333 = stack[-2];
    v292 = stack[0];
    fn = elt(env, 13); /* multd */
    v292 = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v292 = cons(stack[-1], v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    goto v337;

v337:
    {
        popv(5);
        fn = elt(env, 14); /* simpgd */
        return (*qfn1(fn))(qenv(fn), v292);
    }

v241:
    v333 = stack[-2];
    v292 = stack[-3];
    fn = elt(env, 13); /* multd */
    v333 = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v292 = (Lisp_Object)17; /* 1 */
    v292 = cons(v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    goto v337;

v60:
    v292 = stack[-2];
    v333 = qcar(v292);
    v292 = elt(env, 2); /* !:rn!: */
    v292 = get(v333, v292);
    env = stack[-4];
    v333 = v292;
    if (v292 == nil) goto v56;
    v292 = v333;
    if (!(!consp(v292))) goto v56;
    v292 = stack[-2];
    v292 = Lapply1(nil, v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    stack[-2] = v292;
    goto v336;

v56:
    v292 = stack[-2];
    v333 = qcar(v292);
    v292 = elt(env, 3); /* quotient */
    v292 = get(v333, v292);
    env = stack[-4];
    if (v292 == nil) goto v338;
    v9 = (Lisp_Object)17; /* 1 */
    v333 = stack[-2];
    v292 = elt(env, 3); /* quotient */
    fn = elt(env, 15); /* dcombine */
    v292 = (*qfnn(fn))(qenv(fn), 3, v9, v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    stack[-2] = v292;
    v333 = stack[-2];
    v292 = stack[-1];
    v292 = qcar(v292);
    fn = elt(env, 13); /* multd */
    stack[0] = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v333 = stack[-2];
    v292 = stack[-1];
    v292 = qcdr(v292);
    fn = elt(env, 13); /* multd */
    v292 = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    {
        Lisp_Object v339 = stack[0];
        popv(5);
        return cons(v339, v292);
    }

v338:
    v292 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 16); /* terpri!* */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v292 = elt(env, 5); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 17); /* lprie */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v333 = elt(env, 6); /* "field conversion" */
    v292 = stack[-2];
    v292 = list2(v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    fn = elt(env, 18); /* printty */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v333 = elt(env, 7); /* " " */
    v292 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 19); /* lpriw */
    v292 = (*qfn2(fn))(qenv(fn), v333, v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v292 = elt(env, 9); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v333 = v292;
    v292 = v333;
    qvalue(elt(env, 10)) = v292; /* errmsg!* */
    v292 = qvalue(elt(env, 11)); /* !*protfg */
    if (!(v292 == nil)) goto v42;
    v292 = v333;
    fn = elt(env, 17); /* lprie */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    goto v42;

v42:
    v292 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    goto v336;
/* error exit handlers */
v335:
    popv(5);
    return nil;
}



/* Code for groeb!=newpair */

static Lisp_Object MS_CDECL CC_groebMnewpair(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v57, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=newpair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=newpair");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-1] = v0;
/* end of prologue */
    v58 = stack[-3];
    fn = elt(env, 1); /* bas_dpoly */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    v58 = stack[-2];
    fn = elt(env, 1); /* bas_dpoly */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    fn = elt(env, 3); /* mo_lcm */
    v58 = (*qfn2(fn))(qenv(fn), stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    stack[0] = v58;
    stack[-4] = stack[-1];
    v107 = stack[0];
    v57 = stack[-3];
    v58 = stack[-2];
    fn = elt(env, 4); /* groeb!=weight */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v107, v57, v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    v57 = stack[-3];
    v58 = stack[-2];
    v58 = list2(v57, v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    {
        Lisp_Object v55 = stack[-4];
        Lisp_Object v111 = stack[-1];
        Lisp_Object v69 = stack[0];
        popv(6);
        return list3star(v55, v111, v69, v58);
    }
/* error exit handlers */
v56:
    popv(6);
    return nil;
}



/* Code for simp!-prop1 */

static Lisp_Object CC_simpKprop1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v378, v379, v380;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop1");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v381:
    v378 = stack[-4];
    if (!consp(v378)) goto v304;
    v378 = stack[-4];
    v379 = qcar(v378);
    v378 = qvalue(elt(env, 1)); /* !'and */
    if (!(equal(v379, v378))) goto v98;
    v378 = stack[-3];
    if (!(v378 == nil)) goto v120;

v98:
    v378 = stack[-4];
    v379 = qcar(v378);
    v378 = qvalue(elt(env, 2)); /* !'or */
    if (!(equal(v379, v378))) goto v154;
    v378 = stack[-3];
    if (!(v378 == nil)) goto v154;

v120:
    v378 = (Lisp_Object)17; /* 1 */
    stack[0] = v378;
    v378 = stack[-4];
    v378 = qcdr(v378);
    stack[-1] = v378;
    goto v88;

v88:
    v378 = stack[-1];
    if (v378 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v378 = stack[-1];
    v378 = qcar(v378);
    v379 = v378;
    v378 = stack[-3];
    v378 = CC_simpKprop1(env, v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    fn = elt(env, 18); /* multf */
    v378 = (*qfn2(fn))(qenv(fn), stack[0], v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    stack[0] = v378;
    v378 = stack[-1];
    v378 = qcdr(v378);
    stack[-1] = v378;
    goto v88;

v154:
    v378 = stack[-4];
    v379 = qcar(v378);
    v378 = qvalue(elt(env, 2)); /* !'or */
    if (!(equal(v379, v378))) goto v244;
    v378 = stack[-3];
    if (!(v378 == nil)) goto v331;

v244:
    v378 = stack[-4];
    v379 = qcar(v378);
    v378 = qvalue(elt(env, 1)); /* !'and */
    if (!(equal(v379, v378))) goto v142;
    v378 = stack[-3];
    if (!(v378 == nil)) goto v142;

v331:
    v378 = qvalue(elt(env, 3)); /* nil */
    stack[0] = v378;
    v378 = stack[-4];
    v378 = qcdr(v378);
    stack[-1] = v378;
    goto v383;

v383:
    v378 = stack[-1];
    if (v378 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v378 = stack[-1];
    v378 = qcar(v378);
    v379 = v378;
    v378 = stack[-3];
    v378 = CC_simpKprop1(env, v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    fn = elt(env, 19); /* addf */
    v378 = (*qfn2(fn))(qenv(fn), stack[0], v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    stack[0] = v378;
    v378 = stack[-1];
    v378 = qcdr(v378);
    stack[-1] = v378;
    goto v383;

v142:
    v378 = stack[-4];
    v379 = qcar(v378);
    v378 = elt(env, 4); /* not */
    if (v379 == v378) goto v41;
    v378 = stack[-4];
    v379 = qcar(v378);
    v378 = elt(env, 5); /* implies */
    if (v379 == v378) goto v323;
    v378 = stack[-4];
    v379 = qcar(v378);
    v378 = elt(env, 8); /* equiv */
    if (!(v379 == v378)) goto v63;
    stack[-5] = elt(env, 6); /* or */
    v380 = elt(env, 9); /* and */
    v378 = stack[-4];
    v378 = qcdr(v378);
    v379 = qcar(v378);
    v378 = stack[-4];
    v378 = qcdr(v378);
    v378 = qcdr(v378);
    v378 = qcar(v378);
    stack[-2] = list3(v380, v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    stack[-1] = elt(env, 9); /* and */
    v379 = elt(env, 4); /* not */
    v378 = stack[-4];
    v378 = qcdr(v378);
    v378 = qcar(v378);
    stack[0] = list2(v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v379 = elt(env, 4); /* not */
    v378 = stack[-4];
    v378 = qcdr(v378);
    v378 = qcdr(v378);
    v378 = qcar(v378);
    v378 = list2(v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v378 = list3(stack[-1], stack[0], v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v379 = list3(stack[-5], stack[-2], v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v378 = stack[-3];
    v378 = CC_simpKprop1(env, v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    stack[0] = v378;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v63:
    v378 = stack[-4];
    fn = elt(env, 20); /* reval */
    v378 = (*qfn1(fn))(qenv(fn), v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    stack[-4] = v378;
    v379 = stack[-4];
    v378 = elt(env, 14); /* boolean */
    if (!consp(v379)) goto v213;
    v379 = qcar(v379);
    if (!(v379 == v378)) goto v213;
    v378 = stack[-4];
    v378 = qcdr(v378);
    v379 = qcar(v378);
    v378 = stack[-3];
    stack[-4] = v379;
    stack[-3] = v378;
    goto v381;

v213:
    v378 = stack[-3];
    if (v378 == nil) goto v384;
    v378 = elt(env, 15); /* prop!* */
    v379 = v378;
    goto v385;

v385:
    v378 = stack[-4];
    v378 = list2(v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    fn = elt(env, 21); /* simp */
    v378 = (*qfn1(fn))(qenv(fn), v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v378 = qcar(v378);
    stack[0] = v378;
    v379 = stack[-4];
    v378 = qvalue(elt(env, 17)); /* propvars!* */
    v378 = Lmember(nil, v379, v378);
    if (!(v378 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v379 = stack[-4];
    v378 = qvalue(elt(env, 17)); /* propvars!* */
    v378 = cons(v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    qvalue(elt(env, 17)) = v378; /* propvars!* */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v384:
    v378 = elt(env, 16); /* not_prop!* */
    v379 = v378;
    goto v385;

v323:
    v378 = stack[-3];
    if (v378 == nil) goto v8;
    stack[0] = elt(env, 6); /* or */
    v379 = elt(env, 4); /* not */
    v378 = stack[-4];
    v378 = qcdr(v378);
    v378 = qcar(v378);
    v379 = list2(v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v378 = stack[-4];
    v378 = qcdr(v378);
    v378 = qcdr(v378);
    v378 = qcar(v378);
    v379 = list3(stack[0], v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v378 = qvalue(elt(env, 7)); /* t */
    v378 = CC_simpKprop1(env, v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    stack[0] = v378;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v8:
    stack[0] = elt(env, 6); /* or */
    v379 = elt(env, 4); /* not */
    v378 = stack[-4];
    v378 = qcdr(v378);
    v378 = qcdr(v378);
    v378 = qcar(v378);
    v379 = list2(v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v378 = stack[-4];
    v378 = qcdr(v378);
    v378 = qcar(v378);
    v379 = list3(stack[0], v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-6];
    v378 = qvalue(elt(env, 7)); /* t */
    v378 = CC_simpKprop1(env, v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    stack[0] = v378;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v41:
    v378 = stack[-4];
    v378 = qcdr(v378);
    v379 = qcar(v378);
    v378 = stack[-3];
    v378 = (v378 == nil ? lisp_true : nil);
    v378 = CC_simpKprop1(env, v379, v378);
    nil = C_nil;
    if (exception_pending()) goto v382;
    stack[0] = v378;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v304:
    v379 = stack[-4];
    v378 = (Lisp_Object)17; /* 1 */
    if (v379 == v378) goto v226;
    v379 = stack[-4];
    v378 = qvalue(elt(env, 7)); /* t */
    if (equal(v379, v378)) goto v226;
    v379 = stack[-4];
    v378 = elt(env, 10); /* true */
    if (v379 == v378) goto v226;
    v379 = stack[-4];
    v378 = (Lisp_Object)1; /* 0 */
    if (v379 == v378) goto v386;
    v378 = stack[-4];
    if (v378 == nil) goto v386;
    v379 = stack[-4];
    v378 = elt(env, 11); /* false */
    if (!(v379 == v378)) goto v387;

v386:
    v378 = stack[-3];
    v378 = (v378 == nil ? lisp_true : nil);
    stack[-4] = v378;
    goto v387;

v387:
    v379 = stack[-4];
    v378 = qvalue(elt(env, 7)); /* t */
    if (equal(v379, v378)) goto v388;
    v378 = stack[-4];
    if (!(v378 == nil)) goto v63;
    v379 = elt(env, 13); /* (and !*true (not !*true)) */
    v378 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v379;
    stack[-3] = v378;
    goto v381;

v388:
    v379 = elt(env, 12); /* (or !*true (not !*true)) */
    v378 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v379;
    stack[-3] = v378;
    goto v381;

v226:
    v378 = stack[-3];
    stack[-4] = v378;
    goto v387;
/* error exit handlers */
v382:
    popv(7);
    return nil;
}



/* Code for ad_splitname */

static Lisp_Object CC_ad_splitname(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v306;
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
    v306 = v0;
/* end of prologue */
    v150 = v306;
    if (symbolp(v150)) goto v22;
    v150 = nil;
    { popv(3); return onevalue(v150); }

v22:
    stack[0] = nil;
    v150 = v306;
    v150 = Lexplode(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v389;
    env = stack[-2];
    v150 = Lreverse(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v389;
    env = stack[-2];
    stack[-1] = v150;
    goto v91;

v91:
    v150 = stack[-1];
    if (v150 == nil) goto v120;
    v150 = stack[-1];
    v150 = qcar(v150);
    fn = elt(env, 2); /* charnump!: */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v389;
    env = stack[-2];
    if (v150 == nil) goto v120;
    v150 = stack[-1];
    v306 = qcar(v150);
    v150 = stack[0];
    v150 = cons(v306, v150);
    nil = C_nil;
    if (exception_pending()) goto v389;
    env = stack[-2];
    stack[0] = v150;
    v150 = stack[-1];
    v150 = qcdr(v150);
    stack[-1] = v150;
    goto v91;

v120:
    v150 = stack[-1];
    if (v150 == nil) goto v123;
    v150 = stack[-1];
    v150 = Lreverse(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v389;
    env = stack[-2];
    v150 = Lcompress(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v389;
    env = stack[-2];
    v150 = Lintern(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v389;
    env = stack[-2];
    stack[-1] = v150;
    goto v123;

v123:
    v150 = stack[0];
    if (v150 == nil) goto v55;
    v150 = stack[0];
    v150 = Lcompress(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v389;
    stack[0] = v150;
    goto v55;

v55:
    v306 = stack[-1];
    v150 = stack[0];
    popv(3);
    return cons(v306, v150);
/* error exit handlers */
v389:
    popv(3);
    return nil;
}



/* Code for bfrsq */

static Lisp_Object CC_bfrsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v251;
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
    v251 = v0;
/* end of prologue */
    v69 = v251;
    v69 = qcar(v69);
    v251 = qcdr(v251);
    stack[-1] = v251;
    v251 = v69;
    if (!consp(v251)) goto v95;
    v251 = v69;
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v251, v69);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v251 = stack[-1];
    v69 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v69 = (*qfn2(fn))(qenv(fn), v251, v69);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    {
        Lisp_Object v150 = stack[0];
        popv(3);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v150, v69);
    }

v95:
    v251 = v69;
    stack[0] = times2(v251, v69);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v251 = stack[-1];
    v69 = stack[-1];
    v69 = times2(v251, v69);
    nil = C_nil;
    if (exception_pending()) goto v151;
    {
        Lisp_Object v306 = stack[0];
        popv(3);
        return plus2(v306, v69);
    }
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for gen!+can!+bas */

static Lisp_Object CC_genLcanLbas(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v394;
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
    v394 = (Lisp_Object)17; /* 1 */
    v129 = (Lisp_Object)17; /* 1 */
    v129 = cons(v394, v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    stack[-10] = v129;
    v394 = qvalue(elt(env, 1)); /* nil */
    v129 = (Lisp_Object)17; /* 1 */
    v129 = cons(v394, v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    stack[-8] = v129;
    v129 = (Lisp_Object)17; /* 1 */
    stack[-7] = v129;
    v394 = stack[-9];
    v129 = stack[-7];
    v129 = difference2(v394, v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lminusp(nil, v129);
    env = stack[-11];
    if (v129 == nil) goto v169;
    v129 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v129); }

v169:
    v129 = (Lisp_Object)17; /* 1 */
    stack[-3] = v129;
    v394 = stack[-9];
    v129 = stack[-3];
    v129 = difference2(v394, v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lminusp(nil, v129);
    env = stack[-11];
    if (v129 == nil) goto v330;
    v129 = qvalue(elt(env, 1)); /* nil */
    goto v332;

v332:
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    stack[-5] = v129;
    stack[-6] = v129;
    goto v97;

v97:
    v129 = stack[-7];
    v129 = add1(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    stack[-7] = v129;
    v394 = stack[-9];
    v129 = stack[-7];
    v129 = difference2(v394, v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lminusp(nil, v129);
    env = stack[-11];
    if (!(v129 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    v129 = (Lisp_Object)17; /* 1 */
    stack[-3] = v129;
    v394 = stack[-9];
    v129 = stack[-3];
    v129 = difference2(v394, v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lminusp(nil, v129);
    env = stack[-11];
    if (v129 == nil) goto v30;
    v129 = qvalue(elt(env, 1)); /* nil */
    goto v371;

v371:
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lrplacd(nil, stack[-4], v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = stack[-5];
    v129 = qcdr(v129);
    stack[-5] = v129;
    goto v97;

v30:
    v394 = stack[-7];
    v129 = stack[-3];
    if (equal(v394, v129)) goto v395;
    v129 = stack[-8];
    goto v396;

v396:
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    stack[-1] = v129;
    stack[-2] = v129;
    goto v323;

v323:
    v129 = stack[-3];
    v129 = add1(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    stack[-3] = v129;
    v394 = stack[-9];
    v129 = stack[-3];
    v129 = difference2(v394, v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lminusp(nil, v129);
    env = stack[-11];
    if (v129 == nil) goto v71;
    v129 = stack[-2];
    goto v371;

v71:
    stack[0] = stack[-1];
    v394 = stack[-7];
    v129 = stack[-3];
    if (equal(v394, v129)) goto v7;
    v129 = stack[-8];
    goto v16;

v16:
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lrplacd(nil, stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v323;

v7:
    v129 = stack[-10];
    goto v16;

v395:
    v129 = stack[-10];
    goto v396;

v330:
    v394 = stack[-7];
    v129 = stack[-3];
    if (equal(v394, v129)) goto v160;
    v129 = stack[-8];
    goto v51;

v51:
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    stack[-1] = v129;
    stack[-2] = v129;
    goto v118;

v118:
    v129 = stack[-3];
    v129 = add1(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    stack[-3] = v129;
    v394 = stack[-9];
    v129 = stack[-3];
    v129 = difference2(v394, v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lminusp(nil, v129);
    env = stack[-11];
    if (v129 == nil) goto v147;
    v129 = stack[-2];
    goto v332;

v147:
    stack[0] = stack[-1];
    v394 = stack[-7];
    v129 = stack[-3];
    if (equal(v394, v129)) goto v397;
    v129 = stack[-8];
    goto v245;

v245:
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = Lrplacd(nil, stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-11];
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v118;

v397:
    v129 = stack[-10];
    goto v245;

v160:
    v129 = stack[-10];
    goto v51;
/* error exit handlers */
v238:
    popv(12);
    return nil;
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v121, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for carx");
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
/* copy arguments values to proper place */
    v121 = v1;
    v60 = v0;
/* end of prologue */
    v169 = v60;
    v169 = qcdr(v169);
    if (v169 == nil) goto v103;
    v169 = elt(env, 1); /* "Wrong number of arguments to" */
    v169 = list2(v169, v121);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[0];
    v121 = v169;
    v169 = v121;
    qvalue(elt(env, 2)) = v169; /* errmsg!* */
    v169 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v169 == nil)) goto v90;
    v169 = v121;
    fn = elt(env, 4); /* lprie */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[0];
    goto v90;

v90:
    v169 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    v169 = nil;
    { popv(1); return onevalue(v169); }

v103:
    v169 = v60;
    v169 = qcar(v169);
    { popv(1); return onevalue(v169); }
/* error exit handlers */
v59:
    popv(1);
    return nil;
}



/* Code for qqe_simplterm!-tail */

static Lisp_Object CC_qqe_simpltermKtail(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v398, v399, v288;
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
    v398 = stack[-2];
    fn = elt(env, 7); /* qqe_arg2l */
    v398 = (*qfn1(fn))(qenv(fn), v398);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-4];
    stack[-3] = v398;
    v399 = stack[-3];
    v398 = elt(env, 1); /* qepsilon */
    if (v399 == v398) goto v84;
    v398 = stack[-3];
    if (!consp(v398)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v398 = stack[-2];
    fn = elt(env, 8); /* qqe_op */
    v398 = (*qfn1(fn))(qenv(fn), v398);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-4];
    stack[-1] = v398;
    v398 = stack[-3];
    fn = elt(env, 8); /* qqe_op */
    v398 = (*qfn1(fn))(qenv(fn), v398);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-4];
    stack[0] = v398;
    v399 = stack[0];
    v398 = elt(env, 2); /* (ladd radd) */
    v398 = Lmemq(nil, v399, v398);
    if (v398 == nil) goto v97;
    v398 = stack[-3];
    fn = elt(env, 9); /* qqe_arg2r */
    v398 = (*qfn1(fn))(qenv(fn), v398);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-4];
    v288 = v398;
    v399 = v288;
    v398 = elt(env, 1); /* qepsilon */
    if (v399 == v398) goto v89;
    v399 = stack[-1];
    v398 = elt(env, 3); /* ltail */
    if (!(v399 == v398)) goto v154;
    v399 = stack[0];
    v398 = elt(env, 4); /* radd */
    if (v399 == v398) { popv(5); return onevalue(v288); }
    else goto v154;

v154:
    v399 = stack[-1];
    v398 = elt(env, 5); /* rtail */
    if (!(v399 == v398)) goto v97;
    v399 = stack[0];
    v398 = elt(env, 6); /* ladd */
    if (v399 == v398) { popv(5); return onevalue(v288); }
    else goto v97;

v97:
    v398 = stack[-3];
    fn = elt(env, 10); /* qqe_simplterm */
    v398 = (*qfn1(fn))(qenv(fn), v398);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-4];
    v288 = v398;
    v399 = v288;
    v398 = stack[-3];
    if (equal(v399, v398)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v398 = stack[-1];
    v399 = v288;
    v398 = list2(v398, v399);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 10); /* qqe_simplterm */
        return (*qfn1(fn))(qenv(fn), v398);
    }

v89:
    v398 = elt(env, 1); /* qepsilon */
    { popv(5); return onevalue(v398); }

v84:
    v398 = elt(env, 1); /* qepsilon */
    { popv(5); return onevalue(v398); }
/* error exit handlers */
v311:
    popv(5);
    return nil;
}



/* Code for fctrf1 */

static Lisp_Object CC_fctrf1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v401, v358, v14;
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
    v401 = stack[-3];
    if (!consp(v401)) goto v67;
    v401 = stack[-3];
    v401 = qcar(v401);
    if (!consp(v401)) goto v67;
    v358 = qvalue(elt(env, 1)); /* dmode!* */
    v401 = elt(env, 2); /* field */
    v401 = Lflagp(nil, v358, v401);
    env = stack[-5];
    if (v401 == nil) goto v100;
    v401 = stack[-3];
    fn = elt(env, 4); /* lnc */
    v358 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-1] = v358;
    v401 = (Lisp_Object)17; /* 1 */
    if (v358 == v401) goto v100;
    v401 = stack[-1];
    fn = elt(env, 5); /* !:recip */
    v358 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v401 = stack[-3];
    fn = elt(env, 6); /* multd */
    v401 = (*qfn2(fn))(qenv(fn), v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-3] = v401;
    goto v127;

v127:
    v401 = stack[-3];
    fn = elt(env, 7); /* comfac */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-4] = v401;
    stack[0] = stack[-3];
    v401 = stack[-4];
    v401 = qcar(v401);
    if (v401 == nil) goto v372;
    v401 = stack[-4];
    v401 = ncons(v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    goto v314;

v314:
    fn = elt(env, 8); /* quotf */
    v401 = (*qfn2(fn))(qenv(fn), stack[0], v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-3] = v401;
    v401 = stack[-4];
    v401 = qcdr(v401);
    v401 = CC_fctrf1(env, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-2] = v401;
    v401 = stack[-4];
    v401 = qcar(v401);
    if (v401 == nil) goto v403;
    v401 = stack[-2];
    stack[0] = qcar(v401);
    v401 = stack[-4];
    v401 = qcar(v401);
    v14 = qcar(v401);
    v358 = (Lisp_Object)17; /* 1 */
    v401 = (Lisp_Object)17; /* 1 */
    v401 = acons(v14, v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v358 = ncons(v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v401 = stack[-4];
    v401 = qcar(v401);
    v401 = qcdr(v401);
    v358 = cons(v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v401 = stack[-2];
    v401 = qcdr(v401);
    v401 = list2star(stack[0], v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-2] = v401;
    goto v403;

v403:
    v401 = stack[-1];
    if (v401 == nil) goto v325;
    v358 = stack[-1];
    v401 = (Lisp_Object)17; /* 1 */
    if (v358 == v401) goto v325;
    v358 = stack[-1];
    v401 = stack[-2];
    v401 = qcar(v401);
    fn = elt(env, 6); /* multd */
    v358 = (*qfn2(fn))(qenv(fn), v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v401 = stack[-2];
    v401 = qcdr(v401);
    v401 = cons(v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-2] = v401;
    goto v325;

v325:
    v401 = stack[-3];
    if (!consp(v401)) goto v290;
    v401 = stack[-3];
    v401 = qcar(v401);
    if (!consp(v401)) goto v290;
    v401 = stack[-3];
    fn = elt(env, 9); /* minusf */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    if (v401 == nil) goto v308;
    v401 = stack[-3];
    fn = elt(env, 10); /* negf */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-3] = v401;
    v401 = stack[-2];
    v401 = qcar(v401);
    fn = elt(env, 10); /* negf */
    v358 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v401 = stack[-2];
    v401 = qcdr(v401);
    v401 = cons(v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-2] = v401;
    goto v308;

v308:
    v401 = stack[-3];
    fn = elt(env, 11); /* factor!-prim!-f */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-1] = v401;
    v401 = stack[-1];
    v358 = qcar(v401);
    v401 = stack[-2];
    v401 = qcar(v401);
    fn = elt(env, 12); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v401 = stack[-1];
    v358 = qcdr(v401);
    v401 = stack[-2];
    v401 = qcdr(v401);
    v401 = Lappend(nil, v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    {
        Lisp_Object v404 = stack[0];
        popv(6);
        return cons(v404, v401);
    }

v290:
    v358 = stack[-3];
    v401 = stack[-2];
    v401 = qcar(v401);
    fn = elt(env, 12); /* multf */
    v358 = (*qfn2(fn))(qenv(fn), v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    v401 = stack[-2];
    v401 = qcdr(v401);
    popv(6);
    return cons(v358, v401);

v372:
    v401 = stack[-4];
    v401 = qcdr(v401);
    goto v314;

v100:
    v401 = qvalue(elt(env, 1)); /* dmode!* */
    if (v401 == nil) goto v127;
    v358 = qvalue(elt(env, 1)); /* dmode!* */
    v401 = elt(env, 3); /* unitsfn */
    v401 = get(v358, v401);
    env = stack[-5];
    stack[-2] = v401;
    if (v401 == nil) goto v127;
    stack[-1] = stack[-2];
    v358 = (Lisp_Object)17; /* 1 */
    v401 = stack[-3];
    stack[0] = cons(v358, v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v401 = stack[-3];
    fn = elt(env, 4); /* lnc */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    v401 = Lapply2(nil, 3, stack[-1], stack[0], v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-4] = v401;
    v401 = stack[-4];
    v401 = qcdr(v401);
    stack[-3] = v401;
    v401 = stack[-4];
    v401 = qcar(v401);
    fn = elt(env, 5); /* !:recip */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v402;
    env = stack[-5];
    stack[-1] = v401;
    goto v127;

v67:
    v401 = stack[-3];
    popv(6);
    return ncons(v401);
/* error exit handlers */
v402:
    popv(6);
    return nil;
}



/* Code for aex_boundids */

static Lisp_Object CC_aex_boundids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96;
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
    v96 = stack[0];
    fn = elt(env, 1); /* aex_ids */
    stack[-1] = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    v96 = stack[0];
    fn = elt(env, 2); /* aex_ctx */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    fn = elt(env, 3); /* ctx_idl */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    {
        Lisp_Object v86 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* intersection */
        return (*qfn2(fn))(qenv(fn), v86, v96);
    }
/* error exit handlers */
v91:
    popv(3);
    return nil;
}



setup_type const u24_setup[] =
{
    {"cl_apply2ats1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_apply2ats1},
    {"aex_freeids",             CC_aex_freeids, too_many_1,    wrong_no_1},
    {"ps:value",                CC_psTvalue,    too_many_1,    wrong_no_1},
    {"rootextractsq",           CC_rootextractsq,too_many_1,   wrong_no_1},
    {"getdec",                  CC_getdec,      too_many_1,    wrong_no_1},
    {"groebsavelterm",          CC_groebsavelterm,too_many_1,  wrong_no_1},
    {"coordp",                  CC_coordp,      too_many_1,    wrong_no_1},
    {"l-subst",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_lKsubst},
    {"comm1",                   CC_comm1,       too_many_1,    wrong_no_1},
    {"dfprintfn",               CC_dfprintfn,   too_many_1,    wrong_no_1},
    {"ratn",                    CC_ratn,        too_many_1,    wrong_no_1},
    {"subsublis",               too_few_2,      CC_subsublis,  wrong_no_2},
    {"wureducedp",              too_few_2,      CC_wureducedp, wrong_no_2},
    {"ratpoly_quot",            too_few_2,      CC_ratpoly_quot,wrong_no_2},
    {"cgp_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_cgp_mk},
    {"unaryir",                 too_few_2,      CC_unaryir,    wrong_no_2},
    {"ps:depvar",               CC_psTdepvar,   too_many_1,    wrong_no_1},
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
    {NULL, (one_args *)"u24", (two_args *)"21983 4608150 2039761", 0}
};

/* end of generated code */
