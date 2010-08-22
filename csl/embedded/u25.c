
/* $destdir/generated-c\u25.c Machine generated C code */

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


/* Code for evaluate!-in!-order!-mod!-p */

static Lisp_Object CC_evaluateKinKorderKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11, v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-in-order-mod-p");
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

v14:
    v10 = stack[-1];
    if (!consp(v10)) goto v15;
    v10 = stack[-1];
    v10 = qcar(v10);
    if (!consp(v10)) goto v15;
    v10 = stack[-1];
    v10 = qcar(v10);
    v10 = qcar(v10);
    v11 = qcar(v10);
    v10 = stack[0];
    v10 = qcar(v10);
    v10 = qcar(v10);
    if (equal(v11, v10)) goto v16;
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[0] = v10;
    goto v14;

v16:
    v10 = stack[-1];
    v10 = qcar(v10);
    v11 = qcdr(v10);
    v10 = stack[0];
    v10 = qcdr(v10);
    v13 = CC_evaluateKinKorderKmodKp(env, v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v10 = stack[-1];
    v10 = qcar(v10);
    v10 = qcar(v10);
    v12 = qcdr(v10);
    v10 = stack[-1];
    v11 = qcdr(v10);
    v10 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* horner!-rule!-in!-order!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 4, v13, v12, v11, v10);
    }

v15:
    v10 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v17:
    popv(3);
    return nil;
}



/* Code for ofsf_entry2at */

static Lisp_Object MS_CDECL CC_ofsf_entry2at(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v18, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26, v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at");
#endif
    if (stack >= stacklimit)
    {
        push3(v18,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v18);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v26 = v18;
    v27 = v1;
    v28 = v0;
/* end of prologue */
    v25 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v25 == nil) goto v29;
    v25 = v28;
    fn = elt(env, 2); /* ofsf_entry2at1 */
    v25 = (*qfnn(fn))(qenv(fn), 3, v25, v27, v26);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cl_identifyat */
        return (*qfn1(fn))(qenv(fn), v25);
    }

v29:
    v25 = v28;
    {
        popv(1);
        fn = elt(env, 2); /* ofsf_entry2at1 */
        return (*qfnn(fn))(qenv(fn), 3, v25, v27, v26);
    }
/* error exit handlers */
v30:
    popv(1);
    return nil;
}



/* Code for makecoeffpairshom */

