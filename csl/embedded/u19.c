
/* $destdir/generated-c\u19.c Machine generated C code */

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


/* Code for ibalp_var!-satlist */

static Lisp_Object CC_ibalp_varKsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-satlist");
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
    stack[-4] = v1;
    v28 = v0;
/* end of prologue */
    stack[-5] = v28;
    goto v30;

v30:
    v28 = stack[-5];
    if (v28 == nil) goto v31;
    v28 = stack[-5];
    v28 = qcar(v28);
    stack[-3] = v28;
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    if (!(v28 == nil)) goto v32;
    v28 = stack[-3];
    v28 = qcar(v28);
    stack[-2] = v28;
    goto v33;

v33:
    v28 = stack[-2];
    if (v28 == nil) goto v34;
    v28 = stack[-2];
    v28 = qcar(v28);
    stack[-1] = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    v28 = sub1(v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v28 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-2];
    v28 = qcdr(v28);
    stack[-2] = v28;
    goto v33;

v34:
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcar(v28);
    stack[-2] = v28;
    goto v36;

v36:
    v28 = stack[-2];
    if (v28 == nil) goto v37;
    v28 = stack[-2];
    v28 = qcar(v28);
    stack[-1] = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    v28 = sub1(v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v28 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-2];
    v28 = qcdr(v28);
    stack[-2] = v28;
    goto v36;

v37:
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    stack[-1] = v28;
    goto v38;

v38:
    v28 = stack[-1];
    if (v28 == nil) goto v39;
    v28 = stack[-1];
    v28 = qcar(v28);
    v29 = v28;
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    stack[0] = qcdr(v29);
    v29 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    fn = elt(env, 4); /* delq */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v38;

v39:
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v29 = qcdr(v28);
    v28 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    goto v32;

v32:
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v29 = stack[-4];
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    v28 = cons(v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-5];
    v28 = qcdr(v28);
    stack[-5] = v28;
    goto v30;

v31:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v28); }
/* error exit handlers */
v35:
    popv(7);
    return nil;
}



/* Code for bvarml */

static Lisp_Object CC_bvarml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bvarml");
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
    v42 = elt(env, 1); /* "<bvar>" */
    fn = elt(env, 5); /* printout */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v42 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 6); /* indent!* */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v42 = stack[0];
    v42 = qcar(v42);
    fn = elt(env, 7); /* expression */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v42 = stack[0];
    v42 = qcdr(v42);
    v43 = qcar(v42);
    v42 = (Lisp_Object)17; /* 1 */
    if (v43 == v42) goto v45;
    v42 = stack[0];
    v42 = qcdr(v42);
    v42 = qcar(v42);
    v42 = ncons(v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    fn = elt(env, 8); /* degreeml */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    goto v45;

v45:
    v42 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 6); /* indent!* */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v42 = elt(env, 4); /* "</bvar>" */
    fn = elt(env, 5); /* printout */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    v42 = nil;
    { popv(2); return onevalue(v42); }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for bcneg */

