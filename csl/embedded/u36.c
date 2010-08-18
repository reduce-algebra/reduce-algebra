
/* $destdir/generated-c\u36.c Machine generated C code */

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


/* Code for makecoeffpairs1 */

static Lisp_Object MS_CDECL CC_makecoeffpairs1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairs1");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v3;
    stack[-11] = v2;
    stack[-12] = v1;
    stack[-13] = v0;
/* end of prologue */
    v58 = stack[-12];
    if (v58 == nil) goto v62;
    v58 = stack[-13];
    v61 = qcdr(v58);
    v58 = stack[-12];
    v60 = qcdr(v58);
    v58 = stack[-11];
    v59 = qcdr(v58);
    v58 = stack[-10];
    v58 = qcdr(v58);
    v58 = CC_makecoeffpairs1(env, 4, v61, v60, v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-14] = v58;
    goto v64;

v64:
    v58 = stack[-14];
    if (v58 == nil) goto v65;
    v58 = stack[-14];
    v58 = qcar(v58);
    stack[-6] = v58;
    v58 = stack[-13];
    stack[-2] = qcar(v58);
    v58 = stack[-12];
    stack[-1] = qcar(v58);
    v58 = stack[-11];
    stack[0] = qcar(v58);
    v58 = stack[-10];
    v58 = qcar(v58);
    fn = elt(env, 3); /* tayexp!-minus */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v58 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v66;
    v58 = stack[-5];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[-1] = qcar(v58);
    v58 = stack[-6];
    stack[0] = qcar(v58);
    v58 = v59;
    v59 = qcdr(v58);
    v58 = stack[-6];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = acons(stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-3] = v58;
    stack[-4] = v58;
    goto v67;

v67:
    v58 = stack[-5];
    v58 = qcdr(v58);
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v68;
    stack[-2] = stack[-3];
    v58 = stack[-5];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[-1] = qcar(v58);
    v58 = stack[-6];
    stack[0] = qcar(v58);
    v58 = v59;
    v59 = qcdr(v58);
    v58 = stack[-6];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = acons(stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = Lrplacd(nil, stack[-2], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = stack[-3];
    v58 = qcdr(v58);
    stack[-3] = v58;
    goto v67;

v68:
    v58 = stack[-4];
    goto v69;

v69:
    stack[-9] = v58;
    v58 = stack[-9];
    fn = elt(env, 5); /* lastpair */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-8] = v58;
    v58 = stack[-14];
    v58 = qcdr(v58);
    stack[-14] = v58;
    v58 = stack[-8];
    if (!consp(v58)) goto v64;
    else goto v70;

v70:
    v58 = stack[-14];
    if (v58 == nil) { Lisp_Object res = stack[-9]; popv(16); return onevalue(res); }
    stack[-7] = stack[-8];
    v58 = stack[-14];
    v58 = qcar(v58);
    stack[-6] = v58;
    v58 = stack[-13];
    stack[-2] = qcar(v58);
    v58 = stack[-12];
    stack[-1] = qcar(v58);
    v58 = stack[-11];
    stack[0] = qcar(v58);
    v58 = stack[-10];
    v58 = qcar(v58);
    fn = elt(env, 3); /* tayexp!-minus */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v58 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v71;
    v58 = stack[-5];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[-1] = qcar(v58);
    v58 = stack[-6];
    stack[0] = qcar(v58);
    v58 = v59;
    v59 = qcdr(v58);
    v58 = stack[-6];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = acons(stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-3] = v58;
    stack[-4] = v58;
    goto v72;

v72:
    v58 = stack[-5];
    v58 = qcdr(v58);
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v73;
    stack[-2] = stack[-3];
    v58 = stack[-5];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[-1] = qcar(v58);
    v58 = stack[-6];
    stack[0] = qcar(v58);
    v58 = v59;
    v59 = qcdr(v58);
    v58 = stack[-6];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = acons(stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = Lrplacd(nil, stack[-2], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = stack[-3];
    v58 = qcdr(v58);
    stack[-3] = v58;
    goto v72;

v73:
    v58 = stack[-4];
    goto v74;

v74:
    v58 = Lrplacd(nil, stack[-7], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = stack[-8];
    fn = elt(env, 5); /* lastpair */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-8] = v58;
    v58 = stack[-14];
    v58 = qcdr(v58);
    stack[-14] = v58;
    goto v70;

v71:
    v58 = qvalue(elt(env, 2)); /* nil */
    goto v74;

v66:
    v58 = qvalue(elt(env, 2)); /* nil */
    goto v69;

v65:
    v58 = qvalue(elt(env, 2)); /* nil */
    { popv(16); return onevalue(v58); }

v62:
    v58 = elt(env, 1); /* ((nil)) */
    { popv(16); return onevalue(v58); }
/* error exit handlers */
v63:
    popv(16);
    return nil;
}



/* Code for gigcd!: */

static Lisp_Object CC_gigcdT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gigcd:");
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

v79:
    v77 = stack[0];
    fn = elt(env, 1); /* gizerop!: */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    if (v77 == nil) goto v6;
    v77 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* fqa */
        return (*qfn1(fn))(qenv(fn), v77);
    }

v6:
    v77 = stack[0];
    stack[-2] = v77;
    v78 = stack[-1];
    v77 = stack[0];
    fn = elt(env, 3); /* giremainder */
    v77 = (*qfn2(fn))(qenv(fn), v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    stack[0] = v77;
    v77 = stack[-2];
    stack[-1] = v77;
    goto v79;
/* error exit handlers */
v80:
    popv(4);
    return nil;
}



/* Code for rlis */

static Lisp_Object MS_CDECL CC_rlis(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rlis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rlis");
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
    v88 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v88;
    fn = elt(env, 7); /* scan */
    v89 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v88 = elt(env, 2); /* delim */
    v88 = Lflagp(nil, v89, v88);
    env = stack[-2];
    if (v88 == nil) goto v91;
    v88 = stack[0];
    v89 = qvalue(elt(env, 3)); /* nil */
    popv(3);
    return list2(v88, v89);

v91:
    v88 = qvalue(elt(env, 4)); /* !*reduce4 */
    if (v88 == nil) goto v31;
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); /* list */
    v88 = elt(env, 6); /* lambda */
    fn = elt(env, 8); /* xread1 */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    fn = elt(env, 9); /* remcomma */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v88 = cons(stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v92 = stack[-1];
        popv(3);
        return list2(v92, v88);
    }

v31:
    v88 = elt(env, 6); /* lambda */
    fn = elt(env, 8); /* xread1 */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    fn = elt(env, 9); /* remcomma */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v93 = stack[0];
        popv(3);
        return cons(v93, v88);
    }
/* error exit handlers */
v90:
    popv(3);
    return nil;
}



/* Code for splitrec */

