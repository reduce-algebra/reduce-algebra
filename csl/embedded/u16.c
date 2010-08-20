
/* $destdir/generated-c\u16.c Machine generated C code */

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


/* Code for exptpri */

static Lisp_Object CC_exptpri(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptpri");
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
    v75 = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*list */
    qvalue(elt(env, 1)) = nil; /* !*list */
    stack[0] = nil;
    v74 = qvalue(elt(env, 2)); /* !*nat */
    if (v74 == nil) goto v77;
    v74 = qvalue(elt(env, 3)); /* !*fort */
    if (!(v74 == nil)) goto v77;
    v76 = elt(env, 5); /* expt */
    v74 = elt(env, 6); /* infix */
    v74 = get(v76, v74);
    env = stack[-7];
    stack[-2] = v74;
    v74 = (Lisp_Object)greaterp2(v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v74 = v74 ? lisp_true : nil;
    env = stack[-7];
    v74 = (v74 == nil ? lisp_true : nil);
    stack[-4] = v74;
    v74 = stack[-5];
    v74 = qcdr(v74);
    v74 = qcar(v74);
    stack[-1] = v74;
    v74 = stack[-5];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    stack[-3] = v74;
    v74 = qvalue(elt(env, 7)); /* !*eraise */
    if (v74 == nil) goto v79;
    v74 = stack[-1];
    if (!consp(v74)) goto v79;
    v74 = stack[-1];
    v75 = qcar(v74);
    v74 = elt(env, 8); /* prifn */
    v74 = get(v75, v74);
    env = stack[-7];
    stack[0] = v74;
    if (v74 == nil) goto v79;
    v75 = stack[0];
    v74 = elt(env, 5); /* expt */
    v75 = get(v75, v74);
    env = stack[-7];
    v74 = elt(env, 9); /* inbrackets */
    if (!(v75 == v74)) goto v79;
    v76 = stack[-1];
    v75 = (Lisp_Object)1; /* 0 */
    v74 = elt(env, 9); /* inbrackets */
    fn = elt(env, 21); /* layout!-formula */
    v74 = (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-1] = v74;
    goto v80;

v80:
    v74 = stack[-1];
    if (v74 == nil) goto v81;
    stack[-5] = qvalue(elt(env, 12)); /* !*ratpri */
    qvalue(elt(env, 12)) = nil; /* !*ratpri */
    v75 = stack[-3];
    v74 = elt(env, 13); /* quotient */
    if (!consp(v75)) goto v82;
    v75 = qcar(v75);
    if (!(v75 == v74)) goto v82;
    v74 = stack[-3];
    v74 = qcdr(v74);
    v75 = qcar(v74);
    v74 = elt(env, 14); /* minus */
    if (!consp(v75)) goto v82;
    v75 = qcar(v75);
    if (!(v75 == v74)) goto v82;
    stack[0] = elt(env, 14); /* minus */
    v74 = stack[-3];
    v76 = qcar(v74);
    v74 = stack[-3];
    v74 = qcdr(v74);
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v75 = qcar(v74);
    v74 = stack[-3];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    v74 = list3(v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    v74 = list2(stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-3] = v74;
    goto v84;

v84:
    v76 = stack[-3];
    v74 = qvalue(elt(env, 7)); /* !*eraise */
    if (v74 == nil) goto v85;
    v74 = (Lisp_Object)1; /* 0 */
    v75 = v74;
    goto v86;

v86:
    v74 = qvalue(elt(env, 11)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v74 = (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-3] = v74;
    qvalue(elt(env, 12)) = stack[-5]; /* !*ratpri */
    v74 = stack[-3];
    if (v74 == nil) goto v87;
    v74 = stack[-1];
    v74 = qcar(v74);
    v75 = qcdr(v74);
    v74 = stack[-3];
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v74 = plus2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-5] = v74;
    v74 = stack[-4];
    if (v74 == nil) goto v88;
    v75 = stack[-5];
    v74 = (Lisp_Object)33; /* 2 */
    v74 = plus2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-5] = v74;
    goto v88;

v88:
    stack[0] = stack[-5];
    v74 = qvalue(elt(env, 11)); /* nil */
    v75 = Llinelength(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = qvalue(elt(env, 15)); /* spare!* */
    v75 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = qvalue(elt(env, 16)); /* orig!* */
    v74 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = (Lisp_Object)greaterp2(stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v74 = v74 ? lisp_true : nil;
    env = stack[-7];
    if (v74 == nil) goto v89;
    v74 = elt(env, 4); /* failed */
    goto v90;

v90:
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    { popv(8); return onevalue(v74); }

v89:
    stack[0] = stack[-5];
    v74 = qvalue(elt(env, 11)); /* nil */
    v75 = Llinelength(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = qvalue(elt(env, 15)); /* spare!* */
    v75 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = qvalue(elt(env, 17)); /* posn!* */
    v74 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = (Lisp_Object)greaterp2(stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v74 = v74 ? lisp_true : nil;
    env = stack[-7];
    if (v74 == nil) goto v91;
    v74 = qvalue(elt(env, 18)); /* t */
    fn = elt(env, 22); /* terpri!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    goto v91;

v91:
    v74 = stack[-4];
    if (v74 == nil) goto v92;
    v74 = elt(env, 19); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    goto v92;

v92:
    v74 = stack[-1];
    fn = elt(env, 24); /* putpline */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = qvalue(elt(env, 7)); /* !*eraise */
    if (v74 == nil) goto v93;
    v75 = (Lisp_Object)17; /* 1 */
    v74 = stack[-3];
    v74 = qcdr(v74);
    v74 = qcar(v74);
    v74 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-5] = v74;
    goto v94;

v94:
    v76 = (Lisp_Object)1; /* 0 */
    v75 = stack[-5];
    v74 = stack[-3];
    v74 = qcar(v74);
    v74 = qcar(v74);
    fn = elt(env, 25); /* update!-pline */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = stack[-3];
    v74 = qcar(v74);
    stack[-1] = qcdr(v74);
    v74 = stack[-3];
    v74 = qcdr(v74);
    v75 = qcar(v74);
    v74 = stack[-5];
    stack[0] = plus2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = stack[-3];
    v74 = qcdr(v74);
    v75 = qcdr(v74);
    v74 = stack[-5];
    v74 = plus2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = cons(stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = acons(stack[-2], stack[-1], v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    fn = elt(env, 24); /* putpline */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = stack[-4];
    if (v74 == nil) goto v95;
    v74 = elt(env, 20); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    goto v95;

v95:
    v74 = nil;
    goto v90;

v93:
    v74 = elt(env, 5); /* expt */
    fn = elt(env, 26); /* oprin */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = (Lisp_Object)1; /* 0 */
    stack[-5] = v74;
    goto v94;

v87:
    v74 = elt(env, 4); /* failed */
    goto v90;

v85:
    v74 = stack[-2];
    v75 = v74;
    goto v86;

v82:
    v74 = stack[-3];
    fn = elt(env, 27); /* negnumberchk */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-3] = v74;
    goto v84;

v81:
    v74 = elt(env, 4); /* failed */
    goto v90;

v79:
    v75 = stack[0];
    v74 = elt(env, 10); /* indexprin */
    if (!(v75 == v74)) goto v96;
    v75 = stack[-1];
    v74 = stack[-3];
    fn = elt(env, 28); /* indexpower */
    v75 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v74 = elt(env, 4); /* failed */
    if (v75 == v74) goto v96;
    v74 = qvalue(elt(env, 11)); /* nil */
    goto v90;

v96:
    v76 = stack[-1];
    v75 = stack[-2];
    v74 = qvalue(elt(env, 11)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v74 = (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-1] = v74;
    goto v80;

v77:
    v74 = elt(env, 4); /* failed */
    goto v90;
/* error exit handlers */
v83:
    env = stack[-7];
    qvalue(elt(env, 12)) = stack[-5]; /* !*ratpri */
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
v78:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
}



/* Code for simpg3 */

static Lisp_Object CC_simpg3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpg3");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v0;
/* end of prologue */
    v97 = v90;
    v90 = elt(env, 1); /* g3 */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v97, v90);
    }
}



/* Code for add!-degrees */

static Lisp_Object CC_addKdegrees(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add-degrees");
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
    stack[-5] = nil;
    goto v97;

v97:
    v103 = stack[-4];
    if (v103 == nil) goto v90;
    v103 = stack[-4];
    v103 = qcar(v103);
    stack[-2] = v103;
    v103 = stack[-3];
    v103 = qcar(v103);
    stack[-1] = v103;
    v103 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v103;
    goto v105;

v105:
    v103 = stack[-2];
    if (v103 == nil) goto v106;
    v103 = stack[-2];
    v104 = qcar(v103);
    v103 = stack[-1];
    v103 = qcar(v103);
    fn = elt(env, 2); /* tayexp!-plus2 */
    v104 = (*qfn2(fn))(qenv(fn), v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    v103 = stack[0];
    v103 = cons(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    stack[0] = v103;
    v103 = stack[-2];
    v103 = qcdr(v103);
    stack[-2] = v103;
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    goto v105;

v106:
    v103 = stack[0];
    v104 = Lnreverse(nil, v103);
    env = stack[-6];
    v103 = stack[-5];
    v103 = cons(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    stack[-5] = v103;
    v103 = stack[-4];
    v103 = qcdr(v103);
    stack[-4] = v103;
    v103 = stack[-3];
    v103 = qcdr(v103);
    stack[-3] = v103;
    goto v97;

v90:
    v103 = stack[-5];
        popv(7);
        return Lnreverse(nil, v103);
/* error exit handlers */
v107:
    popv(7);
    return nil;
}



/* Code for tmsf */

static Lisp_Object CC_tmsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v115, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tmsf");
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
    v54 = (Lisp_Object)1; /* 0 */
    v116 = v54;
    goto v2;

v2:
    v54 = stack[-1];
    if (!consp(v54)) goto v12;
    v54 = stack[-1];
    v54 = qcar(v54);
    if (!consp(v54)) goto v12;
    stack[-2] = v116;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v54 = qcar(v54);
    stack[0] = v54;
    fn = elt(env, 2); /* sfp */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    if (v54 == nil) goto v80;
    v54 = stack[0];
    v54 = CC_tmsf(env, v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    stack[0] = v54;
    goto v117;

v117:
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcdr(v54);
    fn = elt(env, 3); /* tmsf!* */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v54 = plus2(stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v54 = plus2(stack[-2], v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v116 = v54;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v115 = qcdr(v54);
    v54 = (Lisp_Object)17; /* 1 */
    if (v115 == v54) goto v118;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v115 = qcdr(v54);
    v54 = (Lisp_Object)33; /* 2 */
    if (v115 == v54) goto v64;
    v115 = v116;
    v54 = (Lisp_Object)33; /* 2 */
    v54 = plus2(v115, v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v116 = v54;
    goto v118;

v118:
    v54 = stack[-1];
    v54 = qcdr(v54);
    stack[-1] = v54;
    goto v2;

v64:
    v54 = v116;
    v54 = add1(v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v116 = v54;
    goto v118;

v80:
    v54 = (Lisp_Object)17; /* 1 */
    stack[0] = v54;
    goto v117;

v12:
    v54 = stack[-1];
    if (v54 == nil) { popv(4); return onevalue(v116); }
    v54 = v116;
    popv(4);
    return add1(v54);
/* error exit handlers */
v56:
    popv(4);
    return nil;
}



/* Code for ibalp_clausep */

static Lisp_Object CC_ibalp_clausep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clausep");
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
    v73 = stack[0];
    fn = elt(env, 3); /* ibalp_litp */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-1];
    if (!(v73 == nil)) { popv(2); return onevalue(v73); }
    v73 = stack[0];
    if (!consp(v73)) goto v121;
    v73 = stack[0];
    v73 = qcar(v73);
    v71 = v73;
    goto v77;

v77:
    v73 = elt(env, 1); /* or */
    if (v71 == v73) goto v122;
    v73 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v73); }

v122:
    v73 = stack[0];
    v73 = qcdr(v73);
    {
        popv(2);
        fn = elt(env, 4); /* ibalp_litlp */
        return (*qfn1(fn))(qenv(fn), v73);
    }

v121:
    v73 = stack[0];
    v71 = v73;
    goto v77;
/* error exit handlers */
v120:
    popv(2);
    return nil;
}



/* Code for tobvarir */

static Lisp_Object CC_tobvarir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tobvarir");
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
    v117 = stack[-1];
    if (v117 == nil) goto v7;
    stack[-2] = elt(env, 1); /* bvar */
    v117 = stack[-1];
    v124 = qcar(v117);
    v117 = (Lisp_Object)17; /* 1 */
    stack[0] = list2(v124, v117);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v117 = stack[-1];
    v117 = qcdr(v117);
    v117 = CC_tobvarir(env, v117);
    nil = C_nil;
    if (exception_pending()) goto v125;
    {
        Lisp_Object v120 = stack[-2];
        Lisp_Object v126 = stack[0];
        popv(4);
        return acons(v120, v126, v117);
    }

v7:
    v117 = nil;
    { popv(4); return onevalue(v117); }
/* error exit handlers */
v125:
    popv(4);
    return nil;
}



/* Code for diffsq */

static Lisp_Object CC_diffsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffsq");
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
    v135 = stack[-2];
    v136 = qcar(v135);
    v135 = stack[-1];
    fn = elt(env, 1); /* difff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    stack[0] = stack[-2];
    v135 = stack[-2];
    v136 = qcdr(v135);
    v135 = stack[-1];
    fn = elt(env, 1); /* difff */
    v135 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    v135 = (*qfn2(fn))(qenv(fn), stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    fn = elt(env, 3); /* negsq */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v136 = (Lisp_Object)17; /* 1 */
    v135 = stack[-2];
    v135 = qcdr(v135);
    v135 = cons(v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    {
        Lisp_Object v138 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v138, v135);
    }
/* error exit handlers */
v137:
    popv(5);
    return nil;
}



/* Code for prin2t */

static Lisp_Object CC_prin2t(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2t");
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
    v41 = stack[0];
    v41 = Lprinc(nil, v41);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v41 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v12;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for rd!:prep */

static Lisp_Object CC_rdTprep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:prep");
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
    v130 = qvalue(elt(env, 1)); /* !*noconvert */
    if (v130 == nil) goto v7;
    v130 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* rdprep1 */
        return (*qfn1(fn))(qenv(fn), v130);
    }

v7:
    v130 = stack[0];
    fn = elt(env, 3); /* rd!:onep */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    if (v130 == nil) goto v90;
    v130 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v130); }

v90:
    v130 = stack[0];
    fn = elt(env, 4); /* rd!:minus */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    fn = elt(env, 3); /* rd!:onep */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    if (v130 == nil) goto v139;
    v130 = (Lisp_Object)-15; /* -1 */
    { popv(2); return onevalue(v130); }

v139:
    v130 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* rdprep1 */
        return (*qfn1(fn))(qenv(fn), v130);
    }
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for opmtchrevop */

static Lisp_Object CC_opmtchrevop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtchrevop");
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
    v73 = qvalue(elt(env, 1)); /* !*val */
    if (v73 == nil) goto v60;
    v71 = elt(env, 2); /* cons */
    v73 = stack[0];
    v73 = Lsmemq(nil, v71, v73);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    if (!(v73 == nil)) goto v60;
    v73 = stack[0];
    stack[-1] = qcar(v73);
    v73 = stack[0];
    v73 = qcdr(v73);
    fn = elt(env, 3); /* revlis */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v73 = cons(stack[-1], v73);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v73);
    }

