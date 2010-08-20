
/* $destdir/generated-c\u22.c Machine generated C code */

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


/* Code for reverse!-num1 */

static Lisp_Object CC_reverseKnum1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reverse-num1");
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
    stack[0] = v0;
/* end of prologue */
    v45 = stack[0];
    v44 = (Lisp_Object)1; /* 0 */
    if (v45 == v44) goto v46;
    v45 = stack[-2];
    v44 = (Lisp_Object)17; /* 1 */
    if (v45 == v44) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v45 = stack[-2];
    v44 = (Lisp_Object)33; /* 2 */
    if (v45 == v44) goto v47;
    v45 = stack[-2];
    v44 = (Lisp_Object)49; /* 3 */
    if (v45 == v44) goto v48;
    v45 = stack[-2];
    v44 = (Lisp_Object)65; /* 4 */
    if (v45 == v44) goto v49;
    stack[-1] = (Lisp_Object)33; /* 2 */
    v45 = stack[-2];
    v44 = (Lisp_Object)33; /* 2 */
    v44 = quot2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v44 = Lexpt(nil, stack[-1], v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    stack[-3] = v44;
    v45 = stack[0];
    v44 = stack[-3];
    v44 = Ldivide(nil, v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    stack[-1] = v44;
    v44 = stack[-2];
    v44 = Levenp(nil, v44);
    env = stack[-4];
    if (!(v44 == nil)) goto v51;
    v45 = stack[-3];
    v44 = (Lisp_Object)33; /* 2 */
    v44 = times2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    stack[-3] = v44;
    goto v51;

v51:
    v44 = stack[-1];
    stack[0] = qcdr(v44);
    v45 = stack[-2];
    v44 = (Lisp_Object)33; /* 2 */
    v44 = quot2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v45 = CC_reverseKnum1(env, stack[0], v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v44 = stack[-3];
    stack[0] = times2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v44 = stack[-1];
    stack[-1] = qcar(v44);
    v44 = stack[-2];
    v45 = add1(v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v44 = (Lisp_Object)33; /* 2 */
    v44 = quot2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v44 = CC_reverseKnum1(env, stack[-1], v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    {
        Lisp_Object v52 = stack[0];
        popv(5);
        return plus2(v52, v44);
    }

v49:
    v45 = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v44 = stack[0];
    v44 = *(Lisp_Object *)((char *)v45 + (CELL-TAG_VECTOR) + ((int32_t)v44/(16/CELL)));
    { popv(5); return onevalue(v44); }

v48:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v45 = (Lisp_Object)33; /* 2 */
    v44 = stack[0];
    v44 = times2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v44 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v44/(16/CELL)));
    { popv(5); return onevalue(v44); }

v47:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v45 = (Lisp_Object)65; /* 4 */
    v44 = stack[0];
    v44 = times2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v44 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v44/(16/CELL)));
    { popv(5); return onevalue(v44); }

v46:
    v44 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v44); }
/* error exit handlers */
v50:
    popv(5);
    return nil;
}



/* Code for !*tayexp2q */

static Lisp_Object CC_Htayexp2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *tayexp2q");
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
    v53 = v0;
/* end of prologue */
    v54 = v53;
    if (!consp(v54)) goto v55;
    v53 = qcdr(v53);
    { popv(1); return onevalue(v53); }

v55:
    v54 = v53;
    v54 = (Lisp_Object)zerop(v54);
    v54 = v54 ? lisp_true : nil;
    env = stack[0];
    if (v54 == nil) goto v56;
    v53 = qvalue(elt(env, 1)); /* nil */
    v54 = v53;
    goto v57;

v57:
    v53 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v54, v53);

v56:
    v54 = v53;
    goto v57;
}



/* Code for lambdaom */

static Lisp_Object CC_lambdaom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdaom");
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
    v59 = v0;
/* end of prologue */
    v58 = v59;
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    stack[-1] = v58;
    v58 = v59;
    v58 = Lreverse(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = qcar(v58);
    stack[0] = v58;
    v58 = elt(env, 1); /* "<OMBIND>" */
    fn = elt(env, 8); /* printout */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 9); /* indent!* */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = elt(env, 3); /* "<OMS cd=""fns1"" name=""lambda""/>" */
    fn = elt(env, 8); /* printout */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = elt(env, 4); /* "<OMBVAR>" */
    fn = elt(env, 8); /* printout */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 9); /* indent!* */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = stack[-1];
    fn = elt(env, 10); /* objectom */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 9); /* indent!* */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = elt(env, 6); /* "</OMBVAR>" */
    fn = elt(env, 8); /* printout */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = stack[0];
    fn = elt(env, 10); /* objectom */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 9); /* indent!* */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v58 = elt(env, 7); /* "</OMBIND>" */
    fn = elt(env, 8); /* printout */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v58 = nil;
    { popv(3); return onevalue(v58); }
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for ps!:value */

static Lisp_Object CC_psTvalue(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v66, v67;
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
    v66 = v0;
/* end of prologue */
    v37 = v66;
    if (!consp(v37)) goto v68;
    v37 = v66;
    v67 = qcar(v37);
    v37 = elt(env, 1); /* !:ps!: */
    if (v67 == v37) goto v69;
    v37 = v66;
    v67 = qcar(v37);
    v37 = elt(env, 2); /* dname */
    v37 = get(v67, v37);
    env = stack[0];
    if (!(v37 == nil)) goto v68;

v69:
    v37 = (Lisp_Object)65; /* 4 */
    {
        popv(1);
        fn = elt(env, 3); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v66, v37);
    }

v68:
    v37 = v66;
    if (!(v37 == nil)) { popv(1); return onevalue(v66); }
    v37 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v37); }
}



/* Code for overall_factor */

static Lisp_Object CC_overall_factor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for overall_factor");
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

v72:
    v39 = stack[0];
    v39 = (v39 == nil ? lisp_true : nil);
    if (!(v39 == nil)) { popv(4); return onevalue(v39); }
    stack[-2] = stack[-1];
    v39 = stack[0];
    fn = elt(env, 2); /* xval */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    v39 = Lmemq(nil, stack[-2], v39);
    if (v39 == nil) goto v57;
    v47 = stack[-1];
    v39 = stack[0];
    v39 = qcdr(v39);
    stack[-1] = v47;
    stack[0] = v39;
    goto v72;

v57:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v39); }
/* error exit handlers */
v59:
    popv(4);
    return nil;
}



/* Code for testchar1 */

