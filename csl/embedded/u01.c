
/* $destdir/generated-c\u01.c Machine generated C code */

/* Signature: 00000000 20-Aug-2010 */

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


/* Code for noncomp */

static Lisp_Object CC_noncomp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v1 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v1 == nil) goto v3;
    v1 = v2;
    {
        fn = elt(env, 3); /* noncomp1 */
        return (*qfn1(fn))(qenv(fn), v1);
    }

v3:
    v1 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v1);
}



/* Code for simpcar */

static Lisp_Object CC_simpcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qcar(v4);
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



/* Code for reval */

static Lisp_Object CC_reval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = v7;
    v7 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for terminalp */

static Lisp_Object MS_CDECL CC_terminalp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "terminalp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for terminalp");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v8 = qvalue(elt(env, 1)); /* !*int */
    if (v8 == nil) goto v9;
    v8 = qvalue(elt(env, 3)); /* ifl!* */
    v8 = (v8 == nil ? lisp_true : nil);
    return onevalue(v8);

v9:
    v8 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v8);
}



/* Code for delcp */

static Lisp_Object CC_delcp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delcp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* delchar */
        return Lflagp(nil, v7, v8);
}



/* Code for ordop */

static Lisp_Object CC_ordop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v19, v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v10;
    v21 = v0;
/* end of prologue */
    v17 = qvalue(elt(env, 1)); /* kord!* */
    v19 = v17;
    goto v22;

v22:
    v17 = v19;
    if (v17 == nil) goto v23;
    v18 = v21;
    v17 = v19;
    v17 = qcar(v17);
    if (v18 == v17) goto v24;
    v18 = v20;
    v17 = v19;
    v17 = qcar(v17);
    if (v18 == v17) goto v25;
    v17 = v19;
    v17 = qcdr(v17);
    v19 = v17;
    goto v22;

v25:
    v17 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v17);

v24:
    v17 = qvalue(elt(env, 2)); /* t */
    return onevalue(v17);

v23:
    v17 = v21;
    v18 = v20;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v17, v18);
    }
}



/* Code for exchk */

static Lisp_Object CC_exchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28, v29, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exchk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v0;
/* end of prologue */
    v15 = v27;
    v29 = qvalue(elt(env, 1)); /* nil */
    v28 = qvalue(elt(env, 1)); /* nil */
    v27 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* exchk1 */
        return (*qfnn(fn))(qenv(fn), 4, v15, v29, v28, v27);
    }
}



/* Code for noncomfp */

static Lisp_Object CC_noncomfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomfp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v1 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v1 == nil) goto v3;
    v1 = v2;
    {
        fn = elt(env, 3); /* noncomfp1 */
        return (*qfn1(fn))(qenv(fn), v1);
    }

v3:
    v1 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v1);
}



/* Code for wuconstantp */

static Lisp_Object CC_wuconstantp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wuconstantp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v31 = v32;
    v31 = (consp(v31) ? nil : lisp_true);
    if (!(v31 == nil)) goto v22;
    v31 = v32;
    v31 = qcar(v31);
    v31 = (consp(v31) ? nil : lisp_true);
    goto v22;

v22:
    if (!(v31 == nil)) return onevalue(v31);
    v31 = v32;
    v31 = qcar(v31);
    v31 = qcar(v31);
    v31 = qcar(v31);
    v32 = qvalue(elt(env, 1)); /* wuvarlist!* */
    v31 = Lmemq(nil, v31, v32);
    v31 = (v31 == nil ? lisp_true : nil);
    return onevalue(v31);
}



/* Code for mkcopy */

static Lisp_Object CC_mkcopy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkcopy");
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
    goto v4;

v4:
    v35 = stack[0];
    if (!consp(v35)) goto v1;
    v35 = stack[0];
    v35 = qcar(v35);
    v36 = CC_mkcopy(env, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v35 = stack[-1];
    v35 = cons(v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    stack[-1] = v35;
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v4;

v1:
    v36 = stack[-1];
    v35 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v36, v35);
    }
/* error exit handlers */
v37:
    popv(3);
    return nil;
}



/* Code for remove!-free!-vars!-l */

static Lisp_Object CC_removeKfreeKvarsKl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars-l");
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
    v40 = stack[0];
    if (!consp(v40)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v40 = stack[0];
    v41 = qcar(v40);
    v40 = elt(env, 1); /* !*sq */
    if (v41 == v40) goto v8;
    v40 = stack[0];
    v40 = qcar(v40);
    fn = elt(env, 2); /* remove!-free!-vars */
    stack[-1] = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    v40 = stack[0];
    v40 = qcdr(v40);
    v40 = CC_removeKfreeKvarsKl(env, v40);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    v40 = cons(stack[-1], v40);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v42 = v40;
    v41 = v42;
    v40 = stack[0];
    if (equal(v41, v40)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else { popv(3); return onevalue(v42); }

v8:
    v40 = stack[0];
    v40 = qcdr(v40);
    v40 = qcar(v40);
    fn = elt(env, 3); /* prepsq!* */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    stack[0] = v40;
    goto v3;
/* error exit handlers */
v43:
    popv(3);
    return nil;
}



/* Code for num!-exponents */

static Lisp_Object CC_numKexponents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num-exponents");
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

v45:
    v44 = stack[0];
    v44 = (consp(v44) ? nil : lisp_true);
    if (!(v44 == nil)) goto v22;
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = (consp(v44) ? nil : lisp_true);
    goto v22;

v22:
    if (!(v44 == nil)) { popv(2); return onevalue(v44); }
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = qcar(v44);
    v44 = qcdr(v44);
    v44 = integerp(v44);
    if (v44 == nil) goto v26;
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = qcdr(v44);
    v44 = CC_numKexponents(env, v44);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    if (v44 == nil) goto v46;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v45;

v46:
    v44 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v44); }

v26:
    v44 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v44); }
/* error exit handlers */
v37:
    popv(2);
    return nil;
}



/* Code for mchkopt */

static Lisp_Object CC_mchkopt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v14, v48, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchkopt");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v14 = v10;
    v48 = v0;
/* end of prologue */
    v47 = v14;
    v25 = qcar(v47);
    v47 = elt(env, 1); /* optional */
    v47 = get(v25, v47);
    env = stack[0];
    v25 = v47;
    v47 = v25;
    if (v47 == nil) goto v27;
    v47 = v48;
    v48 = v25;
    {
        popv(1);
        fn = elt(env, 2); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v47, v14, v48);
    }

v27:
    v47 = nil;
    { popv(1); return onevalue(v47); }
}



/* Code for nth */

static Lisp_Object CC_nth(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nth");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v10;
    v2 = v0;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    errexit();
    v1 = qcar(v1);
    return onevalue(v1);
}



/* Code for ibalp_cec */

static Lisp_Object CC_ibalp_cec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_cec");
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
    v30 = stack[0];
    if (v30 == nil) goto v49;
    v30 = stack[0];
    v30 = qcar(v30);
    fn = elt(env, 2); /* ibalp_emptyclausep */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    if (v30 == nil) goto v29;
    v30 = stack[0];
    v30 = qcar(v30);
    { popv(2); return onevalue(v30); }

v29:
    v30 = stack[0];
    v30 = qcdr(v30);
    stack[0] = v30;
    goto v3;

v49:
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v30); }
/* error exit handlers */
v50:
    popv(2);
    return nil;
}



/* Code for delall */

static Lisp_Object CC_delall(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delall");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */

v4:
    v52 = stack[0];
    if (v52 == nil) goto v5;
    v17 = stack[-1];
    v52 = stack[0];
    v52 = qcar(v52);
    if (equal(v17, v52)) goto v1;
    v52 = stack[0];
    v52 = qcar(v52);
    stack[-2] = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v17 = stack[-1];
    v52 = stack[0];
    v52 = qcdr(v52);
    v52 = CC_delall(env, v17, v52);
    nil = C_nil;
    if (exception_pending()) goto v21;
    {
        Lisp_Object v38 = stack[-2];
        popv(4);
        return Lappend(nil, v38, v52);
    }

v1:
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v4;

v5:
    v52 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v52); }
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for ps!:getv */

static Lisp_Object CC_psTgetv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:getv");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    v60 = v0;
/* end of prologue */
    v59 = v60;
    v58 = elt(env, 1); /* !:ps!: */
    if (!consp(v59)) goto v17;
    v59 = qcar(v59);
    if (!(v59 == v58)) goto v17;
    v58 = v60;
    v58 = qcdr(v58);
    if (symbolp(v58)) goto v24;
    v58 = v60;
    v59 = qcdr(v58);
    v58 = stack[0];
    v58 = *(Lisp_Object *)((char *)v59 + (CELL-TAG_VECTOR) + ((int32_t)v58/(16/CELL)));
    { popv(3); return onevalue(v58); }

v24:
    v58 = v60;
    v58 = qcdr(v58);
    fn = elt(env, 4); /* eval */
    v59 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v58 = stack[0];
    v58 = *(Lisp_Object *)((char *)v59 + (CELL-TAG_VECTOR) + ((int32_t)v58/(16/CELL)));
    { popv(3); return onevalue(v58); }

v17:
    stack[-1] = elt(env, 2); /* tps */
    stack[0] = (Lisp_Object)17; /* 1 */
    v58 = elt(env, 3); /* "PS:GETV: not a ps" */
    v59 = v60;
    v58 = list2(v58, v59);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    {
        Lisp_Object v62 = stack[-1];
        Lisp_Object v63 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v62, v63, v58);
    }
/* error exit handlers */
v61:
    popv(3);
    return nil;
}



/* Code for add_prin_char */

static Lisp_Object CC_add_prin_char(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v66;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_prin_char");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v62 = qvalue(elt(env, 1)); /* !*nat */
    if (v62 == nil) goto v4;
    v66 = qvalue(elt(env, 3)); /* posn!* */
    v63 = stack[0];
    v62 = qvalue(elt(env, 4)); /* ycoord!* */
    v66 = acons(v66, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v63 = stack[-1];
    v62 = qvalue(elt(env, 5)); /* pline!* */
    v62 = acons(v66, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    qvalue(elt(env, 5)) = v62; /* pline!* */
    v62 = stack[0];
    qvalue(elt(env, 3)) = v62; /* posn!* */
    { popv(3); return onevalue(v62); }

v4:
    v62 = stack[-1];
    v62 = Lstringp(nil, v62);
    env = stack[-2];
    if (!(v62 == nil)) goto v7;
    v63 = stack[-1];
    v62 = elt(env, 2); /* switch!* */
    v62 = get(v63, v62);
    env = stack[-2];
    if (!(v62 == nil)) goto v7;
    v62 = stack[-1];
    v62 = Ldigitp(nil, v62);
    env = stack[-2];
    if (!(v62 == nil)) goto v7;
    v62 = stack[-1];
    v62 = Lexplodec(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v63 = qcar(v62);
    v62 = elt(env, 2); /* switch!* */
    v62 = get(v63, v62);
    if (!(v62 == nil)) goto v7;
    v62 = stack[-1];
        popv(3);
        return Lprin(nil, v62);

v7:
    v62 = stack[-1];
        popv(3);
        return Lprinc(nil, v62);
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for c!:ordxp */

static Lisp_Object CC_cTordxp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordxp");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v51 = v10;
    v52 = v0;
/* end of prologue */
    v17 = v52;
    v17 = Lconsp(nil, v17);
    env = stack[0];
    if (v17 == nil) goto v22;
    v17 = v51;
    v17 = Lconsp(nil, v17);
    env = stack[0];
    if (v17 == nil) goto v31;
    v52 = qcdr(v52);
    v51 = qcdr(v51);
        popv(1);
        return Llessp(nil, v52, v51);

v31:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v51); }

v22:
    v17 = v51;
    v17 = Lconsp(nil, v17);
    env = stack[0];
    if (v17 == nil) goto v11;
    v51 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v51); }

v11:
        popv(1);
        return Llessp(nil, v52, v51);
}



/* Code for dm!-abs */

static Lisp_Object CC_dmKabs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-abs");
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
    v2 = stack[0];
    fn = elt(env, 1); /* !:minusp */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    if (v2 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v2 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* dm!-minus */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for evcomp */

static Lisp_Object CC_evcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v29 = v10;
    v15 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dipsortevcomp!* */
    v29 = list2(v15, v29);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    {
        Lisp_Object v30 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v30, v29);
    }
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for evmatrixcomp2 */

static Lisp_Object MS_CDECL CC_evmatrixcomp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v10,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76, v77, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmatrixcomp2");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v10,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v34;
    stack[-1] = v10;
    stack[-2] = v0;
/* end of prologue */

