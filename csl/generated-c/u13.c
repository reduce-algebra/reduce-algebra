
/* $destdir\u13.c        Machine generated C code */

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


/* Code for all_edge */

static Lisp_Object CC_all_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_edge");
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
    v9 = nil;
    goto v10;

v10:
    v7 = stack[0];
    if (v7 == nil) goto v11;
    v8 = stack[-1];
    v7 = stack[0];
    v7 = qcar(v7);
    v7 = qcar(v7);
    if (v8 == v7) goto v12;
    v7 = stack[0];
    v7 = qcdr(v7);
    stack[0] = v7;
    goto v10;

v12:
    v7 = stack[0];
    v7 = qcar(v7);
    v8 = v9;
    v7 = cons(v7, v8);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    v9 = v7;
    v7 = stack[0];
    v7 = qcdr(v7);
    stack[0] = v7;
    goto v10;

v11:
    v7 = v9;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v7);
    }
/* error exit handlers */
v13:
    popv(3);
    return nil;
}



/* Code for red_better */

static Lisp_Object CC_red_better(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_better");
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
    v15 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bas_dplen */
    stack[-1] = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v15 = stack[0];
    fn = elt(env, 1); /* bas_dplen */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v16;
    {
        Lisp_Object v17 = stack[-1];
        popv(3);
        return Llessp(nil, v17, v15);
    }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for pv_times3 */

static Lisp_Object CC_pv_times3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times3");
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
    v21 = stack[-1];
    v22 = qcar(v21);
    v21 = stack[0];
    v21 = qcar(v21);
    stack[-2] = times2(v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v21 = stack[-1];
    v22 = qcdr(v21);
    v21 = stack[0];
    v21 = qcdr(v21);
    fn = elt(env, 1); /* pappend */
    v21 = (*qfn2(fn))(qenv(fn), v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v23;
    {
        Lisp_Object v24 = stack[-2];
        popv(4);
        return cons(v24, v21);
    }
/* error exit handlers */
v23:
    popv(4);
    return nil;
}



/* Code for pa_coinc_split */

static Lisp_Object CC_pa_coinc_split(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_coinc_split");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    stack[-6] = nil;
    v90 = stack[-9];
    v90 = qcdr(v90);
    fn = elt(env, 3); /* upbve */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-4] = v90;
    v90 = stack[-4];
    v90 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = Lmkvect(nil, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-10] = v90;
    v90 = stack[-4];
    v90 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = Lmkvect(nil, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-7] = v90;
    v90 = stack[-4];
    v90 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = Lmkvect(nil, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-5] = v90;
    v90 = (Lisp_Object)1; /* 0 */
    stack[-3] = v90;
    v90 = stack[-9];
    v90 = qcar(v90);
    stack[-2] = v90;
    goto v2;

v2:
    v90 = stack[-2];
    if (v90 == nil) goto v94;
    v90 = stack[-2];
    v90 = qcar(v90);
    stack[-1] = v90;
    v90 = stack[-3];
    v90 = add1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-3] = v90;
    stack[0] = stack[-10];
    v90 = stack[-1];
    v91 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v91/(16/CELL))) = v90;
    v90 = stack[-2];
    v90 = qcdr(v90);
    stack[-2] = v90;
    goto v2;

v94:
    v90 = (Lisp_Object)1; /* 0 */
    stack[-3] = v90;
    v90 = stack[-8];
    v90 = qcar(v90);
    stack[-2] = v90;
    goto v95;

v95:
    v90 = stack[-2];
    if (v90 == nil) goto v96;
    v90 = stack[-2];
    v90 = qcar(v90);
    stack[-1] = v90;
    v90 = stack[-3];
    v90 = add1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-3] = v90;
    stack[0] = stack[-7];
    v90 = stack[-1];
    v91 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v91/(16/CELL))) = v90;
    v90 = stack[-2];
    v90 = qcdr(v90);
    stack[-2] = v90;
    goto v95;

v96:
    v90 = (Lisp_Object)17; /* 1 */
    stack[-3] = v90;
    goto v97;

v97:
    v91 = stack[-4];
    v90 = stack[-3];
    v90 = difference2(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = Lminusp(nil, v90);
    env = stack[-11];
    if (v90 == nil) goto v98;
    v91 = stack[-6];
    v90 = elt(env, 2); /* lambda_l9xqtr_2 */
    fn = elt(env, 4); /* sort */
    v90 = (*qfn2(fn))(qenv(fn), v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-6] = v90;
    v90 = stack[-6];
    stack[-3] = v90;
    v90 = stack[-3];
    if (v90 == nil) goto v99;
    v90 = stack[-3];
    v90 = qcar(v90);
    v90 = qcdr(v90);
    v90 = qcar(v90);
    v90 = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-1] = v90;
    stack[-2] = v90;
    goto v100;

v100:
    v90 = stack[-3];
    v90 = qcdr(v90);
    stack[-3] = v90;
    v90 = stack[-3];
    if (v90 == nil) goto v101;
    stack[0] = stack[-1];
    v90 = stack[-3];
    v90 = qcar(v90);
    v90 = qcdr(v90);
    v90 = qcar(v90);
    v90 = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = Lrplacd(nil, stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = stack[-1];
    v90 = qcdr(v90);
    stack[-1] = v90;
    goto v100;

v101:
    v90 = stack[-2];
    v91 = v90;
    goto v102;

v102:
    v90 = stack[-5];
    v90 = cons(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-5] = v90;
    v90 = stack[-6];
    stack[-3] = v90;
    v90 = stack[-3];
    if (v90 == nil) goto v103;
    v90 = stack[-3];
    v90 = qcar(v90);
    v91 = v90;
    v91 = qcar(v91);
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = cons(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-1] = v90;
    stack[-2] = v90;
    goto v104;

v104:
    v90 = stack[-3];
    v90 = qcdr(v90);
    stack[-3] = v90;
    v90 = stack[-3];
    if (v90 == nil) goto v105;
    stack[0] = stack[-1];
    v90 = stack[-3];
    v90 = qcar(v90);
    v91 = v90;
    v91 = qcar(v91);
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = cons(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = Lrplacd(nil, stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = stack[-1];
    v90 = qcdr(v90);
    stack[-1] = v90;
    goto v104;

v105:
    v90 = stack[-2];
    goto v106;

v106:
    v91 = v90;
    v90 = stack[-5];
    popv(12);
    return cons(v91, v90);

v103:
    v90 = qvalue(elt(env, 1)); /* nil */
    goto v106;

v99:
    v90 = qvalue(elt(env, 1)); /* nil */
    v91 = v90;
    goto v102;

v98:
    stack[-1] = stack[-10];
    v90 = stack[-9];
    stack[0] = qcdr(v90);
    v90 = stack[-3];
    v90 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    v90 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-2] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    stack[-1] = stack[-7];
    v90 = stack[-8];
    stack[0] = qcdr(v90);
    v90 = stack[-3];
    v90 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    v90 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    v90 = cons(stack[-2], v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v92 = v90;
    v91 = v92;
    v90 = stack[-6];
    v90 = Lassoc(nil, v91, v90);
    stack[-1] = v90;
    if (v90 == nil) goto v107;
    v90 = stack[-1];
    stack[0] = qcdr(v90);
    v90 = stack[-1];
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = add1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = Lrplacd(nil, stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[0] = stack[-5];
    v90 = stack[-3];
    v91 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = stack[-1];
    v90 = qcdr(v90);
    v90 = qcar(v90);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v91/(16/CELL))) = v90;
    goto v108;

v108:
    v90 = stack[-3];
    v90 = add1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-3] = v90;
    goto v97;

v107:
    v91 = stack[-3];
    v90 = (Lisp_Object)17; /* 1 */
    v90 = list2star(v92, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-1] = v90;
    v91 = stack[-1];
    v90 = stack[-6];
    v90 = cons(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    stack[-6] = v90;
    stack[0] = stack[-5];
    v90 = stack[-3];
    v91 = sub1(v90);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-11];
    v90 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v91/(16/CELL))) = v90;
    goto v108;
/* error exit handlers */
v93:
    popv(12);
    return nil;
}



/* Code for lambda_l9xqtr_2 */

static Lisp_Object CC_lambda_l9xqtr_2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9xqtr_2");
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
    v111 = stack[-1];
    v111 = qcar(v111);
    v112 = qcar(v111);
    v111 = stack[0];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = (Lisp_Object)lessp2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v87;
    v111 = v111 ? lisp_true : nil;
    env = stack[-2];
    if (v111 == nil) goto v113;
    v111 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v111); }

v113:
    v111 = stack[0];
    v111 = qcar(v111);
    v112 = qcar(v111);
    v111 = stack[-1];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = (Lisp_Object)lessp2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v87;
    v111 = v111 ? lisp_true : nil;
    env = stack[-2];
    if (v111 == nil) goto v114;
    v111 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v111); }

v114:
    v111 = stack[-1];
    v111 = qcar(v111);
    v112 = qcdr(v111);
    v111 = stack[0];
    v111 = qcar(v111);
    v111 = qcdr(v111);
        popv(3);
        return Lleq(nil, v112, v111);
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for modquotient!: */

static Lisp_Object CC_modquotientT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modquotient:");
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
    v16 = v1;
    v110 = v0;
/* end of prologue */
    stack[0] = qcdr(v110);
    v110 = v16;
    v110 = qcdr(v110);
    fn = elt(env, 1); /* general!-modular!-reciprocal */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    fn = elt(env, 2); /* general!-modular!-times */
    v110 = (*qfn2(fn))(qenv(fn), stack[0], v110);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v110);
    }
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for general!-times!-mod!-p */