static Lisp_Object CC_testchar1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testchar1");
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
    v66 = stack[0];
    v66 = integerp(v66);
    if (!(v66 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v66 = stack[0];
    v66 = Lexplodec(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    v66 = qcdr(v66);
    if (v66 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v67 = stack[0];
    v66 = qvalue(elt(env, 1)); /* nochar!* */
    v66 = Lmember(nil, v67, v66);
    if (!(v66 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v67 = stack[0];
    v66 = qvalue(elt(env, 2)); /* nochar1!* */
    v66 = Lmember(nil, v67, v66);
    if (!(v66 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v67 = stack[0];
    v66 = qvalue(elt(env, 2)); /* nochar1!* */
    v66 = cons(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    qvalue(elt(env, 2)) = v66; /* nochar1!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v73:
    popv(2);
    return nil;
}



/* Code for chkint!* */

static Lisp_Object CC_chkintH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chkint*");
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
    v78 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v78 == nil) goto v80;
    v78 = stack[0];
    v78 = Lfloatp(nil, v78);
    env = stack[-1];
    if (v78 == nil) goto v81;
    v78 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v78);
    }

v81:
    v78 = stack[0];
    if (!consp(v78)) goto v82;
    v78 = stack[0];
    goto v83;

v83:
    {
        popv(2);
        fn = elt(env, 5); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v78);
    }

v82:
    v78 = stack[0];
    v78 = integerp(v78);
    if (v78 == nil) goto v35;
    v22 = elt(env, 2); /* !:rd!: */
    v79 = stack[0];
    v78 = (Lisp_Object)1; /* 0 */
    v78 = list2star(v22, v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    goto v83;

v35:
    v78 = stack[0];
    fn = elt(env, 6); /* read!:num */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    goto v83;

v80:
    v78 = stack[0];
    v78 = Labsval(nil, v78);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    v79 = v78;
    v78 = stack[0];
    v78 = Lfloatp(nil, v78);
    env = stack[-1];
    if (!(v78 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v78 = v79;
    fn = elt(env, 7); /* msd */
    v79 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    v78 = qvalue(elt(env, 3)); /* !!maxbflexp */
    v78 = (Lisp_Object)lesseq2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v78 = v78 ? lisp_true : nil;
    env = stack[-1];
    if (v78 == nil) goto v85;
    v78 = stack[0];
        popv(2);
        return Lfloat(nil, v78);

v85:
    fn = elt(env, 8); /* rndbfon */
    v78 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    v78 = stack[0];
    v78 = Lfloatp(nil, v78);
    env = stack[-1];
    if (v78 == nil) goto v86;
    v78 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v78);
    }

v86:
    v78 = stack[0];
    if (!consp(v78)) goto v87;
    v78 = stack[0];
    goto v88;

v88:
    {
        popv(2);
        fn = elt(env, 5); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v78);
    }

v87:
    v78 = stack[0];
    v78 = integerp(v78);
    if (v78 == nil) goto v21;
    v22 = elt(env, 2); /* !:rd!: */
    v79 = stack[0];
    v78 = (Lisp_Object)1; /* 0 */
    v78 = list2star(v22, v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    goto v88;

v21:
    v78 = stack[0];
    fn = elt(env, 6); /* read!:num */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    goto v88;
/* error exit handlers */
v84:
    popv(2);
    return nil;
}



/* Code for gparg1p */

static Lisp_Object CC_gparg1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gparg1p");
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

v72:
    v56 = stack[0];
    v56 = (v56 == nil ? lisp_true : nil);
    if (!(v56 == nil)) { popv(2); return onevalue(v56); }
    v56 = stack[0];
    v56 = qcar(v56);
    fn = elt(env, 2); /* gpargp */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-1];
    if (v56 == nil) goto v89;
    v56 = stack[0];
    v56 = qcdr(v56);
    stack[0] = v56;
    goto v72;

v89:
    v56 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v56); }
/* error exit handlers */
v40:
    popv(2);
    return nil;
}



/* Code for !*pf2sq */

static Lisp_Object CC_Hpf2sq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *pf2sq");
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
    v100 = qvalue(elt(env, 1)); /* nil */
    v99 = (Lisp_Object)17; /* 1 */
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    stack[-1] = v99;
    v99 = stack[0];
    if (v99 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v99 = stack[0];
    stack[0] = v99;
    goto v40;

v40:
    v99 = stack[0];
    if (v99 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v99 = stack[0];
    v99 = qcar(v99);
    v100 = qcar(v99);
    v99 = (Lisp_Object)17; /* 1 */
    if (v100 == v99) goto v32;
    v99 = stack[0];
    v99 = qcar(v99);
    v100 = qcar(v99);
    v99 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* to */
    v100 = (*qfn2(fn))(qenv(fn), v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v99 = (Lisp_Object)17; /* 1 */
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v100 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v99 = (Lisp_Object)17; /* 1 */
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v100 = v99;
    goto v35;

v35:
    v99 = stack[0];
    v99 = qcar(v99);
    v99 = qcdr(v99);
    fn = elt(env, 3); /* multsq */
    v100 = (*qfn2(fn))(qenv(fn), v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v99 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v99 = (*qfn2(fn))(qenv(fn), v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    stack[-1] = v99;
    v99 = stack[0];
    v99 = qcdr(v99);
    stack[0] = v99;
    goto v40;

v32:
    v100 = (Lisp_Object)17; /* 1 */
    v99 = (Lisp_Object)17; /* 1 */
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v100 = v99;
    goto v35;
/* error exit handlers */
v74:
    popv(3);
    return nil;
}



/* Code for prop!-simp2 */

static Lisp_Object CC_propKsimp2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp2");
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
    v104 = stack[-2];
    if (!consp(v104)) goto v42;
    v94 = stack[-2];
    v104 = stack[-3];
    v104 = Lmember(nil, v94, v104);
    goto v98;

v98:
    stack[-4] = v104;
    if (v104 == nil) goto v33;
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v104 = stack[-3];
    stack[0] = Llength(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v104 = stack[-4];
    v104 = Llength(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v104 = difference2(stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    stack[0] = Lexpt(nil, stack[-1], v104);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v94 = stack[-2];
    v104 = stack[-3];
    v104 = Ldelete(nil, v94, v104);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v85 = stack[0];
        popv(6);
        return cons(v85, v104);
    }

v33:
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v104); }

v42:
    v104 = qvalue(elt(env, 1)); /* nil */
    goto v98;
/* error exit handlers */
v105:
    popv(6);
    return nil;
}



/* Code for quotpri */

static Lisp_Object CC_quotpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v69, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotpri");
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
    v69 = v0;
/* end of prologue */
    stack[0] = nil;
    v60 = qvalue(elt(env, 1)); /* !*ratpri */
    if (v60 == nil) goto v106;
    v60 = qvalue(elt(env, 2)); /* !*nat */
    if (v60 == nil) goto v106;
    v60 = qvalue(elt(env, 3)); /* !*fort */
    if (!(v60 == nil)) goto v106;
    v60 = qvalue(elt(env, 4)); /* !*list */
    if (!(v60 == nil)) goto v106;
    v60 = qvalue(elt(env, 5)); /* !*mcd */
    if (v60 == nil) goto v106;
    v80 = qvalue(elt(env, 7)); /* dmode!* */
    v60 = elt(env, 8); /* ratmode */
    v60 = Lflagp(nil, v80, v60);
    env = stack[-1];
    if (v60 == nil) goto v107;
    v60 = qvalue(elt(env, 7)); /* dmode!* */
    stack[0] = v60;
    v60 = qvalue(elt(env, 9)); /* nil */
    qvalue(elt(env, 7)) = v60; /* dmode!* */
    goto v107;

v107:
    v60 = v69;
    fn = elt(env, 10); /* ratfunpri1 */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    v69 = v60;
    v60 = stack[0];
    if (v60 == nil) { popv(2); return onevalue(v69); }
    v60 = stack[0];
    qvalue(elt(env, 7)) = v60; /* dmode!* */
    { popv(2); return onevalue(v69); }

v106:
    v60 = elt(env, 6); /* failed */
    { popv(2); return onevalue(v60); }
/* error exit handlers */
v61:
    popv(2);
    return nil;
}



/* Code for red!=hide */

static Lisp_Object CC_redMhide(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hide");
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
    v113 = v0;
/* end of prologue */
    stack[-5] = v113;
    v113 = stack[-5];
    if (v113 == nil) goto v98;
    v113 = stack[-5];
    v113 = qcar(v113);
    stack[-1] = v113;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v113 = stack[-1];
    v113 = qcar(v113);
    fn = elt(env, 2); /* mo_neg */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v114 = (*qfn2(fn))(qenv(fn), stack[0], v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    v113 = stack[-1];
    v113 = qcdr(v113);
    v113 = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    v113 = ncons(v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    stack[-3] = v113;
    stack[-4] = v113;
    goto v106;

v106:
    v113 = stack[-5];
    v113 = qcdr(v113);
    stack[-5] = v113;
    v113 = stack[-5];
    if (v113 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v113 = stack[-5];
    v113 = qcar(v113);
    stack[-1] = v113;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v113 = stack[-1];
    v113 = qcar(v113);
    fn = elt(env, 2); /* mo_neg */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v114 = (*qfn2(fn))(qenv(fn), stack[0], v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    v113 = stack[-1];
    v113 = qcdr(v113);
    v113 = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    v113 = ncons(v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    v113 = Lrplacd(nil, stack[-2], v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-6];
    v113 = stack[-3];
    v113 = qcdr(v113);
    stack[-3] = v113;
    goto v106;

v98:
    v113 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v113); }
/* error exit handlers */
v115:
    popv(7);
    return nil;
}



/* Code for dfprintfn */

static Lisp_Object CC_dfprintfn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v66, v67;
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
    v37 = v0;
/* end of prologue */
    v66 = qvalue(elt(env, 1)); /* !*nat */
    if (v66 == nil) goto v68;
    v66 = qvalue(elt(env, 2)); /* !*fort */
    if (!(v66 == nil)) goto v68;
    v66 = qvalue(elt(env, 3)); /* !*dfprint */
    if (v66 == nil) goto v68;
    v66 = elt(env, 5); /* !!df!! */
    v37 = qcdr(v37);
    v67 = cons(v66, v37);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[0];
    v66 = (Lisp_Object)1; /* 0 */
    v37 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 7); /* layout!-formula */
    v37 = (*qfnn(fn))(qenv(fn), 3, v67, v66, v37);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[0];
    v66 = v37;
    v37 = v66;
    if (v37 == nil) goto v35;
    v37 = v66;
    fn = elt(env, 8); /* putpline */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v37 = nil;
    { popv(1); return onevalue(v37); }

v35:
    v37 = elt(env, 4); /* failed */
    { popv(1); return onevalue(v37); }

v68:
    v37 = elt(env, 4); /* failed */
    { popv(1); return onevalue(v37); }
/* error exit handlers */
v117:
    popv(1);
    return nil;
}



/* Code for cgp_mk */

static Lisp_Object MS_CDECL CC_cgp_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, Lisp_Object v102,
                         Lisp_Object v68, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v112, v38, v39, v47;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "cgp_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_mk");
#endif
    if (stack >= stacklimit)
    {
        push5(v68,v102,v90,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v90,v102,v68);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v71 = v68;
    v112 = v102;
    v38 = v90;
    v39 = v1;
    v47 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* cgp */
    stack[-1] = v47;
    stack[0] = v39;
    v71 = list3(v38, v112, v71);
    nil = C_nil;
    if (exception_pending()) goto v59;
    {
        Lisp_Object v35 = stack[-2];
        Lisp_Object v34 = stack[-1];
        Lisp_Object v60 = stack[0];
        popv(3);
        return list3star(v35, v34, v60, v71);
    }
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for omfir */

static Lisp_Object MS_CDECL CC_omfir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omfir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omfir");
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
    v47 = qvalue(elt(env, 1)); /* atts */
    v39 = elt(env, 2); /* dec */
    fn = elt(env, 5); /* find */
    v39 = (*qfn2(fn))(qenv(fn), v47, v39);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    stack[0] = v39;
    v47 = qvalue(elt(env, 1)); /* atts */
    v39 = elt(env, 3); /* name */
    fn = elt(env, 5); /* find */
    v39 = (*qfn2(fn))(qenv(fn), v47, v39);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    if (v39 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v47 = elt(env, 4); /* "wrong att" */
    v39 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v39 = (*qfn2(fn))(qenv(fn), v47, v39);
    nil = C_nil;
    if (exception_pending()) goto v77;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v77:
    popv(2);
    return nil;
}



/* Code for ps!:depvar */

static Lisp_Object CC_psTdepvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34, v60;
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
    v34 = v0;
/* end of prologue */
    v35 = v34;
    if (!consp(v35)) goto v68;
    v35 = v34;
    v60 = qcar(v35);
    v35 = elt(env, 1); /* !:ps!: */
    if (v60 == v35) goto v47;
    v35 = v34;
    v60 = qcar(v35);
    v35 = elt(env, 2); /* dname */
    v35 = get(v60, v35);
    env = stack[0];
    if (!(v35 == nil)) goto v68;

v47:
    v35 = (Lisp_Object)33; /* 2 */
    {
        popv(1);
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v34, v35);
    }

v68:
    v35 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v35); }
}



/* Code for insoccs */

static Lisp_Object CC_insoccs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insoccs");
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
    v76 = stack[-1];
    if (symbolp(v76)) goto v41;
    v76 = stack[-1];
    fn = elt(env, 2); /* subscriptedvarp */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (!(v76 == nil)) goto v41;
    v76 = stack[-1];
    v76 = Lconsp(nil, v76);
    env = stack[-2];
    if (v76 == nil) goto v107;
    v76 = stack[-1];
    v76 = qcar(v76);
    fn = elt(env, 2); /* subscriptedvarp */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (!(v76 == nil)) goto v41;

v107:
    v76 = stack[-1];
    if (symbolp(v76)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v76 = stack[-1];
    fn = elt(env, 3); /* constp */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (!(v76 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v76 = stack[-1];
    v76 = qcdr(v76);
    stack[-1] = v76;
    goto v69;

v69:
    v76 = stack[-1];
    if (v76 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v76 = stack[-1];
    v76 = qcar(v76);
    v118 = v76;
    v76 = stack[0];
    v76 = CC_insoccs(env, v118, v76);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    stack[0] = v76;
    v76 = stack[-1];
    v76 = qcdr(v76);
    stack[-1] = v76;
    goto v69;

v41:
    v118 = stack[0];
    v76 = stack[-1];
    fn = elt(env, 4); /* insertocc */
    v76 = (*qfn2(fn))(qenv(fn), v118, v76);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    stack[0] = v76;
    goto v107;
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



/* Code for smemberl */

static Lisp_Object CC_smemberl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemberl");
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
    goto v107;

v107:
    v37 = stack[-1];
    if (v37 == nil) goto v80;
    v37 = stack[0];
    if (v37 == nil) goto v80;
    v37 = stack[-1];
    v66 = qcar(v37);
    v37 = stack[0];
    fn = elt(env, 1); /* smember */
    v37 = (*qfn2(fn))(qenv(fn), v66, v37);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    if (v37 == nil) goto v35;
    v37 = stack[-1];
    v66 = qcar(v37);
    v37 = stack[-2];
    v37 = cons(v66, v37);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    stack[-2] = v37;
    v37 = stack[-1];
    v37 = qcdr(v37);
    stack[-1] = v37;
    goto v107;

v35:
    v37 = stack[-1];
    v37 = qcdr(v37);
    stack[-1] = v37;
    goto v107;

v80:
    v37 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v37);
    }
/* error exit handlers */
v108:
    popv(4);
    return nil;
}



/* Code for locate_member */

static Lisp_Object CC_locate_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34, v60, v69;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for locate_member");
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
    v60 = v1;
    v69 = v0;
/* end of prologue */
    v34 = v69;
    v35 = v60;
    v35 = Lmember(nil, v34, v35);
    if (v35 == nil) goto v46;
    v34 = v69;
    v35 = v60;
    v35 = qcar(v35);
    if (equal(v34, v35)) goto v65;
    v35 = v69;
    v34 = v60;
    v34 = qcdr(v34);
    v35 = CC_locate_member(env, v35, v34);
    errexit();
    return add1(v35);

v65:
    v35 = (Lisp_Object)17; /* 1 */
    return onevalue(v35);

v46:
    v35 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v35);
}



/* Code for rootextractf */

