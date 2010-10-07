
/* $destdir\u31.c        Machine generated C code */

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


/* Code for lispcodeexp */

static Lisp_Object CC_lispcodeexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109, v110;
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

v111:
    v108 = stack[-2];
    if (is_number(v108)) goto v112;
    v109 = stack[-2];
    v108 = elt(env, 1); /* e */
    if (v109 == v108) goto v113;
    v108 = stack[-2];
    if (!consp(v108)) goto v114;
    v108 = stack[-2];
    v109 = qcar(v108);
    v108 = elt(env, 4); /* (!:rd!: !:cr!: !:crn!: !:gi!:) */
    v108 = Lmemq(nil, v109, v108);
    if (!(v108 == nil)) goto v114;
    v108 = stack[-2];
    v109 = qcar(v108);
    v108 = elt(env, 6); /* expt */
    if (v109 == v108) goto v115;
    v108 = stack[-2];
    v109 = qcar(v108);
    v108 = elt(env, 11); /* quotient */
    if (v109 == v108) goto v116;
    v108 = stack[-2];
    v109 = qcar(v108);
    v108 = elt(env, 14); /* recip */
    if (v109 == v108) goto v117;
    v108 = stack[-2];
    v109 = qcar(v108);
    v108 = elt(env, 16); /* difference */
    if (v109 == v108) goto v118;
    v108 = stack[-2];
    v109 = qcar(v108);
    v108 = qvalue(elt(env, 19)); /* !*lisparithexpops!* */
    v108 = Lmemq(nil, v109, v108);
    if (!(v108 == nil)) goto v119;
    v108 = stack[-2];
    v109 = qcar(v108);
    v108 = qvalue(elt(env, 20)); /* !*lisplogexpops!* */
    v108 = Lmemq(nil, v109, v108);
    if (!(v108 == nil)) goto v119;
    v108 = stack[-2];
    stack[-3] = v108;
    v108 = stack[-3];
    if (v108 == nil) goto v120;
    v108 = stack[-3];
    v108 = qcar(v108);
    v109 = v108;
    v108 = qvalue(elt(env, 12)); /* nil */
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = ncons(v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v108;
    stack[-2] = v108;
    goto v122;

v122:
    v108 = stack[-3];
    v108 = qcdr(v108);
    stack[-3] = v108;
    v108 = stack[-3];
    if (v108 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v108 = stack[-3];
    v108 = qcar(v108);
    v109 = v108;
    v108 = qvalue(elt(env, 12)); /* nil */
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = ncons(v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = Lrplacd(nil, stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = stack[-1];
    v108 = qcdr(v108);
    stack[-1] = v108;
    goto v122;

v120:
    v108 = qvalue(elt(env, 12)); /* nil */
    { popv(6); return onevalue(v108); }

v119:
    v108 = stack[-2];
    stack[-4] = v108;
    v108 = stack[-4];
    if (v108 == nil) goto v123;
    v108 = stack[-4];
    v108 = qcar(v108);
    v109 = v108;
    v108 = stack[-3];
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = ncons(v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v108;
    stack[-2] = v108;
    goto v124;

v124:
    v108 = stack[-4];
    v108 = qcdr(v108);
    stack[-4] = v108;
    v108 = stack[-4];
    if (v108 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v108 = stack[-4];
    v108 = qcar(v108);
    v109 = v108;
    v108 = stack[-3];
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = ncons(v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = Lrplacd(nil, stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = stack[-1];
    v108 = qcdr(v108);
    stack[-1] = v108;
    goto v124;

v123:
    v108 = qvalue(elt(env, 12)); /* nil */
    { popv(6); return onevalue(v108); }

v118:
    stack[-4] = elt(env, 17); /* plus */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[0] = elt(env, 18); /* minus */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = stack[-3];
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = list2(stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v125 = stack[-4];
        Lisp_Object v126 = stack[-1];
        popv(6);
        return list3(v125, v126, v108);
    }

v117:
    v108 = qvalue(elt(env, 15)); /* !*period */
    if (v108 == nil) goto v127;
    stack[-1] = elt(env, 11); /* quotient */
    stack[0] = elt(env, 3); /* 1.0 */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = stack[-3];
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v128 = stack[-1];
        Lisp_Object v129 = stack[0];
        popv(6);
        return list3(v128, v129, v108);
    }

v127:
    stack[-1] = elt(env, 11); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = stack[-3];
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v130 = stack[-1];
        Lisp_Object v131 = stack[0];
        popv(6);
        return list3(v130, v131, v108);
    }

v116:
    stack[-1] = elt(env, 11); /* quotient */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = qvalue(elt(env, 13)); /* t */
    stack[0] = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = qvalue(elt(env, 13)); /* t */
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v132 = stack[-1];
        Lisp_Object v133 = stack[0];
        popv(6);
        return list3(v132, v133, v108);
    }

v115:
    v108 = stack[-2];
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = elt(env, 1); /* e */
    if (v109 == v108) goto v134;
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = elt(env, 7); /* (quotient 1 2) */
    if (equal(v109, v108)) goto v135;
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = elt(env, 9); /* !:rd!: */
    if (!consp(v109)) goto v136;
    v109 = qcar(v109);
    if (!(v109 == v108)) goto v136;
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v108 = qcar(v108);
    fn = elt(env, 21); /* realrat */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v108;
    v109 = stack[-1];
    v108 = elt(env, 10); /* (1 . 2) */
    if (equal(v109, v108)) goto v137;
    stack[0] = elt(env, 6); /* expt */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = stack[-3];
    stack[-2] = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v110 = elt(env, 11); /* quotient */
    v108 = stack[-1];
    v109 = qcar(v108);
    v108 = stack[-1];
    v108 = qcdr(v108);
    v109 = list3(v110, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = qvalue(elt(env, 12)); /* nil */
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v138 = stack[0];
        Lisp_Object v139 = stack[-2];
        popv(6);
        return list3(v138, v139, v108);
    }

v137:
    stack[0] = elt(env, 8); /* sqrt */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = stack[-3];
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v140 = stack[0];
        popv(6);
        return list2(v140, v108);
    }

v136:
    stack[0] = elt(env, 6); /* expt */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = qvalue(elt(env, 12)); /* nil */
    v108 = CC_lispcodeexp(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v141 = stack[0];
        Lisp_Object v142 = stack[-1];
        popv(6);
        return list3(v141, v142, v108);
    }

v135:
    v109 = elt(env, 8); /* sqrt */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = qcar(v108);
    v109 = list2(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = stack[-3];
    stack[-2] = v109;
    stack[-3] = v108;
    goto v111;

v134:
    v109 = elt(env, 2); /* exp */
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v108 = qcar(v108);
    v109 = list2(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = stack[-3];
    stack[-2] = v109;
    stack[-3] = v108;
    goto v111;

v114:
    v108 = qvalue(elt(env, 5)); /* irena!-constants */
    if (v108 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v108 = stack[-2];
    if (v108 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v108 = stack[-2];
    v108 = Lstringp(nil, v108);
    env = stack[-5];
    if (!(v108 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v108 = stack[-2];
    fn = elt(env, 22); /* check!-for!-irena!-constants */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v113:
    v109 = elt(env, 2); /* exp */
    v108 = elt(env, 3); /* 1.0 */
    v109 = list2(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = stack[-3];
    stack[-2] = v109;
    stack[-3] = v108;
    goto v111;

v112:
    v108 = stack[-3];
    if (v108 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v108 = stack[-2];
        popv(6);
        return Lfloat(nil, v108);
/* error exit handlers */
v121:
    popv(6);
    return nil;
}



/* Code for ext_mult */

static Lisp_Object CC_ext_mult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ext_mult");
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
    v158 = v1;
    v159 = v0;
/* end of prologue */
    v159 = qcdr(v159);
    v158 = qcdr(v158);
    fn = elt(env, 3); /* merge_lists */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-1];
    stack[0] = v158;
    v158 = stack[0];
    if (v158 == nil) goto v162;
    v158 = stack[0];
    v158 = qcdr(v158);
    if (v158 == nil) goto v163;
    v159 = elt(env, 2); /* ext */
    v158 = stack[0];
    v158 = qcdr(v158);
    v158 = cons(v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-1];
    fn = elt(env, 4); /* !*a2k */
    v160 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-1];
    v159 = (Lisp_Object)17; /* 1 */
    v158 = stack[0];
    v158 = qcar(v158);
    v159 = acons(v160, v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-1];
    v160 = qvalue(elt(env, 1)); /* nil */
    v158 = (Lisp_Object)17; /* 1 */
    popv(2);
    return acons(v159, v160, v158);

v163:
    v159 = (Lisp_Object)17; /* 1 */
    v158 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v159, v158);

v162:
    v159 = qvalue(elt(env, 1)); /* nil */
    v158 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v159, v158);
/* error exit handlers */
v161:
    popv(2);
    return nil;
}



/* Code for ofsf_negateat */

static Lisp_Object CC_ofsf_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v168, v169;
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
    v163 = stack[0];
    v163 = qcdr(v163);
    v168 = qcar(v163);
    v163 = stack[0];
    v163 = qcdr(v163);
    v163 = qcdr(v163);
    v163 = qcar(v163);
    v163 = list2(v168, v163);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v163;
    v163 = stack[0];
    v163 = qcar(v163);
    fn = elt(env, 1); /* ofsf_lnegrel */
    v169 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v163 = stack[-1];
    v168 = qcar(v163);
    v163 = stack[-1];
    v163 = qcdr(v163);
    v163 = qcar(v163);
    popv(3);
    return list3(v169, v168, v163);
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for simpexpt1 */

static Lisp_Object MS_CDECL CC_simpexpt1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v170, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v225, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt1");
#endif
    if (stack >= stacklimit)
    {
        push3(v170,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v170);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v170;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = qvalue(elt(env, 1)); /* !*allfac */
    qvalue(elt(env, 1)) = nil; /* !*allfac */
    stack[-3] = qvalue(elt(env, 2)); /* !*div */
    qvalue(elt(env, 2)) = nil; /* !*div */
    v224 = stack[-6];
    v224 = Lonep(nil, v224);
    env = stack[-8];
    if (v224 == nil) goto v157;
    v225 = (Lisp_Object)17; /* 1 */
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v156:
    qvalue(elt(env, 2)) = stack[-3]; /* !*div */
    qvalue(elt(env, 1)) = stack[-7]; /* !*allfac */
    { popv(9); return onevalue(v224); }

v157:
    v224 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v224; /* !*allfac */
    v224 = stack[-5];
    v224 = qcar(v224);
    stack[-2] = v224;
    v225 = stack[-2];
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v97;
    v224 = stack[-5];
    v225 = qcdr(v224);
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v97;
    v224 = stack[-6];
    fn = elt(env, 13); /* simp */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v97:
    v225 = stack[-6];
    v224 = elt(env, 4); /* e */
    if (!(v225 == v224)) goto v227;
    v224 = stack[-5];
    v224 = qcdr(v224);
    if (!consp(v224)) goto v228;
    v224 = stack[-5];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    if (!(!consp(v224))) goto v227;

v228:
    v224 = stack[-2];
    if (!consp(v224)) goto v227;
    v224 = stack[-2];
    v224 = qcar(v224);
    if (!consp(v224)) goto v227;
    v224 = stack[-2];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v225 = qcdr(v224);
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v227;
    v224 = stack[-2];
    v224 = qcdr(v224);
    if (!(v224 == nil)) goto v227;
    v224 = stack[-2];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v225 = qcar(v224);
    v224 = elt(env, 5); /* log */
    if (!consp(v225)) goto v227;
    v225 = qcar(v225);
    if (!(v225 == v224)) goto v227;
    v224 = stack[-2];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v224 = qcar(v224);
    v224 = qcdr(v224);
    v224 = qcar(v224);
    fn = elt(env, 14); /* simp!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    fn = elt(env, 15); /* prepsq!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v224 = stack[-2];
    v224 = qcar(v224);
    v225 = qcdr(v224);
    v224 = stack[-5];
    v224 = qcdr(v224);
    v225 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v224 = qvalue(elt(env, 6)); /* nil */
    v224 = CC_simpexpt1(env, 3, stack[0], v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v227:
    v224 = stack[-2];
    if (!consp(v224)) goto v229;
    v224 = stack[-2];
    v224 = qcar(v224);
    if (!(!consp(v224))) goto v230;

v229:
    v224 = stack[-5];
    v224 = qcdr(v224);
    if (!consp(v224)) goto v135;
    v224 = stack[-5];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    if (!(!consp(v224))) goto v230;

v135:
    v224 = stack[-6];
    fn = elt(env, 13); /* simp */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    stack[-1] = v224;
    v224 = stack[-2];
    if (v224 == nil) goto v231;
    v224 = stack[-1];
    v224 = qcar(v224);
    if (v224 == nil) goto v232;
    v224 = stack[-2];
    if (!(!consp(v224))) goto v233;
    v224 = stack[-5];
    v225 = qcdr(v224);
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v233;
    v224 = stack[-1];
    v224 = qcar(v224);
    if (!consp(v224)) goto v234;
    v224 = stack[-1];
    v224 = qcar(v224);
    v224 = qcar(v224);
    if (!(!consp(v224))) goto v233;

v234:
    v224 = stack[-1];
    v225 = qcdr(v224);
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v233;
    v224 = stack[-1];
    v224 = qcar(v224);
    if (!(!consp(v224))) goto v55;
    v225 = stack[-2];
    v224 = (Lisp_Object)1; /* 0 */
    v224 = (Lisp_Object)greaterp2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v224 = v224 ? lisp_true : nil;
    env = stack[-8];
    if (v224 == nil) goto v55;
    v224 = stack[-1];
    v225 = qcar(v224);
    v224 = stack[-2];
    v224 = Lexpt(nil, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    fn = elt(env, 16); /* !*d2q */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v55:
    v224 = stack[-1];
    v225 = qcar(v224);
    v224 = stack[-2];
    fn = elt(env, 17); /* !:expt */
    v225 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    stack[-1] = v224;
    v224 = qvalue(elt(env, 11)); /* !*mcd */
    if (v224 == nil) goto v235;
    v224 = stack[-1];
    fn = elt(env, 18); /* resimp */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v235:
    v224 = stack[-1];
    goto v156;

v233:
    stack[0] = elt(env, 12); /* expt */
    v225 = stack[-1];
    v224 = stack[-5];
    v224 = list2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    fn = elt(env, 19); /* domainvalchk */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v225 = v224;
    if (v224 == nil) goto v236;
    v224 = v225;
    goto v156;

v236:
    v224 = stack[-2];
    if (!(!consp(v224))) goto v237;
    v224 = stack[-5];
    v225 = qcdr(v224);
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v237;
    v225 = stack[-2];
    v224 = (Lisp_Object)1; /* 0 */
    v224 = (Lisp_Object)lessp2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v224 = v224 ? lisp_true : nil;
    env = stack[-8];
    if (v224 == nil) goto v238;
    v224 = qvalue(elt(env, 11)); /* !*mcd */
    if (v224 == nil) goto v239;
    stack[0] = stack[-1];
    v224 = stack[-2];
    v224 = negate(v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    fn = elt(env, 20); /* exptsq */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    fn = elt(env, 21); /* invsq */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v239:
    v224 = stack[-1];
    v225 = qcar(v224);
    v224 = stack[-2];
    fn = elt(env, 22); /* expf */
    stack[0] = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v224 = stack[-1];
    stack[-1] = qcdr(v224);
    v224 = stack[-2];
    v224 = negate(v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    fn = elt(env, 23); /* mksfpf */
    v224 = (*qfn2(fn))(qenv(fn), stack[-1], v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    fn = elt(env, 24); /* multf */
    v225 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v238:
    v225 = stack[-1];
    v224 = stack[-2];
    fn = elt(env, 20); /* exptsq */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v237:
    v224 = stack[-4];
    if (v224 == nil) goto v240;
    v224 = stack[-6];
    v226 = v224;
    goto v241;

v241:
    v225 = stack[-5];
    v224 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 25); /* simpexpt11 */
    v224 = (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v240:
    v224 = stack[-1];
    fn = elt(env, 26); /* subs2!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    fn = elt(env, 15); /* prepsq!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v226 = v224;
    goto v241;

v232:
    v224 = stack[-2];
    if (!consp(v224)) goto v242;
    v224 = stack[-2];
    v224 = qcar(v224);
    if (!(!consp(v224))) goto v71;

v242:
    v224 = stack[-2];
    fn = elt(env, 27); /* minusf */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    if (v224 == nil) goto v71;
    v224 = elt(env, 10); /* "Zero divisor" */
    v225 = v224;
    v224 = v225;
    qvalue(elt(env, 8)) = v224; /* errmsg!* */
    v224 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v224 == nil)) goto v243;
    v224 = v225;
    fn = elt(env, 28); /* lprie */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v243;

v243:
    v224 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v224 = nil;
    goto v156;

v71:
    v225 = qvalue(elt(env, 6)); /* nil */
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v231:
    v224 = stack[-1];
    v224 = qcar(v224);
    if (v224 == nil) goto v244;
    v225 = (Lisp_Object)17; /* 1 */
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;

v244:
    v224 = elt(env, 7); /* "0**0 formed" */
    v225 = v224;
    v224 = v225;
    qvalue(elt(env, 8)) = v224; /* errmsg!* */
    v224 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v224 == nil)) goto v245;
    v224 = v225;
    fn = elt(env, 28); /* lprie */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v245;

v245:
    v224 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    v224 = nil;
    goto v156;

v230:
    v226 = stack[-6];
    v225 = stack[-5];
    v224 = stack[-4];
    fn = elt(env, 25); /* simpexpt11 */
    v224 = (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-8];
    goto v156;
/* error exit handlers */
v22:
    env = stack[-8];
    qvalue(elt(env, 2)) = stack[-3]; /* !*div */
    qvalue(elt(env, 1)) = stack[-7]; /* !*allfac */
    popv(9);
    return nil;
}



/* Code for getargsrd */

static Lisp_Object MS_CDECL CC_getargsrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "getargsrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getargsrd");
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
    v154 = qvalue(elt(env, 1)); /* char */
    v155 = elt(env, 2); /* (b v a r) */
    if (equal(v154, v155)) goto v183;
    v155 = nil;
    { popv(2); return onevalue(v155); }

v183:
    fn = elt(env, 3); /* bvarrd */
    v155 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    stack[0] = v155;
    fn = elt(env, 4); /* lex */
    v155 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    v155 = CC_getargsrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v101;
    {
        Lisp_Object v246 = stack[0];
        popv(2);
        return cons(v246, v155);
    }
/* error exit handlers */
v101:
    popv(2);
    return nil;
}



/* Code for remdiff */

static Lisp_Object CC_remdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v252, v253;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remdiff");
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
    stack[-1] = v0;
/* end of prologue */
    v252 = stack[-1];
    if (symbolp(v252)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v252 = stack[-1];
    fn = elt(env, 5); /* constp */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    if (!(v252 == nil)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v252 = stack[-1];
    v253 = qcar(v252);
    v252 = elt(env, 1); /* difference */
    if (v253 == v252) goto v100;
    v252 = stack[-1];
    stack[-4] = qcar(v252);
    v252 = stack[-1];
    v252 = qcdr(v252);
    stack[-3] = v252;
    v252 = stack[-3];
    if (v252 == nil) goto v145;
    v252 = stack[-3];
    v252 = qcar(v252);
    v252 = CC_remdiff(env, v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    v252 = ncons(v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    stack[-1] = v252;
    stack[-2] = v252;
    goto v151;

v151:
    v252 = stack[-3];
    v252 = qcdr(v252);
    stack[-3] = v252;
    v252 = stack[-3];
    if (v252 == nil) goto v254;
    stack[0] = stack[-1];
    v252 = stack[-3];
    v252 = qcar(v252);
    v252 = CC_remdiff(env, v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    v252 = ncons(v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    v252 = Lrplacd(nil, stack[0], v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    v252 = stack[-1];
    v252 = qcdr(v252);
    stack[-1] = v252;
    goto v151;

v254:
    v252 = stack[-2];
    goto v148;

v148:
    {
        Lisp_Object v104 = stack[-4];
        popv(6);
        return cons(v104, v252);
    }

v145:
    v252 = qvalue(elt(env, 4)); /* nil */
    goto v148;

v100:
    stack[-3] = elt(env, 2); /* plus */
    v252 = stack[-1];
    v252 = qcdr(v252);
    v252 = qcar(v252);
    stack[-2] = CC_remdiff(env, v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    stack[0] = elt(env, 3); /* minus */
    v252 = stack[-1];
    v252 = qcdr(v252);
    v252 = qcdr(v252);
    v252 = qcar(v252);
    v252 = CC_remdiff(env, v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    v252 = list2(stack[0], v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-5];
    v252 = list3(stack[-3], stack[-2], v252);
    nil = C_nil;
    if (exception_pending()) goto v91;
    { popv(6); return onevalue(v252); }
/* error exit handlers */
v91:
    popv(6);
    return nil;
}



/* Code for suspend */

static Lisp_Object MS_CDECL CC_suspend(Lisp_Object env, int nargs,
                         Lisp_Object v255, Lisp_Object v171,
                         Lisp_Object v172, Lisp_Object v183,
                         Lisp_Object v112, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v247, v218, v219, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "suspend");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for suspend");
#endif
    if (stack >= stacklimit)
    {
        push5(v112,v183,v172,v171,v255);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v255,v171,v172,v183,v112);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v112;
    v218 = v183;
    v219 = v172;
    v228 = v171;
    v247 = v255;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-6] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-5] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v247; /* op */
    v247 = v228;
    qvalue(elt(env, 2)) = v247; /* r */
    v247 = v219;
    qvalue(elt(env, 3)) = v247; /* p */
    v247 = qvalue(elt(env, 2)); /* r */
    stack[-4] = qcar(v247);
    v247 = qvalue(elt(env, 3)); /* p */
    stack[-3] = qcar(v247);
    stack[-2] = v218;
    stack[-1] = qvalue(elt(env, 1)); /* op */
    v247 = qvalue(elt(env, 2)); /* r */
    stack[0] = qcdr(v247);
    v218 = qvalue(elt(env, 1)); /* op */
    v247 = qvalue(elt(env, 3)); /* p */
    v247 = qcdr(v247);
    v247 = cons(v218, v247);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    v247 = ncons(v247);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    v218 = acons(stack[-1], stack[0], v247);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    v247 = stack[-7];
    v247 = cons(v218, v247);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    fn = elt(env, 4); /* amatch */
    v247 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-3], stack[-2], v247);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; /* p */
    qvalue(elt(env, 2)) = stack[-6]; /* r */
    qvalue(elt(env, 1)) = stack[-8]; /* op */
    { popv(10); return onevalue(v247); }
/* error exit handlers */
v159:
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; /* p */
    qvalue(elt(env, 2)) = stack[-6]; /* r */
    qvalue(elt(env, 1)) = stack[-8]; /* op */
    popv(10);
    return nil;
}



/* Code for matsm */

static Lisp_Object CC_matsm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v259;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm");
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
    v148 = v0;
/* end of prologue */
    stack[-2] = nil;
    v259 = v148;
    v148 = elt(env, 1); /* matrix */
    fn = elt(env, 3); /* nssimp */
    v148 = (*qfn2(fn))(qenv(fn), v259, v148);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-3];
    stack[-1] = v148;
    goto v173;

v173:
    v148 = stack[-1];
    if (v148 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v148 = stack[-1];
    v148 = qcar(v148);
    v259 = v148;
    v148 = v259;
    stack[0] = qcar(v148);
    v148 = v259;
    v148 = qcdr(v148);
    fn = elt(env, 4); /* matsm1 */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-3];
    fn = elt(env, 5); /* multsm */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-3];
    v259 = stack[-2];
    if (v259 == nil) goto v222;
    v259 = stack[-2];
    fn = elt(env, 6); /* addm */
    v148 = (*qfn2(fn))(qenv(fn), v259, v148);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-3];
    goto v222;

v222:
    stack[-2] = v148;
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v173;
/* error exit handlers */
v219:
    popv(4);
    return nil;
}



/* Code for bcminus!? */

static Lisp_Object CC_bcminusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcminus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v167 = v0;
/* end of prologue */
    v149 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v149 == nil) goto v191;
    v149 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v149);

v191:
    v149 = v167;
    v149 = qcar(v149);
    {
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v149);
    }
}