v60:
    v73 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v73);
    }
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for total!-degree!-in!-powers */

static Lisp_Object CC_totalKdegreeKinKpowers(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v115, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for total-degree-in-powers");
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

v148:
    v54 = stack[-1];
    if (v54 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v54 = stack[-1];
    if (!consp(v54)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v54 = stack[-1];
    v54 = qcar(v54);
    if (!consp(v54)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v115 = qcar(v54);
    v54 = stack[0];
    v54 = Latsoc(nil, v115, v54);
    stack[-2] = v54;
    if (v54 == nil) goto v104;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v115 = qcdr(v54);
    v54 = stack[-2];
    v54 = qcdr(v54);
    v54 = (Lisp_Object)greaterp2(v115, v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    if (v54 == nil) goto v62;
    v115 = stack[-2];
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v54 = qcdr(v54);
    v54 = Lrplacd(nil, v115, v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    goto v62;

v62:
    v54 = stack[-1];
    stack[-2] = qcdr(v54);
    v54 = stack[-1];
    v54 = qcar(v54);
    v115 = qcdr(v54);
    v54 = stack[0];
    v54 = CC_totalKdegreeKinKpowers(env, v115, v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v54;
    goto v148;

v104:
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v116 = qcar(v54);
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v115 = qcdr(v54);
    v54 = stack[0];
    v54 = acons(v116, v115, v54);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    stack[0] = v54;
    goto v62;
/* error exit handlers */
v56:
    popv(4);
    return nil;
}



/* Code for mvar_member */

static Lisp_Object CC_mvar_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v72, v73, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mvar_member");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v1;
    v71 = v0;
/* end of prologue */
    v72 = v71;
    v124 = v73;
    v124 = (equal(v72, v124) ? lisp_true : nil);
    if (!(v124 == nil)) return onevalue(v124);
    v124 = v73;
    if (!consp(v124)) goto v119;
    v124 = v71;
    v72 = v73;
    v72 = qcdr(v72);
    {
        fn = elt(env, 2); /* arglist_member */
        return (*qfn2(fn))(qenv(fn), v124, v72);
    }

v119:
    v124 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v124);
}



/* Code for exptf */

static Lisp_Object CC_exptf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptf");
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
    v103 = stack[0];
    v64 = (Lisp_Object)1; /* 0 */
    v64 = (Lisp_Object)lessp2(v103, v64);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v64 = v64 ? lisp_true : nil;
    env = stack[-2];
    if (v64 == nil) goto v41;
    v104 = elt(env, 1); /* "exptf" */
    v103 = stack[-1];
    v64 = stack[0];
    v64 = list3(v104, v103, v64);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* errach */
        return (*qfn1(fn))(qenv(fn), v64);
    }

v41:
    v64 = stack[-1];
    if (!consp(v64)) goto v125;
    v64 = stack[-1];
    v64 = qcar(v64);
    if (!consp(v64)) goto v125;
    v64 = qvalue(elt(env, 2)); /* !*exp */
    if (!(v64 == nil)) goto v135;
    v64 = stack[-1];
    fn = elt(env, 4); /* kernlp */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    if (!(v64 == nil)) goto v135;
    v103 = stack[-1];
    v64 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* mksfpf */
        return (*qfn2(fn))(qenv(fn), v103, v64);
    }

v135:
    v103 = stack[-1];
    v64 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* exptf1 */
        return (*qfn2(fn))(qenv(fn), v103, v64);
    }

v125:
    v103 = stack[-1];
    v64 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v103, v64);
    }
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for remove!-free!-vars!* */

static Lisp_Object CC_removeKfreeKvarsH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars*");
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
    v20 = v0;
/* end of prologue */
    v41 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*!*noremove!*!* */
    qvalue(elt(env, 2)) = v41; /* !*!*noremove!*!* */
    v41 = v20;
    fn = elt(env, 3); /* remove!-free!-vars */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    { popv(2); return onevalue(v41); }
/* error exit handlers */
v2:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    popv(2);
    return nil;
}



/* Code for simpexpt */

static Lisp_Object CC_simpexpt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v99, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt");
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
    v126 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v126; /* kord!* */
    v126 = stack[0];
    v99 = qcdr(v126);
    v126 = elt(env, 3); /* expt */
    fn = elt(env, 5); /* carx */
    v126 = (*qfn2(fn))(qenv(fn), v99, v126);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    fn = elt(env, 6); /* simpexpon */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    v99 = v126;
    v126 = elt(env, 4); /* resimp */
    fn = elt(env, 7); /* simpexpon1 */
    v126 = (*qfn2(fn))(qenv(fn), v99, v126);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    v99 = stack[0];
    v131 = qcar(v99);
    v99 = v126;
    v126 = qvalue(elt(env, 1)); /* nil */
    {
        popv(3);
        fn = elt(env, 8); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v131, v99, v126);
    }
/* error exit handlers */
v155:
    popv(3);
    return nil;
v154:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    popv(3);
    return nil;
}



/* Code for ibalp_process!-var */

