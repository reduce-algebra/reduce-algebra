
/* $destdir\u15.c        Machine generated C code */

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


/* Code for qremf */

static Lisp_Object CC_qremf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qremf");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    v100 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v100; /* !*exp */
    v100 = stack[-6];
    if (!consp(v100)) goto v103;
    v100 = stack[-6];
    v100 = qcar(v100);
    if (!consp(v100)) goto v103;
    v100 = qvalue(elt(env, 3)); /* nil */
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-2] = v100;
    goto v105;

v105:
    v100 = stack[-7];
    if (!consp(v100)) goto v106;
    v100 = stack[-7];
    v100 = qcar(v100);
    if (!consp(v100)) goto v106;
    v100 = stack[-7];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v101 = qcar(v100);
    v100 = stack[-6];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v100 = qcar(v100);
    if (v101 == v100) goto v107;
    v100 = stack[-7];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v101 = qcar(v100);
    v100 = stack[-6];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v100 = qcar(v100);
    fn = elt(env, 4); /* ordop */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    if (v100 == nil) goto v108;
    v100 = stack[-7];
    v100 = qcar(v100);
    v101 = qcdr(v100);
    v100 = stack[-6];
    v100 = CC_qremf(env, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-4] = v100;
    v100 = stack[-7];
    v100 = qcar(v100);
    v101 = qcar(v100);
    v100 = (Lisp_Object)17; /* 1 */
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v101 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-4];
    v100 = qcar(v100);
    fn = elt(env, 5); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-7];
    v100 = qcar(v100);
    v101 = qcar(v100);
    v100 = (Lisp_Object)17; /* 1 */
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v101 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-4];
    v100 = qcdr(v100);
    fn = elt(env, 5); /* multf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = cons(stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-1] = v100;
    v100 = stack[-2];
    v101 = qcar(v100);
    v100 = stack[-1];
    v100 = qcar(v100);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-2];
    v101 = qcdr(v100);
    v100 = stack[-1];
    v100 = qcdr(v100);
    fn = elt(env, 6); /* addf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = cons(stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-2] = v100;
    v100 = stack[-7];
    v100 = qcdr(v100);
    stack[-7] = v100;
    goto v105;

v108:
    v101 = qvalue(elt(env, 3)); /* nil */
    v100 = stack[-7];
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-1] = v100;
    v100 = stack[-2];
    v101 = qcar(v100);
    v100 = stack[-1];
    v100 = qcar(v100);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-2];
    v101 = qcdr(v100);
    v100 = stack[-1];
    v100 = qcdr(v100);
    fn = elt(env, 6); /* addf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = cons(stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    goto v109;

v109:
    qvalue(elt(env, 1)) = stack[-5]; /* !*exp */
    { popv(10); return onevalue(v100); }

v107:
    v100 = stack[-7];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v101 = qcdr(v100);
    v100 = stack[-6];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v100 = qcdr(v100);
    v101 = difference2(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-8] = v101;
    v100 = (Lisp_Object)1; /* 0 */
    v100 = (Lisp_Object)lessp2(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v100 = v100 ? lisp_true : nil;
    env = stack[-9];
    if (v100 == nil) goto v110;
    v101 = qvalue(elt(env, 3)); /* nil */
    v100 = stack[-7];
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-1] = v100;
    v100 = stack[-2];
    v101 = qcar(v100);
    v100 = stack[-1];
    v100 = qcar(v100);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-2];
    v101 = qcdr(v100);
    v100 = stack[-1];
    v100 = qcdr(v100);
    fn = elt(env, 6); /* addf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = cons(stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    goto v109;

v110:
    v100 = stack[-7];
    v100 = qcar(v100);
    v101 = qcdr(v100);
    v100 = stack[-6];
    v100 = qcar(v100);
    v100 = qcdr(v100);
    v100 = CC_qremf(env, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-4] = v100;
    v100 = stack[-7];
    v100 = qcar(v100);
    v101 = qcar(v100);
    v100 = (Lisp_Object)17; /* 1 */
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v101 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-4];
    v100 = qcdr(v100);
    fn = elt(env, 5); /* multf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-3] = v100;
    v101 = stack[-8];
    v100 = (Lisp_Object)1; /* 0 */
    if (v101 == v100) goto v111;
    v100 = stack[-7];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v102 = qcar(v100);
    v101 = stack[-8];
    v100 = (Lisp_Object)17; /* 1 */
    v100 = acons(v102, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v101 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-4];
    v100 = qcar(v100);
    fn = elt(env, 5); /* multf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v101 = v100;
    goto v112;

v112:
    v100 = stack[-3];
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-1] = v100;
    v100 = stack[-2];
    v101 = qcar(v100);
    v100 = stack[-1];
    v100 = qcar(v100);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-2];
    v101 = qcdr(v100);
    v100 = stack[-1];
    v100 = qcdr(v100);
    fn = elt(env, 6); /* addf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = cons(stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-2] = v100;
    v100 = stack[-4];
    v100 = qcar(v100);
    if (v100 == nil) goto v113;
    stack[0] = stack[-7];
    v101 = stack[-8];
    v100 = (Lisp_Object)1; /* 0 */
    if (v101 == v100) goto v114;
    v100 = stack[-7];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v102 = qcar(v100);
    v101 = stack[-8];
    v100 = (Lisp_Object)17; /* 1 */
    v100 = acons(v102, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v101 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-6];
    fn = elt(env, 5); /* multf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-1] = v100;
    goto v115;

v115:
    v100 = stack[-4];
    v100 = qcar(v100);
    fn = elt(env, 7); /* negf */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    fn = elt(env, 5); /* multf */
    v100 = (*qfn2(fn))(qenv(fn), stack[-1], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-3];
    fn = elt(env, 7); /* negf */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    fn = elt(env, 6); /* addf */
    v100 = (*qfn2(fn))(qenv(fn), stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    goto v116;

v116:
    stack[-7] = v100;
    goto v105;

v114:
    v100 = stack[-6];
    stack[-1] = v100;
    goto v115;

v113:
    v100 = stack[-7];
    v100 = qcdr(v100);
    goto v116;

v111:
    v100 = stack[-4];
    v100 = qcar(v100);
    v101 = v100;
    goto v112;

v106:
    v101 = qvalue(elt(env, 3)); /* nil */
    v100 = stack[-7];
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    stack[-1] = v100;
    v100 = stack[-2];
    v101 = qcar(v100);
    v100 = stack[-1];
    v100 = qcar(v100);
    fn = elt(env, 6); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = stack[-2];
    v101 = qcdr(v100);
    v100 = stack[-1];
    v100 = qcdr(v100);
    fn = elt(env, 6); /* addf */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    v100 = cons(stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    goto v109;

v103:
    v101 = stack[-7];
    v100 = stack[-6];
    fn = elt(env, 8); /* qremd */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-9];
    goto v109;
/* error exit handlers */
v104:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-5]; /* !*exp */
    popv(10);
    return nil;
}



/* Code for intexprlisp */

static Lisp_Object CC_intexprlisp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intexprlisp");
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

v123:
    v121 = stack[-1];
    v121 = (v121 == nil ? lisp_true : nil);
    if (!(v121 == nil)) { popv(3); return onevalue(v121); }
    v121 = stack[-1];
    v122 = qcar(v121);
    v121 = stack[0];
    fn = elt(env, 2); /* intexprnp */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    if (v121 == nil) goto v105;
    v121 = stack[-1];
    v122 = qcdr(v121);
    v121 = stack[0];
    stack[-1] = v122;
    stack[0] = v121;
    goto v123;

v105:
    v121 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v121); }
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for squared!+matrix!+p */

static Lisp_Object CC_squaredLmatrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for squared+matrix+p");
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
    v126 = stack[0];
    fn = elt(env, 2); /* matrix!+p */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    if (v126 == nil) goto v16;
    v126 = stack[0];
    fn = elt(env, 3); /* get!+row!+nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v126 = stack[0];
    fn = elt(env, 4); /* get!+col!+nr */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    if (!(equal(stack[-1], v126))) goto v16;
    v126 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v126); }

v16:
    v126 = nil;
    { popv(3); return onevalue(v126); }
/* error exit handlers */
v127:
    popv(3);
    return nil;
}



/* Code for ibalp_simpterm */

static Lisp_Object CC_ibalp_simpterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpterm");
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
    stack[0] = v0;
/* end of prologue */

v123:
    v137 = stack[0];
    if (!consp(v137)) goto v9;
    v137 = stack[0];
    v137 = qcar(v137);
    stack[-1] = v137;
    v137 = stack[-1];
    fn = elt(env, 3); /* ibalp_boolfp */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    if (v137 == nil) goto v139;
    stack[-4] = stack[-1];
    v137 = stack[0];
    v137 = qcdr(v137);
    stack[-3] = v137;
    v137 = stack[-3];
    if (v137 == nil) goto v124;
    v137 = stack[-3];
    v137 = qcar(v137);
    v137 = CC_ibalp_simpterm(env, v137);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    v137 = ncons(v137);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    stack[-1] = v137;
    stack[-2] = v137;
    goto v119;

v119:
    v137 = stack[-3];
    v137 = qcdr(v137);
    stack[-3] = v137;
    v137 = stack[-3];
    if (v137 == nil) goto v140;
    stack[0] = stack[-1];
    v137 = stack[-3];
    v137 = qcar(v137);
    v137 = CC_ibalp_simpterm(env, v137);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    v137 = ncons(v137);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    v137 = Lrplacd(nil, stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    v137 = stack[-1];
    v137 = qcdr(v137);
    stack[-1] = v137;
    goto v119;

v140:
    v137 = stack[-2];
    goto v141;

v141:
    {
        Lisp_Object v107 = stack[-4];
        popv(6);
        return cons(v107, v137);
    }

v124:
    v137 = qvalue(elt(env, 1)); /* nil */
    goto v141;

v139:
    v137 = stack[0];
    fn = elt(env, 4); /* reval */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    stack[0] = v137;
    v138 = stack[0];
    v137 = stack[-1];
    if (!consp(v138)) goto v90;
    v138 = qcar(v138);
    if (!(v138 == v137)) goto v90;
    v138 = stack[-1];
    v137 = elt(env, 2); /* "Boolean function" */
    fn = elt(env, 5); /* typerr */
    v137 = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    goto v90;

v90:
    v137 = stack[0];
    stack[0] = v137;
    goto v123;

v9:
    v137 = stack[0];
    {
        popv(6);
        fn = elt(env, 6); /* ibalp_simpatom */
        return (*qfn1(fn))(qenv(fn), v137);
    }
/* error exit handlers */
v82:
    popv(6);
    return nil;
}



/* Code for ratpoly_nullp */

static Lisp_Object CC_ratpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v143;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v125 = v0;
/* end of prologue */
    v143 = v125;
    v143 = qcar(v143);
    v143 = (v143 == nil ? lisp_true : nil);
    if (!(v143 == nil)) return onevalue(v143);
    v143 = qcar(v125);
    v125 = (Lisp_Object)1; /* 0 */
    v125 = (v143 == v125 ? lisp_true : nil);
    return onevalue(v125);
}



/* Code for vbcgcd */

static Lisp_Object CC_vbcgcd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcgcd");
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
    v156 = stack[-1];
    v84 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 2); /* vbcsize */
    v84 = (*qfn2(fn))(qenv(fn), v156, v84);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    if (v84 == nil) goto v2;
    v156 = stack[0];
    v84 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 2); /* vbcsize */
    v84 = (*qfn2(fn))(qenv(fn), v156, v84);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    if (v84 == nil) goto v2;
    v84 = stack[-1];
    v156 = qcdr(v84);
    v84 = (Lisp_Object)17; /* 1 */
    if (!(v156 == v84)) goto v107;
    v84 = stack[0];
    v156 = qcdr(v84);
    v84 = (Lisp_Object)17; /* 1 */
    if (!(v156 == v84)) goto v107;
    v84 = stack[-1];
    v84 = qcar(v84);
    v84 = integerp(v84);
    if (v84 == nil) goto v157;
    v84 = stack[0];
    v84 = qcar(v84);
    v84 = integerp(v84);
    if (v84 == nil) goto v157;
    v84 = stack[-1];
    v156 = qcar(v84);
    v84 = stack[0];
    v84 = qcar(v84);
    v156 = Lgcd(nil, v156, v84);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v84 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v156, v84);