static Lisp_Object CC_generalKtimesKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-times-mod-p");
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
    v141 = stack[-2];
    if (v141 == nil) goto v59;
    v141 = stack[-1];
    if (v141 == nil) goto v59;
    v141 = stack[-2];
    if (!consp(v141)) goto v143;
    v141 = stack[-2];
    v141 = qcar(v141);
    if (!consp(v141)) goto v143;
    v141 = stack[-1];
    if (!consp(v141)) goto v24;
    v141 = stack[-1];
    v141 = qcar(v141);
    if (!consp(v141)) goto v24;
    v141 = stack[-2];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v142 = qcar(v141);
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = qcar(v141);
    if (equal(v142, v141)) goto v144;
    v141 = stack[-2];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v142 = qcar(v141);
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = qcar(v141);
    fn = elt(env, 2); /* ordop */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    if (v141 == nil) goto v72;
    v141 = stack[-2];
    v141 = qcar(v141);
    stack[-3] = qcar(v141);
    v141 = stack[-2];
    v141 = qcar(v141);
    v142 = qcdr(v141);
    v141 = stack[-1];
    stack[0] = CC_generalKtimesKmodKp(env, v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v141 = stack[-2];
    v142 = qcdr(v141);
    v141 = stack[-1];
    v141 = CC_generalKtimesKmodKp(env, v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    {
        Lisp_Object v62 = stack[-3];
        Lisp_Object v145 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v62, v145, v141);
    }

v72:
    v141 = stack[-1];
    v141 = qcar(v141);
    stack[-3] = qcar(v141);
    v142 = stack[-2];
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    stack[0] = CC_generalKtimesKmodKp(env, v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v142 = stack[-2];
    v141 = stack[-1];
    v141 = qcdr(v141);
    v141 = CC_generalKtimesKmodKp(env, v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    {
        Lisp_Object v146 = stack[-3];
        Lisp_Object v147 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v146, v147, v141);
    }

v144:
    v141 = stack[-2];
    v142 = qcar(v141);
    v141 = stack[-1];
    fn = elt(env, 4); /* general!-times!-term!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v141 = stack[-1];
    v142 = qcar(v141);
    v141 = stack[-2];
    v141 = qcdr(v141);
    fn = elt(env, 4); /* general!-times!-term!-mod!-p */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    fn = elt(env, 5); /* general!-plus!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v141 = stack[-2];
    v142 = qcdr(v141);
    v141 = stack[-1];
    v141 = qcdr(v141);
    v141 = CC_generalKtimesKmodKp(env, v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    {
        Lisp_Object v61 = stack[0];
        popv(5);
        fn = elt(env, 5); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v61, v141);
    }

v24:
    v142 = stack[-2];
    v141 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* gen!-mult!-by!-const!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v142, v141);
    }

v143:
    v142 = stack[-1];
    v141 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* gen!-mult!-by!-const!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v142, v141);
    }

v59:
    v141 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v141); }
/* error exit handlers */
v60:
    popv(5);
    return nil;
}



/* Code for qqe_simplterm */

static Lisp_Object CC_qqe_simplterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v152, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplterm");
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
    v88 = stack[0];
    if (!consp(v88)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v88 = stack[0];
    fn = elt(env, 4); /* qqe_op */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-1];
    v86 = v88;
    v152 = v86;
    v88 = elt(env, 1); /* (ltail rtail) */
    v88 = Lmemq(nil, v152, v88);
    if (v88 == nil) goto v21;
    v88 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* qqe_simplterm!-tail */
        return (*qfn1(fn))(qenv(fn), v88);
    }

v21:
    v152 = v86;
    v88 = elt(env, 2); /* (lhead rhead) */
    v88 = Lmemq(nil, v152, v88);
    if (v88 == nil) goto v8;
    v88 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* qqe_simplterm!-head */
        return (*qfn1(fn))(qenv(fn), v88);
    }

v8:
    v152 = v86;
    v88 = elt(env, 3); /* (ladd radd) */
    v88 = Lmemq(nil, v152, v88);
    if (v88 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v88 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* qqe_simplterm!-add */
        return (*qfn1(fn))(qenv(fn), v88);
    }
/* error exit handlers */
v153:
    popv(2);
    return nil;
}



/* Code for mkzl */

static Lisp_Object CC_mkzl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkzl");
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
    goto v83;

v83:
    v2 = stack[0];
    v94 = (Lisp_Object)17; /* 1 */
    if (v2 == v94) goto v27;
    v2 = (Lisp_Object)1; /* 0 */
    v94 = stack[-1];
    v94 = cons(v2, v94);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    stack[-1] = v94;
    v94 = stack[0];
    v94 = sub1(v94);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    stack[0] = v94;
    goto v83;

v27:
    v94 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v94);
    }
/* error exit handlers */
v24:
    popv(3);
    return nil;
}



/* Code for numpoly_nullp */

static Lisp_Object CC_numpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v110 = v0;
/* end of prologue */
    v16 = v110;
    v16 = (v16 == nil ? lisp_true : nil);
    if (!(v16 == nil)) return onevalue(v16);
    v16 = v110;
    v110 = (Lisp_Object)1; /* 0 */
    v110 = (v16 == v110 ? lisp_true : nil);
    return onevalue(v110);
}



/* Code for matrixrowrd */

static Lisp_Object MS_CDECL CC_matrixrowrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrowrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 2); /* mathml */
    v151 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-1];
    v113 = v151;
    v151 = v113;
    if (v151 == nil) goto v27;
    stack[0] = v113;
    v151 = CC_matrixrowrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v140;
    {
        Lisp_Object v12 = stack[0];
        popv(2);
        return cons(v12, v151);
    }

v27:
    v151 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v151); }
/* error exit handlers */
v140:
    popv(2);
    return nil;
}



/* Code for dipilcomb1 */

static Lisp_Object MS_CDECL CC_dipilcomb1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v150, Lisp_Object v4,
                         Lisp_Object v73, Lisp_Object v59, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v197, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "dipilcomb1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipilcomb1");