v45:
    v75 = stack[-2];
    if (v75 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v75 = stack[-1];
    if (v75 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v75 = stack[-1];
    v75 = qcar(v75);
    stack[-3] = v75;
    v76 = stack[-3];
    v75 = (Lisp_Object)1; /* 0 */
    v75 = Leqn(nil, v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    if (v75 == nil) goto v18;
    v75 = stack[-2];
    v77 = qcdr(v75);
    v75 = stack[-1];
    v76 = qcdr(v75);
    v75 = stack[0];
    stack[-2] = v77;
    stack[-1] = v76;
    stack[0] = v75;
    goto v45;

v18:
    v76 = stack[-3];
    v75 = (Lisp_Object)17; /* 1 */
    v75 = Leqn(nil, v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    if (v75 == nil) goto v80;
    v75 = stack[-2];
    v78 = qcdr(v75);
    v75 = stack[-1];
    v77 = qcdr(v75);
    v76 = stack[0];
    v75 = stack[-2];
    v75 = qcar(v75);
    v75 = (Lisp_Object)(int32_t)((int32_t)v76 + (int32_t)v75 - TAG_FIXNUM);
    stack[-2] = v78;
    stack[-1] = v77;
    stack[0] = v75;
    goto v45;

v80:
    v78 = stack[-2];
    v77 = stack[-3];
    v76 = stack[-1];
    v75 = stack[0];
    {
        popv(5);
        fn = elt(env, 1); /* evmatrixcomp3 */
        return (*qfnn(fn))(qenv(fn), 4, v78, v77, v76, v75);
    }
/* error exit handlers */
v79:
    popv(5);
    return nil;
}



/* Code for xval */

static Lisp_Object CC_xval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v0;
/* end of prologue */
    v22 = qcar(v22);
    v22 = qcar(v22);
    {
        fn = elt(env, 1); /* wedgefax */
        return (*qfn1(fn))(qenv(fn), v22);
    }
}



/* Code for smember */

static Lisp_Object CC_smember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v51;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smember");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */

v49:
    v51 = stack[-1];
    v68 = stack[0];
    if (equal(v51, v68)) goto v4;
    v68 = stack[0];
    if (!consp(v68)) goto v26;
    v51 = stack[-1];
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = CC_smember(env, v51, v68);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (!(v68 == nil)) { popv(3); return onevalue(v68); }
    v51 = stack[-1];
    v68 = stack[0];
    v68 = qcdr(v68);
    stack[-1] = v51;
    stack[0] = v68;
    goto v49;

v26:
    v68 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v68); }

v4:
    v68 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v68); }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for convprec */

static Lisp_Object CC_convprec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convprec");
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
    v4 = v0;
/* end of prologue */
    fn = elt(env, 1); /* round!* */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* convchk */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v22:
    popv(1);
    return nil;
}



/* Code for quotf */

static Lisp_Object CC_quotf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v23, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v23 = v10;
    v26 = v0;
/* end of prologue */
    v2 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = v2; /* !*exp */
    v2 = v26;
    fn = elt(env, 3); /* quotf1 */
    v2 = (*qfn2(fn))(qenv(fn), v2, v23);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    { popv(2); return onevalue(v2); }
/* error exit handlers */
v28:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    popv(2);
    return nil;
}



/* Code for physopp */

static Lisp_Object CC_physopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopp");
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
    v81 = v0;
/* end of prologue */
    v42 = v81;
    if (!consp(v42)) goto v3;
    v42 = v81;
    v42 = qcar(v42);
    if (symbolp(v42)) goto v19;
    v42 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v42); }

v19:
    v42 = v81;
    v81 = qcar(v42);
    v42 = elt(env, 2); /* rtype */
    v42 = get(v81, v42);
    env = stack[0];
    v81 = elt(env, 3); /* physop */
    v42 = (v42 == v81 ? lisp_true : nil);
    { popv(1); return onevalue(v42); }

v3:
    v42 = v81;
    if (symbolp(v42)) goto v46;
    v42 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v42); }

v46:
    v42 = elt(env, 2); /* rtype */
    v42 = get(v81, v42);
    env = stack[0];
    v81 = elt(env, 3); /* physop */
    v42 = (v42 == v81 ? lisp_true : nil);
    { popv(1); return onevalue(v42); }
}



/* Code for memq_edgelist */

static Lisp_Object CC_memq_edgelist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for memq_edgelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v10;
    v2 = v0;
/* end of prologue */
    v2 = qcar(v2);
    v1 = Lassoc(nil, v2, v1);
    return onevalue(v1);
}



/* Code for !*n2f */

static Lisp_Object CC_Hn2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *n2f");
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
    v2 = (Lisp_Object)zerop(v2);
    v2 = v2 ? lisp_true : nil;
    env = stack[0];
    if (v2 == nil) { popv(1); return onevalue(v1); }
    v1 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v1); }
}



/* Code for c_zero */

static Lisp_Object MS_CDECL CC_c_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v34;
    argcheck(nargs, 0, "c_zero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c_zero");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v34 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v34);
}



/* Code for sieve_pv0 */

static Lisp_Object MS_CDECL CC_sieve_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v10,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sieve_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sieve_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v10,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v34;
    stack[-1] = v10;
    stack[-2] = v0;
/* end of prologue */
    v65 = stack[-2];
    if (!(v65 == nil)) goto v23;
    v65 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v65); }

v23:
    v65 = stack[-1];
    if (v65 == nil) goto v57;
    v65 = stack[-1];
    v65 = qcar(v65);
    v65 = qcar(v65);
    v61 = qcdr(v65);
    v65 = stack[-2];
    v65 = qcar(v65);
    v65 = qcdr(v65);
    v65 = (Lisp_Object)greaterp2(v61, v65);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v65 = v65 ? lisp_true : nil;
    env = stack[-3];
    if (v65 == nil) goto v57;
    v65 = stack[-1];
    v65 = qcdr(v65);
    stack[-1] = v65;
    goto v23;

v57:
    v65 = stack[-2];
    if (v65 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v65 = stack[-1];
    if (v65 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v62 = stack[-2];
    v65 = stack[-1];
    v61 = qcar(v65);
    v65 = stack[0];
    fn = elt(env, 2); /* reduce_pv0 */
    v65 = (*qfnn(fn))(qenv(fn), 3, v62, v61, v65);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    stack[-2] = v65;
    v65 = stack[-1];
    v65 = qcdr(v65);
    stack[-1] = v65;
    goto v57;
/* error exit handlers */
v74:
    popv(4);
    return nil;
}



/* Code for listp */

static Lisp_Object CC_listp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v0;
/* end of prologue */

v45:
    v15 = v29;
    v15 = (v15 == nil ? lisp_true : nil);
    if (!(v15 == nil)) return onevalue(v15);
    v15 = v29;
    if (!consp(v15)) goto v6;
    v29 = qcdr(v29);
    goto v45;

v6:
    v29 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v29);
}



/* Code for quotelist */

static Lisp_Object CC_quotelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v9 = elt(env, 1); /* list */
    return onevalue(v9);
}



/* Code for revpr */

static Lisp_Object CC_revpr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revpr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v2 = v1;
    v2 = qcdr(v2);
    v1 = qcar(v1);
    return cons(v2, v1);
}



/* Code for pnth */

static Lisp_Object CC_pnth(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v11, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnth");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v11 = v10;
    stack[0] = v0;
/* end of prologue */

v4:
    v82 = stack[0];
    if (v82 == nil) goto v1;
    v57 = v11;
    v82 = (Lisp_Object)17; /* 1 */
    if (v57 == v82) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v82 = stack[0];
    v82 = qcdr(v82);
    stack[0] = v82;
    v82 = v11;
    v82 = sub1(v82);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    v11 = v82;
    goto v4;

v1:
    v57 = elt(env, 1); /* alg */
    v11 = (Lisp_Object)97; /* 6 */
    v82 = elt(env, 2); /* "Index out of range" */
    {
        popv(2);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v57, v11, v82);
    }
/* error exit handlers */
v68:
    popv(2);
    return nil;
}



/* Code for degr */

static Lisp_Object CC_degr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v25, v35;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v48 = v10;
    v25 = v0;
/* end of prologue */
    v35 = v25;
    if (!consp(v35)) goto v4;
    v35 = v25;
    v35 = qcar(v35);
    if (!consp(v35)) goto v4;
    v35 = v25;
    v35 = qcar(v35);
    v35 = qcar(v35);
    v35 = qcar(v35);
    if (!(v35 == v48)) goto v4;
    v48 = v25;
    v48 = qcar(v48);
    v48 = qcar(v48);
    v48 = qcdr(v48);
    return onevalue(v48);

v4:
    v48 = (Lisp_Object)1; /* 0 */
    return onevalue(v48);
}



/* Code for ibalp_commonlenisone */

static Lisp_Object CC_ibalp_commonlenisone(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_commonlenisone");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v32 = stack[-1];
    if (v32 == nil) goto v1;
    v32 = qvalue(elt(env, 1)); /* nil */
    goto v49;

v49:
    if (!(v32 == nil)) { popv(3); return onevalue(v32); }
    v32 = stack[0];
    if (v32 == nil) goto v30;
    v32 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v32); }

v30:
    v32 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* ibalp_lenisone */
        return (*qfn1(fn))(qenv(fn), v32);
    }

v1:
    v32 = stack[0];
    fn = elt(env, 2); /* ibalp_lenisone */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    goto v49;
/* error exit handlers */
v47:
    popv(3);
    return nil;
}



/* Code for find2 */

static Lisp_Object CC_find2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v19, v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v10;
    v19 = v0;
/* end of prologue */

v6:
    v20 = v18;
    v17 = nil;
    if (v20 == v17) goto v49;
    v17 = v18;
    v17 = qcar(v17);
    v19 = Lmember(nil, v17, v19);
    v17 = v18;
    v17 = qcdr(v17);
    v18 = v17;
    goto v6;

v49:
    v17 = v19;
    if (v17 == nil) goto v46;
    v17 = v19;
    v17 = qcdr(v17);
    return onevalue(v17);

v46:
    v17 = elt(env, 1); /* (stop) */
    return onevalue(v17);
}



/* Code for zero2nil */

static Lisp_Object CC_zero2nil(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero2nil");
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
    v1 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    if (v1 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v1 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v1); }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for binding */

static Lisp_Object CC_binding(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binding");
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
    v29 = v0;
/* end of prologue */
    v15 = v29;
    v29 = elt(env, 0); /* binding */
    v29 = get(v15, v29);
    v15 = v29;
    v29 = v15;
    if (v29 == nil) goto v23;
    v29 = v15;
    v29 = qcar(v29);
    return onevalue(v29);

v23:
    v29 = nil;
    return onevalue(v29);
}



/* Code for prepf */

static Lisp_Object CC_prepf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepf");
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
    v24 = v0;
/* end of prologue */
    v30 = v24;
    v24 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1 */
    v24 = (*qfn2(fn))(qenv(fn), v30, v24);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[0];
    v30 = v24;
    v24 = v30;
    if (v24 == nil) goto v2;
    v24 = v30;
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v24);
    }

v2:
    v24 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v24); }
/* error exit handlers */
v46:
    popv(1);
    return nil;
}



/* Code for vevmtest!? */

static Lisp_Object CC_vevmtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v58, v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevmtest?");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v58 = v10;
    v59 = v0;
/* end of prologue */

v4:
    v56 = v58;
    if (v56 == nil) goto v5;
    v56 = v59;
    if (v56 == nil) goto v1;
    v56 = v59;
    v60 = qcar(v56);
    v56 = v58;
    v56 = qcar(v56);
    if (((int32_t)(v60)) < ((int32_t)(v56))) goto v81;
    v56 = v59;
    v56 = qcdr(v56);
    v59 = v56;
    v56 = v58;
    v56 = qcdr(v56);
    v58 = v56;
    goto v4;

v81:
    v56 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v56); }

v1:
    v56 = v58;
    if (v56 == nil) goto v28;
    v56 = v58;
    v59 = qcar(v56);
    v56 = (Lisp_Object)1; /* 0 */
    if (!(v59 == v56)) goto v39;
    v56 = v58;
    v56 = qcdr(v56);
    fn = elt(env, 3); /* vevzero!?1 */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[0];
    if (!(v56 == nil)) goto v28;

v39:
    v56 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v56); }

v28:
    v56 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v56); }

v5:
    v56 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v56); }
/* error exit handlers */
v64:
    popv(1);
    return nil;
}



/* Code for vbcsize */