static Lisp_Object MS_CDECL CC_makecoeffpairshom(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v18, Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102, v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairshom");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairshom");
#endif
    if (stack >= stacklimit)
    {
        push4(v31,v18,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v18,v31);
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
    stack[-11] = v31;
    stack[-12] = v18;
    stack[-13] = v1;
    stack[-14] = v0;
/* end of prologue */
    v101 = stack[-12];
    if (v101 == nil) goto v105;
    v101 = stack[-13];
    v101 = qcar(v101);
    stack[-15] = v101;
    goto v106;

v106:
    stack[0] = stack[-11];
    v101 = stack[-14];
    v102 = qcar(v101);
    v101 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    fn = elt(env, 4); /* tayexp!-times2 */
    v101 = (*qfn2(fn))(qenv(fn), stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    fn = elt(env, 5); /* tayexp!-minusp */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    if (v101 == nil) goto v7;
    v101 = qvalue(elt(env, 2)); /* nil */
    { popv(17); return onevalue(v101); }

v7:
    v101 = stack[-14];
    v104 = qcdr(v101);
    v101 = stack[-13];
    v103 = qcdr(v101);
    v101 = stack[-12];
    v102 = qcdr(v101);
    v101 = stack[-11];
    v101 = CC_makecoeffpairshom(env, 4, v104, v103, v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    stack[-7] = v101;
    v101 = stack[-7];
    if (v101 == nil) goto v17;
    v101 = stack[-7];
    v101 = qcar(v101);
    stack[-3] = v101;
    stack[-2] = stack[-15];
    v101 = stack[-3];
    stack[-1] = qcar(v101);
    v101 = stack[-13];
    stack[0] = qcar(v101);
    v101 = stack[-12];
    v102 = qcar(v101);
    v101 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v102 = (*qfn2(fn))(qenv(fn), stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = stack[-3];
    v101 = qcdr(v101);
    v101 = cons(v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = acons(stack[-2], stack[-1], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    stack[-5] = v101;
    stack[-6] = v101;
    goto v6;

v6:
    v101 = stack[-7];
    v101 = qcdr(v101);
    stack[-7] = v101;
    v101 = stack[-7];
    if (v101 == nil) goto v108;
    stack[-4] = stack[-5];
    v101 = stack[-7];
    v101 = qcar(v101);
    stack[-3] = v101;
    stack[-2] = stack[-15];
    v101 = stack[-3];
    stack[-1] = qcar(v101);
    v101 = stack[-13];
    stack[0] = qcar(v101);
    v101 = stack[-12];
    v102 = qcar(v101);
    v101 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v102 = (*qfn2(fn))(qenv(fn), stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = stack[-3];
    v101 = qcdr(v101);
    v101 = cons(v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = acons(stack[-2], stack[-1], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = Lrplacd(nil, stack[-4], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = stack[-5];
    v101 = qcdr(v101);
    stack[-5] = v101;
    goto v6;

v108:
    v101 = stack[-6];
    goto v109;

v109:
    stack[-10] = v101;
    v101 = stack[-10];
    fn = elt(env, 7); /* lastpair */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    stack[-9] = v101;
    v102 = stack[-15];
    v101 = stack[-11];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    stack[-15] = v101;
    v101 = stack[-9];
    if (!consp(v101)) goto v106;
    else goto v110;

v110:
    stack[0] = stack[-11];
    v101 = stack[-14];
    v102 = qcar(v101);
    v101 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    fn = elt(env, 4); /* tayexp!-times2 */
    v101 = (*qfn2(fn))(qenv(fn), stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    fn = elt(env, 5); /* tayexp!-minusp */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    if (!(v101 == nil)) { Lisp_Object res = stack[-10]; popv(17); return onevalue(res); }
    stack[-8] = stack[-9];
    v101 = stack[-14];
    v104 = qcdr(v101);
    v101 = stack[-13];
    v103 = qcdr(v101);
    v101 = stack[-12];
    v102 = qcdr(v101);
    v101 = stack[-11];
    v101 = CC_makecoeffpairshom(env, 4, v104, v103, v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    stack[-7] = v101;
    v101 = stack[-7];
    if (v101 == nil) goto v111;
    v101 = stack[-7];
    v101 = qcar(v101);
    stack[-3] = v101;
    stack[-2] = stack[-15];
    v101 = stack[-3];
    stack[-1] = qcar(v101);
    v101 = stack[-13];
    stack[0] = qcar(v101);
    v101 = stack[-12];
    v102 = qcar(v101);
    v101 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v102 = (*qfn2(fn))(qenv(fn), stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = stack[-3];
    v101 = qcdr(v101);
    v101 = cons(v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = acons(stack[-2], stack[-1], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    stack[-5] = v101;
    stack[-6] = v101;
    goto v112;

v112:
    v101 = stack[-7];
    v101 = qcdr(v101);
    stack[-7] = v101;
    v101 = stack[-7];
    if (v101 == nil) goto v113;
    stack[-4] = stack[-5];
    v101 = stack[-7];
    v101 = qcar(v101);
    stack[-3] = v101;
    stack[-2] = stack[-15];
    v101 = stack[-3];
    stack[-1] = qcar(v101);
    v101 = stack[-13];
    stack[0] = qcar(v101);
    v101 = stack[-12];
    v102 = qcar(v101);
    v101 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v102 = (*qfn2(fn))(qenv(fn), stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = stack[-3];
    v101 = qcdr(v101);
    v101 = cons(v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = acons(stack[-2], stack[-1], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = Lrplacd(nil, stack[-4], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = stack[-5];
    v101 = qcdr(v101);
    stack[-5] = v101;
    goto v112;

v113:
    v101 = stack[-6];
    goto v114;

v114:
    v101 = Lrplacd(nil, stack[-8], v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    v101 = stack[-9];
    fn = elt(env, 7); /* lastpair */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    stack[-9] = v101;
    v102 = stack[-15];
    v101 = stack[-11];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-16];
    stack[-15] = v101;
    goto v110;

v111:
    v101 = qvalue(elt(env, 2)); /* nil */
    goto v114;

v17:
    v101 = qvalue(elt(env, 2)); /* nil */
    goto v109;

v105:
    v101 = elt(env, 1); /* ((nil)) */
    { popv(17); return onevalue(v101); }
/* error exit handlers */
v107:
    popv(17);
    return nil;
}



/* Code for sets */

static Lisp_Object CC_sets(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v25;
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
    v21 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = elt(env, 2); /* "<" */
    v21 = Lprinc(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = stack[0];
    v21 = Lprinc(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = elt(env, 3); /* "/>" */
    v21 = Lprinc(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v25 = qvalue(elt(env, 4)); /* indent */
    v21 = (Lisp_Object)49; /* 3 */
    v21 = plus2(v25, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    qvalue(elt(env, 4)) = v21; /* indent */
    v21 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v25 = qvalue(elt(env, 4)); /* indent */
    v21 = (Lisp_Object)49; /* 3 */
    v21 = difference2(v25, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    qvalue(elt(env, 4)) = v21; /* indent */
    v21 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v21 = nil;
    { popv(3); return onevalue(v21); }
/* error exit handlers */
v28:
    popv(3);
    return nil;
}



/* Code for look_for_substitute */

static Lisp_Object MS_CDECL CC_look_for_substitute(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v18, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v123, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_substitute");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_substitute");
#endif
    if (stack >= stacklimit)
    {
        push3(v18,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v18);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v18;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v125:
    v122 = stack[0];
    if (!consp(v122)) goto v126;
    v124 = stack[-2];
    v123 = stack[-1];
    v122 = stack[0];
    fn = elt(env, 2); /* look_for_rational */
    v122 = (*qfnn(fn))(qenv(fn), 3, v124, v123, v122);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v123 = v122;
    if (!(v122 == nil)) { popv(4); return onevalue(v123); }
    v124 = stack[-2];
    v123 = stack[-1];
    v122 = stack[0];
    fn = elt(env, 3); /* look_for_quad */
    v122 = (*qfnn(fn))(qenv(fn), 3, v124, v123, v122);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v123 = v122;
    if (!(v122 == nil)) { popv(4); return onevalue(v123); }
    v124 = stack[-2];
    v123 = stack[-1];
    v122 = stack[0];
    v122 = qcar(v122);
    v122 = CC_look_for_substitute(env, 3, v124, v123, v122);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v123 = v122;
    if (!(v122 == nil)) { popv(4); return onevalue(v123); }
    v124 = stack[-2];
    v123 = stack[-1];
    v122 = stack[0];
    v122 = qcdr(v122);
    stack[-2] = v124;
    stack[-1] = v123;
    stack[0] = v122;
    goto v125;

v126:
    v122 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v122); }
/* error exit handlers */
v95:
    popv(4);
    return nil;
}



/* Code for add_item */

static Lisp_Object CC_add_item(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_item");
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

v14:
    v100 = stack[0];
    v100 = qcdr(v100);
    if (v100 == nil) goto v34;
    v100 = stack[0];
    v100 = qcar(v100);
    v129 = qcar(v100);
    v100 = stack[-1];
    v100 = qcar(v100);
    fn = elt(env, 3); /* monordp */
    v100 = (*qfn2(fn))(qenv(fn), v129, v100);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    if (v100 == nil) goto v130;
    v100 = stack[0];
    v100 = qcdr(v100);
    v100 = qcar(v100);
    stack[0] = v100;
    goto v14;

v130:
    v100 = stack[0];
    v100 = qcdr(v100);
    v100 = qcdr(v100);
    stack[0] = v100;
    goto v14;

v34:
    v129 = stack[0];
    v100 = stack[-1];
    fn = elt(env, 4); /* setcar */
    v100 = (*qfn2(fn))(qenv(fn), v129, v100);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[-1] = elt(env, 1); /* !*xset!* */
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v100 = elt(env, 1); /* !*xset!* */
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v100 = acons(stack[-1], stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    fn = elt(env, 5); /* setcdr */
    v100 = (*qfn2(fn))(qenv(fn), stack[-2], v100);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v100 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v100); }
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for getphystypeall */

static Lisp_Object CC_getphystypeall(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v133;
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
    v133 = (Lisp_Object)1; /* 0 */
    v16 = stack[0];
    fn = elt(env, 3); /* deleteall */
    v16 = (*qfn2(fn))(qenv(fn), v133, v16);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    fn = elt(env, 4); /* collectphystype */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    v133 = v16;
    if (v16 == nil) goto v105;
    v16 = v133;
    v16 = qcdr(v16);
    if (v16 == nil) goto v30;
    stack[-1] = elt(env, 0); /* getphystypeall */
    v133 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v16 = stack[0];
    v16 = list2(v133, v16);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v16 = (*qfn2(fn))(qenv(fn), stack[-1], v16);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v16 = nil;
    { popv(3); return onevalue(v16); }

v30:
    v16 = v133;
    v16 = qcar(v16);
    { popv(3); return onevalue(v16); }

v105:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v16); }
/* error exit handlers */
v88:
    popv(3);
    return nil;
}



/* Code for edge_new_parents */

static Lisp_Object CC_edge_new_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v25, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edge_new_parents");
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
    v26 = v0;
/* end of prologue */
    v21 = v26;
    v25 = qcar(v21);
    v21 = qvalue(elt(env, 1)); /* old_edge_list */
    v21 = Lassoc(nil, v25, v21);
    if (v21 == nil) goto v131;
    v21 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v21); }

v131:
    v21 = v26;
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v25 = v21;
    v25 = qcar(v25);
    v21 = qcdr(v21);
    v21 = list2(v25, v21);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* edge_new_parent */
        return (*qfn1(fn))(qenv(fn), v21);
    }
/* error exit handlers */
v27:
    popv(1);
    return nil;
}



/* Code for innprodpex */

static Lisp_Object CC_innprodpex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodpex");
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

v125:
    v124 = stack[-1];
    if (v124 == nil) goto v14;
    v137 = stack[-2];
    v124 = stack[-1];
    v124 = qcar(v124);
    v124 = qcar(v124);
    fn = elt(env, 2); /* innprodp2 */
    v124 = (*qfn2(fn))(qenv(fn), v137, v124);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v137 = v124;
    v124 = v137;
    if (v124 == nil) goto v11;
    v124 = v137;
    stack[-3] = qcdr(v124);
    v124 = v137;
    v124 = qcar(v124);
    if (v124 == nil) goto v74;
    v124 = stack[-1];
    v124 = qcar(v124);
    v124 = qcdr(v124);
    fn = elt(env, 3); /* negf */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[0] = v124;
    goto v139;

v139:
    v137 = stack[-2];
    v124 = stack[-1];
    v124 = qcdr(v124);
    v124 = CC_innprodpex(env, v137, v124);
    nil = C_nil;
    if (exception_pending()) goto v138;
    {
        Lisp_Object v140 = stack[-3];
        Lisp_Object v141 = stack[0];
        popv(5);
        return acons(v140, v141, v124);
    }

v74:
    v124 = stack[-1];
    v124 = qcar(v124);
    v124 = qcdr(v124);
    stack[0] = v124;
    goto v139;

v11:
    v137 = stack[-2];
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-2] = v137;
    stack[-1] = v124;
    goto v125;

v14:
    v124 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v124); }
/* error exit handlers */
v138:
    popv(5);
    return nil;
}



/* Code for sqprint */

static Lisp_Object CC_sqprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v151, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqprint");
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
    stack[0] = qvalue(elt(env, 1)); /* !*prin!# */
    qvalue(elt(env, 1)) = nil; /* !*prin!# */
    v76 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v76; /* !*prin!# */
    v76 = qvalue(elt(env, 3)); /* orig!* */
    stack[-2] = v76;
    v76 = qvalue(elt(env, 4)); /* !*nat */
    if (v76 == nil) goto v153;
    v151 = qvalue(elt(env, 5)); /* posn!* */
    v76 = (Lisp_Object)321; /* 20 */
    v76 = (Lisp_Object)lessp2(v151, v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    v76 = v76 ? lisp_true : nil;
    env = stack[-3];
    if (v76 == nil) goto v153;
    v76 = qvalue(elt(env, 5)); /* posn!* */
    qvalue(elt(env, 3)) = v76; /* orig!* */
    goto v153;

v153:
    v76 = qvalue(elt(env, 6)); /* !*pri */
    if (!(v76 == nil)) goto v8;
    v76 = qvalue(elt(env, 7)); /* wtl!* */
    if (!(v76 == nil)) goto v8;
    v76 = stack[-1];
    v151 = qcdr(v76);
    v76 = (Lisp_Object)17; /* 1 */
    if (v151 == v76) goto v155;
    v76 = stack[-1];
    v76 = qcar(v76);
    if (!consp(v76)) goto v127;
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = qcar(v76);
    if (!consp(v76)) goto v127;
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = qcdr(v76);
    goto v13;

v13:
    v151 = stack[-1];
    v152 = qcar(v151);
    v151 = v76;
    v76 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 10); /* xprinf */
    v76 = (*qfnn(fn))(qenv(fn), 3, v152, v151, v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    v76 = elt(env, 9); /* " / " */
    fn = elt(env, 11); /* prin2!* */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    v76 = stack[-1];
    v76 = qcdr(v76);
    if (!consp(v76)) goto v156;
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcar(v76);
    if (!consp(v76)) goto v156;
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    if (!(v76 == nil)) goto v157;
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v151 = qcdr(v76);
    v76 = (Lisp_Object)17; /* 1 */
    v76 = Lneq(nil, v151, v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    goto v157;

v157:
    v151 = stack[-1];
    v152 = qcdr(v151);
    v151 = v76;
    v76 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 10); /* xprinf */
    v76 = (*qfnn(fn))(qenv(fn), 3, v152, v151, v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    goto v128;

v128:
    v76 = stack[-2];
    qvalue(elt(env, 3)) = v76; /* orig!* */
    qvalue(elt(env, 1)) = stack[0]; /* !*prin!# */
    { popv(4); return onevalue(v76); }

v156:
    v76 = qvalue(elt(env, 8)); /* nil */
    goto v157;

v127:
    v76 = qvalue(elt(env, 8)); /* nil */
    goto v13;

v155:
    v76 = stack[-1];
    v76 = qcar(v76);
    fn = elt(env, 12); /* xprinf2 */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    goto v128;

v8:
    v76 = stack[-1];
    fn = elt(env, 13); /* sqhorner!* */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    fn = elt(env, 14); /* prepsq!* */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    fn = elt(env, 15); /* prepreform */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    fn = elt(env, 16); /* maprin */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    goto v128;
/* error exit handlers */
v154:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* !*prin!# */
    popv(4);
    return nil;
}



/* Code for bas_make */

static Lisp_Object CC_bas_make(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_make");
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
    stack[-2] = v1;
    v128 = v0;
/* end of prologue */
    stack[-3] = v128;
    stack[-1] = stack[-2];
    v128 = stack[-2];
    stack[0] = Llength(nil, v128);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    v128 = stack[-2];
    fn = elt(env, 2); /* dp_ecart */
    v8 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    v128 = qvalue(elt(env, 1)); /* nil */
    v128 = list2(v8, v128);
    nil = C_nil;
    if (exception_pending()) goto v20;
    {
        Lisp_Object v21 = stack[-3];
        Lisp_Object v25 = stack[-1];
        Lisp_Object v26 = stack[0];
        popv(5);
        return list3star(v21, v25, v26, v128);
    }
/* error exit handlers */
v20:
    popv(5);
    return nil;
}



/* Code for macrochk */

static Lisp_Object CC_macrochk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v122, v123, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for macrochk");
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
    v17 = stack[-1];
    if (!consp(v17)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v17 = stack[-1];
    v17 = qcar(v17);
    fn = elt(env, 4); /* expdrmacro */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    v122 = v17;
    if (v17 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v123 = stack[0];
    v17 = elt(env, 1); /* symbolic */
    if (v123 == v17) goto v116;
    v17 = stack[-1];
    v17 = qcar(v17);
    if (!(symbolp(v17))) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v17 = stack[-1];
    v123 = qcar(v17);
    v17 = elt(env, 2); /* opfn */
    v17 = Lflagp(nil, v123, v17);
    env = stack[-2];
    if (v17 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else goto v116;

v116:
    v17 = v122;
    v123 = qcar(v17);
    v17 = elt(env, 3); /* macrofn */
    v124 = get(v123, v17);
    v17 = v122;
    v123 = qcdr(v17);
    v17 = stack[-1];
    v122 = qcdr(v17);
    v17 = stack[-1];
    v17 = qcar(v17);
        popv(3);
        return Lapply3(nil, 4, v124, v123, v122, v17);
/* error exit handlers */
v148:
    popv(3);
    return nil;
}



/* Code for rl_identifyonoff */

static Lisp_Object CC_rl_identifyonoff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_identifyonoff");
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
    v160 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_identifyonoff!* */
    v160 = ncons(v160);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    {
        Lisp_Object v69 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v69, v160);
    }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for vp2 */

static Lisp_Object CC_vp2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp2");
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
    v128 = nil;
    goto v14;

v14:
    v119 = stack[0];
    if (v119 == nil) goto v15;
    v119 = (Lisp_Object)1; /* 0 */
    v119 = cons(v119, v128);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v128 = v119;
    v119 = stack[0];
    v119 = qcdr(v119);
    stack[0] = v119;
    goto v14;

v15:
    v119 = v128;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v119);
    }
/* error exit handlers */
v106:
    popv(2);
    return nil;
}



/* Code for ev_revgradlexcomp */

static Lisp_Object CC_ev_revgradlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_revgradlexcomp");
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

v125:
    v149 = stack[-2];
    if (v149 == nil) goto v126;
    v149 = stack[-2];
    v148 = qcar(v149);
    v149 = stack[-1];
    v149 = qcar(v149);
    v149 = Leqn(nil, v148, v149);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    if (v149 == nil) goto v69;
    v149 = stack[-2];
    v148 = qcdr(v149);
    v149 = stack[-1];
    v149 = qcdr(v149);
    stack[-2] = v148;
    stack[-1] = v149;
    goto v125;

v69:
    v149 = stack[-2];
    fn = elt(env, 1); /* ev_tdeg */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    stack[-3] = v149;
    v149 = stack[-1];
    fn = elt(env, 1); /* ev_tdeg */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    stack[0] = v149;
    v148 = stack[-3];
    v149 = stack[0];
    v149 = Leqn(nil, v148, v149);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    if (v149 == nil) goto v12;
    v148 = stack[-2];
    v149 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* ev_invlexcomp */
        return (*qfn2(fn))(qenv(fn), v148, v149);
    }

v12:
    v148 = stack[-3];
    v149 = stack[0];
    if (((int32_t)(v148)) > ((int32_t)(v149))) goto v10;
    v149 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v149); }

v10:
    v149 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v149); }

v126:
    v149 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v149); }
/* error exit handlers */
v141:
    popv(5);
    return nil;
}



/* Code for listrd */

static Lisp_Object MS_CDECL CC_listrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v165, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "listrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listrd");
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
    v165 = qvalue(elt(env, 1)); /* atts */
    v164 = elt(env, 2); /* (o r d e r) */
    fn = elt(env, 11); /* search_att */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    stack[-1] = v164;
    v164 = elt(env, 3); /* (t y p e != l i s t !$) */
    qvalue(elt(env, 1)) = v164; /* atts */
    stack[0] = elt(env, 4); /* list */
    fn = elt(env, 12); /* stats_getargs */
    v164 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    v164 = cons(stack[0], v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    v165 = v164;
    stack[0] = v165;
    v146 = stack[-1];
    v165 = elt(env, 5); /* (l e x i c o g r a p h i c) */
    if (!(equal(v146, v165))) goto v7;
    v165 = elt(env, 6); /* sortlist */
    v146 = v164;
    v164 = elt(env, 7); /* lexog */
    v164 = list3(v165, v146, v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    goto v7;

v7:
    v146 = stack[-1];
    v165 = elt(env, 8); /* (n u m e r i c) */
    if (equal(v146, v165)) goto v136;
    v146 = elt(env, 6); /* sortlist */
    v165 = v164;
    v164 = elt(env, 10); /* pred */
    v164 = list3(v146, v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    goto v109;

v109:
    v165 = v164;
    if (!(v165 == nil)) { popv(3); return onevalue(v164); }
    v164 = stack[0];
    { popv(3); return onevalue(v164); }

v136:
    v146 = elt(env, 6); /* sortlist */
    v165 = v164;
    v164 = elt(env, 9); /* numer */
    v164 = list3(v146, v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    goto v109;
/* error exit handlers */
v166:
    popv(3);
    return nil;
}



/* Code for domainvalchk */

static Lisp_Object CC_domainvalchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v122, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domainvalchk");
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
    v122 = qvalue(elt(env, 1)); /* dmode!* */
    v17 = elt(env, 0); /* domainvalchk */
    v17 = get(v122, v17);
    env = stack[-3];
    stack[-2] = v17;
    if (v17 == nil) goto v15;
    v123 = stack[-2];
    v122 = stack[-1];
    v17 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v123, v122, v17);

v15:
    v17 = stack[0];
    v17 = Lreverse(nil, v17);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    stack[0] = v17;
    goto v167;

v167:
    v17 = stack[0];
    if (v17 == nil) goto v30;
    v17 = stack[0];
    v17 = qcar(v17);
    v122 = qcdr(v17);
    v17 = (Lisp_Object)17; /* 1 */
    if (v122 == v17) goto v5;
    v17 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v17); }

v5:
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 3); /* mk!*sq */
    v122 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    v17 = stack[-2];
    v17 = cons(v122, v17);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    stack[-2] = v17;
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v167;