#endif
    if (stack >= stacklimit)
    {
        push6(v59,v73,v4,v150,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v150,v4,v73,v59);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v59;
    stack[-11] = v73;
    stack[-12] = v4;
    stack[-13] = v150;
    stack[-14] = v1;
    stack[-15] = v0;
/* end of prologue */
    v196 = qvalue(elt(env, 1)); /* !*gcd */
    stack[-1] = v196;
    stack[-16] = nil;
    stack[-9] = nil;
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v197 = stack[-14];
    v196 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (v196 == nil) goto v22;
    v197 = stack[-11];
    v196 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (v196 == nil) goto v22;
    v196 = stack[-1];
    goto v19;

v19:
    qvalue(elt(env, 1)) = v196; /* !*gcd */
    v196 = stack[-13];
    fn = elt(env, 5); /* evzero!? */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v196 = (v196 == nil ? lisp_true : nil);
    stack[-7] = v196;
    v196 = stack[-10];
    fn = elt(env, 5); /* evzero!? */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v196 = (v196 == nil ? lisp_true : nil);
    stack[-6] = v196;
    v196 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v196;
    stack[-5] = v196;
    v196 = qvalue(elt(env, 3)); /* nil */
    stack[-8] = v196;
    stack[-2] = v196;
    stack[-3] = v196;
    goto v12;

v12:
    v196 = stack[-5];
    if (v196 == nil) goto v200;
    v196 = stack[-15];
    if (v196 == nil) goto v201;
    v196 = stack[-15];
    v196 = qcar(v196);
    stack[-16] = v196;
    v196 = stack[-7];
    if (v196 == nil) goto v202;
    v197 = stack[-16];
    v196 = stack[-13];
    fn = elt(env, 6); /* evsum */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    stack[-16] = v196;
    goto v202;

v202:
    v196 = qvalue(elt(env, 3)); /* nil */
    stack[-5] = v196;
    goto v200;

v200:
    v196 = stack[-4];
    if (v196 == nil) goto v203;
    v196 = stack[-12];
    if (v196 == nil) goto v76;
    v196 = stack[-12];
    v196 = qcar(v196);
    stack[-9] = v196;
    v196 = stack[-6];
    if (v196 == nil) goto v204;
    v197 = stack[-9];
    v196 = stack[-10];
    fn = elt(env, 6); /* evsum */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    stack[-9] = v196;
    goto v204;

v204:
    v196 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v196;
    goto v203;

v203:
    v197 = stack[-16];
    v196 = stack[-9];
    fn = elt(env, 7); /* evcomp */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v198 = v196;
    v197 = v198;
    v196 = (Lisp_Object)17; /* 1 */
    if (v197 == v196) goto v205;
    v197 = v198;
    v196 = (Lisp_Object)-15; /* -1 */
    if (v197 == v196) goto v206;
    v196 = qvalue(elt(env, 1)); /* !*gcd */
    if (v196 == nil) goto v207;
    v196 = stack[-15];
    v196 = qcdr(v196);
    v197 = qcar(v196);
    v196 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (v196 == nil) goto v208;
    v196 = stack[-12];
    v196 = qcdr(v196);
    v197 = qcar(v196);
    v196 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (!(v196 == nil)) goto v207;

v208:
    v196 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v196; /* !*gcd */
    goto v207;

v207:
    v196 = stack[-15];
    v196 = qcdr(v196);
    v197 = qcar(v196);
    v196 = stack[-14];
    fn = elt(env, 8); /* bcprod */
    stack[-1] = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v196 = stack[-12];
    v196 = qcdr(v196);
    v197 = qcar(v196);
    v196 = stack[-11];
    fn = elt(env, 8); /* bcprod */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    fn = elt(env, 9); /* bcsum */
    v196 = (*qfn2(fn))(qenv(fn), stack[-1], v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    stack[-1] = v196;
    v196 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (!(v196 == nil)) goto v209;
    v198 = stack[-16];
    v197 = stack[-1];
    v196 = qvalue(elt(env, 3)); /* nil */
    v196 = list2star(v198, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v196 = Lnconc(nil, stack[-2], v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    stack[-3] = v196;
    v196 = stack[-3];
    v196 = qcdr(v196);
    v196 = qcdr(v196);
    stack[-2] = v196;
    goto v209;

v209:
    v196 = stack[-15];
    v196 = qcdr(v196);
    v196 = qcdr(v196);
    stack[-15] = v196;
    v196 = stack[-12];
    v196 = qcdr(v196);
    v196 = qcdr(v196);
    stack[-12] = v196;
    v196 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v196;
    stack[-5] = v196;
    goto v142;

v142:
    v196 = stack[-8];
    if (!(v196 == nil)) goto v12;
    v196 = stack[-3];
    stack[-2] = v196;
    stack[-8] = v196;
    goto v12;

v206:
    v196 = qvalue(elt(env, 1)); /* !*gcd */
    if (v196 == nil) goto v210;
    v196 = stack[-12];
    v196 = qcdr(v196);
    v197 = qcar(v196);
    v196 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (!(v196 == nil)) goto v210;
    v196 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v196; /* !*gcd */
    goto v210;

v210:
    v196 = stack[-12];
    v196 = qcdr(v196);
    v197 = qcar(v196);
    v196 = stack[-11];
    fn = elt(env, 8); /* bcprod */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    stack[-1] = v196;
    v196 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (!(v196 == nil)) goto v211;
    v198 = stack[-9];
    v197 = stack[-1];
    v196 = qvalue(elt(env, 3)); /* nil */
    v196 = list2star(v198, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v196 = Lnconc(nil, stack[-2], v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    stack[-3] = v196;
    v196 = stack[-3];
    v196 = qcdr(v196);
    v196 = qcdr(v196);
    stack[-2] = v196;
    goto v211;

v211:
    v196 = stack[-12];
    v196 = qcdr(v196);
    v196 = qcdr(v196);
    stack[-12] = v196;
    v196 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v196;
    goto v142;

v205:
    v196 = qvalue(elt(env, 1)); /* !*gcd */
    if (v196 == nil) goto v212;
    v196 = stack[-15];
    v196 = qcdr(v196);
    v197 = qcar(v196);
    v196 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (!(v196 == nil)) goto v212;
    v196 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v196; /* !*gcd */
    goto v212;

v212:
    v196 = stack[-15];
    v196 = qcdr(v196);
    v197 = qcar(v196);
    v196 = stack[-14];
    fn = elt(env, 8); /* bcprod */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    stack[-1] = v196;
    v196 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    if (!(v196 == nil)) goto v50;
    v198 = stack[-16];
    v197 = stack[-1];
    v196 = qvalue(elt(env, 3)); /* nil */
    v196 = list2star(v198, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v196 = Lnconc(nil, stack[-2], v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    stack[-3] = v196;
    v196 = stack[-3];
    v196 = qcdr(v196);
    v196 = qcdr(v196);
    stack[-2] = v196;
    goto v50;

v50:
    v196 = stack[-15];
    v196 = qcdr(v196);
    v196 = qcdr(v196);
    stack[-15] = v196;
    v196 = qvalue(elt(env, 2)); /* t */
    stack[-5] = v196;
    goto v142;

v76:
    stack[-1] = stack[-8];
    stack[-2] = stack[-15];
    v198 = stack[-13];
    v197 = stack[-14];
    v196 = qvalue(elt(env, 3)); /* nil */
    v196 = list2star(v198, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    fn = elt(env, 11); /* dipprod */
    v196 = (*qfn2(fn))(qenv(fn), stack[-2], v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v196 = Lnconc(nil, stack[-1], v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    goto v140;

v140:
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(18); return onevalue(v196); }

v201:
    v196 = stack[-12];
    if (v196 == nil) goto v144;
    stack[-1] = stack[-8];
    stack[-2] = stack[-12];
    v198 = stack[-10];
    v197 = stack[-11];
    v196 = qvalue(elt(env, 3)); /* nil */
    v196 = list2star(v198, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    fn = elt(env, 11); /* dipprod */
    v196 = (*qfn2(fn))(qenv(fn), stack[-2], v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    v196 = Lnconc(nil, stack[-1], v196);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-17];
    goto v140;

v144:
    v196 = stack[-8];
    goto v140;

v22:
    v196 = nil;
    goto v19;
/* error exit handlers */
v199:
    env = stack[-17];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(18);
    return nil;
}



/* Code for scalprod */

static Lisp_Object CC_scalprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scalprod");
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
    v213 = stack[-1];
    if (!(v213 == nil)) goto v10;
    v213 = stack[0];
    if (!(v213 == nil)) goto v10;
    v214 = qvalue(elt(env, 1)); /* nil */
    v213 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v214, v213);

v10:
    v213 = stack[-1];
    if (v213 == nil) goto v18;
    v213 = stack[0];
    if (v213 == nil) goto v18;
    v213 = stack[-1];
    v214 = qcar(v213);
    v213 = stack[0];
    v213 = qcar(v213);
    fn = elt(env, 5); /* multsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    v213 = stack[-1];
    v214 = qcdr(v213);
    v213 = stack[0];
    v213 = qcdr(v213);
    v213 = CC_scalprod(env, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    {
        Lisp_Object v216 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* addsq */
        return (*qfn2(fn))(qenv(fn), v216, v213);
    }

v18:
    v213 = elt(env, 2); /* "Matrix mismatch" */
    v214 = v213;
    v213 = v214;
    qvalue(elt(env, 3)) = v213; /* errmsg!* */
    v213 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v213 == nil)) goto v94;
    v213 = v214;
    fn = elt(env, 7); /* lprie */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    goto v94;

v94:
    v213 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v215;
    v213 = nil;
    { popv(4); return onevalue(v213); }
/* error exit handlers */
v215:
    popv(4);
    return nil;
}



/* Code for gsugar */

static Lisp_Object CC_gsugar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsugar");
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
    v86 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v86 == nil) goto v59;
    v86 = stack[0];
    if (v86 == nil) goto v11;
    v86 = stack[0];
    v86 = qcdr(v86);
    v86 = qcdr(v86);
    v86 = qcdr(v86);
    v86 = qcar(v86);
    if (v86 == nil) goto v11;
    v217 = stack[0];
    v86 = elt(env, 2); /* sugar */
    fn = elt(env, 4); /* vdpgetprop */
    v86 = (*qfn2(fn))(qenv(fn), v217, v86);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    goto v27;

v27:
    stack[-1] = v86;
    v86 = stack[-1];
    if (!(v86 == nil)) { popv(3); return onevalue(v86); }
    v217 = elt(env, 3); /* "*** missing sugar" */
    v86 = stack[0];
    v86 = list2(v217, v86);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v86 = Lprint(nil, v86);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    fn = elt(env, 5); /* backtrace */
    v86 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v86 = stack[0];
    fn = elt(env, 6); /* vdptdeg */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    stack[-1] = v86;
    v217 = stack[0];
    v86 = stack[-1];
    fn = elt(env, 7); /* gsetsugar */
    v86 = (*qfn2(fn))(qenv(fn), v217, v86);
    nil = C_nil;
    if (exception_pending()) goto v85;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v11:
    v86 = (Lisp_Object)1; /* 0 */
    goto v27;

v59:
    v86 = nil;
    { popv(3); return onevalue(v86); }
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for wedgepf */

static Lisp_Object CC_wedgepf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgepf");
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
    v15 = v1;
    v157 = v0;
/* end of prologue */
    stack[0] = v157;
    fn = elt(env, 1); /* !*pf2wedgepf */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    fn = elt(env, 2); /* wedgepf2 */
    v15 = (*qfn2(fn))(qenv(fn), stack[0], v15);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*wedgepf2pf */
        return (*qfn1(fn))(qenv(fn), v15);
    }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for ncoeffs */

static Lisp_Object CC_ncoeffs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v216;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ncoeffs");
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
    v216 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v215 = (Lisp_Object)1; /* 0 */
    stack[-2] = v215;
    v215 = v216;
    stack[-1] = v215;
    goto v14;

v14:
    v215 = stack[-1];
    if (v215 == nil) goto v219;
    v215 = stack[-1];
    v215 = qcar(v215);
    stack[0] = v215;
    v215 = stack[0];
    v215 = qcar(v215);
    stack[-4] = v215;
    goto v2;

v2:
    v216 = stack[-2];
    v215 = stack[-4];
    v215 = (Lisp_Object)lessp2(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v215 = v215 ? lisp_true : nil;
    env = stack[-5];
    if (v215 == nil) goto v140;
    v216 = qvalue(elt(env, 1)); /* nil */
    v215 = stack[-3];
    v215 = cons(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-5];
    stack[-3] = v215;
    v215 = stack[-2];
    v215 = add1(v215);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-5];
    stack[-2] = v215;
    goto v2;

v140:
    v215 = stack[-2];
    v215 = add1(v215);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-5];
    stack[-2] = v215;
    v215 = stack[0];
    v216 = qcdr(v215);
    v215 = stack[-3];
    v215 = cons(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-5];
    stack[-3] = v215;
    v215 = stack[-1];
    v215 = qcdr(v215);
    stack[-1] = v215;
    goto v14;

v219:
    v216 = stack[-4];
    v215 = stack[-3];
    popv(6);
    return cons(v216, v215);
/* error exit handlers */
v136:
    popv(6);
    return nil;
}



/* Code for prinfit */

static Lisp_Object MS_CDECL CC_prinfit(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v150, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v219, v201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prinfit");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinfit");
#endif
    if (stack >= stacklimit)
    {
        push3(v150,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v150);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v150;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v95 = qvalue(elt(env, 1)); /* !*nat */
    if (v95 == nil) goto v11;
    v95 = qvalue(elt(env, 2)); /* testing!-width!* */
    if (!(v95 == nil)) goto v11;
    v201 = stack[-2];
    v219 = stack[-1];
    v95 = stack[0];
    fn = elt(env, 3); /* layout!-formula */
    v95 = (*qfnn(fn))(qenv(fn), 3, v201, v219, v95);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v219 = v95;
    v95 = v219;
    if (v95 == nil) goto v89;
    v95 = v219;
    fn = elt(env, 4); /* putpline */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v95 = nil;
    { popv(4); return onevalue(v95); }

v89:
    v95 = stack[0];
    if (v95 == nil) goto v88;
    v95 = stack[0];
    fn = elt(env, 5); /* oprin */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    goto v88;

v88:
    v219 = stack[-2];
    v95 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* maprint */
        return (*qfn2(fn))(qenv(fn), v219, v95);
    }

v11:
    v95 = stack[0];
    if (v95 == nil) goto v113;
    v95 = stack[0];
    fn = elt(env, 5); /* oprin */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    goto v113;

v113:
    v219 = stack[-2];
    v95 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* maprint */
        return (*qfn2(fn))(qenv(fn), v219, v95);
    }
/* error exit handlers */
v135:
    popv(4);
    return nil;
}



/* Code for defined_edge */

static Lisp_Object CC_defined_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defined_edge");
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
    stack[0] = v1;
    v220 = v0;
/* end of prologue */
    v23 = v220;
    v24 = qcar(v23);
    v23 = qvalue(elt(env, 1)); /* old_edge_list */
    v23 = Lassoc(nil, v24, v23);
    if (!(v23 == nil)) { popv(2); return onevalue(v23); }
    v23 = v220;
    v24 = qcar(v23);
    v23 = qvalue(elt(env, 2)); /* new_edge_list */
    fn = elt(env, 4); /* all_edge */
    v220 = (*qfn2(fn))(qenv(fn), v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-1];
    v24 = qvalue(elt(env, 3)); /* nil */
    v23 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* defined_all_edge */
        return (*qfnn(fn))(qenv(fn), 3, v220, v24, v23);
    }
