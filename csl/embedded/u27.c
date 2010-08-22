
/* $destdir/generated-c\u27.c Machine generated C code */

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


/* Code for setrd */

static Lisp_Object MS_CDECL CC_setrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setrd");
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
    v5 = elt(env, 1); /* (t y p e != s e t !$) */
    qvalue(elt(env, 2)) = v5; /* atts */
    stack[0] = elt(env, 3); /* list */
    fn = elt(env, 4); /* stats_getargs */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    v5 = cons(stack[0], v5);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    v6 = v5;
    v5 = v6;
    stack[0] = qcar(v5);
    v5 = v6;
    v5 = qcdr(v5);
    fn = elt(env, 5); /* norepeat */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v7;
    {
        Lisp_Object v8 = stack[0];
        popv(2);
        return cons(v8, v5);
    }
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for multerm */

static Lisp_Object CC_multerm(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multerm");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v9;
/* end of prologue */
    v17 = stack[-1];
    v18 = qcdr(v17);
    v17 = stack[0];
    v17 = qcdr(v17);
    fn = elt(env, 1); /* !*multsq */
    v17 = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    stack[-2] = v17;
    v17 = stack[-1];
    v18 = qcar(v17);
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 2); /* mulpower */
    v17 = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    {
        Lisp_Object v20 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multdfconst */
        return (*qfn2(fn))(qenv(fn), v20, v17);
    }
/* error exit handlers */
v19:
    popv(4);
    return nil;
}



/* Code for evinsert */

static Lisp_Object MS_CDECL CC_evinsert(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, Lisp_Object v14, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "evinsert");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evinsert");
#endif
    if (stack >= stacklimit)
    {
        push4(v14,v21,v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v9,v2,v21,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v14;
    stack[-1] = v21;
    stack[-2] = v2;
    stack[-3] = v9;
/* end of prologue */
    v32 = nil;
    goto v33;

v33:
    v30 = stack[-3];
    if (v30 == nil) goto v3;
    v30 = stack[0];
    if (v30 == nil) goto v3;
    v30 = stack[0];
    v31 = qcar(v30);
    v30 = stack[-2];
    if (equal(v31, v30)) goto v12;
    v30 = stack[-3];
    v30 = qcar(v30);
    v31 = v32;
    v30 = cons(v30, v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v32 = v30;
    v30 = stack[-3];
    v30 = qcdr(v30);
    stack[-3] = v30;
    v30 = stack[0];
    v30 = qcdr(v30);
    stack[0] = v30;
    goto v33;

v12:
    stack[0] = v32;
    v31 = stack[-1];
    v30 = stack[-3];
    v30 = qcdr(v30);
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    {
        Lisp_Object v35 = stack[0];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v35, v30);
    }

v3:
    v30 = v32;
    {
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v30);
    }
/* error exit handlers */
v34:
    popv(5);
    return nil;
}



/* Code for list!-evaluate */

static Lisp_Object MS_CDECL CC_listKevaluate(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "list-evaluate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-evaluate");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v9,v2,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v21;
    stack[-4] = v2;
    v43 = v9;
/* end of prologue */
    stack[-5] = v43;
    v43 = stack[-5];
    if (v43 == nil) goto v15;
    v43 = stack[-5];
    v43 = qcar(v43);
    v45 = v43;
    v44 = stack[-4];
    v43 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v43 = (*qfnn(fn))(qenv(fn), 3, v45, v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-6];
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-6];
    stack[-1] = v43;
    stack[-2] = v43;
    goto v47;

v47:
    v43 = stack[-5];
    v43 = qcdr(v43);
    stack[-5] = v43;
    v43 = stack[-5];
    if (v43 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v43 = stack[-5];
    v43 = qcar(v43);
    v45 = v43;
    v44 = stack[-4];
    v43 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v43 = (*qfnn(fn))(qenv(fn), 3, v45, v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-6];
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-6];
    v43 = Lrplacd(nil, stack[0], v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-6];
    v43 = stack[-1];
    v43 = qcdr(v43);
    stack[-1] = v43;
    goto v47;

v15:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v43); }
/* error exit handlers */
v46:
    popv(7);
    return nil;
}



/* Code for indxsymp */

static Lisp_Object CC_indxsymp(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indxsymp");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v9;
/* end of prologue */

v49:
    v17 = stack[0];
    v17 = (v17 == nil ? lisp_true : nil);
    if (!(v17 == nil)) { popv(3); return onevalue(v17); }
    v17 = stack[0];
    v18 = qcar(v17);
    v17 = stack[-1];
    v17 = Lapply1(nil, v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    if (v17 == nil) goto v51;
    v18 = stack[-1];
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[-1] = v18;
    stack[0] = v17;
    goto v49;

v51:
    v17 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v17); }
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for reval3 */

static Lisp_Object CC_reval3(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval3");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v52 = v9;
/* end of prologue */
    fn = elt(env, 1); /* simp */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v33:
    popv(1);
    return nil;
}



/* Code for harmonicp */

static Lisp_Object CC_harmonicp(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for harmonicp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v9;
/* end of prologue */
    v3 = elt(env, 1); /* fourier!-angle */
    return get(v51, v3);
}



/* Code for clean_numid */

static Lisp_Object CC_clean_numid(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clean_numid");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
/* end of prologue */
    stack[-1] = nil;
    goto v24;

v24:
    v17 = stack[0];
    if (v17 == nil) goto v33;
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 1); /* !*id2num */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    if (v17 == nil) goto v11;
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v24;

v11:
    v17 = stack[0];
    v18 = qcar(v17);
    v17 = stack[-1];
    v17 = cons(v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    stack[-1] = v17;
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v24;

v33:
    v17 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v17);
    }
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for fd2q */