static Lisp_Object CC_bcneg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcneg");
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
    v42 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v42 == nil) goto v33;
    v43 = stack[0];
    v42 = (Lisp_Object)1; /* 0 */
    v42 = Leqn(nil, v43, v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    if (!(v42 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v43 = qvalue(elt(env, 2)); /* current!-modulus */
    v42 = stack[0];
    v42 = (Lisp_Object)(int32_t)((int32_t)v43 - (int32_t)v42 + TAG_FIXNUM);
    { popv(2); return onevalue(v42); }

v33:
    v42 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* negsq */
        return (*qfn1(fn))(qenv(fn), v42);
    }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for random */

static Lisp_Object CC_random(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random");
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
    v73 = stack[-3];
    if (!(is_number(v73))) goto v41;
    v74 = stack[-3];
    v73 = (Lisp_Object)1; /* 0 */
    v73 = (Lisp_Object)lesseq2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v73 = v73 ? lisp_true : nil;
    env = stack[-5];
    if (!(v73 == nil)) goto v41;

v76:
    v73 = stack[-3];
    v73 = Lfloatp(nil, v73);
    env = stack[-5];
    if (v73 == nil) goto v77;
    fn = elt(env, 5); /* next!-random!-number */
    v73 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v74 = Lfloat(nil, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = qvalue(elt(env, 2)); /* unidev_fac!* */
    v73 = times2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    stack[-2] = v73;
    fn = elt(env, 5); /* next!-random!-number */
    v73 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v74 = Lfloat(nil, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = stack[-2];
    stack[0] = plus2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v74 = qvalue(elt(env, 2)); /* unidev_fac!* */
    v73 = stack[-3];
    v73 = times2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    {
        Lisp_Object v78 = stack[0];
        popv(6);
        return times2(v78, v73);
    }

v77:
    fn = elt(env, 5); /* next!-random!-number */
    v73 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    stack[-2] = v73;
    v73 = qvalue(elt(env, 3)); /* randommodulus!* */
    stack[-4] = v73;
    goto v20;

v20:
    v74 = stack[-4];
    v73 = stack[-3];
    v73 = (Lisp_Object)lessp2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v73 = v73 ? lisp_true : nil;
    env = stack[-5];
    if (v73 == nil) goto v79;
    v74 = stack[-4];
    v73 = qvalue(elt(env, 3)); /* randommodulus!* */
    v73 = times2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    stack[-4] = v73;
    v74 = qvalue(elt(env, 3)); /* randommodulus!* */
    v73 = stack[-2];
    stack[0] = times2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    fn = elt(env, 5); /* next!-random!-number */
    v73 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = plus2(stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    stack[-2] = v73;
    goto v20;

v79:
    stack[-1] = stack[-2];
    stack[0] = stack[-4];
    v74 = stack[-4];
    v73 = stack[-3];
    v73 = Cremainder(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = difference2(stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = (Lisp_Object)lessp2(stack[-1], v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v73 = v73 ? lisp_true : nil;
    env = stack[-5];
    if (v73 == nil) goto v77;
    v74 = stack[-2];
    v73 = stack[-3];
    popv(6);
    return Cremainder(v74, v73);

v41:
    v74 = stack[-3];
    v73 = elt(env, 1); /* "positive number" */
    fn = elt(env, 6); /* typerr */
    v73 = (*qfn2(fn))(qenv(fn), v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    goto v76;
/* error exit handlers */
v75:
    popv(6);
    return nil;
}



/* Code for !*di2q0 */

static Lisp_Object CC_Hdi2q0(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v57)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v56, v14, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *di2q0");
#endif
    if (stack >= stacklimit)
    {
        push2(v57,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v57);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v55 = v57;
    stack[-3] = v1;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v55; /* varlist */
    stack[-2] = nil;
    goto v45;

v45:
    v55 = stack[-3];
    if (v55 == nil) goto v98;
    v55 = stack[-3];
    v55 = qcar(v55);
    stack[-1] = qcdr(v55);
    stack[0] = qvalue(elt(env, 1)); /* varlist */
    v56 = qvalue(elt(env, 2)); /* ordering */
    v55 = elt(env, 3); /* lex */
    if (v56 == v55) goto v99;
    v55 = stack[-3];
    fn = elt(env, 5); /* ljet */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v55 = qcdr(v55);
    goto v100;

v100:
    fn = elt(env, 6); /* pair */
    v55 = (*qfn2(fn))(qenv(fn), stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v97 = stack[-1];
    stack[-1] = v55;
    goto v64;

v64:
    v55 = stack[-1];
    if (v55 == nil) goto v69;
    v55 = stack[-1];
    v55 = qcar(v55);
    v14 = v55;
    v55 = v14;
    v56 = qcdr(v55);
    v55 = (Lisp_Object)1; /* 0 */
    if (v56 == v55) goto v77;
    stack[0] = v97;
    v56 = v14;
    v55 = (Lisp_Object)17; /* 1 */
    v14 = cons(v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v56 = qvalue(elt(env, 4)); /* nil */
    v55 = (Lisp_Object)17; /* 1 */
    v55 = acons(v14, v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    fn = elt(env, 7); /* multsq */
    v55 = (*qfn2(fn))(qenv(fn), stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v97 = v55;
    goto v77;

v77:
    v55 = stack[-1];
    v55 = qcdr(v55);
    stack[-1] = v55;
    goto v64;

v69:
    v56 = v97;
    v55 = stack[-2];
    v55 = cons(v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    stack[-2] = v55;
    v55 = stack[-3];
    v55 = qcdr(v55);
    stack[-3] = v55;
    goto v45;

v99:
    v55 = stack[-3];
    fn = elt(env, 5); /* ljet */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    goto v100;

v98:
    v56 = qvalue(elt(env, 4)); /* nil */
    v55 = (Lisp_Object)17; /* 1 */
    v55 = cons(v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v56 = v55;
    goto v101;

v101:
    v55 = stack[-2];
    if (v55 == nil) goto v102;
    v55 = stack[-2];
    v55 = qcar(v55);
    fn = elt(env, 8); /* addsq */
    v55 = (*qfn2(fn))(qenv(fn), v55, v56);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v56 = v55;
    v55 = stack[-2];
    v55 = qcdr(v55);
    stack[-2] = v55;
    goto v101;

v102:
    v55 = v56;
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    { popv(6); return onevalue(v55); }
/* error exit handlers */
v49:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    popv(6);
    return nil;
}



/* Code for resimpf */

static Lisp_Object CC_resimpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimpf");
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
    v101 = v0;
/* end of prologue */
    v104 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v104; /* varstack!* */
    v104 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subf1 */
    v104 = (*qfn2(fn))(qenv(fn), v101, v104);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v104 = qcar(v104);
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v104); }
/* error exit handlers */
v6:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for ibalp_getupl */

static Lisp_Object CC_ibalp_getupl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v66;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getupl");
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
    v107 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v107;
    goto v84;

v84:
    v107 = stack[-1];
    if (v107 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v107 = stack[-1];
    v107 = qcar(v107);
    stack[0] = v107;
    v107 = stack[0];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    if (!(v107 == nil)) goto v72;
    v107 = stack[0];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v66 = qcar(v107);
    v107 = stack[0];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    v66 = plus2(v66, v107);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    v107 = (Lisp_Object)17; /* 1 */
    v107 = Leqn(nil, v66, v107);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    if (v107 == nil) goto v72;
    v66 = stack[0];
    v107 = stack[-2];
    v107 = cons(v66, v107);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    stack[-2] = v107;
    goto v72;

v72:
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    goto v84;
/* error exit handlers */
v91:
    popv(4);
    return nil;
}



/* Code for encodeir */

static Lisp_Object CC_encodeir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v65, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for encodeir");
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
    stack[-1] = qvalue(elt(env, 1)); /* char */
    v65 = elt(env, 2); /* !  */
    v111 = qvalue(elt(env, 3)); /* atts */
    v111 = cons(v65, v111);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v111 = Lappend(nil, stack[-1], v111);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v65 = elt(env, 4); /* !$ */
    fn = elt(env, 7); /* delall */
    v111 = (*qfn2(fn))(qenv(fn), v65, v111);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    stack[-1] = elt(env, 5); /* semantic */
    v106 = stack[0];
    v65 = v111;
    v111 = qvalue(elt(env, 6)); /* nil */
    v111 = list2star(v106, v65, v111);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v65 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v112 = stack[-1];
        popv(3);
        return list2star(v112, v111, v65);
    }
/* error exit handlers */
v86:
    popv(3);
    return nil;
}



/* Code for dip2vdp */

static Lisp_Object CC_dip2vdp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip2vdp");
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
    v116 = v0;
/* end of prologue */
    v67 = qvalue(elt(env, 1)); /* !*groebsubs */
    if (v67 == nil) goto v83;
    v67 = v116;
    fn = elt(env, 4); /* dipsubs2 */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-3];
    goto v27;

v27:
    v116 = v67;
    v67 = v116;
    if (v67 == nil) goto v71;
    stack[-2] = elt(env, 2); /* vdp */
    v67 = v116;
    stack[-1] = qcar(v67);
    v67 = v116;
    v67 = qcdr(v67);
    stack[0] = qcar(v67);
    v67 = qvalue(elt(env, 3)); /* nil */
    v67 = list2(v116, v67);
    nil = C_nil;
    if (exception_pending()) goto v77;
    {
        Lisp_Object v117 = stack[-2];
        Lisp_Object v118 = stack[-1];
        Lisp_Object v119 = stack[0];
        popv(4);
        return list3star(v117, v118, v119, v67);
    }

v71:
    stack[-2] = elt(env, 2); /* vdp */
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v67 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 5); /* a2bc */
    stack[0] = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-3];
    v116 = qvalue(elt(env, 3)); /* nil */
    v67 = qvalue(elt(env, 3)); /* nil */
    v67 = list2(v116, v67);
    nil = C_nil;
    if (exception_pending()) goto v77;
    {
        Lisp_Object v120 = stack[-2];
        Lisp_Object v121 = stack[-1];
        Lisp_Object v21 = stack[0];
        popv(4);
        return list3star(v120, v121, v21, v67);
    }

v83:
    v67 = v116;
    goto v27;
/* error exit handlers */
v77:
    popv(4);
    return nil;
}



/* Code for lispassignp */

static Lisp_Object CC_lispassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v103 = elt(env, 1); /* setq */
        return Leqcar(nil, v31, v103);
}



/* Code for all_defined_vertex */

static Lisp_Object CC_all_defined_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v48, v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v1;
    v48 = v0;
/* end of prologue */
    v72 = v48;
    v71 = qvalue(elt(env, 1)); /* nil */
    v48 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_vertex */
        return (*qfnn(fn))(qenv(fn), 4, v72, v71, v48, v47);
    }
}



/* Code for fieldconv */

static Lisp_Object CC_fieldconv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v2, v3;
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
    v147 = stack[-1];
    v147 = qcar(v147);
    stack[-3] = v147;
    v147 = stack[-1];
    v147 = qcdr(v147);
    stack[0] = v147;
    v147 = qvalue(elt(env, 1)); /* dmode!* */
    if (v147 == nil) goto v41;
    v147 = stack[0];
    if (!consp(v147)) goto v148;
    v147 = stack[0];
    v147 = qcar(v147);
    if (!consp(v147)) goto v148;
    v2 = stack[-3];
    v147 = stack[-2];
    fn = elt(env, 5); /* divd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v2 = stack[0];
    v147 = stack[-2];
    fn = elt(env, 5); /* divd */
    v147 = (*qfn2(fn))(qenv(fn), v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    {
        Lisp_Object v4 = stack[-1];
        popv(5);
        return cons(v4, v147);
    }

v148:
    v2 = stack[-3];
    v147 = stack[0];
    fn = elt(env, 5); /* divd */
    v2 = (*qfn2(fn))(qenv(fn), v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v147 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v2, v147);

v41:
    v2 = stack[-2];
    v147 = elt(env, 2); /* !:rn!: */
    if (!consp(v2)) goto v43;
    v2 = qcar(v2);
    if (!(v2 == v147)) goto v43;

v60:
    v147 = stack[-2];
    v3 = qcar(v147);
    v147 = stack[-2];
    v147 = qcdr(v147);
    v2 = qcdr(v147);
    v147 = stack[-2];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    v147 = list2star(v3, v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    stack[-2] = v147;
    v147 = stack[0];
    if (!consp(v147)) goto v38;
    v147 = stack[0];
    v147 = qcar(v147);
    if (!consp(v147)) goto v38;
    v2 = stack[-2];
    v147 = stack[-3];
    fn = elt(env, 6); /* multd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v2 = stack[-2];
    v147 = stack[0];
    fn = elt(env, 6); /* multd */
    v147 = (*qfn2(fn))(qenv(fn), v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v147 = cons(stack[-1], v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    goto v150;

v150:
    {
        popv(5);
        fn = elt(env, 7); /* simpgd */
        return (*qfn1(fn))(qenv(fn), v147);
    }

v38:
    v2 = stack[-2];
    v147 = stack[-3];
    fn = elt(env, 6); /* multd */
    v2 = (*qfn2(fn))(qenv(fn), v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v147 = (Lisp_Object)17; /* 1 */
    v147 = cons(v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    goto v150;

v43:
    v147 = stack[-2];
    v2 = qcar(v147);
    v147 = elt(env, 2); /* !:rn!: */
    v147 = get(v2, v147);
    env = stack[-4];
    v2 = v147;
    if (v147 == nil) goto v68;
    v147 = v2;
    if (!(!consp(v147))) goto v68;
    v147 = stack[-2];
    v147 = Lapply1(nil, v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    stack[-2] = v147;
    goto v60;

v68:
    v147 = stack[-2];
    v2 = qcar(v147);
    v147 = elt(env, 3); /* quotient */
    v147 = get(v2, v147);
    env = stack[-4];
    if (v147 == nil) goto v90;
    v3 = (Lisp_Object)17; /* 1 */
    v2 = stack[-2];
    v147 = elt(env, 3); /* quotient */
    fn = elt(env, 8); /* dcombine */
    v147 = (*qfnn(fn))(qenv(fn), 3, v3, v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    stack[-2] = v147;
    v2 = stack[-2];
    v147 = stack[-1];
    v147 = qcar(v147);
    fn = elt(env, 6); /* multd */
    stack[0] = (*qfn2(fn))(qenv(fn), v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    v2 = stack[-2];
    v147 = stack[-1];
    v147 = qcdr(v147);
    fn = elt(env, 6); /* multd */
    v147 = (*qfn2(fn))(qenv(fn), v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    {
        Lisp_Object v151 = stack[0];
        popv(5);
        return cons(v151, v147);
    }

v90:
    v2 = elt(env, 4); /* "field conversion" */
    v147 = stack[-2];
    v147 = list2(v2, v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    fn = elt(env, 9); /* errach */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-4];
    goto v60;
/* error exit handlers */
v149:
    popv(5);
    return nil;
}



/* Code for simpcv */

static Lisp_Object CC_simpcv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpcv");
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
    v121 = stack[-1];
    v21 = Llength(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    v121 = (Lisp_Object)49; /* 3 */
    if (v21 == v121) goto v33;
    v21 = elt(env, 1); /* "Invalid number of edges in vertex" */
    v121 = stack[-1];
    v121 = list2(v21, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* cerror */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v33:
    v21 = elt(env, 2); /* simpcgraph */
    v121 = qvalue(elt(env, 3)); /* mul!* */
    v121 = Lmemq(nil, v21, v121);
    if (!(v121 == nil)) goto v67;
    v21 = qvalue(elt(env, 3)); /* mul!* */
    v121 = elt(env, 2); /* simpcgraph */
    fn = elt(env, 5); /* aconc!* */
    v121 = (*qfn2(fn))(qenv(fn), v21, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    qvalue(elt(env, 3)) = v121; /* mul!* */
    goto v67;

v67:
    v21 = stack[0];
    v121 = stack[-1];
    v21 = cons(v21, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    v121 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* to */
    v21 = (*qfn2(fn))(qenv(fn), v21, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    v121 = (Lisp_Object)17; /* 1 */
    v121 = cons(v21, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    v21 = ncons(v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    v121 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v21, v121);
/* error exit handlers */
v92:
    popv(3);
    return nil;
}



/* Code for ibalp_clmember */

static Lisp_Object CC_ibalp_clmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clmember");
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

v154:
    v114 = stack[0];
    if (v114 == nil) goto v80;
    v100 = stack[-1];
    v114 = stack[0];
    v114 = qcar(v114);
    fn = elt(env, 2); /* ibalp_cequal */
    v114 = (*qfn2(fn))(qenv(fn), v100, v114);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    if (!(v114 == nil)) { popv(3); return onevalue(v114); }
    v100 = stack[-1];
    v114 = stack[0];
    v114 = qcdr(v114);
    stack[-1] = v100;
    stack[0] = v114;
    goto v154;

v80:
    v114 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v114); }
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for row */

static Lisp_Object CC_row(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for row");
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
    v6 = stack[0];
    if (v6 == nil) goto v80;
    v6 = stack[0];
    v6 = qcar(v6);
    fn = elt(env, 2); /* expression */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-1];
    v6 = stack[0];
    v6 = qcdr(v6);
    v6 = CC_row(env, v6);
    nil = C_nil;
    if (exception_pending()) goto v48;
    goto v80;

v80:
    v6 = nil;
    { popv(2); return onevalue(v6); }
/* error exit handlers */
v48:
    popv(2);
    return nil;
}



/* Code for bcfd */

static Lisp_Object CC_bcfd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v95, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcfd");
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
    v109 = v0;
/* end of prologue */
    v96 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v96 == nil) goto v84;
    v96 = v109;
    v96 = integerp(v96);
    if (v96 == nil) goto v40;
    v96 = v109;
    {
        popv(1);
        fn = elt(env, 4); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v96);
    }

v40:
    v96 = v109;
    v95 = qcar(v96);
    v96 = elt(env, 2); /* !:mod!: */
    if (v95 == v96) goto v155;
    v96 = elt(env, 3); /* "Invalid modular coefficient" */
    v95 = v109;
    v96 = list2(v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* rederr */
        return (*qfn1(fn))(qenv(fn), v96);
    }

v155:
    v96 = v109;
    v96 = qcdr(v96);
    {
        popv(1);
        fn = elt(env, 4); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v96);
    }

v84:
    v95 = v109;
    v96 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 6); /* mkbc */
        return (*qfn2(fn))(qenv(fn), v95, v96);
    }
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for freeindexchk */

static Lisp_Object CC_freeindexchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeindexchk");
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
    v48 = v0;
/* end of prologue */
    v47 = v48;
    if (v47 == nil) goto v101;
    v47 = qvalue(elt(env, 1)); /* indxl!* */
    if (v47 == nil) goto v101;
    v47 = v48;
    fn = elt(env, 4); /* indxchk */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[0];
    if (v47 == nil) goto v101;
    v47 = elt(env, 2); /* form!-with!-free!-indices */
    { popv(1); return onevalue(v47); }

v101:
    v47 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v47); }
/* error exit handlers */
v71:
    popv(1);
    return nil;
}



/* Code for equalreval */

static Lisp_Object CC_equalreval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v69, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equalreval");
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
    v113 = stack[-1];
    v113 = qcdr(v113);
    v113 = qcar(v113);
    fn = elt(env, 4); /* reval */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-2] = v113;
    v113 = qvalue(elt(env, 1)); /* !*evallhseqp */
    if (!(v113 == nil)) goto v153;
    v113 = stack[-1];
    v113 = qcar(v113);
    if (!consp(v113)) goto v95;
    v113 = stack[-1];
    v113 = qcar(v113);
    v69 = qcar(v113);
    v113 = elt(env, 2); /* immediate */
    v113 = Lflagp(nil, v69, v113);
    env = stack[-3];
    if (!(v113 == nil)) goto v153;

v95:
    v64 = elt(env, 3); /* equal */
    v113 = stack[-1];
    v69 = qcar(v113);
    v113 = stack[-2];
    popv(4);
    return list3(v64, v69, v113);

v153:
    stack[0] = elt(env, 3); /* equal */
    v113 = stack[-1];
    v113 = qcar(v113);
    fn = elt(env, 4); /* reval */
    v69 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v145;
    v113 = stack[-2];
    {
        Lisp_Object v107 = stack[0];
        popv(4);
        return list3(v107, v69, v113);
    }
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for physopordchk!* */

static Lisp_Object CC_physopordchkH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopordchk*");
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
    stack[-1] = v0;
/* end of prologue */

v154:
    v73 = stack[-1];
    v73 = qcar(v73);
    stack[-4] = v73;
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    v73 = stack[-1];
    if (v73 == nil) goto v101;
    v73 = stack[-4];
    v74 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = stack[0];
    v73 = CC_physopordchkH(env, v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    if (v73 == nil) goto v163;
    v74 = stack[-1];
    v73 = stack[0];
    stack[-1] = v74;
    stack[0] = v73;
    goto v154;

v163:
    v73 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v73); }

v101:
    v73 = stack[0];
    v73 = qcdr(v73);
    if (v73 == nil) goto v46;
    v73 = stack[0];
    stack[-3] = v73;
    v73 = stack[-3];
    if (v73 == nil) goto v164;
    v73 = stack[-3];
    v73 = qcar(v73);
    v74 = stack[-4];
    fn = elt(env, 3); /* ncmpchk */
    v73 = (*qfn2(fn))(qenv(fn), v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    stack[-1] = v73;
    stack[-2] = v73;
    goto v113;

v113:
    v73 = stack[-3];
    v73 = qcdr(v73);
    stack[-3] = v73;
    v73 = stack[-3];
    if (v73 == nil) goto v93;
    stack[0] = stack[-1];
    v73 = stack[-3];
    v73 = qcar(v73);
    v74 = stack[-4];
    fn = elt(env, 3); /* ncmpchk */
    v73 = (*qfn2(fn))(qenv(fn), v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = Lrplacd(nil, stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    goto v113;

v93:
    v73 = stack[-2];
    goto v19;

v19:
    v74 = qvalue(elt(env, 1)); /* nil */
    v73 = Lmember(nil, v74, v73);
    if (v73 == nil) goto v79;
    v73 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v73); }

v79:
    v73 = qvalue(elt(env, 2)); /* t */
    { popv(6); return onevalue(v73); }

v164:
    v73 = qvalue(elt(env, 1)); /* nil */
    goto v19;

v46:
    v74 = stack[-4];
    v73 = stack[0];
    v73 = qcar(v73);
    fn = elt(env, 3); /* ncmpchk */
    v73 = (*qfn2(fn))(qenv(fn), v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    if (v73 == nil) goto v165;
    v73 = stack[-4];
    fn = elt(env, 4); /* invp */
    v74 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v73 = stack[0];
    v73 = qcar(v73);
    v73 = (equal(v74, v73) ? lisp_true : nil);
    v73 = (v73 == nil ? lisp_true : nil);
    { popv(6); return onevalue(v73); }

v165:
    v73 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v73); }
/* error exit handlers */
v75:
    popv(6);
    return nil;
}



/* Code for red!=subst1 */

static Lisp_Object CC_redMsubst1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v148, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=subst1");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v129 = stack[-6];
    fn = elt(env, 5); /* bas_dpoly */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[0] = v129;
    v129 = stack[0];
    fn = elt(env, 6); /* dp_lc */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-1] = v129;
    v129 = stack[-6];
    fn = elt(env, 7); /* bas_rep */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-7] = v129;
    v129 = stack[-5];
    fn = elt(env, 5); /* bas_dpoly */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-3] = v129;
    v129 = stack[-3];
    fn = elt(env, 6); /* dp_lc */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-2] = v129;
    v129 = qvalue(elt(env, 1)); /* !*bcsimp */
    if (v129 == nil) goto v119;
    v129 = stack[-2];
    fn = elt(env, 8); /* bc_inv */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-4] = v129;
    if (v129 == nil) goto v108;
    v148 = stack[-1];
    v129 = stack[-4];
    fn = elt(env, 9); /* bc_prod */
    v129 = (*qfn2(fn))(qenv(fn), v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-1] = v129;
    v129 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* bc_fi */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-2] = v129;
    goto v119;