static Lisp_Object MS_CDECL CC_ibalp_processKvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v108, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v185, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ibalp_process-var");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_process-var");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v108,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v108,v3);
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
    stack[-11] = v3;
    stack[-12] = v108;
    stack[-13] = v1;
    stack[-14] = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* !! */
    v24 = stack[-12];
    v24 = Lexplode(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = cons(stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = Lcompress(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = Lintern(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    stack[-12] = v24;
    v185 = stack[-12];
    v24 = stack[-13];
    v24 = Latsoc(nil, v185, v24);
    v185 = v24;
    if (v24 == nil) goto v126;
    v24 = v185;
    v24 = qcdr(v24);
    stack[0] = v24;
    goto v188;

v188:
    v185 = stack[-11];
    v24 = (Lisp_Object)17; /* 1 */
    v24 = Leqn(nil, v185, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    if (v24 == nil) goto v189;
    v24 = stack[0];
    v24 = qcdr(v24);
    stack[-1] = qcdr(v24);
    v185 = stack[-14];
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcar(v24);
    v24 = cons(v185, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v24 = (*qfn2(fn))(qenv(fn), stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    stack[-1] = qcdr(v24);
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcar(v24);
    v24 = add1(v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v24 = (*qfn2(fn))(qenv(fn), stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    stack[-1] = qcdr(v24);
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcar(v24);
    v24 = add1(v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v24 = (*qfn2(fn))(qenv(fn), stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    stack[-1] = stack[-14];
    v185 = stack[0];
    v24 = stack[-14];
    v24 = qcar(v24);
    v24 = cons(v185, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v24 = (*qfn2(fn))(qenv(fn), stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    { Lisp_Object res = stack[-13]; popv(17); return onevalue(res); }

v189:
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    stack[-1] = qcdr(v24);
    v185 = stack[-14];
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcar(v24);
    v24 = cons(v185, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v24 = (*qfn2(fn))(qenv(fn), stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    stack[-1] = qcdr(v24);
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcar(v24);
    v24 = add1(v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v24 = (*qfn2(fn))(qenv(fn), stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    stack[-1] = qcdr(v24);
    v24 = stack[0];
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcdr(v24);
    v24 = qcar(v24);
    v24 = add1(v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v24 = (*qfn2(fn))(qenv(fn), stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = stack[-14];
    stack[-1] = qcdr(v24);
    v185 = stack[0];
    v24 = stack[-14];
    v24 = qcdr(v24);
    v24 = qcar(v24);
    v24 = cons(v185, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v24 = (*qfn2(fn))(qenv(fn), stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    { Lisp_Object res = stack[-13]; popv(17); return onevalue(res); }

v126:
    stack[-15] = stack[-12];
    stack[-10] = qvalue(elt(env, 2)); /* nil */
    stack[-9] = qvalue(elt(env, 2)); /* nil */
    stack[-8] = qvalue(elt(env, 2)); /* nil */
    stack[-7] = (Lisp_Object)1; /* 0 */
    stack[-6] = (Lisp_Object)1; /* 0 */
    stack[-5] = (Lisp_Object)-15; /* -1 */
    stack[-4] = qvalue(elt(env, 2)); /* nil */
    stack[-3] = (Lisp_Object)1; /* 0 */
    stack[-2] = (Lisp_Object)1; /* 0 */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    stack[0] = (Lisp_Object)1; /* 0 */
    v186 = qvalue(elt(env, 2)); /* nil */
    v185 = (Lisp_Object)1; /* 0 */
    v24 = qvalue(elt(env, 2)); /* nil */
    v24 = list3(v186, v185, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = list3star(stack[-2], stack[-1], stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = list3star(stack[-5], stack[-4], stack[-3], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = list3star(stack[-8], stack[-7], stack[-6], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    v24 = list3star(stack[-15], stack[-10], stack[-9], v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    stack[0] = v24;
    v186 = stack[-12];
    v185 = stack[0];
    v24 = stack[-13];
    v24 = acons(v186, v185, v24);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-16];
    stack[-13] = v24;
    goto v188;
/* error exit handlers */
v187:
    popv(17);
    return nil;
}



/* Code for floatprop */

static Lisp_Object CC_floatprop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v119;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for floatprop");
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
    v129 = v0;
/* end of prologue */
    v119 = v129;
    v119 = Lfloatp(nil, v119);
    env = stack[0];
    if (!(v119 == nil)) { popv(1); return onevalue(v119); }
    v119 = elt(env, 1); /* !:rd!: */
        popv(1);
        return Leqcar(nil, v129, v119);
}



/* Code for xlcm */

static Lisp_Object CC_xlcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xlcm");
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
    goto v41;

v41:
    v55 = stack[-1];
    if (v55 == nil) goto v134;
    v55 = stack[-1];
    v193 = qcar(v55);
    v55 = (Lisp_Object)17; /* 1 */
    if (v193 == v55) goto v134;
    v55 = stack[0];
    if (v55 == nil) goto v80;
    v55 = stack[0];
    v193 = qcar(v55);
    v55 = (Lisp_Object)17; /* 1 */
    if (v193 == v55) goto v80;
    v55 = stack[-1];
    v193 = qcar(v55);
    v55 = stack[0];
    v55 = qcar(v55);
    if (v193 == v55) goto v112;
    v55 = stack[-1];
    v193 = qcar(v55);
    v55 = stack[0];
    v55 = qcar(v55);
    fn = elt(env, 1); /* factorordp */
    v55 = (*qfn2(fn))(qenv(fn), v193, v55);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    if (v55 == nil) goto v141;
    v55 = stack[-1];
    v193 = qcar(v55);
    v55 = stack[-2];
    v55 = cons(v193, v55);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[-2] = v55;
    v55 = stack[-1];
    v55 = qcdr(v55);
    stack[-1] = v55;
    goto v41;

v141:
    v55 = stack[0];
    v193 = qcar(v55);
    v55 = stack[-2];
    v55 = cons(v193, v55);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[-2] = v55;
    v55 = stack[0];
    v55 = qcdr(v55);
    stack[0] = v55;
    goto v41;

v112:
    v55 = stack[-1];
    v193 = qcar(v55);
    v55 = stack[-2];
    v55 = cons(v193, v55);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[-2] = v55;
    v55 = stack[-1];
    v55 = qcdr(v55);
    stack[-1] = v55;
    v55 = stack[0];
    v55 = qcdr(v55);
    stack[0] = v55;
    goto v41;

v80:
    v193 = stack[-2];
    v55 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v193, v55);
    }

v134:
    v193 = stack[-2];
    v55 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v193, v55);
    }
/* error exit handlers */
v96:
    popv(4);
    return nil;
}



/* Code for prinlatom */

static Lisp_Object CC_prinlatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinlatom");
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
    v191 = stack[-1];
    v104 = elt(env, 1); /* font */
    v104 = get(v191, v104);
    env = stack[-3];
    stack[-2] = v104;
    if (v104 == nil) goto v70;
    v104 = stack[-2];
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    goto v70;

v70:
    v191 = stack[-1];
    v104 = elt(env, 2); /* accent */
    v104 = get(v191, v104);
    env = stack[-3];
    stack[0] = v104;
    if (v104 == nil) goto v132;
    v104 = stack[0];
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    goto v132;

v132:
    v191 = stack[-1];
    v104 = elt(env, 3); /* name */
    v104 = get(v191, v104);
    env = stack[-3];
    v191 = v104;
    if (v104 == nil) goto v128;
    v104 = v191;
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    goto v120;

v120:
    v104 = stack[0];
    if (v104 == nil) goto v151;
    v104 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    goto v151;

v151:
    v104 = stack[-2];
    if (v104 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v104 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v67;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v128:
    v104 = stack[-1];
    fn = elt(env, 6); /* testchar1 */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    goto v120;
/* error exit handlers */
v67:
    popv(4);
    return nil;
}



/* Code for pterpri */

static Lisp_Object MS_CDECL CC_pterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v150, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pterpri");
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
    v145 = qvalue(elt(env, 1)); /* nil */
    v145 = Lwrs(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-3] = v145;
    v145 = qvalue(elt(env, 2)); /* !*pprinbuf!* */
    v145 = Lnreverse(nil, v145);
    env = stack[-4];
    stack[-2] = v145;
    v145 = qvalue(elt(env, 3)); /* !*outchanl!* */
    stack[-1] = v145;
    goto v149;

v149:
    v145 = stack[-1];
    if (v145 == nil) goto v97;
    v145 = stack[-1];
    v145 = qcar(v145);
    v145 = Lwrs(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v145 = stack[-2];
    stack[0] = v145;
    goto v122;

v122:
    v145 = stack[0];
    if (v145 == nil) goto v114;
    v145 = stack[0];
    v145 = qcar(v145);
    v64 = v145;
    v150 = qvalue(elt(env, 4)); /* gentranlang!* */
    v145 = elt(env, 5); /* fortran */
    if (v150 == v145) goto v127;
    v145 = v64;
    v145 = Lprinc(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v132;

v132:
    v145 = stack[0];
    v145 = qcdr(v145);
    stack[0] = v145;
    goto v122;

v127:
    v145 = v64;
    fn = elt(env, 7); /* fprin2 */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v132;

v114:
    v145 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v145 = stack[-1];
    v145 = qcdr(v145);
    stack[-1] = v145;
    goto v149;

v97:
    v145 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 6)) = v145; /* !*posn!* */
    v145 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v145; /* !*pprinbuf!* */
    v145 = stack[-3];
    v145 = Lwrs(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v145 = nil;
    { popv(5); return onevalue(v145); }
/* error exit handlers */
v153:
    popv(5);
    return nil;
}



/* Code for physopsm!* */

static Lisp_Object CC_physopsmH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v219, v220, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsm*");
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
    stack[0] = nil;
    v91 = stack[-3];
    if (v91 == nil) goto v97;
    v91 = stack[-3];
    if (is_number(v91)) goto v97;
    v91 = stack[-3];
    fn = elt(env, 13); /* physopp */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    if (v91 == nil) goto v222;
    v219 = stack[-3];
    v91 = elt(env, 1); /* rvalue */
    v91 = get(v219, v91);
    env = stack[-5];
    stack[-1] = v91;
    if (v91 == nil) goto v105;
    v91 = stack[-1];
    fn = elt(env, 14); /* physopaeval */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    goto v134;

v134:
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v105:
    v91 = stack[-3];
    if (symbolp(v91)) goto v120;
    v91 = stack[-3];
    v219 = qcar(v91);
    v91 = elt(env, 2); /* psimpfn */
    v91 = get(v219, v91);
    env = stack[-5];
    stack[-1] = v91;
    if (v91 == nil) goto v112;
    v219 = stack[-1];
    v91 = stack[-3];
    v91 = Lapply1(nil, v219, v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    goto v134;

v112:
    v91 = stack[-3];
    v219 = qcar(v91);
    v91 = elt(env, 3); /* opmtch */
    v91 = get(v219, v91);
    env = stack[-5];
    if (v91 == nil) goto v65;
    v91 = stack[-3];
    fn = elt(env, 15); /* opmtch!* */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    stack[-1] = v91;
    if (v91 == nil) goto v65;
    v91 = stack[-1];
    goto v134;

v65:
    v91 = stack[-3];
    goto v134;

v120:
    v91 = stack[-3];
    goto v134;

v222:
    v91 = stack[-3];
    if (!consp(v91)) goto v110;
    v91 = stack[-3];
    v91 = qcar(v91);
    stack[-4] = v91;
    v91 = stack[-3];
    v91 = qcdr(v91);
    stack[-2] = v91;
    v219 = stack[-4];
    v91 = elt(env, 4); /* physopfunction */
    v91 = get(v219, v91);
    env = stack[-5];
    stack[-1] = v91;
    if (v91 == nil) goto v223;
    v219 = stack[-4];
    v91 = elt(env, 5); /* physoparith */
    v91 = Lflagp(nil, v219, v91);
    env = stack[-5];
    if (v91 == nil) goto v224;
    v91 = stack[-2];
    fn = elt(env, 16); /* hasonephysop */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    if (v91 == nil) goto v37;
    stack[0] = stack[-1];
    v91 = stack[-2];
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v91 = (*qfn2(fn))(qenv(fn), stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v37:
    v219 = stack[-4];
    v91 = stack[-2];
    v91 = cons(v219, v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    fn = elt(env, 18); /* reval3 */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v224:
    v219 = stack[-4];
    v91 = elt(env, 6); /* physopfn */
    v91 = Lflagp(nil, v219, v91);
    env = stack[-5];
    if (v91 == nil) goto v84;
    v91 = stack[-2];
    fn = elt(env, 19); /* areallphysops */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    if (v91 == nil) goto v225;
    stack[0] = stack[-1];
    v91 = stack[-2];
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v91 = (*qfn2(fn))(qenv(fn), stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v225:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v221 = elt(env, 7); /* "invalid call of " */
    v220 = stack[-4];
    v219 = elt(env, 8); /* " with args: " */
    v91 = stack[-2];
    v91 = list4(v221, v220, v219, v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v91 = (*qfn2(fn))(qenv(fn), stack[-1], v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v84:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v220 = stack[-4];
    v219 = elt(env, 9); /* " has been flagged Physopfunction" */
    v91 = elt(env, 10); /* " but is not defined" */
    v91 = list3(v220, v219, v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v91 = (*qfn2(fn))(qenv(fn), stack[-1], v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v223:
    v219 = stack[-4];
    v91 = elt(env, 11); /* physopmapping */
    v91 = Lflagp(nil, v219, v91);
    env = stack[-5];
    if (v91 == nil) goto v226;
    v91 = stack[-2];
    fn = elt(env, 21); /* !*physopp!* */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    if (v91 == nil) goto v226;
    v219 = stack[-4];
    v91 = stack[-2];
    v219 = cons(v219, v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v91 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 22); /* to */
    v219 = (*qfn2(fn))(qenv(fn), v219, v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v91 = (Lisp_Object)17; /* 1 */
    v91 = cons(v219, v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v219 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v91 = (Lisp_Object)17; /* 1 */
    v91 = cons(v219, v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    fn = elt(env, 23); /* mk!*sq */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v226:
    v219 = stack[-4];
    v91 = elt(env, 12); /* prog */
    if (v219 == v91) goto v227;
    v91 = stack[-3];
    fn = elt(env, 24); /* aeval */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v227:
    v91 = stack[-2];
    fn = elt(env, 25); /* physopprog */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v110:
    v91 = stack[-3];
    fn = elt(env, 24); /* aeval */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v21;
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v97:
    v91 = stack[-3];
    stack[0] = v91;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
/* error exit handlers */
v21:
    popv(6);
    return nil;
}



/* Code for pst_termnodep */

static Lisp_Object CC_pst_termnodep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v152;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v0;
/* end of prologue */
    v152 = qcdr(v77);
    v77 = (Lisp_Object)1; /* 0 */
    v77 = *(Lisp_Object *)((char *)v152 + (CELL-TAG_VECTOR) + ((int32_t)v77/(16/CELL)));
    v77 = qcdr(v77);
    v77 = (v77 == nil ? lisp_true : nil);
    return onevalue(v77);
}



/* Code for evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_evaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v108, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v230, v178, v177, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v108,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v108;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v41:
    v116 = stack[-3];
    if (!consp(v116)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v116 = stack[-3];
    v116 = qcar(v116);
    if (!consp(v116)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v230 = stack[-1];
    v116 = (Lisp_Object)1; /* 0 */
    if (v230 == v116) goto v123;
    v116 = stack[-2];
    if (v116 == nil) goto v114;
    v116 = stack[-3];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v230 = qcar(v116);
    v116 = stack[-2];
    if (equal(v230, v116)) goto v101;
    v116 = stack[-3];
    v116 = qcar(v116);
    stack[-4] = qcar(v116);
    v116 = stack[-3];
    v116 = qcar(v116);
    v178 = qcdr(v116);
    v230 = stack[-2];
    v116 = stack[-1];
    stack[0] = CC_evaluateKmodKp(env, 3, v178, v230, v116);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    v116 = stack[-3];
    v178 = qcdr(v116);
    v230 = stack[-2];
    v116 = stack[-1];
    v116 = CC_evaluateKmodKp(env, 3, v178, v230, v116);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    {
        Lisp_Object v96 = stack[-4];
        Lisp_Object v231 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v96, v231, v116);
    }

v101:
    v116 = stack[-3];
    v116 = qcar(v116);
    v56 = qcdr(v116);
    v116 = stack[-3];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v177 = qcdr(v116);
    v116 = stack[-3];
    v178 = qcdr(v116);
    v230 = stack[-1];
    v116 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v56, v177, v178, v230, v116);
    }

v114:
    v116 = elt(env, 2); /* "Variable=NIL in EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v116);
    }

v123:
    v116 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v116;
    goto v41;
/* error exit handlers */
v188:
    popv(6);
    return nil;
}



/* Code for texstrlen */

static Lisp_Object CC_texstrlen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v102, v100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texstrlen");
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
    v179 = v0;
/* end of prologue */
    v102 = (Lisp_Object)1; /* 0 */
    v100 = v102;
    v102 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v179;
    goto v149;

v149:
    v179 = stack[0];
    if (v179 == nil) { popv(2); return onevalue(v100); }
    v179 = stack[0];
    v179 = qcar(v179);
    if (!(v102 == nil)) goto v99;
    v102 = v179;
    v179 = elt(env, 2); /* !! */
    if (!(v102 == v179)) goto v99;
    v179 = qvalue(elt(env, 3)); /* t */
    v102 = v179;
    goto v130;

v130:
    v179 = stack[0];
    v179 = qcdr(v179);
    stack[0] = v179;
    goto v149;

v99:
    v179 = v100;
    v179 = add1(v179);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    v100 = v179;
    v179 = qvalue(elt(env, 1)); /* nil */
    v102 = v179;
    goto v130;
/* error exit handlers */
v135:
    popv(2);
    return nil;
}



/* Code for get_group_in */

static Lisp_Object CC_get_group_in(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v41;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_group_in");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */
    v41 = qcar(v41);
    return onevalue(v41);
}



/* Code for ibalp_redclause */

static Lisp_Object CC_ibalp_redclause(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_redclause");
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
    stack[0] = nil;
    v131 = stack[-1];
    v131 = qcar(v131);
    stack[-2] = v131;
    goto v90;

v90:
    v131 = stack[-2];
    if (v131 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v131 = stack[0];
    if (!(v131 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v131 = stack[-2];
    v132 = qcar(v131);
    v131 = stack[-1];
    v131 = qcdr(v131);
    v131 = qcar(v131);
    fn = elt(env, 3); /* ibalp_vmember */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    if (v131 == nil) goto v192;
    v131 = qvalue(elt(env, 2)); /* t */
    stack[0] = v131;
    goto v192;

v192:
    v131 = stack[-2];
    v131 = qcdr(v131);
    stack[-2] = v131;
    goto v90;
/* error exit handlers */
v80:
    popv(4);
    return nil;
}



/* Code for ir2mml */

static Lisp_Object CC_ir2mml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ir2mml");
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
    v121 = elt(env, 1); /* (indent) */
    fn = elt(env, 8); /* fluid */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-1];
    v121 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 2)) = v121; /* ind */
    v121 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v121; /* indent */
    v121 = elt(env, 4); /* "<math>" */
    fn = elt(env, 9); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-1];
    v121 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 10); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-1];
    v121 = stack[0];
    fn = elt(env, 11); /* expression */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-1];
    v121 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-1];
    v121 = elt(env, 7); /* "</math>" */
    fn = elt(env, 9); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v139;
    v121 = nil;
    { popv(2); return onevalue(v121); }
/* error exit handlers */
v139:
    popv(2);
    return nil;
}



/* Code for subs4q */

static Lisp_Object CC_subs4q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v170, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs4q");
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
    stack[-3] = nil;
    stack[-2] = nil;
    v170 = elt(env, 1); /* slash */
    v169 = elt(env, 2); /* opmtch */
    v169 = get(v170, v169);
    env = stack[-7];
    stack[-6] = v169;
    if (v169 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v169 = stack[-5];
    fn = elt(env, 7); /* prepsq */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    stack[-4] = v169;
    v170 = elt(env, 1); /* slash */
    v169 = elt(env, 2); /* opmtch */
    v169 = Lremprop(nil, v170, v169);
    env = stack[-7];
    v236 = elt(env, 3); /* slash!* */
    v170 = elt(env, 2); /* opmtch */
    v169 = stack[-6];
    v169 = Lputprop(nil, 3, v236, v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    goto v80;

v80:
    v169 = stack[-4];
    if (v169 == nil) goto v155;
    v170 = stack[-4];
    stack[-3] = v170;
    v169 = elt(env, 4); /* quotient */
    if (!consp(v170)) goto v155;
    v170 = qcar(v170);
    if (!(v170 == v169)) goto v155;
    v170 = elt(env, 3); /* slash!* */
    v169 = stack[-4];
    v169 = qcdr(v169);
    v169 = cons(v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    fn = elt(env, 2); /* opmtch */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    if (!(v169 == nil)) goto v180;
    v170 = elt(env, 6); /* minus */
    v169 = stack[-4];
    v169 = qcdr(v169);
    v169 = qcdr(v169);
    v169 = qcar(v169);
    v169 = Lsmemq(nil, v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    if (v169 == nil) goto v107;
    stack[-1] = elt(env, 3); /* slash!* */
    v170 = elt(env, 6); /* minus */
    v169 = stack[-4];
    v169 = qcdr(v169);
    v169 = qcar(v169);
    v169 = list2(v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    fn = elt(env, 8); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    v170 = elt(env, 6); /* minus */
    v169 = stack[-4];
    v169 = qcdr(v169);
    v169 = qcdr(v169);
    v169 = qcar(v169);
    v169 = list2(v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    fn = elt(env, 8); /* reval */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    v169 = list3(stack[-1], stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    fn = elt(env, 2); /* opmtch */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    goto v180;

v180:
    stack[-4] = v169;
    v169 = stack[-2];
    if (!(v169 == nil)) goto v215;
    v169 = stack[-4];
    goto v215;

v215:
    stack[-2] = v169;
    goto v80;

v107:
    v169 = qvalue(elt(env, 5)); /* nil */
    goto v180;

v155:
    v169 = stack[-2];
    if (v169 == nil) goto v173;
    v169 = stack[-3];
    fn = elt(env, 9); /* simp!* */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-7];
    goto v172;

v172:
    stack[-5] = v169;
    v236 = elt(env, 1); /* slash */
    v170 = elt(env, 2); /* opmtch */
    v169 = stack[-6];
    v169 = Lputprop(nil, 3, v236, v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v212;
    { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v173:
    v169 = stack[-5];
    goto v172;
/* error exit handlers */
v212:
    popv(8);
    return nil;
}



/* Code for dm!-eq */

static Lisp_Object CC_dmKeq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-eq");
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
    v149 = v1;
    v77 = v0;
/* end of prologue */
    fn = elt(env, 1); /* dm!-difference */
    v149 = (*qfn2(fn))(qenv(fn), v77, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !:zerop */
        return (*qfn1(fn))(qenv(fn), v149);
    }
/* error exit handlers */
v152:
    popv(1);
    return nil;
}



/* Code for groebcplistsortin */

static Lisp_Object CC_groebcplistsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsortin");
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
    stack[0] = v1;
    v133 = v0;
/* end of prologue */
    v192 = stack[0];
    if (v192 == nil) goto v7;
    v192 = stack[0];
    fn = elt(env, 1); /* groebcplistsortin1 */
    v192 = (*qfn2(fn))(qenv(fn), v133, v192);
    nil = C_nil;
    if (exception_pending()) goto v130;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v7:
    v192 = v133;
    popv(1);
    return ncons(v192);
/* error exit handlers */
v130:
    popv(1);
    return nil;
}



/* Code for evgradlexcomp */

static Lisp_Object CC_evgradlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evgradlexcomp");
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

v7:
    v237 = stack[-2];
    if (v237 == nil) goto v12;
    v237 = stack[-1];
    if (v237 == nil) goto v149;
    v237 = stack[-2];
    v143 = qcar(v237);
    v237 = stack[-1];
    v237 = qcar(v237);
    v237 = Leqn(nil, v143, v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    if (v237 == nil) goto v72;
    v237 = stack[-2];
    v237 = qcdr(v237);
    stack[-2] = v237;
    v237 = stack[-1];
    v237 = qcdr(v237);
    stack[-1] = v237;
    goto v7;

v72:
    v237 = stack[-2];
    fn = elt(env, 2); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    v237 = stack[-1];
    fn = elt(env, 2); /* evtdeg */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v237;
    v143 = stack[-3];
    v237 = stack[0];
    v237 = Leqn(nil, v143, v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    if (v237 == nil) goto v235;
    v237 = stack[-2];
    v143 = qcar(v237);
    v237 = stack[-1];
    v237 = qcar(v237);
    if (((int32_t)(v143)) > ((int32_t)(v237))) goto v106;
    v237 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v237); }

v106:
    v237 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v237); }

v235:
    v143 = stack[-3];
    v237 = stack[0];
    if (((int32_t)(v143)) > ((int32_t)(v237))) goto v104;
    v237 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v237); }

v104:
    v237 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v237); }

v149:
    v237 = elt(env, 1); /* (0) */
    stack[-1] = v237;
    goto v7;

v12:
    v237 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v237); }
/* error exit handlers */
v182:
    popv(5);
    return nil;
}



/* Code for fortranname */

static Lisp_Object CC_fortranname(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortranname");
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
    v145 = stack[0];
    v145 = Lstringp(nil, v145);
    env = stack[-1];
    if (v145 == nil) goto v119;
    v145 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* stringtoatom */
        return (*qfn1(fn))(qenv(fn), v145);
    }

v119:
    v150 = stack[0];
    v145 = qvalue(elt(env, 1)); /* !*notfortranfuns!* */
    v145 = Lmemq(nil, v150, v145);
    if (v145 == nil) goto v77;
    v145 = qvalue(elt(env, 2)); /* !*stdout!* */
    v145 = qcdr(v145);
    v145 = Lwrs(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v145 = elt(env, 3); /* "*** WARNING: " */
    v145 = Lprinc(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v145 = stack[0];
    v145 = Lprin(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v145 = elt(env, 4); /* " is not an intrinsic Fortran function" */
    fn = elt(env, 10); /* prin2t */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    goto v77;

v77:
    v145 = qvalue(elt(env, 6)); /* !*double */
    if (v145 == nil) goto v138;
    v150 = stack[0];
    v145 = elt(env, 7); /* !*doublename!* */
    v145 = get(v150, v145);
    if (v145 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v145); }

v138:
    v150 = stack[0];
    v145 = elt(env, 8); /* !*fortranname!* */
    v145 = get(v150, v145);
    if (v145 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v145); }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for collectphystype */

static Lisp_Object CC_collectphystype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectphystype");
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
    v69 = stack[0];
    fn = elt(env, 2); /* physopp */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    if (v69 == nil) goto v7;
    v69 = stack[0];
    fn = elt(env, 3); /* getphystype */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v145;
    popv(5);
    return ncons(v69);

v7:
    v69 = stack[0];
    if (!consp(v69)) goto v97;
    v69 = stack[0];
    stack[-3] = v69;
    v69 = stack[-3];
    if (v69 == nil) goto v114;
    v69 = stack[-3];
    v69 = qcar(v69);
    fn = elt(env, 3); /* getphystype */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-1] = v69;
    stack[-2] = v69;
    goto v134;

v134:
    v69 = stack[-3];
    v69 = qcdr(v69);
    stack[-3] = v69;
    v69 = stack[-3];
    if (v69 == nil) goto v127;
    stack[0] = stack[-1];
    v69 = stack[-3];
    v69 = qcar(v69);
    fn = elt(env, 3); /* getphystype */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v69 = Lrplacd(nil, stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v69 = stack[-1];
    v69 = qcdr(v69);
    stack[-1] = v69;
    goto v134;

v127:
    v69 = stack[-2];
    goto v133;

v133:
    {
        popv(5);
        fn = elt(env, 4); /* deletemult!* */
        return (*qfn1(fn))(qenv(fn), v69);
    }

v114:
    v69 = qvalue(elt(env, 1)); /* nil */
    goto v133;

v97:
    v69 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v69); }
/* error exit handlers */
v145:
    popv(5);
    return nil;
}



/* Code for mktails1 */

static Lisp_Object MS_CDECL CC_mktails1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v108, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v243, v244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktails1");
#endif
    if (stack >= stacklimit)
    {
        push3(v108,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    v214 = v1;
    stack[-1] = v0;
/* end of prologue */
    v243 = stack[-1];
    fn = elt(env, 3); /* getroad */
    v214 = (*qfn2(fn))(qenv(fn), v243, v214);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-3];
    v243 = v214;
    v244 = (Lisp_Object)1; /* 0 */
    v214 = v243;
    if (v244 == v214) goto v140;
    v244 = (Lisp_Object)1; /* 0 */
    v214 = stack[-1];
    v214 = qcdr(v214);
    if (v244 == v214) goto v68;
    v244 = stack[-1];
    v214 = stack[0];
    v214 = Lassoc(nil, v244, v214);
    v244 = v214;
    v214 = v244;
    if (v214 == nil) goto v144;
    v214 = v244;
    v214 = qcdr(v214);
    v214 = qcdr(v214);
    if (v214 == nil) goto v229;
    v214 = v244;
    v214 = qcdr(v214);
    v243 = Lreverse(nil, v214);
    nil = C_nil;
    if (exception_pending()) goto v245;
    v214 = stack[0];
    popv(4);
    return cons(v243, v214);

v229:
    v214 = v244;
    v243 = qcdr(v214);
    v214 = stack[0];
    popv(4);
    return cons(v243, v214);

v144:
    v214 = stack[-1];
    fn = elt(env, 4); /* mkinds */
    v214 = (*qfn2(fn))(qenv(fn), v214, v243);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-3];
    v244 = v214;
    stack[-2] = v244;
    v214 = stack[-1];
    v243 = v244;
    v243 = cons(v214, v243);
    nil = C_nil;
    if (exception_pending()) goto v245;
    v214 = stack[0];
    {
        Lisp_Object v246 = stack[-2];
        popv(4);
        return list2star(v246, v243, v214);
    }

v68:
    v214 = stack[-1];
    v243 = qcar(v214);
    v214 = elt(env, 2); /* replace_by_vector */
    v214 = get(v243, v214);
    env = stack[-3];
    if (!(v214 == nil)) goto v137;
    v214 = stack[-1];
    v214 = qcar(v214);
    goto v137;

v137:
    v243 = ncons(v214);
    nil = C_nil;
    if (exception_pending()) goto v245;
    v214 = stack[0];
    popv(4);
    return cons(v243, v214);

v140:
    v243 = qvalue(elt(env, 1)); /* nil */
    v214 = stack[0];
    popv(4);
    return cons(v243, v214);
/* error exit handlers */
v245:
    popv(4);
    return nil;
}



/* Code for mv!-domainlist */

static Lisp_Object CC_mvKdomainlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist");
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
    v122 = nil;
    goto v7;

v7:
    v114 = stack[0];
    if (v114 == nil) goto v12;
    v114 = stack[0];
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = cons(v114, v122);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-1];
    v122 = v114;
    v114 = stack[0];
    v114 = qcdr(v114);
    stack[0] = v114;
    goto v7;

v12:
    v114 = v122;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v114);
    }
/* error exit handlers */
v117:
    popv(2);
    return nil;
}



/* Code for fs!:prin1 */

static Lisp_Object CC_fsTprin1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v251;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin1");
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
    v250 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v250;
    v251 = stack[0];
    v250 = (Lisp_Object)1; /* 0 */
    v251 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v250/(16/CELL)));
    v250 = elt(env, 2); /* (1 . 1) */
    if (equal(v251, v250)) goto v2;
    v250 = elt(env, 3); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    v251 = stack[0];
    v250 = (Lisp_Object)1; /* 0 */
    v250 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v250/(16/CELL)));
    fn = elt(env, 13); /* sqprint */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    v250 = elt(env, 4); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    goto v2;

v2:
    v250 = stack[0];
    fn = elt(env, 14); /* fs!:null!-angle */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    if (v250 == nil) goto v179;
    v251 = stack[0];
    v250 = (Lisp_Object)1; /* 0 */
    v251 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v250/(16/CELL)));
    v250 = elt(env, 2); /* (1 . 1) */
    if (!(equal(v251, v250))) goto v132;
    v250 = elt(env, 11); /* "1" */
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    goto v132;