static Lisp_Object CC_rootextractf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v147, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootextractf");
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
    v146 = stack[-3];
    if (!consp(v146)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v146 = stack[-3];
    v146 = qcar(v146);
    if (!consp(v146)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v146 = stack[-3];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v146 = qcar(v146);
    stack[-4] = v146;
    v146 = stack[-3];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    stack[0] = v146;
    v146 = stack[-3];
    v146 = qcdr(v146);
    v146 = CC_rootextractf(env, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-2] = v146;
    v146 = stack[-3];
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = CC_rootextractf(env, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-1] = v146;
    v146 = stack[-1];
    if (v146 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v146 = stack[-4];
    if (!consp(v146)) goto v36;
    v146 = stack[-4];
    v147 = qcar(v146);
    v146 = elt(env, 1); /* sqrt */
    if (v147 == v146) goto v150;
    v146 = stack[-4];
    v147 = qcar(v146);
    v146 = elt(env, 2); /* expt */
    if (!(v147 == v146)) goto v151;
    v146 = stack[-4];
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    v147 = qcar(v146);
    v146 = elt(env, 3); /* quotient */
    if (!consp(v147)) goto v151;
    v147 = qcar(v147);
    if (!(v147 == v146)) goto v151;
    v146 = stack[-4];
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v147 = qcar(v146);
    v146 = (Lisp_Object)17; /* 1 */
    if (!(v147 == v146)) goto v151;
    v146 = stack[-4];
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    if (!(is_number(v146))) goto v151;

v150:
    v148 = stack[0];
    v146 = stack[-4];
    v147 = qcar(v146);
    v146 = elt(env, 1); /* sqrt */
    if (v147 == v146) goto v152;
    v146 = stack[-4];
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    goto v153;

v153:
    v146 = Ldivide(nil, v148, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[0] = v146;
    v146 = stack[0];
    v147 = qcar(v146);
    v146 = (Lisp_Object)1; /* 0 */
    if (v147 == v146) goto v154;
    v146 = stack[-4];
    v146 = qcdr(v146);
    v146 = qcar(v146);
    if (is_number(v146)) goto v52;
    v146 = stack[-4];
    v146 = qcdr(v146);
    v147 = qcar(v146);
    v146 = stack[0];
    v146 = qcar(v146);
    v146 = list2(v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    fn = elt(env, 4); /* simpexpt */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v148 = v146;
    v146 = v148;
    v147 = qcdr(v146);
    v146 = (Lisp_Object)17; /* 1 */
    if (v147 == v146) goto v155;
    v146 = stack[-3];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    stack[0] = v146;
    goto v151;

v151:
    v147 = stack[0];
    v146 = (Lisp_Object)1; /* 0 */
    if (v147 == v146) goto v156;
    v146 = stack[-1];
    if (v146 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v147 = stack[-4];
    v146 = stack[0];
    fn = elt(env, 5); /* to */
    v148 = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v147 = stack[-1];
    v146 = stack[-2];
    popv(6);
    return acons(v148, v147, v146);

v156:
    v147 = stack[-1];
    v146 = stack[-2];
    {
        popv(6);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v147, v146);
    }

v155:
    v146 = v148;
    v147 = qcar(v146);
    v146 = stack[-1];
    fn = elt(env, 7); /* multf */
    v146 = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-1] = v146;
    v146 = stack[0];
    v146 = qcdr(v146);
    stack[0] = v146;
    goto v151;

v52:
    v146 = stack[-4];
    v146 = qcdr(v146);
    v147 = qcar(v146);
    v146 = stack[0];
    v146 = qcar(v146);
    v147 = Lexpt(nil, v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v146 = stack[-1];
    fn = elt(env, 8); /* multd */
    v146 = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-1] = v146;
    v146 = stack[0];
    v146 = qcdr(v146);
    stack[0] = v146;
    goto v151;

v154:
    v146 = stack[-1];
    if (v146 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v146 = stack[-3];
    v146 = qcar(v146);
    v148 = qcar(v146);
    v147 = stack[-1];
    v146 = stack[-2];
    popv(6);
    return acons(v148, v147, v146);

v152:
    v146 = (Lisp_Object)33; /* 2 */
    goto v153;

v36:
    v146 = stack[-3];
    v146 = qcar(v146);
    v148 = qcar(v146);
    v147 = stack[-1];
    v146 = stack[-2];
    popv(6);
    return acons(v148, v147, v146);
/* error exit handlers */
v149:
    popv(6);
    return nil;
}



/* Code for reduce!-mod!-p!* */

static Lisp_Object CC_reduceKmodKpH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-p*");
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
    v106 = v1;
    v55 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* current!-modulus */
    qvalue(elt(env, 1)) = v106; /* current!-modulus */
    v106 = v55;
    fn = elt(env, 2); /* general!-reduce!-mod!-p */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* current!-modulus */
    { popv(2); return onevalue(v106); }
/* error exit handlers */
v57:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* current!-modulus */
    popv(2);
    return nil;
}



/* Code for gitimes!: */

static Lisp_Object CC_gitimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v30, v31, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gitimes:");
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
    v110 = v1;
    v30 = v0;
/* end of prologue */
    v31 = v30;
    v31 = qcdr(v31);
    v158 = qcar(v31);
    v30 = qcdr(v30);
    v31 = qcdr(v30);
    v30 = v110;
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v110 = qcdr(v110);
    v110 = qcdr(v110);
    stack[-4] = v158;
    stack[-3] = v31;
    stack[-2] = v30;
    stack[-1] = v110;
    v30 = stack[-4];
    v110 = stack[-2];
    stack[0] = times2(v30, v110);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v30 = stack[-3];
    v110 = stack[-1];
    v110 = times2(v30, v110);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    stack[0] = difference2(stack[0], v110);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v30 = stack[-4];
    v110 = stack[-1];
    stack[-1] = times2(v30, v110);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v30 = stack[-2];
    v110 = stack[-3];
    v110 = times2(v30, v110);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v110 = plus2(stack[-1], v110);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    {
        Lisp_Object v86 = stack[0];
        popv(6);
        fn = elt(env, 1); /* mkgi */
        return (*qfn2(fn))(qenv(fn), v86, v110);
    }
/* error exit handlers */
v92:
    popv(6);
    return nil;
}



/* Code for gen!+can!+bas */

static Lisp_Object CC_genLcanLbas(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v176;
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
    v176 = (Lisp_Object)17; /* 1 */
    v175 = (Lisp_Object)17; /* 1 */
    v175 = cons(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    stack[-10] = v175;
    v176 = qvalue(elt(env, 1)); /* nil */
    v175 = (Lisp_Object)17; /* 1 */
    v175 = cons(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    stack[-8] = v175;
    v175 = (Lisp_Object)17; /* 1 */
    stack[-7] = v175;
    v176 = stack[-9];
    v175 = stack[-7];
    v175 = difference2(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lminusp(nil, v175);
    env = stack[-11];
    if (v175 == nil) goto v39;
    v175 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v175); }

v39:
    v175 = (Lisp_Object)17; /* 1 */
    stack[-3] = v175;
    v176 = stack[-9];
    v175 = stack[-3];
    v175 = difference2(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lminusp(nil, v175);
    env = stack[-11];
    if (v175 == nil) goto v109;
    v175 = qvalue(elt(env, 1)); /* nil */
    goto v73;

v73:
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    stack[-5] = v175;
    stack[-6] = v175;
    goto v71;

v71:
    v175 = stack[-7];
    v175 = add1(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    stack[-7] = v175;
    v176 = stack[-9];
    v175 = stack[-7];
    v175 = difference2(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lminusp(nil, v175);
    env = stack[-11];
    if (!(v175 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    v175 = (Lisp_Object)17; /* 1 */
    stack[-3] = v175;
    v176 = stack[-9];
    v175 = stack[-3];
    v175 = difference2(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lminusp(nil, v175);
    env = stack[-11];
    if (v175 == nil) goto v178;
    v175 = qvalue(elt(env, 1)); /* nil */
    goto v13;

v13:
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lrplacd(nil, stack[-4], v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = stack[-5];
    v175 = qcdr(v175);
    stack[-5] = v175;
    goto v71;

v178:
    v176 = stack[-7];
    v175 = stack[-3];
    if (equal(v176, v175)) goto v140;
    v175 = stack[-8];
    goto v138;

v138:
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    stack[-1] = v175;
    stack[-2] = v175;
    goto v179;

v179:
    v175 = stack[-3];
    v175 = add1(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    stack[-3] = v175;
    v176 = stack[-9];
    v175 = stack[-3];
    v175 = difference2(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lminusp(nil, v175);
    env = stack[-11];
    if (v175 == nil) goto v180;
    v175 = stack[-2];
    goto v13;

v180:
    stack[0] = stack[-1];
    v176 = stack[-7];
    v175 = stack[-3];
    if (equal(v176, v175)) goto v134;
    v175 = stack[-8];
    goto v181;

v181:
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lrplacd(nil, stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = stack[-1];
    v175 = qcdr(v175);
    stack[-1] = v175;
    goto v179;

v134:
    v175 = stack[-10];
    goto v181;

v140:
    v175 = stack[-10];
    goto v138;

v109:
    v176 = stack[-7];
    v175 = stack[-3];
    if (equal(v176, v175)) goto v31;
    v175 = stack[-8];
    goto v30;

v30:
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    stack[-1] = v175;
    stack[-2] = v175;
    goto v108;

v108:
    v175 = stack[-3];
    v175 = add1(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    stack[-3] = v175;
    v176 = stack[-9];
    v175 = stack[-3];
    v175 = difference2(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lminusp(nil, v175);
    env = stack[-11];
    if (v175 == nil) goto v74;
    v175 = stack[-2];
    goto v73;

v74:
    stack[0] = stack[-1];
    v176 = stack[-7];
    v175 = stack[-3];
    if (equal(v176, v175)) goto v23;
    v175 = stack[-8];
    goto v22;

v22:
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = Lrplacd(nil, stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-11];
    v175 = stack[-1];
    v175 = qcdr(v175);
    stack[-1] = v175;
    goto v108;

v23:
    v175 = stack[-10];
    goto v22;

v31:
    v175 = stack[-10];
    goto v30;
/* error exit handlers */
v177:
    popv(12);
    return nil;
}



/* Code for cgp_number */

static Lisp_Object CC_cgp_number(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_number");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */
    v98 = v57;
    v57 = (Lisp_Object)81; /* 5 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v98, v57);
    }
}



/* Code for lambdafun */

static Lisp_Object CC_lambdafun(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdafun");
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
    v106 = v0;
/* end of prologue */
    v106 = Lreverse(nil, v106);
    errexit();
    v106 = qcar(v106);
    return onevalue(v106);
}



/* Code for reform!-minus */

static Lisp_Object CC_reformKminus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v184, v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reform-minus");
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
    v183 = stack[0];
    if (v183 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v183 = stack[-1];
    if (v183 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v183 = stack[-1];
    v183 = qcar(v183);
    v184 = stack[0];
    v99 = qcar(v184);
    v184 = elt(env, 1); /* minus */
    if (!consp(v99)) goto v49;
    v99 = qcar(v99);
    if (!(v99 == v184)) goto v49;
    v99 = v183;
    v184 = elt(env, 2); /* quotient */
    if (!consp(v99)) goto v49;
    v99 = qcar(v99);
    if (!(v99 == v184)) goto v49;
    v184 = v183;
    v184 = qcdr(v184);
    v99 = qcar(v184);
    v184 = elt(env, 1); /* minus */
    if (!consp(v99)) goto v49;
    v99 = qcar(v99);
    if (!(v99 == v184)) goto v49;
    stack[-2] = elt(env, 1); /* minus */
    v99 = elt(env, 2); /* quotient */
    v184 = v183;
    v184 = qcdr(v184);
    v184 = qcar(v184);
    v184 = qcdr(v184);
    v184 = qcar(v184);
    v183 = qcdr(v183);
    v183 = qcdr(v183);
    v183 = qcar(v183);
    v183 = list3(v99, v184, v183);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    v183 = list2(stack[-2], v183);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    stack[-2] = v183;
    goto v93;

v93:
    v183 = stack[-1];
    v184 = qcdr(v183);
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = CC_reformKminus(env, v184, v183);
    nil = C_nil;
    if (exception_pending()) goto v74;
    {
        Lisp_Object v20 = stack[-2];
        popv(4);
        return cons(v20, v183);
    }

v49:
    stack[-2] = v183;
    goto v93;
/* error exit handlers */
v74:
    popv(4);
    return nil;
}



/* Code for r2findindex */

static Lisp_Object CC_r2findindex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v81, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2findindex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v1;
    v81 = v0;
/* end of prologue */
    v65 = v81;
    v81 = v124;
    v124 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* r2findindex1 */
        return (*qfnn(fn))(qenv(fn), 3, v65, v81, v124);
    }
}



/* Code for mo_2a */

static Lisp_Object CC_mo_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_2a");
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
    v42 = v0;
/* end of prologue */
    stack[0] = qcar(v42);
    v42 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 2); /* ring_all_names */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    {
        Lisp_Object v81 = stack[0];
        popv(2);
        fn = elt(env, 3); /* mo!=expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v81, v42);
    }
/* error exit handlers */
v124:
    popv(2);
    return nil;
}



/* Code for dv_ind2var */

static Lisp_Object CC_dv_ind2var(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_ind2var");
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
    stack[-1] = stack[0];
    v47 = qvalue(elt(env, 1)); /* g_dvnames */
    fn = elt(env, 3); /* upbve */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v47 = (Lisp_Object)lesseq2(stack[-1], v47);
    nil = C_nil;
    if (exception_pending()) goto v59;
    v47 = v47 ? lisp_true : nil;
    env = stack[-2];
    if (v47 == nil) goto v63;
    stack[-1] = qvalue(elt(env, 1)); /* g_dvnames */
    v47 = stack[0];
    v47 = sub1(v47);
    nil = C_nil;
    if (exception_pending()) goto v59;
    v47 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v47/(16/CELL)));
    { popv(3); return onevalue(v47); }

v63:
    v116 = qvalue(elt(env, 2)); /* g_dvbase */
    v47 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v116, v47);
    }
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for rootrnd */

static Lisp_Object CC_rootrnd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootrnd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */
    v98 = v57;
    v57 = qvalue(elt(env, 1)); /* acc!# */
    {
        fn = elt(env, 2); /* rtrnda */
        return (*qfn2(fn))(qenv(fn), v98, v57);
    }
}



/* Code for termorder */

static Lisp_Object CC_termorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termorder");
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
    v110 = stack[-1];
    if (v110 == nil) goto v55;
    v110 = stack[-1];
    v110 = (Lisp_Object)zerop(v110);
    v110 = v110 ? lisp_true : nil;
    env = stack[-3];
    if (v110 == nil) goto v124;
    v110 = stack[0];
    v110 = (Lisp_Object)zerop(v110);
    v110 = v110 ? lisp_true : nil;
    env = stack[-3];
    if (!(v110 == nil)) goto v55;

v124:
    v110 = stack[-1];
    v110 = (Lisp_Object)zerop(v110);
    v110 = v110 ? lisp_true : nil;
    env = stack[-3];
    if (!(v110 == nil)) goto v55;
    v110 = stack[0];
    v110 = (Lisp_Object)zerop(v110);
    v110 = v110 ? lisp_true : nil;
    env = stack[-3];
    if (!(v110 == nil)) goto v55;

v55:
    v110 = stack[-1];
    fn = elt(env, 1); /* listsum */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    stack[-2] = v110;
    v110 = stack[0];
    fn = elt(env, 1); /* listsum */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    v31 = v110;
    v30 = stack[-2];
    v110 = v31;
    if (equal(v30, v110)) goto v66;
    v110 = stack[-2];
    v30 = v31;
    v110 = (Lisp_Object)lessp2(v110, v30);
    nil = C_nil;
    if (exception_pending()) goto v185;
    v110 = v110 ? lisp_true : nil;
    if (v110 == nil) goto v118;
    v110 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v110); }

v118:
    v110 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v110); }

v66:
    v30 = stack[-1];
    v110 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* termorder1 */
        return (*qfn2(fn))(qenv(fn), v30, v110);
    }
/* error exit handlers */
v185:
    popv(4);
    return nil;
}



/* Code for lastnondomain */

static Lisp_Object CC_lastnondomain(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lastnondomain");
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

v68:
    v59 = v58;
    if (!consp(v59)) goto v65;
    v59 = v58;
    v59 = qcar(v59);
    if (!consp(v59)) goto v65;
    v59 = v58;
    v59 = qcdr(v59);
    if (!consp(v59)) { popv(1); return onevalue(v58); }
    v59 = v58;
    v59 = qcdr(v59);
    v59 = qcar(v59);
    if (!consp(v59)) { popv(1); return onevalue(v58); }
    v58 = qcdr(v58);
    goto v68;

v65:
    v59 = elt(env, 1); /* "non-domain" */
    v58 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* errach */
        return (*qfn1(fn))(qenv(fn), v58);
    }
/* error exit handlers */
v35:
    popv(1);
    return nil;
}



/* Code for plusdf */

static Lisp_Object CC_plusdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v188, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plusdf");
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
    stack[0] = nil;
    goto v107;

v107:
    v187 = stack[-2];
    if (v187 == nil) goto v43;
    v187 = stack[-1];
    if (v187 == nil) goto v103;
    v187 = stack[-2];
    v187 = qcar(v187);
    v188 = qcar(v187);
    v187 = stack[-1];
    v187 = qcar(v187);
    v187 = qcar(v187);
    if (equal(v188, v187)) goto v61;
    v187 = stack[-2];
    v187 = qcar(v187);
    v188 = qcar(v187);
    v187 = stack[-1];
    v187 = qcar(v187);
    v187 = qcar(v187);
    fn = elt(env, 1); /* orddf */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    if (v187 == nil) goto v191;
    v187 = stack[-2];
    v188 = qcar(v187);
    v187 = stack[0];
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    stack[0] = v187;
    v187 = stack[-2];
    v187 = qcdr(v187);
    stack[-2] = v187;
    goto v107;

v191:
    v187 = stack[-1];
    v188 = qcar(v187);
    v187 = stack[0];
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    stack[0] = v187;
    v187 = stack[-1];
    v187 = qcdr(v187);
    stack[-1] = v187;
    goto v107;

v61:
    stack[-3] = stack[0];
    v187 = stack[-2];
    v187 = qcar(v187);
    v188 = qcdr(v187);
    v187 = stack[-1];
    v187 = qcar(v187);
    v187 = qcdr(v187);
    fn = elt(env, 2); /* !*addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    v187 = stack[-2];
    v188 = qcdr(v187);
    v187 = stack[-1];
    v187 = qcdr(v187);
    v187 = CC_plusdf(env, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    v188 = stack[0];
    v189 = v188;
    v189 = qcar(v189);
    if (v189 == nil) goto v66;
    v189 = stack[-2];
    v189 = qcar(v189);
    v189 = qcar(v189);
    v187 = acons(v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    goto v66;

v66:
    {
        Lisp_Object v154 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v154, v187);
    }

v103:
    v188 = stack[0];
    v187 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v188, v187);
    }

v43:
    v188 = stack[0];
    v187 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v188, v187);
    }
/* error exit handlers */
v190:
    popv(5);
    return nil;
}



/* Code for replace1_parents */

static Lisp_Object MS_CDECL CC_replace1_parents(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v56, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace1_parents");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace1_parents");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v83 = v90;
    v56 = v1;
    v82 = v0;
/* end of prologue */
    v82 = qcar(v82);
    v56 = qcar(v56);
    v83 = qcdr(v83);
    v83 = qcar(v83);
    {
        fn = elt(env, 1); /* replace2_parents */
        return (*qfnn(fn))(qenv(fn), 3, v82, v56, v83);
    }
}



/* Code for simp!-prop2 */

static Lisp_Object CC_simpKprop2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop2");
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
    stack[-5] = v0;
/* end of prologue */
    v165 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-1] = v165;
    goto v124;