v119:
    v129 = stack[0];
    fn = elt(env, 11); /* dp_lmon */
    stack[-4] = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = stack[-3];
    fn = elt(env, 11); /* dp_lmon */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    fn = elt(env, 12); /* mo_diff */
    v129 = (*qfn2(fn))(qenv(fn), stack[-4], v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-4] = v129;
    v148 = stack[-2];
    v129 = stack[0];
    fn = elt(env, 13); /* dp_times_bc */
    stack[0] = (*qfn2(fn))(qenv(fn), v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v178 = stack[-1];
    v148 = stack[-4];
    v129 = stack[-3];
    fn = elt(env, 14); /* dp_times_bcmo */
    v129 = (*qfnn(fn))(qenv(fn), 3, v178, v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    fn = elt(env, 15); /* dp_diff */
    v129 = (*qfn2(fn))(qenv(fn), stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[0] = v129;
    v148 = stack[-2];
    v129 = stack[-7];
    fn = elt(env, 13); /* dp_times_bc */
    stack[-2] = (*qfn2(fn))(qenv(fn), v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = stack[-5];
    fn = elt(env, 7); /* bas_rep */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    fn = elt(env, 14); /* dp_times_bcmo */
    v129 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-4], v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    fn = elt(env, 15); /* dp_diff */
    v129 = (*qfn2(fn))(qenv(fn), stack[-2], v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-1] = v129;
    fn = elt(env, 16); /* cali_trace */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = (Lisp_Object)1265; /* 79 */
    v129 = (Lisp_Object)greaterp2(v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    v129 = v129 ? lisp_true : nil;
    env = stack[-8];
    if (v129 == nil) goto v180;
    v129 = elt(env, 2); /* "---> " */
    v129 = Lprinc(nil, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = stack[0];
    fn = elt(env, 17); /* dp_print */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    goto v133;

v133:
    fn = elt(env, 16); /* cali_trace */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = (Lisp_Object)1425; /* 89 */
    v129 = (Lisp_Object)greaterp2(v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    v129 = v129 ? lisp_true : nil;
    env = stack[-8];
    if (v129 == nil) goto v181;
    v129 = elt(env, 4); /* " uses " */
    v129 = Lprinc(nil, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = stack[-3];
    fn = elt(env, 17); /* dp_print */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    goto v181;

v181:
    v129 = stack[-6];
    fn = elt(env, 18); /* bas_nr */
    v178 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v148 = stack[0];
    v129 = stack[-1];
    {
        popv(9);
        fn = elt(env, 19); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v178, v148, v129);
    }

v180:
    fn = elt(env, 16); /* cali_trace */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = (Lisp_Object)1; /* 0 */
    v129 = (Lisp_Object)greaterp2(v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    v129 = v129 ? lisp_true : nil;
    env = stack[-8];
    if (v129 == nil) goto v133;
    v129 = elt(env, 3); /* "." */
    v129 = Lprinc(nil, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    goto v133;

v108:
    v148 = stack[-2];
    v129 = stack[-1];
    fn = elt(env, 20); /* bc_gcd */
    v129 = (*qfn2(fn))(qenv(fn), v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-4] = v129;
    v148 = stack[-2];
    v129 = stack[-4];
    fn = elt(env, 21); /* bc_divmod */
    v129 = (*qfn2(fn))(qenv(fn), v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = qcar(v129);
    stack[-2] = v129;
    v148 = stack[-1];
    v129 = stack[-4];
    fn = elt(env, 21); /* bc_divmod */
    v129 = (*qfn2(fn))(qenv(fn), v148, v129);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v129 = qcar(v129);
    stack[-1] = v129;
    goto v119;
/* error exit handlers */
v179:
    popv(9);
    return nil;
}



/* Code for st_consolidate */

static Lisp_Object CC_st_consolidate(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v184;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_consolidate");
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
    v183 = stack[-3];
    if (v183 == nil) goto v83;
    v183 = stack[-3];
    v183 = qcdr(v183);
    v183 = qcar(v183);
    if (is_number(v183)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v183 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v183;
    v183 = stack[-3];
    v183 = qcdr(v183);
    v183 = Lreverse(nil, v183);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[0] = v183;
    goto v165;

v165:
    v183 = stack[0];
    if (v183 == nil) goto v185;
    v183 = stack[0];
    v183 = qcar(v183);
    v183 = CC_st_consolidate(env, v183);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v184 = v183;
    if (v184 == nil) goto v23;
    v184 = v183;
    v184 = qcdr(v184);
    v184 = qcdr(v184);
    if (v184 == nil) goto v68;
    v184 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v184;
    goto v67;

v67:
    v184 = v183;
    v183 = stack[-1];
    v183 = cons(v184, v183);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-1] = v183;
    goto v23;

v23:
    v183 = stack[0];
    v183 = qcdr(v183);
    stack[0] = v183;
    goto v165;

v68:
    v184 = elt(env, 3); /* !* */
    v183 = qcdr(v183);
    v183 = qcar(v183);
    v183 = list2(v184, v183);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    goto v67;

v185:
    v183 = stack[-1];
    if (v183 == nil) goto v73;
    v183 = stack[-1];
    v183 = qcdr(v183);
    if (v183 == nil) goto v37;
    v183 = stack[-2];
    if (v183 == nil) goto v14;
    v183 = stack[-1];
    stack[-4] = v183;
    v183 = stack[-4];
    if (v183 == nil) goto v58;
    v183 = stack[-4];
    v183 = qcar(v183);
    v183 = qcdr(v183);
    v183 = qcar(v183);
    v183 = ncons(v183);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[-1] = v183;
    stack[-2] = v183;
    goto v186;

v186:
    v183 = stack[-4];
    v183 = qcdr(v183);
    stack[-4] = v183;
    v183 = stack[-4];
    if (v183 == nil) goto v79;
    stack[0] = stack[-1];
    v183 = stack[-4];
    v183 = qcar(v183);
    v183 = qcdr(v183);
    v183 = qcar(v183);
    v183 = ncons(v183);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v183 = Lrplacd(nil, stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v183 = stack[-1];
    v183 = qcdr(v183);
    stack[-1] = v183;
    goto v186;

v79:
    v183 = stack[-2];
    goto v187;

v187:
    stack[-1] = v183;
    goto v14;

v14:
    v183 = stack[-3];
    v184 = qcar(v183);
    v183 = stack[-1];
    popv(6);
    return cons(v184, v183);

v58:
    v183 = qvalue(elt(env, 1)); /* nil */
    goto v187;

v37:
    v183 = stack[-1];
    v183 = qcar(v183);
    { popv(6); return onevalue(v183); }

v73:
    v183 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v183); }

v83:
    v183 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v183); }
/* error exit handlers */
v170:
    popv(6);
    return nil;
}



/* Code for getrmacro */

static Lisp_Object CC_getrmacro(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v108, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrmacro");
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
    v109 = stack[0];
    if (symbolp(v109)) goto v84;
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v109); }

v84:
    v109 = stack[0];
    fn = elt(env, 4); /* getd */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v111 = v109;
    if (v109 == nil) goto v34;
    v109 = v111;
    v108 = qcar(v109);
    v109 = elt(env, 2); /* macro */
    if (v108 == v109) { popv(2); return onevalue(v111); }
    else goto v34;

v34:
    v108 = stack[0];
    v109 = elt(env, 3); /* smacro */
    v109 = get(v108, v109);
    env = stack[-1];
    v111 = v109;
    if (v109 == nil) goto v152;
    v109 = elt(env, 3); /* smacro */
    v108 = v111;
    popv(2);
    return cons(v109, v108);

v152:
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v109); }
/* error exit handlers */
v106:
    popv(2);
    return nil;
}



/* Code for wusort */

static Lisp_Object CC_wusort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wusort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v103 = v31;
    v31 = elt(env, 1); /* wulessp!* */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v103, v31);
    }
}



/* Code for gck2 */

static Lisp_Object CC_gck2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gck2");
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