v132:
    v250 = nil;
    { popv(5); return onevalue(v250); }

v179:
    v251 = stack[0];
    v250 = (Lisp_Object)17; /* 1 */
    v250 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v250/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    v250 = elt(env, 5); /* "[" */
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    v251 = stack[0];
    v250 = (Lisp_Object)33; /* 2 */
    v250 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v250/(16/CELL)));
    stack[-2] = v250;
    v250 = (Lisp_Object)1; /* 0 */
    stack[0] = v250;
    goto v65;

v65:
    v251 = (Lisp_Object)113; /* 7 */
    v250 = stack[0];
    v250 = difference2(v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    v250 = Lminusp(nil, v250);
    env = stack[-4];
    if (v250 == nil) goto v147;
    v250 = elt(env, 10); /* "]" */
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    goto v132;

v147:
    v251 = stack[-2];
    v250 = stack[0];
    v251 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v250/(16/CELL)));
    stack[-1] = v251;
    v250 = (Lisp_Object)1; /* 0 */
    if (v251 == v250) goto v63;
    v251 = stack[-1];
    v250 = (Lisp_Object)1; /* 0 */
    v250 = (Lisp_Object)lessp2(v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v250 = v250 ? lisp_true : nil;
    env = stack[-4];
    if (v250 == nil) goto v142;
    v250 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v250;
    v250 = elt(env, 7); /* "-" */
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    v250 = stack[-1];
    v250 = negate(v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    stack[-1] = v250;
    goto v142;

v142:
    v250 = stack[-3];
    if (!(v250 == nil)) goto v238;
    v250 = elt(env, 8); /* "+" */
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    goto v238;

v238:
    v251 = stack[-1];
    v250 = (Lisp_Object)17; /* 1 */
    if (v251 == v250) goto v215;
    v250 = stack[-1];
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    goto v215;

v215:
    v250 = qvalue(elt(env, 6)); /* nil */
    stack[-3] = v250;
    v251 = qvalue(elt(env, 9)); /* fourier!-name!* */
    v250 = stack[0];
    v250 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v250/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    goto v63;

v63:
    v250 = stack[0];
    v250 = add1(v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-4];
    stack[0] = v250;
    goto v65;
/* error exit handlers */
v252:
    popv(5);
    return nil;
}



/* Code for inprint */

static Lisp_Object MS_CDECL CC_inprint(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v108, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v275, v276, v277, v278;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprint");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inprint");
#endif
    if (stack >= stacklimit)
    {
        push3(v108,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v276 = stack[-2];
    v275 = elt(env, 1); /* times */
    if (!(v276 == v275)) goto v69;
    v275 = qvalue(elt(env, 2)); /* !*nat */
    if (v275 == nil) goto v69;
    v275 = qvalue(elt(env, 3)); /* !*asterisk */
    if (!(v275 == nil)) goto v69;
    v275 = elt(env, 4); /* times2 */
    stack[-2] = v275;
    v278 = elt(env, 4); /* times2 */
    v277 = elt(env, 5); /* infix */
    v276 = elt(env, 1); /* times */
    v275 = elt(env, 5); /* infix */
    v275 = get(v276, v275);
    env = stack[-4];
    v275 = Lputprop(nil, 3, v278, v277, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v277 = elt(env, 4); /* times2 */
    v276 = elt(env, 6); /* prtch */
    v275 = elt(env, 7); /* " " */
    v275 = Lputprop(nil, 3, v277, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v69;

v69:
    v276 = stack[-2];
    v275 = elt(env, 8); /* plus */
    if (!(v276 == v275)) goto v107;
    v275 = qvalue(elt(env, 9)); /* !*revpri */
    if (v275 == nil) goto v107;
    v275 = stack[0];
    v275 = Lreverse(nil, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    stack[0] = v275;
    goto v107;

v107:
    v276 = stack[-2];
    v275 = elt(env, 10); /* alt */
    v275 = get(v276, v275);
    env = stack[-4];
    if (!(v275 == nil)) goto v153;
    v276 = stack[-2];
    v275 = elt(env, 11); /* not */
    if (v276 == v275) goto v61;
    v276 = stack[-2];
    v275 = elt(env, 12); /* setq */
    if (!(v276 == v275)) goto v63;
    v275 = stack[0];
    v275 = Lreverse(nil, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v275 = qcar(v275);
    stack[-3] = v275;
    if (!consp(v275)) goto v63;
    v275 = stack[-3];
    v275 = qcar(v275);
    if (!(symbolp(v275))) goto v63;
    v275 = stack[-3];
    fn = elt(env, 24); /* getrtype */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v276 = v275;
    if (v275 == nil) goto v63;
    v275 = elt(env, 13); /* tag */
    v276 = get(v276, v275);
    env = stack[-4];
    v275 = elt(env, 14); /* setprifn */
    v275 = get(v276, v275);
    env = stack[-4];
    v276 = v275;
    if (v275 == nil) goto v63;
    v277 = v276;
    v275 = stack[0];
    v276 = qcar(v275);
    v275 = stack[-3];
        popv(5);
        return Lapply2(nil, 3, v277, v276, v275);

v63:
    v275 = stack[0];
    v275 = qcar(v275);
    if (!consp(v275)) goto v49;
    v275 = stack[0];
    v275 = qcar(v275);
    v275 = qcar(v275);
    if (!(symbolp(v275))) goto v49;
    v275 = qvalue(elt(env, 2)); /* !*nat */
    if (v275 == nil) goto v49;
    v275 = stack[0];
    v275 = qcar(v275);
    v276 = qcar(v275);
    v275 = elt(env, 15); /* prifn */
    v275 = get(v276, v275);
    env = stack[-4];
    stack[-3] = v275;
    if (!(v275 == nil)) goto v280;
    v275 = stack[0];
    v275 = qcar(v275);
    v276 = qcar(v275);
    v275 = elt(env, 16); /* pprifn */
    v275 = get(v276, v275);
    env = stack[-4];
    stack[-3] = v275;
    if (!(v275 == nil)) goto v280;

v49:
    v275 = qvalue(elt(env, 20)); /* !*nosplit */
    if (v275 == nil) goto v281;
    v275 = qvalue(elt(env, 21)); /* testing!-width!* */
    if (!(v275 == nil)) goto v281;
    v275 = stack[0];
    v277 = qcar(v275);
    v276 = stack[-1];
    v275 = qvalue(elt(env, 22)); /* nil */
    fn = elt(env, 25); /* prinfit */
    v275 = (*qfnn(fn))(qenv(fn), 3, v277, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v246;

v246:
    v275 = stack[0];
    v275 = qcdr(v275);
    stack[0] = v275;
    goto v153;

v153:
    v275 = qvalue(elt(env, 20)); /* !*nosplit */
    if (v275 == nil) goto v282;
    v275 = qvalue(elt(env, 21)); /* testing!-width!* */
    if (!(v275 == nil)) goto v282;
    v275 = stack[0];
    stack[-3] = v275;
    goto v28;

v28:
    v275 = stack[-3];
    if (v275 == nil) goto v283;
    v275 = stack[-3];
    v275 = qcar(v275);
    stack[0] = v275;
    v275 = stack[0];
    if (!consp(v275)) goto v284;
    v277 = stack[-2];
    v275 = stack[0];
    v276 = qcar(v275);
    v275 = elt(env, 10); /* alt */
    v275 = get(v276, v275);
    env = stack[-4];
    if (!(v277 == v275)) goto v284;
    v277 = stack[0];
    v276 = stack[-1];
    v275 = qvalue(elt(env, 22)); /* nil */
    fn = elt(env, 25); /* prinfit */
    v275 = (*qfnn(fn))(qenv(fn), 3, v277, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v31;

v31:
    v275 = stack[-3];
    v275 = qcdr(v275);
    stack[-3] = v275;
    goto v28;

v284:
    v276 = stack[-2];
    v275 = elt(env, 23); /* (setq !*comma!*) */
    v275 = Lmemq(nil, v276, v275);
    if (v275 == nil) goto v187;
    v275 = stack[-2];
    fn = elt(env, 26); /* oprin */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v275 = stack[0];
    fn = elt(env, 27); /* negnumberchk */
    v277 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v276 = stack[-1];
    v275 = qvalue(elt(env, 22)); /* nil */
    fn = elt(env, 25); /* prinfit */
    v275 = (*qfnn(fn))(qenv(fn), 3, v277, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v31;

v187:
    v275 = stack[0];
    fn = elt(env, 27); /* negnumberchk */
    v277 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v276 = stack[-1];
    v275 = stack[-2];
    fn = elt(env, 25); /* prinfit */
    v275 = (*qfnn(fn))(qenv(fn), 3, v277, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v31;

v283:
    v275 = nil;
    { popv(5); return onevalue(v275); }

v282:
    v275 = stack[0];
    stack[-3] = v275;
    goto v15;

v15:
    v275 = stack[-3];
    if (v275 == nil) goto v283;
    v275 = stack[-3];
    v275 = qcar(v275);
    stack[0] = v275;
    v275 = stack[0];
    if (!consp(v275)) goto v8;
    v277 = stack[-2];
    v275 = stack[0];
    v276 = qcar(v275);
    v275 = elt(env, 10); /* alt */
    v275 = get(v276, v275);
    env = stack[-4];
    if (!(v277 == v275)) goto v8;
    v276 = stack[0];
    v275 = stack[-1];
    fn = elt(env, 28); /* maprint */
    v275 = (*qfn2(fn))(qenv(fn), v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v285;

v285:
    v275 = stack[-3];
    v275 = qcdr(v275);
    stack[-3] = v275;
    goto v15;

v8:
    v275 = stack[-2];
    fn = elt(env, 26); /* oprin */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v275 = stack[0];
    fn = elt(env, 27); /* negnumberchk */
    v276 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v275 = stack[-1];
    fn = elt(env, 28); /* maprint */
    v275 = (*qfn2(fn))(qenv(fn), v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v285;

v281:
    v275 = stack[0];
    v276 = qcar(v275);
    v275 = stack[-1];
    fn = elt(env, 28); /* maprint */
    v275 = (*qfn2(fn))(qenv(fn), v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v246;

v280:
    v276 = stack[-3];
    v275 = stack[-2];
    v276 = get(v276, v275);
    env = stack[-4];
    v275 = elt(env, 17); /* inbrackets */
    if (!(v276 == v275)) goto v49;
    v275 = elt(env, 18); /* "(" */
    fn = elt(env, 29); /* prin2!* */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v275 = stack[0];
    v276 = qcar(v275);
    v275 = stack[-1];
    fn = elt(env, 28); /* maprint */
    v275 = (*qfn2(fn))(qenv(fn), v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v275 = elt(env, 19); /* ")" */
    fn = elt(env, 29); /* prin2!* */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v246;

v61:
    v275 = stack[-2];
    fn = elt(env, 26); /* oprin */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    goto v63;
/* error exit handlers */
v279:
    popv(5);
    return nil;
}



/* Code for splitlist!: */

static Lisp_Object CC_splitlistT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v127, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitlist:");
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
    v154 = nil;
    goto v41;

v41:
    v132 = stack[-1];
    if (v132 == nil) goto v2;
    v132 = stack[-1];
    v127 = qcar(v132);
    v132 = stack[0];
    if (!consp(v127)) goto v120;
    v127 = qcar(v127);
    if (!(v127 == v132)) goto v120;
    v132 = stack[-1];
    v132 = qcar(v132);
    v127 = v154;
    v132 = cons(v132, v127);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    v154 = v132;
    v132 = stack[-1];
    v132 = qcdr(v132);
    stack[-1] = v132;
    goto v41;

v120:
    v132 = stack[-1];
    v132 = qcdr(v132);
    stack[-1] = v132;
    goto v41;

v2:
    v132 = v154;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v132);
    }
/* error exit handlers */
v101:
    popv(3);
    return nil;
}



/* Code for reduce!-degree!-mod!-p */

static Lisp_Object CC_reduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v216, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-degree-mod-p");
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
    v184 = stack[-1];
    v184 = qcar(v184);
    v184 = qcdr(v184);
    {   int32_t w = int_of_fixnum(v184);
        if (w != 0) w = current_modulus - w;
        v216 = fixnum_of_int(w);
    }
    v184 = stack[0];
    v184 = qcar(v184);
    v184 = qcdr(v184);
    v184 = Lmodular_quotient(nil, v216, v184);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    stack[-2] = v184;
    v184 = stack[-1];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v216 = qcdr(v184);
    v184 = stack[0];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v184 = qcdr(v184);
    v184 = (Lisp_Object)(int32_t)((int32_t)v216 - (int32_t)v184 + TAG_FIXNUM);
    v217 = v184;
    v216 = v217;
    v184 = (Lisp_Object)1; /* 0 */
    if (v216 == v184) goto v179;
    v184 = stack[-1];
    stack[-1] = qcdr(v184);
    v184 = stack[0];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v184 = qcar(v184);
    v216 = v217;
    fn = elt(env, 1); /* mksp */
    v216 = (*qfn2(fn))(qenv(fn), v184, v216);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v184 = stack[-2];
    v216 = cons(v216, v184);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v184 = stack[0];
    v184 = qcdr(v184);
    fn = elt(env, 2); /* times!-term!-mod!-p */
    v184 = (*qfn2(fn))(qenv(fn), v216, v184);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    {
        Lisp_Object v116 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v116, v184);
    }

v179:
    v184 = stack[-1];
    stack[-1] = qcdr(v184);
    v184 = stack[0];
    v216 = qcdr(v184);
    v184 = stack[-2];
    fn = elt(env, 4); /* multiply!-by!-constant!-mod!-p */
    v184 = (*qfn2(fn))(qenv(fn), v216, v184);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    {
        Lisp_Object v230 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v230, v184);
    }
/* error exit handlers */
v115:
    popv(4);
    return nil;
}



/* Code for xxsort */

static Lisp_Object CC_xxsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xxsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v0;
/* end of prologue */
    v97 = v90;
    v90 = elt(env, 1); /* lambda_l7fvjw_2 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v97, v90);
    }
}



/* Code for lambda_l7fvjw_2 */

static Lisp_Object CC_lambda_l7fvjw_2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l7fvjw_2");
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
    v139 = v1;
    v192 = v0;
/* end of prologue */
    v192 = qcar(v192);
    v139 = qcar(v139);
    fn = elt(env, 1); /* termorder */
    v192 = (*qfn2(fn))(qenv(fn), v192, v139);
    errexit();
    v139 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v192, v139);
}



/* Code for expnd1 */

static Lisp_Object CC_expnd1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expnd1");
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
    goto v41;

v41:
    v188 = stack[-1];
    if (!consp(v188)) goto v20;
    v188 = stack[-1];
    v188 = qcar(v188);
    if (!consp(v188)) goto v20;
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcar(v188);
    fn = elt(env, 1); /* sfp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    if (v188 == nil) goto v106;
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v96 = qcdr(v188);
    v188 = (Lisp_Object)1; /* 0 */
    v188 = (Lisp_Object)lessp2(v96, v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v188 = v188 ? lisp_true : nil;
    env = stack[-3];
    if (!(v188 == nil)) goto v106;
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcar(v188);
    v96 = CC_expnd1(env, v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcdr(v188);
    fn = elt(env, 2); /* exptf */
    stack[0] = (*qfn2(fn))(qenv(fn), v96, v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcdr(v188);
    v188 = CC_expnd1(env, v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v188 = (*qfn2(fn))(qenv(fn), stack[0], v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v96 = v188;
    goto v192;

v192:
    v188 = stack[-2];
    v188 = cons(v96, v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    stack[-2] = v188;
    v188 = stack[-1];
    v188 = qcdr(v188);
    stack[-1] = v188;
    goto v41;

v106:
    v188 = stack[-1];
    v188 = qcar(v188);
    v96 = qcar(v188);
    v188 = (Lisp_Object)17; /* 1 */
    v188 = cons(v96, v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    stack[0] = ncons(v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcdr(v188);
    v188 = CC_expnd1(env, v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v188 = (*qfn2(fn))(qenv(fn), stack[0], v188);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v96 = v188;
    goto v192;

v20:
    v188 = stack[-1];
    v96 = v188;
    goto v12;

v12:
    v188 = stack[-2];
    if (v188 == nil) { popv(4); return onevalue(v96); }
    v188 = stack[-2];
    v188 = qcar(v188);
    fn = elt(env, 4); /* addf */
    v188 = (*qfn2(fn))(qenv(fn), v188, v96);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v96 = v188;
    v188 = stack[-2];
    v188 = qcdr(v188);
    stack[-2] = v188;
    goto v12;
/* error exit handlers */
v175:
    popv(4);
    return nil;
}



/* Code for ibalp_readclause */

static Lisp_Object CC_ibalp_readclause(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v296, v194, v195, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_readclause");
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
    v296 = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v296 = qcdr(v296);
    stack[-4] = v296;
    stack[-5] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 1)); /* nil */
    stack[0] = (Lisp_Object)1; /* 0 */
    v160 = (Lisp_Object)1; /* 0 */
    v195 = qvalue(elt(env, 1)); /* nil */
    v194 = qvalue(elt(env, 1)); /* nil */
    v296 = qvalue(elt(env, 1)); /* nil */
    v296 = list4(v160, v195, v194, v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    v296 = list3star(stack[-5], stack[-1], stack[0], v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    stack[-5] = v296;
    v296 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v296;
    goto v101;

v101:
    v296 = stack[-1];
    if (v296 == nil) goto v80;
    v296 = stack[-4];
    if (v296 == nil) goto v80;
    v296 = stack[-4];
    v296 = qcar(v296);
    stack[-8] = v296;
    v194 = stack[-8];
    v296 = elt(env, 3); /* true */
    if (v194 == v296) goto v68;
    v296 = stack[-4];
    v296 = qcdr(v296);
    stack[-4] = v296;
    v194 = stack[-8];
    v296 = elt(env, 4); /* false */
    if (v194 == v296) goto v101;
    v296 = stack[-8];
    if (!consp(v296)) goto v59;
    v296 = stack[-8];
    v296 = qcar(v296);
    v194 = v296;
    goto v79;

v79:
    v296 = elt(env, 5); /* not */
    if (v194 == v296) goto v62;
    v296 = stack[-8];
    fn = elt(env, 6); /* ibalp_arg2l */
    v296 = (*qfn1(fn))(qenv(fn), v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    stack[-6] = v296;
    v296 = stack[-8];
    fn = elt(env, 7); /* ibalp_arg2r */
    v296 = (*qfn1(fn))(qenv(fn), v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    goto v171;

v171:
    v194 = v296;
    v296 = (Lisp_Object)17; /* 1 */
    v296 = Leqn(nil, v194, v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    if (v296 == nil) goto v297;
    v194 = stack[-6];
    v296 = stack[-3];
    v296 = Lmemq(nil, v194, v296);
    if (!(v296 == nil)) goto v101;
    v296 = stack[-5];
    v296 = qcdr(v296);
    stack[0] = qcdr(v296);
    v296 = stack[-5];
    v296 = qcdr(v296);
    v296 = qcdr(v296);
    v296 = qcar(v296);
    v296 = add1(v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    fn = elt(env, 8); /* setcar */
    v296 = (*qfn2(fn))(qenv(fn), stack[0], v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    v194 = stack[-6];
    v296 = stack[-3];
    v296 = cons(v194, v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    stack[-3] = v296;
    v160 = stack[-5];
    v195 = stack[-7];
    v194 = stack[-6];
    v296 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* ibalp_process!-var */
    v296 = (*qfnn(fn))(qenv(fn), 4, v160, v195, v194, v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    stack[-7] = v296;
    goto v101;

v297:
    v194 = stack[-6];
    v296 = stack[-2];
    v296 = Lmemq(nil, v194, v296);
    if (!(v296 == nil)) goto v101;
    v296 = stack[-5];
    v296 = qcdr(v296);
    v296 = qcdr(v296);
    stack[0] = qcdr(v296);
    v296 = stack[-5];
    v296 = qcdr(v296);
    v296 = qcdr(v296);
    v296 = qcdr(v296);
    v296 = qcar(v296);
    v296 = add1(v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    fn = elt(env, 8); /* setcar */
    v296 = (*qfn2(fn))(qenv(fn), stack[0], v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    v194 = stack[-6];
    v296 = stack[-2];
    v296 = cons(v194, v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    stack[-2] = v296;
    v160 = stack[-5];
    v195 = stack[-7];
    v194 = stack[-6];
    v296 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 9); /* ibalp_process!-var */
    v296 = (*qfnn(fn))(qenv(fn), 4, v160, v195, v194, v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    stack[-7] = v296;
    goto v101;

v62:
    v296 = stack[-8];
    v296 = qcdr(v296);
    v296 = qcar(v296);
    fn = elt(env, 6); /* ibalp_arg2l */
    v296 = (*qfn1(fn))(qenv(fn), v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    stack[-6] = v296;
    stack[0] = (Lisp_Object)17; /* 1 */
    v296 = stack[-8];
    v296 = qcdr(v296);
    v296 = qcar(v296);
    fn = elt(env, 7); /* ibalp_arg2r */
    v296 = (*qfn1(fn))(qenv(fn), v296);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-9];
    v296 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v296 + TAG_FIXNUM);
    goto v171;

v59:
    v296 = stack[-8];
    v194 = v296;
    goto v79;

v68:
    v296 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v296;
    goto v101;

v80:
    v296 = stack[-1];
    if (v296 == nil) goto v298;
    v194 = stack[-5];
    v296 = stack[-7];
    popv(10);
    return cons(v194, v296);

v298:
    v194 = elt(env, 3); /* true */
    v296 = stack[-7];
    popv(10);
    return cons(v194, v296);
/* error exit handlers */
v221:
    popv(10);
    return nil;
}



/* Code for aex_mk */

static Lisp_Object MS_CDECL CC_aex_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v108, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v114, v122, v140;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "aex_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mk");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v108,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v108,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v70 = v3;
    v114 = v108;
    v122 = v1;
    v140 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v140;
    stack[0] = v122;
    v70 = list2(v114, v70);
    nil = C_nil;
    if (exception_pending()) goto v73;
    {
        Lisp_Object v71 = stack[-2];
        Lisp_Object v125 = stack[-1];
        Lisp_Object v120 = stack[0];
        popv(3);
        return list3star(v71, v125, v120, v70);
    }
/* error exit handlers */
v73:
    popv(3);
    return nil;
}



/* Code for getsetvars */

static Lisp_Object CC_getsetvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getsetvars");
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
    goto v7;

v7:
    v103 = stack[0];
    if (!consp(v103)) goto v12;
    v103 = stack[0];
    v104 = qcar(v103);
    v103 = elt(env, 1); /* (setel setk) */
    v103 = Lmemq(nil, v104, v103);
    if (v103 == nil) goto v127;
    v103 = stack[0];
    v103 = qcdr(v103);
    v103 = qcar(v103);
    fn = elt(env, 3); /* getsetvarlis */
    v104 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v103 = stack[-1];
    v103 = cons(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v103;
    v103 = stack[0];
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    v103 = qcar(v103);
    stack[0] = v103;
    goto v7;

v127:
    v103 = stack[0];
    v104 = qcar(v103);
    v103 = elt(env, 2); /* setq */
    if (v104 == v103) goto v135;
    v103 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v103);
    }

v135:
    v103 = stack[0];
    v103 = qcdr(v103);
    v103 = qcar(v103);
    v104 = Lmkquote(nil, v103);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v103 = stack[-1];
    v103 = cons(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v103;
    v103 = stack[0];
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    v103 = qcar(v103);
    stack[0] = v103;
    goto v7;

v12:
    v103 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v103);
    }
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for dipev2f */

static Lisp_Object CC_dipev2f(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipev2f");
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

v7:
    v180 = stack[-1];
    if (v180 == nil) goto v12;
    v180 = stack[-1];
    v112 = qcar(v180);
    v180 = (Lisp_Object)1; /* 0 */
    if (v112 == v180) goto v149;
    v180 = stack[0];
    v112 = qcar(v180);
    v180 = stack[-1];
    v180 = qcar(v180);
    fn = elt(env, 1); /* to */
    v112 = (*qfn2(fn))(qenv(fn), v112, v180);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    v180 = (Lisp_Object)17; /* 1 */
    v180 = cons(v112, v180);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    stack[-2] = ncons(v180);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    v180 = stack[-1];
    v112 = qcdr(v180);
    v180 = stack[0];
    v180 = qcdr(v180);
    v180 = CC_dipev2f(env, v112, v180);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-3];
    {
        Lisp_Object v103 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* multf */
        return (*qfn2(fn))(qenv(fn), v103, v180);
    }

v149:
    v180 = stack[-1];
    v180 = qcdr(v180);
    stack[-1] = v180;
    v180 = stack[0];
    v180 = qcdr(v180);
    stack[0] = v180;
    goto v7;

v12:
    v180 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v180); }
/* error exit handlers */
v64:
    popv(4);
    return nil;
}



/* Code for my_freeof */

static Lisp_Object CC_my_freeof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v117, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my_freeof");
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
    v117 = stack[0];
    v140 = stack[-1];
    fn = elt(env, 3); /* smember */
    v140 = (*qfn2(fn))(qenv(fn), v117, v140);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    if (v140 == nil) goto v222;
    v140 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v140); }

v222:
    v124 = qvalue(elt(env, 2)); /* depl!* */
    v117 = stack[-1];
    v140 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeofdepl */
        return (*qfnn(fn))(qenv(fn), 3, v124, v117, v140);
    }
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for setk */

static Lisp_Object CC_setk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v54, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setk");
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
    v54 = v0;
/* end of prologue */
    v142 = v54;
    if (!consp(v142)) goto v183;
    v142 = v54;
    v115 = qcar(v142);
    v142 = elt(env, 1); /* evalargfn */
    v142 = get(v115, v142);
    env = stack[-2];
    v115 = v142;
    v142 = v115;
    if (v142 == nil) goto v151;
    v142 = v54;
    stack[-1] = qcar(v142);
    v142 = v115;
    v54 = qcdr(v54);
    v142 = Lapply1(nil, v142, v54);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-2];
    v54 = cons(stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-2];
    v142 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v54, v142);
    }

v151:
    v142 = v54;
    v115 = qcar(v142);
    v142 = elt(env, 2); /* rtype */
    v115 = get(v115, v142);
    env = stack[-2];
    v142 = elt(env, 3); /* matrix */
    if (v115 == v142) goto v64;
    v142 = v54;
    stack[-1] = qcar(v142);
    v142 = v54;
    v142 = qcdr(v142);
    fn = elt(env, 5); /* revlis */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-2];
    v54 = cons(stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-2];
    v142 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v54, v142);
    }

v64:
    v142 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v54, v142);
    }

v183:
    v142 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v54, v142);
    }
/* error exit handlers */
v178:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-mv!-!+ */

static Lisp_Object CC_mvKpowKmvKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-+");
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
    goto v41;

v41:
    v71 = stack[0];
    if (v71 == nil) goto v2;
    v125 = stack[-1];
    v71 = stack[0];
    v71 = qcar(v71);
    fn = elt(env, 1); /* mv!-pow!-mv!-term!-!+ */
    v125 = (*qfn2(fn))(qenv(fn), v125, v71);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v71 = stack[-2];
    v71 = cons(v125, v71);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    stack[-2] = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v41;

v2:
    v71 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v71);
    }
/* error exit handlers */
v131:
    popv(4);
    return nil;
}



