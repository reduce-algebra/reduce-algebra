
/* $destdir/generated-c\u05.c Machine generated C code */

/* Signature: 00000000 13-Aug-2010 */

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
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? 153600 : 2048)
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
#define PAGE_MASK               ((((uint32_t)1) << (32-PAGE_BITS)) - 1)
#define OFFSET_MASK             ((((uint32_t)1) << PAGE_BITS) - 1)
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
extern Lisp_Object gchook, resources, callstack;
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
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#endif
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
extern jmp_buf *errorset_buffer;
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
extern int time_base,  space_base,  io_base,  errors_base;
extern int time_now,   space_now,   io_now,   errors_now;
extern int time_limit, space_limit, io_limit, errors_limit;
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


/* Code for mkwedge */

static Lisp_Object CC_mkwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkwedge");
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
    v4 = v0;
/* end of prologue */
    v6 = v4;
    v5 = (Lisp_Object)17; /* 1 */
    v4 = (Lisp_Object)17; /* 1 */
    v4 = list2star(v6, v5, v4);
    errexit();
    return ncons(v4);
}



/* Code for negsq */

static Lisp_Object CC_negsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negsq");
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
    v2 = stack[0];
    v2 = qcar(v2);
    fn = elt(env, 1); /* negf */
    v4 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v6;
    v2 = stack[0];
    v2 = qcdr(v2);
    popv(1);
    return cons(v4, v2);
/* error exit handlers */
v6:
    popv(1);
    return nil;
}



/* Code for noncommutingf */

static Lisp_Object CC_noncommutingf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncommutingf");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */

v17:
    v15 = stack[0];
    fn = elt(env, 2); /* domain!*p */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (v15 == nil) goto v6;
    v15 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v15); }

v6:
    v16 = stack[-1];
    v15 = stack[0];
    v15 = qcar(v15);
    v15 = qcar(v15);
    v15 = qcar(v15);
    fn = elt(env, 3); /* noncommuting */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (!(v15 == nil)) { popv(3); return onevalue(v15); }
    v16 = stack[-1];
    v15 = stack[0];
    v15 = qcar(v15);
    v15 = qcdr(v15);
    v15 = CC_noncommutingf(env, v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (!(v15 == nil)) { popv(3); return onevalue(v15); }
    v16 = stack[-1];
    v15 = stack[0];
    v15 = qcdr(v15);
    stack[-1] = v16;
    stack[0] = v15;
    goto v17;
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for getrtype */

static Lisp_Object CC_getrtype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtype");
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

v17:
    v43 = stack[0];
    if (v43 == nil) goto v7;
    v43 = stack[0];
    if (!consp(v43)) goto v1;
    v43 = stack[0];
    v43 = qcar(v43);
    if (symbolp(v43)) goto v46;
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v43); }

v46:
    v43 = stack[0];
    v44 = qcar(v43);
    v43 = elt(env, 3); /* avalue */
    v43 = get(v44, v43);
    env = stack[-1];
    v45 = v43;
    if (v43 == nil) goto v47;
    v43 = v45;
    v44 = qcar(v43);
    v43 = elt(env, 6); /* rtypefn */
    v43 = get(v44, v43);
    env = stack[-1];
    v45 = v43;
    if (v43 == nil) goto v47;
    v44 = v45;
    v43 = stack[0];
    v43 = qcdr(v43);
        popv(2);
        return Lapply1(nil, v44, v43);

v47:
    v43 = stack[0];
    v44 = qcar(v43);
    v43 = elt(env, 7); /* sub */
    if (v44 == v43) goto v48;
    v43 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* getrtype2 */
        return (*qfn1(fn))(qenv(fn), v43);
    }

v48:
    v43 = elt(env, 8); /* yetunknowntype */
    { popv(2); return onevalue(v43); }

v1:
    v43 = stack[0];
    if (symbolp(v43)) goto v9;
    v43 = stack[0];
    if (is_number(v43)) goto v49;
    v43 = stack[0];
    {
        popv(2);
        fn = elt(env, 10); /* getrtype1 */
        return (*qfn1(fn))(qenv(fn), v43);
    }

v49:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v43); }

v9:
    v44 = stack[0];
    v43 = elt(env, 2); /* share */
    v43 = Lflagp(nil, v44, v43);
    env = stack[-1];
    if (v43 == nil) goto v50;
    v43 = stack[0];
    fn = elt(env, 11); /* eval */
    v44 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    v45 = v44;
    v43 = stack[0];
    if (v44 == v43) goto v52;
    v43 = v45;
    stack[0] = v43;
    goto v17;

v52:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v43); }

v50:
    v44 = stack[0];
    v43 = elt(env, 3); /* avalue */
    v43 = get(v44, v43);
    env = stack[-1];
    v45 = v43;
    if (v43 == nil) goto v53;
    v43 = v45;
    v44 = qcar(v43);
    v43 = elt(env, 4); /* (scalar generic) */
    v43 = Lmemq(nil, v44, v43);
    if (!(v43 == nil)) goto v53;

v54:
    v43 = v45;
    v44 = qcar(v43);
    v43 = elt(env, 6); /* rtypefn */
    v43 = get(v44, v43);
    env = stack[-1];
    v44 = v43;
    if (v43 == nil) goto v55;
    v43 = v44;
    v44 = qvalue(elt(env, 1)); /* nil */
        popv(2);
        return Lapply1(nil, v43, v44);

v55:
    v43 = v45;
    v43 = qcar(v43);
    { popv(2); return onevalue(v43); }

v53:
    v44 = stack[0];
    v43 = elt(env, 5); /* rtype */
    v43 = get(v44, v43);
    env = stack[-1];
    v45 = v43;
    if (v43 == nil) goto v56;
    v43 = v45;
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    v45 = v43;
    if (!(v43 == nil)) goto v54;

v56:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v43); }

v7:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for mo!=lexcomp */

static Lisp_Object CC_moMlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60, v61, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=lexcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v8;
    v61 = v0;
/* end of prologue */

v63:
    v59 = v61;
    if (v59 == nil) goto v7;
    v59 = v60;
    if (v59 == nil) goto v64;
    v59 = v61;
    v62 = qcar(v59);
    v59 = v60;
    v59 = qcar(v59);
    if (equal(v62, v59)) goto v65;
    v59 = v61;
    v59 = qcar(v59);
    v60 = qcar(v60);
    if (((int32_t)(v59)) > ((int32_t)(v60))) goto v42;
    v59 = (Lisp_Object)-15; /* -1 */
    return onevalue(v59);

v42:
    v59 = (Lisp_Object)17; /* 1 */
    return onevalue(v59);

v65:
    v59 = v61;
    v59 = qcdr(v59);
    v61 = v59;
    v59 = v60;
    v59 = qcdr(v59);
    v60 = v59;
    goto v63;

v64:
    v59 = elt(env, 1); /* (0) */
    v60 = v59;
    goto v63;

v7:
    v59 = v60;
    if (v59 == nil) goto v2;
    v59 = elt(env, 1); /* (0) */
    v61 = v59;
    goto v63;

v2:
    v59 = (Lisp_Object)1; /* 0 */
    return onevalue(v59);
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v23, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "insert_pv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv1");
#endif
    if (stack >= stacklimit)
    {
        push3(v23,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v23;
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */

v80:
    v78 = stack[-1];
    if (v78 == nil) goto v81;
    v78 = stack[-2];
    if (v78 == nil) goto v82;
    v78 = stack[-1];
    v78 = qcar(v78);
    v78 = qcar(v78);
    v79 = qcdr(v78);
    v78 = stack[-2];
    v78 = qcar(v78);
    v78 = qcdr(v78);
    v78 = (Lisp_Object)greaterp2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    v78 = v78 ? lisp_true : nil;
    env = stack[-4];
    if (v78 == nil) goto v53;
    v78 = stack[-1];
    v78 = qcdr(v78);
    stack[-3] = v78;
    v78 = stack[-1];
    v79 = qcar(v78);
    v78 = stack[-2];
    fn = elt(env, 2); /* reduce_pv */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    fn = elt(env, 3); /* pv_renorm */
    v79 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v78 = stack[0];
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    stack[0] = v78;
    v78 = stack[-3];
    stack[-1] = v78;
    goto v80;

v53:
    v78 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v78;
    v79 = stack[-2];
    v78 = stack[0];
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    stack[0] = v78;
    v78 = stack[-3];
    stack[-2] = v78;
    goto v80;

v82:
    v78 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v78;
    v78 = stack[-1];
    v78 = qcdr(v78);
    stack[-3] = v78;
    v78 = stack[-1];
    v79 = qcar(v78);
    v78 = stack[0];
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    stack[0] = v78;
    v78 = stack[-3];
    stack[-1] = v78;
    goto v80;

v81:
    v78 = stack[-2];
    if (v78 == nil) goto v5;
    v79 = stack[-2];
    v78 = stack[0];
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
        popv(5);
        return Lnreverse(nil, v78);

v5:
    v78 = stack[0];
        popv(5);
        return Lnreverse(nil, v78);
/* error exit handlers */
v83:
    popv(5);
    return nil;
}



/* Code for mod!# */

static Lisp_Object CC_modC(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v85;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod#");
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
    v57 = v0;
/* end of prologue */
    v85 = v57;
    v57 = qvalue(elt(env, 1)); /* current!-modulus */
    v57 = Cremainder(v85, v57);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-1];
    stack[0] = v57;
    v85 = stack[0];
    v57 = (Lisp_Object)1; /* 0 */
    v57 = (Lisp_Object)lessp2(v85, v57);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v57 = v57 ? lisp_true : nil;
    env = stack[-1];
    if (v57 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v57 = stack[0];
    v85 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return plus2(v57, v85);
/* error exit handlers */
v86:
    popv(2);
    return nil;
}



/* Code for noncomp!* */

static Lisp_Object CC_noncompH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp*");
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
    v89 = stack[0];
    fn = elt(env, 3); /* noncomp */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    if (!(v89 == nil)) { popv(2); return onevalue(v89); }
    v90 = stack[0];
    v89 = elt(env, 1); /* expt */
    if (!consp(v90)) goto v84;
    v90 = qcar(v90);
    if (!(v90 == v89)) goto v84;
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcar(v89);
    {
        popv(2);
        fn = elt(env, 3); /* noncomp */
        return (*qfn1(fn))(qenv(fn), v89);
    }

v84:
    v89 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v89); }
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for convprec!* */

static Lisp_Object CC_convprecH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convprec*");
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
    v91 = v0;
/* end of prologue */
    v64 = v91;
    if (!consp(v64)) goto v77;
    v64 = elt(env, 1); /* !:rd!: */
    v91 = cons(v64, v91);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[0];
    goto v77;

v77:
    {
        popv(1);
        fn = elt(env, 2); /* convchk */
        return (*qfn1(fn))(qenv(fn), v91);
    }
/* error exit handlers */
v11:
    popv(1);
    return nil;
}



/* Code for tayexp!-min2 */

static Lisp_Object CC_tayexpKmin2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-min2");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v64 = stack[-1];
    v91 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v91 = (*qfn2(fn))(qenv(fn), v64, v91);
    nil = C_nil;
    if (exception_pending()) goto v92;
    if (v91 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for ibalp_var!-unsatlist */

static Lisp_Object CC_ibalp_varKunsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-unsatlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v8;
    v94 = v0;
/* end of prologue */
    stack[-3] = v94;
    goto v96;

v96:
    v94 = stack[-3];
    if (v94 == nil) goto v81;
    v94 = stack[-3];
    v94 = qcar(v94);
    stack[-1] = v94;
    v95 = stack[-2];
    v94 = (Lisp_Object)17; /* 1 */
    v94 = Leqn(nil, v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-4];
    if (v94 == nil) goto v98;
    v94 = stack[-1];
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    stack[0] = qcdr(v94);
    v94 = stack[-1];
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcar(v94);
    v94 = sub1(v94);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-4];
    fn = elt(env, 2); /* setcar */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-4];
    goto v87;

