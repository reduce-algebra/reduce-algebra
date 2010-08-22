
/* $destdir/generated-c\u43.c Machine generated C code */

/* Signature: 00000000 21-Aug-2010 */

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


/* Code for reduce!-eival!-powers1 */

static Lisp_Object CC_reduceKeivalKpowers1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-eival-powers1");
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

v32:
    v30 = stack[0];
    v30 = qcar(v30);
    if (!consp(v30)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    if (!consp(v30)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    v31 = qcdr(v30);
    v30 = stack[-1];
    v30 = qcar(v30);
    v30 = qcdr(v30);
    v30 = (Lisp_Object)lessp2(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v30 = v30 ? lisp_true : nil;
    env = stack[-3];
    if (!(v30 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    v31 = qcdr(v30);
    v30 = stack[-1];
    v30 = qcar(v30);
    v30 = qcdr(v30);
    if (equal(v31, v30)) goto v34;
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    stack[-2] = qcar(v30);
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    v31 = qcdr(v30);
    v30 = stack[-1];
    v30 = qcar(v30);
    v30 = qcdr(v30);
    v30 = difference2(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    fn = elt(env, 1); /* to */
    v31 = (*qfn2(fn))(qenv(fn), stack[-2], v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v30 = (Lisp_Object)17; /* 1 */
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v31 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcdr(v30);
    fn = elt(env, 2); /* multf */
    v31 = (*qfn2(fn))(qenv(fn), v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v30 = stack[0];
    v30 = qcdr(v30);
    v31 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v30 = stack[-1];
    v30 = qcdr(v30);
    fn = elt(env, 3); /* multsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v30 = stack[0];
    v30 = qcar(v30);
    v31 = qcdr(v30);
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    fn = elt(env, 4); /* addsq */
    v30 = (*qfn2(fn))(qenv(fn), stack[-2], v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    stack[0] = v30;
    goto v32;

v34:
    v30 = stack[-1];
    stack[-1] = qcdr(v30);
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v31 = qcdr(v30);
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    fn = elt(env, 3); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v30 = stack[0];
    v30 = qcar(v30);
    v31 = qcdr(v30);
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    {
        Lisp_Object v35 = stack[-1];
        popv(4);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v35, v30);
    }
/* error exit handlers */
v33:
    popv(4);
    return nil;
}



/* Code for ezgcd!-comfac */

static Lisp_Object CC_ezgcdKcomfac(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v50, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ezgcd-comfac");
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
    v9 = stack[-1];
    if (!consp(v9)) goto v51;
    v9 = stack[-1];
    v9 = qcar(v9);
    if (!consp(v9)) goto v51;
    v9 = stack[-1];
    v9 = qcdr(v9);
    if (v9 == nil) goto v52;
    stack[-2] = nil;
    v7 = nil;
    v9 = stack[-1];
    v9 = qcar(v9);
    v9 = qcar(v9);
    v9 = qcar(v9);
    stack[0] = v9;
    goto v34;

v34:
    v9 = stack[-1];
    v9 = qcar(v9);
    v9 = qcar(v9);
    v50 = qcar(v9);
    v9 = stack[0];
    if (!(equal(v50, v9))) goto v53;
    v9 = stack[-1];
    v9 = qcdr(v9);
    if (!consp(v9)) goto v53;
    v9 = stack[-1];
    v9 = qcdr(v9);
    v9 = qcar(v9);
    if (!consp(v9)) goto v53;
    v9 = stack[-1];
    v9 = qcar(v9);
    v9 = qcdr(v9);
    v50 = v7;
    v9 = cons(v9, v50);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v7 = v9;
    v9 = stack[-1];
    v9 = qcdr(v9);
    stack[-1] = v9;
    goto v34;

v53:
    v9 = stack[-1];
    v9 = qcar(v9);
    v9 = qcar(v9);
    v50 = qcar(v9);
    v9 = stack[0];
    if (equal(v50, v9)) goto v55;
    v9 = stack[-1];
    v50 = v7;
    v9 = cons(v9, v50);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v7 = v9;
    goto v56;

v56:
    stack[0] = stack[-2];
    v9 = v7;
    fn = elt(env, 2); /* gcdlist */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v54;
    {
        Lisp_Object v57 = stack[0];
        popv(4);
        return cons(v57, v9);
    }

v55:
    v9 = stack[-1];
    v9 = qcar(v9);
    v9 = qcdr(v9);
    v50 = v7;
    v9 = cons(v9, v50);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v7 = v9;
    v9 = stack[-1];
    v9 = qcdr(v9);
    if (v9 == nil) goto v58;
    v9 = stack[-1];
    v9 = qcdr(v9);
    v50 = v7;
    v9 = cons(v9, v50);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v7 = v9;
    goto v56;

v58:
    v9 = stack[-1];
    v9 = qcar(v9);
    v9 = qcar(v9);
    stack[-2] = v9;
    goto v56;

v52:
    v9 = stack[-1];
    v9 = qcar(v9);
    stack[0] = qcar(v9);
    v9 = stack[-1];
    v9 = qcar(v9);
    v9 = qcdr(v9);
    fn = elt(env, 3); /* poly!-abs */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v54;
    {
        Lisp_Object v59 = stack[0];
        popv(4);
        return cons(v59, v9);
    }

v51:
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v9 = stack[-1];
    fn = elt(env, 3); /* poly!-abs */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v54;
    {
        Lisp_Object v60 = stack[0];
        popv(4);
        return cons(v60, v9);
    }
/* error exit handlers */
v54:
    popv(4);
    return nil;
}



/* Code for cl_applysac2 */

static Lisp_Object MS_CDECL CC_cl_applysac2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v61, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_applysac2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac2");
#endif
    if (stack >= stacklimit)
    {
        push3(v61,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v61);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v61;
    v60 = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v59 = v60;
    if (v59 == nil) goto v80;
    v59 = v60;
    stack[0] = v59;
    goto v52;

v52:
    v59 = stack[0];
    if (v59 == nil) goto v81;
    v79 = stack[-2];
    v59 = stack[0];
    v60 = qcar(v59);
    v59 = stack[-1];
    fn = elt(env, 7); /* cl_subandcut */
    v60 = (*qfnn(fn))(qenv(fn), 3, v79, v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    stack[-3] = v60;
    v59 = elt(env, 2); /* keep1 */
    if (!(v60 == v59)) goto v81;
    v59 = stack[0];
    v59 = qcdr(v59);
    stack[0] = v59;
    goto v52;

v81:
    v59 = stack[-3];
    if (v59 == nil) goto v34;
    v59 = stack[0];
    if (v59 == nil) goto v82;
    v60 = stack[-3];
    v59 = elt(env, 5); /* keep2 */
    if (v60 == v59) goto v83;
    v60 = stack[-3];
    v59 = elt(env, 6); /* failed */
    if (v60 == v59) goto v84;
    v79 = qvalue(elt(env, 3)); /* nil */
    v60 = stack[-3];
    v59 = stack[0];
    v59 = qcdr(v59);
    popv(5);
    return acons(v79, v60, v59);

v84:
    v79 = stack[-2];
    v59 = stack[0];
    v60 = qcdr(v59);
    v59 = stack[-1];
    v59 = CC_cl_applysac2(env, 3, v79, v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    stack[-3] = v59;
    v60 = stack[-3];
    v59 = elt(env, 4); /* break */
    if (v60 == v59) goto v15;
    v60 = stack[0];
    v59 = stack[-3];
    v59 = qcdr(v59);
    fn = elt(env, 8); /* setcdr */
    v59 = (*qfn2(fn))(qenv(fn), v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v31;
    v59 = stack[-3];
    v60 = qcar(v59);
    v59 = stack[0];
    popv(5);
    return cons(v60, v59);

v15:
    v59 = elt(env, 4); /* break */
    { popv(5); return onevalue(v59); }

v83:
    v60 = qvalue(elt(env, 3)); /* nil */
    v59 = stack[0];
    popv(5);
    return cons(v60, v59);

v82:
    v60 = qvalue(elt(env, 1)); /* t */
    v59 = stack[-2];
    v59 = cons(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v31;
    popv(5);
    return ncons(v59);

v34:
    v59 = elt(env, 4); /* break */
    { popv(5); return onevalue(v59); }

v80:
    v60 = qvalue(elt(env, 1)); /* t */
    v59 = stack[-2];
    v59 = cons(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v31;
    popv(5);
    return ncons(v59);
/* error exit handlers */
v31:
    popv(5);
    return nil;
}



/* Code for acfsf_0mk2 */

static Lisp_Object CC_acfsf_0mk2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v80, v88;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for acfsf_0mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v1;
    v80 = v0;
/* end of prologue */
    v88 = qvalue(elt(env, 1)); /* nil */
    return list3(v80, v87, v88);
}



/* Code for ps!:find!-order1 */

static Lisp_Object CC_psTfindKorder1(Lisp_Object env,
                         Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:find-order1");
#endif
    if (stack >= stacklimit)
    {
        push(v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v111 = v1;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v111; /* ps */
    v111 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 9); /* ps!:order */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-3] = v111;
    v111 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 10); /* ps!:last!-term */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v112 = stack[-3];
    v111 = (Lisp_Object)lesseq2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v111 = v111 ? lisp_true : nil;
    env = stack[-5];
    if (v111 == nil) goto v115;
    v111 = stack[-3];
    goto v32;

v32:
    qvalue(elt(env, 1)) = stack[-4]; /* ps */
    { popv(6); return onevalue(v111); }

v115:
    v112 = qvalue(elt(env, 1)); /* ps */
    v111 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 11); /* ps!:getv */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v111 = qcar(v111);
    v112 = v111;
    v111 = elt(env, 2); /* ps!:order!-fn */
    stack[0] = get(v112, v111);
    env = stack[-5];
    v111 = qvalue(elt(env, 1)); /* ps */
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    fn = elt(env, 12); /* apply */
    v111 = (*qfn2(fn))(qenv(fn), stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-3] = v111;
    v113 = qvalue(elt(env, 1)); /* ps */
    v112 = (Lisp_Object)1; /* 0 */
    v111 = stack[-3];
    fn = elt(env, 13); /* ps!:putv */
    v111 = (*qfnn(fn))(qenv(fn), 3, v113, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-1] = qvalue(elt(env, 1)); /* ps */
    stack[0] = (Lisp_Object)17; /* 1 */
    v111 = stack[-3];
    v111 = sub1(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    fn = elt(env, 13); /* ps!:putv */
    v111 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v111 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 14); /* ps!:value */
    v112 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v111 = (Lisp_Object)1; /* 0 */
    if (!(v112 == v111)) goto v116;
    v111 = (Lisp_Object)1; /* 0 */
    stack[-3] = v111;
    v113 = qvalue(elt(env, 1)); /* ps */
    v112 = (Lisp_Object)17; /* 1 */
    v111 = qvalue(elt(env, 3)); /* ps!:max!-order */
    fn = elt(env, 13); /* ps!:putv */
    v111 = (*qfnn(fn))(qenv(fn), 3, v113, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    goto v117;

v117:
    v111 = stack[-3];
    goto v32;

v116:
    v112 = qvalue(elt(env, 1)); /* ps */
    v111 = stack[-3];
    fn = elt(env, 15); /* ps!:evaluate!-next */
    stack[0] = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v112 = qvalue(elt(env, 4)); /* nil */
    v111 = (Lisp_Object)17; /* 1 */
    v111 = cons(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    if (!(equal(stack[0], v111))) goto v117;
    v111 = stack[-3];
    v111 = add1(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-3] = v111;
    v112 = stack[-3];
    v111 = qvalue(elt(env, 5)); /* ps!:order!-limit */
    v111 = (Lisp_Object)greaterp2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v111 = v111 ? lisp_true : nil;
    env = stack[-5];
    if (v111 == nil) goto v116;
    stack[-2] = elt(env, 6); /* tps */
    stack[-1] = (Lisp_Object)353; /* 22 */
    stack[0] = elt(env, 7); /* "Expression " */
    v111 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 14); /* ps!:value */
    v113 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v112 = elt(env, 8); /* " has zero expansion to order " */
    v111 = stack[-3];
    v111 = list4(stack[0], v113, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    fn = elt(env, 16); /* rerror */
    v111 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    goto v116;
/* error exit handlers */
v114:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* ps */
    popv(6);
    return nil;
}



/* Code for expttermp */

static Lisp_Object CC_expttermp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v120, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expttermp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v120 = v1;
    v74 = v0;
/* end of prologue */
    v107 = v74;
    v106 = elt(env, 1); /* expt */
    if (!consp(v107)) goto v121;
    v107 = qcar(v107);
    if (!(v107 == v106)) goto v121;
    v106 = v74;
    v106 = qcdr(v106);
    v106 = qcar(v106);
    v107 = v120;
    {
        fn = elt(env, 2); /* expttermp1 */
        return (*qfn2(fn))(qenv(fn), v106, v107);
    }

v121:
    v106 = v74;
    v107 = v120;
    {
        fn = elt(env, 2); /* expttermp1 */
        return (*qfn2(fn))(qenv(fn), v106, v107);
    }
}



/* Code for xvarp */

static Lisp_Object CC_xvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v21, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xvarp");
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
    v21 = qvalue(elt(env, 1)); /* xvars!* */
    v44 = qvalue(elt(env, 2)); /* t */
    if (equal(v21, v44)) goto v32;
    v44 = stack[0];
    fn = elt(env, 7); /* xdegree */
    v21 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    v44 = (Lisp_Object)1; /* 0 */
    v44 = Lneq(nil, v21, v44);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    if (!(v44 == nil)) { popv(2); return onevalue(v44); }
    v44 = stack[0];
    v21 = qvalue(elt(env, 1)); /* xvars!* */
    v44 = Lmemq(nil, v44, v21);
    { popv(2); return onevalue(v44); }

v32:
    v44 = stack[0];
    if (!consp(v44)) goto v120;
    v44 = stack[0];
    v21 = qcar(v44);
    v44 = elt(env, 4); /* indexvar */
    v44 = Lflagp(nil, v21, v44);
    env = stack[-1];
    if (v44 == nil) goto v19;
    v44 = stack[0];
    v44 = qcdr(v44);
    v83 = Llength(nil, v44);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    v44 = stack[0];
    v21 = qcar(v44);
    v44 = elt(env, 5); /* ifdegree */
    v44 = get(v21, v44);
    v44 = Lassoc(nil, v83, v44);
    { popv(2); return onevalue(v44); }

v19:
    v44 = stack[0];
    v44 = qcar(v44);
    v21 = elt(env, 6); /* (wedge d partdf hodge innerprod liedf) */
    v44 = Lmemq(nil, v44, v21);
    { popv(2); return onevalue(v44); }

v120:
    v44 = stack[0];
    v21 = elt(env, 3); /* fdegree */
    popv(2);
    return get(v44, v21);
/* error exit handlers */
v101:
    popv(2);
    return nil;
}



/* Code for partitpartdf */

static Lisp_Object CC_partitpartdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitpartdf");
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
    v52 = v0;
/* end of prologue */
    v81 = v52;
    v81 = qcdr(v81);
    if (v81 == nil) goto v62;
    stack[0] = (Lisp_Object)17; /* 1 */
    v81 = v52;
    fn = elt(env, 1); /* simppartdf0 */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v81 = cons(stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v109;
    popv(2);
    return ncons(v81);

v62:
    v81 = v52;
    v81 = qcar(v81);
    fn = elt(env, 2); /* !*a2k */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* mknatvec */
        return (*qfn1(fn))(qenv(fn), v81);
    }
/* error exit handlers */
v109:
    popv(2);
    return nil;
}



/* Code for listsub */

static Lisp_Object CC_listsub(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listsub");
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
    v134 = v1;
    stack[-3] = v0;
/* end of prologue */
    v134 = qcdr(v134);
    stack[-4] = v134;
    v134 = stack[-4];
    if (v134 == nil) goto v87;
    v134 = stack[-4];
    v134 = qcar(v134);
    v124 = stack[-3];
    fn = elt(env, 2); /* subeval1 */
    v134 = (*qfn2(fn))(qenv(fn), v124, v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v134 = ncons(v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    stack[-1] = v134;
    stack[-2] = v134;
    goto v110;

v110:
    v134 = stack[-4];
    v134 = qcdr(v134);
    stack[-4] = v134;
    v134 = stack[-4];
    if (v134 == nil) goto v118;
    stack[0] = stack[-1];
    v134 = stack[-4];
    v134 = qcar(v134);
    v124 = stack[-3];
    fn = elt(env, 2); /* subeval1 */
    v134 = (*qfn2(fn))(qenv(fn), v124, v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v134 = ncons(v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v134 = Lrplacd(nil, stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v134 = stack[-1];
    v134 = qcdr(v134);
    stack[-1] = v134;
    goto v110;

v118:
    v134 = stack[-2];
    goto v91;

v91:
    {
        popv(6);
        fn = elt(env, 3); /* makelist */
        return (*qfn1(fn))(qenv(fn), v134);
    }

v87:
    v134 = qvalue(elt(env, 1)); /* nil */
    goto v91;
/* error exit handlers */
v135:
    popv(6);
    return nil;
}



/* Code for modroots2 */

static Lisp_Object MS_CDECL CC_modroots2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v61, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v143, v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "modroots2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modroots2");
#endif
    if (stack >= stacklimit)
    {
        push3(v61,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v61);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v98 = v61;
    stack[-3] = v1;
    v99 = v0;
/* end of prologue */
    v12 = v99;
    if (!consp(v12)) goto v91;
    v12 = v99;
    v12 = qcar(v12);
    if (!(!consp(v12))) goto v105;

v91:
    v12 = v99;
    if (v12 == nil) goto v105;
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v12); }

v105:
    v12 = v99;
    if (v12 == nil) goto v52;
    v143 = stack[-3];
    v12 = (Lisp_Object)33; /* 2 */
    if (v143 == v12) goto v42;
    v143 = v99;
    v12 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* modroots3 */
        return (*qfn2(fn))(qenv(fn), v143, v12);
    }

v42:
    v143 = v99;
    v12 = qvalue(elt(env, 3)); /* t */
    {
        popv(6);
        fn = elt(env, 5); /* modroots4 */
        return (*qfnn(fn))(qenv(fn), 3, v143, v12, v98);
    }

v52:
    v143 = stack[-3];
    v12 = (Lisp_Object)33; /* 2 */
    if (!(v143 == v12)) goto v106;
    v12 = v98;
    if (v12 == nil) goto v106;
    v12 = elt(env, 2); /* (-1 0 1) */
    { popv(6); return onevalue(v12); }

v106:
    v12 = (Lisp_Object)1; /* 0 */
    stack[-4] = v12;
    v12 = stack[-3];
    v143 = sub1(v12);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v12 = stack[-4];
    v12 = difference2(v143, v12);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v12 = Lminusp(nil, v12);
    env = stack[-5];
    if (v12 == nil) goto v26;
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v12); }

v26:
    v12 = stack[-4];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[-1] = v12;
    stack[-2] = v12;
    goto v130;

v130:
    v12 = stack[-4];
    v12 = add1(v12);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[-4] = v12;
    v12 = stack[-3];
    v143 = sub1(v12);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v12 = stack[-4];
    v12 = difference2(v143, v12);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v12 = Lminusp(nil, v12);
    env = stack[-5];
    if (!(v12 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v12 = stack[-4];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v12 = Lrplacd(nil, stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v12 = stack[-1];
    v12 = qcdr(v12);
    stack[-1] = v12;
    goto v130;
/* error exit handlers */
v144:
    popv(6);
    return nil;
}



/* Code for rl_qe */

static Lisp_Object CC_rl_qe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_qe");
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
    v145 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_qe!* */
    v48 = list2(v145, v48);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    {
        Lisp_Object v132 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v132, v48);
    }
/* error exit handlers */
v78:
    popv(2);
    return nil;
}



/* Code for preptaycoeff */

static Lisp_Object CC_preptaycoeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v97, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaycoeff");
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
    stack[-6] = nil;
    goto v91;

v91:
    v99 = stack[-4];
    if (v99 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v99 = stack[-5];
    v99 = qcar(v99);
    stack[-3] = v99;
    v99 = stack[-4];
    v99 = qcar(v99);
    v99 = qcar(v99);
    stack[-2] = v99;
    goto v119;

v119:
    v99 = stack[-2];
    if (v99 == nil) goto v132;
    v99 = stack[-2];
    v99 = qcar(v99);
    v68 = v99;
    v99 = stack[-4];
    v99 = qcar(v99);
    v99 = qcdr(v99);
    v97 = qcar(v99);
    v99 = elt(env, 2); /* infinity */
    if (v97 == v99) goto v124;
    stack[0] = v68;
    v99 = stack[-4];
    v99 = qcar(v99);
    v99 = qcdr(v99);
    v99 = qcar(v99);
    fn = elt(env, 4); /* reval */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    fn = elt(env, 5); /* checkdifference */
    v97 = (*qfn2(fn))(qenv(fn), stack[0], v99);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v99 = stack[-3];
    v99 = qcar(v99);
    fn = elt(env, 6); /* checkexp */
    v99 = (*qfn2(fn))(qenv(fn), v97, v99);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v97 = v99;
    goto v38;

v38:
    v99 = stack[-6];
    v99 = cons(v97, v99);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    stack[-6] = v99;
    v99 = stack[-3];
    v99 = qcdr(v99);
    stack[-3] = v99;
    v99 = stack[-2];
    v99 = qcdr(v99);
    stack[-2] = v99;
    goto v119;

v124:
    v99 = stack[-3];
    v97 = qcar(v99);
    v99 = (Lisp_Object)1; /* 0 */
    if (v97 == v99) goto v154;
    stack[-1] = elt(env, 3); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v97 = v68;
    v99 = stack[-3];
    v99 = qcar(v99);
    fn = elt(env, 6); /* checkexp */
    v99 = (*qfn2(fn))(qenv(fn), v97, v99);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v99 = list3(stack[-1], stack[0], v99);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    goto v142;

v142:
    v97 = v99;
    goto v38;

v154:
    v99 = (Lisp_Object)17; /* 1 */
    goto v142;

v132:
    v99 = stack[-5];
    v99 = qcdr(v99);
    stack[-5] = v99;
    v99 = stack[-4];
    v99 = qcdr(v99);
    stack[-4] = v99;
    goto v91;
/* error exit handlers */
v153:
    popv(8);
    return nil;
}



/* Code for mkarg */

static Lisp_Object CC_mkarg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarg");
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
    v44 = stack[-1];
    if (v44 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v44 = stack[-1];
    v44 = Lconstantp(nil, v44);
    env = stack[-3];
    if (!(v44 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v44 = stack[-1];
    if (!consp(v44)) goto v77;
    v44 = stack[-1];
    v21 = qcar(v44);
    v44 = elt(env, 1); /* (quote !:dn!: !:int!:) */
    v44 = Lmemq(nil, v21, v44);
    if (v44 == nil) goto v76;
    v44 = stack[-1];
        popv(4);
        return Lmkquote(nil, v44);

v76:
    stack[-2] = nil;
    goto v104;

v104:
    v44 = stack[-1];
    if (v44 == nil) goto v154;
    v44 = stack[-1];
    v21 = qcar(v44);
    v44 = stack[0];
    v21 = CC_mkarg(env, v21, v44);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    v44 = stack[-2];
    v44 = cons(v21, v44);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    stack[-2] = v44;
    v44 = stack[-1];
    v44 = qcdr(v44);
    stack[-1] = v44;
    goto v104;

v154:
    stack[0] = elt(env, 2); /* list */
    v44 = stack[-2];
    fn = elt(env, 3); /* reversip!* */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v152;
    {
        Lisp_Object v155 = stack[0];
        popv(4);
        return cons(v155, v44);
    }

v77:
    v21 = stack[-1];
    v44 = stack[0];
    v44 = Latsoc(nil, v21, v44);
    if (!(v44 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v44 = stack[-1];
        popv(4);
        return Lmkquote(nil, v44);
/* error exit handlers */
v152:
    popv(4);
    return nil;
}



/* Code for ratnump */

static Lisp_Object CC_ratnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratnump");
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
    v80 = v0;
/* end of prologue */
    fn = elt(env, 2); /* simp!* */
    v88 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[0];
    v80 = v88;
    v88 = qcar(v88);
    if (!consp(v88)) goto v90;
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v80); }

v90:
    v80 = qcdr(v80);
    v80 = (consp(v80) ? nil : lisp_true);
    { popv(1); return onevalue(v80); }
/* error exit handlers */
v49:
    popv(1);
    return nil;
}



/* Code for rm_neg_pow */

static Lisp_Object CC_rm_neg_pow(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rm_neg_pow");
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
    if (!consp(v116)) goto v51;
    v116 = stack[-1];
    v116 = qcar(v116);
    if (!consp(v116)) goto v51;
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = Lminusp(nil, v116);
    env = stack[-3];
    if (v116 == nil) goto v42;
    stack[-2] = (Lisp_Object)17; /* 1 */
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcar(v116);
    stack[0] = qcar(v116);
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = negate(v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    fn = elt(env, 2); /* to */
    v84 = (*qfn2(fn))(qenv(fn), stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v116 = (Lisp_Object)17; /* 1 */
    v84 = cons(v84, v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v116 = qvalue(elt(env, 1)); /* nil */
    stack[0] = list2star(stack[-2], v84, v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = CC_rm_neg_pow(env, v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    fn = elt(env, 3); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v116 = stack[-1];
    v116 = qcdr(v116);
    v116 = CC_rm_neg_pow(env, v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    {
        Lisp_Object v99 = stack[0];
        popv(4);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v99, v116);
    }

v42:
    v116 = stack[-1];
    v116 = qcar(v116);
    v84 = qcar(v116);
    v116 = (Lisp_Object)17; /* 1 */
    v116 = cons(v84, v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v84 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v116 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v84, v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = CC_rm_neg_pow(env, v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    fn = elt(env, 3); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v116 = stack[-1];
    v116 = qcdr(v116);
    v116 = CC_rm_neg_pow(env, v116);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    {
        Lisp_Object v97 = stack[0];
        popv(4);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v97, v116);
    }

v51:
    v84 = stack[-1];
    v116 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v84, v116);
/* error exit handlers */
v98:
    popv(4);
    return nil;
}



/* Code for mkuniquewedge1 */

static Lisp_Object CC_mkuniquewedge1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuniquewedge1");
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
    v74 = stack[0];
    v74 = qcdr(v74);
    if (v74 == nil) goto v62;
    v74 = qvalue(elt(env, 1)); /* wedgemtch!* */
    if (v74 == nil) goto v131;
    v74 = stack[0];
    fn = elt(env, 3); /* wedgemtch */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    v38 = v74;
    if (v74 == nil) goto v131;
    v74 = v38;
    {
        popv(2);
        fn = elt(env, 4); /* partitop */
        return (*qfn1(fn))(qenv(fn), v74);
    }

v131:
    v38 = elt(env, 2); /* wedge */
    v74 = stack[0];
    v74 = cons(v38, v74);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v74);
    }

v62:
    v74 = stack[0];
    v74 = qcar(v74);
    {
        popv(2);
        fn = elt(env, 5); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v74);
    }
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for ratmean */

static Lisp_Object CC_ratmean(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v80, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratmean");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v1;
    v80 = v0;
/* end of prologue */
    v88 = v80;
    v80 = v87;
    v87 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* ratplusm */
        return (*qfnn(fn))(qenv(fn), 3, v88, v80, v87);
    }
}



/* Code for coeff_sortl */

static Lisp_Object MS_CDECL CC_coeff_sortl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v61, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v119, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_sortl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_sortl");
#endif
    if (stack >= stacklimit)
    {
        push3(v61,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v61);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v61;
    stack[-1] = v1;
    v132 = v0;
/* end of prologue */
    v119 = v132;
    v132 = stack[0];
    fn = elt(env, 1); /* coeff_ordn */
    v81 = (*qfn2(fn))(qenv(fn), v119, v132);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-2];
    v119 = stack[-1];
    v132 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* coeff_sortl1 */
        return (*qfnn(fn))(qenv(fn), 3, v81, v119, v132);
    }
/* error exit handlers */
v109:
    popv(3);
    return nil;
}



/* Code for degree!-order */

static Lisp_Object CC_degreeKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v74, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degree-order");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v74 = v1;
    v38 = v0;
/* end of prologue */
    v120 = v38;
    if (!consp(v120)) goto v32;
    v120 = v38;
    v120 = qcar(v120);
    if (!consp(v120)) goto v32;
    v120 = v74;
    if (!consp(v120)) goto v86;
    v120 = v74;
    v120 = qcar(v120);
    if (!consp(v120)) goto v86;
    v120 = v38;
    v120 = qcar(v120);
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcdr(v74);
        return Llessp(nil, v120, v74);

v86:
    v120 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v120);

v32:
    v120 = qvalue(elt(env, 1)); /* t */
    return onevalue(v120);
}



/* Code for fillin */

static Lisp_Object CC_fillin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fillin");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v0;
/* end of prologue */
    v78 = v77;
    if (v78 == nil) goto v62;
    v78 = v77;
    v77 = qcar(v77);
    v77 = qcar(v77);
    {
        fn = elt(env, 2); /* fillin1 */
        return (*qfn2(fn))(qenv(fn), v78, v77);
    }

v62:
    v77 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v77);
}



/* Code for find!-null!-space */

static Lisp_Object CC_findKnullKspace(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v127, v128, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find-null-space");
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
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    v103 = (Lisp_Object)17; /* 1 */
    stack[0] = v103;
    goto v80;

v80:
    v127 = stack[-1];
    v103 = stack[0];
    v103 = (Lisp_Object)(int32_t)((int32_t)v127 - (int32_t)v103 + TAG_FIXNUM);
    v103 = ((intptr_t)(v103) < 0 ? lisp_true : nil);
    if (v103 == nil) goto v108;
    v128 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v127 = stack[-2];
    v103 = stack[-1];
    fn = elt(env, 3); /* tidy!-up!-null!-vectors */
    v103 = (*qfnn(fn))(qenv(fn), 3, v128, v127, v103);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v103); }

v108:
    v18 = stack[0];
    v128 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v127 = stack[-2];
    v103 = stack[-1];
    fn = elt(env, 4); /* clear!-column */
    v103 = (*qfnn(fn))(qenv(fn), 4, v18, v128, v127, v103);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-4];
    qvalue(elt(env, 1)) = v103; /* null!-space!-basis */
    v103 = stack[0];
    v103 = (Lisp_Object)((int32_t)(v103) + 0x10);
    stack[0] = v103;
    goto v80;
/* error exit handlers */
v124:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for sqlessp */

static Lisp_Object CC_sqlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqlessp");
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
    v81 = v1;
    v52 = v0;
/* end of prologue */
    stack[0] = v52;
    fn = elt(env, 2); /* negsq */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    fn = elt(env, 3); /* addsq */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v81 = qcar(v81);
    v52 = v81;
    v81 = v52;
    if (v81 == nil) goto v88;
    v81 = v52;
    {
        popv(2);
        fn = elt(env, 4); /* !:minusp */
        return (*qfn1(fn))(qenv(fn), v81);
    }

v88:
    v81 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v81); }