v30:
    v122 = stack[-1];
    v17 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* valuechk */
        return (*qfn2(fn))(qenv(fn), v122, v17);
    }
/* error exit handlers */
v148:
    popv(4);
    return nil;
}



/* Code for diffp */

static Lisp_Object CC_diffp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v324, v325, v326, v327;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp");
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
    stack[-1] = nil;
    v324 = stack[-5];
    v324 = qcdr(v324);
    stack[-6] = v324;
    v324 = stack[-5];
    v324 = qcar(v324);
    stack[-5] = v324;
    v325 = stack[-6];
    v324 = (Lisp_Object)17; /* 1 */
    v324 = (Lisp_Object)greaterp2(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v324 = v324 ? lisp_true : nil;
    env = stack[-7];
    if (v324 == nil) goto v329;
    v324 = stack[-5];
    fn = elt(env, 20); /* noncomp */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    if (v324 == nil) goto v329;
    v325 = stack[-5];
    v324 = stack[-4];
    v324 = list2(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 21); /* simpdf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[0] = stack[-5];
    v324 = stack[-6];
    v324 = sub1(v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = list2(stack[0], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 22); /* simpexpt */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 23); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v325 = stack[-5];
    v324 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 24); /* to */
    v325 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = (Lisp_Object)17; /* 1 */
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v325 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-2] = stack[-5];
    v324 = stack[-6];
    v324 = sub1(v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v325 = cons(stack[-2], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-4];
    v324 = CC_diffp(env, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 23); /* multsq */
    v324 = (*qfn2(fn))(qenv(fn), stack[0], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    {
        Lisp_Object v330 = stack[-1];
        popv(8);
        fn = elt(env, 25); /* addsq */
        return (*qfn2(fn))(qenv(fn), v330, v324);
    }

v329:
    v325 = stack[-5];
    v324 = stack[-4];
    if (!(v325 == v324)) goto v331;
    v325 = (Lisp_Object)17; /* 1 */
    v324 = (Lisp_Object)17; /* 1 */
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    if (!(v324 == nil)) goto v101;

v331:
    v324 = stack[-5];
    if (!consp(v324)) goto v332;
    v324 = stack[-5];
    v324 = qcar(v324);
    if (!consp(v324)) goto v333;
    v325 = stack[-5];
    v324 = stack[-4];
    fn = elt(env, 26); /* difff */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    if (!(v324 == nil)) goto v101;

v333:
    v324 = stack[-5];
    v325 = qcar(v324);
    v324 = elt(env, 1); /* !*sq */
    if (!(v325 == v324)) goto v334;
    v324 = stack[-5];
    v324 = qcdr(v324);
    v325 = qcar(v324);
    v324 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    if (!(v324 == nil)) goto v101;

v334:
    v324 = stack[-5];
    v325 = qcar(v324);
    v324 = elt(env, 2); /* dfform */
    v324 = get(v325, v324);
    env = stack[-7];
    stack[-3] = v324;
    if (v324 == nil) goto v335;
    v327 = stack[-3];
    v326 = stack[-5];
    v325 = stack[-4];
    v324 = stack[-6];
        popv(8);
        return Lapply3(nil, 4, v327, v326, v325, v324);

v335:
    v324 = stack[-5];
    stack[0] = qcar(v324);
    v324 = stack[-5];
    fn = elt(env, 28); /* dfn_prop */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = get(stack[0], v324);
    env = stack[-7];
    stack[-3] = v324;
    if (v324 == nil) goto v50;
    v324 = stack[-3];
    stack[-2] = v324;
    v324 = stack[-5];
    v324 = qcdr(v324);
    stack[0] = v324;
    goto v336;

v336:
    v324 = stack[0];
    v324 = qcar(v324);
    fn = elt(env, 29); /* simp */
    v325 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v325 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-1];
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    v324 = stack[-1];
    v324 = qcar(v324);
    v324 = qcar(v324);
    if (v324 == nil) goto v55;
    v324 = stack[-2];
    v324 = qcar(v324);
    if (!(v324 == nil)) goto v55;

v337:
    v324 = stack[-5];
    v325 = qcar(v324);
    v324 = elt(env, 14); /* df */
    if (v325 == v324) goto v338;
    v326 = elt(env, 14); /* df */
    v325 = stack[-5];
    v324 = stack[-4];
    v324 = list3(v326, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v132;

v132:
    v324 = stack[-1];
    fn = elt(env, 30); /* opmtch */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-3] = v324;
    if (v324 == nil) goto v339;
    v324 = stack[-3];
    fn = elt(env, 29); /* simp */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v101;

v101:
    v325 = stack[-5];
    v324 = qvalue(elt(env, 5)); /* wtl!* */
    v324 = Latsoc(nil, v325, v324);
    stack[-3] = v324;
    if (v324 == nil) goto v340;
    stack[0] = elt(env, 6); /* k!* */
    v324 = stack[-3];
    v324 = qcdr(v324);
    v324 = negate(v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 24); /* to */
    v325 = (*qfn2(fn))(qenv(fn), stack[0], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = (Lisp_Object)17; /* 1 */
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v325 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = (Lisp_Object)17; /* 1 */
    v325 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-1];
    fn = elt(env, 23); /* multsq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v340;

v340:
    v324 = stack[-6];
    v324 = sub1(v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[0] = v324;
    v325 = stack[-6];
    v324 = (Lisp_Object)17; /* 1 */
    if (v325 == v324) goto v341;
    v325 = qvalue(elt(env, 7)); /* dmode!* */
    v324 = elt(env, 8); /* convert */
    v324 = Lflagp(nil, v325, v324);
    env = stack[-7];
    if (v324 == nil) goto v342;
    v325 = qvalue(elt(env, 7)); /* dmode!* */
    v324 = elt(env, 9); /* i2d */
    v325 = get(v325, v324);
    env = stack[-7];
    v324 = stack[-6];
    v324 = Lapply1(nil, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 31); /* int!-equiv!-chk */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-6] = v324;
    if (!(v324 == nil)) goto v342;
    v325 = qvalue(elt(env, 3)); /* nil */
    v324 = (Lisp_Object)17; /* 1 */
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    goto v343;