static Lisp_Object CC_fd2q(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fd2q");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
/* end of prologue */

v40:
    v60 = stack[0];
    if (!consp(v60)) goto v3;
    v60 = stack[0];
    v61 = qcar(v60);
    v60 = elt(env, 1); /* !:ar!: */
    if (v61 == v60) goto v62;
    v60 = stack[0];
    v61 = qcar(v60);
    v60 = elt(env, 2); /* !:rn!: */
    if (v61 == v60) goto v12;
    v60 = stack[0];
    v60 = qcar(v60);
    v61 = qcar(v60);
    v60 = (Lisp_Object)17; /* 1 */
    v60 = cons(v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v61 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v60 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v60 = stack[0];
    v60 = qcar(v60);
    v60 = qcdr(v60);
    v60 = CC_fd2q(env, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    fn = elt(env, 3); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = CC_fd2q(env, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    {
        Lisp_Object v64 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v64, v60);
    }

v12:
    v60 = stack[0];
    v60 = qcdr(v60);
    { popv(3); return onevalue(v60); }

v62:
    v60 = stack[0];
    v60 = qcdr(v60);
    stack[0] = v60;
    goto v40;

v3:
    v61 = stack[0];
    v60 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v61, v60);
/* error exit handlers */
v63:
    popv(3);
    return nil;
}



/* Code for sq2sspl */

static Lisp_Object CC_sq2sspl(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sspl");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v9;
/* end of prologue */
    stack[-2] = nil;
    goto v52;

v52:
    v23 = stack[-1];
    if (!consp(v23)) goto v33;
    v23 = stack[-1];
    v23 = qcar(v23);
    if (!consp(v23)) goto v33;
    v23 = stack[-1];
    v54 = qcar(v23);
    v23 = stack[0];
    fn = elt(env, 1); /* sq2sstm */
    v54 = (*qfn2(fn))(qenv(fn), v54, v23);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v23 = stack[-2];
    v23 = cons(v54, v23);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-2] = v23;
    v23 = stack[-1];
    v23 = qcdr(v23);
    stack[-1] = v23;
    goto v52;

v33:
    v23 = stack[-1];
    v54 = v23;
    goto v47;

v47:
    v23 = stack[-2];
    if (v23 == nil) { popv(4); return onevalue(v54); }
    v23 = stack[-2];
    v23 = qcar(v23);
    v23 = Lappend(nil, v23, v54);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v54 = v23;
    v23 = stack[-2];
    v23 = qcdr(v23);
    stack[-2] = v23;
    goto v47;
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for maxfrom1 */

static Lisp_Object MS_CDECL CC_maxfrom1(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "maxfrom1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxfrom1");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v9,v2,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v2;
    stack[-2] = v9;
/* end of prologue */

v41:
    v18 = stack[-2];
    if (v18 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v18 = stack[-2];
    v18 = qcar(v18);
    v25 = qcar(v18);
    v18 = stack[-1];
    fn = elt(env, 1); /* nth */
    v25 = (*qfn2(fn))(qenv(fn), v25, v18);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v18 = stack[0];
    fn = elt(env, 2); /* max */
    v18 = (*qfn2(fn))(qenv(fn), v25, v18);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    stack[0] = v18;
    v18 = stack[-2];
    v18 = qcdr(v18);
    stack[-2] = v18;
    goto v41;
/* error exit handlers */
v20:
    popv(4);
    return nil;
}



/* Code for mk!+resimp!+mat */

static Lisp_Object CC_mkLresimpLmat(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+resimp+mat");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v75 = v9;
/* end of prologue */
    stack[-7] = v75;
    v75 = stack[-7];
    if (v75 == nil) goto v59;
    v75 = stack[-7];
    v75 = qcar(v75);
    stack[-3] = v75;
    v75 = stack[-3];
    if (v75 == nil) goto v17;
    v75 = stack[-3];
    v75 = qcar(v75);
    fn = elt(env, 2); /* resimp */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    stack[-1] = v75;
    stack[-2] = v75;
    goto v8;

v8:
    v75 = stack[-3];
    v75 = qcdr(v75);
    stack[-3] = v75;
    v75 = stack[-3];
    if (v75 == nil) goto v37;
    stack[0] = stack[-1];
    v75 = stack[-3];
    v75 = qcar(v75);
    fn = elt(env, 2); /* resimp */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = Lrplacd(nil, stack[0], v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = stack[-1];
    v75 = qcdr(v75);
    stack[-1] = v75;
    goto v8;

v37:
    v75 = stack[-2];
    goto v7;

v7:
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    stack[-5] = v75;
    stack[-6] = v75;
    goto v4;

v4:
    v75 = stack[-7];
    v75 = qcdr(v75);
    stack[-7] = v75;
    v75 = stack[-7];
    if (v75 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    stack[-4] = stack[-5];
    v75 = stack[-7];
    v75 = qcar(v75);
    stack[-3] = v75;
    v75 = stack[-3];
    if (v75 == nil) goto v77;
    v75 = stack[-3];
    v75 = qcar(v75);
    fn = elt(env, 2); /* resimp */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    stack[-1] = v75;
    stack[-2] = v75;
    goto v78;

v78:
    v75 = stack[-3];
    v75 = qcdr(v75);
    stack[-3] = v75;
    v75 = stack[-3];
    if (v75 == nil) goto v79;
    stack[0] = stack[-1];
    v75 = stack[-3];
    v75 = qcar(v75);
    fn = elt(env, 2); /* resimp */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = Lrplacd(nil, stack[0], v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = stack[-1];
    v75 = qcdr(v75);
    stack[-1] = v75;
    goto v78;

v79:
    v75 = stack[-2];
    goto v80;

v80:
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = Lrplacd(nil, stack[-4], v75);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-8];
    v75 = stack[-5];
    v75 = qcdr(v75);
    stack[-5] = v75;
    goto v4;

v77:
    v75 = qvalue(elt(env, 1)); /* nil */
    goto v80;

v17:
    v75 = qvalue(elt(env, 1)); /* nil */
    goto v7;

v59:
    v75 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v75); }
/* error exit handlers */
v76:
    popv(9);
    return nil;
}



/* Code for vdp_plist */

static Lisp_Object CC_vdp_plist(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object v33;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_plist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v9;
/* end of prologue */
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    v33 = qcar(v33);
    return onevalue(v33);
}



/* Code for setfuncsnaryrd */

static Lisp_Object MS_CDECL CC_setfuncsnaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setfuncsnaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setfuncsnaryrd");
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
    fn = elt(env, 4); /* mathml */
    v81 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    stack[0] = v81;
    v81 = stack[0];
    v81 = Lconsp(nil, v81);
    env = stack[-1];
    if (v81 == nil) goto v41;
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = qcar(v81);
    if (v81 == nil) goto v41;
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = qcar(v81);
    v81 = qcar(v81);
    v81 = qcdr(v81);
    v81 = qcar(v81);
    v22 = Lintern(nil, v81);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    v81 = elt(env, 1); /* multiset */
    if (!(v22 == v81)) goto v41;
    v81 = elt(env, 1); /* multiset */
    qvalue(elt(env, 2)) = v81; /* mmlatts */
    goto v41;

v41:
    v81 = stack[0];
    if (v81 == nil) goto v20;
    v81 = CC_setfuncsnaryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v54;
    {
        Lisp_Object v72 = stack[0];
        popv(2);
        return cons(v72, v81);
    }

v20:
    v81 = nil;
    { popv(2); return onevalue(v81); }
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for init */

static Lisp_Object CC_init(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v130, v131, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for init");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v9;
/* end of prologue */
    v129 = qvalue(elt(env, 1)); /* rowmin */
    stack[-2] = v129;
    goto v59;

v59:
    v130 = qvalue(elt(env, 2)); /* rowmax */
    v129 = stack[-2];
    v129 = difference2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v129 = Lminusp(nil, v129);
    env = stack[-3];
    if (v129 == nil) goto v8;
    v130 = qvalue(elt(env, 5)); /* maxvar */
    v129 = stack[-1];
    if (equal(v130, v129)) goto v134;
    v130 = (Lisp_Object)33; /* 2 */
    v129 = stack[-1];
    v129 = times2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v129 = Lmkvect(nil, v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    qvalue(elt(env, 4)) = v129; /* codmat */
    goto v135;

v135:
    v129 = qvalue(elt(env, 14)); /* kvarlst */
    if (v129 == nil) goto v136;
    v129 = qvalue(elt(env, 14)); /* kvarlst */
    v132 = v129;
    goto v137;

v137:
    v129 = v132;
    if (v129 == nil) goto v136;
    v129 = v132;
    v129 = qcar(v129);
    v131 = v129;
    v129 = v131;
    v129 = qcdr(v129);
    v130 = qcar(v129);
    v129 = elt(env, 14); /* kvarlst */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v129 = v131;
    v129 = qcdr(v129);
    v130 = qcar(v129);
    v129 = elt(env, 11); /* nex */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v129 = v132;
    v129 = qcdr(v129);
    v132 = v129;
    goto v137;

v136:
    v129 = elt(env, 19); /* (plus minus difference times expt sqrt) */
    v131 = v129;
    goto v138;

v138:
    v129 = v131;
    if (v129 == nil) goto v139;
    v129 = v131;
    v129 = qcar(v129);
    v130 = v129;
    v129 = elt(env, 14); /* kvarlst */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v129 = v131;
    v129 = qcdr(v129);
    v131 = v129;
    goto v138;

v139:
    v129 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 20)) = v129; /* avarlst */
    qvalue(elt(env, 21)) = v129; /* codbexl!* */
    qvalue(elt(env, 14)) = v129; /* kvarlst */
    qvalue(elt(env, 22)) = v129; /* prevlst */
    qvalue(elt(env, 8)) = v129; /* varlst!+ */
    qvalue(elt(env, 9)) = v129; /* varlst!* */
    v129 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 23)) = v129; /* preprefixlist */
    qvalue(elt(env, 24)) = v129; /* malst */
    v129 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 25)) = v129; /* prefixlist */
    v129 = (Lisp_Object)-15; /* -1 */
    qvalue(elt(env, 2)) = v129; /* rowmax */
    v129 = stack[-1];
    qvalue(elt(env, 5)) = v129; /* maxvar */
    v129 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v129; /* rowmin */
    v132 = (Lisp_Object)1; /* 0 */
    v131 = (Lisp_Object)1; /* 0 */
    v130 = (Lisp_Object)1; /* 0 */
    v129 = (Lisp_Object)1; /* 0 */
    v129 = list4(v132, v131, v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    qvalue(elt(env, 26)) = v129; /* ops */
    v129 = nil;
    { popv(4); return onevalue(v129); }

v134:
    v129 = (Lisp_Object)1; /* 0 */
    stack[0] = v129;
    goto v140;

v140:
    v130 = (Lisp_Object)33; /* 2 */
    v129 = stack[-1];
    v130 = times2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v129 = stack[0];
    v129 = difference2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v129 = Lminusp(nil, v129);
    env = stack[-3];
    if (!(v129 == nil)) goto v135;
    v131 = qvalue(elt(env, 4)); /* codmat */
    v130 = stack[0];
    v129 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v131 + (CELL-TAG_VECTOR) + ((int32_t)v130/(16/CELL))) = v129;
    v129 = stack[0];
    v129 = add1(v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    stack[0] = v129;
    goto v140;

v8:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v130 = qvalue(elt(env, 5)); /* maxvar */
    v129 = stack[-2];
    v129 = plus2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v129 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v129/(16/CELL)));
    if (v129 == nil) goto v5;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v130 = qvalue(elt(env, 5)); /* maxvar */
    v129 = stack[-2];
    v129 = plus2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v130 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v129/(16/CELL)));
    v129 = (Lisp_Object)49; /* 3 */
    v129 = *(Lisp_Object *)((char *)v130 + (CELL-TAG_VECTOR) + ((int32_t)v129/(16/CELL)));
    v131 = v129;
    if (is_number(v129)) goto v5;
    v130 = v131;
    v129 = elt(env, 6); /* npcdvar */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 7); /* nvarlst */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 8); /* varlst!+ */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 9); /* varlst!* */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 10); /* rowindex */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 11); /* nex */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 12); /* inlhs */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 13); /* rowocc */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 14); /* kvarlst */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 15); /* alias */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 16); /* finalalias */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 17); /* aliaslist */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    v130 = v131;
    v129 = elt(env, 18); /* inalias */
    v129 = Lremprop(nil, v130, v129);
    env = stack[-3];
    goto v5;

v5:
    v129 = stack[-2];
    v129 = add1(v129);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    stack[-2] = v129;
    goto v59;
/* error exit handlers */
v133:
    popv(4);
    return nil;
}



/* Code for gftimes */

static Lisp_Object CC_gftimes(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gftimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v2;
    v8 = v9;
/* end of prologue */
    v29 = v8;
    v29 = qcar(v29);
    if (!consp(v29)) goto v51;
    v29 = v8;
    {
        fn = elt(env, 1); /* gbftimes */
        return (*qfn2(fn))(qenv(fn), v29, v7);
    }

v51:
    v29 = v8;
    {
        fn = elt(env, 2); /* gfftimes */
        return (*qfn2(fn))(qenv(fn), v29, v7);
    }
}



/* Code for skp_ordp */

static Lisp_Object CC_skp_ordp(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v58, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for skp_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v2;
    v58 = v9;
/* end of prologue */
    v62 = qcar(v58);
    v58 = qcar(v59);
    v59 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v62, v58, v59);
    }
}



/* Code for msolve!-psys1 */

static Lisp_Object CC_msolveKpsys1(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-psys1");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v2;
    stack[0] = v9;
/* end of prologue */
    v69 = qvalue(elt(env, 1)); /* nil */
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-7];
    v70 = v69;
    v69 = stack[0];
    stack[-4] = v69;
    goto v141;

v141:
    v69 = stack[-4];
    if (v69 == nil) { popv(8); return onevalue(v70); }
    v69 = stack[-4];
    v69 = qcar(v69);
    stack[-3] = v69;
    v69 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v69;
    v69 = v70;
    stack[-2] = v69;
    goto v8;

v8:
    v69 = stack[-2];
    if (v69 == nil) goto v7;
    v69 = stack[-2];
    v69 = qcar(v69);
    stack[-1] = v69;
    v70 = stack[-3];
    v69 = stack[-1];
    fn = elt(env, 2); /* subf */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-7];
    v69 = qcar(v69);
    fn = elt(env, 3); /* moduntag */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-7];
    fn = elt(env, 4); /* general!-reduce!-mod!-p */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-7];
    v70 = v69;
    v69 = v70;
    if (v69 == nil) goto v72;
    v69 = v70;
    if (!consp(v69)) goto v66;
    v69 = v70;
    v69 = qcar(v69);
    if (!consp(v69)) goto v66;
    v69 = stack[-5];
    fn = elt(env, 5); /* msolve!-poly */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-7];
    stack[0] = v69;
    goto v149;

v149:
    v69 = stack[0];
    if (v69 == nil) goto v66;
    v69 = stack[0];
    v69 = qcar(v69);
    v70 = stack[-1];
    v70 = Lappend(nil, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-7];
    v69 = stack[-6];
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-7];
    stack[-6] = v69;
    v69 = stack[0];
    v69 = qcdr(v69);
    stack[0] = v69;
    goto v149;

v66:
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v8;

v72:
    v70 = stack[-1];
    v69 = stack[-6];
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-7];
    stack[-6] = v69;
    goto v66;

v7:
    v69 = stack[-6];
    v70 = v69;
    v69 = stack[-4];
    v69 = qcdr(v69);
    stack[-4] = v69;
    goto v141;
/* error exit handlers */
v148:
    popv(8);
    return nil;
}



/* Code for orddf */

static Lisp_Object CC_orddf(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for orddf");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v9;
/* end of prologue */

v24:
    v38 = stack[-1];
    if (v38 == nil) goto v33;
    v38 = stack[0];
    if (v38 == nil) goto v10;
    v38 = stack[-1];
    v30 = qcar(v38);
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 6); /* exptcompare */
    v38 = (*qfn2(fn))(qenv(fn), v30, v38);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    if (v38 == nil) goto v150;
    v38 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v38); }