/* Code for numprintlen */

static Lisp_Object CC_numprintlen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v284, v285;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numprintlen");
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
    stack[-1] = v0;
/* end of prologue */

v171:
    v284 = stack[-1];
    if (!consp(v284)) goto v112;
    v284 = stack[-1];
    v284 = Llength(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = Lonep(nil, v284);
    env = stack[-6];
    if (v284 == nil) goto v287;
    v284 = stack[-1];
    v284 = qcar(v284);
    stack[-1] = v284;
    goto v171;

v287:
    v284 = stack[-1];
    v285 = qcar(v284);
    v284 = elt(env, 1); /* !:rd!: */
    if (v285 == v284) goto v168;
    v284 = stack[-1];
    v285 = qcar(v284);
    v284 = elt(env, 3); /* (!:cr!: !:crn!: !:gi!:) */
    v284 = Lmemq(nil, v285, v284);
    if (v284 == nil) goto v288;
    v285 = elt(env, 1); /* !:rd!: */
    v284 = stack[-1];
    v284 = qcdr(v284);
    v284 = qcar(v284);
    v284 = cons(v285, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v285 = v284;
    v284 = v285;
    v284 = qcdr(v284);
    if (!consp(v284)) goto v289;
    v284 = v285;
    stack[0] = v284;
    goto v290;

v290:
    v285 = qvalue(elt(env, 2)); /* !:bprec!: */
    v284 = (Lisp_Object)49; /* 3 */
    v284 = difference2(v285, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v284 = (*qfn2(fn))(qenv(fn), stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    stack[0] = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v285 = elt(env, 1); /* !:rd!: */
    v284 = stack[-1];
    v284 = qcdr(v284);
    v284 = qcdr(v284);
    v284 = cons(v285, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v285 = v284;
    v284 = v285;
    v284 = qcdr(v284);
    if (!consp(v284)) goto v291;
    v284 = v285;
    stack[-1] = v284;
    goto v205;

v205:
    v285 = qvalue(elt(env, 2)); /* !:bprec!: */
    v284 = (Lisp_Object)49; /* 3 */
    v284 = difference2(v285, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v284 = (*qfn2(fn))(qenv(fn), stack[-1], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = cons(stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-1] = v284;
    stack[-4] = (Lisp_Object)193; /* 12 */
    v284 = stack[-1];
    v284 = qcar(v284);
    v284 = qcar(v284);
    stack[-3] = Llength(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = stack[-1];
    v284 = qcar(v284);
    v284 = qcdr(v284);
    v284 = Lexplode(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-2] = Llength(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = stack[-1];
    v284 = qcdr(v284);
    v284 = qcar(v284);
    stack[0] = Llength(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = stack[-1];
    v284 = qcdr(v284);
    v284 = qcdr(v284);
    v284 = Lexplode(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = Llength(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = plus2(stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = plus2(stack[-2], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = plus2(stack[-3], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    {
        Lisp_Object v292 = stack[-4];
        popv(7);
        return plus2(v292, v284);
    }

v291:
    v284 = v285;
    v284 = qcdr(v284);
    fn = elt(env, 9); /* fl2bf */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-1] = v284;
    goto v205;

v289:
    v284 = v285;
    v284 = qcdr(v284);
    fn = elt(env, 9); /* fl2bf */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[0] = v284;
    goto v290;

v288:
    v284 = stack[-1];
    stack[-5] = Llength(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-4] = elt(env, 4); /* plus */
    v284 = stack[-1];
    v284 = qcdr(v284);
    stack[-3] = v284;
    v284 = stack[-3];
    if (v284 == nil) goto v293;
    v284 = stack[-3];
    v284 = qcar(v284);
    v284 = CC_numprintlen(env, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = ncons(v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-1] = v284;
    stack[-2] = v284;
    goto v294;

v294:
    v284 = stack[-3];
    v284 = qcdr(v284);
    stack[-3] = v284;
    v284 = stack[-3];
    if (v284 == nil) goto v295;
    stack[0] = stack[-1];
    v284 = stack[-3];
    v284 = qcar(v284);
    v284 = CC_numprintlen(env, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = ncons(v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = Lrplacd(nil, stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = stack[-1];
    v284 = qcdr(v284);
    stack[-1] = v284;
    goto v294;

v295:
    v284 = stack[-2];
    goto v296;

v296:
    v284 = cons(stack[-4], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 10); /* eval */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    {
        Lisp_Object v297 = stack[-5];
        popv(7);
        return plus2(v297, v284);
    }

v293:
    v284 = qvalue(elt(env, 5)); /* nil */
    goto v296;

v168:
    v284 = stack[-1];
    v284 = qcdr(v284);
    if (!consp(v284)) goto v298;
    v284 = stack[-1];
    stack[0] = v284;
    goto v299;

v299:
    v285 = qvalue(elt(env, 2)); /* !:bprec!: */
    v284 = (Lisp_Object)49; /* 3 */
    v284 = difference2(v285, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v284 = (*qfn2(fn))(qenv(fn), stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-1] = v284;
    stack[-2] = (Lisp_Object)33; /* 2 */
    v284 = stack[-1];
    v284 = qcar(v284);
    stack[0] = Llength(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = stack[-1];
    v284 = qcdr(v284);
    v284 = qcar(v284);
    v284 = Lexplode(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = Llength(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v284 = plus2(stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    {
        Lisp_Object v300 = stack[-2];
        popv(7);
        return plus2(v300, v284);
    }

v298:
    v284 = stack[-1];
    v284 = qcdr(v284);
    fn = elt(env, 9); /* fl2bf */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[0] = v284;
    goto v299;

v112:
    v284 = stack[-1];
    v284 = Lexplode(nil, v284);
    nil = C_nil;
    if (exception_pending()) goto v286;
        popv(7);
        return Llength(nil, v284);
/* error exit handlers */
v286:
    popv(7);
    return nil;
}



/* Code for indxchk */

static Lisp_Object CC_indxchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indxchk");
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
    v159 = v0;
/* end of prologue */
    stack[-1] = v159;
    v160 = qvalue(elt(env, 1)); /* indxl!* */
    v159 = qvalue(elt(env, 2)); /* nosuml!* */
    fn = elt(env, 5); /* union */
    v159 = (*qfn2(fn))(qenv(fn), v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-2];
    stack[0] = v159;
    goto v183;

v183:
    v159 = stack[-1];
    if (v159 == nil) goto v303;
    v159 = stack[-1];
    v159 = qcar(v159);
    if (!consp(v159)) goto v168;
    v159 = stack[-1];
    v159 = qcar(v159);
    v159 = qcdr(v159);
    v159 = qcar(v159);
    if (is_number(v159)) goto v299;
    v159 = stack[-1];
    v159 = qcar(v159);
    v159 = qcdr(v159);
    v159 = qcar(v159);
    v160 = v159;
    goto v101;

v101:
    v159 = stack[0];
    v159 = Lmemq(nil, v160, v159);
    if (v159 == nil) goto v164;
    v159 = stack[-1];
    v159 = qcdr(v159);
    stack[-1] = v159;
    goto v183;

v164:
    v159 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v159); }

v299:
    v159 = stack[-1];
    v159 = qcar(v159);
    v159 = qcdr(v159);
    v159 = qcar(v159);
    fn = elt(env, 6); /* !*num2id */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-2];
    v160 = v159;
    goto v101;

v168:
    v159 = stack[-1];
    v159 = qcar(v159);
    if (is_number(v159)) goto v222;
    v159 = stack[-1];
    v159 = qcar(v159);
    goto v152;

v152:
    v160 = v159;
    goto v101;

v222:
    v159 = stack[-1];
    v159 = qcar(v159);
    v159 = Labsval(nil, v159);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-2];
    fn = elt(env, 6); /* !*num2id */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-2];
    goto v152;

v303:
    v159 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v159); }
/* error exit handlers */
v302:
    popv(3);
    return nil;
}



/* Code for color!-strand */

static Lisp_Object MS_CDECL CC_colorKstrand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v170, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v298, v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color-strand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color-strand");
#endif
    if (stack >= stacklimit)
    {
        push3(v170,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v170);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v170;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v112;

v112:
    v298 = stack[-1];
    if (v298 == nil) goto v156;
    v98 = stack[-2];
    v298 = stack[-1];
    v298 = qcar(v298);
    fn = elt(env, 1); /* color!-roads */
    v99 = (*qfn2(fn))(qenv(fn), v98, v298);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    v98 = stack[0];
    v298 = stack[-3];
    v298 = acons(v99, v98, v298);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    stack[-3] = v298;
    v298 = stack[-1];
    v298 = qcdr(v298);
    stack[-1] = v298;
    v298 = stack[0];
    v298 = add1(v298);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-4];
    stack[0] = v298;
    goto v112;

v156:
    v298 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v298);
    }
/* error exit handlers */
v220:
    popv(5);
    return nil;
}



/* Code for reduce!-columns */

static Lisp_Object MS_CDECL CC_reduceKcolumns(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v170, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v316, v317;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-columns");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-columns");
#endif
    if (stack >= stacklimit)
    {
        push3(v170,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v170);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v170;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v316 = stack[-6];
    stack[-3] = v316;
    v316 = stack[-5];
    stack[-2] = v316;
    stack[0] = stack[-6];
    v317 = stack[-6];
    v316 = stack[-4];
    fn = elt(env, 2); /* red!-weight */
    v316 = (*qfn2(fn))(qenv(fn), v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    v316 = cons(stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    stack[-7] = v316;
    goto v256;

v256:
    v316 = stack[-3];
    if (v316 == nil) goto v165;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = (Lisp_Object)1; /* 0 */
    if (v317 == v316) goto v257;
    v316 = stack[-2];
    v317 = qcar(v316);
    v316 = (Lisp_Object)1; /* 0 */
    if (v317 == v316) goto v257;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = stack[-2];
    v316 = qcar(v316);
    v316 = Ldivide(nil, v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    stack[-1] = v316;
    v317 = qcdr(v316);
    v316 = (Lisp_Object)1; /* 0 */
    if (!(v317 == v316)) goto v257;
    stack[0] = stack[-6];
    v316 = stack[-1];
    v317 = qcar(v316);
    v316 = stack[-5];
    fn = elt(env, 3); /* mv!-domainlist!-!* */
    v316 = (*qfn2(fn))(qenv(fn), v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    fn = elt(env, 4); /* mv!-domainlist!-!- */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    stack[-1] = v316;
    v317 = stack[-1];
    v316 = stack[-4];
    fn = elt(env, 2); /* red!-weight */
    v316 = (*qfn2(fn))(qenv(fn), v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    stack[0] = v316;
    v317 = stack[0];
    v316 = stack[-7];
    v316 = qcdr(v316);
    fn = elt(env, 5); /* red!-weight!-less!-p */
    v316 = (*qfn2(fn))(qenv(fn), v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    if (v316 == nil) goto v257;
    v317 = stack[-1];
    v316 = stack[0];
    v317 = cons(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    v316 = stack[-7];
    fn = elt(env, 6); /* more!-apartp */
    v316 = (*qfn2(fn))(qenv(fn), v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    if (!(v316 == nil)) goto v257;
    v317 = stack[-1];
    v316 = stack[0];
    v316 = cons(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-8];
    stack[-7] = v316;
    goto v257;

v257:
    v316 = stack[-3];
    v316 = qcdr(v316);
    stack[-3] = v316;
    v316 = stack[-2];
    v316 = qcdr(v316);
    stack[-2] = v316;
    goto v256;

v165:
    v316 = stack[-7];
    v316 = qcar(v316);
    { popv(9); return onevalue(v316); }
/* error exit handlers */
v318:
    popv(9);
    return nil;
}



/* Code for matop_pseudomod */

static Lisp_Object CC_matop_pseudomod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matop_pseudomod");
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
    v157 = v1;
    v149 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mod!* */
    v157 = (*qfn2(fn))(qenv(fn), v149, v157);
    errexit();
    v157 = qcar(v157);
    return onevalue(v157);
}



/* Code for pa_list2vect */

static Lisp_Object CC_pa_list2vect(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v321, v322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_list2vect");
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
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    v321 = (Lisp_Object)1; /* 0 */
    stack[-3] = v321;
    v321 = stack[-5];
    v321 = sub1(v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    v321 = Lmkvect(nil, v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    stack[-6] = v321;
    v321 = stack[0];
    stack[-2] = v321;
    goto v166;

v166:
    v321 = stack[-2];
    if (v321 == nil) goto v167;
    v321 = stack[-2];
    v321 = qcar(v321);
    stack[0] = v321;
    v322 = elt(env, 2); /* min */
    v321 = stack[0];
    v321 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    fn = elt(env, 3); /* eval */
    v322 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    v321 = stack[-4];
    v321 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    stack[-4] = v321;
    v321 = stack[0];
    stack[-1] = v321;
    goto v250;

v250:
    v321 = stack[-1];
    if (v321 == nil) goto v114;
    v321 = stack[-1];
    v321 = qcar(v321);
    stack[0] = stack[-6];
    v322 = sub1(v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    v321 = stack[-4];
    v321 = qcar(v321);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v322/(16/CELL))) = v321;
    v321 = stack[-1];
    v321 = qcdr(v321);
    stack[-1] = v321;
    goto v250;

v114:
    v321 = stack[-2];
    v321 = qcdr(v321);
    stack[-2] = v321;
    goto v166;

v167:
    v321 = (Lisp_Object)17; /* 1 */
    stack[-1] = v321;
    goto v323;

v323:
    v322 = stack[-5];
    v321 = stack[-1];
    v321 = difference2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    v321 = Lminusp(nil, v321);
    env = stack[-7];
    if (v321 == nil) goto v249;
    v321 = stack[-4];
    v322 = Lreverse(nil, v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    v321 = stack[-6];
    popv(8);
    return cons(v322, v321);

v249:
    stack[0] = stack[-6];
    v321 = stack[-1];
    v321 = sub1(v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    v321 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v321/(16/CELL)));
    if (!(v321 == nil)) goto v92;
    v322 = stack[-3];
    v321 = (Lisp_Object)1; /* 0 */
    if (!(v322 == v321)) goto v324;
    v321 = stack[-1];
    stack[-3] = v321;
    v322 = stack[-3];
    v321 = stack[-4];
    v321 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    stack[-4] = v321;
    goto v324;

v324:
    stack[0] = stack[-6];
    v321 = stack[-1];
    v322 = sub1(v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    v321 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v322/(16/CELL))) = v321;
    goto v92;

v92:
    v321 = stack[-1];
    v321 = add1(v321);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-7];
    stack[-1] = v321;
    goto v323;
/* error exit handlers */
v291:
    popv(8);
    return nil;
}



/* Code for build!-null!-vector */

static Lisp_Object MS_CDECL CC_buildKnullKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v170, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v145, v158, v159, v160, v313, v161, v302;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "build-null-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for build-null-vector");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v160 = v170;
    v313 = v1;
    v161 = v0;
/* end of prologue */
    v143 = (Lisp_Object)17; /* 1 */
    v302 = v143;
    goto v166;

v166:
    v143 = v161;
    v145 = (Lisp_Object)((int32_t)(v143) - 0x10);
    v143 = v302;
    v143 = (Lisp_Object)(int32_t)((int32_t)v145 - (int32_t)v143 + TAG_FIXNUM);
    v143 = ((intptr_t)(v143) < 0 ? lisp_true : nil);
    if (v143 == nil) goto v154;
    v158 = v313;
    v145 = v161;
    v143 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v158 + (CELL-TAG_VECTOR) + ((int32_t)v145/(16/CELL))) = v143;
    v143 = v313;
    v145 = v161;
    return cons(v143, v145);

v154:
    v159 = v313;
    v158 = v302;
    v145 = v160;
    v143 = v302;
    v145 = *(Lisp_Object *)((char *)v145 + (CELL-TAG_VECTOR) + ((int32_t)v143/(16/CELL)));
    v143 = v161;
    v143 = *(Lisp_Object *)((char *)v145 + (CELL-TAG_VECTOR) + ((int32_t)v143/(16/CELL)));
    *(Lisp_Object *)((char *)v159 + (CELL-TAG_VECTOR) + ((int32_t)v158/(16/CELL))) = v143;
    v143 = v302;
    v143 = (Lisp_Object)((int32_t)(v143) + 0x10);
    v302 = v143;
    goto v166;
}



/* Code for listeval0 */

static Lisp_Object CC_listeval0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95, v309;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeval0");
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
    v94 = qvalue(elt(env, 1)); /* simpcount!* */
    v95 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-1];
    qvalue(elt(env, 1)) = v95; /* simpcount!* */
    v94 = qvalue(elt(env, 2)); /* simplimit!* */
    v94 = (Lisp_Object)greaterp2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v94 = v94 ? lisp_true : nil;
    env = stack[-1];
    if (v94 == nil) goto v183;
    v94 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v94; /* simpcount!* */
    v94 = elt(env, 3); /* "Simplification recursion too deep" */
    v95 = v94;
    v94 = v95;
    qvalue(elt(env, 4)) = v94; /* errmsg!* */
    v94 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v94 == nil)) goto v155;
    v94 = v95;
    fn = elt(env, 8); /* lprie */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-1];
    goto v155;

v155:
    v94 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-1];
    goto v183;

v183:
    v94 = stack[0];
    if (!(symbolp(v94))) goto v168;
    v95 = stack[0];
    v94 = elt(env, 6); /* share */
    v94 = Lflagp(nil, v95, v94);
    env = stack[-1];
    if (v94 == nil) goto v97;
    v94 = stack[0];
    fn = elt(env, 9); /* eval */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-1];
    v94 = CC_listeval0(env, v94);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-1];
    stack[0] = v94;
    goto v168;

v168:
    v94 = qvalue(elt(env, 1)); /* simpcount!* */
    v94 = sub1(v94);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-1];
    qvalue(elt(env, 1)) = v94; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v97:
    v95 = stack[0];
    v94 = elt(env, 7); /* avalue */
    v94 = get(v95, v94);
    env = stack[-1];
    v309 = v94;
    if (v94 == nil) goto v168;
    v94 = v309;
    v94 = qcdr(v94);
    v95 = qcar(v94);
    v94 = stack[0];
    if (equal(v95, v94)) goto v168;
    v94 = v309;
    v94 = qcdr(v94);
    v94 = qcar(v94);
    v94 = CC_listeval0(env, v94);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-1];
    stack[0] = v94;
    goto v168;
/* error exit handlers */
v323:
    popv(2);
    return nil;
}



/* Code for min2!-order */

static Lisp_Object MS_CDECL CC_min2Korder(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v170, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v323, v254;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "min2-order");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for min2-order");
#endif
    if (stack >= stacklimit)
    {
        push3(v170,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v170);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v170;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v112;

v112:
    v323 = stack[-3];
    if (v323 == nil) goto v156;
    v323 = stack[-1];
    v323 = qcar(v323);
    stack[0] = v323;
    v323 = (Lisp_Object)1; /* 0 */
    v254 = v323;
    goto v100;

v100:
    v323 = stack[0];
    if (v323 == nil) goto v168;
    v323 = stack[0];
    v323 = qcar(v323);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v323 = (*qfn2(fn))(qenv(fn), v323, v254);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v254 = v323;
    v323 = stack[0];
    v323 = qcdr(v323);
    stack[0] = v323;
    goto v100;

v168:
    v323 = v254;
    stack[0] = v323;
    v254 = stack[0];
    v323 = stack[-2];
    v323 = qcar(v323);
    fn = elt(env, 2); /* tayexp!-greaterp */
    v323 = (*qfn2(fn))(qenv(fn), v254, v323);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    if (v323 == nil) goto v159;
    v254 = stack[0];
    v323 = stack[-3];
    v323 = qcar(v323);
    fn = elt(env, 3); /* tayexp!-min2 */
    v323 = (*qfn2(fn))(qenv(fn), v254, v323);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v254 = v323;
    goto v162;

v162:
    v323 = stack[-4];
    v323 = cons(v254, v323);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-4] = v323;
    v323 = stack[-3];
    v323 = qcdr(v323);
    stack[-3] = v323;
    v323 = stack[-2];
    v323 = qcdr(v323);
    stack[-2] = v323;
    v323 = stack[-1];
    v323 = qcdr(v323);
    stack[-1] = v323;
    goto v112;

v159:
    v323 = stack[-3];
    v323 = qcar(v323);
    v254 = v323;
    goto v162;

v156:
    v323 = stack[-4];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v323);
    }
/* error exit handlers */
v312:
    popv(6);
    return nil;
}



/* Code for evalnumberp */

static Lisp_Object CC_evalnumberp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283, v299, v227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalnumberp");
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
    v283 = v0;
/* end of prologue */
    fn = elt(env, 4); /* aeval */
    v283 = (*qfn1(fn))(qenv(fn), v283);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[0];
    v227 = v283;
    v283 = v227;
    if (!consp(v283)) goto v112;
    v283 = v227;
    v299 = qcar(v283);
    v283 = elt(env, 1); /* !*sq */
    if (!(v299 == v283)) goto v157;
    v283 = v227;
    v283 = qcdr(v283);
    v283 = qcar(v283);
    v283 = qcdr(v283);
    if (!(!consp(v283))) goto v157;
    v283 = v227;
    v283 = qcdr(v283);
    v283 = qcar(v283);
    v283 = qcar(v283);
    v299 = v283;
    v283 = v299;
    v283 = (consp(v283) ? nil : lisp_true);
    if (!(v283 == nil)) { popv(1); return onevalue(v283); }
    v283 = v299;
    v283 = qcar(v283);
    v299 = elt(env, 3); /* numbertag */
        popv(1);
        return Lflagp(nil, v283, v299);

v157:
    v283 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v283); }