static Lisp_Object MS_CDECL CC_splitrec(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v17, v5, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "splitrec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitrec");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v3;
    stack[-3] = v2;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v18 = stack[-5];
    if (!consp(v18)) goto v64;
    v18 = stack[-5];
    v18 = qcar(v18);
    if (!consp(v18)) goto v64;
    v18 = stack[-5];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v17 = qcar(v18);
    v18 = stack[-4];
    if (!consp(v17)) goto v114;
    v17 = qcar(v17);
    if (!(v17 == v18)) goto v114;
    v18 = stack[-5];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = qcar(v18);
    v17 = Llength(nil, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    v18 = (Lisp_Object)33; /* 2 */
    v18 = (Lisp_Object)greaterp2(v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    v18 = v18 ? lisp_true : nil;
    env = stack[-7];
    if (v18 == nil) goto v114;
    v18 = stack[-5];
    v18 = qcar(v18);
    stack[-6] = qcdr(v18);
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v18 = stack[-5];
    v18 = qcar(v18);
    v17 = qcar(v18);
    v18 = stack[-2];
    v18 = cons(v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    v18 = CC_splitrec(env, 4, stack[-6], stack[-1], stack[0], v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    goto v116;

v116:
    v18 = stack[-5];
    v18 = qcdr(v18);
    if (v18 == nil) goto v117;
    v18 = stack[-5];
    v113 = qcdr(v18);
    v5 = stack[-4];
    v17 = stack[-3];
    v18 = stack[-2];
    v18 = CC_splitrec(env, 4, v113, v5, v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    goto v117;

v117:
    v18 = nil;
    { popv(8); return onevalue(v18); }

v114:
    v18 = stack[-5];
    v18 = qcar(v18);
    stack[-1] = qcdr(v18);
    stack[0] = stack[-4];
    v18 = stack[-5];
    v18 = qcar(v18);
    v17 = qcar(v18);
    v18 = stack[-3];
    v18 = cons(v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    v17 = ncons(v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    v18 = stack[-2];
    v18 = CC_splitrec(env, 4, stack[-1], stack[0], v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    goto v116;

v64:
    v17 = stack[-5];
    v18 = stack[-3];
    fn = elt(env, 2); /* multf */
    v18 = (*qfn2(fn))(qenv(fn), v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[-3] = v18;
    v17 = stack[-2];
    v18 = qvalue(elt(env, 1)); /* list!-pq */
    v18 = Lassoc(nil, v17, v18);
    v17 = v18;
    if (v18 == nil) goto v118;
    stack[0] = v17;
    v18 = v17;
    v17 = qcdr(v18);
    v18 = stack[-3];
    fn = elt(env, 3); /* addf */
    v18 = (*qfn2(fn))(qenv(fn), v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    v18 = Lrplacd(nil, stack[0], v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    goto v119;

v119:
    v18 = nil;
    { popv(8); return onevalue(v18); }

v118:
    v5 = stack[-2];
    v17 = stack[-3];
    v18 = qvalue(elt(env, 1)); /* list!-pq */
    v18 = acons(v5, v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    qvalue(elt(env, 1)) = v18; /* list!-pq */
    goto v119;
/* error exit handlers */
v115:
    popv(8);
    return nil;
}



/* Code for tchscheme */

static Lisp_Object MS_CDECL CC_tchscheme(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tchscheme");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tchscheme");
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
    stack[-2] = nil;
    v68 = (Lisp_Object)1; /* 0 */
    stack[-1] = v68;
    goto v87;

v87:
    v130 = qvalue(elt(env, 1)); /* rowmax */
    v68 = stack[-1];
    v68 = difference2(v130, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v68 = Lminusp(nil, v68);
    env = stack[-3];
    if (!(v68 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v130 = qvalue(elt(env, 4)); /* maxvar */
    v68 = stack[-1];
    v68 = plus2(v130, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v130 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v68/(16/CELL)));
    v68 = (Lisp_Object)49; /* 3 */
    v130 = *(Lisp_Object *)((char *)v130 + (CELL-TAG_VECTOR) + ((int32_t)v68/(16/CELL)));
    v68 = (Lisp_Object)-15; /* -1 */
    if (v130 == v68) goto v76;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v130 = qvalue(elt(env, 4)); /* maxvar */
    v68 = stack[-1];
    v68 = plus2(v130, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v130 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v68/(16/CELL)));
    v68 = (Lisp_Object)65; /* 4 */
    v68 = *(Lisp_Object *)((char *)v130 + (CELL-TAG_VECTOR) + ((int32_t)v68/(16/CELL)));
    stack[0] = v68;
    if (v68 == nil) goto v76;
    v68 = stack[0];
    v68 = qcdr(v68);
    if (!(v68 == nil)) goto v76;
    v130 = stack[-1];
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    v68 = qcar(v68);
    fn = elt(env, 6); /* transferrow */
    v68 = (*qfn2(fn))(qenv(fn), v130, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    if (v68 == nil) goto v76;
    v130 = stack[-1];
    v68 = stack[0];
    v68 = qcar(v68);
    fn = elt(env, 7); /* chscheme */
    v68 = (*qfn2(fn))(qenv(fn), v130, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v68 = qvalue(elt(env, 5)); /* t */
    stack[-2] = v68;
    goto v76;

v76:
    v68 = stack[-1];
    v68 = add1(v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    stack[-1] = v68;
    goto v87;
/* error exit handlers */
v102:
    popv(4);
    return nil;
}



/* Code for fieldp */

static Lisp_Object CC_fieldp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fieldp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v132 = v0;
/* end of prologue */
    v70 = v132;
    if (!consp(v70)) goto v133;
    v70 = v132;
    v70 = qcar(v70);
    v132 = elt(env, 2); /* field */
        return Lflagp(nil, v70, v132);

v133:
    v70 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v70);
}



/* Code for xpartitk */

static Lisp_Object CC_xpartitk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v137, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitk");
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
    v137 = stack[0];
    v89 = elt(env, 1); /* (wedge partdf) */
    fn = elt(env, 2); /* memqcar */
    v89 = (*qfn2(fn))(qenv(fn), v137, v89);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    if (v89 == nil) goto v43;
    v89 = stack[0];
    fn = elt(env, 3); /* reval */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    v138 = v89;
    v137 = v138;
    v89 = stack[0];
    if (equal(v137, v89)) goto v139;
    v89 = v138;
    {
        popv(2);
        fn = elt(env, 4); /* xpartitop */
        return (*qfn1(fn))(qenv(fn), v89);
    }

v139:
    v138 = stack[0];
    v137 = (Lisp_Object)17; /* 1 */
    v89 = (Lisp_Object)17; /* 1 */
    v89 = list2star(v138, v137, v89);
    nil = C_nil;
    if (exception_pending()) goto v92;
    popv(2);
    return ncons(v89);

v43:
    v138 = stack[0];
    v137 = (Lisp_Object)17; /* 1 */
    v89 = (Lisp_Object)17; /* 1 */
    v89 = list2star(v138, v137, v89);
    nil = C_nil;
    if (exception_pending()) goto v92;
    popv(2);
    return ncons(v89);
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for deflate1 */

static Lisp_Object CC_deflate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v143, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deflate1");
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
    v142 = v0;
/* end of prologue */
    stack[-5] = nil;
    fn = elt(env, 2); /* ncoeffs */
    v143 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-6];
    v142 = v143;
    v143 = qcar(v143);
    stack[-3] = v143;
    v142 = qcdr(v142);
    v143 = v142;
    v143 = qcar(v143);
    stack[-2] = v143;
    v142 = qcdr(v142);
    stack[-1] = v142;
    goto v64;

v64:
    v142 = stack[-1];
    if (v142 == nil) goto v146;
    v142 = stack[-1];
    v142 = qcar(v142);
    stack[0] = v142;
    v142 = stack[-3];
    v142 = sub1(v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-6];
    stack[-3] = v142;
    v142 = stack[-2];
    v142 = qcdr(v142);
    v143 = qcar(v142);
    v142 = (Lisp_Object)1; /* 0 */
    if (v143 == v142) goto v88;
    v144 = stack[-3];
    v143 = stack[-2];
    v142 = stack[-5];
    v142 = acons(v144, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-6];
    stack[-5] = v142;
    goto v88;

v88:
    v143 = stack[-4];
    v142 = stack[-2];
    fn = elt(env, 3); /* times!: */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-6];
    stack[-2] = v142;
    v142 = stack[0];
    if (v142 == nil) goto v110;
    v143 = stack[0];
    v142 = stack[-2];
    fn = elt(env, 4); /* plus!: */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-6];
    stack[-2] = v142;
    goto v110;

v110:
    v142 = stack[-1];
    v142 = qcdr(v142);
    stack[-1] = v142;
    goto v64;

v146:
    v143 = stack[-2];
    v142 = stack[-5];
    popv(7);
    return cons(v143, v142);
/* error exit handlers */
v145:
    popv(7);
    return nil;
}



/* Code for endofstmtp */

static Lisp_Object MS_CDECL CC_endofstmtp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v6;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endofstmtp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endofstmtp");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v6 = qvalue(elt(env, 1)); /* cursym!* */
    v30 = elt(env, 2); /* (!*semicol!* !*rsqbkt!* end) */
    v30 = Lmember(nil, v6, v30);
    if (v30 == nil) goto v133;
    v30 = qvalue(elt(env, 3)); /* t */
    return onevalue(v30);

v133:
    v30 = nil;
    return onevalue(v30);
}



/* Code for lndepends */

static Lisp_Object CC_lndepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lndepends");
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

v149:
    v80 = stack[-1];
    if (v80 == nil) goto v120;
    v80 = stack[-1];
    v57 = qcar(v80);
    v80 = stack[0];
    fn = elt(env, 2); /* ndepends */
    v80 = (*qfn2(fn))(qenv(fn), v57, v80);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    if (!(v80 == nil)) { popv(3); return onevalue(v80); }
    v80 = stack[-1];
    v57 = qcdr(v80);
    v80 = stack[0];
    stack[-1] = v57;
    stack[0] = v80;
    goto v149;

v120:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v80); }
/* error exit handlers */
v150:
    popv(3);
    return nil;
}



/* Code for requote1 */

static Lisp_Object CC_requote1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v145;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for requote1");
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
    goto v79;

v79:
    v151 = stack[0];
    if (v151 == nil) goto v152;
    v151 = stack[0];
    v151 = qcar(v151);
    if (is_number(v151)) goto v139;
    v151 = stack[0];
    v145 = qcar(v151);
    v151 = elt(env, 1); /* (nil t) */
    v151 = Lmemq(nil, v145, v151);
    if (!(v151 == nil)) goto v139;
    v151 = stack[0];
    v151 = qcar(v151);
    if (!consp(v151)) goto v134;
    v151 = stack[0];
    v151 = qcar(v151);
    v145 = qcar(v151);
    v151 = elt(env, 3); /* quote */
    if (v145 == v151) goto v126;
    v151 = stack[0];
    v151 = qcar(v151);
    v145 = qcar(v151);
    v151 = elt(env, 4); /* list */
    if (!(v145 == v151)) goto v121;
    v151 = stack[0];
    v151 = qcar(v151);
    v151 = qcdr(v151);
    v151 = CC_requote1(env, v151);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v145 = v151;
    if (v151 == nil) goto v121;
    v151 = stack[-1];
    v151 = cons(v145, v151);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v151;
    goto v91;

v91:
    v151 = stack[0];
    v151 = qcdr(v151);
    stack[0] = v151;
    goto v79;

v121:
    v151 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v151); }

v126:
    v151 = stack[0];
    v151 = qcar(v151);
    v151 = qcdr(v151);
    v145 = qcar(v151);
    v151 = stack[-1];
    v151 = cons(v145, v151);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v151;
    goto v91;

v134:
    v151 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v151); }

v139:
    v151 = stack[0];
    v145 = qcar(v151);
    v151 = stack[-1];
    v151 = cons(v145, v151);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v151;
    goto v91;

v152:
    v151 = stack[-1];
        popv(3);
        return Lnreverse(nil, v151);
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for al1_defined_vertex */

static Lisp_Object MS_CDECL CC_al1_defined_vertex(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "al1_defined_vertex");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for al1_defined_vertex");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v91:
    v109 = stack[-3];
    if (v109 == nil) goto v148;
    v109 = stack[-3];
    v108 = qcar(v109);
    v109 = stack[0];
    fn = elt(env, 3); /* defined_edge */
    v109 = (*qfn2(fn))(qenv(fn), v108, v109);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    if (v109 == nil) goto v156;
    v108 = stack[-2];
    v109 = stack[-3];
    v109 = qcdr(v109);
    v109 = Lnconc(nil, v108, v109);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-4] = v109;
    v109 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v109;
    v109 = stack[-3];
    v108 = qcar(v109);
    v109 = stack[-1];
    v109 = cons(v108, v109);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-1] = v109;
    v109 = stack[-3];
    v108 = qcar(v109);
    v109 = stack[0];
    v109 = cons(v108, v109);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[0] = v109;
    v109 = stack[-4];
    stack[-3] = v109;
    goto v91;

