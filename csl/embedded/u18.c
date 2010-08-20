
/* $destdir/generated-c\u18.c Machine generated C code */

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


/* Code for quotof */

static Lisp_Object CC_quotof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotof");
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
    v62 = stack[-3];
    if (v62 == nil) goto v65;
    v63 = stack[-3];
    v62 = stack[-2];
    if (equal(v63, v62)) goto v66;
    v63 = stack[-2];
    v62 = (Lisp_Object)17; /* 1 */
    if (v63 == v62) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v62 = stack[-2];
    if (!consp(v62)) goto v67;
    v62 = stack[-2];
    v62 = qcar(v62);
    if (!consp(v62)) goto v67;
    v62 = stack[-3];
    if (!consp(v62)) goto v68;
    v62 = stack[-3];
    v62 = qcar(v62);
    if (!consp(v62)) goto v68;
    v62 = stack[-3];
    v62 = qcar(v62);
    v63 = qcar(v62);
    v62 = stack[-2];
    v62 = qcar(v62);
    v62 = qcar(v62);
    stack[0] = v63;
    stack[-4] = v62;
    v62 = stack[0];
    v63 = qcar(v62);
    v62 = stack[-4];
    v62 = qcar(v62);
    if (v63 == v62) goto v69;
    v62 = stack[0];
    v63 = qcar(v62);
    v62 = stack[-4];
    v62 = qcar(v62);
    fn = elt(env, 4); /* ordop */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    if (v62 == nil) goto v71;
    stack[-1] = stack[0];
    v62 = stack[-3];
    v62 = qcar(v62);
    v63 = qcdr(v62);
    v62 = stack[-2];
    stack[0] = CC_quotof(env, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v62 = stack[-3];
    v63 = qcdr(v62);
    v62 = stack[-2];
    v62 = CC_quotof(env, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    {
        Lisp_Object v72 = stack[-1];
        Lisp_Object v73 = stack[0];
        popv(6);
        return acons(v72, v73, v62);
    }

v71:
    v62 = stack[-4];
    stack[0] = qcar(v62);
    v62 = stack[-4];
    v62 = qcdr(v62);
    v62 = negate(v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    fn = elt(env, 5); /* mksp */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    stack[-1] = stack[-3];
    v63 = stack[-2];
    v62 = elt(env, 3); /* lcx */
    fn = elt(env, 6); /* carx */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v62 = qcdr(v62);
    v62 = CC_quotof(env, stack[-1], v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v62 = cons(stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    popv(6);
    return ncons(v62);

v69:
    v62 = stack[0];
    v63 = qcdr(v62);
    v62 = stack[-4];
    v62 = qcdr(v62);
    stack[-1] = difference2(v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v62 = stack[-3];
    v62 = qcar(v62);
    stack[0] = qcdr(v62);
    v63 = stack[-2];
    v62 = elt(env, 3); /* lcx */
    fn = elt(env, 6); /* carx */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v62 = qcdr(v62);
    stack[0] = CC_quotof(env, stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v62 = stack[-3];
    v63 = qcdr(v62);
    v62 = stack[-2];
    v62 = CC_quotof(env, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v64 = stack[-1];
    stack[-1] = stack[0];
    stack[0] = v62;
    v63 = v64;
    v62 = (Lisp_Object)1; /* 0 */
    if (v63 == v62) goto v74;
    v62 = stack[-4];
    v62 = qcar(v62);
    v63 = v64;
    fn = elt(env, 7); /* to */
    v64 = (*qfn2(fn))(qenv(fn), v62, v63);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v63 = stack[-1];
    v62 = stack[0];
    popv(6);
    return acons(v64, v63, v62);

v74:
    v63 = stack[-1];
    v62 = stack[0];
    {
        popv(6);
        fn = elt(env, 8); /* raddf */
        return (*qfn2(fn))(qenv(fn), v63, v62);
    }

v68:
    v62 = stack[-2];
    v62 = qcar(v62);
    v62 = qcar(v62);
    v62 = qcdr(v62);
    v63 = stack[-2];
    v63 = qcar(v63);
    v63 = qcar(v63);
    stack[0] = qcar(v63);
    v63 = v62;
    if (is_number(v63)) goto v75;
    v63 = elt(env, 2); /* minus */
    v62 = list2(v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    goto v76;

v76:
    fn = elt(env, 5); /* mksp */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    stack[-1] = stack[-3];
    v63 = stack[-2];
    v62 = elt(env, 3); /* lcx */
    fn = elt(env, 6); /* carx */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v62 = qcdr(v62);
    v62 = CC_quotof(env, stack[-1], v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v62 = cons(stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    popv(6);
    return ncons(v62);

v75:
    v62 = negate(v62);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    goto v76;

v67:
    v63 = stack[-3];
    v62 = stack[-2];
    {
        popv(6);
        fn = elt(env, 9); /* quotofd */
        return (*qfn2(fn))(qenv(fn), v63, v62);
    }

v66:
    v62 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v62); }

v65:
    v62 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v62); }
/* error exit handlers */
v70:
    popv(6);
    return nil;
}



/* Code for decprec2internal */

static Lisp_Object CC_decprec2internal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for decprec2internal");
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
    v79 = v0;
/* end of prologue */
    v80 = v79;
    v79 = qvalue(elt(env, 1)); /* log2of10 */
    v79 = times2(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    fn = elt(env, 2); /* ceiling */
    v80 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v79 = (Lisp_Object)49; /* 3 */
    popv(1);
    return plus2(v80, v79);
/* error exit handlers */
v81:
    popv(1);
    return nil;
}



/* Code for rl_csimpl */

static Lisp_Object CC_rl_csimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_csimpl");
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
    v83 = qvalue(elt(env, 1)); /* !*rlsimpl */
    if (v83 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v83 = elt(env, 2); /* rl_simpl */
    fn = elt(env, 4); /* getd */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    if (v83 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v59 = stack[0];
    v58 = qvalue(elt(env, 3)); /* nil */
    v83 = (Lisp_Object)-15; /* -1 */
    {
        popv(2);
        fn = elt(env, 2); /* rl_simpl */
        return (*qfnn(fn))(qenv(fn), 3, v59, v58, v83);
    }
/* error exit handlers */
v84:
    popv(2);
    return nil;
}



/* Code for vunion */

static Lisp_Object CC_vunion(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vunion");
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
    v49 = stack[-2];
    if (v49 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v49 = stack[-2];
    v49 = qcar(v49);
    v50 = qcar(v49);
    v49 = stack[-1];
    v49 = Lassoc(nil, v50, v49);
    stack[-3] = v49;
    if (v49 == nil) goto v83;
    v49 = stack[-2];
    v49 = qcar(v49);
    v50 = qcdr(v49);
    v49 = stack[-3];
    v49 = qcdr(v49);
    v49 = (Lisp_Object)greaterp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v49 = v49 ? lisp_true : nil;
    env = stack[-4];
    if (v49 == nil) goto v106;
    v49 = stack[-2];
    stack[0] = qcar(v49);
    v49 = stack[-2];
    stack[-2] = qcdr(v49);
    v50 = stack[-3];
    v49 = stack[-1];
    v49 = Ldelete(nil, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v49 = CC_vunion(env, stack[-2], v49);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v107 = stack[0];
        popv(5);
        return cons(v107, v49);
    }

v106:
    stack[0] = stack[-3];
    v49 = stack[-2];
    stack[-2] = qcdr(v49);
    v50 = stack[-3];
    v49 = stack[-1];
    v49 = Ldelete(nil, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v49 = CC_vunion(env, stack[-2], v49);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v108 = stack[0];
        popv(5);
        return cons(v108, v49);
    }

v83:
    v49 = stack[-2];
    stack[0] = qcar(v49);
    v49 = stack[-2];
    v50 = qcdr(v49);
    v49 = stack[-1];
    v49 = CC_vunion(env, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v109 = stack[0];
        popv(5);
        return cons(v109, v49);
    }
/* error exit handlers */
v105:
    popv(5);
    return nil;
}



/* Code for ibalp_dav */

static Lisp_Object CC_ibalp_dav(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_dav");
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
    stack[-4] = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 1)) = nil; /* nil */
    v69 = stack[-3];
    stack[-1] = v69;
    goto v66;

v66:
    v69 = stack[-1];
    if (v69 == nil) goto v77;
    v69 = stack[-1];
    v69 = qcar(v69);
    stack[0] = v69;
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    if (v69 == nil) goto v82;
    v69 = stack[0];
    v119 = qcdr(v69);
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    fn = elt(env, 2); /* ibalp_var!-unset */
    v69 = (*qfn2(fn))(qenv(fn), v119, v69);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-5];
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v119 = qcdr(v69);
    v69 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setcar */
    v69 = (*qfn2(fn))(qenv(fn), v119, v69);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-5];
    goto v82;

v82:
    v69 = stack[-1];
    v69 = qcdr(v69);
    stack[-1] = v69;
    goto v66;

v77:
    v69 = stack[-3];
    stack[0] = v69;
    goto v121;

v121:
    v69 = stack[0];
    if (v69 == nil) goto v76;
    v69 = stack[0];
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v119 = qcdr(v69);
    v69 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setcar */
    v69 = (*qfn2(fn))(qenv(fn), v119, v69);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-5];
    v69 = stack[0];
    v69 = qcdr(v69);
    stack[0] = v69;
    goto v121;

v76:
    v69 = stack[-2];
    stack[0] = v69;
    goto v49;

v49:
    v69 = stack[0];
    if (v69 == nil) goto v90;
    v69 = stack[0];
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v119 = qcdr(v69);
    v69 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setcar */
    v69 = (*qfn2(fn))(qenv(fn), v119, v69);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-5];
    v69 = stack[0];
    v69 = qcdr(v69);
    stack[0] = v69;
    goto v49;

v90:
    v69 = nil;
    qvalue(elt(env, 1)) = stack[-4]; /* nil */
    { popv(6); return onevalue(v69); }
/* error exit handlers */
v120:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* nil */
    popv(6);
    return nil;
}



/* Code for vdp_zero!? */

static Lisp_Object CC_vdp_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_zero?");
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
    v65 = v0;
/* end of prologue */
    fn = elt(env, 1); /* vdp_poly */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    errexit();
    v65 = (v65 == nil ? lisp_true : nil);
    return onevalue(v65);
}



/* Code for naryom */

static Lisp_Object CC_naryom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for naryom");
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
    v87 = stack[-1];
    v87 = qcar(v87);
    stack[0] = v87;
    v88 = stack[0];
    v87 = elt(env, 1); /* var */
    if (!(v88 == v87)) goto v81;
    v87 = elt(env, 2); /* variance */
    stack[0] = v87;
    goto v81;

v81:
    v88 = stack[0];
    v87 = qvalue(elt(env, 3)); /* valid_om!* */
    v87 = Lassoc(nil, v88, v87);
    stack[-2] = v87;
    v87 = stack[-2];
    if (v87 == nil) goto v84;
    v87 = stack[-2];
    v87 = qcdr(v87);
    v87 = qcar(v87);
    stack[-2] = v87;
    goto v84;

v84:
    v87 = stack[-1];
    v87 = qcdr(v87);
    v87 = qcar(v87);
    if (v87 == nil) goto v67;
    v87 = stack[-1];
    v87 = qcdr(v87);
    v88 = qcar(v87);
    v87 = elt(env, 4); /* multiset */
    if (!(v88 == v87)) goto v67;
    v87 = stack[-1];
    v87 = qcdr(v87);
    v87 = qcar(v87);
    stack[-2] = v87;
    goto v67;

v67:
    v87 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v88 = qvalue(elt(env, 7)); /* indent */
    v87 = (Lisp_Object)33; /* 2 */
    v87 = plus2(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    qvalue(elt(env, 7)) = v87; /* indent */
    v87 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v87 = stack[-2];
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v87 = elt(env, 9); /* """ name=""" */
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v87 = stack[0];
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v87 = elt(env, 10); /* """>" */
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v87 = stack[-1];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    fn = elt(env, 13); /* multiom */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v88 = qvalue(elt(env, 7)); /* indent */
    v87 = (Lisp_Object)33; /* 2 */
    v87 = difference2(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    qvalue(elt(env, 7)) = v87; /* indent */
    v87 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v125;
    v87 = nil;
    { popv(4); return onevalue(v87); }
/* error exit handlers */
v125:
    popv(4);
    return nil;
}



/* Code for pfordp */

static Lisp_Object CC_pfordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pfordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v132 = v1;
    v133 = v0;
/* end of prologue */

v65:
    v131 = v133;
    if (v131 == nil) goto v77;
    v131 = v132;
    if (v131 == nil) goto v60;
    v131 = v133;
    v131 = qcar(v131);
    v134 = qcar(v131);
    v131 = v132;
    v131 = qcar(v131);
    v131 = qcar(v131);
    if (v134 == v131) goto v135;
    v131 = v133;
    v131 = qcar(v131);
    v131 = qcar(v131);
    v132 = qcar(v132);
    v132 = qcar(v132);
    {
        fn = elt(env, 2); /* termordp */
        return (*qfn2(fn))(qenv(fn), v131, v132);
    }

v135:
    v131 = v133;
    v131 = qcdr(v131);
    v133 = v131;
    v131 = v132;
    v131 = qcdr(v131);
    v132 = v131;
    goto v65;

v60:
    v131 = v133;
    v131 = qcar(v131);
    v132 = qcar(v131);
    v131 = (Lisp_Object)17; /* 1 */
        return Lneq(nil, v132, v131);

v77:
    v131 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v131);
}