static Lisp_Object CC_vbcsize(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcsize");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v21 = v10;
    stack[0] = v0;
/* end of prologue */

v49:
    v38 = v21;
    v20 = (Lisp_Object)-15; /* -1 */
    if (((int32_t)(v38)) > ((int32_t)(v20))) goto v4;
    v20 = stack[0];
    if (!consp(v20)) { popv(2); return onevalue(v21); }
    v20 = stack[0];
    v20 = qcar(v20);
    v21 = (Lisp_Object)((int32_t)(v21) + 0x10);
    v20 = CC_vbcsize(env, v20, v21);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v21 = v20;
    v20 = v21;
    if (v20 == nil) goto v44;
    v20 = stack[0];
    v20 = qcdr(v20);
    stack[0] = v20;
    goto v49;

v44:
    v20 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v20); }

v4:
    v20 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v20); }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for ordpp */

static Lisp_Object CC_ordpp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v67, v83, v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordpp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v83 = v10;
    v84 = v0;
/* end of prologue */
    v74 = v84;
    v67 = qcar(v74);
    v74 = v83;
    v74 = qcar(v74);
    if (v67 == v74) goto v24;
    v74 = qvalue(elt(env, 1)); /* kord!* */
    v85 = v74;
    v74 = v84;
    v74 = qcar(v74);
    v84 = v74;
    v74 = v83;
    v74 = qcar(v74);
    v83 = v74;
    goto v22;

v22:
    v74 = v85;
    if (v74 == nil) goto v12;
    v67 = v84;
    v74 = v85;
    v74 = qcar(v74);
    if (v67 == v74) goto v20;
    v67 = v83;
    v74 = v85;
    v74 = qcar(v74);
    if (v67 == v74) goto v86;
    v74 = v85;
    v74 = qcdr(v74);
    v85 = v74;
    goto v22;

v86:
    v74 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v74);

v20:
    v74 = qvalue(elt(env, 2)); /* t */
    return onevalue(v74);

v12:
    v74 = v84;
    v67 = v83;
    {
        fn = elt(env, 4); /* ordpa */
        return (*qfn2(fn))(qenv(fn), v74, v67);
    }

v24:
    v74 = v84;
    v74 = qcdr(v74);
    v67 = v83;
    v67 = qcdr(v67);
        return Lgreaterp(nil, v74, v67);
}



/* Code for wedgefax */

static Lisp_Object CC_wedgefax(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v24, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgefax");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v0;
/* end of prologue */
    v16 = v24;
    v30 = elt(env, 1); /* wedge */
    if (!consp(v16)) goto v27;
    v16 = qcar(v16);
    if (!(v16 == v30)) goto v27;
    v16 = v24;
    v16 = qcdr(v16);
    return onevalue(v16);

v27:
    v16 = v24;
    return ncons(v16);
}



/* Code for times!: */

static Lisp_Object CC_timesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times:");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = elt(env, 1); /* !:rd!: */
    v39 = stack[-2];
    v39 = qcdr(v39);
    v37 = qcar(v39);
    v39 = stack[-1];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    stack[0] = times2(v37, v39);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v39 = stack[-2];
    v39 = qcdr(v39);
    v37 = qcdr(v39);
    v39 = stack[-1];
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    v39 = plus2(v37, v39);
    nil = C_nil;
    if (exception_pending()) goto v68;
    {
        Lisp_Object v51 = stack[-3];
        Lisp_Object v52 = stack[0];
        popv(5);
        return list2star(v51, v52, v39);
    }
/* error exit handlers */
v68:
    popv(5);
    return nil;
}



/* Code for round!* */

static Lisp_Object CC_roundH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for round*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v23 = v2;
    v23 = qcdr(v23);
    if (!(!consp(v23))) return onevalue(v2);
    v2 = qcdr(v2);
    return onevalue(v2);
}



/* Code for noncomp2 */

static Lisp_Object CC_noncomp2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v0;
/* end of prologue */
    v15 = v16;
    if (!consp(v15)) goto v3;
    v15 = v16;
    v16 = elt(env, 1); /* noncom */
        return Lflagpcar(nil, v15, v16);

v3:
    v15 = v16;
    if (!symbolp(v15)) v15 = nil;
    else { v15 = qfastgets(v15);
           if (v15 != nil) { v15 = elt(v15, 0); /* noncom */
#ifdef RECORD_GET
             if (v15 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v15 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v15 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v15 == SPID_NOPROP) v15 = nil; else v15 = lisp_true; }}
#endif
    return onevalue(v15);
}



/* Code for union_edge */

static Lisp_Object CC_union_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for union_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v33 = stack[-1];
    v32 = stack[0];
    fn = elt(env, 1); /* memq_edgelist */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v14;
    if (!(v32 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v33 = stack[-1];
    v32 = stack[0];
    popv(2);
    return cons(v33, v32);
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for termsf */

static Lisp_Object CC_termsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v51;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termsf");
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
    v68 = (Lisp_Object)1; /* 0 */
    v51 = v68;
    goto v5;

v5:
    v68 = stack[0];
    if (!consp(v68)) goto v49;
    v68 = stack[0];
    v68 = qcar(v68);
    if (!consp(v68)) goto v49;
    stack[-1] = v51;
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    v68 = CC_termsf(env, v68);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v68 = plus2(stack[-1], v68);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v51 = v68;
    v68 = stack[0];
    v68 = qcdr(v68);
    stack[0] = v68;
    goto v5;

v49:
    v68 = stack[0];
    if (v68 == nil) { popv(3); return onevalue(v51); }
    v68 = v51;
    popv(3);
    return add1(v68);
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for readch1 */

static Lisp_Object MS_CDECL CC_readch1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "readch1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for readch1");
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
    fn = elt(env, 6); /* terminalp */
    v20 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    if (v20 == nil) goto v22;
    v20 = qvalue(elt(env, 4)); /* crbuf1!* */
    if (v20 == nil) goto v39;
    v20 = qvalue(elt(env, 4)); /* crbuf1!* */
    v20 = qcar(v20);
    stack[0] = v20;
    v20 = qvalue(elt(env, 4)); /* crbuf1!* */
    v20 = qcdr(v20);
    qvalue(elt(env, 4)) = v20; /* crbuf1!* */
    goto v57;

v57:
    v21 = stack[0];
    v20 = qvalue(elt(env, 5)); /* crbuf!* */
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    qvalue(elt(env, 5)) = v20; /* crbuf!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v39:
    v20 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    stack[0] = v20;
    goto v57;

v22:
    v20 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    stack[0] = v20;
    v21 = stack[0];
    v20 = qvalue(elt(env, 1)); /* !$eol!$ */
    if (!(v21 == v20)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v20 = qvalue(elt(env, 3)); /* curline!* */
    v20 = add1(v20);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    qvalue(elt(env, 3)) = v20; /* curline!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v73:
    popv(2);
    return nil;
}



/* Code for mkspm */

static Lisp_Object CC_mkspm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkspm");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v42 = stack[0];
    v41 = (Lisp_Object)1; /* 0 */
    if (v42 == v41) goto v4;
    v41 = qvalue(elt(env, 1)); /* subfg!* */
    if (v41 == nil) goto v24;
    v42 = stack[-1];
    v41 = qvalue(elt(env, 2)); /* asymplis!* */
    v41 = Latsoc(nil, v42, v41);
    v42 = v41;
    if (v41 == nil) goto v24;
    v41 = v42;
    v42 = qcdr(v41);
    v41 = stack[0];
    v41 = (Lisp_Object)lesseq2(v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v41 = v41 ? lisp_true : nil;
    env = stack[-2];
    if (v41 == nil) goto v24;
    v41 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v41); }

v24:
    v41 = stack[-1];
    fn = elt(env, 4); /* sub2chk */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    v42 = stack[-1];
    v41 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* to */
        return (*qfn2(fn))(qenv(fn), v42, v41);
    }

v4:
    v41 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v41); }
/* error exit handlers */
v43:
    popv(3);
    return nil;
}



/* Code for mo_divides!? */

static Lisp_Object CC_mo_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v10;
    v23 = v0;
/* end of prologue */
    v23 = qcar(v23);
    v2 = qcar(v2);
    {
        fn = elt(env, 1); /* mo!=modiv1 */
        return (*qfn2(fn))(qenv(fn), v23, v2);
    }
}



/* Code for mchk!* */

static Lisp_Object CC_mchkH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchk*");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v52 = stack[-1];
    v51 = stack[0];
    fn = elt(env, 3); /* mchk */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v52 = v51;
    if (!(v51 == nil)) { popv(3); return onevalue(v52); }
    v51 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v51 == nil)) goto v15;
    v51 = stack[-1];
    fn = elt(env, 4); /* sfp */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    if (v51 == nil) goto v15;
    v51 = stack[0];
    fn = elt(env, 4); /* sfp */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    if (v51 == nil) goto v15;
    v51 = stack[-1];
    fn = elt(env, 5); /* prepf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v51 = stack[0];
    fn = elt(env, 5); /* prepf */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    {
        Lisp_Object v20 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* mchk */
        return (*qfn2(fn))(qenv(fn), v20, v51);
    }

v15:
    v51 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for dlesslex */

static Lisp_Object CC_dlesslex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v51, v52, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dlesslex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v10;
    v52 = v0;
/* end of prologue */

v4:
    v68 = v52;
    if (v68 == nil) goto v5;
    v68 = v52;
    v17 = qcar(v68);
    v68 = v51;
    v68 = qcar(v68);
    if (((int32_t)(v17)) > ((int32_t)(v68))) goto v1;
    v68 = v52;
    v17 = qcar(v68);
    v68 = v51;
    v68 = qcar(v68);
    if (((int32_t)(v17)) < ((int32_t)(v68))) goto v50;
    v68 = v52;
    v68 = qcdr(v68);
    v52 = v68;
    v68 = v51;
    v68 = qcdr(v68);
    v51 = v68;
    goto v4;

v50:
    v68 = qvalue(elt(env, 2)); /* t */
    return onevalue(v68);

v1:
    v68 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v68);

v5:
    v68 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v68);
}



/* Code for pappl */

static Lisp_Object CC_pappl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v10;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v43 = stack[-3];
    fn = elt(env, 2); /* unpkp */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    stack[-3] = v43;
    goto v2;

v2:
    v43 = stack[-3];
    if (v43 == nil) goto v1;
    v43 = stack[-2];
    stack[-1] = v43;
    v43 = (Lisp_Object)17; /* 1 */
    stack[0] = v43;
    goto v25;

v25:
    v43 = stack[-3];
    v43 = qcar(v43);
    v56 = sub1(v43);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    v43 = stack[0];
    v43 = difference2(v56, v43);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    v43 = Lminusp(nil, v43);
    env = stack[-5];
    if (v43 == nil) goto v33;
    v43 = stack[-1];
    v56 = qcar(v43);
    v43 = stack[-4];
    v43 = cons(v56, v43);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    stack[-4] = v43;
    v43 = stack[-3];
    v43 = qcdr(v43);
    stack[-3] = v43;
    goto v2;

v33:
    v43 = stack[-1];
    v43 = qcdr(v43);
    stack[-1] = v43;
    v43 = stack[0];
    v43 = add1(v43);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    stack[0] = v43;
    goto v25;

v1:
    v43 = stack[-4];
        popv(6);
        return Lnreverse(nil, v43);
/* error exit handlers */
v61:
    popv(6);
    return nil;
}



/* Code for adjoin!-term */

static Lisp_Object MS_CDECL CC_adjoinKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v10,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v50, v31, v32;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adjoin-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adjoin-term");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v34;
    v50 = v10;
    v31 = v0;
/* end of prologue */
    v32 = v50;
    if (v32 == nil) return onevalue(v46);
    return acons(v31, v50, v46);
}



/* Code for modzerop!: */

static Lisp_Object CC_modzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v1 = qcdr(v8);
    v8 = (Lisp_Object)1; /* 0 */
    v8 = (v1 == v8 ? lisp_true : nil);
    return onevalue(v8);
}



/* Code for reorder */

static Lisp_Object CC_reorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reorder");
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
    goto v22;

v22:
    v81 = stack[-1];
    if (!consp(v81)) goto v49;
    v81 = stack[-1];
    v81 = qcar(v81);
    if (!consp(v81)) goto v49;
    v81 = stack[-1];
    v81 = qcar(v81);
    stack[0] = qcar(v81);
    v81 = stack[-1];
    v81 = qcar(v81);
    v81 = qcdr(v81);
    v81 = CC_reorder(env, v81);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    fn = elt(env, 1); /* rmultpf */
    v86 = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    v81 = stack[-2];
    v81 = cons(v86, v81);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    stack[-2] = v81;
    v81 = stack[-1];
    v81 = qcdr(v81);
    stack[-1] = v81;
    goto v22;