/* error exit handlers */
v109:
    popv(2);
    return nil;
}



/* Code for distribute!.multiplicity */

static Lisp_Object CC_distributeQmultiplicity(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v154;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for distribute.multiplicity");
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
    v142 = v0;
/* end of prologue */
    stack[-4] = v142;
    v142 = stack[-4];
    if (v142 == nil) goto v51;
    v142 = stack[-4];
    v142 = qcar(v142);
    v154 = v142;
    v142 = stack[-3];
    v142 = cons(v154, v142);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-1] = v142;
    stack[-2] = v142;
    goto v91;

v91:
    v142 = stack[-4];
    v142 = qcdr(v142);
    stack[-4] = v142;
    v142 = stack[-4];
    if (v142 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v142 = stack[-4];
    v142 = qcar(v142);
    v154 = v142;
    v142 = stack[-3];
    v142 = cons(v154, v142);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v142 = Lrplacd(nil, stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v142 = stack[-1];
    v142 = qcdr(v142);
    stack[-1] = v142;
    goto v91;

v51:
    v142 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v142); }
/* error exit handlers */
v46:
    popv(6);
    return nil;
}



/* Code for appends */

static Lisp_Object MS_CDECL CC_appends(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v61, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v77, v78;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "appends");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for appends");
#endif
    if (stack >= stacklimit)
    {
        push3(v61,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v61);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v145 = v61;
    v77 = v1;
    v78 = v0;
/* end of prologue */
    stack[0] = v78;
    v145 = Lappend(nil, v77, v145);
    nil = C_nil;
    if (exception_pending()) goto v119;
    {
        Lisp_Object v81 = stack[0];
        popv(1);
        return Lappend(nil, v81, v145);
    }
/* error exit handlers */
v119:
    popv(1);
    return nil;
}



