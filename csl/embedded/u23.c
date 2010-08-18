
/* $destdir/generated-c\u23.c Machine generated C code */

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


/* Code for gfplusn */

static Lisp_Object CC_gfplusn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfplusn");
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
    v10 = stack[-1];
    v10 = qcar(v10);
    if (!consp(v10)) goto v12;
    v10 = stack[-1];
    v11 = qcar(v10);
    v10 = stack[0];
    v10 = qcar(v10);
    fn = elt(env, 1); /* plus!: */
    stack[-2] = (*qfn2(fn))(qenv(fn), v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v10 = stack[-1];
    v11 = qcdr(v10);
    v10 = stack[0];
    v10 = qcdr(v10);
    fn = elt(env, 1); /* plus!: */
    v10 = (*qfn2(fn))(qenv(fn), v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    {
        Lisp_Object v14 = stack[-2];
        popv(4);
        return cons(v14, v10);
    }

v12:
    v11 = stack[-1];
    v10 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* gffplus */
        return (*qfn2(fn))(qenv(fn), v11, v10);
    }
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for mkfortterpri */

static Lisp_Object MS_CDECL CC_mkfortterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkfortterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkfortterpri");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v15 = elt(env, 1); /* fortterpri */
    return ncons(v15);
}



/* Code for clogsq!* */

static Lisp_Object CC_clogsqH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clogsq*");
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
    v19 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* !*div */
    qvalue(elt(env, 1)) = nil; /* !*div */
    stack[-2] = qvalue(elt(env, 2)); /* !*combinelogs */
    qvalue(elt(env, 2)) = nil; /* !*combinelogs */
    stack[-1] = qvalue(elt(env, 3)); /* !*expandlogs */
    qvalue(elt(env, 3)) = nil; /* !*expandlogs */
    v20 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v20; /* !*expandlogs */
    qvalue(elt(env, 1)) = v20; /* !*div */
    v20 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*uncached */
    qvalue(elt(env, 5)) = v20; /* !*uncached */
    fn = elt(env, 7); /* prepsq */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    fn = elt(env, 8); /* simp */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* !*uncached */
    v20 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 3)) = v20; /* !*expandlogs */
    fn = elt(env, 9); /* prepsq!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-4];
    fn = elt(env, 10); /* comblog */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-4];
    fn = elt(env, 11); /* simp!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-1]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-2]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-3]; /* !*div */
    { popv(5); return onevalue(v19); }
/* error exit handlers */
v3:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-1]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-2]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-3]; /* !*div */
    popv(5);
    return nil;
v21:
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* !*uncached */
    qvalue(elt(env, 3)) = stack[-1]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-2]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-3]; /* !*div */
    popv(5);
    return nil;
}



/* Code for ratfunpri1 */

static Lisp_Object CC_ratfunpri1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratfunpri1");
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
    stack[0] = v0;