v150:
    v38 = stack[0];
    v30 = qcar(v38);
    v38 = stack[-1];
    v38 = qcar(v38);
    fn = elt(env, 6); /* exptcompare */
    v38 = (*qfn2(fn))(qenv(fn), v30, v38);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    if (v38 == nil) goto v81;
    v38 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v38); }

v81:
    v38 = stack[-1];
    v38 = qcdr(v38);
    stack[-1] = v38;
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v24;

v10:
    v38 = elt(env, 3); /* "Orddf u longer than v" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v38);
    }

v33:
    v38 = stack[0];
    if (v38 == nil) goto v15;
    v38 = elt(env, 2); /* "Orddf v longer than u" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v38);
    }

v15:
    v38 = elt(env, 1); /* "Orddf = case" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v38);
    }
/* error exit handlers */
v127:
    popv(3);
    return nil;
}



/* Code for simpexpt1 */

static Lisp_Object MS_CDECL CC_simpexpt1(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v201, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt1");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v9,v2,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v21;
    stack[-5] = v2;
    stack[-6] = v9;
/* end of prologue */
    stack[-7] = qvalue(elt(env, 1)); /* !*allfac */
    qvalue(elt(env, 1)) = nil; /* !*allfac */
    stack[-3] = qvalue(elt(env, 2)); /* !*div */
    qvalue(elt(env, 2)) = nil; /* !*div */
    v200 = stack[-6];
    v200 = Lonep(nil, v200);
    env = stack[-8];
    if (v200 == nil) goto v4;
    v201 = (Lisp_Object)17; /* 1 */
    v200 = (Lisp_Object)17; /* 1 */
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v51:
    qvalue(elt(env, 2)) = stack[-3]; /* !*div */
    qvalue(elt(env, 1)) = stack[-7]; /* !*allfac */
    { popv(9); return onevalue(v200); }

v4:
    v200 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v200; /* !*allfac */
    v200 = stack[-5];
    v200 = qcar(v200);
    stack[-2] = v200;
    v201 = stack[-2];
    v200 = (Lisp_Object)17; /* 1 */
    if (!(v201 == v200)) goto v54;
    v200 = stack[-5];
    v201 = qcdr(v200);
    v200 = (Lisp_Object)17; /* 1 */
    if (!(v201 == v200)) goto v54;
    v200 = stack[-6];
    fn = elt(env, 12); /* simp */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v54:
    v201 = stack[-6];
    v200 = elt(env, 4); /* e */
    if (!(v201 == v200)) goto v66;
    v200 = stack[-5];
    v200 = qcdr(v200);
    if (!consp(v200)) goto v127;
    v200 = stack[-5];
    v200 = qcdr(v200);
    v200 = qcar(v200);
    if (!(!consp(v200))) goto v66;

v127:
    v200 = stack[-2];
    if (!consp(v200)) goto v66;
    v200 = stack[-2];
    v200 = qcar(v200);
    if (!consp(v200)) goto v66;
    v200 = stack[-2];
    v200 = qcar(v200);
    v200 = qcar(v200);
    v201 = qcdr(v200);
    v200 = (Lisp_Object)17; /* 1 */
    if (!(v201 == v200)) goto v66;
    v200 = stack[-2];
    v200 = qcdr(v200);
    if (!(v200 == nil)) goto v66;
    v200 = stack[-2];
    v200 = qcar(v200);
    v200 = qcar(v200);
    v201 = qcar(v200);
    v200 = elt(env, 5); /* log */
    if (!consp(v201)) goto v66;
    v201 = qcar(v201);
    if (!(v201 == v200)) goto v66;
    v200 = stack[-2];
    v200 = qcar(v200);
    v200 = qcar(v200);
    v200 = qcar(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    fn = elt(env, 13); /* simp!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    fn = elt(env, 14); /* prepsq!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    v200 = stack[-2];
    v200 = qcar(v200);
    v201 = qcdr(v200);
    v200 = stack[-5];
    v200 = qcdr(v200);
    v201 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    v200 = qvalue(elt(env, 6)); /* nil */
    v200 = CC_simpexpt1(env, 3, stack[0], v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v66:
    v200 = stack[-2];
    if (!consp(v200)) goto v204;
    v200 = stack[-2];
    v200 = qcar(v200);
    if (!(!consp(v200))) goto v205;

v204:
    v200 = stack[-5];
    v200 = qcdr(v200);
    if (!consp(v200)) goto v206;
    v200 = stack[-5];
    v200 = qcdr(v200);
    v200 = qcar(v200);
    if (!(!consp(v200))) goto v205;

v206:
    v200 = stack[-6];
    fn = elt(env, 12); /* simp */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    stack[-1] = v200;
    v200 = stack[-2];
    if (v200 == nil) goto v207;
    v200 = stack[-1];
    v200 = qcar(v200);
    if (v200 == nil) goto v208;
    v200 = stack[-2];
    if (!(!consp(v200))) goto v131;
    v200 = stack[-5];
    v201 = qcdr(v200);
    v200 = (Lisp_Object)17; /* 1 */
    if (!(v201 == v200)) goto v131;
    v200 = stack[-1];
    v200 = qcar(v200);
    if (!consp(v200)) goto v209;
    v200 = stack[-1];
    v200 = qcar(v200);
    v200 = qcar(v200);
    if (!(!consp(v200))) goto v131;

v209:
    v200 = stack[-1];
    v201 = qcdr(v200);
    v200 = (Lisp_Object)17; /* 1 */
    if (!(v201 == v200)) goto v131;
    v200 = stack[-1];
    v200 = qcar(v200);
    if (!(!consp(v200))) goto v210;
    v201 = stack[-2];
    v200 = (Lisp_Object)1; /* 0 */
    v200 = (Lisp_Object)greaterp2(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    v200 = v200 ? lisp_true : nil;
    env = stack[-8];
    if (v200 == nil) goto v210;
    v200 = stack[-1];
    v201 = qcar(v200);
    v200 = stack[-2];
    v200 = Lexpt(nil, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    fn = elt(env, 15); /* !*d2q */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v210:
    v200 = stack[-1];
    v201 = qcar(v200);
    v200 = stack[-2];
    fn = elt(env, 16); /* !:expt */
    v201 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    v200 = (Lisp_Object)17; /* 1 */
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    stack[-1] = v200;
    v200 = qvalue(elt(env, 10)); /* !*mcd */
    if (v200 == nil) goto v84;
    v200 = stack[-1];
    fn = elt(env, 17); /* resimp */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v84:
    v200 = stack[-1];
    goto v51;

v131:
    stack[0] = elt(env, 11); /* expt */
    v201 = stack[-1];
    v200 = stack[-5];
    v200 = list2(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    fn = elt(env, 18); /* domainvalchk */
    v200 = (*qfn2(fn))(qenv(fn), stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    v201 = v200;
    if (v200 == nil) goto v129;
    v200 = v201;
    goto v51;

v129:
    v200 = stack[-2];
    if (!(!consp(v200))) goto v211;
    v200 = stack[-5];
    v201 = qcdr(v200);
    v200 = (Lisp_Object)17; /* 1 */
    if (!(v201 == v200)) goto v211;
    v201 = stack[-2];
    v200 = (Lisp_Object)1; /* 0 */
    v200 = (Lisp_Object)lessp2(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    v200 = v200 ? lisp_true : nil;
    env = stack[-8];
    if (v200 == nil) goto v212;
    v200 = qvalue(elt(env, 10)); /* !*mcd */
    if (v200 == nil) goto v213;
    stack[0] = stack[-1];
    v200 = stack[-2];
    v200 = negate(v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    fn = elt(env, 19); /* exptsq */
    v200 = (*qfn2(fn))(qenv(fn), stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    fn = elt(env, 20); /* invsq */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v213:
    v200 = stack[-1];
    v201 = qcar(v200);
    v200 = stack[-2];
    fn = elt(env, 21); /* expf */
    stack[0] = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    v200 = stack[-1];
    stack[-1] = qcdr(v200);
    v200 = stack[-2];
    v200 = negate(v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    fn = elt(env, 22); /* mksfpf */
    v200 = (*qfn2(fn))(qenv(fn), stack[-1], v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    fn = elt(env, 23); /* multf */
    v201 = (*qfn2(fn))(qenv(fn), stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    v200 = (Lisp_Object)17; /* 1 */
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v212:
    v201 = stack[-1];
    v200 = stack[-2];
    fn = elt(env, 19); /* exptsq */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v211:
    v200 = stack[-4];
    if (v200 == nil) goto v214;
    v200 = stack[-6];
    v202 = v200;
    goto v215;

v215:
    v201 = stack[-5];
    v200 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 24); /* simpexpt11 */
    v200 = (*qfnn(fn))(qenv(fn), 3, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v214:
    v200 = stack[-1];
    fn = elt(env, 25); /* subs2!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    fn = elt(env, 14); /* prepsq!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    v202 = v200;
    goto v215;

v208:
    v200 = stack[-2];
    if (!consp(v200)) goto v216;
    v200 = stack[-2];
    v200 = qcar(v200);
    if (!(!consp(v200))) goto v217;

v216:
    v200 = stack[-2];
    fn = elt(env, 26); /* minusf */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    if (v200 == nil) goto v217;
    v202 = elt(env, 7); /* alg */
    v201 = (Lisp_Object)241; /* 15 */
    v200 = elt(env, 9); /* "Zero divisor" */
    fn = elt(env, 27); /* rerror */
    v200 = (*qfnn(fn))(qenv(fn), 3, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v217:
    v201 = qvalue(elt(env, 6)); /* nil */
    v200 = (Lisp_Object)17; /* 1 */
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v207:
    v200 = stack[-1];
    v200 = qcar(v200);
    if (v200 == nil) goto v218;
    v201 = (Lisp_Object)17; /* 1 */
    v200 = (Lisp_Object)17; /* 1 */
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v218:
    v202 = elt(env, 7); /* alg */
    v201 = (Lisp_Object)225; /* 14 */
    v200 = elt(env, 8); /* "0**0 formed" */
    fn = elt(env, 27); /* rerror */
    v200 = (*qfnn(fn))(qenv(fn), 3, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;

v205:
    v202 = stack[-6];
    v201 = stack[-5];
    v200 = stack[-4];
    fn = elt(env, 24); /* simpexpt11 */
    v200 = (*qfnn(fn))(qenv(fn), 3, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-8];
    goto v51;
/* error exit handlers */
v203:
    env = stack[-8];
    qvalue(elt(env, 2)) = stack[-3]; /* !*div */
    qvalue(elt(env, 1)) = stack[-7]; /* !*allfac */
    popv(9);
    return nil;
}



/* Code for mk!+squared!+norm */

static Lisp_Object CC_mkLsquaredLnorm(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+squared+norm");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v9;
/* end of prologue */
    v15 = v4;
    {
        fn = elt(env, 1); /* mk!+inner!+product */
        return (*qfn2(fn))(qenv(fn), v15, v4);
    }
}



/* Code for ciml */

static Lisp_Object MS_CDECL CC_ciml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ciml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ciml");
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
    v219 = qvalue(elt(env, 2)); /* atts */
    v20 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 5); /* search_att */
    v20 = (*qfn2(fn))(qenv(fn), v219, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    fn = elt(env, 6); /* lex */
    v20 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v20 = qvalue(elt(env, 4)); /* char */
    stack[0] = v20;
    fn = elt(env, 6); /* lex */
    v20 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v20 = stack[0];
    v20 = Lcompress(nil, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    stack[0] = v20;
    v20 = stack[0];
    if (!(is_number(v20))) goto v74;
    v219 = stack[0];
    v20 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 7); /* errorml */
    v20 = (*qfn2(fn))(qenv(fn), v219, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    goto v74;

v74:
    v20 = stack[0];
        popv(2);
        return Lintern(nil, v20);
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for ldf!-simp */

static Lisp_Object CC_ldfKsimp(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-simp");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v44 = v9;
/* end of prologue */
    v43 = v44;
    if (v43 == nil) goto v40;
    v43 = v44;
    v43 = qcdr(v43);
    if (v43 == nil) goto v10;
    v43 = v44;
    fn = elt(env, 2); /* prepf */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    fn = elt(env, 3); /* simp */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v43 = qcar(v43);
    v44 = v43;
    v43 = v44;
    if (!consp(v43)) goto v28;
    v43 = v44;
    v43 = qcar(v43);
    if (!consp(v43)) goto v28;
    stack[0] = v44;
    v43 = v44;
    fn = elt(env, 4); /* comfac */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v43 = qcdr(v43);
    fn = elt(env, 5); /* quotf */
    v43 = (*qfn2(fn))(qenv(fn), stack[0], v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v44 = v43;
    goto v28;

v28:
    v43 = v44;
    {
        popv(2);
        fn = elt(env, 6); /* absf */
        return (*qfn1(fn))(qenv(fn), v43);
    }

v10:
    v43 = v44;
    v43 = qcar(v43);
    v43 = qcar(v43);
    v44 = qcar(v43);
    v43 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* to */
    v44 = (*qfn2(fn))(qenv(fn), v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v43 = (Lisp_Object)17; /* 1 */
    v43 = cons(v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    fn = elt(env, 2); /* prepf */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    fn = elt(env, 3); /* simp */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v43 = qcar(v43);
    { popv(2); return onevalue(v43); }

v40:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for inszzz */

static Lisp_Object CC_inszzz(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inszzz");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v9;
/* end of prologue */
    stack[-3] = nil;
    goto v41;

v41:
    v224 = stack[-1];
    if (v224 == nil) goto v6;
    v224 = stack[-1];
    v224 = qcar(v224);
    v225 = qcar(v224);
    v224 = stack[-2];
    v224 = qcar(v224);
    v224 = (Lisp_Object)lessp2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v224 = v224 ? lisp_true : nil;
    env = stack[-4];
    if (!(v224 == nil)) goto v6;
    v224 = stack[-1];
    v224 = qcar(v224);
    v225 = qcar(v224);
    v224 = stack[-2];
    v224 = qcar(v224);
    if (equal(v225, v224)) goto v81;
    v224 = stack[-1];
    v225 = qcar(v224);
    v224 = stack[-3];
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    stack[-3] = v224;
    v224 = stack[-1];
    v224 = qcdr(v224);
    stack[-1] = v224;
    goto v41;

v81:
    v224 = stack[-1];
    v224 = qcar(v224);
    stack[0] = qcdr(v224);
    v224 = stack[-1];
    v224 = qcar(v224);
    v224 = qcdr(v224);
    v225 = qcar(v224);
    v224 = stack[-2];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    fn = elt(env, 1); /* dm!-plus */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    v224 = Lrplaca(nil, stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    v224 = stack[-1];
    v224 = qcar(v224);
    v224 = qcdr(v224);
    v224 = qcar(v224);
    fn = elt(env, 2); /* zeropp */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    if (v224 == nil) goto v226;
    v225 = stack[-3];
    v224 = stack[-1];
    v224 = qcdr(v224);
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v225, v224);
    }

v226:
    v225 = stack[-3];
    v224 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v225, v224);
    }

v6:
    stack[0] = stack[-3];
    v225 = stack[-2];
    v224 = stack[-1];
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    {
        Lisp_Object v120 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v120, v224);
    }
/* error exit handlers */
v119:
    popv(5);
    return nil;
}



/* Code for suspend */

static Lisp_Object MS_CDECL CC_suspend(Lisp_Object env, int nargs,
                         Lisp_Object v14, Lisp_Object v40,
                         Lisp_Object v24, Lisp_Object v41,
                         Lisp_Object v52, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31, v32, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "suspend");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for suspend");
#endif
    if (stack >= stacklimit)
    {
        push5(v52,v41,v24,v40,v14);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v14,v40,v24,v41,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v52;
    v31 = v41;
    v32 = v24;
    v127 = v40;
    v30 = v14;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-6] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-5] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v30; /* op */
    v30 = v127;
    qvalue(elt(env, 2)) = v30; /* r */
    v30 = v32;
    qvalue(elt(env, 3)) = v30; /* p */
    v30 = qvalue(elt(env, 2)); /* r */
    stack[-4] = qcar(v30);
    v30 = qvalue(elt(env, 3)); /* p */
    stack[-3] = qcar(v30);
    stack[-2] = v31;
    stack[-1] = qvalue(elt(env, 1)); /* op */
    v30 = qvalue(elt(env, 2)); /* r */
    stack[0] = qcdr(v30);
    v31 = qvalue(elt(env, 1)); /* op */
    v30 = qvalue(elt(env, 3)); /* p */
    v30 = qcdr(v30);
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-9];
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-9];
    v31 = acons(stack[-1], stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-9];
    v30 = stack[-7];
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-9];
    fn = elt(env, 4); /* amatch */
    v30 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-3], stack[-2], v30);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; /* p */
    qvalue(elt(env, 2)) = stack[-6]; /* r */
    qvalue(elt(env, 1)) = stack[-8]; /* op */
    { popv(10); return onevalue(v30); }
/* error exit handlers */
v46:
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; /* p */
    qvalue(elt(env, 2)) = stack[-6]; /* r */
    qvalue(elt(env, 1)) = stack[-8]; /* op */
    popv(10);
    return nil;
}



/* Code for critical_element */

static Lisp_Object CC_critical_element(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for critical_element");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v9;
/* end of prologue */
    v15 = v4;
    v15 = qcdr(v15);
    v15 = qcar(v15);
        return Lapply1(nil, v15, v4);
}



/* Code for color!-strand */

static Lisp_Object MS_CDECL CC_colorKstrand(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v128, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color-strand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color-strand");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v9,v2,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v2;
    stack[-2] = v9;
/* end of prologue */
    stack[-3] = nil;
    goto v52;

v52:
    v219 = stack[-1];
    if (v219 == nil) goto v51;
    v128 = stack[-2];
    v219 = stack[-1];
    v219 = qcar(v219);
    fn = elt(env, 1); /* color!-roads */
    v27 = (*qfn2(fn))(qenv(fn), v128, v219);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    v128 = stack[0];
    v219 = stack[-3];
    v219 = acons(v27, v128, v219);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    stack[-3] = v219;
    v219 = stack[-1];
    v219 = qcdr(v219);
    stack[-1] = v219;
    v219 = stack[0];
    v219 = add1(v219);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    stack[0] = v219;
    goto v52;

v51:
    v219 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v219);
    }
/* error exit handlers */
v37:
    popv(5);
    return nil;
}



/* Code for cali!=min */

static Lisp_Object MS_CDECL CC_caliMmin(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v73, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cali=min");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cali=min");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v9,v2,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v2;
    stack[-2] = v9;
/* end of prologue */

v41:
    v72 = stack[-1];
    if (v72 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v38 = stack[-2];
    v72 = stack[-1];
    v73 = qcar(v72);
    v72 = stack[0];
    fn = elt(env, 1); /* listtest */
    v72 = (*qfnn(fn))(qenv(fn), 3, v38, v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    if (!(v72 == nil)) goto v15;
    v72 = stack[-1];
    v38 = qcdr(v72);
    v72 = stack[-1];
    v73 = qcar(v72);
    v72 = stack[0];
    fn = elt(env, 1); /* listtest */
    v72 = (*qfnn(fn))(qenv(fn), 3, v38, v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    if (!(v72 == nil)) goto v15;
    v72 = stack[-1];
    v73 = qcar(v72);
    v72 = stack[-2];
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    stack[-2] = v72;
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v41;

v15:
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v41;
/* error exit handlers */
v127:
    popv(4);
    return nil;
}



/* Code for extadd */

static Lisp_Object CC_extadd(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v2;
    stack[-3] = v9;
/* end of prologue */
    v233 = stack[-3];
    if (v233 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v233 = stack[-2];
    if (v233 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v233 = qvalue(elt(env, 1)); /* nil */
    v233 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[-1] = v233;
    stack[-4] = v233;
    goto v74;

v74:
    v233 = stack[-3];
    if (v233 == nil) goto v235;
    v233 = stack[-2];
    if (v233 == nil) goto v235;
    v233 = stack[-2];
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = stack[-3];
    v233 = qcar(v233);
    v233 = qcar(v233);
    if (equal(v234, v233)) goto v22;
    v233 = stack[-2];
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = stack[-3];
    v233 = qcar(v233);
    v233 = qcar(v233);
    fn = elt(env, 2); /* ordexp */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    if (v233 == nil) goto v236;
    stack[0] = stack[-1];
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v233 = (*qfn2(fn))(qenv(fn), stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v233 = stack[-2];
    v233 = qcdr(v233);
    stack[-2] = v233;
    v233 = stack[-1];
    v233 = qcdr(v233);
    stack[-1] = v233;
    goto v74;

v236:
    stack[0] = stack[-1];
    v233 = stack[-3];
    v233 = qcar(v233);
    v233 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v233 = (*qfn2(fn))(qenv(fn), stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v233 = stack[-3];
    v233 = qcdr(v233);
    stack[-3] = v233;
    v233 = stack[-1];
    v233 = qcdr(v233);
    stack[-1] = v233;
    goto v74;

v22:
    v233 = stack[-3];
    v233 = qcar(v233);
    v234 = qcdr(v233);
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcdr(v233);
    fn = elt(env, 4); /* addf */
    v234 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v233 = v234;
    if (v234 == nil) goto v39;
    stack[0] = stack[-1];
    v234 = stack[-3];
    v234 = qcar(v234);
    v234 = qcar(v234);
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v233 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v233 = (*qfn2(fn))(qenv(fn), stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v233 = stack[-1];
    v233 = qcdr(v233);
    stack[-1] = v233;
    goto v39;

v39:
    v233 = stack[-3];
    v233 = qcdr(v233);
    stack[-3] = v233;
    v233 = stack[-2];
    v233 = qcdr(v233);
    stack[-2] = v233;
    goto v74;

v235:
    v234 = stack[-1];
    v233 = stack[-3];
    if (v233 == nil) goto v115;
    v233 = stack[-3];
    goto v116;

v116:
    fn = elt(env, 3); /* setcdr */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v233 = stack[-4];
    v233 = qcdr(v233);
    { popv(6); return onevalue(v233); }

v115:
    v233 = stack[-2];
    goto v116;
/* error exit handlers */
v195:
    popv(6);
    return nil;
}



/* Code for cl_nnf */

static Lisp_Object CC_cl_nnf(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_nnf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v9;
/* end of prologue */
    v3 = v51;
    v51 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* cl_nnf1 */
        return (*qfn2(fn))(qenv(fn), v3, v51);
    }
}



/* Code for pickbasicset */

static Lisp_Object CC_pickbasicset(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pickbasicset");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v9;
/* end of prologue */
    stack[-3] = nil;
    v198 = qvalue(elt(env, 1)); /* wuvarlist!* */
    stack[-1] = v198;
    goto v33;

v33:
    v198 = stack[-1];
    if (v198 == nil) goto v52;
    v198 = stack[-1];
    v198 = qcar(v198);
    stack[0] = v198;
    goto v0;

v0:
    v198 = stack[-2];
    if (v198 == nil) goto v36;
    v198 = stack[-2];
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcar(v198);
    v220 = qcar(v198);
    v198 = stack[0];
    fn = elt(env, 3); /* symbollessp */
    v198 = (*qfn2(fn))(qenv(fn), v220, v198);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    if (v198 == nil) goto v36;
    v198 = stack[-2];
    v198 = qcdr(v198);
    stack[-2] = v198;
    goto v0;

v36:
    v198 = stack[-2];
    if (v198 == nil) goto v232;
    v220 = stack[0];
    v198 = stack[-2];
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcar(v198);
    if (!(equal(v220, v198))) goto v232;
    v198 = stack[-2];
    v220 = qcar(v198);
    v198 = stack[-3];
    fn = elt(env, 4); /* wureducedpolysp */
    v198 = (*qfn2(fn))(qenv(fn), v220, v198);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    if (!(v198 == nil)) goto v232;
    v198 = stack[-2];
    v198 = qcdr(v198);
    stack[-2] = v198;
    goto v36;

v232:
    v198 = stack[-2];
    if (v198 == nil) goto v240;
    v220 = stack[0];
    v198 = stack[-2];
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcar(v198);
    if (!(equal(v220, v198))) goto v240;
    v198 = stack[-2];
    v220 = qcar(v198);
    v198 = stack[-3];
    v198 = cons(v220, v198);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    stack[-3] = v198;
    v198 = stack[-2];
    v198 = qcdr(v198);
    stack[-2] = v198;
    goto v240;

v240:
    v198 = stack[-1];
    v198 = qcdr(v198);
    stack[-1] = v198;
    goto v33;

v52:
    v198 = stack[-3];
        popv(5);
        return Lnreverse(nil, v198);
/* error exit handlers */
v239:
    popv(5);
    return nil;
}



/* Code for mk!+conjugate!+sq */

static Lisp_Object CC_mkLconjugateLsq(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+conjugate+sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v9;
/* end of prologue */
    {
        fn = elt(env, 1); /* conjsq */
        return (*qfn1(fn))(qenv(fn), v41);
    }
}



/* Code for dvfsf_smupdknowl */

static Lisp_Object MS_CDECL CC_dvfsf_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, Lisp_Object v14, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v128, v27, v150, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_smupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v128 = v14;
    v27 = v21;
    v150 = v2;
    v28 = v9;
/* end of prologue */
    v219 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v219 == nil) goto v29;
    v219 = v28;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v219, v150, v27, v128);
    }

v29:
    v219 = v28;
    {
        fn = elt(env, 3); /* cl_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v219, v150, v27, v128);
    }
}



/* Code for bvarom */

static Lisp_Object CC_bvarom(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bvarom");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v9;
/* end of prologue */
    v13 = stack[0];
    v13 = qcar(v13);
    v13 = Lconsp(nil, v13);
    env = stack[-1];
    if (v13 == nil) goto v24;
    v13 = stack[0];
    v13 = qcar(v13);
    v17 = qcar(v13);
    v13 = elt(env, 1); /* bvar */
    if (!(v17 == v13)) goto v24;
    v13 = stack[0];
    v13 = qcar(v13);
    v13 = qcdr(v13);
    v13 = qcar(v13);
    fn = elt(env, 2); /* objectom */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = CC_bvarom(env, v13);
    nil = C_nil;
    if (exception_pending()) goto v25;
    goto v24;

v24:
    v13 = nil;
    { popv(2); return onevalue(v13); }
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for a2vdp */

static Lisp_Object CC_a2vdp(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v55, v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for a2vdp");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v241 = v9;
/* end of prologue */
    v55 = v241;
    v46 = (Lisp_Object)1; /* 0 */
    if (v55 == v46) goto v58;
    v46 = v241;
    if (v46 == nil) goto v58;
    v46 = v241;
    fn = elt(env, 3); /* a2dip */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-3];
    v55 = v46;
    stack[-2] = elt(env, 1); /* vdp */
    v46 = v55;
    stack[-1] = qcar(v46);
    v46 = v55;
    v46 = qcdr(v46);
    stack[0] = qcar(v46);
    v46 = qvalue(elt(env, 2)); /* nil */
    v46 = list2(v55, v46);
    nil = C_nil;
    if (exception_pending()) goto v240;
    {
        Lisp_Object v67 = stack[-2];
        Lisp_Object v60 = stack[-1];
        Lisp_Object v61 = stack[0];
        popv(4);
        return list3star(v67, v60, v61, v46);
    }

v58:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v55 = qvalue(elt(env, 2)); /* nil */
    v46 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v55, v46);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-3];
    v55 = qvalue(elt(env, 2)); /* nil */
    v46 = qvalue(elt(env, 2)); /* nil */
    v46 = list2(v55, v46);
    nil = C_nil;
    if (exception_pending()) goto v240;
    {
        Lisp_Object v242 = stack[-2];
        Lisp_Object v145 = stack[-1];
        Lisp_Object v63 = stack[0];
        popv(4);
        return list3star(v242, v145, v63, v46);
    }
/* error exit handlers */
v240:
    popv(4);
    return nil;
}



/* Code for equiv!-coeffs */

static Lisp_Object CC_equivKcoeffs(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equiv-coeffs");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v9;
/* end of prologue */
    stack[-2] = nil;
    goto v41;

v41:
    v61 = stack[-1];
    if (v61 == nil) goto v15;
    v61 = stack[0];
    if (v61 == nil) goto v10;
    v61 = stack[-1];
    v61 = qcar(v61);
    v242 = qcar(v61);
    v61 = stack[0];
    v61 = qcar(v61);
    v61 = qcar(v61);
    if (equal(v242, v61)) goto v128;
    v61 = stack[-1];
    v61 = qcar(v61);
    v242 = qcar(v61);
    v61 = stack[0];
    v61 = qcar(v61);
    v61 = qcar(v61);
    fn = elt(env, 1); /* mv!-pow!-!> */
    v61 = (*qfn2(fn))(qenv(fn), v242, v61);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    if (v61 == nil) goto v46;
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    goto v41;

v46:
    v242 = (Lisp_Object)1; /* 0 */
    v61 = stack[-2];
    v61 = cons(v242, v61);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    stack[-2] = v61;
    v61 = stack[0];
    v61 = qcdr(v61);
    stack[0] = v61;
    goto v41;

v128:
    v61 = stack[-1];
    v61 = qcar(v61);
    v242 = qcdr(v61);
    v61 = stack[-2];
    v61 = cons(v242, v61);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    stack[-2] = v61;
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    v61 = stack[0];
    v61 = qcdr(v61);
    stack[0] = v61;
    goto v41;

v10:
    v61 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v61);
    }

v15:
    stack[-1] = stack[-2];
    v61 = stack[0];
    v61 = Llength(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    fn = elt(env, 3); /* nzeros */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    {
        Lisp_Object v68 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v68, v61);
    }
/* error exit handlers */
v71:
    popv(4);
    return nil;
}



/* Code for cl_pnf */

static Lisp_Object CC_cl_pnf(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pnf");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v24 = v9;
/* end of prologue */
    fn = elt(env, 1); /* rl_nnf */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* cl_pnf1 */
        return (*qfn1(fn))(qenv(fn), v24);
    }
/* error exit handlers */
v41:
    popv(1);
    return nil;
}



/* Code for dip_moncomp */

static Lisp_Object MS_CDECL CC_dip_moncomp(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v59, v58;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip_moncomp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_moncomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v21;
    v59 = v2;
    v58 = v9;
/* end of prologue */
    return list2star(v59, v58, v16);
}



/* Code for omattrir */

static Lisp_Object MS_CDECL CC_omattrir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omattrir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omattrir");
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
    fn = elt(env, 6); /* lex */
    v223 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    fn = elt(env, 7); /* omatpir */
    v223 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    stack[-1] = v223;
    fn = elt(env, 6); /* lex */
    v223 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    fn = elt(env, 8); /* omobj */
    v223 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    stack[0] = v223;
    fn = elt(env, 6); /* lex */
    v223 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    v223 = elt(env, 1); /* (!/ o m a t t r) */
    fn = elt(env, 9); /* checktag */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    v223 = stack[-1];
    v223 = Lconsp(nil, v223);
    env = stack[-2];
    if (v223 == nil) goto v15;
    v223 = stack[-1];
    v223 = qcar(v223);
    v223 = qcdr(v223);
    v56 = qcar(v223);
    v223 = elt(env, 2); /* csymbol */
    if (!(v56 == v223)) goto v15;
    v56 = stack[0];
    v223 = qvalue(elt(env, 3)); /* nil */
    v57 = qvalue(elt(env, 3)); /* nil */
    popv(3);
    return list2star(v56, v223, v57);

v15:
    v223 = stack[0];
    if (is_number(v223)) goto v147;
    v57 = elt(env, 5); /* ci */
    v56 = stack[-1];
    v223 = stack[0];
    popv(3);
    return list3(v57, v56, v223);

v147:
    v57 = elt(env, 4); /* cn */
    v56 = stack[-1];
    v223 = stack[0];
    popv(3);
    return list3(v57, v56, v223);
/* error exit handlers */
v241:
    popv(3);
    return nil;
}



/* Code for extbrsea */

static Lisp_Object MS_CDECL CC_extbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v263, v264, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "extbrsea");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extbrsea");
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
    v263 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v263;
    goto v16;

v16:
    v264 = qvalue(elt(env, 2)); /* rowmax */
    v263 = stack[-1];
    v263 = difference2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v263 = Lminusp(nil, v263);
    env = stack[-2];
    if (v263 == nil) goto v19;
    fn = elt(env, 8); /* initbrsea */
    v263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    goto v267;

v267:
    fn = elt(env, 10); /* expandprod */
    v263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v263 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v263;
    goto v113;

v113:
    v264 = qvalue(elt(env, 2)); /* rowmax */
    v263 = stack[-1];
    v263 = difference2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v263 = Lminusp(nil, v263);
    env = stack[-2];
    if (v263 == nil) goto v268;
    fn = elt(env, 8); /* initbrsea */
    v263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    fn = elt(env, 11); /* shrinkprod */
    v263 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    if (!(v263 == nil)) goto v267;
    v263 = nil;
    { popv(3); return onevalue(v263); }

v268:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v264 = qvalue(elt(env, 5)); /* maxvar */
    v263 = stack[-1];
    v263 = plus2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v264 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v263 = (Lisp_Object)49; /* 3 */
    v264 = *(Lisp_Object *)((char *)v264 + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v263 = (Lisp_Object)-15; /* -1 */
    if (v264 == v263) goto v269;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v264 = qvalue(elt(env, 5)); /* maxvar */
    v263 = stack[-1];
    v263 = plus2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v264 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v263 = (Lisp_Object)33; /* 2 */
    v264 = *(Lisp_Object *)((char *)v264 + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v263 = elt(env, 7); /* times */
    if (!(v264 == v263)) goto v269;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v264 = qvalue(elt(env, 5)); /* maxvar */
    v263 = stack[-1];
    v263 = plus2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v265 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v264 = (Lisp_Object)1; /* 0 */
    v263 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v265 + (CELL-TAG_VECTOR) + ((int32_t)v264/(16/CELL))) = v263;
    goto v270;

v270:
    v263 = stack[-1];
    v263 = add1(v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    stack[-1] = v263;
    goto v113;

v269:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v264 = qvalue(elt(env, 5)); /* maxvar */
    v263 = stack[-1];
    v263 = plus2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v265 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v264 = (Lisp_Object)1; /* 0 */
    v263 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v265 + (CELL-TAG_VECTOR) + ((int32_t)v264/(16/CELL))) = v263;
    goto v270;

v19:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v264 = qvalue(elt(env, 5)); /* maxvar */
    v263 = stack[-1];
    v263 = plus2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v264 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v263 = (Lisp_Object)49; /* 3 */
    v264 = *(Lisp_Object *)((char *)v264 + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v263 = (Lisp_Object)-15; /* -1 */
    if (v264 == v263) goto v271;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v264 = qvalue(elt(env, 5)); /* maxvar */
    v263 = stack[-1];
    v263 = plus2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v264 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v263 = (Lisp_Object)49; /* 3 */
    v264 = *(Lisp_Object *)((char *)v264 + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v263 = (Lisp_Object)-31; /* -2 */
    if (v264 == v263) goto v271;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v264 = qvalue(elt(env, 5)); /* maxvar */
    v263 = stack[-1];
    v263 = plus2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v265 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v264 = (Lisp_Object)1; /* 0 */
    v263 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v265 + (CELL-TAG_VECTOR) + ((int32_t)v264/(16/CELL))) = v263;
    goto v74;

v74:
    v263 = stack[-1];
    v263 = add1(v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    stack[-1] = v263;
    goto v16;

v271:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v264 = qvalue(elt(env, 5)); /* maxvar */
    v263 = stack[-1];
    v263 = plus2(v264, v263);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v265 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v263/(16/CELL)));
    v264 = (Lisp_Object)1; /* 0 */
    v263 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v265 + (CELL-TAG_VECTOR) + ((int32_t)v264/(16/CELL))) = v263;
    goto v74;
/* error exit handlers */
v266:
    popv(3);
    return nil;
}



/* Code for fnreval */

static Lisp_Object MS_CDECL CC_fnreval(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v273, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fnreval");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnreval");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v9,v2,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v21;
    stack[-1] = v2;
    stack[0] = v9;
/* end of prologue */
    stack[-2] = nil;
    goto v52;

v52:
    v273 = stack[0];
    if (v273 == nil) goto v51;
    v118 = stack[-1];
    v273 = qvalue(elt(env, 1)); /* t */
    if (v118 == v273) goto v5;
    v273 = stack[-1];
    if (v273 == nil) goto v26;
    v273 = stack[-1];
    v273 = qcar(v273);
    if (v273 == nil) goto v224;
    v273 = stack[0];
    v273 = qcar(v273);
    v118 = v273;
    goto v142;

v142:
    v273 = stack[-2];
    v273 = cons(v118, v273);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-6];
    stack[-2] = v273;
    v273 = stack[0];
    v273 = qcdr(v273);
    stack[0] = v273;
    v273 = stack[-1];
    v273 = qcdr(v273);
    stack[-1] = v273;
    goto v52;

v224:
    v273 = stack[0];
    v118 = qcar(v273);
    v273 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v273 = (*qfn2(fn))(qenv(fn), v118, v273);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-6];
    v118 = v273;
    goto v142;