v124:
    v165 = stack[-1];
    if (v165 == nil) goto v43;
    v165 = stack[-1];
    v165 = qcar(v165);
    stack[0] = v165;
    v165 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v165;
    goto v53;

v53:
    v165 = stack[-5];
    if (v165 == nil) goto v63;
    v165 = stack[-5];
    v165 = qcar(v165);
    stack[-3] = v165;
    v165 = stack[-5];
    v165 = qcdr(v165);
    stack[-5] = v165;
    v166 = elt(env, 3); /* prop!* */
    v165 = stack[0];
    v165 = list2(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    stack[-4] = v165;
    v166 = elt(env, 4); /* not_prop!* */
    v165 = stack[0];
    v165 = list2(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    v141 = v165;
    v166 = stack[-4];
    v165 = stack[-3];
    v165 = Lmember(nil, v166, v165);
    if (!(v165 == nil)) goto v109;
    v165 = v141;
    v166 = stack[-4];
    v141 = v166;
    stack[-4] = v165;
    goto v109;

v109:
    v166 = stack[-4];
    v165 = stack[-3];
    v165 = Lsubst(nil, 3, v141, v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    stack[-6] = v165;
    v166 = stack[-3];
    v165 = stack[-2];
    v165 = cons(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    stack[-2] = v165;
    v166 = stack[-6];
    v165 = stack[-5];
    v165 = Lmember(nil, v166, v165);
    stack[-6] = v165;
    if (v165 == nil) goto v53;
    v165 = stack[-6];
    if (v165 == nil) goto v191;
    v165 = stack[-6];
    v166 = qcar(v165);
    v165 = stack[-5];
    v165 = Ldelete(nil, v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    stack[-5] = v165;
    v165 = stack[-6];
    v166 = qcar(v165);
    v165 = stack[-2];
    v165 = cons(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    stack[-2] = v165;
    goto v191;

v191:
    v166 = stack[-4];
    v165 = stack[-3];
    v165 = Ldelete(nil, v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    stack[-3] = v165;
    v165 = stack[-3];
    v166 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    v165 = stack[-2];
    fn = elt(env, 5); /* union */
    v165 = (*qfn2(fn))(qenv(fn), v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-7];
    stack[-2] = v165;
    goto v53;

v63:
    v165 = stack[-2];
    stack[-5] = v165;
    v165 = stack[-1];
    v165 = qcdr(v165);
    stack[-1] = v165;
    goto v124;

v43:
    v165 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); /* simp!-prop!-condense */
        return (*qfn1(fn))(qenv(fn), v165);
    }
/* error exit handlers */
v14:
    popv(8);
    return nil;
}



/* Code for deginvar */

static Lisp_Object CC_deginvar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deginvar");
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
    v32 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    if (v32 == nil) goto v42;
    v32 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v32); }

v42:
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcar(v32);
    v33 = qcar(v32);
    v32 = stack[0];
    if (equal(v33, v32)) goto v57;
    stack[-2] = qvalue(elt(env, 1)); /* kord!* */
    qvalue(elt(env, 1)) = nil; /* kord!* */
    v32 = stack[0];
    v32 = ncons(v32);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    qvalue(elt(env, 1)) = v32; /* kord!* */
    v32 = stack[-1];
    fn = elt(env, 3); /* reorder */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    stack[-1] = v32;
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcar(v32);
    v33 = qcar(v32);
    v32 = stack[0];
    if (equal(v33, v32)) goto v58;
    v32 = (Lisp_Object)1; /* 0 */
    goto v71;

v71:
    qvalue(elt(env, 1)) = stack[-2]; /* kord!* */
    { popv(4); return onevalue(v32); }

v58:
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcar(v32);
    v32 = qcdr(v32);
    goto v71;

v57:
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcar(v32);
    v32 = qcdr(v32);
    { popv(4); return onevalue(v32); }
/* error exit handlers */
v95:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* kord!* */
    popv(4);
    return nil;
v94:
    popv(4);
    return nil;
}



/* Code for evallessp */

static Lisp_Object CC_evallessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evallessp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v42 = v1;
    v98 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* evalgreaterp */
        return (*qfn2(fn))(qenv(fn), v42, v98);
    }
}