v156:
    v109 = stack[-3];
    v109 = qcdr(v109);
    stack[-4] = v109;
    v109 = stack[-3];
    v108 = qcar(v109);
    v109 = stack[-2];
    v109 = cons(v108, v109);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-2] = v109;
    v109 = stack[-4];
    stack[-3] = v109;
    goto v91;

v148:
    v109 = stack[-2];
    if (v109 == nil) goto v87;
    v108 = stack[-2];
    v109 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* re_parents */
        return (*qfn2(fn))(qenv(fn), v108, v109);
    }

v87:
    v109 = qvalue(elt(env, 1)); /* t */
    { popv(6); return onevalue(v109); }
/* error exit handlers */
v46:
    popv(6);
    return nil;
}



/* Code for simp!-prop!-form */

static Lisp_Object CC_simpKpropKform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187, v188;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-form");
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
    v187 = v0;
/* end of prologue */
    v188 = v187;
    v186 = elt(env, 1); /* (nil) */
    if (equal(v188, v186)) goto v133;
    v186 = v187;
    stack[-7] = v186;
    v186 = stack[-7];
    if (v186 == nil) goto v76;
    v186 = stack[-7];
    v186 = qcar(v186);
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v85;
    v186 = stack[-3];
    v186 = qcar(v186);
    v188 = v186;
    v187 = v188;
    v186 = elt(env, 4); /* not_prop!* */
    if (!consp(v187)) goto v189;
    v187 = qcar(v187);
    if (!(v187 == v186)) goto v189;
    v186 = elt(env, 5); /* not */
    v187 = v188;
    v187 = qcdr(v187);
    v187 = qcar(v187);
    v186 = list2(v186, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    goto v69;

v69:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-1] = v186;
    stack[-2] = v186;
    goto v134;

v134:
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v49;
    stack[0] = stack[-1];
    v186 = stack[-3];
    v186 = qcar(v186);
    v188 = v186;
    v187 = v188;
    v186 = elt(env, 4); /* not_prop!* */
    if (!consp(v187)) goto v32;
    v187 = qcar(v187);
    if (!(v187 == v186)) goto v32;
    v186 = elt(env, 5); /* not */
    v187 = v188;
    v187 = qcdr(v187);
    v187 = qcar(v187);
    v186 = list2(v186, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    goto v191;

v191:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = Lrplacd(nil, stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = stack[-1];
    v186 = qcdr(v186);
    stack[-1] = v186;
    goto v134;

v32:
    v186 = v188;
    v186 = qcdr(v186);
    v186 = qcar(v186);
    goto v191;

v49:
    v186 = stack[-2];
    goto v55;

v55:
    v187 = v186;
    v187 = qcdr(v187);
    if (v187 == nil) goto v99;
    v187 = qvalue(elt(env, 6)); /* !'and */
    v186 = cons(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    goto v192;

v192:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-5] = v186;
    stack[-6] = v186;
    goto v128;

v128:
    v186 = stack[-7];
    v186 = qcdr(v186);
    stack[-7] = v186;
    v186 = stack[-7];
    if (v186 == nil) goto v193;
    stack[-4] = stack[-5];
    v186 = stack[-7];
    v186 = qcar(v186);
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v14;
    v186 = stack[-3];
    v186 = qcar(v186);
    v188 = v186;
    v187 = v188;
    v186 = elt(env, 4); /* not_prop!* */
    if (!consp(v187)) goto v194;
    v187 = qcar(v187);
    if (!(v187 == v186)) goto v194;
    v186 = elt(env, 5); /* not */
    v187 = v188;
    v187 = qcdr(v187);
    v187 = qcar(v187);
    v186 = list2(v186, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    goto v195;

v195:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-1] = v186;
    stack[-2] = v186;
    goto v196;

v196:
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v197;
    stack[0] = stack[-1];
    v186 = stack[-3];
    v186 = qcar(v186);
    v188 = v186;
    v187 = v188;
    v186 = elt(env, 4); /* not_prop!* */
    if (!consp(v187)) goto v15;
    v187 = qcar(v187);
    if (!(v187 == v186)) goto v15;
    v186 = elt(env, 5); /* not */
    v187 = v188;
    v187 = qcdr(v187);
    v187 = qcar(v187);
    v186 = list2(v186, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    goto v22;

v22:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = Lrplacd(nil, stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = stack[-1];
    v186 = qcdr(v186);
    stack[-1] = v186;
    goto v196;

v15:
    v186 = v188;
    v186 = qcdr(v186);
    v186 = qcar(v186);
    goto v22;

v197:
    v186 = stack[-2];
    goto v74;

v74:
    v187 = v186;
    v187 = qcdr(v187);
    if (v187 == nil) goto v198;
    v187 = qvalue(elt(env, 6)); /* !'and */
    v186 = cons(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    goto v199;

v199:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = Lrplacd(nil, stack[-4], v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = stack[-5];
    v186 = qcdr(v186);
    stack[-5] = v186;
    goto v128;

v198:
    v186 = qcar(v186);
    goto v199;

v194:
    v186 = v188;
    v186 = qcdr(v186);
    v186 = qcar(v186);
    goto v195;

v14:
    v186 = qvalue(elt(env, 3)); /* nil */
    goto v74;

v193:
    v186 = stack[-6];
    goto v132;

v132:
    v187 = v186;
    v186 = v187;
    v186 = qcdr(v186);
    if (v186 == nil) goto v200;
    v186 = qvalue(elt(env, 7)); /* !'or */
    popv(9);
    return cons(v186, v187);

v200:
    v186 = v187;
    v186 = qcar(v186);
    { popv(9); return onevalue(v186); }

v99:
    v186 = qcar(v186);
    goto v192;

v189:
    v186 = v188;
    v186 = qcdr(v186);
    v186 = qcar(v186);
    goto v69;

v85:
    v186 = qvalue(elt(env, 3)); /* nil */
    goto v55;

v76:
    v186 = qvalue(elt(env, 3)); /* nil */
    goto v132;

v133:
    v186 = qvalue(elt(env, 2)); /* !'true */
    { popv(9); return onevalue(v186); }
/* error exit handlers */
v190:
    popv(9);
    return nil;
}



/* Code for bfminus */

static Lisp_Object CC_bfminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfminus");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v29 = v30;
    if (!consp(v29)) goto v133;
    v29 = v30;
    {
        fn = elt(env, 1); /* minus!: */
        return (*qfn1(fn))(qenv(fn), v29);
    }

v133:
    v29 = v30;
    return negate(v29);
}



/* Code for ofsf_ir2atl */

static Lisp_Object MS_CDECL CC_ofsf_ir2atl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_ir2atl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ir2atl");
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
    stack[0] = v1;
    stack[-5] = v0;
/* end of prologue */
    v104 = stack[0];
    v105 = qcar(v104);
    v104 = (Lisp_Object)17; /* 1 */
    v104 = cons(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-7];
    stack[-6] = v104;
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[-3] = v104;
    goto v70;

v70:
    v104 = stack[-3];
    if (v104 == nil) goto v76;
    v104 = stack[-3];
    v104 = qcar(v104);
    v105 = v104;
    v104 = v105;
    v102 = qcar(v104);
    v104 = stack[-4];
    if (equal(v102, v104)) goto v39;
    v104 = nil;
    goto v57;

v57:
    stack[-2] = v104;
    v104 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-7];
    stack[-1] = v104;
    v104 = stack[-3];
    v104 = qcdr(v104);
    stack[-3] = v104;
    v104 = stack[-1];
    if (!consp(v104)) goto v70;
    else goto v132;

v132:
    v104 = stack[-3];
    if (v104 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    stack[0] = stack[-1];
    v104 = stack[-3];
    v104 = qcar(v104);
    v105 = v104;
    v104 = v105;
    v102 = qcar(v104);
    v104 = stack[-4];
    if (equal(v102, v104)) goto v145;
    v104 = nil;
    goto v125;

v125:
    v104 = Lrplacd(nil, stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-7];
    v104 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-7];
    stack[-1] = v104;
    v104 = stack[-3];
    v104 = qcdr(v104);
    stack[-3] = v104;
    goto v132;

v145:
    v102 = stack[-5];
    v104 = v105;
    v105 = qcdr(v104);
    v104 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v104 = (*qfnn(fn))(qenv(fn), 3, v102, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-7];
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-7];
    goto v125;

v39:
    v102 = stack[-5];
    v104 = v105;
    v105 = qcdr(v104);
    v104 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v104 = (*qfnn(fn))(qenv(fn), 3, v102, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-7];
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-7];
    goto v57;

v76:
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v104); }
/* error exit handlers */
v202:
    popv(8);
    return nil;
}



/* Code for addinds */

static Lisp_Object CC_addinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addinds");
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
    goto v79;

v79:
    v53 = stack[-1];
    if (v53 == nil) goto v152;
    v53 = stack[0];
    if (v53 == nil) goto v83;
    v53 = stack[-1];
    v155 = qcar(v53);
    v53 = stack[0];
    v53 = qcar(v53);
    v53 = qcar(v53);
    v155 = plus2(v155, v53);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v53 = stack[-2];
    v53 = cons(v155, v53);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    stack[-2] = v53;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    v53 = stack[0];
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v79;

v83:
    stack[0] = stack[-2];
    v53 = elt(env, 2); /* "Powu too long" */
    fn = elt(env, 3); /* interr */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    {
        Lisp_Object v189 = stack[0];
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v189, v53);
    }

v152:
    v53 = stack[0];
    if (v53 == nil) goto v30;
    stack[0] = stack[-2];
    v53 = elt(env, 1); /* "Powrhs too long" */
    fn = elt(env, 3); /* interr */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    {
        Lisp_Object v203 = stack[0];
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v203, v53);
    }