v26:
    stack[-5] = stack[-2];
    v273 = stack[0];
    stack[-3] = v273;
    v273 = stack[-3];
    if (v273 == nil) goto v65;
    v273 = stack[-3];
    v273 = qcar(v273);
    v118 = v273;
    v273 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v273 = (*qfn2(fn))(qenv(fn), v118, v273);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-6];
    v273 = ncons(v273);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-6];
    stack[-1] = v273;
    stack[-2] = v273;
    goto v37;

v37:
    v273 = stack[-3];
    v273 = qcdr(v273);
    stack[-3] = v273;
    v273 = stack[-3];
    if (v273 == nil) goto v56;
    stack[0] = stack[-1];
    v273 = stack[-3];
    v273 = qcar(v273);
    v118 = v273;
    v273 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v273 = (*qfn2(fn))(qenv(fn), v118, v273);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-6];
    v273 = ncons(v273);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-6];
    v273 = Lrplacd(nil, stack[0], v273);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-6];
    v273 = stack[-1];
    v273 = qcdr(v273);
    stack[-1] = v273;
    goto v37;

v56:
    v273 = stack[-2];
    goto v20;

v20:
    {
        Lisp_Object v116 = stack[-5];
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v116, v273);
    }

v65:
    v273 = qvalue(elt(env, 2)); /* nil */
    goto v20;