v157:
    v84 = stack[-1];
    v156 = qcar(v84);
    v84 = stack[0];
    v84 = qcar(v84);
    fn = elt(env, 3); /* gcdf!* */
    v156 = (*qfn2(fn))(qenv(fn), v156, v84);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v84 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v156, v84);

v107:
    v156 = (Lisp_Object)17; /* 1 */
    v84 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v156, v84);

v2:
    v84 = elt(env, 1); /* (1 . 1) */
    { popv(3); return onevalue(v84); }
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for vdpred */

static Lisp_Object CC_vdpred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpred");
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
    v147 = stack[-3];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v147 = qcar(v147);
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    stack[-4] = v147;
    v147 = stack[-4];
    if (v147 == nil) goto v117;
    stack[-2] = elt(env, 1); /* vdp */
    v147 = stack[-4];
    stack[-1] = qcar(v147);
    v147 = stack[-4];
    v147 = qcdr(v147);
    stack[0] = qcar(v147);
    v157 = stack[-4];
    v147 = qvalue(elt(env, 2)); /* nil */
    v147 = list2(v157, v147);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-5];
    v147 = list3star(stack[-2], stack[-1], stack[0], v147);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-5];
    stack[-4] = v147;
    v147 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v147 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v157 = stack[-3];
    v147 = elt(env, 4); /* sugar */
    fn = elt(env, 5); /* vdpgetprop */
    v157 = (*qfn2(fn))(qenv(fn), v157, v147);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-5];
    v147 = v157;
    if (v157 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v157 = stack[-4];
    fn = elt(env, 6); /* gsetsugar */
    v147 = (*qfn2(fn))(qenv(fn), v157, v147);
    nil = C_nil;
    if (exception_pending()) goto v138;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v117:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v147 = qvalue(elt(env, 2)); /* nil */
    stack[0] = ncons(v147);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-5];
    v157 = qvalue(elt(env, 2)); /* nil */
    v147 = qvalue(elt(env, 2)); /* nil */
    v147 = list2(v157, v147);
    nil = C_nil;
    if (exception_pending()) goto v138;
    {
        Lisp_Object v164 = stack[-2];
        Lisp_Object v148 = stack[-1];
        Lisp_Object v146 = stack[0];
        popv(6);
        return list3star(v164, v148, v146, v147);
    }
/* error exit handlers */
v138:
    popv(6);
    return nil;
}



/* Code for termordp!! */

static Lisp_Object CC_termordpB(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v97, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp!");
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
    v98 = v0;
/* end of prologue */
    v97 = v98;
    v136 = stack[0];
    if (equal(v97, v136)) goto v16;
    v136 = v98;
    fn = elt(env, 2); /* guesspftype */
    stack[-1] = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-2];
    v136 = stack[0];
    fn = elt(env, 2); /* guesspftype */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-2];
    {
        Lisp_Object v121 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* termordp */
        return (*qfn2(fn))(qenv(fn), v121, v136);
    }

v16:
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v136); }
/* error exit handlers */
v119:
    popv(3);
    return nil;
}



/* Code for !*sqprint */

static Lisp_Object CC_Hsqprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sqprint");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v0;
/* end of prologue */
    v38 = qcdr(v38);
    v38 = qcar(v38);
    {
        fn = elt(env, 1); /* sqprint */
        return (*qfn1(fn))(qenv(fn), v38);
    }
}



/* Code for rd!:plus */

static Lisp_Object CC_rdTplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v183, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:plus");
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
    stack[0] = v0;
/* end of prologue */
    v182 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (!(v182 == nil)) goto v184;
    v182 = stack[0];
    v182 = qcdr(v182);
    if (!(!consp(v182))) goto v184;
    v182 = stack[-1];
    v182 = qcdr(v182);
    if (!(!consp(v182))) goto v184;
    v182 = stack[0];
    v183 = qcdr(v182);
    v182 = stack[-1];
    v182 = qcdr(v182);
    fn = elt(env, 7); /* safe!-fp!-plus */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    v183 = v182;
    if (v182 == nil) goto v184;
    v182 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v182, v183);

v184:
    v183 = stack[0];
    v182 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    stack[-3] = v182;
    v182 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v182;
    v182 = stack[-3];
    if (!consp(v182)) goto v91;
    v183 = stack[-3];
    v182 = stack[-2];
    fn = elt(env, 9); /* plubf */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v161;

v161:
    stack[0] = v182;
    v60 = stack[0];
    v183 = stack[-3];
    v182 = stack[-2];
    fn = elt(env, 10); /* rdzchk */
    v182 = (*qfnn(fn))(qenv(fn), 3, v60, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    v183 = v182;
    v182 = v183;
    if (!(!consp(v182))) { popv(5); return onevalue(v183); }
    v182 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v182, v183);

v91:
    stack[-1] = elt(env, 5); /* plus2 */
    v182 = stack[-3];
    stack[0] = Lmkquote(nil, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    v182 = stack[-2];
    v182 = Lmkquote(nil, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    v60 = list3(stack[-1], stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    v183 = qvalue(elt(env, 1)); /* nil */
    v182 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v182 = (*qfnn(fn))(qenv(fn), 3, v60, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    v183 = v182;
    v182 = v183;
    if (!consp(v182)) goto v128;
    v182 = v183;
    v182 = qcdr(v182);
    if (!(v182 == nil)) goto v128;
    v182 = v183;
    v182 = qcar(v182);
    goto v161;

v128:
    fn = elt(env, 12); /* rndbfon */
    v182 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    v182 = stack[-3];
    v182 = Lfloatp(nil, v182);
    env = stack[-4];
    if (v182 == nil) goto v186;
    v182 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    stack[0] = v182;
    goto v187;

v187:
    stack[-3] = stack[0];
    v182 = stack[-2];
    v182 = Lfloatp(nil, v182);
    env = stack[-4];
    if (v182 == nil) goto v188;
    v182 = stack[-2];
    fn = elt(env, 13); /* fl2bf */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v189;

v189:
    stack[-2] = v182;
    fn = elt(env, 9); /* plubf */
    v182 = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v161;

v188:
    v182 = stack[-2];
    if (!consp(v182)) goto v190;
    v182 = stack[-2];
    goto v191;

v191:
    fn = elt(env, 14); /* csl_normbf */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v189;

v190:
    v182 = stack[-2];
    v182 = integerp(v182);
    if (v182 == nil) goto v192;
    v60 = elt(env, 3); /* !:rd!: */
    v183 = stack[-2];
    v182 = (Lisp_Object)1; /* 0 */
    v182 = list2star(v60, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v191;

v192:
    v182 = stack[-2];
    fn = elt(env, 15); /* read!:num */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v191;

v186:
    v182 = stack[-3];
    if (!consp(v182)) goto v193;
    v182 = stack[-3];
    goto v194;

v194:
    fn = elt(env, 14); /* csl_normbf */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    stack[0] = v182;
    goto v187;

v193:
    v182 = stack[-3];
    v182 = integerp(v182);
    if (v182 == nil) goto v195;
    v60 = elt(env, 3); /* !:rd!: */
    v183 = stack[-3];
    v182 = (Lisp_Object)1; /* 0 */
    v182 = list2star(v60, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v194;

v195:
    v182 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-4];
    goto v194;
/* error exit handlers */
v185:
    popv(5);
    return nil;
}



/* Code for physopaeval */

static Lisp_Object CC_physopaeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v199, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopaeval");
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
    v198 = stack[0];
    fn = elt(env, 6); /* physopp */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    if (v198 == nil) goto v2;
    v199 = stack[0];
    v198 = elt(env, 1); /* rvalue */
    v198 = get(v199, v198);
    env = stack[-1];
    v200 = v198;
    if (v198 == nil) goto v142;
    v198 = v200;
    v199 = qcar(v198);
    v198 = elt(env, 2); /* !*sq */
    if (!(v199 == v198)) { popv(2); return onevalue(v200); }
    v198 = qvalue(elt(env, 3)); /* !*nosq */
    if (v198 == nil) goto v124;
    v198 = v200;
    v198 = qcdr(v198);
    v198 = qcar(v198);
    {
        popv(2);
        fn = elt(env, 7); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v198);
    }

v124:
    v198 = v200;
    v198 = qcdr(v198);
    v198 = qcar(v198);
    {
        popv(2);
        fn = elt(env, 8); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v198);
    }

v142:
    v198 = stack[0];
    if (!consp(v198)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v198 = stack[0];
    v199 = qcar(v198);
    v198 = elt(env, 4); /* psimpfn */
    v198 = get(v199, v198);
    env = stack[-1];
    v200 = v198;
    if (v198 == nil) goto v202;
    v199 = v200;
    v198 = stack[0];
        popv(2);
        return Lapply1(nil, v199, v198);

v202:
    v198 = stack[0];
    v199 = qcar(v198);
    v198 = elt(env, 5); /* opmtch */
    v198 = get(v199, v198);
    env = stack[-1];
    if (v198 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v198 = stack[0];
    fn = elt(env, 9); /* opmtch!* */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    v200 = v198;
    if (v198 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v200); }

v2:
    v198 = stack[0];
    if (!consp(v198)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v198 = stack[0];
    v199 = qcar(v198);
    v198 = elt(env, 2); /* !*sq */
    if (!(v199 == v198)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v198 = qvalue(elt(env, 3)); /* !*nosq */
    if (v198 == nil) goto v84;
    v198 = stack[0];
    v198 = qcdr(v198);
    v198 = qcar(v198);
    {
        popv(2);
        fn = elt(env, 7); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v198);
    }

v84:
    v198 = stack[0];
    v198 = qcdr(v198);
    v198 = qcar(v198);
    {
        popv(2);
        fn = elt(env, 8); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v198);
    }
/* error exit handlers */
v201:
    popv(2);
    return nil;
}



/* Code for assert_install */

static Lisp_Object CC_assert_install(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_install");
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
    v133 = v0;
/* end of prologue */
    v127 = qvalue(elt(env, 1)); /* !*assert */
    if (v127 == nil) goto v16;
    v127 = v133;
    stack[0] = v127;
    goto v105;

v105:
    v127 = stack[0];
    if (v127 == nil) goto v142;
    v127 = stack[0];
    v127 = qcar(v127);
    fn = elt(env, 3); /* assert_install1 */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    v127 = stack[0];
    v127 = qcdr(v127);
    stack[0] = v127;
    goto v105;

v142:
    v127 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v127); }

v16:
    v127 = nil;
    { popv(2); return onevalue(v127); }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for pv_intequiv */

static Lisp_Object CC_pv_intequiv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v142;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_intequiv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v142 = v0;
/* end of prologue */
    v166 = v142;
    v166 = qcdr(v166);
    if (!consp(v166)) goto v3;
    v166 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v166);

v3:
    v166 = v142;
    v166 = qcdr(v166);
    return onevalue(v166);
}



/* Code for splitlist!: */

static Lisp_Object CC_splitlistT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v155, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitlist:");
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
    v106 = nil;
    goto v38;

v38:
    v154 = stack[-1];
    if (v154 == nil) goto v109;
    v154 = stack[-1];
    v155 = qcar(v154);
    v154 = stack[0];
    if (!consp(v155)) goto v203;
    v155 = qcar(v155);
    if (!(v155 == v154)) goto v203;
    v154 = stack[-1];
    v154 = qcar(v154);
    v155 = v106;
    v154 = cons(v154, v155);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-2];
    v106 = v154;
    v154 = stack[-1];
    v154 = qcdr(v154);
    stack[-1] = v154;
    goto v38;