/* Code for dm!-lt */

static Lisp_Object CC_dmKlt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-lt");
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
    v51 = v1;
    v86 = v0;
/* end of prologue */
    fn = elt(env, 1); /* dm!-difference */
    v51 = (*qfn2(fn))(qenv(fn), v86, v51);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !:minusp */
        return (*qfn1(fn))(qenv(fn), v51);
    }
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



/* Code for exdfp0 */

static Lisp_Object CC_exdfp0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v83, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exdfp0");
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
    v83 = v0;
/* end of prologue */
    v21 = v83;
    v21 = qcar(v21);
    stack[0] = v21;
    v21 = v83;
    v21 = qcdr(v21);
    stack[-2] = v21;
    v21 = stack[0];
    fn = elt(env, 3); /* sfp */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    if (!(v21 == nil)) goto v80;
    v21 = stack[0];
    fn = elt(env, 4); /* exformp */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    if (!(v21 == nil)) goto v80;
    v21 = qvalue(elt(env, 1)); /* subfg!* */
    if (!(v21 == nil)) goto v122;

v80:
    v21 = stack[0];
    fn = elt(env, 3); /* sfp */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    if (v21 == nil) goto v47;
    v21 = stack[0];
    fn = elt(env, 5); /* exdff0 */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    goto v108;