v80:
    v194 = stack[-1];
    if (v194 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v7 = stack[-2];
    v194 = stack[-1];
    if (equal(v7, v194)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v194 = stack[-2];
    if (!consp(v194)) goto v41;
    v194 = stack[-2];
    v194 = qcar(v194);
    if (!consp(v194)) goto v41;
    v194 = stack[-1];
    if (!consp(v194)) goto v60;
    v194 = stack[-1];
    v194 = qcar(v194);
    if (!consp(v194)) goto v60;
    v194 = stack[-2];
    v194 = qcar(v194);
    v7 = qcar(v194);
    v194 = stack[-1];
    v194 = qcar(v194);
    v194 = qcar(v194);
    stack[-3] = v7;
    stack[0] = v194;
    v194 = stack[-3];
    v7 = qcar(v194);
    v194 = stack[0];
    v194 = qcar(v194);
    if (v7 == v194) goto v75;
    v194 = stack[-3];
    v7 = qcar(v194);
    v194 = stack[0];
    v194 = qcar(v194);
    fn = elt(env, 4); /* ordop */
    v194 = (*qfn2(fn))(qenv(fn), v7, v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-4];
    if (v194 == nil) goto v196;
    v194 = stack[-2];
    fn = elt(env, 5); /* cdarx */
    v7 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-4];
    v194 = stack[-1];
    stack[-2] = v7;
    stack[-1] = v194;
    goto v80;

v196:
    stack[0] = stack[-2];
    v194 = stack[-1];
    fn = elt(env, 5); /* cdarx */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-4];
    stack[-2] = stack[0];
    stack[-1] = v194;
    goto v80;

v75:
    v194 = stack[-3];
    v7 = qcdr(v194);
    v194 = stack[0];
    v194 = qcdr(v194);
    v194 = (Lisp_Object)greaterp2(v7, v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v194 = v194 ? lisp_true : nil;
    env = stack[-4];
    if (v194 == nil) goto v136;
    v194 = stack[0];
    stack[0] = v194;
    goto v197;

v197:
    v194 = stack[-2];
    fn = elt(env, 5); /* cdarx */
    stack[-2] = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-4];
    v194 = stack[-1];
    fn = elt(env, 5); /* cdarx */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-4];
    v194 = CC_gck2(env, stack[-2], v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-4];
    v194 = cons(stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    popv(5);
    return ncons(v194);

v136:
    v194 = stack[-3];
    stack[0] = v194;
    goto v197;

v60:
    v194 = stack[-2];
    fn = elt(env, 5); /* cdarx */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-4];
    stack[-2] = v194;
    goto v80;

v41:
    v194 = stack[-1];
    if (!consp(v194)) goto v152;
    v194 = stack[-1];
    v194 = qcar(v194);
    if (!consp(v194)) goto v152;
    v194 = stack[-1];
    fn = elt(env, 5); /* cdarx */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-4];
    stack[-1] = v194;
    goto v80;

v152:
    v7 = qvalue(elt(env, 1)); /* dmode!* */
    v194 = elt(env, 2); /* field */
    v194 = Lflagp(nil, v7, v194);
    env = stack[-4];
    if (!(v194 == nil)) goto v155;
    v194 = stack[-2];
    v194 = Lconsp(nil, v194);
    env = stack[-4];
    if (v194 == nil) goto v106;
    v194 = stack[-2];
    v7 = qcar(v194);
    v194 = elt(env, 2); /* field */
    v194 = Lflagp(nil, v7, v194);
    env = stack[-4];
    if (!(v194 == nil)) goto v155;

v106:
    v194 = stack[-1];
    v194 = Lconsp(nil, v194);
    env = stack[-4];
    if (v194 == nil) goto v20;
    v194 = stack[-1];
    v7 = qcar(v194);
    v194 = elt(env, 2); /* field */
    v194 = Lflagp(nil, v7, v194);
    env = stack[-4];
    if (!(v194 == nil)) goto v155;

v20:
    v7 = qvalue(elt(env, 1)); /* dmode!* */
    v194 = elt(env, 3); /* !:gi!: */
    if (v7 == v194) goto v142;
    v7 = stack[-2];
    v194 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* gcddd */
        return (*qfn2(fn))(qenv(fn), v7, v194);
    }

v142:
    v7 = stack[-2];
    v194 = stack[-1];
    {
        popv(5);
        fn = elt(env, 7); /* intgcdd */
        return (*qfn2(fn))(qenv(fn), v7, v194);
    }

v155:
    v194 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v194); }
/* error exit handlers */
v195:
    popv(5);
    return nil;
}



/* Code for ibalp_minclnr */

static Lisp_Object CC_ibalp_minclnr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_minclnr");
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
    v120 = v0;
/* end of prologue */
    v119 = (Lisp_Object)1600001; /* 100000 */
    stack[-2] = v119;
    v119 = v120;
    stack[-1] = v119;
    goto v83;

v83:
    v119 = stack[-1];
    if (v119 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v119 = stack[-1];
    v119 = qcar(v119);
    stack[0] = v119;
    v119 = stack[0];
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = qcar(v119);
    if (!(v119 == nil)) goto v198;
    v119 = stack[0];
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v120 = qcar(v119);
    v119 = stack[0];
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = qcar(v119);
    v120 = plus2(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-3];
    v119 = stack[-2];
    v119 = (Lisp_Object)lessp2(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v119 = v119 ? lisp_true : nil;
    env = stack[-3];
    if (v119 == nil) goto v198;
    v119 = stack[0];
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v120 = qcar(v119);
    v119 = stack[0];
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = qcar(v119);
    v119 = plus2(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-3];
    stack[-2] = v119;
    goto v198;

v198:
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-1] = v119;
    goto v83;
/* error exit handlers */
v176:
    popv(4);
    return nil;
}



/* Code for mml2ir */

static Lisp_Object MS_CDECL CC_mml2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mml2ir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mml2ir");
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
    v66 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v66;
    v66 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v66; /* mmlatts */
    v67 = elt(env, 3); /* !! */
    v66 = (Lisp_Object)513; /* 32 */
    v66 = list2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    v66 = Lcompress(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    qvalue(elt(env, 4)) = v66; /* space */
    v66 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v66; /* count */
    v66 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    qvalue(elt(env, 6)) = v66; /* ch */
    v66 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v66; /* temp2 */
    fn = elt(env, 13); /* lex */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    v67 = qvalue(elt(env, 8)); /* char */
    v66 = elt(env, 9); /* (m a t h) */
    if (equal(v67, v66)) goto v198;
    v67 = elt(env, 10); /* "<math>" */
    v66 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 14); /* errorml */
    v66 = (*qfn2(fn))(qenv(fn), v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    goto v72;

v72:
    fn = elt(env, 13); /* lex */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    v67 = qvalue(elt(env, 8)); /* char */
    v66 = elt(env, 11); /* (!/ m a t h) */
    if (equal(v67, v66)) goto v152;
    v67 = elt(env, 12); /* "</math>" */
    v66 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 14); /* errorml */
    v66 = (*qfn2(fn))(qenv(fn), v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v162;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v152:
    v66 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v162;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v198:
    fn = elt(env, 15); /* mathml */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    stack[0] = v66;
    goto v72;
/* error exit handlers */
v162:
    popv(2);
    return nil;
}



/* Code for initarg */

static Lisp_Object CC_initarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initarg");
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
    v205 = qvalue(elt(env, 1)); /* op */
    v204 = elt(env, 2); /* symmetric */
    v204 = Lflagp(nil, v205, v204);
    env = stack[-6];
    qvalue(elt(env, 3)) = v204; /* symm */
    v204 = qvalue(elt(env, 4)); /* p */
    stack[0] = Llength(nil, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v204 = qvalue(elt(env, 5)); /* r */
    v204 = Llength(nil, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v204 = difference2(stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v204 = add1(v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-1] = v204;
    v204 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 16); /* ident */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    qvalue(elt(env, 6)) = v204; /* identity */
    v204 = qvalue(elt(env, 5)); /* r */
    v204 = qcar(v204);
    fn = elt(env, 17); /* mgenp */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-3] = v204;
    v204 = qvalue(elt(env, 5)); /* r */
    v204 = qcdr(v204);
    fn = elt(env, 18); /* list!-mgen */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[0] = v204;
    v205 = qvalue(elt(env, 1)); /* op */
    v204 = elt(env, 7); /* assoc */
    v204 = Lflagp(nil, v205, v204);
    env = stack[-6];
    if (v204 == nil) goto v23;
    v204 = qvalue(elt(env, 3)); /* symm */
    if (v204 == nil) goto v68;
    v205 = stack[0];
    v204 = (Lisp_Object)1; /* 0 */
    v204 = (Lisp_Object)greaterp2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v204 = v204 ? lisp_true : nil;
    env = stack[-6];
    if (v204 == nil) goto v105;
    v204 = qvalue(elt(env, 9)); /* !*sym!-assoc */
    v204 = (v204 == nil ? lisp_true : nil);
    goto v112;

v112:
    v204 = (v204 == nil ? lisp_true : nil);
    goto v155;

v155:
    stack[-5] = v204;
    v204 = qvalue(elt(env, 5)); /* r */
    v205 = Llength(nil, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v204 = (Lisp_Object)17; /* 1 */
    v204 = (Lisp_Object)greaterp2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v204 = v204 ? lisp_true : nil;
    env = stack[-6];
    if (v204 == nil) goto v22;
    v204 = stack[-5];
    if (!(v204 == nil)) goto v21;
    v204 = stack[0];
    goto v21;

v21:
    stack[-2] = v204;
    v205 = stack[-1];
    v204 = (Lisp_Object)17; /* 1 */
    v204 = (Lisp_Object)greaterp2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v204 = v204 ? lisp_true : nil;
    env = stack[-6];
    if (!(v204 == nil)) goto v143;
    v204 = qvalue(elt(env, 6)); /* identity */
    if (v204 == nil) goto v19;
    v204 = qvalue(elt(env, 4)); /* p */
    v205 = Llength(nil, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v204 = (Lisp_Object)1; /* 0 */
    v204 = (Lisp_Object)greaterp2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v204 = v204 ? lisp_true : nil;
    env = stack[-6];
    goto v143;

v143:
    v205 = v204;
    v204 = stack[-3];
    if (v204 == nil) goto v131;
    v204 = v205;
    goto v163;

v163:
    qvalue(elt(env, 10)) = v204; /* mcontract */
    v204 = stack[-5];
    if (v204 == nil) goto v16;
    v204 = v205;
    if (v204 == nil) goto v14;
    v204 = stack[-3];
    v204 = (v204 == nil ? lisp_true : nil);
    goto v15;

v15:
    qvalue(elt(env, 11)) = v204; /* acontract */
    v204 = qvalue(elt(env, 6)); /* identity */
    if (v204 == nil) goto v139;
    v205 = stack[-1];
    v204 = (Lisp_Object)17; /* 1 */
    v204 = (Lisp_Object)lessp2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v204 = v204 ? lisp_true : nil;
    env = stack[-6];
    if (!(v204 == nil)) goto v74;
    v204 = stack[-2];
    goto v74;

v74:
    qvalue(elt(env, 12)) = v204; /* expand */
    v204 = stack[-2];
    if (!(v204 == nil)) goto v207;
    v205 = stack[-1];
    v204 = (Lisp_Object)17; /* 1 */
    v204 = (Lisp_Object)lessp2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v204 = v204 ? lisp_true : nil;
    env = stack[-6];
    if (!(v204 == nil)) goto v207;
    v204 = stack[-1];
    goto v197;

v197:
    qvalue(elt(env, 13)) = v204; /* i */
    v204 = qvalue(elt(env, 6)); /* identity */
    if (v204 == nil) goto v208;
    v204 = qvalue(elt(env, 4)); /* p */
    v204 = Llength(nil, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    goto v12;

v12:
    qvalue(elt(env, 14)) = v204; /* upb */
    v204 = qvalue(elt(env, 3)); /* symm */
    if (v204 == nil) goto v126;
    v204 = stack[-4];
    fn = elt(env, 19); /* initcomb */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    qvalue(elt(env, 15)) = v204; /* comb */
    goto v126;

v126:
    v204 = nil;
    { popv(7); return onevalue(v204); }

v208:
    v205 = stack[-1];
    v204 = stack[0];
    v204 = plus2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    goto v12;

v207:
    v204 = stack[-3];
    if (v204 == nil) goto v168;
    v204 = (Lisp_Object)1; /* 0 */
    goto v197;

v168:
    v204 = (Lisp_Object)17; /* 1 */
    goto v197;

v139:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v74;

v14:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v15;

v16:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v15;

v131:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v163;

v19:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v143;

v22:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v21;

v105:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v112;

v68:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v112;

v23:
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v155;
/* error exit handlers */
v206:
    popv(7);
    return nil;
}



/* Code for dipevlcomp */

static Lisp_Object CC_dipevlcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipevlcomp");
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
    v101 = v1;
    v122 = v0;
/* end of prologue */
    v122 = qcar(v122);
    v101 = qcar(v101);
    fn = elt(env, 1); /* evcompless!? */
    v101 = (*qfn2(fn))(qenv(fn), v122, v101);
    errexit();
    v101 = (v101 == nil ? lisp_true : nil);
    return onevalue(v101);
}



/* Code for gbfdot */

static Lisp_Object CC_gbfdot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbfdot");
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
    v34 = stack[-1];
    v33 = qcar(v34);
    v34 = stack[0];
    v34 = qcar(v34);
    fn = elt(env, 1); /* csl_timbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v33, v34);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-3];
    v34 = stack[-1];
    v33 = qcdr(v34);
    v34 = stack[0];
    v34 = qcdr(v34);
    fn = elt(env, 1); /* csl_timbf */
    v34 = (*qfn2(fn))(qenv(fn), v33, v34);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-3];
    {
        Lisp_Object v43 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v43, v34);
    }