v112:
    v283 = v227;
    v283 = (is_number(v283) ? lisp_true : nil);
    { popv(1); return onevalue(v283); }
/* error exit handlers */
v260:
    popv(1);
    return nil;
}



/* Code for pasf_susibinad */

static Lisp_Object CC_pasf_susibinad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v342, v116, v343, v344, v284;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susibinad");
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
    v58 = stack[-4];
    v59 = qcdr(v58);
    v58 = stack[-3];
    v58 = qcdr(v58);
    fn = elt(env, 7); /* cl_susiminlevel */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    stack[-1] = v58;
    v58 = stack[-4];
    v58 = qcar(v58);
    stack[-4] = v58;
    v58 = stack[-3];
    v58 = qcar(v58);
    stack[-3] = v58;
    v59 = stack[-3];
    v58 = elt(env, 1); /* false */
    if (v59 == v58) goto v246;
    v59 = stack[-3];
    v58 = elt(env, 2); /* true */
    if (v59 == v58) goto v98;
    v58 = stack[-4];
    v58 = qcdr(v58);
    v59 = qcar(v58);
    v58 = stack[-3];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    if (equal(v59, v58)) goto v301;
    v58 = stack[-4];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    fn = elt(env, 8); /* pasf_dec */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    stack[-5] = v58;
    v58 = stack[-3];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    fn = elt(env, 8); /* pasf_dec */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    stack[-2] = v58;
    v58 = stack[-5];
    v59 = qcar(v58);
    v58 = stack[-2];
    v58 = qcar(v58);
    if (equal(v59, v58)) goto v90;
    v58 = stack[-5];
    v59 = qcar(v58);
    v58 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 9); /* kernels1 */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    stack[0] = v58;
    v58 = stack[-2];
    v59 = qcar(v58);
    v58 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 9); /* kernels1 */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    v342 = v58;
    v58 = stack[-4];
    v59 = qcar(v58);
    v58 = elt(env, 5); /* equal */
    if (!(v59 == v58)) goto v74;
    v58 = stack[0];
    v58 = qcdr(v58);
    if (!(v58 == nil)) goto v74;
    v58 = stack[0];
    v59 = qcar(v58);
    v58 = v342;
    v58 = Lmemq(nil, v59, v58);
    if (v58 == nil) goto v74;
    stack[-2] = stack[-3];
    v58 = stack[0];
    stack[0] = qcar(v58);
    v58 = stack[-5];
    v58 = qcdr(v58);
    fn = elt(env, 10); /* negf */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    fn = elt(env, 11); /* pasf_subfof1 */
    v342 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    v59 = stack[-1];
    v58 = qvalue(elt(env, 6)); /* t */
    {
        popv(7);
        fn = elt(env, 12); /* pasf_susibinad1 */
        return (*qfnn(fn))(qenv(fn), 3, v342, v59, v58);
    }