v108:
    v151 = v21;
    if (v21 == nil) goto v122;
    v83 = stack[-2];
    v21 = (Lisp_Object)17; /* 1 */
    if (v83 == v21) { popv(4); return onevalue(v151); }
    stack[-1] = v151;
    v21 = stack[-2];
    v21 = sub1(v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 6); /* to */
    v83 = (*qfn2(fn))(qenv(fn), stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v21 = stack[-2];
    v21 = cons(v83, v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v83 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v21 = (Lisp_Object)17; /* 1 */
    v21 = cons(v83, v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    {
        Lisp_Object v71 = stack[-1];
        popv(4);
        fn = elt(env, 7); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v71, v21);
    }

v122:
    v21 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v21); }

v47:
    v21 = stack[0];
    fn = elt(env, 8); /* exdfk */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    goto v108;
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for randpoly */

static Lisp_Object CC_randpoly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v261, v262, v263, v264, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for randpoly");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-14] = v0;
/* end of prologue */
    stack[-15] = nil;
    stack[-12] = nil;
    stack[-7] = nil;
    v261 = elt(env, 1); /* lambda_l7ipth_11 */
    stack[-13] = v261;
    v261 = (Lisp_Object)81; /* 5 */
    stack[-10] = v261;
    v261 = (Lisp_Object)1; /* 0 */
    stack[-9] = v261;
    v261 = (Lisp_Object)97; /* 6 */
    stack[-11] = v261;
    v261 = elt(env, 2); /* sparse */
    stack[-8] = v261;
    stack[-6] = qvalue(elt(env, 3)); /* wtl!* */
    qvalue(elt(env, 3)) = nil; /* wtl!* */
    v261 = stack[-14];
    fn = elt(env, 16); /* revlis */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    stack[-14] = v261;
    v261 = qcar(v261);
    stack[0] = v261;
    v262 = stack[0];
    v261 = elt(env, 4); /* list */
    if (!consp(v262)) goto v38;
    v262 = qcar(v262);
    if (!(v262 == v261)) goto v38;
    v261 = stack[0];
    v261 = qcdr(v261);
    goto v108;

v108:
    stack[0] = v261;
    v261 = stack[0];
    stack[-5] = v261;
    v261 = stack[-5];
    if (v261 == nil) goto v127;
    v261 = stack[-5];
    v261 = qcar(v261);
    stack[-1] = v261;
    v261 = stack[-1];
    fn = elt(env, 17); /* eqexpr */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    if (v261 == nil) goto v82;
    v261 = stack[-1];
    fn = elt(env, 18); /* !*eqn2a */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    stack[-1] = v261;
    v261 = (Lisp_Object)17; /* 1 */
    stack[-9] = v261;
    goto v45;