v5:
    v118 = stack[-2];
    v273 = stack[0];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v118, v273);
    }

v51:
    v273 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v273);
    }
/* error exit handlers */
v274:
    popv(7);
    return nil;
}



/* Code for tp1 */

static Lisp_Object CC_tp1(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v243, v223;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tp1");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v9;
/* end of prologue */
    v243 = qvalue(elt(env, 1)); /* nil */
    v243 = ncons(v243);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    stack[-3] = v243;
    stack[-5] = v243;
    goto v15;

v15:
    v243 = stack[-4];
    v243 = qcar(v243);
    if (v243 == nil) goto v4;
    v243 = stack[-4];
    stack[-2] = v243;
    v243 = qvalue(elt(env, 1)); /* nil */
    v243 = ncons(v243);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    stack[0] = v243;
    stack[-1] = v243;
    goto v6;

v6:
    v243 = stack[-2];
    if (v243 == nil) goto v72;
    v243 = stack[-2];
    v243 = qcar(v243);
    v243 = qcar(v243);
    v243 = ncons(v243);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v243 = Lrplacd(nil, stack[0], v243);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v243 = qcdr(v243);
    stack[0] = v243;
    v223 = stack[-2];
    v243 = stack[-2];
    v243 = qcar(v243);
    v243 = qcdr(v243);
    v243 = Lrplaca(nil, v223, v243);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v243 = qcdr(v243);
    stack[-2] = v243;
    goto v6;

v72:
    stack[0] = stack[-3];
    v243 = stack[-1];
    v243 = qcdr(v243);
    v243 = ncons(v243);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v243 = Lrplacd(nil, stack[0], v243);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v243 = qcdr(v243);
    stack[-3] = v243;
    goto v15;

v4:
    v243 = stack[-5];
    v243 = qcdr(v243);
    { popv(7); return onevalue(v243); }
/* error exit handlers */
v149:
    popv(7);
    return nil;
}