v87:
    v94 = stack[-3];
    v94 = qcdr(v94);
    stack[-3] = v94;
    goto v96;

v98:
    v94 = stack[-1];
    v94 = qcdr(v94);
    stack[0] = qcdr(v94);
    v94 = stack[-1];
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcar(v94);
    v94 = sub1(v94);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-4];
    fn = elt(env, 2); /* setcar */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-4];
    goto v87;

v81:
    v94 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v94); }
/* error exit handlers */
v97:
    popv(5);
    return nil;
}



/* Code for pnthxzz */

static Lisp_Object CC_pnthxzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v93, v75, v76;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnthxzz");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v93 = v8;
    v75 = v0;
/* end of prologue */

v63:
    v90 = v93;
    if (v90 == nil) return onevalue(v93);
    v90 = v93;
    v90 = qcar(v90);
    v76 = qcar(v90);
    v90 = v75;
    if (equal(v76, v90)) return onevalue(v93);
    v90 = v93;
    v90 = qcdr(v90);
    v93 = v90;
    goto v63;
}



/* Code for off1 */

static Lisp_Object CC_off1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for off1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v0;
/* end of prologue */
    v3 = v81;
    v81 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* onoff */
        return (*qfn2(fn))(qenv(fn), v3, v81);
    }
}



/* Code for fast_unchecked_getmatelem */

static Lisp_Object CC_fast_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fast_unchecked_getmatelem");
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
    v65 = stack[0];
    v65 = qcar(v65);
    v12 = qcdr(v65);
    v65 = stack[0];
    v65 = qcdr(v65);
    v65 = qcar(v65);
    fn = elt(env, 1); /* nth */
    v12 = (*qfn2(fn))(qenv(fn), v12, v65);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    v65 = stack[0];
    v65 = qcdr(v65);
    v65 = qcdr(v65);
    v65 = qcar(v65);
    {
        popv(2);
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v12, v65);
    }
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for smemqlp */

static Lisp_Object CC_smemqlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v72;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemqlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */

v17:
    v62 = stack[0];
    if (v62 == nil) goto v63;
    v62 = stack[0];
    if (is_number(v62)) goto v63;
    v62 = stack[0];
    if (!consp(v62)) goto v5;
    v62 = stack[0];
    v72 = qcar(v62);
    v62 = elt(env, 2); /* quote */
    if (v72 == v62) goto v92;
    v72 = stack[-1];
    v62 = stack[0];
    v62 = qcar(v62);
    v62 = CC_smemqlp(env, v72, v62);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    if (!(v62 == nil)) { popv(3); return onevalue(v62); }
    v72 = stack[-1];
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[-1] = v72;
    stack[0] = v62;
    goto v17;

v92:
    v62 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v62); }

v5:
    v72 = stack[0];
    v62 = stack[-1];
    v62 = Lmemq(nil, v72, v62);
    { popv(3); return onevalue(v62); }

v63:
    v62 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v62); }
/* error exit handlers */
v73:
    popv(3);
    return nil;
}



/* Code for sort */

static Lisp_Object CC_sort(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sort");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    v87 = v0;
/* end of prologue */
    v91 = v87;
    v87 = qvalue(elt(env, 1)); /* nil */
    v91 = Lappend(nil, v91, v87);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    v87 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* stable!-sortip */
        return (*qfn2(fn))(qenv(fn), v91, v87);
    }
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for smemql */

static Lisp_Object CC_smemql(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemql");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v96;

v96:
    v99 = stack[-1];
    if (v99 == nil) goto v84;
    v99 = stack[-1];
    v100 = qcar(v99);
    v99 = stack[0];
    v99 = Lsmemq(nil, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    if (v99 == nil) goto v10;
    v99 = stack[-1];
    v100 = qcar(v99);
    v99 = stack[-2];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    stack[-2] = v99;
    v99 = stack[-1];
    v99 = qcdr(v99);
    stack[-1] = v99;
    goto v96;

v10:
    v99 = stack[-1];
    v99 = qcdr(v99);
    stack[-1] = v99;
    goto v96;

v84:
    v99 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v99);
    }
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for physopp!* */

static Lisp_Object CC_physoppH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopp*");
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
    v102 = stack[0];
    fn = elt(env, 5); /* physopp */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    if (!(v102 == nil)) { popv(2); return onevalue(v102); }
    v102 = stack[0];
    if (!consp(v102)) goto v84;
    v102 = stack[0];
    v37 = qcar(v102);
    v102 = elt(env, 2); /* physopfn */
    v102 = Lflagp(nil, v37, v102);
    env = stack[-1];
    if (!(v102 == nil)) { popv(2); return onevalue(v102); }
    v102 = stack[0];
    v37 = qcar(v102);
    v102 = elt(env, 3); /* physoparith */
    v102 = Lflagp(nil, v37, v102);
    env = stack[-1];
    if (v102 == nil) goto v76;
    v102 = stack[0];
    v102 = qcdr(v102);
    fn = elt(env, 6); /* hasonephysop */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    goto v75;

v75:
    if (!(v102 == nil)) { popv(2); return onevalue(v102); }
    v102 = stack[0];
    v37 = qcar(v102);
    v102 = elt(env, 4); /* physopmapping */
    v102 = Lflagp(nil, v37, v102);
    env = stack[-1];
    if (v102 == nil) goto v39;
    v102 = stack[0];
    v102 = qcdr(v102);
    {
        popv(2);
        fn = elt(env, 6); /* hasonephysop */
        return (*qfn1(fn))(qenv(fn), v102);
    }

v39:
    v102 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v102); }

v76:
    v102 = qvalue(elt(env, 1)); /* nil */
    goto v75;

v84:
    v102 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v102); }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for red_divtestbe */

static Lisp_Object MS_CDECL CC_red_divtestbe(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v23, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_divtestbe");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_divtestbe");
#endif
    if (stack >= stacklimit)
    {
        push3(v23,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v23;
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */

v96:
    v74 = stack[-2];
    if (v74 == nil) goto v84;
    v74 = stack[-2];
    v74 = qcar(v74);
    fn = elt(env, 2); /* bas_dpecart */
    v13 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v74 = stack[0];
    v74 = (Lisp_Object)lesseq2(v13, v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v74 = v74 ? lisp_true : nil;
    env = stack[-3];
    if (v74 == nil) goto v99;
    v74 = stack[-2];
    v74 = qcar(v74);
    fn = elt(env, 3); /* bas_dpoly */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    fn = elt(env, 4); /* dp_lmon */
    v13 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v74 = stack[-1];
    fn = elt(env, 5); /* mo_vdivides!? */
    v74 = (*qfn2(fn))(qenv(fn), v13, v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    if (v74 == nil) goto v99;
    v74 = stack[-2];
    v74 = qcar(v74);
    { popv(4); return onevalue(v74); }

v99:
    v74 = stack[-2];
    v74 = qcdr(v74);
    stack[-2] = v74;
    goto v96;

v84:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v74); }
/* error exit handlers */
v39:
    popv(4);
    return nil;
}



/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v23, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for layout-formula");
#endif
    if (stack >= stacklimit)
    {
        push3(v23,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v23;
    stack[-7] = v8;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* ycoord!* */
    qvalue(elt(env, 1)) = nil; /* ycoord!* */
    stack[-5] = qvalue(elt(env, 2)); /* ymin!* */
    qvalue(elt(env, 2)) = nil; /* ymin!* */
    stack[-4] = qvalue(elt(env, 3)); /* ymax!* */
    qvalue(elt(env, 3)) = nil; /* ymax!* */
    stack[-3] = qvalue(elt(env, 4)); /* posn!* */
    qvalue(elt(env, 4)) = nil; /* posn!* */
    stack[-2] = qvalue(elt(env, 5)); /* pline!* */
    qvalue(elt(env, 5)) = nil; /* pline!* */
    stack[-1] = qvalue(elt(env, 6)); /* testing!-width!* */
    qvalue(elt(env, 6)) = nil; /* testing!-width!* */
    stack[0] = qvalue(elt(env, 7)); /* overflowed!* */
    qvalue(elt(env, 7)) = nil; /* overflowed!* */
    v106 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 7)) = v106; /* overflowed!* */
    qvalue(elt(env, 5)) = v106; /* pline!* */
    v106 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v106; /* ymax!* */
    qvalue(elt(env, 2)) = v106; /* ymin!* */
    qvalue(elt(env, 1)) = v106; /* ycoord!* */
    v106 = qvalue(elt(env, 9)); /* orig!* */
    qvalue(elt(env, 4)) = v106; /* posn!* */
    v106 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 6)) = v106; /* testing!-width!* */
    v106 = stack[-6];
    if (v106 == nil) goto v99;
    v78 = stack[-6];
    v106 = elt(env, 11); /* inbrackets */
    if (v78 == v106) goto v65;
    v106 = stack[-6];
    fn = elt(env, 14); /* oprin */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-10];
    goto v99;

v99:
    v78 = stack[-8];
    v106 = stack[-7];
    fn = elt(env, 15); /* maprint */
    v106 = (*qfn2(fn))(qenv(fn), v78, v106);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-10];
    v78 = stack[-6];
    v106 = elt(env, 11); /* inbrackets */
    if (!(v78 == v106)) goto v98;
    v106 = elt(env, 13); /* ")" */
    fn = elt(env, 16); /* prin2!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-10];
    goto v98;

v98:
    v106 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v106 == nil) goto v97;
    v106 = qvalue(elt(env, 8)); /* nil */
    goto v1;

v1:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v106); }

v97:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v78 = qvalue(elt(env, 4)); /* posn!* */
    v106 = qvalue(elt(env, 9)); /* orig!* */
    stack[-6] = difference2(v78, v106);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-10];
    v78 = qvalue(elt(env, 2)); /* ymin!* */
    v106 = qvalue(elt(env, 3)); /* ymax!* */
    v106 = cons(v78, v106);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-10];
    v106 = acons(stack[-7], stack[-6], v106);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-10];
    goto v1;

v65:
    v106 = elt(env, 12); /* "(" */
    fn = elt(env, 16); /* prin2!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-10];
    goto v99;
/* error exit handlers */
v107:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    popv(11);
    return nil;
}



/* Code for gperm1 */

static Lisp_Object MS_CDECL CC_gperm1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v23, Lisp_Object v30, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gperm1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm1");
#endif
    if (stack >= stacklimit)
    {
        push4(v30,v23,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v8,v23,v30);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v30;
    stack[-2] = v23;
    stack[-3] = v8;
    stack[-4] = v0;
/* end of prologue */

v84:
    v94 = stack[-4];
    if (v94 == nil) goto v6;
    v94 = stack[-4];
    v94 = qcdr(v94);
    stack[-5] = v94;
    v94 = stack[-4];
    v95 = qcar(v94);
    v94 = stack[-2];
    v94 = cons(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[0] = v94;
    v95 = stack[-3];
    v94 = stack[-2];
    v94 = cons(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    fn = elt(env, 1); /* rev */
    v95 = (*qfn2(fn))(qenv(fn), stack[-4], v94);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    v94 = stack[-1];
    v94 = cons(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[-1] = v94;
    v94 = stack[0];
    stack[-2] = v94;
    v94 = stack[-5];
    stack[-4] = v94;
    goto v84;

v6:
    v110 = stack[-3];
    v95 = stack[-2];
    v94 = stack[-1];
    popv(7);
    return acons(v110, v95, v94);
/* error exit handlers */
v111:
    popv(7);
    return nil;
}



/* Code for removev */

static Lisp_Object CC_removev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v39, v18, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removev");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v40 = v8;
    v18 = v0;
/* end of prologue */

v63:
    v98 = v18;
    if (v98 == nil) goto v2;
    v98 = v18;
    v98 = qcdr(v98);
    v39 = qcar(v98);
    v98 = v40;
    if (v39 == v98) goto v85;
    v98 = v18;
    v98 = qcdr(v98);
    v18 = v98;
    goto v63;

v85:
    v98 = v18;
    v39 = v18;
    v39 = qcdr(v39);
    v39 = qcdr(v39);
        popv(1);
        return Lrplacd(nil, v98, v39);

v2:
    v39 = elt(env, 1); /* "Vertex" */
    v18 = v40;
    v98 = elt(env, 2); /* "is absent." */
    v98 = list3(v39, v18, v98);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cerror */
        return (*qfn1(fn))(qenv(fn), v98);
    }
/* error exit handlers */
v109:
    popv(1);
    return nil;
}



/* Code for ibalp_emptyclausep */

static Lisp_Object CC_ibalp_emptyclausep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_emptyclausep");
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
    v100 = stack[0];
    v100 = qcdr(v100);
    v100 = qcdr(v100);
    v100 = qcdr(v100);
    v100 = qcdr(v100);
    v100 = qcar(v100);
    if (v100 == nil) goto v6;
    v100 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v100); }