v45:
    v261 = elt(env, 7); /* g */
    v261 = Lgensym1(nil, v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    stack[0] = v261;
    v263 = elt(env, 8); /* equal */
    v262 = stack[0];
    v261 = stack[-1];
    v262 = list3(v263, v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    v261 = stack[-7];
    v261 = cons(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    stack[-7] = v261;
    v261 = stack[0];
    goto v23;

v23:
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    stack[-3] = v261;
    stack[-4] = v261;
    goto v75;

v75:
    v261 = stack[-5];
    v261 = qcdr(v261);
    stack[-5] = v261;
    v261 = stack[-5];
    if (v261 == nil) goto v147;
    stack[-2] = stack[-3];
    v261 = stack[-5];
    v261 = qcar(v261);
    stack[-1] = v261;
    v261 = stack[-1];
    fn = elt(env, 17); /* eqexpr */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    if (v261 == nil) goto v267;
    v261 = stack[-1];
    fn = elt(env, 18); /* !*eqn2a */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    stack[-1] = v261;
    v261 = (Lisp_Object)17; /* 1 */
    stack[-9] = v261;
    goto v97;

v97:
    v261 = elt(env, 7); /* g */
    v261 = Lgensym1(nil, v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    stack[0] = v261;
    v263 = elt(env, 8); /* equal */
    v262 = stack[0];
    v261 = stack[-1];
    v262 = list3(v263, v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    v261 = stack[-7];
    v261 = cons(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    stack[-7] = v261;
    v261 = stack[0];
    goto v98;

v98:
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    v261 = Lrplacd(nil, stack[-2], v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    goto v75;

v267:
    v261 = stack[-1];
    fn = elt(env, 19); /* simp!* */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    fn = elt(env, 20); /* kernp */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    if (v261 == nil) goto v97;
    v261 = stack[-1];
    goto v98;

v147:
    v261 = stack[-4];
    goto v27;

v27:
    stack[0] = v261;
    v261 = stack[-15];
    if (v261 == nil) goto v78;
    v261 = stack[0];
    v261 = qcar(v261);
    stack[0] = v261;
    goto v78;

v78:
    qvalue(elt(env, 3)) = stack[-6]; /* wtl!* */
    v261 = stack[-14];
    v261 = qcdr(v261);
    stack[-2] = v261;
    goto v35;

v35:
    v261 = stack[-2];
    if (v261 == nil) goto v268;
    v261 = stack[-2];
    v261 = qcar(v261);
    stack[-1] = v261;
    v262 = stack[-1];
    v261 = elt(env, 9); /* dense */
    if (v262 == v261) goto v269;
    v262 = stack[-1];
    v261 = elt(env, 2); /* sparse */
    if (v262 == v261) goto v269;
    v261 = stack[-1];
    fn = elt(env, 17); /* eqexpr */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    if (v261 == nil) goto v271;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v262 = qcar(v261);
    v261 = elt(env, 10); /* coeffs */
    if (!(v262 == v261)) goto v272;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    fn = elt(env, 21); /* functionp */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    if (v261 == nil) goto v272;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    stack[-13] = v261;
    goto v273;

v273:
    if (!(v261 == nil)) goto v274;

v271:
    v262 = stack[-1];
    v261 = elt(env, 15); /* "optional randpoly argument" */
    fn = elt(env, 22); /* typerr */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    goto v274;

v274:
    v261 = stack[-2];
    v261 = qcdr(v261);
    stack[-2] = v261;
    goto v35;

v272:
    v261 = stack[-1];
    v261 = qcdr(v261);
    v262 = qcar(v261);
    v261 = elt(env, 11); /* expons */
    if (!(v262 == v261)) goto v275;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    fn = elt(env, 21); /* functionp */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    if (v261 == nil) goto v275;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    stack[-12] = v261;
    goto v273;

v275:
    v261 = stack[-1];
    v261 = qcdr(v261);
    v262 = qcar(v261);
    v261 = elt(env, 12); /* (degree deg maxdeg) */
    v261 = Lmemq(nil, v262, v261);
    if (v261 == nil) goto v276;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    fn = elt(env, 23); /* natnump */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    if (v261 == nil) goto v276;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    stack[-10] = v261;
    goto v273;

v276:
    v261 = stack[-1];
    v261 = qcdr(v261);
    v262 = qcar(v261);
    v261 = elt(env, 13); /* (ord mindeg) */
    v261 = Lmemq(nil, v262, v261);
    if (v261 == nil) goto v277;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    fn = elt(env, 23); /* natnump */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    if (v261 == nil) goto v277;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    stack[-9] = v261;
    goto v273;

v277:
    v261 = stack[-1];
    v261 = qcdr(v261);
    v262 = qcar(v261);
    v261 = elt(env, 14); /* terms */
    if (!(v262 == v261)) goto v278;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    fn = elt(env, 23); /* natnump */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    if (v261 == nil) goto v278;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    stack[-11] = v261;
    goto v273;

v278:
    v261 = nil;
    goto v273;

v269:
    v261 = stack[-1];
    stack[-8] = v261;
    goto v274;

v268:
    v262 = qvalue(elt(env, 6)); /* nil */
    v261 = (Lisp_Object)17; /* 1 */
    v261 = cons(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = v261;
    v262 = stack[-9];
    v261 = stack[-10];
    v261 = (Lisp_Object)lesseq2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v261 = v261 ? lisp_true : nil;
    env = stack[-16];
    if (v261 == nil) goto v279;
    v262 = stack[-8];
    v261 = elt(env, 2); /* sparse */
    if (v262 == v261) goto v280;
    v261 = stack[-15];
    if (v261 == nil) goto v281;
    v262 = stack[-13];
    v261 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = v261;
    v262 = stack[-9];
    v261 = (Lisp_Object)1; /* 0 */
    v261 = (Lisp_Object)greaterp2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v261 = v261 ? lisp_true : nil;
    env = stack[-16];
    if (v261 == nil) goto v282;
    v262 = stack[0];
    v261 = stack[-9];
    fn = elt(env, 25); /* mksq */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = v261;
    goto v282;

v282:
    v261 = stack[-9];
    v261 = add1(v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-2] = v261;
    goto v283;

v283:
    v262 = stack[-10];
    v261 = stack[-2];
    v261 = difference2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v261 = Lminusp(nil, v261);
    env = stack[-16];
    if (!(v261 == nil)) goto v279;
    stack[-3] = stack[-1];
    v262 = stack[-13];
    v261 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[-1] = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v262 = stack[0];
    v261 = stack[-2];
    fn = elt(env, 25); /* mksq */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-3], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = v261;
    v261 = stack[-2];
    v261 = add1(v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-2] = v261;
    goto v283;

v279:
    v261 = stack[-7];
    if (v261 == nil) { Lisp_Object res = stack[-1]; popv(17); return onevalue(res); }
    stack[0] = stack[-7];
    v261 = stack[-1];
    fn = elt(env, 28); /* mk!*sq */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v261 = Lappend(nil, stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 29); /* subeval */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    {
        popv(17);
        fn = elt(env, 19); /* simp!* */
        return (*qfn1(fn))(qenv(fn), v261);
    }

v281:
    v263 = stack[0];
    v262 = stack[-10];
    v261 = stack[-9];
    fn = elt(env, 30); /* rand!-mons!-dense */
    v261 = (*qfnn(fn))(qenv(fn), 3, v263, v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-3] = v261;
    goto v284;

v284:
    v261 = stack[-3];
    if (v261 == nil) goto v279;
    v261 = stack[-3];
    v261 = qcar(v261);
    stack[-2] = v261;
    v262 = stack[-13];
    v261 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v262 = stack[-2];
    v261 = (Lisp_Object)17; /* 1 */
    v261 = cons(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = v261;
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    goto v284;

v280:
    v261 = stack[-12];
    if (v261 == nil) goto v285;
    v261 = stack[-15];
    if (v261 == nil) goto v286;
    v261 = (Lisp_Object)17; /* 1 */
    stack[-3] = v261;
    goto v287;

v287:
    v262 = stack[-11];
    v261 = stack[-3];
    v261 = difference2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v261 = Lminusp(nil, v261);
    env = stack[-16];
    if (!(v261 == nil)) goto v279;
    stack[-4] = stack[-1];
    v262 = stack[-13];
    v261 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[-2] = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = stack[0];
    v261 = stack[-12];
    fn = elt(env, 31); /* apply_e */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 32); /* !*kp2q */
    v261 = (*qfn2(fn))(qenv(fn), stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-2], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-4], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = v261;
    v261 = stack[-3];
    v261 = add1(v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-3] = v261;
    goto v287;

v286:
    v261 = (Lisp_Object)17; /* 1 */
    stack[-4] = v261;
    goto v288;

v288:
    v262 = stack[-11];
    v261 = stack[-4];
    v261 = difference2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v261 = Lminusp(nil, v261);
    env = stack[-16];
    if (!(v261 == nil)) goto v279;
    v262 = stack[-13];
    v261 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v262 = v261;
    v261 = v262;
    v261 = qcar(v261);
    if (v261 == nil) goto v289;
    stack[-5] = stack[-1];
    v261 = stack[0];
    stack[-3] = v261;
    goto v290;

v290:
    v261 = stack[-3];
    if (v261 == nil) goto v291;
    v261 = stack[-3];
    v261 = qcar(v261);
    stack[-2] = v262;
    stack[-1] = v261;
    v261 = stack[-12];
    fn = elt(env, 31); /* apply_e */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 32); /* !*kp2q */
    v261 = (*qfn2(fn))(qenv(fn), stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-2], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v262 = v261;
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    goto v290;

v291:
    v261 = v262;
    fn = elt(env, 27); /* addsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-5], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = v261;
    goto v289;

v289:
    v261 = stack[-4];
    v261 = add1(v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-4] = v261;
    goto v288;

v285:
    v265 = stack[0];
    v264 = stack[-11];
    v263 = stack[-10];
    v262 = stack[-9];
    v261 = stack[-15];
    fn = elt(env, 33); /* rand!-mons!-sparse */
    v261 = (*qfnn(fn))(qenv(fn), 5, v265, v264, v263, v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-3] = v261;
    goto v292;

v292:
    v261 = stack[-3];
    if (v261 == nil) goto v279;
    v261 = stack[-3];
    v261 = qcar(v261);
    stack[-2] = v261;
    v262 = stack[-13];
    v261 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    v262 = stack[-2];
    v261 = (Lisp_Object)17; /* 1 */
    v261 = cons(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v261 = (*qfn2(fn))(qenv(fn), stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-16];
    stack[-1] = v261;
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    goto v292;

v82:
    v261 = stack[-1];
    fn = elt(env, 19); /* simp!* */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    fn = elt(env, 20); /* kernp */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    if (v261 == nil) goto v45;
    v261 = stack[-1];
    goto v23;

v127:
    v261 = qvalue(elt(env, 6)); /* nil */
    goto v27;

v38:
    v261 = qvalue(elt(env, 5)); /* t */
    stack[-15] = v261;
    v261 = stack[0];
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-16];
    goto v108;
/* error exit handlers */
v270:
    popv(17);
    return nil;
v266:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-6]; /* wtl!* */
    popv(17);
    return nil;
}



/* Code for lambda_l7ipth_11 */

static Lisp_Object MS_CDECL CC_lambda_l7ipth_11(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lambda_l7ipth_11");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l7ipth_11");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* end of prologue */
    v90 = (Lisp_Object)3185; /* 199 */
    fn = elt(env, 1); /* random */
    v85 = (*qfn1(fn))(qenv(fn), v90);
    errexit();
    v90 = (Lisp_Object)1585; /* 99 */
    return difference2(v85, v90);
}



/* Code for noncom1 */

static Lisp_Object CC_noncom1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncom1");
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
    v86 = v0;
/* end of prologue */
    v51 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 2)) = v51; /* !*ncmp */
    v51 = v86;
    v51 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    v86 = elt(env, 3); /* noncom */
        popv(1);
        return Lflag(nil, v51, v86);
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



/* Code for split!-wrt!-variables */