/* end of prologue */
    v107 = qvalue(elt(env, 1)); /* spare!* */
    v106 = (Lisp_Object)33; /* 2 */
    v106 = plus2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    qvalue(elt(env, 1)) = v106; /* spare!* */
    v106 = stack[0];
    v106 = qcdr(v106);
    v108 = qcar(v106);
    v107 = (Lisp_Object)1; /* 0 */
    v106 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* layout!-formula */
    v106 = (*qfnn(fn))(qenv(fn), 3, v108, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[-7] = v106;
    if (v106 == nil) goto v110;
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcdr(v106);
    v108 = qcar(v106);
    v107 = (Lisp_Object)1; /* 0 */
    v106 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* layout!-formula */
    v106 = (*qfnn(fn))(qenv(fn), 3, v108, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[-6] = v106;
    if (v106 == nil) goto v110;
    v107 = qvalue(elt(env, 1)); /* spare!* */
    v106 = (Lisp_Object)33; /* 2 */
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    qvalue(elt(env, 1)) = v106; /* spare!* */
    stack[0] = (Lisp_Object)33; /* 2 */
    v106 = stack[-7];
    v106 = qcar(v106);
    v107 = qcdr(v106);
    v106 = stack[-6];
    v106 = qcar(v106);
    v106 = qcdr(v106);
    fn = elt(env, 17); /* max */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = plus2(stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[-2] = v106;
    stack[0] = stack[-2];
    v106 = qvalue(elt(env, 2)); /* nil */
    v107 = Llinelength(nil, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = qvalue(elt(env, 1)); /* spare!* */
    v107 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = qvalue(elt(env, 3)); /* posn!* */
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = (Lisp_Object)greaterp2(stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    v106 = v106 ? lisp_true : nil;
    env = stack[-8];
    if (v106 == nil) goto v111;
    v106 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 18); /* terpri!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    goto v111;

v111:
    v106 = stack[-7];
    v106 = qcar(v106);
    v107 = qcdr(v106);
    v106 = stack[-6];
    v106 = qcar(v106);
    v106 = qcdr(v106);
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[-1] = v106;
    v107 = stack[-1];
    v106 = (Lisp_Object)1; /* 0 */
    v106 = (Lisp_Object)greaterp2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    v106 = v106 ? lisp_true : nil;
    env = stack[-8];
    if (v106 == nil) goto v112;
    v106 = (Lisp_Object)1; /* 0 */
    stack[0] = v106;
    v107 = stack[-1];
    v106 = (Lisp_Object)33; /* 2 */
    v106 = quot2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[-3] = v106;
    goto v113;

v113:
    v106 = stack[-7];
    v106 = qcdr(v106);
    v107 = qcdr(v106);
    v106 = stack[-7];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = add1(v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[-5] = v106;
    v106 = stack[-6];
    v106 = qcdr(v106);
    v107 = qcdr(v106);
    v106 = stack[-6];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = add1(v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[-4] = v106;
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 3)); /* posn!* */
    v107 = (Lisp_Object)17; /* 1 */
    v106 = qvalue(elt(env, 5)); /* orig!* */
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = plus2(stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[0] = plus2(stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v107 = (Lisp_Object)17; /* 1 */
    v106 = stack[-7];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    v107 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = qvalue(elt(env, 6)); /* ycoord!* */
    v107 = plus2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = stack[-7];
    v106 = qcar(v106);
    v106 = qcar(v106);
    fn = elt(env, 19); /* update!-pline */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[0], v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[0] = qvalue(elt(env, 3)); /* posn!* */
    v107 = (Lisp_Object)17; /* 1 */
    v106 = qvalue(elt(env, 5)); /* orig!* */
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = plus2(stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[0] = plus2(stack[-3], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v107 = qvalue(elt(env, 6)); /* ycoord!* */
    v106 = stack[-6];
    v106 = qcdr(v106);
    v106 = qcdr(v106);
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v107 = sub1(v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = stack[-6];
    v106 = qcar(v106);
    v106 = qcar(v106);
    fn = elt(env, 19); /* update!-pline */
    v107 = (*qfnn(fn))(qenv(fn), 3, stack[0], v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = qvalue(elt(env, 7)); /* pline!* */
    v106 = Lappend(nil, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = Lappend(nil, stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    qvalue(elt(env, 7)) = v106; /* pline!* */
    stack[0] = qvalue(elt(env, 8)); /* ymin!* */
    v107 = qvalue(elt(env, 6)); /* ycoord!* */
    v106 = stack[-4];
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    fn = elt(env, 20); /* min */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    qvalue(elt(env, 8)) = v106; /* ymin!* */
    stack[0] = qvalue(elt(env, 9)); /* ymax!* */
    v107 = qvalue(elt(env, 6)); /* ycoord!* */
    v106 = stack[-5];
    v106 = plus2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    fn = elt(env, 17); /* max */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    qvalue(elt(env, 9)) = v106; /* ymax!* */
    v106 = elt(env, 10); /* bar */
    fn = elt(env, 21); /* symbol */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[-1] = v106;
    v106 = (Lisp_Object)17; /* 1 */
    stack[0] = v106;
    goto v114;

v114:
    v107 = stack[-2];
    v106 = stack[0];
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = Lminusp(nil, v106);
    env = stack[-8];
    if (!(v106 == nil)) goto v115;
    v106 = stack[-1];
    fn = elt(env, 22); /* prin2!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = stack[0];
    v106 = add1(v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[0] = v106;
    goto v114;

v115:
    v106 = nil;
    { popv(9); return onevalue(v106); }

v112:
    v106 = stack[-1];
    v107 = negate(v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = (Lisp_Object)33; /* 2 */
    v106 = quot2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    stack[0] = v106;
    v106 = (Lisp_Object)1; /* 0 */
    stack[-3] = v106;
    goto v113;

v110:
    v107 = qvalue(elt(env, 1)); /* spare!* */
    v106 = (Lisp_Object)33; /* 2 */
    v106 = difference2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    qvalue(elt(env, 1)) = v106; /* spare!* */
    v106 = stack[0];
    v106 = qcdr(v106);
    stack[0] = v106;
    v107 = elt(env, 11); /* quotient */
    v106 = elt(env, 12); /* infix */
    v106 = get(v107, v106);
    env = stack[-8];
    stack[-2] = v106;
    v106 = qvalue(elt(env, 13)); /* p!*!* */
    if (v106 == nil) goto v116;
    v107 = qvalue(elt(env, 13)); /* p!*!* */
    v106 = stack[-2];
    v106 = (Lisp_Object)greaterp2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    v106 = v106 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v106;
    goto v117;

v117:
    v106 = stack[-1];
    if (v106 == nil) goto v118;
    v106 = elt(env, 14); /* "(" */
    fn = elt(env, 22); /* prin2!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    goto v118;

v118:
    v106 = stack[0];
    v107 = qcar(v106);
    v106 = stack[-2];
    fn = elt(env, 23); /* maprint */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = elt(env, 11); /* quotient */
    fn = elt(env, 24); /* oprin */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    fn = elt(env, 25); /* negnumberchk */
    v107 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = stack[-2];
    fn = elt(env, 23); /* maprint */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-8];
    v106 = stack[-1];
    if (v106 == nil) goto v115;
    v106 = elt(env, 15); /* ")" */
    fn = elt(env, 22); /* prin2!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v109;
    goto v115;

v116:
    v106 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v106;
    goto v117;
/* error exit handlers */
v109:
    popv(9);
    return nil;
}



/* Code for simp!-prop1 */

static Lisp_Object CC_simpKprop1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop1");
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

v183:
    v180 = stack[-4];
    if (!consp(v180)) goto v184;
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = qvalue(elt(env, 1)); /* !'and */
    if (!(equal(v181, v180))) goto v185;
    v180 = stack[-3];
    if (!(v180 == nil)) goto v8;

v185:
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = qvalue(elt(env, 2)); /* !'or */
    if (!(equal(v181, v180))) goto v186;
    v180 = stack[-3];
    if (!(v180 == nil)) goto v186;

v8:
    v180 = (Lisp_Object)17; /* 1 */
    stack[0] = v180;
    v180 = stack[-4];
    v180 = qcdr(v180);
    stack[-1] = v180;
    goto v10;

v10:
    v180 = stack[-1];
    if (v180 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v180 = stack[-1];
    v180 = qcar(v180);
    v181 = v180;
    v180 = stack[-3];
    v180 = CC_simpKprop1(env, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    fn = elt(env, 18); /* multf */
    v180 = (*qfn2(fn))(qenv(fn), stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    stack[0] = v180;
    v180 = stack[-1];
    v180 = qcdr(v180);
    stack[-1] = v180;
    goto v10;

v186:
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = qvalue(elt(env, 2)); /* !'or */
    if (!(equal(v181, v180))) goto v188;
    v180 = stack[-3];
    if (!(v180 == nil)) goto v189;

v188:
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = qvalue(elt(env, 1)); /* !'and */
    if (!(equal(v181, v180))) goto v190;
    v180 = stack[-3];
    if (!(v180 == nil)) goto v190;

v189:
    v180 = qvalue(elt(env, 3)); /* nil */
    stack[0] = v180;
    v180 = stack[-4];
    v180 = qcdr(v180);
    stack[-1] = v180;
    goto v191;

v191:
    v180 = stack[-1];
    if (v180 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v180 = stack[-1];
    v180 = qcar(v180);
    v181 = v180;
    v180 = stack[-3];
    v180 = CC_simpKprop1(env, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    fn = elt(env, 19); /* addf */
    v180 = (*qfn2(fn))(qenv(fn), stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    stack[0] = v180;
    v180 = stack[-1];
    v180 = qcdr(v180);
    stack[-1] = v180;
    goto v191;

v190:
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 4); /* not */
    if (v181 == v180) goto v192;
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 5); /* implies */
    if (v181 == v180) goto v112;
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 8); /* equiv */
    if (!(v181 == v180)) goto v40;
    stack[-5] = elt(env, 6); /* or */
    v182 = elt(env, 9); /* and */
    v180 = stack[-4];
    v180 = qcdr(v180);
    v181 = qcar(v180);
    v180 = stack[-4];
    v180 = qcdr(v180);
    v180 = qcdr(v180);
    v180 = qcar(v180);
    stack[-2] = list3(v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    stack[-1] = elt(env, 9); /* and */
    v181 = elt(env, 4); /* not */
    v180 = stack[-4];
    v180 = qcdr(v180);
    v180 = qcar(v180);
    stack[0] = list2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v181 = elt(env, 4); /* not */
    v180 = stack[-4];
    v180 = qcdr(v180);
    v180 = qcdr(v180);
    v180 = qcar(v180);
    v180 = list2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v180 = list3(stack[-1], stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v181 = list3(stack[-5], stack[-2], v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v180 = stack[-3];
    v180 = CC_simpKprop1(env, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    stack[0] = v180;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v40:
    v180 = stack[-4];
    fn = elt(env, 20); /* reval */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    stack[-4] = v180;
    v181 = stack[-4];
    v180 = elt(env, 14); /* boolean */
    if (!consp(v181)) goto v23;
    v181 = qcar(v181);
    if (!(v181 == v180)) goto v23;
    v180 = stack[-4];
    v180 = qcdr(v180);
    v181 = qcar(v180);
    v180 = stack[-3];
    stack[-4] = v181;
    stack[-3] = v180;
    goto v183;

v23:
    v180 = stack[-3];
    if (v180 == nil) goto v193;
    v180 = elt(env, 15); /* prop!* */
    v181 = v180;
    goto v194;

v194:
    v180 = stack[-4];
    v180 = list2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    fn = elt(env, 21); /* simp */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v180 = qcar(v180);
    stack[0] = v180;
    v181 = stack[-4];
    v180 = qvalue(elt(env, 17)); /* propvars!* */
    v180 = Lmember(nil, v181, v180);
    if (!(v180 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v181 = stack[-4];
    v180 = qvalue(elt(env, 17)); /* propvars!* */
    v180 = cons(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    qvalue(elt(env, 17)) = v180; /* propvars!* */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v193:
    v180 = elt(env, 16); /* not_prop!* */
    v181 = v180;
    goto v194;

v112:
    v180 = stack[-3];
    if (v180 == nil) goto v195;
    stack[0] = elt(env, 6); /* or */
    v181 = elt(env, 4); /* not */
    v180 = stack[-4];
    v180 = qcdr(v180);
    v180 = qcar(v180);
    v181 = list2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v180 = stack[-4];
    v180 = qcdr(v180);
    v180 = qcdr(v180);
    v180 = qcar(v180);
    v181 = list3(stack[0], v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v180 = qvalue(elt(env, 7)); /* t */
    v180 = CC_simpKprop1(env, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    stack[0] = v180;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v195:
    stack[0] = elt(env, 6); /* or */
    v181 = elt(env, 4); /* not */
    v180 = stack[-4];
    v180 = qcdr(v180);
    v180 = qcdr(v180);
    v180 = qcar(v180);
    v181 = list2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v180 = stack[-4];
    v180 = qcdr(v180);
    v180 = qcar(v180);
    v181 = list3(stack[0], v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v180 = qvalue(elt(env, 7)); /* t */
    v180 = CC_simpKprop1(env, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    stack[0] = v180;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v192:
    v180 = stack[-4];
    v180 = qcdr(v180);
    v181 = qcar(v180);
    v180 = stack[-3];
    v180 = (v180 == nil ? lisp_true : nil);
    v180 = CC_simpKprop1(env, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v187;
    stack[0] = v180;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v184:
    v181 = stack[-4];
    v180 = (Lisp_Object)17; /* 1 */
    if (v181 == v180) goto v196;
    v181 = stack[-4];
    v180 = qvalue(elt(env, 7)); /* t */
    if (equal(v181, v180)) goto v196;
    v181 = stack[-4];
    v180 = elt(env, 10); /* true */
    if (v181 == v180) goto v196;
    v181 = stack[-4];
    v180 = (Lisp_Object)1; /* 0 */
    if (v181 == v180) goto v197;
    v180 = stack[-4];
    if (v180 == nil) goto v197;
    v181 = stack[-4];
    v180 = elt(env, 11); /* false */
    if (!(v181 == v180)) goto v198;

v197:
    v180 = stack[-3];
    v180 = (v180 == nil ? lisp_true : nil);
    stack[-4] = v180;
    goto v198;

v198:
    v181 = stack[-4];
    v180 = qvalue(elt(env, 7)); /* t */
    if (equal(v181, v180)) goto v28;
    v180 = stack[-4];
    if (!(v180 == nil)) goto v40;
    v181 = elt(env, 13); /* (and !*true (not !*true)) */
    v180 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v181;
    stack[-3] = v180;
    goto v183;

v28:
    v181 = elt(env, 12); /* (or !*true (not !*true)) */
    v180 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v181;
    stack[-3] = v180;
    goto v183;

v196:
    v180 = stack[-3];
    stack[-4] = v180;
    goto v198;
/* error exit handlers */
v187:
    popv(7);
    return nil;
}



/* Code for general!-horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKhornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v18, Lisp_Object v15,
                         Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v210, v190, v211, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "general-horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-horner-rule-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push5(v16,v15,v18,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v18,v15,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v16;
    stack[-3] = v15;
    stack[-4] = v18;
    v190 = v1;
    v211 = v0;
/* end of prologue */

v183:
    v209 = stack[-4];
    if (!consp(v209)) goto v45;
    v209 = stack[-4];
    v209 = qcar(v209);
    if (!consp(v209)) goto v45;
    v209 = stack[-4];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v210 = qcar(v209);
    v209 = stack[-2];
    if (!(equal(v210, v209))) goto v45;
    v209 = stack[-4];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v209 = qcdr(v209);
    stack[-5] = v209;
    v209 = stack[-3];
    if (v209 == nil) goto v97;
    v209 = stack[-3];
    v209 = (Lisp_Object)zerop(v209);
    v209 = v209 ? lisp_true : nil;
    env = stack[-6];
    if (!(v209 == nil)) goto v97;
    v209 = stack[-4];
    v209 = qcar(v209);
    stack[-1] = qcdr(v209);
    stack[0] = v211;
    v210 = stack[-3];
    v209 = stack[-5];
    v209 = (Lisp_Object)(int32_t)((int32_t)v190 - (int32_t)v209 + TAG_FIXNUM);
    fn = elt(env, 1); /* general!-expt!-mod!-p */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-6];
    fn = elt(env, 2); /* general!-times!-mod!-p */
    v209 = (*qfn2(fn))(qenv(fn), stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-6];
    fn = elt(env, 3); /* general!-plus!-mod!-p */
    v209 = (*qfn2(fn))(qenv(fn), stack[-1], v209);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-6];
    v211 = v209;
    goto v189;

v189:
    v190 = stack[-5];
    v209 = stack[-4];
    v212 = qcdr(v209);
    v210 = stack[-3];
    v209 = stack[-2];
    stack[-4] = v212;
    stack[-3] = v210;
    stack[-2] = v209;
    goto v183;

v97:
    v209 = stack[-4];
    v209 = qcar(v209);
    v209 = qcdr(v209);
    v211 = v209;
    goto v189;

v45:
    v209 = stack[-3];
    if (v209 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v209 = stack[-3];
    v209 = (Lisp_Object)zerop(v209);
    v209 = v209 ? lisp_true : nil;
    env = stack[-6];
    if (!(v209 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v211;
    v209 = stack[-3];
    v210 = v190;
    fn = elt(env, 1); /* general!-expt!-mod!-p */
    v209 = (*qfn2(fn))(qenv(fn), v209, v210);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-6];
    fn = elt(env, 2); /* general!-times!-mod!-p */
    v209 = (*qfn2(fn))(qenv(fn), stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-6];
    v211 = v209;
    v209 = stack[-4];
    v210 = v211;
    {
        popv(7);
        fn = elt(env, 3); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v209, v210);
    }
/* error exit handlers */
v192:
    popv(7);
    return nil;
}



/* Code for rl_bettergaussp */

static Lisp_Object CC_rl_bettergaussp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_bettergaussp");
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
    v19 = v1;
    v20 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bettergaussp!* */
    v19 = list2(v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-1];
    {
        Lisp_Object v215 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v215, v19);
    }
/* error exit handlers */
v214:
    popv(2);
    return nil;
}



/* Code for multdfconst */

static Lisp_Object CC_multdfconst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdfconst");
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
    goto v53;

v53:
    v10 = stack[-1];
    if (v10 == nil) goto v75;
    v10 = stack[-2];
    v10 = qcar(v10);
    if (v10 == nil) goto v75;
    v10 = stack[-1];
    v10 = qcar(v10);
    stack[0] = qcar(v10);
    v11 = stack[-2];
    v10 = stack[-1];
    v10 = qcar(v10);
    v10 = qcdr(v10);
    fn = elt(env, 1); /* multsq */
    v10 = (*qfn2(fn))(qenv(fn), v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-4];
    fn = elt(env, 2); /* subs2q */
    v11 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-4];
    v10 = stack[-3];
    v10 = acons(stack[0], v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-4];
    stack[-3] = v10;
    v10 = stack[-1];
    v10 = qcdr(v10);
    stack[-1] = v10;
    goto v53;

v75:
    v10 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v14:
    popv(5);
    return nil;
}



/* Code for offexpchk */

static Lisp_Object CC_offexpchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for offexpchk");
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
    v7 = qvalue(elt(env, 1)); /* !*really_off_exp */
    if (!(v7 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v7 = qvalue(elt(env, 2)); /* frlis!* */
    if (v7 == nil) goto v45;
    v7 = stack[0];
    v7 = qcar(v7);
    fn = elt(env, 3); /* freevarinexptchk */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    if (!(v7 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v45:
    v7 = stack[0];
    v7 = qcdr(v7);
    fn = elt(env, 3); /* freevarinexptchk */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    if (!(v7 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v7 = stack[0];
    v7 = qcar(v7);
    fn = elt(env, 4); /* mkprod */
    stack[-1] = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    v7 = stack[0];
    v7 = qcdr(v7);
    fn = elt(env, 4); /* mkprod */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    {
        Lisp_Object v173 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* canprod */
        return (*qfn2(fn))(qenv(fn), v173, v7);
    }
/* error exit handlers */
v172:
    popv(3);
    return nil;
}



/* Code for give!*position */

static Lisp_Object CC_giveHposition(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for give*position");
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
    v102 = (Lisp_Object)17; /* 1 */
    stack[-4] = v102;
    v102 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v102;
    goto v35;

v35:
    v102 = stack[-1];
    if (!(v102 == nil)) goto v12;
    stack[0] = stack[-4];
    v102 = stack[-2];
    v102 = Llength(nil, v102);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v102 = (Lisp_Object)lesseq2(stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v99;
    v102 = v102 ? lisp_true : nil;
    env = stack[-5];
    if (v102 == nil) goto v12;
    v217 = stack[-2];
    v102 = stack[-4];
    fn = elt(env, 4); /* nth */
    v217 = (*qfn2(fn))(qenv(fn), v217, v102);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v102 = stack[-3];
    if (equal(v217, v102)) goto v185;
    v102 = stack[-4];
    v102 = add1(v102);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    stack[-4] = v102;
    goto v35;

v185:
    v102 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v102;
    goto v35;

v12:
    v102 = stack[-1];
    if (!(v102 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v102 = elt(env, 3); /* "error in give position" */
    fn = elt(env, 5); /* rederr */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v99;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v99:
    popv(6);
    return nil;
}



/* Code for atomlis */

static Lisp_Object CC_atomlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v218;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atomlis");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */

v183:
    v218 = v20;
    v218 = (v218 == nil ? lisp_true : nil);
    if (!(v218 == nil)) return onevalue(v218);
    v218 = v20;
    v218 = qcar(v218);
    if (!consp(v218)) goto v219;
    v20 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v20);

v219:
    v20 = qcdr(v20);
    goto v183;
}



/* Code for mconv1 */

static Lisp_Object CC_mconv1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mconv1");
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
    goto v17;

v17:
    v5 = stack[-1];
    if (!consp(v5)) goto v9;
    v5 = stack[-1];
    v5 = qcar(v5);
    if (!consp(v5)) goto v9;
    v5 = stack[-1];
    v5 = qcar(v5);
    stack[0] = qcar(v5);
    v5 = stack[-1];
    v5 = qcar(v5);
    v5 = qcdr(v5);
    v10 = CC_mconv1(env, v5);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-3];
    v5 = stack[-2];
    v5 = acons(stack[0], v10, v5);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-3];
    stack[-2] = v5;
    v5 = stack[-1];
    v5 = qcdr(v5);
    stack[-1] = v5;
    goto v17;

v9:
    stack[0] = stack[-2];
    v5 = stack[-1];
    fn = elt(env, 1); /* drnconv */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-3];
    {
        Lisp_Object v13 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v13, v5);
    }
/* error exit handlers */
v221:
    popv(4);
    return nil;
}



/* Code for gcd2 */

static Lisp_Object CC_gcd2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v172, v173;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd2");
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
    stack[0] = v1;
    v172 = v0;
/* end of prologue */

v75:
    v220 = stack[0];
    v220 = Cremainder(v172, v220);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-1];
    v173 = v220;
    v172 = v173;
    v220 = (Lisp_Object)1; /* 0 */
    if (v172 == v220) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v172 = stack[0];
    v220 = v173;
    stack[0] = v220;
    goto v75;
/* error exit handlers */
v224:
    popv(2);
    return nil;
}



/* Code for lchk */

static Lisp_Object CC_lchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lchk");
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
    v10 = stack[0];
    if (v10 == nil) goto v45;
    v10 = stack[0];
    v10 = qcar(v10);
    if (!consp(v10)) goto v45;
    v10 = stack[0];
    v10 = qcar(v10);
    v10 = Llength(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-2];
    stack[-1] = v10;
    goto v214;

v214:
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[0] = v10;
    v10 = stack[0];
    if (v10 == nil) goto v218;
    v10 = stack[0];
    v10 = qcar(v10);
    if (!consp(v10)) goto v218;
    v10 = stack[0];
    v10 = qcar(v10);
    v11 = Llength(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-2];
    v10 = stack[-1];
    if (equal(v11, v10)) goto v214;
    else goto v218;

v218:
    v10 = stack[0];
    v10 = (v10 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v10); }

v45:
    v10 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v10); }
/* error exit handlers */
v221:
    popv(3);
    return nil;
}



/* Code for wedgef */

static Lisp_Object CC_wedgef(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v62, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgef");
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
    v74 = stack[-1];
    fn = elt(env, 7); /* dim!<deg */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    if (v74 == nil) goto v82;
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v74); }

v82:
    v74 = stack[-1];
    v62 = qcar(v74);
    v74 = elt(env, 2); /* hodge */
    if (!consp(v62)) goto v111;
    v62 = qcar(v62);
    if (!(v62 == v74)) goto v111;
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    fn = elt(env, 8); /* deg!*form */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    stack[-2] = v74;
    stack[0] = stack[-2];
    v74 = stack[-1];
    v74 = qcdr(v74);
    fn = elt(env, 9); /* deg!*farg */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    if (equal(stack[0], v74)) goto v204;
    v74 = stack[-1];
    {
        popv(4);
        fn = elt(env, 10); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v74);
    }

v204:
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v148 = qcar(v74);
    v62 = (Lisp_Object)17; /* 1 */
    v74 = (Lisp_Object)17; /* 1 */
    v74 = list2star(v148, v62, v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    stack[0] = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    v74 = stack[-1];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    if (v74 == nil) goto v244;
    v74 = stack[-1];
    v74 = qcdr(v74);
    fn = elt(env, 11); /* mkuniquewedge1 */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    goto v100;

v100:
    fn = elt(env, 12); /* hodgepf */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 13); /* mkunarywedge */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 14); /* wedgepf2 */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    stack[0] = stack[-2];
    v74 = qvalue(elt(env, 3)); /* dimex!* */
    fn = elt(env, 15); /* negf */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 16); /* addf */
    v74 = (*qfn2(fn))(qenv(fn), stack[-2], v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 17); /* multf */
    v74 = (*qfn2(fn))(qenv(fn), stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 18); /* mksgnsq */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    {
        Lisp_Object v65 = stack[-1];
        popv(4);
        fn = elt(env, 19); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v65, v74);
    }

v244:
    v74 = stack[-1];
    v74 = qcdr(v74);
    v148 = qcar(v74);
    v62 = (Lisp_Object)17; /* 1 */
    v74 = (Lisp_Object)17; /* 1 */
    v74 = list2star(v148, v62, v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    goto v100;

v111:
    v74 = stack[-1];
    v62 = qcar(v74);
    v74 = elt(env, 4); /* d */
    if (!consp(v62)) goto v245;
    v62 = qcar(v62);
    if (!(v62 == v74)) goto v245;
    v62 = elt(env, 4); /* d */
    v74 = elt(env, 5); /* noxpnd */
    v74 = Lflagp(nil, v62, v74);
    env = stack[-3];
    if (!(v74 == nil)) goto v246;
    v62 = qvalue(elt(env, 6)); /* lftshft!* */
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    fn = elt(env, 20); /* smemqlp */
    v74 = (*qfn2(fn))(qenv(fn), v62, v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    if (!(v74 == nil)) goto v246;

v245:
    v74 = stack[-1];
    {
        popv(4);
        fn = elt(env, 10); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v74);
    }

v246:
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v62 = qcar(v74);
    v74 = stack[-1];
    v74 = qcdr(v74);
    v74 = cons(v62, v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 21); /* dwedge */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 13); /* mkunarywedge */
    stack[-2] = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v148 = qcar(v74);
    v62 = (Lisp_Object)17; /* 1 */
    v74 = (Lisp_Object)17; /* 1 */
    v74 = list2star(v148, v62, v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    stack[0] = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    v74 = stack[-1];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    if (v74 == nil) goto v143;
    v74 = stack[-1];
    v74 = qcdr(v74);
    fn = elt(env, 21); /* dwedge */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    goto v149;

v149:
    fn = elt(env, 13); /* mkunarywedge */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 14); /* wedgepf2 */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    fn = elt(env, 8); /* deg!*form */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 18); /* mksgnsq */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 22); /* negsq */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    fn = elt(env, 19); /* multpfsq */
    v74 = (*qfn2(fn))(qenv(fn), stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    {
        Lisp_Object v247 = stack[-2];
        popv(4);
        fn = elt(env, 23); /* addpf */
        return (*qfn2(fn))(qenv(fn), v247, v74);
    }

v143:
    v74 = stack[-1];
    v74 = qcdr(v74);
    v74 = qcar(v74);
    fn = elt(env, 24); /* exdfk */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    goto v149;
/* error exit handlers */
v144:
    popv(4);
    return nil;
}



/* Code for sublap */

static Lisp_Object CC_sublap(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sublap");
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
    v166 = stack[-1];
    if (v166 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v166 = stack[0];
    if (v166 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v166 = stack[0];
    if (!consp(v166)) goto v8;
    v166 = stack[0];
    v97 = qcar(v166);
    v166 = elt(env, 1); /* app */
    v166 = Lflagp(nil, v97, v166);
    env = stack[-3];
    if (v166 == nil) goto v253;
    v97 = stack[-1];
    v166 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* sublap1 */
        return (*qfn2(fn))(qenv(fn), v97, v166);
    }

v253:
    v97 = stack[-1];
    v166 = stack[0];
    v166 = qcar(v166);
    stack[-2] = CC_sublap(env, v97, v166);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-3];
    v97 = stack[-1];
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = CC_sublap(env, v97, v166);
    nil = C_nil;
    if (exception_pending()) goto v254;
    {
        Lisp_Object v188 = stack[-2];
        popv(4);
        return cons(v188, v166);
    }

v8:
    v166 = stack[0];
    if (is_number(v166)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v97 = stack[0];
    v166 = stack[-1];
    v166 = Latsoc(nil, v97, v166);
    v97 = v166;
    if (v166 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v166 = v97;
    v166 = qcdr(v166);
    { popv(4); return onevalue(v166); }
/* error exit handlers */
v254:
    popv(4);
    return nil;
}



/* Code for !*di2q */

static Lisp_Object CC_Hdi2q(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v18)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v257, v258, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *di2q");
#endif
    if (stack >= stacklimit)
    {
        push2(v18,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v18);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v257 = v18;
    v258 = v1;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v257; /* varlist */
    v257 = v258;
    stack[-3] = v257;
    v257 = stack[-3];
    if (v257 == nil) goto v222;
    v257 = stack[-3];
    v257 = qcar(v257);
    v258 = v257;
    v249 = qcar(v258);
    v258 = qcdr(v257);
    v257 = (Lisp_Object)17; /* 1 */
    v257 = list2star(v249, v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    stack[-1] = v257;
    stack[-2] = v257;
    goto v20;

v20:
    v257 = stack[-3];
    v257 = qcdr(v257);
    stack[-3] = v257;
    v257 = stack[-3];
    if (v257 == nil) goto v252;
    stack[0] = stack[-1];
    v257 = stack[-3];
    v257 = qcar(v257);
    v258 = v257;
    v249 = qcar(v258);
    v258 = qcdr(v257);
    v257 = (Lisp_Object)17; /* 1 */
    v257 = list2star(v249, v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = Lrplacd(nil, stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = stack[-1];
    v257 = qcdr(v257);
    stack[-1] = v257;
    goto v20;

v252:
    v257 = stack[-2];
    v258 = v257;
    goto v35;

v35:
    v257 = qvalue(elt(env, 1)); /* varlist */
    fn = elt(env, 3); /* !*di2q0 */
    v257 = (*qfn2(fn))(qenv(fn), v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    { popv(6); return onevalue(v257); }

v222:
    v257 = qvalue(elt(env, 2)); /* nil */
    v258 = v257;
    goto v35;
/* error exit handlers */
v259:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    popv(6);
    return nil;
}



/* Code for cl_fvarl1 */

static Lisp_Object CC_cl_fvarl1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_fvarl1");
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
    v17 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cl_varl1 */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    errexit();
    v17 = qcar(v17);
    return onevalue(v17);
}



/* Code for containerml */

static Lisp_Object CC_containerml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for containerml");
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
    v5 = stack[0];
    v256 = elt(env, 1); /* integer_interval */
    if (!(v5 == v256)) goto v53;
    v256 = elt(env, 2); /* interval */
    stack[0] = v256;
    goto v53;

v53:
    v256 = elt(env, 3); /* "<" */
    fn = elt(env, 9); /* printout */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v256 = stack[0];
    v256 = Lprinc(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v256 = stack[-1];
    v5 = qcar(v256);
    v256 = elt(env, 4); /* "" */
    fn = elt(env, 10); /* attributesml */
    v256 = (*qfn2(fn))(qenv(fn), v5, v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v256 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 11); /* indent!* */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v256 = stack[-1];
    v256 = qcdr(v256);
    fn = elt(env, 12); /* multi_elem */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v256 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 11); /* indent!* */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v256 = elt(env, 7); /* "</" */
    fn = elt(env, 9); /* printout */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v256 = stack[0];
    v256 = Lprinc(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v256 = elt(env, 8); /* ">" */
    v256 = Lprinc(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v261;
    v256 = nil;
    { popv(3); return onevalue(v256); }
/* error exit handlers */
v261:
    popv(3);
    return nil;
}



/* Code for exptplus */

static Lisp_Object CC_exptplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptplus");
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
    v14 = v1;
    v203 = v0;
/* end of prologue */
    v13 = v203;
    if (!consp(v13)) goto v17;
    v13 = v14;
    if (!consp(v13)) goto v173;
    v13 = elt(env, 1); /* "Bad exponent sum" */
    {
        fn = elt(env, 2); /* interr */
        return (*qfn1(fn))(qenv(fn), v13);
    }

v173:
    v13 = v203;
    v13 = qcar(v13);
    v13 = plus2(v13, v14);
    errexit();
    return ncons(v13);

v17:
    v13 = v14;
    if (!consp(v13)) goto v219;
    v13 = v203;
    v14 = qcar(v14);
    v13 = plus2(v13, v14);
    errexit();
    return ncons(v13);

v219:
    v13 = v203;
    return plus2(v13, v14);
}



/* Code for dipequal */

static Lisp_Object CC_dipequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipequal");
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

v17:
    v101 = stack[-1];
    if (v101 == nil) goto v45;
    v101 = stack[0];
    if (v101 == nil) goto v223;
    v101 = stack[-1];
    v101 = qcdr(v101);
    v102 = qcar(v101);
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = qcar(v101);
    if (equal(v102, v101)) goto v225;
    v101 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v101); }

v225:
    v101 = stack[-1];
    v102 = qcar(v101);
    v101 = stack[0];
    v101 = qcar(v101);
    fn = elt(env, 2); /* evequal */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-2];
    if (v101 == nil) goto v263;
    v101 = stack[-1];
    v101 = qcdr(v101);
    v101 = qcdr(v101);
    stack[-1] = v101;
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = qcdr(v101);
    stack[0] = v101;
    goto v17;

v263:
    v101 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v101); }

v223:
    v101 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v101); }

v45:
    v101 = stack[0];
    v101 = (v101 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v101); }
/* error exit handlers */
v168:
    popv(3);
    return nil;
}



/* Code for difference!: */

static Lisp_Object CC_differenceT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v270, v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference:");
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
    v85 = v1;
    v86 = v0;
/* end of prologue */
    v269 = v86;
    v269 = qcdr(v269);
    v270 = qcar(v269);
    stack[-1] = v270;
    v269 = (Lisp_Object)1; /* 0 */
    if (v270 == v269) goto v82;
    v269 = v85;
    v269 = qcdr(v269);
    v270 = qcar(v269);
    stack[0] = v270;
    v269 = (Lisp_Object)1; /* 0 */
    if (v270 == v269) { popv(6); return onevalue(v86); }
    v269 = v86;
    v269 = qcdr(v269);
    v269 = qcdr(v269);
    stack[-4] = v269;
    v270 = v85;
    v270 = qcdr(v270);
    v270 = qcdr(v270);
    stack[-2] = v270;
    v270 = difference2(v269, v270);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    stack[-3] = v270;
    v269 = (Lisp_Object)1; /* 0 */
    if (v270 == v269) goto v255;
    v270 = stack[-3];
    v269 = (Lisp_Object)1; /* 0 */
    v269 = (Lisp_Object)greaterp2(v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    v269 = v269 ? lisp_true : nil;
    env = stack[-5];
    if (v269 == nil) goto v200;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v270 = stack[-1];
    v269 = stack[-3];
    v270 = Lash1(nil, v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v269 = stack[0];
    v270 = difference2(v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    v269 = stack[-2];
    {
        Lisp_Object v234 = stack[-4];
        popv(6);
        return list2star(v234, v270, v269);
    }

v200:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v269 = stack[-3];
    v269 = negate(v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v269 = Lash1(nil, stack[0], v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v270 = difference2(stack[-1], v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    v269 = stack[-4];
    {
        Lisp_Object v83 = stack[-2];
        popv(6);
        return list2star(v83, v270, v269);
    }

v255:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v270 = stack[-1];
    v269 = stack[0];
    v270 = difference2(v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    v269 = stack[-4];
    {
        Lisp_Object v84 = stack[-2];
        popv(6);
        return list2star(v84, v270, v269);
    }

v82:
    v269 = v85;
    {
        popv(6);
        fn = elt(env, 2); /* minus!: */
        return (*qfn1(fn))(qenv(fn), v269);
    }
/* error exit handlers */
v271:
    popv(6);
    return nil;
}



/* Code for indexsymmetrize */

static Lisp_Object CC_indexsymmetrize(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v267, v189, v248;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexsymmetrize");
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
    v267 = stack[-2];
    v189 = qcar(v267);
    v267 = elt(env, 1); /* indxsymmetrize */
    v267 = get(v189, v267);
    env = stack[-4];
    stack[-3] = v267;
    v267 = (Lisp_Object)17; /* 1 */
    stack[0] = v267;
    v189 = (Lisp_Object)17; /* 1 */
    v267 = stack[-2];
    v267 = qcdr(v267);
    v267 = cons(v189, v267);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    stack[-1] = v267;
    goto v40;

v40:
    v267 = stack[-3];
    if (v267 == nil) goto v7;
    v267 = stack[-3];
    v189 = qcar(v267);
    v267 = stack[-1];
    v267 = qcdr(v267);
    v267 = Lapply1(nil, v189, v267);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    stack[-1] = v267;
    v267 = stack[-1];
    if (v267 == nil) goto v255;
    v267 = stack[-1];
    v189 = qcar(v267);
    v267 = stack[0];
    v267 = times2(v189, v267);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    stack[0] = v267;
    v267 = stack[-3];
    v267 = qcdr(v267);
    stack[-3] = v267;
    goto v40;

v255:
    v267 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v267); }

v7:
    v248 = stack[0];
    v267 = stack[-2];
    v189 = qcar(v267);
    v267 = stack[-1];
    v267 = qcdr(v267);
    popv(5);
    return list2star(v248, v189, v267);
/* error exit handlers */
v258:
    popv(5);
    return nil;
}



/* Code for !*xadd */

static Lisp_Object CC_Hxadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v263, v268, v171;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *xadd");
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
    v171 = v1;
    stack[0] = v0;
/* end of prologue */
    v204 = v171;
    v268 = v204;
    goto v75;

v75:
    v204 = v268;
    if (v204 == nil) goto v45;
    v204 = stack[0];
    v263 = qcar(v204);
    v204 = v268;
    v204 = qcar(v204);
    v204 = qcar(v204);
    if (equal(v263, v204)) goto v45;
    v204 = v268;
    v204 = qcdr(v204);
    v268 = v204;
    goto v75;

v45:
    v204 = v268;
    if (v204 == nil) goto v10;
    v204 = v268;
    v204 = qcar(v204);
    v263 = v171;
    v204 = Ldelete(nil, v204, v263);
    nil = C_nil;
    if (exception_pending()) goto v255;
    v171 = v204;
    goto v10;

v10:
    v204 = stack[0];
    v263 = v171;
    popv(1);
    return cons(v204, v263);
/* error exit handlers */
v255:
    popv(1);
    return nil;
}



/* Code for contract!-strand */

static Lisp_Object CC_contractKstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contract-strand");
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
    v82 = v1;
    v223 = v0;
/* end of prologue */
    stack[0] = v223;
    fn = elt(env, 1); /* zero!-roads */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    {
        Lisp_Object v9 = stack[0];
        popv(2);
        fn = elt(env, 2); /* contr!-strand */
        return (*qfn2(fn))(qenv(fn), v9, v82);
    }
/* error exit handlers */
v8:
    popv(2);
    return nil;
}



/* Code for liennewstruc */

static Lisp_Object MS_CDECL CC_liennewstruc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v18, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v400, v401, v402, v403;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "liennewstruc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for liennewstruc");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-12] = v18;
    stack[-13] = v1;
    stack[-14] = v0;
/* end of prologue */
    v402 = elt(env, 1); /* lie_a */
    v401 = stack[-14];
    v400 = stack[-14];
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = ncons(v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 12); /* matrix */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 13); /* aeval */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[0] = elt(env, 1); /* lie_a */
    v402 = elt(env, 2); /* expt */
    v401 = elt(env, 1); /* lie_a */
    v400 = (Lisp_Object)1; /* 0 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 13); /* aeval */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 14); /* setk */
    v400 = (*qfn2(fn))(qenv(fn), stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-13];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-15] = v400;
    goto v14;