/* Code for !:rn2rd */

static Lisp_Object CC_Trn2rd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :rn2rd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v119 = v0;
/* end of prologue */
    v129 = qvalue(elt(env, 1)); /* !*roundall */
    if (v129 == nil) return onevalue(v119);
    v129 = qvalue(elt(env, 2)); /* !*rounded */
    if (v129 == nil) return onevalue(v119);
    v129 = v119;
    {
        fn = elt(env, 3); /* !*rn2rd */
        return (*qfn1(fn))(qenv(fn), v129);
    }
}



/* Code for red!=cancelsimp */

static Lisp_Object CC_redMcancelsimp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=cancelsimp");
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
    v124 = stack[-1];
    v117 = stack[0];
    fn = elt(env, 2); /* red_better */
    v117 = (*qfn2(fn))(qenv(fn), v124, v117);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    if (v117 == nil) goto v7;
    v117 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    fn = elt(env, 4); /* dp_lmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v117 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    fn = elt(env, 4); /* dp_lmon */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    {
        Lisp_Object v125 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* mo_vdivides!? */
        return (*qfn2(fn))(qenv(fn), v125, v117);
    }

v7:
    v117 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v117); }
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for idcons_ordp */

static Lisp_Object CC_idcons_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v129, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idcons_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v152 = v1;
    v129 = v0;