static Lisp_Object MS_CDECL CC_splitKwrtKvariables(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v61, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v44, v21;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-wrt-variables");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-wrt-variables");
#endif
    if (stack >= stacklimit)
    {
        push3(v61,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v61);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v61;
    stack[-1] = v1;
    v44 = v0;
/* end of prologue */

v105:
    v20 = v44;
    if (v20 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v20 = stack[0];
    if (v20 == nil) goto v80;
    v20 = stack[0];
    v21 = qcar(v20);
    v20 = (Lisp_Object)17; /* 1 */
    if (v21 == v20) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else goto v80;

v80:
    v20 = v44;
    if (!consp(v20)) goto v107;
    v20 = v44;
    v20 = qcar(v20);
    if (!consp(v20)) goto v107;
    v20 = v44;
    v20 = qcar(v20);
    v20 = qcar(v20);
    v21 = qcar(v20);
    v20 = stack[-1];
    v20 = Lmember(nil, v21, v20);
    if (v20 == nil) goto v117;
    v20 = v44;
    v20 = qcdr(v20);
    stack[-2] = v20;
    v20 = v44;
    v20 = qcar(v20);
    v21 = qcdr(v20);
    v44 = stack[-1];
    v20 = stack[0];
    v20 = CC_splitKwrtKvariables(env, 3, v21, v44, v20);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    stack[0] = v20;
    v20 = stack[-2];
    v44 = v20;
    goto v105;

v117:
    v20 = stack[0];
    popv(4);
    return cons(v44, v20);

v107:
    v20 = v44;
    v44 = Labsval(nil, v20);
    nil = C_nil;
    if (exception_pending()) goto v152;
    v20 = stack[0];
    popv(4);
    return cons(v44, v20);
/* error exit handlers */
v152:
    popv(4);
    return nil;
}



/* Code for groeb_updatepl */

static Lisp_Object MS_CDECL CC_groeb_updatepl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v61, Lisp_Object v89, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "groeb_updatepl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb_updatepl");
#endif
    if (stack >= stacklimit)
    {
        push4(v89,v61,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v61,v89);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v89;
    stack[-7] = v61;
    stack[0] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    v143 = stack[-7];
    fn = elt(env, 3); /* bas_nr */
    v98 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    v143 = (Lisp_Object)1; /* 0 */
    v143 = Lneq(nil, v98, v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    stack[-3] = v143;
    v143 = stack[-7];
    fn = elt(env, 4); /* bas_dpoly */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    fn = elt(env, 5); /* dp_lmon */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    stack[-4] = v143;
    v143 = stack[-4];
    fn = elt(env, 6); /* mo_comp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    stack[-5] = v143;
    v143 = stack[0];
    stack[-2] = v143;
    goto v121;

v121:
    v143 = stack[-2];
    if (v143 == nil) goto v101;
    v143 = stack[-2];
    v143 = qcar(v143);
    stack[-1] = v143;
    stack[0] = stack[-5];
    v143 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    fn = elt(env, 5); /* dp_lmon */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    fn = elt(env, 6); /* mo_comp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    if (!(equal(stack[0], v143))) goto v37;
    v143 = stack[-3];
    if (!(v143 == nil)) goto v72;
    v143 = stack[-1];
    fn = elt(env, 3); /* bas_nr */
    v98 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    v143 = (Lisp_Object)1; /* 0 */
    if (!(v98 == v143)) goto v72;

v37:
    v143 = stack[-2];
    v143 = qcdr(v143);
    stack[-2] = v143;
    goto v121;

v72:
    v99 = stack[-5];
    v98 = stack[-1];
    v143 = stack[-7];
    fn = elt(env, 7); /* groeb!=newpair */
    v98 = (*qfnn(fn))(qenv(fn), 3, v99, v98, v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    v143 = stack[-9];
    v143 = cons(v98, v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    stack[-9] = v143;
    goto v37;

v101:
    v98 = stack[-9];
    v143 = elt(env, 2); /* groeb!=better */
    fn = elt(env, 8); /* sort */
    v143 = (*qfn2(fn))(qenv(fn), v98, v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    fn = elt(env, 9); /* groeb!=crita */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    stack[-9] = v143;
    v143 = stack[-6];
    if (v143 == nil) goto v70;
    v143 = stack[-9];
    fn = elt(env, 10); /* groeb!=critc */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    stack[-9] = v143;
    goto v70;

v70:
    stack[0] = stack[-9];
    v98 = stack[-4];
    v143 = stack[-8];
    fn = elt(env, 11); /* groeb!=critb */
    v98 = (*qfn2(fn))(qenv(fn), v98, v143);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-10];
    v143 = elt(env, 2); /* groeb!=better */
    {
        Lisp_Object v295 = stack[0];
        popv(11);
        fn = elt(env, 12); /* merge */
        return (*qfnn(fn))(qenv(fn), 3, v295, v98, v143);
    }
/* error exit handlers */
v294:
    popv(11);
    return nil;
}



/* Code for lexorder */

static Lisp_Object CC_lexorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lexorder");
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
    v22 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = v22;
    goto v110;

v110:
    v22 = stack[-3];
    if (v22 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v22 = stack[-3];
    v22 = qcar(v22);
    stack[-2] = v22;
    stack[-1] = qvalue(elt(env, 2)); /* gv */
    v22 = stack[-2];
    stack[0] = qcar(v22);
    v23 = qvalue(elt(env, 2)); /* gv */
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = *(Lisp_Object *)((char *)v23 + (CELL-TAG_VECTOR) + ((int32_t)v22/(16/CELL)));
    fn = elt(env, 3); /* !*g2lex */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    fn = elt(env, 4); /* gcdout */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v22;
    fn = elt(env, 5); /* ljet */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v23 = stack[-2];
    v23 = qcar(v23);
    v23 = cons(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v22 = stack[-4];
    fn = elt(env, 6); /* insert */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-4] = v22;
    v22 = stack[-3];
    v22 = qcdr(v22);
    stack[-3] = v22;
    goto v110;
/* error exit handlers */
v157:
    popv(6);
    return nil;
}



/* Code for dummy_nam */

static Lisp_Object CC_dummy_nam(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dummy_nam");
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
    v51 = v0;
/* end of prologue */
    fn = elt(env, 4); /* ordn */
    v86 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    v51 = elt(env, 1); /* symbolic */
    fn = elt(env, 5); /* list2vect!* */
    v51 = (*qfn2(fn))(qenv(fn), v86, v51);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    qvalue(elt(env, 2)) = v51; /* g_dvnames */
    v51 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v51); }
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



/* Code for radf */

static Lisp_Object CC_radf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v349, v350;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for radf");
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
    stack[-6] = nil;
    stack[-2] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-1] = qvalue(elt(env, 2)); /* !*mcd */
    qvalue(elt(env, 2)) = nil; /* !*mcd */
    v349 = stack[-8];
    if (v349 == nil) goto v87;
    v349 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v349; /* !*mcd */
    qvalue(elt(env, 1)) = v349; /* !*gcd */
    v349 = (Lisp_Object)17; /* 1 */
    stack[-9] = v349;
    v349 = (Lisp_Object)17; /* 1 */
    stack[-3] = v349;
    goto v81;

v81:
    v349 = stack[-8];
    if (!consp(v349)) goto v351;
    v349 = stack[-8];
    v349 = qcar(v349);
    if (!consp(v349)) goto v351;
    v349 = stack[-8];
    fn = elt(env, 13); /* comfac */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-4] = v349;
    v349 = stack[-4];
    v349 = qcar(v349);
    if (v349 == nil) goto v353;
    v349 = qvalue(elt(env, 5)); /* !*precise_complex */
    if (v349 == nil) goto v259;
    v350 = (Lisp_Object)1; /* 0 */
    v349 = stack[-4];
    v349 = qcar(v349);
    v349 = qcdr(v349);
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    goto v102;

v102:
    stack[-5] = v349;
    v349 = stack[-5];
    v350 = qcar(v349);
    v349 = (Lisp_Object)1; /* 0 */
    if (v350 == v349) goto v354;
    v349 = stack[-5];
    v349 = qcar(v349);
    v349 = Levenp(nil, v349);
    env = stack[-10];
    if (v349 == nil) goto v294;
    v349 = stack[-8];
    v349 = qcar(v349);
    v349 = qcar(v349);
    v350 = qcar(v349);
    v349 = stack[-5];
    v349 = qcar(v349);
    fn = elt(env, 14); /* to */
    v350 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = (Lisp_Object)17; /* 1 */
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v350 = v349;
    goto v21;

v21:
    v349 = stack[-9];
    fn = elt(env, 15); /* multf */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-9] = v349;
    goto v354;

v354:
    v349 = stack[-5];
    v350 = qcdr(v349);
    v349 = (Lisp_Object)1; /* 0 */
    if (v350 == v349) goto v353;
    v349 = stack[-8];
    v349 = qcar(v349);
    v349 = qcar(v349);
    v349 = qcar(v349);
    fn = elt(env, 16); /* sfchk */
    v350 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = stack[-5];
    v349 = qcdr(v349);
    fn = elt(env, 17); /* mkexpt */
    v350 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = stack[-6];
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-6] = v349;
    goto v353;

v353:
    stack[0] = stack[-8];
    v349 = stack[-4];
    fn = elt(env, 18); /* comfac!-to!-poly */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    fn = elt(env, 19); /* quotf */
    v349 = (*qfn2(fn))(qenv(fn), stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-5] = v349;
    v349 = stack[-4];
    v349 = qcdr(v349);
    stack[-8] = v349;
    v349 = qvalue(elt(env, 8)); /* !*reduced */
    if (v349 == nil) goto v355;
    v349 = stack[-5];
    fn = elt(env, 20); /* minusf */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    if (v349 == nil) goto v355;
    v349 = stack[-5];
    fn = elt(env, 21); /* negf */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-5] = v349;
    v349 = stack[-8];
    fn = elt(env, 21); /* negf */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-8] = v349;
    goto v355;

v355:
    v350 = qvalue(elt(env, 9)); /* dmode!* */
    v349 = elt(env, 10); /* field */
    v349 = Lflagp(nil, v350, v349);
    env = stack[-10];
    if (v349 == nil) goto v356;
    v349 = stack[-5];
    fn = elt(env, 22); /* lnc */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-4] = v349;
    v350 = stack[-4];
    v349 = (Lisp_Object)17; /* 1 */
    if (v350 == v349) goto v356;
    v350 = stack[-5];
    v349 = stack[-4];
    fn = elt(env, 19); /* quotf */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-5] = v349;
    v350 = stack[-4];
    v349 = stack[-3];
    fn = elt(env, 23); /* multd */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-3] = v349;
    goto v356;

v356:
    v350 = stack[-5];
    v349 = (Lisp_Object)17; /* 1 */
    if (v350 == v349) goto v81;
    v349 = qvalue(elt(env, 5)); /* !*precise_complex */
    if (v349 == nil) goto v357;
    v350 = stack[-5];
    v349 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 14); /* to */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v350 = v349;
    goto v358;

v358:
    v349 = stack[-7];
    fn = elt(env, 24); /* radf1 */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-5] = v349;
    v349 = stack[-5];
    v349 = qcar(v349);
    stack[-4] = v349;
    v350 = stack[-4];
    v349 = (Lisp_Object)17; /* 1 */
    if (v350 == v349) goto v359;
    v349 = qvalue(elt(env, 6)); /* !*precise */
    if (v349 == nil) goto v360;
    v349 = stack[-7];
    v349 = Levenp(nil, v349);
    env = stack[-10];
    if (v349 == nil) goto v360;
    stack[0] = elt(env, 7); /* abs */
    v349 = stack[-4];
    fn = elt(env, 25); /* prepf */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v350 = list2(stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 26); /* mksp */
    v350 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = (Lisp_Object)17; /* 1 */
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-4] = v349;
    goto v360;

v360:
    v350 = stack[-4];
    v349 = stack[-9];
    fn = elt(env, 15); /* multf */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-9] = v349;
    goto v359;

v359:
    v350 = stack[-6];
    v349 = stack[-5];
    v349 = qcdr(v349);
    v349 = Lappend(nil, v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-6] = v349;
    goto v81;

v357:
    v349 = stack[-5];
    fn = elt(env, 27); /* sqfrf */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v350 = v349;
    goto v358;

v294:
    v349 = stack[-8];
    v349 = qcar(v349);
    v349 = qcar(v349);
    v350 = qcar(v349);
    v349 = stack[-4];
    v349 = qcar(v349);
    v349 = qcdr(v349);
    fn = elt(env, 14); /* to */
    v350 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = (Lisp_Object)17; /* 1 */
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[0] = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = qvalue(elt(env, 6)); /* !*precise */
    if (v349 == nil) goto v361;
    v349 = stack[-7];
    v349 = Levenp(nil, v349);
    env = stack[-10];
    if (v349 == nil) goto v361;
    v350 = elt(env, 7); /* abs */
    v349 = stack[-8];
    v349 = qcar(v349);
    v349 = qcar(v349);
    v349 = qcar(v349);
    v349 = list2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v350 = v349;
    goto v54;