v49:
    v81 = stack[-1];
    v86 = v81;
    goto v5;

v5:
    v81 = stack[-2];
    if (v81 == nil) { popv(4); return onevalue(v86); }
    v81 = stack[-2];
    v81 = qcar(v81);
    fn = elt(env, 2); /* raddf */
    v81 = (*qfn2(fn))(qenv(fn), v81, v86);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    v86 = v81;
    v81 = stack[-2];
    v81 = qcdr(v81);
    stack[-2] = v81;
    goto v5;
/* error exit handlers */
v59:
    popv(4);
    return nil;
}



/* Code for noncomp1 */

static Lisp_Object CC_noncomp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v11, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp1");
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
    v82 = v11;
    v82 = Lconsp(nil, v82);
    env = stack[0];
    if (v82 == nil) goto v3;
    v82 = v11;
    v82 = qcar(v82);
    v82 = Lconsp(nil, v82);
    env = stack[0];
    if (v82 == nil) goto v29;
    v82 = v11;
    {
        popv(1);
        fn = elt(env, 3); /* noncomfp */
        return (*qfn1(fn))(qenv(fn), v82);
    }

v29:
    v82 = v11;
    v57 = qcar(v82);
    v82 = elt(env, 2); /* taylor!* */
    if (v57 == v82) goto v27;
    v82 = v11;
    v82 = qcar(v82);
    if (!symbolp(v82)) v82 = nil;
    else { v82 = qfastgets(v82);
           if (v82 != nil) { v82 = elt(v82, 0); /* noncom */
#ifdef RECORD_GET
             if (v82 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v82 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v82 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v82 == SPID_NOPROP) v82 = nil; else v82 = lisp_true; }}
#endif
    if (!(v82 == nil)) { popv(1); return onevalue(v82); }
    v82 = v11;
    v82 = qcdr(v82);
    {
        popv(1);
        fn = elt(env, 4); /* noncomlistp */
        return (*qfn1(fn))(qenv(fn), v82);
    }

v27:
    v82 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v82); }

v3:
    v82 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v82); }
}



/* Code for subs3f */

static Lisp_Object CC_subs3f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v23, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3f");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v26 = v2;
    v23 = qvalue(elt(env, 1)); /* !*match */
    v2 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* subs3f1 */
        return (*qfnn(fn))(qenv(fn), 3, v26, v23, v2);
    }
}



/* Code for tayexp!-lessp */

static Lisp_Object CC_tayexpKlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v48, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-lessp");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v48 = v10;
    v25 = v0;
/* end of prologue */
    v14 = v25;
    if (!(!consp(v14))) goto v46;
    v14 = v48;
    if (!(!consp(v14))) goto v46;
    v14 = v25;
        popv(1);
        return Llessp(nil, v14, v48);

v46:
    v14 = v25;
    fn = elt(env, 1); /* tayexp!-difference */
    v14 = (*qfn2(fn))(qenv(fn), v14, v48);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !:minusp */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v35:
    popv(1);
    return nil;
}



/* Code for get!+mat!+entry */

static Lisp_Object MS_CDECL CC_getLmatLentry(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v10,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "get+mat+entry");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+mat+entry");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v10,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v34;
    v24 = v10;
    v30 = v0;
/* end of prologue */
    fn = elt(env, 1); /* nth */
    v30 = (*qfn2(fn))(qenv(fn), v30, v24);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v24 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v30, v24);
    }
/* error exit handlers */
v50:
    popv(2);
    return nil;
}



/* Code for butes */

static Lisp_Object CC_butes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v51, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for butes");
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
    v52 = v0;
/* end of prologue */
    v68 = v52;
    v68 = qcar(v68);
    qvalue(elt(env, 1)) = v68; /* cha */
    v51 = qvalue(elt(env, 1)); /* cha */
    v68 = elt(env, 2); /* !  */
    if (v51 == v68) goto v6;
    v51 = qvalue(elt(env, 1)); /* cha */
    v68 = elt(env, 3); /* !$ */
    if (v51 == v68) goto v6;
    v68 = v52;
    stack[0] = qcar(v68);
    v68 = v52;
    v68 = qcdr(v68);
    v68 = CC_butes(env, v68);
    nil = C_nil;
    if (exception_pending()) goto v18;
    {
        Lisp_Object v19 = stack[0];
        popv(1);
        return cons(v19, v68);
    }

v6:
    v68 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v68); }
/* error exit handlers */
v18:
    popv(1);
    return nil;
}



/* Code for noncomfp1 */

static Lisp_Object CC_noncomfp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomfp1");
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

v45:
    v14 = stack[0];
    if (!consp(v14)) goto v3;
    v14 = stack[0];
    v14 = qcar(v14);
    if (!consp(v14)) goto v3;
    v14 = stack[0];
    v14 = qcar(v14);
    v14 = qcar(v14);
    v14 = qcar(v14);
    fn = elt(env, 2); /* noncomp */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    if (!(v14 == nil)) { popv(2); return onevalue(v14); }
    v14 = stack[0];
    v14 = qcar(v14);
    v14 = qcdr(v14);
    v14 = CC_noncomfp1(env, v14);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    if (!(v14 == nil)) { popv(2); return onevalue(v14); }
    v14 = stack[0];
    v14 = qcdr(v14);
    stack[0] = v14;
    goto v45;

v3:
    v14 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v14); }
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for scprint */

static Lisp_Object CC_scprint(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scprint");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v10;
    v62 = v0;
/* end of prologue */
    v61 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v61; /* posn!* */
    v61 = v62;
    stack[-1] = v61;
    goto v7;

v7:
    v61 = stack[-1];
    if (v61 == nil) goto v6;
    v61 = stack[-1];
    v61 = qcar(v61);
    stack[0] = v61;
    v61 = stack[0];
    v61 = qcar(v61);
    v62 = qcdr(v61);
    v61 = stack[-2];
    if (!(equal(v62, v61))) goto v30;
    v61 = stack[0];
    v61 = qcar(v61);
    v61 = qcar(v61);
    v62 = qcar(v61);
    v61 = qvalue(elt(env, 1)); /* posn!* */
    v62 = difference2(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-4];
    stack[-3] = v62;
    v61 = (Lisp_Object)1; /* 0 */
    v61 = (Lisp_Object)lessp2(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v61 = v61 ? lisp_true : nil;
    env = stack[-4];
    if (!(v61 == nil)) goto v44;
    v61 = stack[-3];
    v61 = Lxtab(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-4];
    goto v44;

v44:
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = Lprinc(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-4];
    v61 = stack[0];
    v61 = qcar(v61);
    v61 = qcar(v61);
    v61 = qcdr(v61);
    qvalue(elt(env, 1)) = v61; /* posn!* */
    goto v30;

v30:
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    goto v7;

v6:
    v61 = nil;
    { popv(5); return onevalue(v61); }
/* error exit handlers */
v67:
    popv(5);
    return nil;
}



/* Code for ldepends */

static Lisp_Object CC_ldepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */

v45:
    v51 = stack[-1];
    if (v51 == nil) goto v4;
    v51 = stack[-1];
    if (!consp(v51)) goto v2;
    v51 = stack[-1];
    v52 = qcar(v51);
    v51 = stack[0];
    fn = elt(env, 2); /* depends */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    if (!(v51 == nil)) { popv(3); return onevalue(v51); }
    v51 = stack[-1];
    v52 = qcdr(v51);
    v51 = stack[0];
    stack[-1] = v52;
    stack[0] = v51;
    goto v45;

v2:
    v52 = stack[-1];
    v51 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* depends */
        return (*qfn2(fn))(qenv(fn), v52, v51);
    }

v4:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for numlis */

static Lisp_Object CC_numlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlis");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */

v45:
    v16 = v15;
    v16 = (v16 == nil ? lisp_true : nil);
    if (!(v16 == nil)) return onevalue(v16);
    v16 = v15;
    v16 = qcar(v16);
    if (is_number(v16)) goto v23;
    v15 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v15);

v23:
    v15 = qcdr(v15);
    goto v45;
}



/* Code for !:minusp */

static Lisp_Object CC_Tminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v13, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :minusp");
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
    v47 = v0;
/* end of prologue */
    v33 = v47;
    if (!consp(v33)) goto v3;
    v33 = v47;
    v13 = qcar(v33);
    v33 = elt(env, 1); /* minusp */
    v33 = get(v13, v33);
    v13 = v47;
        return Lapply1(nil, v33, v13);

v3:
    v33 = v47;
        return Lminusp(nil, v33);
}



/* Code for pm!:free */

static Lisp_Object CC_pmTfree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:free");
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
    v8 = v0;
/* end of prologue */
    fn = elt(env, 2); /* binding */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[0];
    v1 = elt(env, 1); /* unbound */
    v8 = (v8 == v1 ? lisp_true : nil);
    { popv(1); return onevalue(v8); }
/* error exit handlers */
v2:
    popv(1);
    return nil;
}



/* Code for prepf1 */

static Lisp_Object CC_prepf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v90 = stack[-1];
    if (v90 == nil) goto v4;
    v90 = stack[-1];
    if (!consp(v90)) goto v15;
    v90 = stack[-1];
    v90 = qcar(v90);
    if (!consp(v90)) goto v15;
    v90 = stack[-1];
    v90 = qcar(v90);
    stack[-2] = qcdr(v90);
    v90 = stack[-1];
    v90 = qcar(v90);
    v90 = qcar(v90);
    v91 = qcar(v90);
    v90 = elt(env, 2); /* k!* */
    if (v91 == v90) goto v19;
    v90 = stack[-1];
    v90 = qcar(v90);
    v91 = qcar(v90);
    v90 = stack[0];
    v90 = cons(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    goto v57;

v57:
    stack[-2] = CC_prepf1(env, stack[-2], v90);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v90 = stack[-1];
    v91 = qcdr(v90);
    v90 = stack[0];
    v90 = CC_prepf1(env, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    {
        Lisp_Object v70 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nconc!* */
        return (*qfn2(fn))(qenv(fn), v70, v90);
    }

v19:
    v90 = stack[0];
    goto v57;

v15:
    v90 = stack[-1];
    fn = elt(env, 4); /* prepd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v90 = stack[0];
    fn = elt(env, 5); /* exchk */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v90 = cons(stack[-1], v90);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    fn = elt(env, 6); /* retimes */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v69;
    popv(4);
    return ncons(v90);

v4:
    v90 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v90); }
/* error exit handlers */
v69:
    popv(4);
    return nil;
}



/* Code for !*d2q */

static Lisp_Object CC_Hd2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *d2q");
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
    v54 = stack[0];
    if (is_number(v54)) goto v3;
    v54 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    if (v54 == nil) goto v18;
    v55 = qvalue(elt(env, 1)); /* nil */
    v54 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v55, v54);

v18:
    v55 = stack[0];
    v54 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v55, v54);

v3:
    v54 = stack[0];
    v54 = (Lisp_Object)zerop(v54);
    v54 = v54 ? lisp_true : nil;
    env = stack[-1];
    if (v54 == nil) goto v50;
    v55 = qvalue(elt(env, 1)); /* nil */
    v54 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v55, v54);

v50:
    v55 = stack[0];
    v54 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v55, v54);
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for buchvevdivides!? */

static Lisp_Object CC_buchvevdividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v44, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for buchvevdivides?");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v44 = stack[0];
    v36 = stack[-1];
    fn = elt(env, 3); /* vevmtest!? */
    v36 = (*qfn2(fn))(qenv(fn), v44, v36);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    if (v36 == nil) goto v4;
    v36 = qvalue(elt(env, 2)); /* gmodule!* */
    v36 = (v36 == nil ? lisp_true : nil);
    if (!(v36 == nil)) { popv(3); return onevalue(v36); }
    v39 = stack[-1];
    v44 = stack[0];
    v36 = qvalue(elt(env, 2)); /* gmodule!* */
    {
        popv(3);
        fn = elt(env, 4); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v39, v44, v36);
    }

v4:
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v36); }
/* error exit handlers */
v11:
    popv(3);
    return nil;
}



/* Code for expchk */

static Lisp_Object CC_expchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expchk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v1 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v1 == nil)) return onevalue(v2);
    v1 = v2;
    {
        fn = elt(env, 2); /* offexpchk */
        return (*qfn1(fn))(qenv(fn), v1);
    }
}



/* Code for csl_normbf */