/* end of prologue */
    v119 = v129;
    v129 = v152;
    v152 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v119, v129, v152);
    }
}



/* Code for b!:ordexp */

static Lisp_Object CC_bTordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v80;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:ordexp");
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

v7:
    v155 = stack[-1];
    if (v155 == nil) goto v12;
    v155 = stack[-1];
    v80 = qcar(v155);
    v155 = stack[0];
    v155 = qcar(v155);
    v155 = (Lisp_Object)greaterp2(v80, v155);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v155 = v155 ? lisp_true : nil;
    env = stack[-2];
    if (v155 == nil) goto v114;
    v155 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v155); }

v114:
    v155 = stack[-1];
    v80 = qcar(v155);
    v155 = stack[0];
    v155 = qcar(v155);
    if (equal(v80, v155)) goto v105;
    v155 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v155); }

v105:
    v155 = stack[-1];
    v155 = qcdr(v155);
    stack[-1] = v155;
    v155 = stack[0];
    v155 = qcdr(v155);
    stack[0] = v155;
    goto v7;

v12:
    v155 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v155); }
/* error exit handlers */
v102:
    popv(3);
    return nil;
}



/* Code for horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_hornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v108, Lisp_Object v3,
                         Lisp_Object v60, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v300, v248, v239, v240, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push5(v60,v3,v108,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v108,v3,v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v60;
    stack[-3] = v3;
    stack[-4] = v108;
    v239 = v1;
    v240 = v0;
/* end of prologue */