v6:
    v100 = stack[0];
    v100 = qcdr(v100);
    v100 = qcdr(v100);
    v52 = qcar(v100);
    v100 = (Lisp_Object)1; /* 0 */
    v100 = Leqn(nil, v52, v100);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-1];
    if (v100 == nil) goto v2;
    v100 = stack[0];
    v100 = qcdr(v100);
    v100 = qcdr(v100);
    v100 = qcdr(v100);
    v52 = qcar(v100);
    v100 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Leqn(nil, v52, v100);

v2:
    v100 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v100); }
/* error exit handlers */
v74:
    popv(2);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v8, Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate");
#endif
    if (stack >= stacklimit)
    {
        push2(v23,v8);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v8,v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v23;
    v62 = v8;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v62; /* ps */
    v72 = qvalue(elt(env, 1)); /* ps */
    v62 = stack[-2];
    fn = elt(env, 3); /* ps!:get!-term */
    v62 = (*qfn2(fn))(qenv(fn), v72, v62);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[-1] = v62;
    v62 = stack[-1];
    if (v62 == nil) goto v64;
    v62 = stack[-1];
    goto v96;

v96:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v62); }

v64:
    v62 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:last!-term */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v62 = add1(v62);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[0] = v62;
    goto v41;

v41:
    v72 = stack[-2];
    v62 = stack[0];
    v62 = difference2(v72, v62);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v62 = Lminusp(nil, v62);
    env = stack[-4];
    if (v62 == nil) goto v16;
    v62 = stack[-1];
    goto v96;

v16:
    v72 = qvalue(elt(env, 1)); /* ps */
    v62 = stack[0];
    fn = elt(env, 5); /* ps!:evaluate!-next */
    v62 = (*qfn2(fn))(qenv(fn), v72, v62);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[-1] = v62;
    v62 = stack[0];
    v62 = add1(v62);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[0] = v62;
    goto v41;
/* error exit handlers */
v94:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for subscriptedvarp */

static Lisp_Object CC_subscriptedvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subscriptedvarp");
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
    v76 = qvalue(elt(env, 1)); /* nil */
    v75 = stack[0];
    fn = elt(env, 3); /* symtabget */
    v75 = (*qfn2(fn))(qenv(fn), v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v76 = Llength(nil, v75);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v75 = (Lisp_Object)33; /* 2 */
    v75 = (Lisp_Object)greaterp2(v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v75 = v75 ? lisp_true : nil;
    env = stack[-1];
    if (!(v75 == nil)) { popv(2); return onevalue(v75); }
    v75 = stack[0];
    v76 = elt(env, 2); /* subscripted */
        popv(2);
        return Lflagp(nil, v75, v76);
/* error exit handlers */
v58:
    popv(2);
    return nil;
}



/* Code for bound */

static Lisp_Object CC_bound(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bound");
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
    v11 = v0;
/* end of prologue */
    fn = elt(env, 3); /* binding */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[0];
    v49 = v11;
    v11 = v49;
    if (v11 == nil) goto v80;
    v11 = v49;
    v49 = elt(env, 2); /* unbound */
        popv(1);
        return Lneq(nil, v11, v49);

v80:
    v11 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v11); }
/* error exit handlers */
v92:
    popv(1);
    return nil;
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*farg");
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
    v52 = v14;
    v52 = qcdr(v52);
    if (v52 == nil) goto v77;
    stack[-1] = nil;
    v52 = v14;
    stack[0] = v52;
    goto v91;

v91:
    v52 = stack[0];
    if (v52 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v52 = stack[0];
    v52 = qcar(v52);
    fn = elt(env, 2); /* deg!*form */
    v14 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    v52 = stack[-1];
    fn = elt(env, 3); /* addf */
    v52 = (*qfn2(fn))(qenv(fn), v14, v52);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    stack[-1] = v52;
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v91;

v77:
    v52 = v14;
    v52 = qcar(v52);
    {
        popv(3);
        fn = elt(env, 2); /* deg!*form */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v15:
    popv(3);
    return nil;
}



/* Code for abs!: */

static Lisp_Object CC_absT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for abs:");
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
    v85 = qcdr(v85);
    v10 = qcar(v85);
    v85 = (Lisp_Object)1; /* 0 */
    v85 = (Lisp_Object)greaterp2(v10, v85);
    nil = C_nil;
    if (exception_pending()) goto v42;
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (!(v85 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); /* !:rd!: */
    v85 = stack[0];
    v85 = qcdr(v85);
    v85 = qcar(v85);
    v10 = negate(v85);
    nil = C_nil;
    if (exception_pending()) goto v42;
    v85 = stack[0];
    v85 = qcdr(v85);
    v85 = qcdr(v85);
    {
        Lisp_Object v99 = stack[-1];
        popv(3);
        return list2star(v99, v10, v85);
    }
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



/* Code for dp_diff */

static Lisp_Object CC_dp_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v1 = v8;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    fn = elt(env, 1); /* dp_neg */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    {
        Lisp_Object v6 = stack[0];
        popv(2);
        fn = elt(env, 2); /* dp_sum */
        return (*qfn2(fn))(qenv(fn), v6, v1);
    }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for resimp */

static Lisp_Object CC_resimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp");
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
    v80 = v0;
/* end of prologue */
    v96 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v96; /* varstack!* */
    v96 = v80;
    fn = elt(env, 3); /* resimp1 */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v96); }
/* error exit handlers */
v84:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for pv_sort2a */

static Lisp_Object CC_pv_sort2a(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v118;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort2a");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */

v63:
    v117 = stack[0];
    v117 = qcdr(v117);
    if (v117 == nil) goto v88;
    v117 = stack[-1];
    v118 = qcdr(v117);
    v117 = stack[0];
    v117 = qcar(v117);
    v117 = qcdr(v117);
    v117 = (Lisp_Object)greaterp2(v118, v117);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v117 = v117 ? lisp_true : nil;
    env = stack[-3];
    if (v117 == nil) goto v53;
    v117 = stack[0];
    v117 = qcdr(v117);
    stack[0] = v117;
    goto v63;

v53:
    v117 = stack[0];
    v118 = qcar(v117);
    v117 = stack[0];
    v117 = qcdr(v117);
    v117 = cons(v118, v117);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    stack[-2] = v117;
    v118 = stack[0];
    v117 = stack[-1];
    v118 = Lrplaca(nil, v118, v117);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v117 = stack[-2];
        popv(4);
        return Lrplacd(nil, v118, v117);

v88:
    v117 = stack[-1];
    v118 = qcdr(v117);
    v117 = stack[0];
    v117 = qcar(v117);
    v117 = qcdr(v117);
    v117 = (Lisp_Object)greaterp2(v118, v117);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v117 = v117 ? lisp_true : nil;
    env = stack[-3];
    if (v117 == nil) goto v42;
    v117 = stack[-1];
    v117 = ncons(v117);
    nil = C_nil;
    if (exception_pending()) goto v28;
    {
        Lisp_Object v55 = stack[0];
        popv(4);
        return Lrplacd(nil, v55, v117);
    }

v42:
    v117 = stack[0];
    v118 = qcar(v117);
    v117 = stack[0];
    v117 = qcdr(v117);
    v117 = cons(v118, v117);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    stack[-2] = v117;
    v118 = stack[0];
    v117 = stack[-1];
    v118 = Lrplaca(nil, v118, v117);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v117 = stack[-2];
        popv(4);
        return Lrplacd(nil, v118, v117);
/* error exit handlers */
v28:
    popv(4);
    return nil;
}



/* Code for modplus!: */

static Lisp_Object CC_modplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v4 = v8;
    v5 = v0;
/* end of prologue */
    v5 = qcdr(v5);
    v4 = qcdr(v4);
    fn = elt(env, 1); /* general!-modular!-plus */
    v4 = (*qfn2(fn))(qenv(fn), v5, v4);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v6:
    popv(1);
    return nil;
}



/* Code for mkgi */

static Lisp_Object CC_mkgi(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkgi");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v8;
    v5 = v0;
/* end of prologue */
    v6 = elt(env, 1); /* !:gi!: */
    return list2star(v6, v5, v4);
}



/* Code for sfto_dcontentf */

static Lisp_Object CC_sfto_dcontentf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dcontentf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v0;
/* end of prologue */
    v3 = v81;
    v81 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sfto_dcontentf1 */
        return (*qfn2(fn))(qenv(fn), v3, v81);
    }
}



/* Code for frvarsof */

static Lisp_Object CC_frvarsof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v50, v94, v95;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for frvarsof");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v50 = v8;
    v94 = v0;
/* end of prologue */

v3:
    v95 = v94;
    v73 = qvalue(elt(env, 1)); /* frlis!* */
    v73 = Lmemq(nil, v95, v73);
    if (v73 == nil) goto v81;
    v95 = v94;
    v73 = v50;
    v73 = Lmemq(nil, v95, v73);
    if (!(v73 == nil)) { popv(2); return onevalue(v50); }
    stack[0] = v50;
    v73 = v94;
    v73 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v102;
    {
        Lisp_Object v37 = stack[0];
        popv(2);
        return Lappend(nil, v37, v73);
    }

v81:
    v73 = v94;
    if (!consp(v73)) { popv(2); return onevalue(v50); }
    v73 = v94;
    v73 = qcdr(v73);
    stack[0] = v73;
    v73 = v94;
    v73 = qcar(v73);
    v73 = CC_frvarsof(env, v73, v50);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v50 = v73;
    v73 = stack[0];
    v94 = v73;
    goto v3;
/* error exit handlers */
v102:
    popv(2);
    return nil;
}



/* Code for ibalp_lenisone */

static Lisp_Object CC_ibalp_lenisone(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_lenisone");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v2 = v4;
    if (v2 == nil) goto v77;
    v2 = v4;
    v2 = qcdr(v2);
    v2 = (v2 == nil ? lisp_true : nil);
    return onevalue(v2);

v77:
    v2 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v2);
}



/* Code for omobj */

static Lisp_Object MS_CDECL CC_omobj(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobj");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobj");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v93 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 4); /* compress!* */
    v75 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[0];
    v93 = qvalue(elt(env, 2)); /* omfuncs!* */
    v93 = Lassoc(nil, v75, v93);
    v75 = v93;
    if (v93 == nil) goto v96;
    v93 = v75;
    v93 = qcdr(v93);
    v75 = qcar(v93);
    v93 = qvalue(elt(env, 3)); /* nil */
    {
        popv(1);
        fn = elt(env, 5); /* apply */
        return (*qfn2(fn))(qenv(fn), v75, v93);
    }

v96:
    v93 = nil;
    { popv(1); return onevalue(v93); }
/* error exit handlers */
v76:
    popv(1);
    return nil;
}



/* Code for quotematrix */

static Lisp_Object CC_quotematrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v30;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotematrix");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v30 = elt(env, 1); /* matrix */
    return onevalue(v30);
}



/* Code for algid */

static Lisp_Object CC_algid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v82, v58;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algid");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v76 = v8;
    v58 = v0;
/* end of prologue */
    v82 = v58;
    v76 = Latsoc(nil, v82, v76);
    if (!(v76 == nil)) return onevalue(v58);
    v82 = v58;
    v76 = elt(env, 1); /* share */
    v76 = Lflagp(nil, v82, v76);
    if (!(v76 == nil)) return onevalue(v58);
    v76 = v58;
        return Lmkquote(nil, v76);
}