/* Code for bcminus!? */

static Lisp_Object CC_bcminusW(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcminus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v141 = v9;
/* end of prologue */
    v15 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v15 == nil) goto v33;
    v15 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v15);

v33:
    v15 = v141;
    v15 = qcar(v15);
    {
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v15);
    }
}



/* Code for xreadlist */

static Lisp_Object MS_CDECL CC_xreadlist(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "xreadlist");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xreadlist");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    fn = elt(env, 10); /* scan */
    v69 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v239 = elt(env, 1); /* !*rcbkt!* */
    if (!(v69 == v239)) goto v52;
    fn = elt(env, 10); /* scan */
    v239 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v239 = elt(env, 2); /* list */
    popv(5);
    return ncons(v239);

v52:
    v239 = stack[-1];
    if (v239 == nil) goto v7;
    v239 = elt(env, 3); /* group */
    fn = elt(env, 11); /* xread1 */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v239 = ncons(v239);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    fn = elt(env, 12); /* nconc2 */
    v239 = (*qfn2(fn))(qenv(fn), stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[0] = v239;
    goto v11;

v11:
    v239 = qvalue(elt(env, 4)); /* cursym!* */
    stack[-3] = v239;
    v69 = stack[-3];
    v239 = elt(env, 5); /* !*semicol!* */
    if (v69 == v239) goto v31;
    fn = elt(env, 10); /* scan */
    v69 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v239 = elt(env, 1); /* !*rcbkt!* */
    if (!(v69 == v239)) goto v126;
    v69 = stack[-3];
    v239 = elt(env, 8); /* !*comma!* */
    if (!(v69 == v239)) goto v126;
    v69 = elt(env, 9); /* "Syntax error: invalid comma in list" */
    v239 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 13); /* symerr */
    v239 = (*qfn2(fn))(qenv(fn), v69, v239);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    goto v126;

v126:
    v69 = stack[-3];
    v239 = elt(env, 1); /* !*rcbkt!* */
    if (v69 == v239) goto v124;
    v239 = stack[-2];
    if (!(v239 == nil)) goto v52;
    v239 = stack[-3];
    stack[-2] = v239;
    goto v52;

v124:
    v69 = elt(env, 2); /* list */
    v239 = stack[-1];
    popv(5);
    return cons(v69, v239);

v31:
    v69 = elt(env, 6); /* "Syntax error: semicolon in list" */
    v239 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 13); /* symerr */
    v239 = (*qfn2(fn))(qenv(fn), v69, v239);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    goto v126;

v7:
    stack[0] = stack[-1];
    v239 = elt(env, 3); /* group */
    fn = elt(env, 11); /* xread1 */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    fn = elt(env, 14); /* aconc */
    v239 = (*qfn2(fn))(qenv(fn), stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[0] = v239;
    stack[-1] = v239;
    goto v11;
/* error exit handlers */
v260:
    popv(5);
    return nil;
}