v30:
    v53 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v53);
    }
/* error exit handlers */
v116:
    popv(4);
    return nil;
}



/* Code for impartf */

static Lisp_Object CC_impartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartf");
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
    v36 = elt(env, 1); /* i */
    v206 = qvalue(elt(env, 2)); /* kord!* */
    v206 = cons(v36, v206);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v206; /* kord!* */
    v206 = stack[0];
    fn = elt(env, 6); /* reorder */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    stack[-2] = v206;
    v206 = stack[-2];
    if (!consp(v206)) goto v87;
    v206 = stack[-2];
    v206 = qcar(v206);
    if (!consp(v206)) goto v87;
    v206 = stack[-2];
    v206 = qcar(v206);
    v206 = qcar(v206);
    v36 = qcar(v206);
    v206 = elt(env, 1); /* i */
    if (v36 == v206) goto v143;
    v206 = stack[-2];
    v206 = qcar(v206);
    v36 = qcar(v206);
    v206 = (Lisp_Object)17; /* 1 */
    v206 = cons(v36, v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    stack[0] = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v206 = stack[-2];
    v206 = qcar(v206);
    v206 = qcdr(v206);
    v206 = CC_impartf(env, v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    fn = elt(env, 7); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v206 = stack[-2];
    v206 = qcdr(v206);
    v206 = CC_impartf(env, v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    fn = elt(env, 8); /* addf */
    v206 = (*qfn2(fn))(qenv(fn), stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    goto v6;

v6:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v206); }

v143:
    v206 = stack[-2];
    v206 = qcar(v206);
    stack[0] = qcdr(v206);
    v206 = stack[-2];
    v206 = qcdr(v206);
    v206 = CC_impartf(env, v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    fn = elt(env, 8); /* addf */
    v206 = (*qfn2(fn))(qenv(fn), stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    goto v6;

v87:
    v206 = stack[-2];
    if (!consp(v206)) goto v76;
    v206 = stack[-2];
    v36 = qcar(v206);
    v206 = elt(env, 4); /* cmpxfn */
    v206 = get(v36, v206);
    env = stack[-4];
    if (v206 == nil) goto v189;
    v206 = stack[-2];
    stack[-1] = qcar(v206);
    v206 = stack[-2];
    v206 = qcdr(v206);
    stack[0] = qcdr(v206);
    v206 = stack[-2];
    v36 = qcar(v206);
    v206 = elt(env, 5); /* i2d */
    v36 = get(v36, v206);
    env = stack[-4];
    v206 = (Lisp_Object)1; /* 0 */
    v206 = Lapply1(nil, v36, v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v206 = qcdr(v206);
    v206 = qcar(v206);
    v206 = list2star(stack[-1], stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    fn = elt(env, 9); /* int!-equiv!-chk */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    goto v6;

v189:
    v206 = qvalue(elt(env, 3)); /* nil */
    goto v6;

v76:
    v206 = qvalue(elt(env, 3)); /* nil */
    goto v6;
/* error exit handlers */
v98:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v181:
    popv(5);
    return nil;
}



/* Code for ofsf_sacrel */

static Lisp_Object MS_CDECL CC_ofsf_sacrel(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v83, v54, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_sacrel");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v2;
    v54 = v1;
    v150 = v0;
/* end of prologue */
    v83 = v57;
    v57 = elt(env, 1); /* or */
    if (v83 == v57) goto v87;
    v57 = v150;
    v83 = v54;
    {
        fn = elt(env, 2); /* ofsf_sacrel!-and */
        return (*qfn2(fn))(qenv(fn), v57, v83);
    }

v87:
    v57 = v150;
    v83 = v54;
    {
        fn = elt(env, 3); /* ofsf_sacrel!-or */
        return (*qfn2(fn))(qenv(fn), v57, v83);
    }
}



/* Code for ps!:quotient!-erule */

static Lisp_Object CC_psTquotientKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:quotient-erule");
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
    stack[-7] = v1;
    v98 = v0;
/* end of prologue */
    v181 = v98;
    v181 = qcdr(v181);
    v181 = qcar(v181);
    stack[-8] = v181;
    v181 = v98;
    v181 = qcdr(v181);
    v181 = qcdr(v181);
    v181 = qcar(v181);
    stack[-6] = v181;
    v98 = qvalue(elt(env, 1)); /* nil */
    v181 = (Lisp_Object)17; /* 1 */
    v181 = cons(v98, v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    stack[0] = v181;
    v181 = stack[-6];
    fn = elt(env, 3); /* ps!:order */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    stack[-4] = v181;
    v181 = qvalue(elt(env, 2)); /* ps */
    fn = elt(env, 3); /* ps!:order */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    stack[-5] = v181;
    v181 = (Lisp_Object)17; /* 1 */
    stack[-3] = v181;
    goto v39;

v39:
    v98 = stack[-7];
    v181 = stack[-5];
    v98 = difference2(v98, v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    v181 = stack[-3];
    v181 = difference2(v98, v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    v181 = Lminusp(nil, v181);
    env = stack[-9];
    if (v181 == nil) goto v118;
    stack[-1] = stack[-8];
    v98 = stack[-7];
    v181 = stack[-4];
    v181 = plus2(v98, v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    v181 = stack[0];
    fn = elt(env, 5); /* negsq */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    fn = elt(env, 6); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-1], v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    v98 = stack[-6];
    v181 = stack[-4];
    fn = elt(env, 4); /* ps!:evaluate */
    v181 = (*qfn2(fn))(qenv(fn), v98, v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    {
        Lisp_Object v100 = stack[0];
        popv(10);
        fn = elt(env, 7); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v100, v181);
    }

v118:
    stack[-2] = stack[0];
    stack[0] = stack[-6];
    v98 = stack[-3];
    v181 = stack[-4];
    v181 = plus2(v98, v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 2)); /* ps */
    v98 = stack[-7];
    v181 = stack[-3];
    v181 = difference2(v98, v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    v181 = (*qfn2(fn))(qenv(fn), stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    fn = elt(env, 8); /* multsq */
    v181 = (*qfn2(fn))(qenv(fn), stack[-1], v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    fn = elt(env, 6); /* addsq */
    v181 = (*qfn2(fn))(qenv(fn), stack[-2], v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    stack[0] = v181;
    v181 = stack[-3];
    v181 = add1(v181);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-9];
    stack[-3] = v181;
    goto v39;
/* error exit handlers */
v210:
    popv(10);
    return nil;
}



/* Code for idsort */

static Lisp_Object CC_idsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v147 = v0;
/* end of prologue */
    v148 = v147;
    v147 = elt(env, 1); /* idcompare */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v148, v147);
    }
}



/* Code for vdpappendmon */

static Lisp_Object MS_CDECL CC_vdpappendmon(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v211, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpappendmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpappendmon");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v123 = stack[-4];
    if (v123 == nil) goto v131;
    v123 = stack[-4];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcar(v123);
    if (v123 == nil) goto v131;
    v123 = stack[-3];
    fn = elt(env, 3); /* vbczero!? */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-6];
    if (!(v123 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-5] = elt(env, 1); /* vdp */
    v123 = stack[-4];
    v123 = qcdr(v123);
    stack[-1] = qcar(v123);
    v123 = stack[-4];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    stack[0] = qcar(v123);
    v123 = stack[-4];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    stack[-4] = qcar(v123);
    v146 = stack[-2];
    v211 = stack[-3];
    v123 = qvalue(elt(env, 2)); /* nil */
    v123 = list2star(v146, v211, v123);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-6];
    fn = elt(env, 4); /* dipsum */
    v211 = (*qfn2(fn))(qenv(fn), stack[-4], v123);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-6];
    v123 = qvalue(elt(env, 2)); /* nil */
    v123 = list2(v211, v123);
    nil = C_nil;
    if (exception_pending()) goto v142;
    {
        Lisp_Object v143 = stack[-5];
        Lisp_Object v144 = stack[-1];
        Lisp_Object v121 = stack[0];
        popv(7);
        return list3star(v143, v144, v121, v123);
    }

v131:
    v211 = stack[-3];
    v123 = stack[-2];
    {
        popv(7);
        fn = elt(env, 5); /* vdpfmon */
        return (*qfn2(fn))(qenv(fn), v211, v123);
    }
/* error exit handlers */
v142:
    popv(7);
    return nil;
}



/* Code for preproc1 */

static Lisp_Object CC_preproc1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v285, v286, v287;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preproc1");
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

v133:
    v285 = stack[-1];
    if (!consp(v285)) goto v62;
    v285 = stack[-1];
    v286 = qcar(v285);
    v285 = elt(env, 1); /* !:rd!: */
    if (v286 == v285) goto v136;
    v285 = stack[-1];
    v286 = qcar(v285);
    v285 = elt(env, 2); /* !:dn!: */
    if (v286 == v285) goto v140;
    v285 = stack[-1];
    v286 = qcar(v285);
    v285 = elt(env, 3); /* !*sq */
    if (v286 == v285) goto v191;
    v285 = stack[-1];
    v286 = qcar(v285);
    v285 = elt(env, 4); /* procedure */
    if (v286 == v285) goto v40;
    v285 = stack[-1];
    v286 = qcar(v285);
    v285 = elt(env, 10); /* declare */
    if (v286 == v285) goto v288;
    v285 = stack[-1];
    v286 = qcar(v285);
    v285 = elt(env, 13); /* setq */
    if (!(v286 == v285)) goto v289;
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcar(v285);
    v285 = Lconsp(nil, v285);
    env = stack[-5];
    if (v285 == nil) goto v289;
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcar(v285);
    v286 = qcar(v285);
    v285 = elt(env, 14); /* (cond progn) */
    v285 = Lmemq(nil, v286, v285);
    if (v285 == nil) goto v289;
    v285 = stack[-1];
    {
        popv(6);
        fn = elt(env, 20); /* migrate!-setqs */
        return (*qfn1(fn))(qenv(fn), v285);
    }

v289:
    v285 = stack[-1];
    v286 = qcar(v285);
    v285 = elt(env, 15); /* (plus times difference quotient minus) */
    v285 = Lmemq(nil, v286, v285);
    if (v285 == nil) goto v290;
    v285 = stack[-1];
    fn = elt(env, 21); /* simp!* */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v287 = v285;
    v285 = qcar(v285);
    v285 = Lconsp(nil, v285);
    env = stack[-5];
    if (v285 == nil) goto v292;
    v285 = v287;
    v285 = qcar(v285);
    v286 = qcar(v285);
    v285 = elt(env, 16); /* (!:cr!: !:crn!: !:gi!:) */
    v285 = Lmemq(nil, v286, v285);
    if (v285 == nil) goto v292;
    v285 = v287;
    v285 = qcdr(v285);
    v285 = Lonep(nil, v285);
    env = stack[-5];
    if (v285 == nil) goto v293;
    v285 = v287;
    v285 = qcar(v285);
    popv(6);
    return ncons(v285);

v293:
    stack[-1] = elt(env, 17); /* quotient */
    v285 = v287;
    stack[0] = qcar(v285);
    v285 = v287;
    v286 = qcdr(v285);
    v285 = (Lisp_Object)17; /* 1 */
    v285 = cons(v286, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    fn = elt(env, 22); /* prepsq */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = qcar(v285);
    v285 = list3(stack[-1], stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    popv(6);
    return ncons(v285);

v292:
    v285 = stack[-1];
    stack[-3] = v285;
    goto v294;

v294:
    v285 = stack[-3];
    if (v285 == nil) goto v295;
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-2] = v285;
    v285 = stack[-2];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    v285 = stack[-1];
    if (!consp(v285)) goto v294;
    else goto v296;

v296:
    v285 = stack[-3];
    if (v285 == nil) goto v297;
    stack[0] = stack[-1];
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = Lrplacd(nil, stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-1];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v296;

v297:
    v285 = stack[-2];
    goto v298;

v298:
    popv(6);
    return ncons(v285);

v295:
    v285 = qvalue(elt(env, 8)); /* nil */
    goto v298;

v290:
    v285 = qvalue(elt(env, 6)); /* !*getdecs */
    if (v285 == nil) goto v299;
    v285 = stack[-1];
    v286 = qcar(v285);
    v285 = elt(env, 18); /* (!~for for) */
    v285 = Lmemq(nil, v286, v285);
    if (v285 == nil) goto v299;
    v287 = qvalue(elt(env, 8)); /* nil */
    v285 = stack[-1];
    v285 = qcdr(v285);
    v286 = qcar(v285);
    v285 = elt(env, 19); /* (integer) */
    fn = elt(env, 24); /* symtabput */
    v285 = (*qfnn(fn))(qenv(fn), 3, v287, v286, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    goto v299;

v299:
    v285 = stack[-1];
    stack[-3] = v285;
    goto v300;

v300:
    v285 = stack[-3];
    if (v285 == nil) goto v301;
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-2] = v285;
    v285 = stack[-2];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    v285 = stack[-1];
    if (!consp(v285)) goto v300;
    else goto v302;

v302:
    v285 = stack[-3];
    if (v285 == nil) goto v303;
    stack[0] = stack[-1];
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = Lrplacd(nil, stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-1];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v302;

v303:
    v285 = stack[-2];
    goto v304;

v304:
    popv(6);
    return ncons(v285);

v301:
    v285 = qvalue(elt(env, 8)); /* nil */
    goto v304;

v288:
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = qcar(v285);
    stack[-1] = v285;
    v285 = stack[-1];
    fn = elt(env, 25); /* preprocdec */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-1];
    stack[-4] = v285;
    goto v305;

v305:
    v285 = stack[-4];
    if (v285 == nil) goto v306;
    v285 = stack[-4];
    v285 = qcar(v285);
    stack[-3] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-2] = v285;
    goto v307;

v307:
    v285 = stack[-2];
    if (v285 == nil) goto v308;
    v285 = stack[-2];
    v285 = qcar(v285);
    v287 = v285;
    v285 = stack[-3];
    v286 = qcar(v285);
    v285 = elt(env, 11); /* (subroutine function) */
    v285 = Lmemq(nil, v286, v285);
    if (v285 == nil) goto v309;
    v286 = elt(env, 12); /* !*type!* */
    v285 = stack[-3];
    v285 = qcar(v285);
    fn = elt(env, 24); /* symtabput */
    v285 = (*qfnn(fn))(qenv(fn), 3, v287, v286, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    goto v310;

v310:
    v285 = stack[-2];
    v285 = qcdr(v285);
    stack[-2] = v285;
    goto v307;

v309:
    stack[-1] = qvalue(elt(env, 8)); /* nil */
    v285 = v287;
    if (!consp(v285)) goto v311;
    v285 = v287;
    v285 = qcar(v285);
    stack[0] = v285;
    goto v312;

v312:
    v285 = v287;
    if (!consp(v285)) goto v313;
    v285 = stack[-3];
    v285 = qcar(v285);
    v286 = v287;
    v286 = qcdr(v286);
    v285 = cons(v285, v286);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    goto v314;

v314:
    fn = elt(env, 24); /* symtabput */
    v285 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    goto v310;

v313:
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = ncons(v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    goto v314;

v311:
    v285 = v287;
    stack[0] = v285;
    goto v312;

v308:
    v285 = stack[-4];
    v285 = qcdr(v285);
    stack[-4] = v285;
    goto v305;

v306:
    v285 = qvalue(elt(env, 8)); /* nil */
    { popv(6); return onevalue(v285); }

v40:
    v285 = stack[-1];
    v285 = qcdr(v285);
    v287 = qcar(v285);
    v286 = elt(env, 5); /* !*params!* */
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcar(v285);
    fn = elt(env, 24); /* symtabput */
    v285 = (*qfnn(fn))(qenv(fn), 3, v287, v286, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = qvalue(elt(env, 6)); /* !*getdecs */
    if (v285 == nil) goto v315;
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v286 = qcar(v285);
    v285 = elt(env, 7); /* (real integer) */
    v285 = Lmemq(nil, v286, v285);
    if (v285 == nil) goto v316;
    v285 = stack[-1];
    v285 = qcdr(v285);
    stack[-2] = qcar(v285);
    v285 = stack[-1];
    v285 = qcdr(v285);
    stack[0] = qcar(v285);
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcar(v285);
    v285 = ncons(v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    fn = elt(env, 24); /* symtabput */
    v285 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcar(v285);
    stack[-3] = v285;
    goto v317;

v317:
    v285 = stack[-3];
    if (v285 == nil) goto v168;
    v285 = stack[-3];
    v285 = qcar(v285);
    v286 = v285;
    v285 = stack[-1];
    v285 = qcdr(v285);
    stack[-2] = qcar(v285);
    stack[0] = v286;
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcar(v285);
    v285 = ncons(v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    fn = elt(env, 24); /* symtabput */
    v285 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v317;

v168:
    v287 = elt(env, 4); /* procedure */
    v285 = stack[-1];
    v285 = qcdr(v285);
    v286 = qcar(v285);
    v285 = nil;
    stack[-4] = list3(v287, v286, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v318;

v318:
    v285 = stack[-3];
    if (v285 == nil) goto v319;
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-2] = v285;
    v285 = stack[-2];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    v285 = stack[-1];
    if (!consp(v285)) goto v318;
    else goto v320;

v320:
    v285 = stack[-3];
    if (v285 == nil) goto v13;
    stack[0] = stack[-1];
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = Lrplacd(nil, stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-1];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v320;

v13:
    v285 = stack[-2];
    goto v166;

v166:
    v285 = Lnconc(nil, stack[-4], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    popv(6);
    return ncons(v285);

v319:
    v285 = qvalue(elt(env, 8)); /* nil */
    goto v166;

v316:
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    v285 = qcar(v285);
    stack[-3] = v285;
    goto v188;

v188:
    v285 = stack[-3];
    if (v285 == nil) goto v187;
    v285 = stack[-3];
    v285 = qcar(v285);
    v286 = v285;
    v285 = stack[-1];
    v285 = qcdr(v285);
    stack[-2] = qcar(v285);
    stack[0] = v286;
    v285 = qvalue(elt(env, 9)); /* deftype!* */
    v285 = ncons(v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    fn = elt(env, 24); /* symtabput */
    v285 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v188;

v187:
    v285 = stack[-1];
    stack[-3] = v285;
    goto v321;

v321:
    v285 = stack[-3];
    if (v285 == nil) goto v322;
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-2] = v285;
    v285 = stack[-2];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    v285 = stack[-1];
    if (!consp(v285)) goto v321;
    else goto v323;

v323:
    v285 = stack[-3];
    if (v285 == nil) goto v324;
    stack[0] = stack[-1];
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = Lrplacd(nil, stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-1];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v323;

v324:
    v285 = stack[-2];
    goto v325;

v325:
    popv(6);
    return ncons(v285);

v322:
    v285 = qvalue(elt(env, 8)); /* nil */
    goto v325;

v315:
    v285 = stack[-1];
    stack[-3] = v285;
    goto v326;

v326:
    v285 = stack[-3];
    if (v285 == nil) goto v327;
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-2] = v285;
    v285 = stack[-2];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    v285 = stack[-1];
    if (!consp(v285)) goto v326;
    else goto v328;

v328:
    v285 = stack[-3];
    if (v285 == nil) goto v329;
    stack[0] = stack[-1];
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = CC_preproc1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = Lrplacd(nil, stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    v285 = stack[-1];
    fn = elt(env, 23); /* lastpair */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v328;

v329:
    v285 = stack[-2];
    goto v330;

v330:
    popv(6);
    return ncons(v285);

v327:
    v285 = qvalue(elt(env, 8)); /* nil */
    goto v330;

v191:
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcar(v285);
    fn = elt(env, 22); /* prepsq */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    goto v133;

v140:
    v285 = stack[-1];
    v285 = qcdr(v285);
    v286 = qcar(v285);
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = qcdr(v285);
    fn = elt(env, 26); /* decimal2internal */
    v285 = (*qfn2(fn))(qenv(fn), v286, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    stack[-1] = v285;
    goto v133;

v136:
    v285 = stack[-1];
    v285 = qcdr(v285);
    if (!consp(v285)) goto v76;
    v285 = stack[-1];
    goto v75;

v75:
    popv(6);
    return ncons(v285);

v76:
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = Lfloatp(nil, v285);
    env = stack[-5];
    if (v285 == nil) goto v135;
    v285 = stack[-1];
    v285 = qcdr(v285);
    fn = elt(env, 27); /* fl2bf */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    goto v75;

v135:
    v285 = stack[-1];
    v285 = qcdr(v285);
    if (!consp(v285)) goto v127;
    v285 = stack[-1];
    v285 = qcdr(v285);
    goto v111;

v111:
    fn = elt(env, 28); /* csl_normbf */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    goto v75;

v127:
    v285 = stack[-1];
    v285 = qcdr(v285);
    v285 = integerp(v285);
    if (v285 == nil) goto v155;
    v287 = elt(env, 1); /* !:rd!: */
    v285 = stack[-1];
    v286 = qcdr(v285);
    v285 = (Lisp_Object)1; /* 0 */
    v285 = list2star(v287, v286, v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    goto v111;

v155:
    v285 = stack[-1];
    v285 = qcdr(v285);
    fn = elt(env, 29); /* read!:num */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-5];
    goto v111;

v62:
    v285 = stack[-1];
    popv(6);
    return ncons(v285);
/* error exit handlers */
v291:
    popv(6);
    return nil;
}



/* Code for pnth!* */

static Lisp_Object CC_pnthH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v141, v139;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnth*");
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
    v141 = v1;
    stack[0] = v0;
/* end of prologue */

v120:
    v78 = stack[0];
    if (v78 == nil) goto v91;
    v139 = v141;
    v78 = (Lisp_Object)17; /* 1 */
    if (v139 == v78) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v78 = stack[0];
    v78 = qcdr(v78);
    stack[0] = v78;
    v78 = v141;
    v78 = sub1(v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-1];
    v141 = v78;
    goto v120;

v91:
    v78 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v78); }
/* error exit handlers */
v80:
    popv(2);
    return nil;
}



/* Code for listquotient */

static Lisp_Object CC_listquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v135, v65, v84;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listquotient");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v1;
    v84 = v0;
/* end of prologue */
    v135 = v65;
    v134 = (Lisp_Object)17; /* 1 */
    if (v135 == v134) return onevalue(v84);
    v135 = v65;
    v134 = v84;
    if (equal(v135, v134)) goto v6;
    v134 = elt(env, 1); /* quotient */
    v135 = v84;
    return list3(v134, v135, v65);

v6:
    v134 = (Lisp_Object)17; /* 1 */
    return onevalue(v134);
}



/* Code for normmat */

static Lisp_Object CC_normmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v336, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for normmat");
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
    v193 = v0;
/* end of prologue */
    stack[-6] = nil;
    v336 = (Lisp_Object)17; /* 1 */
    stack[-8] = v336;
    v336 = v193;
    stack[-5] = v336;
    goto v148;

v148:
    v336 = stack[-5];
    if (v336 == nil) goto v98;
    v336 = stack[-5];
    v336 = qcar(v336);
    stack[-1] = v336;
    v336 = (Lisp_Object)17; /* 1 */
    stack[-7] = v336;
    v336 = stack[-1];
    stack[0] = v336;
    goto v119;

v119:
    v336 = stack[0];
    if (v336 == nil) goto v42;
    v336 = stack[0];
    v336 = qcar(v336);
    v193 = stack[-7];
    v336 = qcdr(v336);
    fn = elt(env, 2); /* lcm */
    v336 = (*qfn2(fn))(qenv(fn), v193, v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    stack[-7] = v336;
    v336 = stack[0];
    v336 = qcdr(v336);
    stack[0] = v336;
    goto v119;

v42:
    v336 = stack[-1];
    stack[-4] = v336;
    v336 = stack[-4];
    if (v336 == nil) goto v93;
    v336 = stack[-4];
    v336 = qcar(v336);
    v193 = v336;
    stack[0] = qcar(v193);
    v193 = stack[-7];
    v336 = qcdr(v336);
    fn = elt(env, 3); /* quotf */
    v336 = (*qfn2(fn))(qenv(fn), v193, v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    fn = elt(env, 4); /* multf */
    v336 = (*qfn2(fn))(qenv(fn), stack[0], v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    v336 = ncons(v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    stack[-2] = v336;
    stack[-3] = v336;
    goto v137;

v137:
    v336 = stack[-4];
    v336 = qcdr(v336);
    stack[-4] = v336;
    v336 = stack[-4];
    if (v336 == nil) goto v182;
    stack[-1] = stack[-2];
    v336 = stack[-4];
    v336 = qcar(v336);
    v193 = v336;
    stack[0] = qcar(v193);
    v193 = stack[-7];
    v336 = qcdr(v336);
    fn = elt(env, 3); /* quotf */
    v336 = (*qfn2(fn))(qenv(fn), v193, v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    fn = elt(env, 4); /* multf */
    v336 = (*qfn2(fn))(qenv(fn), stack[0], v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    v336 = ncons(v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    v336 = Lrplacd(nil, stack[-1], v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    v336 = stack[-2];
    v336 = qcdr(v336);
    stack[-2] = v336;
    goto v137;

v182:
    v336 = stack[-3];
    v193 = v336;
    goto v69;

v69:
    v336 = stack[-6];
    v336 = cons(v193, v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    stack[-6] = v336;
    v193 = stack[-7];
    v336 = stack[-8];
    fn = elt(env, 4); /* multf */
    v336 = (*qfn2(fn))(qenv(fn), v193, v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-9];
    stack[-8] = v336;
    v336 = stack[-5];
    v336 = qcdr(v336);
    stack[-5] = v336;
    goto v148;

v93:
    v336 = qvalue(elt(env, 1)); /* nil */
    v193 = v336;
    goto v69;

v98:
    v336 = stack[-6];
    v193 = Lreverse(nil, v336);
    nil = C_nil;
    if (exception_pending()) goto v159;
    v336 = stack[-8];
    popv(10);
    return cons(v193, v336);
/* error exit handlers */
v159:
    popv(10);
    return nil;
}



/* Code for prepcadr */

static Lisp_Object CC_prepcadr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepcadr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v79 = v0;
/* end of prologue */
    v79 = qcdr(v79);
    v79 = qcar(v79);
    {
        fn = elt(env, 1); /* prepsq */
        return (*qfn1(fn))(qenv(fn), v79);
    }
}



/* Code for !*hfac */

static Lisp_Object CC_Hhfac(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v31, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *hfac");
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
    v42 = stack[0];
    v42 = integerp(v42);
    if (v42 == nil) goto v78;
    v31 = stack[0];
    v42 = (Lisp_Object)1; /* 0 */
    v42 = (Lisp_Object)lessp2(v31, v42);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v42 = v42 ? lisp_true : nil;
    env = stack[-1];
    if (!(v42 == nil)) goto v78;
    v31 = stack[0];
    v42 = (Lisp_Object)33; /* 2 */
    v42 = (Lisp_Object)greaterp2(v31, v42);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v42 = v42 ? lisp_true : nil;
    env = stack[-1];
    if (!(v42 == nil)) goto v78;
    v42 = elt(env, 3); /* hfactors */
    fn = elt(env, 4); /* getavalue */
    v31 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v42 = stack[0];
    v42 = *(Lisp_Object *)((char *)v31 + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL)));
    { popv(2); return onevalue(v42); }

v78:
    v69 = elt(env, 1); /* avector */
    v31 = (Lisp_Object)209; /* 13 */
    v42 = elt(env, 2); /* "Invalid index" */
    {
        popv(2);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v69, v31, v42);
    }
/* error exit handlers */
v82:
    popv(2);
    return nil;
}



/* Code for general!-modular!-difference */

static Lisp_Object CC_generalKmodularKdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-difference");
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
    v54 = v1;
    v150 = v0;
/* end of prologue */
    v54 = difference2(v150, v54);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-1];
    stack[0] = v54;
    v150 = stack[0];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)lessp2(v150, v54);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v54 = v54 ? lisp_true : nil;
    env = stack[-1];
    if (v54 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v150 = stack[0];
    v54 = qvalue(elt(env, 1)); /* current!-modulus */
    v54 = plus2(v150, v54);
    nil = C_nil;
    if (exception_pending()) goto v134;
    stack[0] = v54;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v134:
    popv(2);
    return nil;
}



/* Code for eval!-yetunknowntypeexpr */

static Lisp_Object CC_evalKyetunknowntypeexpr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eval-yetunknowntypeexpr");
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
    stack[0] = v0;
/* end of prologue */

v149:
    v196 = stack[0];
    if (!consp(v196)) goto v152;
    v196 = stack[0];
    v4 = qcar(v196);
    v196 = elt(env, 2); /* !*sq */
    if (v4 == v196) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v196 = stack[0];
    v4 = qcar(v196);
    v196 = elt(env, 3); /* dname */
    v196 = get(v4, v196);
    env = stack[-6];
    if (!(v196 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v196 = stack[0];
    v4 = qcar(v196);
    v196 = elt(env, 4); /* !:dn!: */
    if (v4 == v196) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v196 = stack[0];
    v4 = qcar(v196);
    v196 = elt(env, 5); /* psopfn */
    v196 = get(v4, v196);
    env = stack[-6];
    stack[-1] = v196;
    v196 = stack[-1];
    if (v196 == nil) goto v201;
    v196 = stack[0];
    fn = elt(env, 8); /* getrtype */
    v4 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-6];
    v196 = elt(env, 6); /* yetunknowntype */
    if (!(v4 == v196)) goto v201;
    v4 = stack[-1];
    v196 = stack[0];
    v196 = qcdr(v196);
        popv(7);
        return Lapply1(nil, v4, v196);

v201:
    v196 = stack[0];
    stack[-5] = qcar(v196);
    v196 = stack[0];
    v196 = qcdr(v196);
    stack[-3] = v196;
    v196 = stack[-3];
    if (v196 == nil) goto v40;
    v196 = stack[-3];
    v196 = qcar(v196);
    v4 = v196;
    v196 = stack[-4];
    v196 = CC_evalKyetunknowntypeexpr(env, v4, v196);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-6];
    v196 = ncons(v196);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-6];
    stack[-1] = v196;
    stack[-2] = v196;
    goto v183;

v183:
    v196 = stack[-3];
    v196 = qcdr(v196);
    stack[-3] = v196;
    v196 = stack[-3];
    if (v196 == nil) goto v37;
    stack[0] = stack[-1];
    v196 = stack[-3];
    v196 = qcar(v196);
    v4 = v196;
    v196 = stack[-4];
    v196 = CC_evalKyetunknowntypeexpr(env, v4, v196);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-6];
    v196 = ncons(v196);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-6];
    v196 = Lrplacd(nil, stack[0], v196);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-6];
    v196 = stack[-1];
    v196 = qcdr(v196);
    stack[-1] = v196;
    goto v183;

v37:
    v196 = stack[-2];
    goto v68;

v68:
    {
        Lisp_Object v113 = stack[-5];
        popv(7);
        return cons(v113, v196);
    }

v40:
    v196 = qvalue(elt(env, 7)); /* nil */
    goto v68;

v152:
    v4 = stack[0];
    v196 = elt(env, 1); /* avalue */
    v196 = get(v4, v196);
    env = stack[-6];
    v4 = v196;
    v196 = v4;
    if (v196 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v196 = v4;
    v196 = qcdr(v196);
    v4 = qcar(v196);
    v196 = stack[-4];
    stack[0] = v4;
    stack[-4] = v196;
    goto v149;
/* error exit handlers */
v5:
    popv(7);
    return nil;
}



/* Code for subdf */

static Lisp_Object MS_CDECL CC_subdf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subdf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subdf");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v149:
    v104 = stack[-4];
    if (v104 == nil) goto v79;
    v104 = stack[-4];
    v104 = qcar(v104);
    v104 = qcdr(v104);
    stack[0] = qcar(v104);
    v105 = stack[-2];
    v104 = stack[-3];
    v104 = cons(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    fn = elt(env, 2); /* subf */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    fn = elt(env, 3); /* subs2q */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    stack[-5] = v104;
    stack[0] = stack[-5];
    v105 = qvalue(elt(env, 1)); /* nil */
    v104 = (Lisp_Object)17; /* 1 */
    v104 = cons(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    if (equal(stack[0], v104)) goto v81;
    v104 = stack[-4];
    v104 = qcar(v104);
    stack[-1] = qcar(v104);
    v104 = stack[-5];
    stack[0] = qcar(v104);
    v104 = stack[-5];
    v105 = qcdr(v104);
    v104 = stack[-4];
    v104 = qcar(v104);
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    fn = elt(env, 4); /* !*multf */
    v104 = (*qfn2(fn))(qenv(fn), v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    v104 = list2star(stack[-1], stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    stack[0] = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    v104 = stack[-4];
    v102 = qcdr(v104);
    v105 = stack[-3];
    v104 = stack[-2];
    v104 = CC_subdf(env, 3, v102, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-6];
    {
        Lisp_Object v202 = stack[0];
        popv(7);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v202, v104);
    }

v81:
    v104 = stack[-4];
    v102 = qcdr(v104);
    v105 = stack[-3];
    v104 = stack[-2];
    stack[-4] = v102;
    stack[-3] = v105;
    stack[-2] = v104;
    goto v149;

v79:
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v104); }
/* error exit handlers */
v284:
    popv(7);
    return nil;
}



/* Code for ps!:term!-rthpow */

static Lisp_Object MS_CDECL CC_psTtermKrthpow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:term-rthpow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:term-rthpow");
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
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v92 = stack[-3];
    v90 = stack[-2];
    fn = elt(env, 2); /* ps!:get!-term */
    v90 = (*qfn2(fn))(qenv(fn), v92, v90);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[-4] = v90;
    v90 = stack[-4];
    if (!(v90 == nil)) goto v82;
    v90 = stack[-3];
    fn = elt(env, 3); /* ps!:last!-term */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    v90 = add1(v90);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[0] = v90;
    goto v83;

v83:
    v92 = stack[-2];
    v90 = stack[0];
    v90 = difference2(v92, v90);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    v90 = Lminusp(nil, v90);
    env = stack[-5];
    if (!(v90 == nil)) goto v82;
    v92 = stack[-3];
    v90 = stack[0];
    fn = elt(env, 4); /* ps!:set!-rthpow */
    v90 = (*qfn2(fn))(qenv(fn), v92, v90);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[-4] = v90;
    v90 = stack[0];
    v90 = add1(v90);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[0] = v90;
    goto v83;

v82:
    v92 = stack[-4];
    v90 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); /* ps!:evaluate */
        return (*qfn2(fn))(qenv(fn), v92, v90);
    }
/* error exit handlers */
v50:
    popv(6);
    return nil;
}