/* Code for red!-char!-downcase */

static Lisp_Object CC_redKcharKdowncase(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v49, v92;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-char-downcase");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v49 = v0;
/* end of prologue */
    v11 = v49;
    v92 = qvalue(elt(env, 1)); /* charassoc!* */
    v11 = Latsoc(nil, v11, v92);
    v92 = v11;
    v11 = v92;
    if (v11 == nil) return onevalue(v49);
    v11 = v92;
    v11 = qcdr(v11);
    return onevalue(v11);
}



/* Code for reval2 */

static Lisp_Object CC_reval2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval2");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    v10 = v0;
/* end of prologue */
    v85 = stack[0];
    if (!(v85 == nil)) goto v4;
    v85 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v85 == nil) goto v4;
    v85 = qvalue(elt(env, 2)); /* dmode!* */
    if (!(v85 == nil)) goto v4;
    v85 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = qvalue(elt(env, 4)); /* !*mcd */
    qvalue(elt(env, 4)) = v85; /* !*mcd */
    v85 = v10;
    fn = elt(env, 5); /* simp!* */
    v10 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    qvalue(elt(env, 4)) = stack[-1]; /* !*mcd */
    v85 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* !*q2a1 */
        return (*qfn2(fn))(qenv(fn), v10, v85);
    }

v4:
    v85 = v10;
    fn = elt(env, 5); /* simp!* */
    v10 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v85 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* !*q2a1 */
        return (*qfn2(fn))(qenv(fn), v10, v85);
    }
/* error exit handlers */
v99:
    popv(3);
    return nil;
v42:
    env = stack[-2];
    qvalue(elt(env, 4)) = stack[-1]; /* !*mcd */
    popv(3);
    return nil;
}



/* Code for dp_times_bc */

static Lisp_Object CC_dp_times_bc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bc");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v119 = v8;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v119;
    v119 = stack[-5];
    if (v119 == nil) goto v1;
    v119 = stack[-5];
    v119 = qcar(v119);
    v35 = v119;
    stack[0] = qcar(v35);
    v35 = stack[-4];
    v119 = qcdr(v119);
    fn = elt(env, 2); /* bc_prod */
    v119 = (*qfn2(fn))(qenv(fn), v35, v119);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-6];
    v119 = cons(stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-6];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-6];
    stack[-2] = v119;
    stack[-3] = v119;
    goto v7;

v7:
    v119 = stack[-5];
    v119 = qcdr(v119);
    stack[-5] = v119;
    v119 = stack[-5];
    if (v119 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v119 = stack[-5];
    v119 = qcar(v119);
    v35 = v119;
    stack[0] = qcar(v35);
    v35 = stack[-4];
    v119 = qcdr(v119);
    fn = elt(env, 2); /* bc_prod */
    v119 = (*qfn2(fn))(qenv(fn), v35, v119);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-6];
    v119 = cons(stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-6];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-6];
    v119 = Lrplacd(nil, stack[-1], v119);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-6];
    v119 = stack[-2];
    v119 = qcdr(v119);
    stack[-2] = v119;
    goto v7;

v1:
    v119 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v119); }
/* error exit handlers */
v104:
    popv(7);
    return nil;
}



/* Code for tsym4 */

static Lisp_Object MS_CDECL CC_tsym4(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v23, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "tsym4");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tsym4");
#endif
    if (stack >= stacklimit)
    {
        push3(v23,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v23;
    stack[-1] = v8;
    v74 = v0;
/* end of prologue */

v80:
    v13 = v74;
    if (v13 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v13 = v74;
    v13 = qcdr(v13);
    stack[-2] = v13;
    v13 = stack[-1];
    v13 = qcdr(v13);
    v74 = qcar(v74);
    fn = elt(env, 1); /* pv_applp */
    v13 = (*qfn2(fn))(qenv(fn), v13, v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v74 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v74 = (*qfn2(fn))(qenv(fn), v13, v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    fn = elt(env, 3); /* pv_renorm */
    v13 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v74 = stack[0];
    fn = elt(env, 4); /* insert_pv */
    v74 = (*qfn2(fn))(qenv(fn), v13, v74);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    stack[0] = v74;
    v74 = stack[-2];
    goto v80;
/* error exit handlers */
v39:
    popv(4);
    return nil;
}



/* Code for wulessp */

static Lisp_Object CC_wulessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v118 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    if (v118 == nil) goto v91;
    v118 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v118;
    goto v84;

v84:
    v118 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    if (v118 == nil) goto v58;
    v118 = qvalue(elt(env, 1)); /* nil */
    goto v81;

v81:
    fn = elt(env, 3); /* symbollessp */
    v118 = (*qfn2(fn))(qenv(fn), stack[-2], v118);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    if (!(v118 == nil)) { popv(4); return onevalue(v118); }
    v118 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    if (v118 == nil) goto v59;
    v118 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v118;
    goto v74;

v74:
    v118 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    if (v118 == nil) goto v37;
    v118 = qvalue(elt(env, 1)); /* nil */
    goto v13;

v13:
    if (equal(stack[-2], v118)) goto v36;
    v118 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v118); }

v36:
    v118 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    if (v118 == nil) goto v120;
    v118 = (Lisp_Object)1; /* 0 */
    stack[-1] = v118;
    goto v71;

v71:
    v118 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v28;
    if (v118 == nil) goto v121;
    v118 = (Lisp_Object)1; /* 0 */
    goto v69;

v69:
    {
        Lisp_Object v55 = stack[-1];
        popv(4);
        return Llessp(nil, v55, v118);
    }

v121:
    v118 = stack[0];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v118 = qcdr(v118);
    goto v69;

v120:
    v118 = stack[-1];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v118 = qcdr(v118);
    stack[-1] = v118;
    goto v71;

v37:
    v118 = stack[0];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v118 = qcar(v118);
    goto v13;

v59:
    v118 = stack[-1];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v118 = qcar(v118);
    stack[-2] = v118;
    goto v74;

v58:
    v118 = stack[0];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v118 = qcar(v118);
    goto v81;

v91:
    v118 = stack[-1];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v118 = qcar(v118);
    stack[-2] = v118;
    goto v84;
/* error exit handlers */
v28:
    popv(4);
    return nil;
}



/* Code for sortcolelem */

static Lisp_Object MS_CDECL CC_sortcolelem(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v23, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v123;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sortcolelem");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sortcolelem");
#endif
    if (stack >= stacklimit)
    {
        push3(v23,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v23;
    stack[-2] = v8;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = nil;
    v79 = stack[-2];
    v79 = qcdr(v79);
    stack[-4] = v79;
    goto v1;

v1:
    v79 = stack[0];
    if (v79 == nil) goto v4;
    v79 = nil;
    { popv(6); return onevalue(v79); }

v4:
    v79 = stack[-4];
    if (v79 == nil) goto v12;
    v123 = stack[-3];
    v79 = stack[-4];
    v79 = qcar(v79);
    v79 = qcar(v79);
    v79 = (Lisp_Object)lessp2(v123, v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    v79 = v79 ? lisp_true : nil;
    env = stack[-5];
    if (v79 == nil) goto v69;
    stack[0] = stack[-2];
    v123 = stack[-3];
    v79 = stack[-1];
    v79 = cons(v123, v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v123 = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v79 = stack[-4];
    v79 = Lrplacd(nil, v123, v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v79 = Lrplacd(nil, stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v79 = qvalue(elt(env, 2)); /* t */
    stack[0] = v79;
    goto v1;

v69:
    v123 = stack[-3];
    v79 = stack[-4];
    v79 = qcar(v79);
    v79 = qcar(v79);
    v79 = (Lisp_Object)greaterp2(v123, v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    v79 = v79 ? lisp_true : nil;
    env = stack[-5];
    if (v79 == nil) goto v1;
    v79 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v79;
    v79 = stack[-2];
    v79 = qcdr(v79);
    stack[-2] = v79;
    v79 = stack[-2];
    v79 = qcdr(v79);
    stack[-4] = v79;
    goto v1;

v12:
    stack[0] = stack[-2];
    v123 = stack[-3];
    v79 = stack[-1];
    v79 = cons(v123, v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v79 = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v79 = Lrplacd(nil, stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v79 = qvalue(elt(env, 2)); /* t */
    stack[0] = v79;
    goto v1;
/* error exit handlers */
v121:
    popv(6);
    return nil;
}



/* Code for downwght */

static Lisp_Object CC_downwght(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for downwght");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v5 = stack[-1];
    fn = elt(env, 1); /* delhisto */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    v6 = stack[-1];
    v5 = stack[0];
    fn = elt(env, 2); /* downwght1 */
    v5 = (*qfn2(fn))(qenv(fn), v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    v5 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* inshisto */
        return (*qfn1(fn))(qenv(fn), v5);
    }
/* error exit handlers */
v91:
    popv(3);
    return nil;
}



/* Code for diplength */

static Lisp_Object CC_diplength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v74;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diplength");
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
    goto v96;

v96:
    v14 = stack[0];
    if (v14 == nil) goto v80;
    v74 = (Lisp_Object)17; /* 1 */
    v14 = stack[-1];
    v14 = cons(v74, v14);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    stack[-1] = v14;
    v14 = stack[0];
    v14 = qcdr(v14);
    v14 = qcdr(v14);
    stack[0] = v14;
    goto v96;

v80:
    v14 = (Lisp_Object)1; /* 0 */
    v74 = v14;
    goto v7;

v7:
    v14 = stack[-1];
    if (v14 == nil) { popv(3); return onevalue(v74); }
    v14 = stack[-1];
    v14 = qcar(v14);
    v14 = plus2(v14, v74);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v74 = v14;
    v14 = stack[-1];
    v14 = qcdr(v14);
    stack[-1] = v14;
    goto v7;
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for mknwedge */

static Lisp_Object CC_mknwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mknwedge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v0;
/* end of prologue */
    v64 = v11;
    v64 = qcdr(v64);
    if (v64 == nil) goto v6;
    v64 = elt(env, 1); /* wedge */
    return cons(v64, v11);

v6:
    v64 = v11;
    v64 = qcar(v64);
    return onevalue(v64);
}



/* Code for worderp */

static Lisp_Object CC_worderp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for worderp");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */

v63:
    v131 = stack[-1];
    if (!consp(v131)) goto v84;
    v131 = stack[-1];
    v132 = qcar(v131);
    v131 = elt(env, 1); /* indexvar */
    v131 = Lflagp(nil, v132, v131);
    env = stack[-2];
    if (v131 == nil) goto v84;
    v131 = stack[0];
    if (!consp(v131)) goto v84;
    v131 = stack[0];
    v132 = qcar(v131);
    v131 = elt(env, 1); /* indexvar */
    v131 = Lflagp(nil, v132, v131);
    env = stack[-2];
    if (v131 == nil) goto v84;
    v132 = stack[-1];
    v131 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* indexvarordp */
        return (*qfn2(fn))(qenv(fn), v132, v131);
    }

v84:
    v131 = stack[-1];
    if (!consp(v131)) goto v52;
    v132 = stack[-1];
    v131 = qvalue(elt(env, 2)); /* kord!* */
    v131 = Lmemq(nil, v132, v131);
    if (!(v131 == nil)) goto v52;
    v131 = stack[0];
    if (!consp(v131)) goto v107;
    v132 = stack[0];
    v131 = qvalue(elt(env, 2)); /* kord!* */
    v131 = Lmemq(nil, v132, v131);
    if (!(v131 == nil)) goto v107;
    v131 = stack[-1];
    fn = elt(env, 6); /* peel */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    stack[-1] = v131;
    v131 = stack[0];
    fn = elt(env, 6); /* peel */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    stack[0] = v131;
    goto v63;

v107:
    v131 = stack[-1];
    fn = elt(env, 6); /* peel */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v133 = v131;
    v132 = v133;
    v131 = stack[0];
    if (v132 == v131) goto v135;
    v132 = v133;
    v131 = stack[0];
    stack[-1] = v132;
    stack[0] = v131;
    goto v63;

v135:
    v131 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v131); }

v52:
    v131 = stack[0];
    if (!consp(v131)) goto v136;
    v132 = stack[0];
    v131 = qvalue(elt(env, 2)); /* kord!* */
    v131 = Lmemq(nil, v132, v131);
    if (!(v131 == nil)) goto v136;
    v131 = stack[0];
    fn = elt(env, 6); /* peel */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v133 = v131;
    v132 = stack[-1];
    v131 = v133;
    if (v132 == v131) goto v103;
    v131 = stack[-1];
    v132 = v133;
    stack[-1] = v131;
    stack[0] = v132;
    goto v63;

v103:
    v131 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v131); }

v136:
    v132 = stack[-1];
    v131 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* ordop */
        return (*qfn2(fn))(qenv(fn), v132, v131);
    }
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



/* Code for simpminus */

static Lisp_Object CC_simpminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpminus");
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
    v1 = v0;
/* end of prologue */
    v2 = v1;
    v1 = elt(env, 1); /* minus */
    fn = elt(env, 2); /* carx */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[0];
    fn = elt(env, 3); /* simp */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* negsq */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v4:
    popv(1);
    return nil;
}



/* Code for getphystype!*sq */

static Lisp_Object CC_getphystypeHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype*sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v96 = v0;
/* end of prologue */
    v96 = qcar(v96);
    v96 = qcar(v96);
    {
        fn = elt(env, 1); /* getphystypesf */
        return (*qfn1(fn))(qenv(fn), v96);
    }
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpplus");
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
    v13 = stack[0];
    v15 = Llength(nil, v13);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v13 = (Lisp_Object)33; /* 2 */
    if (!(v15 == v13)) goto v11;
    v13 = stack[0];
    fn = elt(env, 2); /* ckpreci!# */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    goto v11;

v11:
    v15 = qvalue(elt(env, 1)); /* nil */
    v13 = (Lisp_Object)17; /* 1 */
    v13 = cons(v15, v13);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    stack[-1] = v13;
    goto v63;

v63:
    v13 = stack[0];
    if (v13 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v13 = stack[0];
    fn = elt(env, 3); /* simpcar */
    v15 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v13 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v13 = (*qfn2(fn))(qenv(fn), v15, v13);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    stack[-1] = v13;
    v13 = stack[0];
    v13 = qcdr(v13);
    stack[0] = v13;
    goto v63;
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for groeb!=testa */

static Lisp_Object CC_groebMtesta(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testa");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    v12 = v0;
/* end of prologue */
    v89 = v12;
    v12 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    stack[-1] = (*qfn2(fn))(qenv(fn), v89, v12);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v89 = stack[0];
    v12 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    v12 = (*qfn2(fn))(qenv(fn), v89, v12);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    {
        Lisp_Object v76 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v76, v12);
    }
/* error exit handlers */
v75:
    popv(3);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp1");
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
    v76 = stack[0];
    v82 = qcar(v76);
    v76 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v82, v76);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    v76 = stack[0];
    v82 = qcdr(v76);
    v76 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v76 = (*qfn2(fn))(qenv(fn), v82, v76);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    fn = elt(env, 5); /* quotsq */
    v76 = (*qfn2(fn))(qenv(fn), stack[-1], v76);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    stack[0] = v76;
    v76 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v76; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v57:
    popv(3);
    return nil;
}