/* error exit handlers */
v42:
    popv(4);
    return nil;
}



/* Code for prop!-simp1 */

static Lisp_Object MS_CDECL CC_propKsimp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v57, Lisp_Object v27,
                         Lisp_Object v81, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211, v79, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "prop-simp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp1");
#endif
    if (stack >= stacklimit)
    {
        push5(v81,v27,v57,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v57,v27,v81);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v81;
    stack[0] = v27;
    stack[-5] = v57;
    stack[-2] = v1;
    stack[-6] = v0;
/* end of prologue */

v154:
    v211 = stack[-2];
    if (v211 == nil) goto v72;
    v79 = stack[-6];
    v211 = stack[-2];
    v211 = qcar(v211);
    fn = elt(env, 1); /* prop!-simp2 */
    v211 = (*qfn2(fn))(qenv(fn), v79, v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    stack[-3] = v211;
    v211 = stack[-3];
    if (v211 == nil) goto v108;
    v211 = stack[-3];
    stack[-6] = qcdr(v211);
    v211 = stack[-2];
    stack[-2] = qcdr(v211);
    stack[-1] = stack[-5];
    v211 = stack[0];
    stack[0] = add1(v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v211 = stack[-3];
    stack[-7] = qcar(v211);
    stack[-3] = (Lisp_Object)-15; /* -1 */
    v211 = stack[-5];
    v211 = Llength(nil, v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v211 = Lexpt(nil, stack[-3], v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v211 = times2(stack[-4], v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v211 = times2(stack[-7], v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    stack[-5] = stack[-1];
    stack[-4] = v211;
    goto v154;

v108:
    stack[-3] = stack[-6];
    v211 = stack[-2];
    stack[-1] = qcdr(v211);
    v211 = stack[-2];
    v79 = qcar(v211);
    v211 = stack[-5];
    v85 = cons(v79, v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    v79 = stack[0];
    v211 = stack[-4];
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v85;
    stack[0] = v79;
    stack[-4] = v211;
    goto v154;

v72:
    v79 = stack[0];
    v211 = stack[-4];
    stack[0] = list2(v79, v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-8];
    stack[-1] = stack[-6];
    v211 = stack[-5];
    v211 = Lreverse(nil, v211);
    nil = C_nil;
    if (exception_pending()) goto v182;
    {
        Lisp_Object v173 = stack[0];
        Lisp_Object v53 = stack[-1];
        popv(9);
        return list2star(v173, v53, v211);
    }
/* error exit handlers */
v182:
    popv(9);
    return nil;
}



/* Code for red_totalred */

static Lisp_Object CC_red_totalred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_totalred");
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
    v48 = v1;
    v71 = v0;
/* end of prologue */
    stack[0] = v71;
    fn = elt(env, 1); /* red_topred */
    v48 = (*qfn2(fn))(qenv(fn), v71, v48);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-1];
    {
        Lisp_Object v41 = stack[0];
        popv(2);
        fn = elt(env, 2); /* red_tailred */
        return (*qfn2(fn))(qenv(fn), v41, v48);
    }
/* error exit handlers */
v198:
    popv(2);
    return nil;
}



/* Code for exptsq */

static Lisp_Object CC_exptsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v221, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptsq");
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
    v221 = stack[-1];
    v220 = (Lisp_Object)17; /* 1 */
    if (v221 == v220) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v221 = stack[-1];
    v220 = (Lisp_Object)1; /* 0 */
    if (v221 == v220) goto v48;
    v220 = stack[-2];
    v220 = qcar(v220);
    if (v220 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v221 = stack[-1];
    v220 = (Lisp_Object)1; /* 0 */
    v220 = (Lisp_Object)lessp2(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    v220 = v220 ? lisp_true : nil;
    env = stack[-4];
    if (v220 == nil) goto v105;
    v220 = stack[-2];
    fn = elt(env, 6); /* mk!*sq */
    v221 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    v220 = stack[-1];
    v220 = list2(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 7); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v220);
    }

v105:
    v220 = qvalue(elt(env, 3)); /* !*exp */
    if (v220 == nil) goto v87;
    v220 = stack[-2];
    fn = elt(env, 8); /* kernp */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    if (v220 == nil) goto v51;
    v220 = stack[-2];
    v220 = qcar(v220);
    v220 = qcar(v220);
    v220 = qcar(v220);
    v221 = qcar(v220);
    v220 = stack[-1];
    {
        popv(5);
        fn = elt(env, 9); /* mksq */
        return (*qfn2(fn))(qenv(fn), v221, v220);
    }

v51:
    v220 = stack[-2];
    v221 = qcdr(v220);
    v220 = (Lisp_Object)17; /* 1 */
    if (v221 == v220) goto v56;
    v220 = stack[-2];
    v220 = qcar(v220);
    if (!consp(v220)) goto v207;
    v220 = stack[-2];
    v220 = qcar(v220);
    v220 = qcar(v220);
    if (!consp(v220)) goto v207;
    v220 = stack[-2];
    stack[-3] = v220;
    goto v224;

v224:
    v220 = stack[-1];
    v221 = sub1(v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    stack[-1] = v221;
    v220 = (Lisp_Object)1; /* 0 */
    v220 = (Lisp_Object)greaterp2(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    v220 = v220 ? lisp_true : nil;
    env = stack[-4];
    if (v220 == nil) goto v225;
    v220 = stack[-2];
    v221 = qcar(v220);
    v220 = stack[-3];
    v220 = qcar(v220);
    fn = elt(env, 10); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    v220 = stack[-2];
    v221 = qcdr(v220);
    v220 = stack[-3];
    v220 = qcdr(v220);
    fn = elt(env, 10); /* multf */
    v220 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    v220 = cons(stack[0], v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    stack[-3] = v220;
    goto v224;

v225:
    v220 = stack[-3];
    fn = elt(env, 11); /* canonsq */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    stack[-3] = v220;
    goto v76;

v76:
    v220 = stack[-3];
    v220 = qcdr(v220);
    if (!(v220 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v222 = elt(env, 1); /* poly */
    v221 = (Lisp_Object)1617; /* 101 */
    v220 = elt(env, 5); /* "Zero divisor" */
    fn = elt(env, 12); /* rerror */
    v220 = (*qfnn(fn))(qenv(fn), 3, v222, v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v207:
    v220 = stack[-2];
    v221 = qcar(v220);
    v220 = stack[-1];
    fn = elt(env, 13); /* !:expt */
    v221 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    v220 = (Lisp_Object)17; /* 1 */
    stack[-3] = cons(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    stack[0] = (Lisp_Object)17; /* 1 */
    v220 = stack[-2];
    v221 = qcdr(v220);
    v220 = stack[-1];
    fn = elt(env, 14); /* exptf */
    v220 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    v220 = cons(stack[0], v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    fn = elt(env, 15); /* multsq */
    v220 = (*qfn2(fn))(qenv(fn), stack[-3], v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    stack[-3] = v220;
    goto v76;

v56:
    v220 = stack[-2];
    v221 = qcar(v220);
    v220 = stack[-1];
    fn = elt(env, 14); /* exptf */
    v221 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    v220 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v221, v220);

v87:
    v220 = stack[-2];
    v221 = qcar(v220);
    v220 = stack[-1];
    fn = elt(env, 16); /* mksfpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-4];
    v220 = stack[-2];
    v221 = qcdr(v220);
    v220 = stack[-1];
    fn = elt(env, 16); /* mksfpf */
    v220 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v223;
    {
        Lisp_Object v226 = stack[0];
        popv(5);
        return cons(v226, v220);
    }

v48:
    v220 = stack[-2];
    v220 = qcar(v220);
    if (v220 == nil) goto v42;
    v221 = (Lisp_Object)17; /* 1 */
    v220 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v221, v220);

v42:
    v222 = elt(env, 1); /* poly */
    v221 = (Lisp_Object)65; /* 4 */
    v220 = elt(env, 2); /* " 0**0 formed" */
    {
        popv(5);
        fn = elt(env, 12); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v222, v221, v220);
    }
/* error exit handlers */
v223:
    popv(5);
    return nil;
}



/* Code for mo_comp */

static Lisp_Object CC_mo_comp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v122;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_comp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v101 = v0;
/* end of prologue */
    v122 = v101;
    v122 = qcar(v122);
    if (v122 == nil) goto v81;
    v101 = qcar(v101);
    v101 = qcar(v101);
    return onevalue(v101);

v81:
    v101 = (Lisp_Object)1; /* 0 */
    return onevalue(v101);
}



/* Code for get!-denom!-ll */

static Lisp_Object CC_getKdenomKll(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-denom-ll");
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
    stack[-3] = nil;
    goto v30;

v30:
    v99 = stack[-2];
    if (v99 == nil) goto v83;
    v99 = stack[-2];
    stack[0] = qcar(v99);
    v99 = stack[-1];
    v99 = qcar(v99);
    fn = elt(env, 1); /* get!-denom!-l */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    fn = elt(env, 2); /* lcmn */
    v115 = (*qfn2(fn))(qenv(fn), stack[0], v99);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v99 = stack[-3];
    v99 = cons(v115, v99);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    stack[-3] = v99;
    v99 = stack[-2];
    v99 = qcdr(v99);
    stack[-2] = v99;
    v99 = stack[-1];
    v99 = qcdr(v99);
    stack[-1] = v99;
    goto v30;

v83:
    v99 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v99);
    }
/* error exit handlers */
v152:
    popv(5);
    return nil;
}



/* Code for binaryrd */

static Lisp_Object MS_CDECL CC_binaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "binaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binaryrd");
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
    fn = elt(env, 2); /* mathml */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    stack[-1] = v71;
    fn = elt(env, 2); /* mathml */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    stack[0] = v71;
    fn = elt(env, 3); /* lex */
    v71 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    v72 = stack[-1];
    v71 = stack[0];
    v198 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return list2star(v72, v71, v198);
/* error exit handlers */
v185:
    popv(3);
    return nil;
}



/* Code for meq */

static Lisp_Object CC_meq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v114, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for meq");
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
    v153 = stack[-1];
    fn = elt(env, 2); /* binding */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v114 = v153;
    v153 = v114;
    if (v153 == nil) goto v110;
    v153 = v114;
    v100 = elt(env, 1); /* unbound */
    if (v153 == v100) goto v110;
    v153 = v114;
    v114 = v153;
    goto v84;

v84:
    v153 = stack[0];
    v153 = (equal(v114, v153) ? lisp_true : nil);
    { popv(3); return onevalue(v153); }

v110:
    v153 = stack[-1];
    v114 = v153;
    goto v84;
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for dip!-nc!-ev!-prod1 */

static Lisp_Object MS_CDECL CC_dipKncKevKprod1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v57, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v44, v99, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip-nc-ev-prod1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip-nc-ev-prod1");
#endif
    if (stack >= stacklimit)
    {
        push3(v57,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v57);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v44 = v57;
    v99 = v1;
    v115 = v0;
/* end of prologue */
    v94 = v115;
    if (v94 == nil) { popv(3); return onevalue(v44); }
    v94 = v115;
    stack[-1] = qcar(v94);
    stack[0] = v99;
    v94 = v115;
    v94 = qcdr(v94);
    v99 = (Lisp_Object)((int32_t)(v99) + 0x10);
    v94 = CC_dipKncKevKprod1(env, 3, v94, v99, v44);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    {
        Lisp_Object v70 = stack[-1];
        Lisp_Object v152 = stack[0];
        popv(3);
        fn = elt(env, 1); /* dip!-nc!-ev!-prod2 */
        return (*qfnn(fn))(qenv(fn), 3, v70, v152, v94);
    }
/* error exit handlers */
v146:
    popv(3);
    return nil;
}



/* Code for vdpsave */

static Lisp_Object CC_vdpsave(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v27;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsave");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v0;
/* end of prologue */
    return onevalue(v27);
}



/* Code for partitexdf */

static Lisp_Object CC_partitexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitexdf");
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
    v30 = v0;
/* end of prologue */
    v30 = qcar(v30);
    fn = elt(env, 1); /* partitop */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* exdfpf */
        return (*qfn1(fn))(qenv(fn), v30);
    }
/* error exit handlers */
v76:
    popv(1);
    return nil;
}



/* Code for permp */

static Lisp_Object CC_permp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v25, v86, v112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for permp");
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
    v25 = v1;
    v86 = v0;
/* end of prologue */

v80:
    v24 = v86;
    if (v24 == nil) goto v84;
    v24 = v86;
    v112 = qcar(v24);
    v24 = v25;
    v24 = qcar(v24);
    if (equal(v112, v24)) goto v45;
    v24 = v86;
    stack[0] = qcdr(v24);
    v24 = v25;
    v24 = qcar(v24);
    v86 = qcar(v86);
    v25 = qcdr(v25);
    v24 = Lsubst(nil, 3, v24, v86, v25);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-1];
    v24 = CC_permp(env, stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v113;
    v24 = (v24 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v24); }

v45:
    v24 = v86;
    v24 = qcdr(v24);
    v86 = v24;
    v24 = v25;
    v24 = qcdr(v24);
    v25 = v24;
    goto v80;

v84:
    v24 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v24); }