/* Code for flatindl */

static Lisp_Object CC_flatindl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v68;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatindl");
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
    goto v118;

v118:
    v57 = stack[0];
    if (v57 == nil) goto v136;
    v57 = stack[0];
    v68 = qcar(v57);
    v57 = stack[-1];
    v57 = cons(v68, v57);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    stack[-1] = v57;
    v57 = stack[0];
    v57 = qcdr(v57);
    stack[0] = v57;
    goto v118;

v136:
    v57 = qvalue(elt(env, 1)); /* nil */
    v68 = v57;
    goto v77;

v77:
    v57 = stack[-1];
    if (v57 == nil) { popv(3); return onevalue(v68); }
    v57 = stack[-1];
    v57 = qcar(v57);
    v57 = Lappend(nil, v57, v68);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    v68 = v57;
    v57 = stack[-1];
    v57 = qcdr(v57);
    stack[-1] = v57;
    goto v77;
/* error exit handlers */
v137:
    popv(3);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v68;
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

v139:
    v57 = stack[0];
    fn = elt(env, 4); /* listp */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    if (v57 == nil) goto v65;
    v57 = stack[0];
    stack[-1] = qcar(v57);
    v68 = elt(env, 1); /* expt */
    v57 = elt(env, 2); /* minus */
    v57 = list2(v68, v57);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    v57 = Lmember(nil, stack[-1], v57);
    if (v57 == nil) goto v140;
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = qcar(v57);
    stack[0] = v57;
    goto v139;

v140:
    v57 = stack[0];
    fn = elt(env, 4); /* listp */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v137;
    if (v57 == nil) goto v65;
    v57 = stack[0];
    v57 = qcar(v57);
    { popv(3); return onevalue(v57); }

v65:
    v57 = nil;
    { popv(3); return onevalue(v57); }
/* error exit handlers */
v137:
    popv(3);
    return nil;
}



/* Code for general!-evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKevaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v123, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v147, v148, v149, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "general-evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-evaluate-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v123,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v123);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v123;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v118:
    v48 = stack[-3];
    if (!consp(v48)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v48 = stack[-3];
    v48 = qcar(v48);
    if (!consp(v48)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v147 = stack[-1];
    v48 = (Lisp_Object)1; /* 0 */
    if (v147 == v48) goto v61;
    v48 = stack[-2];
    if (v48 == nil) goto v59;
    v48 = stack[-3];
    v48 = qcar(v48);
    v48 = qcar(v48);
    v147 = qcar(v48);
    v48 = stack[-2];
    if (equal(v147, v48)) goto v150;
    v48 = stack[-3];
    v48 = qcar(v48);
    stack[-4] = qcar(v48);
    v48 = stack[-3];
    v48 = qcar(v48);
    v148 = qcdr(v48);
    v147 = stack[-2];
    v48 = stack[-1];
    stack[0] = CC_generalKevaluateKmodKp(env, 3, v148, v147, v48);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v48 = stack[-3];
    v148 = qcdr(v48);
    v147 = stack[-2];
    v48 = stack[-1];
    v48 = CC_generalKevaluateKmodKp(env, 3, v148, v147, v48);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    {
        Lisp_Object v151 = stack[-4];
        Lisp_Object v152 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v151, v152, v48);
    }

v150:
    v48 = stack[-3];
    v48 = qcar(v48);
    v105 = qcdr(v48);
    v48 = stack[-3];
    v48 = qcar(v48);
    v48 = qcar(v48);
    v149 = qcdr(v48);
    v48 = stack[-3];
    v148 = qcdr(v48);
    v147 = stack[-1];
    v48 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* general!-horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v105, v149, v148, v147, v48);
    }

v59:
    v48 = elt(env, 2); /* "Variable=NIL in GENERAL-EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v48);
    }

v61:
    v48 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v48;
    goto v118;
/* error exit handlers */
v10:
    popv(6);
    return nil;
}



/* Code for sgn */

static Lisp_Object CC_sgn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v155;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sgn");
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
    v155 = stack[0];
    v84 = (Lisp_Object)1; /* 0 */
    v84 = (Lisp_Object)greaterp2(v155, v84);
    nil = C_nil;
    if (exception_pending()) goto v100;
    v84 = v84 ? lisp_true : nil;
    env = stack[-1];
    if (v84 == nil) goto v79;
    v84 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v84); }

v79:
    v155 = stack[0];
    v84 = (Lisp_Object)1; /* 0 */
    v84 = (Lisp_Object)lessp2(v155, v84);
    nil = C_nil;
    if (exception_pending()) goto v100;
    v84 = v84 ? lisp_true : nil;
    if (v84 == nil) goto v58;
    v84 = (Lisp_Object)-15; /* -1 */
    { popv(2); return onevalue(v84); }

v58:
    v84 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v84); }
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for gf2cr!: */

static Lisp_Object CC_gf2crT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gf2cr:");
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
    stack[-2] = elt(env, 1); /* !:cr!: */
    v61 = stack[-1];
    v61 = qcar(v61);
    fn = elt(env, 2); /* striptag */
    stack[0] = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    v61 = stack[-1];
    v61 = qcdr(v61);
    fn = elt(env, 2); /* striptag */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v82;
    {
        Lisp_Object v104 = stack[-2];
        Lisp_Object v130 = stack[0];
        popv(4);
        return list2star(v104, v130, v61);
    }
/* error exit handlers */
v82:
    popv(4);
    return nil;
}



/* Code for innprodkp */

static Lisp_Object MS_CDECL CC_innprodkp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v123, Lisp_Object v91, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "innprodkp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodkp");
#endif
    if (stack >= stacklimit)
    {
        push4(v91,v123,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v123,v91);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v91;
    stack[-1] = v123;
    stack[-2] = v1;
    v132 = v0;
/* end of prologue */

v136:
    v131 = stack[-1];
    if (v131 == nil) goto v156;
    v133 = stack[-2];
    v131 = stack[-1];
    v131 = qcar(v131);
    if (equal(v133, v131)) goto v100;
    v131 = stack[-1];
    v131 = qcar(v131);
    v131 = cons(v131, v132);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    v132 = v131;
    v131 = stack[-1];
    v131 = qcdr(v131);
    stack[-1] = v131;
    v131 = stack[0];
    v131 = (v131 == nil ? lisp_true : nil);
    stack[0] = v131;
    goto v136;

v100:
    v131 = v132;
    v132 = Lnreverse(nil, v131);
    env = stack[-3];
    v131 = stack[-1];
    v131 = qcdr(v131);
    v131 = Lnconc(nil, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v45 = stack[0];
        popv(4);
        return cons(v45, v131);
    }

v156:
    v131 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v131); }
/* error exit handlers */
v92:
    popv(4);
    return nil;
}



/* Code for ofsf_clnegrel */

static Lisp_Object CC_ofsf_clnegrel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_clnegrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v154 = v1;
    v157 = v0;
/* end of prologue */
    if (!(v154 == nil)) return onevalue(v157);
    v154 = v157;
    {
        fn = elt(env, 1); /* ofsf_lnegrel */
        return (*qfn1(fn))(qenv(fn), v154);
    }
}



/* Code for mkzl */

static Lisp_Object CC_mkzl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v100;
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
    goto v156;

v156:
    v100 = stack[0];
    v101 = (Lisp_Object)17; /* 1 */
    if (v100 == v101) goto v77;
    v100 = (Lisp_Object)1; /* 0 */
    v101 = stack[-1];
    v101 = cons(v100, v101);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    stack[-1] = v101;
    v101 = stack[0];
    v101 = sub1(v101);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    stack[0] = v101;
    goto v156;