/* Code for gperm */

static Lisp_Object CC_gperm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm");
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
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v2;

v2:
    v119 = stack[0];
    v122 = (Lisp_Object)1; /* 0 */
    v122 = (Lisp_Object)greaterp2(v119, v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v122 = v122 ? lisp_true : nil;
    env = stack[-4];
    if (v122 == nil) goto v96;
    v119 = stack[0];
    v122 = stack[-1];
    v122 = cons(v119, v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-1] = v122;
    v122 = stack[0];
    v122 = sub1(v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[0] = v122;
    goto v2;

v96:
    v122 = stack[-1];
    fn = elt(env, 2); /* gperm0 */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-3] = v122;
    v122 = stack[-3];
    if (v122 == nil) goto v100;
    v122 = stack[-3];
    v122 = qcar(v122);
    fn = elt(env, 3); /* pkp */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-1] = v122;
    stack[-2] = v122;
    goto v10;

v10:
    v122 = stack[-3];
    v122 = qcdr(v122);
    stack[-3] = v122;
    v122 = stack[-3];
    if (v122 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v122 = stack[-3];
    v122 = qcar(v122);
    fn = elt(env, 3); /* pkp */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v122 = Lrplacd(nil, stack[0], v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v122 = stack[-1];
    v122 = qcdr(v122);
    stack[-1] = v122;
    goto v10;

v100:
    v122 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v122); }
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for reordsq */

static Lisp_Object CC_reordsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reordsq");
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
    v4 = stack[0];
    v4 = qcar(v4);
    fn = elt(env, 1); /* reorder */
    stack[-1] = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    v4 = stack[0];
    v4 = qcdr(v4);
    fn = elt(env, 1); /* reorder */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v88;
    {
        Lisp_Object v87 = stack[-1];
        popv(3);
        return cons(v87, v4);
    }
/* error exit handlers */
v88:
    popv(3);
    return nil;
}



/* Code for minus!-mod!-p */

static Lisp_Object CC_minusKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minus-mod-p");
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
    goto v63;

v63:
    v39 = stack[-1];
    if (v39 == nil) goto v7;
    v39 = stack[-1];
    if (!consp(v39)) goto v11;
    v39 = stack[-1];
    v39 = qcar(v39);
    if (!consp(v39)) goto v11;
    v39 = stack[-1];
    v39 = qcar(v39);
    stack[0] = qcar(v39);
    v39 = stack[-1];
    v39 = qcar(v39);
    v39 = qcdr(v39);
    v18 = CC_minusKmodKp(env, v39);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    v39 = stack[-2];
    v39 = acons(stack[0], v18, v39);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    stack[-2] = v39;
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[-1] = v39;
    goto v63;

v11:
    v18 = stack[-2];
    v39 = stack[-1];
    {   int32_t w = int_of_fixnum(v39);
        if (w != 0) w = current_modulus - w;
        v39 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v18, v39);
    }

v7:
    v39 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v39);
    }
/* error exit handlers */
v59:
    popv(4);
    return nil;
}



/* Code for errorset!* */

static Lisp_Object CC_errorsetH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for errorset*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v8;
    v5 = v0;
/* end of prologue */
    v6 = v5;
    v5 = v4;
    v4 = qvalue(elt(env, 1)); /* !*backtrace */
    {
        fn = elt(env, 2); /* errorset */
        return (*qfnn(fn))(qenv(fn), 3, v6, v5, v4);
    }
}



/* Code for free!-powerp */

static Lisp_Object CC_freeKpowerp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for free-powerp");
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

v17:
    v82 = stack[0];
    if (!consp(v82)) goto v77;
    v82 = stack[0];
    v82 = qcar(v82);
    if (!consp(v82)) goto v77;
    v82 = stack[0];
    v82 = qcar(v82);
    v82 = qcar(v82);
    v82 = qcdr(v82);
    v82 = integerp(v82);
    v82 = (v82 == nil ? lisp_true : nil);
    if (!(v82 == nil)) { popv(2); return onevalue(v82); }
    v82 = stack[0];
    v82 = qcar(v82);
    v82 = qcdr(v82);
    v82 = CC_freeKpowerp(env, v82);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    if (!(v82 == nil)) { popv(2); return onevalue(v82); }
    v82 = stack[0];
    v82 = qcdr(v82);
    stack[0] = v82;
    goto v17;

v77:
    v82 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v82); }
/* error exit handlers */
v9:
    popv(2);
    return nil;
}



/* Code for gcdf1 */