v54:
    v349 = stack[-5];
    v349 = qcar(v349);
    fn = elt(env, 14); /* to */
    v350 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = (Lisp_Object)17; /* 1 */
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v350 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = stack[-7];
    fn = elt(env, 28); /* check!-radf!-sign */
    v349 = (*qfnn(fn))(qenv(fn), 3, stack[0], v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v350 = v349;
    goto v21;

v361:
    v349 = stack[-8];
    v349 = qcar(v349);
    v349 = qcar(v349);
    v349 = qcar(v349);
    v350 = v349;
    goto v54;

v259:
    v349 = stack[-4];
    v349 = qcar(v349);
    v350 = qcdr(v349);
    v349 = stack[-7];
    v349 = Ldivide(nil, v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    goto v102;

v351:
    v350 = stack[-8];
    v349 = (Lisp_Object)17; /* 1 */
    if (v350 == v349) goto v223;
    v350 = stack[-8];
    v349 = stack[-7];
    fn = elt(env, 29); /* radd */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-5] = v349;
    v349 = stack[-5];
    v350 = qcar(v349);
    v349 = stack[-9];
    fn = elt(env, 15); /* multf */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-9] = v349;
    v349 = stack[-5];
    v350 = qcdr(v349);
    v349 = stack[-6];
    v349 = Lappend(nil, v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-6] = v349;
    goto v223;

v223:
    v350 = stack[-3];
    v349 = (Lisp_Object)17; /* 1 */
    if (v350 == v349) goto v362;
    v349 = qvalue(elt(env, 11)); /* !*numval */
    if (v349 == nil) goto v363;
    stack[-5] = elt(env, 12); /* expt */
    stack[-4] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v349 = stack[-7];
    fn = elt(env, 30); /* !:recip */
    v350 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = (Lisp_Object)17; /* 1 */
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = acons(stack[-4], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    fn = elt(env, 31); /* domainvalchk */
    v349 = (*qfn2(fn))(qenv(fn), stack[-5], v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-4] = v349;
    if (v349 == nil) goto v363;
    v349 = stack[-4];
    fn = elt(env, 32); /* !*q2f */
    v350 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = stack[-9];
    fn = elt(env, 23); /* multd */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-9] = v349;
    goto v362;

v362:
    v350 = stack[-9];
    v349 = stack[-6];
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    goto v85;

v85:
    qvalue(elt(env, 2)) = stack[-1]; /* !*mcd */
    qvalue(elt(env, 1)) = stack[-2]; /* !*gcd */
    { popv(11); return onevalue(v349); }

v363:
    v349 = stack[-3];
    fn = elt(env, 25); /* prepf */
    v350 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    v349 = stack[-6];
    v349 = cons(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    stack[-6] = v349;
    goto v362;

v87:
    v349 = stack[-8];
    v349 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-10];
    goto v85;
/* error exit handlers */
v352:
    env = stack[-10];
    qvalue(elt(env, 2)) = stack[-1]; /* !*mcd */
    qvalue(elt(env, 1)) = stack[-2]; /* !*gcd */
    popv(11);
    return nil;
}



/* Code for ofsf_smwrmknowl */

static Lisp_Object CC_ofsf_smwrmknowl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwrmknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v109 = v1;
    v121 = v0;
/* end of prologue */
    v108 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v108 == nil) goto v145;
    v108 = v121;
    {
        fn = elt(env, 2); /* ofsf_susirmknowl */
        return (*qfn2(fn))(qenv(fn), v108, v109);
    }

v145:
    v108 = v121;
    {
        fn = elt(env, 3); /* ofsf_smrmknowl */
        return (*qfn2(fn))(qenv(fn), v108, v109);
    }
}



/* Code for gcdk */

static Lisp_Object CC_gcdk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v324, v377;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdk");
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
    stack[-9] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-10] = nil;
    v324 = stack[0];
    v268 = stack[-9];
    if (equal(v324, v268)) { Lisp_Object res = stack[0]; popv(12); return onevalue(res); }
    v268 = stack[0];
    if (!consp(v268)) goto v132;
    v268 = stack[0];
    v268 = qcar(v268);
    if (!consp(v268)) goto v132;
    v324 = stack[-9];
    v268 = stack[0];
    v268 = qcar(v268);
    v268 = qcar(v268);
    v268 = qcar(v268);
    stack[-8] = v268;
    fn = elt(env, 8); /* degr */
    v324 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    v268 = (Lisp_Object)1; /* 0 */
    if (v324 == v268) goto v132;
    v268 = stack[0];
    v268 = qcar(v268);
    v268 = qcar(v268);
    v324 = qcdr(v268);
    v268 = stack[-9];
    v268 = qcar(v268);
    v268 = qcar(v268);
    v268 = qcdr(v268);
    v268 = (Lisp_Object)lessp2(v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    v268 = v268 ? lisp_true : nil;
    env = stack[-11];
    if (v268 == nil) goto v72;
    v268 = stack[0];
    stack[-7] = v268;
    v268 = stack[-9];
    stack[0] = v268;
    v268 = stack[-7];
    stack[-9] = v268;
    goto v72;

v72:
    v324 = stack[0];
    v268 = stack[-9];
    fn = elt(env, 9); /* quotf1 */
    v268 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    if (!(v268 == nil)) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    v268 = qvalue(elt(env, 1)); /* !*heugcd */
    if (v268 == nil) goto v100;
    v324 = stack[0];
    v268 = stack[-9];
    fn = elt(env, 10); /* heu!-gcd */
    v268 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    v324 = v268;
    if (!(v268 == nil)) { popv(12); return onevalue(v324); }

v100:
    v268 = stack[-9];
    v268 = qcar(v268);
    v268 = qcar(v268);
    v324 = qcdr(v268);
    v268 = (Lisp_Object)17; /* 1 */
    if (v324 == v268) goto v260;
    v268 = elt(env, 2); /* modular!-multicheck */
    fn = elt(env, 11); /* getd */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    if (v268 == nil) goto v138;
    v377 = stack[0];
    v324 = stack[-9];
    v268 = stack[-8];
    fn = elt(env, 2); /* modular!-multicheck */
    v268 = (*qfnn(fn))(qenv(fn), 3, v377, v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    if (!(v268 == nil)) goto v260;

v138:
    v268 = qvalue(elt(env, 3)); /* !*mcd */
    if (!(v268 == nil)) goto v144;

v260:
    v268 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v268); }

v144:
    v324 = stack[0];
    v268 = stack[-9];
    fn = elt(env, 12); /* remk */
    v268 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    stack[-7] = v268;
    v268 = stack[-7];
    if (v268 == nil) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    v324 = stack[-7];
    v268 = stack[-8];
    fn = elt(env, 8); /* degr */
    v324 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    v268 = (Lisp_Object)1; /* 0 */
    if (v324 == v268) goto v348;
    v324 = stack[-9];
    v268 = stack[-10];
    fn = elt(env, 13); /* addlc */
    v268 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    stack[-10] = v268;
    v324 = stack[-7];
    v268 = stack[-7];
    v268 = qcar(v268);
    v268 = qcdr(v268);
    fn = elt(env, 9); /* quotf1 */
    v268 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    v324 = v268;
    if (v268 == nil) goto v242;
    v268 = v324;
    stack[-7] = v268;
    goto v94;

v94:
    v268 = stack[-9];
    stack[0] = v268;
    v268 = stack[-7];
    fn = elt(env, 14); /* prim!-part */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    stack[-9] = v268;
    v324 = stack[-9];
    v268 = stack[-8];
    fn = elt(env, 8); /* degr */
    v324 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    v268 = (Lisp_Object)1; /* 0 */
    if (!(v324 == v268)) goto v144;
    v268 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v268); }

v242:
    v268 = stack[-10];
    stack[-6] = v268;
    goto v346;

v346:
    v268 = stack[-6];
    if (v268 == nil) goto v94;
    v268 = stack[-6];
    v268 = qcar(v268);
    stack[-5] = v268;
    v268 = stack[-5];
    if (!(!consp(v268))) goto v254;
    v324 = qvalue(elt(env, 5)); /* dmode!* */
    v268 = elt(env, 6); /* field */
    v268 = Lflagp(nil, v324, v268);
    env = stack[-11];
    if (!(v268 == nil)) goto v254;

v379:
    v324 = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 9); /* quotf1 */
    v268 = (*qfn2(fn))(qenv(fn), v324, v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    v324 = v268;
    if (v268 == nil) goto v380;
    v268 = v324;
    stack[-7] = v268;
    goto v379;

v380:
    v268 = stack[-6];
    v268 = qcdr(v268);
    stack[-6] = v268;
    goto v346;

v254:
    v268 = stack[-5];
    if (!consp(v268)) goto v353;
    v268 = stack[-5];
    v268 = qcar(v268);
    if (!(!consp(v268))) goto v379;

v353:
    v324 = qvalue(elt(env, 5)); /* dmode!* */
    v268 = elt(env, 6); /* field */
    v268 = Lflagp(nil, v324, v268);
    env = stack[-11];
    if (!(v268 == nil)) goto v380;
    v268 = stack[-5];
    v324 = qcar(v268);
    v268 = elt(env, 7); /* units */
    v268 = get(v324, v268);
    env = stack[-11];
    v324 = v268;
    if (v268 == nil) goto v379;
    stack[-4] = stack[-5];
    v268 = v324;
    stack[-3] = v268;
    v268 = stack[-3];
    if (v268 == nil) goto v337;
    v268 = stack[-3];
    v268 = qcar(v268);
    v268 = qcar(v268);
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    stack[-1] = v268;
    stack[-2] = v268;
    goto v381;

v381:
    v268 = stack[-3];
    v268 = qcdr(v268);
    stack[-3] = v268;
    v268 = stack[-3];
    if (v268 == nil) goto v382;
    stack[0] = stack[-1];
    v268 = stack[-3];
    v268 = qcar(v268);
    v268 = qcar(v268);
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    v268 = Lrplacd(nil, stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v378;
    env = stack[-11];
    v268 = stack[-1];
    v268 = qcdr(v268);
    stack[-1] = v268;
    goto v381;

v382:
    v268 = stack[-2];
    goto v383;

v383:
    v268 = Lmember(nil, stack[-4], v268);
    if (v268 == nil) goto v379;
    else goto v380;

v337:
    v268 = qvalue(elt(env, 4)); /* nil */
    goto v383;

v348:
    v268 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v268); }