v77:
    v101 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v101);
    }
/* error exit handlers */
v117:
    popv(3);
    return nil;
}



/* Code for mkprod */

static Lisp_Object CC_mkprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprod");
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
    stack[-2] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v179 = stack[-4];
    if (v179 == nil) goto v153;
    v179 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    if (!(v179 == nil)) goto v153;
    v179 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v179; /* !*sub2 */
    v180 = stack[-4];
    v179 = (Lisp_Object)17; /* 1 */
    v179 = cons(v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    fn = elt(env, 11); /* subs2 */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[0] = v179;
    v179 = stack[0];
    v180 = qcdr(v179);
    v179 = (Lisp_Object)17; /* 1 */
    if (v180 == v179) goto v150;
    v179 = stack[-4];
    goto v66;

v66:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    { popv(7); return onevalue(v179); }

v150:
    v179 = stack[0];
    v180 = qcar(v179);
    v179 = stack[-4];
    if (equal(v180, v179)) goto v101;
    v179 = stack[0];
    v179 = qcar(v179);
    stack[-4] = v179;
    v179 = stack[-4];
    if (v179 == nil) goto v132;
    v179 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    if (!(v179 == nil)) goto v132;

v101:
    v179 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v179; /* !*exp */
    v179 = stack[-4];
    fn = elt(env, 12); /* ckrn */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[-5] = v179;
    v180 = stack[-4];
    v179 = stack[-5];
    fn = elt(env, 13); /* quotf */
    v179 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[-4] = v179;
    v179 = stack[-4];
    fn = elt(env, 14); /* expnd */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[0] = v179;
    v179 = stack[0];
    if (v179 == nil) goto v53;
    v179 = stack[0];
    fn = elt(env, 10); /* kernlp */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    if (!(v179 == nil)) goto v53;
    v179 = qvalue(elt(env, 4)); /* !*mcd */
    if (v179 == nil) goto v107;
    v179 = qvalue(elt(env, 5)); /* !*sqfree */
    if (!(v179 == nil)) goto v114;
    v179 = qvalue(elt(env, 6)); /* !*factor */
    if (!(v179 == nil)) goto v114;
    v179 = qvalue(elt(env, 7)); /* !*gcd */
    if (!(v179 == nil)) goto v114;

v107:
    v179 = stack[0];
    fn = elt(env, 12); /* ckrn */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[-3] = v179;
    v180 = stack[0];
    v179 = stack[-3];
    fn = elt(env, 13); /* quotf */
    v179 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[0] = v179;
    v180 = stack[0];
    v179 = (Lisp_Object)17; /* 1 */
    v179 = cons(v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    v179 = list2(stack[-3], v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[-3] = v179;
    goto v181;

v181:
    v179 = stack[-3];
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v180 = qcdr(v179);
    v179 = (Lisp_Object)17; /* 1 */
    v179 = (Lisp_Object)greaterp2(v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v179 = v179 ? lisp_true : nil;
    env = stack[-6];
    if (!(v179 == nil)) goto v35;
    v179 = stack[-3];
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    if (!(v179 == nil)) goto v35;
    v179 = qvalue(elt(env, 9)); /* !*group */
    if (!(v179 == nil)) goto v182;
    v179 = stack[-4];
    fn = elt(env, 15); /* tmsf */
    stack[0] = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    v179 = stack[-3];
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v179 = qcar(v179);
    fn = elt(env, 15); /* tmsf */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    v179 = (Lisp_Object)greaterp2(stack[0], v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v179 = v179 ? lisp_true : nil;
    env = stack[-6];
    if (v179 == nil) goto v182;
    v179 = stack[-3];
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v180 = qcar(v179);
    v179 = stack[-3];
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v179 = qcdr(v179);
    fn = elt(env, 16); /* mksp!* */
    v180 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    v179 = stack[-3];
    v179 = qcar(v179);
    fn = elt(env, 17); /* multf */
    v179 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[0] = v179;
    goto v183;

v183:
    v180 = stack[-5];
    v179 = stack[0];
    fn = elt(env, 17); /* multf */
    v179 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    goto v66;

v182:
    v180 = stack[-4];
    v179 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksp!* */
    v179 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[0] = v179;
    goto v183;

v35:
    v179 = stack[-3];
    v179 = qcar(v179);
    stack[0] = v179;
    v179 = stack[-3];
    v179 = qcdr(v179);
    stack[-3] = v179;
    goto v184;

v184:
    v179 = stack[-3];
    if (v179 == nil) goto v183;
    v179 = stack[-3];
    v179 = qcar(v179);
    v180 = v179;
    v180 = qcar(v180);
    v179 = qcdr(v179);
    fn = elt(env, 16); /* mksp!* */
    v180 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    v179 = stack[0];
    fn = elt(env, 17); /* multf */
    v179 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[0] = v179;
    v179 = stack[-3];
    v179 = qcdr(v179);
    stack[-3] = v179;
    goto v184;

v114:
    v179 = stack[0];
    fn = elt(env, 18); /* fctrf */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[-3] = v179;
    goto v181;

v53:
    v180 = stack[-5];
    v179 = stack[0];
    fn = elt(env, 17); /* multf */
    v179 = (*qfn2(fn))(qenv(fn), v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    goto v66;

v132:
    v179 = stack[-4];
    goto v66;

v153:
    v179 = stack[-4];
    goto v66;
/* error exit handlers */
v71:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    popv(7);
    return nil;
}



/* Code for ibalp_unitprop */

static Lisp_Object MS_CDECL CC_ibalp_unitprop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v123, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v193, v184, v194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_unitprop");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_unitprop");
#endif
    if (stack >= stacklimit)
    {
        push3(v123,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v123);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v123;
    stack[-4] = v1;
    v192 = v0;
/* end of prologue */
    stack[-2] = nil;
    v193 = nil;
    stack[-5] = v192;
    stack[0] = v192;
    goto v61;

v61:
    v192 = stack[-5];
    if (v192 == nil) goto v40;
    v192 = v193;
    if (!(v192 == nil)) goto v40;
    v192 = stack[-5];
    v192 = qcar(v192);
    stack[-1] = v192;
    v192 = stack[-1];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    if (!(v192 == nil)) goto v155;
    v192 = stack[-1];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v193 = v192;
    v192 = (Lisp_Object)17; /* 1 */
    v192 = Leqn(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    if (v192 == nil) goto v49;
    v192 = stack[-1];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v192 = qcar(v192);
    stack[-2] = v192;
    v192 = stack[-2];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    if (!(v192 == nil)) goto v155;
    v194 = stack[-2];
    v184 = (Lisp_Object)17; /* 1 */
    v193 = stack[-3];
    v192 = stack[-1];
    fn = elt(env, 2); /* ibalp_var!-set */
    v192 = (*qfnn(fn))(qenv(fn), 4, v194, v184, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    stack[-1] = v192;
    v193 = stack[0];
    v192 = stack[-1];
    v192 = Lnconc(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    v192 = stack[-1];
    if (!(v192 == nil)) goto v125;
    v192 = stack[0];
    goto v125;

v125:
    stack[0] = v192;
    goto v155;

v155:
    v192 = stack[-5];
    v192 = qcdr(v192);
    stack[-5] = v192;
    v192 = stack[-4];
    fn = elt(env, 3); /* ibalp_cec */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    v193 = v192;
    goto v61;

v49:
    v192 = stack[-1];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v192 = qcar(v192);
    stack[-2] = v192;
    v192 = stack[-2];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    if (!(v192 == nil)) goto v155;
    v194 = stack[-2];
    v184 = (Lisp_Object)1; /* 0 */
    v193 = stack[-3];
    v192 = stack[-1];
    fn = elt(env, 2); /* ibalp_var!-set */
    v192 = (*qfnn(fn))(qenv(fn), 4, v194, v184, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    stack[-1] = v192;
    v193 = stack[0];
    v192 = stack[-1];
    v192 = Lnconc(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-6];
    v192 = stack[-1];
    if (!(v192 == nil)) goto v196;
    v192 = stack[0];
    goto v196;

v196:
    stack[0] = v192;
    goto v155;

v40:
    v192 = stack[-2];
    popv(7);
    return cons(v193, v192);
/* error exit handlers */
v195:
    popv(7);
    return nil;
}



/* Code for ev_lexcomp */

static Lisp_Object CC_ev_lexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v68;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_lexcomp");
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

v65:
    v57 = stack[-1];
    if (v57 == nil) goto v77;
    v57 = stack[-1];
    v68 = qcar(v57);
    v57 = stack[0];
    v57 = qcar(v57);
    v57 = Leqn(nil, v68, v57);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    if (v57 == nil) goto v155;
    v57 = stack[-1];
    v57 = qcdr(v57);
    stack[-1] = v57;
    v57 = stack[0];
    v57 = qcdr(v57);
    stack[0] = v57;
    goto v65;

v155:
    v57 = stack[-1];
    v68 = qcar(v57);
    v57 = stack[0];
    v57 = qcar(v57);
    if (((int32_t)(v68)) > ((int32_t)(v57))) goto v138;
    v57 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v57); }

v138:
    v57 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v57); }

v77:
    v57 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v57); }
/* error exit handlers */
v137:
    popv(3);
    return nil;
}



/* Code for rationalizesq */

static Lisp_Object CC_rationalizesq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizesq");
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
    stack[-4] = qvalue(elt(env, 1)); /* !*structure */
    qvalue(elt(env, 1)) = nil; /* !*structure */
    stack[-2] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v49 = qvalue(elt(env, 3)); /* dmode!* */
    v90 = elt(env, 4); /* rationalizefn */
    v90 = get(v49, v90);
    env = stack[-5];
    stack[0] = v90;
    if (v90 == nil) goto v84;
    v49 = stack[0];
    v90 = stack[-3];
    v90 = Lapply1(nil, v49, v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    stack[-3] = v90;
    goto v84;

v84:
    v49 = elt(env, 5); /* (i 2 (nil . t) -1 nil) */
    v90 = qvalue(elt(env, 6)); /* powlis!* */
    v90 = cons(v49, v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    qvalue(elt(env, 6)) = v90; /* powlis!* */
    v90 = stack[-3];
    fn = elt(env, 9); /* subs2q */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    stack[-1] = v90;
    v90 = qvalue(elt(env, 6)); /* powlis!* */
    v90 = qcdr(v90);
    qvalue(elt(env, 6)) = v90; /* powlis!* */
    v90 = stack[-1];
    v90 = qcdr(v90);
    if (!consp(v90)) goto v56;
    v90 = stack[-1];
    v90 = qcdr(v90);
    v90 = qcar(v90);
    if (!consp(v90)) goto v56;
    v90 = stack[-1];
    v90 = qcdr(v90);
    fn = elt(env, 10); /* rationalizef */
    v49 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    stack[0] = v49;
    v90 = (Lisp_Object)17; /* 1 */
    if (v49 == v90) goto v125;
    v90 = stack[-1];
    v49 = qcar(v90);
    v90 = stack[0];
    fn = elt(env, 11); /* multf */
    stack[-3] = (*qfn2(fn))(qenv(fn), v49, v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v90 = stack[-1];
    v49 = qcdr(v90);
    v90 = stack[0];
    fn = elt(env, 11); /* multf */
    v90 = (*qfn2(fn))(qenv(fn), v49, v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v90 = cons(stack[-3], v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    stack[-1] = v90;
    v90 = qvalue(elt(env, 7)); /* !*algint */
    if (!(v90 == nil)) goto v53;
    v90 = qvalue(elt(env, 8)); /* !*rationalize */
    if (!(v90 == nil)) goto v53;
    v90 = stack[-1];
    fn = elt(env, 12); /* gcdchk */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    stack[-1] = v90;
    goto v53;

v53:
    v90 = stack[-1];
    fn = elt(env, 9); /* subs2q */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v136;

v136:
    qvalue(elt(env, 2)) = stack[-2]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-4]; /* !*structure */
    { popv(6); return onevalue(v90); }

v125:
    v90 = stack[-3];
    goto v136;

v56:
    v90 = stack[-1];
    goto v136;
/* error exit handlers */
v105:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-2]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-4]; /* !*structure */
    popv(6);
    return nil;
}



/* Code for vdpequal */

static Lisp_Object CC_vdpequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v121, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpequal");
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
    v121 = stack[-1];
    v76 = stack[0];
    v76 = (v121 == v76 ? lisp_true : nil);
    if (!(v76 == nil)) { popv(4); return onevalue(v76); }
    v121 = stack[-1];
    v76 = elt(env, 1); /* number */
    fn = elt(env, 3); /* vdpgetprop */
    stack[-2] = (*qfn2(fn))(qenv(fn), v121, v76);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v121 = stack[0];
    v76 = elt(env, 1); /* number */
    fn = elt(env, 3); /* vdpgetprop */
    v76 = (*qfn2(fn))(qenv(fn), v121, v76);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v94 = stack[-2];
    v121 = v76;
    v76 = v94;
    if (v76 == nil) goto v67;
    v76 = v94;
    v76 = (equal(v76, v121) ? lisp_true : nil);
    goto v198;

v198:
    if (!(v76 == nil)) { popv(4); return onevalue(v76); }
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v121 = qcar(v76);
    v76 = stack[0];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    {
        popv(4);
        fn = elt(env, 4); /* dipequal */
        return (*qfn2(fn))(qenv(fn), v121, v76);
    }

v67:
    v76 = qvalue(elt(env, 2)); /* nil */
    goto v198;
/* error exit handlers */
v52:
    popv(4);
    return nil;
}



/* Code for xdegreecheck */

static Lisp_Object CC_xdegreecheck(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegreecheck");
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
    v80 = qvalue(elt(env, 1)); /* xtruncate!* */
    if (v80 == nil) goto v110;
    v80 = v81;
    fn = elt(env, 3); /* xdegree */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[0];
    v81 = qvalue(elt(env, 1)); /* xtruncate!* */
        popv(1);
        return Lgreaterp(nil, v80, v81);

v110:
    v80 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v80); }