static Lisp_Object CC_csl_normbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v80, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csl_normbf");
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
    stack[-3] = nil;
    v85 = stack[-2];
    v85 = qcdr(v85);
    v80 = qcar(v85);
    stack[0] = v80;
    v85 = (Lisp_Object)1; /* 0 */
    if (v80 == v85) goto v7;
    v80 = stack[0];
    v85 = (Lisp_Object)1; /* 0 */
    v85 = (Lisp_Object)lessp2(v80, v85);
    nil = C_nil;
    if (exception_pending()) goto v93;
    v85 = v85 ? lisp_true : nil;
    env = stack[-4];
    if (v85 == nil) goto v46;
    v85 = stack[0];
    v85 = negate(v85);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[0] = v85;
    v85 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v85;
    goto v46;

v46:
    v85 = stack[0];
    fn = elt(env, 4); /* lsd */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-1] = v85;
    v85 = stack[-1];
    v85 = negate(v85);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    v85 = ash(stack[0], v85);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[0] = v85;
    v85 = stack[-3];
    if (v85 == nil) goto v41;
    v85 = stack[0];
    v85 = negate(v85);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[0] = v85;
    goto v41;

v41:
    v80 = stack[-1];
    v85 = stack[-2];
    v85 = qcdr(v85);
    v85 = qcdr(v85);
    v85 = plus2(v80, v85);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-1] = v85;
    v92 = elt(env, 3); /* !:rd!: */
    v80 = stack[0];
    v85 = stack[-1];
    popv(5);
    return list2star(v92, v80, v85);

v7:
    v85 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(5); return onevalue(v85); }
/* error exit handlers */
v93:
    popv(5);
    return nil;
}



/* Code for mkround */

static Lisp_Object CC_mkround(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkround");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v29 = v15;
    if (!(!consp(v29))) return onevalue(v15);
    v29 = elt(env, 1); /* !:rd!: */
    return cons(v29, v15);
}



/* Code for argsofopr */

static Lisp_Object CC_argsofopr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for argsofopr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* number!-of!-args */
    return get(v7, v8);
}



/* Code for multf */

static Lisp_Object CC_multf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v143, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multf");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v49;

v49:
    v142 = stack[-2];
    if (v142 == nil) goto v7;
    v142 = stack[-1];
    if (v142 == nil) goto v7;
    v143 = stack[-2];
    v142 = (Lisp_Object)17; /* 1 */
    if (v143 == v142) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v143 = stack[-1];
    v142 = (Lisp_Object)17; /* 1 */
    if (v143 == v142) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v142 = stack[-2];
    if (!consp(v142)) goto v17;
    v142 = stack[-2];
    v142 = qcar(v142);
    if (!consp(v142)) goto v17;
    v142 = stack[-1];
    if (!consp(v142)) goto v43;
    v142 = stack[-1];
    v142 = qcar(v142);
    if (!consp(v142)) goto v43;
    v142 = qvalue(elt(env, 2)); /* !*exp */
    if (!(v142 == nil)) goto v6;
    v142 = qvalue(elt(env, 3)); /* ncmp!* */
    if (!(v142 == nil)) goto v6;
    v142 = qvalue(elt(env, 4)); /* wtl!* */
    if (!(v142 == nil)) goto v6;
    v142 = stack[-3];
    if (!(v142 == nil)) goto v6;
    v142 = stack[-2];
    fn = elt(env, 10); /* mkprod */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-2] = v142;
    v142 = stack[-1];
    fn = elt(env, 10); /* mkprod */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-1] = v142;
    v142 = qvalue(elt(env, 5)); /* t */
    stack[-3] = v142;
    goto v49;

v6:
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = qcar(v142);
    stack[-3] = v142;
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = qcar(v142);
    stack[0] = v142;
    v142 = stack[-1];
    fn = elt(env, 11); /* noncomfp */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    if (v142 == nil) goto v146;
    v142 = stack[-3];
    fn = elt(env, 12); /* noncomp */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    if (!(v142 == nil)) goto v147;
    v142 = qvalue(elt(env, 6)); /* !*!*processed */
    if (!(v142 == nil)) goto v146;

v147:
    v143 = stack[-2];
    v142 = stack[-1];
    {
        popv(5);
        fn = elt(env, 13); /* multfnc */
        return (*qfn2(fn))(qenv(fn), v143, v142);
    }

v146:
    v143 = stack[-3];
    v142 = stack[0];
    if (v143 == v142) goto v148;
    v143 = stack[-3];
    v142 = stack[0];
    fn = elt(env, 14); /* ordop */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    if (v142 == nil) goto v149;
    v142 = stack[-2];
    v142 = qcar(v142);
    v143 = qcdr(v142);
    v142 = stack[-1];
    v142 = CC_multf(env, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-3] = v142;
    v142 = stack[-2];
    v143 = qcdr(v142);
    v142 = stack[-1];
    v142 = CC_multf(env, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    stack[0] = v142;
    v142 = stack[-3];
    if (v142 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v142 = stack[-2];
    v142 = qcar(v142);
    v144 = qcar(v142);
    v143 = stack[-3];
    v142 = stack[0];
    popv(5);
    return acons(v144, v143, v142);

v149:
    v143 = stack[-2];
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    v142 = CC_multf(env, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-3] = v142;
    v143 = stack[-2];
    v142 = stack[-1];
    v142 = qcdr(v142);
    v142 = CC_multf(env, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    stack[0] = v142;
    v142 = stack[-3];
    if (v142 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v142 = stack[-1];
    v142 = qcar(v142);
    v144 = qcar(v142);
    v143 = stack[-3];
    v142 = stack[0];
    popv(5);
    return acons(v144, v143, v142);

v148:
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = qcdr(v142);
    v142 = integerp(v142);
    if (v142 == nil) goto v150;
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = qcdr(v142);
    v142 = integerp(v142);
    if (v142 == nil) goto v150;
    stack[0] = stack[-3];
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v143 = qcdr(v142);
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = qcdr(v142);
    v142 = plus2(v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    fn = elt(env, 15); /* mkspm */
    v142 = (*qfn2(fn))(qenv(fn), stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-3] = v142;
    goto v151;

v151:
    v142 = stack[-2];
    v143 = qcdr(v142);
    v142 = stack[-1];
    stack[0] = CC_multf(env, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v142 = stack[-2];
    v142 = qcar(v142);
    v143 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v142 = stack[-1];
    v142 = qcdr(v142);
    v142 = CC_multf(env, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    fn = elt(env, 16); /* addf */
    v142 = (*qfn2(fn))(qenv(fn), stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[0] = v142;
    v142 = stack[-3];
    if (v142 == nil) goto v152;
    v142 = stack[-2];
    v142 = qcar(v142);
    v143 = qcdr(v142);
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    v142 = CC_multf(env, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-2] = v142;
    if (v142 == nil) goto v152;
    v143 = stack[-3];
    v142 = (Lisp_Object)17; /* 1 */
    if (v143 == v142) goto v153;
    v142 = qvalue(elt(env, 9)); /* !*mcd */
    if (v142 == nil) goto v154;
    v144 = stack[-3];
    v143 = stack[-2];
    v142 = stack[0];
    popv(5);
    return acons(v144, v143, v142);

v154:
    v143 = stack[-3];
    v142 = stack[-2];
    v142 = cons(v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v143 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v142 = stack[0];
    {
        popv(5);
        fn = elt(env, 16); /* addf */
        return (*qfn2(fn))(qenv(fn), v143, v142);
    }

v153:
    v143 = stack[-2];
    v142 = stack[0];
    {
        popv(5);
        fn = elt(env, 16); /* addf */
        return (*qfn2(fn))(qenv(fn), v143, v142);
    }

v152:
    v142 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 8)) = v142; /* !*asymp!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v150:
    stack[0] = stack[-3];
    v144 = elt(env, 7); /* plus */
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v143 = qcdr(v142);
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = qcdr(v142);
    v142 = list3(v144, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    fn = elt(env, 17); /* reval */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    fn = elt(env, 18); /* to */
    v142 = (*qfn2(fn))(qenv(fn), stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-3] = v142;
    goto v151;

v43:
    v143 = stack[-1];
    v142 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); /* multd */
        return (*qfn2(fn))(qenv(fn), v143, v142);
    }

v17:
    v143 = stack[-2];
    v142 = stack[-1];
    {
        popv(5);
        fn = elt(env, 19); /* multd */
        return (*qfn2(fn))(qenv(fn), v143, v142);
    }

v7:
    v142 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v142); }
/* error exit handlers */
v145:
    popv(5);
    return nil;
}



/* Code for bc_prod */

static Lisp_Object CC_bc_prod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_prod");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v1 = v10;
    v2 = v0;
/* end of prologue */
    fn = elt(env, 1); /* multf */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for multdm */

static Lisp_Object CC_multdm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdm");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v61 = v10;
    v62 = v0;
/* end of prologue */
    v65 = v62;
    if (!(!consp(v65))) goto v43;
    v65 = v61;
    if (!(!consp(v65))) goto v43;
    v65 = v62;
    v65 = times2(v65, v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    v62 = v65;
    v65 = qvalue(elt(env, 1)); /* dmode!* */
    if (v65 == nil) { popv(1); return onevalue(v62); }
    v61 = qvalue(elt(env, 1)); /* dmode!* */
    v65 = elt(env, 2); /* convert */
    v65 = Lflagp(nil, v61, v65);
    env = stack[0];
    if (v65 == nil) { popv(1); return onevalue(v62); }
    v61 = qvalue(elt(env, 1)); /* dmode!* */
    v65 = elt(env, 3); /* i2d */
    v65 = get(v61, v65);
    v61 = v62;
        popv(1);
        return Lapply1(nil, v65, v61);

v43:
    v65 = elt(env, 4); /* times */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v62, v61, v65);
    }
/* error exit handlers */
v63:
    popv(1);
    return nil;
}



/* Code for negnumberchk */

static Lisp_Object CC_negnumberchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negnumberchk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v0;
/* end of prologue */
    v32 = v33;
    v13 = elt(env, 1); /* minus */
    if (!consp(v32)) return onevalue(v33);
    v32 = qcar(v32);
    if (!(v32 == v13)) return onevalue(v33);
    v32 = v33;
    v32 = qcdr(v32);
    v32 = qcar(v32);
    if (!(is_number(v32))) return onevalue(v33);
    v32 = v33;
    v32 = qcdr(v32);
    v32 = qcar(v32);
    return negate(v32);
}



/* Code for reduce_pv */

static Lisp_Object CC_reduce_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v26, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce_pv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v23 = v10;
    v26 = v0;
/* end of prologue */
    v27 = v26;
    v26 = v23;
    v23 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reduce_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v27, v26, v23);
    }
}



/* Code for noncomlistp */

static Lisp_Object CC_noncomlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomlistp");
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

v45:
    v16 = stack[0];
    v16 = Lconsp(nil, v16);
    env = stack[-1];
    if (v16 == nil) goto v3;
    v16 = stack[0];
    v16 = qcar(v16);
    fn = elt(env, 2); /* noncomp1 */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    if (!(v16 == nil)) { popv(2); return onevalue(v16); }
    v16 = stack[0];
    v16 = qcdr(v16);
    stack[0] = v16;
    goto v45;

v3:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v16); }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for rnzerop!: */

static Lisp_Object CC_rnzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v1 = qcdr(v1);
    v2 = qcar(v1);
    v1 = (Lisp_Object)1; /* 0 */
    v1 = (v2 == v1 ? lisp_true : nil);
    return onevalue(v1);
}



/* Code for modonep!: */

static Lisp_Object CC_modonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v1;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modonep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v1 = qcdr(v8);
    v8 = (Lisp_Object)17; /* 1 */
    v8 = (v1 == v8 ? lisp_true : nil);
    return onevalue(v8);
}



/* Code for mksp */

static Lisp_Object CC_mksp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksp");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    v1 = v0;
/* end of prologue */
    fn = elt(env, 1); /* fkern */
    v2 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    v1 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* getpower */
        return (*qfn2(fn))(qenv(fn), v2, v1);
    }
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for prin2x */

static Lisp_Object CC_prin2x(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2x");
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
    v7 = v0;
/* end of prologue */
    v8 = v7;
    v7 = qvalue(elt(env, 1)); /* outl!* */
    v7 = cons(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[0];
    qvalue(elt(env, 1)) = v7; /* outl!* */
    { popv(1); return onevalue(v7); }
/* error exit handlers */
v1:
    popv(1);
    return nil;
}



/* Code for rmultpf */

static Lisp_Object CC_rmultpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rmultpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v22;

v22:
    v80 = stack[-1];
    if (v80 == nil) goto v6;
    v80 = stack[-1];
    if (!consp(v80)) goto v39;
    v80 = stack[-1];
    v80 = qcar(v80);
    if (!consp(v80)) goto v39;
    v80 = stack[-2];
    v92 = qcar(v80);
    v80 = stack[-1];
    v80 = qcar(v80);
    v80 = qcar(v80);
    v80 = qcar(v80);
    fn = elt(env, 1); /* reordop */
    v80 = (*qfn2(fn))(qenv(fn), v92, v80);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    if (!(v80 == nil)) goto v39;
    v80 = stack[-1];
    v80 = qcar(v80);
    stack[0] = qcar(v80);
    v92 = stack[-2];
    v80 = stack[-1];
    v80 = qcar(v80);
    v80 = qcdr(v80);
    v92 = CC_rmultpf(env, v92, v80);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    v80 = stack[-3];
    v80 = acons(stack[0], v92, v80);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-3] = v80;
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v22;