/* error exit handlers */
v114:
    popv(2);
    return nil;
}



/* Code for formcond1 */

static Lisp_Object MS_CDECL CC_formcond1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v150, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v85, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond1");
#endif
    if (stack >= stacklimit)
    {
        push3(v150,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v150);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v150;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v55;

v55:
    v200 = stack[-3];
    if (v200 == nil) goto v83;
    v200 = stack[-3];
    v200 = qcar(v200);
    v221 = qcar(v200);
    v85 = stack[-2];
    v200 = stack[-1];
    fn = elt(env, 1); /* formbool */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v221, v85, v200);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v200 = stack[-3];
    v200 = qcar(v200);
    v200 = qcdr(v200);
    v221 = qcar(v200);
    v85 = stack[-2];
    v200 = stack[-1];
    fn = elt(env, 2); /* formc */
    v200 = (*qfnn(fn))(qenv(fn), 3, v221, v85, v200);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v85 = list2(stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v200 = stack[-4];
    v200 = cons(v85, v200);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    stack[-4] = v200;
    v200 = stack[-3];
    v200 = qcdr(v200);
    stack[-3] = v200;
    goto v55;

v83:
    v200 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v200);
    }
/* error exit handlers */
v214:
    popv(6);
    return nil;
}



/* Code for mv!-domainlist!-!* */

static Lisp_Object CC_mvKdomainlistKH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist-*");
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
    stack[-2] = nil;
    goto v10;

v10:
    v23 = stack[0];
    if (v23 == nil) goto v11;
    v24 = stack[-1];
    v23 = stack[0];
    v23 = qcar(v23);
    v24 = times2(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-3];
    v23 = stack[-2];
    v23 = cons(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-3];
    stack[-2] = v23;
    v23 = stack[0];
    v23 = qcdr(v23);
    stack[0] = v23;
    goto v10;

v11:
    v23 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v23);
    }
/* error exit handlers */
v195:
    popv(4);
    return nil;
}



/* Code for mo!=revlexcomp */

static Lisp_Object CC_moMrevlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=revlexcomp");
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
    v9 = stack[-1];
    stack[-2] = Llength(nil, v9);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    v9 = stack[0];
    v9 = Llength(nil, v9);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v9))) goto v59;
    v9 = stack[0];
    stack[-2] = Llength(nil, v9);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    v9 = stack[-1];
    v9 = Llength(nil, v9);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v9))) goto v17;
    v9 = stack[-1];
    stack[-1] = Lreverse(nil, v9);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    v9 = stack[0];
    v9 = Lreverse(nil, v9);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    fn = elt(env, 1); /* mo!=degcomp */
    v9 = (*qfn2(fn))(qenv(fn), stack[-1], v9);
    nil = C_nil;
    if (exception_pending()) goto v148;
    popv(4);
    return negate(v9);

v17:
    v9 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v9); }

v59:
    v9 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v9); }
/* error exit handlers */
v148:
    popv(4);
    return nil;
}



/* Code for subsetp */

static Lisp_Object CC_subsetp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v23, v24, v220;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsetp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v23 = v1;
    v24 = v0;
/* end of prologue */

v222:
    v3 = v24;
    v3 = (v3 == nil ? lisp_true : nil);
    if (!(v3 == nil)) return onevalue(v3);
    v3 = v24;
    v220 = qcar(v3);
    v3 = v23;
    v3 = Lmember(nil, v220, v3);
    if (v3 == nil) goto v83;
    v3 = v24;
    v24 = qcdr(v3);
    v3 = v23;
    v23 = v3;
    goto v222;

v83:
    v3 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v3);
}



/* Code for dl_get */

static Lisp_Object CC_dl_get(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v83 = v0;
/* end of prologue */
    v14 = v83;
    v83 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* dl_get2 */
        return (*qfn2(fn))(qenv(fn), v14, v83);
    }
}



/* Code for removeg2 */

static Lisp_Object MS_CDECL CC_removeg2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v150, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v51, v236, v237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg2");
#endif
    if (stack >= stacklimit)
    {
        push3(v150,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v150);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v150;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v235 = stack[-4];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v51 = v235;
    v235 = stack[-3];
    v236 = qcar(v235);
    v235 = elt(env, 1); /* g3 */
    if (!(v236 == v235)) goto v8;
    v236 = v51;
    v235 = stack[-3];
    v235 = qcdr(v235);
    v235 = Lmemq(nil, v236, v235);
    if (v235 == nil) goto v8;
    v235 = stack[-3];
    fn = elt(env, 5); /* revv0 */
    v235 = (*qfn2(fn))(qenv(fn), v235, v51);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    goto v17;

v17:
    stack[-3] = v235;
    v51 = stack[-3];
    v235 = elt(env, 4); /* qg */
    v235 = Lrplaca(nil, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = stack[-5];
    stack[0] = qcar(v235);
    v235 = stack[-5];
    v235 = qcdr(v235);
    fn = elt(env, 6); /* mkcopy */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = cons(stack[0], v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    stack[-6] = v235;
    v51 = stack[-4];
    v235 = stack[-6];
    v235 = Lmember(nil, v51, v235);
    v235 = qcar(v235);
    stack[-1] = v235;
    v51 = stack[-3];
    v235 = stack[-6];
    v235 = Lmember(nil, v51, v235);
    v235 = qcar(v235);
    stack[0] = v235;
    v235 = stack[-4];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    stack[-2] = v235;
    v235 = stack[-4];
    v235 = qcdr(v235);
    v51 = qcdr(v235);
    v235 = stack[-4];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = stack[-4];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v51 = qcdr(v235);
    v235 = stack[-3];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = stack[-3];
    v235 = qcdr(v235);
    v51 = qcdr(v235);
    v235 = stack[-2];
    v235 = Lrplaca(nil, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = stack[-1];
    v235 = qcdr(v235);
    v235 = qcar(v235);
    stack[-2] = v235;
    v235 = stack[-1];
    v51 = qcdr(v235);
    v235 = stack[-1];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = stack[-1];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v51 = qcdr(v235);
    v235 = stack[0];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = stack[0];
    v235 = qcdr(v235);
    v51 = qcdr(v235);
    v235 = stack[0];
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = stack[0];
    v51 = qcdr(v235);
    v235 = stack[-2];
    v235 = Lrplaca(nil, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    stack[0] = stack[-5];
    v235 = stack[-6];
    v235 = qcar(v235);
    v235 = qcar(v235);
    fn = elt(env, 7); /* negf */
    v51 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    v235 = stack[-6];
    v235 = qcar(v235);
    v235 = qcdr(v235);
    v51 = cons(v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    v235 = stack[-6];
    v235 = qcdr(v235);
    {
        Lisp_Object v238 = stack[0];
        popv(8);
        return list2star(v238, v51, v235);
    }

v8:
    v237 = elt(env, 2); /* "Edge" */
    v236 = v51;
    v51 = elt(env, 3); /* "is absent in vertex" */
    v235 = stack[-3];
    v235 = list4(v237, v236, v51, v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    fn = elt(env, 8); /* cerror */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-7];
    goto v17;
/* error exit handlers */
v48:
    popv(8);
    return nil;
}



/* Code for freevarinexptchk */

static Lisp_Object CC_freevarinexptchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freevarinexptchk");
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

v222:
    v94 = stack[0];
    if (!consp(v94)) goto v73;
    v94 = stack[0];
    v94 = qcar(v94);
    if (!consp(v94)) goto v73;
    v94 = stack[0];
    v94 = qcar(v94);
    v94 = qcar(v94);
    v94 = qcdr(v94);
    v94 = (is_number(v94) ? lisp_true : nil);
    v94 = (v94 == nil ? lisp_true : nil);
    if (!(v94 == nil)) { popv(2); return onevalue(v94); }
    v94 = stack[0];
    v94 = qcar(v94);
    v94 = qcdr(v94);
    v94 = CC_freevarinexptchk(env, v94);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-1];
    if (!(v94 == nil)) { popv(2); return onevalue(v94); }
    v94 = stack[0];
    v94 = qcdr(v94);
    stack[0] = v94;
    goto v222;

v73:
    v94 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v94); }
/* error exit handlers */
v3:
    popv(2);
    return nil;
}



/* Code for pasf_smwmkatl */

static Lisp_Object MS_CDECL CC_pasf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v150, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8, v9, v89, v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v4;
    v9 = v150;
    v89 = v1;
    v239 = v0;
/* end of prologue */
    v7 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v7 == nil) goto v154;
    v7 = v239;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v7, v89, v9, v8);
    }

v154:
    v7 = v239;
    {
        fn = elt(env, 3); /* cl_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v7, v89, v9, v8);
    }
}



/* Code for ibalp_hassimple */

static Lisp_Object CC_ibalp_hassimple(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_hassimple");
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
    v8 = v0;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v8;
    goto v11;

v11:
    v8 = stack[0];
    if (v8 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v8 = stack[-1];
    if (!(v8 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v8 = stack[0];
    v8 = qcar(v8);
    v9 = qcar(v8);
    v8 = stack[0];
    v8 = qcar(v8);
    v8 = qcdr(v8);
    v8 = qcar(v8);
    fn = elt(env, 2); /* ibalp_commonlenisone */
    v8 = (*qfn2(fn))(qenv(fn), v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    if (v8 == nil) goto v143;
    v8 = stack[0];
    v8 = qcar(v8);
    stack[-1] = v8;
    goto v143;

v143:
    v8 = stack[0];
    v8 = qcdr(v8);
    stack[0] = v8;
    goto v11;
/* error exit handlers */
v13:
    popv(3);
    return nil;
}



/* Code for maxtype */

static Lisp_Object CC_maxtype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxtype");
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
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v143 = v5;
    if (!consp(v143)) return onevalue(v5);
    v143 = v5;
    v143 = qcdr(v143);
    v143 = Lconsp(nil, v143);
    if (v143 == nil) goto v16;
    v143 = v5;
    v143 = qcdr(v143);
    v143 = qcar(v143);
    return onevalue(v143);

v16:
    v143 = v5;
    v143 = qcar(v143);
    return onevalue(v143);
}



/* Code for actual_alst */

static Lisp_Object CC_actual_alst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for actual_alst");
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
    v89 = nil;
    goto v10;

v10:
    v8 = stack[-1];
    if (v8 == nil) goto v11;
    v8 = stack[-1];
    v8 = qcar(v8);
    v9 = qcar(v8);
    v8 = stack[0];
    v8 = Lmemq(nil, v9, v8);
    if (v8 == nil) goto v218;
    v8 = stack[-1];
    v8 = qcar(v8);
    v9 = v89;
    v8 = cons(v8, v9);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    v89 = v8;
    v8 = stack[-1];
    v8 = qcdr(v8);
    stack[-1] = v8;
    goto v10;

v218:
    v8 = stack[-1];
    v8 = qcdr(v8);
    stack[-1] = v8;
    goto v10;

v11:
    v8 = v89;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v8);
    }
/* error exit handlers */
v148:
    popv(3);
    return nil;
}



/* Code for assert_check1 */

static Lisp_Object MS_CDECL CC_assert_check1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v150, Lisp_Object v4,
                         Lisp_Object v73, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v235, v51, v236, v237, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "assert_check1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_check1");