/* Code for vdpsimpcont */

static Lisp_Object CC_vdpsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v137, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsimpcont");
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
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    stack[0] = v89;
    v89 = stack[0];
    if (v89 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v89 = stack[0];
    fn = elt(env, 2); /* dipsimpcont */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    stack[-2] = v89;
    v89 = stack[-2];
    v89 = qcdr(v89);
    fn = elt(env, 3); /* dip2vdp */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    stack[-1] = v89;
    v89 = stack[-2];
    v89 = qcar(v89);
    stack[-2] = v89;
    v89 = stack[-2];
    fn = elt(env, 4); /* evzero!? */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    if (!(v89 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    if (!(v89 == nil)) goto v41;
    v89 = stack[-2];
    fn = elt(env, 5); /* evtdeg */
    v137 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v89 = (Lisp_Object)17; /* 1 */
    v89 = (Lisp_Object)greaterp2(v137, v89);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v89 = v89 ? lisp_true : nil;
    env = stack[-3];
    if (v89 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else goto v41;

v41:
    v138 = stack[-1];
    v137 = elt(env, 1); /* monfac */
    v89 = stack[-2];
    fn = elt(env, 6); /* vdpputprop */
    v89 = (*qfnn(fn))(qenv(fn), 3, v138, v137, v89);
    nil = C_nil;
    if (exception_pending()) goto v52;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v52:
    popv(4);
    return nil;
}



/* Code for r2oreaction */

static Lisp_Object MS_CDECL CC_r2oreaction(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v173, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "r2oreaction");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2oreaction");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v3;
    v174 = v2;
    stack[-5] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-6] = v174;
    v174 = stack[-1];
    stack[-2] = v174;
    goto v29;

v29:
    v174 = stack[-2];
    if (v174 == nil) goto v136;
    v174 = stack[-2];
    v174 = qcar(v174);
    stack[0] = elt(env, 2); /* times */
    stack[-3] = stack[-6];
    v164 = elt(env, 3); /* expt */
    v173 = v174;
    v173 = qcdr(v173);
    v174 = qcar(v174);
    v174 = list3(v164, v173, v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    v174 = list3(stack[0], stack[-3], v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    fn = elt(env, 6); /* aeval */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    stack[-6] = v174;
    v174 = stack[-2];
    v174 = qcdr(v174);
    stack[-2] = v174;
    goto v29;

v136:
    v174 = stack[-1];
    stack[-3] = v174;
    goto v82;

v82:
    v174 = stack[-3];
    if (v174 == nil) goto v67;
    v174 = stack[-3];
    v174 = qcar(v174);
    v173 = v174;
    v164 = qcdr(v173);
    v173 = stack[-4];
    v173 = Lassoc(nil, v164, v173);
    stack[-2] = v173;
    stack[-1] = elt(env, 4); /* difference */
    stack[0] = qcdr(v173);
    v164 = elt(env, 2); /* times */
    v173 = stack[-6];
    v174 = qcar(v174);
    v174 = list3(v164, v173, v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    v174 = list3(stack[-1], stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    v174 = Lrplacd(nil, stack[-2], v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    v174 = stack[-3];
    v174 = qcdr(v174);
    stack[-3] = v174;
    goto v82;

v67:
    v174 = stack[-5];
    stack[-3] = v174;
    goto v130;

v130:
    v174 = stack[-3];
    if (v174 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v174 = stack[-3];
    v174 = qcar(v174);
    v173 = v174;
    v164 = qcdr(v173);
    v173 = stack[-4];
    v173 = Lassoc(nil, v164, v173);
    stack[-2] = v173;
    stack[-1] = elt(env, 5); /* plus */
    stack[0] = qcdr(v173);
    v164 = elt(env, 2); /* times */
    v173 = stack[-6];
    v174 = qcar(v174);
    v174 = list3(v164, v173, v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    v174 = list3(stack[-1], stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    v174 = Lrplacd(nil, stack[-2], v174);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-7];
    v174 = stack[-3];
    v174 = qcdr(v174);
    stack[-3] = v174;
    goto v130;
/* error exit handlers */
v18:
    popv(8);
    return nil;
}



/* Code for chksymmetries!&sub1 */

static Lisp_Object MS_CDECL CC_chksymmetriesGsub1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v55, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&sub1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chksymmetries&sub1");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    v150 = v2;
    v55 = v1;
    v134 = v0;
/* end of prologue */
    v150 = Lsubst(nil, 3, v134, v55, v150);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    stack[-1] = v150;
    v150 = stack[0];
    if (v150 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v55 = stack[-1];
    v150 = stack[0];
    fn = elt(env, 2); /* indxsymp */
    v150 = (*qfn2(fn))(qenv(fn), v55, v150);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    if (!(v150 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v150 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v150); }
/* error exit handlers */
v84:
    popv(3);
    return nil;
}



/* Code for defined_vertex */

static Lisp_Object CC_defined_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defined_vertex");
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

v120:
    v80 = stack[-1];
    if (v80 == nil) goto v91;
    v80 = stack[-1];
    v57 = qcar(v80);
    v80 = stack[0];
    fn = elt(env, 3); /* memq_edgelist */
    v80 = (*qfn2(fn))(qenv(fn), v57, v80);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    if (v80 == nil) goto v141;
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v120;

v141:
    v80 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v80); }

v91:
    v80 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v80); }
/* error exit handlers */
v150:
    popv(3);
    return nil;
}



/* Code for red_extract */

static Lisp_Object CC_red_extract(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_extract");
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
    stack[0] = (Lisp_Object)1; /* 0 */
    v65 = stack[-2];
    fn = elt(env, 1); /* bas_rep */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    fn = elt(env, 2); /* dp_comp */
    v65 = (*qfn2(fn))(qenv(fn), stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    stack[-3] = v65;
    v65 = stack[-2];
    fn = elt(env, 3); /* bas_nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v65 = stack[-2];
    fn = elt(env, 4); /* bas_dpoly */
    stack[0] = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v65 = stack[-2];
    fn = elt(env, 1); /* bas_rep */
    v84 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v65 = stack[-3];
    fn = elt(env, 5); /* dp_diff */
    v65 = (*qfn2(fn))(qenv(fn), v84, v65);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    fn = elt(env, 6); /* bas_make1 */
    v84 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v65 = stack[-3];
    popv(5);
    return cons(v84, v65);
/* error exit handlers */
v39:
    popv(5);
    return nil;
}



/* Code for can_rep_cell */

static Lisp_Object CC_can_rep_cell(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129, v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for can_rep_cell");
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
    push(nil);
/* copy arguments values to proper place */
    v86 = v1;
    v128 = v0;
/* end of prologue */
    v128 = qcdr(v128);
    v129 = qcar(v128);
    v128 = (Lisp_Object)17; /* 1 */
    stack[0] = *(Lisp_Object *)((char *)v129 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    v128 = v86;
    v128 = sub1(v128);
    nil = C_nil;
    if (exception_pending()) goto v76;
    v128 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    { popv(1); return onevalue(v128); }
/* error exit handlers */
v76:
    popv(1);
    return nil;
}



/* Code for ofsf_surep */

static Lisp_Object CC_ofsf_surep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_surep");
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
    v128 = v1;
    v129 = v0;
/* end of prologue */
    v86 = v129;
    v129 = v128;
    v128 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* cl_simpl */
    v128 = (*qfnn(fn))(qenv(fn), 3, v86, v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[0];
    v129 = elt(env, 1); /* true */
    v128 = (v128 == v129 ? lisp_true : nil);
    { popv(1); return onevalue(v128); }
/* error exit handlers */
v75:
    popv(1);
    return nil;
}



/* Code for reprod */

static Lisp_Object CC_reprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reprod");
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

v120:
    v80 = stack[-1];
    if (v80 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v80 = stack[-1];
    v57 = qcar(v80);
    v80 = (Lisp_Object)17; /* 1 */
    v80 = cons(v57, v80);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    v57 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    v80 = stack[0];
    fn = elt(env, 2); /* multf */
    v80 = (*qfn2(fn))(qenv(fn), v57, v80);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    stack[0] = v80;
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v120;
/* error exit handlers */
v150:
    popv(3);
    return nil;
}



/* Code for transferrow1 */

static Lisp_Object CC_transferrow1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow1");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v126 = qvalue(elt(env, 2)); /* maxvar */
    v81 = stack[0];
    v81 = plus2(v126, v81);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v126 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v81/(16/CELL)));
    v81 = (Lisp_Object)81; /* 5 */
    v81 = *(Lisp_Object *)((char *)v126 + (CELL-TAG_VECTOR) + ((int32_t)v81/(16/CELL)));
    if (v81 == nil) goto v150;
    v81 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v81); }

v150:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v126 = qvalue(elt(env, 2)); /* maxvar */
    v81 = stack[0];
    v81 = plus2(v126, v81);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v126 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v81/(16/CELL)));
    v81 = (Lisp_Object)49; /* 3 */
    v81 = *(Lisp_Object *)((char *)v126 + (CELL-TAG_VECTOR) + ((int32_t)v81/(16/CELL)));
    v81 = (is_number(v81) ? lisp_true : nil);
    { popv(3); return onevalue(v81); }
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for vdpfmon */