v132:
    v268 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v268); }
/* error exit handlers */
v378:
    popv(12);
    return nil;
}



/* Code for get!*order */

static Lisp_Object CC_getHorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*order");
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
    v105 = v0;
/* end of prologue */
    fn = elt(env, 1); /* get!*elements */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    errexit();
        return Llength(nil, v105);
}



/* Code for subst!-cn */

static Lisp_Object MS_CDECL CC_substKcn(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v61, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subst-cn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subst-cn");
#endif
    if (stack >= stacklimit)
    {
        push3(v61,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v61);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v61;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v19 = stack[-1];
    v19 = ncons(v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    fn = elt(env, 1); /* setkorder */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-3] = v19;
    v19 = stack[-2];
    fn = elt(env, 2); /* reorder */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-2] = v19;
    v19 = stack[-2];
    if (!consp(v19)) goto v86;
    v19 = stack[-2];
    v19 = qcar(v19);
    if (!consp(v19)) goto v86;
    v19 = stack[-2];
    v19 = qcar(v19);
    v19 = qcar(v19);
    v141 = qcar(v19);
    v19 = stack[-1];
    if (!(v141 == v19)) goto v86;
    v19 = stack[0];
    if (v19 == nil) goto v82;
    v19 = stack[-2];
    v19 = qcar(v19);
    stack[-1] = qcdr(v19);
    v19 = stack[0];
    v19 = qcar(v19);
    fn = elt(env, 2); /* reorder */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    fn = elt(env, 3); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v19 = stack[-2];
    stack[-2] = qcdr(v19);
    v19 = stack[0];
    v19 = qcdr(v19);
    fn = elt(env, 2); /* reorder */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    fn = elt(env, 3); /* multf */
    v19 = (*qfn2(fn))(qenv(fn), stack[-2], v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    fn = elt(env, 4); /* addf */
    v19 = (*qfn2(fn))(qenv(fn), stack[-1], v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-2] = v19;
    goto v86;

v86:
    v19 = stack[-3];
    fn = elt(env, 1); /* setkorder */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v19 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); /* reorder */
        return (*qfn1(fn))(qenv(fn), v19);
    }

v82:
    v19 = stack[-2];
    v19 = qcdr(v19);
    stack[-2] = v19;
    goto v86;
/* error exit handlers */
v123:
    popv(5);
    return nil;
}



/* Code for bc_minus!? */

static Lisp_Object CC_bc_minusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_minus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v62 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v62);
    }
}



/* Code for vectordifference */

static Lisp_Object CC_vectordifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vectordifference");
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
    v78 = v1;
    v132 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* vectoradd */
    stack[0] = v132;
    v132 = elt(env, 2); /* vectorminus */
    v78 = list2(v132, v78);
    nil = C_nil;
    if (exception_pending()) goto v52;
    {
        Lisp_Object v108 = stack[-1];
        Lisp_Object v109 = stack[0];
        popv(2);
        return list3(v108, v109, v78);
    }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for validrule */

static Lisp_Object CC_validrule(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for validrule");
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
    v80 = v0;
/* end of prologue */
    fn = elt(env, 2); /* validrule1 */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[0];
    v88 = v80;
    v80 = v88;
    if (v80 == nil) goto v105;
    v80 = v88;
    popv(1);
    return ncons(v80);

v105:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v80); }
/* error exit handlers */
v49:
    popv(1);
    return nil;
}



/* Code for bassoc */

static Lisp_Object CC_bassoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v43, v130, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bassoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v1;
    v129 = v0;
/* end of prologue */

v32:
    v37 = v130;
    if (v37 == nil) goto v91;
    v43 = v129;
    v37 = v130;
    v37 = qcar(v37);
    v37 = qcar(v37);
    if (v43 == v37) goto v51;
    v43 = v129;
    v37 = v130;
    v37 = qcar(v37);
    v37 = qcdr(v37);
    if (v43 == v37) goto v51;
    v37 = v130;
    v37 = qcdr(v37);
    v130 = v37;
    goto v32;

v51:
    v37 = v130;
    v37 = qcar(v37);
    return onevalue(v37);

v91:
    v37 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v37);
}



/* Code for quotfexf!*1 */

static Lisp_Object CC_quotfexfH1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v123, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfexf*1");
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
    v149 = stack[-1];
    if (v149 == nil) goto v32;
    v123 = stack[-1];
    v149 = stack[0];
    fn = elt(env, 6); /* quotf */
    v149 = (*qfn2(fn))(qenv(fn), v123, v149);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    v123 = v149;
    v149 = v123;
    if (!(v149 == nil)) { popv(3); return onevalue(v123); }
    v123 = stack[-1];
    v149 = stack[0];
    v149 = cons(v123, v149);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    fn = elt(env, 7); /* rationalizesq */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    v122 = v149;
    v149 = v122;
    v123 = qcdr(v149);
    v149 = (Lisp_Object)17; /* 1 */
    if (v123 == v149) goto v37;
    v149 = qvalue(elt(env, 2)); /* t */
    stack[0] = qvalue(elt(env, 3)); /* !*rationalize */
    qvalue(elt(env, 3)) = v149; /* !*rationalize */
    v149 = v122;
    fn = elt(env, 7); /* rationalizesq */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-2];
    qvalue(elt(env, 3)) = stack[0]; /* !*rationalize */
    v122 = v149;
    v123 = qcdr(v149);
    v149 = (Lisp_Object)17; /* 1 */
    if (v123 == v149) goto v103;
    v122 = elt(env, 4); /* matrix */
    v123 = (Lisp_Object)177; /* 11 */
    v149 = elt(env, 5); /* "Catastrophic division failure" */
    {
        popv(3);
        fn = elt(env, 8); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v122, v123, v149);
    }

v103:
    v149 = v122;
    v149 = qcar(v149);
    { popv(3); return onevalue(v149); }

v37:
    v149 = v122;
    v149 = qcar(v149);
    { popv(3); return onevalue(v149); }

v32:
    v149 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v149); }
/* error exit handlers */
v83:
    env = stack[-2];
    qvalue(elt(env, 3)) = stack[0]; /* !*rationalize */
    popv(3);
    return nil;
v21:
    popv(3);
    return nil;
}



/* Code for bc_power */

static Lisp_Object CC_bc_power(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_power");
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
    v51 = v1;
    v86 = v0;
/* end of prologue */
    fn = elt(env, 1); /* exptf */
    v51 = (*qfn2(fn))(qenv(fn), v86, v51);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v51);
    }
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



setup_type const u43_setup[] =
{
    {"reduce-eival-powers1",    too_few_2,      CC_reduceKeivalKpowers1,wrong_no_2},
    {"ezgcd-comfac",            CC_ezgcdKcomfac,too_many_1,    wrong_no_1},
    {"cl_applysac2",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_applysac2},
    {"acfsf_0mk2",              too_few_2,      CC_acfsf_0mk2, wrong_no_2},
    {"ps:find-order1",          CC_psTfindKorder1,too_many_1,  wrong_no_1},
    {"expttermp",               too_few_2,      CC_expttermp,  wrong_no_2},
    {"xvarp",                   CC_xvarp,       too_many_1,    wrong_no_1},
    {"partitpartdf",            CC_partitpartdf,too_many_1,    wrong_no_1},
    {"listsub",                 too_few_2,      CC_listsub,    wrong_no_2},
    {"modroots2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modroots2},
    {"rl_qe",                   too_few_2,      CC_rl_qe,      wrong_no_2},
    {"preptaycoeff",            too_few_2,      CC_preptaycoeff,wrong_no_2},
    {"mkarg",                   too_few_2,      CC_mkarg,      wrong_no_2},
    {"ratnump",                 CC_ratnump,     too_many_1,    wrong_no_1},
    {"rm_neg_pow",              CC_rm_neg_pow,  too_many_1,    wrong_no_1},
    {"mkuniquewedge1",          CC_mkuniquewedge1,too_many_1,  wrong_no_1},
    {"ratmean",                 too_few_2,      CC_ratmean,    wrong_no_2},
    {"coeff_sortl",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_sortl},
    {"degree-order",            too_few_2,      CC_degreeKorder,wrong_no_2},
    {"fillin",                  CC_fillin,      too_many_1,    wrong_no_1},
    {"find-null-space",         too_few_2,      CC_findKnullKspace,wrong_no_2},
    {"sqlessp",                 too_few_2,      CC_sqlessp,    wrong_no_2},
    {"distribute.multiplicity", too_few_2,      CC_distributeQmultiplicity,wrong_no_2},
    {"appends",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_appends},
    {"dm-lt",                   too_few_2,      CC_dmKlt,      wrong_no_2},
    {"exdfp0",                  CC_exdfp0,      too_many_1,    wrong_no_1},
    {"randpoly",                CC_randpoly,    too_many_1,    wrong_no_1},
    {"lambda_l7ipth_11",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_lambda_l7ipth_11},
    {"noncom1",                 CC_noncom1,     too_many_1,    wrong_no_1},
    {"split-wrt-variables",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKwrtKvariables},
    {"groeb_updatepl",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_groeb_updatepl},
    {"lexorder",                CC_lexorder,    too_many_1,    wrong_no_1},
    {"dummy_nam",               CC_dummy_nam,   too_many_1,    wrong_no_1},
    {"radf",                    too_few_2,      CC_radf,       wrong_no_2},
    {"ofsf_smwrmknowl",         too_few_2,      CC_ofsf_smwrmknowl,wrong_no_2},
    {"gcdk",                    too_few_2,      CC_gcdk,       wrong_no_2},
    {"get*order",               CC_getHorder,   too_many_1,    wrong_no_1},
    {"subst-cn",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_substKcn},
    {"bc_minus?",               CC_bc_minusW,   too_many_1,    wrong_no_1},
    {"vectordifference",        too_few_2,      CC_vectordifference,wrong_no_2},
    {"validrule",               CC_validrule,   too_many_1,    wrong_no_1},
    {"bassoc",                  too_few_2,      CC_bassoc,     wrong_no_2},
    {"quotfexf*1",              too_few_2,      CC_quotfexfH1, wrong_no_2},
    {"bc_power",                too_few_2,      CC_bc_power,   wrong_no_2},
    {NULL, (one_args *)"u43", (two_args *)"1507 4556937 4672674", 0}
};

/* end of generated code */