/* error exit handlers */
v82:
    popv(1);
    return nil;
}



/* Code for gfdot */

static Lisp_Object CC_gfdot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v138, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfdot");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v138 = v1;
    v84 = v0;
/* end of prologue */
    v59 = v84;
    v59 = qcar(v59);
    if (!consp(v59)) goto v156;
    v59 = v84;
    {
        fn = elt(env, 1); /* gbfdot */
        return (*qfn2(fn))(qenv(fn), v59, v138);
    }

v156:
    v59 = v84;
    {
        fn = elt(env, 2); /* gffdot */
        return (*qfn2(fn))(qenv(fn), v59, v138);
    }
}



/* Code for lesspcdr */

static Lisp_Object CC_lesspcdr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v157;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lesspcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v154 = v1;
    v157 = v0;
/* end of prologue */
    v157 = qcdr(v157);
    v154 = qcdr(v154);
        return Llessp(nil, v157, v154);
}



/* Code for setk0 */

static Lisp_Object CC_setk0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v112, v18, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setk0");
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
    stack[0] = qvalue(elt(env, 1)); /* frasc!* */
    qvalue(elt(env, 1)) = nil; /* frasc!* */
    v109 = stack[-1];
    fn = elt(env, 8); /* getrtype */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[-3] = v109;
    if (v109 == nil) goto v156;
    v112 = stack[-3];
    v109 = elt(env, 2); /* setelemfn */
    v109 = get(v112, v109);
    env = stack[-4];
    if (v109 == nil) goto v156;
    v109 = qvalue(elt(env, 3)); /* nil */
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    qvalue(elt(env, 4)) = v109; /* alglist!* */
    v10 = stack[-2];
    v18 = stack[-1];
    v112 = qvalue(elt(env, 3)); /* nil */
    v109 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 9); /* let2 */
    v109 = (*qfnn(fn))(qenv(fn), 4, v10, v18, v112, v109);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    goto v77;

v77:
    v109 = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* frasc!* */
    { popv(5); return onevalue(v109); }

v156:
    v109 = stack[-2];
    if (!consp(v109)) goto v191;
    v109 = stack[-2];
    v109 = qcar(v109);
    if (!(symbolp(v109))) goto v191;
    v109 = stack[-2];
    fn = elt(env, 8); /* getrtype */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    if (!(v109 == nil)) goto v135;
    v109 = stack[-2];
    v112 = qcar(v109);
    v109 = elt(env, 6); /* rtype */
    v109 = get(v112, v109);
    env = stack[-4];
    goto v135;

v135:
    stack[-3] = v109;
    if (v109 == nil) goto v176;
    v112 = stack[-3];
    v109 = elt(env, 2); /* setelemfn */
    v109 = get(v112, v109);
    env = stack[-4];
    stack[-3] = v109;
    if (!(v109 == nil)) goto v102;

v176:
    v109 = stack[-2];
    v112 = qcar(v109);
    v109 = elt(env, 7); /* setkfn */
    v109 = get(v112, v109);
    env = stack[-4];
    stack[-3] = v109;
    if (!(v109 == nil)) goto v102;

v191:
    v10 = stack[-2];
    v18 = stack[-1];
    v112 = qvalue(elt(env, 3)); /* nil */
    v109 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 9); /* let2 */
    v109 = (*qfnn(fn))(qenv(fn), 4, v10, v18, v112, v109);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    goto v77;

v102:
    v109 = qvalue(elt(env, 3)); /* nil */
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    qvalue(elt(env, 4)) = v109; /* alglist!* */
    v18 = stack[-3];
    v112 = stack[-2];
    v109 = stack[-1];
    v109 = Lapply2(nil, 3, v18, v112, v109);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    goto v77;
/* error exit handlers */
v174:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* frasc!* */
    popv(5);
    return nil;
}



/* Code for fs!:null!-angle */