#endif
    if (stack >= stacklimit)
    {
        push5(v73,v4,v150,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v150,v4,v73);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-5] = v73;
    stack[-6] = v4;
    stack[-7] = v150;
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    stack[-4] = nil;
    v52 = (Lisp_Object)1; /* 0 */
    stack[-3] = v52;
    v52 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v52 == nil) goto v16;
    v235 = stack[-9];
    v52 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v52 = Latsoc(nil, v235, v52);
    v235 = v52;
    v52 = v235;
    if (v52 == nil) goto v109;
    v52 = v235;
    stack[0] = qcdr(v52);
    v52 = v235;
    v52 = qcdr(v52);
    v52 = qcar(v52);
    v52 = add1(v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    fn = elt(env, 6); /* setcar */
    v52 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    goto v16;

v16:
    v52 = stack[-6];
    stack[-10] = v52;
    v52 = stack[-7];
    stack[-2] = v52;
    goto v216;

v216:
    v52 = stack[-2];
    if (v52 == nil) goto v250;
    v52 = stack[-2];
    v52 = qcar(v52);
    stack[-1] = v52;
    v52 = stack[-3];
    v52 = add1(v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    stack[-3] = v52;
    v52 = stack[-10];
    v235 = qcar(v52);
    v52 = elt(env, 4); /* assert_checkfn */
    v52 = get(v235, v52);
    env = stack[-11];
    v235 = v52;
    if (v52 == nil) goto v251;
    stack[0] = v235;
    v52 = stack[-1];
    v52 = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    fn = elt(env, 7); /* apply */
    v52 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    if (!(v52 == nil)) goto v251;
    v52 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v52;
    v248 = stack[-9];
    v237 = stack[-6];
    v236 = stack[-5];
    v51 = stack[-3];
    v52 = stack[-10];
    v235 = qcar(v52);
    v52 = stack[-1];
    fn = elt(env, 8); /* assert_error */
    v52 = (*qfnn(fn))(qenv(fn), 6, v248, v237, v236, v51, v235, v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    goto v251;

v251:
    v52 = stack[-10];
    v52 = qcdr(v52);
    stack[-10] = v52;
    v52 = stack[-2];
    v52 = qcdr(v52);
    stack[-2] = v52;
    goto v216;

v250:
    v235 = stack[-8];
    v52 = stack[-7];
    fn = elt(env, 7); /* apply */
    v52 = (*qfn2(fn))(qenv(fn), v235, v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    stack[-1] = v52;
    v235 = stack[-5];
    v52 = elt(env, 4); /* assert_checkfn */
    v52 = get(v235, v52);
    env = stack[-11];
    v235 = v52;
    if (v52 == nil) goto v252;
    stack[0] = v235;
    v52 = stack[-1];
    v52 = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    fn = elt(env, 7); /* apply */
    v52 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    if (!(v52 == nil)) goto v252;
    v52 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v52;
    v248 = stack[-9];
    v237 = stack[-6];
    v236 = stack[-5];
    v51 = (Lisp_Object)1; /* 0 */
    v235 = stack[-5];
    v52 = stack[-1];
    fn = elt(env, 8); /* assert_error */
    v52 = (*qfnn(fn))(qenv(fn), 6, v248, v237, v236, v51, v235, v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    goto v252;

v252:
    v52 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v52 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v52 = stack[-4];
    if (v52 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v235 = stack[-9];
    v52 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v52 = Latsoc(nil, v235, v52);
    v52 = qcdr(v52);
    v235 = v52;
    v52 = v235;
    stack[0] = qcdr(v52);
    v52 = v235;
    v52 = qcdr(v52);
    v52 = qcar(v52);
    v52 = add1(v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    fn = elt(env, 6); /* setcar */
    v52 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }

v109:
    stack[0] = stack[-9];
    v51 = (Lisp_Object)17; /* 1 */
    v235 = (Lisp_Object)1; /* 0 */
    v52 = (Lisp_Object)1; /* 0 */
    v235 = list3(v51, v235, v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    v52 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v52 = acons(stack[0], v235, v52);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    qvalue(elt(env, 2)) = v52; /* assertstatistics!* */
    goto v16;
/* error exit handlers */
v249:
    popv(12);
    return nil;
}



/* Code for aminusp!:1 */

static Lisp_Object CC_aminuspT1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v130, v257, v258;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aminusp:1");
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
    v256 = stack[-1];
    fn = elt(env, 6); /* aeval!* */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[-1] = v256;
    v256 = stack[-1];
    stack[-2] = v256;
    v256 = stack[-2];
    v256 = integerp(v256);
    if (v256 == nil) goto v18;
    v256 = stack[-2];
        popv(4);
        return Lminusp(nil, v256);

v18:
    v130 = stack[-2];
    v256 = elt(env, 1); /* !*sq */
    if (!consp(v130)) goto v154;
    v130 = qcar(v130);
    if (!(v130 == v256)) goto v154;

v11:
    v256 = stack[-2];
    v256 = qcdr(v256);
    v256 = qcar(v256);
    stack[-2] = v256;
    v256 = stack[-2];
    v256 = qcar(v256);
    v256 = integerp(v256);
    if (v256 == nil) goto v201;
    v256 = stack[-2];
    v256 = qcdr(v256);
    v256 = integerp(v256);
    if (v256 == nil) goto v201;
    v256 = stack[-2];
    v256 = qcar(v256);
        popv(4);
        return Lminusp(nil, v256);

v201:
    v256 = stack[-2];
    v130 = qcdr(v256);
    v256 = (Lisp_Object)17; /* 1 */
    if (!(v130 == v256)) goto v259;
    v256 = stack[-2];
    v256 = qcar(v256);
    stack[-2] = v256;
    if (!consp(v256)) goto v97;
    v256 = stack[-2];
    v256 = qcar(v256);
    if (!(!consp(v256))) goto v259;

v97:
    v130 = elt(env, 5); /* !:minusp */
    v256 = stack[-2];
        popv(4);
        return Lapply1(nil, v130, v256);

v259:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v256 = stack[-1];
    fn = elt(env, 7); /* reval */
    v258 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v257 = elt(env, 3); /* "invalid in FOR statement" */
    v130 = qvalue(elt(env, 2)); /* nil */
    v256 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v256 = (*qfnn(fn))(qenv(fn), 5, stack[0], v258, v257, v130, v256);
    nil = C_nil;
    if (exception_pending()) goto v98;
    v256 = nil;
    { popv(4); return onevalue(v256); }

v154:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v256 = stack[-1];
    fn = elt(env, 7); /* reval */
    v258 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v257 = elt(env, 3); /* "invalid in FOR statement" */
    v130 = qvalue(elt(env, 2)); /* nil */
    v256 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v256 = (*qfnn(fn))(qenv(fn), 5, stack[0], v258, v257, v130, v256);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    goto v11;
/* error exit handlers */
v98:
    popv(4);
    return nil;
}



/* Code for gperm3 */

static Lisp_Object CC_gperm3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v94, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm3");
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
    v94 = v1;
    v22 = v0;
/* end of prologue */

v10:
    v2 = v22;
    if (v2 == nil) { popv(2); return onevalue(v94); }
    v2 = v22;
    v2 = qcdr(v2);
    stack[0] = v2;
    v2 = v94;
    v94 = qcar(v22);
    v22 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* gperm2 */
    v22 = (*qfnn(fn))(qenv(fn), 3, v2, v94, v22);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v94 = v22;
    v22 = stack[0];
    goto v10;
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for dv_skel2factor1 */

static Lisp_Object CC_dv_skel2factor1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v251, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor1");
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
    v251 = stack[-1];
    if (v251 == nil) goto v11;
    v251 = stack[-1];
    fn = elt(env, 3); /* listp */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    if (v251 == nil) goto v148;
    v251 = stack[-1];
    v80 = qcar(v251);
    v251 = stack[0];
    v251 = CC_dv_skel2factor1(env, v80, v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    stack[-2] = v251;
    v251 = stack[-1];
    v80 = qcdr(v251);
    v251 = stack[0];
    v251 = CC_dv_skel2factor1(env, v80, v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    v251 = cons(stack[-2], v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    { popv(4); return onevalue(v251); }

v148:
    v80 = stack[-1];
    v251 = elt(env, 2); /* !~dv */
    if (!(v80 == v251)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v251 = stack[0];
    v251 = qcar(v251);
    stack[-1] = v251;
    v251 = stack[0];
    v251 = qcdr(v251);
    if (v251 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v80 = stack[0];
    v251 = stack[0];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = Lrplaca(nil, v80, v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    v80 = stack[0];
    v251 = stack[0];
    v251 = qcdr(v251);
    v251 = qcdr(v251);
    v251 = Lrplacd(nil, v80, v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v11:
    v251 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v251); }
/* error exit handlers */
v260:
    popv(4);
    return nil;
}



/* Code for cl_susiupdknowl */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v150, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v219, v201, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v4,v150,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v150,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v95 = v150;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v83;

v83:
    v219 = stack[-1];
    if (v219 == nil) goto v139;
    v219 = stack[-1];
    v219 = qcar(v219);
    stack[-3] = v219;
    v219 = stack[-1];
    v219 = qcdr(v219);
    stack[-1] = v219;
    v213 = stack[-2];
    v201 = stack[-3];
    v219 = v95;
    v95 = stack[0];
    fn = elt(env, 4); /* cl_susiupdknowl1 */
    v95 = (*qfnn(fn))(qenv(fn), 4, v213, v201, v219, v95);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    v201 = v95;
    v219 = elt(env, 2); /* false */
    if (!(v201 == v219)) goto v83;
    v219 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v219;
    v219 = elt(env, 3); /* break */
    stack[-3] = v219;
    goto v83;

v139:
    v201 = stack[-3];
    v219 = elt(env, 3); /* break */
    if (!(v201 == v219)) { popv(5); return onevalue(v95); }
    v95 = elt(env, 2); /* false */
    { popv(5); return onevalue(v95); }
/* error exit handlers */
v215:
    popv(5);
    return nil;
}



/* Code for rl_simpbop */

static Lisp_Object CC_rl_simpbop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpbop");
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
    v88 = v0;
/* end of prologue */
    v87 = v88;
    stack[-4] = qcar(v87);
    v87 = v88;
    v87 = qcdr(v87);
    stack[-3] = v87;
    v87 = stack[-3];
    if (v87 == nil) goto v143;
    v87 = stack[-3];
    v87 = qcar(v87);
    fn = elt(env, 2); /* rl_simp1 */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v87 = ncons(v87);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-1] = v87;
    stack[-2] = v87;
    goto v110;

v110:
    v87 = stack[-3];
    v87 = qcdr(v87);
    stack[-3] = v87;
    v87 = stack[-3];
    if (v87 == nil) goto v23;
    stack[0] = stack[-1];
    v87 = stack[-3];
    v87 = qcar(v87);
    fn = elt(env, 2); /* rl_simp1 */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v87 = ncons(v87);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v87 = Lrplacd(nil, stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v87 = stack[-1];
    v87 = qcdr(v87);
    stack[-1] = v87;
    goto v110;

v23:
    v87 = stack[-2];
    goto v10;

v10:
    {
        Lisp_Object v221 = stack[-4];
        popv(6);
        return cons(v221, v87);
    }

v143:
    v87 = qvalue(elt(env, 1)); /* nil */
    goto v10;
/* error exit handlers */
v85:
    popv(6);
    return nil;
}



/* Code for rl_ordatp */

static Lisp_Object CC_rl_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_ordatp");
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
    v20 = v1;
    v18 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_ordatp!* */
    v20 = list2(v18, v20);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    {
        Lisp_Object v151 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v151, v20);
    }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for spband_matrix */

static Lisp_Object CC_spband_matrix(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v277, v278, v279;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spband_matrix");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[0] = stack[-7];
    v279 = elt(env, 1); /* spm */
    v278 = stack[-7];
    v277 = stack[-7];
    v277 = list3(v279, v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    fn = elt(env, 10); /* mkempspmat */
    v277 = (*qfn2(fn))(qenv(fn), stack[0], v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    stack[-9] = v277;
    v277 = stack[-7];
    v277 = integerp(v277);
    if (!(v277 == nil)) goto v24;
    v277 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v277 == nil)) goto v89;
    v277 = elt(env, 3); /* "Error in spband_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 11); /* lprie */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    goto v89;

v89:
    v277 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    goto v24;

v24:
    v277 = stack[-8];
    if (!consp(v277)) goto v139;
    v277 = stack[-8];
    v278 = qcar(v277);
    v277 = elt(env, 4); /* list */
    if (v278 == v277) goto v217;
    v277 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v277 == nil)) goto v84;
    v277 = elt(env, 5); /* "Error in spband_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 11); /* lprie */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    goto v84;

v84:
    v277 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    goto v234;

v234:
    v277 = stack[-8];
    v277 = Llength(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    stack[-4] = v277;
    v277 = stack[-4];
    v277 = Levenp(nil, v277);
    env = stack[-10];
    if (v277 == nil) goto v97;
    v277 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v277 == nil)) goto v254;
    v277 = elt(env, 6); /* "Error in spband matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 11); /* lprie */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    goto v254;

v254:
    v277 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    goto v97;

v97:
    stack[0] = elt(env, 7); /* quotient */
    v277 = stack[-4];
    v278 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v277 = (Lisp_Object)33; /* 2 */
    v277 = list3(stack[0], v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    fn = elt(env, 12); /* reval */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    stack[-3] = v277;
    v277 = stack[-3];
    v277 = integerp(v277);
    if (v277 == nil) goto v77;
    v277 = stack[-3];
    v278 = v277;
    goto v280;

v280:
    v277 = stack[-7];
    v277 = (Lisp_Object)greaterp2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v131;
    v277 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v277 == nil)) goto v281;
    v277 = elt(env, 8); /* "Error in spband_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 11); /* lprie */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    goto v281;

v281:
    v277 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    goto v131;

v131:
    v277 = (Lisp_Object)33; /* 2 */
    stack[-5] = v277;
    v277 = (Lisp_Object)17; /* 1 */
    stack[-2] = v277;
    goto v116;

v116:
    v278 = stack[-7];
    v277 = stack[-2];
    v277 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v277 = Lminusp(nil, v277);
    env = stack[-10];
    if (!(v277 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v278 = stack[-2];
    v277 = stack[-3];
    v277 = (Lisp_Object)lesseq2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v142;
    v277 = (Lisp_Object)17; /* 1 */
    stack[-6] = v277;
    goto v242;

v242:
    v278 = stack[-3];
    v277 = stack[-2];
    v278 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v277 = stack[-6];
    v278 = plus2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v277 = (Lisp_Object)1; /* 0 */
    v277 = (Lisp_Object)greaterp2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v39;
    v278 = stack[-6];
    v277 = stack[-7];
    v277 = (Lisp_Object)lesseq2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v39;
    v278 = stack[-3];
    v277 = stack[-2];
    v278 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v277 = stack[-6];
    v278 = plus2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v277 = stack[-4];
    v277 = (Lisp_Object)lesseq2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v39;
    v279 = stack[-9];
    v278 = stack[-2];
    v277 = stack[-6];
    stack[-1] = list3(v279, v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    stack[0] = stack[-8];
    v278 = stack[-3];
    v277 = stack[-2];
    v278 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v277 = stack[-6];
    v277 = plus2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    fn = elt(env, 13); /* pnth */
    v277 = (*qfn2(fn))(qenv(fn), stack[0], v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v279 = qcar(v277);
    v278 = stack[-9];
    v277 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* letmtr3 */
    v277 = (*qfnn(fn))(qenv(fn), 4, stack[-1], v279, v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v277 = stack[-6];
    v277 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    stack[-6] = v277;
    goto v242;

v39:
    v278 = stack[-2];
    v277 = stack[-3];
    v277 = (Lisp_Object)greaterp2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v282;
    v277 = stack[-5];
    v277 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    stack[-5] = v277;
    goto v282;

v282:
    v277 = stack[-2];
    v277 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    stack[-2] = v277;
    goto v116;

v142:
    v277 = stack[-5];
    stack[-6] = v277;
    goto v242;

v77:
    v277 = stack[-3];
    fn = elt(env, 12); /* reval */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    v278 = v277;
    goto v280;

v217:
    v277 = stack[-8];
    v277 = qcdr(v277);
    stack[-8] = v277;
    goto v234;

v139:
    v277 = stack[-8];
    v277 = ncons(v277);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-10];
    stack[-8] = v277;
    goto v234;
/* error exit handlers */
v29:
    popv(11);
    return nil;
}



/* Code for redcodmat */

static Lisp_Object MS_CDECL CC_redcodmat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "redcodmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redcodmat");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    v6 = qvalue(elt(env, 1)); /* rowmin */
    stack[0] = v6;
    goto v115;

v115:
    v140 = qvalue(elt(env, 2)); /* rowmax */
    v6 = stack[0];
    v6 = difference2(v140, v6);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-1];
    v6 = Lminusp(nil, v6);
    env = stack[-1];
    if (v6 == nil) goto v55;
    v6 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v6); }

v55:
    v6 = stack[0];
    fn = elt(env, 4); /* testred */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-1];
    v6 = stack[0];
    v6 = add1(v6);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-1];
    stack[0] = v6;
    goto v115;