v203:
    v154 = stack[-1];
    v154 = qcdr(v154);
    stack[-1] = v154;
    goto v38;

v109:
    v154 = v106;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v154);
    }
/* error exit handlers */
v204:
    popv(3);
    return nil;
}



/* Code for wtchk */

static Lisp_Object CC_wtchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v86, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wtchk");
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
    v157 = stack[-1];
    if (v157 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v157 = stack[-2];
    stack[-3] = ncons(v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    stack[0] = elt(env, 1); /* k!* */
    v86 = stack[-1];
    v157 = stack[-2];
    v157 = qcar(v157);
    v157 = qcdr(v157);
    v86 = times2(v86, v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v157 = (Lisp_Object)17; /* 1 */
    v157 = acons(stack[0], v86, v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v157 = ncons(v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    fn = elt(env, 10); /* quotf */
    v157 = (*qfn2(fn))(qenv(fn), stack[-3], v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v86 = v157;
    v157 = v86;
    if (v157 == nil) goto v184;
    v157 = v86;
    v157 = qcar(v157);
    { popv(5); return onevalue(v157); }

v184:
    v157 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 11); /* terpri!* */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v157 = elt(env, 3); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 12); /* lprie */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v128 = elt(env, 4); /* "weight confusion" */
    v86 = stack[-2];
    v157 = stack[-1];
    v157 = list3(v128, v86, v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    fn = elt(env, 13); /* printty */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v86 = elt(env, 5); /* " " */
    v157 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 14); /* lpriw */
    v157 = (*qfn2(fn))(qenv(fn), v86, v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v157 = elt(env, 7); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v86 = v157;
    v157 = v86;
    qvalue(elt(env, 8)) = v157; /* errmsg!* */
    v157 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v157 == nil)) goto v152;
    v157 = v86;
    fn = elt(env, 12); /* lprie */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    goto v152;

v152:
    v157 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v157 = nil;
    { popv(5); return onevalue(v157); }
/* error exit handlers */
v164:
    popv(5);
    return nil;
}



/* Code for exptcompare */

static Lisp_Object CC_exptcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v155, v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptcompare");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v155 = v1;
    v106 = v0;
/* end of prologue */
    v154 = v106;
    if (!consp(v154)) goto v16;
    v154 = v155;
    if (!consp(v154)) goto v141;
    v154 = v106;
    v154 = qcar(v154);
    v155 = qcar(v155);
        return Lgreaterp(nil, v154, v155);

v141:
    v154 = qvalue(elt(env, 2)); /* t */
    return onevalue(v154);

v16:
    v154 = v155;
    if (!consp(v154)) goto v142;
    v154 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v154);

v142:
    v154 = v106;
        return Lgreaterp(nil, v154, v155);
}



/* Code for qqe_number!-of!-adds!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKaddsKinKqterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_number-of-adds-in-qterm");
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

v3:
    v132 = stack[0];
    if (!consp(v132)) goto v9;
    v132 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v120 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    v132 = elt(env, 1); /* (ladd radd) */
    v132 = Lmemq(nil, v120, v132);
    if (v132 == nil) goto v133;
    v132 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    v132 = CC_qqe_numberKofKaddsKinKqterm(env, v132);
    nil = C_nil;
    if (exception_pending()) goto v121;
    popv(2);
    return add1(v132);

v133:
    v132 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    stack[0] = v132;
    goto v3;

v9:
    v132 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v132); }
/* error exit handlers */
v121:
    popv(2);
    return nil;
}



/* Code for sq2sspl */

static Lisp_Object CC_sq2sspl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sspl");
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
    goto v9;

v9:
    v160 = stack[-1];
    if (!consp(v160)) goto v2;
    v160 = stack[-1];
    v160 = qcar(v160);
    if (!consp(v160)) goto v2;
    v160 = stack[-1];
    v88 = qcar(v160);
    v160 = stack[0];
    fn = elt(env, 1); /* sq2sstm */
    v88 = (*qfn2(fn))(qenv(fn), v88, v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v160 = stack[-2];
    v160 = cons(v88, v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    stack[-2] = v160;
    v160 = stack[-1];
    v160 = qcdr(v160);
    stack[-1] = v160;
    goto v9;

v2:
    v160 = stack[-1];
    v88 = v160;
    goto v109;

v109:
    v160 = stack[-2];
    if (v160 == nil) { popv(4); return onevalue(v88); }
    v160 = stack[-2];
    v160 = qcar(v160);
    v160 = Lappend(nil, v160, v88);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v88 = v160;
    v160 = stack[-2];
    v160 = qcdr(v160);
    stack[-2] = v160;
    goto v109;
/* error exit handlers */
v207:
    popv(4);
    return nil;
}



/* Code for ibalp_clauselp */

static Lisp_Object CC_ibalp_clauselp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clauselp");
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

v123:
    v118 = stack[0];
    v118 = (v118 == nil ? lisp_true : nil);
    if (!(v118 == nil)) { popv(2); return onevalue(v118); }
    v118 = stack[0];
    v118 = qcar(v118);
    fn = elt(env, 2); /* ibalp_clausep */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-1];
    if (v118 == nil) goto v109;
    v118 = stack[0];
    v118 = qcdr(v118);
    stack[0] = v118;
    goto v123;

v109:
    v118 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v118); }
/* error exit handlers */
v126:
    popv(2);
    return nil;
}



/* Code for aex_lc */

static Lisp_Object CC_aex_lc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v203, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_lc");
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
    v181 = v1;
    stack[0] = v0;
/* end of prologue */
    v203 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v181 = (*qfn2(fn))(qenv(fn), v203, v181);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    if (v181 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v181 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_lc */
    stack[-1] = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    v181 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v124 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    v203 = qvalue(elt(env, 1)); /* nil */
    v181 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v155 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v155, v124, v203, v181);
    }
/* error exit handlers */
v154:
    popv(3);
    return nil;
}



/* Code for nary */

static Lisp_Object CC_nary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nary");
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
    v134 = stack[-1];
    v135 = qcar(v134);
    v134 = elt(env, 1); /* e */
    if (!(v135 == v134)) goto v181;
    v135 = stack[0];
    v134 = elt(env, 2); /* power */
    if (!(v135 == v134)) goto v181;
    v134 = stack[-1];
    v135 = qcdr(v134);
    v134 = elt(env, 3); /* exp */
    fn = elt(env, 10); /* unary */
    v134 = (*qfn2(fn))(qenv(fn), v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    goto v38;

v38:
    v134 = nil;
    { popv(3); return onevalue(v134); }

v181:
    v134 = elt(env, 4); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v134 = elt(env, 5); /* "<" */
    v134 = Lprinc(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v134 = stack[0];
    v134 = Lprinc(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v134 = stack[-1];
    v135 = qcar(v134);
    v134 = elt(env, 6); /* "/" */
    fn = elt(env, 12); /* attributesml */
    v134 = (*qfn2(fn))(qenv(fn), v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v134 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* indent!* */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v134 = stack[-1];
    v134 = qcdr(v134);
    fn = elt(env, 14); /* multi_elem */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v134 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v134 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v94;
    goto v38;
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for ldt!-tvar */

static Lisp_Object CC_ldtKtvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v127, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v141 = v0;
/* end of prologue */
    v141 = qcar(v141);
    v141 = qcar(v141);
    v127 = v141;
    v141 = v127;
    v133 = elt(env, 1); /* df */
    if (!consp(v141)) return onevalue(v127);
    v141 = qcar(v141);
    if (!(v141 == v133)) return onevalue(v127);
    v141 = v127;
    v141 = qcdr(v141);
    v141 = qcar(v141);
    return onevalue(v141);
}



/* Code for spquotematrix */

static Lisp_Object CC_spquotematrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v48;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spquotematrix");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v48 = v0;
/* end of prologue */
    v48 = elt(env, 1); /* sparse */
    return onevalue(v48);
}



/* Code for dm!-minus */

static Lisp_Object CC_dmKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-minus");
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
    v16 = v0;
/* end of prologue */
    fn = elt(env, 1); /* !:minus */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v16);
    }
/* error exit handlers */
v38:
    popv(1);
    return nil;
}



/* Code for chk */

static Lisp_Object CC_chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v180, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chk");
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

v123:
    v90 = stack[0];
    v90 = (v90 == nil ? lisp_true : nil);
    if (!(v90 == nil)) { popv(3); return onevalue(v90); }
    v180 = stack[0];
    v90 = qvalue(elt(env, 1)); /* t */
    v90 = (v180 == v90 ? lisp_true : nil);
    if (!(v90 == nil)) { popv(3); return onevalue(v90); }
    v90 = stack[0];
    v90 = qcar(v90);
    fn = elt(env, 3); /* bsubs */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    stack[-1] = v90;
    v90 = stack[-1];
    fn = elt(env, 4); /* freexp */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    if (v90 == nil) goto v211;
    v90 = stack[0];
    v90 = qcdr(v90);
    v90 = CC_chk(env, v90);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    v180 = v90;
    v90 = v180;
    if (v90 == nil) goto v119;
    v90 = v180;
    v91 = qvalue(elt(env, 1)); /* t */
    if (v90 == v91) goto v203;
    v90 = stack[-1];
    popv(3);
    return cons(v90, v180);

v203:
    v90 = stack[-1];
    popv(3);
    return ncons(v90);

v119:
    v90 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v90); }

v211:
    v90 = stack[-1];
    fn = elt(env, 5); /* reval */
    v180 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    v90 = qvalue(elt(env, 1)); /* t */
    if (v180 == v90) goto v212;
    v90 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v90); }

v212:
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[0] = v90;
    goto v123;
/* error exit handlers */
v152:
    popv(3);
    return nil;
}



/* Code for vdpzero */

static Lisp_Object MS_CDECL CC_vdpzero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpzero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpzero");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v48 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* a2vdp */
        return (*qfn1(fn))(qenv(fn), v48);
    }
}



/* Code for vdpputprop */

static Lisp_Object MS_CDECL CC_vdpputprop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v129, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v107, v214, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpputprop");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpputprop");
#endif
    if (stack >= stacklimit)
    {
        push3(v129,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v129);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v129;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v82 = stack[-3];
    v82 = Lconsp(nil, v82);
    env = stack[-5];
    if (v82 == nil) goto v119;
    v82 = stack[-3];
    v82 = qcdr(v82);
    stack[-4] = v82;
    v82 = Lconsp(nil, v82);
    env = stack[-5];
    if (v82 == nil) goto v119;
    v82 = stack[-4];
    v82 = qcdr(v82);
    stack[-4] = v82;
    v82 = Lconsp(nil, v82);
    env = stack[-5];
    if (v82 == nil) goto v119;
    v82 = stack[-4];
    v82 = qcdr(v82);
    stack[-4] = v82;
    v82 = Lconsp(nil, v82);
    env = stack[-5];
    if (v82 == nil) goto v119;
    v82 = stack[-4];
    v82 = qcdr(v82);
    stack[-4] = v82;
    v82 = Lconsp(nil, v82);
    env = stack[-5];
    if (!(v82 == nil)) goto v212;

v119:
    v215 = elt(env, 1); /* "vdpputprop given a non-vdp as 1st parameter" 
*/
    v214 = stack[-3];
    v107 = stack[-2];
    v82 = stack[-1];
    v82 = list4(v215, v214, v107, v82);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-5];
    v107 = v82;
    v82 = v107;
    qvalue(elt(env, 2)) = v82; /* errmsg!* */
    v82 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v82 == nil)) goto v153;
    v82 = v107;
    fn = elt(env, 4); /* lprie */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-5];
    goto v153;

v153:
    v82 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-5];
    goto v212;