static Lisp_Object CC_fsTnullKangle(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:null-angle");
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
    v177 = v0;
/* end of prologue */
    v99 = v177;
    v177 = (Lisp_Object)33; /* 2 */
    v177 = *(Lisp_Object *)((char *)v99 + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    stack[0] = v177;
    v177 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v177;
    v177 = (Lisp_Object)1; /* 0 */
    stack[-1] = v177;
    goto v59;

v59:
    v99 = stack[0];
    v177 = stack[-1];
    v99 = *(Lisp_Object *)((char *)v99 + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = (Lisp_Object)1; /* 0 */
    if (v99 == v177) goto v80;
    v177 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v177); }

v80:
    v177 = stack[-1];
    v177 = add1(v177);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    stack[-1] = v177;
    v99 = stack[-1];
    v177 = (Lisp_Object)129; /* 8 */
    v177 = (Lisp_Object)lessp2(v99, v177);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v177 = v177 ? lisp_true : nil;
    env = stack[-3];
    if (v177 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    else goto v59;
/* error exit handlers */
v132:
    popv(4);
    return nil;
}



/* Code for merge */

static Lisp_Object MS_CDECL CC_merge(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v123, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95, v201;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "merge");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge");
#endif
    if (stack >= stacklimit)
    {
        push3(v123,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v123);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v123;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v94 = stack[-2];
    if (v94 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v94 = stack[-1];
    if (v94 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v201 = stack[0];
    v94 = stack[-2];
    v95 = qcar(v94);
    v94 = stack[-1];
    v94 = qcar(v94);
    v94 = Lapply2(nil, 3, v201, v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    if (v94 == nil) goto v98;
    stack[-3] = stack[-2];
    v94 = stack[-2];
    v201 = qcdr(v94);
    v95 = stack[-1];
    v94 = stack[0];
    v94 = CC_merge(env, 3, v201, v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    {
        Lisp_Object v97 = stack[-3];
        popv(5);
        return Lrplacd(nil, v97, v94);
    }

v98:
    stack[-3] = stack[-1];
    v201 = stack[-2];
    v94 = stack[-1];
    v95 = qcdr(v94);
    v94 = stack[0];
    v94 = CC_merge(env, 3, v201, v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    {
        Lisp_Object v115 = stack[-3];
        popv(5);
        return Lrplacd(nil, v115, v94);
    }
/* error exit handlers */
v96:
    popv(5);
    return nil;
}



/* Code for mod_eval_uni_poly */

static Lisp_Object CC_mod_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v175, v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod_eval_uni_poly");
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
    v174 = stack[-2];
    if (!consp(v174)) goto v65;
    v174 = stack[-2];
    v174 = qcar(v174);
    v174 = qcdr(v174);
    fn = elt(env, 3); /* mod!# */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v204 = v174;
    v174 = stack[-2];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcdr(v174);
    v175 = v174;
    v174 = stack[-2];
    v174 = qcdr(v174);
    stack[-2] = v174;
    goto v138;

v138:
    v174 = stack[-2];
    if (!consp(v174)) goto v46;
    stack[-3] = v204;
    stack[0] = stack[-1];
    v174 = stack[-2];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcdr(v174);
    v174 = difference2(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    fn = elt(env, 4); /* general!-modular!-expt */
    v174 = (*qfn2(fn))(qenv(fn), stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v175 = times2(stack[-3], v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v174 = qvalue(elt(env, 2)); /* current!-modulus */
    stack[0] = Cremainder(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v174 = stack[-2];
    v174 = qcar(v174);
    v174 = qcdr(v174);
    fn = elt(env, 3); /* mod!# */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v174 = (*qfn2(fn))(qenv(fn), stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v204 = v174;
    v174 = stack[-2];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = qcdr(v174);
    v175 = v174;
    v174 = stack[-2];
    v174 = qcdr(v174);
    stack[-2] = v174;
    goto v138;

v46:
    stack[0] = v204;
    v174 = stack[-1];
    fn = elt(env, 4); /* general!-modular!-expt */
    v174 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v175 = times2(stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v174 = qvalue(elt(env, 2)); /* current!-modulus */
    v174 = Cremainder(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v204 = v174;
    v174 = stack[-2];
    if (v174 == nil) { popv(5); return onevalue(v204); }
    stack[0] = v204;
    v174 = stack[-2];
    fn = elt(env, 3); /* mod!# */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v174 = (*qfn2(fn))(qenv(fn), stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v204 = v174;
    { popv(5); return onevalue(v204); }

v65:
    v174 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* mod!# */
        return (*qfn1(fn))(qenv(fn), v174);
    }
/* error exit handlers */
v111:
    popv(5);
    return nil;
}



/* Code for cl_identifyat */

static Lisp_Object CC_cl_identifyat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v135;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyat");
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
    v135 = stack[0];
    v127 = elt(env, 1); /* true */
    if (v135 == v127) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v135 = stack[0];
    v127 = elt(env, 2); /* false */
    if (v135 == v127) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v135 = stack[0];
    v127 = qvalue(elt(env, 3)); /* cl_identify!-atl!* */
    v127 = Lmember(nil, v135, v127);
    v135 = v127;
    if (v127 == nil) goto v178;
    v127 = v135;
    v127 = qcar(v127);
    { popv(2); return onevalue(v127); }

v178:
    v135 = stack[0];
    v127 = qvalue(elt(env, 3)); /* cl_identify!-atl!* */
    v127 = cons(v135, v127);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    qvalue(elt(env, 3)) = v127; /* cl_identify!-atl!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v177:
    popv(2);
    return nil;
}



/* Code for wupseudodivide */

static Lisp_Object MS_CDECL CC_wupseudodivide(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v123, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wupseudodivide");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wupseudodivide");
#endif
    if (stack >= stacklimit)
    {
        push3(v123,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v123);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v123;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v212 = stack[-4];
    stack[0] = v212;
    v212 = stack[-1];
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    fn = elt(env, 2); /* setkorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    stack[-5] = v212;
    v212 = stack[-4];
    fn = elt(env, 3); /* reorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    stack[-4] = v212;
    v212 = stack[-4];
    fn = elt(env, 4); /* wuconstantp */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    if (!(v212 == nil)) goto v82;
    v212 = stack[-4];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v213 = qcar(v212);
    v212 = stack[-1];
    if (!(equal(v213, v212))) goto v82;
    v212 = stack[-3];
    fn = elt(env, 3); /* reorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    stack[-3] = v212;
    v212 = stack[-3];
    fn = elt(env, 4); /* wuconstantp */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    if (!(v212 == nil)) goto v121;
    v212 = stack[-3];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v213 = qcar(v212);
    v212 = stack[-1];
    if (!(equal(v213, v212))) goto v121;
    v212 = stack[-4];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v212 = qcdr(v212);
    stack[-2] = v212;
    v212 = stack[-3];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v212 = qcdr(v212);
    stack[-1] = v212;
    v213 = stack[-2];
    v212 = stack[-1];
    v212 = difference2(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v213 = add1(v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = (Lisp_Object)1; /* 0 */
    v212 = (Lisp_Object)lessp2(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v212 = v212 ? lisp_true : nil;
    env = stack[-6];
    if (v212 == nil) goto v48;
    v212 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v213 = qvalue(elt(env, 1)); /* nil */
    v212 = stack[0];
    popv(7);
    return cons(v213, v212);

v48:
    v212 = stack[-3];
    v212 = qcar(v212);
    v212 = qcdr(v212);
    stack[0] = v212;
    v213 = stack[-2];
    v212 = stack[-1];
    v212 = difference2(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = add1(v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    fn = elt(env, 5); /* exptf */
    v212 = (*qfn2(fn))(qenv(fn), stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    stack[0] = v212;
    v213 = stack[0];
    v212 = stack[-4];
    fn = elt(env, 6); /* multf */
    v213 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = stack[-3];
    fn = elt(env, 7); /* qremf */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    stack[-1] = v212;
    v213 = stack[0];
    v212 = stack[-1];
    v212 = qcdr(v212);
    fn = elt(env, 8); /* gcdf!* */
    v213 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = stack[-1];
    v212 = qcar(v212);
    fn = elt(env, 8); /* gcdf!* */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    stack[-2] = v212;
    v212 = stack[-1];
    v213 = qcar(v212);
    v212 = stack[-2];
    fn = elt(env, 9); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = stack[-1];
    v213 = qcdr(v212);
    v212 = stack[-2];
    fn = elt(env, 9); /* quotf */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = cons(stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    stack[-1] = v212;
    v212 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = stack[-1];
    v212 = qcar(v212);
    fn = elt(env, 3); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = stack[-1];
    v212 = qcdr(v212);
    fn = elt(env, 3); /* reorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    {
        Lisp_Object v163 = stack[0];
        popv(7);
        return cons(v163, v212);
    }

v121:
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v212 = stack[-4];
    v212 = qcar(v212);
    v213 = qcdr(v212);
    v212 = stack[-3];
    fn = elt(env, 8); /* gcdf!* */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    fn = elt(env, 9); /* quotf */
    v212 = (*qfn2(fn))(qenv(fn), stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    fn = elt(env, 6); /* multf */
    v212 = (*qfn2(fn))(qenv(fn), stack[-1], v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    stack[-4] = v212;
    v212 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v212 = stack[-4];
    fn = elt(env, 3); /* reorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    popv(7);
    return ncons(v212);

v82:
    v212 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-6];
    v213 = qvalue(elt(env, 1)); /* nil */
    v212 = stack[0];
    popv(7);
    return cons(v213, v212);
/* error exit handlers */
v214:
    popv(7);
    return nil;
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140;
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
    v140 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v140 = ncons(v140);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-1];
    {
        Lisp_Object v157 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v157, v140);
    }
/* error exit handlers */
v154:
    popv(2);
    return nil;
}



/* Code for ctx_fromial */

static Lisp_Object CC_ctx_fromial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v140;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_fromial");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v156 = v0;
/* end of prologue */
    v140 = elt(env, 1); /* ctx */
    return list2(v140, v156);
}



/* Code for unaryrd */

static Lisp_Object MS_CDECL CC_unaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "unaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unaryrd");
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
    fn = elt(env, 1); /* mathml */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-1];
    stack[0] = v77;
    fn = elt(env, 2); /* lex */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v156;
    v77 = stack[0];
    popv(2);
    return ncons(v77);
/* error exit handlers */
v156:
    popv(2);
    return nil;
}



/* Code for dmconv0 */

static Lisp_Object CC_dmconv0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v104, v130;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dmconv0");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v0;
/* end of prologue */
    v82 = v130;
    if (v82 == nil) goto v110;
    v104 = v130;
    v82 = elt(env, 2); /* !:gi!: */
    if (v104 == v82) goto v77;
    v82 = v130;
    goto v91;

v91:
    qvalue(elt(env, 4)) = v82; /* dmd!* */
    return onevalue(v82);

v77:
    v82 = elt(env, 3); /* !:crn!: */
    goto v91;

v110:
    v82 = elt(env, 1); /* !:rn!: */
    goto v91;
}



/* Code for band_matrix */

static Lisp_Object CC_band_matrix(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for band_matrix");
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
    stack[-10] = nil;
    v163 = stack[-8];
    v163 = integerp(v163);
    if (!(v163 == nil)) goto v78;
    v163 = elt(env, 1); /* "Error in band_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 8); /* rederr */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    goto v78;

v78:
    v163 = stack[-9];
    if (!consp(v163)) goto v129;
    v163 = stack[-9];
    v226 = qcar(v163);
    v163 = elt(env, 2); /* list */
    if (v226 == v163) goto v84;
    v163 = elt(env, 3); /* "Error in band_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 8); /* rederr */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    goto v130;

v130:
    v163 = stack[-9];
    v163 = Llength(nil, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    stack[-7] = v163;
    v163 = stack[-7];
    v163 = Levenp(nil, v163);
    env = stack[-11];
    if (v163 == nil) goto v132;
    v163 = elt(env, 4); /* "Error in band matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 8); /* rederr */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    goto v132;

v132:
    stack[0] = elt(env, 5); /* quotient */
    v163 = stack[-7];
    v226 = add1(v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v163 = (Lisp_Object)33; /* 2 */
    v163 = list3(stack[0], v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    fn = elt(env, 9); /* reval */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    stack[-6] = v163;
    v163 = stack[-6];
    v163 = integerp(v163);
    if (v163 == nil) goto v199;
    v163 = stack[-6];
    v226 = v163;
    goto v75;

v75:
    v163 = stack[-8];
    v163 = (Lisp_Object)greaterp2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v163 = v163 ? lisp_true : nil;
    env = stack[-11];
    if (v163 == nil) goto v88;
    v163 = elt(env, 6); /* "Error in band_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 8); /* rederr */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    goto v94;

v94:
    v163 = (Lisp_Object)17; /* 1 */
    stack[-5] = v163;
    goto v112;

v112:
    v226 = stack[-8];
    v163 = stack[-5];
    v163 = difference2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v163 = Lminusp(nil, v163);
    env = stack[-11];
    if (!(v163 == nil)) { Lisp_Object res = stack[-10]; popv(12); return onevalue(res); }
    v163 = (Lisp_Object)17; /* 1 */
    stack[-4] = v163;
    goto v190;

v190:
    v226 = stack[-8];
    v163 = stack[-4];
    v163 = difference2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v163 = Lminusp(nil, v163);
    env = stack[-11];
    if (v163 == nil) goto v185;
    v163 = stack[-5];
    v163 = add1(v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    stack[-5] = v163;
    goto v112;

v185:
    v226 = stack[-6];
    v163 = stack[-5];
    v226 = difference2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v163 = stack[-4];
    v226 = plus2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v163 = (Lisp_Object)1; /* 0 */
    v163 = (Lisp_Object)greaterp2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v163 = v163 ? lisp_true : nil;
    env = stack[-11];
    if (v163 == nil) goto v186;
    v226 = stack[-6];
    v163 = stack[-5];
    v226 = difference2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v163 = stack[-4];
    v226 = plus2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v163 = stack[-7];
    v163 = (Lisp_Object)lesseq2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v163 = v163 ? lisp_true : nil;
    env = stack[-11];
    if (v163 == nil) goto v186;
    stack[-3] = stack[-10];
    stack[-2] = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-9];
    v226 = stack[-6];
    v163 = stack[-5];
    v226 = difference2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v163 = stack[-4];
    v163 = plus2(v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    fn = elt(env, 10); /* nth */
    v163 = (*qfn2(fn))(qenv(fn), stack[0], v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    fn = elt(env, 11); /* setmat */
    v163 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[-2], stack[-1], v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    goto v186;

v186:
    v163 = stack[-4];
    v163 = add1(v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    stack[-4] = v163;
    goto v190;

v88:
    v226 = stack[-8];
    v163 = stack[-8];
    fn = elt(env, 12); /* mkmatrix */
    v163 = (*qfn2(fn))(qenv(fn), v226, v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    stack[-10] = v163;
    goto v94;

v199:
    v163 = stack[-6];
    fn = elt(env, 9); /* reval */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    v226 = v163;
    goto v75;

v84:
    v163 = stack[-9];
    v163 = qcdr(v163);
    stack[-9] = v163;
    goto v130;

v129:
    v163 = stack[-9];
    v163 = ncons(v163);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-11];
    stack[-9] = v163;
    goto v130;
/* error exit handlers */
v227:
    popv(12);
    return nil;
}



/* Code for resume */

static Lisp_Object CC_resume(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v178, v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resume");
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
    v103 = v1;
    v178 = v0;
/* end of prologue */
    v56 = v103;
    if (v56 == nil) goto v155;
    v56 = v103;
    v56 = qcar(v56);
    v57 = qcar(v56);
    v56 = v103;
    v56 = qcar(v56);
    v56 = qcdr(v56);
    v56 = qcar(v56);
    v103 = qcdr(v103);
    {
        popv(1);
        fn = elt(env, 3); /* amatch */
        return (*qfnn(fn))(qenv(fn), 4, v57, v56, v178, v103);
    }

v155:
    v103 = v178;
    fn = elt(env, 4); /* chk */
    v178 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[0];
    v103 = qvalue(elt(env, 1)); /* t */
    if (v178 == v103) goto v138;
    v103 = nil;
    { popv(1); return onevalue(v103); }

v138:
    v103 = qvalue(elt(env, 2)); /* substitution */
    {
        popv(1);
        fn = elt(env, 5); /* bsubs */
        return (*qfn1(fn))(qenv(fn), v103);
    }
/* error exit handlers */
v68:
    popv(1);
    return nil;
}



/* Code for gftimesn */

static Lisp_Object CC_gftimesn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v230, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gftimesn");
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
    v230 = v1;
    v199 = v0;
/* end of prologue */
    v229 = v199;
    v229 = qcar(v229);
    if (!consp(v229)) goto v156;
    v229 = v199;
    v229 = qcar(v229);
    stack[-4] = v229;
    v229 = v199;
    v229 = qcdr(v229);
    stack[-3] = v229;
    v229 = v230;
    v229 = qcar(v229);
    stack[-2] = v229;
    v229 = v230;
    v229 = qcdr(v229);
    stack[-1] = v229;
    v230 = stack[-4];
    v229 = stack[-2];
    fn = elt(env, 1); /* times!: */
    stack[0] = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v230 = stack[-3];
    v229 = stack[-1];
    fn = elt(env, 1); /* times!: */
    v229 = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    fn = elt(env, 2); /* difference!: */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v229);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v230 = stack[-4];
    v229 = stack[-1];
    fn = elt(env, 1); /* times!: */
    stack[-1] = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v230 = stack[-3];
    v229 = stack[-2];
    fn = elt(env, 1); /* times!: */
    v229 = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    fn = elt(env, 3); /* plus!: */
    v229 = (*qfn2(fn))(qenv(fn), stack[-1], v229);
    nil = C_nil;
    if (exception_pending()) goto v122;
    {
        Lisp_Object v144 = stack[0];
        popv(6);
        return cons(v144, v229);
    }

v156:
    v229 = v199;
    {
        popv(6);
        fn = elt(env, 4); /* gfftimes */
        return (*qfn2(fn))(qenv(fn), v229, v230);
    }
/* error exit handlers */
v122:
    popv(6);
    return nil;
}



/* Code for formatfort */

static Lisp_Object CC_formatfort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v236, v237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formatfort");
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
    stack[-2] = qvalue(elt(env, 1)); /* !*lower */
    qvalue(elt(env, 1)) = nil; /* !*lower */
    v235 = (Lisp_Object)4801; /* 300 */
    v235 = Llinelength(nil, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[-4] = v235;
    v235 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v235; /* !*posn!* */
    v235 = stack[0];
    stack[-1] = v235;
    goto v154;

v154:
    v235 = stack[-1];
    if (v235 == nil) goto v153;
    v235 = stack[-1];
    v235 = qcar(v235);
    stack[0] = v235;
    v235 = stack[0];
    v235 = Lconsp(nil, v235);
    env = stack[-5];
    if (v235 == nil) goto v100;
    v235 = stack[0];
    fn = elt(env, 11); /* lispeval */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    goto v83;

v83:
    v235 = stack[-1];
    v235 = qcdr(v235);
    stack[-1] = v235;
    goto v154;

v100:
    v235 = stack[0];
    v235 = integerp(v235);
    if (v235 == nil) goto v117;
    v236 = stack[0];
    v235 = qvalue(elt(env, 4)); /* maxint */
    v235 = (Lisp_Object)greaterp2(v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v235 = v235 ? lisp_true : nil;
    env = stack[-5];
    if (!(v235 == nil)) goto v198;
    stack[-3] = stack[0];
    v235 = qvalue(elt(env, 4)); /* maxint */
    v235 = negate(v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v235 = (Lisp_Object)lessp2(stack[-3], v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v235 = v235 ? lisp_true : nil;
    env = stack[-5];
    if (!(v235 == nil)) goto v198;

v117:
    v235 = stack[0];
    v235 = Lexplodec(nil, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[-3] = v235;
    v235 = stack[0];
    v235 = Lfloatp(nil, v235);
    env = stack[-5];
    if (v235 == nil) goto v194;
    v235 = qvalue(elt(env, 5)); /* !*double */
    if (v235 == nil) goto v188;
    v236 = elt(env, 6); /* e */
    v235 = stack[-3];
    v235 = Lmemq(nil, v236, v235);
    if (v235 == nil) goto v90;
    v237 = elt(env, 7); /* !D */
    v236 = elt(env, 6); /* e */
    v235 = stack[-3];
    v235 = Lsubst(nil, 3, v237, v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[-3] = v235;
    goto v194;

v194:
    stack[0] = qvalue(elt(env, 2)); /* !*posn!* */
    v235 = stack[-3];
    v235 = Llength(nil, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v236 = plus2(stack[0], v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v235 = qvalue(elt(env, 10)); /* fortlinelen!* */
    v235 = (Lisp_Object)greaterp2(v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v235 = v235 ? lisp_true : nil;
    env = stack[-5];
    if (v235 == nil) goto v238;
    fn = elt(env, 12); /* fortcontline */
    v235 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    goto v238;

v238:
    v235 = stack[-3];
    stack[0] = v235;
    goto v239;

v239:
    v235 = stack[0];
    if (v235 == nil) goto v83;
    v235 = stack[0];
    v235 = qcar(v235);
    fn = elt(env, 13); /* pprin2 */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v235 = stack[0];
    v235 = qcdr(v235);
    stack[0] = v235;
    goto v239;

v90:
    v236 = elt(env, 8); /* !E */
    v235 = stack[-3];
    v235 = Lmemq(nil, v236, v235);
    if (v235 == nil) goto v240;
    v237 = elt(env, 7); /* !D */
    v236 = elt(env, 8); /* !E */
    v235 = stack[-3];
    v235 = Lsubst(nil, 3, v237, v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[-3] = v235;
    goto v194;

v240:
    v236 = stack[-3];
    v235 = elt(env, 9); /* (d !0) */
    v235 = Lappend(nil, v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[-3] = v235;
    goto v194;

v188:
    v236 = elt(env, 6); /* e */
    v235 = stack[-3];
    v235 = Lmemq(nil, v236, v235);
    if (v235 == nil) goto v194;
    v237 = elt(env, 8); /* !E */
    v236 = elt(env, 6); /* e */
    v235 = stack[-3];
    v235 = Lsubst(nil, 3, v237, v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[-3] = v235;
    goto v194;

v198:
    v235 = stack[0];
    fn = elt(env, 14); /* i2rd!* */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v235 = qcdr(v235);
    stack[0] = v235;
    goto v117;

v153:
    v235 = stack[-4];
    v235 = Llinelength(nil, v235);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v235 = nil;
    qvalue(elt(env, 1)) = stack[-2]; /* !*lower */
    { popv(6); return onevalue(v235); }
/* error exit handlers */
v216:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-2]; /* !*lower */
    popv(6);
    return nil;
}



/* Code for fctargs */

static Lisp_Object CC_fctargs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctargs");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v0;
/* end of prologue */
    v61 = qvalue(elt(env, 1)); /* depl!* */
    v61 = Lassoc(nil, v60, v61);
    v60 = v61;
    if (v61 == nil) goto v65;
    v60 = qcdr(v60);
    return onevalue(v60);

v65:
    v60 = nil;
    return onevalue(v60);
}



/* Code for factorial */

static Lisp_Object CC_factorial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorial");
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
    v103 = stack[-1];
    v103 = integerp(v103);
    if (v103 == nil) goto v80;
    v178 = stack[-1];
    v103 = (Lisp_Object)1; /* 0 */
    v103 = (Lisp_Object)lessp2(v178, v103);
    nil = C_nil;
    if (exception_pending()) goto v150;
    v103 = v103 ? lisp_true : nil;
    env = stack[-3];
    if (!(v103 == nil)) goto v80;
    v103 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* nfactorial */
        return (*qfn1(fn))(qenv(fn), v103);
    }

v80:
    stack[-2] = elt(env, 1); /* arith */
    stack[0] = (Lisp_Object)65; /* 4 */
    v178 = stack[-1];
    v103 = elt(env, 2); /* "invalid factorial argument" */
    v103 = list2(v178, v103);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-3];
    {
        Lisp_Object v126 = stack[-2];
        Lisp_Object v137 = stack[0];
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v126, v137, v103);
    }
/* error exit handlers */
v150:
    popv(4);
    return nil;
}



/* Code for rl_prepfof */

static Lisp_Object CC_rl_prepfof(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_prepfof");
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
    v65 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_csimpl */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* rl_prepfof1 */
        return (*qfn1(fn))(qenv(fn), v65);
    }
/* error exit handlers */
v118:
    popv(1);
    return nil;
}



/* Code for delasc */

static Lisp_Object CC_delasc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v126, v137;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delasc");
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
    v137 = nil;
    goto v77;

v77:
    v150 = stack[0];
    if (v150 == nil) goto v136;
    v150 = stack[0];
    v150 = qcar(v150);
    if (!consp(v150)) goto v202;
    v126 = stack[-1];
    v150 = stack[0];
    v150 = qcar(v150);
    v150 = qcar(v150);
    if (!(equal(v126, v150))) goto v202;

v60:
    v150 = stack[0];
    v150 = qcdr(v150);
    stack[0] = v150;
    goto v77;

v202:
    v150 = stack[0];
    v150 = qcar(v150);
    v126 = v137;
    v150 = cons(v150, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    v137 = v150;
    goto v60;

v136:
    v150 = v137;
        popv(3);
        return Lnreverse(nil, v150);
/* error exit handlers */
v135:
    popv(3);
    return nil;
}



/* Code for ibalp_unvar!-unsatlist */

static Lisp_Object CC_ibalp_unvarKunsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v254, v255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_unvar-unsatlist");
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
    v254 = v0;
/* end of prologue */
    stack[-5] = v254;
    goto v66;

v66:
    v254 = stack[-5];
    if (v254 == nil) goto v77;
    v254 = stack[-5];
    v254 = qcar(v254);
    stack[-3] = v254;
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v255 = stack[-4];
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    fn = elt(env, 2); /* delq */
    v254 = (*qfn2(fn))(qenv(fn), v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    if (!(v254 == nil)) goto v150;
    v254 = stack[-3];
    v254 = qcar(v254);
    stack[-2] = v254;
    goto v132;

v132:
    v254 = stack[-2];
    if (v254 == nil) goto v131;
    v254 = stack[-2];
    v254 = qcar(v254);
    stack[-1] = v254;
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = add1(v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v254 = stack[-1];
    fn = elt(env, 4); /* ibalp_calcmom */
    v254 = (*qfn1(fn))(qenv(fn), v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-2];
    v254 = qcdr(v254);
    stack[-2] = v254;
    goto v132;

v131:
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcar(v254);
    stack[-2] = v254;
    goto v109;

v109:
    v254 = stack[-2];
    if (v254 == nil) goto v108;
    v254 = stack[-2];
    v254 = qcar(v254);
    stack[-1] = v254;
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = add1(v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v254 = stack[-1];
    fn = elt(env, 4); /* ibalp_calcmom */
    v254 = (*qfn1(fn))(qenv(fn), v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-2];
    v254 = qcdr(v254);
    stack[-2] = v254;
    goto v109;

v108:
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    stack[-1] = v254;
    goto v195;

v195:
    v254 = stack[-1];
    if (v254 == nil) goto v257;
    v254 = stack[-1];
    v254 = qcar(v254);
    v255 = v254;
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    stack[0] = qcdr(v255);
    v255 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    fn = elt(env, 2); /* delq */
    v254 = (*qfn2(fn))(qenv(fn), v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-1];
    v254 = qcdr(v254);
    stack[-1] = v254;
    goto v195;

v257:
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v255 = qcdr(v254);
    v254 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-3];
    fn = elt(env, 5); /* ibalp_getnewwl */
    v254 = (*qfn1(fn))(qenv(fn), v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    stack[-1] = v254;
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v255 = stack[-1];
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = cons(v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v255 = stack[-3];
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = cons(v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-3];
    fn = elt(env, 5); /* ibalp_getnewwl */
    v254 = (*qfn1(fn))(qenv(fn), v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    stack[-1] = v254;
    v254 = stack[-1];
    if (v254 == nil) goto v150;
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v255 = stack[-1];
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = cons(v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    stack[0] = qcdr(v254);
    v255 = stack[-3];
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = cons(v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v254 = (*qfn2(fn))(qenv(fn), stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    goto v150;

v150:
    v254 = stack[-5];
    v254 = qcdr(v254);
    stack[-5] = v254;
    goto v66;

v77:
    v254 = nil;
    { popv(7); return onevalue(v254); }
/* error exit handlers */
v256:
    popv(7);
    return nil;
}



/* Code for om2ir */

static Lisp_Object MS_CDECL CC_om2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2ir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for om2ir");
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
    v121 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v121;
    v121 = elt(env, 2); /* (safe_atts char ch atts count temp space temp2) 
*/
    fn = elt(env, 13); /* fluid */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    v94 = elt(env, 3); /* !! */
    v121 = (Lisp_Object)513; /* 32 */
    v121 = list2(v94, v121);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    v121 = Lcompress(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    qvalue(elt(env, 4)) = v121; /* space */
    v121 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v121; /* count */
    v121 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    qvalue(elt(env, 6)) = v121; /* ch */
    v121 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v121; /* temp2 */
    fn = elt(env, 14); /* lex */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    v94 = qvalue(elt(env, 8)); /* char */
    v121 = elt(env, 9); /* (o m o b j) */
    if (equal(v94, v121)) goto v104;
    v94 = elt(env, 10); /* "<omobj>" */
    v121 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 15); /* errorml */
    v121 = (*qfn2(fn))(qenv(fn), v94, v121);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    goto v82;

v82:
    fn = elt(env, 14); /* lex */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    v94 = qvalue(elt(env, 8)); /* char */
    v121 = elt(env, 11); /* (!/ o m o b j) */
    if (equal(v94, v121)) goto v137;
    v94 = elt(env, 12); /* "</omobj>" */
    v121 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 15); /* errorml */
    v121 = (*qfn2(fn))(qenv(fn), v94, v121);
    nil = C_nil;
    if (exception_pending()) goto v201;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v137:
    v121 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v104:
    fn = elt(env, 14); /* lex */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    fn = elt(env, 16); /* omobj */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    stack[0] = v121;
    goto v82;
/* error exit handlers */
v201:
    popv(2);
    return nil;
}



/* Code for mkmatrix */

static Lisp_Object CC_mkmatrix(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v170;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkmatrix");
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
    stack[-10] = elt(env, 1); /* mat */
    v185 = (Lisp_Object)17; /* 1 */
    stack[-7] = v185;
    v170 = stack[-9];
    v185 = stack[-7];
    v185 = difference2(v170, v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lminusp(nil, v185);
    env = stack[-11];
    if (v185 == nil) goto v79;
    v185 = qvalue(elt(env, 2)); /* nil */
    goto v136;

v136:
    {
        Lisp_Object v259 = stack[-10];
        popv(12);
        return cons(v259, v185);
    }

v79:
    v185 = (Lisp_Object)17; /* 1 */
    stack[-3] = v185;
    v170 = stack[-8];
    v185 = stack[-3];
    v185 = difference2(v170, v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lminusp(nil, v185);
    env = stack[-11];
    if (v185 == nil) goto v103;
    v185 = qvalue(elt(env, 2)); /* nil */
    goto v198;

v198:
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    stack[-5] = v185;
    stack[-6] = v185;
    goto v78;

v78:
    v185 = stack[-7];
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    stack[-7] = v185;
    v170 = stack[-9];
    v185 = stack[-7];
    v185 = difference2(v170, v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lminusp(nil, v185);
    env = stack[-11];
    if (v185 == nil) goto v125;
    v185 = stack[-6];
    goto v136;

v125:
    stack[-4] = stack[-5];
    v185 = (Lisp_Object)17; /* 1 */
    stack[-3] = v185;
    v170 = stack[-8];
    v185 = stack[-3];
    v185 = difference2(v170, v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lminusp(nil, v185);
    env = stack[-11];
    if (v185 == nil) goto v18;
    v185 = qvalue(elt(env, 2)); /* nil */
    goto v107;

v107:
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lrplacd(nil, stack[-4], v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = stack[-5];
    v185 = qcdr(v185);
    stack[-5] = v185;
    goto v78;

v18:
    v185 = (Lisp_Object)1; /* 0 */
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    stack[-1] = v185;
    stack[-2] = v185;
    goto v108;

v108:
    v185 = stack[-3];
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    stack[-3] = v185;
    v170 = stack[-8];
    v185 = stack[-3];
    v185 = difference2(v170, v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lminusp(nil, v185);
    env = stack[-11];
    if (v185 == nil) goto v260;
    v185 = stack[-2];
    goto v107;

v260:
    stack[0] = stack[-1];
    v185 = (Lisp_Object)1; /* 0 */
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lrplacd(nil, stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    goto v108;

v103:
    v185 = (Lisp_Object)1; /* 0 */
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    stack[-1] = v185;
    stack[-2] = v185;
    goto v67;

v67:
    v185 = stack[-3];
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    stack[-3] = v185;
    v170 = stack[-8];
    v185 = stack[-3];
    v185 = difference2(v170, v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lminusp(nil, v185);
    env = stack[-11];
    if (v185 == nil) goto v51;
    v185 = stack[-2];
    goto v198;

v51:
    stack[0] = stack[-1];
    v185 = (Lisp_Object)1; /* 0 */
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = Lrplacd(nil, stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-11];
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    goto v67;
/* error exit handlers */
v231:
    popv(12);
    return nil;
}



/* Code for gvarlis1 */

static Lisp_Object CC_gvarlis1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gvarlis1");
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
    goto v136;

v136:
    v98 = stack[-1];
    if (v98 == nil) goto v77;
    v98 = stack[-1];
    v177 = qcar(v98);
    v98 = stack[0];
    fn = elt(env, 1); /* gvar1 */
    v177 = (*qfn2(fn))(qenv(fn), v177, v98);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v98 = stack[-2];
    v98 = cons(v177, v98);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    stack[-2] = v98;
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v136;

v77:
    v98 = stack[0];
    v177 = v98;
    goto v66;

v66:
    v98 = stack[-2];
    if (v98 == nil) { popv(4); return onevalue(v177); }
    v98 = stack[-2];
    v98 = qcar(v98);
    fn = elt(env, 2); /* union */
    v98 = (*qfn2(fn))(qenv(fn), v98, v177);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v177 = v98;
    v98 = stack[-2];
    v98 = qcdr(v98);
    stack[-2] = v98;
    goto v66;
/* error exit handlers */
v131:
    popv(4);
    return nil;
}



/* Code for oprinla */

static Lisp_Object CC_oprinla(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v135, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oprinla");
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
    v135 = v0;
/* end of prologue */
    v98 = v135;
    v127 = elt(env, 1); /* lapr */
    v127 = get(v98, v127);
    env = stack[0];
    v98 = v127;
    if (v127 == nil) goto v104;
    v127 = v98;
    fn = elt(env, 5); /* prin2la */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v177;
    goto v118;

v118:
    v127 = nil;
    { popv(1); return onevalue(v127); }

v104:
    v98 = v135;
    v127 = elt(env, 2); /* prtch */
    v127 = get(v98, v127);
    env = stack[0];
    v98 = v127;
    if (v127 == nil) goto v128;
    v127 = v98;
    fn = elt(env, 5); /* prin2la */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v177;
    goto v118;

v128:
    v98 = v135;
    v127 = elt(env, 3); /* lapop */
    v127 = get(v98, v127);
    env = stack[0];
    v98 = v127;
    if (v127 == nil) goto v150;
    v127 = v98;
    fn = elt(env, 5); /* prin2la */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[0];
    v127 = elt(env, 4); /* !  */
    fn = elt(env, 5); /* prin2la */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v177;
    goto v118;

v150:
    v127 = v135;
    fn = elt(env, 6); /* prinlatom */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v177;
    goto v118;
/* error exit handlers */
v177:
    popv(1);
    return nil;
}



/* Code for coposp */

static Lisp_Object CC_coposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v0;
/* end of prologue */
    v104 = v130;
    v104 = qcdr(v104);
    v104 = (v104 == nil ? lisp_true : nil);
    if (!(v104 == nil)) return onevalue(v104);
    v104 = v130;
    v104 = qcar(v104);
    if (!consp(v104)) goto v156;
    v104 = v130;
    v104 = qcdr(v104);
    {
        fn = elt(env, 1); /* covposp */
        return (*qfn1(fn))(qenv(fn), v104);
    }

v156:
    v104 = v130;
    v104 = qcdr(v104);
    {
        fn = elt(env, 2); /* contposp */
        return (*qfn1(fn))(qenv(fn), v104);
    }
}



/* Code for prepd1 */

static Lisp_Object CC_prepd1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v138;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepd1");
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
    v138 = v0;
/* end of prologue */
    v58 = v138;
    if (!consp(v58)) return onevalue(v138);
    v58 = v138;
    v59 = qcar(v58);
    v58 = elt(env, 1); /* prepfn */
    v58 = get(v59, v58);
    v59 = v138;
        return Lapply1(nil, v58, v59);
}



/* Code for groeb!=newpair */

static Lisp_Object MS_CDECL CC_groebMnewpair(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v123, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v127, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=newpair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=newpair");
#endif
    if (stack >= stacklimit)
    {
        push3(v123,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v123);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v123;
    stack[-3] = v1;
    stack[-1] = v0;
/* end of prologue */
    v200 = stack[-3];
    fn = elt(env, 1); /* bas_dpoly */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    v200 = stack[-2];
    fn = elt(env, 1); /* bas_dpoly */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    fn = elt(env, 3); /* mo_lcm */
    v200 = (*qfn2(fn))(qenv(fn), stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    stack[0] = v200;
    stack[-4] = stack[-1];
    v135 = stack[0];
    v127 = stack[-3];
    v200 = stack[-2];
    fn = elt(env, 4); /* groeb!=weight */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v135, v127, v200);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    v127 = stack[-3];
    v200 = stack[-2];
    v200 = list2(v127, v200);
    nil = C_nil;
    if (exception_pending()) goto v131;
    {
        Lisp_Object v132 = stack[-4];
        Lisp_Object v133 = stack[-1];
        Lisp_Object v134 = stack[0];
        popv(6);
        return list3star(v132, v133, v134, v200);
    }
/* error exit handlers */
v131:
    popv(6);
    return nil;
}



/* Code for ilog2 */

static Lisp_Object CC_ilog2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ilog2");
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
    v43 = stack[-2];
    v111 = (Lisp_Object)1; /* 0 */
    v111 = (Lisp_Object)lesseq2(v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v111 = v111 ? lisp_true : nil;
    env = stack[-4];
    if (v111 == nil) goto v77;
    v43 = stack[-2];
    v111 = elt(env, 0); /* ilog2 */
    fn = elt(env, 2); /* terrlst */
    v111 = (*qfn2(fn))(qenv(fn), v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    goto v77;

v77:
    v111 = (Lisp_Object)33; /* 2 */
    stack[0] = v111;
    v111 = stack[0];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-1] = v111;
    goto v197;

v197:
    v43 = stack[-2];
    v111 = stack[0];
    v111 = (Lisp_Object)greaterp2(v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v111 = v111 ? lisp_true : nil;
    env = stack[-4];
    if (v111 == nil) goto v101;
    v43 = stack[0];
    v111 = stack[-1];
    v111 = cons(v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-1] = v111;
    v43 = stack[0];
    v111 = stack[0];
    v111 = times2(v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[0] = v111;
    goto v197;

v101:
    v111 = (Lisp_Object)1; /* 0 */
    stack[-3] = v111;
    goto v95;

v95:
    v111 = stack[-1];
    v43 = qcar(v111);
    stack[0] = v43;
    v111 = (Lisp_Object)33; /* 2 */
    if (v43 == v111) goto v152;
    v111 = stack[-1];
    v111 = qcdr(v111);
    stack[-1] = v111;
    v43 = stack[-2];
    v111 = stack[0];
    v111 = (Lisp_Object)geq2(v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v111 = v111 ? lisp_true : nil;
    env = stack[-4];
    if (v111 == nil) goto v48;
    v43 = stack[-2];
    v111 = stack[0];
    v111 = quot2(v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-2] = v111;
    v111 = stack[-3];
    v111 = add1(v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-3] = v111;
    goto v48;

v48:
    v43 = stack[-3];
    v111 = (Lisp_Object)33; /* 2 */
    v111 = times2(v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-3] = v111;
    goto v95;

v152:
    v43 = stack[-2];
    v111 = (Lisp_Object)33; /* 2 */
    v111 = (Lisp_Object)geq2(v43, v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v111 = v111 ? lisp_true : nil;
    env = stack[-4];
    if (v111 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v111 = stack[-3];
    v111 = add1(v111);
    nil = C_nil;
    if (exception_pending()) goto v188;
    stack[-3] = v111;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v188:
    popv(5);
    return nil;
}



setup_type const u18_setup[] =
{
    {"quotof",                  too_few_2,      CC_quotof,     wrong_no_2},
    {"decprec2internal",        CC_decprec2internal,too_many_1,wrong_no_1},
    {"rl_csimpl",               CC_rl_csimpl,   too_many_1,    wrong_no_1},
    {"vunion",                  too_few_2,      CC_vunion,     wrong_no_2},
    {"ibalp_dav",               too_few_2,      CC_ibalp_dav,  wrong_no_2},
    {"vdp_zero?",               CC_vdp_zeroW,   too_many_1,    wrong_no_1},
    {"naryom",                  CC_naryom,      too_many_1,    wrong_no_1},
    {"pfordp",                  too_few_2,      CC_pfordp,     wrong_no_2},
    {"flatindl",                CC_flatindl,    too_many_1,    wrong_no_1},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"general-evaluate-mod-p",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKevaluateKmodKp},
    {"sgn",                     CC_sgn,         too_many_1,    wrong_no_1},
    {"gf2cr:",                  CC_gf2crT,      too_many_1,    wrong_no_1},
    {"innprodkp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_innprodkp},
    {"ofsf_clnegrel",           too_few_2,      CC_ofsf_clnegrel,wrong_no_2},
    {"mkzl",                    CC_mkzl,        too_many_1,    wrong_no_1},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"ibalp_unitprop",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_unitprop},
    {"ev_lexcomp",              too_few_2,      CC_ev_lexcomp, wrong_no_2},
    {"rationalizesq",           CC_rationalizesq,too_many_1,   wrong_no_1},
    {"vdpequal",                too_few_2,      CC_vdpequal,   wrong_no_2},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {"gfdot",                   too_few_2,      CC_gfdot,      wrong_no_2},
    {"lesspcdr",                too_few_2,      CC_lesspcdr,   wrong_no_2},
    {"setk0",                   too_few_2,      CC_setk0,      wrong_no_2},
    {"fs:null-angle",           CC_fsTnullKangle,too_many_1,   wrong_no_1},
    {"merge",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_merge},
    {"mod_eval_uni_poly",       too_few_2,      CC_mod_eval_uni_poly,wrong_no_2},
    {"cl_identifyat",           CC_cl_identifyat,too_many_1,   wrong_no_1},
    {"wupseudodivide",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_wupseudodivide},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"ctx_fromial",             CC_ctx_fromial, too_many_1,    wrong_no_1},
    {"unaryrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_unaryrd},
    {"dmconv0",                 CC_dmconv0,     too_many_1,    wrong_no_1},
    {"band_matrix",             too_few_2,      CC_band_matrix,wrong_no_2},
    {"resume",                  too_few_2,      CC_resume,     wrong_no_2},
    {"gftimesn",                too_few_2,      CC_gftimesn,   wrong_no_2},
    {"formatfort",              CC_formatfort,  too_many_1,    wrong_no_1},
    {"fctargs",                 CC_fctargs,     too_many_1,    wrong_no_1},
    {"factorial",               CC_factorial,   too_many_1,    wrong_no_1},
    {"rl_prepfof",              CC_rl_prepfof,  too_many_1,    wrong_no_1},
    {"delasc",                  too_few_2,      CC_delasc,     wrong_no_2},
    {"ibalp_unvar-unsatlist",   too_few_2,      CC_ibalp_unvarKunsatlist,wrong_no_2},
    {"om2ir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2ir},
    {"mkmatrix",                too_few_2,      CC_mkmatrix,   wrong_no_2},
    {"gvarlis1",                too_few_2,      CC_gvarlis1,   wrong_no_2},
    {"oprinla",                 CC_oprinla,     too_many_1,    wrong_no_1},
    {"coposp",                  CC_coposp,      too_many_1,    wrong_no_1},
    {"prepd1",                  CC_prepd1,      too_many_1,    wrong_no_1},
    {"groeb=newpair",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMnewpair},
    {"ilog2",                   CC_ilog2,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u18", (two_args *)"16137 925795 9745105", 0}
};

/* end of generated code */