/* error exit handlers */
v113:
    popv(2);
    return nil;
}



/* Code for ordop2 */

static Lisp_Object CC_ordop2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v95, v109, v108, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v108 = v1;
    v111 = v0;
/* end of prologue */
    v96 = qvalue(elt(env, 1)); /* kord!* */
    v109 = v96;
    goto v30;

v30:
    v96 = v109;
    if (v96 == nil) goto v101;
    v95 = v111;
    v96 = v109;
    v96 = qcar(v96);
    if (v95 == v96) goto v198;
    v95 = v108;
    v96 = v109;
    v96 = qcar(v96);
    if (v95 == v96) goto v114;
    v96 = v109;
    v96 = qcdr(v96);
    v109 = v96;
    goto v30;

v114:
    v96 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v96);

v198:
    v96 = qvalue(elt(env, 2)); /* t */
    return onevalue(v96);

v101:
    v96 = v111;
    v95 = v108;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v96, v95);
    }
}



/* Code for def_edge */

static Lisp_Object CC_def_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v100, v42, v43;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for def_edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v1;
    v114 = v0;
/* end of prologue */
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v42 = v114;
    v114 = v42;
    v100 = qcar(v114);
    v114 = v43;
    v114 = Lassoc(nil, v100, v114);
    if (v114 == nil) goto v83;
    v114 = v42;
    v114 = qcdr(v114);
    v100 = v43;
    v114 = Lassoc(nil, v114, v100);
    return onevalue(v114);

v83:
    v114 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v114);
}



/* Code for mo_equal!? */

static Lisp_Object CC_mo_equalW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_equal?");
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
    v122 = v0;
/* end of prologue */
    v122 = qcar(v122);
    fn = elt(env, 1); /* mo!=shorten */
    stack[-1] = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v122 = stack[0];
    v122 = qcar(v122);
    fn = elt(env, 1); /* mo!=shorten */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v48;
    v122 = (equal(stack[-1], v122) ? lisp_true : nil);
    { popv(3); return onevalue(v122); }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for st_sorttree */

static Lisp_Object MS_CDECL CC_st_sorttree(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v57, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v47, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree");
#endif
    if (stack >= stacklimit)
    {
        push3(v57,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v57);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v57;
    v47 = v1;
    v48 = v0;
/* end of prologue */
    fn = elt(env, 1); /* st_sorttree1 */
    v6 = (*qfnn(fn))(qenv(fn), 3, v48, v47, v6);
    errexit();
    v6 = qcdr(v6);
    return onevalue(v6);
}



/* Code for use!-berlekamp */

static Lisp_Object MS_CDECL CC_useKberlekamp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v57, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v257, v258, v259, v260, v261, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "use-berlekamp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for use-berlekamp");
#endif
    if (stack >= stacklimit)
    {
        push3(v57,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v57);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v57;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v256 = qvalue(elt(env, 1)); /* dpoly */
    v256 = (Lisp_Object)((int32_t)(v256) - 0x10);
    stack[-3] = v256;
    v256 = stack[-3];
    v256 = Lmkvect(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-8];
    stack[-7] = v256;
    v256 = (Lisp_Object)1; /* 0 */
    stack[0] = v256;
    goto v185;

v185:
    v257 = stack[-3];
    v256 = stack[0];
    v256 = (Lisp_Object)(int32_t)((int32_t)v257 - (int32_t)v256 + TAG_FIXNUM);
    v256 = ((intptr_t)(v256) < 0 ? lisp_true : nil);
    if (v256 == nil) goto v198;
    v259 = stack[-6];
    v258 = stack[-5];
    v257 = qvalue(elt(env, 3)); /* poly!-vector */
    v256 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v256 = (*qfnn(fn))(qenv(fn), 4, v259, v258, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-8];
    stack[-5] = v256;
    v256 = (Lisp_Object)1; /* 0 */
    stack[-2] = v256;
    v256 = stack[-3];
    v256 = Lmkvect(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-8];
    stack[-1] = v256;
    v258 = stack[-1];
    v257 = (Lisp_Object)1; /* 0 */
    v256 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v258 + (CELL-TAG_VECTOR) + ((int32_t)v257/(16/CELL))) = v256;
    v256 = (Lisp_Object)17; /* 1 */
    stack[0] = v256;
    goto v156;

v156:
    v257 = stack[-3];
    v256 = stack[0];
    v256 = (Lisp_Object)(int32_t)((int32_t)v257 - (int32_t)v256 + TAG_FIXNUM);
    v256 = ((intptr_t)(v256) < 0 ? lisp_true : nil);
    if (v256 == nil) goto v182;
    v257 = stack[-7];
    v256 = stack[-3];
    {
        popv(9);
        fn = elt(env, 6); /* find!-null!-space */
        return (*qfn2(fn))(qenv(fn), v257, v256);
    }

v182:
    v257 = qvalue(elt(env, 4)); /* current!-modulus */
    v256 = qvalue(elt(env, 1)); /* dpoly */
    if (((int32_t)(v257)) > ((int32_t)(v256))) goto v264;
    v256 = (Lisp_Object)1; /* 0 */
    v259 = v256;
    goto v265;

v265:
    v256 = qvalue(elt(env, 4)); /* current!-modulus */
    v257 = (Lisp_Object)((int32_t)(v256) - 0x10);
    v256 = v259;
    v256 = (Lisp_Object)(int32_t)((int32_t)v257 - (int32_t)v256 + TAG_FIXNUM);
    v256 = ((intptr_t)(v256) < 0 ? lisp_true : nil);
    if (v256 == nil) goto v266;
    v256 = (Lisp_Object)1; /* 0 */
    v260 = v256;
    goto v12;

v12:
    v257 = stack[-2];
    v256 = v260;
    v256 = (Lisp_Object)(int32_t)((int32_t)v257 - (int32_t)v256 + TAG_FIXNUM);
    v256 = ((intptr_t)(v256) < 0 ? lisp_true : nil);
    if (v256 == nil) goto v224;
    v257 = stack[-2];
    v256 = qvalue(elt(env, 4)); /* current!-modulus */
    v256 = (Lisp_Object)(int32_t)((int32_t)v257 + (int32_t)v256 - TAG_FIXNUM);
    stack[-2] = v256;
    goto v29;

v29:
    v259 = stack[-4];
    v258 = stack[-2];
    v257 = qvalue(elt(env, 3)); /* poly!-vector */
    v256 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v256 = (*qfnn(fn))(qenv(fn), 4, v259, v258, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-8];
    stack[-2] = v256;
    v256 = (Lisp_Object)1; /* 0 */
    v262 = v256;
    goto v222;

v222:
    v257 = stack[-2];
    v256 = v262;
    v256 = (Lisp_Object)(int32_t)((int32_t)v257 - (int32_t)v256 + TAG_FIXNUM);
    v256 = ((intptr_t)(v256) < 0 ? lisp_true : nil);
    if (v256 == nil) goto v267;
    v257 = stack[-7];
    v256 = stack[0];
    v259 = *(Lisp_Object *)((char *)v257 + (CELL-TAG_VECTOR) + ((int32_t)v256/(16/CELL)));
    v258 = stack[0];
    v257 = stack[-7];
    v256 = stack[0];
    v257 = *(Lisp_Object *)((char *)v257 + (CELL-TAG_VECTOR) + ((int32_t)v256/(16/CELL)));
    v256 = stack[0];
    v257 = *(Lisp_Object *)((char *)v257 + (CELL-TAG_VECTOR) + ((int32_t)v256/(16/CELL)));
    v256 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v257) - int_of_fixnum(v256);
        if (w < 0) w += current_modulus;
        v256 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v259 + (CELL-TAG_VECTOR) + ((int32_t)v258/(16/CELL))) = v256;
    v256 = stack[0];
    v256 = (Lisp_Object)((int32_t)(v256) + 0x10);
    stack[0] = v256;
    goto v156;

v267:
    v257 = stack[-7];
    v256 = v262;
    v261 = *(Lisp_Object *)((char *)v257 + (CELL-TAG_VECTOR) + ((int32_t)v256/(16/CELL)));
    v260 = stack[0];
    v259 = stack[-1];
    v258 = v262;
    v257 = stack[-4];
    v256 = v262;
    v256 = *(Lisp_Object *)((char *)v257 + (CELL-TAG_VECTOR) + ((int32_t)v256/(16/CELL)));
    *(Lisp_Object *)((char *)v259 + (CELL-TAG_VECTOR) + ((int32_t)v258/(16/CELL))) = v256;
    *(Lisp_Object *)((char *)v261 + (CELL-TAG_VECTOR) + ((int32_t)v260/(16/CELL))) = v256;
    v256 = v262;
    v256 = (Lisp_Object)((int32_t)(v256) + 0x10);
    v262 = v256;
    goto v222;