v212:
    v107 = stack[-2];
    v82 = stack[-4];
    v82 = qcar(v82);
    v82 = Lassoc(nil, v107, v82);
    v107 = v82;
    v82 = v107;
    if (v82 == nil) goto v131;
    v82 = stack[-1];
    v82 = Lrplacd(nil, v107, v82);
    nil = C_nil;
    if (exception_pending()) goto v84;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v131:
    stack[0] = stack[-4];
    v214 = stack[-2];
    v107 = stack[-1];
    v82 = stack[-4];
    v82 = qcar(v82);
    v82 = acons(v214, v107, v82);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-5];
    v82 = Lrplaca(nil, stack[0], v82);
    nil = C_nil;
    if (exception_pending()) goto v84;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
/* error exit handlers */
v84:
    popv(6);
    return nil;
}



/* Code for repasc */

static Lisp_Object MS_CDECL CC_repasc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v129, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v179, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "repasc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repasc");
#endif
    if (stack >= stacklimit)
    {
        push3(v129,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v129);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v129;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v147 = nil;
    goto v9;

v9:
    v87 = stack[0];
    if (v87 == nil) goto v142;
    v179 = stack[-2];
    v87 = stack[0];
    v87 = qcar(v87);
    v87 = qcar(v87);
    if (equal(v179, v87)) goto v160;
    v87 = stack[0];
    v87 = qcar(v87);
    v179 = v147;
    v87 = cons(v87, v179);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    v147 = v87;
    v87 = stack[0];
    v87 = qcdr(v87);
    stack[0] = v87;
    goto v9;

v160:
    stack[-3] = v147;
    v147 = stack[-2];
    v179 = stack[-1];
    v87 = stack[0];
    v87 = qcdr(v87);
    v87 = acons(v147, v179, v87);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    {
        Lisp_Object v137 = stack[-3];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v137, v87);
    }

v142:
    stack[0] = v147;
    v147 = elt(env, 1); /* "key" */
    v179 = stack[-2];
    v87 = elt(env, 2); /* "not found" */
    v87 = list3(v147, v179, v87);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    v179 = v87;
    v87 = v179;
    qvalue(elt(env, 3)) = v87; /* errmsg!* */
    v87 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v87 == nil)) goto v203;
    v87 = v179;
    fn = elt(env, 6); /* lprie */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    goto v203;

v203:
    v87 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    v87 = nil;
    {
        Lisp_Object v138 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v138, v87);
    }
/* error exit handlers */
v218:
    popv(5);
    return nil;
}



/* Code for putd */

static Lisp_Object MS_CDECL CC_putd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v129, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v174, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "putd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putd");
#endif
    if (stack >= stacklimit)
    {
        push3(v129,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v129);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v129;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v174 = stack[0];
    v229 = elt(env, 1); /* funarg */
    if (!consp(v174)) goto v16;
    v174 = qcar(v174);
    if (!(v174 == v229)) goto v16;
    v174 = elt(env, 2); /* lambda */
    v229 = stack[0];
    v229 = qcdr(v229);
    v229 = qcdr(v229);
    v229 = cons(v174, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    stack[0] = v229;
    goto v16;

v16:
    v229 = stack[-2];
    if (!symbolp(v229)) v229 = nil;
    else { v229 = qfastgets(v229);
           if (v229 != nil) { v229 = elt(v229, 1); /* lose */
#ifdef RECORD_GET
             if (v229 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v229 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v229 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v229 == SPID_NOPROP) v229 = nil; else v229 = lisp_true; }}
#endif
    if (v229 == nil) goto v154;
    v229 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    v229 = elt(env, 3); /* "+++ " */
    v229 = Lprinc(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    v229 = stack[-2];
    v229 = Lprin(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    v229 = elt(env, 4); /* " not defined (LOSE flag)" */
    v229 = Lprintc(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    v229 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v229); }

v154:
    v229 = qvalue(elt(env, 6)); /* !*redefmsg */
    if (v229 == nil) goto v135;
    v229 = stack[-2];
    fn = elt(env, 15); /* getd */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    if (v229 == nil) goto v135;
    v229 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    v229 = elt(env, 3); /* "+++ " */
    v229 = Lprinc(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    v229 = stack[-2];
    v229 = Lprin(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    v229 = elt(env, 7); /* " redefined" */
    v229 = Lprintc(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    goto v135;

v135:
    v174 = stack[-1];
    v229 = elt(env, 8); /* expr */
    if (v174 == v229) goto v205;
    v174 = stack[-1];
    v229 = elt(env, 9); /* subr */
    if (v174 == v229) goto v179;
    v174 = stack[-1];
    v229 = elt(env, 10); /* macro */
    if (!(v174 == v229)) goto v231;
    v174 = stack[0];
    v229 = elt(env, 2); /* lambda */
    if (!consp(v174)) goto v231;
    v174 = qcar(v174);
    if (!(v174 == v229)) goto v231;
    v67 = elt(env, 11); /* dm */
    v174 = stack[-2];
    v229 = stack[0];
    v229 = qcdr(v229);
    v229 = list2star(v67, v174, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v231:
    v174 = stack[-1];
    v229 = elt(env, 12); /* fexpr */
    if (!(v174 == v229)) goto v71;
    v174 = stack[0];
    v229 = elt(env, 2); /* lambda */
    if (!consp(v174)) goto v71;
    v174 = qcar(v174);
    if (!(v174 == v229)) goto v71;
    v67 = elt(env, 13); /* df */
    v174 = stack[-2];
    v229 = stack[0];
    v229 = qcdr(v229);
    v229 = list2star(v67, v174, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v71:
    v174 = elt(env, 14); /* "Bad type ~S in putd" */
    v229 = stack[-1];
    fn = elt(env, 17); /* error */
    v229 = (*qfn2(fn))(qenv(fn), v174, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v179:
    v174 = stack[-2];
    v229 = stack[0];
    v229 = Lsymbol_set_definition(nil, v174, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v205:
    v174 = stack[-2];
    v229 = stack[0];
    v229 = Lsymbol_set_definition(nil, v174, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v230:
    popv(4);
    return nil;
}



/* Code for evalequal */

static Lisp_Object CC_evalequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v160, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalequal");
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
    v232 = stack[-2];
    fn = elt(env, 3); /* getrtype */
    stack[0] = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[-3] = stack[0];
    v232 = stack[-1];
    fn = elt(env, 3); /* getrtype */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    if (equal(stack[0], v232)) goto v109;
    v232 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v232); }

v109:
    v232 = stack[-3];
    if (v232 == nil) goto v98;
    v160 = stack[-2];
    v232 = stack[-1];
    v232 = (equal(v160, v232) ? lisp_true : nil);
    { popv(5); return onevalue(v232); }

v98:
    v88 = elt(env, 2); /* difference */
    v160 = stack[-2];
    v232 = stack[-1];
    v232 = list3(v88, v160, v232);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    fn = elt(env, 4); /* reval */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[-3] = v232;
    if (is_number(v232)) goto v154;
    v232 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v232); }

v154:
    v232 = stack[-3];
        popv(5);
        return Lzerop(nil, v232);
/* error exit handlers */
v134:
    popv(5);
    return nil;
}



/* Code for sf2mv1 */

static Lisp_Object MS_CDECL CC_sf2mv1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v129, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v144, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sf2mv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2mv1");
#endif
    if (stack >= stacklimit)
    {
        push3(v129,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v129);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v129;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v38:
    v145 = stack[-3];
    if (v145 == nil) goto v109;
    v145 = stack[-3];
    if (!consp(v145)) goto v97;
    v145 = stack[-3];
    v145 = qcar(v145);
    if (!consp(v145)) goto v97;
    v145 = stack[-3];
    v145 = qcar(v145);
    v145 = qcar(v145);
    v144 = qcar(v145);
    v145 = stack[-1];
    v145 = qcar(v145);
    if (equal(v144, v145)) goto v235;
    stack[0] = stack[-2];
    v145 = (Lisp_Object)1; /* 0 */
    v145 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v145 = Lappend(nil, stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    stack[-2] = v145;
    v145 = stack[-1];
    v145 = qcdr(v145);
    stack[-1] = v145;
    goto v38;

v235:
    v145 = stack[-3];
    v145 = qcar(v145);
    stack[-4] = qcdr(v145);
    stack[0] = stack[-2];
    v145 = stack[-3];
    v145 = qcar(v145);
    v145 = qcar(v145);
    v145 = qcdr(v145);
    v145 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v144 = Lappend(nil, stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v145 = stack[-1];
    v145 = qcdr(v145);
    stack[0] = CC_sf2mv1(env, 3, stack[-4], v144, v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v145 = stack[-3];
    v234 = qcdr(v145);
    v144 = stack[-2];
    v145 = stack[-1];
    v145 = CC_sf2mv1(env, 3, v234, v144, v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    {
        Lisp_Object v175 = stack[0];
        popv(6);
        return Lappend(nil, v175, v145);
    }

v97:
    stack[0] = stack[-2];
    v145 = stack[-1];
    v145 = Llength(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    fn = elt(env, 2); /* nzeros */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v144 = Lappend(nil, stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v145 = stack[-3];
    v145 = cons(v144, v145);
    nil = C_nil;
    if (exception_pending()) goto v83;
    popv(6);
    return ncons(v145);

v109:
    v145 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v145); }
/* error exit handlers */
v83:
    popv(6);
    return nil;
}



/* Code for bc_inv */

static Lisp_Object CC_bc_inv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_inv");
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
    v96 = v92;
    v95 = (Lisp_Object)17; /* 1 */
    if (v96 == v95) { popv(1); return onevalue(v92); }
    v96 = v92;
    v95 = (Lisp_Object)-15; /* -1 */
    if (v96 == v95) { popv(1); return onevalue(v92); }
    v95 = (Lisp_Object)17; /* 1 */
    v96 = v92;
    fn = elt(env, 2); /* qremf */
    v95 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[0];
    v96 = v95;
    v95 = v96;
    v95 = qcdr(v95);
    if (v95 == nil) goto v184;
    v95 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v95); }

v184:
    v95 = v96;
    v95 = qcar(v95);
    { popv(1); return onevalue(v95); }
/* error exit handlers */
v153:
    popv(1);
    return nil;
}



/* Code for gperm0 */

static Lisp_Object CC_gperm0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm0");
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
    v103 = v0;
/* end of prologue */
    v126 = v103;
    if (v126 == nil) goto v3;
    v126 = v103;
    stack[0] = qcdr(v126);
    v126 = v103;
    v126 = qcar(v126);
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    {
        Lisp_Object v133 = stack[0];
        popv(2);
        fn = elt(env, 2); /* gperm3 */
        return (*qfn2(fn))(qenv(fn), v133, v126);
    }

v3:
    v126 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v126); }
/* error exit handlers */
v127:
    popv(2);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_cambhead");
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

v123:
    v184 = stack[0];
    fn = elt(env, 4); /* listp */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    if (v184 == nil) goto v16;
    v184 = stack[0];
    stack[-1] = qcar(v184);
    v210 = elt(env, 1); /* expt */
    v184 = elt(env, 2); /* minus */
    v184 = list2(v210, v184);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    v184 = Lmember(nil, stack[-1], v184);
    if (v184 == nil) goto v236;
    v184 = stack[0];
    v184 = qcdr(v184);
    v184 = qcar(v184);
    stack[0] = v184;
    goto v123;

v236:
    v184 = stack[0];
    fn = elt(env, 4); /* listp */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v95;
    if (v184 == nil) goto v16;
    v184 = stack[0];
    v184 = qcar(v184);
    { popv(3); return onevalue(v184); }

v16:
    v184 = nil;
    { popv(3); return onevalue(v184); }
/* error exit handlers */
v95:
    popv(3);
    return nil;
}



/* Code for expt!-mod!-p */

static Lisp_Object CC_exptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v152, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-mod-p");
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
    v149 = v1;
    stack[0] = v0;
/* end of prologue */
    v152 = v149;
    v159 = (Lisp_Object)1; /* 0 */
    if (v152 == v159) goto v16;
    v152 = v149;
    v159 = (Lisp_Object)17; /* 1 */
    if (v152 == v159) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v152 = v149;
    v159 = (Lisp_Object)33; /* 2 */
    v159 = Ldivide(nil, v152, v159);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    stack[-1] = v159;
    v152 = stack[0];
    v159 = stack[-1];
    v159 = qcar(v159);
    v159 = CC_exptKmodKp(env, v152, v159);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v149 = v159;
    v159 = v149;
    v152 = v149;
    fn = elt(env, 1); /* times!-mod!-p */
    v159 = (*qfn2(fn))(qenv(fn), v159, v152);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v149 = v159;
    v159 = stack[-1];
    v152 = qcdr(v159);
    v159 = (Lisp_Object)1; /* 0 */
    if (v152 == v159) { popv(3); return onevalue(v149); }
    v152 = v149;
    v159 = stack[0];
    fn = elt(env, 1); /* times!-mod!-p */
    v159 = (*qfn2(fn))(qenv(fn), v152, v159);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v149 = v159;
    { popv(3); return onevalue(v149); }

v16:
    v159 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v159); }
/* error exit handlers */
v131:
    popv(3);
    return nil;
}