v74:
    v58 = stack[-3];
    v59 = qcar(v58);
    v58 = elt(env, 5); /* equal */
    if (!(v59 == v58)) goto v346;
    v58 = v342;
    v58 = qcdr(v58);
    if (!(v58 == nil)) goto v346;
    v58 = v342;
    v59 = qcar(v58);
    v58 = stack[0];
    v58 = Lmemq(nil, v59, v58);
    if (v58 == nil) goto v346;
    stack[-3] = stack[-4];
    v58 = v342;
    stack[0] = qcar(v58);
    v58 = stack[-2];
    v58 = qcdr(v58);
    fn = elt(env, 10); /* negf */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    fn = elt(env, 11); /* pasf_subfof1 */
    v342 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-6];
    v59 = stack[-1];
    v58 = qvalue(elt(env, 4)); /* nil */
    {
        popv(7);
        fn = elt(env, 12); /* pasf_susibinad1 */
        return (*qfnn(fn))(qenv(fn), 3, v342, v59, v58);
    }

v346:
    v58 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v58); }

v90:
    v58 = stack[-4];
    v284 = qcar(v58);
    v58 = stack[-5];
    v344 = qcar(v58);
    v58 = stack[-5];
    v58 = qcdr(v58);
    if (v58 == nil) goto v279;
    v58 = stack[-5];
    v58 = qcdr(v58);
    v343 = v58;
    goto v306;