/* error exit handlers */
v154:
    popv(2);
    return nil;
}



/* Code for xord_gradlex */

static Lisp_Object CC_xord_gradlex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_gradlex");
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
    v153 = stack[-1];
    v200 = qcar(v153);
    v153 = (Lisp_Object)17; /* 1 */
    if (v200 == v153) goto v59;
    v153 = stack[0];
    v200 = qcar(v153);
    v153 = (Lisp_Object)17; /* 1 */
    if (v200 == v153) goto v16;
    v153 = stack[-1];
    stack[-2] = Llength(nil, v153);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v153 = stack[0];
    v153 = Llength(nil, v153);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    if (equal(stack[-2], v153)) goto v195;
    v153 = stack[-1];
    stack[-1] = Llength(nil, v153);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v153 = stack[0];
    v153 = Llength(nil, v153);
    nil = C_nil;
    if (exception_pending()) goto v95;
    {
        Lisp_Object v219 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v219, v153);
    }

v195:
    v200 = stack[-1];
    v153 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v200, v153);
    }

v16:
    v153 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v153); }

v59:
    v153 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v153); }
/* error exit handlers */
v95:
    popv(4);
    return nil;
}



/* Code for delete!-dups */

static Lisp_Object CC_deleteKdups(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v13, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delete-dups");
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
    v148 = nil;
    goto v59;

v59:
    v239 = stack[0];
    if (v239 == nil) goto v7;
    v239 = stack[0];
    v13 = qcar(v239);
    v239 = stack[0];
    v239 = qcdr(v239);
    v239 = Lmember(nil, v13, v239);
    if (v239 == nil) goto v22;
    v239 = stack[0];
    v239 = qcdr(v239);
    stack[0] = v239;
    goto v59;

v22:
    v239 = stack[0];
    v239 = qcar(v239);
    v13 = v148;
    v239 = cons(v239, v13);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v148 = v239;
    v239 = stack[0];
    v239 = qcdr(v239);
    stack[0] = v239;
    goto v59;

v7:
    v239 = v148;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v239);
    }
/* error exit handlers */
v109:
    popv(2);
    return nil;
}



/* Code for inttovec!-solve */