/* Code for qqe_simplat1 */

static Lisp_Object CC_qqe_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v232, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplat1");
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
    v217 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v217 = (*qfn1(fn))(qenv(fn), v217);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v160 = v217;
    v232 = v160;
    v217 = elt(env, 1); /* (qequal qneq) */
    v217 = Lmemq(nil, v232, v217);
    if (v217 == nil) goto v117;
    v232 = v160;
    v217 = elt(env, 2); /* qequal */
    if (v232 == v217) goto v203;
    v232 = stack[-1];
    v217 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_simplqneq */
        return (*qfn2(fn))(qenv(fn), v232, v217);
    }

v203:
    v232 = stack[-1];
    v217 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* qqe_simplqequal */
        return (*qfn2(fn))(qenv(fn), v232, v217);
    }

v117:
    v232 = stack[-1];
    v217 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* qqe_simplbtat */
        return (*qfn2(fn))(qenv(fn), v232, v217);
    }
/* error exit handlers */
v235:
    popv(3);
    return nil;
}



/* Code for sf2ss */

static Lisp_Object CC_sf2ss(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2ss");
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
    v95 = stack[-1];
    if (!consp(v95)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v95 = stack[-1];
    v95 = qcar(v95);
    if (!consp(v95)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v95 = stack[-1];
    fn = elt(env, 1); /* searchpl */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[-2] = v95;
    v95 = stack[-2];
    fn = elt(env, 2); /* qsort */
    stack[0] = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v95 = stack[-2];
    v95 = Llength(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v95 = cons(stack[0], v95);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[0] = v95;
    v96 = stack[-1];
    fn = elt(env, 3); /* sq2sspl */
    v96 = (*qfn2(fn))(qenv(fn), v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v95 = (Lisp_Object)17; /* 1 */
    v95 = list2star(stack[0], v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* lx2xx */
        return (*qfn1(fn))(qenv(fn), v95);
    }
/* error exit handlers */
v161:
    popv(4);
    return nil;
}



/* Code for ratpoly_1 */

static Lisp_Object MS_CDECL CC_ratpoly_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_1");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v48 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v48);
    }
}



/* Code for variableom */

static Lisp_Object CC_variableom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variableom");
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
    v160 = stack[0];
    v88 = Lintern(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = qvalue(elt(env, 1)); /* constantsom!* */
    v160 = Lassoc(nil, v88, v160);
    stack[-1] = v160;
    v160 = stack[-1];
    if (v160 == nil) goto v163;
    v160 = elt(env, 2); /* "<OMS " */
    fn = elt(env, 9); /* printout */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = elt(env, 3); /* "cd=""" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = stack[-1];
    v160 = qcdr(v160);
    v160 = qcar(v160);
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = elt(env, 4); /* """ " */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = elt(env, 5); /* "name=""" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = stack[-1];
    v160 = qcdr(v160);
    v160 = qcdr(v160);
    v160 = qcar(v160);
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = elt(env, 6); /* """/>" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    goto v139;

v139:
    v160 = nil;
    { popv(3); return onevalue(v160); }

v163:
    v160 = stack[0];
    if (v160 == nil) goto v139;
    v160 = elt(env, 8); /* "<OMV " */
    fn = elt(env, 9); /* printout */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = elt(env, 5); /* "name=""" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = stack[0];
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v160 = elt(env, 6); /* """/>" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v211;
    goto v139;
/* error exit handlers */
v211:
    popv(3);
    return nil;
}



/* Code for delhisto */

static Lisp_Object CC_delhisto(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v66, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delhisto");
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
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v66 = qvalue(elt(env, 2)); /* maxvar */
    v65 = stack[-2];
    v65 = plus2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v66 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = (Lisp_Object)1; /* 0 */
    v65 = *(Lisp_Object *)((char *)v66 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    if (v65 == nil) goto v16;
    v66 = stack[-2];
    v65 = (Lisp_Object)1; /* 0 */
    v65 = (Lisp_Object)geq2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v65 = v65 ? lisp_true : nil;
    env = stack[-4];
    if (v65 == nil) goto v16;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v66 = qvalue(elt(env, 2)); /* maxvar */
    v65 = stack[-2];
    v65 = plus2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v66 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = (Lisp_Object)113; /* 7 */
    v65 = *(Lisp_Object *)((char *)v66 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = qcar(v65);
    stack[-3] = v65;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v66 = qvalue(elt(env, 2)); /* maxvar */
    v65 = stack[-2];
    v65 = plus2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v66 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = (Lisp_Object)113; /* 7 */
    v65 = *(Lisp_Object *)((char *)v66 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = qcdr(v65);
    stack[-1] = v65;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v66 = qvalue(elt(env, 2)); /* maxvar */
    v65 = stack[-2];
    v65 = plus2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v66 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = (Lisp_Object)17; /* 1 */
    v65 = *(Lisp_Object *)((char *)v66 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v66 = qcdr(v65);
    v65 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 4); /* min */
    v65 = (*qfn2(fn))(qenv(fn), v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v66 = stack[-3];
    if (v66 == nil) goto v190;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v66 = qvalue(elt(env, 2)); /* maxvar */
    v65 = stack[-3];
    v65 = plus2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v66 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = (Lisp_Object)113; /* 7 */
    v66 = *(Lisp_Object *)((char *)v66 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = stack[-1];
    v65 = Lrplacd(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    goto v252;

v252:
    v65 = stack[-1];
    if (v65 == nil) goto v219;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v66 = qvalue(elt(env, 2)); /* maxvar */
    v65 = stack[-1];
    v65 = plus2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v66 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = (Lisp_Object)113; /* 7 */
    v66 = *(Lisp_Object *)((char *)v66 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = stack[-3];
    v65 = Lrplaca(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v219;

v219:
    v65 = nil;
    { popv(5); return onevalue(v65); }

v190:
    v250 = qvalue(elt(env, 3)); /* codhisto */
    v66 = v65;
    v65 = stack[-1];
    *(Lisp_Object *)((char *)v250 + (CELL-TAG_VECTOR) + ((int32_t)v66/(16/CELL))) = v65;
    goto v252;

v16:
    v65 = nil;
    { popv(5); return onevalue(v65); }
/* error exit handlers */
v251:
    popv(5);
    return nil;
}



/* Code for newenv */

static Lisp_Object CC_newenv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newenv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v0;
/* end of prologue */
    v236 = v105;
    v105 = elt(env, 1); /* unbound */
    {
        fn = elt(env, 2); /* bind */
        return (*qfn2(fn))(qenv(fn), v236, v105);
    }
}



/* Code for setmat */

static Lisp_Object MS_CDECL CC_setmat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v129, Lisp_Object v48, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v180, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmat");
#endif
    if (stack >= stacklimit)
    {
        push4(v48,v129,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v129,v48);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v48;
    stack[-1] = v129;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v90 = qvalue(elt(env, 1)); /* !*modular */
    if (v90 == nil) goto v38;
    v90 = elt(env, 2); /* modular */
    v90 = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    fn = elt(env, 6); /* off */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    v90 = elt(env, 3); /* mod_was_on */
    v90 = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    fn = elt(env, 7); /* on */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    goto v38;

v38:
    v90 = stack[-2];
    v90 = integerp(v90);
    if (v90 == nil) goto v141;
    v90 = stack[-2];
    goto v143;

v143:
    stack[-2] = v90;
    v90 = stack[-1];
    v90 = integerp(v90);
    if (v90 == nil) goto v181;
    v90 = stack[-1];
    goto v98;

v98:
    stack[-1] = v90;
    v91 = stack[-3];
    v180 = stack[-2];
    v90 = stack[-1];
    v91 = list3(v91, v180, v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    v180 = stack[0];
    v90 = stack[-3];
    fn = elt(env, 8); /* my_letmtr */
    v90 = (*qfnn(fn))(qenv(fn), 3, v91, v180, v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    v90 = qvalue(elt(env, 5)); /* !*mod_was_on */
    if (v90 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v90 = elt(env, 2); /* modular */
    v90 = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    fn = elt(env, 7); /* on */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    v90 = elt(env, 3); /* mod_was_on */
    v90 = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    fn = elt(env, 6); /* off */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v181:
    v90 = stack[-1];
    fn = elt(env, 9); /* reval */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    goto v98;

v141:
    v90 = stack[-2];
    fn = elt(env, 9); /* reval */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-4];
    goto v143;
/* error exit handlers */
v202:
    popv(5);
    return nil;
}



/* Code for !*pf2wedgepf */

static Lisp_Object CC_Hpf2wedgepf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *pf2wedgepf");
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
    goto v16;

v16:
    v121 = stack[0];
    if (v121 == nil) goto v2;
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcar(v121);
    fn = elt(env, 1); /* wedgefax */
    v181 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    v121 = stack[0];
    v121 = qcar(v121);
    v122 = qcdr(v121);
    v121 = stack[-1];
    v121 = acons(v181, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    stack[-1] = v121;
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v16;

v2:
    v121 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v162:
    popv(3);
    return nil;
}



/* Code for prinlatom */

static Lisp_Object CC_prinlatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinlatom");
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
    v205 = stack[-1];
    v150 = elt(env, 1); /* font */
    v150 = get(v205, v150);
    env = stack[-3];
    stack[-2] = v150;
    if (v150 == nil) goto v133;
    v150 = stack[-2];
    fn = elt(env, 5); /* prin2la */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    goto v133;

v133:
    v205 = stack[-1];
    v150 = elt(env, 2); /* accent */
    v150 = get(v205, v150);
    env = stack[-3];
    stack[0] = v150;
    if (v150 == nil) goto v154;
    v150 = stack[0];
    fn = elt(env, 5); /* prin2la */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    goto v154;

v154:
    v205 = stack[-1];
    v150 = elt(env, 3); /* name */
    v150 = get(v205, v150);
    env = stack[-3];
    v205 = v150;
    if (v150 == nil) goto v92;
    v150 = v205;
    fn = elt(env, 5); /* prin2la */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    goto v203;

v203:
    v150 = stack[0];
    if (v150 == nil) goto v160;
    v150 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    goto v160;

v160:
    v150 = stack[-2];
    if (v150 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v150 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v180;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v92:
    v150 = stack[-1];
    fn = elt(env, 6); /* testchar1 */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    fn = elt(env, 5); /* prin2la */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    goto v203;
/* error exit handlers */
v180:
    popv(4);
    return nil;
}



/* Code for inttovec */

static Lisp_Object CC_inttovec(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec");
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
    v117 = v1;
    v143 = v0;
/* end of prologue */
    stack[0] = v117;
    fn = elt(env, 1); /* inttovec!-solve */
    v143 = (*qfn2(fn))(qenv(fn), v117, v143);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-1];
    {
        Lisp_Object v126 = stack[0];
        popv(2);
        fn = elt(env, 2); /* inttovec1 */
        return (*qfn2(fn))(qenv(fn), v126, v143);
    }
/* error exit handlers */
v197:
    popv(2);
    return nil;
}



/* Code for fctlength */

static Lisp_Object CC_fctlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctlength");
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
    v16 = v0;
/* end of prologue */
    fn = elt(env, 1); /* fctargs */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    errexit();
        return Llength(nil, v16);
}



/* Code for set!-global!-mode */

static Lisp_Object CC_setKglobalKmode(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-global-mode");
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
    v133 = qvalue(elt(env, 1)); /* nil */
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    qvalue(elt(env, 2)) = v133; /* alglist!* */
    v133 = stack[-2];
    qvalue(elt(env, 3)) = v133; /* !*mode */
    stack[-3] = elt(env, 4); /* null */
    stack[-1] = elt(env, 5); /* setq */
    stack[0] = elt(env, 3); /* !*mode */
    v133 = stack[-2];
    v133 = Lmkquote(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    v133 = list3(stack[-1], stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v120;
    {
        Lisp_Object v119 = stack[-3];
        popv(5);
        return list2(v119, v133);
    }
/* error exit handlers */
v120:
    popv(5);
    return nil;
}



/* Code for setel */

static Lisp_Object CC_setel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v228, v150, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel");
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
    v196 = stack[-2];
    v228 = qcar(v196);
    v196 = elt(env, 1); /* dimension */
    v196 = get(v228, v196);
    env = stack[-4];
    stack[-3] = v196;
    v196 = stack[-3];
    stack[0] = Llength(nil, v196);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    v196 = stack[-2];
    v196 = qcdr(v196);
    v196 = Llength(nil, v196);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    if (equal(stack[0], v196)) goto v217;
    v196 = elt(env, 2); /* "Incorrect array reference" */
    v228 = v196;
    v196 = v228;
    qvalue(elt(env, 3)) = v196; /* errmsg!* */
    v196 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v196 == nil)) goto v121;
    v196 = v228;
    fn = elt(env, 6); /* lprie */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v121;

v121:
    v196 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v91;
    v196 = nil;
    { popv(5); return onevalue(v196); }

v217:
    v196 = stack[-2];
    v228 = qcar(v196);
    v196 = elt(env, 5); /* avalue */
    v196 = get(v228, v196);
    env = stack[-4];
    v196 = qcdr(v196);
    v205 = qcar(v196);
    v196 = stack[-2];
    v150 = qcdr(v196);
    v228 = stack[-1];
    v196 = stack[-3];
    {
        popv(5);
        fn = elt(env, 7); /* setel1 */
        return (*qfnn(fn))(qenv(fn), 4, v205, v150, v228, v196);
    }
/* error exit handlers */
v91:
    popv(5);
    return nil;
}



/* Code for mkkl */

static Lisp_Object CC_mkkl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkkl");
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
    v97 = v1;
    v98 = v0;
/* end of prologue */

v38:
    v132 = v98;
    if (v132 == nil) { popv(2); return onevalue(v97); }
    v132 = v98;
    v132 = qcdr(v132);
    stack[0] = v132;
    v98 = qcar(v98);
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-1];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-1];
    v98 = stack[0];
    goto v38;
/* error exit handlers */
v119:
    popv(2);
    return nil;
}



/* Code for groeb!=better */

static Lisp_Object CC_groebMbetter(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=better");
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
    v196 = stack[-1];
    v196 = qcdr(v196);
    v228 = qcar(v196);
    v196 = stack[0];
    v196 = qcdr(v196);
    v196 = qcar(v196);
    v196 = (Lisp_Object)lessp2(v228, v196);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v196 = v196 ? lisp_true : nil;
    env = stack[-2];
    if (v196 == nil) goto v126;
    v196 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v196); }

v126:
    v196 = stack[-1];
    v196 = qcdr(v196);
    v228 = qcar(v196);
    v196 = stack[0];
    v196 = qcdr(v196);
    v196 = qcar(v196);
    if (equal(v228, v196)) goto v237;
    v196 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v196); }

v237:
    v228 = stack[-1];
    v196 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v196 = (*qfn2(fn))(qenv(fn), v228, v196);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    stack[-1] = qcar(v196);
    v228 = stack[0];
    v196 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v196 = (*qfn2(fn))(qenv(fn), v228, v196);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    v196 = qcar(v196);
    fn = elt(env, 4); /* mo_compare */
    v228 = (*qfn2(fn))(qenv(fn), stack[-1], v196);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v196 = (Lisp_Object)1; /* 0 */
        popv(3);
        return Lleq(nil, v228, v196);
/* error exit handlers */
v206:
    popv(3);
    return nil;
}



/* Code for wi_new */

static Lisp_Object CC_wi_new(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wi_new");
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
    v98 = qvalue(elt(env, 1)); /* wi_number */
    v98 = add1(v98);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-4];
    qvalue(elt(env, 1)) = v98; /* wi_number */
    v132 = elt(env, 2); /* !: */
    v98 = qvalue(elt(env, 1)); /* wi_number */
    fn = elt(env, 4); /* mkid */
    v98 = (*qfn2(fn))(qenv(fn), v132, v98);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-4];
    v98 = Lintern(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-4];
    stack[-3] = v98;
    stack[-1] = stack[-3];
    stack[0] = elt(env, 3); /* windex */
    v98 = stack[-2];
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-4];
    v98 = Lputprop(nil, 3, stack[-1], stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v181;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v181:
    popv(5);
    return nil;
}