/* Code for mk!+real!+inner!+product */

static Lisp_Object CC_mkLrealLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+real+inner+product");
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
    v93 = stack[-3];
    fn = elt(env, 5); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v93 = stack[-2];
    fn = elt(env, 5); /* get!+vec!+dim */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    if (equal(stack[0], v93)) goto v41;
    v93 = elt(env, 1); /* "wrong dimensions in innerproduct" */
    fn = elt(env, 6); /* rederr */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v41;

v41:
    v25 = qvalue(elt(env, 2)); /* nil */
    v93 = (Lisp_Object)17; /* 1 */
    v93 = cons(v25, v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[0] = v93;
    v93 = (Lisp_Object)17; /* 1 */
    stack[-4] = v93;
    goto v60;

v60:
    v93 = stack[-3];
    fn = elt(env, 5); /* get!+vec!+dim */
    v25 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v93 = stack[-4];
    v93 = difference2(v25, v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v93 = Lminusp(nil, v93);
    env = stack[-5];
    if (v93 == nil) goto v73;
    v93 = qvalue(elt(env, 3)); /* t */
    stack[-1] = qvalue(elt(env, 4)); /* !*sub2 */
    qvalue(elt(env, 4)) = v93; /* !*sub2 */
    v93 = stack[0];
    fn = elt(env, 7); /* subs2 */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-5];
    stack[0] = v93;
    qvalue(elt(env, 4)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v73:
    stack[-1] = stack[0];
    v25 = stack[-3];
    v93 = stack[-4];
    fn = elt(env, 8); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v25, v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v25 = stack[-2];
    v93 = stack[-4];
    fn = elt(env, 8); /* get!+vec!+entry */
    v93 = (*qfn2(fn))(qenv(fn), v25, v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    fn = elt(env, 9); /* multsq */
    v93 = (*qfn2(fn))(qenv(fn), stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    fn = elt(env, 10); /* addsq */
    v93 = (*qfn2(fn))(qenv(fn), stack[-1], v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[0] = v93;
    v93 = stack[-4];
    v93 = add1(v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[-4] = v93;
    goto v60;
/* error exit handlers */
v182:
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v8:
    popv(6);
    return nil;
}



/* Code for lambdavar */

static Lisp_Object CC_lambdavar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdavar");
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
    v89 = v0;
/* end of prologue */
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = Lreverse(nil, v89);
    errexit();
    v89 = qcdr(v89);
    return onevalue(v89);
}



/* Code for make!-unique!-freevars */

static Lisp_Object CC_makeKuniqueKfreevars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v150, v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-unique-freevars");
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
    v150 = v0;
/* end of prologue */
    v198 = v150;
    if (!consp(v198)) goto v42;
    v198 = v150;
    stack[-3] = v198;
    v198 = stack[-3];
    if (v198 == nil) goto v86;
    v198 = stack[-3];
    v198 = qcar(v198);
    v198 = CC_makeKuniqueKfreevars(env, v198);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    stack[-1] = v198;
    stack[-2] = v198;
    goto v185;

v185:
    v198 = stack[-3];
    v198 = qcdr(v198);
    stack[-3] = v198;
    v198 = stack[-3];
    if (v198 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v198 = stack[-3];
    v198 = qcar(v198);
    v198 = CC_makeKuniqueKfreevars(env, v198);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    v198 = Lrplacd(nil, stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    v198 = stack[-1];
    v198 = qcdr(v198);
    stack[-1] = v198;
    goto v185;

v86:
    v198 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v198); }

v42:
    v195 = v150;
    v198 = elt(env, 1); /* gen */
    v198 = get(v195, v198);
    env = stack[-4];
    if (v198 == nil) { popv(5); return onevalue(v150); }
    v195 = v150;
    v198 = qvalue(elt(env, 2)); /* freevarlist!* */
    v198 = Latsoc(nil, v195, v198);
    stack[0] = v198;
    v198 = stack[0];
    if (!(v198 == nil)) goto v112;
    stack[0] = v150;
    fn = elt(env, 5); /* pm!:gensym */
    v198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    v198 = cons(stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    stack[0] = v198;
    v198 = stack[0];
    v195 = qcdr(v198);
    v150 = elt(env, 1); /* gen */
    v198 = qvalue(elt(env, 3)); /* t */
    v198 = Lputprop(nil, 3, v195, v150, v198);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    v150 = stack[0];
    v198 = qvalue(elt(env, 2)); /* freevarlist!* */
    v198 = cons(v150, v198);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-4];
    qvalue(elt(env, 2)) = v198; /* freevarlist!* */
    goto v112;

v112:
    v198 = stack[0];
    v198 = qcdr(v198);
    { popv(5); return onevalue(v198); }
/* error exit handlers */
v142:
    popv(5);
    return nil;
}



/* Code for f2dip11 */

static Lisp_Object CC_f2dip11(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip11");
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

v72:
    v96 = qvalue(elt(env, 1)); /* !*notestparameters */
    if (!(v96 == nil)) { popv(2); return onevalue(v96); }
    v97 = stack[0];
    v96 = qvalue(elt(env, 2)); /* vdpvars!* */
    v96 = Lmember(nil, v97, v96);
    if (v96 == nil) goto v106;
    v97 = stack[0];
    v96 = elt(env, 3); /* "occurs in a parameter and is member of the groebner variables." 
*/
    v96 = list2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    fn = elt(env, 6); /* rederr */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    goto v106;

v106:
    v96 = stack[0];
    if (!consp(v96)) goto v77;
    v96 = stack[0];
    v96 = qcar(v96);
    v96 = CC_f2dip11(env, v96);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    v96 = stack[0];
    v96 = qcdr(v96);
    stack[0] = v96;
    goto v72;

v77:
    v97 = stack[0];
    v96 = elt(env, 4); /* list */
    if (v97 == v96) goto v47;
    v96 = nil;
    { popv(2); return onevalue(v96); }

v47:
    v96 = elt(env, 5); /* "groebner: LIST not allowed." */
    {
        popv(2);
        fn = elt(env, 6); /* rederr */
        return (*qfn1(fn))(qenv(fn), v96);
    }
/* error exit handlers */
v32:
    popv(2);
    return nil;
}



/* Code for eqexpr */

static Lisp_Object CC_eqexpr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v47, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eqexpr");
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
    v47 = v0;
/* end of prologue */
    v39 = v47;
    if (!consp(v39)) goto v68;
    v39 = v47;
    v116 = qcar(v39);
    v39 = elt(env, 2); /* equalopr */
    v39 = Lflagp(nil, v116, v39);
    env = stack[0];
    if (v39 == nil) goto v55;
    v39 = v47;
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    if (v39 == nil) goto v56;
    v39 = v47;
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    v39 = (v39 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v39); }

v56:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v39); }

v55:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v39); }

v68:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v39); }
}



/* Code for numprintlen */

static Lisp_Object CC_numprintlen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v208;
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