/* Code for nspaces */

static Lisp_Object CC_nspaces(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v128, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nspaces");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v9;
/* end of prologue */
    stack[-2] = nil;
    v219 = (Lisp_Object)17; /* 1 */
    stack[0] = v219;
    goto v59;

v59:
    v128 = stack[-1];
    v219 = stack[0];
    v219 = difference2(v128, v219);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v219 = Lminusp(nil, v219);
    env = stack[-3];
    if (v219 == nil) goto v5;
    v219 = stack[-2];
    v219 = Lcompress(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v36;
        popv(4);
        return Lintern(nil, v219);

v5:
    v27 = elt(env, 2); /* !! */
    v128 = elt(env, 3); /* !  */
    v219 = stack[-2];
    v219 = list2star(v27, v128, v219);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[-2] = v219;
    v219 = stack[0];
    v219 = add1(v219);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[0] = v219;
    goto v59;
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for deletez1 */

static Lisp_Object CC_deletez1(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v147, v39, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deletez1");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v9;
/* end of prologue */
    v65 = nil;
    goto v41;

v41:
    v146 = stack[-1];
    if (v146 == nil) goto v47;
    v39 = (Lisp_Object)1; /* 0 */
    v146 = stack[-1];
    v146 = qcar(v146);
    v147 = qcar(v146);
    v146 = stack[0];
    v146 = Lassoc(nil, v147, v146);
    v146 = qcdr(v146);
    if (v39 == v146) goto v141;
    v146 = stack[-1];
    v146 = qcar(v146);
    v147 = v65;
    v146 = cons(v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v65 = v146;
    v146 = stack[-1];
    v146 = qcdr(v146);
    stack[-1] = v146;
    goto v41;

v141:
    v146 = stack[-1];
    v146 = qcdr(v146);
    stack[-1] = v146;
    goto v41;

v47:
    v146 = v65;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v146);
    }
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for pa_list2vect */

static Lisp_Object CC_pa_list2vect(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v277, v278;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_list2vect");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v2;
    stack[0] = v9;
/* end of prologue */
    stack[-4] = nil;
    v277 = (Lisp_Object)1; /* 0 */
    stack[-3] = v277;
    v277 = stack[-5];
    v277 = sub1(v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    v277 = Lmkvect(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    stack[-6] = v277;
    v277 = stack[0];
    stack[-2] = v277;
    goto v16;

v16:
    v277 = stack[-2];
    if (v277 == nil) goto v141;
    v277 = stack[-2];
    v277 = qcar(v277);
    stack[0] = v277;
    v278 = elt(env, 2); /* min */
    v277 = stack[0];
    v277 = cons(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    fn = elt(env, 3); /* eval */
    v278 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    v277 = stack[-4];
    v277 = cons(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    stack[-4] = v277;
    v277 = stack[0];
    stack[-1] = v277;
    goto v232;

v232:
    v277 = stack[-1];
    if (v277 == nil) goto v28;
    v277 = stack[-1];
    v277 = qcar(v277);
    stack[0] = stack[-6];
    v278 = sub1(v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    v277 = stack[-4];
    v277 = qcar(v277);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v278/(16/CELL))) = v277;
    v277 = stack[-1];
    v277 = qcdr(v277);
    stack[-1] = v277;
    goto v232;

v28:
    v277 = stack[-2];
    v277 = qcdr(v277);
    stack[-2] = v277;
    goto v16;

v141:
    v277 = (Lisp_Object)17; /* 1 */
    stack[-1] = v277;
    goto v145;

v145:
    v278 = stack[-5];
    v277 = stack[-1];
    v277 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    v277 = Lminusp(nil, v277);
    env = stack[-7];
    if (v277 == nil) goto v280;
    v277 = stack[-4];
    v278 = Lreverse(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    v277 = stack[-6];
    popv(8);
    return cons(v278, v277);

v280:
    stack[0] = stack[-6];
    v277 = stack[-1];
    v277 = sub1(v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    v277 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v277/(16/CELL)));
    if (!(v277 == nil)) goto v272;
    v278 = stack[-3];
    v277 = (Lisp_Object)1; /* 0 */
    if (!(v278 == v277)) goto v228;
    v277 = stack[-1];
    stack[-3] = v277;
    v278 = stack[-3];
    v277 = stack[-4];
    v277 = cons(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    stack[-4] = v277;
    goto v228;

v228:
    stack[0] = stack[-6];
    v277 = stack[-1];
    v278 = sub1(v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    v277 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v278/(16/CELL))) = v277;
    goto v272;

v272:
    v277 = stack[-1];
    v277 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-7];
    stack[-1] = v277;
    goto v145;
/* error exit handlers */
v279:
    popv(8);
    return nil;
}



/* Code for solvealgdepends */

static Lisp_Object CC_solvealgdepends(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgdepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v9;
/* end of prologue */

v3:
    v63 = stack[-1];
    v145 = stack[0];
    if (equal(v63, v145)) goto v47;
    v145 = stack[-1];
    if (!consp(v145)) goto v48;
    v63 = stack[-1];
    v145 = elt(env, 3); /* root_of */
    if (!consp(v63)) goto v30;
    v63 = qcar(v63);
    if (!(v63 == v145)) goto v30;
    v63 = stack[0];
    v145 = stack[-1];
    v145 = qcdr(v145);
    v145 = qcdr(v145);
    v145 = qcar(v145);
    if (equal(v63, v145)) goto v25;
    v145 = stack[-1];
    v145 = qcdr(v145);
    v145 = qcar(v145);
    stack[-1] = v145;
    goto v3;

v25:
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v145); }

v30:
    v145 = stack[-1];
    v63 = qcar(v145);
    v145 = stack[0];
    v145 = CC_solvealgdepends(env, v63, v145);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v63 = v145;
    if (!(v145 == nil)) { popv(3); return onevalue(v63); }
    v145 = stack[-1];
    v63 = qcdr(v145);
    v145 = stack[0];
    v145 = CC_solvealgdepends(env, v63, v145);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v63 = v145;
    if (!(v145 == nil)) { popv(3); return onevalue(v63); }
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v145); }

v48:
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v145); }

v47:
    v145 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v145); }
/* error exit handlers */
v68:
    popv(3);
    return nil;
}



/* Code for get!-height */

static Lisp_Object CC_getKheight(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-height");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
/* end of prologue */
    v7 = stack[0];
    if (v7 == nil) goto v40;
    v7 = stack[0];
    if (is_number(v7)) goto v33;
    v7 = stack[0];
    v7 = qcar(v7);
    v7 = qcdr(v7);
    stack[-1] = CC_getKheight(env, v7);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v7 = stack[0];
    v7 = qcdr(v7);
    v7 = CC_getKheight(env, v7);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    {
        Lisp_Object v13 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* max */
        return (*qfn2(fn))(qenv(fn), v13, v7);
    }

v33:
    v7 = stack[0];
        popv(3);
        return Labsval(nil, v7);

v40:
    v7 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v7); }
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



/* Code for sfto_pdecf */

static Lisp_Object CC_sfto_pdecf(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_pdecf");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
/* end of prologue */
    v127 = stack[0];
    if (!consp(v127)) goto v58;
    v127 = stack[0];
    v127 = qcar(v127);
    if (!consp(v127)) goto v58;
    v127 = stack[0];
    fn = elt(env, 1); /* sfto_ucontentf */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-1] = v127;
    v127 = stack[-1];
    v127 = CC_sfto_pdecf(env, v127);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-2] = v127;
    v43 = stack[0];
    v127 = stack[-1];
    fn = elt(env, 2); /* quotf */
    v127 = (*qfn2(fn))(qenv(fn), v43, v127);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    fn = elt(env, 3); /* sfto_updecf */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-1] = v127;
    v127 = stack[-2];
    v43 = qcar(v127);
    v127 = stack[-1];
    v127 = qcar(v127);
    fn = elt(env, 4); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v43, v127);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    v127 = stack[-2];
    v43 = qcdr(v127);
    v127 = stack[-1];
    v127 = qcdr(v127);
    fn = elt(env, 4); /* multf */
    v127 = (*qfn2(fn))(qenv(fn), v43, v127);
    nil = C_nil;
    if (exception_pending()) goto v35;
    {
        Lisp_Object v243 = stack[0];
        popv(4);
        return cons(v243, v127);
    }

v58:
    v43 = (Lisp_Object)17; /* 1 */
    v127 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v43, v127);
/* error exit handlers */
v35:
    popv(4);
    return nil;
}



/* Code for evalnumberp */

static Lisp_Object CC_evalnumberp(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalnumberp");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v39 = v9;
/* end of prologue */
    fn = elt(env, 4); /* aeval */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    v66 = v39;
    v39 = v66;
    if (!consp(v39)) goto v52;
    v39 = v66;
    v65 = qcar(v39);
    v39 = elt(env, 1); /* !*sq */
    if (!(v65 == v39)) goto v4;
    v39 = v66;
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v39 = qcdr(v39);
    if (!(!consp(v39))) goto v4;
    v39 = v66;
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v39 = qcar(v39);
    v65 = v39;
    v39 = v65;
    v39 = (consp(v39) ? nil : lisp_true);
    if (!(v39 == nil)) { popv(1); return onevalue(v39); }
    v39 = v65;
    v39 = qcar(v39);
    v65 = elt(env, 3); /* numbertag */
        popv(1);
        return Lflagp(nil, v39, v65);

v4:
    v39 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v39); }

v52:
    v39 = v66;
    v39 = (is_number(v39) ? lisp_true : nil);
    { popv(1); return onevalue(v39); }
/* error exit handlers */
v81:
    popv(1);
    return nil;
}



/* Code for intervalom */