v14:
    stack[0] = elt(env, 3); /* difference */
    v402 = elt(env, 3); /* difference */
    v401 = stack[-14];
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-15];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v257;
    v402 = elt(env, 5); /* plus */
    v401 = stack[-13];
    v400 = (Lisp_Object)33; /* 2 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-2] = v400;
    goto v128;

v128:
    stack[0] = elt(env, 3); /* difference */
    v400 = stack[-14];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-2];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v405;
    stack[0] = elt(env, 9); /* lientrans */
    v402 = elt(env, 8); /* times */
    v401 = elt(env, 1); /* lie_a */
    v400 = elt(env, 9); /* lientrans */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 13); /* aeval */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 14); /* setk */
    v400 = (*qfn2(fn))(qenv(fn), stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v402 = elt(env, 5); /* plus */
    v401 = stack[-13];
    v400 = (Lisp_Object)33; /* 2 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-13] = v400;
    goto v406;

v406:
    stack[0] = elt(env, 3); /* difference */
    v402 = elt(env, 3); /* difference */
    v401 = stack[-14];
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-13];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v407;
    v400 = elt(env, 1); /* lie_a */
    v400 = ncons(v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 17); /* clear */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 13); /* aeval */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    v400 = nil;
    { popv(17); return onevalue(v400); }