v343:
    {
        popv(8);
        fn = elt(env, 32); /* rationalizesq */
        return (*qfn1(fn))(qenv(fn), v324);
    }

v342:
    v325 = stack[-5];
    v324 = stack[0];
    fn = elt(env, 24); /* to */
    v325 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-6];
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v325 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = (Lisp_Object)17; /* 1 */
    v325 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-1];
    fn = elt(env, 23); /* multsq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    goto v343;

v341:
    v324 = stack[-1];
    goto v343;

v339:
    v325 = stack[-5];
    v324 = stack[-4];
    fn = elt(env, 33); /* depends */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    if (!(v324 == nil)) goto v344;
    v324 = qvalue(elt(env, 11)); /* !*depend */
    if (!(v324 == nil)) goto v344;
    v325 = qvalue(elt(env, 3)); /* nil */
    v324 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v325, v324);

v344:
    v325 = stack[-1];
    v324 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 34); /* mksq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v101;

v338:
    v324 = stack[-5];
    v324 = qcdr(v324);
    v325 = qcar(v324);
    v324 = stack[-4];
    if (!(v325 == v324)) goto v345;
    v324 = qvalue(elt(env, 15)); /* !*commutedf */
    if (v324 == nil) goto v346;
    v324 = qvalue(elt(env, 11)); /* !*depend */
    if (!(v324 == nil)) goto v346;
    v325 = qvalue(elt(env, 3)); /* nil */
    v324 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v325, v324);

v346:
    v324 = qvalue(elt(env, 16)); /* !*simpnoncomdf */
    if (v324 == nil) goto v347;
    v325 = stack[-4];
    v324 = qvalue(elt(env, 13)); /* depl!* */
    v324 = Latsoc(nil, v325, v324);
    stack[-1] = v324;
    if (v324 == nil) goto v347;
    v324 = stack[-1];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    if (!(v324 == nil)) goto v347;
    v324 = stack[-5];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = qcar(v324);
    stack[-3] = v324;
    v326 = elt(env, 14); /* df */
    v325 = stack[-5];
    v324 = stack[-3];
    v324 = list3(v326, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v326 = elt(env, 14); /* df */
    v325 = stack[-4];
    v324 = stack[-3];
    v324 = list3(v326, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 35); /* quotsq */
    v324 = (*qfn2(fn))(qenv(fn), stack[0], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v101;

v347:
    v324 = stack[-5];
    v324 = qcdr(v324);
    v325 = qcar(v324);
    v324 = elt(env, 17); /* int */
    if (!consp(v325)) goto v345;
    v325 = qcar(v325);
    if (!(v325 == v324)) goto v345;
    v324 = stack[-5];
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v325 = qcar(v324);
    v324 = stack[-4];
    if (v325 == v324) goto v348;
    v324 = qvalue(elt(env, 18)); /* !*allowdfint */
    if (v324 == nil) goto v345;
    v324 = stack[-5];
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v324 = qcdr(v324);
    v324 = qcar(v324);
    fn = elt(env, 36); /* simp!* */
    v325 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    fn = elt(env, 37); /* not_df_p */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    if (v324 == nil) goto v345;
    stack[-2] = elt(env, 14); /* df */
    stack[0] = elt(env, 17); /* int */
    v324 = stack[-1];
    fn = elt(env, 38); /* mk!*sq */
    v325 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-5];
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v324 = list3(stack[0], v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 39); /* reval */
    v325 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-5];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = list2star(stack[-2], v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v132;

v345:
    v324 = stack[-5];
    v324 = qcdr(v324);
    stack[0] = qcar(v324);
    v325 = stack[-5];
    v324 = stack[-4];
    fn = elt(env, 40); /* merge!-ind!-vars */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v326 = cons(stack[0], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v326;
    v325 = elt(env, 14); /* df */
    v324 = elt(env, 19); /* kvalue */
    v324 = get(v325, v324);
    env = stack[-7];
    fn = elt(env, 41); /* find_sub_df */
    v324 = (*qfn2(fn))(qenv(fn), v326, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-3] = v324;
    if (v324 == nil) goto v349;
    v324 = stack[-3];
    v324 = qcar(v324);
    fn = elt(env, 29); /* simp */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    v324 = stack[-3];
    v324 = qcdr(v324);
    stack[-3] = v324;
    goto v350;

v350:
    v324 = stack[-3];
    if (v324 == nil) goto v101;
    v324 = stack[-3];
    v324 = qcar(v324);
    stack[-2] = v324;
    v324 = (Lisp_Object)17; /* 1 */
    stack[0] = v324;
    goto v351;

v351:
    v324 = stack[-2];
    v325 = qcdr(v324);
    v324 = stack[0];
    v324 = difference2(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = Lminusp(nil, v324);
    env = stack[-7];
    if (v324 == nil) goto v352;
    v324 = stack[-3];
    v324 = qcdr(v324);
    stack[-3] = v324;
    goto v350;

v352:
    v325 = stack[-1];
    v324 = stack[-2];
    v324 = qcar(v324);
    fn = elt(env, 27); /* diffsq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    v324 = stack[0];
    v324 = add1(v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[0] = v324;
    goto v351;

v349:
    v325 = elt(env, 14); /* df */
    v324 = stack[-1];
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v132;

v348:
    v326 = elt(env, 14); /* df */
    v324 = stack[-5];
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v324 = qcdr(v324);
    v325 = qcar(v324);
    v324 = stack[-5];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = list2star(v326, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v132;

v55:
    v324 = stack[-2];
    v324 = qcdr(v324);
    stack[-2] = v324;
    v324 = stack[0];
    v324 = qcdr(v324);
    stack[0] = v324;
    v324 = stack[0];
    if (v324 == nil) goto v60;
    v324 = stack[-2];
    if (!(v324 == nil)) goto v336;

v60:
    v324 = stack[0];
    if (!(v324 == nil)) goto v337;
    v324 = stack[-2];
    if (!(v324 == nil)) goto v337;
    v324 = stack[-1];
    v324 = Lreverse(nil, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-2] = v324;
    v324 = stack[-5];
    v324 = qcdr(v324);
    stack[0] = v324;
    v325 = qvalue(elt(env, 3)); /* nil */
    v324 = (Lisp_Object)17; /* 1 */
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v135;

v135:
    v324 = stack[-2];
    v324 = qcar(v324);
    v324 = qcar(v324);
    if (v324 == nil) goto v353;
    v324 = stack[-2];
    stack[-4] = qcar(v324);
    v324 = stack[-3];
    v324 = qcar(v324);
    v325 = qcar(v324);
    v324 = stack[0];
    fn = elt(env, 42); /* pair */
    v325 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-3];
    v324 = qcar(v324);
    v324 = qcdr(v324);
    v324 = Lsubla(nil, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 23); /* multsq */
    v325 = (*qfn2(fn))(qenv(fn), stack[-4], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-1];
    fn = elt(env, 25); /* addsq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    goto v353;

v353:
    v324 = stack[-3];
    v324 = qcdr(v324);
    stack[-3] = v324;
    v324 = stack[-2];
    v324 = qcdr(v324);
    stack[-2] = v324;
    v324 = stack[-2];
    if (v324 == nil) goto v101;
    else goto v135;

v50:
    v324 = stack[-5];
    v325 = qcar(v324);
    v324 = elt(env, 4); /* plus */
    if (!(v325 == v324)) goto v337;
    v324 = stack[-5];
    fn = elt(env, 29); /* simp */
    v325 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v324 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    if (v324 == nil) goto v337;
    else goto v101;

v332:
    v325 = stack[-5];
    v324 = stack[-4];
    fn = elt(env, 33); /* depends */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    if (!(v324 == nil)) goto v354;
    v325 = stack[-5];
    v324 = qvalue(elt(env, 10)); /* powlis!* */
    v324 = Latsoc(nil, v325, v324);
    stack[-3] = v324;
    if (v324 == nil) goto v355;
    v324 = stack[-3];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v325 = qcar(v324);
    v324 = stack[-4];
    fn = elt(env, 33); /* depends */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    if (!(v324 == nil)) goto v354;

v355:
    v324 = qvalue(elt(env, 11)); /* !*depend */
    if (!(v324 == nil)) goto v354;
    v325 = qvalue(elt(env, 3)); /* nil */
    v324 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v325, v324);

v354:
    v324 = qvalue(elt(env, 12)); /* !*expanddf */
    if (v324 == nil) goto v356;
    v326 = stack[-4];
    v325 = stack[-5];
    v324 = qvalue(elt(env, 13)); /* depl!* */
    v324 = Latsoc(nil, v325, v324);
    v324 = qcdr(v324);
    stack[-3] = v324;
    v324 = Lmemq(nil, v326, v324);
    if (!(v324 == nil)) goto v356;
    v325 = qvalue(elt(env, 3)); /* nil */
    v324 = (Lisp_Object)17; /* 1 */
    v324 = cons(v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    v324 = stack[-3];
    stack[-3] = v324;
    goto v357;

v357:
    v324 = stack[-3];
    if (v324 == nil) goto v101;
    v324 = stack[-3];
    v324 = qcar(v324);
    stack[-2] = v324;
    v326 = elt(env, 14); /* df */
    v325 = stack[-5];
    v324 = stack[-2];
    v324 = list3(v326, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    v326 = elt(env, 14); /* df */
    v325 = stack[-2];
    v324 = stack[-4];
    v324 = list3(v326, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 23); /* multsq */
    v324 = (*qfn2(fn))(qenv(fn), stack[0], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    fn = elt(env, 25); /* addsq */
    v324 = (*qfn2(fn))(qenv(fn), stack[-1], v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    v324 = stack[-3];
    v324 = qcdr(v324);
    stack[-3] = v324;
    goto v357;

v356:
    v326 = elt(env, 14); /* df */
    v325 = stack[-5];
    v324 = stack[-4];
    v324 = list3(v326, v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-1] = v324;
    v324 = stack[-1];
    fn = elt(env, 30); /* opmtch */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    stack[-3] = v324;
    if (v324 == nil) goto v358;
    v324 = stack[-3];
    fn = elt(env, 29); /* simp */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    goto v359;

v359:
    stack[-1] = v324;
    goto v101;

v358:
    v325 = stack[-1];
    v324 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 34); /* mksq */
    v324 = (*qfn2(fn))(qenv(fn), v325, v324);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-7];
    goto v359;
/* error exit handlers */
v328:
    popv(8);
    return nil;
}



/* Code for greatertype */

static Lisp_Object CC_greatertype(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v365, v366, v367;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greatertype");
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
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v365 = qvalue(elt(env, 1)); /* optlang!* */
    if (v365 == nil) goto v29;
    v365 = qvalue(elt(env, 1)); /* optlang!* */
    v366 = v365;
    goto v37;

v37:
    v365 = elt(env, 3); /* conversion */
    v365 = get(v366, v365);
    env = stack[-8];
    fn = elt(env, 6); /* eval */
    v365 = (*qfn1(fn))(qenv(fn), v365);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-7] = v365;
    v365 = stack[-7];
    v366 = qcar(v365);
    v365 = stack[-5];
    if (equal(v366, v365)) goto v9;
    v365 = stack[-7];
    v366 = qcar(v365);
    v365 = stack[-6];
    if (!(equal(v366, v365))) goto v130;
    v365 = qvalue(elt(env, 5)); /* nil */
    stack[-1] = v365;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v130:
    v365 = stack[-7];
    v365 = qcdr(v365);
    stack[-7] = v365;
    if (v365 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v365 = stack[-4];
    if (!(v365 == nil)) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v365 = stack[-7];
    v365 = qcar(v365);
    v367 = v365;
    goto v123;

v123:
    v365 = v367;
    if (v365 == nil) goto v122;
    v365 = stack[-2];
    if (!(v365 == nil)) goto v122;
    v365 = v367;
    v366 = qcar(v365);
    v365 = stack[-6];
    if (!(equal(v366, v365))) goto v319;
    v365 = qvalue(elt(env, 4)); /* t */
    stack[-3] = v365;
    goto v319;

v319:
    v365 = v367;
    v366 = qcar(v365);
    v365 = stack[-5];
    if (equal(v366, v365)) goto v166;
    v365 = v367;
    v365 = qcdr(v365);
    v367 = v365;
    goto v123;

v166:
    v365 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v365;
    goto v123;

v122:
    v365 = stack[-2];
    if (v365 == nil) goto v94;
    v365 = v367;
    v365 = qcdr(v365);
    v367 = v365;
    goto v143;

v143:
    v365 = v367;
    if (v365 == nil) goto v94;
    v365 = stack[-1];
    if (!(v365 == nil)) goto v94;
    v365 = v367;
    v366 = qcar(v365);
    v365 = stack[-6];
    if (equal(v366, v365)) goto v312;
    v365 = v367;
    v365 = qcdr(v365);
    v367 = v365;
    goto v143;

v312:
    v365 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v365;
    stack[-3] = v365;
    goto v143;

v94:
    v365 = stack[-3];
    if (v365 == nil) goto v368;
    v365 = stack[-2];
    if (!(v365 == nil)) goto v368;

v369:
    stack[0] = (Lisp_Object)65; /* 4 */
    v366 = stack[-6];
    v365 = stack[-5];
    v365 = cons(v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    fn = elt(env, 7); /* typerror */
    v365 = (*qfn2(fn))(qenv(fn), stack[0], v365);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    goto v130;

v368:
    v365 = stack[-3];
    if (!(v365 == nil)) goto v311;
    v365 = stack[-2];
    if (!(v365 == nil)) goto v369;

v311:
    v365 = stack[-3];
    if (v365 == nil) goto v130;
    v365 = stack[-2];
    if (v365 == nil) goto v130;
    v365 = qvalue(elt(env, 4)); /* t */
    stack[-4] = v365;
    goto v130;

v9:
    v365 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v365;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v29:
    v365 = elt(env, 2); /* fortran */
    v366 = v365;
    goto v37;
/* error exit handlers */
v67:
    popv(9);
    return nil;
}



/* Code for mkupf */

static Lisp_Object CC_mkupf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v165, v146;
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v164 = v0;
/* end of prologue */
    v165 = v164;
    v164 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* mksq */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-1];
    stack[0] = v164;
    v164 = stack[0];
    v164 = qcar(v164);
    if (v164 == nil) goto v37;
    v164 = stack[0];
    v164 = qcar(v164);
    if (!consp(v164)) goto v19;
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = qcar(v164);
    if (!consp(v164)) goto v19;
    v164 = stack[0];
    v165 = qcdr(v164);
    v164 = (Lisp_Object)17; /* 1 */
    if (!(v165 == v164)) goto v90;
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v165 = qcdr(v164);
    v164 = (Lisp_Object)17; /* 1 */
    if (!(v165 == v164)) goto v90;
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = qcdr(v164);
    if (!(v164 == nil)) goto v90;
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcar(v164);
    fn = elt(env, 3); /* sfp */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-1];
    if (!(v164 == nil)) goto v90;
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcar(v164);
    v146 = qcar(v164);
    v165 = (Lisp_Object)17; /* 1 */
    v164 = (Lisp_Object)17; /* 1 */
    v164 = list2star(v146, v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v322;
    popv(2);
    return ncons(v164);

v90:
    v164 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* partitsq!* */
        return (*qfn1(fn))(qenv(fn), v164);
    }

v19:
    v165 = (Lisp_Object)17; /* 1 */
    v164 = stack[0];
    v164 = cons(v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v322;
    popv(2);
    return ncons(v164);

v37:
    v164 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v164); }
/* error exit handlers */
v322:
    popv(2);
    return nil;
}