v306:
    v58 = stack[-3];
    v116 = qcar(v58);
    v58 = stack[-2];
    v342 = qcar(v58);
    v58 = stack[-2];
    v58 = qcdr(v58);
    if (v58 == nil) goto v347;
    v58 = stack[-2];
    v58 = qcdr(v58);
    v59 = v58;
    goto v213;

v213:
    v58 = stack[-1];
    {
        popv(7);
        fn = elt(env, 13); /* pasf_susibinord */
        return (*qfnn(fn))(qenv(fn), 7, v284, v344, v343, v116, v342, v59, v58);
    }

v347:
    v58 = (Lisp_Object)1; /* 0 */
    v59 = v58;
    goto v213;

v279:
    v58 = (Lisp_Object)1; /* 0 */
    v343 = v58;
    goto v306;

v301:
    v58 = stack[-4];
    v58 = qcdr(v58);
    v116 = qcar(v58);
    v58 = stack[-4];
    v342 = qcar(v58);
    v58 = stack[-3];
    v59 = qcar(v58);
    v58 = stack[-1];
    {
        popv(7);
        fn = elt(env, 14); /* pasf_susibineq */
        return (*qfnn(fn))(qenv(fn), 4, v116, v342, v59, v58);
    }

v98:
    v58 = elt(env, 3); /* (delete . t) */
    popv(7);
    return ncons(v58);

v246:
    v58 = elt(env, 1); /* false */
    { popv(7); return onevalue(v58); }
/* error exit handlers */
v345:
    popv(7);
    return nil;
}



/* Code for sets */

static Lisp_Object CC_sets(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sets");
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
    v168 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v168 = elt(env, 2); /* "<" */
    v168 = Lprinc(nil, v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v168 = stack[0];
    v168 = Lprinc(nil, v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v168 = elt(env, 3); /* "/>" */
    v168 = Lprinc(nil, v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v169 = qvalue(elt(env, 4)); /* indent */
    v168 = (Lisp_Object)49; /* 3 */
    v168 = plus2(v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    qvalue(elt(env, 4)) = v168; /* indent */
    v168 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v169 = qvalue(elt(env, 4)); /* indent */
    v168 = (Lisp_Object)49; /* 3 */
    v168 = difference2(v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    qvalue(elt(env, 4)) = v168; /* indent */
    v168 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v168 = nil;
    { popv(3); return onevalue(v168); }
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for insertocc */

static Lisp_Object CC_insertocc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v260, v314;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertocc");
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
    v314 = v1;
    stack[-1] = v0;
/* end of prologue */
    v260 = v314;
    v227 = stack[-1];
    v227 = Lassoc(nil, v260, v227);
    stack[-2] = v227;
    if (v227 == nil) goto v106;
    stack[0] = v314;
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = add1(v227);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-3];
    v314 = cons(stack[0], v227);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-3];
    v260 = stack[-2];
    v227 = stack[-1];
    v227 = Lsubst(nil, 3, v314, v260, v227);
    nil = C_nil;
    if (exception_pending()) goto v259;
    stack[-1] = v227;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v106:
    v260 = (Lisp_Object)17; /* 1 */
    v227 = stack[-1];
    v227 = acons(v314, v260, v227);
    nil = C_nil;
    if (exception_pending()) goto v259;
    stack[-1] = v227;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v259:
    popv(4);
    return nil;
}



/* Code for vdpcondense */

static Lisp_Object CC_vdpcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpcondense");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v191 = v0;
/* end of prologue */
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    v191 = qcar(v191);
    {
        fn = elt(env, 1); /* dipcondense */
        return (*qfn1(fn))(qenv(fn), v191);
    }
}



/* Code for gpexpp */

static Lisp_Object CC_gpexpp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexpp");
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

v172:
    v203 = stack[0];
    if (!consp(v203)) goto v191;
    v203 = stack[0];
    v266 = qcar(v203);
    v203 = elt(env, 2); /* (!:rd!: !:cr!: !:crn!: !:gi!:) */
    v203 = Lmemq(nil, v266, v203);
    if (v203 == nil) goto v298;
    v203 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v203); }