static Lisp_Object CC_inttovecKsolve(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v134;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec-solve");
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
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v134 = stack[-2];
    v253 = (Lisp_Object)1; /* 0 */
    if (v134 == v253) goto v6;
    v134 = stack[-3];
    v253 = (Lisp_Object)17; /* 1 */
    if (v134 == v253) goto v6;
    v253 = (Lisp_Object)1; /* 0 */
    stack[-4] = v253;
    v253 = (Lisp_Object)17; /* 1 */
    stack[0] = v253;
    goto v9;

v9:
    v253 = stack[0];
    stack[-1] = v253;
    v253 = stack[-4];
    v253 = add1(v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-5];
    stack[-4] = v253;
    v134 = stack[-3];
    v253 = stack[-4];
    v134 = plus2(v134, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-5];
    v253 = stack[-1];
    v134 = times2(v134, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-5];
    v253 = stack[-4];
    v253 = quot2(v134, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-5];
    stack[0] = v253;
    v134 = stack[0];
    v253 = stack[-2];
    v253 = (Lisp_Object)greaterp2(v134, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v253 = v253 ? lisp_true : nil;
    env = stack[-5];
    if (v253 == nil) goto v9;
    stack[0] = stack[-4];
    v134 = stack[-2];
    v253 = stack[-1];
    v253 = difference2(v134, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    {
        Lisp_Object v202 = stack[0];
        popv(6);
        return cons(v202, v253);
    }

v6:
    v134 = stack[-2];
    v253 = (Lisp_Object)1; /* 0 */
    popv(6);
    return cons(v134, v253);
/* error exit handlers */
v284:
    popv(6);
    return nil;
}



/* Code for gpexp1p */

static Lisp_Object CC_gpexp1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexp1p");
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

v222:
    v143 = stack[0];
    v143 = (v143 == nil ? lisp_true : nil);
    if (!(v143 == nil)) { popv(2); return onevalue(v143); }
    v143 = stack[0];
    v143 = qcar(v143);
    fn = elt(env, 2); /* gpexpp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-1];
    if (v143 == nil) goto v11;
    v143 = stack[0];
    v143 = qcdr(v143);
    stack[0] = v143;
    goto v222;

v11:
    v143 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v143); }
/* error exit handlers */
v151:
    popv(2);
    return nil;
}



/* Code for cstimes */

static Lisp_Object CC_cstimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v221, v96, v95;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cstimes");
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
    v221 = v1;
    v96 = v0;
/* end of prologue */

v10:
    v85 = v96;
    if (v85 == nil) goto v11;
    v85 = v96;
    v95 = qcar(v85);
    v85 = (Lisp_Object)17; /* 1 */
    if (v95 == v85) goto v23;
    v85 = v96;
    v85 = qcdr(v85);
    stack[0] = v85;
    v85 = v96;
    v85 = qcar(v85);
    v85 = cons(v85, v221);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    v221 = v85;
    v85 = stack[0];
    v96 = v85;
    goto v10;

v23:
    v85 = v96;
    v85 = qcdr(v85);
    v96 = v85;
    goto v10;

v11:
    v85 = v221;
    if (v85 == nil) goto v157;
    v85 = v221;
    v85 = qcdr(v85);
    if (v85 == nil) goto v20;
    v85 = elt(env, 1); /* times */
    popv(2);
    return cons(v85, v221);

v20:
    v85 = v221;
    v85 = qcar(v85);
    { popv(2); return onevalue(v85); }

v157:
    v85 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v85); }
/* error exit handlers */
v201:
    popv(2);
    return nil;
}



/* Code for evalneq */

static Lisp_Object CC_evalneq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalneq");
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
    v115 = v1;
    v15 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalequal */
    v115 = (*qfn2(fn))(qenv(fn), v15, v115);
    errexit();
    v115 = (v115 == nil ? lisp_true : nil);
    return onevalue(v115);
}



/* Code for mo_neg */

static Lisp_Object CC_mo_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neg");
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
    stack[-2] = v0;
/* end of prologue */
    v283 = stack[-2];
    v283 = qcar(v283);
    stack[-4] = v283;
    v283 = stack[-4];
    if (v283 == nil) goto v20;
    v283 = stack[-4];
    v283 = qcar(v283);
    v283 = negate(v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    v283 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    stack[-1] = v283;
    stack[-3] = v283;
    goto v15;

v15:
    v283 = stack[-4];
    v283 = qcdr(v283);
    stack[-4] = v283;
    v283 = stack[-4];
    if (v283 == nil) goto v2;
    stack[0] = stack[-1];
    v283 = stack[-4];
    v283 = qcar(v283);
    v283 = negate(v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    v283 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    v283 = Lrplacd(nil, stack[0], v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    v283 = stack[-1];
    v283 = qcdr(v283);
    stack[-1] = v283;
    goto v15;

v2:
    v283 = stack[-3];
    stack[-4] = v283;
    goto v59;

v59:
    v283 = stack[-2];
    v283 = qcdr(v283);
    stack[-3] = v283;
    v283 = stack[-3];
    if (v283 == nil) goto v221;
    v283 = stack[-3];
    v283 = qcar(v283);
    v283 = negate(v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    v283 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    stack[-1] = v283;
    stack[-2] = v283;
    goto v86;

v86:
    v283 = stack[-3];
    v283 = qcdr(v283);
    stack[-3] = v283;
    v283 = stack[-3];
    if (v283 == nil) goto v285;
    stack[0] = stack[-1];
    v283 = stack[-3];
    v283 = qcar(v283);
    v283 = negate(v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    v283 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    v283 = Lrplacd(nil, stack[0], v283);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-5];
    v283 = stack[-1];
    v283 = qcdr(v283);
    stack[-1] = v283;
    goto v86;

v285:
    v283 = stack[-2];
    goto v10;

v10:
    {
        Lisp_Object v97 = stack[-4];
        popv(6);
        return cons(v97, v283);
    }

v221:
    v283 = qvalue(elt(env, 1)); /* nil */
    goto v10;

v20:
    v283 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v283;
    goto v59;
/* error exit handlers */
v193:
    popv(6);
    return nil;
}



/* Code for pst_termnodep */

static Lisp_Object CC_pst_termnodep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v157;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v157 = qcdr(v15);
    v15 = (Lisp_Object)1; /* 0 */
    v15 = *(Lisp_Object *)((char *)v157 + (CELL-TAG_VECTOR) + ((int32_t)v15/(16/CELL)));
    v15 = qcdr(v15);
    v15 = (v15 == nil ? lisp_true : nil);
    return onevalue(v15);
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_negateat");
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
    v14 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v14 = ncons(v14);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    {
        Lisp_Object v157 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v157, v14);
    }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for ibalp_simpatom */

static Lisp_Object CC_ibalp_simpatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v287;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpatom");
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
    v287 = stack[0];
    v202 = (Lisp_Object)1; /* 0 */
    if (v287 == v202) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v287 = stack[0];
    v202 = (Lisp_Object)17; /* 1 */
    if (v287 == v202) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v202 = stack[0];
    if (symbolp(v202)) goto v19;
    v202 = stack[0];
    if (!(v202 == nil)) goto v234;
    v287 = elt(env, 2); /* "nil" */
    v202 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v202 = (*qfn2(fn))(qenv(fn), v287, v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-1];
    goto v234;

v234:
    v202 = stack[0];
    if (!(is_number(v202))) goto v219;
    v287 = elt(env, 4); /* "number" */
    v202 = stack[0];
    v287 = list2(v287, v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-1];
    v202 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v202 = (*qfn2(fn))(qenv(fn), v287, v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-1];
    goto v219;

v219:
    v202 = stack[0];
    v202 = Lstringp(nil, v202);
    env = stack[-1];
    if (v202 == nil) goto v81;
    v287 = elt(env, 5); /* "string" */
    v202 = stack[0];
    v287 = list2(v287, v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-1];
    v202 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v202 = (*qfn2(fn))(qenv(fn), v287, v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    goto v81;

v81:
    v202 = nil;
    { popv(2); return onevalue(v202); }

v19:
    v202 = stack[0];
    fn = elt(env, 7); /* rl_gettype */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-1];
    if (v202 == nil) goto v8;
    v202 = stack[0];
    fn = elt(env, 8); /* reval */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 9); /* ibalp_simpterm */
        return (*qfn1(fn))(qenv(fn), v202);
    }

v8:
    v202 = stack[0];
    v287 = ncons(v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-1];
    v202 = elt(env, 1); /* used!* */
    v202 = Lflag(nil, v287, v202);
    nil = C_nil;
    if (exception_pending()) goto v79;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v79:
    popv(2);
    return nil;
}



/* Code for ratpoly_lc */

static Lisp_Object CC_ratpoly_lc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_lc");
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
    stack[0] = v0;
/* end of prologue */
    v15 = stack[0];
    v15 = qcar(v15);
    fn = elt(env, 1); /* numpoly_lc */
    v157 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v15 = stack[0];
    v15 = qcdr(v15);
    popv(1);
    return cons(v157, v15);
/* error exit handlers */
v16:
    popv(1);
    return nil;
}



/* Code for poly!-abs */

static Lisp_Object CC_polyKabs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-abs");
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
    v15 = stack[0];
    fn = elt(env, 1); /* poly!-minusp */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    if (v15 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v15 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v15);
    }
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for mathml2 */

static Lisp_Object MS_CDECL CC_mathml2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml2");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    {
        fn = elt(env, 2); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
}



/* Code for getrtype1 */

static Lisp_Object CC_getrtype1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v4;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtype1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v4);
}



/* Code for add_minus */