/* Code for cos!* */

static Lisp_Object CC_cosH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cos*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v153 = v0;
/* end of prologue */
    v160 = v153;
    v153 = qvalue(elt(env, 1)); /* !:bprec!: */
    {
        fn = elt(env, 2); /* cos!: */
        return (*qfn2(fn))(qenv(fn), v160, v153);
    }
}



/* Code for aceq */

static Lisp_Object CC_aceq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v89, v88, v74;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aceq");
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
    v89 = v1;
    v88 = v0;
/* end of prologue */

v167:
    v87 = v88;
    if (v87 == nil) goto v126;
    v87 = v89;
    if (v87 == nil) goto v69;
    v87 = v88;
    v74 = qcar(v87);
    v87 = v89;
    v87 = Lmember(nil, v74, v87);
    if (v87 == nil) goto v2;
    v87 = v88;
    v87 = qcdr(v87);
    stack[0] = v87;
    v87 = v88;
    v87 = qcar(v87);
    v87 = Ldelete(nil, v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v89 = v87;
    v87 = stack[0];
    v88 = v87;
    goto v167;

v2:
    v87 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v87); }

v69:
    v87 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v87); }

v126:
    v87 = v89;
    v87 = (v87 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v87); }
/* error exit handlers */
v6:
    popv(2);
    return nil;
}



/* Code for collectphysops */

static Lisp_Object CC_collectphysops(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v4;
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
    v130 = stack[0];
    if (!consp(v130)) goto v126;
    v130 = stack[0];
    fn = elt(env, 2); /* physopp */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    if (v130 == nil) goto v167;
    stack[-1] = stack[0];
    v130 = stack[0];
    fn = elt(env, 3); /* collectindices */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    fn = elt(env, 4); /* removeindices */
    v130 = (*qfn2(fn))(qenv(fn), stack[-1], v130);
    nil = C_nil;
    if (exception_pending()) goto v136;
    popv(3);
    return ncons(v130);

v167:
    v130 = stack[0];
    v130 = qcar(v130);
    v4 = v130;
    v130 = stack[0];
    v130 = qcdr(v130);
    stack[0] = v130;
    v130 = v4;
    v130 = CC_collectphysops(env, v130);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v130 = Lnconc(nil, stack[-1], v130);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    stack[-1] = v130;
    v130 = stack[0];
    if (v130 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else goto v167;

v126:
    v130 = stack[0];
    fn = elt(env, 2); /* physopp */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    if (v130 == nil) goto v23;
    v130 = stack[0];
    popv(3);
    return ncons(v130);

v23:
    v130 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v130); }
/* error exit handlers */
v136:
    popv(3);
    return nil;
}



/* Code for color!-roads */