static Lisp_Object CC_gcdf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */
    v143 = stack[-2];
    if (v143 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v143 = stack[-1];
    if (v143 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v144 = stack[-2];
    v143 = (Lisp_Object)17; /* 1 */
    if (v144 == v143) goto v6;
    v144 = stack[-1];
    v143 = (Lisp_Object)17; /* 1 */
    if (v144 == v143) goto v6;
    v143 = stack[-2];
    if (!consp(v143)) goto v14;
    v143 = stack[-2];
    v143 = qcar(v143);
    if (!consp(v143)) goto v14;
    v143 = stack[-1];
    if (!consp(v143)) goto v72;
    v143 = stack[-1];
    v143 = qcar(v143);
    if (!consp(v143)) goto v72;
    v143 = stack[-2];
    fn = elt(env, 5); /* num!-exponents */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (v143 == nil) goto v54;
    v143 = stack[-1];
    fn = elt(env, 5); /* num!-exponents */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (v143 == nil) goto v54;
    v144 = stack[-2];
    v143 = stack[-1];
    fn = elt(env, 6); /* quotf1 */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (!(v143 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v144 = stack[-1];
    v143 = stack[-2];
    fn = elt(env, 6); /* quotf1 */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (!(v143 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v54:
    v144 = stack[-2];
    v143 = stack[-1];
    fn = elt(env, 7); /* gcdf2 */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[-3] = v143;
    v143 = qvalue(elt(env, 1)); /* !*gcd */
    if (v143 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v144 = qvalue(elt(env, 2)); /* dmode!* */
    v143 = elt(env, 3); /* (!:rd!: !:cr!:) */
    v143 = Lmemq(nil, v144, v143);
    if (!(v143 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v144 = stack[-2];
    v143 = stack[-3];
    fn = elt(env, 6); /* quotf1 */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (v143 == nil) goto v113;
    v144 = stack[-1];
    v143 = stack[-3];
    fn = elt(env, 6); /* quotf1 */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (!(v143 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v113:
    v143 = stack[-2];
    fn = elt(env, 8); /* noncomfp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (!(v143 == nil)) goto v145;
    v143 = stack[-1];
    fn = elt(env, 8); /* noncomfp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (!(v143 == nil)) goto v145;
    stack[0] = elt(env, 4); /* "gcdf failed" */
    v143 = stack[-2];
    fn = elt(env, 9); /* prepf */
    stack[-2] = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v143 = stack[-1];
    fn = elt(env, 9); /* prepf */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v143 = list3(stack[0], stack[-2], v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    fn = elt(env, 10); /* errach */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v44;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v145:
    v143 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v143); }

v72:
    v144 = stack[-1];
    v143 = stack[-2];
    {
        popv(5);
        fn = elt(env, 11); /* gcdfd */
        return (*qfn2(fn))(qenv(fn), v144, v143);
    }

v14:
    v144 = stack[-2];
    v143 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* gcdfd */
        return (*qfn2(fn))(qenv(fn), v144, v143);
    }

v6:
    v143 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v143); }
/* error exit handlers */
v44:
    popv(5);
    return nil;
}



/* Code for mathml */

static Lisp_Object MS_CDECL CC_mathml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 2); /* lex */
    v80 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v7:
    popv(1);
    return nil;
}



/* Code for multi_elem */

static Lisp_Object CC_multi_elem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_elem");
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
    v93 = stack[0];
    v75 = Llength(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    v93 = (Lisp_Object)17; /* 1 */
    if (v75 == v93) goto v96;
    v93 = stack[0];
    v93 = qcar(v93);
    fn = elt(env, 2); /* expression */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    v93 = stack[0];
    v93 = qcdr(v93);
    v93 = CC_multi_elem(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v82;
    goto v63;

v63:
    v93 = nil;
    { popv(2); return onevalue(v93); }

v96:
    v93 = stack[0];
    v93 = qcar(v93);
    fn = elt(env, 2); /* expression */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v82;
    goto v63;
/* error exit handlers */
v82:
    popv(2);
    return nil;
}



/* Code for emtch */

static Lisp_Object CC_emtch(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for emtch");
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
    v49 = stack[0];
    if (!consp(v49)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v49 = stack[0];
    fn = elt(env, 1); /* opmtch */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v12;
    v92 = v49;
    v49 = v92;
    if (v49 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    else { popv(1); return onevalue(v92); }
/* error exit handlers */
v12:
    popv(1);
    return nil;
}



/* Code for mk!*sq */

static Lisp_Object CC_mkHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk*sq");
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
    v116 = v0;
/* end of prologue */
    fn = elt(env, 6); /* expchk */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    stack[0] = v116;
    v116 = stack[0];
    v116 = qcar(v116);
    if (v116 == nil) goto v80;
    v116 = stack[0];
    v116 = qcar(v116);
    if (!(!consp(v116))) goto v2;
    v116 = stack[0];
    v122 = qcdr(v116);
    v116 = (Lisp_Object)17; /* 1 */
    if (!(v122 == v116)) goto v2;
    v116 = stack[0];
    v116 = qcar(v116);
    { popv(3); return onevalue(v116); }

v2:
    v116 = stack[0];
    fn = elt(env, 7); /* kernp */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    if (v116 == nil) goto v59;
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcar(v116);
    v122 = qcar(v116);
    v116 = elt(env, 1); /* list */
    if (!consp(v122)) goto v59;
    v122 = qcar(v122);
    if (!(v122 == v116)) goto v59;
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcar(v116);
    { popv(3); return onevalue(v116); }

v59:
    stack[-1] = elt(env, 2); /* !*sq */
    v116 = qvalue(elt(env, 3)); /* !*resubs */
    if (v116 == nil) goto v97;
    v116 = qvalue(elt(env, 4)); /* !*sqvar!* */
    goto v101;

v101:
    {
        Lisp_Object v70 = stack[-1];
        Lisp_Object v71 = stack[0];
        popv(3);
        return list2star(v70, v71, v116);
    }

v97:
    v116 = qvalue(elt(env, 5)); /* nil */
    v116 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v36;
    goto v101;

v80:
    v116 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v116); }
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for xdegree */

static Lisp_Object CC_xdegree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegree");
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
    v4 = v0;
/* end of prologue */
    fn = elt(env, 1); /* deg!*form */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    errexit();
    v5 = v4;
    v4 = v5;
    if (!(v4 == nil)) return onevalue(v5);
    v4 = (Lisp_Object)1; /* 0 */
    return onevalue(v4);
}



/* Code for boundindp */

static Lisp_Object CC_boundindp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v9, v57, v85;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boundindp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v85 = v8;
    v57 = v0;
/* end of prologue */

v63:
    v58 = v57;
    if (v58 == nil) goto v7;
    v58 = v57;
    v9 = qcar(v58);
    v58 = v85;
    v58 = Lmember(nil, v9, v58);
    if (v58 == nil) goto v75;
    v58 = v57;
    v58 = qcdr(v58);
    v57 = v58;
    goto v63;

v75:
    v58 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v58);

v7:
    v58 = qvalue(elt(env, 1)); /* t */
    return onevalue(v58);
}



/* Code for dp_sum */

static Lisp_Object CC_dp_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v151, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_sum");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */

v17:
    v150 = stack[-1];
    if (v150 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v150 = stack[0];
    if (v150 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v150 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    v150 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    fn = elt(env, 2); /* mo_compare */
    v150 = (*qfn2(fn))(qenv(fn), stack[-2], v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    v145 = v150;
    v151 = v145;
    v150 = (Lisp_Object)17; /* 1 */
    if (v151 == v150) goto v100;
    v151 = v145;
    v150 = (Lisp_Object)-15; /* -1 */
    if (v151 == v150) goto v97;
    v150 = stack[-1];
    fn = elt(env, 3); /* dp_lc */
    stack[-2] = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    v150 = stack[0];
    fn = elt(env, 3); /* dp_lc */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    fn = elt(env, 4); /* bc_sum */
    v150 = (*qfn2(fn))(qenv(fn), stack[-2], v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    stack[-2] = v150;
    v150 = stack[-2];
    fn = elt(env, 5); /* bc_zero!? */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    if (v150 == nil) goto v153;
    v150 = stack[-1];
    v151 = qcdr(v150);
    v150 = stack[0];
    v150 = qcdr(v150);
    stack[-1] = v151;
    stack[0] = v150;
    goto v17;

v153:
    v150 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    fn = elt(env, 6); /* dp_term */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    v150 = stack[-1];
    v151 = qcdr(v150);
    v150 = stack[0];
    v150 = qcdr(v150);
    v150 = CC_dp_sum(env, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    {
        Lisp_Object v24 = stack[-2];
        popv(4);
        return cons(v24, v150);
    }

v97:
    v150 = stack[0];
    stack[-2] = qcar(v150);
    v151 = stack[-1];
    v150 = stack[0];
    v150 = qcdr(v150);
    v150 = CC_dp_sum(env, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    {
        Lisp_Object v25 = stack[-2];
        popv(4);
        return cons(v25, v150);
    }

v100:
    v150 = stack[-1];
    stack[-2] = qcar(v150);
    v150 = stack[-1];
    v151 = qcdr(v150);
    v150 = stack[0];
    v150 = CC_dp_sum(env, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v152;
    {
        Lisp_Object v154 = stack[-2];
        popv(4);
        return cons(v154, v150);
    }
/* error exit handlers */
v152:
    popv(4);
    return nil;
}



/* Code for gcdf!* */

static Lisp_Object CC_gcdfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf*");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v6 = v8;
    v88 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v5 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v5; /* !*gcd */
    v5 = v88;
    fn = elt(env, 3); /* gcdf */
    v5 = (*qfn2(fn))(qenv(fn), v5, v6);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v5); }
/* error exit handlers */
v91:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl_pv");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v35 = v8;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v35;
    v35 = stack[-5];
    if (v35 == nil) goto v2;
    v35 = stack[-5];
    v35 = qcar(v35);
    v36 = v35;
    stack[0] = qcar(v36);
    v36 = stack[-4];
    v35 = qcdr(v35);
    fn = elt(env, 2); /* pappl0 */
    v35 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v35 = cons(stack[0], v35);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    stack[-2] = v35;
    stack[-3] = v35;
    goto v84;

v84:
    v35 = stack[-5];
    v35 = qcdr(v35);
    stack[-5] = v35;
    v35 = stack[-5];
    if (v35 == nil) goto v52;
    stack[-1] = stack[-2];
    v35 = stack[-5];
    v35 = qcar(v35);
    v36 = v35;
    stack[0] = qcar(v36);
    v36 = stack[-4];
    v35 = qcdr(v35);
    fn = elt(env, 2); /* pappl0 */
    v35 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v35 = cons(stack[0], v35);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v35 = Lrplacd(nil, stack[-1], v35);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v35 = stack[-2];
    v35 = qcdr(v35);
    stack[-2] = v35;
    goto v84;

v52:
    v35 = stack[-3];
    goto v7;

v7:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v35);
    }

v2:
    v35 = qvalue(elt(env, 1)); /* nil */
    goto v7;
/* error exit handlers */
v105:
    popv(7);
    return nil;
}



/* Code for arzerop!: */

static Lisp_Object CC_arzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v63 = v0;
/* end of prologue */
    v63 = qcdr(v63);
    v63 = (v63 == nil ? lisp_true : nil);
    return onevalue(v63);
}



/* Code for general!-plus!-mod!-p */

static Lisp_Object CC_generalKplusKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-plus-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v8;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v96;

v96:
    v168 = stack[-3];
    if (v168 == nil) goto v2;
    v168 = stack[-2];
    if (v168 == nil) goto v65;
    v168 = stack[-3];
    if (!consp(v168)) goto v82;
    v168 = stack[-3];
    v168 = qcar(v168);
    if (!consp(v168)) goto v82;
    v168 = stack[-2];
    if (!consp(v168)) goto v105;
    v168 = stack[-2];
    v168 = qcar(v168);
    if (!consp(v168)) goto v105;
    v168 = stack[-3];
    v168 = qcar(v168);
    v169 = qcar(v168);
    v168 = stack[-2];
    v168 = qcar(v168);
    v168 = qcar(v168);
    if (equal(v169, v168)) goto v118;
    v168 = stack[-3];
    v168 = qcar(v168);
    v168 = qcar(v168);
    v169 = qcar(v168);
    v168 = stack[-2];
    v168 = qcar(v168);
    v168 = qcar(v168);
    v168 = qcar(v168);
    if (!(equal(v169, v168))) goto v170;
    v168 = stack[-3];
    v168 = qcar(v168);
    v168 = qcar(v168);
    v169 = qcdr(v168);
    v168 = stack[-2];
    v168 = qcar(v168);
    v168 = qcar(v168);
    v168 = qcdr(v168);
    if (!(((int32_t)(v169)) > ((int32_t)(v168)))) goto v170;

v171:
    v168 = stack[-3];
    v169 = qcar(v168);
    v168 = stack[0];
    v168 = cons(v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    stack[0] = v168;
    v168 = stack[-3];
    v168 = qcdr(v168);
    stack[-3] = v168;
    goto v96;

v170:
    v168 = stack[-3];
    v168 = qcar(v168);
    v168 = qcar(v168);
    v169 = qcar(v168);
    v168 = stack[-2];
    v168 = qcar(v168);
    v168 = qcar(v168);
    v168 = qcar(v168);
    if (equal(v169, v168)) goto v173;
    v168 = stack[-3];
    v168 = qcar(v168);
    v168 = qcar(v168);
    v169 = qcar(v168);
    v168 = stack[-2];
    v168 = qcar(v168);
    v168 = qcar(v168);
    v168 = qcar(v168);
    fn = elt(env, 1); /* ordop */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    if (!(v168 == nil)) goto v171;

v173:
    v168 = stack[-2];
    v169 = qcar(v168);
    v168 = stack[0];
    v168 = cons(v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    stack[0] = v168;
    v168 = stack[-2];
    v168 = qcdr(v168);
    stack[-2] = v168;
    goto v96;

v118:
    stack[-4] = stack[0];
    v168 = stack[-3];
    v168 = qcar(v168);
    stack[-1] = qcar(v168);
    v168 = stack[-3];
    v168 = qcar(v168);
    v169 = qcdr(v168);
    v168 = stack[-2];
    v168 = qcar(v168);
    v168 = qcdr(v168);
    stack[0] = CC_generalKplusKmodKp(env, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    v168 = stack[-3];
    v169 = qcdr(v168);
    v168 = stack[-2];
    v168 = qcdr(v168);
    v168 = CC_generalKplusKmodKp(env, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    fn = elt(env, 2); /* adjoin!-term */
    v168 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    {
        Lisp_Object v174 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v174, v168);
    }

v105:
    v168 = stack[-3];
    v169 = qcar(v168);
    v168 = stack[0];
    v168 = cons(v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    stack[0] = v168;
    v168 = stack[-3];
    v168 = qcdr(v168);
    stack[-3] = v168;
    goto v96;

v82:
    v168 = stack[-2];
    if (!consp(v168)) goto v61;
    v168 = stack[-2];
    v168 = qcar(v168);
    if (!consp(v168)) goto v61;
    v168 = stack[-2];
    v169 = qcar(v168);
    v168 = stack[0];
    v168 = cons(v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    stack[0] = v168;
    v168 = stack[-2];
    v168 = qcdr(v168);
    stack[-2] = v168;
    goto v96;

v61:
    v169 = stack[-3];
    v168 = stack[-2];
    fn = elt(env, 4); /* general!-modular!-plus */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    fn = elt(env, 5); /* !*n2f */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    {
        Lisp_Object v175 = stack[0];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v175, v168);
    }

v65:
    v169 = stack[0];
    v168 = stack[-3];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v169, v168);
    }

v2:
    v169 = stack[0];
    v168 = stack[-2];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v169, v168);
    }
/* error exit handlers */
v172:
    popv(6);
    return nil;
}



/* Code for rl_smcpknowl */

static Lisp_Object CC_rl_smcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smcpknowl");
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
    v3 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smcpknowl!* */
    v3 = ncons(v3);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    {
        Lisp_Object v4 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v4, v3);
    }
/* error exit handlers */
v2:
    popv(2);
    return nil;
}



/* Code for subs2f1 */