v407:
    v402 = elt(env, 5); /* plus */
    v401 = stack[-13];
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-11] = v400;
    goto v408;

v408:
    stack[0] = elt(env, 3); /* difference */
    v400 = stack[-14];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-11];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v409;
    v400 = stack[-13];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-13] = v400;
    goto v406;

v409:
    v402 = elt(env, 6); /* lie_lamb */
    v401 = stack[-13];
    v400 = stack[-11];
    stack[-10] = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-9] = elt(env, 7); /* quotient */
    v400 = (Lisp_Object)17; /* 1 */
    stack[-8] = v400;
    v400 = (Lisp_Object)1; /* 0 */
    stack[-7] = v400;
    goto v410;

v410:
    stack[0] = elt(env, 3); /* difference */
    v400 = stack[-14];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-8];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v411;
    v400 = stack[-7];
    stack[0] = v400;
    v402 = elt(env, 9); /* lientrans */
    v401 = (Lisp_Object)17; /* 1 */
    v400 = stack[-12];
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = list3(stack[-9], stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 14); /* setk */
    v400 = (*qfn2(fn))(qenv(fn), stack[-10], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-11];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-11] = v400;
    goto v408;

v411:
    stack[-6] = elt(env, 5); /* plus */
    v400 = (Lisp_Object)17; /* 1 */
    stack[-5] = v400;
    v400 = (Lisp_Object)1; /* 0 */
    stack[-4] = v400;
    goto v412;