v68:
    v135 = stack[-1];
    if (!consp(v135)) goto v106;
    v135 = stack[-1];
    v135 = Llength(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = Lonep(nil, v135);
    env = stack[-6];
    if (v135 == nil) goto v40;
    v135 = stack[-1];
    v135 = qcar(v135);
    stack[-1] = v135;
    goto v68;

v40:
    v135 = stack[-1];
    v208 = qcar(v135);
    v135 = elt(env, 1); /* !:rd!: */
    if (v208 == v135) goto v56;
    v135 = stack[-1];
    v208 = qcar(v135);
    v135 = elt(env, 2); /* (!:cr!: !:crn!: !:gi!:) */
    v135 = Lmemq(nil, v208, v135);
    if (v135 == nil) goto v172;
    v208 = elt(env, 1); /* !:rd!: */
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcar(v135);
    v135 = cons(v208, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    fn = elt(env, 5); /* rd!:explode */
    stack[0] = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v208 = elt(env, 1); /* !:rd!: */
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = cons(v208, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    fn = elt(env, 5); /* rd!:explode */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = cons(stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-1] = v135;
    stack[-4] = (Lisp_Object)193; /* 12 */
    v135 = stack[-1];
    v135 = qcar(v135);
    v135 = qcar(v135);
    stack[-3] = Llength(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = stack[-1];
    v135 = qcar(v135);
    v135 = qcdr(v135);
    v135 = Lexplode(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-2] = Llength(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcar(v135);
    stack[0] = Llength(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = Lexplode(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = Llength(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = plus2(stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = plus2(stack[-2], v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = plus2(stack[-3], v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v210 = stack[-4];
        popv(7);
        return plus2(v210, v135);
    }

v172:
    v135 = stack[-1];
    stack[-5] = Llength(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-4] = elt(env, 3); /* plus */
    v135 = stack[-1];
    v135 = qcdr(v135);
    stack[-3] = v135;
    v135 = stack[-3];
    if (v135 == nil) goto v211;
    v135 = stack[-3];
    v135 = qcar(v135);
    v135 = CC_numprintlen(env, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-1] = v135;
    stack[-2] = v135;
    goto v212;

v212:
    v135 = stack[-3];
    v135 = qcdr(v135);
    stack[-3] = v135;
    v135 = stack[-3];
    if (v135 == nil) goto v213;
    stack[0] = stack[-1];
    v135 = stack[-3];
    v135 = qcar(v135);
    v135 = CC_numprintlen(env, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = Lrplacd(nil, stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = stack[-1];
    v135 = qcdr(v135);
    stack[-1] = v135;
    goto v212;

v213:
    v135 = stack[-2];
    goto v166;

v166:
    v135 = cons(stack[-4], v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    fn = elt(env, 6); /* lispeval */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v214 = stack[-5];
        popv(7);
        return plus2(v214, v135);
    }

v211:
    v135 = qvalue(elt(env, 4)); /* nil */
    goto v166;

v56:
    v135 = stack[-1];
    fn = elt(env, 5); /* rd!:explode */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-1] = v135;
    stack[-2] = (Lisp_Object)33; /* 2 */
    v135 = stack[-1];
    v135 = qcar(v135);
    stack[0] = Llength(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcar(v135);
    v135 = Lexplode(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = Llength(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v135 = plus2(stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v215 = stack[-2];
        popv(7);
        return plus2(v215, v135);
    }

v106:
    v135 = stack[-1];
    v135 = Lexplode(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v209;
        popv(7);
        return Llength(nil, v135);
/* error exit handlers */
v209:
    popv(7);
    return nil;
}



/* Code for getphystypecar */

static Lisp_Object CC_getphystypecar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypecar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v0;
/* end of prologue */
    v43 = v124;
    if (!consp(v43)) goto v68;
    v43 = v124;
    v43 = qcar(v43);
    {
        fn = elt(env, 2); /* getphystype */
        return (*qfn1(fn))(qenv(fn), v43);
    }

v68:
    v43 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v43);
}



/* Code for remchkf */

static Lisp_Object MS_CDECL CC_remchkf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "remchkf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remchkf");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v90;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v33 = stack[-2];
    v32 = stack[-1];
    fn = elt(env, 1); /* remchkf1 */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    stack[-3] = v32;
    v32 = stack[-3];
    if (!consp(v32)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v32 = stack[-3];
    v32 = qcar(v32);
    if (!consp(v32)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v32 = stack[-2];
    fn = elt(env, 2); /* kernels */
    v33 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    v32 = stack[0];
    fn = elt(env, 3); /* intersection */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    if (v32 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v32 = stack[-3];
    stack[-2] = qcar(v32);
    v32 = stack[-3];
    v48 = qcdr(v32);
    v33 = stack[-1];
    v32 = stack[0];
    v32 = CC_remchkf(env, 3, v48, v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    {
        Lisp_Object v28 = stack[-2];
        popv(5);
        return cons(v28, v32);
    }
/* error exit handlers */
v29:
    popv(5);
    return nil;
}



/* Code for subcare */

static Lisp_Object MS_CDECL CC_subcare(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v92, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subcare");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subcare");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v90;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v106;

v106:
    v114 = stack[0];
    if (v114 == nil) goto v57;
    v92 = stack[-2];
    v114 = stack[0];
    if (equal(v92, v114)) goto v111;
    v114 = stack[0];
    if (!consp(v114)) goto v37;
    v114 = stack[0];
    v92 = qcar(v114);
    v114 = elt(env, 1); /* subfunc */
    v114 = get(v92, v114);
    env = stack[-4];
    if (!(v114 == nil)) goto v37;
    v86 = stack[-2];
    v92 = stack[-1];
    v114 = stack[0];
    v114 = qcar(v114);
    v92 = CC_subcare(env, 3, v86, v92, v114);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v114 = stack[-3];
    v114 = cons(v92, v114);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    stack[-3] = v114;
    v114 = stack[0];
    v114 = qcdr(v114);
    stack[0] = v114;
    goto v106;

v37:
    v92 = stack[-3];
    v114 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v92, v114);
    }

v111:
    v92 = stack[-3];
    v114 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v92, v114);
    }

v57:
    v114 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v114);
    }
/* error exit handlers */
v115:
    popv(5);
    return nil;
}



/* Code for red_tailreddriver */

static Lisp_Object MS_CDECL CC_red_tailreddriver(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_tailreddriver");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_tailreddriver");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v90;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v36 = stack[-2];
    fn = elt(env, 2); /* bas_dpoly */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    if (v36 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v36 = stack[-2];
    fn = elt(env, 2); /* bas_dpoly */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    v36 = qcdr(v36);
    if (v36 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v36 = stack[-3];
    if (v36 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    else goto v103;

v103:
    v36 = stack[-2];
    fn = elt(env, 2); /* bas_dpoly */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    if (v36 == nil) goto v41;
    stack[-4] = stack[-1];
    stack[0] = stack[-3];
    v36 = stack[-2];
    fn = elt(env, 3); /* red!=hidelt */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    v36 = Lapply2(nil, 3, stack[-4], stack[0], v36);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    stack[-2] = v36;
    goto v103;

v41:
    v36 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* red!=recover */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v108:
    popv(6);
    return nil;
}



/* Code for ad_splitname */

static Lisp_Object CC_ad_splitname(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v76;
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
    v76 = v0;
/* end of prologue */
    v28 = v76;
    if (symbolp(v28)) goto v68;
    v28 = nil;
    { popv(3); return onevalue(v28); }

v68:
    stack[0] = nil;
    v28 = v76;
    v28 = Lexplode(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v28 = Lreverse(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    stack[-1] = v28;
    goto v65;

v65:
    v28 = stack[-1];
    if (v28 == nil) goto v81;
    v28 = stack[-1];
    v28 = qcar(v28);
    fn = elt(env, 2); /* charnump!: */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    if (v28 == nil) goto v81;
    v28 = stack[-1];
    v76 = qcar(v28);
    v28 = stack[0];
    v28 = cons(v76, v28);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    stack[0] = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v65;

v81:
    v28 = stack[-1];
    if (v28 == nil) goto v60;
    v28 = stack[-1];
    v28 = Lreverse(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v28 = Lcompress(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v28 = Lintern(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    stack[-1] = v28;
    goto v60;

v60:
    v28 = stack[0];
    if (v28 == nil) goto v33;
    v28 = stack[0];
    v28 = Lcompress(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v85;
    stack[0] = v28;
    goto v33;

v33:
    v76 = stack[-1];
    v28 = stack[0];
    popv(3);
    return cons(v76, v28);
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for general!-ordered!-gcd!-mod!-p */

static Lisp_Object CC_generalKorderedKgcdKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-ordered-gcd-mod-p");
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
    v186 = (Lisp_Object)1; /* 0 */
    stack[-2] = v186;
    goto v89;

v89:
    v185 = stack[-1];
    v186 = stack[0];
    fn = elt(env, 2); /* general!-reduce!-degree!-mod!-p */
    v186 = (*qfn2(fn))(qenv(fn), v185, v186);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    stack[-1] = v186;
    v186 = stack[-1];
    if (v186 == nil) goto v70;
    v186 = stack[-2];
    v186 = add1(v186);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    stack[-2] = v186;
    v186 = stack[-1];
    if (!consp(v186)) goto v116;
    v186 = stack[-1];
    v186 = qcar(v186);
    if (!consp(v186)) goto v116;
    v186 = stack[-1];
    v186 = qcar(v186);
    v186 = qcar(v186);
    v185 = qcdr(v186);
    v186 = stack[0];
    v186 = qcar(v186);
    v186 = qcar(v186);
    v186 = qcdr(v186);
    v186 = (Lisp_Object)lessp2(v185, v186);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v186 = v186 ? lisp_true : nil;
    env = stack[-3];
    if (v186 == nil) goto v89;
    v185 = qvalue(elt(env, 1)); /* reduction!-count */
    v186 = stack[-2];
    v186 = plus2(v185, v186);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    qvalue(elt(env, 1)) = v186; /* reduction!-count */
    v186 = (Lisp_Object)1; /* 0 */
    stack[-2] = v186;
    v186 = stack[-1];
    v185 = v186;
    v186 = stack[0];
    stack[-1] = v186;
    v186 = v185;
    stack[0] = v186;
    goto v89;

v116:
    v185 = qvalue(elt(env, 1)); /* reduction!-count */
    v186 = stack[-2];
    v186 = plus2(v185, v186);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    qvalue(elt(env, 1)) = v186; /* reduction!-count */
    v186 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v186); }

v70:
    v186 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* general!-monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v186);
    }
/* error exit handlers */
v86:
    popv(4);
    return nil;
}



/* Code for ofsf_entry2at1 */

static Lisp_Object MS_CDECL CC_ofsf_entry2at1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at1");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v90;
    stack[-1] = v1;
    v35 = v0;
/* end of prologue */
    v34 = stack[-1];
    v60 = qcar(v34);
    v34 = v35;
    v35 = elt(env, 1); /* and */
    v35 = (v34 == v35 ? lisp_true : nil);
    fn = elt(env, 3); /* ofsf_clnegrel */
    stack[-2] = (*qfn2(fn))(qenv(fn), v60, v35);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    v34 = stack[0];
    v35 = stack[-1];
    v35 = qcdr(v35);
    fn = elt(env, 4); /* addsq */
    v35 = (*qfn2(fn))(qenv(fn), v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    v35 = qcar(v35);
    v34 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v36 = stack[-2];
        popv(4);
        return list3(v36, v35, v34);
    }
/* error exit handlers */
v61:
    popv(4);
    return nil;
}



/* Code for rl_qefsolset */

static Lisp_Object MS_CDECL CC_rl_qefsolset(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, Lisp_Object v102,
                         Lisp_Object v68, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v116, v77, v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rl_qefsolset");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_qefsolset");
#endif
    if (stack >= stacklimit)
    {
        push5(v68,v102,v90,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v90,v102,v68);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v47 = v68;
    v116 = v102;
    v77 = v90;
    v58 = v1;
    v59 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* rl_qefsolset!* */
    stack[-2] = v59;
    stack[-1] = v58;
    stack[0] = v77;
    v47 = list2(v116, v47);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    v47 = list3star(stack[-2], stack[-1], stack[0], v47);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    {
        Lisp_Object v174 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v174, v47);
    }
/* error exit handlers */
v80:
    popv(5);
    return nil;
}



/* Code for sfto_reorder */

static Lisp_Object CC_sfto_reorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_reorder");
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
    v124 = v1;
    stack[0] = v0;
/* end of prologue */
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    fn = elt(env, 1); /* setkorder */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[-1] = v124;
    v124 = stack[0];
    fn = elt(env, 2); /* reorder */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[0] = v124;
    v124 = stack[-1];
    fn = elt(env, 1); /* setkorder */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v64;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for relnrd */

static Lisp_Object MS_CDECL CC_relnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "relnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for relnrd");
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
    stack[0] = nil;
    fn = elt(env, 5); /* lex */
    v94 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v94 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v95 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v94 = qvalue(elt(env, 2)); /* rdreln!* */
    v94 = Lassoc(nil, v95, v94);
    stack[-1] = v94;
    if (v94 == nil) goto v47;
    v94 = stack[-1];
    v94 = qcdr(v94);
    fn = elt(env, 7); /* first */
    stack[0] = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v94 = stack[-1];
    v94 = qcdr(v94);
    fn = elt(env, 8); /* rest */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    fn = elt(env, 9); /* apply */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[0] = v94;
    goto v36;

v36:
    v95 = stack[0];
    v94 = qvalue(elt(env, 3)); /* t */
    if (equal(v95, v94)) goto v174;
    v94 = stack[0];
    if (!(v94 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v94 = elt(env, 4); /* false */
    { popv(3); return onevalue(v94); }

v174:
    v94 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v94); }

v47:
    v94 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v95 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v94 = (Lisp_Object)289; /* 18 */
    fn = elt(env, 10); /* errorml */
    v94 = (*qfn2(fn))(qenv(fn), v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    goto v36;
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for getdec */

static Lisp_Object CC_getdec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v40;
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
    v40 = qvalue(elt(env, 1)); /* nil */
    v82 = stack[0];
    fn = elt(env, 2); /* symtabget */
    v82 = (*qfn2(fn))(qenv(fn), v40, v82);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v40 = v82;
    v82 = v40;
    if (!(v82 == nil)) { popv(2); return onevalue(v40); }
    v82 = stack[0];
    fn = elt(env, 3); /* implicitdec */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v40 = v82;
    { popv(2); return onevalue(v40); }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for mk!-strand!-vertex2 */

static Lisp_Object MS_CDECL CC_mkKstrandKvertex2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v65, v64;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk-strand-vertex2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-strand-vertex2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v90;
    v65 = v1;
    v64 = v0;
/* end of prologue */
    return list3(v64, v65, v81);
}



/* Code for dp_neworder */

static Lisp_Object CC_dp_neworder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neworder");
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
    v110 = v0;
/* end of prologue */
    stack[-4] = v110;
    v110 = stack[-4];
    if (v110 == nil) goto v64;
    v110 = stack[-4];
    v110 = qcar(v110);
    stack[0] = v110;
    v110 = stack[0];
    v110 = qcar(v110);
    fn = elt(env, 3); /* mo_neworder */
    v30 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v110 = stack[0];
    v110 = qcdr(v110);
    v110 = cons(v30, v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    stack[-2] = v110;
    stack[-3] = v110;
    goto v43;

v43:
    v110 = stack[-4];
    v110 = qcdr(v110);
    stack[-4] = v110;
    v110 = stack[-4];
    if (v110 == nil) goto v34;
    stack[-1] = stack[-2];
    v110 = stack[-4];
    v110 = qcar(v110);
    stack[0] = v110;
    v110 = stack[0];
    v110 = qcar(v110);
    fn = elt(env, 3); /* mo_neworder */
    v30 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v110 = stack[0];
    v110 = qcdr(v110);
    v110 = cons(v30, v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v110 = Lrplacd(nil, stack[-1], v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v110 = stack[-2];
    v110 = qcdr(v110);
    stack[-2] = v110;
    goto v43;

v34:
    v110 = stack[-3];
    v30 = v110;
    goto v46;

v46:
    v110 = elt(env, 2); /* dp!=mocompare */
    {
        popv(6);
        fn = elt(env, 4); /* sort */
        return (*qfn2(fn))(qenv(fn), v30, v110);
    }

v64:
    v110 = qvalue(elt(env, 1)); /* nil */
    v30 = v110;
    goto v46;
/* error exit handlers */
v113:
    popv(6);
    return nil;
}



/* Code for dummyp */

static Lisp_Object CC_dummyp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v11, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dummyp");
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
    v207 = (Lisp_Object)1; /* 0 */
    stack[-2] = v207;
    v207 = stack[-3];
    if (symbolp(v207)) goto v57;
    v207 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v207); }

v57:
    v207 = (Lisp_Object)17; /* 1 */
    stack[-4] = v207;
    goto v103;

v103:
    stack[0] = stack[-4];
    v207 = qvalue(elt(env, 2)); /* g_dvnames */
    fn = elt(env, 4); /* upbve */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    v207 = (Lisp_Object)lesseq2(stack[0], v207);
    nil = C_nil;
    if (exception_pending()) goto v196;
    v207 = v207 ? lisp_true : nil;
    env = stack[-5];
    if (v207 == nil) goto v76;
    stack[-1] = stack[-3];
    stack[0] = qvalue(elt(env, 2)); /* g_dvnames */
    v207 = stack[-4];
    v207 = sub1(v207);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    v207 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v207/(16/CELL)));
    if (equal(stack[-1], v207)) goto v116;
    v207 = stack[-4];
    v207 = add1(v207);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    stack[-4] = v207;
    goto v103;

v116:
    v207 = stack[-4];
    stack[-2] = v207;
    v207 = qvalue(elt(env, 2)); /* g_dvnames */
    fn = elt(env, 4); /* upbve */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    v207 = add1(v207);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    stack[-4] = v207;
    goto v103;

v76:
    v11 = stack[-2];
    v207 = (Lisp_Object)1; /* 0 */
    if (!(v11 == v207)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v207 = stack[-3];
    fn = elt(env, 5); /* ad_splitname */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    v11 = v207;
    v207 = v11;
    v207 = qcar(v207);
    v8 = qvalue(elt(env, 3)); /* g_dvbase */
    if (v207 == v8) goto v113;
    v207 = nil;
    { popv(6); return onevalue(v207); }

v113:
    v207 = v11;
    v207 = qcdr(v207);
    { popv(6); return onevalue(v207); }
/* error exit handlers */
v196:
    popv(6);
    return nil;
}



/* Code for bndtst */

static Lisp_Object CC_bndtst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bndtst");
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
    v98 = v0;
/* end of prologue */
    fn = elt(env, 2); /* abs!: */
    v42 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[0];
    v98 = qvalue(elt(env, 1)); /* tentothetenth!*!* */
    {
        popv(1);
        fn = elt(env, 3); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v42, v98);
    }
/* error exit handlers */
v43:
    popv(1);
    return nil;
}



/* Code for derivative!-mod!-p!-1 */

static Lisp_Object CC_derivativeKmodKpK1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derivative-mod-p-1");
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
    v93 = stack[-2];
    if (!consp(v93)) goto v46;
    v93 = stack[-2];
    v93 = qcar(v93);
    if (!consp(v93)) goto v46;
    v93 = stack[-2];
    v93 = qcar(v93);
    v93 = qcar(v93);
    v25 = qcar(v93);
    v93 = stack[-1];
    if (equal(v25, v93)) goto v53;
    v93 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v93); }

v53:
    v93 = stack[-2];
    v93 = qcar(v93);
    v93 = qcar(v93);
    v25 = qcdr(v93);
    v93 = (Lisp_Object)17; /* 1 */
    if (v25 == v93) goto v62;
    v25 = stack[-1];
    v93 = stack[-2];
    v93 = qcar(v93);
    v93 = qcar(v93);
    v93 = qcdr(v93);
    v93 = (Lisp_Object)((int32_t)(v93) - 0x10);
    fn = elt(env, 2); /* mksp */
    stack[-3] = (*qfn2(fn))(qenv(fn), v25, v93);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v93 = stack[-2];
    v93 = qcar(v93);
    v25 = qcdr(v93);
    v93 = stack[-2];
    v93 = qcar(v93);
    v93 = qcar(v93);
    v93 = qcdr(v93);
    v93 = Lmodular_number(nil, v93);
    env = stack[-4];
    fn = elt(env, 3); /* multiply!-by!-constant!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v25, v93);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v93 = stack[-2];
    v25 = qcdr(v93);
    v93 = stack[-1];
    v93 = CC_derivativeKmodKpK1(env, v25, v93);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    {
        Lisp_Object v8 = stack[-3];
        Lisp_Object v182 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v8, v182, v93);
    }

v62:
    v93 = stack[-2];
    v93 = qcar(v93);
    v93 = qcdr(v93);
    { popv(5); return onevalue(v93); }

v46:
    v93 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v93); }
/* error exit handlers */
v11:
    popv(5);
    return nil;
}



/* Code for cl_smsimpl!-junct */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v90, Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v217, v212, v14, v15, v10, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_smsimpl-junct");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct");
#endif
    if (stack >= stacklimit)
    {
        push4(v102,v90,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v90,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v102;
    stack[-6] = v90;
    stack[0] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v199 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v199 == nil) goto v70;
    v199 = stack[-6];
    fn = elt(env, 5); /* rl_smcpknowl */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-9];
    stack[-2] = v199;
    v212 = elt(env, 3); /* false */
    v217 = stack[-7];
    v199 = elt(env, 4); /* and */
    v199 = (v217 == v199 ? lisp_true : nil);
    fn = elt(env, 6); /* cl_cflip */
    v199 = (*qfn2(fn))(qenv(fn), v212, v199);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-9];
    stack[-8] = v199;
    v199 = stack[0];
    stack[-1] = v199;
    goto v73;