/* Code for general!-reduce!-degree!-mod!-p */

static Lisp_Object CC_generalKreduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-degree-mod-p");
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
    v77 = stack[-2];
    v77 = qcar(v77);
    v224 = qcdr(v77);
    v77 = (Lisp_Object)1; /* 0 */
    if (v224 == v77) goto v139;
    v224 = qvalue(elt(env, 1)); /* current!-modulus */
    v77 = stack[-2];
    v77 = qcar(v77);
    v77 = qcdr(v77);
    v77 = difference2(v224, v77);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    stack[0] = v77;
    goto v105;

v105:
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = qcdr(v77);
    fn = elt(env, 2); /* general!-modular!-reciprocal */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    fn = elt(env, 3); /* general!-modular!-times */
    v77 = (*qfn2(fn))(qenv(fn), stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    stack[-3] = v77;
    v77 = stack[-2];
    v77 = qcar(v77);
    v77 = qcar(v77);
    v224 = qcdr(v77);
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = qcar(v77);
    v77 = qcdr(v77);
    v77 = (Lisp_Object)(int32_t)((int32_t)v224 - (int32_t)v77 + TAG_FIXNUM);
    stack[0] = v77;
    v224 = stack[0];
    v77 = (Lisp_Object)1; /* 0 */
    if (v224 == v77) goto v206;
    v77 = stack[-2];
    stack[-2] = qcdr(v77);
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = qcar(v77);
    v77 = qcar(v77);
    fn = elt(env, 4); /* fkern */
    v224 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    v77 = stack[0];
    fn = elt(env, 5); /* getpower */
    v224 = (*qfn2(fn))(qenv(fn), v224, v77);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    v77 = stack[-3];
    v224 = cons(v224, v77);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    v77 = stack[-1];
    v77 = qcdr(v77);
    fn = elt(env, 6); /* general!-times!-term!-mod!-p */
    v77 = (*qfn2(fn))(qenv(fn), v224, v77);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    {
        Lisp_Object v73 = stack[-2];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v73, v77);
    }

v206:
    v77 = stack[-2];
    stack[0] = qcdr(v77);
    v77 = stack[-1];
    v224 = qcdr(v77);
    v77 = stack[-3];
    fn = elt(env, 8); /* general!-multiply!-by!-constant!-mod!-p */
    v77 = (*qfn2(fn))(qenv(fn), v224, v77);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    {
        Lisp_Object v254 = stack[0];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v254, v77);
    }

v139:
    v77 = stack[-2];
    v77 = qcar(v77);
    v77 = qcdr(v77);
    stack[0] = v77;
    goto v105;
/* error exit handlers */
v201:
    popv(5);
    return nil;
}



/* Code for simp!*sq */

static Lisp_Object CC_simpHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v118 = v0;
/* end of prologue */
    v117 = v118;
    v117 = qcdr(v117);
    v117 = qcar(v117);
    if (v117 == nil) goto v142;
    v117 = qvalue(elt(env, 1)); /* !*resimp */
    if (!(v117 == nil)) goto v142;
    v117 = v118;
    v117 = qcar(v117);
    return onevalue(v117);

v142:
    v117 = v118;
    v117 = qcar(v117);
    {
        fn = elt(env, 2); /* resimp1 */
        return (*qfn1(fn))(qenv(fn), v117);
    }
}



/* Code for findremainder */

static Lisp_Object CC_findremainder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v203, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findremainder");
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
    v181 = v1;
    v203 = v0;
/* end of prologue */
    stack[0] = v181;
    goto v38;

v38:
    v181 = stack[0];
    if (v181 == nil) { popv(2); return onevalue(v203); }
    v181 = stack[0];
    v181 = qcar(v181);
    v124 = v203;
    v203 = v181;
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = qcar(v181);
    fn = elt(env, 2); /* wupseudodivide */
    v181 = (*qfnn(fn))(qenv(fn), 3, v124, v203, v181);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    v181 = qcdr(v181);
    v203 = v181;
    v181 = stack[0];
    v181 = qcdr(v181);
    stack[0] = v181;
    goto v38;
/* error exit handlers */
v163:
    popv(2);
    return nil;
}



/* Code for rndifference!: */

static Lisp_Object CC_rndifferenceT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rndifference:");
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
    v140 = stack[-1];
    v140 = qcdr(v140);
    v161 = qcar(v140);
    v140 = stack[0];
    v140 = qcdr(v140);
    v140 = qcdr(v140);
    stack[-2] = times2(v161, v140);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v140 = stack[-1];
    v140 = qcdr(v140);
    v161 = qcdr(v140);
    v140 = stack[0];
    v140 = qcdr(v140);
    v140 = qcar(v140);
    v140 = times2(v161, v140);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    stack[-2] = difference2(stack[-2], v140);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v140 = stack[-1];
    v140 = qcdr(v140);
    v161 = qcdr(v140);
    v140 = stack[0];
    v140 = qcdr(v140);
    v140 = qcdr(v140);
    v140 = times2(v161, v140);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    {
        Lisp_Object v212 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v212, v140);
    }
/* error exit handlers */
v88:
    popv(4);
    return nil;
}



/* Code for qqe_arg!-check */

static Lisp_Object CC_qqe_argKcheck(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check");
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
    v147 = stack[0];
    v147 = qcar(v147);
    stack[-1] = v147;
    v147 = stack[-1];
    fn = elt(env, 4); /* qqe_rqopp */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    if (v147 == nil) goto v2;
    v147 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check!-lq!-rq */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    goto v38;

v38:
    v147 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v147); }

v2:
    v147 = stack[-1];
    fn = elt(env, 6); /* qqe_rbopp */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    if (v147 == nil) goto v142;
    v147 = stack[0];
    fn = elt(env, 7); /* qqe_arg!-check!-lb!-rb */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    goto v38;

v142:
    v147 = stack[-1];
    fn = elt(env, 8); /* qqe_qopheadp */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    if (!(v147 == nil)) goto v117;
    v147 = stack[-1];
    fn = elt(env, 9); /* qqe_qoptailp */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    if (!(v147 == nil)) goto v117;
    v147 = stack[-1];
    fn = elt(env, 10); /* qqe_qopaddp */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    if (v147 == nil) goto v161;
    v147 = stack[0];
    fn = elt(env, 11); /* qqe_arg!-check!-lb!-rq */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    goto v38;

v161:
    v147 = stack[0];
    v147 = qcdr(v147);
    stack[-1] = v147;
    goto v212;