v298:
    v203 = stack[0];
    v266 = qcar(v203);
    v203 = elt(env, 4); /* plus */
    if (v266 == v203) goto v260;
    v203 = stack[0];
    v266 = qcar(v203);
    v203 = elt(env, 5); /* (minus recip) */
    v203 = Lmemq(nil, v266, v203);
    if (v203 == nil) goto v352;
    v203 = stack[0];
    v266 = Llength(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    v203 = (Lisp_Object)33; /* 2 */
    if (v266 == v203) goto v353;
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v353:
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcar(v203);
    stack[0] = v203;
    goto v172;

v352:
    v203 = stack[0];
    v266 = qcar(v203);
    v203 = elt(env, 6); /* (difference quotient expt) */
    v203 = Lmemq(nil, v266, v203);
    if (v203 == nil) goto v354;
    v203 = stack[0];
    v266 = Llength(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    v203 = (Lisp_Object)49; /* 3 */
    if (v266 == v203) goto v305;
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v305:
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcar(v203);
    v203 = CC_gpexpp(env, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    if (v203 == nil) goto v317;
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    v203 = qcar(v203);
    stack[0] = v203;
    goto v172;

v317:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v354:
    v203 = stack[0];
    v266 = qcar(v203);
    v203 = elt(env, 7); /* times */
    if (v266 == v203) goto v231;
    v203 = stack[0];
    v266 = qcar(v203);
    v203 = elt(env, 8); /* !:rd!: */
    if (v266 == v203) goto v355;
    v203 = stack[0];
    v266 = qcar(v203);
    v203 = elt(env, 9); /* (!:cr!: !:crn!: !:gi!:) */
    v203 = Lmemq(nil, v266, v203);
    if (v203 == nil) goto v331;
    v203 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v203); }

v331:
    v203 = stack[0];
    v203 = qcar(v203);
    fn = elt(env, 10); /* unresidp */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    if (v203 == nil) goto v265;
    v203 = stack[0];
    v203 = qcdr(v203);
    {
        popv(2);
        fn = elt(env, 11); /* gparg1p */
        return (*qfn1(fn))(qenv(fn), v203);
    }

v265:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v355:
    v203 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v203); }

v231:
    v203 = stack[0];
    v266 = Llength(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    v203 = (Lisp_Object)49; /* 3 */
    v203 = (Lisp_Object)geq2(v266, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    v203 = v203 ? lisp_true : nil;
    env = stack[-1];
    if (v203 == nil) goto v356;
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcar(v203);
    v203 = CC_gpexpp(env, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    if (v203 == nil) goto v271;
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    v203 = qcar(v203);
    v203 = CC_gpexpp(env, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    if (v203 == nil) goto v206;
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    {
        popv(2);
        fn = elt(env, 12); /* gpexp1p */
        return (*qfn1(fn))(qenv(fn), v203);
    }

v206:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v271:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v356:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v260:
    v203 = stack[0];
    v266 = Llength(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    v203 = (Lisp_Object)33; /* 2 */
    v203 = (Lisp_Object)geq2(v266, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    v203 = v203 ? lisp_true : nil;
    env = stack[-1];
    if (v203 == nil) goto v161;
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcar(v203);
    v203 = CC_gpexpp(env, v203);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-1];
    if (v203 == nil) goto v159;
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    {
        popv(2);
        fn = elt(env, 12); /* gpexp1p */
        return (*qfn1(fn))(qenv(fn), v203);
    }

v159:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v161:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }

v191:
    v203 = stack[0];
    v203 = Lsymbolp(nil, v203);
    env = stack[-1];
    v266 = v203;
    if (!(v203 == nil)) { popv(2); return onevalue(v266); }
    v203 = stack[0];
    v203 = (is_number(v203) ? lisp_true : nil);
    v266 = v203;
    if (!(v203 == nil)) { popv(2); return onevalue(v266); }
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }
/* error exit handlers */
v294:
    popv(2);
    return nil;
}



/* Code for indxsymp */

static Lisp_Object CC_indxsymp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v169;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indxsymp");
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

v111:
    v168 = stack[0];
    v168 = (v168 == nil ? lisp_true : nil);
    if (!(v168 == nil)) { popv(3); return onevalue(v168); }
    v168 = stack[0];
    v169 = qcar(v168);
    v168 = stack[-1];
    v168 = Lapply1(nil, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    if (v168 == nil) goto v156;
    v169 = stack[-1];
    v168 = stack[0];
    v168 = qcdr(v168);
    stack[-1] = v169;
    stack[0] = v168;
    goto v111;

v156:
    v168 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v168); }
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for termorder1 */

static Lisp_Object CC_termorder1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termorder1");
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

v172:
    v228 = stack[-1];
    if (v228 == nil) goto v191;
    v228 = stack[-1];
    v228 = (Lisp_Object)zerop(v228);
    v228 = v228 ? lisp_true : nil;
    env = stack[-2];
    if (v228 == nil) goto v149;
    v228 = stack[0];
    v228 = (Lisp_Object)zerop(v228);
    v228 = v228 ? lisp_true : nil;
    env = stack[-2];
    if (v228 == nil) goto v149;
    v228 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v228); }

v149:
    v228 = stack[-1];
    v228 = (Lisp_Object)zerop(v228);
    v228 = v228 ? lisp_true : nil;
    env = stack[-2];
    if (v228 == nil) goto v287;
    v228 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v228); }

v287:
    v228 = stack[0];
    v228 = (Lisp_Object)zerop(v228);
    v228 = v228 ? lisp_true : nil;
    env = stack[-2];
    if (v228 == nil) goto v169;
    v228 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v228); }

v169:
    v228 = stack[-1];
    v150 = qcar(v228);
    v228 = stack[0];
    v228 = qcar(v228);
    v228 = (Lisp_Object)lessp2(v150, v228);
    nil = C_nil;
    if (exception_pending()) goto v146;
    v228 = v228 ? lisp_true : nil;
    env = stack[-2];
    if (v228 == nil) goto v220;
    v228 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v228); }

v220:
    v228 = stack[-1];
    v150 = qcar(v228);
    v228 = stack[0];
    v228 = qcar(v228);
    v228 = (Lisp_Object)greaterp2(v150, v228);
    nil = C_nil;
    if (exception_pending()) goto v146;
    v228 = v228 ? lisp_true : nil;
    env = stack[-2];
    if (v228 == nil) goto v148;
    v228 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v228); }

v148:
    v228 = stack[-1];
    v228 = qcdr(v228);
    stack[-1] = v228;
    v228 = stack[0];
    v228 = qcdr(v228);
    stack[0] = v228;
    goto v172;

v191:
    v228 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v228); }
/* error exit handlers */
v146:
    popv(3);
    return nil;
}



/* Code for formproc */