v412:
    stack[0] = elt(env, 3); /* difference */
    v400 = stack[-14];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-5];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v413;
    v400 = stack[-4];
    v401 = v400;
    v400 = stack[-7];
    v400 = list3(stack[-6], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-7] = v400;
    v400 = stack[-8];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-8] = v400;
    goto v410;

v413:
    stack[-3] = elt(env, 5); /* plus */
    stack[-2] = elt(env, 8); /* times */
    v402 = elt(env, 9); /* lientrans */
    v401 = stack[-13];
    v400 = stack[-8];
    stack[-1] = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v402 = elt(env, 9); /* lientrans */
    v401 = stack[-11];
    v400 = stack[-5];
    stack[0] = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v403 = elt(env, 10); /* lie_cc */
    v402 = stack[-8];
    v401 = stack[-5];
    v400 = stack[-12];
    v400 = list4(v403, v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = list4(stack[-2], stack[-1], stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-4];
    v400 = list3(stack[-3], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-4] = v400;
    v400 = stack[-5];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-5] = v400;
    goto v412;

v405:
    stack[-1] = elt(env, 1); /* lie_a */
    stack[0] = stack[-2];
    v402 = elt(env, 5); /* plus */
    v401 = stack[-13];
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-1] = list3(stack[-1], stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[0] = elt(env, 11); /* minus */
    v402 = elt(env, 6); /* lie_lamb */
    v401 = stack[-13];
    v400 = stack[-2];
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = list2(stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 14); /* setk */
    v400 = (*qfn2(fn))(qenv(fn), stack[-1], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v402 = elt(env, 1); /* lie_a */
    v401 = stack[-2];
    v400 = stack[-13];
    stack[-1] = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[0] = elt(env, 6); /* lie_lamb */
    v402 = elt(env, 5); /* plus */
    v401 = stack[-13];
    v400 = (Lisp_Object)17; /* 1 */
    v401 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-2];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 14); /* setk */
    v400 = (*qfn2(fn))(qenv(fn), stack[-1], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-2];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-2] = v400;
    goto v128;

v257:
    v402 = elt(env, 5); /* plus */
    v401 = stack[-15];
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-11] = v400;
    goto v414;

v414:
    stack[0] = elt(env, 3); /* difference */
    v400 = stack[-14];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-11];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v94;
    v400 = stack[-15];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-15] = v400;
    goto v14;