v212:
    v147 = stack[-1];
    if (v147 == nil) goto v38;
    v147 = stack[-1];
    v147 = qcar(v147);
    fn = elt(env, 12); /* qqe_arg!-check!-b */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    if (!(v147 == nil)) goto v205;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v147 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    v157 = stack[0];
    v147 = elt(env, 3); /* "some arguments are not of basic type" */
    fn = elt(env, 14); /* typerr */
    v147 = (*qfn2(fn))(qenv(fn), v157, v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    goto v205;

v205:
    v147 = stack[-1];
    v147 = qcdr(v147);
    stack[-1] = v147;
    goto v212;

v117:
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    fn = elt(env, 15); /* qqe_arg!-check!-q */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    if (!(v147 == nil)) goto v38;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v147 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    v157 = stack[0];
    v147 = elt(env, 1); /* "some arguments are not of queue type" */
    fn = elt(env, 14); /* typerr */
    v147 = (*qfn2(fn))(qenv(fn), v157, v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    goto v38;
/* error exit handlers */
v226:
    popv(3);
    return nil;
}



/* Code for setunion */

static Lisp_Object CC_setunion(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v154, v155;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setunion");
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
    v154 = v0;
/* end of prologue */

v16:
    v163 = stack[0];
    if (v163 == nil) { popv(3); return onevalue(v154); }
    v163 = stack[0];
    v155 = qcar(v163);
    v163 = v154;
    v163 = Lmember(nil, v155, v163);
    if (v163 == nil) goto v97;
    v163 = stack[0];
    v163 = qcdr(v163);
    stack[0] = v163;
    goto v16;

v97:
    stack[-1] = v154;
    v163 = stack[0];
    v163 = qcar(v163);
    v163 = ncons(v163);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    v163 = Lappend(nil, stack[-1], v163);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    v154 = v163;
    v163 = stack[0];
    v163 = qcdr(v163);
    stack[0] = v163;
    goto v16;
/* error exit handlers */
v210:
    popv(3);
    return nil;
}



/* Code for ibalp_redclause */

static Lisp_Object CC_ibalp_redclause(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_redclause");
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
    stack[0] = nil;
    v163 = stack[-1];
    v163 = qcar(v163);
    stack[-2] = v163;
    goto v105;

v105:
    v163 = stack[-2];
    if (v163 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v163 = stack[0];
    if (!(v163 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v163 = stack[-2];
    v154 = qcar(v163);
    v163 = stack[-1];
    v163 = qcdr(v163);
    v163 = qcar(v163);
    fn = elt(env, 3); /* ibalp_vmember */
    v163 = (*qfn2(fn))(qenv(fn), v154, v163);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-3];
    if (v163 == nil) goto v197;
    v163 = qvalue(elt(env, 2)); /* t */
    stack[0] = v163;
    goto v197;

v197:
    v163 = stack[-2];
    v163 = qcdr(v163);
    stack[-2] = v163;
    goto v105;
/* error exit handlers */
v210:
    popv(4);
    return nil;
}



/* Code for aex_ids */

static Lisp_Object CC_aex_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_ids");
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
    v16 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_idl */
        return (*qfn1(fn))(qenv(fn), v16);
    }
/* error exit handlers */
v38:
    popv(1);
    return nil;
}



/* Code for stats_getargs */

static Lisp_Object MS_CDECL CC_stats_getargs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "stats_getargs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stats_getargs");
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
    v117 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-1];
    v118 = v117;
    v117 = v118;
    if (v117 == nil) goto v9;
    stack[0] = v118;
    v117 = CC_stats_getargs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v126;
    {
        Lisp_Object v103 = stack[0];
        popv(2);
        return cons(v103, v117);
    }

v9:
    v117 = nil;
    { popv(2); return onevalue(v117); }
/* error exit handlers */
v126:
    popv(2);
    return nil;
}



/* Code for nfactorial */

static Lisp_Object CC_nfactorial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nfactorial");
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
    v211 = stack[-1];
    v235 = (Lisp_Object)321; /* 20 */
    v235 = (Lisp_Object)greaterp2(v211, v235);
    nil = C_nil;
    if (exception_pending()) goto v93;
    v235 = v235 ? lisp_true : nil;
    env = stack[-3];
    if (v235 == nil) goto v126;
    v211 = (Lisp_Object)17; /* 1 */
    v235 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* fac!-part */
        return (*qfn2(fn))(qenv(fn), v211, v235);
    }

v126:
    v235 = (Lisp_Object)17; /* 1 */
    stack[-2] = v235;
    v235 = (Lisp_Object)17; /* 1 */
    stack[0] = v235;
    goto v163;

v163:
    v211 = stack[-1];
    v235 = stack[0];
    v235 = difference2(v211, v235);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    v235 = Lminusp(nil, v235);
    env = stack[-3];
    if (!(v235 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v211 = stack[-2];
    v235 = stack[0];
    v235 = times2(v211, v235);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    stack[-2] = v235;
    v235 = stack[0];
    v235 = add1(v235);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    stack[0] = v235;
    goto v163;
/* error exit handlers */
v93:
    popv(4);
    return nil;
}



/* Code for mksetq */

static Lisp_Object CC_mksetq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v211, v207, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksetq");
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
    v211 = v1;
    v207 = v0;
/* end of prologue */
    v235 = v207;
    if (!consp(v235)) goto v109;
    v235 = v207;
    v134 = qcar(v235);
    v235 = elt(env, 2); /* setfn */
    v235 = get(v134, v235);
    env = stack[0];
    v134 = v235;
    if (v235 == nil) goto v140;
    v235 = v134;
        popv(1);
        return Lapply2(nil, 3, v235, v207, v211);

v140:
    v211 = v207;
    v235 = elt(env, 3); /* "assignment argument" */
    fn = elt(env, 4); /* typerr */
    v235 = (*qfn2(fn))(qenv(fn), v211, v235);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v235 = nil;
    { popv(1); return onevalue(v235); }

v109:
    v235 = elt(env, 1); /* setq */
    popv(1);
    return list3(v235, v207, v211);
/* error exit handlers */
v135:
    popv(1);
    return nil;
}



/* Code for mo_neworder */

static Lisp_Object CC_mo_neworder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neworder");
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
    v139 = v0;
/* end of prologue */
    v139 = qcar(v139);
    fn = elt(env, 1); /* mo!=shorten */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    stack[0] = v139;
    fn = elt(env, 2); /* mo!=deglist */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v125;
    {
        Lisp_Object v143 = stack[0];
        popv(2);
        return cons(v143, v139);
    }
/* error exit handlers */
v125:
    popv(2);
    return nil;
}



/* Code for class */

static Lisp_Object CC_class(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for class");
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
    v203 = stack[0];
    fn = elt(env, 3); /* ord */
    v124 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    v203 = (Lisp_Object)1; /* 0 */
    if (v124 == v203) goto v3;
    v124 = qvalue(elt(env, 1)); /* ordering */
    v203 = elt(env, 2); /* lex */
    if (v124 == v203) goto v197;
    v203 = stack[0];
    v203 = qcdr(v203);
    goto v118;

v118:
    v203 = Lreverse(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    fn = elt(env, 4); /* leftzeros */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v163;
    v203 = (Lisp_Object)((int32_t)(v203) + 0x10);
    { popv(2); return onevalue(v203); }

v197:
    v203 = stack[0];
    goto v118;

v3:
    v203 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v203); }
/* error exit handlers */
v163:
    popv(2);
    return nil;
}



/* Code for dl_get2 */

static Lisp_Object CC_dl_get2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v210, v204, v237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get2");
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
    v210 = v1;
    v204 = v0;
/* end of prologue */

v38:
    v184 = v204;
    if (v184 == nil) { popv(2); return onevalue(v210); }
    v184 = v204;
    v237 = qcar(v184);
    v184 = elt(env, 1); /* dummy */
    v184 = get(v237, v184);
    env = stack[-1];
    if (v184 == nil) goto v163;
    v184 = v204;
    v184 = qcdr(v184);
    stack[0] = v184;
    v184 = v204;
    v204 = qcar(v184);
    v184 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* di_insert */
    v184 = (*qfnn(fn))(qenv(fn), 3, v204, v210, v184);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v210 = v184;
    v184 = stack[0];
    v204 = v184;
    goto v38;

v163:
    v184 = v204;
    v184 = qcdr(v184);
    v204 = v184;
    goto v38;
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for moduntag */

static Lisp_Object CC_moduntag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moduntag");
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
    goto v236;

v236:
    v217 = stack[0];
    v161 = elt(env, 1); /* !:mod!: */
    if (!consp(v217)) goto v109;
    v217 = qcar(v217);
    if (!(v217 == v161)) goto v109;
    v217 = stack[-1];
    v161 = stack[0];
    v161 = qcdr(v161);
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v217, v161);
    }

v109:
    v161 = stack[0];
    if (!consp(v161)) goto v120;
    v161 = stack[0];
    v161 = qcar(v161);
    v217 = CC_moduntag(env, v161);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    v161 = stack[-1];
    v161 = cons(v217, v161);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    stack[-1] = v161;
    v161 = stack[0];
    v161 = qcdr(v161);
    stack[0] = v161;
    goto v236;

v120:
    v217 = stack[-1];
    v161 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v217, v161);
    }
/* error exit handlers */
v88:
    popv(3);
    return nil;
}



/* Code for numeric!-content */

static Lisp_Object CC_numericKcontent(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v209, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numeric-content");
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

v3:
    v93 = stack[0];
    if (!consp(v93)) goto v9;
    v93 = stack[0];
    v93 = qcar(v93);
    if (!consp(v93)) goto v9;
    v93 = stack[0];
    v93 = qcdr(v93);
    if (v93 == nil) goto v127;
    v93 = stack[0];
    v93 = qcar(v93);
    v93 = qcdr(v93);
    v93 = CC_numericKcontent(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    v94 = v93;
    v209 = v94;
    v93 = (Lisp_Object)17; /* 1 */
    if (v209 == v93) { popv(3); return onevalue(v94); }
    stack[-1] = v94;
    v93 = stack[0];
    v93 = qcdr(v93);
    v93 = CC_numericKcontent(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    fn = elt(env, 1); /* gcddd */
    v93 = (*qfn2(fn))(qenv(fn), stack[-1], v93);
    nil = C_nil;
    if (exception_pending()) goto v228;
    v94 = v93;
    { popv(3); return onevalue(v94); }

v127:
    v93 = stack[0];
    v93 = qcar(v93);
    v93 = qcdr(v93);
    stack[0] = v93;
    goto v3;

v9:
    v93 = stack[0];
    fn = elt(env, 2); /* minusf */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    if (v93 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v93 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* negf */
        return (*qfn1(fn))(qenv(fn), v93);
    }
/* error exit handlers */
v228:
    popv(3);
    return nil;
}



/* Code for ibalp_clausep */

static Lisp_Object CC_ibalp_clausep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clausep");
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
    v121 = stack[0];
    fn = elt(env, 3); /* ibalp_litp */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    if (!(v121 == nil)) { popv(2); return onevalue(v121); }
    v121 = stack[0];
    if (!consp(v121)) goto v143;
    v121 = stack[0];
    v121 = qcar(v121);
    v122 = v121;
    goto v166;

v166:
    v121 = elt(env, 1); /* or */
    if (v122 == v121) goto v97;
    v121 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v121); }

v97:
    v121 = stack[0];
    v121 = qcdr(v121);
    {
        popv(2);
        fn = elt(env, 4); /* ibalp_litlp */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v143:
    v121 = stack[0];
    v122 = v121;
    goto v166;
/* error exit handlers */
v203:
    popv(2);
    return nil;
}



/* Code for aex_fromrp */

static Lisp_Object CC_aex_fromrp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_fromrp");
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
    v103 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v103;
    fn = elt(env, 3); /* ctx_new */
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v141 = qvalue(elt(env, 2)); /* t */
    v103 = qvalue(elt(env, 2)); /* t */
    v103 = list2(v141, v103);
    nil = C_nil;
    if (exception_pending()) goto v97;
    {
        Lisp_Object v98 = stack[-2];
        Lisp_Object v132 = stack[-1];
        Lisp_Object v120 = stack[0];
        popv(4);
        return list3star(v98, v132, v120, v103);
    }
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variablesir");
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
    v210 = qvalue(elt(env, 1)); /* char */
    v184 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v210, v184)) goto v38;
    fn = elt(env, 4); /* omvir */
    v184 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-1];
    stack[0] = v184;
    fn = elt(env, 5); /* lex */
    v184 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-1];
    v184 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v237;
    v210 = stack[0];
    if (v210 == nil) goto v127;
    v210 = stack[0];
    popv(2);
    return cons(v210, v184);