static Lisp_Object CC_add_minus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v243;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_minus");
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
    v121 = stack[-1];
    if (!consp(v121)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v121 = stack[-1];
    v243 = qcar(v121);
    v121 = elt(env, 1); /* !:rd!: */
    if (!(v243 == v121)) goto v24;
    v121 = stack[-1];
    v243 = qcdr(v121);
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)geq2(v243, v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v121 = v121 ? lisp_true : nil;
    env = stack[-3];
    if (!(v121 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v24:
    v121 = stack[-1];
    v243 = qcar(v121);
    v121 = elt(env, 1); /* !:rd!: */
    if (!(v243 == v121)) goto v289;
    v121 = stack[-1];
    v243 = qcdr(v121);
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)lessp2(v243, v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v121 = v121 ? lisp_true : nil;
    env = stack[-3];
    if (v121 == nil) goto v289;
    stack[-2] = elt(env, 2); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = Labsval(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-3];
    v121 = cons(stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    {
        Lisp_Object v203 = stack[-2];
        popv(4);
        return list2(v203, v121);
    }

v289:
    v121 = stack[-1];
    v243 = qcar(v121);
    v121 = elt(env, 2); /* minus */
    if (!(v243 == v121)) goto v191;
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = qcar(v121);
    if (is_number(v121)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else goto v191;

v191:
    v121 = stack[-1];
    v243 = qcar(v121);
    v121 = elt(env, 2); /* minus */
    if (!(v243 == v121)) goto v290;
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = qcar(v121);
    v243 = qcdr(v121);
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)lessp2(v243, v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v121 = v121 ? lisp_true : nil;
    env = stack[-3];
    if (v121 == nil) goto v290;
    stack[0] = elt(env, 1); /* !:rd!: */
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v121 = Labsval(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    {
        Lisp_Object v63 = stack[0];
        popv(4);
        return cons(v63, v121);
    }

v290:
    v121 = stack[-1];
    v243 = qcar(v121);
    v121 = elt(env, 2); /* minus */
    if (v243 == v121) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v121 = stack[-1];
    v243 = qcdr(v121);
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)lessp2(v243, v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v121 = v121 ? lisp_true : nil;
    env = stack[-3];
    if (v121 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = elt(env, 2); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = Labsval(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-3];
    v121 = cons(stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v227;
    {
        Lisp_Object v64 = stack[-2];
        popv(4);
        return list2(v64, v121);
    }
/* error exit handlers */
v227:
    popv(4);
    return nil;
}



/* Code for guesspftype */

static Lisp_Object CC_guesspftype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v234, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for guesspftype");
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
    v112 = stack[0];
    if (!consp(v112)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v112 = stack[0];
    v234 = qcar(v112);
    v112 = elt(env, 1); /* (wedge d partdf hodge innerprod liedf) */
    v112 = Lmemq(nil, v234, v112);
    if (!(v112 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v112 = stack[0];
    v112 = qcdr(v112);
    v139 = Llength(nil, v112);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-1];
    v112 = stack[0];
    v234 = qcar(v112);
    v112 = elt(env, 2); /* ifdegree */
    v112 = get(v234, v112);
    env = stack[-1];
    v112 = Lassoc(nil, v139, v112);
    if (v112 == nil) goto v148;
    v112 = stack[0];
    v112 = qcdr(v112);
    fn = elt(env, 3); /* xvarlistp */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-1];
    if (v112 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v148;

v148:
    v112 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mknwedge */
        return (*qfn1(fn))(qenv(fn), v112);
    }
/* error exit handlers */
v88:
    popv(2);
    return nil;
}



/* Code for !:dmpluslst */

static Lisp_Object CC_Tdmpluslst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmpluslst");
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
    v154 = v19;
    if (v154 == nil) goto v73;
    v154 = v19;
    v154 = qcdr(v154);
    if (v154 == nil) goto v27;
    v154 = v19;
    stack[0] = qcar(v154);
    v154 = v19;
    v154 = qcdr(v154);
    v154 = CC_Tdmpluslst(env, v154);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    {
        Lisp_Object v94 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:plus */
        return (*qfn2(fn))(qenv(fn), v94, v154);
    }

v27:
    v154 = v19;
    v154 = qcar(v154);
    { popv(2); return onevalue(v154); }

v73:
    v154 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v154); }
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for mapins */

static Lisp_Object CC_mapins(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapins");
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
    stack[-2] = nil;
    goto v10;

v10:
    v7 = stack[0];
    if (v7 == nil) goto v11;
    v8 = stack[-1];
    v7 = stack[0];
    v7 = qcar(v7);
    v7 = qcar(v7);
    v9 = cons(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    v7 = stack[0];
    v7 = qcar(v7);
    v8 = qcdr(v7);
    v7 = stack[-2];
    v7 = acons(v9, v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    stack[-2] = v7;
    v7 = stack[0];
    v7 = qcdr(v7);
    stack[0] = v7;
    goto v10;

v11:
    v7 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v7);
    }
/* error exit handlers */
v148:
    popv(4);
    return nil;
}



/* Code for deleteall */

static Lisp_Object CC_deleteall(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v195, v7, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteall");
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
    v7 = nil;
    goto v55;

v55:
    v114 = stack[0];
    if (v114 == nil) { popv(4); return onevalue(v7); }
    v114 = stack[0];
    v114 = qcar(v114);
    v8 = v114;
    v114 = stack[0];
    v114 = qcdr(v114);
    stack[0] = v114;
    v195 = v8;
    v114 = stack[-1];
    if (equal(v195, v114)) goto v55;
    stack[-2] = v7;
    v114 = v8;
    v114 = ncons(v114);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v114 = Lnconc(nil, stack[-2], v114);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v7 = v114;
    goto v55;
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for quotdd */

static Lisp_Object CC_quotdd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v283, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotdd");
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
    v255 = stack[-1];
    if (!(!consp(v255))) goto v190;
    v255 = stack[0];
    if (!consp(v255)) goto v17;
    v255 = stack[0];
    v283 = qcar(v255);
    v255 = elt(env, 2); /* i2d */
    v255 = get(v283, v255);
    env = stack[-2];
    v133 = v255;
    if (v255 == nil) goto v9;
    v283 = v133;
    v255 = stack[-1];
    v255 = Lapply1(nil, v283, v255);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-2];
    stack[-1] = v255;
    goto v190;

v190:
    v133 = stack[-1];
    v283 = stack[0];
    v255 = elt(env, 3); /* quotient */
    {
        popv(3);
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v133, v283, v255);
    }

v9:
    v255 = stack[0];
    if (!(!consp(v255))) goto v190;
    v255 = stack[-1];
    v283 = qcar(v255);
    v255 = elt(env, 2); /* i2d */
    v255 = get(v283, v255);
    env = stack[-2];
    v133 = v255;
    if (v255 == nil) goto v190;
    v283 = v133;
    v255 = stack[0];
    v255 = Lapply1(nil, v283, v255);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-2];
    stack[0] = v255;
    goto v190;

v17:
    v283 = stack[-1];
    v255 = stack[0];
    v255 = Ldivide(nil, v283, v255);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-2];
    v133 = v255;
    v255 = v133;
    v283 = qcdr(v255);
    v255 = (Lisp_Object)1; /* 0 */
    if (v283 == v255) goto v12;
    v255 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v255); }

v12:
    v255 = v133;
    v255 = qcar(v255);
    { popv(3); return onevalue(v255); }
/* error exit handlers */
v194:
    popv(3);
    return nil;
}



setup_type const u13_setup[] =
{
    {"all_edge",                too_few_2,      CC_all_edge,   wrong_no_2},
    {"red_better",              too_few_2,      CC_red_better, wrong_no_2},
    {"pv_times3",               too_few_2,      CC_pv_times3,  wrong_no_2},
    {"pa_coinc_split",          too_few_2,      CC_pa_coinc_split,wrong_no_2},
    {"lambda_l9xqtr_2",         too_few_2,      CC_lambda_l9xqtr_2,wrong_no_2},
    {"modquotient:",            too_few_2,      CC_modquotientT,wrong_no_2},
    {"general-times-mod-p",     too_few_2,      CC_generalKtimesKmodKp,wrong_no_2},
    {"qqe_simplterm",           CC_qqe_simplterm,too_many_1,   wrong_no_1},
    {"mkzl",                    CC_mkzl,        too_many_1,    wrong_no_1},
    {"numpoly_nullp",           CC_numpoly_nullp,too_many_1,   wrong_no_1},
    {"matrixrowrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrowrd},
    {"dipilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipilcomb1},
    {"scalprod",                too_few_2,      CC_scalprod,   wrong_no_2},
    {"gsugar",                  CC_gsugar,      too_many_1,    wrong_no_1},
    {"wedgepf",                 too_few_2,      CC_wedgepf,    wrong_no_2},
    {"ncoeffs",                 CC_ncoeffs,     too_many_1,    wrong_no_1},
    {"prinfit",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_prinfit},
    {"defined_edge",            too_few_2,      CC_defined_edge,wrong_no_2},
    {"formcond1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond1},
    {"mv-domainlist-*",         too_few_2,      CC_mvKdomainlistKH,wrong_no_2},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"subsetp",                 too_few_2,      CC_subsetp,    wrong_no_2},
    {"dl_get",                  CC_dl_get,      too_many_1,    wrong_no_1},
    {"removeg2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg2},
    {"freevarinexptchk",        CC_freevarinexptchk,too_many_1,wrong_no_1},
    {"pasf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwmkatl},
    {"ibalp_hassimple",         CC_ibalp_hassimple,too_many_1, wrong_no_1},
    {"maxtype",                 CC_maxtype,     too_many_1,    wrong_no_1},
    {"actual_alst",             too_few_2,      CC_actual_alst,wrong_no_2},
    {"assert_check1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_check1},
    {"aminusp:1",               CC_aminuspT1,   too_many_1,    wrong_no_1},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"dv_skel2factor1",         too_few_2,      CC_dv_skel2factor1,wrong_no_2},
    {"cl_susiupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"rl_ordatp",               too_few_2,      CC_rl_ordatp,  wrong_no_2},
    {"spband_matrix",           too_few_2,      CC_spband_matrix,wrong_no_2},
    {"redcodmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_redcodmat},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"delete-dups",             CC_deleteKdups, too_many_1,    wrong_no_1},
    {"inttovec-solve",          too_few_2,      CC_inttovecKsolve,wrong_no_2},
    {"gpexp1p",                 CC_gpexp1p,     too_many_1,    wrong_no_1},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"evalneq",                 too_few_2,      CC_evalneq,    wrong_no_2},
    {"mo_neg",                  CC_mo_neg,      too_many_1,    wrong_no_1},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"ibalp_simpatom",          CC_ibalp_simpatom,too_many_1,  wrong_no_1},
    {"ratpoly_lc",              CC_ratpoly_lc,  too_many_1,    wrong_no_1},
    {"poly-abs",                CC_polyKabs,    too_many_1,    wrong_no_1},
    {"mathml2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml2},
    {"getrtype1",               CC_getrtype1,   too_many_1,    wrong_no_1},
    {"add_minus",               CC_add_minus,   too_many_1,    wrong_no_1},
    {"guesspftype",             CC_guesspftype, too_many_1,    wrong_no_1},
    {":dmpluslst",              CC_Tdmpluslst,  too_many_1,    wrong_no_1},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"deleteall",               too_few_2,      CC_deleteall,  wrong_no_2},
    {"quotdd",                  too_few_2,      CC_quotdd,     wrong_no_2},
    {NULL, (one_args *)"u13", (two_args *)"14854 5416727 1480983", 0}
};

/* end of generated code */