static Lisp_Object CC_vdpfmon(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpfmon");
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
    v41 = v0;
/* end of prologue */
    stack[-5] = elt(env, 1); /* vdp */
    stack[-3] = stack[-4];
    stack[-2] = v41;
    stack[-1] = stack[-4];
    stack[0] = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-6];
    v41 = qvalue(elt(env, 2)); /* nil */
    v41 = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-6];
    v41 = acons(stack[-1], stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-6];
    v41 = list3star(stack[-5], stack[-3], stack[-2], v41);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-6];
    stack[-1] = v41;
    v41 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v41 == nil) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v41 = stack[-4];
    fn = elt(env, 4); /* vevtdeg */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-6];
    fn = elt(env, 5); /* gsetsugar */
    v41 = (*qfn2(fn))(qenv(fn), stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v81;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
/* error exit handlers */
v81:
    popv(7);
    return nil;
}



/* Code for mkunarywedge */

static Lisp_Object CC_mkunarywedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v83, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkunarywedge");
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
    goto v120;

v120:
    v57 = stack[0];
    if (v57 == nil) goto v91;
    v57 = stack[0];
    v57 = qcar(v57);
    v57 = qcar(v57);
    v54 = ncons(v57);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v57 = stack[0];
    v57 = qcar(v57);
    v83 = qcdr(v57);
    v57 = stack[-1];
    v57 = acons(v54, v83, v57);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    stack[-1] = v57;
    v57 = stack[0];
    v57 = qcdr(v57);
    stack[0] = v57;
    goto v120;