static Lisp_Object CC_colorKroads(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v152, v82;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color-roads");
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
    v82 = v0;
/* end of prologue */
    v151 = stack[-4];
    v151 = qcar(v151);
    v152 = qcar(v151);
    v151 = v82;
    v151 = Lassoc(nil, v152, v151);
    v151 = qcdr(v151);
    stack[-1] = v151;
    v151 = stack[-4];
    v151 = qcdr(v151);
    v151 = qcar(v151);
    v152 = qcar(v151);
    v151 = v82;
    v151 = Lassoc(nil, v152, v151);
    v151 = qcdr(v151);
    stack[0] = v151;
    v151 = stack[-4];
    v151 = qcdr(v151);
    v151 = qcdr(v151);
    v151 = qcar(v151);
    v151 = qcar(v151);
    v152 = v82;
    v151 = Lassoc(nil, v151, v152);
    v151 = qcdr(v151);
    stack[-5] = v151;
    stack[-2] = stack[-1];
    v152 = stack[0];
    v151 = stack[-5];
    v151 = plus2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-6];
    v152 = plus2(stack[-2], v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-6];
    v151 = (Lisp_Object)33; /* 2 */
    v151 = quot2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-6];
    stack[-2] = v151;
    v152 = stack[-2];
    v151 = stack[-1];
    v151 = difference2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-6];
    stack[-1] = v151;
    v152 = stack[-2];
    v151 = stack[0];
    v151 = difference2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-6];
    stack[0] = v151;
    v152 = stack[-2];
    v151 = stack[-5];
    v151 = difference2(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-6];
    stack[-5] = v151;
    v151 = stack[-4];
    v151 = qcar(v151);
    stack[-3] = qcar(v151);
    stack[-2] = stack[-1];
    v151 = stack[-4];
    v151 = qcdr(v151);
    v151 = qcar(v151);
    stack[-1] = qcar(v151);
    v151 = stack[-4];
    v151 = qcdr(v151);
    v151 = qcdr(v151);
    v151 = qcar(v151);
    v152 = qcar(v151);
    v151 = stack[-5];
    v151 = cons(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-6];
    v151 = ncons(v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-6];
    v151 = acons(stack[-1], stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v375;
    {
        Lisp_Object v376 = stack[-3];
        Lisp_Object v79 = stack[-2];
        popv(7);
        return acons(v376, v79, v151);
    }
/* error exit handlers */
v375:
    popv(7);
    return nil;
}



/* Code for remchkf1 */

static Lisp_Object CC_remchkf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v89, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remchkf1");
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
    v87 = stack[-1];
    fn = elt(env, 3); /* termsf */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    stack[-2] = v87;
    v88 = stack[-1];
    v89 = stack[0];
    v87 = stack[-2];
    fn = elt(env, 4); /* xremf */
    v87 = (*qfnn(fn))(qenv(fn), 3, v88, v89, v87);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    stack[0] = v87;
    v87 = stack[0];
    if (v87 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v87 = stack[0];
    v87 = qcar(v87);
    stack[0] = v87;
    fn = elt(env, 3); /* termsf */
    v89 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    v87 = stack[-2];
    v87 = (Lisp_Object)geq2(v89, v87);
    nil = C_nil;
    if (exception_pending()) goto v127;
    v87 = v87 ? lisp_true : nil;
    env = stack[-3];
    if (!(v87 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v87 = qvalue(elt(env, 1)); /* !*trcompact */
    if (v87 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v87 = elt(env, 2); /* "*** Remainder smaller" */
    fn = elt(env, 5); /* prin2t */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v127;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v127:
    popv(4);
    return nil;
}



/* Code for reduce!-eival!-powers */

static Lisp_Object CC_reduceKeivalKpowers(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v116, v139, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-eival-powers");
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
    v139 = v1;
    v117 = v0;
/* end of prologue */
    v7 = v139;
    if (!consp(v7)) goto v8;
    v7 = v139;
    v7 = qcar(v7);
    if (!consp(v7)) goto v8;
    v7 = v139;
    v7 = qcar(v7);
    v7 = qcar(v7);
    v116 = qcar(v7);
    v7 = v117;
    v7 = qcar(v7);
    v7 = qcar(v7);
    if (!(v116 == v7)) goto v8;
    stack[0] = v117;
    v116 = v139;
    v7 = (Lisp_Object)17; /* 1 */
    v7 = cons(v116, v7);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    {
        Lisp_Object v4 = stack[0];
        popv(2);
        fn = elt(env, 1); /* reduce!-eival!-powers1 */
        return (*qfn2(fn))(qenv(fn), v4, v7);
    }

v8:
    v116 = v139;
    v7 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v116, v7);
/* error exit handlers */
v130:
    popv(2);
    return nil;
}



/* Code for cl_fvarl */

static Lisp_Object CC_cl_fvarl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_fvarl");
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
    v160 = v0;
/* end of prologue */
    fn = elt(env, 2); /* cl_fvarl1 */
    v135 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[0];
    v160 = elt(env, 1); /* ordp */
    {
        popv(1);
        fn = elt(env, 3); /* sort */
        return (*qfn2(fn))(qenv(fn), v135, v160);
    }
/* error exit handlers */
v34:
    popv(1);
    return nil;
}



/* Code for formboollis */

static Lisp_Object MS_CDECL CC_formboollis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v18, Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v129, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "formboollis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formboollis");
#endif
    if (stack >= stacklimit)
    {
        push4(v31,v18,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v18,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v18;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v15;

v15:
    v100 = stack[-3];
    if (v100 == nil) goto v160;
    v100 = stack[0];
    if (v100 == nil) goto v74;
    v100 = stack[-3];
    v10 = qcar(v100);
    v129 = stack[-2];
    v100 = stack[-1];
    fn = elt(env, 1); /* formbool */
    v129 = (*qfnn(fn))(qenv(fn), 3, v10, v129, v100);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    v100 = stack[-4];
    v100 = cons(v129, v100);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    stack[-4] = v100;
    goto v153;

v153:
    v100 = stack[-3];
    v100 = qcdr(v100);
    stack[-3] = v100;
    goto v15;

v74:
    v100 = stack[-3];
    v10 = qcar(v100);
    v129 = stack[-2];
    v100 = stack[-1];
    fn = elt(env, 2); /* formc!* */
    v129 = (*qfnn(fn))(qenv(fn), 3, v10, v129, v100);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    v100 = stack[-4];
    v100 = cons(v129, v100);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    stack[-4] = v100;
    goto v153;

v160:
    v100 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); /* reversip!* */
        return (*qfn1(fn))(qenv(fn), v100);
    }
/* error exit handlers */
v17:
    popv(6);
    return nil;
}



/* Code for enter!-sorted */

static Lisp_Object CC_enterKsorted(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for enter-sorted");
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
    goto v167;

v167:
    v129 = stack[0];
    if (v129 == nil) goto v34;
    v129 = stack[-1];
    v10 = qcar(v129);
    v129 = stack[0];
    v129 = qcar(v129);
    v129 = qcar(v129);
    fn = elt(env, 1); /* taydegree!< */
    v129 = (*qfn2(fn))(qenv(fn), v10, v129);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    if (v129 == nil) goto v116;
    v10 = stack[-1];
    v129 = stack[0];
    v129 = cons(v10, v129);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    {
        Lisp_Object v163 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v163, v129);
    }

v116:
    v129 = stack[0];
    v10 = qcar(v129);
    v129 = stack[-2];
    v129 = cons(v10, v129);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    stack[-2] = v129;
    v129 = stack[0];
    v129 = qcdr(v129);
    stack[0] = v129;
    goto v167;

v34:
    stack[0] = stack[-2];
    v129 = stack[-1];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    {
        Lisp_Object v17 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v17, v129);
    }
/* error exit handlers */
v121:
    popv(4);
    return nil;
}



/* Code for symbolsom */

static Lisp_Object CC_symbolsom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v375, v376, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbolsom");
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
    stack[-1] = nil;
    v375 = stack[-4];
    v376 = qcar(v375);
    v375 = qvalue(elt(env, 1)); /* valid_om!* */
    v375 = Lassoc(nil, v376, v375);
    stack[-5] = v375;
    v375 = stack[-5];
    if (v375 == nil) goto v22;
    v375 = stack[-5];
    v375 = qcdr(v375);
    v375 = qcar(v375);
    stack[-5] = v375;
    goto v22;