v94:
    v402 = elt(env, 6); /* lie_lamb */
    v401 = stack[-15];
    v400 = stack[-11];
    stack[-10] = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-9] = elt(env, 7); /* quotient */
    v400 = (Lisp_Object)17; /* 1 */
    stack[-8] = v400;
    v400 = (Lisp_Object)1; /* 0 */
    stack[-7] = v400;
    goto v271;

v271:
    stack[0] = elt(env, 3); /* difference */
    v400 = stack[-14];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-8];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v81;
    v400 = stack[-7];
    stack[0] = v400;
    v402 = elt(env, 9); /* lientrans */
    v401 = (Lisp_Object)17; /* 1 */
    v400 = stack[-12];
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = list3(stack[-9], stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 14); /* setk */
    v400 = (*qfn2(fn))(qenv(fn), stack[-10], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-11];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-11] = v400;
    goto v414;

v81:
    stack[-6] = elt(env, 5); /* plus */
    v400 = (Lisp_Object)17; /* 1 */
    stack[-5] = v400;
    v400 = (Lisp_Object)1; /* 0 */
    stack[-4] = v400;
    goto v415;

v415:
    stack[0] = elt(env, 3); /* difference */
    v400 = stack[-14];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-5];
    v400 = list3(stack[0], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 16); /* aminusp!: */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    if (v400 == nil) goto v230;
    v400 = stack[-4];
    v401 = v400;
    v400 = stack[-7];
    v400 = list3(stack[-6], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-7] = v400;
    v400 = stack[-8];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-8] = v400;
    goto v271;

v230:
    stack[-3] = elt(env, 5); /* plus */
    stack[-2] = elt(env, 8); /* times */
    v402 = elt(env, 9); /* lientrans */
    v401 = stack[-15];
    v400 = stack[-8];
    stack[-1] = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v402 = elt(env, 9); /* lientrans */
    v401 = stack[-11];
    v400 = stack[-5];
    stack[0] = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v403 = elt(env, 10); /* lie_cc */
    v402 = stack[-8];
    v401 = stack[-5];
    v400 = stack[-12];
    v400 = list4(v403, v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = list4(stack[-2], stack[-1], stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v401 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    v400 = stack[-4];
    v400 = list3(stack[-3], v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-4] = v400;
    v400 = stack[-5];
    v402 = elt(env, 5); /* plus */
    v401 = v400;
    v400 = (Lisp_Object)17; /* 1 */
    v400 = list3(v402, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    fn = elt(env, 15); /* aeval!* */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-16];
    stack[-5] = v400;
    goto v415;
/* error exit handlers */
v404:
    popv(17);
    return nil;
}



/* Code for mv!-pow!-!> */

static Lisp_Object CC_mvKpowKS(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v224, v216, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow->");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v224 = v1;
    v216 = v0;
/* end of prologue */

v17:
    v225 = v216;
    if (v225 == nil) goto v45;
    v225 = v216;
    v4 = qcar(v225);
    v225 = v224;
    v225 = qcar(v225);
    if (equal(v4, v225)) goto v82;
    v225 = v216;
    v225 = qcar(v225);
    v224 = qcar(v224);
        return Lgreaterp(nil, v225, v224);

v82:
    v225 = v216;
    v225 = qcdr(v225);
    v216 = v225;
    v225 = v224;
    v225 = qcdr(v225);
    v224 = v225;
    goto v17;

v45:
    v225 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v225);
}



/* Code for simp!-prop!-condense */

static Lisp_Object CC_simpKpropKcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-condense");
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
    stack[-2] = nil;
    v248 = stack[-3];
    v189 = elt(env, 1); /* lambda_l73kgx_5 */
    fn = elt(env, 3); /* sort */
    v189 = (*qfn2(fn))(qenv(fn), v248, v189);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-5];
    stack[-3] = v189;
    goto v9;

v9:
    v189 = stack[-3];
    if (v189 == nil) goto v8;
    v189 = stack[-3];
    v189 = qcar(v189);
    stack[-4] = v189;
    v189 = stack[-3];
    v189 = qcdr(v189);
    stack[-3] = v189;
    v248 = stack[-4];
    v189 = stack[-2];
    v189 = cons(v248, v189);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-5];
    stack[-2] = v189;
    v189 = stack[-3];
    stack[-1] = v189;
    goto v173;

v173:
    v189 = stack[-1];
    if (v189 == nil) goto v9;
    v189 = stack[-1];
    v189 = qcar(v189);
    stack[0] = v189;
    v248 = stack[-4];
    v189 = stack[0];
    fn = elt(env, 4); /* subsetp */
    v189 = (*qfn2(fn))(qenv(fn), v248, v189);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-5];
    if (v189 == nil) goto v13;
    v248 = stack[0];
    v189 = stack[-3];
    v189 = Ldelete(nil, v248, v189);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-5];
    stack[-3] = v189;
    goto v13;

v13:
    v189 = stack[-1];
    v189 = qcdr(v189);
    stack[-1] = v189;
    goto v173;

v8:
    v189 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* ordn */
        return (*qfn1(fn))(qenv(fn), v189);
    }
/* error exit handlers */
v249:
    popv(6);
    return nil;
}



/* Code for lambda_l73kgx_5 */

static Lisp_Object CC_lambda_l73kgx_5(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l73kgx_5");
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
    v223 = v0;
/* end of prologue */
    stack[-1] = Llength(nil, v223);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v223 = stack[0];
    v223 = Llength(nil, v223);
    nil = C_nil;
    if (exception_pending()) goto v9;
    {
        Lisp_Object v213 = stack[-1];
        popv(3);
        return Llessp(nil, v213, v223);
    }
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for split_cov_cont_ids */

static Lisp_Object CC_split_cov_cont_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v167, v168;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_cov_cont_ids");
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
    stack[0] = nil;
    goto v45;

v45:
    v217 = stack[-1];
    if (v217 == nil) goto v204;
    v217 = stack[-1];
    v217 = qcar(v217);
    v168 = v217;
    v167 = v168;
    v217 = elt(env, 2); /* minus */
    if (!consp(v167)) goto v256;
    v167 = qcar(v167);
    if (!(v167 == v217)) goto v256;
    v217 = v168;
    v217 = qcdr(v217);
    v167 = qcar(v217);
    v217 = stack[-2];
    v217 = cons(v167, v217);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[-2] = v217;
    goto v20;

v20:
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    goto v45;

v256:
    v167 = v168;
    v217 = stack[0];
    v217 = cons(v167, v217);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[0] = v217;
    goto v20;

v204:
    v217 = stack[-2];
    v167 = Lnreverse(nil, v217);
    env = stack[-3];
    v217 = stack[0];
    v217 = Lnreverse(nil, v217);
    popv(4);
    return list2(v167, v217);
/* error exit handlers */
v99:
    popv(4);
    return nil;
}



/* Code for quotfail!-in!-vector */

static Lisp_Object MS_CDECL CC_quotfailKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v18, Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v427, v428, v60, v61, v50, v380, v429, v430;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "quotfail-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v15,v18,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v18,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v15;
    stack[-2] = v18;
    v60 = v1;
    stack[-3] = v0;
/* end of prologue */
    v428 = v60;
    v427 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v428)) < ((int32_t)(v427))) { popv(6); return onevalue(v60); }
    v428 = stack[-1];
    v427 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v428)) < ((int32_t)(v427))) goto v213;
    v428 = v60;
    v427 = stack[-1];
    if (((int32_t)(v428)) < ((int32_t)(v427))) goto v105;
    v428 = v60;
    v427 = stack[-1];
    v427 = (Lisp_Object)(int32_t)((int32_t)v428 - (int32_t)v427 + TAG_FIXNUM);
    stack[-4] = v427;
    v427 = stack[-4];
    stack[0] = v427;
    goto v268;

v268:
    v427 = stack[0];
    v427 = ((intptr_t)(v427) < 0 ? lisp_true : nil);
    if (v427 == nil) goto v267;
    v427 = (Lisp_Object)1; /* 0 */
    stack[0] = v427;
    goto v149;

v149:
    v427 = stack[-1];
    v428 = (Lisp_Object)((int32_t)(v427) - 0x10);
    v427 = stack[0];
    v427 = (Lisp_Object)(int32_t)((int32_t)v428 - (int32_t)v427 + TAG_FIXNUM);
    v427 = ((intptr_t)(v427) < 0 ? lisp_true : nil);
    if (v427 == nil) goto v431;
    v427 = (Lisp_Object)1; /* 0 */
    v380 = v427;
    goto v68;

v68:
    v428 = stack[-4];
    v427 = v380;
    v427 = (Lisp_Object)(int32_t)((int32_t)v428 - (int32_t)v427 + TAG_FIXNUM);
    v427 = ((intptr_t)(v427) < 0 ? lisp_true : nil);
    if (!(v427 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v50 = stack[-3];
    v61 = v380;
    v60 = stack[-3];
    v428 = stack[-1];
    v427 = v380;
    v427 = (Lisp_Object)(int32_t)((int32_t)v428 + (int32_t)v427 - TAG_FIXNUM);
    v427 = *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v427/(16/CELL)));
    *(Lisp_Object *)((char *)v50 + (CELL-TAG_VECTOR) + ((int32_t)v61/(16/CELL))) = v427;
    v427 = v380;
    v427 = (Lisp_Object)((int32_t)(v427) + 0x10);
    v380 = v427;
    goto v68;

v431:
    v428 = stack[-3];
    v427 = stack[0];
    v428 = *(Lisp_Object *)((char *)v428 + (CELL-TAG_VECTOR) + ((int32_t)v427/(16/CELL)));
    v427 = (Lisp_Object)1; /* 0 */
    if (v428 == v427) goto v70;
    v427 = elt(env, 4); /* "Quotient not exact in QUOTFAIL!-IN!-VECTOR" 
*/
    fn = elt(env, 5); /* errorf */
    v427 = (*qfn1(fn))(qenv(fn), v427);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-5];
    goto v70;

v70:
    v427 = stack[0];
    v427 = (Lisp_Object)((int32_t)(v427) + 0x10);
    stack[0] = v427;
    goto v149;