static Lisp_Object CC_subs2f1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v238, v239, v240, v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2f1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0;
/* end of prologue */
    v237 = stack[-7];
    if (!consp(v237)) goto v77;
    v237 = stack[-7];
    v237 = qcar(v237);
    if (!consp(v237)) goto v77;
    stack[-3] = nil;
    v237 = stack[-7];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v237 = qcar(v237);
    stack[-8] = v237;
    v238 = qvalue(elt(env, 1)); /* nil */
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-2] = v237;
    goto v92;

v92:
    v237 = stack[-7];
    if (v237 == nil) goto v65;
    v238 = stack[-7];
    v237 = stack[-8];
    fn = elt(env, 11); /* degr */
    v238 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = (Lisp_Object)1; /* 0 */
    if (v238 == v237) goto v65;
    v237 = stack[-7];
    v238 = qcar(v237);
    v237 = stack[-3];
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-3] = v237;
    v237 = stack[-7];
    v237 = qcdr(v237);
    stack[-7] = v237;
    goto v92;

v65:
    v237 = qvalue(elt(env, 2)); /* powlis!* */
    stack[-4] = v237;
    goto v12;

v12:
    v237 = stack[-4];
    if (v237 == nil) goto v89;
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v238 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcar(v237);
    if (equal(v238, v237)) goto v114;
    v238 = stack[-8];
    v237 = elt(env, 3); /* expt */
    if (!consp(v238)) goto v71;
    v238 = qcar(v238);
    if (!(v238 == v237)) goto v71;
    v237 = stack[-8];
    v237 = qcdr(v237);
    v238 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcar(v237);
    if (!(equal(v238, v237))) goto v71;
    v237 = stack[-8];
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v238 = qcar(v237);
    v237 = elt(env, 4); /* quotient */
    if (!consp(v238)) goto v71;
    v238 = qcar(v238);
    if (!(v238 == v237)) goto v71;
    v237 = stack[-8];
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v238 = qcar(v237);
    v237 = (Lisp_Object)17; /* 1 */
    if (!(v238 == v237)) goto v71;
    v237 = stack[-8];
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    if (!(is_number(v237))) goto v71;
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v238 = qcdr(v237);
    v237 = stack[-8];
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v237 = Ldivide(nil, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-6] = v237;
    v237 = stack[-6];
    v238 = qcar(v237);
    v237 = (Lisp_Object)1; /* 0 */
    if (v238 == v237) goto v243;
    v237 = stack[-8];
    v237 = qcdr(v237);
    v237 = qcar(v237);
    fn = elt(env, 12); /* simp */
    v238 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-6];
    v237 = qcar(v237);
    fn = elt(env, 13); /* exptsq */
    v237 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-5] = v237;
    goto v156;

v156:
    v237 = stack[-6];
    v238 = qcdr(v237);
    v237 = (Lisp_Object)1; /* 0 */
    if (v238 == v237) goto v244;
    stack[-1] = qvalue(elt(env, 5)); /* alglist!* */
    qvalue(elt(env, 5)) = nil; /* alglist!* */
    stack[0] = qvalue(elt(env, 6)); /* dmode!* */
    qvalue(elt(env, 6)) = nil; /* dmode!* */
    v237 = qvalue(elt(env, 1)); /* nil */
    v237 = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    qvalue(elt(env, 5)) = v237; /* alglist!* */
    v237 = stack[-6];
    v238 = qcdr(v237);
    v237 = stack[-8];
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    fn = elt(env, 14); /* cancel */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    stack[-6] = v237;
    qvalue(elt(env, 6)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 5)) = stack[-1]; /* alglist!* */
    v237 = stack[-8];
    v237 = qcdr(v237);
    v238 = qcar(v237);
    v237 = stack[-6];
    v237 = qcar(v237);
    v239 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v238 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    fn = elt(env, 15); /* subs2p */
    v238 = (*qfnn(fn))(qenv(fn), 3, v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-6];
    v237 = qcdr(v237);
    fn = elt(env, 16); /* raddsq */
    v238 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-5];
    fn = elt(env, 17); /* multsq */
    v237 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-5] = v237;
    goto v244;

v244:
    stack[0] = stack[-5];
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = CC_subs2f1(env, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    fn = elt(env, 17); /* multsq */
    v238 = (*qfn2(fn))(qenv(fn), stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-2];
    fn = elt(env, 18); /* addsq */
    v237 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-2] = v237;
    goto v75;

v75:
    v237 = stack[-3];
    v237 = qcdr(v237);
    stack[-3] = v237;
    v237 = stack[-3];
    if (!(v237 == nil)) goto v65;

v76:
    v237 = stack[-7];
    v237 = CC_subs2f1(env, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-3] = v237;
    v237 = qvalue(elt(env, 9)); /* !*exp */
    if (!(v237 == nil)) goto v246;
    v237 = stack[-3];
    v237 = qcar(v237);
    fn = elt(env, 19); /* mkprod */
    stack[0] = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-3];
    v237 = qcdr(v237);
    fn = elt(env, 19); /* mkprod */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = cons(stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-3] = v237;
    goto v246;

v246:
    v238 = stack[-2];
    v237 = stack[-3];
    {
        popv(10);
        fn = elt(env, 18); /* addsq */
        return (*qfn2(fn))(qenv(fn), v238, v237);
    }

v243:
    v238 = (Lisp_Object)17; /* 1 */
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-5] = v237;
    goto v156;

v71:
    v237 = stack[-4];
    v237 = qcdr(v237);
    stack[-4] = v237;
    goto v12;

v114:
    v237 = stack[-3];
    v237 = qcar(v237);
    v239 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v238 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    fn = elt(env, 15); /* subs2p */
    v237 = (*qfnn(fn))(qenv(fn), 3, v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-5] = v237;
    goto v244;

v89:
    v237 = qvalue(elt(env, 7)); /* powlis1!* */
    stack[-4] = v237;
    goto v90;

v90:
    v237 = stack[-4];
    if (v237 == nil) goto v247;
    v237 = stack[-3];
    v237 = qcar(v237);
    v241 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v240 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v239 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v238 = qcar(v237);
    v237 = stack[-4];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v237 = qcdr(v237);
    fn = elt(env, 20); /* mtchp */
    v237 = (*qfnn(fn))(qenv(fn), 5, v241, v240, v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-5] = v237;
    if (!(v237 == nil)) goto v244;
    v237 = stack[-4];
    v237 = qcdr(v237);
    stack[-4] = v237;
    goto v90;

v247:
    v238 = stack[-8];
    v237 = elt(env, 3); /* expt */
    if (!consp(v238)) goto v248;
    v238 = qcar(v238);
    if (!(v238 == v237)) goto v248;
    v237 = qvalue(elt(env, 8)); /* !*structure */
    if (!(v237 == nil)) goto v248;

v249:
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v238 = qcdr(v237);
    v237 = (Lisp_Object)17; /* 1 */
    if (!(v238 == v237)) goto v250;
    v237 = stack[-8];
    v237 = qcdr(v237);
    v238 = qcar(v237);
    v237 = elt(env, 3); /* expt */
    if (!consp(v238)) goto v251;
    v238 = qcar(v238);
    if (!(v238 == v237)) goto v251;

v250:
    v237 = stack[-8];
    v237 = qcdr(v237);
    stack[0] = qcar(v237);
    v239 = elt(env, 10); /* times */
    v237 = stack[-8];
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v238 = qcar(v237);
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = list3(v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = list2(stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    fn = elt(env, 21); /* simpexpt */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-5] = v237;
    goto v252;

v252:
    stack[0] = stack[-5];
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = CC_subs2f1(env, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    fn = elt(env, 17); /* multsq */
    v238 = (*qfn2(fn))(qenv(fn), stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-2];
    fn = elt(env, 18); /* addsq */
    v237 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-2] = v237;
    v237 = stack[-3];
    v237 = qcdr(v237);
    stack[-3] = v237;
    v237 = stack[-3];
    if (v237 == nil) goto v76;
    else goto v249;

v251:
    v238 = stack[-8];
    v237 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 22); /* mksq */
    v237 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-5] = v237;
    goto v252;

v248:
    v237 = stack[-3];
    v237 = qcar(v237);
    v238 = qcar(v237);
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v238 = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = CC_subs2f1(env, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    fn = elt(env, 17); /* multsq */
    v238 = (*qfn2(fn))(qenv(fn), stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    v237 = stack[-2];
    fn = elt(env, 18); /* addsq */
    v237 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-9];
    stack[-2] = v237;
    goto v75;

v77:
    v237 = stack[-7];
    {
        popv(10);
        fn = elt(env, 23); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v237);
    }
/* error exit handlers */
v245:
    env = stack[-9];
    qvalue(elt(env, 6)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 5)) = stack[-1]; /* alglist!* */
    popv(10);
    return nil;
v242:
    popv(10);
    return nil;
}



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retattributes");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */

v17:
    v95 = stack[0];
    if (v95 == nil) goto v80;
    v110 = stack[-1];
    v95 = stack[0];
    v95 = qcar(v95);
    fn = elt(env, 2); /* find */
    v95 = (*qfn2(fn))(qenv(fn), v110, v95);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v110 = v95;
    if (v110 == nil) goto v60;
    v110 = stack[0];
    v110 = qcar(v110);
    stack[-2] = list2(v110, v95);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v110 = stack[-1];
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = CC_retattributes(env, v110, v95);
    nil = C_nil;
    if (exception_pending()) goto v97;
    {
        Lisp_Object v68 = stack[-2];
        popv(4);
        return cons(v68, v95);
    }

v60:
    v110 = stack[-1];
    v95 = stack[0];
    v95 = qcdr(v95);
    stack[-1] = v110;
    stack[0] = v95;
    goto v17;

v80:
    v95 = nil;
    { popv(4); return onevalue(v95); }
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for errorp */

static Lisp_Object CC_errorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for errorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v84 = v0;
/* end of prologue */
    v81 = v84;
    v81 = (consp(v81) ? nil : lisp_true);
    if (!(v81 == nil)) return onevalue(v81);
    v84 = qcdr(v84);
    return onevalue(v84);
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retimes1");
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
    goto v63;

v63:
    v253 = stack[0];
    if (v253 == nil) goto v7;
    v253 = stack[0];
    v146 = qcar(v253);
    v253 = (Lisp_Object)17; /* 1 */
    if (v146 == v253) goto v2;
    v253 = stack[0];
    v253 = qcar(v253);
    v253 = Lminusp(nil, v253);
    env = stack[-2];
    if (v253 == nil) goto v89;
    v253 = qvalue(elt(env, 1)); /* !*bool */
    v253 = (v253 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v253; /* !*bool */
    v253 = stack[0];
    v253 = qcar(v253);
    v146 = negate(v253);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v253 = stack[0];
    v253 = qcdr(v253);
    v253 = cons(v146, v253);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[0] = v253;
    goto v63;

v89:
    v253 = stack[0];
    v253 = qcar(v253);
    if (!consp(v253)) goto v98;
    v253 = stack[0];
    v253 = qcar(v253);
    v146 = qcar(v253);
    v253 = elt(env, 2); /* minus */
    if (v146 == v253) goto v72;
    v253 = stack[0];
    v253 = qcar(v253);
    v146 = qcar(v253);
    v253 = elt(env, 3); /* times */
    if (v146 == v253) goto v79;
    v253 = stack[0];
    v146 = qcar(v253);
    v253 = stack[-1];
    v253 = cons(v146, v253);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v253;
    v253 = stack[0];
    v253 = qcdr(v253);
    stack[0] = v253;
    goto v63;

v79:
    v253 = stack[0];
    v253 = qcar(v253);
    v146 = qcdr(v253);
    v253 = stack[0];
    v253 = qcdr(v253);
    v253 = Lappend(nil, v146, v253);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[0] = v253;
    goto v63;

v72:
    v253 = qvalue(elt(env, 1)); /* !*bool */
    v253 = (v253 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v253; /* !*bool */
    v253 = stack[0];
    v253 = qcar(v253);
    v253 = qcdr(v253);
    v146 = qcar(v253);
    v253 = stack[0];
    v253 = qcdr(v253);
    v253 = cons(v146, v253);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[0] = v253;
    goto v63;

v98:
    v253 = stack[0];
    v146 = qcar(v253);
    v253 = stack[-1];
    v253 = cons(v146, v253);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v253;
    v253 = stack[0];
    v253 = qcdr(v253);
    stack[0] = v253;
    goto v63;

v2:
    v253 = stack[0];
    v253 = qcdr(v253);
    stack[0] = v253;
    goto v63;

v7:
    v253 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v253);
    }
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v14, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcsum");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v52 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v52 == nil) goto v92;
    v14 = stack[-1];
    v52 = stack[0];
    v52 = plus2(v14, v52);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v52);
    }