v39:
    stack[0] = stack[-3];
    v92 = stack[-2];
    v80 = stack[-1];
    v80 = cons(v92, v80);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    {
        Lisp_Object v155 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v155, v80);
    }

v6:
    v80 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v80);
    }
/* error exit handlers */
v93:
    popv(5);
    return nil;
}



/* Code for arrayp */

static Lisp_Object CC_arrayp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arrayp");
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
    v28 = v0;
/* end of prologue */
    v29 = v28;
    v28 = elt(env, 1); /* rtype */
    v28 = get(v29, v28);
    env = stack[0];
    v29 = elt(env, 2); /* array */
    v28 = (v28 == v29 ? lisp_true : nil);
    { popv(1); return onevalue(v28); }
}



/* Code for finde */

static Lisp_Object CC_finde(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v14, v48, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for finde");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v10;
    v48 = v0;
/* end of prologue */

v4:
    v47 = v48;
    if (v47 == nil) goto v5;
    v14 = v25;
    v47 = v48;
    v47 = qcar(v47);
    v47 = qcdr(v47);
    v47 = Lmemq(nil, v14, v47);
    if (!(v47 == nil)) return onevalue(v48);
    v47 = v48;
    v47 = qcdr(v47);
    v48 = v47;
    goto v4;

v5:
    v47 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v47);
}



/* Code for nocp */

static Lisp_Object CC_nocp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nocp");
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

v45:
    v24 = stack[0];
    v24 = (v24 == nil ? lisp_true : nil);
    if (!(v24 == nil)) { popv(2); return onevalue(v24); }
    v24 = stack[0];
    v24 = qcar(v24);
    v24 = qcar(v24);
    fn = elt(env, 2); /* noncomp */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    if (v24 == nil) goto v6;
    v24 = stack[0];
    v24 = qcdr(v24);
    stack[0] = v24;
    goto v45;

v6:
    v24 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v24); }
/* error exit handlers */
v46:
    popv(2);
    return nil;
}



/* Code for quotsq */

static Lisp_Object CC_quotsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v1 = v10;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    fn = elt(env, 1); /* invsq */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    {
        Lisp_Object v27 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v27, v1);
    }
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for kernlp */

static Lisp_Object CC_kernlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */

v3:
    v32 = v31;
    if (!consp(v32)) return onevalue(v31);
    v32 = v31;
    v32 = qcar(v32);
    if (!consp(v32)) return onevalue(v31);
    v32 = v31;
    v32 = qcdr(v32);
    if (v32 == nil) goto v26;
    v31 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v31);

v26:
    v31 = qcar(v31);
    v31 = qcdr(v31);
    goto v3;
}



/* Code for ibalp_calcmom */

static Lisp_Object CC_ibalp_calcmom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_calcmom");
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
    v54 = stack[0];
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v55 = qcar(v54);
    v54 = stack[0];
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcar(v54);
    v55 = plus2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v54 = (Lisp_Object)513; /* 32 */
    stack[-1] = times2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v54 = stack[0];
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v55 = qcar(v54);
    v54 = stack[0];
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcar(v54);
    v54 = times2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v42;
    {
        Lisp_Object v81 = stack[-1];
        popv(3);
        return plus2(v81, v54);
    }
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



/* Code for compress!* */

static Lisp_Object CC_compressH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77, v78, v156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compress*");
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
    v76 = v0;
/* end of prologue */
    v156 = nil;
    v77 = v76;
    v77 = qcar(v77);
    v77 = Ldigitp(nil, v77);
    env = stack[-1];
    if (v77 == nil) goto v22;
        popv(2);
        return Lcompress(nil, v76);

v22:
    stack[0] = v76;
    goto v28;

v28:
    v76 = stack[0];
    if (v76 == nil) goto v27;
    v76 = stack[0];
    v76 = qcar(v76);
    v78 = v76;
    v77 = v78;
    v76 = elt(env, 2); /* !/ */
    if (v77 == v76) goto v64;
    v77 = v78;
    v76 = elt(env, 3); /* !- */
    if (v77 == v76) goto v64;
    v77 = v78;
    v76 = elt(env, 4); /* !; */
    if (v77 == v76) goto v64;
    v77 = v78;
    v76 = elt(env, 5); /* !. */
    if (v77 == v76) goto v64;
    v76 = v78;
    v77 = v156;
    v76 = cons(v76, v77);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-1];
    v156 = v76;
    goto v47;

v47:
    v76 = stack[0];
    v76 = qcdr(v76);
    stack[0] = v76;
    goto v28;

v64:
    v77 = v78;
    v76 = elt(env, 6); /* !! */
    v78 = v156;
    v76 = list2star(v77, v76, v78);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-1];
    v156 = v76;
    goto v47;

v27:
    v76 = v156;
    v76 = Lnreverse(nil, v76);
    env = stack[-1];
    v76 = Lcompress(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v157;
        popv(2);
        return Lintern(nil, v76);
/* error exit handlers */
v157:
    popv(2);
    return nil;
}



/* Code for ps!:order */

static Lisp_Object CC_psTorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v57, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:order");
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
    v57 = v0;
/* end of prologue */
    v11 = v57;
    if (!consp(v11)) goto v3;
    v11 = v57;
    v12 = qcar(v11);
    v11 = elt(env, 1); /* !:ps!: */
    if (v12 == v11) goto v36;
    v11 = v57;
    v12 = qcar(v11);
    v11 = elt(env, 2); /* dname */
    v11 = get(v12, v11);
    env = stack[0];
    if (!(v11 == nil)) goto v3;

v36:
    v11 = (Lisp_Object)1; /* 0 */
    {
        popv(1);
        fn = elt(env, 3); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v57, v11);
    }

v3:
    v11 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v11); }
}



/* Code for !:onep */

static Lisp_Object CC_Tonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v13, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :onep");
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
    v47 = v0;
/* end of prologue */
    v33 = v47;
    if (!consp(v33)) goto v3;
    v33 = v47;
    v13 = qcar(v33);
    v33 = elt(env, 1); /* onep */
    v33 = get(v13, v33);
    v13 = v47;
        return Lapply1(nil, v33, v13);

v3:
    v33 = v47;
        return Lonep(nil, v33);
}



/* Code for bcprod */

static Lisp_Object CC_bcprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcprod");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v68 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v68 == nil) goto v46;
    v51 = stack[-1];
    v68 = stack[0];
    v68 = times2(v51, v68);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v68);
    }

v46:
    v52 = stack[-1];
    v51 = stack[0];
    v68 = elt(env, 2); /* times */
    fn = elt(env, 4); /* bcint2op */
    v68 = (*qfnn(fn))(qenv(fn), 3, v52, v51, v68);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    if (!(v68 == nil)) { popv(3); return onevalue(v68); }
    v51 = stack[-1];
    v68 = stack[0];
    fn = elt(env, 5); /* multsq */
    v68 = (*qfn2(fn))(qenv(fn), v51, v68);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v68);
    }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for ordad */

static Lisp_Object CC_ordad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordad");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v5;

v5:
    v61 = stack[0];
    if (v61 == nil) goto v82;
    v62 = stack[-1];
    v61 = stack[0];
    v61 = qcar(v61);
    fn = elt(env, 2); /* ordp */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    if (!(v61 == nil)) goto v82;
    v61 = stack[0];
    v62 = qcar(v61);
    v61 = stack[-2];
    v61 = cons(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    stack[-2] = v61;
    v61 = stack[0];
    v61 = qcdr(v61);
    stack[0] = v61;
    goto v5;

v82:
    v62 = stack[-1];
    v61 = stack[0];
    v61 = cons(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    stack[0] = v61;
    goto v19;

v19:
    v61 = stack[-2];
    if (v61 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v61 = stack[-2];
    v61 = qcdr(v61);
    stack[-1] = v61;
    v62 = stack[-2];
    v61 = stack[0];
    v61 = Lrplacd(nil, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    v61 = stack[-2];
    stack[0] = v61;
    v61 = stack[-1];
    stack[-2] = v61;
    goto v19;
/* error exit handlers */
v74:
    popv(4);
    return nil;
}



/* Code for sublistp */

static Lisp_Object CC_sublistp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v68, v51, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sublistp");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v68 = v10;
    v51 = v0;
/* end of prologue */

v45:
    v12 = v51;
    v12 = (v12 == nil ? lisp_true : nil);
    if (!(v12 == nil)) { popv(2); return onevalue(v12); }
    v12 = v51;
    v52 = qcar(v12);
    v12 = v68;
    v12 = Lmember(nil, v52, v12);
    if (v12 == nil) goto v7;
    v12 = v51;
    stack[0] = qcdr(v12);
    v12 = v51;
    v12 = qcar(v12);
    v12 = Ldelete(nil, v12, v68);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v51 = stack[0];
    v68 = v12;
    goto v45;

v7:
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v12); }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for addcomment */

static Lisp_Object CC_addcomment(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v9;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addcomment");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    qvalue(elt(env, 1)) = v9; /* cursym!* */
    return onevalue(v9);
}



/* Code for order!: */

static Lisp_Object CC_orderT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for order:");
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
    v35 = stack[0];
    v35 = qcdr(v35);
    v36 = qcar(v35);
    v35 = (Lisp_Object)1; /* 0 */
    if (v36 == v35) goto v3;
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = Labsval(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    fn = elt(env, 1); /* msd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v35 = sub1(v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    {
        Lisp_Object v82 = stack[-1];
        popv(3);
        return plus2(v82, v35);
    }

v3:
    v35 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v35); }
/* error exit handlers */
v37:
    popv(3);
    return nil;
}



/* Code for pprin2 */

static Lisp_Object CC_pprin2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pprin2");
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
    v46 = stack[0];
    v30 = qvalue(elt(env, 1)); /* !*pprinbuf!* */
    v30 = cons(v46, v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    qvalue(elt(env, 1)) = v30; /* !*pprinbuf!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*posn!* */
    v30 = stack[0];
    v30 = Lexplodec(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v30 = Llength(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v30 = plus2(stack[-1], v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    qvalue(elt(env, 2)) = v30; /* !*posn!* */
    v30 = nil;
    { popv(3); return onevalue(v30); }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for gcdfd1 */

static Lisp_Object CC_gcdfd1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdfd1");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    v12 = v0;
/* end of prologue */

v4:
    v68 = stack[0];
    if (v68 == nil) { popv(2); return onevalue(v12); }
    v68 = stack[0];
    if (!consp(v68)) goto v16;
    v68 = stack[0];
    v68 = qcar(v68);
    if (!consp(v68)) goto v16;
    v68 = v12;
    v12 = stack[0];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = CC_gcdfd1(env, v68, v12);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v68 = stack[0];
    v68 = qcdr(v68);
    stack[0] = v68;
    goto v4;

v16:
    v68 = v12;
    v12 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* gcddd */
        return (*qfn2(fn))(qenv(fn), v68, v12);
    }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for isanindex */

static Lisp_Object CC_isanindex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v56, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isanindex");
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
    v43 = v58;
    if (symbolp(v43)) goto v2;
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v43); }

v2:
    v56 = v58;
    v43 = qvalue(elt(env, 2)); /* physopindices!* */
    v43 = Lmemq(nil, v56, v43);
    if (!(v43 == nil)) { popv(1); return onevalue(v43); }
    v56 = v58;
    v43 = qvalue(elt(env, 3)); /* physopvarind!* */
    v43 = Lmember(nil, v56, v43);
    if (!(v43 == nil)) { popv(1); return onevalue(v43); }
    v56 = v58;
    v43 = qvalue(elt(env, 4)); /* frlis!* */
    v43 = Lmemq(nil, v56, v43);
    if (v43 == nil) goto v25;
    v56 = v58;
    v43 = qvalue(elt(env, 5)); /* frasc!* */
    fn = elt(env, 6); /* revassoc */
    v43 = (*qfn2(fn))(qenv(fn), v56, v43);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[0];
    v56 = qvalue(elt(env, 2)); /* physopindices!* */
    v43 = Lmember(nil, v43, v56);
    { popv(1); return onevalue(v43); }

v25:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v43); }
/* error exit handlers */
v59:
    popv(1);
    return nil;
}