v267:
    v60 = stack[-3];
    v428 = stack[-1];
    v427 = stack[0];
    v427 = (Lisp_Object)(int32_t)((int32_t)v428 + (int32_t)v427 - TAG_FIXNUM);
    v60 = *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v427/(16/CELL)));
    v428 = stack[-2];
    v427 = stack[-1];
    v427 = *(Lisp_Object *)((char *)v428 + (CELL-TAG_VECTOR) + ((int32_t)v427/(16/CELL)));
    v427 = Lmodular_quotient(nil, v60, v427);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-5];
    v430 = v427;
    v427 = (Lisp_Object)1; /* 0 */
    v429 = v427;
    goto v199;

v199:
    v427 = stack[-1];
    v428 = (Lisp_Object)((int32_t)(v427) - 0x10);
    v427 = v429;
    v427 = (Lisp_Object)(int32_t)((int32_t)v428 - (int32_t)v427 + TAG_FIXNUM);
    v427 = ((intptr_t)(v427) < 0 ? lisp_true : nil);
    if (v427 == nil) goto v432;
    v60 = stack[-3];
    v428 = stack[-1];
    v427 = stack[0];
    v427 = (Lisp_Object)(int32_t)((int32_t)v428 + (int32_t)v427 - TAG_FIXNUM);
    v428 = v430;
    *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v427/(16/CELL))) = v428;
    v427 = stack[0];
    v427 = (Lisp_Object)((int32_t)(v427) - 0x10);
    stack[0] = v427;
    goto v268;

v432:
    v380 = stack[-3];
    v428 = stack[0];
    v427 = v429;
    v50 = (Lisp_Object)(int32_t)((int32_t)v428 + (int32_t)v427 - TAG_FIXNUM);
    v60 = stack[-3];
    v428 = stack[0];
    v427 = v429;
    v427 = (Lisp_Object)(int32_t)((int32_t)v428 + (int32_t)v427 - TAG_FIXNUM);
    v61 = *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v427/(16/CELL)));
    v60 = v430;
    v428 = stack[-2];
    v427 = v429;
    v427 = *(Lisp_Object *)((char *)v428 + (CELL-TAG_VECTOR) + ((int32_t)v427/(16/CELL)));
    v427 = Lmodular_times(nil, v60, v427);
    env = stack[-5];
    {   int32_t w = int_of_fixnum(v61) - int_of_fixnum(v427);
        if (w < 0) w += current_modulus;
        v427 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v380 + (CELL-TAG_VECTOR) + ((int32_t)v50/(16/CELL))) = v427;
    v427 = v429;
    v427 = (Lisp_Object)((int32_t)(v427) + 0x10);
    v429 = v427;
    goto v199;

v105:
    v427 = elt(env, 2); /* "Bad degrees in QUOTFAIL-IN-VECTOR" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v427);
    }

v213:
    v427 = elt(env, 1); /* "Attempt to divide by zero" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v427);
    }
/* error exit handlers */
v138:
    popv(6);
    return nil;
}



/* Code for reduce!-mod!-eigf */

static Lisp_Object CC_reduceKmodKeigf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-eigf");
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
    stack[-1] = v1;
    v2 = v0;
/* end of prologue */
    v220 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[-2] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v220; /* !*sub2 */
    v220 = v2;
    v220 = qcar(v220);
    stack[0] = qcar(v220);
    v220 = v2;
    v220 = qcdr(v220);
    v2 = qcar(v2);
    v2 = qcdr(v2);
    v2 = cons(v220, v2);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-3];
    fn = elt(env, 2); /* cancel */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-3];
    fn = elt(env, 3); /* negsq */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-3];
    v220 = cons(stack[0], v2);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-3];
    v2 = stack[-1];
    fn = elt(env, 4); /* reduce!-eival!-powers */
    v2 = (*qfn2(fn))(qenv(fn), v220, v2);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-3];
    fn = elt(env, 5); /* subs2 */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* !*sub2 */
    { popv(4); return onevalue(v2); }
/* error exit handlers */
v224:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* !*sub2 */
    popv(4);
    return nil;
}



/* Code for dfconst */

static Lisp_Object CC_dfconst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfconst");
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
    v214 = stack[0];
    v214 = qcar(v214);
    if (v214 == nil) goto v16;
    v214 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 3); /* vp2 */
    v215 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    v214 = stack[0];
    v214 = cons(v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v21;
    popv(2);
    return ncons(v214);

v16:
    v214 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v214); }
/* error exit handlers */
v21:
    popv(2);
    return nil;
}



/* Code for matrix_rows */

static Lisp_Object CC_matrix_rows(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix_rows");
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
    v220 = stack[0];
    if (v220 == nil) goto v17;
    v220 = elt(env, 1); /* "<matrixrow>" */
    fn = elt(env, 5); /* printout */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    v172 = qvalue(elt(env, 2)); /* indent */
    v220 = (Lisp_Object)49; /* 3 */
    v220 = plus2(v172, v220);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    qvalue(elt(env, 2)) = v220; /* indent */
    v220 = stack[0];
    v220 = qcar(v220);
    fn = elt(env, 6); /* row */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    v172 = qvalue(elt(env, 2)); /* indent */
    v220 = (Lisp_Object)49; /* 3 */
    v220 = difference2(v172, v220);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    qvalue(elt(env, 2)) = v220; /* indent */
    v220 = elt(env, 3); /* "</matrixrow>" */
    fn = elt(env, 5); /* printout */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    v220 = stack[0];
    v220 = qcdr(v220);
    v220 = CC_matrix_rows(env, v220);
    nil = C_nil;
    if (exception_pending()) goto v225;
    goto v17;

v17:
    v220 = nil;
    { popv(2); return onevalue(v220); }
/* error exit handlers */
v225:
    popv(2);
    return nil;
}



/* Code for ps!:prepfn!: */

static Lisp_Object CC_psTprepfnT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v15;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:prepfn:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    return onevalue(v15);
}



/* Code for vevstrictlydivides!? */

static Lisp_Object CC_vevstrictlydividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v174, v104, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevstrictlydivides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v1;
    v105 = v0;
/* end of prologue */
    v174 = v105;
    v3 = v104;
    if (equal(v174, v3)) goto v17;
    v3 = v104;
    v174 = v105;
    {
        fn = elt(env, 2); /* vevmtest!? */
        return (*qfn2(fn))(qenv(fn), v3, v174);
    }

v17:
    v3 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v3);
}



/* Code for klistt */

static Lisp_Object CC_klistt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for klistt");
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
    goto v17;

v17:
    v7 = stack[0];
    if (!consp(v7)) goto v45;
    v7 = stack[0];
    v7 = qcar(v7);
    v2 = qcar(v7);
    v7 = stack[-1];
    v7 = cons(v2, v7);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-2];
    stack[-1] = v7;
    v2 = stack[0];
    v7 = elt(env, 1); /* list */
    fn = elt(env, 2); /* carx */
    v7 = (*qfn2(fn))(qenv(fn), v2, v7);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-2];
    v7 = qcdr(v7);
    stack[0] = v7;
    goto v17;

v45:
    v7 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v7);
    }
/* error exit handlers */
v173:
    popv(3);
    return nil;
}



/* Code for matpri */

static Lisp_Object CC_matpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matpri");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */
    v82 = qcdr(v35);
    v35 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* matpri1 */
        return (*qfn2(fn))(qenv(fn), v82, v35);
    }
}



/* Code for omatpir */

static Lisp_Object MS_CDECL CC_omatpir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v104, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omatpir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omatpir");
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
    fn = elt(env, 3); /* lex */
    v174 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    fn = elt(env, 4); /* omsir */
    v174 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    v174 = qcar(v174);
    stack[-1] = v174;
    fn = elt(env, 3); /* lex */
    v174 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v174 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    v174 = qcar(v174);
    stack[0] = v174;
    fn = elt(env, 3); /* lex */
    v174 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    v174 = elt(env, 1); /* (!/ o m a t p) */
    fn = elt(env, 6); /* checktag */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    v105 = stack[-1];
    v104 = stack[0];
    v174 = qvalue(elt(env, 2)); /* nil */
    v174 = list2star(v105, v104, v174);
    nil = C_nil;
    if (exception_pending()) goto v185;
    popv(3);
    return ncons(v174);
/* error exit handlers */
v185:
    popv(3);
    return nil;
}



/* Code for drnconv */

static Lisp_Object CC_drnconv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v203, v204;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drnconv");
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
    v204 = v0;
/* end of prologue */
    v14 = v204;
    if (v14 == nil) return onevalue(v204);
    v14 = v204;
    if (is_number(v14)) return onevalue(v204);
    v203 = v204;
    v14 = qvalue(elt(env, 1)); /* dmd!* */
    if (!consp(v203)) goto v222;
    v203 = qcar(v203);
    if (v203 == v14) return onevalue(v204);
    else goto v222;

v222:
    v14 = v204;
    v203 = qcar(v14);
    v14 = qvalue(elt(env, 1)); /* dmd!* */
    v14 = get(v203, v14);
    v203 = v14;
    v14 = v203;
    if (v14 == nil) return onevalue(v204);
    v14 = v203;
    if (!(!consp(v14))) return onevalue(v204);
    v14 = v203;
    v203 = v204;
        return Lapply1(nil, v14, v203);
}



/* Code for evinvlexcomp */

static Lisp_Object CC_evinvlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v254;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evinvlexcomp");
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

v17:
    v98 = stack[-1];
    if (v98 == nil) goto v45;
    v98 = stack[0];
    if (v98 == nil) goto v21;
    v98 = stack[-1];
    v254 = qcar(v98);
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = Leqn(nil, v254, v98);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-3];
    if (v98 == nil) goto v13;
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    v98 = stack[0];
    v98 = qcdr(v98);
    stack[0] = v98;
    goto v17;