v148:
    v300 = stack[-4];
    if (!consp(v300)) goto v12;
    v300 = stack[-4];
    v300 = qcar(v300);
    if (!consp(v300)) goto v12;
    v300 = stack[-4];
    v300 = qcar(v300);
    v300 = qcar(v300);
    v248 = qcar(v300);
    v300 = stack[-2];
    if (!(equal(v248, v300))) goto v12;
    v300 = stack[-4];
    v300 = qcar(v300);
    v300 = qcar(v300);
    v300 = qcdr(v300);
    stack[-5] = v300;
    v300 = stack[-3];
    if (v300 == nil) goto v61;
    v300 = stack[-3];
    v300 = (Lisp_Object)zerop(v300);
    v300 = v300 ? lisp_true : nil;
    env = stack[-6];
    if (!(v300 == nil)) goto v61;
    v300 = stack[-4];
    v300 = qcar(v300);
    stack[-1] = qcdr(v300);
    stack[0] = v240;
    v248 = stack[-3];
    v300 = stack[-5];
    v300 = (Lisp_Object)(int32_t)((int32_t)v239 - (int32_t)v300 + TAG_FIXNUM);
    fn = elt(env, 1); /* expt!-mod!-p */
    v300 = (*qfn2(fn))(qenv(fn), v248, v300);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-6];
    fn = elt(env, 2); /* times!-mod!-p */
    v300 = (*qfn2(fn))(qenv(fn), stack[0], v300);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-6];
    fn = elt(env, 3); /* plus!-mod!-p */
    v300 = (*qfn2(fn))(qenv(fn), stack[-1], v300);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-6];
    v240 = v300;
    goto v67;