static Lisp_Object CC_intervalom(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v271, v272, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalom");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v9;
/* end of prologue */
    v271 = stack[-2];
    v271 = qcdr(v271);
    v271 = qcar(v271);
    stack[-3] = v271;
    v271 = stack[-2];
    v271 = qcar(v271);
    stack[-1] = v271;
    v272 = stack[-1];
    v271 = elt(env, 1); /* lowupperlimit */
    if (!(v272 == v271)) goto v20;
    v271 = elt(env, 2); /* integer_interval */
    stack[-1] = v271;
    v271 = qvalue(elt(env, 3)); /* nil */
    stack[-3] = v271;
    v271 = stack[-2];
    v77 = qcar(v271);
    v272 = qvalue(elt(env, 3)); /* nil */
    v271 = stack[-2];
    v271 = qcdr(v271);
    v271 = list2star(v77, v272, v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    stack[-2] = v271;
    goto v20;

v20:
    v272 = stack[-1];
    v271 = qvalue(elt(env, 4)); /* valid_om!* */
    v271 = Lassoc(nil, v272, v271);
    v271 = qcdr(v271);
    v271 = qcar(v271);
    stack[0] = v271;
    v271 = stack[-3];
    if (v271 == nil) goto v39;
    v271 = stack[-3];
    v271 = qcar(v271);
    v271 = qcdr(v271);
    v271 = qcar(v271);
    v272 = Lintern(nil, v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = qvalue(elt(env, 5)); /* interval!* */
    v271 = Lassoc(nil, v272, v271);
    v271 = qcdr(v271);
    v271 = qcar(v271);
    stack[-1] = v271;
    goto v39;

v39:
    v271 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* indent!* */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = stack[0];
    v271 = Lprinc(nil, v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = elt(env, 9); /* """ name=""" */
    v271 = Lprinc(nil, v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = stack[-1];
    v271 = Lprinc(nil, v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = elt(env, 10); /* """/>" */
    v271 = Lprinc(nil, v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = stack[-2];
    v271 = qcdr(v271);
    v271 = qcdr(v271);
    fn = elt(env, 14); /* multiom */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v271 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v231;
    v271 = nil;
    { popv(5); return onevalue(v271); }
/* error exit handlers */
v231:
    popv(5);
    return nil;
}



/* Code for simpunion */

static Lisp_Object CC_simpunion(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v275, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpunion");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v241 = v9;
/* end of prologue */
    v275 = elt(env, 1); /* union */
    fn = elt(env, 3); /* applysetop */
    v241 = (*qfn2(fn))(qenv(fn), v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-1];
    v149 = v241;
    v241 = v149;
    v275 = qcar(v241);
    v241 = elt(env, 1); /* union */
    if (v275 == v241) goto v37;
    v241 = v149;
    v275 = v241;
    goto v29;

v29:
    v241 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* mksp */
    v275 = (*qfn2(fn))(qenv(fn), v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-1];
    v241 = (Lisp_Object)17; /* 1 */
    v241 = cons(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-1];
    v275 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v240;
    v241 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v275, v241);

v37:
    v241 = qvalue(elt(env, 2)); /* empty_set */
    v275 = v149;
    v275 = qcdr(v275);
    v241 = Ldelete(nil, v241, v275);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-1];
    v149 = v241;
    v241 = qcdr(v241);
    if (v241 == nil) goto v44;
    stack[0] = elt(env, 1); /* union */
    v241 = v149;
    fn = elt(env, 5); /* ordn */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-1];
    v241 = cons(stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-1];
    goto v150;

v150:
    v275 = v241;
    goto v29;

v44:
    v241 = v149;
    v241 = qcar(v241);
    goto v150;
/* error exit handlers */
v240:
    popv(2);
    return nil;
}



/* Code for get!:const */

static Lisp_Object CC_getTconst(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v275, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get:const");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v9;
/* end of prologue */
    v275 = stack[-1];
    if (!(!consp(v275))) goto v57;
    v275 = stack[0];
    v275 = integerp(v275);
    if (v275 == nil) goto v57;
    v149 = stack[0];
    v275 = (Lisp_Object)1; /* 0 */
    v275 = (Lisp_Object)greaterp2(v149, v275);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v275 = v275 ? lisp_true : nil;
    env = stack[-2];
    if (v275 == nil) goto v57;
    v149 = stack[-1];
    v275 = elt(env, 1); /* save!:c */
    v275 = get(v149, v275);
    env = stack[-2];
    stack[-1] = v275;
    v275 = stack[-1];
    if (v275 == nil) goto v18;
    v275 = stack[-1];
    v149 = qcar(v275);
    v275 = stack[0];
    v275 = (Lisp_Object)lessp2(v149, v275);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v275 = v275 ? lisp_true : nil;
    env = stack[-2];
    if (!(v275 == nil)) goto v18;
    v275 = stack[-1];
    v149 = qcar(v275);
    v275 = stack[0];
    if (equal(v149, v275)) goto v147;
    v275 = stack[-1];
    v149 = qcdr(v275);
    v275 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v149, v275);
    }

v147:
    v275 = stack[-1];
    v275 = qcdr(v275);
    { popv(3); return onevalue(v275); }

v18:
    v275 = elt(env, 2); /* not_found */
    { popv(3); return onevalue(v275); }

v57:
    v275 = elt(env, 0); /* get!:const */
    {
        popv(3);
        fn = elt(env, 4); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v275);
    }
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for toolongexpp */

static Lisp_Object CC_toolongexpp(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toolongexpp");
#endif
    if (stack >= stacklimit)
    {
        push(v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v3 = v9;
/* end of prologue */
    fn = elt(env, 2); /* numprintlen */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[0];
    v4 = qvalue(elt(env, 1)); /* maxexpprintlen!* */
        popv(1);
        return Lgreaterp(nil, v3, v4);
/* error exit handlers */
v15:
    popv(1);
    return nil;
}



/* Code for find_bubles_coeff */

static Lisp_Object MS_CDECL CC_find_bubles_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v9, Lisp_Object v2,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v48, v1, v0;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_bubles_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles_coeff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v62 = v21;
    v48 = v2;
    v1 = v9;
/* end of prologue */
    v0 = v1;
    v1 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* find_bubles1_coeff */
        return (*qfnn(fn))(qenv(fn), 4, v0, v1, v48, v62);
    }
}



/* Code for fs!:minusp */

static Lisp_Object CC_fsTminusp(Lisp_Object env,
                         Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v27, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v9;
/* end of prologue */

v40:
    v128 = v27;
    if (v128 == nil) goto v52;
    v150 = v27;
    v128 = (Lisp_Object)49; /* 3 */
    v128 = *(Lisp_Object *)((char *)v150 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    if (v128 == nil) goto v74;
    v128 = (Lisp_Object)49; /* 3 */
    v128 = *(Lisp_Object *)((char *)v27 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    v27 = v128;
    goto v40;

v74:
    v128 = (Lisp_Object)1; /* 0 */
    v128 = *(Lisp_Object *)((char *)v27 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    v128 = qcar(v128);
    {
        fn = elt(env, 2); /* minusf */
        return (*qfn1(fn))(qenv(fn), v128);
    }

v52:
    v128 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v128);
}



/* Code for ratdif */

static Lisp_Object CC_ratdif(Lisp_Object env,
                         Lisp_Object v9, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratdif");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v9,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v16 = v2;
    v59 = v9;
/* end of prologue */
    stack[0] = v59;
    fn = elt(env, 2); /* ratminus */
    v59 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v16 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v48 = stack[0];
        popv(2);
        fn = elt(env, 3); /* ratplusm */
        return (*qfnn(fn))(qenv(fn), 3, v48, v59, v16);
    }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



setup_type const u27_setup[] =
{
    {"setrd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrd},
    {"multerm",                 too_few_2,      CC_multerm,    wrong_no_2},
    {"evinsert",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evinsert},
    {"list-evaluate",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_listKevaluate},
    {"indxsymp",                too_few_2,      CC_indxsymp,   wrong_no_2},
    {"reval3",                  CC_reval3,      too_many_1,    wrong_no_1},
    {"harmonicp",               CC_harmonicp,   too_many_1,    wrong_no_1},
    {"clean_numid",             CC_clean_numid, too_many_1,    wrong_no_1},
    {"fd2q",                    CC_fd2q,        too_many_1,    wrong_no_1},
    {"sq2sspl",                 too_few_2,      CC_sq2sspl,    wrong_no_2},
    {"maxfrom1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_maxfrom1},
    {"mk+resimp+mat",           CC_mkLresimpLmat,too_many_1,   wrong_no_1},
    {"vdp_plist",               CC_vdp_plist,   too_many_1,    wrong_no_1},
    {"setfuncsnaryrd",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_setfuncsnaryrd},
    {"init",                    CC_init,        too_many_1,    wrong_no_1},
    {"gftimes",                 too_few_2,      CC_gftimes,    wrong_no_2},
    {"skp_ordp",                too_few_2,      CC_skp_ordp,   wrong_no_2},
    {"msolve-psys1",            too_few_2,      CC_msolveKpsys1,wrong_no_2},
    {"orddf",                   too_few_2,      CC_orddf,      wrong_no_2},
    {"simpexpt1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt1},
    {"mk+squared+norm",         CC_mkLsquaredLnorm,too_many_1, wrong_no_1},
    {"ciml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_ciml},
    {"ldf-simp",                CC_ldfKsimp,    too_many_1,    wrong_no_1},
    {"inszzz",                  too_few_2,      CC_inszzz,     wrong_no_2},
    {"suspend",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_suspend},
    {"critical_element",        CC_critical_element,too_many_1,wrong_no_1},
    {"color-strand",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_colorKstrand},
    {"cali=min",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_caliMmin},
    {"extadd",                  too_few_2,      CC_extadd,     wrong_no_2},
    {"cl_nnf",                  CC_cl_nnf,      too_many_1,    wrong_no_1},
    {"pickbasicset",            CC_pickbasicset,too_many_1,    wrong_no_1},
    {"mk+conjugate+sq",         CC_mkLconjugateLsq,too_many_1, wrong_no_1},
    {"dvfsf_smupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_smupdknowl},
    {"bvarom",                  CC_bvarom,      too_many_1,    wrong_no_1},
    {"a2vdp",                   CC_a2vdp,       too_many_1,    wrong_no_1},
    {"equiv-coeffs",            too_few_2,      CC_equivKcoeffs,wrong_no_2},
    {"cl_pnf",                  CC_cl_pnf,      too_many_1,    wrong_no_1},
    {"dip_moncomp",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_dip_moncomp},
    {"omattrir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_omattrir},
    {"extbrsea",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_extbrsea},
    {"fnreval",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnreval},
    {"tp1",                     CC_tp1,         too_many_1,    wrong_no_1},
    {"bcminus?",                CC_bcminusW,    too_many_1,    wrong_no_1},
    {"xreadlist",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreadlist},
    {"nspaces",                 CC_nspaces,     too_many_1,    wrong_no_1},
    {"deletez1",                too_few_2,      CC_deletez1,   wrong_no_2},
    {"pa_list2vect",            too_few_2,      CC_pa_list2vect,wrong_no_2},
    {"solvealgdepends",         too_few_2,      CC_solvealgdepends,wrong_no_2},
    {"get-height",              CC_getKheight,  too_many_1,    wrong_no_1},
    {"sfto_pdecf",              CC_sfto_pdecf,  too_many_1,    wrong_no_1},
    {"evalnumberp",             CC_evalnumberp, too_many_1,    wrong_no_1},
    {"intervalom",              CC_intervalom,  too_many_1,    wrong_no_1},
    {"simpunion",               CC_simpunion,   too_many_1,    wrong_no_1},
    {"get:const",               too_few_2,      CC_getTconst,  wrong_no_2},
    {"toolongexpp",             CC_toolongexpp, too_many_1,    wrong_no_1},
    {"find_bubles_coeff",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles_coeff},
    {"fs:minusp",               CC_fsTminusp,   too_many_1,    wrong_no_1},
    {"ratdif",                  too_few_2,      CC_ratdif,     wrong_no_2},
    {NULL, (one_args *)"u27", (two_args *)"14391 2483074 8683247", 0}
};

/* end of generated code */