v92:
    v74 = stack[-1];
    v14 = stack[0];
    v52 = elt(env, 2); /* plus2 */
    fn = elt(env, 4); /* bcint2op */
    v52 = (*qfnn(fn))(qenv(fn), 3, v74, v14, v52);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    if (!(v52 == nil)) { popv(3); return onevalue(v52); }
    v14 = stack[-1];
    v52 = stack[0];
    fn = elt(env, 5); /* addsq */
    v52 = (*qfn2(fn))(qenv(fn), v14, v52);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsetsugar");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v58 = v8;
    stack[-1] = v0;
/* end of prologue */
    v82 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v82 == nil) goto v7;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 3); /* sugar */
    v82 = v58;
    if (!(v82 == nil)) goto v64;
    v82 = stack[-1];
    fn = elt(env, 4); /* vdptdeg */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    goto v64;

v64:
    fn = elt(env, 5); /* vdpputprop */
    v82 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v82);
    nil = C_nil;
    if (exception_pending()) goto v10;
    goto v80;

v80:
    if (v82 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v82); }

v7:
    v82 = qvalue(elt(env, 2)); /* nil */
    goto v80;
/* error exit handlers */
v10:
    popv(4);
    return nil;
}



/* Code for deg!*form */

static Lisp_Object CC_degHform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v258, v259;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*form");
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

v17:
    v171 = stack[0];
    if (!consp(v171)) goto v7;
    v171 = stack[0];
    v171 = qcar(v171);
    v259 = v171;
    v258 = v259;
    v171 = elt(env, 3); /* indexvar */
    v171 = Lflagp(nil, v258, v171);
    env = stack[-2];
    if (v171 == nil) goto v122;
    v171 = stack[0];
    v171 = qcdr(v171);
    v259 = Llength(nil, v171);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    v171 = stack[0];
    v258 = qcar(v171);
    v171 = elt(env, 4); /* ifdegree */
    v171 = get(v258, v171);
    env = stack[-2];
    v171 = Lassoc(nil, v259, v171);
    v258 = v171;
    v171 = v258;
    if (v171 == nil) goto v97;
    v171 = v258;
    v171 = qcdr(v171);
    { popv(3); return onevalue(v171); }

v97:
    v171 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v171); }

v122:
    v258 = v259;
    v171 = elt(env, 5); /* wedge */
    if (v258 == v171) goto v111;
    v258 = v259;
    v171 = elt(env, 6); /* d */
    if (v258 == v171) goto v78;
    v258 = v259;
    v171 = elt(env, 7); /* hodge */
    if (v258 == v171) goto v165;
    v258 = v259;
    v171 = elt(env, 9); /* partdf */
    if (v258 == v171) goto v147;
    v258 = v259;
    v171 = elt(env, 10); /* liedf */
    if (v258 == v171) goto v24;
    v258 = v259;
    v171 = elt(env, 11); /* innerprod */
    if (v258 == v171) goto v260;
    v258 = v259;
    v171 = elt(env, 12); /* (plus minus difference quotient) */
    v171 = Lmemq(nil, v258, v171);
    if (v171 == nil) goto v261;
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcar(v171);
    stack[0] = v171;
    goto v17;

v261:
    v258 = v259;
    v171 = elt(env, 13); /* times */
    if (v258 == v171) goto v262;
    v171 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v171); }

v262:
    v171 = stack[0];
    v171 = qcdr(v171);
    {
        popv(3);
        fn = elt(env, 14); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v171);
    }

v260:
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcdr(v171);
    v171 = qcar(v171);
    v171 = CC_degHform(env, v171);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    {
        Lisp_Object v157 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* addd */
        return (*qfn2(fn))(qenv(fn), v157, v171);
    }

v24:
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcdr(v171);
    v171 = qcar(v171);
    stack[0] = v171;
    goto v17;

v147:
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcdr(v171);
    if (v171 == nil) goto v129;
    v171 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v171); }

v129:
    v171 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v171); }

v165:
    stack[-1] = qvalue(elt(env, 8)); /* dimex!* */
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcar(v171);
    v171 = CC_degHform(env, v171);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    fn = elt(env, 16); /* negf */
    v171 = (*qfn1(fn))(qenv(fn), v171);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    {
        Lisp_Object v158 = stack[-1];
        popv(3);
        fn = elt(env, 17); /* addf */
        return (*qfn2(fn))(qenv(fn), v158, v171);
    }

v78:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcar(v171);
    v171 = CC_degHform(env, v171);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    {
        Lisp_Object v263 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* addd */
        return (*qfn2(fn))(qenv(fn), v263, v171);
    }

v111:
    v171 = stack[0];
    v171 = qcdr(v171);
    {
        popv(3);
        fn = elt(env, 14); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v171);
    }

v7:
    v258 = stack[0];
    v171 = elt(env, 1); /* fdegree */
    v171 = get(v258, v171);
    env = stack[-2];
    v258 = v171;
    v171 = v258;
    if (v171 == nil) goto v92;
    v171 = v258;
    v171 = qcar(v171);
    { popv(3); return onevalue(v171); }

v92:
    v171 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v171); }
/* error exit handlers */
v231:
    popv(3);
    return nil;
}



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v109, v112, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :difference");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v8;
    v59 = v0;
/* end of prologue */
    v40 = v59;
    if (v40 == nil) goto v63;
    v40 = v112;
    if (v40 == nil) return onevalue(v59);
    v109 = v59;
    v40 = v112;
    if (equal(v109, v40)) goto v4;
    v40 = v59;
    if (!(!consp(v40))) goto v100;
    v40 = v112;
    if (!(!consp(v40))) goto v100;
    v40 = v59;
    v109 = v112;
    return difference2(v40, v109);

v100:
    v109 = v59;
    v40 = elt(env, 2); /* difference */
    {
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v109, v112, v40);
    }

v4:
    v40 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v40);

v63:
    v40 = v112;
    {
        fn = elt(env, 4); /* !:minus */
        return (*qfn1(fn))(qenv(fn), v40);
    }
}



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v108, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecopp");
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
    v108 = v0;
/* end of prologue */
    v101 = v108;
    if (symbolp(v101)) goto v91;
    v101 = qvalue(elt(env, 1)); /* nil */
    goto v96;

v96:
    if (!(v101 == nil)) { popv(1); return onevalue(v101); }
    v101 = v108;
    if (!consp(v101)) goto v76;
    v101 = v108;
    v73 = qcar(v101);
    v101 = elt(env, 2); /* phystype */
    v73 = get(v73, v101);
    env = stack[0];
    v101 = elt(env, 3); /* vector */
    if (v73 == v101) goto v109;
    v101 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v101); }

v109:
    v101 = v108;
    v101 = qcdr(v101);
    v101 = qcar(v101);
    fn = elt(env, 4); /* isanindex */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v101 = (v101 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v101); }

v76:
    v101 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v101); }

v91:
    v73 = v108;
    v101 = elt(env, 2); /* phystype */
    v73 = get(v73, v101);
    env = stack[0];
    v101 = elt(env, 3); /* vector */
    v101 = (v73 == v101 ? lisp_true : nil);
    goto v96;
/* error exit handlers */
v50:
    popv(1);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v91 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v64 = stack[-1];
    v91 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v91 = (*qfn2(fn))(qenv(fn), v64, v91);
    nil = C_nil;
    if (exception_pending()) goto v65;
    {
        Lisp_Object v12 = stack[-2];
        popv(4);
        return cons(v12, v91);
    }
/* error exit handlers */
v65:
    popv(4);
    return nil;
}



setup_type const u05_setup[] =
{
    {"mkwedge",                 CC_mkwedge,     too_many_1,    wrong_no_1},
    {"negsq",                   CC_negsq,       too_many_1,    wrong_no_1},
    {"noncommutingf",           too_few_2,      CC_noncommutingf,wrong_no_2},
    {"getrtype",                CC_getrtype,    too_many_1,    wrong_no_1},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"mod#",                    CC_modC,        too_many_1,    wrong_no_1},
    {"noncomp*",                CC_noncompH,    too_many_1,    wrong_no_1},
    {"convprec*",               CC_convprecH,   too_many_1,    wrong_no_1},
    {"tayexp-min2",             too_few_2,      CC_tayexpKmin2,wrong_no_2},
    {"ibalp_var-unsatlist",     too_few_2,      CC_ibalp_varKunsatlist,wrong_no_2},
    {"pnthxzz",                 too_few_2,      CC_pnthxzz,    wrong_no_2},
    {"off1",                    CC_off1,        too_many_1,    wrong_no_1},
    {"fast_unchecked_getmatelem",CC_fast_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"smemqlp",                 too_few_2,      CC_smemqlp,    wrong_no_2},
    {"sort",                    too_few_2,      CC_sort,       wrong_no_2},
    {"smemql",                  too_few_2,      CC_smemql,     wrong_no_2},
    {"physopp*",                CC_physoppH,    too_many_1,    wrong_no_1},
    {"red_divtestbe",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_divtestbe},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"removev",                 too_few_2,      CC_removev,    wrong_no_2},
    {"ibalp_emptyclausep",      CC_ibalp_emptyclausep,too_many_1,wrong_no_1},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"bound",                   CC_bound,       too_many_1,    wrong_no_1},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"abs:",                    CC_absT,        too_many_1,    wrong_no_1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"resimp",                  CC_resimp,      too_many_1,    wrong_no_1},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"mkgi",                    too_few_2,      CC_mkgi,       wrong_no_2},
    {"sfto_dcontentf",          CC_sfto_dcontentf,too_many_1,  wrong_no_1},
    {"frvarsof",                too_few_2,      CC_frvarsof,   wrong_no_2},
    {"ibalp_lenisone",          CC_ibalp_lenisone,too_many_1,  wrong_no_1},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"quotematrix",             CC_quotematrix, too_many_1,    wrong_no_1},
    {"algid",                   too_few_2,      CC_algid,      wrong_no_2},
    {"red-char-downcase",       CC_redKcharKdowncase,too_many_1,wrong_no_1},
    {"reval2",                  too_few_2,      CC_reval2,     wrong_no_2},
    {"dp_times_bc",             too_few_2,      CC_dp_times_bc,wrong_no_2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"wulessp",                 too_few_2,      CC_wulessp,    wrong_no_2},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"simpminus",               CC_simpminus,   too_many_1,    wrong_no_1},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"reordsq",                 CC_reordsq,     too_many_1,    wrong_no_1},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"errorset*",               too_few_2,      CC_errorsetH,  wrong_no_2},
    {"free-powerp",             CC_freeKpowerp, too_many_1,    wrong_no_1},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"multi_elem",              CC_multi_elem,  too_many_1,    wrong_no_1},
    {"emtch",                   CC_emtch,       too_many_1,    wrong_no_1},
    {"mk*sq",                   CC_mkHsq,       too_many_1,    wrong_no_1},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"arzerop:",                CC_arzeropT,    too_many_1,    wrong_no_1},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"rl_smcpknowl",            CC_rl_smcpknowl,too_many_1,    wrong_no_1},
    {"subs2f1",                 CC_subs2f1,     too_many_1,    wrong_no_1},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"errorp",                  CC_errorp,      too_many_1,    wrong_no_1},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {NULL, (one_args *)"u05", (two_args *)"1335 4023954 8434426", 0}
};

/* end of generated code */