v67:
    v239 = stack[-5];
    v300 = stack[-4];
    v173 = qcdr(v300);
    v248 = stack[-3];
    v300 = stack[-2];
    stack[-4] = v173;
    stack[-3] = v248;
    stack[-2] = v300;
    goto v148;

v61:
    v300 = stack[-4];
    v300 = qcar(v300);
    v300 = qcdr(v300);
    v240 = v300;
    goto v67;

v12:
    v300 = stack[-3];
    if (v300 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v300 = stack[-3];
    v300 = (Lisp_Object)zerop(v300);
    v300 = v300 ? lisp_true : nil;
    env = stack[-6];
    if (!(v300 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v240;
    v300 = stack[-3];
    v248 = v239;
    fn = elt(env, 1); /* expt!-mod!-p */
    v300 = (*qfn2(fn))(qenv(fn), v300, v248);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-6];
    fn = elt(env, 2); /* times!-mod!-p */
    v300 = (*qfn2(fn))(qenv(fn), stack[0], v300);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-6];
    v240 = v300;
    v300 = stack[-4];
    v248 = v240;
    {
        popv(7);
        fn = elt(env, 3); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v300, v248);
    }
/* error exit handlers */
v245:
    popv(7);
    return nil;
}



/* Code for ofsf_smmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v108, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v127, v154, v155, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v154 = v3;
    v155 = v108;
    v80 = v1;
    v132 = v0;
/* end of prologue */
    v127 = v132;
    v132 = elt(env, 1); /* and */
    if (v127 == v132) goto v123;
    v132 = v80;
    v127 = v155;
    {
        fn = elt(env, 2); /* ofsf_smmkatl!-or */
        return (*qfnn(fn))(qenv(fn), 3, v132, v127, v154);
    }

v123:
    v132 = v80;
    v127 = v155;
    {
        fn = elt(env, 3); /* ofsf_smmkatl!-and */
        return (*qfnn(fn))(qenv(fn), 3, v132, v127, v154);
    }
}



/* Code for cl_apply2ats */

static Lisp_Object CC_cl_apply2ats(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v129, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_apply2ats");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v152 = v1;
    v129 = v0;
/* end of prologue */
    v119 = v129;
    v129 = v152;
    v152 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v119, v129, v152);
    }
}



/* Code for get_char_value */

static Lisp_Object CC_get_char_value(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_char_value");
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
    v113 = v0;
/* end of prologue */
    stack[-1] = nil;
    v112 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v112;
    v112 = v113;
    v112 = qcdr(v112);
    stack[0] = v112;
    goto v77;

v77:
    v112 = stack[-3];
    if (!(v112 == nil)) goto v149;
    v112 = stack[0];
    v113 = Llength(nil, v112);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    v112 = (Lisp_Object)1; /* 0 */
    v112 = (Lisp_Object)greaterp2(v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v112 = v112 ? lisp_true : nil;
    env = stack[-4];
    if (v112 == nil) goto v149;
    v112 = stack[0];
    v112 = qcar(v112);
    v113 = qcar(v112);
    v112 = stack[-2];
    if (!(equal(v113, v112))) goto v72;
    v112 = stack[0];
    v112 = qcar(v112);
    v112 = qcdr(v112);
    v112 = qcar(v112);
    stack[-1] = v112;
    v112 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v112;
    goto v72;

v72:
    v112 = stack[0];
    v112 = qcdr(v112);
    stack[0] = v112;
    goto v77;

v149:
    v112 = stack[-3];
    if (!(v112 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v112 = elt(env, 3); /* "error in get character element" */
    fn = elt(env, 4); /* rederr */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v112 = nil;
    { popv(5); return onevalue(v112); }
/* error exit handlers */
v104:
    popv(5);
    return nil;
}



setup_type const u16_setup[] =
{
    {"exptpri",                 too_few_2,      CC_exptpri,    wrong_no_2},
    {"simpg3",                  CC_simpg3,      too_many_1,    wrong_no_1},
    {"add-degrees",             too_few_2,      CC_addKdegrees,wrong_no_2},
    {"tmsf",                    CC_tmsf,        too_many_1,    wrong_no_1},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"tobvarir",                CC_tobvarir,    too_many_1,    wrong_no_1},
    {"diffsq",                  too_few_2,      CC_diffsq,     wrong_no_2},
    {"prin2t",                  CC_prin2t,      too_many_1,    wrong_no_1},
    {"rd:prep",                 CC_rdTprep,     too_many_1,    wrong_no_1},
    {"opmtchrevop",             CC_opmtchrevop, too_many_1,    wrong_no_1},
    {"total-degree-in-powers",  too_few_2,      CC_totalKdegreeKinKpowers,wrong_no_2},
    {"mvar_member",             too_few_2,      CC_mvar_member,wrong_no_2},
    {"exptf",                   too_few_2,      CC_exptf,      wrong_no_2},
    {"remove-free-vars*",       CC_removeKfreeKvarsH,too_many_1,wrong_no_1},
    {"simpexpt",                CC_simpexpt,    too_many_1,    wrong_no_1},
    {"ibalp_process-var",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_processKvar},
    {"floatprop",               CC_floatprop,   too_many_1,    wrong_no_1},
    {"xlcm",                    too_few_2,      CC_xlcm,       wrong_no_2},
    {"prinlatom",               CC_prinlatom,   too_many_1,    wrong_no_1},
    {"pterpri",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_pterpri},
    {"physopsm*",               CC_physopsmH,   too_many_1,    wrong_no_1},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {"evaluate-mod-p",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKmodKp},
    {"texstrlen",               CC_texstrlen,   too_many_1,    wrong_no_1},
    {"get_group_in",            CC_get_group_in,too_many_1,    wrong_no_1},
    {"ibalp_redclause",         CC_ibalp_redclause,too_many_1, wrong_no_1},
    {"ir2mml",                  CC_ir2mml,      too_many_1,    wrong_no_1},
    {"subs4q",                  CC_subs4q,      too_many_1,    wrong_no_1},
    {"dm-eq",                   too_few_2,      CC_dmKeq,      wrong_no_2},
    {"groebcplistsortin",       too_few_2,      CC_groebcplistsortin,wrong_no_2},
    {"evgradlexcomp",           too_few_2,      CC_evgradlexcomp,wrong_no_2},
    {"fortranname",             CC_fortranname, too_many_1,    wrong_no_1},
    {"collectphystype",         CC_collectphystype,too_many_1, wrong_no_1},
    {"mktails1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails1},
    {"mv-domainlist",           CC_mvKdomainlist,too_many_1,   wrong_no_1},
    {"fs:prin1",                CC_fsTprin1,    too_many_1,    wrong_no_1},
    {"inprint",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprint},
    {"splitlist:",              too_few_2,      CC_splitlistT, wrong_no_2},
    {"reduce-degree-mod-p",     too_few_2,      CC_reduceKdegreeKmodKp,wrong_no_2},
    {"xxsort",                  CC_xxsort,      too_many_1,    wrong_no_1},
    {"lambda_l7fvjw_2",         too_few_2,      CC_lambda_l7fvjw_2,wrong_no_2},
    {"expnd1",                  CC_expnd1,      too_many_1,    wrong_no_1},
    {"ibalp_readclause",        too_few_2,      CC_ibalp_readclause,wrong_no_2},
    {"aex_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_mk},
    {"getsetvars",              CC_getsetvars,  too_many_1,    wrong_no_1},
    {"dipev2f",                 too_few_2,      CC_dipev2f,    wrong_no_2},
    {"my_freeof",               too_few_2,      CC_my_freeof,  wrong_no_2},
    {"setk",                    too_few_2,      CC_setk,       wrong_no_2},
    {"mv-pow-mv-+",             too_few_2,      CC_mvKpowKmvKL,wrong_no_2},
    {":rn2rd",                  CC_Trn2rd,      too_many_1,    wrong_no_1},
    {"red=cancelsimp",          too_few_2,      CC_redMcancelsimp,wrong_no_2},
    {"idcons_ordp",             too_few_2,      CC_idcons_ordp,wrong_no_2},
    {"b:ordexp",                too_few_2,      CC_bTordexp,   wrong_no_2},
    {"horner-rule-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKmodKp},
    {"ofsf_smmkatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatl},
    {"cl_apply2ats",            too_few_2,      CC_cl_apply2ats,wrong_no_2},
    {"get_char_value",          too_few_2,      CC_get_char_value,wrong_no_2},
    {NULL, (one_args *)"u16", (two_args *)"12900 7372942 5692327", 0}
};

/* end of generated code */