v91:
    v57 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v57);
    }
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



setup_type const u36_setup[] =
{
    {"makecoeffpairs1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs1},
    {"gigcd:",                  too_few_2,      CC_gigcdT,     wrong_no_2},
    {"rlis",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_rlis},
    {"splitrec",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitrec},
    {"tchscheme",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_tchscheme},
    {"fieldp",                  CC_fieldp,      too_many_1,    wrong_no_1},
    {"xpartitk",                CC_xpartitk,    too_many_1,    wrong_no_1},
    {"deflate1",                too_few_2,      CC_deflate1,   wrong_no_2},
    {"endofstmtp",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_endofstmtp},
    {"lndepends",               too_few_2,      CC_lndepends,  wrong_no_2},
    {"requote1",                CC_requote1,    too_many_1,    wrong_no_1},
    {"al1_defined_vertex",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_al1_defined_vertex},
    {"simp-prop-form",          CC_simpKpropKform,too_many_1,  wrong_no_1},
    {"bfminus",                 CC_bfminus,     too_many_1,    wrong_no_1},
    {"ofsf_ir2atl",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_ir2atl},
    {"addinds",                 too_few_2,      CC_addinds,    wrong_no_2},
    {"impartf",                 CC_impartf,     too_many_1,    wrong_no_1},
    {"ofsf_sacrel",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sacrel},
    {"ps:quotient-erule",       too_few_2,      CC_psTquotientKerule,wrong_no_2},
    {"idsort",                  CC_idsort,      too_many_1,    wrong_no_1},
    {"vdpappendmon",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpappendmon},
    {"preproc1",                CC_preproc1,    too_many_1,    wrong_no_1},
    {"pnth*",                   too_few_2,      CC_pnthH,      wrong_no_2},
    {"listquotient",            too_few_2,      CC_listquotient,wrong_no_2},
    {"normmat",                 CC_normmat,     too_many_1,    wrong_no_1},
    {"prepcadr",                CC_prepcadr,    too_many_1,    wrong_no_1},
    {"*hfac",                   CC_Hhfac,       too_many_1,    wrong_no_1},
    {"general-modular-difference",too_few_2,    CC_generalKmodularKdifference,wrong_no_2},
    {"eval-yetunknowntypeexpr", too_few_2,      CC_evalKyetunknowntypeexpr,wrong_no_2},
    {"subdf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_subdf},
    {"ps:term-rthpow",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTtermKrthpow},
    {"vdpsimpcont",             CC_vdpsimpcont, too_many_1,    wrong_no_1},
    {"r2oreaction",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2oreaction},
    {"chksymmetries&sub1",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsub1},
    {"defined_vertex",          too_few_2,      CC_defined_vertex,wrong_no_2},
    {"red_extract",             CC_red_extract, too_many_1,    wrong_no_1},
    {"can_rep_cell",            too_few_2,      CC_can_rep_cell,wrong_no_2},
    {"ofsf_surep",              too_few_2,      CC_ofsf_surep, wrong_no_2},
    {"reprod",                  too_few_2,      CC_reprod,     wrong_no_2},
    {"transferrow1",            CC_transferrow1,too_many_1,    wrong_no_1},
    {"vdpfmon",                 too_few_2,      CC_vdpfmon,    wrong_no_2},
    {"mkunarywedge",            CC_mkunarywedge,too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u36", (two_args *)"21183 6415740 9414898", 0}
};

/* end of generated code */