v22:
    v375 = stack[-4];
    v375 = qcar(v375);
    stack[0] = v375;
    v375 = stack[-4];
    v375 = qcdr(v375);
    v375 = qcdr(v375);
    v375 = qcar(v375);
    stack[-3] = v375;
    v375 = stack[-4];
    v375 = Lreverse(nil, v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = qcar(v375);
    stack[-2] = v375;
    v376 = stack[0];
    v375 = elt(env, 2); /* diff */
    if (v376 == v375) goto v27;
    v375 = stack[-4];
    v375 = qcdr(v375);
    v375 = qcdr(v375);
    v375 = qcdr(v375);
    v375 = qcar(v375);
    stack[-1] = v375;
    goto v27;

v27:
    v375 = stack[-1];
    if (v375 == nil) goto v116;
    v375 = stack[-1];
    v376 = qcar(v375);
    v375 = elt(env, 3); /* condition */
    if (!(v376 == v375)) goto v116;
    v376 = elt(env, 4); /* "<condition> tag not supported in MathML" */
    v375 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* errorml */
    v375 = (*qfn2(fn))(qenv(fn), v376, v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    goto v116;

v116:
    v375 = elt(env, 5); /* "<OMA>" */
    fn = elt(env, 16); /* printout */
    v375 = (*qfn1(fn))(qenv(fn), v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = qvalue(elt(env, 6)); /* t */
    fn = elt(env, 17); /* indent!* */
    v375 = (*qfn1(fn))(qenv(fn), v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = stack[-1];
    if (v375 == nil) goto v156;
    v376 = stack[0];
    v375 = elt(env, 7); /* int */
    if (!(v376 == v375)) goto v156;
    v375 = elt(env, 8); /* defint */
    stack[0] = v375;
    goto v156;

v156:
    v375 = elt(env, 9); /* "<OMS cd=""" */
    fn = elt(env, 16); /* printout */
    v375 = (*qfn1(fn))(qenv(fn), v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = stack[-5];
    v375 = Lprinc(nil, v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = elt(env, 10); /* """ name=""" */
    v375 = Lprinc(nil, v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = stack[0];
    v375 = Lprinc(nil, v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = elt(env, 11); /* """/>" */
    v375 = Lprinc(nil, v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = stack[-1];
    if (v375 == nil) goto v318;
    v375 = stack[-1];
    fn = elt(env, 18); /* objectom */
    v375 = (*qfn1(fn))(qenv(fn), v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    goto v318;

v318:
    stack[-1] = elt(env, 12); /* lambda */
    stack[0] = qvalue(elt(env, 13)); /* nil */
    v79 = stack[-3];
    v376 = stack[-2];
    v375 = qvalue(elt(env, 13)); /* nil */
    v375 = list2star(v79, v376, v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = list2star(stack[-1], stack[0], v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    fn = elt(env, 19); /* lambdaom */
    v375 = (*qfn1(fn))(qenv(fn), v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = qvalue(elt(env, 13)); /* nil */
    fn = elt(env, 17); /* indent!* */
    v375 = (*qfn1(fn))(qenv(fn), v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-6];
    v375 = elt(env, 14); /* "</OMA>" */
    fn = elt(env, 16); /* printout */
    v375 = (*qfn1(fn))(qenv(fn), v375);
    nil = C_nil;
    if (exception_pending()) goto v377;
    v375 = nil;
    { popv(7); return onevalue(v375); }
/* error exit handlers */
v377:
    popv(7);
    return nil;
}



/* Code for maxl */

static Lisp_Object CC_maxl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxl");
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
    goto v167;

v167:
    v133 = stack[0];
    if (v133 == nil) goto v105;
    v133 = stack[0];
    v87 = qcar(v133);
    v133 = stack[-1];
    v133 = cons(v87, v133);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    stack[-1] = v133;
    v133 = stack[0];
    v133 = qcdr(v133);
    stack[0] = v133;
    goto v167;

v105:
    v133 = (Lisp_Object)-159999; /* -10000 */
    v87 = v133;
    goto v15;

v15:
    v133 = stack[-1];
    if (v133 == nil) { popv(3); return onevalue(v87); }
    v133 = stack[-1];
    v133 = qcar(v133);
    fn = elt(env, 1); /* max */
    v133 = (*qfn2(fn))(qenv(fn), v133, v87);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v87 = v133;
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-1] = v133;
    goto v15;
/* error exit handlers */
v74:
    popv(3);
    return nil;
}



/* Code for sptransmat */

static Lisp_Object CC_sptransmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v383, v384, v309;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sptransmat");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v84 = stack[-1];
    v84 = Lconsp(nil, v84);
    env = stack[-7];
    if (v84 == nil) goto v150;
    v84 = stack[-1];
    stack[0] = v84;
    v84 = stack[-1];
    fn = elt(env, 3); /* matlength */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v84 = qcdr(v84);
    goto v34;

v34:
    v383 = (Lisp_Object)1; /* 0 */
    stack[-6] = v383;
    v383 = (Lisp_Object)1; /* 0 */
    stack[-5] = v383;
    v383 = v84;
    stack[-1] = qcar(v383);
    v383 = elt(env, 1); /* spm */
    v84 = cons(v383, v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    fn = elt(env, 4); /* mkempspmat */
    v84 = (*qfn2(fn))(qenv(fn), stack[-1], v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-2] = v84;
    v84 = qvalue(elt(env, 2)); /* nil */
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-3] = v84;
    v84 = stack[0];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v117;

v117:
    v84 = stack[-1];
    if (v84 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v84 = stack[-1];
    v84 = qcar(v84);
    stack[0] = v84;
    v84 = stack[-6];
    v84 = add1(v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-6] = v84;
    v84 = stack[0];
    stack[0] = v84;
    goto v124;

v124:
    v84 = stack[0];
    if (v84 == nil) goto v123;
    v84 = stack[0];
    v84 = qcar(v84);
    stack[-4] = v84;
    v84 = stack[-5];
    v84 = add1(v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-5] = v84;
    v383 = stack[-4];
    v84 = (Lisp_Object)1; /* 0 */
    if (v383 == v84) goto v90;
    v384 = stack[-5];
    v383 = stack[-4];
    v84 = stack[-3];
    v84 = acons(v384, v383, v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-3] = v84;
    goto v90;

v90:
    v84 = stack[0];
    v84 = qcdr(v84);
    stack[0] = v84;
    goto v124;

v123:
    v84 = stack[-3];
    v84 = Lreverse(nil, v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-3] = v84;
    stack[0] = stack[-3];
    v84 = qvalue(elt(env, 2)); /* nil */
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    if (equal(stack[0], v84)) goto v331;
    v383 = stack[-2];
    v84 = stack[-6];
    v309 = list2(v383, v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v384 = stack[-3];
    v383 = stack[-2];
    v84 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 5); /* letmtr3 */
    v84 = (*qfnn(fn))(qenv(fn), 4, v309, v384, v383, v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    goto v331;

v331:
    v84 = (Lisp_Object)1; /* 0 */
    stack[-5] = v84;
    v84 = qvalue(elt(env, 2)); /* nil */
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-3] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v117;

v150:
    v84 = stack[-1];
    fn = elt(env, 6); /* aeval */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[0] = v84;
    v84 = stack[-1];
    fn = elt(env, 6); /* aeval */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    fn = elt(env, 3); /* matlength */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v84 = qcdr(v84);
    goto v34;
/* error exit handlers */
v360:
    popv(8);
    return nil;
}



/* Code for gcompatible */

static Lisp_Object CC_gcompatible(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v29, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcompatible");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v1;
    v119 = v0;
/* end of prologue */
    v120 = qvalue(elt(env, 1)); /* gmodule!* */
    v120 = (v120 == nil ? lisp_true : nil);
    if (!(v120 == nil)) return onevalue(v120);
    v120 = v119;
    v120 = qcdr(v120);
    v119 = qcar(v120);
    v120 = v29;
    v120 = qcdr(v120);
    v29 = qcar(v120);
    v120 = qvalue(elt(env, 1)); /* gmodule!* */
    {
        fn = elt(env, 2); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v119, v29, v120);
    }
}



/* Code for f2dip1 */

static Lisp_Object MS_CDECL CC_f2dip1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v18, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v320, v374, v164, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "f2dip1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip1");
#endif
    if (stack >= stacklimit)
    {
        push3(v18,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v18);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v18;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v91 = stack[-2];
    if (v91 == nil) goto v167;
    v91 = stack[-2];
    if (!consp(v91)) goto v153;
    v91 = stack[-2];
    v91 = qcar(v91);
    if (!consp(v91)) goto v153;
    v91 = stack[-2];
    v91 = qcar(v91);
    v91 = qcar(v91);
    v165 = qcar(v91);
    v91 = stack[-2];
    v91 = qcar(v91);
    v91 = qcar(v91);
    v164 = qcdr(v91);
    v91 = stack[-2];
    v91 = qcar(v91);
    v374 = qcdr(v91);
    v320 = stack[-1];
    v91 = stack[0];
    fn = elt(env, 2); /* f2dip2 */
    stack[-3] = (*qfnn(fn))(qenv(fn), 5, v165, v164, v374, v320, v91);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-4];
    v91 = stack[-2];
    v374 = qcdr(v91);
    v320 = stack[-1];
    v91 = stack[0];
    v91 = CC_f2dip1(env, 3, v374, v320, v91);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-4];
    {
        Lisp_Object v319 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* dipsum */
        return (*qfn2(fn))(qenv(fn), v319, v91);
    }

v153:
    v91 = stack[0];
    v91 = (is_number(v91) ? lisp_true : nil);
    if (!(v91 == nil)) goto v27;
    v91 = stack[0];
    fn = elt(env, 4); /* f2dip11 */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-4];
    goto v27;

v27:
    v91 = stack[-2];
    fn = elt(env, 5); /* bcfd */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-4];
    fn = elt(env, 6); /* bcprod */
    v91 = (*qfn2(fn))(qenv(fn), stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-4];
    v320 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v316 = stack[-1];
        popv(5);
        return list2star(v316, v91, v320);
    }

v167:
    v91 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v91); }
/* error exit handlers */
v321:
    popv(5);
    return nil;
}



/* Code for !*!*a2i */

static Lisp_Object CC_HHa2i(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **a2i");
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
    v128 = v1;
    stack[0] = v0;
/* end of prologue */
    v8 = stack[0];
    fn = elt(env, 2); /* intexprnp */
    v128 = (*qfn2(fn))(qenv(fn), v8, v128);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-1];
    if (!(v128 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v8 = elt(env, 1); /* ieval */
    v128 = stack[0];
    popv(2);
    return list2(v8, v128);
/* error exit handlers */
v115:
    popv(2);
    return nil;
}



/* Code for atom_compare */

static Lisp_Object CC_atom_compare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v2, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atom_compare");
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
    v2 = v1;
    v16 = v0;
/* end of prologue */
    v159 = v16;
    if (is_number(v159)) goto v14;
    v159 = v2;
    if (symbolp(v159)) goto v115;
    v159 = v2;
    v159 = (is_number(v159) ? lisp_true : nil);
    return onevalue(v159);

v115:
    v159 = v16;
        return Lorderp(nil, v159, v2);

v14:
    v159 = v2;
    if (is_number(v159)) goto v132;
    v159 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v159);

v132:
    v159 = v16;
    v159 = (Lisp_Object)lessp2(v159, v2);
    errexit();
    v159 = v159 ? lisp_true : nil;
    v159 = (v159 == nil ? lisp_true : nil);
    return onevalue(v159);
}



/* Code for msolve!-poly1 */