v224:
    v259 = stack[-4];
    v257 = qvalue(elt(env, 4)); /* current!-modulus */
    v256 = v260;
    v258 = (Lisp_Object)(int32_t)((int32_t)v257 + (int32_t)v256 - TAG_FIXNUM);
    v257 = stack[-1];
    v256 = v260;
    v256 = *(Lisp_Object *)((char *)v257 + (CELL-TAG_VECTOR) + ((int32_t)v256/(16/CELL)));
    *(Lisp_Object *)((char *)v259 + (CELL-TAG_VECTOR) + ((int32_t)v258/(16/CELL))) = v256;
    v256 = v260;
    v256 = (Lisp_Object)((int32_t)(v256) + 0x10);
    v260 = v256;
    goto v12;

v266:
    v258 = stack[-4];
    v257 = v259;
    v256 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v258 + (CELL-TAG_VECTOR) + ((int32_t)v257/(16/CELL))) = v256;
    v256 = v259;
    v256 = (Lisp_Object)((int32_t)(v256) + 0x10);
    v259 = v256;
    goto v265;

v264:
    v260 = stack[-1];
    v259 = stack[-2];
    v258 = stack[-6];
    v257 = stack[-5];
    v256 = stack[-4];
    fn = elt(env, 7); /* times!-in!-vector */
    v256 = (*qfnn(fn))(qenv(fn), 5, v260, v259, v258, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-8];
    stack[-2] = v256;
    goto v29;

v198:
    v256 = stack[-3];
    v256 = Lmkvect(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-8];
    v260 = v256;
    v256 = (Lisp_Object)1; /* 0 */
    v259 = v256;
    goto v96;

v96:
    v257 = stack[-3];
    v256 = v259;
    v256 = (Lisp_Object)(int32_t)((int32_t)v257 - (int32_t)v256 + TAG_FIXNUM);
    v256 = ((intptr_t)(v256) < 0 ? lisp_true : nil);
    if (v256 == nil) goto v112;
    v257 = stack[-7];
    v256 = stack[0];
    v258 = v260;
    *(Lisp_Object *)((char *)v257 + (CELL-TAG_VECTOR) + ((int32_t)v256/(16/CELL))) = v258;
    v256 = stack[0];
    v256 = (Lisp_Object)((int32_t)(v256) + 0x10);
    stack[0] = v256;
    goto v185;

v112:
    v258 = v260;
    v257 = v259;
    v256 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v258 + (CELL-TAG_VECTOR) + ((int32_t)v257/(16/CELL))) = v256;
    v256 = v259;
    v256 = (Lisp_Object)((int32_t)(v256) + 0x10);
    v259 = v256;
    goto v96;
/* error exit handlers */
v263:
    popv(9);
    return nil;
}



/* Code for mk!+trace */

static Lisp_Object CC_mkLtrace(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v162, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+trace");
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
    v116 = stack[-1];
    fn = elt(env, 5); /* squared!+matrix!+p */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    if (!(v116 == nil)) goto v122;
    v116 = elt(env, 1); /* "no square matrix in add" */
    fn = elt(env, 6); /* rederr */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    goto v122;

v122:
    v162 = qvalue(elt(env, 2)); /* nil */
    v116 = (Lisp_Object)17; /* 1 */
    v116 = cons(v162, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    stack[0] = v116;
    v116 = (Lisp_Object)17; /* 1 */
    stack[-2] = v116;
    goto v100;

v100:
    v116 = stack[-1];
    fn = elt(env, 7); /* get!+row!+nr */
    v162 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    v116 = stack[-2];
    v116 = difference2(v162, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    v116 = Lminusp(nil, v116);
    env = stack[-3];
    if (v116 == nil) goto v65;
    v116 = qvalue(elt(env, 3)); /* t */
    stack[-1] = qvalue(elt(env, 4)); /* !*sub2 */
    qvalue(elt(env, 4)) = v116; /* !*sub2 */
    v116 = stack[0];
    fn = elt(env, 8); /* subs2 */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    stack[0] = v116;
    qvalue(elt(env, 4)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v65:
    v91 = stack[-1];
    v162 = stack[-2];
    v116 = stack[-2];
    fn = elt(env, 9); /* get!+mat!+entry */
    v116 = (*qfnn(fn))(qenv(fn), 3, v91, v162, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    fn = elt(env, 10); /* addsq */
    v116 = (*qfn2(fn))(qenv(fn), stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    stack[0] = v116;
    v116 = stack[-2];
    v116 = add1(v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    stack[-2] = v116;
    goto v100;
/* error exit handlers */
v119:
    env = stack[-3];
    qvalue(elt(env, 4)) = stack[-1]; /* !*sub2 */
    popv(4);
    return nil;
v118:
    popv(4);
    return nil;
}



/* Code for command */

static Lisp_Object MS_CDECL CC_command(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v276, v277, v278, v279;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for command");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-1] = qvalue(elt(env, 2)); /* loopdelimslist!* */
    qvalue(elt(env, 2)) = nil; /* loopdelimslist!* */
    v276 = qvalue(elt(env, 3)); /* !*demo */
    if (v276 == nil) goto v101;
    v276 = qvalue(elt(env, 4)); /* ifl!* */
    if (v276 == nil) goto v101;
    fn = elt(env, 29); /* commdemo */
    v276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v76;

v76:
    qvalue(elt(env, 2)) = stack[-1]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-2]; /* errmsg!* */
    { popv(4); return onevalue(v276); }

v101:
    v276 = qvalue(elt(env, 5)); /* !*slin */
    if (v276 == nil) goto v84;
    v276 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (!(v276 == nil)) goto v84;
    fn = elt(env, 30); /* setcloc!* */
    v276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    v276 = qvalue(elt(env, 7)); /* lreadfn!* */
    if (v276 == nil) goto v155;
    v277 = qvalue(elt(env, 7)); /* lreadfn!* */
    v276 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 31); /* lispapply */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v46;

v46:
    stack[0] = v276;
    goto v83;

v83:
    v276 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v276 == nil) goto v64;
    v276 = qvalue(elt(env, 25)); /* !*debug */
    if (v276 == nil) goto v281;
    v276 = elt(env, 26); /* "Parse: " */
    v276 = Lprinc(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    v276 = stack[0];
    fn = elt(env, 32); /* prettyprint */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v281;

v281:
    v277 = qvalue(elt(env, 17)); /* key!* */
    v276 = elt(env, 27); /* !*semicol!* */
    if (v277 == v276) goto v84;
    v276 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v276 == nil) goto v250;
    v276 = stack[0];
    fn = elt(env, 33); /* n_form */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    stack[0] = v276;
    goto v253;

v253:
    v276 = qvalue(elt(env, 25)); /* !*debug */
    if (v276 == nil) goto v221;
    v276 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    v276 = elt(env, 28); /* "Form: " */
    v276 = Lprinc(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    v276 = stack[0];
    fn = elt(env, 32); /* prettyprint */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v221;

v221:
    v276 = stack[0];
    goto v76;

v250:
    v276 = stack[0];
    fn = elt(env, 34); /* form */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    stack[0] = v276;
    goto v253;

v84:
    fn = elt(env, 35); /* readch1 */
    v276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    qvalue(elt(env, 9)) = v276; /* crchar!* */
    v277 = qvalue(elt(env, 9)); /* crchar!* */
    v276 = qvalue(elt(env, 10)); /* !$eol!$ */
    if (equal(v277, v276)) goto v84;
    fn = elt(env, 36); /* command1 */
    v276 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    stack[0] = v276;
    goto v83;

v64:
    v276 = qvalue(elt(env, 11)); /* !*struct */
    if (v276 == nil) goto v113;
    v276 = stack[0];
    fn = elt(env, 37); /* structchk */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    stack[0] = v276;
    goto v113;

v113:
    v276 = qvalue(elt(env, 12)); /* !*pret */
    if (v276 == nil) goto v116;
    v276 = stack[0];
    if (!consp(v276)) goto v162;
    v276 = stack[0];
    v277 = qcar(v276);
    v276 = elt(env, 13); /* (in out shut) */
    v276 = Lmemq(nil, v277, v276);
    if (!(v276 == nil)) goto v116;

v162:
    v276 = stack[0];
    if (!(v276 == nil)) goto v209;
    v277 = qvalue(elt(env, 14)); /* cursym!* */
    v276 = elt(env, 15); /* end */
    if (!(v277 == v276)) goto v209;
    v276 = elt(env, 15); /* end */
    fn = elt(env, 38); /* rprint */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v116;

v116:
    v276 = qvalue(elt(env, 5)); /* !*slin */
    if (v276 == nil) goto v175;
    v277 = elt(env, 16); /* symbolic */
    v276 = stack[0];
    v276 = list2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v76;

v175:
    v276 = stack[0];
    fn = elt(env, 34); /* form */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    v277 = v276;
    v278 = qvalue(elt(env, 17)); /* key!* */
    v276 = elt(env, 18); /* modefn */
    v276 = Lflagp(nil, v278, v276);
    env = stack[-3];
    if (v276 == nil) goto v51;
    v276 = qvalue(elt(env, 17)); /* key!* */
    goto v194;

v194:
    stack[0] = v276;
    v279 = v277;
    v278 = qvalue(elt(env, 8)); /* nil */
    v277 = elt(env, 16); /* symbolic */
    fn = elt(env, 39); /* convertmode1 */
    v276 = (*qfnn(fn))(qenv(fn), 4, v279, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    v276 = list2(stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v76;

v51:
    v276 = v277;
    if (!consp(v276)) goto v224;
    v276 = v277;
    v278 = qcar(v276);
    v276 = elt(env, 19); /* quote */
    if (v278 == v276) goto v224;
    v276 = v277;
    v276 = qcar(v276);
    if (!(symbolp(v276))) goto v82;
    v276 = v277;
    v278 = qcar(v276);
    v276 = elt(env, 20); /* nochange */
    v276 = Lflagp(nil, v278, v276);
    env = stack[-3];
    if (!(v276 == nil)) goto v11;
    v276 = v277;
    v278 = qcar(v276);
    v276 = elt(env, 21); /* intfn */
    v276 = Lflagp(nil, v278, v276);
    env = stack[-3];
    if (!(v276 == nil)) goto v11;
    v276 = v277;
    v278 = qcar(v276);
    v276 = elt(env, 22); /* list */
    if (!(v278 == v276)) goto v82;

v11:
    v276 = v277;
    v278 = qcar(v276);
    v276 = elt(env, 23); /* (setq setel setf) */
    v276 = Lmemq(nil, v278, v276);
    if (v276 == nil) goto v224;
    v276 = v277;
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v278 = qcar(v276);
    v276 = elt(env, 19); /* quote */
    if (!consp(v278)) goto v224;
    v278 = qcar(v278);
    if (!(v278 == v276)) goto v224;

v82:
    v276 = elt(env, 16); /* symbolic */
    goto v194;

v224:
    v276 = qvalue(elt(env, 24)); /* !*mode */
    goto v194;

v209:
    v276 = stack[0];
    fn = elt(env, 38); /* rprint */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    v276 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v116;

v155:
    v276 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-3];
    goto v46;
/* error exit handlers */
v280:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-2]; /* errmsg!* */
    popv(4);
    return nil;
}



/* Code for simpdf!* */

static Lisp_Object CC_simpdfH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v26, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdf*");
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
    v110 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simpdf */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    stack[0] = v110;
    v110 = stack[0];
    fn = elt(env, 2); /* rootextractsq */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v46 = v110;
    v26 = v46;
    v110 = stack[0];
    if (equal(v26, v110)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v110 = v46;
    {
        popv(2);
        fn = elt(env, 3); /* resimp */
        return (*qfn1(fn))(qenv(fn), v110);
    }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for embed!-null!-fn */

static Lisp_Object CC_embedKnullKfn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v175, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for embed-null-fn");
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
    v175 = v0;
/* end of prologue */
    v89 = v175;
    if (!consp(v89)) { popv(5); return onevalue(v175); }
    v89 = v175;
    stack[-3] = v89;
    goto v122;

v122:
    v89 = stack[-3];
    if (v89 == nil) goto v72;
    v89 = stack[-3];
    v89 = qcar(v89);
    v141 = v89;
    v89 = v141;
    if (!consp(v89)) goto v34;
    v89 = v141;
    v175 = qcar(v89);
    v89 = elt(env, 2); /* null!-fn */
    if (v175 == v89) goto v42;
    v89 = v141;
    v89 = CC_embedKnullKfn(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    v89 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    goto v46;

v46:
    stack[-2] = v89;
    v89 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    stack[-1] = v89;
    v89 = stack[-3];
    v89 = qcdr(v89);
    stack[-3] = v89;
    v89 = stack[-1];
    if (!consp(v89)) goto v122;
    else goto v6;

v6:
    v89 = stack[-3];
    if (v89 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v89 = stack[-3];
    v89 = qcar(v89);
    v141 = v89;
    v89 = v141;
    if (!consp(v89)) goto v176;
    v89 = v141;
    v175 = qcar(v89);
    v89 = elt(env, 2); /* null!-fn */
    if (v175 == v89) goto v37;
    v89 = v141;
    v89 = CC_embedKnullKfn(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    v89 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    goto v77;

v77:
    v89 = Lrplacd(nil, stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    v89 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    stack[-1] = v89;
    v89 = stack[-3];
    v89 = qcdr(v89);
    stack[-3] = v89;
    goto v6;

v37:
    v89 = v141;
    v89 = qcdr(v89);
    v89 = CC_embedKnullKfn(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    goto v77;

v176:
    v89 = v141;
    v89 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    goto v77;

v42:
    v89 = v141;
    v89 = qcdr(v89);
    v89 = CC_embedKnullKfn(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    goto v46;

v34:
    v89 = v141;
    v89 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-4];
    goto v46;

v72:
    v89 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v89); }
/* error exit handlers */
v283:
    popv(5);
    return nil;
}



/* Code for dipprod */

static Lisp_Object CC_dipprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipprod");
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
    v43 = stack[-1];
    fn = elt(env, 1); /* diplength */
    stack[-2] = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v43 = stack[0];
    fn = elt(env, 1); /* diplength */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v43 = (Lisp_Object)lesseq2(stack[-2], v43);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v43 = v43 ? lisp_true : nil;
    env = stack[-3];
    if (v43 == nil) goto v46;
    v94 = stack[-1];
    v43 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* dipprodin */
        return (*qfn2(fn))(qenv(fn), v94, v43);
    }

v46:
    v94 = stack[0];
    v43 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* dipprodin */
        return (*qfn2(fn))(qenv(fn), v94, v43);
    }
/* error exit handlers */
v155:
    popv(4);
    return nil;
}



/* Code for ordexp */

static Lisp_Object CC_ordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v65, v106, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v1;
    v106 = v0;
/* end of prologue */

v80:
    v111 = v106;
    if (v111 == nil) goto v84;
    v111 = v106;
    v24 = qcar(v111);
    v111 = v65;
    v111 = qcar(v111);
    if (v24 == v111) goto v45;
    v111 = v106;
    v111 = qcar(v111);
    if (v111 == nil) goto v26;
    v111 = v65;
    v111 = qcar(v111);
    if (v111 == nil) goto v114;
    v111 = v106;
    v111 = qcar(v111);
    v65 = qcar(v65);
    {
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v111, v65);
    }

v114:
    v111 = qvalue(elt(env, 1)); /* t */
    return onevalue(v111);

v26:
    v111 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v111);

v45:
    v111 = v106;
    v111 = qcdr(v111);
    v106 = v111;
    v111 = v65;
    v111 = qcdr(v111);
    v65 = v111;
    goto v80;

v84:
    v111 = qvalue(elt(env, 1)); /* t */
    return onevalue(v111);
}



/* Code for edge_new_parent */

static Lisp_Object CC_edge_new_parent(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v23, v146;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edge_new_parent");
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
    v23 = v0;
/* end of prologue */

v154:
    v155 = v23;
    if (v155 == nil) goto v81;
    v155 = v23;
    v146 = qcar(v155);
    v155 = qvalue(elt(env, 2)); /* new_edge_list */
    v155 = Lassoc(nil, v146, v155);
    v146 = v155;
    v155 = v146;
    if (v155 == nil) goto v43;
    stack[0] = v146;
    v155 = v23;
    v155 = qcdr(v155);
    v155 = CC_edge_new_parent(env, v155);
    nil = C_nil;
    if (exception_pending()) goto v152;
    {
        Lisp_Object v96 = stack[0];
        popv(1);
        return cons(v96, v155);
    }

v43:
    v155 = v23;
    v155 = qcdr(v155);
    v23 = v155;
    goto v154;

v81:
    v155 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v155); }