v73:
    v199 = stack[-1];
    if (v199 == nil) goto v173;
    v199 = stack[-1];
    v199 = qcar(v199);
    stack[0] = v199;
    v199 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-9];
    if (v199 == nil) goto v113;
    v217 = stack[0];
    v199 = stack[-7];
    fn = elt(env, 8); /* cl_simplat */
    v199 = (*qfn2(fn))(qenv(fn), v217, v199);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-9];
    goto v29;

v29:
    stack[0] = v199;
    v199 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-9];
    if (v199 == nil) goto v184;
    v217 = stack[0];
    v199 = stack[-4];
    v199 = cons(v217, v199);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-9];
    stack[-4] = v199;
    goto v26;

v26:
    v199 = stack[-1];
    v199 = qcdr(v199);
    stack[-1] = v199;
    goto v73;

v184:
    v217 = stack[0];
    v199 = stack[-3];
    v199 = cons(v217, v199);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-9];
    stack[-3] = v199;
    goto v26;

v113:
    v199 = stack[0];
    goto v29;

v173:
    v14 = stack[-7];
    v212 = stack[-4];
    v217 = stack[-2];
    v199 = stack[-5];
    fn = elt(env, 9); /* rl_smupdknowl */
    v199 = (*qfnn(fn))(qenv(fn), 4, v14, v212, v217, v199);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-9];
    stack[-2] = v199;
    v217 = stack[-2];
    v199 = elt(env, 3); /* false */
    if (v217 == v199) goto v152;
    v2 = stack[-7];
    v10 = stack[-4];
    v199 = stack[-3];
    v15 = Lnreverse(nil, v199);
    env = stack[-9];
    v14 = stack[-6];
    v212 = stack[-2];
    v217 = stack[-5];
    v199 = stack[-8];
    {
        popv(10);
        fn = elt(env, 10); /* cl_smsimpl!-junct1 */
        return (*qfnn(fn))(qenv(fn), 7, v2, v10, v15, v14, v212, v217, v199);
    }

v152:
    v199 = stack[-8];
    popv(10);
    return ncons(v199);

v70:
    v14 = stack[0];
    v212 = stack[-5];
    v217 = stack[-7];
    v199 = qvalue(elt(env, 2)); /* nil */
    {
        popv(10);
        fn = elt(env, 11); /* cl_gand!-col */
        return (*qfnn(fn))(qenv(fn), 4, v14, v212, v217, v199);
    }
/* error exit handlers */
v138:
    popv(10);
    return nil;
}



/* Code for rl_bestgaussp */

static Lisp_Object CC_rl_bestgaussp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_bestgaussp");
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
    v98 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bestgaussp!* */
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    {
        Lisp_Object v124 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v124, v98);
    }
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for expnd */

static Lisp_Object CC_expnd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expnd");
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
    v58 = qvalue(elt(env, 1)); /* !*really_off_exp */
    if (!(v58 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v58 = stack[0];
    fn = elt(env, 3); /* expnd1 */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    stack[0] = v58;
    v58 = qvalue(elt(env, 2)); /* !*sub2 */
    if (v58 == nil) goto v47;
    v58 = stack[0];
    fn = elt(env, 4); /* subs2f */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v35 = v58;
    v59 = qcdr(v58);
    v58 = (Lisp_Object)17; /* 1 */
    if (!(v59 == v58)) goto v47;
    v58 = v35;
    v58 = qcar(v58);
    goto v43;

v43:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    { popv(3); return onevalue(v58); }

v47:
    v58 = stack[0];
    goto v43;
/* error exit handlers */
v69:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    popv(3);
    return nil;
}



/* Code for semanticml */

static Lisp_Object CC_semanticml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for semanticml");
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
    v115 = stack[0];
    v87 = Llength(nil, v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = (Lisp_Object)17; /* 1 */
    v115 = (Lisp_Object)greaterp2(v87, v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    v115 = v115 ? lisp_true : nil;
    env = stack[-1];
    if (v115 == nil) goto v46;
    v115 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 3); /* "<fn>" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    goto v46;

v46:
    v115 = elt(env, 5); /* "<semantic>" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 6); /* "<ci><mo>" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = stack[0];
    v115 = qcar(v115);
    v115 = qcar(v115);
    v115 = Lprinc(nil, v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 7); /* "</mo></ci>" */
    v115 = Lprinc(nil, v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 8); /* "<annotation-xml encoding=""OpenMath"">" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 9); /* "<" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = stack[0];
    v115 = qcar(v115);
    v115 = qcdr(v115);
    v115 = qcar(v115);
    fn = elt(env, 17); /* list2string */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 10); /* ">" */
    v115 = Lprinc(nil, v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 11); /* "</annotation-xml>" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 12); /* "</semantic>" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = stack[0];
    v87 = Llength(nil, v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = (Lisp_Object)17; /* 1 */
    v115 = (Lisp_Object)greaterp2(v87, v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    v115 = v115 ? lisp_true : nil;
    env = stack[-1];
    if (v115 == nil) goto v104;
    v115 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 13); /* "</fn>" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = stack[0];
    v115 = qcdr(v115);
    fn = elt(env, 18); /* multi_elem */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v115 = elt(env, 14); /* "</apply>" */
    fn = elt(env, 15); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v25;
    goto v104;

v104:
    v115 = nil;
    { popv(2); return onevalue(v115); }
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for znumrnil */

static Lisp_Object CC_znumrnil(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for znumrnil");
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
    v83 = stack[0];
    fn = elt(env, 2); /* znumr */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-1];
    if (v83 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v56 = qvalue(elt(env, 1)); /* nil */
    v83 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v56, v83);
/* error exit handlers */
v40:
    popv(2);
    return nil;
}