v13:
    v98 = stack[-1];
    v254 = qcdr(v98);
    v98 = stack[0];
    v98 = qcdr(v98);
    v98 = CC_evinvlexcomp(env, v254, v98);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-3];
    stack[-2] = v98;
    v254 = stack[-2];
    v98 = (Lisp_Object)1; /* 0 */
    v98 = Leqn(nil, v254, v98);
    nil = C_nil;
    if (exception_pending()) goto v241;
    if (v98 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v98 = stack[0];
    v254 = qcar(v98);
    v98 = stack[-1];
    v98 = qcar(v98);
    if (((int32_t)(v254)) > ((int32_t)(v98))) goto v267;
    v98 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v98); }

v267:
    v98 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v98); }

v21:
    v254 = stack[-1];
    v98 = elt(env, 1); /* (0) */
    {
        popv(4);
        fn = elt(env, 2); /* evlexcomp */
        return (*qfn2(fn))(qenv(fn), v254, v98);
    }

v45:
    v98 = stack[0];
    if (v98 == nil) goto v223;
    v98 = elt(env, 1); /* (0) */
    stack[-1] = v98;
    goto v17;

v223:
    v98 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v98); }
/* error exit handlers */
v241:
    popv(4);
    return nil;
}



/* Code for fl2bf */

static Lisp_Object CC_fl2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v261;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fl2bf");
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
    v11 = v0;
/* end of prologue */
    fn = elt(env, 3); /* frexp */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    stack[-2] = v11;
    v11 = stack[-2];
    v11 = qcdr(v11);
    v261 = stack[-2];
    v261 = qcar(v261);
    stack[-2] = v261;
    stack[0] = v11;
    v261 = (Lisp_Object)33; /* 2 */
    v11 = qvalue(elt(env, 1)); /* !!nbfpd */
    v11 = Lexpt(nil, v261, v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    v11 = times2(stack[0], v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    v11 = Ltruncate(nil, v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    stack[-1] = elt(env, 2); /* !:rd!: */
    stack[0] = v11;
    v261 = stack[-2];
    v11 = qvalue(elt(env, 1)); /* !!nbfpd */
    v11 = difference2(v261, v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    v11 = list2star(stack[-1], stack[0], v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v11);
    }
/* error exit handlers */
v14:
    popv(4);
    return nil;
}



/* Code for intrdsortin */

static Lisp_Object CC_intrdsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intrdsortin");
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
    goto v53;

v53:
    v253 = stack[0];
    if (v253 == nil) goto v223;
    v253 = stack[-1];
    v99 = qcar(v253);
    v253 = stack[0];
    v253 = qcar(v253);
    v253 = qcar(v253);
    fn = elt(env, 1); /* !:difference */
    v253 = (*qfn2(fn))(qenv(fn), v99, v253);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    fn = elt(env, 2); /* !:minusp */
    v253 = (*qfn1(fn))(qenv(fn), v253);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    if (v253 == nil) goto v101;
    v253 = stack[0];
    v99 = qcar(v253);
    v253 = stack[-2];
    v253 = cons(v99, v253);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    stack[-2] = v253;
    v253 = stack[0];
    v253 = qcdr(v253);
    stack[0] = v253;
    goto v53;

v101:
    v99 = stack[-1];
    v253 = stack[0];
    v253 = cons(v99, v253);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    {
        Lisp_Object v267 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v267, v253);
    }

v223:
    stack[0] = stack[-2];
    v253 = stack[-1];
    v253 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    {
        Lisp_Object v189 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v189, v253);
    }
/* error exit handlers */
v250:
    popv(4);
    return nil;
}



/* Code for contr!-strand */

static Lisp_Object CC_contrKstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr-strand");
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
    stack[0] = v1;
    v3 = v0;
/* end of prologue */

v17:
    v174 = stack[0];
    if (v174 == nil) { popv(2); return onevalue(v3); }
    v174 = v3;
    v3 = stack[0];
    v3 = qcar(v3);
    fn = elt(env, 1); /* contr1!-strand */
    v3 = (*qfn2(fn))(qenv(fn), v174, v3);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v174 = stack[0];
    v174 = qcdr(v174);
    stack[0] = v174;
    goto v17;
/* error exit handlers */
v105:
    popv(2);
    return nil;
}



/* Code for fs!:prin */

static Lisp_Object CC_fsTprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin");
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
    v172 = stack[0];
    if (!(v172 == nil)) goto v223;
    v172 = elt(env, 1); /* " 0 " */
    {
        popv(2);
        fn = elt(env, 4); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v172);
    }

v223:
    v172 = stack[0];
    if (v172 == nil) goto v9;
    v172 = stack[0];
    fn = elt(env, 5); /* fs!:prin1 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-1];
    v173 = stack[0];
    v172 = (Lisp_Object)49; /* 3 */
    v172 = *(Lisp_Object *)((char *)v173 + (CELL-TAG_VECTOR) + ((int32_t)v172/(16/CELL)));
    stack[0] = v172;
    v172 = stack[0];
    if (v172 == nil) goto v223;
    v172 = elt(env, 3); /* " + " */
    fn = elt(env, 4); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-1];
    goto v223;

v9:
    v172 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v172); }
/* error exit handlers */
v224:
    popv(2);
    return nil;
}



/* Code for st_ad_numsorttree */

static Lisp_Object CC_st_ad_numsorttree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_ad_numsorttree");
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
    v19 = v0;
/* end of prologue */
    fn = elt(env, 1); /* st_ad_numsorttree1 */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    errexit();
    v20 = v19;
    v20 = qcar(v20);
    v19 = qcdr(v19);
    v19 = qcar(v19);
    return cons(v20, v19);
}



/* Code for cl_identifyonoff */

static Lisp_Object CC_cl_identifyonoff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v15;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyonoff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v15 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v15; /* cl_identify!-atl!* */
    return onevalue(v15);
}



setup_type const u23_setup[] =
{
    {"gfplusn",                 too_few_2,      CC_gfplusn,    wrong_no_2},
    {"mkfortterpri",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkfortterpri},
    {"clogsq*",                 CC_clogsqH,     too_many_1,    wrong_no_1},
    {"ratfunpri1",              CC_ratfunpri1,  too_many_1,    wrong_no_1},
    {"simp-prop1",              too_few_2,      CC_simpKprop1, wrong_no_2},
    {"general-horner-rule-mod-p",wrong_no_na,   wrong_no_nb,   (n_args *)CC_generalKhornerKruleKmodKp},
    {"rl_bettergaussp",         too_few_2,      CC_rl_bettergaussp,wrong_no_2},
    {"multdfconst",             too_few_2,      CC_multdfconst,wrong_no_2},
    {"offexpchk",               CC_offexpchk,   too_many_1,    wrong_no_1},
    {"give*position",           too_few_2,      CC_giveHposition,wrong_no_2},
    {"atomlis",                 CC_atomlis,     too_many_1,    wrong_no_1},
    {"mconv1",                  CC_mconv1,      too_many_1,    wrong_no_1},
    {"gcd2",                    too_few_2,      CC_gcd2,       wrong_no_2},
    {"lchk",                    CC_lchk,        too_many_1,    wrong_no_1},
    {"wedgef",                  CC_wedgef,      too_many_1,    wrong_no_1},
    {"sublap",                  too_few_2,      CC_sublap,     wrong_no_2},
    {"*di2q",                   too_few_2,      CC_Hdi2q,      wrong_no_2},
    {"cl_fvarl1",               CC_cl_fvarl1,   too_many_1,    wrong_no_1},
    {"containerml",             too_few_2,      CC_containerml,wrong_no_2},
    {"exptplus",                too_few_2,      CC_exptplus,   wrong_no_2},
    {"dipequal",                too_few_2,      CC_dipequal,   wrong_no_2},
    {"difference:",             too_few_2,      CC_differenceT,wrong_no_2},
    {"indexsymmetrize",         CC_indexsymmetrize,too_many_1, wrong_no_1},
    {"*xadd",                   too_few_2,      CC_Hxadd,      wrong_no_2},
    {"contract-strand",         too_few_2,      CC_contractKstrand,wrong_no_2},
    {"liennewstruc",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_liennewstruc},
    {"mv-pow->",                too_few_2,      CC_mvKpowKS,   wrong_no_2},
    {"simp-prop-condense",      CC_simpKpropKcondense,too_many_1,wrong_no_1},
    {"lambda_l73kgx_5",         too_few_2,      CC_lambda_l73kgx_5,wrong_no_2},
    {"split_cov_cont_ids",      CC_split_cov_cont_ids,too_many_1,wrong_no_1},
    {"quotfail-in-vector",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfailKinKvector},
    {"reduce-mod-eigf",         too_few_2,      CC_reduceKmodKeigf,wrong_no_2},
    {"dfconst",                 CC_dfconst,     too_many_1,    wrong_no_1},
    {"matrix_rows",             CC_matrix_rows, too_many_1,    wrong_no_1},
    {"ps:prepfn:",              CC_psTprepfnT,  too_many_1,    wrong_no_1},
    {"vevstrictlydivides?",     too_few_2,      CC_vevstrictlydividesW,wrong_no_2},
    {"klistt",                  CC_klistt,      too_many_1,    wrong_no_1},
    {"matpri",                  CC_matpri,      too_many_1,    wrong_no_1},
    {"omatpir",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_omatpir},
    {"drnconv",                 CC_drnconv,     too_many_1,    wrong_no_1},
    {"evinvlexcomp",            too_few_2,      CC_evinvlexcomp,wrong_no_2},
    {"fl2bf",                   CC_fl2bf,       too_many_1,    wrong_no_1},
    {"intrdsortin",             too_few_2,      CC_intrdsortin,wrong_no_2},
    {"contr-strand",            too_few_2,      CC_contrKstrand,wrong_no_2},
    {"fs:prin",                 CC_fsTprin,     too_many_1,    wrong_no_1},
    {"st_ad_numsorttree",       CC_st_ad_numsorttree,too_many_1,wrong_no_1},
    {"cl_identifyonoff",        CC_cl_identifyonoff,too_many_1,wrong_no_1},
    {NULL, (one_args *)"u23", (two_args *)"20261 1246073 3873955", 0}
};

/* end of generated code */