static Lisp_Object MS_CDECL CC_formproc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v170, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v128, v129, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formproc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formproc");
#endif
    if (stack >= stacklimit)
    {
        push3(v170,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v170);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v170;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* fname!* */
    qvalue(elt(env, 1)) = nil; /* fname!* */
    stack[-2] = nil;
    v126 = stack[-1];
    v126 = qcdr(v126);
    stack[-1] = v126;
    v126 = stack[-1];
    v126 = qcar(v126);
    qvalue(elt(env, 1)) = v126; /* fname!* */
    stack[-5] = v126;
    v126 = stack[-1];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    if (v126 == nil) goto v315;
    v126 = stack[-1];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    stack[-7] = v126;
    goto v315;

v315:
    v126 = stack[-1];
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    stack[-1] = v126;
    v126 = stack[-1];
    v126 = qcar(v126);
    qvalue(elt(env, 2)) = v126; /* ftype!* */
    stack[-4] = v126;
    v126 = stack[-5];
    if (!symbolp(v126)) v126 = nil;
    else { v126 = qfastgets(v126);
           if (v126 != nil) { v126 = elt(v126, 1); /* lose */
#ifdef RECORD_GET
             if (v126 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v126 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v126 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v126 == SPID_NOPROP) v126 = nil; else v126 = lisp_true; }}
#endif
    if (v126 == nil) goto v152;
    v126 = qvalue(elt(env, 3)); /* !*lose */
    if (!(v126 == nil)) goto v153;
    v126 = qvalue(elt(env, 4)); /* !*defn */
    if (!(v126 == nil)) goto v152;

v153:
    v126 = qvalue(elt(env, 5)); /* !*msg */
    if (v126 == nil) goto v221;
    stack[0] = elt(env, 7); /* "***" */
    v128 = stack[-5];
    v126 = elt(env, 8); /* "not defined (LOSE flag)" */
    v126 = list2(v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v126 = (*qfn2(fn))(qenv(fn), stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    goto v221;

v221:
    v126 = elt(env, 9); /* (quote nil) */
    goto v149;

v149:
    qvalue(elt(env, 1)) = stack[-6]; /* fname!* */
    { popv(10); return onevalue(v126); }

v152:
    v126 = qvalue(elt(env, 10)); /* !*redeflg!* */
    if (v126 == nil) goto v113;
    v126 = stack[-5];
    fn = elt(env, 39); /* getd */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    if (v126 == nil) goto v113;
    v126 = qvalue(elt(env, 5)); /* !*msg */
    if (v126 == nil) goto v113;
    stack[-3] = elt(env, 7); /* "***" */
    v128 = stack[-5];
    v126 = elt(env, 11); /* "redefined" */
    v126 = list2(v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v126 = (*qfn2(fn))(qenv(fn), stack[-3], v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    goto v113;

v113:
    v126 = stack[-1];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    stack[-3] = v126;
    goto v167;

v167:
    v126 = stack[-3];
    if (v126 == nil) goto v166;
    v126 = stack[-3];
    v126 = qcar(v126);
    v126 = Lsymbol_specialp(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    if (!(v126 == nil)) goto v408;
    v126 = stack[-3];
    v126 = qcar(v126);
    v126 = Lsymbol_globalp(nil, v126);
    env = stack[-9];
    if (!(v126 == nil)) goto v408;

v352:
    v126 = stack[-3];
    v126 = qcdr(v126);
    stack[-3] = v126;
    goto v167;

v408:
    v126 = stack[-3];
    v128 = qcar(v126);
    v126 = stack[-2];
    v126 = cons(v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-2] = v126;
    goto v352;

v166:
    v126 = stack[-1];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    stack[-3] = v126;
    v126 = stack[-1];
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    v126 = qcar(v126);
    stack[-8] = v126;
    v128 = stack[-8];
    v126 = elt(env, 12); /* rblock */
    if (!consp(v128)) goto v84;
    v128 = qcar(v128);
    if (!(v128 == v126)) goto v84;
    v126 = stack[-8];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    goto v87;

v87:
    stack[-1] = v126;
    v130 = stack[-3];
    v129 = stack[-1];
    v128 = stack[0];
    v126 = stack[-7];
    fn = elt(env, 40); /* pairxvars */
    v126 = (*qfnn(fn))(qenv(fn), 4, v130, v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[0] = v126;
    v126 = stack[-1];
    if (v126 == nil) goto v207;
    v126 = stack[-8];
    stack[-1] = qcar(v126);
    v126 = stack[-8];
    v128 = qcdr(v126);
    v126 = stack[0];
    v126 = qcdr(v126);
    v126 = Lrplaca(nil, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = cons(stack[-1], v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    goto v207;

v207:
    v129 = stack[-8];
    v126 = stack[0];
    v128 = qcar(v126);
    v126 = stack[-7];
    fn = elt(env, 41); /* form1 */
    v126 = (*qfnn(fn))(qenv(fn), 3, v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    v126 = stack[-2];
    if (v126 == nil) goto v409;
    v128 = stack[-4];
    v126 = elt(env, 13); /* (expr fexpr macro) */
    v126 = Lmemq(nil, v128, v126);
    if (v126 == nil) goto v409;
    stack[-1] = elt(env, 14); /* progn */
    stack[0] = elt(env, 15); /* declare */
    v128 = elt(env, 16); /* special */
    v126 = stack[-2];
    v126 = cons(v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v128 = list2(stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = stack[-8];
    v126 = list3(stack[-1], v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    goto v409;

v409:
    v126 = qvalue(elt(env, 17)); /* !*nosmacros */
    if (v126 == nil) goto v198;
    v128 = stack[-4];
    v126 = elt(env, 18); /* smacro */
    if (!(v128 == v126)) goto v198;
    v126 = elt(env, 19); /* expr */
    stack[-4] = v126;
    goto v198;

v198:
    v128 = stack[-4];
    v126 = elt(env, 18); /* smacro */
    if (v128 == v126) goto v196;
    v128 = stack[-5];
    v126 = elt(env, 18); /* smacro */
    v126 = get(v128, v126);
    env = stack[-9];
    if (v126 == nil) goto v196;
    v126 = qvalue(elt(env, 5)); /* !*msg */
    if (v126 == nil) goto v196;
    stack[0] = elt(env, 7); /* "***" */
    v129 = elt(env, 20); /* "SMACRO" */
    v128 = stack[-5];
    v126 = elt(env, 11); /* "redefined" */
    v126 = list3(v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v126 = (*qfn2(fn))(qenv(fn), stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    goto v196;

v196:
    v129 = stack[-3];
    v128 = stack[-8];
    v126 = stack[-7];
    fn = elt(env, 42); /* symbvarlst */
    v126 = (*qfnn(fn))(qenv(fn), 3, v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v128 = stack[-4];
    v126 = elt(env, 19); /* expr */
    if (v128 == v126) goto v193;
    v128 = stack[-4];
    v126 = elt(env, 22); /* fexpr */
    if (v128 == v126) goto v410;
    v128 = stack[-4];
    v126 = elt(env, 24); /* macro */
    if (v128 == v126) goto v411;
    v128 = stack[-4];
    v126 = elt(env, 26); /* procfn */
    v126 = get(v128, v126);
    env = stack[-9];
    stack[-1] = v126;
    if (v126 == nil) goto v26;
    v130 = stack[-1];
    v129 = stack[-5];
    v128 = stack[-3];
    v126 = stack[-8];
    v126 = Lapply3(nil, 4, v130, v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    goto v149;

v26:
    stack[-2] = elt(env, 27); /* putc */
    v126 = stack[-5];
    stack[-1] = Lmkquote(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = stack[-4];
    stack[0] = Lmkquote(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v129 = elt(env, 28); /* lambda */
    v128 = stack[-3];
    v126 = stack[-8];
    v126 = list3(v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = Lmkquote(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = list4(stack[-2], stack[-1], stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    goto v412;

v412:
    v128 = stack[-7];
    v126 = elt(env, 29); /* symbolic */
    if (v128 == v126) goto v225;
    stack[-1] = elt(env, 30); /* flag */
    v126 = stack[-5];
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[0] = Lmkquote(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = elt(env, 31); /* opfn */
    v126 = Lmkquote(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v128 = list3(stack[-1], stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = stack[-8];
    fn = elt(env, 43); /* mkprogn */
    v126 = (*qfn2(fn))(qenv(fn), v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    goto v225;

v225:
    v126 = qvalue(elt(env, 32)); /* !*argnochk */
    if (v126 == nil) goto v413;
    v128 = stack[-4];
    v126 = elt(env, 33); /* (expr smacro) */
    v126 = Lmemq(nil, v128, v126);
    if (v126 == nil) goto v413;
    stack[-1] = elt(env, 34); /* put */
    v126 = stack[-5];
    stack[-2] = Lmkquote(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = elt(env, 35); /* number!-of!-args */
    stack[0] = Lmkquote(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = stack[-3];
    v126 = Llength(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v128 = list4(stack[-1], stack[-2], stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v126 = stack[-8];
    fn = elt(env, 43); /* mkprogn */
    v126 = (*qfn2(fn))(qenv(fn), v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    goto v413;

v413:
    v126 = qvalue(elt(env, 4)); /* !*defn */
    if (v126 == nil) goto v414;
    v128 = stack[-4];
    v126 = elt(env, 36); /* (fexpr macro smacro) */
    v126 = Lmemq(nil, v128, v126);
    if (v126 == nil) goto v414;
    v126 = stack[-8];
    fn = elt(env, 44); /* eval */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    goto v414;

v414:
    v126 = qvalue(elt(env, 37)); /* !*micro!-version */
    if (v126 == nil) goto v415;
    v128 = stack[-4];
    v126 = elt(env, 36); /* (fexpr macro smacro) */
    v126 = Lmemq(nil, v128, v126);
    if (v126 == nil) goto v415;
    v126 = qvalue(elt(env, 6)); /* nil */
    goto v149;

v415:
    v126 = stack[-8];
    goto v149;

v411:
    v130 = elt(env, 25); /* dm */
    v129 = stack[-5];
    v128 = stack[-3];
    v126 = stack[-8];
    v126 = list4(v130, v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    goto v412;

v410:
    v130 = elt(env, 23); /* df */
    v129 = stack[-5];
    v128 = stack[-3];
    v126 = stack[-8];
    v126 = list4(v130, v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    goto v412;

v193:
    v130 = elt(env, 21); /* de */
    v129 = stack[-5];
    v128 = stack[-3];
    v126 = stack[-8];
    v126 = list4(v130, v129, v128, v126);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v126;
    goto v412;

v84:
    v126 = qvalue(elt(env, 6)); /* nil */
    goto v87;
/* error exit handlers */
v407:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-6]; /* fname!* */
    popv(10);
    return nil;
}



/* Code for fs!:minusp */

static Lisp_Object CC_fsTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v99 = v0;
/* end of prologue */

v171:
    v98 = v99;
    if (v98 == nil) goto v112;
    v106 = v99;
    v98 = (Lisp_Object)49; /* 3 */
    v98 = *(Lisp_Object *)((char *)v106 + (CELL-TAG_VECTOR) + ((int32_t)v98/(16/CELL)));
    if (v98 == nil) goto v164;
    v98 = (Lisp_Object)49; /* 3 */
    v98 = *(Lisp_Object *)((char *)v99 + (CELL-TAG_VECTOR) + ((int32_t)v98/(16/CELL)));
    v99 = v98;
    goto v171;

v164:
    v98 = (Lisp_Object)1; /* 0 */
    v98 = *(Lisp_Object *)((char *)v99 + (CELL-TAG_VECTOR) + ((int32_t)v98/(16/CELL)));
    v98 = qcar(v98);
    {
        fn = elt(env, 2); /* minusf */
        return (*qfn1(fn))(qenv(fn), v98);
    }

v112:
    v98 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v98);
}



/* Code for simp!-prop!-dist */

static Lisp_Object CC_simpKpropKdist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v279, v229, v304;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-dist");
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
    v229 = v0;
/* end of prologue */
    v304 = v229;
    v279 = elt(env, 1); /* plus */
    if (!consp(v304)) goto v261;
    v304 = qcar(v304);
    if (!(v304 == v279)) goto v261;
    v279 = v229;
    v279 = qcdr(v279);
    v229 = v279;
    goto v255;

v255:
    v279 = v229;
    stack[-3] = v279;
    v279 = stack[-3];
    if (v279 == nil) goto v246;
    v279 = stack[-3];
    v279 = qcar(v279);
    v304 = v279;
    v229 = v304;
    v279 = elt(env, 3); /* times */
    if (!consp(v229)) goto v299;
    v229 = qcar(v229);
    if (!(v229 == v279)) goto v299;
    v279 = v304;
    v279 = qcdr(v279);
    goto v152;

v152:
    v304 = v279;
    v279 = v304;
    v279 = qcar(v279);
    if (!(is_number(v279))) goto v150;
    v279 = v304;
    v279 = qcdr(v279);
    v304 = v279;
    goto v150;

v150:
    v229 = v304;
    v279 = elt(env, 4); /* lambda_l9xqtt_7 */
    fn = elt(env, 7); /* sort */
    v279 = (*qfn2(fn))(qenv(fn), v229, v279);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    stack[-1] = v279;
    stack[-2] = v279;
    goto v155;

v155:
    v279 = stack[-3];
    v279 = qcdr(v279);
    stack[-3] = v279;
    v279 = stack[-3];
    if (v279 == nil) goto v313;
    stack[0] = stack[-1];
    v279 = stack[-3];
    v279 = qcar(v279);
    v304 = v279;
    v229 = v304;
    v279 = elt(env, 3); /* times */
    if (!consp(v229)) goto v252;
    v229 = qcar(v229);
    if (!(v229 == v279)) goto v252;
    v279 = v304;
    v279 = qcdr(v279);
    goto v312;

v312:
    v304 = v279;
    v279 = v304;
    v279 = qcar(v279);
    if (!(is_number(v279))) goto v289;
    v279 = v304;
    v279 = qcdr(v279);
    v304 = v279;
    goto v289;

v289:
    v229 = v304;
    v279 = elt(env, 5); /* lambda_l9xqtt_8 */
    fn = elt(env, 7); /* sort */
    v279 = (*qfn2(fn))(qenv(fn), v229, v279);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v279 = Lrplacd(nil, stack[0], v279);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v279 = stack[-1];
    v279 = qcdr(v279);
    stack[-1] = v279;
    goto v155;

v252:
    v279 = v304;
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v312;

v313:
    v279 = stack[-2];
    goto v164;

v164:
    v229 = v279;
    v279 = elt(env, 6); /* simp!-prop!-order */
    {
        popv(5);
        fn = elt(env, 7); /* sort */
        return (*qfn2(fn))(qenv(fn), v229, v279);
    }

v299:
    v279 = v304;
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v152;

v246:
    v279 = qvalue(elt(env, 2)); /* nil */
    goto v164;

v261:
    v279 = v229;
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v229 = v279;
    goto v255;
/* error exit handlers */
v102:
    popv(5);
    return nil;
}



/* Code for lambda_l9xqtt_8 */

static Lisp_Object CC_lambda_l9xqtt_8(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v261;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9xqtt_8");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v166 = v1;
    v261 = v0;
/* end of prologue */
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v261, v166);
    }
}



/* Code for lambda_l9xqtt_7 */

static Lisp_Object CC_lambda_l9xqtt_7(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v261;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9xqtt_7");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v166 = v1;
    v261 = v0;
/* end of prologue */
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v261, v166);
    }
}



/* Code for fd2q */

static Lisp_Object CC_fd2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v309;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fd2q");
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

v171:
    v95 = stack[0];
    if (!consp(v95)) goto v256;
    v95 = stack[0];
    v309 = qcar(v95);
    v95 = elt(env, 1); /* !:ar!: */
    if (v309 == v95) goto v303;
    v95 = stack[0];
    v309 = qcar(v95);
    v95 = elt(env, 2); /* !:rn!: */
    if (v309 == v95) goto v257;
    v95 = stack[0];
    v95 = qcar(v95);
    v309 = qcar(v95);
    v95 = (Lisp_Object)17; /* 1 */
    v95 = cons(v309, v95);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    v309 = ncons(v95);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    v95 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v309, v95);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    v95 = stack[0];
    v95 = qcar(v95);
    v95 = qcdr(v95);
    v95 = CC_fd2q(env, v95);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    fn = elt(env, 3); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v95);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = CC_fd2q(env, v95);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    {
        Lisp_Object v115 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v115, v95);
    }

v257:
    v95 = stack[0];
    v95 = qcdr(v95);
    { popv(3); return onevalue(v95); }

v303:
    v95 = stack[0];
    v95 = qcdr(v95);
    stack[0] = v95;
    goto v171;

v256:
    v309 = stack[0];
    v95 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v309, v95);
/* error exit handlers */
v254:
    popv(3);
    return nil;
}



/* Code for msolve!-psys1 */

static Lisp_Object CC_msolveKpsys1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v419, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-psys1");
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
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    v419 = qvalue(elt(env, 1)); /* nil */
    v419 = ncons(v419);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    v213 = v419;
    v419 = stack[0];
    stack[-4] = v419;
    goto v167;

v167:
    v419 = stack[-4];
    if (v419 == nil) { popv(8); return onevalue(v213); }
    v419 = stack[-4];
    v419 = qcar(v419);
    stack[-3] = v419;
    v419 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v419;
    v419 = v213;
    stack[-2] = v419;
    goto v246;

v246:
    v419 = stack[-2];
    if (v419 == nil) goto v101;
    v419 = stack[-2];
    v419 = qcar(v419);
    stack[-1] = v419;
    v213 = stack[-3];
    v419 = stack[-1];
    fn = elt(env, 2); /* subf */
    v419 = (*qfn2(fn))(qenv(fn), v213, v419);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    v419 = qcar(v419);
    fn = elt(env, 3); /* moduntag */
    v419 = (*qfn1(fn))(qenv(fn), v419);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    fn = elt(env, 4); /* general!-reduce!-mod!-p */
    v419 = (*qfn1(fn))(qenv(fn), v419);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    v213 = v419;
    v419 = v213;
    if (v419 == nil) goto v148;
    v419 = v213;
    if (!consp(v419)) goto v227;
    v419 = v213;
    v419 = qcar(v419);
    if (!consp(v419)) goto v227;
    v419 = stack[-5];
    fn = elt(env, 5); /* msolve!-poly */
    v419 = (*qfn2(fn))(qenv(fn), v213, v419);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    stack[0] = v419;
    goto v302;

v302:
    v419 = stack[0];
    if (v419 == nil) goto v227;
    v419 = stack[0];
    v419 = qcar(v419);
    v213 = stack[-1];
    v213 = Lappend(nil, v213, v419);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    v419 = stack[-6];
    v419 = cons(v213, v419);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    stack[-6] = v419;
    v419 = stack[0];
    v419 = qcdr(v419);
    stack[0] = v419;
    goto v302;

v227:
    v419 = stack[-2];
    v419 = qcdr(v419);
    stack[-2] = v419;
    goto v246;

v148:
    v213 = stack[-1];
    v419 = stack[-6];
    v419 = cons(v213, v419);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    stack[-6] = v419;
    goto v227;

v101:
    v419 = stack[-6];
    v213 = v419;
    v419 = stack[-4];
    v419 = qcdr(v419);
    stack[-4] = v419;
    goto v167;
/* error exit handlers */
v215:
    popv(8);
    return nil;
}



/* Code for solvealgdepends */

static Lisp_Object CC_solvealgdepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v323, v254;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgdepends");
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

v256:
    v254 = stack[-1];
    v323 = stack[0];
    if (equal(v254, v323)) goto v173;
    v323 = stack[-1];
    if (!consp(v323)) goto v348;
    v254 = stack[-1];
    v323 = elt(env, 3); /* root_of */
    if (!consp(v254)) goto v247;
    v254 = qcar(v254);
    if (!(v254 == v323)) goto v247;
    v254 = stack[0];
    v323 = stack[-1];
    v323 = qcdr(v323);
    v323 = qcdr(v323);
    v323 = qcar(v323);
    if (equal(v254, v323)) goto v107;
    v323 = stack[-1];
    v323 = qcdr(v323);
    v323 = qcar(v323);
    stack[-1] = v323;
    goto v256;

v107:
    v323 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v323); }

v247:
    v323 = stack[-1];
    v254 = qcar(v323);
    v323 = stack[0];
    v323 = CC_solvealgdepends(env, v254, v323);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-2];
    v254 = v323;
    if (!(v323 == nil)) { popv(3); return onevalue(v254); }
    v323 = stack[-1];
    v254 = qcdr(v323);
    v323 = stack[0];
    v323 = CC_solvealgdepends(env, v254, v323);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-2];
    v254 = v323;
    if (!(v323 == nil)) { popv(3); return onevalue(v254); }
    v323 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v323); }

v348:
    v323 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v323); }

v173:
    v323 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v323); }
/* error exit handlers */
v281:
    popv(3);
    return nil;
}



/* Code for get!-height */

static Lisp_Object CC_getKheight(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-height");
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
    v101 = stack[0];
    if (v101 == nil) goto v171;
    v101 = stack[0];
    if (is_number(v101)) goto v191;
    v101 = stack[0];
    v101 = qcar(v101);
    v101 = qcdr(v101);
    stack[-1] = CC_getKheight(env, v101);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = CC_getKheight(env, v101);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    {
        Lisp_Object v163 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* max */
        return (*qfn2(fn))(qenv(fn), v163, v101);
    }

v191:
    v101 = stack[0];
        popv(3);
        return Labsval(nil, v101);

v171:
    v101 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v101); }
/* error exit handlers */
v165:
    popv(3);
    return nil;
}



setup_type const u31_setup[] =
{
    {"lispcodeexp",             too_few_2,      CC_lispcodeexp,wrong_no_2},
    {"ext_mult",                too_few_2,      CC_ext_mult,   wrong_no_2},
    {"ofsf_negateat",           CC_ofsf_negateat,too_many_1,   wrong_no_1},
    {"simpexpt1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt1},
    {"getargsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_getargsrd},
    {"remdiff",                 CC_remdiff,     too_many_1,    wrong_no_1},
    {"suspend",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_suspend},
    {"matsm",                   CC_matsm,       too_many_1,    wrong_no_1},
    {"bcminus?",                CC_bcminusW,    too_many_1,    wrong_no_1},
    {"numprintlen",             CC_numprintlen, too_many_1,    wrong_no_1},
    {"indxchk",                 CC_indxchk,     too_many_1,    wrong_no_1},
    {"color-strand",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_colorKstrand},
    {"reduce-columns",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKcolumns},
    {"matop_pseudomod",         too_few_2,      CC_matop_pseudomod,wrong_no_2},
    {"pa_list2vect",            too_few_2,      CC_pa_list2vect,wrong_no_2},
    {"build-null-vector",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_buildKnullKvector},
    {"listeval0",               CC_listeval0,   too_many_1,    wrong_no_1},
    {"min2-order",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_min2Korder},
    {"evalnumberp",             CC_evalnumberp, too_many_1,    wrong_no_1},
    {"pasf_susibinad",          too_few_2,      CC_pasf_susibinad,wrong_no_2},
    {"sets",                    too_few_2,      CC_sets,       wrong_no_2},
    {"insertocc",               too_few_2,      CC_insertocc,  wrong_no_2},
    {"vdpcondense",             CC_vdpcondense, too_many_1,    wrong_no_1},
    {"gpexpp",                  CC_gpexpp,      too_many_1,    wrong_no_1},
    {"indxsymp",                too_few_2,      CC_indxsymp,   wrong_no_2},
    {"termorder1",              too_few_2,      CC_termorder1, wrong_no_2},
    {"formproc",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formproc},
    {"fs:minusp",               CC_fsTminusp,   too_many_1,    wrong_no_1},
    {"simp-prop-dist",          CC_simpKpropKdist,too_many_1,  wrong_no_1},
    {"lambda_l9xqtt_8",         too_few_2,      CC_lambda_l9xqtt_8,wrong_no_2},
    {"lambda_l9xqtt_7",         too_few_2,      CC_lambda_l9xqtt_7,wrong_no_2},
    {"fd2q",                    CC_fd2q,        too_many_1,    wrong_no_1},
    {"msolve-psys1",            too_few_2,      CC_msolveKpsys1,wrong_no_2},
    {"solvealgdepends",         too_few_2,      CC_solvealgdepends,wrong_no_2},
    {"get-height",              CC_getKheight,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u31", (two_args *)"10881 2072699 6057341", 0}
};

/* end of generated code */