/* error exit handlers */
v152:
    popv(1);
    return nil;
}



/* Code for comblog */

static Lisp_Object CC_comblog(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comblog");
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
    goto v80;

v80:
    v58 = stack[0];
    if (!consp(v58)) goto v40;
    v58 = stack[0];
    v88 = qcar(v58);
    v58 = qvalue(elt(env, 1)); /* domainlist!* */
    v58 = Lmemq(nil, v88, v58);
    if (!(v58 == nil)) goto v40;
    v58 = stack[0];
    v88 = qcar(v58);
    v58 = elt(env, 2); /* plus */
    if (v88 == v58) goto v20;
    v58 = stack[0];
    v88 = qcar(v58);
    v58 = elt(env, 3); /* times */
    if (!(v88 == v58)) goto v282;
    v58 = stack[0];
    fn = elt(env, 6); /* simp!* */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    v58 = qcar(v58);
    v88 = v58;
    v58 = v88;
    if (!consp(v58)) goto v69;
    v58 = v88;
    v58 = qcar(v58);
    if (!consp(v58)) goto v69;
    v58 = v88;
    v58 = qcar(v58);
    v58 = qcar(v58);
    v88 = qcar(v58);
    v58 = elt(env, 5); /* log */
    v58 = Leqcar(nil, v88, v58);
    env = stack[-2];
    goto v113;

v113:
    if (!(v58 == nil)) goto v20;

v282:
    v58 = stack[0];
    v58 = qcar(v58);
    v88 = CC_comblog(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    v58 = stack[-1];
    v58 = cons(v88, v58);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    stack[-1] = v58;
    v58 = stack[0];
    v58 = qcdr(v58);
    stack[0] = v58;
    goto v80;

v20:
    v58 = stack[0];
    fn = elt(env, 6); /* simp!* */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    fn = elt(env, 7); /* clogsq */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    fn = elt(env, 8); /* prepsq!* */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    {
        Lisp_Object v18 = stack[-1];
        popv(3);
        fn = elt(env, 9); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v18, v58);
    }

v69:
    v58 = qvalue(elt(env, 4)); /* nil */
    goto v113;

v40:
    v88 = stack[-1];
    v58 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v88, v58);
    }
/* error exit handlers */
v141:
    popv(3);
    return nil;
}



setup_type const u19_setup[] =
{
    {"ibalp_var-satlist",       too_few_2,      CC_ibalp_varKsatlist,wrong_no_2},
    {"bvarml",                  CC_bvarml,      too_many_1,    wrong_no_1},
    {"bcneg",                   CC_bcneg,       too_many_1,    wrong_no_1},
    {"random",                  CC_random,      too_many_1,    wrong_no_1},
    {"*di2q0",                  too_few_2,      CC_Hdi2q0,     wrong_no_2},
    {"resimpf",                 CC_resimpf,     too_many_1,    wrong_no_1},
    {"ibalp_getupl",            CC_ibalp_getupl,too_many_1,    wrong_no_1},
    {"encodeir",                CC_encodeir,    too_many_1,    wrong_no_1},
    {"dip2vdp",                 CC_dip2vdp,     too_many_1,    wrong_no_1},
    {"lispassignp",             CC_lispassignp, too_many_1,    wrong_no_1},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"fieldconv",               too_few_2,      CC_fieldconv,  wrong_no_2},
    {"simpcv",                  too_few_2,      CC_simpcv,     wrong_no_2},
    {"ibalp_clmember",          too_few_2,      CC_ibalp_clmember,wrong_no_2},
    {"row",                     CC_row,         too_many_1,    wrong_no_1},
    {"bcfd",                    CC_bcfd,        too_many_1,    wrong_no_1},
    {"freeindexchk",            CC_freeindexchk,too_many_1,    wrong_no_1},
    {"equalreval",              CC_equalreval,  too_many_1,    wrong_no_1},
    {"physopordchk*",           too_few_2,      CC_physopordchkH,wrong_no_2},
    {"red=subst1",              too_few_2,      CC_redMsubst1, wrong_no_2},
    {"st_consolidate",          CC_st_consolidate,too_many_1,  wrong_no_1},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"wusort",                  CC_wusort,      too_many_1,    wrong_no_1},
    {"gck2",                    too_few_2,      CC_gck2,       wrong_no_2},
    {"ibalp_minclnr",           CC_ibalp_minclnr,too_many_1,   wrong_no_1},
    {"mml2ir",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mml2ir},
    {"initarg",                 CC_initarg,     too_many_1,    wrong_no_1},
    {"dipevlcomp",              too_few_2,      CC_dipevlcomp, wrong_no_2},
    {"gbfdot",                  too_few_2,      CC_gbfdot,     wrong_no_2},
    {"prop-simp1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_propKsimp1},
    {"red_totalred",            too_few_2,      CC_red_totalred,wrong_no_2},
    {"exptsq",                  too_few_2,      CC_exptsq,     wrong_no_2},
    {"mo_comp",                 CC_mo_comp,     too_many_1,    wrong_no_1},
    {"get-denom-ll",            too_few_2,      CC_getKdenomKll,wrong_no_2},
    {"binaryrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_binaryrd},
    {"meq",                     too_few_2,      CC_meq,        wrong_no_2},
    {"dip-nc-ev-prod1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod1},
    {"vdpsave",                 CC_vdpsave,     too_many_1,    wrong_no_1},
    {"partitexdf",              CC_partitexdf,  too_many_1,    wrong_no_1},
    {"permp",                   too_few_2,      CC_permp,      wrong_no_2},
    {"ordop2",                  too_few_2,      CC_ordop2,     wrong_no_2},
    {"def_edge",                too_few_2,      CC_def_edge,   wrong_no_2},
    {"mo_equal?",               too_few_2,      CC_mo_equalW,  wrong_no_2},
    {"st_sorttree",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree},
    {"use-berlekamp",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_useKberlekamp},
    {"mk+trace",                CC_mkLtrace,    too_many_1,    wrong_no_1},
    {"command",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_command},
    {"simpdf*",                 CC_simpdfH,     too_many_1,    wrong_no_1},
    {"embed-null-fn",           CC_embedKnullKfn,too_many_1,   wrong_no_1},
    {"dipprod",                 too_few_2,      CC_dipprod,    wrong_no_2},
    {"ordexp",                  too_few_2,      CC_ordexp,     wrong_no_2},
    {"edge_new_parent",         CC_edge_new_parent,too_many_1, wrong_no_1},
    {"comblog",                 CC_comblog,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u19", (two_args *)"22908 234396 1998750", 0}
};

/* end of generated code */