v127:
    v210 = stack[0];
        popv(2);
        return Lappend(nil, v210, v184);

v38:
    v184 = nil;
    { popv(2); return onevalue(v184); }
/* error exit handlers */
v237:
    popv(2);
    return nil;
}



/* Code for cr!:minusp */

static Lisp_Object CC_crTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v232, v160;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:minusp");
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
    v217 = v0;
/* end of prologue */
    v232 = v217;
    v232 = qcdr(v232);
    v232 = qcar(v232);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v160 = v232;
    v232 = v217;
    v217 = v160;
    if (!consp(v217)) goto v165;
    v217 = v232;
    v217 = qcar(v217);
    v217 = (Lisp_Object)zerop(v217);
    v217 = v217 ? lisp_true : nil;
    env = stack[0];
    if (v217 == nil) goto v203;
    v217 = v160;
    v232 = qcar(v217);
    v217 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v232, v217);

v203:
    v217 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v217); }

v165:
    v217 = v232;
    v217 = (Lisp_Object)zerop(v217);
    v217 = v217 ? lisp_true : nil;
    env = stack[0];
    if (v217 == nil) goto v125;
    v232 = v160;
    v217 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v232, v217);

v125:
    v217 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v217); }
}



/* Code for groebnormalform */

static Lisp_Object MS_CDECL CC_groebnormalform(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v129, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v117, v118, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groebnormalform");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebnormalform");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v143 = v129;
    v117 = v1;
    v118 = v0;
/* end of prologue */
    v197 = v118;
    v118 = v117;
    v117 = v143;
    v143 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* groebnormalform0 */
        return (*qfnn(fn))(qenv(fn), 4, v197, v118, v117, v143);
    }
}



/* Code for inttovec1 */

static Lisp_Object CC_inttovec1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec1");
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
    v88 = stack[-1];
    v160 = (Lisp_Object)17; /* 1 */
    if (v88 == v160) goto v16;
    v160 = stack[-1];
    v88 = sub1(v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v160 = stack[0];
    v160 = qcdr(v160);
    fn = elt(env, 1); /* inttovec!-solve */
    v160 = (*qfn2(fn))(qenv(fn), v88, v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    stack[-2] = v160;
    v160 = stack[0];
    v88 = qcar(v160);
    v160 = stack[-2];
    v160 = qcar(v160);
    stack[0] = difference2(v88, v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v160 = stack[-1];
    v88 = sub1(v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v160 = stack[-2];
    v160 = CC_inttovec1(env, v88, v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    {
        Lisp_Object v134 = stack[0];
        popv(4);
        return cons(v134, v160);
    }

v16:
    v160 = stack[0];
    v160 = qcar(v160);
    popv(4);
    return ncons(v160);
/* error exit handlers */
v207:
    popv(4);
    return nil;
}



/* Code for pterpri */

static Lisp_Object MS_CDECL CC_pterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v89, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pterpri");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    v94 = qvalue(elt(env, 1)); /* nil */
    v94 = Lwrs(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    stack[-3] = v94;
    v94 = qvalue(elt(env, 2)); /* !*pprinbuf!* */
    v94 = Lnreverse(nil, v94);
    env = stack[-4];
    stack[-2] = v94;
    v94 = qvalue(elt(env, 3)); /* !*outchanl!* */
    stack[-1] = v94;
    goto v165;

v165:
    v94 = stack[-1];
    if (v94 == nil) goto v236;
    v94 = stack[-1];
    v94 = qcar(v94);
    v94 = Lwrs(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v94 = stack[-2];
    stack[0] = v94;
    goto v97;

v97:
    v94 = stack[0];
    if (v94 == nil) goto v136;
    v94 = stack[0];
    v94 = qcar(v94);
    v196 = v94;
    v89 = qvalue(elt(env, 4)); /* gentranlang!* */
    v94 = elt(env, 5); /* fortran */
    if (v89 == v94) goto v155;
    v94 = v196;
    v94 = Lprinc(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    goto v154;

v154:
    v94 = stack[0];
    v94 = qcdr(v94);
    stack[0] = v94;
    goto v97;

v155:
    v94 = v196;
    fn = elt(env, 7); /* fprin2 */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    goto v154;

v136:
    v94 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v94 = stack[-1];
    v94 = qcdr(v94);
    stack[-1] = v94;
    goto v165;

v236:
    v94 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 6)) = v94; /* !*posn!* */
    v94 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v94; /* !*pprinbuf!* */
    v94 = stack[-3];
    v94 = Lwrs(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v94 = nil;
    { popv(5); return onevalue(v94); }
/* error exit handlers */
v216:
    popv(5);
    return nil;
}



/* Code for opmtchrevop */

static Lisp_Object CC_opmtchrevop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtchrevop");
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
    v121 = qvalue(elt(env, 1)); /* !*val */
    if (v121 == nil) goto v3;
    v122 = elt(env, 2); /* cons */
    v121 = stack[0];
    v121 = Lsmemq(nil, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    if (!(v121 == nil)) goto v3;
    v121 = stack[0];
    stack[-1] = qcar(v121);
    v121 = stack[0];
    v121 = qcdr(v121);
    fn = elt(env, 3); /* revlis */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v121 = cons(stack[-1], v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v3:
    v121 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for invp */

static Lisp_Object CC_invp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v196, v228;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invp");
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
    v228 = v0;
/* end of prologue */
    v196 = v228;
    v89 = elt(env, 1); /* unit */
    if (v196 == v89) return onevalue(v228);
    v89 = v228;
    if (!consp(v89)) goto v143;
    v89 = v228;
    v196 = qcar(v89);
    v89 = elt(env, 3); /* (comm anticomm) */
    v89 = Lmember(nil, v196, v89);
    if (v89 == nil) goto v88;
    v196 = elt(env, 4); /* quotient */
    v89 = (Lisp_Object)17; /* 1 */
    return list3(v196, v89, v228);

v88:
    v89 = v228;
    v196 = qcar(v89);
    v89 = elt(env, 2); /* inverse */
    v89 = get(v196, v89);
    v196 = v228;
    v196 = qcdr(v196);
    return cons(v89, v196);

v143:
    v89 = v228;
    v196 = elt(env, 2); /* inverse */
    return get(v89, v196);
}



setup_type const u15_setup[] =
{
    {"qremf",                   too_few_2,      CC_qremf,      wrong_no_2},
    {"intexprlisp",             too_few_2,      CC_intexprlisp,wrong_no_2},
    {"squared+matrix+p",        CC_squaredLmatrixLp,too_many_1,wrong_no_1},
    {"ibalp_simpterm",          CC_ibalp_simpterm,too_many_1,  wrong_no_1},
    {"ratpoly_nullp",           CC_ratpoly_nullp,too_many_1,   wrong_no_1},
    {"vbcgcd",                  too_few_2,      CC_vbcgcd,     wrong_no_2},
    {"vdpred",                  CC_vdpred,      too_many_1,    wrong_no_1},
    {"termordp!",               too_few_2,      CC_termordpB,  wrong_no_2},
    {"*sqprint",                CC_Hsqprint,    too_many_1,    wrong_no_1},
    {"rd:plus",                 too_few_2,      CC_rdTplus,    wrong_no_2},
    {"physopaeval",             CC_physopaeval, too_many_1,    wrong_no_1},
    {"assert_install",          CC_assert_install,too_many_1,  wrong_no_1},
    {"pv_intequiv",             CC_pv_intequiv, too_many_1,    wrong_no_1},
    {"splitlist:",              too_few_2,      CC_splitlistT, wrong_no_2},
    {"wtchk",                   too_few_2,      CC_wtchk,      wrong_no_2},
    {"exptcompare",             too_few_2,      CC_exptcompare,wrong_no_2},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,too_many_1,wrong_no_1},
    {"sq2sspl",                 too_few_2,      CC_sq2sspl,    wrong_no_2},
    {"ibalp_clauselp",          CC_ibalp_clauselp,too_many_1,  wrong_no_1},
    {"aex_lc",                  too_few_2,      CC_aex_lc,     wrong_no_2},
    {"nary",                    too_few_2,      CC_nary,       wrong_no_2},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"spquotematrix",           CC_spquotematrix,too_many_1,   wrong_no_1},
    {"dm-minus",                CC_dmKminus,    too_many_1,    wrong_no_1},
    {"chk",                     CC_chk,         too_many_1,    wrong_no_1},
    {"vdpzero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpzero},
    {"vdpputprop",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpputprop},
    {"repasc",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_repasc},
    {"putd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_putd},
    {"evalequal",               too_few_2,      CC_evalequal,  wrong_no_2},
    {"sf2mv1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_sf2mv1},
    {"bc_inv",                  CC_bc_inv,      too_many_1,    wrong_no_1},
    {"gperm0",                  CC_gperm0,      too_many_1,    wrong_no_1},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"expt-mod-p",              too_few_2,      CC_exptKmodKp, wrong_no_2},
    {"qqe_simplat1",            too_few_2,      CC_qqe_simplat1,wrong_no_2},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ratpoly_1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_1},
    {"variableom",              CC_variableom,  too_many_1,    wrong_no_1},
    {"delhisto",                CC_delhisto,    too_many_1,    wrong_no_1},
    {"newenv",                  CC_newenv,      too_many_1,    wrong_no_1},
    {"setmat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setmat},
    {"*pf2wedgepf",             CC_Hpf2wedgepf, too_many_1,    wrong_no_1},
    {"prinlatom",               CC_prinlatom,   too_many_1,    wrong_no_1},
    {"inttovec",                too_few_2,      CC_inttovec,   wrong_no_2},
    {"fctlength",               CC_fctlength,   too_many_1,    wrong_no_1},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"setel",                   too_few_2,      CC_setel,      wrong_no_2},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {"groeb=better",            too_few_2,      CC_groebMbetter,wrong_no_2},
    {"wi_new",                  CC_wi_new,      too_many_1,    wrong_no_1},
    {"general-reduce-degree-mod-p",too_few_2,   CC_generalKreduceKdegreeKmodKp,wrong_no_2},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"findremainder",           too_few_2,      CC_findremainder,wrong_no_2},
    {"rndifference:",           too_few_2,      CC_rndifferenceT,wrong_no_2},
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"setunion",                too_few_2,      CC_setunion,   wrong_no_2},
    {"ibalp_redclause",         CC_ibalp_redclause,too_many_1, wrong_no_1},
    {"aex_ids",                 CC_aex_ids,     too_many_1,    wrong_no_1},
    {"stats_getargs",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_stats_getargs},
    {"nfactorial",              CC_nfactorial,  too_many_1,    wrong_no_1},
    {"mksetq",                  too_few_2,      CC_mksetq,     wrong_no_2},
    {"mo_neworder",             CC_mo_neworder, too_many_1,    wrong_no_1},
    {"class",                   CC_class,       too_many_1,    wrong_no_1},
    {"dl_get2",                 too_few_2,      CC_dl_get2,    wrong_no_2},
    {"moduntag",                CC_moduntag,    too_many_1,    wrong_no_1},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"aex_fromrp",              CC_aex_fromrp,  too_many_1,    wrong_no_1},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"cr:minusp",               CC_crTminusp,   too_many_1,    wrong_no_1},
    {"groebnormalform",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebnormalform},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"pterpri",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_pterpri},
    {"opmtchrevop",             CC_opmtchrevop, too_many_1,    wrong_no_1},
    {"invp",                    CC_invp,        too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u15", (two_args *)"18670 6192638 2947865", 0}
};

/* end of generated code */