/* Code for evalvars */

static Lisp_Object CC_evalvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalvars");
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
    goto v46;

v46:
    v99 = stack[-1];
    if (v99 == nil) goto v55;
    v99 = stack[-1];
    v99 = qcar(v99);
    if (!consp(v99)) goto v71;
    v99 = stack[-1];
    v99 = qcar(v99);
    v100 = qcar(v99);
    v99 = elt(env, 1); /* intfn */
    v99 = Lflagp(nil, v100, v99);
    env = stack[-3];
    if (!(v99 == nil)) goto v71;
    v99 = stack[-1];
    v99 = qcar(v99);
    v100 = qcar(v99);
    v99 = elt(env, 2); /* rtype */
    v100 = get(v100, v99);
    env = stack[-3];
    v99 = elt(env, 3); /* setelemfn */
    v99 = get(v100, v99);
    env = stack[-3];
    if (v99 == nil) goto v26;
    v99 = stack[-1];
    v99 = qcar(v99);
    stack[0] = qcar(v99);
    v99 = stack[-1];
    v99 = qcar(v99);
    v99 = qcdr(v99);
    fn = elt(env, 4); /* revlis_without_mode */
    v100 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v99 = stack[-2];
    v99 = acons(stack[0], v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    stack[-2] = v99;
    v99 = stack[-1];
    v99 = qcdr(v99);
    stack[-1] = v99;
    goto v46;

v26:
    v99 = stack[-1];
    v99 = qcar(v99);
    stack[0] = qcar(v99);
    v99 = stack[-1];
    v99 = qcar(v99);
    v99 = qcdr(v99);
    fn = elt(env, 5); /* revlis */
    v100 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v99 = stack[-2];
    v99 = acons(stack[0], v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    stack[-2] = v99;
    v99 = stack[-1];
    v99 = qcdr(v99);
    stack[-1] = v99;
    goto v46;

v71:
    v99 = stack[-1];
    v100 = qcar(v99);
    v99 = stack[-2];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    stack[-2] = v99;
    v99 = stack[-1];
    v99 = qcdr(v99);
    stack[-1] = v99;
    goto v46;

v55:
    v99 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v99);
    }
/* error exit handlers */
v20:
    popv(4);
    return nil;
}



/* Code for amatch */

static Lisp_Object MS_CDECL CC_amatch(Lisp_Object env, int nargs,
                         Lisp_Object v90, Lisp_Object v102,
                         Lisp_Object v68, Lisp_Object v46, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v216, v144, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "amatch");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for amatch");
#endif
    if (stack >= stacklimit)
    {
        push4(v46,v68,v102,v90);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v90,v102,v68,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v46;
    stack[-4] = v68;
    v216 = v102;
    v218 = v90;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* r */
    qvalue(elt(env, 1)) = nil; /* r */
    stack[-2] = qvalue(elt(env, 2)); /* p */
    qvalue(elt(env, 2)) = nil; /* p */
    qvalue(elt(env, 1)) = v218; /* r */
    v218 = v216;
    qvalue(elt(env, 2)) = v218; /* p */
    goto v65;

v65:
    v218 = qvalue(elt(env, 1)); /* r */
    if (!consp(v218)) goto v41;
    v218 = qvalue(elt(env, 2)); /* p */
    if (!consp(v218)) goto v80;
    v218 = qvalue(elt(env, 1)); /* r */
    v216 = qcar(v218);
    v218 = qvalue(elt(env, 2)); /* p */
    v218 = qcar(v218);
    if (!(equal(v216, v218))) goto v80;
    v218 = qvalue(elt(env, 1)); /* r */
    stack[0] = qcar(v218);
    v218 = qvalue(elt(env, 1)); /* r */
    v218 = qcdr(v218);
    fn = elt(env, 6); /* mval */
    v143 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v218 = qvalue(elt(env, 2)); /* p */
    v144 = qcdr(v218);
    v216 = stack[-4];
    v218 = stack[-3];
    fn = elt(env, 7); /* unify */
    v218 = (*qfnn(fn))(qenv(fn), 5, stack[0], v143, v144, v216, v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    goto v57;

v57:
    qvalue(elt(env, 2)) = stack[-2]; /* p */
    qvalue(elt(env, 1)) = stack[-5]; /* r */
    { popv(7); return onevalue(v218); }

v80:
    v218 = qvalue(elt(env, 1)); /* r */
    fn = elt(env, 8); /* suchp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    if (v218 == nil) goto v92;
    v218 = qvalue(elt(env, 1)); /* r */
    v218 = qcdr(v218);
    v218 = qcar(v218);
    stack[0] = v218;
    v218 = qvalue(elt(env, 1)); /* r */
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    v216 = qcar(v218);
    v218 = stack[-4];
    v218 = cons(v216, v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    stack[-4] = v218;
    v218 = stack[0];
    qvalue(elt(env, 1)) = v218; /* r */
    goto v65;

v92:
    v218 = qvalue(elt(env, 4)); /* !*semantic */
    if (v218 == nil) goto v219;
    v144 = elt(env, 5); /* equal */
    v216 = qvalue(elt(env, 1)); /* r */
    v218 = qvalue(elt(env, 2)); /* p */
    v216 = list3(v144, v216, v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v218 = stack[-4];
    v216 = cons(v216, v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v218 = stack[-3];
    fn = elt(env, 9); /* resume */
    v218 = (*qfn2(fn))(qenv(fn), v216, v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    goto v57;

v219:
    v218 = qvalue(elt(env, 3)); /* nil */
    goto v57;

v41:
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v218 = qvalue(elt(env, 1)); /* r */
    v218 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    fn = elt(env, 6); /* mval */
    stack[0] = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v218 = qvalue(elt(env, 2)); /* p */
    v144 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v216 = stack[-4];
    v218 = stack[-3];
    fn = elt(env, 7); /* unify */
    v218 = (*qfnn(fn))(qenv(fn), 5, stack[-1], stack[0], v144, v216, v218);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    goto v57;
/* error exit handlers */
v189:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; /* p */
    qvalue(elt(env, 1)) = stack[-5]; /* r */
    popv(7);
    return nil;
}



setup_type const u22_setup[] =
{
    {"reverse-num1",            too_few_2,      CC_reverseKnum1,wrong_no_2},
    {"*tayexp2q",               CC_Htayexp2q,   too_many_1,    wrong_no_1},
    {"lambdaom",                CC_lambdaom,    too_many_1,    wrong_no_1},
    {"ps:value",                CC_psTvalue,    too_many_1,    wrong_no_1},
    {"overall_factor",          too_few_2,      CC_overall_factor,wrong_no_2},
    {"testchar1",               CC_testchar1,   too_many_1,    wrong_no_1},
    {"chkint*",                 CC_chkintH,     too_many_1,    wrong_no_1},
    {"gparg1p",                 CC_gparg1p,     too_many_1,    wrong_no_1},
    {"*pf2sq",                  CC_Hpf2sq,      too_many_1,    wrong_no_1},
    {"prop-simp2",              too_few_2,      CC_propKsimp2, wrong_no_2},
    {"quotpri",                 CC_quotpri,     too_many_1,    wrong_no_1},
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {"dfprintfn",               CC_dfprintfn,   too_many_1,    wrong_no_1},
    {"cgp_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_cgp_mk},
    {"omfir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omfir},
    {"ps:depvar",               CC_psTdepvar,   too_many_1,    wrong_no_1},
    {"insoccs",                 too_few_2,      CC_insoccs,    wrong_no_2},
    {"smemberl",                too_few_2,      CC_smemberl,   wrong_no_2},
    {"locate_member",           too_few_2,      CC_locate_member,wrong_no_2},
    {"rootextractf",            CC_rootextractf,too_many_1,    wrong_no_1},
    {"reduce-mod-p*",           too_few_2,      CC_reduceKmodKpH,wrong_no_2},
    {"gitimes:",                too_few_2,      CC_gitimesT,   wrong_no_2},
    {"gen+can+bas",             CC_genLcanLbas, too_many_1,    wrong_no_1},
    {"cgp_number",              CC_cgp_number,  too_many_1,    wrong_no_1},
    {"lambdafun",               CC_lambdafun,   too_many_1,    wrong_no_1},
    {"reform-minus",            too_few_2,      CC_reformKminus,wrong_no_2},
    {"r2findindex",             too_few_2,      CC_r2findindex,wrong_no_2},
    {"mo_2a",                   CC_mo_2a,       too_many_1,    wrong_no_1},
    {"dv_ind2var",              CC_dv_ind2var,  too_many_1,    wrong_no_1},
    {"rootrnd",                 CC_rootrnd,     too_many_1,    wrong_no_1},
    {"termorder",               too_few_2,      CC_termorder,  wrong_no_2},
    {"lastnondomain",           CC_lastnondomain,too_many_1,   wrong_no_1},
    {"plusdf",                  too_few_2,      CC_plusdf,     wrong_no_2},
    {"replace1_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace1_parents},
    {"simp-prop2",              CC_simpKprop2,  too_many_1,    wrong_no_1},
    {"deginvar",                too_few_2,      CC_deginvar,   wrong_no_2},
    {"evallessp",               too_few_2,      CC_evallessp,  wrong_no_2},
    {"mk+real+inner+product",   too_few_2,      CC_mkLrealLinnerLproduct,wrong_no_2},
    {"lambdavar",               CC_lambdavar,   too_many_1,    wrong_no_1},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,too_many_1,wrong_no_1},
    {"f2dip11",                 CC_f2dip11,     too_many_1,    wrong_no_1},
    {"eqexpr",                  CC_eqexpr,      too_many_1,    wrong_no_1},
    {"numprintlen",             CC_numprintlen, too_many_1,    wrong_no_1},
    {"getphystypecar",          CC_getphystypecar,too_many_1,  wrong_no_1},
    {"remchkf",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_remchkf},
    {"subcare",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subcare},
    {"red_tailreddriver",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_tailreddriver},
    {"ad_splitname",            CC_ad_splitname,too_many_1,    wrong_no_1},
    {"general-ordered-gcd-mod-p",too_few_2,     CC_generalKorderedKgcdKmodKp,wrong_no_2},
    {"ofsf_entry2at1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at1},
    {"rl_qefsolset",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_qefsolset},
    {"sfto_reorder",            too_few_2,      CC_sfto_reorder,wrong_no_2},
    {"relnrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_relnrd},
    {"getdec",                  CC_getdec,      too_many_1,    wrong_no_1},
    {"mk-strand-vertex2",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKstrandKvertex2},
    {"dp_neworder",             CC_dp_neworder, too_many_1,    wrong_no_1},
    {"dummyp",                  CC_dummyp,      too_many_1,    wrong_no_1},
    {"bndtst",                  CC_bndtst,      too_many_1,    wrong_no_1},
    {"derivative-mod-p-1",      too_few_2,      CC_derivativeKmodKpK1,wrong_no_2},
    {"cl_smsimpl-junct",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct},
    {"rl_bestgaussp",           CC_rl_bestgaussp,too_many_1,   wrong_no_1},
    {"expnd",                   CC_expnd,       too_many_1,    wrong_no_1},
    {"semanticml",              CC_semanticml,  too_many_1,    wrong_no_1},
    {"znumrnil",                CC_znumrnil,    too_many_1,    wrong_no_1},
    {"evalvars",                CC_evalvars,    too_many_1,    wrong_no_1},
    {"amatch",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_amatch},
    {NULL, (one_args *)"u22", (two_args *)"16414 8045482 7609764", 0}
};

/* end of generated code */