/* Code for addf */

static Lisp_Object CC_addf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v131, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addf");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v22;

v22:
    v172 = stack[-2];
    if (v172 == nil) goto v2;
    v172 = stack[-1];
    if (v172 == nil) goto v50;
    v172 = stack[-2];
    if (!consp(v172)) goto v18;
    v172 = stack[-2];
    v172 = qcar(v172);
    if (!consp(v172)) goto v18;
    v172 = stack[-1];
    if (!consp(v172)) goto v62;
    v172 = stack[-1];
    v172 = qcar(v172);
    if (!consp(v172)) goto v62;
    v172 = stack[-2];
    v172 = qcar(v172);
    v131 = qcar(v172);
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    if (equal(v131, v172)) goto v72;
    v172 = stack[-2];
    v172 = qcar(v172);
    v131 = qcar(v172);
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    fn = elt(env, 1); /* ordpp */
    v172 = (*qfn2(fn))(qenv(fn), v131, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    if (v172 == nil) goto v175;
    v172 = stack[-2];
    v131 = qcar(v172);
    v172 = stack[0];
    v172 = cons(v131, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[0] = v172;
    v172 = stack[-2];
    v172 = qcdr(v172);
    stack[-2] = v172;
    goto v22;

v175:
    v172 = stack[-1];
    v131 = qcar(v172);
    v172 = stack[0];
    v172 = cons(v131, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[0] = v172;
    v172 = stack[-1];
    v172 = qcdr(v172);
    stack[-1] = v172;
    goto v22;

v72:
    stack[-3] = stack[0];
    v172 = stack[-2];
    v172 = qcar(v172);
    v131 = qcdr(v172);
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcdr(v172);
    stack[0] = CC_addf(env, v131, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v172 = stack[-2];
    v131 = qcdr(v172);
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = CC_addf(env, v131, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v131 = stack[0];
    v173 = v131;
    if (v173 == nil) goto v77;
    v173 = stack[-2];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v172 = acons(v173, v131, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    goto v77;

v77:
    {
        Lisp_Object v176 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v176, v172);
    }

v62:
    v131 = stack[-1];
    v172 = stack[-2];
    fn = elt(env, 3); /* addd */
    v172 = (*qfn2(fn))(qenv(fn), v131, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    {
        Lisp_Object v177 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v177, v172);
    }

v18:
    v131 = stack[-2];
    v172 = stack[-1];
    fn = elt(env, 3); /* addd */
    v172 = (*qfn2(fn))(qenv(fn), v131, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    {
        Lisp_Object v178 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v178, v172);
    }

v50:
    v131 = stack[0];
    v172 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v131, v172);
    }

v2:
    v131 = stack[0];
    v172 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v131, v172);
    }
/* error exit handlers */
v174:
    popv(5);
    return nil;
}



/* Code for getrtypecar */

static Lisp_Object CC_getrtypecar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtypecar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qcar(v4);
    {
        fn = elt(env, 1); /* getrtype */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



/* Code for sub2chk */

static Lisp_Object CC_sub2chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v35, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub2chk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v36 = v0;
/* end of prologue */
    v25 = qvalue(elt(env, 1)); /* subfg!* */
    if (v25 == nil) goto v4;
    v35 = v36;
    v25 = qvalue(elt(env, 2)); /* powlis!* */
    v25 = Latsoc(nil, v35, v25);
    if (!(v25 == nil)) goto v3;
    v25 = v36;
    if (!consp(v25)) goto v4;
    v25 = v36;
    v35 = qcar(v25);
    v25 = elt(env, 3); /* (expt sqrt) */
    v25 = Lmemq(nil, v35, v25);
    if (!(v25 == nil)) goto v3;

v4:
    v25 = nil;
    return onevalue(v25);

v3:
    v25 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 5)) = v25; /* !*sub2 */
    return onevalue(v25);
}



/* Code for ring_ecart */

static Lisp_Object CC_ring_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ring_ecart");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v8 = v7;
    v7 = (Lisp_Object)81; /* 5 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }
}



/* Code for mtp */

static Lisp_Object CC_mtp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v57, v12;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */

v45:
    v11 = v57;
    v11 = (v11 == nil ? lisp_true : nil);
    if (!(v11 == nil)) return onevalue(v11);
    v11 = v57;
    v12 = qcar(v11);
    v11 = qvalue(elt(env, 1)); /* frlis!* */
    v11 = Lmemq(nil, v12, v11);
    if (v11 == nil) goto v6;
    v11 = v57;
    v12 = qcar(v11);
    v11 = v57;
    v11 = qcdr(v11);
    v11 = Lmember(nil, v12, v11);
    if (v11 == nil) goto v36;
    v11 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v11);

v36:
    v11 = v57;
    v11 = qcdr(v11);
    v57 = v11;
    goto v45;

v6:
    v11 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v11);
}



/* Code for unpkp */

static Lisp_Object CC_unpkp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v182, v183;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unpkp");
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
    v181 = stack[-1];
    if (!(!consp(v181))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v181 = stack[-1];
    v181 = Lexplode(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    stack[-1] = v181;
    v181 = stack[-1];
    v182 = Llength(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v181 = (Lisp_Object)161; /* 10 */
    v181 = (Lisp_Object)geq2(v182, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    v181 = v181 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v181;
    v181 = stack[0];
    if (v181 == nil) goto v52;
    v181 = stack[-1];
    v181 = Llength(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v181 = Levenp(nil, v181);
    env = stack[-3];
    if (!(v181 == nil)) goto v52;
    v182 = elt(env, 1); /* !0 */
    v181 = stack[-1];
    v181 = cons(v182, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    stack[-1] = v181;
    goto v52;

v52:
    v181 = stack[-1];
    if (v181 == nil) goto v51;
    v181 = stack[0];
    if (v181 == nil) goto v185;
    v181 = stack[-1];
    v182 = qcar(v181);
    v181 = qvalue(elt(env, 3)); /* diglist!* */
    v181 = Lassoc(nil, v182, v181);
    v181 = qcdr(v181);
    v182 = v181;
    v181 = stack[-1];
    v181 = qcdr(v181);
    stack[-1] = v181;
    v181 = (Lisp_Object)161; /* 10 */
    v183 = times2(v182, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v181 = stack[-1];
    v182 = qcar(v181);
    v181 = qvalue(elt(env, 3)); /* diglist!* */
    v181 = Lassoc(nil, v182, v181);
    v181 = qcdr(v181);
    v182 = plus2(v183, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v181 = stack[-2];
    v181 = cons(v182, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    stack[-2] = v181;
    goto v53;

v53:
    v181 = stack[-1];
    v181 = qcdr(v181);
    stack[-1] = v181;
    goto v52;

v185:
    v181 = stack[-1];
    v182 = qcar(v181);
    v181 = qvalue(elt(env, 3)); /* diglist!* */
    v181 = Lassoc(nil, v182, v181);
    v182 = qcdr(v181);
    v181 = stack[-2];
    v181 = cons(v182, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    stack[-2] = v181;
    goto v53;

v51:
    v181 = stack[-2];
        popv(4);
        return Lnreverse(nil, v181);
/* error exit handlers */
v184:
    popv(4);
    return nil;
}



/* Code for rnequiv */

static Lisp_Object CC_rnequiv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v24, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnequiv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v0;
/* end of prologue */
    v16 = v24;
    v16 = qcdr(v16);
    v24 = v16;
    v30 = qcdr(v16);
    v16 = (Lisp_Object)17; /* 1 */
    if (v30 == v16) goto v3;
    v16 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v16);

v3:
    v16 = v24;
    v16 = qcar(v16);
    return onevalue(v16);
}



/* Code for multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_multiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiply-by-constant-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v0;
/* end of prologue */
    v61 = stack[-2];
    if (v61 == nil) goto v4;
    v62 = stack[-1];
    v61 = (Lisp_Object)17; /* 1 */
    if (v62 == v61) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v61 = stack[-2];
    if (!consp(v61)) goto v13;
    v61 = stack[-2];
    v61 = qcar(v61);
    if (!consp(v61)) goto v13;
    v61 = stack[-2];
    v61 = qcar(v61);
    stack[-3] = qcar(v61);
    v61 = stack[-2];
    v61 = qcar(v61);
    v62 = qcdr(v61);
    v61 = stack[-1];
    stack[0] = CC_multiplyKbyKconstantKmodKp(env, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-4];
    v61 = stack[-2];
    v62 = qcdr(v61);
    v61 = stack[-1];
    v61 = CC_multiplyKbyKconstantKmodKp(env, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-4];
    {
        Lisp_Object v83 = stack[-3];
        Lisp_Object v84 = stack[0];
        popv(5);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v83, v84, v61);
    }

v13:
    v62 = stack[-2];
    v61 = stack[-1];
    v61 = Lmodular_times(nil, v62, v61);
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v61);
    }

v4:
    v61 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v61); }
/* error exit handlers */
v67:
    popv(5);
    return nil;
}



/* Code for reordop */

static Lisp_Object CC_reordop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reordop");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v47 == nil) goto v5;
    v47 = stack[-1];
    fn = elt(env, 3); /* noncomp1 */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    if (v47 == nil) goto v1;
    v47 = stack[0];
    fn = elt(env, 3); /* noncomp1 */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    goto v49;

v49:
    if (!(v47 == nil)) { popv(3); return onevalue(v47); }
    v14 = stack[-1];
    v47 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* ordop */
        return (*qfn2(fn))(qenv(fn), v14, v47);
    }

v1:
    v47 = qvalue(elt(env, 2)); /* nil */
    goto v49;

v5:
    v47 = qvalue(elt(env, 2)); /* nil */
    goto v49;
/* error exit handlers */
v35:
    popv(3);
    return nil;
}



/* Code for aconc!* */

static Lisp_Object CC_aconcH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aconc*");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v1 = v10;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    v1 = ncons(v1);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v27 = stack[0];
        popv(1);
        return Lnconc(nil, v27, v1);
    }
/* error exit handlers */
v26:
    popv(1);
    return nil;
}



/* Code for aconc */

static Lisp_Object CC_aconc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aconc");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v1 = v10;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    v1 = ncons(v1);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v27 = stack[0];
        popv(1);
        return Lnconc(nil, v27, v1);
    }
/* error exit handlers */
v26:
    popv(1);
    return nil;
}



/* Code for exptchksq */

static Lisp_Object CC_exptchksq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptchksq");
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
    v46 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v46 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v46 = stack[0];
    v46 = qcar(v46);
    fn = elt(env, 2); /* exptchk */
    stack[-1] = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v46 = stack[0];
    v46 = qcdr(v46);
    fn = elt(env, 2); /* exptchk */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    fn = elt(env, 3); /* invsq */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    {
        Lisp_Object v33 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v33, v46);
    }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for replus */

static Lisp_Object CC_replus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replus");
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
    v14 = v0;
/* end of prologue */
    v47 = v14;
    if (v47 == nil) goto v3;
    v47 = v14;
    if (!consp(v47)) { popv(1); return onevalue(v14); }
    v47 = v14;
    v47 = qcdr(v47);
    if (v47 == nil) goto v1;
    stack[0] = elt(env, 1); /* plus */
    v47 = v14;
    fn = elt(env, 2); /* unplus */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v25;
    {
        Lisp_Object v35 = stack[0];
        popv(1);
        return cons(v35, v47);
    }

v1:
    v47 = v14;
    v47 = qcar(v47);
    { popv(1); return onevalue(v47); }

v3:
    v47 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v47); }
/* error exit handlers */
v25:
    popv(1);
    return nil;
}



/* Code for multd */

static Lisp_Object CC_multd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multd");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v22;

v22:
    v87 = stack[-1];
    if (v87 == nil) goto v6;
    v88 = stack[-1];
    v87 = (Lisp_Object)17; /* 1 */
    if (v88 == v87) goto v50;
    v87 = stack[-1];
    if (!consp(v87)) goto v11;
    v87 = stack[-1];
    v87 = qcar(v87);
    if (!consp(v87)) goto v11;
    v87 = stack[-1];
    v87 = qcar(v87);
    stack[0] = qcar(v87);
    v88 = stack[-2];
    v87 = stack[-1];
    v87 = qcar(v87);
    v87 = qcdr(v87);
    v88 = CC_multd(env, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v87 = stack[-3];
    v87 = acons(stack[0], v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    stack[-3] = v87;
    v87 = stack[-1];
    v87 = qcdr(v87);
    stack[-1] = v87;
    goto v22;

v11:
    stack[0] = stack[-3];
    v88 = stack[-2];
    v87 = stack[-1];
    fn = elt(env, 1); /* multdm */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    {
        Lisp_Object v69 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v69, v87);
    }

v50:
    v88 = stack[-3];
    v87 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v88, v87);
    }