static Lisp_Object CC_msolveKpoly1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v400, v401;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-poly1");
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
    v39 = stack[-5];
    if (!consp(v39)) goto v161;
    v39 = stack[-5];
    v39 = qcar(v39);
    if (!consp(v39)) goto v161;
    v39 = stack[-5];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v400 = qcdr(v39);
    v39 = (Lisp_Object)17; /* 1 */
    if (!(v400 == v39)) goto v161;
    v39 = stack[-5];
    v39 = qcar(v39);
    v39 = qcdr(v39);
    fn = elt(env, 5); /* safe!-modrecip */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v39;
    v39 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v39; /* erfg!* */
    v39 = stack[0];
    if (v39 == nil) goto v161;
    v39 = stack[-5];
    v39 = qcdr(v39);
    fn = elt(env, 6); /* negf */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 7); /* multf */
    v39 = (*qfn2(fn))(qenv(fn), stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 8); /* moduntag */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v39;
    v39 = stack[0];
    if (v39 == nil) goto v139;
    v400 = stack[0];
    v39 = (Lisp_Object)1; /* 0 */
    v39 = (Lisp_Object)lessp2(v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v39 = v39 ? lisp_true : nil;
    env = stack[-7];
    if (!(v39 == nil)) goto v117;
    v400 = stack[0];
    v39 = qvalue(elt(env, 3)); /* current!-modulus */
    v39 = (Lisp_Object)greaterp2(v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v39 = v39 ? lisp_true : nil;
    env = stack[-7];
    if (!(v39 == nil)) goto v117;

v139:
    v39 = stack[0];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v39;
    goto v15;

v15:
    v39 = stack[0];
    stack[-5] = v39;
    v39 = stack[-5];
    if (v39 == nil) goto v295;
    v39 = stack[-5];
    v39 = qcar(v39);
    stack[0] = stack[-4];
    fn = elt(env, 9); /* prepf */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = cons(stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-2] = v39;
    stack[-3] = v39;
    goto v402;

v402:
    v39 = stack[-5];
    v39 = qcdr(v39);
    stack[-5] = v39;
    v39 = stack[-5];
    if (v39 == nil) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v39 = stack[-5];
    v39 = qcar(v39);
    stack[0] = stack[-4];
    fn = elt(env, 9); /* prepf */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = cons(stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = Lrplacd(nil, stack[-1], v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = stack[-2];
    v39 = qcdr(v39);
    stack[-2] = v39;
    goto v402;

v295:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v39); }

v117:
    v39 = stack[0];
    fn = elt(env, 10); /* general!-modular!-number */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v39;
    goto v139;

v161:
    v401 = stack[-5];
    v400 = stack[-4];
    v39 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 11); /* lowestdeg */
    v39 = (*qfnn(fn))(qenv(fn), 3, v401, v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-6] = v39;
    v400 = stack[-6];
    v39 = (Lisp_Object)1; /* 0 */
    v39 = (Lisp_Object)greaterp2(v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v39 = v39 ? lisp_true : nil;
    env = stack[-7];
    if (v39 == nil) goto v146;
    stack[0] = stack[-5];
    v401 = elt(env, 4); /* expt */
    v400 = stack[-4];
    v39 = stack[-6];
    v39 = list3(v401, v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 12); /* simp */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = qcar(v39);
    fn = elt(env, 13); /* quotf */
    v39 = (*qfn2(fn))(qenv(fn), stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-5] = v39;
    goto v146;

v146:
    v39 = stack[-5];
    fn = elt(env, 8); /* moduntag */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 14); /* general!-reduce!-mod!-p */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-5] = v39;
    v39 = (Lisp_Object)17; /* 1 */
    stack[-3] = v39;
    goto v363;

v363:
    v39 = qvalue(elt(env, 3)); /* current!-modulus */
    v400 = sub1(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = stack[-3];
    v39 = difference2(v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = Lminusp(nil, v39);
    env = stack[-7];
    if (v39 == nil) goto v403;
    v39 = qvalue(elt(env, 1)); /* nil */
    goto v82;

v82:
    stack[0] = v39;
    v400 = stack[-6];
    v39 = (Lisp_Object)1; /* 0 */
    v39 = (Lisp_Object)greaterp2(v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v39 = v39 ? lisp_true : nil;
    env = stack[-7];
    if (v39 == nil) goto v15;
    v39 = qvalue(elt(env, 1)); /* nil */
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = Lappend(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v39;
    goto v15;

v403:
    v401 = stack[-5];
    v400 = stack[-4];
    v39 = stack[-3];
    fn = elt(env, 15); /* general!-evaluate!-mod!-p */
    v39 = (*qfnn(fn))(qenv(fn), 3, v401, v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    if (v39 == nil) goto v368;
    v39 = nil;
    goto v311;

v311:
    stack[-2] = v39;
    v39 = stack[-2];
    fn = elt(env, 16); /* lastpair */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v39;
    v39 = stack[-3];
    v39 = add1(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-3] = v39;
    v39 = stack[-1];
    if (!consp(v39)) goto v363;
    else goto v304;

v304:
    v39 = qvalue(elt(env, 3)); /* current!-modulus */
    v400 = sub1(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = stack[-3];
    v39 = difference2(v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = Lminusp(nil, v39);
    env = stack[-7];
    if (v39 == nil) goto v404;
    v39 = stack[-2];
    goto v82;

v404:
    stack[0] = stack[-1];
    v401 = stack[-5];
    v400 = stack[-4];
    v39 = stack[-3];
    fn = elt(env, 15); /* general!-evaluate!-mod!-p */
    v39 = (*qfnn(fn))(qenv(fn), 3, v401, v400, v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    if (v39 == nil) goto v405;
    v39 = nil;
    goto v302;

v302:
    v39 = Lrplacd(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v39 = stack[-1];
    fn = elt(env, 16); /* lastpair */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v39;
    v39 = stack[-3];
    v39 = add1(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-3] = v39;
    goto v304;

v405:
    v39 = stack[-3];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v302;

v368:
    v39 = stack[-3];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v311;
/* error exit handlers */
v284:
    popv(8);
    return nil;
}



/* Code for make!-image */

static Lisp_Object CC_makeKimage(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image");
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
    v121 = stack[-2];
    if (!consp(v121)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v121 = stack[-2];
    v121 = qcar(v121);
    if (!consp(v121)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v121 = stack[-2];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v163 = qcar(v121);
    v121 = qvalue(elt(env, 1)); /* m!-image!-variable */
    if (equal(v163, v121)) goto v128;
    v163 = stack[-2];
    v121 = stack[-1];
    fn = elt(env, 2); /* evaluate!-in!-order */
    v121 = (*qfn2(fn))(qenv(fn), v163, v121);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v128:
    v121 = stack[-2];
    v121 = qcar(v121);
    stack[-3] = qcar(v121);
    v121 = stack[-2];
    v121 = qcar(v121);
    v163 = qcdr(v121);
    v121 = stack[-1];
    fn = elt(env, 2); /* evaluate!-in!-order */
    v121 = (*qfn2(fn))(qenv(fn), v163, v121);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    fn = elt(env, 3); /* !*n2f */
    stack[0] = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v121 = stack[-2];
    v163 = qcdr(v121);
    v121 = stack[-1];
    v121 = CC_makeKimage(env, v163, v121);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    {
        Lisp_Object v149 = stack[-3];
        Lisp_Object v148 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v149, v148, v121);
    }
/* error exit handlers */
v137:
    popv(5);
    return nil;
}



/* Code for mkid */

static Lisp_Object CC_mkid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkid");
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
    v116 = v0;
/* end of prologue */
    v139 = v116;
    if (symbolp(v139)) goto v167;
    v139 = v116;
    v116 = elt(env, 1); /* "MKID root" */
    {
        popv(3);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v139, v116);
    }

v167:
    v139 = stack[0];
    if (!(!consp(v139))) goto v89;
    v139 = stack[0];
    if (symbolp(v139)) goto v21;
    v139 = stack[0];
    v139 = integerp(v139);
    if (v139 == nil) goto v89;
    v139 = stack[0];
    v139 = Lminusp(nil, v139);
    env = stack[-2];
    if (!(v139 == nil)) goto v89;

v21:
    stack[-1] = Lexplode(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v116 = stack[0];
    v116 = Lexplode(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v116 = Lnconc(nil, stack[-1], v116);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v116 = Lcompress(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v130;
        popv(3);
        return Lintern(nil, v116);

v89:
    v139 = stack[0];
    v116 = elt(env, 2); /* "MKID index" */
    {
        popv(3);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v139, v116);
    }
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



setup_type const u25_setup[] =
{
    {"evaluate-in-order-mod-p", too_few_2,      CC_evaluateKinKorderKmodKp,wrong_no_2},
    {"ofsf_entry2at",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at},
    {"makecoeffpairshom",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairshom},
    {"sets",                    too_few_2,      CC_sets,       wrong_no_2},
    {"look_for_substitute",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_substitute},
    {"add_item",                too_few_2,      CC_add_item,   wrong_no_2},
    {"getphystypeall",          CC_getphystypeall,too_many_1,  wrong_no_1},
    {"edge_new_parents",        CC_edge_new_parents,too_many_1,wrong_no_1},
    {"innprodpex",              too_few_2,      CC_innprodpex, wrong_no_2},
    {"sqprint",                 CC_sqprint,     too_many_1,    wrong_no_1},
    {"bas_make",                too_few_2,      CC_bas_make,   wrong_no_2},
    {"macrochk",                too_few_2,      CC_macrochk,   wrong_no_2},
    {"rl_identifyonoff",        CC_rl_identifyonoff,too_many_1,wrong_no_1},
    {"vp2",                     CC_vp2,         too_many_1,    wrong_no_1},
    {"ev_revgradlexcomp",       too_few_2,      CC_ev_revgradlexcomp,wrong_no_2},
    {"listrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_listrd},
    {"domainvalchk",            too_few_2,      CC_domainvalchk,wrong_no_2},
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"greatertype",             too_few_2,      CC_greatertype,wrong_no_2},
    {"mkupf",                   CC_mkupf,       too_many_1,    wrong_no_1},
    {"cos*",                    CC_cosH,        too_many_1,    wrong_no_1},
    {"aceq",                    too_few_2,      CC_aceq,       wrong_no_2},
    {"collectphysops",          CC_collectphysops,too_many_1,  wrong_no_1},
    {"color-roads",             too_few_2,      CC_colorKroads,wrong_no_2},
    {"remchkf1",                too_few_2,      CC_remchkf1,   wrong_no_2},
    {"reduce-eival-powers",     too_few_2,      CC_reduceKeivalKpowers,wrong_no_2},
    {"cl_fvarl",                CC_cl_fvarl,    too_many_1,    wrong_no_1},
    {"formboollis",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_formboollis},
    {"enter-sorted",            too_few_2,      CC_enterKsorted,wrong_no_2},
    {"symbolsom",               CC_symbolsom,   too_many_1,    wrong_no_1},
    {"maxl",                    CC_maxl,        too_many_1,    wrong_no_1},
    {"sptransmat",              CC_sptransmat,  too_many_1,    wrong_no_1},
    {"gcompatible",             too_few_2,      CC_gcompatible,wrong_no_2},
    {"f2dip1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip1},
    {"**a2i",                   too_few_2,      CC_HHa2i,      wrong_no_2},
    {"atom_compare",            too_few_2,      CC_atom_compare,wrong_no_2},
    {"msolve-poly1",            too_few_2,      CC_msolveKpoly1,wrong_no_2},
    {"make-image",              too_few_2,      CC_makeKimage, wrong_no_2},
    {"mkid",                    too_few_2,      CC_mkid,       wrong_no_2},
    {NULL, (one_args *)"u25", (two_args *)"4635 3757137 114132", 0}
};

/* end of generated code */