v6:
    v87 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v87);
    }
/* error exit handlers */
v186:
    popv(5);
    return nil;
}



/* Code for delq */

static Lisp_Object CC_delq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v73, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delq");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v0;
/* end of prologue */
    v53 = nil;
    goto v22;

v22:
    v38 = stack[0];
    if (v38 == nil) goto v18;
    v38 = stack[0];
    v73 = qcar(v38);
    v38 = stack[-1];
    if (v73 == v38) goto v31;
    v38 = stack[0];
    v38 = qcar(v38);
    v73 = v53;
    v38 = cons(v38, v73);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-2];
    v53 = v38;
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v22;

v31:
    v73 = v53;
    v38 = stack[0];
    v38 = qcdr(v38);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v73, v38);
    }

v18:
    v38 = v53;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v38);
    }
/* error exit handlers */
v40:
    popv(3);
    return nil;
}



/* Code for get_token */

static Lisp_Object MS_CDECL CC_get_token(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v37;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "get_token");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_token");
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
    v39 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v39;
    goto v1;

v1:
    v37 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    qvalue(elt(env, 2)) = v37; /* ch */
    v39 = elt(env, 3); /* !> */
    if (v37 == v39) goto v47;
    v37 = qvalue(elt(env, 2)); /* ch */
    v39 = stack[0];
    v39 = cons(v37, v39);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    stack[0] = v39;
    goto v1;

v47:
    v37 = elt(env, 4); /* !$ */
    v39 = stack[0];
    popv(2);
    return cons(v37, v39);
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for ps!:last!-term */

static Lisp_Object CC_psTlastKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v57, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:last-term");
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
    v57 = v0;
/* end of prologue */
    v11 = v57;
    if (!consp(v11)) goto v3;
    v11 = v57;
    v12 = qcar(v11);
    v11 = elt(env, 1); /* !:ps!: */
    if (v12 == v11) goto v36;
    v11 = v57;
    v12 = qcar(v11);
    v11 = elt(env, 2); /* dname */
    v11 = get(v12, v11);
    env = stack[0];
    if (!(v11 == nil)) goto v3;

v36:
    v11 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v57, v11);
    }

v3:
    v11 = qvalue(elt(env, 3)); /* ps!:max!-order */
    { popv(1); return onevalue(v11); }
}



setup_type const u01_setup[] =
{
    {"noncomp",                 CC_noncomp,     too_many_1,    wrong_no_1},
    {"simpcar",                 CC_simpcar,     too_many_1,    wrong_no_1},
    {"reval",                   CC_reval,       too_many_1,    wrong_no_1},
    {"terminalp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_terminalp},
    {"delcp",                   CC_delcp,       too_many_1,    wrong_no_1},
    {"ordop",                   too_few_2,      CC_ordop,      wrong_no_2},
    {"exchk",                   CC_exchk,       too_many_1,    wrong_no_1},
    {"noncomfp",                CC_noncomfp,    too_many_1,    wrong_no_1},
    {"wuconstantp",             CC_wuconstantp, too_many_1,    wrong_no_1},
    {"mkcopy",                  CC_mkcopy,      too_many_1,    wrong_no_1},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,too_many_1,wrong_no_1},
    {"num-exponents",           CC_numKexponents,too_many_1,   wrong_no_1},
    {"mchkopt",                 too_few_2,      CC_mchkopt,    wrong_no_2},
    {"nth",                     too_few_2,      CC_nth,        wrong_no_2},
    {"ibalp_cec",               CC_ibalp_cec,   too_many_1,    wrong_no_1},
    {"delall",                  too_few_2,      CC_delall,     wrong_no_2},
    {"ps:getv",                 too_few_2,      CC_psTgetv,    wrong_no_2},
    {"add_prin_char",           too_few_2,      CC_add_prin_char,wrong_no_2},
    {"c:ordxp",                 too_few_2,      CC_cTordxp,    wrong_no_2},
    {"dm-abs",                  CC_dmKabs,      too_many_1,    wrong_no_1},
    {"evcomp",                  too_few_2,      CC_evcomp,     wrong_no_2},
    {"evmatrixcomp2",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp2},
    {"xval",                    CC_xval,        too_many_1,    wrong_no_1},
    {"smember",                 too_few_2,      CC_smember,    wrong_no_2},
    {"convprec",                CC_convprec,    too_many_1,    wrong_no_1},
    {"quotf",                   too_few_2,      CC_quotf,      wrong_no_2},
    {"physopp",                 CC_physopp,     too_many_1,    wrong_no_1},
    {"memq_edgelist",           too_few_2,      CC_memq_edgelist,wrong_no_2},
    {"*n2f",                    CC_Hn2f,        too_many_1,    wrong_no_1},
    {"c_zero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_c_zero},
    {"sieve_pv0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sieve_pv0},
    {"listp",                   CC_listp,       too_many_1,    wrong_no_1},
    {"quotelist",               CC_quotelist,   too_many_1,    wrong_no_1},
    {"revpr",                   CC_revpr,       too_many_1,    wrong_no_1},
    {"pnth",                    too_few_2,      CC_pnth,       wrong_no_2},
    {"degr",                    too_few_2,      CC_degr,       wrong_no_2},
    {"ibalp_commonlenisone",    too_few_2,      CC_ibalp_commonlenisone,wrong_no_2},
    {"find2",                   too_few_2,      CC_find2,      wrong_no_2},
    {"zero2nil",                CC_zero2nil,    too_many_1,    wrong_no_1},
    {"binding",                 CC_binding,     too_many_1,    wrong_no_1},
    {"prepf",                   CC_prepf,       too_many_1,    wrong_no_1},
    {"vevmtest?",               too_few_2,      CC_vevmtestW,  wrong_no_2},
    {"vbcsize",                 too_few_2,      CC_vbcsize,    wrong_no_2},
    {"ordpp",                   too_few_2,      CC_ordpp,      wrong_no_2},
    {"wedgefax",                CC_wedgefax,    too_many_1,    wrong_no_1},
    {"times:",                  too_few_2,      CC_timesT,     wrong_no_2},
    {"round*",                  CC_roundH,      too_many_1,    wrong_no_1},
    {"noncomp2",                CC_noncomp2,    too_many_1,    wrong_no_1},
    {"union_edge",              too_few_2,      CC_union_edge, wrong_no_2},
    {"termsf",                  CC_termsf,      too_many_1,    wrong_no_1},
    {"readch1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_readch1},
    {"mkspm",                   too_few_2,      CC_mkspm,      wrong_no_2},
    {"mo_divides?",             too_few_2,      CC_mo_dividesW,wrong_no_2},
    {"mchk*",                   too_few_2,      CC_mchkH,      wrong_no_2},
    {"dlesslex",                too_few_2,      CC_dlesslex,   wrong_no_2},
    {"pappl",                   too_few_2,      CC_pappl,      wrong_no_2},
    {"adjoin-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_adjoinKterm},
    {"modzerop:",               CC_modzeropT,   too_many_1,    wrong_no_1},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"noncomp1",                CC_noncomp1,    too_many_1,    wrong_no_1},
    {"subs3f",                  CC_subs3f,      too_many_1,    wrong_no_1},
    {"tayexp-lessp",            too_few_2,      CC_tayexpKlessp,wrong_no_2},
    {"get+mat+entry",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_getLmatLentry},
    {"butes",                   CC_butes,       too_many_1,    wrong_no_1},
    {"noncomfp1",               CC_noncomfp1,   too_many_1,    wrong_no_1},
    {"scprint",                 too_few_2,      CC_scprint,    wrong_no_2},
    {"ldepends",                too_few_2,      CC_ldepends,   wrong_no_2},
    {"numlis",                  CC_numlis,      too_many_1,    wrong_no_1},
    {":minusp",                 CC_Tminusp,     too_many_1,    wrong_no_1},
    {"pm:free",                 CC_pmTfree,     too_many_1,    wrong_no_1},
    {"prepf1",                  too_few_2,      CC_prepf1,     wrong_no_2},
    {"*d2q",                    CC_Hd2q,        too_many_1,    wrong_no_1},
    {"buchvevdivides?",         too_few_2,      CC_buchvevdividesW,wrong_no_2},
    {"expchk",                  CC_expchk,      too_many_1,    wrong_no_1},
    {"csl_normbf",              CC_csl_normbf,  too_many_1,    wrong_no_1},
    {"mkround",                 CC_mkround,     too_many_1,    wrong_no_1},
    {"argsofopr",               CC_argsofopr,   too_many_1,    wrong_no_1},
    {"multf",                   too_few_2,      CC_multf,      wrong_no_2},
    {"bc_prod",                 too_few_2,      CC_bc_prod,    wrong_no_2},
    {"multdm",                  too_few_2,      CC_multdm,     wrong_no_2},
    {"negnumberchk",            CC_negnumberchk,too_many_1,    wrong_no_1},
    {"reduce_pv",               too_few_2,      CC_reduce_pv,  wrong_no_2},
    {"noncomlistp",             CC_noncomlistp, too_many_1,    wrong_no_1},
    {"rnzerop:",                CC_rnzeropT,    too_many_1,    wrong_no_1},
    {"modonep:",                CC_modonepT,    too_many_1,    wrong_no_1},
    {"mksp",                    too_few_2,      CC_mksp,       wrong_no_2},
    {"prin2x",                  CC_prin2x,      too_many_1,    wrong_no_1},
    {"rmultpf",                 too_few_2,      CC_rmultpf,    wrong_no_2},
    {"arrayp",                  CC_arrayp,      too_many_1,    wrong_no_1},
    {"finde",                   too_few_2,      CC_finde,      wrong_no_2},
    {"nocp",                    CC_nocp,        too_many_1,    wrong_no_1},
    {"quotsq",                  too_few_2,      CC_quotsq,     wrong_no_2},
    {"kernlp",                  CC_kernlp,      too_many_1,    wrong_no_1},
    {"ibalp_calcmom",           CC_ibalp_calcmom,too_many_1,   wrong_no_1},
    {"compress*",               CC_compressH,   too_many_1,    wrong_no_1},
    {"ps:order",                CC_psTorder,    too_many_1,    wrong_no_1},
    {":onep",                   CC_Tonep,       too_many_1,    wrong_no_1},
    {"bcprod",                  too_few_2,      CC_bcprod,     wrong_no_2},
    {"ordad",                   too_few_2,      CC_ordad,      wrong_no_2},
    {"sublistp",                too_few_2,      CC_sublistp,   wrong_no_2},
    {"addcomment",              CC_addcomment,  too_many_1,    wrong_no_1},
    {"order:",                  CC_orderT,      too_many_1,    wrong_no_1},
    {"pprin2",                  CC_pprin2,      too_many_1,    wrong_no_1},
    {"gcdfd1",                  too_few_2,      CC_gcdfd1,     wrong_no_2},
    {"isanindex",               CC_isanindex,   too_many_1,    wrong_no_1},
    {"addf",                    too_few_2,      CC_addf,       wrong_no_2},
    {"getrtypecar",             CC_getrtypecar, too_many_1,    wrong_no_1},
    {"sub2chk",                 CC_sub2chk,     too_many_1,    wrong_no_1},
    {"ring_ecart",              CC_ring_ecart,  too_many_1,    wrong_no_1},
    {"mtp",                     CC_mtp,         too_many_1,    wrong_no_1},
    {"unpkp",                   CC_unpkp,       too_many_1,    wrong_no_1},
    {"rnequiv",                 CC_rnequiv,     too_many_1,    wrong_no_1},
    {"multiply-by-constant-mod-p",too_few_2,    CC_multiplyKbyKconstantKmodKp,wrong_no_2},
    {"reordop",                 too_few_2,      CC_reordop,    wrong_no_2},
    {"aconc*",                  too_few_2,      CC_aconcH,     wrong_no_2},
    {"aconc",                   too_few_2,      CC_aconc,      wrong_no_2},
    {"exptchksq",               CC_exptchksq,   too_many_1,    wrong_no_1},
    {"replus",                  CC_replus,      too_many_1,    wrong_no_1},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {"delq",                    too_few_2,      CC_delq,       wrong_no_2},
    {"get_token",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_token},
    {"ps:last-term",            CC_psTlastKterm,too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u01", (two_args *)"14536 6814783 5930663", 0}
};

/* end of generated code */
